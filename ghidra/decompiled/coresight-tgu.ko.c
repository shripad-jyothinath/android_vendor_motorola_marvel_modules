// Decompiled by Ghidra 12.2
// Program: coresight-tgu.ko
// Image base: 00100000

//------------------------------------------------------------
// tgu_probe @ 00100214 size=568
// signature: undefined tgu_probe(void)
// callers: []
//------------------------------------------------------------

void tgu_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long lStack_70;
  undefined **local_68;
  long local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = (undefined **)0x0;
  local_60 = 0;
  local_78 = 0;
  lStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  local_60 = coresight_alloc_device_name(tgu_devs,param_1);
  if (local_60 != 0) {
    uVar2 = coresight_get_platform_data(param_1);
    if (0xfffffffffffff000 < uVar2) goto LAB_00100400;
    *(ulong *)(param_1 + 0x90) = uVar2;
    plVar3 = (long *)devm_kmalloc(param_1,0x78,0xdc0);
    if (plVar3 != (long *)0x0) {
      plVar3[1] = param_1;
      *(long **)(param_1 + 0x98) = plVar3;
      lVar4 = devm_ioremap_resource(param_1,param_1 + 0x390);
      *plVar3 = lVar4;
      if (lVar4 != 0) {
        uVar5 = *(undefined8 *)(param_1 + 0x2e8);
        *(undefined4 *)(plVar3 + 4) = 0;
        iVar1 = of_property_read_variable_u32_array(uVar5,"tgu-steps",(long)plVar3 + 0x24,1,0);
        if ((((iVar1 < 0) ||
             (iVar1 = of_property_read_variable_u32_array
                                (*(undefined8 *)(param_1 + 0x2e8),"tgu-conditions",plVar3 + 5,1,0),
             iVar1 < 0)) ||
            (iVar1 = of_property_read_variable_u32_array
                               (*(undefined8 *)(param_1 + 0x2e8),"tgu-regs",(long)plVar3 + 0x2c,1,0)
            , iVar1 < 0)) ||
           (iVar1 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2e8),"tgu-timer-counters",plVar3 + 6,1,0)
           , iVar1 < 0)) {
          uVar2 = 0xffffffea;
          goto LAB_00100400;
        }
        lVar4 = devm_kmalloc(param_1,0x1000,0xdc0);
        plVar3[7] = lVar4;
        if (lVar4 != 0) {
          lVar4 = devm_kmalloc(param_1,0x400,0xdc0);
          plVar3[8] = lVar4;
          if (lVar4 != 0) {
            lVar4 = devm_kmalloc(param_1,0x400,0xdc0);
            plVar3[9] = lVar4;
            if (lVar4 != 0) {
              lVar4 = devm_kmalloc(param_1,0x80,0xdc0);
              plVar3[10] = lVar4;
              if (lVar4 != 0) {
                lVar4 = devm_kmalloc(param_1,0x80,0xdc0);
                plVar3[0xb] = lVar4;
                if (lVar4 != 0) {
                  local_78 = *(undefined8 *)(param_1 + 0x90);
                  *(undefined1 *)((long)plVar3 + 0x74) = 0;
                  local_90 = CONCAT44(local_90._4_4_,4);
                  local_68 = &tgu_attr_grps;
                  lStack_70 = param_1;
                  uVar2 = coresight_register(&local_90);
                  plVar3[2] = uVar2;
                  if (uVar2 < 0xfffffffffffff001) {
                    __pm_runtime_idle(param_1,5);
                    uVar2 = 0;
                  }
                  else {
                    __pm_runtime_idle(param_1,5);
                    uVar2 = uVar2 & 0xffffffff;
                  }
                  goto LAB_00100400;
                }
              }
            }
          }
        }
      }
    }
  }
  uVar2 = 0xfffffff4;
LAB_00100400:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// enable_tgu_store @ 00100450 size=668
// signature: undefined enable_tgu_store(void)
// callers: []
//------------------------------------------------------------

