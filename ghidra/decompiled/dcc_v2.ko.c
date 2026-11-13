// Decompiled by Ghidra 12.2
// Program: dcc_v2.ko
// Image base: 00100000

//------------------------------------------------------------
// dcc_probe @ 00100c0c size=1124
// signature: undefined dcc_probe(void)
// callers: []
//------------------------------------------------------------

void dcc_probe(long param_1)

{
  long lVar1;
  uint *puVar2;
  int iVar3;
  long *plVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  char cVar8;
  uint uVar9;
  long lVar10;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  long local_60;
  long local_58;
  ulong uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar6 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  plVar4 = (long *)devm_kmalloc(lVar1,0x180,0xdc0);
  if (plVar4 != (long *)0x0) {
    plVar4[2] = lVar1;
    *(long **)(param_1 + 0xa8) = plVar4;
    plVar5 = (long *)platform_get_resource_byname(param_1,0x200,"dcc-base");
    if (plVar5 == (long *)0x0) {
LAB_00100de0:
      uVar7 = 0xffffffea;
      goto LAB_00101010;
    }
    *(int *)(plVar4 + 1) = ((int)plVar5[1] - (int)*plVar5) + 1;
    lVar6 = devm_ioremap(lVar1,*plVar5,(plVar5[1] - *plVar5) + 1);
    *plVar4 = lVar6;
    if (lVar6 != 0) {
      plVar5 = (long *)platform_get_resource_byname(param_1,0x200,"dcc-ram-base");
      if (plVar5 == (long *)0x0) goto LAB_00100de0;
      *(int *)(plVar4 + 10) = ((int)plVar5[1] - (int)*plVar5) + 1;
      lVar6 = devm_ioremap(lVar1,*plVar5,(plVar5[1] - *plVar5) + 1);
      plVar4[9] = lVar6;
      if (lVar6 != 0) {
        iVar3 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"dcc-ram-offset",(long)plVar4 + 0x54,1,0
                          );
        if (iVar3 < 0) goto LAB_00100de0;
        iVar3 = of_property_count_elems_of_size(*(undefined8 *)(param_1 + 0x2f8),"ll-reg-offsets",4)
        ;
        *(int *)((long)plVar4 + 0x164) = iVar3;
        if (iVar3 < 1) {
          _dev_info(lVar1,"ll-reg-offsets property doesn\'t exist\n");
          *(undefined4 *)((long)plVar4 + 0x164) = 0;
        }
        else {
          iVar3 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"per-ll-reg-cnt",plVar4 + 0x2c,1,0);
          if (iVar3 < 0) goto LAB_00100de0;
        }
        puVar2 = (uint *)(plVar4 + 0xd);
        iVar3 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"dcc-mem-map-ver",puVar2,1,0);
        if (iVar3 < 0) {
          if ((*(uint *)(*plVar4 + 4) >> 9 & 1) == 0) {
            if (((*(uint *)(*plVar4 + 4) ^ 0xffffffff) & 0x3f) != 0) {
              *puVar2 = 0;
              goto LAB_00100dec;
            }
            uVar9 = 1;
          }
          else {
            uVar9 = 2;
          }
          *puVar2 = uVar9;
LAB_00100dcc:
          iVar3 = *(int *)(*plVar4 + 0x10);
          *(int *)(plVar4 + 0x29) = iVar3;
          if (iVar3 == 0) goto LAB_00100de0;
        }
        else {
          if (2 < *puVar2) goto LAB_00100de0;
          if (*puVar2 != 0) goto LAB_00100dcc;
LAB_00100dec:
          *(undefined4 *)(plVar4 + 0x29) = 8;
        }
        if ((*(uint *)(*plVar4 + 4) >> 6 & 1) == 0) {
          iVar3 = ((uint)(*(int *)((long)plVar4 + 0x54) + (int)plVar4[10]) >> 2) - 1;
          cVar8 = '\0';
          if (iVar3 != 0) {
            cVar8 = ' ' - (char)LZCOUNT(iVar3);
          }
        }
        else {
          cVar8 = '\x10';
        }
        *(char *)(plVar4 + 0x2b) = cVar8;
        __mutex_init(plVar4 + 3,"&drvdata->mutex",&dcc_probe___key);
        lVar6 = devm_kmalloc(lVar1,(ulong)*(uint *)(plVar4 + 0x29) << 2,0xdc0);
        plVar4[0xb] = lVar6;
        if (lVar6 != 0) {
          lVar6 = devm_kmalloc(lVar1,(ulong)*(uint *)(plVar4 + 0x29) << 2,0xdc0);
          plVar4[0xc] = lVar6;
          if (lVar6 != 0) {
            lVar6 = devm_kmalloc(lVar1,(int)plVar4[0x29],0xdc0);
            plVar4[0xf] = lVar6;
            if (lVar6 != 0) {
              lVar6 = devm_kmalloc(lVar1,(int)plVar4[0x29],0xdc0);
              plVar4[0x10] = lVar6;
              if (lVar6 != 0) {
                lVar6 = devm_kmalloc(lVar1,(int)plVar4[0x29],0xdc0);
                plVar4[0x11] = lVar6;
                if (lVar6 != 0) {
                  lVar6 = devm_kmalloc(lVar1,(int)plVar4[0x29],0xdc0);
                  plVar4[0x12] = lVar6;
                  if (lVar6 != 0) {
                    lVar6 = devm_kmalloc(lVar1,(ulong)*(uint *)(plVar4 + 0x29) << 2,0xdc0);
                    plVar4[0x28] = lVar6;
                    if (lVar6 != 0) {
                      lVar6 = devm_kmalloc(lVar1,(int)plVar4[0x29],0xdc0);
                      plVar4[0x2a] = lVar6;
                      if (lVar6 != 0) {
                        lVar6 = devm_kmalloc(lVar1,(int)plVar4[0x29],0xdc0);
                        plVar4[0x2f] = lVar6;
                        if (lVar6 != 0) {
                          lVar6 = devm_kmalloc(lVar1,(ulong)*(uint *)(plVar4 + 0x29) << 4,0xdc0);
                          plVar4[0x27] = lVar6;
                          if (lVar6 != 0) {
                            if ((int)plVar4[0x29] != 0) {
                              uVar9 = 0;
                              do {
                                lVar10 = (long)(int)uVar9;
                                lVar6 = plVar4[0x27] + (long)(int)uVar9 * 0x10;
                                *(long *)lVar6 = lVar6;
                                *(long *)(lVar6 + 8) = lVar6;
                                *(undefined4 *)(plVar4[0x28] + (long)(int)uVar9 * 4) = 0;
                                uVar9 = uVar9 + 1;
                                *(undefined1 *)(plVar4[0x10] + lVar10) = 1;
                                *(undefined1 *)(plVar4[0x11] + lVar10) = 0;
                              } while (uVar9 < *(uint *)(plVar4 + 0x29));
                            }
                            __memset_io(plVar4[9],0,(int)plVar4[10]);
                            *(undefined1 *)((long)plVar4 + 0x14c) = 0xff;
                            uVar7 = dcc_sram_dev_init(plVar4);
                            if (((int)uVar7 == 0) &&
                               (uVar7 = dcc_create_files(lVar1), (int)uVar7 == 0)) {
                              dcc_configure_list(plVar4,*(undefined8 *)(param_1 + 0x2f8));
                              strscpy(&local_78,"KDCCDATA",9);
                              local_60 = plVar4[9];
                              uStack_50 = (ulong)*(uint *)(plVar4 + 10);
                              local_58 = *plVar5;
                              iVar3 = msm_minidump_add_region(&local_78);
                              if (iVar3 < 0) {
                                _dev_err(plVar4[2],"Failed to add DCC data in Minidump\n");
                              }
                              uVar7 = 0;
                            }
                            goto LAB_00101010;
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
      }
    }
  }
  uVar7 = 0xfffffff4;
LAB_00101010:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// dcc_remove @ 00101074 size=92
// signature: undefined dcc_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 dcc_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  device_destroy(*(undefined8 *)(lVar1 + 0x130),*(undefined4 *)(lVar1 + 0x128));
  class_destroy(*(undefined8 *)(lVar1 + 0x130));
  cdev_del(lVar1 + 0xa8);
  unregister_chrdev_region(*(undefined4 *)(lVar1 + 0x128),1);
  dcc_config_reset(lVar1);
  return 0;
}



//------------------------------------------------------------
// dcc_sram_dev_init @ 001010d0 size=380
// signature: undefined dcc_sram_dev_init(void)
// callers: [dcc_probe]
//------------------------------------------------------------

ulong dcc_sram_dev_init(long param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = devm_kmalloc(*(undefined8 *)(param_1 + 0x10),9,0xdc0);
  *(long *)(param_1 + 0xa0) = lVar2;
  if (lVar2 == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    strscpy(lVar2,"dcc_sram",9);
    local_3c = 0;
    uVar1 = alloc_chrdev_region(&local_3c,0,1,*(undefined8 *)(param_1 + 0xa0));
    if (uVar1 == 0) {
      lVar2 = param_1 + 0xa8;
      cdev_init(lVar2,&dcc_sram_fops);
      *(undefined1 **)(param_1 + 0x108) = &__this_module;
      uVar1 = cdev_add(lVar2,local_3c,1);
      if (uVar1 == 0) {
        uVar3 = __class_create(&__this_module,*(undefined8 *)(param_1 + 0xa0),
                               &dcc_sram_dev_register___key);
        *(ulong *)(param_1 + 0x130) = uVar3;
        if (uVar3 < 0xfffffffffffff001) {
          uVar3 = device_create(uVar3,0,*(undefined4 *)(param_1 + 0x128),param_1,
                                *(undefined8 *)(param_1 + 0xa0));
          if (uVar3 < 0xfffffffffffff001) {
            uVar3 = 0;
            goto LAB_00101218;
          }
          class_destroy(*(undefined8 *)(param_1 + 0x130));
        }
        cdev_del(lVar2);
        unregister_chrdev_region(*(undefined4 *)(param_1 + 0x128),1);
        if ((int)uVar3 == 0) goto LAB_00101218;
      }
      else {
        uVar3 = (ulong)uVar1;
        unregister_chrdev_region(*(undefined4 *)(param_1 + 0x128),1);
      }
    }
    else {
      uVar3 = (ulong)uVar1;
    }
    _dev_err(*(undefined8 *)(param_1 + 0x10),"DCC: sram node not registered.\n");
  }
LAB_00101218:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// dcc_create_files @ 0010124c size=204
// signature: undefined dcc_create_files(void)
// callers: [dcc_probe]
//------------------------------------------------------------

int dcc_create_files(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  undefined **ppuVar6;
  ulong uVar7;
  
  iVar2 = device_create_file(param_1,&dev_attr_func_type);
  ppuVar6 = &dcc_attrs;
  if (iVar2 == 0) {
    uVar5 = 1;
    do {
      uVar7 = -(uVar5 >> 0x1f) & 0xfffffff800000000 | uVar5 << 3;
      if ((0x90 < uVar7) || (iVar4 = (int)uVar5, iVar4 == 0x12)) goto LAB_00101314;
      ppuVar6 = &dcc_attrs + iVar4;
      if (*ppuVar6 == (undefined *)0x0) {
        return 0;
      }
      iVar2 = device_create_file(param_1);
      uVar5 = (ulong)(iVar4 + 1);
    } while (iVar2 == 0);
    bVar3 = 0x88 < uVar7;
  }
  else {
    bVar3 = false;
  }
  if (!bVar3) {
    _dev_err(param_1,"DCC: Couldn\'t create sysfs attribute: %s\n",*(undefined8 *)*ppuVar6);
    return iVar2;
  }
LAB_00101314:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x101318);
  (*pcVar1)();
}



//------------------------------------------------------------
// dcc_configure_list @ 00101318 size=164
// signature: undefined dcc_configure_list(void)
// callers: [dcc_probe]
//------------------------------------------------------------

void dcc_configure_list(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = of_get_next_available_child(param_2,0);
  if (lVar2 == 0) {
LAB_00101398:
    iVar1 = dcc_dt_parse(param_1,param_2);
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    do {
      iVar1 = dcc_dt_parse(param_1,lVar2);
      if (iVar1 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x10),"DCC link list config failed err:%d\n",iVar1);
        if (iVar1 != -1) {
          return;
        }
        goto LAB_00101398;
      }
      lVar2 = of_get_next_available_child(param_2,lVar2);
    } while (lVar2 != 0);
  }
  dcc_enable(param_1);
  return;
}



//------------------------------------------------------------
// dcc_sram_read @ 001013c0 size=536
// signature: undefined dcc_sram_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong dcc_sram_read(long param_1,ulong param_2,ulong param_3,ulong *param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  long lVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined4 *puVar9;
  ulong uVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0xd8);
  uVar5 = *param_4;
  uVar8 = (ulong)*(uint *)(lVar11 + 0x50);
  if ((long)uVar5 < (long)uVar8) {
    uVar10 = uVar8 - uVar5;
    if (uVar5 + param_3 <= uVar8 && !CARRY8(uVar5,param_3)) {
      uVar10 = param_3;
    }
    puVar3 = (undefined4 *)__kmalloc(uVar10,0xdc0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar10 = 0xfffffffffffffff4;
    }
    else {
      if ((uVar10 == 0) ||
         (puVar6 = (undefined4 *)(*(long *)(lVar11 + 0x48) + *param_4),
         (((uint)uVar10 | (uint)puVar6) & 3) != 0)) {
        _dev_err(*(undefined8 *)(lVar11 + 0x10),"Target address or size not aligned with 4 bytes\n")
        ;
        uVar10 = 0xffffffffffffffea;
      }
      else {
        if (3 < uVar10) {
          uVar5 = uVar10;
          puVar9 = puVar3;
          do {
            uVar1 = *puVar6;
            puVar6 = puVar6 + 1;
            uVar5 = uVar5 - 4;
            *puVar9 = uVar1;
            puVar9 = puVar9 + 1;
          } while (3 < uVar5);
        }
        if (uVar10 >> 0x1f != 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1015a8);
          (*pcVar2)();
        }
        __check_object_size(puVar3,uVar10,1);
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar5 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar5 = param_2 & (long)(param_2 << 8) >> 8;
        }
        lVar4 = 1;
        if (uVar5 <= 0x8000000000 - uVar10) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar5 = daif;
            if ((uVar5 & 0x80) == 0) {
              uVar8 = daif;
              daif = uVar8 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar8 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar8 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar5;
          }
          lVar4 = __arch_copy_to_user(puVar7,param_2 & 0xff7fffffffffffff,puVar3,uVar10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar5 = daif;
            if ((uVar5 & 0x80) == 0) {
              uVar8 = daif;
              daif = uVar8 | 0xc0;
            }
            uVar8 = ttbr1_el1;
            ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar8 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar5;
          }
        }
        if (lVar4 == 0) {
          *param_4 = *param_4 + uVar10;
        }
        else {
          _dev_err(*(undefined8 *)(lVar11 + 0x10),"DCC: Couldn\'t copy all data to user\n");
          uVar10 = 0xfffffffffffffff2;
        }
      }
      kfree(puVar3);
    }
  }
  else {
    uVar10 = 0;
  }
  return uVar10;
}



