// Decompiled by Ghidra 12.2
// Program: coresight-tmc-sec.ko
// Image base: 00100000

//------------------------------------------------------------
// enable_secure_etr_sink @ 001003bc size=796
// signature: undefined enable_secure_etr_sink(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int enable_secure_etr_sink(long param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  void *__s;
  undefined8 *puVar8;
  int *piVar9;
  undefined8 uVar10;
  ulong uVar11;
  undefined8 *puVar12;
  ulong *local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  puVar12 = *(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98);
  mutex_lock(puVar12 + 0x18);
  if (*(char *)((long)puVar12 + 0xf4) != '\0') {
LAB_00100408:
    iVar6 = -0x10;
    goto LAB_0010062c;
  }
  if (*(int *)(puVar12 + 0x1f) == 1) {
    piVar9 = *(int **)(param_1 + 0x3c8);
    Hint_Prefetch(piVar9,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar9,0x10);
      if (bVar3) {
        *piVar9 = *piVar9 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    iVar6 = 0;
    goto LAB_0010062c;
  }
  uVar5 = hashlen_string(0,puVar12[0x15]);
  local_70 = (ulong *)CONCAT44(local_70._4_4_,uVar5);
  lVar7 = bus_find_device(*(undefined8 *)(puVar12[1] + 0xb8),0,&local_70,coresight_sink_by_id);
  if ((lVar7 == 0) || (lVar7 = *(long *)(*(long *)(lVar7 + 0x60) + 0x98), lVar7 == 0)) {
    _dev_info(*puVar12,"real_sink config error\n");
    iVar6 = -0x16;
    goto LAB_0010062c;
  }
  if (*(int *)(lVar7 + 0x84) - 1U < 2) {
    _dev_info(*puVar12,"%s is enabled, please disable it\n",puVar12[0x15]);
    goto LAB_00100408;
  }
  uVar10 = puVar12[0x24];
  iVar6 = clk_prepare(uVar10);
  if (iVar6 != 0) goto LAB_0010062c;
  iVar6 = clk_enable(uVar10);
  if (iVar6 == 0) {
    local_68 = 0;
    local_60 = 0;
    local_70 = (ulong *)0x0;
    __s = (void *)dmam_alloc_attrs(*puVar12,*(undefined4 *)((long)puVar12 + 0x11c),&local_60,0xcc0,0
                                  );
    if (__s != (void *)0x0) {
      dma_get_sgtable_attrs
                (*puVar12,&local_70,__s,local_60,*(undefined4 *)((long)puVar12 + 0x11c),0);
      uVar4 = _memstart_addr;
      uVar11 = *local_70;
      sg_free_table(&local_70);
      memset(__s,0,(ulong)*(uint *)((long)puVar12 + 0x11c));
      puVar8 = (undefined8 *)devm_kmalloc(*puVar12,0x18,0xdc0);
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = __s;
        uVar1 = *(uint *)((long)puVar12 + 0x11c);
        puVar8[1] = ((uVar11 & 0x3fffffffffffffc) + (uVar4 >> 0xc) * 0x40) * 0x40 + 0x8000000000;
        puVar8[2] = (ulong)uVar1;
        puVar12[0x20] = puVar8;
        local_70 = (ulong *)0x60000000f;
        local_60 = 8;
        qcom_scm_assign_mem(puVar8[1],puVar8[2],&local_60,&local_70,1);
        iVar6 = remote_etm_etr_assign
                          (*(undefined4 *)(puVar12 + 0x17),2,1,*(undefined8 *)(puVar12[0x20] + 8),
                           *(undefined8 *)(puVar12[0x20] + 0x10));
        if (iVar6 == 0) {
          _dev_info(*puVar12,"modem etr enable\n");
          *(undefined4 *)(puVar12 + 0x1f) = 1;
          *(undefined4 *)(lVar7 + 0x84) = 3;
          puVar12[0x16] = lVar7;
          piVar9 = *(int **)(param_1 + 0x3c8);
          Hint_Prefetch(piVar9,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar9,0x10);
            if (bVar3) {
              *piVar9 = *piVar9 + 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          iVar6 = 0;
          goto LAB_0010062c;
        }
        local_70 = (ulong *)0x700000003;
        local_60 = 0x8000;
        qcom_scm_assign_mem(*(undefined8 *)(puVar12[0x20] + 8),*(undefined8 *)(puVar12[0x20] + 0x10)
                            ,&local_60,&local_70,1);
        puVar8 = (undefined8 *)puVar12[0x20];
        dmam_free_coherent(*puVar12,puVar8[2],*puVar8,puVar8[1]);
        uVar10 = puVar12[0x24];
        clk_disable(uVar10);
        goto LAB_001004ac;
      }
    }
    uVar10 = puVar12[0x24];
    clk_disable(uVar10);
    clk_unprepare(uVar10);
    iVar6 = -0xc;
  }
  else {
LAB_001004ac:
    clk_unprepare(uVar10);
  }
LAB_0010062c:
  mutex_unlock(puVar12 + 0x18);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// disable_secure_etr_sink @ 001006fc size=340
// signature: undefined disable_secure_etr_sink(void)
// callers: []
//------------------------------------------------------------

int disable_secure_etr_sink(long param_1)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar7 = *(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98);
  mutex_lock(puVar7 + 0x18);
  if (*(char *)((long)puVar7 + 0xf4) == '\0') {
    piVar5 = *(int **)(param_1 + 0x3c8);
    Hint_Prefetch(piVar5,2,0,1);
    do {
      iVar4 = *piVar5;
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(piVar5,0x10);
      if (bVar2) {
        *piVar5 = iVar4 + -1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar4 + -1 == 0) {
      iVar4 = remote_etm_etr_assign
                        (*(undefined4 *)(puVar7 + 0x17),1,1,*(undefined8 *)(puVar7[0x20] + 8),
                         *(undefined8 *)(puVar7[0x20] + 0x10));
      if (iVar4 != 0) {
        _dev_err(*puVar7,"assign etr to apss fail\n");
      }
      local_48 = 0x8000;
      uStack_40 = 0x700000003;
      qcom_scm_assign_mem(*(undefined8 *)(puVar7[0x20] + 8),*(undefined8 *)(puVar7[0x20] + 0x10),
                          &local_48,&uStack_40,1);
      puVar6 = (undefined8 *)puVar7[0x20];
      dmam_free_coherent(*puVar7,puVar6[2],*puVar6,puVar6[1]);
      _dev_info(*puVar7,"disable modem etr\n");
      *(undefined4 *)(puVar7 + 0x1f) = 0;
      if (puVar7[0x16] != 0) {
        *(undefined4 *)(puVar7[0x16] + 0x84) = 0;
        puVar7[0x16] = 0;
      }
      goto LAB_0010075c;
    }
  }
  iVar4 = -0x10;
LAB_0010075c:
  uVar8 = puVar7[0x24];
  clk_disable(uVar8);
  clk_unprepare(uVar8);
  mutex_unlock(puVar7 + 0x18);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// coresight_sink_by_id @ 00100864 size=56
// signature: undefined coresight_sink_by_id(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_sink_by_id(long param_1,int *param_2)

{
  if ((((*(uint *)(param_1 + -0x30) | 2) == 2) && (*(long *)(param_1 + 0x3a0) != 0)) &&
     (*param_2 == *(int *)(*(long *)(param_1 + 0x3a0) + 0x20))) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// secure_etr_probe @ 001008a0 size=684
// signature: undefined secure_etr_probe(void)
// callers: []
//------------------------------------------------------------

ulong secure_etr_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 local_a0;
  undefined8 local_98;
  undefined **local_90;
  ulong local_88;
  long lStack_80;
  undefined **local_78;
  long local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = (undefined **)0x0;
  local_70 = 0;
  local_88 = 0;
  lStack_80 = 0;
  local_98 = 0;
  local_90 = (undefined **)0x0;
  local_a0 = 0;
  plVar6 = (long *)devm_kmalloc(lVar1,0x128,0xdc0);
  if (plVar6 != (long *)0x0) {
    *plVar6 = lVar1;
    *(long **)(param_1 + 0xa8) = plVar6;
    uVar7 = coresight_get_platform_data(lVar1);
    uVar8 = dma_set_mask(lVar1,0xffffffffffffffff);
    if ((int)uVar8 == 0) {
      dma_set_coherent_mask(lVar1,0xffffffffffffffff);
    }
    else {
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) goto LAB_00100aa4;
    }
    if (0xfffffffffffff000 < uVar7) {
      uVar9 = uVar7 & 0xffffffff;
      goto LAB_00100aa4;
    }
    *(ulong *)(param_1 + 0xa0) = uVar7;
    *(undefined4 *)(plVar6 + 0x1e) = 0;
    __mutex_init(plVar6 + 0x18,"&drvdata->mem_lock",&secure_etr_probe___key);
    uVar8 = devm_clk_get(lVar1,"apb_pclk");
    plVar6[0x24] = uVar8;
    if (0xfffffffffffff000 < uVar8) {
      _dev_err(lVar1,"not config clk\n");
    }
    uVar8 = of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"real-name",plVar6 + 0x15);
    uVar9 = uVar8 & 0xffffffff;
    if ((int)uVar8 != 0) goto LAB_00100aa4;
    uVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qdss,support-remote-etm",plVar6 + 0x17,1,0)
    ;
    uVar2 = uVar4;
    if (-1 < (int)uVar4) {
      uVar2 = 0;
    }
    uVar9 = (ulong)uVar2;
    if ((int)uVar4 < 0) goto LAB_00100aa4;
    uVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qdss,buffer-size",(long)plVar6 + 0x11c,1,0)
    ;
    uVar2 = uVar4;
    if (-1 < (int)uVar4) {
      uVar2 = 0;
    }
    uVar9 = (ulong)uVar2;
    if ((int)uVar4 < 0) goto LAB_00100aa4;
    iVar5 = of_get_coresight_csr_name(*(undefined8 *)(param_1 + 0x2f8),plVar6 + 0x22);
    if (iVar5 == 0) {
      uVar8 = coresight_csr_get(plVar6[0x22]);
      plVar6[0x21] = uVar8;
      if (0xfffffffffffff000 < uVar8) {
        _dev_err(lVar1,"failed to get csr, defer probe\n");
        uVar9 = 0xfffffdfb;
        goto LAB_00100aa4;
      }
    }
    else {
      _dev_err(lVar1,"No csr data\n");
    }
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"csr-atid-offset",plVar6 + 0x23,1,0);
    uVar8 = secure_etr_map_memory(plVar6);
    uVar9 = uVar8 & 0xffffffff;
    if ((int)uVar8 != 0) goto LAB_00100aa4;
    local_70 = coresight_alloc_device_name(secure_etr_devs,lVar1);
    if (local_70 != 0) {
      local_a0 = 0x200000000;
      local_90 = &secure_etr_cs_ops;
      local_78 = &coresight_secure_etr_groups;
      local_88 = uVar7;
      lStack_80 = lVar1;
      uVar9 = coresight_register(&local_a0);
      plVar6[1] = uVar9;
      if (uVar9 < 0xfffffffffffff001) {
        plVar6[2] = local_70;
        uVar7 = sec_etr_sram_dev_register(plVar6);
        uVar9 = uVar7 & 0xffffffff;
        if ((int)uVar7 == 0) {
          pm_runtime_enable(lVar1);
        }
        else {
          coresight_unregister(plVar6[1]);
        }
      }
      goto LAB_00100aa4;
    }
  }
  uVar9 = 0xfffffff4;
