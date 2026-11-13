// Decompiled by Ghidra 12.2
// Program: qce50_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// qce_get_crypto_status @ 0010105c size=596
// signature: undefined qce_get_crypto_status(void)
// callers: [qce_manage_timeout]
//------------------------------------------------------------

void qce_get_crypto_status(long param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x48) + 0x1a100);
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x48) + 0x1a104);
  uVar3 = readl_relaxed(*(long *)(param_1 + 0x48) + 0x1a11c);
  uVar4 = readl_relaxed(*(long *)(param_1 + 0x48) + 0x1a124);
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x48) + 0x1a128);
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x48) + 0x1a13c);
  if ((uVar1 & 0xfffffffd) == 0x2000004) {
    pcVar8 = "qce_get_crypto_status";
    puVar7 = &DAT_00110744;
    pcVar9 = "qce_get_crypto_status";
    *param_2 = 1;
    uVar6 = uVar1;
    goto LAB_00101290;
  }
  if (*(uint *)(param_1 + 0x1ac) < 8) {
    if ((uVar3 & 0xff00) == 0 && (uVar6 & 0x300) == 0) {
      if ((uVar3 >> 0x18 == 0) && ((uVar6 & 0x3000000) == 0)) goto LAB_0010117c;
      puVar7 = &DAT_00110aaf;
      param_2[2] = 1;
    }
    else {
      puVar7 = &DAT_00110307;
      param_2[1] = 1;
    }
    _printk(puVar7,"qce_get_crypto_status","qce_get_crypto_status");
  }
  else {
    if ((uVar3 >> 4 & 1) == 0) {
      if ((uVar3 >> 0xc & 1) == 0) {
LAB_0010117c:
        _printk(&DAT_0010ff1c,"qce_get_crypto_status","qce_get_crypto_status");
        param_2[3] = 1;
        goto LAB_001011fc;
      }
      puVar7 = &DAT_0011034c;
      param_2[2] = 1;
    }
    else {
      puVar7 = &DAT_00110dd7;
      param_2[1] = 1;
    }
    _printk(puVar7,"qce_get_crypto_status","qce_get_crypto_status",uVar3 >> 0x10);
  }
LAB_001011fc:
  _printk(&DAT_0010ff4e,"dump_status_regs","dump_status_regs",uVar1);
  _printk(&DAT_00110148,"dump_status_regs","dump_status_regs",uVar2);
  _printk(&DAT_001104bc,"dump_status_regs","dump_status_regs",uVar3);
  _printk(&DAT_001105e0,"dump_status_regs","dump_status_regs",uVar4);
  _printk(&DAT_0011112c,"dump_status_regs","dump_status_regs",uVar5);
  puVar7 = &DAT_0010fa9f;
  pcVar8 = "dump_status_regs";
  pcVar9 = "dump_status_regs";
LAB_00101290:
  _printk(puVar7,pcVar8,pcVar9,uVar6);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001012b0 size=124
// signature: undefined readl_relaxed(void)
// callers: [_probe_ce_engine, _sps_producer_callback, qce_sps_init, qce_get_crypto_status]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1012f8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qce_set_irqs @ 00101330 size=44
// signature: undefined qce_set_irqs(void)
// callers: []
//------------------------------------------------------------

void qce_set_irqs(long param_1,uint param_2)

{
  if ((param_2 & 1) == 0) {
    sps_bam_disable_irqs(*(undefined8 *)(param_1 + 0x1a0));
  }
  else {
    sps_bam_enable_irqs();
  }
  return;
}



//------------------------------------------------------------
// qce_manage_timeout @ 00101360 size=888
// signature: undefined qce_manage_timeout(void)
// callers: []
//------------------------------------------------------------

void qce_manage_timeout(long param_1,uint param_2)

{
  int *piVar1;
  ushort uVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined *puVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined4 local_60 [2];
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (8 < param_2) {
LAB_001016bc:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1016c0);
    (*pcVar4)();
  }
  uVar10 = (ulong)param_2;
  lVar8 = param_1 + (ulong)param_2 * 0x1bf8;
  piVar1 = (int *)(lVar8 + 0xea8);
  local_60[0] = 0;
  uVar2 = *(ushort *)(lVar8 + 0x2a98);
  uVar12 = (ulong)uVar2;
  _printk(&DAT_001110a5,"qce_manage_timeout","qce_manage_timeout",uVar10,uVar12);
  if (8 < uVar2) goto LAB_001016bc;
  lVar9 = param_1 + 0x118 + uVar12 * 4;
  sps_pipe_reset(*(undefined8 *)(param_1 + 0x1a0),*(undefined4 *)(lVar9 + 100));
  sps_pipe_reset(*(undefined8 *)(param_1 + 0x1a0),*(undefined4 *)(lVar9 + 0x40));
  uVar13 = *(undefined8 *)(param_1 + 0x118 + (ulong)(uint)uVar2 * 0xb8 + 0x718);
  iVar6 = sps_disconnect(uVar13);
  if (iVar6 == 0) {
    uVar11 = (uint)uVar2;
    lVar9 = param_1 + uVar12 * 0xb8;
    memset(*(void **)(lVar9 + 0x870),0,(ulong)*(uint *)(lVar9 + 0x888));
    iVar6 = sps_connect(uVar13,lVar9 + 0x838);
    if (iVar6 != 0) {
LAB_001014b4:
      puVar7 = &DAT_00110ca8;
      goto LAB_001014d0;
    }
    uVar13 = *(undefined8 *)(param_1 + (ulong)uVar11 * 0xb8 + 0x1b8);
    iVar6 = sps_disconnect(uVar13);
    if (iVar6 != 0) goto LAB_001014b4;
    lVar9 = param_1 + (ulong)uVar11 * 0xb8;
    memset(*(void **)(lVar9 + 0x1f8),0,(ulong)*(uint *)(lVar9 + 0x210));
    iVar6 = sps_connect(uVar13,lVar9 + 0x1c0);
    if (iVar6 != 0) goto LAB_001014b4;
    iVar6 = sps_register_event(uVar13,param_1 + (ulong)uVar11 * 0xb8 + 0x250);
    if (iVar6 == 0) goto LAB_001014f8;
    _printk(&DAT_00110e16,"qce_sps_pipe_reset",iVar6);
  }
  else {
    puVar7 = &DAT_00110953;
LAB_001014d0:
    _printk(puVar7,"qce_sps_pipe_reset",uVar13,iVar6);
  }
  _printk(&DAT_00110449,"qce_manage_timeout","qce_manage_timeout");
LAB_001014f8:
  qce_get_crypto_status(param_1,local_60);
  if ((char)local_60[0] == '\0') {
    uVar11 = 0;
    do {
      usleep_range_state(3000,5000,2);
      qce_get_crypto_status(param_1,local_60);
      _printk(&DAT_00110776,"qce_manage_timeout","qce_manage_timeout");
      if ((char)local_60[0] != '\0') break;
      bVar5 = uVar11 < 999;
      uVar11 = uVar11 + 1;
    } while (bVar5);
  }
  DataSynchronizationBarrier(3,2,0);
  if (((*(char *)(param_1 + 0x78) == '\0') && (*(char *)(param_1 + 0x40) != '\0')) &&
     (iVar6 = sps_transfer_one(*(undefined8 *)
                                (param_1 + (ulong)*(ushort *)(lVar8 + 0x2a98) * 0xb8 + 0x830),
                               (*(long *)(param_1 + uVar10 * 0x1bf8 + 0x2930) +
                               *(long *)(param_1 + 0x18)) - *(long *)(param_1 + 0x10),0,0,0xa00),
     iVar6 != 0)) {
    _printk(&DAT_00110174,"_qce_unlock_other_pipes",iVar6);
    _printk(&DAT_001110d6,"qce_manage_timeout","qce_manage_timeout");
    iVar6 = *piVar1;
  }
  else {
    iVar6 = *piVar1;
  }
  if (iVar6 == 0) {
    _printk(&DAT_0010fa60,"qce_manage_timeout",uVar10);
    uVar13 = 0xfffffffa;
  }
  else {
    *(undefined4 *)(param_1 + uVar10 * 0x1bf8 + 0xeb0) = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar6 = *piVar1;
      cVar3 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = 0;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar6 == 0) {
      _printk(&DAT_00110c06,"qce_free_req_info",uVar10);
    }
    else if (param_2 < 8) {
      piVar1 = (int *)(param_1 + 0x10a68);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = *piVar1 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    uVar13 = 0;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}



//------------------------------------------------------------
// qce_free_req_info @ 001016e0 size=168
// signature: undefined qce_free_req_info(void)
// callers: [qce_aead_req]
//------------------------------------------------------------

void qce_free_req_info(long param_1,uint param_2,ulong param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  long lVar6;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101774);
    (*pcVar5)();
  }
  lVar6 = param_1 + (ulong)param_2 * 0x1bf8;
  piVar1 = (int *)(lVar6 + 0xea8);
  *(undefined4 *)(lVar6 + 0xeb0) = 5;
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = 0;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar2 == 0) {
    _printk(&DAT_00110c06,"qce_free_req_info",param_2);
  }
  else if ((param_2 < 8) && ((param_3 & 1) != 0)) {
    piVar1 = (int *)(param_1 + 0x10a68);
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
  return;
}



//------------------------------------------------------------
// qce_get_driver_stats @ 00101794 size=4
// signature: undefined qce_get_driver_stats(void)
// callers: []
//------------------------------------------------------------

void qce_get_driver_stats(void)

{
  return;
}



//------------------------------------------------------------
// qce_clear_driver_stats @ 0010179c size=16
// signature: undefined qce_clear_driver_stats(void)
// callers: []
//------------------------------------------------------------

void qce_clear_driver_stats(long param_1)

{
  *(undefined8 *)(param_1 + 0x10bcc) = 0;
  return;
}



//------------------------------------------------------------
// _qce_suspend @ 001017b0 size=384
// signature: undefined _qce_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 _qce_suspend(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffed;
  }
  else {
    if ((*(char *)(param_1 + 0x10bfa) != '\0') && (*(int *)(param_1 + 0x134) != -1)) {
      sps_disconnect(*(undefined8 *)(param_1 + 0x830));
      sps_disconnect(*(undefined8 *)(param_1 + 0x1b8));
    }
    if (*(char *)(param_1 + 0x10bfb) != '\0') {
      if (*(int *)(param_1 + 0x138) != -1) {
        sps_disconnect(*(undefined8 *)(param_1 + 0x8e8));
        sps_disconnect(*(undefined8 *)(param_1 + 0x270));
      }
      if (*(char *)(param_1 + 0x10bfb) != '\0') {
        if (*(int *)(param_1 + 0x13c) != -1) {
          sps_disconnect(*(undefined8 *)(param_1 + 0x9a0));
          sps_disconnect(*(undefined8 *)(param_1 + 0x328));
        }
        if (*(char *)(param_1 + 0x10bfb) != '\0') {
          if (*(int *)(param_1 + 0x140) != -1) {
            sps_disconnect(*(undefined8 *)(param_1 + 0xa58));
            sps_disconnect(*(undefined8 *)(param_1 + 0x3e0));
          }
          if (*(char *)(param_1 + 0x10bfb) != '\0') {
            if (*(int *)(param_1 + 0x144) != -1) {
              sps_disconnect(*(undefined8 *)(param_1 + 0xb10));
              sps_disconnect(*(undefined8 *)(param_1 + 0x498));
            }
            if (*(char *)(param_1 + 0x10bfb) != '\0') {
              if (*(int *)(param_1 + 0x148) != -1) {
                sps_disconnect(*(undefined8 *)(param_1 + 0xbc8));
                sps_disconnect(*(undefined8 *)(param_1 + 0x550));
              }
              if (*(char *)(param_1 + 0x10bfb) != '\0') {
                if (*(int *)(param_1 + 0x14c) != -1) {
                  sps_disconnect(*(undefined8 *)(param_1 + 0xc80));
                  sps_disconnect(*(undefined8 *)(param_1 + 0x608));
                }
                if (*(char *)(param_1 + 0x10bfb) != '\0') {
                  if (*(int *)(param_1 + 0x150) != -1) {
                    sps_disconnect(*(undefined8 *)(param_1 + 0xd38));
                    sps_disconnect(*(undefined8 *)(param_1 + 0x6c0));
                  }
                  if ((*(char *)(param_1 + 0x10bfb) != '\0') && (*(int *)(param_1 + 0x154) != -1)) {
                    sps_disconnect(*(undefined8 *)(param_1 + 0xdf0));
                    sps_disconnect(*(undefined8 *)(param_1 + 0x778));
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// _qce_resume @ 00101934 size=532
// signature: undefined _qce_resume(void)
// callers: []
//------------------------------------------------------------

int _qce_resume(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  if (param_1 == 0) {
    iVar2 = -0x13;
  }
  else {
    if ((*(char *)(param_1 + 0x10bfa) == '\0') || (*(int *)(param_1 + 0x134) == -1)) {
      iVar2 = -0x13;
    }
    else {
      uVar3 = *(undefined8 *)(param_1 + 0x830);
      memset(*(void **)(param_1 + 0x870),0,(ulong)*(uint *)(param_1 + 0x888));
      iVar2 = sps_connect(uVar3,param_1 + 0x838);
      if (iVar2 != 0) {
LAB_00101b04:
        _printk(&DAT_00110ca8,"_qce_resume",uVar3,iVar2);
        return iVar2;
      }
      uVar3 = *(undefined8 *)(param_1 + 0x1b8);
      memset(*(void **)(param_1 + 0x1f8),0,(ulong)*(uint *)(param_1 + 0x210));
      iVar2 = sps_connect(uVar3,param_1 + 0x1c0);
      if (iVar2 != 0) {
        _printk(&DAT_00110ca8,"_qce_resume",uVar3,iVar2);
      }
      iVar2 = sps_register_event(uVar3,param_1 + 0x250);
      if (iVar2 != 0) {
        _printk(&DAT_00110e16,"_qce_resume",iVar2);
      }
    }
    lVar4 = 0;
    lVar5 = 0x138;
    do {
      if (*(char *)(param_1 + 0x10bfb) == '\0') {
        return iVar2;
      }
      if (*(int *)(param_1 + lVar5) != -1) {
        lVar1 = param_1 + lVar4;
        uVar3 = *(undefined8 *)(lVar1 + 0x8e8);
        memset(*(void **)(lVar1 + 0x928),0,(ulong)*(uint *)(lVar1 + 0x940));
        iVar2 = sps_connect(uVar3,lVar1 + 0x8f0);
        if (iVar2 != 0) goto LAB_00101b04;
        uVar3 = *(undefined8 *)(lVar1 + 0x270);
        memset(*(void **)(lVar1 + 0x2b0),0,(ulong)*(uint *)(lVar1 + 0x2c8));
        iVar2 = sps_connect(uVar3,lVar1 + 0x278);
        if (iVar2 != 0) {
          _printk(&DAT_00110ca8,"_qce_resume",uVar3,iVar2);
        }
        iVar2 = sps_register_event(uVar3,param_1 + lVar4 + 0x308);
        if (iVar2 != 0) {
          _printk(&DAT_00110e16,"_qce_resume",iVar2);
        }
      }
      lVar4 = lVar4 + 0xb8;
      lVar5 = lVar5 + 4;
    } while (lVar4 != 0x5c0);
  }
  return iVar2;
}



//------------------------------------------------------------
// qce_aead_req @ 00101b4c size=8272
// signature: undefined qce_aead_req(void)
// callers: []
//------------------------------------------------------------

int qce_aead_req(undefined8 *param_1,long param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  ushort uVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  code *pcVar10;
  bool bVar11;
  uint uVar12;
  int iVar13;
  long lVar14;
  long lVar15;
  char *pcVar16;
  undefined8 *puVar17;
  uint *puVar18;
  long lVar19;
  uint uVar20;
  undefined4 *puVar21;
  ulong uVar22;
  undefined4 uVar23;
  uint *puVar24;
  uint uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  uint *puVar28;
  ulong uVar29;
  ulong uVar30;
  bool bVar31;
  uint uVar32;
  undefined4 uVar33;
  byte *pbVar34;
  uint uVar35;
  undefined4 uVar36;
  uint *puVar37;
  ulong uVar38;
  int iVar39;
  uint uVar40;
  undefined8 uVar41;
  int iVar42;
  long lVar43;
  long lVar44;
  undefined8 uVar45;
  long *plVar46;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
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
  
  lVar44 = sp_el0;
  local_70 = *(long *)(lVar44 + 0x638);
  if (*(int *)(param_2 + 0x20) == 4) {
    lVar44 = *(long *)(param_2 + 0x10);
    iVar42 = *(int *)(param_2 + 0x34);
    uVar12 = qce_alloc_req_info(param_1);
    if ((int)uVar12 < 0) {
LAB_00101c24:
      iVar13 = -0x10;
      goto LAB_0010324c;
    }
    uVar38 = (ulong)uVar12;
    *(uint *)(param_2 + 0xa8) = uVar12;
    if (9 < uVar12) goto LAB_00103b7c;
    iVar4 = *(int *)(lVar44 + 0x34);
    uVar20 = *(int *)(param_2 + 0x50) + iVar4;
    if (*(int *)(param_2 + 0x1c) == 0) {
      iVar13 = *(int *)(param_1 + 0x35);
      *(int *)(param_2 + 0x80) = iVar4;
      iVar4 = *(int *)(lVar44 + 0x34) + iVar42;
      iVar42 = ((iVar42 + iVar13) - 1U & -iVar13) - iVar42;
    }
    else {
      iVar4 = iVar4 - iVar42;
      *(int *)(param_2 + 0x80) = iVar4;
    }
    if (*(int *)((long)param_1 + 0x1ac) == 0) {
      if ((int)uVar20 < 1) goto LAB_00101d4c;
      iVar13 = 0;
      lVar14 = *(long *)(lVar44 + 0x40);
      uVar40 = uVar20;
      do {
        iVar13 = iVar13 + 1;
        uVar40 = uVar40 - *(int *)(lVar14 + 0xc);
        lVar14 = sg_next();
      } while (0 < (int)uVar40);
    }
    else {
      iVar39 = *(int *)(lVar44 + 0x30) + *(int *)(lVar44 + 0x34);
      if (iVar39 < 1) {
LAB_00101d4c:
        iVar13 = 0;
      }
      else {
        iVar13 = 0;
        lVar14 = *(long *)(lVar44 + 0x40);
        do {
          iVar13 = iVar13 + 1;
          iVar39 = iVar39 - *(int *)(lVar14 + 0xc);
          lVar14 = sg_next();
        } while (0 < iVar39);
      }
    }
    *(int *)(param_1 + uVar38 * 0x37f + 0x54b) = iVar13;
    piVar1 = (int *)(param_1 + uVar38 * 0x37f + 0x54b);
    iVar39 = *(int *)(param_2 + 0x50);
    if (iVar39 == 0) {
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x549) = 0;
      param_1[uVar38 * 0x37f + 0x54a] = 0;
    }
    else {
      if (iVar39 < 1) {
        *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x549) = 0;
      }
      else {
        lVar14 = *(long *)(param_2 + 0x58);
        uVar40 = 0;
        do {
          uVar25 = uVar40;
          uVar40 = uVar25 + 1;
          iVar39 = iVar39 - *(int *)(lVar14 + 0xc);
          lVar14 = sg_next();
        } while (0 < iVar39);
        *(uint *)(param_1 + uVar38 * 0x37f + 0x549) = uVar40;
        if (uVar25 < 0x7fffffff) {
          uVar41 = *param_1;
          uVar45 = *(undefined8 *)(param_2 + 0x58);
          do {
            dma_map_sg_attrs(uVar41,uVar45,1,1,0);
            uVar45 = sg_next(uVar45);
            uVar40 = uVar40 - 1;
          } while (uVar40 != 0);
        }
      }
      iVar13 = *piVar1;
      param_1[uVar38 * 0x37f + 0x54a] = *(undefined8 *)(param_2 + 0x58);
    }
    lVar14 = *(long *)(lVar44 + 0x40);
    lVar15 = *(long *)(lVar44 + 0x48);
    bVar11 = lVar14 != lVar15;
    if (0 < iVar13) {
      uVar45 = *param_1;
      do {
        dma_map_sg_attrs(uVar45,lVar14,1,bVar11,0);
        lVar14 = sg_next(lVar14);
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      lVar14 = *(long *)(lVar44 + 0x40);
      lVar15 = *(long *)(lVar44 + 0x48);
    }
    piVar2 = (int *)(param_1 + uVar38 * 0x37f + 0x1d5);
    if (lVar14 == lVar15) {
      iVar13 = *piVar1;
LAB_00101f90:
      *(int *)((long)param_1 + uVar38 * 0x1bf8 + 0x2a5c) = iVar13;
      if (*(char *)(param_1 + 8) != '\0') goto LAB_00101f1c;
LAB_00101fa4:
      _ce_setup_cipher_direct(param_1,param_2,uVar20,*(undefined4 *)(param_2 + 0x50));
      iVar13 = 0;
      plVar46 = (long *)0x0;
LAB_001022f4:
      *(undefined4 *)((long)param_1 + uVar38 * 0x1bf8 + 0x2a7c) = *(undefined4 *)(param_2 + 0x20);
      param_1[uVar38 * 0x37f + 0x548] = *(undefined8 *)(param_2 + 0x10);
      param_1[uVar38 * 0x37f + 0x546] = *(undefined8 *)(param_2 + 8);
      uVar23 = *(undefined4 *)(param_2 + 0x1c);
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x1d6) = 2;
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x54f) = uVar23;
      *(uint *)((long)param_1 + uVar38 * 0x1bf8 + 0x2a94) = uVar20;
      if (8 < uVar12) goto LAB_00103b7c;
      cVar9 = *(char *)(param_1 + 8);
      puVar28 = (uint *)(param_1 + uVar38 * 0x37f + 0x1db);
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x1db) = 0;
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x1df) = 0;
      if ((cVar9 == '\0') || (plVar46 == (long *)0x0)) {
LAB_001023a0:
        if ((*(int *)((long)param_1 + 0x1ac) == 0) ||
           (((*(int *)(param_2 + 0x50) != 0 &&
             (iVar13 = _qce_sps_add_sg_data
                                 (param_1,*(undefined8 *)(param_2 + 0x58),*(int *)(param_2 + 0x50),
                                  param_1 + uVar38 * 0x37f + 0x1d9), iVar13 != 0)) ||
            (iVar13 = _qce_sps_add_sg_data_off
                                (param_1,*(undefined8 *)(lVar44 + 0x40),
                                 *(undefined4 *)(lVar44 + 0x34),*(undefined4 *)(lVar44 + 0x30),
                                 param_1 + uVar38 * 0x37f + 0x1d9), iVar13 != 0))))
        goto LAB_00102680;
        if (*puVar28 != 0) {
          lVar14 = param_1[uVar38 * 0x37f + 0x1da] + (ulong)(*puVar28 - 1) * 8;
          *(uint *)(lVar14 + 4) = *(uint *)(lVar14 + 4) | 0x50000000;
        }
        if (((*(int *)(param_2 + 0x1c) == 1) && (*(char *)(param_1 + 0xf) != '\0')) &&
           (*(char *)((long)param_1 + 0x79) == '\0')) {
          uVar5 = *(ushort *)(param_1 + uVar38 * 0x37f + 0x4b9);
          lVar14 = (param_1[uVar38 * 0x37f + 0x49f] - param_1[2]) + param_1[3];
          puVar21 = (undefined4 *)(param_1[uVar38 * 0x37f + 0x1da] + (ulong)*puVar28 * 8);
          *puVar21 = (int)lVar14;
          puVar21[1] = (uint)uVar5 | (uint)((ulong)lVar14 >> 0x10) & 0xf0000 | 0x8000000;
          uVar40 = *puVar28 + 1;
          *puVar28 = uVar40;
          if (0x1ff < uVar40) {
            _printk(&DAT_0010fd4b,"_qce_sps_add_cmd",uVar40,0x200);
          }
          uVar40 = *(uint *)(param_1 + 0x35);
          if (uVar40 != 0) {
            uVar29 = (ulong)*puVar28;
            lVar14 = (param_1[3] + (ulong)*(uint *)(param_1 + uVar38 * 0x37f + 0x543)) - param_1[2];
            puVar21 = (undefined4 *)(param_1[uVar38 * 0x37f + 0x1da] + uVar29 * 8);
            do {
              if ((int)uVar29 == 0x200) {
                _printk(&DAT_0010fd4b,"_qce_sps_add_data",0x200,0x200);
                uVar40 = *puVar28;
                goto joined_r0x00103b70;
              }
              uVar25 = uVar40;
              if (0x7fbf < uVar40) {
                uVar25 = 0x7fc0;
              }
              uVar40 = uVar40 - uVar25;
              *puVar21 = (int)lVar14;
              puVar21[1] = (uint)((ulong)lVar14 >> 0x10) & 0xf0000 | uVar25;
              lVar14 = lVar14 + (ulong)uVar25;
              uVar29 = (ulong)(*puVar28 + 1);
              *puVar28 = *puVar28 + 1;
              puVar21 = puVar21 + 2;
            } while (uVar40 != 0);
          }
          uVar40 = *puVar28;
joined_r0x00103b70:
          if (uVar40 != 0) {
            lVar14 = param_1[uVar38 * 0x37f + 0x1da] + (ulong)(uVar40 - 1) * 8;
            *(uint *)(lVar14 + 4) = *(uint *)(lVar14 + 4) | 0x50000000;
          }
        }
        if (*(char *)(param_1 + 0xf) != '\0') {
          uVar5 = *(ushort *)(param_1 + uVar38 * 0x37f + 0x540);
          lVar14 = (param_1[uVar38 * 0x37f + 0x526] - param_1[2]) + param_1[3];
          puVar21 = (undefined4 *)(param_1[uVar38 * 0x37f + 0x1da] + (ulong)*puVar28 * 8);
          *puVar21 = (int)lVar14;
          puVar21[1] = uVar5 | 0xa000000 | (uint)((ulong)lVar14 >> 0x10) & 0xf0000;
          uVar40 = *puVar28 + 1;
          *puVar28 = uVar40;
          if (0x1ff < uVar40) goto LAB_00102664;
        }
        uVar40 = *(uint *)(param_2 + 0x50);
        if (uVar40 != 0) {
          puVar28 = (uint *)(param_1 + uVar38 * 0x37f + 0x1df);
          uVar29 = (ulong)*puVar28;
          lVar14 = (param_1[3] + (ulong)*(uint *)(param_1 + (ulong)uVar12 * 0x37f + 0x543)) -
                   param_1[2];
          puVar21 = (undefined4 *)(param_1[(ulong)uVar12 * 0x37f + 0x1de] + uVar29 * 8);
          do {
            if ((int)uVar29 == 0x200) {
              pcVar16 = "_qce_sps_add_data";
              uVar40 = 0x200;
              goto LAB_00102674;
            }
            uVar25 = uVar40;
            if (0x7fbf < uVar40) {
              uVar25 = 0x7fc0;
            }
            uVar40 = uVar40 - uVar25;
            *puVar21 = (int)lVar14;
            puVar21[1] = (uint)((ulong)lVar14 >> 0x10) & 0xf0000 | uVar25;
            lVar14 = lVar14 + (ulong)uVar25;
            uVar29 = (ulong)(*puVar28 + 1);
            *puVar28 = *puVar28 + 1;
            puVar21 = puVar21 + 2;
          } while (uVar40 != 0);
        }
        puVar17 = param_1 + (ulong)uVar12 * 0x37f + 0x1dd;
        iVar13 = _qce_sps_add_sg_data_off
                           (param_1,*(undefined8 *)(lVar44 + 0x48),iVar4,
                            *(undefined4 *)(lVar44 + 0x30),puVar17);
        if ((iVar13 == 0) &&
           (iVar13 = _qce_sps_add_data((param_1[3] +
                                       (ulong)*(uint *)(param_1 + (ulong)uVar12 * 0x37f + 0x543)) -
                                       param_1[2],iVar42,puVar17), iVar13 == 0)) {
          if ((*(char *)(param_1 + 0xf) == '\0') && (0x7fc0 < uVar20)) {
            uVar23 = 0;
          }
          else {
            iVar13 = _qce_sps_add_data((param_1[3] +
                                       (ulong)*(uint *)(param_1 + uVar38 * 0x37f + 0x541)) -
                                       param_1[2],0x80,puVar17);
            if (iVar13 != 0) goto LAB_00102680;
            uVar23 = 2;
          }
          *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x1d7) = uVar23;
          _qce_ccm_get_around_output(param_1,piVar2,*(undefined4 *)(param_2 + 0x1c));
          select_mode(param_1,piVar2);
          iVar13 = _qce_sps_transfer(param_1,uVar38);
          piVar3 = (int *)((long)param_1 + 0x10a64);
          Hint_Prefetch(piVar3,2,0,1);
          do {
            if (*piVar3 != 1) goto LAB_00103bcc;
            cVar9 = '\x01';
            bVar11 = (bool)ExclusiveMonitorPass(piVar3,0x10);
            if (bVar11) {
              *piVar3 = 0;
              cVar9 = ExclusiveMonitorsStatus();
            }
          } while (cVar9 != '\0');
          DataMemoryBarrier(2,3);
LAB_00103bcc:
          if (iVar13 == 0) goto LAB_0010324c;
        }
      }
      else {
        lVar14 = (*plVar46 - param_1[2]) + param_1[3];
        uVar5 = *(ushort *)(plVar46 + 0x1a);
        puVar21 = (undefined4 *)param_1[(ulong)uVar12 * 0x37f + 0x1da];
        *puVar21 = (int)lVar14;
        puVar21[1] = (uint)uVar5 | (uint)((ulong)lVar14 >> 0x10) & 0xf0000 | 0xc000000;
        uVar40 = *puVar28 + 1;
        *puVar28 = uVar40;
        if (uVar40 < 0x200) {
          iVar13 = 0;
          goto LAB_001023a0;
        }
LAB_00102664:
        pcVar16 = "_qce_sps_add_cmd";
LAB_00102674:
        _printk(&DAT_0010fd4b,pcVar16,uVar40,0x200);
        iVar13 = -0xc;
      }
LAB_00102680:
      iVar42 = *(int *)(param_1 + uVar38 * 0x37f + 0x549);
      if ((iVar42 != 0) && (0 < iVar42)) {
        uVar41 = *param_1;
        uVar45 = *(undefined8 *)(param_2 + 0x58);
        do {
          dma_unmap_sg_attrs(uVar41,uVar45,1,1,0);
          uVar45 = sg_next(uVar45);
          iVar42 = iVar42 + -1;
        } while (iVar42 != 0);
      }
      iVar42 = *piVar1;
      if (iVar42 != 0) {
        lVar14 = *(long *)(lVar44 + 0x40);
        bVar11 = lVar14 != *(long *)(lVar44 + 0x48);
        if (0 < iVar42) {
          uVar45 = *param_1;
          do {
            dma_unmap_sg_attrs(uVar45,lVar14,1,bVar11,0);
            lVar14 = sg_next(lVar14);
            iVar42 = iVar42 + -1;
          } while (iVar42 != 0);
        }
      }
      lVar14 = *(long *)(lVar44 + 0x48);
      if ((*(long *)(lVar44 + 0x40) != lVar14) &&
         (iVar42 = *(int *)((long)param_1 + uVar38 * 0x1bf8 + 0x2a5c), 0 < iVar42)) {
        uVar45 = *param_1;
        do {
          dma_unmap_sg_attrs(uVar45,lVar14,1,2,0);
          lVar14 = sg_next(lVar14);
          iVar42 = iVar42 + -1;
        } while (iVar42 != 0);
      }
      if (8 < uVar12) {
LAB_00103b7c:
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x103b80);
        (*pcVar10)();
      }
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x1d6) = 5;
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar42 = *piVar2;
        cVar9 = '\x01';
        bVar11 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar11) {
          *piVar2 = 0;
          cVar9 = ExclusiveMonitorsStatus();
        }
      } while (cVar9 != '\0');
      DataMemoryBarrier(2,3);
    }
    else {
      iVar13 = *(int *)(lVar44 + 0x30) + iVar4;
      if (iVar13 < 1) {
        iVar13 = 0;
        goto LAB_00101f90;
      }
      uVar40 = 0;
      do {
        uVar25 = uVar40;
        uVar40 = uVar25 + 1;
        iVar13 = iVar13 - *(int *)(lVar15 + 0xc);
        lVar15 = sg_next();
      } while (0 < iVar13);
      *(uint *)((long)param_1 + uVar38 * 0x1bf8 + 0x2a5c) = uVar40;
      if (uVar25 < 0x7fffffff) {
        uVar41 = *param_1;
        uVar45 = *(undefined8 *)(lVar44 + 0x48);
        do {
          dma_map_sg_attrs(uVar41,uVar45,1,2,0);
          uVar45 = sg_next(uVar45);
          uVar40 = uVar40 - 1;
        } while (uVar40 != 0);
      }
      if (*(char *)(param_1 + 8) == '\0') goto LAB_00101fa4;
LAB_00101f1c:
      iVar13 = *(int *)(param_2 + 0x18);
      if (iVar13 == 0) {
        iVar39 = *(int *)(param_2 + 0x20);
        puVar17 = param_1 + uVar38 * 0x37f;
        if (iVar39 == 1) {
          lVar14 = 0x14f0;
LAB_00101ff8:
          plVar46 = (long *)((long)puVar17 + lVar14);
          iVar39 = 1;
        }
        else {
          plVar46 = puVar17 + 0x283;
        }
LAB_001022d0:
        if (plVar46 != (long *)0x0) {
          iVar13 = _ce_setup_cipher(param_1,param_2,uVar20,*(undefined4 *)(param_2 + 0x50),plVar46);
          if (-1 < iVar13) goto LAB_001022f4;
          goto LAB_00102680;
        }
      }
      else {
        if (iVar13 == 1) {
          iVar39 = *(int *)(param_2 + 0x20);
          puVar17 = param_1 + uVar38 * 0x37f;
          if (iVar39 == 1) {
            lVar14 = 0x16a0;
            goto LAB_00101ff8;
          }
          plVar46 = puVar17 + 0x2b9;
          goto LAB_001022d0;
        }
        if (iVar13 == 2) {
          iVar39 = *(int *)(param_2 + 0x20);
          switch(iVar39) {
          case 0:
          case 2:
            lVar14 = uVar38 * 0x37f + 0x1e1;
            if (*(int *)(param_2 + 0x68) != 0x10) {
              lVar14 = uVar38 * 0x37f + 0x1fc;
            }
            plVar46 = param_1 + lVar14;
            break;
          case 1:
            if (*(int *)(param_2 + 0x68) == 0x10) {
              lVar14 = 0x10b8;
              puVar17 = param_1 + uVar38 * 0x37f;
            }
            else {
              lVar14 = 0x1190;
              puVar17 = param_1 + uVar38 * 0x37f;
            }
            goto LAB_00101ff8;
          case 3:
            if ((*(uint *)(param_2 + 0x68) & 0xfffffffe) == 0x20) {
              lVar14 = 0x1268;
            }
            else {
              lVar14 = 0x1340;
            }
            plVar46 = (long *)((long)param_1 + lVar14 + uVar38 * 0x1bf8);
            iVar39 = 3;
            break;
          case 4:
            if (*(int *)(param_2 + 0x68) == 0x10) {
              lVar14 = 0x2348;
            }
            else {
              lVar14 = 0x2420;
            }
            plVar46 = (long *)((long)param_1 + lVar14 + uVar38 * 0x1bf8);
            iVar39 = 4;
            break;
          default:
            goto switchD_00101f54_default;
          }
          goto LAB_001022d0;
        }
        iVar39 = *(int *)(param_2 + 0x20);
      }
switchD_00101f54_default:
      _printk(&DAT_0010fd14,"_qce_aead_ccm_req",iVar13,iVar39);
      if (8 < uVar12) goto LAB_00103b7c;
      iVar13 = -0x16;
      *(undefined4 *)(param_1 + uVar38 * 0x37f + 0x1d6) = 5;
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar42 = *piVar2;
        cVar9 = '\x01';
        bVar11 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar11) {
          *piVar2 = 0;
          cVar9 = ExclusiveMonitorsStatus();
        }
      } while (cVar9 != '\0');
      DataMemoryBarrier(2,3);
    }
  }
  else {
    uVar38 = qce_alloc_req_info(param_1);
    uVar12 = (uint)uVar38;
    if ((int)uVar12 < 0) goto LAB_00101c24;
    uVar29 = uVar38 & 0xffffffff;
    *(uint *)(param_2 + 0xa8) = uVar12;
    if (9 < uVar12) goto LAB_00103b7c;
    lVar44 = *(long *)(param_2 + 0x10);
    uVar20 = *(uint *)(*(long *)(*(long *)(lVar44 + 0x20) + 0x10) + -0x10);
    *(uint *)(param_2 + 0x78) = uVar20;
    if (*(int *)(param_2 + 0x1c) == 0) {
      uVar40 = *(uint *)(lVar44 + 0x34);
    }
    else {
      uVar40 = *(int *)(lVar44 + 0x34) - *(int *)(param_2 + 0x34);
    }
    *(uint *)(param_2 + 0x80) = uVar40;
    uVar25 = *(uint *)(lVar44 + 0x30);
    if (CARRY4(uVar25,uVar40)) {
      _printk(&DAT_0010fe92,"qce_aead_req");
      iVar13 = -0x16;
      goto LAB_0010324c;
    }
    uVar40 = uVar25 + uVar40;
    piVar1 = (int *)(param_1 + uVar29 * 0x37f + 0x1d5);
    if (*(char *)(param_1 + 8) != '\0') {
      if (8 < uVar12) goto LAB_00103b7c;
      iVar13 = *(int *)(param_2 + 0x18);
      if (iVar13 == 0) {
        iVar42 = *(int *)(param_2 + 0x20);
        if (iVar42 == 0) {
          if (*(int *)(param_2 + 0x24) == 3) {
            lVar14 = 0x2198;
          }
          else {
            if (*(int *)(param_2 + 0x24) != 2) goto LAB_0010226c;
            lVar14 = 0x1e38;
          }
          goto LAB_001020d4;
        }
      }
      else if (iVar13 == 1) {
        iVar42 = *(int *)(param_2 + 0x20);
        if (iVar42 == 0) {
          if (*(int *)(param_2 + 0x24) == 3) {
            lVar14 = 0x2270;
          }
          else {
            if (*(int *)(param_2 + 0x24) != 2) goto LAB_0010226c;
            lVar14 = 0x1f10;
          }
          goto LAB_001020d4;
        }
      }
      else if (iVar13 == 2) {
        iVar42 = *(int *)(param_2 + 0x20);
        if (iVar42 == 0) {
          if (*(int *)(param_2 + 0x68) == 0x20) {
            if (*(int *)(param_2 + 0x24) == 3) {
              lVar14 = 0x20c0;
            }
            else {
              if (*(int *)(param_2 + 0x24) != 2) goto LAB_0010226c;
              lVar14 = 0x1d60;
            }
          }
          else {
            if (*(int *)(param_2 + 0x68) != 0x10) {
LAB_0010226c:
              iVar42 = 0;
              goto LAB_00102828;
            }
            if (*(int *)(param_2 + 0x24) == 3) {
              lVar14 = 0x1fe8;
            }
            else {
              if (*(int *)(param_2 + 0x24) != 2) goto LAB_0010226c;
              lVar14 = 0x1c88;
            }
          }
LAB_001020d4:
          plVar46 = (long *)((long)param_1 + lVar14 + uVar29 * 0x1bf8);
          iVar42 = 0;
          if (plVar46 != (long *)0x0) {
            local_80 = 0;
            local_78 = 0;
            local_90 = 0;
            local_88 = 0;
            local_a0 = 0;
            local_98 = 0;
            local_b0 = 0;
            local_a8 = 0;
            local_c0 = 0;
            local_b8 = 0;
            local_d0 = 0;
            local_c8 = 0;
            local_e0 = 0;
            local_d8 = 0;
            local_f0 = 0;
            local_e8 = 0;
            local_100 = 0;
            local_f8 = 0;
            if (8 < *(uint *)(param_2 + 0x94)) goto LAB_00103b7c;
            uVar35 = (*(uint *)(param_1 + 0x35) >> 3) * 0x20000 - 0x1fff2 |
                     *(int *)((long)param_1 + (ulong)*(uint *)(param_2 + 0x94) * 4 + 0x134) << 5;
            uVar32 = *(uint *)(param_2 + 0x68);
            *(uint *)((long)param_1 + 0x8c) = uVar35;
            *(uint *)(param_1 + 0x12) = uVar35 | 0x200;
            *(uint *)(plVar46[1] + 4) = uVar35;
            *(undefined4 *)(plVar46[2] + 4) = *(undefined4 *)(param_1 + 0x12);
            if (*(uint *)(param_2 + 0x18) < 2) {
              bVar11 = true;
LAB_00102160:
              if (*(int *)(param_2 + 0x20) == 0) {
                puVar28 = *(uint **)(param_2 + 0x70);
                if (uVar20 < 4) {
                  bVar31 = false;
                  puVar37 = (uint *)((long)&local_f8 + 4);
                  puVar18 = puVar28;
                }
                else {
                  puVar18 = puVar28 + 1;
                  uVar35 = (*puVar28 & 0xff00ff00) >> 8 | (*puVar28 & 0xff00ff) << 8;
                  uVar8 = uVar35 >> 0x10 | uVar35 << 0x10;
                  uVar35 = uVar20 >> 2;
                  local_f8 = (ulong)uVar8 << 0x20;
                  if (uVar35 == 1) {
                    bVar31 = false;
                    puVar37 = (uint *)&local_f8;
                  }
                  else {
                    uVar7 = (puVar28[1] & 0xff00ff00) >> 8 | (puVar28[1] & 0xff00ff) << 8;
                    local_f8 = CONCAT44(uVar8,uVar7 >> 0x10 | uVar7 << 0x10);
                    if (uVar35 == 2) {
                      bVar31 = false;
                      puVar18 = puVar28 + 2;
                      puVar37 = (uint *)((long)&local_100 + 4);
                    }
                    else {
                      uVar8 = (puVar28[2] & 0xff00ff00) >> 8 | (puVar28[2] & 0xff00ff) << 8;
                      uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
                      local_100 = (ulong)uVar8 << 0x20;
                      if (uVar35 == 3) {
                        bVar31 = false;
                        puVar18 = puVar28 + 3;
                        puVar37 = (uint *)&local_100;
                      }
                      else {
                        uVar7 = (puVar28[3] & 0xff00ff00) >> 8 | (puVar28[3] & 0xff00ff) << 8;
                        uVar7 = uVar7 >> 0x10 | uVar7 << 0x10;
                        puVar37 = (uint *)(ulong)uVar7;
                        local_100 = CONCAT44(uVar8,uVar7);
                        if (uVar35 != 4) goto LAB_00103b78;
                        puVar18 = puVar28 + 4;
                        bVar31 = true;
                      }
                    }
                  }
                }
                uVar20 = uVar20 & 3;
                if (uVar20 == 1) {
                  uVar20 = (uint)(byte)*puVar18 << 0x18;
LAB_001028cc:
                  if (bVar31) goto LAB_00103b78;
                  *puVar37 = uVar20;
                }
                else {
                  if (uVar20 == 2) {
                    uVar20 = (uint)(byte)*puVar18 << 0x18 |
                             (uint)*(byte *)((long)puVar18 + 1) << 0x10;
                    goto LAB_001028cc;
                  }
                  if (uVar20 == 3) {
                    uVar20 = (uint)(byte)*puVar18 << 0x18 |
                             (uint)*(byte *)((long)puVar18 + 1) << 0x10 |
                             (uint)*(byte *)((long)puVar18 + 2) << 8;
                    goto LAB_001028cc;
                  }
                }
                lVar14 = plVar46[8];
                *(undefined4 *)(lVar14 + 4) = local_f8._4_4_;
                *(uint *)(lVar14 + 0x14) = (uint)local_f8;
                if (!bVar11) {
                  *(undefined4 *)(lVar14 + 0x24) = local_100._4_4_;
                  *(uint *)(lVar14 + 0x34) = (uint)local_100;
                }
                uVar20 = uVar32 >> 2;
                pbVar34 = *(byte **)(param_2 + 0x60);
                puVar28 = (uint *)&local_f0;
                if (uVar32 < 4) {
                  uVar30 = 0;
                }
                else {
                  uVar30 = 0;
                  uVar35 = uVar20;
                  do {
                    uVar22 = uVar30;
                    if ((0x3f < uVar22) || (uVar22 == 0x40)) goto LAB_00103b78;
                    uVar35 = uVar35 - 1;
                    uVar8 = (*(uint *)(pbVar34 + uVar22) & 0xff00ff00) >> 8 |
                            (*(uint *)(pbVar34 + uVar22) & 0xff00ff) << 8;
                    *(uint *)((long)puVar28 + uVar22) = uVar8 >> 0x10 | uVar8 << 0x10;
                    uVar30 = uVar22 + 4;
                  } while (uVar35 != 0);
                  pbVar34 = pbVar34 + uVar30;
                  puVar28 = (uint *)((long)&local_f0 + uVar22 + 4);
                }
                uVar35 = uVar32 & 3;
                if (uVar35 == 1) {
                  uVar35 = (uint)*pbVar34 << 0x18;
LAB_001029a4:
                  if ((0x3c < uVar30) || (0x3c < uVar30)) goto LAB_00103b78;
                  *puVar28 = uVar35;
                }
                else {
                  if (uVar35 == 2) {
                    uVar35 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10;
                    goto LAB_001029a4;
                  }
                  if (uVar35 == 3) {
                    uVar35 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10 |
                             (uint)pbVar34[2] << 8;
                    goto LAB_001029a4;
                  }
                }
                if (3 < uVar32) {
                  lVar14 = plVar46[6];
                  if (uVar20 < 2) {
                    uVar20 = 1;
                  }
                  *(uint *)(lVar14 + 4) = (uint)local_f0;
                  if (7 < uVar32) {
                    *(undefined4 *)(lVar14 + 0x14) = local_f0._4_4_;
                    if (uVar20 != 2) {
                      *(undefined4 *)(lVar14 + 0x24) = (undefined4)local_e8;
                      if (uVar20 != 3) {
                        *(undefined4 *)(lVar14 + 0x34) = local_e8._4_4_;
                        if (uVar20 != 4) {
                          *(undefined4 *)(lVar14 + 0x44) = (undefined4)local_e0;
                          if (uVar20 != 5) {
                            *(undefined4 *)(lVar14 + 0x54) = local_e0._4_4_;
                            if (uVar20 != 6) {
                              *(undefined4 *)(lVar14 + 100) = (undefined4)local_d8;
                              if (uVar20 != 7) {
                                *(undefined4 *)(lVar14 + 0x74) = local_d8._4_4_;
                                if (uVar20 != 8) {
                                  *(undefined4 *)(lVar14 + 0x84) = (undefined4)local_d0;
                                  if (uVar20 != 9) {
                                    *(undefined4 *)(lVar14 + 0x94) = local_d0._4_4_;
                                    if (uVar20 != 10) {
                                      *(undefined4 *)(lVar14 + 0xa4) = (undefined4)local_c8;
                                      if (uVar20 != 0xb) {
                                        *(undefined4 *)(lVar14 + 0xb4) = local_c8._4_4_;
                                        if (uVar20 != 0xc) {
                                          *(undefined4 *)(lVar14 + 0xc4) = (undefined4)local_c0;
                                          if (uVar20 != 0xd) {
                                            *(undefined4 *)(lVar14 + 0xd4) = local_c0._4_4_;
                                            if (uVar20 != 0xe) {
                                              *(undefined4 *)(lVar14 + 0xe4) = (undefined4)local_b8;
                                              if (uVar20 != 0xf) {
                                                *(undefined4 *)(lVar14 + 0xf4) = local_b8._4_4_;
                                                if (uVar20 != 0x10) goto LAB_00103b7c;
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
                          }
                        }
                      }
                    }
                  }
                }
                uVar20 = *(uint *)(plVar46[3] + 4);
                *(uint *)(plVar46[3] + 4) =
                     uVar20 & 0xfffff800 |
                     uVar20 & 0x3ff | (uint)(*(int *)(param_2 + 0x1c) == 0) << 10;
                puVar28 = (uint *)&local_b0;
                uVar20 = *(uint *)(param_2 + 0x30);
                pbVar34 = *(byte **)(param_2 + 0x28);
                if (uVar20 < 4) {
                  uVar30 = 0;
                }
                else {
                  uVar32 = uVar20 >> 2;
                  uVar30 = 0;
                  do {
                    uVar22 = uVar30;
                    if ((0x3f < uVar22) || (uVar22 == 0x40)) goto LAB_00103b78;
                    uVar32 = uVar32 - 1;
                    uVar35 = (*(uint *)(pbVar34 + uVar22) & 0xff00ff00) >> 8 |
                             (*(uint *)(pbVar34 + uVar22) & 0xff00ff) << 8;
                    *(uint *)((long)puVar28 + uVar22) = uVar35 >> 0x10 | uVar35 << 0x10;
                    uVar30 = uVar22 + 4;
                  } while (uVar32 != 0);
                  pbVar34 = pbVar34 + uVar30;
                  puVar28 = (uint *)((long)&local_b0 + uVar22 + 4);
                }
                uVar20 = uVar20 & 3;
                if (uVar20 == 1) {
                  uVar20 = (uint)*pbVar34 << 0x18;
LAB_00102b98:
                  if ((0x3c < uVar30) || (0x3c < uVar30)) goto LAB_00103b78;
                  *puVar28 = uVar20;
                }
                else {
                  if (uVar20 == 2) {
                    uVar20 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10;
                    goto LAB_00102b98;
                  }
                  if (uVar20 == 3) {
                    uVar20 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10 |
                             (uint)pbVar34[2] << 8;
                    goto LAB_00102b98;
                  }
                }
                lVar14 = plVar46[0x14];
                *(uint *)(lVar14 + 4) = (uint)local_b0;
                *(undefined4 *)(lVar14 + 0x14) = local_b0._4_4_;
                *(undefined4 *)(lVar14 + 0x24) = (undefined4)local_a8;
                *(undefined4 *)(lVar14 + 0x34) = local_a8._4_4_;
                *(undefined4 *)(lVar14 + 0x44) = (undefined4)local_a0;
                *(undefined4 *)(lVar14 + 0x54) = local_a0._4_4_;
                *(undefined4 *)(lVar14 + 100) = (undefined4)local_98;
                *(undefined4 *)(lVar14 + 0x74) = local_98._4_4_;
                *(undefined4 *)(lVar14 + 0x84) = (undefined4)local_90;
                *(undefined4 *)(lVar14 + 0x94) = local_90._4_4_;
                *(undefined4 *)(lVar14 + 0xa4) = (undefined4)local_88;
                *(undefined4 *)(lVar14 + 0xb4) = local_88._4_4_;
                *(undefined4 *)(lVar14 + 0xc4) = (undefined4)local_80;
                *(undefined4 *)(lVar14 + 0xd4) = local_80._4_4_;
                *(undefined4 *)(lVar14 + 0xe4) = (undefined4)local_78;
                *(undefined4 *)(lVar14 + 0xf4) = local_78._4_4_;
                lVar14 = plVar46[0x15];
                if (*(int *)(param_2 + 0x24) == 2) {
                  uVar23 = 0xefcdab89;
                  uVar27 = 0xc3d2e1f0;
                  uVar36 = 0x98badcfe;
                  uVar33 = 0x67452301;
                  uVar26 = 0x10325476;
                }
                else {
                  uVar23 = 0xbb67ae85;
                  uVar26 = 0xa54ff53a;
                  uVar33 = 0x6a09e667;
                  uVar27 = 0x510e527f;
                  uVar36 = 0x3c6ef372;
                  *(undefined4 *)(lVar14 + 0x54) = 0x9b05688c;
                  *(undefined4 *)(lVar14 + 100) = 0x1f83d9ab;
                  *(undefined4 *)(lVar14 + 0x74) = 0x5be0cd19;
                }
                *(undefined4 *)(lVar14 + 4) = uVar33;
                *(undefined4 *)(lVar14 + 0x14) = uVar23;
                *(undefined4 *)(lVar14 + 0x24) = uVar36;
                *(undefined4 *)(lVar14 + 0x34) = uVar26;
                *(undefined4 *)(lVar14 + 0x44) = uVar27;
                lVar14 = plVar46[0x17];
                *(undefined4 *)(lVar14 + 4) = 0;
                *(undefined4 *)(lVar14 + 0x14) = 0;
                uVar20 = *(uint *)(plVar46[0x11] + 4) & 0xffff3fff;
                uVar32 = uVar20 | 0x4000;
                if (*(int *)(param_2 + 0x1c) != 0) {
                  uVar32 = uVar20;
                }
                *(uint *)(plVar46[0x11] + 4) = uVar32;
                *(uint *)(plVar46[0x12] + 4) = uVar40;
                *(undefined4 *)(plVar46[0x13] + 4) = 0;
                *(uint *)(plVar46[0x18] + 4) = uVar40;
                *(undefined4 *)(plVar46[4] + 4) = *(undefined4 *)(param_2 + 0x80);
                *(uint *)(plVar46[5] + 4) = uVar25 & 0xffff;
                goto LAB_00102d08;
              }
            }
            else if ((*(uint *)(param_2 + 0x18) == 2) &&
                    ((bVar11 = false, uVar32 == 0x20 || (uVar32 == 0x10)))) goto LAB_00102160;
            *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1d6) = 5;
            Hint_Prefetch(piVar1,2,0,1);
            do {
              iVar13 = *piVar1;
              cVar9 = '\x01';
              bVar11 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar11) {
                *piVar1 = 0;
                cVar9 = ExclusiveMonitorsStatus();
              }
            } while (cVar9 != '\0');
            DataMemoryBarrier(2,3);
            if (iVar13 == 0) {
              _printk(&DAT_00110c06,"qce_free_req_info",uVar38 & 0xffffffff);
              iVar13 = -0x16;
            }
            else {
              iVar13 = -0x16;
            }
            goto LAB_0010324c;
          }
        }
      }
      else {
        iVar42 = *(int *)(param_2 + 0x20);
      }
LAB_00102828:
      _printk(&DAT_00110b99,"qce_aead_req",iVar13,iVar42,*(undefined4 *)(param_2 + 0x68),
              *(undefined4 *)(param_2 + 0x34));
      qce_free_req_info(param_1,uVar29,0);
      iVar13 = -0x16;
      goto LAB_0010324c;
    }
    plVar46 = (long *)0x0;
LAB_00102d08:
    iVar13 = 0;
    if (0 < (int)uVar40) {
      lVar14 = *(long *)(lVar44 + 0x40);
      uVar20 = uVar40;
      do {
        iVar13 = iVar13 + 1;
        uVar20 = uVar20 - *(int *)(lVar14 + 0xc);
        lVar14 = sg_next();
      } while (0 < (int)uVar20);
    }
    *(int *)(param_1 + uVar29 * 0x37f + 0x54b) = iVar13;
    lVar14 = *(long *)(lVar44 + 0x40);
    lVar15 = *(long *)(lVar44 + 0x48);
    bVar11 = lVar14 != lVar15;
    if (0 < iVar13) {
      uVar45 = *param_1;
      do {
        dma_map_sg_attrs(uVar45,lVar14,1,bVar11,0);
        lVar14 = sg_next(lVar14);
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      lVar14 = *(long *)(lVar44 + 0x40);
      lVar15 = *(long *)(lVar44 + 0x48);
    }
    if (lVar14 != lVar15) {
      if ((int)uVar40 < 1) {
        *(undefined4 *)((long)param_1 + uVar29 * 0x1bf8 + 0x2a5c) = 0;
      }
      else {
        uVar25 = uVar40;
        uVar20 = 0;
        do {
          uVar32 = uVar20;
          uVar20 = uVar32 + 1;
          uVar25 = uVar25 - *(int *)(lVar15 + 0xc);
          lVar15 = sg_next();
        } while (0 < (int)uVar25);
        *(uint *)((long)param_1 + uVar29 * 0x1bf8 + 0x2a5c) = uVar20;
        if (uVar32 < 0x7fffffff) {
          uVar41 = *param_1;
          uVar45 = *(undefined8 *)(lVar44 + 0x48);
          do {
            dma_map_sg_attrs(uVar41,uVar45,1,2,0);
            uVar45 = sg_next(uVar45);
            uVar20 = uVar20 - 1;
          } while (uVar20 != 0);
        }
      }
    }
    param_1[uVar29 * 0x37f + 0x548] = *(undefined8 *)(param_2 + 0x10);
    param_1[uVar29 * 0x37f + 0x546] = *(undefined8 *)(param_2 + 8);
    uVar23 = *(undefined4 *)(param_2 + 0x1c);
    param_1[uVar29 * 0x37f + 0x54a] = 0;
    *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x553) = 0;
    *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1d6) = 2;
    *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x54f) = uVar23;
    *(uint *)((long)param_1 + uVar29 * 0x1bf8 + 0x2a94) = uVar40;
    if (8 < uVar12) goto LAB_00103b7c;
    cVar9 = *(char *)(param_1 + 8);
    puVar28 = (uint *)(param_1 + uVar29 * 0x37f + 0x1db);
    *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1db) = 0;
    *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1df) = 0;
    if (cVar9 == '\0') {
      uVar6 = *(undefined2 *)(lVar44 + 0x30);
      uVar12 = *(uint *)(param_2 + 0x78);
      local_80 = 0;
      local_78 = 0;
      plVar46 = param_1 + 9;
      local_90 = 0;
      local_88 = 0;
      local_a0 = 0;
      local_98 = 0;
      local_b0 = 0;
      local_a8 = 0;
      local_c0 = 0;
      local_b8 = 0;
      local_d0 = 0;
      local_c8 = 0;
      local_e0 = 0;
      local_d8 = 0;
      local_f0 = 0;
      local_e8 = 0;
      local_100 = 0;
      local_f8 = 0;
      writel_relaxed(0,*plVar46 + 0x1a100);
      if (8 < *(uint *)(param_2 + 0x94)) goto LAB_00103b7c;
      uVar20 = (*(uint *)(param_1 + 0x35) >> 3) * 0x20000 - 0x1fff2 |
               *(int *)((long)param_1 + (ulong)*(uint *)(param_2 + 0x94) * 4 + 0x134) << 5;
      *(uint *)((long)param_1 + 0x8c) = uVar20;
      *(uint *)(param_1 + 0x12) = uVar20 | 0x200;
      writel_relaxed(uVar20,param_1[9] + 0x1a400);
      DataSynchronizationBarrier(3,3,0);
      iVar13 = *(int *)(param_2 + 0x18);
      uVar20 = *(uint *)(param_2 + 0x68);
      if (iVar13 == 2) {
        if (*(int *)(param_2 + 0x20) != 0) goto LAB_00103170;
        if (uVar20 == 0x20) {
          bVar11 = false;
          puVar18 = (uint *)(param_1 + 0x13);
        }
        else {
          if (uVar20 != 0x10) goto LAB_00103170;
          bVar11 = false;
          puVar18 = (uint *)((long)param_1 + 0x94);
        }
      }
      else if (iVar13 == 1) {
        if (*(int *)(param_2 + 0x20) != 0) goto LAB_00103170;
        puVar18 = (uint *)((long)param_1 + 0xc4);
        bVar11 = true;
      }
      else {
        if ((iVar13 != 0) || (*(int *)(param_2 + 0x20) != 0)) {
LAB_00103170:
          iVar13 = -0x16;
          goto LAB_00103174;
        }
        puVar18 = (uint *)((long)param_1 + 0xbc);
        bVar11 = true;
      }
      uVar25 = *puVar18;
      puVar18 = *(uint **)(param_2 + 0x70);
      if (uVar12 < 4) {
        bVar31 = false;
        puVar24 = (uint *)((long)&local_f8 + 4);
        puVar37 = puVar18;
      }
      else {
        puVar37 = puVar18 + 1;
        uVar32 = (*puVar18 & 0xff00ff00) >> 8 | (*puVar18 & 0xff00ff) << 8;
        uVar35 = uVar32 >> 0x10 | uVar32 << 0x10;
        uVar32 = uVar12 >> 2;
        local_f8 = CONCAT44(uVar35,(uint)local_f8);
        if (uVar32 == 1) {
          bVar31 = false;
          puVar24 = (uint *)&local_f8;
        }
        else {
          uVar8 = (puVar18[1] & 0xff00ff00) >> 8 | (puVar18[1] & 0xff00ff) << 8;
          local_f8 = CONCAT44(uVar35,uVar8 >> 0x10 | uVar8 << 0x10);
          if (uVar32 == 2) {
            bVar31 = false;
            puVar37 = puVar18 + 2;
            puVar24 = (uint *)((long)&local_100 + 4);
          }
          else {
            uVar35 = (puVar18[2] & 0xff00ff00) >> 8 | (puVar18[2] & 0xff00ff) << 8;
            uVar35 = uVar35 >> 0x10 | uVar35 << 0x10;
            local_100 = CONCAT44(uVar35,(uint)local_100);
            if (uVar32 == 3) {
              bVar31 = false;
              puVar37 = puVar18 + 3;
              puVar24 = (uint *)&local_100;
            }
            else {
              uVar8 = (puVar18[3] & 0xff00ff00) >> 8 | (puVar18[3] & 0xff00ff) << 8;
              uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
              puVar24 = (uint *)(ulong)uVar8;
              local_100 = CONCAT44(uVar35,uVar8);
              if (uVar32 != 4) goto LAB_00103b78;
              puVar37 = puVar18 + 4;
              bVar31 = true;
            }
          }
        }
      }
      uVar12 = uVar12 & 3;
      if (uVar12 == 1) {
        uVar12 = (uint)(byte)*puVar37 << 0x18;
LAB_00103548:
        if (bVar31) goto LAB_00103b78;
        *puVar24 = uVar12;
      }
      else {
        if (uVar12 == 2) {
          uVar12 = (uint)(byte)*puVar37 << 0x18 | (uint)*(byte *)((long)puVar37 + 1) << 0x10;
          goto LAB_00103548;
        }
        if (uVar12 == 3) {
          uVar12 = (uint)(byte)*puVar37 << 0x18 | (uint)*(byte *)((long)puVar37 + 1) << 0x10 |
                   (uint)*(byte *)((long)puVar37 + 2) << 8;
          goto LAB_00103548;
        }
      }
      writel_relaxed(local_f8._4_4_,*plVar46 + 0x1a20c);
      writel_relaxed(local_f8 & 0xffffffff,*plVar46 + 0x1a210);
      if (!bVar11) {
        writel_relaxed(local_100._4_4_,*plVar46 + 0x1a214);
        writel_relaxed(local_100 & 0xffffffff,*plVar46 + 0x1a218);
      }
      uVar12 = uVar20 >> 2;
      pbVar34 = *(byte **)(param_2 + 0x60);
      puVar18 = (uint *)&local_f0;
      if (uVar20 < 4) {
        uVar30 = 0;
      }
      else {
        uVar30 = 0;
        uVar32 = uVar12;
        do {
          uVar22 = uVar30;
          if ((0x3f < uVar22) || (uVar22 == 0x40)) goto LAB_00103b78;
          uVar32 = uVar32 - 1;
          uVar35 = (*(uint *)(pbVar34 + uVar22) & 0xff00ff00) >> 8 |
                   (*(uint *)(pbVar34 + uVar22) & 0xff00ff) << 8;
          *(uint *)((long)puVar18 + uVar22) = uVar35 >> 0x10 | uVar35 << 0x10;
          uVar30 = uVar22 + 4;
        } while (uVar32 != 0);
        pbVar34 = pbVar34 + uVar30;
        puVar18 = (uint *)((long)&local_f0 + uVar22 + 4);
      }
      uVar32 = uVar20 & 3;
      if (uVar32 == 1) {
        uVar32 = (uint)*pbVar34 << 0x18;
LAB_0010366c:
        if ((0x3c < uVar30) || (0x3c < uVar30)) goto LAB_00103b78;
        *puVar18 = uVar32;
      }
      else {
        if (uVar32 == 2) {
          uVar32 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10;
          goto LAB_0010366c;
        }
        if (uVar32 == 3) {
          uVar32 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10 | (uint)pbVar34[2] << 8;
          goto LAB_0010366c;
        }
      }
      if (3 < uVar20) {
        lVar14 = 0;
        if (uVar12 < 2) {
          uVar12 = 1;
        }
        do {
          if (lVar14 == 0x40) goto LAB_00103b7c;
          writel_relaxed(*(undefined4 *)((long)&local_f0 + lVar14),*plVar46 + lVar14 + 0x1d000);
          lVar14 = lVar14 + 4;
        } while ((ulong)uVar12 * 4 != lVar14);
      }
      uVar12 = uVar25 | 0x400;
      if (*(int *)(param_2 + 0x1c) != 0) {
        uVar12 = uVar25;
      }
      writel_relaxed(uVar12,*plVar46 + 0x1a200);
      uVar12 = *(uint *)(param_2 + 0x30);
      puVar18 = (uint *)&local_b0;
      pbVar34 = *(byte **)(param_2 + 0x28);
      if (uVar12 < 4) {
        uVar30 = 0;
      }
      else {
        uVar20 = uVar12 >> 2;
        uVar30 = 0;
        do {
          uVar22 = uVar30;
          if ((0x3f < uVar22) || (uVar22 == 0x40)) goto LAB_00103b78;
          uVar20 = uVar20 - 1;
          uVar25 = (*(uint *)(pbVar34 + uVar22) & 0xff00ff00) >> 8 |
                   (*(uint *)(pbVar34 + uVar22) & 0xff00ff) << 8;
          *(uint *)((long)puVar18 + uVar22) = uVar25 >> 0x10 | uVar25 << 0x10;
          uVar30 = uVar22 + 4;
        } while (uVar20 != 0);
        pbVar34 = pbVar34 + uVar30;
        puVar18 = (uint *)((long)&local_b0 + uVar22 + 4);
      }
      uVar12 = uVar12 & 3;
      if (uVar12 == 1) {
        uVar12 = (uint)*pbVar34 << 0x18;
LAB_001037ac:
        if ((0x3c < uVar30) || (0x3c < uVar30)) {
LAB_00103b78:
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(1,0x103b7c);
          (*pcVar10)();
        }
        *puVar18 = uVar12;
      }
      else {
        if (uVar12 == 2) {
          uVar12 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10;
          goto LAB_001037ac;
        }
        if (uVar12 == 3) {
          uVar12 = (uint)*pbVar34 << 0x18 | (uint)pbVar34[1] << 0x10 | (uint)pbVar34[2] << 8;
          goto LAB_001037ac;
        }
      }
      lVar14 = 0x1a320;
      writel_relaxed(local_b0 & 0xffffffff,*plVar46 + 0x1d040);
      writel_relaxed(local_b0._4_4_,*plVar46 + 0x1d044);
      writel_relaxed(local_a8 & 0xffffffff,*plVar46 + 0x1d048);
      writel_relaxed(local_a8._4_4_,*plVar46 + 0x1d04c);
      writel_relaxed(local_a0 & 0xffffffff,*plVar46 + 0x1d050);
      writel_relaxed(local_a0._4_4_,*plVar46 + 0x1d054);
      writel_relaxed(local_98 & 0xffffffff,*plVar46 + 0x1d058);
      writel_relaxed(local_98._4_4_,*plVar46 + 0x1d05c);
      writel_relaxed(local_90 & 0xffffffff,*plVar46 + 0x1d060);
      writel_relaxed(local_90._4_4_,*plVar46 + 0x1d064);
      writel_relaxed(local_88 & 0xffffffff,*plVar46 + 0x1d068);
      writel_relaxed(local_88._4_4_,*plVar46 + 0x1d06c);
      writel_relaxed(local_80 & 0xffffffff,*plVar46 + 0x1d070);
      writel_relaxed(local_80._4_4_,*plVar46 + 0x1d074);
      writel_relaxed(local_78 & 0xffffffff,*plVar46 + 0x1d078);
      writel_relaxed(local_78._4_4_,*plVar46 + 0x1d07c);
      if (*(int *)(param_2 + 0x24) == 2) {
        uVar23 = 0xc3d2e1f0;
        local_140 = 0xefcdab89;
        local_138 = 0x98badcfe;
        local_13c = 0x10325476;
        writel_relaxed(0x67452301,*plVar46 + 0x1a310);
        lVar19 = 0x1a314;
        lVar15 = 0x1a318;
        lVar43 = 0x1a31c;
      }
      else {
        uVar23 = 0x5be0cd19;
        local_138 = 0x9b05688c;
        local_140 = 0x510e527f;
        local_13c = 0x1f83d9ab;
        writel_relaxed(0x6a09e667,*plVar46 + 0x1a310);
        writel_relaxed(0xbb67ae85,*plVar46 + 0x1a314);
        writel_relaxed(0x3c6ef372,*plVar46 + 0x1a318);
        writel_relaxed(0xa54ff53a,*plVar46 + 0x1a31c);
        lVar15 = 0x1a324;
        lVar43 = 0x1a328;
        lVar14 = 0x1a32c;
        lVar19 = 0x1a320;
      }
      writel_relaxed(local_140,param_1[9] + lVar19);
      writel_relaxed(local_138,param_1[9] + lVar15);
      writel_relaxed(local_13c,param_1[9] + lVar43);
      writel_relaxed(uVar23,param_1[9] + lVar14);
      writel_relaxed(0,param_1[9] + 0x1a390);
      writel_relaxed(0,param_1[9] + 0x1a394);
      writel_relaxed(*(undefined4 *)(param_2 + 0x80),param_1[9] + 0x1a204);
      writel_relaxed(uVar6,param_1[9] + 0x1a208);
      lVar14 = 0xf4;
      if (*(int *)(param_2 + 0x24) != 2) {
        lVar14 = 0xf8;
      }
      uVar12 = *(uint *)((long)param_1 + lVar14) | 0x4000;
      if (*(int *)(param_2 + 0x1c) != 0) {
        uVar12 = *(uint *)((long)param_1 + lVar14);
      }
      writel_relaxed(uVar12,param_1[9] + 0x1a300);
      writel_relaxed(uVar40,param_1[9] + 0x1a304);
      writel_relaxed(0,param_1[9] + 0x1a308);
      writel_relaxed(uVar40,param_1[9] + 0x1a110);
      writel_relaxed(*(undefined4 *)(param_1 + 0x12),param_1[9] + 0x1a400);
      writel_relaxed(7,param_1[9] + 0x1a120);
      DataSynchronizationBarrier(3,3,0);
LAB_00102eec:
      iVar42 = *(int *)((long)param_1 + 0x1ac);
      *(undefined4 *)((long)param_1 + uVar29 * 0x1bf8 + 0x2a7c) = *(undefined4 *)(param_2 + 0x20);
      iVar13 = _qce_sps_add_sg_data
                         (param_1,*(undefined8 *)(lVar44 + 0x40),uVar40,
                          param_1 + uVar29 * 0x37f + 0x1d9);
      if (iVar42 == 0) {
        if (iVar13 == 0) {
          if (*puVar28 != 0) {
            lVar14 = param_1[uVar29 * 0x37f + 0x1da] + (ulong)(*puVar28 - 1) * 8;
            *(uint *)(lVar14 + 4) = *(uint *)(lVar14 + 4) | 0x50000000;
          }
          iVar13 = _qce_sps_add_sg_data
                             (param_1,*(undefined8 *)(lVar44 + 0x48),uVar40,
                              param_1 + uVar29 * 0x37f + 0x1dd);
          if (iVar13 == 0) {
            if (uVar40 < 0x7fc1) {
              iVar13 = _qce_sps_add_data((param_1[3] +
                                         (ulong)*(uint *)(param_1 + uVar29 * 0x37f + 0x541)) -
                                         param_1[2],0x80,param_1 + uVar29 * 0x37f + 0x1dd);
              if (iVar13 != 0) goto LAB_00103174;
              iVar13 = *(int *)(param_1 + uVar29 * 0x37f + 0x1df);
              uVar27 = 2;
              uVar23 = 2;
            }
            else {
              uVar27 = 0;
              iVar13 = *(int *)(param_1 + uVar29 * 0x37f + 0x1df);
              uVar23 = 0;
            }
            if (iVar13 != 0) {
              lVar14 = param_1[uVar29 * 0x37f + 0x1de] + (ulong)(iVar13 - 1) * 8;
              *(uint *)(lVar14 + 4) = *(uint *)(lVar14 + 4) | 0x80000000;
              uVar23 = uVar27;
            }
            *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1d7) = uVar23;
            iVar13 = _qce_sps_transfer(param_1,uVar38 & 0xffffffff);
joined_r0x0010314c:
            if (iVar13 == 0) goto LAB_0010324c;
          }
        }
      }
      else if (iVar13 == 0) {
        if (*puVar28 != 0) {
          lVar14 = param_1[uVar29 * 0x37f + 0x1da] + (ulong)(*puVar28 - 1) * 8;
          *(uint *)(lVar14 + 4) = *(uint *)(lVar14 + 4) | 0x50000000;
        }
        if ((*(char *)(param_1 + 0xf) == '\0') ||
           (iVar13 = _qce_sps_add_cmd(param_1,0x200,param_1 + uVar29 * 0x37f + 0x526,
                                      param_1 + uVar29 * 0x37f + 0x1d9), iVar13 == 0)) {
          iVar13 = _qce_sps_add_sg_data
                             (param_1,*(undefined8 *)(lVar44 + 0x48),uVar40,
                              param_1 + uVar29 * 0x37f + 0x1dd);
          if (iVar13 == 0) {
            if ((*(char *)(param_1 + 0xf) == '\0') && (0x7fc0 < uVar40)) {
              uVar23 = 0;
            }
            else {
              iVar13 = _qce_sps_add_data((param_1[3] +
                                         (ulong)*(uint *)(param_1 + uVar29 * 0x37f + 0x541)) -
                                         param_1[2],0x80,param_1 + uVar29 * 0x37f + 0x1dd);
              if (iVar13 != 0) goto LAB_00103174;
              uVar23 = 2;
            }
            *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1d7) = uVar23;
            select_mode(param_1,piVar1);
            iVar13 = _qce_sps_transfer(param_1,uVar38 & 0xffffffff);
            piVar2 = (int *)((long)param_1 + 0x10a64);
            Hint_Prefetch(piVar2,2,0,1);
            do {
              if (*piVar2 != 1) goto joined_r0x0010314c;
              cVar9 = '\x01';
              bVar11 = (bool)ExclusiveMonitorPass(piVar2,0x10);
              if (bVar11) {
                *piVar2 = 0;
                cVar9 = ExclusiveMonitorsStatus();
              }
            } while (cVar9 != '\0');
            DataMemoryBarrier(2,3);
            goto joined_r0x0010314c;
          }
        }
      }
    }
    else {
      lVar14 = (*plVar46 - param_1[2]) + param_1[3];
      uVar5 = *(ushort *)(plVar46 + 0x1a);
      puVar21 = (undefined4 *)param_1[uVar29 * 0x37f + 0x1da];
      *puVar21 = (int)lVar14;
      puVar21[1] = (uint)uVar5 | (uint)((ulong)lVar14 >> 0x10) & 0xf0000 | 0xc000000;
      uVar12 = *puVar28 + 1;
      *puVar28 = uVar12;
      if (uVar12 < 0x200) goto LAB_00102eec;
      _printk(&DAT_0010fd4b,"_qce_sps_add_cmd",uVar12,0x200);
      iVar13 = -0xc;
    }
LAB_00103174:
    iVar42 = *(int *)(param_1 + uVar29 * 0x37f + 0x54b);
    if (iVar42 != 0) {
      lVar14 = *(long *)(lVar44 + 0x40);
      bVar11 = lVar14 != *(long *)(lVar44 + 0x48);
      if (0 < iVar42) {
        uVar45 = *param_1;
        do {
          dma_unmap_sg_attrs(uVar45,lVar14,1,bVar11,0);
          lVar14 = sg_next(lVar14);
          iVar42 = iVar42 + -1;
        } while (iVar42 != 0);
      }
    }
    lVar14 = *(long *)(lVar44 + 0x48);
    uVar38 = uVar38 & 0xffffffff;
    if ((*(long *)(lVar44 + 0x40) != lVar14) &&
       (iVar42 = *(int *)((long)param_1 + uVar29 * 0x1bf8 + 0x2a5c), 0 < iVar42)) {
      uVar45 = *param_1;
      do {
        dma_unmap_sg_attrs(uVar45,lVar14,1,2,0);
        lVar14 = sg_next(lVar14);
        iVar42 = iVar42 + -1;
      } while (iVar42 != 0);
    }
    *(undefined4 *)(param_1 + uVar29 * 0x37f + 0x1d6) = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar42 = *piVar1;
      cVar9 = '\x01';
      bVar11 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar11) {
        *piVar1 = 0;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    DataMemoryBarrier(2,3);
  }
  if (iVar42 == 0) {
    _printk(&DAT_00110c06,"qce_free_req_info",uVar38);
  }
LAB_0010324c:
  lVar44 = sp_el0;
  if (*(long *)(lVar44 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar13;
}



//------------------------------------------------------------
// qce_alloc_req_info @ 00103bd4 size=464
// signature: undefined qce_alloc_req_info(void)
// callers: [qce_f9_req, qce_aead_req, qce_f8_req, qce_f8_multi_pkt_req, qce_ablk_cipher_req, qce_process_sha_req]
//------------------------------------------------------------

ulong qce_alloc_req_info(long param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  ulong uVar8;
  
  iVar4 = *(int *)(param_1 + 0x10a60);
  uVar2 = 0;
  if (iVar4 + 1 < 8) {
    uVar2 = iVar4 + 1;
  }
  uVar8 = (ulong)uVar2;
  if (8 < uVar2) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x103da4);
    (*pcVar7)();
  }
  piVar1 = (int *)(param_1 + (ulong)uVar2 * 0x1bf8 + 0xea8);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar4 = *piVar1;
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar6) {
      *piVar1 = 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar4 != 0) {
    uVar3 = 0;
    if (uVar2 < 7) {
      uVar3 = uVar2 + 1;
    }
    uVar8 = (ulong)uVar3;
    piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar4 != 0) {
      uVar2 = 0;
      if (uVar3 < 7) {
        uVar2 = uVar3 + 1;
      }
      uVar8 = (ulong)uVar2;
      piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar4 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar4 != 0) {
        uVar3 = 0;
        if (uVar2 < 7) {
          uVar3 = uVar2 + 1;
        }
        uVar8 = (ulong)uVar3;
        piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar4 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar4 != 0) {
          uVar2 = 0;
          if (uVar3 < 7) {
            uVar2 = uVar3 + 1;
          }
          uVar8 = (ulong)uVar2;
          piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar4 = *piVar1;
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar6) {
              *piVar1 = 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          DataMemoryBarrier(2,3);
          if (iVar4 != 0) {
            uVar3 = 0;
            if (uVar2 < 7) {
              uVar3 = uVar2 + 1;
            }
            uVar8 = (ulong)uVar3;
            piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
            Hint_Prefetch(piVar1,2,0,1);
            do {
              iVar4 = *piVar1;
              cVar5 = '\x01';
              bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar6) {
                *piVar1 = 1;
                cVar5 = ExclusiveMonitorsStatus();
              }
            } while (cVar5 != '\0');
            DataMemoryBarrier(2,3);
            if (iVar4 != 0) {
              uVar2 = 0;
              if (uVar3 < 7) {
                uVar2 = uVar3 + 1;
              }
              uVar8 = (ulong)uVar2;
              piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
              Hint_Prefetch(piVar1,2,0,1);
              do {
                iVar4 = *piVar1;
                cVar5 = '\x01';
                bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                if (bVar6) {
                  *piVar1 = 1;
                  cVar5 = ExclusiveMonitorsStatus();
                }
              } while (cVar5 != '\0');
              DataMemoryBarrier(2,3);
              if (iVar4 != 0) {
                uVar3 = 0;
                if (uVar2 < 7) {
                  uVar3 = uVar2 + 1;
                }
                uVar8 = (ulong)uVar3;
                piVar1 = (int *)(param_1 + uVar8 * 0x1bf8 + 0xea8);
                Hint_Prefetch(piVar1,2,0,1);
                do {
                  iVar4 = *piVar1;
                  cVar5 = '\x01';
                  bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                  if (bVar6) {
                    *piVar1 = 1;
                    cVar5 = ExclusiveMonitorsStatus();
                  }
                } while (cVar5 != '\0');
                DataMemoryBarrier(2,3);
                if (iVar4 != 0) {
                  _printk(&DAT_00110e4c,"qce_alloc_req_info",*(undefined4 *)(param_1 + 0x10bc8),
                          *(undefined4 *)(param_1 + 0x10a68));
                  return 0xfffffff0;
                }
              }
            }
          }
        }
      }
    }
  }
  *(int *)(param_1 + 0x10a60) = (int)uVar8;
  return uVar8;
}



//------------------------------------------------------------
// _qce_sps_add_cmd @ 00103da4 size=132
// signature: undefined _qce_sps_add_cmd(void)
// callers: [qce_aead_req]
//------------------------------------------------------------

undefined8 _qce_sps_add_cmd(long param_1,uint param_2,long *param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  ushort uVar4;
  undefined8 uVar5;
  
  uVar4 = *(ushort *)(param_3 + 0x1a);
  lVar2 = (*param_3 - *(long *)(param_1 + 0x10)) + *(long *)(param_1 + 0x18);
  puVar3 = (undefined4 *)(*(long *)(param_4 + 8) + (ulong)*(uint *)(param_4 + 0x10) * 8);
  *puVar3 = (int)lVar2;
  puVar3[1] = (uint)uVar4 | ((uint)((ulong)lVar2 >> 0x20) & 0xf | param_2) << 0x10 | 0x8000000;
  uVar1 = *(int *)(param_4 + 0x10) + 1;
  *(uint *)(param_4 + 0x10) = uVar1;
  if (uVar1 < 0x200) {
    uVar5 = 0;
  }
  else {
    _printk(&DAT_0010fd4b,"_qce_sps_add_cmd",uVar1,0x200);
    uVar5 = 0xfffffff4;
  }
  return uVar5;
}



//------------------------------------------------------------
// _qce_sps_add_sg_data @ 00103e28 size=272
// signature: undefined _qce_sps_add_sg_data(void)
// callers: [qce_aead_req, qce_process_sha_req]
//------------------------------------------------------------

undefined8 _qce_sps_add_sg_data(long param_1,long param_2,uint param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  if ((param_3 != 0) && (param_2 != 0)) {
    puVar6 = (undefined4 *)(*(long *)(param_4 + 8) + (ulong)*(uint *)(param_4 + 0x10) * 8);
    do {
      uVar1 = param_3;
      if (*(uint *)(param_2 + 0x18) <= param_3) {
        uVar1 = *(uint *)(param_2 + 0x18);
      }
      uVar2 = uVar1;
      if (*(int *)(param_1 + 0x1ac) == 0) {
        uVar2 = (uVar1 + *(int *)(param_1 + 0x1a8)) - 1 & -*(int *)(param_1 + 0x1a8);
      }
      if (uVar2 != 0) {
        lVar3 = *(long *)(param_2 + 0x10);
        iVar4 = *(int *)(param_4 + 0x10);
        puVar5 = puVar6;
        do {
          if (iVar4 == 0x200) {
            _printk(&DAT_0010fd4b,"_qce_sps_add_sg_data",0x200,0x200);
            return 0xfffffff4;
          }
          uVar7 = uVar2;
          if (0x7fbf < uVar2) {
            uVar7 = 0x7fc0;
          }
          uVar2 = uVar2 - uVar7;
          puVar6 = puVar5 + 2;
          *puVar5 = (int)lVar3;
          puVar5[1] = (uint)((ulong)lVar3 >> 0x10) & 0xf0000 | uVar7;
          lVar3 = lVar3 + (ulong)uVar7;
          iVar4 = *(int *)(param_4 + 0x10) + 1;
          *(int *)(param_4 + 0x10) = iVar4;
          puVar5 = puVar6;
        } while (uVar2 != 0);
      }
      param_3 = param_3 - uVar1;
      param_2 = sg_next(param_2);
    } while ((param_3 != 0) && (param_2 != 0));
  }
  return 0;
}



//------------------------------------------------------------
// _qce_sps_add_data @ 00103f38 size=140
// signature: undefined _qce_sps_add_data(void)
// callers: [qce_aead_req, qce_f8_req, qce_f8_multi_pkt_req, qce_ablk_cipher_req]
//------------------------------------------------------------

undefined8 _qce_sps_add_data(long param_1,uint param_2,long param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  ulong uVar3;
  
  if (param_2 != 0) {
    uVar3 = (ulong)*(uint *)(param_3 + 0x10);
    puVar1 = (undefined4 *)(*(long *)(param_3 + 8) + uVar3 * 8);
    do {
      if ((int)uVar3 == 0x200) {
        _printk(&DAT_0010fd4b,"_qce_sps_add_data",0x200,0x200);
        return 0xfffffff4;
      }
      uVar2 = param_2;
      if (0x7fbf < param_2) {
        uVar2 = 0x7fc0;
      }
      param_2 = param_2 - uVar2;
      *puVar1 = (int)param_1;
      puVar1[1] = (uint)((ulong)param_1 >> 0x10) & 0xf0000 | uVar2;
      param_1 = param_1 + (ulong)uVar2;
      uVar2 = *(int *)(param_3 + 0x10) + 1;
      uVar3 = (ulong)uVar2;
      *(uint *)(param_3 + 0x10) = uVar2;
      puVar1 = puVar1 + 2;
    } while (param_2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// _qce_sps_transfer @ 00103fc4 size=236
// signature: undefined _qce_sps_transfer(void)
// callers: [qce_f9_req, qce_aead_req, qce_f8_req, qce_f8_multi_pkt_req, qce_ablk_cipher_req, qce_process_sha_req]
//------------------------------------------------------------

int _qce_sps_transfer(long param_1,uint param_2)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  
  if (param_2 < 9) {
    lVar6 = param_1 + (ulong)param_2 * 0x1bf8;
    uVar1 = *(ushort *)(lVar6 + 0x2a98);
    *(ulong *)(lVar6 + 0xf00) = (ulong)(param_2 | 0xdead0000);
    *(ulong *)(lVar6 + 0xee0) = (ulong)(param_2 | 0xdead0000);
    if (*(int *)(lVar6 + 0xed8) != 0) {
      lVar7 = param_1 + (ulong)uVar1 * 0xb8;
      iVar3 = sps_transfer(*(undefined8 *)(lVar7 + 0x830),param_1 + (ulong)param_2 * 0x1bf8 + 0xec8)
      ;
      if (iVar3 != 0) {
        puVar5 = (undefined8 *)(lVar7 + 0x830);
        puVar4 = &DAT_00111179;
        goto LAB_00104094;
      }
    }
    if (uVar1 < 9) {
      param_1 = param_1 + (ulong)uVar1 * 0xb8;
      iVar3 = sps_transfer(*(undefined8 *)(param_1 + 0x1b8),lVar6 + 0xee8);
      if (iVar3 == 0) {
        return 0;
      }
      puVar5 = (undefined8 *)(param_1 + 0x1b8);
      puVar4 = &DAT_0010fae4;
LAB_00104094:
      _printk(puVar4,"_qce_sps_transfer",*puVar5,iVar3);
      return iVar3;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1040b0);
  (*pcVar2)();
}



//------------------------------------------------------------
// select_mode @ 001040b0 size=428
// signature: undefined select_mode(void)
// callers: [qce_f9_req, qce_aead_req, qce_f8_req, qce_f8_multi_pkt_req, qce_ablk_cipher_req, qce_process_sha_req]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void select_mode(long param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  char cVar7;
  bool bVar8;
  uint uVar9;
  
  if (*(char *)(param_1 + 0x78) != '\0') {
    piVar2 = (int *)(param_1 + 0x10a64);
    do {
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar5 = *piVar2;
        if (iVar5 != 0) goto LAB_0010412c;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar8) {
          *piVar2 = 1;
          cVar7 = ExclusiveMonitorsStatus();
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010412c:
      if (iVar5 == 0) goto LAB_001041d4;
      __const_udelay(200);
    } while( true );
  }
LAB_00104250:
  if (*(int *)(param_2 + 0x50) != 0) {
    lVar1 = *(long *)(param_2 + 0x48) + (ulong)(*(int *)(param_2 + 0x50) - 1) * 8;
    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | 0x80000000;
  }
  return;
LAB_001041d4:
  puVar3 = (uint *)(param_1 + 0x10a68);
  Hint_Prefetch(puVar3,2,0,1);
  do {
    uVar6 = *puVar3;
    cVar7 = '\x01';
    bVar8 = (bool)ExclusiveMonitorPass(puVar3,0x10);
    if (bVar8) {
      *puVar3 = uVar6 + 1;
      cVar7 = ExclusiveMonitorsStatus();
    }
  } while (cVar7 != '\0');
  DataMemoryBarrier(2,3);
  if (*(int *)(param_1 + 0x10bc0) != 0) {
    uVar4 = *(uint *)(param_1 + 0x10bc4);
    uVar6 = uVar4 + 1;
    *(uint *)(param_1 + 0x10bc4) = uVar6;
    uVar9 = *(uint *)(param_2 + 0x1bec) >> 7;
    if (2 < uVar9) {
      uVar9 = 3;
    }
    if ((uVar9 < uVar6) && ((uVar4 != uVar9 || (*(char *)(param_1 + 0x10be4) == '\0')))) {
      if (*(int *)(param_2 + 0x50) != 0) {
        lVar1 = *(long *)(param_2 + 0x48) + (ulong)(*(int *)(param_2 + 0x50) - 1) * 8;
        *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | 0x80000000;
      }
      *(undefined4 *)(param_1 + 0x10bc4) = 0;
      *(undefined4 *)(param_1 + 0x10bdc) = 0;
      *(undefined4 *)(param_1 + 0x10be0) = 0;
      *(byte *)(param_1 + 0x10be4) = *(byte *)(param_1 + 0x10be4) ^ 1;
      return;
    }
    piVar2 = (int *)(param_1 + 0x10bdc);
    Hint_Prefetch(piVar2,2,0,1);
    do {
      cVar7 = '\x01';
      bVar8 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar8) {
        *piVar2 = *piVar2 + 1;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
    return;
  }
  if (1 < uVar6 + 1) {
    *(undefined4 *)(param_1 + 0x10bc0) = 1;
    if (*(int *)(param_2 + 0x50) != 0) {
      lVar1 = *(long *)(param_2 + 0x48) + (ulong)(*(int *)(param_2 + 0x50) - 1) * 8;
      *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | 0x80000000;
    }
    *(undefined4 *)(param_1 + 0x10bc4) = 0;
    *(undefined4 *)(param_1 + 0x10bdc) = 1;
    *(undefined4 *)(param_1 + 0x10be0) = 1;
    mod_timer(param_1 + 0x10a70,_jiffies + 5);
    return;
  }
  goto LAB_00104250;
}



//------------------------------------------------------------
// qce_ablk_cipher_req @ 001042a4 size=2120
// signature: undefined qce_ablk_cipher_req(void)
// callers: []
//------------------------------------------------------------

int qce_ablk_cipher_req(undefined8 *param_1,long param_2)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  ushort uVar7;
  char cVar8;
  code *pcVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  char *pcVar14;
  ulong uVar15;
  int iVar16;
  undefined8 *puVar17;
  undefined4 *puVar18;
  uint uVar19;
  ulong uVar20;
  undefined8 uVar21;
  uint uVar22;
  uint uVar23;
  undefined8 uVar24;
  long *plVar25;
  uint *puVar26;
  
  puVar26 = *(uint **)(param_2 + 0x10);
  uVar11 = qce_alloc_req_info();
  if ((int)uVar11 < 0) {
    return -0x10;
  }
  *(uint *)(param_2 + 0xa8) = uVar11;
  if (9 < uVar11) goto LAB_00104ae8;
  puVar4 = (uint *)(param_1 + (ulong)uVar11 * 0x37f + 0x54b);
  param_1[(ulong)uVar11 * 0x37f + 0x54b] = 0;
  uVar22 = *puVar26;
  if ((int)uVar22 < 1) {
    uVar19 = 0;
  }
  else {
    uVar19 = 0;
    lVar13 = *(long *)(puVar26 + 4);
    do {
      uVar19 = uVar19 + 1;
      uVar22 = uVar22 - *(int *)(lVar13 + 0xc);
      lVar13 = sg_next();
    } while (0 < (int)uVar22);
  }
  *puVar4 = uVar19;
  uVar20 = (ulong)uVar11;
  puVar5 = (uint *)((long)param_1 + (ulong)uVar11 * 0x1bf8 + 0x2a5c);
  if (7 < *(int *)(param_2 + 0x94) - 1U) {
    lVar13 = *(long *)(puVar26 + 4);
    bVar10 = lVar13 != *(long *)(puVar26 + 6);
    if (0 < (int)uVar19) {
      uVar24 = *param_1;
      do {
        dma_map_sg_attrs(uVar24,lVar13,1,bVar10,0);
        lVar13 = sg_next(lVar13);
        uVar19 = uVar19 - 1;
      } while (uVar19 != 0);
    }
  }
  lVar13 = *(long *)(puVar26 + 6);
  if (*(long *)(puVar26 + 4) == lVar13) {
    uVar22 = *puVar4;
LAB_0010445c:
    *puVar5 = uVar22;
  }
  else {
    uVar22 = *puVar26;
    if ((int)uVar22 < 1) {
      uVar22 = 0;
      goto LAB_0010445c;
    }
    uVar19 = 0;
    do {
      uVar23 = uVar19;
      uVar19 = uVar23 + 1;
      uVar22 = uVar22 - *(int *)(lVar13 + 0xc);
      lVar13 = sg_next();
    } while (0 < (int)uVar22);
    *puVar5 = uVar19;
    if ((7 < *(int *)(param_2 + 0x94) - 1U) && (uVar23 < 0x7fffffff)) {
      uVar21 = *param_1;
      uVar24 = *(undefined8 *)(puVar26 + 6);
      do {
        dma_map_sg_attrs(uVar21,uVar24,1,2,0);
        uVar24 = sg_next(uVar24);
        uVar19 = uVar19 - 1;
      } while (uVar19 != 0);
    }
  }
  iVar12 = *(int *)(param_2 + 0x1c);
  iVar16 = *(int *)((long)param_1 + 0x1ac);
  piVar1 = (int *)(param_1 + (ulong)uVar11 * 0x37f + 0x1d5);
  *(int *)(param_1 + uVar20 * 0x37f + 0x54f) = iVar12;
  if (((iVar16 == 0) && (iVar12 == 1)) && (*(int *)(param_2 + 0x20) == 0)) {
    lVar13 = ((**(ulong **)(puVar26 + 4) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
             (ulong)(uint)(*(ulong **)(puVar26 + 4))[1] +
             (ulong)*(uint *)(*(long *)(puVar26 + 4) + 0xc);
    uVar24 = *(undefined8 *)(lVar13 + -8);
    param_1[uVar20 * 0x37f + 0x54d] = *(undefined8 *)(lVar13 + -0x10);
    param_1[uVar20 * 0x37f + 0x54e] = uVar24;
    if (*(char *)(param_1 + 8) == '\0') goto LAB_001045a0;
LAB_001044a0:
    iVar12 = *(int *)(param_2 + 0x18);
    if (iVar12 != 0) {
      if (iVar12 == 1) {
        iVar16 = *(int *)(param_2 + 0x20);
        puVar17 = param_1 + uVar20 * 0x37f;
        if (iVar16 == 1) {
          lVar13 = 0x16a0;
          goto LAB_00104538;
        }
        plVar25 = puVar17 + 0x2b9;
        goto LAB_00104660;
      }
      if (iVar12 == 2) {
        iVar16 = *(int *)(param_2 + 0x20);
        switch(iVar16) {
        case 0:
        case 2:
          lVar13 = uVar20 * 0x37f + 0x1e1;
          if (*(int *)(param_2 + 0x68) != 0x10) {
            lVar13 = uVar20 * 0x37f + 0x1fc;
          }
          plVar25 = param_1 + lVar13;
          break;
        case 1:
          if (*(int *)(param_2 + 0x68) == 0x10) {
            lVar13 = 0x10b8;
            puVar17 = param_1 + uVar20 * 0x37f;
          }
          else {
            lVar13 = 0x1190;
            puVar17 = param_1 + uVar20 * 0x37f;
          }
          goto LAB_00104538;
        case 3:
          if ((*(uint *)(param_2 + 0x68) & 0xfffffffe) == 0x20) {
            lVar13 = 0x1268;
          }
          else {
            lVar13 = 0x1340;
          }
          plVar25 = (long *)((long)param_1 + lVar13 + uVar20 * 0x1bf8);
          iVar16 = 3;
          break;
        case 4:
          if (*(int *)(param_2 + 0x68) == 0x10) {
            lVar13 = 0x2348;
          }
          else {
            lVar13 = 0x2420;
          }
          plVar25 = (long *)((long)param_1 + lVar13 + uVar20 * 0x1bf8);
          iVar16 = 4;
          break;
        default:
          goto switchD_001044d8_default;
        }
        goto LAB_00104660;
      }
      iVar16 = *(int *)(param_2 + 0x20);
switchD_001044d8_default:
      _printk(&DAT_0010fd14,"qce_ablk_cipher_req",iVar12,iVar16);
      if (8 < uVar11) goto LAB_00104ae8;
      iVar12 = -0x16;
      *(undefined4 *)(param_1 + uVar20 * 0x37f + 0x1d6) = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar16 = *piVar1;
        cVar8 = '\x01';
        bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar10) {
          *piVar1 = 0;
          cVar8 = ExclusiveMonitorsStatus();
        }
      } while (cVar8 != '\0');
      DataMemoryBarrier(2,3);
      goto joined_r0x00104ac8;
    }
    iVar16 = *(int *)(param_2 + 0x20);
    puVar17 = param_1 + uVar20 * 0x37f;
    if (iVar16 == 1) {
      lVar13 = 0x14f0;
LAB_00104538:
      plVar25 = (long *)((long)puVar17 + lVar13);
      iVar16 = 1;
    }
    else {
      plVar25 = puVar17 + 0x283;
    }
LAB_00104660:
    if (plVar25 == (long *)0x0) goto switchD_001044d8_default;
    iVar12 = _ce_setup_cipher(param_1,param_2,*puVar26,0,plVar25);
    if (-1 < iVar12) goto LAB_00104680;
  }
  else {
    if (*(char *)(param_1 + 8) != '\0') goto LAB_001044a0;
LAB_001045a0:
    _ce_setup_cipher_direct(param_1,param_2,*puVar26,0);
    plVar25 = (long *)0x0;
LAB_00104680:
    *(undefined4 *)((long)param_1 + uVar20 * 0x1bf8 + 0x2a7c) = *(undefined4 *)(param_2 + 0x20);
    uVar6 = *(undefined4 *)(param_2 + 0x94);
    param_1[uVar20 * 0x37f + 0x548] = puVar26;
    *(undefined4 *)(param_1 + uVar20 * 0x37f + 0x553) = uVar6;
    uVar24 = *(undefined8 *)(param_2 + 8);
    *(undefined4 *)(param_1 + uVar20 * 0x37f + 0x1d6) = 1;
    param_1[uVar20 * 0x37f + 0x546] = uVar24;
    *(uint *)((long)param_1 + uVar20 * 0x1bf8 + 0x2a94) = *puVar26;
    if (8 < uVar11) goto LAB_00104ae8;
    uVar15 = 0;
    cVar8 = *(char *)(param_1 + 8);
    puVar2 = (uint *)(param_1 + uVar20 * 0x37f + 0x1db);
    *(undefined4 *)(param_1 + uVar20 * 0x37f + 0x1db) = 0;
    *(undefined4 *)(param_1 + uVar20 * 0x37f + 0x1df) = 0;
    if ((cVar8 == '\0') || (plVar25 == (long *)0x0)) {
LAB_00104728:
      uVar22 = *puVar26;
      if (uVar22 != 0) {
        lVar13 = *(long *)(*(long *)(puVar26 + 4) + 0x10);
        puVar18 = (undefined4 *)(param_1[uVar20 * 0x37f + 0x1da] + uVar15 * 8);
        do {
          if ((int)uVar15 == 0x200) {
            pcVar14 = "_qce_sps_add_data";
            goto LAB_00104968;
          }
          uVar19 = uVar22;
          if (0x7fbf < uVar22) {
            uVar19 = 0x7fc0;
          }
          uVar22 = uVar22 - uVar19;
          *puVar18 = (int)lVar13;
          puVar18[1] = (uint)((ulong)lVar13 >> 0x10) & 0xf0000 | uVar19;
          lVar13 = lVar13 + (ulong)uVar19;
          uVar15 = (ulong)(*puVar2 + 1);
          *puVar2 = *puVar2 + 1;
          puVar18 = puVar18 + 2;
        } while (uVar22 != 0);
      }
      if ((int)uVar15 != 0) {
        lVar13 = param_1[uVar20 * 0x37f + 0x1da] + (ulong)((int)uVar15 - 1) * 8;
        *(uint *)(lVar13 + 4) = *(uint *)(lVar13 + 4) | 0x50000000;
      }
      if (*(char *)(param_1 + 0xf) != '\0') {
        uVar7 = *(ushort *)(param_1 + uVar20 * 0x37f + 0x540);
        lVar13 = (param_1[uVar20 * 0x37f + 0x526] - param_1[2]) + param_1[3];
        puVar18 = (undefined4 *)(param_1[uVar20 * 0x37f + 0x1da] + (ulong)*puVar2 * 8);
        *puVar18 = (int)lVar13;
        puVar18[1] = uVar7 | 0xa000000 | (uint)((ulong)lVar13 >> 0x10) & 0xf0000;
        uVar22 = *puVar2 + 1;
        uVar15 = (ulong)uVar22;
        *puVar2 = uVar22;
        if (0x1ff < uVar22) goto LAB_0010492c;
      }
      uVar22 = *puVar26;
      if (uVar22 != 0) {
        puVar2 = (uint *)(param_1 + uVar20 * 0x37f + 0x1df);
        uVar15 = (ulong)*puVar2;
        lVar13 = *(long *)(*(long *)(puVar26 + 6) + 0x10);
        puVar18 = (undefined4 *)(param_1[uVar20 * 0x37f + 0x1de] + uVar15 * 8);
        do {
          if ((int)uVar15 == 0x200) {
            pcVar14 = "_qce_sps_add_data";
            uVar15 = 0x200;
            goto LAB_00104968;
          }
          uVar19 = uVar22;
          if (0x7fbf < uVar22) {
            uVar19 = 0x7fc0;
          }
          uVar22 = uVar22 - uVar19;
          *puVar18 = (int)lVar13;
          puVar18[1] = (uint)((ulong)lVar13 >> 0x10) & 0xf0000 | uVar19;
          lVar13 = lVar13 + (ulong)uVar19;
          uVar15 = (ulong)(*puVar2 + 1);
          *puVar2 = *puVar2 + 1;
          puVar18 = puVar18 + 2;
        } while (uVar22 != 0);
      }
      if ((*(char *)(param_1 + 0xf) == '\0') && (0x7fc0 < *puVar26)) {
        *(undefined4 *)(param_1 + (ulong)uVar11 * 0x37f + 0x1d7) = 0;
      }
      else {
        *(undefined4 *)(param_1 + (ulong)uVar11 * 0x37f + 0x1d7) = 2;
        if ((7 < *(int *)(param_2 + 0x94) - 1U) &&
           (iVar12 = _qce_sps_add_data((param_1[3] +
                                       (ulong)*(uint *)(param_1 + uVar20 * 0x37f + 0x541)) -
                                       param_1[2],0x80,param_1 + uVar20 * 0x37f + 0x1dd),
           iVar12 != 0)) goto LAB_00104974;
      }
      select_mode(param_1,piVar1);
      iVar12 = _qce_sps_transfer(param_1,uVar11);
      piVar3 = (int *)((long)param_1 + 0x10a64);
      Hint_Prefetch(piVar3,2,0,1);
      do {
        if (*piVar3 != 1) goto LAB_00104b0c;
        cVar8 = '\x01';
        bVar10 = (bool)ExclusiveMonitorPass(piVar3,0x10);
        if (bVar10) {
          *piVar3 = 0;
          cVar8 = ExclusiveMonitorsStatus();
        }
      } while (cVar8 != '\0');
      DataMemoryBarrier(2,3);
LAB_00104b0c:
      if (iVar12 == 0) {
        return 0;
      }
    }
    else {
      lVar13 = (*plVar25 - param_1[2]) + param_1[3];
      uVar7 = *(ushort *)(plVar25 + 0x1a);
      puVar18 = (undefined4 *)param_1[uVar20 * 0x37f + 0x1da];
      *puVar18 = (int)lVar13;
      puVar18[1] = (uint)uVar7 | (uint)((ulong)lVar13 >> 0x10) & 0xf0000 | 0xc000000;
      uVar22 = *puVar2 + 1;
      uVar15 = (ulong)uVar22;
      *puVar2 = uVar22;
      if (uVar22 < 0x200) goto LAB_00104728;
LAB_0010492c:
      pcVar14 = "_qce_sps_add_cmd";
LAB_00104968:
      _printk(&DAT_0010fd4b,pcVar14,uVar15,0x200);
      iVar12 = -0xc;
    }
  }
LAB_00104974:
  if (7 < *(int *)(param_2 + 0x94) - 1U) {
    lVar13 = *(long *)(puVar26 + 6);
    if (((*(long *)(puVar26 + 4) != lVar13) && (uVar22 = *puVar5, uVar22 != 0)) && (0 < (int)uVar22)
       ) {
      uVar24 = *param_1;
      do {
        dma_unmap_sg_attrs(uVar24,lVar13,1,2,0);
        lVar13 = sg_next(lVar13);
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
    }
    uVar22 = *puVar4;
    if (uVar22 != 0) {
      lVar13 = *(long *)(puVar26 + 4);
      bVar10 = lVar13 != *(long *)(puVar26 + 6);
      if (0 < (int)uVar22) {
        uVar24 = *param_1;
        do {
          dma_unmap_sg_attrs(uVar24,lVar13,1,bVar10,0);
          lVar13 = sg_next(lVar13);
          uVar22 = uVar22 - 1;
        } while (uVar22 != 0);
      }
    }
  }
  if (uVar11 < 9) {
    *(undefined4 *)(param_1 + uVar20 * 0x37f + 0x1d6) = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar16 = *piVar1;
      cVar8 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = 0;
        cVar8 = ExclusiveMonitorsStatus();
      }
    } while (cVar8 != '\0');
    DataMemoryBarrier(2,3);
joined_r0x00104ac8:
    if (iVar16 == 0) {
      _printk(&DAT_00110c06,"qce_free_req_info",uVar11);
    }
    return iVar12;
  }
LAB_00104ae8:
                    /* WARNING: Does not return */
  pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x104aec);
  (*pcVar9)();
}



//------------------------------------------------------------
// _ce_setup_cipher @ 00104b14 size=3532
// signature: undefined _ce_setup_cipher(void)
// callers: [qce_aead_req, qce_ablk_cipher_req]
//------------------------------------------------------------

void _ce_setup_cipher(long param_1,int *param_2,int param_3,uint param_4,long param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  bool bVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  ulong uVar17;
  ulong uVar18;
  long *plVar19;
  byte *pbVar20;
  uint uVar21;
  long lVar22;
  uint uVar23;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  uint local_a8 [16];
  long local_68;
  
  lVar22 = sp_el0;
  local_68 = *(long *)(lVar22 + 0x638);
  local_a8[0xc] = 0;
  local_a8[0xd] = 0;
  local_a8[0xe] = 0;
  local_a8[0xf] = 0;
  local_a8[8] = 0;
  local_a8[9] = 0;
  local_a8[10] = 0;
  local_a8[0xb] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_b8 = 0;
  local_b0 = 0;
  if (8 < (uint)param_2[0x25]) goto LAB_001058d8;
  uVar8 = param_2[0x1e];
  uVar2 = (*(uint *)(param_1 + 0x1a8) >> 3) * 0x20000 - 0x1fff2 |
          *(int *)(param_1 + (ulong)(uint)param_2[0x25] * 4 + 0x134) << 5;
  uVar15 = (uint)param_2[0x1a] >> (param_2[8] == 3);
  *(uint *)(param_1 + 0x8c) = uVar2;
  *(uint *)(param_1 + 0x90) = uVar2 | 0x200;
  *(uint *)(*(long *)(param_5 + 8) + 4) = uVar2;
  *(undefined4 *)(*(long *)(param_5 + 0x10) + 4) = *(undefined4 *)(param_1 + 0x90);
  puVar16 = *(uint **)(param_5 + 200);
  uVar1 = param_2[0x24];
  uVar2 = uVar1 & 3;
  uVar21 = (uint)*(byte *)((long)puVar16 + 3) << 0x18;
  if ((uVar1 & 1) == 0) {
    *puVar16 = uVar21 | *(int *)(param_1 + 0x50) + 0x1a120U & 0xffffff;
    if (uVar2 == 2) {
      uVar23 = 0;
    }
    else {
      pbVar20 = *(byte **)(param_2 + 0x18);
      puVar16 = local_a8;
      uVar23 = uVar15 >> 2;
      if (uVar15 < 4) {
        uVar17 = 0;
      }
      else {
        uVar17 = 0;
        uVar21 = uVar23;
        do {
          uVar18 = uVar17;
          if (0x3f < uVar18) goto LAB_001058d4;
          uVar21 = uVar21 - 1;
          uVar11 = (*(uint *)(pbVar20 + uVar18) & 0xff00ff00) >> 8 |
                   (*(uint *)(pbVar20 + uVar18) & 0xff00ff) << 8;
          *(uint *)((long)puVar16 + uVar18) = uVar11 >> 0x10 | uVar11 << 0x10;
          uVar17 = uVar18 + 4;
        } while (uVar21 != 0);
        pbVar20 = pbVar20 + uVar17;
        puVar16 = (uint *)((long)local_a8 + uVar18 + 4);
      }
      uVar21 = uVar15 & 3;
      if (uVar21 == 1) {
        uVar21 = (uint)*pbVar20 << 0x18;
      }
      else if (uVar21 == 2) {
        uVar21 = (uint)*pbVar20 << 0x18 | (uint)pbVar20[1] << 0x10;
      }
      else {
        if (uVar21 != 3) goto LAB_00104cd4;
        uVar21 = (uint)*pbVar20 << 0x18 | (uint)pbVar20[1] << 0x10 | (uint)pbVar20[2] << 8;
      }
      if (0x3c < uVar17) goto LAB_001058d4;
      *puVar16 = uVar21;
    }
  }
  else {
    uVar23 = 0;
    *puVar16 = uVar21 | *(int *)(param_1 + 0x50) + 0x1b000U & 0xffffff;
  }
LAB_00104cd4:
  uVar1 = uVar1 & 1;
  if (*param_2 == 2) {
    iVar12 = param_2[8];
    if (iVar12 == 4) {
      lVar22 = *(long *)(param_5 + 0xb0);
      uVar21 = param_2[0x1a];
      uVar11 = (param_2[0xe] & 0xff00ff00U) >> 8 | (param_2[0xe] & 0xff00ffU) << 8;
      uVar14 = (param_2[0xf] & 0xff00ff00U) >> 8 | (param_2[0xf] & 0xff00ffU) << 8;
      uVar3 = (param_2[0x10] & 0xff00ff00U) >> 8 | (param_2[0x10] & 0xff00ffU) << 8;
      uVar4 = (param_2[0x11] & 0xff00ff00U) >> 8 | (param_2[0x11] & 0xff00ffU) << 8;
      *(uint *)(lVar22 + 4) = uVar11 >> 0x10 | uVar11 << 0x10;
      *(uint *)(lVar22 + 0x14) = uVar14 >> 0x10 | uVar14 << 0x10;
      *(uint *)(lVar22 + 0x24) = uVar3 >> 0x10 | uVar3 << 0x10;
      *(uint *)(lVar22 + 0x34) = uVar4 >> 0x10 | uVar4 << 0x10;
      if (param_2[0xc] == 0x10) {
        puVar16 = (uint *)(param_1 + 0xec);
LAB_00104d48:
        uVar11 = *puVar16;
      }
      else {
        if (param_2[0xc] == 0x20) {
          puVar16 = (uint *)(param_1 + 0xf0);
          goto LAB_00104d48;
        }
        uVar11 = 0;
      }
      if (param_2[7] != 0) {
        uVar11 = uVar11 | 0x4000;
      }
      uVar11 = param_2[0xd] * 0x200 - 0x200U | uVar11;
      if (uVar1 == 0) {
        uVar11 = uVar11 & 0xfffbffff;
        if (3 < uVar21) {
          uVar14 = uVar21 >> 2;
          lVar22 = *(long *)(param_5 + 0xa0);
          if (uVar14 < 2) {
            uVar14 = 1;
          }
          *(uint *)(lVar22 + 4) = local_a8[0];
          if (7 < uVar21) {
            *(uint *)(lVar22 + 0x14) = local_a8[1];
            if (uVar14 != 2) {
              *(uint *)(lVar22 + 0x24) = local_a8[2];
              if (uVar14 != 3) {
                *(uint *)(lVar22 + 0x34) = local_a8[3];
                if (uVar14 != 4) {
                  *(uint *)(lVar22 + 0x44) = local_a8[4];
                  if (uVar14 != 5) {
                    *(uint *)(lVar22 + 0x54) = local_a8[5];
                    if (uVar14 != 6) {
                      *(uint *)(lVar22 + 100) = local_a8[6];
                      if (uVar14 != 7) {
                        *(uint *)(lVar22 + 0x74) = local_a8[7];
                        if (uVar14 != 8) {
                          *(uint *)(lVar22 + 0x84) = local_a8[8];
                          if (uVar14 != 9) {
                            *(uint *)(lVar22 + 0x94) = local_a8[9];
                            if (uVar14 != 10) {
                              *(uint *)(lVar22 + 0xa4) = local_a8[10];
                              if (uVar14 != 0xb) {
                                *(uint *)(lVar22 + 0xb4) = local_a8[0xb];
                                if (uVar14 != 0xc) {
                                  *(uint *)(lVar22 + 0xc4) = local_a8[0xc];
                                  if (uVar14 != 0xd) {
                                    *(uint *)(lVar22 + 0xd4) = local_a8[0xd];
                                    if (uVar14 != 0xe) {
                                      *(uint *)(lVar22 + 0xe4) = local_a8[0xe];
                                      if (uVar14 != 0xf) {
                                        *(uint *)(lVar22 + 0xf4) = local_a8[0xf];
                                        if (uVar14 != 0x10) goto LAB_001058d8;
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
                  }
                }
              }
            }
          }
        }
      }
      else {
        uVar11 = uVar11 | 0x40000;
      }
      *(uint *)(*(long *)(param_5 + 0x88) + 4) = uVar11;
      iVar12 = param_3;
      if (param_2[7] != 0) {
        iVar12 = param_3 - param_2[0xd];
      }
      plVar19 = (long *)(param_5 + 0x98);
      *(int *)(*(long *)(param_5 + 0x90) + 4) = iVar12;
      goto LAB_00104ec4;
    }
  }
  else {
    plVar19 = (long *)(param_5 + 0x88);
LAB_00104ec4:
    *(undefined4 *)(*plVar19 + 4) = 0;
    iVar12 = param_2[8];
  }
  switch(iVar12) {
  case 0:
    if (uVar15 == 0x10) {
      uVar21 = *(uint *)(param_1 + 0x94);
    }
    else {
      uVar21 = *(uint *)(param_1 + 0x98);
    }
    break;
  case 1:
    if (uVar15 == 0x10) {
      uVar21 = *(uint *)(param_1 + 0x9c);
    }
    else {
      uVar21 = *(uint *)(param_1 + 0xa0);
    }
    break;
  default:
    if (uVar15 == 0x10) {
      uVar21 = *(uint *)(param_1 + 0xac);
    }
    else {
      uVar21 = *(uint *)(param_1 + 0xb0);
    }
    break;
  case 3:
    if (uVar15 == 0x10) {
      uVar21 = *(uint *)(param_1 + 0xa4);
    }
    else {
      uVar21 = *(uint *)(param_1 + 0xa8);
    }
    break;
  case 4:
    lVar22 = 0xb4;
    if (uVar15 != 0x10) {
      lVar22 = 0xb8;
    }
    uVar21 = *(uint *)(param_1 + lVar22) | 0x2100;
  }
  if (param_2[6] == 1) {
    if (iVar12 != 1) {
      if (0x10 < uVar8) {
LAB_0010550c:
        _printk(&DAT_0011019b,"_ce_setup_cipher","_ce_setup_cipher");
        uVar6 = 0xffffffea;
        goto LAB_0010589c;
      }
      puVar9 = *(uint **)(param_2 + 0x1c);
      puVar16 = (uint *)&local_b8;
      if (uVar8 < 4) {
        uVar17 = 0xfffffffffffffff3;
        puVar10 = puVar9;
      }
      else {
        puVar10 = puVar9 + 1;
        uVar15 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8;
        uVar23 = uVar15 >> 0x10 | uVar15 << 0x10;
        uVar15 = uVar8 >> 2;
        local_b8 = (ulong)uVar23;
        if (uVar15 == 1) {
          puVar16 = (uint *)((ulong)puVar16 | 4);
          uVar17 = 0xfffffffffffffff7;
        }
        else {
          uVar11 = (puVar9[1] & 0xff00ff00) >> 8 | (puVar9[1] & 0xff00ff) << 8;
          local_b8 = CONCAT44(uVar11 >> 0x10 | uVar11 << 0x10,uVar23);
          if (uVar15 == 2) {
            puVar10 = puVar9 + 2;
            puVar16 = (uint *)&local_b0;
            uVar17 = 0xfffffffffffffffb;
          }
          else {
            uVar23 = (puVar9[2] & 0xff00ff00) >> 8 | (puVar9[2] & 0xff00ff) << 8;
            uVar23 = uVar23 >> 0x10 | uVar23 << 0x10;
            local_b0 = (ulong)uVar23;
            if (uVar15 == 3) {
              puVar10 = puVar9 + 3;
              puVar16 = (uint *)((long)&local_b0 + 4);
              uVar17 = 0xffffffffffffffff;
            }
            else {
              puVar10 = puVar9 + 4;
              uVar17 = 3;
              uVar15 = (puVar9[3] & 0xff00ff00) >> 8 | (puVar9[3] & 0xff00ff) << 8;
              puVar16 = local_a8;
              local_b0 = CONCAT44(uVar15 >> 0x10 | uVar15 << 0x10,uVar23);
            }
          }
        }
      }
      uVar8 = uVar8 & 3;
      if (uVar8 == 1) {
        uVar8 = (uint)(byte)*puVar10 << 0x18;
LAB_00105278:
        if (uVar17 < 4) {
LAB_001058d4:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x1058d8);
          (*pcVar5)();
        }
        *puVar16 = uVar8;
      }
      else {
        if (uVar8 == 2) {
          uVar8 = (uint)(byte)*puVar10 << 0x18 | (uint)*(byte *)((long)puVar10 + 1) << 0x10;
          goto LAB_00105278;
        }
        if (uVar8 == 3) {
          uVar8 = (uint)(byte)*puVar10 << 0x18 | (uint)*(byte *)((long)puVar10 + 1) << 0x10 |
                  (uint)*(byte *)((long)puVar10 + 2) << 8;
          goto LAB_00105278;
        }
      }
      lVar22 = *(long *)(param_5 + 0x40);
      *(uint *)(lVar22 + 4) = (uint)local_b8;
      *(undefined4 *)(lVar22 + 0x14) = local_b8._4_4_;
    }
    if (uVar1 == 0) {
      lVar22 = *(long *)(param_5 + 0x30);
      *(uint *)(lVar22 + 4) = local_a8[0];
      *(uint *)(lVar22 + 0x14) = local_a8[1];
      *(uint *)(lVar22 + 0x24) = local_a8[2];
      *(uint *)(lVar22 + 0x34) = local_a8[3];
      bVar7 = true;
      *(uint *)(lVar22 + 0x44) = local_a8[4];
      *(uint *)(lVar22 + 0x54) = local_a8[5];
    }
    else {
LAB_00105298:
      bVar7 = true;
    }
  }
  else if (param_2[6] == 0) {
    if (iVar12 != 1) {
      if (0x10 < uVar8) goto LAB_0010550c;
      puVar9 = *(uint **)(param_2 + 0x1c);
      puVar16 = (uint *)&local_b8;
      if (uVar8 < 4) {
        uVar17 = 0xfffffffffffffff3;
        puVar10 = puVar9;
      }
      else {
        puVar10 = puVar9 + 1;
        uVar15 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8;
        uVar23 = uVar15 >> 0x10 | uVar15 << 0x10;
        uVar15 = uVar8 >> 2;
        local_b8 = (ulong)uVar23;
        if (uVar15 == 1) {
          puVar16 = (uint *)((ulong)puVar16 | 4);
          uVar17 = 0xfffffffffffffff7;
        }
        else {
          uVar11 = (puVar9[1] & 0xff00ff00) >> 8 | (puVar9[1] & 0xff00ff) << 8;
          local_b8 = CONCAT44(uVar11 >> 0x10 | uVar11 << 0x10,uVar23);
          if (uVar15 == 2) {
            puVar10 = puVar9 + 2;
            puVar16 = (uint *)&local_b0;
            uVar17 = 0xfffffffffffffffb;
          }
          else {
            uVar23 = (puVar9[2] & 0xff00ff00) >> 8 | (puVar9[2] & 0xff00ff) << 8;
            uVar23 = uVar23 >> 0x10 | uVar23 << 0x10;
            local_b0 = (ulong)uVar23;
            if (uVar15 == 3) {
              puVar10 = puVar9 + 3;
              puVar16 = (uint *)((long)&local_b0 + 4);
              uVar17 = 0xffffffffffffffff;
            }
            else {
              puVar10 = puVar9 + 4;
              uVar17 = 3;
              uVar15 = (puVar9[3] & 0xff00ff00) >> 8 | (puVar9[3] & 0xff00ff) << 8;
              puVar16 = local_a8;
              local_b0 = CONCAT44(uVar15 >> 0x10 | uVar15 << 0x10,uVar23);
            }
          }
        }
      }
      uVar8 = uVar8 & 3;
      if (uVar8 == 1) {
        uVar8 = (uint)(byte)*puVar10 << 0x18;
LAB_001051d0:
        if (uVar17 < 4) goto LAB_001058d4;
        *puVar16 = uVar8;
      }
      else {
        if (uVar8 == 2) {
          uVar8 = (uint)(byte)*puVar10 << 0x18 | (uint)*(byte *)((long)puVar10 + 1) << 0x10;
          goto LAB_001051d0;
        }
        if (uVar8 == 3) {
          uVar8 = (uint)(byte)*puVar10 << 0x18 | (uint)*(byte *)((long)puVar10 + 1) << 0x10 |
                  (uint)*(byte *)((long)puVar10 + 2) << 8;
          goto LAB_001051d0;
        }
      }
      lVar22 = *(long *)(param_5 + 0x40);
      *(uint *)(lVar22 + 4) = (uint)local_b8;
      *(undefined4 *)(lVar22 + 0x14) = local_b8._4_4_;
    }
    if (uVar1 != 0) goto LAB_00105298;
    lVar22 = *(long *)(param_5 + 0x30);
    bVar7 = true;
    *(uint *)(lVar22 + 4) = local_a8[0];
    *(uint *)(lVar22 + 0x14) = local_a8[1];
  }
  else {
    if (iVar12 == 3) {
      local_c8 = 0;
      local_c0 = 0;
      local_d8 = 0;
      local_d0 = 0;
      if ((uVar1 == 0) && (uVar2 != 2)) {
        uVar11 = param_2[0x1a];
        uVar15 = uVar11 >> 3;
        puVar16 = (uint *)(*(long *)(param_2 + 0x18) + (ulong)(uVar11 >> 1));
        if (uVar11 < 8) {
          uVar17 = 0;
          puVar9 = (uint *)((long)&local_c0 + 4);
          puVar10 = puVar16;
        }
        else {
          uVar14 = (*puVar16 & 0xff00ff00) >> 8 | (*puVar16 & 0xff00ff) << 8;
          uVar14 = uVar14 >> 0x10 | uVar14 << 0x10;
          local_c0 = (ulong)uVar14 << 0x20;
          if (uVar15 == 1) {
            puVar9 = (uint *)&local_c0;
            uVar17 = 4;
            puVar10 = puVar16 + 1;
          }
          else {
            uVar3 = puVar16[1];
            uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
            local_c0 = CONCAT44(uVar14,uVar3 >> 0x10 | uVar3 << 0x10);
            if (uVar15 == 2) {
              puVar9 = (uint *)((long)&local_c8 + 4);
              uVar17 = 8;
              puVar10 = puVar16 + 2;
            }
            else {
              uVar14 = puVar16[2];
              uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
              uVar14 = uVar14 >> 0x10 | uVar14 << 0x10;
              local_c8 = (ulong)uVar14 << 0x20;
              if (uVar15 == 3) {
                puVar9 = (uint *)&local_c8;
                uVar17 = 0xc;
                puVar10 = puVar16 + 3;
              }
              else {
                uVar3 = puVar16[3];
                uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
                local_c8 = CONCAT44(uVar14,uVar3 >> 0x10 | uVar3 << 0x10);
                if (uVar15 == 4) {
                  puVar9 = (uint *)((long)&local_d0 + 4);
                  uVar17 = 0x10;
                  puVar10 = puVar16 + 4;
                }
                else {
                  uVar14 = puVar16[4];
                  uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
                  uVar14 = uVar14 >> 0x10 | uVar14 << 0x10;
                  local_d0 = (ulong)uVar14 << 0x20;
                  if (uVar15 == 5) {
                    puVar9 = (uint *)&local_d0;
                    uVar17 = 0x14;
                    puVar10 = puVar16 + 5;
                  }
                  else {
                    uVar3 = puVar16[5];
                    uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
                    local_d0 = CONCAT44(uVar14,uVar3 >> 0x10 | uVar3 << 0x10);
                    if (uVar15 == 6) {
                      puVar9 = (uint *)((long)&local_d8 + 4);
                      uVar17 = 0x18;
                      puVar10 = puVar16 + 6;
                    }
                    else {
                      uVar14 = puVar16[6];
                      uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
                      uVar14 = uVar14 >> 0x10 | uVar14 << 0x10;
                      local_d8 = (ulong)uVar14 << 0x20;
                      if (uVar15 == 7) {
                        puVar9 = (uint *)&local_d8;
                        uVar17 = 0x1c;
                        puVar10 = puVar16 + 7;
                      }
                      else {
                        puVar10 = puVar16 + 8;
                        uVar3 = puVar16[7];
                        uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
                        uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
                        puVar9 = (uint *)(ulong)uVar3;
                        local_d8 = CONCAT44(uVar14,uVar3);
                        if (uVar15 != 8) goto LAB_001058d4;
                        uVar17 = 0x20;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        uVar14 = uVar11 >> 1 & 3;
        if (uVar14 == 1) {
          uVar14 = (uint)(byte)*puVar10 << 0x18;
LAB_001053bc:
          if (0x1c < uVar17) goto LAB_001058d4;
          *puVar9 = uVar14;
        }
        else {
          if (uVar14 == 2) {
            uVar14 = (uint)(byte)*puVar10 << 0x18 | (uint)*(byte *)((long)puVar10 + 1) << 0x10;
            goto LAB_001053bc;
          }
          if (uVar14 == 3) {
            uVar14 = (uint)(byte)*puVar10 << 0x18 | (uint)*(byte *)((long)puVar10 + 1) << 0x10 |
                     (uint)*(byte *)((long)puVar10 + 2) << 8;
            goto LAB_001053bc;
          }
        }
        if (7 < uVar11) {
          lVar22 = *(long *)(param_5 + 0x38);
          if (uVar15 < 2) {
            uVar15 = 1;
          }
          *(undefined4 *)(lVar22 + 4) = local_c0._4_4_;
          if (0xf < uVar11) {
            *(uint *)(lVar22 + 0x14) = (uint)local_c0;
            if (uVar15 != 2) {
              *(undefined4 *)(lVar22 + 0x24) = local_c8._4_4_;
              if (uVar15 != 3) {
                *(uint *)(lVar22 + 0x34) = (uint)local_c8;
                if (uVar15 != 4) {
                  *(undefined4 *)(lVar22 + 0x44) = local_d0._4_4_;
                  if (uVar15 != 5) {
                    *(uint *)(lVar22 + 0x54) = (uint)local_d0;
                    if (uVar15 != 6) {
                      *(undefined4 *)(lVar22 + 100) = local_d8._4_4_;
                      if (uVar15 != 7) {
                        *(uint *)(lVar22 + 0x74) = (uint)local_d8;
                        if (uVar15 != 8) goto LAB_001058d8;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (*(char *)((long)param_2 + 0x91) == '\x02') {
        uVar15 = param_2[0x20];
        if (0x3ff < uVar15) {
          uVar15 = 0x400;
        }
      }
      else if (*(char *)((long)param_2 + 0x91) == '\x01') {
        uVar15 = param_2[0x20];
        if (0x1ff < uVar15) {
          uVar15 = 0x200;
        }
      }
      else {
        uVar15 = param_2[0x20];
      }
      *(uint *)(*(long *)(param_5 + 0x70) + 4) = uVar15;
      iVar12 = param_2[8];
    }
    if (iVar12 != 1) {
      if (0x10 < uVar8) goto LAB_0010550c;
      puVar16 = *(uint **)(param_2 + 0x1c);
      if (iVar12 == 3) {
        _byte_stream_swap_to_net_words(&local_b8);
      }
      else {
        if (uVar8 < 4) {
          lVar22 = 0;
          puVar9 = puVar16;
        }
        else {
          puVar9 = puVar16 + 1;
          uVar15 = (*puVar16 & 0xff00ff00) >> 8 | (*puVar16 & 0xff00ff) << 8;
          uVar11 = uVar15 >> 0x10 | uVar15 << 0x10;
          uVar15 = uVar8 >> 2;
          local_b8 = CONCAT44(local_b8._4_4_,uVar11);
          if (uVar15 == 1) {
            lVar22 = 4;
          }
          else {
            uVar14 = (puVar16[1] & 0xff00ff00) >> 8 | (puVar16[1] & 0xff00ff) << 8;
            local_b8 = CONCAT44(uVar14 >> 0x10 | uVar14 << 0x10,uVar11);
            if (uVar15 == 2) {
              puVar9 = puVar16 + 2;
              lVar22 = 8;
            }
            else {
              uVar11 = (puVar16[2] & 0xff00ff00) >> 8 | (puVar16[2] & 0xff00ff) << 8;
              uVar11 = uVar11 >> 0x10 | uVar11 << 0x10;
              local_b0 = CONCAT44(local_b0._4_4_,uVar11);
              if (uVar15 == 3) {
                puVar9 = puVar16 + 3;
                lVar22 = 0xc;
              }
              else {
                puVar9 = puVar16 + 4;
                uVar15 = (puVar16[3] & 0xff00ff00) >> 8 | (puVar16[3] & 0xff00ff) << 8;
                lVar22 = 0x10;
                local_b0 = CONCAT44(uVar15 >> 0x10 | uVar15 << 0x10,uVar11);
              }
            }
          }
        }
        uVar8 = uVar8 & 3;
        if (uVar8 == 1) {
          uVar8 = (uint)(byte)*puVar9 << 0x18;
        }
        else if (uVar8 == 2) {
          uVar8 = (uint)(byte)*puVar9 << 0x18 | (uint)*(byte *)((long)puVar9 + 1) << 0x10;
        }
        else {
          if (uVar8 != 3) goto LAB_001055e8;
          uVar8 = (uint)(byte)*puVar9 << 0x18 | (uint)*(byte *)((long)puVar9 + 1) << 0x10 |
                  (uint)*(byte *)((long)puVar9 + 2) << 8;
        }
        if (lVar22 - 0xdU < 4) goto LAB_001058d4;
        *(uint *)((long)local_a8 + lVar22 + -0x10) = uVar8;
      }
LAB_001055e8:
      lVar22 = *(long *)(param_5 + 0x40);
      *(uint *)(lVar22 + 4) = (uint)local_b8;
      *(undefined4 *)(lVar22 + 0x14) = local_b8._4_4_;
      *(uint *)(lVar22 + 0x24) = (uint)local_b0;
      *(undefined4 *)(lVar22 + 0x34) = local_b0._4_4_;
      if (param_2[8] == 4) {
        lVar22 = *(long *)(param_5 + 0x48);
        *(uint *)(lVar22 + 4) = (uint)local_b8;
        *(undefined4 *)(lVar22 + 0x14) = local_b8._4_4_;
        *(uint *)(lVar22 + 0x24) = (uint)local_b0;
        *(undefined4 *)(lVar22 + 0x34) = local_b0._4_4_;
        *(int *)(*(long *)(param_5 + 0x40) + 0x34) = *(int *)(*(long *)(param_5 + 0x40) + 0x34) + 1;
      }
    }
    bVar7 = false;
    if (((uVar1 == 0) && (*param_2 != 1)) && (uVar23 != 0)) {
      lVar22 = *(long *)(param_5 + 0x30);
      *(uint *)(lVar22 + 4) = local_a8[0];
      if (uVar23 != 1) {
        *(uint *)(lVar22 + 0x14) = local_a8[1];
        if (uVar23 != 2) {
          *(uint *)(lVar22 + 0x24) = local_a8[2];
          if (uVar23 != 3) {
            *(uint *)(lVar22 + 0x34) = local_a8[3];
            if (uVar23 != 4) {
              *(uint *)(lVar22 + 0x44) = local_a8[4];
              if (uVar23 != 5) {
                *(uint *)(lVar22 + 0x54) = local_a8[5];
                if (uVar23 != 6) {
                  *(uint *)(lVar22 + 100) = local_a8[6];
                  if (uVar23 != 7) {
                    *(uint *)(lVar22 + 0x74) = local_a8[7];
                    if (uVar23 != 8) {
                      *(uint *)(lVar22 + 0x84) = local_a8[8];
                      if (uVar23 != 9) {
                        *(uint *)(lVar22 + 0x94) = local_a8[9];
                        if (uVar23 != 10) {
                          *(uint *)(lVar22 + 0xa4) = local_a8[10];
                          if (uVar23 != 0xb) {
                            *(uint *)(lVar22 + 0xb4) = local_a8[0xb];
                            if (uVar23 != 0xc) {
                              *(uint *)(lVar22 + 0xc4) = local_a8[0xc];
                              if (uVar23 != 0xd) {
                                *(uint *)(lVar22 + 0xd4) = local_a8[0xd];
                                if (uVar23 != 0xe) {
                                  *(uint *)(lVar22 + 0xe4) = local_a8[0xe];
                                  if (uVar23 != 0xf) {
                                    *(uint *)(lVar22 + 0xf4) = local_a8[0xf];
                                    if (uVar23 != 0x10) {
LAB_001058d8:
                    /* WARNING: Does not return */
                                      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1058dc);
                                      (*pcVar5)();
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
                }
              }
            }
          }
        }
      }
      bVar7 = false;
    }
  }
  if ((uint)param_2[6] < 2) {
    uVar8 = *(uint *)(*(long *)(param_5 + 0x18) + 4);
    if (param_2[7] == 0) {
      uVar8 = uVar8 | 0x400;
    }
    else {
      uVar8 = uVar8 & 0xfffffbff;
    }
  }
  else {
    uVar8 = uVar21 | 0x8000;
    if (uVar2 != 2) {
      uVar8 = uVar21;
    }
    uVar8 = uVar8 | (uint)(param_2[7] == 0) << 10;
  }
  *(uint *)(*(long *)(param_5 + 0x18) + 4) = uVar8 & 0xffff8000 | uVar8 & 0x3fff | uVar1 << 0xe;
  if ((char)param_2[0x29] == '\0') {
    if ((param_2[8] == 4) && (param_2[7] == 1)) {
      iVar12 = param_2[0xd] + param_2[0x20];
    }
    else {
      iVar12 = param_2[0x20];
    }
  }
  else {
    iVar12 = 0;
  }
  *(int *)(*(long *)(param_5 + 0x20) + 4) = iVar12;
  *(uint *)(*(long *)(param_5 + 0x28) + 4) = param_4 & 0xffff;
  *(int *)(*(long *)(param_5 + 0xc0) + 4) = param_3;
  if (!bVar7) {
    *(int *)(*(long *)(param_5 + 0x78) + 4) = param_2[0x27];
    *(uint *)(*(long *)(param_5 + 0x80) + 4) = (uint)(param_2[0x28] != 0) | param_2[0x28] << 4;
    iVar12 = param_2[0x1f];
    *(undefined8 *)(param_1 + 0x10c) = 0xffffffffffffffff;
    *(uint *)(param_1 + 0x104) = -(uint)(iVar12 != 0x40);
    *(uint *)(param_1 + 0x108) = -(uint)(iVar12 != 0x40);
    *(undefined4 *)(*(long *)(param_5 + 0x68) + 4) = 0xffffffff;
    *(undefined4 *)(*(long *)(param_5 + 0x60) + 4) = *(undefined4 *)(param_1 + 0x10c);
    *(undefined4 *)(*(long *)(param_5 + 0x58) + 4) = *(undefined4 *)(param_1 + 0x108);
    *(undefined4 *)(*(long *)(param_5 + 0x50) + 4) = *(undefined4 *)(param_1 + 0x104);
  }
  lVar22 = *(long *)(param_5 + 200);
  uVar6 = 0;
  *(undefined4 *)(lVar22 + 4) = 0;
  uVar13 = 3;
  if (7 < param_2[0x25] - 1U) {
    uVar13 = 7;
  }
  *(undefined4 *)(lVar22 + 4) = uVar13;
LAB_0010589c:
  lVar22 = sp_el0;
  if (*(long *)(lVar22 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// _ce_setup_cipher_direct @ 001058e0 size=3888
// signature: undefined _ce_setup_cipher_direct(void)
// callers: [qce_aead_req, qce_ablk_cipher_req]
//------------------------------------------------------------

void _ce_setup_cipher_direct(long param_1,int *param_2,int param_3,undefined2 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  ulong uVar12;
  uint *puVar13;
  undefined4 uVar14;
  uint *puVar15;
  ulong uVar16;
  uint uVar17;
  byte *pbVar18;
  ulong uVar19;
  uint uVar20;
  long lVar21;
  long *plVar22;
  ulong local_f0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar21 = sp_el0;
  local_68 = *(long *)(lVar21 + 0x638);
  plVar22 = (long *)(param_1 + 0x48);
  uVar9 = param_2[0x1e];
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  writel_relaxed(0,*plVar22 + 0x1a100);
  if (8 < (uint)param_2[0x25]) goto LAB_00106808;
  uVar2 = (*(uint *)(param_1 + 0x1a8) >> 3) * 0x20000 - 0x1fff2 |
          *(int *)(param_1 + (ulong)(uint)param_2[0x25] * 4 + 0x134) << 5;
  *(uint *)(param_1 + 0x8c) = uVar2;
  *(uint *)(param_1 + 0x90) = uVar2 | 0x200;
  writel_relaxed(uVar2,*(long *)(param_1 + 0x48) + 0x1a400);
  writel_relaxed(*(undefined4 *)(param_1 + 0x90),*(long *)(param_1 + 0x48) + 0x1a400);
  DataSynchronizationBarrier(3,3,0);
  iVar7 = param_2[8];
  uVar11 = param_2[0x24];
  uVar20 = param_2[0x1a];
  uVar2 = uVar11 & 3;
  uVar1 = uVar20 >> (iVar7 == 3);
  if (uVar2 != 2 && (uVar11 & 1) == 0) {
    pbVar18 = *(byte **)(param_2 + 0x18);
    puVar10 = (uint *)&local_a8;
    local_f0 = (ulong)(uVar1 >> 2);
    if (uVar1 < 4) {
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
      uVar19 = local_f0;
      do {
        uVar16 = uVar12;
        if (0x3f < uVar16) goto LAB_00106804;
        uVar8 = (int)uVar19 - 1;
        uVar19 = (ulong)uVar8;
        uVar17 = (*(uint *)(pbVar18 + uVar16) & 0xff00ff00) >> 8 |
                 (*(uint *)(pbVar18 + uVar16) & 0xff00ff) << 8;
        *(uint *)((long)puVar10 + uVar16) = uVar17 >> 0x10 | uVar17 << 0x10;
        uVar12 = uVar16 + 4;
      } while (uVar8 != 0);
      pbVar18 = pbVar18 + uVar12;
      puVar10 = (uint *)((long)&local_a8 + uVar16 + 4);
    }
    uVar17 = uVar1 & 3;
    if (uVar17 == 1) {
      uVar17 = (uint)*pbVar18 << 0x18;
    }
    else if (uVar17 == 2) {
      uVar17 = (uint)*pbVar18 << 0x18 | (uint)pbVar18[1] << 0x10;
    }
    else {
      if (uVar17 != 3) goto LAB_00105a9c;
      uVar17 = (uint)*pbVar18 << 0x18 | (uint)pbVar18[1] << 0x10 | (uint)pbVar18[2] << 8;
    }
    if (0x3c < uVar12) goto LAB_00106804;
    *puVar10 = uVar17;
  }
  else {
    local_f0 = 0;
  }
LAB_00105a9c:
  uVar17 = uVar11 & 1;
  if (*param_2 == 2) {
    if (iVar7 == 4) {
      lVar21 = 0;
      do {
        writel_relaxed(0,*plVar22 + lVar21 + 0x1a310);
        writel_relaxed(0,*plVar22 + lVar21 + 0x1d040);
        lVar21 = lVar21 + 4;
      } while (lVar21 != 0x40);
      writel_relaxed(0,*plVar22 + 0x1a390);
      writel_relaxed(0,*plVar22 + 0x1a394);
      writel_relaxed(0,*plVar22 + 0x1a398);
      writel_relaxed(0,*plVar22 + 0x1a39c);
      uVar8 = (param_2[0xe] & 0xff00ff00U) >> 8 | (param_2[0xe] & 0xff00ffU) << 8;
      uVar3 = (param_2[0xf] & 0xff00ff00U) >> 8 | (param_2[0xf] & 0xff00ffU) << 8;
      uVar4 = (param_2[0x10] & 0xff00ff00U) >> 8 | (param_2[0x10] & 0xff00ffU) << 8;
      uVar5 = (param_2[0x11] & 0xff00ff00U) >> 8 | (param_2[0x11] & 0xff00ffU) << 8;
      writel_relaxed(uVar8 >> 0x10 | uVar8 << 0x10,*plVar22 + 0x1a350);
      writel_relaxed(uVar3 >> 0x10 | uVar3 << 0x10,*plVar22 + 0x1a354);
      writel_relaxed(uVar4 >> 0x10 | uVar4 << 0x10,*plVar22 + 0x1a358);
      writel_relaxed(uVar5 >> 0x10 | uVar5 << 0x10,*plVar22 + 0x1a35c);
      if (param_2[0xc] == 0x10) {
        puVar10 = (uint *)(param_1 + 0xec);
LAB_00105c0c:
        uVar8 = *puVar10;
      }
      else {
        uVar8 = 0;
        if (param_2[0xc] == 0x20) {
          puVar10 = (uint *)(param_1 + 0xf0);
          goto LAB_00105c0c;
        }
      }
      if (param_2[7] != 0) {
        uVar8 = uVar8 | 0x4000;
      }
      uVar8 = param_2[0xd] * 0x200 - 0x200U | uVar8;
      if (uVar17 == 0) {
        uVar8 = uVar8 & 0xfffbffff;
        if (3 < uVar20) {
          uVar20 = uVar20 >> 2;
          if (uVar20 < 2) {
            uVar20 = 1;
          }
          lVar21 = 0;
          do {
            if (lVar21 == 0x40) goto LAB_00106808;
            writel_relaxed(*(undefined4 *)((long)&local_a8 + lVar21),*plVar22 + lVar21 + 0x1d040);
            lVar21 = lVar21 + 4;
          } while ((ulong)uVar20 * 4 != lVar21);
        }
      }
      else {
        uVar8 = uVar8 | 0x40000;
      }
      writel_relaxed(uVar8,*plVar22 + 0x1a300);
      iVar7 = param_3;
      if (param_2[7] != 0) {
        iVar7 = param_3 - param_2[0xd];
      }
      writel_relaxed(iVar7,*plVar22 + 0x1a304);
      lVar21 = 0x1a308;
      goto LAB_00105ce4;
    }
  }
  else {
    lVar21 = 0x1a300;
LAB_00105ce4:
    writel_relaxed(0,*plVar22 + lVar21);
  }
  DataSynchronizationBarrier(3,3,0);
  iVar7 = param_2[8];
  switch(iVar7) {
  case 0:
    if (uVar1 == 0x10) {
      puVar10 = (uint *)(param_1 + 0x94);
    }
    else {
      puVar10 = (uint *)(param_1 + 0x98);
    }
    break;
  case 1:
    if (uVar1 == 0x10) {
      puVar10 = (uint *)(param_1 + 0x9c);
    }
    else {
      puVar10 = (uint *)(param_1 + 0xa0);
    }
    break;
  default:
    if (uVar1 == 0x10) {
      puVar10 = (uint *)(param_1 + 0xac);
    }
    else {
      puVar10 = (uint *)(param_1 + 0xb0);
    }
    break;
  case 3:
    if (uVar1 == 0x10) {
      puVar10 = (uint *)(param_1 + 0xa4);
    }
    else {
      puVar10 = (uint *)(param_1 + 0xa8);
    }
    break;
  case 4:
    if (uVar1 == 0x10) {
      puVar10 = (uint *)(param_1 + 0xb4);
    }
    else {
      puVar10 = (uint *)(param_1 + 0xb8);
    }
  }
  if (param_2[6] == 1) {
    if (iVar7 == 1) {
      uVar20 = *(uint *)(param_1 + 200);
      uVar12 = local_a8;
    }
    else {
      puVar10 = *(uint **)(param_2 + 0x1c);
      if (uVar9 < 4) {
        uVar12 = 0;
        puVar15 = puVar10;
      }
      else {
        puVar15 = puVar10 + 1;
        uVar20 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
        uVar11 = uVar20 >> 0x10 | uVar20 << 0x10;
        uVar20 = uVar9 >> 2;
        local_b8 = CONCAT44(local_b8._4_4_,uVar11);
        if (uVar20 == 1) {
          uVar12 = 4;
        }
        else {
          uVar1 = (puVar10[1] & 0xff00ff00) >> 8 | (puVar10[1] & 0xff00ff) << 8;
          local_b8 = CONCAT44(uVar1 >> 0x10 | uVar1 << 0x10,uVar11);
          if (uVar20 == 2) {
            puVar15 = puVar10 + 2;
            uVar12 = 8;
          }
          else {
            uVar11 = (puVar10[2] & 0xff00ff00) >> 8 | (puVar10[2] & 0xff00ff) << 8;
            uVar11 = uVar11 >> 0x10 | uVar11 << 0x10;
            local_b0 = CONCAT44(local_b0._4_4_,uVar11);
            if (uVar20 == 3) {
              puVar15 = puVar10 + 3;
              uVar12 = 0xc;
            }
            else {
              uVar1 = (puVar10[3] & 0xff00ff00) >> 8 | (puVar10[3] & 0xff00ff) << 8;
              local_b0 = CONCAT44(uVar1 >> 0x10 | uVar1 << 0x10,uVar11);
              if (uVar20 != 4) goto LAB_00106804;
              puVar15 = puVar10 + 4;
              uVar12 = 0x10;
            }
          }
        }
      }
      uVar9 = uVar9 & 3;
      if (uVar9 == 1) {
        uVar9 = (uint)(byte)*puVar15 << 0x18;
LAB_001060c0:
        if (0xc < uVar12) {
LAB_00106804:
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x106808);
          (*pcVar6)();
        }
        *(uint *)((long)&local_b8 + uVar12) = uVar9;
      }
      else {
        if (uVar9 == 2) {
          uVar9 = (uint)(byte)*puVar15 << 0x18 | (uint)*(byte *)((long)puVar15 + 1) << 0x10;
          goto LAB_001060c0;
        }
        if (uVar9 == 3) {
          uVar9 = (uint)(byte)*puVar15 << 0x18 | (uint)*(byte *)((long)puVar15 + 1) << 0x10 |
                  (uint)*(byte *)((long)puVar15 + 2) << 8;
          goto LAB_001060c0;
        }
      }
      writel_relaxed(local_b8 & 0xffffffff,*(long *)(param_1 + 0x48) + 0x1a20c);
      writel_relaxed(local_b8._4_4_,*(long *)(param_1 + 0x48) + 0x1a210);
      uVar20 = *(uint *)(param_1 + 0xc4);
      uVar12 = local_a8;
    }
    local_a8 = uVar12;
    if (uVar17 != 0) goto LAB_0010664c;
    local_a8._0_4_ = (uint)uVar12;
    uVar9 = (uint)local_a8;
    writel_relaxed(uVar12 & 0xffffffff,*plVar22 + 0x1d000);
    writel_relaxed(uVar12 & 0xffffffff,*plVar22 + 0x1d004);
    writel_relaxed(uVar12 & 0xffffffff,*plVar22 + 0x1d008);
    writel_relaxed(uVar12 & 0xffffffff,*plVar22 + 0x1d00c);
    writel_relaxed(uVar12 & 0xffffffff,*plVar22 + 0x1d010);
    lVar21 = 0x1d014;
  }
  else {
    if (param_2[6] != 0) {
      uVar20 = *puVar10;
      if (iVar7 == 3) {
        local_c8 = 0;
        local_c0 = 0;
        local_d8 = 0;
        local_d0 = 0;
        if (uVar2 != 2 && (uVar11 & 1) == 0) {
          uVar1 = param_2[0x1a];
          uVar11 = uVar1 >> 3;
          puVar10 = (uint *)(*(long *)(param_2 + 0x18) + (ulong)(uVar1 >> 1));
          if (uVar1 < 8) {
            uVar12 = 0;
            puVar15 = (uint *)((long)&local_c0 + 4);
            puVar13 = puVar10;
          }
          else {
            uVar8 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
            uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
            local_c0 = (ulong)uVar8 << 0x20;
            if (uVar11 == 1) {
              puVar15 = (uint *)&local_c0;
              uVar12 = 4;
              puVar13 = puVar10 + 1;
            }
            else {
              uVar3 = puVar10[1];
              uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
              local_c0 = CONCAT44(uVar8,uVar3 >> 0x10 | uVar3 << 0x10);
              if (uVar11 == 2) {
                puVar15 = (uint *)((long)&local_c8 + 4);
                uVar12 = 8;
                puVar13 = puVar10 + 2;
              }
              else {
                uVar8 = puVar10[2];
                uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
                uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
                local_c8 = (ulong)uVar8 << 0x20;
                if (uVar11 == 3) {
                  puVar15 = (uint *)&local_c8;
                  uVar12 = 0xc;
                  puVar13 = puVar10 + 3;
                }
                else {
                  uVar3 = puVar10[3];
                  uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
                  local_c8 = CONCAT44(uVar8,uVar3 >> 0x10 | uVar3 << 0x10);
                  if (uVar11 == 4) {
                    puVar15 = (uint *)((long)&local_d0 + 4);
                    uVar12 = 0x10;
                    puVar13 = puVar10 + 4;
                  }
                  else {
                    uVar8 = puVar10[4];
                    uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
                    uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
                    local_d0 = (ulong)uVar8 << 0x20;
                    if (uVar11 == 5) {
                      puVar15 = (uint *)&local_d0;
                      uVar12 = 0x14;
                      puVar13 = puVar10 + 5;
                    }
                    else {
                      uVar3 = puVar10[5];
                      uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
                      local_d0 = CONCAT44(uVar8,uVar3 >> 0x10 | uVar3 << 0x10);
                      if (uVar11 == 6) {
                        puVar15 = (uint *)((long)&local_d8 + 4);
                        uVar12 = 0x18;
                        puVar13 = puVar10 + 6;
                      }
                      else {
                        uVar8 = puVar10[6];
                        uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
                        uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
                        local_d8 = (ulong)uVar8 << 0x20;
                        if (uVar11 == 7) {
                          puVar15 = (uint *)&local_d8;
                          uVar12 = 0x1c;
                          puVar13 = puVar10 + 7;
                        }
                        else {
                          puVar13 = puVar10 + 8;
                          uVar3 = puVar10[7];
                          uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
                          uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
                          puVar15 = (uint *)(ulong)uVar3;
                          local_d8 = CONCAT44(uVar8,uVar3);
                          if (uVar11 != 8) goto LAB_00106804;
                          uVar12 = 0x20;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          uVar8 = uVar1 >> 1 & 3;
          if (uVar8 == 1) {
            uVar8 = (uint)(byte)*puVar13 << 0x18;
LAB_00106278:
            if (0x1c < uVar12) goto LAB_00106804;
            *puVar15 = uVar8;
          }
          else {
            if (uVar8 == 2) {
              uVar8 = (uint)(byte)*puVar13 << 0x18 | (uint)*(byte *)((long)puVar13 + 1) << 0x10;
              goto LAB_00106278;
            }
            if (uVar8 == 3) {
              uVar8 = (uint)(byte)*puVar13 << 0x18 | (uint)*(byte *)((long)puVar13 + 1) << 0x10 |
                      (uint)*(byte *)((long)puVar13 + 2) << 8;
              goto LAB_00106278;
            }
          }
          if (7 < uVar1) {
            if (uVar11 < 2) {
              uVar11 = 1;
            }
            writel_relaxed(local_c0._4_4_,*plVar22 + 0x1d020);
            if ((0xf < uVar1) &&
               (writel_relaxed(local_c0 & 0xffffffff,*plVar22 + 0x1d024), uVar11 != 2)) {
              writel_relaxed(local_c8._4_4_,*plVar22 + 0x1d028);
              if ((uVar11 != 3) &&
                 (writel_relaxed(local_c8 & 0xffffffff,*plVar22 + 0x1d02c), uVar11 != 4)) {
                writel_relaxed(local_d0._4_4_,*plVar22 + 0x1d030);
                if ((uVar11 != 5) &&
                   (writel_relaxed(local_d0 & 0xffffffff,*plVar22 + 0x1d034), uVar11 != 6)) {
                  writel_relaxed(local_d8._4_4_,*plVar22 + 0x1d038);
                  if ((uVar11 != 7) &&
                     (writel_relaxed(local_d8 & 0xffffffff,*plVar22 + 0x1d03c), uVar11 != 8)) {
LAB_00106808:
                    /* WARNING: Does not return */
                    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10680c);
                    (*pcVar6)();
                  }
                }
              }
            }
          }
        }
        if (*(char *)((long)param_2 + 0x91) == '\x02') {
          uVar11 = param_2[0x20];
          if (0x3ff < uVar11) {
            uVar11 = 0x400;
          }
        }
        else if (*(char *)((long)param_2 + 0x91) == '\x01') {
          uVar11 = param_2[0x20];
          if (0x1ff < uVar11) {
            uVar11 = 0x200;
          }
        }
        else {
          uVar11 = param_2[0x20];
        }
        writel_relaxed(uVar11,*plVar22 + 0x1a230);
        iVar7 = param_2[8];
      }
      if (iVar7 != 1) {
        if (iVar7 == 3) {
          _byte_stream_swap_to_net_words(&local_b8,*(undefined8 *)(param_2 + 0x1c),uVar9);
        }
        else {
          puVar10 = *(uint **)(param_2 + 0x1c);
          if (uVar9 < 4) {
            uVar12 = 0;
            puVar15 = puVar10;
          }
          else {
            puVar15 = puVar10 + 1;
            uVar11 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
            uVar1 = uVar11 >> 0x10 | uVar11 << 0x10;
            uVar11 = uVar9 >> 2;
            local_b8._4_4_ = (undefined4)(local_b8 >> 0x20);
            local_b8 = CONCAT44(local_b8._4_4_,uVar1);
            if (uVar11 == 1) {
              uVar12 = 4;
            }
            else {
              uVar8 = (puVar10[1] & 0xff00ff00) >> 8 | (puVar10[1] & 0xff00ff) << 8;
              local_b8 = CONCAT44(uVar8 >> 0x10 | uVar8 << 0x10,uVar1);
              if (uVar11 == 2) {
                puVar15 = puVar10 + 2;
                uVar12 = 8;
              }
              else {
                uVar1 = (puVar10[2] & 0xff00ff00) >> 8 | (puVar10[2] & 0xff00ff) << 8;
                uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
                local_b0._4_4_ = (int)(local_b0 >> 0x20);
                local_b0 = CONCAT44(local_b0._4_4_,uVar1);
                if (uVar11 == 3) {
                  puVar15 = puVar10 + 3;
                  uVar12 = 0xc;
                }
                else {
                  uVar8 = (puVar10[3] & 0xff00ff00) >> 8 | (puVar10[3] & 0xff00ff) << 8;
                  local_b0 = CONCAT44(uVar8 >> 0x10 | uVar8 << 0x10,uVar1);
                  if (uVar11 != 4) goto LAB_00106804;
                  puVar15 = puVar10 + 4;
                  uVar12 = 0x10;
                }
              }
            }
          }
          uVar9 = uVar9 & 3;
          if (uVar9 == 1) {
            uVar9 = (uint)(byte)*puVar15 << 0x18;
          }
          else if (uVar9 == 2) {
            uVar9 = (uint)(byte)*puVar15 << 0x18 | (uint)*(byte *)((long)puVar15 + 1) << 0x10;
          }
          else {
            if (uVar9 != 3) goto LAB_001064f4;
            uVar9 = (uint)(byte)*puVar15 << 0x18 | (uint)*(byte *)((long)puVar15 + 1) << 0x10 |
                    (uint)*(byte *)((long)puVar15 + 2) << 8;
          }
          if (0xc < uVar12) goto LAB_00106804;
          *(uint *)((long)&local_b8 + uVar12) = uVar9;
        }
LAB_001064f4:
        uVar12 = local_b8;
        writel_relaxed(local_b8 & 0xffffffff,*plVar22 + 0x1a20c);
        uVar14 = local_b8._4_4_;
        writel_relaxed(local_b8._4_4_,*plVar22 + 0x1a210);
        uVar19 = local_b0;
        writel_relaxed(local_b0 & 0xffffffff,*plVar22 + 0x1a214);
        iVar7 = local_b0._4_4_;
        writel_relaxed(local_b0._4_4_,*plVar22 + 0x1a218);
        if (param_2[8] == 4) {
          writel_relaxed(uVar12 & 0xffffffff,*plVar22 + 0x1a220);
          writel_relaxed(uVar14,*plVar22 + 0x1a224);
          writel_relaxed(uVar19 & 0xffffffff,*plVar22 + 0x1a228);
          writel_relaxed(iVar7,*plVar22 + 0x1a22c);
          writel_relaxed(iVar7 + 1,*plVar22 + 0x1a218);
        }
      }
      if ((((uVar2 != 2) && (*param_2 != 1)) && (uVar17 == 0)) && ((int)local_f0 != 0)) {
        lVar21 = 0;
        do {
          if (lVar21 == 0x40) goto LAB_00106808;
          writel_relaxed(*(undefined4 *)((long)&local_a8 + lVar21),*plVar22 + lVar21 + 0x1d000);
          lVar21 = lVar21 + 4;
        } while (local_f0 * 4 != lVar21);
      }
      goto LAB_0010664c;
    }
    if (iVar7 == 1) {
      uVar20 = *(uint *)(param_1 + 0xc0);
    }
    else {
      uVar20 = *(uint *)(param_1 + 0xbc);
      puVar10 = *(uint **)(param_2 + 0x1c);
      if (uVar9 < 4) {
        uVar12 = 0;
        puVar15 = puVar10;
      }
      else {
        puVar15 = puVar10 + 1;
        uVar11 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8;
        uVar1 = uVar11 >> 0x10 | uVar11 << 0x10;
        uVar11 = uVar9 >> 2;
        local_b8 = CONCAT44(local_b8._4_4_,uVar1);
        if (uVar11 == 1) {
          uVar12 = 4;
        }
        else {
          uVar8 = (puVar10[1] & 0xff00ff00) >> 8 | (puVar10[1] & 0xff00ff) << 8;
          local_b8 = CONCAT44(uVar8 >> 0x10 | uVar8 << 0x10,uVar1);
          if (uVar11 == 2) {
            puVar15 = puVar10 + 2;
            uVar12 = 8;
          }
          else {
            uVar1 = (puVar10[2] & 0xff00ff00) >> 8 | (puVar10[2] & 0xff00ff) << 8;
            uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
            local_b0 = CONCAT44(local_b0._4_4_,uVar1);
            if (uVar11 == 3) {
              puVar15 = puVar10 + 3;
              uVar12 = 0xc;
            }
            else {
              uVar8 = (puVar10[3] & 0xff00ff00) >> 8 | (puVar10[3] & 0xff00ff) << 8;
              local_b0 = CONCAT44(uVar8 >> 0x10 | uVar8 << 0x10,uVar1);
              if (uVar11 != 4) goto LAB_00106804;
              puVar15 = puVar10 + 4;
              uVar12 = 0x10;
            }
          }
        }
      }
      uVar9 = uVar9 & 3;
      if (uVar9 == 1) {
        uVar9 = (uint)(byte)*puVar15 << 0x18;
LAB_00105ff0:
        if (0xc < uVar12) goto LAB_00106804;
        *(uint *)((long)&local_b8 + uVar12) = uVar9;
      }
      else {
        if (uVar9 == 2) {
          uVar9 = (uint)(byte)*puVar15 << 0x18 | (uint)*(byte *)((long)puVar15 + 1) << 0x10;
          goto LAB_00105ff0;
        }
        if (uVar9 == 3) {
          uVar9 = (uint)(byte)*puVar15 << 0x18 | (uint)*(byte *)((long)puVar15 + 1) << 0x10 |
                  (uint)*(byte *)((long)puVar15 + 2) << 8;
          goto LAB_00105ff0;
        }
      }
      writel_relaxed(local_b8 & 0xffffffff,*plVar22 + 0x1a20c);
      writel_relaxed(local_b8._4_4_,*plVar22 + 0x1a210);
    }
    if (uVar17 != 0) goto LAB_0010664c;
    lVar21 = 0x1d004;
    writel_relaxed(local_a8 & 0xffffffff,*plVar22 + 0x1d000);
    uVar9 = local_a8._4_4_;
  }
  writel_relaxed(uVar9,*plVar22 + lVar21);
LAB_0010664c:
  uVar9 = uVar20 | 0x8000;
  if (uVar2 != 2) {
    uVar9 = uVar20;
  }
  writel_relaxed(uVar9 & 0xffffbfff | (uint)(param_2[7] == 0) << 10 | uVar17 << 0xe,
                 *plVar22 + 0x1a200);
  if ((param_2[8] == 4) && (param_2[7] == 1)) {
    iVar7 = param_2[0xd] + param_2[0x20];
  }
  else {
    iVar7 = param_2[0x20];
  }
  writel_relaxed(iVar7,*plVar22 + 0x1a204);
  if ((char)param_2[0x26] != '\0') {
    writel_relaxed(param_2[0x27],*plVar22 + 0x1a500);
  }
  writel_relaxed((uint)(param_2[0x28] != 0) | param_2[0x28] << 4,*(long *)(param_1 + 0x48) + 0x1a504
                );
  writel_relaxed(param_4,*(long *)(param_1 + 0x48) + 0x1a208);
  iVar7 = param_2[0x1f];
  *(undefined8 *)(param_1 + 0x10c) = 0xffffffffffffffff;
  *(uint *)(param_1 + 0x104) = -(uint)(iVar7 != 0x40);
  *(uint *)(param_1 + 0x108) = -(uint)(iVar7 != 0x40);
  writel_relaxed(0xffffffff,*(long *)(param_1 + 0x48) + 0x1a21c);
  writel_relaxed(*(undefined4 *)(param_1 + 0x10c),*(long *)(param_1 + 0x48) + 0x1a234);
  writel_relaxed(*(undefined4 *)(param_1 + 0x108),*(long *)(param_1 + 0x48) + 0x1a238);
  writel_relaxed(*(undefined4 *)(param_1 + 0x104),*(long *)(param_1 + 0x48) + 0x1a23c);
  writel_relaxed(param_3,*(long *)(param_1 + 0x48) + 0x1a110);
  lVar21 = 0x1b000;
  if (uVar17 == 0) {
    lVar21 = 0x1a120;
  }
  uVar14 = 5;
  if (uVar17 == 0) {
    uVar14 = 7;
  }
  writel_relaxed(uVar14,*(long *)(param_1 + 0x48) + lVar21);
  DataSynchronizationBarrier(3,3,0);
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qce_process_sha_req @ 00106814 size=4212
// signature: undefined qce_process_sha_req(void)
// callers: [qce_multireq_timeout]
//------------------------------------------------------------

int qce_process_sha_req(undefined8 *param_1,undefined8 *param_2)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  char *pcVar11;
  long *plVar12;
  undefined4 uVar13;
  int iVar14;
  ulong uVar15;
  ulong uVar16;
  uint *puVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint uVar20;
  byte *pbVar21;
  uint *puVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  uint uVar26;
  uint uVar27;
  ulong uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined8 *puVar31;
  uint uVar32;
  long lVar33;
  uint uVar34;
  int *piVar35;
  uint local_dc;
  undefined8 local_d8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar33 = sp_el0;
  local_68 = *(long *)(lVar33 + 0x638);
  piVar1 = (int *)((long)param_1 + 0x10a64);
  if (param_2 == (undefined8 *)0x0) {
    uVar7 = 8;
    puVar31 = param_1 + 0x2158;
    *(undefined4 *)((long)param_1 + 0x10b14) = 8;
  }
  else {
    uVar7 = qce_alloc_req_info(param_1);
    if ((int)uVar7 < 0) {
      iVar9 = -0x10;
      goto LAB_00107618;
    }
    *(uint *)((long)param_2 + 0x54) = uVar7;
    puVar31 = param_2;
    if (9 < uVar7) goto LAB_00107874;
  }
  iVar9 = *(int *)(puVar31 + 8);
  lVar33 = puVar31[9];
  uVar28 = (ulong)uVar7;
  piVar2 = (int *)(param_1 + (ulong)uVar7 * 0x37f + 0x1d5);
  if (0 < iVar9) {
    lVar10 = puVar31[3];
    uVar32 = 0;
    do {
      uVar20 = uVar32;
      uVar32 = uVar20 + 1;
      iVar9 = iVar9 - *(int *)(lVar10 + 0xc);
      lVar10 = sg_next();
    } while (0 < iVar9);
    piVar35 = (int *)(param_1 + uVar28 * 0x37f + 0x54b);
    *(uint *)(param_1 + uVar28 * 0x37f + 0x54b) = uVar32;
    if (uVar20 < 0x7fffffff) {
      uVar29 = *param_1;
      uVar30 = puVar31[3];
      do {
        dma_map_sg_attrs(uVar29,uVar30,1,1,0);
        uVar30 = sg_next(uVar30);
        uVar32 = uVar32 - 1;
      } while (uVar32 != 0);
    }
    if (*(char *)(param_1 + 8) != '\0') goto LAB_00106928;
LAB_0010697c:
    uVar32 = *(uint *)(puVar31 + 7);
    local_78 = 0;
    local_70 = 0;
    local_88 = 0;
    local_80 = 0;
    local_98 = 0;
    local_90 = 0;
    local_a8 = 0;
    local_a0 = 0;
    writel_relaxed(0,param_1[9] + 0x1a100);
    uVar20 = (*(uint *)(param_1 + 0x35) >> 3) * 0x20000 - 0x1fff2 |
             *(int *)((long)param_1 + 0x134) << 5;
    *(uint *)((long)param_1 + 0x8c) = uVar20;
    *(uint *)(param_1 + 0x12) = uVar20 | 0x200;
    writel_relaxed(uVar20,param_1[9] + 0x1a400);
    DataSynchronizationBarrier(3,3,0);
    iVar9 = *(int *)(puVar31 + 1);
    if (iVar9 == 4) {
      writel_relaxed(0,param_1[9] + 0x1a300);
      writel_relaxed(0,param_1[9] + 0x1a200);
      writel_relaxed(0,param_1[9] + 0x1a204);
      lVar10 = 0;
      do {
        writel_relaxed(0,param_1[9] + lVar10 + 0x1a310);
        writel_relaxed(0,param_1[9] + lVar10 + 0x1d040);
        lVar10 = lVar10 + 4;
      } while (lVar10 != 0x40);
      writel_relaxed(0,param_1[9] + 0x1a390);
      writel_relaxed(0,param_1[9] + 0x1a394);
      writel_relaxed(0,param_1[9] + 0x1a398);
      writel_relaxed(0,param_1[9] + 0x1a39c);
      lVar10 = 0xd4;
      if (*(int *)(puVar31 + 7) != 0x10) {
        lVar10 = 0xd8;
      }
      uVar20 = *(uint *)((long)param_1 + lVar10);
      iVar9 = *(int *)(puVar31 + 1);
    }
    else {
      uVar20 = 0;
    }
    if (iVar9 - 2U < 3) {
      uVar19 = *(uint *)(puVar31 + 7);
      puVar22 = (uint *)&local_a8;
      pbVar21 = (byte *)puVar31[6];
      if (uVar19 < 4) {
        uVar15 = 0;
      }
      else {
        uVar23 = uVar19 >> 2;
        uVar15 = 0;
        do {
          uVar16 = uVar15;
          if ((0x3f < uVar16) || (uVar16 == 0x40)) goto LAB_00107870;
          uVar23 = uVar23 - 1;
          uVar34 = (*(uint *)(pbVar21 + uVar16) & 0xff00ff00) >> 8 |
                   (*(uint *)(pbVar21 + uVar16) & 0xff00ff) << 8;
          *(uint *)((long)puVar22 + uVar16) = uVar34 >> 0x10 | uVar34 << 0x10;
          uVar15 = uVar16 + 4;
        } while (uVar23 != 0);
        pbVar21 = pbVar21 + uVar15;
        puVar22 = (uint *)((long)&local_a8 + uVar16 + 4);
      }
      uVar19 = uVar19 & 3;
      if (uVar19 == 1) {
        uVar19 = (uint)*pbVar21 << 0x18;
LAB_00106d18:
        if ((0x3c < uVar15) || (0x3c < uVar15)) goto LAB_00107870;
        *puVar22 = uVar19;
      }
      else {
        if (uVar19 == 2) {
          uVar19 = (uint)*pbVar21 << 0x18 | (uint)pbVar21[1] << 0x10;
          goto LAB_00106d18;
        }
        if (uVar19 == 3) {
          uVar19 = (uint)*pbVar21 << 0x18 | (uint)pbVar21[1] << 0x10 | (uint)pbVar21[2] << 8;
          goto LAB_00106d18;
        }
      }
      uVar19 = *(uint *)(puVar31 + 10);
      if ((uVar19 & 1) == 0) {
        if ((uVar19 >> 1 & 1) == 0) {
          if (uVar32 < 4) goto LAB_00106d34;
          uVar32 = uVar32 >> 2;
          if (uVar32 < 2) {
            uVar32 = 1;
          }
          lVar10 = 0;
          do {
            if (lVar10 == 0x40) goto LAB_00107874;
            writel_relaxed(*(undefined4 *)((long)&local_a8 + lVar10),param_1[9] + lVar10 + 0x1d040);
            lVar10 = lVar10 + 4;
          } while ((ulong)uVar32 * 4 != lVar10);
          bVar5 = false;
          iVar9 = *(int *)(puVar31 + 1);
        }
        else {
          bVar5 = true;
        }
      }
      else {
LAB_00106d34:
        bVar5 = false;
      }
      uVar19 = uVar19 & 1;
      if (iVar9 != 4) goto LAB_00106db8;
LAB_001070e4:
      writel_relaxed(uVar20,param_1[9] + 0x1a300);
      writel_relaxed(*(undefined4 *)(puVar31 + 8),param_1[9] + 0x1a304);
      writel_relaxed(0,param_1[9] + 0x1a308);
      writel_relaxed(0,param_1[9] + 0x1a200);
      writel_relaxed(*(undefined4 *)(puVar31 + 8),param_1[9] + 0x1a110);
      writel_relaxed(*(undefined4 *)(param_1 + 0x12),param_1[9] + 0x1a400);
      lVar10 = 0x1b000;
      if (uVar19 == 0) {
        lVar10 = 0x1a120;
      }
      uVar13 = 5;
      if (uVar19 == 0) {
        uVar13 = 7;
      }
      writel_relaxed(uVar13,param_1[9] + lVar10);
      DataSynchronizationBarrier(3,3,0);
      iVar9 = 0;
    }
    else {
      bVar5 = false;
      uVar19 = 0;
LAB_00106db8:
      if ((*(char *)((long)puVar31 + 0x3d) != '\0') || ((*(byte *)(puVar31 + 8) & 0x3f) == 0)) {
        switch(iVar9) {
        case 0:
          puVar22 = (uint *)((long)param_1 + 0xdc);
          bVar25 = true;
          break;
        case 1:
          bVar25 = false;
          puVar22 = (uint *)(param_1 + 0x1c);
          break;
        case 2:
          puVar22 = (uint *)((long)param_1 + 0xe4);
          bVar25 = true;
          break;
        case 3:
          bVar25 = false;
          puVar22 = (uint *)(param_1 + 0x1d);
          break;
        default:
          iVar9 = -0x16;
          goto LAB_00107190;
        }
        if (*(char *)((long)puVar31 + 0x3c) == '\0') {
          puVar17 = (uint *)puVar31[2];
          uVar32 = (*puVar17 & 0xff00ff00) >> 8 | (*puVar17 & 0xff00ff) << 8;
          uVar26 = uVar32 >> 0x10 | uVar32 << 0x10;
          uVar32 = (puVar17[1] & 0xff00ff00) >> 8 | (puVar17[1] & 0xff00ff) << 8;
          uVar32 = uVar32 >> 0x10 | uVar32 << 0x10;
          uVar20 = (puVar17[2] & 0xff00ff00) >> 8 | (puVar17[2] & 0xff00ff) << 8;
          uVar23 = uVar20 >> 0x10 | uVar20 << 0x10;
          uVar20 = (puVar17[3] & 0xff00ff00) >> 8 | (puVar17[3] & 0xff00ff) << 8;
          uVar34 = uVar20 >> 0x10 | uVar20 << 0x10;
          uVar20 = (puVar17[4] & 0xff00ff00) >> 8 | (puVar17[4] & 0xff00ff) << 8;
          uVar20 = uVar20 >> 0x10 | uVar20 << 0x10;
          if (bVar25) {
            local_d8 = 0;
            local_dc = 0;
          }
          else {
            uVar24 = (puVar17[5] & 0xff00ff00) >> 8 | (puVar17[5] & 0xff00ff) << 8;
            uVar27 = (puVar17[6] & 0xff00ff00) >> 8 | (puVar17[6] & 0xff00ff) << 8;
            local_dc = uVar27 >> 0x10 | uVar27 << 0x10;
            uVar27 = (puVar17[7] & 0xff00ff00) >> 8 | (puVar17[7] & 0xff00ff) << 8;
            local_d8 = CONCAT44(uVar27 >> 0x10 | uVar27 << 0x10,uVar24 >> 0x10 | uVar24 << 0x10);
          }
        }
        else if (bVar25) {
          local_d8 = 0;
          local_dc = 0;
          uVar32 = 0xefcdab89;
          uVar20 = 0xc3d2e1f0;
          uVar23 = 0x98badcfe;
          uVar26 = 0x67452301;
          uVar34 = 0x10325476;
        }
        else {
          uVar32 = 0xbb67ae85;
          uVar34 = 0xa54ff53a;
          uVar26 = 0x6a09e667;
          uVar20 = 0x510e527f;
          uVar23 = 0x3c6ef372;
          local_d8 = 0x5be0cd199b05688c;
          local_dc = 0x1f83d9ab;
        }
        uVar24 = *puVar22;
        writel_relaxed(uVar26,param_1[9] + 0x1a310);
        writel_relaxed(uVar32,param_1[9] + 0x1a314);
        writel_relaxed(uVar23,param_1[9] + 0x1a318);
        writel_relaxed(uVar34,param_1[9] + 0x1a31c);
        writel_relaxed(uVar20,param_1[9] + 0x1a320);
        if ((*(uint *)(puVar31 + 1) | 2) == 3) {
          writel_relaxed(local_d8 & 0xffffffff,param_1[9] + 0x1a324);
          writel_relaxed(local_dc,param_1[9] + 0x1a328);
          writel_relaxed(local_d8._4_4_,param_1[9] + 0x1a32c);
        }
        writel_relaxed(*(undefined4 *)(puVar31 + 4),param_1[9] + 0x1a390);
        writel_relaxed(*(undefined4 *)((long)puVar31 + 0x24),param_1[9] + 0x1a394);
        uVar20 = uVar24 & 0xfffcffff | (uint)*(byte *)((long)puVar31 + 0x3d) << 0x10 |
                 (uint)*(byte *)((long)puVar31 + 0x3c) << 0x11;
        uVar32 = uVar20 | 0x40000;
        if (uVar19 == 0) {
          uVar32 = uVar20;
        }
        uVar20 = uVar32 | 0x80000;
        if (!bVar5) {
          uVar20 = uVar32;
        }
        goto LAB_001070e4;
      }
      iVar9 = -5;
    }
LAB_00107190:
    plVar12 = (long *)0x0;
    goto LAB_001074e4;
  }
  piVar35 = (int *)(param_1 + uVar28 * 0x37f + 0x54b);
  *(undefined4 *)(param_1 + uVar28 * 0x37f + 0x54b) = 0;
  if (*(char *)(param_1 + 8) == '\0') goto LAB_0010697c;
LAB_00106928:
  if (8 < uVar7) goto LAB_00107874;
  switch(*(undefined4 *)(puVar31 + 1)) {
  case 0:
    lVar10 = 0x1778;
    break;
  case 1:
    lVar10 = 0x1850;
    break;
  case 2:
    lVar10 = 0x1928;
    break;
  case 3:
    lVar10 = 0x1a00;
    break;
  case 4:
    if (*(int *)(puVar31 + 7) == 0x10) {
      lVar10 = 0x1ad8;
    }
    else {
      lVar10 = 0x1bb0;
    }
    break;
  default:
    goto switchD_00106950_default;
  }
  plVar12 = (long *)((long)param_1 + lVar10 + uVar28 * 0x1bf8);
  if (plVar12 == (long *)0x0) {
switchD_00106950_default:
    _printk(&DAT_00111100,"qce_process_sha_req");
    iVar9 = -0x16;
    *(undefined4 *)(param_1 + uVar28 * 0x37f + 0x1d6) = 5;
    Hint_Prefetch(piVar2,2,0,1);
    do {
      iVar14 = *piVar2;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar5) {
        *piVar2 = 0;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
  }
  else {
    local_78 = 0;
    local_70 = 0;
    local_88 = 0;
    local_80 = 0;
    local_98 = 0;
    local_90 = 0;
    uVar32 = *(uint *)(puVar31 + 7);
    uVar20 = (*(uint *)(param_1 + 0x35) >> 3) * 0x20000 - 0x1fff2 |
             *(int *)((long)param_1 + 0x134) << 5;
    local_a8 = 0;
    local_a0 = 0;
    *(uint *)((long)param_1 + 0x8c) = uVar20;
    *(uint *)(param_1 + 0x12) = uVar20 | 0x200;
    *(uint *)(plVar12[1] + 4) = uVar20;
    *(undefined4 *)(plVar12[2] + 4) = *(undefined4 *)(param_1 + 0x12);
    iVar9 = *(int *)(puVar31 + 1);
    if (iVar9 - 2U < 3) {
      uVar20 = *(uint *)(puVar31 + 10);
      puVar22 = (uint *)plVar12[0x19];
      if ((uVar20 & 1) == 0) {
        *puVar22 = *(int *)(param_1 + 10) + 0x1a120U & 0xffffff |
                   (uint)*(byte *)((long)puVar22 + 3) << 0x18;
        if ((uVar20 & 3) == 2) {
          bVar5 = true;
        }
        else {
          uVar19 = *(uint *)(puVar31 + 7);
          puVar22 = (uint *)&local_a8;
          lVar10 = plVar12[0x14];
          pbVar21 = (byte *)puVar31[6];
          if (uVar19 < 4) {
            uVar15 = 0;
          }
          else {
            uVar23 = uVar19 >> 2;
            uVar15 = 0;
            do {
              uVar16 = uVar15;
              if ((0x3f < uVar16) || (uVar16 == 0x40)) goto LAB_00107870;
              uVar23 = uVar23 - 1;
              uVar34 = (*(uint *)(pbVar21 + uVar16) & 0xff00ff00) >> 8 |
                       (*(uint *)(pbVar21 + uVar16) & 0xff00ff) << 8;
              *(uint *)((long)puVar22 + uVar16) = uVar34 >> 0x10 | uVar34 << 0x10;
              uVar15 = uVar16 + 4;
            } while (uVar23 != 0);
            pbVar21 = pbVar21 + uVar15;
            puVar22 = (uint *)((long)&local_a8 + uVar16 + 4);
          }
          uVar19 = uVar19 & 3;
          if (uVar19 == 1) {
            uVar19 = (uint)*pbVar21 << 0x18;
LAB_001071b8:
            if ((0x3c < uVar15) || (0x3c < uVar15)) {
LAB_00107870:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(1,0x107874);
              (*pcVar6)();
            }
            *puVar22 = uVar19;
          }
          else {
            if (uVar19 == 2) {
              uVar19 = (uint)*pbVar21 << 0x18 | (uint)pbVar21[1] << 0x10;
              goto LAB_001071b8;
            }
            if (uVar19 == 3) {
              uVar19 = (uint)*pbVar21 << 0x18 | (uint)pbVar21[1] << 0x10 | (uint)pbVar21[2] << 8;
              goto LAB_001071b8;
            }
          }
          if (3 < uVar32) {
            uVar19 = uVar32 >> 2;
            if (uVar19 < 2) {
              uVar19 = 1;
            }
            *(uint *)(lVar10 + 4) = (uint)local_a8;
            if (7 < uVar32) {
              *(undefined4 *)(lVar10 + 0x14) = local_a8._4_4_;
              if (uVar19 != 2) {
                *(undefined4 *)(lVar10 + 0x24) = (undefined4)local_a0;
                if (uVar19 != 3) {
                  *(undefined4 *)(lVar10 + 0x34) = local_a0._4_4_;
                  if (uVar19 != 4) {
                    *(undefined4 *)(lVar10 + 0x44) = (undefined4)local_98;
                    if (uVar19 != 5) {
                      *(undefined4 *)(lVar10 + 0x54) = local_98._4_4_;
                      if (uVar19 != 6) {
                        *(undefined4 *)(lVar10 + 100) = (undefined4)local_90;
                        if (uVar19 != 7) {
                          *(undefined4 *)(lVar10 + 0x74) = local_90._4_4_;
                          if (uVar19 != 8) {
                            *(undefined4 *)(lVar10 + 0x84) = (undefined4)local_88;
                            if (uVar19 != 9) {
                              *(undefined4 *)(lVar10 + 0x94) = local_88._4_4_;
                              if (uVar19 != 10) {
                                *(undefined4 *)(lVar10 + 0xa4) = (undefined4)local_80;
                                if (uVar19 != 0xb) {
                                  *(undefined4 *)(lVar10 + 0xb4) = local_80._4_4_;
                                  if (uVar19 != 0xc) {
                                    *(undefined4 *)(lVar10 + 0xc4) = (undefined4)local_78;
                                    if (uVar19 != 0xd) {
                                      *(undefined4 *)(lVar10 + 0xd4) = local_78._4_4_;
                                      if (uVar19 != 0xe) {
                                        *(undefined4 *)(lVar10 + 0xe4) = (undefined4)local_70;
                                        if (uVar19 != 0xf) {
                                          *(undefined4 *)(lVar10 + 0xf4) = local_70._4_4_;
                                          if (uVar19 != 0x10) goto LAB_00107874;
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
                    }
                  }
                }
              }
            }
          }
          bVar5 = false;
        }
      }
      else {
        bVar5 = false;
        *puVar22 = *(int *)(param_1 + 10) + 0x1b000U & 0xffffff |
                   (uint)*(byte *)((long)puVar22 + 3) << 0x18;
      }
      iVar9 = *(int *)(puVar31 + 1);
      if (iVar9 != 4) {
        uVar20 = uVar20 & 1;
        cVar4 = *(char *)((long)puVar31 + 0x3d);
        goto joined_r0x00106ca8;
      }
LAB_001074b0:
      *(undefined4 *)(plVar12[0x12] + 4) = *(undefined4 *)(puVar31 + 8);
      *(undefined4 *)(plVar12[3] + 4) = 0;
      *(undefined4 *)(plVar12[0x13] + 4) = 0;
      iVar14 = *(int *)(puVar31 + 8);
      if (iVar14 == 0) {
        iVar14 = *(int *)(param_1 + 0x35);
      }
      iVar9 = 0;
      *(int *)(plVar12[0x18] + 4) = iVar14;
    }
    else {
      bVar5 = false;
      uVar20 = 0;
      cVar4 = *(char *)((long)puVar31 + 0x3d);
joined_r0x00106ca8:
      if ((cVar4 != '\0') || ((*(byte *)(puVar31 + 8) & 0x3f) == 0)) {
        switch(iVar9) {
        case 0:
        case 2:
          if (*(char *)((long)puVar31 + 0x3c) == '\0') {
            bVar25 = true;
LAB_001073d4:
            puVar22 = (uint *)puVar31[2];
            uVar32 = (*puVar22 & 0xff00ff00) >> 8 | (*puVar22 & 0xff00ff) << 8;
            uVar34 = uVar32 >> 0x10 | uVar32 << 0x10;
            uVar32 = (puVar22[1] & 0xff00ff00) >> 8 | (puVar22[1] & 0xff00ff) << 8;
            uVar32 = uVar32 >> 0x10 | uVar32 << 0x10;
            uVar19 = (puVar22[2] & 0xff00ff00) >> 8 | (puVar22[2] & 0xff00ff) << 8;
            uVar27 = uVar19 >> 0x10 | uVar19 << 0x10;
            uVar19 = (puVar22[3] & 0xff00ff00) >> 8 | (puVar22[3] & 0xff00ff) << 8;
            uVar19 = uVar19 >> 0x10 | uVar19 << 0x10;
            uVar23 = (puVar22[4] & 0xff00ff00) >> 8 | (puVar22[4] & 0xff00ff) << 8;
            uVar24 = uVar23 >> 0x10 | uVar23 << 0x10;
            if (bVar25) {
              uVar23 = 0;
              uVar8 = 0;
              uVar26 = 0;
            }
            else {
              uVar23 = (puVar22[5] & 0xff00ff00) >> 8 | (puVar22[5] & 0xff00ff) << 8;
              uVar23 = uVar23 >> 0x10 | uVar23 << 0x10;
              uVar26 = (puVar22[6] & 0xff00ff00) >> 8 | (puVar22[6] & 0xff00ff) << 8;
              uVar8 = uVar26 >> 0x10 | uVar26 << 0x10;
              uVar26 = (puVar22[7] & 0xff00ff00) >> 8 | (puVar22[7] & 0xff00ff) << 8;
              uVar26 = uVar26 >> 0x10 | uVar26 << 0x10;
            }
          }
          else {
            uVar23 = 0;
            uVar8 = 0;
            uVar26 = 0;
            uVar32 = 0xefcdab89;
            uVar24 = 0xc3d2e1f0;
            uVar27 = 0x98badcfe;
            uVar34 = 0x67452301;
            uVar19 = 0x10325476;
          }
          break;
        case 1:
        case 3:
          if (*(char *)((long)puVar31 + 0x3c) == '\0') {
            bVar25 = false;
            goto LAB_001073d4;
          }
          uVar32 = 0xbb67ae85;
          uVar19 = 0xa54ff53a;
          uVar23 = 0x9b05688c;
          uVar34 = 0x6a09e667;
          uVar26 = 0x5be0cd19;
          uVar24 = 0x510e527f;
          uVar27 = 0x3c6ef372;
          uVar8 = 0x1f83d9ab;
          break;
        default:
          iVar9 = -0x16;
          goto LAB_001074e4;
        }
        lVar10 = plVar12[0x15];
        *(uint *)(lVar10 + 4) = uVar34;
        *(uint *)(lVar10 + 0x14) = uVar32;
        *(uint *)(lVar10 + 0x24) = uVar27;
        *(uint *)(lVar10 + 0x34) = uVar19;
        *(uint *)(lVar10 + 0x44) = uVar24;
        if ((*(uint *)(puVar31 + 1) | 2) == 3) {
          *(uint *)(lVar10 + 0x54) = uVar23;
          *(uint *)(lVar10 + 100) = uVar8;
          *(uint *)(lVar10 + 0x74) = uVar26;
        }
        lVar10 = plVar12[0x17];
        *(undefined4 *)(lVar10 + 4) = *(undefined4 *)(puVar31 + 4);
        *(undefined4 *)(lVar10 + 0x14) = *(undefined4 *)((long)puVar31 + 0x24);
        uVar32 = *(uint *)(plVar12[0x11] + 4) & 0xfff0ffff;
        if (*(char *)((long)puVar31 + 0x3d) != '\0') {
          uVar32 = uVar32 | 0x10000;
        }
        if (*(char *)((long)puVar31 + 0x3c) != '\0') {
          uVar32 = uVar32 | 0x20000;
        }
        uVar19 = uVar32 | 0x40000;
        if (uVar20 == 0) {
          uVar19 = uVar32;
        }
        uVar32 = uVar19 | 0x80000;
        if (!bVar5) {
          uVar32 = uVar19;
        }
        *(uint *)(plVar12[0x11] + 4) = uVar32;
        goto LAB_001074b0;
      }
      iVar9 = -5;
    }
LAB_001074e4:
    if (iVar9 < 0) goto LAB_001075a0;
    param_1[(ulong)uVar7 * 0x37f + 0x548] = lVar33;
    uVar30 = *puVar31;
    *(undefined4 *)(param_1 + (ulong)uVar7 * 0x37f + 0x553) = 0;
    *(undefined4 *)(param_1 + (ulong)uVar7 * 0x37f + 0x1d6) = 0;
    param_1[(ulong)uVar7 * 0x37f + 0x546] = uVar30;
    *(undefined4 *)((long)param_1 + (ulong)uVar7 * 0x1bf8 + 0x2a94) = *(undefined4 *)(puVar31 + 8);
    if (8 < uVar7) goto LAB_00107874;
    cVar4 = *(char *)(param_1 + 8);
    puVar22 = (uint *)(param_1 + (ulong)uVar7 * 0x37f + 0x1db);
    *(undefined4 *)(param_1 + (ulong)uVar7 * 0x37f + 0x1db) = 0;
    *(undefined4 *)(param_1 + (ulong)uVar7 * 0x37f + 0x1df) = 0;
    if ((cVar4 == '\0') || (plVar12 == (long *)0x0)) {
LAB_0010757c:
      iVar9 = _qce_sps_add_sg_data
                        (param_1,*(undefined8 *)(lVar33 + 0x38),*(undefined4 *)(lVar33 + 0x30),
                         param_1 + (ulong)uVar7 * 0x37f + 0x1d9);
      if (iVar9 == 0) {
        if ((*(int *)(lVar33 + 0x30) == 0) && (uVar32 = *(uint *)(param_1 + 0x35), uVar32 != 0)) {
          uVar15 = (ulong)*puVar22;
          lVar33 = (param_1[3] + (ulong)*(uint *)(param_1 + (ulong)uVar7 * 0x37f + 0x543)) -
                   param_1[2];
          puVar18 = (undefined4 *)(param_1[(ulong)uVar7 * 0x37f + 0x1da] + uVar15 * 8);
          do {
            if ((int)uVar15 == 0x200) goto LAB_0010784c;
            uVar20 = uVar32;
            if (0x7fbf < uVar32) {
              uVar20 = 0x7fc0;
            }
            uVar32 = uVar32 - uVar20;
            *puVar18 = (int)lVar33;
            puVar18[1] = (uint)((ulong)lVar33 >> 0x10) & 0xf0000 | uVar20;
            lVar33 = lVar33 + (ulong)uVar20;
            uVar15 = (ulong)(*puVar22 + 1);
            *puVar22 = *puVar22 + 1;
            puVar18 = puVar18 + 2;
          } while (uVar32 != 0);
        }
        if (*puVar22 != 0) {
          lVar33 = param_1[uVar28 * 0x37f + 0x1da] + (ulong)(*puVar22 - 1) * 8;
          *(uint *)(lVar33 + 4) = *(uint *)(lVar33 + 4) | 0x50000000;
        }
        if (*(char *)(param_1 + 0xf) != '\0') {
          uVar3 = *(ushort *)(param_1 + uVar28 * 0x37f + 0x540);
          lVar33 = (param_1[uVar28 * 0x37f + 0x526] - param_1[2]) + param_1[3];
          puVar18 = (undefined4 *)(param_1[uVar28 * 0x37f + 0x1da] + (ulong)*puVar22 * 8);
          *puVar18 = (int)lVar33;
          puVar18[1] = uVar3 | 0xa000000 | (uint)((ulong)lVar33 >> 0x10) & 0xf0000;
          uVar32 = *puVar22 + 1;
          *puVar22 = uVar32;
          if (0x1ff < uVar32) goto LAB_00107838;
        }
        puVar22 = (uint *)(param_1 + (ulong)uVar7 * 0x37f + 0x1df);
        if (*puVar22 == 0x200) {
LAB_0010784c:
          pcVar11 = "_qce_sps_add_data";
          uVar32 = 0x200;
          goto LAB_00107860;
        }
        lVar33 = (param_1[3] + (ulong)*(uint *)(param_1 + (ulong)uVar7 * 0x37f + 0x541)) -
                 param_1[2];
        puVar18 = (undefined4 *)(param_1[(ulong)uVar7 * 0x37f + 0x1de] + (ulong)*puVar22 * 8);
        *puVar18 = (int)lVar33;
        puVar18[1] = (uint)((ulong)lVar33 >> 0x10) & 0xf0000 | 0x80;
        uVar20 = *puVar22;
        uVar32 = uVar20 + 1;
        *puVar22 = uVar32;
        if (param_2 == (undefined8 *)0x0) {
          if (uVar32 != 0) {
            lVar33 = param_1[(ulong)uVar7 * 0x37f + 0x1de] + (ulong)uVar20 * 8;
            *(uint *)(lVar33 + 4) = *(uint *)(lVar33 + 4) | 0x80000000;
          }
          iVar9 = _qce_sps_transfer(param_1,uVar28);
        }
        else {
          select_mode(param_1,piVar2);
          iVar9 = _qce_sps_transfer(param_1,uVar28);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            if (*piVar1 != 1) goto joined_r0x00107814;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = 0;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          DataMemoryBarrier(2,3);
        }
joined_r0x00107814:
        if (iVar9 == 0) goto LAB_00107618;
      }
    }
    else {
      uVar3 = *(ushort *)(plVar12 + 0x1a);
      lVar10 = (*plVar12 - param_1[2]) + param_1[3];
      puVar18 = (undefined4 *)param_1[(ulong)uVar7 * 0x37f + 0x1da];
      *puVar18 = (int)lVar10;
      puVar18[1] = (uint)uVar3 | (uint)((ulong)lVar10 >> 0x10) & 0xf0000 | 0xc000000;
      uVar32 = *puVar22 + 1;
      *puVar22 = uVar32;
      if (uVar32 < 0x200) goto LAB_0010757c;
LAB_00107838:
      pcVar11 = "_qce_sps_add_cmd";
LAB_00107860:
      _printk(&DAT_0010fd4b,pcVar11,uVar32,0x200);
      iVar9 = -0xc;
    }
LAB_001075a0:
    iVar14 = *piVar35;
    if ((iVar14 != 0) && (0 < iVar14)) {
      uVar29 = *param_1;
      uVar30 = puVar31[3];
      do {
        dma_unmap_sg_attrs(uVar29,uVar30,1,1,0);
        uVar30 = sg_next(uVar30);
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
    }
    if (8 < uVar7) {
LAB_00107874:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x107878);
      (*pcVar6)();
    }
    *(undefined4 *)(param_1 + uVar28 * 0x37f + 0x1d6) = 5;
    Hint_Prefetch(piVar2,2,0,1);
    do {
      iVar14 = *piVar2;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar5) {
        *piVar2 = 0;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
  }
  if (iVar14 == 0) {
    _printk(&DAT_00110c06,"qce_free_req_info",uVar28);
  }
LAB_00107618:
  lVar33 = sp_el0;
  if (*(long *)(lVar33 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// qce_f8_req @ 001078ac size=1492
// signature: undefined qce_f8_req(void)
// callers: []
//------------------------------------------------------------

int qce_f8_req(undefined8 *param_1,ulong *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  long *plVar4;
  ushort uVar5;
  int iVar6;
  char cVar7;
  bool bVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 uVar14;
  char *pcVar15;
  ulong uVar16;
  uint uVar17;
  long lVar18;
  undefined4 *puVar19;
  uint uVar20;
  ulong uVar21;
  long *plVar22;
  ulong uVar23;
  
  uVar10 = qce_alloc_req_info();
  if ((int)uVar10 < 0) {
    return -0x10;
  }
  uVar21 = (ulong)uVar10;
  *(uint *)((long)param_2 + 0x34) = uVar10;
  if (9 < uVar10) goto LAB_00107e78;
  piVar1 = (int *)(param_1 + uVar21 * 0x37f + 0x1d5);
  if ((int)param_2[6] == 1) {
    lVar18 = 0x26a8;
LAB_00107934:
    plVar4 = (long *)((long)param_1 + lVar18 + uVar21 * 0x1bf8);
    uVar23 = *param_2;
    if ((uVar23 != 0) && ((byte)param_2[3] < 0x1f)) {
      uVar16 = param_2[1];
      plVar22 = (long *)*param_1;
      uVar13 = param_2[2];
      uVar12 = is_vmalloc_addr(uVar23);
      if (((uVar12 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
        dma_map_single_attrs___already_done = 1;
        uVar14 = dev_driver_string(plVar22);
        lVar18 = plVar22[0xe];
        if (lVar18 == 0) {
          lVar18 = *plVar22;
        }
        __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar14,lVar18);
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x800,0x107a38);
        (*pcVar9)();
      }
      if ((uVar12 & 1) == 0) {
        uVar23 = dma_map_page_attrs(plVar22,(((long)(uVar23 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                            0x40 + -0x200000000,uVar23 & 0xfff,(short)uVar13,
                                    uVar23 != uVar16,0);
      }
      else {
        uVar23 = 0xffffffffffffffff;
      }
      param_1[uVar21 * 0x37f + 0x550] = uVar23;
      uVar13 = param_2[1];
      if (*param_2 == uVar13) {
        uVar13 = 0;
      }
      else {
        uVar23 = param_2[2];
        plVar22 = (long *)*param_1;
        uVar12 = is_vmalloc_addr(uVar13);
        if (((uVar12 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar14 = dev_driver_string(plVar22);
          lVar18 = plVar22[0xe];
          if (lVar18 == 0) {
            lVar18 = *plVar22;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar14,lVar18);
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x800,0x107afc);
          (*pcVar9)();
        }
        if ((uVar12 & 1) == 0) {
          uVar13 = dma_map_page_attrs(plVar22,(((long)(uVar13 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                              0x40 + -0x200000000,uVar13 & 0xfff,(short)uVar23,2,0);
          uVar23 = uVar13;
        }
        else {
          uVar13 = 0xffffffffffffffff;
          uVar23 = 0xffffffffffffffff;
        }
      }
      param_1[(ulong)uVar10 * 0x37f + 0x551] = uVar13;
      *(uint *)(param_1 + (ulong)uVar10 * 0x37f + 0x552) = (uint)(ushort)param_2[2];
      if (*(char *)(param_1 + 8) == '\0') {
        _ce_f8_setup_direct(param_1,param_2,1,0,(short)param_2[2]);
      }
      else {
        _ce_f8_setup();
      }
      param_1[(ulong)uVar10 * 0x37f + 0x548] = param_3;
      param_1[(ulong)uVar10 * 0x37f + 0x546] = param_4;
      *(undefined4 *)(param_1 + (ulong)uVar10 * 0x37f + 0x553) = 0;
      *(undefined4 *)(param_1 + (ulong)uVar10 * 0x37f + 0x1d6) = 3;
      *(uint *)((long)param_1 + (ulong)uVar10 * 0x1bf8 + 0x2a94) = (uint)(ushort)param_2[2];
      if (8 < uVar10) {
LAB_00107e78:
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x107e7c);
        (*pcVar9)();
      }
      cVar7 = *(char *)(param_1 + 8);
      puVar2 = (uint *)(param_1 + (ulong)uVar10 * 0x37f + 0x1db);
      *(undefined4 *)(param_1 + (ulong)uVar10 * 0x37f + 0x1db) = 0;
      *(undefined4 *)(param_1 + (ulong)uVar10 * 0x37f + 0x1df) = 0;
      if (cVar7 == '\0') {
        uVar13 = 0;
        uVar5 = (ushort)param_2[2];
joined_r0x00107c28:
        if (uVar5 != 0) {
          uVar17 = (uint)uVar5;
          uVar12 = (ulong)*(uint *)(param_1 + uVar21 * 0x37f + 0x550);
          puVar19 = (undefined4 *)(param_1[uVar21 * 0x37f + 0x1da] + uVar13 * 8);
          do {
            if ((int)uVar13 == 0x200) {
              pcVar15 = "_qce_sps_add_data";
              goto LAB_00107dbc;
            }
            uVar20 = uVar17;
            if (0x7fbf < uVar17) {
              uVar20 = 0x7fc0;
            }
            uVar17 = uVar17 - uVar20;
            *puVar19 = (int)uVar12;
            puVar19[1] = (uint)(uVar12 >> 0x10) & 0xf0000 | uVar20;
            uVar12 = uVar12 + uVar20;
            uVar13 = (ulong)(*puVar2 + 1);
            *puVar2 = *puVar2 + 1;
            puVar19 = puVar19 + 2;
          } while (uVar17 != 0);
        }
        if ((int)uVar13 == 0) {
          uVar13 = 0;
        }
        else {
          lVar18 = param_1[uVar21 * 0x37f + 0x1da] + (ulong)((int)uVar13 - 1) * 8;
          *(uint *)(lVar18 + 4) = *(uint *)(lVar18 + 4) | 0x50000000;
          uVar13 = (ulong)*puVar2;
        }
        uVar5 = *(ushort *)(param_1 + uVar21 * 0x37f + 0x540);
        lVar18 = (param_1[uVar21 * 0x37f + 0x526] - param_1[2]) + param_1[3];
        puVar19 = (undefined4 *)(param_1[uVar21 * 0x37f + 0x1da] + uVar13 * 8);
        *puVar19 = (int)lVar18;
        puVar19[1] = uVar5 | 0xa000000 | (uint)((ulong)lVar18 >> 0x10) & 0xf0000;
        uVar17 = *puVar2 + 1;
        uVar13 = (ulong)uVar17;
        *puVar2 = uVar17;
        if (0x1ff < uVar17) goto LAB_00107d98;
        iVar11 = _qce_sps_add_data(uVar23 & 0xffffffff,(short)param_2[2],
                                   param_1 + uVar21 * 0x37f + 0x1dd);
        if ((iVar11 == 0) &&
           (iVar11 = _qce_sps_add_data((param_1[3] +
                                       (ulong)*(uint *)(param_1 + uVar21 * 0x37f + 0x541)) -
                                       param_1[2],0x80,param_1 + uVar21 * 0x37f + 0x1dd),
           iVar11 == 0)) {
          select_mode(param_1,piVar1);
          iVar11 = _qce_sps_transfer(param_1,uVar21);
          piVar3 = (int *)((long)param_1 + 0x10a64);
          Hint_Prefetch(piVar3,2,0,1);
          do {
            if (*piVar3 != 1) goto LAB_00107e9c;
            cVar7 = '\x01';
            bVar8 = (bool)ExclusiveMonitorPass(piVar3,0x10);
            if (bVar8) {
              *piVar3 = 0;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
          DataMemoryBarrier(2,3);
LAB_00107e9c:
          if (iVar11 == 0) {
            return 0;
          }
        }
      }
      else {
        lVar18 = (*plVar4 - param_1[2]) + param_1[3];
        uVar5 = *(ushort *)(plVar4 + 0x1a);
        puVar19 = (undefined4 *)param_1[uVar21 * 0x37f + 0x1da];
        *puVar19 = (int)lVar18;
        puVar19[1] = (uint)uVar5 | (uint)((ulong)lVar18 >> 0x10) & 0xf0000 | 0xc000000;
        uVar17 = *puVar2 + 1;
        uVar13 = (ulong)uVar17;
        *puVar2 = uVar17;
        if (uVar17 < 0x200) {
          uVar5 = (ushort)param_2[2];
          goto joined_r0x00107c28;
        }
LAB_00107d98:
        pcVar15 = "_qce_sps_add_cmd";
LAB_00107dbc:
        _printk(&DAT_0010fd4b,pcVar15,uVar13,0x200);
        iVar11 = -0xc;
      }
      if (param_1[uVar21 * 0x37f + 0x551] != 0) {
        dma_unmap_page_attrs(*param_1,param_1[uVar21 * 0x37f + 0x551],(short)param_2[2],2,0);
      }
      lVar18 = param_1[uVar21 * 0x37f + 0x550];
      if (lVar18 != 0) {
        dma_unmap_page_attrs(*param_1,lVar18,(short)param_2[2],*param_2 != param_2[1],0);
      }
      *(undefined4 *)(param_1 + (ulong)uVar10 * 0x37f + 0x1d6) = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar6 = *piVar1;
        cVar7 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar8) {
          *piVar1 = 0;
          cVar7 = ExclusiveMonitorsStatus();
        }
      } while (cVar7 != '\0');
      DataMemoryBarrier(2,3);
      goto joined_r0x00107e34;
    }
    if (8 < uVar10) goto LAB_00107e78;
    *(undefined4 *)(param_1 + uVar21 * 0x37f + 0x1d6) = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar6 = *piVar1;
      cVar7 = '\x01';
      bVar8 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar8) {
        *piVar1 = 0;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
    DataMemoryBarrier(2,3);
  }
  else {
    if ((int)param_2[6] == 0) {
      lVar18 = 0x25d0;
      goto LAB_00107934;
    }
    if (8 < uVar10) goto LAB_00107e78;
    *(undefined4 *)(param_1 + uVar21 * 0x37f + 0x1d6) = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar6 = *piVar1;
      cVar7 = '\x01';
      bVar8 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar8) {
        *piVar1 = 0;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
    DataMemoryBarrier(2,3);
  }
  iVar11 = -0x16;
joined_r0x00107e34:
  if (iVar6 == 0) {
    _printk(&DAT_00110c06,"qce_free_req_info",uVar21);
  }
  return iVar11;
}



//------------------------------------------------------------
// _ce_f8_setup @ 00107ea4 size=260
// signature: undefined _ce_f8_setup(void)
// callers: [qce_f8_req, qce_f8_multi_pkt_req]
//------------------------------------------------------------

void _ce_f8_setup(long param_1,long param_2,ushort param_3,uint param_4,uint param_5,long param_6)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  
  uVar3 = (*(uint *)(param_1 + 0x1a8) >> 3) * 0x20000 - 0x1fff2 | *(int *)(param_1 + 0x134) << 5;
  lVar7 = 0xcc;
  if (*(int *)(param_2 + 0x30) != 0) {
    lVar7 = 0xd0;
  }
  *(uint *)(param_1 + 0x8c) = uVar3;
  *(uint *)(param_1 + 0x90) = uVar3 | 0x200;
  uVar2 = *(uint *)(param_1 + lVar7);
  *(uint *)(*(long *)(param_6 + 8) + 4) = uVar3;
  *(undefined4 *)(*(long *)(param_6 + 0x10) + 4) = *(undefined4 *)(param_1 + 0x90);
  uVar3 = (*(uint *)(param_2 + 0x19) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x19) & 0xff00ff) << 8;
  lVar7 = *(long *)(param_6 + 0x30);
  uVar4 = (*(uint *)(param_2 + 0x1d) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x1d) & 0xff00ff) << 8;
  uVar5 = (*(uint *)(param_2 + 0x21) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x21) & 0xff00ff) << 8;
  uVar6 = (*(uint *)(param_2 + 0x25) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x25) & 0xff00ff) << 8;
  *(uint *)(lVar7 + 4) = uVar3 >> 0x10 | uVar3 << 0x10;
  *(uint *)(lVar7 + 0x14) = uVar4 >> 0x10 | uVar4 << 0x10;
  *(uint *)(lVar7 + 0x24) = uVar5 >> 0x10 | uVar5 << 0x10;
  *(uint *)(lVar7 + 0x34) = uVar6 >> 0x10 | uVar6 << 0x10;
  uVar3 = uVar2 | 0x10000;
  if (*(int *)(param_2 + 0x2c) != 1) {
    uVar3 = uVar2;
  }
  uVar1 = 0;
  if (param_3 != 1) {
    uVar1 = param_3;
  }
  *(uint *)(*(long *)(param_6 + 0x18) + 4) = uVar3;
  *(uint *)(*(long *)(param_6 + 0x28) + 4) = param_4 & 0xffff;
  *(uint *)(*(long *)(param_6 + 0x20) + 4) = param_5 & 0xffff;
  *(uint *)(*(long *)(param_6 + 0xc0) + 4) = (uint)*(ushort *)(param_2 + 0x10);
  lVar7 = *(long *)(param_6 + 0x40);
  *(undefined4 *)(lVar7 + 4) = *(undefined4 *)(param_2 + 0x14);
  *(uint *)(lVar7 + 0x14) = (uint)*(byte *)(param_2 + 0x18) | (uint)uVar1 << 0x10;
  **(uint **)(param_6 + 200) =
       *(int *)(param_1 + 0x50) + 0x1a120U & 0xffffff |
       (uint)*(byte *)((long)*(uint **)(param_6 + 200) + 3) << 0x18;
  return;
}



//------------------------------------------------------------
// _ce_f8_setup_direct @ 00107fa8 size=524
// signature: undefined _ce_f8_setup_direct(void)
// callers: [qce_f8_req, qce_f8_multi_pkt_req]
//------------------------------------------------------------

void _ce_f8_setup_direct(long param_1,long param_2,ushort param_3,undefined2 param_4,
                        undefined2 param_5)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  lVar2 = 0xcc;
  if (*(int *)(param_2 + 0x30) != 0) {
    lVar2 = 0xd0;
  }
  uVar3 = *(uint *)(param_1 + lVar2);
  writel_relaxed(0,*(long *)(param_1 + 0x48) + 0x1a100);
  uVar4 = (*(uint *)(param_1 + 0x1a8) >> 3) * 0x20000 - 0x1fff2 | *(int *)(param_1 + 0x134) << 5;
  *(uint *)(param_1 + 0x8c) = uVar4;
  *(uint *)(param_1 + 0x90) = uVar4 | 0x200;
  writel_relaxed(uVar4,*(long *)(param_1 + 0x48) + 0x1a400);
  writel_relaxed(0,*(long *)(param_1 + 0x48) + 0x1a300);
  writel_relaxed(0,*(long *)(param_1 + 0x48) + 0x1a304);
  uVar4 = (*(uint *)(param_2 + 0x19) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x19) & 0xff00ff) << 8;
  uVar5 = (*(uint *)(param_2 + 0x1d) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x1d) & 0xff00ff) << 8;
  uVar6 = (*(uint *)(param_2 + 0x21) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x21) & 0xff00ff) << 8;
  uVar7 = (*(uint *)(param_2 + 0x25) & 0xff00ff00) >> 8 |
          (*(uint *)(param_2 + 0x25) & 0xff00ff) << 8;
  writel_relaxed(uVar4 >> 0x10 | uVar4 << 0x10,*(long *)(param_1 + 0x48) + 0x1d000);
  writel_relaxed(uVar5 >> 0x10 | uVar5 << 0x10,*(long *)(param_1 + 0x48) + 0x1d004);
  writel_relaxed(uVar6 >> 0x10 | uVar6 << 0x10,*(long *)(param_1 + 0x48) + 0x1d008);
  writel_relaxed(uVar7 >> 0x10 | uVar7 << 0x10,*(long *)(param_1 + 0x48) + 0x1d00c);
  uVar4 = uVar3 | 0x10000;
  if (*(int *)(param_2 + 0x2c) != 1) {
    uVar4 = uVar3;
  }
  writel_relaxed(uVar4,*(long *)(param_1 + 0x48) + 0x1a200);
  writel_relaxed(param_4,*(long *)(param_1 + 0x48) + 0x1a208);
  writel_relaxed(param_5,*(long *)(param_1 + 0x48) + 0x1a204);
  writel_relaxed(*(undefined2 *)(param_2 + 0x10),*(long *)(param_1 + 0x48) + 0x1a110);
  writel_relaxed(*(undefined4 *)(param_2 + 0x14),*(long *)(param_1 + 0x48) + 0x1a20c);
  uVar1 = 0;
  if (param_3 != 1) {
    uVar1 = param_3;
  }
  writel_relaxed((uint)*(byte *)(param_2 + 0x18) | (uint)uVar1 << 0x10,
                 *(long *)(param_1 + 0x48) + 0x1a210);
  writel_relaxed(*(undefined4 *)(param_1 + 0x90),*(long *)(param_1 + 0x48) + 0x1a400);
  writel_relaxed(7,*(long *)(param_1 + 0x48) + 0x1a120);
  DataSynchronizationBarrier(3,3,0);
  return;
}



//------------------------------------------------------------
// qce_f8_multi_pkt_req @ 001081b8 size=1532
// signature: undefined qce_f8_multi_pkt_req(void)
// callers: []
//------------------------------------------------------------

int qce_f8_multi_pkt_req(undefined8 *param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  long *plVar4;
  uint uVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  int iVar10;
  bool bVar11;
  code *pcVar12;
  uint uVar13;
  int iVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 uVar17;
  char *pcVar18;
  long lVar19;
  undefined4 *puVar20;
  uint uVar21;
  uint uVar22;
  ulong uVar23;
  ulong uVar24;
  long *plVar25;
  uint uVar26;
  
  uVar7 = *param_2;
  uVar8 = param_2[1];
  uVar9 = param_2[2];
  uVar13 = qce_alloc_req_info();
  if ((int)uVar13 < 0) {
    return -0x10;
  }
  uVar23 = (ulong)uVar13;
  *(uint *)(param_2 + 0x1e) = uVar13;
  if (9 < uVar13) {
LAB_001087ac:
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x5512,0x1087b0);
    (*pcVar12)();
  }
  piVar1 = (int *)(param_1 + uVar23 * 0x37f + 0x1d5);
  if (*(int *)(param_2 + 0x1c) == 1) {
    lVar19 = 0x26a8;
  }
  else {
    if (*(int *)(param_2 + 0x1c) != 0) {
      if (8 < uVar13) goto LAB_001087ac;
      iVar14 = -0x16;
      *(undefined4 *)(param_1 + uVar23 * 0x37f + 0x1d6) = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar10 = *piVar1;
        cVar6 = '\x01';
        bVar11 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar11) {
          *piVar1 = 0;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      DataMemoryBarrier(2,3);
      goto joined_r0x00108764;
    }
    lVar19 = 0x25d0;
  }
  plVar4 = (long *)((long)param_1 + lVar19 + uVar23 * 0x1bf8);
  plVar25 = (long *)*param_1;
  uVar24 = *(ulong *)(param_2 + 4);
  uVar16 = *(ulong *)(param_2 + 8);
  uVar26 = (uint)param_2[0xc] * (uint)uVar7;
  uVar15 = is_vmalloc_addr(uVar24);
  if (((uVar15 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar17 = dev_driver_string(plVar25);
    lVar19 = plVar25[0xe];
    if (lVar19 == 0) {
      lVar19 = *plVar25;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar17,lVar19);
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x800,0x108320);
    (*pcVar12)();
  }
  if ((uVar15 & 1) == 0) {
    uVar24 = dma_map_page_attrs(plVar25,(((long)(uVar24 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                        -0x200000000,uVar24 & 0xfff,uVar26,uVar24 != uVar16,0);
  }
  else {
    uVar24 = 0xffffffffffffffff;
  }
  param_1[uVar23 * 0x37f + 0x550] = uVar24;
  uVar16 = *(ulong *)(param_2 + 8);
  if (*(ulong *)(param_2 + 4) == uVar16) {
    uVar16 = 0;
  }
  else {
    plVar25 = (long *)*param_1;
    uVar24 = is_vmalloc_addr(uVar16);
    if (((uVar24 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar17 = dev_driver_string(plVar25);
      lVar19 = plVar25[0xe];
      if (lVar19 == 0) {
        lVar19 = *plVar25;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar17,lVar19);
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x800,0x1083e8);
      (*pcVar12)();
    }
    if ((uVar24 & 1) == 0) {
      uVar16 = dma_map_page_attrs(plVar25,(((long)(uVar16 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40
                                          + -0x200000000,uVar16 & 0xfff,uVar26,2,0);
      uVar24 = uVar16;
    }
    else {
      uVar16 = 0xffffffffffffffff;
      uVar24 = 0xffffffffffffffff;
    }
  }
  cVar6 = *(char *)(param_1 + 8);
  param_1[uVar23 * 0x37f + 0x551] = uVar16;
  *(uint *)(param_1 + uVar23 * 0x37f + 0x552) = uVar26;
  if (cVar6 == '\0') {
    _ce_f8_setup_direct(param_1,param_2 + 4,(uint)uVar7,uVar8,uVar9);
  }
  else {
    _ce_f8_setup();
  }
  param_1[(ulong)uVar13 * 0x37f + 0x548] = param_3;
  param_1[(ulong)uVar13 * 0x37f + 0x546] = param_4;
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x553) = 0;
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x1d6) = 3;
  *(uint *)((long)param_1 + (ulong)uVar13 * 0x1bf8 + 0x2a94) = uVar26;
  if (8 < uVar13) goto LAB_001087ac;
  cVar6 = *(char *)(param_1 + 8);
  puVar2 = (uint *)(param_1 + (ulong)uVar13 * 0x37f + 0x1db);
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x1db) = 0;
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x1df) = 0;
  if (cVar6 == '\0') {
    if (uVar26 == 0) {
LAB_00108590:
      uVar16 = 0;
    }
    else {
      uVar22 = 0;
      uVar16 = (ulong)*(uint *)(param_1 + uVar23 * 0x37f + 0x550);
      puVar20 = (undefined4 *)param_1[(ulong)uVar13 * 0x37f + 0x1da];
      uVar21 = uVar26;
      do {
        if (uVar22 == 0x200) goto LAB_001086d8;
        uVar22 = uVar21;
        if (0x7fbf < uVar21) {
          uVar22 = 0x7fc0;
        }
        uVar21 = uVar21 - uVar22;
        *puVar20 = (int)uVar16;
        puVar20[1] = (uint)(uVar16 >> 0x10) & 0xf0000 | uVar22;
        uVar5 = *puVar2;
        uVar16 = uVar16 + uVar22;
        uVar22 = uVar5 + 1;
        *puVar2 = uVar22;
        puVar20 = puVar20 + 2;
      } while (uVar21 != 0);
      if (uVar22 == 0) goto LAB_00108590;
      lVar19 = param_1[uVar23 * 0x37f + 0x1da] + (ulong)uVar5 * 8;
      *(uint *)(lVar19 + 4) = *(uint *)(lVar19 + 4) | 0x50000000;
      uVar16 = (ulong)*puVar2;
    }
    uVar7 = *(ushort *)(param_1 + uVar23 * 0x37f + 0x540);
    lVar19 = (param_1[uVar23 * 0x37f + 0x526] - param_1[2]) + param_1[3];
    puVar20 = (undefined4 *)(param_1[uVar23 * 0x37f + 0x1da] + uVar16 * 8);
    *puVar20 = (int)lVar19;
    puVar20[1] = uVar7 | 0xa000000 | (uint)((ulong)lVar19 >> 0x10) & 0xf0000;
    uVar22 = *puVar2 + 1;
    *puVar2 = uVar22;
    if (0x1ff < uVar22) goto LAB_001086c4;
    if (uVar26 != 0) {
      puVar2 = (uint *)(param_1 + (ulong)uVar13 * 0x37f + 0x1df);
      uVar16 = (ulong)*puVar2;
      uVar24 = uVar24 & 0xffffffff;
      puVar20 = (undefined4 *)(param_1[(ulong)uVar13 * 0x37f + 0x1de] + uVar16 * 8);
      uVar22 = uVar26;
      do {
        if ((int)uVar16 == 0x200) goto LAB_001086d8;
        uVar21 = uVar22;
        if (0x7fbf < uVar22) {
          uVar21 = 0x7fc0;
        }
        uVar22 = uVar22 - uVar21;
        *puVar20 = (int)uVar24;
        puVar20[1] = (uint)(uVar24 >> 0x10) & 0xf0000 | uVar21;
        uVar24 = uVar24 + uVar21;
        uVar16 = (ulong)(*puVar2 + 1);
        *puVar2 = *puVar2 + 1;
        puVar20 = puVar20 + 2;
      } while (uVar22 != 0);
    }
    iVar14 = _qce_sps_add_data((param_1[3] +
                               (ulong)*(uint *)(param_1 + (ulong)uVar13 * 0x37f + 0x541)) -
                               param_1[2],0x80,param_1 + (ulong)uVar13 * 0x37f + 0x1dd);
    if (iVar14 == 0) {
      select_mode(param_1,piVar1);
      iVar14 = _qce_sps_transfer(param_1,uVar23);
      piVar3 = (int *)((long)param_1 + 0x10a64);
      Hint_Prefetch(piVar3,2,0,1);
      do {
        if (*piVar3 != 1) goto LAB_001087d0;
        cVar6 = '\x01';
        bVar11 = (bool)ExclusiveMonitorPass(piVar3,0x10);
        if (bVar11) {
          *piVar3 = 0;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      DataMemoryBarrier(2,3);
LAB_001087d0:
      if (iVar14 == 0) {
        return 0;
      }
    }
  }
  else {
    lVar19 = (*plVar4 - param_1[2]) + param_1[3];
    uVar7 = *(ushort *)(plVar4 + 0x1a);
    puVar20 = (undefined4 *)param_1[(ulong)uVar13 * 0x37f + 0x1da];
    *puVar20 = (int)lVar19;
    puVar20[1] = (uint)uVar7 | (uint)((ulong)lVar19 >> 0x10) & 0xf0000 | 0xc000000;
    uVar22 = *puVar2 + 1;
    *puVar2 = uVar22;
    if (0x1ff < uVar22) {
LAB_001086c4:
      pcVar18 = "_qce_sps_add_cmd";
      goto LAB_001086ec;
    }
    iVar14 = 0;
  }
LAB_001086fc:
  if (param_1[uVar23 * 0x37f + 0x551] != 0) {
    dma_unmap_page_attrs(*param_1,param_1[uVar23 * 0x37f + 0x551],uVar26,2,0);
  }
  dma_unmap_page_attrs
            (*param_1,param_1[uVar23 * 0x37f + 0x550],uVar26,
             *(long *)(param_2 + 4) != *(long *)(param_2 + 8),0);
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x1d6) = 5;
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar10 = *piVar1;
    cVar6 = '\x01';
    bVar11 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar11) {
      *piVar1 = 0;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  DataMemoryBarrier(2,3);
joined_r0x00108764:
  if (iVar10 == 0) {
    _printk(&DAT_00110c06,"qce_free_req_info",uVar23);
  }
  return iVar14;
LAB_001086d8:
  pcVar18 = "_qce_sps_add_data";
  uVar22 = 0x200;
LAB_001086ec:
  _printk(&DAT_0010fd4b,pcVar18,uVar22,0x200);
  iVar14 = -0xc;
  goto LAB_001086fc;
}



//------------------------------------------------------------
// qce_f9_req @ 001087dc size=1808
// signature: undefined qce_f9_req(void)
// callers: []
//------------------------------------------------------------

int qce_f9_req(undefined8 *param_1,ulong *param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  long *plVar4;
  char cVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  code *pcVar12;
  uint uVar13;
  int iVar14;
  ulong uVar15;
  undefined8 uVar16;
  char *pcVar17;
  ulong uVar18;
  long lVar19;
  uint uVar20;
  undefined4 *puVar21;
  uint uVar22;
  ulong uVar23;
  long *plVar24;
  ulong uVar25;
  
  uVar13 = qce_alloc_req_info();
  if ((int)uVar13 < 0) {
    return -0x10;
  }
  uVar23 = (ulong)uVar13;
  *(uint *)(param_2 + 6) = uVar13;
  if (9 < uVar13) {
LAB_00108ee0:
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x5512,0x108ee4);
    (*pcVar12)();
  }
  piVar1 = (int *)(param_1 + uVar23 * 0x37f + 0x1d5);
  if (*(int *)((long)param_2 + 0x2c) == 1) {
    lVar19 = 0x2858;
  }
  else {
    if (*(int *)((long)param_2 + 0x2c) != 0) {
      if (8 < uVar13) goto LAB_00108ee0;
      iVar14 = -0x16;
      *(undefined4 *)(param_1 + uVar23 * 0x37f + 0x1d6) = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar11 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar11) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      goto joined_r0x00108e98;
    }
    lVar19 = 0x2780;
  }
  uVar25 = *param_2;
  plVar4 = (long *)((long)param_1 + lVar19 + uVar23 * 0x1bf8);
  plVar24 = (long *)*param_1;
  uVar18 = param_2[1];
  uVar15 = is_vmalloc_addr(uVar25);
  if (((uVar15 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar16 = dev_driver_string(plVar24);
    lVar19 = plVar24[0xe];
    if (lVar19 == 0) {
      lVar19 = *plVar24;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar16,lVar19);
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x800,0x108928);
    (*pcVar12)();
  }
  if ((uVar15 & 1) == 0) {
    uVar16 = dma_map_page_attrs(plVar24,(((long)(uVar25 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                        -0x200000000,uVar25 & 0xfff,(short)uVar18,1,0);
  }
  else {
    uVar16 = 0xffffffffffffffff;
  }
  uVar20 = *(uint *)(param_1 + 0x35);
  param_1[uVar23 * 0x37f + 0x550] = uVar16;
  *(uint *)(param_1 + uVar23 * 0x37f + 0x552) = (uint)(ushort)param_2[1];
  lVar19 = 0xfc;
  if (*(int *)((long)param_2 + 0x2c) != 0) {
    lVar19 = 0x100;
  }
  uVar22 = (uVar20 >> 3) * 0x20000 - 0x1fff2 | *(int *)((long)param_1 + 0x134) << 5;
  uVar20 = *(uint *)((long)param_1 + lVar19);
  *(uint *)((long)param_1 + 0x8c) = uVar22;
  *(uint *)(param_1 + 0x12) = uVar22 | 0x200;
  if (*(char *)(param_1 + 8) == '\0') {
    writel_relaxed(0,param_1[9] + 0x1a100);
    writel_relaxed(*(undefined4 *)((long)param_1 + 0x8c),param_1[9] + 0x1a400);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,param_1[9] + 0x1a200);
    writel_relaxed(0,param_1[9] + 0x1a204);
    uVar22 = (*(uint *)((long)param_2 + 0x1c) & 0xff00ff00) >> 8 |
             (*(uint *)((long)param_2 + 0x1c) & 0xff00ff) << 8;
    uVar8 = ((uint)param_2[4] & 0xff00ff00) >> 8 | ((uint)param_2[4] & 0xff00ff) << 8;
    uVar9 = (*(uint *)((long)param_2 + 0x24) & 0xff00ff00) >> 8 |
            (*(uint *)((long)param_2 + 0x24) & 0xff00ff) << 8;
    uVar10 = ((uint)param_2[5] & 0xff00ff00) >> 8 | ((uint)param_2[5] & 0xff00ff) << 8;
    writel_relaxed(uVar22 >> 0x10 | uVar22 << 0x10,param_1[9] + 0x1a310);
    writel_relaxed(uVar8 >> 0x10 | uVar8 << 0x10,param_1[9] + 0x1a314);
    writel_relaxed(uVar9 >> 0x10 | uVar9 << 0x10,param_1[9] + 0x1a318);
    writel_relaxed(uVar10 >> 0x10 | uVar10 << 0x10,param_1[9] + 0x1a31c);
    writel_relaxed(*(undefined1 *)((long)param_2 + 10),param_1[9] + 0x1a320);
    writel_relaxed((int)param_2[2],param_1[9] + 0x1a390);
    writel_relaxed(*(undefined4 *)((long)param_2 + 0x14),param_1[9] + 0x1a394);
    uVar22 = uVar20 | 0x800000;
    if ((int)param_2[3] != 1) {
      uVar22 = uVar20;
    }
    writel_relaxed(uVar22,param_1[9] + 0x1a300);
    writel_relaxed((short)param_2[1],param_1[9] + 0x1a304);
    writel_relaxed(0,param_1[9] + 0x1a308);
    writel_relaxed((short)param_2[1],param_1[9] + 0x1a110);
    writel_relaxed(*(undefined4 *)(param_1 + 0x12),param_1[9] + 0x1a400);
    writel_relaxed(7,param_1[9] + 0x1a120);
    DataSynchronizationBarrier(3,3,0);
  }
  else {
    *(uint *)(plVar4[1] + 4) = uVar22;
    *(undefined4 *)(plVar4[2] + 4) = *(undefined4 *)(param_1 + 0x12);
    lVar19 = plVar4[0x15];
    uVar22 = (*(uint *)((long)param_2 + 0x1c) & 0xff00ff00) >> 8 |
             (*(uint *)((long)param_2 + 0x1c) & 0xff00ff) << 8;
    uVar8 = ((uint)param_2[4] & 0xff00ff00) >> 8 | ((uint)param_2[4] & 0xff00ff) << 8;
    uVar9 = (*(uint *)((long)param_2 + 0x24) & 0xff00ff00) >> 8 |
            (*(uint *)((long)param_2 + 0x24) & 0xff00ff) << 8;
    uVar10 = ((uint)param_2[5] & 0xff00ff00) >> 8 | ((uint)param_2[5] & 0xff00ff) << 8;
    *(uint *)(lVar19 + 4) = uVar22 >> 0x10 | uVar22 << 0x10;
    *(uint *)(lVar19 + 0x14) = uVar8 >> 0x10 | uVar8 << 0x10;
    *(uint *)(lVar19 + 0x24) = uVar9 >> 0x10 | uVar9 << 0x10;
    *(uint *)(lVar19 + 0x34) = uVar10 >> 0x10 | uVar10 << 0x10;
    *(uint *)(lVar19 + 0x44) = (uint)*(byte *)((long)param_2 + 10);
    lVar19 = plVar4[0x17];
    *(int *)(lVar19 + 4) = (int)param_2[2];
    *(undefined4 *)(lVar19 + 0x14) = *(undefined4 *)((long)param_2 + 0x14);
    uVar22 = uVar20 | 0x800000;
    if ((int)param_2[3] != 1) {
      uVar22 = uVar20;
    }
    *(uint *)(plVar4[0x11] + 4) = uVar22;
    *(uint *)(plVar4[0x12] + 4) = (uint)(ushort)param_2[1];
    *(undefined4 *)(plVar4[0x13] + 4) = 0;
    *(uint *)(plVar4[0x18] + 4) = (uint)(ushort)param_2[1];
    *(uint *)plVar4[0x19] =
         *(int *)(param_1 + 10) + 0x1a120U & 0xffffff | (uint)*(byte *)(plVar4[0x19] + 3) << 0x18;
  }
  param_1[uVar23 * 0x37f + 0x548] = param_3;
  *(undefined4 *)(param_1 + uVar23 * 0x37f + 0x553) = 0;
  *(undefined4 *)(param_1 + uVar23 * 0x37f + 0x1d6) = 4;
  param_1[uVar23 * 0x37f + 0x546] = param_4;
  *(uint *)((long)param_1 + uVar23 * 0x1bf8 + 0x2a94) = (uint)(ushort)param_2[1];
  if (8 < uVar13) goto LAB_00108ee0;
  cVar5 = *(char *)(param_1 + 8);
  puVar2 = (uint *)(param_1 + (ulong)uVar13 * 0x37f + 0x1db);
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x1db) = 0;
  *(undefined4 *)(param_1 + (ulong)uVar13 * 0x37f + 0x1df) = 0;
  if (cVar5 == '\0') {
    uVar18 = 0;
    uVar6 = (ushort)param_2[1];
joined_r0x00108ca8:
    if (uVar6 != 0) {
      uVar20 = (uint)uVar6;
      uVar15 = (ulong)*(uint *)(param_1 + uVar23 * 0x37f + 0x550);
      puVar21 = (undefined4 *)(param_1[uVar23 * 0x37f + 0x1da] + uVar18 * 8);
      do {
        if ((int)uVar18 == 0x200) {
          pcVar17 = "_qce_sps_add_data";
          goto LAB_00108e50;
        }
        uVar22 = uVar20;
        if (0x7fbf < uVar20) {
          uVar22 = 0x7fc0;
        }
        uVar20 = uVar20 - uVar22;
        *puVar21 = (int)uVar15;
        puVar21[1] = (uint)(uVar15 >> 0x10) & 0xf0000 | uVar22;
        uVar15 = uVar15 + uVar22;
        uVar18 = (ulong)(*puVar2 + 1);
        *puVar2 = *puVar2 + 1;
        puVar21 = puVar21 + 2;
      } while (uVar20 != 0);
    }
    if ((int)uVar18 == 0) {
      uVar18 = 0;
    }
    else {
      lVar19 = param_1[(ulong)uVar13 * 0x37f + 0x1da] + (ulong)((int)uVar18 - 1) * 8;
      *(uint *)(lVar19 + 4) = *(uint *)(lVar19 + 4) | 0x50000000;
      uVar18 = (ulong)*puVar2;
    }
    uVar6 = *(ushort *)(param_1 + (ulong)uVar13 * 0x37f + 0x540);
    lVar19 = (param_1[(ulong)uVar13 * 0x37f + 0x526] - param_1[2]) + param_1[3];
    puVar21 = (undefined4 *)(param_1[(ulong)uVar13 * 0x37f + 0x1da] + uVar18 * 8);
    *puVar21 = (int)lVar19;
    puVar21[1] = uVar6 | 0xa000000 | (uint)((ulong)lVar19 >> 0x10) & 0xf0000;
    uVar20 = *puVar2 + 1;
    uVar18 = (ulong)uVar20;
    *puVar2 = uVar20;
    if (0x1ff < uVar20) goto LAB_00108e14;
    puVar2 = (uint *)(param_1 + (ulong)uVar13 * 0x37f + 0x1df);
    if (*puVar2 == 0x200) {
      pcVar17 = "_qce_sps_add_data";
      uVar18 = 0x200;
      goto LAB_00108e50;
    }
    lVar19 = (param_1[3] + (ulong)*(uint *)(param_1 + (ulong)uVar13 * 0x37f + 0x541)) - param_1[2];
    puVar21 = (undefined4 *)(param_1[(ulong)uVar13 * 0x37f + 0x1de] + (ulong)*puVar2 * 8);
    *puVar21 = (int)lVar19;
    puVar21[1] = (uint)((ulong)lVar19 >> 0x10) & 0xf0000 | 0x80;
    *puVar2 = *puVar2 + 1;
    select_mode(param_1,piVar1);
    iVar14 = _qce_sps_transfer(param_1,uVar23);
    piVar3 = (int *)((long)param_1 + 0x10a64);
    Hint_Prefetch(piVar3,2,0,1);
    do {
      if (*piVar3 != 1) goto LAB_00108f04;
      cVar5 = '\x01';
      bVar11 = (bool)ExclusiveMonitorPass(piVar3,0x10);
      if (bVar11) {
        *piVar3 = 0;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
LAB_00108f04:
    if (iVar14 == 0) {
      return 0;
    }
  }
  else {
    lVar19 = (*plVar4 - param_1[2]) + param_1[3];
    uVar6 = *(ushort *)(plVar4 + 0x1a);
    puVar21 = (undefined4 *)param_1[uVar23 * 0x37f + 0x1da];
    *puVar21 = (int)lVar19;
    puVar21[1] = (uint)uVar6 | (uint)((ulong)lVar19 >> 0x10) & 0xf0000 | 0xc000000;
    uVar20 = *puVar2 + 1;
    uVar18 = (ulong)uVar20;
    *puVar2 = uVar20;
    if (uVar20 < 0x200) {
      uVar6 = (ushort)param_2[1];
      goto joined_r0x00108ca8;
    }
LAB_00108e14:
    pcVar17 = "_qce_sps_add_cmd";
LAB_00108e50:
    _printk(&DAT_0010fd4b,pcVar17,uVar18,0x200);
    iVar14 = -0xc;
  }
  dma_unmap_page_attrs(*param_1,param_1[uVar23 * 0x37f + 0x550],(short)param_2[1],1,0);
  *(undefined4 *)(param_1 + uVar23 * 0x37f + 0x1d6) = 5;
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar7 = *piVar1;
    cVar5 = '\x01';
    bVar11 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar11) {
      *piVar1 = 0;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  DataMemoryBarrier(2,3);
joined_r0x00108e98:
  if (iVar7 == 0) {
    _printk(&DAT_00110c06,"qce_free_req_info",uVar23);
  }
  return iVar14;
}



//------------------------------------------------------------
// qce_enable_clk @ 00108f10 size=452
// signature: undefined qce_enable_clk(void)
// callers: [qce_open, qce_close]
//------------------------------------------------------------

int qce_enable_clk(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x10bf9) != '\0') {
    return 0;
  }
  lVar2 = *(long *)(param_1 + 0x58);
  if (lVar2 != 0) {
    iVar1 = clk_prepare(lVar2);
    if (iVar1 != 0) {
LAB_00109000:
      _printk(&DAT_00110d65,"qce_enable_clk");
      return iVar1;
    }
    iVar1 = clk_enable(lVar2);
    if (iVar1 != 0) {
      clk_unprepare(lVar2);
      goto LAB_00109000;
    }
  }
  if (*(char *)(param_1 + 0x43) != '\0') {
    return 0;
  }
  lVar2 = *(long *)(param_1 + 0x60);
  if (lVar2 != 0) {
    iVar1 = clk_prepare(lVar2);
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar2);
      if (iVar1 == 0) goto LAB_00108f9c;
      clk_unprepare(lVar2);
    }
    _printk(&DAT_001106e0,"qce_enable_clk");
    goto LAB_001090b8;
  }
LAB_00108f9c:
  lVar2 = *(long *)(param_1 + 0x68);
  if (lVar2 == 0) {
LAB_00108fbc:
    lVar2 = *(long *)(param_1 + 0x70);
    if (lVar2 == 0) {
      return 0;
    }
    iVar1 = clk_prepare(lVar2);
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar2);
      if (iVar1 == 0) {
        return 0;
      }
      clk_unprepare(lVar2);
    }
    _printk(&DAT_00110377,"qce_enable_clk");
    lVar2 = *(long *)(param_1 + 0x68);
    if (lVar2 != 0) {
      clk_disable(lVar2);
      clk_unprepare(lVar2);
    }
  }
  else {
    iVar1 = clk_prepare(lVar2);
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar2);
      if (iVar1 == 0) goto LAB_00108fbc;
      clk_unprepare(lVar2);
    }
    _printk(&DAT_0010ffc4,"qce_enable_clk");
  }
  lVar2 = *(long *)(param_1 + 0x60);
  if (lVar2 != 0) {
    clk_disable(lVar2);
    clk_unprepare(lVar2);
  }
LAB_001090b8:
  lVar2 = *(long *)(param_1 + 0x58);
  if (lVar2 == 0) {
    return iVar1;
  }
  clk_disable(lVar2);
  clk_unprepare(lVar2);
  return iVar1;
}



//------------------------------------------------------------
// qce_disable_clk @ 001090d8 size=152
// signature: undefined qce_disable_clk(void)
// callers: [qce_open, qce_close]
//------------------------------------------------------------

undefined8 qce_disable_clk(long param_1)

{
  long lVar1;
  
  if (*(char *)(param_1 + 0x10bf9) == '\0') {
    lVar1 = *(long *)(param_1 + 0x70);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x68);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x60);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x58);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
  }
  return 0;
}



//------------------------------------------------------------
// qce_open @ 00109174 size=3144
// signature: undefined qce_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * qce_open(long param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  long *plVar11;
  int *piVar12;
  undefined4 *puVar13;
  ulong uVar14;
  undefined *puVar15;
  
  plVar8 = (long *)kmalloc_large(0x10c00,0xdc0);
  if (plVar8 == (long *)0x0) {
    *param_2 = -0xc;
    _printk(&DAT_0011046d,"qce_open",0xfffffff4);
    return (long *)0x0;
  }
  *plVar8 = param_1 + 0x10;
  mutex_lock(qce_iomap_mutex);
  if (*(long *)(param_1 + 0x2f8) == 0) {
    *param_2 = -0x16;
    _printk(&DAT_00110497,"qce_open");
    goto LAB_00109bf8;
  }
  puVar1 = (undefined8 *)(param_1 + 0x2f8);
  lVar9 = of_find_property(*(long *)(param_1 + 0x2f8),"qcom,ce-hw-shared",0);
  uVar10 = *puVar1;
  *(uint *)((long)plVar8 + 0x3c) = (uint)(lVar9 != 0);
  lVar9 = of_find_property(uVar10,"qcom,ce-hw-key",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x41) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,use-sw-aes-cbc-ecb-ctr-algo",0);
  uVar10 = *puVar1;
  *(bool *)(plVar8 + 0x10) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,use-sw-aead-algo",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x81) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,use-sw-aes-xts-algo",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x82) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,use-sw-ahash-algo",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x83) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,use-sw-hmac-algo",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x84) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,use-sw-aes-ccm-algo",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x85) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,clk-mgmt-sus-res",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x42) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,support-core-clk-only",0);
  uVar10 = *puVar1;
  *(bool *)((long)plVar8 + 0x43) = lVar9 != 0;
  lVar9 = of_find_property(uVar10,"qcom,request-bw-before-clk",0);
  puVar2 = (undefined8 *)((long)plVar8 + 0x134);
  uVar10 = *puVar1;
  *(undefined4 *)((long)plVar8 + 0x154) = 0;
  *puVar2 = 0;
  *(undefined8 *)((long)plVar8 + 0x13c) = 0;
  *(undefined8 *)((long)plVar8 + 0x144) = 0;
  *(undefined8 *)((long)plVar8 + 0x14c) = 0;
  *(bool *)((long)plVar8 + 0x44) = lVar9 != 0;
  *(undefined1 *)((long)plVar8 + 0x10bfa) = 1;
  iVar5 = of_property_read_variable_u32_array(uVar10,"qcom,bam-pipe-pair",puVar2,1,0);
  if (iVar5 < 0) {
    _printk(&DAT_00110a30,"__qce_get_device_tree_data");
    *(undefined1 *)((long)plVar8 + 0x10bfa) = 0;
    *(undefined4 *)puVar2 = 0xffffffff;
  }
  lVar9 = of_find_property(*puVar1,"qcom,offload-ops-support",0);
  if (lVar9 != 0) {
    uVar10 = *puVar1;
    *(undefined1 *)((long)plVar8 + 0x10bfb) = 1;
    iVar5 = of_property_read_variable_u32_array
                      (uVar10,"qcom,bam-pipe-offload-cpb-hlos",(undefined4 *)((long)plVar8 + 0x154),
                       1,0);
    if (iVar5 < 0) {
      _printk(&DAT_00110010,"__qce_get_device_tree_data");
      *(undefined4 *)((long)plVar8 + 0x154) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-hlos",plVar8 + 0x27,1,0);
    if (iVar5 < 0) {
      _printk(&DAT_0010f9bc,"__qce_get_device_tree_data");
      *(undefined4 *)(plVar8 + 0x27) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-hlos-1",
                       (undefined4 *)((long)plVar8 + 0x13c),1,0);
    if (iVar5 < 0) {
      _printk(&DAT_001109a1,"__qce_get_device_tree_data");
      *(undefined4 *)((long)plVar8 + 0x13c) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-cpb",plVar8 + 0x28,1,0);
    if (iVar5 < 0) {
      _printk(&DAT_001103d1,"__qce_get_device_tree_data");
      *(undefined4 *)(plVar8 + 0x28) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-cpb-1",
                       (undefined4 *)((long)plVar8 + 0x144),1,0);
    if (iVar5 < 0) {
      _printk(&DAT_00110c42,"__qce_get_device_tree_data");
      *(undefined4 *)((long)plVar8 + 0x144) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-cpb-2",plVar8 + 0x29,1,0);
    if (iVar5 < 0) {
      _printk(&DAT_00110519,"__qce_get_device_tree_data");
      *(undefined4 *)(plVar8 + 0x29) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-cpb-3",
                       (undefined4 *)((long)plVar8 + 0x14c),1,0);
    if (iVar5 < 0) {
      _printk(&DAT_0010fb1f,"__qce_get_device_tree_data");
      *(undefined4 *)((long)plVar8 + 0x14c) = 0xffffffff;
    }
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,bam-pipe-offload-hlos-cpb-4",plVar8 + 0x2a,1,0);
    if (iVar5 < 0) {
      _printk(&DAT_0010fa14,"__qce_get_device_tree_data");
      *(undefined4 *)(plVar8 + 0x2a) = 0xffffffff;
    }
  }
  iVar5 = of_property_read_variable_u32_array(*puVar1,"qcom,ce-device",plVar8 + 0x25,1,0);
  if (iVar5 < 0) {
    puVar15 = &DAT_00110713;
LAB_001098dc:
    _printk(puVar15,"__qce_get_device_tree_data");
    iVar5 = -0x16;
  }
  else {
    iVar5 = of_property_read_variable_u32_array
                      (*puVar1,"qcom,ce-hw-instance",(long)plVar8 + 300,1,0);
    if (iVar5 < 0) {
      puVar15 = &DAT_00110552;
      goto LAB_001098dc;
    }
    iVar5 = of_property_read_variable_u32_array(*puVar1,"qcom,bam-ee",plVar8 + 0x26,1,0);
    if (iVar5 < 0) {
      _printk(&DAT_0010fb58,"__qce_get_device_tree_data");
      *(undefined4 *)(plVar8 + 0x26) = 1;
    }
    puVar3 = (uint *)((long)plVar8 + 0x7c);
    iVar5 = of_property_read_variable_u32_array(*puVar1,"qcom,ce-opp-freq",puVar3,1,0);
    if (iVar5 < 0) {
      _printk(&DAT_001101cd,"__qce_get_device_tree_data");
      *puVar3 = 100000000;
    }
    lVar9 = of_find_property(*puVar1,"qcom,smmu-s1-enable",0);
    if (lVar9 != 0) {
      *(undefined1 *)(plVar8 + 0x217f) = 1;
    }
    lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,no-clock-support",0);
    *(bool *)((long)plVar8 + 0x10bf9) = lVar9 != 0;
    *(uint *)(plVar8 + 0x2b) = *(int *)((long)plVar8 + 0x134) << 1 | 1;
    *(int *)(plVar8 + 0x30) = (int)plVar8[0x27] << 1;
    *(int *)((long)plVar8 + 0x17c) = *(int *)((long)plVar8 + 0x134) << 1;
    *(uint *)(plVar8 + 0x2c) = *(int *)((long)plVar8 + 0x13c) << 1 | 1;
    *(int *)((long)plVar8 + 0x184) = *(int *)((long)plVar8 + 0x13c) << 1;
    *(int *)(plVar8 + 0x31) = (int)plVar8[0x28] << 1;
    *(uint *)((long)plVar8 + 0x15c) = (int)plVar8[0x27] << 1 | 1;
    *(uint *)((long)plVar8 + 0x164) = (int)plVar8[0x28] << 1 | 1;
    *(int *)((long)plVar8 + 0x18c) = *(int *)((long)plVar8 + 0x144) << 1;
    *(uint *)(plVar8 + 0x2d) = *(int *)((long)plVar8 + 0x144) << 1 | 1;
    *(int *)(plVar8 + 0x32) = (int)plVar8[0x29] << 1;
    *(int *)((long)plVar8 + 0x194) = *(int *)((long)plVar8 + 0x14c) << 1;
    *(uint *)(plVar8 + 0x2e) = *(int *)((long)plVar8 + 0x14c) << 1 | 1;
    *(uint *)((long)plVar8 + 0x16c) = (int)plVar8[0x29] << 1 | 1;
    *(int *)(plVar8 + 0x33) = (int)plVar8[0x2a] << 1;
    *(uint *)((long)plVar8 + 0x174) = (int)plVar8[0x2a] << 1 | 1;
    *(int *)((long)plVar8 + 0x19c) = *(int *)((long)plVar8 + 0x154) << 1;
    *(uint *)(plVar8 + 0x2f) = *(int *)((long)plVar8 + 0x154) << 1 | 1;
    plVar11 = (long *)platform_get_resource_byname(param_1,0x200,"crypto-base");
    if (plVar11 == (long *)0x0) {
      _printk(&DAT_00110cfc,"__qce_get_device_tree_data");
LAB_00109984:
      iVar5 = -0x13;
    }
    else {
      *(int *)(plVar8 + 10) = (int)*plVar11;
      uVar10 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar10 = 0x68000000000f13;
      }
      lVar9 = ioremap_prot(*plVar11,(plVar11[1] - *plVar11) + 1,uVar10);
      plVar8[9] = lVar9;
      if (lVar9 != 0) {
        piVar12 = (int *)platform_get_resource_byname(param_1,0x200,"crypto-bam-base");
        if (piVar12 != (int *)0x0) {
          *(int *)((long)plVar8 + 0x34) = (int)*(undefined8 *)piVar12;
          *(int *)(plVar8 + 7) = (piVar12[2] - *piVar12) + 1;
          uVar6 = platform_get_irq(param_1,0);
          lVar9 = plVar8[0x217f];
          *(undefined4 *)(plVar8 + 0x23) = uVar6;
          *param_2 = 0;
          if ((char)lVar9 != '\0') {
            lVar9 = *plVar8;
            puVar13 = *(undefined4 **)(lVar9 + 0x2b8);
            if (puVar13 == (undefined4 *)0x0) {
              puVar13 = (undefined4 *)devm_kmalloc(lVar9,0x10,0xdc0);
              *(undefined4 **)(lVar9 + 0x2b8) = puVar13;
              if (puVar13 == (undefined4 *)0x0) {
                iVar5 = -5;
                goto LAB_00109988;
              }
            }
            *puVar13 = 0xffffffff;
            if (*(long *)(lVar9 + 0x2b8) != 0) {
              *(undefined8 *)(*(long *)(lVar9 + 0x2b8) + 8) = 0xffffffffffffffff;
            }
          }
          *(undefined4 *)(plVar8 + 0x1d5) = 0;
          *(undefined4 *)(plVar8 + 0x554) = 0;
          *(undefined4 *)(plVar8 + 0x8d3) = 0;
          *(undefined4 *)(plVar8 + 0xc52) = 0;
          *(undefined4 *)(plVar8 + 0xfd1) = 0;
          *(undefined4 *)(plVar8 + 0x1350) = 0;
          *(undefined4 *)(plVar8 + 0x16cf) = 0;
          *(undefined4 *)(plVar8 + 0x1a4e) = 0;
          *(undefined4 *)(plVar8 + 0x1dcd) = 0;
          *(undefined4 *)(plVar8 + 0x214c) = 0;
          *(undefined4 *)(plVar8 + 4) = 0x5a000;
          lVar9 = dma_alloc_attrs(*plVar8,0x5a000,plVar8 + 3,0xcc0,0);
          plVar8[2] = lVar9;
          if (lVar9 == 0) {
            *param_2 = -0xc;
            _printk(&DAT_0010fc10,"qce_open");
          }
          else {
            *(undefined4 *)(plVar8 + 6) = 0x12000;
            lVar9 = kmalloc_large(0x12000,0xdc0);
            plVar8[5] = lVar9;
            if (lVar9 != 0) {
              lVar9 = kmalloc_trace(_kfree,0xdc0,0x40);
              plVar8[0x217d] = lVar9;
              if (lVar9 != 0) {
                if (*(char *)((long)plVar8 + 0x10bf9) == '\0') {
                  uVar14 = clk_get(*plVar8,"core_clk_src");
                  plVar8[0xb] = uVar14;
                  if (uVar14 < 0xfffffffffffff001) {
                    if ((*(char *)((long)plVar8 + 0x44) == '\0') &&
                       (uVar7 = clk_set_rate(uVar14,*puVar3), uVar7 != 0)) {
                      uVar14 = (ulong)uVar7;
                      _printk(&DAT_00110060,"__qce_init_clk",(ulong)*puVar3 / 1000000);
                      lVar9 = plVar8[0xb];
                    }
                    else {
                      if (*(char *)((long)plVar8 + 0x43) != '\0') goto LAB_0010984c;
LAB_00109ad8:
                      uVar14 = clk_get(*plVar8,"core_clk");
                      plVar8[0xc] = uVar14;
                      if (uVar14 < 0xfffffffffffff001) {
                        uVar14 = clk_get(*plVar8,"iface_clk");
                        plVar8[0xd] = uVar14;
                        if (uVar14 < 0xfffffffffffff001) {
                          uVar14 = clk_get(*plVar8,"bus_clk");
                          plVar8[0xe] = uVar14;
                          if (uVar14 < 0xfffffffffffff001) goto LAB_00109b2c;
                          _printk(&DAT_00110d34,"__qce_init_clk");
                          if (plVar8[0xd] == 0) {
                            lVar9 = plVar8[0xc];
                          }
                          else {
                            clk_put();
                            lVar9 = plVar8[0xc];
                          }
                        }
                        else {
                          _printk(&DAT_001107eb,"__qce_init_clk");
                          lVar9 = plVar8[0xc];
                        }
                        if (lVar9 == 0) {
                          lVar9 = plVar8[0xb];
                        }
                        else {
                          clk_put();
                          lVar9 = plVar8[0xb];
                        }
                      }
                      else {
                        _printk(&DAT_0011021c,"__qce_init_clk");
                        lVar9 = plVar8[0xb];
                      }
                    }
                    if (lVar9 != 0) {
                      clk_put();
                    }
                    _printk(&DAT_00110244,"__qce_init_clk",uVar14 & 0xffffffff);
                  }
                  else {
                    if (*(char *)((long)plVar8 + 0x43) == '\0') {
                      _printk(&DAT_0010f931,"__qce_init_clk");
                      plVar8[0xb] = 0;
                      if (*(char *)((long)plVar8 + 0x43) == '\0') goto LAB_00109ad8;
LAB_0010984c:
                      plVar8[0xd] = 0;
                      plVar8[0xe] = 0;
                      plVar8[0xc] = 0;
                      goto LAB_00109b2c;
                    }
                    plVar8[0xb] = 0;
                    _printk(&DAT_0010fdb0,"__qce_init_clk");
                  }
                  *param_2 = (int)uVar14;
                  if ((int)uVar14 != 0) goto LAB_00109bc0;
                }
                else {
LAB_00109b2c:
                  *param_2 = 0;
                }
                iVar5 = qce_enable_clk(plVar8);
                *param_2 = iVar5;
                if (iVar5 == 0) {
                  iVar5 = _probe_ce_engine(plVar8);
                  if (iVar5 == 0) {
                    *param_2 = 0;
                    qce_init_ce_cfg_val(plVar8);
                    iVar5 = qce_sps_init(plVar8);
                    *param_2 = iVar5;
                    if (iVar5 == 0) {
                      qce_setup_ce_sps_data(plVar8);
                      qce_disable_clk(plVar8);
                      setup_dummy_req(plVar8);
                      *(undefined4 *)(plVar8 + 0x214d) = 0;
                      *(undefined4 *)(plVar8 + 0x2178) = 0;
                      init_timer_key(plVar8 + 0x214e,qce_multireq_timeout,0,0,0);
                      lVar9 = _jiffies;
                      *(undefined4 *)((long)plVar8 + 0x10bc4) = 0;
                      *(undefined4 *)((long)plVar8 + 0x10a64) = 0;
                      *(int *)(plVar8 + 0x2179) = qce_open_pcedev_no;
                      plVar8[0x2150] = lVar9 + 5;
                      qce_open_pcedev_no = qce_open_pcedev_no + 1;
                      mutex_unlock(qce_iomap_mutex);
                      return plVar8;
                    }
                  }
                  else {
                    *param_2 = -6;
                  }
                  qce_disable_clk(plVar8);
                  cVar4 = *(char *)((long)plVar8 + 0x10bf9);
                }
                else {
                  cVar4 = *(char *)((long)plVar8 + 0x10bf9);
                }
                if (cVar4 == '\0') {
                  if (plVar8[0xe] != 0) {
                    clk_put();
                  }
                  if (plVar8[0xd] != 0) {
                    clk_put();
                  }
                  if (plVar8[0xc] != 0) {
                    clk_put();
                  }
                  if (plVar8[0xb] != 0) {
                    clk_put();
                  }
                }
              }
            }
LAB_00109bc0:
            kfree(plVar8[0x217d]);
            kfree(plVar8[5]);
            if (plVar8[2] != 0) {
              dma_free_attrs(*plVar8,(long)(int)plVar8[4],plVar8[2],plVar8[3],0);
            }
          }
          if (plVar8[9] != 0) {
            iounmap();
          }
          goto LAB_00109bf8;
        }
        _printk(&DAT_00110ed6,"__qce_get_device_tree_data");
        if (plVar8[9] != 0) {
          iounmap();
        }
        goto LAB_00109984;
      }
      _printk(&DAT_00110eab,"__qce_get_device_tree_data");
      iVar5 = -0xc;
    }
  }
LAB_00109988:
  *param_2 = iVar5;
LAB_00109bf8:
  mutex_unlock(qce_iomap_mutex);
  kfree(plVar8);
  return (long *)0x0;
}



//------------------------------------------------------------
// _probe_ce_engine @ 00109dbc size=248
// signature: undefined _probe_ce_engine(void)
// callers: [qce_open]
//------------------------------------------------------------

undefined8 _probe_ce_engine(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  uVar4 = readl_relaxed(param_1[9] + 0x1a000);
  DataSynchronizationBarrier(3,3,0);
  uVar6 = uVar4 >> 0x18 & 0xff;
  uVar2 = (uint)uVar4 >> 0x10 & 0xff;
  uVar1 = (uint)uVar4 & 0xffff;
  if ((int)uVar6 == 5) {
    *(bool *)(param_1 + 0xf) = 2 < uVar2;
    if ((uVar2 < 4) && (uVar2 != 3 || (uVar4 & 0xffff) == 0)) {
      *(undefined1 *)((long)param_1 + 0x79) = 0;
    }
    else {
      *(undefined1 *)((long)param_1 + 0x79) = 1;
    }
    *(uint *)((long)param_1 + 0x1ac) = uVar2;
    *(undefined4 *)(param_1 + 0x36) = 5;
    uVar3 = readl_relaxed(param_1[9] + 0x1a108);
    *(undefined4 *)(param_1 + 0x11) = uVar3;
    _dev_info(*param_1,"QTI Crypto %d.%d.%d device found @0x%x\n",5,uVar2,uVar1,
              *(undefined4 *)(param_1 + 10));
    uVar5 = 0;
    *(undefined4 *)(param_1 + 0x35) = 0x40;
  }
  else {
    _printk(&DAT_001109d0,"_probe_ce_engine",*(undefined4 *)(param_1 + 10),uVar6,uVar2,uVar1);
    uVar5 = 0xfffffffb;
  }
  return uVar5;
}



//------------------------------------------------------------
// qce_init_ce_cfg_val @ 00109eb4 size=208
// signature: undefined qce_init_ce_cfg_val(void)
// callers: [qce_open]
//------------------------------------------------------------

void qce_init_ce_cfg_val(long param_1)

{
  uint uVar1;
  
  uVar1 = (*(uint *)(param_1 + 0x1a8) >> 3) * 0x20000 - 0x1fff2 | *(int *)(param_1 + 0x134) << 5;
  *(uint *)(param_1 + 0x8c) = uVar1;
  *(undefined8 *)(param_1 + 0xa4) = 0xd2000000c2;
  *(undefined8 *)(param_1 + 0xac) = 0x9200000082;
  *(undefined8 *)(param_1 + 0x94) = 0x5200000042;
  *(undefined8 *)(param_1 + 0x9c) = 0x1200000002;
  *(undefined8 *)(param_1 + 0xb4) = 0x211200002102;
  *(undefined8 *)(param_1 + 0xbc) = 0x100000041;
  *(undefined8 *)(param_1 + 0xc4) = 0x900000049;
  *(undefined8 *)(param_1 + 0xcc) = 0x500000004;
  *(uint *)(param_1 + 0x90) = uVar1 | 0x200;
  *(undefined4 *)(param_1 + 0xd4) = 0x31e42;
  *(undefined4 *)(param_1 + 0xd8) = 0x31e52;
  *(undefined8 *)(param_1 + 0xdc) = 0x20100000001;
  *(undefined8 *)(param_1 + 0xe4) = 0x24100000041;
  *(undefined4 *)(param_1 + 0xf4) = 0x30041;
  *(undefined4 *)(param_1 + 0xf8) = 0x30241;
  *(undefined4 *)(param_1 + 0xec) = 0x430002;
  *(undefined4 *)(param_1 + 0xf0) = 0x430012;
  *(undefined4 *)(param_1 + 0xfc) = 0x30003;
  *(undefined4 *)(param_1 + 0x100) = 0x30004;
  *(undefined8 *)(param_1 + 0x104) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x10c) = 0xffffffffffffffff;
  return;
}



//------------------------------------------------------------
// qce_sps_init @ 00109f84 size=988
// signature: undefined qce_sps_init(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qce_sps_init(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined **ppuVar7;
  undefined *puVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  undefined8 local_e8;
  ulong local_e0;
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
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar13 = sp_el0;
  local_58 = *(long *)(lVar13 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = 0;
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
  local_e0 = 0;
  mutex_lock(bam_register_lock);
  ppuVar7 = &qce50_bam_list;
  do {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &qce50_bam_list) goto LAB_0010a04c;
  } while (*(int *)((long)ppuVar7 + 0x1c) != *(int *)((long)param_1 + 0x34));
  if (ppuVar7 != (undefined **)0x0) {
    *(int *)(ppuVar7 + 3) = *(int *)(ppuVar7 + 3) + 1;
    param_1[0x34] = ppuVar7[2];
    *(undefined4 *)((long)param_1 + 0x11c) = *(undefined4 *)((long)ppuVar7 + 0x1c);
    puVar8 = ppuVar7[4];
    param_1[1] = ppuVar7;
    param_1[0x24] = puVar8;
    *(undefined1 *)(param_1 + 8) = *(undefined1 *)(ppuVar7 + 5);
LAB_0010a168:
    mutex_unlock(bam_register_lock);
    if ((*(char *)((long)param_1 + 0x10bfa) == '\0') || (*(int *)((long)param_1 + 0x134) == -1)) {
LAB_0010a1cc:
      lVar13 = 0x4e;
      lVar12 = 0x270;
      do {
        if (*(char *)((long)param_1 + 0x10bfb) == '\0') break;
        if (*(int *)((long)param_1 + lVar13 * 4) != -1) {
          uVar11 = lVar13 - 0x4d;
          iVar5 = qce_sps_init_ep_conn(param_1,(long)param_1 + lVar12,uVar11 & 0xffffffff,1);
          if (iVar5 != 0) goto LAB_0010a278;
          iVar5 = qce_sps_init_ep_conn(param_1,(long)param_1 + lVar12 + 0x678,uVar11 & 0xffffffff,0)
          ;
          if (iVar5 != 0) {
            puVar6 = (undefined8 *)((long)param_1 + lVar12);
            goto LAB_0010a23c;
          }
        }
        lVar13 = lVar13 + 1;
        lVar12 = lVar12 + 0xb8;
      } while (lVar13 != 0x56);
      _printk(&DAT_0010f96a,"qce_sps_init",*(undefined4 *)((long)param_1 + 0x11c),
              *(undefined4 *)(param_1 + 0x23));
      iVar5 = 0;
    }
    else {
      puVar6 = param_1 + 0x37;
      iVar5 = qce_sps_init_ep_conn(param_1,puVar6,0,1);
      if (iVar5 == 0) {
        iVar5 = qce_sps_init_ep_conn(param_1,param_1 + 0x106,0,0);
        if (iVar5 == 0) goto LAB_0010a1cc;
        uVar11 = 0;
LAB_0010a23c:
        uVar9 = *puVar6;
        uVar11 = uVar11 & 0xffffffff;
        sps_disconnect(uVar9);
        dma_free_attrs(*param_1,*(undefined4 *)(param_1 + uVar11 * 0x17 + 0x42),
                       param_1[uVar11 * 0x17 + 0x3f],param_1[uVar11 * 0x17 + 0x40],0);
        sps_free_endpoint(uVar9);
      }
LAB_0010a278:
      qce_sps_release_bam(param_1);
    }
    goto LAB_0010a2d4;
  }
LAB_0010a04c:
  puVar6 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x30);
  cVar3 = arm64_use_ng_mappings;
  if (puVar6 == (undefined8 *)0x0) {
LAB_0010a2c4:
    iVar5 = -0xc;
  }
  else {
    uVar1 = *(undefined4 *)((long)param_1 + 0x34);
    uVar2 = *(undefined4 *)(param_1 + 7);
    *(undefined4 *)(puVar6 + 3) = 1;
    *(undefined4 *)((long)puVar6 + 0x1c) = uVar1;
    uVar9 = 0x68000000000713;
    if (cVar3 != '\0') {
      uVar9 = 0x68000000000f13;
    }
    lVar13 = ioremap_prot(uVar1,uVar2,uVar9);
    puVar6[4] = lVar13;
    if (lVar13 == 0) {
      kfree(puVar6);
      _printk(&DAT_0010fb97,"qce_sps_get_bam");
      goto LAB_0010a2c4;
    }
    param_1[0x24] = lVar13;
    *(undefined4 *)((long)param_1 + 0x11c) = uVar1;
    puVar10 = puVar6 + 2;
    *puVar10 = 0;
    uVar4 = readl_relaxed(lVar13 + 0x7c);
    *(byte *)(puVar6 + 5) = (byte)(uVar4 >> 0x1b) & 1;
    if ((uVar4 >> 0x1b & 1) == 0) {
      _printk(&DAT_00110877,"qce_sps_get_bam",uVar4);
      *(undefined1 *)(param_1 + 0xf) = 0;
    }
    local_e0 = (ulong)*(uint *)((long)param_1 + 0x11c);
    local_d8 = param_1[0x24];
    *(byte *)(param_1 + 8) = (byte)((uVar4 & 0x8000000) >> 0x1b);
    local_a8 = CONCAT44(0x10,(undefined4)local_a8);
    local_c8 = CONCAT44(0x40,(undefined4)local_c8);
    uStack_d0 = CONCAT44(*(undefined4 *)(param_1 + 0x23),(undefined4)uStack_d0);
    if ((uVar4 & 0x8000000) == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = (uint)(*(int *)((long)param_1 + 0x3c) != 0);
    }
    local_80 = CONCAT44(local_80._4_4_,uVar4);
    local_78 = CONCAT44(2,*(undefined4 *)(param_1 + 0x26));
    local_e8 = CONCAT44(local_e8._4_4_,0x400);
    iVar5 = sps_register_bam_device(&local_e8,puVar10);
    if (iVar5 == 0) {
      param_1[1] = puVar6;
      puVar8 = PTR_qce50_bam_list_00111348;
      uVar11 = __list_add_valid(puVar6,PTR_qce50_bam_list_00111348,&qce50_bam_list);
      if ((uVar11 & 1) != 0) {
        PTR_qce50_bam_list_00111348 = (undefined *)puVar6;
        *puVar6 = &qce50_bam_list;
        puVar6[1] = puVar8;
        *(undefined8 **)puVar8 = puVar6;
      }
      param_1[0x34] = *puVar10;
      goto LAB_0010a168;
    }
    _printk(&DAT_00110095,"qce_sps_get_bam",iVar5);
    iounmap(puVar6[4]);
    kfree(puVar6);
    iVar5 = -5;
  }
  mutex_unlock(bam_register_lock);
LAB_0010a2d4:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qce_setup_ce_sps_data @ 0010a360 size=1640
// signature: undefined qce_setup_ce_sps_data(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qce_setup_ce_sps_data(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  int iVar13;
  uint *puVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  uint *local_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  lVar16 = 0;
  uVar15 = 0;
  lVar18 = 0x25c0;
  lVar11 = *(long *)(param_1 + 0x28);
  iVar3 = *(int *)(param_1 + 0x30);
  lVar17 = lVar11 << 8;
  puVar9 = (uint *)((*(long *)(param_1 + 0x10) + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  do {
    lVar2 = param_1 + lVar16;
    *(long *)(lVar2 + 0xed0) = lVar11;
    lVar12 = _kimage_voffset;
    lVar1 = _memstart_addr;
    uVar10 = (lVar17 >> 8) + 0x8000000000;
    *(long *)(lVar2 + 0xef0) = lVar11 + 0x1000;
    lVar1 = lVar1 + uVar10;
    if (uVar10 >> 0x26 != 0) {
      lVar1 = (lVar17 >> 8) - lVar12;
    }
    *(long *)(lVar2 + 0xec8) = lVar1;
    lVar12 = lVar17 + 0x100000 >> 8;
    uVar10 = lVar12 + 0x8000000000;
    lVar1 = _memstart_addr + uVar10;
    if (uVar10 >> 0x26 != 0) {
      lVar1 = lVar12 - _kimage_voffset;
    }
    cVar6 = *(char *)(param_1 + 0x40);
    *(long *)(lVar2 + 0xee8) = lVar1;
    if (cVar6 != '\0') {
      local_70 = (uint *)((long)puVar9 + (long)*(int *)(param_1 + 0x1a8) + -1 &
                         -(long)*(int *)(param_1 + 0x1a8));
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,1);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,1);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,1);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,3,1);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,0);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,0);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,0);
      _setup_cipher_aes_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,3,0);
      _setup_cipher_des_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,1);
      _setup_cipher_des_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,0);
      _setup_cipher_des_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,1);
      _setup_cipher_des_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,0);
      _setup_auth_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,0);
      _setup_auth_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,0);
      _setup_auth_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,0);
      _setup_auth_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,3,0);
      _setup_auth_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,4,1);
      _setup_auth_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,4,0);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,8,1);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,0x18,1);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,0x10,1);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,0x20,1);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0,8,0);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1,0x18,0);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,0x10,0);
      _setup_aead_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,2,0x20,0);
      uVar8 = *(uint *)(param_1 + 0x1a8);
      iVar5 = *(int *)(param_1 + 0x50);
      local_70 = (uint *)((long)local_70 + (long)(int)uVar8 + -1 & -(long)(int)uVar8);
      *(uint **)(lVar2 + 0x24f8) = local_70;
      *local_70 = iVar5 + 0x1a110U & 0xffffff;
      local_70[1] = uVar8;
      local_70[2] = 0xffffffff;
      local_70[3] = 0;
      iVar5 = *(int *)(param_1 + 0x50);
      uVar8 = *(uint *)(param_1 + 0x9c);
      local_70[6] = 0xffffffff;
      local_70[7] = 0;
      local_70[4] = iVar5 + 0x1a200U & 0xffffff;
      local_70[5] = uVar8;
      iVar5 = *(int *)(param_1 + 0x50);
      local_70[9] = 0;
      local_70[10] = 0xffffffff;
      local_70[0xb] = 0;
      local_70[8] = iVar5 + 0x1a204U & 0xffffff;
      iVar5 = *(int *)(param_1 + 0x50);
      local_70[0xd] = 0;
      local_70[0xe] = 0xffffffff;
      local_70[0xf] = 0;
      local_70[0xc] = iVar5 + 0x1a208U & 0xffffff;
      iVar5 = *(int *)(param_1 + 0x50);
      local_70[0x11] = 0;
      local_70[0x12] = 0xffffffff;
      local_70[0x13] = 0;
      local_70[0x10] = iVar5 + 0x1a300U & 0xffffff;
      iVar5 = *(int *)(param_1 + 0x50);
      local_70[0x15] = 0;
      local_70[0x16] = 0xffffffff;
      local_70[0x17] = 0;
      local_70[0x14] = iVar5 + 0x1a304U & 0xffffff;
      iVar5 = *(int *)(param_1 + 0x50);
      local_70[0x19] = 0;
      local_70[0x1a] = 0xffffffff;
      local_70[0x1b] = 0;
      local_70[0x18] = iVar5 + 0x1a308U & 0xffffff;
      iVar5 = *(int *)(param_1 + 0x50);
      local_70[0x1d] = 7;
      local_70[0x1e] = 0xffffffff;
      local_70[0x1f] = 0;
      local_70[0x1c] = iVar5 + 0x1a120U & 0xffffff;
      if (param_1 + lVar18 != 0) {
        *(uint **)(lVar2 + 0x25c0) = local_70 + 0x1c;
      }
      lVar1 = param_1 + lVar16;
      local_70 = local_70 + 0x20;
      *(undefined8 *)(lVar1 + 0x25c8) = 0x80;
      _setup_aead_ccm_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1);
      _setup_aead_ccm_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0);
      _setup_f8_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0);
      _setup_f8_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1);
      _setup_f9_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,0);
      _setup_f9_cmdlistptrs(param_1,uVar15 & 0xffffffff,&local_70,1);
      iVar5 = *(int *)(param_1 + 0x50);
      puVar14 = (uint *)((long)local_70 + (long)*(int *)(param_1 + 0x1a8) + -1 &
                        -(long)*(int *)(param_1 + 0x1a8));
      puVar9 = puVar14 + 4;
      *(uint **)(lVar1 + 0x2930) = puVar14;
      *puVar14 = iVar5 + 0x1a400U & 0xffffff;
      puVar14[3] = 0;
      puVar14[1] = 0xe01ef;
      puVar14[2] = 0xffffffff;
      *(long *)(lVar1 + 0x2a00) = (long)puVar9 - (long)local_70;
    }
    iVar7 = *(int *)(param_1 + 0x1a8);
    uVar15 = uVar15 + 1;
    iVar5 = *(int *)(param_1 + 0x18);
    lVar17 = lVar17 + 0x200000;
    iVar4 = *(int *)(param_1 + 0x10);
    uVar10 = (long)puVar9 + (long)iVar7 + -1 & -(long)iVar7;
    iVar13 = (int)(uVar10 + 0x80);
    *(int *)(lVar2 + 0x2a0c) = iVar13;
    lVar16 = lVar16 + 0x1bf8;
    *(ulong *)(lVar2 + 0x2a28) = uVar10 + 0x80;
    *(int *)(lVar2 + 0x2a08) = (int)uVar10;
    lVar18 = lVar18 + 0x1bf8;
    *(ulong *)(lVar2 + 0x2a20) = uVar10;
    puVar9 = (uint *)(uVar10 + 0x100 + (long)(iVar7 << 1));
    lVar11 = lVar11 + 0x2000;
    *(int *)(lVar2 + 0x2a10) = ((int)uVar10 + iVar5) - iVar4;
    *(int *)(lVar2 + 0x2a14) = (iVar5 + iVar13) - iVar4;
    *(int *)(lVar2 + 0x2a18) = (int)(uVar10 + 0x100);
  } while (uVar15 != 9);
  local_70 = puVar9;
  if (((long)*(int *)(param_1 + 0x20) < (long)puVar9 - *(long *)(param_1 + 0x10)) ||
     (iVar3 + -0x12000 < 0)) {
                    /* WARNING: Subroutine does not return */
    panic("qce50: Not enough coherent memory. Allocate %x , need %lx\n");
  }
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// setup_dummy_req @ 0010a9c8 size=172
// signature: undefined setup_dummy_req(void)
// callers: [qce_open]
//------------------------------------------------------------

void setup_dummy_req(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  
  uVar5 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._56_8_;
  uVar4 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._48_8_;
  uVar2 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._40_8_;
  lVar1 = param_1 + 0x10b18;
  pcVar6 = *(char **)(param_1 + 0x10be8);
  *(undefined8 *)(pcVar6 + 0x20) = s_abcdbcdecdefdefgefghfghighijhijk_00110408._32_8_;
  *(undefined8 *)(pcVar6 + 0x28) = uVar2;
  uVar3 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._8_8_;
  uVar2 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._0_8_;
  *(undefined8 *)(pcVar6 + 0x30) = uVar4;
  *(undefined8 *)(pcVar6 + 0x38) = uVar5;
  uVar5 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._24_8_;
  uVar4 = s_abcdbcdecdefdefgefghfghighijhijk_00110408._16_8_;
  *(undefined8 *)pcVar6 = uVar2;
  *(undefined8 *)(pcVar6 + 8) = uVar3;
  *(undefined8 *)(pcVar6 + 0x10) = uVar4;
  *(undefined8 *)(pcVar6 + 0x18) = uVar5;
  sg_init_one(lVar1,*(undefined8 *)(param_1 + 0x10be8),0x40);
  *(undefined4 *)(param_1 + 0x10ac8) = 0;
  *(long *)(param_1 + 0x10ad8) = lVar1;
  *(undefined8 *)(param_1 + 0x10ae0) = 0;
  *(code **)(param_1 + 0x10ac0) = qce_dummy_complete;
  *(undefined2 *)(param_1 + 0x10afc) = 0x101;
  *(undefined4 *)(param_1 + 0x10b00) = 0x40;
  *(long *)(param_1 + 0x10b08) = param_1 + 0x10b40;
  *(undefined4 *)(param_1 + 0x10b10) = 0;
  *(undefined8 *)(param_1 + 0x10ae8) = 0;
  *(undefined8 *)(param_1 + 0x10af0) = 0;
  *(long *)(param_1 + 0x10b78) = lVar1;
  *(undefined4 *)(param_1 + 0x10b70) = 0x40;
  return;
}



//------------------------------------------------------------
// qce_multireq_timeout @ 0010aa78 size=344
// signature: undefined qce_multireq_timeout(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qce_multireq_timeout(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *(int *)(param_1 + 0x16c);
  if ((iVar6 == 0) || (iVar6 != *(int *)(param_1 + 0x170))) {
    *(int *)(param_1 + 0x170) = iVar6;
LAB_0010aafc:
    mod_timer(param_1,_jiffies + 5);
    return;
  }
  uVar4 = daif;
  if ((uVar4 & 0x80) == 0) {
    uVar5 = daif;
    daif = uVar5 | 0xc0;
  }
  piVar7 = (int *)(param_1 + -0xc);
  Hint_Prefetch(piVar7,2,0,1);
  do {
    iVar6 = *piVar7;
    if (iVar6 != 0) goto LAB_0010ab40;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar7,0x10);
    if (bVar3) {
      *piVar7 = 2;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
LAB_0010ab40:
  if (iVar6 != 0) {
    daif = uVar4;
    goto LAB_0010aafc;
  }
  piVar1 = (int *)(param_1 + -0x1c08);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar6 = *piVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar6 == 0) {
    iVar6 = qce_process_sha_req(param_1 + -0x10a70,0);
    *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + 1;
    if (iVar6 == 0) goto LAB_0010ab88;
  }
  _printk(&DAT_0010fe0c,"qce_multireq_timeout",*(undefined4 *)(param_1 + 0x158));
LAB_0010ab88:
  Hint_Prefetch(piVar7,2,0,1);
  do {
    if (*piVar7 != 2) goto LAB_0010aba4;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar7,0x10);
    if (bVar3) {
      *piVar7 = 0;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
LAB_0010aba4:
  *(undefined4 *)(param_1 + 0x150) = 0;
  daif = uVar4;
  del_timer(param_1);
  *(int *)(param_1 + 0x15c) = *(int *)(param_1 + 0x15c) + 1;
  return;
}



//------------------------------------------------------------
// qce_close @ 0010ac10 size=492
// signature: undefined qce_close(void)
// callers: []
//------------------------------------------------------------

undefined8 qce_close(undefined8 *param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == (undefined8 *)0x0) {
    uVar1 = 0xffffffed;
  }
  else {
    mutex_lock(qce_iomap_mutex);
    qce_enable_clk(param_1);
    if ((*(char *)((long)param_1 + 0x10bfa) != '\0') && (*(int *)((long)param_1 + 0x134) != -1)) {
      uVar1 = param_1[0x106];
      sps_disconnect(uVar1);
      dma_free_attrs(*param_1,*(undefined4 *)(param_1 + 0x111),param_1[0x10e],param_1[0x10f],0);
      sps_free_endpoint(uVar1);
      uVar1 = param_1[0x37];
      sps_disconnect(uVar1);
      dma_free_attrs(*param_1,*(undefined4 *)(param_1 + 0x42),param_1[0x3f],param_1[0x40],0);
      sps_free_endpoint(uVar1);
    }
    lVar2 = 0;
    lVar3 = 0x138;
    do {
      if (*(char *)((long)param_1 + 0x10bfb) == '\0') break;
      if (*(int *)((long)param_1 + lVar3) != -1) {
        uVar1 = *(undefined8 *)((long)param_1 + lVar2 + 0x8e8);
        sps_disconnect(uVar1);
        dma_free_attrs(*param_1,*(undefined4 *)((long)param_1 + lVar2 + 0x940),
                       *(undefined8 *)((long)param_1 + lVar2 + 0x928),
                       *(undefined8 *)((long)param_1 + lVar2 + 0x930),0);
        sps_free_endpoint(uVar1);
        uVar1 = *(undefined8 *)((long)param_1 + lVar2 + 0x270);
        sps_disconnect(uVar1);
        dma_free_attrs(*param_1,*(undefined4 *)((long)param_1 + lVar2 + 0x2c8),
                       *(undefined8 *)((long)param_1 + lVar2 + 0x2b0),
                       *(undefined8 *)((long)param_1 + lVar2 + 0x2b8),0);
        sps_free_endpoint(uVar1);
      }
      lVar2 = lVar2 + 0xb8;
      lVar3 = lVar3 + 4;
    } while (lVar2 != 0x5c0);
    qce_sps_release_bam(param_1);
    if (param_1[9] != 0) {
      iounmap();
    }
    if (param_1[2] != 0) {
      dma_free_attrs(*param_1,(long)*(int *)(param_1 + 4),param_1[2],param_1[3],0);
    }
    kfree(param_1[0x217d]);
    kfree(param_1[5]);
    qce_disable_clk(param_1);
    if (*(char *)((long)param_1 + 0x10bf9) == '\0') {
      if (param_1[0xe] != 0) {
        clk_put();
      }
      if (param_1[0xd] != 0) {
        clk_put();
      }
      if (param_1[0xc] != 0) {
        clk_put();
      }
      if (param_1[0xb] != 0) {
        clk_put();
      }
    }
    mutex_unlock(qce_iomap_mutex);
    kfree(param_1);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qce_hw_support @ 0010ae00 size=208
// signature: undefined qce_hw_support(void)
// callers: []
//------------------------------------------------------------

undefined8 qce_hw_support(long param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  *param_2 = 0x1000000;
  *(undefined2 *)(param_2 + 1) = 1;
  *(undefined1 *)((long)param_2 + 6) = 1;
  uVar1 = *(uint *)(param_1 + 0x88);
  *(undefined1 *)((long)param_2 + 10) = 1;
  *(bool *)(param_2 + 2) = ((uVar1 ^ 0xffffffff) & 0x18c) == 0;
  *(bool *)((long)param_2 + 0xb) = *(int *)(param_1 + 0x3c) == 1;
  uVar2 = *(undefined1 *)(param_1 + 0x41);
  *(undefined1 *)((long)param_2 + 7) = 1;
  *(undefined1 *)(param_2 + 3) = uVar2;
  *(undefined1 *)((long)param_2 + 0x13) = *(undefined1 *)(param_1 + 0x42);
  *(undefined1 *)(param_2 + 5) = *(undefined1 *)(param_1 + 0x44);
  *(bool *)((long)param_2 + 9) = *(int *)(param_1 + 0x1ac) == 0;
  *(undefined1 *)((long)param_2 + 0xd) = *(undefined1 *)(param_1 + 0x80);
  *(undefined1 *)((long)param_2 + 0xe) = *(undefined1 *)(param_1 + 0x81);
  *(undefined1 *)((long)param_2 + 0xf) = *(undefined1 *)(param_1 + 0x82);
  *(undefined1 *)(param_2 + 4) = *(undefined1 *)(param_1 + 0x83);
  *(undefined1 *)((long)param_2 + 0x11) = *(undefined1 *)(param_1 + 0x84);
  *(undefined1 *)((long)param_2 + 0x12) = *(undefined1 *)(param_1 + 0x85);
  param_2[6] = *(undefined4 *)(param_1 + 0x128);
  param_2[7] = *(undefined4 *)(param_1 + 300);
  uVar3 = 8;
  if (*(char *)(param_1 + 0x78) == '\0') {
    uVar3 = 1;
  }
  param_2[8] = uVar3;
  return 0;
}



//------------------------------------------------------------
// qce_dump_req @ 0010aed4 size=520
// signature: undefined qce_dump_req(void)
// callers: []
//------------------------------------------------------------

void qce_dump_req(long param_1)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint *puVar4;
  long lVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = 0;
  do {
    iVar1 = *(int *)(param_1 + uVar3 * 0x1bf8 + 0xea8);
    _printk(&DAT_0010fff8,"qce_dump_req","qce_dump_req",uVar3 & 0xffffffff,iVar1 != 0);
    if (iVar1 != 0) {
      lVar5 = param_1 + uVar3 * 0x1bf8;
      puVar4 = *(uint **)(lVar5 + 0xed0);
      _printk(&DAT_0011120e,"_qce_dump_descr_fifos");
      _printk(&DAT_00110b65,"_qce_dump_descr_fifos");
      _printk(&DAT_0011120e,"_qce_dump_descr_fifos");
      if (*(int *)(lVar5 + 0xed8) != 0) {
        uVar8 = 0;
        do {
          _printk(&DAT_0010fcdf,"_qce_dump_descr_fifos",uVar8,*puVar4,puVar4[1] & 0xffff,
                  puVar4[1] >> 0x10);
          if (((puVar4[1] >> 0x1b & 1) != 0) && (uVar2 = puVar4[1] >> 4 & 0xfff, uVar2 != 0)) {
            uVar9 = 0;
            puVar6 = (uint *)((*(long *)(param_1 + 0x10) - *(long *)(param_1 + 0x18)) +
                             (ulong)*puVar4);
            do {
              _printk(&DAT_00110fac,"_qce_dump_descr_fifos",uVar9,*puVar6 & 0xffffff,puVar6[1]);
              uVar9 = uVar9 + 1;
              puVar6 = puVar6 + 4;
            } while (uVar2 != uVar9);
          }
          puVar4 = puVar4 + 2;
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(uint *)(lVar5 + 0xed8));
      }
      _printk(&DAT_0011120e,"_qce_dump_descr_fifos");
      _printk(&DAT_00111071,"_qce_dump_descr_fifos");
      _printk(&DAT_0011120e,"_qce_dump_descr_fifos");
      lVar5 = param_1 + uVar3 * 0x1bf8;
      if (*(int *)(lVar5 + 0xef8) != 0) {
        uVar8 = 0;
        puVar7 = *(undefined4 **)(param_1 + uVar3 * 0x1bf8 + 0xef0);
        do {
          _printk(&DAT_0010fcdf,"_qce_dump_descr_fifos",uVar8,*puVar7,puVar7[1] & 0xffff,
                  (uint)puVar7[1] >> 0x10);
          uVar8 = uVar8 + 1;
          puVar7 = puVar7 + 2;
        } while (uVar8 < *(uint *)(lVar5 + 0xef8));
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 8);
  return;
}



//------------------------------------------------------------
// _qce_sps_add_sg_data_off @ 0010b0dc size=440
// signature: undefined _qce_sps_add_sg_data_off(void)
// callers: [qce_aead_req]
//------------------------------------------------------------

undefined8
_qce_sps_add_sg_data_off(long param_1,long param_2,uint param_3,uint param_4,long param_5)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_2 == 0) {
    uVar3 = 0xfffffffe;
  }
  else {
    lVar5 = *(long *)(param_5 + 8);
    uVar1 = *(uint *)(param_5 + 0x10);
    uVar9 = *(uint *)(param_2 + 0x18);
    while (param_4 != 0) {
      if (param_2 == 0) {
        _printk(&DAT_00110650,"_qce_sps_add_sg_data_off",param_4,param_3);
        return 0xfffffffe;
      }
      uVar8 = *(uint *)(param_2 + 0x18);
      uVar2 = param_4 - uVar8;
      if (param_4 < uVar8) {
        uVar9 = uVar8 - param_4;
        break;
      }
      param_2 = sg_next(param_2);
      param_4 = uVar2;
      if (param_2 != 0) {
        uVar9 = *(uint *)(param_2 + 0x18);
      }
    }
    uVar3 = 0;
    if ((param_3 != 0) && (uVar3 = 0, param_2 != 0)) {
      puVar7 = (undefined4 *)(lVar5 + (ulong)uVar1 * 8);
      while( true ) {
        uVar1 = param_3;
        if (uVar9 <= param_3) {
          uVar1 = uVar9;
        }
        uVar9 = uVar1;
        if (*(int *)(param_1 + 0x1ac) == 0) {
          uVar9 = (uVar1 + *(int *)(param_1 + 0x1a8)) - 1 & -*(int *)(param_1 + 0x1a8);
        }
        if (uVar9 != 0) {
          iVar4 = *(int *)(param_5 + 0x10);
          lVar5 = *(long *)(param_2 + 0x10) + (ulong)param_4;
          puVar6 = puVar7;
          do {
            if (iVar4 == 0x200) {
              _printk(&DAT_0010fd4b,"_qce_sps_add_sg_data_off",0x200,0x200);
              goto LAB_0010b22c;
            }
            uVar8 = uVar9;
            if (0x7fbf < uVar9) {
              uVar8 = 0x7fc0;
            }
            uVar9 = uVar9 - uVar8;
            puVar7 = puVar6 + 2;
            *puVar6 = (int)lVar5;
            puVar6[1] = (uint)((ulong)lVar5 >> 0x10) & 0xf0000 | uVar8;
            lVar5 = lVar5 + (ulong)uVar8;
            iVar4 = *(int *)(param_5 + 0x10) + 1;
            *(int *)(param_5 + 0x10) = iVar4;
            puVar6 = puVar7;
          } while (uVar9 != 0);
        }
        param_3 = param_3 - uVar1;
        if (param_3 == 0) {
          return 0;
        }
        param_2 = sg_next(param_2);
        if (param_2 == 0) break;
        uVar9 = *(uint *)(param_2 + 0x18);
        param_4 = 0;
      }
      _printk(&DAT_00111158,"_qce_sps_add_sg_data_off",param_3);
LAB_0010b22c:
      uVar3 = 0xfffffff4;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// _qce_ccm_get_around_output @ 0010b294 size=288
// signature: undefined _qce_ccm_get_around_output(void)
// callers: [qce_aead_req]
//------------------------------------------------------------

void _qce_ccm_get_around_output(long param_1,long param_2,int param_3)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  uint uVar4;
  ulong uVar5;
  
  if (((param_3 == 1) && (*(char *)(param_1 + 0x78) != '\0')) && (*(char *)(param_1 + 0x79) == '\0')
     ) {
    uVar1 = *(uint *)(param_1 + 0x1a8);
    if (uVar1 != 0) {
      uVar5 = (ulong)*(uint *)(param_2 + 0x50);
      lVar2 = (*(long *)(param_1 + 0x18) + (ulong)*(uint *)(param_2 + 0x1b70)) -
              *(long *)(param_1 + 0x10);
      puVar3 = (undefined4 *)(*(long *)(param_2 + 0x48) + uVar5 * 8);
      do {
        if ((int)uVar5 == 0x200) {
          _printk(&DAT_0010fd4b,"_qce_sps_add_data",0x200,0x200);
          break;
        }
        uVar4 = uVar1;
        if (0x7fbf < uVar1) {
          uVar4 = 0x7fc0;
        }
        uVar1 = uVar1 - uVar4;
        *puVar3 = (int)lVar2;
        puVar3[1] = (uint)((ulong)lVar2 >> 0x10) & 0xf0000 | uVar4;
        lVar2 = lVar2 + (ulong)uVar4;
        uVar4 = *(int *)(param_2 + 0x50) + 1;
        uVar5 = (ulong)uVar4;
        *(uint *)(param_2 + 0x50) = uVar4;
        puVar3 = puVar3 + 2;
      } while (uVar1 != 0);
    }
    if (*(uint *)(param_2 + 0x50) == 0x200) {
      _printk(&DAT_0010fd4b,"_qce_sps_add_data",0x200,0x200);
    }
    else {
      lVar2 = (*(long *)(param_1 + 0x18) + (ulong)*(uint *)(param_2 + 0x1b64)) -
              *(long *)(param_1 + 0x10);
      puVar3 = (undefined4 *)(*(long *)(param_2 + 0x48) + (ulong)*(uint *)(param_2 + 0x50) * 8);
      *puVar3 = (int)lVar2;
      puVar3[1] = (uint)((ulong)lVar2 >> 0x10) & 0xf0000 | 0x80;
      *(int *)(param_2 + 0x50) = *(int *)(param_2 + 0x50) + 1;
    }
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 0010b3b4 size=132
// signature: undefined writel_relaxed(void)
// callers: [qce_f9_req, _ce_f8_setup_direct, qce_aead_req, qce_process_sha_req, _ce_setup_cipher_direct]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10b3cc,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10b408,uVar1);
  return;
}



//------------------------------------------------------------
// _byte_stream_swap_to_net_words @ 0010b438 size=188
// signature: undefined _byte_stream_swap_to_net_words(void)
// callers: [_ce_setup_cipher, _ce_setup_cipher_direct]
//------------------------------------------------------------

void _byte_stream_swap_to_net_words(uint *param_1,long param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint local_28 [4];
  long local_18;
  
  lVar5 = sp_el0;
  local_18 = *(long *)(lVar5 + 0x638);
  uVar3 = (ulong)(0x10 - param_3);
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  if (0x10 - param_3 < 0x10) {
    do {
      param_3 = param_3 - 1;
      if (0xf < uVar3) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x10b4f0);
        (*pcVar1)();
      }
      *(undefined1 *)((long)local_28 + uVar3) = *(undefined1 *)(param_2 + (ulong)param_3);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 != 0x10);
    uVar4 = (local_28[0] & 0xff00ff00) >> 8 | (local_28[0] & 0xff00ff) << 8;
    uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
    uVar6 = (local_28[1] & 0xff00ff00) >> 8 | (local_28[1] & 0xff00ff) << 8;
    uVar6 = uVar6 >> 0x10 | uVar6 << 0x10;
    uVar7 = (local_28[2] & 0xff00ff00) >> 8 | (local_28[2] & 0xff00ff) << 8;
    uVar7 = uVar7 >> 0x10 | uVar7 << 0x10;
    uVar2 = (local_28[3] & 0xff00ff00) >> 8 | (local_28[3] & 0xff00ff) << 8;
    uVar2 = uVar2 >> 0x10 | uVar2 << 0x10;
  }
  else {
    uVar4 = 0;
    uVar6 = 0;
    uVar7 = 0;
    uVar2 = 0;
  }
  *param_1 = uVar4;
  param_1[1] = uVar6;
  param_1[2] = uVar7;
  lVar5 = sp_el0;
  lVar5 = *(long *)(lVar5 + 0x638);
  param_1[3] = uVar2;
  if (lVar5 != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qce_sps_init_ep_conn @ 0010b4f4 size=532
// signature: undefined qce_sps_init_ep_conn(void)
// callers: [qce_sps_init]
//------------------------------------------------------------

int qce_sps_init_ep_conn(undefined8 *param_1,long *param_2,uint param_3,uint param_4)

{
  long *plVar1;
  bool bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined4 uVar6;
  long lVar7;
  
  lVar5 = sps_alloc_endpoint();
  if (lVar5 == 0) {
    _printk(&DAT_00110f00,"qce_sps_init_ep_conn",param_4 & 1);
    return -0xc;
  }
  plVar1 = param_2 + 1;
  *param_2 = lVar5;
  iVar4 = sps_get_config(lVar5,plVar1);
  if (iVar4 == 0) {
    bVar2 = (param_4 & 1) == 0;
    if (bVar2) {
      *plVar1 = 0x7fffffffffffffff;
      uVar6 = 0x20000000;
      lVar7 = param_1[0x34];
    }
    else {
      uVar6 = 0x20000001;
      lVar7 = 0x7fffffffffffffff;
      *plVar1 = param_1[0x34];
    }
    param_2[4] = lVar7;
    *(uint *)((long)param_2 + 0x34) = (uint)bVar2;
    *(undefined4 *)((long)param_2 + 0x3c) = uVar6;
    if (8 < param_3) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10b708);
      (*pcVar3)();
    }
    *(undefined4 *)(param_2 + 3) = *(undefined4 *)((long)param_1 + (ulong)param_3 * 4 + 0x158);
    *(undefined4 *)(param_2 + 6) = *(undefined4 *)((long)param_1 + (ulong)param_3 * 4 + 0x17c);
    uVar6 = *(undefined4 *)((long)param_1 + (ulong)param_3 * 4 + 0x134);
    *(undefined4 *)(param_2 + 0xb) = 0x9000;
    *(undefined4 *)(param_2 + 0x10) = 0x10;
    *(undefined4 *)((long)param_2 + 0x84) = uVar6;
    lVar7 = dma_alloc_attrs(*param_1,0x9000,param_2 + 9,0xdc0,0);
    param_2[8] = lVar7;
    if (lVar7 == 0) {
      _printk(&DAT_0010fc10,"qce_sps_init_ep_conn");
      iVar4 = -0xc;
    }
    else {
      iVar4 = sps_connect(lVar5,plVar1);
      if (iVar4 == 0) {
        *(undefined4 *)((long)param_2 + 0x9c) = 0;
        param_2[0x14] = 0;
        param_2[0x16] = (long)param_1;
        if ((param_4 & 1) == 0) {
          param_2[0x15] = 0;
          *(undefined4 *)(param_2 + 0x13) = 0x20;
          return 0;
        }
        *(undefined4 *)(param_2 + 0x13) = 0x21;
        param_2[0x15] = (long)_sps_producer_callback;
        iVar4 = sps_register_event(*param_2,param_2 + 0x13);
        if (iVar4 == 0) {
          return 0;
        }
        _printk(&DAT_001100cc,"qce_sps_init_ep_conn",iVar4);
      }
      else {
        _printk(&DAT_00111000,"qce_sps_init_ep_conn",lVar5,iVar4);
      }
      dma_free_attrs(*param_1,(int)param_2[0xb],param_2[8],param_2[9],0);
    }
  }
  else {
    _printk(&DAT_00111276,"qce_sps_init_ep_conn",lVar5,iVar4);
  }
  sps_free_endpoint(lVar5);
  return iVar4;
}



//------------------------------------------------------------
// qce_sps_release_bam @ 0010b708 size=164
// signature: undefined qce_sps_release_bam(void)
// callers: [qce_close, qce_sps_init]
//------------------------------------------------------------

void qce_sps_release_bam(long param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  
  mutex_lock(bam_register_lock);
  plVar5 = *(long **)(param_1 + 8);
  if (plVar5 != (long *)0x0) {
    iVar3 = (int)plVar5[3] + -1;
    *(int *)(plVar5 + 3) = iVar3;
    if (iVar3 == 0) {
      if (*(long *)(param_1 + 0x1a0) != 0) {
        sps_deregister_bam_device();
        *(undefined8 *)(param_1 + 0x1a0) = 0;
      }
      iounmap(plVar5[4]);
      uVar4 = __list_del_entry_valid(plVar5);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar5;
        plVar2 = (long *)plVar5[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar5 = -0x2152ffffffffff00;
      plVar5[1] = -0x2152fffffffffede;
      kfree(plVar5);
    }
  }
  *(undefined8 *)(param_1 + 8) = 0;
  mutex_unlock(bam_register_lock);
  return;
}



//------------------------------------------------------------
// _sps_producer_callback @ 0010b7b0 size=4988
// signature: undefined _sps_producer_callback(void)
// callers: []
//------------------------------------------------------------

void _sps_producer_callback(undefined8 *param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  undefined *puVar10;
  undefined8 *puVar11;
  char *pcVar12;
  ulong uVar13;
  undefined4 uVar14;
  uint *puVar15;
  undefined8 *puVar16;
  long lVar17;
  long lVar18;
  undefined4 *puVar19;
  undefined8 uVar20;
  uint uVar21;
  undefined8 uVar22;
  code *pcVar23;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  uVar13 = param_1[3];
  if ((uint)uVar13 >> 0x10 != 0xdead) {
    puVar10 = &DAT_001102d5;
    pcVar12 = "_sps_producer_callback";
    goto LAB_0010beb4;
  }
  uVar3 = (uint)uVar13 & 0xff;
  if (8 < uVar3) {
    puVar10 = &DAT_001102d5;
LAB_0010bea8:
    pcVar12 = "_sps_producer_callback";
    goto LAB_0010beb0;
  }
  param_1 = (undefined8 *)*param_1;
  uVar13 = uVar13 & 0xff;
  if (*(int *)(param_1 + uVar13 * 0x37f + 0x1d5) == 0) {
    puVar10 = &DAT_0010fa60;
    goto LAB_0010bea8;
  }
  puVar2 = (uint *)(param_1 + uVar13 * 0x37f + 0x553);
  if ((*(int *)(param_1 + uVar13 * 0x37f + 0x1d6) - 1U < 2) &&
     (*(int *)(param_1 + uVar13 * 0x37f + 0x1d7) == 0)) {
    *(int *)(param_1 + uVar13 * 0x37f + 0x1d7) = 2;
    if ((ushort)*puVar2 == 0) {
      lVar17 = param_1[2];
      lVar9 = param_1[3];
      *(undefined4 *)(param_1 + uVar13 * 0x37f + 0x1df) = 0;
      lVar17 = (lVar9 + (ulong)*(uint *)(param_1 + uVar13 * 0x37f + 0x541)) - lVar17;
      puVar19 = (undefined4 *)param_1[uVar13 * 0x37f + 0x1de];
      *puVar19 = (int)lVar17;
      puVar19[1] = (uint)((ulong)lVar17 >> 0x10) & 0xf0000 | 0x80;
      uVar3 = *(uint *)(param_1 + uVar13 * 0x37f + 0x1df);
      *(uint *)(param_1 + uVar13 * 0x37f + 0x1df) = uVar3 + 1;
      if (uVar3 != 0xffffffff) {
        lVar17 = param_1[uVar13 * 0x37f + 0x1de] + (ulong)uVar3 * 8;
        *(uint *)(lVar17 + 4) = *(uint *)(lVar17 + 4) | 0x80000000;
      }
      iVar7 = sps_transfer(param_1[0x37],param_1 + uVar13 * 0x37f + 0x1dd);
      if (iVar7 != 0) {
        _printk(&DAT_0010ff79,"_sps_producer_callback",param_1[0x37],iVar7);
      }
    }
    goto LAB_0010c3a0;
  }
  piVar1 = (int *)(param_1 + uVar13 * 0x37f + 0x1d5);
  puVar11 = param_1 + uVar13 * 0x37f + 0x1d6;
  switch(*(int *)(param_1 + uVar13 * 0x37f + 0x1d6)) {
  case 0:
    lVar18 = param_1[uVar13 * 0x37f + 0x548];
    if (lVar18 == 0) {
      _printk(&DAT_001108b7,"_sha_complete");
      goto LAB_0010c3a0;
    }
    pcVar23 = (code *)param_1[uVar13 * 0x37f + 0x546];
    iVar7 = *(int *)(param_1 + uVar13 * 0x37f + 0x54b);
    if (0 < iVar7) {
      uVar22 = *param_1;
      uVar20 = *(undefined8 *)(lVar18 + 0x38);
      do {
        dma_unmap_sg_attrs(uVar22,uVar20,1,1,0);
        uVar20 = sg_next(uVar20);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    puVar16 = (undefined8 *)param_1[uVar13 * 0x37f + 0x544];
    local_78 = puVar16[2];
    uStack_70 = puVar16[3];
    local_88 = *puVar16;
    uStack_80 = puVar16[1];
    uVar8 = (*(uint *)(puVar16 + 8) & 0xff00ff00) >> 8 | (*(uint *)(puVar16 + 8) & 0xff00ff) << 8;
    uVar21 = (*(uint *)((long)puVar16 + 0x44) & 0xff00ff00) >> 8 |
             (*(uint *)((long)puVar16 + 0x44) & 0xff00ff) << 8;
    local_98 = CONCAT44(uVar21 >> 0x10 | uVar21 << 0x10,uVar8 >> 0x10 | uVar8 << 0x10);
    if (8 < uVar3) goto LAB_0010ca38;
    if ((*(char *)(param_1 + 0xf) == '\0') && (*(char *)(param_1 + 8) != '\0')) {
      iVar7 = sps_transfer_one(param_1[(ulong)(ushort)*puVar2 * 0x17 + 0x106],
                               (param_1[uVar13 * 0x37f + 0x526] + param_1[3]) - param_1[2],0,0,0xa00
                              );
      if (iVar7 != 0) {
        _printk(&DAT_00110174,"_qce_unlock_other_pipes",iVar7);
        *(undefined4 *)puVar11 = 5;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar7 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = 0;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar7 == 0) {
          _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
        }
        else if (uVar3 < 8) {
          piVar1 = (int *)(param_1 + 0x214d);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar6) {
              *piVar1 = *piVar1 + -1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
        }
        puVar11 = &local_98;
        goto LAB_0010c96c;
      }
      puVar16 = (undefined8 *)param_1[uVar13 * 0x37f + 0x544];
    }
    uVar8 = *(uint *)(puVar16 + 0xc);
    *(undefined4 *)(puVar16 + 0xc) = 0;
    uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
    if (((uVar8 >> 0x10 | uVar8 << 0x10) & 0x104001) == 0) {
      if (*(int *)((long)param_1 + uVar13 * 0x1bf8 + 0xebc) != 0) {
        puVar10 = &DAT_0011103c;
        goto LAB_0010c59c;
      }
      uVar20 = 0;
      iVar7 = *piVar1;
    }
    else {
      puVar10 = &DAT_00110c7b;
LAB_0010c59c:
      _printk(puVar10,"_sha_complete");
      uVar20 = 0xfffffffa;
      iVar7 = *piVar1;
    }
    if (iVar7 != 0) {
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
        pcVar23 = (code *)SoftwareBreakpoint(0x822c,0x10ba04);
        (*pcVar23)();
      }
      (*pcVar23)(lVar18,&local_88,&local_98,uVar20);
      goto LAB_0010c3a0;
    }
    puVar10 = &DAT_0010fa60;
    pcVar12 = "_sha_complete";
    break;
  case 1:
    local_88 = 0;
    uStack_80 = 0;
    uVar8 = *puVar2;
    pcVar23 = (code *)param_1[uVar13 * 0x37f + 0x546];
    puVar15 = (uint *)param_1[uVar13 * 0x37f + 0x548];
    if (7 < uVar8 - 1) {
      lVar17 = *(long *)(puVar15 + 4);
      lVar9 = *(long *)(puVar15 + 6);
      if (lVar17 == lVar9) {
        lVar9 = lVar17;
      }
      else {
        iVar7 = *(int *)((long)param_1 + uVar13 * 0x1bf8 + 0x2a5c);
        if (0 < iVar7) {
          uVar20 = *param_1;
          do {
            dma_unmap_sg_attrs(uVar20,lVar9,1,2,0);
            lVar9 = sg_next(lVar9);
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          lVar17 = *(long *)(puVar15 + 4);
          lVar9 = *(long *)(puVar15 + 6);
        }
      }
      bVar6 = lVar17 != lVar9;
      iVar7 = *(int *)(param_1 + uVar13 * 0x37f + 0x54b);
      if (0 < iVar7) {
        uVar20 = *param_1;
        do {
          dma_unmap_sg_attrs(uVar20,lVar17,1,bVar6,0);
          lVar17 = sg_next(lVar17);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (8 < uVar3) goto LAB_0010ca38;
      uVar8 = (uint)(ushort)*puVar2;
    }
    if (((*(char *)(param_1 + 0xf) == '\0') && (*(char *)(param_1 + 8) != '\0')) &&
       (iVar7 = sps_transfer_one(param_1[(ulong)(uVar8 & 0xffff) * 0x17 + 0x106],
                                 (param_1[uVar13 * 0x37f + 0x526] + param_1[3]) - param_1[2],0,0,
                                 0xa00), iVar7 != 0)) {
      _printk(&DAT_00110174,"_qce_unlock_other_pipes");
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
        pcVar23 = (code *)SoftwareBreakpoint(0x8234,0x10c890);
        (*pcVar23)();
      }
      (*pcVar23)(puVar15,0,0,0xfffffffa);
      goto LAB_0010c3a0;
    }
    uVar21 = 0;
    uVar8 = *(uint *)(param_1[uVar13 * 0x37f + 0x544] + 0x60);
    *(undefined4 *)(param_1[uVar13 * 0x37f + 0x544] + 0x60) = 0;
    if ((7 < *puVar2 - 1) &&
       (uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8,
       ((uVar8 >> 0x10 | uVar8 << 0x10) & 0x104001) != 0)) {
      _printk(&DAT_00110b12,"_ablk_cipher_complete");
      uVar21 = 0xfffffffa;
    }
    if (*(int *)(param_1 + uVar13 * 0x37f + 0x1d8) != 0 ||
        *(int *)((long)param_1 + uVar13 * 0x1bf8 + 0xebc) != 0) {
      _printk(&DAT_00110588,"_ablk_cipher_complete");
      uVar21 = 0xfffffffa;
    }
    uVar8 = *(uint *)((long)param_1 + uVar13 * 0x1bf8 + 0x2a7c);
    if (uVar8 == 1) {
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      puVar11 = (undefined8 *)0x0;
      uVar21 = *(uint *)((long)param_1 + uVar13 * 0x1bf8 + 0xebc) | uVar21;
    }
    else {
      if (*(int *)((long)param_1 + 0x1ac) == 0) {
        if (uVar8 == 0) {
          if (*(int *)(param_1 + uVar13 * 0x37f + 0x54f) == 1) {
            uStack_80 = param_1[uVar13 * 0x37f + 0x54e];
            local_88 = param_1[uVar13 * 0x37f + 0x54d];
            goto LAB_0010c330;
          }
          lVar17 = ((**(ulong **)(puVar15 + 4) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                   (ulong)(uint)(*(ulong **)(puVar15 + 4))[1] +
                   (ulong)*(uint *)(*(long *)(puVar15 + 4) + 0xc);
          local_88 = *(undefined8 *)(lVar17 + -0x10);
          uStack_80 = *(undefined8 *)(lVar17 + -8);
          uVar8 = *(uint *)((long)param_1 + uVar13 * 0x1bf8 + 0x2a7c);
        }
        if ((uVar8 & 0xfffffffe) == 2) {
          local_88 = **(undefined8 **)(puVar15 + 2);
          uVar20 = (*(undefined8 **)(puVar15 + 2))[1];
          if (uVar8 == 3) {
            uVar8 = 1;
          }
          else {
            uVar8 = *puVar15 >> 4;
          }
          uStack_80._4_4_ = (uint)((ulong)uVar20 >> 0x20);
          uVar4 = (uStack_80._4_4_ & 0xff00ff00) >> 8 | (uStack_80._4_4_ & 0xff00ff) << 8;
          uVar8 = (uVar4 >> 0x10 | uVar4 << 0x10) + uVar8;
          uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
          uStack_80 = CONCAT44(uVar8 >> 0x10 | uVar8 << 0x10,(int)uVar20);
        }
      }
      else {
        local_88 = *(undefined8 *)(param_1[uVar13 * 0x37f + 0x544] + 0x50);
        uStack_80 = *(undefined8 *)(param_1[uVar13 * 0x37f + 0x544] + 0x58);
      }
LAB_0010c330:
      if (*piVar1 == 0) {
        puVar10 = &DAT_0010fa60;
        pcVar12 = "_ablk_cipher_complete";
        break;
      }
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      puVar11 = &local_88;
    }
    if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
      pcVar23 = (code *)SoftwareBreakpoint(0x822d,0x10c39c);
      (*pcVar23)();
    }
    (*pcVar23)(puVar15,0,puVar11,uVar21);
    goto LAB_0010c3a0;
  case 2:
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    lVar18 = param_1[uVar13 * 0x37f + 0x548];
    pcVar23 = (code *)param_1[uVar13 * 0x37f + 0x546];
    lVar17 = *(long *)(lVar18 + 0x40);
    lVar9 = *(long *)(lVar18 + 0x48);
    if (lVar17 == lVar9) {
      lVar9 = lVar17;
    }
    else {
      iVar7 = *(int *)((long)param_1 + uVar13 * 0x1bf8 + 0x2a5c);
      if (iVar7 < 1) {
      }
      else {
        uVar20 = *param_1;
        do {
          dma_unmap_sg_attrs(uVar20,lVar9,1,2,0);
          lVar9 = sg_next(lVar9);
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        lVar17 = *(long *)(lVar18 + 0x40);
        lVar9 = *(long *)(lVar18 + 0x48);
      }
    }
    bVar6 = lVar17 != lVar9;
    iVar7 = *(int *)(param_1 + uVar13 * 0x37f + 0x54b);
    if (0 < iVar7) {
      uVar20 = *param_1;
      do {
        dma_unmap_sg_attrs(uVar20,lVar17,1,bVar6,0);
        lVar17 = sg_next(lVar17);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    lVar17 = param_1[uVar13 * 0x37f + 0x54a];
    if ((lVar17 != 0) && (iVar7 = *(int *)(param_1 + uVar13 * 0x37f + 0x549), 0 < iVar7)) {
      uVar20 = *param_1;
      do {
        dma_unmap_sg_attrs(uVar20,lVar17,1,1,0);
        lVar17 = sg_next(lVar17);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    puVar16 = (undefined8 *)param_1[uVar13 * 0x37f + 0x544];
    local_78 = puVar16[2];
    uStack_70 = puVar16[3];
    local_88 = *puVar16;
    uStack_80 = puVar16[1];
    if (*(int *)(param_1 + uVar13 * 0x37f + 0x54f) == 1) {
      if (*(char *)(param_1 + 0xf) == '\0') {
        uVar8 = readl_relaxed(param_1[9] + 0x1a100);
      }
      else {
        if (*(char *)((long)param_1 + 0x79) == '\0') {
          puVar16 = (undefined8 *)param_1[uVar13 * 0x37f + 0x545];
        }
        uVar8 = (*(uint *)(puVar16 + 0xc) & 0xff00ff00) >> 8 |
                (*(uint *)(puVar16 + 0xc) & 0xff00ff) << 8;
        uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
      }
    }
    else {
      uVar8 = 0;
    }
    if (8 < uVar3) {
LAB_0010ca38:
                    /* WARNING: Does not return */
      pcVar23 = (code *)SoftwareBreakpoint(0x5512,0x10ca3c);
      (*pcVar23)();
    }
    if (((*(char *)(param_1 + 0xf) == '\0') && (*(char *)(param_1 + 8) != '\0')) &&
       (iVar7 = sps_transfer_one(param_1[(ulong)(ushort)*puVar2 * 0x17 + 0x106],
                                 (param_1[uVar13 * 0x37f + 0x526] + param_1[3]) - param_1[2],0,0,
                                 0xa00), iVar7 != 0)) {
      _printk(&DAT_00110174,"_qce_unlock_other_pipes",iVar7);
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      puVar11 = (undefined8 *)0x0;
LAB_0010c96c:
      if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
        pcVar23 = (code *)SoftwareBreakpoint(0x822c,0x10c988);
        (*pcVar23)();
      }
      (*pcVar23)(lVar18,&local_88,puVar11,0xfffffffa);
      goto LAB_0010c3a0;
    }
    lVar17 = param_1[uVar13 * 0x37f + 0x544];
    uVar21 = *(uint *)(lVar17 + 0x60);
    *(undefined4 *)(lVar17 + 0x60) = 0;
    uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
    if (((uVar21 >> 0x10 | uVar21 << 0x10) & 0x104001) == 0) {
      if (*(int *)(param_1 + uVar13 * 0x37f + 0x1d8) != 0 ||
          *(int *)((long)param_1 + uVar13 * 0x1bf8 + 0xebc) != 0) {
        _printk(&DAT_00110f3c,"_aead_complete");
        goto LAB_0010c564;
      }
      uVar14 = 0;
      bVar6 = true;
      iVar7 = *piVar1;
    }
    else {
      _printk(&DAT_00110106,"_aead_complete");
LAB_0010c564:
      bVar6 = false;
      uVar14 = 0xfffffffa;
      iVar7 = *piVar1;
    }
    if (iVar7 != 0) {
      if (*(int *)((long)param_1 + uVar13 * 0x1bf8 + 0x2a7c) == 4) {
        if ((bVar6) &&
           (uVar14 = 0, 0x7fffffff < uVar8 && *(int *)(param_1 + uVar13 * 0x37f + 0x54f) == 1)) {
          uVar14 = 0xffffffb6;
        }
        *(undefined4 *)puVar11 = 5;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar7 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = 0;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar7 == 0) {
          _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
        }
        else if (uVar3 < 8) {
          piVar1 = (int *)(param_1 + 0x214d);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar6) {
              *piVar1 = *piVar1 + -1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
        }
        puVar11 = (undefined8 *)0x0;
      }
      else {
        lVar17 = param_1[uVar13 * 0x37f + 0x544];
        local_98 = *(undefined8 *)(lVar17 + 0x50);
        uStack_90 = *(undefined8 *)(lVar17 + 0x58);
        *(undefined4 *)puVar11 = 5;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar7 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = 0;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar7 == 0) {
          _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
        }
        else if (uVar3 < 8) {
          piVar1 = (int *)(param_1 + 0x214d);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar6) {
              *piVar1 = *piVar1 + -1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
        }
        puVar11 = &local_98;
      }
      if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
        pcVar23 = (code *)SoftwareBreakpoint(0x822c,0x10c18c);
        (*pcVar23)();
      }
      (*pcVar23)(lVar18,&local_88,puVar11,uVar14);
      goto LAB_0010c3a0;
    }
    puVar10 = &DAT_0010fa60;
    pcVar12 = "_aead_complete";
    break;
  case 3:
    pcVar23 = (code *)param_1[uVar13 * 0x37f + 0x546];
    uVar20 = param_1[uVar13 * 0x37f + 0x548];
    if (param_1[uVar13 * 0x37f + 0x551] != 0) {
      dma_unmap_page_attrs
                (*param_1,param_1[uVar13 * 0x37f + 0x551],
                 *(undefined4 *)(param_1 + uVar13 * 0x37f + 0x552),2,0);
    }
    if (param_1[uVar13 * 0x37f + 0x550] != 0) {
      dma_unmap_page_attrs
                (*param_1,param_1[uVar13 * 0x37f + 0x550],
                 *(undefined4 *)(param_1 + uVar13 * 0x37f + 0x552),
                 param_1[uVar13 * 0x37f + 0x551] != 0,0);
    }
    if (((*(char *)(param_1 + 0xf) == '\0') && (*(char *)(param_1 + 8) != '\0')) &&
       (iVar7 = sps_transfer_one(param_1[(ulong)(ushort)*puVar2 * 0x17 + 0x106],
                                 (param_1[uVar13 * 0x37f + 0x526] + param_1[3]) - param_1[2],0,0,
                                 0xa00), iVar7 != 0)) {
      _printk(&DAT_00110174,"_qce_unlock_other_pipes",iVar7);
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
        uVar22 = 0xfffffffa;
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        uVar22 = 0xfffffffa;
      }
      else {
        uVar22 = 0xfffffffa;
      }
    }
    else {
      uVar8 = *(uint *)(param_1[uVar13 * 0x37f + 0x544] + 0x60);
      uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
      uVar8 = uVar8 >> 0x10 | uVar8 << 0x10;
      if ((uVar8 & 0x104001) == 0) {
        if (*(int *)(param_1 + uVar13 * 0x37f + 0x1d8) != 0 ||
            *(int *)((long)param_1 + uVar13 * 0x1bf8 + 0xebc) != 0) {
          _printk(&DAT_00110272,"_f8_complete");
          goto LAB_0010c548;
        }
        uVar22 = 0;
      }
      else {
        uVar21 = *(uint *)(param_1[uVar13 * 0x37f + 0x544] + 100);
        uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
        _printk(&DAT_0010fee4,"_f8_complete",uVar8,uVar21 >> 0x10 | uVar21 << 0x10,uVar3);
LAB_0010c548:
        uVar22 = 0xfffffffa;
      }
      *(undefined4 *)(param_1[uVar13 * 0x37f + 0x544] + 0x60) = 0;
      *(undefined4 *)(param_1[uVar13 * 0x37f + 0x544] + 100) = 0;
      *(undefined4 *)puVar11 = 5;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = 0;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar7 == 0) {
        _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
      }
      else if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
    }
    puVar11 = (undefined8 *)0x0;
    goto LAB_0010bd90;
  case 4:
    pcVar23 = (code *)param_1[uVar13 * 0x37f + 0x546];
    uVar20 = param_1[uVar13 * 0x37f + 0x548];
    dma_unmap_page_attrs
              (*param_1,param_1[uVar13 * 0x37f + 0x550],
               *(undefined4 *)(param_1 + uVar13 * 0x37f + 0x552),1,0);
    puVar15 = (uint *)param_1[uVar13 * 0x37f + 0x544];
    uVar8 = (*puVar15 & 0xff00ff00) >> 8 | (*puVar15 & 0xff00ff) << 8;
    local_88 = CONCAT44(local_88._4_4_,uVar8 >> 0x10 | uVar8 << 0x10);
    if ((*(char *)(param_1 + 0xf) == '\0') && (*(char *)(param_1 + 8) != '\0')) {
      iVar7 = sps_transfer_one(param_1[(ulong)(ushort)*puVar2 * 0x17 + 0x106],
                               (param_1[uVar13 * 0x37f + 0x526] + param_1[3]) - param_1[2],0,0,0xa00
                              );
      if (iVar7 != 0) {
        _printk(&DAT_00110174,"_qce_unlock_other_pipes",iVar7);
        *(undefined4 *)puVar11 = 5;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar7 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = 0;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar7 == 0) {
          _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
        }
        else if (uVar3 < 8) {
          piVar1 = (int *)(param_1 + 0x214d);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar6) {
              *piVar1 = *piVar1 + -1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
        }
        if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
          pcVar23 = (code *)SoftwareBreakpoint(0x8236,0x10c7ac);
          (*pcVar23)();
        }
        (*pcVar23)(uVar20,0,0,0xfffffffa);
        goto LAB_0010c3a0;
      }
      puVar15 = (uint *)param_1[uVar13 * 0x37f + 0x544];
    }
    uVar8 = puVar15[0x18];
    puVar15[0x18] = 0;
    uVar8 = (uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8;
    if (((uVar8 >> 0x10 | uVar8 << 0x10) & 0x104001) == 0) {
      if (*(int *)(param_1 + uVar13 * 0x37f + 0x1d8) != 0 ||
          *(int *)((long)param_1 + uVar13 * 0x1bf8 + 0xebc) != 0) {
        _printk(&DAT_00110f75,"_f9_complete");
        goto LAB_0010c52c;
      }
      uVar22 = 0;
    }
    else {
      _printk(&DAT_001106a1,"_f9_complete");
LAB_0010c52c:
      uVar22 = 0xfffffffa;
    }
    *(undefined4 *)puVar11 = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar7 = *piVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = 0;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar7 == 0) {
      _printk(&DAT_00110c06,"qce_free_req_info",uVar3);
    }
    else if (uVar3 < 8) {
      piVar1 = (int *)(param_1 + 0x214d);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = *piVar1 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
    }
    puVar11 = &local_88;
LAB_0010bd90:
    if (*(int *)(pcVar23 + -4) != 0x1bae92c1) {
                    /* WARNING: Does not return */
      pcVar23 = (code *)SoftwareBreakpoint(0x8236,0x10bdb0);
      (*pcVar23)();
    }
    (*pcVar23)(uVar20,puVar11,0,uVar22);
    goto LAB_0010c3a0;
  default:
    *(undefined4 *)puVar11 = 5;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar7 = *piVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = 0;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar7 != 0) {
      if (uVar3 < 8) {
        piVar1 = (int *)(param_1 + 0x214d);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = *piVar1 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
      }
      goto LAB_0010c3a0;
    }
    puVar10 = &DAT_00110c06;
    pcVar12 = "qce_free_req_info";
  }
LAB_0010beb0:
  uVar13 = (ulong)uVar3;
LAB_0010beb4:
  _printk(puVar10,pcVar12,uVar13);
LAB_0010c3a0:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _setup_cipher_aes_cmdlistptrs @ 0010cbac size=2284
// signature: undefined _setup_cipher_aes_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010d1d0) */

void _setup_cipher_aes_cmdlistptrs
               (long param_1,uint param_2,long *param_3,uint param_4,ulong param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  code *pcVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  ulong uVar14;
  undefined8 *puVar15;
  long lVar16;
  int *piVar17;
  bool bVar18;
  uint *puVar19;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x10d498);
    (*pcVar9)();
  }
  puVar13 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                    -(long)*(int *)(param_1 + 0x1a8));
  *param_3 = (long)puVar13;
  if (3 < param_4) {
    _printk(&DAT_0010fc9e,"_setup_cipher_aes_cmdlistptrs",param_4);
    return;
  }
  uVar14 = (ulong)param_2;
  switch(param_4) {
  default:
    if ((param_5 & 1) == 0) {
      lVar16 = param_1 + uVar14 * 0x1bf8;
      bVar18 = false;
      bVar5 = false;
      uVar12 = 0;
      bVar8 = false;
      puVar15 = (undefined8 *)(lVar16 + 0xfe0);
      puVar10 = (uint *)(param_1 + 0x98);
      if (param_4 != 0) {
        puVar10 = (uint *)(param_1 + 0xb0);
      }
      bVar7 = true;
      bVar6 = true;
      *(uint **)(lVar16 + 0xfe0) = puVar13;
    }
    else {
      bVar5 = false;
      uVar12 = 0;
      bVar8 = false;
      puVar15 = (undefined8 *)(param_1 + (ulong)param_2 * 0x1bf8 + 0xf08);
      puVar10 = (uint *)(param_1 + 0x94);
      if (param_4 != 0) {
        puVar10 = (uint *)(param_1 + 0xac);
      }
      bVar18 = true;
      bVar7 = true;
      bVar6 = true;
      *puVar15 = puVar13;
    }
    break;
  case 1:
    if ((param_5 & 1) == 0) {
      bVar18 = false;
      bVar5 = false;
      uVar12 = 0;
      lVar16 = param_1 + uVar14 * 0x1bf8;
      bVar6 = false;
      puVar10 = (uint *)(param_1 + 0xa0);
      puVar15 = (undefined8 *)(lVar16 + 0x1190);
      bVar7 = true;
      bVar8 = true;
      *(uint **)(lVar16 + 0x1190) = puVar13;
    }
    else {
      bVar5 = false;
      uVar12 = 0;
      bVar6 = false;
      lVar16 = param_1 + uVar14 * 0x1bf8;
      puVar10 = (uint *)(param_1 + 0x9c);
      bVar18 = true;
      puVar15 = (undefined8 *)(lVar16 + 0x10b8);
      bVar7 = true;
      bVar8 = true;
      *(uint **)(lVar16 + 0x10b8) = puVar13;
    }
    break;
  case 3:
    if ((param_5 & 1) == 0) {
      bVar18 = false;
      bVar7 = false;
      bVar8 = false;
      lVar16 = param_1 + uVar14 * 0x1bf8;
      puVar10 = (uint *)(param_1 + 0xa8);
      uVar12 = 8;
      puVar15 = (undefined8 *)(lVar16 + 0x1340);
      bVar5 = true;
      bVar6 = true;
      *(uint **)(lVar16 + 0x1340) = puVar13;
    }
    else {
      bVar7 = false;
      bVar8 = false;
      lVar16 = param_1 + uVar14 * 0x1bf8;
      puVar10 = (uint *)(param_1 + 0xa4);
      uVar12 = 4;
      bVar18 = true;
      puVar15 = (undefined8 *)(lVar16 + 0x1268);
      bVar5 = true;
      bVar6 = true;
      *(uint **)(lVar16 + 0x1268) = puVar13;
    }
  }
  uVar2 = *puVar10;
  piVar17 = (int *)(param_1 + 0x50);
  iVar4 = *piVar17;
  puVar13[1] = 0;
  puVar13[2] = 0xffffffff;
  puVar13[3] = 0;
  *puVar13 = iVar4 + 0x1a100U & 0xffffff;
  iVar4 = *piVar17;
  puVar13[5] = 0;
  puVar13[6] = 0xffffffff;
  puVar13[7] = 0;
  puVar13[4] = iVar4 + 0x1a104U & 0xffffff;
  iVar4 = *piVar17;
  puVar13[9] = 0;
  puVar13[10] = 0xffffffff;
  puVar13[0xb] = 0;
  puVar13[8] = iVar4 + 0x1a11cU & 0xffffff;
  iVar4 = *piVar17;
  puVar13[0xd] = 0;
  puVar13[0xe] = 0xffffffff;
  puVar13[0xf] = 0;
  puVar13[0xc] = iVar4 + 0x1a124U & 0xffffff;
  iVar4 = *piVar17;
  puVar13[0x11] = 0;
  puVar13[0x12] = 0xffffffff;
  puVar13[0x13] = 0;
  puVar13[0x10] = iVar4 + 0x1a128U & 0xffffff;
  iVar4 = *piVar17;
  puVar13[0x15] = 0;
  puVar13[0x16] = 0xffffffff;
  puVar13[0x17] = 0;
  puVar13[0x14] = iVar4 + 0x1a13cU & 0xffffff;
  uVar3 = *(uint *)(param_1 + 0x8c);
  puVar13[0x18] = *piVar17 + 0x1a400U & 0xffffff;
  puVar13[0x19] = uVar3;
  puVar13[0x1a] = 0xffffffff;
  puVar13[0x1b] = 0;
  if (puVar15 + 1 != (undefined8 *)0x0) {
    puVar15[1] = puVar13 + 0x18;
  }
  puVar13[0x1c] = *piVar17 + 0x1a110U & 0xffffff;
  puVar13[0x1d] = 0;
  puVar13[0x1e] = 0xffffffff;
  puVar13[0x1f] = 0;
  if (puVar15 + 0x18 != (undefined8 *)0x0) {
    puVar15[0x18] = puVar13 + 0x1c;
  }
  puVar13[0x20] = *piVar17 + 0x1a200U & 0xffffff;
  puVar13[0x21] = uVar2;
  puVar13[0x22] = 0xffffffff;
  puVar13[0x23] = 0;
  if (puVar15 + 3 != (undefined8 *)0x0) {
    puVar15[3] = puVar13 + 0x20;
  }
  puVar13[0x24] = *piVar17 + 0x1a204U & 0xffffff;
  puVar13[0x25] = 0;
  puVar13[0x26] = 0xffffffff;
  puVar13[0x27] = 0;
  if (puVar15 + 4 != (undefined8 *)0x0) {
    puVar15[4] = puVar13 + 0x24;
  }
  puVar13[0x28] = *piVar17 + 0x1a208U & 0xffffff;
  puVar13[0x29] = 0;
  puVar13[0x2a] = 0xffffffff;
  puVar13[0x2b] = 0;
  if (puVar15 + 5 != (undefined8 *)0x0) {
    puVar15[5] = puVar13 + 0x28;
  }
  uVar2 = *(uint *)(param_1 + 0x110);
  puVar13[0x2c] = *(int *)(param_1 + 0x50) + 0x1a21cU & 0xffffff;
  puVar13[0x2d] = uVar2;
  puVar13[0x2e] = 0xffffffff;
  puVar13[0x2f] = 0;
  if (puVar15 + 0xd != (undefined8 *)0x0) {
    puVar15[0xd] = puVar13 + 0x2c;
  }
  uVar2 = *(uint *)(param_1 + 0x10c);
  puVar13[0x30] = *(int *)(param_1 + 0x50) + 0x1a234U & 0xffffff;
  puVar13[0x31] = uVar2;
  puVar13[0x32] = 0xffffffff;
  puVar13[0x33] = 0;
  if (puVar15 + 0xc != (undefined8 *)0x0) {
    puVar15[0xc] = puVar13 + 0x30;
  }
  uVar2 = *(uint *)(param_1 + 0x108);
  puVar13[0x34] = *(int *)(param_1 + 0x50) + 0x1a238U & 0xffffff;
  puVar13[0x35] = uVar2;
  puVar13[0x36] = 0xffffffff;
  puVar13[0x37] = 0;
  if (puVar15 + 0xb != (undefined8 *)0x0) {
    puVar15[0xb] = puVar13 + 0x34;
  }
  uVar2 = *(uint *)(param_1 + 0x104);
  puVar13[0x38] = *(int *)(param_1 + 0x50) + 0x1a23cU & 0xffffff;
  puVar13[0x39] = uVar2;
  puVar13[0x3a] = 0xffffffff;
  puVar13[0x3b] = 0;
  if (puVar15 + 10 != (undefined8 *)0x0) {
    puVar15[10] = puVar13 + 0x38;
  }
  puVar13[0x3c] = *piVar17 + 0x1a300U & 0xffffff;
  puVar13[0x3d] = 0;
  puVar13[0x3e] = 0xffffffff;
  puVar13[0x3f] = 0;
  if (puVar15 + 0x11 != (undefined8 *)0x0) {
    puVar15[0x11] = puVar13 + 0x3c;
  }
  iVar4 = *piVar17;
  puVar13[0x43] = 0;
  puVar13[0x41] = 0;
  puVar13[0x42] = 0xffffffff;
  puVar13[0x40] = iVar4 + 0x1a500U & 0xffffff;
  if (puVar15 + 0xf != (long *)0x0) {
    puVar15[0xf] = puVar13 + 0x40;
  }
  iVar4 = *piVar17;
  puVar13[0x47] = 0;
  puVar13[0x45] = 0;
  puVar13[0x46] = 0xffffffff;
  puVar13[0x44] = iVar4 + 0x1a504U & 0xffffff;
  if (puVar15 + 0x10 != (long *)0x0) {
    puVar15[0x10] = puVar13 + 0x44;
  }
  iVar4 = *piVar17;
  puVar13[0x4b] = 0;
  puVar13[0x49] = 0;
  puVar13[0x4a] = 0xffffffff;
  puVar13[0x48] = iVar4 + 0x1d000U & 0xffffff;
  if (puVar15 + 6 != (long *)0x0) {
    puVar15[6] = puVar13 + 0x48;
  }
  iVar4 = *piVar17;
  puVar13[0x4f] = 0;
  puVar13[0x4d] = 0;
  puVar13[0x4e] = 0xffffffff;
  puVar13[0x4c] = iVar4 + 0x1d004U & 0xffffff;
  iVar4 = *piVar17;
  puVar13[0x51] = 0;
  puVar13[0x52] = 0xffffffff;
  puVar13[0x53] = 0;
  puVar10 = puVar13 + 0x54;
  puVar13[0x50] = iVar4 + 0x1d008U & 0xffffff;
  iVar4 = *piVar17;
  puVar13[0x55] = 0;
  puVar13[0x56] = 0xffffffff;
  puVar13[0x57] = 0;
  puVar13[0x54] = iVar4 + 0x1d00cU & 0xffffff;
  puVar11 = puVar13 + 0x58;
  if (!bVar18) {
    iVar4 = *piVar17;
    puVar13[0x5b] = 0;
    puVar10 = puVar13 + 100;
    puVar13[0x58] = iVar4 + 0x1d010U & 0xffffff;
    puVar13[0x59] = 0;
    puVar13[0x5a] = 0xffffffff;
    iVar4 = *piVar17;
    puVar13[0x5f] = 0;
    puVar13[0x5d] = 0;
    puVar13[0x5e] = 0xffffffff;
    puVar13[0x5c] = iVar4 + 0x1d014U & 0xffffff;
    iVar4 = *piVar17;
    puVar13[0x61] = 0;
    puVar13[0x62] = 0xffffffff;
    puVar13[99] = 0;
    puVar11 = puVar13 + 0x68;
    puVar13[0x60] = iVar4 + 0x1d018U & 0xffffff;
    iVar4 = *piVar17;
    puVar13[0x65] = 0;
    puVar13[0x66] = 0xffffffff;
    puVar13[0x67] = 0;
    puVar13[100] = iVar4 + 0x1d01cU & 0xffffff;
  }
  if (bVar7) goto joined_r0x0010d0e0;
  *puVar11 = *piVar17 + 0x1d020U & 0xffffff;
  puVar10[5] = 0;
  puVar10[6] = 0xffffffff;
  puVar10[7] = 0;
  if (puVar15 + 7 != (undefined8 *)0x0) {
    puVar15[7] = puVar11;
  }
  puVar19 = puVar10 + 8;
  if (bVar5) {
    if (uVar12 < 3) {
      uVar12 = 2;
    }
    puVar10[8] = *piVar17 + 0x1d024U & 0xffffff;
    puVar11[5] = 0;
    puVar11[6] = 0xffffffff;
    puVar11[7] = 0;
    iVar4 = *piVar17;
    puVar10[0xd] = 0;
    puVar10[0xe] = 0xffffffff;
    puVar10[0xf] = 0;
    puVar10[0xc] = iVar4 + 0x1d028U & 0xffffff;
    puVar11 = puVar10 + 0x10;
    *puVar11 = *piVar17 + 0x1d02cU & 0xffffff;
    puVar10[0x11] = 0;
    puVar10[0x12] = 0xffffffff;
    puVar10[0x13] = 0;
    if (uVar12 != 4) {
      iVar4 = *piVar17;
      puVar10[0x17] = 0;
      puVar10[0x15] = 0;
      puVar10[0x16] = 0xffffffff;
      puVar10[0x14] = iVar4 + 0x1d030U & 0xffffff;
      puVar11 = puVar10 + 0x18;
      *puVar11 = *piVar17 + 0x1d034U & 0xffffff;
      puVar10[0x19] = 0;
      puVar10[0x1a] = 0xffffffff;
      puVar10[0x1b] = 0;
      if (uVar12 != 6) {
        iVar4 = *piVar17;
        puVar10[0x1d] = 0;
        puVar10[0x1e] = 0xffffffff;
        puVar10[0x1f] = 0;
        puVar10[0x1c] = iVar4 + 0x1d038U & 0xffffff;
        puVar11 = puVar10 + 0x20;
        *puVar11 = *piVar17 + 0x1d03cU & 0xffffff;
        puVar19 = puVar10 + 0x24;
        puVar10[0x21] = 0;
        puVar10[0x22] = 0xffffffff;
        puVar10[0x23] = 0;
        goto LAB_0010d2b4;
      }
    }
    puVar19 = puVar11 + 4;
  }
LAB_0010d2b4:
  *puVar19 = *piVar17 + 0x1a230U & 0xffffff;
  puVar11[5] = 0;
  puVar11[6] = 0xffffffff;
  puVar11[7] = 0;
  if (puVar15 + 0xe != (long *)0x0) {
    puVar15[0xe] = puVar19;
  }
  puVar11 = puVar11 + 8;
joined_r0x0010d0e0:
  if (!bVar8) {
    iVar4 = *piVar17;
    puVar11[3] = 0;
    puVar11[1] = 0;
    puVar11[2] = 0xffffffff;
    *puVar11 = iVar4 + 0x1a20cU & 0xffffff;
    if (puVar15 + 8 != (undefined8 *)0x0) {
      puVar15[8] = puVar11;
    }
    if (bVar6) {
      iVar4 = *piVar17;
      puVar11[7] = 0;
      puVar11[5] = 0;
      puVar11[6] = 0xffffffff;
      puVar11[4] = iVar4 + 0x1a210U & 0xffffff;
      if (bVar8) {
        puVar11 = puVar11 + 8;
      }
      else {
        iVar4 = *piVar17;
        puVar11[9] = 0;
        puVar11[10] = 0xffffffff;
        puVar11[0xb] = 0;
        puVar11[8] = iVar4 + 0x1a214U & 0xffffff;
        iVar4 = *piVar17;
        puVar11[0xd] = 0;
        puVar11[0xe] = 0xffffffff;
        puVar11[0xf] = 0;
        puVar11[0xc] = iVar4 + 0x1a218U & 0xffffff;
        puVar11 = puVar11 + 0x10;
      }
    }
    else {
      puVar11 = puVar11 + 4;
    }
  }
  iVar4 = *piVar17;
  puVar11[3] = 0;
  puVar11[1] = 0;
  puVar11[2] = 0xffffffff;
  puVar1 = puVar15 + 0x12;
  *puVar11 = iVar4 + 0x1a304U & 0xffffff;
  if (param_4 == 3) {
    lVar16 = 1;
    puVar10 = puVar11;
  }
  else {
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = puVar11;
    }
    lVar16 = 2;
    puVar11[4] = *piVar17 + 0x1a308U & 0xffffff;
    puVar11[5] = 0;
    puVar11[6] = 0xffffffff;
    puVar11[7] = 0;
    puVar10 = puVar11 + 4;
  }
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = puVar10;
  }
  iVar4 = *(int *)(param_1 + 0x50);
  uVar12 = *(uint *)(param_1 + 0x90);
  puVar11 = puVar11 + lVar16 * 4;
  puVar11[2] = 0xffffffff;
  puVar11[3] = 0;
  *puVar11 = iVar4 + 0x1a400U & 0xffffff;
  puVar11[1] = uVar12;
  if (puVar15 + 2 != (long *)0x0) {
    puVar15[2] = puVar11;
  }
  puVar11[4] = *piVar17 + 0x1a120U & 0xffffff;
  puVar11[5] = 7;
  puVar11[6] = 0xffffffff;
  puVar11[7] = 0;
  if (puVar15 + 0x19 != (undefined8 *)0x0) {
    puVar15[0x19] = puVar11 + 4;
  }
  puVar15[0x1a] = (long)(puVar11 + 8) - (long)puVar13;
  *param_3 = (long)(puVar11 + 8);
  return;
}



//------------------------------------------------------------
// _setup_cipher_des_cmdlistptrs @ 0010d498 size=972
// signature: undefined _setup_cipher_des_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

void _setup_cipher_des_cmdlistptrs(long param_1,uint param_2,long *param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  code *pcVar5;
  uint *puVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  bool bVar10;
  uint *puVar11;
  uint *puVar12;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10d864);
    (*pcVar5)();
  }
  puVar6 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  uVar7 = (ulong)param_2;
  *param_3 = (long)puVar6;
  if (param_4 == 1) {
    bVar10 = false;
    if ((param_5 & 1) == 0) {
      puVar12 = (uint *)(param_1 + 200);
      lVar9 = param_1 + uVar7 * 0x1bf8;
      bVar4 = true;
      lVar8 = lVar9 + 0x16a0;
      *(uint **)(lVar9 + 0x16a0) = puVar6;
    }
    else {
      bVar4 = false;
      puVar12 = (uint *)(param_1 + 0xc4);
      lVar9 = param_1 + uVar7 * 0x1bf8;
      lVar8 = lVar9 + 0x15c8;
      *(uint **)(lVar9 + 0x15c8) = puVar6;
    }
  }
  else {
    if (param_4 != 0) {
      _printk(&DAT_001108e7,"_setup_cipher_des_cmdlistptrs",param_4);
      return;
    }
    if ((param_5 & 1) == 0) {
      puVar12 = (uint *)(param_1 + 0xc0);
      bVar10 = true;
      lVar9 = param_1 + uVar7 * 0x1bf8;
      bVar4 = true;
      lVar8 = lVar9 + 0x14f0;
      *(uint **)(lVar9 + 0x14f0) = puVar6;
    }
    else {
      bVar4 = false;
      puVar12 = (uint *)(param_1 + 0xbc);
      bVar10 = true;
      lVar9 = param_1 + uVar7 * 0x1bf8;
      lVar8 = lVar9 + 0x1418;
      *(uint **)(lVar9 + 0x1418) = puVar6;
    }
  }
  iVar1 = *(int *)(param_1 + 0x50);
  uVar2 = *puVar12;
  puVar6[3] = 0;
  puVar6[1] = 0;
  puVar6[2] = 0xffffffff;
  *puVar6 = iVar1 + 0x1a100U & 0xffffff;
  uVar3 = *(uint *)(param_1 + 0x8c);
  puVar6[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  puVar6[5] = uVar3;
  puVar6[6] = 0xffffffff;
  puVar6[7] = 0;
  if ((undefined8 *)(lVar8 + 8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 8) = puVar6 + 4;
  }
  puVar6[8] = *(int *)(param_1 + 0x50) + 0x1a110U & 0xffffff;
  puVar6[9] = 0;
  puVar6[10] = 0xffffffff;
  puVar6[0xb] = 0;
  if ((undefined8 *)(lVar8 + 0xc0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xc0) = puVar6 + 8;
  }
  puVar6[0xc] = *(int *)(param_1 + 0x50) + 0x1a200U & 0xffffff;
  puVar6[0xd] = uVar2;
  puVar6[0xe] = 0xffffffff;
  puVar6[0xf] = 0;
  if ((undefined8 *)(lVar8 + 0x18) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x18) = puVar6 + 0xc;
  }
  puVar6[0x10] = *(int *)(param_1 + 0x50) + 0x1a204U & 0xffffff;
  puVar6[0x11] = 0;
  puVar6[0x12] = 0xffffffff;
  puVar6[0x13] = 0;
  if ((undefined8 *)(lVar8 + 0x20) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x20) = puVar6 + 0x10;
  }
  puVar6[0x14] = *(int *)(param_1 + 0x50) + 0x1a208U & 0xffffff;
  puVar6[0x15] = 0;
  puVar6[0x16] = 0xffffffff;
  puVar6[0x17] = 0;
  if ((undefined8 *)(lVar8 + 0x28) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x28) = puVar6 + 0x14;
  }
  puVar6[0x18] = *(int *)(param_1 + 0x50) + 0x1a300U & 0xffffff;
  puVar6[0x19] = 0;
  puVar6[0x1a] = 0xffffffff;
  puVar6[0x1b] = 0;
  if ((undefined8 *)(lVar8 + 0x88) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x88) = puVar6 + 0x18;
  }
  puVar6[0x1c] = *(int *)(param_1 + 0x50) + 0x1d000U & 0xffffff;
  puVar6[0x1d] = 0;
  puVar6[0x1e] = 0xffffffff;
  puVar6[0x1f] = 0;
  if ((undefined8 *)(lVar8 + 0x30) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x30) = puVar6 + 0x1c;
  }
  puVar12 = puVar6 + 0x20;
  *puVar12 = *(int *)(param_1 + 0x50) + 0x1d004U & 0xffffff;
  puVar6[0x21] = 0;
  puVar6[0x22] = 0xffffffff;
  puVar6[0x23] = 0;
  if (bVar10) {
    puVar11 = puVar6 + 0x24;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x50);
    puVar6[0x25] = 0;
    puVar6[0x26] = 0xffffffff;
    puVar6[0x27] = 0;
    puVar6[0x24] = iVar1 + 0x1d008U & 0xffffff;
    iVar1 = *(int *)(param_1 + 0x50);
    puVar6[0x29] = 0;
    puVar6[0x2a] = 0xffffffff;
    puVar6[0x2b] = 0;
    puVar6[0x28] = iVar1 + 0x1d00cU & 0xffffff;
    iVar1 = *(int *)(param_1 + 0x50);
    puVar6[0x2d] = 0;
    puVar6[0x2e] = 0xffffffff;
    puVar6[0x2f] = 0;
    puVar6[0x2c] = iVar1 + 0x1d010U & 0xffffff;
    puVar12 = puVar6 + 0x30;
    *puVar12 = *(int *)(param_1 + 0x50) + 0x1d014U & 0xffffff;
    puVar11 = puVar6 + 0x34;
    puVar6[0x31] = 0;
    puVar6[0x32] = 0xffffffff;
    puVar6[0x33] = 0;
  }
  if (!bVar4) {
    *puVar11 = *(int *)(param_1 + 0x50) + 0x1a20cU & 0xffffff;
    puVar12[5] = 0;
    puVar12[6] = 0xffffffff;
    puVar12[7] = 0;
    if ((long *)(lVar8 + 0x40) != (long *)0x0) {
      *(long *)(lVar8 + 0x40) = (long)puVar11;
    }
    iVar1 = *(int *)(param_1 + 0x50);
    puVar12[9] = 0;
    puVar12[10] = 0xffffffff;
    puVar12[0xb] = 0;
    puVar11 = puVar12 + 0xc;
    puVar12[8] = iVar1 + 0x1a210U & 0xffffff;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  uVar2 = *(uint *)(param_1 + 0x90);
  puVar11[2] = 0xffffffff;
  puVar11[3] = 0;
  *puVar11 = iVar1 + 0x1a400U & 0xffffff;
  puVar11[1] = uVar2;
  if ((undefined8 *)(lVar8 + 0x10) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x10) = puVar11;
  }
  puVar11[4] = *(int *)(param_1 + 0x50) + 0x1a120U & 0xffffff;
  puVar11[5] = 7;
  puVar11[6] = 0xffffffff;
  puVar11[7] = 0;
  if ((undefined8 *)(lVar8 + 200) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 200) = puVar11 + 4;
  }
  *(long *)(lVar8 + 0xd0) = (long)(puVar11 + 8) - (long)puVar6;
  *param_3 = (long)(puVar11 + 8);
  return;
}



//------------------------------------------------------------
// _setup_auth_cmdlistptrs @ 0010d864 size=1924
// signature: undefined _setup_auth_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

void _setup_auth_cmdlistptrs(long param_1,uint param_2,long *param_3,uint param_4,ulong param_5)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  bool bVar4;
  long lVar5;
  code *pcVar6;
  uint uVar7;
  uint *puVar8;
  ulong uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  int *piVar14;
  uint uVar15;
  uint *puVar16;
  bool bVar17;
  uint *puVar18;
  int iVar19;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10dfe8);
    (*pcVar6)();
  }
  puVar8 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  *param_3 = (long)puVar8;
  if (4 < param_4) {
    _printk(&DAT_001108e7,"_setup_auth_cmdlistptrs",param_4);
    return;
  }
  uVar9 = (ulong)param_2;
  switch(param_4) {
  case 0:
    iVar19 = *(int *)(param_1 + 0x50);
    uVar15 = *(uint *)(param_1 + 0xdc);
    lVar12 = param_1 + uVar9 * 0x1bf8;
    puVar2 = (undefined8 *)(lVar12 + 0x1780);
    *(uint **)(lVar12 + 0x1778) = puVar8;
    puVar8[1] = 0;
    puVar8[2] = 0xffffffff;
    puVar8[3] = 0;
    *puVar8 = iVar19 + 0x1a100U & 0xffffff;
    lVar12 = lVar12 + 0x1778;
    uVar10 = *(uint *)(param_1 + 0x8c);
    puVar8[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
    puVar8[5] = uVar10;
    puVar8[6] = 0xffffffff;
    puVar8[7] = 0;
    uVar10 = 0;
    break;
  case 1:
    iVar19 = *(int *)(param_1 + 0x50);
    lVar13 = param_1 + uVar9 * 0x1bf8;
    uVar15 = *(uint *)(param_1 + 0xe0);
    *(uint **)(lVar13 + 0x1850) = puVar8;
    puVar8[1] = 0;
    puVar8[2] = 0xffffffff;
    puVar8[3] = 0;
    *puVar8 = iVar19 + 0x1a100U & 0xffffff;
    lVar12 = lVar13 + 0x1850;
    uVar10 = *(uint *)(param_1 + 0x8c);
    puVar8[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
    puVar8[5] = uVar10;
    puVar8[6] = 0xffffffff;
    puVar8[7] = 0;
    if ((undefined8 *)(lVar13 + 0x1858) != (undefined8 *)0x0) {
      *(undefined8 *)(lVar13 + 0x1858) = puVar8 + 4;
    }
    iVar19 = *(int *)(param_1 + 0x50);
    uVar10 = 0;
    bVar17 = false;
    puVar8[9] = 0;
    puVar8[10] = 0xffffffff;
    bVar4 = true;
    uVar7 = 8;
    goto LAB_0010db90;
  case 2:
    iVar19 = *(int *)(param_1 + 0x50);
    uVar15 = *(uint *)(param_1 + 0xe4);
    lVar12 = param_1 + uVar9 * 0x1bf8;
    puVar2 = (undefined8 *)(lVar12 + 0x1930);
    *(uint **)(lVar12 + 0x1928) = puVar8;
    puVar8[1] = 0;
    puVar8[2] = 0xffffffff;
    puVar8[3] = 0;
    *puVar8 = iVar19 + 0x1a100U & 0xffffff;
    lVar12 = lVar12 + 0x1928;
    uVar10 = *(uint *)(param_1 + 0x8c);
    puVar8[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
    puVar8[5] = uVar10;
    puVar8[6] = 0xffffffff;
    puVar8[7] = 0;
    uVar10 = 0x10;
    break;
  case 3:
    iVar19 = *(int *)(param_1 + 0x50);
    uVar15 = *(uint *)(param_1 + 0xe8);
    lVar13 = param_1 + uVar9 * 0x1bf8;
    *(uint **)(lVar13 + 0x1a00) = puVar8;
    puVar8[1] = 0;
    puVar8[2] = 0xffffffff;
    puVar8[3] = 0;
    *puVar8 = iVar19 + 0x1a100U & 0xffffff;
    lVar12 = lVar13 + 0x1a00;
    uVar10 = *(uint *)(param_1 + 0x8c);
    puVar8[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
    puVar8[5] = uVar10;
    puVar8[6] = 0xffffffff;
    puVar8[7] = 0;
    if ((undefined8 *)(lVar13 + 0x1a08) != (undefined8 *)0x0) {
      *(undefined8 *)(lVar13 + 0x1a08) = puVar8 + 4;
    }
    iVar19 = *(int *)(param_1 + 0x50);
    puVar8[9] = 0;
    puVar8[10] = 0xffffffff;
    bVar17 = false;
    uVar7 = 8;
    bVar4 = true;
    uVar10 = 0x10;
    puVar8[8] = iVar19 + 0x1a204U & 0xffffff;
    goto LAB_0010db98;
  case 4:
    lVar13 = param_1 + uVar9 * 0x1bf8;
    if ((param_5 & 1) == 0) {
      puVar16 = (uint *)(param_1 + 0xd8);
      lVar12 = lVar13 + 0x1bb0;
      uVar10 = 8;
      *(uint **)(lVar13 + 0x1bb0) = puVar8;
    }
    else {
      puVar16 = (uint *)(param_1 + 0xd4);
      lVar12 = lVar13 + 0x1ad8;
      uVar10 = 4;
      *(uint **)(lVar13 + 0x1ad8) = puVar8;
    }
    iVar19 = *(int *)(param_1 + 0x50);
    uVar15 = *puVar16;
    puVar8[3] = 0;
    puVar8[1] = 0;
    puVar8[2] = 0xffffffff;
    *puVar8 = iVar19 + 0x1a100U & 0xffffff;
    uVar7 = *(uint *)(param_1 + 0x8c);
    puVar8[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
    puVar8[5] = uVar7;
    puVar8[6] = 0xffffffff;
    puVar8[7] = 0;
    if ((undefined8 *)(lVar12 + 8) != (undefined8 *)0x0) {
      *(undefined8 *)(lVar12 + 8) = puVar8 + 4;
    }
    iVar19 = *(int *)(param_1 + 0x50);
    bVar4 = false;
    uVar7 = 0;
    puVar8[9] = 0;
    puVar8[10] = 0xffffffff;
    bVar17 = true;
LAB_0010db90:
    puVar8[8] = iVar19 + 0x1a204U & 0xffffff;
LAB_0010db98:
    lVar13 = 3;
    puVar8[0xb] = 0;
    goto LAB_0010db9c;
  }
  if (puVar2 == (undefined8 *)0x0) {
    bVar17 = false;
    bVar4 = true;
    uVar7 = 5;
    lVar13 = 2;
  }
  else {
    bVar4 = true;
    uVar7 = 5;
    bVar17 = false;
    lVar13 = 2;
    *puVar2 = puVar8 + 4;
  }
LAB_0010db9c:
  puVar16 = puVar8 + lVar13 * 4;
  piVar14 = (int *)(param_1 + 0x50);
  iVar19 = *piVar14;
  puVar16[3] = 0;
  puVar16[1] = 0;
  puVar16[2] = 0xffffffff;
  *puVar16 = iVar19 + 0x1a110U & 0xffffff;
  if ((long *)(lVar12 + 0xc0) != (long *)0x0) {
    *(long *)(lVar12 + 0xc0) = (long)puVar16;
  }
  puVar16[4] = *piVar14 + 0x1a200U & 0xffffff;
  puVar16[5] = 0;
  puVar16[6] = 0xffffffff;
  puVar16[7] = 0;
  if ((undefined8 *)(lVar12 + 0x18) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar12 + 0x18) = puVar16 + 4;
  }
  puVar16[8] = *piVar14 + 0x1a300U & 0xffffff;
  puVar16[9] = uVar15;
  puVar16[10] = 0xffffffff;
  puVar16[0xb] = 0;
  if ((undefined8 *)(lVar12 + 0x88) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar12 + 0x88) = puVar16 + 8;
  }
  puVar16[0xc] = *piVar14 + 0x1a304U & 0xffffff;
  puVar16[0xd] = 0;
  puVar16[0xe] = 0xffffffff;
  puVar16[0xf] = 0;
  if ((undefined8 *)(lVar12 + 0x90) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar12 + 0x90) = puVar16 + 0xc;
  }
  puVar16[0x10] = *piVar14 + 0x1a308U & 0xffffff;
  puVar16[0x11] = 0;
  puVar16[0x12] = 0xffffffff;
  puVar16[0x13] = 0;
  if ((undefined8 *)(lVar12 + 0x98) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar12 + 0x98) = puVar16 + 0x10;
  }
  if (param_4 == 4) {
    iVar19 = 0x1a310;
    lVar13 = 0;
    do {
      lVar1 = lVar13 + 0x10;
      uVar15 = iVar19 + *piVar14;
      iVar19 = iVar19 + 4;
      *(undefined8 *)((long)puVar16 + lVar13 + 0x54) = 0xffffffff00000000;
      *(undefined4 *)((long)puVar16 + lVar13 + 0x5c) = 0;
      *(uint *)((long)puVar16 + lVar13 + 0x50) = uVar15 & 0xffffff;
      lVar13 = lVar1;
    } while ((int)lVar1 != 0x100);
    lVar13 = 0;
    iVar19 = 0x1d040;
    do {
      lVar5 = lVar1 + lVar13;
      lVar13 = lVar13 + 0x10;
      uVar15 = iVar19 + *piVar14;
      iVar19 = iVar19 + 4;
      *(undefined8 *)((long)puVar16 + lVar5 + 0x54) = 0xffffffff00000000;
      *(undefined4 *)((long)puVar16 + lVar5 + 0x5c) = 0;
      *(uint *)((long)puVar16 + lVar5 + 0x50) = uVar15 & 0xffffff;
    } while ((int)lVar13 != 0x100);
    iVar19 = *piVar14;
    lVar5 = lVar1 + lVar13;
    puVar18 = (uint *)((long)puVar16 + lVar13 + lVar1 + 0x50);
    *(undefined8 *)((long)puVar16 + lVar5 + 0x54) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar16 + lVar5 + 0x5c) = 0;
    *(uint *)((long)puVar16 + lVar5 + 0x50) = iVar19 + 0x1a390U & 0xffffff;
  }
  else {
    iVar19 = *piVar14;
    puVar16[0x17] = 0;
    puVar16[0x15] = 0;
    puVar16[0x16] = 0xffffffff;
    puVar16[0x14] = iVar19 + 0x1a310U & 0xffffff;
    if ((long *)(lVar12 + 0xa8) != (long *)0x0) {
      *(long *)(lVar12 + 0xa8) = (long)(puVar16 + 0x14);
    }
    puVar18 = puVar16 + 0x18;
    if (bVar4) {
      iVar19 = *piVar14;
      puVar16[0x1b] = 0;
      if (uVar7 < 3) {
        uVar7 = 2;
      }
      puVar16[0x19] = 0;
      puVar16[0x1a] = 0xffffffff;
      *puVar18 = iVar19 + 0x1a314U & 0xffffff;
      puVar18 = puVar16 + 0x1c;
      if (!bVar17) {
        iVar19 = *piVar14;
        puVar16[0x1d] = 0;
        puVar16[0x1e] = 0xffffffff;
        puVar16[0x1f] = 0;
        *puVar18 = iVar19 + 0x1a318U & 0xffffff;
        puVar18 = puVar16 + 0x20;
        if (uVar7 != 3) {
          iVar19 = *piVar14;
          puVar16[0x23] = 0;
          puVar16[0x21] = 0;
          puVar16[0x22] = 0xffffffff;
          *puVar18 = iVar19 + 0x1a31cU & 0xffffff;
          puVar18 = puVar16 + 0x24;
          if (uVar7 != 4) {
            iVar19 = *piVar14;
            puVar16[0x25] = 0;
            puVar16[0x26] = 0xffffffff;
            puVar16[0x27] = 0;
            *puVar18 = iVar19 + 0x1a320U & 0xffffff;
            puVar18 = puVar16 + 0x28;
            if (uVar7 != 5) {
              iVar19 = *piVar14;
              puVar16[0x2b] = 0;
              puVar16[0x29] = 0;
              puVar16[0x2a] = 0xffffffff;
              *puVar18 = iVar19 + 0x1a324U & 0xffffff;
              puVar18 = puVar16 + 0x2c;
              if (uVar7 != 6) {
                iVar19 = *piVar14;
                puVar16[0x2d] = 0;
                puVar16[0x2e] = 0xffffffff;
                puVar16[0x2f] = 0;
                *puVar18 = iVar19 + 0x1a328U & 0xffffff;
                puVar18 = puVar16 + 0x30;
                if (uVar7 != 7) {
                  iVar19 = *piVar14;
                  puVar16[0x33] = 0;
                  puVar16[0x31] = 0;
                  puVar16[0x32] = 0xffffffff;
                  *puVar18 = iVar19 + 0x1a32cU & 0xffffff;
                  puVar18 = puVar16 + 0x34;
                }
              }
            }
          }
        }
      }
    }
    iVar19 = *piVar14;
    puVar18[3] = 0;
    puVar18[1] = 0;
    puVar18[2] = 0xffffffff;
    *puVar18 = iVar19 + 0x1a390U & 0xffffff;
    if ((undefined8 *)(lVar12 + 0xb8) != (undefined8 *)0x0) {
      *(undefined8 *)(lVar12 + 0xb8) = puVar18;
    }
  }
  iVar19 = *piVar14;
  puVar18[7] = 0;
  puVar18[5] = 0;
  puVar18[6] = 0xffffffff;
  puVar16 = puVar18 + 8;
  puVar18[4] = iVar19 + 0x1a394U & 0xffffff;
  if (uVar10 != 0) {
    iVar19 = *piVar14;
    puVar18[9] = 0;
    puVar18[10] = 0xffffffff;
    puVar18[0xb] = 0;
    puVar18[8] = iVar19 + 0x1d040U & 0xffffff;
    if ((long *)(lVar12 + 0xa0) != (long *)0x0) {
      *(long *)(lVar12 + 0xa0) = (long)puVar16;
    }
    puVar16 = puVar18 + 0xc;
    if (1 < uVar10) {
      iVar11 = uVar10 - 1;
      iVar19 = 0x1d044;
      puVar18 = puVar16;
      do {
        iVar3 = *piVar14;
        iVar11 = iVar11 + -1;
        puVar18[1] = 0;
        puVar18[2] = 0xffffffff;
        puVar18[3] = 0;
        uVar10 = iVar19 + iVar3;
        iVar19 = iVar19 + 4;
        puVar16 = puVar18 + 4;
        *puVar18 = uVar10 & 0xffffff;
        puVar18 = puVar16;
      } while (iVar11 != 0);
    }
  }
  iVar19 = *(int *)(param_1 + 0x50);
  uVar10 = *(uint *)(param_1 + 0x90);
  puVar16[2] = 0xffffffff;
  puVar16[3] = 0;
  *puVar16 = iVar19 + 0x1a400U & 0xffffff;
  puVar16[1] = uVar10;
  if ((undefined8 *)(lVar12 + 0x10) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar12 + 0x10) = puVar16;
  }
  puVar16[4] = *piVar14 + 0x1a120U & 0xffffff;
  puVar16[5] = 7;
  puVar16[6] = 0xffffffff;
  puVar16[7] = 0;
  if ((undefined8 *)(lVar12 + 200) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar12 + 200) = puVar16 + 4;
  }
  *(long *)(lVar12 + 0xd0) = (long)(puVar16 + 8) - (long)puVar8;
  *param_3 = (long)(puVar16 + 8);
  return;
}



//------------------------------------------------------------
// _setup_aead_cmdlistptrs @ 0010dfe8 size=1352
// signature: undefined _setup_aead_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

void _setup_aead_cmdlistptrs
               (long param_1,uint param_2,long *param_3,int param_4,uint param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  int *piVar10;
  int iVar11;
  uint *puVar12;
  undefined4 *puVar13;
  bool bVar14;
  uint *puVar15;
  long lVar16;
  undefined4 uVar17;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10e530);
    (*pcVar3)();
  }
  puVar6 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  uVar7 = (ulong)param_2;
  *param_3 = (long)puVar6;
  if (param_4 == 2) {
    if (param_5 == 0x20) {
      bVar14 = false;
      lVar8 = param_1 + uVar7 * 0x1bf8;
      lVar9 = 0xe58;
      if ((param_6 & 1) == 0) {
        lVar9 = 0x11b8;
      }
      puVar13 = (undefined4 *)(param_1 + 0x98);
    }
    else {
      if (param_5 != 0x10) {
        return;
      }
      bVar14 = false;
      lVar8 = param_1 + uVar7 * 0x1bf8;
      lVar9 = 0xd80;
      if ((param_6 & 1) == 0) {
        lVar9 = 0x10e0;
      }
      puVar13 = (undefined4 *)(param_1 + 0x94);
    }
  }
  else {
    if (param_4 == 1) {
      lVar9 = 0x1008;
      if ((param_6 & 1) == 0) {
        lVar9 = 0x1368;
      }
      puVar13 = (undefined4 *)(param_1 + 0xc4);
    }
    else {
      if (param_4 != 0) {
        return;
      }
      lVar9 = 0xf30;
      if ((param_6 & 1) == 0) {
        lVar9 = 0x1290;
      }
      puVar13 = (undefined4 *)(param_1 + 0xbc);
    }
    lVar8 = param_1 + uVar7 * 0x1bf8;
    bVar14 = true;
  }
  lVar8 = lVar8 + lVar9;
  *(uint **)(lVar8 + 0xf08) = puVar6;
  uVar17 = *puVar13;
  piVar10 = (int *)(param_1 + 0x50);
  iVar5 = *piVar10;
  puVar6[1] = 0;
  puVar6[2] = 0xffffffff;
  puVar6[3] = 0;
  *puVar6 = iVar5 + 0x1a100U & 0xffffff;
  uVar1 = *(uint *)(param_1 + 0x8c);
  puVar6[4] = *piVar10 + 0x1a400U & 0xffffff;
  puVar6[5] = uVar1;
  puVar6[6] = 0xffffffff;
  puVar6[7] = 0;
  if ((undefined8 *)(lVar8 + 0xf10) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf10) = puVar6 + 4;
  }
  puVar6[8] = *piVar10 + 0x1d000U & 0xffffff;
  puVar6[9] = 0;
  puVar6[10] = 0xffffffff;
  puVar6[0xb] = 0;
  if ((undefined8 *)(lVar8 + 0xf38) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf38) = puVar6 + 8;
  }
  puVar4 = puVar6 + 0xc;
  if (7 < param_5) {
    param_5 = param_5 >> 2;
    if (param_5 < 3) {
      param_5 = 2;
    }
    iVar5 = 0x1d004;
    iVar11 = param_5 - 1;
    puVar12 = puVar4;
    do {
      iVar2 = *piVar10;
      iVar11 = iVar11 + -1;
      puVar12[1] = 0;
      puVar12[2] = 0xffffffff;
      puVar12[3] = 0;
      uVar1 = iVar5 + iVar2;
      iVar5 = iVar5 + 4;
      puVar4 = puVar12 + 4;
      *puVar12 = uVar1 & 0xffffff;
      puVar12 = puVar4;
    } while (iVar11 != 0);
  }
  iVar5 = *piVar10;
  puVar4[3] = 0;
  puVar4[1] = 0;
  puVar4[2] = 0xffffffff;
  *puVar4 = iVar5 + 0x1a20cU & 0xffffff;
  if ((undefined8 *)(lVar8 + 0xf48) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf48) = puVar4;
  }
  puVar12 = puVar4 + 4;
  *puVar12 = *piVar10 + 0x1a210U & 0xffffff;
  puVar4[5] = 0;
  puVar4[6] = 0xffffffff;
  puVar4[7] = 0;
  if (bVar14) {
    puVar15 = puVar4 + 8;
  }
  else {
    iVar5 = *piVar10;
    puVar4[0xb] = 0;
    puVar4[9] = 0;
    puVar4[10] = 0xffffffff;
    puVar4[8] = iVar5 + 0x1a214U & 0xffffff;
    puVar12 = puVar4 + 0xc;
    *puVar12 = *piVar10 + 0x1a218U & 0xffffff;
    puVar15 = puVar4 + 0x10;
    puVar4[0xd] = 0;
    puVar4[0xe] = 0xffffffff;
    puVar4[0xf] = 0;
  }
  iVar5 = 5;
  if ((param_6 & 1) == 0) {
    iVar5 = 8;
  }
  *puVar15 = *piVar10 + 0x1a310U & 0xffffff;
  puVar12[5] = 0;
  puVar12[6] = 0xffffffff;
  puVar12[7] = 0;
  if ((long *)(lVar8 + 0xfb0) != (long *)0x0) {
    *(long *)(lVar8 + 0xfb0) = (long)puVar15;
  }
  iVar5 = iVar5 + -1;
  iVar11 = 0x1a314;
  lVar9 = 0;
  do {
    lVar16 = lVar9;
    iVar5 = iVar5 + -1;
    uVar1 = iVar11 + *piVar10;
    iVar11 = iVar11 + 4;
    *(undefined8 *)((long)puVar12 + lVar16 + 0x24) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar12 + lVar16 + 0x2c) = 0;
    *(uint *)((long)puVar12 + lVar16 + 0x20) = uVar1 & 0xffffff;
    lVar9 = lVar16 + 0x10;
  } while (iVar5 != 0);
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0x30);
  *puVar4 = *piVar10 + 0x1a390U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0x34) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x3c) = 0;
  if ((undefined8 *)(lVar8 + 0xfc0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xfc0) = puVar4;
  }
  iVar5 = *piVar10;
  *(undefined8 *)((long)puVar12 + lVar16 + 0x44) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x4c) = 0;
  *(uint *)((long)puVar12 + lVar16 + 0x40) = iVar5 + 0x1a394U & 0xffffff;
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0x50);
  *puVar4 = *piVar10 + 0x1d040U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0x54) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x5c) = 0;
  if ((undefined8 *)(lVar8 + 0xfa8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xfa8) = puVar4;
  }
  iVar5 = 0;
  do {
    lVar16 = lVar9;
    iVar2 = *piVar10;
    iVar11 = iVar5 + 4;
    *(undefined8 *)((long)puVar12 + lVar16 + 0x54) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar12 + lVar16 + 0x5c) = 0;
    *(uint *)((long)puVar12 + lVar16 + 0x50) = iVar5 + iVar2 + 0x1d044U & 0xffffff;
    lVar9 = lVar16 + 0x10;
    iVar5 = iVar11;
  } while (iVar11 != 0x3c);
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0x60);
  *puVar4 = *piVar10 + 0x1a110U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 100) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x6c) = 0;
  if ((undefined8 *)(lVar8 + 0xfc8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xfc8) = puVar4;
  }
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0x70);
  *puVar4 = *piVar10 + 0x1a200U & 0xffffff;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x74) = uVar17;
  *(undefined8 *)((long)puVar12 + lVar16 + 0x78) = 0xffffffff;
  if ((undefined8 *)(lVar8 + 0xf20) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf20) = puVar4;
  }
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0x80);
  *puVar4 = *piVar10 + 0x1a204U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0x84) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x8c) = 0;
  if ((undefined8 *)(lVar8 + 0xf28) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf28) = puVar4;
  }
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0x90);
  *puVar4 = *piVar10 + 0x1a208U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0x94) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0x9c) = 0;
  if ((undefined8 *)(lVar8 + 0xf30) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf30) = puVar4;
  }
  if ((param_6 & 1) == 0) {
    uVar17 = *(undefined4 *)(param_1 + 0xf8);
  }
  else {
    uVar17 = *(undefined4 *)(param_1 + 0xf4);
  }
  *(uint *)((long)puVar12 + lVar16 + 0xa0) = *piVar10 + 0x1a300U & 0xffffff;
  *(undefined4 *)((long)puVar12 + lVar16 + 0xa4) = uVar17;
  *(undefined8 *)((long)puVar12 + lVar16 + 0xa8) = 0xffffffff;
  if ((long *)(lVar8 + 0xf90) != (long *)0x0) {
    *(long *)(lVar8 + 0xf90) = (long)puVar12 + lVar16 + 0xa0;
  }
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0xb0);
  *puVar4 = *piVar10 + 0x1a304U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0xb4) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0xbc) = 0;
  if ((undefined8 *)(lVar8 + 0xf98) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf98) = puVar4;
  }
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0xc0);
  *puVar4 = *piVar10 + 0x1a308U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0xc4) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar12 + lVar16 + 0xcc) = 0;
  if ((undefined8 *)(lVar8 + 4000) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 4000) = puVar4;
  }
  uVar17 = *(undefined4 *)(param_1 + 0x90);
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0xd0);
  *puVar4 = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  *(undefined4 *)((long)puVar12 + lVar16 + 0xd4) = uVar17;
  *(undefined8 *)((long)puVar12 + lVar16 + 0xd8) = 0xffffffff;
  if ((undefined8 *)(lVar8 + 0xf18) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xf18) = puVar4;
  }
  puVar4 = (uint *)((long)puVar12 + lVar16 + 0xe0);
  *puVar4 = *piVar10 + 0x1a120U & 0xffffff;
  *(undefined8 *)((long)puVar12 + lVar16 + 0xe4) = 0xffffffff00000007;
  *(undefined4 *)((long)puVar12 + lVar16 + 0xec) = 0;
  if ((undefined8 *)(lVar8 + 0xfd0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xfd0) = puVar4;
  }
  *(long *)(lVar8 + 0xfd8) = (long)puVar12 + ((lVar16 + 0x10) - (long)puVar6) + 0xe0;
  *param_3 = (long)puVar12 + lVar16 + 0xf0;
  return;
}



//------------------------------------------------------------
// _setup_aead_ccm_cmdlistptrs @ 0010e530 size=2220
// signature: undefined _setup_aead_ccm_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

void _setup_aead_ccm_cmdlistptrs(long param_1,uint param_2,long *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  code *pcVar6;
  uint *puVar7;
  long lVar8;
  long lVar9;
  int *piVar10;
  uint *puVar11;
  long lVar12;
  int iVar13;
  uint *puVar14;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10eddc);
    (*pcVar6)();
  }
  puVar7 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  lVar9 = param_1 + (ulong)param_2 * 0x1bf8;
  *param_3 = (long)puVar7;
  if ((param_4 & 1) == 0) {
    puVar14 = (uint *)(param_1 + 0xf0);
    lVar8 = lVar9 + 0x2420;
    puVar11 = (uint *)(param_1 + 0xb8);
    *(uint **)(lVar9 + 0x2420) = puVar7;
  }
  else {
    puVar14 = (uint *)(param_1 + 0xec);
    lVar8 = lVar9 + 0x2348;
    puVar11 = (uint *)(param_1 + 0xb4);
    *(uint **)(lVar9 + 0x2348) = puVar7;
  }
  uVar1 = *puVar14;
  piVar10 = (int *)(param_1 + 0x50);
  iVar13 = *piVar10;
  uVar2 = *puVar11;
  puVar7[1] = 0;
  puVar7[2] = 0xffffffff;
  puVar7[3] = 0;
  *puVar7 = iVar13 + 0x1a100U & 0xffffff;
  uVar3 = *(uint *)(param_1 + 0x8c);
  puVar7[4] = *piVar10 + 0x1a400U & 0xffffff;
  puVar7[5] = uVar3;
  puVar7[6] = 0xffffffff;
  puVar7[7] = 0;
  if ((undefined8 *)(lVar8 + 8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 8) = puVar7 + 4;
  }
  iVar13 = *piVar10;
  puVar7[9] = 0;
  puVar7[10] = 0xffffffff;
  puVar7[0xb] = 0;
  puVar7[8] = iVar13 + 0x1a200U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0xd] = 0;
  puVar7[0xe] = 0xffffffff;
  puVar7[0xf] = 0;
  puVar7[0xc] = iVar13 + 0x1a208U & 0xffffff;
  puVar7[0x10] = *piVar10 + 0x1a110U & 0xffffff;
  puVar7[0x11] = 0;
  puVar7[0x12] = 0xffffffff;
  puVar7[0x13] = 0;
  if ((undefined8 *)(lVar8 + 0xc0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xc0) = puVar7 + 0x10;
  }
  puVar7[0x14] = *piVar10 + 0x1a200U & 0xffffff;
  puVar7[0x15] = uVar2;
  puVar7[0x16] = 0xffffffff;
  puVar7[0x17] = 0;
  if ((undefined8 *)(lVar8 + 0x18) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x18) = puVar7 + 0x14;
  }
  puVar7[0x18] = *piVar10 + 0x1a204U & 0xffffff;
  puVar7[0x19] = 0;
  puVar7[0x1a] = 0xffffffff;
  puVar7[0x1b] = 0;
  if ((undefined8 *)(lVar8 + 0x20) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x20) = puVar7 + 0x18;
  }
  puVar7[0x1c] = *piVar10 + 0x1a208U & 0xffffff;
  puVar7[0x1d] = 0;
  puVar7[0x1e] = 0xffffffff;
  puVar7[0x1f] = 0;
  if ((undefined8 *)(lVar8 + 0x28) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x28) = puVar7 + 0x1c;
  }
  uVar2 = *(uint *)(param_1 + 0x110);
  puVar7[0x20] = *(int *)(param_1 + 0x50) + 0x1a21cU & 0xffffff;
  puVar7[0x21] = uVar2;
  puVar7[0x22] = 0xffffffff;
  puVar7[0x23] = 0;
  if ((undefined8 *)(lVar8 + 0x68) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x68) = puVar7 + 0x20;
  }
  uVar2 = *(uint *)(param_1 + 0x10c);
  puVar7[0x24] = *(int *)(param_1 + 0x50) + 0x1a23cU & 0xffffff;
  puVar7[0x25] = uVar2;
  puVar7[0x26] = 0xffffffff;
  puVar7[0x27] = 0;
  if ((undefined8 *)(lVar8 + 0x60) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x60) = puVar7 + 0x24;
  }
  uVar2 = *(uint *)(param_1 + 0x108);
  puVar7[0x28] = *(int *)(param_1 + 0x50) + 0x1a238U & 0xffffff;
  puVar7[0x29] = uVar2;
  puVar7[0x2a] = 0xffffffff;
  puVar7[0x2b] = 0;
  if ((undefined8 *)(lVar8 + 0x58) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x58) = puVar7 + 0x28;
  }
  uVar2 = *(uint *)(param_1 + 0x104);
  puVar7[0x2c] = *(int *)(param_1 + 0x50) + 0x1a234U & 0xffffff;
  puVar7[0x2d] = uVar2;
  puVar7[0x2e] = 0xffffffff;
  puVar7[0x2f] = 0;
  if ((undefined8 *)(lVar8 + 0x50) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x50) = puVar7 + 0x2c;
  }
  puVar7[0x30] = *piVar10 + 0x1a300U & 0xffffff;
  puVar7[0x31] = uVar1;
  puVar7[0x32] = 0xffffffff;
  puVar7[0x33] = 0;
  if ((undefined8 *)(lVar8 + 0x88) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x88) = puVar7 + 0x30;
  }
  puVar7[0x34] = *piVar10 + 0x1a304U & 0xffffff;
  puVar7[0x35] = 0;
  puVar7[0x36] = 0xffffffff;
  puVar7[0x37] = 0;
  if ((undefined8 *)(lVar8 + 0x90) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x90) = puVar7 + 0x34;
  }
  puVar7[0x38] = *piVar10 + 0x1a308U & 0xffffff;
  puVar7[0x39] = 0;
  puVar7[0x3a] = 0xffffffff;
  puVar7[0x3b] = 0;
  if ((undefined8 *)(lVar8 + 0x98) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x98) = puVar7 + 0x38;
  }
  iVar13 = *piVar10;
  puVar7[0x3f] = 0;
  puVar7[0x3d] = 0;
  puVar7[0x3e] = 0xffffffff;
  puVar7[0x3c] = iVar13 + 0x1a310U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x41] = 0;
  puVar7[0x42] = 0xffffffff;
  puVar7[0x43] = 0;
  puVar7[0x40] = iVar13 + 0x1a314U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x45] = 0;
  puVar7[0x46] = 0xffffffff;
  puVar7[0x47] = 0;
  puVar7[0x44] = iVar13 + 0x1a318U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x49] = 0;
  puVar7[0x4a] = 0xffffffff;
  puVar7[0x4b] = 0;
  puVar7[0x48] = iVar13 + 0x1a31cU & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x4d] = 0;
  puVar7[0x4e] = 0xffffffff;
  puVar7[0x4f] = 0;
  puVar7[0x4c] = iVar13 + 0x1a320U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x51] = 0;
  puVar7[0x52] = 0xffffffff;
  puVar7[0x53] = 0;
  puVar7[0x50] = iVar13 + 0x1a324U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x55] = 0;
  puVar7[0x56] = 0xffffffff;
  puVar7[0x57] = 0;
  puVar7[0x54] = iVar13 + 0x1a328U & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x59] = 0;
  puVar7[0x5a] = 0xffffffff;
  puVar7[0x5b] = 0;
  puVar7[0x58] = iVar13 + 0x1a32cU & 0xffffff;
  iVar13 = *piVar10;
  puVar7[0x5d] = 0;
  puVar7[0x5e] = 0xffffffff;
  puVar7[0x5f] = 0;
  puVar7[0x5c] = iVar13 + 0x1a390U & 0xffffff;
  iVar4 = *piVar10;
  puVar7[0x61] = 0;
  puVar7[0x62] = 0xffffffff;
  puVar7[99] = 0;
  iVar13 = 0x1d040;
  puVar7[0x60] = iVar4 + 0x1a394U & 0xffffff;
  lVar9 = 0;
  do {
    lVar12 = lVar9;
    uVar1 = iVar13 + *piVar10;
    iVar13 = iVar13 + 4;
    *(undefined8 *)((long)puVar7 + lVar12 + 0x194) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar12 + 0x19c) = 0;
    *(uint *)((long)puVar7 + lVar12 + 400) = uVar1 & 0xffffff;
    lVar9 = lVar12 + 0x10;
  } while ((int)(lVar12 + 0x10) != 0x100);
  iVar13 = *piVar10;
  *(undefined4 *)((long)puVar7 + lVar12 + 0x1ac) = 0;
  *(undefined8 *)((long)puVar7 + lVar12 + 0x1a4) = 0xffffffff00000000;
  *(uint *)((long)puVar7 + lVar12 + 0x1a0) = iVar13 + 0x1d040U & 0xffffff;
  if ((long *)(lVar8 + 0xa0) != (long *)0x0) {
    *(long *)(lVar8 + 0xa0) = (long)puVar7 + lVar12 + 0x1a0;
  }
  iVar13 = *piVar10;
  *(undefined4 *)((long)puVar7 + lVar12 + 0x1bc) = 0;
  *(undefined8 *)((long)puVar7 + lVar12 + 0x1b4) = 0xffffffff00000000;
  *(uint *)((long)puVar7 + lVar12 + 0x1b0) = iVar13 + 0x1d044U & 0xffffff;
  iVar13 = *piVar10;
  *(undefined8 *)((long)puVar7 + lVar12 + 0x1c4) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar12 + 0x1cc) = 0;
  *(uint *)((long)puVar7 + lVar12 + 0x1c0) = iVar13 + 0x1d048U & 0xffffff;
  iVar13 = *piVar10;
  *(undefined8 *)((long)puVar7 + lVar12 + 0x1d4) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar12 + 0x1dc) = 0;
  *(uint *)((long)puVar7 + lVar12 + 0x1d0) = iVar13 + 0x1d04cU & 0xffffff;
  if ((param_4 & 1) == 0) {
    *(uint *)((long)puVar7 + lVar12 + 0x1e0) = *piVar10 + 0x1d050U & 0xffffff;
    *(undefined8 *)((long)puVar7 + lVar12 + 0x1e4) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar12 + 0x1ec) = 0;
    iVar13 = *piVar10;
    *(undefined8 *)((long)puVar7 + lVar12 + 500) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar12 + 0x1fc) = 0;
    *(uint *)((long)puVar7 + lVar12 + 0x1f0) = iVar13 + 0x1d054U & 0xffffff;
    iVar13 = *piVar10;
    *(undefined8 *)((long)puVar7 + lVar12 + 0x204) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar12 + 0x20c) = 0;
    *(uint *)((long)puVar7 + lVar12 + 0x200) = iVar13 + 0x1d058U & 0xffffff;
    iVar13 = *piVar10;
    *(undefined8 *)((long)puVar7 + lVar12 + 0x214) = 0xffffffff00000000;
    lVar5 = lVar12 + 0x220;
    *(undefined4 *)((long)puVar7 + lVar12 + 0x21c) = 0;
    lVar9 = lVar12 + 0x210;
    *(uint *)((long)puVar7 + lVar12 + 0x210) = iVar13 + 0x1d05cU & 0xffffff;
  }
  else {
    lVar9 = lVar12 + 0x1d0;
    lVar5 = lVar12 + 0x1e0;
  }
  *(uint *)((long)puVar7 + lVar5) = *piVar10 + 0x1a350U & 0xffffff;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x14) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x1c) = 0;
  if ((undefined8 *)(lVar8 + 0xb0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0xb0) = (uint *)((long)puVar7 + lVar5);
  }
  iVar13 = *piVar10;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x24) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x2c) = 0;
  *(uint *)((long)puVar7 + lVar9 + 0x20) = iVar13 + 0x1a354U & 0xffffff;
  iVar13 = *piVar10;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x34) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x3c) = 0;
  *(uint *)((long)puVar7 + lVar9 + 0x30) = iVar13 + 0x1a358U & 0xffffff;
  iVar13 = *piVar10;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x44) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x4c) = 0;
  *(uint *)((long)puVar7 + lVar9 + 0x40) = iVar13 + 0x1a35cU & 0xffffff;
  puVar14 = (uint *)((long)puVar7 + lVar9 + 0x50);
  *puVar14 = *piVar10 + 0x1d000U & 0xffffff;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x54) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x5c) = 0;
  if ((undefined8 *)(lVar8 + 0x30) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x30) = puVar14;
  }
  iVar13 = *piVar10;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x6c) = 0;
  *(undefined8 *)((long)puVar7 + lVar9 + 100) = 0xffffffff00000000;
  *(uint *)((long)puVar7 + lVar9 + 0x60) = iVar13 + 0x1d004U & 0xffffff;
  iVar13 = *piVar10;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x74) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x7c) = 0;
  *(uint *)((long)puVar7 + lVar9 + 0x70) = iVar13 + 0x1d008U & 0xffffff;
  puVar14 = (uint *)((long)puVar7 + lVar9 + 0x80);
  *puVar14 = *piVar10 + 0x1d00cU & 0xffffff;
  *(undefined8 *)((long)puVar7 + lVar9 + 0x84) = 0xffffffff00000000;
  *(undefined4 *)((long)puVar7 + lVar9 + 0x8c) = 0;
  if ((param_4 & 1) == 0) {
    iVar13 = *piVar10;
    *(undefined8 *)((long)puVar7 + lVar9 + 0x94) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar9 + 0x9c) = 0;
    *(uint *)((long)puVar7 + lVar9 + 0x90) = iVar13 + 0x1d010U & 0xffffff;
    iVar13 = *piVar10;
    *(undefined8 *)((long)puVar7 + lVar9 + 0xa4) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar9 + 0xac) = 0;
    *(uint *)((long)puVar7 + lVar9 + 0xa0) = iVar13 + 0x1d014U & 0xffffff;
    iVar13 = *piVar10;
    *(undefined8 *)((long)puVar7 + lVar9 + 0xb4) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar9 + 0xbc) = 0;
    *(uint *)((long)puVar7 + lVar9 + 0xb0) = iVar13 + 0x1d018U & 0xffffff;
    puVar14 = (uint *)((long)puVar7 + lVar9 + 0xc0);
    *puVar14 = *piVar10 + 0x1d01cU & 0xffffff;
    lVar12 = lVar9 + 0xd0;
    *(undefined8 *)((long)puVar7 + lVar9 + 0xc4) = 0xffffffff00000000;
    *(undefined4 *)((long)puVar7 + lVar9 + 0xcc) = 0;
  }
  else {
    lVar12 = lVar9 + 0x90;
  }
  *(uint *)((long)puVar7 + lVar12) = *piVar10 + 0x1a20cU & 0xffffff;
  puVar14[5] = 0;
  puVar14[6] = 0xffffffff;
  puVar14[7] = 0;
  if ((undefined8 *)(lVar8 + 0x40) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x40) = (uint *)((long)puVar7 + lVar12);
  }
  iVar13 = *piVar10;
  puVar14[0xb] = 0;
  puVar14[9] = 0;
  puVar14[10] = 0xffffffff;
  puVar14[8] = iVar13 + 0x1a210U & 0xffffff;
  iVar13 = *piVar10;
  puVar14[0xd] = 0;
  puVar14[0xe] = 0xffffffff;
  puVar14[0xf] = 0;
  puVar14[0xc] = iVar13 + 0x1a214U & 0xffffff;
  iVar13 = *piVar10;
  puVar14[0x11] = 0;
  puVar14[0x12] = 0xffffffff;
  puVar14[0x13] = 0;
  puVar14[0x10] = iVar13 + 0x1a218U & 0xffffff;
  puVar14[0x14] = *piVar10 + 0x1a220U & 0xffffff;
  puVar14[0x15] = 0;
  puVar14[0x16] = 0xffffffff;
  puVar14[0x17] = 0;
  if ((undefined8 *)(lVar8 + 0x48) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x48) = puVar14 + 0x14;
  }
  iVar13 = *(int *)(param_1 + 0x50);
  puVar14[0x19] = 0;
  puVar14[0x1a] = 0xffffffff;
  puVar14[0x1b] = 0;
  puVar14[0x18] = iVar13 + 0x1a224U & 0xffffff;
  iVar13 = *(int *)(param_1 + 0x50);
  puVar14[0x1d] = 0;
  puVar14[0x1e] = 0xffffffff;
  puVar14[0x1f] = 0;
  puVar14[0x1c] = iVar13 + 0x1a228U & 0xffffff;
  iVar13 = *(int *)(param_1 + 0x50);
  puVar14[0x21] = 0;
  puVar14[0x22] = 0xffffffff;
  puVar14[0x23] = 0;
  puVar14[0x20] = iVar13 + 0x1a22cU & 0xffffff;
  uVar1 = *(uint *)(param_1 + 0x90);
  puVar14[0x24] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  puVar14[0x25] = uVar1;
  puVar14[0x26] = 0xffffffff;
  puVar14[0x27] = 0;
  if ((undefined8 *)(lVar8 + 0x10) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 0x10) = puVar14 + 0x24;
  }
  puVar14[0x28] = *piVar10 + 0x1a120U & 0xffffff;
  puVar14[0x29] = 7;
  puVar14[0x2a] = 0xffffffff;
  puVar14[0x2b] = 0;
  if ((undefined8 *)(lVar8 + 200) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar8 + 200) = puVar14 + 0x28;
  }
  *(long *)(lVar8 + 0xd0) = (long)(puVar14 + 0x2c) - (long)puVar7;
  *param_3 = (long)(puVar14 + 0x2c);
  return;
}



//------------------------------------------------------------
// _setup_f8_cmdlistptrs @ 0010eddc size=820
// signature: undefined _setup_f8_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

void _setup_f8_cmdlistptrs(long param_1,uint param_2,long *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint *puVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10f110);
    (*pcVar4)();
  }
  puVar5 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  lVar7 = param_1 + (ulong)param_2 * 0x1bf8;
  *param_3 = (long)puVar5;
  if (param_4 == 0) {
    puVar8 = (uint *)(param_1 + 0xcc);
    lVar6 = lVar7 + 0x25d0;
    *(uint **)(lVar7 + 0x25d0) = puVar5;
  }
  else {
    puVar8 = (uint *)(param_1 + 0xd0);
    lVar6 = lVar7 + 0x26a8;
    *(uint **)(lVar7 + 0x26a8) = puVar5;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  uVar2 = *puVar8;
  puVar5[3] = 0;
  puVar5[1] = 0;
  puVar5[2] = 0xffffffff;
  *puVar5 = iVar1 + 0x1a100U & 0xffffff;
  uVar3 = *(uint *)(param_1 + 0x8c);
  puVar5[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  puVar5[5] = uVar3;
  puVar5[6] = 0xffffffff;
  puVar5[7] = 0;
  if ((undefined8 *)(lVar6 + 8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 8) = puVar5 + 4;
  }
  puVar5[8] = *(int *)(param_1 + 0x50) + 0x1a110U & 0xffffff;
  puVar5[9] = 0;
  puVar5[10] = 0xffffffff;
  puVar5[0xb] = 0;
  if ((undefined8 *)(lVar6 + 0xc0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0xc0) = puVar5 + 8;
  }
  puVar5[0xc] = *(int *)(param_1 + 0x50) + 0x1a200U & 0xffffff;
  puVar5[0xd] = uVar2;
  puVar5[0xe] = 0xffffffff;
  puVar5[0xf] = 0;
  if ((undefined8 *)(lVar6 + 0x18) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x18) = puVar5 + 0xc;
  }
  puVar5[0x10] = *(int *)(param_1 + 0x50) + 0x1a204U & 0xffffff;
  puVar5[0x11] = 0;
  puVar5[0x12] = 0xffffffff;
  puVar5[0x13] = 0;
  if ((undefined8 *)(lVar6 + 0x20) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x20) = puVar5 + 0x10;
  }
  puVar5[0x14] = *(int *)(param_1 + 0x50) + 0x1a208U & 0xffffff;
  puVar5[0x15] = 0;
  puVar5[0x16] = 0xffffffff;
  puVar5[0x17] = 0;
  if ((undefined8 *)(lVar6 + 0x28) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x28) = puVar5 + 0x14;
  }
  puVar5[0x18] = *(int *)(param_1 + 0x50) + 0x1a300U & 0xffffff;
  puVar5[0x19] = 0;
  puVar5[0x1a] = 0xffffffff;
  puVar5[0x1b] = 0;
  if ((undefined8 *)(lVar6 + 0x88) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x88) = puVar5 + 0x18;
  }
  puVar5[0x1c] = *(int *)(param_1 + 0x50) + 0x1a304U & 0xffffff;
  puVar5[0x1d] = 0;
  puVar5[0x1e] = 0xffffffff;
  puVar5[0x1f] = 0;
  if ((undefined8 *)(lVar6 + 0x90) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x90) = puVar5 + 0x1c;
  }
  puVar5[0x20] = *(int *)(param_1 + 0x50) + 0x1a308U & 0xffffff;
  puVar5[0x21] = 0;
  puVar5[0x22] = 0xffffffff;
  puVar5[0x23] = 0;
  if ((undefined8 *)(lVar6 + 0x98) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x98) = puVar5 + 0x20;
  }
  puVar5[0x24] = *(int *)(param_1 + 0x50) + 0x1d000U & 0xffffff;
  puVar5[0x25] = 0;
  puVar5[0x26] = 0xffffffff;
  puVar5[0x27] = 0;
  if ((undefined8 *)(lVar6 + 0x30) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x30) = puVar5 + 0x24;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x2b] = 0;
  puVar5[0x29] = 0;
  puVar5[0x2a] = 0xffffffff;
  puVar5[0x28] = iVar1 + 0x1d004U & 0xffffff;
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x2d] = 0;
  puVar5[0x2e] = 0xffffffff;
  puVar5[0x2f] = 0;
  puVar5[0x2c] = iVar1 + 0x1d008U & 0xffffff;
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x31] = 0;
  puVar5[0x32] = 0xffffffff;
  puVar5[0x33] = 0;
  puVar5[0x30] = iVar1 + 0x1d00cU & 0xffffff;
  puVar5[0x34] = *(int *)(param_1 + 0x50) + 0x1a20cU & 0xffffff;
  puVar5[0x35] = 0;
  puVar5[0x36] = 0xffffffff;
  puVar5[0x37] = 0;
  if ((undefined8 *)(lVar6 + 0x40) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x40) = puVar5 + 0x34;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x39] = 0;
  puVar5[0x3a] = 0xffffffff;
  puVar5[0x3b] = 0;
  puVar5[0x38] = iVar1 + 0x1a210U & 0xffffff;
  uVar2 = *(uint *)(param_1 + 0x90);
  puVar5[0x3c] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  puVar5[0x3d] = uVar2;
  puVar5[0x3e] = 0xffffffff;
  puVar5[0x3f] = 0;
  if ((undefined8 *)(lVar6 + 0x10) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x10) = puVar5 + 0x3c;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x43] = 0;
  puVar5[0x41] = 7;
  puVar5[0x42] = 0xffffffff;
  puVar5[0x40] = iVar1 + 0x1a120U & 0xffffff;
  if ((long *)(lVar6 + 200) != (long *)0x0) {
    *(long *)(lVar6 + 200) = (long)(puVar5 + 0x40);
  }
  *(undefined8 *)(lVar6 + 0xd0) = 0x110;
  *param_3 = (long)(puVar5 + 0x44);
  return;
}



//------------------------------------------------------------
// _setup_f9_cmdlistptrs @ 0010f110 size=756
// signature: undefined _setup_f9_cmdlistptrs(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

void _setup_f9_cmdlistptrs(long param_1,uint param_2,long *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint *puVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  
  if (8 < param_2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10f404);
    (*pcVar4)();
  }
  lVar7 = param_1 + (ulong)param_2 * 0x1bf8;
  puVar5 = (uint *)((*param_3 + (long)*(int *)(param_1 + 0x1a8)) - 1U &
                   -(long)*(int *)(param_1 + 0x1a8));
  *param_3 = (long)puVar5;
  if (param_4 == 0) {
    puVar8 = (uint *)(param_1 + 0xfc);
    lVar6 = lVar7 + 0x2780;
    *(uint **)(lVar7 + 0x2780) = puVar5;
  }
  else {
    puVar8 = (uint *)(param_1 + 0x100);
    lVar6 = lVar7 + 0x2858;
    *(uint **)(lVar7 + 0x2858) = puVar5;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  uVar2 = *puVar8;
  puVar5[3] = 0;
  puVar5[1] = 0;
  puVar5[2] = 0xffffffff;
  *puVar5 = iVar1 + 0x1a100U & 0xffffff;
  uVar3 = *(uint *)(param_1 + 0x8c);
  puVar5[4] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  puVar5[5] = uVar3;
  puVar5[6] = 0xffffffff;
  puVar5[7] = 0;
  if ((undefined8 *)(lVar6 + 8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 8) = puVar5 + 4;
  }
  puVar5[8] = *(int *)(param_1 + 0x50) + 0x1a110U & 0xffffff;
  puVar5[9] = 0;
  puVar5[10] = 0xffffffff;
  puVar5[0xb] = 0;
  if ((undefined8 *)(lVar6 + 0xc0) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0xc0) = puVar5 + 8;
  }
  puVar5[0xc] = *(int *)(param_1 + 0x50) + 0x1a200U & 0xffffff;
  puVar5[0xd] = 0;
  puVar5[0xe] = 0xffffffff;
  puVar5[0xf] = 0;
  if ((undefined8 *)(lVar6 + 0x18) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x18) = puVar5 + 0xc;
  }
  puVar5[0x10] = *(int *)(param_1 + 0x50) + 0x1a300U & 0xffffff;
  puVar5[0x11] = uVar2;
  puVar5[0x12] = 0xffffffff;
  puVar5[0x13] = 0;
  if ((undefined8 *)(lVar6 + 0x88) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x88) = puVar5 + 0x10;
  }
  puVar5[0x14] = *(int *)(param_1 + 0x50) + 0x1a304U & 0xffffff;
  puVar5[0x15] = 0;
  puVar5[0x16] = 0xffffffff;
  puVar5[0x17] = 0;
  if ((undefined8 *)(lVar6 + 0x90) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x90) = puVar5 + 0x14;
  }
  puVar5[0x18] = *(int *)(param_1 + 0x50) + 0x1a308U & 0xffffff;
  puVar5[0x19] = 0;
  puVar5[0x1a] = 0xffffffff;
  puVar5[0x1b] = 0;
  if ((undefined8 *)(lVar6 + 0x98) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x98) = puVar5 + 0x18;
  }
  puVar5[0x1c] = *(int *)(param_1 + 0x50) + 0x1a310U & 0xffffff;
  puVar5[0x1d] = 0;
  puVar5[0x1e] = 0xffffffff;
  puVar5[0x1f] = 0;
  if ((undefined8 *)(lVar6 + 0xa8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0xa8) = puVar5 + 0x1c;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x21] = 0;
  puVar5[0x22] = 0xffffffff;
  puVar5[0x23] = 0;
  puVar5[0x20] = iVar1 + 0x1a314U & 0xffffff;
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x25] = 0;
  puVar5[0x26] = 0xffffffff;
  puVar5[0x27] = 0;
  puVar5[0x24] = iVar1 + 0x1a318U & 0xffffff;
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x29] = 0;
  puVar5[0x2a] = 0xffffffff;
  puVar5[0x2b] = 0;
  puVar5[0x28] = iVar1 + 0x1a31cU & 0xffffff;
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x2d] = 0;
  puVar5[0x2e] = 0xffffffff;
  puVar5[0x2f] = 0;
  puVar5[0x2c] = iVar1 + 0x1a320U & 0xffffff;
  puVar5[0x30] = *(int *)(param_1 + 0x50) + 0x1a390U & 0xffffff;
  puVar5[0x31] = 0;
  puVar5[0x32] = 0xffffffff;
  puVar5[0x33] = 0;
  if ((undefined8 *)(lVar6 + 0xb8) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0xb8) = puVar5 + 0x30;
  }
  iVar1 = *(int *)(param_1 + 0x50);
  puVar5[0x37] = 0;
  puVar5[0x35] = 0;
  puVar5[0x36] = 0xffffffff;
  puVar5[0x34] = iVar1 + 0x1a394U & 0xffffff;
  uVar2 = *(uint *)(param_1 + 0x90);
  puVar5[0x38] = *(int *)(param_1 + 0x50) + 0x1a400U & 0xffffff;
  puVar5[0x39] = uVar2;
  puVar5[0x3a] = 0xffffffff;
  puVar5[0x3b] = 0;
  if ((undefined8 *)(lVar6 + 0x10) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 0x10) = puVar5 + 0x38;
  }
  puVar5[0x3c] = *(int *)(param_1 + 0x50) + 0x1a120U & 0xffffff;
  puVar5[0x3d] = 7;
  puVar5[0x3e] = 0xffffffff;
  puVar5[0x3f] = 0;
  if ((undefined8 *)(lVar6 + 200) != (undefined8 *)0x0) {
    *(undefined8 *)(lVar6 + 200) = puVar5 + 0x3c;
  }
  *(undefined8 *)(lVar6 + 0xd0) = 0x100;
  *param_3 = (long)(puVar5 + 0x40);
  return;
}



//------------------------------------------------------------
// qce_dummy_complete @ 0010f408 size=52
// signature: undefined qce_dummy_complete(void)
// callers: []
//------------------------------------------------------------

void qce_dummy_complete(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_00110921,"qce_dummy_complete");
    return;
  }
  return;
}



//------------------------------------------------------------
// _printk @ 00113000 size=1
// signature: undefined _printk(void)
// callers: [qce_process_sha_req, qce_open, qce_multireq_timeout, qce_manage_timeout, qce_f9_req, _setup_cipher_des_cmdlistptrs, qce_enable_clk, _setup_cipher_aes_cmdlistptrs, _qce_sps_add_cmd, _probe_ce_engine, _sps_producer_callback, qce_aead_req, _setup_auth_cmdlistptrs, qce_dummy_complete, qce_free_req_info, qce_get_crypto_status, _qce_resume, _qce_sps_transfer, _ce_setup_cipher, _qce_sps_add_sg_data, qce_ablk_cipher_req, qce_f8_req, qce_sps_init_ep_conn, qce_sps_init, qce_alloc_req_info, _qce_sps_add_data, qce_f8_multi_pkt_req, _qce_ccm_get_around_output, _qce_sps_add_sg_data_off, qce_dump_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00113008 size=1
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
// log_post_read_mmio @ 00113010 size=1
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
// sps_bam_enable_irqs @ 00113018 size=1
// signature: undefined sps_bam_enable_irqs(void)
// callers: [qce_set_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_bam_enable_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_bam_disable_irqs @ 00113020 size=1
// signature: undefined sps_bam_disable_irqs(void)
// callers: [qce_set_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_bam_disable_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_pipe_reset @ 00113028 size=1
// signature: undefined sps_pipe_reset(void)
// callers: [qce_manage_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_pipe_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_disconnect @ 00113030 size=1
// signature: undefined sps_disconnect(void)
// callers: [qce_sps_init, qce_manage_timeout, _qce_suspend, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_disconnect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00113038 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [_qce_resume, qce_manage_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_connect @ 00113040 size=1
// signature: undefined sps_connect(void)
// callers: [qce_sps_init_ep_conn, _qce_resume, qce_manage_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_register_event @ 00113048 size=1
// signature: undefined sps_register_event(void)
// callers: [qce_sps_init_ep_conn, _qce_resume, qce_manage_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_register_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00113050 size=1
// signature: undefined usleep_range_state(void)
// callers: [qce_manage_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_transfer_one @ 00113058 size=1
// signature: undefined sps_transfer_one(void)
// callers: [_sps_producer_callback, qce_manage_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_transfer_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00113068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qce_sps_init, qce_process_sha_req, _sps_producer_callback, qce_manage_timeout, qce_aead_req, _ce_setup_cipher, qce_setup_ce_sps_data, _byte_stream_swap_to_net_words, _ce_setup_cipher_direct]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 00113070 size=1
// signature: undefined sg_next(void)
// callers: [qce_process_sha_req, _sps_producer_callback, qce_aead_req, _qce_sps_add_sg_data, _qce_sps_add_sg_data_off, qce_ablk_cipher_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_sg_attrs @ 00113078 size=1
// signature: undefined dma_map_sg_attrs(void)
// callers: [qce_process_sha_req, qce_aead_req, qce_ablk_cipher_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_sg_attrs @ 00113080 size=1
// signature: undefined dma_unmap_sg_attrs(void)
// callers: [qce_process_sha_req, _sps_producer_callback, qce_aead_req, qce_ablk_cipher_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_transfer @ 00113088 size=1
// signature: undefined sps_transfer(void)
// callers: [_qce_sps_transfer, _sps_producer_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00113090 size=1
// signature: undefined __const_udelay(void)
// callers: [select_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 001130a0 size=1
// signature: undefined mod_timer(void)
// callers: [qce_multireq_timeout, select_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 001130b0 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [qce_f8_multi_pkt_req, qce_f9_req, qce_f8_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 001130b8 size=1
// signature: undefined dev_driver_string(void)
// callers: [qce_f8_multi_pkt_req, qce_f9_req, qce_f8_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001130c0 size=1
// signature: undefined __warn_printk(void)
// callers: [qce_f8_multi_pkt_req, qce_f9_req, qce_f8_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 001130c8 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [qce_f8_multi_pkt_req, qce_f9_req, qce_f8_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 001130d0 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [_sps_producer_callback, qce_f8_multi_pkt_req, qce_f9_req, qce_f8_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001130d8 size=1
// signature: undefined clk_prepare(void)
// callers: [qce_enable_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001130e0 size=1
// signature: undefined clk_enable(void)
// callers: [qce_enable_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001130e8 size=1
// signature: undefined clk_unprepare(void)
// callers: [qce_disable_clk, qce_enable_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001130f0 size=1
// signature: undefined clk_disable(void)
// callers: [qce_disable_clk, qce_enable_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 001130f8 size=1
// signature: undefined kmalloc_large(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00113100 size=1
// signature: undefined mutex_lock(void)
// callers: [qce_sps_init, qce_open, qce_sps_release_bam, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00113108 size=1
// signature: undefined of_find_property(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00113110 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00113118 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00113128 size=1
// signature: undefined ioremap_prot(void)
// callers: [qce_sps_init, qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00113130 size=1
// signature: undefined platform_get_irq(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00113138 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00113140 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qce_sps_init_ep_conn, qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00113150 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qce_sps_init, qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 00113158 size=1
// signature: undefined clk_get(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 00113160 size=1
// signature: undefined clk_set_rate(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00113168 size=1
// signature: undefined iounmap(void)
// callers: [qce_sps_init, qce_open, qce_sps_release_bam, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_put @ 00113170 size=1
// signature: undefined clk_put(void)
// callers: [qce_open, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00113178 size=1
// signature: undefined kfree(void)
// callers: [qce_sps_init, qce_open, qce_sps_release_bam, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00113180 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qce_sps_init_ep_conn, qce_sps_init, qce_open, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00113188 size=1
// signature: undefined mutex_unlock(void)
// callers: [qce_sps_init, qce_open, qce_sps_release_bam, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00113190 size=1
// signature: undefined init_timer_key(void)
// callers: [qce_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00113198 size=1
// signature: undefined _dev_info(void)
// callers: [_probe_ce_engine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_register_bam_device @ 001131a0 size=1
// signature: undefined sps_register_bam_device(void)
// callers: [qce_sps_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_register_bam_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001131a8 size=1
// signature: undefined __list_add_valid(void)
// callers: [qce_sps_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_free_endpoint @ 001131b0 size=1
// signature: undefined sps_free_endpoint(void)
// callers: [qce_sps_init_ep_conn, qce_sps_init, qce_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_free_endpoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 001131c8 size=1
// signature: noreturn undefined panic(void)
// callers: [qce_setup_ce_sps_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_one @ 001131d0 size=1
// signature: undefined sg_init_one(void)
// callers: [setup_dummy_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 001131e0 size=1
// signature: undefined del_timer(void)
// callers: [qce_multireq_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001131e8 size=1
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
// log_post_write_mmio @ 001131f0 size=1
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
// sps_alloc_endpoint @ 001131f8 size=1
// signature: undefined sps_alloc_endpoint(void)
// callers: [qce_sps_init_ep_conn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_alloc_endpoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_get_config @ 00113200 size=1
// signature: undefined sps_get_config(void)
// callers: [qce_sps_init_ep_conn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_get_config(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sps_deregister_bam_device @ 00113208 size=1
// signature: undefined sps_deregister_bam_device(void)
// callers: [qce_sps_release_bam]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sps_deregister_bam_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00113210 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qce_sps_release_bam]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



