// Decompiled by Ghidra 12.2
// Program: smmu_proxy_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// smmu_proxy_get_csf_version @ 00100364 size=480
// signature: undefined smmu_proxy_get_csf_version(void)
// callers: [smmu_proxy_map, sender_probe_handler, smmu_proxy_dev_ioctl]
//------------------------------------------------------------

int smmu_proxy_get_csf_version(int *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  code *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  int local_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  code *local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_88 = (code *)0x0;
  uStack_80 = 0;
  if (cached_csf_version_0 == 0) {
    iVar5 = get_client_env_object(&local_88);
    if (iVar5 == 0) {
      local_58 = (code *)0x0;
      uStack_50 = 0;
      local_78 = CONCAT44(local_78._4_4_,0x11b);
      uStack_60 = 4;
      local_68 = &local_78;
      if (*(int *)(local_88 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x822a,0x10040c);
        (*pcVar4)();
      }
      iVar5 = (*local_88)(uStack_80,0,&local_68,0x1001);
      uVar3 = uStack_50;
      pcVar4 = local_58;
      if (iVar5 == 0) {
        local_70 = 0;
        local_78 = 0;
        uStack_60 = 0xc;
        if (*(int *)(local_58 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8238,0x100450);
          local_68 = &local_78;
          (*pcVar4)();
        }
        local_68 = &local_78;
        iVar5 = (*local_58)(uStack_50,1,&local_68,0x10);
        *(undefined8 *)param_1 = local_78;
        param_1[2] = local_70;
        if (*(int *)(pcVar4 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8238,0x100490);
          (*pcVar4)();
        }
        (*pcVar4)(uVar3,0xffff,0,0);
        if (*(int *)(local_88 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1004bc);
          (*pcVar4)();
        }
        (*local_88)(uStack_80,0xffff,0,0);
        cached_csf_version_1 = param_1[1];
        cached_csf_version_2 = param_1[2];
        cached_csf_version_0 = *param_1;
        goto LAB_001004dc;
      }
      puVar6 = &DAT_0010128d;
    }
    else {
      puVar6 = &DAT_00101266;
    }
    _printk(puVar6,"smmu_proxy_get_csf_version",iVar5);
  }
  else {
    *param_1 = cached_csf_version_0;
    iVar2 = cached_csf_version_2;
    iVar5 = 0;
    param_1[1] = cached_csf_version_1;
    param_1[2] = iVar2;
  }
LAB_001004dc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// smmu_proxy_create_dev @ 00100548 size=272
// signature: undefined smmu_proxy_create_dev(void)
// callers: [sender_probe_handler]
//------------------------------------------------------------

ulong smmu_proxy_create_dev(undefined8 param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = alloc_chrdev_region(&smmu_proxy_dev_no,0,1,"qti-smmu-proxy");
  if ((int)uVar1 < 0) {
    uVar2 = (ulong)uVar1;
  }
  else {
    uVar2 = __class_create(&__this_module,"qti-smmu-proxy",&smmu_proxy_create_dev___key);
    smmu_proxy_class = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      cdev_init(smmu_proxy_char_dev,param_1);
      uVar1 = cdev_add(smmu_proxy_char_dev,smmu_proxy_dev_no,1);
      if ((int)uVar1 < 0) {
        uVar2 = (ulong)uVar1;
      }
      else {
        uVar2 = device_create(smmu_proxy_class,0,smmu_proxy_dev_no,0,"qti-smmu-proxy");
        if (uVar2 < 0xfffffffffffff001) {
          uVar2 = 0;
          goto LAB_00100638;
        }
        cdev_del(smmu_proxy_char_dev);
      }
      class_destroy(smmu_proxy_class);
    }
    unregister_chrdev_region(smmu_proxy_dev_no,1);
  }
LAB_00100638:
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// smmu_proxy_unmap @ 0010065c size=396
// signature: undefined smmu_proxy_unmap(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int smmu_proxy_unmap(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined *puVar6;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  mutex_lock(&sender_mutex);
  puVar5 = (undefined8 *)kmalloc_trace(_mem_buf_dma_buf_exclusive_owner,0xdc0,0xf0);
  if (puVar5 == (undefined8 *)0x0) {
    _printk(&DAT_00101040,"smmu_proxy_unmap");
    iVar3 = -0xc;
    goto LAB_001007a8;
  }
  iVar3 = mem_buf_dma_buf_get_memparcel_hdl(param_1,puVar5 + 1);
  uVar2 = msgq_hdl;
  if (iVar3 == 0) {
    *puVar5 = 0xc00000002;
    iVar3 = gh_msgq_send(uVar2,puVar5,0xc,0);
    if (iVar3 < 0) {
      puVar6 = &DAT_0010108f;
      goto LAB_00100790;
    }
    iVar3 = gh_msgq_recv(msgq_hdl,puVar5,0xc,&local_40,0);
    if (iVar3 < 0) {
      iVar4 = ___ratelimit(smmu_proxy_unmap__rs,"smmu_proxy_unmap");
      if (iVar4 != 0) {
        puVar6 = &DAT_0010121c;
        goto LAB_00100790;
      }
    }
    else {
      iVar4 = *(int *)(puVar5 + 1);
      if (iVar4 != 0) {
        _printk(&DAT_00101151,"smmu_proxy_unmap",iVar4);
        iVar3 = iVar4;
      }
    }
  }
  else {
    puVar6 = &DAT_00101062;
LAB_00100790:
    _printk(puVar6,"smmu_proxy_unmap",iVar3);
  }
  kfree(puVar5);
LAB_001007a8:
  mutex_unlock(&sender_mutex);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// smmu_proxy_map @ 001007ec size=748
// signature: undefined smmu_proxy_map(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int smmu_proxy_map(long param_1,long *param_2,undefined8 param_3)

{
  int *piVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  ulong uVar8;
  undefined *puVar9;
  undefined8 local_a8;
  undefined8 *local_a0;
  undefined8 *puStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_70 = 0;
  local_80 = 0;
  local_78 = 0;
  local_68 = 0x600000006;
  local_60 = 0x310000002d;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = (undefined8 *)0x0;
  puStack_98 = (undefined8 *)0x0;
  local_a8 = 0;
  iVar5 = smmu_proxy_get_csf_version(&local_80);
  if (iVar5 != 0) goto LAB_00100a9c;
  iVar4 = (int)local_78;
  iVar6 = 1;
  if ((int)local_78 == 1) {
    iVar6 = 2;
  }
  mutex_lock(&sender_mutex);
  puVar7 = (undefined4 *)kmalloc_trace(_mem_buf_dma_buf_exclusive_owner,0xdc0,0xf0);
  if (puVar7 == (undefined4 *)0x0) {
    iVar5 = -0xc;
  }
  else {
    uVar8 = mem_buf_dma_buf_exclusive_owner(param_3);
    if ((uVar8 & 1) == 0) {
LAB_001008bc:
      puVar7[4] = iVar6;
      *(short *)(puVar7 + 5) = (short)local_60;
      *(char *)((long)puVar7 + 0x16) = (char)local_68;
      if (iVar4 == 1) {
        *(short *)(puVar7 + 6) = (short)((ulong)local_60 >> 0x20);
        *(char *)((long)puVar7 + 0x1a) = (char)((ulong)local_68 >> 0x20);
      }
      piVar1 = puVar7 + 2;
      iVar5 = mem_buf_dma_buf_get_memparcel_hdl(param_3,piVar1);
      if (iVar5 != 0) {
        puVar9 = &DAT_00101062;
        goto LAB_00100a78;
      }
      iVar5 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),"qti,smmu-proxy-cb-id",puVar7 + 3,1,0);
      uVar3 = msgq_hdl;
      if (iVar5 < 0) {
        _dev_err(param_1,"%s: Err reading \'qti,smmu-proxy-cb-id\' rc: %d\n","smmu_proxy_map",iVar5)
        ;
        goto LAB_00100a88;
      }
      iVar5 = iVar6 * 4 + 0x14;
      *puVar7 = 0;
      puVar7[1] = iVar5;
      iVar5 = gh_msgq_send(uVar3,puVar7,iVar5,0);
      if (iVar5 < 0) {
        puVar9 = &DAT_0010108f;
        goto LAB_00100a78;
      }
      iVar5 = gh_msgq_recv(msgq_hdl,puVar7,0x1c,&local_70,0);
      if (-1 < iVar5) {
        iVar5 = *piVar1;
        if (iVar5 == 0) {
          iVar5 = mem_buf_dma_buf_set_destructor(param_3,smmu_proxy_unmap,param_3);
          if (iVar5 == 0) {
            *(undefined8 *)(*param_2 + 0x10) = *(undefined8 *)(puVar7 + 3);
            *(int *)(*param_2 + 0x18) = (int)*(undefined8 *)(puVar7 + 5);
            *(undefined4 *)(param_2 + 1) = 1;
          }
          else {
            iVar6 = ___ratelimit(smmu_proxy_map__rs_10,"smmu_proxy_map");
            if (iVar6 != 0) {
              puVar9 = &DAT_001010e5;
              goto LAB_00100a78;
            }
          }
          goto LAB_00100a88;
        }
        iVar6 = ___ratelimit(smmu_proxy_map__rs_8,"smmu_proxy_map");
        if (iVar6 == 0) goto LAB_00100a88;
        puVar9 = &DAT_00101125;
        iVar6 = *piVar1;
        goto LAB_00100a84;
      }
      iVar6 = ___ratelimit(smmu_proxy_map__rs,"smmu_proxy_map");
      if (iVar6 != 0) {
        puVar9 = &DAT_0010121c;
        goto LAB_00100a78;
      }
    }
    else {
      local_a0 = &local_60;
      puStack_98 = &local_68;
      local_a8 = CONCAT44(local_a8._4_4_,iVar6);
      iVar5 = mem_buf_lend(param_3,&local_a8);
      if (iVar5 == 0) goto LAB_001008bc;
      puVar9 = &DAT_001012b7;
LAB_00100a78:
      iVar6 = iVar5;
LAB_00100a84:
      _printk(puVar9,"smmu_proxy_map",iVar6);
    }
LAB_00100a88:
    kfree(puVar7);
  }
  mutex_unlock(&sender_mutex);
