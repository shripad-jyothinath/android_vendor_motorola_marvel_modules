// Decompiled by Ghidra 12.2
// Program: gh_tlmm_vm_mem_access.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_tlmm_vm_mem_access_probe @ 0010015c size=1020
// signature: undefined gh_tlmm_vm_mem_access_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_tlmm_vm_mem_access_probe(long param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  undefined2 local_64 [2];
  undefined4 local_60;
  int local_5c;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  gh_tlmm_dev = param_1 + 0x10;
  uVar8 = *(undefined8 *)(param_1 + 0x2f8);
  local_60 = 0;
  local_64[0] = 0;
  local_5c = 0;
  lVar5 = of_find_property(uVar8,"qcom,master",0);
  if (lVar5 == 0) {
    iVar2 = of_property_read_u32_index(uVar8,"qcom,rm-mem-handle",1,&local_5c);
    if (iVar2 == 0) {
      DAT_00101014 = local_5c;
      goto LAB_001001e4;
    }
    _dev_err(gh_tlmm_dev,"Failed to receive mem handle rc:%d\n",iVar2);
LAB_00100480:
    _dev_err(gh_tlmm_dev,"Failed to populate TLMM VM info\n");
  }
  else {
LAB_001001e4:
    DAT_00101010 = 2;
    uVar3 = of_count_phandle_with_args(uVar8,"tlmm-vm-gpio-list","#gpio-cells");
    if ((int)uVar3 < 0) {
      _dev_err(gh_tlmm_dev,"Invalid number of gpios specified\n");
      goto LAB_00100480;
    }
    uVar7 = (ulong)uVar3 * 4;
    lVar5 = __kmalloc(uVar7,0xcc0);
    if (lVar5 == 0) goto LAB_00100480;
    if (uVar3 != 0) {
      iVar2 = 0;
      uVar10 = 0;
      do {
        iVar4 = of_get_named_gpio_flags(uVar8,"tlmm-vm-gpio-list",iVar2,0);
        if (iVar4 < 0) {
          _dev_err(gh_tlmm_dev,"Failed to receive shared gpios %d\n");
          goto LAB_00100478;
        }
        if ((uVar7 == uVar10) || (uVar7 <= uVar10)) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x100554);
          (*pcVar1)();
        }
        *(int *)(lVar5 + uVar10) = iVar4;
        uVar10 = uVar10 + 4;
        iVar2 = iVar2 + 1;
      } while (uVar7 != uVar10);
    }
    DAT_00101028 = uVar3;
    DAT_00101018 = __kmalloc(uVar7,0xdc0);
    if (DAT_00101018 == 0) {
LAB_00100478:
      kfree(lVar5);
      goto LAB_00100480;
    }
    DAT_00101020 = __kmalloc(uVar7,0xdc0);
    if (DAT_00101020 == 0) {
LAB_0010046c:
      kfree(DAT_00101018);
      goto LAB_00100478;
    }
    piVar6 = (int *)kmalloc_trace(_gh_rm_mem_release,0xdc0,0x60);
    if (piVar6 == (int *)0x0) {
LAB_00100464:
      kfree(DAT_00101020);
      goto LAB_0010046c;
    }
    if (uVar3 != 0) {
      lVar9 = 0;
      do {
        uVar7 = msm_gpio_get_pin_address(*(undefined4 *)(lVar5 + lVar9),piVar6);
        if ((uVar7 & 1) == 0) {
          _dev_err(gh_tlmm_dev,"Invalid gpio\n");
          kfree(piVar6);
          goto LAB_00100464;
        }
        *(int *)(DAT_00101018 + lVar9) = (int)*(undefined8 *)piVar6;
        *(int *)(DAT_00101020 + lVar9) = (piVar6[2] - *piVar6) + 1;
        lVar9 = lVar9 + 4;
      } while ((ulong)uVar3 * 4 != lVar9);
    }
    kfree(piVar6);
    kfree(lVar5);
    uVar7 = of_find_compatible_node(0,0,"qcom,gunyah-vm-id-1.0");
    if (((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) &&
       ((uVar7 = of_find_compatible_node(0,0,"qcom,haven-vm-id-1.0"), uVar7 == 0 ||
        (0xfffffffffffff000 < uVar7)))) {
      _dev_err(gh_tlmm_dev,"Could not find vm-id node\n");
      uVar8 = 0xffffffed;
      goto LAB_00100494;
    }
    iVar2 = of_property_read_variable_u32_array(uVar7,"qcom,owner-vmid",&local_60,1,0);
    if (-1 < iVar2) {
      uVar8 = ghd_rm_get_vmid(2,local_64);
      if ((int)uVar8 != 0) goto LAB_00100494;
      if (DAT_00101014 == 0) {
        _dev_err(gh_tlmm_dev,"Invalid memory handle\n");
      }
      else {
        iVar2 = gh_rm_mem_release(DAT_00101014,0);
        if (iVar2 != 0) {
          _dev_err(gh_tlmm_dev,"VM mem release failed rc:%d\n",iVar2);
        }
        iVar2 = gh_rm_mem_notify(DAT_00101014,2,3,0);
        if (iVar2 != 0) {
          _dev_err(gh_tlmm_dev,"Failed to notify mem release to PVM rc:%d\n",iVar2);
        }
        DAT_00101014 = 0;
      }
LAB_0010041c:
      uVar8 = 0;
      goto LAB_00100494;
    }
    uVar7 = gh_mem_notifier_register(3,gh_tlmm_vm_mem_on_release_handler,&gh_tlmm_vm_info_data);
    if (uVar7 < 0xfffffffffffff001) {
      _DAT_00101008 = 0x7fffffff;
      gh_tlmm_vm_info_data = gh_guest_memshare_nb_handler;
      _DAT_00101030 = uVar7;
      uVar8 = gh_rm_register_notifier(&gh_tlmm_vm_info_data);
      if ((int)uVar8 != 0) goto LAB_00100494;
      goto LAB_0010041c;
    }
    _dev_err(gh_tlmm_dev,"Failed to register on release notifier%d\n");
  }
  uVar8 = 0xffffffea;