LAB_00100aa4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// secure_etr_remove @ 00100b50 size=108
// signature: undefined secure_etr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 secure_etr_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  __pm_runtime_disable(param_1 + 0x10,1);
  device_destroy(*(undefined8 *)(lVar1 + 0xa0),*(undefined4 *)(lVar1 + 0x98));
  class_destroy(*(undefined8 *)(lVar1 + 0xa0));
  cdev_del(lVar1 + 0x18);
  unregister_chrdev_region(*(undefined4 *)(lVar1 + 0x98),1);
  coresight_unregister(*(undefined8 *)(lVar1 + 8));
  return 0;
}



//------------------------------------------------------------
// secure_etr_map_memory @ 00100bbc size=208
// signature: undefined secure_etr_map_memory(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

void secure_etr_map_memory(long *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long local_78 [11];
  
  lVar3 = sp_el0;
  local_78[10] = *(long *)(lVar3 + 0x638);
  lVar3 = *param_1;
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
                    (*(undefined8 *)(lVar3 + 0x2e8),"memory-region",0,0,0,local_78);
  iVar2 = -0x13;
  if ((iVar1 == 0) && (local_78[0] != 0)) {
    iVar1 = of_reserved_mem_device_init_by_idx(lVar3,*(undefined8 *)(lVar3 + 0x2e8),0);
    iVar2 = 0;
    if (iVar1 != 0) {
      _dev_err(lVar3,"Failed to initialize reserved mem, ret %d\n",iVar1);
      iVar2 = iVar1;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// sec_etr_sram_dev_register @ 00100c8c size=292
// signature: undefined sec_etr_sram_dev_register(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

ulong sec_etr_sram_dev_register(long param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar2 = alloc_chrdev_region(&local_3c,0,1,*(undefined8 *)(param_1 + 0x10));
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 0) {
    lVar1 = param_1 + 0x18;
    cdev_init(lVar1,&secure_etr_fops);
    *(undefined1 **)(param_1 + 0x78) = &__this_module;
    uVar2 = cdev_add(lVar1,local_3c,1);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      uVar3 = __class_create(&__this_module,*(undefined8 *)(param_1 + 0x10),
                             &sec_etr_sram_dev_register___key);
      *(ulong *)(param_1 + 0xa0) = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        uVar3 = device_create(uVar3,0,*(undefined4 *)(param_1 + 0x98),param_1,
                              *(undefined8 *)(param_1 + 0x10));
        if (uVar3 < 0xfffffffffffff001) {
          uVar3 = 0;
          goto LAB_00100d74;
        }
        class_destroy(*(undefined8 *)(param_1 + 0xa0));
      }
      cdev_del(lVar1);
    }
    unregister_chrdev_region(*(undefined4 *)(param_1 + 0x98),1);
  }
LAB_00100d74:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// buffer_size_show @ 00100db4 size=64
// signature: undefined buffer_size_show(void)
// callers: []
//------------------------------------------------------------

long buffer_size_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010179d,
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x11c));
  return (long)iVar1;
}



