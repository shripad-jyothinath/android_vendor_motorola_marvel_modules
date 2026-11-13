// Decompiled by Ghidra 12.2
// Program: qrtr-gunyah.ko
// Image base: 00100000

//------------------------------------------------------------
// qrtr_gunyah_probe @ 0010033c size=1408
// signature: undefined qrtr_gunyah_probe(void)
// callers: []
//------------------------------------------------------------

ulong qrtr_gunyah_probe(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  bool bVar9;
  uint uVar10;
  int iVar11;
  undefined8 *puVar12;
  long lVar13;
  undefined4 *puVar14;
  char *pcVar15;
  ulong uVar16;
  ulong uVar17;
  undefined8 uVar18;
  long lVar19;
  int local_ac;
  long local_a8 [11];
  
  lVar19 = sp_el0;
  lVar13 = param_1 + 0x10;
  local_a8[10] = *(long *)(lVar19 + 0x638);
  uVar18 = *(undefined8 *)(param_1 + 0x2f8);
  puVar12 = (undefined8 *)devm_kmalloc(lVar13,0x1b8,0xdc0);
  if (puVar12 != (undefined8 *)0x0) {
    puVar12[2] = lVar13;
    *(undefined8 **)(param_1 + 0xa8) = puVar12;
    lVar13 = devm_kmalloc(lVar13,0x10020,0xdc0);
    puVar12[3] = lVar13;
    if (lVar13 != 0) {
      __mutex_init(puVar12 + 0x19,"&qdev->state_lock",&qrtr_gunyah_probe___key);
      *(undefined1 *)(puVar12 + 0x1f) = 0;
      *(undefined4 *)(puVar12 + 0x28) = 0;
      uVar10 = of_property_read_variable_u32_array
                         (uVar18,"gunyah-label",(int *)((long)puVar12 + 0xfc),1,0);
      if ((int)uVar10 < 0) {
        puVar14 = (undefined4 *)(ulong)uVar10;
        _dev_err(puVar12[2],"failed to read label info %d\n",puVar14);
        goto LAB_001007c4;
      }
      lVar13 = of_find_property(uVar18,"qcom,master",0);
      lVar19 = puVar12[2];
      *(bool *)(puVar12 + 0x15) = lVar13 != 0;
      if (lVar13 == 0) {
        local_ac = 0;
        lVar13 = of_find_compatible_node(0,0,"qcom,qrtr-gunyah-gen");
        if (lVar13 != 0) {
          do {
            iVar11 = of_property_read_variable_u32_array(lVar13,"qcom,label",&local_ac,1,0);
            if ((-1 < iVar11) && (local_ac == *(int *)((long)puVar12 + 0xfc))) {
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
              iVar11 = __of_parse_phandle_with_args(lVar13,"memory-region",0,0,0,local_a8);
              if ((iVar11 == 0) && (local_a8[0] != 0)) goto LAB_00100554;
              _dev_err(puVar12[2],"can\'t parse svm shared mem node!\n");
              break;
            }
            lVar13 = of_find_compatible_node(lVar13,0,"qcom,qrtr-gunyah-gen");
          } while (lVar13 != 0);
        }
        pcVar15 = "can\'t parse shared mem node!\n";
LAB_001008a4:
        _dev_err(lVar19,pcVar15);
        puVar14 = (undefined4 *)0xffffffea;
        goto LAB_001007c4;
      }
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
      iVar11 = __of_parse_phandle_with_args
                         (*(undefined8 *)(lVar19 + 0x2e8),"shared-buffer",0,0,0,local_a8);
      if ((iVar11 == 0) && (local_a8[0] != 0)) {
LAB_00100554:
        iVar11 = of_address_to_resource(local_a8[0],0,puVar12 + 6);
        if (iVar11 != 0) {
          pcVar15 = "of_address_to_resource failed!\n";
          goto LAB_001008a4;
        }
        lVar13 = puVar12[6];
        lVar1 = puVar12[7];
        puVar14 = (undefined4 *)devm_ioremap_resource(lVar19,puVar12 + 6);
        puVar12[0x13] = puVar14;
        if (puVar14 < (undefined4 *)0xfffffffffffff001) {
          lVar13 = (lVar1 - lVar13) + 1;
          goto LAB_00100590;
        }
        _dev_err(lVar19,"ioremap failed!\n");
        puVar14 = (undefined4 *)puVar12[0x13];
        if ((int)puVar14 != 0) goto LAB_001007c4;
      }
      else {
        puVar14 = (undefined4 *)dma_alloc_attrs(puVar12[2],0x9000,puVar12 + 6,0xcc0,0x40);
        puVar12[0x13] = puVar14;
        if (puVar14 == (undefined4 *)0x0) goto LAB_00100498;
        lVar13 = 0x9000;
        puVar12[7] = puVar12[6] + 0x8fff;
LAB_00100590:
        puVar12[0x14] = lVar13;
      }
      if (*(char *)(puVar12 + 0x15) == '\0') {
        *puVar14 = 0x24495043;
        bVar9 = *(char *)(puVar12 + 0x15) != '\0';
        lVar13 = 0xc;
        if (bVar9) {
          lVar13 = 4;
        }
        lVar19 = 0x10;
        if (bVar9) {
          lVar19 = 8;
        }
        lVar1 = 4;
        if (bVar9) {
          lVar1 = 0xc;
        }
        lVar2 = 8;
        if (bVar9) {
          lVar2 = 0x10;
        }
        lVar3 = 0x1000;
        if (bVar9) {
          lVar3 = 0x5000;
        }
        lVar4 = 0x5000;
        if (bVar9) {
          lVar4 = 0x1000;
        }
        lVar5 = 0x18;
        if (bVar9) {
          lVar5 = 0x14;
        }
        puVar12[0x29] = (long)puVar14 + lVar13;
        puVar12[0x2a] = (long)puVar14 + lVar19;
        lVar13 = 0x14;
        if (bVar9) {
          lVar13 = 0x18;
        }
        puVar12[0x2d] = 0x4000;
        puVar12[0x2e] = (long)puVar14 + lVar1;
        puVar12[0x31] = puVar12[0x13] + lVar3;
        puVar12[0x32] = 0x4000;
        puVar12[0x2b] = (long)puVar14 + lVar5;
        puVar12[0x2c] = puVar12[0x13] + lVar4;
        puVar12[0x2f] = (long)puVar14 + lVar2;
        puVar12[0x30] = (long)puVar14 + lVar13;
        *(undefined4 *)((long)puVar14 + lVar19) = 0;
        *(undefined4 *)puVar12[0x2b] = 0;
        *(undefined4 *)puVar12[0x2e] = 0;
      }
      __init_waitqueue_head(puVar12 + 0x33,"&qdev->tx_avail_notify",&qrtr_gunyah_probe___key_5);
      if (*(char *)(puVar12 + 0x15) != '\0') {
        iVar11 = of_property_read_variable_u32_array
                           (uVar18,"peer-name",(undefined4 *)((long)puVar12 + 0xac),1,0);
        if (iVar11 < 0) {
          *(undefined4 *)((long)puVar12 + 0xac) = 0;
        }
        puVar12[0x16] = qrtr_gunyah_vm_cb;
        *(undefined4 *)(puVar12 + 0x18) = 0x7fffffff;
        gh_register_vm_notifier();
      }
      uVar6 = *(undefined4 *)((long)puVar12 + 0xfc);
      puVar14 = (undefined4 *)gh_dbl_tx_register(uVar6);
      puVar12[0x20] = puVar14;
      if ((puVar14 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < puVar14)) {
        _dev_err(puVar12[2],"failed to get gunyah tx dbl %d\n",(ulong)puVar14 & 0xffffffff);
        goto LAB_001007c4;
      }
      puVar12[0x22] = 0xfffffffe0;
      puVar12[0x23] = puVar12 + 0x23;
      puVar12[0x24] = puVar12 + 0x23;
      puVar12[0x25] = qrtr_gunyah_retry_work;
      *puVar12 = qrtr_gunyah_send;
      if (*(char *)(puVar12 + 0x15) == '\0') {
        uVar16 = qrtr_endpoint_register(puVar12,1,0,0);
        puVar14 = (undefined4 *)(uVar16 & 0xffffffff);
        if ((int)uVar16 == 0) goto LAB_001006f8;
      }
      else {
LAB_001006f8:
        puVar14 = (undefined4 *)gh_dbl_rx_register(uVar6,qrtr_gunyah_cb,puVar12);
        puVar12[0x21] = puVar14;
        if ((puVar14 != (undefined4 *)0x0) && (puVar14 < (undefined4 *)0xfffffffffffff001)) {
          if (*(char *)(puVar12 + 0x15) == '\0') {
            uVar10 = *(uint *)puVar12[0x2e];
            uVar7 = *(uint *)puVar12[0x2f];
            if (uVar7 < uVar10) {
              uVar17 = puVar12[0x32];
              uVar16 = ((ulong)uVar7 - (ulong)uVar10) + uVar17;
            }
            else {
              uVar16 = (ulong)(uVar7 - uVar10);
              uVar17 = puVar12[0x32];
            }
            if (uVar17 < uVar16) {
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x800,0x1008b8);
              (*pcVar8)();
            }
            if (uVar16 != 0) {
              qrtr_gunyah_read(puVar12);
            }
            if (*(char *)(puVar12 + 0x15) != '\0') goto LAB_001007a0;
          }
          else {
LAB_001007a0:
            iVar11 = of_property_read_variable_u32_array
                               (uVar18,"qcom,rproc-handle",puVar12 + 0x36,1,0);
            if (iVar11 < 0) {
              _dev_warn(puVar12[2],"qcom,rproc-handle not found, VM crash recovery disabled\n");
            }
          }
          puVar14 = (undefined4 *)0x0;
          goto LAB_001007c4;
        }
        _dev_err(puVar12[2],"failed to get gunyah rx dbl %d\n",(ulong)puVar14 & 0xffffffff);
        qrtr_endpoint_unregister(puVar12);
      }
      cancel_work_sync(puVar12 + 0x22);
      gh_dbl_tx_unregister(puVar12[0x20]);
      goto LAB_001007c4;
    }
  }
