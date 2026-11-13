// Decompiled by Ghidra 12.2
// Program: memory_dump_v2.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_dump_table_version @ 0010049c size=8
// signature: undefined msm_dump_table_version(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_dump_table_version(void)

{
  return 0x200000;
}



//------------------------------------------------------------
// msm_dump_data_register @ 001004a8 size=492
// signature: undefined msm_dump_data_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_dump_data_register(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  char *__string;
  char local_68 [16];
  undefined8 local_58;
  ulong local_50;
  long local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if (DAT_00103140 == 0) {
    _printk(&DAT_00102bc9);
  }
  else {
    lVar5 = -0x3f00;
    do {
      if (*(int *)(DAT_00103140 + lVar5 + 0x3f08) == param_1) {
        lVar5 = *(long *)(DAT_00103140 + lVar5 + 0x3f30);
        if (lVar5 != 0) {
          uVar3 = DAT_00103140 + (lVar5 - memdump);
          if (0xfffffffffffff000 < uVar3) goto LAB_00100580;
          if ((uVar3 != 0) && (uVar1 = *(uint *)(uVar3 + 4), uVar1 < 0x150)) {
            lVar5 = uVar3 + (ulong)uVar1 * 0x30;
            *(uint *)(lVar5 + 8) = *param_2;
            *(undefined4 *)(lVar5 + 0x2c) = 0;
            uVar6 = *(undefined8 *)(param_2 + 10);
            *(uint *)(uVar3 + 4) = uVar1 + 1;
            *(undefined8 *)(lVar5 + 0x30) = uVar6;
            goto LAB_00100584;
          }
          uVar3 = 0xffffffea;
          goto LAB_0010063c;
        }
        break;
      }
      lVar5 = lVar5 + 0x30;
    } while (lVar5 != 0);
    _printk(&DAT_00102ba1);
  }
  uVar3 = 0xffffffffffffffea;
LAB_00100580:
  if ((int)uVar3 != 0) goto LAB_0010063c;
LAB_00100584:
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  uVar3 = *(long *)(param_2 + 10) - _memstart_addr | 0xffffff8000000000;
  if ((*(long *)(uVar3 + 0x28) == 0) || (*(long *)(uVar3 + 0x30) == 0)) {
LAB_00100668:
    _printk(&DAT_00102ac6);
  }
  else {
    __string = (char *)(uVar3 + 8);
    if (*__string == '\0') {
      snprintf(local_68,0xd,"KMDT0x%X",*param_2);
    }
    else {
      uVar4 = strnlen(__string,0xd);
      if (0x1f < uVar4) {
        fortify_panic("strnlen");
LAB_00100688:
        fortify_panic("strscpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (uVar4 != 0xd) {
        uVar4 = uVar4 + 1;
      }
      if (0xd < uVar4) goto LAB_00100688;
      strscpy(local_68,__string);
    }
    local_48 = *(long *)(uVar3 + 0x28);
    uStack_40 = *(undefined8 *)(uVar3 + 0x30);
    local_50 = local_48 - _memstart_addr | 0xffffff8000000000;
    local_58 = CONCAT44(local_58._4_4_,*param_2);
    iVar2 = msm_minidump_add_region(local_68);
    if (iVar2 < 0) goto LAB_00100668;
  }
  uVar3 = 0;
LAB_0010063c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// msm_dump_data_register_nominidump @ 00100698 size=208
// signature: undefined msm_dump_data_register_nominidump(void)
// callers: []
//------------------------------------------------------------

ulong msm_dump_data_register_nominidump(int param_1,undefined4 *param_2)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (DAT_00103140 == 0) {
    _printk(&DAT_00102bc9);
  }
  else {
    lVar3 = -0x3f00;
    do {
      if (*(int *)(DAT_00103140 + lVar3 + 0x3f08) == param_1) {
        lVar3 = *(long *)(DAT_00103140 + lVar3 + 0x3f30);
        if (lVar3 != 0) {
          uVar1 = DAT_00103140 + (lVar3 - memdump);
          if (0xfffffffffffff000 < uVar1) {
            return uVar1;
          }
          if ((uVar1 == 0) || (uVar2 = *(uint *)(uVar1 + 4), 0x14f < uVar2)) {
            return 0xffffffea;
          }
          lVar3 = uVar1 + (ulong)uVar2 * 0x30;
          *(undefined4 *)(lVar3 + 8) = *param_2;
          *(undefined4 *)(lVar3 + 0x2c) = 0;
          uVar4 = *(undefined8 *)(param_2 + 10);
          *(uint *)(uVar1 + 4) = uVar2 + 1;
          *(undefined8 *)(lVar3 + 0x30) = uVar4;
          return 0;
        }
        break;
      }
      lVar3 = lVar3 + 0x30;
    } while (lVar3 != 0);
    _printk(&DAT_00102ba1,param_1);
  }
  return 0xffffffffffffffea;
}