LAB_00100494:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// gh_tlmm_vm_mem_access_remove @ 0010055c size=76
// signature: undefined gh_tlmm_vm_mem_access_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gh_tlmm_vm_mem_access_remove(long param_1)

{
  long lVar1;
  
  lVar1 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,master",0);
  if (lVar1 != 0) {
    gh_mem_notifier_unregister(_DAT_00101030);
  }
  gh_rm_unregister_notifier(&gh_tlmm_vm_info_data);
  return 0;
}



//------------------------------------------------------------
// gh_tlmm_vm_mem_on_release_handler @ 001005ac size=220
// signature: undefined gh_tlmm_vm_mem_on_release_handler(void)
// callers: []
//------------------------------------------------------------

void gh_tlmm_vm_mem_on_release_handler(int param_1,long param_2,long param_3,int *param_4)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == 0x51100012) {
    if (param_1 == 3) {
      if ((param_3 == 0) || (param_4 == (int *)0x0)) {
        pcVar2 = "Invalid data or notification message\n";
      }
      else {
        iVar1 = *param_4;
        if (iVar1 == *(int *)(param_3 + 0x1c)) {
          if (iVar1 != 0) {
            iVar1 = ghd_rm_mem_reclaim(iVar1,0);
            if (iVar1 != 0) {
              _dev_err(gh_tlmm_dev,"VM mem reclaim failed rc:%d\n",iVar1);
            }
            *(undefined4 *)(param_3 + 0x1c) = 0;
            return;
          }
          pcVar2 = "Invalid memory handle\n";
        }
        else {
          pcVar2 = "Invalid mem handle detected\n";
        }
      }
    }
    else {
      pcVar2 = "Invalid tag\n";
    }
  }
  else {
    pcVar2 = "Invalid notification type\n";
  }
  _dev_err(gh_tlmm_dev,pcVar2);
  return;
}