LAB_00100498:
  puVar14 = (undefined4 *)0xfffffff4;
LAB_001007c4:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar14 & 0xffffffff;
}



//------------------------------------------------------------
// qrtr_gunyah_remove @ 001008cc size=268
// signature: undefined qrtr_gunyah_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qrtr_gunyah_remove(long param_1)

{
  int iVar1;
  long lVar2;
  undefined2 local_80 [2];
  undefined2 local_7c [2];
  long local_78 [11];
  
  lVar2 = sp_el0;
  local_78[10] = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0xa8);
  local_7c[0] = 0;
  local_80[0] = 0;
  cancel_work_sync(lVar2 + 0x110);
  gh_dbl_tx_unregister(*(undefined8 *)(lVar2 + 0x100));
  gh_dbl_rx_unregister(*(undefined8 *)(lVar2 + 0x108));
  if (*(char *)(lVar2 + 0xa8) != '\0') {
    gh_unregister_vm_notifier(lVar2 + 0xb0);
    iVar1 = ghd_rm_get_vmid(*(undefined4 *)(lVar2 + 0xac),local_7c);
    if ((iVar1 == 0) && (iVar1 = ghd_rm_get_vmid(1,local_80), iVar1 == 0)) {
      qrtr_gunyah_unshare_mem(lVar2,local_80[0],local_7c[0]);
      local_78[8] = 0;
      local_78[9] = 0;
      local_78[6] = 0;
      local_78[7] = 0;
      local_78[4] = 0;
      local_78[5] = 0;
      local_78[2] = 0;
      local_78[3] = 0;
      local_78[0] = 0;
      local_78[1] = 0;
      iVar1 = __of_parse_phandle_with_args
                        (*(undefined8 *)(*(long *)(lVar2 + 0x10) + 0x2e8),"shared-buffer",0,0,0,
                         local_78);
      if ((iVar1 != 0) || (local_78[0] == 0)) {
        dma_free_attrs(*(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0xa0),
                       *(undefined8 *)(lVar2 + 0x98),*(undefined8 *)(lVar2 + 0x30),0x40);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qrtr_gunyah_fifo_init @ 001009d8 size=152
// signature: undefined qrtr_gunyah_fifo_init(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

void qrtr_gunyah_fifo_init(long param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined4 *puVar9;
  
  puVar1 = *(undefined4 **)(param_1 + 0x98);
  *puVar1 = 0x24495043;
  if (*(char *)(param_1 + 0xa8) == '\0') {
    puVar9 = puVar1 + 3;
    puVar2 = puVar1 + 4;
    puVar3 = puVar1 + 6;
    puVar4 = puVar1 + 1;
    puVar5 = puVar1 + 2;
    lVar7 = *(long *)(param_1 + 0x98) + 0x5000;
    lVar6 = *(long *)(param_1 + 0x98) + 0x1000;
    lVar8 = 5;
  }
  else {
    puVar9 = puVar1 + 1;
    puVar2 = puVar1 + 2;
    puVar3 = puVar1 + 5;
    puVar4 = puVar1 + 3;
    puVar5 = puVar1 + 4;
    lVar7 = *(long *)(param_1 + 0x98) + 0x1000;
    lVar6 = *(long *)(param_1 + 0x98) + 0x5000;
    lVar8 = 6;
  }
  *(undefined4 **)(param_1 + 0x148) = puVar9;
  *(undefined4 **)(param_1 + 0x150) = puVar2;
  *(undefined4 **)(param_1 + 0x158) = puVar3;
  *(long *)(param_1 + 0x160) = lVar7;
  *(undefined8 *)(param_1 + 0x168) = 0x4000;
  *(undefined4 **)(param_1 + 0x170) = puVar4;
  *(long *)(param_1 + 0x188) = lVar6;
  *(undefined8 *)(param_1 + 400) = 0x4000;
  *(undefined4 **)(param_1 + 0x178) = puVar5;
  *(undefined4 **)(param_1 + 0x180) = puVar1 + lVar8;
  *puVar2 = 0;
  **(undefined4 **)(param_1 + 0x158) = 0;
  **(undefined4 **)(param_1 + 0x170) = 0;
  return;
}



//------------------------------------------------------------
// qrtr_gunyah_vm_cb @ 00100a74 size=544
// signature: undefined qrtr_gunyah_vm_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 qrtr_gunyah_vm_cb(long param_1,long param_2,short *param_3)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  undefined2 local_40 [2];
  short local_3c [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_3c[0] = 0;
  local_40[0] = 0;
  if (param_3 == (short *)0x0) goto LAB_00100bc4;
  sVar2 = *param_3;
  iVar3 = ghd_rm_get_vmid(*(undefined4 *)(param_1 + -4),local_3c);
  if (((iVar3 != 0) || (iVar3 = ghd_rm_get_vmid(1,local_40), iVar3 != 0)) || (local_3c[0] != sVar2))
  goto LAB_00100bc4;
  lVar6 = param_1 + -0xb0;
  mutex_lock(param_1 + 0x18);
  if (param_2 - 2U < 2) {
    if (*(char *)(param_1 + 0x48) != '\0') {
      qrtr_endpoint_unregister(lVar6);
      qrtr_gunyah_unshare_mem(lVar6,local_40[0],local_3c[0]);
      *(undefined1 *)(param_1 + 0x48) = 0;
    }
  }
  else if (param_2 == 1) {
    if (*(char *)(param_1 + 0x48) == '\0') {
      qrtr_gunyah_fifo_init(lVar6);
      iVar3 = qrtr_endpoint_register(lVar6,1,0,0);
      if (iVar3 == 0) {
        iVar3 = qrtr_gunyah_share_mem(lVar6,local_40[0],local_3c[0]);
        if (iVar3 == 0) {
          *(undefined1 *)(param_1 + 0x48) = 1;
        }
        else {
          _printk(&DAT_00101e84,"qrtr_gunyah_vm_cb","qrtr_gunyah_vm_cb");
          qrtr_endpoint_unregister(lVar6);
        }
      }
      else {
        _printk(&DAT_001020c9,"qrtr_gunyah_vm_cb","qrtr_gunyah_vm_cb");
      }
    }
  }
  else if (param_2 == 6) {
    _dev_info(*(undefined8 *)(param_1 + -0xa0),"%s: VM crash detected!\n","qrtr_gunyah_vm_cb");
    lVar6 = rproc_get_by_phandle(*(undefined4 *)(param_1 + 0x100));
    if (lVar6 == 0) {
      _dev_err(*(undefined8 *)(param_1 + -0xa0),"%s: Failed to get rproc handle!\n",
               "qrtr_gunyah_vm_cb");
    }
    else {
      iVar3 = rproc_shutdown();
      if (iVar3 == 0) {
        iVar3 = rproc_boot(lVar6);
        if (iVar3 != 0) {
          uVar4 = *(undefined8 *)(param_1 + -0xa0);
          uVar1 = *(undefined4 *)(lVar6 + 0x3cc);
          pcVar5 = "%s: rproc_boot() failed: %d, state=%d, rproc=%s\n";
          goto LAB_00100c7c;
        }
      }
      else {
        uVar4 = *(undefined8 *)(param_1 + -0xa0);
        uVar1 = *(undefined4 *)(lVar6 + 0x3cc);
        pcVar5 = "%s: rproc_shutdown() failed: %d, state=%d, rproc=%s\n";
LAB_00100c7c:
        _dev_err(uVar4,pcVar5,"qrtr_gunyah_vm_cb",iVar3,uVar1,*(undefined8 *)(lVar6 + 0x18));
      }
      rproc_put(lVar6);
    }
  }
  mutex_unlock(param_1 + 0x18);
LAB_00100bc4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qrtr_gunyah_retry_work @ 00100c98 size=92
// signature: undefined qrtr_gunyah_retry_work(void)
// callers: []
//------------------------------------------------------------

void qrtr_gunyah_retry_work(long param_1)

{
  long lVar1;
  undefined8 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = 1;
  gh_dbl_send(*(undefined8 *)(param_1 + -0x10),&local_20,0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_gunyah_send @ 00100cf8 size=1416
// signature: undefined qrtr_gunyah_send(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100eec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qrtr_gunyah_send(long param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  undefined4 uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  uint uVar14;
  long lVar15;
  int iVar16;
  uint uVar17;
  int local_31c;
  undefined8 local_2f8;
  undefined8 local_2f0;
  ulong uStack_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  long local_70;
  
  lVar15 = sp_el0;
  local_70 = *(long *)(lVar15 + 0x638);
  uVar17 = *(uint *)(param_2 + 0x70);
  if ((int)uVar17 < 1) {
    local_31c = 0;
  }
  else {
    iVar16 = 0;
    local_31c = 0;
    do {
      while( true ) {
        uVar2 = **(uint **)(param_1 + 0x150);
        uVar13 = (ulong)uVar2;
        uVar14 = **(uint **)(param_1 + 0x148);
        if (uVar2 < uVar14) {
          uVar14 = uVar14 - uVar2;
          uVar11 = *(ulong *)(param_1 + 0x168);
          uVar12 = uVar11 - uVar13;
        }
        else {
          uVar11 = *(ulong *)(param_1 + 0x168);
          uVar14 = (uVar14 - uVar2) + (int)uVar11;
          uVar12 = uVar11 - uVar13;
        }
        if (uVar11 < uVar13) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x100ec4);
          (*pcVar6)();
        }
        uVar4 = uVar14 - 8;
        if (7 < uVar14 && uVar4 != 0) break;
        **(undefined4 **)(param_1 + 0x158) = 1;
        local_2b0 = 1;
        iVar7 = gh_dbl_send(*(undefined8 *)(param_1 + 0x100),&local_2b0,0x100000000);
        if (iVar7 != 0) {
          if (iVar7 == 0xb) {
            cVar3 = *(char *)(param_1 + 0xa8);
          }
          else {
            _dev_err(*(undefined8 *)(param_1 + 0x10),"failed to raise doorbell %d\n",iVar7);
            cVar3 = *(char *)(param_1 + 0xa8);
          }
          if (cVar3 == '\0') {
            queue_work_on(0x20,_system_wq,param_1 + 0x110);
          }
        }
        uVar14 = **(uint **)(param_1 + 0x148);
        uVar2 = **(uint **)(param_1 + 0x150);
        if (uVar2 < uVar14) {
          uVar14 = uVar14 - uVar2;
          uVar13 = *(ulong *)(param_1 + 0x168);
        }
        else {
          uVar13 = *(ulong *)(param_1 + 0x168);
          uVar14 = (uVar14 - uVar2) + (int)uVar13;
        }
        if (uVar13 < uVar2) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x100ee0);
          (*pcVar6)();
        }
        if (uVar14 < 9) {
          local_298 = 0;
          uStack_290 = 0;
          local_2a8 = 0;
          uStack_2a0 = 0;
          local_2b0 = 0;
          init_wait_entry(&local_2b0,0);
          lVar15 = 0x9c4;
          while( true ) {
            prepare_to_wait_event(param_1 + 0x198,&local_2b0,2);
            uVar14 = **(uint **)(param_1 + 0x148);
            uVar2 = **(uint **)(param_1 + 0x150);
            uVar13 = (ulong)uVar2;
            if (uVar2 < uVar14) {
              uVar14 = uVar14 - uVar2;
              uVar12 = *(ulong *)(param_1 + 0x168);
            }
            else {
              uVar12 = *(ulong *)(param_1 + 0x168);
              uVar14 = (uVar14 - uVar2) + (int)uVar12;
            }
            if (uVar12 < uVar13) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x800,0x100e60);
              (*pcVar6)();
            }
            bVar5 = uVar12 >= uVar13;
            if ((bVar5 && 8 < uVar14) && lVar15 == 0) {
              lVar15 = 1;
            }
            if (((bVar5 && 7 < uVar14) && (uVar12 < uVar13 || uVar14 != 8)) || (lVar15 == 0)) break;
            lVar15 = schedule_timeout(lVar15);
          }
          finish_wait(param_1 + 0x198,&local_2b0);
          if ((int)lVar15 == 0) {
            _dev_err(*(undefined8 *)(param_1 + 0x10),"transport stalled\n");
            local_31c = -0x6e;
            goto LAB_00101218;
          }
        }
      }
      if (uVar17 <= uVar4) {
        uVar4 = uVar17;
      }
      uVar11 = (ulong)uVar4;
      if (*(int *)(param_2 + 0x74) == 0) {
        uVar1 = uVar12;
        if (uVar11 <= uVar12) {
          uVar1 = uVar11;
        }
        lVar15 = *(long *)(param_2 + 0xe0) + (long)iVar16;
        if (uVar1 != 0) {
          __memcpy_toio(*(long *)(param_1 + 0x160) + uVar13,lVar15,uVar1);
        }
        if (uVar12 < uVar11) {
          __memcpy_toio(*(undefined8 *)(param_1 + 0x160),lVar15 + uVar1,uVar11 - uVar1);
        }
        uVar13 = *(ulong *)(param_1 + 0x168);
        DataMemoryBarrier(2,2);
      }
      else {
        memset(&local_2b0,0,0x240);
        sg_init_table(&local_2b0,
                      *(byte *)(*(long *)(param_2 + 0xd8) + (ulong)*(uint *)(param_2 + 0xd4) + 2) +
                      1);
        local_31c = skb_to_sgvec(param_2,&local_2b0,0,*(undefined4 *)(param_2 + 0x70));
        if (local_31c < 0) {
          _printk(&DAT_00101e63,"qrtr_gunyah_send",local_31c);
          break;
        }
        uVar2 = **(uint **)(param_1 + 0x150);
        uVar12 = (ulong)uVar2;
        uVar13 = *(ulong *)(param_1 + 0x168) - uVar12;
        if (*(ulong *)(param_1 + 0x168) < uVar12) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1011f0);
          (*pcVar6)();
        }
        uVar1 = uVar13;
        if (uVar11 <= uVar13) {
          uVar1 = uVar11;
        }
        iVar7 = iVar16;
        if (uVar1 != 0) {
          uVar8 = sg_nents(&local_2b0);
          lVar15 = *(long *)(param_1 + 0x160);
          local_2c0 = 0;
          uStack_2b8 = 0;
          local_2d0 = 0;
          uStack_2c8 = 0;
          local_2e0 = 0;
          uStack_2d8 = 0;
          local_2f0 = 0;
          uStack_2e8 = 0;
          local_2f8 = 0;
          sg_miter_start(&local_2f8,&local_2b0,uVar8,5);
          uVar9 = sg_miter_skip(&local_2f8,(long)iVar16);
          if ((uVar9 & 1) == 0) {
            uVar14 = 0;
          }
          else {
            uVar9 = 0;
            do {
              uVar10 = sg_miter_next(&local_2f8);
              uVar14 = (uint)uVar9;
              if ((uVar10 & 1) == 0) break;
              uVar10 = uStack_2e8;
              if (uVar1 - uVar9 <= uStack_2e8) {
                uVar10 = uVar1 - uVar9;
              }
              __memcpy_toio(lVar15 + uVar12 + uVar9,local_2f0,uVar10 & 0xffffffff);
              uVar14 = uVar14 + (int)uVar10;
              uVar9 = (ulong)uVar14;
            } while (uVar9 < uVar1);
            sg_miter_stop(&local_2f8);
          }
          iVar7 = uVar14 + iVar16;
        }
        if (uVar13 < uVar11) {
          uVar8 = sg_nents(&local_2b0);
          lVar15 = *(long *)(param_1 + 0x160);
          local_2c0 = 0;
          uStack_2b8 = 0;
          local_2d0 = 0;
          uStack_2c8 = 0;
          local_2e0 = 0;
          uStack_2d8 = 0;
          local_2f0 = 0;
          uStack_2e8 = 0;
          local_2f8 = 0;
          sg_miter_start(&local_2f8,&local_2b0,uVar8,5);
          uVar13 = sg_miter_skip(&local_2f8,(long)iVar7);
          if ((uVar13 & 1) != 0) {
            uVar13 = 0;
            uVar14 = 0;
            do {
              uVar12 = sg_miter_next(&local_2f8);
              if ((uVar12 & 1) == 0) break;
              uVar9 = (uVar11 - uVar1) - uVar13;
              uVar12 = uStack_2e8;
              if (uVar9 <= uStack_2e8) {
                uVar12 = uVar9;
              }
              __memcpy_toio(lVar15 + uVar13,local_2f0,uVar12 & 0xffffffff);
              uVar14 = uVar14 + (int)uVar12;
              uVar13 = (ulong)uVar14;
            } while (uVar13 < uVar11 - uVar1);
            sg_miter_stop(&local_2f8);
          }
        }
        uVar13 = *(ulong *)(param_1 + 0x168);
        DataMemoryBarrier(2,2);
      }
      iVar7 = 0;
      if (uVar13 <= uVar2 + uVar4) {
        iVar7 = (int)uVar13;
      }
      **(int **)(param_1 + 0x150) = (uVar2 + uVar4) - iVar7;
      uVar17 = uVar17 - uVar4;
      local_2b0 = 1;
      iVar7 = gh_dbl_send(*(undefined8 *)(param_1 + 0x100),&local_2b0,0x100000000);
      if (iVar7 != 0) {
        if (iVar7 == 0xb) {
          cVar3 = *(char *)(param_1 + 0xa8);
        }
        else {
          _dev_err(*(undefined8 *)(param_1 + 0x10),"failed to raise doorbell %d\n",iVar7);
          cVar3 = *(char *)(param_1 + 0xa8);
        }
        if (cVar3 == '\0') {
          queue_work_on(0x20,_system_wq,param_1 + 0x110);
        }
      }
      iVar16 = uVar4 + iVar16;
    } while (0 < (int)uVar17);
  }