//------------------------------------------------------------
// mem_dump_probe @ 0010076c size=2908
// signature: undefined mem_dump_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mem_dump_probe(long param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  undefined8 *puVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  char *__string;
  undefined8 uVar15;
  bool bVar16;
  undefined4 *puVar17;
  bool bVar18;
  bool bVar19;
  long lVar20;
  undefined8 uStack_170;
  long lStack_168;
  undefined1 *puStack_160;
  code *pcStack_158;
  long lStack_150;
  long local_140;
  undefined4 *local_138;
  uint local_12c;
  long local_128;
  undefined8 local_120;
  ulong *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined4 *local_d8;
  long local_d0;
  size_t local_c8;
  long local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  undefined1 auStack_68 [8];
  
  lVar20 = sp_el0;
  lVar13 = param_1 + 0x10;
  local_70 = *(long *)(lVar20 + 0x638);
  uVar7 = dma_set_mask(lVar13,0xffffffffffffffff);
  if ((int)uVar7 == 0) {
    dma_set_coherent_mask(lVar13,0xffffffffffffffff);
  }
  else {
    uVar14 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) goto LAB_00100914;
  }
  uVar15 = *(undefined8 *)(param_1 + 0x2f8);
  local_d0 = 0;
  local_c8 = 0;
  local_e0 = 0;
  local_d8 = (undefined4 *)0x0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_108 = 0;
  local_100 = 0;
  local_118 = (ulong *)0x0;
  uStack_110 = 0;
  local_f8 = 6;
  uStack_f4 = 3;
  local_120 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  iVar3 = __of_parse_phandle_with_args(uVar15,"memory-region",0,0,0,&local_c0);
  if (((iVar3 == 0) && (local_c0 != 0)) &&
     (iVar3 = of_reserved_mem_device_init_by_idx(lVar13,*(undefined8 *)(param_1 + 0x2f8),0),
     iVar3 != 0)) {
    _dev_err(lVar13,"Failed to initialize reserved mem, ret %d\n",iVar3);
  }
  else {
    local_100 = local_100 & 0xffffffff;
    total_size = 0x7e10;
    puVar8 = (undefined8 *)of_get_next_available_child(uVar15,0);
    if (puVar8 == (undefined8 *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      do {
        iVar4 = of_property_read_variable_u32_array
                          (puVar8,"qcom,dump-size",(long)&local_100 + 4,1,0);
        if (iVar4 < 0) {
          _dev_err(lVar13,"Unable to find size for %s\n",*puVar8);
        }
        else {
          iVar3 = iVar3 + 1;
          total_size = total_size + (local_100 >> 0x20);
        }
        puVar8 = (undefined8 *)of_get_next_available_child(uVar15,puVar8);
      } while (puVar8 != (undefined8 *)0x0);
    }
    total_size = total_size + (long)iVar3 * 0x40 + 0xfff & 0xfffffffffffff000;
    puVar9 = (undefined4 *)dmam_alloc_attrs(lVar13,total_size,&local_108,0xcc0,0);
    if (puVar9 != (undefined4 *)0x0) {
      dma_get_sgtable_attrs(lVar13,&local_118,puVar9,local_108,total_size,0);
      lVar20 = ((*local_118 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40;
      lVar12 = lVar20 + 0x8000000000;
      sg_free_table(&local_118);
      sVar1 = total_size;
      memset(puVar9,0,total_size);
      uVar5 = qtee_shmbridge_register(lVar12,sVar1,&uStack_f4,&local_f8,1,6,&local_120);
      if (uVar5 != 0) {
        uVar14 = (ulong)uVar5;
        _dev_err(lVar13,"Failed to create shm bridge.ret=%d\n",uVar14);
        goto LAB_00100914;
      }
      DAT_00103140 = puVar9;
      *puVar9 = 0x200000;
      memdump = lVar12;
      puVar9[0xfc2] = 0x200000;
      puVar17 = DAT_00103140;
      if ((DAT_00103140 == (undefined4 *)0x0) || (uVar5 = DAT_00103140[1], 0x14f < uVar5)) {
        _printk(&DAT_00102c50);
        _dev_err(lVar13,"Memory Dump table set up is failed\n");
        qtee_shmbridge_deregister(local_120);
        uVar14 = 0xffffffea;
        goto LAB_00100914;
      }
      DAT_00103140[1] = uVar5 + 1;
      puVar17[(ulong)uVar5 * 0xc + 2] = 0;
      puVar17[(ulong)uVar5 * 0xc + 0xb] = 1;
      *(long *)(puVar17 + (ulong)uVar5 * 0xc + 0xc) = lVar20 + 0x8000003f08;
      _printk(&DAT_00102aef);
      register_syscore_ops(memory_dump_syscore_ops);
      iVar3 = qcom_scm_assign_dump_table_region(1,lVar12,total_size);
      if ((iVar3 != 0) && (uVar5 = init_memdump_imem_area(total_size), uVar5 != 0)) {
        uVar14 = (ulong)uVar5;
        qtee_shmbridge_deregister(local_120);
        goto LAB_00100914;
      }
      puVar8 = (undefined8 *)of_get_next_available_child(uVar15,0);
      local_140 = lVar12;
      if (puVar8 == (undefined8 *)0x0) {
        uVar14 = 0;
        local_12c = 0;
      }
      else {
        lVar20 = lVar20 + 0x8000007e10;
        puVar17 = puVar9 + 0x1f84;
        local_12c = 0;
        do {
          uVar6 = of_property_read_variable_u32_array
                            (puVar8,"qcom,dump-size",(long)&local_100 + 4,1,0);
          uVar5 = uVar6;
          if (-1 < (int)uVar6) {
            uVar5 = 0;
          }
          uVar14 = (ulong)uVar5;
          if (-1 < (int)uVar6) {
            uVar5 = of_property_read_variable_u32_array(puVar8,"qcom,dump-id",&local_100,1,0);
            if ((int)uVar5 < 0) {
              uVar14 = (ulong)uVar5;
              _dev_err(lVar13,"Unable to find id for %s\n",*puVar8);
            }
            else {
              uVar2 = (uint)local_100;
              *(long *)(puVar17 + 10) = lVar20 + 0x40;
              *(ulong *)(puVar17 + 0xc) = local_100 >> 0x20;
              __string = (char *)*puVar8;
              uVar7 = strnlen(__string,0x20);
              if (uVar7 == 0xffffffffffffffff) {
LAB_001012bc:
                uStack_170 = fortify_panic("strnlen");
                pcStack_158 = init_memdump_imem_area;
                lVar20 = sp_el0;
                lStack_168 = *(long *)(lVar20 + 0x638);
                puStack_160 = auStack_68 + 8;
                lStack_150 = lVar13;
                lVar13 = of_find_compatible_node(0,0,"qcom,msm-imem-mem_dump_table");
                if (lVar13 == 0) {
                  _printk(&DAT_00102eb6);
                  uVar7 = 0xffffffed;
                }
                else {
                  lVar13 = of_iomap(lVar13,0);
                  if (lVar13 == 0) {
                    _printk(&DAT_00102fc6);
                    uVar7 = 0xfffffff4;
                  }
                  else {
                    __memcpy_toio(lVar13,&memdump,8);
                    __memcpy_toio(lVar13 + 0x724,&uStack_170,8);
                    DataSynchronizationBarrier(3,3,0);
                    _printk(&DAT_00102c1d);
                    iounmap(lVar13);
                    uVar7 = 0;
                  }
                }
                lVar13 = sp_el0;
                if (*(long *)(lVar13 + 0x638) != lStack_168) {
                    /* WARNING: Subroutine does not return */
                  __stack_chk_fail(uVar7);
                }
                return uVar7;
              }
              if (uVar7 != 0x20) {
                uVar7 = uVar7 + 1;
              }
              if (0x20 < uVar7) {
                fortify_panic("strscpy");
                goto LAB_001012bc;
              }
              strscpy(puVar17 + 2,__string);
              local_128 = lVar20;
              if (DAT_00103140 == (undefined4 *)0x0) {
                _printk(&DAT_00102bc9);
              }
              else {
                lVar12 = -0x3f00;
                do {
                  if (*(int *)((long)DAT_00103140 + lVar12 + 0x3f08) == 0) {
                    lVar12 = *(long *)((long)DAT_00103140 + lVar12 + 0x3f30);
                    if (lVar12 != 0) {
                      uVar14 = (long)DAT_00103140 + (lVar12 - memdump);
                      if (0xfffffffffffff000 < uVar14) goto LAB_00100c94;
                      if ((uVar14 == 0) || (uVar5 = *(uint *)(uVar14 + 4), 0x14f < uVar5)) {
                        uVar14 = 0xffffffea;
                        goto LAB_00100d6c;
                      }
                      lVar12 = uVar14 + (ulong)uVar5 * 0x30;
                      *(uint *)(uVar14 + 4) = uVar5 + 1;
                      uVar14 = 0;
                      *(undefined4 *)(lVar12 + 8) = uVar2;
                      *(undefined4 *)(lVar12 + 0x2c) = 0;
                      *(long *)(lVar12 + 0x30) = lVar20;
                      goto LAB_00100c98;
                    }
                    break;
                  }
                  lVar12 = lVar12 + 0x30;
                } while (lVar12 != 0);
                _printk(&DAT_00102ba1,0);
              }
              uVar14 = 0xffffffffffffffea;
LAB_00100c94:
              if ((int)uVar14 != 0) {
LAB_00100d6c:
                _dev_err(lVar13,"Data dump setup failed, id = %d\n",local_100 & 0xffffffff);
              }
LAB_00100c98:
              uVar5 = (uint)local_100;
              if (((uint)local_100 == 0xef) || (((uint)local_100 & 0xfffffff8) == 0x1f0)) {
                lVar20 = *(long *)(param_1 + 0xa8);
                local_12c = local_100._4_4_;
                if (lVar20 == 0) {
                  lVar20 = devm_kmalloc(lVar13,0x78,0xdc0);
                  if (lVar20 != 0) {
                    __mutex_init(lVar20,"&cpudata->mutex",&cpuss_dump_init___key);
                    *(long *)(param_1 + 0xa8) = lVar20;
                    goto LAB_00100cf0;
                  }
                }
                else {
LAB_00100cf0:
                  local_138 = puVar17 + 0x10;
                  if (uVar5 == 0xef) {
                    puVar10 = (undefined8 *)devm_kmalloc(lVar13,0x20,0xdc0);
                    *(undefined8 **)(lVar20 + 0x30) = puVar10;
                    if (puVar10 != (undefined8 *)0x0) {
                      uVar5 = 1;
                      *puVar10 = local_138;
                      lVar20 = *(long *)(lVar20 + 0x30);
LAB_00100b00:
                      cpuss_dump_init_initialized = cpuss_dump_init_initialized | uVar5;
                      *(uint *)(lVar20 + 8) = local_12c;
                    }
                  }
                  else {
                    puVar10 = (undefined8 *)devm_kmalloc(lVar13,0x18,0xdc0);
                    plVar11 = (long *)(lVar20 + (long)(int)(uVar5 - 0x1f0) * 8 + 0x38);
                    *plVar11 = (long)puVar10;
                    if (puVar10 != (undefined8 *)0x0) {
                      *puVar10 = local_138;
                      uVar5 = 2;
                      lVar20 = *plVar11;
                      goto LAB_00100b00;
                    }
                  }
                }
                local_12c = cpuss_dump_init_initialized;
              }
              lVar20 = (local_100 >> 0x20) + 0x40;
              puVar17 = (undefined4 *)((long)puVar17 + lVar20);
              lVar20 = lVar20 + local_128;
            }
          }
          puVar8 = (undefined8 *)of_get_next_available_child(uVar15,puVar8);
        } while (puVar8 != (undefined8 *)0x0);
      }
      local_c8 = total_size;
      local_d0 = local_140;
      local_d8 = puVar9;
      strscpy(&local_f0,"MEMDUMP",8);
      iVar3 = msm_minidump_add_region(&local_f0);
      if (iVar3 < 0) {
        _dev_err(lVar13,"Mini dump entry failed id = %d\n",local_100 & 0xffffffff);
      }
      uVar5 = local_12c;
      if ((local_12c & 1) != 0) {
        iVar3 = device_create_file(lVar13,&dev_attr_core_reg_num);
        if (iVar3 == 0) {
          iVar4 = device_create_file(lVar13,&dev_attr_register_config);
          if (iVar4 == 0) {
            iVar4 = device_create_file(lVar13,&dev_attr_register_reset);
            if (iVar4 == 0) {
              iVar4 = device_create_file(lVar13,&dev_attr_format_version);
              if (iVar4 == 0) goto LAB_00100f00;
              bVar19 = false;
              bVar18 = false;
              bVar16 = true;
              lVar20 = 3;
            }
            else {
              bVar19 = false;
              bVar16 = false;
              bVar18 = true;
              lVar20 = 2;
            }
          }
          else {
            bVar18 = false;
            bVar16 = false;
            bVar19 = true;
            lVar20 = 1;
          }
        }
        else {
          bVar19 = false;
          bVar18 = false;
          bVar16 = false;
          lVar20 = 0;
        }
        _dev_err(lVar13,"Couldn\'t create sysfs attribute: %s\n",
                 *(undefined8 *)(&register_dump_attrs)[lVar20]);
        if ((((iVar3 == 0) && (device_remove_file(lVar13,&dev_attr_core_reg_num), !bVar19)) &&
            (device_remove_file(lVar13,&dev_attr_register_config), !bVar18)) &&
           (device_remove_file(lVar13,&dev_attr_register_reset), !bVar16)) {
          device_remove_file(lVar13,&dev_attr_format_version);
        }
        _dev_err(lVar13,"Fail to create files for cpuss register dump\n");
      }
LAB_00100f00:
      if ((uVar5 >> 1 & 1) != 0) {
        iVar3 = device_create_file(lVar13,&dev_attr_spr_config);
        if (iVar3 == 0) {
          iVar4 = device_create_file(lVar13,&dev_attr_sprs_register_reset);
          if (iVar4 == 0) {
            iVar4 = device_create_file(lVar13,&dev_attr_sprs_format_version);
            if (iVar4 == 0) goto joined_r0x00100f44;
            bVar18 = false;
            bVar16 = true;
            lVar20 = 2;
          }
          else {
            bVar16 = false;
            bVar18 = true;
            lVar20 = 1;
          }
        }
        else {
          bVar18 = false;
          bVar16 = false;
          lVar20 = 0;
        }
        _dev_err(lVar13,"Couldn\'t create sysfs attribute: %s\n",
                 *(undefined8 *)(&spr_dump_attrs)[lVar20]);
        if (((iVar3 == 0) && (device_remove_file(lVar13,&dev_attr_spr_config), !bVar18)) &&
           (device_remove_file(lVar13,&dev_attr_sprs_register_reset), !bVar16)) {
          device_remove_file(lVar13,&dev_attr_sprs_format_version);
        }
        _dev_err(lVar13,"Fail to create files for spr dump\n");
      }
joined_r0x00100f44:
      if (((uVar5 >> 1 & 1) != 0) && (lVar13 = *(long *)(param_1 + 0xa8), lVar13 != 0)) {
        mutex_lock(lVar13);
        if (*(long *)(lVar13 + 0x38) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x38) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x38) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x38),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x38) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x38);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x38) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x40) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x40) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x40) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x40),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x40) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x40);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x40) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x48) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x48) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x48) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x48),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x48) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x48);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x48) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x50) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x50) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x50) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x50),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x50) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x50);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x50) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x58) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x58) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x58) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x58),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x58) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x58);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x58) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x60) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x60) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x60) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x60),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x60) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x60);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x60) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x68) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x68) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x68) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x68),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x68) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x68);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x68) + 0x10) = 0;
        }
        if (*(long *)(lVar13 + 0x70) != 0) {
          *(undefined4 *)(*(long *)(lVar13 + 0x70) + 0xc) = 0;
          *(undefined4 *)(*(long *)(lVar13 + 0x70) + 0x10) = 0x18;
          memset((void *)**(undefined8 **)(lVar13 + 0x70),0xde,
                 (ulong)*(uint *)(*(undefined8 **)(lVar13 + 0x70) + 1));
          puVar9 = (undefined4 *)**(undefined8 **)(lVar13 + 0x70);
          *puVar9 = 0xc0ffee;
          *(undefined8 *)(puVar9 + 1) = 0x500000001;
          puVar9[3] = 0x18;
          *(undefined8 *)(**(long **)(lVar13 + 0x70) + 0x10) = 0;
        }
        mutex_unlock(lVar13);
      }
      goto LAB_00100914;
    }
  }
  uVar14 = 0xfffffff4;
