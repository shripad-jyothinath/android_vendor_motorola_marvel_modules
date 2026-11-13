// Decompiled by Ghidra 12.2
// Program: smp2p.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_smp2p_probe @ 0010049c size=1452
// signature: undefined qcom_smp2p_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_smp2p_probe(long param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  size_t __n;
  char *pcVar11;
  long lVar12;
  undefined8 *puVar13;
  long *plVar14;
  long *plVar15;
  char *pcVar16;
  ulong uVar17;
  long lVar18;
  long local_b8;
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
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  if (ilc == 0) {
    ilc = ipc_log_context_create(2,"smp2p",0);
  }
  lVar8 = param_1 + 0x10;
  plVar5 = (long *)devm_kmalloc(lVar8,0xb0,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar17 = 0xfffffff4;
    goto LAB_0010099c;
  }
  plVar14 = plVar5 + 0x12;
  plVar1 = plVar5 + 0x14;
  *plVar5 = lVar8;
  plVar5[0x12] = (long)plVar14;
  plVar5[0x13] = (long)plVar14;
  plVar5[0x14] = (long)plVar1;
  plVar5[0x15] = (long)plVar1;
  *(long **)(param_1 + 0xa8) = plVar5;
  uVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,smem",plVar5 + 3,2,0);
  uVar4 = uVar2;
  if (-1 < (int)uVar2) {
    uVar4 = 0;
  }
  uVar17 = (ulong)uVar4;
  if ((int)uVar2 < 0) goto LAB_0010099c;
  pcVar16 = "qcom,local-pid";
  iVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,local-pid",plVar5 + 6,1,0);
  if (iVar3 < 0) {
LAB_00100678:
    pcVar11 = "failed to read %s\n";
  }
  else {
    pcVar16 = "qcom,remote-pid";
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,remote-pid",(long)plVar5 + 0x34,1,0);
    if (iVar3 < 0) goto LAB_00100678;
    uVar6 = platform_get_irq(param_1,0);
    uVar17 = uVar6 & 0xffffffff;
    if ((int)uVar6 < 0) goto LAB_0010099c;
    plVar5[10] = lVar8;
    *(undefined1 *)(plVar5 + 0xd) = 1;
    uVar17 = mbox_request_channel(plVar5 + 10,0);
    plVar5[0x11] = uVar17;
    if (uVar17 < 0xfffffffffffff001) goto LAB_001006cc;
    if ((0x14 < uVar17 + 0x16) || ((1L << (uVar17 + 0x16 & 0x3f) & 0x100009U) == 0))
    goto LAB_0010099c;
    lVar18 = *plVar5;
    plVar5[0x11] = 0;
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
    iVar3 = __of_parse_phandle_with_args(*(undefined8 *)(lVar18 + 0x2e8),"qcom,ipc",0,0,0,&local_b8)
    ;
    if ((iVar3 != 0) || (local_b8 == 0)) {
      _dev_err(lVar18,"no qcom,ipc node\n");
      uVar17 = 0xffffffed;
      goto LAB_0010099c;
    }
    uVar7 = syscon_node_to_regmap();
    plVar5[8] = uVar7;
    if (0xfffffffffffff000 < uVar7) {
      uVar17 = uVar7 & 0xffffffff;
      if ((int)uVar7 != 0) goto LAB_0010099c;
LAB_001006cc:
      uVar4 = qcom_smp2p_alloc_outbound_item(plVar5);
      if ((int)uVar4 < 0) {
        uVar17 = (ulong)uVar4;
      }
      else {
        lVar18 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),0);
        if (lVar18 != 0) {
          do {
            plVar9 = (long *)kmalloc_trace(_memcpy,0xdc0,0x68);
            if (plVar9 == (long *)0x0) goto LAB_00100920;
            plVar9[2] = (long)plVar5;
            *(undefined4 *)(plVar9 + 0xc) = 0;
            uVar4 = of_property_read_string(lVar18,"qcom,entry-name",plVar9 + 3);
            if ((int)uVar4 < 0) {
              uVar17 = (ulong)uVar4;
              goto LAB_0010092c;
            }
            lVar10 = of_find_property(lVar18,"interrupt-controller",0);
            if (lVar10 == 0) {
              pcVar16 = (char *)plVar9[3];
              local_b8 = 0;
              local_b0 = 0;
              lVar10 = plVar5[2];
              __n = strlen(pcVar16);
              if (0xe < __n) {
                __n = 0xf;
              }
              memcpy(&local_b8,pcVar16,__n);
              *(undefined1 *)((long)&local_b8 + __n) = 0;
              lVar12 = lVar10 + (ulong)*(ushort *)(lVar10 + 0xe) * 0x14;
              *(long *)(lVar12 + 0x14) = local_b8;
              *(undefined8 *)(lVar12 + 0x1c) = local_b0;
              plVar9[4] = lVar12 + 0x24;
              *(short *)(lVar10 + 0xe) = *(short *)(lVar10 + 0xe) + 1;
              uVar17 = qcom_smem_state_register(lVar18,&smp2p_state_ops,plVar9);
              plVar9[0xb] = uVar17;
              if (0xfffffffffffff000 < uVar17) {
                _dev_err(*plVar5,"failed to register qcom_smem_state\n");
                uVar17 = plVar9[0xb];
                if ((int)uVar17 < 0) goto LAB_0010092c;
              }
              lVar10 = *plVar1;
              uVar17 = __list_add_valid(plVar9,plVar1,lVar10);
              plVar15 = plVar1;
            }
            else {
              lVar10 = __irq_domain_add(lVar18 + 0x18,0x20,0x20,0,smp2p_irq_ops,plVar9);
              plVar9[6] = lVar10;
              if (lVar10 == 0) {
                _dev_err(*plVar5,"failed to add irq_domain\n");
                uVar17 = 0xfffffff4;
                goto LAB_0010092c;
              }
              lVar10 = *plVar14;
              uVar17 = __list_add_valid(plVar9,plVar14,lVar10);
              plVar15 = plVar14;
            }
            if ((uVar17 & 1) != 0) {
              *(long **)(lVar10 + 8) = plVar9;
              *plVar9 = lVar10;
              plVar9[1] = (long)plVar15;
              *plVar15 = (long)plVar9;
            }
            lVar18 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),lVar18);
          } while (lVar18 != 0);
        }
        qcom_smp2p_start_in(plVar5);
        qcom_smp2p_kick(plVar5);
        puVar13 = *(undefined8 **)(param_1 + 0x2f8);
        *(int *)(plVar5 + 7) = (int)uVar6;
        lVar18 = kasprintf(0xcc0,&DAT_0010221f,*puVar13);
        plVar5[5] = lVar18;
        if (lVar18 == 0) {
LAB_00100920:
          uVar17 = 0xfffffff4;
        }
        else {
          uVar4 = devm_request_threaded_irq
                            (lVar8,uVar6 & 0xffffffff,0,qcom_smp2p_intr,0x2000,lVar18,plVar5);
          if (uVar4 == 0) {
            device_set_wakeup_capable(lVar8,1);
            uVar6 = dev_pm_set_wake_irq(lVar8,uVar6 & 0xffffffff);
            uVar17 = uVar6 & 0xffffffff;
            if ((int)uVar6 == 0) goto LAB_0010099c;
            dev_pm_clear_wake_irq(lVar8);
          }
          else {
            uVar17 = (ulong)uVar4;
            _dev_err(lVar8,"failed to request interrupt\n");
          }
        }