LAB_00101218:
  **(undefined4 **)(param_1 + 0x158) = 0;
  kfree_skb_reason(param_2,1);
  lVar15 = sp_el0;
  if (-1 < local_31c) {
    local_31c = 0;
  }
  if (*(long *)(lVar15 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_31c);
  }
  return;
}



//------------------------------------------------------------
// qrtr_gunyah_cb @ 00101298 size=32
// signature: undefined qrtr_gunyah_cb(void)
// callers: []
//------------------------------------------------------------

void qrtr_gunyah_cb(undefined8 param_1,undefined8 param_2)

{
  qrtr_gunyah_read(param_2);
  return;
}



//------------------------------------------------------------
// qrtr_gunyah_read @ 001012b8 size=1120
// signature: undefined qrtr_gunyah_read(void)
// callers: [qrtr_gunyah_cb, qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qrtr_gunyah_read(long param_1)

{
  uint uVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00101fc1,"qrtr_gunyah_read","qrtr_gunyah_read");
  }
  else {
    uVar6 = _raw_spin_lock_irqsave();
    __wake_up(param_1 + 0x198,3,0,0);
    while( true ) {
      uVar9 = **(uint **)(param_1 + 0x170);
      uVar1 = **(uint **)(param_1 + 0x178);
      if (uVar1 < uVar9) {
        uVar7 = *(ulong *)(param_1 + 400);
        uVar13 = ((ulong)uVar1 - (ulong)uVar9) + uVar7;
      }
      else {
        uVar13 = (ulong)(uVar1 - uVar9);
        uVar7 = *(ulong *)(param_1 + 400);
      }
      if (uVar7 < uVar13) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x101710);
        (*pcVar3)();
      }
      if (uVar13 == 0) break;
      uVar13 = (ulong)*(uint *)(param_1 + 0x28);
      if (*(uint *)(param_1 + 0x28) == 0) {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        uVar9 = **(uint **)(param_1 + 0x170);
        iVar4 = 0;
        if (uVar7 <= uVar9) {
          iVar4 = (int)uVar7;
        }
        uVar11 = (ulong)(uVar9 - iVar4);
        uVar13 = uVar7 - uVar11;
        if (uVar7 < uVar11) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1016c0);
          (*pcVar3)();
        }
        uVar7 = uVar13;
        if (0x1f < uVar13) {
          uVar7 = 0x20;
        }
        if (uVar7 != 0) {
          __memcpy_fromio(&local_88,*(long *)(param_1 + 0x188) + uVar11,uVar7);
        }
        if (uVar13 < 0x20) {
          __memcpy_fromio((long)&local_88 + uVar7,*(undefined8 *)(param_1 + 0x188),0x20 - uVar7);
        }
        uVar5 = qrtr_peek_pkt_size(&local_88);
        uVar7 = (ulong)(int)uVar5;
        uVar9 = **(uint **)(param_1 + 0x178);
        uVar1 = **(uint **)(param_1 + 0x170);
        uVar13 = (ulong)uVar1;
        if (uVar5 < 0x10021) {
          if (uVar9 < uVar1) {
            uVar12 = *(ulong *)(param_1 + 400);
            uVar11 = (uVar9 - uVar13) + uVar12;
          }
          else {
            uVar11 = (ulong)(uVar9 - uVar1);
            uVar12 = *(ulong *)(param_1 + 400);
          }
          if (uVar12 < uVar11) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1016c8);
            (*pcVar3)();
          }
          uVar10 = uVar11;
          if (uVar7 <= uVar11) {
            uVar10 = uVar7;
          }
          iVar4 = 0;
          if (uVar12 <= uVar13) {
            iVar4 = (int)uVar12;
          }
          uVar8 = (ulong)(uVar1 - iVar4);
          uVar13 = uVar12 - uVar8;
          if (uVar12 < uVar8) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1016e0);
            (*pcVar3)();
          }
          lVar14 = *(long *)(param_1 + 0x18);
          uVar12 = uVar13;
          if (uVar10 <= uVar13) {
            uVar12 = uVar10;
          }
          if (uVar12 != 0) {
            __memcpy_fromio(lVar14,*(long *)(param_1 + 0x188) + uVar8,uVar12);
          }
          if (uVar13 < uVar10) {
            __memcpy_fromio(lVar14 + uVar12,*(undefined8 *)(param_1 + 0x188),uVar10 - uVar12);
          }
          uVar13 = *(ulong *)(param_1 + 400);
          uVar9 = **(uint **)(param_1 + 0x170) + (int)uVar10;
          if (uVar13 <= uVar9) {
            iVar4 = 0;
            if (uVar13 != 0) {
              iVar4 = (int)(uVar9 / uVar13);
            }
            uVar9 = uVar9 - iVar4 * (int)uVar13;
          }
          **(uint **)(param_1 + 0x170) = uVar9;
          if (uVar11 < uVar7) {
            *(ulong *)(param_1 + 0x20) = uVar7;
            *(int *)(param_1 + 0x28) = (int)uVar10;
          }
          else {
            iVar4 = qrtr_endpoint_post(param_1,*(undefined8 *)(param_1 + 0x18),uVar7);
            if (iVar4 == -0x16) {
              _dev_err(*(undefined8 *)(param_1 + 0x10),"invalid ipcrouter packet\n");
            }
          }
        }
        else {
          if (uVar9 < uVar1) {
            uVar11 = *(ulong *)(param_1 + 400);
            uVar13 = (uVar9 - uVar13) + uVar11;
          }
          else {
            uVar13 = (ulong)(uVar9 - uVar1);
            uVar11 = *(ulong *)(param_1 + 400);
          }
          if (uVar11 < uVar13) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1016ec);
            (*pcVar3)();
          }
          _dev_err(*(undefined8 *)(param_1 + 0x10),"invalid pkt_len:%zu dropping:%zu bytes\n",uVar7,
                   uVar13);
          uVar7 = *(ulong *)(param_1 + 400);
          uVar9 = **(uint **)(param_1 + 0x170) + (int)uVar13;
          if (uVar7 <= uVar9) {
            iVar4 = 0;
            if (uVar7 != 0) {
              iVar4 = (int)(uVar9 / uVar7);
            }
            uVar9 = uVar9 - iVar4 * (int)uVar7;
          }
          **(uint **)(param_1 + 0x170) = uVar9;
        }
      }
      else {
        uVar11 = ((ulong)uVar1 - (ulong)uVar9) + uVar7;
        if (uVar9 <= uVar1) {
          uVar11 = (ulong)(uVar1 - uVar9);
        }
        if (uVar7 < uVar11) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10169c);
          (*pcVar3)();
        }
        uVar12 = *(ulong *)(param_1 + 0x20) - uVar13;
        if (uVar11 + uVar13 <= *(ulong *)(param_1 + 0x20)) {
          uVar12 = uVar11;
        }
        iVar4 = 0;
        if (uVar7 <= uVar9) {
          iVar4 = (int)uVar7;
        }
        uVar10 = (ulong)(uVar9 - iVar4);
        uVar11 = uVar7 - uVar10;
        if (uVar7 < uVar10) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1016b8);
          (*pcVar3)();
        }
        uVar7 = uVar11;
        if (uVar12 <= uVar11) {
          uVar7 = uVar12;
        }
        lVar14 = *(long *)(param_1 + 0x18) + uVar13;
        if (uVar7 != 0) {
          __memcpy_fromio(lVar14,*(long *)(param_1 + 0x188) + uVar10,uVar7);
        }
        if (uVar11 < uVar12) {
          __memcpy_fromio(lVar14 + uVar7,*(undefined8 *)(param_1 + 0x188),uVar12 - uVar7);
        }
        uVar13 = *(ulong *)(param_1 + 400);
        uVar9 = **(uint **)(param_1 + 0x170) + (int)uVar12;
        if (uVar13 <= uVar9) {
          iVar4 = 0;
          if (uVar13 != 0) {
            iVar4 = (int)(uVar9 / uVar13);
          }
          uVar9 = uVar9 - iVar4 * (int)uVar13;
        }
        **(uint **)(param_1 + 0x170) = uVar9;
        lVar14 = uVar12 + *(uint *)(param_1 + 0x28);
        if (lVar14 == *(long *)(param_1 + 0x20)) {
          iVar4 = qrtr_endpoint_post(param_1,*(undefined8 *)(param_1 + 0x18));
          if (iVar4 == -0x16) {
            _dev_err(*(undefined8 *)(param_1 + 0x10),"invalid ipcrouter packet\n");
          }
          *(undefined4 *)(param_1 + 0x28) = 0;
          *(undefined8 *)(param_1 + 0x20) = 0;
        }
        else {
          *(int *)(param_1 + 0x28) = (int)lVar14;
        }
      }
      if (**(int **)(param_1 + 0x180) != 0) {
        local_88 = 1;
        iVar4 = gh_dbl_send(*(undefined8 *)(param_1 + 0x100),&local_88,0x100000000);
        if (iVar4 != 0) {
          if (iVar4 == 0xb) {
            cVar2 = *(char *)(param_1 + 0xa8);
          }
          else {
            _dev_err(*(undefined8 *)(param_1 + 0x10),"failed to raise doorbell %d\n",iVar4);
            cVar2 = *(char *)(param_1 + 0xa8);
          }
          if (cVar2 == '\0') {
            queue_work_on(0x20,_system_wq,param_1 + 0x110);
          }
        }
      }
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x140,uVar6);
  }
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_gunyah_share_mem @ 00101754 size=532
// signature: undefined qrtr_gunyah_share_mem(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qrtr_gunyah_share_mem(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  ulong local_70;
  ulong uStack_68;
  uint local_60 [3];
  undefined4 uStack_54;
  uint local_50 [2];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_60[0] = (uint)param_2 & 0xffff;
  local_60[2] = (uint)param_3 & 0xffff;
  local_50[1] = 7;
  uStack_68 = 1L << (param_2 & 0x3f);
  local_60[1] = 6;
  local_70 = 1L << (param_3 & 0x3f) | uStack_68;
  uStack_54 = 6;
  local_50[0] = local_60[0];
  iVar4 = qcom_scm_assign_mem(*(long *)(param_1 + 0x30),
                              (*(long *)(param_1 + 0x38) - *(long *)(param_1 + 0x30)) + 1,&uStack_68
                              ,local_60,2);
  if (iVar4 == 0) {
    puVar6 = (undefined4 *)kmalloc_trace(_DAT_00104200,0xdc0,0xc);
    if (puVar6 == (undefined4 *)0x0) {
      iVar4 = -0xc;
    }
    else {
      puVar7 = (undefined2 *)kmalloc_trace(_DAT_00104200,0xdc0,0x14);
      if (puVar7 == (undefined2 *)0x0) {
        kfree(puVar6);
        iVar4 = -0xc;
      }
      else {
        lVar1 = *(long *)(param_1 + 0x30);
        lVar2 = *(long *)(param_1 + 0x38);
        *puVar6 = 2;
        *(undefined1 *)((long)puVar6 + 6) = 6;
        uVar3 = *(undefined4 *)(param_1 + 0xfc);
        *(undefined1 *)((long)puVar6 + 10) = 6;
        *puVar7 = 1;
        *(long *)(puVar7 + 2) = lVar1;
        *(short *)(puVar6 + 1) = (short)param_2;
        *(long *)(puVar7 + 6) = (lVar2 - lVar1) + 1;
        *(short *)(puVar6 + 2) = (short)param_3;
        iVar4 = ghd_rm_mem_share(0,1,uVar3,puVar6,puVar7,0,param_1 + 0x90);
        if (iVar4 != 0) {
          _printk(&DAT_00101f57,"qrtr_gunyah_share_mem","qrtr_gunyah_share_mem",
                  *(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0xa0),iVar4);
          iVar5 = qcom_scm_assign_mem(*(long *)(param_1 + 0x30),
                                      (*(long *)(param_1 + 0x38) - *(long *)(param_1 + 0x30)) + 1,
                                      &local_70,local_50,1);
          if (iVar5 != 0) {
            _printk(&DAT_00102024,"qrtr_gunyah_share_mem","qrtr_gunyah_share_mem",
                    *(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0xa0),iVar4);
          }
        }
        kfree(puVar6);
        kfree(puVar7);
      }
    }
  }
  else {
    _printk(&DAT_00102024,"qrtr_gunyah_share_mem","qrtr_gunyah_share_mem",
            *(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0xa0),iVar4);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qrtr_gunyah_unshare_mem @ 00101968 size=232
// signature: undefined qrtr_gunyah_unshare_mem(void)
// callers: [qrtr_gunyah_vm_cb, qrtr_gunyah_remove]
//------------------------------------------------------------

void qrtr_gunyah_unshare_mem(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  ulong local_38;
  uint local_30 [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 1L << (param_3 & 0x3f) | 1L << (param_2 & 0x3f);
  local_30[0] = (uint)param_2 & 0xffff;
  local_30[1] = 7;
  iVar2 = ghd_rm_mem_reclaim(*(undefined4 *)(param_1 + 0x90),0);
  if (iVar2 != 0) {
    _printk(&DAT_00101cb0,"qrtr_gunyah_unshare_mem","qrtr_gunyah_unshare_mem");
  }
  iVar2 = qcom_scm_assign_mem(*(long *)(param_1 + 0x30),
                              (*(long *)(param_1 + 0x38) - *(long *)(param_1 + 0x30)) + 1,&local_38,
                              local_30,1);
  if (iVar2 != 0) {
    _printk(&DAT_00102024,"qrtr_gunyah_unshare_mem","qrtr_gunyah_unshare_mem",
            *(long *)(param_1 + 0x30),(*(long *)(param_1 + 0x38) - *(long *)(param_1 + 0x30)) + 1,
            iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101a54 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qrtr_gunyah_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101a84 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qrtr_gunyah_driver);
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
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104018 size=1
// signature: undefined __mutex_init(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104028 size=1
// signature: undefined of_find_property(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104030 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qrtr_gunyah_probe, qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00104038 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00104040 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00104048 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00104050 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00104058 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_register_vm_notifier @ 00104060 size=1
// signature: undefined gh_register_vm_notifier(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_register_vm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_tx_register @ 00104068 size=1
// signature: undefined gh_dbl_tx_register(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_tx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_register @ 00104070 size=1
// signature: undefined gh_dbl_rx_register(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_register @ 00104078 size=1
// signature: undefined qrtr_endpoint_register(void)
// callers: [qrtr_gunyah_vm_cb, qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00104080 size=1
// signature: undefined cancel_work_sync(void)
// callers: [qrtr_gunyah_probe, qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_tx_unregister @ 00104088 size=1
// signature: undefined gh_dbl_tx_unregister(void)
// callers: [qrtr_gunyah_probe, qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_tx_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104090 size=1
// signature: undefined _dev_err(void)
// callers: [qrtr_gunyah_send, qrtr_gunyah_vm_cb, qrtr_gunyah_probe, qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_unregister @ 00104098 size=1
// signature: undefined qrtr_endpoint_unregister(void)
// callers: [qrtr_gunyah_vm_cb, qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001040a0 size=1
// signature: undefined _dev_warn(void)
// callers: [qrtr_gunyah_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qrtr_gunyah_retry_work, qrtr_gunyah_send, qrtr_gunyah_unshare_mem, qrtr_gunyah_vm_cb, qrtr_gunyah_share_mem, qrtr_gunyah_probe, qrtr_gunyah_read, qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_unregister @ 001040b0 size=1
// signature: undefined gh_dbl_rx_unregister(void)
// callers: [qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_unregister_vm_notifier @ 001040b8 size=1
// signature: undefined gh_unregister_vm_notifier(void)
// callers: [qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_unregister_vm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 001040c0 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [qrtr_gunyah_vm_cb, qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001040c8 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qrtr_gunyah_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001040d0 size=1
// signature: undefined mutex_lock(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001040d8 size=1
// signature: undefined _dev_info(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 001040e0 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_shutdown @ 001040e8 size=1
// signature: undefined rproc_shutdown(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_boot @ 001040f0 size=1
// signature: undefined rproc_boot(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_boot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_put @ 001040f8 size=1
// signature: undefined rproc_put(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104100 size=1
// signature: undefined mutex_unlock(void)
// callers: [qrtr_gunyah_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104108 size=1
// signature: undefined _printk(void)
// callers: [qrtr_gunyah_send, qrtr_gunyah_unshare_mem, qrtr_gunyah_vm_cb, qrtr_gunyah_share_mem, qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_send @ 00104110 size=1
// signature: undefined gh_dbl_send(void)
// callers: [qrtr_gunyah_retry_work, qrtr_gunyah_send, qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00104118 size=1
// signature: undefined finish_wait(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104128 size=1
// signature: undefined queue_work_on(void)
// callers: [qrtr_gunyah_send, qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00104130 size=1
// signature: undefined init_wait_entry(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00104138 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00104140 size=1
// signature: undefined schedule_timeout(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104148 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 00104150 size=1
// signature: undefined sg_init_table(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_to_sgvec @ 00104158 size=1
// signature: undefined skb_to_sgvec(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_to_sgvec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_nents @ 00104160 size=1
// signature: undefined sg_nents(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_nents(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_start @ 00104168 size=1
// signature: undefined sg_miter_start(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_skip @ 00104170 size=1
// signature: undefined sg_miter_skip(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_skip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_next @ 00104178 size=1
// signature: undefined sg_miter_next(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 00104180 size=1
// signature: undefined __memcpy_toio(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_stop @ 00104188 size=1
// signature: undefined sg_miter_stop(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 00104190 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [qrtr_gunyah_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104198 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001041a0 size=1
// signature: undefined __wake_up(void)
// callers: [qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 001041a8 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_endpoint_post @ 001041b0 size=1
// signature: undefined qrtr_endpoint_post(void)
// callers: [qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_endpoint_post(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qrtr_peek_pkt_size @ 001041b8 size=1
// signature: undefined qrtr_peek_pkt_size(void)
// callers: [qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qrtr_peek_pkt_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001041c0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qrtr_gunyah_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 001041c8 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [qrtr_gunyah_unshare_mem, qrtr_gunyah_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001041d8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qrtr_gunyah_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 001041e0 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [qrtr_gunyah_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001041e8 size=1
// signature: undefined kfree(void)
// callers: [qrtr_gunyah_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 001041f0 size=1
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [qrtr_gunyah_unshare_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



