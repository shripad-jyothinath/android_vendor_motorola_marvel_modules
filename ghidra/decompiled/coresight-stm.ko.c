// Decompiled by Ghidra 12.2
// Program: coresight-stm.ko
// Image base: 00100000

//------------------------------------------------------------
// stm_probe @ 00100594 size=980
// signature: undefined stm_probe(void)
// callers: []
//------------------------------------------------------------

ulong stm_probe(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  ulong *puVar13;
  undefined8 local_128;
  undefined8 local_120;
  undefined1 *local_118;
  ulong local_110;
  long local_108;
  undefined **local_100;
  ulong local_f8;
  undefined8 local_f0;
  ulong local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  ulong local_d0 [12];
  char *local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_d0[10] = 0;
  local_d0[0xb] = 0;
  local_d0[8] = 0;
  local_d0[9] = 0;
  local_d0[6] = 0;
  local_d0[7] = 0;
  local_d0[4] = 0;
  local_d0[5] = 0;
  local_d0[2] = 0;
  local_d0[3] = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_100 = (undefined **)0x0;
  local_f8 = 0;
  local_110 = 0;
  local_108 = 0;
  local_120 = 0;
  local_118 = (undefined1 *)0x0;
  local_128 = 0;
  uVar6 = coresight_alloc_device_name(stm_devs,param_1);
  local_f8 = uVar6;
  if ((uVar6 == 0) || (puVar7 = (ulong *)devm_kmalloc(param_1,0xb0,0xdc0), puVar7 == (ulong *)0x0))
  {
LAB_001008c0:
    uVar9 = 0xfffffff4;
    goto LAB_001008c4;
  }
  uVar8 = devm_clk_get(param_1,"atclk");
  puVar7[1] = uVar8;
  if (uVar8 < 0xfffffffffffff001) {
    uVar10 = clk_prepare();
    uVar9 = uVar10 & 0xffffffff;
    if ((int)uVar10 != 0) goto LAB_001008c4;
    uVar3 = clk_enable(uVar8);
    if (uVar3 != 0) {
      uVar9 = (ulong)uVar3;
      clk_unprepare(uVar8);
      goto LAB_001008c4;
    }
  }
  *(ulong **)(param_1 + 0x98) = puVar7;
  uVar9 = devm_ioremap_resource(param_1,param_1 + 0x390);
  if (uVar9 < 0xfffffffffffff001) {
    *puVar7 = uVar9;
    local_f0 = CONCAT71(local_f0._1_7_,1);
    local_e8 = uVar9;
    uVar8 = dev_fwnode(param_1);
    uVar9 = 0xfffffffe;
    if ((uVar8 != 0) && (uVar8 < 0xfffffffffffff001)) {
      if (*(undefined **)(uVar8 + 8) == &of_fwnode_ops) {
        uVar12 = *(undefined8 *)(param_1 + 0x2e8);
        local_70 = (char *)0x0;
        iVar4 = of_property_read_string_helper(uVar12,"reg-names",&local_70,1,0);
        if (-1 < iVar4) {
          iVar4 = 0;
          do {
            iVar5 = strcmp("stm-stimulus-base",local_70);
            if (iVar5 == 0) {
              uVar8 = of_address_to_resource(uVar12,iVar4,local_d0);
              uVar9 = uVar8 & 0xffffffff;
              if ((int)uVar8 != 0) goto LAB_001008c4;
              puVar7[5] = local_d0[0];
              uVar9 = devm_ioremap_resource(param_1,local_d0);
              if (0xfffffffffffff000 < uVar9) goto LAB_00100664;
              puVar7[4] = uVar9;
              uVar3 = boot_nr_channel;
              uVar11 = 4;
              if ((*(uint *)(*puVar7 + 0xea4) & 0xf000) != 0) {
                uVar11 = 8;
              }
              *(undefined4 *)((long)puVar7 + 0x94) = uVar11;
              if (uVar3 == 0) {
                uVar1 = *(uint *)(*puVar7 + 0xfc8) & 0x1ffff;
                uVar3 = 0x20;
                if (uVar1 != 0) {
                  uVar3 = uVar1;
                }
              }
              *(uint *)(puVar7 + 0x14) = uVar3;
              uVar8 = devm_bitmap_zalloc(param_1,uVar3,0xcc0);
              puVar7[6] = uVar8;
              if (uVar8 == 0) goto LAB_001008c0;
              *(undefined4 *)(puVar7 + 3) = 0;
              stm_init_default_data(puVar7);
              puVar13 = puVar7 + 7;
              *puVar13 = uVar6;
              puVar7[9] = 0x100000001;
              *(undefined8 *)((long)puVar7 + 0x54) = 0x100000100;
              *(int *)(puVar7 + 10) = (int)puVar7[0x14];
              puVar7[0xc] = (ulong)stm_generic_packet;
              puVar7[0xd] = (ulong)stm_mmio_addr;
              puVar7[0xe] = (ulong)stm_generic_link;
              puVar7[0xf] = (ulong)stm_generic_unlink;
              puVar7[0x10] = (ulong)stm_generic_set_options;
              iVar4 = stm_register_device(param_1,puVar13,&__this_module);
              if (iVar4 != 0) {
                _dev_info(param_1,"%s : stm_register_device failed, probing deferred\n",uVar6);
                __pm_runtime_idle(param_1,5);
                uVar9 = 0xfffffdfb;
                goto LAB_001008c4;
              }
              uVar9 = coresight_get_platform_data(param_1);
              if (uVar9 < 0xfffffffffffff001) {
                *(ulong *)(param_1 + 0x90) = uVar9;
                local_128 = 0x200000003;
                local_118 = stm_cs_ops;
                local_100 = &coresight_stm_groups;
                local_110 = uVar9;
                local_108 = param_1;
                uVar9 = coresight_register(&local_128);
                puVar7[2] = uVar9;
                if (uVar9 < 0xfffffffffffff001) {
                  __pm_runtime_idle(param_1,5);
                  if (*(long *)(param_2 + 8) == 0) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = *(undefined8 *)(*(long *)(param_2 + 8) + 0x10);
                  }
                  _dev_info(puVar7[2] + 0x38,"%s initialized\n",uVar12);
                  uVar9 = 0;
                  goto LAB_001008c4;
                }
              }
              stm_unregister_device(puVar13);
              goto LAB_001008c4;
            }
            iVar4 = iVar4 + 1;
            iVar5 = of_property_read_string_helper(uVar12,"reg-names",&local_70,1,iVar4);
          } while (-1 < iVar5);
        }
        uVar9 = 0xffffffea;
      }
      else {
        uVar9 = 0xfffffffe;
      }
    }
  }
  else {
LAB_00100664:
    uVar9 = uVar9 & 0xffffffff;
  }
