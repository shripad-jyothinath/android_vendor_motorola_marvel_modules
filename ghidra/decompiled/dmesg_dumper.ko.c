// Decompiled by Ghidra 12.2
// Program: dmesg_dumper.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_ddump_probe @ 00100374 size=1488
// signature: undefined qcom_ddump_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_ddump_probe(long param_1)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  long *plVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  uint local_bc;
  ulong local_b8 [11];
  
  lVar4 = sp_el0;
  plVar7 = (long *)(param_1 + 0x10);
  local_b8[10] = *(long *)(lVar4 + 0x638);
  uVar8 = *(undefined8 *)(param_1 + 0x2f8);
  plVar3 = (long *)devm_kmalloc(plVar7,0x158,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar9 = 0xfffffff4;
    goto LAB_00100904;
  }
  *(long **)(param_1 + 0xa8) = plVar3;
  *plVar3 = (long)plVar7;
  uVar1 = of_property_read_variable_u32_array(uVar8,"gunyah-label",plVar3 + 0x15,1,0);
  if ((int)uVar1 < 0) {
    uVar9 = (ulong)uVar1;
    _dev_err(plVar7,"Failed to read label %d\n",uVar9);
    goto LAB_00100904;
  }
  lVar4 = of_find_property(uVar8,"qcom,primary-vm",0);
  lVar10 = *plVar3;
  local_bc = 0;
  *(bool *)((long)plVar3 + 0xb4) = lVar4 != 0;
  if (lVar4 == 0) {
    local_b8[0] = local_b8[0] & 0xffffffff00000000;
    lVar4 = of_find_compatible_node(0,0,"qcom,ddump-gunyah-gen");
    if (lVar4 != 0) {
      do {
        iVar2 = of_property_read_variable_u32_array(lVar4,"qcom,label",local_b8,1,0);
        if ((-1 < iVar2) && ((int)local_b8[0] == (int)plVar3[0x15])) goto LAB_001004a4;
        lVar4 = of_find_compatible_node(lVar4,0,"qcom,ddump-gunyah-gen");
      } while (lVar4 != 0);
    }
    _dev_err(lVar10,"Unable to parse shared mem node\n");
    uVar9 = 0xffffffea;
    goto LAB_00100904;
  }
  lVar4 = *(long *)(lVar10 + 0x2e8);
LAB_001004a4:
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
  iVar2 = __of_parse_phandle_with_args(lVar4,"memory-region",0,0,0,local_b8);
  uVar9 = 0xffffffea;
  if ((iVar2 != 0) || (local_b8[0] == 0)) goto LAB_00100904;
  iVar2 = of_address_to_resource(local_b8[0],0,plVar3 + 7);
  if (iVar2 != 0) {
    uVar1 = dma_set_mask(lVar10,0xffffffffffffffff);
    if (uVar1 != 0) {
      uVar9 = (ulong)uVar1;
      _dev_err(lVar10,"%s: dma_set_mask_and_coherent failed\n","qcom_ddump_map_memory");
      goto LAB_00100904;
    }
    dma_set_coherent_mask(lVar10,0xffffffffffffffff);
    uVar1 = of_reserved_mem_device_init_by_idx(lVar10,*(undefined8 *)(lVar10 + 0x2e8),0);
    if (uVar1 == 0) {
      uVar1 = of_property_read_variable_u32_array
                        (*(undefined8 *)(*plVar3 + 0x2e8),"shared-buffer-size",&local_bc,1,0);
      if (-1 < (int)uVar1) {
        uVar9 = (ulong)local_bc;
        *(undefined1 *)(plVar3 + 0x2a) = 0;
        goto LAB_00100570;
      }
      pcVar6 = "%s: Failed to get shared memory size, ret %d\n";
    }
    else {
      pcVar6 = "%s: Failed to initialize CMA mem, ret %d\n";
    }
    uVar9 = (ulong)uVar1;
    _dev_err(lVar10,pcVar6,"qcom_ddump_map_memory",uVar9);
    goto LAB_00100904;
  }
  *(undefined1 *)(plVar3 + 0x2a) = 1;
  uVar9 = (plVar3[8] - plVar3[7]) + 1;