//------------------------------------------------------------
// secure_etr_read @ 00100df8 size=420
// signature: undefined secure_etr_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong secure_etr_read(long param_1,ulong param_2,ulong param_3,ulong *param_4)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  
  lVar1 = *(long *)(param_1 + 0xd8) + 0xc0;
  plVar8 = *(long **)(*(long *)(param_1 + 0xd8) + 0x100);
  mutex_lock(lVar1);
  uVar4 = *param_4;
  uVar6 = plVar8[2];
  uVar7 = uVar6 - uVar4;
  if (!CARRY8(uVar4,param_3) && uVar4 + param_3 <= uVar6) {
    uVar7 = param_3;
  }
  if (uVar7 != 0) {
    if (uVar7 >> 0x1f != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100f84);
      (*pcVar2)();
    }
    lVar3 = *plVar8 + uVar4;
    __check_object_size(lVar3,uVar7,1);
    puVar5 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar4 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar4 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar4 <= 0x8000000000 - uVar7) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        puVar5 = (undefined8 *)puVar5[1];
        uVar6 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      lVar3 = __arch_copy_to_user(puVar5,param_2 & 0xff7fffffffffffff,lVar3,uVar7);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        uVar6 = ttbr1_el1;
        ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      if (lVar3 == 0) {
        *param_4 = *param_4 + uVar7;
        goto LAB_00100f48;
      }
    }
    uVar7 = 0xfffffffffffffff2;
  }
