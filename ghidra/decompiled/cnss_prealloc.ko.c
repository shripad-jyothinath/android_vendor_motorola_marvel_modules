// Decompiled by Ghidra 12.2
// Program: cnss_prealloc.ko
// Image base: 00100000

//------------------------------------------------------------
// cnss_initialize_prealloc_pool @ 0010027c size=536
// signature: undefined cnss_initialize_prealloc_pool(void)
// callers: []
//------------------------------------------------------------

void cnss_initialize_prealloc_pool(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  long lVar8;
  
  _printk(&DAT_00101209,param_1);
  puVar2 = (undefined4 *)&cnss_pools_wcn6750;
  if (param_1 != 0x6750) {
    puVar2 = &cnss_pools_default;
  }
  uVar6 = 0;
  cnss_pools = (undefined4 *)&cnss_pools_adrastea;
  if (param_1 != 0xabcd) {
    cnss_pools = puVar2;
  }
  cnss_prealloc_pool_size = 5;
  do {
    lVar8 = (long)(int)uVar6;
    lVar1 = lVar8 + (long)(int)uVar6 * 2;
    uVar3 = cnss_pools[lVar1 * 8];
    uVar5 = kmem_cache_create_usercopy(cnss_pools + lVar1 * 8 + 3,uVar3,0,0x4000000,0,uVar3,0);
    *(undefined8 *)(cnss_pools + lVar1 * 8 + 0x12) = uVar5;
    if (*(long *)(cnss_pools + lVar1 * 8 + 0x12) == 0) {
      _printk(&DAT_00101280,cnss_pools + (long)(int)uVar6 * 0x18 + 3);
    }
    else {
      uVar5 = mempool_create(cnss_pools[lVar8 * 0x18 + 2],&mempool_alloc_slab,&mempool_free_slab);
      *(undefined8 *)(cnss_pools + lVar8 * 0x18 + 0x10) = uVar5;
      if (*(long *)(cnss_pools + lVar8 * 0x18 + 0x10) == 0) {
        _printk(&DAT_001011a2,cnss_pools + lVar8 * 0x18 + 3);
        kmem_cache_destroy(*(undefined8 *)(cnss_pools + lVar8 * 0x18 + 0x12));
        *(undefined8 *)(cnss_pools + lVar8 * 0x18 + 0x12) = 0;
      }
      else {
        cnss_pools[lVar8 * 0x18 + 0x16] = cnss_pools[lVar8 * 0x18 + 2];
        uVar5 = __kmalloc((long)(int)cnss_pools[lVar8 * 0x18 + 2] << 3,0xdc0);
        *(undefined8 *)(cnss_pools + lVar8 * 0x18 + 0x14) = uVar5;
        if (*(long *)(cnss_pools + lVar8 * 0x18 + 0x14) == 0) {
          puVar7 = (undefined8 *)(cnss_pools + (long)(int)uVar6 * 0x18);
          _printk(&DAT_001011c6,(undefined4 *)((long)puVar7 + 0xc),*(undefined4 *)(puVar7 + 1),
                  *puVar7);
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100444);
          (*pcVar4)();
        }
        puVar7 = (undefined8 *)(cnss_pools + (long)(int)uVar6 * 0x18);
        _printk(&DAT_001012a2,(undefined4 *)((long)puVar7 + 0xc),*(undefined4 *)(puVar7 + 1),*puVar7
               );
      }
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < cnss_prealloc_pool_size);
  pool_table_lock = 0;
  return;
}



//------------------------------------------------------------
// cnss_deinitialize_prealloc_pool @ 0010049c size=212
// signature: undefined cnss_deinitialize_prealloc_pool(void)
// callers: []
//------------------------------------------------------------

void cnss_deinitialize_prealloc_pool(void)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  
  if (cnss_pools != 0 && cnss_prealloc_pool_size != 0) {
    uVar3 = 0;
    do {
      _printk(&DAT_0010125b,cnss_pools + (long)(int)uVar3 * 0x60 + 0xc);
      mempool_destroy(*(undefined8 *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x40));
      kmem_cache_destroy(*(undefined8 *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x48));
      *(undefined8 *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x40) = 0;
      *(undefined8 *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x48) = 0;
      kfree(*(undefined8 *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x50));
      lVar1 = (long)(int)uVar3;
      uVar3 = uVar3 + 1;
      bVar2 = uVar3 < cnss_prealloc_pool_size;
      *(undefined8 *)(cnss_pools + lVar1 * 0x60 + 0x50) = 0;
    } while (bVar2);
  }
  return;
}



//------------------------------------------------------------
// wcnss_check_pool_lists @ 00100574 size=200
// signature: undefined wcnss_check_pool_lists(void)
// callers: []
//------------------------------------------------------------

