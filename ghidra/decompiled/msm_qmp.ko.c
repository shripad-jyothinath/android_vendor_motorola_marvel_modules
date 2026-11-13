// Decompiled by Ghidra 12.2
// Program: msm_qmp.ko
// Image base: 00100000

//------------------------------------------------------------
// qmp_mbox_probe @ 001005e4 size=2476
// signature: undefined qmp_mbox_probe(void)
// callers: []
//------------------------------------------------------------

ulong qmp_mbox_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  undefined *puVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  long *plVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 *puVar20;
  long *plVar21;
  undefined4 local_c4;
  undefined8 local_c0;
  ulong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  lVar8 = param_1 + 0x10;
  local_68 = *(long *)(lVar7 + 0x638);
  puVar16 = *(undefined8 **)(param_1 + 0x2f8);
  plVar4 = (long *)devm_kmalloc(lVar8,0xa0,0xdc0);
  if (plVar4 == (long *)0x0) goto LAB_00100a2c;
  *(long **)(param_1 + 0xa8) = plVar4;
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
  iVar1 = __of_parse_phandle_with_args(puVar16,"qcom,qmp",0,0,0,&local_b8);
  if ((iVar1 == 0) && (local_b8 != 0)) {
    uVar5 = qmp_get(lVar8);
    plVar4[0x11] = uVar5;
    if (0xfffffffffffff000 < uVar5) {
      uVar5 = uVar5 & 0xffffffff;
      goto LAB_00100a30;
    }
    lVar7 = of_get_property(*(undefined8 *)(param_1 + 0x2f8),"label",0);
    plVar4[1] = lVar7;
    if (lVar7 == 0) {
      puVar11 = &DAT_00102c32;
      pcVar12 = "qmp_shim_init";
      goto LAB_00100ea4;
    }
    plVar21 = plVar4 + 2;
    plVar4[2] = (long)plVar21;
    plVar6 = plVar4 + 3;
    *plVar6 = (long)plVar21;
    *plVar4 = lVar8;
    puVar16 = (undefined8 *)devm_kmalloc(lVar8,0x238,0xdc0);
    if (puVar16 != (undefined8 *)0x0) {
      lVar8 = devm_kmalloc(*plVar4,0x1000,0xdc0);
      puVar16[0x1c] = lVar8;
      if (lVar8 != 0) {
        uVar2 = get_mbox_num_chans(*(undefined8 *)(param_1 + 0x2f8));
        lVar8 = *plVar4;
        *(bool *)(puVar16 + 0x17) = 1 < uVar2;
        lVar8 = devm_kmalloc(lVar8,(ulong)uVar2 * 0xf8,0xdc0);
        if (lVar8 != 0) {
          if (uVar2 != 0) {
            if ((uVar2 == 1) || ((int)(uVar2 - 1) < 0)) {
              uVar13 = 0;
            }
            else {
              uVar14 = 0;
              uVar13 = uVar2 & 0xfffffffe;
              do {
                iVar1 = uVar14 + 1;
                lVar7 = (long)(int)uVar14;
                uVar14 = uVar14 + 2;
                *(undefined8 **)(lVar8 + lVar7 * 0xf8 + 0xf0) = puVar16;
                *(undefined8 **)(lVar8 + (long)iVar1 * 0xf8 + 0xf0) = puVar16;
              } while (uVar13 != uVar14);
              if (uVar2 == uVar13) goto LAB_00100c04;
            }
            do {
              lVar7 = (long)(int)uVar13;
              uVar13 = uVar13 + 1;
              *(undefined8 **)(lVar8 + lVar7 * 0xf8 + 0xf0) = puVar16;
            } while (uVar2 != uVar13);
          }
LAB_00100c04:
          puVar16[2] = *plVar4;
          puVar16[3] = &qmp_mbox_shim_ops;
          puVar16[4] = lVar8;
          *(uint *)(puVar16 + 5) = uVar2;
          *(undefined2 *)((long)puVar16 + 0x2c) = 1;
          puVar16[7] = qmp_mbox_of_xlate;
          __mutex_init(puVar16 + 0x25,"&mbox->state_lock",&qmp_shim_init___key);
          *(undefined4 *)((long)puVar16 + 0xa4) = 0;
          puVar16[0x45] = plVar4;
          puVar16[0x1d] = 0xfffffffe0;
          puVar16[0x1e] = puVar16 + 0x1e;
          puVar16[0x1f] = puVar16 + 0x1e;
          puVar16[0x20] = qmp_shim_worker;
          uVar2 = mbox_controller_register(puVar16 + 2);
          if (uVar2 == 0) {
            plVar17 = plVar21;
            do {
              plVar17 = (long *)*plVar17;
              if (plVar17 == plVar21) {
                puVar15 = (undefined8 *)*plVar6;
                uVar5 = __list_add_valid(puVar16,puVar15,plVar21);
                if ((uVar5 & 1) == 0) goto LAB_00100ce8;
                goto LAB_00100cdc;
              }
            } while (*(int *)(puVar16 + 0x14) < (int)plVar17[0x14]);
            plVar6 = plVar17 + 1;
            puVar15 = (undefined8 *)*plVar6;
            uVar5 = __list_add_valid(puVar16,puVar15,plVar17);
            if ((uVar5 & 1) != 0) {
              plVar21 = plVar17;
LAB_00100cdc:
              *plVar6 = (long)puVar16;
              *puVar16 = plVar21;
              puVar16[1] = puVar15;
              *puVar15 = puVar16;
            }
LAB_00100ce8:
            lVar8 = ipc_log_context_create(2,plVar4[1],0);
            uVar5 = 0;
            *(undefined2 *)((long)plVar4 + 0x99) = 0;
            plVar4[0x12] = lVar8;
            goto LAB_00100a30;
          }
          puVar11 = &DAT_00102f95;
          pcVar12 = "qmp_shim_init";
LAB_00100ef4:
          uVar5 = (ulong)uVar2;
          _printk(puVar11,pcVar12,uVar5);
          goto LAB_00100a30;
        }
      }
    }
    goto LAB_00100a2c;
  }
  uVar18 = *(undefined8 *)(param_1 + 0x2f8);
  plVar21 = *(long **)(param_1 + 0xa8);
  lVar7 = of_get_property(uVar18,"label",0);
  plVar21[1] = lVar7;
  if (lVar7 == 0) {
    puVar11 = &DAT_00102c32;
LAB_00100e9c:
    pcVar12 = "qmp_edge_init";
LAB_00100ea4:
    _printk(puVar11,pcVar12);
    uVar5 = 0xffffffed;
    goto LAB_00100a30;
  }
  plVar21[2] = (long)(plVar21 + 2);
  plVar21[3] = (long)(plVar21 + 2);
  *plVar21 = lVar8;
  plVar6 = (long *)platform_get_resource_byname(param_1,0x200,"msgram");
  if (plVar6 == (long *)0x0) {
    local_c0 = local_c0 & 0xffffffff;
    local_b8 = 0;
    uVar2 = of_property_read_variable_u32_array(uVar18,"qcom,remote-pid",(long)&local_c0 + 4,1,0);
    if ((int)uVar2 < 0) {
      uVar5 = (ulong)uVar2;
      _printk(&DAT_00102d91,uVar5);
      goto LAB_00100a30;
    }
    uVar5 = qcom_smem_get(local_c0._4_4_,0x275,&local_b8);
    if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
      if ((int)uVar5 != 0) goto LAB_00100a30;
    }
    else {
      plVar21[4] = uVar5;
    }
  }
  else {
    lVar7 = devm_ioremap(lVar8,*plVar6,(plVar6[1] - *plVar6) + 1);
    plVar21[4] = lVar7;
    if (lVar7 == 0) {
      uVar5 = 0xfffffffb;
      goto LAB_00100a30;
    }
  }
  plVar21[9] = lVar8;
  *(undefined1 *)(plVar21 + 0xc) = 1;
  uVar9 = mbox_request_channel(plVar21 + 9,0);
  plVar21[0x10] = uVar9;
  if (uVar9 < 0xfffffffffffff001) {
LAB_001008d4:
    iVar1 = irq_of_parse_and_map(uVar18,0);
    *(int *)((long)plVar21 + 0x3c) = iVar1;
    if (iVar1 == 0) {
      puVar11 = &DAT_00102ef6;
      goto LAB_00100e9c;
    }
  }
  else {
    if (uVar9 == 0xffffffffffffffed) {
      plVar21[0x10] = 0;
      lVar7 = *(long *)(param_1 + 0xa8);
      uVar19 = *(undefined8 *)(param_1 + 0x2f8);
      plVar6 = (long *)platform_get_resource_byname(param_1,0x200,"irq-reg-base");
      if (plVar6 == (long *)0x0) {
        uVar5 = 0xffffffed;
        puVar11 = &DAT_00102db7;
      }
      else {
        iVar1 = of_property_read_variable_u32_array(uVar19,"qcom,irq-mask",lVar7 + 0x38,1,0);
        if (iVar1 < 0) {
          uVar5 = 0xffffffed;
          puVar11 = &DAT_00103089;
        }
        else {
          lVar10 = devm_ioremap(lVar8,*plVar6,(plVar6[1] - *plVar6) + 1);
          *(long *)(lVar7 + 0x28) = lVar10;
          if (lVar10 != 0) goto LAB_001008d4;
          uVar5 = 0xfffffffb;
          puVar11 = &DAT_00102dd7;
        }
      }
      _printk(puVar11,"qmp_parse_ipc");
      goto LAB_00100a30;
    }
    uVar5 = uVar9 & 0xffffffff;
    if ((int)uVar9 != 0) goto LAB_00100a30;
  }
  local_b8 = local_b8 & 0xffffffff00000000;
  local_c0 = 0;
  local_c4 = 0;
  iVar1 = of_property_read_variable_u32_array(puVar16,"mbox-desc-offset",&local_c0,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001030aa,"qmp_mbox_init","mbox-desc-offset");
  }
  else {
    iVar1 = of_property_read_variable_u32_array(puVar16,"priority",&local_c4,1,0);
    if (-1 < iVar1) {
      puVar15 = (undefined8 *)devm_kmalloc(*plVar4,0x238,0xdc0);
      if (puVar15 != (undefined8 *)0x0) {
        iVar1 = of_property_read_variable_u32_array(puVar16,"mbox-offset",&local_b8,1,0);
        if (-1 < iVar1) {
          *(undefined4 *)(puVar15 + 0x18) = (undefined4)local_b8;
        }
        iVar1 = of_property_read_variable_u32_array(puVar16,"mbox-size",(long)&local_c0 + 4,1,0);
        if (-1 < iVar1) {
          *(undefined4 *)((long)puVar15 + 0xc4) = local_c0._4_4_;
        }
        lVar7 = plVar4[4];
        puVar15[0x45] = plVar4;
        *(undefined4 *)(puVar15 + 0x14) = local_c4;
        puVar15[0x16] = lVar7 + (local_c0 & 0xffffffff);
        uVar2 = get_mbox_num_chans(puVar16);
        lVar7 = *plVar4;
        *(bool *)(puVar15 + 0x17) = 1 < uVar2;
        lVar7 = devm_kmalloc(lVar7,(ulong)uVar2 * 0xf8,0xdc0);
        if (lVar7 != 0) {
          if (uVar2 != 0) {
            if ((uVar2 == 1) || ((int)(uVar2 - 1) < 0)) {
              uVar13 = 0;
            }
            else {
              uVar14 = 0;
              uVar13 = uVar2 & 0xfffffffe;
              do {
                iVar1 = uVar14 + 1;
                lVar10 = (long)(int)uVar14;
                uVar14 = uVar14 + 2;
                *(undefined8 **)(lVar7 + lVar10 * 0xf8 + 0xf0) = puVar15;
                *(undefined8 **)(lVar7 + (long)iVar1 * 0xf8 + 0xf0) = puVar15;
              } while (uVar13 != uVar14);
              if (uVar2 == uVar13) goto LAB_00100a88;
            }
            do {
              lVar10 = (long)(int)uVar13;
              uVar13 = uVar13 + 1;
              *(undefined8 **)(lVar7 + lVar10 * 0xf8 + 0xf0) = puVar15;
            } while (uVar2 != uVar13);
          }
LAB_00100a88:
          puVar15[2] = *plVar4;
          puVar15[3] = &qmp_mbox_ops;
          puVar15[4] = lVar7;
          *(uint *)(puVar15 + 5) = uVar2;
          *(undefined2 *)((long)puVar15 + 0x2c) = 1;
          puVar15[7] = qmp_mbox_of_xlate;
          uVar2 = mbox_controller_register(puVar15 + 2);
          if (uVar2 != 0) {
            puVar11 = &DAT_00102f44;
            pcVar12 = "qmp_mbox_init";
            goto LAB_00100ef4;
          }
          *(undefined4 *)(puVar15 + 0x2b) = 0;
          __mutex_init(puVar15 + 0x25,"&mbox->state_lock",&qmp_mbox_init___key);
          *(undefined4 *)(puVar15 + 0x24) = 0;
          *(undefined4 *)(puVar15 + 0x2c) = 0;
          __init_swait_queue_head(puVar15 + 0x2d,"&x->wait",&init_completion___key);
          *(undefined4 *)(puVar15 + 0x30) = 0;
          __init_swait_queue_head(puVar15 + 0x31,"&x->wait",&init_completion___key);
          puVar15[0x34] = 0xfffffffe0;
          *(undefined1 *)((long)puVar15 + 0xb9) = 0;
          *(undefined4 *)((long)puVar15 + 0xa4) = 0;
          puVar15[0x35] = puVar15 + 0x35;
          puVar15[0x36] = puVar15 + 0x35;
          puVar15[0x37] = qmp_notify_timeout;
          init_timer_key(puVar15 + 0x3a,&delayed_work_timer_fn,0x200000,0,0);
          plVar21 = plVar4 + 2;
          *(undefined1 *)(puVar15 + 0x46) = 0;
          *(undefined2 *)((long)plVar4 + 0x99) = 0;
          plVar6 = plVar21;
          do {
            plVar6 = (long *)*plVar6;
            if (plVar6 == plVar21) {
              plVar17 = plVar4 + 3;
              puVar20 = (undefined8 *)*plVar17;
              uVar5 = __list_add_valid(puVar15,puVar20,plVar21);
              if ((uVar5 & 1) != 0) goto LAB_00100bcc;
              goto LAB_00100d58;
            }
          } while (*(int *)(puVar15 + 0x14) < (int)plVar6[0x14]);
          plVar17 = plVar6 + 1;
          puVar20 = (undefined8 *)*plVar17;
          uVar5 = __list_add_valid(puVar15,puVar20,plVar6);
          plVar21 = plVar6;
          if ((uVar5 & 1) != 0) {
LAB_00100bcc:
            *plVar17 = (long)puVar15;
            *puVar15 = plVar21;
            puVar15[1] = puVar20;
            *puVar20 = puVar15;
          }
          goto LAB_00100d58;
        }
      }
LAB_00100a2c:
      uVar5 = 0xfffffff4;
      goto LAB_00100a30;
    }
    _printk(&DAT_001030aa,"qmp_mbox_init","priority");
  }
