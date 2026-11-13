// Decompiled by Ghidra 12.2
// Program: bwprof.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_bwprof_driver_probe @ 0010036c size=1124
// signature: undefined qcom_bwprof_driver_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_bwprof_driver_probe(long param_1)

{
  long lVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  char *pcVar10;
  undefined8 uVar11;
  char local_60 [24];
  long local_48;
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar7 + 0x638);
  piVar5 = (int *)of_device_get_match_data(lVar1);
  if (piVar5 == (int *)0x0) {
    iVar4 = 2;
LAB_0010066c:
    _dev_err(lVar1,"Invalid bwprof type specified: %u\n",iVar4);
    iVar4 = -0x16;
  }
  else {
    iVar4 = *piVar5;
    if (iVar4 == 1) {
      local_60[0x10] = '\0';
      local_60[0x11] = '\0';
      local_60[0x12] = '\0';
      local_60[0x13] = '\0';
      local_60[0] = '\0';
      local_60[1] = '\0';
      local_60[2] = '\0';
      local_60[3] = '\0';
      local_60[4] = '\0';
      local_60[5] = '\0';
      local_60[6] = '\0';
      local_60[7] = '\0';
      local_60[8] = '\0';
      local_60[9] = '\0';
      local_60[10] = '\0';
      local_60[0xb] = '\0';
      local_60[0xc] = '\0';
      local_60[0xd] = '\0';
      local_60[0xe] = '\0';
      local_60[0xf] = '\0';
      if (bwprof_data == (long *)0x0) {
        _dev_err(lVar1,"Missing bwprof dev data!\n");
        iVar4 = -0x13;
      }
      else {
        plVar6 = (long *)devm_kmalloc(lVar1,0xb0,0xdc0);
        if (plVar6 == (long *)0x0) goto LAB_00100684;
        *plVar6 = lVar1;
        plVar8 = (long *)platform_get_resource_byname(param_1,0x200,&DAT_001017e0);
        if (plVar8 == (long *)0x0) {
          pcVar10 = "base not found!\n";
LAB_001006e4:
          _dev_err(lVar1,pcVar10);
          iVar4 = -0x16;
        }
        else {
          lVar7 = devm_ioremap(lVar1,*plVar8,(plVar8[1] - *plVar8) + 1);
          plVar6[0xd] = lVar7;
          if (lVar7 == 0) {
            pcVar10 = "Unable map base!\n";
            goto LAB_00100730;
          }
          iVar4 = of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"client",plVar6 + 0x15);
          if (iVar4 < 0) {
            _dev_err(lVar1,"client not found!: %d\n",iVar4);
          }
          else {
            snprintf(local_60,0x14,"bwmon%d",(int)bwprof_data[0x1f]);
            plVar8 = plVar6 + 1;
            iVar4 = kobject_init_and_add(plVar8,mon_ktype,bwprof_data + 1,local_60);
            if (-1 < iVar4) {
              configure_bwmon_node(plVar6);
              mutex_lock(bwprof_lock);
              puVar2 = PTR_bwprof_list_001015a0;
              plVar8 = plVar6 + 0xe;
              uVar9 = __list_add_valid(plVar8,PTR_bwprof_list_001015a0,&bwprof_list);
              if ((uVar9 & 1) != 0) {
                PTR_bwprof_list_001015a0 = (undefined *)plVar8;
                plVar6[0xe] = (long)&bwprof_list;
                plVar6[0xf] = (long)puVar2;
                *(long **)puVar2 = plVar8;
              }
              mutex_unlock(bwprof_lock);
              iVar4 = 0;
              *(int *)(bwprof_data + 0x1f) = (int)bwprof_data[0x1f] + 1;
              goto LAB_00100798;
            }
            _dev_err(lVar1,"failed to init bwprof mon kobj: %d\n",iVar4);
LAB_00100780:
            kobject_put(plVar8);
          }
        }
      }
    }
    else {
      if (iVar4 != 0) goto LAB_0010066c;
      if (bwprof_data != (long *)0x0) {
        _dev_err(lVar1,"only one bwprof device allowed\n");
      }
      plVar6 = (long *)devm_kmalloc(lVar1,0x100,0xdc0);
      bwprof_data = plVar6;
      if (plVar6 == (long *)0x0) {
LAB_00100684:
        iVar4 = -0xc;
      }
      else {
        uVar11 = *(undefined8 *)(param_1 + 0x2f8);
        *plVar6 = lVar1;
        *(undefined4 *)(plVar6 + 0x1f) = 0;
        *(undefined4 *)(plVar6 + 0x15) = 100;
        iVar3 = of_property_read_variable_u32_array(uVar11,"qcom,bus-width",(long)plVar6 + 0xfc,1,0)
        ;
        iVar4 = iVar3;
        if (-1 < iVar3) {
          iVar4 = 0;
        }
        if ((iVar3 < 0) || (*(int *)((long)bwprof_data + 0xfc) == 0)) {
          _dev_err(lVar1,"Missing or invalid bus-width: %d\n",iVar4);
          iVar4 = -0x16;
        }
        else {
          plVar6 = (long *)platform_get_resource_byname(param_1,0x200,"mem-freq");
          if (plVar6 == (long *)0x0) {
            pcVar10 = "mem-freq not found!\n";
            goto LAB_001006e4;
          }
          lVar7 = devm_ioremap(lVar1,*plVar6,(plVar6[1] - *plVar6) + 1);
          plVar6 = bwprof_data;
          bwprof_data[0xd] = lVar7;
          if (lVar7 == 0) {
            pcVar10 = "Unable map memfreq base!\n";
          }
          else {
            hrtimer_init(plVar6 + 0x16,1,1);
            bwprof_data[0x1b] = (long)bwprof_hrtimer_handler;
            lVar7 = alloc_workqueue(&DAT_00101739,0x4000e,1,"bwprof_wq");
            plVar6 = bwprof_data;
            bwprof_data[0x14] = lVar7;
            if (lVar7 != 0) {
              plVar6[0xe] = 0xfffffffe0;
              plVar6[0xf] = (long)(plVar6 + 0xf);
              plVar6[0x10] = (long)(plVar6 + 0xf);
              uVar11 = _of_get_next_available_child;
              plVar6[0x11] = (long)bwprof_update_work;
              iVar4 = kobject_init_and_add(plVar6 + 1,&bwprof_ktype,uVar11,"bw_prof");
              if (-1 < iVar4) {
                uVar11 = *(undefined8 *)(param_1 + 0x2f8);
                lVar7 = of_get_next_available_child(uVar11,0);
                if (lVar7 != 0) {
                  iVar4 = 0;
                  do {
                    lVar7 = of_get_next_available_child(uVar11,lVar7);
                    iVar4 = iVar4 + -1;
                  } while (lVar7 != 0);
                  if (iVar4 != 0) {
                    of_platform_populate(*(undefined8 *)(param_1 + 0x2f8),0,0,lVar1);
                    iVar4 = 0;
                    goto LAB_00100798;
                  }
                }
                iVar4 = 0;
                goto LAB_00100798;
              }
              _dev_err(lVar1,"failed to init bwprof kobj: %d\n",iVar4);
              plVar8 = bwprof_data + 1;
              goto LAB_00100780;
            }
            pcVar10 = "Couldn\'t create bwprof workqueue.\n";
          }
LAB_00100730:
          _dev_err(lVar1,pcVar10);
          iVar4 = -0xc;
        }
      }
    }
    _dev_err(lVar1,"Failure to probe bwprof device: %d\n",iVar4);
  }