long enable_tgu_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  plVar8 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if (iVar3 == 0) {
    iVar3 = __pm_runtime_resume(plVar8[1],4);
    if (iVar3 < 0) {
      __pm_runtime_idle(plVar8[1],5);
      param_4 = (long)iVar3;
    }
    else {
      _raw_spin_lock(plVar8 + 4);
      *(undefined4 *)(*plVar8 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)*plVar8 = 0;
      if (local_40 == 0) {
        __pm_runtime_idle(plVar8[1],5);
      }
      else {
        if (-1 < (int)plVar8[0xc]) {
          iVar3 = 0;
          do {
            plVar1 = (long *)(plVar8[7] + (long)iVar3 * 0x10);
            iVar3 = iVar3 + 1;
            *(int *)(*plVar8 + *plVar1) = (int)plVar1[1];
          } while (iVar3 <= (int)plVar8[0xc]);
        }
        iVar3 = (int)plVar8[5];
        if (-1 < iVar3) {
          iVar4 = 0;
          iVar6 = *(int *)((long)plVar8 + 0x24);
          iVar5 = 0x50;
          do {
            if (-1 < iVar6) {
              iVar3 = 0;
              iVar7 = iVar5;
              do {
                iVar3 = iVar3 + 1;
                *(undefined4 *)(*plVar8 + (long)iVar7) = 0x1000000;
                iVar6 = *(int *)((long)plVar8 + 0x24);
                iVar7 = iVar7 + 0x1d8;
              } while (iVar3 <= iVar6);
              iVar3 = (int)plVar8[5];
            }
            iVar4 = iVar4 + 1;
            iVar5 = iVar5 + 4;
          } while (iVar4 <= iVar3);
        }
        if (-1 < *(int *)((long)plVar8 + 100)) {
          iVar3 = 0;
          do {
            plVar1 = (long *)(plVar8[8] + (long)iVar3 * 0x10);
            iVar3 = iVar3 + 1;
            *(int *)(*plVar8 + *plVar1) = (int)plVar1[1];
          } while (iVar3 <= *(int *)((long)plVar8 + 100));
        }
        if (-1 < (int)plVar8[0xd]) {
          iVar3 = 0;
          do {
            plVar1 = (long *)(plVar8[9] + (long)iVar3 * 0x10);
            iVar3 = iVar3 + 1;
            *(int *)(*plVar8 + *plVar1) = (int)plVar1[1];
          } while (iVar3 <= (int)plVar8[0xd]);
        }
        if (-1 < *(int *)((long)plVar8 + 0x6c)) {
          iVar3 = 0;
          do {
            plVar1 = (long *)(plVar8[10] + (long)iVar3 * 0x10);
            iVar3 = iVar3 + 1;
            *(int *)(*plVar8 + *plVar1) = (int)plVar1[1];
          } while (iVar3 <= *(int *)((long)plVar8 + 0x6c));
        }
        if (-1 < (int)plVar8[0xe]) {
          iVar3 = 0;
          do {
            plVar1 = (long *)(plVar8[0xb] + (long)iVar3 * 0x10);
            iVar3 = iVar3 + 1;
            *(int *)(*plVar8 + *plVar1) = (int)plVar1[1];
          } while (iVar3 <= (int)plVar8[0xe]);
        }
        *(undefined4 *)*plVar8 = 1;
        *(undefined1 *)((long)plVar8 + 0x74) = 1;
      }
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar8 + 0xfb0) = 0;
      _raw_spin_unlock(plVar8 + 4);
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// reset_tgu_store @ 001006f0 size=288
// signature: undefined reset_tgu_store(void)
// callers: []
//------------------------------------------------------------

long reset_tgu_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if ((*(char *)((long)plVar3 + 0x74) == '\0') &&
       (iVar2 = __pm_runtime_resume(plVar3[1],4), iVar2 < 0)) {
      __pm_runtime_idle(plVar3[1],5);
      param_4 = (long)iVar2;
    }
    else {
      _raw_spin_lock(plVar3 + 4);
      *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      if (local_40 != 0) {
        *(undefined4 *)*plVar3 = 0;
        *(undefined4 *)(plVar3 + 0xe) = 0;
        plVar3[0xc] = 0;
        plVar3[0xd] = 0;
      }
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      _raw_spin_unlock(plVar3 + 4);
      __pm_runtime_idle(plVar3[1],5);
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_group_store @ 00100814 size=340
// signature: undefined set_group_store(void)
// callers: []
//------------------------------------------------------------

undefined8 set_group_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  ulong local_50;
  int local_44;
  int local_40;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  local_50 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(lVar2 + 0x60) < 0x100) {
    iVar1 = sscanf(param_3,"%d %d %d %lx",&local_3c,&local_40,&local_44,&local_50);
    if (iVar1 == 4) {
      _raw_spin_lock(lVar2 + 0x20);
      if ((local_3c < 5) && (local_40 <= *(int *)(lVar2 + 0x2c))) {
        *(long *)(*(long *)(lVar2 + 0x38) + (long)*(int *)(lVar2 + 0x60) * 0x10) =
             (long)(local_3c * 0x60 + local_40 * 4 + local_44 * 0x1d8 + 0x74);
        *(ulong *)(*(long *)(lVar2 + 0x38) + (long)*(int *)(lVar2 + 0x60) * 0x10 + 8) = local_50;
        *(int *)(lVar2 + 0x60) = *(int *)(lVar2 + 0x60) + 1;
      }
      else {
        _dev_err(*(undefined8 *)(lVar2 + 8),"Invalid group data\n");
      }
      _raw_spin_unlock(lVar2 + 0x20);
      goto LAB_00100920;
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8)," Too many groups are being configured\n");
  }
  param_4 = 0xffffffffffffffea;
