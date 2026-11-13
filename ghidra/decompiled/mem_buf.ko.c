// Decompiled by Ghidra 12.2
// Program: mem_buf.ko
// Image base: 00100000

//------------------------------------------------------------
// mem_buf_acl_to_vmid_perms_list @ 00100b0c size=664
// signature: undefined mem_buf_acl_to_vmid_perms_list(void)
// callers: [mem_buf_lend_user, mem_buf_retrieve_user, mem_buf_prep_alloc_data]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mem_buf_acl_to_vmid_perms_list(uint param_1,long param_2,long *param_3,long *param_4)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  size_t __n;
  uint uVar10;
  ulong uVar11;
  undefined8 uVar12;
  long lVar13;
  undefined8 local_70;
  long local_68;
  
  lVar8 = sp_el0;
  uVar12 = 0xffffffea;
  local_68 = *(long *)(lVar8 + 0x638);
  local_70 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar3 = (ulong)param_1 * 4;
    lVar8 = __kmalloc(uVar3,0xcc0);
    if (lVar8 == 0) {
      uVar12 = 0xfffffff4;
    }
    else {
      lVar9 = __kmalloc(uVar3,0xcc0);
      if (lVar9 == 0) {
        kfree(lVar8);
        uVar12 = 0xfffffff4;
      }
      else {
        uVar10 = 0;
        puVar4 = (undefined8 *)sp_el0;
        do {
          uVar1 = param_2 + (long)(int)uVar10 * 8;
          if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
             (uVar11 = uVar1, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
            uVar11 = uVar1 & (long)(uVar1 * 0x100) >> 8;
          }
          if (0x7ffffffff8 < uVar11) {
            __n = 8;
LAB_00100d9c:
            memset((void *)((long)&local_68 - __n),0,__n);
            uVar12 = 0xfffffff2;
LAB_00100d1c:
            kfree(lVar9);
            kfree(lVar8);
            goto LAB_00100d3c;
          }
          lVar13 = (long)(int)uVar10;
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar11 = daif;
            if ((uVar11 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar4[1];
            InstructionSynchronizationBarrier();
            daif = uVar11;
          }
          __n = __arch_copy_from_user(&local_70,uVar1 & 0xff7fffffffffffff,8);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar1 = daif;
            if ((uVar1 & 0x80) == 0) {
              uVar11 = daif;
              daif = uVar11 | 0xc0;
            }
            uVar11 = ttbr1_el1;
            ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar11 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar1;
          }
          if (__n != 0) goto LAB_00100d9c;
          iVar7 = mem_buf_fd_to_vmid(local_70 & 0xffffffff);
          if (uVar3 <= (ulong)(lVar13 * 4)) {
LAB_00100d94:
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(1,0x100d98);
            (*pcVar6)();
          }
          *(int *)(lVar8 + lVar13 * 4) = iVar7;
          if (7 < local_70._4_4_) {
            iVar7 = ___ratelimit(&is_valid_mem_buf_perms__rs,"is_valid_mem_buf_perms");
            if (iVar7 != 0) {
              _printk(&DAT_00103daf,"is_valid_mem_buf_perms");
            }
            if (uVar3 <= (ulong)(lVar13 * 4)) goto LAB_00100d94;
            uVar12 = 0xffffffea;
            *(undefined4 *)(lVar9 + lVar13 * 4) = 0xffffffea;
            goto LAB_00100d1c;
          }
          if (uVar3 <= (ulong)(lVar13 * 4)) goto LAB_00100d94;
          uVar2 = (local_70._4_4_ & 0xaaaaaaaa) >> 1 | (local_70._4_4_ & 0x55555555) << 1;
          *(uint *)(lVar9 + lVar13 * 4) =
               (((uVar2 & 0xcccccccc) >> 2 | (uVar2 & 0x33333333) << 2) & 0xf) >> 1;
          if (iVar7 < 0) {
            uVar12 = 0xffffffea;
            goto LAB_00100d1c;
          }
          uVar10 = uVar10 + 1;
        } while (param_1 != uVar10);
        uVar12 = 0;
        *param_3 = lVar8;
        *param_4 = lVar9;
      }
    }
  }
LAB_00100d3c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// mem_buf_msgq_probe @ 00100dc0 size=212
// signature: undefined mem_buf_msgq_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mem_buf_msgq_probe(long param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (_mem_buf_dev == 0) {
    uVar3 = 0xfffffdfb;
  }
  else {
    uVar2 = mem_buf_msgq_alloc(param_1 + 0x10);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      cdev_init(mem_buf_char_dev,mem_buf_dev_fops);
      uVar1 = cdev_add(mem_buf_char_dev,mem_buf_dev_no,1);
      if ((int)uVar1 < 0) {
        uVar3 = (ulong)uVar1;
      }
      else {
        uVar3 = device_create(mem_buf_class,0,mem_buf_dev_no,0,"membuf");
        if (uVar3 < 0xfffffffffffff001) {
          uVar3 = 0;
          goto LAB_00100e7c;
        }
        cdev_del(mem_buf_char_dev);
      }
      mem_buf_msgq_free(param_1 + 0x10);
    }
  }
LAB_00100e7c:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_msgq_remove @ 00100e98 size=80
// signature: undefined mem_buf_msgq_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_msgq_remove(long param_1)

{
  device_destroy(mem_buf_class,mem_buf_dev_no);
  cdev_del(mem_buf_char_dev);
  mem_buf_msgq_free(param_1 + 0x10);
  return 0;
}



//------------------------------------------------------------
// mem_buf_dev_ioctl @ 00100eec size=1144
// signature: undefined mem_buf_dev_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_dev_ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong local_98;
  undefined8 local_90;
  long local_88;
  long local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  uVar1 = param_2 >> 0x10 & 0x3fff;
  uVar10 = (ulong)uVar1;
  local_48 = *(long *)(lVar7 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_98 = 0;
  if (0x48 < uVar1) {
    lVar7 = -0x16;
    goto LAB_001012f8;
  }
  __check_object_size(&local_98,uVar10,0);
  puVar3 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
     (uVar9 = param_3, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
    uVar9 = param_3 & (long)(param_3 << 8) >> 8;
  }
  uVar8 = uVar10;
  if (uVar9 <= 0x8000000000 - uVar10) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar8 = daif;
        daif = uVar8 | 0xc0;
      }
      uVar8 = ttbr1_el1;
      ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar3[1];
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    uVar8 = __arch_copy_from_user(&local_98,param_3 & 0xff7fffffffffffff,uVar10);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      uVar4 = ttbr1_el1;
      ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
  }
  if (uVar8 != 0) {
    lVar7 = -0xe;
    goto LAB_001012f8;
  }
  if ((param_2 >> 0x1e & 1) == 0) {
    local_60 = 0;
    uStack_58 = 0;
    local_70 = 0;
    uStack_68 = 0;
    local_80 = 0;
    uStack_78 = 0;
    local_90 = 0;
    local_88 = 0;
    local_98 = 0;
  }
  lVar7 = -0x19;
  if ((int)param_2 < -0x3fcfb2fd) {
    if (param_2 == 0xc0084d02) {
      uVar9 = dma_buf_get(local_98 & 0xffffffff);
      if (0xfffffffffffff000 < uVar9) goto LAB_001011c0;
      uVar8 = to_mem_buf_vmperm(uVar9);
      if (uVar8 < 0xfffffffffffff001) {
        uVar6 = mem_buf_dma_buf_exclusive_owner(uVar9);
        iVar5 = 0;
        local_98 = CONCAT44(uVar6,(undefined4)local_98) & 0x1ffffffff;
      }
      else {
LAB_001011f8:
        iVar5 = -0x16;
      }
LAB_0010120c:
      dma_buf_put(uVar9);
joined_r0x00101214:
      if (iVar5 != 0) {
        lVar7 = (long)iVar5;
        goto LAB_001012f8;
      }
    }
    else {
      if (param_2 == 0xc0104d05) {
        local_4c = 0;
        uVar9 = dma_buf_get(local_90 & 0xffffffff);
        if (uVar9 < 0xfffffffffffff001) {
          iVar5 = mem_buf_dma_buf_get_memparcel_hdl(uVar9,&local_4c);
          if (iVar5 != 0) goto LAB_001011f8;
          local_98 = (ulong)local_4c;
          iVar5 = 0;
          goto LAB_0010120c;
        }
LAB_001011c0:
        iVar5 = (int)uVar9;
        goto joined_r0x00101214;
      }
      if (param_2 != 0xc0204d03) goto LAB_001012f8;
      lVar7 = -0x16;
      if (((local_90._4_4_ != 0) || (local_88 != 0)) || (local_80 != 0)) goto LAB_001012f8;
      uVar8 = dma_buf_get(local_90 & 0xffffffff);
      uVar9 = uVar8;
      if (uVar8 < 0xfffffffffffff001) {
        uVar9 = mem_buf_reclaim(uVar8);
        uVar9 = uVar9 & 0xffffffff;
        dma_buf_put(uVar8);
      }
      if ((int)uVar9 != 0) {
        lVar7 = (long)(int)uVar9;
        goto LAB_001012f8;
      }
    }
LAB_00101220:
    __check_object_size(&local_98,uVar10,1);
    if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar9 <= 0x8000000000 - uVar10) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar8 = daif;
          daif = uVar8 | 0xc0;
        }
        uVar8 = ttbr1_el1;
        ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar3[1];
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      uVar10 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_98,uVar10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar8 = daif;
          daif = uVar8 | 0xc0;
        }
        uVar8 = ttbr1_el1;
        ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar8 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
    }
    lVar7 = 0;
    if (uVar10 != 0) {
      lVar7 = -0xe;
    }
  }
  else {
    if ((int)param_2 < -0x3fc7b2fc) {
      if (param_2 == 0xc0304d03) {
        iVar5 = mem_buf_lend_user(&local_98,1);
      }
      else {
        if (param_2 != 0xc0304d06) goto LAB_001012f8;
        iVar5 = mem_buf_lend_user(&local_98,0);
      }
joined_r0x00101190:
      if (iVar5 == 0) goto LAB_00101220;
    }
    else {
      if (param_2 == 0xc0384d04) {
        iVar5 = mem_buf_retrieve_user(&local_98);
        goto joined_r0x00101190;
      }
      if (param_2 != 0xc0484d00) goto LAB_001012f8;
      if ((mem_buf_capability >> 1 & 1) == 0) {
        lVar7 = -0x5f;
        goto LAB_001012f8;
      }
      iVar5 = mem_buf_alloc_fd(&local_98);
      if (-1 < iVar5) {
        uStack_78 = CONCAT44(iVar5,(undefined4)uStack_78);
        goto LAB_00101220;
      }
    }
    lVar7 = (long)iVar5;
  }