LAB_00100570:
  plVar3[0x14] = uVar9;
  if (*(char *)((long)plVar3 + 0xb4) == '\0') {
    lVar4 = *(long *)(param_1 + 0x80);
    if (lVar4 == 0) {
      lVar4 = *plVar7;
    }
    lVar4 = __devm_request_region(plVar7,&iomem_resource,plVar3[7],uVar9,lVar4);
    if (lVar4 == 0) {
      _dev_err(plVar7,"request mem region fail\n");
      uVar9 = 0xfffffffa;
      goto LAB_00100904;
    }
    lVar4 = devm_ioremap_wc(plVar7,plVar3[7],plVar3[0x14]);
    plVar3[0x13] = lVar4;
    if (lVar4 == 0) {
      _dev_err(plVar7,"ioremap fail\n");
      uVar9 = 0xfffffff4;
      goto LAB_00100904;
    }
    kmsg_dump_rewind(plVar3 + 5);
    plVar3[3] = (long)qcom_ddump_to_shm;
    uVar5 = kmsg_dump_register(plVar3 + 1);
    uVar9 = uVar5 & 0xffffffff;
    if ((int)uVar5 != 0) goto LAB_00100904;
  }
  else {
    iVar2 = of_property_read_variable_u32_array
                      (uVar8,"peer-name",(undefined4 *)((long)plVar3 + 0xac),1,0);
    if (iVar2 < 0) {
      *(undefined4 *)((long)plVar3 + 0xac) = 0;
    }
    plVar3[0x17] = (long)qcom_ddump_rm_cb;
    *(undefined4 *)(plVar3 + 0x19) = 0x7fffffff;
    gh_rm_register_notifier();
  }
  plVar7 = (long *)*plVar3;
  if ((ulong)plVar3[0x14] < 0x418) {
    _dev_err(plVar7,"Shared memory size should greater than %d\n",0x418);
    uVar9 = 0xffffffea;
  }
  else {
    if (*(char *)((long)plVar3 + 0xb4) == '\0') {
      *(undefined1 *)(plVar3[0x13] + 0x10) = 0;
      lVar4 = plVar7[0xe];
      if (lVar4 == 0) {
        lVar4 = *plVar7;
      }
      lVar4 = wakeup_source_register(plVar7,lVar4);
      plVar3[0x20] = lVar4;
      if (lVar4 != 0) {
        *(undefined4 *)(plVar3 + 0x23) = 0x7fffffff;
        plVar3[0x21] = (long)qcom_ddump_gh_panic_handler;
        uVar5 = gh_panic_notifier_register(plVar3 + 0x21);
        uVar9 = uVar5 & 0xffffffff;
        if ((int)uVar5 == 0) goto LAB_0010065c;
LAB_001008a4:
        if (*(char *)((long)plVar3 + 0xb4) == '\0') {
          wakeup_source_unregister(plVar3[0x20]);
        }
        if ((int)uVar9 == 0) goto LAB_00100904;
        goto LAB_001008e8;
      }
    }
    else {
      if ((char)plVar3[0x2a] == '\0') {
LAB_0010061c:
        *(undefined4 *)(plVar3 + 0x1c) = 0;
        __init_swait_queue_head(plVar3 + 0x1d,"&x->wait",&init_completion___key);
        lVar4 = proc_create_data("vmkmsg",0x100,0,ddump_proc_ops,plVar3);
        if (lVar4 != 0) {
LAB_0010065c:
          lVar4 = plVar3[0x15];
          uVar9 = gh_dbl_tx_register((int)lVar4);
          plVar3[0x1a] = uVar9;
          if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
            _dev_err(plVar7,"%s:Failed to get gunyah tx dbl %d\n","qcom_ddump_alive_log_probe",
                     uVar9 & 0xffffffff);
          }
          else {
            uVar9 = gh_dbl_rx_register((int)lVar4,qcom_ddump_gh_cb,plVar3);
            plVar3[0x1b] = uVar9;
            if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) {
              uVar9 = 0;
              goto LAB_00100904;
            }
            _dev_err(plVar7,"%s:Failed to get gunyah rx dbl %d\n","qcom_ddump_alive_log_probe",
                     uVar9 & 0xffffffff);
            gh_dbl_tx_unregister(plVar3[0x1a]);
          }
          if (*(char *)((long)plVar3 + 0xb4) == '\0') {
            gh_panic_notifier_unregister(plVar3 + 0x21);
          }
          else {
            remove_proc_entry("vmkmsg",0);
          }
          goto LAB_001008a4;
        }
        pcVar6 = "proc_create_data fail\n";
      }
      else {
        lVar4 = plVar7[0xe];
        if (lVar4 == 0) {
          lVar4 = *plVar7;
        }
        lVar4 = __devm_request_region(plVar7,&iomem_resource,plVar3[7],plVar3[0x14],lVar4);
        if (lVar4 == 0) {
          _dev_err(plVar7,"request mem region fail\n");
          uVar9 = 0xfffffffa;
          goto LAB_001008e8;
        }
        lVar4 = devm_ioremap_wc(plVar7,plVar3[7],plVar3[0x14]);
        plVar3[0x13] = lVar4;
        if (lVar4 != 0) goto LAB_0010061c;
        pcVar6 = "ioremap fail\n";
      }
      _dev_err(plVar7,pcVar6);
    }
    uVar9 = 0xfffffff4;
  }