LAB_00100920:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_condition_store @ 0010096c size=320
// signature: undefined set_condition_store(void)
// callers: []
//------------------------------------------------------------

undefined8 set_condition_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_48 [2];
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48[0] = 0;
  local_48[1] = 0;
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(lVar2 + 100) < 0x40) {
    iVar1 = sscanf(param_3,"%d %d %lx",local_48 + 1,local_48,&local_40);
    if (iVar1 == 3) {
      _raw_spin_lock(lVar2 + 0x20);
      if ((*(int *)(lVar2 + 0x28) < local_48[1]) || (*(int *)(lVar2 + 0x24) < local_48[0])) {
        _dev_err(*(undefined8 *)(lVar2 + 8),"Invalid condition decode data\n");
      }
      else {
        *(long *)(*(long *)(lVar2 + 0x40) + (long)*(int *)(lVar2 + 100) * 0x10) =
             (long)(local_48[0] * 0x1d8 + local_48[1] * 4 + 0x50);
        *(ulong *)(*(long *)(lVar2 + 0x40) + (long)*(int *)(lVar2 + 100) * 0x10 + 8) = local_40;
        *(int *)(lVar2 + 100) = *(int *)(lVar2 + 100) + 1;
      }
      _raw_spin_unlock(lVar2 + 0x20);
      goto LAB_00100a64;
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8)," Too many groups are being configured\n");
  }
  param_4 = 0xffffffffffffffea;
LAB_00100a64:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_select_store @ 00100ab0 size=320
// signature: undefined set_select_store(void)
// callers: []
//------------------------------------------------------------

undefined8 set_select_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_48 [2];
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48[0] = 0;
  local_48[1] = 0;
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(lVar2 + 0x68) < 0x40) {
    iVar1 = sscanf(param_3,"%d %d %lx",local_48 + 1,local_48,&local_40);
    if (iVar1 == 3) {
      _raw_spin_lock(lVar2 + 0x20);
      if ((*(int *)(lVar2 + 0x28) < local_48[1]) || (*(int *)(lVar2 + 0x24) < local_48[0])) {
        _dev_err(*(undefined8 *)(lVar2 + 8),"Invalid select decode data\n");
      }
      else {
        *(long *)(*(long *)(lVar2 + 0x48) + (long)*(int *)(lVar2 + 0x68) * 0x10) =
             (long)(local_48[0] * 0x1d8 + local_48[1] * 4 + 0x60);
        *(ulong *)(*(long *)(lVar2 + 0x48) + (long)*(int *)(lVar2 + 0x68) * 0x10 + 8) = local_40;
        *(int *)(lVar2 + 0x68) = *(int *)(lVar2 + 0x68) + 1;
      }
      _raw_spin_unlock(lVar2 + 0x20);
      goto LAB_00100ba8;
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8)," Too many groups are being configured\n");
  }
  param_4 = 0xffffffffffffffea;