LAB_00100f48:
  mutex_unlock(lVar1);
  return uVar7;
}



//------------------------------------------------------------
// secure_etr_open @ 00100fbc size=276
// signature: undefined secure_etr_open(void)
// callers: []
//------------------------------------------------------------

int secure_etr_open(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar3 = *(long *)(param_1 + 0x290);
  lVar1 = lVar3 + 0xa8;
  mutex_lock(lVar1);
  if (*(char *)(lVar3 + 0xdc) == '\0') {
    if (*(int *)(lVar3 + 0xe0) == 1) {
      iVar2 = remote_etm_etr_assign
                        (*(undefined4 *)(lVar3 + 0xa0),1,1,
                         *(undefined8 *)(*(long *)(lVar3 + 0xe8) + 8),
                         *(undefined8 *)(*(long *)(lVar3 + 0xe8) + 0x10));
      if (iVar2 == 0) {
        local_58 = 0x8000;
        uStack_50 = 0x700000003;
        qcom_scm_assign_mem(*(undefined8 *)(*(long *)(lVar3 + 0xe8) + 8),
                            *(undefined8 *)(*(long *)(lVar3 + 0xe8) + 0x10),&local_58,&uStack_50,1);
        *(undefined1 *)(lVar3 + 0xdc) = 1;
        *(long *)(param_2 + 0xd8) = lVar3 + -0x18;
        mutex_unlock(lVar1);
        nonseekable_open(param_1,param_2);
        iVar2 = 0;
        goto LAB_00101098;
      }
    }
    else {
      iVar2 = -0x16;
    }
  }
  else {
    iVar2 = -0x10;
  }
  mutex_unlock(lVar1);
LAB_00101098:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// secure_etr_release @ 001010d4 size=204
// signature: undefined secure_etr_release(void)
// callers: []
//------------------------------------------------------------

int secure_etr_release(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_2 + 0xd8);
  mutex_lock(lVar2 + 0xc0);
  local_48 = 8;
  uStack_40 = 0x60000000f;
  qcom_scm_assign_mem(*(undefined8 *)(*(long *)(lVar2 + 0x100) + 8),
                      *(undefined8 *)(*(long *)(lVar2 + 0x100) + 0x10),&local_48,&uStack_40,1);
  iVar1 = remote_etm_etr_assign
                    (*(undefined4 *)(lVar2 + 0xb8),2,1,*(undefined8 *)(*(long *)(lVar2 + 0x100) + 8)
                     ,*(undefined8 *)(*(long *)(lVar2 + 0x100) + 0x10));
  if (iVar1 == 0) {
    iVar1 = remote_etm_reenable(*(undefined4 *)(lVar2 + 0xb8));
    if (iVar1 == 0) {
      *(undefined1 *)(lVar2 + 0xf4) = 0;
    }
  }
  mutex_unlock(lVar2 + 0xc0);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 001011cc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&secure_etr_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001011fc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&secure_etr_driver);
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
// mutex_lock @ 00103010 size=1
// signature: undefined mutex_lock(void)
// callers: [secure_etr_open, enable_secure_etr_sink, secure_etr_release, secure_etr_read, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hashlen_string @ 00103020 size=1
// signature: undefined hashlen_string(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hashlen_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_find_device @ 00103028 size=1
// signature: undefined bus_find_device(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_find_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00103030 size=1
// signature: undefined clk_prepare(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00103038 size=1
// signature: undefined clk_enable(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00103040 size=1
// signature: undefined clk_unprepare(void)
// callers: [enable_secure_etr_sink, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_alloc_attrs @ 00103048 size=1
// signature: undefined dmam_alloc_attrs(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_sgtable_attrs @ 00103050 size=1
// signature: undefined dma_get_sgtable_attrs(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_sgtable_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 00103060 size=1
// signature: undefined sg_free_table(void)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00103068 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103070 size=1
// signature: undefined devm_kmalloc(void)
// callers: [secure_etr_probe, enable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00103078 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [secure_etr_open, enable_secure_etr_sink, secure_etr_release, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remote_etm_etr_assign @ 00103080 size=1
// signature: undefined remote_etm_etr_assign(void)
// callers: [secure_etr_open, enable_secure_etr_sink, secure_etr_release, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remote_etm_etr_assign(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_free_coherent @ 00103088 size=1
// signature: undefined dmam_free_coherent(void)
// callers: [enable_secure_etr_sink, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_free_coherent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00103090 size=1
// signature: undefined clk_disable(void)
// callers: [enable_secure_etr_sink, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103098 size=1
// signature: undefined _dev_info(void)
// callers: [enable_secure_etr_sink, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001030a0 size=1
// signature: undefined mutex_unlock(void)
// callers: [secure_etr_open, enable_secure_etr_sink, secure_etr_release, secure_etr_read, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [secure_etr_probe, secure_etr_open, enable_secure_etr_sink, secure_etr_release, secure_etr_map_memory, sec_etr_sram_dev_register, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030b0 size=1
// signature: undefined _dev_err(void)
// callers: [secure_etr_probe, secure_etr_map_memory, disable_secure_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 001030b8 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 001030c0 size=1
// signature: undefined dma_set_mask(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 001030c8 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001030d0 size=1
// signature: undefined __mutex_init(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001030d8 size=1
// signature: undefined devm_clk_get(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001030e0 size=1
// signature: undefined of_property_read_string(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001030e8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_coresight_csr_name @ 001030f0 size=1
// signature: undefined of_get_coresight_csr_name(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_coresight_csr_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_csr_get @ 001030f8 size=1
// signature: undefined coresight_csr_get(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_csr_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 00103100 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00103108 size=1
// signature: undefined coresight_register(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00103110 size=1
// signature: undefined coresight_unregister(void)
// callers: [secure_etr_probe, secure_etr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00103118 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [secure_etr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00103120 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [secure_etr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00103128 size=1
// signature: undefined device_destroy(void)
// callers: [secure_etr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00103130 size=1
// signature: undefined class_destroy(void)
// callers: [secure_etr_remove, sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00103138 size=1
// signature: undefined cdev_del(void)
// callers: [secure_etr_remove, sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00103140 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [secure_etr_remove, sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103148 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [secure_etr_map_memory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00103150 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [secure_etr_map_memory]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00103158 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00103160 size=1
// signature: undefined cdev_init(void)
// callers: [sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00103168 size=1
// signature: undefined cdev_add(void)
// callers: [sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00103170 size=1
// signature: undefined __class_create(void)
// callers: [sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00103178 size=1
// signature: undefined device_create(void)
// callers: [sec_etr_sram_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103180 size=1
// signature: undefined scnprintf(void)
// callers: [buffer_size_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00103188 size=1
// signature: undefined __check_object_size(void)
// callers: [secure_etr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00103198 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [secure_etr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nonseekable_open @ 001031a8 size=1
// signature: undefined nonseekable_open(void)
// callers: [secure_etr_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remote_etm_reenable @ 001031b0 size=1
// signature: undefined remote_etm_reenable(void)
// callers: [secure_etr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remote_etm_reenable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