LAB_001008e8:
  if (*(char *)((long)plVar3 + 0xb4) == '\0') {
    kmsg_dump_unregister(plVar3 + 1);
  }
  else {
    gh_rm_unregister_notifier(plVar3 + 0x17);
  }
LAB_00100904:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_ddump_remove @ 00100948 size=300
// signature: undefined qcom_ddump_remove(void)
// callers: []
//------------------------------------------------------------

void qcom_ddump_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined2 local_40 [2];
  undefined2 local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0xa8);
  local_3c[0] = 0;
  local_40[0] = 0;
  gh_dbl_tx_unregister(puVar5[0x1a]);
  gh_dbl_rx_unregister(puVar5[0x1b]);
  if (*(char *)((long)puVar5 + 0xb4) == '\0') {
    gh_panic_notifier_unregister(puVar5 + 0x21);
    wakeup_source_unregister(puVar5[0x20]);
    if (*(char *)((long)puVar5 + 0xb4) == '\0') goto LAB_00100a34;
LAB_001009a8:
    gh_rm_unregister_notifier(puVar5 + 0x17);
    uVar3 = ghd_rm_get_vmid(*(undefined4 *)((long)puVar5 + 0xac),local_3c);
    if ((((int)uVar3 != 0) || (uVar3 = ghd_rm_get_vmid(1,local_40), (int)uVar3 != 0)) ||
       (uVar3 = qcom_ddump_unshare_mem(puVar5,local_40[0],local_3c[0]), (int)uVar3 != 0))
    goto LAB_00100a44;
    if (*(char *)(puVar5 + 0x2a) == '\0') {
      uVar6 = *puVar5;
      uVar3 = puVar5[0x13];
      uVar1 = puVar5[0x14];
      uVar4 = phys_to_dma(uVar6,puVar5[7]);
      dma_free_attrs(uVar6,uVar1,uVar3,uVar4,0);
    }
  }
  else {
    remove_proc_entry("vmkmsg",0);
    if (*(char *)((long)puVar5 + 0xb4) != '\0') goto LAB_001009a8;
LAB_00100a34:
    uVar3 = kmsg_dump_unregister(puVar5 + 1);
    if ((int)uVar3 != 0) goto LAB_00100a44;
  }
  uVar3 = 0;