LAB_00100914:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14 & 0xffffffff;
}



//------------------------------------------------------------
// init_memdump_imem_area @ 001012c8 size=220
// signature: undefined init_memdump_imem_area(void)
// callers: [mem_dump_probe, memory_dump_syscore_resume]
//------------------------------------------------------------

void init_memdump_imem_area(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = param_1;
  lVar1 = of_find_compatible_node(0,0,"qcom,msm-imem-mem_dump_table");
  if (lVar1 == 0) {
    _printk(&DAT_00102eb6);
    uVar2 = 0xffffffed;
  }
  else {
    lVar1 = of_iomap(lVar1,0);
    if (lVar1 == 0) {
      _printk(&DAT_00102fc6);
      uVar2 = 0xfffffff4;
    }
    else {
      __memcpy_toio(lVar1,&memdump,8);
      __memcpy_toio(lVar1 + 0x724,&local_30,8);
      DataSynchronizationBarrier(3,3,0);
      _printk(&DAT_00102c1d);
      iounmap(lVar1);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// memory_dump_syscore_resume @ 001013a8 size=56
// signature: undefined memory_dump_syscore_resume(void)
// callers: []
//------------------------------------------------------------

void memory_dump_syscore_resume(void)

{
  int iVar1;
  
  iVar1 = init_memdump_imem_area(total_size);
  if (iVar1 != 0) {
    _printk(&DAT_00102f93);
  }
  return;
}



//------------------------------------------------------------
// core_reg_num_show @ 001013e4 size=104
// signature: undefined core_reg_num_show(void)
// callers: []
//------------------------------------------------------------

long core_reg_num_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    lVar2 = -0xe;
  }
  else {
    mutex_lock(lVar2);
    iVar1 = scnprintf(param_3,0x1000,&DAT_00102b19,*(undefined4 *)(*(long *)(lVar2 + 0x30) + 0xc));
    mutex_unlock(lVar2);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// core_reg_num_store @ 00101450 size=268
// signature: undefined core_reg_num_store(void)
// callers: []
//------------------------------------------------------------

long core_reg_num_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  iVar2 = kstrtouint(param_3,0x10,&local_4c);
  if (iVar2 == 0) {
    mutex_lock(lVar4);
    iVar2 = local_4c;
    lVar3 = *(long *)(lVar4 + 0x30);
    if ((*(int *)(lVar3 + 0x10) == 0) && (*(int *)(lVar3 + 0x18) == 0)) {
      iVar1 = *(int *)(lVar3 + 0xc);
      mutex_unlock(lVar4);
      if ((iVar2 != iVar1) && (iVar2 = update_reg_dump_table(param_1,local_4c), iVar2 != 0)) {
        _dev_err(param_1,"Couldn\'t set core_reg_num, no enough memory\n");
        param_4 = (long)iVar2;
      }
    }
    else {
      _dev_err(param_1,"Couldn\'t set core_reg_num, register available in list\n");
      mutex_unlock(lVar4);
      param_4 = -1;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// update_reg_dump_table @ 0010155c size=240
// signature: undefined update_reg_dump_table(void)
// callers: [core_reg_num_store, register_reset_store]
//------------------------------------------------------------

undefined8 update_reg_dump_table(long param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = *(long *)(param_1 + 0x98);
  iVar1 = param_2 * 2;
  mutex_lock(lVar4);
  uVar5 = 0xfffffff4;
  if (iVar1 + 6U >> 0x1e == 0) {
    uVar2 = (iVar1 + 6U) * 4;
    if (uVar2 < *(uint *)(*(long *)(lVar4 + 0x30) + 8)) {
      *(int *)(*(long *)(lVar4 + 0x30) + 0xc) = param_2;
      *(undefined4 *)(*(long *)(lVar4 + 0x30) + 0x10) = 0;
      *(undefined4 *)(*(long *)(lVar4 + 0x30) + 0x14) = 4;
      *(undefined4 *)(*(long *)(lVar4 + 0x30) + 0x18) = 0;
      *(uint *)(*(long *)(lVar4 + 0x30) + 0x1c) = uVar2;
      memset((void *)**(undefined8 **)(lVar4 + 0x30),0xde,
             (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x30) + 1));
      puVar3 = (undefined8 *)**(undefined8 **)(lVar4 + 0x30);
      *puVar3 = 0x200c0ffee;
      *(int *)(puVar3 + 1) = iVar1 + 5;
      *(uint *)((long)puVar3 + 0xc) = uVar2;
      memset((void *)(**(long **)(lVar4 + 0x30) + 0x10),0,(ulong)(iVar1 + 2) << 2);
      uVar5 = 0;
    }
  }
  mutex_unlock(lVar4);
  return uVar5;
}



//------------------------------------------------------------
// register_config_show @ 00101650 size=568
// signature: undefined register_config_show(void)
// callers: []
//------------------------------------------------------------

void register_config_show(long param_1,undefined8 param_2,undefined1 *param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x98);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  *param_3 = 0;
  if (lVar10 == 0) {
    lVar10 = -0xe;
  }
  else {
    mutex_lock(lVar10);
    lVar12 = **(long **)(lVar10 + 0x30);
    uVar5 = scnprintf(&local_a8,0x40,"per-core registers:\n");
    strlcat(param_3,&local_a8,0x1000);
    iVar3 = *(int *)(lVar12 + 8);
    iVar2 = iVar3 + (*(uint *)(*(long *)(lVar10 + 0x30) + 0x18) >> 2) + 1;
    if (4 < iVar2) {
      iVar11 = 4;
      do {
        if (iVar11 == iVar3) {
          iVar6 = scnprintf(&local_a8,0x40,"system registers:\n");
          if (iVar6 + uVar5 < 0x1001) {
            strlcat(param_3,&local_a8,0x1000);
            uVar5 = iVar6 + uVar5;
            goto LAB_00101758;
          }
LAB_00101830:
          _dev_err(param_1,"Couldn\'t write complete config\n");
          break;
        }
LAB_00101758:
        puVar1 = (uint *)(lVar12 + (long)iVar11 * 4);
        uVar4 = *puVar1;
        if (uVar4 == 0) {
          iVar11 = iVar11 + 1;
        }
        else {
          switch(uVar4 & 3) {
          case 0:
            uVar8 = puVar1[1];
            pcVar7 = "0x%x, 0x%x, r\n";
            break;
          case 1:
            iVar6 = scnprintf(&local_a8,0x40,"0x%x, 0x%x, r\n",uVar4 & 0xfffffffc,4);
            iVar9 = 1;
            goto LAB_00101800;
          case 2:
            uVar8 = puVar1[1];
            pcVar7 = "0x%x, 0x%x, w\n";
            break;
          case 3:
            uVar8 = puVar1[1] & 0xffffff;
            pcVar7 = "0x%x, 0x%x, d\n";
            if (puVar1[1] >> 0x18 != 1) {
              pcVar7 = "0x%x, 0x%x, R\n";
            }
          }
          iVar6 = scnprintf(&local_a8,0x40,pcVar7,uVar4 & 0xfffffffc,uVar8);
          iVar9 = 2;
LAB_00101800:
          if (0x1000 < iVar6 + uVar5) goto LAB_00101830;
          iVar11 = iVar11 + iVar9;
          strlcat(param_3,&local_a8,0x1000);
          uVar5 = iVar6 + uVar5;
        }
      } while (iVar11 < iVar2);
    }
    mutex_unlock(lVar10);
    lVar10 = (long)(int)uVar5;
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar10);
  }
  return;
}



//------------------------------------------------------------
// register_config_store @ 0010188c size=800
// signature: undefined register_config_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void register_config_store(long param_1,undefined8 param_2,char *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  long *plVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  byte local_58 [4];
  uint local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  local_54 = 0;
  local_50 = 0;
  local_58[0] = 0;
  iVar2 = sscanf(param_3,"%x %x %c %u",&local_4c,&local_50,local_58,&local_54);
  if (1 < iVar2) {
    if (iVar2 == 2) {
      local_58[0] = 0x72;
    }
    if (local_54 < 2) {
      if ((local_4c & 3) == 0) {
        if ((local_58[0] | 0x20) != 0x72) {
          uVar11 = 4;
LAB_00101960:
          mutex_lock(lVar9);
          plVar6 = *(long **)(lVar9 + 0x30);
          lVar10 = *plVar6;
          if (local_54 == 0) {
            uVar1 = 8;
            if (uVar11 != 4 || local_58[0] != 0x72) {
              uVar1 = uVar11 + 8;
            }
            if (((uVar1 < uVar11) ||
                (uVar1 = uVar1 + *(uint *)((long)plVar6 + 0x1c),
                uVar1 < *(uint *)((long)plVar6 + 0x1c))) || (*(uint *)(plVar6 + 1) < uVar1)) {
              pcVar5 = "Couldn\'t add system reg config, no enough memory\n";
              goto LAB_00101b24;
            }
            iVar2 = *(int *)(lVar10 + 8) + (*(uint *)(plVar6 + 3) >> 2);
            iVar4 = config_cpuss_register(param_1,lVar10,iVar2,local_58[0],local_4c,local_50);
            if (iVar4 == 0) {
              iVar4 = 4;
              if (local_58[0] != 0x72 || local_50 != 4) {
                iVar4 = 8;
              }
              iVar8 = 1;
              if (local_58[0] != 0x72 || local_50 != 4) {
                iVar8 = 2;
              }
              *(int *)(*(long *)(lVar9 + 0x30) + 0x18) =
                   *(int *)(*(long *)(lVar9 + 0x30) + 0x18) + iVar4;
              uVar11 = iVar2 + iVar8;
              *(uint *)(*(long *)(lVar9 + 0x30) + 0x1c) = uVar1;
              *(undefined4 *)(lVar10 + (ulong)uVar11 * 4) = 0;
              *(uint *)(lVar10 + 0xc) = uVar11 * 4 + 4;
LAB_00101afc:
              iVar4 = param_4;
            }
          }
          else if ((int)plVar6[2] == *(int *)((long)plVar6 + 0xc)) {
            _dev_err(param_1,"Couldn\'t add per-core config, out of range\n");
            iVar4 = -0x16;
          }
          else {
            uVar3 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
            uVar1 = 0;
            if (uVar3 != 0) {
              uVar1 = (uVar3 * uVar11) / uVar3;
            }
            if (uVar11 <= uVar1) {
              lVar7 = *(long *)(lVar9 + 0x30);
              uVar11 = *(uint *)(lVar7 + 0x1c) + uVar3 * uVar11;
              if ((*(uint *)(lVar7 + 0x1c) <= uVar11) && (uVar11 <= *(uint *)(lVar7 + 8))) {
                iVar4 = config_cpuss_register
                                  (param_1,lVar10,*(undefined4 *)(lVar7 + 0x14),local_58[0],local_4c
                                   ,local_50);
                if (iVar4 == 0) {
                  iVar2 = 1;
                  if (local_50 != 4 || local_58[0] != 0x72) {
                    iVar2 = 2;
                  }
                  *(int *)(*(long *)(lVar9 + 0x30) + 0x14) =
                       *(int *)(*(long *)(lVar9 + 0x30) + 0x14) + iVar2;
                  *(int *)(*(long *)(lVar9 + 0x30) + 0x10) =
                       *(int *)(*(long *)(lVar9 + 0x30) + 0x10) + 1;
                  *(uint *)(*(long *)(lVar9 + 0x30) + 0x1c) = uVar11;
                  goto LAB_00101afc;
                }
                goto LAB_00101b6c;
              }
            }
            pcVar5 = "Couldn\'t add per-core reg config, no enough memory\n";
LAB_00101b24:
            _dev_err(param_1,pcVar5);
            iVar4 = -0xc;
          }
LAB_00101b6c:
          mutex_unlock(lVar9);
          lVar9 = (long)iVar4;
          goto LAB_00101b78;
        }
        if (local_50 == 0) {
          pcVar5 = "Invalid length of 0\n";
        }
        else {
          if ((local_58[0] != 0x72) || ((local_50 & 3) == 0)) {
            uVar11 = local_50 << 2;
            if (local_58[0] != 0x52) {
              uVar11 = local_50;
            }
            goto LAB_00101960;
          }
          pcVar5 = "Invalid length, must be 4 byte aligned\n";
        }
      }
      else {
        pcVar5 = "Invalid address, must be 4 byte aligned\n";
      }
      _dev_err(param_1,pcVar5);
      lVar9 = -0x16;
      goto LAB_00101b78;
    }
  }
  lVar9 = -0x16;
LAB_00101b78:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar9);
  }
  return;
}