//------------------------------------------------------------
// dcc_sram_open @ 001015f4 size=20
// signature: undefined dcc_sram_open(void)
// callers: []
//------------------------------------------------------------

undefined8 dcc_sram_open(long param_1,long param_2)

{
  *(long *)(param_2 + 0xd8) = *(long *)(param_1 + 0x290) + -0xa8;
  return 0;
}



//------------------------------------------------------------
// func_type_show @ 0010160c size=176
// signature: undefined func_type_show(void)
// callers: []
//------------------------------------------------------------

long func_type_show(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar6 + 0x148) == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = 0;
    lVar4 = 0;
    do {
      uVar1 = *(uint *)(*(long *)(lVar6 + 0x60) + uVar5 * 4);
      if (1 < uVar1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1016bc);
        (*pcVar2)();
      }
      iVar3 = scnprintf(param_3 + lVar4,0x1000 - lVar4,"%u :%s\n",uVar5 & 0xffffffff,
                        (&str_dcc_func_type)[uVar1]);
      lVar4 = lVar4 + iVar3;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(lVar6 + 0x148));
  }
  return lVar4;
}



//------------------------------------------------------------
// func_type_store @ 001016c0 size=300
// signature: undefined func_type_store(void)
// callers: []
//------------------------------------------------------------

long func_type_store(long param_1,undefined8 param_2,char *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 local_48;
  undefined2 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  local_48 = 0;
  sVar3 = strlen(param_3);
  if (sVar3 < 10) {
    iVar2 = sscanf(param_3,"%8s",&local_48);
    if (iVar2 == 1) {
      mutex_lock(lVar6 + 0x18);
      bVar1 = *(byte *)(lVar6 + 0x14c);
      if ((uint)bVar1 < *(uint *)(lVar6 + 0x148)) {
        if (*(char *)(*(long *)(lVar6 + 0x78) + (ulong)bVar1) == '\0') {
          if ((int)local_48 == 0x706163) {
            uVar4 = 0;
          }
          else {
            if ((int)local_48 != 0x637263) goto LAB_001017ac;
            uVar4 = 1;
          }
          lVar5 = (long)param_4;
          *(undefined4 *)(*(long *)(lVar6 + 0x60) + (ulong)bVar1 * 4) = uVar4;
        }
        else {
          lVar5 = -0x10;
        }
      }
      else {
        _dev_err(param_1,"Select link list to program using curr_list\n");
LAB_001017ac:
        lVar5 = -0x16;
      }
      mutex_unlock(lVar6 + 0x18);
      goto LAB_001017b8;
    }
  }
  lVar5 = -0x16;
LAB_001017b8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}



//------------------------------------------------------------
// data_sink_show @ 001017f0 size=176
// signature: undefined data_sink_show(void)
// callers: []
//------------------------------------------------------------

long data_sink_show(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar6 + 0x148) == 0) {
    lVar4 = 0;
  }
  else {
    uVar5 = 0;
    lVar4 = 0;
    do {
      uVar1 = *(uint *)(*(long *)(lVar6 + 0x58) + uVar5 * 4);
      if (1 < uVar1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1018a0);
        (*pcVar2)();
      }
      iVar3 = scnprintf(param_3 + lVar4,0x1000 - lVar4,"%u :%s\n",uVar5 & 0xffffffff,
                        (&str_dcc_data_sink)[uVar1]);
      lVar4 = lVar4 + iVar3;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(lVar6 + 0x148));
  }
  return lVar4;
}



//------------------------------------------------------------
// data_sink_store @ 001018a4 size=304
// signature: undefined data_sink_store(void)
// callers: []
//------------------------------------------------------------

long data_sink_store(long param_1,undefined8 param_2,char *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 local_48;
  undefined2 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  local_48 = 0;
  sVar3 = strlen(param_3);
  if (sVar3 < 10) {
    iVar2 = sscanf(param_3,"%8s",&local_48);
    if (iVar2 == 1) {
      mutex_lock(lVar6 + 0x18);
      bVar1 = *(byte *)(lVar6 + 0x14c);
      if ((uint)bVar1 < *(uint *)(lVar6 + 0x148)) {
        if (*(char *)(*(long *)(lVar6 + 0x78) + (ulong)bVar1) == '\0') {
          uVar4 = 0;
          if ((int)local_48 != 0x6d617273 || local_48._4_1_ != '\0') {
            if ((int)local_48 != 0x627461) goto LAB_00101994;
            uVar4 = 1;
          }
          lVar5 = (long)param_4;
          *(undefined4 *)(*(long *)(lVar6 + 0x58) + (ulong)bVar1 * 4) = uVar4;
        }
        else {
          lVar5 = -0x10;
        }
      }
      else {
        _dev_err(param_1,"Select link list to program using curr_list\n");
LAB_00101994:
        lVar5 = -0x16;
      }
      mutex_unlock(lVar6 + 0x18);
      goto LAB_001019a0;
    }
  }
  lVar5 = -0x16;
LAB_001019a0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}



//------------------------------------------------------------
// trigger_store @ 001019d8 size=872
// signature: undefined trigger_store(void)
// callers: []
//------------------------------------------------------------

void trigger_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  long *plVar10;
  uint uVar11;
  uint uVar12;
  long local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  plVar10 = *(long **)(param_1 + 0x98);
  local_70 = 0;
  iVar4 = kstrtoull(param_3,0x10,&local_70);
  lVar5 = -0x16;
  if ((iVar4 == 0) && (local_70 == 1)) {
    mutex_lock(plVar10 + 3);
    uVar7 = *(uint *)(plVar10 + 0x29);
    if (uVar7 != 0) {
      uVar8 = 0;
      uVar11 = 0x44;
      do {
        if ((*(char *)(plVar10[0xf] + (long)(int)uVar8) != '\0') &&
           (*(char *)(plVar10[0x11] + (long)(int)uVar8) != '\0')) {
          _dev_info(plVar10[2],"DCC SW trigger link list %d\n",uVar8);
          uVar2 = uVar8 << 7;
          uVar7 = uVar8 << 7 | 0x38;
          if ((int)plVar10[0xd] == 1) {
            uVar12 = uVar2 | 0x30;
          }
          else {
            uVar12 = uVar7;
            if ((int)plVar10[0xd] == 0) {
              uVar12 = uVar11 - 0x24;
            }
          }
          uVar1 = *(uint *)(*plVar10 + (ulong)uVar12);
          iVar4 = (int)plVar10[0xd];
          uVar12 = 0xfffffeff;
          if (iVar4 != 2) {
            uVar12 = 0xfffffdff;
          }
          if (iVar4 == 1) {
            uVar9 = uVar2 | 0x30;
          }
          else {
            uVar9 = uVar7;
            if (iVar4 == 0) {
              uVar9 = uVar11 - 0x24;
            }
          }
          *(uint *)(*plVar10 + (ulong)uVar9) = uVar12 & uVar1;
          if ((int)plVar10[0xd] == 1) {
            uVar12 = uVar2 | 0x58;
          }
          else if ((int)plVar10[0xd] == 0) {
            uVar12 = uVar11;
          }
          else {
            uVar12 = uVar2 | 0x60;
          }
          *(undefined4 *)(*plVar10 + (ulong)uVar12) = 1;
          if ((int)plVar10[0xd] == 1) {
            uVar7 = uVar2 | 0x30;
          }
          else if ((int)plVar10[0xd] == 0) {
            uVar7 = uVar11 - 0x24;
          }
          *(uint *)(*plVar10 + (ulong)uVar7) = uVar1;
          uVar7 = *(uint *)(plVar10 + 0x29);
        }
        uVar8 = uVar8 + 1;
        uVar11 = uVar11 + 0x80;
      } while (uVar8 < uVar7);
    }
    uVar6 = dcc_ready(plVar10);
    if ((uVar6 & 1) == 0) {
      _dev_err(plVar10[2],"DCC is busy after receiving sw tigger.\n");
      param_4 = -0x10;
    }
    else {
      uVar7 = *(uint *)(plVar10 + 0x29);
      if (uVar7 != 0) {
        uVar8 = 0;
        uVar11 = 100;
        do {
          if (*(char *)(plVar10[0xf] + (long)(int)uVar8) != '\0') {
            if ((int)plVar10[0xd] == 1) {
              uVar7 = uVar8 << 7 | 0x5c;
            }
            else if ((int)plVar10[0xd] == 0) {
              uVar7 = uVar11 - 0x1c;
            }
            else {
              uVar7 = uVar8 << 7 | 100;
            }
            if (*(int *)(*plVar10 + (ulong)uVar7) != 0) {
              _dev_err(plVar10[2],"Read access error for list %d err: 0x%x.\n");
              uVar7 = uVar11 - 0x2c;
              if ((int)plVar10[0xd] == 0) {
                uVar8 = uVar11 - 0x44;
              }
              else {
                uVar8 = uVar7;
                if ((int)plVar10[0xd] == 1) {
                  uVar8 = uVar11 - 0x34;
                }
              }
              uVar2 = *(uint *)(*plVar10 + (ulong)uVar8);
              iVar4 = (int)plVar10[0xd];
              uVar8 = 0xfffffeff;
              if (iVar4 != 2) {
                uVar8 = 0xfffffdff;
              }
              if (iVar4 == 0) {
                uVar12 = uVar11 - 0x44;
              }
              else {
                uVar12 = uVar7;
                if (iVar4 == 1) {
                  uVar12 = uVar11 - 0x34;
                }
              }
              *(uint *)(*plVar10 + (ulong)uVar12) = uVar8 & uVar2;
              if ((int)plVar10[0xd] == 0) {
                uVar8 = uVar11 - 0x1c;
              }
              else {
                uVar8 = uVar11;
                if ((int)plVar10[0xd] == 1) {
                  uVar8 = uVar11 - 8;
                }
              }
              *(undefined4 *)(*plVar10 + (ulong)uVar8) = 3;
              if ((int)plVar10[0xd] == 0) {
                uVar7 = uVar11 - 0x44;
              }
              else if ((int)plVar10[0xd] == 1) {
                uVar7 = uVar11 - 0x34;
              }
              param_4 = -0x3d;
              *(uint *)(*plVar10 + (ulong)uVar7) = uVar2;
              break;
            }
            uVar7 = *(uint *)(plVar10 + 0x29);
          }
          uVar8 = uVar8 + 1;
          uVar11 = uVar11 + 0x80;
        } while (uVar8 < uVar7);
      }
    }
    mutex_unlock(plVar10 + 3);
    lVar5 = (long)param_4;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// dcc_ready @ 00101d40 size=172
// signature: undefined dcc_ready(void)
// callers: [trigger_store, enable_store, dcc_enable]
//------------------------------------------------------------

bool dcc_ready(long *param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = ktime_get();
  uVar2 = readl(*param_1 + 0x1c);
  if ((uVar2 & 3) != 0) {
    do {
      lVar3 = ktime_get();
      if (lVar1 + 100000 < lVar3) {
        uVar2 = readl(*param_1 + 0x1c);
        return (uVar2 & 3) == 0;
      }
      usleep_range_state(1,1,2);
      Yield();
      uVar2 = readl(*param_1 + 0x1c);
    } while ((uVar2 & 3) != 0);
  }
  return true;
}



//------------------------------------------------------------
// readl @ 00101dec size=140
// signature: undefined readl(void)
// callers: [dcc_ready]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101e44,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// enable_show @ 00101e7c size=196
// signature: undefined enable_show(void)
// callers: []
//------------------------------------------------------------

long enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar7 + 0x18);
  uVar1 = *(uint *)(lVar7 + 0x148);
  if (*(byte *)(lVar7 + 0x14c) < uVar1) {
    if (**(char **)(lVar7 + 0x78) == '\0') {
      uVar2 = 1;
      do {
        uVar5 = uVar2;
        if (uVar1 == uVar5) break;
        uVar2 = uVar5 + 1;
      } while ((*(char **)(lVar7 + 0x78))[(int)uVar5] == '\0');
      bVar3 = uVar5 < uVar1;
    }
    else {
      bVar3 = true;
    }
    iVar4 = scnprintf(param_3,0x1000,&DAT_001054c1,bVar3);
    lVar6 = (long)iVar4;
  }
  else {
    _dev_err(param_1,"Select link list to program using curr_list\n");
    lVar6 = -0x16;
  }
  mutex_unlock(lVar7 + 0x18);
  return lVar6;
}