void wcnss_check_pool_lists(void)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  
  _printk(&DAT_001012dc);
  if (cnss_prealloc_pool_size != 0) {
    uVar4 = 0;
    do {
      lVar5 = cnss_pools + (long)(int)uVar4 * 0x60;
      iVar1 = *(int *)(lVar5 + 0x58);
      if (iVar1 != 0) {
        lVar6 = 0;
        do {
          lVar3 = *(long *)(*(long *)(lVar5 + 0x50) + lVar6 * 8);
          if (lVar3 != 0) {
            _printk(&DAT_001012f6,lVar3,cnss_pools + (long)(int)uVar4 * 0x60 + 0xc,lVar6);
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100620);
            (*pcVar2)();
          }
          lVar6 = lVar6 + 1;
        } while (iVar1 != lVar6);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < cnss_prealloc_pool_size);
  }
  return;
}



//------------------------------------------------------------
// wcnss_prealloc_get @ 00100644 size=568
// signature: undefined wcnss_prealloc_get(void)
// callers: []
//------------------------------------------------------------

long wcnss_prealloc_get(ulong param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined4 uVar5;
  ulong *puVar6;
  long lVar7;
  uint uVar8;
  long *plVar9;
  uint uVar10;
  long lVar11;
  
  if (cnss_pools == (ulong *)0x0) {
    return 0;
  }
  lVar2 = sp_el0;
  if (((*(uint *)(lVar2 + 0x10) & 0xffff00) == 0) && (*(int *)(lVar2 + 0x10) == 0)) {
    uVar4 = daif;
    uVar5 = 0xb20;
    if (((uVar4 & 0x80) == 0) && (uVar5 = 0xdc0, *(int *)(lVar2 + 0x4b4) != 0)) {
      uVar5 = 0xb20;
    }
  }
  else {
    uVar5 = 0xb20;
  }
  if (*cnss_pools <= param_1 && cnss_prealloc_pool_size != 0) {
    uVar10 = 0;
    puVar6 = cnss_pools;
    uVar8 = cnss_prealloc_pool_size;
    do {
      if (param_1 <= puVar6[(long)(int)uVar10 * 0xc]) {
        if (puVar6[(long)(int)uVar10 * 0xc + 8] != 0) {
          if (puVar6[(long)(int)uVar10 * 0xc + 10] == 0) {
            _printk(&DAT_0010123f,(long)puVar6 + (long)(int)uVar10 * 0x60 + 0xc);
            break;
          }
          lVar2 = mempool_alloc(puVar6[(long)(int)uVar10 * 0xc + 8],uVar5);
          if (lVar2 != 0) {
            uVar3 = _raw_spin_lock_irqsave(&pool_table_lock);
            iVar1 = (int)cnss_pools[(long)(int)uVar10 * 0xc + 0xb];
            lVar7 = (long)iVar1;
            if (iVar1 == 0) {
              lVar7 = 0;
              goto LAB_001007c8;
            }
            plVar9 = (long *)cnss_pools[(long)(int)uVar10 * 0xc + 10];
            lVar11 = lVar7;
            goto LAB_00100790;
          }
          puVar6 = cnss_pools;
          uVar8 = cnss_prealloc_pool_size;
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar8);
  }
  goto LAB_001006a8;
  while( true ) {
    plVar9 = plVar9 + 1;
    lVar11 = lVar11 + -1;
    if (lVar11 == 0) break;
LAB_00100790:
    if (*plVar9 == 0) {
      *plVar9 = lVar2;
      goto LAB_00100820;
    }
  }
LAB_001007c8:
  uVar4 = krealloc((long *)cnss_pools[(long)(int)uVar10 * 0xc + 10],
                   -(ulong)(iVar1 + 1U >> 0x1f) & 0xfffffff800000000 | (ulong)(iVar1 + 1U) << 3,
                   0xa20);
  cnss_pools[(long)(int)uVar10 * 0xc + 10] = uVar4;
  if (cnss_pools[(long)(int)uVar10 * 0xc + 10] != 0) {
    *(long *)(cnss_pools[(long)(int)uVar10 * 0xc + 10] + lVar7 * 8) = lVar2;
    *(int *)(cnss_pools + (long)(int)uVar10 * 0xc + 0xb) =
         (int)cnss_pools[(long)(int)uVar10 * 0xc + 0xb] + 1;
LAB_00100820:
    _raw_spin_unlock_irqrestore(&pool_table_lock,uVar3);
    return lVar2;
  }
  _raw_spin_unlock_irqrestore(&pool_table_lock,uVar3);
  mempool_free(lVar2,cnss_pools[(long)(int)uVar10 * 0xc + 8]);
LAB_001006a8:
  if (*cnss_pools <= param_1) {
    _printk(&DAT_0010131e,param_1,uVar5);
  }
  return 0;
}



//------------------------------------------------------------
// wcnss_prealloc_put @ 00100880 size=312
// signature: undefined wcnss_prealloc_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcnss_prealloc_put(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  
  if ((param_1 != 0) && (cnss_pools != 0 && cnss_prealloc_pool_size != 0)) {
    uVar3 = 0;
    do {
      if (*(long *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x40) != 0) {
        if (*(long *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x50) == 0) {
          _printk(&DAT_0010123f,cnss_pools + (long)(int)uVar3 * 0x60 + 0xc);
          return 0;
        }
        uVar2 = _raw_spin_lock_irqsave(&pool_table_lock);
        lVar4 = cnss_pools + (long)(int)uVar3 * 0x60;
        iVar1 = *(int *)(lVar4 + 0x58);
        if (iVar1 != 0) {
          lVar5 = 0;
          lVar4 = *(long *)(lVar4 + 0x50);
          do {
            if (*(long *)(lVar4 + lVar5 * 8) == param_1) {
              *(undefined8 *)(lVar4 + lVar5 * 8) = 0;
              _raw_spin_unlock_irqrestore(&pool_table_lock,uVar2);
              if (-1 < (int)lVar5) {
                mempool_free(param_1,*(undefined8 *)(cnss_pools + (long)(int)uVar3 * 0x60 + 0x40));
                return 1;
              }
              goto LAB_001008e0;
            }
            lVar5 = lVar5 + 1;
          } while (iVar1 != lVar5);
        }
        _raw_spin_unlock_irqrestore(&pool_table_lock,uVar2);
      }
LAB_001008e0:
      uVar3 = uVar3 + 1;
    } while (uVar3 < cnss_prealloc_pool_size);
  }
  return 0;
}



//------------------------------------------------------------
// wcnss_prealloc_check_memory_leak @ 001009bc size=4
// signature: undefined wcnss_prealloc_check_memory_leak(void)
// callers: []
//------------------------------------------------------------

void wcnss_prealloc_check_memory_leak(void)

{
  return;
}



//------------------------------------------------------------
// wcnss_pre_alloc_reset @ 001009c4 size=8
// signature: undefined wcnss_pre_alloc_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 wcnss_pre_alloc_reset(void)

{
  return 0xffffffa1;
}



//------------------------------------------------------------
// init_module @ 00100ad4 size=108
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = of_find_node_with_property(0,"qcom,wlan");
  if (lVar1 != 0) {
    do {
      uVar2 = of_device_is_available(lVar1);
      if ((uVar2 & 1) != 0) {
        return 0;
      }
      lVar1 = of_find_node_with_property(lVar1,"qcom,wlan");
    } while (lVar1 != 0);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// cleanup_module @ 00100b44 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// _printk @ 00102000 size=1
// signature: undefined _printk(void)
// callers: [wcnss_check_pool_lists, cnss_initialize_prealloc_pool, wcnss_prealloc_get, wcnss_prealloc_put, cnss_deinitialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmem_cache_create_usercopy @ 00102018 size=1
// signature: undefined kmem_cache_create_usercopy(void)
// callers: [cnss_initialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_create_usercopy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mempool_create @ 00102020 size=1
// signature: undefined mempool_create(void)
// callers: [cnss_initialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mempool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmem_cache_destroy @ 00102028 size=1
// signature: undefined kmem_cache_destroy(void)
// callers: [cnss_initialize_prealloc_pool, cnss_deinitialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmem_cache_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102030 size=1
// signature: undefined __kmalloc(void)
// callers: [cnss_initialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mempool_destroy @ 00102038 size=1
// signature: undefined mempool_destroy(void)
// callers: [cnss_deinitialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mempool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102040 size=1
// signature: undefined kfree(void)
// callers: [cnss_deinitialize_prealloc_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mempool_alloc @ 00102048 size=1
// signature: undefined mempool_alloc(void)
// callers: [wcnss_prealloc_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mempool_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00102050 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [wcnss_prealloc_get, wcnss_prealloc_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 00102058 size=1
// signature: undefined krealloc(void)
// callers: [wcnss_prealloc_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00102060 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [wcnss_prealloc_get, wcnss_prealloc_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mempool_free @ 00102068 size=1
// signature: undefined mempool_free(void)
// callers: [wcnss_prealloc_get, wcnss_prealloc_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mempool_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_with_property @ 00102070 size=1
// signature: undefined of_find_node_with_property(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_with_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00102078 size=1
// signature: undefined of_device_is_available(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