//------------------------------------------------------------
// gh_guest_memshare_nb_handler @ 0010068c size=592
// signature: undefined gh_guest_memshare_nb_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gh_guest_memshare_nb_handler(undefined8 param_1,long param_2,short *param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  short local_48 [2];
  undefined4 local_44;
  undefined2 local_40 [2];
  undefined2 local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48[0] = 0;
  if (((param_2 != 0x56100008) || (ghd_rm_get_vmid(2,local_48), local_48[0] != *param_3)) ||
     ((char)param_3[2] != '\x02')) goto LAB_00100888;
  local_44 = 0;
  local_3c[0] = 0;
  local_40[0] = 0;
  ghd_rm_get_vmid(2,local_3c);
  ghd_rm_get_vmid(1,local_40);
  puVar7 = (undefined4 *)kmalloc_trace(_ghd_rm_get_vmid,0xdc0,0xc);
  if (puVar7 == (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0xc;
  }
  else {
    *puVar7 = 2;
    *(undefined2 *)(puVar7 + 1) = local_3c[0];
    *(undefined1 *)((long)puVar7 + 6) = 4;
    *(undefined2 *)(puVar7 + 2) = local_40[0];
    *(undefined1 *)((long)puVar7 + 10) = 6;
    if ((undefined4 *)0xfffffffffffff000 < puVar7) {
      _dev_err(gh_tlmm_dev,"Failed to get acl of IO memories for TLMM\n");
      goto LAB_00100888;
    }
  }
  uVar11 = (ulong)DAT_00101028 << 4 | 4;
  puVar8 = (undefined2 *)__kmalloc(uVar11,0xdc0);
  uVar4 = DAT_00101028;
  if (puVar8 == (undefined2 *)0x0) {
    puVar8 = (undefined2 *)0xc;
LAB_00100848:
    iVar6 = ghd_rm_mem_share(1,0,8,puVar7,puVar8,0,&local_44);
    if (iVar6 == 0) {
      DAT_00101014 = local_44;
    }
    else {
      _dev_err(gh_tlmm_dev,"Failed to share IO memories for TLMM rc:%d\n",iVar6);
    }
    kfree(puVar8);
  }
  else {
    *puVar8 = (short)DAT_00101028;
    lVar3 = DAT_00101020;
    lVar2 = DAT_00101018;
    if (uVar4 != 0) {
      uVar9 = 0;
      do {
        lVar10 = (long)(int)uVar9;
        if (((uVar11 <= (lVar10 << 4 | 4U)) || (uVar11 <= (lVar10 << 4 | 4U))) ||
           ((*(ulong *)(puVar8 + lVar10 * 8 + 2) = (ulong)*(uint *)(lVar2 + lVar10 * 4),
            uVar11 < (-(uVar9 >> 0x1f) & 0xfffffff000000000 | uVar9 << 4 | 0xc) ||
            (uVar11 < (lVar10 << 4 | 0xcU))))) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x1008d8);
          (*pcVar5)();
        }
        uVar1 = (int)uVar9 + 1;
        uVar9 = (ulong)uVar1;
        *(ulong *)(puVar8 + lVar10 * 8 + 6) = (ulong)*(uint *)(lVar3 + lVar10 * 4);
      } while (uVar4 != uVar1);
    }
    if (puVar8 < (undefined2 *)0xfffffffffffff001) goto LAB_00100848;
    _dev_err(gh_tlmm_dev,"Failed to get sgl of IO memories for TLMM\n");
  }
  kfree(puVar7);
LAB_00100888:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 001008e0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gh_tlmm_vm_mem_access_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100910 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gh_tlmm_vm_mem_access_driver);
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
// of_find_property @ 00102010 size=1
// signature: undefined of_find_property(void)
// callers: [gh_tlmm_vm_mem_access_remove, gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00102018 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00102020 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102028 size=1
// signature: undefined __kmalloc(void)
// callers: [gh_tlmm_vm_mem_access_probe, gh_guest_memshare_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00102030 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102040 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_tlmm_vm_mem_access_probe, gh_guest_memshare_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_gpio_get_pin_address @ 00102048 size=1
// signature: undefined msm_gpio_get_pin_address(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_gpio_get_pin_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102050 size=1
// signature: undefined kfree(void)
// callers: [gh_tlmm_vm_mem_access_probe, gh_guest_memshare_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00102058 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102060 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 00102068 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_tlmm_vm_mem_access_probe, gh_guest_memshare_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_release @ 00102070 size=1
// signature: undefined gh_rm_mem_release(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_mem_notify @ 00102078 size=1
// signature: undefined gh_rm_mem_notify(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_mem_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_mem_notifier_register @ 00102080 size=1
// signature: undefined gh_mem_notifier_register(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_mem_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00102088 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [gh_tlmm_vm_mem_access_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102090 size=1
// signature: undefined _dev_err(void)
// callers: [gh_tlmm_vm_mem_access_probe, gh_guest_memshare_nb_handler, gh_tlmm_vm_mem_on_release_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_tlmm_vm_mem_access_probe, gh_guest_memshare_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_mem_notifier_unregister @ 001020a0 size=1
// signature: undefined gh_mem_notifier_unregister(void)
// callers: [gh_tlmm_vm_mem_access_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_mem_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 001020a8 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [gh_tlmm_vm_mem_access_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_reclaim @ 001020b0 size=1
// signature: undefined ghd_rm_mem_reclaim(void)
// callers: [gh_tlmm_vm_mem_on_release_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_mem_share @ 001020b8 size=1
// signature: undefined ghd_rm_mem_share(void)
// callers: [gh_guest_memshare_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_mem_share(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



