// Decompiled by Ghidra 12.2
// Program: gh_panic_notifier.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_panic_notifier_register @ 0010032c size=40
// signature: undefined gh_panic_notifier_register(void)
// callers: []
//------------------------------------------------------------

void gh_panic_notifier_register(undefined8 param_1)

{
  srcu_notifier_chain_register(&gh_panic_notifier,param_1);
  return;
}



//------------------------------------------------------------
// gh_panic_notifier_unregister @ 00100358 size=40
// signature: undefined gh_panic_notifier_unregister(void)
// callers: []
//------------------------------------------------------------

void gh_panic_notifier_unregister(undefined8 param_1)

{
  srcu_notifier_chain_unregister(&gh_panic_notifier,param_1);
  return;
}



//------------------------------------------------------------
// gh_panic_notifier_probe @ 00100384 size=1292
// signature: undefined gh_panic_notifier_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong gh_panic_notifier_probe(long param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined8 *puVar9;
  char *pcVar10;
  char *pcVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  undefined8 uVar15;
  int local_ac;
  ulong local_a8 [11];
  
  lVar13 = sp_el0;
  plVar1 = (long *)(param_1 + 0x10);
  local_a8[10] = *(long *)(lVar13 + 0x638);
  uVar15 = *(undefined8 *)(param_1 + 0x2f8);
  plVar4 = (long *)devm_kmalloc(plVar1,0xd0,0xdc0);
  if (plVar4 == (long *)0x0) {
LAB_001006e4:
    uVar6 = 0xfffffff4;
    goto LAB_001006e8;
  }
  *(long **)(param_1 + 0xa8) = plVar4;
  *plVar4 = (long)plVar1;
  uVar2 = of_property_read_variable_u32_array(uVar15,"gunyah-label",plVar4 + 0xf,1,0);
  if ((int)uVar2 < 0) {
    uVar6 = (ulong)uVar2;
    _dev_err(plVar1,"Failed to read label %d\n",uVar6);
    goto LAB_001006e8;
  }
  lVar13 = plVar4[0xf];
  lVar5 = of_find_property(uVar15,"qcom,primary-vm",0);
  *(bool *)((long)plVar4 + 0x84) = lVar5 != 0;
  if (lVar5 == 0) {
    local_ac = 0;
    lVar5 = of_find_compatible_node(0,0,"qcom,gunyah-panic-gen");
    if (lVar5 != 0) {
      do {
        iVar3 = of_property_read_variable_u32_array(lVar5,"qcom,label",&local_ac,1,0);
        if ((-1 < iVar3) && (local_ac == (int)plVar4[0xf])) {
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
          iVar3 = __of_parse_phandle_with_args(lVar5,"memory-region",0,0,0,local_a8);
          uVar6 = local_a8[0];
          if (iVar3 != 0) {
            uVar6 = 0;
          }
          iVar3 = of_address_to_resource(uVar6,0,plVar4 + 1);
          if (iVar3 != 0) {
            _dev_err(*plVar4,"of_address_to_resource failed!\n");
            uVar6 = 0xffffffea;
            goto LAB_001006e8;
          }
          plVar14 = (long *)*plVar4;
          lVar5 = (plVar4[2] - plVar4[1]) + 1;
          plVar4[0xe] = lVar5;
          lVar12 = plVar14[0xe];
          if (lVar12 == 0) {
            lVar12 = *plVar14;
          }
          lVar5 = __devm_request_region(plVar14,&iomem_resource,plVar4[1],lVar5,lVar12);
          if (lVar5 == 0) {
            _dev_err(*plVar4,"request mem region fail\n");
            uVar6 = 0xfffffffa;
            goto LAB_001006e8;
          }
          lVar5 = devm_ioremap_wc(*plVar4,plVar4[1],plVar4[0xe]);
          plVar4[0xd] = lVar5;
          if (lVar5 == 0) {
            _dev_err(*plVar4,"ioremap fail\n");
            goto LAB_001006e4;
          }
          uVar6 = gh_dbl_rx_register((int)lVar13,gh_panic_notify_receiver,plVar4);
          plVar4[0x12] = uVar6;
          if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
            _dev_err(plVar1,"%s:Failed to get gunyah rx dbl %d\n","gh_panic_notifier_probe",
                     uVar6 & 0xffffffff);
            goto LAB_001006e8;
          }
          lVar13 = *(long *)(param_1 + 0x80);
          if (lVar13 == 0) {
            lVar13 = *plVar1;
          }
          lVar13 = wakeup_source_register(plVar1,lVar13);
          plVar4[0x13] = lVar13;
          if (lVar13 == 0) {
            _dev_err(plVar1,"%s:Failed to register wakeup source\n","gh_panic_notifier_probe");
            gh_dbl_rx_unregister(plVar4[0x12]);
            goto LAB_001006e4;
          }
          uVar6 = 0;
          goto LAB_001006e8;
        }
        lVar5 = of_find_compatible_node(lVar5,0,"qcom,gunyah-panic-gen");
      } while (lVar5 != 0);
    }
    _dev_err(*plVar4,"can\'t find the label=%d memory!\n",(int)plVar4[0xf]);
    uVar6 = 0xffffffed;
    goto LAB_001006e8;
  }
  plVar14 = (long *)*plVar4;
  local_a8[0] = local_a8[0] & 0xffffffff00000000;
  uVar2 = dma_set_mask(plVar14,0xffffffffffffffff);
  if (uVar2 != 0) {
    uVar6 = (ulong)uVar2;
    _dev_err(plVar14,"%s: dma_set_mask_and_coherent failed\n","gh_panic_notifier_pvm_mem_probe");
    goto LAB_001006e8;
  }
  dma_set_coherent_mask(plVar14,0xffffffffffffffff);
  uVar2 = of_reserved_mem_device_init_by_idx(plVar14,plVar14[0x5d],0);
  if (uVar2 == 0) {
    uVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(*plVar4 + 0x2e8),"shared-buffer-size",local_a8,1,0);
    if ((int)uVar2 < 0) {
      pcVar10 = "%s: Failed to get shared memory size, ret %d\n";
      goto LAB_00100794;
    }
    plVar4[0xe] = local_a8[0] & 0xffffffff;
    iVar3 = of_property_read_variable_u32_array
                      (uVar15,"peer-name",(undefined4 *)((long)plVar4 + 0x7c),1,0);
    if (iVar3 < 0) {
      *(undefined4 *)((long)plVar4 + 0x7c) = 0;
    }
    uVar6 = gh_dbl_tx_register((int)lVar13);
    plVar4[0x11] = uVar6;
    if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
      puVar7 = (undefined1 *)kmalloc_trace(_iomem_resource,0xdc0,0x50);
      recovery_vms = puVar7;
      if (puVar7 != (undefined1 *)0x0) {
        *puVar7 = 0;
        *(code **)(puVar7 + 0x18) = recovery_show;
        *(code **)(puVar7 + 0x20) = recovery_store;
        *(undefined2 *)(puVar7 + 0x10) = 0x180;
        *(char **)(puVar7 + 8) = "trustedvm_recovery";
        uVar2 = sysfs_create_file_ns(plVar1,puVar7 + 8,0);
        puVar7 = recovery_vms;
        if (uVar2 == 0) {
          puVar9 = (undefined8 *)(recovery_vms + 0x30);
          *puVar9 = "oemvm_recovery";
          puVar7[0x28] = 0;
          *(code **)(puVar7 + 0x40) = recovery_show;
          *(code **)(puVar7 + 0x48) = recovery_store;
          *(undefined2 *)(puVar7 + 0x38) = 0x180;
          uVar8 = sysfs_create_file_ns(plVar1,puVar9,0);
          uVar6 = uVar8 & 0xffffffff;
          if ((int)uVar8 == 0) {
            plVar4[0x14] = (long)gh_panic_notifier_vm_cb;
            *(undefined4 *)(plVar4 + 0x16) = 0x7fffffff;
            gh_register_vm_notifier(plVar4 + 0x14);
            goto LAB_001006e8;
          }
          lVar13 = 1;
        }
        else {
          uVar6 = (ulong)uVar2;
          lVar13 = 0;
        }
        _printk(&DAT_001019da,(&recovery_name_to_vm_name)[lVar13 * 4],uVar6);
        gh_dbl_tx_unregister(plVar4[0x11]);
        kfree(recovery_vms);
        goto LAB_001006e8;
      }
      gh_dbl_tx_unregister(plVar4[0x11]);
      goto LAB_001006e4;
    }
    pcVar10 = "%s:Failed to get gunyah tx dbl %d\n";
    pcVar11 = "gh_panic_notifier_probe";
    plVar14 = plVar1;
  }
  else {
    pcVar10 = "%s: Failed to initialize CMA mem, ret %d\n";
LAB_00100794:
    uVar6 = (ulong)uVar2;
    pcVar11 = "gh_panic_notifier_pvm_mem_probe";
  }
  _dev_err(plVar14,pcVar10,pcVar11,uVar6 & 0xffffffff);