//------------------------------------------------------------
// enable_store @ 00101f44 size=528
// signature: undefined enable_store(void)
// callers: []
//------------------------------------------------------------

void enable_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  long *plVar10;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  plVar10 = *(long **)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  lVar3 = -0x16;
  if ((iVar2 != 0) || (1 < local_40)) goto LAB_00102124;
  if (local_40 == 0) {
    mutex_lock(plVar10 + 3);
    uVar4 = dcc_ready(plVar10);
    if ((uVar4 & 1) == 0) {
      _dev_err(plVar10[2],"DCC is not ready Disabling DCC...\n");
      uVar8 = *(uint *)(plVar10 + 0x29);
    }
    else {
      uVar8 = *(uint *)(plVar10 + 0x29);
    }
    if (uVar8 != 0) {
      uVar6 = 0;
      uVar5 = 0x28;
      do {
        if (*(char *)(plVar10[0xf] + (long)(int)uVar6) != '\0') {
          uVar7 = uVar6 << 7;
          uVar8 = uVar6 << 7 | 0x38;
          if ((int)plVar10[0xd] == 1) {
            uVar9 = uVar7 | 0x30;
          }
          else {
            uVar9 = uVar8;
            if ((int)plVar10[0xd] == 0) {
              uVar9 = uVar5 - 8;
            }
          }
          *(undefined4 *)(*plVar10 + (ulong)uVar9) = 0;
          if ((int)plVar10[0xd] == 1) {
            uVar9 = uVar7 | 0x34;
          }
          else if ((int)plVar10[0xd] == 0) {
            uVar9 = uVar5 - 4;
          }
          else {
            uVar9 = uVar7 | 0x3c;
          }
          *(undefined4 *)(*plVar10 + (ulong)uVar9) = 0;
          if ((int)plVar10[0xd] != 1) {
            if ((int)plVar10[0xd] == 0) {
              uVar8 = uVar5;
            }
            else {
              uVar8 = uVar7 | 0x40;
            }
          }
          *(undefined4 *)(*plVar10 + (ulong)uVar8) = 0;
          if ((int)plVar10[0xd] == 1) {
            uVar7 = uVar7 | 0x2c;
          }
          else if ((int)plVar10[0xd] == 0) {
            uVar7 = uVar5 - 0xc;
          }
          else {
            uVar7 = uVar7 | 0x34;
          }
          *(undefined4 *)(*plVar10 + (ulong)uVar7) = 0;
          *(undefined1 *)(plVar10[0xf] + (long)(int)uVar6) = 0;
          uVar8 = *(uint *)(plVar10 + 0x29);
        }
        uVar6 = uVar6 + 1;
        uVar5 = uVar5 + 0x80;
      } while (uVar6 < uVar8);
    }
    __memset_io(plVar10[9],0,(int)plVar10[10]);
    *(undefined8 *)((long)plVar10 + 0x6c) = 0;
    *(undefined4 *)((long)plVar10 + 0x15c) = 0;
    mutex_unlock(plVar10 + 3);
LAB_0010211c:
    iVar2 = param_4;
  }
  else {
    iVar2 = dcc_enable(plVar10);
    if (iVar2 == 0) goto LAB_0010211c;
  }
  lVar3 = (long)iVar2;
LAB_00102124:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// dcc_enable @ 00102154 size=2992
// signature: undefined dcc_enable(void)
// callers: [dcc_configure_list, enable_store]
//------------------------------------------------------------

int dcc_enable(long *param_1)

