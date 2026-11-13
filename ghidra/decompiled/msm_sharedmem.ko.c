// Decompiled by Ghidra 12.2
// Program: msm_sharedmem.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_sharedmem_probe @ 0010015c size=792
// signature: undefined msm_sharedmem_probe(void)
// callers: []
//------------------------------------------------------------

int msm_sharedmem_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  bool bVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined *puVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  long local_b8;
  undefined4 local_ac;
  long local_a8 [11];
  
  lVar1 = sp_el0;
  local_a8[10] = *(long *)(lVar1 + 0x638);
  local_ac = 0xffffffff;
  if (*(long *)(param_1 + 0x2f8) == 0) {
    puVar7 = &DAT_00100f66;
  }
  else {
    plVar5 = (long *)platform_get_resource(param_1,0x200,0);
    if (plVar5 != (long *)0x0) {
      lVar1 = param_1 + 0x10;
      iVar4 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,client-id",&local_ac,1,0);
      if (iVar4 < 0) {
        local_ac = 0xffffffff;
        _printk(&DAT_00100eeb,"msm_sharedmem_probe");
      }
      lVar6 = devm_kmalloc(lVar1,0x240,0xdc0);
      if (lVar6 == 0) {
LAB_001001e8:
        iVar4 = -0xc;
        goto LAB_001001ec;
      }
      lVar8 = *plVar5;
      uVar2 = (plVar5[1] - lVar8) + 1;
      iVar10 = (int)uVar2;
      local_b8 = lVar8;
      if (iVar10 == 0) {
        puVar7 = &DAT_00100ce7;
LAB_001002e0:
        _printk(puVar7,"msm_sharedmem_probe");
        iVar4 = -0x16;
      }
      else {
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
        iVar4 = __of_parse_phandle_with_args
                          (*(undefined8 *)(param_1 + 0x2f8),"memory-region",0,0,0,local_a8);
        if ((iVar4 == 0) && (local_a8[0] != 0)) {
          lVar8 = of_reserved_mem_lookup();
          if (lVar8 == 0) {
            puVar7 = &DAT_00100b0a;
            goto LAB_001002e0;
          }
          iVar4 = of_reserved_mem_device_init_by_idx(lVar1,*(undefined8 *)(param_1 + 0x2f8),0);
          if (iVar4 == 0) {
            lVar8 = *(long *)(lVar8 + 0x20);
            local_b8 = lVar8;
            _printk(&DAT_00100e1e,"msm_sharedmem_probe");
            goto LAB_00100328;
          }
          puVar7 = &DAT_00100e9e;
        }
        else {
LAB_00100328:
          if (lVar8 == 0) {
            lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,guard-memory",0);
            if (lVar8 != 0) {
              iVar10 = iVar10 + 0x2000;
            }
            uVar11 = 0xffffffe1;
            do {
              bVar3 = 0xfffffffe < uVar11;
              uVar11 = uVar11 + 1;
              if (bVar3) {
                _printk(&DAT_00100d9b,"msm_sharedmem_probe",iVar10);
                goto LAB_001001e8;
              }
              lVar9 = dma_alloc_attrs(lVar1,iVar10,&local_b8,0xcc0,0);
            } while (lVar9 == 0);
            if (lVar8 != 0) {
              local_b8 = local_b8 + 0x1000;
            }
          }
          lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,vm-nav-path",0);
          setup_shared_ram_perms(local_ac,local_b8,uVar2 & 0xffffffff,lVar8 != 0);
          *(code **)(lVar6 + 0x218) = sharedmem_mmap;
          lVar8 = plVar5[2];
          *(long *)(lVar6 + 0x20) = local_b8;
          *(long *)(lVar6 + 8) = lVar8;
          *(undefined **)(lVar6 + 0x10) = &DAT_00100ddc;
          *(ulong *)(lVar6 + 0x30) = uVar2 & 0xffffffff;
          *(undefined4 *)(lVar6 + 0x38) = 1;
          iVar4 = __uio_register_device(&__this_module,lVar1,lVar6);
          if (iVar4 == 0) {
            *(long *)(param_1 + 0xa8) = lVar6;
            _printk(&DAT_00100d52,"msm_sharedmem_probe",plVar5[2]);
            goto LAB_001001ec;
          }
          puVar7 = &DAT_00100c82;
        }
        _printk(puVar7,"msm_sharedmem_probe",iVar4);
      }
      goto LAB_001001ec;
    }
    puVar7 = &DAT_00100c59;
  }
  _printk(puVar7,"msm_sharedmem_probe");
  iVar4 = -0x13;
