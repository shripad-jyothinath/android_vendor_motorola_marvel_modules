// Decompiled by Ghidra 12.2
// Program: qcom_ramdump.ko
// Image base: 00100000

//------------------------------------------------------------
// dump_enabled @ 00100244 size=20
// signature: undefined dump_enabled(void)
// callers: []
//------------------------------------------------------------

bool dump_enabled(void)

{
  return enable_dump_collection != 0;
}



//------------------------------------------------------------
// qcom_dump @ 0010025c size=460
// signature: undefined qcom_dump(void)
// callers: []
//------------------------------------------------------------

void qcom_dump(long *param_1,undefined8 param_2)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long local_80 [6];
  
  lVar5 = sp_el0;
  local_80[5] = *(long *)(lVar5 + 0x638);
  if ((param_1 == (long *)0x0) || (plVar6 = (long *)*param_1, plVar6 == param_1)) {
    uVar2 = 0xffffffea;
  }
  else {
    lVar5 = 0;
    do {
      _printk(&DAT_001010cb,plVar6[4]);
      plVar1 = plVar6 + 4;
      plVar6 = (long *)*plVar6;
      lVar5 = *plVar1 + lVar5;
    } while (plVar6 != param_1);
    lVar3 = vmalloc(lVar5);
    if (lVar3 == 0) {
      uVar2 = 0xfffffff4;
    }
    else {
      plVar6 = (long *)*param_1;
      if (plVar6 != param_1) {
        lVar7 = 0;
        do {
          if (plVar6[3] == 0) {
            lVar4 = devm_ioremap(param_2,plVar6[2],plVar6[4]);
            if (lVar4 == 0) {
              _dev_err(param_2,"invalid coredump segment (%pad, %zu)\n",plVar6 + 2,plVar6[4]);
              memset((void *)(lVar3 + lVar7),0xff,plVar6[4]);
            }
            else {
              __memcpy_fromio(lVar3 + lVar7,lVar4,plVar6[4]);
            }
          }
          else {
            memcpy((void *)(lVar3 + lVar7),(void *)plVar6[3],plVar6[4]);
          }
          plVar1 = plVar6 + 4;
          plVar6 = (long *)*plVar6;
          lVar7 = *plVar1 + lVar7;
        } while (plVar6 != param_1);
      }
      local_80[3] = 0;
      local_80[4] = 0;
      local_80[1] = 0;
      local_80[2] = 0;
      local_80[0] = lVar3;
      __init_swait_queue_head(local_80 + 2,"&x->wait",&init_completion___key);
      dev_coredumpm(param_2,0,local_80,lVar5,0xcc0,qcom_devcd_readv,qcom_devcd_freev);
      wait_for_completion(local_80 + 1);
      uVar2 = completion_done(local_80 + 1);
      uVar2 = (uVar2 ^ 0xffffffff) & 1;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_80[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_elf_dump @ 0010042c size=1632
// signature: undefined qcom_elf_dump(void)
// callers: [qcom_fw_elf_dump]
//------------------------------------------------------------

void qcom_elf_dump(long *param_1,undefined8 param_2,char param_3)

{
  long *plVar1;
  ulong uVar2;
  undefined4 *__s;
  size_t __n;
  code *pcVar3;
  bool bVar4;
  uint uVar5;
  undefined4 *__s_00;
  long lVar6;
  size_t __n_00;
  long *plVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  undefined4 *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  if ((param_1 == (long *)0x0) || (plVar7 = (long *)*param_1, plVar7 == param_1)) {
    uVar5 = 0xffffffea;
  }
  else {
    iVar8 = 0;
    __n = 0x34;
    if (param_3 != '\x01') {
      __n = 0x40;
    }
    lVar6 = 0x20;
    uVar2 = __n;
    if (param_3 != '\x01') {
      lVar6 = 0x38;
    }
    do {
      uVar9 = uVar2;
      lVar11 = plVar7[4];
      plVar7 = (long *)*plVar7;
      iVar8 = iVar8 + 1;
      uVar2 = uVar9 + lVar6 + lVar11;
    } while (plVar7 != param_1);
    __s_00 = (undefined4 *)vmalloc(uVar2);
    if (__s_00 != (undefined4 *)0x0) {
      memset(__s_00,0,__n);
      if ((3 < uVar2) && (*__s_00 = 0x464c457f, uVar2 != 4)) {
        *(char *)(__s_00 + 1) = param_3;
        if ((5 < uVar2) &&
           ((*(undefined1 *)((long)__s_00 + 5) = 1, uVar2 != 6 &&
            (*(undefined1 *)((long)__s_00 + 6) = 1, 7 < uVar2)))) {
          bVar4 = uVar2 < 0x10 || (uVar2 & 0xfffffffffffffffe) == 0x10;
          *(undefined1 *)((long)__s_00 + 7) = 0;
          if (param_3 == '\x01') {
            if ((((bVar4) || (*(undefined2 *)(__s_00 + 4) = 4, uVar2 < 0x12)) ||
                (((uVar2 & 0xfffffffffffffffe) == 0x12 ||
                 ((*(undefined2 *)((long)__s_00 + 0x12) = 0, uVar2 < 0x14 ||
                  ((uVar2 & 0xfffffffffffffffc) == 0x14)))))) ||
               ((__s_00[5] = 1, uVar2 < 0x1c ||
                (((((((uVar2 & 0xfffffffffffffffc) == 0x1c || (__s_00[7] = 0x34, uVar2 < 0x28)) ||
                    ((uVar2 & 0xfffffffffffffffe) == 0x28)) ||
                   ((*(undefined2 *)(__s_00 + 10) = 0x34, uVar2 < 0x2a ||
                    ((uVar2 & 0xfffffffffffffffe) == 0x2a)))) ||
                  (*(undefined2 *)((long)__s_00 + 0x2a) = 0x20, uVar2 < 0x2c)) ||
                 ((uVar2 & 0xfffffffffffffffe) == 0x2c)))))) goto LAB_00100a84;
            __n_00 = 0x20;
            *(short *)(__s_00 + 0xb) = (short)iVar8;
          }
          else {
            if ((((((bVar4) || (*(undefined2 *)(__s_00 + 4) = 4, uVar2 < 0x12)) ||
                  ((uVar2 & 0xfffffffffffffffe) == 0x12)) ||
                 (((*(undefined2 *)((long)__s_00 + 0x12) = 0, uVar2 < 0x14 ||
                   ((uVar2 & 0xfffffffffffffffc) == 0x14)) ||
                  ((__s_00[5] = 1, uVar2 < 0x20 ||
                   (((uVar2 & 0xfffffffffffffff8) == 0x20 ||
                    (*(undefined8 *)(__s_00 + 8) = 0x40, uVar2 < 0x34)))))))) ||
                (((uVar2 & 0xfffffffffffffffe) == 0x34 ||
                 (((*(undefined2 *)(__s_00 + 0xd) = 0x40, uVar2 < 0x36 ||
                   ((uVar2 & 0xfffffffffffffffe) == 0x36)) ||
                  (*(undefined2 *)((long)__s_00 + 0x36) = 0x38, uVar2 < 0x38)))))) ||
               ((uVar2 & 0xfffffffffffffffe) == 0x38)) goto LAB_00100a84;
            __n_00 = 0x38;
            *(short *)(__s_00 + 0xe) = (short)iVar8;
          }
          plVar7 = (long *)*param_1;
          if (plVar7 != param_1) {
            lVar13 = __n + (long)(int)__n_00 * (long)iVar8;
            uVar12 = __n + 0x30;
            uVar9 = ((lVar6 - __n) + uVar9 + lVar11) - 0x30;
            do {
              uVar10 = uVar12 - 0x30;
              __s = (undefined4 *)(uVar10 + (long)__s_00);
              memset(__s,0,__n_00);
              bVar4 = (uVar2 < uVar10 || uVar9 + 0x30 < 4) || (long)uVar10 < 0;
              if (param_3 == '\x01') {
                if (bVar4) goto LAB_00100a84;
                *__s = 1;
                if ((((long)(uVar12 - 0x2c) < 0) || (uVar2 < uVar12 - 0x2c)) || (uVar9 + 0x2c < 4))
                goto LAB_00100a84;
                *(int *)((long)__s_00 + (uVar12 - 0x2c)) = (int)lVar13;
                if ((((long)(uVar12 - 0x28) < 0) || (uVar2 < uVar12 - 0x28)) || (uVar9 + 0x28 < 4))
                goto LAB_00100a84;
                *(int *)((long)__s_00 + (uVar12 - 0x28)) = (int)plVar7[2];
                if ((((long)(uVar12 - 0x24) < 0) || (uVar2 < uVar12 - 0x24)) || (uVar9 + 0x24 < 4))
                goto LAB_00100a84;
                *(int *)((long)__s_00 + (uVar12 - 0x24)) = (int)plVar7[2];
                if ((((long)(uVar12 - 0x20) < 0) || (uVar2 < uVar12 - 0x20)) || (uVar9 + 0x20 < 4))
                goto LAB_00100a84;
                *(int *)((long)__s_00 + (uVar12 - 0x20)) = (int)plVar7[4];
                if ((((long)(uVar12 - 0x1c) < 0) || (uVar2 < uVar12 - 0x1c)) || (uVar9 + 0x1c < 4))
                goto LAB_00100a84;
                *(int *)((long)__s_00 + (uVar12 - 0x1c)) = (int)plVar7[4];
                if ((((long)(uVar12 - 0x18) < 0) || (uVar2 < uVar12 - 0x18)) || (uVar9 + 0x18 < 4))
                goto LAB_00100a84;
                *(undefined4 *)((long)__s_00 + (uVar12 - 0x18)) = 7;
                if ((((long)(uVar12 - 0x14) < 0) || (uVar2 < uVar12 - 0x14)) || (uVar9 + 0x14 < 4))
                goto LAB_00100a84;
                *(undefined4 *)((long)__s_00 + (uVar12 - 0x14)) = 0;
                if (plVar7[3] == 0) goto LAB_00100988;
LAB_001006e4:
                memcpy((void *)((long)__s_00 + lVar13),(void *)plVar7[3],plVar7[4]);
              }
              else {
                if (bVar4) goto LAB_00100a84;
                *__s = 1;
                if ((((long)(uVar12 - 0x28) < 0) || (uVar2 < uVar12 - 0x28)) || (uVar9 + 0x28 < 8))
                goto LAB_00100a84;
                *(long *)((long)__s_00 + (uVar12 - 0x28)) = lVar13;
                if ((((long)(uVar12 - 0x20) < 0) || (uVar2 < uVar12 - 0x20)) || (uVar9 + 0x20 < 8))
                goto LAB_00100a84;
                *(long *)((long)__s_00 + (uVar12 - 0x20)) = plVar7[2];
                if ((((long)(uVar12 - 0x18) < 0) || (uVar2 < uVar12 - 0x18)) || (uVar9 + 0x18 < 8))
                goto LAB_00100a84;
                *(long *)((long)__s_00 + (uVar12 - 0x18)) = plVar7[2];
                if ((((long)(uVar12 - 0x10) < 0) || (uVar2 < uVar12 - 0x10)) || (uVar9 + 0x10 < 8))
                goto LAB_00100a84;
                *(long *)((long)__s_00 + (uVar12 - 0x10)) = plVar7[4];
                if ((((long)(uVar12 - 8) < 0) || (uVar2 < uVar12 - 8)) ||
                   (0xfffffffffffffff7 < uVar9)) goto LAB_00100a84;
                *(long *)((long)__s_00 + (uVar12 - 8)) = plVar7[4];
                if (((((long)(uVar12 - 0x2c) < 0) || (uVar2 < uVar12 - 0x2c)) ||
                    ((uVar9 + 0x2c < 4 ||
                     ((*(undefined4 *)((long)__s_00 + (uVar12 - 0x2c)) = 7, (long)uVar12 < 0 ||
                      (uVar2 < uVar12)))))) || (uVar9 < 8)) goto LAB_00100a84;
                *(undefined8 *)((long)__s_00 + uVar12) = 0;
                if (plVar7[3] != 0) goto LAB_001006e4;
LAB_00100988:
                lVar6 = devm_ioremap(param_2,plVar7[2],plVar7[4]);
                if (lVar6 == 0) {
                  _dev_err(param_2,"invalid coredump segment (%pad, %zu)\n",plVar7 + 2,plVar7[4]);
                  memset((void *)((long)__s_00 + lVar13),0xff,plVar7[4]);
                }
                else {
                  __memcpy_fromio((long)__s_00 + lVar13,lVar6,plVar7[4]);
                }
              }
              plVar1 = plVar7 + 4;
              plVar7 = (long *)*plVar7;
              lVar13 = *plVar1 + lVar13;
              uVar12 = uVar12 + __n_00;
              uVar9 = uVar9 - __n_00;
            } while (plVar7 != param_1);
          }
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = __s_00;
          __init_swait_queue_head(&uStack_80,"&x->wait",&init_completion___key);
          dev_coredumpm(param_2,0,&local_90,uVar2,0xcc0,qcom_devcd_readv,qcom_devcd_freev);
          wait_for_completion(&local_88);
          uVar5 = completion_done(&local_88);
          uVar5 = (uVar5 ^ 0xffffffff) & 1;
          goto LAB_00100a4c;
        }
      }
LAB_00100a84:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100a88);
      (*pcVar3)();
    }
    uVar5 = 0xfffffff4;
  }
LAB_00100a4c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qcom_fw_elf_dump @ 00100a90 size=316
// signature: undefined qcom_fw_elf_dump(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_fw_elf_dump(long param_1,undefined8 param_2)

{
  long ***ppplVar1;
  long ***ppplVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  uint *puVar7;
  long ***local_78;
  long ***local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 8);
  local_78 = (long ***)&local_78;
  local_70 = (long ***)&local_78;
  if (*(short *)(lVar5 + 0x2c) != 0) {
    uVar6 = 0;
    puVar7 = (uint *)(lVar5 + 0x4c);
    do {
      if (((puVar7[-6] == 1) && ((*puVar7 & 0x7000000) != 0x2000000)) && (puVar7[-1] != 0)) {
        ppplVar2 = (long ***)kmalloc_trace(_mutex_unlock,0xdc0,0x28);
        ppplVar1 = local_70;
        if (ppplVar2 == (long ***)0x0) {
          uVar4 = 0xfffffff4;
          goto LAB_00100b88;
        }
        ppplVar2[2] = (long **)(ulong)puVar7[-3];
        ppplVar2[4] = (long **)(ulong)puVar7[-1];
        uVar3 = __list_add_valid(ppplVar2,local_70,&local_78);
        if ((uVar3 & 1) != 0) {
          *ppplVar2 = (long **)&local_78;
          ppplVar2[1] = (long **)ppplVar1;
          local_70 = ppplVar2;
          *ppplVar1 = (long **)ppplVar2;
        }
      }
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 8;
    } while (uVar6 < *(ushort *)(lVar5 + 0x2c));
  }
  qcom_elf_dump(&local_78,param_2,1);
  uVar4 = 0;
LAB_00100b88:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_create_ramdump_device @ 00100bd0 size=564
// signature: undefined qcom_create_ramdump_device(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long qcom_create_ramdump_device(long param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char *__s;
  ulong uVar4;
  long lVar5;
  
  if (param_1 == 0) {
    _printk(&DAT_00101126,"qcom_create_ramdump_device");
    lVar5 = 0;
  }
  else {
    mutex_lock(&rd_minor_mutex);
    if ((ramdump_devnode_inited & 1) == 0) {
      ramdump_class = __class_create(&__this_module,"ramdump",&ramdump_devnode_init___key);
      iVar1 = alloc_chrdev_region(&ramdump_dev,0,0x100,"ramdump");
      if (iVar1 != 0) {
        _printk(&DAT_001011b9,"ramdump_devnode_init");
        mutex_unlock(&rd_minor_mutex);
        return (long)iVar1;
      }
      ramdump_devnode_inited = 1;
    }
    mutex_unlock(&rd_minor_mutex);
    __s = (char *)kmalloc_trace(_device_create,0xdc0,400);
    lVar5 = 0;
    if (__s != (char *)0x0) {
      uVar2 = ida_alloc_range(rd_minor_id,0,0xff,0xcc0);
      if ((int)uVar2 < 0) {
        _printk(&DAT_00101160,"qcom_create_ramdump_device",uVar2);
        iVar1 = -0x13;
      }
      else {
        snprintf(__s,0x100,"%s",param_1);
        uVar4 = device_create(ramdump_class,param_2,ramdump_dev & 0xfff00000 | uVar2,__s,__s);
        *(ulong *)(__s + 0x188) = uVar4;
        if (uVar4 < 0xfffffffffffff001) {
          cdev_init(__s + 0x100,0);
          uVar3 = cdev_add(__s + 0x100,ramdump_dev & 0xfff00000 | uVar2,1);
          if (uVar3 == 0) {
            return *(long *)(__s + 0x188);
          }
          uVar4 = (ulong)uVar3;
          _printk(&DAT_001010a8,"qcom_create_ramdump_device",param_1,uVar4);
          device_unregister(*(undefined8 *)(__s + 0x188));
        }
        else {
          _printk(&DAT_00101189,"qcom_create_ramdump_device",param_1,uVar4 & 0xffffffff);
        }
        iVar1 = (int)uVar4;
        ida_free(rd_minor_id,uVar2);
      }
      kfree(__s);
      lVar5 = (long)iVar1;
    }
  }
  return lVar5;
}



//------------------------------------------------------------
// qcom_destroy_ramdump_device @ 00100e08 size=96
// signature: undefined qcom_destroy_ramdump_device(void)
// callers: []
//------------------------------------------------------------

void qcom_destroy_ramdump_device(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = *(ulong *)(param_1 + 0x98);
  if ((uVar2 != 0) && (uVar2 < 0xfffffffffffff001)) {
    uVar1 = *(uint *)(uVar2 + 0x180);
    cdev_del(uVar2 + 0x100);
    device_unregister(*(undefined8 *)(uVar2 + 0x188));
    ida_free(rd_minor_id,uVar1 & 0xfffff);
    kfree(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_devcd_readv @ 00100e6c size=92
// signature: undefined qcom_devcd_readv(void)
// callers: []
//------------------------------------------------------------

void qcom_devcd_readv(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_20 = param_2;
  memory_read_from_buffer(param_1,param_3,&local_20,*param_4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_devcd_freev @ 00100ecc size=52
// signature: undefined qcom_devcd_freev(void)
// callers: []
//------------------------------------------------------------

void qcom_devcd_freev(undefined8 *param_1)

{
  vfree(*param_1);
  complete_all(param_1 + 1);
  return;
}



//------------------------------------------------------------
// _printk @ 00102000 size=1
// signature: undefined _printk(void)
// callers: [qcom_dump, qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 00102008 size=1
// signature: undefined vmalloc(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00102010 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00102018 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00102020 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102028 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00102030 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00102038 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_coredumpm @ 00102040 size=1
// signature: undefined dev_coredumpm(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_coredumpm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 00102048 size=1
// signature: undefined wait_for_completion(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// completion_done @ 00102050 size=1
// signature: undefined completion_done(void)
// callers: [qcom_elf_dump, qcom_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_elf_dump, qcom_dump, qcom_devcd_readv, qcom_fw_elf_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_create_ramdump_device, qcom_fw_elf_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102070 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_fw_elf_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102078 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00102080 size=1
// signature: undefined __class_create(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00102088 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102090 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00102098 size=1
// signature: undefined ida_alloc_range(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001020a0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001020a8 size=1
// signature: undefined device_create(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001020b0 size=1
// signature: undefined cdev_init(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001020b8 size=1
// signature: undefined cdev_add(void)
// callers: [qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 001020c0 size=1
// signature: undefined device_unregister(void)
// callers: [qcom_destroy_ramdump_device, qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 001020c8 size=1
// signature: undefined ida_free(void)
// callers: [qcom_destroy_ramdump_device, qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001020d0 size=1
// signature: undefined kfree(void)
// callers: [qcom_destroy_ramdump_device, qcom_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 001020d8 size=1
// signature: undefined cdev_del(void)
// callers: [qcom_destroy_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memory_read_from_buffer @ 001020e0 size=1
// signature: undefined memory_read_from_buffer(void)
// callers: [qcom_devcd_readv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memory_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 001020e8 size=1
// signature: undefined vfree(void)
// callers: [qcom_devcd_freev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 001020f0 size=1
// signature: undefined complete_all(void)
// callers: [qcom_devcd_freev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