{
  long *plVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  long *plVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  long lVar26;
  int local_6c;
  long local_68;
  
  lVar26 = sp_el0;
  local_68 = *(long *)(lVar26 + 0x638);
  local_6c = 0;
  uVar21 = *(undefined8 *)(param_1[2] + 0x2e8);
  mutex_lock(param_1 + 3);
  uVar11 = *(uint *)(param_1 + 0x29);
  if (uVar11 == 0) {
LAB_001021d8:
    __memset_io(param_1[9],0xde,(int)param_1[10]);
    if ((int)param_1[0x29] == 0) {
      iVar24 = 0;
      goto LAB_00102c00;
    }
  }
  else if (*(char *)param_1[0xf] == '\0') {
    uVar25 = 1;
    do {
      uVar14 = uVar25;
      if (uVar11 == uVar14) break;
      uVar25 = uVar14 + 1;
    } while (((char *)param_1[0xf])[(int)uVar14] == '\0');
    if (uVar11 <= uVar14) goto LAB_001021d8;
  }
  uVar11 = 0;
  iVar24 = 0;
  do {
    lVar26 = (long)(int)uVar11;
    plVar1 = (long *)(param_1[0x27] + (long)(int)uVar11 * 0x10);
    if ((long *)*plVar1 != plVar1) {
      if (*(char *)(param_1[0xf] + lVar26) == '\0') {
        uVar14 = uVar11 << 7;
        uVar25 = uVar11 << 7 | 0x34;
        if ((int)param_1[0xd] == 1) {
          uVar12 = uVar14 | 0x2c;
        }
        else {
          uVar12 = uVar25;
          if ((int)param_1[0xd] == 0) {
            uVar12 = uVar14 | 0x1c;
          }
        }
        if ((*(uint *)(*param_1 + (ulong)uVar12) & 1) == 0) {
          _dev_info(param_1[2],"DCC list passed %d\n",uVar11);
          if ((int)param_1[0xd] == 1) {
            uVar12 = uVar14 | 0x2c;
          }
          else {
            uVar12 = uVar25;
            if ((int)param_1[0xd] == 0) {
              uVar12 = uVar14 | 0x1c;
            }
          }
          *(undefined4 *)(*param_1 + (ulong)uVar12) = 1;
          plVar1 = (long *)(param_1[0x27] + lVar26 * 0x10);
          iVar24 = *(int *)((long)param_1 + 0x6c);
          plVar15 = (long *)*plVar1;
          uVar12 = iVar24 << 2;
          if (plVar15 == plVar1) {
            iVar7 = 0;
LAB_0010233c:
            uVar22 = *(uint *)(param_1 + 10);
            if (uVar12 <= uVar22 - 4) {
              *(undefined4 *)(param_1[9] + (ulong)uVar12) = 0xc0000000;
              uVar19 = uVar12 + 4;
              if ((*(int *)(param_1[0xb] + lVar26 * 4) == 0) &&
                 (*(int *)(param_1[0xc] + lVar26 * 4) == 0)) {
                uVar12 = uVar19 + iVar7;
                uVar22 = *(uint *)(param_1 + 10);
                *(uint *)((long)param_1 + 0x6c) = uVar12 >> 2;
                if (uVar12 <= uVar22) goto LAB_001023ac;
              }
              else {
                uVar22 = *(uint *)(param_1 + 10);
                *(uint *)((long)param_1 + 0x6c) = uVar19 >> 2;
                if (uVar19 <= uVar22) {
LAB_001023ac:
                  *(uint *)(param_1 + 0xe) = uVar19 >> 2;
                  if ((int)param_1[0xd] == 1) {
                    uVar12 = uVar25;
                  }
                  else {
                    uVar12 = uVar14 | 0x3c;
                    if ((int)param_1[0xd] == 0) {
                      uVar12 = uVar14 | 0x24;
                    }
                  }
                  uVar19 = uVar14 | 0x40;
                  *(uint *)(*param_1 + (ulong)uVar12) =
                       iVar24 + (*(uint *)((long)param_1 + 0x54) >> 2);
                  if ((int)param_1[0xd] == 1) {
                    uVar12 = uVar14 | 0x38;
                  }
                  else {
                    uVar12 = uVar19;
                    if ((int)param_1[0xd] == 0) {
                      uVar12 = uVar14 | 0x28;
                    }
                  }
                  *(uint *)(*param_1 + (ulong)uVar12) =
                       (int)param_1[0xe] + (*(uint *)((long)param_1 + 0x54) >> 2);
                  uVar12 = uVar14 | 0x44;
                  uVar13 = uVar14 | 0x3c;
                  if (((int)param_1[0xd] != 1) && (uVar13 = uVar12, (int)param_1[0xd] == 0)) {
                    uVar13 = uVar14 | 0x2c;
                  }
                  *(undefined4 *)(*param_1 + (ulong)uVar13) = 0xfff;
                  if ((*(uint *)(*param_1 + 4) >> 7 & 1) == 0) {
LAB_001027f0:
                    iVar24 = 0;
                  }
                  else {
                    iVar7 = of_property_read_variable_u32_array
                                      (uVar21,"qcom,transaction_timeout",&local_6c,1,0);
                    iVar24 = iVar7;
                    if (-1 < iVar7) {
                      iVar24 = 0;
                    }
                    if (iVar7 < 0) {
                      local_6c = 0x3f;
                    }
                    else if (local_6c == 0) goto LAB_001027f0;
                    if ((int)param_1[0xd] != 1) {
                      if ((int)param_1[0xd] == 0) {
                        uVar19 = uVar14 | 0x30;
                      }
                      else {
                        uVar19 = uVar14 | 0x48;
                      }
                    }
                    *(int *)(*param_1 + (ulong)uVar19) = local_6c;
                  }
                  uVar19 = uVar14 | 0x4c;
                  if ((int)param_1[0xd] == 1) {
                    uVar13 = uVar12;
                  }
                  else {
                    uVar13 = uVar19;
                    if ((int)param_1[0xd] == 0) {
                      uVar13 = uVar14 | 0x30;
                    }
                  }
                  *(undefined4 *)(*param_1 + (ulong)uVar13) = 0;
                  if ((int)param_1[0xd] == 1) {
                    uVar25 = 0x48;
LAB_001028f0:
                    uVar25 = uVar14 | uVar25;
                  }
                  else if ((int)param_1[0xd] != 0) {
                    uVar25 = 0x50;
                    goto LAB_001028f0;
                  }
                  *(undefined4 *)(*param_1 + (ulong)uVar25) = 7;
                  _dev_info(param_1[2],"All values written to enable.\n");
                  DataSynchronizationBarrier(3,3,0);
                  *(undefined1 *)(param_1[0xf] + lVar26) = 1;
                  if (*(int *)(param_1[0xc] + lVar26 * 4) == 1) {
                    uVar8 = dcc_ready(param_1);
                    if ((uVar8 & 1) == 0) {
                      _dev_err(param_1[2],"DCC is not ready\n");
                    }
                    if ((int)param_1[0xd] == 1) {
                      uVar8 = 0x58;
LAB_0010296c:
                      uVar8 = (ulong)*(byte *)((long)param_1 + 0x14c) << 7 | uVar8;
                    }
                    else {
                      if ((int)param_1[0xd] == 0) {
                        uVar8 = 0x44;
                        goto LAB_0010296c;
                      }
                      uVar8 = (ulong)*(byte *)((long)param_1 + 0x14c) << 7 | 0x60;
                    }
                    *(undefined4 *)(*param_1 + uVar8) = 1;
                    uVar8 = dcc_ready(param_1);
                    if ((uVar8 & 1) == 0) {
                      _dev_err(param_1[2],"DCC is not ready\n");
                    }
                    if ((int)param_1[0xd] == 0) {
                      uVar8 = 0x44;
LAB_001029bc:
                      uVar8 = (ulong)*(byte *)((long)param_1 + 0x14c) << 7 | uVar8;
                    }
                    else {
                      if ((int)param_1[0xd] == 1) {
                        uVar8 = 0x58;
                        goto LAB_001029bc;
                      }
                      uVar8 = (ulong)*(byte *)((long)param_1 + 0x14c) << 7 | 0x60;
                    }
                    *(undefined4 *)(*param_1 + uVar8) = 1;
                    if ((int)param_1[0xd] == 1) {
                      uVar8 = 0x48;
LAB_00102a00:
                      uVar8 = (ulong)*(byte *)((long)param_1 + 0x14c) << 7 | uVar8;
                    }
                    else {
                      if ((int)param_1[0xd] == 0) {
                        uVar8 = 0x34;
                        goto LAB_00102a00;
                      }
                      uVar8 = (ulong)*(byte *)((long)param_1 + 0x14c) << 7 | 0x50;
                    }
                    *(undefined4 *)(*param_1 + uVar8) = 2;
                    if ((char)param_1[0x13] == '\0') {
                      if (((int)param_1[0xd] != 1) && (uVar12 = uVar19, (int)param_1[0xd] == 0)) {
                        uVar12 = uVar14 | 0x30;
                      }
                      *(undefined4 *)(*param_1 + (ulong)uVar12) = 2;
                    }
                  }
                  iVar7 = (int)param_1[0xd];
                  if (iVar7 == 2) {
                    *(uint *)(*param_1 + (ulong)(uVar14 | 0x6c)) =
                         (uint)*(byte *)(param_1[0x2f] + lVar26);
                    if ((int)param_1[0xd] == 1) {
                      uVar19 = uVar14 | 0x60;
                    }
                    else if ((int)param_1[0xd] != 0) {
                      uVar19 = uVar14 | 0x68;
                    }
                    *(uint *)(*param_1 + (ulong)uVar19) = (uint)*(byte *)(param_1[0x2a] + lVar26);
                    uVar25 = *(uint *)(param_1[0xc] + lVar26 * 4);
                    uVar19 = uVar14 | 0x38;
                    iVar7 = (int)param_1[0xd];
                    uVar12 = *(int *)(param_1[0xb] + lVar26 * 4) << 4;
                    if (*(char *)(param_1[0x10] + lVar26) == '\0') {
                      if (iVar7 == 1) {
                        uVar19 = uVar14 | 0x30;
                      }
                      else if (iVar7 == 0) {
                        uVar19 = uVar14 | 0x20;
                      }
                      *(uint *)(*param_1 + (ulong)uVar19) = (uVar25 | uVar12) & 0xfffffeff;
                    }
                    else {
                      if (iVar7 == 1) {
                        uVar19 = uVar14 | 0x30;
                      }
                      else if (iVar7 == 0) {
                        uVar19 = uVar14 | 0x20;
                      }
                      *(uint *)(*param_1 + (ulong)uVar19) = uVar12 | uVar25 | 0x100;
                    }
                  }
                  else {
                    uVar25 = *(uint *)(param_1[0xc] + lVar26 * 4);
                    uVar12 = (uint)*(byte *)(param_1[0x2a] + lVar26) << 8;
                    uVar19 = *(int *)(param_1[0xb] + lVar26 * 4) << 4;
                    uVar13 = uVar14 | 0x38;
                    if (*(char *)(param_1[0x10] + lVar26) == '\0') {
                      if (iVar7 == 1) {
                        uVar13 = uVar14 | 0x30;
                      }
                      else if (iVar7 == 0) {
                        uVar13 = uVar14 | 0x20;
                      }
                      *(uint *)(*param_1 + (ulong)uVar13) = (uVar12 | uVar25 | uVar19) & 0xfffffdff;
                    }
                    else {
                      if (iVar7 == 1) {
                        uVar13 = uVar14 | 0x30;
                      }
                      else if (iVar7 == 0) {
                        uVar13 = uVar14 | 0x20;
                      }
                      *(uint *)(*param_1 + (ulong)uVar13) = uVar19 | uVar25 | uVar12 | 0x200;
                    }
                  }
                  goto LAB_00102230;
                }
                uVar12 = uVar19;
              }
            }
LAB_00102c78:
            __memset_io(param_1[9],0,uVar22);
            lVar26 = param_1[2];
            pcVar9 = "DCC SRAM oversteps, 0x%x (0x%x)\n";
            uVar3 = (undefined4)param_1[10];
LAB_00102c9c:
            _dev_err(lVar26,pcVar9,uVar12,uVar3);
          }
          else {
            bVar5 = false;
            iVar16 = 0;
            iVar17 = 0;
            iVar7 = 0;
            uVar13 = 0;
            uVar19 = 0;
            uVar22 = 0;
            uVar23 = 0;
            do {
              iVar4 = (int)plVar15[-1];
              if (iVar4 == 1) {
                if (uVar23 != 0) {
                  uVar22 = *(uint *)(param_1 + 10);
                  if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                  uVar8 = (ulong)uVar12;
                  uVar12 = uVar12 + 4;
                  *(uint *)(param_1[9] + uVar8) = uVar23;
                }
                if (bVar5) {
                  uVar22 = *(uint *)(param_1 + 10);
                  if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                  uVar13 = uVar12 - uVar13;
                  uVar22 = uVar12 + 4;
                  iVar7 = iVar7 + (iVar7 - iVar17) * iVar16;
                  uVar8 = (ulong)uVar12;
                  uVar12 = 0;
                  *(uint *)(param_1[9] + uVar8) =
                       (int)(-1L << ((ulong)*(byte *)(param_1 + 0x2b) & 0x3f)) + 0x10000000U &
                       iVar16 << (ulong)(*(byte *)(param_1 + 0x2b) & 0x1f) | uVar13 >> 2 |
                       0x40000000;
                  iVar17 = 0;
                }
                else {
                  iVar16 = (int)plVar15[-3] + -1;
                  uVar22 = uVar12;
                  iVar17 = iVar7;
                }
                uVar19 = 0;
                uVar10 = 0;
                uVar18 = 0;
                bVar5 = (bool)(bVar5 ^ 1);
                uVar13 = uVar12;
              }
              else {
                uVar18 = uVar22;
                if (iVar4 == 3) {
                  if (uVar23 != 0) {
                    uVar22 = *(uint *)(param_1 + 10);
                    if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                    uVar19 = 0;
                    uVar8 = (ulong)uVar12;
                    uVar12 = uVar12 + 4;
                    *(uint *)(param_1[9] + uVar8) = uVar23;
                    uVar18 = 0;
                  }
                  uVar22 = *(uint *)(param_1 + 10);
                  if (uVar12 <= uVar22 - 4) {
                    uVar22 = 0x10000000;
                    if (*(char *)((long)plVar15 + -0xc) != '\0') {
                      uVar22 = 0x30000000;
                    }
                    *(uint *)(param_1[9] + (ulong)uVar12) = uVar22 | *(uint *)(plVar15 + -5) >> 4;
                    uVar22 = *(uint *)(param_1 + 10);
                    uVar2 = uVar12 + 4;
                    if (uVar2 <= uVar22 - 4) {
                      *(uint *)(param_1[9] + (ulong)uVar2) =
                           (*(uint *)(plVar15 + -4) & 0x7f) << 8 |
                           *(uint *)((long)plVar15 + -0x24) >> 2 & 0xff | uVar23 | 0xc0008000;
                      uVar22 = *(uint *)(param_1 + 10);
                      uVar2 = uVar12 + 8;
                      if (uVar2 <= uVar22 - 4) {
                        uVar10 = 0;
                        *(undefined4 *)(param_1[9] + (ulong)uVar2) =
                             *(undefined4 *)((long)plVar15 + -0x14);
                        uVar22 = uVar12 + 0xc;
                        goto LAB_00102424;
                      }
                    }
LAB_00102c64:
                    uVar12 = uVar2;
                  }
                  goto LAB_00102c78;
                }
                if (iVar4 == 2) {
                  if (uVar23 == 0) {
                    uVar23 = uVar12;
                  }
                  else {
                    uVar22 = *(uint *)(param_1 + 10);
                    if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                    uVar19 = 0;
                    *(uint *)(param_1[9] + (ulong)uVar12) = uVar23;
                    uVar23 = uVar12 + 4;
                    uVar18 = 0;
                  }
                  uVar22 = *(uint *)(param_1 + 10);
                  uVar12 = uVar23;
                  if (uVar22 - 4 < uVar23) goto LAB_00102c78;
                  *(undefined4 *)(param_1[9] + (ulong)uVar23) = 0x80000000;
                  uVar22 = *(uint *)(param_1 + 10);
                  uVar12 = uVar23 + 4;
                  if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                  *(int *)(param_1[9] + (ulong)uVar12) = (int)plVar15[-2];
                  uVar22 = *(uint *)(param_1 + 10);
                  uVar2 = uVar23 + 8;
                  if (uVar22 - 4 < uVar2) goto LAB_00102c64;
                  uVar10 = 0;
                  *(undefined4 *)(param_1[9] + (ulong)uVar2) =
                       *(undefined4 *)((long)plVar15 + -0x14);
                  uVar22 = uVar23 + 0xc;
                }
                else {
                  uVar2 = *(uint *)((long)plVar15 + -0x24) >> 2;
                  uVar18 = *(uint *)(plVar15 + -5) >> 4;
                  if (*(char *)((long)plVar15 + -0xc) != '\0') {
                    uVar18 = *(uint *)(plVar15 + -5) >> 4 | 0x20000000;
                  }
                  lVar6 = plVar15[-4];
                  if (((uVar22 == 0) || (uVar22 != uVar18)) || (uVar2 < uVar19)) {
                    if (uVar23 != 0) {
                      uVar22 = *(uint *)(param_1 + 10);
                      if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                      uVar8 = (ulong)uVar12;
                      uVar12 = uVar12 + 4;
                      *(uint *)(param_1[9] + uVar8) = uVar23;
                    }
                    uVar22 = *(uint *)(param_1 + 10);
                    if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                    uVar19 = 0;
                    uVar23 = 0;
                    uVar8 = (ulong)uVar12;
                    uVar12 = uVar12 + 4;
                    *(uint *)(param_1[9] + uVar8) = uVar18;
                  }
                  if ((0xff < uVar2 - uVar19) || (uVar22 = *(uint *)(plVar15 + -4), 0x7f < uVar22))
                  {
                    uVar12 = *(uint *)(plVar15 + -5);
                    uVar3 = *(undefined4 *)((long)plVar15 + -0x24);
                    lVar26 = param_1[2];
                    pcVar9 = "DCC: Programming error Base: 0x%x, offset 0x%x\n";
                    goto LAB_00102c9c;
                  }
                  uVar20 = 0;
                  if (uVar23 != 0) {
                    uVar20 = 0xf;
                  }
                  uVar10 = 0xc0008000;
                  if (uVar23 != 0) {
                    uVar10 = uVar23 & 0x7fff | 0xc0000000;
                  }
                  uVar10 = ((uVar22 & 0x7f) << 8 | uVar2 - uVar19) << (ulong)uVar20 | uVar10;
                  if (uVar23 != 0) {
                    uVar22 = *(uint *)(param_1 + 10);
                    if (uVar22 - 4 < uVar12) goto LAB_00102c78;
                    uVar8 = (ulong)uVar12;
                    uVar12 = uVar12 + 4;
                    *(uint *)(param_1[9] + uVar8) = uVar10;
                    uVar10 = 0;
                    uVar22 = *(uint *)(plVar15 + -4);
                  }
                  iVar7 = iVar7 + (int)lVar6 * 4;
                  uVar19 = (uVar2 + uVar22) - 1;
                  uVar22 = uVar12;
                }
              }
LAB_00102424:
              uVar12 = uVar22;
              plVar15 = (long *)*plVar15;
              uVar22 = uVar18;
              uVar23 = uVar10;
            } while (plVar15 != (long *)(param_1[0x27] + lVar26 * 0x10));
            if (uVar10 == 0) {
              if (!bVar5) goto LAB_0010233c;
            }
            else {
              uVar22 = *(uint *)(param_1 + 10);
              if (uVar22 - 4 < uVar12) goto LAB_00102c78;
              *(uint *)(param_1[9] + (ulong)uVar12) = uVar10;
              if (!bVar5) {
                uVar12 = uVar12 + 4;
                goto LAB_0010233c;
              }
            }
            _dev_err(param_1[2],"DCC: Programming error: Loop unterminated\n");
          }
          if ((int)param_1[0xd] == 1) {
            uVar25 = uVar14 | 0x2c;
          }
          else if ((int)param_1[0xd] == 0) {
            uVar25 = uVar14 | 0x1c;
          }
          *(undefined4 *)(*param_1 + (ulong)uVar25) = 0;
          _dev_info(param_1[2],"DCC ram programming failed\n");
          iVar24 = -0x16;
          goto LAB_00102c0c;
        }
        _dev_err(param_1[2],"List %d is already locked\n",uVar11);
      }
      else {
        _dev_err(param_1[2],"List %d is already enabled\n",uVar11);
      }
    }
LAB_00102230:
    uVar11 = uVar11 + 1;
  } while (uVar11 < *(uint *)(param_1 + 0x29));
LAB_00102c00:
  *(int *)((long)param_1 + 0x15c) = *(int *)((long)param_1 + 0x6c) << 2;
LAB_00102c0c:
  mutex_unlock(param_1 + 3);
  lVar26 = sp_el0;
  if (*(long *)(lVar26 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar24;
}



//------------------------------------------------------------
// hw_trig_show @ 00102d08 size=100
// signature: undefined hw_trig_show(void)
// callers: []
//------------------------------------------------------------

long hw_trig_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if ((uint)*(byte *)(lVar2 + 0x14c) < *(uint *)(lVar2 + 0x148)) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_001054c1,
                      *(undefined1 *)(*(long *)(lVar2 + 0x80) + (ulong)*(byte *)(lVar2 + 0x14c)));
    lVar2 = (long)iVar1;
  }
  else {
    _dev_err(param_1,"Select link list to program using curr_list\n");
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// hw_trig_store @ 00102d70 size=252
// signature: undefined hw_trig_store(void)
// callers: []
//------------------------------------------------------------

long hw_trig_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0x10,&local_50);
  lVar3 = -0x16;
  if ((iVar2 == 0) && (local_50 < 2)) {
    mutex_lock(lVar4 + 0x18);
    bVar1 = *(byte *)(lVar4 + 0x14c);
    if ((uint)bVar1 < *(uint *)(lVar4 + 0x148)) {
      if (*(char *)(*(long *)(lVar4 + 0x78) + (ulong)bVar1) == '\0') {
        lVar3 = (long)param_4;
        *(bool *)(*(long *)(lVar4 + 0x80) + (ulong)bVar1) = local_50 != 0;
      }
      else {
        lVar3 = -0x10;
      }
    }
    else {
      _dev_err(param_1,"Select link list to program using curr_list\n");
    }
    mutex_unlock(lVar4 + 0x18);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// sw_trig_show @ 00102e70 size=100
// signature: undefined sw_trig_show(void)
// callers: []
//------------------------------------------------------------

long sw_trig_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if ((uint)*(byte *)(lVar2 + 0x14c) < *(uint *)(lVar2 + 0x148)) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_001054c1,
                      *(undefined1 *)(*(long *)(lVar2 + 0x88) + (ulong)*(byte *)(lVar2 + 0x14c)));
    lVar2 = (long)iVar1;
  }
  else {
    _dev_err(param_1,"Select link list to program using curr_list\n");
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// sw_trig_store @ 00102ed8 size=204
// signature: undefined sw_trig_store(void)
// callers: []
//------------------------------------------------------------

void sw_trig_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  lVar2 = -0x16;
  if ((iVar1 == 0) && (local_40 < 2)) {
    if ((uint)*(byte *)(lVar3 + 0x14c) < *(uint *)(lVar3 + 0x148)) {
      lVar2 = (long)param_4;
      *(bool *)(*(long *)(lVar3 + 0x88) + (ulong)*(byte *)(lVar3 + 0x14c)) = local_40 != 0;
    }
    else {
      _dev_err(param_1,"Select link list to program using curr_list\n");
      lVar2 = -0x16;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// config_show @ 00102fa8 size=484
// signature: undefined config_show(void)
// callers: []
//------------------------------------------------------------

long config_show(long param_1,undefined8 param_2,undefined1 *param_3)

{
  long *plVar1;
  undefined4 uVar3;
  undefined4 uVar2;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  uint uVar12;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x98);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  *param_3 = 0;
  mutex_lock(lVar11 + 0x18);
  if ((uint)*(byte *)(lVar11 + 0x14c) < *(uint *)(lVar11 + 0x148)) {
    plVar1 = (long *)(*(long *)(lVar11 + 0x138) + (ulong)*(byte *)(lVar11 + 0x14c) * 0x10);
    plVar10 = (long *)*plVar1;
    if (plVar10 == plVar1) {
      uVar9 = 0;
    }
    else {
      uVar12 = 0;
      do {
        iVar7 = (int)plVar10[-1];
        if (iVar7 == 1) {
          iVar7 = scnprintf(&local_a8,0x40,"Index: 0x%x, Loop: %d\n",
                            *(undefined4 *)((long)plVar10 + -0x1c),(int)plVar10[-3]);
        }
        else {
          if (iVar7 == 3) {
            uVar2 = (undefined4)plVar10[-5];
            uVar4 = *(undefined4 *)((long)plVar10 + -0x24);
            uVar3 = (undefined4)plVar10[-4];
            uVar5 = *(undefined4 *)((long)plVar10 + -0x1c);
            uVar6 = *(undefined1 *)((long)plVar10 + -0xc);
            pcVar8 = "Write Index: 0x%x, Base: 0x%x, Offset: 0x%x, len: 0x%x APB: %d\n";
          }
          else {
            if (iVar7 == 2) {
              iVar7 = scnprintf(&local_a8,0x40,"Index: 0x%x, mask: 0x%x, val: 0x%x\n",
                                *(undefined4 *)((long)plVar10 + -0x1c),(int)plVar10[-2],
                                *(undefined4 *)((long)plVar10 + -0x14));
              goto LAB_001030d8;
            }
            uVar2 = (undefined4)plVar10[-5];
            uVar4 = *(undefined4 *)((long)plVar10 + -0x24);
            uVar3 = (undefined4)plVar10[-4];
            uVar5 = *(undefined4 *)((long)plVar10 + -0x1c);
            uVar6 = *(undefined1 *)((long)plVar10 + -0xc);
            pcVar8 = "Read Index: 0x%x, Base: 0x%x, Offset: 0x%x, len: 0x%x APB: %d\n";
          }
          iVar7 = scnprintf(&local_a8,0x40,pcVar8,uVar5,uVar2,uVar4,uVar3,uVar6);
        }
LAB_001030d8:
        uVar9 = iVar7 + uVar12;
        if (0x1000 < uVar9) {
          pcVar8 = "DCC: Couldn\'t write complete config\n";
          uVar9 = uVar12;
          goto LAB_00103138;
        }
        strlcat(param_3,&local_a8,0x1000);
        plVar10 = (long *)*plVar10;
        uVar12 = uVar9;
      } while (plVar10 !=
               (long *)(*(long *)(lVar11 + 0x138) + (ulong)*(byte *)(lVar11 + 0x14c) * 0x10));
    }
  }
  else {
    uVar9 = 0xffffffea;
    pcVar8 = "Select link list to program using curr_list\n";
LAB_00103138:
    _dev_err(param_1,pcVar8);
  }
  mutex_unlock(lVar11 + 0x18);
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)(int)uVar9;
}



//------------------------------------------------------------
// config_store @ 00103190 size=244
// signature: undefined config_store(void)
// callers: []
//------------------------------------------------------------

void config_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint local_34;
  int local_30;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x98);
  local_2c = 0;
  local_34 = 0;
  local_30 = 0;
  iVar2 = sscanf(param_3,"%x %i %d",&local_34,&local_2c,&local_30);
  lVar3 = -0x16;
  if (((iVar2 - 4U < 0xfffffffd) || (local_30 < 0)) || (1 < local_30)) goto LAB_00103258;
  if (iVar2 == 1) {
    local_2c = 1;
LAB_00103238:
    uVar4 = 0;
    local_30 = 0;
  }
  else {
    if ((iVar2 != 3) || (local_30 != 1)) goto LAB_00103238;
    uVar4 = 1;
    local_30 = 1;
  }
  iVar2 = dcc_config_add(uVar5,local_34,local_2c,uVar4);
  lVar3 = param_4;
  if (iVar2 != 0) {
    lVar3 = (long)iVar2;
  }