LAB_001008c4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// stm_remove @ 0010096c size=52
// signature: undefined stm_remove(void)
// callers: []
//------------------------------------------------------------

void stm_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  coresight_unregister(*(undefined8 *)(lVar1 + 0x10));
  stm_unregister_device(lVar1 + 0x38);
  return;
}



//------------------------------------------------------------
// stm_freeze @ 001009a4 size=104
// signature: undefined stm_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_freeze(long param_1)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = *(long *)(param_1 + 0x98);
  coresight_disable(*(undefined8 *)(lVar1 + 0x10));
  lVar1 = *(long *)(lVar1 + 0x40);
  if (lVar1 != 0) {
    for (plVar2 = *(long **)(lVar1 + 0x418); plVar2 != (long *)(lVar1 + 0x418);
        plVar2 = (long *)*plVar2) {
      __pm_runtime_suspend(lVar1,0xd);
    }
  }
  return 0;
}



//------------------------------------------------------------
// stm_restore @ 00100a10 size=96
// signature: undefined stm_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_restore(long param_1)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x40);
  if (lVar1 != 0) {
    for (plVar2 = *(long **)(lVar1 + 0x418); plVar2 != (long *)(lVar1 + 0x418);
        plVar2 = (long *)*plVar2) {
      __pm_runtime_resume(lVar1,5);
    }
  }
  return 0;
}



//------------------------------------------------------------
// stm_runtime_suspend @ 00100a74 size=72
// signature: undefined stm_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_runtime_suspend(long param_1)

{
  ulong uVar1;
  
  if ((*(long *)(param_1 + 0x98) != 0) &&
     (uVar1 = *(ulong *)(*(long *)(param_1 + 0x98) + 8), uVar1 < 0xfffffffffffff001)) {
    clk_disable(uVar1);
    clk_unprepare(uVar1);
  }
  return 0;
}