LAB_001012f8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// mem_buf_lend_user @ 00101394 size=320
// signature: undefined mem_buf_lend_user(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

ulong mem_buf_lend_user(undefined4 *param_1,ulong param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if (param_1[1] == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    uVar6 = 0xffffffea;
    if ((((*(long *)(param_1 + 2) != 0) && ((uint)param_1[1] < 0x11)) &&
        (*(long *)(param_1 + 6) == 0)) &&
       ((*(long *)(param_1 + 8) == 0 && (*(long *)(param_1 + 10) == 0)))) {
      uVar4 = dma_buf_get(*param_1);
      if (uVar4 < 0xfffffffffffff001) {
        uVar5 = mem_buf_acl_to_vmid_perms_list
                          (param_1[1],*(undefined8 *)(param_1 + 2),&uStack_50,&local_58);
        uVar3 = uStack_50;
        uVar2 = local_58;
        uVar6 = uVar5 & 0xffffffff;
        if ((int)uVar5 == 0) {
          local_80 = CONCAT44(local_80._4_4_,param_1[1]);
          local_78 = uStack_50;
          uStack_70 = local_58;
          if ((param_2 & 1) == 0) {
            uVar5 = mem_buf_share(uVar4,&local_80);
          }
          else {
            uVar5 = mem_buf_lend();
          }
          uVar6 = uVar5 & 0xffffffff;
          if ((int)uVar5 == 0) {
            uVar6 = 0;
            *(ulong *)(param_1 + 4) = local_68 & 0xffffffff;
          }
          kfree(uVar2);
          kfree(uVar3);
        }
        dma_buf_put(uVar4);
      }
      else {
        uVar6 = uVar4 & 0xffffffff;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// mem_buf_alloc @ 00101550 size=736
// signature: undefined mem_buf_alloc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * mem_buf_alloc(long *param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  int iVar12;
  undefined4 local_5c;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_5c = 7;
  if ((mem_buf_capability >> 1 & 1) == 0) {
    plVar10 = (long *)0xffffffffffffffa1;
    goto LAB_00101634;
  }
  if ((((param_1 == (long *)0x0) || (*param_1 == 0)) || ((int)param_1[1] != 1)) ||
     (((param_1[2] == 0 || (param_1[3] == 0)) ||
      ((1 < (int)param_1[6] - 1U || (1 < (int)param_1[8] - 1U)))))) {
    plVar10 = (long *)0xffffffffffffffea;
    goto LAB_00101634;
  }
  plVar10 = (long *)kmalloc_trace(_mutex_lock,0xdc0,0x60);
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)0xfffffffffffffff4;
    goto LAB_00101634;
  }
  lVar11 = *param_1;
  lVar7 = param_1[2];
  lVar4 = param_1[1];
  *plVar10 = lVar11;
  uVar8 = mem_buf_vmid_perm_list_to_gh_acl(lVar7,&local_5c,(int)lVar4);
  plVar10[1] = uVar8;
  if (uVar8 < 0xfffffffffffff001) {
    if (param_1[5] == 0) {
LAB_00101694:
      iVar12 = (int)param_1[6];
      iVar2 = (int)param_1[8];
      *(int *)((long)plVar10 + 0x1c) = (int)param_1[4];
      *(int *)(plVar10 + 4) = iVar12;
      *(int *)(plVar10 + 6) = iVar2;
      if (iVar12 == 1) {
        uVar9 = kstrdup(param_1[7],0xcc0);
        plVar10[5] = uVar9;
        if (uVar9 < 0xfffffffffffff001) {
          iVar3 = (int)param_1[8];
          goto LAB_001016ec;
        }
      }
      else if (iVar12 == 2) {
        plVar10[5] = 0;
        iVar3 = iVar2;
LAB_001016ec:
        if (iVar3 == 1) {
          uVar9 = kstrdup(param_1[9],0xcc0);
          plVar10[7] = uVar9;
          if (uVar9 < 0xfffffffffffff001) goto LAB_00101738;
          uVar9 = uVar9 & 0xffffffff;
        }
        else if (iVar3 == 2) {
          plVar10[7] = 0;
LAB_00101738:
          trace_mem_buf_alloc_info(lVar11,iVar12,iVar2,uVar8);
          uVar8 = mem_buf_request_mem(plVar10);
          uVar9 = uVar8 & 0xffffffff;
          if ((int)uVar8 == 0) {
            uVar6 = mem_buf_map_mem_s2(*(undefined4 *)((long)plVar10 + 0x1c),plVar10 + 3,plVar10[1],
                                       plVar10 + 2,3);
            if (uVar6 == 0) {
              mutex_lock(&mem_buf_list_lock);
              puVar5 = PTR_mem_buf_list_00103ac0;
              plVar1 = plVar10 + 9;
              uVar8 = __list_add_valid(plVar1,PTR_mem_buf_list_00103ac0,&mem_buf_list);
              if ((uVar8 & 1) != 0) {
                PTR_mem_buf_list_00103ac0 = (undefined *)plVar1;
                plVar10[9] = (long)&mem_buf_list;
                plVar10[10] = (long)puVar5;
                *(long **)puVar5 = plVar1;
              }
              mutex_unlock(&mem_buf_list_lock);
              goto LAB_00101634;
            }
            uVar9 = (ulong)uVar6;
            mem_buf_relinquish_mem(plVar10);
          }
          if ((int)plVar10[6] == 1) {
            kfree(plVar10[7]);
          }
        }
        else {
          uVar9 = 0xffffffea;
          plVar10[7] = -0x16;
        }
        if ((int)plVar10[4] == 1) {
          kfree(plVar10[5]);
        }
      }
      else {
        uVar9 = 0xffffffffffffffea;
        plVar10[5] = -0x16;
      }
      iVar12 = (int)uVar9;
      if (plVar10[2] != 0) {
        kvfree();
      }
    }
    else {
      uVar9 = dup_gh_sgl_desc();
      plVar10[2] = uVar9;
      if (uVar9 < 0xfffffffffffff001) goto LAB_00101694;
      iVar12 = (int)uVar9;
    }
    kfree(plVar10[1]);
  }
  else {
    iVar12 = (int)uVar8;
  }
  kfree(plVar10);
  plVar10 = (long *)(long)iVar12;
LAB_00101634:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar10;
}



//------------------------------------------------------------
// trace_mem_buf_alloc_info @ 00101830 size=36
// signature: undefined trace_mem_buf_alloc_info(void)
// callers: [mem_buf_alloc]
//------------------------------------------------------------

void trace_mem_buf_alloc_info(void)

{
  return;
}



//------------------------------------------------------------
// mem_buf_request_mem @ 001018c8 size=180
// signature: undefined mem_buf_request_mem(void)
// callers: [mem_buf_alloc]
//------------------------------------------------------------

ulong mem_buf_request_mem(undefined8 *param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = mem_buf_init_txn(mem_buf_msgq_hdl,param_1);
  if (uVar2 < 0xfffffffffffff001) {
    uVar3 = mem_buf_construct_alloc_req
                      (uVar2,*param_1,param_1[1],*(undefined4 *)(param_1 + 4),param_1[5],
                       *(undefined4 *)((long)param_1 + 0x1c));
    if (uVar3 < 0xfffffffffffff001) {
      uVar1 = mem_buf_msgq_send(mem_buf_msgq_hdl,uVar3);
      kfree(uVar3);
      if ((int)uVar1 < 0) {
        uVar3 = (ulong)uVar1;
      }
      else {
        uVar3 = mem_buf_txn_wait(mem_buf_msgq_hdl,uVar2);
        uVar3 = uVar3 & 0xffffffff;
      }
    }
    mem_buf_destroy_txn(mem_buf_msgq_hdl,uVar2);
  }
  else {
    uVar3 = uVar2 & 0xffffffff;
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_relinquish_mem @ 0010197c size=248
// signature: undefined mem_buf_relinquish_mem(void)
// callers: [mem_buf_free, mem_buf_alloc]
//------------------------------------------------------------

void mem_buf_relinquish_mem(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_58;
  undefined4 *local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  iVar2 = *(int *)(param_1 + 0x18);
  local_30 = 7;
  uStack_2c = 3;
  local_48 = (undefined4 *)0x0;
  local_40 = 0;
  local_58 = 0;
  local_50 = (undefined4 *)0x0;
  if (iVar2 == -1) {
    uVar3 = dup_gh_sgl_desc_to_sgt(*(undefined8 *)(param_1 + 0x10));
    if (uVar3 < 0xfffffffffffff001) {
      local_50 = &uStack_2c;
      local_48 = &local_30;
      local_58 = CONCAT44(local_58._4_4_,1);
      local_40 = CONCAT44(1,(undefined4)local_40);
      local_38 = 0;
      iVar2 = mem_buf_assign_mem(0,uVar3,&local_58);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x18) = (undefined4)local_40;
        __mem_buf_relinquish_mem(*(undefined4 *)(param_1 + 0x58));
      }
      sg_free_table(uVar3);
      kfree(uVar3);
    }
  }
  else {
    if (*(int *)(param_1 + 0x1c) != 0) {
      iVar2 = mem_buf_unmap_mem_s2(iVar2);
      if (iVar2 != 0) goto LAB_00101a48;
      iVar2 = *(int *)(param_1 + 0x18);
    }
    __mem_buf_relinquish_mem(*(undefined4 *)(param_1 + 0x58),iVar2);
  }
LAB_00101a48:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mem_buf_free @ 00101a78 size=176
// signature: undefined mem_buf_free(void)
// callers: []
//------------------------------------------------------------

void mem_buf_free(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  mutex_lock(&mem_buf_list_lock);
  uVar3 = __list_del_entry_valid(param_1 + 0x48);
  if ((uVar3 & 1) != 0) {
    lVar1 = *(long *)(param_1 + 0x48);
    plVar2 = *(long **)(param_1 + 0x50);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(param_1 + 0x48) = 0xdead000000000100;
  *(undefined8 *)(param_1 + 0x50) = 0xdead000000000122;
  mutex_unlock(&mem_buf_list_lock);
  mem_buf_relinquish_mem(param_1);
  kvfree(*(undefined8 *)(param_1 + 0x10));
  if (*(int *)(param_1 + 0x30) == 1) {
    kfree(*(undefined8 *)(param_1 + 0x38));
  }
  if (*(int *)(param_1 + 0x20) == 1) {
    kfree(*(undefined8 *)(param_1 + 0x28));
  }
  kfree(*(undefined8 *)(param_1 + 8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// mem_buf_get_sgl @ 00101b2c size=8
// signature: undefined mem_buf_get_sgl(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_buf_get_sgl(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}



//------------------------------------------------------------
// mem_buf_retrieve @ 00101b38 size=616
// signature: undefined mem_buf_retrieve(void)
// callers: [mem_buf_retrieve_user]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * mem_buf_retrieve(uint *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  undefined8 *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ulong uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined *local_98;
  undefined *puStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_68 = DAT_00104368;
  uStack_60 = DAT_00104370;
  local_58 = DAT_00104378;
  local_88 = DAT_00104348;
  local_80 = DAT_00104350;
  local_78 = DAT_00104358;
  uStack_70 = DAT_00104360;
  local_98 = PTR_s_mem_buf_00104338;
  puStack_90 = PTR___this_module_00104340;
  if (((((param_1[7] & 0xfff7fffc) == 0) && (param_1[1] != 0)) && (*(long *)(param_1 + 2) != 0)) &&
     (*(long *)(param_1 + 4) != 0)) {
    puVar6 = (undefined8 *)kmalloc_trace(_mem_buf_vmid_perm_list_to_gh_acl,0xdc0,0xb0);
    if (puVar6 == (undefined8 *)0x0) {
      puVar12 = (undefined8 *)0xfffffffffffffff4;
    }
    else {
      puVar7 = (uint *)mem_buf_vmid_perm_list_to_gh_acl
                                 (*(undefined8 *)(param_1 + 2),*(undefined8 *)(param_1 + 4),
                                  param_1[1]);
      if (puVar7 < (uint *)0xfffffffffffff001) {
        uVar10 = (ulong)*puVar7;
        if (*puVar7 != 0) {
          pcVar11 = (char *)((long)puVar7 + 6);
          do {
            if ((*param_1 == (uint)*(ushort *)(pcVar11 + -2)) && (*pcVar11 != '\0')) {
              uVar8 = 2;
              goto LAB_00101c80;
            }
            pcVar11 = pcVar11 + 4;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        uVar8 = 1;
LAB_00101c80:
        iVar5 = mem_buf_map_mem_s2(uVar8,param_1 + 6,puVar7,&local_50);
        if (iVar5 == 0) {
          iVar5 = mem_buf_map_mem_s1(local_50);
          if (-1 < iVar5) {
            puVar12 = (undefined8 *)dup_gh_sgl_desc_to_sgt(local_50);
            if (puVar12 < (undefined8 *)0xfffffffffffff001) {
              uVar8 = puVar12[1];
              puVar13 = puVar6 + 10;
              *puVar13 = *puVar12;
              puVar6[0xb] = uVar8;
              kfree(puVar12);
              qcom_sg_buffer_init(puVar6);
              *puVar6 = 0;
              uVar9 = mem_buf_get_sgl_buf_size(local_50);
              uVar8 = *(undefined8 *)(param_1 + 2);
              uVar1 = *(undefined8 *)(param_1 + 4);
              puVar6[9] = uVar9;
              uVar2 = param_1[6];
              uVar3 = param_1[1];
              *(undefined1 *)(puVar6 + 0xe) = 0;
              puVar6[0x14] = mem_buf_retrieve_release;
              uVar8 = mem_buf_vmperm_alloc_accept
                                (puVar13,uVar2,uVar8,uVar1,uVar3,&qcom_sg_release,puVar6 + 0x15);
              local_80 = puVar6[9];
              puVar6[0xf] = uVar8;
              local_78 = CONCAT44(local_78._4_4_,param_1[7]);
              local_68 = puVar6;
              puVar12 = (undefined8 *)qcom_dma_buf_export(&local_98);
              if (puVar12 < (undefined8 *)0xfffffffffffff001) {
                kvfree(local_50);
                kfree(puVar7);
                goto LAB_00101bac;
              }
              sg_free_table(puVar13);
            }
            iVar5 = (int)puVar12;
            mem_buf_unmap_mem_s1(local_50);
          }
          kvfree(local_50);
          mem_buf_unmap_mem_s2(param_1[6]);
        }
        kfree(puVar7);
      }
      else {
        iVar5 = (int)puVar7;
      }
      kfree(puVar6);
      puVar12 = (undefined8 *)(long)iVar5;
    }
  }
  else {
    puVar12 = (undefined8 *)0xffffffffffffffea;
  }
LAB_00101bac:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar12;
}



//------------------------------------------------------------
// mem_buf_retrieve_release @ 00101da4 size=52
// signature: undefined mem_buf_retrieve_release(void)
// callers: []
//------------------------------------------------------------

void mem_buf_retrieve_release(long param_1)

{
  sg_free_table(param_1 + 0x50);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// qcom_dma_buf_export @ 00101dd8 size=68
// signature: undefined qcom_dma_buf_export(void)
// callers: [mem_buf_retrieve]
//------------------------------------------------------------

ulong qcom_dma_buf_export(undefined8 param_1)

{
  ulong uVar1;
  
  uVar1 = mem_buf_dma_buf_export(param_1,&qcom_sg_buf_ops);
  if (uVar1 < 0xfffffffffffff001) {
    qcom_store_dma_buf_fops(*(undefined8 *)(uVar1 + 8));
  }
  return uVar1;
}



//------------------------------------------------------------
// mem_buf_alloc_fd @ 00101e20 size=200
// signature: undefined mem_buf_alloc_fd(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

void mem_buf_alloc_fd(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((*param_1 != 0) && (*(uint *)(param_1 + 2) != 0)) {
    uVar2 = 0xffffffea;
    if ((((param_1[1] == 0) ||
         (((0x10 < *(uint *)(param_1 + 2) || (*(int *)((long)param_1 + 0x14) != 1)) ||
          ((int)param_1[4] != 1)))) ||
        (((param_1[6] != 0 || (param_1[7] != 0)) || (param_1[8] != 0)))) ||
       (uVar2 = mem_buf_prep_alloc_data(&local_68), (int)uVar2 < 0)) goto LAB_00101ec0;
    mem_buf_free_alloc_data(&local_68);
  }
  uVar2 = 0xffffffea;
LAB_00101ec0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// mem_buf_prep_alloc_data @ 00101ee8 size=232
// signature: undefined mem_buf_prep_alloc_data(void)
// callers: [mem_buf_alloc_fd]
//------------------------------------------------------------

ulong mem_buf_prep_alloc_data(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = *(undefined4 *)(param_2 + 2);
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 1) = uVar1;
  uVar2 = mem_buf_acl_to_vmid_perms_list(uVar1,param_2[1],param_1 + 2,param_1 + 3);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 0) {
    param_1[5] = 0;
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)((long)param_2 + 0x14);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 4);
    uVar3 = mem_buf_retrieve_mem_type_data_user(*(undefined4 *)((long)param_2 + 0x14),param_2[3]);
    param_1[7] = uVar3;
    if (uVar3 < 0xfffffffffffff001) {
      uVar3 = mem_buf_retrieve_mem_type_data_user(*(undefined4 *)(param_2 + 4),param_2[5]);
      param_1[9] = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        uVar3 = 0;
        goto LAB_00101fb4;
      }
      if (*(int *)(param_1 + 6) == 1) {
        kfree(param_1[7]);
      }
    }
    kfree(param_1[2]);
    kfree(param_1[3]);
  }
LAB_00101fb4:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_free_alloc_data @ 00101fd0 size=92
// signature: undefined mem_buf_free_alloc_data(void)
// callers: [mem_buf_alloc_fd]
//------------------------------------------------------------

void mem_buf_free_alloc_data(long param_1)

{
  if (*(int *)(param_1 + 0x40) == 1) {
    kfree(*(undefined8 *)(param_1 + 0x48));
  }
  if (*(int *)(param_1 + 0x30) == 1) {
    kfree(*(undefined8 *)(param_1 + 0x38));
  }
  kfree(*(undefined8 *)(param_1 + 0x10));
  kfree(*(undefined8 *)(param_1 + 0x18));
  return;
}



//------------------------------------------------------------
// mem_buf_retrieve_user @ 00102030 size=384
// signature: undefined mem_buf_retrieve_user(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

ulong mem_buf_retrieve_user(undefined4 *param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar1 = param_1[1];
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_4c = 0;
  local_68 = 0;
  local_60 = 0;
  if (uVar1 == 0) {
    uVar6 = 0xffffffea;
    goto LAB_0010210c;
  }
  uVar6 = 0xffffffea;
  if ((((*(long *)(param_1 + 2) == 0) || (0x10 < uVar1)) || (*(long *)(param_1 + 8) != 0)) ||
     (((*(long *)(param_1 + 10) != 0 || (*(long *)(param_1 + 0xc) != 0)) ||
      ((param_1[7] & 0xfff7fffc) != 0)))) goto LAB_0010210c;
  uVar4 = mem_buf_acl_to_vmid_perms_list(uVar1,*(long *)(param_1 + 2),&local_40,&local_48);
  uVar6 = uVar4 & 0xffffffff;
  if ((int)uVar4 != 0) goto LAB_0010210c;
  iVar3 = mem_buf_fd_to_vmid(*param_1);
  local_68 = CONCAT44(local_68._4_4_,iVar3);
  if (iVar3 < 0) {
    iVar3 = ___ratelimit(mem_buf_retrieve_user__rs,"mem_buf_retrieve_user");
    if (iVar3 != 0) {
      _printk(&DAT_00103f14,"mem_buf_retrieve_user",*param_1);
    }
LAB_00102188:
    uVar6 = 0;
  }
  else {
    local_68 = CONCAT44(param_1[1],iVar3);
    local_4c = param_1[7];
    local_60 = local_40;
    local_58 = local_48;
    local_50 = (undefined4)*(undefined8 *)(param_1 + 4);
    uVar4 = mem_buf_retrieve(&local_68);
    if (uVar4 < 0xfffffffffffff001) {
      uVar5 = dma_buf_fd(uVar4,local_4c);
      uVar6 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        param_1[6] = (int)uVar5;
        goto LAB_00102188;
      }
      dma_buf_put(uVar4);
    }
    else {
      uVar6 = uVar4 & 0xffffffff;
    }
  }
  kfree(local_40);
  kfree(local_48);
LAB_0010210c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// mem_buf_msgq_alloc @ 001021b4 size=252
// signature: undefined mem_buf_msgq_alloc(void)
// callers: [mem_buf_msgq_probe]
//------------------------------------------------------------

ulong mem_buf_msgq_alloc(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  undefined *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = PTR_msgq_ops_001043a0;
  uStack_40 = DAT_001043a8;
  if ((mem_buf_capability & 3) != 0) {
    mem_buf_wq = alloc_workqueue("mem_buf_wq",0x12,0);
    if (mem_buf_wq == 0) {
      _dev_err(param_1,"Unable to initialize workqueue\n");
      uVar2 = 0xffffffea;
      goto LAB_00102240;
    }
    uVar2 = mem_buf_msgq_register("trusted_vm",&local_48);
    mem_buf_msgq_hdl = uVar2;
    if (0xfffffffffffff000 < uVar2) {
      _dev_err(param_1,"Unable to register for mem-buf message queue\n");
      destroy_workqueue(mem_buf_wq);
      mem_buf_wq = 0;
      goto LAB_00102240;
    }
  }
  uVar2 = 0;
LAB_00102240:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// mem_buf_msgq_free @ 001022b4 size=216
// signature: undefined mem_buf_msgq_free(void)
// callers: [mem_buf_msgq_probe, mem_buf_msgq_remove]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_msgq_free(void)

{
  if ((mem_buf_capability & 3) != 0) {
    mutex_lock(&mem_buf_list_lock);
    if ((undefined **)mem_buf_list != &mem_buf_list) {
      _dev_err(_mem_buf_dev,"Removing mem-buf driver while there are membufs\n");
    }
    mutex_unlock(&mem_buf_list_lock);
    mutex_lock(mem_buf_xfer_mem_list_lock);
    if ((undefined **)mem_buf_xfer_mem_list != &mem_buf_xfer_mem_list) {
      _dev_err(_mem_buf_dev,"Removing mem-buf driver while memory is still lent\n");
    }
    mutex_unlock(mem_buf_xfer_mem_list_lock);
    mem_buf_msgq_unregister(mem_buf_msgq_hdl);
    mem_buf_msgq_hdl = 0;
    destroy_workqueue(mem_buf_wq);
    mem_buf_wq = 0;
  }
  return;
}



//------------------------------------------------------------
// __mem_buf_relinquish_mem @ 0010238c size=184
// signature: undefined __mem_buf_relinquish_mem(void)
// callers: [mem_buf_relinquish_memparcel_hdl, mem_buf_relinquish_mem]
//------------------------------------------------------------

void __mem_buf_relinquish_mem(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = mem_buf_init_txn(mem_buf_msgq_hdl,0);
  if (uVar2 < 0xfffffffffffff001) {
    uVar3 = mem_buf_construct_relinquish_msg(uVar2,param_1,param_2);
    if (uVar3 < 0xfffffffffffff001) {
      iVar1 = mem_buf_msgq_send(mem_buf_msgq_hdl,uVar3);
      kfree(uVar3);
      if (iVar1 < 0) {
        _printk(&DAT_00103c21,"__mem_buf_relinquish_mem",iVar1);
      }
      mem_buf_txn_wait(mem_buf_msgq_hdl,uVar2);
    }
    mem_buf_destroy_txn(mem_buf_msgq_hdl,uVar2);
  }
  return;
}



//------------------------------------------------------------
// mem_buf_retrieve_mem_type_data_user @ 001024ac size=400
// signature: undefined mem_buf_retrieve_mem_type_data_user(void)
// callers: [mem_buf_prep_alloc_data]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long mem_buf_retrieve_mem_type_data_user(int param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined8 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  if (param_1 == 2) {
    lVar4 = 0;
    goto LAB_001025f4;
  }
  if (param_1 == 1) {
    puVar5 = (undefined8 *)sp_el0;
    local_30 = 0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar6 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar6 < 0x7ffffffff9) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        puVar5 = (undefined8 *)puVar5[1];
        uVar2 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      lVar4 = __arch_copy_from_user(puVar5,&local_30,param_2 & 0xff7fffffffffffff,8);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      if (lVar4 == 0) {
        lVar4 = kmalloc_trace(_mutex_lock,0xdc0,0x80);
        if (lVar4 == 0) {
          lVar4 = -0xc;
          goto LAB_001025f4;
        }
        iVar3 = strncpy_from_user(lVar4,local_30,0x80);
        if ((-1 < iVar3) && (iVar3 != 0x80)) goto LAB_001025f4;
        kfree(lVar4);
      }
    }
  }
  lVar4 = -0x16;
LAB_001025f4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// mem_buf_alloc_req_hdlr @ 00102658 size=176
// signature: undefined mem_buf_alloc_req_hdlr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_alloc_req_hdlr(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  
  if (((mem_buf_capability & 1) != 0) &&
     (plVar2 = (long *)kmalloc_trace(_kvfree,0xcc0,0x40), plVar2 != (long *)0x0)) {
    lVar3 = kmemdup(param_2,param_3,0xcc0);
    if (lVar3 == 0) {
      kfree(plVar2);
    }
    else {
      *plVar2 = lVar3;
      plVar2[1] = param_3;
      plVar2[2] = 0xfffffffe0;
      plVar2[3] = (long)(plVar2 + 3);
      plVar2[4] = (long)(plVar2 + 3);
      uVar1 = mem_buf_wq;
      plVar2[5] = (long)mem_buf_alloc_req_work;
      queue_work_on(0x20,uVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// mem_buf_alloc_resp_hdlr @ 0010270c size=120
// signature: undefined mem_buf_alloc_resp_hdlr(void)
// callers: []
//------------------------------------------------------------

int mem_buf_alloc_resp_hdlr(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  
  if ((mem_buf_capability >> 1 & 1) == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 < 0) {
      _printk(&DAT_00103bfb,"mem_buf_alloc_resp_hdlr",iVar1);
    }
    else {
      *(undefined4 *)(param_4 + 0x18) = *(undefined4 *)(param_2 + 0x10);
      *(undefined4 *)(param_4 + 0x58) = *(undefined4 *)(param_2 + 0x14);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// mem_buf_relinquish_hdlr @ 00102804 size=176
// signature: undefined mem_buf_relinquish_hdlr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_relinquish_hdlr(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  
  if (((mem_buf_capability & 1) != 0) &&
     (plVar2 = (long *)kmalloc_trace(_kvfree,0xcc0,0x40), plVar2 != (long *)0x0)) {
    lVar3 = kmemdup(param_2,param_3,0xcc0);
    if (lVar3 == 0) {
      kfree(plVar2);
    }
    else {
      *plVar2 = lVar3;
      plVar2[1] = param_3;
      plVar2[2] = 0xfffffffe0;
      plVar2[3] = (long)(plVar2 + 3);
      plVar2[4] = (long)(plVar2 + 3);
      uVar1 = mem_buf_wq;
      plVar2[5] = (long)mem_buf_relinquish_work;
      queue_work_on(0x20,uVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// mem_buf_relinquish_memparcel_hdl @ 001028b8 size=36
// signature: undefined mem_buf_relinquish_memparcel_hdl(void)
// callers: []
//------------------------------------------------------------

void mem_buf_relinquish_memparcel_hdl(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  __mem_buf_relinquish_mem(param_2,param_3);
  return;
}



//------------------------------------------------------------
// mem_buf_alloc_req_work @ 001028e0 size=2332
// signature: undefined mem_buf_alloc_req_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_alloc_req_work(long param_1)

{
  char *__string;
  long lVar1;
  long *plVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined *puVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  long *plVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 *puVar15;
  ulong uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  long lVar19;
  ulong *puVar20;
  ulong uVar21;
  long lVar22;
  long *plVar23;
  long lVar24;
  long lVar25;
  int iVar26;
  ulong uVar27;
  long lVar28;
  ulong uVar29;
  undefined8 local_90;
  long local_88;
  long lStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar24 = sp_el0;
  local_68 = *(long *)(lVar24 + 0x638);
  plVar23 = (long *)(param_1 + -0x10);
  lVar24 = *plVar23;
  while( true ) {
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    lStack_80 = 0;
    local_90 = 0;
    if ((*(int *)(lVar24 + 0x1c) != 1) ||
       (__string = (char *)(lVar24 + 0x24), __string == (char *)0x0)) break;
    iVar11 = *(int *)(lVar24 + 0x14);
    plVar12 = (long *)kmalloc_trace(_mutex_lock,0xdc0,0x60);
    if (plVar12 == (long *)0x0) {
      plVar12 = (long *)0xfffffffffffffff4;
      goto LAB_0010304c;
    }
    mutex_lock(mem_buf_idr_mutex);
    iVar9 = idr_alloc_cyclic(mem_buf_obj_idr,0,0,0x7fffffff,0xcc0);
    mutex_unlock(mem_buf_idr_mutex);
    if (iVar9 < 0) {
      _printk(&DAT_00103d00,"mem_buf_alloc_obj_id",iVar9);
      _printk(&DAT_00103f32,"mem_buf_prep_xfer_mem",iVar9);
LAB_00102e9c:
      kfree(plVar12);
      plVar12 = (long *)(long)iVar9;
      if ((long *)0xfffffffffffff000 < plVar12) goto joined_r0x00103048;
LAB_00102a54:
      if ((int)plVar12[1] != 2) {
        if ((int)plVar12[1] == 1) {
          lVar25 = plVar12[2];
          lVar19 = dma_heap_find(lVar25);
          if (lVar19 != 0) {
            uVar13 = dma_heap_buffer_alloc(lVar19,*plVar12,0x80002,0);
            if (0xfffffffffffff000 < uVar13) {
              _printk(&DAT_00103ed3,"mem_buf_rmt_alloc_dmaheap_mem",*plVar12,lVar25,0x80002,uVar13);
              goto LAB_00102ff0;
            }
            uVar14 = dma_buf_attach(uVar13,_mem_buf_dev);
            if (0xfffffffffffff000 < uVar14) {
              _printk(&DAT_00103de2,"mem_buf_rmt_alloc_dmaheap_mem",uVar14);
              dma_buf_put(uVar13);
              uVar13 = uVar14 & 0xffffffff;
              goto LAB_00102ff0;
            }
            puVar15 = (undefined8 *)dma_buf_map_attachment(uVar14,0);
            if ((undefined8 *)0xfffffffffffff000 < puVar15) {
              _printk(&DAT_00103cbd,"mem_buf_rmt_alloc_dmaheap_mem",puVar15);
              dma_buf_detach(uVar13,uVar14);
              dma_buf_put(uVar13);
              uVar13 = (ulong)puVar15 & 0xffffffff;
              goto LAB_00102ff0;
            }
            *(ulong *)(lVar25 + 0x80) = uVar13;
            *(ulong *)(lVar25 + 0x88) = uVar14;
            goto LAB_00102ad0;
          }
          _printk(&DAT_00103fd3,"mem_buf_rmt_alloc_dmaheap_mem",lVar25);
        }
        iVar11 = -0x16;
        goto LAB_00102f24;
      }
      lVar19 = *plVar12;
      puVar15 = (undefined8 *)kmalloc_trace(_kvfree,0xdc0,0x10);
      if (puVar15 == (undefined8 *)0x0) {
        iVar11 = -0xc;
        goto LAB_00102f24;
      }
      uVar14 = lVar19 + 0xfff;
      uVar27 = uVar14 >> 0xc;
      lVar19 = *(long *)(_mem_buf_dev + 0x2d8);
      if (lVar19 != 0) {
        uVar16 = sg_alloc_table(puVar15,1,0xcc0);
        uVar13 = uVar16 & 0xffffffff;
        if ((int)uVar16 != 0) goto LAB_00102fe8;
        uVar10 = (int)uVar27 << 0xc;
        uVar13 = (ulong)uVar10 - 1;
        iVar11 = 0x40 - (int)LZCOUNT(uVar13 >> 0xc);
        if (8 < iVar11) {
          iVar11 = 9;
        }
        iVar9 = 0;
        if (uVar13 != 0xfff) {
          iVar9 = iVar11;
        }
        uVar13 = cma_alloc(lVar19,uVar14 >> 0xc & 0xffffffff,iVar9,0);
        if (uVar13 == 0) {
          sg_free_table(puVar15);
          uVar13 = 0xfffffff4;
          goto LAB_00102fe8;
        }
        if ((uVar13 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x800,0x10326c);
          (*pcVar8)();
        }
        puVar20 = (ulong *)*puVar15;
        *(undefined4 *)(puVar20 + 1) = 0;
        *(uint *)((long)puVar20 + 0xc) = uVar10;
        *puVar20 = *puVar20 & 3 | uVar13;
        memset((void *)((uVar13 & 0x3ffffffffffc0) << 6 | 0xff00000000000000),0,(ulong)uVar10);
        goto LAB_00102ad0;
      }
      uVar16 = (uVar27 & 0xffffffff) * 8;
      lVar19 = kvmalloc_node(uVar16,0xdc0,0xffffffff);
      if (lVar19 == 0) {
        uVar13 = 0xfffffff4;
        goto LAB_00102fe8;
      }
      uVar13 = uVar27;
      if ((int)uVar27 != 0) {
        uVar13 = 0;
        uVar29 = 0x7ff;
        do {
          iVar11 = (int)uVar13;
          uVar29 = uVar29 & (long)((2 << (ulong)(((uint)LZCOUNT((int)uVar27) ^ 0x1f) & 0x1f)) + -1);
          while( true ) {
            if (uVar29 == 0) {
              uVar13 = 0xfffffff4;
              goto LAB_00102ebc;
            }
            uVar10 = (uint)LZCOUNT(uVar29) ^ 0x3f;
            uVar18 = 0x12dc0;
            uVar5 = 1 << (ulong)(uVar10 & 0x1f);
            uVar6 = tpidr_el1;
            if (uVar29 <= uVar5) {
              uVar18 = 0xdc0;
            }
            lVar25 = __alloc_pages(uVar18,uVar10,0,0);
            if (lVar25 != 0) break;
            uVar29 = uVar29 & ~uVar5;
          }
          if (uVar10 != 0) {
            split_page(lVar25,uVar10);
          }
          uVar21 = (ulong)(uVar5 - 1);
          uVar3 = 0;
          if ((ulong)((long)iVar11 * 8) <= uVar16) {
            uVar3 = uVar16 + (long)iVar11 * -8;
          }
          uVar4 = uVar21;
          if (uVar3 >> 3 <= uVar21) {
            uVar4 = uVar3 >> 3;
          }
          lVar28 = lVar25;
          uVar10 = uVar5;
          if (1 < uVar4) {
            uVar3 = 0;
            if ((ulong)((long)iVar11 * 8) <= uVar16) {
              uVar3 = uVar16 + (long)iVar11 * -8;
            }
            if (uVar3 >> 3 <= uVar21) {
              uVar21 = uVar3 >> 3;
            }
            if (iVar11 <= iVar11 + (int)uVar21) {
              uVar3 = uVar4 + 1 & 1;
              uVar21 = 2;
              if (uVar3 != 0) {
                uVar21 = uVar3;
              }
              lVar22 = (uVar4 + 1) - uVar21;
              iVar9 = (int)lVar22;
              uVar10 = uVar5 - iVar9;
              lVar28 = lVar25 + lVar22 * 0x40;
              do {
                lVar1 = lVar25 + 0x40;
                iVar26 = (int)uVar13;
                *(long *)(lVar19 + (long)iVar26 * 8) = lVar25;
                lVar25 = lVar25 + 0x80;
                lVar22 = lVar22 + -2;
                uVar13 = (ulong)(iVar26 + 2);
                *(long *)(lVar19 + (long)(iVar26 + 1) * 8) = lVar1;
              } while (lVar22 != 0);
              uVar13 = (ulong)(uint)(iVar11 + iVar9);
            }
          }
          do {
            iVar11 = (int)uVar13;
            if ((uVar16 <= (ulong)((long)iVar11 * 8)) || (uVar16 <= (ulong)((long)iVar11 * 8)))
            goto LAB_00103178;
            *(long *)(lVar19 + (long)iVar11 * 8) = lVar28;
            uVar13 = (ulong)(iVar11 + 1);
            uVar10 = uVar10 - 1;
            lVar28 = lVar28 + 0x40;
          } while (uVar10 != 0);
          uVar5 = (int)uVar27 - uVar5;
          uVar27 = (ulong)uVar5;
        } while (uVar5 != 0);
      }
      iVar11 = (int)uVar13;
      uVar14 = sg_alloc_table_from_pages_segment
                         (puVar15,lVar19,uVar13 & 0xffffffff,0,uVar14 & 0xfffff000,0xffffffff,0xcc0)
      ;
      uVar13 = uVar14 & 0xffffffff;
      if ((int)uVar14 == 0) {
        kvfree(lVar19);
LAB_00102ad0:
        plVar12[3] = (long)puVar15;
        *(undefined1 *)(plVar12 + 4) = 0;
LAB_00102ad8:
        uVar18 = *(undefined4 *)(lVar24 + 0x18);
        local_88 = plVar12[9];
        lStack_80 = plVar12[10];
        local_90 = CONCAT44(local_90._4_4_,(int)plVar12[8]);
        iVar11 = mem_buf_assign_mem(uVar18,puVar15,&local_90);
        if (-1 < iVar11) {
          *(undefined4 *)((long)plVar12 + 0x24) = uVar18;
          *(undefined4 *)(plVar12 + 5) = (undefined4)local_78;
          goto LAB_00102ffc;
        }
        if (iVar11 == -99) {
          iVar11 = -99;
        }
        else {
          mem_buf_rmt_free_mem(plVar12);
        }
LAB_00102f24:
        mem_buf_free_xfer_mem(plVar12);
        plVar12 = (long *)(long)iVar11;
      }
      else {
LAB_00102ebc:
        if (iVar11 == 0) {
          kvfree(lVar19);
        }
        else {
          iVar11 = iVar11 + -1;
          do {
            if ((uVar16 <= (ulong)((long)iVar11 * 8)) || (uVar16 <= (ulong)((long)iVar11 * 8))) {
LAB_00103178:
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(1,0x10317c);
              (*pcVar8)();
            }
            __free_pages(*(undefined8 *)(lVar19 + (long)iVar11 * 8),0);
            iVar11 = iVar11 + -1;
          } while (iVar11 != -1);
          kvfree(lVar19);
          if ((int)uVar13 == 0) goto LAB_00102ad0;
        }
LAB_00102fe8:
        kfree(puVar15);
LAB_00102ff0:
        iVar11 = (int)uVar13;
        if (iVar11 < 0) goto LAB_00102f24;
        if ((char)plVar12[4] == '\0') {
          puVar15 = (undefined8 *)plVar12[3];
          goto LAB_00102ad8;
        }
LAB_00102ffc:
        mutex_lock(mem_buf_xfer_mem_list_lock);
        puVar7 = mem_buf_xfer_mem_list;
        plVar2 = plVar12 + 6;
        uVar13 = __list_add_valid(plVar2,&mem_buf_xfer_mem_list,mem_buf_xfer_mem_list);
        if ((uVar13 & 1) != 0) {
          *(long **)(puVar7 + 8) = plVar2;
          plVar12[6] = (long)puVar7;
          plVar12[7] = (long)&mem_buf_xfer_mem_list;
          mem_buf_xfer_mem_list = (undefined *)plVar2;
        }
        mutex_unlock(mem_buf_xfer_mem_list_lock);
      }
joined_r0x00103048:
      if ((long *)0xfffffffffffff000 < plVar12) goto LAB_0010304c;
      uVar13 = 0;
      uVar18 = (undefined4)plVar12[5];
      uVar17 = (undefined4)plVar12[0xb];
      goto LAB_00103074;
    }
    *(int *)(plVar12 + 0xb) = iVar9;
    lVar19 = *(long *)(lVar24 + 0xc);
    *(int *)(plVar12 + 1) = iVar11;
    *plVar12 = lVar19;
    *(undefined4 *)(plVar12 + 8) = 1;
    uVar10 = mem_buf_gh_acl_desc_to_vmid_perm_list((int *)(lVar24 + 0x1c),plVar12 + 9,plVar12 + 10);
    if (uVar10 != 0) {
      uVar13 = (ulong)uVar10;
      _printk(&DAT_00103f56,"mem_buf_prep_xfer_mem",uVar13);
LAB_00102e70:
      iVar9 = (int)uVar13;
      lVar19 = plVar12[0xb];
      mutex_lock(mem_buf_idr_mutex);
      idr_remove(mem_buf_obj_idr,(int)lVar19);
      mutex_unlock(mem_buf_idr_mutex);
      goto LAB_00102e9c;
    }
    if (iVar11 == 2) {
      uVar13 = 0;
LAB_00102a3c:
      plVar12[2] = uVar13;
      plVar12[6] = (long)(plVar12 + 6);
      plVar12[7] = (long)(plVar12 + 6);
      if (plVar12 < (long *)0xfffffffffffff001) goto LAB_00102a54;
      goto joined_r0x00103048;
    }
    if (iVar11 != 1) {
      uVar13 = 0xffffffffffffffea;
LAB_00102e48:
      _printk(&DAT_00103e67,"mem_buf_prep_xfer_mem",uVar13);
      kfree(plVar12[9]);
      kfree(plVar12[10]);
      goto LAB_00102e70;
    }
    uVar13 = kmalloc_trace(_mem_buf_vmid_perm_list_to_gh_acl,0xdc0,0x90);
    if (uVar13 == 0) {
      uVar13 = 0xfffffffffffffff4;
      goto LAB_00102e48;
    }
    uVar14 = strnlen(__string,0x80);
    if (uVar14 == 0xffffffffffffffff) {
      fortify_panic("strnlen");
    }
    else {
      if (uVar14 != 0x80) {
        uVar14 = uVar14 + 1;
      }
      if (uVar14 < 0x81) {
        strscpy(uVar13,__string);
        if (uVar13 < 0xfffffffffffff001) goto LAB_00102a3c;
        goto LAB_00102e48;
      }
    }
    fortify_panic("strscpy");
    lVar19 = tpidr_el1;
    if ((*(ulong *)(&__cpu_online_mask +
                   ((ulong)(*(uint *)(&cpu_number + lVar19) >> 3) & 0x1ffffff8)) >>
         ((ulong)*(uint *)(&cpu_number + lVar19) & 0x3f) & 1) != 0) {
      lVar25 = sp_el0;
      *(int *)(lVar25 + 0x10) = *(int *)(lVar25 + 0x10) + 1;
      __traceiter_receive_alloc_req(0,lVar24);
      lVar19 = *(long *)(lVar25 + 0x10) + -1;
      *(int *)(lVar25 + 0x10) = (int)lVar19;
      if ((lVar19 == 0) || (*(long *)(lVar25 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
    }
  }
  plVar12 = (long *)0xffffffffffffffea;
LAB_0010304c:
  uVar13 = (ulong)plVar12 & 0xffffffff;
  _printk(&DAT_00103e06,"mem_buf_alloc_req_work",(ulong)plVar12 & 0xffffffff);
  plVar12 = (long *)0x0;
  uVar18 = 0;
  uVar17 = 0;
LAB_00103074:
  uVar13 = mem_buf_construct_alloc_resp(lVar24,uVar13,uVar18,uVar17);
  kfree(*plVar23);
  kfree(plVar23);
  if (uVar13 < 0xfffffffffffff001) {
    iVar11 = mem_buf_msgq_send(mem_buf_msgq_hdl,uVar13);
    kfree(uVar13);
    if (-1 < iVar11) goto LAB_00103118;
    _printk(&DAT_00103c57,"mem_buf_alloc_req_work",iVar11);
  }
  if (plVar12 != (long *)0x0) {
    mutex_lock(mem_buf_xfer_mem_list_lock);
    uVar13 = __list_del_entry_valid(plVar12 + 6);
    if ((uVar13 & 1) != 0) {
      lVar24 = plVar12[6];
      plVar23 = (long *)plVar12[7];
      *(long **)(lVar24 + 8) = plVar23;
      *plVar23 = lVar24;
    }
    plVar12[6] = -0x2152ffffffffff00;
    plVar12[7] = -0x2152fffffffffede;
    mutex_unlock(mem_buf_xfer_mem_list_lock);
    mem_buf_cleanup_alloc_req(plVar12,(int)plVar12[5]);
  }
LAB_00103118:
  lVar24 = sp_el0;
  if (*(long *)(lVar24 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mem_buf_cleanup_alloc_req @ 0010326c size=264
// signature: undefined mem_buf_cleanup_alloc_req(void)
// callers: [mem_buf_relinquish_work, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_cleanup_alloc_req(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 local_38;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = param_2;
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(param_1 + 0x28) == param_2) {
      iVar2 = mem_buf_unassign_mem
                        (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x48),
                         *(undefined4 *)(param_1 + 0x40));
      if (iVar2 < 0) goto LAB_001032ac;
    }
    else {
      local_38 = 0;
      puVar3 = (undefined4 *)kmalloc_trace(_kvfree,0xdc0,8,param_2);
      if (puVar3 == (undefined4 *)0x0) goto LAB_001032ac;
      *puVar3 = 1;
      *(undefined2 *)(puVar3 + 1) = 3;
      *(undefined1 *)((long)puVar3 + 6) = 7;
      iVar2 = mem_buf_map_mem_s2(0,&local_2c,puVar3,&local_38,0x2d);
      if (iVar2 != 0) {
        kfree(puVar3);
        goto LAB_001032ac;
      }
      kvfree(local_38);
      kfree(puVar3);
    }
  }
  mem_buf_rmt_free_mem(param_1);
  mem_buf_free_xfer_mem(param_1);
LAB_001032ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mem_buf_rmt_free_mem @ 00103374 size=284
// signature: undefined mem_buf_rmt_free_mem(void)
// callers: [mem_buf_alloc_req_work, mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mem_buf_rmt_free_mem(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *plVar5;
  ulong *local_50;
  ulong local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (*(int *)(param_1 + 8) == 2) {
    plVar5 = *(long **)(param_1 + 0x18);
    local_48 = 0;
    uStack_40 = 0;
    local_50 = (ulong *)0x0;
    uVar4 = cma_release(*(undefined8 *)(_mem_buf_dev + 0x2d8),*(ulong *)*plVar5 & 0xfffffffffffffffc
                        ,*(uint *)(*plVar5 + 0xc) >> 0xc);
    if ((uVar4 & 1) == 0) {
      __sg_page_iter_start(&local_50,*plVar5,(int)plVar5[1],0);
      while (uVar4 = __sg_page_iter_next(&local_50), (uVar4 & 1) != 0) {
        __free_pages((*local_50 & 0xfffffffffffffffc) + (local_48 & 0xffffffff) * 0x40,0);
      }
    }
    sg_free_table(plVar5);
    kfree(plVar5);
  }
  else if (*(int *)(param_1 + 8) == 1) {
    lVar1 = *(long *)(param_1 + 0x10);
    uVar2 = *(undefined8 *)(lVar1 + 0x80);
    uVar3 = *(undefined8 *)(lVar1 + 0x88);
    dma_buf_unmap_attachment(uVar3,*(undefined8 *)(param_1 + 0x18),0);
    dma_buf_detach(uVar2,uVar3);
    dma_buf_put(*(undefined8 *)(lVar1 + 0x80));
    flush_delayed_fput();
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mem_buf_free_xfer_mem @ 00103490 size=132
// signature: undefined mem_buf_free_xfer_mem(void)
// callers: [mem_buf_alloc_req_work, mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

void mem_buf_free_xfer_mem(long param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) == 1) {
    kfree(*(undefined8 *)(param_1 + 0x10));
  }
  kfree(*(undefined8 *)(param_1 + 0x48));
  kfree(*(undefined8 *)(param_1 + 0x50));
  uVar1 = *(undefined4 *)(param_1 + 0x58);
  mutex_lock(mem_buf_idr_mutex);
  idr_remove(mem_buf_obj_idr,uVar1);
  mutex_unlock(mem_buf_idr_mutex);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// mem_buf_relinquish_work @ 00103518 size=292
// signature: undefined mem_buf_relinquish_work(void)
// callers: []
//------------------------------------------------------------

void mem_buf_relinquish_work(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  undefined **ppuVar7;
  
  plVar5 = (long *)(param_1 + -0x10);
  lVar6 = *plVar5;
  iVar3 = *(int *)(lVar6 + 0x10);
  mutex_lock(mem_buf_xfer_mem_list_lock);
  ppuVar7 = &mem_buf_xfer_mem_list;
  do {
    ppuVar7 = (undefined **)*ppuVar7;
    if (ppuVar7 == &mem_buf_xfer_mem_list) {
      mutex_unlock(mem_buf_xfer_mem_list_lock);
      goto LAB_00103620;
    }
  } while (*(int *)(ppuVar7 + 5) != iVar3);
  uVar4 = __list_del_entry_valid(ppuVar7);
  if ((uVar4 & 1) != 0) {
    puVar1 = *ppuVar7;
    plVar2 = (long *)ppuVar7[1];
    *(long **)(puVar1 + 8) = plVar2;
    *plVar2 = (long)puVar1;
  }
  *ppuVar7 = (undefined *)0xdead000000000100;
  ppuVar7[1] = (undefined *)0xdead000000000122;
  mutex_unlock(mem_buf_xfer_mem_list_lock);
  if (ppuVar7 + -6 == (undefined **)0x0) {
LAB_00103620:
    _printk(&DAT_00103f93,"mem_buf_relinquish_work",iVar3);
  }
  else {
    mem_buf_cleanup_alloc_req(ppuVar7 + -6,*(undefined4 *)(lVar6 + 0xc));
  }
  uVar4 = mem_buf_construct_relinquish_resp(lVar6);
  if (uVar4 < 0xfffffffffffff001) {
    mem_buf_msgq_send(mem_buf_msgq_hdl,uVar4);
    kfree(uVar4);
  }
  kfree(*plVar5);
  kfree(plVar5);
  return;
}



//------------------------------------------------------------
// init_module @ 00103758 size=188
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = alloc_chrdev_region(&mem_buf_dev_no,0,1,"membuf");
  if ((int)uVar1 < 0) {
    uVar2 = (ulong)uVar1;
  }
  else {
    uVar2 = __class_create(&__this_module,"membuf",&mem_buf_init___key);
    mem_buf_class = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar1 = __platform_driver_register(&mem_buf_msgq_driver,&__this_module);
      if (-1 < (int)uVar1) {
        uVar2 = 0;
        goto LAB_00103800;
      }
      uVar2 = (ulong)uVar1;
      class_destroy(mem_buf_class);
    }
    unregister_chrdev_region(mem_buf_dev_no,1);
  }
LAB_00103800:
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 00103818 size=64
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mem_buf_msgq_driver);
  class_destroy(mem_buf_class);
  unregister_chrdev_region(mem_buf_dev_no,1);
  return;
}



//------------------------------------------------------------
// __kmalloc @ 00107000 size=1
// signature: undefined __kmalloc(void)
// callers: [mem_buf_acl_to_vmid_perms_list]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00107018 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [mem_buf_acl_to_vmid_perms_list, mem_buf_dev_ioctl, mem_buf_retrieve_mem_type_data_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_fd_to_vmid @ 00107020 size=1
// signature: undefined mem_buf_fd_to_vmid(void)
// callers: [mem_buf_acl_to_vmid_perms_list, mem_buf_retrieve_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_fd_to_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00107030 size=1
// signature: undefined kfree(void)
// callers: [mem_buf_acl_to_vmid_perms_list, mem_buf_lend_user, mem_buf_retrieve_user, mem_buf_retrieve, mem_buf_relinquish_work, mem_buf_request_mem, mem_buf_rmt_free_mem, mem_buf_alloc_req_hdlr, mem_buf_relinquish_mem, mem_buf_prep_alloc_data, mem_buf_retrieve_release, mem_buf_free, mem_buf_retrieve_mem_type_data_user, mem_buf_relinquish_hdlr, mem_buf_free_xfer_mem, mem_buf_free_alloc_data, mem_buf_alloc, mem_buf_alloc_req_work, mem_buf_cleanup_alloc_req, __mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00107038 size=1
// signature: undefined ___ratelimit(void)
// callers: [mem_buf_acl_to_vmid_perms_list, mem_buf_retrieve_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00107040 size=1
// signature: undefined _printk(void)
// callers: [mem_buf_acl_to_vmid_perms_list, mem_buf_retrieve_user, mem_buf_alloc_resp_hdlr, mem_buf_relinquish_work, mem_buf_alloc_req_work, __mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00107048 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [mem_buf_acl_to_vmid_perms_list, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mem_buf_alloc_fd, mem_buf_acl_to_vmid_perms_list, mem_buf_lend_user, mem_buf_msgq_alloc, mem_buf_retrieve_user, mem_buf_retrieve, mem_buf_dev_ioctl, mem_buf_rmt_free_mem, mem_buf_relinquish_mem, mem_buf_retrieve_mem_type_data_user, mem_buf_alloc, mem_buf_alloc_req_work, mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00107058 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00107060 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107068 size=1
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
// class_destroy @ 00107070 size=1
// signature: undefined class_destroy(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00107078 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00107080 size=1
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
// cdev_init @ 00107090 size=1
// signature: undefined cdev_init(void)
// callers: [mem_buf_msgq_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00107098 size=1
// signature: undefined cdev_add(void)
// callers: [mem_buf_msgq_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001070a0 size=1
// signature: undefined device_create(void)
// callers: [mem_buf_msgq_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 001070a8 size=1
// signature: undefined cdev_del(void)
// callers: [mem_buf_msgq_probe, mem_buf_msgq_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 001070b0 size=1
// signature: undefined device_destroy(void)
// callers: [mem_buf_msgq_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001070b8 size=1
// signature: undefined __check_object_size(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get @ 001070c0 size=1
// signature: undefined dma_buf_get(void)
// callers: [mem_buf_lend_user, mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_reclaim @ 001070c8 size=1
// signature: undefined mem_buf_reclaim(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 001070d0 size=1
// signature: undefined dma_buf_put(void)
// callers: [mem_buf_lend_user, mem_buf_retrieve_user, mem_buf_dev_ioctl, mem_buf_rmt_free_mem, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// to_mem_buf_vmperm @ 001070e0 size=1
// signature: undefined to_mem_buf_vmperm(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void to_mem_buf_vmperm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_exclusive_owner @ 001070e8 size=1
// signature: undefined mem_buf_dma_buf_exclusive_owner(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_exclusive_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_get_memparcel_hdl @ 001070f0 size=1
// signature: undefined mem_buf_dma_buf_get_memparcel_hdl(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_get_memparcel_hdl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001070f8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [mem_buf_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_lend @ 00107100 size=1
// signature: undefined mem_buf_lend(void)
// callers: [mem_buf_lend_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_lend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_share @ 00107108 size=1
// signature: undefined mem_buf_share(void)
// callers: [mem_buf_lend_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00107120 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mem_buf_retrieve, mem_buf_retrieve_mem_type_data_user, mem_buf_relinquish_hdlr, mem_buf_alloc_req_hdlr, mem_buf_alloc, mem_buf_alloc_req_work, mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmid_perm_list_to_gh_acl @ 00107128 size=1
// signature: undefined mem_buf_vmid_perm_list_to_gh_acl(void)
// callers: [mem_buf_retrieve, mem_buf_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmid_perm_list_to_gh_acl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dup_gh_sgl_desc @ 00107130 size=1
// signature: undefined dup_gh_sgl_desc(void)
// callers: [mem_buf_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dup_gh_sgl_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00107138 size=1
// signature: undefined kstrdup(void)
// callers: [mem_buf_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_map_mem_s2 @ 00107140 size=1
// signature: undefined mem_buf_map_mem_s2(void)
// callers: [mem_buf_retrieve, mem_buf_alloc, mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_map_mem_s2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree @ 00107148 size=1
// signature: undefined kvfree(void)
// callers: [mem_buf_retrieve, mem_buf_free, mem_buf_alloc, mem_buf_alloc_req_work, mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00107150 size=1
// signature: undefined mutex_lock(void)
// callers: [mem_buf_msgq_free, mem_buf_relinquish_work, mem_buf_free, mem_buf_free_xfer_mem, mem_buf_alloc, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00107158 size=1
// signature: undefined __list_add_valid(void)
// callers: [mem_buf_alloc, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00107160 size=1
// signature: undefined mutex_unlock(void)
// callers: [mem_buf_msgq_free, mem_buf_relinquish_work, mem_buf_free, mem_buf_free_xfer_mem, mem_buf_alloc, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 00107188 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_init_txn @ 00107190 size=1
// signature: undefined mem_buf_init_txn(void)
// callers: [mem_buf_request_mem, __mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_init_txn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_construct_alloc_req @ 00107198 size=1
// signature: undefined mem_buf_construct_alloc_req(void)
// callers: [mem_buf_request_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_construct_alloc_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_msgq_send @ 001071a0 size=1
// signature: undefined mem_buf_msgq_send(void)
// callers: [mem_buf_relinquish_work, mem_buf_request_mem, mem_buf_alloc_req_work, __mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_msgq_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_txn_wait @ 001071a8 size=1
// signature: undefined mem_buf_txn_wait(void)
// callers: [mem_buf_request_mem, __mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_destroy_txn @ 001071b0 size=1
// signature: undefined mem_buf_destroy_txn(void)
// callers: [mem_buf_request_mem, __mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_destroy_txn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_unmap_mem_s2 @ 001071b8 size=1
// signature: undefined mem_buf_unmap_mem_s2(void)
// callers: [mem_buf_retrieve, mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_unmap_mem_s2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dup_gh_sgl_desc_to_sgt @ 001071c0 size=1
// signature: undefined dup_gh_sgl_desc_to_sgt(void)
// callers: [mem_buf_retrieve, mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dup_gh_sgl_desc_to_sgt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_assign_mem @ 001071c8 size=1
// signature: undefined mem_buf_assign_mem(void)
// callers: [mem_buf_relinquish_mem, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 001071d0 size=1
// signature: undefined sg_free_table(void)
// callers: [mem_buf_retrieve, mem_buf_rmt_free_mem, mem_buf_relinquish_mem, mem_buf_retrieve_release, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001071d8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mem_buf_relinquish_work, mem_buf_free, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_map_mem_s1 @ 001071e0 size=1
// signature: undefined mem_buf_map_mem_s1(void)
// callers: [mem_buf_retrieve]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_map_mem_s1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_sg_buffer_init @ 001071e8 size=1
// signature: undefined qcom_sg_buffer_init(void)
// callers: [mem_buf_retrieve]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_sg_buffer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_get_sgl_buf_size @ 001071f0 size=1
// signature: undefined mem_buf_get_sgl_buf_size(void)
// callers: [mem_buf_retrieve]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_get_sgl_buf_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc_accept @ 00107200 size=1
// signature: undefined mem_buf_vmperm_alloc_accept(void)
// callers: [mem_buf_retrieve]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_alloc_accept(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_unmap_mem_s1 @ 00107208 size=1
// signature: undefined mem_buf_unmap_mem_s1(void)
// callers: [mem_buf_retrieve]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_unmap_mem_s1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_export @ 00107218 size=1
// signature: undefined mem_buf_dma_buf_export(void)
// callers: [qcom_dma_buf_export]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_export(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_store_dma_buf_fops @ 00107220 size=1
// signature: undefined qcom_store_dma_buf_fops(void)
// callers: [qcom_dma_buf_export]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_store_dma_buf_fops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_fd @ 00107228 size=1
// signature: undefined dma_buf_fd(void)
// callers: [mem_buf_retrieve_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00107230 size=1
// signature: undefined alloc_workqueue(void)
// callers: [mem_buf_msgq_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_msgq_register @ 00107238 size=1
// signature: undefined mem_buf_msgq_register(void)
// callers: [mem_buf_msgq_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_msgq_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00107240 size=1
// signature: undefined _dev_err(void)
// callers: [mem_buf_msgq_alloc, mem_buf_msgq_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00107248 size=1
// signature: undefined destroy_workqueue(void)
// callers: [mem_buf_msgq_alloc, mem_buf_msgq_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_msgq_unregister @ 00107250 size=1
// signature: undefined mem_buf_msgq_unregister(void)
// callers: [mem_buf_msgq_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_msgq_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_construct_relinquish_msg @ 00107258 size=1
// signature: undefined mem_buf_construct_relinquish_msg(void)
// callers: [__mem_buf_relinquish_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_construct_relinquish_msg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncpy_from_user @ 00107270 size=1
// signature: undefined strncpy_from_user(void)
// callers: [mem_buf_retrieve_mem_type_data_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strncpy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 00107278 size=1
// signature: undefined kmemdup(void)
// callers: [mem_buf_relinquish_hdlr, mem_buf_alloc_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00107280 size=1
// signature: undefined queue_work_on(void)
// callers: [mem_buf_relinquish_hdlr, mem_buf_alloc_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_cyclic @ 001072a0 size=1
// signature: undefined idr_alloc_cyclic(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_gh_acl_desc_to_vmid_perm_list @ 001072a8 size=1
// signature: undefined mem_buf_gh_acl_desc_to_vmid_perm_list(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_gh_acl_desc_to_vmid_perm_list(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001072b0 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001072b8 size=1
// signature: undefined strscpy(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_find @ 001072c0 size=1
// signature: undefined dma_heap_find(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_buffer_alloc @ 001072c8 size=1
// signature: undefined dma_heap_buffer_alloc(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_buffer_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_attach @ 001072d0 size=1
// signature: undefined dma_buf_attach(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_map_attachment @ 001072d8 size=1
// signature: undefined dma_buf_map_attachment(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_map_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table @ 001072e0 size=1
// signature: undefined sg_alloc_table(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_alloc @ 001072e8 size=1
// signature: undefined cma_alloc(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvmalloc_node @ 001072f8 size=1
// signature: undefined kvmalloc_node(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvmalloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 00107300 size=1
// signature: undefined __alloc_pages(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// split_page @ 00107308 size=1
// signature: undefined split_page(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void split_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table_from_pages_segment @ 00107310 size=1
// signature: undefined sg_alloc_table_from_pages_segment(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table_from_pages_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00107318 size=1
// signature: undefined idr_remove(void)
// callers: [mem_buf_free_xfer_mem, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 00107320 size=1
// signature: undefined __free_pages(void)
// callers: [mem_buf_rmt_free_mem, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_detach @ 00107328 size=1
// signature: undefined dma_buf_detach(void)
// callers: [mem_buf_rmt_free_mem, mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_construct_alloc_resp @ 00107330 size=1
// signature: undefined mem_buf_construct_alloc_resp(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_construct_alloc_resp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00107340 size=1
// signature: undefined fortify_panic(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __traceiter_receive_alloc_req @ 00107348 size=1
// signature: undefined __traceiter_receive_alloc_req(void)
// callers: [mem_buf_alloc_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __traceiter_receive_alloc_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_unassign_mem @ 00107358 size=1
// signature: undefined mem_buf_unassign_mem(void)
// callers: [mem_buf_cleanup_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_unassign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_unmap_attachment @ 00107360 size=1
// signature: undefined dma_buf_unmap_attachment(void)
// callers: [mem_buf_rmt_free_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_delayed_fput @ 00107368 size=1
// signature: undefined flush_delayed_fput(void)
// callers: [mem_buf_rmt_free_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_delayed_fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_release @ 00107370 size=1
// signature: undefined cma_release(void)
// callers: [mem_buf_rmt_free_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_start @ 00107378 size=1
// signature: undefined __sg_page_iter_start(void)
// callers: [mem_buf_rmt_free_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_next @ 00107380 size=1
// signature: undefined __sg_page_iter_next(void)
// callers: [mem_buf_rmt_free_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_construct_relinquish_resp @ 00107390 size=1
// signature: undefined mem_buf_construct_relinquish_resp(void)
// callers: [mem_buf_relinquish_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_construct_relinquish_resp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