LAB_00103258:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// dcc_config_add @ 00103284 size=504
// signature: undefined dcc_config_add(void)
// callers: [dcc_dt_parse, config_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dcc_config_add(long param_1,uint param_2,uint param_3,int param_4)

{
  uint *puVar1;
  byte bVar2;
  uint *puVar3;
  ulong uVar4;
  char *pcVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  undefined8 uVar10;
  long *plVar11;
  uint uVar12;
  
  mutex_lock(param_1 + 0x18);
  if ((uint)*(byte *)(param_1 + 0x14c) < *(uint *)(param_1 + 0x148)) {
    if ((param_3 != 0) && (param_3 <= *(uint *)(param_1 + 0x50) >> 3)) {
      plVar11 = (long *)(*(long *)(param_1 + 0x138) + (ulong)*(byte *)(param_1 + 0x14c) * 0x10);
      if (((long *)*plVar11 == plVar11) || (lVar9 = plVar11[1], *(int *)(lVar9 + -8) != 0)) {
LAB_0010330c:
        uVar12 = param_2 & 0xfffffff0;
LAB_00103310:
        param_2 = param_2 - uVar12;
        do {
          puVar3 = (uint *)kmalloc_trace(_strcmp,0xdc0,0x38);
          if (puVar3 == (uint *)0x0) {
            uVar10 = 0xfffffff4;
            goto LAB_00103428;
          }
          bVar2 = *(byte *)(param_1 + 0x14c);
          lVar9 = *(long *)(param_1 + 0x140);
          uVar8 = param_3;
          if (0x7e < param_3) {
            uVar8 = 0x7f;
          }
          *puVar3 = uVar12;
          puVar3[1] = param_2;
          lVar7 = (ulong)bVar2 * 4;
          puVar1 = puVar3 + 10;
          puVar3[2] = uVar8;
          uVar8 = *(uint *)(lVar9 + lVar7);
          *(uint *)(lVar9 + lVar7) = uVar8 + 1;
          puVar3[3] = uVar8;
          puVar3[8] = 0;
          *(bool *)(puVar3 + 7) = param_4 != 0;
          *(uint **)(puVar3 + 10) = puVar1;
          *(uint **)(puVar3 + 0xc) = puVar1;
          lVar9 = *(long *)(param_1 + 0x138) + (ulong)*(byte *)(param_1 + 0x14c) * 0x10;
          plVar11 = *(long **)(lVar9 + 8);
          uVar4 = __list_add_valid(puVar1,plVar11,lVar9);
          if ((uVar4 & 1) != 0) {
            *(uint **)(lVar9 + 8) = puVar1;
            *(long *)(puVar3 + 10) = lVar9;
            *(long **)(puVar3 + 0xc) = plVar11;
            *plVar11 = (long)puVar1;
          }
          param_2 = param_2 + 0x1fc;
          param_3 = param_3 - puVar3[2];
        } while (param_3 != 0);
      }
      else {
        uVar12 = *(uint *)(lVar9 + -0x28);
        uVar8 = *(int *)(lVar9 + -0x24) + uVar12;
        if ((param_2 < uVar8) || (uVar8 + 0x3fc < param_2)) goto LAB_0010330c;
        if (uVar8 + *(int *)(lVar9 + -0x20) * 4 != param_2) goto LAB_00103310;
        param_3 = *(int *)(lVar9 + -0x20) + param_3;
        uVar6 = param_3;
        if (0x7e < param_3) {
          uVar6 = 0x7f;
        }
        param_3 = param_3 - uVar6;
        *(uint *)(lVar9 + -0x20) = uVar6;
        if (param_3 != 0) {
          param_2 = uVar8 + uVar6 * 4;
          goto LAB_00103310;
        }
      }
      uVar10 = 0;
      goto LAB_00103428;
    }
    pcVar5 = "DCC: Invalid length\n";
  }
  else {
    pcVar5 = "Select link list to program using curr_list\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x10),pcVar5);
  uVar10 = 0xffffffea;
LAB_00103428:
  mutex_unlock(param_1 + 0x18);
  return uVar10;
}



//------------------------------------------------------------
// config_reset_store @ 00103480 size=148
// signature: undefined config_reset_store(void)
// callers: []
//------------------------------------------------------------

void config_reset_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x98);
  local_30 = 0;
  iVar2 = kstrtoull(param_3,0x10,&local_30);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_30 < 2)) {
    if (local_30 != 0) {
      dcc_config_reset(uVar4);
    }
    uVar3 = param_4;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// dcc_config_reset @ 00103514 size=248
// signature: undefined dcc_config_reset(void)
// callers: [dcc_remove, config_reset_store]
//------------------------------------------------------------

void dcc_config_reset(long param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  long *plVar7;
  
  mutex_lock(param_1 + 0x18);
  uVar4 = *(uint *)(param_1 + 0x148);
  if (uVar4 != 0) {
    uVar5 = 0;
    lVar3 = *(long *)(param_1 + 0x138);
    do {
      plVar7 = (long *)(lVar3 + (long)(int)uVar5 * 0x10);
      plVar6 = (long *)*plVar7;
      if (plVar6 != plVar7) {
        do {
          plVar7 = (long *)*plVar6;
          uVar2 = __list_del_entry_valid(plVar6);
          if ((uVar2 & 1) != 0) {
            lVar3 = *plVar6;
            plVar1 = (long *)plVar6[1];
            *(long **)(lVar3 + 8) = plVar1;
            *plVar1 = lVar3;
          }
          *plVar6 = -0x2152ffffffffff00;
          plVar6[1] = -0x2152fffffffffede;
          kfree(plVar6 + -5);
          lVar3 = (long)(int)uVar5 * 4;
          *(int *)(*(long *)(param_1 + 0x140) + lVar3) =
               *(int *)(*(long *)(param_1 + 0x140) + lVar3) + -1;
          lVar3 = *(long *)(param_1 + 0x138);
          plVar6 = plVar7;
        } while (plVar7 != (long *)(lVar3 + (long)(int)uVar5 * 0x10));
        uVar4 = *(uint *)(param_1 + 0x148);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar4);
  }
  *(undefined8 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  mutex_unlock(param_1 + 0x18);
  return;
}



//------------------------------------------------------------
// ready_show @ 00103610 size=188
// signature: undefined ready_show(void)
// callers: []
//------------------------------------------------------------

long ready_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  plVar3 = *(long **)(param_1 + 0x98);
  mutex_lock(plVar3 + 3);
  if ((uint)*(byte *)((long)plVar3 + 0x14c) < *(uint *)(plVar3 + 0x29)) {
    if (*(char *)(plVar3[0xf] + (ulong)*(byte *)((long)plVar3 + 0x14c)) != '\0') {
      lVar2 = 0xc;
      if ((int)plVar3[0xd] != 0) {
        lVar2 = 0x1c;
      }
      iVar1 = scnprintf(param_3,0x1000,&DAT_001054c1,*(uint *)(*plVar3 + lVar2) >> 1 & 1);
      lVar2 = (long)iVar1;
      goto LAB_001036ac;
    }
  }
  else {
    _dev_err(param_1,"Select link list to program using curr_list\n");
  }
  lVar2 = -0x16;
LAB_001036ac:
  mutex_unlock(plVar3 + 3);
  return lVar2;
}



//------------------------------------------------------------
// crc_error_show @ 001036d0 size=216
// signature: undefined crc_error_show(void)
// callers: []
//------------------------------------------------------------

long crc_error_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  
  plVar6 = *(long **)(param_1 + 0x98);
  mutex_lock(plVar6 + 3);
  bVar3 = *(byte *)((long)plVar6 + 0x14c);
  if ((uint)bVar3 < *(uint *)(plVar6 + 0x29)) {
    if (*(char *)(plVar6[0xf] + (ulong)bVar3) != '\0') {
      uVar1 = (uint)bVar3 << 7 | 0x50;
      if ((int)plVar6[0xd] == 0) {
        uVar1 = (uint)bVar3 << 7 | 0x34;
      }
      uVar2 = (uint)bVar3 << 7 | 0x48;
      if ((int)plVar6[0xd] != 1) {
        uVar2 = uVar1;
      }
      iVar4 = scnprintf(param_3,0x1000,&DAT_001054c1,*(uint *)(*plVar6 + (ulong)uVar2) >> 1 & 1);
      lVar5 = (long)iVar4;
      goto LAB_00103788;
    }
  }
  else {
    _dev_err(param_1,"Select link list to program using curr_list\n");
  }
  lVar5 = -0x16;
LAB_00103788:
  mutex_unlock(plVar6 + 3);
  return lVar5;
}



//------------------------------------------------------------
// interrupt_disable_show @ 001037ac size=60
// signature: undefined interrupt_disable_show(void)
// callers: []
//------------------------------------------------------------

long interrupt_disable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001054c1,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0x98));
  return (long)iVar1;
}