LAB_00100d58:
  lVar7 = plVar4[1];
  *(long **)(param_1 + 0xa8) = plVar4;
  lVar7 = ipc_log_context_create(2,lVar7,0);
  plVar4[0x12] = lVar7;
  uVar2 = devm_request_threaded_irq
                    (lVar8,*(undefined4 *)((long)plVar4 + 0x3c),qmp_irq_handler,
                     qmp_thread_irq_handler,1,*puVar16,plVar4);
  if ((int)uVar2 < 0) {
    uVar5 = (ulong)uVar2;
    qmp_mbox_remove(param_1);
    iVar1 = ___ratelimit(qmp_mbox_probe__rs,"qmp_mbox_probe");
    if (iVar1 != 0) {
      _printk("%s[%s]: request threaded irq on %d failed: %d\n",&DAT_00102cbc,"qmp_mbox_probe",
              *(undefined4 *)((long)plVar4 + 0x3c),uVar5);
    }
    ipc_log_string(plVar4[0x12],"%s[%s]: request threaded irq on %d failed: %d\n",&DAT_00102d90,
                   "qmp_mbox_probe",*(undefined4 *)((long)plVar4 + 0x3c),uVar5);
  }
  else {
    iVar1 = irq_set_irq_wake(*(undefined4 *)((long)plVar4 + 0x3c),1);
    if (iVar1 < 0) {
      iVar3 = ___ratelimit(qmp_mbox_probe__rs_5,"qmp_mbox_probe");
      if (iVar3 != 0) {
        _printk("%s[%s]: enable_irq_wake on %d failed: %d\n",&DAT_00102cbc,"qmp_mbox_probe",
                *(undefined4 *)((long)plVar4 + 0x3c),iVar1);
      }
      ipc_log_string(plVar4[0x12],"%s[%s]: enable_irq_wake on %d failed: %d\n",&DAT_00102d90,
                     "qmp_mbox_probe",*(undefined4 *)((long)plVar4 + 0x3c),iVar1);
    }
    lVar8 = of_find_property(puVar16,"qcom,early-boot",0);
    if (lVar8 == 0) {
      uVar5 = 0;
    }
    else {
      for (plVar21 = (long *)plVar4[2]; plVar21 != plVar4 + 2; plVar21 = (long *)*plVar21) {
        __qmp_rx_worker(plVar21);
      }
      uVar5 = 0;
      *(undefined1 *)(plVar4 + 0x13) = 1;
    }
  }