//------------------------------------------------------------
// stm_runtime_resume @ 00100ac0 size=88
// signature: undefined stm_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_runtime_resume(long param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((((*(long *)(param_1 + 0x98) != 0) &&
       (uVar2 = *(ulong *)(*(long *)(param_1 + 0x98) + 8), uVar2 < 0xfffffffffffff001)) &&
      (iVar1 = clk_prepare(uVar2), iVar1 == 0)) && (iVar1 = clk_enable(uVar2), iVar1 != 0)) {
    clk_unprepare(uVar2);
  }
  return 0;
}



//------------------------------------------------------------
// stm_init_default_data @ 00100b18 size=60
// signature: undefined stm_init_default_data(void)
// callers: [stm_probe]
//------------------------------------------------------------

void stm_init_default_data(long param_1)

{
  *(undefined8 *)(param_1 + 0x98) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x90) = 1;
  __bitmap_clear(*(undefined8 *)(param_1 + 0x30),0,*(undefined4 *)(param_1 + 0xa0));
  return;
}



//------------------------------------------------------------
// stm_generic_packet @ 00100b58 size=424
// signature: undefined stm_generic_packet(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

ulong stm_generic_packet(long param_1,undefined8 param_2,ulong param_3,int param_4,uint param_5,
                        uint param_6,undefined8 *param_7)

