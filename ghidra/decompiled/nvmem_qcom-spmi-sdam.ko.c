// Decompiled by Ghidra 12.2
// Program: nvmem_qcom-spmi-sdam.ko
// Image base: 00100000

//------------------------------------------------------------
// sdam_probe @ 0010012c size=404
// signature: undefined sdam_probe(void)
// callers: []
//------------------------------------------------------------

void sdam_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  plVar3 = (long *)devm_kmalloc(lVar1,0xa8,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar6 = 0xfffffff4;
    goto LAB_00100234;
  }
  lVar4 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
  *plVar3 = lVar4;
  if (lVar4 == 0) {
    _dev_err(lVar1,"Failed to get regmap handle\n");
LAB_001002b4:
    uVar6 = 0xfffffffa;
  }
  else {
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),&DAT_0010090e,plVar3 + 0x14,1,0);
    if (iVar2 < 0) {
      pcVar7 = "Failed to get SDAM base, rc=%d\n";
    }
    else {
      iVar2 = regmap_read(*plVar3,(int)plVar3[0x14] + 0x44,&local_3c);
      if (-1 < iVar2) {
        plVar3[2] = (long)"spmi_sdam";
        plVar3[4] = (long)&__this_module;
        *(int *)((long)plVar3 + 0xa4) = local_3c << 5;
        *(int *)(plVar3 + 0xf) = local_3c << 5;
        *(undefined8 *)((long)plVar3 + 0x7c) = 0x100000001;
        *(undefined4 *)(plVar3 + 3) = 0xfffffffe;
        plVar3[1] = lVar1;
        plVar3[0xc] = (long)sdam_read;
        plVar3[0xd] = (long)sdam_write;
        plVar3[0x11] = (long)plVar3;
        uVar5 = devm_nvmem_register(lVar1);
        if (uVar5 < 0xfffffffffffff001) {
          uVar6 = 0;
          goto LAB_00100234;
        }
        _dev_err(lVar1,"Failed to register SDAM nvmem device rc=%ld\n",uVar5);
        goto LAB_001002b4;
      }
      pcVar7 = "Failed to read SDAM_SIZE rc=%d\n";
    }
    _dev_err(lVar1,pcVar7,iVar2);
    uVar6 = 0xffffffea;
  }
LAB_00100234:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// sdam_read @ 001002c4 size=212
// signature: undefined sdam_read(void)
// callers: []
//------------------------------------------------------------

int sdam_read(undefined8 *param_1,uint param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = param_1[1];
  if ((param_4 == 0) ||
     ((((param_2 < 0x40 || (uVar1 = *(int *)((long)param_1 + 0xa4) + 0x3f, uVar1 < param_2)) ||
       ((ulong)uVar1 < (param_4 + (ulong)param_2) - 1)) && ((1 < param_2 - 0xe5 || (param_4 != 1))))
     )) {
    _dev_err(uVar3,"Invalid SDAM offset %#x len=%zd\n",param_2,param_4);
    iVar2 = -0x16;
  }
  else {
    iVar2 = regmap_bulk_read(*param_1,*(int *)(param_1 + 0x14) + param_2,param_3,param_4);
    if (iVar2 < 0) {
      _dev_err(uVar3,"Failed to read SDAM offset %#x len=%zd, rc=%d\n",param_2,param_4,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// sdam_write @ 0010039c size=276
// signature: undefined sdam_write(void)
// callers: []
//------------------------------------------------------------

int sdam_write(undefined8 *param_1,uint param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  uVar5 = param_1[1];
  if (param_4 == 0) {
LAB_00100470:
    pcVar4 = "Invalid SDAM offset %#x len=%zd\n";
LAB_00100478:
    _dev_err(uVar5,pcVar4,param_2,param_4);
    iVar3 = -0x16;
  }
  else {
    if (((param_2 < 0x40) || (uVar1 = *(int *)((long)param_1 + 0xa4) + 0x3f, uVar1 < param_2)) ||
       (uVar2 = (ulong)param_2 + param_4, (ulong)uVar1 < uVar2 - 1)) {
      if ((1 < param_2 - 0xe5) || (param_4 != 1)) goto LAB_00100470;
    }
    else if ((((param_2 < 0x41) && (0x40 < uVar2)) || ((param_2 < 0x42 && (0x41 < uVar2)))) ||
            ((param_2 < 0x45 && (0x44 < uVar2)))) {
      pcVar4 = "Invalid write offset %#x len=%zd\n";
      goto LAB_00100478;
    }
    iVar3 = regmap_bulk_write(*param_1,*(int *)(param_1 + 0x14) + param_2,param_3,param_4);
    if (iVar3 < 0) {
      _dev_err(uVar5,"Failed to write SDAM offset %#x len=%zd, rc=%d\n",param_2,param_4,iVar3);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// init_module @ 001004b4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&sdam_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001004e4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&sdam_driver);
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [sdam_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00102018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [sdam_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [sdam_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00102028 size=1
// signature: undefined regmap_read(void)
// callers: [sdam_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_register @ 00102030 size=1
// signature: undefined devm_nvmem_register(void)
// callers: [sdam_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102038 size=1
// signature: undefined _dev_err(void)
// callers: [sdam_probe, sdam_write, sdam_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [sdam_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00102048 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [sdam_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 00102050 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [sdam_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