LAB_00100a30:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// qmp_mbox_remove @ 00100f94 size=88
// signature: undefined qmp_mbox_remove(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

undefined8 qmp_mbox_remove(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  disable_irq(*(undefined4 *)(lVar1 + 0x3c));
  plVar2 = (long *)(lVar1 + 0x10);
  for (plVar3 = (long *)*plVar2; plVar3 != plVar2; plVar3 = (long *)*plVar3) {
    mbox_controller_unregister(plVar3 + 2);
    kfree(plVar3[0x1a]);
  }
  return 0;
}



//------------------------------------------------------------
// qmp_irq_handler @ 00100ff0 size=92
// signature: undefined qmp_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_irq_handler(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_2 + 0x99) == '\0') || (*(char *)(param_2 + 0x98) == '\0')) {
    if (*(long *)(param_2 + 0x30) != 0) {
      writel_relaxed(*(undefined4 *)(param_2 + 0x38));
    }
    uVar1 = 2;
    *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qmp_thread_irq_handler @ 00101050 size=72
// signature: undefined qmp_thread_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_thread_irq_handler(undefined8 param_1,long param_2)

{
  long *plVar1;
  
  for (plVar1 = *(long **)(param_2 + 0x10); plVar1 != (long *)(param_2 + 0x10);
      plVar1 = (long *)*plVar1) {
    __qmp_rx_worker(plVar1);
  }
  return 1;
}



//------------------------------------------------------------
// __qmp_rx_worker @ 00101098 size=1788
// signature: undefined __qmp_rx_worker(void)
// callers: [qmp_mbox_restore, qmp_mbox_probe, qmp_thread_irq_handler]
//------------------------------------------------------------