LAB_00100798:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// bwprof_hrtimer_handler @ 001007d4 size=92
// signature: undefined bwprof_hrtimer_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 bwprof_hrtimer_handler(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = ktime_get();
  queue_work_on(0x20,*(undefined8 *)(bwprof_data + 0xa0),bwprof_data + 0x70);
  hrtimer_forward(param_1,uVar1,50000000);
  return 1;
}



//------------------------------------------------------------
// bwprof_update_work @ 00100834 size=424
// signature: undefined bwprof_update_work(void)
// callers: []
//------------------------------------------------------------

void bwprof_update_work(void)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  long extraout_x1;
  long extraout_x1_00;
  long extraout_x1_01;
  long lVar8;
  ulong uVar9;
  uint uVar10;
  int iVar11;
  undefined **ppuVar12;
  
  puVar7 = (undefined *)ktime_get();
  mutex_lock(bwprof_lock);
  lVar8 = bwprof_data;
  uVar1 = *(uint *)(bwprof_data + 0xa8);
  iVar11 = *(int *)(bwprof_data + 0xac) + 1;
  uVar2 = iVar11 * 0x32;
  *(int *)(bwprof_data + 0xac) = iVar11;
  if (uVar2 < uVar1) {
    iVar11 = 0;
    uVar10 = 0;
    lVar8 = extraout_x1;
  }
  else {
    *(undefined4 *)(lVar8 + 0xac) = 0;
    uVar5 = readl_relaxed(*(undefined8 *)(lVar8 + 0x68));
    uVar10 = 0;
    if (uVar5 != 0) {
      uVar10 = 1000000 / uVar5;
    }
    iVar11 = *(int *)(bwprof_data + 0xfc) * uVar10;
    lVar8 = extraout_x1_00;
  }
  if ((undefined **)bwprof_list != &bwprof_list) {
    uVar4 = sp_el0;
    ppuVar12 = (undefined **)bwprof_list;
    do {
      if (*(char *)(ppuVar12 + 2) != '\0') {
        writel_relaxed(0,ppuVar12[-1] + 0x10);
        iVar6 = readl_relaxed(ppuVar12[-1] + 0x48);
        ppuVar12[6] = ppuVar12[6] + (uint)(iVar6 << 0x10);
        writel_relaxed(1,ppuVar12[-1] + 0x14);
        DataSynchronizationBarrier(3,2,0);
        writel_relaxed(0,ppuVar12[-1] + 0x14);
        writel_relaxed(960000,ppuVar12[-1] + 0x20);
        writel_relaxed(1,ppuVar12[-1] + 0x10);
        lVar8 = extraout_x1_01;
        if (uVar1 <= uVar2) {
          ppuVar12[3] = puVar7;
          iVar6 = *(int *)(bwprof_data + 0xa8);
          *(int *)((long)ppuVar12 + 0x24) = iVar11;
          *(uint *)(ppuVar12 + 5) = uVar10;
          uVar9 = (ulong)(uint)(iVar6 * 1000);
          puVar3 = (undefined *)0x0;
          if (uVar9 != 0) {
            puVar3 = (undefined *)((ulong)ppuVar12[6] / uVar9);
          }
          ppuVar12[6] = puVar3;
          *(int *)(ppuVar12 + 4) = (int)puVar3;
          lVar8 = *(long *)((long)ppuVar12[-0xe] + 0x70);
          if (lVar8 == 0) {
            lVar8 = *(long *)ppuVar12[-0xe];
          }
          ppuVar12[6] = (undefined *)0x0;
        }
      }
      ppuVar12 = (undefined **)*ppuVar12;
    } while (ppuVar12 != &bwprof_list);
  }
  mutex_unlock(bwprof_lock,lVar8);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100a48 size=124
