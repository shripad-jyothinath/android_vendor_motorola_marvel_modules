// Decompiled by Ghidra 12.2
// Program: mmi_annotate.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_annotate @ 001003ec size=320
// signature: undefined mmi_annotate(void)
// callers: [mmi_annotate_mem_write, mmi_annotate_write, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 mmi_annotate(char *param_1)

{
  long lVar1;
  uint uVar2;
  size_t __n;
  undefined1 auStack_2f8 [128];
  char acStack_238 [512];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  memset(acStack_238,0,0x200);
  uVar2 = vsnprintf(acStack_238,0x200,param_1,auStack_2f8 + 0x80);
  mutex_lock(&mem_lock);
  if (DAT_00101270 != 0) {
    __n = (size_t)(int)uVar2;
    if (DAT_00101268 + __n < (ulong)mem_data) {
      if (0x200 < uVar2) {
        fortify_panic("memcpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      memcpy((void *)(DAT_00101270 + DAT_00101268),acStack_238,__n);
      DAT_00101268 = DAT_00101268 + __n;
    }
  }
  mutex_unlock(&mem_lock);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// mmi_annotate_persist @ 00100530 size=340
// signature: undefined mmi_annotate_persist(void)
// callers: [mmi_annotate_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 mmi_annotate_persist(char *param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  uint in_w6;
  size_t __n;
  undefined1 auStack_2f8 [128];
  char acStack_238 [512];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  memset(acStack_238,0,0x200);
  uVar2 = vsnprintf(acStack_238,0x200,param_1,auStack_2f8 + 0x80);
  if (persist_unsupported == 0) {
    mutex_lock(persist_lock);
    lVar1 = persist_data;
    if ((persist_data != 0) &&
       (__n = (size_t)(int)uVar2,
       *(long *)(persist_data + 0x10) + __n < *(ulong *)(persist_data + 8))) {
      if (0x200 < uVar2) {
        fortify_panic("memcpy");
        if ((in_w6 >> 0x16 & 1) == 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        uVar3 = __platform_driver_register(&mmi_annotate_driver,&__this_module);
        return uVar3;
      }
      memcpy((void *)(persist_data + *(long *)(persist_data + 0x10) + 0x18),acStack_238,__n);
      *(size_t *)(lVar1 + 0x10) = *(long *)(lVar1 + 0x10) + __n;
    }
    mutex_unlock(persist_lock);
  }
  else {
    mmi_annotate(&DAT_00101307,acStack_238);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100688 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_annotate_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001006b8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_annotate_driver);
  return;
}



//------------------------------------------------------------
// mmi_annotate_probe @ 001006e0 size=968
// signature: undefined mmi_annotate_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int mmi_annotate_probe(long param_1)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  char *pcVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  int *piVar10;
  long local_138;
  long lStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulong local_d0;
  undefined8 local_c8;
  void *local_c0;
  long local_b8;
  ulong local_b0;
  long local_a8 [11];
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_a8[10] = *(long *)(lVar5 + 0x638);
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_138 = 0;
  lStack_130 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_c8 = 0;
  local_c0 = (void *)0x0;
  local_d8 = 0;
  local_d0 = 0;
  plVar4 = (long *)devm_kmalloc(lVar1,0x10,0xdc0);
  if (plVar4 != (long *)0x0) {
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
    iVar3 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2f8),"memory-region",0,0,0,local_a8);
    if ((iVar3 != 0) || (local_a8[0] == 0)) {
      _dev_err(lVar1,"No %s specified\n","memory-region");
LAB_0010084c:
      iVar3 = 0;
      goto LAB_00100750;
    }
    iVar3 = of_address_to_resource(local_a8[0],0,&local_138);
    lVar5 = local_138;
    if (iVar3 != 0) {
      _dev_err(lVar1,"No memory address assigned to the region\n");
      goto LAB_00100750;
    }
    lVar8 = lStack_130 - local_138;
    plVar7 = (long *)(lVar8 + 1);
    *plVar4 = local_138;
    plVar4[1] = (long)plVar7;
    _dev_info(lVar1,"size %zx",plVar7);
    _dev_info(lVar1,"addr %lx",lVar5);
    if (plVar7 < (long *)0x18) {
      pcVar6 = "Mem size too small %zx/%zd\n";
      plVar4 = plVar7;
      plVar7 = (long *)0x18;
    }
    else {
      persist_data = (int *)mmi_annotate_ram_vmap(lVar5,plVar7);
      if (persist_data != (int *)0x0) {
        iVar3 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"mem-size",&mem_data,1,0);
        if (iVar3 < 0) {
          pcVar6 = "mem-size defaulting to %d";
          mem_data = 0x1000;
        }
        else {
          pcVar6 = "mem-size %x";
        }
        _dev_info(lVar1,pcVar6,mem_data);
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"persist_unsupported",0);
        persist_unsupported = (uint)(lVar5 != 0);
        if (lVar5 != 0) {
          _dev_info(lVar1,"persist unsupported : 1");
        }
        DAT_00101270 = (void *)__kmalloc(mem_data,0xdc0);
        piVar2 = persist_data;
        if (DAT_00101270 == (void *)0x0) {
          _dev_err(lVar1,"Cannot allocate buffer of size %x\n",mem_data);
          goto LAB_0010074c;
        }
        uVar9 = lVar8 - 0x17;
        iVar3 = *persist_data;
        *(ulong *)(persist_data + 2) = uVar9;
        piVar10 = persist_data;
        if ((iVar3 == -0x5432edcc) && (*(size_t *)(piVar2 + 4) <= uVar9)) {
          memcpy(DAT_00101270,persist_data + 6,*(size_t *)(piVar2 + 4));
          DAT_00101268 = DAT_00101268 + *(long *)(piVar10 + 4);
        }
        else {
          *piVar2 = -0x5432edcc;
          piVar10 = piVar2;
        }
        piVar10[4] = 0;
        piVar10[5] = 0;
        procfs_file = proc_create("driver/mmi_annotate",0x124,0,mmi_annotate_operations);
        mem_procfs_file = proc_create("driver/mmi_annotate_mem",0x1a0,0,mmi_annotate_mem_operations)
        ;
        local_d0 = local_d0 & 0xffffffffffffff00;
        local_d8 = 0x455441544f4e4e41;
        if (persist_unsupported == 0) {
          local_b8 = *plVar4;
          local_b0 = plVar4[1];
          local_c0 = (void *)(local_b8 - _memstart_addr | 0xffffff8000000000);
        }
        else {
          lVar1 = ((long)DAT_00101270 << 8) >> 8;
          uVar9 = lVar1 + 0x8000000000;
          local_b8 = uVar9 + _memstart_addr;
          if (uVar9 >> 0x26 != 0) {
            local_b8 = lVar1 - _kimage_voffset;
          }
          local_b0 = (ulong)mem_data;
          local_c0 = DAT_00101270;
        }
        iVar3 = msm_minidump_add_region(&local_d8);
        if (iVar3 < 0) {
          _printk(&DAT_0010146c);
        }
        goto LAB_0010084c;
      }
      pcVar6 = "Cannot remap buffer %pa size %zx\n";
    }
    _dev_err(lVar1,pcVar6,plVar4,plVar7);
  }