LAB_00100ba8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_timer_store @ 00100bf4 size=300
// signature: undefined set_timer_store(void)
// callers: []
//------------------------------------------------------------

undefined8 set_timer_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_44;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(lVar2 + 0x6c) < 8) {
    iVar1 = sscanf(param_3,"%d %lx",&local_44,&local_40);
    if (iVar1 == 2) {
      _raw_spin_lock(lVar2 + 0x20);
      if (*(int *)(lVar2 + 0x30) < local_44) {
        _dev_err(*(undefined8 *)(lVar2 + 8),"Invalid TGU timer data\n");
      }
      else {
        *(long *)(*(long *)(lVar2 + 0x50) + (long)*(int *)(lVar2 + 0x6c) * 0x10) =
             (long)(local_44 * 0x1d8 + 0x40);
        *(ulong *)(*(long *)(lVar2 + 0x50) + (long)*(int *)(lVar2 + 0x6c) * 0x10 + 8) = local_40;
        *(int *)(lVar2 + 0x6c) = *(int *)(lVar2 + 0x6c) + 1;
      }
      _raw_spin_unlock(lVar2 + 0x20);
      goto LAB_00100cd8;
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8)," Too many groups are being configured\n");
  }
  param_4 = 0xffffffffffffffea;
LAB_00100cd8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_counter_store @ 00100d24 size=300
// signature: undefined set_counter_store(void)
// callers: []
//------------------------------------------------------------

undefined8 set_counter_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_44;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(lVar2 + 0x70) < 8) {
    iVar1 = sscanf(param_3,"%d %lx",&local_44,&local_40);
    if (iVar1 == 2) {
      _raw_spin_lock(lVar2 + 0x20);
      if (*(int *)(lVar2 + 0x30) < local_44) {
        _dev_err(*(undefined8 *)(lVar2 + 8),"Invalid TGU counter data\n");
      }
      else {
        *(long *)(*(long *)(lVar2 + 0x58) + (long)*(int *)(lVar2 + 0x70) * 0x10) =
             (long)(local_44 * 0x1d8 + 0x48);
        *(ulong *)(*(long *)(lVar2 + 0x58) + (long)*(int *)(lVar2 + 0x70) * 0x10 + 8) = local_40;
        *(int *)(lVar2 + 0x70) = *(int *)(lVar2 + 0x70) + 1;
      }
      _raw_spin_unlock(lVar2 + 0x20);
      goto LAB_00100e08;
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8)," Too many groups are being configured\n");
  }
  param_4 = 0xffffffffffffffea;
LAB_00100e08:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00100e54 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  amba_driver_register(&tgu_driver);
  return;
}



//------------------------------------------------------------
// amba_driver_register @ 00102000 size=1
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
// coresight_alloc_device_name @ 00102008 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [tgu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00102010 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [tgu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [tgu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00102020 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [tgu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [tgu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00102030 size=1
// signature: undefined coresight_register(void)
// callers: [tgu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00102038 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [tgu_probe, enable_tgu_store, reset_tgu_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [tgu_probe, set_group_store, set_condition_store, set_counter_store, set_timer_store, enable_tgu_store, reset_tgu_store, set_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00102048 size=1
// signature: undefined kstrtoull(void)
// callers: [enable_tgu_store, reset_tgu_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00102050 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [enable_tgu_store, reset_tgu_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00102058 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [set_group_store, set_condition_store, set_counter_store, set_timer_store, enable_tgu_store, reset_tgu_store, set_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00102060 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [set_group_store, set_condition_store, set_counter_store, set_timer_store, enable_tgu_store, reset_tgu_store, set_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00102068 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [set_group_store, set_condition_store, set_counter_store, set_timer_store, set_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102070 size=1
// signature: undefined _dev_err(void)
// callers: [set_group_store, set_condition_store, set_counter_store, set_timer_store, set_select_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



