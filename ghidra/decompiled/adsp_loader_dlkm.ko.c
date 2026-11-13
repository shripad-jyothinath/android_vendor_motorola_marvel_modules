// Decompiled by Ghidra 12.2
// Program: adsp_loader_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// adsp_loader_probe @ 00100194 size=1388
// signature: undefined adsp_loader_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int adsp_loader_probe(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  void *__src;
  long lVar9;
  int *piVar10;
  size_t sVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long *plVar15;
  undefined4 local_8c;
  char *local_88;
  char *local_80;
  int local_78;
  int local_74;
  size_t local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = param_1 + 0x10;
  local_70 = 0;
  local_74 = 0;
  local_78 = 0;
  local_88 = (char *)0x0;
  local_80 = (char *)0x0;
  local_8c = 0;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,rproc-handle",&local_8c);
  if (lVar5 == 0) {
    _dev_err(lVar9,"Missing remotproc handle\n");
    iVar2 = -0x207;
    goto LAB_00100464;
  }
  uVar3 = (**(uint **)(lVar5 + 0x10) & 0xff00ff00) >> 8 |
          (**(uint **)(lVar5 + 0x10) & 0xff00ff) << 8;
  lVar5 = rproc_get_by_phandle(uVar3 >> 0x10 | uVar3 << 0x10);
  if (lVar5 == 0) {
    _dev_err(lVar9,"fail to get rproc\n");
    iVar2 = -0x205;
    goto LAB_00100464;
  }
  adsp_private = 0;
  puVar6 = (undefined8 *)devm_kmalloc(lVar9,0x28,0xdc0);
  if (puVar6 == (undefined8 *)0x0) {
    iVar2 = -0xc;
  }
  else {
    *(undefined8 **)(param_1 + 0xa8) = puVar6;
    *puVar6 = 0;
    puVar6[1] = 0;
    lVar7 = devm_kmalloc(lVar9,0x28,0xdc0);
    puVar6[2] = lVar7;
    uVar1 = _kernel_kobj;
    if (lVar7 == 0) {
LAB_00100430:
      iVar2 = -0xc;
      lVar7 = puVar6[1];
    }
    else {
      *(undefined ***)(lVar7 + 0x18) = &attrs;
      lVar7 = kobject_create_and_add("boot_adsp",uVar1);
      puVar6[1] = lVar7;
      if (lVar7 == 0) {
        _dev_err(lVar9,"%s: sysfs create and add failed\n","adsp_loader_init_sysfs");
        goto LAB_00100430;
      }
      iVar2 = sysfs_create_group(lVar7,puVar6[2]);
      if (iVar2 == 0) {
        plVar15 = *(long **)(param_1 + 0xa8);
        adsp_private = param_1;
        *plVar15 = lVar5;
        uVar8 = nvmem_cell_get(lVar9,"adsp_variant");
        if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"adsp-fuse-not-supported",&local_78,1,
                             0);
          if ((-1 < iVar2) &&
             ((local_78 != 0 &&
              (iVar2 = of_property_read_string
                                 (*(undefined8 *)(param_1 + 0x2f8),"adsp-fw-name",&local_80),
              -1 < iVar2)))) {
            sVar11 = strlen(local_80);
            lVar7 = (long)((int)sVar11 + 1);
            lVar5 = devm_kmalloc(lVar9,lVar7,0xdc0);
            plVar15[3] = lVar5;
            if (lVar5 != 0) {
              strlcpy(lVar5,local_80,lVar7);
              iVar2 = of_property_read_string
                                (*(undefined8 *)(param_1 + 0x2f8),"adsp-dtb-name",&local_88);
              if (-1 < iVar2) {
                sVar11 = strlen(local_88);
                lVar5 = (long)((int)sVar11 + 1);
                lVar9 = devm_kmalloc(lVar9,lVar5,0xdc0);
                plVar15[4] = lVar9;
                if (lVar9 != 0) {
                  strscpy(lVar9,local_88,lVar5);
                }
              }
            }
          }
        }
        else {
          __src = (void *)nvmem_cell_read(uVar8,&local_70);
          nvmem_cell_put(uVar8);
          if ((__src != (void *)0x0) && (__src < (void *)0xfffffffffffff001)) {
            if (local_70 - 5 < 0xfffffffffffffffb || local_70 == 0) {
              kfree(__src);
            }
            else {
              memcpy(&local_74,__src,local_70);
              iVar2 = local_74;
              _dev_info(param_1 + 0x10,"%s: adsp variant fuse reg value: 0x%x\n","adsp_loader_probe"
                        ,local_74);
              kfree(__src);
              uVar3 = of_property_read_string_helper
                                (*(undefined8 *)(param_1 + 0x2f8),"adsp-fw-names",0,0,0);
              if (0xfffffffb < uVar3 - 5) {
                uVar8 = (ulong)uVar3;
                piVar10 = (int *)devm_kmalloc(lVar9,uVar8 << 2,0xdc0);
                if (piVar10 != (int *)0x0) {
                  iVar4 = of_property_read_variable_u32_array
                                    (*(undefined8 *)(param_1 + 0x2f8),"adsp-fw-bit-values",piVar10,
                                     uVar8,0);
                  if (iVar4 < 0) {
                    lVar5 = 0;
                  }
                  else {
                    lVar5 = devm_kmalloc(lVar9,uVar8 << 3,0xdc0);
                    if ((lVar5 != 0) &&
                       (iVar4 = of_property_read_string_helper
                                          (*(undefined8 *)(param_1 + 0x2f8),"adsp-fw-names",lVar5,
                                           uVar8,0), -1 < iVar4)) {
                      lVar7 = devm_kmalloc(lVar9,uVar8 << 3,0xdc0);
                      iVar4 = of_property_read_string_helper
                                        (*(undefined8 *)(param_1 + 0x2f8),"adsp-dtb-fw-names",lVar7,
                                         uVar8,0);
                      if (-1 < iVar4) {
                        if (*piVar10 == iVar2) {
                          lVar14 = 0;
                        }
                        else {
                          if (uVar3 == 1) goto LAB_001005f0;
                          if (piVar10[1] == iVar2) {
                            lVar14 = 1;
                          }
                          else {
                            if (uVar3 == 2) goto LAB_001005f0;
                            if (piVar10[2] == iVar2) {
                              lVar14 = 2;
                            }
                            else {
                              if ((uVar3 == 3) || (piVar10[3] != iVar2)) goto LAB_001005f0;
                              lVar14 = 3;
                            }
                          }
                        }
                        sVar11 = strlen(*(char **)(lVar5 + lVar14 * 8));
                        lVar13 = (long)((int)sVar11 + 1);
                        lVar12 = devm_kmalloc(lVar9,lVar13,0xdc0);
                        plVar15[3] = lVar12;
                        if (lVar12 != 0) {
                          strlcpy(lVar12,*(undefined8 *)(lVar5 + lVar14 * 8),lVar13);
                          sVar11 = strlen(*(char **)(lVar7 + lVar14 * 8));
                          lVar13 = (long)((int)sVar11 + 1);
                          lVar12 = devm_kmalloc(lVar9,lVar13,0xdc0);
                          plVar15[4] = lVar12;
                          if (lVar12 != 0) {
                            strscpy(lVar12,*(undefined8 *)(lVar7 + lVar14 * 8),lVar13);
                          }
                        }
                      }
                    }
                  }
LAB_001005f0:
                  adsp_ldr_work = 0xfffffffe0;
                  DAT_00101348 = &DAT_00101348;
                  DAT_00101350 = &DAT_00101348;
                  DAT_00101358 = adsp_load_fw;
                  devm_kfree(lVar9,piVar10);
                  iVar2 = 0;
                  if (lVar5 != 0) {
                    devm_kfree(lVar9,lVar5);
                    iVar2 = 0;
                  }
                  goto LAB_00100464;
                }
              }
            }
          }
        }
        iVar2 = 0;
        adsp_ldr_work = 0xfffffffe0;
        DAT_00101348 = &DAT_00101348;
        DAT_00101350 = &DAT_00101348;
        DAT_00101358 = adsp_load_fw;
        goto LAB_00100464;
      }
      _dev_err(lVar9,"%s: sysfs create group failed %d\n","adsp_loader_init_sysfs",iVar2);
      lVar7 = puVar6[1];
    }
    if (lVar7 != 0) {
      kobject_del();
      puVar6[1] = 0;
    }
  }
  _dev_err(lVar9,"%s: Error in initing sysfs\n","adsp_loader_probe");
  rproc_put(lVar5);