//------------------------------------------------------------
// config_cpuss_register @ 00101bac size=228
// signature: undefined config_cpuss_register(void)
// callers: [register_config_store]
//------------------------------------------------------------

undefined8
config_cpuss_register
          (undefined8 param_1,long param_2,uint param_3,undefined1 param_4,uint param_5,uint param_6
          )

{
  undefined4 *puVar1;
  uint *puVar2;
  char *pcVar3;
  
  switch(param_4) {
  case 0x52:
    if (param_6 >> 0x18 == 0) {
      puVar2 = (uint *)(param_2 + (ulong)param_3 * 4);
      *puVar2 = param_5 | 3;
      puVar2[1] = param_6 | 0x2000000;
      return 0;
    }
    pcVar3 = "repeat read time exceeded the limit\n";
    break;
  default:
    pcVar3 = "Don\'t support this command\n";
    break;
  case 100:
    if (param_6 >> 0x18 == 0) {
      puVar1 = (undefined4 *)(param_2 + (ulong)param_3 * 4);
      *puVar1 = 3;
      puVar1[1] = param_6 | 0x1000000;
      return 0;
    }
    pcVar3 = "sleep time exceeded the limit\n";
    break;
  case 0x72:
    if (param_6 < 5) {
      *(uint *)(param_2 + (ulong)param_3 * 4) = param_5 | 1;
      return 0;
    }
    puVar2 = (uint *)(param_2 + (ulong)param_3 * 4);
    *puVar2 = param_5;
    puVar2[1] = param_6;
    return 0;
  case 0x77:
    puVar2 = (uint *)(param_2 + (ulong)param_3 * 4);
    *puVar2 = param_5 | 2;
    puVar2[1] = param_6;
    return 0;
  }
  _dev_err(param_1,pcVar3);
  return 0xffffffea;
}



