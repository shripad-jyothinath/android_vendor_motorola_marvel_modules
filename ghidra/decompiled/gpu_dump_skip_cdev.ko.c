// Decompiled by Ghidra 12.2
// Program: gpu_dump_skip_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// gpu_dump_skip_probe @ 0010013c size=360
// signature: undefined gpu_dump_skip_probe(void)
// callers: []
//------------------------------------------------------------

ulong gpu_dump_skip_probe(long param_1)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 local_58;
  char acStack_50 [8];
  char local_48 [8];
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  local_58 = 0;
  acStack_50 = (char  [8])s_gpu_dump_skip_cdev_001007f0._0_8_;
  local_48 = (char  [8])s_gpu_dump_skip_cdev_001007f0._8_8_;
  local_40 = 0x7665;
  puVar3 = (undefined1 *)devm_kmalloc(lVar1,0x28,0xdc0);
  if (puVar3 == (undefined1 *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_0010022c;
  }
  iVar2 = of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"nvmem-cell-names",&local_58);
  if (iVar2 == 0) {
    uVar4 = nvmem_cell_get(lVar1,local_58);
    *(ulong *)(puVar3 + 0x18) = uVar4;
    if (0xfffffffffffff000 < uVar4) {
      _dev_err(lVar1,"failed to get nvmem cell %s\n",local_58);
      goto LAB_0010022c;
    }
    lVar5 = of_find_compatible_node(0,0,"qcom,msm-imem-gpu-dump-skip");
    *(long *)(puVar3 + 0x20) = lVar5;
    if (lVar5 == 0) {
      uVar4 = 0xfffffffe;
      goto LAB_0010022c;
    }
    *puVar3 = 2;
    uVar4 = devm_thermal_of_cooling_device_register
                      (lVar1,uVar6,acStack_50,puVar3,&gpu_dump_skip_ops);
    *(ulong *)(puVar3 + 8) = uVar4;
    if (0xfffffffffffff000 < uVar4) {
      _dev_err(lVar1,"Cdev register failed for %s, ret:%d\n",acStack_50,uVar4 & 0xffffffff);
      goto LAB_0010022c;
    }
  }
  uVar4 = 0;
LAB_0010022c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// gpu_dump_skip_remove @ 001002a8 size=44
// signature: undefined gpu_dump_skip_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 gpu_dump_skip_remove(long param_1)

{
  if (*(long *)(*(long *)(param_1 + 0xa8) + 0x18) != 0) {
    nvmem_cell_put();
  }
  return 0;
}



//------------------------------------------------------------
// gpu_dump_skip_get_max_state @ 001002d8 size=16
// signature: undefined gpu_dump_skip_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 gpu_dump_skip_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 1;
  return 0;
}



//------------------------------------------------------------
// gpu_dump_skip_get_state @ 001002ec size=28
// signature: undefined gpu_dump_skip_get_state(void)
// callers: []
//------------------------------------------------------------

undefined8 gpu_dump_skip_get_state(long param_1,ulong *param_2)

{
  *param_2 = (ulong)(**(char **)(param_1 + 0x3b0) != '\0');
  return 0;
}



//------------------------------------------------------------
// gpu_dump_skip_set_state @ 0010030c size=140
// signature: undefined gpu_dump_skip_set_state(void)
// callers: []
//------------------------------------------------------------

undefined8 gpu_dump_skip_set_state(long param_1,ulong param_2)

{
  undefined8 uVar1;
  uint *puVar2;
  byte *pbVar3;
  
  if (param_2 < 2) {
    pbVar3 = *(byte **)(param_1 + 0x3b0);
    if (*pbVar3 != param_2) {
      *pbVar3 = (byte)param_2;
      if (*(long *)(pbVar3 + 0x18) != 0) {
        nvmem_cell_write(*(long *)(pbVar3 + 0x18),pbVar3,1);
      }
      puVar2 = (uint *)of_iomap(*(undefined8 *)(pbVar3 + 0x20),0);
      if (puVar2 == (uint *)0x0) {
        _printk(&DAT_00100615);
        return 0xfffffff4;
      }
      *puVar2 = (uint)*pbVar3;
      iounmap();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 0010039c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gpu_dump_skip_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001003cc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gpu_dump_skip_driver);
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
// callers: [gpu_dump_skip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00102018 size=1
// signature: undefined of_property_read_string(void)
// callers: [gpu_dump_skip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 00102020 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [gpu_dump_skip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00102028 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [gpu_dump_skip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_cooling_device_register @ 00102030 size=1
// signature: undefined devm_thermal_of_cooling_device_register(void)
// callers: [gpu_dump_skip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102038 size=1
// signature: undefined _dev_err(void)
// callers: [gpu_dump_skip_probe]
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
// callers: [gpu_dump_skip_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 00102048 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [gpu_dump_skip_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_write @ 00102050 size=1
// signature: undefined nvmem_cell_write(void)
// callers: [gpu_dump_skip_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 00102058 size=1
// signature: undefined of_iomap(void)
// callers: [gpu_dump_skip_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00102060 size=1
// signature: undefined iounmap(void)
// callers: [gpu_dump_skip_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102068 size=1
// signature: undefined _printk(void)
// callers: [gpu_dump_skip_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