{
  long lVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  ulong __n;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((param_1 == 0x38) || (*(long *)(param_1 + 0x50) == 0)) {
    __n = 0xfffffffffffffff3;
  }
  else if ((uint)param_3 < *(uint *)(param_1 + 0x68)) {
    lVar1 = *(long *)(param_1 + -0x18) + (ulong)((uint)param_3 << 8);
    uVar5 = *(uint *)(param_1 + 0x5c);
    uVar4 = (ulong)uVar5;
    uVar3 = (param_5 & 2) << 2 |
            ((uint)(*(ulong *)(*(long *)(param_1 + -8) + ((param_3 & 0xffffffff) >> 3 & 0x1ffffff8))
                   >> (param_3 & 0x3f)) & 1) << 7;
    if (param_6 <= uVar5) {
      uVar5 = (uint)(1L << ((ulong)~(uint)LZCOUNT((ulong)param_6) & 0x3f));
    }
    __n = (ulong)uVar5;
    if (param_4 == 0) {
      local_40 = 0;
      if (((uVar4 & 0xff) - 1 & (ulong)param_7) != 0) {
        if (8 < uVar5) {
          fortify_panic("memcpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        memcpy(&local_40,param_7,__n);
        param_7 = &local_40;
      }
      if (uVar5 - 1 < 8) {
        puVar2 = (undefined8 *)(lVar1 + (ulong)((uVar3 | (param_5 & 1) << 4) ^ 0x98));
        switch(uVar5) {
        case 1:
          *(undefined1 *)puVar2 = *(undefined1 *)param_7;
          break;
        case 2:
          *(undefined2 *)puVar2 = *(undefined2 *)param_7;
          break;
        case 4:
          *(undefined4 *)puVar2 = *(undefined4 *)param_7;
          break;
        case 8:
          *puVar2 = *param_7;
        }
      }
    }
    else if (param_4 == 1) {
      __n = 1;
      *(undefined1 *)(lVar1 + (ulong)(uVar3 ^ 0xe8)) = *(undefined1 *)param_7;
    }
    else {
      __n = 0xfffffffffffffdf4;
    }
  }
  else {
    __n = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __n;
}



//------------------------------------------------------------
// stm_mmio_addr @ 00100d04 size=32
// signature: undefined stm_mmio_addr(void)
// callers: []
//------------------------------------------------------------

ulong stm_mmio_addr(long param_1,undefined8 param_2,int param_3,uint param_4)

{
  ulong uVar1;
  
  uVar1 = *(long *)(param_1 + -0x10) + (ulong)(uint)(param_3 << 8);
  if ((uVar1 & 0xfff) != 0 || (param_4 & 0xf) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// stm_generic_link @ 00100d28 size=52
// signature: undefined stm_generic_link(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_generic_link(long param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0x38) || (*(long *)(param_1 + -0x28) == 0)) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = coresight_enable();
  }
  return uVar1;
}



//------------------------------------------------------------
// stm_generic_unlink @ 00100d60 size=44
// signature: undefined stm_generic_unlink(void)
// callers: []
//------------------------------------------------------------

void stm_generic_unlink(long param_1)

{
  if ((param_1 != 0x38) && (*(long *)(param_1 + -0x28) != 0)) {
    coresight_disable();
  }
  return;
}



//------------------------------------------------------------
// stm_generic_set_options @ 00100d90 size=160
// signature: undefined stm_generic_set_options(void)
// callers: []
//------------------------------------------------------------

undefined8
stm_generic_set_options
          (long param_1,undefined8 param_2,uint param_3,undefined8 param_4,long param_5)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  if (((param_1 != 0x38) && (*(long *)(param_1 + 0x50) != 0)) &&
     (param_3 < *(uint *)(param_1 + 0x68))) {
    if (param_5 == 1) {
      puVar1 = (ulong *)(*(long *)(param_1 + -8) + (ulong)(param_3 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & (1L << ((ulong)param_3 & 0x3f) ^ 0xffffffffffffffffU);
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      return 0;
    }
    if (param_5 == 0) {
      puVar1 = (ulong *)(*(long *)(param_1 + -8) + (ulong)(param_3 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 1L << ((ulong)param_3 & 0x3f);
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      return 0;
    }
  }
  return 0xffffffffffffffea;
}



//------------------------------------------------------------
// stm_trace_id @ 00100e54 size=16
// signature: undefined stm_trace_id(void)
// callers: []
//------------------------------------------------------------

undefined1 stm_trace_id(long param_1)

{
  return *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0x98) + 0x90);
}



//------------------------------------------------------------
// stm_enable @ 00100e68 size=524
// signature: undefined stm_enable(void)
// callers: []
//------------------------------------------------------------

int stm_enable(long param_1,undefined8 param_2,int param_3)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  long *plVar9;
  
  if (param_3 == 1) {
    plVar9 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
    plVar1 = plVar9 + 0x11;
    Hint_Prefetch(plVar1,2,0,1);
    do {
      lVar7 = *plVar1;
      if (lVar7 != 0) goto LAB_00100efc;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar5) {
        *plVar1 = 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
LAB_00100efc:
    if ((int)lVar7 == 0) {
      iVar6 = __pm_runtime_resume(*(undefined8 *)(param_1 + 0x98),4);
      if (iVar6 < 0) {
        piVar2 = (int *)(*(long *)(param_1 + 0x98) + 0x1f8);
        iVar8 = *(int *)(*(long *)(param_1 + 0x98) + 0x1f8);
        do {
          if (iVar8 == 0) {
            return iVar6;
          }
          Hint_Prefetch(piVar2,2,0,1);
          do {
            iVar3 = *piVar2;
            if (iVar3 != iVar8) goto LAB_00101070;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar5) {
              *piVar2 = iVar8 + -1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          DataMemoryBarrier(2,3);
LAB_00101070:
          bVar5 = iVar8 != iVar3;
          iVar8 = iVar3;
        } while (bVar5);
      }
      else {
        _raw_spin_lock(plVar9 + 3);
        if (*(int *)((long)plVar9 + 0xa4) != 0) {
          *(undefined4 *)(*plVar9 + 0xfb0) = 0xc5acce55;
          DataSynchronizationBarrier(3,3,0);
          *(undefined4 *)(*plVar9 + 0xd60) = *(undefined4 *)((long)plVar9 + 0xac);
          *(int *)(*plVar9 + 0xd20) = (int)plVar9[0x15];
          *(undefined4 *)(*plVar9 + 0xd00) = *(undefined4 *)((long)plVar9 + 0xa4);
          *(undefined4 *)(*plVar9 + 0xd64) = 5;
          DataSynchronizationBarrier(3,3,0);
          *(undefined4 *)(*plVar9 + 0xfb0) = 0;
        }
        iVar6 = 0;
        *(undefined4 *)(*plVar9 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar9 + 0xe70) = 0x10;
        *(undefined4 *)(*plVar9 + 0xe60) = *(undefined4 *)((long)plVar9 + 0x9c);
        *(int *)(*plVar9 + 0xe00) = (int)plVar9[0x13];
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar9 + 0xfb0) = 0;
        *(undefined4 *)(*plVar9 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar9 + 0xe90) = 0xfff;
        *(uint *)(*plVar9 + 0xe80) = (uint)*(byte *)(plVar9 + 0x12) << 0x10 | 3;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar9 + 0xfb0) = 0;
        _raw_spin_unlock(plVar9 + 3);
      }
    }
    else {
      iVar6 = -0x10;
    }
  }
  else {
    iVar6 = -0x16;
  }
  return iVar6;
}



//------------------------------------------------------------
// stm_disable @ 001010a8 size=332
// signature: undefined stm_disable(void)
// callers: []
//------------------------------------------------------------

void stm_disable(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  if (plVar1[0x11] == 1) {
    _raw_spin_lock(plVar1 + 3);
    *(undefined4 *)(*plVar1 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    *(uint *)(*plVar1 + 0xe80) = *(uint *)(*plVar1 + 0xe80) & 0xfffffffe;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar1 + 0xfb0) = 0;
    *(undefined4 *)(*plVar1 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar1 + 0xe00) = 0;
    *(undefined4 *)(*plVar1 + 0xe70) = 0;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar1 + 0xfb0) = 0;
    if (*(int *)((long)plVar1 + 0xa4) != 0) {
      *(undefined4 *)(*plVar1 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar1 + 0xd64) = 0;
      *(undefined4 *)(*plVar1 + 0xd00) = 0;
      *(undefined4 *)(*plVar1 + 0xd20) = 0;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar1 + 0xfb0) = 0;
    }
    _raw_spin_unlock(plVar1 + 3);
    coresight_timeout(param_1 + 0x20,0xe80,0x17,0);
    __pm_runtime_idle(*(undefined8 *)(param_1 + 0x98),5);
    plVar1[0x11] = 0;
  }
  return;
}



//------------------------------------------------------------
// hwevent_enable_show @ 001011f8 size=64
// signature: undefined hwevent_enable_show(void)
// callers: []
//------------------------------------------------------------

long hwevent_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%#lx\n",
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0xa4));
  return (long)iVar1;
}