LAB_0010092c:
        plVar9 = (long *)*plVar14;
        while (plVar9 != plVar14) {
          plVar15 = (long *)*plVar9;
          irq_domain_remove(plVar9[6]);
          kfree(plVar9);
          plVar9 = plVar15;
        }
        plVar14 = (long *)*plVar1;
        while (plVar14 != plVar1) {
          plVar9 = (long *)*plVar14;
          qcom_smem_state_unregister(plVar14[0xb]);
          kfree(plVar14);
          plVar14 = plVar9;
        }
        kfree(plVar5[5]);
        *(undefined2 *)(plVar5[2] + 0xe) = 0;
      }
      mbox_free_channel(plVar5[0x11]);
      goto LAB_0010099c;
    }
    iVar3 = of_property_read_u32_index(*(undefined8 *)(lVar18 + 0x2e8),"qcom,ipc",1,plVar5 + 9);
    if (iVar3 < 0) {
      pcVar11 = "no offset in %s\n";
    }
    else {
      iVar3 = of_property_read_u32_index
                        (*(undefined8 *)(lVar18 + 0x2e8),"qcom,ipc",2,(long)plVar5 + 0x4c);
      if (-1 < iVar3) goto LAB_001006cc;
      pcVar11 = "no bit in %s\n";
    }
    pcVar16 = "qcom,ipc";
    lVar8 = lVar18;
  }
  _dev_err(lVar8,pcVar11,pcVar16);
  uVar17 = 0xffffffea;
LAB_0010099c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_smp2p_remove @ 00100a4c size=180
// signature: undefined qcom_smp2p_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smp2p_remove(long param_1)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  dev_pm_clear_wake_irq(param_1 + 0x10);
  plVar1 = (long *)*(long *)(lVar2 + 0x90);
  while (plVar1 != (long *)(lVar2 + 0x90)) {
    plVar3 = (long *)*plVar1;
    irq_domain_remove(plVar1[6]);
    kfree(plVar1);
    plVar1 = plVar3;
  }
  plVar1 = (long *)*(long *)(lVar2 + 0xa0);
  while (plVar1 != (long *)(lVar2 + 0xa0)) {
    plVar3 = (long *)*plVar1;
    qcom_smem_state_unregister(plVar1[0xb]);
    kfree(plVar1);
    plVar1 = plVar3;
  }
  mbox_free_channel(*(undefined8 *)(lVar2 + 0x88));
  kfree(*(undefined8 *)(lVar2 + 0x28));
  *(undefined2 *)(*(long *)(lVar2 + 0x10) + 0xe) = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_smp2p_alloc_outbound_item @ 00100b00 size=404