// signature: undefined readl_relaxed(void)
// callers: [bwprof_update_work]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100a90,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00100ac4 size=132
// signature: undefined writel_relaxed(void)
// callers: [bwprof_update_work, store_mon_enabled, configure_bwmon_node]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100adc,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100b18,uVar1);
  return;
}



//------------------------------------------------------------
// attr_show @ 00100b4c size=68
// signature: undefined attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_show(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x40e7484a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100b78);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00100b94 size=68
// signature: undefined attr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_store(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5800598) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100bc0);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_sample_ms @ 00100bdc size=60
// signature: undefined show_sample_ms(void)
// callers: []
//------------------------------------------------------------

long show_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001016fc,*(undefined4 *)(bwprof_data + 0xa8));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_sample_ms @ 00100c1c size=156
// signature: undefined store_sample_ms(void)
// callers: []
//------------------------------------------------------------

long store_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,10,&local_2c);
  if (iVar2 == 0) {
    uVar3 = local_2c;
    if (local_2c < 0x65) {
      uVar3 = 100;
    }
    if (1999 < uVar3) {
      uVar3 = 2000;
    }
    *(uint *)(bwprof_data + 0xa8) = uVar3;
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// configure_bwmon_node @ 00100cb8 size=208
// signature: undefined configure_bwmon_node(void)
// callers: [store_mon_enabled, qcom_bwprof_driver_probe]
//------------------------------------------------------------

void configure_bwmon_node(long param_1)

{
  writel_relaxed(0,*(long *)(param_1 + 0x68) + 0x10);
  writel_relaxed(1,*(long *)(param_1 + 0x68) + 0x14);
  DataSynchronizationBarrier(3,2,0);
  writel_relaxed(0,*(long *)(param_1 + 0x68) + 0x14);
  writel_relaxed(960000,*(long *)(param_1 + 0x68) + 0x20);
  writel_relaxed(0xffff,*(long *)(param_1 + 0x68) + 0x24);
  writel_relaxed(0xffff,*(long *)(param_1 + 0x68) + 0x28);
  writel_relaxed(0,*(long *)(param_1 + 0x68) + 0x2c);
  writel_relaxed(0xffffffff,*(long *)(param_1 + 0x68) + 0x34);
  writel_relaxed(0,*(long *)(param_1 + 0x68) + 0x30);
  writel_relaxed(960000,*(long *)(param_1 + 0x68) + 0x20);
  return;
}



//------------------------------------------------------------
// show_mon_enabled @ 00100d8c size=56
// signature: undefined show_mon_enabled(void)
// callers: []
//------------------------------------------------------------

long show_mon_enabled(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001016fc,*(undefined1 *)(param_1 + 0x78));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_mon_enabled @ 00100dc8 size=388
// signature: undefined store_mon_enabled(void)
// callers: []
//------------------------------------------------------------

long store_mon_enabled(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined **ppuVar4;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  iVar2 = kstrtobool(param_3,local_2c);
  if (iVar2 == 0) {
    if (*(char *)(param_1 + 0x78) != local_2c[0]) {
      mutex_lock(bwprof_lock);
      *(char *)(param_1 + 0x78) = local_2c[0];
      if (local_2c[0] == '\0') {
        writel_relaxed(0,*(long *)(param_1 + 0x60) + 0x10);
        writel_relaxed(2,*(long *)(param_1 + 0x60) + 0x14);
        DataSynchronizationBarrier(3,2,0);
        writel_relaxed(0,*(long *)(param_1 + 0x60) + 0x14);
        writel_relaxed(960000,*(long *)(param_1 + 0x60) + 0x20);
        ppuVar4 = &bwprof_list;
        *(undefined8 *)(param_1 + 0x88) = 0;
        *(undefined8 *)(param_1 + 0x90) = 0;
        *(undefined8 *)(param_1 + 0x80) = 0;
        do {
          ppuVar4 = (undefined **)*ppuVar4;
          if (ppuVar4 == &bwprof_list) {
            hrtimer_cancel(bwprof_data + 0xb0);
            cancel_work_sync(bwprof_data + 0x70);
            break;
          }
        } while (*(char *)(ppuVar4 + 2) == '\0');
      }
      else {
        configure_bwmon_node(param_1 + -8);
        writel_relaxed(1,*(long *)(param_1 + 0x60) + 0x10);
        uVar3 = hrtimer_active(bwprof_data + 0xb0);
        if ((uVar3 & 1) == 0) {
          hrtimer_start_range_ns(bwprof_data + 0xb0,50000000,0,3);
        }
      }
      mutex_unlock(bwprof_lock);
    }
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_last_sample @ 00100f50 size=64
// signature: undefined show_last_sample(void)
// callers: []
//------------------------------------------------------------

long show_last_sample(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%llu\t%u\t%u\t%u\n",*(undefined8 *)(param_1 + 0x80),
                    *(undefined4 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x8c),
                    *(undefined4 *)(param_1 + 0x90));
  return (long)iVar1;
}



//------------------------------------------------------------
// show_client @ 00100f94 size=56
// signature: undefined show_client(void)
// callers: []
//------------------------------------------------------------

long show_client(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010180a,*(undefined8 *)(param_1 + 0xa0));
  return (long)iVar1;
}



//------------------------------------------------------------
// init_module @ 00100fd8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_bwprof_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101008 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_bwprof_driver);
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
// of_device_get_match_data @ 00103010 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00103028 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00103030 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 00103038 size=1
// signature: undefined hrtimer_init(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00103040 size=1
// signature: undefined alloc_workqueue(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00103050 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00103058 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00103060 size=1
// signature: undefined of_platform_populate(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00103068 size=1
// signature: undefined of_property_read_string(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103070 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103078 size=1
// signature: undefined mutex_lock(void)
// callers: [bwprof_update_work, store_mon_enabled, qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103080 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103088 size=1
// signature: undefined mutex_unlock(void)
// callers: [bwprof_update_work, store_mon_enabled, qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103090 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00103098 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_bwprof_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030a0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [store_mon_enabled, qcom_bwprof_driver_probe, store_sample_ms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001030a8 size=1
// signature: undefined ktime_get(void)
// callers: [bwprof_hrtimer_handler, bwprof_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030b0 size=1
// signature: undefined queue_work_on(void)
// callers: [bwprof_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_forward @ 001030b8 size=1
// signature: undefined hrtimer_forward(void)
// callers: [bwprof_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_forward(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001030e8 size=1
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
// log_post_read_mmio @ 001030f0 size=1
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
// log_write_mmio @ 001030f8 size=1
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
// log_post_write_mmio @ 00103100 size=1
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
// scnprintf @ 00103108 size=1
// signature: undefined scnprintf(void)
// callers: [show_sample_ms, show_client, show_last_sample, show_mon_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00103110 size=1
// signature: undefined kstrtoint(void)
// callers: [store_sample_ms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 00103118 size=1
// signature: undefined kstrtobool(void)
// callers: [store_mon_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 00103120 size=1
// signature: undefined hrtimer_active(void)
// callers: [store_mon_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 00103128 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [store_mon_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 00103130 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [store_mon_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00103138 size=1
// signature: undefined cancel_work_sync(void)
// callers: [store_mon_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