//------------------------------------------------------------
// interrupt_disable_store @ 001037ec size=180
// signature: undefined interrupt_disable_store(void)
// callers: []
//------------------------------------------------------------

void interrupt_disable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_40 < 2)) {
    lVar1 = lVar4 + 0x18;
    mutex_lock(lVar1);
    *(bool *)(lVar4 + 0x98) = local_40 != 0;
    mutex_unlock(lVar1);
    uVar3 = param_4;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// loop_store @ 001038a4 size=364
// signature: undefined loop_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 loop_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  undefined8 local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x98);
  local_60 = 0;
  mutex_lock(lVar8 + 0x18);
  iVar3 = kstrtoull(param_3,0x10,&local_60);
  uVar2 = local_60;
  if (iVar3 == 0) {
    if ((uint)*(byte *)(lVar8 + 0x14c) < *(uint *)(lVar8 + 0x148)) {
      lVar4 = kmalloc_trace(_strcmp,0xdc0,0x38);
      if (lVar4 == 0) {
        param_4 = 0xfffffffffffffff4;
      }
      else {
        uVar6 = (uint)uVar2;
        if (0xfe < uVar6) {
          uVar6 = 0xff;
        }
        lVar1 = lVar4 + 0x28;
        *(uint *)(lVar4 + 0x10) = uVar6;
        lVar7 = (ulong)*(byte *)(lVar8 + 0x14c) * 4;
        iVar3 = *(int *)(*(long *)(lVar8 + 0x140) + lVar7);
        *(int *)(*(long *)(lVar8 + 0x140) + lVar7) = iVar3 + 1;
        *(int *)(lVar4 + 0xc) = iVar3;
        *(undefined4 *)(lVar4 + 0x20) = 1;
        *(long *)(lVar4 + 0x28) = lVar1;
        *(long *)(lVar4 + 0x30) = lVar1;
        lVar7 = *(long *)(lVar8 + 0x138) + (ulong)*(byte *)(lVar8 + 0x14c) * 0x10;
        plVar9 = *(long **)(lVar7 + 8);
        uVar5 = __list_add_valid(lVar1,plVar9,lVar7);
        if ((uVar5 & 1) != 0) {
          *(long *)(lVar7 + 8) = lVar1;
          *(long *)(lVar4 + 0x28) = lVar7;
          *(long **)(lVar4 + 0x30) = plVar9;
          *plVar9 = lVar1;
        }
      }
      goto LAB_00103908;
    }
    _dev_err(param_1,"Select link list to program using curr_list\n");
  }
  param_4 = 0xffffffffffffffea;
LAB_00103908:
  mutex_unlock(lVar8 + 0x18);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// rd_mod_wr_store @ 00103a14 size=156
// signature: undefined rd_mod_wr_store(void)
// callers: []
//------------------------------------------------------------

void rd_mod_wr_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x98);
  local_30 = 0;
  iVar2 = sscanf(param_3,"%x %x",(uint *)((long)&local_30 + 4),(uint *)&local_30);
  if (iVar2 == 2) {
    iVar2 = dcc_rd_mod_wr_add(uVar3,local_30._4_4_,local_30 & 0xffffffff);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// dcc_rd_mod_wr_add @ 00103ab0 size=320
// signature: undefined dcc_rd_mod_wr_add(void)
// callers: [rd_mod_wr_store, dcc_dt_parse]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dcc_rd_mod_wr_add(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  byte bVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long *plVar9;
  
  mutex_lock(param_1 + 0x18);
  if ((uint)*(byte *)(param_1 + 0x14c) < *(uint *)(param_1 + 0x148)) {
    plVar9 = (long *)(*(long *)(param_1 + 0x138) + (ulong)*(byte *)(param_1 + 0x14c) * 0x10);
    if ((long *)*plVar9 == plVar9) {
      _dev_err(*(undefined8 *)(param_1 + 0x10),"DCC: No read address programmed\n");
      uVar8 = 0xffffffff;
    }
    else {
      lVar4 = kmalloc_trace(_strcmp,0xdc0,0x38);
      if (lVar4 == 0) {
        uVar8 = 0xfffffff4;
      }
      else {
        bVar3 = *(byte *)(param_1 + 0x14c);
        lVar7 = *(long *)(param_1 + 0x140);
        *(undefined4 *)(lVar4 + 0x14) = param_3;
        *(undefined4 *)(lVar4 + 0x18) = param_2;
        lVar1 = lVar4 + 0x28;
        lVar6 = (ulong)bVar3 * 4;
        *(undefined4 *)(lVar4 + 0x20) = 2;
        iVar2 = *(int *)(lVar7 + lVar6);
        *(int *)(lVar7 + lVar6) = iVar2 + 1;
        *(int *)(lVar4 + 0xc) = iVar2;
        *(long *)(lVar4 + 0x28) = lVar1;
        *(long *)(lVar4 + 0x30) = lVar1;
        lVar6 = *(long *)(param_1 + 0x138) + (ulong)*(byte *)(param_1 + 0x14c) * 0x10;
        plVar9 = *(long **)(lVar6 + 8);
        uVar5 = __list_add_valid(lVar1,plVar9,lVar6);
        uVar8 = 0;
        if ((uVar5 & 1) != 0) {
          *(long *)(lVar6 + 8) = lVar1;
          *(long *)(lVar4 + 0x28) = lVar6;
          *(long **)(lVar4 + 0x30) = plVar9;
          *plVar9 = lVar1;
        }
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x10),"Select link list to program using curr_list\n");
    uVar8 = 0xffffffea;
  }
  mutex_unlock(param_1 + 0x18);
  return uVar8;
}



//------------------------------------------------------------
// curr_list_show @ 00103bf4 size=136
// signature: undefined curr_list_show(void)
// callers: []
//------------------------------------------------------------

long curr_list_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x18;
  mutex_lock(lVar1);
  if (*(char *)(lVar3 + 0x14c) == -1) {
    _dev_err(param_1,"curr_list is not set.\n");
    lVar3 = -0x16;
  }
  else {
    iVar2 = scnprintf(param_3,0x1000,&DAT_00105574);
    lVar3 = (long)iVar2;
  }
  mutex_unlock(lVar1);
  return lVar3;
}



//------------------------------------------------------------
// curr_list_store @ 00103c80 size=376
// signature: undefined curr_list_store(void)
// callers: []
//------------------------------------------------------------

undefined8 curr_list_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  long *plVar8;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  plVar8 = *(long **)(param_1 + 0x98);
  local_40 = 0;
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if ((iVar3 != 0) || (*(uint *)(plVar8 + 0x29) <= local_40)) {
    param_4 = 0xffffffffffffffea;
    goto LAB_00103d04;
  }
  mutex_lock(plVar8 + 3);
  uVar6 = *(uint *)(plVar8 + 0x29);
  if (uVar6 == 0) {
LAB_00103d74:
    if ((int)plVar8[0xd] == 1) {
      uVar6 = (int)local_40 << 7 | 0x2c;
    }
    else if ((int)plVar8[0xd] == 0) {
      uVar6 = (int)local_40 << 7 | 0x1c;
    }
    else {
      uVar6 = (int)local_40 << 7 | 0x34;
    }
    if ((*(uint *)(*plVar8 + (ulong)uVar6) & 1) != 0) {
      lVar4 = plVar8[2];
      pcVar5 = "DCC linked list is already configured\n";
      goto LAB_00103de8;
    }
    *(char *)((long)plVar8 + 0x14c) = (char)local_40;
  }
  else {
    if (*(char *)plVar8[0xf] == '\0') {
      uVar1 = 1;
      do {
        uVar7 = uVar1;
        if (uVar6 == uVar7) break;
        uVar1 = uVar7 + 1;
      } while (((char *)plVar8[0xf])[(int)uVar7] == '\0');
      bVar2 = uVar7 < uVar6;
    }
    else {
      bVar2 = true;
    }
    if ((*(char *)((long)plVar8 + 0x14c) == -1) || (!bVar2)) goto LAB_00103d74;
    lVar4 = plVar8[2];
    pcVar5 = "DCC is enabled, please disable it first.\n";
LAB_00103de8:
    _dev_err(lVar4,pcVar5);
    param_4 = 0xffffffffffffffea;
  }
  mutex_unlock(plVar8 + 3);