void __qmp_rx_worker(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x228);
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  __memcpy_fromio(&local_98,*(undefined8 *)(param_1 + 0xb0),0x40);
  if ((int)local_98 != 0x4d41494c) goto LAB_001016bc;
  mutex_lock(param_1 + 0x128);
  switch(*(undefined4 *)(param_1 + 0x120)) {
  case 0:
    *(undefined4 *)(param_1 + 0x118) = local_98._4_4_;
    *(undefined4 *)(param_1 + 0x11c) = (undefined4)uStack_90;
    writel(uStack_90._4_4_,*(long *)(param_1 + 0xb0) + 0x10);
    if (local_68._4_4_ == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0xc0);
      iVar2 = *(int *)(param_1 + 0xc4);
    }
    else {
      *(undefined4 *)(param_1 + 0xc0) = (undefined4)local_60;
      *(int *)(param_1 + 0xc4) = local_68._4_4_;
      iVar2 = local_68._4_4_;
      uVar5 = (undefined4)local_60;
    }
    lVar7 = *(long *)(param_1 + 0xb0);
    writel(0xffff,lVar7 + 0x24);
    writel(0xffff0000,lVar7 + 0x28);
    writel(0xffff0000,lVar7 + 0x2c);
    writel(0xffff0000,lVar7 + 0x30);
    writel(iVar2,lVar7 + 0x34);
    writel(uVar5,lVar7 + 0x38);
    *(undefined4 *)(param_1 + 0x120) = 1;
    lVar7 = __kmalloc(uStack_80._4_4_,0xdc0);
    *(long *)(param_1 + 0xd0) = lVar7;
    if (lVar7 == 0) {
      iVar2 = ___ratelimit(__qmp_rx_worker__rs,"__qmp_rx_worker");
      if (iVar2 != 0) {
        _printk("%s[%s]: Failed to allocate rx pkt\n",&DAT_00102cbc,"__qmp_rx_worker");
      }
      uVar3 = *(undefined8 *)(lVar6 + 0x90);
      pcVar4 = "%s[%s]: Failed to allocate rx pkt\n";
      goto LAB_001014e8;
    }
    ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: Set to link negotiation\n","__qmp_rx_worker"
                  );
    DataSynchronizationBarrier(3,2,0);
    if (*(long *)(lVar6 + 0x80) == 0) {
      writel_relaxed(*(undefined4 *)(lVar6 + 0x38),*(undefined8 *)(lVar6 + 0x28));
    }
    else {
      mbox_send_message(*(long *)(lVar6 + 0x80),0);
      mbox_client_txdone(*(undefined8 *)(lVar6 + 0x80),0);
    }
    *(int *)(lVar6 + 0x40) = *(int *)(lVar6 + 0x40) + 1;
    break;
  case 1:
    if (((int)local_70 != 0xffff) || (local_78._4_4_ != 0xffff)) {
      iVar2 = ___ratelimit(__qmp_rx_worker__rs_39,"__qmp_rx_worker");
      if (iVar2 != 0) {
        _printk("%s[%s]: RX int without negotiation ack\n",&DAT_00102cbc,"__qmp_rx_worker");
      }
      uVar3 = *(undefined8 *)(lVar6 + 0x90);
      pcVar4 = "%s[%s]: RX int without negotiation ack\n";
      goto LAB_001014e8;
    }
    *(undefined4 *)(param_1 + 0x120) = 2;
    complete_all(param_1 + 0x160);
    ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: Set to link connected\n","__qmp_rx_worker");
    if (*(char *)(param_1 + 0x230) != '\0') {
      writel(0xffff,*(long *)(param_1 + 0xb0) + 0x2c);
      *(undefined4 *)(param_1 + 0x120) = 3;
      send_irq(*(undefined8 *)(param_1 + 0x228));
    }
    break;
  case 2:
    if (local_88._4_4_ == (int)uStack_80) {
      iVar2 = ___ratelimit(__qmp_rx_worker__rs_42,"__qmp_rx_worker");
      if (iVar2 != 0) {
        _printk("%s[%s]: RX int without ch open\n",&DAT_00102cbc,"__qmp_rx_worker");
      }
      uVar3 = *(undefined8 *)(lVar6 + 0x90);
      pcVar4 = "%s[%s]: RX int without ch open\n";
      goto LAB_001014e8;
    }
    writel(local_88._4_4_,*(long *)(param_1 + 0xb0) + 0x18);
    DataSynchronizationBarrier(3,2,0);
    if (*(long *)(lVar6 + 0x80) == 0) {
      writel_relaxed(*(undefined4 *)(lVar6 + 0x38),*(undefined8 *)(lVar6 + 0x28));
    }
    else {
      mbox_send_message(*(long *)(lVar6 + 0x80),0);
      mbox_client_txdone(*(undefined8 *)(lVar6 + 0x80),0);
    }
    pcVar4 = "[%s]: Received remote ch open\n";
    uVar3 = *(undefined8 *)(lVar6 + 0x90);
    *(int *)(lVar6 + 0x40) = *(int *)(lVar6 + 0x40) + 1;
LAB_001015d8:
    ipc_log_string(uVar3,pcVar4,"__qmp_rx_worker");
    break;
  case 3:
    if (((int)local_68 == 0xffff) && (local_70._4_4_ == 0xffff)) {
      *(undefined4 *)(param_1 + 0x120) = 4;
      ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: Received local ch open ack\n",
                     "__qmp_rx_worker");
    }
    if (local_88._4_4_ != (int)uStack_80) {
      writel(local_88._4_4_,*(long *)(param_1 + 0xb0) + 0x18);
      DataSynchronizationBarrier(3,2,0);
      if (*(long *)(lVar6 + 0x80) == 0) {
        writel_relaxed(*(undefined4 *)(lVar6 + 0x38),*(undefined8 *)(lVar6 + 0x28));
      }
      else {
        mbox_send_message(*(long *)(lVar6 + 0x80),0);
        mbox_client_txdone(*(undefined8 *)(lVar6 + 0x80),0);
      }
      *(int *)(lVar6 + 0x40) = *(int *)(lVar6 + 0x40) + 1;
      ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: Received remote channel open\n",
                     "__qmp_rx_worker");
    }
    if (((*(int *)(param_1 + 0x120) == 4) && (local_70._4_4_ == 0xffff)) &&
       (local_88._4_4_ == 0xffff)) {
      *(undefined4 *)(param_1 + 0x120) = 5;
LAB_001015c8:
      complete_all(param_1 + 0x180);
      uVar3 = *(undefined8 *)(lVar6 + 0x90);
      pcVar4 = "[%s]: Set to channel connected\n";
      goto LAB_001015d8;
    }
    break;
  case 4:
    if (local_88._4_4_ != (int)uStack_80) {
      writel(local_88._4_4_,*(long *)(param_1 + 0xb0) + 0x18);
      *(undefined4 *)(param_1 + 0x120) = 5;
      DataSynchronizationBarrier(3,2,0);
      if (*(long *)(lVar6 + 0x80) == 0) {
        writel_relaxed(*(undefined4 *)(lVar6 + 0x38),*(undefined8 *)(lVar6 + 0x28));
      }
      else {
        mbox_send_message(*(long *)(lVar6 + 0x80),0);
        mbox_client_txdone(*(undefined8 *)(lVar6 + 0x80),0);
      }
      *(int *)(lVar6 + 0x40) = *(int *)(lVar6 + 0x40) + 1;
      goto LAB_001015c8;
    }
    iVar2 = ___ratelimit(__qmp_rx_worker__rs_48,"__qmp_rx_worker");
    if (iVar2 != 0) {
      _printk("%s[%s]: RX int without remote ch open\n",&DAT_00102cbc,"__qmp_rx_worker");
    }
    uVar3 = *(undefined8 *)(lVar6 + 0x90);
    pcVar4 = "%s[%s]: RX int without remote ch open\n";
    goto LAB_001014e8;
  case 5:
    if (local_88._4_4_ == -0x10000) {
      writel(0xffff0000,*(long *)(param_1 + 0xb0) + 0x18);
      *(undefined4 *)(param_1 + 0x120) = 4;
      ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: REMOTE DISCONNECT\n","__qmp_rx_worker");
      DataSynchronizationBarrier(3,2,0);
      if (*(long *)(lVar6 + 0x80) == 0) {
        writel_relaxed(*(undefined4 *)(lVar6 + 0x38),*(undefined8 *)(lVar6 + 0x28));
      }
      else {
        mbox_send_message(*(long *)(lVar6 + 0x80),0);
        mbox_client_txdone(*(undefined8 *)(lVar6 + 0x80),0);
      }
      *(int *)(lVar6 + 0x40) = *(int *)(lVar6 + 0x40) + 1;
    }
    iVar2 = readl(*(long *)(param_1 + 0xb0) + (local_78 & 0xffffffff));
    if ((iVar2 != 0) && (*(char *)(param_1 + 0xb8) == '\0')) {
      qmp_recv_data(param_1,local_78 & 0xffffffff);
    }
    lVar7 = param_1 + 0x158;
    uVar3 = _raw_spin_lock_irqsave(lVar7);
    if (*(char *)(param_1 + 0xb9) != '\0') {
      uVar1 = *(uint *)(param_1 + 0xbc);
      iVar2 = readl(*(long *)(param_1 + 0xb0) + (ulong)*(uint *)(param_1 + 0xc0));
      if (iVar2 == 0) {
        *(undefined1 *)(param_1 + 0xb9) = 0;
        cancel_delayed_work(param_1 + 0x1a0);
        ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: TX flag cleared, idx%d\n",
                       "__qmp_rx_worker",uVar1);
        _raw_spin_unlock_irqrestore(lVar7,uVar3);
        mbox_chan_txdone(*(long *)(param_1 + 0x20) + (ulong)uVar1 * 0xf8,0);
        uVar3 = _raw_spin_lock_irqsave(lVar7);
      }
    }
    _raw_spin_unlock_irqrestore(lVar7,uVar3);
    break;
  case 6:
    if (((int)local_68 == -0x10000) && (local_70._4_4_ == -0x10000)) {
      *(undefined4 *)(param_1 + 0x120) = 2;
      ipc_log_string(*(undefined8 *)(lVar6 + 0x90),"[%s]: Channel closed\n","__qmp_rx_worker");
      *(undefined4 *)(param_1 + 0x180) = 0;
    }
    break;
  default:
    iVar2 = ___ratelimit(__qmp_rx_worker__rs_53,"__qmp_rx_worker");
    if (iVar2 != 0) {
      _printk("%s[%s]: Local Channel State corrupted\n",&DAT_00102cbc,"__qmp_rx_worker");
    }
    uVar3 = *(undefined8 *)(lVar6 + 0x90);
    pcVar4 = "%s[%s]: Local Channel State corrupted\n";