// signature: undefined qcom_smp2p_alloc_outbound_item(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

ulong qcom_smp2p_alloc_outbound_item(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  char cVar6;
  undefined4 *puVar7;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar1 = *(undefined4 *)((long)param_1 + 0x1c);
  uVar2 = *(undefined4 *)((long)param_1 + 0x34);
  uVar5 = qcom_smem_alloc(uVar2,uVar1,0x154);
  iVar4 = (int)uVar5;
  if ((iVar4 < 0) && (puVar7 = (undefined4 *)(uVar5 & 0xffffffff), iVar4 != -0x11)) {
    if (iVar4 == -0x205) {
      puVar7 = (undefined4 *)0xfffffdfb;
    }
    else {
      _dev_err(*param_1,"unable to allocate local smp2p item\n");
    }
    goto LAB_00100c38;
  }
  puVar7 = (undefined4 *)qcom_smem_get(uVar2,uVar1,0);
  if ((undefined4 *)0xfffffffffffff000 < puVar7) {
    _dev_err(*param_1,"Unable to acquire local smp2p item\n");
    goto LAB_00100c38;
  }
  memset(puVar7 + 1,0,0x150);
  *puVar7 = 0x504d5324;
  *(short *)(puVar7 + 2) = (short)*(undefined4 *)(param_1 + 6);
  uVar1 = *(undefined4 *)((long)param_1 + 0x34);
  puVar7[3] = 0x10;
  *(undefined1 *)((long)puVar7 + 7) = 0;
  *(undefined2 *)((long)puVar7 + 5) = 1;
  *(short *)((long)puVar7 + 10) = (short)uVar1;
  local_40 = 0;
  uVar5 = qcom_smem_get(*(undefined4 *)((long)param_1 + 0x34),*(undefined4 *)(param_1 + 3),&local_40
                       );
  if (uVar5 < 0xfffffffffffff001) {
    cVar6 = *(char *)(uVar5 + 4);
    DataSynchronizationBarrier(3,2,0);
    if (cVar6 == '\0') goto LAB_00100bf0;
  }
  else {
    DataSynchronizationBarrier(3,2,0);
LAB_00100bf0:
    cVar6 = '\x01';
  }
  *(char *)(puVar7 + 1) = cVar6;
  DataSynchronizationBarrier(3,2,0);
  if (param_1[0x11] == 0) {
    regmap_write(param_1[8],*(undefined4 *)(param_1 + 9),
                 1L << ((ulong)*(uint *)((long)param_1 + 0x4c) & 0x3f));
  }
  else {
    mbox_send_message(param_1[0x11],0);
    mbox_client_txdone(param_1[0x11],0);
  }
  param_1[2] = puVar7;
  puVar7 = (undefined4 *)0x0;
LAB_00100c38:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar7 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_smp2p_start_in @ 00100c94 size=272
// signature: undefined qcom_smp2p_start_in(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

void qcom_smp2p_start_in(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  uVar4 = qcom_smem_get(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x18),&local_70);
  if ((uVar4 < 0xfffffffffffff001) &&
     (*(ulong *)(param_1 + 8) = uVar4, *(char *)(uVar4 + 4) != '\0')) {
    uVar1 = *(uint *)(param_1 + 0x20);
    uVar6 = (ulong)uVar1;
    uVar7 = (ulong)*(ushort *)(uVar4 + 0xe);
    if ((int)uVar1 < (int)(uint)*(ushort *)(uVar4 + 0xe)) {
      uVar6 = (ulong)(int)uVar1;
      do {
        lVar5 = uVar4 + uVar6 * 0x14;
        plVar8 = (long *)(param_1 + 0x90);
        do {
          plVar8 = (long *)*plVar8;
          if (plVar8 == (long *)(param_1 + 0x90)) goto LAB_00100d10;
          local_68 = *(undefined8 *)(lVar5 + 0x14);
          uStack_60 = *(undefined8 *)(lVar5 + 0x1c);
          iVar2 = strcmp((char *)&local_68,(char *)plVar8[3]);
        } while (iVar2 != 0);
        plVar8[4] = uVar4 + uVar6 * 0x14 + 0x24;
        uVar3 = readl();
        *(undefined4 *)(plVar8 + 5) = uVar3;
        uVar7 = (ulong)*(ushort *)(uVar4 + 0xe);
LAB_00100d10:
        uVar6 = uVar6 + 1;
      } while ((long)uVar6 < (long)uVar7);
    }
    *(int *)(param_1 + 0x20) = (int)uVar6;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_smp2p_kick @ 00100da4 size=92
// signature: undefined qcom_smp2p_kick(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

void qcom_smp2p_kick(long param_1)

{
  DataSynchronizationBarrier(3,2,0);
  if (*(long *)(param_1 + 0x88) == 0) {
    regmap_write(*(undefined8 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x48),
                 1L << ((ulong)*(uint *)(param_1 + 0x4c) & 0x3f));
  }
  else {
    mbox_send_message(*(long *)(param_1 + 0x88),0);
    mbox_client_txdone(*(undefined8 *)(param_1 + 0x88),0);
  }
  return;
}



//------------------------------------------------------------
// qcom_smp2p_intr @ 00100e04 size=1136
// signature: undefined qcom_smp2p_intr(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smp2p_intr(undefined8 param_1,undefined8 *param_2)

{
  ulong *puVar1;
  undefined4 uVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  bool bVar6;
  uint3 uVar7;
  bool bVar8;
  undefined8 uVar9;
  int iVar10;
  uint uVar11;
  undefined1 uVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  undefined8 *puVar16;
  ulong uVar17;
  ulong uVar18;
  long *plVar19;
  undefined8 *puVar20;
  undefined8 local_88;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_88 = 0;
  uVar17 = param_2[1];
  if (uVar17 == 0) {
    uVar17 = qcom_smem_get(*(undefined4 *)((long)param_2 + 0x34),*(undefined4 *)(param_2 + 3),
                           &local_88);
    if (0xfffffffffffff000 < uVar17) {
      _dev_err(*param_2,"Unable to acquire remote smp2p item\n");
      goto LAB_0010122c;
    }
    param_2[1] = uVar17;
  }
  if (*(char *)((long)param_2 + 0x26) == '\0') {
    lVar14 = param_2[2];
    ipc_log_string(ilc,"[%s]: %d: version[%d:%d]\n","qcom_smp2p_negotiate",
                   *(undefined4 *)((long)param_2 + 0x34),*(undefined1 *)(uVar17 + 4),
                   *(undefined1 *)(lVar14 + 4));
    if (*(char *)(uVar17 + 4) == *(char *)(lVar14 + 4)) {
      uVar7 = *(uint3 *)(lVar14 + 5) & *(uint3 *)(uVar17 + 5);
      *(short *)(lVar14 + 5) = (short)uVar7;
      *(char *)(lVar14 + 7) = (char)(uVar7 >> 0x10);
      if ((uVar7 & 1) == 0) {
        uVar12 = *(undefined1 *)((long)param_2 + 0x24);
      }
      else {
        uVar12 = 1;
        *(undefined1 *)((long)param_2 + 0x24) = 1;
      }
      uVar9 = ilc;
      *(undefined1 *)((long)param_2 + 0x26) = 1;
      ipc_log_string(uVar9,"[%s]: %d: state=open ssr_ack=%d\n","qcom_smp2p_negotiate",
                     *(undefined4 *)((long)param_2 + 0x34),uVar12);
    }
    if (*(char *)((long)param_2 + 0x26) == '\0') goto LAB_0010122c;
    uVar17 = param_2[1];
    if (*(char *)((long)param_2 + 0x24) != '\0') goto LAB_00100f28;
LAB_00100f3c:
    bVar8 = false;
  }
  else {
    if (*(char *)((long)param_2 + 0x24) == '\0') goto LAB_00100f3c;
LAB_00100f28:
    if ((*(uint *)(uVar17 + 0x10) & 1) == (uint)*(byte *)((long)param_2 + 0x25)) goto LAB_00100f3c;
    if (1 < *(byte *)(uVar17 + 4)) {
      puVar20 = param_2 + 0x12;
      puVar16 = (undefined8 *)*puVar20;
      if (puVar16 != puVar20) {
        do {
          if (puVar16[4] != 0) {
            *(undefined4 *)(puVar16 + 5) = 0;
          }
          puVar16 = (undefined8 *)*puVar16;
        } while (puVar16 != puVar20);
        uVar17 = param_2[1];
      }
    }
    bVar8 = true;
  }
  uVar3 = *(uint *)(param_2 + 4);
  uVar13 = (ulong)uVar3;
  uVar18 = (ulong)*(ushort *)(uVar17 + 0xe);
  if ((int)uVar3 < (int)(uint)*(ushort *)(uVar17 + 0xe)) {
    uVar13 = (ulong)(int)uVar3;
    do {
      lVar14 = uVar17 + uVar13 * 0x14;
      puVar20 = param_2 + 0x12;
      do {
        puVar20 = (undefined8 *)*puVar20;
        if (puVar20 == param_2 + 0x12) goto LAB_00100fac;
        local_78 = *(undefined8 *)(lVar14 + 0x14);
        uStack_70 = *(undefined8 *)(lVar14 + 0x1c);
        iVar10 = strcmp((char *)&local_78,(char *)puVar20[3]);
      } while (iVar10 != 0);
      puVar20[4] = uVar17 + uVar13 * 0x14 + 0x24;
      uVar18 = (ulong)*(ushort *)(uVar17 + 0xe);
LAB_00100fac:
      uVar13 = uVar13 + 1;
    } while ((long)uVar13 < (long)uVar18);
    uVar13 = uVar13 & 0xffffffff;
  }
  *(int *)(param_2 + 4) = (int)uVar13;
  ipc_log_string(ilc,"[%s]: %d: smp2p_num:%d in_num:%d\n","qcom_smp2p_notify_in",
                 *(undefined4 *)((long)param_2 + 0x34),uVar13,*(undefined2 *)(uVar17 + 0xe));
  for (plVar19 = (long *)param_2[0x12]; plVar19 != param_2 + 0x12; plVar19 = (long *)*plVar19) {
    if (plVar19[4] == 0) {
      ipc_log_string(ilc,"[%s]: %d:\t%s: skipping not ready\n","qcom_smp2p_notify_in",
                     *(undefined4 *)((long)param_2 + 0x34),plVar19[3]);
    }
    else {
      uVar11 = readl();
      uVar3 = *(uint *)(plVar19 + 5);
      *(uint *)(plVar19 + 5) = uVar11;
      DataSynchronizationBarrier(3,3,0);
      uVar17 = plVar19[8];
      uVar13 = uVar17 | uVar3 ^ uVar11;
      ipc_log_string(ilc,"[%s]: %d:\t%s: status:%0lx val:%0x\n","qcom_smp2p_notify_in",
                     *(undefined4 *)((long)param_2 + 0x34),plVar19[3],uVar13,uVar11);
      if (uVar13 != 0) {
        if (smp2p_suspend_in_progress == '\x01') {
          _printk(&DAT_00102150,param_2[5],plVar19[3],uVar13);
          smp2p_suspend_in_progress = '\0';
        }
        uVar13 = 0;
        do {
          uVar13 = (uVar17 & 0xffffffff | (ulong)(uVar3 ^ uVar11)) & -1L << (uVar13 & 0x3f);
          uVar18 = (uVar13 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar13 & 0x5555555555555555) << 1;
          uVar18 = (uVar18 & 0xcccccccccccccccc) >> 2 | (uVar18 & 0x3333333333333333) << 2;
          uVar18 = (uVar18 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar15 = (uVar18 & 0xff00ff00ff00ff00) >> 8 | (uVar18 & 0xff00ff00ff00ff) << 8;
          uVar18 = 0x20;
          if (uVar13 != 0) {
            uVar18 = LZCOUNT((uVar15 >> 0x10 | (uVar15 & 0xffff0000ffff) << 0x10) << 0x20);
          }
          if (0x1f < uVar18) break;
          uVar13 = 1L << (uVar18 & 0x3f);
          if ((uVar13 & uVar11) == 0) {
            uVar15 = plVar19[10];
          }
          else {
            uVar15 = plVar19[9];
          }
          if ((uVar15 & uVar13) != 0) {
            local_7c = 0;
            lVar14 = __irq_resolve_mapping(plVar19[6],uVar18,&local_7c);
            uVar2 = 0;
            if (lVar14 != 0) {
              uVar2 = local_7c;
            }
            handle_nested_irq(uVar2);
            puVar1 = (ulong *)(plVar19 + 8);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar5 = '\x01';
              bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar6) {
                *puVar1 = *puVar1 & (uVar13 ^ 0xffffffffffffffff);
                cVar5 = ExclusiveMonitorsStatus();
              }
            } while (cVar5 != '\0');
          }
          uVar13 = uVar18 + 1;
        } while (uVar18 < 0x1f);
      }
    }
  }
  if (bVar8) {
    lVar14 = param_2[2];
    ipc_log_string(ilc,"[%s]: %d: SSR detected, doing SSR Handshake\n","qcom_smp2p_do_ssr_ack",
                   *(undefined4 *)((long)param_2 + 0x34));
    bVar4 = *(byte *)((long)param_2 + 0x25);
    *(byte *)((long)param_2 + 0x25) = bVar4 ^ 1;
    uVar3 = *(uint *)(lVar14 + 0x10);
    *(uint *)(lVar14 + 0x10) = uVar3 & 0xfffffffc | uVar3 & 1 | (uint)(bVar4 == 0) << 1;
    DataSynchronizationBarrier(3,2,0);
    if (param_2[0x11] == 0) {
      regmap_write(param_2[8],*(undefined4 *)(param_2 + 9),
                   1L << ((ulong)*(uint *)((long)param_2 + 0x4c) & 0x3f));
    }
    else {
      mbox_send_message(param_2[0x11],0);
      mbox_client_txdone(param_2[0x11],0);
    }
  }
LAB_0010122c:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// smp2p_irq_map @ 00101284 size=148
// signature: undefined smp2p_irq_map(void)
// callers: []
//------------------------------------------------------------

undefined8 smp2p_irq_map(long param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x20);
  irq_set_chip_and_handler_name(param_2,&smp2p_irq_chip,&handle_level_irq,0);
  irq_set_chip_data(param_2,lVar1);
  irq_modify_status(param_2,0,0x8000);
  irq_modify_status(param_2,0,0x400);
  irq_set_parent(param_2,*(undefined4 *)(*(long *)(lVar1 + 0x10) + 0x38));
  irq_modify_status(param_2,0,0x80000);
  return 0;
}



//------------------------------------------------------------
// smp2p_mask_irq @ 0010131c size=56
// signature: undefined smp2p_mask_irq(void)
// callers: []
//------------------------------------------------------------

void smp2p_mask_irq(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  
  uVar4 = *(ulong *)(param_1 + 8);
  puVar1 = (ulong *)(*(long *)(param_1 + 0x30) + 0x38 + (uVar4 >> 6 & 0x3ffffff) * 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 & (1L << (uVar4 & 0x3f) ^ 0xffffffffffffffffU);
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// smp2p_unmask_irq @ 00101364 size=56
// signature: undefined smp2p_unmask_irq(void)
// callers: []
//------------------------------------------------------------

void smp2p_unmask_irq(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  
  uVar4 = *(ulong *)(param_1 + 8);
  puVar1 = (ulong *)(*(long *)(param_1 + 0x30) + 0x38 + (uVar4 >> 6 & 0x3ffffff) * 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 1L << (uVar4 & 0x3f);
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// smp2p_retrigger_irq @ 001013ac size=136
// signature: undefined smp2p_retrigger_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 smp2p_retrigger_irq(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x30);
  uVar4 = *(ulong *)(param_1 + 8);
  ipc_log_string(ilc,"[%s]: %d: %s: %lu\n","smp2p_retrigger_irq",
                 *(undefined4 *)(*(long *)(lVar5 + 0x10) + 0x34),*(undefined8 *)(lVar5 + 0x18),uVar4
                );
  puVar1 = (ulong *)(lVar5 + 0x40 + (uVar4 >> 6 & 0x3ffffff) * 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 1L << (uVar4 & 0x3f);
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataSynchronizationBarrier(3,3,0);
  return 0;
}



//------------------------------------------------------------
// smp2p_set_irq_type @ 00101440 size=196
// signature: undefined smp2p_set_irq_type(void)
// callers: []
//------------------------------------------------------------

undefined8 smp2p_set_irq_type(long param_1,uint param_2)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  
  if ((param_2 & 3) == 0) {
    return 0xffffffea;
  }
  lVar7 = *(long *)(param_1 + 0x30);
  uVar6 = *(ulong *)(param_1 + 8);
  lVar1 = lVar7 + 0x48;
  uVar5 = uVar6 >> 6 & 0x3ffffff;
  uVar8 = 1L << (uVar6 & 0x3f);
  if ((param_2 & 1) == 0) {
    puVar2 = (ulong *)(lVar1 + uVar5 * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & (uVar8 ^ 0xffffffffffffffff);
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  else {
    puVar2 = (ulong *)(lVar1 + uVar5 * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 | uVar8;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  lVar7 = lVar7 + 0x50;
  uVar6 = 1L << (uVar6 & 0x3f);
  if ((param_2 >> 1 & 1) == 0) {
    puVar2 = (ulong *)(lVar7 + uVar5 * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & (uVar6 ^ 0xffffffffffffffff);
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    return 0;
  }
  puVar2 = (ulong *)(lVar7 + uVar5 * 8);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar4) {
      *puVar2 = *puVar2 | uVar6;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  return 0;
}



//------------------------------------------------------------
// smp2p_irq_get_irqchip_state @ 0010153c size=104
// signature: undefined smp2p_irq_get_irqchip_state(void)
// callers: []
//------------------------------------------------------------

undefined8 smp2p_irq_get_irqchip_state(long param_1,int param_2,byte *param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  
  if (param_2 == 3) {
    if (*(long *)(*(long *)(param_1 + 0x30) + 0x20) == 0) {
      uVar2 = 0xffffffed;
    }
    else {
      uVar1 = readl();
      uVar2 = 0;
      *param_3 = (byte)((uVar1 & 0xffffffff) >> (*(ulong *)(param_1 + 8) & 0x3f)) & 1;
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// readl @ 001015a4 size=140
// signature: undefined readl(void)
// callers: [qcom_smp2p_intr, smp2p_update_bits, qcom_smp2p_start_in, smp2p_irq_get_irqchip_state]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1015fc,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// smp2p_update_bits @ 00101634 size=236
// signature: undefined smp2p_update_bits(void)
// callers: []
//------------------------------------------------------------

undefined8 smp2p_update_bits(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x60);
  uVar1 = readl(*(undefined8 *)(param_1 + 0x20));
  param_3 = uVar1 & (param_2 ^ 0xffffffff) | param_3;
  writel(param_3,*(undefined8 *)(param_1 + 0x20));
  _raw_spin_unlock_irqrestore(param_1 + 0x60,uVar2);
  ipc_log_string(ilc,"[%s]: %d: %s: orig:0x%0x new:0x%0x\n","smp2p_update_bits",
                 *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x34),*(undefined8 *)(param_1 + 0x18),
                 uVar1,param_3);
  if (param_3 != uVar1) {
    lVar3 = *(long *)(param_1 + 0x10);
    DataSynchronizationBarrier(3,2,0);
    if (*(long *)(lVar3 + 0x88) == 0) {
      regmap_write(*(undefined8 *)(lVar3 + 0x40),*(undefined4 *)(lVar3 + 0x48),
                   1L << ((ulong)*(uint *)(lVar3 + 0x4c) & 0x3f));
    }
    else {
      mbox_send_message(*(long *)(lVar3 + 0x88),0);
      mbox_client_txdone(*(undefined8 *)(lVar3 + 0x88),0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// writel @ 00101720 size=136
// signature: undefined writel(void)
// callers: [smp2p_update_bits]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101738,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101778,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_smp2p_resume @ 001017ac size=16
// signature: undefined qcom_smp2p_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smp2p_resume(void)

{
  smp2p_suspend_in_progress = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_smp2p_freeze @ 001017c0 size=220
// signature: undefined qcom_smp2p_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smp2p_freeze(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  
  lVar5 = *(long *)(param_1 + 0x98);
  irq_set_irq_wake(*(undefined4 *)(lVar5 + 0x38),0);
  plVar6 = (long *)(lVar5 + 0xa0);
  plVar3 = (long *)*plVar6;
  while (plVar3 != plVar6) {
    plVar7 = (long *)*plVar3;
    qcom_smem_state_unregister(plVar3[0xb]);
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    kfree(plVar3);
    plVar3 = plVar7;
  }
  *(long *)(lVar5 + 0xa0) = lVar5 + 0xa0;
  *(long **)(lVar5 + 0xa8) = plVar6;
  plVar3 = (long *)*(long *)(lVar5 + 0x90);
  while (plVar3 != (long *)(lVar5 + 0x90)) {
    *(undefined4 *)(plVar3 + 5) = 0;
    plVar3 = (long *)*plVar3;
  }
  *(undefined8 *)(lVar5 + 8) = 0;
  *(undefined4 *)(lVar5 + 0x20) = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_smp2p_restore @ 001018a0 size=636
// signature: undefined qcom_smp2p_restore(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_smp2p_restore(long param_1)

{
  long *plVar1;
  ushort uVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  size_t __n;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  char *__s;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0x98);
  uVar3 = qcom_smp2p_alloc_outbound_item(puVar8);
  uVar9 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
LAB_00101a6c:
    if ((int)uVar9 == -0x11) {
      uVar9 = 0xffffffef;
    }
    else {
LAB_00101ac8:
      _dev_err(param_1,"failed to alloc items ret = %d\n",uVar9 & 0xffffffff);
    }
  }
  else {
    lVar4 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2e8),0);
    if (lVar4 != 0) {
      plVar1 = puVar8 + 0x14;
      do {
        plVar5 = (long *)kmalloc_trace(_memcpy,0xdc0,0x68);
        if (plVar5 == (long *)0x0) {
          uVar9 = 0xfffffff4;
          goto LAB_00101ac8;
        }
        plVar5[2] = (long)puVar8;
        *(undefined4 *)(plVar5 + 0xc) = 0;
        uVar3 = of_property_read_string(lVar4,"qcom,entry-name",plVar5 + 3);
        uVar9 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
LAB_00101a64:
          kfree(plVar5);
          goto LAB_00101a6c;
        }
        lVar6 = of_find_property(lVar4,"interrupt-controller",0);
        if (lVar6 == 0) {
          __s = (char *)plVar5[3];
          lVar6 = puVar8[2];
          local_78 = 0;
          uStack_70 = 0;
          __n = strlen(__s);
          if (0xe < __n) {
            __n = 0xf;
          }
          memcpy(&local_78,__s,__n);
          uVar2 = *(ushort *)(lVar6 + 0xe);
          *(undefined1 *)((long)&local_78 + __n) = 0;
          lVar7 = lVar6 + (ulong)uVar2 * 0x14;
          *(undefined8 *)(lVar7 + 0x14) = local_78;
          *(undefined8 *)(lVar7 + 0x1c) = uStack_70;
          plVar5[4] = lVar7 + 0x24;
          *(short *)(lVar6 + 0xe) = *(short *)(lVar6 + 0xe) + 1;
          uVar3 = qcom_smem_state_register(lVar4,&smp2p_state_ops,plVar5);
          plVar5[0xb] = uVar3;
          if (uVar3 < 0xfffffffffffff001) {
            uVar9 = 0;
          }
          else {
            _dev_err(*puVar8,"failed to register qcom_smem_state\n");
            uVar9 = plVar5[0xb];
            if ((int)uVar9 < 0) goto LAB_00101a64;
          }
          lVar6 = *plVar1;
          uVar3 = __list_add_valid(plVar5,plVar1,lVar6);
          if ((uVar3 & 1) != 0) {
            *(long **)(lVar6 + 8) = plVar5;
            *plVar5 = lVar6;
            plVar5[1] = (long)plVar1;
            *plVar1 = (long)plVar5;
          }
        }
        else {
          kfree(plVar5);
        }
        lVar4 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2e8),lVar4);
      } while (lVar4 != 0);
    }
    irq_set_irq_wake(*(undefined4 *)(puVar8 + 7),1);
    DataSynchronizationBarrier(3,2,0);
    if (puVar8[0x11] == 0) {
      regmap_write(puVar8[8],*(undefined4 *)(puVar8 + 9),
                   1L << ((ulong)*(uint *)((long)puVar8 + 0x4c) & 0x3f));
    }
    else {
      mbox_send_message(puVar8[0x11],0);
      mbox_client_txdone(puVar8[0x11],0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_smp2p_suspend_no_irq @ 00101b20 size=20
// signature: undefined qcom_smp2p_suspend_no_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smp2p_suspend_no_irq(void)

{
  smp2p_suspend_in_progress = 1;
  return 0;
}



//------------------------------------------------------------
// init_module @ 00101b3c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_smp2p_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101b6c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_smp2p_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// platform_driver_unregister @ 00104008 size=1
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
// ipc_log_context_create @ 00104010 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00104028 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 00104030 size=1
// signature: undefined mbox_request_channel(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104038 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_node_to_regmap @ 00104040 size=1
// signature: undefined syscon_node_to_regmap(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_node_to_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104048 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_smp2p_intr, qcom_smp2p_restore, qcom_smp2p_alloc_outbound_item, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00104050 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00104058 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00104070 size=1
// signature: undefined of_property_read_string(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104078 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_domain_add @ 00104080 size=1
// signature: undefined __irq_domain_add(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_domain_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104088 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00104090 size=1
// signature: size_t strlen(char * __s)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104098 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_register @ 001040a0 size=1
// signature: undefined qcom_smem_state_register(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 001040a8 size=1
// signature: undefined kasprintf(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001040b0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001040b8 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_set_wake_irq @ 001040c0 size=1
// signature: undefined dev_pm_set_wake_irq(void)
// callers: [qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_set_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_clear_wake_irq @ 001040c8 size=1
// signature: undefined dev_pm_clear_wake_irq(void)
// callers: [qcom_smp2p_remove, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_clear_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_remove @ 001040d0 size=1
// signature: undefined irq_domain_remove(void)
// callers: [qcom_smp2p_remove, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040d8 size=1
// signature: undefined kfree(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_freeze, qcom_smp2p_remove, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_unregister @ 001040e0 size=1
// signature: undefined qcom_smem_state_unregister(void)
// callers: [qcom_smp2p_freeze, qcom_smp2p_remove, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 001040e8 size=1
// signature: undefined mbox_free_channel(void)
// callers: [qcom_smp2p_remove, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040f0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_smp2p_intr, qcom_smp2p_restore, qcom_smp2p_alloc_outbound_item, qcom_smp2p_start_in, qcom_smp2p_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_alloc @ 001040f8 size=1
// signature: undefined qcom_smem_alloc(void)
// callers: [qcom_smp2p_alloc_outbound_item]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00104100 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qcom_smp2p_intr, qcom_smp2p_alloc_outbound_item, qcom_smp2p_start_in]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104108 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_smp2p_alloc_outbound_item]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 00104110 size=1
// signature: undefined mbox_send_message(void)
// callers: [qcom_smp2p_kick, qcom_smp2p_intr, qcom_smp2p_restore, qcom_smp2p_alloc_outbound_item, smp2p_update_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_client_txdone @ 00104118 size=1
// signature: undefined mbox_client_txdone(void)
// callers: [qcom_smp2p_kick, qcom_smp2p_intr, qcom_smp2p_restore, qcom_smp2p_alloc_outbound_item, smp2p_update_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_client_txdone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00104120 size=1
// signature: undefined regmap_write(void)
// callers: [qcom_smp2p_kick, qcom_smp2p_intr, qcom_smp2p_restore, qcom_smp2p_alloc_outbound_item, smp2p_update_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104128 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_smp2p_intr, qcom_smp2p_start_in]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00104130 size=1
// signature: undefined ipc_log_string(void)
// callers: [qcom_smp2p_intr, smp2p_retrigger_irq, smp2p_update_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104138 size=1
// signature: undefined _printk(void)
// callers: [qcom_smp2p_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 00104140 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [qcom_smp2p_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// handle_nested_irq @ 00104148 size=1
// signature: undefined handle_nested_irq(void)
// callers: [qcom_smp2p_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void handle_nested_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_and_handler_name @ 00104160 size=1
// signature: undefined irq_set_chip_and_handler_name(void)
// callers: [smp2p_irq_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_and_handler_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_data @ 00104168 size=1
// signature: undefined irq_set_chip_data(void)
// callers: [smp2p_irq_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 00104170 size=1
// signature: undefined irq_modify_status(void)
// callers: [smp2p_irq_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_parent @ 00104178 size=1
// signature: undefined irq_set_parent(void)
// callers: [smp2p_irq_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00104180 size=1
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
// log_post_read_mmio @ 00104188 size=1
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
// _raw_spin_lock_irqsave @ 00104190 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [smp2p_update_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104198 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [smp2p_update_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001041a0 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 001041a8 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001041b0 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [qcom_smp2p_restore, qcom_smp2p_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001041b8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_smp2p_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