//------------------------------------------------------------
// register_reset_store @ 00101c94 size=148
// signature: undefined register_reset_store(void)
// callers: []
//------------------------------------------------------------

void register_reset_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,0x10,&local_2c);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_2c == 1)) {
    update_reg_dump_table(param_1,1);
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
// format_version_show @ 00101d2c size=108
// signature: undefined format_version_show(void)
// callers: []
//------------------------------------------------------------

long format_version_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    lVar2 = -0xe;
  }
  else {
    mutex_lock(lVar2);
    iVar1 = scnprintf(param_3,0x1000,&DAT_00102b19,*(undefined4 *)(**(long **)(lVar2 + 0x30) + 4));
    mutex_unlock(lVar2);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// spr_config_show @ 00101d9c size=468
// signature: undefined spr_config_show(void)
// callers: []
//------------------------------------------------------------

void spr_config_show(long param_1,undefined8 param_2,undefined1 *param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  long *plVar7;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  *param_3 = 0;
  if (lVar4 == 0) {
    lVar4 = -0xe;
  }
  else {
    mutex_lock(lVar4);
    uVar1 = scnprintf(&uStack_a8,0x40,"spr data list below:\n");
    strlcat(param_3,&uStack_a8,0x1000);
    uVar5 = 0;
    do {
      if (0x1000 < uVar1) {
        _dev_err(param_1,"Couldn\'t write complete config\n");
        break;
      }
      plVar7 = (long *)(lVar4 + uVar5 * 8 + 0x38);
      if ((long *)*plVar7 == (long *)0x0) {
        _dev_err(param_1,"SPR data pinter for CPU%d is empty\n",uVar5 & 0xffffffff);
      }
      else {
        lVar3 = *(long *)*plVar7;
        iVar2 = scnprintf(&uStack_a8,0x40,"spr data for CPU[%d] below:\n",uVar5 & 0xffffffff);
        strlcat(param_3,&uStack_a8,0x1000);
        uVar1 = iVar2 + uVar1;
        if (*(int *)(*plVar7 + 0xc) != 0) {
          uVar6 = 0;
          do {
            if (0x1000 < uVar1) {
              _dev_err(param_1,"Couldn\'t write complete config\n");
              break;
            }
            iVar2 = scnprintf(&uStack_a8,0x40,&DAT_00102b42,
                              *(undefined4 *)(lVar3 + 0x14 + (long)(int)uVar6 * 4));
            strlcat(param_3,&uStack_a8,0x1000);
            uVar1 = iVar2 + uVar1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < *(uint *)(*plVar7 + 0xc));
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 8);
    mutex_unlock(lVar4);
    lVar4 = (long)(int)uVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// spr_config_store @ 00101f74 size=348
// signature: undefined spr_config_store(void)
// callers: []
//------------------------------------------------------------

long spr_config_store(long param_1,undefined8 param_2,char *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = sscanf(param_3,"%d %d",(int *)((long)&local_40 + 4),(int *)&local_40);
  if (iVar2 != 2) {
    lVar4 = -0x16;
    goto LAB_0010206c;
  }
  if (lVar6 == 0) {
    lVar4 = -0xe;
    goto LAB_0010206c;
  }
  if (7 < (uint)local_40) {
    _dev_err(param_1,"Input the wrong CPU number\n");
    lVar4 = -0x16;
    goto LAB_0010206c;
  }
  mutex_lock(lVar6);
  plVar3 = *(long **)(lVar6 + (local_40 & 0xffffffff) * 8 + 0x38);
  if (plVar3 == (long *)0x0) {
LAB_00102050:
    lVar4 = (long)param_4;
  }
  else {
    if ((int)plVar3[2] + 0xcU < *(uint *)(plVar3 + 1)) {
      uVar1 = *(uint *)((long)plVar3 + 0xc);
      lVar4 = *plVar3;
      *(uint *)(lVar4 + 0xc) = uVar1 * 4 + 0x1c;
      lVar4 = lVar4 + (ulong)uVar1 * 4;
      *(undefined4 *)(lVar4 + 0x14) = local_40._4_4_;
      *(undefined4 *)(lVar4 + 0x18) = 0;
      lVar4 = lVar6 + (local_40 & 0xffffffff) * 8;
      lVar5 = *(long *)(lVar4 + 0x38);
      *(int *)(lVar5 + 0xc) = *(int *)(lVar5 + 0xc) + 1;
      lVar4 = *(long *)(lVar4 + 0x38);
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 0xc;
      goto LAB_00102050;
    }
    _dev_err(param_1,"Couldn\'t add SPR config, no enough memory\n");
    lVar4 = -0xc;
  }
  mutex_unlock(lVar6);
LAB_0010206c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// sprs_register_reset_store @ 001020d4 size=848
// signature: undefined sprs_register_reset_store(void)
// callers: []
//------------------------------------------------------------

void sprs_register_reset_store
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  long lVar4;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0x10,&local_3c);
  uVar2 = 0xffffffffffffffea;
  if ((iVar1 == 0) && (local_3c == 1)) {
    lVar4 = *(long *)(param_1 + 0x98);
    if (lVar4 != 0) {
      mutex_lock(lVar4);
      if (*(long *)(lVar4 + 0x38) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x38) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x38) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x38),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x38) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x38);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x38) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x40) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x40) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x40) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x40),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x40) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x40);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x40) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x48) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x48) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x48) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x48),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x48) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x48);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x48) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x50) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x50) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x50) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x50),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x50) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x50);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x50) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x58) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x58) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x58) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x58),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x58) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x58);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x58) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x60) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x60) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x60) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x60),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x60) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x60);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x60) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x68) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x68) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x68) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x68),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x68) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x68);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x68) + 0x10) = 0;
      }
      if (*(long *)(lVar4 + 0x70) != 0) {
        *(undefined4 *)(*(long *)(lVar4 + 0x70) + 0xc) = 0;
        *(undefined4 *)(*(long *)(lVar4 + 0x70) + 0x10) = 0x18;
        memset((void *)**(undefined8 **)(lVar4 + 0x70),0xde,
               (ulong)*(uint *)(*(undefined8 **)(lVar4 + 0x70) + 1));
        puVar3 = (undefined4 *)**(undefined8 **)(lVar4 + 0x70);
        *puVar3 = 0xc0ffee;
        *(undefined8 *)(puVar3 + 1) = 0x500000001;
        puVar3[3] = 0x18;
        *(undefined8 *)(**(long **)(lVar4 + 0x70) + 0x10) = 0;
      }
      mutex_unlock(lVar4);
    }
    uVar2 = param_4;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// sprs_format_version_show @ 00102428 size=668