LAB_001014e8:
    ipc_log_string(uVar3,pcVar4,&DAT_00102d90,"__qmp_rx_worker");
  }
  mutex_unlock(param_1 + 0x128);
LAB_001016bc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// get_mbox_num_chans @ 00101794 size=316
// signature: undefined get_mbox_num_chans(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

int get_mbox_num_chans(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  long local_a8 [11];
  
  lVar3 = sp_el0;
  local_a8[10] = *(long *)(lVar3 + 0x638);
  local_a8[8] = 0;
  local_a8[9] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  lVar3 = of_find_node_with_property(0,"mboxes");
  if (lVar3 != 0) {
    iVar5 = 0;
    do {
      uVar4 = of_device_is_available(lVar3);
      if (((uVar4 & 1) != 0) &&
         (iVar1 = of_count_phandle_with_args(lVar3,"mboxes","#mbox-cells"), 0 < iVar1)) {
        iVar6 = 0;
        do {
          iVar2 = __of_parse_phandle_with_args
                            (lVar3,"mboxes","#mbox-cells",0xffffffff,iVar6,local_a8);
          if ((iVar2 == 0) && (local_a8[0] == param_1)) {
            iVar5 = iVar5 + 1;
            break;
          }
          iVar6 = iVar6 + 1;
        } while (iVar1 != iVar6);
      }
      lVar3 = of_find_node_with_property(lVar3,"mboxes");
    } while (lVar3 != 0);
    if (iVar5 != 0) goto LAB_00101894;
  }
  iVar5 = 1;
LAB_00101894:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qmp_mbox_of_xlate @ 001018d4 size=144
// signature: undefined qmp_mbox_of_xlate(void)
// callers: []
//------------------------------------------------------------

long qmp_mbox_of_xlate(long param_1)

{
  long lVar1;
  
  if ((*(uint *)(param_1 + 0x94) < *(uint *)(param_1 + 0x18)) && (*(long *)(param_1 + 0x10) != 0)) {
    mutex_lock(param_1 + 0x118);
    lVar1 = *(long *)(param_1 + 0x10) + (ulong)*(uint *)(param_1 + 0x94) * 0xf8;
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) + 1;
    mutex_unlock(param_1 + 0x118);
  }
  else {
    _printk(&DAT_00102d4c,"qmp_mbox_of_xlate");
    lVar1 = -0xc;
  }
  return lVar1;
}



//------------------------------------------------------------
// qmp_shim_worker @ 00101968 size=84
// signature: undefined qmp_shim_worker(void)
// callers: []
//------------------------------------------------------------

void qmp_shim_worker(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = qmp_send(*(undefined8 *)(*(long *)(param_1 + 0x140) + 0x88),*(undefined8 *)(param_1 + -8),
                   *(undefined4 *)(param_1 + -0x10));
  mbox_chan_txdone(*(long *)(param_1 + -200) + (ulong)*(uint *)(param_1 + -0x2c) * 0xf8,uVar1);
  return;
}