LAB_00103d04:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// config_write_store @ 00103dfc size=452
// signature: undefined config_write_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 config_write_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long *plVar11;
  int local_64;
  uint local_60;
  uint local_5c;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x98);
  local_5c = 0;
  local_64 = 0;
  local_60 = 0;
  mutex_lock(lVar10 + 0x18);
  iVar5 = sscanf(param_3,"%x %x %d",&local_5c,&local_60,&local_64);
  uVar4 = local_5c;
  uVar2 = local_60;
  iVar3 = local_64;
  uVar9 = 0xffffffffffffffea;
  if (((0xfffffffd < iVar5 - 4U) && (-1 < local_64)) && (local_64 < 2)) {
    if ((uint)*(byte *)(lVar10 + 0x14c) < *(uint *)(lVar10 + 0x148)) {
      puVar6 = (uint *)kmalloc_trace(_strcmp,0xdc0,0x38);
      if (puVar6 == (uint *)0x0) {
        uVar9 = 0xfffffffffffffff4;
      }
      else {
        puVar6[5] = uVar2;
        puVar6[8] = 3;
        puVar1 = puVar6 + 10;
        *puVar6 = uVar4 & 0xfffffff0;
        puVar6[1] = uVar4 & 0xf;
        lVar8 = (ulong)*(byte *)(lVar10 + 0x14c) * 4;
        uVar2 = *(uint *)(*(long *)(lVar10 + 0x140) + lVar8);
        *(uint *)(*(long *)(lVar10 + 0x140) + lVar8) = uVar2 + 1;
        puVar6[2] = 1;
        puVar6[3] = uVar2;
        *(bool *)(puVar6 + 7) = iVar3 != 0;
        *(uint **)(puVar6 + 10) = puVar1;
        *(uint **)(puVar6 + 0xc) = puVar1;
        lVar8 = *(long *)(lVar10 + 0x138) + (ulong)*(byte *)(lVar10 + 0x14c) * 0x10;
        plVar11 = *(long **)(lVar8 + 8);
        uVar7 = __list_add_valid(puVar1,plVar11,lVar8);
        uVar9 = param_4;
        if ((uVar7 & 1) != 0) {
          *(uint **)(lVar8 + 8) = puVar1;
          *(long *)(puVar6 + 10) = lVar8;
          *(long **)(puVar6 + 0xc) = plVar11;
          *plVar11 = (long)puVar1;
        }
      }
    }
    else {
      _dev_err(param_1,"Select link list to program using curr_list\n");
    }
  }
  mutex_unlock(lVar10 + 0x18);
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// cti_trig_show @ 00103fc4 size=64
// signature: undefined cti_trig_show(void)
// callers: []
//------------------------------------------------------------

long cti_trig_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105574,
                    *(undefined1 *)
                     (*(long *)(*(long *)(param_1 + 0x98) + 0x150) +
                     (ulong)*(byte *)(*(long *)(param_1 + 0x98) + 0x14c)));
  return (long)iVar1;
}



//------------------------------------------------------------
// cti_trig_store @ 00104008 size=252
// signature: undefined cti_trig_store(void)
// callers: []
//------------------------------------------------------------

long cti_trig_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0x10,&local_50);
  lVar3 = -0x16;
  if ((iVar2 == 0) && (local_50 < 2)) {
    mutex_lock(lVar4 + 0x18);
    bVar1 = *(byte *)(lVar4 + 0x14c);
    if ((uint)bVar1 < *(uint *)(lVar4 + 0x148)) {
      if (*(char *)(*(long *)(lVar4 + 0x78) + (ulong)bVar1) == '\0') {
        lVar3 = (long)param_4;
        *(bool *)(*(long *)(lVar4 + 0x150) + (ulong)bVar1) = local_50 != 0;
      }
      else {
        lVar3 = -0x10;
      }
    }
    else {
      _dev_err(param_1,"Select link list to program using curr_list\n");
    }
    mutex_unlock(lVar4 + 0x18);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// ap_ns_qad_override_en_show @ 00104108 size=100
// signature: undefined ap_ns_qad_override_en_show(void)
// callers: []
//------------------------------------------------------------

long ap_ns_qad_override_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar2 + 0x68) == 2) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00105574,
                      *(undefined1 *)(*(long *)(lVar2 + 0x178) + (ulong)*(byte *)(lVar2 + 0x14c)));
    lVar2 = (long)iVar1;
  }
  else {
    _dev_err(param_1,"QAD output is not supported\n");
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// ap_ns_qad_override_en_store @ 00104170 size=284
// signature: undefined ap_ns_qad_override_en_store(void)
// callers: []
//------------------------------------------------------------

long ap_ns_qad_override_en_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  if (*(int *)(lVar4 + 0x68) == 2) {
    iVar2 = kstrtoull(param_3,0x10,&local_50);
    lVar3 = -0x16;
    if ((iVar2 == 0) && (local_50 < 2)) {
      mutex_lock(lVar4 + 0x18);
      bVar1 = *(byte *)(lVar4 + 0x14c);
      if ((uint)bVar1 < *(uint *)(lVar4 + 0x148)) {
        if (*(char *)(*(long *)(lVar4 + 0x78) + (ulong)bVar1) == '\0') {
          lVar3 = (long)param_4;
          *(bool *)(*(long *)(lVar4 + 0x178) + (ulong)bVar1) = local_50 != 0;
        }
        else {
          lVar3 = -0x10;
        }
      }
      else {
        _dev_err(param_1,"Select link list to program using curr_list\n");
      }
      mutex_unlock(lVar4 + 0x18);
    }
  }
  else {
    _dev_err(param_1,"QAD output is not supported\n");
    lVar3 = -0x16;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// dcc_dt_parse @ 0010428c size=960
// signature: undefined dcc_dt_parse(void)
// callers: [dcc_configure_list]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int dcc_dt_parse(long param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  char *__s1;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  uint *puVar13;
  ulong uVar14;
  undefined4 uVar15;
  long lVar16;
  uint uVar17;
  long lVar18;
  uint *puVar19;
  long *plVar20;
  uint uVar21;
  char *local_78;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_6c = 0;
  local_70 = 0;
  local_78 = (char *)0x0;
  iVar10 = of_property_read_variable_u32_array(param_2,"qcom,curr-link-list",&local_70,1,0);
  if (iVar10 < 0) goto LAB_001045b0;
  if (local_70 < *(uint *)(param_1 + 0x148)) {
    *(char *)(param_1 + 0x14c) = (char)local_70;
    lVar12 = of_find_property(param_2,"qcom,ap-qad-override",0);
    if (lVar12 != 0) {
      *(undefined1 *)(*(long *)(param_1 + 0x178) + (ulong)*(byte *)(param_1 + 0x14c)) = 1;
    }
    *(undefined4 *)(*(long *)(param_1 + 0x58) + (ulong)local_70 * 4) = 0;
    iVar10 = of_property_read_string(param_2,"qcom,data-sink",&local_78);
    __s1 = local_78;
    if (iVar10 == 0) {
      iVar11 = strcmp(local_78,"sram");
      if (iVar11 == 0) {
        uVar15 = 0;
      }
      else {
        iVar11 = strcmp(__s1,"atb");
        if (iVar11 != 0) {
          uVar21 = *(uint *)(*(long *)(param_1 + 0x58) + (ulong)local_70 * 4);
          if (1 < uVar21) {
                    /* WARNING: Does not return */
            pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10464c);
            (*pcVar8)();
          }
          _dev_err(*(undefined8 *)(param_1 + 0x10),
                   "Unknown sink type for DCC Using \'%s\' as data sink\n",
                   (&str_dcc_data_sink)[uVar21]);
          goto LAB_001043a0;
        }
        uVar15 = 1;
      }
      *(undefined4 *)(*(long *)(param_1 + 0x58) + (ulong)local_70 * 4) = uVar15;
    }
LAB_001043a0:
    lVar12 = of_get_property(param_2,"qcom,link-list",&local_6c);
    if ((lVar12 == 0) || (uVar21 = local_6c >> 2, bVar9 = local_6c < 4, local_6c = uVar21, bVar9))
    goto LAB_001045b0;
    uVar21 = 0;
    do {
      uVar1 = *(uint *)(lVar12 + (long)(int)uVar21 * 4);
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
      if (3 < uVar1) {
        iVar10 = -0x16;
        goto LAB_0010462c;
      }
      uVar17 = *(uint *)(lVar12 + (long)(int)(uVar21 + 1) * 4);
      uVar2 = *(uint *)(lVar12 + (long)(int)(uVar21 + 2) * 4);
      uVar3 = *(uint *)(lVar12 + (long)(int)(uVar21 + 3) * 4);
      uVar6 = (uVar17 & 0xff00ff00) >> 8;
      uVar5 = uVar6 | (uVar17 & 0xff00ff) << 8;
      uVar7 = uVar5 >> 0x10;
      uVar5 = uVar5 << 0x10;
      uVar17 = uVar7 | uVar5;
      uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
      uVar2 = uVar2 >> 0x10 | uVar2 << 0x10;
      switch(uVar1) {
      case 0:
        uVar1 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
        iVar10 = dcc_config_add(param_1,uVar17,uVar2,uVar1 >> 0x10 | uVar1 << 0x10);
        goto joined_r0x001043f8;
      case 1:
        puVar13 = (uint *)kmalloc_trace(_strcmp,0xdc0,0x38);
        if (puVar13 == (uint *)0x0) {
LAB_00104620:
          iVar10 = -0xc;
          goto LAB_0010462c;
        }
        bVar4 = *(byte *)(param_1 + 0x14c);
        lVar16 = *(long *)(param_1 + 0x140);
        puVar13[5] = uVar2;
        puVar13[8] = 3;
        lVar18 = (ulong)bVar4 * 4;
        puVar19 = puVar13 + 10;
        *puVar13 = uVar7 & 0xfffffff0 | uVar5;
        puVar13[1] = (uVar6 & 0xf0000) >> 0x10;
        uVar1 = *(uint *)(lVar16 + lVar18);
        *(uint *)(lVar16 + lVar18) = uVar1 + 1;
        puVar13[2] = 1;
        puVar13[3] = uVar1;
        *(bool *)(puVar13 + 7) = uVar3 != 0;
        *(uint **)(puVar13 + 10) = puVar19;
        *(uint **)(puVar13 + 0xc) = puVar19;
        lVar18 = *(long *)(param_1 + 0x138) + (ulong)*(byte *)(param_1 + 0x14c) * 0x10;
        plVar20 = *(long **)(lVar18 + 8);
        uVar14 = __list_add_valid(puVar19,plVar20,lVar18);
        if ((uVar14 & 1) != 0) {
          *(uint **)(lVar18 + 8) = puVar19;
          *(long *)(puVar13 + 10) = lVar18;
LAB_00104590:
          *(long **)(puVar13 + 0xc) = plVar20;
          *plVar20 = (long)puVar19;
        }
        break;
      case 2:
        puVar13 = (uint *)kmalloc_trace(_strcmp,0xdc0,0x38);
        if (puVar13 == (uint *)0x0) goto LAB_00104620;
        lVar18 = *(long *)(param_1 + 0x140);
        if (0xfe < uVar17) {
          uVar17 = 0xff;
        }
        puVar19 = puVar13 + 10;
        lVar16 = (ulong)*(byte *)(param_1 + 0x14c) * 4;
        puVar13[4] = uVar17;
        uVar1 = *(uint *)(lVar18 + lVar16);
        *(uint *)(lVar18 + lVar16) = uVar1 + 1;
        puVar13[3] = uVar1;
        puVar13[8] = 1;
        *(uint **)(puVar13 + 10) = puVar19;
        *(uint **)(puVar13 + 0xc) = puVar19;
        lVar18 = *(long *)(param_1 + 0x138) + (ulong)*(byte *)(param_1 + 0x14c) * 0x10;
        plVar20 = *(long **)(lVar18 + 8);
        uVar14 = __list_add_valid(puVar19,plVar20,lVar18);
        if ((uVar14 & 1) != 0) {
          *(uint **)(lVar18 + 8) = puVar19;
          *(long *)(puVar13 + 10) = lVar18;
          goto LAB_00104590;
        }
        break;
      case 3:
        iVar10 = dcc_rd_mod_wr_add(param_1,uVar17,uVar2);
joined_r0x001043f8:
        if (iVar10 != 0) {
LAB_0010462c:
          _dev_err(*(undefined8 *)(param_1 + 0x10),"DCC init time config failed err:%d\n",iVar10);
          goto LAB_001045b0;
        }
      }
      uVar21 = uVar21 + 4;
    } while (uVar21 < local_6c);
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x10),"List configuration failed.\n");
  }
  iVar10 = 0;
LAB_001045b0:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar10;
}



//------------------------------------------------------------
// dcc_v2_freeze @ 00104650 size=580
// signature: undefined dcc_v2_freeze(void)
// callers: []
//------------------------------------------------------------