// signature: undefined sprs_format_version_show(void)
// callers: []
//------------------------------------------------------------

void sprs_format_version_show(long param_1,undefined8 param_2,undefined1 *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  *param_3 = 0;
  if (lVar5 == 0) {
    lVar5 = -0xe;
  }
  else {
    mutex_lock(lVar5);
    if (*(long **)(lVar5 + 0x38) == (long *)0x0) {
      iVar2 = 0;
      plVar4 = *(long **)(lVar5 + 0x40);
    }
    else {
      iVar2 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",0,
                        *(undefined4 *)(**(long **)(lVar5 + 0x38) + 4));
      strlcat(param_3,&local_78,0x1000);
      plVar4 = *(long **)(lVar5 + 0x40);
    }
    if (plVar4 != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",1,
                        *(undefined4 *)(*plVar4 + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    if (*(long **)(lVar5 + 0x48) != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",2,
                        *(undefined4 *)(**(long **)(lVar5 + 0x48) + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    if (*(long **)(lVar5 + 0x50) != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",3,
                        *(undefined4 *)(**(long **)(lVar5 + 0x50) + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    if (*(long **)(lVar5 + 0x58) != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",4,
                        *(undefined4 *)(**(long **)(lVar5 + 0x58) + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    if (*(long **)(lVar5 + 0x60) != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",5,
                        *(undefined4 *)(**(long **)(lVar5 + 0x60) + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    if (*(long **)(lVar5 + 0x68) != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",6,
                        *(undefined4 *)(**(long **)(lVar5 + 0x68) + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    if (*(long **)(lVar5 + 0x70) != (long *)0x0) {
      iVar3 = scnprintf(&local_78,0x40,"SPR data format version for cpu%d is %d\n",7,
                        *(undefined4 *)(**(long **)(lVar5 + 0x70) + 4));
      strlcat(param_3,&local_78,0x1000);
      iVar2 = iVar3 + iVar2;
    }
    mutex_unlock(lVar5);
    lVar5 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0010271c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mem_dump_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010274c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mem_dump_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00105000 size=1
// signature: undefined _printk(void)
// callers: [init_memdump_imem_area, mem_dump_probe, msm_dump_data_register_nominidump, memory_dump_syscore_resume, msm_dump_data_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00105010 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [mem_dump_probe, msm_dump_data_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00105018 size=1
// signature: undefined strscpy(void)
// callers: [mem_dump_probe, msm_dump_data_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00105020 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [msm_dump_data_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00105028 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [mem_dump_probe, msm_dump_data_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [spr_config_store, init_memdump_imem_area, mem_dump_probe, sprs_format_version_show, core_reg_num_store, register_reset_store, msm_dump_data_register, register_config_store, register_config_show, sprs_register_reset_store, spr_config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00105038 size=1
// signature: undefined fortify_panic(void)
// callers: [mem_dump_probe, msm_dump_data_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105040 size=1
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
// platform_driver_unregister @ 00105048 size=1
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
// dma_set_mask @ 00105050 size=1
// signature: undefined dma_set_mask(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00105058 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00105060 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00105068 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00105070 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105078 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105080 size=1
// signature: undefined _dev_err(void)
// callers: [spr_config_store, mem_dump_probe, core_reg_num_store, register_config_store, register_config_show, config_cpuss_register, spr_config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_alloc_attrs @ 00105088 size=1
// signature: undefined dmam_alloc_attrs(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_sgtable_attrs @ 00105090 size=1
// signature: undefined dma_get_sgtable_attrs(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_sgtable_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 00105098 size=1
// signature: undefined sg_free_table(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001050a0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [mem_dump_probe, update_reg_dump_table, sprs_register_reset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_register @ 001050a8 size=1
// signature: undefined qtee_shmbridge_register(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_deregister @ 001050b0 size=1
// signature: undefined qtee_shmbridge_deregister(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_syscore_ops @ 001050b8 size=1
// signature: undefined register_syscore_ops(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_dump_table_region @ 001050c0 size=1
// signature: undefined qcom_scm_assign_dump_table_region(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_dump_table_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001050c8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001050d0 size=1
// signature: undefined __mutex_init(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 001050d8 size=1
// signature: undefined device_create_file(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 001050e0 size=1
// signature: undefined device_remove_file(void)
// callers: [mem_dump_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001050e8 size=1
// signature: undefined mutex_lock(void)
// callers: [core_reg_num_show, spr_config_store, mem_dump_probe, sprs_format_version_show, core_reg_num_store, update_reg_dump_table, register_config_store, format_version_show, register_config_show, sprs_register_reset_store, spr_config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001050f0 size=1
// signature: undefined mutex_unlock(void)
// callers: [core_reg_num_show, spr_config_store, mem_dump_probe, sprs_format_version_show, core_reg_num_store, update_reg_dump_table, register_config_store, format_version_show, register_config_show, sprs_register_reset_store, spr_config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 001050f8 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [init_memdump_imem_area]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 00105100 size=1
// signature: undefined of_iomap(void)
// callers: [init_memdump_imem_area]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 00105108 size=1
// signature: undefined __memcpy_toio(void)
// callers: [init_memdump_imem_area]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00105110 size=1
// signature: undefined iounmap(void)
// callers: [init_memdump_imem_area]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00105118 size=1
// signature: undefined scnprintf(void)
// callers: [core_reg_num_show, sprs_format_version_show, format_version_show, register_config_show, spr_config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00105120 size=1
// signature: undefined kstrtouint(void)
// callers: [core_reg_num_store, register_reset_store, sprs_register_reset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 00105128 size=1
// signature: undefined strlcat(void)
// callers: [sprs_format_version_show, register_config_show, spr_config_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00105130 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [spr_config_store, register_config_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00105148 size=1
// signature: undefined __bitmap_weight(void)
// callers: [register_config_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