LAB_00100464:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// adsp_loader_remove @ 00100704 size=88
// signature: undefined adsp_loader_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 adsp_loader_remove(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  if (plVar1 != (long *)0x0) {
    if (*plVar1 != 0) {
      rproc_shutdown();
      *plVar1 = 0;
    }
    if (plVar1[1] != 0) {
      sysfs_remove_group(plVar1[1],plVar1[2]);
      kobject_del(plVar1[1]);
      plVar1[1] = 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// adsp_load_fw @ 00100760 size=612
// signature: undefined adsp_load_fw(void)
// callers: []
//------------------------------------------------------------

void adsp_load_fw(void)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  ulong *puVar7;
  undefined8 local_40;
  long local_38;
  
  lVar1 = adsp_private;
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  if (adsp_private == 0) {
    pcVar6 = "%s: Platform device null\n";
    lVar4 = 0x10;
LAB_00100954:
    _dev_err(lVar4,pcVar6,"adsp_load_fw");
  }
  else {
    if (*(long *)(adsp_private + 0x2f8) == 0) {
      pcVar6 = "%s: Device tree information missing\n";
LAB_0010094c:
      lVar4 = lVar1 + 0x10;
      goto LAB_00100954;
    }
    puVar7 = *(ulong **)(adsp_private + 0xa8);
    if (puVar7 == (ulong *)0x0) {
      pcVar6 = " %s: Private data get failed\n";
      goto LAB_0010094c;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(long *)(adsp_private + 0x2f8),"qcom,adsp-state",(long)&local_40 + 4,1,0);
    if (-1 < iVar2) {
      lVar4 = of_find_property(*(undefined8 *)(lVar1 + 0x2f8),"qcom,proc-img-to-load",&local_40);
      if (lVar4 == 0) {
LAB_00100828:
        uVar3 = spf_core_is_apm_ready(10000);
        local_40 = CONCAT44(uVar3,(undefined4)local_40) & 0x1ffffffff;
        if ((uVar3 & 1) != 0) goto LAB_00100970;
        if (puVar7[3] != 0) {
          _dev_info(lVar1 + 0x10,"%s: Load ADSP with fw name %s\n","adsp_load_fw");
          iVar2 = rproc_set_firmware(*puVar7,puVar7[3]);
          if (iVar2 == 0) goto LAB_001008e4;
          pcVar6 = "%s: rproc set firmware failed,\n";
LAB_001009a4:
          lVar4 = lVar1 + 0x10;
          goto LAB_00100954;
        }
        _dev_info(lVar1 + 0x10,"%s: Load default ADSP\n","adsp_load_fw");
LAB_001008e4:
        if (puVar7[4] == 0) {
          _dev_info(lVar1 + 0x10,"%s: Load default ADSP DTB\n","adsp_load_fw");
        }
        else {
          _dev_info(lVar1 + 0x10,"%s: Load ADSP DTB with fw name %s\n","adsp_load_fw");
          iVar2 = qcom_rproc_set_dtb_firmware(*puVar7,puVar7[4]);
          if (iVar2 != 0) {
            pcVar6 = "%s: rproc set dtb firmware failed,\n";
            goto LAB_001009a4;
          }
        }
        iVar2 = rproc_boot(*puVar7);
        if (iVar2 == 0) goto LAB_00100970;
      }
      else {
        uVar3 = (**(uint **)(lVar4 + 0x10) & 0xff00ff00) >> 8 |
                (**(uint **)(lVar4 + 0x10) & 0xff00ff) << 8;
        uVar5 = rproc_get_by_phandle(uVar3 >> 0x10 | uVar3 << 0x10);
        *puVar7 = uVar5;
        if (uVar5 == 0) goto LAB_00100958;
        iVar2 = strcmp(*(char **)(uVar5 + 0x18),"modem");
        if ((iVar2 != 0 || local_40._4_4_ != 0) ||
           ((iVar2 = rproc_boot(uVar5), *puVar7 < 0xfffffffffffff001 && (iVar2 == 0))))
        goto LAB_00100828;
      }
      pcVar6 = "%s: pil get failed,\n";
      goto LAB_0010094c;
    }
    _dev_err(lVar1 + 0x10,"%s: ADSP state = %x\n","adsp_load_fw",local_40._4_4_);
  }
LAB_00100958:
  _dev_err(lVar1 + 0x10,"%s: Q6 image loading failed\n","adsp_load_fw");
LAB_00100970:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// adsp_boot_store @ 001009c8 size=216
// signature: undefined adsp_boot_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adsp_boot_store(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = sscanf(param_3,"%du",&local_2c);
  if (iVar2 == 1) {
    if (local_2c == 0) {
      if ((*(long **)(adsp_private + 0xa8) != (long *)0x0) &&
         (**(long **)(adsp_private + 0xa8) != 0)) {
        rproc_shutdown();
      }
    }
    else if (local_2c == 1) {
      queue_work_on(0x20,_system_wq,&adsp_ldr_work);
    }
  }
  else {
    _printk(&DAT_00100fe9,"adsp_boot_store");
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// adsp_ssr_store @ 00100aa4 size=216
// signature: undefined adsp_ssr_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void adsp_ssr_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  int local_3c;
  long local_38;
  
  lVar1 = adsp_private;
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_3c = 0;
  plVar4 = *(long **)(adsp_private + 0xa8);
  if (plVar4 == (long *)0x0) {
    uVar3 = 0xffffffffffffffea;
  }
  else {
    iVar2 = kstrtoint(param_3,10,&local_3c);
    uVar3 = 0xffffffffffffffea;
    if (((-1 < iVar2) && (local_3c == 1)) && (lVar5 = *plVar4, lVar5 != 0)) {
      _dev_err(lVar1 + 0x10,"requesting for ADSP restart\n");
      rproc_shutdown(lVar5);
      queue_work_on(0x20,_system_wq,&adsp_ldr_work);
      uVar3 = param_4;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100b80 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&adsp_loader_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100bb0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&adsp_loader_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// of_find_property @ 00103010 size=1
// signature: undefined of_find_property(void)
// callers: [adsp_loader_probe, adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 00103018 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [adsp_loader_probe, adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00103030 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00103038 size=1
// signature: undefined sysfs_create_group(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 00103040 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 00103048 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 00103050 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103058 size=1
// signature: undefined kfree(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103060 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [adsp_loader_probe, adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00103068 size=1
// signature: undefined of_property_read_string(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00103070 size=1
// signature: size_t strlen(char * __s)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 00103078 size=1
// signature: undefined strlcpy(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103080 size=1
// signature: undefined strscpy(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103088 size=1
// signature: undefined _dev_err(void)
// callers: [adsp_ssr_store, adsp_loader_probe, adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_del @ 00103090 size=1
// signature: undefined kobject_del(void)
// callers: [adsp_loader_probe, adsp_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_put @ 00103098 size=1
// signature: undefined rproc_put(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001030a0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001030a8 size=1
// signature: undefined _dev_info(void)
// callers: [adsp_loader_probe, adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 001030b0 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 001030b8 size=1
// signature: undefined devm_kfree(void)
// callers: [adsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030c0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [adsp_boot_store, adsp_ssr_store, adsp_loader_probe, adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_shutdown @ 001030c8 size=1
// signature: undefined rproc_shutdown(void)
// callers: [adsp_boot_store, adsp_ssr_store, adsp_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 001030d0 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [adsp_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001030d8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_boot @ 001030e0 size=1
// signature: undefined rproc_boot(void)
// callers: [adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_boot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spf_core_is_apm_ready @ 001030e8 size=1
// signature: undefined spf_core_is_apm_ready(void)
// callers: [adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spf_core_is_apm_ready(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_set_firmware @ 001030f0 size=1
// signature: undefined rproc_set_firmware(void)
// callers: [adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_set_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_rproc_set_dtb_firmware @ 001030f8 size=1
// signature: undefined qcom_rproc_set_dtb_firmware(void)
// callers: [adsp_load_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_rproc_set_dtb_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00103100 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [adsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00103110 size=1
// signature: undefined queue_work_on(void)
// callers: [adsp_boot_store, adsp_ssr_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103118 size=1
// signature: undefined _printk(void)
// callers: [adsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00103120 size=1
// signature: undefined kstrtoint(void)
// callers: [adsp_ssr_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