LAB_00100a9c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// smmu_proxy_unmap_nop @ 00100adc size=4
// signature: undefined smmu_proxy_unmap_nop(void)
// callers: []
//------------------------------------------------------------

void smmu_proxy_unmap_nop(void)

{
  return;
}



//------------------------------------------------------------
// sender_probe_handler @ 00100ae4 size=364
// signature: undefined sender_probe_handler(void)
// callers: []
//------------------------------------------------------------

ulong sender_probe_handler(void)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  undefined *puVar6;
  code *pcVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  uVar3 = gh_msgq_register(10);
  msgq_hdl = uVar3;
  if (0xfffffffffffff000 < uVar3) {
    _printk(&DAT_00101316,"sender_probe_handler",uVar3);
    goto LAB_00100b88;
  }
  uVar2 = smmu_proxy_get_csf_version(&local_38);
  if (uVar2 == 0) {
    if (((int)local_38 == 2) && (local_38._4_4_ == 0)) {
      pcVar4 = (code *)0x0;
      pcVar7 = (code *)0x0;
LAB_00100b68:
      uVar5 = qti_smmu_proxy_register_callbacks(pcVar4,pcVar7);
      uVar3 = uVar5 & 0xffffffff;
      if ((int)uVar5 != 0) {
        puVar6 = &DAT_001010b4;
        goto LAB_00100bec;
      }
      uVar5 = smmu_proxy_create_dev(smmu_proxy_dev_fops);
      uVar3 = uVar5 & 0xffffffff;
      if ((int)uVar5 == 0) goto LAB_00100b88;
      _printk(&DAT_00101194,"sender_probe_handler",uVar3);
      qti_smmu_proxy_register_callbacks(0,0);
    }
    else {
      if (((int)local_38 == 2) && (local_38._4_4_ == 5)) {
        pcVar4 = smmu_proxy_map;
        pcVar7 = smmu_proxy_unmap_nop;
        goto LAB_00100b68;
      }
      _printk(&DAT_00101244,"sender_probe_handler");
      uVar3 = 0;
    }
  }
  else {
    uVar3 = (ulong)uVar2;
    puVar6 = &DAT_001011f4;
LAB_00100bec:
    _printk(puVar6,"sender_probe_handler",uVar3);
  }
  gh_msgq_unregister(msgq_hdl);