LAB_001006e8:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// gh_panic_notifier_remove @ 00100894 size=96
// signature: undefined gh_panic_notifier_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_panic_notifier_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (*(char *)(lVar1 + 0x84) == '\0') {
    gh_dbl_rx_unregister(*(undefined8 *)(lVar1 + 0x90));
    wakeup_source_unregister(*(undefined8 *)(lVar1 + 0x98));
  }
  else {
    gh_dbl_tx_unregister(*(undefined8 *)(lVar1 + 0x88));
    gh_unregister_vm_notifier(lVar1 + 0xa0);
    kfree(recovery_vms);
  }
  return 0;
}



//------------------------------------------------------------
// gh_panic_notifier_vm_cb @ 001008f8 size=688
// signature: undefined gh_panic_notifier_vm_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_panic_notifier_vm_cb(long param_1,long param_2,ushort *param_3)

{
  ulong *puVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  long lVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong uVar8;
  undefined8 *puVar9;
  ushort local_58 [2];
  ushort local_54 [2];
  undefined8 local_50;
  ulong local_48;
  uint local_40 [2];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  local_54[0] = 0;
  local_58[0] = 0;
  iVar2 = ghd_rm_get_vmid(*(undefined4 *)(param_1 + -0x24),local_54);
  if ((iVar2 == 0) && (iVar2 = ghd_rm_get_vmid(1,local_58), iVar2 == 0)) {
    puVar9 = (undefined8 *)(param_1 + -0xa0);
    if (param_2 == 1) {
      if (local_54[0] == *param_3) {
        puVar4 = (undefined1 *)
                 dma_alloc_attrs(*(undefined8 *)(param_1 + -0xa0),*(undefined8 *)(param_1 + -0x30),
                                 &local_50,0xcc0,0);
        *(undefined1 **)(param_1 + -0x38) = puVar4;
        if (puVar4 != (undefined1 *)0x0) {
          lVar5 = dma_to_phys(*(undefined8 *)(param_1 + -0xa0),local_50);
          *(long *)(param_1 + -0x98) = lVar5;
          *(long *)(param_1 + -0x90) = lVar5 + *(long *)(param_1 + -0x30) + -1;
          *puVar4 = 0;
          iVar2 = gh_panic_notifier_share_mem(puVar9,local_58[0],local_54[0]);
          if (iVar2 == 0) {
            *(undefined8 *)(param_1 + 0x18) = gh_panic_notifier_notify;
            *(undefined4 *)(param_1 + 0x28) = 0;
            atomic_notifier_chain_register(&panic_notifier_list,(undefined8 *)(param_1 + 0x18));
          }
          else {
            _dev_err(*puVar9,"Failed to share memory\n");
          }
        }
      }
    }
    else if (param_2 == 3) {
      if (local_54[0] == *param_3) {
        atomic_notifier_chain_unregister(&panic_notifier_list,param_1 + 0x18);
        local_40[0] = (uint)local_58[0];
        local_40[1] = 7;
        local_48 = 1L << ((ulong)local_54[0] & 0x3f) | 1L << ((ulong)local_58[0] & 0x3f);
        iVar2 = ghd_rm_mem_reclaim(*(undefined4 *)(param_1 + -0x20),0);
        if (iVar2 != 0) {
          _dev_err(*puVar9,"Gunyah mem reclaim failed: %d\n",iVar2);
        }
        iVar2 = qcom_scm_assign_mem(*(long *)(param_1 + -0x98),
                                    (*(long *)(param_1 + -0x90) - *(long *)(param_1 + -0x98)) + 1,
                                    &local_48,local_40,1);
        lVar5 = *(long *)(param_1 + -0xa0);
        if (iVar2 == 0) {
          puVar7 = *(ulong **)(lVar5 + 0x2b0);
          uVar6 = *(ulong *)(param_1 + -0x98);
          if (puVar7 != (ulong *)0x0) {
            uVar8 = puVar7[2];
            while (uVar8 != 0) {
              if (*puVar7 <= uVar6 && uVar6 - *puVar7 < uVar8) {
                uVar6 = uVar6 - puVar7[3];
                goto LAB_00100b40;
              }
              puVar1 = puVar7 + 6;
              puVar7 = puVar7 + 4;
              uVar8 = *puVar1;
            }
            uVar6 = 0xffffffffffffffff;
          }
LAB_00100b40:
          dma_free_attrs(lVar5,*(undefined8 *)(param_1 + -0x30),*(undefined8 *)(param_1 + -0x38),
                         uVar6,0);
          *(undefined8 *)(param_1 + -0x38) = 0;
        }
        else {
          _dev_err(lVar5,"unshare mem assign call failed with %d\n");
        }
      }
    }
    else if (param_2 == 6) {
      _dev_err(*puVar9,"VM: %d Crashed!\n",*param_3);
      pcVar3 = (char *)get_recovery_vm_from_vmid(*param_3);
      if (pcVar3 == (char *)0x0) {
        _dev_err(*puVar9,"Failed to get recovery vm for VM:%d!\n",*param_3);
      }
      else if (*pcVar3 == '\0') {
        if (local_54[0] == *param_3) {
          atomic_notifier_chain_unregister(&panic_notifier_list,param_1 + 0x18);
        }
                    /* WARNING: Subroutine does not return */
        panic("Resetting the SoC");
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// gh_panic_notify_receiver @ 00100bac size=148
// signature: undefined gh_panic_notify_receiver(void)
// callers: []
//------------------------------------------------------------

void gh_panic_notify_receiver(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined1 *puVar2;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar2 = *(undefined1 **)(param_2 + 0x68);
  local_40 = 1;
  gh_dbl_read_and_clean(*(undefined8 *)(param_2 + 0x90),&local_40,0x100000000);
  __pm_stay_awake(*(undefined8 *)(param_2 + 0x98));
  srcu_notifier_call_chain(&gh_panic_notifier,0,0);
  *puVar2 = 1;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// recovery_show @ 00100c44 size=168
// signature: undefined recovery_show(void)
// callers: []
//------------------------------------------------------------

long recovery_show(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  
  pcVar4 = (char *)*param_2;
  iVar2 = strcmp(pcVar4,"trustedvm_recovery");
  if (iVar2 == 0) {
    lVar3 = 0;
  }
  else {
    iVar2 = strcmp(pcVar4,"oemvm_recovery");
    if (iVar2 != 0) {
      return -0x16;
    }
    lVar3 = 1;
  }
  pcVar4 = (char *)(recovery_vms + lVar3 * 0x28);
  if (pcVar4 == (char *)0x0) {
    return -0x16;
  }
  pcVar1 = "disabled";
  if (*pcVar4 != '\0') {
    pcVar1 = "enabled";
  }
  iVar2 = sysfs_emit(param_3,&DAT_00101c47,pcVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// recovery_store @ 00100cf0 size=192
// signature: undefined recovery_store(void)
// callers: []
//------------------------------------------------------------

undefined8
recovery_store(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  undefined1 uVar3;
  long lVar4;
  char *__s1;
  undefined1 *puVar5;
  
  __s1 = (char *)*param_2;
  iVar1 = strcmp(__s1,"trustedvm_recovery");
  if (iVar1 == 0) {
    lVar4 = 0;
  }
  else {
    iVar1 = strcmp(__s1,"oemvm_recovery");
    if (iVar1 != 0) {
      return 0xffffffffffffffea;
    }
    lVar4 = 1;
  }
  puVar5 = (undefined1 *)(recovery_vms + lVar4 * 0x28);
  if (puVar5 == (undefined1 *)0x0) {
    return 0xffffffffffffffea;
  }
  uVar2 = sysfs_streq(param_3,"enabled");
  if ((uVar2 & 1) == 0) {
    uVar2 = sysfs_streq(param_3,"disabled");
    if ((uVar2 & 1) == 0) {
      return 0xffffffffffffffea;
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  *puVar5 = uVar3;
  return param_4;
}



//------------------------------------------------------------
// dma_to_phys @ 00100db0 size=72
// signature: undefined dma_to_phys(void)
// callers: [gh_panic_notifier_vm_cb]
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
// gh_panic_notifier_share_mem @ 00100df8 size=484
// signature: undefined gh_panic_notifier_share_mem(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_panic_notifier_share_mem(undefined8 *param_1,ulong param_2,ulong param_3)

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
  uStack_4c = 6;
  uStack_68 = 1L << (param_3 & 0x3f) | local_70;
  uStack_54 = 6;
  local_60[1] = 7;
  local_60[2] = local_60[0];
  iVar4 = qcom_scm_assign_mem(param_1[1],param_1[0xe],&local_70,local_60 + 2,2);
  if (iVar4 == 0) {
    puVar6 = (undefined4 *)kmalloc_trace(_of_address_to_resource,0xdc0,0xc);
    if (puVar6 == (undefined4 *)0x0) {
      iVar4 = -0xc;
    }
    else {
      puVar7 = (undefined2 *)kmalloc_trace(_of_address_to_resource,0xdc0,0x14);
      if (puVar7 == (undefined2 *)0x0) {
        kfree(puVar6);
        iVar4 = -0xc;
      }
      else {
        lVar1 = param_1[1];
        lVar2 = param_1[2];
        *puVar6 = 2;
        *(undefined1 *)((long)puVar6 + 6) = 6;
        uVar3 = *(undefined4 *)(param_1 + 0xf);
        *(undefined1 *)((long)puVar6 + 10) = 6;
        *puVar7 = 1;
        *(long *)(puVar7 + 2) = lVar1;
        *(short *)(puVar6 + 1) = (short)param_2;
        *(long *)(puVar7 + 6) = (lVar2 - lVar1) + 1;
        *(short *)(puVar6 + 2) = (short)param_3;
        iVar4 = ghd_rm_mem_share(0,0,uVar3,puVar6,puVar7,0,param_1 + 0x10);
        if (iVar4 != 0) {
          _dev_err(*param_1,"Gunyah mem share addr=%x size=%u failed: %d\n",param_1[1],param_1[0xe],
                   iVar4);
          iVar5 = qcom_scm_assign_mem(param_1[1],param_1[0xe],&uStack_68,local_60,1);
          if (iVar5 != 0) {
            _dev_err(*param_1,"qcom_scm_assign_mem addr=%x size=%u failed: %d\n",param_1[1],
                     param_1[0xe],iVar4);
          }
        }
        kfree(puVar6);
        kfree(puVar7);
      }
    }
  }
  else {
    _dev_err(*param_1,"qcom_scm_assign_mem addr=%x size=%u failed: %d\n",param_1[1],param_1[0xe],
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
// gh_panic_notifier_notify @ 00100fe0 size=656
// signature: undefined gh_panic_notifier_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gh_panic_notifier_notify(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  uint uVar8;
  char *pcVar9;
  long lVar10;
  undefined2 local_64 [2];
  ulong local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  pcVar9 = *(char **)(param_1 + -0x50);
  local_64[0] = 0;
  if ((pcVar9 != (char *)0x0) &&
     (iVar3 = ghd_rm_get_vmid(*(undefined4 *)(param_1 + -0x3c),local_64), iVar3 == 0)) {
    local_60 = 1;
    iVar3 = gh_dbl_send(*(undefined8 *)(param_1 + -0x30),&local_60,0x100000000);
    if (iVar3 == 0) {
      iVar3 = 0x14;
LAB_00101050:
      local_60 = local_60 & 0xffffffffffffff00;
      lVar5 = irq_to_desc(0);
      if (_nr_irqs != 0) {
        uVar8 = 0;
LAB_00101090:
        if ((lVar5 != 0) && (lVar10 = *(long *)(lVar5 + 0x48), lVar10 != 0)) {
          lVar1 = lVar5 + 0x30;
          lVar6 = lVar1;
          do {
            if (*(long *)(lVar6 + 0x18) == 0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x800,0x101074);
              (*pcVar7)();
            }
            pcVar7 = *(code **)(*(long *)(lVar6 + 0x18) + 200);
            if (pcVar7 != (code *)0x0) {
              if (lVar6 != 0) {
                if (*(int *)(pcVar7 + -4) != 0x6ae77d83) {
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1010e4);
                  (*pcVar7)();
                }
                iVar4 = (*pcVar7)(lVar6,0,&local_60);
                if ((iVar4 == 0) && ((char)local_60 != '\0')) {
                  lVar6 = lVar1;
                  goto LAB_001010f8;
                }
              }
              break;
            }
            lVar6 = *(long *)(lVar6 + 0x28);
          } while (lVar6 != 0);
        }
        goto LAB_00101074;
      }
LAB_001011dc:
      iVar4 = gh_poll_vcpu_run(local_64[0]);
      if (iVar4 == 0) {
        cVar2 = *pcVar9;
        if ((cVar2 != '\0') || (iVar3 = iVar3 + -1, iVar3 == 0)) goto joined_r0x0010125c;
        goto LAB_00101050;
      }
      _printk_deferred("Failed poll vcpu run %d\n",iVar4);
      cVar2 = *pcVar9;
joined_r0x0010125c:
      if (cVar2 == '\0') {
        _printk_deferred("Notify the panic to VM fail\n");
      }
    }
    else {
      _printk_deferred("failed to raise virq to the sender %d\n",iVar3);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
  while (lVar6 = *(long *)(lVar6 + 0x28), lVar6 != 0) {
LAB_001010f8:
    if (*(long *)(lVar6 + 0x18) == 0) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x800,0x1011d8);
      (*pcVar7)();
    }
    pcVar7 = *(code **)(*(long *)(lVar6 + 0x18) + 0xd0);
    if (pcVar7 != (code *)0x0) {
      if (lVar6 != 0) {
        if (*(int *)(pcVar7 + -4) != -0x70d868ca) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101138);
          (*pcVar7)();
        }
        iVar4 = (*pcVar7)(lVar6,0,0);
        if (iVar4 == 0) goto LAB_00101174;
      }
      break;
    }
  }
  if (((*(byte *)(*(long *)(lVar5 + 0x40) + 2) >> 2 & 1) != 0) &&
     (pcVar7 = *(code **)(lVar10 + 0x48), pcVar7 != (code *)0x0)) {
    if (*(int *)(pcVar7 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101170);
      (*pcVar7)();
    }
    (*pcVar7)(lVar1);
  }
LAB_00101174:
  pcVar7 = *(code **)(lVar10 + 0x30);
  if (pcVar7 != (code *)0x0) {
    if (*(int *)(pcVar7 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101198);
      (*pcVar7)();
    }
    (*pcVar7)(lVar1);
  }
  pcVar7 = *(code **)(lVar10 + 0x20);
  if ((pcVar7 != (code *)0x0) && ((*(byte *)(*(long *)(lVar5 + 0x40) + 2) & 1) == 0)) {
    if (*(int *)(pcVar7 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1011cc);
      (*pcVar7)();
    }
    (*pcVar7)(lVar1);
  }
LAB_00101074:
  uVar8 = uVar8 + 1;
  lVar5 = irq_to_desc(uVar8);
  if (_nr_irqs <= uVar8) goto LAB_001011dc;
  goto LAB_00101090;
}



//------------------------------------------------------------
// get_recovery_vm_from_vmid @ 00101274 size=176
// signature: undefined get_recovery_vm_from_vmid(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

void get_recovery_vm_from_vmid(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar2 = gh_rm_get_vm_name(param_1,&local_2c);
  if (iVar2 == 0) {
    if (local_2c == 2) {
      lVar3 = 0;
    }
    else {
      lVar3 = 0;
      if (local_2c != 4) goto LAB_001012dc;
      lVar3 = 1;
    }
    lVar3 = recovery_vms + lVar3 * 0x28;
  }
  else {
    _printk(&DAT_00101d7e,(uint)param_1 & 0xffff,iVar2);
    lVar3 = 0;
  }
LAB_001012dc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101364 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gh_panic_notifier_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101394 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gh_panic_notifier_driver);
  return;
}



//------------------------------------------------------------
// srcu_notifier_chain_register @ 00104000 size=1
// signature: undefined srcu_notifier_chain_register(void)
// callers: [gh_panic_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_unregister @ 00104008 size=1
// signature: undefined srcu_notifier_chain_unregister(void)
// callers: [gh_panic_notifier_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104010 size=1
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
// platform_driver_unregister @ 00104018 size=1
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
// devm_kmalloc @ 00104020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104030 size=1
// signature: undefined of_find_property(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00104038 size=1
// signature: undefined dma_set_mask(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00104040 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00104048 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_tx_register @ 00104050 size=1
// signature: undefined gh_dbl_tx_register(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_tx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104060 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_panic_notifier_probe, gh_panic_notifier_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00104068 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_register_vm_notifier @ 00104070 size=1
// signature: undefined gh_register_vm_notifier(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_register_vm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00104078 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104080 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00104088 size=1
// signature: undefined of_address_to_resource(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_request_region @ 00104098 size=1
// signature: undefined __devm_request_region(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_request_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_wc @ 001040a0 size=1
// signature: undefined devm_ioremap_wc(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_wc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_register @ 001040a8 size=1
// signature: undefined gh_dbl_rx_register(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 001040b0 size=1
// signature: undefined wakeup_source_register(void)
// callers: [gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_tx_unregister @ 001040b8 size=1
// signature: undefined gh_dbl_tx_unregister(void)
// callers: [gh_panic_notifier_probe, gh_panic_notifier_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_tx_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001040c0 size=1
// signature: undefined _dev_err(void)
// callers: [gh_panic_notifier_vm_cb, gh_panic_notifier_probe, gh_panic_notifier_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040c8 size=1
// signature: undefined _printk(void)
// callers: [get_recovery_vm_from_vmid, gh_panic_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040d0 size=1
// signature: undefined kfree(void)
// callers: [gh_panic_notifier_probe, gh_panic_notifier_remove, gh_panic_notifier_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_rx_unregister @ 001040d8 size=1
// signature: undefined gh_dbl_rx_unregister(void)
// callers: [gh_panic_notifier_probe, gh_panic_notifier_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_rx_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040e0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_panic_notify_receiver, gh_panic_notifier_vm_cb, get_recovery_vm_from_vmid, gh_panic_notifier_probe, gh_panic_notifier_notify, gh_panic_notifier_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_unregister_vm_notifier @ 001040e8 size=1
// signature: undefined gh_unregister_vm_notifier(void)
// callers: [gh_panic_notifier_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_unregister_vm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 001040f0 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [gh_panic_notifier_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 001040f8 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_panic_notifier_vm_cb, gh_panic_notifier_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00104108 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00104110 size=1
// signature: noreturn undefined panic(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00104118 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00104120 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 00104128 size=1
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00104130 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [gh_panic_notifier_vm_cb, gh_panic_notifier_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00104138 size=1
// signature: undefined dma_free_attrs(void)
// callers: [gh_panic_notifier_vm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_read_and_clean @ 00104140 size=1
// signature: undefined gh_dbl_read_and_clean(void)
// callers: [gh_panic_notify_receiver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_read_and_clean(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_stay_awake @ 00104148 size=1
// signature: undefined __pm_stay_awake(void)
// callers: [gh_panic_notify_receiver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_call_chain @ 00104150 size=1
// signature: undefined srcu_notifier_call_chain(void)
// callers: [gh_panic_notify_receiver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104158 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [recovery_show, recovery_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00104160 size=1
// signature: undefined sysfs_emit(void)
// callers: [recovery_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_streq @ 00104168 size=1
// signature: undefined sysfs_streq(void)
// callers: [recovery_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_streq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 00104170 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [gh_panic_notifier_share_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_dbl_send @ 00104178 size=1
// signature: undefined gh_dbl_send(void)
// callers: [gh_panic_notifier_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_dbl_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_to_desc @ 00104188 size=1
// signature: undefined irq_to_desc(void)
// callers: [gh_panic_notifier_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_poll_vcpu_run @ 00104190 size=1
// signature: undefined gh_poll_vcpu_run(void)
// callers: [gh_panic_notifier_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_poll_vcpu_run(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk_deferred @ 00104198 size=1
// signature: undefined _printk_deferred(void)
// callers: [gh_panic_notifier_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk_deferred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_get_vm_name @ 001041a0 size=1
// signature: undefined gh_rm_get_vm_name(void)
// callers: [get_recovery_vm_from_vmid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_get_vm_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



