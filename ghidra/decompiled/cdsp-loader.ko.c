// Decompiled by Ghidra 12.2
// Program: cdsp-loader.ko
// Image base: 00100000

//------------------------------------------------------------
// cdsp_loader_probe @ 00100124 size=488
// signature: undefined cdsp_loader_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cdsp_loader_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_4c = 0;
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,rproc-handle",&local_4c);
  if (lVar5 == 0) {
    _dev_err(lVar1,"%s: error reading rproc phandle\n","cdsp_loader_probe");
    iVar4 = -0x207;
    goto LAB_001002ac;
  }
  uVar2 = (**(uint **)(lVar5 + 0x10) & 0xff00ff00) >> 8 |
          (**(uint **)(lVar5 + 0x10) & 0xff00ff) << 8;
  lVar5 = rproc_get_by_phandle(uVar2 >> 0x10 | uVar2 << 0x10);
  if (lVar5 == 0) {
    _dev_err(lVar1,"%s: rproc not found\n","cdsp_loader_probe");
    iVar4 = -0x205;
    goto LAB_001002ac;
  }
  cdsp_private = 0;
  puVar6 = (undefined8 *)devm_kmalloc(lVar1,0x18,0xdc0);
  if (puVar6 == (undefined8 *)0x0) {
    iVar4 = -0xc;
  }
  else {
    *(undefined8 **)(param_1 + 0xa8) = puVar6;
    *puVar6 = 0;
    puVar6[1] = 0;
    lVar5 = devm_kmalloc(lVar1,0x28,0xdc0);
    puVar6[2] = lVar5;
    uVar3 = _kernel_kobj;
    if (lVar5 == 0) {
LAB_00100264:
      iVar4 = -0xc;
      lVar5 = puVar6[1];
    }
    else {
      *(undefined ***)(lVar5 + 0x18) = &attrs;
      lVar5 = kobject_create_and_add("boot_cdsp",uVar3);
      puVar6[1] = lVar5;
      if (lVar5 == 0) {
        _dev_err(lVar1,"%s: sysfs create and add failed\n","cdsp_loader_init_sysfs");
        goto LAB_00100264;
      }
      iVar4 = sysfs_create_group(lVar5,puVar6[2]);
      if (iVar4 == 0) {
        cdsp_private = param_1;
        goto LAB_001002ac;
      }
      _dev_err(lVar1,"%s: sysfs create group failed %d\n","cdsp_loader_init_sysfs",iVar4);
      lVar5 = puVar6[1];
    }
    if (lVar5 != 0) {
      kobject_del();
      puVar6[1] = 0;
    }
    _dev_err(lVar1,"%s failed with ret %d\n","cdsp_loader_init_sysfs",iVar4);
  }
  _dev_err(lVar1,"%s: Error in initing sysfs\n","cdsp_loader_probe");
LAB_001002ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// cdsp_loader_remove @ 00100310 size=96
// signature: undefined cdsp_loader_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsp_loader_remove(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  if (plVar1 != (long *)0x0) {
    if (*plVar1 != 0) {
      rproc_shutdown();
      *plVar1 = 0;
      cdsp_state = 0;
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
// cdsp_boot_store @ 00100374 size=520
// signature: undefined cdsp_boot_store(void)
// callers: []
//------------------------------------------------------------

long cdsp_boot_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  long *plVar5;
  int local_4c;
  char *local_48;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  iVar2 = kstrtouint(param_3,0,&local_4c);
  lVar1 = cdsp_private;
  if (iVar2 != 0) {
    param_4 = (long)iVar2;
    goto LAB_001003b8;
  }
  if (local_4c == 0) {
    plVar5 = *(long **)(cdsp_private + 0xa8);
    if ((plVar5 != (long *)0x0) && (*plVar5 != 0)) {
      rproc_shutdown();
      *plVar5 = 0;
      cdsp_state = 0;
    }
    goto LAB_001003b8;
  }
  if (local_4c != 1) goto LAB_001003b8;
  local_3c = 0;
  local_48 = (char *)0x0;
  if (cdsp_private == 0) {
    _printk(&DAT_00100ade,"cdsp_loader_do");
    goto LAB_001003b8;
  }
  if (*(long *)(cdsp_private + 0x2f8) == 0) {
    pcVar4 = "%s: Device tree information missing\n";
LAB_001004f4:
    _dev_err(lVar1 + 0x10,pcVar4,"cdsp_loader_do");
  }
  else {
    iVar2 = of_property_read_string
                      (*(long *)(cdsp_private + 0x2f8),"qcom,proc-img-to-load",&local_48);
    if (iVar2 == 0) {
      iVar2 = strcmp(local_48,"cdsp");
      if (iVar2 == 0) {
        if ((cdsp_state & 1) != 0) goto LAB_001003b8;
        plVar5 = *(long **)(lVar1 + 0xa8);
        if (plVar5 == (long *)0x0) {
          pcVar4 = "%s: Private data get failed\n";
          goto LAB_001004f4;
        }
        iVar2 = of_property_read_variable_u32_array
                          (*(undefined8 *)(lVar1 + 0x2f8),"qcom,rproc-handle",&local_3c,1,0);
        if (iVar2 < 0) {
          _printk(&DAT_00100b7c,"cdsp_loader_do",iVar2);
          pcVar4 = "error reading rproc phandle\n";
        }
        else {
          lVar3 = rproc_get_by_phandle(local_3c);
          *plVar5 = lVar3;
          if (lVar3 != 0) {
            iVar2 = rproc_boot();
            if (iVar2 == 0) {
              cdsp_state = 1;
              goto LAB_001003b8;
            }
            _dev_err(lVar1 + 0x10,"%s: rproc_boot failed with error %d\n","cdsp_loader_do",iVar2);
            goto LAB_0010055c;
          }
          pcVar4 = "rproc not found\n";
        }
        _dev_err(lVar1 + 0x10,pcVar4);
      }
    }
  }
LAB_0010055c:
  _dev_err(lVar1 + 0x10,"%s: CDSP image loading failed\n","cdsp_loader_do");
LAB_001003b8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00100580 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cdsp_loader_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001005b0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cdsp_loader_driver);
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
// callers: [cdsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 00102018 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [cdsp_loader_probe, cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [cdsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00102030 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [cdsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00102038 size=1
// signature: undefined sysfs_create_group(void)
// callers: [cdsp_loader_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [cdsp_loader_probe, cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_del @ 00102048 size=1
// signature: undefined kobject_del(void)
// callers: [cdsp_loader_probe, cdsp_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cdsp_loader_probe, cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_shutdown @ 00102058 size=1
// signature: undefined rproc_shutdown(void)
// callers: [cdsp_loader_remove, cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00102060 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [cdsp_loader_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00102068 size=1
// signature: undefined kstrtouint(void)
// callers: [cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00102070 size=1
// signature: undefined of_property_read_string(void)
// callers: [cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102078 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102080 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_boot @ 00102088 size=1
// signature: undefined rproc_boot(void)
// callers: [cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_boot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102090 size=1
// signature: undefined _printk(void)
// callers: [cdsp_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