LAB_00100a44:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_ddump_rm_cb @ 00100a78 size=504
// signature: undefined qcom_ddump_rm_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ddump_rm_cb(long param_1,long param_2,short *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined2 local_48 [2];
  short local_44 [2];
  undefined8 local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_40 = 0;
  local_44[0] = 0;
  local_48[0] = 0;
  if (((param_2 != 0x56100008) ||
      ((((char)param_3[2] != '\v' && ((char)param_3[2] != '\x02')) ||
       (iVar4 = ghd_rm_get_vmid(*(undefined4 *)(param_1 + -0xc),local_44), iVar4 != 0)))) ||
     ((iVar4 = ghd_rm_get_vmid(1,local_48), iVar4 != 0 || (local_44[0] != *param_3))))
  goto LAB_00100c08;
  cVar3 = (char)param_3[2];
  puVar8 = (undefined8 *)(param_1 + -0xb8);
  if (cVar3 == '\x02') {
    if (*(char *)(param_1 + 0x98) == '\0') {
      lVar5 = dma_alloc_attrs(*(undefined8 *)(param_1 + -0xb8),*(undefined8 *)(param_1 + -0x18),
                              &local_40,0xcc0,0);
      *(long *)(param_1 + -0x20) = lVar5;
      if (lVar5 == 0) goto LAB_00100c08;
      lVar5 = dma_to_phys(*(undefined8 *)(param_1 + -0xb8),local_40);
      *(long *)(param_1 + -0x80) = lVar5;
      *(long *)(param_1 + -0x78) = lVar5 + *(long *)(param_1 + -0x18) + -1;
    }
    strscpy(param_1 + 0x68,"VM_LOG",7);
    *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_1 + -0x20);
    *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(param_1 + -0x80);
    *(undefined8 *)(param_1 + 0x90) = *(undefined8 *)(param_1 + -0x18);
    iVar4 = msm_minidump_add_region(param_1 + 0x68);
    if (iVar4 < 0) {
      _dev_err(*puVar8,"Failed to add vm log entry in minidump table %d\n",iVar4);
    }
    iVar4 = qcom_ddump_share_mem(puVar8,local_48[0],local_44[0]);
    if (iVar4 == 0) {
      cVar3 = (char)param_3[2];
      vm_status_ready = 1;
      goto LAB_00100bb0;
    }
    _dev_err(*puVar8,"Failed to share memory\n");
    cVar3 = *(char *)(param_1 + 0x98);
  }
  else {
LAB_00100bb0:
    if (cVar3 != '\v') goto LAB_00100c08;
    vm_status_ready = 0;
    iVar4 = qcom_ddump_unshare_mem(puVar8,local_48[0],local_44[0]);
    if (iVar4 != 0) goto LAB_00100c08;
    cVar3 = *(char *)(param_1 + 0x98);
  }
  if (cVar3 == '\0') {
    uVar7 = *(undefined8 *)(param_1 + -0xb8);
    uVar1 = *(undefined8 *)(param_1 + -0x20);
    uVar2 = *(undefined8 *)(param_1 + -0x18);
    uVar6 = phys_to_dma(uVar7,*(undefined8 *)(param_1 + -0x80));
    dma_free_attrs(uVar7,uVar2,uVar1,uVar6,0);
  }
LAB_00100c08:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_ddump_to_shm @ 00100c74 size=168
// signature: undefined qcom_ddump_to_shm(void)
// callers: [qcom_ddump_gh_panic_handler]
//------------------------------------------------------------

void qcom_ddump_to_shm(long param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  _dev_warn(*(undefined8 *)(param_1 + -8),"reason = %d\n",param_2);
  kmsg_dump_rewind(param_1 + 0x20);
  memset(*(void **)(param_1 + 0x90),0,*(size_t *)(param_1 + 0x98));
  kmsg_dump_get_buffer
            (param_1 + 0x20,0,*(undefined8 *)(param_1 + 0x90),*(undefined8 *)(param_1 + 0x98),
             &local_30);
  _dev_warn(*(undefined8 *)(param_1 + -8),"size of dmesg logbuf logged = %lld\n",local_30);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dma_to_phys @ 00100d1c size=72
// signature: undefined dma_to_phys(void)
// callers: [qcom_ddump_rm_cb]
//------------------------------------------------------------

ulong dma_to_phys(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_1 + 0x2b0);
  if (lVar1 != 0) {
    uVar3 = *(ulong *)(lVar1 + 0x10);
    if (uVar3 != 0) {
      plVar2 = (long *)(lVar1 + 0x18);
      do {
        if ((ulong)plVar2[-2] <= param_2 && param_2 - plVar2[-2] < uVar3) {
          return *plVar2 + param_2;
        }
        uVar3 = plVar2[3];
        plVar2 = plVar2 + 4;
      } while (uVar3 != 0);
    }
    param_2 = 0xffffffffffffffff;
  }
  return param_2;
}



