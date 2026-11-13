// Decompiled by Ghidra 12.2
// Program: qfprom-sys.ko
// Image base: 00100000

//------------------------------------------------------------
// qfprom_sys_probe @ 00100134 size=608
// signature: undefined qfprom_sys_probe(void)
// callers: []
//------------------------------------------------------------

ulong qfprom_sys_probe(long param_1)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  
  uVar3 = of_property_read_string_helper(*(undefined8 *)(param_1 + 0x2f8),"nvmem-cell-names",0,0,0);
  if ((int)uVar3 < 1) {
    uVar7 = 0xffffffea;
  }
  else {
    lVar2 = param_1 + 0x10;
    puVar5 = (uint *)devm_kmalloc(lVar2,0x18,0xdc0);
    if (puVar5 != (uint *)0x0) {
      lVar10 = (ulong)uVar3 << 3;
      lVar6 = devm_kmalloc(lVar2,lVar10,0xdc0);
      *(long *)(puVar5 + 2) = lVar6;
      if ((lVar6 != 0) && (lVar6 = devm_kmalloc(lVar2,lVar10,0xdc0), lVar6 != 0)) {
        lVar10 = devm_kmalloc(lVar2,lVar10,0xdc0);
        *(long *)(puVar5 + 4) = lVar10;
        if (lVar10 != 0) {
          of_property_read_string_helper
                    (*(undefined8 *)(param_1 + 0x2f8),"nvmem-cell-names",lVar6,(ulong)uVar3,0);
          uVar11 = 0;
          do {
            uVar7 = nvmem_cell_get(lVar2,*(undefined8 *)(lVar6 + uVar11 * 8));
            if ((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) {
              _dev_err(lVar2,"cell corresponding to %s not found\n",
                       *(undefined8 *)(lVar6 + uVar11 * 8));
LAB_00100314:
              if ((int)uVar11 != 0) {
                do {
                  lVar6 = (uVar11 - 1) * 8;
                  sysfs_remove_bin_file(lVar2,*(undefined8 *)(lVar10 + lVar6));
                  nvmem_cell_put(*(undefined8 *)(*(long *)(puVar5 + 2) + lVar6));
                  bVar1 = 1 < uVar11;
                  uVar11 = uVar11 - 1;
                } while (bVar1);
              }
              *puVar5 = 0;
              goto LAB_001002e4;
            }
            uVar8 = devm_kmalloc(lVar2,0x40,0xdc0);
            lVar9 = uVar11 * 8;
            *(undefined8 *)(lVar10 + lVar9) = uVar8;
            lVar10 = *(long *)(puVar5 + 4);
            if (*(long *)(lVar10 + lVar9) == 0) {
              nvmem_cell_put(uVar7);
              uVar7 = 0xfffffff4;
              goto LAB_00100314;
            }
            *(ulong *)(*(long *)(puVar5 + 2) + lVar9) = uVar7;
            **(undefined8 **)(*(long *)(puVar5 + 4) + lVar9) = *(undefined8 *)(lVar6 + lVar9);
            *(undefined2 *)(*(long *)(*(long *)(puVar5 + 4) + lVar9) + 8) = 0x124;
            *(ulong *)(*(long *)(*(long *)(puVar5 + 4) + lVar9) + 0x18) = uVar7;
            *(undefined8 *)(*(long *)(*(long *)(puVar5 + 4) + lVar9) + 0x10) = 4;
            *(code **)(*(long *)(*(long *)(puVar5 + 4) + lVar9) + 0x28) = qfprom_sys_cell_read;
            lVar10 = *(long *)(puVar5 + 4);
            uVar4 = sysfs_create_bin_file(lVar2,*(undefined8 *)(lVar10 + lVar9));
            if (uVar4 != 0) {
              _dev_err(lVar2,"cell corresponding to %s\n",*(undefined8 *)(lVar6 + uVar11 * 8));
              nvmem_cell_put(uVar7);
              uVar7 = (ulong)uVar4;
              goto LAB_00100314;
            }
            uVar11 = uVar11 + 1;
          } while (uVar3 != (uint)uVar11);
          uVar7 = 0;
          *puVar5 = uVar3;
          *(uint **)(param_1 + 0xa0) = puVar5;
          goto LAB_001002e4;
        }
      }
    }
    uVar7 = 0xfffffff4;
  }
LAB_001002e4:
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// qfprom_sys_remove @ 00100398 size=116
// signature: undefined qfprom_sys_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qfprom_sys_remove(long param_1)

{
  int *piVar1;
  long lVar2;
  
  piVar1 = *(int **)(param_1 + 0xa0);
  if (0 < *piVar1) {
    lVar2 = 0;
    do {
      nvmem_cell_put(*(undefined8 *)(*(long *)(piVar1 + 2) + lVar2 * 8));
      sysfs_remove_bin_file(param_1 + 0x10,*(undefined8 *)(*(long *)(piVar1 + 4) + lVar2 * 8));
      lVar2 = lVar2 + 1;
    } while (lVar2 < *piVar1);
  }
  return 0;
}



//------------------------------------------------------------
// qfprom_sys_cell_read @ 00100410 size=172
// signature: undefined qfprom_sys_cell_read(void)
// callers: []
//------------------------------------------------------------

void qfprom_sys_cell_read
               (undefined8 param_1,undefined8 param_2,long param_3,void *param_4,undefined8 param_5,
               ulong param_6)

{
  long lVar1;
  void *__src;
  size_t sVar2;
  size_t local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if ((*(long *)(param_3 + 0x18) == 0) ||
     (__src = (void *)nvmem_cell_read(*(long *)(param_3 + 0x18),&local_40),
     (void *)0xfffffffffffff000 < __src)) {
    sVar2 = 0xffffffffffffffea;
  }
  else {
    if (param_6 <= local_40) {
      local_40 = param_6;
    }
    memcpy(param_4,__src,local_40);
    kfree(__src);
    sVar2 = local_40;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(sVar2);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001004c0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qfprom_sys_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001004f0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qfprom_sys_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// of_property_read_string_helper @ 00102010 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [qfprom_sys_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qfprom_sys_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 00102020 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [qfprom_sys_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_bin_file @ 00102028 size=1
// signature: undefined sysfs_create_bin_file(void)
// callers: [qfprom_sys_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_bin_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 00102030 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [qfprom_sys_probe, qfprom_sys_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_bin_file @ 00102038 size=1
// signature: undefined sysfs_remove_bin_file(void)
// callers: [qfprom_sys_probe, qfprom_sys_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_bin_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [qfprom_sys_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 00102048 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [qfprom_sys_cell_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00102050 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qfprom_sys_cell_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102058 size=1
// signature: undefined kfree(void)
// callers: [qfprom_sys_cell_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qfprom_sys_cell_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