//------------------------------------------------------------
// qmp_shim_send_data @ 001019c0 size=208
// signature: undefined qmp_shim_send_data(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qmp_shim_send_data(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xf0);
  if (lVar4 != 0) {
    if (param_2 == (uint *)0x0) {
      return 0xffffffea;
    }
    lVar2 = *(long *)(lVar4 + 0x228);
    if (lVar2 == 0) {
      return 0xffffffea;
    }
    if ((*(char *)(lVar2 + 0x99) != '\0') || (*(char *)(lVar2 + 0x9a) != '\0')) {
      return 0xfffffffa;
    }
    uVar1 = *param_2;
    if (uVar1 < 0x1001) {
      if (0 < (int)*(uint *)(lVar4 + 0x28)) {
        uVar3 = 0;
        lVar2 = *(long *)(lVar4 + 0x20) + -0xf8;
        do {
          lVar2 = lVar2 + 0xf8;
          if (lVar2 == param_1) {
            *(int *)(lVar4 + 0xbc) = (int)uVar3;
            uVar1 = *param_2;
            break;
          }
          uVar3 = uVar3 + 1;
        } while (*(uint *)(lVar4 + 0x28) != uVar3);
      }
      *(uint *)(lVar4 + 0xd8) = uVar1;
      memcpy(*(void **)(lVar4 + 0xe0),*(void **)(param_2 + 2),(ulong)*param_2);
      queue_work_on(0x20,_system_highpri_wq,lVar4 + 0xe8);
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// qmp_shim_startup @ 00101a94 size=44
// signature: undefined qmp_shim_startup(void)
// callers: []
//------------------------------------------------------------

undefined4 qmp_shim_startup(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  if ((*(long *)(param_1 + 0xf0) == 0) ||
     (lVar2 = *(long *)(*(long *)(param_1 + 0xf0) + 0x228), lVar2 == 0)) {
    return 0xffffffea;
  }
  uVar1 = 0xfffffff5;
  if (*(long *)(lVar2 + 0x88) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qmp_shim_shutdown @ 00101ac4 size=4
// signature: undefined qmp_shim_shutdown(void)
// callers: []
//------------------------------------------------------------

void qmp_shim_shutdown(void)

{
  return;
}



//------------------------------------------------------------
// qmp_last_tx_done @ 00101acc size=48
// signature: undefined qmp_last_tx_done(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_last_tx_done(void)

{
  _printk(&DAT_00103148,"qmp_last_tx_done");
  return 1;
}



//------------------------------------------------------------
// qmp_notify_timeout @ 00101b00 size=260
// signature: undefined qmp_notify_timeout(void)
// callers: []
//------------------------------------------------------------

void qmp_notify_timeout(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = param_1 + -0x48;
  uVar1 = *(uint *)(param_1 + -0xe4);
  lVar5 = *(long *)(param_1 + -0x180);
  uVar3 = _raw_spin_lock_irqsave(lVar4);
  if (*(char *)(param_1 + -0xe7) == '\0') {
    _raw_spin_unlock_irqrestore(lVar4,uVar3);
  }
  else {
    iVar2 = ___ratelimit(qmp_notify_timeout__rs,"qmp_notify_timeout");
    if (iVar2 != 0) {
      _printk("%s[%s]: tx timeout for %d\n",&DAT_00102cbc,"qmp_notify_timeout",
              *(undefined4 *)(param_1 + -0xe4));
    }
    ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x88) + 0x90),"%s[%s]: tx timeout for %d\n",
                   &DAT_00102d90,"qmp_notify_timeout",*(undefined4 *)(param_1 + -0xe4));
    writel(0,*(long *)(param_1 + -0xf0) + (ulong)*(uint *)(param_1 + -0xe0));
    *(undefined1 *)(param_1 + -0xe7) = 0;
    _raw_spin_unlock_irqrestore(lVar4,uVar3);
    mbox_chan_txdone(lVar5 + (ulong)uVar1 * 0xf8,0xffffffc2);
  }
  return;
}



//------------------------------------------------------------
// qmp_send_data @ 00101c08 size=372
// signature: undefined qmp_send_data(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qmp_send_data(long param_1,uint *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  uVar6 = 0xffffffea;
  if (((param_2 != (uint *)0x0) && (lVar8 = *(long *)(param_1 + 0xf0), lVar8 != 0)) &&
     (uVar2 = completion_done(lVar8 + 0x180), (uVar2 & 1) != 0)) {
    lVar7 = *(long *)(lVar8 + 0x228);
    if ((*(char *)(lVar7 + 0x99) == '\0') && (*(char *)(lVar7 + 0x9a) == '\0')) {
      uVar3 = _raw_spin_lock_irqsave(lVar8 + 0x158);
      if (*(char *)(lVar8 + 0xb9) == '\0') {
        if ((ulong)*(uint *)(lVar8 + 0xc4) < (ulong)*param_2 + 4) {
          uVar6 = 0xffffffea;
        }
        else {
          lVar4 = *(long *)(lVar8 + 0xb0) + (ulong)*(uint *)(lVar8 + 0xc0);
          memcpy32_toio(lVar4 + 4,*(undefined8 *)(param_2 + 2));
          writel(*param_2,lVar4);
          uVar1 = readl(lVar4);
          *(undefined1 *)(lVar8 + 0xb9) = 1;
          if (0 < *(int *)(lVar8 + 0x28)) {
            lVar4 = 0;
            lVar5 = *(long *)(lVar8 + 0x20);
            do {
              if (lVar5 == param_1) {
                *(int *)(lVar8 + 0xbc) = (int)lVar4;
              }
              lVar4 = lVar4 + 1;
              lVar5 = lVar5 + 0xf8;
            } while (lVar4 < *(int *)(lVar8 + 0x28));
          }
          ipc_log_string(*(undefined8 *)(lVar7 + 0x90),"[%s]: Copied buffer to msgram sz:%d i:%d\n",
                         "qmp_send_data",uVar1,*(undefined4 *)(lVar8 + 0xbc));
          send_irq(lVar7);
          queue_delayed_work_on(0x20,_system_wq,lVar8 + 0x1a0,0xfa);
          uVar6 = 0;
        }
      }
      else {
        uVar6 = 0xfffffff5;
      }
      _raw_spin_unlock_irqrestore(lVar8 + 0x158,uVar3);
    }
    else {
      uVar6 = 0xfffffffa;
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// qmp_startup @ 00101d80 size=224
// signature: undefined qmp_startup(void)
// callers: []
//------------------------------------------------------------

undefined4 qmp_startup(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xf0);
  if (lVar3 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    lVar1 = wait_for_completion_timeout(lVar3 + 0x160,0x4e2);
    if (lVar1 == 0) {
      uVar2 = 0xfffffff5;
    }
    else {
      mutex_lock(lVar3 + 0x128);
      if (*(int *)(lVar3 + 0x120) == 2) {
        writel(0xffff,*(long *)(lVar3 + 0xb0) + 0x2c);
        lVar1 = *(long *)(lVar3 + 0x228);
        *(undefined4 *)(lVar3 + 0x120) = 3;
        DataSynchronizationBarrier(3,2,0);
        if (*(long *)(lVar1 + 0x80) == 0) {
          writel_relaxed(*(undefined4 *)(lVar1 + 0x38),*(undefined8 *)(lVar1 + 0x28));
        }
        else {
          mbox_send_message(*(long *)(lVar1 + 0x80),0);
          mbox_client_txdone(*(undefined8 *)(lVar1 + 0x80),0);
        }
        *(int *)(lVar1 + 0x40) = *(int *)(lVar1 + 0x40) + 1;
      }
      mutex_unlock(lVar3 + 0x128);
      lVar3 = wait_for_completion_timeout(lVar3 + 0x180,0x4e2);
      uVar2 = 0xffffffc2;
      if (lVar3 != 0) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// qmp_shutdown @ 00101e64 size=236
// signature: undefined qmp_shutdown(void)
// callers: []
//------------------------------------------------------------

void qmp_shutdown(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0xf0);
  mutex_lock(lVar2 + 0x128);
  if (*(uint *)(lVar2 + 0x120) < 3) {
    *(int *)(lVar2 + 0xa4) = *(int *)(lVar2 + 0xa4) + -1;
  }
  else if (*(uint *)(lVar2 + 0x120) == 3) {
    *(undefined4 *)(lVar2 + 0x120) = 2;
    *(int *)(lVar2 + 0xa4) = *(int *)(lVar2 + 0xa4) + -1;
  }
  else {
    uVar1 = *(int *)(lVar2 + 0xa8) + 1;
    *(uint *)(lVar2 + 0xa8) = uVar1;
    if (*(uint *)(lVar2 + 0xa4) <= uVar1) {
      *(undefined4 *)(lVar2 + 0x120) = 6;
      writel(0xffff0000,*(long *)(lVar2 + 0xb0) + 0x2c);
      lVar3 = *(long *)(lVar2 + 0x228);
      DataSynchronizationBarrier(3,2,0);
      if (*(long *)(lVar3 + 0x80) == 0) {
        writel_relaxed(*(undefined4 *)(lVar3 + 0x38),*(undefined8 *)(lVar3 + 0x28));
      }
      else {
        mbox_send_message(*(long *)(lVar3 + 0x80),0);
        mbox_client_txdone(*(undefined8 *)(lVar3 + 0x80),0);
      }
      *(int *)(lVar3 + 0x40) = *(int *)(lVar3 + 0x40) + 1;
      *(undefined8 *)(lVar2 + 0xa4) = 0;
    }
  }
  mutex_unlock(lVar2 + 0x128);
  return;
}



//------------------------------------------------------------
// memcpy32_toio @ 00101f50 size=96
// signature: undefined memcpy32_toio(void)
// callers: [qmp_send_data]
//------------------------------------------------------------

void memcpy32_toio(long param_1,undefined4 *param_2,ulong param_3)

{
  code *pcVar1;
  
  if ((param_3 & 3) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x101fb0);
    (*pcVar1)();
  }
  if (3 < param_3) {
    param_3 = param_3 >> 2;
    do {
      param_3 = param_3 - 1;
      writel(*param_2,param_1);
      param_1 = param_1 + 4;
      param_2 = param_2 + 1;
    } while (param_3 != 0);
  }
  return;
}



//------------------------------------------------------------
// send_irq @ 00101fbc size=96
// signature: undefined send_irq(void)
// callers: [qmp_send_data, __qmp_rx_worker]
//------------------------------------------------------------

void send_irq(long param_1)

{
  DataSynchronizationBarrier(3,2,0);
  if (*(long *)(param_1 + 0x80) == 0) {
    writel_relaxed(*(undefined4 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x28));
  }
  else {
    mbox_send_message(*(long *)(param_1 + 0x80),0);
    mbox_client_txdone(*(undefined8 *)(param_1 + 0x80),0);
  }
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  return;
}



//------------------------------------------------------------
// writel @ 0010201c size=136
// signature: undefined writel(void)
// callers: [memcpy32_toio, qmp_recv_data, qmp_send_data, __qmp_rx_worker, qmp_notify_timeout, qmp_shutdown, qmp_startup]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102034,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102074,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 001020a4 size=140
// signature: undefined readl(void)
// callers: [qmp_recv_data, qmp_send_data, __qmp_rx_worker]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1020fc,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00102130 size=132
// signature: undefined writel_relaxed(void)
// callers: [qmp_irq_handler, qmp_recv_data, send_irq, __qmp_rx_worker, qmp_shutdown, qmp_startup]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102148,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102184,uVar1);
  return;
}



//------------------------------------------------------------
// qmp_recv_data @ 001021b4 size=368
// signature: undefined qmp_recv_data(void)
// callers: [__qmp_rx_worker]
//------------------------------------------------------------

void qmp_recv_data(long param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined4 *puVar6;
  ulong uVar7;
  
  lVar5 = *(long *)(param_1 + 0xb0) + (param_2 & 0xffffffff);
  iVar2 = readl(lVar5);
  uVar1 = iVar2 + 3U & 0xfffffffc;
  *(int *)(param_1 + 200) = iVar2;
  if (*(uint *)(param_1 + 0xc4) < uVar1) {
    iVar2 = ___ratelimit(qmp_recv_data__rs,"qmp_recv_data");
    if (iVar2 != 0) {
      _printk("%s[%s]: Invalid mailbox packet\n",&DAT_00102cbc,"qmp_recv_data");
    }
    ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x228) + 0x90),
                   "%s[%s]: Invalid mailbox packet\n",&DAT_00102d90,"qmp_recv_data");
  }
  else {
    if (uVar1 != 0) {
      uVar7 = (ulong)(iVar2 + 3U >> 2);
      puVar6 = *(undefined4 **)(param_1 + 0xd0);
      lVar4 = lVar5;
      do {
        lVar4 = lVar4 + 4;
        uVar7 = uVar7 - 1;
        uVar3 = readl(lVar4);
        *puVar6 = uVar3;
        puVar6 = puVar6 + 1;
      } while (uVar7 != 0);
    }
    mbox_chan_received_data
              (*(long *)(param_1 + 0x20) + (ulong)*(uint *)(param_1 + 0xbc) * 0xf8,
               (int *)(param_1 + 200));
  }
  writel(0,lVar5);
  ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x228) + 0x90),"[%s]: recv sz:%d\n",
                 "qmp_recv_data",*(undefined4 *)(param_1 + 200));
  lVar5 = *(long *)(param_1 + 0x228);
  DataSynchronizationBarrier(3,2,0);
  if (*(long *)(lVar5 + 0x80) == 0) {
    writel_relaxed(*(undefined4 *)(lVar5 + 0x38),*(undefined8 *)(lVar5 + 0x28));
  }
  else {
    mbox_send_message(*(long *)(lVar5 + 0x80),0);
    mbox_client_txdone(*(undefined8 *)(lVar5 + 0x80),0);
  }
  *(int *)(lVar5 + 0x40) = *(int *)(lVar5 + 0x40) + 1;
  return;
}