//------------------------------------------------------------
// qcom_ddump_share_mem @ 00100d64 size=508
// signature: undefined qcom_ddump_share_mem(void)
// callers: [qcom_ddump_rm_cb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_ddump_share_mem(undefined8 *param_1,ulong param_2,ulong param_3)

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
  uint local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_60[0] = (uint)param_2 & 0xffff;
  local_50 = (uint)param_3 & 0xffff;
  local_70 = 1L << (param_2 & 0x3f);
  uStack_54 = 6;
  uStack_4c = 6;
  uStack_68 = 1L << (param_3 & 0x3f) | local_70;
  local_60[1] = 7;
  local_60[2] = local_60[0];
  iVar4 = qcom_scm_assign_mem(param_1[7],(param_1[8] - param_1[7]) + 1,&local_70,local_60 + 2,2);
  if (iVar4 == 0) {
    puVar6 = (undefined4 *)kmalloc_trace(_complete,0xdc0,0xc);
    if (puVar6 == (undefined4 *)0x0) {
      iVar4 = -0xc;
    }
    else {
      puVar7 = (undefined2 *)kmalloc_trace(_complete,0xdc0,0x14);
      if (puVar7 == (undefined2 *)0x0) {
        kfree(puVar6);
        iVar4 = -0xc;
      }
      else {
        lVar1 = param_1[7];
        lVar2 = param_1[8];
        *puVar6 = 2;
        *(undefined1 *)((long)puVar6 + 6) = 6;
        uVar3 = *(undefined4 *)(param_1 + 0x15);
        *(undefined1 *)((long)puVar6 + 10) = 6;
        *puVar7 = 1;
        *(long *)(puVar7 + 2) = lVar1;
        *(short *)(puVar6 + 1) = (short)param_2;
        *(long *)(puVar7 + 6) = (lVar2 - lVar1) + 1;
        *(short *)(puVar6 + 2) = (short)param_3;
        iVar4 = ghd_rm_mem_share(0,0,uVar3,puVar6,puVar7,0,param_1 + 0x16);
        if (iVar4 != 0) {
          _dev_err(*param_1,"Gunyah mem share addr=%x size=%u failed: %d\n",param_1[7],param_1[0x14]
                   ,iVar4);
          iVar5 = qcom_scm_assign_mem(param_1[7],(param_1[8] - param_1[7]) + 1,&uStack_68,local_60,1
                                     );
          if (iVar5 != 0) {
            _dev_err(*param_1,"qcom_scm_assign_mem addr=%x size=%u failed: %d\n",param_1[7],
                     param_1[0x14],iVar4);
          }
        }
        kfree(puVar6);
        kfree(puVar7);
      }
    }
  }
  else {
    _dev_err(*param_1,"qcom_scm_assign_mem addr=%x size=%u failed: %d\n",param_1[7],param_1[0x14],
             iVar4);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qcom_ddump_unshare_mem @ 00100f60 size=216
// signature: undefined qcom_ddump_unshare_mem(void)
// callers: [qcom_ddump_remove, qcom_ddump_rm_cb]
//------------------------------------------------------------

int qcom_ddump_unshare_mem(undefined8 *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  ulong local_38;
  uint local_30 [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = (uint)param_2 & 0xffff;
  local_38 = 1L << (param_3 & 0x3f) | 1L << (param_2 & 0x3f);
  local_30[1] = 7;
  iVar2 = ghd_rm_mem_reclaim(*(undefined4 *)(param_1 + 0x16),0);
  if (iVar2 != 0) {
    _dev_err(*param_1,"Gunyah mem reclaim failed: %d\n",iVar2);
  }
  iVar2 = qcom_scm_assign_mem(param_1[7],(param_1[8] - param_1[7]) + 1,&local_38,local_30,1);
  if (iVar2 != 0) {
    _dev_err(*param_1,"unshare mem assign call failed with %d\n",iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// phys_to_dma @ 00101038 size=68
// signature: undefined phys_to_dma(void)
// callers: [qcom_ddump_remove, qcom_ddump_rm_cb]
//------------------------------------------------------------

ulong phys_to_dma(long param_1,ulong param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  
  puVar2 = *(ulong **)(param_1 + 0x2b0);
  if (puVar2 != (ulong *)0x0) {
    uVar3 = puVar2[2];
    while (uVar3 != 0) {
      if (*puVar2 <= param_2 && param_2 - *puVar2 < uVar3) {
        return param_2 - puVar2[3];
      }
      puVar1 = puVar2 + 6;
      puVar2 = puVar2 + 4;
      uVar3 = *puVar1;
    }
    param_2 = 0xffffffffffffffff;
  }
  return param_2;
}



//------------------------------------------------------------
// qcom_ddump_gh_panic_handler @ 00101080 size=40
// signature: undefined qcom_ddump_gh_panic_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ddump_gh_panic_handler(long param_1)

{
  qcom_ddump_to_shm(param_1 + -0x100,1);
  return 0;
}



//------------------------------------------------------------
// qcom_ddump_gh_cb @ 001010ac size=236
// signature: undefined qcom_ddump_gh_cb(void)
// callers: []
//------------------------------------------------------------

void qcom_ddump_gh_cb(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = param_2[0x13];
  local_48 = 1;
  gh_dbl_read_and_clean(param_2[0x1b],&local_48,0x100000000);
  if (*(char *)((long)param_2 + 0xb4) == '\0') {
    pm_wakeup_ws_event(param_2[0x20],2000,1);
    local_40 = 1;
    iVar1 = gh_dbl_send(param_2[0x1a],&local_40,0);
    if (iVar1 == 0) {
      lVar2 = *(long *)(lVar2 + 8);
    }
    else {
      _dev_err(*param_2,"failed to raise virq to the sender %d\n",iVar1);
      lVar2 = *(long *)(lVar2 + 8);
    }
    if (lVar2 == 0) {
      pm_wakeup_ws_event(param_2[0x20],0,1);
    }
  }
  else {
    complete(param_2 + 0x1c);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_ddump_vmkmsg_read @ 0010119c size=620
// signature: undefined qcom_ddump_vmkmsg_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_ddump_vmkmsg_read(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  ulong *puVar9;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  if (vm_status_ready == '\x01') {
    puVar8 = *(undefined8 **)(*(long *)(param_1 + 0x20) + 0x2b8);
    if (param_3 < 0x400) {
      _dev_err(*puVar8,"user buffer size should greater than %d\n",0x400);
      uVar7 = 0xffffffffffffffea;
    }
    else {
      puVar9 = (ulong *)puVar8[0x13];
      if (((char)puVar9[2] == '\0') || (0x3ff < puVar9[1])) {
        *puVar9 = param_3;
        local_50 = 1;
        iVar3 = gh_dbl_send(puVar8[0x1a],&local_50,0);
        if (iVar3 != 0) {
          _dev_err(*puVar8,"failed to raise virq to the sender %d\n",iVar3);
        }
        iVar3 = wait_for_completion_timeout(puVar8 + 0x1c,0xfa);
        if (iVar3 == 0) {
          _dev_err(*puVar8,"wait for completion timeout\n");
          uVar7 = 0xffffffffffffff92;
          goto LAB_0010133c;
        }
        uVar7 = puVar9[1];
        if (param_3 < uVar7) {
          _dev_err(*puVar8,"can not read the correct length of svm kmsg\n");
          uVar7 = 0xffffffffffffffea;
          goto LAB_0010133c;
        }
        if (uVar7 != 0) {
          if (uVar7 >> 0x1f != 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1013d4);
            (*pcVar2)();
          }
          __check_object_size(puVar9 + 3,uVar7,1);
          puVar5 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
             (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
            uVar6 = param_2 & (long)(param_2 << 8) >> 8;
          }
          if (uVar6 <= 0x8000000000 - uVar7) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar6 = daif;
              if ((uVar6 & 0x80) == 0) {
                uVar1 = daif;
                daif = uVar1 | 0xc0;
              }
              puVar5 = (undefined8 *)puVar5[1];
              uVar1 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar5;
              InstructionSynchronizationBarrier();
              daif = uVar6;
            }
            lVar4 = __arch_copy_to_user(puVar5,param_2 & 0xff7fffffffffffff,puVar9 + 3,uVar7);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar7 = daif;
              if ((uVar7 & 0x80) == 0) {
                uVar6 = daif;
                daif = uVar6 | 0xc0;
              }
              uVar6 = ttbr1_el1;
              ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar6 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar7;
            }
            if (lVar4 == 0) {
              uVar7 = puVar9[1];
              goto LAB_0010133c;
            }
          }
          _dev_err(*puVar8,"copy_to_user fail\n");
          uVar7 = 0xfffffffffffffff2;
          goto LAB_0010133c;
        }
      }
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0xffffffffffffffed;
  }
LAB_0010133c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0010144c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ddump_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010147c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ddump_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103018 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103020 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00103028 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103030 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00103038 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00103040 size=1
// signature: undefined dma_set_mask(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00103048 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00103050 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00103058 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_request_region @ 00103068 size=1
// signature: undefined __devm_request_region(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_request_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_wc @ 00103070 size=1
// signature: undefined devm_ioremap_wc(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_wc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00103078 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create_data @ 00103080 size=1
// signature: undefined proc_create_data(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_tx_register @ 00103088 size=1
// signature: undefined gh_dbl_tx_register(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_tx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_register @ 00103090 size=1
// signature: undefined gh_dbl_rx_register(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_rewind @ 00103098 size=1
// signature: undefined kmsg_dump_rewind(void)
// callers: [qcom_ddump_probe, qcom_ddump_to_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_rewind(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_register @ 001030a0 size=1
// signature: undefined kmsg_dump_register(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 001030a8 size=1
// signature: undefined wakeup_source_register(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_panic_notifier_register @ 001030b0 size=1
// signature: undefined gh_panic_notifier_register(void)
// callers: [qcom_ddump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_panic_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030b8 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_ddump_probe, qcom_ddump_unshare_mem, qcom_ddump_gh_cb, qcom_ddump_share_mem, qcom_ddump_rm_cb, qcom_ddump_vmkmsg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_tx_unregister @ 001030c0 size=1
// signature: undefined gh_dbl_tx_unregister(void)
// callers: [qcom_ddump_probe, qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_tx_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 001030c8 size=1
// signature: undefined remove_proc_entry(void)
// callers: [qcom_ddump_probe, qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_panic_notifier_unregister @ 001030d0 size=1
// signature: undefined gh_panic_notifier_unregister(void)
// callers: [qcom_ddump_probe, qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_panic_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 001030d8 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [qcom_ddump_probe, qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 001030e0 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [qcom_ddump_probe, qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_unregister @ 001030e8 size=1
// signature: undefined kmsg_dump_unregister(void)
// callers: [qcom_ddump_probe, qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030f0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_ddump_probe, qcom_ddump_unshare_mem, qcom_ddump_gh_cb, qcom_ddump_share_mem, qcom_ddump_remove, qcom_ddump_rm_cb, qcom_ddump_to_shm, qcom_ddump_vmkmsg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_unregister @ 001030f8 size=1
// signature: undefined gh_dbl_rx_unregister(void)
// callers: [qcom_ddump_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 00103100 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [qcom_ddump_remove, qcom_ddump_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00103108 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qcom_ddump_remove, qcom_ddump_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00103110 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qcom_ddump_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103118 size=1
// signature: undefined strscpy(void)
// callers: [qcom_ddump_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00103120 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [qcom_ddump_rm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00103128 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_ddump_to_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00103130 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_ddump_to_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmsg_dump_get_buffer @ 00103138 size=1
// signature: undefined kmsg_dump_get_buffer(void)
// callers: [qcom_ddump_to_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmsg_dump_get_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00103140 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [qcom_ddump_unshare_mem, qcom_ddump_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103150 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_ddump_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 00103158 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [qcom_ddump_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103160 size=1
// signature: undefined kfree(void)
// callers: [qcom_ddump_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 00103168 size=1
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [qcom_ddump_unshare_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_read_and_clean @ 00103170 size=1
// signature: undefined gh_dbl_read_and_clean(void)
// callers: [qcom_ddump_gh_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_read_and_clean(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00103178 size=1
// signature: undefined complete(void)
// callers: [qcom_ddump_gh_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_ws_event @ 00103180 size=1
// signature: undefined pm_wakeup_ws_event(void)
// callers: [qcom_ddump_gh_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_send @ 00103188 size=1
// signature: undefined gh_dbl_send(void)
// callers: [qcom_ddump_gh_cb, qcom_ddump_vmkmsg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00103190 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [qcom_ddump_vmkmsg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00103198 size=1
// signature: undefined __check_object_size(void)
// callers: [qcom_ddump_vmkmsg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001031b0 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [qcom_ddump_vmkmsg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