//------------------------------------------------------------
// hwevent_enable_store @ 0010123c size=136
// signature: undefined hwevent_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
hwevent_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_30);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0xa4) = (undefined4)local_30;
    *(undefined4 *)(lVar2 + 0xa8) = (undefined4)local_30;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hwevent_select_show @ 001012c8 size=64
// signature: undefined hwevent_select_show(void)
// callers: []
//------------------------------------------------------------

long hwevent_select_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%#lx\n",
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0xac));
  return (long)iVar1;
}



//------------------------------------------------------------
// hwevent_select_store @ 0010130c size=136
// signature: undefined hwevent_select_store(void)
// callers: []
//------------------------------------------------------------

undefined8
hwevent_select_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_30);
  if (iVar1 == 0) {
    *(int *)(lVar2 + 0xac) = (int)local_30;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// port_enable_show @ 00101398 size=128
// signature: undefined port_enable_show(void)
// callers: []
//------------------------------------------------------------

long port_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  long *plVar3;
  
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (plVar3[0x11] == 0) {
    uVar2 = (undefined4)plVar3[0x13];
  }
  else {
    _raw_spin_lock(plVar3 + 3);
    uVar2 = *(undefined4 *)(*plVar3 + 0xe00);
    _raw_spin_unlock(plVar3 + 3);
  }
  iVar1 = scnprintf(param_3,0x1000,"%#lx\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// port_enable_store @ 0010141c size=232
// signature: undefined port_enable_store(void)
// callers: []
//------------------------------------------------------------

long port_enable_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    _raw_spin_lock(plVar3 + 3);
    *(int *)(plVar3 + 0x13) = (int)local_40;
    if (plVar3[0x11] != 0) {
      *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      *(int *)(*plVar3 + 0xe00) = (int)plVar3[0x13];
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar3 + 0xfb0) = 0;
    }
    _raw_spin_unlock(plVar3 + 3);
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// port_select_show @ 00101508 size=128
// signature: undefined port_select_show(void)
// callers: []
//------------------------------------------------------------

long port_select_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  long *plVar3;
  
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (plVar3[0x11] == 0) {
    uVar2 = *(undefined4 *)((long)plVar3 + 0x9c);
  }
  else {
    _raw_spin_lock(plVar3 + 3);
    uVar2 = *(undefined4 *)(*plVar3 + 0xe60);
    _raw_spin_unlock(plVar3 + 3);
  }
  iVar1 = scnprintf(param_3,0x1000,"%#lx\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// port_select_store @ 0010158c size=268
// signature: undefined port_select_store(void)
// callers: []
//------------------------------------------------------------

long port_select_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if (iVar3 == 0) {
    _raw_spin_lock(plVar4 + 3);
    *(int *)((long)plVar4 + 0x9c) = (int)local_40;
    if (plVar4[0x11] != 0) {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar1 = *(undefined4 *)(*plVar4 + 0xe00);
      *(undefined4 *)(*plVar4 + 0xe00) = 0;
      *(undefined4 *)(*plVar4 + 0xe60) = *(undefined4 *)((long)plVar4 + 0x9c);
      *(undefined4 *)(*plVar4 + 0xe00) = uVar1;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
    }
    _raw_spin_unlock(plVar4 + 3);
  }
  else {
    param_4 = (long)iVar3;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// traceid_show @ 0010169c size=60
// signature: undefined traceid_show(void)
// callers: []
//------------------------------------------------------------

long traceid_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%#lx\n",
                  (ulong)*(byte *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x90));
  return (long)iVar1;
}



//------------------------------------------------------------
// traceid_store @ 001016dc size=140
// signature: undefined traceid_store(void)
// callers: []
//------------------------------------------------------------

long traceid_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_30);
  if (iVar1 == 0) {
    *(byte *)(lVar2 + 0x90) = (byte)local_30 & 0x7f;
  }
  else {
    param_4 = (long)iVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00101784 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  amba_driver_register(&stm_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001017ac size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  amba_driver_unregister(&stm_driver);
  return;
}



//------------------------------------------------------------
// amba_driver_register @ 00103000 size=1
// signature: undefined amba_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_unregister @ 00103008 size=1
// signature: undefined amba_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 00103010 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00103020 size=1
// signature: undefined devm_clk_get(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00103028 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00103030 size=1
// signature: undefined clk_prepare(void)
// callers: [stm_runtime_resume, stm_probe]
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
// callers: [stm_runtime_resume, stm_probe]
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
// callers: [stm_runtime_resume, stm_probe, stm_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_fwnode @ 00103048 size=1
// signature: undefined dev_fwnode(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00103058 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00103060 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00103068 size=1
// signature: undefined of_address_to_resource(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_bitmap_zalloc @ 00103070 size=1
// signature: undefined devm_bitmap_zalloc(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_bitmap_zalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_register_device @ 00103078 size=1
// signature: undefined stm_register_device(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00103080 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00103088 size=1
// signature: undefined coresight_register(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// stm_unregister_device @ 00103090 size=1
// signature: undefined stm_unregister_device(void)
// callers: [stm_probe, stm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void stm_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103098 size=1
// signature: undefined _dev_info(void)
// callers: [stm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001030a0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [stm_probe, stm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hwevent_enable_store, stm_generic_packet, hwevent_select_store, stm_probe, port_enable_store, traceid_store, port_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 001030b0 size=1
// signature: undefined coresight_unregister(void)
// callers: [stm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disable @ 001030b8 size=1
// signature: undefined coresight_disable(void)
// callers: [stm_generic_unlink, stm_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 001030c0 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [stm_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001030c8 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [stm_restore, stm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001030d0 size=1
// signature: undefined clk_disable(void)
// callers: [stm_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_clear @ 001030d8 size=1
// signature: undefined __bitmap_clear(void)
// callers: [stm_init_default_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_clear(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001030e0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [stm_generic_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030e8 size=1
// signature: undefined fortify_panic(void)
// callers: [stm_generic_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_enable @ 001030f0 size=1
// signature: undefined coresight_enable(void)
// callers: [stm_generic_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00103100 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [port_enable_show, port_select_show, stm_disable, port_enable_store, port_select_store, stm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00103108 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [port_enable_show, port_select_show, stm_disable, port_enable_store, port_select_store, stm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_timeout @ 00103110 size=1
// signature: undefined coresight_timeout(void)
// callers: [stm_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103118 size=1
// signature: undefined scnprintf(void)
// callers: [port_enable_show, hwevent_select_show, hwevent_enable_show, port_select_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00103120 size=1
// signature: undefined kstrtoull(void)
// callers: [hwevent_enable_store, hwevent_select_store, port_enable_store, traceid_store, port_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00103128 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [traceid_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



