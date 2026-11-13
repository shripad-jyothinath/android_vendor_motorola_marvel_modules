// Decompiled by Ghidra 12.2
// Program: mhi.ko
// Image base: 00100000

//------------------------------------------------------------
// to_mhi_pm_state_str @ 00102974 size=52
// signature: undefined to_mhi_pm_state_str(void)
// callers: [mhi_force_reset, mhi_pm_fast_suspend, mhi_debug_reg_dump, mhi_process_ev_work, mhi_download_rddm_image, mhi_pm_fast_resume, mhi_pm_suspend, __mhi_pm_resume, mhi_power_down, mhi_get_remote_time_sync, mhi_pm_st_worker, mhi_device_get_sync_atomic, mhi_get_remote_time, mhi_report_error, mhi_ready_state_transition]
//------------------------------------------------------------

char * to_mhi_pm_state_str(uint param_1)

{
  if ((param_1 == 0) || (0xc < (LZCOUNT((ulong)param_1) ^ 0x3fU))) {
    return "Invalid State";
  }
  return (&mhi_pm_state_str)[LZCOUNT((ulong)param_1) ^ 0x3fU];
}



//------------------------------------------------------------
// mhi_deinit_free_irq @ 001029ac size=132
// signature: undefined mhi_deinit_free_irq(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

void mhi_deinit_free_irq(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0xc4);
  if (uVar1 != 0) {
    uVar3 = 0;
    lVar2 = *(long *)(param_1 + 0x130);
    do {
      if (*(char *)(lVar2 + 0x112) == '\0') {
        free_irq(*(undefined4 *)(*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar2 + 0x18) * 4),
                 lVar2);
        uVar1 = *(uint *)(param_1 + 0xc4);
      }
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + 0x118;
    } while (uVar3 < uVar1);
  }
  free_irq(**(undefined4 **)(param_1 + 0xb8),param_1);
  return;
}



//------------------------------------------------------------
// mhi_init_irq_setup @ 00102a34 size=568
// signature: undefined mhi_init_irq_setup(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

int mhi_init_irq_setup(long param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar5 = *(long *)(param_1 + 0x130);
  lVar6 = 0x4080;
  if (*(long *)(param_1 + 0x2a8) != 0) {
    lVar6 = *(long *)(param_1 + 0x2a8);
  }
  lVar7 = *(long *)(param_1 + 8);
  iVar2 = request_threaded_irq
                    (**(undefined4 **)(param_1 + 0xb8),mhi_intvec_handler,
                     mhi_intvec_threaded_handler,lVar6,&DAT_00114992,param_1);
  if (iVar2 == 0) {
    disable_irq(**(undefined4 **)(param_1 + 0xb8));
    uVar4 = *(uint *)(param_1 + 0xc4);
    if (uVar4 != 0) {
      iVar2 = -1;
      do {
        if (*(char *)(lVar5 + 0x112) == '\0') {
          if (*(uint *)(param_1 + 0xd0) <= *(uint *)(lVar5 + 0x18)) {
            lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            _dev_err(lVar7 + 0x28,"[E][%s] irq %d not available for event ring\n",
                     "mhi_init_irq_setup");
            if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                             "[E][%s] irq %d not available for event ring\n","mhi_init_irq_setup",
                             *(undefined4 *)(lVar5 + 0x18));
            }
            iVar3 = -0x16;
joined_r0x00102c20:
            for (; -1 < iVar2; iVar2 = iVar2 + -1) {
              if (*(char *)(lVar5 + -6) == '\0') {
                free_irq(*(undefined4 *)
                          (*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar5 + -0x100) * 4),
                         lVar5 + -0x118);
              }
              lVar5 = lVar5 + -0x118;
            }
            free_irq(**(undefined4 **)(param_1 + 0xb8),param_1);
            return iVar3;
          }
          iVar3 = request_threaded_irq
                            (*(undefined4 *)
                              (*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar5 + 0x18) * 4),
                             mhi_irq_handler,0,lVar6,&DAT_001133d0,lVar5);
          if (iVar3 != 0) {
            lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            _dev_err(lVar7 + 0x28,"[E][%s] Error requesting irq:%d for ev:%d\n","mhi_init_irq_setup"
                     ,*(undefined4 *)
                       (*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar5 + 0x18) * 4),iVar2 + 1);
            if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                             "[E][%s] Error requesting irq:%d for ev:%d\n","mhi_init_irq_setup",
                             *(undefined4 *)
                              (*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar5 + 0x18) * 4),
                             iVar2 + 1);
            }
            goto joined_r0x00102c20;
          }
          disable_irq(*(undefined4 *)
                       (*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar5 + 0x18) * 4));
          uVar4 = *(uint *)(param_1 + 0xc4);
        }
        uVar1 = iVar2 + 2;
        lVar5 = lVar5 + 0x118;
        iVar2 = iVar2 + 1;
      } while (uVar1 < uVar4);
    }
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_deinit_dev_ctxt @ 00102c70 size=268
// signature: undefined mhi_deinit_dev_ctxt(void)
// callers: [mhi_unprepare_after_power_down, mhi_prepare_for_power_up]
//------------------------------------------------------------

void mhi_deinit_dev_ctxt(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  uint uVar4;
  char *pcVar5;
  
  puVar1 = (undefined8 *)param_1[0x27];
  puVar2 = (undefined8 *)param_1[0x28];
  dma_free_attrs(*param_1,puVar1[10],puVar1[3],*puVar1,0);
  puVar1[4] = 0;
  puVar1[1] = 0;
  dma_free_attrs(*param_1,0x2c,puVar2[2],puVar2[5],0);
  uVar3 = (ulong)*(uint *)((long)param_1 + 0xc4);
  if (*(uint *)((long)param_1 + 0xc4) != 0) {
    uVar4 = 0;
    pcVar5 = (char *)(param_1[0x26] + 0x112);
    do {
      if (*pcVar5 == '\0') {
        dma_free_attrs(*param_1,*(undefined8 *)(pcVar5 + -0x9a),*(undefined8 *)(pcVar5 + -0xd2),
                       *(undefined8 *)(pcVar5 + -0xea),0);
        pcVar5[-0xca] = '\0';
        pcVar5[-0xc9] = '\0';
        pcVar5[-200] = '\0';
        pcVar5[-199] = '\0';
        pcVar5[-0xc6] = '\0';
        pcVar5[-0xc5] = '\0';
        pcVar5[-0xc4] = '\0';
        pcVar5[-0xc3] = '\0';
        pcVar5[-0xe2] = '\0';
        pcVar5[-0xe1] = '\0';
        pcVar5[-0xe0] = '\0';
        pcVar5[-0xdf] = '\0';
        pcVar5[-0xde] = '\0';
        pcVar5[-0xdd] = '\0';
        pcVar5[-0xdc] = '\0';
        pcVar5[-0xdb] = '\0';
        uVar3 = (ulong)*(uint *)((long)param_1 + 0xc4);
      }
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 0x118;
    } while (uVar4 < (uint)uVar3);
  }
  dma_free_attrs(*param_1,uVar3 * 0x2c,*puVar2,puVar2[3],0);
  dma_free_attrs(*param_1,(ulong)*(uint *)(param_1 + 0x18) * 0x2c,puVar2[1],puVar2[4],0);
  kfree(puVar2);
  param_1[0x28] = 0;
  return;
}



//------------------------------------------------------------
// mhi_init_dev_ctxt @ 00102d80 size=840
// signature: undefined mhi_init_dev_ctxt(void)
// callers: [mhi_prepare_for_power_up]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_init_dev_ctxt(undefined8 *param_1)

{
  long *plVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  undefined4 *puVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  ulong *puVar9;
  long lVar10;
  long *plVar11;
  undefined8 *puVar12;
  long lVar13;
  
  *(undefined4 *)((long)param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x33) = 0;
  plVar1 = (long *)kmalloc_trace(___mutex_init,0xdc0,0x30);
  if (plVar1 != (long *)0x0) {
    lVar2 = dma_alloc_attrs(*param_1,(ulong)*(uint *)(param_1 + 0x18) * 0x2c,plVar1 + 4,0xcc0,0);
    plVar1[1] = lVar2;
    if (lVar2 != 0) {
      uVar7 = *(uint *)(param_1 + 0x18);
      if (uVar7 != 0) {
        uVar3 = 0;
        lVar2 = lVar2 + 0x24;
        puVar5 = (undefined4 *)(param_1[0x14] + 0xcc);
        do {
          if (*(char *)((long)puVar5 + 0xbe) == '\0') {
            *(ushort *)(lVar2 + -0x24) = (ushort)((puVar5[7] & 3) << 8) | (ushort)(puVar5[6] << 10);
            *(undefined4 *)(lVar2 + -0x20) = puVar5[2];
            *(undefined4 *)(lVar2 + -0x1c) = *puVar5;
            puVar5[0xe] = 0;
            *(long *)(puVar5 + -3) = lVar2;
            uVar7 = *(uint *)(param_1 + 0x18);
          }
          uVar3 = uVar3 + 1;
          puVar5 = puVar5 + 100;
          lVar2 = lVar2 + 0x2c;
        } while (uVar3 < uVar7);
      }
      lVar2 = dma_alloc_attrs(*param_1,(ulong)*(uint *)((long)param_1 + 0xc4) * 0x2c,plVar1 + 3,
                              0xcc0,0);
      *plVar1 = lVar2;
      if (lVar2 != 0) {
        uVar3 = *(uint *)((long)param_1 + 0xc4);
        uVar7 = 0;
        lVar10 = param_1[0x26];
        if (uVar3 != 0) {
          puVar9 = (ulong *)(lVar2 + 0x24);
          do {
            if (*(char *)(lVar10 + 0x112) == '\0') {
              *(uint *)((long)puVar9 + -0x24) =
                   (uint)*(byte *)((long)puVar9 + -0x24) | *(int *)(lVar10 + 0x14) << 0x10;
              *(undefined4 *)(puVar9 + -4) = 1;
              *(undefined4 *)((long)puVar9 + -0x1c) = *(undefined4 *)(lVar10 + 0x18);
              lVar4 = *(long *)(lVar10 + 0x70);
              *(undefined1 *)(lVar10 + 0x89) = 1;
              lVar13 = lVar4 * 0x10;
              lVar2 = lVar13 + -1 + lVar13;
              *(undefined8 *)(lVar10 + 0x60) = 0x10;
              *(long *)(lVar10 + 0x68) = lVar13;
              *(long *)(lVar10 + 0x78) = lVar2;
              lVar2 = dma_alloc_attrs(*param_1,lVar2,lVar10 + 0x28,0xcc0,0);
              *(long *)(lVar10 + 0x40) = lVar2;
              if (lVar2 == 0) goto LAB_0010301c;
              uVar6 = *(long *)(lVar10 + 0x28) + lVar13 + -1 & lVar4 * -0x10;
              lVar2 = lVar2 + (uVar6 - *(long *)(lVar10 + 0x28));
              *(ulong *)(lVar10 + 0x30) = uVar6;
              *(long *)(lVar10 + 0x50) = lVar2;
              *(long *)(lVar10 + 0x58) = lVar2;
              *(long *)(lVar10 + 0x48) = lVar2;
              puVar9[-3] = uVar6;
              puVar9[-1] = uVar6;
              *puVar9 = uVar6;
              puVar9[-2] = *(ulong *)(lVar10 + 0x68);
              *(ulong **)(lVar10 + 0x38) = puVar9;
              uVar3 = *(uint *)((long)param_1 + 0xc4);
            }
            uVar7 = uVar7 + 1;
            lVar10 = lVar10 + 0x118;
            puVar9 = (ulong *)((long)puVar9 + 0x2c);
          } while (uVar7 < uVar3);
        }
        lVar2 = dma_alloc_attrs(*param_1,0x2c,plVar1 + 5,0xcc0,0);
        plVar1[2] = lVar2;
        if (lVar2 != 0) {
          plVar11 = (long *)param_1[0x27];
          plVar11[7] = 0x10;
          plVar11[8] = 0x800;
          plVar11[9] = 0x80;
          plVar11[10] = 0xfff;
          lVar10 = dma_alloc_attrs(*param_1,0xfff,plVar11,0xcc0,0);
          plVar11[3] = lVar10;
          if (lVar10 != 0) {
            uVar6 = *plVar11 + 0x7ffU & 0xfffffffffffff800;
            lVar10 = lVar10 + (uVar6 - *plVar11);
            plVar11[1] = uVar6;
            plVar11[5] = lVar10;
            plVar11[6] = lVar10;
            plVar11[4] = lVar10;
            *(ulong *)(lVar2 + 0x24) = uVar6;
            *(ulong *)(lVar2 + 0xc) = uVar6;
            *(ulong *)(lVar2 + 0x1c) = uVar6;
            *(long *)(lVar2 + 0x14) = plVar11[8];
            plVar11[2] = lVar2 + 0x24;
            param_1[0x28] = plVar1;
            return 0;
          }
          dma_free_attrs(*param_1,0x2c,plVar1[2],plVar1[5],0);
          uVar7 = *(uint *)((long)param_1 + 0xc4);
          lVar10 = param_1[0x26] + (long)(int)uVar7 * 0x118;
        }
LAB_0010301c:
        iVar8 = uVar7 - 1;
        if (-1 < iVar8) {
          puVar12 = (undefined8 *)(lVar10 + -0xf0);
          do {
            if (*(char *)((long)puVar12 + 0xea) == '\0') {
              dma_free_attrs(*param_1,puVar12[10],puVar12[3],*puVar12,0);
            }
            iVar8 = iVar8 + -1;
            puVar12 = puVar12 + -0x23;
          } while (-1 < iVar8);
        }
        dma_free_attrs(*param_1,(ulong)*(uint *)((long)param_1 + 0xc4) * 0x2c,*plVar1,plVar1[3],0);
      }
      dma_free_attrs(*param_1,(ulong)*(uint *)(param_1 + 0x18) * 0x2c,plVar1[1],plVar1[4],0);
    }
    kfree(plVar1);
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// mhi_init_mmio @ 001030cc size=940
// signature: undefined mhi_init_mmio(void)
// callers: [mhi_ready_state_transition]
//------------------------------------------------------------

int mhi_init_mmio(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  uint local_c4 [31];
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + 0x140);
  local_c4[0] = 0;
  local_c4[1] = 0x5c;
  lVar11 = *(long *)(param_1 + 8);
  lVar10 = *(long *)(param_1 + 0x18);
  local_c4[0x1d] = 0;
  local_c4[0x1e] = 0;
  local_c4[8] = (uint)*(undefined8 *)(lVar7 + 0x18);
  local_c4[7] = 0x60;
  local_c4[4] = (uint)*(undefined8 *)(lVar7 + 0x20);
  local_c4[3] = 0x58;
  local_c4[6] = (uint)((ulong)*(undefined8 *)(lVar7 + 0x18) >> 0x20);
  local_c4[5] = 100;
  local_c4[2] = (uint)((ulong)*(undefined8 *)(lVar7 + 0x20) >> 0x20);
  local_c4[0xc] = (uint)*(undefined8 *)(lVar7 + 0x28);
  local_c4[0xb] = 0x68;
  local_c4[10] = (uint)((ulong)*(undefined8 *)(lVar7 + 0x28) >> 0x20);
  local_c4[9] = 0x6c;
  local_c4[0x10] = *(undefined4 *)(param_1 + 0x40);
  local_c4[0xe] = *(undefined4 *)(param_1 + 0x44);
  local_c4[0xd] = 0x84;
  local_c4[0xf] = 0x80;
  local_c4[0x11] = 0x9c;
  local_c4[0x13] = 0x98;
  local_c4[0x18] = *(undefined4 *)(param_1 + 0x48);
  local_c4[0x16] = *(undefined4 *)(param_1 + 0x4c);
  local_c4[0x15] = 0x8c;
  local_c4[0x17] = 0x88;
  lVar7 = *(long *)(lVar11 + 0xc0);
  local_c4[0x1b] = 0xa0;
  local_c4[0x19] = 0xa4;
  local_c4[0x12] = local_c4[0xe];
  local_c4[0x14] = local_c4[0x10];
  local_c4[0x1a] = local_c4[0x16];
  local_c4[0x1c] = local_c4[0x18];
  if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[D][%s] Initializing MHI registers\n",
                   "mhi_init_mmio");
  }
  iVar2 = mhi_read_reg(param_1,lVar10,0x18,local_c4);
  if (iVar2 == 0) {
    uVar5 = (ulong)local_c4[0];
    if (uVar5 < *(long *)(param_1 + 0x80) - 0x3f8U) {
      *(undefined1 *)(param_1 + 0x2a7) = 0;
      *(ulong *)(param_1 + 0x30) = lVar10 + uVar5 + 0x3f8;
      if (*(int *)(param_1 + 0xc0) != 0) {
        uVar6 = 0;
        plVar9 = (long *)(*(long *)(param_1 + 0xa0) + 0xc0);
        do {
          lVar7 = lVar10 + uVar5;
          uVar6 = uVar6 + 1;
          local_c4[0] = (int)uVar5 + 8;
          uVar5 = (ulong)local_c4[0];
          *plVar9 = lVar7;
          plVar9 = plVar9 + 0x32;
        } while (uVar6 < *(uint *)(param_1 + 0xc0));
      }
      iVar2 = mhi_read_reg(param_1,lVar10,0x20,local_c4);
      if (iVar2 != 0) {
        lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        _dev_err(lVar11 + 0x28,"[E][%s] Unable to read ERDBOFF register\n","mhi_init_mmio");
        if ((lVar7 == 0) || (2 < *(uint *)(lVar7 + 0x18))) goto LAB_00103404;
        uVar3 = *(undefined8 *)(lVar7 + 0x20);
        pcVar4 = "[E][%s] Unable to read ERDBOFF register\n";
        goto LAB_001033f0;
      }
      uVar6 = *(uint *)(param_1 + 0xc4);
      uVar5 = (ulong)local_c4[0];
      if (uVar5 < *(long *)(param_1 + 0x80) - (ulong)(uVar6 << 3)) {
        if (uVar6 != 0) {
          uVar8 = 0;
          pcVar4 = (char *)(*(long *)(param_1 + 0x130) + 0x112);
          do {
            if (*pcVar4 == '\0') {
              *(ulong *)(pcVar4 + -0x92) = lVar10 + uVar5;
              uVar6 = *(uint *)(param_1 + 0xc4);
            }
            uVar8 = uVar8 + 1;
            local_c4[0] = (int)uVar5 + 8;
            uVar5 = (ulong)local_c4[0];
            pcVar4 = pcVar4 + 0x118;
          } while (uVar8 < uVar6);
        }
        lVar7 = 0;
        *(long *)(*(long *)(param_1 + 0x138) + 0x58) = lVar10 + 0x70;
        while (iVar2 = *(int *)((long)local_c4 + lVar7 + 4), iVar2 != 0) {
          mhi_write_reg(param_1,lVar10,iVar2,*(undefined4 *)((long)local_c4 + lVar7 + 8));
          lVar7 = lVar7 + 8;
          if (lVar7 == 0x78) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1032ec);
            (*pcVar1)();
          }
        }
        iVar2 = mhi_write_reg_field(param_1,lVar10,0x10,0xff0000,*(undefined4 *)(param_1 + 0xc4));
        if ((iVar2 == 0) &&
           (iVar2 = mhi_write_reg_field(param_1,lVar10,0x10,0xff000000,
                                        *(undefined4 *)(param_1 + 200)), iVar2 == 0)) {
          mhi_misc_init_mmio(param_1);
        }
        else {
          lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar11 + 0x28,"[E][%s] Unable to write MHICFG register\n","mhi_init_mmio");
          if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
            ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] Unable to write MHICFG register\n"
                           ,"mhi_init_mmio");
          }
        }
        goto LAB_00103330;
      }
      pcVar4 = "ERDB offset: 0x%x is out of range: 0x%zx\n";
    }
    else {
      pcVar4 = "CHDB offset: 0x%x is out of range: 0x%zx\n";
    }
    _dev_err(lVar11 + 0x28,pcVar4);
    iVar2 = -0x22;
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar11 + 0x28,"[E][%s] Unable to read CHDBOFF register\n","mhi_init_mmio");
    if ((lVar7 == 0) || (2 < *(uint *)(lVar7 + 0x18))) {
LAB_00103404:
      iVar2 = -5;
      goto LAB_00103330;
    }
    uVar3 = *(undefined8 *)(lVar7 + 0x20);
    pcVar4 = "[E][%s] Unable to read CHDBOFF register\n";
LAB_001033f0:
    ipc_log_string(uVar3,pcVar4,"mhi_init_mmio");
    iVar2 = -5;
  }
LAB_00103330:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_deinit_chan_ctxt @ 0010347c size=148
// signature: undefined mhi_deinit_chan_ctxt(void)
// callers: [mhi_unprepare_channel, mhi_prepare_channel]
//------------------------------------------------------------

void mhi_deinit_chan_ctxt(undefined8 *param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar2 = *(long *)(param_1[0x28] + 8);
  lVar3 = lVar2 + (ulong)*(uint *)(param_2 + 200) * 0x2c;
  if (*(long *)(lVar3 + 0xc) != 0) {
    lVar4 = (ulong)*(uint *)(param_2 + 200) * 0x2c;
    dma_free_attrs(*param_1,*(undefined8 *)(param_2 + 0xb8),*(undefined8 *)(param_2 + 0x80),
                   *(undefined8 *)(param_2 + 0x68),0);
    vfree(*(undefined8 *)(param_2 + 0x28));
    *(undefined8 *)(param_2 + 0x88) = 0;
    *(undefined8 *)(param_2 + 0x28) = 0;
    *(undefined8 *)(param_2 + 0x78) = 0;
    uVar1 = *(uint *)(lVar2 + lVar4);
    *(undefined8 *)(lVar3 + 0x1c) = 0;
    *(undefined8 *)(lVar3 + 0x24) = 0;
    *(long *)(lVar3 + 0xc) = 0;
    *(undefined8 *)(lVar3 + 0x14) = 0;
    *(uint *)(lVar2 + lVar4) = uVar1 & 0xffffff00;
    DataMemoryBarrier(2,2);
  }
  return;
}



//------------------------------------------------------------
// mhi_init_chan_ctxt @ 00103514 size=300
// signature: undefined mhi_init_chan_ctxt(void)
// callers: [mhi_prepare_channel]
//------------------------------------------------------------

undefined8 mhi_init_chan_ctxt(undefined8 *param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  
  lVar4 = *(long *)(param_2 + 0xb0);
  lVar7 = lVar4 * 0x10;
  uVar1 = *(uint *)(param_2 + 200);
  *(undefined8 *)(param_2 + 0xa0) = 0x10;
  *(long *)(param_2 + 0xa8) = lVar7;
  lVar2 = lVar7 + -1 + lVar7;
  lVar6 = *(long *)(param_1[0x28] + 8);
  *(long *)(param_2 + 0xb8) = lVar2;
  lVar2 = dma_alloc_attrs(*param_1,lVar2,param_2 + 0x68,0xcc0,0);
  *(long *)(param_2 + 0x80) = lVar2;
  if (lVar2 != 0) {
    uVar5 = *(long *)(param_2 + 0x68) + lVar7 + -1 & lVar4 * -0x10;
    *(ulong *)(param_2 + 0x70) = uVar5;
    *(ulong *)(param_2 + 0x88) = lVar2 + (uVar5 - *(long *)(param_2 + 0x68));
    *(undefined8 *)(param_2 + 0x40) = 0x38;
    *(long *)(param_2 + 0x48) = *(long *)(param_2 + 0x50) * 0x38;
    lVar2 = vzalloc();
    *(long *)(param_2 + 0x28) = lVar2;
    if (lVar2 != 0) {
      lVar2 = lVar6 + (ulong)uVar1 * 0x2c;
      *(undefined1 *)(lVar6 + (ulong)uVar1 * 0x2c) = 1;
      uVar3 = *(undefined8 *)(param_2 + 0x70);
      *(undefined8 *)(lVar2 + 0x24) = uVar3;
      *(undefined8 *)(lVar2 + 0xc) = uVar3;
      *(undefined8 *)(lVar2 + 0x1c) = uVar3;
      *(undefined8 *)(lVar2 + 0x14) = *(undefined8 *)(param_2 + 0xa8);
      *(undefined8 **)(param_2 + 0x78) = (undefined8 *)(lVar2 + 0x24);
      *(undefined1 *)(param_2 + 0xe1) = 1;
      *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_2 + 0x88);
      *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(param_2 + 0x88);
      *(undefined8 *)(param_2 + 0x30) = *(undefined8 *)(param_2 + 0x28);
      *(undefined8 *)(param_2 + 0x38) = *(undefined8 *)(param_2 + 0x28);
      DataMemoryBarrier(2,2);
      return 0;
    }
    dma_free_attrs(*param_1,*(undefined8 *)(param_2 + 0xb8),*(undefined8 *)(param_2 + 0x80),
                   *(undefined8 *)(param_2 + 0x68),0);
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// mhi_register_controller @ 00103644 size=1140
// signature: undefined mhi_register_controller(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mhi_register_controller(long *param_1)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  local_5c = 0;
  if ((((((param_1 != (long *)0x0) && (*param_1 != 0)) && (param_1[3] != 0)) &&
       ((param_1[0x49] != 0 && (param_1[0x4b] != 0)))) &&
      ((param_1[0x45] != 0 && ((param_1[0x50] != 0 && (param_1[0x51] != 0)))))) &&
     (((int)param_1[0x1a] != 0 && ((param_1[0x17] != 0 && (param_1[0x10] != 0)))))) {
    param_1[4] = 0;
    param_1[5] = 0;
    iVar6 = parse_config(param_1);
    if (iVar6 == 0) {
      lVar8 = kmalloc_trace(___init_waitqueue_head,0xdc0,0x68);
      param_1[0x27] = lVar8;
      if (lVar8 == 0) {
        uVar10 = 0xfffffff4;
      }
      else {
        param_1[0x36] = (long)(param_1 + 0x36);
        param_1[0x37] = (long)(param_1 + 0x36);
        __mutex_init(param_1 + 0x29,"&mhi_cntrl->pm_mutex",&mhi_register_controller___key);
        param_1[0x3b] = 0xfffffffe0;
        param_1[0x2f] = 0;
        param_1[0x38] = 0;
        param_1[0x3c] = (long)(param_1 + 0x3c);
        param_1[0x3d] = (long)(param_1 + 0x3c);
        param_1[0x3e] = (long)mhi_pm_st_worker;
        __init_waitqueue_head
                  (param_1 + 0x42,"&mhi_cntrl->state_event",&mhi_register_controller___key_29);
        lVar8 = alloc_workqueue("mhi_hiprio_wq",0xa0012,1);
        param_1[0x41] = lVar8;
        if (lVar8 == 0) {
          _dev_err(*param_1,"Failed to allocate workqueue\n");
          uVar10 = 0xfffffff4;
        }
        else {
          *(undefined4 *)(param_1[0x27] + 0x60) = 0;
          if (*(int *)((long)param_1 + 0xc4) != 0) {
            lVar8 = 0;
            uVar7 = 0;
            lVar11 = param_1[0x26];
            do {
              plVar1 = (long *)(lVar11 + lVar8);
              if (*(char *)((long)plVar1 + 0x112) == '\0') {
                *plVar1 = (long)param_1;
                *(undefined4 *)(plVar1 + 0x20) = 0;
                if ((int)plVar1[4] == 2) {
                  lVar2 = lVar11 + lVar8;
                  *(undefined8 *)(lVar2 + 0xd0) = 0xfffffffe0;
                  *(long *)(lVar2 + 0xd8) = lVar2 + 0xd8;
                  *(long *)(lVar2 + 0xe0) = lVar2 + 0xd8;
                  *(code **)(lVar2 + 0xe8) = mhi_process_ev_work;
                }
                else {
                  pcVar3 = mhi_ctrl_ev_task;
                  if (*(int *)(lVar11 + lVar8 + 0x24) != 1) {
                    pcVar3 = mhi_ev_task;
                  }
                  tasklet_init(lVar11 + lVar8 + 0xa8,pcVar3);
                }
              }
              uVar7 = uVar7 + 1;
              lVar8 = lVar8 + 0x118;
            } while (uVar7 < *(uint *)((long)param_1 + 0xc4));
          }
          if ((int)param_1[0x18] != 0) {
            uVar7 = 0;
            lVar8 = param_1[0x14] + 0x174;
            do {
              __mutex_init(lVar8 + -0x54,"&mhi_chan->mutex",&mhi_register_controller___key_33);
              *(undefined4 *)(lVar8 + -0x24) = 0;
              __init_swait_queue_head(lVar8 + -0x1c,"&x->wait",&init_completion___key);
              *(undefined8 *)(lVar8 + -4) = 0;
              uVar7 = uVar7 + 1;
              *(undefined4 *)(lVar8 + -0xa4) =
                   *(undefined4 *)(param_1[0x26] + (ulong)*(uint *)(lVar8 + -0xa8) * 0x118 + 0x14);
              lVar8 = lVar8 + 400;
            } while (uVar7 < *(uint *)(param_1 + 0x18));
          }
          bVar5 = *(char *)((long)param_1 + 0x2a5) != '\0';
          pcVar3 = mhi_map_single_no_bb;
          if (bVar5) {
            pcVar3 = mhi_map_single_use_bb;
          }
          pcVar4 = mhi_unmap_single_no_bb;
          if (bVar5) {
            pcVar4 = mhi_unmap_single_use_bb;
          }
          param_1[0x4e] = (long)pcVar3;
          param_1[0x4f] = (long)pcVar4;
          uVar9 = mhi_read_reg(param_1,param_1[3],0x224,&local_5c);
          uVar10 = uVar9 & 0xffffffff;
          if ((int)uVar9 == 0) {
            *(uint *)((long)param_1 + 0xd4) = local_5c >> 0x1c;
            *(uint *)(param_1 + 0x1b) = local_5c >> 0x10 & 0xfff;
            *(uint *)((long)param_1 + 0xdc) = local_5c >> 8 & 0xff;
            *(uint *)(param_1 + 0x1c) = local_5c & 0xff;
            uVar7 = ida_alloc_range(&mhi_controller_ida,0,0xffffffff,0xcc0);
            *(uint *)(param_1 + 0x54) = uVar7;
            if ((int)uVar7 < 0) {
              uVar10 = (ulong)uVar7;
            }
            else {
              uVar9 = mhi_init_irq_setup(param_1);
              uVar10 = uVar9 & 0xffffffff;
              if ((int)uVar9 == 0) {
                uVar10 = mhi_alloc_device(param_1);
                if (uVar10 < 0xfffffffffffff001) {
                  *(long **)(uVar10 + 0x10) = param_1;
                  plVar1 = (long *)(uVar10 + 0x28);
                  *(undefined4 *)(uVar10 + 0x3b8) = 1;
                  dev_set_name(plVar1,"mhi%d",(int)param_1[0x54]);
                  lVar8 = *(long *)(uVar10 + 0x98);
                  if (lVar8 == 0) {
                    lVar8 = *plVar1;
                  }
                  *(long *)(uVar10 + 8) = lVar8;
                  device_set_wakeup_capable(plVar1,1);
                  device_wakeup_enable(plVar1);
                  param_1[1] = uVar10;
                  uVar7 = mhi_misc_register_controller(param_1);
                  if (uVar7 != 0) {
                    uVar10 = (ulong)uVar7;
                    _dev_err(*param_1,"Could not enable miscellaneous features\n");
                    param_1[1] = 0;
                    goto LAB_00103a28;
                  }
                  uVar9 = device_add(plVar1);
                  uVar10 = uVar9 & 0xffffffff;
                  if ((int)uVar9 == 0) {
                    uVar9 = mhi_misc_sysfs_create(param_1);
                    uVar10 = uVar9 & 0xffffffff;
                    if ((int)uVar9 == 0) goto LAB_001036e0;
                    device_del(plVar1);
                  }
                  mhi_misc_unregister_controller(param_1);
                }
                else {
                  _dev_err(*param_1,"Failed to allocate MHI device\n");
                }
                mhi_deinit_free_irq(param_1);
              }
LAB_00103a28:
              ida_free(&mhi_controller_ida,(int)param_1[0x54]);
            }
          }
          destroy_workqueue(param_1[0x41]);
        }
        kfree(param_1[0x27]);
      }
      kfree(param_1[0x26]);
      vfree(param_1[0x14]);
      goto LAB_001036e0;
    }
  }
  uVar10 = 0xffffffea;
LAB_001036e0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// parse_config @ 00103ab8 size=1372
// signature: undefined parse_config(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

undefined8 parse_config(undefined8 *param_1,uint *param_2)

{
  undefined8 *puVar1;
  long *plVar2;
  uint *puVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  undefined1 auVar12 [16];
  long lVar13;
  ulong uVar14;
  char *pcVar15;
  uint uVar16;
  undefined4 uVar17;
  uint uVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  undefined8 uVar21;
  long lVar22;
  uint *puVar23;
  long lVar24;
  undefined8 uVar25;
  long lVar26;
  
  uVar18 = *param_2;
  uVar25 = *param_1;
  *(uint *)(param_1 + 0x18) = uVar18;
  lVar13 = vzalloc((ulong)uVar18 * 400);
  param_1[0x14] = lVar13;
  if (lVar13 == 0) {
    uVar25 = 0xfffffff4;
  }
  else {
    puVar1 = param_1 + 0x15;
    param_1[0x15] = puVar1;
    param_1[0x16] = puVar1;
    if (param_2[3] != 0) {
      uVar18 = 0;
      do {
        lVar13 = *(long *)(param_2 + 4);
        uVar16 = *(uint *)(lVar13 + (long)(int)uVar18 * 0x38 + 8);
        if (*(uint *)(param_1 + 0x18) <= uVar16) {
          lVar13 = *(long *)(param_1[1] + 0xc0);
          _dev_err(uVar25,"[E][%s] Channel %d not available\n","parse_ch_cfg",uVar16);
          if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x20),"[E][%s] Channel %d not available\n",
                           "parse_ch_cfg",uVar16);
          }
          goto LAB_00103f74;
        }
        lVar26 = param_1[0x14];
        puVar19 = (undefined8 *)(lVar13 + (long)(int)uVar18 * 0x38);
        puVar20 = (undefined8 *)(lVar26 + (ulong)uVar16 * 400);
        uVar21 = *puVar19;
        *(uint *)(puVar20 + 0x19) = uVar16;
        *puVar20 = uVar21;
        uVar6 = *(uint *)((long)puVar19 + 0xc);
        puVar20[0x16] = (ulong)uVar6;
        if (uVar6 == 0) goto LAB_00103f74;
        lVar22 = lVar13 + (long)(int)uVar18 * 0x38;
        lVar24 = lVar26 + (ulong)uVar16 * 400;
        uVar14 = (ulong)uVar6;
        if (*(uint *)(lVar22 + 0x10) != 0) {
          uVar14 = (ulong)*(uint *)(lVar22 + 0x10);
        }
        *(ulong *)(lVar24 + 0x50) = uVar14;
        *(undefined4 *)(lVar24 + 0xcc) = *(undefined4 *)(lVar22 + 0x14);
        iVar7 = *(int *)(lVar22 + 0x18);
        *(int *)(lVar24 + 0xd8) = iVar7;
        iVar4 = iVar7;
        if (*(int *)(lVar22 + 0x1c) != 0) {
          iVar4 = *(int *)(lVar22 + 0x1c);
        }
        *(int *)(lVar24 + 0xd4) = iVar4;
        *(undefined4 *)(lVar24 + 0x100) = *(undefined4 *)(lVar22 + 0x20);
        *(undefined4 *)(lVar24 + 0xe4) = *(undefined4 *)(lVar22 + 0x24);
        cVar9 = *(char *)(lVar22 + 0x2c);
        *(char *)(lVar24 + 0x188) = cVar9;
        cVar10 = *(char *)(lVar22 + 0x2d);
        *(char *)(lVar24 + 0x18a) = cVar10;
        *(undefined1 *)(lVar24 + 0xe0) = *(undefined1 *)(lVar22 + 0x2e);
        cVar11 = *(char *)(lVar22 + 0x2f);
        *(char *)(lVar24 + 0x18b) = cVar11;
        *(undefined1 *)(lVar24 + 0x18c) = *(undefined1 *)(lVar22 + 0x30);
        if (cVar11 != '\0') {
          if (iVar7 == 2) goto LAB_00103bf8;
LAB_00103eb0:
          lVar13 = *(long *)(param_1[1] + 0xc0);
          _dev_err(uVar25,"[E][%s] Invalid channel configuration\n","parse_ch_cfg");
          if ((lVar13 == 0) || (2 < *(uint *)(lVar13 + 0x18))) goto LAB_00103f74;
          uVar25 = *(undefined8 *)(lVar13 + 0x20);
          pcVar15 = "[E][%s] Invalid channel configuration\n";
LAB_00103f68:
          ipc_log_string(uVar25,pcVar15,"parse_ch_cfg");
LAB_00103f74:
          vfree(param_1[0x14]);
          return 0xffffffea;
        }
        if ((iVar7 == 3) || (iVar7 == 0)) {
          if (cVar10 == '\0') goto LAB_00103eb0;
        }
        else {
LAB_00103bf8:
          if ((cVar10 == '\0') &&
             (uVar6 = *(uint *)(lVar13 + (long)(int)uVar18 * 0x38 + 0x28),
             *(uint *)(lVar26 + (ulong)uVar16 * 400 + 0xe8) = uVar6, (uVar6 & 0xfffffffe) != 2)) {
            lVar13 = *(long *)(param_1[1] + 0xc0);
            _dev_err(uVar25,"[E][%s] Invalid Door bell mode\n","parse_ch_cfg");
            if ((lVar13 == 0) || (2 < *(uint *)(lVar13 + 0x18))) goto LAB_00103f74;
            uVar25 = *(undefined8 *)(lVar13 + 0x20);
            pcVar15 = "[E][%s] Invalid Door bell mode\n";
            goto LAB_00103f68;
          }
        }
        lVar13 = lVar26 + (ulong)uVar16 * 400;
        pcVar5 = mhi_db_brstmode;
        if (*(int *)(lVar13 + 0xe8) != 3) {
          pcVar5 = mhi_db_brstmode_disable;
        }
        *(code **)(lVar13 + 0xf8) = pcVar5;
        *(undefined1 *)(lVar13 + 0x189) = 1;
        if (cVar9 != '\0') {
          puVar19 = (undefined8 *)param_1[0x16];
          plVar2 = (long *)(lVar26 + (ulong)uVar16 * 400 + 0x178);
          uVar14 = __list_add_valid(plVar2,puVar19,puVar1);
          if ((uVar14 & 1) != 0) {
            param_1[0x16] = plVar2;
            *plVar2 = (long)puVar1;
            *(undefined8 **)(lVar26 + (ulong)uVar16 * 400 + 0x180) = puVar19;
            *puVar19 = plVar2;
          }
        }
        uVar18 = uVar18 + 1;
      } while (uVar18 < param_2[3]);
    }
    uVar18 = param_2[6];
    uVar25 = *param_1;
    auVar12._8_8_ = 0;
    auVar12._0_8_ = (long)(int)uVar18;
    *(uint *)((long)param_1 + 0xc4) = uVar18;
    if (SUB168(auVar12 * ZEXT816(0x118),8) == 0) {
      lVar13 = __kmalloc((long)(int)uVar18 * 0x118,0xdc0);
      param_1[0x26] = lVar13;
      if (lVar13 != 0) {
        if (0 < (int)uVar18) {
          uVar16 = 0;
          lVar26 = 0;
          puVar23 = (uint *)(lVar13 + 0x90);
          do {
            lVar13 = *(long *)(param_2 + 8);
            puVar23[-0x20] = uVar16;
            puVar3 = (uint *)(lVar13 + lVar26);
            *(ulong *)(puVar23 + -8) = (ulong)*puVar3;
            puVar23[-0x1f] = puVar3[1];
            puVar23[-0x1e] = puVar3[2];
            uVar6 = puVar3[3];
            if (uVar6 != 0xffffffff) {
              uVar8 = *(uint *)(param_1 + 0x18);
              puVar23[-0x1d] = uVar6;
              if (uVar6 < uVar8) {
                *(long *)(puVar23 + -0x22) = param_1[0x14] + (long)(int)uVar6 * 400;
                goto LAB_00103d84;
              }
              lVar13 = *(long *)(param_1[1] + 0xc0);
              _dev_err(uVar25,"[E][%s] Event Ring channel not available\n","parse_ev_cfg");
              if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
                pcVar15 = "[E][%s] Event Ring channel not available\n";
LAB_00103fbc:
                ipc_log_string(*(undefined8 *)(lVar13 + 0x20),pcVar15,"parse_ev_cfg");
              }
LAB_00103fcc:
              kfree(param_1[0x26]);
              uVar25 = 0xffffffea;
              goto LAB_00103fd8;
            }
LAB_00103d84:
            puVar23[-0x1c] = puVar3[4];
            uVar6 = puVar3[5];
            *puVar23 = uVar6;
            if ((uVar6 & 0xfffffffe) != 2) goto LAB_00103fcc;
            pcVar5 = mhi_db_brstmode;
            if (uVar6 != 3) {
              pcVar5 = mhi_db_brstmode_disable;
            }
            *(code **)(puVar23 + 4) = pcVar5;
            uVar6 = *(uint *)(lVar13 + lVar26 + 0x18);
            puVar23[-0x1b] = uVar6;
            if (3 < uVar6) {
              lVar13 = *(long *)(param_1[1] + 0xc0);
              _dev_err(uVar25,"[E][%s] Event Ring type not supported\n","parse_ev_cfg");
              if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
                pcVar15 = "[E][%s] Event Ring type not supported\n";
                goto LAB_00103fbc;
              }
              goto LAB_00103fcc;
            }
            *(undefined **)(puVar23 + 0x1e) =
                 (&PTR_mhi_process_data_event_ring_00116000)[(int)uVar6];
            cVar9 = *(char *)(lVar13 + lVar26 + 0x1c);
            *(char *)(puVar23 + 0x20) = cVar9;
            if (cVar9 == '\0') {
              *(int *)((long)param_1 + 0xcc) = *(int *)((long)param_1 + 0xcc) + 1;
            }
            else {
              *(int *)(param_1 + 0x19) = *(int *)(param_1 + 0x19) + 1;
            }
            lVar13 = lVar13 + lVar26;
            lVar26 = lVar26 + 0x20;
            uVar16 = uVar16 + 1;
            *(undefined1 *)((long)puVar23 + 0x81) = *(undefined1 *)(lVar13 + 0x1d);
            *(undefined1 *)((long)puVar23 + 0x82) = *(undefined1 *)(lVar13 + 0x1e);
            puVar23 = puVar23 + 0x46;
          } while ((ulong)uVar18 * 0x20 != lVar26);
        }
        uVar18 = 1000;
        if (param_2[1] != 0) {
          uVar18 = param_2[1];
        }
        *(uint *)(param_1 + 0x30) = uVar18;
        if (param_2[0xb] != 0) {
          param_1[5] = param_1[3] + (ulong)param_2[0xb];
        }
        *(char *)((long)param_1 + 0x2a5) = (char)param_2[10];
        uVar18 = 0xffff;
        if (param_2[2] != 0) {
          uVar18 = param_2[2];
        }
        param_1[0x53] = (ulong)uVar18;
        *(undefined4 *)(param_1 + 0x31) = 0xc;
        uVar17 = 0xc;
        if (*(char *)((long)param_2 + 0x29) != '\0') {
          uVar17 = 4;
        }
        *(undefined4 *)(param_1 + 0x31) = uVar17;
        return 0;
      }
      uVar25 = 0xfffffff4;
    }
    else {
      uVar25 = 0xfffffff4;
      param_1[0x26] = 0;
    }
LAB_00103fd8:
    vfree(param_1[0x14]);
  }
  return uVar25;
}



//------------------------------------------------------------
// mhi_alloc_device @ 00104018 size=140
// signature: undefined mhi_alloc_device(void)
// callers: [mhi_create_devices, mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long mhi_alloc_device(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = kmalloc_trace(___init_swait_queue_head,0xdc0,0x3d8);
  if (lVar1 == 0) {
    lVar1 = -0xc;
  }
  else {
    device_initialize(lVar1 + 0x28);
    lVar2 = param_1[1];
    *(undefined ***)(lVar1 + 0xa8) = &mhi_bus_type;
    *(code **)(lVar1 + 0x350) = mhi_release_device;
    if (lVar2 == 0) {
      lVar2 = *param_1;
    }
    else {
      lVar2 = lVar2 + 0x28;
    }
    *(long *)(lVar1 + 0x88) = lVar2;
    *(long **)(lVar1 + 0x10) = param_1;
    *(undefined4 *)(lVar1 + 0x3cc) = 0;
  }
  return lVar1;
}



//------------------------------------------------------------
// mhi_unregister_controller @ 001040a8 size=344
// signature: undefined mhi_unregister_controller(void)
// callers: []
//------------------------------------------------------------

void mhi_unregister_controller(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  uint uVar6;
  
  lVar3 = *(long *)(param_1 + 8);
  uVar1 = *(uint *)(param_1 + 0xc4);
  lVar4 = *(long *)(param_1 + 0xa0);
  if (uVar1 != 0) {
    uVar6 = 0;
    lVar2 = *(long *)(param_1 + 0x130);
    do {
      if (*(char *)(lVar2 + 0x112) == '\0') {
        free_irq(*(undefined4 *)(*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(lVar2 + 0x18) * 4),
                 lVar2);
        uVar1 = *(uint *)(param_1 + 0xc4);
      }
      uVar6 = uVar6 + 1;
      lVar2 = lVar2 + 0x118;
    } while (uVar6 < uVar1);
  }
  free_irq(**(undefined4 **)(param_1 + 0xb8),param_1);
  mhi_misc_unregister_controller(param_1);
  mhi_misc_sysfs_destroy(param_1);
  if (*(char *)(param_1 + 0x2a4) != '\0') {
    *(undefined1 *)(param_1 + 0x2a4) = 0;
    if (*(long *)(param_1 + 0x88) != 0) {
      mhi_free_bhie_table(param_1);
    }
    if (*(long *)(param_1 + 0x90) != 0) {
      mhi_free_bhie_table(param_1);
    }
  }
  destroy_workqueue(*(undefined8 *)(param_1 + 0x208));
  kfree(*(undefined8 *)(param_1 + 0x138));
  kfree(*(undefined8 *)(param_1 + 0x130));
  uVar1 = *(uint *)(param_1 + 0xc0);
  if (uVar1 != 0) {
    uVar6 = 0;
    plVar5 = (long *)(lVar4 + 0x110);
    do {
      if (*plVar5 != 0) {
        put_device(*plVar5 + 0x28);
        uVar1 = *(uint *)(param_1 + 0xc0);
      }
      uVar6 = uVar6 + 1;
      plVar5 = plVar5 + 0x32;
    } while (uVar6 < uVar1);
  }
  vfree(*(undefined8 *)(param_1 + 0xa0));
  lVar3 = lVar3 + 0x28;
  device_del(lVar3);
  put_device(lVar3);
  ida_free(&mhi_controller_ida,*(undefined4 *)(param_1 + 0x2a0));
  return;
}



//------------------------------------------------------------
// mhi_alloc_controller @ 00104204 size=44
// signature: undefined mhi_alloc_controller(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_alloc_controller(void)

{
  kmalloc_trace(___init_swait_queue_head,0xdc0,0x2b8);
  return;
}



//------------------------------------------------------------
// mhi_free_controller @ 00104234 size=28
// signature: undefined mhi_free_controller(void)
// callers: []
//------------------------------------------------------------

void mhi_free_controller(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// mhi_prepare_for_power_up @ 00104254 size=676
// signature: undefined mhi_prepare_for_power_up(void)
// callers: []
//------------------------------------------------------------

int mhi_prepare_for_power_up(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 8);
  local_50 = 0;
  mutex_lock(param_1 + 0x148);
  iVar2 = mhi_init_dev_ctxt(param_1);
  if (iVar2 != 0) goto LAB_001044b8;
  iVar2 = mhi_read_reg(param_1,*(undefined8 *)(param_1 + 0x18),0x28,(long)&local_50 + 4);
  if (iVar2 == 0) {
    if (local_50 >> 0x20 < *(ulong *)(param_1 + 0x80)) {
      lVar5 = *(long *)(param_1 + 0x28);
      *(ulong *)(param_1 + 0x20) = *(long *)(param_1 + 0x18) + (local_50 >> 0x20);
      if ((lVar5 == 0) &&
         ((*(char *)(param_1 + 0x2a6) != '\0' || (lVar5 = 0, *(long *)(param_1 + 0x68) != 0)))) {
        iVar2 = mhi_read_reg(param_1,*(long *)(param_1 + 0x18),0x2c,&local_50);
        if (iVar2 != 0) {
          lVar5 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar6 + 0x28,"[E][%s] Error getting BHIE offset\n","mhi_prepare_for_power_up");
          if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x18) < 3)) {
            uVar3 = *(undefined8 *)(lVar5 + 0x20);
            pcVar4 = "[E][%s] Error getting BHIE offset\n";
            goto LAB_0010444c;
          }
          goto LAB_001044b0;
        }
        if (*(ulong *)(param_1 + 0x80) <= (local_50 & 0xffffffff)) {
          lVar5 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar6 + 0x28,"[E][%s] BHIe offset: 0x%x is out of range: 0x%zx\n",
                   "mhi_prepare_for_power_up");
          if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x18) < 3)) {
            uVar3 = *(undefined8 *)(lVar5 + 0x20);
            pcVar4 = "[E][%s] BHIe offset: 0x%x is out of range: 0x%zx\n";
            uVar1 = (undefined4)local_50;
            goto LAB_0010449c;
          }
          goto LAB_001044ac;
        }
        lVar5 = *(long *)(param_1 + 0x18) + (local_50 & 0xffffffff);
        *(long *)(param_1 + 0x28) = lVar5;
      }
      lVar6 = *(long *)(param_1 + 0x68);
      if (lVar6 != 0) {
        if ((lVar5 + 0x60U & 0xf) == 0) {
          __memset_io(lVar5 + 0x60U,0,0x1c);
          lVar6 = *(long *)(param_1 + 0x68);
        }
        mhi_alloc_bhie_table(param_1,param_1 + 0x90,lVar6);
        if (*(long *)(param_1 + 0x90) != 0) {
          iVar2 = mhi_rddm_prepare(param_1);
          if (iVar2 == 0) goto LAB_001044b8;
          mhi_free_bhie_table(param_1,param_1 + 0x90);
          goto LAB_001044b0;
        }
      }
      iVar2 = 0;
      goto LAB_001044b8;
    }
    lVar5 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar6 + 0x28,"[E][%s] BHI offset: 0x%x is out of range: 0x%zx\n",
             "mhi_prepare_for_power_up");
    if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x18) < 3)) {
      uVar3 = *(undefined8 *)(lVar5 + 0x20);
      pcVar4 = "[E][%s] BHI offset: 0x%x is out of range: 0x%zx\n";
      uVar1 = local_50._4_4_;
LAB_0010449c:
      ipc_log_string(uVar3,pcVar4,"mhi_prepare_for_power_up",uVar1,*(undefined8 *)(param_1 + 0x80));
    }
LAB_001044ac:
    iVar2 = -0x16;
  }
  else {
    lVar5 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar6 + 0x28,"[E][%s] Error getting BHI offset\n","mhi_prepare_for_power_up");
    if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x18) < 3)) {
      uVar3 = *(undefined8 *)(lVar5 + 0x20);
      pcVar4 = "[E][%s] Error getting BHI offset\n";
LAB_0010444c:
      ipc_log_string(uVar3,pcVar4,"mhi_prepare_for_power_up");
    }
  }
LAB_001044b0:
  mhi_deinit_dev_ctxt(param_1);
LAB_001044b8:
  mutex_unlock(param_1 + 0x148);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_unprepare_after_power_down @ 001044fc size=64
// signature: undefined mhi_unprepare_after_power_down(void)
// callers: []
//------------------------------------------------------------

void mhi_unprepare_after_power_down(long param_1)

{
  if (*(long *)(param_1 + 0x90) != 0) {
    mhi_free_bhie_table(param_1);
  }
  mhi_deinit_dev_ctxt(param_1);
  return;
}



//------------------------------------------------------------
// mhi_release_device @ 00104540 size=56
// signature: undefined mhi_release_device(void)
// callers: []
//------------------------------------------------------------

void mhi_release_device(long param_1)

{
  if (*(long *)(param_1 + -0x10) != 0) {
    *(undefined8 *)(*(long *)(param_1 + -0x10) + 0x110) = 0;
  }
  if (*(long *)(param_1 + -8) != 0) {
    *(undefined8 *)(*(long *)(param_1 + -8) + 0x110) = 0;
  }
  kfree(param_1 + -0x28);
  return;
}



//------------------------------------------------------------
// __mhi_driver_register @ 0010457c size=96
// signature: undefined __mhi_driver_register(void)
// callers: []
//------------------------------------------------------------

undefined8 __mhi_driver_register(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + 8) == 0) || (*(long *)(param_1 + 0x10) == 0)) {
    uVar1 = 0xffffffea;
  }
  else {
    *(code **)(param_1 + 0x68) = mhi_driver_probe;
    *(undefined ***)(param_1 + 0x38) = &mhi_bus_type;
    *(undefined8 *)(param_1 + 0x40) = param_2;
    *(code **)(param_1 + 0x78) = mhi_driver_remove;
    uVar1 = driver_register(param_1 + 0x30);
  }
  return uVar1;
}



//------------------------------------------------------------
// mhi_driver_probe @ 001045e0 size=272
// signature: undefined mhi_driver_probe(void)
// callers: []
//------------------------------------------------------------

int mhi_driver_probe(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  
  puVar5 = (undefined8 *)(param_1 + -0x28);
  lVar6 = *(long *)(param_1 + 0x88);
  lVar1 = *(long *)(param_1 + -0x18);
  lVar2 = *(long *)(param_1 + -0x10);
  lVar7 = *(long *)(param_1 + -8);
  iVar4 = mhi_device_get_sync(puVar5);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (lVar2 == 0) {
LAB_00104640:
    if (lVar7 != 0) {
      if (((*(char *)(lVar7 + 0x188) != '\0') && (*(long *)(lVar6 + -8) == 0)) ||
         (((*(char *)(lVar7 + 0x18a) == '\0' && (*(long *)(lVar6 + -0x10) == 0)) ||
          ((*(char *)(*(long *)(lVar1 + 0x130) + (ulong)*(uint *)(lVar7 + 0xcc) * 0x118 + 0x111) !=
            '\0' && (*(long *)(lVar6 + -8) == 0)))))) goto LAB_001046c0;
      *(undefined8 *)(lVar7 + 0x118) = *(undefined8 *)(lVar6 + -0x10);
    }
    if (*(int *)(*(code **)(lVar6 + -0x28) + -4) != -0x1b8283e6) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1046b0);
      (*pcVar3)();
    }
    iVar4 = (**(code **)(lVar6 + -0x28))(puVar5,*puVar5);
    if (iVar4 == 0) goto LAB_001046cc;
  }
  else {
    if (((*(char *)(lVar2 + 0x188) == '\0') || (*(long *)(lVar6 + -8) != 0)) &&
       ((*(char *)(lVar2 + 0x18a) != '\0' || (*(long *)(lVar6 + -0x18) != 0)))) {
      *(long *)(lVar2 + 0x118) = *(long *)(lVar6 + -0x18);
      goto LAB_00104640;
    }
LAB_001046c0:
    iVar4 = -0x16;
  }
  mhi_unprepare_from_transfer(puVar5);
LAB_001046cc:
  mhi_device_put(puVar5);
  return iVar4;
}



//------------------------------------------------------------
// mhi_driver_remove @ 001046f4 size=724
// signature: undefined mhi_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_driver_remove(long param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  
  if (*(int *)(param_1 + 0x390) == 1) {
    return 0;
  }
  lVar6 = *(long *)(param_1 + 0x88);
  lVar4 = *(long *)(param_1 + -8);
  puVar3 = *(undefined8 **)(param_1 + -0x18);
  if (lVar4 == 0) {
    iVar8 = 0;
    lVar4 = *(long *)(param_1 + -0x10);
  }
  else {
    lVar7 = lVar4 + 0x170;
    _raw_write_lock_irq(lVar7);
    *(undefined4 *)(lVar4 + 0x108) = 0;
    complete_all(lVar4 + 0x150);
    _raw_write_unlock_irq(lVar7);
    mutex_lock(lVar4 + 0x120);
    _raw_write_lock_irq(lVar7);
    iVar8 = *(int *)(lVar4 + 0x104);
    *(undefined4 *)(lVar4 + 0x104) = 3;
    _raw_write_unlock_irq(lVar7);
    if (*(char *)(lVar4 + 0x18a) == '\0') {
      mhi_reset_chan(puVar3,lVar4);
    }
    mutex_unlock(lVar4 + 0x120);
    lVar4 = *(long *)(param_1 + -0x10);
  }
  if (lVar4 == 0) {
    iVar5 = 0;
  }
  else {
    lVar7 = lVar4 + 0x170;
    _raw_write_lock_irq(lVar7);
    *(undefined4 *)(lVar4 + 0x108) = 0;
    complete_all(lVar4 + 0x150);
    _raw_write_unlock_irq(lVar7);
    mutex_lock(lVar4 + 0x120);
    _raw_write_lock_irq(lVar7);
    iVar5 = *(int *)(lVar4 + 0x104);
    *(undefined4 *)(lVar4 + 0x104) = 3;
    _raw_write_unlock_irq(lVar7);
    if (*(char *)(lVar4 + 0x18a) == '\0') {
      mhi_reset_chan(puVar3,lVar4);
    }
    mutex_unlock(lVar4 + 0x120);
  }
  pcVar2 = *(code **)(lVar6 + -0x20);
  if (*(int *)(pcVar2 + -4) != -0x4625fd7c) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10483c);
    (*pcVar2)();
  }
  (*pcVar2)(param_1 + -0x28);
  lVar4 = *(long *)(param_1 + -8);
  if (lVar4 != 0) {
    mutex_lock(lVar4 + 0x120);
    if ((((iVar8 == 4) || (iVar8 == 1)) && (*(int *)(lVar4 + 0x104) != 0)) &&
       (*(char *)(lVar4 + 0x18a) == '\0')) {
      lVar6 = *(long *)(puVar3[0x28] + 8);
      lVar7 = lVar6 + (ulong)*(uint *)(lVar4 + 200) * 0x2c;
      if (*(long *)(lVar7 + 0xc) != 0) {
        lVar9 = (ulong)*(uint *)(lVar4 + 200) * 0x2c;
        dma_free_attrs(*puVar3,*(undefined8 *)(lVar4 + 0xb8),*(undefined8 *)(lVar4 + 0x80),
                       *(undefined8 *)(lVar4 + 0x68),0);
        vfree(*(undefined8 *)(lVar4 + 0x28));
        *(undefined8 *)(lVar4 + 0x88) = 0;
        *(undefined8 *)(lVar4 + 0x28) = 0;
        *(undefined8 *)(lVar4 + 0x78) = 0;
        uVar1 = *(uint *)(lVar6 + lVar9);
        *(undefined8 *)(lVar7 + 0x1c) = 0;
        *(undefined8 *)(lVar7 + 0x24) = 0;
        *(long *)(lVar7 + 0xc) = 0;
        *(undefined8 *)(lVar7 + 0x14) = 0;
        *(uint *)(lVar6 + lVar9) = uVar1 & 0xffffff00;
        DataMemoryBarrier(2,2);
      }
    }
    *(undefined4 *)(lVar4 + 0x104) = 0;
    mutex_unlock(lVar4 + 0x120);
  }
  lVar4 = *(long *)(param_1 + -0x10);
  if (lVar4 != 0) {
    mutex_lock(lVar4 + 0x120);
    if (((iVar5 == 4) || (iVar5 == 1)) &&
       ((*(int *)(lVar4 + 0x104) != 0 && (*(char *)(lVar4 + 0x18a) == '\0')))) {
      lVar6 = *(long *)(puVar3[0x28] + 8);
      lVar7 = lVar6 + (ulong)*(uint *)(lVar4 + 200) * 0x2c;
      if (*(long *)(lVar7 + 0xc) != 0) {
        lVar9 = (ulong)*(uint *)(lVar4 + 200) * 0x2c;
        dma_free_attrs(*puVar3,*(undefined8 *)(lVar4 + 0xb8),*(undefined8 *)(lVar4 + 0x80),
                       *(undefined8 *)(lVar4 + 0x68),0);
        vfree(*(undefined8 *)(lVar4 + 0x28));
        *(undefined8 *)(lVar4 + 0x88) = 0;
        *(undefined8 *)(lVar4 + 0x28) = 0;
        *(undefined8 *)(lVar4 + 0x78) = 0;
        uVar1 = *(uint *)(lVar6 + lVar9);
        *(undefined8 *)(lVar7 + 0x1c) = 0;
        *(undefined8 *)(lVar7 + 0x24) = 0;
        *(long *)(lVar7 + 0xc) = 0;
        *(undefined8 *)(lVar7 + 0x14) = 0;
        *(uint *)(lVar6 + lVar9) = uVar1 & 0xffffff00;
        DataMemoryBarrier(2,2);
      }
    }
    *(undefined4 *)(lVar4 + 0x104) = 0;
    mutex_unlock(lVar4 + 0x120);
  }
  while (*(int *)(param_1 + 0x3a4) != 0) {
    mhi_device_put(param_1 + -0x28);
  }
  return 0;
}



//------------------------------------------------------------
// mhi_driver_unregister @ 001049cc size=32
// signature: undefined mhi_driver_unregister(void)
// callers: []
//------------------------------------------------------------

void mhi_driver_unregister(long param_1)

{
  driver_unregister(param_1 + 0x30);
  return;
}



//------------------------------------------------------------
// mhi_match @ 001049f0 size=112
// signature: undefined mhi_match(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_match(long param_1,long param_2)

{
  int iVar1;
  char *__s2;
  char *__s1;
  
  if ((*(int *)(param_1 + 0x390) != 1) && (__s2 = *(char **)(param_2 + -0x30), *__s2 != '\0')) {
    __s1 = *(char **)(param_1 + -0x20);
    do {
      iVar1 = strcmp(__s1,__s2);
      if (iVar1 == 0) {
        *(char **)(param_1 + -0x28) = __s2;
        return 1;
      }
      __s2 = __s2 + 0x28;
    } while (*__s2 != '\0');
  }
  return 0;
}



//------------------------------------------------------------
// mhi_uevent @ 00104a64 size=48
// signature: undefined mhi_uevent(void)
// callers: []
//------------------------------------------------------------

void mhi_uevent(long param_1,undefined8 param_2)

{
  add_uevent_var(param_2,"MODALIAS=mhi:%s",*(undefined8 *)(param_1 + -0x20));
  return;
}



//------------------------------------------------------------
// serial_number_show @ 00104a98 size=56
// signature: undefined serial_number_show(void)
// callers: []
//------------------------------------------------------------

long serial_number_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = sysfs_emit(param_3,"Serial Number: %u\n",
                     *(undefined4 *)(*(long *)(param_1 + -0x18) + 0xe4));
  return (long)iVar1;
}



//------------------------------------------------------------
// oem_pk_hash_show @ 00104ad4 size=508
// signature: undefined oem_pk_hash_show(void)
// callers: []
//------------------------------------------------------------

long oem_pk_hash_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + -0x18);
  iVar1 = sysfs_emit_at(param_3,0,"OEMPKHASH[%d]: 0x%x\n",0,*(undefined4 *)(lVar4 + 0xe8));
  iVar2 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",1,*(undefined4 *)(lVar4 + 0xec));
  iVar3 = sysfs_emit_at(param_3,iVar2 + iVar1,"OEMPKHASH[%d]: 0x%x\n",2,
                        *(undefined4 *)(lVar4 + 0xf0));
  iVar3 = iVar3 + iVar2 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",3,*(undefined4 *)(lVar4 + 0xf4));
  iVar1 = iVar1 + iVar3;
  iVar3 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",4,*(undefined4 *)(lVar4 + 0xf8));
  iVar3 = iVar3 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",5,*(undefined4 *)(lVar4 + 0xfc));
  iVar1 = iVar1 + iVar3;
  iVar3 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",6,*(undefined4 *)(lVar4 + 0x100));
  iVar3 = iVar3 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",7,*(undefined4 *)(lVar4 + 0x104));
  iVar1 = iVar1 + iVar3;
  iVar3 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",8,*(undefined4 *)(lVar4 + 0x108));
  iVar3 = iVar3 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",9,*(undefined4 *)(lVar4 + 0x10c));
  iVar1 = iVar1 + iVar3;
  iVar3 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",10,*(undefined4 *)(lVar4 + 0x110));
  iVar3 = iVar3 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",0xb,*(undefined4 *)(lVar4 + 0x114));
  iVar1 = iVar1 + iVar3;
  iVar3 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",0xc,*(undefined4 *)(lVar4 + 0x118));
  iVar3 = iVar3 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",0xd,*(undefined4 *)(lVar4 + 0x11c));
  iVar1 = iVar1 + iVar3;
  iVar3 = sysfs_emit_at(param_3,iVar1,"OEMPKHASH[%d]: 0x%x\n",0xe,*(undefined4 *)(lVar4 + 0x120));
  iVar3 = iVar3 + iVar1;
  iVar1 = sysfs_emit_at(param_3,iVar3,"OEMPKHASH[%d]: 0x%x\n",0xf,*(undefined4 *)(lVar4 + 0x124));
  return (long)(iVar1 + iVar3);
}



//------------------------------------------------------------
// soc_reset_store @ 00104cd4 size=48
// signature: undefined soc_reset_store(void)
// callers: []
//------------------------------------------------------------

undefined8 soc_reset_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  mhi_soc_reset(*(undefined8 *)(param_1 + -0x18));
  return param_4;
}



//------------------------------------------------------------
// mhi_read_reg @ 00104d08 size=64
// signature: undefined mhi_read_reg(void)
// callers: [mhi_scan_rddm_cookie, mhi_get_channel_db_base, mhi_debug_reg_dump, mhi_fw_load_handler, mhi_get_remote_time_sync, mhi_get_event_ring_db_base, mhi_get_soc_info, mhi_prepare_for_power_up, mhi_init_mmio, mhi_misc_init_mmio, mhi_register_controller, mhi_rddm_download_status]
//------------------------------------------------------------

void mhi_read_reg(long param_1,long param_2,ulong param_3,undefined8 param_4)

{
  code *pcVar1;
  
  if (*(int *)(*(code **)(param_1 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104d38);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x280))(param_1,param_2 + (param_3 & 0xffffffff),param_4);
  return;
}



//------------------------------------------------------------
// mhi_read_reg_field @ 00104d4c size=160
// signature: undefined mhi_read_reg_field(void)
// callers: [mhi_fw_load_handler, mhi_pm_st_worker, mhi_download_rddm_image, mhi_get_capability_offset, mhi_download_amss_image, mhi_rddm_download_status]
//------------------------------------------------------------

void mhi_read_reg_field(long param_1,long param_2,ulong param_3,uint param_4,uint *param_5)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104d9c);
    (*pcVar3)();
  }
  iVar4 = (**(code **)(param_1 + 0x280))((int)param_1,param_2 + (param_3 & 0xffffffff),&local_2c);
  if (iVar4 == 0) {
    uVar1 = ((ulong)param_4 & 0xaaaaaaaaaaaaaaaa) >> 1 | ((ulong)param_4 & 0x5555555555555555) << 1;
    uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
    uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
    *param_5 = (local_2c & param_4) >>
               (ulong)((uint)LZCOUNT((uVar1 >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10) << 0x20) &
                      0x1f);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_poll_reg_field @ 00104df0 size=352
// signature: undefined mhi_poll_reg_field(void)
// callers: [mhi_pm_st_worker, mhi_async_power_up, mhi_ready_state_transition]
//------------------------------------------------------------

void mhi_poll_reg_field(long param_1,long param_2,ulong param_3,uint param_4,uint param_5,
                       uint param_6)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  uint uVar7;
  uint local_6c;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  uVar1 = *(int *)(param_1 + 0x180) * 1000;
  if (param_6 <= uVar1) {
    uVar7 = 0;
    if (param_6 != 0) {
      uVar7 = uVar1 / param_6;
    }
    uVar6 = (ulong)param_6;
    uVar2 = ((ulong)param_4 & 0xaaaaaaaaaaaaaaaa) >> 1 | ((ulong)param_4 & 0x5555555555555555) << 1;
    uVar2 = (uVar2 & 0xcccccccccccccccc) >> 2 | (uVar2 & 0x3333333333333333) << 2;
    uVar2 = (uVar2 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar2 = (uVar2 & 0xff00ff00ff00ff00) >> 8 | (uVar2 & 0xff00ff00ff00ff) << 8;
    do {
      local_6c = 0;
      if (*(int *)(*(code **)(param_1 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104ebc);
        (*pcVar4)();
      }
      uVar5 = (**(code **)(param_1 + 0x280))(param_1,param_2 + (param_3 & 0xffffffff),&local_6c);
      if ((int)uVar5 != 0) goto LAB_00104f14;
      if ((local_6c & param_4) >>
          (ulong)((uint)LZCOUNT((uVar2 >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10) << 0x20) & 0x1f)
          == param_5) {
        uVar5 = 0;
        goto LAB_00104f14;
      }
      uVar7 = uVar7 - 1;
      if (param_6 < 0xb) {
        __udelay(uVar6);
      }
      else if (param_6 < 0x4e21) {
        usleep_range_state(uVar6,(ulong)param_6 << 1,2);
      }
      else {
        msleep((uVar6 + 999) / 1000);
      }
    } while (uVar7 != 0);
  }
  uVar5 = 0xffffff92;
LAB_00104f14:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// mhi_write_reg @ 00104f54 size=64
// signature: undefined mhi_write_reg(void)
// callers: [mhi_rddm_prepare, mhi_misc_dbs_pending, mhi_fw_load_handler, mhi_pm_st_worker, mhi_async_power_up, mhi_init_mmio, mhi_get_remote_time, mhi_misc_init_mmio, mhi_download_amss_image, mhi_init_host_notification, mhi_process_misc_bw_ev_ring]
//------------------------------------------------------------

void mhi_write_reg(long param_1,long param_2,ulong param_3,undefined4 param_4)

{
  code *pcVar1;
  
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104f84);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x288))(param_1,param_2 + (param_3 & 0xffffffff),param_4);
  return;
}



//------------------------------------------------------------
// mhi_write_reg_field @ 00104f98 size=236
// signature: undefined mhi_write_reg_field(void)
// callers: [mhi_set_mhi_state, mhi_force_rddm_mode, mhi_rddm_prepare, mhi_pm_m1_transition, __mhi_pm_resume, mhi_pm_st_worker, mhi_async_power_up, mhi_init_mmio, mhi_download_amss_image, mhi_ready_state_transition]
//------------------------------------------------------------

int mhi_write_reg_field(long param_1,long param_2,ulong param_3,uint param_4,int param_5)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  uint local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  param_2 = param_2 + (param_3 & 0xffffffff);
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  if (*(int *)(*(code **)(param_1 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104ff8);
    (*pcVar3)();
  }
  iVar4 = (**(code **)(param_1 + 0x280))(param_1,param_2,&local_4c);
  if (iVar4 == 0) {
    uVar1 = ((ulong)param_4 & 0xaaaaaaaaaaaaaaaa) >> 1 | ((ulong)param_4 & 0x5555555555555555) << 1;
    uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
    uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
    local_4c = local_4c & (param_4 ^ 0xffffffff) |
               param_5 <<
               (ulong)((uint)LZCOUNT((uVar1 >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10) << 0x20) &
                      0x1f);
    if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x105048);
      (*pcVar3)();
    }
    (**(code **)(param_1 + 0x288))(param_1,param_2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// mhi_write_db @ 00105088 size=136
// signature: undefined mhi_write_db(void)
// callers: [mhi_host_notify_db_disable_trace, mhi_assert_dev_wake, mhi_deassert_dev_wake]
//------------------------------------------------------------

void mhi_write_db(long param_1,long param_2,ulong param_3)

{
  code *pcVar1;
  
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1050cc);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x288))(param_1,param_2 + 4,param_3 >> 0x20);
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1050f8);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x288))(param_1,param_2,param_3 & 0xffffffff);
  return;
}



//------------------------------------------------------------
// mhi_db_brstmode @ 00105114 size=156
// signature: undefined mhi_db_brstmode(void)
// callers: []
//------------------------------------------------------------

void mhi_db_brstmode(long param_1,long param_2,long param_3,ulong param_4)

{
  code *pcVar1;
  
  if (*(char *)(param_2 + 1) != '\0') {
    *(ulong *)(param_2 + 0x10) = param_4;
    if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105168);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x288))(param_1,param_3 + 4,param_4 >> 0x20);
    if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105194);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x288))(param_1,param_3,param_4 & 0xffffffff);
    *(undefined1 *)(param_2 + 1) = 0;
  }
  return;
}



//------------------------------------------------------------
// mhi_db_brstmode_disable @ 001051b4 size=140
// signature: undefined mhi_db_brstmode_disable(void)
// callers: []
//------------------------------------------------------------

void mhi_db_brstmode_disable(long param_1,long param_2,long param_3,ulong param_4)

{
  code *pcVar1;
  
  *(ulong *)(param_2 + 0x10) = param_4;
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1051fc);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x288))(param_1,param_3 + 4,param_4 >> 0x20);
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105228);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x288))(param_1,param_3,param_4 & 0xffffffff);
  return;
}



//------------------------------------------------------------
// mhi_ring_er_db @ 00105244 size=80
// signature: undefined mhi_ring_er_db(void)
// callers: [mhi_process_misc_tsync_ev_ring, mhi_pm_st_worker, mhi_pm_m0_transition, mhi_process_misc_bw_ev_ring, mhi_ready_state_transition]
//------------------------------------------------------------

void mhi_ring_er_db(undefined8 *param_1)

{
  code *pcVar1;
  
  if (*(int *)((code *)param_1[0x14] + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x105284);
    (*pcVar1)();
  }
  (*(code *)param_1[0x14])(*param_1,param_1 + 0x11,param_1[0x10],*(undefined8 *)param_1[7]);
  return;
}



//------------------------------------------------------------
// mhi_ring_cmd_db @ 00105298 size=156
// signature: undefined mhi_ring_cmd_db(void)
// callers: [mhi_pm_m0_transition]
//------------------------------------------------------------

void mhi_ring_cmd_db(long param_1,long param_2)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  
  uVar1 = (*(long *)(param_2 + 0x30) - *(long *)(param_2 + 0x20)) + *(long *)(param_2 + 8);
  **(ulong **)(param_2 + 0x10) = uVar1;
  lVar3 = *(long *)(param_2 + 0x58);
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1052f0);
    (*pcVar2)();
  }
  (**(code **)(param_1 + 0x288))(param_1,lVar3 + 4,uVar1 >> 0x20);
  if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10531c);
    (*pcVar2)();
  }
  (**(code **)(param_1 + 0x288))(param_1,lVar3,uVar1 & 0xffffffff);
  return;
}



//------------------------------------------------------------
// mhi_ring_chan_db @ 00105338 size=100
// signature: undefined mhi_ring_chan_db(void)
// callers: [mhi_pm_m0_transition]
//------------------------------------------------------------

void mhi_ring_chan_db(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  DataMemoryBarrier(0,2);
  **(long **)(param_2 + 0x78) =
       (*(long *)(param_2 + 0x98) - *(long *)(param_2 + 0x88)) + *(long *)(param_2 + 0x70);
  if (*(int *)(*(code **)(param_2 + 0xf8) + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x10538c);
    (*pcVar1)();
  }
  (**(code **)(param_2 + 0xf8))(param_1,param_2 + 0xe0,*(undefined8 *)(param_2 + 0xc0));
  return;
}



//------------------------------------------------------------
// mhi_get_exec_env @ 001053a0 size=132
// signature: undefined mhi_get_exec_env(void)
// callers: [mhi_in_rddm, mhi_host_notify_db_disable_trace, mhi_debug_reg_dump, mhi_pm_st_worker, mhi_download_rddm_image, mhi_async_power_up, mhi_pm_fast_resume, mhi_rddm_download_status]
//------------------------------------------------------------

void mhi_get_exec_env(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  if (*(int *)(*(code **)(param_1 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x1053e8);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(param_1 + 0x280))(param_1,*(long *)(param_1 + 0x20) + 0x28,&local_1c);
  lVar1 = sp_el0;
  uVar4 = local_1c;
  if (iVar3 != 0) {
    uVar4 = 10;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// mhi_get_mhi_state @ 00105428 size=132
// signature: undefined mhi_get_mhi_state(void)
// callers: [mhi_host_notify_db_disable_trace, __mhi_pm_resume, mhi_debug_reg_dump, mhi_pm_st_worker, mhi_async_power_up, mhi_device_get_sync_atomic]
//------------------------------------------------------------

void mhi_get_mhi_state(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  uint local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  if (*(int *)(*(code **)(param_1 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x105470);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(param_1 + 0x280))(param_1,*(long *)(param_1 + 0x18) + 0x48,&local_1c);
  lVar1 = sp_el0;
  uVar4 = local_1c >> 8 & 0xff;
  if (iVar3 != 0) {
    uVar4 = 0x100;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// mhi_soc_reset @ 001054b0 size=108
// signature: undefined mhi_soc_reset(void)
// callers: [mhi_force_reset, mhi_download_rddm_image, soc_reset_store]
//------------------------------------------------------------

void mhi_soc_reset(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x290);
  if (pcVar1 == (code *)0x0) {
    if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x10550c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x288))(param_1,*(long *)(param_1 + 0x18) + 0xb0,1);
  }
  else {
    if (*(int *)(pcVar1 + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1054dc);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// mhi_map_single_no_bb @ 00105520 size=236
// signature: undefined mhi_map_single_no_bb(void)
// callers: []
//------------------------------------------------------------

undefined4 mhi_map_single_no_bb(undefined8 *param_1,ulong *param_2)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  ulong uVar7;
  ulong uVar8;
  undefined4 uVar9;
  
  uVar8 = *param_2;
  plVar6 = (long *)*param_1;
  uVar7 = param_2[5];
  uVar5 = param_2[6];
  uVar2 = is_vmalloc_addr(uVar8);
  if (((uVar2 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar3 = dev_driver_string(plVar6);
    lVar4 = plVar6[0xe];
    if (lVar4 == 0) {
      lVar4 = *plVar6;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar3,lVar4);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1055ac);
    (*pcVar1)();
  }
  uVar9 = 0xfffffff4;
  if ((uVar2 & 1) == 0) {
    uVar5 = dma_map_page_attrs(plVar6,(((long)(uVar8 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                      -0x200000000,uVar8 & 0xfff,uVar7,(int)uVar5,0);
    uVar9 = 0xfffffff4;
    if (uVar5 != 0xffffffffffffffff) {
      uVar9 = 0;
    }
  }
  else {
    uVar5 = 0xffffffffffffffff;
  }
  param_2[4] = uVar5;
  return uVar9;
}



//------------------------------------------------------------
// mhi_map_single_use_bb @ 00105618 size=112
// signature: undefined mhi_map_single_use_bb(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_map_single_use_bb(undefined8 *param_1,undefined8 *param_2)

{
  void *__dest;
  undefined8 uVar1;
  
  __dest = (void *)dma_alloc_attrs(*param_1,param_2[5],param_2 + 4,0xa20,0);
  if (__dest == (void *)0x0) {
    uVar1 = 0xfffffff4;
  }
  else {
    if (*(int *)(param_2 + 6) == 1) {
      memcpy(__dest,(void *)*param_2,param_2[5]);
    }
    uVar1 = 0;
    param_2[1] = __dest;
  }
  return uVar1;
}



//------------------------------------------------------------
// mhi_unmap_single_no_bb @ 0010568c size=48
// signature: undefined mhi_unmap_single_no_bb(void)
// callers: []
//------------------------------------------------------------

void mhi_unmap_single_no_bb(undefined8 *param_1,long param_2)

{
  dma_unmap_page_attrs
            (*param_1,*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x28),
             *(undefined4 *)(param_2 + 0x30),0);
  return;
}



//------------------------------------------------------------
// mhi_unmap_single_use_bb @ 001056c0 size=84
// signature: undefined mhi_unmap_single_use_bb(void)
// callers: []
//------------------------------------------------------------

void mhi_unmap_single_use_bb(undefined8 *param_1,undefined8 *param_2)

{
  if (*(int *)(param_2 + 6) == 2) {
    memcpy((void *)*param_2,(void *)param_2[1],param_2[5]);
  }
  dma_free_attrs(*param_1,param_2[5],param_2[1],param_2[4],0);
  return;
}



//------------------------------------------------------------
// mhi_to_virtual @ 00105718 size=20
// signature: undefined mhi_to_virtual(void)
// callers: []
//------------------------------------------------------------

long mhi_to_virtual(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x20) + (param_2 - *(long *)(param_1 + 8));
}



//------------------------------------------------------------
// mhi_to_physical @ 00105730 size=20
// signature: undefined mhi_to_physical(void)
// callers: []
//------------------------------------------------------------

long mhi_to_physical(long param_1,long param_2)

{
  return (param_2 - *(long *)(param_1 + 0x20)) + *(long *)(param_1 + 8);
}



//------------------------------------------------------------
// mhi_destroy_device @ 00105748 size=252
// signature: undefined mhi_destroy_device(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_destroy_device(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  if (*(undefined ***)(param_1 + 0x80) != &mhi_bus_type) {
    return 0;
  }
  if (*(int *)(param_1 + 0x390) == 1) {
    return 0;
  }
  lVar2 = *(long *)(param_1 + -0x18);
  lVar1 = *(long *)(param_1 + -0x10);
  lVar3 = *(long *)(param_1 + -8);
  if (param_2 == (uint *)0x0) {
    if (lVar1 != 0) {
LAB_001057b0:
      uVar4 = 10;
      goto LAB_001057b4;
    }
    if (lVar3 == 0) goto LAB_001057ec;
  }
  else {
    uVar4 = (ulong)*param_2;
    if (lVar1 != 0) {
      if (*param_2 == 10) goto LAB_001057b0;
      if ((*(uint *)(lVar1 + 0x100) >> (uVar4 & 0x3f) & 1) == 0) {
        return 0;
      }
LAB_001057b4:
      put_device(*(long *)(lVar1 + 0x110) + 0x28);
    }
    if (lVar3 == 0) goto LAB_001057ec;
    if (((int)uVar4 != 10) && ((*(uint *)(lVar3 + 0x100) >> (uVar4 & 0x3f) & 1) == 0)) {
      return 0;
    }
  }
  put_device(*(long *)(lVar3 + 0x110) + 0x28);
LAB_001057ec:
  lVar2 = *(long *)(*(long *)(lVar2 + 8) + 0xc0);
  if ((lVar2 != 0) && (*(int *)(lVar2 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x20),"[D][%s] destroy device for chan:%s\n",
                   "mhi_destroy_device",*(undefined8 *)(param_1 + -0x20));
  }
  device_del(param_1);
  put_device(param_1);
  return 0;
}



//------------------------------------------------------------
// mhi_get_free_desc_count @ 00105848 size=96
// signature: undefined mhi_get_free_desc_count(void)
// callers: []
//------------------------------------------------------------

long mhi_get_free_desc_count(long param_1,int param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = 0x18;
  if (param_2 != 1) {
    lVar5 = 0x20;
  }
  lVar5 = *(long *)(param_1 + lVar5);
  uVar1 = *(ulong *)(lVar5 + 0x90);
  uVar2 = *(ulong *)(lVar5 + 0x98);
  if (uVar2 < uVar1) {
    uVar3 = 0;
    if (*(ulong *)(lVar5 + 0xa0) != 0) {
      uVar3 = (uVar1 - uVar2) / *(ulong *)(lVar5 + 0xa0);
    }
    return uVar3 - 1;
  }
  uVar3 = *(ulong *)(lVar5 + 0xa0);
  uVar4 = 0;
  if (uVar3 != 0) {
    uVar4 = (uVar1 - *(long *)(lVar5 + 0x88)) / uVar3;
  }
  uVar1 = 0;
  if (uVar3 != 0) {
    uVar1 = ((*(long *)(lVar5 + 0x88) + *(long *)(lVar5 + 0xa8)) - uVar2) / uVar3;
  }
  return uVar4 + 0xffffffff + uVar1;
}



//------------------------------------------------------------
// mhi_notify @ 001058ac size=68
// signature: undefined mhi_notify(void)
// callers: [mhi_misc_mission_mode, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_notify_fatal_cb, mhi_pm_fast_resume, mhi_pm_suspend]
//------------------------------------------------------------

void mhi_notify(long param_1)

{
  code *pcVar1;
  
  if ((*(long *)(param_1 + 0xb0) != 0) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0xb0) + -8), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x680aab99) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1058e0);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// mhi_create_devices @ 001058f4 size=592
// signature: undefined mhi_create_devices(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

void mhi_create_devices(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  
  if (*(int *)(param_1 + 0xc0) != 0) {
    uVar6 = 0;
    lVar5 = *(long *)(param_1 + 8);
    puVar8 = *(undefined8 **)(param_1 + 0xa0);
    do {
      puVar9 = puVar8;
      if (((*(char *)((long)puVar8 + 0x189) == '\0') || (puVar8[0x22] != 0)) ||
         ((*(uint *)(puVar8 + 0x20) >> ((ulong)*(uint *)(param_1 + 0x18c) & 0x3f) & 1) == 0)) {
        uVar7 = uVar6;
      }
      else {
        uVar2 = mhi_alloc_device(param_1);
        if (0xfffffffffffff000 < uVar2) {
          return;
        }
        *(undefined4 *)(uVar2 + 0x3b8) = 0;
        switch(*(undefined4 *)(puVar8 + 0x1b)) {
        case 0:
        case 3:
          *(undefined4 *)(uVar2 + 0x3bc) = *(undefined4 *)(puVar8 + 0x19);
          *(undefined4 *)(uVar2 + 0x3c0) = *(undefined4 *)((long)puVar8 + 0xcc);
        case 2:
          *(undefined8 **)(uVar2 + 0x20) = puVar8;
          *(undefined4 *)(uVar2 + 0x3c4) = *(undefined4 *)(puVar8 + 0x19);
          *(undefined4 *)(uVar2 + 0x3c8) = *(undefined4 *)((long)puVar8 + 0xcc);
          break;
        case 1:
          *(undefined8 **)(uVar2 + 0x18) = puVar8;
          *(undefined4 *)(uVar2 + 0x3bc) = *(undefined4 *)(puVar8 + 0x19);
          *(undefined4 *)(uVar2 + 0x3c0) = *(undefined4 *)((long)puVar8 + 0xcc);
          break;
        default:
          lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar5 + 0x28,"[E][%s] Direction not supported\n","mhi_create_devices");
          if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
            ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[E][%s] Direction not supported\n",
                           "mhi_create_devices");
          }
          put_device(uVar2 + 0x28);
          return;
        }
        lVar4 = uVar2 + 0x28;
        get_device(lVar4);
        puVar8[0x22] = uVar2;
        uVar7 = uVar6 + 1;
        if (((uVar7 < *(uint *)(param_1 + 0xc0)) && (*(char *)((long)puVar8 + 0x319) != '\0')) &&
           (iVar1 = strcmp((char *)puVar8[0x32],(char *)*puVar8), iVar1 == 0)) {
          puVar9 = puVar8 + 0x32;
          if (*(int *)(puVar8 + 0x4d) == 1) {
            *(undefined8 **)(uVar2 + 0x18) = puVar9;
            *(undefined4 *)(uVar2 + 0x3bc) = *(undefined4 *)(puVar8 + 0x4b);
            *(undefined4 *)(uVar2 + 0x3c0) = *(undefined4 *)((long)puVar8 + 0x25c);
          }
          else {
            *(undefined8 **)(uVar2 + 0x20) = puVar9;
            *(undefined4 *)(uVar2 + 0x3c4) = *(undefined4 *)(puVar8 + 0x4b);
            *(undefined4 *)(uVar2 + 0x3c8) = *(undefined4 *)((long)puVar8 + 0x25c);
          }
          get_device(lVar4);
          puVar8[0x54] = uVar2;
        }
        else {
          uVar7 = uVar6;
        }
        *(undefined8 *)(uVar2 + 8) = *puVar9;
        lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x98);
        if (lVar3 == 0) {
          lVar3 = *(long *)(*(long *)(param_1 + 8) + 0x28);
        }
        dev_set_name(lVar4,"%s_%s",lVar3);
        if ((*(long *)(uVar2 + 0x20) != 0) && (*(char *)(*(long *)(uVar2 + 0x20) + 0x18c) != '\0'))
        {
          device_set_wakeup_capable(lVar4,1);
          device_wakeup_enable(lVar4);
        }
        iVar1 = device_add(lVar4);
        if (iVar1 != 0) {
          put_device(lVar4);
        }
      }
      uVar6 = uVar7 + 1;
      puVar8 = puVar9 + 0x32;
    } while (uVar6 < *(uint *)(param_1 + 0xc0));
  }
  return;
}



//------------------------------------------------------------
// mhi_process_sleeping_events @ 00105b48 size=184
// signature: undefined mhi_process_sleeping_events(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

void mhi_process_sleeping_events(long param_1)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar1 = *(uint *)(param_1 + 0xc4);
  if (uVar1 != 0) {
    uVar2 = 0;
    pcVar3 = (char *)(*(long *)(param_1 + 0x130) + 0x112);
    do {
      if (((*pcVar3 == '\0') && (*(int *)(pcVar3 + -0xf2) == 2)) &&
         (*(long *)(pcVar3 + -0xc2) !=
          *(long *)(pcVar3 + -0xca) +
          (*(long *)(**(long **)(param_1 + 0x140) + (ulong)*(uint *)(pcVar3 + -0x102) * 0x2c + 0x1c)
          - *(long *)(pcVar3 + -0xe2)))) {
        queue_work_on(0x20,*(undefined8 *)(param_1 + 0x208),pcVar3 + -0x42);
        uVar1 = *(uint *)(param_1 + 0xc4);
      }
      uVar2 = uVar2 + 1;
      pcVar3 = pcVar3 + 0x118;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// mhi_irq_handler @ 00105c04 size=448
// signature: undefined mhi_irq_handler(void)
// callers: [mhi_pm_fast_suspend, mhi_pm_fast_resume]
//------------------------------------------------------------

undefined8 mhi_irq_handler(undefined8 param_1,long *param_2)

{
  ulong *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  code *pcVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  
  lVar7 = *param_2;
  if (*(long **)(lVar7 + 0x140) == (long *)0x0) {
    return 1;
  }
  uVar11 = param_2[6];
  uVar10 = *(ulong *)(**(long **)(lVar7 + 0x140) + (ulong)*(uint *)(param_2 + 2) * 0x2c + 0x1c);
  lVar9 = *(long *)(lVar7 + 8);
  if ((uVar10 < uVar11) || ((uVar10 & 0xf) != 0 || param_2[0xd] + uVar11 <= uVar10)) {
    lVar7 = *(long *)(lVar9 + 0xc0);
    _dev_err(lVar9 + 0x28,"[E][%s] Event ring rp points outside of the event ring\n",
             "mhi_irq_handler");
    if (lVar7 == 0) {
      return 1;
    }
    if (2 < *(uint *)(lVar7 + 0x18)) {
      return 1;
    }
    uVar5 = *(undefined8 *)(lVar7 + 0x20);
    pcVar6 = "[E][%s] Event ring rp points outside of the event ring\n";
  }
  else {
    if (param_2[10] == param_2[9] + (uVar10 - uVar11)) {
      return 1;
    }
    if (*(char *)((long)param_2 + 0x111) != '\0') {
      lVar7 = *(long *)(param_2[1] + 0x110);
      if (lVar7 == 0) {
        return 1;
      }
      if (*(long *)(lVar7 + 0xb0) == 0) {
        return 1;
      }
      pcVar8 = *(code **)(*(long *)(lVar7 + 0xb0) + -8);
      if (pcVar8 == (code *)0x0) {
        return 1;
      }
      if (*(int *)(pcVar8 + -4) != -0x680aab99) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x105cac);
        (*pcVar8)();
      }
      (*pcVar8)(lVar7,1);
      return 1;
    }
    iVar2 = (int)param_2[4];
    if (iVar2 == 0) {
      puVar1 = (ulong *)(param_2 + 0x16);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar10 = *puVar1;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = uVar10 | 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
      if ((uVar10 & 1) == 0) {
        __tasklet_schedule(param_2 + 0x15);
        return 1;
      }
      return 1;
    }
    if (iVar2 == 2) {
      queue_work_on(0x20,*(undefined8 *)(lVar7 + 0x208),param_2 + 0x1a);
      return 1;
    }
    if (iVar2 == 1) {
      puVar1 = (ulong *)(param_2 + 0x16);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar10 = *puVar1;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = uVar10 | 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
      if ((uVar10 & 1) == 0) {
        __tasklet_hi_schedule(param_2 + 0x15);
        return 1;
      }
      return 1;
    }
    lVar7 = *(long *)(lVar9 + 0xc0);
    if (lVar7 == 0) {
      return 1;
    }
    if (*(int *)(lVar7 + 0x18) != 0) {
      return 1;
    }
    uVar5 = *(undefined8 *)(lVar7 + 0x20);
    pcVar6 = "[D][%s] skip unknown priority event\n";
  }
  ipc_log_string(uVar5,pcVar6,"mhi_irq_handler");
  return 1;
}



//------------------------------------------------------------
// mhi_intvec_threaded_handler @ 00105de8 size=900
// signature: undefined mhi_intvec_threaded_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Switch with 1 destination removed at 0x001060e8 */
/* WARNING: Exceeded maximum restarts with more pending */

undefined8 mhi_intvec_threaded_handler(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  uint local_3c;
  long local_38;
  
  lVar9 = sp_el0;
  lVar1 = param_2 + 0x178;
  local_38 = *(long *)(lVar9 + 0x638);
  _raw_write_lock_irq(lVar1);
  if ((*(ushort *)(param_2 + 0x184) & 0xfde) != 0) {
    local_3c = 0;
    if (*(int *)(*(code **)(param_2 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x105e5c);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(param_2 + 0x280))(param_2,*(long *)(param_2 + 0x18) + 0x48,&local_3c);
    uVar8 = local_3c >> 8 & 0xff;
    if (iVar3 != 0) {
      uVar8 = 0x100;
    }
    local_3c = 0;
    if (*(int *)(*(code **)(param_2 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105ea0);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(param_2 + 0x280))(param_2,*(long *)(param_2 + 0x20) + 0x28,&local_3c);
    lVar9 = *(long *)(*(long *)(param_2 + 8) + 0xc0);
    uVar10 = local_3c;
    if (iVar3 != 0) {
      uVar10 = 10;
    }
    if ((lVar9 != 0) && (*(int *)(lVar9 + 0x18) == 0)) {
      if (*(uint *)(param_2 + 0x18c) < 10) {
        pcVar4 = (&mhi_ee_str)[*(uint *)(param_2 + 0x18c)];
      }
      else {
        pcVar4 = "INVALID_EE";
      }
      pcVar5 = "RESET";
      switch(*(int *)(param_2 + 400)) {
      case 0:
        break;
      case 1:
        pcVar5 = "READY";
        break;
      case 2:
        pcVar5 = "M0";
        break;
      case 3:
        pcVar5 = "M1";
        break;
      case 4:
        pcVar5 = "M2";
        break;
      case 5:
        pcVar5 = "M3";
        break;
      case 6:
        pcVar5 = "M3 FAST";
        break;
      case 7:
        pcVar5 = "BHI";
        break;
      default:
        if (*(int *)(param_2 + 400) == 0xff) {
          pcVar5 = "SYS ERROR";
        }
        else {
          pcVar5 = "Unknown state";
        }
      }
      if (uVar10 < 10) {
        pcVar6 = (&mhi_ee_str)[uVar10];
        if (7 < uVar8) goto LAB_00106104;
LAB_001060cc:
        pcVar7 = "RESET";
      }
      else {
        pcVar6 = "INVALID_EE";
        if (uVar8 < 8) goto LAB_001060cc;
LAB_00106104:
        if (uVar8 == 0xff) {
          pcVar7 = "SYS ERROR";
        }
        else {
          pcVar7 = "Unknown state";
        }
      }
      ipc_log_string(*(undefined8 *)(lVar9 + 0x20),
                     "[D][%s] local ee: %s state: %s device ee: %s state: %s\n",
                     "mhi_intvec_threaded_handler",pcVar4,pcVar5,pcVar6,pcVar7);
    }
    if (uVar8 == 0xff) {
      lVar9 = *(long *)(*(long *)(param_2 + 8) + 0xc0);
      if ((lVar9 != 0) && (*(int *)(lVar9 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[D][%s] System error detected\n",
                       "mhi_intvec_threaded_handler");
      }
      iVar3 = mhi_tryset_pm_state(param_2,0x100);
      _raw_write_unlock_irq(lVar1);
      if (iVar3 == 0x100) {
        if ((uVar10 - 5 < 2) || (uVar10 == 0)) {
          if (*(int *)(*(code **)(param_2 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105fe0);
            (*pcVar2)();
          }
          (**(code **)(param_2 + 0x228))(param_2,7);
          *(uint *)(param_2 + 0x18c) = uVar10;
        }
        else if (uVar10 == 3) {
          if ((*(long *)(param_2 + 0x90) != 0) && (*(int *)(param_2 + 400) - 2U < 5)) {
            mhi_report_error(param_2);
            if (*(int *)(*(code **)(param_2 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105f78);
              (*pcVar2)();
            }
            (**(code **)(param_2 + 0x228))(param_2,4);
            *(undefined4 *)(param_2 + 0x18c) = 3;
            __wake_up(param_2 + 0x210,3,0,0);
          }
          goto LAB_0010618c;
        }
        __wake_up(param_2 + 0x210,3,0,0);
        mhi_pm_sys_err_handler(param_2);
      }
      goto LAB_0010618c;
    }
  }
  _raw_write_unlock_irq(lVar1);
LAB_0010618c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// mhi_state_str @ 001061c0 size=160
// signature: undefined mhi_state_str(void)
// callers: [mhi_process_ctrl_ev_ring]
//------------------------------------------------------------

char * mhi_state_str(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "RESET";
  switch(param_1) {
  case 0:
    goto switchD_001061e8_caseD_0;
  case 1:
    return "READY";
  case 2:
    return "M0";
  case 3:
    return "M1";
  case 4:
    return "M2";
  case 5:
    return "M3";
  case 6:
    return "M3 FAST";
  case 7:
    return "BHI";
  default:
    if (param_1 == 0xff) {
      return "SYS ERROR";
    }
    pcVar1 = "Unknown state";
switchD_001061e8_caseD_0:
    return pcVar1;
  }
}



//------------------------------------------------------------
// mhi_intvec_handler @ 00106264 size=48
// signature: undefined mhi_intvec_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_intvec_handler(undefined8 param_1,long param_2)

{
  __wake_up(param_2 + 0x210,3,0,0);
  return 2;
}



//------------------------------------------------------------
// mhi_process_ctrl_ev_ring @ 00106298 size=2044
// signature: undefined mhi_process_ctrl_ev_ring(void)
// callers: []
//------------------------------------------------------------

int mhi_process_ctrl_ev_ring(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  int iVar11;
  ulong *puVar12;
  undefined8 uVar13;
  long lVar14;
  ulong *puVar15;
  long lVar16;
  
  iVar11 = -5;
  if ((*(uint *)(param_1 + 0x184) != 1) && (*(uint *)(param_1 + 0x184) < 0x80)) {
    lVar10 = *(long *)(param_1 + 8);
    uVar7 = param_2[6];
    puVar12 = (ulong *)(**(long **)(param_1 + 0x140) + (ulong)*(uint *)(param_2 + 2) * 0x2c + 0x1c);
    uVar8 = *puVar12;
    if ((uVar8 < uVar7) || ((uVar8 & 0xf) != 0 || param_2[0xd] + uVar7 <= uVar8)) {
      lVar14 = *(long *)(lVar10 + 0xc0);
      _dev_err(lVar10 + 0x28,"[E][%s] Event ring rp points outside of the event ring\n",
               "mhi_process_ctrl_ev_ring");
joined_r0x00106a68:
      if ((lVar14 != 0) && (*(uint *)(lVar14 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar14 + 0x20),
                       "[E][%s] Event ring rp points outside of the event ring\n",
                       "mhi_process_ctrl_ev_ring");
      }
      iVar11 = -5;
    }
    else {
      lVar14 = param_2[9];
      puVar15 = (ulong *)param_2[10];
      if ((ulong *)(lVar14 + (uVar8 - uVar7)) == puVar15) {
        iVar11 = 0;
      }
      else {
        iVar11 = 0;
        lVar1 = param_1 + 0x178;
        do {
          uVar6 = *(uint *)((long)puVar15 + 0xc);
          lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          if ((lVar9 != 0) && (*(int *)(lVar9 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar9 + 0x20),
                           "[D][%s] RP:0x%llx Processing Event:0x%llx 0x%08x 0x%08x\n",
                           "mhi_process_ctrl_ev_ring",(long)puVar15 + (uVar7 - lVar14),*puVar15,
                           (int)puVar15[1],uVar6);
          }
          uVar6 = uVar6 >> 0x10 & 0xff;
          switch(uVar6) {
          case 0x20:
            uVar7 = puVar15[1];
            lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            uVar6 = (uint)uVar7 >> 0x18;
            if ((lVar14 == 0) || (*(int *)(lVar14 + 0x18) != 0)) {
              if (4 < uVar6) goto LAB_00106670;
LAB_001063d4:
              if (uVar6 == 2) {
                mhi_pm_m0_transition(param_1);
              }
              else {
                if (uVar6 != 3) goto LAB_001068c4;
                mhi_pm_m1_transition(param_1);
              }
            }
            else {
              pcVar5 = "Unknown state";
              if ((uVar6 + 1 & 0xff) < 9) {
                pcVar5 = *(char **)(&DAT_00116128 + (long)(char)(uVar6 + 1) * 8);
              }
              ipc_log_string(*(undefined8 *)(lVar14 + 0x20),
                             "[D][%s] State change event to state: %s\n","mhi_process_ctrl_ev_ring",
                             pcVar5);
              if (uVar6 < 5) goto LAB_001063d4;
LAB_00106670:
              if (uVar6 == 5) {
                mhi_pm_m3_transition(param_1);
                break;
              }
              if (uVar6 == 0xff) {
                lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
                if ((lVar14 != 0) && (*(int *)(lVar14 + 0x18) == 0)) {
                  ipc_log_string(*(undefined8 *)(lVar14 + 0x20),"[D][%s] System error detected\n",
                                 "mhi_process_ctrl_ev_ring");
                }
                _raw_write_lock_irq(lVar1);
                iVar3 = mhi_tryset_pm_state(param_1,0x100);
                _raw_write_unlock_irq(lVar1);
                if (iVar3 == 0x100) {
                  mhi_pm_sys_err_handler(param_1);
                }
                break;
              }
LAB_001068c4:
              pcVar5 = "Unknown state";
              if (uVar6 < 8) {
                pcVar5 = (&PTR_s_RESET_00116170)[(char)(uVar7 >> 0x18)];
              }
              lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
              _dev_err(lVar10 + 0x28,"[E][%s] Invalid state: %s\n","mhi_process_ctrl_ev_ring",pcVar5
                      );
              if ((lVar14 != 0) && (*(uint *)(lVar14 + 0x18) < 3)) {
                uVar13 = *(undefined8 *)(lVar14 + 0x20);
                uVar4 = mhi_state_str(uVar6);
                ipc_log_string(uVar13,"[E][%s] Invalid state: %s\n","mhi_process_ctrl_ev_ring",uVar4
                              );
              }
            }
            break;
          case 0x21:
            lVar9 = *(long *)(param_1 + 0x138);
            uVar7 = *puVar15;
            lVar14 = *(long *)(param_1 + 8);
            uVar8 = *(ulong *)(lVar9 + 8);
            if (((uVar7 < uVar8) || ((uVar7 & 0xf) != 0)) ||
               (*(long *)(lVar9 + 0x40) + uVar8 <= uVar7)) {
              lVar9 = *(long *)(lVar14 + 0xc0);
              _dev_err(lVar14 + 0x28,"[E][%s] Event element points outside of the cmd ring\n",
                       "mhi_process_cmd_completion");
              if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
                ipc_log_string(*(undefined8 *)(lVar9 + 0x20),
                               "[E][%s] Event element points outside of the cmd ring\n",
                               "mhi_process_cmd_completion");
              }
            }
            else {
              lVar16 = *(long *)(lVar9 + 0x20) + (uVar7 - uVar8);
              if (lVar16 != *(long *)(lVar9 + 0x28)) {
                    /* WARNING: Subroutine does not return */
                panic("Out of order cmd completion: 0x%llx. Expected: 0x%llx\n");
              }
              uVar6 = *(uint *)(lVar16 + 0xc);
              if ((uVar6 & 0xff0000) == 0x490000) {
                mhi_misc_cmd_completion(param_1,0x49,*(undefined1 *)((long)puVar15 + 0xb));
              }
              else {
                uVar6 = uVar6 >> 0x18;
                if ((uVar6 < *(uint *)(param_1 + 0xc0)) &&
                   (*(char *)(*(long *)(param_1 + 0xa0) + (ulong)uVar6 * 400 + 0x189) != '\0')) {
                  lVar14 = *(long *)(param_1 + 0xa0) + (ulong)uVar6 * 400;
                  _raw_write_lock_bh(lVar14 + 0x170);
                  *(uint *)(lVar14 + 0x108) = (uint)*(byte *)((long)puVar15 + 0xb);
                  complete(lVar14 + 0x150);
                  _raw_write_unlock_bh(lVar14 + 0x170);
                }
                else {
                  lVar16 = *(long *)(lVar14 + 0xc0);
                  _dev_err(lVar14 + 0x28,"[E][%s] Completion packet for invalid channel ID: %d\n",
                           "mhi_process_cmd_completion",uVar6);
                  if ((lVar16 != 0) && (*(uint *)(lVar16 + 0x18) < 3)) {
                    ipc_log_string(*(undefined8 *)(lVar16 + 0x20),
                                   "[E][%s] Completion packet for invalid channel ID: %d\n",
                                   "mhi_process_cmd_completion",uVar6);
                  }
                }
              }
              uVar7 = *(long *)(lVar9 + 0x28) + *(long *)(lVar9 + 0x38);
              if (*(ulong *)(lVar9 + 0x20) + *(long *)(lVar9 + 0x40) <= uVar7) {
                uVar7 = *(ulong *)(lVar9 + 0x20);
              }
              *(ulong *)(lVar9 + 0x28) = uVar7;
              DataMemoryBarrier(2,2);
            }
            break;
          case 0x22:
            uVar6 = *(uint *)((long)puVar15 + 0xc) >> 0x18;
            if (*(uint *)(param_1 + 0xc0) <= uVar6) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10698c);
              (*pcVar2)();
            }
            if ((uVar6 < *(uint *)(param_1 + 0xc0)) &&
               (*(char *)(*(long *)(param_1 + 0xa0) + (ulong)uVar6 * 400 + 0x189) != '\0')) {
              parse_xfer_event(param_1,puVar15,*(long *)(param_1 + 0xa0) + (ulong)uVar6 * 400);
            }
            break;
          default:
            lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            _dev_err(lVar10 + 0x28,"[E][%s] Unhandled event type: %d\n","mhi_process_ctrl_ev_ring",
                     uVar6);
            if ((lVar14 != 0) && (*(uint *)(lVar14 + 0x18) < 3)) {
              uVar4 = *(undefined8 *)(lVar14 + 0x20);
              pcVar5 = "[E][%s] Unhandled event type: %d\n";
LAB_0010686c:
              ipc_log_string(uVar4,pcVar5,"mhi_process_ctrl_ev_ring",uVar6);
            }
            break;
          case 0x40:
            uVar6 = (uint)puVar15[1];
            lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            if ((lVar14 != 0) && (*(int *)(lVar14 + 0x18) == 0)) {
              pcVar5 = "INVALID_EE";
              if (uVar6 >> 0x19 < 5) {
                pcVar5 = (&mhi_ee_str)[uVar6 >> 0x18];
              }
              ipc_log_string(*(undefined8 *)(lVar14 + 0x20),"[D][%s] Received EE event: %s\n",
                             "mhi_process_ctrl_ev_ring",pcVar5);
            }
            uVar4 = 2;
            switch(uVar6 >> 0x18) {
            case 1:
              break;
            case 2:
            case 4:
              uVar4 = 3;
              break;
            case 3:
              if (*(int *)(*(code **)(param_1 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10670c);
                (*pcVar2)();
              }
              (**(code **)(param_1 + 0x228))(param_1,4);
              _raw_write_lock_irq(lVar1);
              *(undefined4 *)(param_1 + 0x18c) = 3;
              _raw_write_unlock_irq(lVar1);
              __wake_up(param_1 + 0x210,3,0,0);
              goto LAB_0010674c;
            default:
              lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
              _dev_err(lVar10 + 0x28,"[E][%s] Unhandled EE event: 0x%x\n","mhi_process_ctrl_ev_ring"
                       ,0x40);
              if ((lVar14 != 0) && (*(uint *)(lVar14 + 0x18) < 3)) {
                uVar4 = *(undefined8 *)(lVar14 + 0x20);
                pcVar5 = "[E][%s] Unhandled EE event: 0x%x\n";
                uVar6 = 0x40;
                goto LAB_0010686c;
              }
              goto LAB_0010674c;
            case 7:
              uVar4 = 4;
            }
            mhi_queue_state_transition(param_1,uVar4);
            break;
          case 0x50:
            _raw_write_lock_irq(lVar1);
            *(uint *)(param_1 + 0x1c8) = (uint)*(byte *)((long)puVar15 + 0xf);
            *(uint *)(param_1 + 0x1cc) = (uint)(byte)puVar15[1];
            _raw_write_unlock_irq(lVar1);
            lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            if ((lVar14 != 0) && (*(int *)(lVar14 + 0x18) == 0)) {
              ipc_log_string(*(undefined8 *)(lVar14 + 0x20),"[D][%s] Received BW_REQ event\n",
                             "mhi_process_ctrl_ev_ring");
            }
            if (*(int *)(*(code **)(param_1 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10658c);
              (*pcVar2)();
            }
            (**(code **)(param_1 + 0x228))(param_1,8);
          }
LAB_0010674c:
          uVar8 = param_2[9];
          uVar7 = param_2[0xb] + param_2[0xc];
          if (uVar8 + param_2[0xd] <= (ulong)(param_2[0xb] + param_2[0xc])) {
            uVar7 = uVar8;
          }
          param_2[0xb] = uVar7;
          *(ulong *)param_2[7] = (param_2[6] - uVar8) + uVar7;
          uVar7 = param_2[10] + param_2[0xc];
          if ((ulong)(param_2[9] + param_2[0xd]) <= (ulong)(param_2[10] + param_2[0xc])) {
            uVar7 = param_2[9];
          }
          param_2[10] = uVar7;
          DataMemoryBarrier(2,2);
          uVar8 = *puVar12;
          uVar7 = param_2[6];
          if (((uVar8 < uVar7) || ((uVar8 & 0xf) != 0)) || (param_2[0xd] + uVar7 <= uVar8)) {
            lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            _dev_err(lVar10 + 0x28,"[E][%s] Event ring rp points outside of the event ring\n",
                     "mhi_process_ctrl_ev_ring");
            goto joined_r0x00106a68;
          }
          lVar14 = param_2[9];
          puVar15 = (ulong *)param_2[10];
          iVar11 = iVar11 + 1;
        } while ((ulong *)(lVar14 + (uVar8 - uVar7)) != puVar15);
      }
      _raw_read_lock_bh(param_1 + 0x178);
      if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0) {
        if (*(int *)((code *)param_2[0x14] + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1069ec);
          (*pcVar2)();
        }
        (*(code *)param_2[0x14])(*param_2,param_2 + 0x11,param_2[0x10],*(undefined8 *)param_2[7]);
      }
      _raw_read_unlock_bh(param_1 + 0x178);
    }
  }
  return iVar11;
}



//------------------------------------------------------------
// parse_xfer_event @ 00106aa4 size=1088
// signature: undefined parse_xfer_event(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_process_data_event_ring]
//------------------------------------------------------------

void parse_xfer_event(long param_1,ulong *param_2,long param_3)

{
  int *piVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  uint uVar6;
  char cVar7;
  bool bVar8;
  code *pcVar9;
  int iVar10;
  undefined8 uVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  undefined8 local_c0;
  undefined8 local_b8;
  ulong local_b0;
  long local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_b0 = 0;
  lVar14 = *(long *)(param_1 + 8);
  local_b8 = 0;
  uVar6 = (uint)param_2[1] >> 0x18;
  uVar12 = 0xffffffb5;
  if (uVar6 != 3) {
    uVar12 = 0;
  }
  local_a8 = (ulong)uVar12 << 0x20;
  if (uVar6 < 5) {
    _raw_read_lock_bh(param_3 + 0x170);
    local_c0 = 0;
  }
  else {
    local_c0 = _raw_write_lock_irqsave();
  }
  if (*(int *)(param_3 + 0x104) == 1) {
    if (uVar6 - 2 < 3) {
      uVar15 = *param_2;
      uVar16 = *(ulong *)(param_3 + 0x70);
      if (((uVar15 < uVar16) || ((uVar15 & 0xf) != 0)) ||
         (*(long *)(param_3 + 0xa8) + uVar16 <= uVar15)) {
        lVar17 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        _dev_err(lVar14 + 0x28,"[E][%s] Event element points outside of the tre ring\n",
                 "parse_xfer_event");
        if ((lVar17 != 0) && (*(uint *)(lVar17 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar17 + 0x20),
                         "[E][%s] Event element points outside of the tre ring\n","parse_xfer_event"
                        );
        }
      }
      else {
        uVar5 = *(ulong *)(param_3 + 0x88);
        uVar18 = *(ulong *)(param_3 + 0x90);
        uVar16 = uVar5 + (uVar15 - uVar16);
        uVar2 = uVar5 + *(long *)(param_3 + 0xa8);
        uVar15 = uVar16 + 0x10;
        if (uVar2 <= uVar15) {
          uVar15 = uVar5;
        }
        uVar4 = uVar18 + 0x10;
        if (uVar2 <= uVar18 + 0x10) {
          uVar4 = uVar5;
        }
        local_a8 = CONCAT44(local_a8._4_4_,*(undefined4 *)(param_3 + 0xd8));
        if ((uVar15 == uVar4) || ((*(byte *)(uVar18 + 0xc) & 1) != 0)) {
          if (uVar18 != uVar15) {
            do {
              lVar17 = *(long *)(param_3 + 0x30);
              if (uVar18 == uVar16) {
                uVar12 = (uint)(ushort)param_2[1];
              }
              else {
                uVar12 = (uint)*(undefined8 *)(lVar17 + 0x28);
              }
              lVar13 = lVar17;
              if (*(char *)(lVar17 + 0x35) == '\0') {
                if (*(int *)(*(code **)(param_1 + 0x278) + -4) != -0x12d1612e) {
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106d08);
                  (*pcVar9)();
                }
                (**(code **)(param_1 + 0x278))(param_1,lVar17);
                lVar13 = *(long *)(param_3 + 0x30);
              }
              uVar2 = lVar13 + *(long *)(param_3 + 0x40);
              uVar3 = uVar12 & 0xffff;
              if ((uint)*(ushort *)(lVar17 + 0x28) <= (uVar12 & 0xffff)) {
                uVar3 = (uint)*(ushort *)(lVar17 + 0x28);
              }
              local_b0 = (ulong)uVar3;
              local_b8 = *(undefined8 *)(lVar17 + 0x18);
              if (*(ulong *)(param_3 + 0x28) + *(long *)(param_3 + 0x48) <= uVar2) {
                uVar2 = *(ulong *)(param_3 + 0x28);
              }
              *(ulong *)(param_3 + 0x30) = uVar2;
              DataMemoryBarrier(2,2);
              uVar2 = *(long *)(param_3 + 0x90) + *(long *)(param_3 + 0xa0);
              if (*(ulong *)(param_3 + 0x88) + *(long *)(param_3 + 0xa8) <= uVar2) {
                uVar2 = *(ulong *)(param_3 + 0x88);
              }
              *(ulong *)(param_3 + 0x90) = uVar2;
              DataMemoryBarrier(2,2);
              uVar18 = *(ulong *)(param_3 + 0x90);
              _raw_read_unlock_bh(param_3 + 0x170);
              if (*(int *)(*(code **)(param_3 + 0x118) + -4) != 0x26e788e6) {
                    /* WARNING: Does not return */
                pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106d94);
                (*pcVar9)();
              }
              (**(code **)(param_3 + 0x118))(*(undefined8 *)(param_3 + 0x110),&local_b8);
              if (*(int *)(param_3 + 0xd8) == 1) {
                piVar1 = (int *)(param_1 + 0x198);
                Hint_Prefetch(piVar1,2,0,1);
                do {
                  cVar7 = '\x01';
                  bVar8 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                  if (bVar8) {
                    *piVar1 = *piVar1 + -1;
                    cVar7 = ExclusiveMonitorsStatus();
                  }
                } while (cVar7 != '\0');
                cVar7 = *(char *)(param_3 + 0x18b);
              }
              else {
                cVar7 = *(char *)(param_3 + 0x18b);
              }
              if (cVar7 != '\0') {
                local_a0 = *(undefined8 *)(lVar17 + 0x18);
                local_78 = *(undefined8 *)(lVar17 + 0x28);
                uStack_70 = 0;
                uStack_80 = 0;
                local_98 = 0;
                uStack_90 = 0;
                local_88 = local_a0;
                iVar10 = mhi_queue(*(undefined8 *)(param_3 + 0x110),&local_a0,
                                   *(undefined4 *)(param_3 + 0xd8),2);
                if (iVar10 != 0) {
                  lVar13 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
                  _dev_err(lVar14 + 0x28,"[E][%s] Error recycling buffer for chan:%d\n",
                           "parse_xfer_event",*(undefined4 *)(param_3 + 200));
                  if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
                    ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                                   "[E][%s] Error recycling buffer for chan:%d\n","parse_xfer_event"
                                   ,*(undefined4 *)(param_3 + 200));
                  }
                  kfree(*(undefined8 *)(lVar17 + 0x18));
                }
              }
              _raw_read_lock_bh(param_3 + 0x170);
            } while (uVar18 != uVar15);
          }
        }
        else {
          _dev_err(*(long *)(param_1 + 8) + 0x28,"Event element points to an unexpected TRE\n");
        }
      }
    }
    else {
      if (1 < uVar6 - 5) {
                    /* WARNING: Subroutine does not return */
        panic("Unknown event 0x%x\n",uVar6);
      }
      *(undefined1 *)(param_3 + 0xe1) = 1;
      uVar11 = _raw_read_lock_irqsave(param_1 + 0x178);
      if ((*(long *)(param_3 + 0x98) != *(long *)(param_3 + 0x90)) &&
         ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0)) {
        DataMemoryBarrier(0,2);
        **(long **)(param_3 + 0x78) =
             (*(long *)(param_3 + 0x98) - *(long *)(param_3 + 0x88)) + *(long *)(param_3 + 0x70);
        if (*(int *)(*(code **)(param_3 + 0xf8) + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106c40);
          (*pcVar9)();
        }
        (**(code **)(param_3 + 0xf8))(param_1,param_3 + 0xe0,*(undefined8 *)(param_3 + 0xc0));
      }
      _raw_read_unlock_irqrestore(param_1 + 0x178,uVar11);
    }
  }
  if (uVar6 < 5) {
    _raw_read_unlock_bh(param_3 + 0x170);
  }
  else {
    _raw_write_unlock_irqrestore(param_3 + 0x170,local_c0);
  }
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_process_data_event_ring @ 00106ef4 size=744
// signature: undefined mhi_process_data_event_ring(void)
// callers: []
//------------------------------------------------------------

int mhi_process_data_event_ring(long param_1,undefined8 *param_2,int param_3)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  int iVar8;
  undefined8 *puVar9;
  ulong *puVar10;
  
  iVar8 = -5;
  if ((*(uint *)(param_1 + 0x184) != 1) && (*(uint *)(param_1 + 0x184) < 0x80)) {
    lVar7 = *(long *)(param_1 + 8);
    uVar6 = param_2[6];
    puVar10 = (ulong *)(**(long **)(param_1 + 0x140) + (ulong)*(uint *)(param_2 + 2) * 0x2c + 0x1c);
    uVar5 = *puVar10;
    if ((uVar5 < uVar6) || ((uVar5 & 0xf) != 0 || param_2[0xd] + uVar6 <= uVar5)) {
      lVar4 = *(long *)(lVar7 + 0xc0);
      _dev_err(lVar7 + 0x28,"[E][%s] Event ring rp points outside of the event ring\n",
               "mhi_process_data_event_ring");
joined_r0x001071bc:
      if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                       "[E][%s] Event ring rp points outside of the event ring\n",
                       "mhi_process_data_event_ring");
      }
      iVar8 = -5;
    }
    else {
      puVar9 = (undefined8 *)param_2[10];
      iVar8 = 0;
      if (((undefined8 *)(param_2[9] + (uVar5 - uVar6)) != puVar9) && (param_3 != 0)) {
        iVar8 = 0;
        do {
          uVar1 = *(uint *)((long)puVar9 + 0xc);
          lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          if ((lVar4 == 0) || (*(int *)(lVar4 + 0x18) != 0)) {
            uVar3 = uVar1;
          }
          else {
            ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                           "[D][%s] Processing Event:0x%llx 0x%08x 0x%08x\n",
                           "mhi_process_data_event_ring",*puVar9,*(undefined4 *)(puVar9 + 1),uVar1);
            uVar3 = *(uint *)((long)puVar9 + 0xc);
          }
          uVar3 = uVar3 >> 0x18;
          if (*(uint *)(param_1 + 0xc0) <= uVar3) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1070cc);
            (*pcVar2)();
          }
          if ((uVar3 < *(uint *)(param_1 + 0xc0)) &&
             (lVar4 = *(long *)(param_1 + 0xa0) + (ulong)uVar3 * 400,
             *(char *)(lVar4 + 0x189) != '\0')) {
            uVar1 = uVar1 >> 0x10 & 0xff;
            if (uVar1 == 0x22) {
              parse_xfer_event(param_1,puVar9);
            }
            else {
              if (uVar1 != 0x28) goto LAB_00107034;
              parse_rsc_event(puVar9,lVar4);
            }
            param_3 = param_3 + -1;
          }
LAB_00107034:
          uVar6 = param_2[9];
          uVar5 = param_2[0xb] + param_2[0xc];
          if (uVar6 + param_2[0xd] <= (ulong)(param_2[0xb] + param_2[0xc])) {
            uVar5 = uVar6;
          }
          param_2[0xb] = uVar5;
          *(ulong *)param_2[7] = (param_2[6] - uVar6) + uVar5;
          uVar5 = param_2[10] + param_2[0xc];
          if ((ulong)(param_2[9] + param_2[0xd]) <= (ulong)(param_2[10] + param_2[0xc])) {
            uVar5 = param_2[9];
          }
          param_2[10] = uVar5;
          DataMemoryBarrier(2,2);
          uVar5 = *puVar10;
          uVar6 = param_2[6];
          if (((uVar5 < uVar6) || ((uVar5 & 0xf) != 0)) || (param_2[0xd] + uVar6 <= uVar5)) {
            lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            _dev_err(lVar7 + 0x28,"[E][%s] Event ring rp points outside of the event ring\n",
                     "mhi_process_data_event_ring");
            goto joined_r0x001071bc;
          }
          puVar9 = (undefined8 *)param_2[10];
          iVar8 = iVar8 + 1;
        } while (((undefined8 *)(param_2[9] + (uVar5 - uVar6)) != puVar9) && (param_3 != 0));
      }
      _raw_read_lock_bh(param_1 + 0x178);
      if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0) {
        if (*(int *)((code *)param_2[0x14] + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107140);
          (*pcVar2)();
        }
        (*(code *)param_2[0x14])(*param_2,param_2 + 0x11,param_2[0x10],*(undefined8 *)param_2[7]);
      }
      _raw_read_unlock_bh(param_1 + 0x178);
    }
  }
  return iVar8;
}



//------------------------------------------------------------
// parse_rsc_event @ 001071ec size=292
// signature: undefined parse_rsc_event(void)
// callers: [mhi_process_data_event_ring]
//------------------------------------------------------------

void parse_rsc_event(uint *param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 local_50;
  ulong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (*(ulong *)(param_2 + 0x48) <= (ulong)*param_1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x107308);
    (*pcVar4)();
  }
  local_3c = 0xffffffb5;
  if (param_1[2] >> 0x18 != 3) {
    local_3c = 0;
  }
  uVar3 = param_1[2] & 0xffff;
  lVar1 = *(long *)(param_2 + 0x28) + (ulong)*param_1;
  if (*(ushort *)(lVar1 + 0x28) <= uVar3) {
    uVar3 = (uint)*(ushort *)(lVar1 + 0x28);
  }
  local_48 = (ulong)uVar3;
  local_40 = *(undefined4 *)(param_2 + 0xd8);
  local_50 = *(undefined8 *)(lVar1 + 0x18);
  _raw_read_lock_bh(param_2 + 0x170);
  if (*(int *)(param_2 + 0x104) == 1) {
    if (*(char *)(lVar1 + 0x34) == '\0') {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x107310);
      (*pcVar4)();
    }
    if (*(int *)(*(code **)(param_2 + 0x118) + -4) != 0x26e788e6) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1072a8);
      (*pcVar4)();
    }
    (**(code **)(param_2 + 0x118))(*(undefined8 *)(param_2 + 0x110),&local_50);
    uVar2 = *(long *)(param_2 + 0x90) + *(long *)(param_2 + 0xa0);
    if (*(ulong *)(param_2 + 0x88) + *(long *)(param_2 + 0xa8) <= uVar2) {
      uVar2 = *(ulong *)(param_2 + 0x88);
    }
    *(ulong *)(param_2 + 0x90) = uVar2;
    DataMemoryBarrier(2,2);
    *(undefined1 *)(lVar1 + 0x34) = 0;
  }
  _raw_read_unlock_bh(param_2 + 0x170);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_ev_task @ 0010731c size=112
// signature: undefined mhi_ev_task(void)
// callers: []
//------------------------------------------------------------

void mhi_ev_task(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = *param_1;
  _raw_spin_lock_bh(param_1 + 0x20);
  if (*(int *)((code *)param_1[0x21] + -4) != -0x70dbf4ec) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10736c);
    (*pcVar1)();
  }
  (*(code *)param_1[0x21])(uVar2,param_1,0xffffffff);
  _raw_spin_unlock_bh(param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// mhi_ctrl_ev_task @ 00107390 size=432
// signature: undefined mhi_ctrl_ev_task(void)
// callers: []
//------------------------------------------------------------

void mhi_ctrl_ev_task(long *param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined4 local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *param_1;
  if ((*(ushort *)(lVar5 + 0x184) & 0xfde) == 0) {
    pm_wakeup_dev_event(*(long *)(lVar5 + 8) + 0x28,0,0);
    if (*(int *)(*(code **)(lVar5 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1074dc);
      (*pcVar2)();
    }
    (**(code **)(lVar5 + 0x248))(lVar5);
    if (*(int *)(*(code **)(lVar5 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107500);
      (*pcVar2)();
    }
    (**(code **)(lVar5 + 600))(lVar5);
  }
  else {
    if (*(int *)((code *)param_1[0x21] + -4) != -0x70dbf4ec) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1073f0);
      (*pcVar2)();
    }
    iVar3 = (*(code *)param_1[0x21])(lVar5,param_1,0xffffffff);
    if (iVar3 == 0) {
      lVar1 = lVar5 + 0x178;
      _raw_write_lock_irq(lVar1);
      local_3c = 0;
      if (*(int *)(*(code **)(lVar5 + 0x280) + -4) != -0x452aba71) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x107434);
        (*pcVar2)();
      }
      iVar3 = (**(code **)(lVar5 + 0x280))(lVar5,*(long *)(lVar5 + 0x18) + 0x48,&local_3c);
      if ((iVar3 == 0) && (local_3c._1_1_ == -1)) {
        lVar4 = *(long *)(*(long *)(lVar5 + 8) + 0xc0);
        if ((lVar4 != 0) && (*(int *)(lVar4 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[D][%s] System error detected\n",
                         "mhi_ctrl_ev_task");
        }
        iVar3 = mhi_tryset_pm_state(lVar5,0x100);
        _raw_write_unlock_irq(lVar1);
        if (iVar3 == 0x100) {
          mhi_pm_sys_err_handler(lVar5);
        }
      }
      else {
        _raw_write_unlock_irq(lVar1);
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_process_ev_work @ 00107544 size=368
// signature: undefined mhi_process_ev_work(void)
// callers: []
//------------------------------------------------------------

void mhi_process_ev_work(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  char *pcVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  
  lVar6 = *(long *)(param_1 + -0xd0);
  lVar5 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
  if ((lVar5 != 0) && (*(int *)(lVar5 + 0x18) == 0)) {
    uVar7 = *(undefined8 *)(lVar5 + 0x20);
    uVar2 = to_mhi_pm_state_str(*(undefined4 *)(lVar6 + 0x184));
    pcVar3 = "RESET";
    switch(*(int *)(lVar6 + 400)) {
    case 0:
      break;
    case 1:
      pcVar3 = "READY";
      break;
    case 2:
      pcVar3 = "M0";
      break;
    case 3:
      pcVar3 = "M1";
      break;
    case 4:
      pcVar3 = "M2";
      break;
    case 5:
      pcVar3 = "M3";
      break;
    case 6:
      pcVar3 = "M3 FAST";
      break;
    case 7:
      pcVar3 = "BHI";
      break;
    default:
      if (*(int *)(lVar6 + 400) == 0xff) {
        pcVar3 = "SYS ERROR";
      }
      else {
        pcVar3 = "Unknown state";
      }
    }
    if (*(uint *)(lVar6 + 0x18c) < 10) {
      pcVar4 = (&mhi_ee_str)[*(uint *)(lVar6 + 0x18c)];
    }
    else {
      pcVar4 = "INVALID_EE";
    }
    ipc_log_string(uVar7,"[D][%s] Enter with pm_state:%s MHI_STATE:%s ee:%s\n","mhi_process_ev_work"
                   ,uVar2,pcVar3,pcVar4);
  }
  if ((*(uint *)(lVar6 + 0x184) != 1) && (*(uint *)(lVar6 + 0x184) < 0x80)) {
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != -0x70dbf4ec) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10769c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x38))(lVar6,(long *)(param_1 + -0xd0),0xffffffff);
  }
  return;
}



//------------------------------------------------------------
// mhi_queue_skb @ 001076b8 size=144
// signature: undefined mhi_queue_skb(void)
// callers: []
//------------------------------------------------------------

void mhi_queue_skb(long param_1,int param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long lStack_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  lVar1 = 0x18;
  if (param_2 != 1) {
    lVar1 = 0x20;
  }
  uStack_20 = 0;
  local_40 = 0;
  local_50 = *(undefined8 *)(param_3 + 0xe0);
  local_30 = 0;
  uStack_48 = 0;
  lStack_38 = param_3;
  local_28 = param_4;
  if (*(char *)(*(long *)(param_1 + lVar1) + 0x18b) == '\0') {
    uVar2 = mhi_queue(param_1,&local_50,param_2,param_5);
  }
  else {
    uVar2 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// mhi_queue @ 00107748 size=500
// signature: undefined mhi_queue(void)
// callers: [parse_xfer_event, mhi_queue_dma, mhi_queue_skb, mhi_queue_buf]
//------------------------------------------------------------

undefined8 mhi_queue(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  ulong uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  
  lVar7 = *(long *)(param_1 + 0x10);
  lVar8 = 0x18;
  if (param_3 != 1) {
    lVar8 = 0x20;
  }
  if (*(uint *)(lVar7 + 0x184) < 0x80) {
    lVar8 = *(long *)(param_1 + lVar8);
    uVar2 = *(long *)(lVar8 + 0x98) + *(long *)(lVar8 + 0xa0);
    if (*(ulong *)(lVar8 + 0x88) + *(long *)(lVar8 + 0xa8) <= uVar2) {
      uVar2 = *(ulong *)(lVar8 + 0x88);
    }
    if (uVar2 == *(ulong *)(lVar8 + 0x90)) {
      uVar5 = 0xfffffff5;
    }
    else {
      uVar5 = mhi_gen_tre(lVar7,lVar8,param_2);
      if ((int)uVar5 == 0) {
        pcVar6 = *(code **)(lVar7 + 0x268);
        if (pcVar6 != (code *)0x0) {
          if (*(int *)(pcVar6 + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1077e0);
            (*pcVar6)();
          }
          (*pcVar6)(lVar7);
        }
        uVar5 = _raw_read_lock_irqsave(lVar7 + 0x178);
        if ((*(byte *)(lVar7 + 0x184) & 0x30) != 0) {
          pm_wakeup_dev_event(*(long *)(lVar7 + 8) + 0x28,0,0);
          if (*(int *)(*(code **)(lVar7 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107834);
            (*pcVar6)();
          }
          (**(code **)(lVar7 + 0x248))(lVar7);
          if (*(int *)(*(code **)(lVar7 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107858);
            (*pcVar6)();
          }
          (**(code **)(lVar7 + 600))(lVar7);
        }
        if (*(int *)(*(code **)(lVar7 + 0x240) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10787c);
          (*pcVar6)();
        }
        (**(code **)(lVar7 + 0x240))(lVar7);
        if (*(int *)(lVar8 + 0xd8) == 1) {
          piVar1 = (int *)(lVar7 + 0x198);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = *piVar1 + 1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
        }
        if ((*(uint *)(lVar7 + 0x188) & *(uint *)(lVar7 + 0x184)) != 0) {
          DataMemoryBarrier(0,2);
          **(long **)(lVar8 + 0x78) =
               (*(long *)(lVar8 + 0x98) - *(long *)(lVar8 + 0x88)) + *(long *)(lVar8 + 0x70);
          if (*(int *)(*(code **)(lVar8 + 0xf8) + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1078f4);
            (*pcVar6)();
          }
          (**(code **)(lVar8 + 0xf8))(lVar7,lVar8 + 0xe0,*(undefined8 *)(lVar8 + 0xc0));
        }
        _raw_read_unlock_irqrestore(lVar7 + 0x178,uVar5);
        uVar5 = 0;
      }
    }
  }
  else {
    uVar5 = 0xfffffffb;
  }
  return uVar5;
}



//------------------------------------------------------------
// mhi_queue_dma @ 0010794c size=152
// signature: undefined mhi_queue_dma(void)
// callers: []
//------------------------------------------------------------

void mhi_queue_dma(long param_1,int param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long lStack_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  lVar1 = 0x18;
  if (param_2 != 1) {
    lVar1 = 0x20;
  }
  local_30 = *(undefined8 *)(param_3 + 0x10);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uStack_20 = 0x10000000000;
  lStack_38 = param_3;
  local_28 = param_4;
  if (*(char *)(*(long *)(param_1 + lVar1) + 0x18b) == '\0') {
    uVar2 = mhi_queue(param_1,&local_50,param_2,param_5);
  }
  else {
    uVar2 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// mhi_gen_tre @ 001079e8 size=456
// signature: undefined mhi_gen_tre(void)
// callers: [mhi_prepare_channel, mhi_queue]
//------------------------------------------------------------

int mhi_gen_tre(long param_1,long param_2,undefined8 *param_3,uint param_4)

{
  ulong uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 *puVar7;
  
  _raw_write_lock_bh(param_2 + 0x170);
  if (*(int *)(param_2 + 0x104) == 1) {
    puVar7 = *(undefined8 **)(param_2 + 0x38);
    if (*(char *)((long)puVar7 + 0x34) != '\0') {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x107bb0);
      (*pcVar3)();
    }
    *(undefined1 *)((long)puVar7 + 0x35) = *(undefined1 *)((long)param_3 + 0x35);
    if (*(char *)((long)param_3 + 0x35) == '\0') {
      *puVar7 = *param_3;
    }
    else {
      puVar7[4] = param_3[4];
    }
    puVar7[3] = param_3[3];
    puVar7[2] = *(undefined8 *)(param_2 + 0x98);
    *(undefined4 *)(puVar7 + 6) = *(undefined4 *)(param_2 + 0xd8);
    puVar7[5] = param_3[5];
    if (*(char *)((long)param_3 + 0x35) == '\0') {
      if (*(int *)(*(code **)(param_1 + 0x270) + -4) != -0x2b839958) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107b78);
        (*pcVar3)();
      }
      iVar4 = (**(code **)(param_1 + 0x270))(param_1,puVar7);
      if (iVar4 != 0) goto LAB_00107b84;
    }
    puVar5 = *(undefined8 **)(param_2 + 0x98);
    uVar2 = 0x20000;
    if (*(int *)(param_2 + 0xd0) != 0) {
      uVar2 = 0x20400;
    }
    *puVar5 = puVar7[4];
    *(uint *)(puVar5 + 1) = (uint)*(ushort *)(param_3 + 5);
    *(uint *)((long)puVar5 + 0xc) = param_4 >> 2 & 1 | (param_4 & 3) << 8 | uVar2;
    lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar6 != 0) && (*(int *)(lVar6 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                     "[D][%s] Chan: %d WP: 0x%llx TRE: 0x%llx 0x%08x 0x%08x\n","mhi_gen_tre",
                     *(undefined4 *)(param_2 + 200),
                     (long)puVar5 + (*(long *)(param_2 + 0x70) - *(long *)(param_2 + 0x88)));
    }
    iVar4 = 0;
    uVar1 = *(long *)(param_2 + 0x98) + *(long *)(param_2 + 0xa0);
    if (*(ulong *)(param_2 + 0x88) + *(long *)(param_2 + 0xa8) <= uVar1) {
      uVar1 = *(ulong *)(param_2 + 0x88);
    }
    *(ulong *)(param_2 + 0x98) = uVar1;
    DataMemoryBarrier(2,2);
    uVar1 = *(long *)(param_2 + 0x38) + *(long *)(param_2 + 0x40);
    if (*(ulong *)(param_2 + 0x28) + *(long *)(param_2 + 0x48) <= uVar1) {
      uVar1 = *(ulong *)(param_2 + 0x28);
    }
    *(ulong *)(param_2 + 0x38) = uVar1;
    DataMemoryBarrier(2,2);
  }
  else {
    iVar4 = -0x13;
  }
LAB_00107b84:
  _raw_write_unlock_bh(param_2 + 0x170);
  return iVar4;
}



//------------------------------------------------------------
// mhi_queue_buf @ 00107bb8 size=104
// signature: undefined mhi_queue_buf(void)
// callers: []
//------------------------------------------------------------

void mhi_queue_buf(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5)

{
  long lVar1;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  uStack_20 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 0;
  local_50 = param_3;
  uStack_38 = param_3;
  local_28 = param_4;
  mhi_queue(param_1,&local_50,param_2,param_5);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_queue_is_full @ 00107c24 size=60
// signature: undefined mhi_queue_is_full(void)
// callers: []
//------------------------------------------------------------

bool mhi_queue_is_full(long param_1,int param_2)

{
  ulong uVar1;
  long lVar2;
  
  lVar2 = 0x18;
  if (param_2 != 1) {
    lVar2 = 0x20;
  }
  lVar2 = *(long *)(param_1 + lVar2);
  uVar1 = *(long *)(lVar2 + 0x98) + *(long *)(lVar2 + 0xa0);
  if (*(ulong *)(lVar2 + 0x88) + *(long *)(lVar2 + 0xa8) <= uVar1) {
    uVar1 = *(ulong *)(lVar2 + 0x88);
  }
  return uVar1 == *(ulong *)(lVar2 + 0x90);
}



//------------------------------------------------------------
// mhi_send_cmd @ 00107c64 size=556
// signature: undefined mhi_send_cmd(void)
// callers: [mhi_misc_mission_mode, mhi_update_channel_state]
//------------------------------------------------------------

undefined8 mhi_send_cmd(long param_1,long param_2,int param_3)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  
  lVar11 = *(long *)(param_1 + 0x138);
  if (param_2 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = *(int *)(param_2 + 200) << 0x18;
  }
  lVar12 = *(long *)(param_1 + 8);
  _raw_spin_lock_bh(lVar11 + 0x60);
  puVar2 = *(undefined8 **)(lVar11 + 0x28);
  puVar3 = *(undefined8 **)(lVar11 + 0x30);
  if (puVar3 < puVar2) {
    iVar4 = 0;
    if (*(ulong *)(lVar11 + 0x38) != 0) {
      iVar4 = (int)((ulong)((long)puVar2 - (long)puVar3) / *(ulong *)(lVar11 + 0x38));
    }
    if (iVar4 == 1) {
LAB_00107d18:
      uVar8 = 0xfffffff4;
      goto LAB_00107e20;
    }
  }
  else {
    uVar1 = *(ulong *)(lVar11 + 0x38);
    iVar4 = 0;
    if (uVar1 != 0) {
      iVar4 = (int)((ulong)((long)puVar2 - *(long *)(lVar11 + 0x20)) / uVar1);
    }
    iVar5 = 0;
    if (uVar1 != 0) {
      iVar5 = (int)((ulong)((*(long *)(lVar11 + 0x20) + *(long *)(lVar11 + 0x40)) - (long)puVar3) /
                   uVar1);
    }
    if (iVar4 + -1 + iVar5 == 0) goto LAB_00107d18;
  }
  if (param_3 < 0x12) {
    if (param_3 == 0x10) {
      uVar10 = uVar10 | 0x100000;
LAB_00107d58:
      *puVar3 = 0;
      *(undefined4 *)(puVar3 + 1) = 0;
      *(uint *)((long)puVar3 + 0xc) = uVar10;
    }
    else {
      if (param_3 == 0x11) {
        uVar7 = 0x110000;
        goto LAB_00107d54;
      }
LAB_00107e44:
      lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar12 + 0x28,"[E][%s] Command not supported\n","mhi_send_cmd");
      if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[E][%s] Command not supported\n",
                       "mhi_send_cmd");
      }
    }
  }
  else {
    if (param_3 == 0x12) {
      uVar7 = 0x120000;
LAB_00107d54:
      uVar10 = uVar10 | uVar7;
      goto LAB_00107d58;
    }
    if (param_3 != 0x49) goto LAB_00107e44;
    mhi_misc_cmd_configure(param_1,0x49,puVar3,puVar3 + 1,(long)puVar3 + 0xc);
  }
  uVar1 = *(long *)(lVar11 + 0x30) + *(long *)(lVar11 + 0x38);
  if (*(ulong *)(lVar11 + 0x20) + *(long *)(lVar11 + 0x40) <= uVar1) {
    uVar1 = *(ulong *)(lVar11 + 0x20);
  }
  *(ulong *)(lVar11 + 0x30) = uVar1;
  DataMemoryBarrier(2,2);
  _raw_read_lock_bh(param_1 + 0x178);
  if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0) {
    uVar1 = (*(long *)(lVar11 + 0x30) - *(long *)(lVar11 + 0x20)) + *(long *)(lVar11 + 8);
    **(ulong **)(lVar11 + 0x10) = uVar1;
    lVar12 = *(long *)(lVar11 + 0x58);
    if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107de4);
      (*pcVar6)();
    }
    (**(code **)(param_1 + 0x288))(param_1,lVar12 + 4,uVar1 >> 0x20);
    if (*(int *)(*(code **)(param_1 + 0x288) + -4) != -0x1061b853) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107e10);
      (*pcVar6)();
    }
    (**(code **)(param_1 + 0x288))(param_1,lVar12,uVar1 & 0xffffffff);
  }
  _raw_read_unlock_bh(param_1 + 0x178);
  uVar8 = 0;
LAB_00107e20:
  _raw_spin_unlock_bh(lVar11 + 0x60);
  return uVar8;
}



//------------------------------------------------------------
// mhi_prepare_channel @ 00107e94 size=780
// signature: undefined mhi_prepare_channel(void)
// callers: [mhi_prepare_for_transfer, mhi_prepare_for_transfer_autoqueue]
//------------------------------------------------------------

int mhi_prepare_channel(long param_1,long param_2,byte param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  byte bVar5;
  ulong uVar6;
  code *pcVar7;
  int iVar8;
  long lVar9;
  char *pcVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  long local_90 [8];
  
  lVar11 = sp_el0;
  local_90[7] = *(long *)(lVar11 + 0x638);
  uVar4 = *(uint *)(param_1 + 0x18c);
  if ((*(uint *)(param_2 + 0x100) >> ((ulong)uVar4 & 0x3f) & 1) == 0) {
    lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if (uVar4 < 10) {
      pcVar10 = (&mhi_ee_str)[uVar4];
    }
    else {
      pcVar10 = "INVALID_EE";
    }
    _dev_err(*(long *)(param_2 + 0x110) + 0x28,"[E][%s] Current EE: %s Required EE Mask: 0x%x\n",
             "mhi_prepare_channel",pcVar10);
    if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
      if (*(uint *)(param_1 + 0x18c) < 10) {
        pcVar10 = (&mhi_ee_str)[*(uint *)(param_1 + 0x18c)];
      }
      else {
        pcVar10 = "INVALID_EE";
      }
      ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                     "[E][%s] Current EE: %s Required EE Mask: 0x%x\n","mhi_prepare_channel",pcVar10
                     ,*(undefined4 *)(param_2 + 0x100));
    }
    iVar8 = -0x6b;
  }
  else {
    lVar11 = param_2 + 0x120;
    mutex_lock(lVar11);
    if ((*(char *)(param_2 + 0x18a) != '\0') ||
       (iVar8 = mhi_init_chan_ctxt(param_1,param_2), iVar8 == 0)) {
      iVar8 = mhi_update_channel_state(param_1,param_2,2);
      if (iVar8 == 0) {
        if (*(int *)(param_2 + 0xd8) == 2) {
          bVar5 = param_3 & 1;
          *(byte *)(param_2 + 0x18b) = param_3 & 1;
        }
        else {
          bVar5 = *(byte *)(param_2 + 0x18b);
        }
        if (bVar5 != 0) {
          uVar1 = *(ulong *)(param_2 + 0x90);
          uVar3 = *(ulong *)(param_2 + 0x98);
          if (uVar3 < uVar1) {
            uVar13 = 0;
            if (*(ulong *)(param_2 + 0xa0) != 0) {
              uVar13 = (uVar1 - uVar3) / *(ulong *)(param_2 + 0xa0);
            }
            uVar13 = uVar13 - 1;
            iVar8 = (int)uVar13;
          }
          else {
            uVar2 = *(ulong *)(param_2 + 0xa0);
            uVar6 = 0;
            if (uVar2 != 0) {
              uVar6 = (uVar1 - *(long *)(param_2 + 0x88)) / uVar2;
            }
            uVar13 = 0;
            if (uVar2 != 0) {
              uVar13 = ((*(long *)(param_2 + 0x88) + *(long *)(param_2 + 0xa8)) - uVar3) / uVar2;
            }
            uVar13 = uVar6 + 0xffffffff + uVar13;
            iVar8 = (int)uVar13;
          }
          if (iVar8 != 0) {
            uVar12 = *(undefined8 *)(param_1 + 0x298);
            do {
              local_90[5] = 0;
              local_90[6] = 0;
              local_90[3] = 0;
              local_90[4] = 0;
              local_90[1] = 0;
              local_90[2] = 0;
              lVar9 = __kmalloc(uVar12,0xcc0);
              if (lVar9 == 0) {
                iVar8 = -0xc;
LAB_001080d4:
                mutex_unlock(lVar11);
                mhi_unprepare_channel(param_1,param_2);
                goto LAB_00108164;
              }
              local_90[0] = lVar9;
              local_90[3] = lVar9;
              local_90[5] = uVar12;
              iVar8 = mhi_gen_tre(param_1,param_2,local_90,2);
              if (iVar8 != 0) {
                kfree(lVar9);
                goto LAB_001080d4;
              }
              uVar4 = (int)uVar13 - 1;
              uVar13 = (ulong)uVar4;
            } while (uVar4 != 0);
          }
          _raw_read_lock_bh(param_1 + 0x178);
          if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0) {
            _raw_read_lock_irq(param_2 + 0x170);
            DataMemoryBarrier(0,2);
            **(long **)(param_2 + 0x78) =
                 (*(long *)(param_2 + 0x98) - *(long *)(param_2 + 0x88)) + *(long *)(param_2 + 0x70)
            ;
            if (*(int *)(*(code **)(param_2 + 0xf8) + -4) != 0x334b2fc0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10807c);
              (*pcVar7)();
            }
            (**(code **)(param_2 + 0xf8))(param_1,param_2 + 0xe0,*(undefined8 *)(param_2 + 0xc0));
            _raw_read_unlock_irq(param_2 + 0x170);
          }
          _raw_read_unlock_bh(param_1 + 0x178);
        }
        mutex_unlock(lVar11);
        iVar8 = 0;
        goto LAB_00108164;
      }
      if (*(char *)(param_2 + 0x18a) == '\0') {
        mhi_deinit_chan_ctxt(param_1,param_2);
      }
    }
    mutex_unlock(lVar11);
  }
LAB_00108164:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_90[7]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// mhi_update_channel_state @ 001081a0 size=868
// signature: undefined mhi_update_channel_state(void)
// callers: [mhi_unprepare_channel, mhi_prepare_channel, mhi_update_transfer_state]
//------------------------------------------------------------

int mhi_update_channel_state(long param_1,long param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_2 + 0x110);
  lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((lVar4 == 0) || (*(int *)(lVar4 + 0x18) != 0)) {
    if (param_3 != 2) goto LAB_001081e4;
LAB_00108274:
    if ((*(uint *)(param_2 + 0x104) | 4) != 4) goto LAB_0010839c;
    uVar6 = 0x12;
LAB_00108288:
    iVar2 = mhi_device_get_sync(*(undefined8 *)(param_1 + 8));
    if (iVar2 == 0) {
      if (*(int *)(*(code **)(param_1 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1082b8);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x248))(param_1);
      *(undefined4 *)(param_2 + 0x150) = 0;
      iVar2 = mhi_send_cmd(param_1,param_2,uVar6);
      if (iVar2 == 0) {
        uVar6 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
        iVar2 = wait_for_completion_timeout(param_2 + 0x150,uVar6);
        if ((iVar2 == 0) || (*(int *)(param_2 + 0x108) != 1)) {
          puVar5 = (&mhi_ch_state_type_str)[param_3];
          lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar7 + 0x28,"[E][%s] %d: Failed to receive %s channel command completion\n",
                   "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),puVar5);
          if ((lVar4 == 0) || (2 < *(uint *)(lVar4 + 0x18))) {
            iVar2 = -5;
          }
          else {
            ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                           "[E][%s] %d: Failed to receive %s channel command completion\n",
                           "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),puVar5);
            iVar2 = -5;
          }
        }
        else {
          if (param_3 != 0) {
            _raw_write_lock_irq(param_2 + 0x170);
            uVar3 = 4;
            if (param_3 == 2) {
              uVar3 = 1;
            }
            *(undefined4 *)(param_2 + 0x104) = uVar3;
            _raw_write_unlock_irq(param_2 + 0x170);
          }
          lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          if ((lVar4 != 0) && (*(int *)(lVar4 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                           "[D][%s] %d: Channel state change to %s successful\n",
                           "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),
                           (&mhi_ch_state_type_str)[param_3]);
          }
          iVar2 = 0;
        }
      }
      else {
        puVar5 = (&mhi_ch_state_type_str)[param_3];
        lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        _dev_err(lVar7 + 0x28,"[E][%s] %d: Failed to send %s channel command\n",
                 "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),puVar5);
        if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                         "[E][%s] %d: Failed to send %s channel command\n",
                         "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),puVar5);
        }
      }
      if (*(int *)(*(code **)(param_1 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108384);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 600))(param_1);
      mhi_device_put(*(undefined8 *)(param_1 + 8));
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[D][%s] %d: Updating channel state to: %s\n",
                   "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),
                   (&mhi_ch_state_type_str)[param_3]);
    if (param_3 == 2) goto LAB_00108274;
LAB_001081e4:
    if (param_3 == 1) {
      if (*(int *)(param_2 + 0x104) == 1) {
        uVar6 = 0x11;
        goto LAB_00108288;
      }
    }
    else if (param_3 == 0) {
      lVar4 = param_2 + 0x170;
      _raw_write_lock_irq(lVar4);
      if ((*(uint *)(param_2 + 0x104) < 5) &&
         ((1 << (ulong)(*(uint *)(param_2 + 0x104) & 0x1f) & 0x1aU) != 0)) {
        *(undefined4 *)(param_2 + 0x104) = 0;
        _raw_write_unlock_irq(lVar4);
        uVar6 = 0x10;
        goto LAB_00108288;
      }
      _raw_write_unlock_irq(lVar4);
    }
    else {
      puVar5 = (&mhi_ch_state_type_str)[param_3];
      lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar7 + 0x28,"[E][%s] %d: Channel state update to %s not allowed\n",
               "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),puVar5);
      if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                       "[E][%s] %d: Channel state update to %s not allowed\n",
                       "mhi_update_channel_state",*(undefined4 *)(param_2 + 200),puVar5);
      }
    }
LAB_0010839c:
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_unprepare_channel @ 00108504 size=384
// signature: undefined mhi_unprepare_channel(void)
// callers: [mhi_prepare_for_transfer, mhi_prepare_channel, mhi_prepare_for_transfer_autoqueue, mhi_unprepare_from_transfer]
//------------------------------------------------------------

void mhi_unprepare_channel(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_2 + 0x110);
  mutex_lock(param_2 + 0x120);
  uVar1 = *(uint *)(param_1 + 0x18c);
  if ((*(uint *)(param_2 + 0x100) >> ((ulong)uVar1 & 0x3f) & 1) == 0) {
    lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar4 != 0) && (*(int *)(lVar4 + 0x18) == 0)) {
      if (uVar1 < 10) {
        pcVar3 = (&mhi_ee_str)[uVar1];
      }
      else {
        pcVar3 = "INVALID_EE";
      }
      ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[D][%s] Current EE: %s Required EE Mask: 0x%x\n"
                     ,"mhi_unprepare_channel",pcVar3);
    }
  }
  else {
    iVar2 = mhi_update_channel_state(param_1,param_2,0);
    if (iVar2 != 0) {
      lVar5 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar4 + 0x28,"[E][%s] %d: Failed to reset channel, still resetting\n",
               "mhi_unprepare_channel",*(undefined4 *)(param_2 + 200));
      if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x20),
                       "[E][%s] %d: Failed to reset channel, still resetting\n",
                       "mhi_unprepare_channel",*(undefined4 *)(param_2 + 200));
      }
    }
  }
  _raw_write_lock_irq(param_2 + 0x170);
  *(undefined4 *)(param_2 + 0x104) = 0;
  _raw_write_unlock_irq(param_2 + 0x170);
  if (*(char *)(param_2 + 0x18a) == '\0') {
    mhi_reset_chan(param_1,param_2);
    mhi_deinit_chan_ctxt(param_1,param_2);
  }
  lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((lVar4 != 0) && (*(int *)(lVar4 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[D][%s] %d: successfully reset\n",
                   "mhi_unprepare_channel",*(undefined4 *)(param_2 + 200));
  }
  mutex_unlock(param_2 + 0x120);
  return;
}



//------------------------------------------------------------
// mhi_reset_chan @ 00108688 size=804
// signature: undefined mhi_reset_chan(void)
// callers: [mhi_unprepare_channel, mhi_driver_remove]
//------------------------------------------------------------

void mhi_reset_chan(long param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  undefined8 uVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  long *plVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  if (*(char *)(param_2 + 0x18a) != '\0') goto LAB_00108978;
  iVar4 = *(int *)(param_2 + 200);
  _raw_read_lock_bh();
  lVar16 = *(long *)(param_1 + 8);
  lVar15 = *(long *)(param_1 + 0x130);
  uVar3 = *(uint *)(param_2 + 0xcc);
  lVar9 = *(long *)(lVar16 + 0xc0);
  lVar17 = **(long **)(param_1 + 0x140);
  if ((lVar9 != 0) && (*(int *)(lVar9 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar9 + 0x20),
                   "[D][%s] Marking all events for chan: %d as stale\n","mhi_mark_stale_events",
                   iVar4);
  }
  lVar14 = lVar15 + (ulong)uVar3 * 0x118;
  lVar9 = lVar14 + 0x100;
  uVar8 = _raw_spin_lock_irqsave(lVar9);
  uVar13 = *(ulong *)(lVar14 + 0x30);
  uVar11 = *(ulong *)(lVar17 + (ulong)uVar3 * 0x2c + 0x1c);
  if ((uVar11 < uVar13) || ((uVar11 & 0xf) != 0)) {
LAB_001087cc:
    lVar15 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar16 + 0x28,"[E][%s] Event ring rp points outside of the event ring\n",
             "mhi_mark_stale_events");
    if ((lVar15 != 0) && (*(uint *)(lVar15 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar15 + 0x20),
                     "[E][%s] Event ring rp points outside of the event ring\n",
                     "mhi_mark_stale_events");
    }
  }
  else {
    plVar10 = (long *)(lVar15 + (ulong)uVar3 * 0x118 + 0x68);
    lVar17 = *plVar10;
    if (lVar17 + uVar13 <= uVar11) goto LAB_001087cc;
    lVar15 = lVar15 + (ulong)uVar3 * 0x118;
    plVar12 = (long *)(lVar15 + 0x48);
    lVar14 = *plVar12;
    lVar16 = *(long *)(lVar15 + 0x50);
    lVar15 = lVar14 + (uVar11 - uVar13);
    if (lVar15 != lVar16) {
      do {
        if ((*(uint *)(lVar16 + 0xc) & 0xff0000) == 0x220000 &&
            (ulong)(*(uint *)(lVar16 + 0xc) >> 0x18) == (long)iVar4) {
          *(uint *)(lVar16 + 0xc) = iVar4 << 0x18 | 0x510000;
          lVar14 = *plVar12;
          lVar17 = *plVar10;
        }
        lVar1 = lVar16 + 0x10;
        lVar16 = lVar14;
        if (lVar1 != lVar14 + lVar17) {
          lVar16 = lVar1;
        }
      } while (lVar15 != lVar16);
    }
  }
  lVar15 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((lVar15 != 0) && (*(int *)(lVar15 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar15 + 0x20),
                   "[D][%s] Finished marking events as stale events\n","mhi_mark_stale_events");
  }
  _raw_spin_unlock_irqrestore(lVar9,uVar8);
  local_78 = 0;
  local_80 = 0;
  uStack_70 = 0xffffff9500000000;
  if (*(long *)(param_2 + 0x90) != *(long *)(param_2 + 0x98)) {
    do {
      lVar9 = *(long *)(param_2 + 0x30);
      if (*(int *)(param_2 + 0xd8) == 1) {
        piVar2 = (int *)(param_1 + 0x198);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar6) {
            *piVar2 = *piVar2 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        cVar5 = *(char *)(lVar9 + 0x35);
      }
      else {
        cVar5 = *(char *)(lVar9 + 0x35);
      }
      if (cVar5 == '\0') {
        if (*(int *)(*(code **)(param_1 + 0x278) + -4) != -0x12d1612e) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1088f4);
          (*pcVar7)();
        }
        (**(code **)(param_1 + 0x278))(param_1,lVar9);
      }
      uVar11 = *(long *)(param_2 + 0x30) + *(long *)(param_2 + 0x40);
      if (*(ulong *)(param_2 + 0x28) + *(long *)(param_2 + 0x48) <= uVar11) {
        uVar11 = *(ulong *)(param_2 + 0x28);
      }
      *(ulong *)(param_2 + 0x30) = uVar11;
      DataMemoryBarrier(2,2);
      uVar11 = *(long *)(param_2 + 0x90) + *(long *)(param_2 + 0xa0);
      if (*(ulong *)(param_2 + 0x88) + *(long *)(param_2 + 0xa8) <= uVar11) {
        uVar11 = *(ulong *)(param_2 + 0x88);
      }
      *(ulong *)(param_2 + 0x90) = uVar11;
      DataMemoryBarrier(2,2);
      if (*(char *)(param_2 + 0x18b) == '\0') {
        local_80 = *(undefined8 *)(lVar9 + 0x18);
        if (*(int *)(*(code **)(param_2 + 0x118) + -4) != 0x26e788e6) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x10889c);
          (*pcVar7)();
        }
        (**(code **)(param_2 + 0x118))(*(undefined8 *)(param_2 + 0x110),&local_80);
      }
      else {
        kfree();
      }
    } while (*(long *)(param_2 + 0x90) != *(long *)(param_2 + 0x98));
  }
  _raw_read_unlock_bh(param_1 + 0x178);
LAB_00108978:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_prepare_for_transfer @ 001089b8 size=128
// signature: undefined mhi_prepare_for_transfer(void)
// callers: []
//------------------------------------------------------------

int mhi_prepare_for_transfer(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x18) != 0) {
    iVar2 = mhi_prepare_channel(uVar1,*(long *)(param_1 + 0x18),0);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (*(long *)(param_1 + 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = mhi_prepare_channel(uVar1,*(long *)(param_1 + 0x20),0);
    if ((iVar2 != 0) && (*(long *)(param_1 + 0x18) != 0)) {
      mhi_unprepare_channel(uVar1);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_prepare_for_transfer_autoqueue @ 00108a3c size=128
// signature: undefined mhi_prepare_for_transfer_autoqueue(void)
// callers: []
//------------------------------------------------------------

int mhi_prepare_for_transfer_autoqueue(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x18) != 0) {
    iVar2 = mhi_prepare_channel(uVar1,*(long *)(param_1 + 0x18),1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (*(long *)(param_1 + 0x20) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = mhi_prepare_channel(uVar1,*(long *)(param_1 + 0x20),1);
    if ((iVar2 != 0) && (*(long *)(param_1 + 0x18) != 0)) {
      mhi_unprepare_channel(uVar1);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_unprepare_from_transfer @ 00108ac0 size=380
// signature: undefined mhi_unprepare_from_transfer(void)
// callers: [mhi_driver_probe]
//------------------------------------------------------------

void mhi_unprepare_from_transfer(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  undefined8 *puVar4;
  
  lVar3 = *(long *)(param_1 + 0x10);
  pcVar2 = *(code **)(lVar3 + 0x250);
  lVar1 = *(long *)(*(long *)(lVar3 + 8) + 0xc0);
  if (pcVar2 == (code *)0x0) {
    if ((lVar1 != 0) && (*(int *)(lVar1 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x20),"[D][%s] Calling runtime_get()\n",
                     "mhi_unprepare_from_transfer");
    }
    puVar4 = (undefined8 *)(lVar3 + 0x248);
  }
  else {
    if ((lVar1 == 0) || (*(int *)(lVar1 + 0x18) != 0)) goto LAB_00108b44;
    puVar4 = (undefined8 *)(lVar3 + 0x250);
    ipc_log_string(*(undefined8 *)(lVar1 + 0x20),"[D][%s] Calling runtime_get_sync()\n",
                   "mhi_unprepare_from_transfer");
  }
  pcVar2 = (code *)*puVar4;
LAB_00108b44:
  if (*(int *)(pcVar2 + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x108b60);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3);
  if (*(long *)(param_1 + 0x20) != 0) {
    mhi_unprepare_channel(lVar3);
  }
  if (*(long *)(param_1 + 0x18) != 0) {
    mhi_unprepare_channel(lVar3);
  }
  pcVar2 = *(code **)(lVar3 + 0x260);
  lVar1 = *(long *)(*(long *)(lVar3 + 8) + 0xc0);
  if (pcVar2 == (code *)0x0) {
    if ((lVar1 != 0) && (*(int *)(lVar1 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x20),"[D][%s] Calling runtime_put()\n",
                     "mhi_unprepare_from_transfer");
    }
    if (*(int *)(*(code **)(lVar3 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108c24);
      (*pcVar2)();
    }
    (**(code **)(lVar3 + 600))(lVar3);
  }
  else {
    if ((lVar1 != 0) && (*(int *)(lVar1 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x20),"[D][%s] Calling runtime_put_autosuspend()\n",
                     "mhi_unprepare_from_transfer");
      pcVar2 = *(code **)(lVar3 + 0x260);
    }
    if (*(int *)(pcVar2 + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108bd8);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3);
  }
  return;
}



//------------------------------------------------------------
// mhi_stop_transfer @ 00108c40 size=32
// signature: undefined mhi_stop_transfer(void)
// callers: []
//------------------------------------------------------------

void mhi_stop_transfer(undefined8 param_1)

{
  mhi_update_transfer_state(param_1,1);
  return;
}



//------------------------------------------------------------
// mhi_update_transfer_state @ 00108c60 size=168
// signature: undefined mhi_update_transfer_state(void)
// callers: [mhi_start_transfer, mhi_stop_transfer]
//------------------------------------------------------------

int mhi_update_transfer_state(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20);
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  if (lVar4 != 0) {
    lVar2 = lVar4 + 0x120;
    mutex_lock(lVar2);
    iVar1 = mhi_update_channel_state(uVar3,lVar4,param_2);
    if (iVar1 != 0) goto LAB_00108cd8;
    mutex_unlock(lVar2);
  }
  lVar4 = *(long *)(param_1 + 0x18);
  if (lVar4 == 0) {
    return 0;
  }
  lVar2 = lVar4 + 0x120;
  mutex_lock(lVar2);
  iVar1 = mhi_update_channel_state(uVar3,lVar4,param_2);
LAB_00108cd8:
  mutex_unlock(lVar2);
  return iVar1;
}



//------------------------------------------------------------
// mhi_start_transfer @ 00108d0c size=32
// signature: undefined mhi_start_transfer(void)
// callers: []
//------------------------------------------------------------

void mhi_start_transfer(undefined8 param_1)

{
  mhi_update_transfer_state(param_1,2);
  return;
}



//------------------------------------------------------------
// mhi_poll @ 00108d30 size=140
// signature: undefined mhi_poll(void)
// callers: []
//------------------------------------------------------------

undefined4 mhi_poll(long param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x10);
  lVar4 = *(long *)(lVar3 + 0x130) + (ulong)*(uint *)(*(long *)(param_1 + 0x20) + 0xcc) * 0x118;
  _raw_spin_lock_bh(lVar4 + 0x100);
  if (*(int *)(*(code **)(lVar4 + 0x108) + -4) != -0x70dbf4ec) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108d94);
    (*pcVar1)();
  }
  uVar2 = (**(code **)(lVar4 + 0x108))(lVar3,lVar4,param_2);
  _raw_spin_unlock_bh(lVar4 + 0x100);
  return uVar2;
}



//------------------------------------------------------------
// mhi_tryset_pm_state @ 00108dc0 size=120
// signature: undefined mhi_tryset_pm_state(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_intvec_threaded_handler, mhi_pm_fast_suspend, mhi_fw_load_handler, mhi_pm_suspend, mhi_ctrl_ev_task, mhi_report_error, mhi_download_amss_image]
//------------------------------------------------------------

ulong mhi_tryset_pm_state(long param_1,uint param_2)

{
  ulong uVar1;
  uint uVar2;
  code *pcVar3;
  ulong uVar4;
  
  uVar2 = *(uint *)(param_1 + 0x184);
  uVar4 = (ulong)uVar2;
  uVar1 = 0x2000000000;
  if (uVar2 != 0) {
    uVar1 = 0x3f00000000 - (LZCOUNT(uVar4) << 0x20);
  }
  if ((uVar1 < 0xc00000001) &&
     (uVar2 == *(uint *)(dev_state_transitions + ((long)uVar1 >> 0x20) * 8))) {
    if (0x68 < ((long)uVar1 >> 0x1d | 4U)) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x108e38);
      (*pcVar3)();
    }
    if ((*(uint *)(dev_state_transitions + ((long)uVar1 >> 0x20) * 8 + 4) & param_2) != 0) {
      uVar4 = (ulong)param_2;
      *(uint *)(param_1 + 0x184) = param_2;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// mhi_set_mhi_state @ 00108e3c size=484
// signature: undefined mhi_set_mhi_state(void)
// callers: [mhi_download_rddm_image, mhi_pm_suspend]
//------------------------------------------------------------

void mhi_set_mhi_state(long param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 8);
  if (param_2 == 0) {
    iVar1 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,2,1);
  }
  else {
    iVar1 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,0xff00,param_2);
  }
  if (iVar1 != 0) {
    lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    pcVar2 = "RESET";
    switch(param_2) {
    case 0:
      break;
    case 1:
      pcVar2 = "READY";
      break;
    case 2:
      pcVar2 = "M0";
      break;
    case 3:
      pcVar2 = "M1";
      break;
    case 4:
      pcVar2 = "M2";
      break;
    case 5:
      pcVar2 = "M3";
      break;
    case 6:
      pcVar2 = "M3 FAST";
      break;
    case 7:
      pcVar2 = "BHI";
      break;
    default:
      if (param_2 == 0xff) {
        pcVar2 = "SYS ERROR";
      }
      else {
        pcVar2 = "Unknown state";
      }
    }
    _dev_err(lVar3 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",pcVar2);
    if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
      pcVar2 = "RESET";
      switch(param_2) {
      case 0:
        break;
      case 1:
        pcVar2 = "READY";
        break;
      case 2:
        pcVar2 = "M0";
        break;
      case 3:
        pcVar2 = "M1";
        break;
      case 4:
        pcVar2 = "M2";
        break;
      case 5:
        pcVar2 = "M3";
        break;
      case 6:
        pcVar2 = "M3 FAST";
        break;
      case 7:
        pcVar2 = "BHI";
        break;
      default:
        if (param_2 == 0xff) {
          pcVar2 = "SYS ERROR";
        }
        else {
          pcVar2 = "Unknown state";
        }
      }
      ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[E][%s] Failed to set MHI state to: %s\n",
                     "mhi_set_mhi_state",pcVar2);
    }
  }
  return;
}



//------------------------------------------------------------
// mhi_state_str @ 00109020 size=160
// signature: undefined mhi_state_str(void)
// callers: [__mhi_pm_resume, mhi_pm_suspend]
//------------------------------------------------------------

char * mhi_state_str(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "RESET";
  switch(param_1) {
  case 0:
    goto switchD_00109048_caseD_0;
  case 1:
    return "READY";
  case 2:
    return "M0";
  case 3:
    return "M1";
  case 4:
    return "M2";
  case 5:
    return "M3";
  case 6:
    return "M3 FAST";
  case 7:
    return "BHI";
  default:
    if (param_1 == 0xff) {
      return "SYS ERROR";
    }
    pcVar1 = "Unknown state";
switchD_00109048_caseD_0:
    return pcVar1;
  }
}



//------------------------------------------------------------
// mhi_ready_state_transition @ 001090c4 size=1168
// signature: undefined mhi_ready_state_transition(void)
// callers: [mhi_fw_load_handler, mhi_pm_st_worker]
//------------------------------------------------------------

int mhi_ready_state_transition(long param_1)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  uint uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  uint uVar12;
  
  lVar11 = *(long *)(param_1 + 8);
  if (*(int *)(param_1 + 0x184) == 0x1000) {
    lVar10 = *(long *)(lVar11 + 0xc0);
    _dev_err(lVar11 + 0x28,"[E][%s] Device link is not accessible\n","mhi_ready_state_transition");
    if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar10 + 0x20),"[E][%s] Device link is not accessible\n",
                     "mhi_ready_state_transition");
      return -5;
    }
LAB_00109440:
    iVar3 = -5;
  }
  else {
    iVar3 = mhi_poll_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,2,0,25000);
    if (iVar3 == 0) {
      iVar3 = mhi_poll_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x48,1,1,25000);
      lVar10 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if (iVar3 == 0) {
        if ((lVar10 != 0) && (*(int *)(lVar10 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar10 + 0x20),"[D][%s] Device in READY State\n",
                         "mhi_ready_state_transition");
        }
        lVar10 = param_1 + 0x178;
        _raw_write_lock_irq(lVar10);
        uVar7 = *(uint *)(param_1 + 0x184);
        uVar1 = 0x2000000000;
        if (uVar7 != 0) {
          uVar1 = 0x3f00000000 - (LZCOUNT((ulong)uVar7) << 0x20);
        }
        if ((uVar1 < 0xc00000001) &&
           (uVar7 == *(uint *)(dev_state_transitions + ((long)uVar1 >> 0x20) * 8))) {
          if (0x68 < (uVar1 >> 0x1d | 4)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x109554);
            (*pcVar2)();
          }
          if ((0x1dfcUL >> ((long)uVar1 >> 0x20 & 0x3fU) & 1) != 0) goto LAB_001094a4;
          *(undefined4 *)(param_1 + 0x184) = 2;
          *(undefined4 *)(param_1 + 400) = 1;
          _raw_write_unlock_irq(lVar10);
        }
        else {
LAB_001094a4:
          *(undefined4 *)(param_1 + 400) = 1;
          _raw_write_unlock_irq(lVar10);
          if (uVar7 != 2) {
            lVar10 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            uVar4 = to_mhi_pm_state_str(2);
            uVar5 = to_mhi_pm_state_str(uVar7);
            _dev_err(lVar11 + 0x28,"[E][%s] Error moving to state %s from %s\n",
                     "mhi_ready_state_transition",uVar4,uVar5);
            if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
              uVar8 = *(undefined8 *)(lVar10 + 0x20);
              uVar4 = to_mhi_pm_state_str(2);
              uVar5 = to_mhi_pm_state_str(uVar7);
              ipc_log_string(uVar8,"[E][%s] Error moving to state %s from %s\n",
                             "mhi_ready_state_transition",uVar4,uVar5);
              return -5;
            }
            goto LAB_00109440;
          }
        }
        _raw_read_lock_bh(lVar10);
        if ((*(ushort *)(param_1 + 0x184) & 0xfde) == 0) {
          lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar11 + 0x28,"[E][%s] Device registers not accessible\n",
                   "mhi_ready_state_transition");
          if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
            pcVar6 = "[E][%s] Device registers not accessible\n";
            goto LAB_00109428;
          }
        }
        else {
          iVar3 = mhi_init_mmio(param_1);
          if (iVar3 == 0) {
            uVar7 = *(uint *)(param_1 + 0xc4);
            if (uVar7 != 0) {
              uVar12 = 0;
              lVar11 = *(long *)(param_1 + 0x130);
              do {
                if ((*(char *)(lVar11 + 0x112) == '\0') &&
                   ((bool)*(char *)(lVar11 + 0x110) == (*(int *)(param_1 + 400) != 1))) {
                  *(long *)(lVar11 + 0x58) =
                       (*(long *)(lVar11 + 0x48) + *(long *)(lVar11 + 0x68)) -
                       *(long *)(lVar11 + 0x60);
                  **(long **)(lVar11 + 0x38) =
                       (*(long *)(lVar11 + 0x68) - *(long *)(lVar11 + 0x60)) +
                       *(long *)(lVar11 + 0x30);
                  DataMemoryBarrier(2,2);
                  _raw_spin_lock_irq(lVar11 + 0x100);
                  mhi_ring_er_db(lVar11);
                  _raw_spin_unlock_irq(lVar11 + 0x100);
                  uVar7 = *(uint *)(param_1 + 0xc4);
                }
                uVar12 = uVar12 + 1;
                lVar11 = lVar11 + 0x118;
              } while (uVar12 < uVar7);
            }
            lVar11 = *(long *)(param_1 + 8);
            iVar3 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,0xff00,2);
            if (iVar3 != 0) {
              lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
              _dev_err(lVar11 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
                       &DAT_001133d4);
              if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
                ipc_log_string(*(undefined8 *)(lVar9 + 0x20),
                               "[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
                               &DAT_001133d4);
              }
            }
            _raw_read_unlock_bh(lVar10);
            return 0;
          }
          lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar11 + 0x28,"[E][%s] Error configuring MMIO registers\n",
                   "mhi_ready_state_transition");
          if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
            pcVar6 = "[E][%s] Error configuring MMIO registers\n";
LAB_00109428:
            ipc_log_string(*(undefined8 *)(lVar9 + 0x20),pcVar6,"mhi_ready_state_transition");
          }
        }
        _raw_read_unlock_bh(lVar10);
        goto LAB_00109440;
      }
      _dev_err(lVar11 + 0x28,"[E][%s] Device failed to enter MHI Ready\n",
               "mhi_ready_state_transition");
      if (lVar10 == 0) {
        return iVar3;
      }
      if (2 < *(uint *)(lVar10 + 0x18)) {
        return iVar3;
      }
      uVar4 = *(undefined8 *)(lVar10 + 0x20);
      pcVar6 = "[E][%s] Device failed to enter MHI Ready\n";
    }
    else {
      lVar10 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar11 + 0x28,"[E][%s] Device failed to clear MHI Reset\n",
               "mhi_ready_state_transition");
      if (lVar10 == 0) {
        return iVar3;
      }
      if (2 < *(uint *)(lVar10 + 0x18)) {
        return iVar3;
      }
      uVar4 = *(undefined8 *)(lVar10 + 0x20);
      pcVar6 = "[E][%s] Device failed to clear MHI Reset\n";
    }
    ipc_log_string(uVar4,pcVar6,"mhi_ready_state_transition");
  }
  return iVar3;
}



//------------------------------------------------------------
// mhi_pm_m0_transition @ 00109558 size=752
// signature: undefined mhi_pm_m0_transition(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_pm_fast_resume]
//------------------------------------------------------------

undefined8 mhi_pm_m0_transition(long param_1)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  
  lVar3 = param_1 + 0x178;
  lVar4 = *(long *)(param_1 + 8);
  _raw_write_lock_irq(lVar3);
  uVar6 = *(uint *)(param_1 + 0x184);
  *(undefined4 *)(param_1 + 400) = 2;
  uVar1 = 0x2000000000;
  if (uVar6 != 0) {
    uVar1 = 0x3f00000000 - (LZCOUNT((ulong)uVar6) << 0x20);
  }
  if ((uVar1 < 0xc00000001) &&
     (uVar6 == *(uint *)(dev_state_transitions + ((long)uVar1 >> 0x20) * 8))) {
    if (0x68 < (uVar1 >> 0x1d | 4)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x109848);
      (*pcVar2)();
    }
    if ((0x1fb1UL >> ((long)uVar1 >> 0x20 & 0x3fU) & 1) == 0) {
      *(undefined4 *)(param_1 + 0x184) = 4;
      _raw_write_unlock_irq(lVar3);
      goto LAB_00109600;
    }
  }
  _raw_write_unlock_irq(lVar3);
  if (uVar6 != 4) {
    lVar3 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar4 + 0x28,"[E][%s] Unable to transition to M0 state\n","mhi_pm_m0_transition");
    if ((lVar3 != 0) && (*(uint *)(lVar3 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x20),"[E][%s] Unable to transition to M0 state\n",
                     "mhi_pm_m0_transition");
    }
    return 0xfffffffb;
  }
LAB_00109600:
  *(int *)(param_1 + 0x19c) = *(int *)(param_1 + 0x19c) + 1;
  _raw_read_lock_bh(lVar3);
  if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10963c);
    (*pcVar2)();
  }
  (**(code **)(param_1 + 0x230))(param_1,1);
  if ((*(uint *)(param_1 + 0x18c) < 8) &&
     ((1 << (ulong)(*(uint *)(param_1 + 0x18c) & 0x1f) & 0x94U) != 0)) {
    uVar6 = *(uint *)(param_1 + 0xc4);
    lVar4 = *(long *)(param_1 + 0x138);
    if (uVar6 != 0) {
      uVar7 = 0;
      lVar5 = *(long *)(param_1 + 0x130) + 0x100;
      do {
        if (*(char *)(lVar5 + 0x12) == '\0') {
          _raw_spin_lock_irq(lVar5);
          mhi_ring_er_db(lVar5 + -0x100);
          _raw_spin_unlock_irq(lVar5);
          uVar6 = *(uint *)(param_1 + 0xc4);
        }
        uVar7 = uVar7 + 1;
        lVar5 = lVar5 + 0x118;
      } while (uVar7 < uVar6);
    }
    _raw_spin_lock_irq(lVar4 + 0x60);
    if (*(long *)(lVar4 + 0x28) != *(long *)(lVar4 + 0x30)) {
      mhi_ring_cmd_db(param_1,lVar4);
    }
    _raw_spin_unlock_irq(lVar4 + 0x60);
    mhi_misc_dbs_pending(param_1);
  }
  if (*(int *)(param_1 + 0xc0) != 0) {
    uVar6 = 0;
    pcVar8 = (char *)(*(long *)(param_1 + 0xa0) + 0xe0);
    do {
      if (*pcVar8 != '\0') {
        _raw_write_lock_irq(pcVar8 + 0x90);
        pcVar8[1] = '\x01';
        _raw_write_unlock_irq(pcVar8 + 0x90);
      }
      _raw_read_lock_irq(pcVar8 + 0x90);
      if (((*(long *)(pcVar8 + -0x58) != 0) &&
          (*(long *)(pcVar8 + -0x48) != *(long *)(pcVar8 + -0x50))) &&
         (*(int *)(pcVar8 + 0x24) == 1)) {
        mhi_ring_chan_db(param_1,pcVar8 + -0xe0);
      }
      _raw_read_unlock_irq(pcVar8 + 0x90);
      uVar6 = uVar6 + 1;
      pcVar8 = pcVar8 + 400;
    } while (uVar6 < *(uint *)(param_1 + 0xc0));
  }
  if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1097a4);
    (*pcVar2)();
  }
  (**(code **)(param_1 + 0x238))(param_1,0);
  _raw_read_unlock_bh(lVar3);
  __wake_up(param_1 + 0x210,3,0,0);
  return 0;
}



//------------------------------------------------------------
// mhi_pm_m1_transition @ 0010984c size=564
// signature: undefined mhi_pm_m1_transition(void)
// callers: [mhi_process_ctrl_ev_ring]
//------------------------------------------------------------

void mhi_pm_m1_transition(long param_1)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  
  lVar1 = param_1 + 0x178;
  _raw_write_lock_irq(lVar1);
  uVar3 = *(uint *)(param_1 + 0x184);
  uVar2 = 0x2000000000;
  if (uVar3 != 0) {
    uVar2 = 0x3f00000000 - (LZCOUNT((ulong)uVar3) << 0x20);
  }
  if ((uVar2 < 0xc00000001) &&
     (uVar3 == *(uint *)(dev_state_transitions + ((long)uVar2 >> 0x20) * 8))) {
    if (0x68 < (uVar2 >> 0x1d | 4)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x109a80);
      (*pcVar4)();
    }
    if (((long)uVar2 >> 0x20 & 0x1fffffffffffffffU) == 2) {
      *(undefined4 *)(param_1 + 0x184) = 8;
      goto LAB_001098d8;
    }
  }
  if (uVar3 != 8) {
    _raw_write_unlock_irq(lVar1);
    return;
  }
LAB_001098d8:
  lVar6 = *(long *)(param_1 + 8);
  iVar5 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,0xff00,4);
  if (iVar5 != 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar6 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
             &DAT_00115300);
    if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] Failed to set MHI state to: %s\n",
                     "mhi_set_mhi_state",&DAT_00115300);
    }
  }
  *(undefined4 *)(param_1 + 400) = 4;
  _raw_write_unlock_irq(lVar1);
  *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + 1;
  __wake_up(param_1 + 0x210,3,0,0);
  if ((*(int *)(param_1 + 0x198) == 0) && (*(int *)(param_1 + 0x194) == 0)) {
    if (*(int *)(*(code **)(param_1 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10995c);
      (*pcVar4)();
    }
    (**(code **)(param_1 + 0x228))(param_1,0);
  }
  else {
    lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar6 != 0) && (*(int *)(lVar6 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                     "[D][%s] Exiting M2, pending_pkts: %d dev_wake: %d\n","mhi_pm_m1_transition",
                     *(undefined4 *)(param_1 + 0x198),*(undefined4 *)(param_1 + 0x194));
    }
    _raw_read_lock_bh(lVar1);
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x109a44);
      (*pcVar4)();
    }
    (**(code **)(param_1 + 0x230))(param_1,1);
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x109a6c);
      (*pcVar4)();
    }
    (**(code **)(param_1 + 0x238))(param_1,1);
    _raw_read_unlock_bh(lVar1);
  }
  return;
}



//------------------------------------------------------------
// mhi_pm_m3_transition @ 00109a84 size=316
// signature: undefined mhi_pm_m3_transition(void)
// callers: [mhi_process_ctrl_ev_ring]
//------------------------------------------------------------

undefined8 mhi_pm_m3_transition(long param_1)

{
  ulong uVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = param_1 + 0x178;
  lVar5 = *(long *)(param_1 + 8);
  _raw_write_lock_irq(lVar4);
  uVar2 = *(uint *)(param_1 + 0x184);
  *(undefined4 *)(param_1 + 400) = 5;
  uVar1 = 0x2000000000;
  if (uVar2 != 0) {
    uVar1 = 0x3f00000000 - (LZCOUNT((ulong)uVar2) << 0x20);
  }
  if ((uVar1 < 0xc00000001) &&
     (uVar2 == *(uint *)(dev_state_transitions + ((long)uVar1 >> 0x20) * 8))) {
    if (0x68 < (uVar1 >> 0x1d | 4)) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x109bc0);
      (*pcVar3)();
    }
    if (((long)uVar1 >> 0x20 & 0x1fffffffffffffffU) == 4) {
      *(undefined4 *)(param_1 + 0x184) = 0x20;
      _raw_write_unlock_irq(lVar4);
      goto LAB_00109b24;
    }
  }
  _raw_write_unlock_irq(lVar4);
  if (uVar2 != 0x20) {
    lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar5 + 0x28,"[E][%s] Unable to transition to M3 state\n","mhi_pm_m3_transition");
    if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[E][%s] Unable to transition to M3 state\n",
                     "mhi_pm_m3_transition");
    }
    return 0xfffffffb;
  }
LAB_00109b24:
  *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 1;
  __wake_up(param_1 + 0x210,3,0,0);
  return 0;
}



//------------------------------------------------------------
// mhi_queue_state_transition @ 00109bc4 size=184
// signature: undefined mhi_queue_state_transition(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_power_down, mhi_pm_st_worker, mhi_pm_sys_err_handler, mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_queue_state_transition(long param_1,undefined4 param_2)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  plVar1 = (long *)kmalloc_trace(___mutex_init,0xa20,0x18);
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    *(undefined4 *)(plVar1 + 2) = param_2;
    uVar2 = _raw_spin_lock_irqsave(param_1 + 0x1c0);
    puVar4 = *(undefined8 **)(param_1 + 0x1b8);
    uVar3 = __list_add_valid(plVar1,puVar4,param_1 + 0x1b0);
    if ((uVar3 & 1) != 0) {
      *(long **)(param_1 + 0x1b8) = plVar1;
      *plVar1 = param_1 + 0x1b0;
      plVar1[1] = (long)puVar4;
      *puVar4 = plVar1;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x1c0,uVar2);
    queue_work_on(0x20,*(undefined8 *)(param_1 + 0x208),param_1 + 0x1d8);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// mhi_pm_sys_err_handler @ 00109c80 size=88
// signature: undefined mhi_pm_sys_err_handler(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_intvec_threaded_handler, mhi_ctrl_ev_task]
//------------------------------------------------------------

void mhi_pm_sys_err_handler(long param_1)

{
  long lVar1;
  
  if (*(long *)(param_1 + 0x90) == 0) {
    mhi_queue_state_transition(param_1,5);
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar1 != 0) && (*(int *)(lVar1 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x20),
                     "[D][%s] Controller supports RDDM, skip SYS_ERROR\n","mhi_pm_sys_err_handler");
    }
  }
  return;
}



//------------------------------------------------------------
// mhi_pm_st_worker @ 00109cdc size=5012
// signature: undefined mhi_pm_st_worker(void)
// callers: []
//------------------------------------------------------------

void mhi_pm_st_worker(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  char *pcVar9;
  long ***ppplVar10;
  undefined8 *puVar11;
  long lVar12;
  long lVar13;
  long ****pppplVar14;
  undefined8 *puVar15;
  long lVar16;
  long ***ppplVar17;
  long ****pppplVar18;
  uint uVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  uint *puVar23;
  long lVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  long *plVar27;
  long ****local_a8;
  long ****local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  int local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_a8 = (long ****)&local_a8;
  local_a0 = (long ****)&local_a8;
  _raw_spin_lock_irq(param_1 + -0x18);
  ppplVar17 = (long ***)(param_1 + -0x28);
  ppplVar10 = (long ***)*ppplVar17;
  if (ppplVar10 != ppplVar17) {
    pppplVar14 = *(long *****)(param_1 + -0x20);
    ppplVar10[1] = (long **)local_a0;
    *local_a0 = ppplVar10;
    *pppplVar14 = (long ***)&local_a8;
    *(long *)(param_1 + -0x28) = param_1 + -0x28;
    *(long ****)(param_1 + -0x20) = ppplVar17;
    local_a0 = pppplVar14;
  }
  _raw_spin_unlock_irq(param_1 + -0x18);
  if ((long *****)local_a8 != &local_a8) {
    puVar11 = (undefined8 *)(param_1 + -0x1c0);
    lVar16 = param_1 + -0x1d8;
    plVar27 = (long *)(param_1 + -0x1d0);
    lVar20 = param_1 + -0x90;
    puVar23 = (uint *)(param_1 + -0x114);
    lVar22 = param_1 + -0x60;
    lVar1 = param_1 + 0x38;
    pppplVar14 = local_a8;
    do {
      pppplVar18 = (long ****)*pppplVar14;
      uVar6 = __list_del_entry_valid(pppplVar14);
      if ((uVar6 & 1) != 0) {
        ppplVar10 = *pppplVar14;
        ppplVar17 = pppplVar14[1];
        ppplVar10[1] = (long **)ppplVar17;
        *ppplVar17 = (long **)ppplVar10;
      }
      *pppplVar14 = (long ***)0xdead000000000100;
      pppplVar14[1] = (long ***)0xdead000000000122;
      lVar12 = *(long *)(*plVar27 + 0xc0);
      if ((lVar12 != 0) && (*(int *)(lVar12 + 0x18) == 0)) {
        pcVar9 = "INVALID_STATE";
        if (*(uint *)(pppplVar14 + 2) < 7) {
          pcVar9 = (&dev_state_tran_str)[*(uint *)(pppplVar14 + 2)];
        }
        ipc_log_string(*(undefined8 *)(lVar12 + 0x20),"[D][%s] Handling state transition: %s\n",
                       "mhi_pm_st_worker",pcVar9);
      }
      switch(*(undefined4 *)(pppplVar14 + 2)) {
      case 0:
        _raw_write_lock_irq(lVar22);
        if ((*(ushort *)(param_1 + -0x54) & 0xfde) != 0) {
          uVar3 = mhi_get_exec_env(lVar16);
          *(undefined4 *)(param_1 + -0x4c) = uVar3;
        }
        _raw_write_unlock_irq(lVar22);
        mhi_fw_load_handler(lVar16);
        break;
      case 1:
        mhi_ready_state_transition(lVar16);
        break;
      case 2:
        _raw_write_lock_irq(lVar22);
        *(undefined4 *)(param_1 + -0x4c) = 1;
        _raw_write_unlock_irq(lVar22);
        mhi_process_sleeping_events(lVar16);
        mhi_create_devices(lVar16);
        if (*(char *)(param_1 + 0xce) != '\0') {
          mhi_download_amss_image(lVar16);
        }
        break;
      case 3:
        lVar12 = *(long *)(*plVar27 + 0xc0);
        local_98 = CONCAT44(local_98._4_4_,*(undefined4 *)(param_1 + -0x4c));
        if ((lVar12 != 0) && (*(int *)(lVar12 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar12 + 0x20),
                         "[D][%s] Processing Mission Mode transition\n",
                         "mhi_pm_mission_mode_transition");
        }
        _raw_write_lock_irq(lVar22);
        if ((((*(ushort *)(param_1 + -0x54) & 0xfde) == 0) ||
            (uVar4 = mhi_get_exec_env(lVar16), 7 < uVar4)) ||
           ((1 << (ulong)(uVar4 & 0x1f) & 0x94U) == 0)) {
          *(undefined4 *)(param_1 + -0x54) = 0x1000;
          _raw_write_unlock_irq(lVar22);
          __wake_up(lVar1,3,0,0);
        }
        else {
          *(uint *)(param_1 + -0x4c) = uVar4;
          _raw_write_unlock_irq(lVar22);
          __wake_up(lVar1,3,0,0);
          mhi_reset_reg_write_q(lVar16);
          device_for_each_child(*plVar27 + 0x28,&local_98,mhi_destroy_device);
          if (*(int *)(*(code **)(param_1 + 0x50) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x109fe0);
            (*pcVar2)();
          }
          (**(code **)(param_1 + 0x50))(lVar16,5);
          iVar5 = __mhi_device_get_sync(lVar16);
          if (iVar5 == 0) {
            _raw_read_lock_bh(lVar22);
            if (*(uint *)(param_1 + -0x54) < 0x80) {
              uVar4 = *puVar23;
              if (uVar4 != 0) {
                uVar19 = 0;
                lVar12 = *(long *)(param_1 + -0xa8);
                do {
                  if ((*(char *)(lVar12 + 0x112) == '\0') &&
                     ((bool)*(char *)(lVar12 + 0x110) == (*(int *)(param_1 + -0x48) != 1))) {
                    *(long *)(lVar12 + 0x58) =
                         (*(long *)(lVar12 + 0x48) + *(long *)(lVar12 + 0x68)) -
                         *(long *)(lVar12 + 0x60);
                    **(long **)(lVar12 + 0x38) =
                         (*(long *)(lVar12 + 0x68) - *(long *)(lVar12 + 0x60)) +
                         *(long *)(lVar12 + 0x30);
                    DataMemoryBarrier(2,2);
                    _raw_spin_lock_irq(lVar12 + 0x100);
                    mhi_ring_er_db(lVar12);
                    _raw_spin_unlock_irq(lVar12 + 0x100);
                    uVar4 = *puVar23;
                  }
                  uVar19 = uVar19 + 1;
                  lVar12 = lVar12 + 0x118;
                } while (uVar19 < uVar4);
              }
              _raw_read_unlock_bh(lVar22);
              mhi_process_sleeping_events(lVar16);
              mhi_create_devices(lVar16);
              mhi_misc_mission_mode(lVar16);
              _raw_read_lock_bh(lVar22);
            }
            if (*(int *)(*(code **)(param_1 + 0x60) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10aafc);
              (*pcVar2)();
            }
            (**(code **)(param_1 + 0x60))(lVar16,0);
            _raw_read_unlock_bh(lVar22);
          }
        }
        break;
      case 4:
        _raw_write_lock_irq(lVar22);
        *(undefined4 *)(param_1 + -0x4c) = 7;
        _raw_write_unlock_irq(lVar22);
        mhi_create_devices(lVar16);
        break;
      case 5:
        lVar12 = *plVar27;
        lVar13 = *(long *)(lVar12 + 0xc0);
        if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
          uVar26 = *(undefined8 *)(lVar13 + 0x20);
          uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + -0x54));
          uVar25 = to_mhi_pm_state_str(0x200);
          ipc_log_string(uVar26,"[D][%s] Transitioning from PM state: %s to: %s\n",
                         "mhi_pm_sys_error_transition",uVar7,uVar25);
        }
        if (*(int *)(*(code **)(param_1 + 0x50) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10a13c);
          (*pcVar2)();
        }
        (**(code **)(param_1 + 0x50))(lVar16,6);
        mutex_lock(lVar20);
        _raw_write_lock_irq(lVar22);
        uVar4 = *(uint *)(param_1 + -0x54);
        uVar6 = 0x2000000000;
        if (uVar4 != 0) {
          uVar6 = 0x3f00000000 - (LZCOUNT((ulong)uVar4) << 0x20);
        }
        if ((uVar6 < 0xc00000001) &&
           (uVar4 == *(uint *)(dev_state_transitions + ((long)uVar6 >> 0x20) * 8))) {
          if (0x68 < (uVar6 >> 0x1d | 4)) goto LAB_0010b080;
          if (((long)uVar6 >> 0x20 & 0x1fffffffffffffffU) != 8) goto LAB_0010ae04;
          *(undefined4 *)(param_1 + -0x54) = 0x200;
          _raw_write_unlock_irq(lVar22);
LAB_0010a1c0:
          *(undefined8 *)(param_1 + -0x4c) = 8;
          __wake_up(lVar1,3,0,0);
          if ((uVar4 & 0xfde) != 0) {
            iVar5 = mhi_get_mhi_state(lVar16);
            uVar4 = mhi_get_exec_env(lVar16);
            if ((iVar5 == 0xff) || (1 < uVar4)) {
              local_6c = -1;
              lVar13 = __msecs_to_jiffies(*(undefined4 *)(param_1 + -0x58));
              lVar24 = *plVar27;
              lVar21 = *(long *)(lVar24 + 0xc0);
              if ((lVar21 != 0) && (*(int *)(lVar21 + 0x18) == 0)) {
                ipc_log_string(*(undefined8 *)(lVar21 + 0x20),
                               "[D][%s] Triggering MHI Reset in device\n",
                               "mhi_pm_sys_error_transition");
                lVar24 = *plVar27;
              }
              iVar5 = mhi_write_reg_field(lVar16,*puVar11,0x38,2,1);
              if (iVar5 != 0) {
                lVar21 = *(long *)(*plVar27 + 0xc0);
                _dev_err(lVar24 + 0x28,"[E][%s] Failed to set MHI state to: %s\n",
                         "mhi_set_mhi_state","RESET");
                if ((lVar21 != 0) && (*(uint *)(lVar21 + 0x18) < 3)) {
                  ipc_log_string(*(undefined8 *)(lVar21 + 0x20),
                                 "[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
                                 "RESET");
                }
              }
              iVar5 = mhi_read_reg_field(lVar16,*puVar11,0x38,2,&local_6c);
              lVar21 = lVar13;
              if ((iVar5 != 0 || local_6c == 0) && lVar13 == 0) {
                lVar21 = 1;
              }
              if ((iVar5 == 0 && local_6c != 0) && (lVar21 != 0)) {
                local_80 = 0;
                uStack_78 = 0;
                local_90 = 0;
                uStack_88 = 0;
                local_98 = 0;
                init_wait_entry(&local_98,0);
                lVar21 = lVar13;
                while( true ) {
                  prepare_to_wait_event(lVar1,&local_98,2);
                  iVar5 = mhi_read_reg_field(lVar16,*puVar11,0x38,2,&local_6c);
                  if ((iVar5 != 0 || local_6c == 0) && lVar21 == 0) {
                    lVar21 = 1;
                  }
                  if ((iVar5 != 0 || local_6c == 0) || (lVar21 == 0)) break;
                  lVar21 = schedule_timeout(lVar21);
                }
                finish_wait(lVar1,&local_98);
              }
              if (((int)lVar21 == 0) || (local_6c != 0)) {
                lVar13 = *(long *)(*plVar27 + 0xc0);
                _dev_err(lVar12 + 0x28,"[E][%s] Device failed to exit MHI Reset state\n",
                         "mhi_pm_sys_error_transition");
                if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
                  ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                                 "[E][%s] Device failed to exit MHI Reset state\n",
                                 "mhi_pm_sys_error_transition");
                }
                _raw_write_lock_irq(lVar22);
                uVar4 = *(uint *)(param_1 + -0x54);
                uVar6 = 0x2000000000;
                if (uVar4 != 0) {
                  uVar6 = 0x3f00000000 - (LZCOUNT((ulong)uVar4) << 0x20);
                }
                if ((uVar6 < 0xc00000001) &&
                   (uVar4 == *(uint *)(dev_state_transitions + ((long)uVar6 >> 0x20) * 8))) {
                  if (0x68 < (uVar6 >> 0x1d | 4)) goto LAB_0010b080;
                  if (((long)uVar6 >> 0x20 & 0x1fffffffffffffffU) == 9) {
                    *(undefined4 *)(param_1 + -0x54) = 0x400;
                    _raw_write_unlock_irq(lVar22);
                    goto LAB_0010a790;
                  }
                }
                _raw_write_unlock_irq(lVar22);
                if (uVar4 != 0x400) goto LAB_0010aa3c;
              }
LAB_0010a790:
              mhi_write_reg(lVar16,*(undefined8 *)(param_1 + -0x1b8),0x20,0);
            }
          }
          lVar13 = *(long *)(*plVar27 + 0xc0);
          if ((lVar13 == 0) || (*(int *)(lVar13 + 0x18) != 0)) {
            uVar4 = *puVar23;
          }
          else {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                           "[D][%s] Waiting for all pending event ring processing to complete\n",
                           "mhi_pm_sys_error_transition");
            uVar4 = *puVar23;
          }
          if (uVar4 != 0) {
            uVar4 = 0;
            lVar13 = *(long *)(param_1 + -0xa8) + 0xa8;
            do {
              if (*(char *)(lVar13 + 0x6a) == '\0') {
                if (*(int *)(lVar13 + -0x88) == 2) {
                  cancel_work_sync(lVar13 + 0x28);
                }
                else {
                  tasklet_kill(lVar13);
                }
              }
              uVar4 = uVar4 + 1;
              lVar13 = lVar13 + 0x118;
            } while (uVar4 < *puVar23);
          }
          mutex_unlock(lVar20);
          mhi_misc_disable(lVar16);
          lVar13 = *(long *)(*plVar27 + 0xc0);
          if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                           "[D][%s] Waiting for all pending threads to complete\n",
                           "mhi_pm_sys_error_transition");
          }
          __wake_up(lVar1,3,0,0);
          lVar13 = *plVar27;
          lVar21 = *(long *)(lVar13 + 0xc0);
          if ((lVar21 != 0) && (*(int *)(lVar21 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar21 + 0x20),
                           "[D][%s] Reset all active channels and remove MHI devices\n",
                           "mhi_pm_sys_error_transition");
            lVar13 = *plVar27;
          }
          device_for_each_child(lVar13 + 0x28,0,mhi_destroy_device);
          mutex_lock(lVar20);
          if (*(int *)(param_1 + -0x44) != 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b01c);
            (*pcVar2)();
          }
          if (*(int *)(param_1 + -0x40) != 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b028);
            (*pcVar2)();
          }
          lVar13 = *(long *)(*plVar27 + 0xc0);
          if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x20),"[D][%s] Resetting EV CTXT and CMD CTXT\n"
                           ,"mhi_pm_sys_error_transition");
          }
          lVar13 = *(long *)(param_1 + -0xa0);
          lVar21 = *(long *)(*(long *)(param_1 + -0x98) + 0x10);
          *(undefined8 *)(lVar13 + 0x28) = *(undefined8 *)(lVar13 + 0x20);
          *(undefined8 *)(lVar13 + 0x30) = *(undefined8 *)(lVar13 + 0x20);
          *(undefined8 *)(lVar21 + 0x1c) = *(undefined8 *)(lVar21 + 0xc);
          *(undefined8 *)(lVar21 + 0x24) = *(undefined8 *)(lVar21 + 0xc);
          uVar4 = *puVar23;
          if (uVar4 != 0) {
            uVar19 = 0;
            puVar15 = (undefined8 *)(**(long **)(param_1 + -0x98) + 0x1c);
            pcVar9 = (char *)(*(long *)(param_1 + -0xa8) + 0x112);
            do {
              if (*pcVar9 == '\0') {
                *(undefined8 *)(pcVar9 + -0xc2) = *(undefined8 *)(pcVar9 + -0xca);
                *(undefined8 *)(pcVar9 + -0xba) = *(undefined8 *)(pcVar9 + -0xca);
                *puVar15 = puVar15[-2];
                puVar15[1] = puVar15[-2];
                uVar4 = *puVar23;
              }
              uVar19 = uVar19 + 1;
              pcVar9 = pcVar9 + 0x118;
              puVar15 = (undefined8 *)((long)puVar15 + 0x2c);
            } while (uVar19 < uVar4);
          }
          iVar5 = mhi_get_exec_env(lVar16);
          if (((iVar5 == 0) || (iVar5 = mhi_get_exec_env(lVar16), iVar5 == 5)) ||
             (iVar5 = mhi_get_exec_env(lVar16), iVar5 == 6)) {
            _raw_write_lock_irq(lVar22);
            uVar4 = *(uint *)(param_1 + -0x54);
            uVar6 = 0x2000000000;
            if (uVar4 != 0) {
              uVar6 = 0x3f00000000 - (LZCOUNT((ulong)uVar4) << 0x20);
            }
            if ((uVar6 < 0xc00000001) &&
               (uVar4 == *(uint *)(dev_state_transitions + ((long)uVar6 >> 0x20) * 8))) {
              if (0x68 < (uVar6 >> 0x1d | 4)) {
LAB_0010b080:
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(1,0x10b084);
                (*pcVar2)();
              }
              if ((0x1dfcUL >> ((long)uVar6 >> 0x20 & 0x3fU) & 1) != 0) goto LAB_0010af58;
              *(undefined4 *)(param_1 + -0x54) = 2;
              _raw_write_unlock_irq(lVar22);
            }
            else {
LAB_0010af58:
              _raw_write_unlock_irq(lVar22);
              if (uVar4 != 2) {
                lVar13 = *(long *)(*plVar27 + 0xc0);
                uVar7 = to_mhi_pm_state_str(2);
                uVar25 = to_mhi_pm_state_str(uVar4);
                _dev_err(lVar12 + 0x28,"[E][%s] Error moving to state %s from %s\n",
                         "mhi_pm_sys_error_transition",uVar7,uVar25);
                if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
                  uVar26 = *(undefined8 *)(lVar13 + 0x20);
                  uVar7 = to_mhi_pm_state_str(2);
                  uVar25 = to_mhi_pm_state_str(uVar4);
                  pcVar9 = "[E][%s] Error moving to state %s from %s\n";
                  goto LAB_0010affc;
                }
                goto LAB_0010aa3c;
              }
            }
            uVar7 = 0;
          }
          else {
            uVar7 = 1;
          }
          mhi_queue_state_transition(lVar16,uVar7);
        }
        else {
LAB_0010ae04:
          _raw_write_unlock_irq(lVar22);
          if (uVar4 == 0x200) goto LAB_0010a1c0;
          lVar13 = *(long *)(*plVar27 + 0xc0);
          uVar7 = to_mhi_pm_state_str(uVar4);
          uVar25 = to_mhi_pm_state_str(0x200);
          _dev_err(lVar12 + 0x28,"[E][%s] Failed to transition from PM state: %s to: %s\n",
                   "mhi_pm_sys_error_transition",uVar7,uVar25);
          if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
            uVar26 = *(undefined8 *)(lVar13 + 0x20);
            uVar7 = to_mhi_pm_state_str(uVar4);
            uVar25 = to_mhi_pm_state_str(0x200);
            pcVar9 = "[E][%s] Failed to transition from PM state: %s to: %s\n";
LAB_0010affc:
            ipc_log_string(uVar26,pcVar9,"mhi_pm_sys_error_transition",uVar7,uVar25);
          }
        }
LAB_0010aa3c:
        lVar12 = *(long *)(*plVar27 + 0xc0);
        if ((lVar12 != 0) && (*(int *)(lVar12 + 0x18) == 0)) {
          uVar7 = *(undefined8 *)(lVar12 + 0x20);
          uVar25 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + -0x54));
          pcVar9 = "RESET";
          switch(*(int *)(param_1 + -0x48)) {
          case 0:
            break;
          case 1:
            pcVar9 = "READY";
            break;
          case 2:
            pcVar9 = "M0";
            break;
          case 3:
            pcVar9 = "M1";
            break;
          case 4:
            pcVar9 = "M2";
            break;
          case 5:
            pcVar9 = "M3";
            break;
          case 6:
            pcVar9 = "M3 FAST";
            break;
          case 7:
            pcVar9 = "BHI";
            break;
          default:
            if (*(int *)(param_1 + -0x48) == 0xff) {
              pcVar9 = "SYS ERROR";
            }
            else {
              pcVar9 = "Unknown state";
            }
          }
          pcVar8 = "mhi_pm_sys_error_transition";
LAB_00109dd4:
          ipc_log_string(uVar7,"[D][%s] Exiting with PM state: %s, MHI state: %s\n",pcVar8,uVar25,
                         pcVar9);
        }
        goto LAB_00109dd8;
      case 6:
        lVar12 = *plVar27;
        lVar13 = *(long *)(lVar12 + 0xc0);
        if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
          uVar25 = *(undefined8 *)(lVar13 + 0x20);
          uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + -0x54));
          ipc_log_string(uVar25,"[D][%s] Processing disable transition with PM state: %s\n",
                         "mhi_pm_disable_transition",uVar7);
        }
        mhi_reset_reg_write_q(lVar16);
        mutex_lock(lVar20);
        if ((*(int *)(param_1 + -0x54) != 0x1000) &&
           ((*(long *)(param_1 + -0x148) == 0 || (iVar5 = mhi_get_exec_env(lVar16), iVar5 != 3)))) {
          lVar21 = *plVar27;
          lVar13 = *(long *)(lVar21 + 0xc0);
          if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x20),"[D][%s] Triggering MHI Reset in device\n"
                           ,"mhi_pm_disable_transition");
            lVar21 = *plVar27;
          }
          iVar5 = mhi_write_reg_field(lVar16,*puVar11,0x38,2,1);
          if (iVar5 != 0) {
            lVar13 = *(long *)(*plVar27 + 0xc0);
            _dev_err(lVar21 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
                     "RESET");
            if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                             "[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state","RESET")
              ;
            }
          }
          iVar5 = mhi_poll_reg_field(lVar16,*puVar11,0x38,2,0,25000);
          if (iVar5 != 0) {
            lVar13 = *(long *)(*plVar27 + 0xc0);
            _dev_err(lVar12 + 0x28,"[E][%s] Device failed to clear MHI Reset\n",
                     "mhi_pm_disable_transition");
            if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                             "[E][%s] Device failed to clear MHI Reset\n",
                             "mhi_pm_disable_transition");
            }
          }
          mhi_write_reg(lVar16,*(undefined8 *)(param_1 + -0x1b8),0x20,0);
          iVar5 = mhi_get_exec_env(lVar16);
          if ((((iVar5 != 0) && (iVar5 = mhi_get_exec_env(lVar16), iVar5 != 5)) &&
              (iVar5 = mhi_get_exec_env(lVar16), iVar5 != 6)) &&
             (iVar5 = mhi_poll_reg_field(lVar16,*puVar11,0x48,1,1,25000), iVar5 != 0)) {
            lVar13 = *(long *)(*plVar27 + 0xc0);
            _dev_err(lVar12 + 0x28,"[E][%s] Device failed to enter READY state\n",
                     "mhi_pm_disable_transition");
            if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                             "[E][%s] Device failed to enter READY state\n",
                             "mhi_pm_disable_transition");
            }
          }
        }
        lVar13 = *(long *)(*plVar27 + 0xc0);
        if ((lVar13 == 0) || (*(int *)(lVar13 + 0x18) != 0)) {
          uVar4 = *puVar23;
        }
        else {
          ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                         "[D][%s] Waiting for all pending event ring processing to complete\n",
                         "mhi_pm_disable_transition");
          uVar4 = *puVar23;
        }
        if (uVar4 != 0) {
          uVar4 = 0;
          lVar13 = *(long *)(param_1 + -0xa8) + 0xa8;
          do {
            if (*(char *)(lVar13 + 0x6a) == '\0') {
              disable_irq(*(undefined4 *)
                           (*(long *)(param_1 + -0x120) + (ulong)*(uint *)(lVar13 + -0x90) * 4));
              if (*(int *)(lVar13 + -0x88) == 2) {
                cancel_work_sync(lVar13 + 0x28);
              }
              else {
                tasklet_kill(lVar13);
              }
            }
            uVar4 = uVar4 + 1;
            lVar13 = lVar13 + 0x118;
          } while (uVar4 < *puVar23);
        }
        mutex_unlock(lVar20);
        mhi_misc_disable(lVar16);
        lVar13 = *(long *)(*plVar27 + 0xc0);
        if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar13 + 0x20),
                         "[D][%s] Waiting for all pending threads to complete\n",
                         "mhi_pm_disable_transition");
        }
        __wake_up(lVar1,3,0,0);
        lVar13 = *plVar27;
        lVar21 = *(long *)(lVar13 + 0xc0);
        if ((lVar21 != 0) && (*(int *)(lVar21 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar21 + 0x20),
                         "[D][%s] Reset all active channels and remove MHI devices\n",
                         "mhi_pm_disable_transition");
          lVar13 = *plVar27;
        }
        device_for_each_child(lVar13 + 0x28,0,mhi_destroy_device);
        mutex_lock(lVar20);
        if (*(int *)(param_1 + -0x44) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b008);
          (*pcVar2)();
        }
        if (*(int *)(param_1 + -0x40) != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b014);
          (*pcVar2)();
        }
        lVar13 = *(long *)(*plVar27 + 0xc0);
        if ((lVar13 != 0) && (*(int *)(lVar13 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar13 + 0x20),"[D][%s] Resetting EV CTXT and CMD CTXT\n",
                         "mhi_pm_disable_transition");
        }
        lVar13 = *(long *)(param_1 + -0xa0);
        lVar21 = *(long *)(*(long *)(param_1 + -0x98) + 0x10);
        *(undefined8 *)(lVar13 + 0x28) = *(undefined8 *)(lVar13 + 0x20);
        *(undefined8 *)(lVar13 + 0x30) = *(undefined8 *)(lVar13 + 0x20);
        *(undefined8 *)(lVar21 + 0x1c) = *(undefined8 *)(lVar21 + 0xc);
        *(undefined8 *)(lVar21 + 0x24) = *(undefined8 *)(lVar21 + 0xc);
        uVar4 = *puVar23;
        if (uVar4 != 0) {
          uVar19 = 0;
          puVar15 = (undefined8 *)(**(long **)(param_1 + -0x98) + 0x1c);
          pcVar9 = (char *)(*(long *)(param_1 + -0xa8) + 0x112);
          do {
            if (*pcVar9 == '\0') {
              *(undefined8 *)(pcVar9 + -0xc2) = *(undefined8 *)(pcVar9 + -0xca);
              *(undefined8 *)(pcVar9 + -0xba) = *(undefined8 *)(pcVar9 + -0xca);
              *puVar15 = puVar15[-2];
              puVar15[1] = puVar15[-2];
              uVar4 = *puVar23;
            }
            uVar19 = uVar19 + 1;
            pcVar9 = pcVar9 + 0x118;
            puVar15 = (undefined8 *)((long)puVar15 + 0x2c);
          } while (uVar19 < uVar4);
        }
        _raw_write_lock_irq(lVar22);
        uVar4 = *(uint *)(param_1 + -0x54);
        uVar6 = 0x2000000000;
        if (uVar4 != 0) {
          uVar6 = 0x3f00000000 - (LZCOUNT((ulong)uVar4) << 0x20);
        }
        if ((uVar6 < 0xc00000001) &&
           (uVar4 == *(uint *)(dev_state_transitions + ((long)uVar6 >> 0x20) * 8))) {
          if (0x68 < (uVar6 >> 0x1d | 4)) goto LAB_0010b080;
          if ((0x7fdUL >> ((long)uVar6 >> 0x20 & 0x3fU) & 1) != 0) goto LAB_0010aeac;
          *(undefined4 *)(param_1 + -0x54) = 1;
          _raw_write_unlock_irq(lVar22);
        }
        else {
LAB_0010aeac:
          _raw_write_unlock_irq(lVar22);
          if (uVar4 != 1) {
            lVar13 = *(long *)(*plVar27 + 0xc0);
            uVar7 = to_mhi_pm_state_str(uVar4);
            uVar25 = to_mhi_pm_state_str(1);
            _dev_err(lVar12 + 0x28,"[E][%s] Error moving from PM state: %s to: %s\n",
                     "mhi_pm_disable_transition",uVar7,uVar25);
            if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
              uVar26 = *(undefined8 *)(lVar13 + 0x20);
              uVar7 = to_mhi_pm_state_str(uVar4);
              uVar25 = to_mhi_pm_state_str(1);
              ipc_log_string(uVar26,"[E][%s] Error moving from PM state: %s to: %s\n",
                             "mhi_pm_disable_transition",uVar7,uVar25);
            }
          }
        }
        lVar12 = *(long *)(*plVar27 + 0xc0);
        if ((lVar12 != 0) && (*(int *)(lVar12 + 0x18) == 0)) {
          uVar7 = *(undefined8 *)(lVar12 + 0x20);
          uVar25 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + -0x54));
          pcVar9 = "RESET";
          switch(*(int *)(param_1 + -0x48)) {
          case 0:
            break;
          case 1:
            pcVar9 = "READY";
            break;
          case 2:
            pcVar9 = "M0";
            break;
          case 3:
            pcVar9 = "M1";
            break;
          case 4:
            pcVar9 = "M2";
            break;
          case 5:
            pcVar9 = "M3";
            break;
          case 6:
            pcVar9 = "M3 FAST";
            break;
          case 7:
            pcVar9 = "BHI";
            break;
          default:
            if (*(int *)(param_1 + -0x48) == 0xff) {
              pcVar9 = "SYS ERROR";
            }
            else {
              pcVar9 = "Unknown state";
            }
          }
          pcVar8 = "mhi_pm_disable_transition";
          goto LAB_00109dd4;
        }
LAB_00109dd8:
        mutex_unlock(lVar20);
      }
      kfree(pppplVar14);
      pppplVar14 = pppplVar18;
    } while ((long *****)pppplVar18 != &local_a8);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_pm_suspend @ 0010b08c size=1384
// signature: undefined mhi_pm_suspend(void)
// callers: []
//------------------------------------------------------------

void mhi_pm_suspend(long param_1)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  long lVar9;
  long *plVar10;
  undefined8 uVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar14 = sp_el0;
  local_48 = *(long *)(lVar14 + 0x638);
  if (*(uint *)(param_1 + 0x184) == 1) {
    uVar5 = 0xffffffea;
    goto LAB_0010b294;
  }
  if (*(uint *)(param_1 + 0x184) < 0x80) {
    lVar14 = *(long *)(param_1 + 8);
    if ((*(int *)(param_1 + 0x194) != 0) || (*(int *)(param_1 + 0x198) != 0)) {
LAB_0010b290:
      uVar5 = 0xfffffff0;
      goto LAB_0010b294;
    }
    lVar9 = param_1 + 0x178;
    _raw_read_lock_bh(lVar9);
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10b120);
      (*pcVar3)();
    }
    (**(code **)(param_1 + 0x230))(param_1,0);
    _raw_read_unlock_bh(lVar9);
    mhi_force_reg_write(param_1);
    lVar6 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
    if ((*(uint *)(param_1 + 400) & 0xfffffffe) == 2) {
      if (lVar6 == 0) {
        lVar6 = 1;
      }
    }
    else {
      if (lVar6 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
        lVar6 = 1;
      }
      if ((*(uint *)(param_1 + 0x184) < 0x80) && (lVar6 != 0)) {
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_70 = 0;
        lVar6 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
        init_wait_entry(&local_70,0);
        lVar1 = param_1 + 0x210;
        prepare_to_wait_event(lVar1,&local_70,2);
        uVar2 = *(uint *)(param_1 + 400);
        while ((uVar2 & 0xfffffffe) != 2) {
          if (lVar6 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
            lVar6 = 1;
          }
          if ((0x7f < *(uint *)(param_1 + 0x184)) || (lVar6 == 0)) goto LAB_0010b214;
          lVar6 = schedule_timeout(lVar6);
          prepare_to_wait_event(lVar1,&local_70,2);
          uVar2 = *(uint *)(param_1 + 400);
        }
        if (lVar6 == 0) {
          lVar6 = 1;
        }
LAB_0010b214:
        finish_wait(lVar1,&local_70);
      }
    }
    _raw_read_lock_bh(lVar9);
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10b24c);
      (*pcVar3)();
    }
    (**(code **)(param_1 + 0x238))(param_1,0);
    _raw_read_unlock_bh(lVar9);
    if (((int)lVar6 == 0) || (0x7f < *(uint *)(param_1 + 0x184))) {
      lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar14 + 0x28,"[E][%s] Could not enter M0/M1 state","mhi_pm_suspend");
      if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[E][%s] Could not enter M0/M1 state",
                       "mhi_pm_suspend");
        uVar5 = 0xfffffffb;
        goto LAB_0010b294;
      }
    }
    else {
      mhi_force_reg_write(param_1);
      _raw_write_lock_irq(lVar9);
      if ((*(int *)(param_1 + 0x194) != 0) || (*(int *)(param_1 + 0x198) != 0)) {
        _raw_write_unlock_irq(lVar9);
        goto LAB_0010b290;
      }
      lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar6 != 0) && (*(int *)(lVar6 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar6 + 0x20),"[D][%s] Allowing M3 transition\n",
                       "mhi_pm_suspend");
      }
      iVar4 = mhi_tryset_pm_state(param_1,0x10);
      if (iVar4 == 0x10) {
        mhi_set_mhi_state(param_1,5);
        _raw_write_unlock_irq(lVar9);
        lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        if ((lVar9 != 0) && (*(int *)(lVar9 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[D][%s] Waiting for M3 completion\n",
                         "mhi_pm_suspend");
        }
        lVar9 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
        if (*(int *)(param_1 + 400) == 5) {
          if (lVar9 == 0) {
            lVar9 = 1;
          }
        }
        else {
          if (lVar9 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
            lVar9 = 1;
          }
          if ((*(uint *)(param_1 + 0x184) < 0x80) && (lVar9 != 0)) {
            local_58 = 0;
            uStack_50 = 0;
            local_68 = 0;
            uStack_60 = 0;
            local_70 = 0;
            lVar9 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
            init_wait_entry(&local_70,0);
            lVar6 = param_1 + 0x210;
            prepare_to_wait_event(lVar6,&local_70,2);
            iVar4 = *(int *)(param_1 + 400);
            while (iVar4 != 5) {
              if (lVar9 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
                lVar9 = 1;
              }
              if ((0x7f < *(uint *)(param_1 + 0x184)) || (lVar9 == 0)) goto LAB_0010b468;
              lVar9 = schedule_timeout(lVar9);
              prepare_to_wait_event(lVar6,&local_70,2);
              iVar4 = *(int *)(param_1 + 400);
            }
            if (lVar9 == 0) {
              lVar9 = 1;
            }
LAB_0010b468:
            finish_wait(lVar6,&local_70);
          }
        }
        if ((int)lVar9 == 0) {
          mhi_debug_reg_dump(param_1);
                    /* WARNING: Subroutine does not return */
          panic("Timedout waiting for M3 ACK");
        }
        uVar2 = *(uint *)(param_1 + 0x184);
        if (uVar2 < 0x80) {
          plVar10 = (long *)(param_1 + 0xa8);
          plVar13 = (long *)*plVar10;
          if ((long *)*plVar10 == plVar10) {
            uVar5 = 0;
          }
          else {
            do {
              plVar12 = (long *)*plVar13;
              mutex_lock(plVar13 + -0xb);
              if (plVar13[-0xd] != 0) {
                mhi_notify(plVar13[-0xd],2);
              }
              mutex_unlock(plVar13 + -0xb);
              uVar5 = 0;
              plVar13 = plVar12;
            } while (plVar12 != plVar10);
          }
          goto LAB_0010b294;
        }
        lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        uVar5 = mhi_state_str(*(undefined4 *)(param_1 + 400));
        uVar7 = to_mhi_pm_state_str(uVar2);
        _dev_err(lVar14 + 0x28,"[E][%s] Did not enter M3 state, MHI state: %s, PM state: %s\n",
                 "mhi_pm_suspend",uVar5,uVar7);
        if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
          uVar11 = *(undefined8 *)(lVar9 + 0x20);
          uVar5 = mhi_state_str(*(undefined4 *)(param_1 + 400));
          uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
          pcVar8 = "[E][%s] Did not enter M3 state, MHI state: %s, PM state: %s\n";
          goto LAB_0010b5c0;
        }
      }
      else {
        _raw_write_unlock_irq(lVar9);
        lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        uVar5 = to_mhi_pm_state_str(0x10);
        uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
        _dev_err(lVar14 + 0x28,"[E][%s] Error setting to PM state: %s from: %s\n","mhi_pm_suspend",
                 uVar5,uVar7);
        if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
          uVar11 = *(undefined8 *)(lVar9 + 0x20);
          uVar5 = to_mhi_pm_state_str(0x10);
          uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
          pcVar8 = "[E][%s] Error setting to PM state: %s from: %s\n";
LAB_0010b5c0:
          ipc_log_string(uVar11,pcVar8,"mhi_pm_suspend",uVar5,uVar7);
          uVar5 = 0xfffffffb;
          goto LAB_0010b294;
        }
      }
    }
  }
  uVar5 = 0xfffffffb;
LAB_0010b294:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// mhi_pm_resume @ 0010b5f8 size=28
// signature: undefined mhi_pm_resume(void)
// callers: []
//------------------------------------------------------------

void mhi_pm_resume(void)

{
  __mhi_pm_resume();
  return;
}



//------------------------------------------------------------
// __mhi_pm_resume @ 0010b614 size=1196
// signature: undefined __mhi_pm_resume(void)
// callers: [mhi_pm_resume, mhi_pm_resume_force]
//------------------------------------------------------------

void __mhi_pm_resume(long param_1)

{
  uint uVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar13 = *(long *)(param_1 + 8);
  lVar8 = *(long *)(lVar13 + 0xc0);
  if ((lVar8 != 0) && (*(int *)(lVar8 + 0x18) == 0)) {
    uVar9 = *(undefined8 *)(lVar8 + 0x20);
    uVar5 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
    pcVar7 = "RESET";
    switch(*(int *)(param_1 + 400)) {
    case 0:
      break;
    case 1:
      pcVar7 = "READY";
      break;
    case 2:
      pcVar7 = "M0";
      break;
    case 3:
      pcVar7 = "M1";
      break;
    case 4:
      pcVar7 = "M2";
      break;
    case 5:
      pcVar7 = "M3";
      break;
    case 6:
      pcVar7 = "M3 FAST";
      break;
    case 7:
      pcVar7 = "BHI";
      break;
    default:
      if (*(int *)(param_1 + 400) == 0xff) {
        pcVar7 = "SYS ERROR";
      }
      else {
        pcVar7 = "Unknown state";
      }
    }
    ipc_log_string(uVar9,"[D][%s] Entered with PM state: %s, MHI state: %s\n","__mhi_pm_resume",
                   uVar5,pcVar7);
  }
  if (*(uint *)(param_1 + 0x184) == 1) {
LAB_0010b724:
    uVar5 = 0;
  }
  else {
    if (*(uint *)(param_1 + 0x184) < 0x80) {
      iVar4 = mhi_get_mhi_state(param_1);
      if (iVar4 != 5) {
        mhi_get_mhi_state(param_1);
        uVar5 = mhi_state_str();
        _dev_warn(lVar13 + 0x28,"Resuming from non M3 state (%s)\n",uVar5);
        uVar5 = 0xffffffea;
        goto LAB_0010b738;
      }
      uVar6 = mhi_in_rddm(param_1);
      if ((uVar6 & 1) != 0) goto LAB_0010b724;
      plVar2 = (long *)*(long *)(param_1 + 0xa8);
      while (plVar2 != (long *)(param_1 + 0xa8)) {
        plVar14 = (long *)*plVar2;
        mutex_lock(plVar2 + -0xb);
        if (plVar2[-0xd] != 0) {
          mhi_notify(plVar2[-0xd],3);
        }
        mutex_unlock(plVar2 + -0xb);
        plVar2 = plVar14;
      }
      lVar8 = param_1 + 0x178;
      _raw_write_lock_irq(lVar8);
      uVar1 = *(uint *)(param_1 + 0x184);
      uVar6 = 0x2000000000;
      if (uVar1 != 0) {
        uVar6 = 0x3f00000000 - (LZCOUNT((ulong)uVar1) << 0x20);
      }
      if ((uVar6 < 0xc00000001) &&
         (uVar1 == *(uint *)(dev_state_transitions + ((long)uVar6 >> 0x20) * 8))) {
        if (0x68 < (uVar6 >> 0x1d | 4)) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x10bac0);
          (*pcVar3)();
        }
        if (((long)uVar6 >> 0x20 & 0x1fffffffffffffffU) != 5) goto LAB_0010ba68;
        *(undefined4 *)(param_1 + 0x184) = 0x40;
LAB_0010b808:
        lVar11 = *(long *)(param_1 + 8);
        iVar4 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,0xff00,2);
        if (iVar4 != 0) {
          lVar12 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          _dev_err(lVar11 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
                   &DAT_001133d4);
          if ((lVar12 != 0) && (*(uint *)(lVar12 + 0x18) < 3)) {
            ipc_log_string(*(undefined8 *)(lVar12 + 0x20),"[E][%s] Failed to set MHI state to: %s\n"
                           ,"mhi_set_mhi_state",&DAT_001133d4);
          }
        }
        _raw_write_unlock_irq(lVar8);
        lVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
        if ((*(int *)(param_1 + 400) == 4) || (*(int *)(param_1 + 400) == 2)) {
          if (lVar8 == 0) {
            lVar8 = 1;
          }
        }
        else {
          if (lVar8 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
            lVar8 = 1;
          }
          if ((*(uint *)(param_1 + 0x184) < 0x80) && (lVar8 != 0)) {
            local_58 = 0;
            uStack_50 = 0;
            local_68 = 0;
            uStack_60 = 0;
            local_70 = 0;
            lVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
            init_wait_entry(&local_70,0);
            while( true ) {
              prepare_to_wait_event(param_1 + 0x210,&local_70,2);
              if ((*(int *)(param_1 + 400) == 4) || (*(int *)(param_1 + 400) == 2)) break;
              if (lVar8 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
                lVar8 = 1;
              }
              if ((0x7f < *(uint *)(param_1 + 0x184)) || (lVar8 == 0)) goto LAB_0010b95c;
              lVar8 = schedule_timeout(lVar8);
            }
            if (lVar8 == 0) {
              lVar8 = 1;
            }
LAB_0010b95c:
            finish_wait(param_1 + 0x210,&local_70);
          }
        }
        if ((((int)lVar8 != 0) && (*(uint *)(param_1 + 0x184) < 0x80)) ||
           (uVar6 = mhi_in_rddm(param_1), (uVar6 & 1) != 0)) goto LAB_0010b724;
        lVar8 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        uVar5 = mhi_state_str(*(undefined4 *)(param_1 + 400));
        uVar9 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
        _dev_err(lVar13 + 0x28,"[E][%s] Did not enter M0 state, MHI state: %s, PM state: %s\n",
                 "__mhi_pm_resume",uVar5,uVar9);
        if ((lVar8 == 0) || (2 < *(uint *)(lVar8 + 0x18))) goto LAB_0010b734;
        uVar10 = *(undefined8 *)(lVar8 + 0x20);
        uVar5 = mhi_state_str(*(undefined4 *)(param_1 + 400));
        uVar9 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
        pcVar7 = "[E][%s] Did not enter M0 state, MHI state: %s, PM state: %s\n";
      }
      else {
LAB_0010ba68:
        if (uVar1 == 0x40) goto LAB_0010b808;
        _raw_write_unlock_irq(lVar8);
        lVar8 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        if ((lVar8 == 0) || (1 < *(uint *)(lVar8 + 0x18))) goto LAB_0010b734;
        uVar10 = *(undefined8 *)(lVar8 + 0x20);
        uVar5 = to_mhi_pm_state_str(0x40);
        uVar9 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
        pcVar7 = "[I][%s] Error setting to PM state: %s from: %s\n";
      }
      ipc_log_string(uVar10,pcVar7,"__mhi_pm_resume",uVar5,uVar9);
    }
LAB_0010b734:
    uVar5 = 0xfffffffb;
  }
LAB_0010b738:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// mhi_pm_resume_force @ 0010bac4 size=28
// signature: undefined mhi_pm_resume_force(void)
// callers: []
//------------------------------------------------------------

void mhi_pm_resume_force(void)

{
  __mhi_pm_resume();
  return;
}



//------------------------------------------------------------
// __mhi_device_get_sync @ 0010bae4 size=600
// signature: undefined __mhi_device_get_sync(void)
// callers: [mhi_pm_st_worker, mhi_device_get_sync]
//------------------------------------------------------------

void __mhi_device_get_sync(long param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x178;
  local_48 = *(long *)(lVar6 + 0x638);
  _raw_read_lock_bh(lVar1);
  if (*(uint *)(param_1 + 0x184) < 0x80) {
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10bb4c);
      (*pcVar5)();
    }
    (**(code **)(param_1 + 0x230))(param_1,1);
    if ((*(byte *)(param_1 + 0x184) & 0x30) != 0) {
      pm_wakeup_dev_event(*(long *)(param_1 + 8) + 0x28,0,0);
      if (*(int *)(*(code **)(param_1 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10bb90);
        (*pcVar5)();
      }
      (**(code **)(param_1 + 0x248))(param_1);
      if (*(int *)(*(code **)(param_1 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10bbb4);
        (*pcVar5)();
      }
      (**(code **)(param_1 + 600))(param_1);
    }
    _raw_read_unlock_bh(lVar1);
    mhi_force_reg_write(param_1);
    lVar6 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
    uVar3 = *(uint *)(param_1 + 0x184);
    if ((uVar3 == 4 || uVar3 >= 0x80) && lVar6 == 0) {
      lVar6 = 1;
    }
    if ((uVar3 != 4 && uVar3 < 0x80) && (lVar6 != 0)) {
      local_58 = 0;
      uStack_50 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_70 = 0;
      lVar6 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
      init_wait_entry(&local_70,0);
      lVar2 = param_1 + 0x210;
      prepare_to_wait_event(lVar2,&local_70,2);
      uVar3 = *(uint *)(param_1 + 0x184);
      if ((uVar3 == 4 || uVar3 >= 0x80) && lVar6 == 0) {
        lVar6 = 1;
      }
      lVar4 = lVar6;
      if (uVar3 != 4 && uVar3 < 0x80) {
        do {
          lVar6 = 0;
          if (lVar4 == 0) break;
          lVar6 = schedule_timeout(lVar4);
          prepare_to_wait_event(lVar2,&local_70,2);
          uVar3 = *(uint *)(param_1 + 0x184);
          if ((uVar3 == 4 || 0x7f < uVar3) && lVar6 == 0) {
            lVar6 = 1;
          }
          lVar4 = lVar6;
        } while (uVar3 != 4 && 0x7f >= uVar3);
      }
      finish_wait(lVar2,&local_70);
    }
    if (((int)lVar6 != 0) && (*(uint *)(param_1 + 0x184) < 0x80)) {
      uVar7 = 0;
      goto LAB_0010bd00;
    }
    _raw_read_lock_bh(lVar1);
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10bcf0);
      (*pcVar5)();
    }
    (**(code **)(param_1 + 0x238))(param_1,0);
  }
  _raw_read_unlock_bh(lVar1);
  uVar7 = 0xfffffffb;
LAB_0010bd00:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// mhi_async_power_up @ 0010bd40 size=1124
// signature: undefined mhi_async_power_up(void)
// callers: [mhi_sync_power_up]
//------------------------------------------------------------

int mhi_async_power_up(long param_1)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 8);
  lVar10 = *(long *)(param_1 + 0x130);
  lVar7 = *(long *)(lVar11 + 0xc0);
  if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
    ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[I][%s] Requested to power ON\n",
                   "mhi_async_power_up");
  }
  if (((*(long *)(param_1 + 0x230) == 0) || (*(long *)(param_1 + 0x238) == 0)) ||
     (*(long *)(param_1 + 0x240) == 0)) {
    *(code **)(param_1 + 0x230) = mhi_assert_dev_wake;
    pcVar1 = mhi_toggle_dev_wake;
    if ((*(uint *)(param_1 + 0x188) & 8) != 0) {
      pcVar1 = mhi_toggle_dev_wake_nop;
    }
    *(code **)(param_1 + 0x240) = pcVar1;
    *(code **)(param_1 + 0x238) = mhi_deassert_dev_wake;
  }
  lVar7 = param_1 + 0x148;
  mutex_lock(lVar7);
  *(undefined4 *)(param_1 + 0x184) = 1;
  _raw_write_lock_irq(param_1 + 0x178);
  mhi_write_reg(param_1,*(undefined8 *)(param_1 + 0x20),0x20,0);
  *(undefined4 *)(param_1 + 0x184) = 2;
  *(undefined4 *)(param_1 + 0x18c) = 10;
  uVar3 = mhi_get_exec_env(param_1);
  _raw_write_unlock_irq(param_1 + 0x178);
  if ((uVar3 < 7) && ((1 << (ulong)(uVar3 & 0x1f) & 0x65U) != 0)) {
    iVar4 = mhi_get_mhi_state(param_1);
    lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
      pcVar5 = "RESET";
      switch(iVar4) {
      case 0:
        break;
      case 1:
        pcVar5 = "READY";
        break;
      case 2:
        pcVar5 = "M0";
        break;
      case 3:
        pcVar5 = "M1";
        break;
      case 4:
        pcVar5 = "M2";
        break;
      case 5:
        pcVar5 = "M3";
        break;
      case 6:
        pcVar5 = "M3 FAST";
        break;
      case 7:
        pcVar5 = "BHI";
        break;
      default:
        if (iVar4 == 0xff) {
          pcVar5 = "SYS ERROR";
        }
        else {
          pcVar5 = "Unknown state";
        }
      }
      ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                     "[D][%s] Attempting power on with EE: %s, state: %s\n","mhi_async_power_up",
                     (&mhi_ee_str)[uVar3],pcVar5);
    }
    if (iVar4 == 0xff) {
      lVar11 = *(long *)(param_1 + 8);
      iVar4 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,2,1);
      if (iVar4 != 0) {
        lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        _dev_err(lVar11 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
                 "RESET");
        if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[E][%s] Failed to set MHI state to: %s\n",
                         "mhi_set_mhi_state","RESET");
        }
      }
      iVar4 = mhi_poll_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,2,0,25000);
      if (iVar4 != 0) {
        lVar10 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 2)) {
          ipc_log_string(*(undefined8 *)(lVar10 + 0x20),
                         "[I][%s] Failed to reset MHI due to syserr state\n","mhi_async_power_up");
        }
        goto LAB_0010bef0;
      }
      mhi_write_reg(param_1,*(undefined8 *)(param_1 + 0x20),0x20,0);
    }
    enable_irq(**(undefined4 **)(param_1 + 0xb8));
    uVar6 = *(uint *)(param_1 + 0xc4);
    if (uVar6 != 0) {
      uVar8 = 0;
      pcVar5 = (char *)(lVar10 + 0x112);
      do {
        if (*pcVar5 == '\0') {
          enable_irq(*(undefined4 *)
                      (*(long *)(param_1 + 0xb8) + (ulong)*(uint *)(pcVar5 + -0xfa) * 4));
          uVar6 = *(uint *)(param_1 + 0xc4);
        }
        uVar8 = uVar8 + 1;
        pcVar5 = pcVar5 + 0x118;
      } while (uVar8 < uVar6);
    }
    bVar2 = false;
    if ((uVar3 != 0) && (uVar3 != 5)) {
      bVar2 = uVar3 != 6;
    }
    mhi_queue_state_transition(param_1,bVar2);
    mutex_unlock(lVar7);
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[I][%s] Power on setup success\n",
                     "mhi_async_power_up");
    }
    iVar4 = 0;
  }
  else {
    lVar10 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if (uVar3 < 10) {
      pcVar5 = (&mhi_ee_str)[uVar3];
    }
    else {
      pcVar5 = "INVALID_EE";
    }
    _dev_err(lVar11 + 0x28,"[E][%s] %s is not a valid EE for power on\n","mhi_async_power_up",pcVar5
            );
    if ((lVar10 == 0) || (2 < *(uint *)(lVar10 + 0x18))) {
      iVar4 = -5;
    }
    else {
      if (uVar3 < 10) {
        pcVar5 = (&mhi_ee_str)[uVar3];
      }
      else {
        pcVar5 = "INVALID_EE";
      }
      ipc_log_string(*(undefined8 *)(lVar10 + 0x20),"[E][%s] %s is not a valid EE for power on\n",
                     "mhi_async_power_up",pcVar5);
      iVar4 = -5;
    }
LAB_0010bef0:
    *(undefined4 *)(param_1 + 0x184) = 1;
    mutex_unlock(lVar7);
  }
  return iVar4;
}



//------------------------------------------------------------
// mhi_assert_dev_wake @ 0010c1a8 size=388
// signature: undefined mhi_assert_dev_wake(void)
// callers: []
//------------------------------------------------------------

void mhi_assert_dev_wake(long param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  
  if ((param_2 & 1) == 0) {
    piVar1 = (int *)(param_1 + 0x194);
    iVar3 = *(int *)(param_1 + 0x194);
    while (iVar3 != 0) {
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar3) goto LAB_0010c1ec;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = iVar3 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010c1ec:
      bVar5 = iVar3 == iVar2;
      iVar3 = iVar2;
      if (bVar5) {
        return;
      }
    }
    uVar6 = _raw_spin_lock_irqsave(param_1 + 0x1c4);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar3 = *piVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    if (((iVar3 + 1 == 1) && ((*(byte *)(param_1 + 0x184) >> 3 & 1) != 0)) &&
       (*(char *)(param_1 + 0x2a7) == '\0')) {
      if ((*(byte *)(param_1 + 0x188) >> 3 & 1) == 0) {
        mhi_write_offload_wakedb(param_1,1);
      }
      else {
        mhi_write_db(param_1,*(undefined8 *)(param_1 + 0x30),1);
      }
      *(undefined1 *)(param_1 + 0x2a7) = 1;
    }
  }
  else {
    uVar6 = _raw_spin_lock_irqsave(param_1 + 0x1c4);
    piVar1 = (int *)(param_1 + 0x194);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = *piVar1 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (((*(byte *)(param_1 + 0x184) & 0x4c) != 0) && (*(char *)(param_1 + 0x2a7) == '\0')) {
      if ((*(byte *)(param_1 + 0x188) >> 3 & 1) == 0) {
        mhi_write_offload_wakedb(param_1,1);
      }
      else {
        mhi_write_db(param_1,*(undefined8 *)(param_1 + 0x30),1);
      }
      *(undefined1 *)(param_1 + 0x2a7) = 1;
    }
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x1c4,uVar6);
  return;
}



//------------------------------------------------------------
// mhi_deassert_dev_wake @ 0010c360 size=264
// signature: undefined mhi_deassert_dev_wake(void)
// callers: []
//------------------------------------------------------------

void mhi_deassert_dev_wake(long param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  
  piVar1 = (int *)(param_1 + 0x194);
  iVar3 = *(int *)(param_1 + 0x194);
  do {
    if (iVar3 + -1 == 0) {
      uVar6 = _raw_spin_lock_irqsave(param_1 + 0x1c4);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar3 = *piVar1;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = iVar3 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
      if ((((iVar3 + -1 == 0) && ((*(byte *)(param_1 + 0x184) & 0x4c) != 0)) && ((param_2 & 1) == 0)
          ) && (*(char *)(param_1 + 0x2a7) != '\0')) {
        if ((*(byte *)(param_1 + 0x188) >> 3 & 1) == 0) {
          mhi_write_offload_wakedb(param_1,0);
        }
        else {
          mhi_write_db(param_1,*(undefined8 *)(param_1 + 0x30),0);
        }
        *(undefined1 *)(param_1 + 0x2a7) = 0;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x1c4,uVar6);
      return;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar3) goto LAB_0010c3a4;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar3 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010c3a4:
    bVar5 = iVar3 == iVar2;
    iVar3 = iVar2;
    if (bVar5) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// mhi_toggle_dev_wake_nop @ 0010c490 size=4
// signature: undefined mhi_toggle_dev_wake_nop(void)
// callers: []
//------------------------------------------------------------

void mhi_toggle_dev_wake_nop(void)

{
  return;
}



//------------------------------------------------------------
// mhi_toggle_dev_wake @ 0010c498 size=112
// signature: undefined mhi_toggle_dev_wake(void)
// callers: []
//------------------------------------------------------------

void mhi_toggle_dev_wake(long param_1)

{
  code *pcVar1;
  
  if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c4cc);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x230))(param_1,0);
  if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c4f4);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x238))(param_1,1);
  return;
}



//------------------------------------------------------------
// mhi_power_down @ 0010c50c size=508
// signature: undefined mhi_power_down(void)
// callers: [mhi_sync_power_up]
//------------------------------------------------------------

void mhi_power_down(long param_1,ulong param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  
  lVar1 = param_1 + 0x148;
  lVar10 = *(long *)(param_1 + 8);
  mutex_lock(lVar1);
  lVar2 = param_1 + 0x178;
  _raw_write_lock_irq(lVar2);
  uVar4 = *(uint *)(param_1 + 0x184);
  if (uVar4 == 1) {
    _raw_write_unlock_irq(lVar2);
    mutex_unlock(lVar1);
    return;
  }
  uVar8 = 0x800;
  if ((param_2 & 1) == 0) {
    uVar8 = 0x1000;
  }
  uVar3 = 0x2000000000;
  if (uVar4 != 0) {
    uVar3 = 0x3f00000000 - (LZCOUNT((ulong)uVar4) << 0x20);
  }
  if ((uVar3 < 0xc00000001) &&
     (uVar4 == *(uint *)(dev_state_transitions + ((long)uVar3 >> 0x20) * 8))) {
    if ((0x68 < (uVar3 >> 0x1d | 4)) || (0x68 < ((long)uVar3 >> 0x1d | 4U))) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(1,0x10c708);
      (*pcVar5)();
    }
    if ((*(uint *)(dev_state_transitions + ((long)uVar3 >> 0x20) * 8 + 4) & uVar8) == 0)
    goto LAB_0010c670;
  }
  else {
LAB_0010c670:
    if (uVar4 == uVar8) goto LAB_0010c5f0;
    lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    uVar6 = to_mhi_pm_state_str();
    uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
    _dev_err(lVar10 + 0x28,"[E][%s] Failed to move to state: %s from: %s\n","mhi_power_down",uVar6,
             uVar7);
    if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
      uVar9 = *(undefined8 *)(lVar11 + 0x20);
      uVar6 = to_mhi_pm_state_str(uVar8);
      uVar7 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
      ipc_log_string(uVar9,"[E][%s] Failed to move to state: %s from: %s\n","mhi_power_down",uVar6,
                     uVar7);
    }
    uVar8 = 0x1000;
  }
  *(uint *)(param_1 + 0x184) = uVar8;
LAB_0010c5f0:
  *(undefined8 *)(param_1 + 0x18c) = 8;
  __wake_up(param_1 + 0x210,3,0,0);
  _raw_write_unlock_irq(lVar2);
  mutex_unlock(lVar1);
  mhi_queue_state_transition(param_1,6);
  flush_work(param_1 + 0x1d8);
  disable_irq(**(undefined4 **)(param_1 + 0xb8));
  if (*(long *)(param_1 + 0x88) != 0) {
    mhi_free_bhie_table(param_1);
  }
  return;
}



//------------------------------------------------------------
// mhi_sync_power_up @ 0010c70c size=384
// signature: undefined mhi_sync_power_up(void)
// callers: []
//------------------------------------------------------------

void mhi_sync_power_up(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  uVar1 = mhi_async_power_up();
  if ((int)uVar1 == 0) {
    lVar2 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
    uVar3 = *(uint *)(param_1 + 0x18c);
    if ((7 < uVar3) || ((1 << (ulong)(uVar3 & 0x1f) & 0x94U) == 0)) {
      if ((*(uint *)(param_1 + 0x184) < 0x80) && (0x7f < *(uint *)(param_1 + 0x184) || lVar2 != 0))
      {
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_70 = 0;
        lVar2 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
        init_wait_entry(&local_70,0);
        while( true ) {
          prepare_to_wait_event(param_1 + 0x210,&local_70,2);
          if ((*(uint *)(param_1 + 0x18c) < 8) &&
             ((1 << (ulong)(*(uint *)(param_1 + 0x18c) & 0x1f) & 0x94U) != 0)) break;
          if (lVar2 == 0 && 0x7f < *(uint *)(param_1 + 0x184)) {
            lVar2 = 1;
          }
          if ((0x7f < *(uint *)(param_1 + 0x184)) || (lVar2 == 0)) break;
          lVar2 = schedule_timeout();
        }
        finish_wait(param_1 + 0x210,&local_70);
        uVar3 = *(uint *)(param_1 + 0x18c);
      }
    }
    if ((uVar3 < 8) && ((1 << (ulong)(uVar3 & 0x1f) & 0x94U) != 0)) {
      uVar1 = 0;
    }
    else {
      if (*(long *)(param_1 + 0x90) == 0) {
        mhi_power_down(param_1,0);
      }
      uVar1 = 0xffffff92;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// mhi_force_rddm_mode @ 0010c890 size=476
// signature: undefined mhi_force_rddm_mode(void)
// callers: []
//------------------------------------------------------------

void mhi_force_rddm_mode(long param_1)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  if (*(int *)(param_1 + 0x18c) == 3) {
    uVar3 = 0;
  }
  else {
    lVar5 = *(long *)(param_1 + 8);
    lVar4 = *(long *)(lVar5 + 0xc0);
    if ((lVar4 != 0) && (*(int *)(lVar4 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                     "[D][%s] Triggering SYS_ERR to force RDDM state\n","mhi_force_rddm_mode");
      lVar5 = *(long *)(param_1 + 8);
    }
    iVar1 = mhi_write_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x38,0xff00,0xff);
    if (iVar1 != 0) {
      lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar5 + 0x28,"[E][%s] Failed to set MHI state to: %s\n","mhi_set_mhi_state",
               "SYS ERROR");
      if ((lVar4 != 0) && (*(uint *)(lVar4 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"[E][%s] Failed to set MHI state to: %s\n",
                       "mhi_set_mhi_state","SYS ERROR");
      }
    }
    lVar4 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
    if (lVar4 == 0 && *(int *)(param_1 + 0x18c) == 3) {
      lVar4 = 1;
    }
    if ((*(int *)(param_1 + 0x18c) != 3) && (lVar4 != 0)) {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_60 = 0;
      lVar2 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
      init_wait_entry(&local_60,0);
      lVar5 = param_1 + 0x210;
      prepare_to_wait_event(lVar5,&local_60,2);
      iVar1 = *(int *)(param_1 + 0x18c);
      if (lVar2 == 0 && iVar1 == 3) {
        lVar2 = 1;
      }
      while ((lVar4 = lVar2, iVar1 != 3 && (lVar4 = 0, lVar2 != 0))) {
        lVar2 = schedule_timeout(lVar2);
        prepare_to_wait_event(lVar5,&local_60,2);
        iVar1 = *(int *)(param_1 + 0x18c);
        if (lVar2 == 0 && iVar1 == 3) {
          lVar2 = 1;
        }
      }
      finish_wait(lVar5,&local_60);
    }
    uVar3 = 0xfffffffb;
    if ((int)lVar4 != 0) {
      uVar3 = 0;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// mhi_device_get @ 0010ca70 size=212
// signature: undefined mhi_device_get(void)
// callers: []
//------------------------------------------------------------

void mhi_device_get(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x10);
  *(int *)(param_1 + 0x3cc) = *(int *)(param_1 + 0x3cc) + 1;
  _raw_read_lock_bh(lVar2 + 0x178);
  if ((*(byte *)(lVar2 + 0x184) & 0x30) != 0) {
    pm_wakeup_dev_event(*(long *)(lVar2 + 8) + 0x28,0,0);
    if (*(int *)(*(code **)(lVar2 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cadc);
      (*pcVar1)();
    }
    (**(code **)(lVar2 + 0x248))(lVar2);
    if (*(int *)(*(code **)(lVar2 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cb00);
      (*pcVar1)();
    }
    (**(code **)(lVar2 + 600))(lVar2);
  }
  if (*(int *)(*(code **)(lVar2 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cb28);
    (*pcVar1)();
  }
  (**(code **)(lVar2 + 0x230))(lVar2,1);
  _raw_read_unlock_bh(lVar2 + 0x178);
  return;
}



//------------------------------------------------------------
// mhi_device_get_sync @ 0010cb48 size=60
// signature: undefined mhi_device_get_sync(void)
// callers: [mhi_update_channel_state, mhi_get_remote_time_sync, mhi_process_misc_bw_ev_ring, mhi_driver_probe, mhi_get_remote_time]
//------------------------------------------------------------

void mhi_device_get_sync(long param_1)

{
  int iVar1;
  
  iVar1 = __mhi_device_get_sync(*(undefined8 *)(param_1 + 0x10));
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x3cc) = *(int *)(param_1 + 0x3cc) + 1;
  }
  return;
}



//------------------------------------------------------------
// mhi_device_put @ 0010cb88 size=212
// signature: undefined mhi_device_put(void)
// callers: [mhi_driver_remove, mhi_process_misc_tsync_ev_ring, mhi_update_channel_state, mhi_get_remote_time_sync, mhi_process_misc_bw_ev_ring, mhi_driver_probe, mhi_get_remote_time]
//------------------------------------------------------------

void mhi_device_put(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x10);
  *(int *)(param_1 + 0x3cc) = *(int *)(param_1 + 0x3cc) + -1;
  _raw_read_lock_bh(lVar2 + 0x178);
  if ((*(byte *)(lVar2 + 0x184) & 0x30) != 0) {
    pm_wakeup_dev_event(*(long *)(lVar2 + 8) + 0x28,0,0);
    if (*(int *)(*(code **)(lVar2 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cbf4);
      (*pcVar1)();
    }
    (**(code **)(lVar2 + 0x248))(lVar2);
    if (*(int *)(*(code **)(lVar2 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cc18);
      (*pcVar1)();
    }
    (**(code **)(lVar2 + 600))(lVar2);
  }
  if (*(int *)(*(code **)(lVar2 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cc40);
    (*pcVar1)();
  }
  (**(code **)(lVar2 + 0x238))(lVar2,0);
  _raw_read_unlock_bh(lVar2 + 0x178);
  return;
}



//------------------------------------------------------------
// mhi_in_rddm @ 0010cc5c size=244
// signature: undefined mhi_in_rddm(void)
// callers: [__mhi_pm_resume]
//------------------------------------------------------------

undefined8 mhi_in_rddm(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (*(long *)(param_1 + 0x90) != 0) {
    lVar4 = *(long *)(param_1 + 8);
    iVar2 = mhi_get_exec_env();
    if ((iVar2 == 3) && (*(int *)(param_1 + 400) - 2U < 5)) {
      *(undefined4 *)(param_1 + 0x18c) = 3;
      lVar3 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar4 + 0x28,"[E][%s] RDDM event occurred!\n","mhi_in_rddm");
      if ((lVar3 != 0) && (*(uint *)(lVar3 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x20),"[E][%s] RDDM event occurred!\n","mhi_in_rddm")
        ;
      }
      mhi_report_error(param_1);
      if (*(int *)(*(code **)(param_1 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10cd30);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x228))(param_1,4);
      __wake_up(param_1 + 0x210,3,0,0);
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// mhi_rddm_prepare @ 0010cd54 size=444
// signature: undefined mhi_rddm_prepare(void)
// callers: [mhi_prepare_for_power_up]
//------------------------------------------------------------

int mhi_rddm_prepare(long param_1,long *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = *param_2;
  uVar8 = *(undefined8 *)(param_1 + 0x28);
  lVar10 = *(long *)(param_1 + 8);
  if ((int)param_2[2] == 1) {
    lVar6 = *(long *)(lVar10 + 0xc0);
  }
  else {
    uVar5 = 0;
    puVar7 = (undefined8 *)param_2[1];
    do {
      uVar5 = uVar5 + 1;
      *puVar7 = *(undefined8 *)(lVar9 + 0x10);
      puVar1 = (undefined8 *)(lVar9 + 0x18);
      lVar9 = lVar9 + 0x20;
      puVar7[1] = *puVar1;
      puVar7 = puVar7 + 2;
    } while (uVar5 < (int)param_2[2] - 1U);
    lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  }
  if ((lVar6 != 0) && (*(int *)(lVar6 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar6 + 0x20),"[D][%s] BHIe programming for RDDM\n",
                   "mhi_rddm_prepare");
  }
  mhi_write_reg(param_1,uVar8,100,*(undefined4 *)(lVar9 + 0x14));
  mhi_write_reg(param_1,uVar8,0x60,*(undefined4 *)(lVar9 + 0x10));
  mhi_write_reg(param_1,uVar8,0x68,*(undefined4 *)(lVar9 + 0x18));
  do {
    uVar4 = get_random_u32();
    uVar4 = (uVar4 & 0xffffffff) * 0x40000000 - (uVar4 & 0xffffffff);
  } while ((uVar4 & 0xfffffffc) == 0);
  iVar2 = (int)(uVar4 >> 0x20) + 1;
  iVar3 = mhi_write_reg_field(param_1,uVar8,0x70,0x3fffffff,iVar2);
  lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if (iVar3 == 0) {
    if ((lVar6 != 0) && (*(int *)(lVar6 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                     "[D][%s] Address: %p and len: 0x%zx sequence: %u\n","mhi_rddm_prepare",
                     (undefined4 *)(lVar9 + 0x10),*(undefined8 *)(lVar9 + 0x18),iVar2);
    }
  }
  else {
    _dev_err(lVar10 + 0x28,"[E][%s] Failed to write sequence ID for BHIE_RXVECDB\n",
             "mhi_rddm_prepare");
    if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                     "[E][%s] Failed to write sequence ID for BHIE_RXVECDB\n","mhi_rddm_prepare");
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// mhi_rddm_download_status @ 0010cf14 size=448
// signature: undefined mhi_rddm_download_status(void)
// callers: [mhi_force_reset, mhi_download_rddm_image]
//------------------------------------------------------------

void mhi_rddm_download_status(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  int local_3c;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_3c = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x28);
  lVar8 = *(long *)(param_1 + 8);
  uVar2 = *(int *)(param_1 + 0x180) * 1000;
  if (0x270 < uVar2 >> 3) {
    uVar7 = (ulong)uVar2 / 5000;
    do {
      iVar1 = mhi_read_reg_field(param_1,uVar6,0x78,0xc0000000,&local_3c);
      if (iVar1 != 0) goto LAB_0010d0a0;
      if (local_3c == 2) {
        lVar8 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 2)) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[I][%s] RDDM dumps collected successfully",
                         "mhi_rddm_download_status");
        }
        uVar6 = 0;
        goto LAB_0010d0a4;
      }
      uVar2 = (int)uVar7 - 1;
      uVar7 = (ulong)uVar2;
      __const_udelay(0x147aeb8);
    } while (uVar2 != 0);
  }
  uVar2 = mhi_get_exec_env(param_1);
  uVar3 = mhi_read_reg(param_1,uVar6,0x78,&local_3c);
  lVar5 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if (uVar2 < 10) {
    pcVar4 = (&mhi_ee_str)[uVar2];
  }
  else {
    pcVar4 = "INVALID_EE";
  }
  _dev_err(lVar8 + 0x28,"[E][%s] ret: %d, RXVEC_STATUS: 0x%x, EE:%s\n","mhi_rddm_download_status",
           uVar3,local_3c,pcVar4);
  if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x18) < 3)) {
    if (uVar2 < 10) {
      pcVar4 = (&mhi_ee_str)[uVar2];
    }
    else {
      pcVar4 = "INVALID_EE";
    }
    ipc_log_string(*(undefined8 *)(lVar5 + 0x20),"[E][%s] ret: %d, RXVEC_STATUS: 0x%x, EE:%s\n",
                   "mhi_rddm_download_status",uVar3,local_3c,pcVar4);
  }
LAB_0010d0a0:
  uVar6 = 0xfffffffb;
LAB_0010d0a4:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// mhi_download_rddm_image @ 0010d0d8 size=1224
// signature: undefined mhi_download_rddm_image(void)
// callers: []
//------------------------------------------------------------

void mhi_download_rddm_image(long param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  bool bVar12;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  int local_3c;
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  uVar8 = *(undefined8 *)(param_1 + 0x28);
  local_3c = 0;
  lVar11 = *(long *)(param_1 + 8);
  if ((param_2 & 1) == 0) {
    lVar11 = *(long *)(lVar11 + 0xc0);
    if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                     "[D][%s] Waiting for RDDM image download via BHIe\n","mhi_download_rddm_image")
      ;
    }
    lVar11 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
    iVar3 = mhi_read_reg_field(param_1,uVar8,0x78,0xc0000000,&local_3c);
    if ((iVar3 == 0 && local_3c == 0) && ((iVar3 != 0 || local_3c != 0) || lVar11 != 0)) {
      local_50 = 0;
      uStack_48 = 0;
      local_60 = 0;
      uStack_58 = 0;
      local_68 = 0;
      lVar11 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
      init_wait_entry(&local_68,0);
      while( true ) {
        prepare_to_wait_event(param_1 + 0x210,&local_68,2);
        iVar3 = mhi_read_reg_field(param_1,uVar8,0x78,0xc0000000,&local_3c);
        if (lVar11 == 0 && (iVar3 != 0 || local_3c != 0)) {
          lVar11 = 1;
        }
        if ((iVar3 != 0 || local_3c != 0) || (lVar11 == 0)) break;
        lVar11 = schedule_timeout();
      }
      finish_wait(param_1 + 0x210,&local_68);
    }
    lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x20),"[D][%s] RXVEC_STATUS: 0x%x\n",
                     "mhi_download_rddm_image",local_3c);
    }
    uVar6 = 0;
    if (local_3c != 2) {
      uVar6 = 0xfffffffb;
    }
    goto LAB_0010d4d4;
  }
  lVar7 = *(long *)(lVar11 + 0xc0);
  if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
    uVar9 = *(undefined8 *)(lVar7 + 0x20);
    uVar8 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
    pcVar4 = "RESET";
    switch(*(int *)(param_1 + 400)) {
    case 0:
      break;
    case 1:
      pcVar4 = "READY";
      break;
    case 2:
      pcVar4 = "M0";
      break;
    case 3:
      pcVar4 = "M1";
      break;
    case 4:
      pcVar4 = "M2";
      break;
    case 5:
      pcVar4 = "M3";
      break;
    case 6:
      pcVar4 = "M3 FAST";
      break;
    case 7:
      pcVar4 = "BHI";
      break;
    default:
      if (*(int *)(param_1 + 400) == 0xff) {
        pcVar4 = "SYS ERROR";
      }
      else {
        pcVar4 = "Unknown state";
      }
    }
    if (*(uint *)(param_1 + 0x18c) < 10) {
      pcVar5 = (&mhi_ee_str)[*(uint *)(param_1 + 0x18c)];
    }
    else {
      pcVar5 = "INVALID_EE";
    }
    ipc_log_string(uVar9,"[D][%s] Entered with pm_state:%s dev_state:%s ee:%s\n",
                   "__mhi_download_rddm_in_panic",uVar8,pcVar4,pcVar5);
  }
  *(undefined4 *)(param_1 + 0x184) = 0x1000;
  DataMemoryBarrier(2,2);
  uVar1 = mhi_get_exec_env(param_1);
  uVar10 = (ulong)uVar1;
  if (uVar1 == 3) {
LAB_0010d448:
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
      if ((uint)uVar10 < 10) {
        pcVar4 = (&mhi_ee_str)[uVar10];
      }
      else {
        pcVar4 = "INVALID_EE";
      }
      ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                     "[D][%s] Waiting for RDDM image download via BHIe, current EE:%s\n",
                     "__mhi_download_rddm_in_panic",pcVar4);
    }
    iVar3 = mhi_rddm_download_status(param_1);
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if (iVar3 == 0) {
      if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[I][%s] RDDM dumps collected successfully",
                       "__mhi_download_rddm_in_panic");
      }
      uVar6 = 0;
      goto LAB_0010d4d4;
    }
    if (9 < (uint)uVar10) goto LAB_0010d524;
    bVar12 = false;
    pcVar4 = (&mhi_ee_str)[uVar10];
  }
  else {
    if (uVar1 != 10) {
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                       "[D][%s] Trigger device into RDDM mode using SYS ERR\n",
                       "__mhi_download_rddm_in_panic");
      }
      mhi_set_mhi_state(param_1,0xff);
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[D][%s] Waiting for device to enter RDDM\n",
                       "__mhi_download_rddm_in_panic");
      }
      iVar3 = 99;
      do {
        iVar2 = mhi_get_exec_env(param_1);
        if (iVar2 == 3) {
          if (0 < iVar3) goto LAB_0010d43c;
          break;
        }
        __const_udelay(0x8312b0);
        iVar3 = iVar3 + -1;
      } while (iVar3 != -1);
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                       "[D][%s] Did not enter RDDM, do a host req reset\n",
                       "__mhi_download_rddm_in_panic");
      }
      mhi_soc_reset(param_1);
      __const_udelay(0x8312b0);
LAB_0010d43c:
      uVar10 = mhi_get_exec_env(param_1);
      uVar10 = uVar10 & 0xffffffff;
      goto LAB_0010d448;
    }
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
LAB_0010d524:
    bVar12 = true;
    pcVar4 = "INVALID_EE";
  }
  _dev_err(lVar11 + 0x28,"[E][%s] RDDM transfer failed. Current EE: %s\n",
           "__mhi_download_rddm_in_panic",pcVar4);
  if ((lVar7 == 0) || (2 < *(uint *)(lVar7 + 0x18))) {
    uVar6 = 0xfffffffb;
  }
  else {
    if (bVar12) {
      pcVar4 = "INVALID_EE";
    }
    else {
      pcVar4 = (&mhi_ee_str)[uVar10];
    }
    ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] RDDM transfer failed. Current EE: %s\n",
                   "__mhi_download_rddm_in_panic",pcVar4);
    uVar6 = 0xfffffffb;
  }
LAB_0010d4d4:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// mhi_free_bhie_table @ 0010d5a4 size=144
// signature: undefined mhi_free_bhie_table(void)
// callers: [mhi_power_down, mhi_prepare_for_power_up, mhi_fw_load_handler, mhi_unregister_controller, mhi_unprepare_after_power_down]
//------------------------------------------------------------

void mhi_free_bhie_table(undefined8 *param_1,undefined8 *param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  
  if (*(char *)((long)param_1 + 0x2a4) == '\0') {
    lVar1 = *(long *)*param_2;
    if ((int)((long *)*param_2)[2] != 0) {
      uVar2 = 0;
      puVar3 = (undefined8 *)(lVar1 + 0x18);
      do {
        dma_free_attrs(*param_1,*puVar3,puVar3[-3],puVar3[-1],0x40);
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 4;
      } while (uVar2 < *(uint *)((long *)*param_2 + 2));
      lVar1 = *(long *)*param_2;
    }
    kfree(lVar1);
    kfree(*param_2);
    *param_2 = 0;
  }
  return;
}



//------------------------------------------------------------
// mhi_alloc_bhie_table @ 0010d638 size=536
// signature: undefined mhi_alloc_bhie_table(void)
// callers: [mhi_prepare_for_power_up, mhi_fw_load_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_alloc_bhie_table(undefined8 *param_1,undefined8 *param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  ulong uVar13;
  
  if (*(char *)((long)param_1 + 0x2a4) == '\0') {
    uVar13 = param_1[0xf];
    plVar5 = (long *)kmalloc_trace(___mutex_init,0xdc0,0x18);
    if (plVar5 != (long *)0x0) {
      uVar10 = 0;
      if (uVar13 != 0) {
        uVar10 = ((param_3 + uVar13) - 1) / uVar13;
      }
      uVar1 = (uint)uVar10 + 1;
      if ((int)uVar1 < 0) {
        *plVar5 = 0;
      }
      else {
        uVar9 = -(ulong)(uVar1 >> 0x1f) & 0xffffffe000000000 | (ulong)uVar1 << 5;
        lVar6 = __kmalloc(uVar9,0xdc0);
        *plVar5 = lVar6;
        if (lVar6 != 0) {
          if ((uint)uVar10 < 0x7fffffff) {
            uVar8 = 0;
            uVar11 = 0;
            iVar12 = 1;
            do {
              if (((long)(uVar11 + 0x18) < 0) || (uVar9 < uVar11 + 0x18)) goto LAB_0010d84c;
              uVar2 = uVar8;
              if ((uVar10 & 0xffffffff) * 0x20 != uVar11) {
                uVar2 = uVar13;
              }
              uVar4 = *param_1;
              *(ulong *)(lVar6 + uVar11 + 0x18) = uVar2;
              lVar7 = dma_alloc_attrs(uVar4,uVar2,lVar6 + uVar11 + 0x10,0xcc0,0x40);
              if (((long)uVar11 < 0) || (uVar9 <= uVar11)) goto LAB_0010d84c;
              *(long *)(lVar6 + uVar11) = lVar7;
              if (lVar7 == 0) {
                uVar13 = uVar11;
                if (iVar12 != 1) {
                  do {
                    uVar10 = uVar13 - 0x20;
                    if (((((((long)(uVar13 - 8) < 0) || (uVar9 < uVar13 - 8)) ||
                          (lVar7 = uVar9 - uVar11, lVar7 + 8U < 8)) ||
                         (((long)uVar10 < 0 || (uVar9 < uVar10)))) ||
                        ((uVar11 = uVar11 - 0x20, uVar9 - uVar11 < 8 ||
                         (((long)(uVar13 - 0x10) < 0 || (uVar9 < uVar13 - 0x10)))))) ||
                       (lVar7 + 0x10U < 8)) {
LAB_0010d84c:
                    /* WARNING: Does not return */
                      pcVar3 = (code *)SoftwareBreakpoint(1,0x10d850);
                      (*pcVar3)();
                    }
                    dma_free_attrs(*param_1,*(undefined8 *)(lVar6 + uVar10 + 0x18),
                                   *(undefined8 *)(lVar6 + uVar10),
                                   ((undefined8 *)(lVar6 + uVar10))[2],0x40);
                    iVar12 = iVar12 + -1;
                    uVar13 = uVar10;
                  } while (1 < iVar12);
                }
                goto LAB_0010d814;
              }
              uVar11 = uVar11 + 0x20;
              iVar12 = iVar12 + 1;
              uVar8 = uVar8 + 0x10;
            } while ((ulong)uVar1 * 0x20 != uVar11);
          }
          *param_2 = plVar5;
          *(uint *)(plVar5 + 2) = uVar1;
          plVar5[1] = *(long *)(lVar6 + (-(uVar10 >> 0x1f & 1) & 0xffffffe000000000 |
                                        (uVar10 & 0xffffffff) << 5));
          return 0;
        }
      }
LAB_0010d814:
      kfree(plVar5);
    }
    uVar4 = 0xfffffff4;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// mhi_fw_load_handler @ 0010d854 size=2584
// signature: undefined mhi_fw_load_handler(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

void mhi_fw_load_handler(undefined8 *param_1)

{
  ulong *puVar1;
  size_t sVar2;
  code *pcVar3;
  int iVar4;
  void *pvVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  ulong uVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  long lVar15;
  long lVar16;
  ulong local_a8;
  ulong *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  local_a8 = 0;
  local_a0 = (ulong *)0x0;
  lVar16 = param_1[1];
  if (*(uint *)((long)param_1 + 0x184) < 0x80) {
    iVar4 = mhi_read_reg(param_1,param_1[4],0x40,(long)param_1 + 0xe4);
    if (iVar4 != 0) {
      lVar10 = *(long *)(param_1[1] + 0xc0);
      _dev_err(lVar16 + 0x28,"[E][%s] Could not capture serial number via BHI\n",
               "mhi_fw_load_handler");
      if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar10 + 0x20),
                       "[E][%s] Could not capture serial number via BHI\n","mhi_fw_load_handler");
      }
    }
    lVar10 = 0xe8;
    do {
      iVar4 = mhi_read_reg(param_1,param_1[4],(int)lVar10 + -0x84,(long)param_1 + lVar10);
      if (iVar4 != 0) {
        lVar10 = *(long *)(param_1[1] + 0xc0);
        _dev_err(lVar16 + 0x28,"[E][%s] Could not capture OEM PK HASH via BHI\n",
                 "mhi_fw_load_handler");
        if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar10 + 0x20),
                         "[E][%s] Could not capture OEM PK HASH via BHI\n","mhi_fw_load_handler");
        }
        break;
      }
      lVar10 = lVar10 + 4;
    } while (lVar10 != 0x128);
    iVar4 = *(int *)((long)param_1 + 0x18c);
    if ((iVar4 == 6) || (iVar4 == 0)) {
      lVar10 = 0x60;
      if (iVar4 != 6) {
        lVar10 = 0x50;
      }
      lVar10 = *(long *)((long)param_1 + lVar10);
      if ((lVar10 == 0) ||
         ((*(char *)((long)param_1 + 0x2a6) != '\0' && ((param_1[0xe] == 0 || (param_1[0xf] == 0))))
         )) {
        lVar10 = *(long *)(param_1[1] + 0xc0);
        _dev_err(lVar16 + 0x28,"[E][%s] No firmware image defined or !sbl_size || !seg_len\n",
                 "mhi_fw_load_handler");
        if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar10 + 0x20),
                         "[E][%s] No firmware image defined or !sbl_size || !seg_len\n",
                         "mhi_fw_load_handler");
        }
      }
      else {
        iVar4 = request_firmware(&local_a0,lVar10,*(undefined8 *)(lVar16 + 0x88));
        if (iVar4 == 0) {
LAB_0010d96c:
          puVar1 = local_a0;
          if (*(char *)((long)param_1 + 0x2a6) != '\0') {
            puVar1 = param_1 + 0xe;
          }
          sVar2 = *puVar1;
          if (*local_a0 <= *puVar1) {
            sVar2 = *local_a0;
          }
          pvVar5 = (void *)dma_alloc_attrs(*param_1,sVar2,&local_a8,0xcc0,0);
          if (pvVar5 != (void *)0x0) {
            memcpy(pvVar5,(void *)local_a0[1],sVar2);
            uVar11 = local_a8;
            puVar12 = param_1 + 0x2f;
            uVar13 = param_1[4];
            lVar15 = param_1[1];
            local_70 = 0;
            _raw_read_lock_bh(puVar12);
            if ((*(ushort *)((long)param_1 + 0x184) & 0xfde) == 0) {
LAB_0010de08:
              _raw_read_unlock_bh(puVar12);
LAB_0010de10:
              iVar4 = -5;
            }
            else {
              do {
                uVar6 = get_random_u32();
                uVar6 = (uVar6 & 0xffffffff) * 0x40000000 - (uVar6 & 0xffffffff);
              } while ((uVar6 & 0xfffffffc) == 0);
              iVar4 = (int)(uVar6 >> 0x20) + 1;
              lVar8 = *(long *)(param_1[1] + 0xc0);
              if ((lVar8 != 0) && (*(int *)(lVar8 + 0x18) == 0)) {
                ipc_log_string(*(undefined8 *)(lVar8 + 0x20),
                               "[D][%s] Starting image download via BHI. Session ID: %u\n",
                               "mhi_fw_load_bhi",iVar4);
              }
              mhi_write_reg(param_1,uVar13,0x2c,0);
              mhi_write_reg(param_1,uVar13,0xc,uVar11 >> 0x20);
              mhi_write_reg(param_1,uVar13,8,uVar11 & 0xffffffff);
              mhi_write_reg(param_1,uVar13,0x10,sVar2 & 0xffffffff);
              mhi_write_reg(param_1,uVar13,0x18,iVar4);
              _raw_read_unlock_bh(puVar12);
              lVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x30));
              if ((*(uint *)((long)param_1 + 0x184) < 0x80) &&
                 (iVar4 = mhi_read_reg_field(param_1,uVar13,0x2c,0xc0000000,(long)&local_70 + 4),
                 iVar4 == 0)) {
                if (lVar8 == 0 && local_70._4_4_ != 0) {
                  lVar8 = 1;
                }
                if ((local_70._4_4_ == 0) && (lVar8 != 0)) {
                  local_80 = 0;
                  uStack_78 = 0;
                  local_90 = 0;
                  uStack_88 = 0;
                  local_98 = 0;
                  lVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x30));
                  init_wait_entry(&local_98,0);
                  while ((prepare_to_wait_event(param_1 + 0x42,&local_98,2),
                         *(uint *)((long)param_1 + 0x184) < 0x80 &&
                         (iVar4 = mhi_read_reg_field(param_1,uVar13,0x2c,0xc0000000,
                                                     (long)&local_70 + 4), iVar4 == 0))) {
                    if (lVar8 == 0 && local_70._4_4_ != 0) {
                      lVar8 = 1;
                    }
                    if ((local_70._4_4_ != 0) || (lVar8 == 0)) goto LAB_0010dd7c;
                    lVar8 = schedule_timeout(lVar8);
                  }
                  if (lVar8 == 0) {
                    lVar8 = 1;
                  }
LAB_0010dd7c:
                  finish_wait(param_1 + 0x42,&local_98);
                }
              }
              else if (lVar8 == 0) {
                lVar8 = 1;
              }
              if (0x7f < *(uint *)((long)param_1 + 0x184)) goto LAB_0010de10;
              if (local_70._4_4_ == 3) {
                lVar8 = *(long *)(param_1[1] + 0xc0);
                _dev_err(lVar15 + 0x28,"[E][%s] Image transfer failed\n","mhi_fw_load_bhi");
                if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 3)) {
                  ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[E][%s] Image transfer failed\n",
                                 "mhi_fw_load_bhi");
                }
                _raw_read_lock_bh(puVar12);
                if (((*(ushort *)((long)param_1 + 0x184) & 0xfde) != 0) &&
                   (iVar4 = mhi_read_reg(param_1,uVar13,0x30,&local_70), iVar4 == 0)) {
                  lVar8 = *(long *)(param_1[1] + 0xc0);
                  _dev_err(lVar15 + 0x28,"[E][%s] Reg: %s value: 0x%x\n","mhi_fw_load_bhi",
                           "ERROR_CODE",local_70 & 0xffffffff);
                  if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 3)) {
                    ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[E][%s] Reg: %s value: 0x%x\n",
                                   "mhi_fw_load_bhi","ERROR_CODE",local_70 & 0xffffffff);
                  }
                  iVar4 = mhi_read_reg(param_1,uVar13,0x34,&local_70);
                  if (iVar4 == 0) {
                    lVar8 = *(long *)(param_1[1] + 0xc0);
                    _dev_err(lVar15 + 0x28,"[E][%s] Reg: %s value: 0x%x\n","mhi_fw_load_bhi",
                             "ERROR_DBG1",local_70 & 0xffffffff);
                    if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 3)) {
                      ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[E][%s] Reg: %s value: 0x%x\n",
                                     "mhi_fw_load_bhi","ERROR_DBG1",local_70 & 0xffffffff);
                    }
                    iVar4 = mhi_read_reg(param_1,uVar13,0x38,&local_70);
                    if (iVar4 == 0) {
                      lVar8 = *(long *)(param_1[1] + 0xc0);
                      _dev_err(lVar15 + 0x28,"[E][%s] Reg: %s value: 0x%x\n","mhi_fw_load_bhi",
                               "ERROR_DBG2",local_70 & 0xffffffff);
                      if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 3)) {
                        ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[E][%s] Reg: %s value: 0x%x\n"
                                       ,"mhi_fw_load_bhi","ERROR_DBG2",local_70 & 0xffffffff);
                      }
                      iVar4 = mhi_read_reg(param_1,uVar13,0x3c,&local_70);
                      if (iVar4 == 0) {
                        lVar8 = *(long *)(param_1[1] + 0xc0);
                        _dev_err(lVar15 + 0x28,"[E][%s] Reg: %s value: 0x%x\n","mhi_fw_load_bhi",
                                 "ERROR_DBG3",local_70 & 0xffffffff);
                        if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 3)) {
                          ipc_log_string(*(undefined8 *)(lVar8 + 0x20),
                                         "[E][%s] Reg: %s value: 0x%x\n","mhi_fw_load_bhi",
                                         "ERROR_DBG3",local_70 & 0xffffffff);
                        }
                      }
                    }
                  }
                }
                goto LAB_0010de08;
              }
              iVar4 = -0x6e;
              if ((int)lVar8 != 0) {
                iVar4 = 0;
              }
            }
            dma_free_attrs(*param_1,sVar2,pvVar5,local_a8,0);
            if (iVar4 == 0) {
              if (lVar10 != param_1[0xc]) {
                _raw_write_lock_irq(puVar12);
                *(undefined4 *)(param_1 + 0x32) = 0;
                _raw_write_unlock_irq(puVar12);
                if (*(char *)((long)param_1 + 0x2a6) != '\0') {
                  uVar11 = *local_a0;
                  pvVar5 = (void *)local_a0[1];
                  lVar10 = *(long *)(param_1[1] + 0xc0);
                  if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 2)) {
                    pcVar7 = "False";
                    if (*(char *)(param_1 + 0x13) != '\0') {
                      pcVar7 = "True";
                    }
                    ipc_log_string(*(undefined8 *)(lVar10 + 0x20),"[I][%s] tme_supported_image:%s\n"
                                   ,"mhi_fw_load_handler",pcVar7);
                  }
                  if (*(char *)(param_1 + 0x13) != '\0') {
                    uVar6 = param_1[0xe];
                    uVar11 = uVar11 - uVar6;
                    pvVar5 = (void *)(local_a0[1] + uVar6);
                  }
                  iVar4 = mhi_alloc_bhie_table(param_1,param_1 + 0x11,uVar11);
                  if (iVar4 != 0) goto LAB_0010dee4;
                  if (uVar11 != 0) {
                    plVar9 = (long *)param_1[0x11];
                    puVar12 = (undefined8 *)plVar9[1];
                    puVar14 = (undefined8 *)(*plVar9 + 0x10);
                    do {
                      sVar2 = uVar11;
                      if ((ulong)puVar14[1] <= uVar11) {
                        sVar2 = puVar14[1];
                      }
                      memcpy((void *)puVar14[-2],pvVar5,sVar2);
                      pvVar5 = (void *)((long)pvVar5 + sVar2);
                      uVar11 = uVar11 - sVar2;
                      *puVar12 = *puVar14;
                      puVar12[1] = sVar2;
                      puVar12 = puVar12 + 2;
                      puVar14 = puVar14 + 4;
                    } while (uVar11 != 0);
                  }
                }
              }
              release_firmware(local_a0);
              goto LAB_0010df74;
            }
            lVar10 = *(long *)(param_1[1] + 0xc0);
            _dev_err(lVar16 + 0x28,"[E][%s] MHI did not load image over BHI, ret: %d\n",
                     "mhi_fw_load_handler",iVar4);
            if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar10 + 0x20),
                             "[E][%s] MHI did not load image over BHI, ret: %d\n",
                             "mhi_fw_load_handler",iVar4);
            }
          }
LAB_0010dee4:
          release_firmware(local_a0);
        }
        else if (param_1[0xb] == 0) {
          lVar10 = *(long *)(param_1[1] + 0xc0);
          _dev_err(lVar16 + 0x28,"[E][%s] Error loading firmware: %d\n","mhi_fw_load_handler",iVar4)
          ;
          if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
            uVar13 = *(undefined8 *)(lVar10 + 0x20);
            pcVar7 = "[E][%s] Error loading firmware: %d\n";
LAB_0010dd60:
            ipc_log_string(uVar13,pcVar7,"mhi_fw_load_handler",iVar4);
          }
        }
        else {
          iVar4 = request_firmware(&local_a0,param_1[0xb],*(undefined8 *)(lVar16 + 0x88));
          if (iVar4 == 0) {
            if (*(int *)((code *)param_1[0x45] + -4) != -0x51759158) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10d968);
              (*pcVar3)();
            }
            (*(code *)param_1[0x45])(param_1,9);
            goto LAB_0010d96c;
          }
          lVar10 = *(long *)(param_1[1] + 0xc0);
          _dev_err(lVar16 + 0x28,"[E][%s] Error loading fallback firmware: %d\n",
                   "mhi_fw_load_handler",iVar4);
          if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
            uVar13 = *(undefined8 *)(lVar10 + 0x20);
            pcVar7 = "[E][%s] Error loading fallback firmware: %d\n";
            goto LAB_0010dd60;
          }
        }
      }
    }
    else {
LAB_0010df74:
      iVar4 = mhi_ready_state_transition(param_1);
      lVar10 = *(long *)(param_1[1] + 0xc0);
      if (iVar4 == 0) {
        if ((lVar10 == 0) || (1 < *(uint *)(lVar10 + 0x18))) goto LAB_0010dfb0;
        uVar13 = *(undefined8 *)(lVar10 + 0x20);
        pcVar7 = "[I][%s] Wait for device to enter SBL or Mission mode\n";
        goto LAB_0010dfa4;
      }
      _dev_err(lVar16 + 0x28,"[E][%s] MHI did not enter READY state\n","mhi_fw_load_handler");
      if ((lVar10 != 0) && (*(uint *)(lVar10 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar10 + 0x20),"[E][%s] MHI did not enter READY state\n",
                       "mhi_fw_load_handler");
      }
      if (*(char *)((long)param_1 + 0x2a6) != '\0') {
        mhi_free_bhie_table(param_1,param_1 + 0x11);
      }
    }
    _raw_write_lock_irq(param_1 + 0x2f);
    iVar4 = mhi_tryset_pm_state(param_1,0x80);
    _raw_write_unlock_irq(param_1 + 0x2f);
    if (iVar4 == 0x80) {
      __wake_up(param_1 + 0x42,3,0,0);
    }
  }
  else {
    lVar10 = *(long *)(lVar16 + 0xc0);
    _dev_err(lVar16 + 0x28,"[E][%s] Device MHI is not in valid state\n","mhi_fw_load_handler");
    if ((lVar10 == 0) || (2 < *(uint *)(lVar10 + 0x18))) goto LAB_0010dfb0;
    uVar13 = *(undefined8 *)(lVar10 + 0x20);
    pcVar7 = "[E][%s] Device MHI is not in valid state\n";
LAB_0010dfa4:
    ipc_log_string(uVar13,pcVar7,"mhi_fw_load_handler");
  }
LAB_0010dfb0:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_download_amss_image @ 0010e270 size=796
// signature: undefined mhi_download_amss_image(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

int mhi_download_amss_image(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  int local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  plVar6 = *(long **)(param_1 + 0x88);
  if (plVar6 == (long *)0x0) {
    iVar3 = -5;
  }
  else {
    lVar1 = param_1 + 0x178;
    lVar10 = *(long *)(param_1 + 8);
    local_4c = 0;
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    lVar9 = *plVar6;
    lVar2 = plVar6[2];
    _raw_read_lock_bh(lVar1);
    if ((*(ushort *)(param_1 + 0x184) & 0xfde) == 0) {
      _raw_read_unlock_bh(lVar1);
      iVar3 = -5;
    }
    else {
      do {
        uVar5 = get_random_u32();
        uVar5 = (uVar5 & 0xffffffff) * 0x40000000 - (uVar5 & 0xffffffff);
      } while ((uVar5 & 0xfffffffc) == 0);
      *(int *)(param_1 + 0x128) = (int)(uVar5 >> 0x20) + 1;
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                       "[D][%s] Starting image download via BHIe. Sequence ID: %u\n",
                       "mhi_fw_load_bhie");
      }
      lVar9 = lVar9 + (ulong)((int)lVar2 - 1) * 0x20;
      mhi_write_reg(param_1,uVar8,0x30,*(undefined4 *)(lVar9 + 0x14));
      mhi_write_reg(param_1,uVar8,0x2c,*(undefined4 *)(lVar9 + 0x10));
      mhi_write_reg(param_1,uVar8,0x34,*(undefined4 *)(lVar9 + 0x18));
      iVar3 = mhi_write_reg_field(param_1,uVar8,0x3c,0x3fffffff,*(undefined4 *)(param_1 + 0x128));
      _raw_read_unlock_bh(lVar1);
      if (iVar3 == 0) {
        lVar9 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
        if ((*(uint *)(param_1 + 0x184) < 0x80) &&
           (iVar3 = mhi_read_reg_field(param_1,uVar8,0x44,0xc0000000,&local_4c), iVar3 == 0)) {
          if (lVar9 == 0 && local_4c != 0) {
            lVar9 = 1;
          }
          if ((local_4c == 0) && (lVar9 != 0)) {
            local_60 = 0;
            uStack_58 = 0;
            local_70 = 0;
            uStack_68 = 0;
            local_78 = 0;
            lVar9 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x180));
            init_wait_entry(&local_78,0);
            while ((prepare_to_wait_event(param_1 + 0x210,&local_78,2),
                   *(uint *)(param_1 + 0x184) < 0x80 &&
                   (iVar3 = mhi_read_reg_field(param_1,uVar8,0x44,0xc0000000,&local_4c), iVar3 == 0)
                   )) {
              if (lVar9 == 0 && local_4c != 0) {
                lVar9 = 1;
              }
              if ((local_4c != 0) || (lVar9 == 0)) goto LAB_0010e4d4;
              lVar9 = schedule_timeout(lVar9);
            }
            if (lVar9 == 0) {
              lVar9 = 1;
            }
LAB_0010e4d4:
            finish_wait(param_1 + 0x210,&local_78);
          }
        }
        else if (lVar9 == 0) {
          lVar9 = 1;
        }
        iVar3 = -5;
        if ((*(uint *)(param_1 + 0x184) < 0x80) && (local_4c == 2)) {
          if ((int)lVar9 != 0) {
            iVar3 = 0;
            goto LAB_0010e3f8;
          }
          iVar3 = -0x6e;
        }
      }
    }
    lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar10 + 0x28,"[E][%s] MHI did not load AMSS, ret:%d\n","mhi_download_amss_image",iVar3
            );
    if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[E][%s] MHI did not load AMSS, ret:%d\n",
                     "mhi_download_amss_image",iVar3);
    }
    _raw_write_lock_irq(lVar1);
    iVar4 = mhi_tryset_pm_state(param_1,0x80);
    _raw_write_unlock_irq(lVar1);
    if (iVar4 == 0x80) {
      __wake_up(param_1 + 0x210,3,0,0);
    }
  }
LAB_0010e3f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// mhi_misc_init @ 0010e590 size=72
// signature: undefined mhi_misc_init(void)
// callers: [init_module]
//------------------------------------------------------------

void mhi_misc_init(void)

{
  __mutex_init(&DAT_001163d0,"&mhi_bus.lock",&mhi_misc_init___key);
  mhi_bus = &mhi_bus;
  DAT_001163c8 = &mhi_bus;
  return;
}



//------------------------------------------------------------
// mhi_misc_exit @ 0010e5dc size=4
// signature: undefined mhi_misc_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void mhi_misc_exit(void)

{
  return;
}



//------------------------------------------------------------
// mhi_force_reg_write @ 0010e5e4 size=48
// signature: undefined mhi_force_reg_write(void)
// callers: [mhi_pm_suspend, __mhi_device_get_sync]
//------------------------------------------------------------

void mhi_force_reg_write(long param_1)

{
  if ((*(byte *)(param_1 + 0x188) >> 3 & 1) == 0) {
    flush_work(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x78);
  }
  return;
}



//------------------------------------------------------------
// mhi_reset_reg_write_q @ 0010e618 size=84
// signature: undefined mhi_reset_reg_write_q(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

void mhi_reset_reg_write_q(long param_1)

{
  long lVar1;
  
  if ((*(byte *)(param_1 + 0x188) >> 3 & 1) == 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    cancel_work_sync(lVar1 + 0x78);
    memset(*(void **)(lVar1 + 0xa8),0,0x2000);
    *(undefined4 *)(lVar1 + 0xb4) = 0;
    *(undefined4 *)(lVar1 + 0xb0) = 0xffffffff;
  }
  return;
}



//------------------------------------------------------------
// mhi_write_reg_offload @ 0010e670 size=168
// signature: undefined mhi_write_reg_offload(void)
// callers: []
//------------------------------------------------------------

void mhi_write_reg_offload(long param_1,long param_2,ulong param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  puVar1 = (uint *)(lVar7 + 0xb0);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  uVar5 = (ulong)(uVar2 + 1 & 0x1ff);
  if (*(char *)(*(long *)(lVar7 + 0xa8) + uVar5 * 0x10 + 0xc) != '\0') {
                    /* WARNING: Subroutine does not return */
    panic("queue full idx %d",uVar5);
  }
  lVar6 = uVar5 * 0x10;
  *(ulong *)(*(long *)(lVar7 + 0xa8) + lVar6) = param_2 + (param_3 & 0xffffffff);
  *(undefined4 *)(*(long *)(lVar7 + 0xa8) + lVar6 + 8) = param_4;
  DataMemoryBarrier(2,2);
  *(undefined1 *)(*(long *)(lVar7 + 0xa8) + lVar6 + 0xc) = 1;
  DataMemoryBarrier(2,2);
  queue_work_on(0x20,*(undefined8 *)(lVar7 + 0x70),lVar7 + 0x78);
  return;
}



//------------------------------------------------------------
// mhi_write_offload_wakedb @ 0010e72c size=316
// signature: undefined mhi_write_offload_wakedb(void)
// callers: [mhi_assert_dev_wake, mhi_deassert_dev_wake]
//------------------------------------------------------------

void mhi_write_offload_wakedb(long param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  
  lVar7 = *(long *)(param_1 + 0x30);
  lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  puVar1 = (uint *)(lVar6 + 0xb0);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  uVar5 = (ulong)(uVar2 + 1 & 0x1ff);
  if (*(char *)(*(long *)(lVar6 + 0xa8) + uVar5 * 0x10 + 0xc) == '\0') {
    lVar9 = uVar5 * 0x10;
    *(long *)(*(long *)(lVar6 + 0xa8) + lVar9) = lVar7 + 4;
    *(int *)(*(long *)(lVar6 + 0xa8) + lVar9 + 8) = param_2 >> 0x1f;
    DataMemoryBarrier(2,2);
    *(undefined1 *)(*(long *)(lVar6 + 0xa8) + lVar9 + 0xc) = 1;
    DataMemoryBarrier(2,2);
    queue_work_on(0x20,*(undefined8 *)(lVar6 + 0x70),lVar6 + 0x78);
    uVar8 = *(undefined8 *)(param_1 + 0x30);
    lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    puVar1 = (uint *)(lVar6 + 0xb0);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar2 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    uVar5 = (ulong)(uVar2 + 1 & 0x1ff);
    if (*(char *)(*(long *)(lVar6 + 0xa8) + uVar5 * 0x10 + 0xc) == '\0') {
      lVar7 = uVar5 * 0x10;
      *(undefined8 *)(*(long *)(lVar6 + 0xa8) + lVar7) = uVar8;
      *(int *)(*(long *)(lVar6 + 0xa8) + lVar7 + 8) = param_2;
      DataMemoryBarrier(2,2);
      *(undefined1 *)(*(long *)(lVar6 + 0xa8) + lVar7 + 0xc) = 1;
      DataMemoryBarrier(2,2);
      queue_work_on(0x20,*(undefined8 *)(lVar6 + 0x70),lVar6 + 0x78);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  panic("queue full idx %d");
}



//------------------------------------------------------------
// mhi_reg_write_work @ 0010e88c size=200
// signature: undefined mhi_reg_write_work(void)
// callers: []
//------------------------------------------------------------

void mhi_reg_write_work(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  char *pcVar7;
  
  puVar1 = (undefined8 *)(*(long *)(param_1 + 0x30) + (ulong)*(uint *)(param_1 + 0x3c) * 0x10);
  pcVar7 = (char *)((long)puVar1 + 0xc);
  if ((*pcVar7 != '\0') && (plVar6 = *(long **)(param_1 + -0x68), (int)plVar6[0x32] - 2U < 5)) {
    lVar5 = *plVar6;
    iVar4 = msm_pcie_prevent_l1(lVar5 + -0xd0);
    if (iVar4 == 0) {
      cVar3 = *pcVar7;
      while ((cVar3 != '\0' && ((int)plVar6[0x32] - 2U < 5))) {
        writel_relaxed(*(undefined4 *)(puVar1 + 1),*puVar1);
        *pcVar7 = '\0';
        uVar2 = *(int *)(param_1 + 0x3c) + 1U & 0x1ff;
        puVar1 = (undefined8 *)(*(long *)(param_1 + 0x30) + (ulong)uVar2 * 0x10);
        *(uint *)(param_1 + 0x3c) = uVar2;
        pcVar7 = (char *)((long)puVar1 + 0xc);
        cVar3 = *pcVar7;
      }
      msm_pcie_allow_l1(lVar5 + -0xd0);
    }
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 0010e954 size=132
// signature: undefined writel_relaxed(void)
// callers: [mhi_reg_write_work]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10e96c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10e9a8,uVar1);
  return;
}



//------------------------------------------------------------
// mhi_misc_sysfs_create @ 0010e9dc size=240
// signature: undefined mhi_misc_sysfs_create(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

int mhi_misc_sysfs_create(long param_1)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  
  lVar1 = *(long *)(param_1 + 8) + 0x28;
  iVar2 = sysfs_create_group(lVar1,&mhi_misc_group);
  if (iVar2 == 0) {
    iVar2 = sysfs_create_group(lVar1,mhi_tsync_group);
    if (iVar2 == 0) {
      return 0;
    }
    lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar1,"[E][%s] Failed to create time synchronization sysfs group\n",
             "mhi_misc_sysfs_create");
    if (lVar4 == 0) {
      return iVar2;
    }
    if (2 < *(uint *)(lVar4 + 0x18)) {
      return iVar2;
    }
    pcVar3 = "[E][%s] Failed to create time synchronization sysfs group\n";
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar1,"[E][%s] Failed to create misc sysfs group\n","mhi_misc_sysfs_create");
    if (lVar4 == 0) {
      return iVar2;
    }
    if (2 < *(uint *)(lVar4 + 0x18)) {
      return iVar2;
    }
    pcVar3 = "[E][%s] Failed to create misc sysfs group\n";
  }
  ipc_log_string(*(undefined8 *)(lVar4 + 0x20),pcVar3,"mhi_misc_sysfs_create");
  return iVar2;
}



//------------------------------------------------------------
// mhi_misc_sysfs_destroy @ 0010ead0 size=72
// signature: undefined mhi_misc_sysfs_destroy(void)
// callers: [mhi_unregister_controller]
//------------------------------------------------------------

void mhi_misc_sysfs_destroy(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 8) + 0x28;
  sysfs_remove_group(lVar1,mhi_tsync_group);
  sysfs_remove_group(lVar1,&mhi_misc_group);
  return;
}



//------------------------------------------------------------
// mhi_misc_register_controller @ 0010eb1c size=436
// signature: undefined mhi_misc_register_controller(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_misc_register_controller(long *param_1)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  
  lVar8 = param_1[1];
  puVar4 = (undefined8 *)kmalloc_trace(_dma_alloc_attrs,0xdc0,0xb8);
  if (puVar4 != (undefined8 *)0x0) {
    lVar1 = *param_1;
    lVar2 = param_1[1];
    if (lVar1 != 0xd0) {
      dev_set_name((long *)(lVar2 + 0x28),"mhi_%04x_%02u.%02u.%02u",*(undefined2 *)(lVar1 + -0x92),
                   *(undefined4 *)(*(long *)(lVar1 + -0xc0) + 0xfc),
                   *(undefined1 *)(*(long *)(lVar1 + -0xc0) + 0xf8),
                   *(uint *)(lVar1 + -0x98) >> 3 & 0x1f);
      lVar7 = *(long *)(lVar2 + 0x98);
      if (lVar7 == 0) {
        lVar7 = *(long *)(lVar2 + 0x28);
      }
      *(long *)(lVar2 + 8) = lVar7;
      *(uint *)(puVar4 + 0xb) =
           (uint)*(ushort *)(lVar1 + -0x92) << 0x10 |
           (*(uint *)(*(long *)(lVar1 + -0xc0) + 0xfc) & 0xf) << 0xc |
           (uint)*(byte *)(*(long *)(lVar1 + -0xc0) + 0xf8) << 4 |
           *(uint *)(lVar1 + -0x98) >> 3 & 0xf;
    }
    uVar5 = ipc_log_context_create(100,*(undefined8 *)(lVar2 + 8),0);
    puVar4[4] = uVar5;
    puVar4[2] = param_1;
    mutex_lock(&DAT_001163d0);
    puVar3 = DAT_001163c8;
    uVar6 = __list_add_valid(puVar4,DAT_001163c8,&mhi_bus);
    if ((uVar6 & 1) != 0) {
      DAT_001163c8 = puVar4;
      *puVar4 = &mhi_bus;
      puVar4[1] = puVar3;
      *puVar3 = puVar4;
    }
    mutex_unlock(&DAT_001163d0);
    *(undefined8 **)(lVar8 + 0xc0) = puVar4;
    lVar8 = alloc_workqueue("mhi_offload_wq",0xa0012,1);
    puVar4[0xe] = lVar8;
    if (lVar8 == 0) {
      _dev_err(*param_1,"Failed to allocate offload workqueue\n");
    }
    else {
      puVar4[0xf] = 0xfffffffe0;
      puVar4[0x10] = puVar4 + 0x10;
      puVar4[0x11] = puVar4 + 0x10;
      uVar5 = _device_set_wakeup_capable;
      puVar4[0x12] = mhi_reg_write_work;
      lVar8 = kmalloc_trace(uVar5,0xdc0,0x2000);
      puVar4[0x15] = lVar8;
      if (lVar8 != 0) {
        *(undefined4 *)(puVar4 + 0x16) = 0xffffffff;
        return 0;
      }
      destroy_workqueue(puVar4[0xe]);
    }
    ipc_log_context_destroy(puVar4[4]);
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// mhi_misc_unregister_controller @ 0010ecd4 size=168
// signature: undefined mhi_misc_unregister_controller(void)
// callers: [mhi_register_controller, mhi_unregister_controller]
//------------------------------------------------------------

void mhi_misc_unregister_controller(long param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 8) + 0xc0);
  if (plVar4 != (long *)0x0) {
    mutex_lock(&DAT_001163d0);
    uVar2 = __list_del_entry_valid(plVar4);
    if ((uVar2 & 1) != 0) {
      lVar3 = *plVar4;
      plVar1 = (long *)plVar4[1];
      *(long **)(lVar3 + 8) = plVar1;
      *plVar1 = lVar3;
    }
    *plVar4 = -0x2152ffffffffff00;
    plVar4[1] = -0x2152fffffffffede;
    mutex_unlock(&DAT_001163d0);
    kfree(plVar4[0x15]);
    if (plVar4[0xc] == 0) {
      lVar3 = 0;
    }
    else {
      kfree(*(undefined8 *)(plVar4[0xc] + 0x18));
      lVar3 = plVar4[0xc];
    }
    kfree(lVar3);
    kfree(plVar4[0xd]);
    kfree(plVar4);
  }
  return;
}



//------------------------------------------------------------
// mhi_controller_get_privdata @ 0010ed80 size=36
// signature: undefined mhi_controller_get_privdata(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_controller_get_privdata(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if ((*(long *)(param_1 + 8) == 0) ||
       (lVar2 = *(long *)(*(long *)(param_1 + 8) + 0xc0), lVar2 == 0)) {
      return 0;
    }
    uVar1 = *(undefined8 *)(lVar2 + 0x38);
  }
  return uVar1;
}



//------------------------------------------------------------
// mhi_controller_set_privdata @ 0010eda8 size=28
// signature: undefined mhi_controller_set_privdata(void)
// callers: []
//------------------------------------------------------------

void mhi_controller_set_privdata(long param_1,undefined8 param_2)

{
  long lVar1;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 8) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 8) + 0xc0), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x38) = param_2;
  }
  return;
}



//------------------------------------------------------------
// mhi_bdf_to_controller @ 0010edc8 size=200
// signature: undefined mhi_bdf_to_controller(void)
// callers: []
//------------------------------------------------------------

long mhi_bdf_to_controller(uint param_1,uint param_2,uint param_3,uint param_4)

{
  long lVar1;
  int iVar2;
  char *__s2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  iVar2 = snprintf((char *)&local_58,0x20,"mhi_%04x_%02u.%02u.%02u",param_4,param_1,param_2,param_3)
  ;
  puVar4 = mhi_bus;
  do {
    if ((undefined8 **)puVar4 == &mhi_bus) {
      lVar3 = 0;
      break;
    }
    lVar3 = puVar4[2];
    puVar4 = (undefined8 *)*puVar4;
    __s2 = *(char **)(*(long *)(lVar3 + 8) + 8);
  } while ((__s2 == (char *)0x0) || (iVar2 = strcmp((char *)&local_58,__s2), iVar2 != 0));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return lVar3;
}



//------------------------------------------------------------
// mhi_report_error @ 0010ee94 size=464
// signature: undefined mhi_report_error(void)
// callers: [mhi_force_reset, mhi_intvec_threaded_handler, mhi_in_rddm, mhi_pm_fast_resume]
//------------------------------------------------------------

undefined8 mhi_report_error(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    lVar9 = *(long *)(param_1 + 8);
    lVar5 = param_1 + 0x178;
    plVar7 = *(long **)(*(long *)(lVar9 + 0xc0) + 0x60);
    uVar2 = _raw_write_lock_irqsave(lVar5);
    iVar1 = mhi_tryset_pm_state(param_1,0x100);
    if (iVar1 == 0x100) {
      *(undefined4 *)(param_1 + 400) = 0xff;
      __wake_up(param_1 + 0x210,3,0,0);
      _raw_write_unlock_irqrestore(lVar5,uVar2);
      if ((plVar7 != (long *)0x0) && (*plVar7 != 0)) {
        memcpy((void *)plVar7[3],(void *)*plVar7,plVar7[2]);
        lVar5 = *(long *)(lVar9 + 0x98);
        lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        if (lVar5 == 0) {
          lVar5 = *(long *)(lVar9 + 0x28);
        }
        _dev_err(lVar9 + 0x28,"[E][%s] mhi: %s sfr: %s\n","mhi_report_error",lVar5,*plVar7);
        if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x18) < 3)) {
          lVar5 = *(long *)(lVar9 + 0x98);
          if (lVar5 == 0) {
            lVar5 = *(long *)(lVar9 + 0x28);
          }
          ipc_log_string(*(undefined8 *)(lVar6 + 0x20),"[E][%s] mhi: %s sfr: %s\n",
                         "mhi_report_error",lVar5,*plVar7);
        }
      }
      device_for_each_child(*(long *)(param_1 + 8) + 0x28,0,mhi_notify_fatal_cb);
      uVar2 = 0;
    }
    else {
      lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      uVar3 = to_mhi_pm_state_str(0x100);
      uVar4 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
      _dev_err(lVar9 + 0x28,"[E][%s] Failed to move to state: %s from: %s\n","mhi_report_error",
               uVar3,uVar4);
      if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x18) < 3)) {
        uVar8 = *(undefined8 *)(lVar6 + 0x20);
        uVar3 = to_mhi_pm_state_str(0x100);
        uVar4 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
        ipc_log_string(uVar8,"[E][%s] Failed to move to state: %s from: %s\n","mhi_report_error",
                       uVar3,uVar4);
      }
      _raw_write_unlock_irqrestore(lVar5,uVar2);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// mhi_notify_fatal_cb @ 0010f068 size=40
// signature: undefined mhi_notify_fatal_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_notify_fatal_cb(long param_1)

{
  mhi_notify(param_1 + -0x28,7);
  return 0;
}



//------------------------------------------------------------
// mhi_device_configure @ 0010f094 size=468
// signature: undefined mhi_device_configure(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_device_configure(long param_1,int param_2,long param_3,int param_4)

{
  long *plVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  char *pcVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  
  lVar13 = *(long *)(param_1 + 0x10);
  lVar12 = *(long *)(lVar13 + 8);
  if ((param_2 - 2U < 2) || (param_2 == 0)) {
    plVar1 = (long *)(param_1 + 0x20);
  }
  else {
    if (param_2 != 1) {
      return 0xffffffea;
    }
    plVar1 = (long *)(param_1 + 0x18);
  }
  if (0 < param_4) {
    plVar11 = (long *)(param_3 + 0x18);
    param_4 = param_4 + 1;
    iVar4 = *(int *)(*plVar1 + 200);
    iVar5 = *(int *)(*plVar1 + 0xcc);
    do {
      pcVar10 = (char *)plVar11[-2];
      iVar6 = strcmp(pcVar10,"ECA");
      if (iVar6 == 0) {
        if (*plVar11 != 0x2c) {
          lVar13 = *(long *)(*(long *)(lVar13 + 8) + 0xc0);
          _dev_err(lVar12 + 0x28,"[E][%s] Invalid ECA size, expected:%zu actual%zu\n",
                   "mhi_device_configure",0x2c);
          if (lVar13 == 0) {
            return 0xffffffea;
          }
          if (2 < *(uint *)(lVar13 + 0x18)) {
            return 0xffffffea;
          }
          pcVar10 = "[E][%s] Invalid ECA size, expected:%zu actual%zu\n";
          goto LAB_0010f22c;
        }
        puVar7 = (undefined8 *)(**(long **)(lVar13 + 0x140) + (long)iVar5 * 0x2c);
      }
      else {
        iVar6 = strcmp(pcVar10,"CCA");
        if (iVar6 != 0) {
          return 0xffffffea;
        }
        if (*plVar11 != 0x2c) {
          lVar13 = *(long *)(*(long *)(lVar13 + 8) + 0xc0);
          _dev_err(lVar12 + 0x28,"[E][%s] Invalid CCA size, expected:%zu actual:%zu\n",
                   "mhi_device_configure",0x2c);
          if (lVar13 == 0) {
            return 0xffffffea;
          }
          if (2 < *(uint *)(lVar13 + 0x18)) {
            return 0xffffffea;
          }
          pcVar10 = "[E][%s] Invalid CCA size, expected:%zu actual:%zu\n";
LAB_0010f22c:
          ipc_log_string(*(undefined8 *)(lVar13 + 0x20),pcVar10,"mhi_device_configure",0x2c,*plVar11
                        );
          return 0xffffffea;
        }
        puVar7 = (undefined8 *)(*(long *)(*(long *)(lVar13 + 0x140) + 8) + (long)iVar4 * 0x2c);
      }
      puVar8 = (undefined8 *)plVar11[-3];
      plVar11 = plVar11 + 4;
      param_4 = param_4 + -1;
      uVar2 = puVar8[1];
      *puVar7 = *puVar8;
      puVar7[1] = uVar2;
      uVar2 = puVar8[3];
      uVar3 = puVar8[4];
      uVar9 = puVar8[2];
      *(undefined4 *)(puVar7 + 5) = *(undefined4 *)(puVar8 + 5);
      puVar7[3] = uVar2;
      puVar7[4] = uVar3;
      puVar7[2] = uVar9;
    } while (1 < param_4);
  }
  return 0;
}



//------------------------------------------------------------
// mhi_set_m2_timeout_ms @ 0010f26c size=28
// signature: undefined mhi_set_m2_timeout_ms(void)
// callers: []
//------------------------------------------------------------

void mhi_set_m2_timeout_ms(long param_1,undefined4 param_2)

{
  long lVar1;
  
  if (((param_1 != 0) && (*(long *)(param_1 + 8) != 0)) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 8) + 0xc0), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x30) = param_2;
  }
  return;
}



//------------------------------------------------------------
// mhi_pm_fast_resume @ 0010f28c size=1076
// signature: undefined mhi_pm_fast_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_pm_fast_resume(long param_1,ulong param_2)

{
  long lVar1;
  int *piVar2;
  char *pcVar3;
  char cVar4;
  bool bVar5;
  long *plVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  long lVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long *plVar15;
  
  lVar13 = *(long *)(param_1 + 8);
  lVar14 = *(long *)(lVar13 + 0xc0);
  if ((lVar14 != 0) && (*(int *)(lVar14 + 0x18) == 0)) {
    uVar12 = *(undefined8 *)(lVar14 + 0x20);
    uVar9 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
    pcVar10 = "RESET";
    switch(*(int *)(param_1 + 400)) {
    case 0:
      break;
    case 1:
      pcVar10 = "READY";
      break;
    case 2:
      pcVar10 = "M0";
      break;
    case 3:
      pcVar10 = "M1";
      break;
    case 4:
      pcVar10 = "M2";
      break;
    case 5:
      pcVar10 = "M3";
      break;
    case 6:
      pcVar10 = "M3 FAST";
      break;
    case 7:
      pcVar10 = "BHI";
      break;
    default:
      if (*(int *)(param_1 + 400) == 0xff) {
        pcVar10 = "SYS ERROR";
      }
      else {
        pcVar10 = "Unknown state";
      }
    }
    pcVar3 = "true";
    if ((param_2 & 1) == 0) {
      pcVar3 = "false";
    }
    ipc_log_string(uVar12,"[D][%s] Entered with PM state: %s, MHI state: %s notify: %s\n",
                   "mhi_pm_fast_resume",uVar9,pcVar10,pcVar3);
  }
  if (*(uint *)(param_1 + 0x184) != 1) {
    if (0x7f < *(uint *)(param_1 + 0x184)) {
      return 0xfffffffb;
    }
    lVar1 = param_1 + 0x178;
    _raw_read_lock_bh(lVar1);
    if (*(int *)(param_1 + 0x184) != 0x20) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10f688);
      (*pcVar7)();
    }
    _raw_read_unlock_bh(lVar1);
    if (((*(long *)(param_1 + 0x90) == 0) || (iVar8 = mhi_get_exec_env(param_1), iVar8 != 3)) ||
       (4 < *(int *)(param_1 + 400) - 2U)) {
      if ((param_2 & 1) != 0) {
        plVar6 = (long *)*(long *)(param_1 + 0xa8);
        while (plVar6 != (long *)(param_1 + 0xa8)) {
          plVar15 = (long *)*plVar6;
          mutex_lock(plVar6 + -0xb);
          if (plVar6[-0xd] != 0) {
            mhi_notify(plVar6[-0xd],3);
          }
          mutex_unlock(plVar6 + -0xb);
          plVar6 = plVar15;
        }
      }
      lVar11 = *(long *)(param_1 + 0x130);
      piVar2 = (int *)(lVar11 + 0xb8);
      Hint_Prefetch(piVar2,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar5) {
          *piVar2 = *piVar2 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
      tasklet_unlock_wait(lVar11 + 0xa8);
      DataMemoryBarrier(2,3);
      _raw_write_lock_irq(lVar1);
      if (0x7f < *(uint *)(param_1 + 0x184)) {
        _raw_write_unlock_irq(lVar1);
        DataMemoryBarrier(2,3);
        piVar2 = (int *)(*(long *)(param_1 + 0x130) + 0xb8);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = *piVar2 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        return 0xfffffffb;
      }
      *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(lVar14 + 0x28);
      *(undefined4 *)(param_1 + 400) = *(undefined4 *)(lVar14 + 0x2c);
      _raw_write_unlock_irq(lVar1);
      if (*(int *)(param_1 + 0x184) == 8) {
        _raw_read_lock_bh(lVar1);
        if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10f52c);
          (*pcVar7)();
        }
        (**(code **)(param_1 + 0x230))(param_1,1);
        if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10f554);
          (*pcVar7)();
        }
        (**(code **)(param_1 + 0x238))(param_1,1);
        _raw_read_unlock_bh(lVar1);
      }
      else if (*(int *)(param_1 + 0x184) == 4) {
        mhi_pm_m0_transition(param_1);
      }
      else {
        lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        uVar9 = to_mhi_pm_state_str();
        _dev_err(lVar13 + 0x28,"[E][%s] Unexpected PM state:%s after restore\n","mhi_pm_fast_resume"
                 ,uVar9);
        if ((lVar14 != 0) && (*(uint *)(lVar14 + 0x18) < 3)) {
          uVar12 = *(undefined8 *)(lVar14 + 0x20);
          uVar9 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
          ipc_log_string(uVar12,"[E][%s] Unexpected PM state:%s after restore\n",
                         "mhi_pm_fast_resume",uVar9);
        }
      }
      DataMemoryBarrier(2,3);
      piVar2 = (int *)(*(long *)(param_1 + 0x130) + 0xb8);
      Hint_Prefetch(piVar2,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar5) {
          *piVar2 = *piVar2 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      mhi_irq_handler(0,*(undefined8 *)(param_1 + 0x130));
    }
    else {
      *(undefined4 *)(param_1 + 0x18c) = 3;
      lVar14 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar13 + 0x28,"[E][%s] RDDM event occurred!\n","mhi_pm_fast_resume");
      if ((lVar14 != 0) && (*(uint *)(lVar14 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar14 + 0x20),"[E][%s] RDDM event occurred!\n",
                       "mhi_pm_fast_resume");
      }
      mhi_report_error(param_1);
      if (*(int *)(*(code **)(param_1 + 0x228) + -4) != -0x51759158) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10f604);
        (*pcVar7)();
      }
      (**(code **)(param_1 + 0x228))(param_1,4);
      __wake_up(param_1 + 0x210,3,0,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// mhi_state_str @ 0010f6e8 size=160
// signature: undefined mhi_state_str(void)
// callers: [mhi_device_get_sync_atomic]
//------------------------------------------------------------

char * mhi_state_str(int param_1)

{
  char *pcVar1;
  
  pcVar1 = "RESET";
  switch(param_1) {
  case 0:
    goto switchD_0010f710_caseD_0;
  case 1:
    return "READY";
  case 2:
    return "M0";
  case 3:
    return "M1";
  case 4:
    return "M2";
  case 5:
    return "M3";
  case 6:
    return "M3 FAST";
  case 7:
    return "BHI";
  default:
    if (param_1 == 0xff) {
      return "SYS ERROR";
    }
    pcVar1 = "Unknown state";
switchD_0010f710_caseD_0:
    return pcVar1;
  }
}



//------------------------------------------------------------
// mhi_pm_fast_suspend @ 0010f78c size=1168
// signature: undefined mhi_pm_fast_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_pm_fast_suspend(long param_1,ulong param_2)

{
  int *piVar1;
  char *pcVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  long *plVar10;
  long *plVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  long lVar14;
  long *plVar15;
  long lVar16;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar14 = sp_el0;
  local_48 = *(long *)(lVar14 + 0x638);
  if (*(uint *)(param_1 + 0x184) == 1) {
    uVar13 = 0xffffffea;
    goto LAB_0010f930;
  }
  if (0x7f < *(uint *)(param_1 + 0x184)) {
    uVar13 = 0xfffffffb;
    goto LAB_0010f930;
  }
  lVar14 = *(long *)(param_1 + 8);
  lVar16 = *(long *)(lVar14 + 0xc0);
  if (*(int *)(param_1 + 0x198) != 0) {
    uVar13 = 0xfffffff0;
    goto LAB_0010f930;
  }
  lVar6 = __msecs_to_jiffies(*(undefined4 *)(lVar16 + 0x30));
  if ((*(int *)(param_1 + 400) != 4) && (lVar6 != 0 || *(int *)(param_1 + 400) == 4)) {
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_70 = 0;
    lVar7 = __msecs_to_jiffies(*(undefined4 *)(lVar16 + 0x30));
    init_wait_entry(&local_70,0);
    lVar6 = param_1 + 0x210;
    prepare_to_wait_event(lVar6,&local_70,2);
    iVar5 = *(int *)(param_1 + 400);
    if (lVar7 == 0 && iVar5 == 4) {
      lVar7 = 1;
    }
    while ((iVar5 != 4 && (lVar7 != 0))) {
      lVar7 = schedule_timeout();
      prepare_to_wait_event(lVar6,&local_70,2);
      iVar5 = *(int *)(param_1 + 400);
      if (lVar7 == 0 && iVar5 == 4) {
        lVar7 = 1;
      }
    }
    finish_wait(lVar6,&local_70);
  }
  lVar6 = *(long *)(param_1 + 0x130);
  piVar1 = (int *)(lVar6 + 0xb8);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = *piVar1 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  tasklet_unlock_wait(lVar6 + 0xa8);
  lVar6 = param_1 + 0x178;
  DataMemoryBarrier(2,3);
  _raw_write_lock_irq(lVar6);
  if (*(int *)(param_1 + 0x198) == 0) {
    uVar9 = *(uint *)(param_1 + 0x184);
    if (uVar9 < 0x80) {
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
        pcVar2 = "true";
        if ((param_2 & 1) == 0) {
          pcVar2 = "false";
        }
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                       "[D][%s] Allowing Fast M3 transition with notify: %s\n","mhi_pm_fast_suspend"
                       ,pcVar2);
        uVar9 = *(uint *)(param_1 + 0x184);
      }
      *(uint *)(lVar16 + 0x28) = uVar9;
      *(undefined4 *)(lVar16 + 0x2c) = *(undefined4 *)(param_1 + 400);
      if ((*(int *)(param_1 + 0x184) == 8) && (iVar5 = mhi_tryset_pm_state(param_1,4), iVar5 != 4))
      {
        lVar16 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        uVar13 = to_mhi_pm_state_str(4);
        uVar8 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
        _dev_err(lVar14 + 0x28,"[E][%s] Error setting to PM state: %s from: %s\n",
                 "mhi_pm_fast_suspend",uVar13,uVar8);
        if ((lVar16 != 0) && (*(uint *)(lVar16 + 0x18) < 3)) {
          uVar13 = 4;
LAB_0010fba8:
          uVar12 = *(undefined8 *)(lVar16 + 0x20);
          uVar13 = to_mhi_pm_state_str(uVar13);
          uVar8 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
          ipc_log_string(uVar12,"[E][%s] Error setting to PM state: %s from: %s\n",
                         "mhi_pm_fast_suspend",uVar13,uVar8);
        }
      }
      else {
        iVar5 = mhi_tryset_pm_state(param_1,0x10);
        if (iVar5 == 0x10) {
          iVar5 = mhi_tryset_pm_state(param_1,0x20);
          if (iVar5 == 0x20) {
            *(undefined4 *)(param_1 + 400) = 6;
            *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
            _raw_write_unlock_irq(lVar6);
            if ((*(byte *)(param_1 + 0x188) >> 3 & 1) == 0) {
              flush_work(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x78);
            }
            DataMemoryBarrier(2,3);
            piVar1 = (int *)(*(long *)(param_1 + 0x130) + 0xb8);
            Hint_Prefetch(piVar1,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar4) {
                *piVar1 = *piVar1 + -1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            mhi_irq_handler(0,*(undefined8 *)(param_1 + 0x130));
            uVar13 = 0;
            if ((param_2 & 1) != 0) {
              plVar10 = (long *)(param_1 + 0xa8);
              plVar15 = (long *)*plVar10;
              if ((long *)*plVar10 == plVar10) {
                uVar13 = 0;
              }
              else {
                do {
                  plVar11 = (long *)*plVar15;
                  mutex_lock(plVar15 + -0xb);
                  if (plVar15[-0xd] != 0) {
                    mhi_notify(plVar15[-0xd],2);
                  }
                  mutex_unlock(plVar15 + -0xb);
                  uVar13 = 0;
                  plVar15 = plVar11;
                } while (plVar11 != plVar10);
              }
            }
            goto LAB_0010f930;
          }
          lVar16 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          uVar13 = to_mhi_pm_state_str(0x20);
          uVar8 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
          _dev_err(lVar14 + 0x28,"[E][%s] Error setting to PM state: %s from: %s\n",
                   "mhi_pm_fast_suspend",uVar13,uVar8);
          if ((lVar16 != 0) && (*(uint *)(lVar16 + 0x18) < 3)) {
            uVar13 = 0x20;
            goto LAB_0010fba8;
          }
        }
        else {
          lVar16 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          uVar13 = to_mhi_pm_state_str(0x10);
          uVar8 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
          _dev_err(lVar14 + 0x28,"[E][%s] Error setting to PM state: %s from: %s\n",
                   "mhi_pm_fast_suspend",uVar13,uVar8);
          if ((lVar16 != 0) && (*(uint *)(lVar16 + 0x18) < 3)) {
            uVar13 = 0x10;
            goto LAB_0010fba8;
          }
        }
      }
    }
    uVar13 = 0xfffffffb;
  }
  else {
    uVar13 = 0xfffffff0;
  }
  _raw_write_unlock_irq(lVar6);
  DataMemoryBarrier(2,3);
  piVar1 = (int *)(*(long *)(param_1 + 0x130) + 0xb8);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = *piVar1 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  mhi_irq_handler(0,*(undefined8 *)(param_1 + 0x130));
LAB_0010f930:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13;
}



//------------------------------------------------------------
// mhi_dump_sfr @ 0010fc44 size=964
// signature: undefined mhi_dump_sfr(void)
// callers: []
//------------------------------------------------------------

void mhi_dump_sfr(long param_1)

{
  int iVar1;
  void *__dest;
  size_t __n;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  void *__src;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  uint uVar10;
  undefined8 *puVar11;
  ulong uVar12;
  uint uVar13;
  
  puVar11 = *(undefined8 **)(param_1 + 0x90);
  lVar4 = *(long *)(param_1 + 8);
  plVar8 = (long *)*puVar11;
  lVar7 = *plVar8;
  uVar5 = *(uint *)(lVar7 + 4);
  if (uVar5 - 0x309 < 0xfffffcff) {
    lVar6 = *(long *)(lVar4 + 0xc0);
    _dev_err(lVar4 + 0x28,"[E][%s] invalid reported header size %u\n","mhi_dump_sfr");
    if (lVar6 == 0) {
      return;
    }
    if (*(uint *)(lVar6 + 0x18) < 3) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x20),"[E][%s] invalid reported header size %u\n",
                     "mhi_dump_sfr",*(undefined4 *)(lVar7 + 4));
      return;
    }
    return;
  }
  if (uVar5 - 8 < 0x40) {
    lVar7 = *(long *)(lVar4 + 0xc0);
    _dev_err(lVar4 + 0x28,"[E][%s] invalid rddm table size %u\n","mhi_dump_sfr",0);
    if (lVar7 == 0) {
      return;
    }
    if (*(uint *)(lVar7 + 0x18) < 3) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] invalid rddm table size %u\n",
                     "mhi_dump_sfr",0);
      return;
    }
    return;
  }
  uVar10 = uVar5 - 8 >> 6;
  uVar12 = 0;
  uVar9 = 0;
  uVar13 = (int)plVar8[3] - uVar5;
  __src = (void *)(lVar7 + (ulong)uVar5);
  if (uVar10 < 2) {
    uVar10 = 1;
  }
  while( true ) {
    lVar6 = lVar7 + uVar12 * 0x40;
    iVar1 = strcmp((char *)(lVar6 + 0x34),"Q6-SFR.bin");
    uVar5 = (uint)uVar9;
    if (iVar1 == 0) break;
    uVar3 = *(ulong *)(lVar6 + 0x18);
    if (uVar13 < uVar3) {
      uVar2 = (int)uVar3 - uVar13;
      if (uVar2 != 0) {
        do {
          uVar5 = uVar5 + 1;
          if (*(uint *)(puVar11 + 2) == uVar5) {
            lVar7 = lVar7 + (uVar12 & 0xffffffff) * 0x40 + 0x34;
            lVar6 = *(long *)(lVar4 + 0xc0);
            _dev_err(lVar4 + 0x28,"[E][%s] invalid size for file %s\n","mhi_find_next_file_offset",
                     lVar7);
            if (lVar6 == 0) {
              return;
            }
            if (*(uint *)(lVar6 + 0x18) < 3) {
              ipc_log_string(*(undefined8 *)(lVar6 + 0x20),"[E][%s] invalid size for file %s\n",
                             "mhi_find_next_file_offset",lVar7);
              return;
            }
            return;
          }
          uVar9 = (ulong)uVar5;
          iVar1 = (int)plVar8[(ulong)uVar5 * 4 + 3];
          if ((ulong)uVar2 <= (ulong)plVar8[(ulong)uVar5 * 4 + 3]) {
            uVar13 = iVar1 - uVar2;
            __src = (void *)(plVar8[uVar9 * 4] + (ulong)uVar2);
            goto LAB_0010fccc;
          }
          uVar2 = uVar2 - iVar1;
        } while (uVar2 != 0);
      }
      uVar13 = 0;
    }
    else {
      __src = (void *)((long)__src + uVar3);
      uVar13 = uVar13 - (int)uVar3;
    }
LAB_0010fccc:
    uVar12 = uVar12 + 1;
    if (uVar12 == uVar10) {
      return;
    }
  }
  uVar12 = *(ulong *)(lVar7 + (uVar12 & 0xffffffff) * 0x40 + 0x18);
  uVar10 = (uint)uVar12;
  __dest = (void *)__kmalloc(uVar10 + 1,0xdc0);
  if (__dest == (void *)0x0) {
    return;
  }
  if (uVar10 != 0) {
    if (uVar13 == 0) {
      uVar3 = (plVar8 + uVar9 * 4)[3];
      __src = (void *)plVar8[uVar9 * 4];
      uVar13 = (uint)uVar3;
      if ((uVar12 & 0xffffffff) <= uVar3) {
        uVar13 = uVar10;
      }
    }
    if (uVar13 < uVar10) {
      memcpy(__dest,__src,(ulong)uVar13);
      __dest = (void *)((long)__dest + (ulong)uVar13);
      uVar5 = uVar5 + 1;
      if (uVar5 != *(uint *)(*(long *)(param_1 + 0x90) + 0x10)) {
        uVar13 = uVar10 - uVar13;
        do {
          if (uVar13 == 0) goto LAB_0010ff9c;
          uVar9 = (plVar8 + (ulong)uVar5 * 4)[3];
          __src = (void *)plVar8[(ulong)uVar5 * 4];
          uVar10 = (uint)uVar9;
          if (uVar13 <= uVar9) {
            uVar10 = uVar13;
          }
          if (uVar13 < uVar10 || uVar13 - uVar10 == 0) {
            __n = (size_t)uVar13;
            goto LAB_0010ff90;
          }
          memcpy(__dest,__src,(ulong)uVar10);
          __dest = (void *)((long)__dest + (ulong)uVar10);
          uVar5 = uVar5 + 1;
          uVar13 = uVar13 - uVar10;
        } while (uVar5 != *(uint *)(*(long *)(param_1 + 0x90) + 0x10));
      }
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar4 + 0x28,"[E][%s] invalid size for SFR file\n","mhi_process_sfr");
      if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] invalid size for SFR file\n",
                       "mhi_process_sfr");
      }
      goto LAB_0010fff4;
    }
    __n = uVar12 & 0xffffffff;
LAB_0010ff90:
    memcpy(__dest,__src,__n);
  }
LAB_0010ff9c:
  *(undefined1 *)((long)__dest + (uVar12 & 0xffffffff)) = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  _dev_err(lVar4 + 0x28,"[E][%s] %s\n","mhi_process_sfr",__dest);
  if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
    ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] %s\n","mhi_process_sfr",__dest);
  }
LAB_0010fff4:
  kfree(__dest);
  return;
}



//------------------------------------------------------------
// mhi_scan_rddm_cookie @ 0011000c size=260
// signature: undefined mhi_scan_rddm_cookie(void)
// callers: []
//------------------------------------------------------------

void mhi_scan_rddm_cookie(long param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  bVar1 = false;
  local_2c = 0;
  if ((param_2 != 0) && (*(long *)(param_1 + 0x90) != 0)) {
    lVar3 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar3 != 0) && (*(int *)(lVar3 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x20),"[D][%s] Checking BHI debug register for 0x%x\n",
                     "mhi_scan_rddm_cookie",param_2);
    }
    if (((*(ushort *)(param_1 + 0x184) & 0xfde) == 0) ||
       (iVar2 = mhi_read_reg(param_1,*(undefined8 *)(param_1 + 0x20),0x38,&local_2c), iVar2 != 0)) {
      bVar1 = false;
    }
    else {
      lVar3 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar3 != 0) && (*(int *)(lVar3 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x20),"[D][%s] BHI_ERRDBG2 value:0x%x\n",
                       "mhi_scan_rddm_cookie",local_2c);
      }
      bVar1 = local_2c == param_2;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// mhi_debug_reg_dump @ 00110114 size=1520
// signature: undefined mhi_debug_reg_dump(void)
// callers: [mhi_pm_suspend]
//------------------------------------------------------------

void mhi_debug_reg_dump(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined4 local_1bc;
  char *local_1b8;
  undefined4 local_1b0 [2];
  long local_1a8;
  char *pcStack_1a0;
  undefined4 local_198;
  long local_190;
  char *pcStack_188;
  undefined4 local_180;
  long local_178;
  char *pcStack_170;
  undefined4 local_168;
  long local_160;
  char *pcStack_158;
  undefined4 local_150;
  long local_148;
  char *pcStack_140;
  undefined4 local_138;
  long local_130;
  char *pcStack_128;
  undefined4 local_120;
  undefined8 local_118;
  char *pcStack_110;
  undefined4 local_108;
  undefined8 local_100;
  char *pcStack_f8;
  undefined8 local_e8;
  char *pcStack_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  char *pcStack_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  char *pcStack_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  char *pcStack_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  uVar6 = *(undefined8 *)(param_1 + 0x18);
  lVar11 = *(long *)(param_1 + 0x20);
  local_1bc = 0;
  uVar10 = *(undefined8 *)(param_1 + 0x28);
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  lVar12 = *(long *)(param_1 + 8);
  memset(local_1b0,0,0x128);
  local_1b8 = "BHI_ERRDBG2";
  local_180 = 0x34;
  local_1b0[0] = 0x38;
  local_120 = 0x38;
  pcStack_1a0 = "BHI_ERRDBG3";
  local_168 = 0x30;
  local_198 = 0x3c;
  local_108 = 0x48;
  pcStack_188 = "BHI_ERRDBG1";
  local_150 = 0x28;
  local_d8 = 0x3c;
  pcStack_170 = "BHI_ERRCODE";
  pcStack_128 = "MHI_CNTRL";
  local_c0 = 0x44;
  pcStack_158 = "BHI_EXECENV";
  pcStack_98 = "BHIE_RXVEC_STATUS";
  local_78 = 0;
  uStack_70 = 0;
  uStack_80 = 0;
  pcStack_140 = "BHI_STATUS";
  local_138 = 0x2c;
  pcStack_110 = "MHI_STATUS";
  pcStack_f8 = "MHI_WAKE_DB";
  lVar9 = *(long *)(lVar12 + 0xc0);
  pcStack_e0 = "BHIE_TXVEC_DB";
  pcStack_c8 = "BHIE_TXVEC_STATUS";
  pcStack_b0 = "BHIE_RXVEC_DB";
  local_a8 = 0x70;
  local_90 = 0x78;
  local_1a8 = lVar11;
  local_190 = lVar11;
  local_178 = lVar11;
  local_160 = lVar11;
  local_148 = lVar11;
  local_130 = lVar11;
  local_118 = uVar6;
  local_100 = uVar6;
  local_e8 = uVar1;
  local_d0 = uVar10;
  local_b8 = uVar10;
  local_a0 = uVar10;
  local_88 = uVar10;
  uVar6 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
  pcVar7 = "RESET";
  switch(*(int *)(param_1 + 400)) {
  case 0:
    break;
  case 1:
    pcVar7 = "READY";
    break;
  case 2:
    pcVar7 = "M0";
    break;
  case 3:
    pcVar7 = "M1";
    break;
  case 4:
    pcVar7 = "M2";
    break;
  case 5:
    pcVar7 = "M3";
    break;
  case 6:
    pcVar7 = "M3 FAST";
    break;
  case 7:
    pcVar7 = "BHI";
    break;
  default:
    if (*(int *)(param_1 + 400) == 0xff) {
      pcVar7 = "SYS ERROR";
    }
    else {
      pcVar7 = "Unknown state";
    }
  }
  if (*(uint *)(param_1 + 0x18c) < 10) {
    pcVar8 = (&mhi_ee_str)[*(uint *)(param_1 + 0x18c)];
  }
  else {
    pcVar8 = "INVALID_EE";
  }
  _dev_err(lVar12 + 0x28,"[E][%s] host pm_state:%s dev_state:%s ee:%s\n","mhi_debug_reg_dump",uVar6,
           pcVar7,pcVar8);
  if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
    uVar10 = *(undefined8 *)(lVar9 + 0x20);
    uVar6 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
    pcVar7 = "RESET";
    switch(*(int *)(param_1 + 400)) {
    case 0:
      break;
    case 1:
      pcVar7 = "READY";
      break;
    case 2:
      pcVar7 = "M0";
      break;
    case 3:
      pcVar7 = "M1";
      break;
    case 4:
      pcVar7 = "M2";
      break;
    case 5:
      pcVar7 = "M3";
      break;
    case 6:
      pcVar7 = "M3 FAST";
      break;
    case 7:
      pcVar7 = "BHI";
      break;
    default:
      if (*(int *)(param_1 + 400) == 0xff) {
        pcVar7 = "SYS ERROR";
      }
      else {
        pcVar7 = "Unknown state";
      }
    }
    if (*(uint *)(param_1 + 0x18c) < 10) {
      pcVar8 = (&mhi_ee_str)[*(uint *)(param_1 + 0x18c)];
    }
    else {
      pcVar8 = "INVALID_EE";
    }
    ipc_log_string(uVar10,"[E][%s] host pm_state:%s dev_state:%s ee:%s\n","mhi_debug_reg_dump",uVar6
                   ,pcVar7,pcVar8);
  }
  uVar3 = mhi_get_mhi_state(param_1);
  uVar4 = mhi_get_exec_env(param_1);
  lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if (uVar4 < 10) {
    pcVar7 = (&mhi_ee_str)[uVar4];
  }
  else {
    pcVar7 = "INVALID_EE";
  }
  pcVar8 = "RESET";
  switch((ulong)uVar3) {
  case 0:
    break;
  case 1:
    pcVar8 = "READY";
    break;
  case 2:
    pcVar8 = "M0";
    break;
  case 3:
    pcVar8 = "M1";
    break;
  case 4:
    pcVar8 = "M2";
    break;
  case 5:
    pcVar8 = "M3";
    break;
  case 6:
    pcVar8 = "M3 FAST";
    break;
  case 7:
    pcVar8 = "BHI";
    break;
  default:
    if (uVar3 == 0xff) {
      pcVar8 = "SYS ERROR";
    }
    else {
      pcVar8 = "Unknown state";
    }
  }
  _dev_err(lVar12 + 0x28,"[E][%s] device ee: %s dev_state: %s\n","mhi_debug_reg_dump",pcVar7,pcVar8)
  ;
  if ((lVar11 == 0) || (2 < *(uint *)(lVar11 + 0x18))) goto LAB_00110620;
  if (uVar4 < 10) {
    pcVar7 = (&mhi_ee_str)[uVar4];
    if (uVar3 < 8) goto LAB_00110568;
LAB_001105a8:
    if (uVar3 == 0xff) {
      pcVar8 = "SYS ERROR";
    }
    else {
      pcVar8 = "Unknown state";
    }
  }
  else {
    pcVar7 = "INVALID_EE";
    if (7 < uVar3) goto LAB_001105a8;
LAB_00110568:
    pcVar8 = "RESET";
    switch((ulong)(&switchD_00110584::switchdataD_00116300)[uVar3] * 4 + 0x110588) {
    case 0x110588:
      pcVar8 = "READY";
      break;
    case 0x1105bc:
      pcVar8 = "M0";
      break;
    case 0x1105c8:
      pcVar8 = "M1";
      break;
    case 0x1105d4:
      pcVar8 = "M2";
      break;
    case 0x1105e0:
      pcVar8 = "M3";
      break;
    case 0x1105ec:
      pcVar8 = "M3 FAST";
      break;
    case 0x1105f8:
      pcVar8 = "BHI";
    }
  }
  ipc_log_string(*(undefined8 *)(lVar11 + 0x20),"[E][%s] device ee: %s dev_state: %s\n",
                 "mhi_debug_reg_dump",pcVar7,pcVar8);
LAB_00110620:
  lVar11 = 0;
  do {
    lVar9 = *(long *)((long)local_1b0 + lVar11 + -8);
    if (lVar9 == 0) {
      lVar11 = sp_el0;
      if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (*(long *)((long)&local_1a8 + lVar11) != 0) {
      uVar5 = mhi_read_reg(param_1,*(long *)((long)&local_1a8 + lVar11),
                           *(undefined4 *)((long)local_1b0 + lVar11),&local_1bc);
      lVar13 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar12 + 0x28,"[E][%s] reg: %s val: 0x%x, ret: %d\n","mhi_debug_reg_dump",lVar9,
               local_1bc,uVar5);
      if ((lVar13 != 0) && (*(uint *)(lVar13 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x20),"[E][%s] reg: %s val: 0x%x, ret: %d\n",
                       "mhi_debug_reg_dump",lVar9,local_1bc,uVar5);
      }
    }
    lVar11 = lVar11 + 0x18;
  } while (lVar11 != 0x150);
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x110700);
  (*pcVar2)();
}



//------------------------------------------------------------
// mhi_device_get_sync_atomic @ 00110708 size=748
// signature: undefined mhi_device_get_sync_atomic(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_device_get_sync_atomic(long param_1,int param_2,ulong param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  
  lVar6 = *(long *)(param_1 + 0x10);
  lVar7 = lVar6 + 0x178;
  uVar4 = _raw_read_lock_irqsave(lVar7);
  if (*(uint *)(lVar6 + 0x184) < 0x80) {
    if (*(int *)(*(code **)(lVar6 + 0x230) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x110784);
      (*pcVar2)();
    }
    (**(code **)(lVar6 + 0x230))(lVar6,1);
    _raw_read_unlock_irqrestore(lVar7,uVar4);
    *(int *)(param_1 + 0x3cc) = *(int *)(param_1 + 0x3cc) + 1;
    pm_wakeup_dev_event(*(long *)(lVar6 + 8) + 0x28,0,0);
    if (*(int *)(*(code **)(lVar6 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1107d4);
      (*pcVar2)();
    }
    (**(code **)(lVar6 + 0x248))(lVar6);
    if (param_2 == 0) {
      if (*(int *)(lVar6 + 0x184) != 4) {
        lVar7 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
        _dev_err(param_1 + 0x28,"[E][%s] Return without waiting for M0\n",
                 "mhi_device_get_sync_atomic");
        if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[E][%s] Return without waiting for M0\n",
                         "mhi_device_get_sync_atomic");
        }
      }
    }
    else {
      if ((param_3 & 1) == 0) {
        uVar1 = *(uint *)(lVar6 + 0x184);
        for (; ((uVar1 != 4 && (uVar1 < 0x80)) && (0 < param_2)); param_2 = param_2 + -100) {
          __const_udelay(0x68dbc);
          uVar1 = *(uint *)(lVar6 + 0x184);
        }
      }
      else {
        for (; (iVar3 = mhi_get_mhi_state(lVar6), iVar3 != 2 &&
               (*(uint *)(lVar6 + 0x184) < 0x80 && 0 < param_2)); param_2 = param_2 + -100) {
          __const_udelay(0x68dbc);
        }
      }
      uVar1 = *(uint *)(lVar6 + 0x184);
      if ((0x7f < uVar1) || (param_2 < 1)) {
        lVar9 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
        uVar4 = mhi_state_str(*(undefined4 *)(lVar6 + 400));
        uVar5 = to_mhi_pm_state_str(uVar1);
        _dev_err(param_1 + 0x28,"[E][%s] Did not enter M0, cur_state: %s pm_state: %s\n",
                 "mhi_device_get_sync_atomic",uVar4,uVar5);
        if ((lVar9 != 0) && (*(uint *)(lVar9 + 0x18) < 3)) {
          uVar8 = *(undefined8 *)(lVar9 + 0x20);
          uVar4 = mhi_state_str(*(undefined4 *)(lVar6 + 400));
          uVar5 = to_mhi_pm_state_str(*(undefined4 *)(lVar6 + 0x184));
          ipc_log_string(uVar8,"[E][%s] Did not enter M0, cur_state: %s pm_state: %s\n",
                         "mhi_device_get_sync_atomic",uVar4,uVar5);
        }
        uVar4 = _raw_read_lock_irqsave(lVar7);
        if (*(int *)(*(code **)(lVar6 + 0x238) + -4) != -0x7620970d) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1109ac);
          (*pcVar2)();
        }
        (**(code **)(lVar6 + 0x238))(lVar6,0);
        _raw_read_unlock_irqrestore(lVar7,uVar4);
        *(int *)(param_1 + 0x3cc) = *(int *)(param_1 + 0x3cc) + -1;
        if (*(int *)(*(code **)(lVar6 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1109e8);
          (*pcVar2)();
        }
        (**(code **)(lVar6 + 600))(lVar6);
        return 0xffffff92;
      }
    }
    if (*(int *)(*(code **)(lVar6 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1108d8);
      (*pcVar2)();
    }
    (**(code **)(lVar6 + 600))(lVar6);
    uVar4 = 0;
  }
  else {
    _raw_read_unlock_irqrestore(lVar7,uVar4);
    uVar4 = 0xfffffffb;
  }
  return uVar4;
}



//------------------------------------------------------------
// mhi_controller_setup_timesync @ 001109f8 size=112
// signature: undefined mhi_controller_setup_timesync(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
mhi_controller_setup_timesync(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  puVar1 = (undefined8 *)kmalloc_trace(_dma_alloc_attrs,0xdc0,0xb0);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = 0;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    *(undefined8 **)(lVar3 + 0x68) = puVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// mhi_init_host_notification @ 00110a6c size=204
// signature: undefined mhi_init_host_notification(void)
// callers: []
//------------------------------------------------------------

int mhi_init_host_notification(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  iVar1 = mhi_get_capability_offset(param_1,6,&local_3c);
  if (iVar1 == 0) {
    *(undefined8 *)(param_1 + 0x38) = param_2;
    local_3c = local_3c + 4;
    mhi_write_reg(param_1,*(undefined8 *)(param_1 + 0x18),local_3c,0x8000007c);
    lVar2 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar2 != 0) && (*(int *)(lVar2 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x20),"[D][%s] Host notification DB setup complete.\n",
                     "mhi_init_host_notification");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// mhi_get_capability_offset @ 00110b38 size=228
// signature: undefined mhi_get_capability_offset(void)
// callers: [mhi_misc_init_mmio, mhi_init_host_notification]
//------------------------------------------------------------

void mhi_get_capability_offset(long param_1,int param_2,uint *param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  uVar3 = mhi_read_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),0x24,0xffffffff,param_3);
  if ((int)uVar3 == 0) {
    uVar1 = *param_3;
    do {
      if (0xfff < uVar1) break;
      uVar3 = mhi_read_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),uVar1,0xff000000,
                                 (long)&local_40 + 4);
      if ((int)uVar3 != 0) goto LAB_00110b84;
      if (local_40._4_4_ == param_2) {
        uVar3 = 0;
        goto LAB_00110b84;
      }
      uVar3 = mhi_read_reg_field(param_1,*(undefined8 *)(param_1 + 0x18),*param_3,0xfff000,&local_40
                                );
      if ((int)uVar3 != 0) goto LAB_00110b84;
      *param_3 = (uint)local_40;
      uVar1 = (uint)local_40;
    } while ((uint)local_40 != 0);
    uVar3 = 0xfffffffa;
  }
LAB_00110b84:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// mhi_misc_init_mmio @ 00110c20 size=908
// signature: undefined mhi_misc_init_mmio(void)
// callers: [mhi_init_mmio]
//------------------------------------------------------------

void mhi_misc_init_mmio(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_40 = 0;
  lVar7 = *(long *)(param_1 + 8);
  iVar2 = mhi_read_reg(param_1,*(undefined8 *)(param_1 + 0x18),0x18,&local_40);
  if (iVar2 != 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar7 + 0x28,"[E][%s] Unable to read CHDBOFF register\n","mhi_misc_init_mmio");
    if ((lVar8 != 0) && (*(uint *)(lVar8 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[E][%s] Unable to read CHDBOFF register\n",
                     "mhi_misc_init_mmio");
    }
    uVar3 = 0xfffffffb;
    goto LAB_00110f2c;
  }
  local_3c = 0;
  lVar7 = *(long *)(param_1 + 0x18);
  uVar10 = (ulong)local_40;
  lVar8 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if (((*(long *)(lVar8 + 0x48) != 0) &&
      (iVar2 = mhi_get_capability_offset(param_1,3,&local_3c), iVar2 == 0)) &&
     (iVar2 = *(int *)(param_1 + 0xc4), iVar2 != 0)) {
    piVar6 = (int *)(*(long *)(param_1 + 0x130) + 0x24);
    do {
      if (*piVar6 == 2) {
        uVar1 = piVar6[-5];
        if (-1 < (int)uVar1) {
          *(ulong *)(lVar8 + 0x40) = lVar7 + uVar10 + 0x3f0;
          local_3c = local_3c + 4;
          mhi_write_reg(param_1,*(undefined8 *)(param_1 + 0x18),local_3c,
                        (uVar1 & 0x1f) << 0x13 | 0xfd000000);
          lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
          if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
            ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                           "[D][%s] Bandwidth scaling setup complete. Event ring:%d\n",
                           "mhi_init_bw_scale",uVar1);
          }
          goto LAB_00110cc4;
        }
        break;
      }
      piVar6 = piVar6 + 0x46;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
    ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[I][%s] BW scale setup failure\n",
                   "mhi_misc_init_mmio");
  }
LAB_00110cc4:
  local_3c = 0;
  lVar8 = *(long *)(param_1 + 0x18);
  uVar10 = (ulong)local_40;
  lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  lVar9 = *(long *)(lVar7 + 0x68);
  if (lVar9 == 0) {
LAB_00110cfc:
    if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
      ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[I][%s] Time synchronization setup failure\n",
                     "mhi_misc_init_mmio");
    }
  }
  else {
    iVar2 = mhi_get_capability_offset(param_1,2,&local_3c);
    if (iVar2 != 0) {
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      goto LAB_00110cfc;
    }
    *(ulong *)(lVar9 + 0x18) = *(long *)(param_1 + 0x18) + (ulong)local_3c;
    __mutex_init(lVar9 + 0x80,"&mhi_tsync->mutex",&mhi_init_timesync___key);
    iVar2 = *(int *)(param_1 + 0xc4);
    if (iVar2 != 0) {
      piVar6 = (int *)(*(long *)(param_1 + 0x130) + 0x24);
      do {
        if (*piVar6 == 3) {
          uVar1 = piVar6[-5];
          if (-1 < (int)uVar1) {
            *(undefined4 *)(lVar9 + 0x68) = 0;
            *(long *)(lVar9 + 0x70) = lVar9 + 0x70;
            *(long *)(lVar9 + 0x78) = lVar9 + 0x70;
            *(ulong *)(lVar9 + 0x20) = lVar8 + uVar10 + 1000;
            mhi_write_reg(param_1,*(undefined8 *)(lVar9 + 0x18),4,uVar1 & 0xff | 0x80007d00);
            lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
              ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                             "[D][%s] Time synchronization DB mode setup complete. Event ring:%d\n",
                             "mhi_init_timesync",uVar1);
            }
          }
          break;
        }
        piVar6 = piVar6 + 0x46;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  lVar7 = *(long *)(param_1 + 0x18);
  uVar10 = (ulong)local_40;
  local_3c = 0;
  iVar2 = mhi_get_capability_offset(param_1,6,&local_3c);
  if (iVar2 == 0) {
    local_3c = local_3c + 4;
    *(ulong *)(param_1 + 0x38) = lVar7 + uVar10 + 0x3e0;
    mhi_write_reg(param_1,*(undefined8 *)(param_1 + 0x18),local_3c,0x8000007c);
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar7 != 0) && (*(int *)(lVar7 + 0x18) == 0)) {
      uVar3 = *(undefined8 *)(lVar7 + 0x20);
      pcVar4 = "[D][%s] Host notification DB setup complete.\n";
      pcVar5 = "mhi_init_host_notification";
      goto LAB_00110f24;
    }
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
      uVar3 = *(undefined8 *)(lVar7 + 0x20);
      pcVar4 = "[I][%s] Host notification doorbell setup failure\n";
      pcVar5 = "mhi_misc_init_mmio";
LAB_00110f24:
      ipc_log_string(uVar3,pcVar4,pcVar5);
    }
  }
  uVar3 = 0;
LAB_00110f2c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// mhi_host_notify_db_disable_trace @ 00110fb0 size=604
// signature: undefined mhi_host_notify_db_disable_trace(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_host_notify_db_disable_trace(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  
  if (*(long *)(param_1 + 0x38) == 0) {
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if (lVar7 == 0) {
      return 0xffffffff;
    }
    if (1 < *(uint *)(lVar7 + 0x18)) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(lVar7 + 0x20);
    pcVar4 = "[I][%s] Host notifiction DB feature NOT supported or enabled\n";
  }
  else {
    lVar7 = param_1 + 0x178;
    uVar3 = _raw_read_lock_irqsave(lVar7);
    if (*(uint *)(param_1 + 0x184) == 1) {
      _raw_read_unlock_irqrestore(lVar7,uVar3);
      return 0xffffffea;
    }
    if (0x7f < *(uint *)(param_1 + 0x184)) {
      _raw_read_unlock_irqrestore(lVar7,uVar3);
      return 0xfffffffb;
    }
    iVar1 = mhi_get_mhi_state(param_1);
    uVar2 = mhi_get_exec_env(param_1);
    lVar6 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar6 != 0) && (*(int *)(lVar6 + 0x18) == 0)) {
      pcVar4 = "RESET";
      switch(iVar1) {
      case 0:
        break;
      case 1:
        pcVar4 = "READY";
        break;
      case 2:
        pcVar4 = "M0";
        break;
      case 3:
        pcVar4 = "M1";
        break;
      case 4:
        pcVar4 = "M2";
        break;
      case 5:
        pcVar4 = "M3";
        break;
      case 6:
        pcVar4 = "M3 FAST";
        break;
      case 7:
        pcVar4 = "BHI";
        break;
      default:
        if (iVar1 == 0xff) {
          pcVar4 = "SYS ERROR";
        }
        else {
          pcVar4 = "Unknown state";
        }
      }
      if (uVar2 < 10) {
        pcVar5 = (&mhi_ee_str)[uVar2];
      }
      else {
        pcVar5 = "INVALID_EE";
      }
      ipc_log_string(*(undefined8 *)(lVar6 + 0x20),"[D][%s] Entered with MHI state: %s, EE: %s\n",
                     "mhi_host_notify_db_disable_trace",pcVar4,pcVar5);
    }
    if ((iVar1 == 2) && (uVar2 == 2)) {
      mhi_write_db(param_1,*(undefined8 *)(param_1 + 0x38),1);
      _raw_read_unlock_irqrestore(lVar7,uVar3);
      lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar7 == 0) || (1 < *(uint *)(lVar7 + 0x18))) {
        return 0;
      }
      ipc_log_string(*(undefined8 *)(lVar7 + 0x20),"[I][%s] Host notification DB write Success\n",
                     "mhi_host_notify_db_disable_trace");
      return 0;
    }
    _raw_read_unlock_irqrestore(lVar7,uVar3);
    lVar7 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if (lVar7 == 0) {
      return 0xffffffff;
    }
    if (1 < *(uint *)(lVar7 + 0x18)) {
      return 0xffffffff;
    }
    uVar3 = *(undefined8 *)(lVar7 + 0x20);
    pcVar4 = "[I][%s] Cannot invoke DB due to invalid M state and/or EE\n";
  }
  ipc_log_string(uVar3,pcVar4,"mhi_host_notify_db_disable_trace");
  return 0xffffffff;
}



//------------------------------------------------------------
// mhi_process_misc_tsync_ev_ring @ 00111210 size=828
// signature: undefined mhi_process_misc_tsync_ev_ring(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_process_misc_tsync_ev_ring(long param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long *plVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  ulong *puVar12;
  undefined8 uVar13;
  long *plVar14;
  long lVar15;
  long lVar16;
  
  lVar16 = *(long *)(param_1 + 8);
  lVar9 = param_2 + 0x100;
  uVar5 = *(uint *)(param_2 + 0x10);
  lVar11 = **(long **)(param_1 + 0x140);
  lVar15 = *(long *)(*(long *)(lVar16 + 0xc0) + 0x68);
  _raw_spin_lock_bh(lVar9);
  uVar10 = *(ulong *)(param_2 + 0x30);
  puVar12 = (ulong *)(lVar11 + (ulong)uVar5 * 0x2c + 0x1c);
  uVar8 = *puVar12;
  if ((uVar8 < uVar10) ||
     (lVar11 = *(long *)(param_2 + 0x68), (uVar8 & 0xf) != 0 || lVar11 + uVar10 <= uVar8)) {
    lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    _dev_err(lVar16 + 0x28,
             "[E][%s] Event ring rp points outside of the event ring or unalign rp %llx\n",
             "mhi_process_misc_tsync_ev_ring");
    if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                     "[E][%s] Event ring rp points outside of the event ring or unalign rp %llx\n",
                     "mhi_process_misc_tsync_ev_ring",*puVar12);
    }
  }
  else {
    uVar3 = *(ulong *)(param_2 + 0x48);
    uVar8 = uVar3 + (uVar8 - uVar10);
    if (*(ulong *)(param_2 + 0x50) != uVar8) {
      uVar1 = uVar3 + lVar11;
      if (uVar8 != uVar3) {
        uVar1 = uVar8;
      }
      uVar8 = uVar1 - 0x20;
      *(ulong *)(param_2 + 0x50) = uVar1 - 0x10;
      if (uVar8 < uVar3) {
        lVar16 = *(long *)(param_2 + 0x60);
        uVar8 = (uVar3 + lVar11) - lVar16;
      }
      else {
        lVar16 = *(long *)(param_2 + 0x60);
      }
      uVar2 = uVar8 + lVar16;
      if (uVar3 + lVar11 <= uVar8 + lVar16) {
        uVar2 = uVar3;
      }
      *(ulong *)(param_2 + 0x58) = uVar2;
      **(long **)(param_2 + 0x38) = (uVar10 - uVar3) + uVar2;
      uVar8 = *(long *)(param_2 + 0x50) + *(long *)(param_2 + 0x60);
      if (*(ulong *)(param_2 + 0x48) + *(long *)(param_2 + 0x68) <= uVar8) {
        uVar8 = *(ulong *)(param_2 + 0x48);
      }
      *(ulong *)(param_2 + 0x50) = uVar8;
      DataMemoryBarrier(2,2);
      if (*(char *)(uVar1 - 2) != 'H') {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x111548);
        (*pcVar7)();
      }
      iVar6 = *(int *)(uVar1 - 8);
      uVar13 = *(undefined8 *)(uVar1 - 0x10);
      lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                       "[D][%s] Received TSYNC event with seq: 0x%llx time: 0x%llx\n",
                       "mhi_process_misc_tsync_ev_ring",iVar6,uVar13);
      }
      _raw_read_lock_bh(param_1 + 0x178);
      if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0) {
        mhi_ring_er_db(param_2);
      }
      _raw_read_unlock_bh(param_1 + 0x178);
      _raw_spin_unlock_bh(lVar9);
      mutex_lock(lVar15 + 0x80);
      if (*(int *)(lVar15 + 0x28) != iVar6) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x1115a0);
        (*pcVar7)();
      }
      lVar9 = lVar15 + 0x68;
      _raw_spin_lock(lVar9);
      plVar14 = *(long **)(lVar15 + 0x70);
      while ((plVar14 != (long *)(lVar15 + 0x70) && (plVar14 != (long *)0x0))) {
        uVar8 = __list_del_entry_valid(plVar14);
        if ((uVar8 & 1) != 0) {
          lVar11 = *plVar14;
          plVar4 = (long *)plVar14[1];
          *(long **)(lVar11 + 8) = plVar4;
          *plVar4 = lVar11;
        }
        *plVar14 = -0x2152ffffffffff00;
        plVar14[1] = -0x2152fffffffffede;
        _raw_spin_unlock(lVar9);
        if (*(int *)((code *)plVar14[5] + -4) != -0x429f1dfe) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x111420);
          (*pcVar7)();
        }
        (*(code *)plVar14[5])(plVar14[4],(int)plVar14[2],*(undefined8 *)(lVar15 + 0x30),uVar13);
        kfree(plVar14);
        _raw_spin_lock(lVar9);
        plVar14 = *(long **)(lVar15 + 0x70);
      }
      _raw_spin_unlock(lVar9);
      *(undefined1 *)(lVar15 + 0x40) = 0;
      *(undefined8 *)(lVar15 + 0x38) = uVar13;
      complete(lVar15 + 0x48);
      if (*(int *)(*(code **)(param_1 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x11147c);
        (*pcVar7)();
      }
      (**(code **)(param_1 + 600))(param_1);
      mhi_device_put(*(undefined8 *)(param_1 + 8));
      mutex_unlock(lVar15 + 0x80);
      goto LAB_001114e8;
    }
  }
  _raw_spin_unlock_bh(lVar9);
LAB_001114e8:
  lVar9 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((lVar9 != 0) && (*(int *)(lVar9 + 0x18) == 0)) {
    ipc_log_string(*(undefined8 *)(lVar9 + 0x20),"[D][%s] exit er_index: %u, ret: %d\n",
                   "mhi_process_misc_tsync_ev_ring",*(undefined4 *)(param_2 + 0x10),0);
  }
  return 0;
}



//------------------------------------------------------------
// mhi_process_misc_bw_ev_ring @ 00111638 size=1048
// signature: undefined mhi_process_misc_bw_ev_ring(void)
// callers: []
//------------------------------------------------------------

int mhi_process_misc_bw_ev_ring(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  long lVar11;
  ulong *puVar12;
  long lVar13;
  uint uVar14;
  ulong local_68;
  uint local_60;
  long local_58;
  
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  iVar5 = -0x16;
  uVar14 = *(uint *)(param_2 + 0x10);
  lVar11 = **(long **)(param_1 + 0x140);
  local_60 = 0;
  local_68 = 0;
  if ((*(uint *)(param_1 + 0x18c) < 8) &&
     ((1 << (ulong)(*(uint *)(param_1 + 0x18c) & 0x1f) & 0x94U) != 0)) {
    lVar10 = *(long *)(param_1 + 8);
    lVar8 = param_2 + 0x100;
    lVar13 = *(long *)(lVar10 + 0xc0);
    _raw_spin_lock_bh(lVar8);
    uVar7 = *(ulong *)(param_2 + 0x30);
    puVar12 = (ulong *)(lVar11 + (ulong)uVar14 * 0x2c + 0x1c);
    uVar6 = *puVar12;
    if ((uVar6 < uVar7) ||
       (((uVar6 & 0xf) != 0 || (lVar11 = *(long *)(param_2 + 0x68), lVar11 + uVar7 <= uVar6)))) {
      lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      _dev_err(lVar10 + 0x28,
               "[E][%s] Event ring rp points outside of the event ring or unalign rp %llx\n",
               "mhi_process_misc_bw_ev_ring");
      if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
        ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                       "[E][%s] Event ring rp points outside of the event ring or unalign rp %llx\n"
                       ,"mhi_process_misc_bw_ev_ring",*puVar12);
      }
    }
    else {
      puVar3 = *(undefined8 **)(param_2 + 0x48);
      puVar9 = (undefined8 *)((long)puVar3 + (uVar6 - uVar7));
      if (*(undefined8 **)(param_2 + 0x50) != puVar9) {
        puVar1 = (undefined8 *)((long)puVar3 + lVar11);
        if (puVar9 != puVar3) {
          puVar1 = puVar9;
        }
        puVar9 = puVar1 + -4;
        *(undefined8 **)(param_2 + 0x50) = puVar1 + -2;
        if (puVar9 < puVar3) {
          lVar10 = *(long *)(param_2 + 0x60);
          puVar9 = (undefined8 *)(((long)puVar3 + lVar11) - lVar10);
        }
        else {
          lVar10 = *(long *)(param_2 + 0x60);
        }
        puVar2 = (undefined8 *)((long)puVar9 + lVar10);
        if ((undefined8 *)((long)puVar3 + lVar11) <= (undefined8 *)((long)puVar9 + lVar10)) {
          puVar2 = puVar3;
        }
        *(undefined8 **)(param_2 + 0x58) = puVar2;
        **(long **)(param_2 + 0x38) = (uVar7 - (long)puVar3) + (long)puVar2;
        uVar6 = *(long *)(param_2 + 0x50) + *(long *)(param_2 + 0x60);
        if (*(ulong *)(param_2 + 0x48) + *(long *)(param_2 + 0x68) <= uVar6) {
          uVar6 = *(ulong *)(param_2 + 0x48);
        }
        *(ulong *)(param_2 + 0x50) = uVar6;
        DataMemoryBarrier(2,2);
        if ((*(uint *)((long)puVar1 - 4) & 0xff0000) != 0x500000) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x111a18);
          (*pcVar4)();
        }
        lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
        local_68 = (ulong)CONCAT14(*(undefined1 *)(puVar1 + -1),*(uint *)((long)puVar1 - 4) >> 0x18)
        ;
        local_60 = (uint)*(byte *)((long)puVar1 - 7);
        if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
          ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                         "[D][%s] Received BW_REQ with seq:%d link speed:0x%x width:0x%x\n",
                         "mhi_process_misc_bw_ev_ring");
        }
        lVar11 = param_1 + 0x178;
        _raw_read_lock_bh(lVar11);
        if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) != 0) {
          mhi_ring_er_db(param_2);
        }
        _raw_read_unlock_bh(lVar11);
        _raw_spin_unlock_bh(lVar8);
        iVar5 = mhi_device_get_sync(*(undefined8 *)(param_1 + 8));
        if (iVar5 == 0) {
          if (*(int *)(*(code **)(param_1 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x111860);
            (*pcVar4)();
          }
          (**(code **)(param_1 + 0x248))(param_1);
          mutex_lock(param_1 + 0x148);
          if (*(int *)(*(code **)(lVar13 + 0x48) + -4) != 0x282773ab) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x111894);
            (*pcVar4)();
          }
          iVar5 = (**(code **)(lVar13 + 0x48))(param_1,&local_68);
          if (iVar5 == -0x16) {
            uVar14 = 0x100;
          }
          else if (iVar5 == 0) {
            uVar14 = 0;
            *(ulong *)(param_1 + 0x1c8) = local_68;
            *(uint *)(param_1 + 0x1d0) = local_60;
          }
          else {
            uVar14 = 0xf00;
          }
          _raw_write_lock_bh(lVar11);
          uVar14 = local_60 & 0xff | uVar14;
          *(uint *)(lVar13 + 0x5c) = uVar14;
          if ((*(uint *)(param_1 + 0x188) & *(uint *)(param_1 + 0x184)) == 0) {
            lVar8 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
            if ((lVar8 != 0) && (*(int *)(lVar8 + 0x18) == 0)) {
              ipc_log_string(*(undefined8 *)(lVar8 + 0x20),
                             "[D][%s] Cached BW response for seq: %u, result: %d\n",
                             "mhi_process_misc_bw_ev_ring",local_60,*(undefined4 *)(lVar8 + 0x5c));
            }
          }
          else {
            mhi_write_reg(param_1,*(undefined8 *)(lVar13 + 0x40),0,uVar14);
            *(undefined4 *)(lVar13 + 0x5c) = 0;
          }
          _raw_write_unlock_bh(lVar11);
          if (*(int *)(*(code **)(param_1 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x111994);
            (*pcVar4)();
          }
          (**(code **)(param_1 + 600))(param_1);
          mhi_device_put(*(undefined8 *)(param_1 + 8));
          mutex_unlock(param_1 + 0x148);
        }
        goto LAB_001119a8;
      }
      lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
      if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                       "[D][%s] Ignore BW event:0x%llx ev_ring RP:0x%llx\n",
                       "mhi_process_misc_bw_ev_ring",*puVar9,(uVar7 - (long)puVar3) + (long)puVar9);
      }
    }
    _raw_spin_unlock_bh(lVar8);
    iVar5 = 0;
  }
  else {
LAB_001119a8:
    lVar11 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar11 != 0) && (*(int *)(lVar11 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar11 + 0x20),"[D][%s] exit er_index:%u ret:%d\n",
                     "mhi_process_misc_bw_ev_ring",*(undefined4 *)(param_2 + 0x10),iVar5);
    }
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// mhi_misc_dbs_pending @ 00111aac size=124
// signature: undefined mhi_misc_dbs_pending(void)
// callers: [mhi_pm_m0_transition]
//------------------------------------------------------------

void mhi_misc_dbs_pending(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((*(long *)(lVar2 + 0x48) != 0) && (*(int *)(lVar2 + 0x5c) != 0)) {
    mhi_write_reg(param_1,*(undefined8 *)(lVar2 + 0x40),0);
    lVar1 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
    if ((lVar1 != 0) && (*(int *)(lVar1 + 0x18) == 0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x20),"[D][%s] Completed BW response: %d\n",
                     "mhi_misc_dbs_pending",*(undefined4 *)(lVar1 + 0x5c));
    }
    *(undefined4 *)(lVar2 + 0x5c) = 0;
  }
  return;
}



//------------------------------------------------------------
// mhi_controller_set_bw_scale_cb @ 00111b2c size=16
// signature: undefined mhi_controller_set_bw_scale_cb(void)
// callers: []
//------------------------------------------------------------

void mhi_controller_set_bw_scale_cb(long param_1,undefined8 param_2)

{
  *(undefined8 *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x48) = param_2;
  return;
}



//------------------------------------------------------------
// mhi_controller_set_base @ 00111b40 size=16
// signature: undefined mhi_controller_set_base(void)
// callers: []
//------------------------------------------------------------

void mhi_controller_set_base(long param_1,undefined8 param_2)

{
  *(undefined8 *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x50) = param_2;
  return;
}



//------------------------------------------------------------
// mhi_controller_get_base @ 00111b54 size=36
// signature: undefined mhi_controller_get_base(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_controller_get_base(long param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x50);
  if (lVar1 == 0) {
    return 0xffffffea;
  }
  *param_2 = lVar1;
  return 0;
}



//------------------------------------------------------------
// mhi_controller_get_numeric_id @ 00111b7c size=16
// signature: undefined mhi_controller_get_numeric_id(void)
// callers: []
//------------------------------------------------------------

undefined4 mhi_controller_get_numeric_id(long param_1)

{
  return *(undefined4 *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x58);
}



//------------------------------------------------------------
// mhi_get_channel_db_base @ 00111b90 size=156
// signature: undefined mhi_get_channel_db_base(void)
// callers: []
//------------------------------------------------------------

void mhi_get_channel_db_base(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = *(long *)(param_1 + 0x10);
  local_2c = 0;
  lVar3 = *(long *)(*(long *)(lVar1 + 8) + 0xc0);
  if (((*(ushort *)(lVar1 + 0x184) & 0xfde) == 0) ||
     (uVar2 = mhi_read_reg(lVar1,*(undefined8 *)(lVar1 + 0x18),0x18,&local_2c), (int)uVar2 != 0)) {
    uVar2 = 0xfffffffb;
  }
  else {
    *param_2 = *(long *)(lVar3 + 0x50) + (ulong)local_2c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// mhi_get_event_ring_db_base @ 00111c30 size=156
// signature: undefined mhi_get_event_ring_db_base(void)
// callers: []
//------------------------------------------------------------

void mhi_get_event_ring_db_base(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = *(long *)(param_1 + 0x10);
  local_2c = 0;
  lVar3 = *(long *)(*(long *)(lVar1 + 8) + 0xc0);
  if (((*(ushort *)(lVar1 + 0x184) & 0xfde) == 0) ||
     (uVar2 = mhi_read_reg(lVar1,*(undefined8 *)(lVar1 + 0x18),0x20,&local_2c), (int)uVar2 != 0)) {
    uVar2 = 0xfffffffb;
  }
  else {
    *param_2 = *(long *)(lVar3 + 0x50) + (ulong)local_2c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// mhi_get_device_for_channel @ 00111cd0 size=40
// signature: undefined mhi_get_device_for_channel(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_get_device_for_channel(long param_1,uint param_2)

{
  if (param_2 < *(uint *)(param_1 + 0xc0)) {
    return *(undefined8 *)(*(long *)(param_1 + 0xa0) + (ulong)param_2 * 400 + 0x110);
  }
  return 0;
}



//------------------------------------------------------------
// mhi_controller_set_loglevel @ 00111cfc size=16
// signature: undefined mhi_controller_set_loglevel(void)
// callers: []
//------------------------------------------------------------

void mhi_controller_set_loglevel(long param_1,undefined4 param_2)

{
  *(undefined4 *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x18) = param_2;
  return;
}



//------------------------------------------------------------
// mhi_device_ioctl @ 00111d10 size=8
// signature: undefined mhi_device_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_device_ioctl(void)

{
  return 0xfffffffffffffffb;
}



//------------------------------------------------------------
// mhi_controller_set_sfr_support @ 00111d1c size=120
// signature: undefined mhi_controller_set_sfr_support(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_controller_set_sfr_support(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  lVar1 = kmalloc_trace(___init_waitqueue_head,0xdc0,0x48);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x10) = param_2;
    lVar2 = __kmalloc(param_2,0xdc0);
    *(long *)(lVar1 + 0x18) = lVar2;
    if (lVar2 != 0) {
      *(long *)(lVar3 + 0x60) = lVar1;
      return 0;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// mhi_misc_mission_mode @ 00111d98 size=544
// signature: undefined mhi_misc_mission_mode(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

void mhi_misc_mission_mode(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  long *plVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = param_1[1];
  local_48 = 0;
  uStack_40 = 0;
  plVar6 = *(long **)(*(long *)(lVar5 + 0xc0) + 0x60);
  iVar1 = mhi_get_remote_time_sync(lVar5,&uStack_40,&local_48);
  if (((iVar1 == 0) && (lVar2 = *(long *)(param_1[1] + 0xc0), lVar2 != 0)) &&
     (*(uint *)(lVar2 + 0x18) < 2)) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x20),"[I][%s] Timesync: local: %llx, remote: %llx\n",
                   "mhi_misc_mission_mode",uStack_40,local_48);
  }
  if (0x13 < *(uint *)(param_1 + 0x18)) {
    if (*(long *)(param_1[0x14] + 0x1ec0) != 0) {
      mhi_notify(*(long *)(param_1[0x14] + 0x1ec0),0xb);
    }
  }
  if (plVar6 == (long *)0x0) goto LAB_00111e8c;
  memset((void *)plVar6[3],0,plVar6[2]);
  lVar2 = dma_alloc_attrs(*param_1,plVar6[2],plVar6 + 1,0xcc0,0);
  *plVar6 = lVar2;
  if (lVar2 == 0) {
    lVar2 = *(long *)(param_1[1] + 0xc0);
    _dev_err(lVar5 + 0x28,"[E][%s] Failed to allocate memory for sfr\n","mhi_misc_mission_mode");
    if ((lVar2 == 0) || (2 < *(uint *)(lVar2 + 0x18))) goto LAB_00111e8c;
    pcVar4 = "[E][%s] Failed to allocate memory for sfr\n";
  }
  else {
    *(undefined4 *)(plVar6 + 5) = 0;
    __init_swait_queue_head(plVar6 + 6,"&x->wait",&init_completion___key);
    iVar1 = mhi_send_cmd(param_1,0,0x49);
    if (iVar1 == 0) {
      uVar3 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x30));
      iVar1 = wait_for_completion_timeout(plVar6 + 5,uVar3);
      if ((iVar1 != 0) && ((int)plVar6[4] == 1)) goto LAB_00111e8c;
      lVar2 = *(long *)(param_1[1] + 0xc0);
      _dev_err(lVar5 + 0x28,"[E][%s] Failed to get sfr cfg cmd completion\n","mhi_misc_mission_mode"
              );
      if ((lVar2 == 0) || (2 < *(uint *)(lVar2 + 0x18))) goto LAB_00111e8c;
      pcVar4 = "[E][%s] Failed to get sfr cfg cmd completion\n";
    }
    else {
      lVar2 = *(long *)(param_1[1] + 0xc0);
      _dev_err(lVar5 + 0x28,"[E][%s] Failed to send sfr cfg cmd\n","mhi_misc_mission_mode");
      if ((lVar2 == 0) || (2 < *(uint *)(lVar2 + 0x18))) goto LAB_00111e8c;
      pcVar4 = "[E][%s] Failed to send sfr cfg cmd\n";
    }
  }
  ipc_log_string(*(undefined8 *)(lVar2 + 0x20),pcVar4,"mhi_misc_mission_mode");
LAB_00111e8c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_get_remote_time_sync @ 00111fbc size=1048
// signature: undefined mhi_get_remote_time_sync(void)
// callers: [time_show, mhi_misc_mission_mode]
//------------------------------------------------------------

int mhi_get_remote_time_sync(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long lVar10;
  long lVar11;
  undefined4 local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x10);
  local_70 = 0xffffffff;
  uStack_6c = 0xffffffff;
  lVar10 = *(long *)(lVar6 + 8);
  lVar7 = *(long *)(lVar10 + 0xc0);
  puVar9 = *(undefined8 **)(lVar7 + 0x68);
  if (puVar9 == (undefined8 *)0x0) {
    iVar4 = -0x16;
  }
  else if (*(uint *)(lVar6 + 0x184) < 0x80) {
    puVar1 = puVar9 + 0x10;
    mutex_lock(puVar1);
    if (*(char *)(puVar9 + 8) == '\0') {
      iVar4 = mhi_device_get_sync(*(undefined8 *)(lVar6 + 8));
      if (iVar4 == 0) {
        if (*(int *)(*(code **)(lVar6 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1120b4);
          (*pcVar3)();
        }
        (**(code **)(lVar6 + 0x248))(lVar6);
        if (*(int *)((code *)puVar9[1] + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1120d8);
          (*pcVar3)();
        }
        iVar4 = (*(code *)puVar9[1])(lVar6);
        if (iVar4 == 0) {
          lVar7 = sp_el0;
          *(int *)(lVar7 + 0x10) = *(int *)(lVar7 + 0x10) + 1;
          uVar2 = daif;
          daif = uVar2 | 0xc0;
          iVar4 = mhi_read_reg(0x60,lVar6,puVar9[3],0xc,&local_70);
          if (iVar4 != 0) {
            lVar11 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
            _dev_err(lVar10 + 0x28,"[E][%s] Time HIGH register read error\n",
                     "mhi_get_remote_time_sync");
            if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                             "[E][%s] Time HIGH register read error\n","mhi_get_remote_time_sync");
            }
          }
          iVar4 = mhi_read_reg(lVar6,puVar9[3],8,&uStack_6c);
          if (iVar4 != 0) {
            lVar11 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
            _dev_err(lVar10 + 0x28,"[E][%s] Time LOW register read error\n",
                     "mhi_get_remote_time_sync");
            if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar11 + 0x20),"[E][%s] Time LOW register read error\n"
                             ,"mhi_get_remote_time_sync");
            }
          }
          iVar4 = mhi_read_reg(lVar6,puVar9[3],0xc,&local_70);
          if (iVar4 != 0) {
            lVar11 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
            _dev_err(lVar10 + 0x28,"[E][%s] Time HIGH register read error\n",
                     "mhi_get_remote_time_sync");
            if ((lVar11 != 0) && (*(uint *)(lVar11 + 0x18) < 3)) {
              ipc_log_string(*(undefined8 *)(lVar11 + 0x20),
                             "[E][%s] Time HIGH register read error\n","mhi_get_remote_time_sync");
            }
          }
          *param_3 = CONCAT44(local_70,uStack_6c);
          if (*(int *)((code *)*puVar9 + -4) != -0x1d74bf7b) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x112178);
            (*pcVar3)();
          }
          uVar5 = (*(code *)*puVar9)(lVar6);
          *param_2 = uVar5;
          uVar2 = daif;
          daif = uVar2 & 0xffffffffffffff3f;
          lVar10 = *(long *)(lVar7 + 0x10) + -1;
          *(int *)(lVar7 + 0x10) = (int)lVar10;
          if ((lVar10 == 0) || (*(long *)(lVar7 + 0x10) == 0)) {
            preempt_schedule();
          }
          if (*(int *)((code *)puVar9[2] + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1121c0);
            (*pcVar3)();
          }
          (*(code *)puVar9[2])(lVar6);
        }
        if (*(int *)(*(code **)(lVar6 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1121e4);
          (*pcVar3)();
        }
        (**(code **)(lVar6 + 600))(lVar6);
        mhi_device_put(*(undefined8 *)(lVar6 + 8));
      }
      mutex_unlock(puVar1);
    }
    else {
      uVar8 = puVar9[6];
      mutex_unlock(puVar1);
      uVar5 = __msecs_to_jiffies(*(undefined4 *)(lVar6 + 0x180));
      iVar4 = wait_for_completion_timeout(puVar9 + 9,uVar5);
      if ((*(uint *)(lVar6 + 0x184) < 0x80) && (iVar4 != 0)) {
        *param_2 = uVar8;
        iVar4 = 0;
        *param_3 = puVar9[7];
      }
      else {
        lVar6 = *(long *)(*(long *)(lVar6 + 8) + 0xc0);
        _dev_err(lVar10 + 0x28,"[E][%s] Pending DB request did not complete, abort\n",
                 "mhi_get_remote_time_sync");
        if ((lVar6 != 0) && (*(uint *)(lVar6 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar6 + 0x20),
                         "[E][%s] Pending DB request did not complete, abort\n",
                         "mhi_get_remote_time_sync");
        }
        iVar4 = -0xb;
      }
    }
  }
  else {
    uVar5 = to_mhi_pm_state_str();
    _dev_err(lVar10 + 0x28,"[E][%s] MHI is not in active state, pm_state:%s\n",
             "mhi_get_remote_time_sync",uVar5);
    if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
      uVar8 = *(undefined8 *)(lVar7 + 0x20);
      uVar5 = to_mhi_pm_state_str(*(undefined4 *)(lVar6 + 0x184));
      ipc_log_string(uVar8,"[E][%s] MHI is not in active state, pm_state:%s\n",
                     "mhi_get_remote_time_sync",uVar5);
    }
    iVar4 = -5;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// mhi_misc_disable @ 001123e0 size=76
// signature: undefined mhi_misc_disable(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

void mhi_misc_disable(undefined8 *param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(*(long *)(param_1[1] + 0xc0) + 0x60);
  if ((plVar1 != (long *)0x0) && (*plVar1 != 0)) {
    dma_free_attrs(*param_1,plVar1[2],*plVar1,plVar1[1],0);
    *plVar1 = 0;
  }
  return;
}



//------------------------------------------------------------
// mhi_misc_cmd_configure @ 00112430 size=56
// signature: undefined mhi_misc_cmd_configure(void)
// callers: [mhi_send_cmd]
//------------------------------------------------------------

void mhi_misc_cmd_configure
               (long param_1,int param_2,undefined8 *param_3,int *param_4,undefined4 *param_5)

{
  long lVar1;
  
  if ((param_2 == 0x49) &&
     (lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x60), lVar1 != 0)) {
    *param_3 = *(undefined8 *)(lVar1 + 8);
    *param_4 = *(int *)(lVar1 + 0x10) + -1;
    *param_5 = 0x490000;
  }
  return;
}



//------------------------------------------------------------
// mhi_misc_cmd_completion @ 0011246c size=60
// signature: undefined mhi_misc_cmd_completion(void)
// callers: [mhi_process_ctrl_ev_ring]
//------------------------------------------------------------

void mhi_misc_cmd_completion(long param_1,int param_2,undefined4 param_3)

{
  long lVar1;
  
  if ((param_2 == 0x49) &&
     (lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 8) + 0xc0) + 0x60), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    complete(lVar1 + 0x28);
  }
  return;
}



//------------------------------------------------------------
// mhi_get_remote_time @ 001124ac size=1024
// signature: undefined mhi_get_remote_time(void)
// callers: [time_async_show]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int mhi_get_remote_time(long param_1,undefined4 param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  long lVar12;
  
  lVar8 = *(long *)(param_1 + 0x10);
  lVar12 = *(long *)(lVar8 + 8);
  puVar11 = *(undefined8 **)(*(long *)(lVar12 + 0xc0) + 0x68);
  if ((puVar11 == (undefined8 *)0x0) || (puVar11[4] == 0)) {
    return -0x16;
  }
  mutex_lock(puVar11 + 0x10);
  iVar2 = mhi_device_get_sync(*(undefined8 *)(lVar8 + 8));
  if (iVar2 != 0) goto LAB_00112818;
  if (*(int *)(*(code **)(lVar8 + 0x248) + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x112530);
    (*pcVar1)();
  }
  (**(code **)(lVar8 + 0x248))(lVar8);
  lVar7 = *(long *)(*(long *)(lVar8 + 8) + 0xc0);
  if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 2)) {
    uVar9 = *(undefined8 *)(lVar7 + 0x20);
    uVar3 = to_mhi_pm_state_str(*(undefined4 *)(lVar8 + 0x184));
    pcVar6 = "RESET";
    switch(*(int *)(lVar8 + 400)) {
    case 0:
      break;
    case 1:
      pcVar6 = "READY";
      break;
    case 2:
      pcVar6 = "M0";
      break;
    case 3:
      pcVar6 = "M1";
      break;
    case 4:
      pcVar6 = "M2";
      break;
    case 5:
      pcVar6 = "M3";
      break;
    case 6:
      pcVar6 = "M3 FAST";
      break;
    case 7:
      pcVar6 = "BHI";
      break;
    default:
      if (*(int *)(lVar8 + 400) == 0xff) {
        pcVar6 = "SYS ERROR";
      }
      else {
        pcVar6 = "Unknown state";
      }
    }
    ipc_log_string(uVar9,"[I][%s] Enter with pm_state:%s MHI_STATE:%s\n","mhi_get_remote_time",uVar3
                   ,pcVar6);
  }
  plVar4 = (long *)kmalloc_trace(___mutex_init,0xb20,0x30);
  if (plVar4 == (long *)0x0) {
    iVar2 = -0xc;
LAB_00112678:
    if (*(int *)(*(code **)(lVar8 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x112698);
      (*pcVar1)();
    }
    (**(code **)(lVar8 + 600))(lVar8);
    mhi_device_put(*(undefined8 *)(lVar8 + 8));
  }
  else {
    *(undefined4 *)(plVar4 + 2) = param_2;
    plVar4[4] = param_1;
    plVar4[5] = param_3;
    if (*(char *)(puVar11 + 8) == '\0') {
      iVar2 = 0;
      if (*(int *)(puVar11 + 5) != -2) {
        iVar2 = *(int *)(puVar11 + 5) + 1;
      }
      *(int *)(puVar11 + 5) = iVar2;
      if (*(int *)((code *)puVar11[1] + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x1126dc);
        (*pcVar1)();
      }
      iVar2 = (*(code *)puVar11[1])(lVar8);
      if (iVar2 != 0) {
        lVar7 = *(long *)(*(long *)(lVar8 + 8) + 0xc0);
        _dev_err(lVar12 + 0x28,"[E][%s] LPM disable request failed for %s!\n","mhi_get_remote_time",
                 *(undefined8 *)(param_1 + 8));
        if ((lVar7 != 0) && (*(uint *)(lVar7 + 0x18) < 3)) {
          ipc_log_string(*(undefined8 *)(lVar7 + 0x20),
                         "[E][%s] LPM disable request failed for %s!\n","mhi_get_remote_time",
                         *(undefined8 *)(param_1 + 8));
        }
        kfree(plVar4);
        goto LAB_00112678;
      }
      lVar12 = sp_el0;
      *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
      uVar5 = daif;
      daif = uVar5 | 0xc0;
      if (*(int *)((code *)*puVar11 + -4) != -0x1d74bf7b) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x112720);
        (*pcVar1)();
      }
      uVar3 = (*(code *)*puVar11)(lVar8);
      puVar11[6] = uVar3;
      mhi_write_reg(lVar8,puVar11[4],0,*(undefined4 *)(puVar11 + 5));
      DataSynchronizationBarrier(3,2,0);
      uVar5 = daif;
      daif = uVar5 & 0xffffffffffffff3f;
      lVar7 = *(long *)(lVar12 + 0x10) + -1;
      *(int *)(lVar12 + 0x10) = (int)lVar7;
      if ((lVar7 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
        preempt_schedule();
      }
      if (*(int *)((code *)puVar11[2] + -4) != 0x519895a6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x112780);
        (*pcVar1)();
      }
      (*(code *)puVar11[2])(lVar8);
      lVar8 = *(long *)(*(long *)(lVar8 + 8) + 0xc0);
      if ((lVar8 != 0) && (*(int *)(lVar8 + 0x18) == 0)) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x20),"[D][%s] time DB request with seq:0x%llx\n",
                       "mhi_get_remote_time",*(undefined4 *)(puVar11 + 5));
      }
      *(undefined1 *)(puVar11 + 8) = 1;
      *(undefined4 *)(puVar11 + 9) = 0;
      __init_swait_queue_head(puVar11 + 10,"&x->wait",&init_completion___key);
    }
    else {
      if (*(int *)(*(code **)(lVar8 + 600) + -4) != -0x47fc709a) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x112664);
        (*pcVar1)();
      }
      (**(code **)(lVar8 + 600))(lVar8);
      mhi_device_put(*(undefined8 *)(lVar8 + 8));
    }
    _raw_spin_lock(puVar11 + 0xd);
    puVar10 = (undefined8 *)puVar11[0xf];
    uVar5 = __list_add_valid(plVar4,puVar10,puVar11 + 0xe);
    if ((uVar5 & 1) != 0) {
      puVar11[0xf] = plVar4;
      *plVar4 = (long)(puVar11 + 0xe);
      plVar4[1] = (long)puVar10;
      *puVar10 = plVar4;
    }
    _raw_spin_unlock(puVar11 + 0xd);
    iVar2 = 0;
  }
LAB_00112818:
  mutex_unlock(puVar11 + 0x10);
  return iVar2;
}



//------------------------------------------------------------
// mhi_force_reset @ 001128b8 size=312
// signature: undefined mhi_force_reset(void)
// callers: []
//------------------------------------------------------------

void mhi_force_reset(long param_1)

{
  undefined8 uVar1;
  char *pcVar2;
  char *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = *(long *)(*(long *)(param_1 + 8) + 0xc0);
  if ((lVar4 != 0) && (*(int *)(lVar4 + 0x18) == 0)) {
    uVar5 = *(undefined8 *)(lVar4 + 0x20);
    uVar1 = to_mhi_pm_state_str(*(undefined4 *)(param_1 + 0x184));
    pcVar2 = "RESET";
    switch(*(int *)(param_1 + 400)) {
    case 0:
      break;
    case 1:
      pcVar2 = "READY";
      break;
    case 2:
      pcVar2 = "M0";
      break;
    case 3:
      pcVar2 = "M1";
      break;
    case 4:
      pcVar2 = "M2";
      break;
    case 5:
      pcVar2 = "M3";
      break;
    case 6:
      pcVar2 = "M3 FAST";
      break;
    case 7:
      pcVar2 = "BHI";
      break;
    default:
      if (*(int *)(param_1 + 400) == 0xff) {
        pcVar2 = "SYS ERROR";
      }
      else {
        pcVar2 = "Unknown state";
      }
    }
    if (*(uint *)(param_1 + 0x18c) < 10) {
      pcVar3 = (&mhi_ee_str)[*(uint *)(param_1 + 0x18c)];
    }
    else {
      pcVar3 = "INVALID_EE";
    }
    ipc_log_string(uVar5,"[D][%s] Entered with pm_state:%s dev_state:%s ee:%s\n","mhi_force_reset",
                   uVar1,pcVar2,pcVar3);
  }
  mhi_report_error(param_1);
  mhi_soc_reset(param_1);
  mhi_rddm_download_status(param_1);
  return;
}



//------------------------------------------------------------
// mhi_get_soc_info @ 001129f4 size=132
// signature: undefined mhi_get_soc_info(void)
// callers: []
//------------------------------------------------------------

void mhi_get_soc_info(long param_1)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = mhi_read_reg((int)param_1,*(undefined8 *)(param_1 + 0x18),0x224,&local_2c);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0xd4) = local_2c >> 0x1c;
    *(uint *)(param_1 + 0xd8) = local_2c >> 0x10 & 0xfff;
    *(uint *)(param_1 + 0xdc) = local_2c >> 8 & 0xff;
    *(uint *)(param_1 + 0xe0) = local_2c & 0xff;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// log_level_show @ 00112a7c size=112
// signature: undefined log_level_show(void)
// callers: []
//------------------------------------------------------------

long log_level_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + -0x18) + 8) + 0xc0);
  if (lVar4 == 0) {
    lVar4 = -5;
  }
  else {
    uVar1 = *(uint *)(lVar4 + 0x18);
    if (uVar1 < 5) {
      pcVar3 = (&mhi_log_level_str)[uVar1];
    }
    else {
      pcVar3 = "Mask all";
    }
    iVar2 = scnprintf(param_3,0x1000,"IPC log level begins from: %s\n",pcVar3);
    lVar4 = (long)iVar2;
  }
  return lVar4;
}



//------------------------------------------------------------
// log_level_store @ 00112af0 size=240
// signature: undefined log_level_store(void)
// callers: []
//------------------------------------------------------------

undefined8 log_level_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + -0x18);
  local_3c = 0;
  lVar4 = *(long *)(*(long *)(lVar3 + 8) + 0xc0);
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = 0xffffffffffffffea;
  }
  else if (lVar4 == 0) {
    param_4 = 0xfffffffffffffffb;
  }
  else {
    *(uint *)(lVar4 + 0x18) = local_3c;
    lVar3 = *(long *)(*(long *)(lVar3 + 8) + 0xc0);
    if ((lVar3 != 0) && (*(uint *)(lVar3 + 0x18) < 2)) {
      if (local_3c < 5) {
        pcVar2 = (&mhi_log_level_str)[local_3c];
      }
      else {
        pcVar2 = "Mask all";
      }
      ipc_log_string(*(undefined8 *)(lVar3 + 0x20),"[I][%s] IPC log level changed to: %s\n",
                     "log_level_store",pcVar2);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// time_show @ 00112be4 size=256
// signature: undefined time_show(void)
// callers: []
//------------------------------------------------------------

long time_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + -0x18);
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = mhi_get_remote_time_sync(param_1 + -0x28,&uStack_40,&local_48);
  if (iVar1 == 0) {
    iVar1 = scnprintf(param_3,0x1000,"local: %llu remote: %llu (ticks)\n",uStack_40,local_48);
  }
  else {
    lVar2 = *(long *)(*(long *)(lVar2 + 8) + 0xc0);
    _dev_err(param_1,"[E][%s] Failed to obtain time, ret:%d\n","time_show",iVar1);
    if ((lVar2 != 0) && (*(uint *)(lVar2 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x20),"[E][%s] Failed to obtain time, ret:%d\n",
                     "time_show",iVar1);
    }
    iVar1 = scnprintf(param_3,0x1000,"Request failed or feature unsupported\n");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// time_async_show @ 00112ce8 size=244
// signature: undefined time_async_show(void)
// callers: []
//------------------------------------------------------------

long time_async_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + -0x18);
  iVar1 = get_random_u32();
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  iVar2 = mhi_get_remote_time(param_1 + -0x28,iVar1,mhi_time_async_cb);
  if (iVar2 == 0) {
    iVar1 = scnprintf(param_3,0x1000,"Requested time asynchronously with seq:%llx\n",iVar1);
  }
  else {
    lVar3 = *(long *)(*(long *)(lVar3 + 8) + 0xc0);
    _dev_err(param_1,"[E][%s] Failed to request time, seq:%llx, ret:%d\n","time_async_show",iVar1,
             iVar2);
    if ((lVar3 != 0) && (*(uint *)(lVar3 + 0x18) < 3)) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x20),
                     "[E][%s] Failed to request time, seq:%llx, ret:%d\n","time_async_show",iVar1,
                     iVar2);
    }
    iVar1 = scnprintf(param_3,0x1000,"Request failed or feature unsupported\n");
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// mhi_time_async_cb @ 00112de0 size=88
// signature: undefined mhi_time_async_cb(void)
// callers: []
//------------------------------------------------------------

void mhi_time_async_cb(long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + 0xc0);
  if ((lVar1 != 0) && (*(uint *)(lVar1 + 0x18) < 2)) {
    ipc_log_string(*(undefined8 *)(lVar1 + 0x20),
                   "[I][%s] Time response: seq:%llx local: %llu remote: %llu (ticks)\n",
                   "mhi_time_async_cb",param_2,param_3,param_4);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0011337c size=40
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  mhi_misc_init();
  bus_register(&mhi_bus_type);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001133a8 size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  mhi_misc_exit();
  bus_unregister(&mhi_bus_type);
  return;
}



//------------------------------------------------------------
// free_irq @ 00119000 size=1
// signature: undefined free_irq(void)
// callers: [mhi_init_irq_setup, mhi_unregister_controller, mhi_deinit_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00119008 size=1
// signature: undefined request_threaded_irq(void)
// callers: [mhi_init_irq_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00119010 size=1
// signature: undefined disable_irq(void)
// callers: [mhi_pm_st_worker, mhi_power_down, mhi_init_irq_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00119018 size=1
// signature: undefined _dev_err(void)
// callers: [mhi_ready_state_transition, mhi_unprepare_channel, mhi_update_channel_state, mhi_prepare_channel, mhi_force_rddm_mode, mhi_pm_fast_resume, mhi_pm_fast_suspend, mhi_fw_load_handler, mhi_send_cmd, parse_config, mhi_pm_m3_transition, mhi_debug_reg_dump, mhi_in_rddm, mhi_irq_handler, parse_xfer_event, mhi_dump_sfr, mhi_create_devices, mhi_report_error, __mhi_pm_resume, mhi_power_down, mhi_device_configure, mhi_set_mhi_state, mhi_process_data_event_ring, mhi_register_controller, time_show, mhi_init_irq_setup, mhi_pm_m0_transition, mhi_download_amss_image, mhi_prepare_for_power_up, mhi_reset_chan, mhi_misc_register_controller, mhi_rddm_download_status, mhi_device_get_sync_atomic, mhi_process_misc_bw_ev_ring, mhi_get_remote_time, mhi_pm_m1_transition, mhi_rddm_prepare, mhi_download_rddm_image, mhi_misc_init_mmio, mhi_pm_suspend, mhi_pm_st_worker, mhi_misc_sysfs_create, mhi_process_misc_tsync_ev_ring, mhi_process_ctrl_ev_ring, mhi_misc_mission_mode, mhi_get_remote_time_sync, time_async_show, mhi_init_mmio, mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00119020 size=1
// signature: undefined ipc_log_string(void)
// callers: [mhi_ready_state_transition, mhi_unprepare_channel, mhi_update_channel_state, mhi_prepare_channel, mhi_force_rddm_mode, mhi_pm_fast_resume, mhi_host_notify_db_disable_trace, mhi_pm_fast_suspend, mhi_fw_load_handler, mhi_send_cmd, parse_config, mhi_pm_m3_transition, mhi_debug_reg_dump, mhi_in_rddm, mhi_irq_handler, parse_xfer_event, mhi_dump_sfr, mhi_create_devices, mhi_report_error, __mhi_pm_resume, mhi_power_down, mhi_device_configure, mhi_set_mhi_state, mhi_gen_tre, mhi_process_data_event_ring, mhi_init_host_notification, time_show, log_level_store, mhi_init_irq_setup, mhi_pm_m0_transition, mhi_download_amss_image, mhi_prepare_for_power_up, mhi_reset_chan, mhi_misc_dbs_pending, mhi_rddm_download_status, mhi_device_get_sync_atomic, mhi_process_misc_bw_ev_ring, mhi_unprepare_from_transfer, mhi_get_remote_time, mhi_pm_m1_transition, mhi_scan_rddm_cookie, mhi_force_reset, mhi_rddm_prepare, mhi_destroy_device, mhi_ctrl_ev_task, mhi_download_rddm_image, mhi_misc_init_mmio, mhi_pm_suspend, mhi_pm_sys_err_handler, mhi_process_ev_work, mhi_pm_st_worker, mhi_misc_sysfs_create, mhi_intvec_threaded_handler, mhi_process_misc_tsync_ev_ring, mhi_process_ctrl_ev_ring, mhi_misc_mission_mode, mhi_get_remote_time_sync, time_async_show, mhi_init_mmio, mhi_async_power_up, mhi_time_async_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00119028 size=1
// signature: undefined dma_free_attrs(void)
// callers: [mhi_free_bhie_table, mhi_driver_remove, mhi_misc_disable, mhi_init_chan_ctxt, mhi_fw_load_handler, mhi_deinit_dev_ctxt, mhi_unmap_single_use_bb, mhi_init_dev_ctxt, mhi_alloc_bhie_table, mhi_deinit_chan_ctxt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00119030 size=1
// signature: undefined kfree(void)
// callers: [mhi_misc_unregister_controller, mhi_free_bhie_table, mhi_register_controller, mhi_release_device, mhi_prepare_channel, mhi_init_dev_ctxt, parse_xfer_event, mhi_dump_sfr, mhi_pm_st_worker, mhi_process_misc_tsync_ev_ring, mhi_reset_chan, mhi_deinit_dev_ctxt, mhi_unregister_controller, parse_config, mhi_alloc_bhie_table, mhi_free_controller, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00119040 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mhi_alloc_device, mhi_register_controller, mhi_queue_state_transition, mhi_init_dev_ctxt, mhi_controller_setup_timesync, mhi_controller_set_sfr_support, mhi_alloc_bhie_table, mhi_misc_register_controller, mhi_alloc_controller, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00119048 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [mhi_init_chan_ctxt, mhi_fw_load_handler, mhi_misc_mission_mode, mhi_init_dev_ctxt, mhi_alloc_bhie_table, mhi_map_single_use_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00119050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mhi_register_controller, time_show, log_level_store, mhi_prepare_channel, parse_rsc_event, mhi_force_rddm_mode, mhi_get_exec_env, mhi_download_amss_image, mhi_sync_power_up, mhi_bdf_to_controller, mhi_get_channel_db_base, mhi_write_reg_field, mhi_pm_fast_suspend, mhi_prepare_for_power_up, mhi_fw_load_handler, mhi_reset_chan, mhi_queue_buf, mhi_rddm_download_status, mhi_process_misc_bw_ev_ring, mhi_read_reg_field, mhi_scan_rddm_cookie, mhi_ctrl_ev_task, mhi_queue_dma, mhi_debug_reg_dump, mhi_download_rddm_image, mhi_get_event_ring_db_base, mhi_misc_init_mmio, parse_xfer_event, mhi_queue_skb, mhi_pm_suspend, mhi_get_soc_info, mhi_pm_st_worker, mhi_poll_reg_field, mhi_intvec_threaded_handler, __mhi_pm_resume, mhi_misc_mission_mode, mhi_get_capability_offset, mhi_get_remote_time_sync, mhi_get_mhi_state, __mhi_device_get_sync, mhi_init_host_notification, mhi_init_mmio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 00119058 size=1
// signature: undefined vfree(void)
// callers: [mhi_driver_remove, mhi_register_controller, mhi_unregister_controller, parse_config, mhi_deinit_chan_ctxt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 00119060 size=1
// signature: undefined vzalloc(void)
// callers: [mhi_init_chan_ctxt, parse_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00119068 size=1
// signature: undefined __mutex_init(void)
// callers: [mhi_register_controller, mhi_misc_init, mhi_misc_init_mmio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00119070 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00119078 size=1
// signature: undefined alloc_workqueue(void)
// callers: [mhi_register_controller, mhi_misc_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_init @ 00119080 size=1
// signature: undefined tasklet_init(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00119088 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [mhi_register_controller, mhi_misc_mission_mode, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00119090 size=1
// signature: undefined ida_alloc_range(void)
// callers: [mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00119098 size=1
// signature: undefined dev_set_name(void)
// callers: [mhi_create_devices, mhi_register_controller, mhi_misc_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001190a0 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [mhi_create_devices, mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 001190a8 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [mhi_create_devices, mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add @ 001190b0 size=1
// signature: undefined device_add(void)
// callers: [mhi_create_devices, mhi_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_del @ 001190b8 size=1
// signature: undefined device_del(void)
// callers: [mhi_destroy_device, mhi_register_controller, mhi_unregister_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 001190c0 size=1
// signature: undefined ida_free(void)
// callers: [mhi_register_controller, mhi_unregister_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001190c8 size=1
// signature: undefined destroy_workqueue(void)
// callers: [mhi_register_controller, mhi_unregister_controller, mhi_misc_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001190d0 size=1
// signature: undefined __list_add_valid(void)
// callers: [mhi_queue_state_transition, parse_config, mhi_misc_register_controller, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001190d8 size=1
// signature: undefined __kmalloc(void)
// callers: [mhi_prepare_channel, parse_config, mhi_controller_set_sfr_support, mhi_alloc_bhie_table, mhi_dump_sfr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 001190e0 size=1
// signature: undefined device_initialize(void)
// callers: [mhi_alloc_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001190e8 size=1
// signature: undefined put_device(void)
// callers: [mhi_create_devices, mhi_destroy_device, mhi_unregister_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001190f0 size=1
// signature: undefined mutex_lock(void)
// callers: [mhi_misc_unregister_controller, mhi_driver_remove, mhi_unprepare_channel, mhi_prepare_channel, mhi_pm_suspend, mhi_pm_fast_resume, mhi_pm_st_worker, mhi_update_transfer_state, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_process_misc_tsync_ev_ring, mhi_power_down, mhi_prepare_for_power_up, mhi_get_remote_time_sync, mhi_misc_register_controller, mhi_process_misc_bw_ev_ring, mhi_get_remote_time, mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 001190f8 size=1
// signature: undefined __memset_io(void)
// callers: [mhi_prepare_for_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00119100 size=1
// signature: undefined mutex_unlock(void)
// callers: [mhi_misc_unregister_controller, mhi_driver_remove, mhi_unprepare_channel, mhi_prepare_channel, mhi_pm_suspend, mhi_pm_fast_resume, mhi_pm_st_worker, mhi_update_transfer_state, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_process_misc_tsync_ev_ring, mhi_power_down, mhi_prepare_for_power_up, mhi_get_remote_time_sync, mhi_misc_register_controller, mhi_process_misc_bw_ev_ring, mhi_get_remote_time, mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_register @ 00119108 size=1
// signature: undefined driver_register(void)
// callers: [__mhi_driver_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irq @ 00119110 size=1
// signature: undefined _raw_write_lock_irq(void)
// callers: [mhi_ctrl_ev_task, mhi_ready_state_transition, mhi_driver_remove, mhi_unprepare_channel, mhi_update_channel_state, mhi_pm_suspend, mhi_pm_fast_resume, mhi_pm_m0_transition, mhi_download_amss_image, mhi_pm_st_worker, mhi_intvec_threaded_handler, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_power_down, mhi_process_ctrl_ev_ring, mhi_fw_load_handler, mhi_pm_m1_transition, mhi_pm_m3_transition, mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00119118 size=1
// signature: undefined complete_all(void)
// callers: [mhi_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irq @ 00119120 size=1
// signature: undefined _raw_write_unlock_irq(void)
// callers: [mhi_ctrl_ev_task, mhi_ready_state_transition, mhi_driver_remove, mhi_unprepare_channel, mhi_update_channel_state, mhi_pm_suspend, mhi_pm_fast_resume, mhi_pm_m0_transition, mhi_download_amss_image, mhi_pm_st_worker, mhi_intvec_threaded_handler, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_power_down, mhi_process_ctrl_ev_ring, mhi_fw_load_handler, mhi_pm_m1_transition, mhi_pm_m3_transition, mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 00119128 size=1
// signature: undefined driver_unregister(void)
// callers: [mhi_driver_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00119130 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mhi_create_devices, mhi_bdf_to_controller, mhi_match, mhi_device_configure, mhi_dump_sfr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 00119138 size=1
// signature: undefined add_uevent_var(void)
// callers: [mhi_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 00119140 size=1
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
// bus_unregister @ 00119148 size=1
// signature: undefined bus_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00119150 size=1
// signature: undefined sysfs_emit(void)
// callers: [serial_number_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit_at @ 00119158 size=1
// signature: undefined sysfs_emit_at(void)
// callers: [oem_pk_hash_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit_at(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udelay @ 00119160 size=1
// signature: undefined __udelay(void)
// callers: [mhi_poll_reg_field]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00119168 size=1
// signature: undefined usleep_range_state(void)
// callers: [mhi_poll_reg_field]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00119170 size=1
// signature: undefined msleep(void)
// callers: [mhi_poll_reg_field]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00119178 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [mhi_map_single_no_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 00119180 size=1
// signature: undefined dev_driver_string(void)
// callers: [mhi_map_single_no_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00119188 size=1
// signature: undefined __warn_printk(void)
// callers: [mhi_map_single_no_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 00119190 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [mhi_map_single_no_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00119198 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mhi_report_error, mhi_fw_load_handler, mhi_unmap_single_use_bb, mhi_dump_sfr, mhi_map_single_use_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 001191a0 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [mhi_unmap_single_no_bb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 001191a8 size=1
// signature: undefined get_device(void)
// callers: [mhi_create_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001191b0 size=1
// signature: undefined queue_work_on(void)
// callers: [mhi_queue_state_transition, mhi_irq_handler, mhi_process_sleeping_events, mhi_write_reg_offload, mhi_write_offload_wakedb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __tasklet_hi_schedule @ 001191c0 size=1
// signature: undefined __tasklet_hi_schedule(void)
// callers: [mhi_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tasklet_hi_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __tasklet_schedule @ 001191c8 size=1
// signature: undefined __tasklet_schedule(void)
// callers: [mhi_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tasklet_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001191d0 size=1
// signature: undefined __wake_up(void)
// callers: [mhi_in_rddm, mhi_pm_fast_resume, mhi_pm_m0_transition, mhi_intvec_handler, mhi_download_amss_image, mhi_pm_st_worker, mhi_report_error, mhi_intvec_threaded_handler, mhi_power_down, mhi_process_ctrl_ev_ring, mhi_fw_load_handler, mhi_pm_m1_transition, mhi_pm_m3_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_bh @ 001191d8 size=1
// signature: undefined _raw_write_lock_bh(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_gen_tre, mhi_process_misc_bw_ev_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001191e0 size=1
// signature: undefined complete(void)
// callers: [mhi_process_misc_tsync_ev_ring, mhi_process_ctrl_ev_ring, mhi_misc_cmd_completion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_bh @ 001191e8 size=1
// signature: undefined _raw_write_unlock_bh(void)
// callers: [mhi_process_ctrl_ev_ring, mhi_gen_tre, mhi_process_misc_bw_ev_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_bh @ 001191f0 size=1
// signature: undefined _raw_read_lock_bh(void)
// callers: [mhi_ready_state_transition, mhi_prepare_channel, mhi_device_put, parse_rsc_event, parse_xfer_event, mhi_pm_suspend, mhi_pm_fast_resume, mhi_pm_m0_transition, mhi_device_get, mhi_download_amss_image, mhi_pm_st_worker, mhi_process_misc_tsync_ev_ring, mhi_process_ctrl_ev_ring, mhi_fw_load_handler, mhi_reset_chan, mhi_send_cmd, __mhi_device_get_sync, mhi_process_data_event_ring, mhi_process_misc_bw_ev_ring, mhi_pm_m1_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_bh @ 001191f8 size=1
// signature: undefined _raw_read_unlock_bh(void)
// callers: [mhi_ready_state_transition, mhi_prepare_channel, mhi_device_put, parse_rsc_event, parse_xfer_event, mhi_pm_suspend, mhi_pm_fast_resume, mhi_pm_m0_transition, mhi_device_get, mhi_download_amss_image, mhi_pm_st_worker, mhi_process_misc_tsync_ev_ring, mhi_process_ctrl_ev_ring, mhi_fw_load_handler, mhi_reset_chan, mhi_send_cmd, __mhi_device_get_sync, mhi_process_data_event_ring, mhi_process_misc_bw_ev_ring, mhi_pm_m1_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00119200 size=1
// signature: noreturn undefined panic(void)
// callers: [mhi_process_ctrl_ev_ring, parse_xfer_event, mhi_pm_suspend, mhi_write_reg_offload, mhi_write_offload_wakedb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irqsave @ 00119208 size=1
// signature: undefined _raw_write_lock_irqsave(void)
// callers: [mhi_report_error, parse_xfer_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irqsave @ 00119210 size=1
// signature: undefined _raw_read_lock_irqsave(void)
// callers: [mhi_host_notify_db_disable_trace, parse_xfer_event, mhi_queue, mhi_device_get_sync_atomic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irqrestore @ 00119218 size=1
// signature: undefined _raw_read_unlock_irqrestore(void)
// callers: [mhi_host_notify_db_disable_trace, parse_xfer_event, mhi_queue, mhi_device_get_sync_atomic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irqrestore @ 00119220 size=1
// signature: undefined _raw_write_unlock_irqrestore(void)
// callers: [mhi_report_error, parse_xfer_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00119228 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [mhi_process_misc_tsync_ev_ring, mhi_send_cmd, mhi_poll, mhi_process_misc_bw_ev_ring, mhi_ev_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00119230 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [mhi_process_misc_tsync_ev_ring, mhi_send_cmd, mhi_poll, mhi_process_misc_bw_ev_ring, mhi_ev_task]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 00119238 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [mhi_ctrl_ev_task, mhi_device_put, mhi_queue, mhi_device_get, __mhi_device_get_sync, mhi_device_get_sync_atomic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irq @ 00119240 size=1
// signature: undefined _raw_read_lock_irq(void)
// callers: [mhi_prepare_channel, mhi_pm_m0_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irq @ 00119248 size=1
// signature: undefined _raw_read_unlock_irq(void)
// callers: [mhi_prepare_channel, mhi_pm_m0_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00119250 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [mhi_download_rddm_image, mhi_update_channel_state, mhi_pm_suspend, mhi_force_rddm_mode, mhi_download_amss_image, mhi_sync_power_up, mhi_pm_st_worker, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_fw_load_handler, mhi_misc_mission_mode, mhi_get_remote_time_sync, __mhi_device_get_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00119258 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [mhi_update_channel_state, mhi_misc_mission_mode, mhi_get_remote_time_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00119260 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [mhi_assert_dev_wake, mhi_queue_state_transition, mhi_reset_chan, mhi_deassert_dev_wake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00119268 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [mhi_assert_dev_wake, mhi_queue_state_transition, mhi_reset_chan, mhi_deassert_dev_wake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 00119270 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [mhi_pm_st_worker, mhi_ready_state_transition, mhi_pm_m0_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 00119278 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [mhi_pm_st_worker, mhi_ready_state_transition, mhi_pm_m0_transition]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00119280 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mhi_misc_unregister_controller, mhi_pm_st_worker, mhi_process_misc_tsync_ev_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 00119288 size=1
// signature: undefined device_for_each_child(void)
// callers: [mhi_pm_st_worker, mhi_report_error]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00119290 size=1
// signature: undefined init_wait_entry(void)
// callers: [mhi_pm_st_worker, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_download_rddm_image, mhi_fw_load_handler, mhi_pm_suspend, mhi_force_rddm_mode, __mhi_device_get_sync, mhi_download_amss_image, mhi_sync_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00119298 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [mhi_pm_st_worker, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_download_rddm_image, mhi_fw_load_handler, mhi_pm_suspend, mhi_force_rddm_mode, __mhi_device_get_sync, mhi_download_amss_image, mhi_sync_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 001192a0 size=1
// signature: undefined schedule_timeout(void)
// callers: [mhi_pm_st_worker, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_download_rddm_image, mhi_fw_load_handler, mhi_pm_suspend, mhi_force_rddm_mode, __mhi_device_get_sync, mhi_download_amss_image, mhi_sync_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_kill @ 001192a8 size=1
// signature: undefined tasklet_kill(void)
// callers: [mhi_pm_st_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_kill(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001192b0 size=1
// signature: undefined cancel_work_sync(void)
// callers: [mhi_pm_st_worker, mhi_reset_reg_write_q]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001192b8 size=1
// signature: undefined finish_wait(void)
// callers: [mhi_pm_st_worker, __mhi_pm_resume, mhi_pm_fast_suspend, mhi_download_rddm_image, mhi_fw_load_handler, mhi_pm_suspend, mhi_force_rddm_mode, __mhi_device_get_sync, mhi_download_amss_image, mhi_sync_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001192c0 size=1
// signature: undefined _dev_warn(void)
// callers: [__mhi_pm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 001192c8 size=1
// signature: undefined enable_irq(void)
// callers: [mhi_async_power_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 001192d0 size=1
// signature: undefined flush_work(void)
// callers: [mhi_pm_fast_suspend, mhi_power_down, mhi_force_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_u32 @ 001192d8 size=1
// signature: undefined get_random_u32(void)
// callers: [mhi_rddm_prepare, mhi_fw_load_handler, time_async_show, mhi_download_amss_image]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001192e0 size=1
// signature: undefined __const_udelay(void)
// callers: [mhi_download_rddm_image, mhi_rddm_download_status, mhi_device_get_sync_atomic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 001192e8 size=1
// signature: undefined request_firmware(void)
// callers: [mhi_fw_load_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 001192f0 size=1
// signature: undefined release_firmware(void)
// callers: [mhi_fw_load_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001192f8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [mhi_debug_reg_dump, mhi_misc_mission_mode, mhi_reset_reg_write_q]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_pcie_prevent_l1 @ 00119300 size=1
// signature: undefined msm_pcie_prevent_l1(void)
// callers: [mhi_reg_write_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_pcie_prevent_l1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_pcie_allow_l1 @ 00119308 size=1
// signature: undefined msm_pcie_allow_l1(void)
// callers: [mhi_reg_write_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_pcie_allow_l1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00119310 size=1
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
// log_post_write_mmio @ 00119318 size=1
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
// sysfs_create_group @ 00119320 size=1
// signature: undefined sysfs_create_group(void)
// callers: [mhi_misc_sysfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00119328 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [mhi_misc_sysfs_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00119330 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [mhi_misc_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00119338 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [mhi_misc_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00119340 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [mhi_bdf_to_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_unlock_wait @ 00119348 size=1
// signature: undefined tasklet_unlock_wait(void)
// callers: [mhi_pm_fast_suspend, mhi_pm_fast_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_unlock_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00119350 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [mhi_process_misc_tsync_ev_ring, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00119358 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [mhi_process_misc_tsync_ev_ring, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 00119368 size=1
// signature: undefined preempt_schedule(void)
// callers: [mhi_get_remote_time_sync, mhi_get_remote_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00119370 size=1
// signature: undefined scnprintf(void)
// callers: [log_level_show, time_show, time_async_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00119378 size=1
// signature: undefined kstrtouint(void)
// callers: [log_level_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



