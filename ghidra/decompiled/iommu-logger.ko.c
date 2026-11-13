// Decompiled by Ghidra 12.2
// Program: iommu-logger.ko
// Image base: 00100000

//------------------------------------------------------------
// iommu_logger_register @ 001000bc size=448
// signature: undefined iommu_logger_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong iommu_logger_register(ulong *param_1,undefined8 param_2,undefined8 *param_3,int *param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long lVar11;
  uint uVar12;
  
  lVar6 = _memstart_addr;
  puVar10 = (undefined8 *)0xffffffea;
  if (((param_1 != (ulong *)0x0) && (param_3 != (undefined8 *)0x0)) && (param_4 != (int *)0x0)) {
    uVar12 = 0;
    uVar1 = *param_4 + 2;
    if ((uVar1 < 5) && (uVar1 != 3)) {
      uVar9 = (*(ulong *)(param_4 + 6) & 0xaaaaaaaaaaaaaaaa) >> 1 |
              (*(ulong *)(param_4 + 6) & 0x5555555555555555) << 1;
      uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
      uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
      uVar9 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10;
      uVar4 = (int)LZCOUNT(uVar9 >> 0x20 | uVar9 << 0x20) - 3;
      uVar12 = 0;
      if (uVar4 != 0) {
        uVar12 = (param_4[8] - 4U) / uVar4;
      }
    }
    if (uVar1 < 5) {
      puVar10 = (undefined8 *)0xffffffffffffffea;
      if ((((0x17U >> (ulong)(uVar1 & 0x1f) & 1) != 0) && (uVar12 != 0)) &&
         ((uVar4 = *param_4 + 2, uVar4 < 5 && (uVar4 != 3)))) {
        uVar3 = *(undefined4 *)(&DAT_0010041c + (long)(int)uVar1 * 4);
        lVar11 = *(long *)(param_4 + 0x10);
        puVar10 = (undefined8 *)kmalloc_trace(___list_add_valid,0xdc0,0x40);
        if (puVar10 == (undefined8 *)0x0) {
          puVar10 = (undefined8 *)0xfffffffffffffff4;
        }
        else {
          lVar7 = kasprintf(0xcc0,&DAT_00100416,*param_3);
          if (lVar7 == 0) {
            kfree(puVar10);
            puVar10 = (undefined8 *)0xfffffffffffffff4;
          }
          else {
            uVar8 = iommu_group_get(param_3);
            iommu_group_put();
            puVar2 = puVar10 + 6;
            puVar10[6] = puVar2;
            puVar10[7] = puVar2;
            *puVar10 = param_2;
            puVar10[1] = uVar8;
            puVar10[2] = lVar7;
            *(undefined4 *)(puVar10 + 3) = uVar3;
            *(uint *)((long)puVar10 + 0x1c) = uVar12;
            puVar10[4] = lVar11 - lVar6 | 0xffffff8000000000;
            puVar10[5] = 0;
            if (puVar10 < (undefined8 *)0xfffffffffffff001) {
              mutex_lock(&iommu_debug_attachments_lock);
              puVar5 = iommu_debug_attachments;
              uVar9 = __list_add_valid(puVar2,&iommu_debug_attachments,iommu_debug_attachments);
              if ((uVar9 & 1) != 0) {
                *(undefined8 **)(puVar5 + 8) = puVar2;
                puVar10[6] = puVar5;
                puVar10[7] = &iommu_debug_attachments;
                iommu_debug_attachments = (undefined *)puVar2;
              }
              mutex_unlock(&iommu_debug_attachments_lock);
              *param_1 = (ulong)puVar10;
              puVar10 = (undefined8 *)0x0;
            }
          }
        }
      }
    }
    else {
      puVar10 = (undefined8 *)0xffffffffffffffea;
    }
  }
  return (ulong)puVar10 & 0xffffffff;
}



//------------------------------------------------------------
// iommu_logger_unregister @ 00100280 size=124
// signature: undefined iommu_logger_unregister(void)
// callers: []
//------------------------------------------------------------

void iommu_logger_unregister(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  if (param_1 != 0) {
    mutex_lock(&iommu_debug_attachments_lock);
    uVar3 = __list_del_entry_valid(param_1 + 0x30);
    if ((uVar3 & 1) != 0) {
      lVar1 = *(long *)(param_1 + 0x30);
      plVar2 = *(long **)(param_1 + 0x38);
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *(undefined8 *)(param_1 + 0x30) = 0xdead000000000100;
    *(undefined8 *)(param_1 + 0x38) = 0xdead000000000122;
    mutex_unlock(&iommu_debug_attachments_lock);
    kfree(*(undefined8 *)(param_1 + 0x10));
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00101010 size=1
// signature: undefined kmalloc_trace(void)
// callers: [iommu_logger_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 00101018 size=1
// signature: undefined kasprintf(void)
// callers: [iommu_logger_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_get @ 00101020 size=1
// signature: undefined iommu_group_get(void)
// callers: [iommu_logger_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_put @ 00101028 size=1
// signature: undefined iommu_group_put(void)
// callers: [iommu_logger_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00101030 size=1
// signature: undefined mutex_lock(void)
// callers: [iommu_logger_register, iommu_logger_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00101038 size=1
// signature: undefined __list_add_valid(void)
// callers: [iommu_logger_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00101040 size=1
// signature: undefined mutex_unlock(void)
// callers: [iommu_logger_register, iommu_logger_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00101048 size=1
// signature: undefined kfree(void)
// callers: [iommu_logger_register, iommu_logger_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00101050 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [iommu_logger_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