LAB_00100b88:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// smmu_proxy_dev_ioctl @ 00100c54 size=668
// signature: undefined smmu_proxy_dev_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void smmu_proxy_dev_ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  uVar1 = param_2 >> 0x10 & 0x3fff;
  uVar8 = (ulong)uVar1;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  if (uVar1 < 0x11) {
    __check_object_size(&local_58,uVar8,0);
    puVar2 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar2 + 0x46) >> 5 & 1) != 0) ||
       (uVar7 = param_3, ((uint)*puVar2 >> 0x1a & 1) != 0)) {
      uVar7 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar7 <= 0x8000000000 - uVar8) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar7 = daif;
        if ((uVar7 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr1_el1 = puVar2[1] & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar2[1];
        InstructionSynchronizationBarrier();
        daif = uVar7;
      }
      uVar8 = __arch_copy_from_user(&local_58,param_3 & 0xff7fffffffffffff,uVar8);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar7 = daif;
        if ((uVar7 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar7;
      }
    }
    if (uVar8 == 0) {
      if ((param_2 >> 0x1e & 1) == 0) {
        local_58 = 0;
        uStack_50 = 0;
      }
      if (param_2 == 0x80105500) {
        iVar4 = smmu_proxy_get_csf_version(&local_58);
        if (iVar4 == 0) {
          __check_object_size(&local_58,0x10,1);
          if (((*(byte *)((long)puVar2 + 0x46) >> 5 & 1) != 0) ||
             (uVar8 = param_3, ((uint)*puVar2 >> 0x1a & 1) != 0)) {
            uVar8 = param_3 & (long)(param_3 << 8) >> 8;
          }
          lVar6 = 0x10;
          if (uVar8 < 0x7ffffffff1) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar8 = daif;
              if ((uVar8 & 0x80) == 0) {
                uVar7 = daif;
                daif = uVar7 | 0xc0;
              }
              uVar7 = ttbr1_el1;
              ttbr1_el1 = puVar2[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar2[1];
              InstructionSynchronizationBarrier();
              daif = uVar8;
            }
            lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_58,0x10);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar8 = daif;
              if ((uVar8 & 0x80) == 0) {
                uVar7 = daif;
                daif = uVar7 | 0xc0;
              }
              uVar7 = ttbr1_el1;
              ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar7 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar8;
            }
          }
          lVar5 = 0;
          if (lVar6 != 0) {
            lVar5 = -0xe;
          }
        }
        else {
          lVar5 = (long)iVar4;
        }
      }
      else {
        lVar5 = -0x19;
      }
    }
    else {
      lVar5 = -0xe;
    }
  }
  else {
    lVar5 = -0x16;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101354 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&smmu_proxy_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// get_client_env_object @ 00103000 size=1
// signature: undefined get_client_env_object(void)
// callers: [smmu_proxy_get_csf_version]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_client_env_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103008 size=1
// signature: undefined _printk(void)
// callers: [smmu_proxy_get_csf_version, smmu_proxy_unmap, smmu_proxy_map, sender_probe_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [smmu_proxy_get_csf_version, smmu_proxy_unmap, smmu_proxy_map, sender_probe_handler, smmu_proxy_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00103018 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00103020 size=1
// signature: undefined __class_create(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00103028 size=1
// signature: undefined cdev_init(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00103030 size=1
// signature: undefined cdev_add(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00103038 size=1
// signature: undefined device_create(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00103040 size=1
// signature: undefined cdev_del(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00103048 size=1
// signature: undefined class_destroy(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00103050 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [smmu_proxy_create_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103058 size=1
// signature: undefined mutex_lock(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_get_memparcel_hdl @ 00103070 size=1
// signature: undefined mem_buf_dma_buf_get_memparcel_hdl(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_get_memparcel_hdl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_send @ 00103078 size=1
// signature: undefined gh_msgq_send(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_recv @ 00103080 size=1
// signature: undefined gh_msgq_recv(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_recv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00103088 size=1
// signature: undefined ___ratelimit(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103090 size=1
// signature: undefined kfree(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103098 size=1
// signature: undefined mutex_unlock(void)
// callers: [smmu_proxy_unmap, smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_exclusive_owner @ 001030a0 size=1
// signature: undefined mem_buf_dma_buf_exclusive_owner(void)
// callers: [smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_exclusive_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_lend @ 001030a8 size=1
// signature: undefined mem_buf_lend(void)
// callers: [smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_lend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001030b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_set_destructor @ 001030b8 size=1
// signature: undefined mem_buf_dma_buf_set_destructor(void)
// callers: [smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_set_destructor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030c0 size=1
// signature: undefined _dev_err(void)
// callers: [smmu_proxy_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001030c8 size=1
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
// gh_msgq_register @ 001030d0 size=1
// signature: undefined gh_msgq_register(void)
// callers: [sender_probe_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_smmu_proxy_register_callbacks @ 001030d8 size=1
// signature: undefined qti_smmu_proxy_register_callbacks(void)
// callers: [sender_probe_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_smmu_proxy_register_callbacks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_msgq_unregister @ 001030e0 size=1
// signature: undefined gh_msgq_unregister(void)
// callers: [sender_probe_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_msgq_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001030e8 size=1
// signature: undefined __check_object_size(void)
// callers: [smmu_proxy_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00103100 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [smmu_proxy_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00103108 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [smmu_proxy_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