//------------------------------------------------------------
// qmp_mbox_resume_early @ 00102328 size=76
// signature: undefined qmp_mbox_resume_early(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_mbox_resume_early(undefined8 param_1)

{
  if ((pm_suspend_global_flags & 1) != 0) {
    qmp_mbox_restore();
    _dev_info(param_1,"QMP: Deep sleep exit\n");
  }
  return 0;
}



//------------------------------------------------------------
// qmp_mbox_freeze @ 00102378 size=52
// signature: undefined qmp_mbox_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_mbox_freeze(long param_1)

{
  *(undefined1 *)(*(long *)(param_1 + 0x98) + 0x99) = 1;
  _dev_info(param_1,"QMP: Hibernate entry\n");
  return 0;
}



//------------------------------------------------------------
// qmp_mbox_restore @ 001023b0 size=352
// signature: undefined qmp_mbox_restore(void)
// callers: [qmp_mbox_resume_early]
//------------------------------------------------------------

undefined8 qmp_mbox_restore(long param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  long local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
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
  iVar1 = __of_parse_phandle_with_args(*(undefined8 *)(param_1 + 0x2e8),"qcom,qmp",0,0,0,&local_a8);
  if ((iVar1 != 0) || (local_a8 == 0)) {
    for (plVar2 = *(long **)(lVar3 + 0x10); plVar2 != (long *)(lVar3 + 0x10);
        plVar2 = (long *)*plVar2) {
      *(undefined4 *)(plVar2 + 0x24) = 0;
      *(undefined4 *)(plVar2 + 0x2c) = 0;
      __init_swait_queue_head(plVar2 + 0x2d,"&x->wait",&init_completion___key);
      *(undefined4 *)(plVar2 + 0x30) = 0;
      __init_swait_queue_head(plVar2 + 0x31,"&x->wait",&init_completion___key);
      *(undefined1 *)((long)plVar2 + 0xb9) = 0;
      *(undefined1 *)(plVar2 + 0x46) = 1;
      kfree(plVar2[0x1a]);
      plVar2[0x1a] = 0;
      if (*(char *)(lVar3 + 0x98) != '\0') {
        __qmp_rx_worker(plVar2);
      }
    }
  }
  if (*(char *)(lVar3 + 0x99) != '\0') {
    *(undefined1 *)(lVar3 + 0x99) = 0;
  }
  _dev_info(param_1,"QMP: Hibernate exit\n");
  if (*(char *)(lVar3 + 0x9a) != '\0') {
    *(undefined1 *)(lVar3 + 0x9a) = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qmp_mbox_suspend_noirq @ 00102514 size=68
// signature: undefined qmp_mbox_suspend_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_mbox_suspend_noirq(long param_1)

{
  if ((pm_suspend_global_flags & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x98) + 0x9a) = 1;
    _dev_info(param_1,"QMP: Deep sleep entry\n");
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102560 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qmp_mbox_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102590 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qmp_mbox_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00105000 size=1
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
// platform_driver_unregister @ 00105008 size=1
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
// devm_kmalloc @ 00105010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00105018 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qmp_mbox_restore, get_mbox_num_chans, qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_get @ 00105020 size=1
// signature: undefined qmp_get(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00105028 size=1
// signature: undefined of_get_property(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00105030 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00105038 size=1
// signature: undefined devm_ioremap(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105040 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00105048 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 00105050 size=1
// signature: undefined mbox_request_channel(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_of_parse_and_map @ 00105058 size=1
// signature: undefined irq_of_parse_and_map(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_of_parse_and_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_controller_register @ 00105060 size=1
// signature: undefined mbox_controller_register(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105068 size=1
// signature: undefined __mutex_init(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00105070 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qmp_mbox_restore, qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00105080 size=1
// signature: undefined init_timer_key(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105088 size=1
// signature: undefined __list_add_valid(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00105090 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105098 size=1
// signature: undefined _printk(void)
// callers: [qmp_recv_data, qmp_last_tx_done, qmp_mbox_probe, __qmp_rx_worker, qmp_notify_timeout, qmp_mbox_of_xlate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001050a0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001050a8 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001050b0 size=1
// signature: undefined ___ratelimit(void)
// callers: [qmp_recv_data, qmp_mbox_probe, __qmp_rx_worker, qmp_notify_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001050b8 size=1
// signature: undefined ipc_log_string(void)
// callers: [qmp_recv_data, qmp_send_data, qmp_mbox_probe, __qmp_rx_worker, qmp_notify_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001050c0 size=1
// signature: undefined of_find_property(void)
// callers: [qmp_mbox_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050c8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qmp_mbox_restore, get_mbox_num_chans, qmp_mbox_probe, __qmp_rx_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001050d0 size=1
// signature: undefined disable_irq(void)
// callers: [qmp_mbox_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_controller_unregister @ 001050d8 size=1
// signature: undefined mbox_controller_unregister(void)
// callers: [qmp_mbox_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_controller_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050e0 size=1
// signature: undefined kfree(void)
// callers: [qmp_mbox_restore, qmp_mbox_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 001050e8 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [__qmp_rx_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001050f0 size=1
// signature: undefined mutex_lock(void)
// callers: [__qmp_rx_worker, qmp_shutdown, qmp_mbox_of_xlate, qmp_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 001050f8 size=1
// signature: undefined mbox_send_message(void)
// callers: [qmp_recv_data, send_irq, __qmp_rx_worker, qmp_shutdown, qmp_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_client_txdone @ 00105100 size=1
// signature: undefined mbox_client_txdone(void)
// callers: [qmp_recv_data, send_irq, __qmp_rx_worker, qmp_shutdown, qmp_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_client_txdone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00105108 size=1
// signature: undefined complete_all(void)
// callers: [__qmp_rx_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105110 size=1
// signature: undefined __kmalloc(void)
// callers: [__qmp_rx_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00105118 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qmp_send_data, __qmp_rx_worker, qmp_notify_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00105120 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [__qmp_rx_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00105128 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qmp_send_data, __qmp_rx_worker, qmp_notify_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_chan_txdone @ 00105130 size=1
// signature: undefined mbox_chan_txdone(void)
// callers: [qmp_shim_worker, __qmp_rx_worker, qmp_notify_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_chan_txdone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105138 size=1
// signature: undefined mutex_unlock(void)
// callers: [__qmp_rx_worker, qmp_shutdown, qmp_mbox_of_xlate, qmp_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_with_property @ 00105140 size=1
// signature: undefined of_find_node_with_property(void)
// callers: [get_mbox_num_chans]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_with_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00105148 size=1
// signature: undefined of_device_is_available(void)
// callers: [get_mbox_num_chans]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00105150 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [get_mbox_num_chans]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_send @ 00105158 size=1
// signature: undefined qmp_send(void)
// callers: [qmp_shim_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105160 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qmp_shim_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105170 size=1
// signature: undefined queue_work_on(void)
// callers: [qmp_shim_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// completion_done @ 00105178 size=1
// signature: undefined completion_done(void)
// callers: [qmp_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00105188 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [qmp_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00105190 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [qmp_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00105198 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 001051a0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001051a8 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 001051b0 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_chan_received_data @ 001051b8 size=1
// signature: undefined mbox_chan_received_data(void)
// callers: [qmp_recv_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_chan_received_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001051c8 size=1
// signature: undefined _dev_info(void)
// callers: [qmp_mbox_restore, qmp_mbox_freeze, qmp_mbox_suspend_noirq, qmp_mbox_resume_early]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