LAB_001001ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// msm_sharedmem_remove @ 00100478 size=36
// signature: undefined msm_sharedmem_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_sharedmem_remove(long param_1)

{
  uio_unregister_device(*(undefined8 *)(param_1 + 0xa8));
  return 0;
}



//------------------------------------------------------------
// setup_shared_ram_perms @ 0010049c size=360
// signature: undefined setup_shared_ram_perms(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void setup_shared_ram_perms(int param_1,undefined8 param_2,undefined4 param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 8;
  uStack_40 = param_2;
  if (param_1 != 1) goto LAB_00100578;
  if ((param_4 & 1) == 0) {
    puVar3 = (undefined8 *)kmalloc_trace(_DAT_001020a0,0xdc0,0x10);
    if (puVar3 != (undefined8 *)0x0) {
      puVar6 = (undefined4 *)((long)puVar3 + 0xc);
      uVar5 = 2;
      *puVar3 = 0x600000003;
      *(undefined4 *)(puVar3 + 1) = 0xf;
      goto LAB_0010054c;
    }
    puVar4 = &DAT_00100e5a;
  }
  else {
    puVar3 = (undefined8 *)kmalloc_trace(_DAT_001020a0,0xdc0,0x18);
    if (puVar3 == (undefined8 *)0x0) {
      puVar4 = &DAT_00100f23;
    }
    else {
      puVar6 = (undefined4 *)((long)puVar3 + 0x14);
      uVar5 = 3;
      *puVar3 = 0x600000003;
      puVar3[1] = 0x60000000f;
      *(undefined4 *)(puVar3 + 2) = 0x2b;
LAB_0010054c:
      *puVar6 = 6;
      iVar2 = qcom_scm_assign_mem(param_2,param_3,&local_48,puVar3,uVar5);
      kfree(puVar3);
      if (iVar2 == 0) goto LAB_00100578;
      if (iVar2 != -0x16) {
        _printk(&DAT_00100b4e,"setup_shared_ram_perms",&uStack_40,param_3,iVar2);
        goto LAB_00100578;
      }
      puVar4 = &DAT_00100c1d;
    }
  }
  _printk(puVar4,"setup_shared_ram_perms");
LAB_00100578:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sharedmem_mmap @ 00100608 size=248
// signature: undefined sharedmem_mmap(void)
// callers: []
//------------------------------------------------------------

int sharedmem_mmap(long param_1,long *param_2)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar5 = param_2[0x10];
  if ((uVar5 < 5) && (*(long *)(param_1 + uVar5 * 0x38 + 0x30) != 0)) {
    lVar1 = *param_2;
    uVar4 = param_2[1] - lVar1;
    if (*(ulong *)(param_1 + 0x18 + uVar5 * 0x38 + 0x18) < uVar4) {
      _printk(&DAT_00100bbd,"sharedmem_mmap",param_2[1],lVar1,uVar4);
      return -0x16;
    }
    param_2[3] = param_2[3] & 0xffffffffffffffe3U | 0x60000000000008;
    iVar2 = remap_pfn_range(param_2,lVar1,*(ulong *)(param_1 + 0x18 + uVar5 * 0x38 + 8) >> 0xc,uVar4
                           );
    if (iVar2 == 0) {
      return 0;
    }
    puVar3 = &DAT_00100dee;
  }
  else {
    puVar3 = &DAT_00100cb3;
    iVar2 = -0x16;
  }
  _printk(puVar3,"sharedmem_mmap",iVar2);
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00100704 size=88
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&msm_sharedmem_driver,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_00100d18,"msm_sharedmem_init");
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100760 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_sharedmem_driver);
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
// _printk @ 00102008 size=1
// signature: undefined _printk(void)
// callers: [init_module, setup_shared_ram_perms, sharedmem_mmap, msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00102010 size=1
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
// platform_get_resource @ 00102018 size=1
// signature: undefined platform_get_resource(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102028 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102030 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_lookup @ 00102038 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 00102040 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102048 size=1
// signature: undefined of_find_property(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00102050 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __uio_register_device @ 00102058 size=1
// signature: undefined __uio_register_device(void)
// callers: [msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __uio_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [setup_shared_ram_perms, msm_sharedmem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uio_unregister_device @ 00102068 size=1
// signature: undefined uio_unregister_device(void)
// callers: [msm_sharedmem_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uio_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102078 size=1
// signature: undefined kmalloc_trace(void)
// callers: [setup_shared_ram_perms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00102080 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [setup_shared_ram_perms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102088 size=1
// signature: undefined kfree(void)
// callers: [setup_shared_ram_perms]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remap_pfn_range @ 00102090 size=1
// signature: undefined remap_pfn_range(void)
// callers: [sharedmem_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