int dcc_v2_freeze(long param_1)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined4 *puVar10;
  ulong uVar11;
  undefined4 *puVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  long *plVar16;
  
  plVar16 = *(long **)(param_1 + 0x98);
  if (plVar16 == (long *)0x0) {
    return -0x16;
  }
  uVar3 = *(uint *)(plVar16 + 0x29);
  if (uVar3 == 0) {
    return 0;
  }
  if (*(char *)plVar16[0xf] == '\0') {
    uVar4 = 1;
    do {
      uVar13 = uVar4;
      if (uVar3 == uVar13) {
        return 0;
      }
      uVar4 = uVar13 + 1;
    } while (((char *)plVar16[0xf])[(int)uVar13] == '\0');
    if (uVar3 <= uVar13) {
      return 0;
    }
  }
  uVar3 = *(uint *)((long)plVar16 + 0x164);
  uVar15 = (ulong)(int)uVar3;
  if (uVar3 == 0) {
    return 0;
  }
  if ((int)uVar3 < 0) {
LAB_00104838:
    _dev_err(param_1,"Failed to alloc memory for reg_offsets\n");
    return -0xc;
  }
  lVar8 = __kmalloc(uVar15 * 4,0xdc0);
  if (lVar8 == 0) goto LAB_00104838;
  iVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2e8),"ll-reg-offsets",lVar8,uVar15,uVar15);
  if (-1 < iVar7) {
    lVar9 = __kmalloc(uVar15 << 3,0xdc0);
    plVar16[0x2d] = lVar9;
    if (lVar9 == 0) {
      iVar7 = -0xc;
      goto LAB_001047a0;
    }
    puVar10 = (undefined4 *)__kmalloc((int)plVar16[10],0xdc0);
    plVar16[0x2e] = (long)puVar10;
    if (puVar10 == (undefined4 *)0x0) {
      iVar7 = -0xc;
    }
    else {
      uVar4 = *(uint *)((long)plVar16 + 0x15c);
      uVar11 = (ulong)uVar4;
      if ((uVar4 != 0) && (puVar12 = (undefined4 *)plVar16[9], (((uint)puVar12 | uVar4) & 3) == 0))
      {
        if (uVar4 < 4) {
          mutex_lock(plVar16 + 3);
        }
        else {
          do {
            uVar5 = *puVar12;
            puVar12 = puVar12 + 1;
            uVar11 = uVar11 - 4;
            *puVar10 = uVar5;
            puVar10 = puVar10 + 1;
          } while (3 < uVar11);
          mutex_lock(plVar16 + 3);
          if ((int)uVar3 < 1) goto LAB_00104820;
        }
        uVar14 = uVar15 & 0x3fffffffffffffff;
        lVar9 = 0;
        uVar11 = 0;
        if ((uVar15 & 0x2000000000000000) != 0) {
          uVar14 = 0x2000000000000000;
        }
        do {
          if (((uVar14 == 0) || ((long)uVar11 < 0)) || (uVar15 * 4 <= uVar11)) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(1,0x104894);
            (*pcVar6)();
          }
          uVar14 = uVar14 - 1;
          *(undefined4 *)(plVar16[0x2d] + lVar9) = *(undefined4 *)(lVar8 + uVar11);
          puVar1 = (uint *)(lVar8 + uVar11);
          uVar11 = uVar11 + 4;
          lVar2 = plVar16[0x2d] + lVar9;
          lVar9 = lVar9 + 8;
          *(undefined4 *)(lVar2 + 4) = *(undefined4 *)(*plVar16 + (ulong)*puVar1);
        } while ((ulong)uVar3 * 4 != uVar11);
LAB_00104820:
        mutex_unlock(plVar16 + 3);
        kfree(lVar8);
        return 0;
      }
      _dev_err(param_1,"Failed to copy DCC SRAM contents\n");
      kfree(plVar16[0x2e]);
      iVar7 = -0x16;
      plVar16[0x2e] = 0;
    }
    kfree(plVar16[0x2d]);
    plVar16[0x2d] = 0;
  }
LAB_001047a0:
  kfree(lVar8);
  return iVar7;
}



//------------------------------------------------------------
// dcc_v2_thaw @ 00104898 size=112
// signature: undefined dcc_v2_thaw(void)
// callers: []
//------------------------------------------------------------

undefined8 dcc_v2_thaw(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (((lVar2 == 0) || (*(long *)(lVar2 + 0x168) == 0)) || (*(long *)(lVar2 + 0x170) == 0)) {
    _dev_err(param_1,"Err: %s Invalid argument\n","dcc_v2_thaw");
    uVar1 = 0xffffffea;
  }
  else {
    kfree(*(long *)(lVar2 + 0x170));
    kfree(*(undefined8 *)(lVar2 + 0x168));
    uVar1 = 0;
    *(undefined8 *)(lVar2 + 0x168) = 0;
    *(undefined8 *)(lVar2 + 0x170) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// dcc_v2_restore @ 0010490c size=432
// signature: undefined dcc_v2_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 dcc_v2_restore(long param_1)

{
  long *plVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  long *plVar13;
  
  plVar13 = *(long **)(param_1 + 0x98);
  if (plVar13 == (long *)0x0) {
    _dev_err(param_1,"Err: %s Invalid argument\n","dcc_state_restore");
    return 0xffffffea;
  }
  uVar9 = *(uint *)(plVar13 + 0x29);
  if (uVar9 != 0) {
    if (*(char *)plVar13[0xf] == '\0') {
      uVar5 = 1;
      do {
        uVar10 = uVar5;
        if (uVar9 == uVar10) goto LAB_00104a30;
        uVar5 = uVar10 + 1;
      } while (((char *)plVar13[0xf])[(int)uVar10] == '\0');
      if (uVar9 <= uVar10) goto LAB_00104a30;
    }
    iVar4 = *(int *)((long)plVar13 + 0x164);
    if (iVar4 != 0) {
      lVar6 = plVar13[0x2e];
      if ((lVar6 == 0) || (plVar13[0x2d] == 0)) {
        _dev_err(param_1,"Err: Restore state is NULL\n");
        uVar12 = 0xffffffea;
        goto LAB_00104a34;
      }
      uVar9 = *(uint *)((long)plVar13 + 0x15c);
      if (3 < uVar9) {
        uVar8 = 0;
        do {
          if (uVar8 <= (int)plVar13[10] - 4) {
            *(undefined4 *)(plVar13[9] + uVar8) = *(undefined4 *)(lVar6 + uVar8);
          }
          uVar8 = uVar8 + 4;
        } while (((ulong)uVar9 & 0xfffffffc) != uVar8);
      }
      mutex_lock(plVar13 + 3);
      uVar9 = *(uint *)(plVar13 + 0x29);
      if ((uVar9 != 0) && (0 < iVar4)) {
        uVar5 = 0;
        iVar7 = 0;
        uVar10 = *(uint *)(plVar13 + 0x2c);
        do {
          plVar1 = (long *)(plVar13[0x27] + (long)(int)uVar5 * 0x10);
          if ((long *)*plVar1 == plVar1) {
            iVar7 = uVar10 + iVar7;
          }
          else if (uVar10 != 0) {
            uVar11 = 0;
            do {
              iVar3 = iVar7 + uVar11;
              uVar11 = uVar11 + 1;
              puVar2 = (uint *)(plVar13[0x2d] + (long)iVar3 * 8);
              *(uint *)(*plVar13 + (ulong)*puVar2) = puVar2[1];
              uVar10 = *(uint *)(plVar13 + 0x2c);
            } while (uVar11 < uVar10);
            uVar9 = *(uint *)(plVar13 + 0x29);
            iVar7 = iVar7 + uVar11;
          }
          uVar5 = uVar5 + 1;
        } while ((uVar5 < uVar9) && (iVar7 < iVar4));
      }
      mutex_unlock(plVar13 + 3);
    }
  }
LAB_00104a30:
  uVar12 = 0;
LAB_00104a34:
  kfree(plVar13[0x2e]);
  plVar13[0x2e] = 0;
  kfree(plVar13[0x2d]);
  plVar13[0x2d] = 0;
  return uVar12;
}



//------------------------------------------------------------
// init_module @ 00104b28 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&dcc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104b58 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&dcc_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00107000 size=1
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
// platform_driver_unregister @ 00107008 size=1
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
// devm_kmalloc @ 00107010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [dcc_probe, dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00107018 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [dcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00107020 size=1
// signature: undefined devm_ioremap(void)
// callers: [dcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00107028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [dcc_dt_parse, dcc_probe, dcc_v2_freeze, dcc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00107030 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [dcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00107038 size=1
// signature: undefined __mutex_init(void)
// callers: [dcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 00107040 size=1
// signature: undefined __memset_io(void)
// callers: [dcc_probe, enable_store, dcc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00107048 size=1
// signature: undefined strscpy(void)
// callers: [dcc_probe, dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00107050 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [dcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00107058 size=1
// signature: undefined _dev_info(void)
// callers: [trigger_store, dcc_probe, dcc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00107060 size=1
// signature: undefined _dev_err(void)
// callers: [enable_show, hw_trig_show, ap_ns_qad_override_en_store, dcc_rd_mod_wr_add, sw_trig_store, dcc_v2_thaw, dcc_v2_restore, data_sink_store, sw_trig_show, ready_show, hw_trig_store, dcc_create_files, curr_list_show, dcc_dt_parse, config_write_store, curr_list_store, dcc_v2_freeze, cti_trig_store, dcc_sram_read, trigger_store, dcc_config_add, dcc_configure_list, crc_error_show, loop_store, dcc_probe, func_type_store, config_show, enable_store, dcc_sram_dev_init, dcc_enable, ap_ns_qad_override_en_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hw_trig_store, rd_mod_wr_store, dcc_dt_parse, config_write_store, ap_ns_qad_override_en_store, config_store, curr_list_store, cti_trig_store, sw_trig_store, interrupt_disable_store, data_sink_store, trigger_store, loop_store, dcc_probe, func_type_store, config_show, enable_store, dcc_sram_dev_init, config_reset_store, dcc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00107070 size=1
// signature: undefined device_destroy(void)
// callers: [dcc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00107078 size=1
// signature: undefined class_destroy(void)
// callers: [dcc_remove, dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00107080 size=1
// signature: undefined cdev_del(void)
// callers: [dcc_remove, dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00107088 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [dcc_remove, dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00107090 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00107098 size=1
// signature: undefined cdev_init(void)
// callers: [dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001070a0 size=1
// signature: undefined cdev_add(void)
// callers: [dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001070a8 size=1
// signature: undefined __class_create(void)
// callers: [dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001070b0 size=1
// signature: undefined device_create(void)
// callers: [dcc_sram_dev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 001070b8 size=1
// signature: undefined device_create_file(void)
// callers: [dcc_create_files]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001070c0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [dcc_configure_list]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001070c8 size=1
// signature: undefined __kmalloc(void)
// callers: [dcc_v2_freeze, dcc_sram_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001070d0 size=1
// signature: undefined __check_object_size(void)
// callers: [dcc_sram_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001070e8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [dcc_sram_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001070f0 size=1
// signature: undefined kfree(void)
// callers: [dcc_v2_freeze, dcc_config_reset, dcc_sram_read, dcc_v2_thaw, dcc_v2_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00107100 size=1
// signature: undefined scnprintf(void)
// callers: [data_sink_show, enable_show, curr_list_show, func_type_show, hw_trig_show, crc_error_show, cti_trig_show, config_show, sw_trig_show, interrupt_disable_show, ready_show, ap_ns_qad_override_en_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00107108 size=1
// signature: size_t strlen(char * __s)
// callers: [data_sink_store, func_type_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00107110 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [rd_mod_wr_store, data_sink_store, config_write_store, func_type_store, config_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00107118 size=1
// signature: undefined mutex_lock(void)
// callers: [hw_trig_store, enable_show, curr_list_show, config_write_store, ap_ns_qad_override_en_store, curr_list_store, dcc_v2_freeze, dcc_config_reset, cti_trig_store, dcc_rd_mod_wr_add, interrupt_disable_store, dcc_v2_restore, data_sink_store, trigger_store, dcc_config_add, crc_error_show, loop_store, func_type_store, config_show, enable_store, ready_show, dcc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00107120 size=1
// signature: undefined mutex_unlock(void)
// callers: [hw_trig_store, enable_show, curr_list_show, config_write_store, ap_ns_qad_override_en_store, curr_list_store, dcc_v2_freeze, dcc_config_reset, cti_trig_store, dcc_rd_mod_wr_add, interrupt_disable_store, dcc_v2_restore, data_sink_store, trigger_store, dcc_config_add, crc_error_show, loop_store, func_type_store, config_show, enable_store, ready_show, dcc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00107128 size=1
// signature: undefined kstrtoull(void)
// callers: [hw_trig_store, trigger_store, loop_store, ap_ns_qad_override_en_store, curr_list_store, enable_store, cti_trig_store, config_reset_store, sw_trig_store, interrupt_disable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00107130 size=1
// signature: undefined ktime_get(void)
// callers: [dcc_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00107138 size=1
// signature: undefined usleep_range_state(void)
// callers: [dcc_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00107140 size=1
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
// log_post_read_mmio @ 00107148 size=1
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
// strlcat @ 00107150 size=1
// signature: undefined strlcat(void)
// callers: [config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00107160 size=1
// signature: undefined kmalloc_trace(void)
// callers: [dcc_config_add, dcc_dt_parse, config_write_store, loop_store, dcc_rd_mod_wr_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00107168 size=1
// signature: undefined __list_add_valid(void)
// callers: [dcc_config_add, dcc_dt_parse, config_write_store, loop_store, dcc_rd_mod_wr_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00107170 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [dcc_config_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00107178 size=1
// signature: undefined of_find_property(void)
// callers: [dcc_dt_parse]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00107180 size=1
// signature: undefined of_property_read_string(void)
// callers: [dcc_dt_parse]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00107188 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [dcc_dt_parse]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00107190 size=1
// signature: undefined of_get_property(void)
// callers: [dcc_dt_parse]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