LAB_0010074c:
  iVar3 = -0xc;
LAB_00100750:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// mmi_annotate_remove @ 00100aac size=100
// signature: undefined mmi_annotate_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_annotate_remove(void)

{
  if (procfs_file != 0) {
    remove_proc_entry("driver/mmi_annotate",0);
  }
  if (mem_procfs_file != 0) {
    remove_proc_entry("driver/mmi_annotate_mem",0);
  }
  if (DAT_00101270 != 0) {
    kfree();
  }
  return 0;
}



//------------------------------------------------------------
// mmi_annotate_ram_vmap @ 00100b10 size=360
// signature: undefined mmi_annotate_ram_vmap(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long mmi_annotate_ram_vmap(ulong param_1,long param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined *puVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  
  uVar8 = param_2 + (param_1 & 0xfff) + 0xfff;
  uVar13 = uVar8 >> 0xc;
  lVar3 = __kmalloc(uVar8 >> 9 & 0x7fffffff8,0xcc0);
  if (lVar3 == 0) {
    puVar4 = &DAT_001013a6;
    goto LAB_00100c60;
  }
  if ((int)uVar13 != 0) {
    uVar6 = uVar8 >> 0xc & 0xffffffff;
    if (uVar6 < 2) {
      lVar10 = 0;
    }
    else {
      uVar11 = uVar8 >> 0xc & 1;
      lVar10 = uVar6 - uVar11;
      plVar9 = (long *)(lVar3 + 8);
      lVar12 = (_memstart_addr >> 0xc) * -0x40 + -0x200000000;
      lVar7 = lVar10;
      uVar8 = param_1 >> 0xc;
      do {
        uVar1 = uVar8 + 1;
        uVar5 = uVar8 & 0xfffffffffffff;
        uVar8 = uVar8 + 2;
        lVar7 = lVar7 + -2;
        plVar9[-1] = lVar12 + uVar5 * 0x40;
        *plVar9 = lVar12 + (uVar1 & 0xfffffffffffff) * 0x40;
        plVar9 = plVar9 + 2;
      } while (lVar7 != 0);
      if (uVar11 == 0) goto LAB_00100bf4;
    }
    uVar8 = lVar10 + (param_1 >> 0xc);
    lVar7 = uVar6 - lVar10;
    lVar12 = _memstart_addr >> 0xc;
    plVar9 = (long *)(lVar3 + lVar10 * 8);
    do {
      uVar6 = uVar8 & 0xfffffffffffff;
      uVar8 = uVar8 + 1;
      lVar7 = lVar7 + -1;
      *plVar9 = lVar12 * -0x40 + -0x200000000 + uVar6 * 0x40;
      plVar9 = plVar9 + 1;
    } while (lVar7 != 0);
  }
