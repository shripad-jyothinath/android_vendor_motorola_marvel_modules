// Decompiled by Ghidra 12.2
// Program: gsim.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_gsi_qtimer @ 00103664 size=148
// signature: undefined __traceiter_gsi_qtimer(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_gsi_qtimer
          (undefined8 param_1,undefined8 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  
  if (DAT_0012fd10 != (long *)0x0) {
    plVar2 = DAT_0012fd10;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x205e0280) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1036d0);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3 & 1,param_4,param_5,param_6);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// trace_event_raw_event_gsi_qtimer @ 001036fc size=220
// signature: undefined trace_event_raw_event_gsi_qtimer(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_gsi_qtimer
               (long param_1,undefined8 param_2,byte param_3,undefined1 param_4,undefined4 param_5,
               undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x20), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined1 *)(lVar1 + 0x11) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    *(byte *)(lVar1 + 0x10) = param_3 & 1;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_gsi_qtimer @ 001037dc size=284
// signature: undefined perf_trace_gsi_qtimer(void)
// callers: []
//------------------------------------------------------------

void perf_trace_gsi_qtimer
               (long param_1,undefined8 param_2,byte param_3,undefined1 param_4,undefined4 param_5,
               undefined4 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x24,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined1 *)(lVar3 + 0x11) = param_4;
    *(byte *)(lVar3 + 0x10) = param_3 & 1;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x24,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_gsi_qtimer @ 001038fc size=44
// signature: undefined __bpf_trace_gsi_qtimer(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_gsi_qtimer
               (undefined8 param_1,undefined8 param_2,ulong param_3,undefined1 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3 & 1,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// gsi_find_idx_from_addr @ 0010392c size=44
// signature: undefined gsi_find_idx_from_addr(void)
// callers: [gsi_wq_update_dp_stats]
//------------------------------------------------------------

uint gsi_find_idx_from_addr(long param_1,ulong param_2)

{
  uint uVar1;
  code *pcVar2;
  
  if ((param_2 < *(ulong *)(param_1 + 0x10)) || (*(ulong *)(param_1 + 0x40) <= param_2)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10393c);
    (*pcVar2)();
  }
  uVar1 = 0;
  if (*(byte *)(param_1 + 0x3c) != 0) {
    uVar1 = (uint)((int)param_2 - (int)*(ulong *)(param_1 + 0x10)) / (uint)*(byte *)(param_1 + 0x3c)
    ;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsi_ring_evt_doorbell_polling_mode @ 00103964 size=80
// signature: undefined gsi_ring_evt_doorbell_polling_mode(void)
// callers: []
//------------------------------------------------------------

void gsi_ring_evt_doorbell_polling_mode(ulong param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  lVar1 = gsi_ctx;
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1039b4);
    (*pcVar2)();
  }
  lVar3 = *(long *)(gsi_ctx + param_1 * 0x1c0 + 0x188);
  *(undefined8 *)(lVar3 + 0xa0) = *(undefined8 *)(lVar3 + 0xb0);
  gsihal_write_reg_nk(0x11,*(undefined4 *)(lVar1 + 0x14),*(undefined1 *)(lVar3 + 0x84));
  return;
}



//------------------------------------------------------------
// gsi_complete_clk_grant @ 001039b8 size=416
// signature: undefined gsi_complete_clk_grant(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_complete_clk_grant(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_complete_clk_grant",0x4f1);
    uVar2 = 0xfffffff8;
  }
  else {
    if (*(char *)(gsi_ctx + 0xb0) == '\0') {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d no client registered\n","gsi_complete_clk_grant",
               0x4f6);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d no client registered\n",
                         "gsi_complete_clk_grant",0x4f6);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d no client registered\n",
                         "gsi_complete_clk_grant",0x4f6);
          return 0xfffffffa;
        }
      }
    }
    else {
      if (gsi_ctx == param_1) {
        uVar2 = _raw_spin_lock_irqsave(gsi_ctx + 0x6f90);
        gsi_handle_irq();
        if (*(int *)(*(code **)(gsi_ctx + 0x78) + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x103a20);
          (*pcVar1)();
        }
        (**(code **)(gsi_ctx + 0x78))(*(undefined8 *)(gsi_ctx + 0x80));
        _raw_spin_unlock_irqrestore(gsi_ctx + 0x6f90,uVar2);
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
               "gsi_complete_clk_grant",0x4fc,param_1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n","gsi_complete_clk_grant",
                         0x4fc,param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                         "%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n","gsi_complete_clk_grant",
                         0x4fc,param_1);
        }
      }
    }
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}



//------------------------------------------------------------
// gsi_handle_irq @ 00103b58 size=7812
// signature: undefined gsi_handle_irq(void)
// callers: [gsi_isr, gsi_complete_clk_grant]
//------------------------------------------------------------

void gsi_handle_irq(void)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  ulong uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 uVar10;
  code *pcVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  ulong uVar18;
  char *pcVar19;
  char *pcVar20;
  undefined4 uVar21;
  ulong uVar22;
  long lVar23;
  long lVar24;
  ulong uVar25;
  long lVar26;
  long lVar27;
  int iVar28;
  int iVar29;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  int local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  long local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar23 = sp_el0;
  local_70 = *(long *)(lVar23 + 0x638);
  local_f8 = 0;
  uVar6 = *(undefined4 *)(gsi_ctx + 0x14);
  local_e0 = 0;
  local_f0 = 0;
  local_e8 = 0;
  if (*(int *)(*(code **)(gsi_ctx + 0x88) + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
    pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103bbc);
    (*pcVar11)();
  }
  iVar12 = (**(code **)(gsi_ctx + 0x88))();
  if (iVar12 != 0) {
    uVar17 = sp_el0;
    do {
      iVar12 = gsihal_read_reg_n_fields(6,uVar6,&local_f8);
      if (iVar12 == 0) break;
      if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d type 0x%x\n","gsi_handle_irq",0x420,iVar12
                      );
      }
      uVar14 = *(uint *)(gsi_ctx + 0x7250);
      uVar17 = sched_clock();
      if (0x13 < uVar14) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x105bbc);
        (*pcVar11)();
      }
      lVar23 = (ulong)uVar14 * 0x18;
      *(undefined8 *)(gsi_ctx + lVar23 + 0x7070) = uVar17;
      InstructionSynchronizationBarrier();
      uVar17 = cntvct_el0;
      *(undefined8 *)(gsi_ctx + lVar23 + 0x7078) = uVar17;
      *(int *)(gsi_ctx + lVar23 + 0x7080) = iVar12;
      lVar23 = gsi_ctx;
      iVar12 = 0;
      if (*(int *)(gsi_ctx + 0x7250) != 0x13) {
        iVar12 = *(int *)(gsi_ctx + 0x7250) + 1;
      }
      *(int *)(gsi_ctx + 0x7250) = iVar12;
      if (local_e0 != 0) {
        local_b0 = 0;
        uStack_a8 = 0;
        local_c0 = 0;
        local_b8 = 0;
        if (*(uint *)(lVar23 + 0x10) < 10) {
          uVar14 = gsihal_read_reg_nk(7,uVar6,0);
          gsihal_write_reg_nk(9,uVar6,0,uVar14);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %x\n","gsi_handle_ch_ctrl",0x170,
                             uVar14);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %x\n","gsi_handle_ch_ctrl",0x170,
                             uVar14);
            }
          }
          uVar25 = 0;
          lVar23 = 0x3fe8;
          lVar24 = 0x1c0;
          goto LAB_00105300;
        }
        uVar14 = gsihal_get_bit_map_array_size();
        if (0 < (int)uVar14) {
          uVar25 = 0;
          do {
            uVar18 = uVar25 & 0x7ffffff;
            uVar15 = gsihal_read_reg_nk(0x7d,uVar6,uVar25 & 0xffffffff);
            gsihal_write_reg_nk(0x81,uVar6,uVar25 & 0xffffffff,uVar15);
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %x\n","gsi_handle_ch_ctrl",
                               0x155,uVar15);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %x\n","gsi_handle_ch_ctrl",
                               0x155,uVar15);
              }
            }
            lVar23 = 0;
            lVar24 = uVar18 * 0x700 + 0x3fe8;
            uVar22 = uVar18 * 0x3800 | 0x1c0;
            do {
              lVar26 = gsi_ctx;
              if ((uVar15 >> (ulong)((uint)lVar23 & 0x1f) & 1) != 0) {
                uVar4 = uVar18 * 0x20 + lVar23;
                if ((0x23 < uVar4) || (*(uint *)(gsi_ctx + 0x6fc0) <= uVar4)) {
                  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid channel %d\n",
                           "gsi_handle_ch_ctrl",0x15c,uVar4 & 0xffffffff);
                  if (gsi_ctx != 0) {
                    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid channel %d\n",
                                     "gsi_handle_ch_ctrl",0x15c,uVar4 & 0xffffffff);
                    }
                    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid channel %d\n",
                                     "gsi_handle_ch_ctrl",0x15c,uVar4 & 0xffffffff);
                    }
                  }
                  break;
                }
                gsihal_read_reg_nk_fields(8,uVar6,uVar4 & 0xffffffff,&local_c0);
                lVar26 = lVar26 + uVar22;
                *(int *)(lVar26 + -0x90) = local_c0._4_4_;
                if (gsi_ctx != 0) {
                  if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                    ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %u state updated to %u\n",
                                   "gsi_handle_ch_ctrl",0x166,uVar4 & 0xffffffff);
                  }
                  if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %u state updated to %u\n",
                                   "gsi_handle_ch_ctrl",0x166,uVar4 & 0xffffffff,
                                   *(undefined4 *)(lVar26 + -0x90));
                  }
                }
                complete(lVar26);
                *(long *)(gsi_ctx + lVar24) = *(long *)(gsi_ctx + lVar24) + 1;
              }
              lVar23 = lVar23 + 1;
              lVar24 = lVar24 + 0x38;
              uVar22 = uVar22 + 0x1c0;
            } while (lVar23 != 0x20);
            uVar25 = uVar25 + 1;
          } while (uVar25 != uVar14);
        }
        break;
      }
      if (local_e8._4_4_ != 0) {
        local_b8 = 0;
        local_b0 = 0;
        local_c0 = 0;
        if (*(uint *)(lVar23 + 0x10) < 10) {
          uVar14 = gsihal_read_reg_nk(10,uVar6,0);
          gsihal_write_reg_nk(0xb,uVar6,0,uVar14);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ev %x\n","gsi_handle_ev_ctrl",0x1af,
                             uVar14);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ev %x\n","gsi_handle_ev_ctrl",0x1af,
                             uVar14);
            }
          }
          uVar25 = 0;
          lVar23 = 0x4818;
          goto LAB_0010543c;
        }
        uVar14 = gsihal_get_bit_map_array_size();
        if (uVar14 != 0) {
          uVar25 = 0;
          do {
            uVar15 = gsihal_read_reg_nk(0x7e,uVar6,uVar25 & 0xffffffff);
            gsihal_write_reg_nk(0x82,uVar6,uVar25 & 0xffffffff,uVar15);
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ev %x\n","gsi_handle_ev_ctrl",
                               0x195,uVar15);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ev %x\n","gsi_handle_ev_ctrl",
                               0x195,uVar15);
              }
            }
            lVar23 = 0;
            lVar24 = (uVar25 & 0x7ffffff) * 0x2900 + 0x4818;
            do {
              lVar26 = gsi_ctx;
              if ((uVar15 >> (ulong)((uint)lVar23 & 0x1f) & 1) != 0) {
                uVar18 = (uVar25 & 0x7ffffff) * 0x20 + lVar23;
                if ((0x1e < uVar18) || (*(uint *)(gsi_ctx + 0x6fc4) <= uVar18)) {
                  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid event %d\n",
                           "gsi_handle_ev_ctrl",0x19c,uVar18 & 0xffffffff);
                  if (gsi_ctx != 0) {
                    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid event %d\n",
                                     "gsi_handle_ev_ctrl",0x19c,uVar18 & 0xffffffff);
                    }
                    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid event %d\n",
                                     "gsi_handle_ev_ctrl",0x19c,uVar18 & 0xffffffff);
                    }
                  }
                  break;
                }
                gsihal_read_reg_nk_fields(0xc,uVar6,uVar18 & 0xffffffff,&local_c0);
                *(int *)(lVar26 + lVar24) = local_c0._4_4_;
                if (gsi_ctx != 0) {
                  if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                    ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt %u state updated to %u\n",
                                   "gsi_handle_ev_ctrl",0x1a6,uVar18 & 0xffffffff);
                  }
                  if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt %u state updated to %u\n",
                                   "gsi_handle_ev_ctrl",0x1a6,uVar18 & 0xffffffff,
                                   *(undefined4 *)(lVar26 + lVar24));
                  }
                }
                complete(lVar26 + lVar24 + 0x80);
              }
              lVar23 = lVar23 + 1;
              lVar24 = lVar24 + 0x148;
            } while (lVar23 != 0x20);
            uVar25 = uVar25 + 1;
          } while (uVar25 != uVar14);
        }
        break;
      }
      if ((int)local_e8 == 0) goto LAB_00103db4;
      local_c8 = 0;
      local_d8 = 0;
      uVar13 = gsihal_read_reg_n_fields(0xd,uVar6,&local_d8);
      local_d0 = *(undefined8 *)(gsi_ctx + 0x80);
      if (local_d8._3_1_ == '\0') {
        goto joined_r0x00103d1c;
      }
      uVar14 = gsihal_read_reg_nk(0xe,uVar6,0);
      uVar10 = (undefined2)uVar14;
      if (1 < *(uint *)(gsi_ctx + 0x10)) {
        gsihal_write_reg_nk(0xe,uVar6,0,0);
      }
      gsihal_write_reg_nk(0xf,uVar6,0,0xffffffff);
      local_80 = 0;
      local_78 = 0;
      local_90 = 0;
      local_88 = 0;
      uVar16 = uVar14 >> 0x18 & 0xf;
      local_b0 = 0;
      uStack_a8 = 0;
      uVar15 = uVar14 >> 0x1c;
      local_c0 = 0;
      local_b8 = 0;
      uVar7 = uVar14 >> 0x13 & 0x1f;
      uVar25 = (ulong)uVar7;
      local_a0 = 0;
      local_98 = 0;
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d log err_type=%u ee=%u idx=%u\n",
               "gsi_handle_glob_err",0x1d2,uVar16,uVar15,uVar25);
      lVar23 = 0;
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d log err_type=%u ee=%u idx=%u\n",
                         "gsi_handle_glob_err",0x1d2,uVar16,uVar15,uVar25);
        }
        lVar23 = gsi_ctx;
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d log err_type=%u ee=%u idx=%u\n",
                         "gsi_handle_glob_err",0x1d2,uVar16,uVar15,uVar25);
          lVar23 = gsi_ctx;
        }
      }
      uVar8 = uVar14 >> 8 & 0xf;
      uVar9 = uVar14 >> 4 & 0xf;
      uVar5 = uVar14 & 0xf;
      uVar14 = uVar14 >> 0xc;
      _dev_err(*(undefined8 *)(lVar23 + 8),"%s:%d code=%u arg1=%u arg2=%u arg3=%u\n",
               "gsi_handle_glob_err",0x1d4,uVar14 & 0xf,uVar8,uVar9,uVar5);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d code=%u arg1=%u arg2=%u arg3=%u\n",
                         "gsi_handle_glob_err",0x1d4,uVar14 & 0xf,uVar8,uVar9,uVar5);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d code=%u arg1=%u arg2=%u arg3=%u\n",
                         "gsi_handle_glob_err",0x1d4,uVar14 & 0xf,uVar8,uVar9,uVar5);
        }
      }
      lVar23 = gsi_ctx;
      if (uVar16 == 3) {
        if (*(uint *)(gsi_ctx + 0x6fc4) <= uVar7) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x104d00);
          (*pcVar11)();
        }
        lVar23 = gsi_ctx + uVar25 * 0x148;
        local_90 = *(undefined8 *)(lVar23 + 0x4800);
        local_88._0_6_ = CONCAT24(uVar10,(undefined4)local_88);
        switch(uVar14 & 0xf) {
        case 2:
          if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
            _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                     "gsi_handle_glob_err",0x22c,uVar15);
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                               "gsi_handle_glob_err",0x22c,uVar15);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                               "gsi_handle_glob_err",0x22c,uVar15);
              }
            }
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105854);
            (*pcVar11)();
          }
          local_88 = (ulong)local_88._4_4_ << 0x20;
          break;
        case 3:
          if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
            _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                     "gsi_handle_glob_err",0x232,uVar15);
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                               "gsi_handle_glob_err",0x232,uVar15);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                               "gsi_handle_glob_err",0x232,uVar15);
              }
            }
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105754);
            (*pcVar11)();
          }
          local_88 = CONCAT44(local_88._4_4_,1);
          complete(gsi_ctx + uVar25 * 0x148 + 0x4898);
          break;
        case 4:
          local_88 = CONCAT44(local_88._4_4_,2);
          break;
        case 5:
          if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
            _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                     "gsi_handle_glob_err",0x23b,uVar15);
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                               "gsi_handle_glob_err",0x23b,uVar15);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                               "gsi_handle_glob_err",0x23b,uVar15);
              }
            }
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x800,0x1057d4);
            (*pcVar11)();
          }
          local_88 = CONCAT44(local_88._4_4_,3);
          break;
        default:
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected event log code %d\n",
                   "gsi_handle_glob_err",0x240,uVar14 & 0xf);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected event log code %d\n",
                             "gsi_handle_glob_err",0x240,uVar14 & 0xf);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected event log code %d\n",
                             "gsi_handle_glob_err",0x240,uVar14 & 0xf);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x1056d4);
          (*pcVar11)();
        }
        pcVar11 = *(code **)(lVar23 + 0x47f8);
        if (*(int *)(pcVar11 + -4) != -0x2876285e) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104bc4);
          (*pcVar11)();
        }
        (*pcVar11)(&local_90);
        goto LAB_00104c60;
      }
      if (uVar16 != 2) {
        if (uVar16 == 1) {
          local_98 = (ulong)CONCAT22((short)((ulong)local_98 >> 0x30),uVar10) << 0x20;
          local_a0 = *(undefined8 *)(gsi_ctx + 0x80);
          if (*(int *)(*(code **)(gsi_ctx + 0x68) + -4) != 0x65ac0b17) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1044fc);
            (*pcVar11)();
          }
          (**(code **)(gsi_ctx + 0x68))(&local_a0);
        }
        goto LAB_00104c60;
      }
      if (*(uint *)(gsi_ctx + 0x6fc0) <= uVar7) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x800,0x104c74);
        (*pcVar11)();
      }
      lVar24 = gsi_ctx + uVar25 * 0x1c0;
      local_80 = *(ulong *)(lVar24 + 0x128);
      local_78._0_6_ = CONCAT24(uVar10,(undefined4)local_78);
      switch(uVar14 & 0xf) {
      case 1:
        if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                   "gsi_handle_glob_err",0x1ee);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x1ee,uVar15);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x1ee,uVar15);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105a40);
          (*pcVar11)();
        }
        gsihal_read_reg_nk_fields(8,uVar15,uVar25,&local_c0);
        lVar26 = lVar23 + uVar25 * 0x1c0;
        piVar2 = (int *)(lVar26 + 0x130);
        *(int *)(lVar26 + 0x130) = local_c0._4_4_;
        iVar12 = local_c0._4_4_;
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %u state updated to %u\n",
                           "gsi_handle_glob_err",0x1f6,uVar25);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %u state updated to %u\n",
                           "gsi_handle_glob_err",0x1f6,uVar25,*piVar2);
          }
          iVar12 = *piVar2;
        }
        lVar23 = lVar23 + uVar25 * 0x1c0;
        *(long *)(lVar23 + 0x228) = *(long *)(lVar23 + 0x228) + 1;
        if (iVar12 == 0xf) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Unexpected channel state %d\n",
                   "gsi_handle_glob_err",0x1fa,0xf);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Unexpected channel state %d\n",
                             "gsi_handle_glob_err",0x1fa,*piVar2);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Unexpected channel state %d\n",
                             "gsi_handle_glob_err",0x1fa,*piVar2);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105bb8);
          (*pcVar11)();
        }
        local_78 = local_78 & 0xffffffff00000000;
        break;
      case 2:
        if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                   "gsi_handle_glob_err",0x200,uVar15);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x200,uVar15);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x200,uVar15);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105abc);
          (*pcVar11)();
        }
        uVar21 = 2;
        goto LAB_00104c34;
      case 3:
        if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                   "gsi_handle_glob_err",0x206,uVar15);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x206,uVar15);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x206,uVar15);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105b38);
          (*pcVar11)();
        }
        local_78 = CONCAT44(local_78._4_4_,3);
        complete(gsi_ctx + uVar25 * 0x1c0 + 0x1c0);
        break;
      case 4:
        uVar21 = 4;
        goto LAB_00104c34;
      default:
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected event log code %d\n",
                 "gsi_handle_glob_err",0x21c,uVar14 & 0xf);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected event log code %d\n",
                           "gsi_handle_glob_err",0x21c,uVar14 & 0xf);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected event log code %d\n",
                           "gsi_handle_glob_err",0x21c,uVar14 & 0xf);
          }
        }
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x800,0x1058d0);
        (*pcVar11)();
      case 6:
        if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                   "gsi_handle_glob_err",0x210,uVar15);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x210,uVar15);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x210,uVar15);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x10594c);
          (*pcVar11)();
        }
        local_78 = CONCAT44(local_78._4_4_,1);
        break;
      case 8:
        if (uVar15 != *(uint *)(gsi_ctx + 0x14)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d unexpected EE in event %d\n",
                   "gsi_handle_glob_err",0x217,uVar15);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x217,uVar15);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d unexpected EE in event %d\n",
                             "gsi_handle_glob_err",0x217,uVar15);
            }
          }
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x1059c8);
          (*pcVar11)();
        }
        uVar21 = 5;
LAB_00104c34:
        local_78 = CONCAT44(local_78._4_4_,uVar21);
      }
      pcVar11 = *(code **)(lVar24 + 0x118);
      if (*(int *)(pcVar11 + -4) != 0x35b3608c) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104c5c);
        (*pcVar11)();
      }
      (*pcVar11)(&local_80);
LAB_00104c60:
joined_r0x00103d1c:
      if (local_d8._2_1_ != '\0') {
        complete(gsi_ctx + 0x6fc8);
      }
      if (local_d8._1_1_ != '\0') {
        local_c8 = CONCAT44(local_c8._4_4_,2);
        if (*(int *)(*(code **)(gsi_ctx + 0x68) + -4) != 0x65ac0b17) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103d64);
          (*pcVar11)();
        }
        (**(code **)(gsi_ctx + 0x68))(&local_d0);
      }
      if ((char)local_d8 != '\0') {
        local_c8 = CONCAT44(local_c8._4_4_,3);
        if (*(int *)(*(code **)(gsi_ctx + 0x68) + -4) != 0x65ac0b17) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103d9c);
          (*pcVar11)();
        }
        (**(code **)(gsi_ctx + 0x68))(&local_d0);
      }
      gsihal_write_reg_nk(0x10,uVar6,0,uVar13);
LAB_00103db4:
      if (local_f0._4_4_ != 0) {
        local_b8 = 0;
        local_b0 = 0;
        local_c0 = 0;
        if (*(uint *)(gsi_ctx + 0x10) < 10) {
          uVar14 = gsihal_read_reg_nk(0x13,uVar6,0);
          uVar15 = gsihal_read_reg_nk(3,uVar6,0);
          gsihal_write_reg_nk(0x14,uVar6,0,uVar15 & uVar14);
          uVar25 = 0;
          do {
            if ((uVar14 & uVar15 & 1 << (ulong)((uint)uVar25 & 0x1f)) != 0) {
              if ((0x1e < uVar25) || (*(uint *)(gsi_ctx + 0x6fc4) <= uVar25)) {
                _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid event %d\n","gsi_handle_ieob",
                         0x385,uVar25 & 0xffffffff);
                if (gsi_ctx != 0) {
                  if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                    ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid event %d\n",
                                   "gsi_handle_ieob",0x385,uVar25 & 0xffffffff);
                  }
                  if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid event %d\n",
                                   "gsi_handle_ieob",0x385,uVar25 & 0xffffffff);
                  }
                }
                break;
              }
              lVar23 = gsi_ctx + uVar25 * 0x148;
              piVar2 = (int *)(lVar23 + 0x4798);
              if (*(int *)(lVar23 + 0x479c) != 0) {
                if (*piVar2 != 2) {
                  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Unexpected irq intf %d\n",
                           "gsi_handle_ieob",0x393);
                  if (gsi_ctx != 0) {
                    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Unexpected irq intf %d\n",
                                     "gsi_handle_ieob",0x393,*piVar2);
                    }
                    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Unexpected irq intf %d\n",
                                     "gsi_handle_ieob",0x393,*piVar2);
                    }
                  }
                    /* WARNING: Does not return */
                  pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105538);
                  (*pcVar11)();
                }
                lVar24 = gsi_ctx + uVar25 * 0x148;
                uVar17 = _raw_spin_lock_irqsave();
                puVar3 = (ulong *)(lVar24 + 0x4850);
                do {
                  if (*(int *)(*(code **)(lVar23 + 0x4810) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
                    pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10428c);
                    (*pcVar11)();
                  }
                  uVar18 = (**(code **)(lVar23 + 0x4810))
                                     (piVar2,*(undefined1 *)(lVar24 + 0x481c),uVar6);
                  uVar18 = uVar18 | (ulong)*(uint *)(lVar24 + 0x4844) << 0x20;
                  *(ulong *)(lVar24 + 0x4840) = uVar18;
                  if ((*puVar3 == uVar18) || (*(int *)(*(long *)(lVar24 + 0x48b8) + 300) != 0))
                  break;
                  gsi_process_evt_re(piVar2,&local_c0,1);
                  lVar26 = 1;
                  uVar22 = *puVar3;
                  while (uVar22 != uVar18) {
                    if (*(int *)(*(long *)(lVar24 + 0x48b8) + 300) != 0) {
                      lVar26 = 0;
                      break;
                    }
                    lVar26 = lVar26 + 1;
                    gsi_process_evt_re(piVar2,&local_c0,1);
                    uVar22 = *puVar3;
                  }
                  *(undefined8 *)(lVar24 + 0x4838) = *(undefined8 *)(lVar24 + 0x4848);
                  gsihal_write_reg_nk(0x11,*(undefined4 *)(gsi_ctx + 0x14),
                                      *(undefined1 *)(lVar24 + 0x481c));
                } while (lVar26 != 0);
                _raw_spin_unlock_irqrestore(lVar24 + 0x4820,uVar17);
              }
            }
            uVar25 = uVar25 + 1;
          } while (uVar25 != 0x20);
        }
        else {
          uVar14 = gsihal_get_bit_map_array_size();
          if (0 < (int)uVar14) {
            uVar25 = 0;
            do {
              uVar15 = gsihal_read_reg_nk(0x83,uVar6,uVar25 & 0xffffffff);
              uVar16 = gsihal_read_reg_nk(0x84,uVar6,uVar25 & 0xffffffff);
              gsihal_write_reg_nk(0x85,uVar6,uVar25 & 0xffffffff,uVar16 & uVar15);
              lVar23 = 0;
              do {
                if ((uVar15 & uVar16 & 1 << (ulong)((uint)lVar23 & 0x1f)) != 0) {
                  uVar18 = lVar23 + (ulong)(uint)((int)uVar25 << 5);
                  if ((0x1e < uVar18) || (*(uint *)(gsi_ctx + 0x6fc4) <= uVar18)) {
                    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid event %d\n",
                             "gsi_handle_ieob",0x34d,uVar18 & 0xffffffff);
                    if (gsi_ctx != 0) {
                      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid event %d\n",
                                       "gsi_handle_ieob",0x34d,uVar18 & 0xffffffff);
                      }
                      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid event %d\n",
                                       "gsi_handle_ieob",0x34d,uVar18 & 0xffffffff);
                      }
                    }
                    break;
                  }
                  lVar24 = gsi_ctx + uVar18 * 0x148;
                  piVar2 = (int *)(lVar24 + 0x4798);
                  if (*(int *)(lVar24 + 0x479c) != 0) {
                    if (*piVar2 != 2) {
                      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Unexpected irq intf %d\n",
                               "gsi_handle_ieob",0x35c);
                      if (gsi_ctx != 0) {
                        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                                         "%s:%d Unexpected irq intf %d\n","gsi_handle_ieob",0x35c,
                                         *piVar2);
                        }
                        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                                         "%s:%d Unexpected irq intf %d\n","gsi_handle_ieob",0x35c,
                                         *piVar2);
                        }
                      }
                    /* WARNING: Does not return */
                      pcVar11 = (code *)SoftwareBreakpoint(0x800,0x104dfc);
                      (*pcVar11)();
                    }
                    lVar26 = gsi_ctx + uVar18 * 0x148;
                    uVar17 = _raw_spin_lock_irqsave();
                    puVar3 = (ulong *)(lVar26 + 0x4850);
                    do {
                      if (*(int *)(*(code **)(lVar24 + 0x4810) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
                        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103f70);
                        (*pcVar11)();
                      }
                      uVar18 = (**(code **)(lVar24 + 0x4810))
                                         (piVar2,*(undefined1 *)(lVar26 + 0x481c),uVar6);
                      uVar18 = uVar18 | (ulong)*(uint *)(lVar26 + 0x4844) << 0x20;
                      *(ulong *)(lVar26 + 0x4840) = uVar18;
                      if ((*puVar3 == uVar18) || (*(int *)(*(long *)(lVar26 + 0x48b8) + 300) != 0))
                      break;
                      gsi_process_evt_re(piVar2,&local_c0,1);
                      lVar27 = 1;
                      uVar22 = *puVar3;
                      while (uVar22 != uVar18) {
                        if (*(int *)(*(long *)(lVar26 + 0x48b8) + 300) != 0) {
                          lVar27 = 0;
                          break;
                        }
                        lVar27 = lVar27 + 1;
                        gsi_process_evt_re(piVar2,&local_c0,1);
                        uVar22 = *puVar3;
                      }
                      *(undefined8 *)(lVar26 + 0x4838) = *(undefined8 *)(lVar26 + 0x4848);
                      gsihal_write_reg_nk(0x11,*(undefined4 *)(gsi_ctx + 0x14),
                                          *(undefined1 *)(lVar26 + 0x481c));
                    } while (lVar27 != 0);
                    _raw_spin_unlock_irqrestore(lVar26 + 0x4820,uVar17);
                  }
                }
                lVar23 = lVar23 + 1;
              } while (lVar23 != 0x20);
              uVar25 = uVar25 + 1;
            } while (uVar25 != uVar14);
          }
        }
      }
      if ((int)local_f0 != 0) {
        if (*(uint *)(gsi_ctx + 0x10) < 10) {
          uVar15 = gsihal_read_reg_nk(0x15,uVar6,0);
          gsihal_write_reg_nk(0x15,uVar6,0,uVar15);
          uVar14 = 0;
          do {
            if (((uVar15 >> (ulong)(uVar14 & 0x1f) & 1) != 0) &&
               (_dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d ch %u was inter-EE changed\n",
                         "gsi_handle_inter_ee_ch_ctrl",0x3cc,uVar14), gsi_ctx != 0)) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %u was inter-EE changed\n",
                               "gsi_handle_inter_ee_ch_ctrl",0x3cc,uVar14);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %u was inter-EE changed\n",
                               "gsi_handle_inter_ee_ch_ctrl",0x3cc,uVar14);
              }
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 != 0x20);
        }
        else {
          iVar12 = gsihal_get_bit_map_array_size();
          if (0 < iVar12) {
            iVar28 = 0;
            iVar29 = 0;
            do {
              uVar15 = gsihal_read_reg_nk(0x86,uVar6,iVar29);
              gsihal_write_reg_nk(0x86,uVar6,iVar29,uVar15);
              uVar14 = 0;
              do {
                if ((uVar15 >> (ulong)(uVar14 & 0x1f) & 1) != 0) {
                  iVar1 = iVar28 + uVar14;
                  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d ch %u was inter-EE changed\n",
                           "gsi_handle_inter_ee_ch_ctrl",0x3c1,iVar1);
                  if (gsi_ctx != 0) {
                    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                                     "%s:%d ch %u was inter-EE changed\n",
                                     "gsi_handle_inter_ee_ch_ctrl",0x3c1,iVar1);
                    }
                    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                                     "%s:%d ch %u was inter-EE changed\n",
                                     "gsi_handle_inter_ee_ch_ctrl",0x3c1,iVar1);
                    }
                  }
                }
                uVar14 = uVar14 + 1;
              } while (uVar14 != 0x20);
              iVar29 = iVar29 + 1;
              iVar28 = iVar28 + 0x20;
            } while (iVar29 != iVar12);
          }
        }
      }
      if (local_f8._4_4_ != 0) {
        if (*(uint *)(gsi_ctx + 0x10) < 10) {
          uVar15 = gsihal_read_reg_nk(0x17,uVar6,0);
          gsihal_write_reg_nk(0x18,uVar6,0,uVar15);
          uVar14 = 0;
          do {
            if (((uVar15 >> (ulong)(uVar14 & 0x1f) & 1) != 0) &&
               (_dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt %u was inter-EE changed\n",
                         "gsi_handle_inter_ee_ev_ctrl",0x3ed,uVar14), gsi_ctx != 0)) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt %u was inter-EE changed\n",
                               "gsi_handle_inter_ee_ev_ctrl",0x3ed,uVar14);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt %u was inter-EE changed\n",
                               "gsi_handle_inter_ee_ev_ctrl",0x3ed,uVar14);
              }
            }
            uVar14 = uVar14 + 1;
          } while (uVar14 != 0x20);
        }
        else {
          iVar12 = gsihal_get_bit_map_array_size();
          if (0 < iVar12) {
            iVar28 = 0;
            iVar29 = 0;
            do {
              uVar15 = gsihal_read_reg_nk(0x88,uVar6,iVar29);
              gsihal_write_reg_nk(0x89,uVar6,iVar29,uVar15);
              uVar14 = 0;
              do {
                if ((uVar15 >> (ulong)(uVar14 & 0x1f) & 1) != 0) {
                  iVar1 = iVar28 + uVar14;
                  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt %u was inter-EE changed\n",
                           "gsi_handle_inter_ee_ev_ctrl",0x3e2,iVar1);
                  if (gsi_ctx != 0) {
                    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                                     "%s:%d evt %u was inter-EE changed\n",
                                     "gsi_handle_inter_ee_ev_ctrl",0x3e2,iVar1);
                    }
                    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                                     "%s:%d evt %u was inter-EE changed\n",
                                     "gsi_handle_inter_ee_ev_ctrl",0x3e2,iVar1);
                    }
                  }
                }
                uVar14 = uVar14 + 1;
              } while (uVar14 != 0x20);
              iVar29 = iVar29 + 1;
              iVar28 = iVar28 + 0x20;
            } while (iVar29 != iVar12);
          }
        }
      }
      if ((int)local_f8 != 0) {
        local_b8 = 0;
        local_80 = local_80 & 0xffffffff00000000;
        uVar13 = gsihal_read_reg_n_fields(0x19,uVar6,&local_80);
        local_c0 = *(undefined8 *)(gsi_ctx + 0x80);
        if ((char)local_80 != '\0') {
          local_b8 = CONCAT44(local_b8._4_4_,7);
        }
        if (local_80._1_1_ != '\0') {
          local_b8 = CONCAT44(local_b8._4_4_,6);
        }
        if (local_80._2_1_ != '\0') {
          local_b8 = CONCAT44(local_b8._4_4_,5);
        }
        if (local_80._3_1_ != '\0') {
          local_b8 = CONCAT44(local_b8._4_4_,4);
        }
        pcVar11 = *(code **)(gsi_ctx + 0x68);
        if (pcVar11 != (code *)0x0) {
          if (*(int *)(pcVar11 + -4) != 0x65ac0b17) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1049d4);
            (*pcVar11)();
          }
          (*pcVar11)(&local_c0);
        }
        gsihal_write_reg_nk(0x1a,uVar6,0,uVar13);
      }
      if (*(int *)(*(code **)(gsi_ctx + 0x88) + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103c10);
        (*pcVar11)();
      }
      iVar12 = (**(code **)(gsi_ctx + 0x88))();
    } while (iVar12 != 0);
  }
  goto LAB_00105620;
LAB_00105300:
  do {
    lVar26 = gsi_ctx;
    if ((uVar14 >> (ulong)((uint)uVar25 & 0x1f) & 1) != 0) {
      if (*(uint *)(gsi_ctx + 0x6fc0) <= uVar25) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid channel %d\n","gsi_handle_ch_ctrl",
                 0x175,uVar25 & 0xffffffff);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid channel %d\n",
                           "gsi_handle_ch_ctrl",0x175,uVar25 & 0xffffffff);
          }
          lVar23 = *(long *)(gsi_ctx + 0x6ff0);
          if (lVar23 != 0) {
            pcVar19 = "%s:%d invalid channel %d\n";
            pcVar20 = "gsi_handle_ch_ctrl";
            uVar17 = 0x175;
            goto LAB_00105618;
          }
        }
        break;
      }
      gsihal_read_reg_nk_fields(8,uVar6,uVar25 & 0xffffffff,&local_c0);
      lVar26 = lVar26 + lVar24;
      *(int *)(lVar26 + -0x90) = local_c0._4_4_;
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %u state updated to %u\n",
                         "gsi_handle_ch_ctrl",0x17f,uVar25 & 0xffffffff);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %u state updated to %u\n",
                         "gsi_handle_ch_ctrl",0x17f,uVar25 & 0xffffffff,
                         *(undefined4 *)(lVar26 + -0x90));
        }
      }
      complete(lVar26);
      *(long *)(gsi_ctx + lVar23) = *(long *)(gsi_ctx + lVar23) + 1;
    }
    uVar25 = uVar25 + 1;
    lVar23 = lVar23 + 0x38;
    lVar24 = lVar24 + 0x1c0;
  } while (uVar25 != 0x20);
  goto LAB_00105620;
LAB_0010543c:
  do {
    lVar24 = gsi_ctx;
    if ((uVar14 >> (ulong)((uint)uVar25 & 0x1f) & 1) != 0) {
      if ((uVar25 == 0x1f) || (*(uint *)(gsi_ctx + 0x6fc4) <= uVar25)) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid event %d\n","gsi_handle_ev_ctrl",0x1b4,
                 uVar25 & 0xffffffff);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid event %d\n",
                           "gsi_handle_ev_ctrl",0x1b4,uVar25 & 0xffffffff);
          }
          lVar23 = *(long *)(gsi_ctx + 0x6ff0);
          if (lVar23 != 0) {
            pcVar19 = "%s:%d invalid event %d\n";
            pcVar20 = "gsi_handle_ev_ctrl";
            uVar17 = 0x1b4;
LAB_00105618:
            ipc_log_string(lVar23,pcVar19,pcVar20,uVar17,uVar25 & 0xffffffff);
          }
        }
        break;
      }
      gsihal_read_reg_nk_fields(0xc,uVar6,uVar25 & 0xffffffff,&local_c0);
      *(int *)(lVar24 + lVar23) = local_c0._4_4_;
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt %u state updated to %u\n",
                         "gsi_handle_ev_ctrl",0x1be,uVar25 & 0xffffffff);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt %u state updated to %u\n",
                         "gsi_handle_ev_ctrl",0x1be,uVar25 & 0xffffffff,
                         *(undefined4 *)(lVar24 + lVar23));
        }
      }
      complete(lVar24 + lVar23 + 0x80);
    }
    uVar25 = uVar25 + 1;
    lVar23 = lVar23 + 0x148;
  } while (uVar25 != 0x20);
LAB_00105620:
  lVar23 = sp_el0;
  if (*(long *)(lVar23 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_map_base @ 00105bc4 size=404
// signature: undefined gsi_map_base(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void gsi_map_base(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = param_1;
  if (gsi_ctx == (long *)0x0) {
    _printk(&DAT_00132af7,"gsi_map_base",0x50c);
    uVar2 = 0xfffffff8;
  }
  else {
    lVar1 = devm_ioremap(gsi_ctx[1],param_1,param_2);
    *gsi_ctx = lVar1;
    if (*gsi_ctx == 0) {
      _dev_err(gsi_ctx[1],"%s:%d failed to map access to GSI HW\n","gsi_map_base",0x514);
      if (gsi_ctx != (long *)0x0) {
        if (gsi_ctx[0xdfd] != 0) {
          ipc_log_string(gsi_ctx[0xdfd],"%s:%d failed to map access to GSI HW\n","gsi_map_base",
                         0x514);
        }
        if (gsi_ctx[0xdfe] != 0) {
          ipc_log_string(gsi_ctx[0xdfe],"%s:%d failed to map access to GSI HW\n","gsi_map_base",
                         0x514);
        }
      }
      uVar2 = 0xfffffffc;
    }
    else {
      if (gsi_ctx != (long *)0x0) {
        if (gsi_ctx[0xdfd] != 0) {
          ipc_log_string(gsi_ctx[0xdfd],"%s:%d GSI base(%pa) mapped to (%pK) with len (0x%x)\n",
                         "gsi_map_base",0x51b,&local_40,*gsi_ctx,param_2);
        }
        if (gsi_ctx[0xdfe] != 0) {
          ipc_log_string(gsi_ctx[0xdfe],"%s:%d GSI base(%pa) mapped to (%pK) with len (0x%x)\n",
                         "gsi_map_base",0x51b,&local_40,*gsi_ctx,param_2);
        }
      }
      gsihal_init(param_3,*gsi_ctx);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// gsi_unmap_base @ 00105d5c size=208
// signature: undefined gsi_unmap_base(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

undefined8 gsi_unmap_base(void)

{
  undefined8 uVar1;
  
  if (gsi_ctx == (long *)0x0) {
    _printk(&DAT_00132af7,"gsi_unmap_base",0x527);
    uVar1 = 0xfffffff8;
  }
  else if (*gsi_ctx == 0) {
    _dev_err(gsi_ctx[1],"%s:%d access to GSI HW has not been mapped\n","gsi_unmap_base",0x52c);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d access to GSI HW has not been mapped\n",
                       "gsi_unmap_base",0x52c);
      }
      if (gsi_ctx[0xdfe] != 0) {
        ipc_log_string(gsi_ctx[0xdfe],"%s:%d access to GSI HW has not been mapped\n",
                       "gsi_unmap_base",0x52c);
      }
    }
    uVar1 = 0xfffffffa;
  }
  else {
    devm_iounmap();
    uVar1 = 0;
    *gsi_ctx = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsi_register_device @ 00105e30 size=3140
// signature: undefined gsi_register_device(void)
// callers: []
//------------------------------------------------------------

int gsi_register_device(int *param_1,undefined8 *param_2)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  ulong uVar6;
  char *pcVar7;
  undefined8 uVar8;
  long *plVar9;
  undefined4 local_58 [2];
  char local_50 [8];
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_50[0] = '\0';
  local_58[0] = 0;
  if (gsi_ctx == (long *)0x0) {
    _printk(&DAT_00132af7,"gsi_register_device",0x5bc);
    iVar2 = -8;
    goto LAB_00106154;
  }
  if ((param_1 == (int *)0x0) || (param_2 == (undefined8 *)0x0)) {
    _dev_err(gsi_ctx[1],"%s:%d bad params props=%pK dev_hdl=%pK\n","gsi_register_device",0x5c1,
             param_1,param_2);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d bad params props=%pK dev_hdl=%pK\n",
                       "gsi_register_device",0x5c1,param_1,param_2);
      }
      if (gsi_ctx[0xdfe] != 0) {
        ipc_log_string(gsi_ctx[0xdfe],"%s:%d bad params props=%pK dev_hdl=%pK\n",
                       "gsi_register_device",0x5c1,param_1,param_2);
        iVar2 = -6;
        goto LAB_00106154;
      }
    }
  }
  else if (*param_1 - 0xeU < 0xfffffff3) {
    _dev_err(gsi_ctx[1],"%s:%d bad params gsi_ver=%d\n","gsi_register_device",0x5c6);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d bad params gsi_ver=%d\n","gsi_register_device",0x5c6,
                       *param_1);
      }
      lVar5 = gsi_ctx[0xdfe];
      if (lVar5 != 0) {
        iVar2 = *param_1;
        pcVar7 = "%s:%d bad params gsi_ver=%d\n";
        uVar8 = 0x5c6;
LAB_00105f18:
        ipc_log_string(lVar5,pcVar7,"gsi_register_device",uVar8,iVar2);
        iVar2 = -6;
        goto LAB_00106154;
      }
    }
  }
  else if (*(long *)(param_1 + 0x16) == 0) {
    _dev_err(gsi_ctx[1],"%s:%d notify callback must be provided\n","gsi_register_device",0x5cb);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d notify callback must be provided\n",
                       "gsi_register_device",0x5cb);
      }
      lVar5 = gsi_ctx[0xdfe];
      if (lVar5 != 0) {
        pcVar7 = "%s:%d notify callback must be provided\n";
        uVar8 = 0x5cb;
LAB_00106090:
        ipc_log_string(lVar5,pcVar7,"gsi_register_device",uVar8);
        iVar2 = -6;
        goto LAB_00106154;
      }
    }
  }
  else {
    if ((*(long *)(param_1 + 0x18) == 0) || (*(long *)(param_1 + 0x1a) != 0)) {
      if ((char)gsi_ctx[0x16] == '\0') {
        gsihal_destroy();
        gsi_unmap_base();
        plVar1 = gsi_ctx;
        plVar9 = gsi_ctx + 2;
        *(undefined4 *)(gsi_ctx + 0xdf2) = 0;
        memcpy(plVar9,param_1,0xa0);
        if (param_1[2] == 1) {
          if (param_1[6] == 0) {
            _dev_err(plVar1[1],"%s:%d bad irq specified %u\n","gsi_register_device",0x5e0,0);
            if (gsi_ctx != (long *)0x0) {
              if (gsi_ctx[0xdfd] != 0) {
                ipc_log_string(gsi_ctx[0xdfd],"%s:%d bad irq specified %u\n","gsi_register_device",
                               0x5e0,param_1[6]);
              }
              lVar5 = gsi_ctx[0xdfe];
              if (lVar5 != 0) {
                iVar2 = param_1[6];
                pcVar7 = "%s:%d bad irq specified %u\n";
                uVar8 = 0x5e0;
                goto LAB_00105f18;
              }
            }
            goto LAB_00106150;
          }
          uVar8 = 4;
          if (*(long *)(param_1 + 0x18) != 0) {
            uVar8 = 1;
          }
          iVar2 = devm_request_threaded_irq
                            (plVar1[1],param_1[6],gsi_isr,0,uVar8,&DAT_0011deeb,plVar1);
          if (iVar2 != 0) {
            _dev_err(gsi_ctx[1],"%s:%d failed to register isr for %u\n","gsi_register_device",0x610,
                     param_1[6]);
            if (gsi_ctx != (long *)0x0) {
              if (gsi_ctx[0xdfd] != 0) {
                ipc_log_string(gsi_ctx[0xdfd],"%s:%d failed to register isr for %u\n",
                               "gsi_register_device",0x610,param_1[6]);
              }
              if (gsi_ctx[0xdfe] != 0) {
                ipc_log_string(gsi_ctx[0xdfe],"%s:%d failed to register isr for %u\n",
                               "gsi_register_device",0x610,param_1[6]);
                iVar2 = -1;
                goto LAB_00106154;
              }
            }
            iVar2 = -1;
            goto LAB_00106154;
          }
          if (gsi_ctx != (long *)0x0) {
            if (gsi_ctx[0xdfd] != 0) {
              ipc_log_string(gsi_ctx[0xdfd],"%s:%d succeeded to register isr for %u\n",
                             "gsi_register_device",0x615,param_1[6]);
            }
            if (gsi_ctx[0xdfe] != 0) {
              ipc_log_string(gsi_ctx[0xdfe],"%s:%d succeeded to register isr for %u\n",
                             "gsi_register_device",0x615,param_1[6]);
            }
          }
          iVar2 = irq_set_irq_wake(param_1[6],1);
          if (iVar2 == 0) {
            _dev_err(gsi_ctx[1],"%s:%d GSI irq is wake enabled %u\n","gsi_register_device",0x61b,
                     param_1[6]);
            if (gsi_ctx != (long *)0x0) {
              if (gsi_ctx[0xdfd] != 0) {
                ipc_log_string(gsi_ctx[0xdfd],"%s:%d GSI irq is wake enabled %u\n",
                               "gsi_register_device",0x61b,param_1[6]);
              }
              lVar5 = gsi_ctx[0xdfe];
              if (lVar5 != 0) {
                iVar2 = param_1[6];
                pcVar7 = "%s:%d GSI irq is wake enabled %u\n";
                uVar8 = 0x61b;
LAB_0010646c:
                ipc_log_string(lVar5,pcVar7,"gsi_register_device",uVar8,iVar2);
              }
            }
          }
          else {
            _dev_err(gsi_ctx[1],"%s:%d failed to enable wake irq %u\n","gsi_register_device",0x619,
                     param_1[6]);
            if (gsi_ctx != (long *)0x0) {
              if (gsi_ctx[0xdfd] != 0) {
                ipc_log_string(gsi_ctx[0xdfd],"%s:%d failed to enable wake irq %u\n",
                               "gsi_register_device",0x619,param_1[6]);
              }
              lVar5 = gsi_ctx[0xdfe];
              if (lVar5 != 0) {
                iVar2 = param_1[6];
                pcVar7 = "%s:%d failed to enable wake irq %u\n";
                uVar8 = 0x619;
                goto LAB_0010646c;
              }
            }
          }
          if (((int)gsi_ctx[0xe01] == 0) || (iVar2 = __gsi_allocate_msis(), iVar2 == 0)) {
            if (*gsi_ctx == 0) {
              iVar2 = gsi_map_base(*(undefined8 *)(param_1 + 8),param_1[10],*param_1);
              if (iVar2 == 0) goto LAB_00106494;
            }
            else {
LAB_00106494:
              plVar9 = gsi_ctx + 0xdec;
              *(undefined1 *)(gsi_ctx + 0x16) = 1;
              __mutex_init(plVar9,"&gsi_ctx->mlock",&gsi_register_device___key);
              plVar9 = gsi_ctx;
              *(undefined4 *)((long)gsi_ctx + 0x6fa4) = 0;
              *(undefined4 *)(plVar9 + 0xdf5) = 0;
              iVar2 = gsi_get_max_channels((int)plVar9[2]);
              plVar9 = gsi_ctx;
              *(int *)(gsi_ctx + 0xdf8) = iVar2;
              if (iVar2 == 0) {
                gsi_unmap_base();
                plVar9 = gsi_ctx;
                *gsi_ctx = 0;
                plVar1 = gsi_ctx;
                plVar9[0xe0a] = 0;
                devm_free_irq(plVar1[1],param_1[6]);
                _dev_err(gsi_ctx[1],"%s:%d failed to get max channels\n","gsi_register_device",0x663
                        );
                if (gsi_ctx != (long *)0x0) {
                  if (gsi_ctx[0xdfd] != 0) {
                    ipc_log_string(gsi_ctx[0xdfd],"%s:%d failed to get max channels\n",
                                   "gsi_register_device",0x663);
                  }
                  if (gsi_ctx[0xdfe] != 0) {
                    ipc_log_string(gsi_ctx[0xdfe],"%s:%d failed to get max channels\n",
                                   "gsi_register_device",0x663);
                  }
                }
              }
              else {
                uVar6 = gsi_get_max_event_rings((int)plVar9[2]);
                plVar9 = gsi_ctx;
                uVar3 = (uint)uVar6;
                *(uint *)((long)gsi_ctx + 0x6fc4) = uVar3;
                if (uVar3 == 0) {
                  gsi_unmap_base();
                  plVar9 = gsi_ctx;
                  *gsi_ctx = 0;
                  plVar1 = gsi_ctx;
                  plVar9[0xe0a] = 0;
                  devm_free_irq(plVar1[1],param_1[6]);
                  _dev_err(gsi_ctx[1],"%s:%d failed to get max event rings\n","gsi_register_device",
                           0x66e);
                  if (gsi_ctx != (long *)0x0) {
                    if (gsi_ctx[0xdfd] != 0) {
                      ipc_log_string(gsi_ctx[0xdfd],"%s:%d failed to get max event rings\n",
                                     "gsi_register_device",0x66e);
                    }
                    if (gsi_ctx[0xdfe] != 0) {
                      ipc_log_string(gsi_ctx[0xdfe],"%s:%d failed to get max event rings\n",
                                     "gsi_register_device",0x66e);
                    }
                  }
                }
                else if (uVar3 < 0x20) {
                  if (((char)param_1[0x12] == '\0') || ((uint)param_1[0x13] <= uVar3 - 1)) {
                    uVar6 = -1L << (uVar6 & 0x3f);
                    plVar9[0xdf3] = uVar6;
                    if ((char)param_1[0x12] != '\0') {
                      plVar9[0xdf3] =
                           uVar6 | (long)(-1 << (ulong)(param_1[0x14] + 1U & 0x1f) ^
                                         -1 << (ulong)(param_1[0x13] & 0x1f));
                    }
                    __gsi_config_type_irq(param_1[1],0xffffffff);
                    if (*(uint *)(gsi_ctx + 2) < 10) {
                      __gsi_config_ch_irq(param_1[1],0xffffffff);
                      __gsi_config_evt_irq(param_1[1],0xffffffff);
                      __gsi_config_ieob_irq(param_1[1],0xffffffff,0xffffffff);
                    }
                    else {
                      __gsi_config_all_ch_irq();
                      __gsi_config_all_evt_irq(param_1[1],0xffffffff);
                      __gsi_config_all_ieob_irq(param_1[1],0xffffffff);
                    }
                    __gsi_config_glob_irq(param_1[1],0xffffffff,0xffffffff);
                    iVar2 = param_1[1];
                    uVar4 = gsihal_get_glob_irq_en_gp_int1_mask();
                    __gsi_config_glob_irq(iVar2,uVar4,0);
                    local_58[0] = 0x10101;
                    gsihal_write_reg_n_fields(5,*(undefined4 *)((long)gsi_ctx + 0x14),local_58);
                    gsihal_write_reg_nk(0x20,*(undefined4 *)((long)gsi_ctx + 0x14),0,param_1[2]);
                    if ((3 < *(uint *)(gsi_ctx + 2)) && (param_1[2] != 0)) {
                      gsihal_write_reg_nk(0x21,*(undefined4 *)((long)gsi_ctx + 0x14),0,0);
                      gsihal_write_reg_nk(0x22,*(undefined4 *)((long)gsi_ctx + 0x14),0,0);
                    }
                    gsihal_read_reg_n_fields(0x23,*(undefined4 *)((long)gsi_ctx + 0x14),local_50);
                    plVar9 = gsi_ctx;
                    if (local_50[0] == '\0') {
                      _dev_err(gsi_ctx[1],"%s:%d Manager EE has not enabled GSI, GSI un-usable\n",
                               "gsi_register_device",0x6bc);
                      plVar9 = gsi_ctx;
                      if (gsi_ctx != (long *)0x0) {
                        if (gsi_ctx[0xdfd] != 0) {
                          ipc_log_string(gsi_ctx[0xdfd],
                                         "%s:%d Manager EE has not enabled GSI, GSI un-usable\n",
                                         "gsi_register_device",0x6bc);
                        }
                        plVar9 = gsi_ctx;
                        if (gsi_ctx[0xdfe] != 0) {
                          ipc_log_string(gsi_ctx[0xdfe],
                                         "%s:%d Manager EE has not enabled GSI, GSI un-usable\n",
                                         "gsi_register_device",0x6bc);
                          plVar9 = gsi_ctx;
                        }
                      }
                    }
                    else {
                      *(undefined1 *)(gsi_ctx + 0xdf4) = 1;
                    }
                    if (1 < *(uint *)(plVar9 + 2)) {
                      gsihal_write_reg_nk(0xe,*(undefined4 *)((long)plVar9 + 0x14),0,0);
                      plVar9 = gsi_ctx;
                    }
                    iVar2 = 0;
                    *param_2 = plVar9;
                    *(undefined4 *)(gsi_ctx + 0xe4a) = 0;
                    goto LAB_00106154;
                  }
                  gsi_unmap_base();
                  plVar9 = gsi_ctx;
                  *gsi_ctx = 0;
                  plVar1 = gsi_ctx;
                  plVar9[0xe0a] = 0;
                  devm_free_irq(plVar1[1],param_1[6]);
                  _dev_err(gsi_ctx[1],"%s:%d MHI event ring start id %u is beyond max %u\n",
                           "gsi_register_device",0x681,param_1[0x13],
                           *(undefined4 *)((long)gsi_ctx + 0x6fc4));
                  if (gsi_ctx != (long *)0x0) {
                    if (gsi_ctx[0xdfd] != 0) {
                      ipc_log_string(gsi_ctx[0xdfd],
                                     "%s:%d MHI event ring start id %u is beyond max %u\n",
                                     "gsi_register_device",0x681,param_1[0x13],
                                     *(undefined4 *)((long)gsi_ctx + 0x6fc4));
                    }
                    if (gsi_ctx[0xdfe] != 0) {
                      ipc_log_string(gsi_ctx[0xdfe],
                                     "%s:%d MHI event ring start id %u is beyond max %u\n",
                                     "gsi_register_device",0x681,param_1[0x13],
                                     *(undefined4 *)((long)gsi_ctx + 0x6fc4));
                    }
                  }
                }
                else {
                  _dev_err(plVar9[1],"%s:%d max event rings are beyond absolute maximum\n",
                           "gsi_register_device",0x674);
                  if (gsi_ctx != (long *)0x0) {
                    if (gsi_ctx[0xdfd] != 0) {
                      ipc_log_string(gsi_ctx[0xdfd],
                                     "%s:%d max event rings are beyond absolute maximum\n",
                                     "gsi_register_device",0x674);
                    }
                    if (gsi_ctx[0xdfe] != 0) {
                      ipc_log_string(gsi_ctx[0xdfe],
                                     "%s:%d max event rings are beyond absolute maximum\n",
                                     "gsi_register_device",0x674);
                    }
                  }
                }
              }
              gsi_unmap_base();
              plVar9 = gsi_ctx;
              iVar2 = -1;
              gsi_ctx[0xe0a] = 0;
              *plVar9 = 0;
            }
            uVar3 = *(uint *)(gsi_ctx + 0xe01);
            plVar9 = gsi_ctx;
            if (uVar3 != 0) {
              platform_msi_domain_free_irqs(gsi_ctx[1]);
              plVar9 = gsi_ctx;
              memset(gsi_ctx + 0xe02,0,(ulong)uVar3 + 0x3f >> 3 & 0x3ffffff8);
            }
          }
          else {
            _dev_err(gsi_ctx[1],"%s:%d failed to allocate MSIs\n","gsi_register_device",0x625);
            if (gsi_ctx != (long *)0x0) {
              if (gsi_ctx[0xdfd] != 0) {
                ipc_log_string(gsi_ctx[0xdfd],"%s:%d failed to allocate MSIs\n",
                               "gsi_register_device",0x625);
              }
              if (gsi_ctx[0xdfe] != 0) {
                ipc_log_string(gsi_ctx[0xdfe],"%s:%d failed to allocate MSIs\n",
                               "gsi_register_device",0x625);
                iVar2 = 0;
                plVar9 = gsi_ctx;
                goto LAB_00106a54;
              }
            }
            iVar2 = 0;
            plVar9 = gsi_ctx;
          }
LAB_00106a54:
          devm_free_irq(plVar9[1],param_1[6],plVar9);
          goto LAB_00106154;
        }
        _dev_err(plVar1[1],"%s:%d do not support interrupt type %u\n","gsi_register_device",0x61e);
        if (gsi_ctx != (long *)0x0) {
          if (gsi_ctx[0xdfd] != 0) {
            ipc_log_string(gsi_ctx[0xdfd],"%s:%d do not support interrupt type %u\n",
                           "gsi_register_device",0x61e,param_1[2]);
          }
          if (gsi_ctx[0xdfe] != 0) {
            ipc_log_string(gsi_ctx[0xdfe],"%s:%d do not support interrupt type %u\n",
                           "gsi_register_device",0x61e,param_1[2]);
          }
        }
      }
      else {
        _dev_err(gsi_ctx[1],"%s:%d per already registered\n","gsi_register_device",0x5d5);
        if (gsi_ctx != (long *)0x0) {
          if (gsi_ctx[0xdfd] != 0) {
            ipc_log_string(gsi_ctx[0xdfd],"%s:%d per already registered\n","gsi_register_device",
                           0x5d5);
          }
          if (gsi_ctx[0xdfe] != 0) {
            ipc_log_string(gsi_ctx[0xdfe],"%s:%d per already registered\n","gsi_register_device",
                           0x5d5);
            iVar2 = -7;
            goto LAB_00106154;
          }
        }
      }
      iVar2 = -7;
      goto LAB_00106154;
    }
    _dev_err(gsi_ctx[1],"%s:%d rel callback  must be provided\n","gsi_register_device",0x5d0);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d rel callback  must be provided\n","gsi_register_device"
                       ,0x5d0);
      }
      lVar5 = gsi_ctx[0xdfe];
      if (lVar5 != 0) {
        pcVar7 = "%s:%d rel callback  must be provided\n";
        uVar8 = 0x5d0;
        goto LAB_00106090;
      }
    }
  }
LAB_00106150:
  iVar2 = -6;
LAB_00106154:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gsi_isr @ 00106a78 size=332
// signature: undefined gsi_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_isr(void)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  code *pcVar6;
  char local_2c [4];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  pcVar6 = *(code **)(gsi_ctx + 0x70);
  if (pcVar6 == (code *)0x0) {
    if (*(int *)(*(code **)(gsi_ctx + 0x88) + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106b20);
      (*pcVar6)();
    }
    iVar5 = (**(code **)(gsi_ctx + 0x88))();
    if (iVar5 == 0) {
      if (*(int *)(gsi_ctx + 0x7254) == 5) {
        if (*(int *)(*(code **)(gsi_ctx + 0x90) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106b68);
          (*pcVar6)();
        }
        (**(code **)(gsi_ctx + 0x90))();
      }
      piVar1 = (int *)(gsi_ctx + 0x7254);
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
      *(int *)(gsi_ctx + 0x7254) = 0;
      gsi_handle_irq();
    }
  }
  else {
    local_2c[0] = '\0';
    if (*(int *)(pcVar6 + -4) != -0x51dfd214) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106acc);
      (*pcVar6)();
    }
    (*pcVar6)(*(undefined8 *)(gsi_ctx + 0x80),local_2c);
    if (local_2c[0] != '\0') {
      gsi_handle_irq();
      if (*(int *)(*(code **)(gsi_ctx + 0x78) + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x106afc);
        (*pcVar6)();
      }
      (**(code **)(gsi_ctx + 0x78))(*(undefined8 *)(gsi_ctx + 0x80));
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// __gsi_allocate_msis @ 00106bcc size=1156
// signature: undefined __gsi_allocate_msis(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

undefined8 __gsi_allocate_msis(void)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d gsi_ctx->dev = %lu, gsi_ctx->msi.num = %d",
                     "__gsi_allocate_msis",0x581,*(undefined8 *)(gsi_ctx + 8),
                     *(undefined4 *)(gsi_ctx + 0x7008));
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d gsi_ctx->dev = %lu, gsi_ctx->msi.num = %d",
                     "__gsi_allocate_msis",0x581,*(undefined8 *)(gsi_ctx + 8),
                     *(undefined4 *)(gsi_ctx + 0x7008));
    }
  }
  iVar6 = platform_msi_domain_alloc_irqs
                    (*(undefined8 *)(gsi_ctx + 8),*(undefined4 *)(gsi_ctx + 0x7008),
                     __gsi_msi_write_msg);
  if (iVar6 == 0) {
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d MSI allocating is succesful\n",
                       "__gsi_allocate_msis",0x588);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d MSI allocating is succesful\n",
                       "__gsi_allocate_msis",0x588);
      }
    }
    if (*(int *)(gsi_ctx + 0x7008) != 0) {
      uVar9 = 0;
      do {
        uVar7 = msi_get_virq(*(undefined8 *)(gsi_ctx + 8),uVar9 & 0xffffffff);
        if (uVar9 == 2) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x107060);
          (*pcVar5)();
        }
        *(undefined4 *)(gsi_ctx + uVar9 * 4 + 0x7038) = uVar7;
        if ((*(ulong *)(gsi_ctx + (uVar9 >> 6) * 8 + 0x7010) >> (uVar9 & 0x3f) & 1) != 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d MSI %lu already allocated\n",
                   "__gsi_request_msi_irq",0x562,uVar9);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d MSI %lu already allocated\n",
                             "__gsi_request_msi_irq",0x562,uVar9);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d MSI %lu already allocated\n",
                             "__gsi_request_msi_irq",0x562,uVar9);
            }
          }
LAB_00106fa4:
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d error requesting IRQ for MSI %lu\n",
                   "__gsi_allocate_msis",0x5a3,uVar9);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d error requesting IRQ for MSI %lu\n",
                             "__gsi_allocate_msis",0x5a3,uVar9);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d error requesting IRQ for MSI %lu\n",
                             "__gsi_allocate_msis",0x5a3,uVar9);
            }
          }
          uVar2 = *(uint *)(gsi_ctx + 0x7008);
          platform_msi_domain_free_irqs(*(undefined8 *)(gsi_ctx + 8));
          memset((void *)(gsi_ctx + 0x7010),0,(ulong)uVar2 + 0x3f >> 3 & 0x3ffffff8);
          goto LAB_00107054;
        }
        iVar6 = devm_request_threaded_irq
                          (*(undefined8 *)(gsi_ctx + 8),
                           *(undefined4 *)(gsi_ctx + uVar9 * 4 + 0x7038),gsi_msi_isr,0,0,"gsi_msi");
        if (iVar6 != 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d failed to register msi irq %u idx %lu\n",
                   "__gsi_request_msi_irq",0x570,*(undefined4 *)(gsi_ctx + uVar9 * 4 + 0x7038),uVar9
                  );
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d failed to register msi irq %u idx %lu\n","__gsi_request_msi_irq"
                             ,0x570,*(undefined4 *)(gsi_ctx + uVar9 * 4 + 0x7038),uVar9);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d failed to register msi irq %u idx %lu\n","__gsi_request_msi_irq"
                             ,0x570,*(undefined4 *)(gsi_ctx + uVar9 * 4 + 0x7038),uVar9);
            }
          }
          goto LAB_00106fa4;
        }
        puVar1 = (ulong *)(gsi_ctx + 0x7010 + (uVar9 >> 6) * 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 1L << (uVar9 & 0x3f);
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Requesting IRQ succesful\n",
                           "__gsi_allocate_msis",0x5a7);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Requesting IRQ succesful\n",
                           "__gsi_allocate_msis",0x5a7);
          }
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(gsi_ctx + 0x7008));
    }
    uVar8 = 0;
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d error allocating platform MSIs - %d\n",
             "__gsi_allocate_msis",0x585,iVar6);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d error allocating platform MSIs - %d\n",
                       "__gsi_allocate_msis",0x585,iVar6);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d error allocating platform MSIs - %d\n",
                       "__gsi_allocate_msis",0x585,iVar6);
        return 0xffffffff;
      }
    }
LAB_00107054:
    uVar8 = 0xffffffff;
  }
  return uVar8;
}



//------------------------------------------------------------
// gsi_get_max_channels @ 00107060 size=436
// signature: undefined gsi_get_max_channels(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

undefined4 gsi_get_max_channels(undefined4 param_1)

{
  long lVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_40 = 0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  switch(param_1) {
  case 0:
  case 0xe:
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d GSI version is not supported %d\n",
             "gsi_get_max_channels",0x4aa,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI version is not supported %d\n",
                       "gsi_get_max_channels",0x4aa,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI version is not supported %d\n",
                       "gsi_get_max_channels",0x4aa,param_1);
      }
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x107210);
    (*pcVar3)();
  case 1:
    uVar4 = 0x1b;
    break;
  case 2:
    uVar4 = 0x1c;
    break;
  default:
    gsihal_read_reg_n_fields(0x1d,*(undefined4 *)(gsi_ctx + 0x14),&local_70);
    uVar2 = uStack_50._4_4_;
    goto joined_r0x00107114;
  }
  gsihal_read_reg_n_fields(uVar4,*(undefined4 *)(gsi_ctx + 0x14),&local_40);
  uVar2 = (undefined4)local_30;
joined_r0x00107114:
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d max channels %d\n","gsi_get_max_channels",
                     0x4be,uVar2);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d max channels %d\n","gsi_get_max_channels",
                     0x4be,uVar2);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// gsi_get_max_event_rings @ 00107220 size=472
// signature: undefined gsi_get_max_event_rings(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

undefined4 gsi_get_max_event_rings(undefined4 param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_40 = 0;
  local_48 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  switch(param_1) {
  case 0:
  case 0xe:
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d GSI version is not supported %d\n",
             "gsi_get_max_event_rings",0x4cd,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI version is not supported %d\n",
                       "gsi_get_max_event_rings",0x4cd,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI version is not supported %d\n",
                       "gsi_get_max_event_rings",0x4cd,param_1);
      }
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1073f4);
    (*pcVar2)();
  case 1:
    uVar3 = 0x1b;
    break;
  case 2:
    uVar3 = 0x1c;
    break;
  default:
    gsihal_read_reg_n_fields(0x1d,*(undefined4 *)(gsi_ctx + 0x14),&uStack_70);
    uVar4 = (undefined4)local_50;
    goto joined_r0x001072a0;
  case 10:
  case 0xb:
  case 0xc:
    gsihal_read_reg_n_fields(0x1e,*(undefined4 *)(gsi_ctx + 0x14),&local_78);
    uVar4 = local_78._4_4_;
joined_r0x001072a0:
    if (gsi_ctx == 0) goto LAB_00107348;
    goto LAB_001072fc;
  }
  gsihal_read_reg_n_fields(uVar3,*(undefined4 *)(gsi_ctx + 0x14),&local_40);
  uVar4 = uStack_30._4_4_;
  if (gsi_ctx != 0) {
LAB_001072fc:
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d max event rings %d\n",
                     "gsi_get_max_event_rings",0x4e8,uVar4);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d max event rings %d\n",
                     "gsi_get_max_event_rings",0x4e8,uVar4);
    }
  }
LAB_00107348:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// __gsi_config_type_irq @ 00107404 size=76
// signature: undefined __gsi_config_type_irq(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void __gsi_config_type_irq(undefined4 param_1,undefined4 param_2)

{
  gsihal_read_reg_nk(0,param_1,0);
  gsihal_write_reg_nk(0,param_1,0,param_2);
  return;
}



//------------------------------------------------------------
// __gsi_config_all_ch_irq @ 00107450 size=112
// signature: undefined __gsi_config_all_ch_irq(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void __gsi_config_all_ch_irq(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = gsihal_get_bit_map_array_size();
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      gsihal_read_reg_nk(0x7f,param_1,iVar2);
      gsihal_write_reg_nk(0x7f,param_1,iVar2,param_2);
      iVar2 = iVar2 + 1;
    } while (iVar1 != iVar2);
  }
  return;
}



//------------------------------------------------------------
// __gsi_config_all_evt_irq @ 001074c0 size=112
// signature: undefined __gsi_config_all_evt_irq(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void __gsi_config_all_evt_irq(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = gsihal_get_bit_map_array_size();
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      gsihal_read_reg_nk(0x80,param_1,iVar2);
      gsihal_write_reg_nk(0x80,param_1,iVar2,param_2);
      iVar2 = iVar2 + 1;
    } while (iVar1 != iVar2);
  }
  return;
}



//------------------------------------------------------------
// __gsi_config_all_ieob_irq @ 00107530 size=236
// signature: undefined __gsi_config_all_ieob_irq(void)
// callers: [gsi_register_device, gsi_deregister_device]
//------------------------------------------------------------

void __gsi_config_all_ieob_irq(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = gsihal_get_bit_map_array_size();
  if (iVar1 != 0) {
    iVar3 = 0;
    do {
      uVar2 = gsihal_read_reg_nk(0x84,param_1,iVar3);
      gsihal_write_reg_nk(0x84,param_1,iVar3,param_2);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n",
                         "__gsi_config_all_ieob_irq",0xaa,uVar2,param_2);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                         "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n",
                         "__gsi_config_all_ieob_irq",0xaa,uVar2,param_2);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 != iVar3);
  }
  return;
}



//------------------------------------------------------------
// __gsi_config_ch_irq @ 0010761c size=76
// signature: undefined __gsi_config_ch_irq(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void __gsi_config_ch_irq(undefined4 param_1,undefined4 param_2)

{
  gsihal_read_reg_nk(1,param_1,0);
  gsihal_write_reg_nk(1,param_1,0,param_2);
  return;
}



//------------------------------------------------------------
// __gsi_config_evt_irq @ 00107668 size=76
// signature: undefined __gsi_config_evt_irq(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void __gsi_config_evt_irq(undefined4 param_1,undefined4 param_2)

{
  gsihal_read_reg_nk(2,param_1,0);
  gsihal_write_reg_nk(2,param_1,0,param_2);
  return;
}



//------------------------------------------------------------
// __gsi_config_ieob_irq @ 001076b4 size=200
// signature: undefined __gsi_config_ieob_irq(void)
// callers: [gsi_register_device, gsi_config_channel_mode, gsi_alloc_evt_ring]
//------------------------------------------------------------

void __gsi_config_ieob_irq(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = gsihal_read_reg_nk(3,param_1,0);
  uVar1 = uVar2 & (param_2 ^ 0xffffffff) | param_3 & param_2;
  gsihal_write_reg_nk(3,param_1,0,uVar1);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                     "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n","__gsi_config_ieob_irq",
                     0x9b,uVar2,uVar1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n","__gsi_config_ieob_irq",
                     0x9b,uVar2,uVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// __gsi_config_glob_irq @ 0010777c size=96
// signature: undefined __gsi_config_glob_irq(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void __gsi_config_glob_irq(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = gsihal_read_reg_nk(4,param_1,0);
  gsihal_write_reg_nk(4,param_1,0,uVar1 & (param_2 ^ 0xffffffff) | param_3 & param_2);
  return;
}



//------------------------------------------------------------
// gsi_write_device_scratch @ 001077e0 size=640
// signature: undefined gsi_write_device_scratch(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_write_device_scratch(long param_1,char *param_2)

{
  uint uVar1;
  short sVar2;
  long lVar3;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_write_device_scratch",0x6ed);
    return 0xfffffff8;
  }
  if (*(char *)(gsi_ctx + 0xb0) == '\0') {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d no client registered\n","gsi_write_device_scratch",
             0x6f2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d no client registered\n",
                       "gsi_write_device_scratch",0x6f2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d no client registered\n",
                       "gsi_write_device_scratch",0x6f2);
        return 0xfffffffa;
      }
    }
  }
  else if (gsi_ctx == param_1) {
    if ((((param_2[2] == '\0') || (sVar2 = *(short *)(param_2 + 4), sVar2 == 0x40)) ||
        (sVar2 == 0x200)) || (sVar2 == 0x400)) {
      mutex_lock(gsi_ctx + 0x6f60);
      if (*param_2 != '\0') {
        *(char *)(gsi_ctx + 0x6faf) = param_2[1];
      }
      lVar3 = gsi_ctx;
      if (param_2[2] == '\0') {
        uVar1 = *(uint *)(gsi_ctx + 0x6fac);
      }
      else {
        uVar1 = *(uint *)(gsi_ctx + 0x6fac) & 0xffff0000 |
                *(uint *)(gsi_ctx + 0x6fac) & 0x7fff |
                (uint)(*(short *)(param_2 + 4) == 0x400) << 0xf;
        *(uint *)(gsi_ctx + 0x6fac) = uVar1;
      }
      gsihal_write_reg_nk(0x24,*(undefined4 *)(lVar3 + 0x14),0,uVar1);
      mutex_unlock(gsi_ctx + 0x6f60);
      return 0;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad USB max pkt size dev_hdl=0x%lx sz=%u\n",
             "gsi_write_device_scratch",0x701,param_1,sVar2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad USB max pkt size dev_hdl=0x%lx sz=%u\n","gsi_write_device_scratch"
                       ,0x701,param_1,*(undefined2 *)(param_2 + 4));
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d bad USB max pkt size dev_hdl=0x%lx sz=%u\n","gsi_write_device_scratch"
                       ,0x701,param_1,*(undefined2 *)(param_2 + 4));
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
             "gsi_write_device_scratch",0x6f8,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
                       "gsi_write_device_scratch",0x6f8,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
                       "gsi_write_device_scratch",0x6f8,param_1);
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_deregister_device @ 00107a64 size=1208
// signature: undefined gsi_deregister_device(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_deregister_device(long param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  long lVar7;
  int iVar8;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_deregister_device",0x71d);
    return 0xfffffff8;
  }
  if (*(char *)(gsi_ctx + 0xb0) == '\0') {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d no client registered\n","gsi_deregister_device",
             0x722);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d no client registered\n",
                       "gsi_deregister_device",0x722);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d no client registered\n",
                       "gsi_deregister_device",0x722);
        return 0xfffffffa;
      }
    }
  }
  else {
    if (gsi_ctx == param_1) {
      if ((param_2 & 1) == 0) {
        if (*(int *)(gsi_ctx + 0x6fa4) == 0) {
          if (*(int *)(gsi_ctx + 0x6fa8) == 0) goto LAB_00107ab4;
          _dev_err(*(undefined8 *)(gsi_ctx + 8),
                   "%s:%d cannot deregister %u events are still connected\n","gsi_deregister_device"
                   ,0x734,*(undefined4 *)(gsi_ctx + 0x6fa8));
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d cannot deregister %u events are still connected\n",
                             "gsi_deregister_device",0x734,*(undefined4 *)(gsi_ctx + 0x6fa8));
            }
            lVar4 = *(long *)(gsi_ctx + 0x6ff0);
            if (lVar4 != 0) {
              lVar7 = 0x6fa8;
              pcVar5 = "%s:%d cannot deregister %u events are still connected\n";
              uVar6 = 0x734;
              goto LAB_00107f04;
            }
          }
        }
        else {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),
                   "%s:%d cannot deregister %u channels are still connected\n",
                   "gsi_deregister_device",0x72e,*(int *)(gsi_ctx + 0x6fa4));
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d cannot deregister %u channels are still connected\n",
                             "gsi_deregister_device",0x72e,*(undefined4 *)(gsi_ctx + 0x6fa4));
            }
            lVar4 = *(long *)(gsi_ctx + 0x6ff0);
            if (lVar4 != 0) {
              lVar7 = 0x6fa4;
              pcVar5 = "%s:%d cannot deregister %u channels are still connected\n";
              uVar6 = 0x72e;
LAB_00107f04:
              ipc_log_string(lVar4,pcVar5,"gsi_deregister_device",uVar6,
                             *(undefined4 *)(gsi_ctx + lVar7));
              return 0xfffffff9;
            }
          }
        }
        return 0xfffffff9;
      }
LAB_00107ab4:
      uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
      gsihal_read_reg_nk(0,uVar1,0);
      gsihal_write_reg_nk(0,uVar1,0,0);
      uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
      if (*(uint *)(gsi_ctx + 0x10) < 10) {
        gsihal_read_reg_nk(1,uVar1,0);
        gsihal_write_reg_nk(1,uVar1,0,0);
        uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
        gsihal_read_reg_nk(2,uVar1,0);
        gsihal_write_reg_nk(2,uVar1,0,0);
        uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
        uVar3 = gsihal_read_reg_nk(3,uVar1,0);
        gsihal_write_reg_nk(3,uVar1,0,0);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n",
                           "__gsi_config_ieob_irq",0x9b,uVar3,0);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n",
                           "__gsi_config_ieob_irq",0x9b,uVar3,0);
          }
        }
      }
      else {
        iVar2 = gsihal_get_bit_map_array_size();
        if (iVar2 != 0) {
          iVar8 = 0;
          do {
            gsihal_read_reg_nk(0x7f,uVar1,iVar8);
            gsihal_write_reg_nk(0x7f,uVar1,iVar8,0);
            iVar8 = iVar8 + 1;
          } while (iVar2 != iVar8);
        }
        uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
        iVar2 = gsihal_get_bit_map_array_size();
        if (iVar2 != 0) {
          iVar8 = 0;
          do {
            gsihal_read_reg_nk(0x80,uVar1,iVar8);
            gsihal_write_reg_nk(0x80,uVar1,iVar8,0);
            iVar8 = iVar8 + 1;
          } while (iVar2 != iVar8);
        }
        __gsi_config_all_ieob_irq(*(undefined4 *)(gsi_ctx + 0x14),0);
      }
      uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
      gsihal_read_reg_nk(4,uVar1,0);
      gsihal_write_reg_nk(4,uVar1,0,0);
      uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
      gsihal_read_reg_nk(5,uVar1,0);
      gsihal_write_reg_nk(5,uVar1,0,0);
      if (*(int *)(gsi_ctx + 0x7008) != 0) {
        platform_msi_domain_free_irqs(*(undefined8 *)(gsi_ctx + 8));
      }
      devm_free_irq(*(undefined8 *)(gsi_ctx + 8),*(undefined4 *)(gsi_ctx + 0x28));
      *(undefined1 *)(gsi_ctx + 0xb0) = 0;
      return 0;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
             "gsi_deregister_device",0x728,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
                       "gsi_deregister_device",0x728,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params dev_hdl=0x%lx gsi_ctx=0x%pK\n",
                       "gsi_deregister_device",0x728,param_1);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_alloc_evt_ring @ 00107f20 size=3268
// signature: undefined gsi_alloc_evt_ring(void)
// callers: []
//------------------------------------------------------------

void gsi_alloc_evt_ring(int *param_1,ulong param_2,ulong *param_3)

{
  undefined8 *__s;
  int *piVar1;
  ulong *puVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  char cVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  ulong uVar16;
  code *pcVar17;
  byte *pbVar18;
  ulong uVar19;
  uint uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  long lVar24;
  undefined4 *puVar25;
  long local_70;
  long local_68;
  
  lVar24 = sp_el0;
  local_68 = *(long *)(lVar24 + 0x638);
  local_70 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_alloc_evt_ring",0x89f);
    uVar14 = 0xfffffff8;
    goto LAB_001084ec;
  }
  if (((param_1 == (int *)0x0) || (param_3 == (ulong *)0x0)) || (gsi_ctx != param_2)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),
             "%s:%d bad params props=%pK dev_hdl=0x%lx evt_ring_hdl=%pK\n","gsi_alloc_evt_ring",
             0x8a5,param_1,param_2,param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params props=%pK dev_hdl=0x%lx evt_ring_hdl=%pK\n",
                       "gsi_alloc_evt_ring",0x8a5,param_1,param_2,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d bad params props=%pK dev_hdl=0x%lx evt_ring_hdl=%pK\n",
                       "gsi_alloc_evt_ring",0x8a5,param_1,param_2,param_3);
        uVar14 = 0xfffffffa;
        goto LAB_001084ec;
      }
    }
  }
  else {
    iVar11 = gsi_validate_evt_ring_props(param_1);
    if (iVar11 == 0) {
      if ((char)param_1[0x1c] == '\0') {
        mutex_lock(gsi_ctx + 0x6f60);
        if (*(ulong *)(gsi_ctx + 0x6f98) != 0xffffffffffffffff) {
          uVar23 = ~*(ulong *)(gsi_ctx + 0x6f98);
          uVar23 = (uVar23 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar23 & 0x5555555555555555) << 1;
          uVar23 = (uVar23 & 0xcccccccccccccccc) >> 2 | (uVar23 & 0x3333333333333333) << 2;
          uVar23 = (uVar23 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar23 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar23 = (uVar23 & 0xff00ff00ff00ff00) >> 8 | (uVar23 & 0xff00ff00ff00ff) << 8;
          uVar23 = (uVar23 & 0xffff0000ffff0000) >> 0x10 | (uVar23 & 0xffff0000ffff) << 0x10;
          uVar23 = LZCOUNT(uVar23 >> 0x20 | uVar23 << 0x20);
          puVar2 = (ulong *)(gsi_ctx + 0x6f98);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar8 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar9) {
              *puVar2 = *puVar2 | 1L << (uVar23 & 0x3f);
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
          mutex_unlock(gsi_ctx + 0x6f60);
          goto joined_r0x00107ff8;
        }
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d failed to alloc event ID\n",
                 "gsi_alloc_evt_ring",0x8b3);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d failed to alloc event ID\n",
                           "gsi_alloc_evt_ring",0x8b3);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d failed to alloc event ID\n",
                           "gsi_alloc_evt_ring",0x8b3);
          }
        }
      }
      else {
        uVar23 = (ulong)*(byte *)((long)param_1 + 0x71);
joined_r0x00107ff8:
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Using %lu as virt evt id\n",
                           "gsi_alloc_evt_ring",0x8bc,uVar23);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Using %lu as virt evt id\n",
                           "gsi_alloc_evt_ring",0x8bc,uVar23);
          }
        }
        if (*(long *)(param_1 + 0x12) == 0) {
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d Using CONTEXT reg to read event RP for virt evt id: %lu\n",
                             "gsi_alloc_evt_ring",0x8c6,uVar23);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d Using CONTEXT reg to read event RP for virt evt id: %lu\n",
                             "gsi_alloc_evt_ring",0x8c6,uVar23);
            }
          }
          pcVar17 = gsi_read_event_ring_rp_reg;
        }
        else {
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d Using DDR to read event RP for virt evt id: %lu\n",
                             "gsi_alloc_evt_ring",0x8c0,uVar23);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d Using DDR to read event RP for virt evt id: %lu\n",
                             "gsi_alloc_evt_ring",0x8c0,uVar23);
            }
          }
          pcVar17 = gsi_read_event_ring_rp_ddr;
        }
        *(code **)(param_1 + 0x1e) = pcVar17;
        uVar22 = gsi_ctx;
        if (0x1f < uVar23) {
LAB_00108b54:
                    /* WARNING: Does not return */
          pcVar17 = (code *)SoftwareBreakpoint(0x5512,0x108b58);
          (*pcVar17)();
        }
        lVar24 = gsi_ctx + uVar23 * 0x148;
        __s = (undefined8 *)(lVar24 + 0x4798);
        memset(__s,0,0x148);
        __mutex_init(lVar24 + 0x4868,"&ctx->mlock",&gsi_alloc_evt_ring___key);
        *(undefined4 *)(lVar24 + 0x4898) = 0;
        __init_swait_queue_head(lVar24 + 0x48a0,"&x->wait",&init_completion___key);
        *(undefined4 *)(lVar24 + 0x48cc) = 0;
        *(undefined1 *)(lVar24 + 0x48c8) = 0;
        uVar20 = (uint)uVar23;
        pbVar18 = (byte *)(lVar24 + 0x481c);
        *pbVar18 = (byte)uVar23;
        mutex_lock(gsi_ctx + 0x6f60);
        if ((*param_1 == 2) && (param_1[1] == 0)) {
          if (((((int *)0xfffffffffffff000 < param_1) ||
               ((__s == (undefined8 *)0x0 ||
                ((undefined8 *)0xffffffffffffefff < __s && lVar24 != -0x5798)))) || (gsi_ctx == 0))
             || (0xfffffffffffff000 < gsi_ctx)) {
                    /* WARNING: Does not return */
            pcVar17 = (code *)SoftwareBreakpoint(0x800,0x108b5c);
            (*pcVar17)();
          }
          uVar16 = _find_first_zero_bit(gsi_ctx + 0x7018,*(undefined4 *)(gsi_ctx + 0x7008));
          if (uVar16 < *(uint *)(gsi_ctx + 0x7008)) {
            if ((*(ulong *)(gsi_ctx + ((ulong)(long)(int)uVar16 >> 6) * 8 + 0x7010) >>
                 (uVar16 & 0x3f) & 1) != 0) {
              if (1 < uVar16) goto LAB_00108b54;
              *(uint *)(gsi_ctx + uVar16 * 4 + 0x7040) = (uint)*pbVar18;
              bVar7 = *pbVar18;
              puVar2 = (ulong *)(gsi_ctx + 0x7048 + (ulong)(bVar7 >> 6) * 8);
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar8 = '\x01';
                bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar9) {
                  *puVar2 = *puVar2 | 1L << ((ulong)bVar7 & 0x3f);
                  cVar8 = ExclusiveMonitorsStatus();
                }
                uVar19 = gsi_ctx;
              } while (cVar8 != '\0');
              lVar21 = gsi_ctx + uVar16 * 0xc;
              param_1[9] = *(int *)(lVar21 + 0x7028);
              lVar21 = *(long *)(lVar21 + 0x7020);
              *(long *)(param_1 + 0xc) = lVar21;
              if (uVar19 != 0) {
                if (*(long *)(uVar19 + 0x6fe8) != 0) {
                  ipc_log_string(*(long *)(uVar19 + 0x6fe8),
                                 "%s:%d props->intvec = %d, props->msi_addr = %lu\n",
                                 "__gsi_pair_msi",0x888);
                  uVar19 = gsi_ctx;
                }
                if (*(long *)(uVar19 + 0x6ff0) != 0) {
                  ipc_log_string(*(long *)(uVar19 + 0x6ff0),
                                 "%s:%d props->intvec = %d, props->msi_addr = %lu\n",
                                 "__gsi_pair_msi",0x888,param_1[9],*(undefined8 *)(param_1 + 0xc));
                }
                lVar21 = *(long *)(param_1 + 0xc);
              }
              if (lVar21 == 0) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x800,0x108bbc);
                (*pcVar17)();
              }
              puVar2 = (ulong *)(gsi_ctx + 0x7018 + (uVar16 >> 6) * 8);
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar8 = '\x01';
                bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar9) {
                  *puVar2 = *puVar2 | 1L << (uVar16 & 0x3f);
                  cVar8 = ExclusiveMonitorsStatus();
                }
              } while (cVar8 != '\0');
              if (gsi_ctx != 0) {
                if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu pair MSI succesful\n"
                                 ,"gsi_alloc_evt_ring",0x8e0,uVar23);
                }
                if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu pair MSI succesful\n"
                                 ,"gsi_alloc_evt_ring",0x8e0,uVar23);
                }
              }
              goto LAB_001081ac;
            }
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d MSI %lu not allocated\n",
                               "__gsi_pair_msi",0x87a,uVar16);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d MSI %lu not allocated\n",
                               "__gsi_pair_msi",0x87a,uVar16);
              }
            }
          }
          else {
            _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d No free MSIs for evt %u\n","__gsi_pair_msi"
                     ,0x874,*pbVar18);
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d No free MSIs for evt %u\n",
                               "__gsi_pair_msi",0x874,*pbVar18);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d No free MSIs for evt %u\n",
                               "__gsi_pair_msi",0x874,*pbVar18);
              }
            }
          }
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu failed to pair MSI\n",
                   "gsi_alloc_evt_ring",0x8da,uVar23);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu failed to pair MSI\n",
                             "gsi_alloc_evt_ring",0x8da,uVar23);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu failed to pair MSI\n",
                             "gsi_alloc_evt_ring",0x8da,uVar23);
            }
          }
          if ((char)param_1[0x1c] == '\0') {
            puVar2 = (ulong *)(gsi_ctx + 0x6f98);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar8 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar9) {
                *puVar2 = *puVar2 & (1L << (uVar23 & 0x3f) ^ 0xffffffffffffffffU);
                cVar8 = ExclusiveMonitorsStatus();
              }
            } while (cVar8 != '\0');
          }
          mutex_unlock(gsi_ctx + 0x6f60);
          uVar14 = 0xfffffff8;
          goto LAB_001084ec;
        }
LAB_001081ac:
        uVar15 = *(undefined8 *)(param_1 + 6);
        uVar14 = *(undefined8 *)param_1;
        uVar3 = *(undefined8 *)(param_1 + 2);
        *(undefined8 *)(lVar24 + 0x47a8) = *(undefined8 *)(param_1 + 4);
        *(undefined8 *)(lVar24 + 0x47b0) = uVar15;
        *__s = uVar14;
        *(undefined8 *)(lVar24 + 0x47a0) = uVar3;
        uVar15 = *(undefined8 *)(param_1 + 0xe);
        local_70 = uVar23 << 0x20;
        uVar14 = *(undefined8 *)(param_1 + 8);
        uVar3 = *(undefined8 *)(param_1 + 10);
        *(undefined8 *)(lVar24 + 0x47c8) = *(undefined8 *)(param_1 + 0xc);
        *(undefined8 *)(lVar24 + 0x47d0) = uVar15;
        *(undefined8 *)(lVar24 + 0x47b8) = uVar14;
        *(undefined8 *)(lVar24 + 0x47c0) = uVar3;
        uVar15 = *(undefined8 *)(param_1 + 0x16);
        uVar14 = *(undefined8 *)(param_1 + 0x10);
        uVar3 = *(undefined8 *)(param_1 + 0x12);
        *(undefined8 *)(lVar24 + 0x47e8) = *(undefined8 *)(param_1 + 0x14);
        *(undefined8 *)(lVar24 + 0x47f0) = uVar15;
        *(undefined8 *)(lVar24 + 0x47d8) = uVar14;
        *(undefined8 *)(lVar24 + 0x47e0) = uVar3;
        uVar15 = *(undefined8 *)(param_1 + 0x1e);
        uVar14 = *(undefined8 *)(param_1 + 0x18);
        uVar3 = *(undefined8 *)(param_1 + 0x1a);
        *(undefined8 *)(lVar24 + 0x4808) = *(undefined8 *)(param_1 + 0x1c);
        *(undefined8 *)(lVar24 + 0x4810) = uVar15;
        uVar16 = gsi_ctx;
        *(undefined8 *)(lVar24 + 0x47f8) = uVar14;
        *(undefined8 *)(lVar24 + 0x4800) = uVar3;
        uVar4 = *(undefined4 *)(uVar16 + 0x14);
        gsihal_write_reg_n_fields(0x2f,uVar4,&local_70);
        iVar11 = wait_for_completion_timeout(lVar24 + 0x4898,0x4e2);
        if (iVar11 == 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu timed out\n","gsi_alloc_evt_ring",
                   0x8ea,uVar23);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu timed out\n",
                             "gsi_alloc_evt_ring",0x8ea,uVar23);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu timed out\n",
                             "gsi_alloc_evt_ring",0x8ea,uVar23);
            }
          }
          if ((char)param_1[0x1c] == '\0') {
            puVar2 = (ulong *)(gsi_ctx + 0x6f98);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar8 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar9) {
                *puVar2 = *puVar2 & (1L << (uVar23 & 0x3f) ^ 0xffffffffffffffffU);
                cVar8 = ExclusiveMonitorsStatus();
              }
            } while (cVar8 != '\0');
          }
          mutex_unlock(gsi_ctx + 0x6f60);
          uVar14 = 0xfffffff5;
          goto LAB_001084ec;
        }
        piVar1 = (int *)(uVar22 + uVar23 * 0x148 + 0x4818);
        if (*piVar1 == 1) {
          gsi_program_evt_ring_ctx(param_1,uVar23,*(undefined4 *)(gsi_ctx + 0x14));
          lVar24 = uVar22 + uVar23 * 0x148;
          puVar25 = (undefined4 *)(lVar24 + 0x4820);
          *puVar25 = 0;
          *(undefined8 *)(lVar24 + 0x4828) = *(undefined8 *)(param_1 + 6);
          lVar21 = *(long *)(param_1 + 4);
          *(long *)(lVar24 + 0x4830) = lVar21;
          *(long *)(lVar24 + 0x4838) = lVar21;
          *(long *)(lVar24 + 0x4840) = lVar21;
          *(long *)(lVar24 + 0x4848) = lVar21;
          *(long *)(lVar24 + 0x4850) = lVar21;
          uVar5 = param_1[3];
          *(uint *)(lVar24 + 0x4858) = uVar5;
          uVar6 = param_1[2];
          uVar22 = (ulong)uVar6 & 0xff;
          uVar10 = 0;
          if ((uint)uVar22 != 0) {
            uVar10 = uVar5 / (uint)uVar22;
          }
          *(ushort *)(lVar24 + 0x485e) = (ushort)(uVar10 - 1);
          *(byte *)(lVar24 + 0x485c) = (byte)uVar6;
          *(ulong *)(lVar24 + 0x4860) = uVar22 + uVar22 * (uVar10 - 1 & 0xffff) + lVar21;
          if (*(long **)(param_1 + 0x14) != (long *)0x0) {
            **(long **)(param_1 + 0x14) = lVar21;
          }
          *pbVar18 = (byte)uVar23;
          *param_3 = uVar23;
          piVar1 = (int *)(gsi_ctx + 0x6fa8);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar8 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar9) {
              *piVar1 = *piVar1 + 1;
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
          if (*param_1 == 4) {
            uVar14 = _raw_spin_lock_irqsave(puVar25);
            if (*(long *)(lVar24 + 0x4828) != 0) {
              memset(*(void **)(lVar24 + 0x4828),0,(ulong)*(uint *)(lVar24 + 0x4858));
            }
            lVar21 = *(long *)(lVar24 + 0x4830) +
                     ((ulong)*(ushort *)(lVar24 + 0x485e) + 2) * (ulong)*(byte *)(lVar24 + 0x485c);
            *(long *)(lVar24 + 0x4848) = lVar21;
            *(long *)(lVar24 + 0x4838) = lVar21;
            gsihal_write_reg_nk(0x11,*(undefined4 *)(gsi_ctx + 0x14),*pbVar18);
            _raw_spin_unlock_irqrestore(puVar25,uVar14);
          }
          else if (*param_1 == 2) {
            gsi_prime_evt_ring(__s);
          }
          mutex_unlock(gsi_ctx + 0x6f60);
          uVar14 = _raw_spin_lock_irqsave(gsi_ctx + 0x6f90);
          if (*(uint *)(gsi_ctx + 0x10) < 10) {
            uVar15 = 0x14;
            iVar11 = 1 << (ulong)(uVar20 & 0x1f);
            uVar12 = 0;
          }
          else {
            uVar12 = gsihal_get_ch_reg_idx(uVar23);
            iVar11 = gsihal_get_ch_reg_mask(uVar23);
            uVar15 = 0x85;
          }
          gsihal_write_reg_nk(uVar15,uVar4,uVar12,iVar11);
          if (*(uint *)(gsi_ctx + 0x10) < 10) {
            if ((*param_1 == 2) || (param_1[1] == 0)) {
              uVar4 = *(undefined4 *)(gsi_ctx + 0x14);
              uVar15 = 0xffffffff;
              uVar20 = (uint)*pbVar18;
            }
            else {
              uVar4 = *(undefined4 *)(gsi_ctx + 0x14);
              uVar15 = 0;
            }
            __gsi_config_ieob_irq(uVar4,1 << (ulong)(uVar20 & 0x1f),uVar15);
          }
          else if ((*param_1 == 2) || (param_1[1] == 0)) {
            uVar4 = *(undefined4 *)(gsi_ctx + 0x14);
            uVar12 = gsihal_get_ch_reg_idx(uVar23);
            uVar13 = gsihal_get_ch_reg_mask(uVar23);
            __gsi_config_ieob_irq_k(uVar4,uVar12,uVar13,0xffffffff);
          }
          else {
            uVar4 = *(undefined4 *)(gsi_ctx + 0x14);
            uVar12 = gsihal_get_ch_reg_idx(uVar23);
            uVar13 = gsihal_get_ch_reg_mask(uVar23);
            __gsi_config_ieob_irq_k(uVar4,uVar12,uVar13,0);
          }
          _raw_spin_unlock_irqrestore(gsi_ctx + 0x6f90,uVar14);
          uVar14 = 0;
          goto LAB_001084ec;
        }
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu allocation failed state=%u\n",
                 "gsi_alloc_evt_ring",0x8f3,uVar23);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d evt_id=%lu allocation failed state=%u\n","gsi_alloc_evt_ring",
                           0x8f3,uVar23,*piVar1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d evt_id=%lu allocation failed state=%u\n","gsi_alloc_evt_ring",
                           0x8f3,uVar23,*piVar1);
          }
        }
        if ((char)param_1[0x1c] == '\0') {
          puVar2 = (ulong *)(gsi_ctx + 0x6f98);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar8 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar9) {
              *puVar2 = *puVar2 & (1L << (uVar23 & 0x3f) ^ 0xffffffffffffffffU);
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
        }
      }
      mutex_unlock(gsi_ctx + 0x6f60);
      uVar14 = 0xfffffffc;
      goto LAB_001084ec;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid params\n","gsi_alloc_evt_ring",0x8aa);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid params\n","gsi_alloc_evt_ring",
                       0x8aa);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid params\n","gsi_alloc_evt_ring",
                       0x8aa);
        uVar14 = 0xfffffffa;
        goto LAB_001084ec;
      }
    }
  }
  uVar14 = 0xfffffffa;
LAB_001084ec:
  lVar24 = sp_el0;
  if (*(long *)(lVar24 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar14);
  }
  return;
}



//------------------------------------------------------------
// gsi_validate_evt_ring_props @ 00108c40 size=1124
// signature: undefined gsi_validate_evt_ring_props(void)
// callers: [gsi_set_evt_ring_cfg, gsi_alloc_evt_ring]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 gsi_validate_evt_ring_props(int *param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  ulong uVar8;
  byte bVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  
  iVar1 = param_1[2];
  switch(CONCAT44(iVar1,iVar1 + -4) >> 2 & 0xffffffff) {
  case 0:
    uVar10 = param_1[3];
    uVar7 = uVar10 & 3;
    break;
  case 1:
    uVar10 = param_1[3];
    uVar7 = uVar10 & 7;
    break;
  default:
    uVar10 = param_1[3];
    goto LAB_00108d38;
  case 3:
    uVar10 = param_1[3];
    uVar7 = uVar10 & 0xf;
    break;
  case 7:
    uVar10 = param_1[3];
    uVar7 = uVar10 & 0x1f;
  }
  if (uVar7 == 0) {
LAB_00108d38:
    uVar3 = gsihal_check_ring_length_valid(uVar10,iVar1);
    if ((uVar3 & 1) == 0) {
      return 0xfffffffa;
    }
    uVar8 = *(ulong *)(param_1 + 4);
    lVar4 = (ulong)(uint)param_1[3] - 1;
    uVar11 = 1L << (-LZCOUNT(lVar4) & 0x3fU);
    uVar12 = uVar11 & 0xffffffff;
    uVar3 = uVar11;
    if (lVar4 == 0) {
      uVar3 = 1;
      uVar12 = 1;
    }
    uVar2 = 0;
    if (uVar12 != 0) {
      uVar2 = uVar8 / uVar12;
    }
    if (uVar8 != uVar2 * uVar3) {
      if (lVar4 == 0) {
        uVar11 = 1;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),
               "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
               "gsi_validate_evt_ring_props",0x7f1,uVar8,uVar11);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        lVar4 = 1L << (-LZCOUNT((ulong)(uint)param_1[3] - 1) & 0x3fU);
        if ((ulong)(uint)param_1[3] - 1 == 0) {
          lVar4 = 1;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
                       "gsi_validate_evt_ring_props",0x7f1,*(undefined8 *)(param_1 + 4),lVar4);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0xfffffffa;
      }
      lVar4 = 1L << (-LZCOUNT((ulong)(uint)param_1[3] - 1) & 0x3fU);
      if ((ulong)(uint)param_1[3] - 1 == 0) {
        lVar4 = 1;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
                     "gsi_validate_evt_ring_props",0x7f1,*(undefined8 *)(param_1 + 4),lVar4);
      return 0xfffffffa;
    }
    if (*param_1 != 0) {
      if ((*param_1 == 2) && (*(long *)(param_1 + 6) == 0)) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d protocol %u requires ring base VA\n",
                 "gsi_validate_evt_ring_props",0x7f7,2);
        if (gsi_ctx == 0) {
          return 0xfffffffa;
        }
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d protocol %u requires ring base VA\n",
                         "gsi_validate_evt_ring_props",0x7f7,*param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
          return 0xfffffffa;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d protocol %u requires ring base VA\n",
                       "gsi_validate_evt_ring_props",0x7f7,*param_1);
        return 0xfffffffa;
      }
      if ((char)param_1[0x1c] != '\0') {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d protocol %u cannot specify evchid\n",
                 "gsi_validate_evt_ring_props",0x806);
        if (gsi_ctx == 0) {
          return 0xfffffffa;
        }
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d protocol %u cannot specify evchid\n",
                         "gsi_validate_evt_ring_props",0x806,*param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
          return 0xfffffffa;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d protocol %u cannot specify evchid\n",
                       "gsi_validate_evt_ring_props",0x806,*param_1);
        return 0xfffffffa;
      }
LAB_00108e48:
      if (*(long *)(param_1 + 0x18) != 0) {
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d err callback must be provided\n",
               "gsi_validate_evt_ring_props",0x80b);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d err callback must be provided\n",
                       "gsi_validate_evt_ring_props",0x80b);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0xfffffffa;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d err callback must be provided\n",
                     "gsi_validate_evt_ring_props",0x80b);
      return 0xfffffffa;
    }
    if ((char)param_1[0x1c] == '\0') {
      bVar9 = *(byte *)((long)param_1 + 0x71);
    }
    else {
      bVar9 = *(byte *)((long)param_1 + 0x71);
      if (((uint)bVar9 <= *(uint *)(gsi_ctx + 0x60)) &&
         (*(uint *)(gsi_ctx + 0x5c) < (uint)bVar9 || *(uint *)(gsi_ctx + 0x5c) == (uint)bVar9))
      goto LAB_00108e48;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d MHI requires evchid valid=%d val=%u\n",
             "gsi_validate_evt_ring_props",0x800,(char)param_1[0x1c],bVar9);
    if (gsi_ctx == 0) {
      return 0xfffffffa;
    }
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d MHI requires evchid valid=%d val=%u\n",
                     "gsi_validate_evt_ring_props",0x800,(char)param_1[0x1c],
                     *(undefined1 *)((long)param_1 + 0x71));
    }
    lVar4 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar4 == 0) {
      return 0xfffffffa;
    }
    uVar7 = (uint)*(byte *)(param_1 + 0x1c);
    pcVar5 = "%s:%d MHI requires evchid valid=%d val=%u\n";
    uVar10 = (uint)*(byte *)((long)param_1 + 0x71);
    uVar6 = 0x800;
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),
             "%s:%d bad params ring_len %u not a multiple of RE size %u\n",
             "gsi_validate_evt_ring_props",0x7e4);
    if (gsi_ctx == 0) {
      return 0xfffffffa;
    }
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                     "%s:%d bad params ring_len %u not a multiple of RE size %u\n",
                     "gsi_validate_evt_ring_props",0x7e4,param_1[3],param_1[2]);
    }
    lVar4 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar4 == 0) {
      return 0xfffffffa;
    }
    uVar10 = param_1[2];
    uVar7 = param_1[3];
    pcVar5 = "%s:%d bad params ring_len %u not a multiple of RE size %u\n";
    uVar6 = 0x7e4;
  }
  ipc_log_string(lVar4,pcVar5,"gsi_validate_evt_ring_props",uVar6,uVar7,uVar10);
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_read_event_ring_rp_ddr @ 001090a8 size=36
// signature: undefined gsi_read_event_ring_rp_ddr(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_read_event_ring_rp_ddr(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = readl_relaxed(*(undefined8 *)(param_1 + 0x50));
  return uVar1;
}



//------------------------------------------------------------
// gsi_read_event_ring_rp_reg @ 001090d0 size=88
// signature: undefined gsi_read_event_ring_rp_reg(void)
// callers: []
//------------------------------------------------------------

ulong gsi_read_event_ring_rp_reg(undefined8 param_1,undefined1 param_2,undefined4 param_3)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = gsihal_read_reg_nk(0x47,param_3,param_2);
  lVar2 = gsihal_read_reg_nk(0x48,param_3,param_2);
  return uVar1 & 0xffffffff | lVar2 << 0x20;
}



//------------------------------------------------------------
// gsi_program_evt_ring_ctx @ 00109128 size=584
// signature: undefined gsi_program_evt_ring_ctx(void)
// callers: [gsi_reset_evt_ring, gsi_alloc_evt_ring]
//------------------------------------------------------------

void gsi_program_evt_ring_ctx(int *param_1,undefined1 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  int *piVar3;
  int local_a0 [2];
  undefined4 local_98 [2];
  int local_90 [2];
  undefined4 local_88 [2];
  int local_80 [2];
  undefined4 local_78;
  uint local_74;
  uint uStack_70;
  int local_68 [2];
  undefined4 local_60 [2];
  int local_58 [2];
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  piVar3 = local_a0;
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  local_58[0] = 0;
  local_78 = 0;
  local_88[0] = 0;
  local_90[0] = 0;
  local_98[0] = 0;
  local_a0[0] = 0;
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d intf=%u intr=%u re=%u\n",
                     "gsi_program_evt_ring_ctx",0x75f,*param_1,param_1[1],param_1[2]);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d intf=%u intr=%u re=%u\n",
                     "gsi_program_evt_ring_ctx",0x75f,*param_1,param_1[1],param_1[2]);
    }
  }
  uStack_40 = CONCAT44(*param_1,(undefined4)uStack_40);
  local_48 = CONCAT44(local_48._4_4_,param_1[1]);
  local_50 = CONCAT44(local_50._4_4_,param_1[2]);
  gsihal_write_reg_nk_fields(0xc,param_3,param_2,&local_50);
  local_58[0] = param_1[3];
  gsihal_write_reg_nk_fields(0x25,param_3,param_2,local_58);
  local_60[0] = (undefined4)*(undefined8 *)(param_1 + 4);
  gsihal_write_reg_nk_fields(0x26,param_3,param_2,local_60);
  local_68[0] = param_1[5];
  gsihal_write_reg_nk_fields(0x27,param_3,param_2,local_68);
  local_74 = (uint)*(byte *)((long)param_1 + 0x22);
  uStack_70 = (uint)*(ushort *)(param_1 + 8);
  gsihal_write_reg_nk_fields(0x28,param_3,param_2,&local_78);
  local_80[0] = param_1[9];
  gsihal_write_reg_nk_fields(0x29,param_3,param_2,local_80);
  if (*param_1 == 0xf) {
    local_88[0] = (undefined4)*(undefined8 *)(param_1 + 0x12);
    gsihal_write_reg_nk_fields(0x2a,param_3,param_2,local_88);
    local_90[0] = param_1[0x13];
    piVar3 = local_90;
    uVar2 = 0x2b;
  }
  else {
    local_88[0] = (undefined4)*(undefined8 *)(param_1 + 0xc);
    gsihal_write_reg_nk_fields(0x2a,param_3,param_2,local_88);
    local_90[0] = param_1[0xd];
    gsihal_write_reg_nk_fields(0x2b,param_3,param_2,local_90);
    local_98[0] = (undefined4)*(undefined8 *)(param_1 + 0x12);
    gsihal_write_reg_nk_fields(0x2c,param_3,param_2,local_98);
    local_a0[0] = param_1[0x13];
    uVar2 = 0x2d;
  }
  gsihal_write_reg_nk_fields(uVar2,param_3,param_2,piVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_prime_evt_ring @ 00109370 size=216
// signature: undefined gsi_prime_evt_ring(void)
// callers: [gsi_reset_evt_ring, gsi_alloc_evt_ring]
//------------------------------------------------------------

void gsi_prime_evt_ring(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 local_40 [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x88);
  memset(*(void **)(param_1 + 0x90),0,(ulong)*(uint *)(param_1 + 0xc0));
  lVar1 = gsi_ctx;
  lVar3 = *(long *)(param_1 + 0x98) +
          (ulong)*(byte *)(param_1 + 0xc4) * (ulong)*(ushort *)(param_1 + 0xc6);
  *(long *)(param_1 + 0xb0) = lVar3;
  local_40[0] = (undefined4)((ulong)lVar3 >> 0x20);
  gsihal_write_reg_nk_fields
            (0x2e,*(undefined4 *)(lVar1 + 0x14),*(undefined1 *)(param_1 + 0x84),local_40);
  lVar1 = gsi_ctx;
  *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(param_1 + 0xb0);
  gsihal_write_reg_nk(0x11,*(undefined4 *)(lVar1 + 0x14),*(undefined1 *)(param_1 + 0x84));
  _raw_spin_unlock_irqrestore(param_1 + 0x88,uVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __gsi_config_ieob_irq_k @ 00109448 size=212
// signature: undefined __gsi_config_ieob_irq_k(void)
// callers: [gsi_config_channel_mode, gsi_alloc_evt_ring]
//------------------------------------------------------------

void __gsi_config_ieob_irq_k(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = gsihal_read_reg_nk(0x84,param_1,param_2);
  uVar1 = uVar2 & (param_3 ^ 0xffffffff) | param_4 & param_3;
  gsihal_write_reg_nk(0x84,param_1,param_2,uVar1);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                     "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n","__gsi_config_ieob_irq_k",
                     0xb7,uVar2,uVar1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d current IEO_IRQ_MSK: 0x%x, change to: 0x%x\n","__gsi_config_ieob_irq_k",
                     0xb7,uVar2,uVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_write_evt_ring_scratch @ 00109520 size=536
// signature: undefined gsi_write_evt_ring_scratch(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_write_evt_ring_scratch(ulong param_1,ulong param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_write_evt_ring_scratch",0x939);
    uVar3 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc4)) {
    if (0x1f < param_1) {
LAB_00109734:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x109738);
      (*pcVar2)();
    }
    if (*(int *)(gsi_ctx + param_1 * 0x148 + 0x4818) == 1) {
      lVar4 = gsi_ctx + param_1 * 0x148;
      lVar1 = lVar4 + 0x4868;
      mutex_lock(lVar1);
      *(ulong *)(lVar4 + 0x48d0) = param_2;
      gsihal_write_reg_nk(0x30,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                          param_2 & 0xffffffff);
      gsihal_write_reg_nk(0x31,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,param_2 >> 0x20)
      ;
      mutex_unlock(lVar1);
      uVar3 = 0;
    }
    else {
      if (0x1e < param_1) goto LAB_00109734;
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_write_evt_ring_scratch",
               0x946);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_write_evt_ring_scratch",0x946,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x148 + 0x4818));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_write_evt_ring_scratch",0x946,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x148 + 0x4818));
          return 0xfffffff9;
        }
      }
      uVar3 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n",
             "gsi_write_evt_ring_scratch",0x93e,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_write_evt_ring_scratch",0x93e,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_write_evt_ring_scratch",0x93e,param_1);
        return 0xfffffffa;
      }
    }
    uVar3 = 0xfffffffa;
  }
  return uVar3;
}



//------------------------------------------------------------
// gsi_dealloc_evt_ring @ 0010973c size=1604
// signature: undefined gsi_dealloc_evt_ring(void)
// callers: []
//------------------------------------------------------------

void gsi_dealloc_evt_ring(ulong param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  ulong *puVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 local_50;
  long local_48;
  
  lVar6 = gsi_ctx;
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  local_50 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_dealloc_evt_ring",0x95c);
    uVar9 = 0xfffffff8;
    goto LAB_001098a0;
  }
  if ((0x1e < param_1) || (*(uint *)(gsi_ctx + 0x6fc4) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n",
             "gsi_dealloc_evt_ring",0x962,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_dealloc_evt_ring",0x962,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_dealloc_evt_ring",0x962,param_1);
        uVar9 = 0xfffffffa;
        goto LAB_001098a0;
      }
    }
    uVar9 = 0xfffffffa;
    goto LAB_001098a0;
  }
  lVar11 = gsi_ctx + param_1 * 0x148;
  if (*(int *)(lVar11 + 0x48cc) == 0) {
    piVar1 = (int *)(gsi_ctx + param_1 * 0x148 + 0x4818);
    if (*piVar1 == 1) {
      if ((*(int *)(lVar11 + 0x4798) == 2) && (*(int *)(lVar11 + 0x479c) == 0)) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Interrupt dereg for msi_irq = %d\n",
                 "gsi_dealloc_evt_ring",0x976,*(undefined4 *)(lVar11 + 0x47c0));
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Interrupt dereg for msi_irq = %d\n",
                           "gsi_dealloc_evt_ring",0x976,*(undefined4 *)(lVar11 + 0x47c0));
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Interrupt dereg for msi_irq = %d\n",
                           "gsi_dealloc_evt_ring",0x976,*(undefined4 *)(lVar11 + 0x47c0));
          }
        }
        uVar12 = *(uint *)(gsi_ctx + 0x7008);
        if (uVar12 != 0) {
          uVar13 = 1L << (param_1 & 0x3f);
          if (*(int *)(gsi_ctx + 0x7028) == *(int *)(lVar11 + 0x47bc)) {
            mutex_lock(gsi_ctx + 0x6f60);
            puVar3 = (ulong *)(gsi_ctx + 0x7018);
            Hint_Prefetch(puVar3,2,0,1);
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
              if (bVar5) {
                *puVar3 = *puVar3 & 0xfffffffffffffffe;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            *(undefined4 *)(gsi_ctx + 0x7040) = 0;
            puVar3 = (ulong *)(gsi_ctx + 0x7048);
            Hint_Prefetch(puVar3,2,0,1);
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
              if (bVar5) {
                *puVar3 = *puVar3 & (uVar13 ^ 0xffffffffffffffff);
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            mutex_unlock(gsi_ctx + 0x6f60);
            uVar12 = *(uint *)(gsi_ctx + 0x7008);
          }
          if (1 < uVar12) {
            if (*(int *)(gsi_ctx + 0x7034) == *(int *)(lVar11 + 0x47bc)) {
              mutex_lock(gsi_ctx + 0x6f60);
              puVar3 = (ulong *)(gsi_ctx + 0x7018);
              Hint_Prefetch(puVar3,2,0,1);
              do {
                cVar4 = '\x01';
                bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar5) {
                  *puVar3 = *puVar3 & 0xfffffffffffffffd;
                  cVar4 = ExclusiveMonitorsStatus();
                }
              } while (cVar4 != '\0');
              *(undefined4 *)(gsi_ctx + 0x7044) = 0;
              puVar3 = (ulong *)(gsi_ctx + 0x7048);
              Hint_Prefetch(puVar3,2,0,1);
              do {
                cVar4 = '\x01';
                bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar5) {
                  *puVar3 = *puVar3 & (uVar13 ^ 0xffffffffffffffff);
                  cVar4 = ExclusiveMonitorsStatus();
                }
              } while (cVar4 != '\0');
              mutex_unlock(gsi_ctx + 0x6f60);
              uVar12 = *(uint *)(gsi_ctx + 0x7008);
            }
            if (2 < uVar12) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x109d04);
              (*pcVar7)();
            }
          }
        }
      }
      mutex_lock(gsi_ctx + 0x6f60);
      puVar2 = (undefined4 *)(lVar6 + param_1 * 0x148 + 0x4898);
      *puVar2 = 0;
      local_50 = CONCAT44((int)param_1,10);
      gsihal_write_reg_n_fields(0x2f,*(undefined4 *)(gsi_ctx + 0x14),&local_50);
      iVar8 = wait_for_completion_timeout(puVar2,0x4e2);
      if (iVar8 == 0) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu timed out\n","gsi_dealloc_evt_ring",
                 0x98b,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu timed out\n",
                           "gsi_dealloc_evt_ring",0x98b,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu timed out\n",
                           "gsi_dealloc_evt_ring",0x98b,param_1);
          }
        }
        mutex_unlock(gsi_ctx + 0x6f60);
        uVar9 = 0xfffffff5;
      }
      else {
        if (*piVar1 != 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu unexpected state=%u\n",
                   "gsi_dealloc_evt_ring",0x992,param_1);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu unexpected state=%u\n",
                             "gsi_dealloc_evt_ring",0x992,param_1,*piVar1);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu unexpected state=%u\n",
                             "gsi_dealloc_evt_ring",0x992,param_1,*piVar1);
            }
          }
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x109b74);
          (*pcVar7)();
        }
        mutex_unlock(gsi_ctx + 0x6f60);
        if (*(char *)(lVar11 + 0x4808) == '\0') {
          mutex_lock(gsi_ctx + 0x6f60);
          puVar3 = (ulong *)(gsi_ctx + 0x6f98);
          Hint_Prefetch(puVar3,2,0,1);
          do {
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
            if (bVar5) {
              *puVar3 = *puVar3 & (1L << (param_1 & 0x3f) ^ 0xffffffffffffffffU);
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          mutex_unlock(gsi_ctx + 0x6f60);
        }
        piVar1 = (int *)(gsi_ctx + 0x6fa8);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = *piVar1 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        uVar9 = 0;
      }
      goto LAB_001098a0;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_dealloc_evt_ring",0x96f);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_dealloc_evt_ring",
                       0x96f,*piVar1);
      }
      lVar11 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar11 != 0) {
        iVar8 = *piVar1;
        pcVar10 = "%s:%d bad state %d\n";
        uVar9 = 0x96f;
        goto LAB_00109a50;
      }
    }
  }
  else {
    piVar1 = (int *)(lVar11 + 0x48cc);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d %d channels still using this event ring\n",
             "gsi_dealloc_evt_ring",0x96a,*piVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d %d channels still using this event ring\n"
                       ,"gsi_dealloc_evt_ring",0x96a,*piVar1);
      }
      lVar11 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar11 != 0) {
        iVar8 = *piVar1;
        pcVar10 = "%s:%d %d channels still using this event ring\n";
        uVar9 = 0x96a;
LAB_00109a50:
        ipc_log_string(lVar11,pcVar10,"gsi_dealloc_evt_ring",uVar9,iVar8);
        uVar9 = 0xfffffff9;
        goto LAB_001098a0;
      }
    }
  }
  uVar9 = 0xfffffff9;
LAB_001098a0:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// gsi_query_evt_ring_db_addr @ 00109dd8 size=656
// signature: undefined gsi_query_evt_ring_db_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_query_evt_ring_db_addr(ulong param_1,int *param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_query_evt_ring_db_addr",0x9ac);
    return 0xfffffff8;
  }
  if ((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params msb=%pK lsb=%pK\n",
             "gsi_query_evt_ring_db_addr",0x9b2,param_3,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params msb=%pK lsb=%pK\n",
                       "gsi_query_evt_ring_db_addr",0x9b2,param_3,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params msb=%pK lsb=%pK\n",
                       "gsi_query_evt_ring_db_addr",0x9b2,param_3,param_2);
        return 0xfffffffa;
      }
    }
  }
  else {
    if (param_1 < *(uint *)(gsi_ctx + 0x6fc4)) {
      if (param_1 < 0x20) {
        if (*(int *)(gsi_ctx + param_1 * 0x148 + 0x4818) == 1) {
          iVar1 = *(int *)(gsi_ctx + 0x30);
          iVar3 = gsihal_get_reg_nk_ofst(0x11,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
          *param_2 = iVar3 + iVar1;
          iVar1 = *(int *)(gsi_ctx + 0x30);
          iVar3 = gsihal_get_reg_nk_ofst(0x2e,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
          *param_3 = iVar3 + iVar1;
          return 0;
        }
        if (param_1 < 0x1f) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_query_evt_ring_db_addr",
                   0x9bf);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                             "gsi_query_evt_ring_db_addr",0x9bf,
                             *(undefined4 *)(gsi_ctx + param_1 * 0x148 + 0x4818));
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                             "gsi_query_evt_ring_db_addr",0x9bf,
                             *(undefined4 *)(gsi_ctx + param_1 * 0x148 + 0x4818));
              return 0xfffffff9;
            }
          }
          return 0xfffffff9;
        }
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10a068);
      (*pcVar2)();
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n",
             "gsi_query_evt_ring_db_addr",0x9b7,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_query_evt_ring_db_addr",0x9b7,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_query_evt_ring_db_addr",0x9b7,param_1);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_ring_evt_ring_db @ 0010a06c size=472
// signature: undefined gsi_ring_evt_ring_db(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_ring_evt_ring_db(ulong param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_ring_evt_ring_db",0x9d2);
    uVar2 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc4)) {
    if (0x1f < param_1) {
LAB_0010a240:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a244);
      (*pcVar1)();
    }
    if (*(int *)(gsi_ctx + param_1 * 0x148 + 0x4818) == 1) {
      lVar3 = gsi_ctx + param_1 * 0x148;
      *(undefined8 *)(lVar3 + 0x4848) = param_2;
      *(undefined8 *)(lVar3 + 0x4838) = param_2;
      gsihal_write_reg_nk(0x11,*(undefined4 *)(gsi_ctx + 0x14),*(undefined1 *)(lVar3 + 0x481c),
                          param_2);
      uVar2 = 0;
    }
    else {
      if (0x1e < param_1) goto LAB_0010a240;
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_ring_evt_ring_db",0x9df);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_ring_evt_ring_db",
                         0x9df,*(undefined4 *)(gsi_ctx + param_1 * 0x148 + 0x4818));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_ring_evt_ring_db",
                         0x9df,*(undefined4 *)(gsi_ctx + param_1 * 0x148 + 0x4818));
          return 0xfffffff9;
        }
      }
      uVar2 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n",
             "gsi_ring_evt_ring_db",0x9d7,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_ring_evt_ring_db",0x9d7,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_ring_evt_ring_db",0x9d7,param_1);
        return 0xfffffffa;
      }
    }
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}



//------------------------------------------------------------
// gsi_ring_ch_ring_db @ 0010a248 size=540
// signature: undefined gsi_ring_ch_ring_db(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_ring_ch_ring_db(ulong param_1,ulong param_2)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  long lVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  lVar3 = gsi_ctx;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_ring_ch_ring_db",0x9ef);
    uVar5 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x24 < param_1) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10a464);
      (*pcVar4)();
    }
    lVar7 = gsi_ctx + param_1 * 0x1c0;
    if (*(int *)(lVar7 + 0x130) == 2) {
      lVar8 = gsi_ctx + param_1 * 0x1c0;
      *(ulong *)(lVar8 + 0x160) = param_2;
      gsihal_write_reg_nk(0x32,*(undefined4 *)(gsi_ctx + 0x14),*(undefined1 *)(lVar8 + 0xc0),
                          param_2 >> 0x20);
      lVar7 = gsi_ctx;
      lVar6 = *(long *)(lVar8 + 0x188);
      if ((lVar6 != 0) && (*(int *)(lVar8 + 0xbc) == 0)) {
        *(undefined8 *)(lVar6 + 0xa0) = *(undefined8 *)(lVar6 + 0xb0);
        gsihal_write_reg_nk(0x11,*(undefined4 *)(lVar7 + 0x14),*(undefined1 *)(lVar6 + 0x84));
      }
      uVar2 = *(undefined1 *)(lVar8 + 0xc0);
      *(undefined8 *)(lVar3 + param_1 * 0x1c0 + 0x150) = *(undefined8 *)(lVar8 + 0x160);
      gsihal_write_reg_nk(0x12,*(undefined4 *)(gsi_ctx + 0x14),uVar2);
      uVar5 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_ring_ch_ring_db",0x9fb);
      if (gsi_ctx != 0) {
        puVar1 = (undefined4 *)(lVar7 + 0x130);
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_ring_ch_ring_db",
                         0x9fb,*puVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_ring_ch_ring_db",
                         0x9fb,*puVar1);
          return 0xfffffff9;
        }
      }
      uVar5 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad chan_hdl=%lu\n","gsi_ring_ch_ring_db",0x9f4,
             param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad chan_hdl=%lu\n","gsi_ring_ch_ring_db",
                       0x9f4,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad chan_hdl=%lu\n","gsi_ring_ch_ring_db",
                       0x9f4,param_1);
        return 0xfffffffa;
      }
    }
    uVar5 = 0xfffffffa;
  }
  return uVar5;
}



//------------------------------------------------------------
// gsi_reset_evt_ring @ 0010a468 size=1244
// signature: undefined gsi_reset_evt_ring(void)
// callers: [gsi_set_evt_ring_cfg]
//------------------------------------------------------------

void gsi_reset_evt_ring(ulong param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  code *pcVar8;
  int iVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  int *piVar15;
  long lVar16;
  undefined4 local_70;
  undefined4 uStack_6c;
  long local_68;
  
  lVar7 = gsi_ctx;
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_reset_evt_ring",0xa13);
    uVar10 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc4)) {
    if (0x1f < param_1) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10a940);
      (*pcVar8)();
    }
    lVar12 = gsi_ctx + param_1 * 0x148;
    piVar1 = (int *)(lVar12 + 0x4798);
    piVar15 = (int *)(lVar12 + 0x4818);
    if (*piVar15 == 1) {
      mutex_lock(gsi_ctx + 0x6f60);
      puVar2 = (undefined4 *)(lVar7 + param_1 * 0x148 + 0x4898);
      *puVar2 = 0;
      uStack_6c = (undefined4)param_1;
      local_70 = 9;
      gsihal_write_reg_n_fields(0x2f,*(undefined4 *)(gsi_ctx + 0x14),&local_70);
      iVar9 = wait_for_completion_timeout(puVar2,0x4e2);
      if (iVar9 == 0) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu timed out\n","gsi_reset_evt_ring",
                 0xa2b,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu timed out\n",
                           "gsi_reset_evt_ring",0xa2b,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu timed out\n",
                           "gsi_reset_evt_ring",0xa2b,param_1);
          }
        }
        mutex_unlock(gsi_ctx + 0x6f60);
        uVar10 = 0xfffffff5;
      }
      else {
        if (*piVar15 != 1) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d evt_id=%lu unexpected state=%u\n",
                   "gsi_reset_evt_ring",0xa32,param_1);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d evt_id=%lu unexpected state=%u\n",
                             "gsi_reset_evt_ring",0xa32,param_1,*piVar15);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d evt_id=%lu unexpected state=%u\n",
                             "gsi_reset_evt_ring",0xa32,param_1,*piVar15);
            }
          }
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x800,0x10a92c);
          (*pcVar8)();
        }
        gsi_program_evt_ring_ctx(piVar1,param_1 & 0xffffffff,*(undefined4 *)(gsi_ctx + 0x14));
        uVar3 = *(uint *)(lVar12 + 0x47a0);
        uVar4 = *(uint *)(lVar12 + 0x47a4);
        lVar16 = lVar7 + param_1 * 0x148;
        uVar13 = (ulong)uVar3 & 0xff;
        uVar6 = 0;
        if ((uint)uVar13 != 0) {
          uVar6 = uVar4 / (uint)uVar13;
        }
        lVar11 = *(long *)(lVar12 + 0x47a8);
        uVar10 = *(undefined8 *)(lVar12 + 0x47b0);
        *(ushort *)(lVar16 + 0x485e) = (ushort)(uVar6 - 1);
        *(long *)(lVar16 + 0x4830) = lVar11;
        plVar14 = *(long **)(lVar12 + 0x47e8);
        *(uint *)(lVar16 + 0x4858) = uVar4;
        *(undefined8 *)(lVar16 + 0x4828) = uVar10;
        *(long *)(lVar16 + 0x4838) = lVar11;
        *(long *)(lVar16 + 0x4840) = lVar11;
        *(long *)(lVar16 + 0x4848) = lVar11;
        *(long *)(lVar16 + 0x4850) = lVar11;
        *(byte *)(lVar16 + 0x485c) = (byte)uVar3;
        *(ulong *)(lVar16 + 0x4860) = uVar13 + uVar13 * (uVar6 - 1 & 0xffff) + lVar11;
        if (plVar14 != (long *)0x0) {
          *plVar14 = lVar11;
        }
        lVar12 = lVar7 + param_1 * 0x148;
        uVar5 = *(undefined4 *)(lVar12 + 0x48d4);
        gsihal_write_reg_nk(0x30,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                            *(undefined4 *)(lVar12 + 0x48d0));
        gsihal_write_reg_nk(0x31,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar5);
        iVar9 = *piVar1;
        if (iVar9 == 2) {
          gsi_prime_evt_ring(piVar1);
          iVar9 = *piVar1;
        }
        if (iVar9 == 4) {
          lVar12 = lVar7 + param_1 * 0x148 + 0x4820;
          uVar10 = _raw_spin_lock_irqsave(lVar12);
          if (*(long *)(lVar16 + 0x4828) != 0) {
            memset(*(void **)(lVar16 + 0x4828),0,(ulong)*(uint *)(lVar16 + 0x4858));
          }
          lVar11 = *(long *)(lVar16 + 0x4830) +
                   ((ulong)*(ushort *)(lVar16 + 0x485e) + 2) * (ulong)*(byte *)(lVar16 + 0x485c);
          *(long *)(lVar16 + 0x4848) = lVar11;
          *(long *)(lVar16 + 0x4838) = lVar11;
          gsihal_write_reg_nk(0x11,*(undefined4 *)(gsi_ctx + 0x14),
                              *(undefined1 *)(lVar7 + param_1 * 0x148 + 0x481c));
          _raw_spin_unlock_irqrestore(lVar12,uVar10);
        }
        mutex_unlock(gsi_ctx + 0x6f60);
        uVar10 = 0;
      }
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_reset_evt_ring",0xa1f);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_reset_evt_ring",
                         0xa1f,*piVar15);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_reset_evt_ring",
                         0xa1f,*piVar15);
          uVar10 = 0xfffffff9;
          goto LAB_0010a6cc;
        }
      }
      uVar10 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n","gsi_reset_evt_ring"
             ,0xa18,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_reset_evt_ring",0xa18,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_reset_evt_ring",0xa18,param_1);
        uVar10 = 0xfffffffa;
        goto LAB_0010a6cc;
      }
    }
    uVar10 = 0xfffffffa;
  }
LAB_0010a6cc:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// gsi_get_evt_ring_cfg @ 0010a948 size=704
// signature: undefined gsi_get_evt_ring_cfg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_get_evt_ring_cfg(ulong param_1,undefined8 *param_2,undefined8 *param_3)

{
  int *piVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_get_evt_ring_cfg",0xa50);
    return 0xfffffff8;
  }
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params props=%pK scr=%pK\n",
             "gsi_get_evt_ring_cfg",0xa55,param_2,param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params props=%pK scr=%pK\n",
                       "gsi_get_evt_ring_cfg",0xa55,param_2,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params props=%pK scr=%pK\n",
                       "gsi_get_evt_ring_cfg",0xa55,param_2,param_3);
        return 0xfffffffa;
      }
    }
  }
  else {
    if (param_1 < *(uint *)(gsi_ctx + 0x6fc4)) {
      if (0x1f < param_1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10ac08);
        (*pcVar2)();
      }
      piVar1 = (int *)(gsi_ctx + param_1 * 0x148 + 0x4818);
      if (*piVar1 != 0) {
        lVar6 = gsi_ctx + param_1 * 0x148;
        mutex_lock(lVar6 + 0x4868);
        uVar3 = *(undefined8 *)(lVar6 + 0x47b0);
        uVar4 = *(undefined8 *)(lVar6 + 0x47a0);
        uVar5 = *(undefined8 *)(lVar6 + 0x4798);
        param_2[2] = *(undefined8 *)(lVar6 + 0x47a8);
        param_2[3] = uVar3;
        *param_2 = uVar5;
        param_2[1] = uVar4;
        uVar3 = *(undefined8 *)(lVar6 + 0x47d0);
        uVar4 = *(undefined8 *)(lVar6 + 0x47c0);
        uVar5 = *(undefined8 *)(lVar6 + 0x47b8);
        param_2[6] = *(undefined8 *)(lVar6 + 0x47c8);
        param_2[7] = uVar3;
        param_2[4] = uVar5;
        param_2[5] = uVar4;
        uVar3 = *(undefined8 *)(lVar6 + 0x47f0);
        uVar4 = *(undefined8 *)(lVar6 + 0x47e0);
        uVar5 = *(undefined8 *)(lVar6 + 0x47d8);
        param_2[10] = *(undefined8 *)(lVar6 + 0x47e8);
        param_2[0xb] = uVar3;
        param_2[8] = uVar5;
        param_2[9] = uVar4;
        uVar3 = *(undefined8 *)(lVar6 + 0x4810);
        uVar4 = *(undefined8 *)(lVar6 + 0x4800);
        uVar5 = *(undefined8 *)(lVar6 + 0x47f8);
        param_2[0xe] = *(undefined8 *)(lVar6 + 0x4808);
        param_2[0xf] = uVar3;
        param_2[0xc] = uVar5;
        param_2[0xd] = uVar4;
        *param_3 = *(undefined8 *)(lVar6 + 0x48d0);
        mutex_unlock(lVar6 + 0x4868);
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_get_evt_ring_cfg",0xa61,0);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_get_evt_ring_cfg",
                         0xa61,*piVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_get_evt_ring_cfg",
                         0xa61,*piVar1);
          return 0xfffffff9;
        }
      }
      return 0xfffffff9;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n",
             "gsi_get_evt_ring_cfg",0xa5a,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_get_evt_ring_cfg",0xa5a,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_get_evt_ring_cfg",0xa5a,param_1);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_set_evt_ring_cfg @ 0010ac0c size=820
// signature: undefined gsi_set_evt_ring_cfg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_set_evt_ring_cfg(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  int *piVar10;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_set_evt_ring_cfg",0xa74);
    return 0xfffffff8;
  }
  if ((param_2 == (undefined8 *)0x0) ||
     (iVar5 = gsi_validate_evt_ring_props(param_2), lVar7 = gsi_ctx, iVar5 != 0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params props=%pK\n","gsi_set_evt_ring_cfg",
             0xa79,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params props=%pK\n",
                       "gsi_set_evt_ring_cfg",0xa79,param_2);
      }
      lVar7 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar7 != 0) {
        pcVar8 = "%s:%d bad params props=%pK\n";
        uVar6 = 0xa79;
        goto LAB_0010ae38;
      }
    }
  }
  else {
    if (param_1 < (undefined8 *)(ulong)*(uint *)(gsi_ctx + 0x6fc4)) {
      if ((undefined8 *)0x1f < param_1) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10af40);
        (*pcVar4)();
      }
      lVar9 = gsi_ctx + (long)param_1 * 0x148;
      piVar10 = (int *)(lVar9 + 0x4818);
      if (*piVar10 == 1) {
        if (*(char *)(lVar9 + 0x47f0) == *(char *)(param_2 + 0xb)) {
          lVar1 = gsi_ctx + (long)param_1 * 0x148 + 0x4868;
          mutex_lock(lVar1);
          uVar2 = param_2[3];
          uVar6 = *param_2;
          uVar3 = param_2[1];
          *(undefined8 *)(lVar9 + 0x47a8) = param_2[2];
          *(undefined8 *)(lVar9 + 0x47b0) = uVar2;
          *(undefined8 *)(lVar9 + 0x4798) = uVar6;
          *(undefined8 *)(lVar9 + 0x47a0) = uVar3;
          uVar2 = param_2[7];
          uVar6 = param_2[4];
          uVar3 = param_2[5];
          *(undefined8 *)(lVar9 + 0x47c8) = param_2[6];
          *(undefined8 *)(lVar9 + 0x47d0) = uVar2;
          *(undefined8 *)(lVar9 + 0x47b8) = uVar6;
          *(undefined8 *)(lVar9 + 0x47c0) = uVar3;
          uVar2 = param_2[0xb];
          uVar6 = param_2[8];
          uVar3 = param_2[9];
          *(undefined8 *)(lVar9 + 0x47e8) = param_2[10];
          *(undefined8 *)(lVar9 + 0x47f0) = uVar2;
          *(undefined8 *)(lVar9 + 0x47d8) = uVar6;
          *(undefined8 *)(lVar9 + 0x47e0) = uVar3;
          uVar2 = param_2[0xf];
          uVar6 = param_2[0xc];
          uVar3 = param_2[0xd];
          *(undefined8 *)(lVar9 + 0x4808) = param_2[0xe];
          *(undefined8 *)(lVar9 + 0x4810) = uVar2;
          *(undefined8 *)(lVar9 + 0x47f8) = uVar6;
          *(undefined8 *)(lVar9 + 0x4800) = uVar3;
          if (param_3 != (undefined8 *)0x0) {
            *(undefined8 *)(lVar7 + (long)param_1 * 0x148 + 0x48d0) = *param_3;
          }
          mutex_unlock(lVar1);
          uVar6 = gsi_reset_evt_ring(param_1);
          return uVar6;
        }
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d changing immutable fields not supported\n",
                 "gsi_set_evt_ring_cfg",0xa8a);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d changing immutable fields not supported\n","gsi_set_evt_ring_cfg",
                           0xa8a);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d changing immutable fields not supported\n","gsi_set_evt_ring_cfg",
                           0xa8a);
            return 0xfffffff9;
          }
        }
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_set_evt_ring_cfg",0xa85);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_set_evt_ring_cfg"
                           ,0xa85,*piVar10);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_set_evt_ring_cfg"
                           ,0xa85,*piVar10);
            return 0xfffffff9;
          }
        }
      }
      return 0xfffffff9;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params evt_ring_hdl=%lu\n",
             "gsi_set_evt_ring_cfg",0xa7e,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params evt_ring_hdl=%lu\n",
                       "gsi_set_evt_ring_cfg",0xa7e,param_1);
      }
      lVar7 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar7 != 0) {
        pcVar8 = "%s:%d bad params evt_ring_hdl=%lu\n";
        uVar6 = 0xa7e;
        param_2 = param_1;
LAB_0010ae38:
        ipc_log_string(lVar7,pcVar8,"gsi_set_evt_ring_cfg",uVar6,param_2);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_alloc_channel @ 0010af44 size=2568
// signature: undefined gsi_alloc_channel(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gsi_alloc_channel(uint *param_1,long param_2,ulong *param_3)

{
  undefined8 *__s;
  undefined4 *puVar1;
  int *piVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bVar6;
  undefined2 uVar7;
  char cVar8;
  bool bVar9;
  code *pcVar10;
  int iVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  undefined8 uVar17;
  long lVar18;
  undefined8 uVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  long local_70;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_alloc_channel",0xb4d);
    uVar19 = 0xfffffff8;
    goto LAB_0010b7e4;
  }
  if (((param_1 == (uint *)0x0) || (param_3 == (ulong *)0x0)) || (gsi_ctx != param_2)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params props=%pK dev_hdl=0x%lx chan_hdl=%pK\n",
             "gsi_alloc_channel",0xb53,param_1,param_2,param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params props=%pK dev_hdl=0x%lx chan_hdl=%pK\n","gsi_alloc_channel"
                       ,0xb53,param_1,param_2,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d bad params props=%pK dev_hdl=0x%lx chan_hdl=%pK\n","gsi_alloc_channel"
                       ,0xb53,param_1,param_2,param_3);
        uVar19 = 0xfffffffa;
        goto LAB_0010b7e4;
      }
    }
  }
  else {
    iVar11 = gsi_validate_channel_props(param_1);
    lVar20 = gsi_ctx;
    if (iVar11 == 0) {
      uVar14 = *(ulong *)(param_1 + 4);
      if (uVar14 != 0xffffffffffffffff) {
        if (*(uint *)(gsi_ctx + 0x6fc4) <= uVar14) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid evt ring=%lu\n","gsi_alloc_channel",
                   0xb5e);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid evt ring=%lu\n",
                             "gsi_alloc_channel",0xb5e,*(undefined8 *)(param_1 + 4));
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid evt ring=%lu\n",
                             "gsi_alloc_channel",0xb5e,*(undefined8 *)(param_1 + 4));
            }
          }
          goto LAB_0010b6a4;
        }
        if (0x1e < uVar14) goto LAB_0010b278;
        if (((*(int *)(gsi_ctx + uVar14 * 0x148 + 0x48cc) != 0) &&
            (*(char *)(gsi_ctx + uVar14 * 0x148 + 0x47f0) != '\0')) &&
           (**(int **)(gsi_ctx + uVar14 * 0x148 + 0x48b8) != 5)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),
                   "%s:%d evt ring=%lu exclusively used by ch_hdl=%pK\n","gsi_alloc_channel",0xb68,
                   uVar14,param_3);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d evt ring=%lu exclusively used by ch_hdl=%pK\n",
                             "gsi_alloc_channel",0xb68,*(undefined8 *)(param_1 + 4),param_3);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d evt ring=%lu exclusively used by ch_hdl=%pK\n",
                             "gsi_alloc_channel",0xb68,*(undefined8 *)(param_1 + 4),param_3);
              uVar19 = 0xfffffff9;
              goto LAB_0010b7e4;
            }
          }
          uVar19 = 0xfffffff9;
          goto LAB_0010b7e4;
        }
      }
      uVar14 = (ulong)(byte)param_1[2];
      if (0x24 < uVar14) goto LAB_0010b278;
      lVar22 = gsi_ctx + uVar14 * 0x1c0;
      if (*(char *)(lVar22 + 0x1e0) != '\0') {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan %d already allocated\n",
                 "gsi_alloc_channel",0xb6f,uVar14);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan %d already allocated\n",
                           "gsi_alloc_channel",0xb6f,(char)param_1[2]);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan %d already allocated\n",
                           "gsi_alloc_channel",0xb6f,(char)param_1[2]);
            uVar19 = 0xfffffff8;
            goto LAB_0010b7e4;
          }
        }
        uVar19 = 0xfffffff8;
        goto LAB_0010b7e4;
      }
      __s = (undefined8 *)(lVar22 + 0xb8);
      memset(__s,0,0x1c0);
      uVar4 = *param_1;
      if ((uVar4 < 0x10) && ((1 << (ulong)(uVar4 & 0x1f) & 0x8050U) != 0)) {
        uVar13 = param_1[6];
      }
      else {
        uVar13 = 0;
        if (param_1[6] != 0) {
          uVar13 = param_1[7] / param_1[6];
        }
      }
      lVar12 = (ulong)uVar13 * 0x10 + 0x110;
      if (uVar4 != 5) {
        lVar12 = (ulong)uVar13 * 0x10;
      }
      lVar12 = devm_kmalloc(*(undefined8 *)(lVar20 + 8),lVar12,0xdc0);
      if (lVar12 == 0) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d context not allocated\n","gsi_alloc_channel",
                 0xb87);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d context not allocated\n",
                           "gsi_alloc_channel",0xb87);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d context not allocated\n",
                           "gsi_alloc_channel",0xb87);
            uVar19 = 0xfffffffc;
            goto LAB_0010b7e4;
          }
        }
        uVar19 = 0xfffffffc;
        goto LAB_0010b7e4;
      }
      lVar21 = lVar20 + uVar14 * 0x1c0;
      __mutex_init(lVar21 + 400,"&ctx->mlock",&gsi_alloc_channel___key);
      *(undefined4 *)(lVar21 + 0x1c0) = 0;
      __init_swait_queue_head(lVar21 + 0x1c8,"&x->wait",&init_completion___key);
      *(undefined4 *)(lVar21 + 0x1e4) = 0;
      uVar19 = *(undefined8 *)(param_1 + 4);
      uVar17 = *(undefined8 *)param_1;
      *(undefined8 *)(lVar22 + 0xc0) = *(undefined8 *)(param_1 + 2);
      *(undefined8 *)(lVar22 + 200) = uVar19;
      *__s = uVar17;
      uVar17 = *(undefined8 *)(param_1 + 0xc);
      uVar19 = *(undefined8 *)(param_1 + 6);
      uVar3 = *(undefined8 *)(param_1 + 8);
      *(undefined8 *)(lVar22 + 0xe0) = *(undefined8 *)(param_1 + 10);
      *(undefined8 *)(lVar22 + 0xe8) = uVar17;
      *(undefined8 *)(lVar22 + 0xd0) = uVar19;
      *(undefined8 *)(lVar22 + 0xd8) = uVar3;
      uVar17 = *(undefined8 *)(param_1 + 0x14);
      uVar19 = *(undefined8 *)(param_1 + 0xe);
      uVar3 = *(undefined8 *)(param_1 + 0x10);
      *(undefined8 *)(lVar22 + 0x100) = *(undefined8 *)(param_1 + 0x12);
      *(undefined8 *)(lVar22 + 0x108) = uVar17;
      *(undefined8 *)(lVar22 + 0xf0) = uVar19;
      *(undefined8 *)(lVar22 + 0xf8) = uVar3;
      uVar17 = *(undefined8 *)(param_1 + 0x1c);
      uVar19 = *(undefined8 *)(param_1 + 0x16);
      uVar3 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 *)(lVar22 + 0x120) = *(undefined8 *)(param_1 + 0x1a);
      *(undefined8 *)(lVar22 + 0x128) = uVar17;
      lVar15 = gsi_ctx;
      *(undefined8 *)(lVar22 + 0x110) = uVar19;
      *(undefined8 *)(lVar22 + 0x118) = uVar3;
      if (*(int *)(lVar15 + 0x10) != 5) {
        local_70 = 0;
        mutex_lock(lVar15 + 0x6f60);
        if (0x23 < (ulong)(byte)param_1[2]) goto LAB_0010b278;
        lVar15 = gsi_ctx + (ulong)(byte)param_1[2] * 0x38;
        uVar5 = *(undefined4 *)(gsi_ctx + 0x14);
        *(long *)(lVar15 + 0x3fb8) = *(long *)(lVar15 + 0x3fb8) + 1;
        local_70 = (ulong)(byte)param_1[2] << 0x20;
        gsihal_write_reg_n_fields(0x37,uVar5,&local_70);
        iVar11 = wait_for_completion_timeout(lVar21 + 0x1c0,0x4e2);
        if (iVar11 == 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u timed out\n","gsi_alloc_channel",
                   0xb9b,(char)param_1[2]);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%u timed out\n",
                             "gsi_alloc_channel",0xb9b,(char)param_1[2]);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%u timed out\n",
                             "gsi_alloc_channel",0xb9b,(char)param_1[2]);
            }
          }
          uVar19 = 0xfffffff5;
        }
        else {
          lVar15 = lVar20 + uVar14 * 0x1c0;
          if (*(int *)(lVar15 + 0x130) == 1) goto LAB_0010b1cc;
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u allocation failed state=%d\n",
                   "gsi_alloc_channel",0xba2,(char)param_1[2]);
          if (gsi_ctx != 0) {
            puVar1 = (undefined4 *)(lVar15 + 0x130);
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d chan_hdl=%u allocation failed state=%d\n","gsi_alloc_channel",
                             0xba2,(char)param_1[2],*puVar1);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d chan_hdl=%u allocation failed state=%d\n","gsi_alloc_channel",
                             0xba2,(char)param_1[2],*puVar1);
            }
          }
          uVar19 = 0xfffffffc;
        }
        mutex_unlock(gsi_ctx + 0x6f60);
        devm_kfree(*(undefined8 *)(gsi_ctx + 8),lVar12);
        goto LAB_0010b7e4;
      }
      mutex_lock(lVar15 + 0x6f60);
      *(undefined4 *)(lVar20 + uVar14 * 0x1c0 + 0x130) = 1;
LAB_0010b1cc:
      mutex_unlock(gsi_ctx + 0x6f60);
      lVar15 = gsi_ctx;
      uVar13 = (uint)*(ulong *)(param_1 + 4);
      uVar4 = uVar13 & 0xff;
      if ((uVar13 - 0x1f & 0xff) < 0xe0) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid erindex %u\n","gsi_alloc_channel",0xbb0
                 ,uVar4);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid erindex %u\n",
                           "gsi_alloc_channel",0xbb0,uVar4);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid erindex %u\n",
                           "gsi_alloc_channel",0xbb0,uVar4);
          }
        }
        devm_kfree(*(undefined8 *)(gsi_ctx + 8),lVar12);
        uVar19 = 0xfffffffa;
        goto LAB_0010b7e4;
      }
      if (uVar4 < 0x1f) {
        uVar16 = *(ulong *)(param_1 + 4) & 0xff;
        lVar18 = gsi_ctx + uVar16 * 0x148;
        lVar21 = lVar20 + uVar14 * 0x1c0;
        *(long *)(lVar21 + 0x188) = lVar18 + 0x4798;
        if (1 < *(byte *)(lVar18 + 0x48c8)) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),
                   "%s:%d too many channels sharing the same event ring %u\n","gsi_alloc_channel",
                   0xbbb,uVar4);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d too many channels sharing the same event ring %u\n",
                             "gsi_alloc_channel",0xbbb,uVar4);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d too many channels sharing the same event ring %u\n",
                             "gsi_alloc_channel",0xbbb,uVar4);
            }
          }
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x10b89c);
          (*pcVar10)();
        }
        if (*param_1 != 5) {
          piVar2 = (int *)(lVar15 + uVar16 * 0x148 + 0x48cc);
          Hint_Prefetch(piVar2,2,0,1);
          do {
            cVar8 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar9) {
              *piVar2 = *piVar2 + 1;
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
          lVar15 = *(long *)(lVar21 + 0x188);
          if (*(char *)(lVar15 + 0x58) == '\0') {
            bVar6 = *(byte *)(lVar15 + 0x130);
            *(byte *)(lVar15 + 0x130) = bVar6 + 1;
          }
          else {
            if (*(int *)(lVar15 + 0x134) != 1) goto LAB_0010b34c;
            bVar6 = *(byte *)(lVar15 + 0x130);
            *(byte *)(lVar15 + 0x130) = bVar6 + 1;
          }
          if (1 < bVar6) {
LAB_0010b278:
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x10b27c);
            (*pcVar10)();
          }
          *(undefined8 **)(lVar15 + (ulong)bVar6 * 8 + 0x120) = __s;
        }
      }
LAB_0010b34c:
      gsi_program_chan_ctx(param_1,*(undefined4 *)(gsi_ctx + 0x14));
      lVar15 = lVar20 + uVar14 * 0x1c0;
      *(undefined4 *)(lVar15 + 0x138) = 0;
      *(undefined8 *)(lVar15 + 0x140) = *(undefined8 *)(param_1 + 0xe);
      lVar21 = *(long *)(param_1 + 10);
      *(long *)(lVar15 + 0x148) = lVar21;
      *(long *)(lVar15 + 0x150) = lVar21;
      *(long *)(lVar15 + 0x158) = lVar21;
      *(long *)(lVar15 + 0x160) = lVar21;
      *(long *)(lVar15 + 0x168) = lVar21;
      uVar4 = param_1[7];
      *(uint *)(lVar15 + 0x170) = uVar4;
      uVar16 = (ulong)param_1[6] & 0xff;
      *(char *)(lVar15 + 0x174) = (char)param_1[6];
      uVar13 = 0;
      if ((uint)uVar16 != 0) {
        uVar13 = uVar4 / (uint)uVar16;
      }
      uVar7 = (undefined2)(uVar13 - 1);
      *(undefined2 *)(lVar15 + 0x176) = uVar7;
      *(ulong *)(lVar15 + 0x178) = uVar16 + uVar16 * (uVar13 - 1 & 0xffff) + lVar21;
      if ((short)param_1[8] == 0) {
        *(undefined2 *)(lVar22 + 0xd8) = uVar7;
      }
      lVar20 = lVar20 + uVar14 * 0x1c0;
      *(long *)(lVar20 + 0x180) = lVar12;
      *param_3 = (ulong)(byte)param_1[2];
      *(undefined1 *)(lVar22 + 0x1e0) = 1;
      uVar14 = jiffies_to_msecs(_jiffies);
      *(ulong *)(lVar20 + 0x268) = uVar14 & 0xffffffff;
      piVar2 = (int *)(gsi_ctx + 0x6fa4);
      Hint_Prefetch(piVar2,2,0,1);
      do {
        cVar8 = '\x01';
        bVar9 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar9) {
          *piVar2 = *piVar2 + 1;
          cVar8 = ExclusiveMonitorsStatus();
        }
        lVar20 = gsi_ctx;
      } while (cVar8 != '\0');
      if (*param_1 == 5) {
        *(char *)(gsi_ctx + 0x6ff8) = (char)param_1[2];
        uVar19 = 0;
        *(char *)(lVar20 + 0x6ff9) = (char)*(undefined8 *)(param_1 + 4);
      }
      else {
        uVar19 = 0;
      }
      goto LAB_0010b7e4;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params\n","gsi_alloc_channel",0xb58);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params\n","gsi_alloc_channel",0xb58);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params\n","gsi_alloc_channel",0xb58);
        uVar19 = 0xfffffffa;
        goto LAB_0010b7e4;
      }
    }
  }
LAB_0010b6a4:
  uVar19 = 0xfffffffa;
LAB_0010b7e4:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar19;
}



//------------------------------------------------------------
// gsi_validate_channel_props @ 0010b95c size=1372
// signature: undefined gsi_validate_channel_props(void)
// callers: [gsi_set_channel_cfg, gsi_alloc_channel]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 gsi_validate_channel_props(uint *param_1)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  
  if ((uint)(byte)param_1[2] < *(uint *)(gsi_ctx + 0x6fc0)) {
    uVar8 = param_1[6];
    switch(uVar8) {
    case 4:
      uVar7 = param_1[7];
      uVar2 = uVar7 & 3;
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
switchD_0010b9b4_caseD_5:
      uVar7 = param_1[7];
      goto LAB_0010ba84;
    case 8:
      uVar7 = param_1[7];
      uVar2 = uVar7 & 7;
      break;
    case 0x10:
      uVar7 = param_1[7];
      uVar2 = uVar7 & 0xf;
      break;
    case 0x20:
      uVar7 = param_1[7];
      uVar2 = uVar7 & 0x1f;
      break;
    default:
      if (uVar8 != 0x40) goto switchD_0010b9b4_caseD_5;
      uVar7 = param_1[7];
      uVar2 = uVar7 & 0x3f;
    }
    if (uVar2 != 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),
               "%s:%d bad params ring_len %u not a multiple of re size %u\n",
               "gsi_validate_channel_props",0xb0d);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params ring_len %u not a multiple of re size %u\n",
                       "gsi_validate_channel_props",0xb0d,param_1[7],param_1[6]);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0xfffffffa;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d bad params ring_len %u not a multiple of re size %u\n",
                     "gsi_validate_channel_props",0xb0d,param_1[7],param_1[6]);
      return 0xfffffffa;
    }
LAB_0010ba84:
    uVar3 = gsihal_check_ring_length_valid(uVar7,uVar8);
    if ((uVar3 & 1) == 0) {
      return 0xfffffffa;
    }
    uVar9 = *(ulong *)(param_1 + 10);
    lVar4 = (ulong)param_1[7] - 1;
    uVar10 = 1L << (-LZCOUNT(lVar4) & 0x3fU);
    uVar11 = uVar10 & 0xffffffff;
    uVar3 = uVar10;
    if (lVar4 == 0) {
      uVar3 = 1;
      uVar11 = 1;
    }
    uVar1 = 0;
    if (uVar11 != 0) {
      uVar1 = uVar9 / uVar11;
    }
    if (uVar9 != uVar1 * uVar3) {
      if (lVar4 == 0) {
        uVar10 = 1;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),
               "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
               "gsi_validate_channel_props",0xb1a,uVar9,uVar10);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        lVar4 = 1L << (-LZCOUNT((ulong)param_1[7] - 1) & 0x3fU);
        if ((ulong)param_1[7] - 1 == 0) {
          lVar4 = 1;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
                       "gsi_validate_channel_props",0xb1a,*(undefined8 *)(param_1 + 10),lVar4);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0xfffffffa;
      }
      lVar4 = 1L << (-LZCOUNT((ulong)param_1[7] - 1) & 0x3fU);
      if ((ulong)param_1[7] - 1 == 0) {
        lVar4 = 1;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d bad params ring base not aligned 0x%llx align 0x%lx\n",
                     "gsi_validate_channel_props",0xb1a,*(undefined8 *)(param_1 + 10),lVar4);
      return 0xfffffffa;
    }
    if (((uVar9 + param_1[7]) - (ulong)param_1[6] ^ uVar9) >> 0x20 != 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d MSB is not fixed on ring base 0x%llx size 0x%x\n"
               ,"gsi_validate_channel_props",0xb25);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d MSB is not fixed on ring base 0x%llx size 0x%x\n",
                       "gsi_validate_channel_props",0xb25,*(undefined8 *)(param_1 + 10),param_1[7]);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0xfffffffa;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d MSB is not fixed on ring base 0x%llx size 0x%x\n",
                     "gsi_validate_channel_props",0xb25,*(undefined8 *)(param_1 + 10),param_1[7]);
      return 0xfffffffa;
    }
    if (*param_1 == 2) {
      if (*(long *)(param_1 + 0xe) == 0) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d protocol %u requires ring base VA\n",
                 "gsi_validate_channel_props",0xb2b,2);
        if (gsi_ctx == 0) {
          return 0xfffffffa;
        }
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d protocol %u requires ring base VA\n",
                         "gsi_validate_channel_props",0xb2b,*param_1);
        }
        lVar4 = *(long *)(gsi_ctx + 0x6ff0);
        if (lVar4 == 0) {
          return 0xfffffffa;
        }
        uVar8 = *param_1;
        pcVar5 = "%s:%d protocol %u requires ring base VA\n";
        uVar6 = 0xb2b;
        goto LAB_0010be9c;
      }
      if (0xf < (byte)param_1[0x12]) goto LAB_0010bd44;
      if (*(long *)(param_1 + 0x16) != 0) goto LAB_0010bb8c;
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d xfer callback must be provided\n",
               "gsi_validate_channel_props",0xb35);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d xfer callback must be provided\n",
                       "gsi_validate_channel_props",0xb35);
      }
      lVar4 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar4 == 0) {
        return 0xfffffffa;
      }
      pcVar5 = "%s:%d xfer callback must be provided\n";
      uVar6 = 0xb35;
    }
    else {
      if (0xf < (byte)param_1[0x12]) {
LAB_0010bd44:
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid channel low weight %u\n",
                 "gsi_validate_channel_props",0xb30);
        if (gsi_ctx == 0) {
          return 0xfffffffa;
        }
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid channel low weight %u\n",
                         "gsi_validate_channel_props",0xb30,(byte)param_1[0x12]);
        }
        lVar4 = *(long *)(gsi_ctx + 0x6ff0);
        if (lVar4 == 0) {
          return 0xfffffffa;
        }
        uVar8 = (uint)(byte)param_1[0x12];
        pcVar5 = "%s:%d invalid channel low weight %u\n";
        uVar6 = 0xb30;
        goto LAB_0010be9c;
      }
LAB_0010bb8c:
      if (*(long *)(param_1 + 0x18) != 0) {
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d err callback must be provided\n",
               "gsi_validate_channel_props",0xb3a);
      if (gsi_ctx == 0) {
        return 0xfffffffa;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d err callback must be provided\n",
                       "gsi_validate_channel_props",0xb3a);
      }
      lVar4 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar4 == 0) {
        return 0xfffffffa;
      }
      pcVar5 = "%s:%d err callback must be provided\n";
      uVar6 = 0xb3a;
    }
    ipc_log_string(lVar4,pcVar5,"gsi_validate_channel_props",uVar6);
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d ch_id %u invalid\n","gsi_validate_channel_props",
             0xafe);
    if (gsi_ctx == 0) {
      return 0xfffffffa;
    }
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch_id %u invalid\n",
                     "gsi_validate_channel_props",0xafe,(char)param_1[2]);
    }
    lVar4 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar4 == 0) {
      return 0xfffffffa;
    }
    uVar8 = (uint)(byte)param_1[2];
    pcVar5 = "%s:%d ch_id %u invalid\n";
    uVar6 = 0xafe;
LAB_0010be9c:
    ipc_log_string(lVar4,pcVar5,"gsi_validate_channel_props",uVar6,uVar8);
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_program_chan_ctx @ 0010beb8 size=536
// signature: undefined gsi_program_chan_ctx(void)
// callers: [gsi_reset_channel, gsi_set_channel_cfg, gsi_alloc_channel]
//------------------------------------------------------------

void gsi_program_chan_ctx(uint *param_1,ulong param_2,uint param_3)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  ulong uVar5;
  undefined8 local_80;
  uint local_78 [3];
  ulong local_6c;
  undefined4 local_64;
  uint local_60;
  uint uStack_5c;
  ulong local_58;
  undefined8 local_50;
  uint local_48;
  uint uStack_44;
  uint local_40;
  uint uStack_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  uStack_5c = *param_1;
  local_64 = 0;
  local_6c = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_80 = 0;
  if ((0xf < uStack_5c) || ((0xbbffU >> (ulong)(uStack_5c & 0x1f) & 1) == 0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Unsupported protocol %d\n","gsi_program_chan_ctx",
             0xacc);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Unsupported protocol %d\n",
                       "gsi_program_chan_ctx",0xacc,*param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Unsupported protocol %d\n",
                       "gsi_program_chan_ctx",0xacc,*param_1);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10c0cc);
    (*pcVar4)();
  }
  local_60 = param_1[1];
  uVar3 = param_1[2];
  uVar5 = param_2 & 0xffffffff;
  puVar1 = (uint *)((ulong)&local_80 | 4);
  if (*(uint *)(gsi_ctx + 0x10) < 10) {
    puVar1 = local_78 + 2;
  }
  local_78[0] = param_1[6];
  local_6c = (ulong)*(uint *)(&DAT_0011e080 + (long)(int)uStack_5c * 4);
  *puVar1 = param_3 & 0xff;
  gsihal_write_reg_nk_fields(8,param_2,(char)uVar3,local_78);
  local_80 = CONCAT44(local_80._4_4_,param_1[7]);
  gsihal_write_reg_nk_fields(0x34,uVar5,(char)param_1[2],&local_80);
  gsihal_write_reg_nk(0x35,uVar5,(char)param_1[2],param_1[10]);
  gsihal_write_reg_nk(0x36,uVar5,(char)param_1[2],param_1[0xb]);
  uStack_44 = param_1[0x10];
  local_40 = param_1[0x11];
  local_58 = 0;
  local_50 = 0;
  uStack_3c = (uint)(byte)param_1[0x12];
  local_48 = 0;
  uVar3 = *(uint *)(gsi_ctx + 0x10);
  if (3 < uVar3) {
    if (uVar3 < 6) {
      local_48 = param_1[0x13];
    }
    else {
      local_50 = CONCAT44(param_1[0x13],(uint)(byte)param_1[0x14]);
      if ((7 < uVar3) && (local_58 = (ulong)(byte)param_1[0xc] << 0x20, 9 < uVar3)) {
        local_58 = (ulong)CONCAT14((byte)param_1[0xc],(uint)*(byte *)((long)param_1 + 0x31));
      }
    }
  }
  gsihal_write_reg_nk_fields(0x33,uVar5,(char)param_1[2],&local_58);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_write_channel_scratch3_reg @ 0010c0d8 size=328
// signature: undefined gsi_write_channel_scratch3_reg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_write_channel_scratch3_reg(ulong param_1,ulong param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_write_channel_scratch3_reg",0xc2c);
    uVar2 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x24 < param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10c220);
      (*pcVar1)();
    }
    lVar3 = gsi_ctx + param_1 * 0x1c0;
    mutex_lock(lVar3 + 400);
    *(ulong *)(lVar3 + 0x1f0) =
         (ulong)*(uint *)(lVar3 + 0x1f0) | (param_2 & 0xffff) << 0x20 | (param_2 >> 0x10) << 0x30;
    gsihal_write_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                        param_2 & 0xffffffff);
    mutex_unlock(lVar3 + 400);
    uVar2 = 0;
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_write_channel_scratch3_reg",0xc31,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_channel_scratch3_reg",0xc31,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_channel_scratch3_reg",0xc31,param_1);
      }
    }
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}



//------------------------------------------------------------
// gsi_write_channel_scratch2_reg @ 0010c224 size=344
// signature: undefined gsi_write_channel_scratch2_reg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_write_channel_scratch2_reg(ulong param_1,uint param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_write_channel_scratch2_reg",0xc49);
    uVar2 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x24 < param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10c37c);
      (*pcVar1)();
    }
    lVar4 = gsi_ctx + param_1 * 0x1c0;
    mutex_lock(lVar4 + 400);
    uVar3 = *(ulong *)(lVar4 + 0x1f0);
    *(ulong *)(lVar4 + 0x1f0) = uVar3 & 0xffffffff0000e01f | (ulong)(param_2 & 0xffff1fe0);
    gsihal_write_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                        param_2 & 0xffffffe0 | (uint)uVar3 & 0x1f);
    mutex_unlock(lVar4 + 400);
    uVar2 = 0;
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_write_channel_scratch2_reg",0xc4e,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_channel_scratch2_reg",0xc4e,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_channel_scratch2_reg",0xc4e,param_1);
      }
    }
    uVar2 = 0xfffffffa;
  }
  return uVar2;
}



//------------------------------------------------------------
// gsi_status_enabled @ 0010c380 size=108
// signature: undefined gsi_status_enabled(void)
// callers: []
//------------------------------------------------------------

void gsi_status_enabled(void)

{
  long lVar1;
  char local_20 [8];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20[0] = '\0';
  gsihal_read_reg_n_fields(0x23,*(undefined4 *)(gsi_ctx + 0x14),local_20);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_20[0] != '\0');
  }
  return;
}



//------------------------------------------------------------
// gsi_write_channel_scratch @ 0010c3f0 size=576
// signature: undefined gsi_write_channel_scratch(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_write_channel_scratch(ulong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 uVar6;
  long lVar7;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_write_channel_scratch",0xc8d);
    uVar6 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10c630);
      (*pcVar5)();
    }
    if ((*(uint *)(gsi_ctx + param_1 * 0x1c0 + 0x130) | 2) == 3) {
      lVar7 = gsi_ctx + param_1 * 0x1c0;
      mutex_lock(lVar7 + 400);
      uVar6 = param_2[1];
      uVar4 = param_2[2];
      *(undefined8 *)(lVar7 + 0x1e8) = *param_2;
      *(undefined8 *)(lVar7 + 0x1f0) = uVar6;
      *(undefined8 *)(lVar7 + 0x1f8) = uVar4;
      uVar2 = *(undefined4 *)((long)param_2 + 4);
      uVar1 = *(undefined4 *)(param_2 + 1);
      uVar3 = *(undefined4 *)((long)param_2 + 0xc);
      gsihal_write_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                          *(undefined4 *)param_2);
      gsihal_write_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar2);
      gsihal_write_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar1);
      gsihal_write_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar3);
      mutex_unlock(lVar7 + 400);
      uVar6 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_write_channel_scratch",0xc99
              );
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_write_channel_scratch",0xc99,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_write_channel_scratch",0xc99,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      uVar6 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_write_channel_scratch",0xc92,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_channel_scratch",0xc92,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_channel_scratch",0xc92,param_1);
        return 0xfffffffa;
      }
    }
    uVar6 = 0xfffffffa;
  }
  return uVar6;
}



//------------------------------------------------------------
// gsi_write_wdi3_channel_scratch2_reg @ 0010c634 size=488
// signature: undefined gsi_write_wdi3_channel_scratch2_reg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_write_wdi3_channel_scratch2_reg(ulong param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_write_wdi3_channel_scratch2_reg",0xcae);
    uVar3 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10c81c);
      (*pcVar2)();
    }
    if (*(int *)(gsi_ctx + param_1 * 0x1c0 + 0x130) - 1U < 3) {
      lVar4 = gsi_ctx + param_1 * 0x1c0;
      lVar1 = lVar4 + 400;
      mutex_lock(lVar1);
      *(undefined4 *)(lVar4 + 0x1f0) = param_2;
      gsihal_write_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,param_2);
      mutex_unlock(lVar1);
      uVar3 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n",
               "gsi_write_wdi3_channel_scratch2_reg",0xcbb);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_write_wdi3_channel_scratch2_reg",0xcbb,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_write_wdi3_channel_scratch2_reg",0xcbb,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      uVar3 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_write_wdi3_channel_scratch2_reg",0xcb3,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_wdi3_channel_scratch2_reg",0xcb3,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_write_wdi3_channel_scratch2_reg",0xcb3,param_1);
        return 0xfffffffa;
      }
    }
    uVar3 = 0xfffffffa;
  }
  return uVar3;
}



//------------------------------------------------------------
// gsi_read_channel_scratch @ 0010c820 size=548
// signature: undefined gsi_read_channel_scratch(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_read_channel_scratch(ulong param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_read_channel_scratch",0xcd1);
    uVar5 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10ca44);
      (*pcVar3)();
    }
    if (*(int *)(gsi_ctx + param_1 * 0x1c0 + 0x130) - 1U < 3) {
      lVar1 = gsi_ctx + param_1 * 0x1c0 + 400;
      mutex_lock(lVar1);
      uVar4 = gsihal_read_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      *param_2 = uVar4;
      uVar4 = gsihal_read_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      param_2[1] = uVar4;
      uVar4 = gsihal_read_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      lVar2 = gsi_ctx;
      param_2[2] = uVar4;
      uVar4 = gsihal_read_reg_nk(0x3b,*(undefined4 *)(lVar2 + 0x14),param_1 & 0xffffffff);
      param_2[3] = uVar4;
      mutex_unlock(lVar1);
      uVar5 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_read_channel_scratch",0xcde)
      ;
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_read_channel_scratch",0xcde,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_read_channel_scratch",0xcde,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      uVar5 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_read_channel_scratch",0xcd6,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_read_channel_scratch",0xcd6,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_read_channel_scratch",0xcd6,param_1);
        return 0xfffffffa;
      }
    }
    uVar5 = 0xfffffffa;
  }
  return uVar5;
}



//------------------------------------------------------------
// gsi_read_wdi3_channel_scratch2_reg @ 0010ca48 size=476
// signature: undefined gsi_read_wdi3_channel_scratch2_reg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_read_wdi3_channel_scratch2_reg(ulong param_1,undefined4 *param_2)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_read_wdi3_channel_scratch2_reg",0xcf2);
    uVar4 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10cc24);
      (*pcVar2)();
    }
    if (*(int *)(gsi_ctx + param_1 * 0x1c0 + 0x130) - 1U < 3) {
      lVar1 = gsi_ctx + param_1 * 0x1c0 + 400;
      mutex_lock(lVar1);
      uVar3 = gsihal_read_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      *param_2 = uVar3;
      mutex_unlock(lVar1);
      uVar4 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n",
               "gsi_read_wdi3_channel_scratch2_reg",0xcff);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_read_wdi3_channel_scratch2_reg",0xcff,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_read_wdi3_channel_scratch2_reg",0xcff,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      uVar4 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_read_wdi3_channel_scratch2_reg",0xcf7,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_read_wdi3_channel_scratch2_reg",0xcf7,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_read_wdi3_channel_scratch2_reg",0xcf7,param_1);
        return 0xfffffffa;
      }
    }
    uVar4 = 0xfffffffa;
  }
  return uVar4;
}



//------------------------------------------------------------
// gsi_update_mhi_channel_scratch @ 0010cc28 size=744
// signature: undefined gsi_update_mhi_channel_scratch(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_update_mhi_channel_scratch(ulong param_1,undefined8 param_2,ulong param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_update_mhi_channel_scratch",0xd14);
    uVar6 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10cf10);
      (*pcVar1)();
    }
    if ((*(uint *)(gsi_ctx + param_1 * 0x1c0 + 0x130) | 2) == 3) {
      lVar7 = gsi_ctx + param_1 * 0x1c0;
      mutex_lock(lVar7 + 400);
      uVar2 = gsihal_read_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      uVar3 = gsihal_read_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      uVar4 = gsihal_read_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      uVar5 = gsihal_read_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      uVar9 = uVar5 & 0xffffffff;
      uVar8 = param_3 & 0x100 | (ulong)(uVar4 & 0xfffffeff) | uVar5 << 0x20;
      if (*(uint *)(gsi_ctx + 0x10) < 6) {
        uVar8 = uVar8 & 0xffff0000ffff | param_3 & 0xffff0000ffff0000;
        uVar5 = uVar8 & 0xffffffff00000000;
        uVar9 = uVar8 >> 0x20;
      }
      else {
        uVar5 = uVar5 << 0x20;
      }
      gsihal_write_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar2);
      gsihal_write_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar3);
      gsihal_write_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                          uVar8 & 0xffffffff);
      gsihal_write_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar9);
      *(undefined4 *)(lVar7 + 0x1e8) = uVar2;
      *(undefined4 *)(lVar7 + 0x1ec) = uVar3;
      *(ulong *)(lVar7 + 0x1f0) = uVar8 & 0xffffffff | uVar5;
      *(undefined8 *)(lVar7 + 0x1f8) = 0;
      mutex_unlock(lVar7 + 400);
      uVar6 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_update_mhi_channel_scratch",
               0xd20);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_update_mhi_channel_scratch",0xd20,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_update_mhi_channel_scratch",0xd20,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      uVar6 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_update_mhi_channel_scratch",0xd19,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_update_mhi_channel_scratch",0xd19,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_update_mhi_channel_scratch",0xd19,param_1);
        return 0xfffffffa;
      }
    }
    uVar6 = 0xfffffffa;
  }
  return uVar6;
}



//------------------------------------------------------------
// gsi_query_channel_db_addr @ 0010cf14 size=636
// signature: undefined gsi_query_channel_db_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_query_channel_db_addr(ulong param_1,int *param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_query_channel_db_addr",0xd32);
    return 0xfffffff8;
  }
  if ((param_2 == (int *)0x0) || (param_3 == (int *)0x0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params msb=%pK lsb=%pK\n",
             "gsi_query_channel_db_addr",0xd38,param_3,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params msb=%pK lsb=%pK\n",
                       "gsi_query_channel_db_addr",0xd38,param_3,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params msb=%pK lsb=%pK\n",
                       "gsi_query_channel_db_addr",0xd38,param_3,param_2);
        return 0xfffffffa;
      }
    }
  }
  else {
    if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
      if (0x23 < param_1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10d190);
        (*pcVar2)();
      }
      if (*(int *)(gsi_ctx + param_1 * 0x1c0 + 0x130) != 0) {
        iVar1 = *(int *)(gsi_ctx + 0x30);
        iVar3 = gsihal_get_reg_nk_ofst(0x12,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
        *param_2 = iVar3 + iVar1;
        iVar1 = *(int *)(gsi_ctx + 0x30);
        iVar3 = gsihal_get_reg_nk_ofst(0x32,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
        *param_3 = iVar3 + iVar1;
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_query_channel_db_addr",0xd43
               ,0);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                         "gsi_query_channel_db_addr",0xd43,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                         "gsi_query_channel_db_addr",0xd43,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      return 0xfffffff9;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n",
             "gsi_query_channel_db_addr",0xd3d,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_query_channel_db_addr",0xd3d,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_query_channel_db_addr",0xd3d,param_1);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_pending_irq_type @ 0010d194 size=48
// signature: undefined gsi_pending_irq_type(void)
// callers: []
//------------------------------------------------------------

void gsi_pending_irq_type(void)

{
  gsihal_read_reg_nk(6,*(undefined4 *)(gsi_ctx + 0x14),0);
  return;
}



//------------------------------------------------------------
// gsi_start_channel @ 0010d1c8 size=1204
// signature: undefined gsi_start_channel(void)
// callers: []
//------------------------------------------------------------

void gsi_start_channel(ulong param_1)

{
  int *piVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar2 = gsi_ctx;
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_start_channel",0xd62);
    uVar5 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x24 < param_1) {
LAB_0010d674:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10d678);
      (*pcVar3)();
    }
    lVar8 = gsi_ctx + param_1 * 0x1c0;
    piVar1 = (int *)(lVar8 + 0x130);
    iVar4 = *(int *)(lVar8 + 0x130);
    if (iVar4 - 3U < 2 || iVar4 == 1) {
      mutex_lock(gsi_ctx + 0x6f60);
      lVar7 = lVar2 + param_1 * 0x1c0;
      *(undefined4 *)(lVar7 + 0x1c0) = 0;
      iVar4 = gsihal_read_reg_nk(0x20,*(undefined4 *)(gsi_ctx + 0x14),0);
      piVar6 = *(int **)(lVar7 + 0x188);
      if (((piVar6 != (int *)0x0) && (*piVar6 == 2)) && (iVar4 != 1)) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d GSI_EE_n_CNTXT_INTSET %d\n","gsi_start_channel"
                 ,0xd81,iVar4);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_CNTXT_INTSET %d\n",
                           "gsi_start_channel",0xd81,iVar4);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_CNTXT_INTSET %d\n",
                           "gsi_start_channel",0xd81,iVar4);
          }
        }
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10d568);
        (*pcVar3)();
      }
      if (0x23 < param_1) goto LAB_0010d674;
      lVar7 = gsi_ctx + param_1 * 0x38;
      *(long *)(lVar7 + 0x3fc0) = *(long *)(lVar7 + 0x3fc0) + 1;
      uStack_4c = (undefined4)param_1;
      local_50 = 1;
      gsihal_write_reg_n_fields(0x37,*(undefined4 *)(gsi_ctx + 0x14),&local_50);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d GSI Channel Start, waiting for completion\n","gsi_start_channel",
                         0xd8a);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                         "%s:%d GSI Channel Start, waiting for completion\n","gsi_start_channel",
                         0xd8a);
        }
      }
      gsi_channel_state_change_wait(param_1,lVar8 + 0xb8,1000,1);
      if ((*piVar1 != 2) && (*piVar1 != 5)) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan=%lu timed out, unexpected state=%u\n",
                 "gsi_start_channel",0xd96,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d chan=%lu timed out, unexpected state=%u\n","gsi_start_channel",
                           0xd96,param_1,*piVar1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d chan=%lu timed out, unexpected state=%u\n","gsi_start_channel",
                           0xd96,param_1,*piVar1);
          }
        }
        gsi_dump_ch_info(param_1);
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10d5f4);
        (*pcVar3)();
      }
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI Channel=%lu Start success\n",
                         "gsi_start_channel",0xd9b,param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI Channel=%lu Start success\n",
                         "gsi_start_channel",0xd9b,param_1);
        }
      }
      gsihal_write_reg_nk(0x32,*(undefined4 *)(gsi_ctx + 0x14),*(undefined1 *)(lVar8 + 0xc0),
                          *(undefined4 *)(lVar2 + param_1 * 0x1c0 + 0x164));
      mutex_unlock(gsi_ctx + 0x6f60);
    }
    else {
      if (iVar4 != 2) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_start_channel",0xd75);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_start_channel",
                           0xd75,*piVar1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_start_channel",
                           0xd75,*piVar1);
            uVar5 = 0xfffffff9;
            goto LAB_0010d3c0;
          }
        }
        uVar5 = 0xfffffff9;
        goto LAB_0010d3c0;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu already in started state\n",
                       "gsi_start_channel",0xd6e,param_1);
      }
      uVar5 = 0;
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) goto LAB_0010d3c0;
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu already in started state\n",
                     "gsi_start_channel",0xd6e,param_1);
    }
    uVar5 = 0;
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_start_channel",
             0xd67,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_start_channel",0xd67,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_start_channel",0xd67,param_1);
        uVar5 = 0xfffffffa;
        goto LAB_0010d3c0;
      }
    }
    uVar5 = 0xfffffffa;
  }
LAB_0010d3c0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// gsi_channel_state_change_wait @ 0010d67c size=824
// signature: undefined gsi_channel_state_change_wait(void)
// callers: [gsi_stop_channel, gsi_start_channel]
//------------------------------------------------------------

void gsi_channel_state_change_wait(ulong param_1,long param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  int local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  int local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  iVar9 = 0;
  iVar11 = 0;
  iVar12 = 0;
  local_70 = 0;
  local_80 = 0;
  local_78 = 0;
  iVar10 = 0;
  local_98 = 0;
  uStack_90 = 0;
  uVar1 = *(undefined4 *)(gsi_ctx + 0x14);
  local_88 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  do {
    uVar8 = __msecs_to_jiffies(param_3);
    iVar4 = wait_for_completion_timeout(param_2 + 0x108,uVar8);
    if (iVar4 != 0) goto LAB_0010d978;
    gsihal_read_reg_n_fields(6,uVar1,&local_88);
    if (*(uint *)(gsi_ctx + 0x10) < 10) {
      uVar8 = 7;
      uVar5 = 0;
    }
    else {
      uVar5 = gsihal_get_ch_reg_idx(param_1 & 0xffffffff);
      uVar8 = 0x7d;
    }
    uVar6 = gsihal_read_reg_nk(uVar8,uVar1,uVar5);
    if (*(int *)(gsi_ctx + 0x10) == 1) {
      gsihal_read_reg_nk_fields(8,uVar1,param_1 & 0xffffffff,&local_a8);
      iVar12 = local_a8._4_4_;
    }
    if (local_70 != 0) {
      uVar7 = gsihal_get_ch_reg_mask(param_1 & 0xffffffff);
      if ((uVar7 & uVar6) != 0) {
        gsihal_read_reg_nk_fields(8,uVar1,param_1 & 0xffffffff,&local_a8);
        iVar12 = local_a8._4_4_;
      }
    }
    if (param_4 == 2) {
      if (iVar12 == 4) {
        bVar3 = iVar11 != 0;
        iVar11 = iVar11 + 1;
        iVar4 = 0;
        if (bVar3 && iVar9 != 1) {
          iVar4 = iVar10;
        }
        if (iVar11 == 2) {
          iVar12 = 4;
          goto LAB_0010d970;
        }
      }
      else {
        if (iVar12 != 3) goto LAB_0010d80c;
        bVar3 = iVar9 != 0;
        iVar9 = iVar9 + 1;
        iVar4 = 0;
        if (iVar11 != 1 && bVar3) {
          iVar4 = iVar10;
        }
        if (iVar9 == 4) {
          if (*(uint *)(gsi_ctx + 0x10) < 10) {
            uVar8 = 9;
            uVar5 = 0;
          }
          else {
            uVar5 = gsihal_get_ch_reg_idx(param_1 & 0xffffffff);
            uVar8 = 0x81;
          }
          gsihal_write_reg_nk(uVar8,uVar1,uVar5,uVar6);
          iVar12 = 3;
          goto LAB_0010d970;
        }
      }
    }
    else {
      if ((param_4 == 1) && ((iVar12 == 2 || (iVar12 == 5)))) goto LAB_0010d970;
LAB_0010d80c:
      iVar4 = 0;
      if (iVar11 != 1 && iVar9 != 1) {
        iVar4 = iVar10;
      }
    }
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        local_c8 = local_88;
        uStack_c0 = local_80;
        local_b8 = local_78;
        local_b0 = local_70;
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d GSI wait on chan_hld=%lu irqtyp=%u state=%u intr=%u\n",
                       "gsi_channel_state_change_wait",0x140,param_1,&local_c8,
                       *(undefined4 *)(param_2 + 0x78),uVar6);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        local_c8 = local_88;
        uStack_c0 = local_80;
        local_b8 = local_78;
        local_b0 = local_70;
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d GSI wait on chan_hld=%lu irqtyp=%u state=%u intr=%u\n",
                       "gsi_channel_state_change_wait",0x140,param_1,&local_c8,
                       *(undefined4 *)(param_2 + 0x78),uVar6);
      }
    }
    iVar10 = iVar4 + 1;
  } while (iVar4 < 4);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                     "%s:%d invalidating the channel state when timeout happens\n",
                     "gsi_channel_state_change_wait",0x143);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d invalidating the channel state when timeout happens\n",
                     "gsi_channel_state_change_wait",0x143);
    }
  }
LAB_0010d970:
  *(int *)(param_2 + 0x78) = iVar12;
LAB_0010d978:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_dump_ch_info @ 0010d9b8 size=3632
// signature: undefined gsi_dump_ch_info(void)
// callers: [gsi_stop_channel, gsi_dump_ch, gsi_start_channel]
//------------------------------------------------------------

void gsi_dump_ch_info(ulong param_1)

{
  undefined4 uVar1;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_dump_ch_info",0xdac);
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    uVar1 = gsihal_read_reg_nk(8,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX0  0x%x\n","gsi_dump_ch_info",0xdb7,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX0  0x%x\n","gsi_dump_ch_info",
                       0xdb7,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX0  0x%x\n","gsi_dump_ch_info",
                       0xdb7,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x34,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX1  0x%x\n","gsi_dump_ch_info",0xdba,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX1  0x%x\n","gsi_dump_ch_info",
                       0xdba,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX1  0x%x\n","gsi_dump_ch_info",
                       0xdba,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x35,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX2  0x%x\n","gsi_dump_ch_info",0xdbd,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX2  0x%x\n","gsi_dump_ch_info",
                       0xdbd,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX2  0x%x\n","gsi_dump_ch_info",
                       0xdbd,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x36,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX3  0x%x\n","gsi_dump_ch_info",0xdc0,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX3  0x%x\n","gsi_dump_ch_info",
                       0xdc0,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX3  0x%x\n","gsi_dump_ch_info",
                       0xdc0,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x42,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX4  0x%x\n","gsi_dump_ch_info",0xdc3,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX4  0x%x\n","gsi_dump_ch_info",
                       0xdc3,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX4  0x%x\n","gsi_dump_ch_info",
                       0xdc3,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x43,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX5  0x%x\n","gsi_dump_ch_info",0xdc6,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX5  0x%x\n","gsi_dump_ch_info",
                       0xdc6,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX5  0x%x\n","gsi_dump_ch_info",
                       0xdc6,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x44,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX6  0x%x\n","gsi_dump_ch_info",0xdc9,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX6  0x%x\n","gsi_dump_ch_info",
                       0xdc9,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX6  0x%x\n","gsi_dump_ch_info",
                       0xdc9,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x45,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX7  0x%x\n","gsi_dump_ch_info",0xdcc,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX7  0x%x\n","gsi_dump_ch_info",
                       0xdcc,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX7  0x%x\n","gsi_dump_ch_info",
                       0xdcc,param_1,uVar1);
      }
    }
    if (9 < *(uint *)(gsi_ctx + 0x10)) {
      uVar1 = gsihal_read_reg_nk(0x46,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d CTX8  0x%x\n","gsi_dump_ch_info",0xdd0,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d CTX8  0x%x\n","gsi_dump_ch_info",
                         0xdd0,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d CTX8  0x%x\n","gsi_dump_ch_info",
                         0xdd0,param_1,uVar1);
        }
      }
    }
    uVar1 = gsihal_read_reg_nk(0x78,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d REFRP 0x%x\n","gsi_dump_ch_info",0xdd4,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d REFRP 0x%x\n","gsi_dump_ch_info",
                       0xdd4,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d REFRP 0x%x\n","gsi_dump_ch_info",
                       0xdd4,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x79,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d REFWP 0x%x\n","gsi_dump_ch_info",0xdd7,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d REFWP 0x%x\n","gsi_dump_ch_info",
                       0xdd7,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d REFWP 0x%x\n","gsi_dump_ch_info",
                       0xdd7,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x33,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d QOS   0x%x\n","gsi_dump_ch_info",0xdda,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d QOS   0x%x\n","gsi_dump_ch_info",
                       0xdda,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d QOS   0x%x\n","gsi_dump_ch_info",
                       0xdda,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR0  0x%x\n","gsi_dump_ch_info",0xddd,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR0  0x%x\n","gsi_dump_ch_info",
                       0xddd,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR0  0x%x\n","gsi_dump_ch_info",
                       0xddd,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR1  0x%x\n","gsi_dump_ch_info",0xde0,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR1  0x%x\n","gsi_dump_ch_info",
                       0xde0,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR1  0x%x\n","gsi_dump_ch_info",
                       0xde0,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR2  0x%x\n","gsi_dump_ch_info",0xde3,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR2  0x%x\n","gsi_dump_ch_info",
                       0xde3,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR2  0x%x\n","gsi_dump_ch_info",
                       0xde3,param_1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR3  0x%x\n","gsi_dump_ch_info",0xde6,
             param_1,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR3  0x%x\n","gsi_dump_ch_info",
                       0xde6,param_1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR3  0x%x\n","gsi_dump_ch_info",
                       0xde6,param_1,uVar1);
      }
    }
    if (9 < *(uint *)(gsi_ctx + 0x10)) {
      uVar1 = gsihal_read_reg_nk(0x3c,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR4  0x%x\n","gsi_dump_ch_info",0xdea,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR4  0x%x\n","gsi_dump_ch_info",
                         0xdea,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR4  0x%x\n","gsi_dump_ch_info",
                         0xdea,param_1,uVar1);
        }
      }
      uVar1 = gsihal_read_reg_nk(0x3d,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR5  0x%x\n","gsi_dump_ch_info",0xded,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR5  0x%x\n","gsi_dump_ch_info",
                         0xded,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR5  0x%x\n","gsi_dump_ch_info",
                         0xded,param_1,uVar1);
        }
      }
      uVar1 = gsihal_read_reg_nk(0x3e,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR6  0x%x\n","gsi_dump_ch_info",0xdf0,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR6  0x%x\n","gsi_dump_ch_info",
                         0xdf0,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR6  0x%x\n","gsi_dump_ch_info",
                         0xdf0,param_1,uVar1);
        }
      }
      uVar1 = gsihal_read_reg_nk(0x3f,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR7  0x%x\n","gsi_dump_ch_info",0xdf3,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR7  0x%x\n","gsi_dump_ch_info",
                         0xdf3,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR7  0x%x\n","gsi_dump_ch_info",
                         0xdf3,param_1,uVar1);
        }
      }
      uVar1 = gsihal_read_reg_nk(0x40,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR8  0x%x\n","gsi_dump_ch_info",0xdf6,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR8  0x%x\n","gsi_dump_ch_info",
                         0xdf6,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR8  0x%x\n","gsi_dump_ch_info",
                         0xdf6,param_1,uVar1);
        }
      }
      uVar1 = gsihal_read_reg_nk(0x41,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d CH%2d SCR9  0x%x\n","gsi_dump_ch_info",0xdf9,
               param_1,uVar1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d CH%2d SCR9  0x%x\n","gsi_dump_ch_info",
                         0xdf9,param_1,uVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d CH%2d SCR9  0x%x\n","gsi_dump_ch_info",
                         0xdf9,param_1,uVar1);
        }
      }
    }
  }
  else {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid chan id %u\n","gsi_dump_ch_info",
                     0xdb1,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid chan id %u\n","gsi_dump_ch_info",
                     0xdb1,param_1);
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_dump_ch_scratch @ 0010e7ec size=840
// signature: undefined gsi_dump_ch_scratch(void)
// callers: [gsi_dump_ch_scratch_info]
//------------------------------------------------------------

void gsi_dump_ch_scratch(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Dumping GSI channel scratch info for chan_hdl = %u\n"
           ,"gsi_dump_ch_scratch",0xe08,param_1);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                     "%s:%d Dumping GSI channel scratch info for chan_hdl = %u\n",
                     "gsi_dump_ch_scratch",0xe08,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d Dumping GSI channel scratch info for chan_hdl = %u\n",
                     "gsi_dump_ch_scratch",0xe08,param_1);
    }
  }
  if (*(int *)(*(code **)(gsi_ctx + 0x98) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10e8a0);
    (*pcVar3)();
  }
  (**(code **)(gsi_ctx + 0x98))();
  uVar4 = gsihal_read_reg_nk(0x3d,*(undefined4 *)(gsi_ctx + 0x14),param_1);
  if (uVar4 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Total aggregated frames %u\n","gsi_dump_ch_scratch"
             ,0xe0d,0);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Total aggregated frames %u\n",
                       "gsi_dump_ch_scratch",0xe0d,0);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Total aggregated frames %u\n",
                       "gsi_dump_ch_scratch",0xe0d,0);
      }
    }
    if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10e954);
      (*pcVar3)();
    }
    (**(code **)(gsi_ctx + 0xa0))();
  }
  else {
    iVar5 = gsihal_read_reg_nk(0x3e,*(undefined4 *)(gsi_ctx + 0x14),param_1);
    iVar6 = gsihal_read_reg_nk(0x3f,*(undefined4 *)(gsi_ctx + 0x14),param_1);
    if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10e9ac);
      (*pcVar3)();
    }
    (**(code **)(gsi_ctx + 0xa0))();
    uVar1 = iVar5 - iVar6;
    uVar2 = 0;
    if (uVar4 != 0) {
      uVar2 = uVar1 / uVar4;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Total aggregated frames %u\n","gsi_dump_ch_scratch"
             ,0xe1b,uVar4);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Total aggregated frames %u\n",
                       "gsi_dump_ch_scratch",0xe1b,uVar4);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Total aggregated frames %u\n",
                       "gsi_dump_ch_scratch",0xe1b,uVar4);
      }
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Total aggregated bytes %llu\n",
             "gsi_dump_ch_scratch",0xe1c,uVar1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Total aggregated bytes %llu\n",
                       "gsi_dump_ch_scratch",0xe1c,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Total aggregated bytes %llu\n",
                       "gsi_dump_ch_scratch",0xe1c,uVar1);
      }
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),
             "%s:%d Total no. of avarage aggregated bytes in frame %llu\n","gsi_dump_ch_scratch",
             0xe1d,uVar2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d Total no. of avarage aggregated bytes in frame %llu\n",
                       "gsi_dump_ch_scratch",0xe1d,uVar2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d Total no. of avarage aggregated bytes in frame %llu\n",
                       "gsi_dump_ch_scratch",0xe1d,uVar2);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_stop_channel @ 0010eb38 size=1392
// signature: undefined gsi_stop_channel(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_stop_channel(ulong param_1)

{
  int *piVar1;
  long *plVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar11 = gsi_ctx;
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_stop_channel",0xe2b);
    uVar9 = 0xfffffff8;
    goto LAB_0010edb8;
  }
  if (*(uint *)(gsi_ctx + 0x6fc0) <= param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_stop_channel",0xe30
             ,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_stop_channel",0xe30,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_stop_channel",0xe30,param_1);
        uVar9 = 0xfffffffa;
        goto LAB_0010edb8;
      }
    }
    uVar9 = 0xfffffffa;
    goto LAB_0010edb8;
  }
  if (0x24 < param_1) {
LAB_0010f0a0:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10f0a4);
    (*pcVar4)();
  }
  lVar10 = gsi_ctx + param_1 * 0x1c0;
  piVar1 = (int *)(lVar10 + 0x130);
  switch(*(undefined4 *)(lVar10 + 0x130)) {
  case 2:
  case 4:
  case 0xf:
    mutex_lock(gsi_ctx + 0x6f60);
    lVar11 = lVar11 + param_1 * 0x1c0;
    *(undefined4 *)(lVar11 + 0x1c0) = 0;
    iVar5 = gsihal_read_reg_nk(0x20,*(undefined4 *)(gsi_ctx + 0x14),0);
    if (((*(int **)(lVar11 + 0x188) != (int *)0x0) && (**(int **)(lVar11 + 0x188) == 2)) &&
       (iVar5 != 1)) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d GSI_EE_n_CNTXT_INTSET %d\n","gsi_stop_channel",
               0xe4a,iVar5);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_CNTXT_INTSET %d\n",
                         "gsi_stop_channel",0xe4a,iVar5);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_CNTXT_INTSET %d\n",
                         "gsi_stop_channel",0xe4a,iVar5);
        }
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10f018);
      (*pcVar4)();
    }
    if (0x23 < param_1) goto LAB_0010f0a0;
    lVar8 = gsi_ctx + param_1 * 0x38;
    *(long *)(lVar8 + 0x3fc8) = *(long *)(lVar8 + 0x3fc8) + 1;
    uStack_4c = (undefined4)param_1;
    local_50 = 2;
    gsihal_write_reg_n_fields(0x37,*(undefined4 *)(gsi_ctx + 0x14),&local_50);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d GSI Channel Stop, waiting for completion: 0x%x\n","gsi_stop_channel",
                       0xe54,iVar5);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d GSI Channel Stop, waiting for completion: 0x%x\n","gsi_stop_channel",
                       0xe54,iVar5);
      }
    }
    gsi_channel_state_change_wait(param_1,lVar10 + 0xb8,200,2);
    if (1 < *piVar1 - 3U) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan=%lu unexpected state=%u\n",
               "gsi_stop_channel",0xe5b,param_1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan=%lu unexpected state=%u\n",
                         "gsi_stop_channel",0xe5b,param_1,*piVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan=%lu unexpected state=%u\n",
                         "gsi_stop_channel",0xe5b,param_1,*piVar1);
        }
      }
      gsi_dump_ch_info(param_1);
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10ef14);
      (*pcVar4)();
    }
    if (*piVar1 == 4) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan=%lu busy try again\n","gsi_stop_channel",
               0xe63,param_1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan=%lu busy try again\n",
                         "gsi_stop_channel",0xe63,param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan=%lu busy try again\n",
                         "gsi_stop_channel",0xe63,param_1);
          uVar9 = 0xfffffff4;
          goto LAB_0010eda8;
        }
      }
      uVar9 = 0xfffffff4;
    }
    else {
      plVar2 = (long *)(lVar11 + 0x188);
      lVar10 = *plVar2;
      if ((lVar10 != 0) && (*(int *)(lVar10 + 4) == 0)) {
        uVar9 = _raw_spin_lock_irqsave(lVar10 + 0x88);
        uVar3 = *(undefined4 *)(gsi_ctx + 0x14);
        if (*(uint *)(gsi_ctx + 0x10) < 10) {
          iVar5 = 1 << (ulong)(*(byte *)(*plVar2 + 0x84) & 0x1f);
          uVar7 = 0x14;
          uVar6 = 0;
        }
        else {
          uVar6 = gsihal_get_ch_reg_idx();
          iVar5 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar2 + 0x84));
          uVar7 = 0x85;
        }
        gsihal_write_reg_nk(uVar7,uVar3,uVar6,iVar5);
        _raw_spin_unlock_irqrestore(*plVar2 + 0x88,uVar9);
      }
      uVar9 = 0;
    }
LAB_0010eda8:
    mutex_unlock(gsi_ctx + 0x6f60);
    break;
  case 3:
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu already stopped\n",
                     "gsi_stop_channel",0xe37,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu already stopped\n",
                     "gsi_stop_channel",0xe37,param_1);
    }
    uVar9 = 0;
    break;
  default:
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_stop_channel",0xe3e);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_stop_channel",0xe3e,
                       *piVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_stop_channel",0xe3e,
                       *piVar1);
        uVar9 = 0xfffffff9;
        break;
      }
    }
    uVar9 = 0xfffffff9;
  }
LAB_0010edb8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// gsi_stop_db_channel @ 0010f0ac size=1084
// signature: undefined gsi_stop_db_channel(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_stop_db_channel(ulong param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 local_40;
  undefined4 uStack_3c;
  long local_38;
  
  lVar5 = gsi_ctx;
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_stop_db_channel",0xe87);
    uVar6 = 0xfffffff8;
    goto LAB_0010f204;
  }
  if (*(uint *)(gsi_ctx + 0x6fc0) <= param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_stop_db_channel",
             0xe8c,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_stop_db_channel",0xe8c,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_stop_db_channel",0xe8c,param_1);
      }
    }
    uVar6 = 0xfffffffa;
    goto LAB_0010f204;
  }
  if (0x24 < param_1) {
LAB_0010f4e0:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10f4e4);
    (*pcVar2)();
  }
  lVar4 = gsi_ctx + param_1 * 0x1c0;
  piVar1 = (int *)(lVar4 + 0x130);
  iVar3 = *(int *)(lVar4 + 0x130);
  if (iVar3 != 2 && iVar3 != 4) {
    if (iVar3 == 3) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu already stopped\n",
                       "gsi_stop_db_channel",0xe93,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu already stopped\n",
                       "gsi_stop_db_channel",0xe93,param_1);
      }
      uVar6 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_stop_db_channel",0xe99);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_stop_db_channel",
                         0xe99,*piVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_stop_db_channel",
                         0xe99,*piVar1);
        }
      }
      uVar6 = 0xfffffff9;
    }
    goto LAB_0010f204;
  }
  mutex_lock(gsi_ctx + 0x6f60);
  lVar5 = lVar5 + param_1 * 0x1c0;
  *(undefined4 *)(lVar5 + 0x1c0) = 0;
  if (0x23 < param_1) goto LAB_0010f4e0;
  lVar4 = gsi_ctx + param_1 * 0x38;
  *(long *)(lVar4 + 0x3fe0) = *(long *)(lVar4 + 0x3fe0) + 1;
  uStack_3c = (undefined4)param_1;
  local_40 = 0xb;
  gsihal_write_reg_n_fields(0x37,*(undefined4 *)(gsi_ctx + 0x14),&local_40);
  iVar3 = wait_for_completion_timeout(lVar5 + 0x1c0,0x32);
  if (iVar3 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu timed out\n","gsi_stop_db_channel",
             0xea8,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu timed out\n",
                       "gsi_stop_db_channel",0xea8,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu timed out\n",
                       "gsi_stop_db_channel",0xea8,param_1);
        uVar6 = 0xfffffff5;
        goto LAB_0010f198;
      }
    }
    uVar6 = 0xfffffff5;
  }
  else if (*piVar1 - 3U < 2) {
    if (*piVar1 == 4) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan=%lu busy try again\n","gsi_stop_db_channel",
               0xeb5,param_1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan=%lu busy try again\n",
                         "gsi_stop_db_channel",0xeb5,param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan=%lu busy try again\n",
                         "gsi_stop_db_channel",0xeb5,param_1);
        }
      }
      uVar6 = 0xfffffff4;
    }
    else {
      uVar6 = 0;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan=%lu unexpected state=%u\n",
             "gsi_stop_db_channel",0xeaf,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan=%lu unexpected state=%u\n",
                       "gsi_stop_db_channel",0xeaf,param_1,*piVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan=%lu unexpected state=%u\n",
                       "gsi_stop_db_channel",0xeaf,param_1,*piVar1);
        uVar6 = 0xfffffffb;
        goto LAB_0010f198;
      }
    }
    uVar6 = 0xfffffffb;
  }
LAB_0010f198:
  mutex_unlock(gsi_ctx + 0x6f60);
LAB_0010f204:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// gsi_reset_channel @ 0010f4ec size=1940
// signature: undefined gsi_reset_channel(void)
// callers: []
//------------------------------------------------------------

void gsi_reset_channel(ulong param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  ulong *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort uVar7;
  int iVar8;
  undefined1 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  long lVar16;
  undefined8 uVar17;
  code *pcVar18;
  long lVar19;
  uint uVar20;
  long lVar21;
  undefined8 local_70;
  long local_68;
  
  lVar16 = gsi_ctx;
  lVar21 = sp_el0;
  local_68 = *(long *)(lVar21 + 0x638);
  local_70 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_reset_channel",0xecc);
    uVar17 = 0xfffffff8;
    goto LAB_0010f948;
  }
  if (*(uint *)(gsi_ctx + 0x6fc0) <= param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_reset_channel",
             0xed1,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_reset_channel",0xed1,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_reset_channel",0xed1,param_1);
        uVar17 = 0xfffffffa;
        goto LAB_0010f948;
      }
    }
    uVar17 = 0xfffffffa;
    goto LAB_0010f948;
  }
  if (0x24 < param_1) {
LAB_0010fc84:
                    /* WARNING: Does not return */
    pcVar18 = (code *)SoftwareBreakpoint(0x5512,0x10fc88);
    (*pcVar18)();
  }
  lVar21 = gsi_ctx + param_1 * 0x1c0;
  piVar1 = (int *)(lVar21 + 0x130);
  if ((*(uint *)(lVar21 + 0x130) | 2) != 3) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_reset_channel",0xede);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_reset_channel",0xede,
                       *piVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_reset_channel",0xede,
                       *piVar1);
        uVar17 = 0xfffffff9;
        goto LAB_0010f948;
      }
    }
    uVar17 = 0xfffffff9;
    goto LAB_0010f948;
  }
  mutex_lock(gsi_ctx + 0x6f60);
  lVar10 = lVar16 + param_1 * 0x1c0;
  *(undefined4 *)(lVar10 + 0x1c0) = 0;
  if (0x23 < param_1) goto LAB_0010fc84;
  puVar2 = (undefined4 *)(lVar10 + 0x1c0);
  lVar10 = gsi_ctx + param_1 * 0x38;
  *(long *)(lVar10 + 0x3fd0) = *(long *)(lVar10 + 0x3fd0) + 1;
  local_70 = CONCAT44((int)param_1,9);
  gsihal_write_reg_n_fields(0x37,*(undefined4 *)(gsi_ctx + 0x14),&local_70);
  iVar8 = wait_for_completion_timeout(puVar2,0x4e2);
  if (iVar8 == 0) {
LAB_0010fa50:
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu timed out\n","gsi_reset_channel",0xeed
             ,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu timed out\n",
                       "gsi_reset_channel",0xeed,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu timed out\n",
                       "gsi_reset_channel",0xeed,param_1);
      }
    }
    mutex_unlock(gsi_ctx + 0x6f60);
    uVar17 = 0xfffffff5;
  }
  else {
    if (*piVar1 == 1) {
      uVar20 = 0;
    }
    else {
      uVar20 = 0;
      do {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                 "gsi_reset_channel",0xef5,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                           "gsi_reset_channel",0xef5,param_1,*piVar1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                           "gsi_reset_channel",0xef5,param_1,*piVar1);
          }
        }
        uVar20 = uVar20 + 1;
        if (10 < uVar20) goto LAB_0010fc8c;
        usleep_range_state(1000,2000,2);
      } while (*piVar1 != 1);
    }
    if ((*(int *)(lVar21 + 0xbc) == 0) && (*(uint *)(gsi_ctx + 0x10) < 4)) {
      usleep_range_state(1000,2000,2);
      *puVar2 = 0;
      lVar10 = gsi_ctx + param_1 * 0x38;
      *(long *)(lVar10 + 0x3fd0) = *(long *)(lVar10 + 0x3fd0) + 1;
      local_70 = CONCAT44((int)param_1,9);
      gsihal_write_reg_n_fields(0x37,*(undefined4 *)(gsi_ctx + 0x14),&local_70);
      iVar8 = wait_for_completion_timeout(puVar2,0x4e2);
      if (iVar8 == 0) goto LAB_0010fa50;
      iVar8 = *piVar1;
      while (iVar8 != 1) {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                 "gsi_reset_channel",0xef5,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                           "gsi_reset_channel",0xef5,param_1,*piVar1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                           "gsi_reset_channel",0xef5,param_1,*piVar1);
          }
        }
        uVar20 = uVar20 + 1;
        if (10 < uVar20) {
LAB_0010fc8c:
                    /* WARNING: Does not return */
          pcVar18 = (code *)SoftwareBreakpoint(0x800,0x10fc90);
          (*pcVar18)();
        }
        usleep_range_state(1000,2000,2);
        iVar8 = *piVar1;
      }
    }
    pcVar18 = *(code **)(lVar21 + 0x120);
    if (pcVar18 != (code *)0x0) {
      lVar10 = gsi_ctx + param_1 * 0x1c0;
      if (*(int *)(lVar10 + 0x130) == 1) {
        if (*(int *)(lVar10 + 0xb8) == 5) {
          lVar19 = 0;
          lVar11 = gsi_ctx + param_1 * 0x1c0;
          uVar7 = *(ushort *)(lVar11 + 0x176);
          do {
            lVar12 = *(long *)(lVar11 + 0x180);
            if (*(char *)(lVar12 + lVar19) != '\0') {
              if (*(int *)(pcVar18 + -4) != -0x2d4a22e1) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x8235,0x10f830);
                (*pcVar18)();
              }
              (*pcVar18)(*(undefined8 *)(lVar10 + 0x128),*(undefined8 *)(lVar12 + lVar19 + 8));
            }
            lVar19 = lVar19 + 0x10;
          } while ((ulong)uVar7 * 0x10 + 0x120 != lVar19);
        }
        else {
          lVar19 = gsi_ctx + param_1 * 0x1c0;
          uVar15 = *(ulong *)(lVar19 + 0x168);
          if (uVar15 != *(ulong *)(lVar19 + 0x160)) {
            puVar3 = (ulong *)(lVar19 + 0x168);
            lVar11 = gsi_ctx + param_1 * 0x1c0;
            do {
              uVar13 = *(ulong *)(lVar11 + 0x148);
              if ((uVar15 < uVar13) || (*(ulong *)(lVar11 + 0x178) <= uVar15)) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x800,0x10f9c0);
                (*pcVar18)();
              }
              uVar20 = 0;
              uVar14 = (uint)*(byte *)(lVar11 + 0x174);
              if (uVar14 != 0) {
                uVar20 = (uint)((int)uVar15 - (int)uVar13) / uVar14;
              }
              if (*(char *)(*(long *)(lVar11 + 0x180) + (ulong)(uVar20 & 0xffff) * 0x10) == '\0') {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x800,0x10fa48);
                (*pcVar18)();
              }
              if (*(int *)(pcVar18 + -4) != -0x2d4a22e1) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x8235,0x10fa18);
                (*pcVar18)();
              }
              (*pcVar18)(*(undefined8 *)(lVar10 + 0x128),
                         *(undefined8 *)
                          (*(long *)(lVar11 + 0x180) + (ulong)(uVar20 & 0xffff) * 0x10 + 8));
              uVar13 = *(ulong *)(lVar11 + 0x178);
              uVar15 = *puVar3 + (ulong)*(byte *)(lVar11 + 0x174);
              *puVar3 = uVar15;
              if (uVar15 == uVar13) {
                uVar15 = *(ulong *)(lVar11 + 0x148);
                *puVar3 = uVar15;
              }
            } while (uVar15 != *(ulong *)(lVar19 + 0x160));
          }
        }
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_cleanup_xfer_user_data",
                 0x828);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n",
                           "gsi_cleanup_xfer_user_data",0x828,*(undefined4 *)(lVar10 + 0x130));
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n",
                           "gsi_cleanup_xfer_user_data",0x828,*(undefined4 *)(lVar10 + 0x130));
          }
        }
      }
    }
    lVar10 = *(long *)(lVar16 + param_1 * 0x1c0 + 0x188);
    if (lVar10 == 0) {
      uVar9 = 0xff;
    }
    else {
      uVar9 = *(undefined1 *)(lVar10 + 0x84);
    }
    gsi_program_chan_ctx(lVar21 + 0xb8,*(undefined4 *)(gsi_ctx + 0x14),uVar9);
    uVar20 = *(uint *)(lVar21 + 0xd0);
    lVar10 = *(long *)(lVar21 + 0xe0);
    uVar17 = *(undefined8 *)(lVar21 + 0xf0);
    lVar16 = lVar16 + param_1 * 0x1c0;
    uVar15 = (ulong)uVar20 & 0xff;
    uVar14 = 0;
    if ((uint)uVar15 != 0) {
      uVar14 = *(uint *)(lVar21 + 0xd4) / (uint)uVar15;
    }
    *(uint *)(lVar16 + 0x170) = *(uint *)(lVar21 + 0xd4);
    *(undefined8 *)(lVar16 + 0x140) = uVar17;
    *(long *)(lVar16 + 0x148) = lVar10;
    uVar4 = *(undefined4 *)(lVar16 + 0x1ec);
    *(long *)(lVar16 + 0x150) = lVar10;
    *(long *)(lVar16 + 0x158) = lVar10;
    uVar5 = *(undefined4 *)(lVar16 + 0x1f0);
    *(long *)(lVar16 + 0x160) = lVar10;
    *(long *)(lVar16 + 0x168) = lVar10;
    uVar6 = *(undefined4 *)(lVar16 + 500);
    *(char *)(lVar16 + 0x174) = (char)uVar20;
    *(short *)(lVar16 + 0x176) = (short)(uVar14 - 1);
    *(ulong *)(lVar16 + 0x178) = uVar15 + uVar15 * (uVar14 - 1 & 0xffff) + lVar10;
    gsihal_write_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,
                        *(undefined4 *)(lVar16 + 0x1e8));
    gsihal_write_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar4);
    gsihal_write_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar5);
    gsihal_write_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff,uVar6);
    mutex_unlock(gsi_ctx + 0x6f60);
    uVar17 = 0;
  }
LAB_0010f948:
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar17);
  }
  return;
}



//------------------------------------------------------------
// gsi_dealloc_channel @ 0010fc94 size=1240
// signature: undefined gsi_dealloc_channel(void)
// callers: []
//------------------------------------------------------------

void gsi_dealloc_channel(ulong param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 local_50;
  long local_48;
  
  lVar9 = gsi_ctx;
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  local_50 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_dealloc_channel",0xf29);
    uVar6 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x24 < param_1) {
LAB_0011013c:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x110140);
      (*pcVar4)();
    }
    lVar10 = gsi_ctx + param_1 * 0x1c0;
    piVar1 = (int *)(lVar10 + 0x130);
    if (*(int *)(lVar10 + 0x130) == 1) {
      iVar5 = *(int *)(gsi_ctx + 0x10);
      mutex_lock(gsi_ctx + 0x6f60);
      if (iVar5 == 5) {
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d In GSI_VER_2_2 channel deallocation not supported\n",
                           "gsi_dealloc_channel",0xf53);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d In GSI_VER_2_2 channel deallocation not supported\n",
                           "gsi_dealloc_channel",0xf53);
          }
        }
        *piVar1 = 0;
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu Channel state = %u\n",
                           "gsi_dealloc_channel",0xf56,param_1,0);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu Channel state = %u\n",
                           "gsi_dealloc_channel",0xf56,param_1,*piVar1);
          }
        }
      }
      else {
        lVar7 = lVar9 + param_1 * 0x1c0;
        *(undefined4 *)(lVar7 + 0x1c0) = 0;
        if (0x23 < param_1) goto LAB_0011013c;
        lVar8 = gsi_ctx + param_1 * 0x38;
        *(long *)(lVar8 + 0x3fd8) = *(long *)(lVar8 + 0x3fd8) + 1;
        local_50 = CONCAT44((int)param_1,10);
        gsihal_write_reg_n_fields(0x37,*(undefined4 *)(gsi_ctx + 0x14),&local_50);
        iVar5 = wait_for_completion_timeout(lVar7 + 0x1c0,0x4e2);
        if (iVar5 == 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu timed out\n",
                   "gsi_dealloc_channel",0xf45,param_1);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu timed out\n",
                             "gsi_dealloc_channel",0xf45,param_1);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu timed out\n",
                             "gsi_dealloc_channel",0xf45,param_1);
            }
          }
          mutex_unlock(gsi_ctx + 0x6f60);
          uVar6 = 0xfffffff5;
          goto LAB_0010fed8;
        }
        if (*piVar1 != 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                   "gsi_dealloc_channel",0xf4b,param_1);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                             "gsi_dealloc_channel",0xf4b,param_1,*piVar1);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%lu unexpected state=%u\n",
                             "gsi_dealloc_channel",0xf4b,param_1,*piVar1);
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11013c);
          (*pcVar4)();
        }
      }
      mutex_unlock(gsi_ctx + 0x6f60);
      lVar9 = lVar9 + param_1 * 0x1c0;
      devm_kfree(*(undefined8 *)(gsi_ctx + 8),*(undefined8 *)(lVar9 + 0x180));
      *(undefined1 *)(lVar9 + 0x1e0) = 0;
      if ((*(long *)(lVar9 + 0x188) != 0) && (*(int *)(lVar10 + 0xb8) != 5)) {
        piVar1 = (int *)(*(long *)(lVar9 + 0x188) + 0x134);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = *piVar1 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        *(char *)(*(long *)(lVar9 + 0x188) + 0x130) =
             *(char *)(*(long *)(lVar9 + 0x188) + 0x130) + -1;
      }
      piVar1 = (int *)(gsi_ctx + 0x6fa4);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (*(int *)(lVar10 + 0xb8) == 5) {
        uVar6 = 0;
        *(undefined2 *)(gsi_ctx + 0x6ff8) = 0x1f24;
      }
      else {
        uVar6 = 0;
      }
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_dealloc_channel",0xf35);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_dealloc_channel",
                         0xf35,*piVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_dealloc_channel",
                         0xf35,*piVar1);
          uVar6 = 0xfffffff9;
          goto LAB_0010fed8;
        }
      }
      uVar6 = 0xfffffff9;
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_dealloc_channel",
             0xf2e,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_dealloc_channel",0xf2e,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_dealloc_channel",0xf2e,param_1);
        uVar6 = 0xfffffffa;
        goto LAB_0010fed8;
      }
    }
    uVar6 = 0xfffffffa;
  }
LAB_0010fed8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// gsi_update_ch_dp_stats @ 00110180 size=164
// signature: undefined gsi_update_ch_dp_stats(void)
// callers: [gsi_wq_update_dp_stats]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsi_update_ch_dp_stats(long param_1,uint param_2)

{
  ulong uVar1;
  ulong uVar2;
  long *plVar3;
  
  param_2 = param_2 & 0xffff;
  uVar1 = jiffies_to_msecs(_jiffies);
  if ((param_2 == 0) &&
     (uVar2 = (uVar1 & 0xffffffff) - *(long *)(param_1 + 0x1b0), *(ulong *)(param_1 + 0x1a8) < uVar2
     )) {
    *(ulong *)(param_1 + 0x1a8) = uVar2;
  }
  if (*(ushort *)(param_1 + 0x20) / 3 < param_2) {
    if ((uint)((ulong)*(ushort *)(param_1 + 0x20) * 0xaaaaaaac >> 0x20) < param_2) {
      plVar3 = (long *)(param_1 + 0x1a0);
    }
    else {
      plVar3 = (long *)(param_1 + 0x198);
    }
  }
  else {
    plVar3 = (long *)(param_1 + 400);
  }
  *plVar3 = *plVar3 + 1;
  *(ulong *)(param_1 + 0x1b0) = uVar1 & 0xffffffff;
  return;
}



//------------------------------------------------------------
// gsi_query_channel_info @ 00110228 size=684
// signature: undefined gsi_query_channel_info(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_query_channel_info(ulong param_1,ulong *param_2)

{
  long *plVar1;
  long lVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_query_channel_info",0xfa7);
    uVar5 = 0xfffffff8;
  }
  else if ((param_2 == (ulong *)0x0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu info=%pK\n",
             "gsi_query_channel_info",0xfac,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu info=%pK\n",
                       "gsi_query_channel_info",0xfac,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu info=%pK\n",
                       "gsi_query_channel_info",0xfac,param_1,param_2);
      }
    }
    uVar5 = 0xfffffffa;
  }
  else {
    if (0x24 < param_1) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1104d4);
      (*pcVar4)();
    }
    lVar8 = gsi_ctx + param_1 * 0x1c0;
    lVar7 = *(long *)(lVar8 + 0x188);
    lVar2 = lVar7 + 0x88;
    if (lVar7 == 0) {
      lVar2 = lVar8 + 0x138;
    }
    *(bool *)(param_2 + 2) = lVar7 != 0;
    uVar5 = _raw_spin_lock_irqsave(lVar2);
    uVar3 = *(undefined4 *)(gsi_ctx + 0x14);
    uVar6 = gsihal_read_reg_nk(0x42,uVar3,*(undefined1 *)(lVar8 + 0xc0));
    lVar7 = gsihal_read_reg_nk(0x43,uVar3,*(undefined1 *)(lVar8 + 0xc0));
    uVar6 = uVar6 & 0xffffffff | lVar7 << 0x20;
    *(ulong *)(lVar8 + 0x158) = uVar6;
    param_2[1] = uVar6;
    uVar6 = gsihal_read_reg_nk(0x44,uVar3,*(undefined1 *)(lVar8 + 0xc0));
    lVar7 = gsihal_read_reg_nk(0x45,uVar3,*(undefined1 *)(lVar8 + 0xc0));
    uVar6 = uVar6 & 0xffffffff | lVar7 << 0x20;
    *(ulong *)(lVar8 + 0x150) = uVar6;
    *param_2 = uVar6;
    if ((char)param_2[2] != '\0') {
      plVar1 = (long *)(lVar8 + 0x188);
      uVar6 = gsihal_read_reg_nk(0x47,uVar3,*(undefined1 *)(*plVar1 + 0x84));
      lVar7 = gsihal_read_reg_nk(0x48,uVar3,*(undefined1 *)(*plVar1 + 0x84));
      param_2[4] = uVar6 & 0xffffffff | lVar7 << 0x20;
      uVar6 = gsihal_read_reg_nk(0x49,uVar3,*(undefined1 *)(*plVar1 + 0x84));
      lVar7 = gsihal_read_reg_nk(0x4a,uVar3,*(undefined1 *)(*plVar1 + 0x84));
      param_2[3] = uVar6 & 0xffffffff | lVar7 << 0x20;
    }
    _raw_spin_unlock_irqrestore(lVar2,uVar5);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d ch=%lu RP=0x%llx WP=0x%llx ev_valid=%d ERP=0x%llx EWP=0x%llx\n",
                       "gsi_query_channel_info",0xfdc,param_1,param_2[1],*param_2,(char)param_2[2],
                       param_2[4],param_2[3]);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d ch=%lu RP=0x%llx WP=0x%llx ev_valid=%d ERP=0x%llx EWP=0x%llx\n",
                     "gsi_query_channel_info",0xfdc,param_1,param_2[1],*param_2,(char)param_2[2],
                     param_2[4],param_2[3]);
    }
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// gsi_is_channel_empty @ 001104d8 size=1024
// signature: undefined gsi_is_channel_empty(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_is_channel_empty(ulong param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  code *pcVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  ulong *puVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  int *piVar15;
  
  lVar12 = gsi_ctx;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_is_channel_empty",0xfee);
    uVar7 = 0xfffffff8;
  }
  else if ((param_2 == 0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu is_empty=%pK\n",
             "gsi_is_channel_empty",0xff4,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu is_empty=%pK\n",
                       "gsi_is_channel_empty",0xff4,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu is_empty=%pK\n",
                       "gsi_is_channel_empty",0xff4,param_1,param_2);
        return 0xfffffffa;
      }
    }
    uVar7 = 0xfffffffa;
  }
  else {
    if (0x24 < param_1) {
LAB_001108d4:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1108d8);
      (*pcVar6)();
    }
    lVar14 = gsi_ctx + param_1 * 0x1c0;
    piVar15 = (int *)(lVar14 + 0xb8);
    if (*piVar15 == 2 || *piVar15 == 5) {
      uVar4 = *(undefined4 *)(gsi_ctx + 0x14);
      lVar9 = gsi_ctx + param_1 * 0x1c0;
      plVar1 = (long *)(lVar9 + 0x188);
      lVar2 = lVar9 + 0x138;
      if (*(long *)(lVar9 + 0x188) != 0) {
        lVar2 = *(long *)(lVar9 + 0x188) + 0x88;
      }
      uVar7 = _raw_spin_lock_irqsave(lVar2);
      if ((*(int *)(lVar14 + 0xbc) == 0) && (*plVar1 != 0)) {
        uVar8 = (ulong)*(byte *)(*plVar1 + 0x84);
        if (0x1f < uVar8) goto LAB_001108d4;
        lVar12 = gsi_ctx + uVar8 * 0x148;
        if (*(int *)(*(code **)(lVar12 + 0x4810) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x110618);
          (*pcVar6)();
        }
        uVar11 = (**(code **)(lVar12 + 0x4810))
                           (lVar12 + 0x4798,*(undefined1 *)(lVar12 + 0x481c),uVar4);
        uVar11 = uVar11 | (ulong)*(uint *)(*plVar1 + 0xac) << 0x20;
        *(ulong *)(*plVar1 + 0xa8) = uVar11;
        uVar8 = gsihal_read_reg_nk(0x49,uVar4,*(undefined1 *)(*plVar1 + 0x84));
        uVar8 = uVar8 & 0xffffffff | (ulong)*(uint *)(*plVar1 + 0xa4) << 0x20;
        *(ulong *)(*plVar1 + 0xa0) = uVar8;
        puVar10 = (ulong *)(*plVar1 + 0xb8);
      }
      else {
        uVar8 = gsihal_read_reg_nk(0x42,uVar4,*(undefined1 *)(lVar14 + 0xc0));
        uVar5 = *(undefined1 *)(lVar14 + 0xc0);
        lVar12 = lVar12 + param_1 * 0x1c0;
        uVar11 = uVar8 & 0xffffffff | (ulong)*(uint *)(lVar12 + 0x15c) << 0x20;
        *(ulong *)(lVar12 + 0x158) = uVar11;
        uVar8 = gsihal_read_reg_nk(0x44,uVar4,uVar5);
        uVar8 = uVar8 & 0xffffffff | (ulong)*(uint *)(lVar12 + 0x154) << 0x20;
        puVar10 = (ulong *)(lVar12 + 0x168);
        *(ulong *)(lVar12 + 0x150) = uVar8;
      }
      uVar13 = *puVar10;
      uVar3 = uVar13;
      if (*(int *)(lVar14 + 0xbc) != 0) {
        uVar3 = uVar8;
      }
      *(bool *)param_2 = uVar3 == uVar11;
      _raw_spin_unlock_irqrestore(lVar2,uVar7);
      if ((*(int *)(lVar14 + 0xbc) == 0) && (*plVar1 != 0)) {
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d ch=%ld ev=%d RP=0x%llx WP=0x%llx RP_LOCAL=0x%llx\n",
                           "gsi_is_channel_empty",0x102e,param_1,*(undefined1 *)(*plVar1 + 0x84),
                           uVar11,uVar8,uVar13);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
            return 0;
          }
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                         "%s:%d ch=%ld ev=%d RP=0x%llx WP=0x%llx RP_LOCAL=0x%llx\n",
                         "gsi_is_channel_empty",0x102e,param_1,*(undefined1 *)(*plVar1 + 0x84),
                         uVar11,uVar8,uVar13);
        }
      }
      else if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d ch=%lu RP=0x%llx WP=0x%llx RP_LOCAL=0x%llx\n","gsi_is_channel_empty"
                         ,0x1031,param_1,uVar11,uVar8,uVar13);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
          return 0;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d ch=%lu RP=0x%llx WP=0x%llx RP_LOCAL=0x%llx\n","gsi_is_channel_empty",
                       0x1031,param_1,uVar11,uVar8,uVar13);
      }
      uVar7 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d op not supported for protocol %u\n",
               "gsi_is_channel_empty",0xffd);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d op not supported for protocol %u\n",
                         "gsi_is_channel_empty",0xffd,*piVar15);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d op not supported for protocol %u\n",
                         "gsi_is_channel_empty",0xffd,*piVar15);
          return 0xfffffff9;
        }
      }
      uVar7 = 0xfffffff9;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// gsi_is_event_pending @ 001108dc size=272
// signature: undefined gsi_is_event_pending(void)
// callers: []
//------------------------------------------------------------

bool gsi_is_event_pending(ulong param_1)

{
  code *pcVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x24 < param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1109ec);
      (*pcVar1)();
    }
    lVar5 = gsi_ctx + param_1 * 0x1c0;
    lVar3 = *(long *)(lVar5 + 0x188);
    if (*(int *)(*(code **)(lVar3 + 0x78) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x110940);
      (*pcVar1)();
    }
    uVar4 = (**(code **)(lVar3 + 0x78))
                      (lVar3,*(undefined1 *)(lVar3 + 0x84),*(undefined4 *)(gsi_ctx + 0x14));
    lVar3 = *(long *)(lVar5 + 0x188);
    bVar2 = (uVar4 | (ulong)*(uint *)(lVar3 + 0xac) << 0x20) != *(ulong *)(lVar3 + 0xb8);
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_is_event_pending",
             0x103e,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_is_event_pending",0x103e,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return false;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                     "gsi_is_event_pending",0x103e,param_1);
    }
    bVar2 = false;
  }
  return bVar2;
}



//------------------------------------------------------------
// __gsi_get_gci_cookie @ 001109f0 size=616
// signature: undefined __gsi_get_gci_cookie(void)
// callers: [__gsi_populate_gci_tre]
//------------------------------------------------------------

ulong __gsi_get_gci_cookie(long param_1,ushort param_2)

{
  uint uVar1;
  ushort uVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  ulong uVar7;
  
  lVar5 = *(long *)(param_1 + 200);
  pcVar6 = (char *)(lVar5 + (ulong)param_2 * 0x10);
  if (*pcVar6 == '\0') {
    uVar4 = (ulong)param_2;
    *pcVar6 = '\x01';
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0xbe);
    uVar7 = (ulong)uVar2;
    uVar4 = uVar7 + 1;
    *(long *)(param_1 + 0x188) = *(long *)(param_1 + 0x188) + 1;
    if (((((((*(char *)(lVar5 + uVar4 * 0x10) == '\0') ||
            (uVar4 = uVar7 + 2, *(char *)(lVar5 + uVar4 * 0x10) == '\0')) ||
           (uVar4 = uVar7 + 3, *(char *)(lVar5 + uVar4 * 0x10) == '\0')) ||
          ((uVar4 = uVar7 + 4, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
           (uVar4 = uVar7 + 5, *(char *)(lVar5 + uVar4 * 0x10) == '\0')))) ||
         ((uVar4 = uVar7 + 6, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
          ((uVar4 = uVar7 + 7, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
           (uVar4 = uVar7 + 8, *(char *)(lVar5 + uVar4 * 0x10) == '\0')))))) ||
        (uVar4 = uVar7 + 9, *(char *)(lVar5 + uVar4 * 0x10) == '\0')) ||
       ((((uVar4 = uVar7 + 10, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
          (uVar4 = uVar7 + 0xb, *(char *)(lVar5 + uVar4 * 0x10) == '\0')) ||
         (uVar4 = uVar7 + 0xc, *(char *)(lVar5 + uVar4 * 0x10) == '\0')) ||
        (((uVar4 = uVar7 + 0xd, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
          (uVar4 = uVar7 + 0xe, *(char *)(lVar5 + uVar4 * 0x10) == '\0')) ||
         ((uVar4 = uVar7 + 0xf, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
          ((uVar4 = uVar7 + 0x10, *(char *)(lVar5 + uVar4 * 0x10) == '\0' ||
           (uVar4 = uVar7 + 0x11, *(char *)(lVar5 + uVar4 * 0x10) == '\0')))))))))) {
      *(undefined1 *)(lVar5 + uVar4 * 0x10) = 1;
    }
    else {
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d escape buffer is full\n",
                         "__gsi_get_gci_cookie",0x1068);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d escape buffer is full\n",
                         "__gsi_get_gci_cookie",0x1068);
        }
      }
      uVar4 = 0;
      pcVar6 = *(char **)(param_1 + 200);
      while (*pcVar6 != '\0') {
        uVar1 = (int)uVar4 + 1;
        uVar4 = (ulong)uVar1;
        pcVar6 = pcVar6 + 0x10;
        if (uVar2 + 1 == uVar1) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),
                   "%s:%d both userdata array and escape buffer is full\n","__gsi_get_gci_cookie",
                   0x1071);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d both userdata array and escape buffer is full\n",
                             "__gsi_get_gci_cookie",0x1071);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d both userdata array and escape buffer is full\n",
                             "__gsi_get_gci_cookie",0x1071);
            }
          }
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x110c1c);
          (*pcVar3)();
        }
      }
      *pcVar6 = '\x01';
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// __gsi_populate_gci_tre @ 00110c5c size=508
// signature: undefined __gsi_populate_gci_tre(void)
// callers: [gsi_queue_xfer]
//------------------------------------------------------------

undefined8 __gsi_populate_gci_tre(long param_1,ulong *param_2)

{
  byte bVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong uVar8;
  long lVar9;
  
  uVar8 = *param_2;
  if (uVar8 >> 0x28 == 0) {
    if (*(int *)((long)param_2 + 0xc) == 0) {
      uVar6 = *(ulong *)(param_1 + 0xa8);
      if ((uVar6 < *(ulong *)(param_1 + 0x90)) || (*(ulong *)(param_1 + 0xc0) <= uVar6)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x110ca8);
        (*pcVar4)();
      }
      bVar1 = *(byte *)(param_1 + 0xbc);
      lVar9 = *(long *)(param_1 + 0x88);
      uVar3 = param_2[1];
      uVar2 = 0;
      if (bVar1 != 0) {
        uVar2 = (uint)((int)uVar6 - (int)*(ulong *)(param_1 + 0x90)) / (uint)bVar1;
      }
      iVar5 = __gsi_get_gci_cookie(param_1,uVar2);
      uVar6 = (long)iVar5 & 0xffffffffff;
      if ((ulong)*(ushort *)(param_1 + 0xbe) + 0x11 < uVar6) {
        return 0xffffffff;
      }
      puVar7 = (ulong *)(lVar9 + (ulong)bVar1 * (ulong)(uVar2 & 0xffff));
      *puVar7 = uVar8 & 0x1ffffffffff | (ulong)(ushort)uVar3 << 0x30;
      puVar7[1] = uVar6 | 0x8000000000000;
      *(ulong *)(*(long *)(param_1 + 200) + uVar6 * 0x10 + 8) = param_2[2];
      return 0;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u bad RE type=%u\n",
             "__gsi_populate_gci_tre",0x1086,*(undefined1 *)(param_1 + 8));
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%u bad RE type=%u\n",
                       "__gsi_populate_gci_tre",0x1086,*(undefined1 *)(param_1 + 8),
                       *(undefined4 *)((long)param_2 + 0xc));
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%u bad RE type=%u\n",
                       "__gsi_populate_gci_tre",0x1086,*(undefined1 *)(param_1 + 8),
                       *(undefined4 *)((long)param_2 + 0xc));
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u add too large=%llx\n",
             "__gsi_populate_gci_tre",0x1080,*(undefined1 *)(param_1 + 8),uVar8);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%u add too large=%llx\n",
                       "__gsi_populate_gci_tre",0x1080,*(undefined1 *)(param_1 + 8),*param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%u add too large=%llx\n",
                       "__gsi_populate_gci_tre",0x1080,*(undefined1 *)(param_1 + 8),*param_2);
        return 0xffffffea;
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// __gsi_populate_tre @ 00110e68 size=480
// signature: undefined __gsi_populate_tre(void)
// callers: [gsi_queue_xfer]
//------------------------------------------------------------

undefined8 __gsi_populate_tre(long param_1,undefined8 *param_2)

{
  uint uVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  long lVar5;
  uint uVar6;
  code *pcVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  
  uVar1 = *(uint *)((long)param_2 + 0xc);
  if (uVar1 < 3) {
    if (*(int *)(param_1 + 0x78) == 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","__gsi_populate_tre",0x10b8,0);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","__gsi_populate_tre",
                         0x10b8,*(undefined4 *)(param_1 + 0x78));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","__gsi_populate_tre",
                         0x10b8,*(undefined4 *)(param_1 + 0x78));
        }
      }
      uVar8 = 0xfffffff9;
    }
    else {
      uVar3 = *(ushort *)((long)param_2 + 10);
      uVar9 = *(ulong *)(param_1 + 0xa8);
      uVar4 = *(undefined2 *)(param_2 + 1);
      if ((uVar9 < *(ulong *)(param_1 + 0x90)) || (*(ulong *)(param_1 + 0xc0) <= uVar9)) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x110ec4);
        (*pcVar7)();
      }
      bVar2 = *(byte *)(param_1 + 0xbc);
      uVar8 = 0;
      uVar6 = 0;
      if (bVar2 != 0) {
        uVar6 = (uint)((int)uVar9 - (int)*(ulong *)(param_1 + 0x90)) / (uint)bVar2;
      }
      puVar10 = (undefined8 *)(*(long *)(param_1 + 0x88) + (ulong)bVar2 * (ulong)(uVar6 & 0xffff));
      *puVar10 = *param_2;
      *(undefined2 *)(puVar10 + 1) = uVar4;
      *(undefined2 *)((long)puVar10 + 10) = 0;
      *(ushort *)((long)puVar10 + 0xc) = uVar3 & 0x701;
      *(char *)((long)puVar10 + 0xe) = (char)uVar1 + '\x02';
      lVar5 = (ulong)(uVar6 & 0xffff) * 0x10;
      *(undefined1 *)((long)puVar10 + 0xf) = 0;
      *(undefined1 *)(*(long *)(param_1 + 200) + lVar5) = 1;
      *(undefined8 *)(*(long *)(param_1 + 200) + lVar5 + 8) = param_2[2];
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u bad RE type=%u\n","__gsi_populate_tre",
             0x10ae,*(undefined1 *)(param_1 + 8));
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%u bad RE type=%u\n",
                       "__gsi_populate_tre",0x10ae,*(undefined1 *)(param_1 + 8),
                       *(undefined4 *)((long)param_2 + 0xc));
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%u bad RE type=%u\n",
                       "__gsi_populate_tre",0x10ae,*(undefined1 *)(param_1 + 8),
                       *(undefined4 *)((long)param_2 + 0xc));
      }
    }
    uVar8 = 0xffffffea;
  }
  return uVar8;
}



//------------------------------------------------------------
// gsi_queue_xfer @ 00111054 size=1500
// signature: undefined gsi_queue_xfer(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_queue_xfer(ulong param_1,ulong param_2,long param_3,ulong param_4)

{
  int *piVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  byte bVar6;
  undefined1 uVar7;
  ushort uVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  undefined8 uVar12;
  char *pcVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  long lVar21;
  uint uVar22;
  
  lVar17 = gsi_ctx;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_queue_xfer",0x10d3);
    return 0xfffffff8;
  }
  uVar4 = (uint)param_2 & 0xffff;
  if ((param_1 < *(uint *)(gsi_ctx + 0x6fc0)) && (((param_2 & 0xffff) == 0 || (param_3 != 0)))) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x111648);
      (*pcVar10)();
    }
    lVar14 = gsi_ctx + param_1 * 0x1c0;
    if (*(int *)(lVar14 + 0x130) == 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_queue_xfer",0x10e0,0);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_queue_xfer",0x10e0,
                         *(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        lVar17 = *(long *)(gsi_ctx + 0x6ff0);
        if (lVar17 != 0) {
          pcVar13 = "%s:%d bad state %d\n";
          uVar12 = 0x10e0;
          iVar11 = *(int *)(gsi_ctx + param_1 * 0x1c0 + 0x130);
LAB_00111574:
          ipc_log_string(lVar17,pcVar13,"gsi_queue_xfer",uVar12,iVar11);
        }
      }
    }
    else {
      piVar1 = (int *)(lVar14 + 0xb8);
      if ((*piVar1 == 2) || (*piVar1 == 5)) {
        lVar15 = gsi_ctx + param_1 * 0x1c0;
        lVar5 = lVar15 + 0x138;
        if (*(long *)(lVar15 + 0x188) != 0) {
          lVar5 = *(long *)(lVar15 + 0x188) + 0x88;
        }
        uVar12 = _raw_spin_lock_irqsave(lVar5);
        if ((param_2 & 0xffff) == 0) {
LAB_0011143c:
          lVar21 = gsi_ctx;
          if ((param_4 & 1) != 0) {
            DataSynchronizationBarrier(3,2,0);
            lVar15 = *(long *)(lVar15 + 0x188);
            if ((lVar15 != 0) && (*(int *)(lVar14 + 0xbc) == 0)) {
              *(undefined8 *)(lVar15 + 0xa0) = *(undefined8 *)(lVar15 + 0xb0);
              gsihal_write_reg_nk(0x11,*(undefined4 *)(lVar21 + 0x14),*(undefined1 *)(lVar15 + 0x84)
                                 );
            }
            uVar7 = *(undefined1 *)(lVar14 + 0xc0);
            lVar17 = lVar17 + param_1 * 0x1c0;
            *(undefined8 *)(lVar17 + 0x150) = *(undefined8 *)(lVar17 + 0x160);
            gsihal_write_reg_nk(0x12,*(undefined4 *)(gsi_ctx + 0x14),uVar7);
          }
          _raw_spin_unlock_irqrestore(lVar5,uVar12);
          return 0;
        }
        if (*piVar1 != 5) {
          if (*piVar1 != 2) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x800,0x111640);
            (*pcVar10)();
          }
          if (*(long *)(lVar15 + 0x188) == 0) {
            uVar18 = gsihal_read_reg_nk(0x42,*(undefined4 *)(gsi_ctx + 0x14),
                                        *(undefined1 *)(lVar14 + 0xc0));
            lVar21 = lVar17 + param_1 * 0x1c0;
            uVar18 = uVar18 & 0xffffffff | (ulong)*(uint *)(lVar21 + 0x15c) << 0x20;
            *(ulong *)(lVar21 + 0x158) = uVar18;
          }
          else {
            uVar18 = *(ulong *)(lVar17 + param_1 * 0x1c0 + 0x168);
          }
          uVar16 = *(ulong *)(lVar17 + param_1 * 0x1c0 + 0x148);
          if ((uVar18 < uVar16) || (*(ulong *)(lVar17 + param_1 * 0x1c0 + 0x178) <= uVar18)) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x800,0x111228);
            (*pcVar10)();
          }
          lVar21 = lVar17 + param_1 * 0x1c0;
          bVar6 = *(byte *)(lVar21 + 0x174);
          uVar20 = *(ulong *)(lVar21 + 0x160);
          uVar22 = 0;
          if (bVar6 != 0) {
            uVar22 = (uint)((int)uVar18 - (int)uVar16) / (uint)bVar6;
          }
          if ((uVar20 < uVar16) || (*(ulong *)(lVar17 + param_1 * 0x1c0 + 0x178) <= uVar20)) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x800,0x11126c);
            (*pcVar10)();
          }
          uVar9 = 0;
          if (bVar6 != 0) {
            uVar9 = (uint)((int)uVar20 - (int)uVar16) / (uint)bVar6;
          }
          if ((uVar9 & 0xffff) < (uVar22 & 0xffff)) {
            uVar8 = *(ushort *)(lVar17 + param_1 * 0x1c0 + 0x176);
            iVar11 = (uVar22 - uVar9) + ~(uint)uVar8;
          }
          else {
            iVar11 = uVar22 - uVar9;
            uVar8 = *(ushort *)(lVar17 + param_1 * 0x1c0 + 0x176);
          }
          uVar22 = iVar11 + (uint)uVar8;
          if ((uVar22 & 0xffff) < ((uint)param_2 & 0xffff)) {
            iVar11 = ___ratelimit(gsi_queue_xfer__rs,"gsi_queue_xfer");
            if (iVar11 != 0) {
              _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%lu num_xfers=%u free=%u\n",
                       "gsi_queue_xfer",0x1100,param_1,uVar4,uVar22 & 0xffff);
            }
            if (gsi_ctx != 0) {
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                               "%s:%d chan_hdl=%lu num_xfers=%u free=%u\n","gsi_queue_xfer",0x1100,
                               param_1,uVar4,uVar22 & 0xffff);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                               "%s:%d chan_hdl=%lu num_xfers=%u free=%u\n","gsi_queue_xfer",0x1100,
                               param_1,uVar4,uVar22 & 0xffff);
              }
            }
            _raw_spin_unlock_irqrestore(lVar5,uVar12);
            return 0xfffffffe;
          }
        }
        lVar21 = lVar17 + param_1 * 0x1c0;
        uVar18 = 0;
        uVar22 = uVar4;
        if (uVar4 < 2) {
          uVar22 = 1;
        }
        plVar2 = (long *)(lVar21 + 0x160);
        lVar19 = *(long *)(lVar21 + 0x160);
        do {
          if (*piVar1 == 5) {
            iVar11 = __gsi_populate_gci_tre();
          }
          else {
            iVar11 = __gsi_populate_tre(piVar1,param_3);
          }
          if (iVar11 != 0) {
            uVar22 = (uint)uVar18;
            break;
          }
          lVar3 = *plVar2 + (ulong)*(byte *)(lVar21 + 0x174);
          *plVar2 = lVar3;
          if (lVar3 == *(long *)(lVar21 + 0x178)) {
            *plVar2 = *(long *)(lVar21 + 0x148);
          }
          uVar18 = uVar18 + 1;
          param_3 = param_3 + 0x18;
        } while (uVar22 != uVar18);
        if (uVar22 == uVar4) {
          lVar21 = lVar17 + param_1 * 0x1c0;
          *(ulong *)(lVar21 + 0x200) = *(long *)(lVar21 + 0x200) + (param_2 & 0xffff);
          goto LAB_0011143c;
        }
        *plVar2 = lVar19;
        _raw_spin_unlock_irqrestore(lVar5,uVar12);
        goto LAB_001114c0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d op not supported for protocol %u\n",
               "gsi_queue_xfer",0x10e9);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d op not supported for protocol %u\n",
                         "gsi_queue_xfer",0x10e9,*piVar1);
        }
        lVar17 = *(long *)(gsi_ctx + 0x6ff0);
        if (lVar17 != 0) {
          iVar11 = *piVar1;
          pcVar13 = "%s:%d op not supported for protocol %u\n";
          uVar12 = 0x10e9;
          goto LAB_00111574;
        }
      }
    }
    uVar12 = 0xfffffff9;
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu num_xfers=%u xfer=%pK\n",
             "gsi_queue_xfer",0x10d9,param_1,uVar4,param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params chan_hdl=%lu num_xfers=%u xfer=%pK\n","gsi_queue_xfer",
                       0x10d9,param_1,uVar4,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d bad params chan_hdl=%lu num_xfers=%u xfer=%pK\n","gsi_queue_xfer",
                       0x10d9,param_1,uVar4,param_3);
      }
    }
LAB_001114c0:
    uVar12 = 0xfffffffa;
  }
  return uVar12;
}



//------------------------------------------------------------
// gsi_start_xfer @ 0011164c size=648
// signature: undefined gsi_start_xfer(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_start_xfer(ulong param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  long lVar10;
  
  lVar3 = gsi_ctx;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_start_xfer",0x112d);
    return 0xfffffff8;
  }
  if (*(uint *)(gsi_ctx + 0x6fc0) <= param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_start_xfer",0x1132,
             param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_start_xfer",0x1132,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_start_xfer",0x1132,param_1);
        return 0xfffffffa;
      }
    }
    return 0xfffffffa;
  }
  if (0x24 < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1118d4);
    (*pcVar2)();
  }
  lVar8 = gsi_ctx + param_1 * 0x1c0;
  piVar9 = (int *)(lVar8 + 0xb8);
  if (*piVar9 == 2 || *piVar9 == 5) {
    lVar10 = gsi_ctx + param_1 * 0x1c0;
    if (*(int *)(lVar10 + 0x130) != 0) {
      lVar6 = gsi_ctx + param_1 * 0x1c0;
      lVar10 = *(long *)(lVar6 + 0x160);
      if (*(long *)(lVar6 + 0x150) != lVar10) {
        lVar7 = *(long *)(gsi_ctx + param_1 * 0x1c0 + 0x188);
        if ((lVar7 != 0) && (*(int *)(lVar8 + 0xbc) == 0)) {
          *(undefined8 *)(lVar7 + 0xa0) = *(undefined8 *)(lVar7 + 0xb0);
          gsihal_write_reg_nk(0x11,*(undefined4 *)(lVar3 + 0x14),*(undefined1 *)(lVar7 + 0x84));
          lVar10 = *(long *)(lVar6 + 0x160);
        }
        *(long *)(lVar6 + 0x150) = lVar10;
        gsihal_write_reg_nk(0x12,*(undefined4 *)(gsi_ctx + 0x14),*(undefined1 *)(lVar8 + 0xc0));
      }
      return 0;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_start_xfer",0x113f,0);
    if (gsi_ctx != 0) {
      piVar9 = (int *)(lVar10 + 0x130);
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_start_xfer",0x113f,
                       *piVar9);
      }
      lVar3 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar3 != 0) {
        iVar1 = *piVar9;
        pcVar4 = "%s:%d bad state %d\n";
        uVar5 = 0x113f;
LAB_001118bc:
        ipc_log_string(lVar3,pcVar4,"gsi_start_xfer",uVar5,iVar1);
        return 0xfffffff9;
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d op not supported for protocol %u\n",
             "gsi_start_xfer",0x113a);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d op not supported for protocol %u\n",
                       "gsi_start_xfer",0x113a,*piVar9);
      }
      lVar3 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar3 != 0) {
        iVar1 = *piVar9;
        pcVar4 = "%s:%d op not supported for protocol %u\n";
        uVar5 = 0x113a;
        goto LAB_001118bc;
      }
    }
  }
  return 0xfffffff9;
}



//------------------------------------------------------------
// gsi_poll_channel @ 001118d8 size=84
// signature: undefined gsi_poll_channel(void)
// callers: []
//------------------------------------------------------------

void gsi_poll_channel(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  gsi_poll_n_channel(param_1,param_2,1,&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_poll_n_channel @ 00111930 size=1308
// signature: undefined gsi_poll_n_channel(void)
// callers: [gsi_poll_channel]
//------------------------------------------------------------

undefined8 gsi_poll_n_channel(ulong param_1,long param_2,uint param_3,uint *param_4)

{
  long *plVar1;
  uint uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  char *pcVar12;
  long lVar13;
  long lVar14;
  int *piVar15;
  long lVar16;
  
  lVar13 = gsi_ctx;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_poll_n_channel",0x1160);
    return 0xfffffff8;
  }
  if (((((int)param_3 < 1) || (param_4 == (uint *)0x0)) || (param_2 == 0)) ||
     (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu notify=%pK\n",
             "gsi_poll_n_channel",0x1167,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu notify=%pK\n",
                       "gsi_poll_n_channel",0x1167,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu notify=%pK\n",
                       "gsi_poll_n_channel",0x1167,param_1,param_2);
      }
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d actual_num=%pK expected_num=%d\n",
             "gsi_poll_n_channel",0x1169,param_4,param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d actual_num=%pK expected_num=%d\n",
                       "gsi_poll_n_channel",0x1169,param_4,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d actual_num=%pK expected_num=%d\n",
                       "gsi_poll_n_channel",0x1169,param_4,param_3);
        return 0xfffffffa;
      }
    }
    return 0xfffffffa;
  }
  if (0x24 < param_1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x111e4c);
    (*pcVar4)();
  }
  uVar3 = *(undefined4 *)(gsi_ctx + 0x14);
  piVar15 = (int *)(gsi_ctx + param_1 * 0x1c0 + 0xb8);
  if ((*piVar15 == 2) || (*piVar15 == 5)) {
    lVar16 = gsi_ctx + param_1 * 0x1c0;
    if (*(int *)(lVar16 + 0x130) == 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_poll_n_channel",0x1178,0);
      if (gsi_ctx != 0) {
        piVar15 = (int *)(lVar16 + 0x130);
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_poll_n_channel",
                         0x1178,*piVar15);
        }
        lVar13 = *(long *)(gsi_ctx + 0x6ff0);
        if (lVar13 != 0) {
          iVar6 = *piVar15;
          pcVar12 = "%s:%d bad state %d\n";
          uVar8 = 0x1178;
          goto LAB_00111dbc;
        }
      }
    }
    else {
      lVar16 = gsi_ctx + param_1 * 0x1c0;
      lVar14 = *(long *)(lVar16 + 0x188);
      if (lVar14 != 0) {
        plVar1 = (long *)(lVar16 + 0x188);
        uVar8 = _raw_spin_lock_irqsave(lVar14 + 0x88);
        lVar16 = *plVar1;
        uVar11 = *(ulong *)(lVar16 + 0xb8);
        if (*(ulong *)(lVar16 + 0xa8) == uVar11) {
          if (*(int *)(*(code **)(lVar16 + 0x78) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x111a20);
            (*pcVar4)();
          }
          uVar9 = (**(code **)(lVar16 + 0x78))(lVar16,*(undefined1 *)(lVar16 + 0x84),uVar3);
          uVar9 = uVar9 | (ulong)*(uint *)(*plVar1 + 0xac) << 0x20;
          *(ulong *)(*plVar1 + 0xa8) = uVar9;
          lVar16 = *plVar1;
          uVar11 = *(ulong *)(lVar16 + 0xb8);
          if (uVar9 == uVar11) {
            if (*(uint *)(gsi_ctx + 0x10) < 10) {
              iVar6 = 1 << (ulong)(*(byte *)(lVar16 + 0x84) & 0x1f);
              uVar10 = 0x14;
              uVar5 = 0;
            }
            else {
              uVar5 = gsihal_get_ch_reg_idx();
              iVar6 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar1 + 0x84));
              uVar10 = 0x85;
            }
            gsihal_write_reg_nk(uVar10,uVar3,uVar5,iVar6);
            DataMemoryBarrier(0,2);
            lVar16 = *plVar1;
            if (*(int *)(*(code **)(lVar16 + 0x78) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x111ac4);
              (*pcVar4)();
            }
            uVar9 = (**(code **)(lVar16 + 0x78))(lVar16,*(undefined1 *)(lVar16 + 0x84),uVar3);
            uVar9 = uVar9 | (ulong)*(uint *)(*plVar1 + 0xac) << 0x20;
            *(ulong *)(*plVar1 + 0xa8) = uVar9;
            lVar16 = *plVar1;
            uVar11 = *(ulong *)(lVar16 + 0xb8);
            if (uVar9 == uVar11) {
              _raw_spin_unlock_irqrestore(lVar16 + 0x88,uVar8);
              lVar13 = lVar13 + param_1 * 0x1c0;
              *(long *)(lVar13 + 0x238) = *(long *)(lVar13 + 0x238) + 1;
              return 9;
            }
          }
        }
        uVar7 = gsi_get_complete_num(lVar16 + 0x88,uVar11,*(undefined8 *)(lVar16 + 0xa8));
        uVar2 = uVar7 & 0xffff;
        if (param_3 <= (uVar7 & 0xffff)) {
          uVar2 = param_3;
        }
        *param_4 = uVar2;
        if (uVar2 != 0) {
          lVar16 = 0;
          do {
            gsi_process_evt_re(*plVar1,param_2,0);
            lVar16 = lVar16 + 1;
            param_2 = param_2 + 0x18;
          } while (lVar16 < (int)*param_4);
        }
        _raw_spin_unlock_irqrestore(*plVar1 + 0x88,uVar8);
        lVar13 = lVar13 + param_1 * 0x1c0;
        *(long *)(lVar13 + 0x230) = *(long *)(lVar13 + 0x230) + 1;
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d no event ring associated chan_hdl=%lu\n",
               "gsi_poll_n_channel",0x117d,param_1);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d no event ring associated chan_hdl=%lu\n"
                         ,"gsi_poll_n_channel",0x117d,param_1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d no event ring associated chan_hdl=%lu\n"
                         ,"gsi_poll_n_channel",0x117d,param_1);
          return 0xfffffff9;
        }
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d op not supported for protocol %u\n",
             "gsi_poll_n_channel",0x1172);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d op not supported for protocol %u\n",
                       "gsi_poll_n_channel",0x1172,*piVar15);
      }
      lVar13 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar13 != 0) {
        iVar6 = *piVar15;
        pcVar12 = "%s:%d op not supported for protocol %u\n";
        uVar8 = 0x1172;
LAB_00111dbc:
        ipc_log_string(lVar13,pcVar12,"gsi_poll_n_channel",uVar8,iVar6);
        return 0xfffffff9;
      }
    }
  }
  return 0xfffffff9;
}



//------------------------------------------------------------
// gsi_get_complete_num @ 00111e4c size=420
// signature: undefined gsi_get_complete_num(void)
// callers: [gsi_poll_n_channel, gsi_process_evt_re]
//------------------------------------------------------------

uint gsi_get_complete_num(long param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d gsi base addr 0x%llx end addr 0x%llx\n",
                   "gsi_get_complete_num",0x28c,*(undefined8 *)(param_1 + 0x10),
                   *(undefined8 *)(param_1 + 0x40));
  }
  if ((param_2 < *(ulong *)(param_1 + 0x10)) || (*(ulong *)(param_1 + 0x40) <= param_2)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d address = 0x%llx not in range\n",
             "gsi_get_complete_num",0x28f,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d address = 0x%llx not in range\n",
                       "gsi_get_complete_num",0x28f,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d address = 0x%llx not in range\n",
                       "gsi_get_complete_num",0x28f,param_2);
      }
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x111f74);
    (*pcVar2)();
  }
  if ((*(ulong *)(param_1 + 0x10) <= param_3) && (param_3 < *(ulong *)(param_1 + 0x40))) {
    uVar3 = (int)param_3 - (int)param_2;
    if (param_3 <= param_2) {
      uVar3 = *(int *)(param_1 + 0x38) + uVar3;
    }
    uVar1 = 0;
    if (*(byte *)(param_1 + 0x3c) != 0) {
      uVar1 = uVar3 / *(byte *)(param_1 + 0x3c);
    }
    return uVar1;
  }
  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d address = 0x%llx not in range\n",
           "gsi_get_complete_num",0x294,param_3);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d address = 0x%llx not in range\n",
                     "gsi_get_complete_num",0x294,param_3);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d address = 0x%llx not in range\n",
                     "gsi_get_complete_num",0x294,param_3);
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x111ff0);
  (*pcVar2)();
}



//------------------------------------------------------------
// gsi_process_evt_re @ 00111ff0 size=868
// signature: undefined gsi_process_evt_re(void)
// callers: [gsi_handle_irq, gsi_msi_isr, gsi_poll_n_channel]
//------------------------------------------------------------

void gsi_process_evt_re(long param_1,undefined8 *param_2,ulong param_3)

{
  ulong *puVar1;
  byte bVar2;
  code *pcVar3;
  ushort uVar4;
  ulong uVar5;
  undefined1 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  ulong *puVar16;
  long lVar17;
  
  lVar9 = gsi_ctx;
  puVar16 = (ulong *)((*(long *)(param_1 + 0xb8) + *(long *)(param_1 + 0x90)) -
                     *(long *)(param_1 + 0x98));
  bVar2 = *(byte *)((long)puVar16 + 0xf);
  if (*(uint *)(gsi_ctx + 0x6fc0) <= (uint)bVar2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x11236c);
    (*pcVar3)();
  }
  uVar13 = (uint)bVar2;
  if (uVar13 < 0x25) {
    lVar17 = gsi_ctx + (ulong)uVar13 * 0x1c0;
    if (*(int *)(lVar17 + 0xb8) != 2 && *(int *)(lVar17 + 0xb8) != 5) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x112084);
      (*pcVar3)();
    }
    uVar15 = *puVar16;
    uVar14 = (uint)bVar2;
    if (*(char *)((long)puVar16 + 0xe) == '(') {
      uVar6 = *(undefined1 *)((long)puVar16 + 10);
    }
    else {
      lVar8 = gsi_ctx + (ulong)uVar13 * 0x1c0;
      puVar1 = (ulong *)(lVar8 + 0x168);
      uVar5 = *(ulong *)(lVar8 + 0x168);
      if (uVar5 != uVar15) {
        lVar11 = gsi_ctx + (ulong)uVar13 * 0x1c0;
        uVar4 = gsi_get_complete_num(lVar11 + 0x138,uVar5,uVar15);
        lVar8 = *(long *)(lVar11 + 0x208);
        *puVar1 = uVar15;
        *(ulong *)(lVar11 + 0x208) = lVar8 + (ulong)uVar4;
      }
      if (((param_3 & 1) == 0) ||
         ((uVar5 = uVar15, *(int *)(lVar17 + 0xbc) == 1 && (*(char *)(lVar17 + 0x109) == '\0')))) {
        lVar8 = lVar9 + (ulong)uVar14 * 0x1c0;
        uVar7 = *(ulong *)(lVar8 + 0x178);
        uVar5 = uVar15 + *(byte *)(lVar8 + 0x174);
        *puVar1 = uVar5;
        if (uVar5 == uVar7) {
          uVar5 = *(ulong *)(lVar9 + (ulong)uVar14 * 0x1c0 + 0x148);
          *puVar1 = uVar5;
        }
      }
      lVar8 = lVar9 + (ulong)uVar14 * 0x1c0;
      uVar7 = *(ulong *)(lVar8 + 0x148);
      *(ulong *)(lVar8 + 0x158) = uVar5;
      if ((uVar15 < uVar7) || (*(ulong *)(lVar9 + (ulong)uVar14 * 0x1c0 + 0x178) <= uVar15)) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x112148);
        (*pcVar3)();
      }
      uVar13 = 0;
      uVar10 = (uint)*(byte *)(lVar9 + (ulong)uVar14 * 0x1c0 + 0x174);
      if (uVar10 != 0) {
        uVar13 = (uint)((int)uVar15 - (int)uVar7) / uVar10;
      }
      uVar15 = (ulong)uVar13;
      uVar6 = 0x10;
    }
    *(undefined1 *)((long)param_2 + 0x16) = uVar6;
    lVar8 = (uVar15 & 0xffff) * 0x10;
    lVar11 = lVar9 + (ulong)uVar14 * 0x1c0;
    lVar12 = *(long *)(lVar11 + 0x180);
    if (*(char *)(lVar12 + lVar8) == '\0') {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1123ec);
      (*pcVar3)();
    }
    param_2[1] = *(undefined8 *)(lVar12 + (uVar15 & 0xffff) * 0x10 + 8);
    if (((param_3 & 1) == 0) ||
       ((*(int *)(lVar17 + 0xbc) == 1 && (*(char *)(lVar17 + 0x109) == '\0')))) {
      lVar11 = *(long *)(lVar11 + 0x180);
      lVar12 = lVar9 + (ulong)uVar14 * 0x1c0;
      *(long *)(lVar12 + 0x208) = *(long *)(lVar12 + 0x208) + 1;
      *(undefined1 *)(lVar11 + lVar8) = 0;
      *param_2 = *(undefined8 *)(lVar17 + 0x128);
      *(uint *)(param_2 + 2) = (uint)*(byte *)((long)puVar16 + 0xb);
      *(short *)((long)param_2 + 0x14) = (short)puVar16[1];
      if ((param_3 & 1) == 0) {
        if (0x24 < *(byte *)((long)puVar16 + 0xf)) goto LAB_001123f4;
        goto LAB_00112288;
      }
    }
    else {
      *param_2 = *(undefined8 *)(lVar17 + 0x128);
      *(uint *)(param_2 + 2) = (uint)*(byte *)((long)puVar16 + 0xb);
      *(short *)((long)param_2 + 0x14) = (short)puVar16[1];
    }
    if (*(int *)(lVar9 + (ulong)uVar14 * 0x1c0 + 0x1e4) != 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Calling client callback in polling mode\n",
               "gsi_process_chan",0x2e3);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d Calling client callback in polling mode\n","gsi_process_chan",0x2e3)
          ;
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                         "%s:%d Calling client callback in polling mode\n","gsi_process_chan",0x2e3)
          ;
        }
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x112364);
      (*pcVar3)();
    }
    if (*(int *)(*(code **)(lVar17 + 0x110) + -4) != -0xcd7dd56) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x112248);
      (*pcVar3)();
    }
    (**(code **)(lVar17 + 0x110))(param_2);
    if ((ulong)*(byte *)((long)puVar16 + 0xf) < 0x25) {
      lVar9 = gsi_ctx + (ulong)*(byte *)((long)puVar16 + 0xf) * 0x1c0;
      if (*(int *)(lVar9 + 0xbc) == 0) {
        return;
      }
      if (*(char *)(lVar9 + 0x109) != '\0') {
        return;
      }
LAB_00112288:
      lVar9 = *(long *)(param_1 + 0xb8) + (ulong)*(byte *)(param_1 + 0xc4);
      *(long *)(param_1 + 0xb8) = lVar9;
      if (lVar9 == *(long *)(param_1 + 200)) {
        *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0x98);
      }
      lVar9 = *(long *)(param_1 + 0xb0) + (ulong)*(byte *)(param_1 + 0xc4);
      *(long *)(param_1 + 0xb0) = lVar9;
      if (lVar9 == *(long *)(param_1 + 200)) {
        *(undefined8 *)(param_1 + 0xb0) = *(undefined8 *)(param_1 + 0x98);
      }
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      return;
    }
  }
LAB_001123f4:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1123f8);
  (*pcVar3)();
}



//------------------------------------------------------------
// gsi_config_channel_mode @ 001123fc size=2084
// signature: undefined gsi_config_channel_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_config_channel_mode(ulong param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  long lVar13;
  ulong uVar14;
  undefined4 *puVar15;
  long *plVar16;
  long lVar17;
  long lVar18;
  int *piVar19;
  
  lVar18 = gsi_ctx;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_config_channel_mode",0x11be);
    return 0xfffffff8;
  }
  if (*(uint *)(gsi_ctx + 0x6fc0) <= param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu mode=%u\n",
             "gsi_config_channel_mode",0x11c3,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu mode=%u\n",
                       "gsi_config_channel_mode",0x11c3,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu mode=%u\n",
                       "gsi_config_channel_mode",0x11c3,param_1,param_2);
        return 0xfffffffa;
      }
    }
    return 0xfffffffa;
  }
  if (0x24 < param_1) {
LAB_00112c1c:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x112c20);
    (*pcVar5)();
  }
  piVar19 = (int *)(gsi_ctx + param_1 * 0x1c0 + 0xb8);
  if (*piVar19 != 2 && *piVar19 != 5) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d op not supported for protocol %u\n",
             "gsi_config_channel_mode",0x11cb);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d op not supported for protocol %u\n",
                       "gsi_config_channel_mode",0x11cb,*piVar19);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d op not supported for protocol %u\n",
                       "gsi_config_channel_mode",0x11cb,*piVar19);
        return 0xfffffff9;
      }
    }
    return 0xfffffff9;
  }
  lVar13 = gsi_ctx + param_1 * 0x1c0;
  if (*(long *)(lVar13 + 0x188) == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d cannot configure mode on chan_hdl=%lu\n",
             "gsi_config_channel_mode",0x11d1,param_1);
    if (gsi_ctx == 0) {
      return 0xfffffff9;
    }
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d cannot configure mode on chan_hdl=%lu\n",
                     "gsi_config_channel_mode",0x11d1,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
      return 0xfffffff9;
    }
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d cannot configure mode on chan_hdl=%lu\n",
                   "gsi_config_channel_mode",0x11d1,param_1);
    return 0xfffffff9;
  }
  lVar17 = gsi_ctx + param_1 * 0x1c0;
  iVar8 = *(int *)(lVar17 + 0x1e4);
  if ((iVar8 != 0) == param_2) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d already in requested mode %u chan_hdl=%lu\n"
                     ,"gsi_config_channel_mode",0x11dc,param_2,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
      return 0xfffffff9;
    }
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d already in requested mode %u chan_hdl=%lu\n",
                   "gsi_config_channel_mode",0x11dc,param_2,param_1);
    return 0xfffffff9;
  }
  plVar16 = (long *)(lVar13 + 0x188);
  piVar1 = (int *)(lVar17 + 0x1e4);
  uVar10 = _raw_spin_lock_irqsave(gsi_ctx + 0x6f90);
  if ((param_2 == 1) && (iVar8 == 0)) {
    if (*(uint *)(gsi_ctx + 0x10) < 10) {
      __gsi_config_ieob_irq
                (*(undefined4 *)(gsi_ctx + 0x14),1 << (ulong)(*(byte *)(*plVar16 + 0x84) & 0x1f),0);
    }
    else if (*(int *)(*plVar16 + 4) != 0) {
      uVar12 = *(undefined4 *)(gsi_ctx + 0x14);
      uVar6 = gsihal_get_ch_reg_idx(*(undefined1 *)(*plVar16 + 0x84));
      uVar7 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar16 + 0x84));
      __gsi_config_ieob_irq_k(uVar12,uVar6,uVar7,0);
    }
    uVar12 = *(undefined4 *)(gsi_ctx + 0x14);
    if (*(uint *)(gsi_ctx + 0x10) < 10) {
      iVar8 = 1 << (ulong)(*(byte *)(*plVar16 + 0x84) & 0x1f);
      uVar11 = 0x14;
      uVar6 = 0;
    }
    else {
      uVar6 = gsihal_get_ch_reg_idx();
      iVar8 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar16 + 0x84));
      uVar11 = 0x85;
    }
    gsihal_write_reg_nk(uVar11,uVar12,uVar6,iVar8);
    *piVar1 = 1;
    lVar13 = *plVar16;
    if (*(char *)(lVar13 + 0x130) != '\0') {
      *(undefined4 *)(*(long *)(lVar13 + 0x120) + 300) = 1;
      lVar13 = *plVar16;
      if (1 < *(byte *)(lVar13 + 0x130)) {
        *(undefined4 *)(*(long *)(lVar13 + 0x128) + 300) = 1;
        lVar13 = *plVar16;
        if (2 < *(byte *)(lVar13 + 0x130)) goto LAB_00112c1c;
      }
    }
    if ((*piVar19 == 5) && (*(long *)(lVar13 + 0x120) != 0)) {
      puVar15 = (undefined4 *)(*(long *)(lVar13 + 0x120) + 300);
LAB_001126dc:
      *puVar15 = 1;
    }
    else if (*(char *)(gsi_ctx + 0x6ff9) == *(char *)(lVar13 + 0x84)) {
      uVar14 = (ulong)*(byte *)(gsi_ctx + 0x6ff8);
      if (0x24 < uVar14) goto LAB_00112c1c;
      if (gsi_ctx + uVar14 * 0x1c0 != -0xb8) {
        puVar15 = (undefined4 *)(gsi_ctx + uVar14 * 0x1c0 + 0x1e4);
        goto LAB_001126dc;
      }
    }
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d set gsi_ctx evtr_id %d to %d mode\n",
                       "gsi_config_channel_mode",0x1203,*(undefined1 *)(*plVar16 + 0x84),1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d set gsi_ctx evtr_id %d to %d mode\n",
                       "gsi_config_channel_mode",0x1203,*(undefined1 *)(*plVar16 + 0x84),1);
      }
    }
    plVar16 = (long *)(lVar18 + param_1 * 0x1c0 + 0x210);
  }
  else {
    if ((param_2 != 0) || (iVar8 == 0)) goto LAB_0011294c;
    *piVar1 = 0;
    lVar13 = *plVar16;
    if (*(char *)(lVar13 + 0x130) != '\0') {
      *(undefined4 *)(*(long *)(lVar13 + 0x120) + 300) = 0;
      lVar13 = *plVar16;
      if (1 < *(byte *)(lVar13 + 0x130)) {
        *(undefined4 *)(*(long *)(lVar13 + 0x128) + 300) = 0;
        lVar13 = *plVar16;
        if (2 < *(byte *)(lVar13 + 0x130)) goto LAB_00112c1c;
      }
    }
    if ((*piVar19 == 5) && (*(long *)(lVar13 + 0x120) != 0)) {
      puVar15 = (undefined4 *)(*(long *)(lVar13 + 0x120) + 300);
LAB_0011279c:
      *puVar15 = 0;
    }
    else if (*(char *)(gsi_ctx + 0x6ff9) == *(char *)(lVar13 + 0x84)) {
      uVar14 = (ulong)*(byte *)(gsi_ctx + 0x6ff8);
      if (0x24 < uVar14) goto LAB_00112c1c;
      if (gsi_ctx + uVar14 * 0x1c0 != -0xb8) {
        puVar15 = (undefined4 *)(gsi_ctx + uVar14 * 0x1c0 + 0x1e4);
        goto LAB_0011279c;
      }
    }
    if (*(uint *)(gsi_ctx + 0x10) < 10) {
      __gsi_config_ieob_irq
                (*(undefined4 *)(gsi_ctx + 0x14),1 << (ulong)(*(byte *)(*plVar16 + 0x84) & 0x1f),
                 0xffffffff);
    }
    else if (*(int *)(*plVar16 + 4) != 0) {
      uVar12 = *(undefined4 *)(gsi_ctx + 0x14);
      uVar6 = gsihal_get_ch_reg_idx(*(undefined1 *)(*plVar16 + 0x84));
      uVar7 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar16 + 0x84));
      __gsi_config_ieob_irq_k(uVar12,uVar6,uVar7,0xffffffff);
    }
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d set gsi_ctx evtr_id %d to %d mode\n",
                       "gsi_config_channel_mode",0x1220,*(undefined1 *)(*plVar16 + 0x84),0);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d set gsi_ctx evtr_id %d to %d mode\n",
                       "gsi_config_channel_mode",0x1220,*(undefined1 *)(*plVar16 + 0x84),0);
      }
    }
    if ((*(int *)(gsi_ctx + 0x10) - 5U < 2) && (*(char *)(gsi_ctx + 0xa8) == '\0')) {
      uVar9 = gsihal_read_reg_nk(0x13,*(undefined4 *)(gsi_ctx + 0x14),0);
      uVar2 = 1 << (ulong)(*(byte *)(*plVar16 + 0x84) & 0x1f);
      if ((uVar2 & uVar9) != 0) {
        uVar12 = *(undefined4 *)(gsi_ctx + 0x14);
        if (*(uint *)(gsi_ctx + 0x10) < 10) {
          __gsi_config_ieob_irq(uVar12,uVar2,0);
          uVar11 = 0x14;
          uVar6 = 0;
          uVar12 = *(undefined4 *)(gsi_ctx + 0x14);
          iVar8 = 1 << (ulong)(*(byte *)(*plVar16 + 0x84) & 0x1f);
        }
        else {
          uVar6 = gsihal_get_ch_reg_idx();
          uVar7 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar16 + 0x84));
          __gsi_config_ieob_irq_k(uVar12,uVar6,uVar7,0);
          uVar12 = *(undefined4 *)(gsi_ctx + 0x14);
          uVar6 = gsihal_get_ch_reg_idx(*(undefined1 *)(*plVar16 + 0x84));
          iVar8 = gsihal_get_ch_reg_mask(*(undefined1 *)(*plVar16 + 0x84));
          uVar11 = 0x85;
        }
        gsihal_write_reg_nk(uVar11,uVar12,uVar6,iVar8);
        _raw_spin_unlock_irqrestore(gsi_ctx + 0x6f90,uVar10);
        uVar10 = _raw_spin_lock_irqsave(*plVar16 + 0x88);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar8 = *piVar1;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
        _raw_spin_unlock_irqrestore(*plVar16 + 0x88,uVar10);
        lVar18 = lVar18 + param_1 * 0x1c0;
        lVar13 = *(long *)(lVar18 + 0x220) + 1;
        *(long *)(lVar18 + 0x220) = lVar13;
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d IEOB WA pnd cnt = %ld prvmode = %d\n",
                           "gsi_config_channel_mode",0x124b,lVar13,iVar8);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d IEOB WA pnd cnt = %ld prvmode = %d\n",
                           "gsi_config_channel_mode",0x124b,*(undefined8 *)(lVar18 + 0x220),iVar8);
          }
        }
        uVar12 = 0;
        if (iVar8 != 1) {
          uVar12 = 0xfffffff3;
        }
        return uVar12;
      }
    }
    plVar16 = (long *)(lVar18 + param_1 * 0x1c0 + 0x218);
  }
  *plVar16 = *plVar16 + 1;
LAB_0011294c:
  _raw_spin_unlock_irqrestore(gsi_ctx + 0x6f90,uVar10);
  return 0;
}



//------------------------------------------------------------
// gsi_get_channel_cfg @ 00112c24 size=672
// signature: undefined gsi_get_channel_cfg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_get_channel_cfg(ulong param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_get_channel_cfg",0x125f);
    return 0xfffffff8;
  }
  if ((param_2 == (undefined8 *)0x0) || (param_3 == (undefined8 *)0x0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params props=%pK scr=%pK\n",
             "gsi_get_channel_cfg",0x1264,param_2,param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params props=%pK scr=%pK\n",
                       "gsi_get_channel_cfg",0x1264,param_2,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params props=%pK scr=%pK\n",
                       "gsi_get_channel_cfg",0x1264,param_2,param_3);
        return 0xfffffffa;
      }
    }
  }
  else {
    if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
      if (0x24 < param_1) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x112ec4);
        (*pcVar4)();
      }
      lVar6 = gsi_ctx + param_1 * 0x1c0;
      if (*(int *)(lVar6 + 0x130) != 0) {
        lVar6 = gsi_ctx + param_1 * 0x1c0;
        mutex_lock(lVar6 + 400);
        uVar2 = *(undefined8 *)(lVar6 + 200);
        uVar5 = *(undefined8 *)(lVar6 + 0xb8);
        param_2[1] = *(undefined8 *)(lVar6 + 0xc0);
        param_2[2] = uVar2;
        *param_2 = uVar5;
        uVar5 = *(undefined8 *)(lVar6 + 0xe8);
        uVar2 = *(undefined8 *)(lVar6 + 0xd0);
        uVar3 = *(undefined8 *)(lVar6 + 0xd8);
        param_2[5] = *(undefined8 *)(lVar6 + 0xe0);
        param_2[6] = uVar5;
        param_2[3] = uVar2;
        param_2[4] = uVar3;
        uVar5 = *(undefined8 *)(lVar6 + 0x108);
        uVar2 = *(undefined8 *)(lVar6 + 0xf0);
        uVar3 = *(undefined8 *)(lVar6 + 0xf8);
        param_2[9] = *(undefined8 *)(lVar6 + 0x100);
        param_2[10] = uVar5;
        param_2[7] = uVar2;
        param_2[8] = uVar3;
        uVar5 = *(undefined8 *)(lVar6 + 0x128);
        uVar2 = *(undefined8 *)(lVar6 + 0x110);
        uVar3 = *(undefined8 *)(lVar6 + 0x118);
        param_2[0xd] = *(undefined8 *)(lVar6 + 0x120);
        param_2[0xe] = uVar5;
        param_2[0xb] = uVar2;
        param_2[0xc] = uVar3;
        uVar2 = *(undefined8 *)(lVar6 + 0x1f8);
        uVar5 = *(undefined8 *)(lVar6 + 0x1e8);
        param_3[1] = *(undefined8 *)(lVar6 + 0x1f0);
        param_3[2] = uVar2;
        *param_3 = uVar5;
        mutex_unlock(lVar6 + 400);
        return 0;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_get_channel_cfg",0x1270,0);
      if (gsi_ctx != 0) {
        puVar1 = (undefined4 *)(lVar6 + 0x130);
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_get_channel_cfg",
                         0x1270,*puVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_get_channel_cfg",
                         0x1270,*puVar1);
          return 0xfffffff9;
        }
      }
      return 0xfffffff9;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_get_channel_cfg",
             0x1269,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_get_channel_cfg",0x1269,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_get_channel_cfg",0x1269,param_1);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_set_channel_cfg @ 00112ec8 size=1056
// signature: undefined gsi_set_channel_cfg(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_set_channel_cfg(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  char *pcVar10;
  undefined1 uVar11;
  long lVar12;
  undefined8 uVar13;
  ulong uVar14;
  long lVar15;
  undefined8 uVar16;
  long lVar17;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_set_channel_cfg",0x1283);
    return 0xfffffff8;
  }
  if ((param_2 == (undefined8 *)0x0) ||
     (iVar9 = gsi_validate_channel_props(param_2), lVar15 = gsi_ctx, iVar9 != 0)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params props=%pK\n","gsi_set_channel_cfg",
             0x1288,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params props=%pK\n",
                       "gsi_set_channel_cfg",0x1288,param_2);
      }
      lVar15 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar15 != 0) {
        pcVar10 = "%s:%d bad params props=%pK\n";
        uVar16 = 0x1288;
        goto LAB_0011324c;
      }
    }
  }
  else {
    if (param_1 < (undefined8 *)(ulong)*(uint *)(gsi_ctx + 0x6fc0)) {
      if ((undefined8 *)0x24 < param_1) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x1132e8);
        (*pcVar8)();
      }
      lVar17 = gsi_ctx + (long)param_1 * 0x1c0;
      if (*(int *)(lVar17 + 0x130) == 1) {
        if ((*(char *)(lVar17 + 0xc0) == *(char *)(param_2 + 1)) &&
           (*(long *)(lVar17 + 200) == param_2[2])) {
          lVar1 = gsi_ctx + (long)param_1 * 0x1c0 + 400;
          mutex_lock(lVar1);
          uVar16 = param_2[2];
          uVar13 = *param_2;
          *(undefined8 *)(lVar17 + 0xc0) = param_2[1];
          *(undefined8 *)(lVar17 + 200) = uVar16;
          *(undefined8 *)(lVar17 + 0xb8) = uVar13;
          uVar13 = param_2[6];
          uVar16 = param_2[3];
          uVar3 = param_2[4];
          *(undefined8 *)(lVar17 + 0xe0) = param_2[5];
          *(undefined8 *)(lVar17 + 0xe8) = uVar13;
          *(undefined8 *)(lVar17 + 0xd0) = uVar16;
          *(undefined8 *)(lVar17 + 0xd8) = uVar3;
          uVar13 = param_2[10];
          uVar16 = param_2[7];
          uVar3 = param_2[8];
          *(undefined8 *)(lVar17 + 0x100) = param_2[9];
          *(undefined8 *)(lVar17 + 0x108) = uVar13;
          *(undefined8 *)(lVar17 + 0xf0) = uVar16;
          *(undefined8 *)(lVar17 + 0xf8) = uVar3;
          uVar13 = param_2[0xe];
          uVar16 = param_2[0xb];
          uVar3 = param_2[0xc];
          *(undefined8 *)(lVar17 + 0x120) = param_2[0xd];
          *(undefined8 *)(lVar17 + 0x128) = uVar13;
          *(undefined8 *)(lVar17 + 0x110) = uVar16;
          *(undefined8 *)(lVar17 + 0x118) = uVar3;
          if (param_3 != (undefined8 *)0x0) {
            uVar13 = *param_3;
            uVar16 = param_3[2];
            lVar12 = lVar15 + (long)param_1 * 0x1c0;
            *(undefined8 *)(lVar12 + 0x1f0) = param_3[1];
            *(undefined8 *)(lVar12 + 0x1f8) = uVar16;
            *(undefined8 *)(lVar12 + 0x1e8) = uVar13;
          }
          lVar12 = *(long *)(lVar15 + (long)param_1 * 0x1c0 + 0x188);
          if (lVar12 == 0) {
            uVar11 = 0xff;
          }
          else {
            uVar11 = *(undefined1 *)(lVar12 + 0x84);
          }
          gsi_program_chan_ctx((undefined8 *)(lVar17 + 0xb8),*(undefined4 *)(gsi_ctx + 0x14),uVar11)
          ;
          uVar2 = *(uint *)(lVar17 + 0xd0);
          lVar12 = *(long *)(lVar17 + 0xe0);
          uVar16 = *(undefined8 *)(lVar17 + 0xf0);
          lVar15 = lVar15 + (long)param_1 * 0x1c0;
          uVar14 = (ulong)uVar2 & 0xff;
          uVar7 = 0;
          if ((uint)uVar14 != 0) {
            uVar7 = *(uint *)(lVar17 + 0xd4) / (uint)uVar14;
          }
          *(uint *)(lVar15 + 0x170) = *(uint *)(lVar17 + 0xd4);
          *(undefined8 *)(lVar15 + 0x140) = uVar16;
          *(long *)(lVar15 + 0x148) = lVar12;
          uVar4 = *(undefined4 *)(lVar15 + 0x1ec);
          *(long *)(lVar15 + 0x150) = lVar12;
          *(long *)(lVar15 + 0x158) = lVar12;
          uVar5 = *(undefined4 *)(lVar15 + 0x1f0);
          *(long *)(lVar15 + 0x160) = lVar12;
          *(long *)(lVar15 + 0x168) = lVar12;
          uVar6 = *(undefined4 *)(lVar15 + 500);
          *(char *)(lVar15 + 0x174) = (char)uVar2;
          *(short *)(lVar15 + 0x176) = (short)(uVar7 - 1);
          *(ulong *)(lVar15 + 0x178) = uVar14 + uVar14 * (uVar7 - 1 & 0xffff) + lVar12;
          gsihal_write_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),(ulong)param_1 & 0xffffffff,
                              *(undefined4 *)(lVar15 + 0x1e8));
          gsihal_write_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),(ulong)param_1 & 0xffffffff,uVar4
                             );
          gsihal_write_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),(ulong)param_1 & 0xffffffff,uVar5
                             );
          gsihal_write_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),(ulong)param_1 & 0xffffffff,uVar6
                             );
          mutex_unlock(lVar1);
          return 0;
        }
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d changing immutable fields not supported\n",
                 "gsi_set_channel_cfg",0x129a);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d changing immutable fields not supported\n","gsi_set_channel_cfg",
                           0x129a);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d changing immutable fields not supported\n","gsi_set_channel_cfg",
                           0x129a);
            return 0xfffffff9;
          }
        }
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_set_channel_cfg",0x1294);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_set_channel_cfg",
                           0x1294,*(undefined4 *)(lVar17 + 0x130));
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_set_channel_cfg",
                           0x1294,*(undefined4 *)(lVar17 + 0x130));
            return 0xfffffff9;
          }
        }
      }
      return 0xfffffff9;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_set_channel_cfg",
             0x128d,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_set_channel_cfg",0x128d,param_1);
      }
      lVar15 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar15 != 0) {
        pcVar10 = "%s:%d bad params chan_hdl=%lu\n";
        uVar16 = 0x128d;
        param_2 = param_1;
LAB_0011324c:
        ipc_log_string(lVar15,pcVar10,"gsi_set_channel_cfg",uVar16,param_2);
        return 0xfffffffa;
      }
    }
  }
  return 0xfffffffa;
}



//------------------------------------------------------------
// gsi_configure_regs @ 001132ec size=1256
// signature: undefined gsi_configure_regs(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_configure_regs(undefined4 param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (gsi_ctx == (long *)0x0) {
    _printk(&DAT_00132af7,"gsi_configure_regs",0x12f1);
    uVar1 = 0xfffffff8;
  }
  else if (*gsi_ctx == 0) {
    _dev_err(gsi_ctx[1],"%s:%d access to GSI HW has not been mapped\n","gsi_configure_regs",0x12f6);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d access to GSI HW has not been mapped\n",
                       "gsi_configure_regs",0x12f6);
      }
      if (gsi_ctx[0xdfe] != 0) {
        ipc_log_string(gsi_ctx[0xdfe],"%s:%d access to GSI HW has not been mapped\n",
                       "gsi_configure_regs",0x12f6);
        return 0xfffffffa;
      }
    }
    uVar1 = 0xfffffffa;
  }
  else if (param_2 - 0xe < 0xfffffff3) {
    _dev_err(gsi_ctx[1],"%s:%d Incorrect version %d\n","gsi_configure_regs",0x12fb,param_2);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d Incorrect version %d\n","gsi_configure_regs",0x12fb,
                       param_2);
      }
      if (gsi_ctx[0xdfe] != 0) {
        ipc_log_string(gsi_ctx[0xdfe],"%s:%d Incorrect version %d\n","gsi_configure_regs",0x12fb,
                       param_2);
      }
    }
    uVar1 = 0xffffffff;
  }
  else {
    gsihal_write_reg_nk(0x72,0,0,0);
    gsihal_write_reg_nk(0x73,0,0,param_1);
    gsihal_write_reg_nk(0x5c,0,0,0xfffffffe);
    gsihal_write_reg_nk(0x5d,0,0,0xffffffff);
    gsihal_write_reg_nk(0x5e,0,0,0xffffffbf);
    gsihal_write_reg_nk(0x5f,0,0,0xffffffff);
    gsihal_write_reg_nk(0x60,0,0,0xffffefff);
    gsihal_write_reg_nk(0x61,0,0,0xffffffff);
    gsihal_write_reg_nk(0x62,0,0,0xffffefff);
    gsihal_write_reg_nk(99,0,0,0xffffffff);
    gsihal_write_reg_nk(100,0,0,0);
    gsihal_write_reg_nk(0x65,0,0,0);
    gsihal_write_reg_nk(0x66,0,0,0xf9ffffff);
    gsihal_write_reg_nk(0x67,0,0,0xffffffff);
    gsihal_write_reg_nk(0x68,0,0,0xf9ffffff);
    gsihal_write_reg_nk(0x69,0,0,0xffffffff);
    gsihal_write_reg_nk(0x6a,0,0,0xffffffff);
    gsihal_write_reg_nk(0x6b,0,0,0xfffffffe);
    gsihal_write_reg_nk(0x6c,0,0,0xffffffff);
    gsihal_write_reg_nk(0x6d,0,0,0xffffefff);
    gsihal_write_reg_nk(0x6e,0,0,0xffffffff);
    gsihal_write_reg_nk(0x6f,0,0,0xffffdfff);
    gsihal_write_reg_nk(0x70,0,0,0xffffffff);
    gsihal_write_reg_nk(0x71,0,0,0xff03ffff);
    gsihal_write_reg_nk(0x4b,0,0,1);
    gsihal_write_reg_nk(0x4c,0,0,2);
    gsihal_write_reg_nk(0x4d,0,0,3);
    gsihal_write_reg_nk(0x4e,0,0,4);
    gsihal_write_reg_nk(0x4f,0,0,5);
    gsihal_write_reg_nk(0x50,0,0,6);
    gsihal_write_reg_nk(0x51,0,0,7);
    gsihal_write_reg_nk(0x52,0,0,8);
    gsihal_write_reg_nk(0x53,0,0,9);
    gsihal_write_reg_nk(0x54,0,0,10);
    gsihal_write_reg_nk(0x55,0,0,0xb);
    gsihal_write_reg_nk(0x56,0,0,0xc);
    gsihal_write_reg_nk(0x57,0,0,0xd);
    gsihal_write_reg_nk(0x58,0,0,0xe);
    gsihal_write_reg_nk(0x59,0,0,0xf);
    gsihal_write_reg_nk(0x5a,0,0,0x10);
    uVar1 = 0;
    if (5 < param_2) {
      gsihal_write_reg_nk(0x5b,0,0,0x11);
      uVar1 = 0;
      if (8 < param_2) {
        gsihal_write_reg_nk(0x7b,0,0,0x12);
        uVar1 = 0;
        if (param_2 != 9) {
          gsihal_write_reg_nk(0x7c,0,0,0x13);
          uVar1 = 0;
        }
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// gsi_enable_fw @ 001137d8 size=320
// signature: undefined gsi_enable_fw(void)
// callers: []
//------------------------------------------------------------

void gsi_enable_fw(undefined8 param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_48;
  undefined8 local_40;
  ulong local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_38 = 0;
  local_48 = 0;
  if (param_3 - 0xe < 0xfffffff3) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Incorrect version %d\n","gsi_enable_fw",0x130d,
             param_3);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Incorrect version %d\n","gsi_enable_fw",
                       0x130d,param_3);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Incorrect version %d\n","gsi_enable_fw",
                       0x130d,param_3);
      }
    }
    uVar2 = 0xffffffff;
  }
  else {
    local_40 = 0;
    local_30 = 1;
    local_38 = 1;
    if (param_3 < 2) {
      local_38 = 0x100000001;
    }
    else {
      gsihal_write_reg_nk(0x74,0,0,1);
      local_38 = local_38 & 0xffffffff;
      if (5 < param_3) {
        local_48 = CONCAT44(local_48._4_4_,2);
      }
    }
    gsihal_write_reg_fields(0x75,&local_48);
    uVar2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// gsi_get_inst_ram_offset_and_size @ 0011391c size=120
// signature: undefined gsi_get_inst_ram_offset_and_size(void)
// callers: []
//------------------------------------------------------------

void gsi_get_inst_ram_offset_and_size(ulong *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_get_inst_ram_offset_and_size",0x132e);
  }
  else {
    if (param_2 != (undefined8 *)0x0) {
      uVar1 = gsihal_get_inst_ram_size();
      *param_2 = uVar1;
    }
    if (param_1 != (ulong *)0x0) {
      uVar2 = gsihal_get_reg_nk_ofst(0x7a,0,0);
      *param_1 = uVar2 & 0xffffffff;
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_halt_channel_ee @ 00113998 size=1280
// signature: undefined gsi_halt_channel_ee(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_halt_channel_ee(uint param_1,undefined4 param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_58 = 0;
  local_50 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_halt_channel_ee",0x135f);
    uVar7 = 0xfffffff8;
    goto LAB_00113b90;
  }
  if ((param_3 == (uint *)0x0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_idx=%d\n","gsi_halt_channel_ee",
             0x1364,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_idx=%d\n",
                       "gsi_halt_channel_ee",0x1364,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_idx=%d\n",
                       "gsi_halt_channel_ee",0x1364,param_1);
        uVar7 = 0xfffffffa;
        goto LAB_00113b90;
      }
    }
    uVar7 = 0xfffffffa;
    goto LAB_00113b90;
  }
  mutex_lock(gsi_ctx + 0x6f60);
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar3 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar4 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar4 | uVar3);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(undefined4 *)(gsi_ctx + 0x6fc8) = 0;
  uVar3 = gsihal_read_reg_nk(0x24,*puVar1,0);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(uint *)(gsi_ctx + 0x6fac) = uVar3 & 0xffffff1f;
  gsihal_write_reg_nk(0x24,*puVar1,0);
  local_50 = CONCAT44(local_50._4_4_,param_2);
  local_58 = CONCAT44(param_1,1);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(long *)(gsi_ctx + 0x6f50) = *(long *)(gsi_ctx + 0x6f50) + 1;
  gsihal_write_reg_n_fields(0x76,*puVar1,&local_58);
  iVar5 = wait_for_completion_timeout(gsi_ctx + 0x6fc8,0x139);
  if (iVar5 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_idx=%u ee=%u timed out\n",
             "gsi_halt_channel_ee",0x137c,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_halt_channel_ee",0x137c,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_halt_channel_ee",0x137c,param_1,param_2);
        uVar7 = 0xfffffff5;
        goto LAB_00113b4c;
      }
    }
    uVar7 = 0xfffffff5;
  }
  else {
    uVar4 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
    lVar6 = gsi_ctx;
    uVar3 = uVar4 >> 5 & 7;
    *(uint *)(gsi_ctx + 0x6fac) = uVar4;
    if (uVar3 == 6) {
      if (lVar6 != 0) {
        if (*(long *)(lVar6 + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(lVar6 + 0x6fe8),"%s:%d chan_idx=%u ee=%u busy try again\n",
                         "gsi_halt_channel_ee",0x1385,param_1,param_2);
          lVar6 = gsi_ctx;
        }
        if (*(long *)(lVar6 + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(lVar6 + 0x6ff0),"%s:%d chan_idx=%u ee=%u busy try again\n",
                         "gsi_halt_channel_ee",0x1385,param_1,param_2);
        }
      }
      uVar7 = 0xfffffff4;
      *param_3 = 6;
    }
    else {
      if (uVar3 == 0) {
        _dev_err(*(undefined8 *)(lVar6 + 8),"%s:%d No response received\n","gsi_halt_channel_ee",
                 0x138b);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d No response received\n",
                           "gsi_halt_channel_ee",0x138b);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d No response received\n",
                           "gsi_halt_channel_ee",0x138b);
          }
        }
        gsi_dump_halt_debug_reg(param_1,param_2);
        usleep_range_state(1000,2000,2);
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Reading after usleep scratch 0 reg\n",
                 "gsi_halt_channel_ee",0x138e);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Reading after usleep scratch 0 reg\n",
                           "gsi_halt_channel_ee",0x138e);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Reading after usleep scratch 0 reg\n",
                           "gsi_halt_channel_ee",0x138e);
          }
        }
        uVar3 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
        lVar6 = gsi_ctx;
        *(uint *)(gsi_ctx + 0x6fac) = uVar3;
        if ((uVar3 & 0xe0) == 0) {
          _dev_err(*(undefined8 *)(lVar6 + 8),"%s:%d No response received second attempt\n",
                   "gsi_halt_channel_ee",0x1392);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                             "%s:%d No response received second attempt\n","gsi_halt_channel_ee",
                             0x1392);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                             "%s:%d No response received second attempt\n","gsi_halt_channel_ee",
                             0x1392);
            }
          }
          gsi_dump_halt_debug_reg(param_1,param_2);
          uVar7 = 0xffffffff;
          goto LAB_00113b4c;
        }
        uVar3 = uVar3 >> 5 & 7;
      }
      uVar7 = 0;
      *param_3 = uVar3;
    }
  }
LAB_00113b4c:
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar3 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar4 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar4 & (uVar3 ^ 0xffffffff));
  mutex_unlock(gsi_ctx + 0x6f60);
LAB_00113b90:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// gsi_dump_halt_debug_reg @ 00113e98 size=1356
// signature: undefined gsi_dump_halt_debug_reg(void)
// callers: [gsi_halt_channel_ee]
//------------------------------------------------------------

void gsi_dump_halt_debug_reg(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
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
  uVar2 = *(undefined8 *)(gsi_ctx + 8);
  uVar1 = gsihal_read_reg_nk(0x94,0,0);
  _dev_err(uVar2,"%s:%d DEBUG_PC_FOR_DEBUG = 0x%x\n","gsi_dump_halt_debug_reg",0x1343,uVar1);
  lVar3 = 0;
  if (gsi_ctx != 0) {
    lVar3 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(0x94,0,0);
      ipc_log_string(lVar3,"%s:%d DEBUG_PC_FOR_DEBUG = 0x%x\n","gsi_dump_halt_debug_reg",0x1343,
                     uVar1);
    }
    lVar4 = *(long *)(gsi_ctx + 0x6ff0);
    lVar3 = gsi_ctx;
    if (lVar4 != 0) {
      uVar1 = gsihal_read_reg_nk(0x94,0,0);
      ipc_log_string(lVar4,"%s:%d DEBUG_PC_FOR_DEBUG = 0x%x\n","gsi_dump_halt_debug_reg",0x1343,
                     uVar1);
      lVar3 = gsi_ctx;
    }
  }
  uVar2 = *(undefined8 *)(lVar3 + 8);
  uVar1 = gsihal_read_reg_nk(0x95,0,0);
  _dev_err(uVar2,"%s:%d GSI_DEBUG_BUSY_REG 0x%x\n","gsi_dump_halt_debug_reg",0x1346,uVar1);
  if (gsi_ctx != 0) {
    lVar3 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(0x95,0,0);
      ipc_log_string(lVar3,"%s:%d GSI_DEBUG_BUSY_REG 0x%x\n","gsi_dump_halt_debug_reg",0x1346,uVar1)
      ;
    }
    lVar3 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(0x95,0,0);
      ipc_log_string(lVar3,"%s:%d GSI_DEBUG_BUSY_REG 0x%x\n","gsi_dump_halt_debug_reg",0x1346,uVar1)
      ;
    }
  }
  uVar2 = *(undefined8 *)(gsi_ctx + 8);
  uVar1 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
  _dev_err(uVar2,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n","gsi_dump_halt_debug_reg",0x1349,
           uVar1);
  if (gsi_ctx != 0) {
    lVar3 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
      ipc_log_string(lVar3,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n",
                     "gsi_dump_halt_debug_reg",0x1349,uVar1);
    }
    lVar3 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
      ipc_log_string(lVar3,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n",
                     "gsi_dump_halt_debug_reg",0x1349,uVar1);
    }
  }
  uVar2 = *(undefined8 *)(gsi_ctx + 8);
  uVar1 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
  _dev_err(uVar2,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n",
           "gsi_dump_halt_debug_reg",0x134c,uVar1);
  if (gsi_ctx != 0) {
    lVar3 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
      ipc_log_string(lVar3,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n",
                     "gsi_dump_halt_debug_reg",0x134c,uVar1);
    }
    lVar3 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
      ipc_log_string(lVar3,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n",
                     "gsi_dump_halt_debug_reg",0x134c,uVar1);
    }
  }
  uVar2 = *(undefined8 *)(gsi_ctx + 8);
  uVar1 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
  _dev_err(uVar2,"%s:%d GSI_EE_n_CNTXT_SCRATCH_0_OFFS = 0x%x\n","gsi_dump_halt_debug_reg",0x134f,
           uVar1);
  if (gsi_ctx != 0) {
    lVar3 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
      ipc_log_string(lVar3,"%s:%d GSI_EE_n_CNTXT_SCRATCH_0_OFFS = 0x%x\n","gsi_dump_halt_debug_reg",
                     0x134f,uVar1);
    }
    lVar3 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar3 != 0) {
      uVar1 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
      ipc_log_string(lVar3,"%s:%d GSI_EE_n_CNTXT_SCRATCH_0_OFFS = 0x%x\n","gsi_dump_halt_debug_reg",
                     0x134f,uVar1);
    }
  }
  if (7 < *(uint *)(gsi_ctx + 0x10)) {
    uVar2 = *(undefined8 *)(gsi_ctx + 8);
    uVar1 = gsihal_read_reg_nk(0x3c,param_2,param_1);
    _dev_err(uVar2,"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_4 = 0x%x\n","gsi_dump_halt_debug_reg",0x1352,
             uVar1);
    if (gsi_ctx != 0) {
      lVar3 = *(long *)(gsi_ctx + 0x6fe8);
      if (lVar3 != 0) {
        uVar1 = gsihal_read_reg_nk(0x3c,param_2,param_1);
        ipc_log_string(lVar3,"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_4 = 0x%x\n","gsi_dump_halt_debug_reg",
                       0x1352,uVar1);
      }
      lVar3 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar3 != 0) {
        uVar1 = gsihal_read_reg_nk(0x3c,param_2,param_1);
        ipc_log_string(lVar3,"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_4 = 0x%x\n","gsi_dump_halt_debug_reg",
                       0x1352,uVar1);
      }
    }
  }
  gsihal_read_reg_nk_fields(8,param_2,param_1,&local_58);
  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Q6 channel [%d] state =  %d\n",
           "gsi_dump_halt_debug_reg",0x1355,param_1,local_58._4_4_);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Q6 channel [%d] state =  %d\n",
                     "gsi_dump_halt_debug_reg",0x1355,param_1,local_58._4_4_);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Q6 channel [%d] state =  %d\n",
                     "gsi_dump_halt_debug_reg",0x1355,param_1,local_58._4_4_);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_alloc_channel_ee @ 001143e8 size=1652
// signature: undefined gsi_alloc_channel_ee(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_alloc_channel_ee(uint param_1,int param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  undefined4 local_60;
  uint uStack_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint uStack_4c;
  long local_48;
  
  lVar10 = gsi_ctx;
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  local_54 = 0;
  if ((param_3 == (uint *)0x0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_idx=%d\n","gsi_alloc_channel_ee",
             0x13ac,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_idx=%d\n",
                       "gsi_alloc_channel_ee",0x13ac,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_idx=%d\n",
                       "gsi_alloc_channel_ee",0x13ac,param_1);
        uVar8 = 0xfffffffa;
        goto LAB_001146c8;
      }
    }
    uVar8 = 0xfffffffa;
    goto LAB_001146c8;
  }
  if (param_2 == 0) {
    if (gsi_ctx == 0) {
      _printk(&DAT_00132af7,"gsi_alloc_ap_channel",0xbea);
      uVar8 = 0xfffffff8;
    }
    else {
      if (0x24 < param_1) {
LAB_00114a58:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x114a5c);
        (*pcVar3)();
      }
      if (*(char *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0x1e0) == '\0') {
        lVar9 = gsi_ctx + (ulong)param_1 * 0x1c0;
        memset((void *)(lVar9 + 0xb8),0,0x1c0);
        __mutex_init(lVar9 + 400,"&ctx->mlock",&gsi_alloc_ap_channel___key);
        *(undefined4 *)(lVar9 + 0x1c0) = 0;
        __init_swait_queue_head(lVar9 + 0x1c8,"&x->wait",&init_completion___key);
        *(undefined4 *)(lVar9 + 0x1e4) = 0;
        mutex_lock(gsi_ctx + 0x6f60);
        if (0x23 < param_1) goto LAB_00114a58;
        lVar7 = gsi_ctx + (ulong)param_1 * 0x38;
        uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
        *(long *)(lVar7 + 0x3fb8) = *(long *)(lVar7 + 0x3fb8) + 1;
        local_50 = 0;
        uStack_4c = param_1;
        gsihal_write_reg_n_fields(0x37,uVar2,&local_50);
        iVar6 = wait_for_completion_timeout(lVar9 + 0x1c0,0x4e2);
        if (iVar6 == 0) {
          _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u timed out\n",
                   "gsi_alloc_ap_channel",0xc02,param_1);
          if (gsi_ctx != 0) {
            if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_hdl=%u timed out\n",
                             "gsi_alloc_ap_channel",0xc02,param_1);
            }
            if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
              ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_hdl=%u timed out\n",
                             "gsi_alloc_ap_channel",0xc02,param_1);
            }
          }
          mutex_unlock(gsi_ctx + 0x6f60);
          uVar8 = 0xfffffff5;
        }
        else {
          lVar10 = lVar10 + (ulong)param_1 * 0x1c0;
          if (*(int *)(lVar10 + 0x130) == 1) {
            mutex_unlock(gsi_ctx + 0x6f60);
            uVar8 = 0;
          }
          else {
            _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_hdl=%u allocation failed state=%d\n",
                     "gsi_alloc_ap_channel",0xc08,param_1);
            if (gsi_ctx != 0) {
              puVar1 = (undefined4 *)(lVar10 + 0x130);
              if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                               "%s:%d chan_hdl=%u allocation failed state=%d\n",
                               "gsi_alloc_ap_channel",0xc08,param_1,*puVar1);
              }
              if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                               "%s:%d chan_hdl=%u allocation failed state=%d\n",
                               "gsi_alloc_ap_channel",0xc08,param_1,*puVar1);
              }
            }
            mutex_unlock(gsi_ctx + 0x6f60);
            uVar8 = 0xfffffffc;
          }
        }
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan %d already allocated\n",
                 "gsi_alloc_ap_channel",0xbf0,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan %d already allocated\n",
                           "gsi_alloc_ap_channel",0xbf0,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan %d already allocated\n",
                           "gsi_alloc_ap_channel",0xbf0,param_1);
            uVar8 = 0xfffffff8;
            goto LAB_001146c8;
          }
        }
        uVar8 = 0xfffffff8;
      }
    }
    goto LAB_001146c8;
  }
  mutex_lock(gsi_ctx + 0x6f60);
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar4 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar5 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar5 | uVar4);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(undefined4 *)(gsi_ctx + 0x6fc8) = 0;
  uVar4 = gsihal_read_reg_nk(0x24,*puVar1,0);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(uint *)(gsi_ctx + 0x6fac) = uVar4 & 0xffffff1f;
  gsihal_write_reg_nk(0x24,*puVar1,0);
  local_60 = 2;
  uStack_5c = param_1;
  local_58 = param_2;
  gsihal_write_reg_n_fields(0x76,*(undefined4 *)(gsi_ctx + 0x14),&local_60);
  iVar6 = wait_for_completion_timeout(gsi_ctx + 0x6fc8,0x139);
  if (iVar6 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_idx=%u ee=%u timed out\n",
             "gsi_alloc_channel_ee",0x13c7,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_alloc_channel_ee",0x13c7,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_alloc_channel_ee",0x13c7,param_1,param_2);
        uVar8 = 0xfffffff5;
        goto LAB_00114684;
      }
    }
    uVar8 = 0xfffffff5;
  }
  else {
    uVar5 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
    lVar9 = gsi_ctx;
    uVar4 = uVar5 >> 5 & 7;
    *(uint *)(gsi_ctx + 0x6fac) = uVar5;
    if (uVar4 == 7) {
      if (lVar9 != 0) {
        if (*(long *)(lVar9 + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(lVar9 + 0x6fe8),"%s:%d chan_idx=%u ee=%u out of resources\n",
                         "gsi_alloc_channel_ee",0x13d0,param_1,param_2);
          lVar9 = gsi_ctx;
        }
        if (*(long *)(lVar9 + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(lVar9 + 0x6ff0),"%s:%d chan_idx=%u ee=%u out of resources\n",
                         "gsi_alloc_channel_ee",0x13d0,param_1,param_2);
        }
      }
      uVar8 = 0xfffffffc;
      *param_3 = 7;
    }
    else if (uVar4 == 0) {
      _dev_err(*(undefined8 *)(lVar9 + 8),"%s:%d No response received\n","gsi_alloc_channel_ee",
               0x13d6);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d No response received\n",
                         "gsi_alloc_channel_ee",0x13d6);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d No response received\n",
                         "gsi_alloc_channel_ee",0x13d6);
          uVar8 = 0xffffffff;
          goto LAB_00114684;
        }
      }
      uVar8 = 0xffffffff;
    }
    else {
      uVar8 = 0;
      *param_3 = uVar4;
    }
  }
LAB_00114684:
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar4 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar5 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar5 & (uVar4 ^ 0xffffffff));
  mutex_unlock(gsi_ctx + 0x6f60);
LAB_001146c8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// gsi_enable_flow_control_ee @ 00114a60 size=1420
// signature: undefined gsi_enable_flow_control_ee(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_enable_flow_control_ee(uint param_1,undefined4 param_2,uint *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  local_70 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_enable_flow_control_ee",0x13f3);
    uVar8 = 0xfffffff8;
    goto LAB_00114cfc;
  }
  if ((param_3 == (uint *)0x0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_idx=%d\n",
             "gsi_enable_flow_control_ee",0x13f8,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_idx=%d\n",
                       "gsi_enable_flow_control_ee",0x13f8,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_idx=%d\n",
                       "gsi_enable_flow_control_ee",0x13f8,param_1);
        uVar8 = 0xfffffffa;
        goto LAB_00114cfc;
      }
    }
    uVar8 = 0xfffffffa;
    goto LAB_00114cfc;
  }
  mutex_lock(gsi_ctx + 0x6f60);
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar4 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar5 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar5 | uVar4);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(undefined4 *)(gsi_ctx + 0x6fc8) = 0;
  uVar4 = gsihal_read_reg_nk(0x24,*puVar1,0);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(uint *)(gsi_ctx + 0x6fac) = uVar4 & 0xffffff1f;
  gsihal_write_reg_nk(0x24,*puVar1,0);
  local_70 = CONCAT44(local_70._4_4_,param_2);
  local_78 = CONCAT44(param_1,3);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(long *)(gsi_ctx + 0x6f58) = *(long *)(gsi_ctx + 0x6f58) + 1;
  gsihal_write_reg_n_fields(0x76,*puVar1,&local_78);
  iVar6 = wait_for_completion_timeout(gsi_ctx + 0x6fc8,0x139);
  if (iVar6 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_idx=%u ee=%u timed out\n",
             "gsi_enable_flow_control_ee",0x1412,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_enable_flow_control_ee",0x1412,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_enable_flow_control_ee",0x1412,param_1,param_2);
        uVar8 = 0xfffffff5;
        goto LAB_00114cb8;
      }
    }
    uVar8 = 0xfffffff5;
  }
  else {
    uVar5 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
    lVar7 = gsi_ctx;
    uVar4 = uVar5 >> 5 & 7;
    *(uint *)(gsi_ctx + 0x6fac) = uVar5;
    if (uVar4 == 2) {
      if (lVar7 != 0) {
        if (*(long *)(lVar7 + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(lVar7 + 0x6fe8),"%s:%d chan_idx=%u ee=%u not in correct state\n",
                         "gsi_enable_flow_control_ee",0x141c,param_1,param_2);
          lVar7 = gsi_ctx;
        }
        if (*(long *)(lVar7 + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(lVar7 + 0x6ff0),"%s:%d chan_idx=%u ee=%u not in correct state\n",
                         "gsi_enable_flow_control_ee",0x141c,param_1,param_2);
        }
      }
      uVar4 = 2;
      uVar8 = 0xfffffffc;
    }
    else {
      if (uVar4 - 4 < 2) {
        _dev_err(*(undefined8 *)(lVar7 + 8),"%s:%d chan_idx=%u ee=%u not in correct state\n",
                 "gsi_enable_flow_control_ee",0x1425,param_1,param_2);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d chan_idx=%u ee=%u not in correct state\n",
                           "gsi_enable_flow_control_ee",0x1425,param_1,param_2);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d chan_idx=%u ee=%u not in correct state\n",
                           "gsi_enable_flow_control_ee",0x1425,param_1,param_2);
          }
        }
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x114ed8);
        (*pcVar3)();
      }
      if (uVar4 == 0) {
        _dev_err(*(undefined8 *)(lVar7 + 8),"%s:%d No response received\n",
                 "gsi_enable_flow_control_ee",0x1429);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d No response received\n",
                           "gsi_enable_flow_control_ee",0x1429);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d No response received\n",
                           "gsi_enable_flow_control_ee",0x1429);
            uVar8 = 0xffffffff;
            goto LAB_00114cb8;
          }
        }
        uVar8 = 0xffffffff;
        goto LAB_00114cb8;
      }
      gsihal_read_reg_nk_fields(8,*(undefined4 *)(lVar7 + 0x14),param_1,&local_68);
      iVar6 = local_68._4_4_;
      if (local_68._4_4_ == 5) {
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d ch %u state updated to %u\n",
                           "gsi_enable_flow_control_ee",0x1433,param_1,5);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d ch %u state updated to %u\n",
                           "gsi_enable_flow_control_ee",0x1433,param_1,5);
            uVar8 = 0;
            goto LAB_00114ca4;
          }
        }
        uVar8 = 0;
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d ch %u state updated to %u incorrect state\n",
                 "gsi_enable_flow_control_ee",0x1437,param_1,local_68._4_4_);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d ch %u state updated to %u incorrect state\n",
                           "gsi_enable_flow_control_ee",0x1437,param_1,iVar6);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d ch %u state updated to %u incorrect state\n",
                           "gsi_enable_flow_control_ee",0x1437,param_1,iVar6);
          }
        }
        uVar8 = 0xffffffff;
      }
LAB_00114ca4:
      uVar4 = *(uint *)(gsi_ctx + 0x6fac) >> 5 & 7;
    }
    *param_3 = uVar4;
  }
LAB_00114cb8:
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar4 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar5 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar5 & (uVar4 ^ 0xffffffff));
  mutex_unlock(gsi_ctx + 0x6f60);
LAB_00114cfc:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// gsi_flow_control_ee @ 00114ff0 size=1952
// signature: undefined gsi_flow_control_ee(void)
// callers: []
//------------------------------------------------------------

undefined8
gsi_flow_control_ee(uint param_1,int param_2,undefined4 param_3,ulong param_4,undefined1 param_5,
                   uint *param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  uVar8 = 3;
  if ((param_4 & 1) == 0) {
    uVar8 = 4;
  }
  local_78 = 0;
  local_70 = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_flow_control_ee",0x1450);
    uVar9 = 0xfffffff8;
  }
  else if ((param_6 == (uint *)0x0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_idx=%d\n","gsi_flow_control_ee",
             0x1455,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_idx=%d\n",
                       "gsi_flow_control_ee",0x1455,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_idx=%d\n",
                       "gsi_flow_control_ee",0x1455,param_1);
      }
    }
    uVar9 = 0xfffffffa;
  }
  else {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI flow control opcode=%d, ch_id=%d\n",
                     "gsi_flow_control_ee",0x1459,uVar8,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI flow control opcode=%d, ch_id=%d\n",
                     "gsi_flow_control_ee",0x1459,uVar8,param_1);
    }
    mutex_lock(gsi_ctx + 0x6f60);
    uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
    uVar5 = gsihal_get_glob_irq_en_gp_int1_mask();
    uVar6 = gsihal_read_reg_nk(4,uVar2,0);
    gsihal_write_reg_nk(4,uVar2,0,uVar6 | uVar5);
    puVar1 = (undefined4 *)(gsi_ctx + 0x14);
    *(undefined4 *)(gsi_ctx + 0x6fc8) = 0;
    uVar5 = gsihal_read_reg_nk(0x24,*puVar1,0);
    puVar1 = (undefined4 *)(gsi_ctx + 0x14);
    *(uint *)(gsi_ctx + 0x6fac) = uVar5 & 0xffffff1f;
    gsihal_write_reg_nk(0x24,*puVar1,0);
    local_78 = CONCAT44(param_1,uVar8);
    local_70 = CONCAT35(local_70._5_3_,CONCAT14(param_5,param_3)) & 0xffffff01ffffffff;
    puVar1 = (undefined4 *)(gsi_ctx + 0x14);
    *(long *)(gsi_ctx + 0x6f58) = *(long *)(gsi_ctx + 0x6f58) + 1;
    gsihal_write_reg_n_fields(0x76,*puVar1,&local_78);
    iVar3 = param_2 * 0x14 + 7;
    uVar5 = gsihal_read_reg_nk(0x8a,iVar3,0);
    iVar7 = wait_for_completion_timeout(gsi_ctx + 0x6fc8,0x271);
    if (iVar7 == 0) {
      uVar6 = 0;
      do {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_idx=%u ee=%u timed out\n",
                 "gsi_flow_control_ee",0x1477,param_1,param_3);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_idx=%u ee=%u timed out\n",
                           "gsi_flow_control_ee",0x1477,param_1,param_3);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_idx=%u ee=%u timed out\n",
                           "gsi_flow_control_ee",0x1477,param_1,param_3);
          }
        }
        if ((((param_4 & 1) == 0) || (4 < uVar6)) || ((uVar5 >> 0x13 & 1) == 0)) {
          uVar9 = *(undefined8 *)(gsi_ctx + 8);
          uVar8 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
          _dev_err(uVar9,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n","gsi_flow_control_ee",
                   0x147f,uVar8);
          if (gsi_ctx != 0) {
            lVar10 = *(long *)(gsi_ctx + 0x6fe8);
            if (lVar10 != 0) {
              uVar8 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
              ipc_log_string(lVar10,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n",
                             "gsi_flow_control_ee",0x147f,uVar8);
            }
            lVar10 = *(long *)(gsi_ctx + 0x6ff0);
            if (lVar10 != 0) {
              uVar8 = gsihal_read_reg_nk(4,*(undefined4 *)(gsi_ctx + 0x14),0);
              ipc_log_string(lVar10,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_EN_OFFS = 0x%x\n",
                             "gsi_flow_control_ee",0x147f,uVar8);
            }
          }
          uVar9 = *(undefined8 *)(gsi_ctx + 8);
          uVar8 = gsihal_read_reg_nk(0xd,*(undefined4 *)(gsi_ctx + 0x14),0);
          _dev_err(uVar9,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n",
                   "gsi_flow_control_ee",0x1481,uVar8);
          if (gsi_ctx != 0) {
            lVar10 = *(long *)(gsi_ctx + 0x6fe8);
            if (lVar10 != 0) {
              uVar8 = gsihal_read_reg_nk(0xd,*(undefined4 *)(gsi_ctx + 0x14),0);
              ipc_log_string(lVar10,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n",
                             "gsi_flow_control_ee",0x1481,uVar8);
            }
            lVar10 = *(long *)(gsi_ctx + 0x6ff0);
            if (lVar10 != 0) {
              uVar8 = gsihal_read_reg_nk(0xd,*(undefined4 *)(gsi_ctx + 0x14),0);
              ipc_log_string(lVar10,"%s:%d GSI_EE_n_CNTXT_GLOB_IRQ_STTS_OFFS IRQ type = 0x%x\n",
                             "gsi_flow_control_ee",0x1481,uVar8);
            }
          }
          break;
        }
        uVar6 = uVar6 + 1;
        uVar5 = gsihal_read_reg_nk(0x8a,iVar3,0);
        iVar7 = wait_for_completion_timeout(gsi_ctx + 0x6fc8,0x271);
      } while (iVar7 == 0);
    }
    uVar5 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
    lVar10 = gsi_ctx;
    *(uint *)(gsi_ctx + 0x6fac) = uVar5;
    if (lVar10 != 0) {
      if (*(long *)(lVar10 + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(lVar10 + 0x6fe8),
                       "%s:%d Flow control command response GENERIC_CMD_RESPONSE_CODE = %u, val = %u\n"
                       ,"gsi_flow_control_ee",0x148a,uVar5 >> 5 & 7);
        lVar10 = gsi_ctx;
      }
      if (*(long *)(lVar10 + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(lVar10 + 0x6ff0),
                       "%s:%d Flow control command response GENERIC_CMD_RESPONSE_CODE = %u, val = %u\n"
                       ,"gsi_flow_control_ee",0x148a,*(uint *)(lVar10 + 0x6fac) >> 5 & 7);
        lVar10 = gsi_ctx;
      }
    }
    uVar5 = *(uint *)(lVar10 + 0x6fac) >> 5 & 7;
    if (uVar5 == 2) {
      if (lVar10 != 0) {
        if (*(long *)(lVar10 + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(lVar10 + 0x6fe8),"%s:%d chan_idx=%u ee=%u not in correct state\n"
                         ,"gsi_flow_control_ee",0x148f,param_1,param_3);
          lVar10 = gsi_ctx;
        }
        if (*(long *)(lVar10 + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(lVar10 + 0x6ff0),"%s:%d chan_idx=%u ee=%u not in correct state\n"
                         ,"gsi_flow_control_ee",0x148f,param_1,param_3);
        }
      }
      uVar9 = 0xfffffffc;
      uVar5 = 2;
    }
    else {
      if (uVar5 == 4) {
        _dev_err(*(undefined8 *)(lVar10 + 8),"%s:%d chan_idx=%u ee=%u not in correct state\n",
                 "gsi_flow_control_ee",0x1496,param_1,param_3);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d chan_idx=%u ee=%u not in correct state\n","gsi_flow_control_ee",
                           0x1496,param_1,param_3);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d chan_idx=%u ee=%u not in correct state\n","gsi_flow_control_ee",
                           0x1496,param_1,param_3);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11552c);
        (*pcVar4)();
      }
      if (uVar5 == 5) {
        _dev_err(*(undefined8 *)(lVar10 + 8),"%s:%d Channel ID = %u ee = %u not allocated\n",
                 "gsi_flow_control_ee",0x149a,param_1,param_3);
        lVar10 = gsi_ctx;
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                           "%s:%d Channel ID = %u ee = %u not allocated\n","gsi_flow_control_ee",
                           0x149a,param_1,param_3);
          }
          lVar10 = gsi_ctx;
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                           "%s:%d Channel ID = %u ee = %u not allocated\n","gsi_flow_control_ee",
                           0x149a,param_1,param_3);
            lVar10 = gsi_ctx;
          }
        }
      }
      uVar5 = *(uint *)(lVar10 + 0x6fac) >> 5 & 7;
      if (uVar5 == 0) {
        _dev_err(*(undefined8 *)(lVar10 + 8),"%s:%d No response received\n","gsi_flow_control_ee",
                 0x149e);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d No response received\n",
                           "gsi_flow_control_ee",0x149e);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d No response received\n",
                           "gsi_flow_control_ee",0x149e);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x115620);
        (*pcVar4)();
      }
      uVar9 = 0;
    }
    *param_6 = uVar5;
    uVar8 = *(undefined4 *)(gsi_ctx + 0x14);
    uVar5 = gsihal_get_glob_irq_en_gp_int1_mask();
    uVar6 = gsihal_read_reg_nk(4,uVar8,0);
    gsihal_write_reg_nk(4,uVar8,0,uVar6 & (uVar5 ^ 0xffffffff));
    mutex_unlock(gsi_ctx + 0x6f60);
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// gsi_query_flow_control_state_ee @ 00115794 size=800
// signature: undefined gsi_query_flow_control_state_ee(void)
// callers: []
//------------------------------------------------------------

int gsi_query_flow_control_state_ee(uint param_1,undefined4 param_2,byte param_3,uint *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  long lVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_68;
  uint local_64;
  undefined4 uStack_60;
  uint local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_5c = 0;
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_query_flow_control_state_ee",0x14b7);
    iVar7 = -8;
    goto LAB_00115940;
  }
  if ((param_4 == (uint *)0x0) || (*(uint *)(gsi_ctx + 0x6fc0) <= param_1)) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_idx=%d\n",
             "gsi_query_flow_control_state_ee",0x14bc,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_idx=%d\n",
                       "gsi_query_flow_control_state_ee",0x14bc,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_idx=%d\n",
                       "gsi_query_flow_control_state_ee",0x14bc,param_1);
        iVar7 = -6;
        goto LAB_00115940;
      }
    }
    iVar7 = -6;
    goto LAB_00115940;
  }
  mutex_lock(gsi_ctx + 0x6f60);
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar5 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar6 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar6 | uVar5);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(undefined4 *)(gsi_ctx + 0x6fc8) = 0;
  uVar5 = gsihal_read_reg_nk(0x24,*puVar1,0);
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  *(uint *)(gsi_ctx + 0x6fac) = uVar5 & 0xffffff1f;
  gsihal_write_reg_nk(0x24,*puVar1,0);
  local_68 = 5;
  puVar1 = (undefined4 *)(gsi_ctx + 0x14);
  local_5c = CONCAT31(local_5c._1_3_,param_3) & 0xffffff01;
  *(long *)(gsi_ctx + 0x6f58) = *(long *)(gsi_ctx + 0x6f58) + 1;
  local_64 = param_1;
  uStack_60 = param_2;
  gsihal_write_reg_n_fields(0x76,*puVar1,&local_68);
  iVar7 = wait_for_completion_timeout(gsi_ctx + 0x6fc8,0x139);
  if (iVar7 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d chan_idx=%u ee=%u timed out\n",
             "gsi_query_flow_control_state_ee",0x14d7,param_1,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_query_flow_control_state_ee",0x14d7,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d chan_idx=%u ee=%u timed out\n",
                       "gsi_query_flow_control_state_ee",0x14d7,param_1,param_2);
        iVar7 = -0xb;
        goto LAB_00115900;
      }
    }
    iVar7 = -0xb;
  }
  else {
    uVar5 = gsihal_read_reg_nk(0x24,*(undefined4 *)(gsi_ctx + 0x14),0);
    *(uint *)(gsi_ctx + 0x6fac) = uVar5;
    *param_4 = uVar5 >> 10 & 7;
    uVar5 = *(uint *)(gsi_ctx + 0x6fac) & 0x1c00;
    if ((param_3 & 1) == 0) {
      bVar4 = uVar5 == 0;
    }
    else {
      bVar4 = uVar5 == 0x400;
    }
    iVar7 = -(uint)!bVar4;
  }
LAB_00115900:
  uVar2 = *(undefined4 *)(gsi_ctx + 0x14);
  uVar5 = gsihal_get_glob_irq_en_gp_int1_mask();
  uVar6 = gsihal_read_reg_nk(4,uVar2,0);
  gsihal_write_reg_nk(4,uVar2,0,uVar6 & (uVar5 ^ 0xffffffff));
  mutex_unlock(gsi_ctx + 0x6f60);
LAB_00115940:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// gsi_map_virtual_ch_to_per_ep @ 00115ab8 size=220
// signature: undefined gsi_map_virtual_ch_to_per_ep(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_map_virtual_ch_to_per_ep(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  if (gsi_ctx == (long *)0x0) {
    _printk(&DAT_00132af7,"gsi_map_virtual_ch_to_per_ep",0x14f7);
    uVar1 = 0xfffffff8;
  }
  else if (*gsi_ctx == 0) {
    _dev_err(gsi_ctx[1],"%s:%d access to GSI HW has not been mapped\n",
             "gsi_map_virtual_ch_to_per_ep",0x14fc);
    if (gsi_ctx != (long *)0x0) {
      if (gsi_ctx[0xdfd] != 0) {
        ipc_log_string(gsi_ctx[0xdfd],"%s:%d access to GSI HW has not been mapped\n",
                       "gsi_map_virtual_ch_to_per_ep",0x14fc);
      }
      if (gsi_ctx[0xdfe] != 0) {
        ipc_log_string(gsi_ctx[0xdfe],"%s:%d access to GSI HW has not been mapped\n",
                       "gsi_map_virtual_ch_to_per_ep",0x14fc);
      }
    }
    uVar1 = 0xfffffffa;
  }
  else {
    gsihal_write_reg_nk(0x77,param_1,param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsi_wdi3_write_evt_ring_db @ 00115b98 size=164
// signature: undefined gsi_wdi3_write_evt_ring_db(void)
// callers: []
//------------------------------------------------------------

void gsi_wdi3_write_evt_ring_db(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_wdi3_write_evt_ring_db",0x150b);
  }
  else {
    if (*(uint *)(gsi_ctx + 0x10) < 8) {
      gsihal_write_reg_nk(0x2c,*(undefined4 *)(gsi_ctx + 0x14),param_1,param_2);
      uVar1 = 0x2d;
    }
    else {
      gsihal_write_reg_nk(0x2a,*(undefined4 *)(gsi_ctx + 0x14),param_1,param_2);
      uVar1 = 0x2b;
    }
    gsihal_write_reg_nk(uVar1,*(undefined4 *)(gsi_ctx + 0x14),param_1,param_3);
  }
  return;
}



//------------------------------------------------------------
// gsi_get_refetch_reg @ 00115c40 size=56
// signature: undefined gsi_get_refetch_reg(void)
// callers: []
//------------------------------------------------------------

void gsi_get_refetch_reg(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x78;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x79;
  }
  gsihal_read_reg_nk(uVar1,*(undefined4 *)(gsi_ctx + 0x14),param_1);
  return;
}



//------------------------------------------------------------
// gsi_ntn3_client_stats_get @ 00115c7c size=328
// signature: undefined gsi_ntn3_client_stats_get(void)
// callers: []
//------------------------------------------------------------

ulong gsi_ntn3_client_stats_get(int param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  switch(param_2) {
  default:
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid scratch id %d\n",
             "gsi_ntn3_client_stats_get",0x156e,param_2);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid scratch id %d\n",
                       "gsi_ntn3_client_stats_get",0x156e,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid scratch id %d\n",
                     "gsi_ntn3_client_stats_get",0x156e,param_2);
    }
    return 0;
  case 4:
    uVar1 = gsihal_read_reg_nk(0x3c,*(undefined4 *)(gsi_ctx + 0x14));
    return (ulong)(uVar1 >> 0x12 & 1);
  case 5:
    uVar2 = 0x3d;
    break;
  case 6:
    uVar2 = 0x3e;
    break;
  case 7:
    uVar2 = 0x3f;
    break;
  case 8:
    uVar2 = 0x40;
    break;
  case 9:
    uVar2 = 0x41;
    break;
  case 0xffffffff:
    param_3 = 0;
    uVar2 = 0x8a;
    uVar1 = param_1 * 0x50 + 0x4cU >> 2;
    goto LAB_00115d2c;
  }
  uVar1 = *(uint *)(gsi_ctx + 0x14);
LAB_00115d2c:
  uVar3 = gsihal_read_reg_nk(uVar2,uVar1,param_3);
  return uVar3;
}



//------------------------------------------------------------
// gsi_get_drop_stats @ 00115dc8 size=296
// signature: undefined gsi_get_drop_stats(void)
// callers: []
//------------------------------------------------------------

ulong gsi_get_drop_stats(int param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (*(uint *)(gsi_ctx + 0x10) < 10) {
    if (param_2 != 5) {
      return 0;
    }
    param_3 = 0;
    iVar1 = param_1 * 0xc + 7;
    uVar3 = 0x8a;
  }
  else {
    if (param_2 == 7) {
      uVar2 = gsihal_read_reg_nk(0x3f,*(undefined4 *)(gsi_ctx + 0x14));
      return (ulong)((uVar2 >> 0x10 & 0x1fff) + (uVar2 & 0x1fff));
    }
    if (param_2 == 6) {
      uVar4 = gsihal_read_reg_nk(0x3e,*(undefined4 *)(gsi_ctx + 0x14));
      return uVar4;
    }
    if (param_2 != 5) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid scratch id %d\n","gsi_get_drop_stats",
               0x159e,param_2);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid scratch id %d\n",
                         "gsi_get_drop_stats",0x159e,param_2);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
          return 0;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid scratch id %d\n",
                       "gsi_get_drop_stats",0x159e,param_2);
      }
      return 0;
    }
    iVar1 = *(int *)(gsi_ctx + 0x14);
    uVar3 = 0x3d;
  }
  uVar2 = gsihal_read_reg_nk(uVar3,iVar1,param_3);
  return (ulong)(uVar2 & 0xffff);
}



//------------------------------------------------------------
// gsi_get_wp @ 00115ef4 size=48
// signature: undefined gsi_get_wp(void)
// callers: []
//------------------------------------------------------------

void gsi_get_wp(undefined8 param_1)

{
  gsihal_read_reg_nk(0x44,*(undefined4 *)(gsi_ctx + 0x14),param_1);
  return;
}



//------------------------------------------------------------
// gsi_wdi3_dump_register @ 00115f28 size=1780
// signature: undefined gsi_wdi3_dump_register(void)
// callers: []
//------------------------------------------------------------

void gsi_wdi3_dump_register(ulong param_1)

{
  undefined4 uVar1;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_wdi3_dump_register",0x15c5);
  }
  else {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d reg dump ch id %ld\n",
                     "gsi_wdi3_dump_register",0x15c8,param_1);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d reg dump ch id %ld\n",
                     "gsi_wdi3_dump_register",0x15c8,param_1);
    }
    uVar1 = gsihal_read_reg_nk(8,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_0 0x%x\n",
                       "gsi_wdi3_dump_register",0x15cb,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_0 0x%x\n",
                       "gsi_wdi3_dump_register",0x15cb,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x34,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_1 0x%x\n",
                       "gsi_wdi3_dump_register",0x15ce,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_1 0x%x\n",
                       "gsi_wdi3_dump_register",0x15ce,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x35,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_2 0x%x\n",
                       "gsi_wdi3_dump_register",0x15d1,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_2 0x%x\n",
                       "gsi_wdi3_dump_register",0x15d1,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x36,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_3 0x%x\n",
                       "gsi_wdi3_dump_register",0x15d4,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_3 0x%x\n",
                       "gsi_wdi3_dump_register",0x15d4,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x42,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_4 0x%x\n",
                       "gsi_wdi3_dump_register",0x15d7,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_4 0x%x\n",
                       "gsi_wdi3_dump_register",0x15d7,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x43,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_5 0x%x\n",
                       "gsi_wdi3_dump_register",0x15da,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_5 0x%x\n",
                       "gsi_wdi3_dump_register",0x15da,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x44,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_6 0x%x\n",
                       "gsi_wdi3_dump_register",0x15dd,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_6 0x%x\n",
                       "gsi_wdi3_dump_register",0x15dd,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x45,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_7 0x%x\n",
                       "gsi_wdi3_dump_register",0x15e0,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_CNTXT_7 0x%x\n",
                       "gsi_wdi3_dump_register",0x15e0,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x78,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d GSI_EE_n_GSI_CH_k_RE_FETCH_READ_PTR 0x%x\n","gsi_wdi3_dump_register",
                       0x15e4,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d GSI_EE_n_GSI_CH_k_RE_FETCH_READ_PTR 0x%x\n","gsi_wdi3_dump_register",
                       0x15e4,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x79,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d GSI_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR 0x%x\n","gsi_wdi3_dump_register",
                       0x15e7,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d GSI_EE_n_GSI_CH_k_RE_FETCH_WRITE_PTR 0x%x\n","gsi_wdi3_dump_register",
                       0x15e7,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x33,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_QOS 0x%x\n",
                       "gsi_wdi3_dump_register",0x15ea,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_QOS 0x%x\n",
                       "gsi_wdi3_dump_register",0x15ea,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x38,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_0 0x%x\n",
                       "gsi_wdi3_dump_register",0x15ed,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_0 0x%x\n",
                       "gsi_wdi3_dump_register",0x15ed,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x39,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_1 0x%x\n",
                       "gsi_wdi3_dump_register",0x15f0,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_1 0x%x\n",
                       "gsi_wdi3_dump_register",0x15f0,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x3a,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_2 0x%x\n",
                       "gsi_wdi3_dump_register",0x15f3,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_2 0x%x\n",
                       "gsi_wdi3_dump_register",0x15f3,uVar1);
      }
    }
    uVar1 = gsihal_read_reg_nk(0x3b,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_3 0x%x\n",
                       "gsi_wdi3_dump_register",0x15f6,uVar1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI_EE_n_GSI_CH_k_SCRATCH_3 0x%x\n",
                       "gsi_wdi3_dump_register",0x15f6,uVar1);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_query_msi_addr @ 00116620 size=448
// signature: undefined gsi_query_msi_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_query_msi_addr(ulong param_1,long *param_2)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_query_msi_addr",0x15fd);
    uVar3 = 0xfffffff8;
  }
  else if (param_1 < *(uint *)(gsi_ctx + 0x6fc0)) {
    if (0x23 < param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1167e0);
      (*pcVar1)();
    }
    if (*(int *)(gsi_ctx + param_1 * 0x1c0 + 0x130) == 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad state %d\n","gsi_query_msi_addr",0x1608,0);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad state %d\n","gsi_query_msi_addr",
                         0x1608,*(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad state %d\n","gsi_query_msi_addr",
                         0x1608,*(undefined4 *)(gsi_ctx + param_1 * 0x1c0 + 0x130));
          return 0xfffffff9;
        }
      }
      uVar3 = 0xfffffff9;
    }
    else {
      lVar4 = *(long *)(gsi_ctx + 0x30);
      uVar2 = gsihal_get_reg_nk_ofst(0x46,*(undefined4 *)(gsi_ctx + 0x14),param_1 & 0xffffffff);
      uVar3 = 0;
      *param_2 = lVar4 + (uVar2 & 0xffffffff);
    }
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params chan_hdl=%lu\n","gsi_query_msi_addr",
             0x1602,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_query_msi_addr",0x1602,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad params chan_hdl=%lu\n",
                       "gsi_query_msi_addr",0x1602,param_1);
        return 0xfffffffa;
      }
    }
    uVar3 = 0xfffffffa;
  }
  return uVar3;
}



//------------------------------------------------------------
// gsi_query_device_msi_addr @ 001167e4 size=192
// signature: undefined gsi_query_device_msi_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_query_device_msi_addr(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (gsi_ctx == 0) {
    _printk(&DAT_00132af7,"gsi_query_device_msi_addr",0x1617);
    uVar1 = 0xfffffff8;
  }
  else {
    if (*(char *)(gsi_ctx + 0x6ffa) == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined8 *)(gsi_ctx + 0x7000);
    }
    *param_1 = uVar1;
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Device MSI Addr: 0x%lx",
                       "gsi_query_device_msi_addr",0x1620);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Device MSI Addr: 0x%lx",
                     "gsi_query_device_msi_addr",0x1620,*param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsi_read_event_ring_wp @ 001168a8 size=84
// signature: undefined gsi_read_event_ring_wp(void)
// callers: []
//------------------------------------------------------------

ulong gsi_read_event_ring_wp(undefined4 param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = gsihal_read_reg_nk(0x49,param_2,param_1);
  lVar2 = gsihal_read_reg_nk(0x4a,param_2 & 0xffffffff,param_1);
  return uVar1 & 0xffffffff | lVar2 << 0x20;
}



//------------------------------------------------------------
// gsi_read_event_ring_bp @ 00116900 size=36
// signature: undefined gsi_read_event_ring_bp(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_read_event_ring_bp(uint param_1)

{
  code *pcVar1;
  
  if (0x1e < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116924);
    (*pcVar1)();
  }
  return *(undefined8 *)(gsi_ctx + (ulong)param_1 * 0x148 + 0x4830);
}



//------------------------------------------------------------
// gsi_get_evt_ring_rp @ 00116928 size=100
// signature: undefined gsi_get_evt_ring_rp(void)
// callers: []
//------------------------------------------------------------

void gsi_get_evt_ring_rp(uint param_1)

{
  long lVar1;
  code *pcVar2;
  
  if (0x1e < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x11698c);
    (*pcVar2)();
  }
  lVar1 = gsi_ctx + (ulong)param_1 * 0x148;
  pcVar2 = *(code **)(lVar1 + 0x4810);
  if (*(int *)(pcVar2 + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x822b,0x116978);
    (*pcVar2)();
  }
  (*pcVar2)(lVar1 + 0x4798,param_1,*(undefined4 *)(gsi_ctx + 0x14));
  return;
}



//------------------------------------------------------------
// gsi_read_chan_ring_rp @ 00116990 size=84
// signature: undefined gsi_read_chan_ring_rp(void)
// callers: []
//------------------------------------------------------------

ulong gsi_read_chan_ring_rp(undefined4 param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = gsihal_read_reg_nk(0x42,param_2,param_1);
  lVar2 = gsihal_read_reg_nk(0x43,param_2 & 0xffffffff,param_1);
  return uVar1 & 0xffffffff | lVar2 << 0x20;
}



//------------------------------------------------------------
// gsi_read_chan_ring_wp @ 001169e8 size=84
// signature: undefined gsi_read_chan_ring_wp(void)
// callers: []
//------------------------------------------------------------

ulong gsi_read_chan_ring_wp(undefined4 param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = gsihal_read_reg_nk(0x44,param_2,param_1);
  lVar2 = gsihal_read_reg_nk(0x45,param_2 & 0xffffffff,param_1);
  return uVar1 & 0xffffffff | lVar2 << 0x20;
}



//------------------------------------------------------------
// gsi_read_chan_ring_bp @ 00116a40 size=36
// signature: undefined gsi_read_chan_ring_bp(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_read_chan_ring_bp(uint param_1)

{
  code *pcVar1;
  
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116a64);
    (*pcVar1)();
  }
  return *(undefined8 *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0x148);
}



//------------------------------------------------------------
// gsi_read_chan_ring_re_fetch_wp @ 00116a68 size=40
// signature: undefined gsi_read_chan_ring_re_fetch_wp(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_read_chan_ring_re_fetch_wp(undefined4 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  uVar1 = gsihal_read_reg_nk(0x79,param_2,param_1);
  return uVar1;
}



//------------------------------------------------------------
// gsi_get_chan_prot_type @ 00116a94 size=36
// signature: undefined gsi_get_chan_prot_type(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_chan_prot_type(uint param_1)

{
  code *pcVar1;
  
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116ab8);
    (*pcVar1)();
  }
  return *(undefined4 *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0xb8);
}



//------------------------------------------------------------
// gsi_get_chan_state @ 00116abc size=36
// signature: undefined gsi_get_chan_state(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_chan_state(uint param_1)

{
  code *pcVar1;
  
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116ae0);
    (*pcVar1)();
  }
  return *(undefined4 *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0x130);
}



//------------------------------------------------------------
// gsi_get_chan_poll_mode @ 00116ae4 size=36
// signature: undefined gsi_get_chan_poll_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_chan_poll_mode(uint param_1)

{
  code *pcVar1;
  
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116b08);
    (*pcVar1)();
  }
  return *(undefined4 *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0x1e4);
}



//------------------------------------------------------------
// gsi_get_ring_len @ 00116b0c size=36
// signature: undefined gsi_get_ring_len(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_ring_len(uint param_1)

{
  code *pcVar1;
  
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116b30);
    (*pcVar1)();
  }
  return *(undefined4 *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0x170);
}



//------------------------------------------------------------
// gsi_get_chan_props_db_in_bytes @ 00116b34 size=36
// signature: undefined gsi_get_chan_props_db_in_bytes(void)
// callers: []
//------------------------------------------------------------

undefined1 gsi_get_chan_props_db_in_bytes(uint param_1)

{
  code *pcVar1;
  
  if (0x23 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116b58);
    (*pcVar1)();
  }
  return *(undefined1 *)(gsi_ctx + (ulong)param_1 * 0x1c0 + 0xe8);
}



//------------------------------------------------------------
// gsi_get_peripheral_ee @ 00116b5c size=16
// signature: undefined gsi_get_peripheral_ee(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_peripheral_ee(void)

{
  return *(undefined4 *)(gsi_ctx + 0x14);
}



//------------------------------------------------------------
// gsi_get_chan_stop_stm @ 00116b70 size=44
// signature: undefined gsi_get_chan_stop_stm(void)
// callers: []
//------------------------------------------------------------

uint gsi_get_chan_stop_stm(undefined4 param_1,undefined8 param_2)

{
  uint extraout_var;
  
  gsihal_read_reg_nk(0x3c,param_2,param_1);
  return extraout_var & 0xf0;
}



//------------------------------------------------------------
// gsi_get_evt_ring_re_size @ 00116ba0 size=40
// signature: undefined gsi_get_evt_ring_re_size(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_evt_ring_re_size(uint param_1)

{
  code *pcVar1;
  
  if (0x1e < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116bc8);
    (*pcVar1)();
  }
  return *(undefined4 *)(gsi_ctx + (ulong)param_1 * 0x148 + 0x47a0);
}



//------------------------------------------------------------
// gsi_get_evt_ring_len @ 00116bcc size=40
// signature: undefined gsi_get_evt_ring_len(void)
// callers: []
//------------------------------------------------------------

undefined4 gsi_get_evt_ring_len(uint param_1)

{
  code *pcVar1;
  
  if (0x1e < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x116bf4);
    (*pcVar1)();
  }
  return *(undefined4 *)(gsi_ctx + (ulong)param_1 * 0x148 + 0x4858);
}



//------------------------------------------------------------
// gsi_update_almst_empty_thrshold @ 00116bf8 size=56
// signature: undefined gsi_update_almst_empty_thrshold(void)
// callers: []
//------------------------------------------------------------

void gsi_update_almst_empty_thrshold(undefined8 param_1,undefined2 param_2)

{
  gsihal_write_reg_nk(0x93,*(undefined4 *)(gsi_ctx + 0x14),param_1,param_2);
  return;
}



//------------------------------------------------------------
// gsi_get_hw_profiling_stats @ 00116c34 size=340
// signature: undefined gsi_get_hw_profiling_stats(void)
// callers: [gsi_read_gsi_hw_profiling_stats]
//------------------------------------------------------------

undefined8 gsi_get_hw_profiling_stats(ulong *param_1)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 == (ulong *)0x0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad parms NULL stats == NULL\n",
             "gsi_get_hw_profiling_stats",0x16dc);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad parms NULL stats == NULL\n",
                       "gsi_get_hw_profiling_stats",0x16dc);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad parms NULL stats == NULL\n",
                       "gsi_get_hw_profiling_stats",0x16dc);
      }
    }
    uVar3 = 0xffffffea;
  }
  else {
    uVar1 = gsihal_read_reg_nk(0x8b,0,0);
    lVar2 = gsihal_read_reg_nk(0x8c,0,0);
    *param_1 = uVar1 & 0xffffffff | lVar2 << 0x20;
    uVar1 = gsihal_read_reg_nk(0x8d,0,0);
    lVar2 = gsihal_read_reg_nk(0x8e,0,0);
    param_1[1] = uVar1 & 0xffffffff | lVar2 << 0x20;
    uVar1 = gsihal_read_reg_nk(0x8f,0,0);
    lVar2 = gsihal_read_reg_nk(0x90,0,0);
    param_1[2] = uVar1 & 0xffffffff | lVar2 << 0x20;
    uVar1 = gsihal_read_reg_nk(0x91,0,0);
    lVar2 = gsihal_read_reg_nk(0x92,0,0);
    uVar3 = 0;
    param_1[3] = uVar1 & 0xffffffff | lVar2 << 0x20;
  }
  return uVar3;
}



//------------------------------------------------------------
// gsi_get_fw_version @ 00116d8c size=216
// signature: undefined gsi_get_fw_version(void)
// callers: [gsi_read_gsi_fw_version]
//------------------------------------------------------------

undefined8 gsi_get_fw_version(uint *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_1 == (uint *)0x0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad parms: ver == NULL\n","gsi_get_fw_version",
             0x1700);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad parms: ver == NULL\n",
                       "gsi_get_fw_version",0x1700);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d bad parms: ver == NULL\n",
                       "gsi_get_fw_version",0x1700);
      }
    }
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = gsihal_read_reg_nk(0x7a,(ulong)(9 < *(uint *)(gsi_ctx + 0x10)) << 6,0);
    uVar2 = 0;
    *param_1 = uVar1 >> 10 & 0x3f;
    param_1[1] = uVar1 >> 7 & 7;
    param_1[2] = uVar1 & 0x7f;
  }
  return uVar2;
}



//------------------------------------------------------------
// trace_raw_output_gsi_qtimer @ 00116e68 size=136
// signature: undefined trace_raw_output_gsi_qtimer(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_gsi_qtimer(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    pcVar1 = "false";
    if (*(char *)(lVar3 + 0x10) != '\0') {
      pcVar1 = "true";
    }
    trace_event_printf(param_1,"qtimer=%llu is_ll=%s, evt=%u, ch=0x%x, msk=0x%x\n",
                       *(undefined8 *)(lVar3 + 8),pcVar1,*(undefined1 *)(lVar3 + 0x11),
                       *(undefined4 *)(lVar3 + 0x14),*(undefined4 *)(lVar3 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// __gsi_msi_write_msg @ 00116ef4 size=380
// signature: undefined __gsi_msi_write_msg(void)
// callers: []
//------------------------------------------------------------

void __gsi_msi_write_msg(ulong param_1,undefined8 *param_2)

{
  ushort uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  
  if (((((param_1 == 0) || (0xfffffffffffff000 < param_1)) || (param_2 == (undefined8 *)0x0)) ||
      (((undefined8 *)0xfffffffffffff000 < param_2 || (gsi_ctx == 0)))) ||
     (0xfffffffffffff000 < gsi_ctx)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x11706c);
    (*pcVar2)();
  }
  uVar1 = *(ushort *)(param_1 + 0x48);
  if ((*(uint *)(gsi_ctx + 0x7008) <= (uint)uVar1) ||
     ((*(ulong *)(gsi_ctx + ((ulong)(uVar1 >> 3) & 0x1ff8) + 0x7010) >> ((ulong)uVar1 & 0x3f) & 1)
      != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x117070);
    (*pcVar2)();
  }
  uVar7 = (uint)uVar1;
  if (2 < uVar7) {
LAB_00117064:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x117068);
    (*pcVar2)();
  }
  uVar6 = *param_2;
  lVar5 = gsi_ctx + (ulong)uVar7 * 0xc;
  uVar3 = *(undefined8 *)(gsi_ctx + 8);
  *(undefined4 *)(lVar5 + 0x7028) = *(undefined4 *)(param_2 + 1);
  *(undefined8 *)(lVar5 + 0x7020) = uVar6;
  _dev_notice(uVar3,"saved msi %u msg data %u addr 0x%08x%08x\n",uVar7,*(undefined4 *)(param_2 + 1),
              *(undefined4 *)((long)param_2 + 4),*(undefined4 *)param_2);
  uVar4 = gsi_ctx;
  uVar8 = (uint)uVar1;
  if (*(char *)(gsi_ctx + 0x6ffa) == '\0') {
    if (1 < uVar7) goto LAB_00117064;
    lVar5 = gsi_ctx + (ulong)uVar8 * 0xc;
    *(char *)(gsi_ctx + 0x6ffa) = '\x01';
    *(undefined8 *)(uVar4 + 0x7000) = *(undefined8 *)(lVar5 + 0x7020);
  }
  if (uVar4 != 0) {
    if (*(long *)(uVar4 + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(uVar4 + 0x6fe8),
                     "%s:%d saved msi %u msg data %u addr 0x%08x%08x, MSI:0x%lx\n",
                     "__gsi_msi_write_msg",0x559,uVar8,*(undefined4 *)(param_2 + 1),
                     *(undefined4 *)((long)param_2 + 4),*(undefined4 *)param_2,
                     *(undefined8 *)(uVar4 + 0x7000));
      uVar4 = gsi_ctx;
    }
    if (*(long *)(uVar4 + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(uVar4 + 0x6ff0),
                     "%s:%d saved msi %u msg data %u addr 0x%08x%08x, MSI:0x%lx\n",
                     "__gsi_msi_write_msg",0x559,uVar8,*(undefined4 *)(param_2 + 1),
                     *(undefined4 *)((long)param_2 + 4),*(undefined4 *)param_2,
                     *(undefined8 *)(uVar4 + 0x7000));
    }
  }
  return;
}



//------------------------------------------------------------
// gsi_msi_isr @ 00117074 size=716
// signature: undefined gsi_msi_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 gsi_msi_isr(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  ulong *puVar3;
  undefined4 uVar4;
  byte bVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_80 = 0;
  uVar4 = *(undefined4 *)(gsi_ctx + 0x14);
  local_78 = 0;
  uStack_70 = 0;
  if ((*(int *)(gsi_ctx + 0x7008) == 0) || (*(int *)(gsi_ctx + 0x7038) == param_1)) {
    lVar12 = 0;
  }
  else {
    if ((*(int *)(gsi_ctx + 0x7008) != 1) && (*(int *)(gsi_ctx + 0x703c) != param_1))
    goto LAB_00117338;
    lVar12 = 1;
  }
  bVar5 = *(byte *)(gsi_ctx + lVar12 * 4 + 0x7040);
  if (bVar5 < 0x20) {
    lVar12 = gsi_ctx + (ulong)bVar5 * 0x148;
    piVar1 = (int *)(lVar12 + 0x4798);
    if (*piVar1 != 2) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Unexpected irq intf %d\n","gsi_msi_isr",0x47e);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Unexpected irq intf %d\n","gsi_msi_isr",
                         0x47e,*piVar1);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Unexpected irq intf %d\n","gsi_msi_isr",
                         0x47e,*piVar1);
        }
      }
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x117338);
      (*pcVar6)();
    }
    lVar14 = gsi_ctx + (ulong)bVar5 * 0x148;
    puVar2 = (undefined1 *)(lVar14 + 0x481c);
    uVar7 = gsihal_get_ch_reg_idx(*puVar2);
    uVar8 = gsihal_get_ch_reg_mask(*puVar2);
    gsihal_write_reg_nk(0x85,uVar4,uVar7,uVar8);
    uVar9 = _raw_spin_lock_irqsave();
    puVar3 = (ulong *)(lVar14 + 0x4850);
    do {
      if (*(int *)(*(code **)(lVar12 + 0x4810) + -4) != -0x5258ab4e) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1171f0);
        (*pcVar6)();
      }
      uVar10 = (**(code **)(lVar12 + 0x4810))(piVar1,*puVar2,uVar4);
      uVar10 = uVar10 | (ulong)*(uint *)(lVar14 + 0x4844) << 0x20;
      *(ulong *)(lVar14 + 0x4840) = uVar10;
      if ((*puVar3 == uVar10) ||
         ((*(char *)(lVar12 + 0x47f0) != '\0' && (*(int *)(*(long *)(lVar14 + 0x48b8) + 300) != 0)))
         ) break;
      gsi_process_evt_re(piVar1,&local_80,1);
      lVar13 = 1;
      uVar11 = *puVar3;
      while (uVar11 != uVar10) {
        if ((*(char *)(lVar12 + 0x47f0) != '\0') &&
           (*(int *)(*(long *)(lVar14 + 0x48b8) + 300) != 0)) {
          lVar13 = 0;
          break;
        }
        gsi_process_evt_re(piVar1,&local_80,1);
        lVar13 = lVar13 + 1;
        uVar11 = *puVar3;
      }
      *(undefined8 *)(lVar14 + 0x4838) = *(undefined8 *)(lVar14 + 0x4848);
      gsihal_write_reg_nk(0x11,*(undefined4 *)(gsi_ctx + 0x14),*puVar2);
    } while (lVar13 != 0);
    _raw_spin_unlock_irqrestore(lVar14 + 0x4820,uVar9);
    lVar12 = sp_el0;
    if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return 1;
  }
LAB_00117338:
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x11733c);
  (*pcVar6)();
}



//------------------------------------------------------------
// readl_relaxed @ 00117404 size=124
// signature: undefined readl_relaxed(void)
// callers: [gsi_read_event_ring_rp_ddr]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x11744c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// msm_gsi_probe @ 00117484 size=916
// signature: undefined msm_gsi_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gsi_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = param_1 + 0x10;
  gsi_ctx = devm_kmalloc(lVar1,0x7258,0xdc0);
  if (gsi_ctx == 0) {
    _dev_err(lVar1,"failed to allocated gsi context\n");
    uVar4 = 0xfffffff4;
  }
  else {
    lVar3 = ipc_log_context_create(0x32,&DAT_0011deeb,0x10000);
    lVar5 = gsi_ctx;
    *(long *)(gsi_ctx + 0x6fe8) = lVar3;
    if ((lVar3 == 0) &&
       (_dev_err(*(undefined8 *)(lVar5 + 8),"%s:%d failed to create IPC log, continue...\n",
                 "msm_gsi_probe",0x1737), lVar5 = gsi_ctx, gsi_ctx != 0)) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d failed to create IPC log, continue...\n",
                       "msm_gsi_probe",0x1737);
      }
      lVar5 = gsi_ctx;
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d failed to create IPC log, continue...\n",
                       "msm_gsi_probe",0x1737);
        lVar5 = gsi_ctx;
      }
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,num-msi",lVar5 + 0x7008,1,0);
    if (iVar2 < 0) {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d No MSIs configured\n","msm_gsi_probe",0x173c);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d No MSIs configured\n","msm_gsi_probe",
                         0x173c);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d No MSIs configured\n","msm_gsi_probe",
                         0x173c);
        }
      }
    }
    else if (*(uint *)(gsi_ctx + 0x7008) < 3) {
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Num MSIs=%u\n","msm_gsi_probe",0x1743);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Num MSIs=%u\n","msm_gsi_probe",0x1743,
                         *(undefined4 *)(gsi_ctx + 0x7008));
        }
      }
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Num MSIs %u larger than max %u, normalizing\n",
               "msm_gsi_probe",0x1741,*(uint *)(gsi_ctx + 0x7008),2);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d Num MSIs %u larger than max %u, normalizing\n","msm_gsi_probe",
                         0x1741,*(undefined4 *)(gsi_ctx + 0x7008),2);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                         "%s:%d Num MSIs %u larger than max %u, normalizing\n","msm_gsi_probe",
                         0x1741,*(undefined4 *)(gsi_ctx + 0x7008),2);
        }
      }
      *(undefined4 *)(gsi_ctx + 0x7008) = 2;
    }
    lVar3 = gsi_ctx;
    lVar5 = gsi_ctx + 0x6fd0;
    *(long *)(gsi_ctx + 8) = lVar1;
    *(undefined4 *)(lVar3 + 0x6fc8) = 0;
    __init_swait_queue_head(lVar5,"&x->wait",&init_completion___key);
    gsi_debugfs_init();
    iVar2 = qcom_va_md_register("gsi_mini",&qcom_va_md_gsi_notif_blk);
    if (iVar2 == 0) {
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d gsi mini qcom_va_md_register success\n",
                         "msm_gsi_probe",0x1750);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
          return 0;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d gsi mini qcom_va_md_register success\n",
                       "msm_gsi_probe",0x1750);
      }
    }
    else {
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d gsi mini qcom_va_md_register failed = %d\n",
               "msm_gsi_probe",0x174e,iVar2);
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                         "%s:%d gsi mini qcom_va_md_register failed = %d\n","msm_gsi_probe",0x174e,
                         iVar2);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
          return 0;
        }
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d gsi mini qcom_va_md_register failed = %d\n","msm_gsi_probe",0x174e,
                       iVar2);
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// qcom_va_md_gsi_notif_handler @ 0011781c size=128
// signature: undefined qcom_va_md_gsi_notif_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_va_md_gsi_notif_handler(void)

{
  long lVar1;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0x696e696d5f697367;
  uStack_40 = 0;
  local_28 = 0x7258;
  local_50 = gsi_ctx;
  qcom_va_md_add_region(&local_50);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// gsi_debugfs_init @ 001178dc size=896
// signature: undefined gsi_debugfs_init(void)
// callers: [msm_gsi_probe]
//------------------------------------------------------------

void gsi_debugfs_init(void)

{
  undefined *puVar1;
  undefined8 uVar2;
  
  dent = debugfs_create_dir(&DAT_00131fdc,0);
  if (dent < 0xfffffffffffff001) {
    gsi_debugfs_init_dfile = debugfs_create_file("ev_dump",0x90,dent,0,&gsi_ev_dump_ops);
    if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
      puVar1 = &DAT_00132c53;
      uVar2 = 0x30f;
    }
    else {
      gsi_debugfs_init_dfile = debugfs_create_file("ch_dump",0x90,dent,0,gsi_ch_dump_ops);
      if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
        puVar1 = &DAT_001344d1;
        uVar2 = 0x316;
      }
      else {
        gsi_debugfs_init_dfile =
             debugfs_create_file("ch_scrach_dump",0x90,dent,0,gsi_ch_dump_scratch_ops);
        if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
          puVar1 = &DAT_001346c7;
          uVar2 = 0x31d;
        }
        else {
          gsi_debugfs_init_dfile = debugfs_create_file("stats",0x90,dent,0,gsi_stats_ops);
          if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
            puVar1 = &DAT_00130f79;
            uVar2 = 0x324;
          }
          else {
            gsi_debugfs_init_dfile =
                 debugfs_create_file("enable_dp_stats",0x90,dent,0,gsi_enable_dp_stats_ops);
            if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
              puVar1 = &DAT_00130f79;
              uVar2 = 0x32b;
            }
            else {
              gsi_debugfs_init_dfile =
                   debugfs_create_file("max_elem_dp_stats",0x90,dent,0,gsi_max_elem_dp_stats_ops);
              if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
                puVar1 = &DAT_00130f79;
                uVar2 = 0x332;
              }
              else {
                gsi_debugfs_init_dfile =
                     debugfs_create_file("rst_stats",0x90,dent,0,gsi_rst_stats_ops);
                if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile))
                {
                  puVar1 = &DAT_00130f79;
                  uVar2 = 0x339;
                }
                else {
                  gsi_debugfs_init_dfile =
                       debugfs_create_file("print_dp_stats",0x90,dent,0,gsi_print_dp_stats_ops);
                  if ((gsi_debugfs_init_dfile == 0) || (0xfffffffffffff000 < gsi_debugfs_init_dfile)
                     ) {
                    puVar1 = &DAT_00130f79;
                    uVar2 = 0x340;
                  }
                  else {
                    gsi_debugfs_init_dfile =
                         debugfs_create_file("ipc_low",0x90,dent,0,gsi_ipc_low_ops);
                    if ((gsi_debugfs_init_dfile == 0) ||
                       (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
                      puVar1 = &DAT_0013186f;
                      uVar2 = 0x347;
                    }
                    else {
                      gsi_debugfs_init_dfile =
                           debugfs_create_file("gsi_hw_profiling_stats",0x120,dent,0,
                                               gsi_hw_profiling_ops);
                      if ((gsi_debugfs_init_dfile == 0) ||
                         (0xfffffffffffff000 < gsi_debugfs_init_dfile)) {
                        puVar1 = &DAT_00131df2;
                        uVar2 = 0x34e;
                      }
                      else {
                        gsi_debugfs_init_dfile =
                             debugfs_create_file("gsi_fw_version",0x120,dent,0,gsi_ver_ops);
                        if ((gsi_debugfs_init_dfile != 0) &&
                           (gsi_debugfs_init_dfile < 0xfffffffffffff001)) {
                          return;
                        }
                        puVar1 = &DAT_00131fe0;
                        uVar2 = 0x355;
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
    _printk(puVar1,"gsi_debugfs_init",uVar2);
    debugfs_remove(dent);
  }
  else {
    _printk(&DAT_00133192,"gsi_debugfs_init",0x308);
  }
  return;
}



//------------------------------------------------------------
// gsi_dump_evt @ 00117c60 size=1584
// signature: undefined gsi_dump_evt(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_dump_evt(undefined8 param_1,ulong param_2,ulong param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  long lVar10;
  ulong uVar11;
  char *local_58;
  int local_50;
  uint local_4c;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  local_4c = 0;
  local_50 = 0;
  if (param_3 < 0x1000) {
    __check_object_size(&dbg_buff,param_3,0);
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_2, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar11 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar7 = param_3;
    if (uVar11 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar7 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      uVar7 = __arch_copy_from_user(puVar9,&dbg_buff,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
    }
    if (uVar7 != 0) {
      memset(&dbg_buff + (param_3 - uVar7),0,uVar7);
      param_3 = 0xfffffffffffffff2;
      goto LAB_00117de8;
    }
    if (0xfff < param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x118274);
      (*pcVar4)();
    }
    (&dbg_buff)[param_3] = 0;
    local_58 = &dbg_buff;
    pcVar8 = strsep(&local_58," ");
    if ((((pcVar8 != (char *)0x0) && (iVar5 = kstrtouint(pcVar8,0,&local_4c), iVar5 == 0)) &&
        (pcVar8 = strsep(&local_58," "), pcVar8 != (char *)0x0)) &&
       (iVar5 = kstrtouint(pcVar8,0,&local_50), iVar5 == 0)) {
      if (local_4c < *(uint *)(gsi_ctx + 0x6fc4)) {
        if (*(int *)(*(code **)(gsi_ctx + 0x98) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x117e54);
          (*pcVar4)();
        }
        (**(code **)(gsi_ctx + 0x98))();
        uVar6 = gsihal_read_reg_nk(0xc,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00134dc7,"gsi_dump_evt",0x78,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x25,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00132724,"gsi_dump_evt",0x7b,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x26,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00130fac,"gsi_dump_evt",0x7e,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x27,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_001344f6,"gsi_dump_evt",0x81,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x47,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00135152,"gsi_dump_evt",0x84,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x48,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00133832,"gsi_dump_evt",0x87,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x49,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00132009,"gsi_dump_evt",0x8a,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x4a,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00130fc6,"gsi_dump_evt",0x8d,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x28,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_001355db,"gsi_dump_evt",0x90,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x29,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00133f0d,"gsi_dump_evt",0x93,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x2a,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00133c9f,"gsi_dump_evt",0x96,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x2b,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00132364,"gsi_dump_evt",0x99,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x2c,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_0013516c,"gsi_dump_evt",0x9c,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x2d,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_001329cc,"gsi_dump_evt",0x9f,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x30,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_0013384c,"gsi_dump_evt",0xa2,local_4c,uVar6);
        uVar6 = gsihal_read_reg_nk(0x31,*(undefined4 *)(gsi_ctx + 0x14),local_4c);
        _printk(&DAT_00134fb9,"gsi_dump_evt",0xa5,local_4c,uVar6);
        if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118180);
          (*pcVar4)();
        }
        (**(code **)(gsi_ctx + 0xa0))();
        if (local_50 != 0) {
          if (0x1f < local_4c) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x118278);
            (*pcVar4)();
          }
          lVar10 = gsi_ctx + (ulong)local_4c * 0x148;
          if (*(long *)(lVar10 + 0x47b0) == 0) {
            _printk(&DAT_00133a43,"gsi_dump_evt",0xb9);
          }
          else if (0xf < *(uint *)(lVar10 + 0x47a4)) {
            uVar11 = 0;
            do {
              puVar1 = (undefined4 *)(*(long *)(lVar10 + 0x47b0) + uVar11 * 0x10);
              _printk(&DAT_00134de1,"gsi_dump_evt",0xb7,local_4c,
                      *(long *)(lVar10 + 0x47a8) + uVar11 * 0x10,*puVar1,puVar1[1],puVar1[2],
                      puVar1[3]);
              uVar2 = (int)uVar11 + 1U & 0xffff;
              uVar11 = (ulong)uVar2;
            } while (uVar2 < *(uint *)(lVar10 + 0x47a4) >> 4);
          }
        }
        goto LAB_00117de8;
      }
      _printk(&DAT_001346f3,"gsi_dump_evt",0x70);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_00117de8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_dump_ch @ 001182ac size=816
// signature: undefined gsi_dump_ch(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_dump_ch(undefined8 param_1,ulong param_2,ulong param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  char *pcVar7;
  undefined8 *puVar8;
  long lVar9;
  ulong uVar10;
  char *local_58;
  int local_50;
  uint local_4c;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  local_4c = 0;
  local_50 = 0;
  if (param_3 < 0x1000) {
    __check_object_size(&dbg_buff,param_3,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar6 = param_3;
    if (uVar10 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar6 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      uVar6 = __arch_copy_from_user(puVar8,&dbg_buff,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
    }
    if (uVar6 != 0) {
      memset(&dbg_buff + (param_3 - uVar6),0,uVar6);
      param_3 = 0xfffffffffffffff2;
      goto LAB_00118410;
    }
    if (0xfff < param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x1185c0);
      (*pcVar4)();
    }
    (&dbg_buff)[param_3] = 0;
    local_58 = &dbg_buff;
    pcVar7 = strsep(&local_58," ");
    if ((((pcVar7 != (char *)0x0) && (iVar5 = kstrtouint(pcVar7,0,&local_4c), iVar5 == 0)) &&
        (pcVar7 = strsep(&local_58," "), pcVar7 != (char *)0x0)) &&
       (iVar5 = kstrtouint(pcVar7,0,&local_50), iVar5 == 0)) {
      if (local_4c < *(uint *)(gsi_ctx + 0x6fc0)) {
        if (*(int *)(*(code **)(gsi_ctx + 0x98) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1184a0);
          (*pcVar4)();
        }
        (**(code **)(gsi_ctx + 0x98))();
        gsi_dump_ch_info(local_4c);
        if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1184cc);
          (*pcVar4)();
        }
        (**(code **)(gsi_ctx + 0xa0))();
        if (local_50 != 0) {
          if (0x24 < local_4c) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1185c4);
            (*pcVar4)();
          }
          lVar9 = gsi_ctx + (ulong)local_4c * 0x1c0;
          if (*(long *)(lVar9 + 0xf0) == 0) {
            _printk(&DAT_00134713,"gsi_dump_ch",0xfc);
          }
          else if (0xf < *(uint *)(lVar9 + 0xd4)) {
            uVar10 = 0;
            do {
              puVar1 = (undefined4 *)(*(long *)(lVar9 + 0xf0) + uVar10 * 0x10);
              _printk(&DAT_0013273e,"gsi_dump_ch",0xfa,local_4c,
                      *(long *)(lVar9 + 0xe0) + uVar10 * 0x10,*puVar1,puVar1[1],puVar1[2],puVar1[3])
              ;
              uVar2 = (int)uVar10 + 1U & 0xffff;
              uVar10 = (ulong)uVar2;
            } while (uVar2 < *(uint *)(lVar9 + 0xd4) >> 4);
          }
        }
        goto LAB_00118410;
      }
      _printk(&DAT_00131e32,"gsi_dump_ch",0xe4);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_00118410:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_dump_ch_scratch_info @ 001185f8 size=608
// signature: undefined gsi_dump_ch_scratch_info(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_dump_ch_scratch_info(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  char *local_48;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if (param_3 < 0x1000) {
    __check_object_size(&dbg_buff,param_3,0);
    puVar10 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar11 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar5 = param_3;
    if (uVar11 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar10 = (undefined8 *)puVar10[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      uVar5 = __arch_copy_from_user(puVar10,&dbg_buff,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
    }
    if (uVar5 != 0) {
      memset(&dbg_buff + (param_3 - uVar5),0,uVar5);
      param_3 = 0xfffffffffffffff2;
      goto LAB_00118754;
    }
    if (0xfff < param_3) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x118840);
      (*pcVar3)();
    }
    (&dbg_buff)[param_3] = 0;
    local_48 = &dbg_buff;
    pcVar6 = strsep(&local_48," ");
    if ((pcVar6 != (char *)0x0) && (iVar4 = kstrtouint(pcVar6,0,&local_3c), iVar4 == 0)) {
      if (gsi_ctx == 0) {
        _printk(&DAT_001355f5,"gsi_dump_ch_scratch_info",0x3a,"gsi_dump_ch_scratch_info",0x3a);
        param_3 = 0xffffffffffffffea;
      }
      else {
        if (local_3c < *(uint *)(gsi_ctx + 0x6fc0)) {
          if (9 < *(uint *)(gsi_ctx + 0x10)) {
            gsi_dump_ch_scratch(local_3c);
            goto LAB_00118754;
          }
          puVar7 = &DAT_001313e9;
          uVar8 = 0x43;
          uVar9 = *(uint *)(gsi_ctx + 0x10);
        }
        else {
          puVar7 = &DAT_00131e32;
          uVar8 = 0x3f;
          uVar9 = local_3c;
        }
        _printk(puVar7,"gsi_dump_ch_scratch_info",uVar8,uVar9);
        param_3 = 0xffffffffffffffea;
      }
      goto LAB_00118754;
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_00118754:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_dump_stats @ 00118874 size=312
// signature: undefined gsi_dump_stats(void)
// callers: []
//------------------------------------------------------------

long gsi_dump_stats(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar3 = kstrtoint_from_user(param_2,param_3,0,&local_3c);
  if (iVar3 != 0) {
    param_3 = (long)iVar3;
    goto LAB_00118954;
  }
  uVar4 = (ulong)local_3c;
  if (local_3c == 0xffffffff) {
    local_3c = 0;
    iVar3 = *(int *)(gsi_ctx + 0x6fc0);
    if (iVar3 < 1) goto LAB_00118954;
    uVar4 = 0;
LAB_00118928:
    do {
      if (0x24 < (uint)uVar4) goto LAB_001189a4;
      gsi_dump_ch_stats(gsi_ctx + uVar4 * 0x1c0 + 0xb8);
      local_3c = local_3c + 1;
      uVar4 = (ulong)local_3c;
    } while ((int)local_3c < iVar3);
  }
  else {
    if ((-1 < (int)local_3c) && (local_3c < *(uint *)(gsi_ctx + 0x6fc0))) {
      if (0x23 < local_3c) {
LAB_001189a4:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1189a8);
        (*pcVar2)();
      }
      if (*(char *)(gsi_ctx + (ulong)local_3c * 0x1c0 + 0x1e0) != '\0') {
        iVar3 = local_3c + 1;
        goto LAB_00118928;
      }
    }
    _printk(&DAT_001331bf,"gsi_dump_stats",0x13a);
    param_3 = -0x16;
  }
LAB_00118954:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_dump_ch_stats @ 001189ac size=248
// signature: undefined gsi_dump_ch_stats(void)
// callers: [gsi_dump_stats, gsi_wq_print_dp_stats]
//------------------------------------------------------------

void gsi_dump_ch_stats(long param_1)

{
  if (*(char *)(param_1 + 0x128) != '\0') {
    _printk(&DAT_0013276c,*(undefined1 *)(param_1 + 8));
    _printk(&DAT_00131b16,*(undefined8 *)(param_1 + 0x148),*(undefined8 *)(param_1 + 0x150));
    _printk(&DAT_001353e7,*(undefined8 *)(param_1 + 0x158),*(undefined8 *)(param_1 + 0x160),
            *(undefined8 *)(param_1 + 0x168));
    _printk(&DAT_00134b9b,*(undefined8 *)(param_1 + 0x170));
    _printk(&DAT_001333c9,*(undefined8 *)(param_1 + 0x178),*(undefined8 *)(param_1 + 0x180));
    if (*(long *)(param_1 + 0xd0) != 0) {
      _printk(&DAT_001333e7,*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x140));
    }
    _printk(&DAT_00130fe0,*(undefined8 *)(param_1 + 0x188));
    _printk(&DAT_00132ca1,*(undefined8 *)(param_1 + 400));
    _printk(&DAT_00133f27,*(undefined8 *)(param_1 + 0x198));
    _printk(&DAT_001333f8,*(undefined8 *)(param_1 + 0x1a0));
    _printk(&DAT_00132023,*(undefined8 *)(param_1 + 0x1a8));
    _printk(&DAT_00135186);
  }
  return;
}



//------------------------------------------------------------
// gsi_enable_dp_stats @ 00118aa8 size=824
// signature: undefined gsi_enable_dp_stats(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_enable_dp_stats(undefined8 param_1,ulong param_2,ulong param_3)

{
  int *piVar1;
  ulong uVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long lVar9;
  ulong uVar10;
  uint local_3c;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_3c = 0;
  if (param_3 < 0x1000) {
    __check_object_size(&dbg_buff,param_3,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar7 = param_3;
    if (uVar10 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar7 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      uVar7 = __arch_copy_from_user(puVar8,&dbg_buff,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
    }
    if (uVar7 != 0) {
      memset(&dbg_buff + (param_3 - uVar7),0,uVar7);
      goto LAB_00118d70;
    }
    if (0xfff < param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x118dc4);
      (*pcVar4)();
    }
    (&dbg_buff)[param_3] = 0;
    cVar3 = dbg_buff;
    if ((dbg_buff != '-') && (dbg_buff != '+')) goto LAB_00118d70;
    bVar5 = dbg_buff == '+';
    iVar6 = kstrtoint(&DAT_0012fdc1,0,&local_3c);
    if (iVar6 != 0) goto LAB_00118d70;
    if (((int)local_3c < 0) || (*(uint *)(gsi_ctx + 0x6fc0) <= local_3c)) goto LAB_00118d70;
    if (0x23 < local_3c) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x118dc8);
      (*pcVar4)();
    }
    if (*(char *)(gsi_ctx + (ulong)local_3c * 0x1c0 + 0x1e0) == '\0') goto LAB_00118d70;
    lVar9 = gsi_ctx + (ulong)local_3c * 0x1c0;
    if ((bool)*(char *)(lVar9 + 0x270) != bVar5) {
      *(bool *)(lVar9 + 0x270) = bVar5;
      piVar1 = (int *)(gsi_ctx + 0x6fb4);
      iVar6 = *piVar1;
      if (cVar3 == '+') {
        *piVar1 = iVar6 + 1;
        if (iVar6 == 0) {
          lVar9 = alloc_workqueue(&DAT_00132274,0xe000a,1,"gsi_stat");
          *(long *)(gsi_ctx + 0x6fb8) = lVar9;
          if (lVar9 == 0) {
            _printk(&DAT_001335f5,"gsi_dbg_create_stats_wq",0x143);
            param_3 = 0xfffffffffffffff4;
            goto LAB_00118d8c;
          }
        }
        cancel_delayed_work_sync(&gsi_update_dp_stats_work);
        queue_delayed_work_on(0x20,*(undefined8 *)(gsi_ctx + 0x6fb8),&gsi_update_dp_stats_work,3);
      }
      else {
        *piVar1 = iVar6 + -1;
        if (iVar6 + -1 == 0) {
          cancel_delayed_work_sync(&gsi_update_dp_stats_work);
          cancel_delayed_work_sync(gsi_print_dp_stats_work);
          __flush_workqueue(*(undefined8 *)(gsi_ctx + 0x6fb8));
          destroy_workqueue(*(undefined8 *)(gsi_ctx + 0x6fb8));
          *(undefined8 *)(gsi_ctx + 0x6fb8) = 0;
        }
      }
      goto LAB_00118d8c;
    }
    _printk(&DAT_001329e6,"gsi_enable_dp_stats",0x170);
  }
  else {
LAB_00118d70:
    _printk(&DAT_00134995,"gsi_enable_dp_stats",0x189);
  }
  param_3 = 0xffffffffffffffea;
LAB_00118d8c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_wq_update_dp_stats @ 00118dfc size=420
// signature: undefined gsi_wq_update_dp_stats(void)
// callers: []
//------------------------------------------------------------

void gsi_wq_update_dp_stats(void)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  undefined1 *puVar12;
  ulong uVar13;
  long lVar14;
  
  lVar11 = gsi_ctx;
  if (*(int *)(gsi_ctx + 0x6fc0) != 0) {
    uVar13 = 0;
    lVar14 = 0x270;
    do {
      if (uVar13 == 0x24) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x118fa0);
        (*pcVar4)();
      }
      if ((*(char *)(lVar11 + lVar14 + -0x90) != '\0') && (*(char *)(lVar11 + lVar14) != '\0')) {
        uVar2 = *(undefined4 *)(lVar11 + 0x14);
        if (*(int *)(*(code **)(lVar11 + 0x98) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118eb0);
          (*pcVar4)();
        }
        (**(code **)(lVar11 + 0x98))();
        lVar1 = lVar11 + lVar14;
        puVar12 = (undefined1 *)(lVar1 + -0x1b0);
        uVar7 = gsihal_read_reg_nk(0x42,uVar2,*puVar12);
        lVar8 = gsihal_read_reg_nk(0x43,uVar2,*puVar12);
        uVar9 = gsihal_read_reg_nk(0x44,uVar2,*puVar12);
        lVar10 = gsihal_read_reg_nk(0x45,uVar2,*puVar12);
        if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118f2c);
          (*pcVar4)();
        }
        (**(code **)(gsi_ctx + 0xa0))();
        uVar5 = gsi_find_idx_from_addr(lVar1 + -0x138,uVar7 & 0xffffffff | lVar8 << 0x20);
        uVar6 = gsi_find_idx_from_addr(lVar1 + -0x138,uVar9 & 0xffffffff | lVar10 << 0x20);
        if ((uVar6 & 0xffff) < (uVar5 & 0xffff)) {
          iVar3 = (uVar6 - uVar5) + (uint)*(ushort *)(lVar1 + -0xfa) + 1;
        }
        else {
          iVar3 = uVar6 - uVar5;
        }
        gsi_update_ch_dp_stats(lVar11 + lVar14 + -0x1b8,iVar3);
        lVar11 = gsi_ctx;
      }
      uVar13 = uVar13 + 1;
      lVar14 = lVar14 + 0x1c0;
    } while (uVar13 < *(uint *)(lVar11 + 0x6fc0));
  }
  queue_delayed_work_on(0x20,*(undefined8 *)(lVar11 + 0x6fb8),&gsi_update_dp_stats_work,3);
  return;
}



//------------------------------------------------------------
// gsi_wq_print_dp_stats @ 00118fa4 size=160
// signature: undefined gsi_wq_print_dp_stats(void)
// callers: []
//------------------------------------------------------------

void gsi_wq_print_dp_stats(void)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar2 = gsi_ctx;
  if (*(int *)(gsi_ctx + 0x6fc0) != 0) {
    uVar3 = 0;
    lVar4 = 0x271;
    do {
      if (uVar3 == 0x24) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x119044);
        (*pcVar1)();
      }
      if (*(char *)(lVar2 + lVar4) != '\0') {
        gsi_dump_ch_stats(lVar2 + lVar4 + -0x1b9);
        lVar2 = gsi_ctx;
      }
      uVar3 = uVar3 + 1;
      lVar4 = lVar4 + 0x1c0;
    } while (uVar3 < *(uint *)(lVar2 + 0x6fc0));
  }
  queue_delayed_work_on(0x20,*(undefined8 *)(lVar2 + 0x6fb8),gsi_print_dp_stats_work,0xfa);
  return;
}



//------------------------------------------------------------
// gsi_set_max_elem_dp_stats @ 00119048 size=796
// signature: undefined gsi_set_max_elem_dp_stats(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_set_max_elem_dp_stats(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 *puVar7;
  ulong uVar8;
  char *local_48;
  undefined4 local_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_40 = 0;
  local_48 = (char *)0x0;
  if (param_3 < 0x1000) {
    __check_object_size(&dbg_buff,param_3,0);
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar8 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar5 = param_3;
    if (uVar8 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      uVar5 = __arch_copy_from_user(puVar7,&dbg_buff,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
    }
    if (uVar5 == 0) {
      if (0xfff < param_3) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x119348);
        (*pcVar3)();
      }
      (&dbg_buff)[param_3] = 0;
      local_48 = &dbg_buff;
      pcVar6 = strsep(&local_48," ");
      if (pcVar6 == (char *)0x0) {
        _printk(&DAT_00133a70,"gsi_set_max_elem_dp_stats",0x1a2);
      }
      else {
        iVar4 = kstrtouint(pcVar6,0,&local_3c);
        if (iVar4 == 0) {
          pcVar6 = strsep(&local_48," ");
          if (pcVar6 == (char *)0x0) {
            iVar4 = kstrtouint(&dbg_buff,0,&local_3c);
            if (iVar4 == 0) {
              if (local_3c < *(uint *)(gsi_ctx + 0x6fc0)) {
                if (0x23 < local_3c) goto LAB_00119348;
                _printk(&DAT_001311e9,local_3c,
                        *(undefined2 *)(gsi_ctx + (ulong)local_3c * 0x1c0 + 0xd8));
                goto LAB_001192fc;
              }
            }
          }
          else {
            iVar4 = kstrtouint(pcVar6,0,&local_40);
            if (iVar4 == 0) {
              if (local_3c < *(uint *)(gsi_ctx + 0x6fc0)) {
                if (0x23 < local_3c) {
LAB_00119348:
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11934c);
                  (*pcVar3)();
                }
                *(short *)(gsi_ctx + (ulong)local_3c * 0x1c0 + 0xd8) = (short)local_40;
                goto LAB_001192fc;
              }
              _printk(&DAT_00131e32,"gsi_set_max_elem_dp_stats",0x1be);
            }
            else {
              _printk(&DAT_00133a70,"gsi_set_max_elem_dp_stats",0x1b7);
            }
          }
        }
        else {
          _printk(&DAT_00133a70,"gsi_set_max_elem_dp_stats",0x1a7);
        }
      }
    }
    else {
      memset(&dbg_buff + (param_3 - uVar5),0,uVar5);
    }
  }
  _printk(&DAT_00132a0f,"gsi_set_max_elem_dp_stats",0x1c7);
  _printk(&DAT_0013237e,"gsi_set_max_elem_dp_stats",0x1c8);
  param_3 = 0xffffffffffffffea;
LAB_001192fc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_rst_stats @ 00119380 size=356
// signature: undefined gsi_rst_stats(void)
// callers: []
//------------------------------------------------------------

long gsi_rst_stats(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  uint local_2c;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_2c = 0;
  iVar3 = kstrtoint_from_user(param_2,param_3,0,&local_2c);
  if (iVar3 != 0) {
    param_3 = (long)iVar3;
    goto LAB_00119488;
  }
  if (local_2c == 0xffffffff) {
    iVar3 = *(int *)(gsi_ctx + 0x6fc0);
    if (iVar3 < 1) goto LAB_00119488;
    uVar4 = 0;
LAB_00119428:
    lVar5 = (ulong)uVar4 * 0x1c0 + -0x3f00;
    iVar3 = iVar3 - uVar4;
    do {
      if (lVar5 == 0) {
        local_2c = 0x24;
        goto LAB_001194dc;
      }
      iVar3 = iVar3 + -1;
      lVar1 = gsi_ctx + lVar5;
      lVar5 = lVar5 + 0x1c0;
      *(undefined8 *)(lVar1 + 0x4168) = 0;
      *(undefined8 *)(lVar1 + 0x4160) = 0;
      *(undefined8 *)(lVar1 + 0x4158) = 0;
      *(undefined8 *)(lVar1 + 0x4150) = 0;
      *(undefined8 *)(lVar1 + 0x4148) = 0;
      *(undefined8 *)(lVar1 + 0x4140) = 0;
      *(undefined8 *)(lVar1 + 0x4138) = 0;
      *(undefined8 *)(lVar1 + 0x4130) = 0;
      *(undefined8 *)(lVar1 + 0x4128) = 0;
      *(undefined8 *)(lVar1 + 0x4120) = 0;
      *(undefined8 *)(lVar1 + 0x4118) = 0;
      *(undefined8 *)(lVar1 + 0x4110) = 0;
      *(undefined8 *)(lVar1 + 0x4108) = 0;
      *(undefined8 *)(lVar1 + 0x4100) = 0;
    } while (iVar3 != 0);
  }
  else {
    if ((-1 < (int)local_2c) && (local_2c < *(uint *)(gsi_ctx + 0x6fc0))) {
      if (0x23 < local_2c) {
LAB_001194dc:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1194e0);
        (*pcVar2)();
      }
      if (*(char *)(gsi_ctx + (ulong)local_2c * 0x1c0 + 0x1e0) != '\0') {
        iVar3 = local_2c + 1;
        uVar4 = local_2c;
        goto LAB_00119428;
      }
    }
    _printk(&DAT_00133cb9,"gsi_rst_stats",0x226);
    param_3 = -0x16;
  }
LAB_00119488:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_print_dp_stats @ 001194e8 size=824
// signature: undefined gsi_print_dp_stats(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gsi_print_dp_stats(undefined8 param_1,ulong param_2,ulong param_3)

{
  int *piVar1;
  ulong uVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long lVar9;
  ulong uVar10;
  uint local_3c;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_3c = 0;
  if (param_3 < 0x1000) {
    __check_object_size(&dbg_buff,param_3,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar7 = param_3;
    if (uVar10 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar7 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      uVar7 = __arch_copy_from_user(puVar8,&dbg_buff,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
    }
    if (uVar7 != 0) {
      memset(&dbg_buff + (param_3 - uVar7),0,uVar7);
      goto LAB_001197b0;
    }
    if (0xfff < param_3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x119804);
      (*pcVar4)();
    }
    (&dbg_buff)[param_3] = 0;
    cVar3 = dbg_buff;
    if ((dbg_buff != '-') && (dbg_buff != '+')) goto LAB_001197b0;
    bVar5 = dbg_buff == '+';
    iVar6 = kstrtoint(&DAT_0012fdc1,0,&local_3c);
    if (iVar6 != 0) goto LAB_001197b0;
    if (((int)local_3c < 0) || (*(uint *)(gsi_ctx + 0x6fc0) <= local_3c)) goto LAB_001197b0;
    if (0x23 < local_3c) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x119808);
      (*pcVar4)();
    }
    if (*(char *)(gsi_ctx + (ulong)local_3c * 0x1c0 + 0x1e0) == '\0') goto LAB_001197b0;
    lVar9 = gsi_ctx + (ulong)local_3c * 0x1c0;
    if ((bool)*(char *)(lVar9 + 0x271) != bVar5) {
      *(bool *)(lVar9 + 0x271) = bVar5;
      piVar1 = (int *)(gsi_ctx + 0x6fb4);
      iVar6 = *piVar1;
      if (cVar3 == '+') {
        *piVar1 = iVar6 + 1;
        if (iVar6 == 0) {
          lVar9 = alloc_workqueue(&DAT_00132274,0xe000a,1,"gsi_stat");
          *(long *)(gsi_ctx + 0x6fb8) = lVar9;
          if (lVar9 == 0) {
            _printk(&DAT_001335f5,"gsi_dbg_create_stats_wq",0x143);
            param_3 = 0xfffffffffffffff4;
            goto LAB_001197cc;
          }
        }
        cancel_delayed_work_sync(gsi_print_dp_stats_work);
        queue_delayed_work_on(0x20,*(undefined8 *)(gsi_ctx + 0x6fb8),gsi_print_dp_stats_work,3);
      }
      else {
        *piVar1 = iVar6 + -1;
        if (iVar6 + -1 == 0) {
          cancel_delayed_work_sync(&gsi_update_dp_stats_work);
          cancel_delayed_work_sync(gsi_print_dp_stats_work);
          __flush_workqueue(*(undefined8 *)(gsi_ctx + 0x6fb8));
          destroy_workqueue(*(undefined8 *)(gsi_ctx + 0x6fb8));
          *(undefined8 *)(gsi_ctx + 0x6fb8) = 0;
        }
      }
      goto LAB_001197cc;
    }
    _printk(&DAT_001329e6,"gsi_print_dp_stats",0x247);
  }
  else {
LAB_001197b0:
    _printk(&DAT_0013561e,"gsi_print_dp_stats",0x260);
  }
  param_3 = 0xffffffffffffffea;
LAB_001197cc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsi_enable_ipc_low @ 0011983c size=256
// signature: undefined gsi_enable_ipc_low(void)
// callers: []
//------------------------------------------------------------

long gsi_enable_ipc_low(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  char local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_3c[0] = '\0';
  iVar2 = kstrtos8_from_user(param_2,param_3,0,local_3c);
  if (iVar2 == 0) {
    mutex_lock(gsi_ctx + 0x6f60);
    if (local_3c[0] == '\0') {
      lVar3 = 0;
    }
    else {
      lVar3 = gsi_ipc_logbuf_low;
      if (gsi_ipc_logbuf_low == 0) {
        gsi_ipc_logbuf_low = ipc_log_context_create(0x32,"gsi_low",0x10000);
        lVar3 = gsi_ipc_logbuf_low;
        if (gsi_ipc_logbuf_low == 0) {
          _printk(&DAT_001349c6,"gsi_enable_ipc_low",0x275);
          lVar3 = gsi_ipc_logbuf_low;
        }
      }
    }
    lVar1 = gsi_ctx + 0x6f60;
    *(long *)(gsi_ctx + 0x6ff0) = lVar3;
    mutex_unlock(lVar1);
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
// gsi_read_gsi_hw_profiling_stats @ 00119940 size=368
// signature: undefined gsi_read_gsi_hw_profiling_stats(void)
// callers: []
//------------------------------------------------------------

void gsi_read_gsi_hw_profiling_stats
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  if (*(uint *)(gsi_ctx + 0x10) < 8) {
    pcVar4 = "This feature only support on GSI2.9+\n";
  }
  else {
    if (*(int *)(*(code **)(gsi_ctx + 0x98) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1199c0);
      (*pcVar2)();
    }
    (**(code **)(gsi_ctx + 0x98))();
    iVar3 = gsi_get_hw_profiling_stats(&local_68);
    if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1199f0);
      (*pcVar2)();
    }
    (**(code **)(gsi_ctx + 0xa0))();
    if (iVar3 == 0) {
      iVar3 = scnprintf(&dbg_buff,0x1000,
                        "bp_count=0x%llx\nbp_and_pending_count=0x%llx\nmcs_busy=0x%llx\nmcs_idle=0x%llx\ntotal_cycle_count=0x%llx\nutilization_percentage=%llu%%\n"
                        ,local_68);
      goto LAB_00119a10;
    }
    pcVar4 = "Fail to read GSI HW Profiling stats\n";
  }
  iVar3 = scnprintf(&dbg_buff,0x1000,pcVar4);
LAB_00119a10:
  simple_read_from_buffer(param_2,param_3,param_4,&dbg_buff,(long)iVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsi_read_gsi_fw_version @ 00119ab4 size=324
// signature: undefined gsi_read_gsi_fw_version(void)
// callers: []
//------------------------------------------------------------

void gsi_read_gsi_fw_version
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  local_58 = 0;
  if (*(uint *)(gsi_ctx + 0x10) < 8) {
    pcVar4 = "This feature only support on GSI2.9+\n";
  }
  else {
    if (*(int *)(*(code **)(gsi_ctx + 0x98) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x119b34);
      (*pcVar2)();
    }
    (**(code **)(gsi_ctx + 0x98))();
    iVar3 = gsi_get_fw_version(&local_58);
    if (*(int *)(*(code **)(gsi_ctx + 0xa0) + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x119b64);
      (*pcVar2)();
    }
    (**(code **)(gsi_ctx + 0xa0))();
    if (iVar3 == 0) {
      iVar3 = scnprintf(&dbg_buff,0x1000,"hw=%d\nflavor=%d\nfw=%d\n",local_58 & 0xffffffff,
                        local_58._4_4_,local_50);
      goto LAB_00119b84;
    }
    pcVar4 = "Fail to read GSI FW version\n";
  }
  iVar3 = scnprintf(&dbg_buff,0x1000,pcVar4);
LAB_00119b84:
  simple_read_from_buffer(param_2,param_3,param_4,&dbg_buff,(long)iVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gsihal_init @ 00119cec size=940
// signature: undefined gsihal_init(void)
// callers: [gsi_map_base]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gsihal_init(int param_1,long param_2)

{
  code *pcVar1;
  int *piVar2;
  undefined8 uVar3;
  
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                     "%s:%d initializing GSI HAL, GSI ver %d, base = %pK\n","gsihal_init",0x11,
                     param_1,param_2);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d initializing GSI HAL, GSI ver %d, base = %pK\n","gsihal_init",0x11,
                     param_1,param_2);
    }
  }
  if (gsihal_ctx != (int *)0x0) {
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d gsihal already initialized\n",
                       "gsihal_init",0x14);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d gsihal already initialized\n",
                       "gsihal_init",0x14);
      }
    }
    if (*(long *)((long)gsihal_ctx + 8) == param_2) {
      return 0xffffffef;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d base address of early init is differnet.\n",
             "gsihal_init",0x18);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d base address of early init is differnet.\n","gsihal_init",0x18);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                       "%s:%d base address of early init is differnet.\n","gsihal_init",0x18);
      }
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x119ea0);
    (*pcVar1)();
  }
  if (param_1 - 0xeU < 0xfffffff3) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid GSI version %d\n","gsihal_init",0x20,
             param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid GSI version %d\n","gsihal_init",
                       0x20,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid GSI version %d\n","gsihal_init",
                       0x20,param_1);
        return 0xffffffea;
      }
    }
  }
  else {
    if (param_2 != 0) {
      piVar2 = (int *)kmalloc_trace(_DAT_00138288,0xdc0,0x10);
      gsihal_ctx = piVar2;
      if (piVar2 != (int *)0x0) {
        *piVar2 = param_1;
        *(long *)(piVar2 + 2) = param_2;
        uVar3 = gsihal_reg_init(param_1);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d failed to initialize gsihal regs\n",
                 "gsihal_init",0x36);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d failed to initialize gsihal regs\n",
                           "gsihal_init",0x36);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d failed to initialize gsihal regs\n",
                           "gsihal_init",0x36);
          }
        }
        kfree(gsihal_ctx);
        gsihal_ctx = (int *)0x0;
        return 0xffffffea;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d kzalloc err for gsihal_ctx\n","gsihal_init",0x2d)
      ;
      if (gsi_ctx != 0) {
        if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d kzalloc err for gsihal_ctx\n",
                         "gsihal_init",0x2d);
        }
        if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
          ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d kzalloc err for gsihal_ctx\n",
                         "gsihal_init",0x2d);
          return 0xfffffff4;
        }
      }
      return 0xfffffff4;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid memory io mapping addr\n","gsihal_init",
             0x26);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid memory io mapping addr\n",
                       "gsihal_init",0x26);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid memory io mapping addr\n",
                       "gsihal_init",0x26);
        return 0xffffffea;
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gsihal_destroy @ 0011a0a0 size=128
// signature: undefined gsihal_destroy(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

void gsihal_destroy(void)

{
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Entry\n","gsihal_destroy",0x45);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Entry\n","gsihal_destroy",0x45);
    }
  }
  kfree(gsihal_ctx);
  gsihal_ctx = 0;
  return;
}



//------------------------------------------------------------
// gsihal_reg_name_str @ 0011a124 size=192
// signature: undefined gsihal_reg_name_str(void)
// callers: []
//------------------------------------------------------------

char * gsihal_reg_name_str(uint param_1)

{
  char *pcVar1;
  
  if (param_1 < 0x96) {
    pcVar1 = (&gsireg_name_to_str)[param_1];
  }
  else {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d requested name of invalid reg=%d\n",
             "gsihal_reg_name_str",0xba,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                       "gsihal_reg_name_str",0xba,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                       "gsihal_reg_name_str",0xba,param_1);
      }
    }
    pcVar1 = "Invalid Register";
  }
  return pcVar1;
}



//------------------------------------------------------------
// gsihal_read_reg_nk @ 0011a1e8 size=728
// signature: undefined gsihal_read_reg_nk(void)
// callers: [gsi_dump_ch_info, gsihal_read_ch_reg, gsi_read_event_ring_rp_reg, gsi_pending_irq_type, gsi_read_channel_scratch, gsi_read_chan_ring_wp, gsi_update_mhi_channel_scratch, gsi_flow_control_ee, gsi_get_wp, gsi_wdi3_dump_register, gsi_get_refetch_reg, __gsi_config_all_ieob_irq, __gsi_config_all_ch_irq, __gsi_config_all_evt_irq, gsi_get_drop_stats, gsi_dump_ch_scratch, gsi_enable_flow_control_ee, gsi_handle_irq, gsi_config_channel_mode, gsi_ntn3_client_stats_get, __gsi_config_ch_irq, gsi_dump_evt, gsi_halt_channel_ee, gsi_queue_xfer, __gsi_config_glob_irq, gsi_read_chan_ring_rp, gsi_read_wdi3_channel_scratch2_reg, gsi_wq_update_dp_stats, gsi_stop_channel, __gsi_config_ieob_irq, gsi_get_hw_profiling_stats, gsi_query_channel_info, gsi_get_chan_stop_stm, gsi_query_flow_control_state_ee, __gsi_config_ieob_irq_k, gsi_is_channel_empty, gsi_dump_halt_debug_reg, gsi_channel_state_change_wait, gsi_get_fw_version, gsi_deregister_device, gsi_read_event_ring_wp, __gsi_config_evt_irq, gsi_alloc_channel_ee, __gsi_config_type_irq, gsi_start_channel, gsi_read_chan_ring_re_fetch_wp]
//------------------------------------------------------------

undefined8 gsihal_read_reg_nk(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined *puVar7;
  
  if (gsihal_ctx == (uint *)0x0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d gsihal_ctx mpt initialized","gsihal_read_reg_nk",
             0x7d8);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d gsihal_ctx mpt initialized",
                       "gsihal_read_reg_nk",0x7d8);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d gsihal_ctx mpt initialized",
                       "gsihal_read_reg_nk",0x7d8);
        return 0xffffffff;
      }
    }
    return 0xffffffff;
  }
  uVar6 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n","gsihal_read_reg_nk",
             0x7dd,uVar6);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_nk",0x7dd,uVar6);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_nk",0x7dd,uVar6);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11a41c);
    (*pcVar4)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011a4c0;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d read %s k=%u n=%u\n","gsihal_read_reg_nk",
                   0x7e3,(&gsireg_name_to_str)[uVar6],param_3,param_2);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11a4c8);
    (*pcVar4)();
  }
  if ((uVar6 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    iVar2 = *(int *)((ulong)uVar1 * 0x12c0 + uVar6 * 0x20 + 0x11f660);
    if (iVar2 == -1) {
      if (param_1 < 0x96) {
        puVar7 = (&gsireg_name_to_str)[uVar6];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Read access to obsolete reg=%s\n",
                 "gsihal_read_reg_nk",0x7e7,puVar7);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_nk",0x7e7,puVar7);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_nk",0x7e7,puVar7);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11a4b4);
        (*pcVar4)();
      }
    }
    else if (((uVar6 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x18) < 0x10681) &&
            ((uVar6 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x14) < 0x10681)) {
      lVar3 = uVar6 * 0x20 + (ulong)uVar1 * 0x12c0;
      uVar5 = readl_relaxed(*(long *)(gsihal_ctx + 2) +
                            (ulong)(uint)(iVar2 + *(int *)(&gsihal_reg_objs + lVar3 + 0x18) *
                                                  param_3 +
                                         *(int *)(&gsihal_reg_objs + lVar3 + 0x14) * param_2));
      return uVar5;
    }
  }
LAB_0011a4c0:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x11a4c4);
  (*pcVar4)();
}



//------------------------------------------------------------
// readl_relaxed @ 0011a4c8 size=124
// signature: undefined readl_relaxed(void)
// callers: [gsihal_read_reg_n_fields, gsihal_read_reg_fields, gsihal_read_reg_nk_fields, gsihal_read_reg_nk]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x11a510,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// gsihal_write_reg_nk @ 0011a548 size=604
// signature: undefined gsihal_write_reg_nk(void)
// callers: [gsi_write_wdi3_channel_scratch2_reg, gsi_ring_evt_doorbell_polling_mode, gsi_register_device, gsihal_write_ch_bit_map_reg_n, gsi_update_mhi_channel_scratch, gsi_configure_regs, gsi_poll_n_channel, gsi_flow_control_ee, gsi_write_channel_scratch3_reg, gsi_write_evt_ring_scratch, gsi_alloc_evt_ring, gsi_write_channel_scratch, __gsi_config_all_ieob_irq, gsihal_write_set_ch_bit_map_reg_n, __gsi_config_all_ch_irq, __gsi_config_all_evt_irq, gsi_enable_flow_control_ee, gsi_handle_irq, gsi_write_channel_scratch2_reg, gsi_config_channel_mode, __gsi_config_ch_irq, gsi_write_device_scratch, gsi_prime_evt_ring, gsi_start_xfer, gsi_update_almst_empty_thrshold, gsi_halt_channel_ee, gsi_reset_evt_ring, gsi_queue_xfer, __gsi_config_glob_irq, gsi_set_channel_cfg, gsi_ring_evt_ring_db, gsi_stop_channel, __gsi_config_ieob_irq, gsi_enable_fw, gsi_query_flow_control_state_ee, gsi_wdi3_write_evt_ring_db, gsi_ring_ch_ring_db, gsi_reset_channel, __gsi_config_ieob_irq_k, gsi_channel_state_change_wait, gsi_deregister_device, gsi_map_virtual_ch_to_per_ep, gsi_program_chan_ctx, gsi_msi_isr, __gsi_config_evt_irq, gsi_alloc_channel_ee, __gsi_config_type_irq, gsi_start_channel]
//------------------------------------------------------------

void gsihal_write_reg_nk(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  undefined *puVar6;
  
  uVar5 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n","gsihal_write_reg_nk",
             0x7f9,uVar5);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_nk",0x7f9,uVar5);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_nk",0x7f9,uVar5);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11a70c);
    (*pcVar4)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011a7a4;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d write to %s k=%u n=%u val=%u\n",
                   "gsihal_write_reg_nk",0x7ff,(&gsireg_name_to_str)[uVar5],param_3,param_2,param_4)
    ;
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11a7ac);
    (*pcVar4)();
  }
  if ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    iVar2 = *(int *)((ulong)uVar1 * 0x12c0 + uVar5 * 0x20 + 0x11f660);
    if (iVar2 == -1) {
      if (param_1 < 0x96) {
        puVar6 = (&gsireg_name_to_str)[uVar5];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Write access to obsolete reg=%s\n",
                 "gsihal_write_reg_nk",0x803,puVar6);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_nk",0x803,puVar6);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_nk",0x803,puVar6);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11a7a0);
        (*pcVar4)();
      }
    }
    else if (((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x18) < 0x10681) &&
            ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x14) < 0x10681)) {
      lVar3 = uVar5 * 0x20 + (ulong)uVar1 * 0x12c0;
      DataMemoryBarrier(0,2);
      writel_relaxed(param_4,*(long *)(gsihal_ctx + 2) +
                             (ulong)(uint)(iVar2 + *(int *)(&gsihal_reg_objs + lVar3 + 0x18) *
                                                   param_3 +
                                          *(int *)(&gsihal_reg_objs + lVar3 + 0x14) * param_2));
      return;
    }
  }
LAB_0011a7a4:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x11a7a8);
  (*pcVar4)();
}



//------------------------------------------------------------
// writel_relaxed @ 0011a7ac size=132
// signature: undefined writel_relaxed(void)
// callers: [gsihal_write_reg_nk, gsihal_write_reg_n_fields, gsihal_write_reg_nk_fields, gsihal_write_reg_fields]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x11a7c4,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x11a800,uVar1);
  return;
}



//------------------------------------------------------------
// gsihal_write_reg_fields @ 0011a834 size=768
// signature: undefined gsihal_write_reg_fields(void)
// callers: [gsi_enable_fw]
//------------------------------------------------------------

void gsihal_write_reg_fields(uint param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  undefined *puVar6;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  if (param_2 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Input error fields=%pK\n","gsihal_write_reg_fields"
             ,0x817,0);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Input error fields=%pK\n",
                       "gsihal_write_reg_fields",0x817,0);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Input error fields=%pK\n",
                       "gsihal_write_reg_fields",0x817,0);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11aa20);
    (*pcVar4)();
  }
  uVar5 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n",
             "gsihal_write_reg_fields",0x81d,uVar5);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_fields",0x81d,uVar5);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_fields",0x81d,uVar5);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11aa9c);
    (*pcVar4)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011ab34;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d write to %s after constructing it\n",
                   "gsihal_write_reg_fields",0x823,(&gsireg_name_to_str)[uVar5]);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11ab40);
    (*pcVar4)();
  }
  if ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    uVar2 = *(uint *)((ulong)uVar1 * 0x12c0 + uVar5 * 0x20 + 0x11f660);
    if (uVar2 == 0xffffffff) {
      if (param_1 < 0x96) {
        puVar6 = (&gsireg_name_to_str)[uVar5];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Write access to obsolete reg=%s\n",
                 "gsihal_write_reg_fields",0x827,puVar6);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_fields",0x827,puVar6);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_fields",0x827,puVar6);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11ab30);
        (*pcVar4)();
      }
    }
    else if (uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 < 0x10679) {
      if (*(int *)(*(code **)(&gsihal_reg_objs + uVar5 * 0x20 + (ulong)uVar1 * 0x12c0) + -4) !=
          -0x5ce0dc77) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11a954);
        (*pcVar4)();
      }
      (**(code **)(&gsihal_reg_objs + uVar5 * 0x20 + (ulong)uVar1 * 0x12c0))
                (uVar5,param_2,&local_4c);
      DataMemoryBarrier(0,2);
      writel_relaxed(local_4c,*(long *)(gsihal_ctx + 2) + (ulong)uVar2);
      lVar3 = sp_el0;
      if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
LAB_0011ab34:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x11ab38);
  (*pcVar4)();
}



//------------------------------------------------------------
// gsihal_read_reg_fields @ 0011ab44 size=744
// signature: undefined gsihal_read_reg_fields(void)
// callers: []
//------------------------------------------------------------

undefined4 gsihal_read_reg_fields(uint param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  ulong uVar4;
  undefined *puVar5;
  
  if (param_2 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Input error fields\n","gsihal_read_reg_fields",
             0x839);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Input error fields\n",
                       "gsihal_read_reg_fields",0x839);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Input error fields\n",
                       "gsihal_read_reg_fields",0x839);
      }
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x11ad14);
    (*pcVar3)();
  }
  uVar4 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n","gsihal_read_reg_fields"
             ,0x83f,uVar4);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_fields",0x83f,uVar4);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_fields",0x83f,uVar4);
      }
    }
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x11ad94);
    (*pcVar3)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011ae30;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d read from %s and parse it\n",
                   "gsihal_read_reg_fields",0x845,(&gsireg_name_to_str)[uVar4]);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
LAB_0011ae34:
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11ae38);
    (*pcVar3)();
  }
  if ((uVar4 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    uVar1 = *(uint *)((ulong)uVar1 * 0x12c0 + uVar4 * 0x20 + 0x11f660);
    if (uVar1 == 0xffffffff) {
      if (param_1 < 0x96) {
        puVar5 = (&gsireg_name_to_str)[uVar4];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Read access to obsolete reg=%s\n",
                 "gsihal_read_reg_fields",0x849,puVar5);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_fields",0x849,puVar5);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_fields",0x849,puVar5);
          }
        }
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x11ae2c);
        (*pcVar3)();
      }
    }
    else {
      uVar2 = readl_relaxed(*(long *)(gsihal_ctx + 2) + (ulong)uVar1);
      uVar1 = *gsihal_ctx;
      if (0xd < uVar1) goto LAB_0011ae34;
      if ((uVar4 * 0x20 + (ulong)uVar1 * 0x12c0 | 8) < 0x10681) {
        pcVar3 = *(code **)((ulong)uVar1 * 0x12c0 + uVar4 * 0x20 + 0x11f658);
        if (*(int *)(pcVar3 + -4) != 0x66b891b5) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11ac78);
          (*pcVar3)();
        }
        (*pcVar3)(uVar4,param_2,uVar2);
        return uVar2;
      }
    }
  }
LAB_0011ae30:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x11ae34);
  (*pcVar3)();
}



//------------------------------------------------------------
// gsihal_write_reg_n_fields @ 0011ae3c size=816
// signature: undefined gsihal_write_reg_n_fields(void)
// callers: [gsi_halt_channel_ee, gsi_register_device, gsi_reset_evt_ring, gsi_alloc_channel, gsi_flow_control_ee, gsi_stop_channel, gsi_dealloc_evt_ring, gsi_query_flow_control_state_ee, gsi_alloc_evt_ring, gsi_reset_channel, gsi_dealloc_channel, gsi_enable_flow_control_ee, gsi_stop_db_channel, gsi_alloc_channel_ee, gsi_start_channel]
//------------------------------------------------------------

void gsihal_write_reg_n_fields(uint param_1,int param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  ulong uVar7;
  undefined *puVar8;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  if (param_3 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Input error fields=%pK\n",
             "gsihal_write_reg_n_fields",0x85d,0);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Input error fields=%pK\n",
                       "gsihal_write_reg_n_fields",0x85d,0);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Input error fields=%pK\n",
                       "gsihal_write_reg_n_fields",0x85d,0);
      }
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11b058);
    (*pcVar5)();
  }
  uVar7 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n",
             "gsihal_write_reg_n_fields",0x863,uVar7);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_n_fields",0x863,uVar7);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_n_fields",0x863,uVar7);
      }
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11b0d4);
    (*pcVar5)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011b16c;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d write to %s n=%u after constructing it\n",
                   "gsihal_write_reg_n_fields",0x869,(&gsireg_name_to_str)[uVar7],param_2);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x11b178);
    (*pcVar5)();
  }
  if ((uVar7 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    iVar2 = *(int *)((ulong)uVar1 * 0x12c0 + uVar7 * 0x20 + 0x11f660);
    if (iVar2 == -1) {
      if (param_1 < 0x96) {
        puVar8 = (&gsireg_name_to_str)[uVar7];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Write access to obsolete reg=%s\n",
                 "gsihal_write_reg_n_fields",0x86d,puVar8);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_n_fields",0x86d,puVar8);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_n_fields",0x86d,puVar8);
          }
        }
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11b168);
        (*pcVar5)();
      }
    }
    else {
      uVar6 = uVar7 * 0x20 + (ulong)uVar1 * 0x12c0;
      if (((uVar6 | 0x14) < 0x10681) && (uVar7 * 0x20 + (ulong)uVar1 * 0x12c0 < 0x10679)) {
        iVar3 = *(int *)((ulong)uVar1 * 0x12c0 + uVar7 * 0x20 + 0x11f664);
        if (*(int *)(*(code **)(&gsihal_reg_objs + uVar6) + -4) != -0x5ce0dc77) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11af8c);
          (*pcVar5)();
        }
        (**(code **)(&gsihal_reg_objs + uVar6))(uVar7,param_3,&local_4c);
        DataMemoryBarrier(0,2);
        writel_relaxed(local_4c,*(long *)(gsihal_ctx + 2) + (ulong)(uint)(iVar2 + iVar3 * param_2));
        lVar4 = sp_el0;
        if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
    }
  }
LAB_0011b16c:
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(1,0x11b170);
  (*pcVar5)();
}



//------------------------------------------------------------
// gsihal_read_reg_n_fields @ 0011b17c size=796
// signature: undefined gsihal_read_reg_n_fields(void)
// callers: [gsi_register_device, gsi_channel_state_change_wait, gsi_get_max_channels, gsi_status_enabled, gsi_handle_irq, gsi_get_max_event_rings]
//------------------------------------------------------------

undefined4 gsihal_read_reg_n_fields(uint param_1,int param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  ulong uVar5;
  undefined *puVar6;
  
  if (param_3 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Input error fields\n","gsihal_read_reg_n_fields",
             0x880);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Input error fields\n",
                       "gsihal_read_reg_n_fields",0x880);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Input error fields\n",
                       "gsihal_read_reg_n_fields",0x880);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11b380);
    (*pcVar4)();
  }
  uVar5 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n",
             "gsihal_read_reg_n_fields",0x886,uVar5);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_n_fields",0x886,uVar5);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_n_fields",0x886,uVar5);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11b400);
    (*pcVar4)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011b49c;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d read from %s n=%u and parse it\n",
                   "gsihal_read_reg_n_fields",0x88c,(&gsireg_name_to_str)[uVar5],param_2);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
LAB_0011b4a0:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11b4a4);
    (*pcVar4)();
  }
  if ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    iVar2 = *(int *)((ulong)uVar1 * 0x12c0 + uVar5 * 0x20 + 0x11f660);
    if (iVar2 == -1) {
      if (param_1 < 0x96) {
        puVar6 = (&gsireg_name_to_str)[uVar5];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Read access to obsolete reg=%s\n",
                 "gsihal_read_reg_n_fields",0x890,puVar6);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_n_fields",0x890,puVar6);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_n_fields",0x890,puVar6);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11b498);
        (*pcVar4)();
      }
    }
    else if ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x14) < 0x10681) {
      uVar3 = readl_relaxed(*(long *)(gsihal_ctx + 2) +
                            (ulong)(uint)(iVar2 + *(int *)((ulong)uVar1 * 0x12c0 + uVar5 * 0x20 +
                                                          0x11f664) * param_2));
      uVar1 = *gsihal_ctx;
      if (0xd < uVar1) goto LAB_0011b4a0;
      if ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 8) < 0x10681) {
        pcVar4 = *(code **)((ulong)uVar1 * 0x12c0 + uVar5 * 0x20 + 0x11f658);
        if (*(int *)(pcVar4 + -4) != 0x66b891b5) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b2e4);
          (*pcVar4)();
        }
        (*pcVar4)(uVar5,param_3,uVar3);
        return uVar3;
      }
    }
  }
LAB_0011b49c:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x11b4a0);
  (*pcVar4)();
}



//------------------------------------------------------------
// gsihal_read_reg_nk_fields @ 0011b4a8 size=836
// signature: undefined gsihal_read_reg_nk_fields(void)
// callers: [gsi_dump_halt_debug_reg, gsi_channel_state_change_wait, gsi_enable_flow_control_ee, gsi_handle_irq]
//------------------------------------------------------------

undefined4 gsihal_read_reg_nk_fields(uint param_1,int param_2,int param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  code *pcVar5;
  ulong uVar6;
  undefined *puVar7;
  long lVar8;
  
  if (param_4 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Input error fields\n","gsihal_read_reg_nk_fields",
             0x8a5);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Input error fields\n",
                       "gsihal_read_reg_nk_fields",0x8a5);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Input error fields\n",
                       "gsihal_read_reg_nk_fields",0x8a5);
      }
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11b6d4);
    (*pcVar5)();
  }
  uVar6 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n",
             "gsihal_read_reg_nk_fields",0x8ab,uVar6);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_nk_fields",0x8ab,uVar6);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_read_reg_nk_fields",0x8ab,uVar6);
      }
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11b754);
    (*pcVar5)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011b7f0;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d read from %s n=%u k= %u and parse it\n",
                   "gsihal_read_reg_nk_fields",0x8b1,(&gsireg_name_to_str)[uVar6],param_2,param_3);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
LAB_0011b7f4:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x11b7f8);
    (*pcVar5)();
  }
  if ((uVar6 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    iVar2 = *(int *)((ulong)uVar1 * 0x12c0 + uVar6 * 0x20 + 0x11f660);
    if (iVar2 == -1) {
      if (param_1 < 0x96) {
        puVar7 = (&gsireg_name_to_str)[uVar6];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Read access to obsolete reg=%s\n",
                 "gsihal_read_reg_nk_fields",0x8b5,puVar7);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_nk_fields",0x8b5,puVar7);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Read access to obsolete reg=%s\n",
                           "gsihal_read_reg_nk_fields",0x8b5,puVar7);
          }
        }
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11b7ec);
        (*pcVar5)();
      }
    }
    else {
      lVar8 = uVar6 * 0x20;
      if (((lVar8 + (ulong)uVar1 * 0x12c0 | 0x14) < 0x10681) &&
         ((lVar8 + (ulong)uVar1 * 0x12c0 | 0x18) < 0x10681)) {
        lVar3 = uVar6 * 0x20 + (ulong)uVar1 * 0x12c0;
        uVar4 = readl_relaxed(*(long *)(gsihal_ctx + 2) +
                              (ulong)(uint)(iVar2 + *(int *)(&gsihal_reg_objs + lVar3 + 0x14) *
                                                    param_2 +
                                           *(int *)(&gsihal_reg_objs + lVar3 + 0x18) * param_3));
        uVar1 = *gsihal_ctx;
        if (0xd < uVar1) goto LAB_0011b7f4;
        if ((lVar8 + (ulong)uVar1 * 0x12c0 | 8) < 0x10681) {
          pcVar5 = *(code **)((ulong)uVar1 * 0x12c0 + uVar6 * 0x20 + 0x11f658);
          if (*(int *)(pcVar5 + -4) != 0x66b891b5) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11b634);
            (*pcVar5)();
          }
          (*pcVar5)(uVar6,param_4,uVar4);
          return uVar4;
        }
      }
    }
  }
LAB_0011b7f0:
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(1,0x11b7f4);
  (*pcVar5)();
}



//------------------------------------------------------------
// gsihal_write_reg_nk_fields @ 0011b7fc size=836
// signature: undefined gsihal_write_reg_nk_fields(void)
// callers: [gsi_program_evt_ring_ctx, gsi_program_chan_ctx, gsi_prime_evt_ring]
//------------------------------------------------------------

void gsihal_write_reg_nk_fields(uint param_1,int param_2,int param_3,long param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  code *pcVar6;
  ulong uVar7;
  ulong uVar8;
  undefined *puVar9;
  undefined4 local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  if (param_4 == 0) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Input error fields=%pK\n",
             "gsihal_write_reg_nk_fields",0x8cb,0);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Input error fields=%pK\n",
                       "gsihal_write_reg_nk_fields",0x8cb,0);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Input error fields=%pK\n",
                       "gsihal_write_reg_nk_fields",0x8cb,0);
      }
    }
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x11ba2c);
    (*pcVar6)();
  }
  uVar8 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n",
             "gsihal_write_reg_nk_fields",0x8d1,uVar8);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_nk_fields",0x8d1,uVar8);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_write_reg_nk_fields",0x8d1,uVar8);
      }
    }
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x11baa8);
    (*pcVar6)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011bb40;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d write to %s n=%u after constructing it\n",
                   "gsihal_write_reg_nk_fields",0x8d7,(&gsireg_name_to_str)[uVar8],param_2);
  }
  uVar3 = *gsihal_ctx;
  if (0xd < uVar3) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x11bb4c);
    (*pcVar6)();
  }
  if ((uVar8 * 0x20 + (ulong)uVar3 * 0x12c0 | 0x10) < 0x10681) {
    iVar4 = *(int *)((ulong)uVar3 * 0x12c0 + uVar8 * 0x20 + 0x11f660);
    if (iVar4 == -1) {
      if (param_1 < 0x96) {
        puVar9 = (&gsireg_name_to_str)[uVar8];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Write access to obsolete reg=%s\n",
                 "gsihal_write_reg_nk_fields",0x8db,puVar9);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_nk_fields",0x8db,puVar9);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Write access to obsolete reg=%s\n",
                           "gsihal_write_reg_nk_fields",0x8db,puVar9);
          }
        }
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x11bb3c);
        (*pcVar6)();
      }
    }
    else {
      uVar7 = uVar8 * 0x20 + (ulong)uVar3 * 0x12c0;
      if ((((uVar7 | 0x14) < 0x10681) && ((uVar8 * 0x20 + (ulong)uVar3 * 0x12c0 | 0x18) < 0x10681))
         && (uVar7 < 0x10679)) {
        lVar5 = uVar8 * 0x20 + (ulong)uVar3 * 0x12c0;
        iVar1 = *(int *)(&gsihal_reg_objs + lVar5 + 0x14);
        iVar2 = *(int *)(&gsihal_reg_objs + lVar5 + 0x18);
        if (*(int *)(*(code **)(&gsihal_reg_objs + uVar7) + -4) != -0x5ce0dc77) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11b960);
          (*pcVar6)();
        }
        (**(code **)(&gsihal_reg_objs + uVar7))(uVar8,param_4,&local_4c);
        DataMemoryBarrier(0,2);
        writel_relaxed(local_4c,*(long *)(gsihal_ctx + 2) +
                                (ulong)(uint)(iVar4 + iVar1 * param_2 + iVar2 * param_3));
        lVar5 = sp_el0;
        if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return;
      }
    }
  }
LAB_0011bb40:
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(1,0x11bb44);
  (*pcVar6)();
}



//------------------------------------------------------------
// gsihal_get_reg_nk_ofst @ 0011bb50 size=572
// signature: undefined gsihal_get_reg_nk_ofst(void)
// callers: [gsi_query_msi_addr, gsi_query_evt_ring_db_addr, gsi_get_inst_ram_offset_and_size, gsihal_get_ch_reg_offset, gsi_query_channel_db_addr, gsihal_get_ch_reg_n_offset]
//------------------------------------------------------------

int gsihal_get_reg_nk_ofst(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  undefined *puVar6;
  
  uVar5 = (ulong)param_1;
  if (0x95 < param_1) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Invalid register reg=%u\n","gsihal_get_reg_nk_ofst"
             ,0x8ee,uVar5);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Invalid register reg=%u\n",
                       "gsihal_get_reg_nk_ofst",0x8ee,uVar5);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Invalid register reg=%u\n",
                       "gsihal_get_reg_nk_ofst",0x8ee,uVar5);
      }
    }
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11bcf0);
    (*pcVar4)();
  }
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    if (0x95 < param_1) goto LAB_0011bd8c;
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d get offset of %s k=%u n=%u\n",
                   "gsihal_get_reg_nk_ofst",0x8f4,(&gsireg_name_to_str)[uVar5],param_3,param_2);
  }
  uVar1 = *gsihal_ctx;
  if (0xd < uVar1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11bd94);
    (*pcVar4)();
  }
  if ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x10) < 0x10681) {
    iVar2 = *(int *)((ulong)uVar1 * 0x12c0 + uVar5 * 0x20 + 0x11f660);
    if (iVar2 == -1) {
      if (param_1 < 0x96) {
        puVar6 = (&gsireg_name_to_str)[uVar5];
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d Access to obsolete reg=%s\n",
                 "gsihal_get_reg_nk_ofst",0x8f8,puVar6);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d Access to obsolete reg=%s\n",
                           "gsihal_get_reg_nk_ofst",0x8f8,puVar6);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Access to obsolete reg=%s\n",
                           "gsihal_get_reg_nk_ofst",0x8f8,puVar6);
          }
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11bd88);
        (*pcVar4)();
      }
    }
    else if (((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x14) < 0x10681) &&
            ((uVar5 * 0x20 + (ulong)uVar1 * 0x12c0 | 0x18) < 0x10681)) {
      lVar3 = uVar5 * 0x20 + (ulong)uVar1 * 0x12c0;
      return iVar2 + *(int *)(&gsihal_reg_objs + lVar3 + 0x14) * param_2 +
             *(int *)(&gsihal_reg_objs + lVar3 + 0x18) * param_3;
    }
  }
LAB_0011bd8c:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x11bd90);
  (*pcVar4)();
}



//------------------------------------------------------------
// gsihal_get_bit_map_array_size @ 0011bd98 size=8
// signature: undefined gsihal_get_bit_map_array_size(void)
// callers: [__gsi_config_all_ieob_irq, __gsi_config_all_ch_irq, __gsi_config_all_evt_irq, gsi_deregister_device, gsi_handle_irq]
//------------------------------------------------------------

undefined8 gsihal_get_bit_map_array_size(void)

{
  return 1;
}



//------------------------------------------------------------
// gsihal_read_ch_reg @ 0011bda4 size=36
// signature: undefined gsihal_read_ch_reg(void)
// callers: []
//------------------------------------------------------------

void gsihal_read_ch_reg(undefined8 param_1,ulong param_2)

{
  gsihal_read_reg_nk(param_1,param_2 >> 5 & 0x7ffffff,0);
  return;
}



//------------------------------------------------------------
// gsihal_test_ch_bit @ 0011bdcc size=12
// signature: undefined gsihal_test_ch_bit(void)
// callers: []
//------------------------------------------------------------

uint gsihal_test_ch_bit(uint param_1,uint param_2)

{
  return param_1 >> (ulong)(param_2 & 0x1f) & 1;
}



//------------------------------------------------------------
// gsihal_get_ch_bit @ 0011bddc size=12
// signature: undefined gsihal_get_ch_bit(void)
// callers: []
//------------------------------------------------------------

int gsihal_get_ch_bit(uint param_1)

{
  return 1 << (ulong)(param_1 & 0x1f);
}



//------------------------------------------------------------
// gsihal_get_ch_reg_idx @ 0011bdec size=8
// signature: undefined gsihal_get_ch_reg_idx(void)
// callers: [gsi_channel_state_change_wait, gsi_msi_isr, gsi_poll_n_channel, gsi_config_channel_mode, gsi_stop_channel, gsi_alloc_evt_ring]
//------------------------------------------------------------

ulong gsihal_get_ch_reg_idx(ulong param_1)

{
  return param_1 >> 5 & 0x7ffffff;
}



//------------------------------------------------------------
// gsihal_get_ch_reg_mask @ 0011bdf8 size=12
// signature: undefined gsihal_get_ch_reg_mask(void)
// callers: [gsi_channel_state_change_wait, gsi_msi_isr, gsi_poll_n_channel, gsi_config_channel_mode, gsi_stop_channel, gsi_alloc_evt_ring]
//------------------------------------------------------------

int gsihal_get_ch_reg_mask(uint param_1)

{
  return 1 << (ulong)(param_1 & 0x1f);
}



//------------------------------------------------------------
// gsihal_get_ch_reg_offset @ 0011be08 size=36
// signature: undefined gsihal_get_ch_reg_offset(void)
// callers: []
//------------------------------------------------------------

void gsihal_get_ch_reg_offset(undefined8 param_1,ulong param_2)

{
  gsihal_get_reg_nk_ofst(param_1,0,param_2 >> 5 & 0x7ffffff);
  return;
}



//------------------------------------------------------------
// gsihal_get_ch_reg_n_offset @ 0011be30 size=40
// signature: undefined gsihal_get_ch_reg_n_offset(void)
// callers: []
//------------------------------------------------------------

void gsihal_get_ch_reg_n_offset(undefined8 param_1,undefined4 param_2,ulong param_3)

{
  gsihal_get_reg_nk_ofst(param_1,param_3 >> 5 & 0x7ffffff,param_2);
  return;
}



//------------------------------------------------------------
// gsihal_write_ch_bit_map_reg_n @ 0011be5c size=32
// signature: undefined gsihal_write_ch_bit_map_reg_n(void)
// callers: []
//------------------------------------------------------------

void gsihal_write_ch_bit_map_reg_n(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  gsihal_write_reg_nk(param_1,param_2,param_3 >> 5 & 0x7ffffff);
  return;
}



//------------------------------------------------------------
// gsihal_write_set_ch_bit_map_reg_n @ 0011be80 size=44
// signature: undefined gsihal_write_set_ch_bit_map_reg_n(void)
// callers: []
//------------------------------------------------------------

void gsihal_write_set_ch_bit_map_reg_n(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  gsihal_write_reg_nk(param_1,param_2,param_3 >> 5 & 0x7ffffff,1 << (ulong)((uint)param_3 & 0x1f));
  return;
}



//------------------------------------------------------------
// gsihal_get_inst_ram_size @ 0011beb0 size=216
// signature: undefined gsihal_get_inst_ram_size(void)
// callers: [gsi_get_inst_ram_offset_and_size]
//------------------------------------------------------------

undefined8 gsihal_get_inst_ram_size(void)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = *gsihal_ctx - 1;
  if ((uVar1 < 0xb) && ((0x6ffU >> (ulong)(uVar1 & 0x1f) & 1) != 0)) {
    return *(undefined8 *)(&DAT_0011f120 + (long)(int)uVar1 * 8);
  }
  _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d GSI version is not supported %d\n",
           "gsihal_get_inst_ram_size",0x980);
  if (gsi_ctx != 0) {
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d GSI version is not supported %d\n",
                     "gsihal_get_inst_ram_size",0x980,*gsihal_ctx);
    }
    if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d GSI version is not supported %d\n",
                     "gsihal_get_inst_ram_size",0x980,*gsihal_ctx);
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x11bf88);
  (*pcVar2)();
}



//------------------------------------------------------------
// gsihal_reg_init @ 0011bf90 size=932
// signature: undefined gsihal_reg_init(void)
// callers: [gsihal_init]
//------------------------------------------------------------

void gsihal_reg_init(uint param_1)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  undefined4 *puVar8;
  
  lVar2 = sp_el0;
  lVar2 = *(long *)(lVar2 + 0x638);
  if ((gsi_ctx != 0) && (*(long *)(gsi_ctx + 0x6ff0) != 0)) {
    ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d Entry - GSI ver = %d\n","gsihal_reg_init",
                   0x98f,param_1);
  }
  if (param_1 - 0xe < 0xfffffff3) {
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d invalid GSI HW type (%d)\n","gsihal_reg_init",0x992
             ,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d invalid GSI HW type (%d)\n",
                       "gsihal_reg_init",0x992,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d invalid GSI HW type (%d)\n",
                       "gsihal_reg_init",0x992,param_1);
      }
    }
    uVar6 = 0xffffffea;
  }
  else {
    if (1 < param_1) {
      puVar5 = &gsihal_reg_objs;
      puVar8 = &DAT_00121be0;
      uVar3 = 1;
      do {
        lVar4 = 0;
        uVar3 = uVar3 + 1;
        puVar7 = puVar5;
        do {
          if (((*(long *)(puVar7 + 0x2580) == 0 && *(long *)(puVar7 + 0x2588) == 0) &&
              *(long *)(puVar7 + 0x2590) == 0) && *(long *)(puVar7 + 0x2598) == 0) {
            *(long *)(puVar7 + 0x2580) = *(long *)(puVar7 + 0x12c0);
            *(undefined8 *)(puVar7 + 0x2588) = *(undefined8 *)(puVar7 + 0x12c8);
            *(undefined8 *)(puVar7 + 0x2590) = *(undefined8 *)(puVar7 + 0x12d0);
            *(undefined8 *)(puVar7 + 0x2598) = *(undefined8 *)(puVar7 + 0x12d8);
          }
          else {
            if ((lVar4 != 0x3a8) && (puVar8[lVar4] == 0)) {
              uVar6 = *(undefined8 *)((long)&gsireg_name_to_str + lVar4);
              _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d reg=%s with zero offset gsi_ver=%d\n",
                       "gsihal_reg_init",0x9a6,uVar6,uVar3 & 0xffffffff);
              if (gsi_ctx != 0) {
                if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                                 "%s:%d reg=%s with zero offset gsi_ver=%d\n","gsihal_reg_init",
                                 0x9a6,uVar6,uVar3 & 0xffffffff);
                }
                if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                                 "%s:%d reg=%s with zero offset gsi_ver=%d\n","gsihal_reg_init",
                                 0x9a6,uVar6,uVar3 & 0xffffffff);
                }
              }
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11c1f0);
              (*pcVar1)();
            }
            if (*(long *)(puVar7 + 0x2580) == 0) {
              uVar6 = *(undefined8 *)((long)&gsireg_name_to_str + lVar4);
              _dev_err(*(undefined8 *)(gsi_ctx + 8),
                       "%s:%d reg=%s with NULL construct func gsi_ver=%d\n","gsihal_reg_init",0x9ac,
                       uVar6,uVar3 & 0xffffffff);
              if (gsi_ctx != 0) {
                if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                                 "%s:%d reg=%s with NULL construct func gsi_ver=%d\n",
                                 "gsihal_reg_init",0x9ac,uVar6,uVar3 & 0xffffffff);
                }
                if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                                 "%s:%d reg=%s with NULL construct func gsi_ver=%d\n",
                                 "gsihal_reg_init",0x9ac,uVar6,uVar3 & 0xffffffff);
                }
              }
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11c280);
              (*pcVar1)();
            }
            if (*(long *)(puVar7 + 0x2588) == 0) {
              uVar6 = *(undefined8 *)((long)&gsireg_name_to_str + lVar4);
              _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d reg=%s with NULL parse func gsi_ver=%d\n"
                       ,"gsihal_reg_init",0x9b2,uVar6,uVar3 & 0xffffffff);
              if (gsi_ctx != 0) {
                if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                                 "%s:%d reg=%s with NULL parse func gsi_ver=%d\n","gsihal_reg_init",
                                 0x9b2,uVar6,uVar3 & 0xffffffff);
                }
                if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
                  ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                                 "%s:%d reg=%s with NULL parse func gsi_ver=%d\n","gsihal_reg_init",
                                 0x9b2,uVar6,uVar3 & 0xffffffff);
                }
              }
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11c164);
              (*pcVar1)();
            }
          }
          lVar4 = lVar4 + 8;
          puVar7 = puVar7 + 0x20;
        } while (lVar4 != 0x4b0);
        puVar8 = puVar8 + 0x4b0;
        puVar5 = puVar5 + 0x12c0;
      } while (uVar3 != param_1);
    }
    uVar6 = 0;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != lVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// gsihal_check_ring_length_valid @ 0011c350 size=628
// signature: undefined gsihal_check_ring_length_valid(void)
// callers: [gsi_validate_evt_ring_props, gsi_validate_channel_props]
//------------------------------------------------------------

undefined8 gsihal_check_ring_length_valid(uint param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*gsihal_ctx < 10) {
    if (*gsihal_ctx < 8) {
      if (param_1 < 0x10000) {
        return 1;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params ring_len %u is out of bounds\n",
               "gsihal_check_ring_length_valid",0x9d1,param_1);
      if (gsi_ctx == 0) {
        return 0;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params ring_len %u is out of bounds\n"
                       ,"gsihal_check_ring_length_valid",0x9d1,param_1);
      }
      lVar2 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar2 == 0) {
        return 0;
      }
      uVar3 = 0x9d1;
    }
    else {
      if (param_1 < 0x100000) {
        return 1;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params ring_len %u is out of bounds\n",
               "gsihal_check_ring_length_valid",0x9cc,param_1);
      if (gsi_ctx == 0) {
        return 0;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params ring_len %u is out of bounds\n"
                       ,"gsihal_check_ring_length_valid",0x9cc,param_1);
      }
      lVar2 = *(long *)(gsi_ctx + 0x6ff0);
      if (lVar2 == 0) {
        return 0;
      }
      uVar3 = 0x9cc;
    }
  }
  else {
    if (param_1 >> 0x18 == 0) {
      uVar1 = 0;
      if (param_2 != 0) {
        uVar1 = param_1 / param_2;
      }
      if (uVar1 < 0x10000) {
        return 1;
      }
      _dev_err(*(undefined8 *)(gsi_ctx + 8),
               "%s:%d bad params ring_len %u / re_size %u > 64k elements \n",
               "gsihal_check_ring_length_valid",0x9c7,param_1,param_2);
      if (gsi_ctx == 0) {
        return 0;
      }
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),
                       "%s:%d bad params ring_len %u / re_size %u > 64k elements \n",
                       "gsihal_check_ring_length_valid",0x9c7,param_1,param_2);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) == 0) {
        return 0;
      }
      ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),
                     "%s:%d bad params ring_len %u / re_size %u > 64k elements \n",
                     "gsihal_check_ring_length_valid",0x9c7,param_1,param_2);
      return 0;
    }
    _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d bad params ring_len %u is out of bounds\n",
             "gsihal_check_ring_length_valid",0x9c2,param_1);
    if (gsi_ctx == 0) {
      return 0;
    }
    if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
      ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d bad params ring_len %u is out of bounds\n",
                     "gsihal_check_ring_length_valid",0x9c2,param_1);
    }
    lVar2 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar2 == 0) {
      return 0;
    }
    uVar3 = 0x9c2;
  }
  ipc_log_string(lVar2,"%s:%d bad params ring_len %u is out of bounds\n",
                 "gsihal_check_ring_length_valid",uVar3,param_1);
  return 0;
}



//------------------------------------------------------------
// gsihal_get_glob_irq_en_gp_int1_mask @ 0011c5c8 size=8
// signature: undefined gsihal_get_glob_irq_en_gp_int1_mask(void)
// callers: [gsi_halt_channel_ee, gsi_register_device, gsi_enable_flow_control_ee, gsi_flow_control_ee, gsi_alloc_channel_ee, gsi_query_flow_control_state_ee]
//------------------------------------------------------------

undefined8 gsihal_get_glob_irq_en_gp_int1_mask(void)

{
  return 2;
}



//------------------------------------------------------------
// gsireg_construct_dummy @ 0011c5d4 size=608
// signature: undefined gsireg_construct_dummy(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_dummy(uint param_1)

{
  code *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = *(undefined8 *)(gsi_ctx + 8);
  if (param_1 < 0x96) {
    pcVar2 = (&gsireg_name_to_str)[param_1];
  }
  else {
    _dev_err(uVar3,"%s:%d requested name of invalid reg=%d\n","gsihal_reg_name_str",0xba,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                       "gsihal_reg_name_str",0xba,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                       "gsihal_reg_name_str",0xba,param_1);
      }
    }
    pcVar2 = "Invalid Register";
  }
  _dev_err(uVar3,"%s:%d No construct function for %s\n","gsireg_construct_dummy",0xc5,pcVar2);
  if (gsi_ctx != 0) {
    lVar4 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar4 != 0) {
      if (param_1 < 0x96) {
        pcVar2 = (&gsireg_name_to_str)[param_1];
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d requested name of invalid reg=%d\n",
                 "gsihal_reg_name_str",0xba,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
        }
        pcVar2 = "Invalid Register";
      }
      ipc_log_string(lVar4,"%s:%d No construct function for %s\n","gsireg_construct_dummy",0xc5,
                     pcVar2);
    }
    lVar4 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar4 != 0) {
      if (param_1 < 0x96) {
        pcVar2 = (&gsireg_name_to_str)[param_1];
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d requested name of invalid reg=%d\n",
                 "gsihal_reg_name_str",0xba,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
        }
        pcVar2 = "Invalid Register";
      }
      ipc_log_string(lVar4,"%s:%d No construct function for %s\n","gsireg_construct_dummy",0xc5,
                     pcVar2);
    }
  }
  __warn_printk("invalid register operation");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11c734);
  (*pcVar1)();
}



//------------------------------------------------------------
// gsireg_parse_dummy @ 0011c84c size=608
// signature: undefined gsireg_parse_dummy(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_dummy(uint param_1)

{
  code *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = *(undefined8 *)(gsi_ctx + 8);
  if (param_1 < 0x96) {
    pcVar2 = (&gsireg_name_to_str)[param_1];
  }
  else {
    _dev_err(uVar3,"%s:%d requested name of invalid reg=%d\n","gsihal_reg_name_str",0xba,param_1);
    if (gsi_ctx != 0) {
      if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                       "gsihal_reg_name_str",0xba,param_1);
      }
      if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
        ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                       "gsihal_reg_name_str",0xba,param_1);
      }
    }
    pcVar2 = "Invalid Register";
  }
  _dev_err(uVar3,"%s:%d No parse function for %s\n","gsireg_parse_dummy",0xcd,pcVar2);
  if (gsi_ctx != 0) {
    lVar4 = *(long *)(gsi_ctx + 0x6fe8);
    if (lVar4 != 0) {
      if (param_1 < 0x96) {
        pcVar2 = (&gsireg_name_to_str)[param_1];
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d requested name of invalid reg=%d\n",
                 "gsihal_reg_name_str",0xba,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
        }
        pcVar2 = "Invalid Register";
      }
      ipc_log_string(lVar4,"%s:%d No parse function for %s\n","gsireg_parse_dummy",0xcd,pcVar2);
    }
    lVar4 = *(long *)(gsi_ctx + 0x6ff0);
    if (lVar4 != 0) {
      if (param_1 < 0x96) {
        pcVar2 = (&gsireg_name_to_str)[param_1];
      }
      else {
        _dev_err(*(undefined8 *)(gsi_ctx + 8),"%s:%d requested name of invalid reg=%d\n",
                 "gsihal_reg_name_str",0xba,param_1);
        if (gsi_ctx != 0) {
          if (*(long *)(gsi_ctx + 0x6fe8) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6fe8),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
          if (*(long *)(gsi_ctx + 0x6ff0) != 0) {
            ipc_log_string(*(long *)(gsi_ctx + 0x6ff0),"%s:%d requested name of invalid reg=%d\n",
                           "gsihal_reg_name_str",0xba,param_1);
          }
        }
        pcVar2 = "Invalid Register";
      }
      ipc_log_string(lVar4,"%s:%d No parse function for %s\n","gsireg_parse_dummy",0xcd,pcVar2);
    }
  }
  __warn_printk("invalid register operation");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11c9ac);
  (*pcVar1)();
}



//------------------------------------------------------------
// gsireg_construct_cntxt_gsi_irq_en @ 0011cac4 size=88
// signature: undefined gsireg_construct_cntxt_gsi_irq_en(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_cntxt_gsi_irq_en(undefined8 param_1,char *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(*param_2 != '\0') << 3;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[1] != '\0') << 2;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[2] != '\0') << 1;
  *param_3 = uVar1;
  *param_3 = uVar1 | param_2[3] != '\0';
  return;
}



//------------------------------------------------------------
// gsireg_parse_ctx_type_irq @ 0011cb20 size=48
// signature: undefined gsireg_parse_ctx_type_irq(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ctx_type_irq(undefined8 param_1,uint *param_2,uint param_3)

{
  param_2[5] = param_3 >> 1 & 1;
  param_2[6] = param_3 & 1;
  param_2[3] = param_3 >> 3 & 1;
  param_2[4] = param_3 >> 2 & 1;
  param_2[1] = param_3 >> 5 & 1;
  param_2[2] = param_3 >> 4 & 1;
  *param_2 = param_3 >> 6 & 1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ch_k_cntxt_0 @ 0011cb54 size=120
// signature: undefined gsireg_construct_ch_k_cntxt_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ch_k_cntxt_0(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xfU) << 0x14 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[2] & 0x1fU) << 0xe | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[4] & 0x1fU) << 8 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[5] & 0xfU) << 4 | uVar1;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[6] != 0) << 3;
  *param_3 = uVar1;
  *param_3 = uVar1 | param_2[7] & 7U;
  return;
}



//------------------------------------------------------------
// gsireg_parse_ch_k_cntxt_0 @ 0011cbd0 size=48
// signature: undefined gsireg_parse_ch_k_cntxt_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ch_k_cntxt_0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x18;
  param_2[1] = param_3 >> 0x14 & 0xf;
  param_2[2] = param_3 >> 0xe & 0x1f;
  param_2[4] = param_3 >> 8 & 0x1f;
  param_2[5] = param_3 >> 4 & 0xf;
  param_2[6] = param_3 >> 3 & 1;
  param_2[7] = param_3 & 7;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_0 @ 0011cc04 size=100
// signature: undefined gsireg_construct_ev_ch_k_cntxt_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_0(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xfU) << 0x14 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[3] & 0xffU) << 8 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[2] & 1U) << 0x10 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[4] & 0xfU) << 4 | uVar1;
  *param_3 = uVar1;
  *param_3 = uVar1 | param_2[5] & 0xfU;
  return;
}



//------------------------------------------------------------
// gsireg_parse_ev_ch_k_cntxt_0 @ 0011cc6c size=40
// signature: undefined gsireg_parse_ev_ch_k_cntxt_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ev_ch_k_cntxt_0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x18;
  param_2[1] = param_3 >> 0x14 & 0xf;
  param_2[2] = param_3 >> 0x10 & 1;
  param_2[3] = param_3 >> 8 & 0xff;
  param_2[4] = param_3 >> 4 & 0xf;
  param_2[5] = param_3 & 0xf;
  return;
}



//------------------------------------------------------------
// gsireg_parse_cntxt_glob_irq_stts @ 0011cc98 size=36
// signature: undefined gsireg_parse_cntxt_glob_irq_stts(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_cntxt_glob_irq_stts(undefined8 param_1,byte *param_2,uint param_3)

{
  *param_2 = (byte)(param_3 >> 3) & 1;
  param_2[1] = (byte)(param_3 >> 2) & 1;
  param_2[2] = (byte)(param_3 >> 1) & 1;
  param_2[3] = (byte)param_3 & 1;
  return;
}



//------------------------------------------------------------
// gsireg_parse_cntxt_gsi_irq_stts @ 0011ccc0 size=36
// signature: undefined gsireg_parse_cntxt_gsi_irq_stts(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_cntxt_gsi_irq_stts(undefined8 param_1,byte *param_2,uint param_3)

{
  *param_2 = (byte)(param_3 >> 3) & 1;
  param_2[1] = (byte)(param_3 >> 2) & 1;
  param_2[2] = (byte)(param_3 >> 1) & 1;
  param_2[3] = (byte)param_3 & 1;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param @ 0011cce8 size=40
// signature: undefined gsireg_parse_hw_param(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x1a & 0x1f;
  param_2[1] = param_3 >> 0x19 & 1;
  param_2[2] = param_3 >> 0x14 & 0x1f;
  param_2[3] = param_3 >> 0x10 & 0xf;
  param_2[4] = param_3 >> 8 & 0xff;
  param_2[5] = param_3 & 0xff;
  return;
}



//------------------------------------------------------------
// gsireg_parse_gsi_status @ 0011cd14 size=12
// signature: undefined gsireg_parse_gsi_status(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_gsi_status(undefined8 param_1,byte *param_2,byte param_3)

{
  *param_2 = param_3 & 1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_1 @ 0011cd24 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_1(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_1(undefined8 param_1,ushort *param_2,uint *param_3)

{
  *param_3 = *param_3 | (uint)*param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_2 @ 0011cd3c size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_2(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_2(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_3 @ 0011cd54 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_3(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_3(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_8 @ 0011cd6c size=48
// signature: undefined gsireg_construct_ev_ch_k_cntxt_8(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_8(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xffU) << 0x10 | uVar1;
  *param_3 = uVar1;
  *param_3 = uVar1 | *(ushort *)(param_2 + 2);
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_9 @ 0011cda0 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_9(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_9(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_10 @ 0011cdb8 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_10(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_10(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_11 @ 0011cdd0 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_11(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_11(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_12 @ 0011cde8 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_12(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_12(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_13 @ 0011ce00 size=20
// signature: undefined gsireg_construct_ev_ch_k_cntxt_13(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_13(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_doorbell_1 @ 0011ce18 size=20
// signature: undefined gsireg_construct_ev_ch_k_doorbell_1(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_doorbell_1(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_ev_ch_cmd @ 0011ce30 size=32
// signature: undefined gsireg_construct_ee_n_ev_ch_cmd(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_ev_ch_cmd(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  *param_3 = *(byte *)(param_2 + 1) | uVar1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_gsi_ch_k_qos @ 0011ce54 size=64
// signature: undefined gsireg_construct_ee_n_gsi_ch_k_qos(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_gsi_ch_k_qos(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(*(int *)(param_2 + 0x14) != 0) << 9;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0x18) != 0) << 8;
  *param_3 = uVar1;
  *param_3 = uVar1 | *(uint *)(param_2 + 0x1c) & 0xf;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ch_k_cntxt_1 @ 0011ce98 size=20
// signature: undefined gsireg_construct_ch_k_cntxt_1(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ch_k_cntxt_1(undefined8 param_1,ushort *param_2,uint *param_3)

{
  *param_3 = *param_3 | (uint)*param_2;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_gsi_ch_cmd @ 0011ceb0 size=32
// signature: undefined gsireg_construct_ee_n_gsi_ch_cmd(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_gsi_ch_cmd(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  *param_3 = *(byte *)(param_2 + 1) | uVar1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_gsi_cfg @ 0011ced4 size=128
// signature: undefined gsireg_construct_gsi_cfg(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_gsi_cfg(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(*(int *)(param_2 + 4) != 0) << 5;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 8) != 0) << 4;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0xc) != 0) << 3;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0x10) != 0) << 2;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0x14) != 0) << 1;
  *param_3 = uVar1;
  *param_3 = uVar1 | *(int *)(param_2 + 0x18) != 0;
  return;
}



//------------------------------------------------------------
// gsireg_construct_gsi_ee_generic_cmd @ 0011cf58 size=56
// signature: undefined gsireg_construct_gsi_ee_generic_cmd(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_gsi_ee_generic_cmd(undefined8 param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 & 0x1f;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0x1f) << 5 | uVar1;
  *param_3 = uVar1;
  *param_3 = (param_2[2] & 0xf) << 10 | uVar1;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param0 @ 0011cf94 size=40
// signature: undefined gsireg_parse_hw_param0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x1a & 0x1f;
  param_2[1] = param_3 >> 0x1f;
  param_2[2] = param_3 >> 0x15 & 0x1f;
  param_2[3] = param_3 >> 0x10 & 0x1f;
  param_2[4] = param_3 >> 8 & 0xff;
  param_2[5] = param_3 & 0xff;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_gsi_ch_k_qos_v1_2 @ 0011cfc0 size=84
// signature: undefined gsireg_construct_ee_n_gsi_ch_k_qos_v1_2(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_gsi_ch_k_qos_v1_2(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(*(int *)(param_2 + 0x14) != 0) << 9;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0x18) != 0) << 8;
  *param_3 = uVar1;
  uVar1 = uVar1 | *(uint *)(param_2 + 0x1c) & 0xf;
  *param_3 = uVar1;
  *param_3 = uVar1 | (uint)(*(int *)(param_2 + 0x10) != 0) << 10;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param2 @ 0011d018 size=36
// signature: undefined gsireg_parse_hw_param2(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param2(undefined8 param_1,long param_2,uint param_3)

{
  *(uint *)(param_2 + 0x18) = param_3 >> 0xe & 1;
  *(uint *)(param_2 + 0x1c) = param_3 >> 0xd & 1;
  *(uint *)(param_2 + 0x20) = param_3 >> 8 & 0x1f;
  *(uint *)(param_2 + 0x24) = param_3 >> 3 & 0x1f;
  *(uint *)(param_2 + 0x28) = param_3 & 7;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param2_v2_0 @ 0011d040 size=60
// signature: undefined gsireg_parse_hw_param2_v2_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param2_v2_0(undefined8 param_1,long param_2,uint param_3)

{
  *(uint *)(param_2 + 0x18) = param_3 >> 0xe & 1;
  *(uint *)(param_2 + 0x1c) = param_3 >> 0xd & 1;
  *(uint *)(param_2 + 0x20) = param_3 >> 8 & 0x1f;
  *(uint *)(param_2 + 0x24) = param_3 >> 3 & 0x1f;
  *(uint *)(param_2 + 0x28) = param_3 & 7;
  *(uint *)(param_2 + 8) = param_3 >> 0x1b & 7;
  *(uint *)(param_2 + 0xc) = param_3 >> 0x13 & 0xff;
  *(uint *)(param_2 + 0x10) = param_3 >> 0x10 & 7;
  *(uint *)(param_2 + 0x14) = param_3 >> 0xf & 1;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param2_v2_2 @ 0011d080 size=72
// signature: undefined gsireg_parse_hw_param2_v2_2(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param2_v2_2(undefined8 param_1,uint *param_2,uint param_3)

{
  param_2[6] = param_3 >> 0xe & 1;
  param_2[7] = param_3 >> 0xd & 1;
  param_2[8] = param_3 >> 8 & 0x1f;
  param_2[9] = param_3 >> 3 & 0x1f;
  param_2[10] = param_3 & 7;
  param_2[2] = param_3 >> 0x1b & 7;
  param_2[3] = param_3 >> 0x13 & 0xff;
  param_2[4] = param_3 >> 0x10 & 7;
  param_2[5] = param_3 >> 0xf & 1;
  *param_2 = param_3 >> 0x1f;
  param_2[1] = param_3 >> 0x1e & 1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ch_k_cntxt_0_v2_5 @ 0011d0cc size=140
// signature: undefined gsireg_construct_ch_k_cntxt_0_v2_5(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ch_k_cntxt_0_v2_5(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xfU) << 0x14 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[2] & 0x1fU) << 0xe | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[4] & 0x1fU) << 8 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[5] & 0xfU) << 4 | uVar1;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[6] != 0) << 3;
  *param_3 = uVar1;
  uVar1 = uVar1 | param_2[7] & 7U;
  *param_3 = uVar1;
  *param_3 = uVar1 | (uint)(param_2[3] != 0) << 0xd;
  return;
}



//------------------------------------------------------------
// gsireg_parse_ch_k_cntxt_0_v2_5 @ 0011d15c size=52
// signature: undefined gsireg_parse_ch_k_cntxt_0_v2_5(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ch_k_cntxt_0_v2_5(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x18;
  param_2[1] = param_3 >> 0x14 & 0xf;
  param_2[4] = param_3 >> 8 & 0x1f;
  param_2[5] = param_3 >> 4 & 0xf;
  param_2[6] = param_3 >> 3 & 1;
  param_2[7] = param_3 & 7;
  param_2[2] = param_3 >> 0xe & 0x1f;
  param_2[3] = param_3 >> 0xd & 1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_gsi_ch_k_qos_v2_5 @ 0011d194 size=96
// signature: undefined gsireg_construct_ee_n_gsi_ch_k_qos_v2_5(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_gsi_ch_k_qos_v2_5(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(*(int *)(param_2 + 0x14) != 0) << 9;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0x18) != 0) << 8;
  *param_3 = uVar1;
  uVar1 = uVar1 | *(uint *)(param_2 + 0x1c) & 0xf;
  *param_3 = uVar1;
  uVar1 = (*(uint *)(param_2 + 8) & 0xff) << 0x10 | uVar1;
  *param_3 = uVar1;
  *param_3 = (*(uint *)(param_2 + 0xc) & 0xf) << 10 | uVar1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_gsi_cfg_v2_5 @ 0011d1f8 size=144
// signature: undefined gsireg_construct_gsi_cfg_v2_5(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_gsi_cfg_v2_5(undefined8 param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(param_2[1] != 0) << 5;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[2] != 0) << 4;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[3] != 0) << 3;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[4] != 0) << 2;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[5] != 0) << 1;
  *param_3 = uVar1;
  uVar1 = uVar1 | param_2[6] != 0;
  *param_3 = uVar1;
  *param_3 = (*param_2 & 0xf) << 8 | uVar1;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_1_v2_9 @ 0011d28c size=24
// signature: undefined gsireg_construct_ev_ch_k_cntxt_1_v2_9(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_1_v2_9(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2 & 0xfffff;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_gsi_ch_k_qos_v2_9 @ 0011d2a8 size=116
// signature: undefined gsireg_construct_ee_n_gsi_ch_k_qos_v2_9(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_gsi_ch_k_qos_v2_9(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(*(int *)(param_2 + 0x14) != 0) << 9;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(*(int *)(param_2 + 0x18) != 0) << 8;
  *param_3 = uVar1;
  uVar1 = uVar1 | *(uint *)(param_2 + 0x1c) & 0xf;
  *param_3 = uVar1;
  uVar1 = (*(uint *)(param_2 + 8) & 0xff) << 0x10 | uVar1;
  *param_3 = uVar1;
  uVar1 = (*(uint *)(param_2 + 0xc) & 0xf) << 10 | uVar1;
  *param_3 = uVar1;
  *param_3 = uVar1 | (uint)(*(int *)(param_2 + 4) != 0) << 0x18;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ch_k_cntxt_1_v2_9 @ 0011d320 size=24
// signature: undefined gsireg_construct_ch_k_cntxt_1_v2_9(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ch_k_cntxt_1_v2_9(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2 & 0xfffff;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ch_k_cntxt_0_v3_0 @ 0011d33c size=104
// signature: undefined gsireg_construct_ch_k_cntxt_0_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ch_k_cntxt_0_v3_0(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xfU) << 0x14 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[4] & 0xffU) << 0xc | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[5] & 0xfU) << 8 | uVar1;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[6] != 0) << 7;
  *param_3 = uVar1;
  *param_3 = uVar1 | param_2[7] & 0x7fU;
  return;
}



//------------------------------------------------------------
// gsireg_parse_ch_k_cntxt_0_v3_0 @ 0011d3a8 size=40
// signature: undefined gsireg_parse_ch_k_cntxt_0_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ch_k_cntxt_0_v3_0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x18;
  param_2[1] = param_3 >> 0x14 & 0xf;
  param_2[4] = param_3 >> 0xc & 0xff;
  param_2[5] = param_3 >> 8 & 0xf;
  param_2[6] = param_3 >> 7 & 1;
  param_2[7] = param_3 & 0x7f;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_0_v3_0 @ 0011d3d4 size=100
// signature: undefined gsireg_construct_ev_ch_k_cntxt_0_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_0_v3_0(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 << 0x18;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xfU) << 0x14 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[3] & 0xffU) << 8 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[4] & 0xfU) << 0x10 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[2] & 1U) << 7 | uVar1;
  *param_3 = uVar1;
  *param_3 = uVar1 | param_2[5] & 0x7fU;
  return;
}



//------------------------------------------------------------
// gsireg_parse_ev_ch_k_cntxt_0_v3_0 @ 0011d43c size=40
// signature: undefined gsireg_parse_ev_ch_k_cntxt_0_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ev_ch_k_cntxt_0_v3_0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 0x18;
  param_2[1] = param_3 >> 0x14 & 0xf;
  param_2[2] = param_3 >> 7 & 1;
  param_2[3] = param_3 >> 8 & 0xff;
  param_2[4] = param_3 >> 0x10 & 0xf;
  param_2[5] = param_3 & 0x7f;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param2_v3_0 @ 0011d468 size=64
// signature: undefined gsireg_parse_hw_param2_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param2_v3_0(undefined8 param_1,uint *param_2,uint param_3)

{
  param_2[6] = param_3 >> 0xe & 1;
  param_2[7] = param_3 >> 0xd & 1;
  param_2[9] = param_3 & 0xff;
  param_2[10] = param_3 >> 8 & 0x1f;
  param_2[2] = param_3 >> 0x1b & 7;
  param_2[3] = param_3 >> 0x13 & 0xff;
  param_2[4] = param_3 >> 0x10 & 7;
  param_2[5] = param_3 >> 0xf & 1;
  *param_2 = param_3 >> 0x1f;
  param_2[1] = param_3 >> 0x1e & 1;
  return;
}



//------------------------------------------------------------
// gsireg_parse_hw_param4_v3_0 @ 0011d4ac size=16
// signature: undefined gsireg_parse_hw_param4_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_hw_param4_v3_0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 >> 8 & 0xff;
  param_2[1] = param_3 & 0xff;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ev_ch_k_cntxt_1_v3_0 @ 0011d4c0 size=24
// signature: undefined gsireg_construct_ev_ch_k_cntxt_1_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ev_ch_k_cntxt_1_v3_0(undefined8 param_1,uint *param_2,uint *param_3)

{
  *param_3 = *param_3 | *param_2 & 0xffffff;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ee_n_gsi_ch_k_qos_v3_0 @ 0011d4dc size=136
// signature: undefined gsireg_construct_ee_n_gsi_ch_k_qos_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ee_n_gsi_ch_k_qos_v3_0(undefined8 param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | (uint)(param_2[5] != 0) << 9;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[6] != 0) << 8;
  *param_3 = uVar1;
  uVar1 = uVar1 | param_2[7] & 0xfU;
  *param_3 = uVar1;
  uVar1 = (param_2[2] & 0xffU) << 0x10 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[3] & 0xfU) << 10 | uVar1;
  *param_3 = uVar1;
  uVar1 = uVar1 | (uint)(param_2[1] != 0) << 0x18;
  *param_3 = uVar1;
  *param_3 = uVar1 | (uint)(*param_2 != 0) << 0x19;
  return;
}



//------------------------------------------------------------
// gsireg_construct_ch_k_cntxt_1_v3_0 @ 0011d568 size=36
// signature: undefined gsireg_construct_ch_k_cntxt_1_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_ch_k_cntxt_1_v3_0(undefined8 param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 & 0xffffff;
  *param_3 = uVar1;
  *param_3 = uVar1 | param_2[1] << 0x18;
  return;
}



//------------------------------------------------------------
// gsireg_parse_ch_k_cntxt_1_v3_0 @ 0011d590 size=16
// signature: undefined gsireg_parse_ch_k_cntxt_1_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_parse_ch_k_cntxt_1_v3_0(undefined8 param_1,uint *param_2,uint param_3)

{
  *param_2 = param_3 & 0xffffff;
  param_2[1] = param_3 >> 0x18;
  return;
}



//------------------------------------------------------------
// gsireg_construct_gsi_ee_generic_cmd_v3_0 @ 0011d5a4 size=68
// signature: undefined gsireg_construct_gsi_ee_generic_cmd_v3_0(void)
// callers: []
//------------------------------------------------------------

void gsireg_construct_gsi_ee_generic_cmd_v3_0(undefined8 param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = *param_3 | *param_2 & 0x1f;
  *param_3 = uVar1;
  uVar1 = (param_2[1] & 0xff) << 5 | uVar1;
  *param_3 = uVar1;
  uVar1 = (param_2[2] & 0xf) << 0xd | uVar1;
  *param_3 = uVar1;
  *param_3 = uVar1 | (uint)(byte)param_2[3] << 0x18;
  return;
}



//------------------------------------------------------------
// init_module @ 0011f17c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_gsi_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0011f1ac size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_gsi_driver);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00138000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00138008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00138010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00138018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gsihal_reg_init, gsi_register_device, gsi_get_max_channels, gsi_status_enabled, gsi_alloc_channel, gsi_isr, gsi_flow_control_ee, gsi_rst_stats, gsi_dealloc_evt_ring, gsi_dump_ch_scratch_info, gsi_alloc_evt_ring, gsi_print_dp_stats, gsi_map_base, perf_trace_gsi_qtimer, gsi_enable_flow_control_ee, gsi_handle_irq, gsihal_write_reg_n_fields, gsi_prime_evt_ring, gsi_dump_evt, gsihal_write_reg_nk_fields, trace_event_raw_event_gsi_qtimer, gsi_halt_channel_ee, gsi_reset_evt_ring, gsi_program_evt_ring_ctx, gsi_enable_ipc_low, gsi_dump_stats, gsi_enable_dp_stats, gsi_get_max_event_rings, gsi_stop_channel, gsi_read_gsi_fw_version, gsi_poll_channel, gsi_enable_fw, gsi_query_flow_control_state_ee, gsihal_write_reg_fields, gsi_reset_channel, gsi_dump_halt_debug_reg, gsi_channel_state_change_wait, qcom_va_md_gsi_notif_handler, gsi_dealloc_channel, gsi_program_chan_ctx, gsi_read_gsi_hw_profiling_stats, gsi_msi_isr, gsi_stop_db_channel, gsi_dump_ch, gsi_alloc_channel_ee, gsi_start_channel, gsi_set_max_elem_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00138020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00138028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 00138030 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00138038 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gsi_is_channel_empty, gsi_reset_evt_ring, gsi_queue_xfer, gsi_complete_clk_grant, gsi_handle_irq, gsi_msi_isr, gsi_poll_n_channel, gsi_config_channel_mode, gsi_stop_channel, gsi_prime_evt_ring, gsi_query_channel_info, gsi_alloc_evt_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00138040 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gsi_is_channel_empty, gsi_reset_evt_ring, gsi_queue_xfer, gsi_complete_clk_grant, gsi_handle_irq, gsi_msi_isr, gsi_poll_n_channel, gsi_config_channel_mode, gsi_stop_channel, gsi_prime_evt_ring, gsi_query_channel_info, gsi_alloc_evt_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00138048 size=1
// signature: undefined _printk(void)
// callers: [gsi_dump_ch_info, gsi_register_device, gsi_complete_clk_grant, gsi_read_channel_scratch, gsi_update_mhi_channel_scratch, gsi_configure_regs, gsi_set_evt_ring_cfg, gsi_write_channel_scratch3_reg, gsi_rst_stats, gsi_wdi3_dump_register, gsi_dealloc_evt_ring, gsi_dump_ch_scratch_info, gsi_query_channel_db_addr, gsi_alloc_evt_ring, gsi_write_channel_scratch, gsi_config_channel_mode, gsi_dump_evt, gsi_start_xfer, gsi_queue_xfer, gsi_query_device_msi_addr, gsi_enable_dp_stats, gsi_ring_evt_ring_db, gsi_get_channel_cfg, gsi_dump_ch_stats, gsi_debugfs_init, gsi_query_flow_control_state_ee, gsi_get_evt_ring_cfg, gsi_deregister_device, gsi_dealloc_channel, gsi_map_virtual_ch_to_per_ep, gsi_write_wdi3_channel_scratch2_reg, gsi_query_msi_addr, gsi_alloc_channel, gsi_poll_n_channel, gsi_flow_control_ee, gsi_write_evt_ring_scratch, gsi_print_dp_stats, gsi_map_base, gsi_enable_flow_control_ee, gsi_write_channel_scratch2_reg, gsi_unmap_base, gsi_write_device_scratch, gsi_halt_channel_ee, gsi_reset_evt_ring, gsi_set_channel_cfg, gsi_enable_ipc_low, gsi_query_evt_ring_db_addr, gsi_dump_stats, gsi_read_wdi3_channel_scratch2_reg, gsi_stop_channel, gsi_query_channel_info, gsi_wdi3_write_evt_ring_db, gsi_ring_ch_ring_db, gsi_reset_channel, gsi_is_channel_empty, gsi_stop_db_channel, gsi_get_inst_ram_offset_and_size, gsi_dump_ch, gsi_alloc_channel_ee, gsi_start_channel, gsi_set_max_elem_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00138050 size=1
// signature: undefined _dev_err(void)
// callers: [gsi_dump_ch_info, gsihal_reg_name_str, gsi_register_device, gsi_complete_clk_grant, gsi_read_channel_scratch, gsi_update_mhi_channel_scratch, gsireg_parse_dummy, gsi_configure_regs, gsihal_get_reg_nk_ofst, gsi_set_evt_ring_cfg, gsi_write_channel_scratch3_reg, gsi_dealloc_evt_ring, gsi_query_channel_db_addr, gsi_alloc_evt_ring, gsi_write_channel_scratch, __gsi_populate_gci_tre, gsi_is_event_pending, gsihal_write_reg_nk, gsi_dump_ch_scratch, gsi_handle_irq, gsi_config_channel_mode, gsihal_write_reg_n_fields, gsi_start_xfer, gsi_queue_xfer, gsi_ring_evt_ring_db, __gsi_get_gci_cookie, gsi_get_channel_cfg, __gsi_allocate_msis, gsi_get_max_event_rings, gsi_process_evt_re, gsi_get_hw_profiling_stats, gsihal_init, gsireg_construct_dummy, gsihal_read_reg_nk_fields, gsi_query_flow_control_state_ee, gsi_dump_halt_debug_reg, gsi_get_evt_ring_cfg, gsi_get_fw_version, gsihal_read_reg_fields, gsi_deregister_device, gsi_dealloc_channel, gsi_map_virtual_ch_to_per_ep, gsi_program_chan_ctx, gsi_validate_channel_props, gsi_get_complete_num, gsihal_reg_init, gsi_write_wdi3_channel_scratch2_reg, gsi_query_msi_addr, gsi_get_max_channels, gsi_alloc_channel, gsi_poll_n_channel, gsi_flow_control_ee, gsi_write_evt_ring_scratch, gsi_map_base, gsi_get_drop_stats, gsi_enable_flow_control_ee, gsi_write_channel_scratch2_reg, gsi_ntn3_client_stats_get, gsi_unmap_base, gsi_write_device_scratch, gsihal_write_reg_nk_fields, gsihal_read_reg_n_fields, gsi_halt_channel_ee, msm_gsi_probe, gsi_reset_evt_ring, gsi_set_channel_cfg, gsi_query_evt_ring_db_addr, gsi_read_wdi3_channel_scratch2_reg, gsi_stop_channel, gsi_query_channel_info, gsi_enable_fw, gsi_ring_ch_ring_db, gsihal_write_reg_fields, gsi_reset_channel, gsi_is_channel_empty, gsihal_get_inst_ram_size, gsi_validate_evt_ring_props, __gsi_populate_tre, gsi_msi_isr, gsi_stop_db_channel, gsihal_check_ring_length_valid, gsi_alloc_channel_ee, gsi_start_channel, gsihal_read_reg_nk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00138058 size=1
// signature: undefined ipc_log_string(void)
// callers: [gsi_dump_ch_info, gsihal_reg_name_str, gsi_register_device, gsi_complete_clk_grant, gsi_read_channel_scratch, gsi_update_mhi_channel_scratch, gsireg_parse_dummy, gsi_configure_regs, gsihal_get_reg_nk_ofst, gsi_set_evt_ring_cfg, gsi_write_channel_scratch3_reg, gsi_wdi3_dump_register, gsi_dealloc_evt_ring, gsi_query_channel_db_addr, gsi_alloc_evt_ring, gsi_write_channel_scratch, __gsi_config_all_ieob_irq, __gsi_populate_gci_tre, gsi_is_event_pending, gsihal_write_reg_nk, gsi_dump_ch_scratch, gsi_handle_irq, gsi_config_channel_mode, gsihal_write_reg_n_fields, gsi_start_xfer, gsi_queue_xfer, gsi_query_device_msi_addr, gsi_ring_evt_ring_db, __gsi_get_gci_cookie, gsi_get_channel_cfg, __gsi_allocate_msis, gsi_get_max_event_rings, gsi_process_evt_re, __gsi_config_ieob_irq, gsi_get_hw_profiling_stats, gsihal_init, gsireg_construct_dummy, gsihal_read_reg_nk_fields, gsi_query_flow_control_state_ee, gsi_dump_halt_debug_reg, gsi_get_evt_ring_cfg, gsi_get_fw_version, gsihal_read_reg_fields, gsi_deregister_device, gsi_dealloc_channel, gsi_map_virtual_ch_to_per_ep, gsi_program_chan_ctx, gsi_validate_channel_props, gsi_get_complete_num, gsihal_reg_init, gsi_write_wdi3_channel_scratch2_reg, gsi_query_msi_addr, gsi_get_max_channels, gsi_alloc_channel, __gsi_msi_write_msg, gsi_poll_n_channel, gsi_flow_control_ee, gsi_write_evt_ring_scratch, gsi_map_base, gsi_get_drop_stats, gsi_enable_flow_control_ee, gsi_write_channel_scratch2_reg, gsi_ntn3_client_stats_get, gsi_unmap_base, gsi_write_device_scratch, gsihal_write_reg_nk_fields, gsihal_read_reg_n_fields, gsi_halt_channel_ee, msm_gsi_probe, gsi_reset_evt_ring, gsi_program_evt_ring_ctx, gsi_set_channel_cfg, gsi_query_evt_ring_db_addr, gsihal_destroy, gsi_read_wdi3_channel_scratch2_reg, gsi_stop_channel, gsi_query_channel_info, gsi_enable_fw, gsi_ring_ch_ring_db, gsihal_write_reg_fields, gsi_reset_channel, __gsi_config_ieob_irq_k, gsi_is_channel_empty, gsihal_get_inst_ram_size, gsi_channel_state_change_wait, gsi_validate_evt_ring_props, __gsi_populate_tre, gsi_msi_isr, gsi_stop_db_channel, gsihal_check_ring_length_valid, gsi_alloc_channel_ee, gsi_start_channel, gsihal_read_reg_nk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00138060 size=1
// signature: undefined sched_clock(void)
// callers: [gsi_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00138068 size=1
// signature: undefined complete(void)
// callers: [gsi_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00138088 size=1
// signature: undefined devm_ioremap(void)
// callers: [gsi_map_base]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_iounmap @ 00138090 size=1
// signature: undefined devm_iounmap(void)
// callers: [gsi_unmap_base]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00138098 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [gsi_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001380a0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [gsi_register_device, __gsi_allocate_msis]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001380a8 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [gsi_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001380b0 size=1
// signature: undefined __mutex_init(void)
// callers: [gsi_register_device, gsi_alloc_channel, gsi_alloc_channel_ee, gsi_alloc_evt_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 001380b8 size=1
// signature: undefined devm_free_irq(void)
// callers: [gsi_register_device, gsi_deregister_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_msi_domain_free_irqs @ 001380c0 size=1
// signature: undefined platform_msi_domain_free_irqs(void)
// callers: [gsi_register_device, gsi_deregister_device, __gsi_allocate_msis]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_msi_domain_free_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001380c8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [gsi_register_device, gsi_reset_evt_ring, gsi_enable_dp_stats, gsi_alloc_channel, __gsi_allocate_msis, gsi_dump_ch_scratch_info, gsi_alloc_evt_ring, gsi_print_dp_stats, gsi_dump_ch, gsi_prime_evt_ring, gsi_alloc_channel_ee, gsi_dump_evt, gsi_set_max_elem_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_msi_domain_alloc_irqs @ 001380d8 size=1
// signature: undefined platform_msi_domain_alloc_irqs(void)
// callers: [__gsi_allocate_msis]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_msi_domain_alloc_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msi_get_virq @ 001380e0 size=1
// signature: undefined msi_get_virq(void)
// callers: [__gsi_allocate_msis]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msi_get_virq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001380e8 size=1
// signature: undefined mutex_lock(void)
// callers: [gsi_write_wdi3_channel_scratch2_reg, gsi_read_channel_scratch, gsi_update_mhi_channel_scratch, gsi_alloc_channel, gsi_flow_control_ee, gsi_set_evt_ring_cfg, gsi_write_channel_scratch3_reg, gsi_write_evt_ring_scratch, gsi_dealloc_evt_ring, gsi_alloc_evt_ring, gsi_write_channel_scratch, gsi_enable_flow_control_ee, gsi_write_channel_scratch2_reg, gsi_write_device_scratch, gsi_halt_channel_ee, gsi_reset_evt_ring, gsi_set_channel_cfg, gsi_enable_ipc_low, gsi_get_channel_cfg, gsi_read_wdi3_channel_scratch2_reg, gsi_stop_channel, gsi_query_flow_control_state_ee, gsi_reset_channel, gsi_get_evt_ring_cfg, gsi_dealloc_channel, gsi_stop_db_channel, gsi_alloc_channel_ee, gsi_start_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001380f0 size=1
// signature: undefined mutex_unlock(void)
// callers: [gsi_write_wdi3_channel_scratch2_reg, gsi_read_channel_scratch, gsi_update_mhi_channel_scratch, gsi_alloc_channel, gsi_flow_control_ee, gsi_set_evt_ring_cfg, gsi_write_channel_scratch3_reg, gsi_write_evt_ring_scratch, gsi_dealloc_evt_ring, gsi_alloc_evt_ring, gsi_write_channel_scratch, gsi_enable_flow_control_ee, gsi_write_channel_scratch2_reg, gsi_write_device_scratch, gsi_halt_channel_ee, gsi_reset_evt_ring, gsi_set_channel_cfg, gsi_enable_ipc_low, gsi_get_channel_cfg, gsi_read_wdi3_channel_scratch2_reg, gsi_stop_channel, gsi_query_flow_control_state_ee, gsi_reset_channel, gsi_get_evt_ring_cfg, gsi_dealloc_channel, gsi_stop_db_channel, gsi_alloc_channel_ee, gsi_start_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001380f8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [msm_gsi_probe, gsi_alloc_channel, gsi_alloc_channel_ee, gsi_alloc_evt_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00138100 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [gsi_halt_channel_ee, gsi_reset_evt_ring, gsi_alloc_channel, gsi_flow_control_ee, gsi_dealloc_evt_ring, gsi_query_flow_control_state_ee, gsi_alloc_evt_ring, gsi_reset_channel, gsi_channel_state_change_wait, gsi_dealloc_channel, gsi_enable_flow_control_ee, gsi_stop_db_channel, gsi_alloc_channel_ee]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_zero_bit @ 00138108 size=1
// signature: undefined _find_first_zero_bit(void)
// callers: [gsi_alloc_evt_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_zero_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00138110 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_gsi_probe, gsi_alloc_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 00138120 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [gsi_alloc_channel, gsi_update_ch_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00138128 size=1
// signature: undefined devm_kfree(void)
// callers: [gsi_dealloc_channel, gsi_alloc_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00138130 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [gsi_channel_state_change_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00138138 size=1
// signature: undefined usleep_range_state(void)
// callers: [gsi_reset_channel, gsi_halt_channel_ee]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00138140 size=1
// signature: undefined ___ratelimit(void)
// callers: [gsi_queue_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00138148 size=1
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
// platform_driver_unregister @ 00138150 size=1
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
// trace_raw_output_prep @ 00138158 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00138160 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00138168 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_gsi_qtimer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_notice @ 00138170 size=1
// signature: undefined _dev_notice(void)
// callers: [__gsi_msi_write_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_notice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00138178 size=1
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
// log_post_read_mmio @ 00138180 size=1
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
// ipc_log_context_create @ 00138188 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [gsi_enable_ipc_low, msm_gsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00138190 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_gsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_va_md_register @ 00138198 size=1
// signature: undefined qcom_va_md_register(void)
// callers: [msm_gsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_va_md_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_va_md_add_region @ 001381a0 size=1
// signature: undefined qcom_va_md_add_region(void)
// callers: [qcom_va_md_gsi_notif_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_va_md_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001381b8 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [gsi_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001381c0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [gsi_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001381c8 size=1
// signature: undefined debugfs_remove(void)
// callers: [gsi_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001381d0 size=1
// signature: undefined __check_object_size(void)
// callers: [gsi_dump_ch, gsi_enable_dp_stats, gsi_dump_evt, gsi_dump_ch_scratch_info, gsi_set_max_elem_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001381e0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [gsi_dump_ch, gsi_enable_dp_stats, gsi_dump_evt, gsi_dump_ch_scratch_info, gsi_set_max_elem_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 001381e8 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [gsi_dump_ch, gsi_dump_evt, gsi_dump_ch_scratch_info, gsi_set_max_elem_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001381f0 size=1
// signature: undefined kstrtouint(void)
// callers: [gsi_dump_ch, gsi_dump_evt, gsi_dump_ch_scratch_info, gsi_set_max_elem_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint_from_user @ 00138200 size=1
// signature: undefined kstrtoint_from_user(void)
// callers: [gsi_dump_stats, gsi_rst_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00138208 size=1
// signature: undefined kstrtoint(void)
// callers: [gsi_enable_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00138210 size=1
// signature: undefined alloc_workqueue(void)
// callers: [gsi_enable_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00138218 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [gsi_enable_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00138220 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [gsi_enable_dp_stats, gsi_wq_print_dp_stats, gsi_wq_update_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 00138228 size=1
// signature: undefined __flush_workqueue(void)
// callers: [gsi_enable_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00138230 size=1
// signature: undefined destroy_workqueue(void)
// callers: [gsi_enable_dp_stats, gsi_print_dp_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtos8_from_user @ 00138238 size=1
// signature: undefined kstrtos8_from_user(void)
// callers: [gsi_enable_ipc_low]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtos8_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00138240 size=1
// signature: undefined scnprintf(void)
// callers: [gsi_read_gsi_hw_profiling_stats, gsi_read_gsi_fw_version]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00138248 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [gsi_read_gsi_hw_profiling_stats, gsi_read_gsi_fw_version]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00138260 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gsihal_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00138268 size=1
// signature: undefined kfree(void)
// callers: [gsihal_init, gsihal_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00138270 size=1
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
// log_post_write_mmio @ 00138278 size=1
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
// __warn_printk @ 00138280 size=1
// signature: undefined __warn_printk(void)
// callers: [gsireg_parse_dummy, gsireg_construct_dummy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