LAB_00100bf4:
  uVar2 = 0x68000000000703;
  if (arm64_use_ng_mappings != '\0') {
    uVar2 = 0x68000000000f03;
  }
  lVar7 = vmap(lVar3,uVar13 & 0xffffffff,4,uVar2);
  kfree(lVar3);
  if (lVar7 != 0) {
    return lVar7 + (param_1 & 0xfff);
  }
  puVar4 = &DAT_0010132f;
LAB_00100c60:
  _printk(puVar4,"mmi_annotate_ram_vmap",uVar13 & 0xffffffff);
  return 0;
}



//------------------------------------------------------------
// mmi_annotate_open @ 00100c7c size=48
// signature: undefined mmi_annotate_open(void)
// callers: []
//------------------------------------------------------------

void mmi_annotate_open(long param_1,undefined8 param_2)

{
  single_open(param_2,mmi_annotate_seq_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// mmi_annotate_write @ 00100cb0 size=424
// signature: undefined mmi_annotate_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mmi_annotate_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined1 auStack_438 [1024];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = param_3;
  if (0x3fe < param_3) {
    uVar3 = 0x3ff;
  }
  memset(auStack_438,0,0x400);
  __check_object_size(auStack_438,uVar3,0);
  puVar4 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar5 <= 0x8000000000 - uVar3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar2 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    uVar3 = __arch_copy_from_user(puVar4,auStack_438,param_2 & 0xff7fffffffffffff,uVar3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
  }
  if (uVar3 == 0) {
    if (persist_unsupported == 0) {
      mmi_annotate_persist(&DAT_00101307,auStack_438);
    }
    else {
      mmi_annotate(&DAT_00101307,auStack_438);
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// mmi_annotate_seq_show @ 00100e74 size=124
// signature: undefined mmi_annotate_seq_show(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_annotate_seq_show(undefined8 param_1)

{
  mutex_lock(&mem_lock);
  if ((DAT_00101270 == 0) || (DAT_00101268 == 0)) {
    seq_printf(param_1,"No annotated data.\n");
  }
  else {
    seq_printf(param_1,&DAT_00101307);
  }
  mutex_unlock(&mem_lock);
  return 0;
}



//------------------------------------------------------------
// mmi_annotate_mem_write @ 00100ef4 size=392
// signature: undefined mmi_annotate_mem_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mmi_annotate_mem_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined1 auStack_438 [1024];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = param_3;
  if (0x3fe < param_3) {
    uVar3 = 0x3ff;
  }
  memset(auStack_438,0,0x400);
  __check_object_size(auStack_438,uVar3,0);
  puVar4 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar5 <= 0x8000000000 - uVar3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar2 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    uVar3 = __arch_copy_from_user(puVar4,auStack_438,param_2 & 0xff7fffffffffffff,uVar3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
  }
  if (uVar3 == 0) {
    mmi_annotate(&DAT_00101307,auStack_438);
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// memset @ 00103000 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [mmi_annotate_mem_write, mmi_annotate_write, mmi_annotate, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vsnprintf @ 00103008 size=1
// signature: int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
// callers: [mmi_annotate, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103010 size=1
// signature: undefined mutex_lock(void)
// callers: [mmi_annotate, mmi_annotate_seq_show, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103018 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mmi_annotate_probe, mmi_annotate, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103020 size=1
// signature: undefined mutex_unlock(void)
// callers: [mmi_annotate, mmi_annotate_seq_show, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mmi_annotate_mem_write, mmi_annotate_probe, mmi_annotate_write, mmi_annotate, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00103030 size=1
// signature: undefined fortify_panic(void)
// callers: [mmi_annotate, mmi_annotate_persist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103038 size=1
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
// platform_driver_unregister @ 00103040 size=1
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
// devm_kmalloc @ 00103048 size=1
// signature: undefined devm_kmalloc(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103050 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00103058 size=1
// signature: undefined of_address_to_resource(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103060 size=1
// signature: undefined _dev_info(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103068 size=1
// signature: undefined _dev_err(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103078 size=1
// signature: undefined of_find_property(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103080 size=1
// signature: undefined __kmalloc(void)
// callers: [mmi_annotate_probe, mmi_annotate_ram_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create @ 00103088 size=1
// signature: undefined proc_create(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 001030a0 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [mmi_annotate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030a8 size=1
// signature: undefined _printk(void)
// callers: [mmi_annotate_probe, mmi_annotate_ram_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 001030b0 size=1
// signature: undefined remove_proc_entry(void)
// callers: [mmi_annotate_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001030b8 size=1
// signature: undefined kfree(void)
// callers: [mmi_annotate_remove, mmi_annotate_ram_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmap @ 001030c8 size=1
// signature: undefined vmap(void)
// callers: [mmi_annotate_ram_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001030d0 size=1
// signature: undefined single_open(void)
// callers: [mmi_annotate_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001030d8 size=1
// signature: undefined __check_object_size(void)
// callers: [mmi_annotate_mem_write, mmi_annotate_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001030f0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [mmi_annotate_mem_write, mmi_annotate_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00103100 size=1
// signature: undefined seq_printf(void)
// callers: [mmi_annotate_seq_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



