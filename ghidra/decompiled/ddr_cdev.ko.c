// Decompiled by Ghidra 12.2
// Program: ddr_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// ddr_cdev_probe @ 0010014c size=688
// signature: undefined ddr_cdev_probe(void)
// callers: []
//------------------------------------------------------------

ulong ddr_cdev_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  undefined4 *puVar3;
  ulong uVar4;
  long lVar5;
  undefined4 *puVar6;
  ulong uVar7;
  char *pcVar8;
  long lVar9;
  undefined8 uVar10;
  int local_78;
  uint local_74;
  char local_70 [8];
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  uVar10 = *(undefined8 *)(param_1 + 0x2f8);
  local_78 = 1;
  local_74 = 0;
  local_60 = 0;
  local_70 = (char  [8])s_ddr_cdev_001009f8._0_8_;
  uStack_68 = 0;
  puVar3 = (undefined4 *)devm_kmalloc(lVar1,0x30,0xdc0);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_001003c0;
  }
  uVar4 = of_icc_get(lVar1,0);
  *(ulong *)(puVar3 + 4) = uVar4;
  if (0xfffffffffffff000 < uVar4) {
    if ((int)uVar4 == -0x205) {
      uVar4 = 0xfffffdfb;
    }
    else {
      _dev_err(lVar1,"Unable to register icc path: %d\n",uVar4 & 0xffffffff);
    }
    goto LAB_001003c0;
  }
  lVar5 = of_find_property(uVar10,"qcom,freq-table",&local_74);
  if (lVar5 == 0) {
    pcVar8 = "No DDR frequency entries\n";
LAB_00100348:
    _dev_err(lVar1,pcVar8);
    uVar7 = 0xffffffed;
  }
  else {
    if ((int)local_74 < 1) {
      pcVar8 = "No DDR frequency\n";
      goto LAB_00100348;
    }
    lVar5 = (ulong)(local_74 >> 2) + 1;
    local_74 = (uint)lVar5;
    puVar6 = (undefined4 *)devm_kmalloc(lVar1,lVar5 * 4,0xdc0);
    if (puVar6 == (undefined4 *)0x0) {
      uVar7 = 0xfffffff4;
    }
    else {
      *puVar6 = 0;
      uVar2 = of_property_read_variable_u32_array
                        (uVar10,"qcom,freq-table",puVar6 + 1,(long)(int)(local_74 - 1),0);
      if ((int)uVar2 < 0) {
        uVar7 = (ulong)uVar2;
        pcVar8 = "DDR frequency read error:%d\n";
      }
      else {
        puVar3[10] = local_74;
        *(long *)(puVar3 + 6) = lVar1;
        *(undefined4 **)(puVar3 + 8) = puVar6;
        *puVar3 = 0;
        puVar3[1] = local_74 - 1;
        uVar2 = of_property_read_variable_u32_array(uVar10,"qcom,bus-width",&local_78,1,0);
        if ((int)uVar2 < 0) {
          uVar7 = (ulong)uVar2;
          pcVar8 = "DDR bus width read error:%d\n";
        }
        else {
          if (0 < (int)local_74) {
            lVar5 = 0;
            do {
              lVar9 = lVar5 * 4;
              lVar5 = lVar5 + 1;
              *(int *)(*(long *)(puVar3 + 8) + lVar9) =
                   *(int *)(*(long *)(puVar3 + 8) + lVar9) * local_78;
            } while (lVar5 < (int)local_74);
            uVar4 = *(ulong *)(puVar3 + 4);
          }
          uVar2 = icc_set_bw(uVar4,0,*puVar6);
          if (-1 < (int)uVar2) {
            uVar7 = thermal_of_cooling_device_register(uVar10,local_70,puVar3,&ddr_cdev_ops);
            *(ulong *)(puVar3 + 2) = uVar7;
            if (uVar7 < 0xfffffffffffff001) {
              uVar4 = 0;
              *(undefined4 **)(param_1 + 0xa8) = puVar3;
              goto LAB_001003c0;
            }
            _dev_err(lVar1,"Cdev register failed for %s, ret:%d\n",local_70,uVar7 & 0xffffffff);
            uVar4 = *(ulong *)(puVar3 + 4);
            goto LAB_001003b4;
          }
          uVar7 = (ulong)uVar2;
          pcVar8 = "Error placing DDR freq request. err:%d\n";
        }
      }
      _dev_err(lVar1,pcVar8,uVar7);
    }
  }
LAB_001003b4:
  icc_put(uVar4);
  uVar4 = uVar7 & 0xffffffff;
LAB_001003c0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// ddr_cdev_remove @ 00100400 size=92
// signature: undefined ddr_cdev_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 ddr_cdev_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (*(long *)(lVar1 + 8) != 0) {
    thermal_cooling_device_unregister();
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  if (*(long *)(lVar1 + 0x10) != 0) {
    icc_set_bw(*(long *)(lVar1 + 0x10),0,**(undefined4 **)(lVar1 + 0x20));
    icc_put(*(undefined8 *)(lVar1 + 0x10));
    *(undefined8 *)(lVar1 + 0x10) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// ddr_get_max_state @ 00100460 size=20
// signature: undefined ddr_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 ddr_get_max_state(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 4);
  return 0;
}



//------------------------------------------------------------
// ddr_get_cur_state @ 00100478 size=20
// signature: undefined ddr_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 ddr_get_cur_state(long param_1,ulong *param_2)

{
  *param_2 = (ulong)**(uint **)(param_1 + 0x3b0);
  return 0;
}



//------------------------------------------------------------
// ddr_set_cur_state @ 00100490 size=152
// signature: undefined ddr_set_cur_state(void)
// callers: []
//------------------------------------------------------------

int ddr_set_cur_state(long param_1,ulong param_2)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_1 + 0x3b0);
  if (puVar2[1] < param_2) {
    iVar1 = -0x16;
  }
  else if (*puVar2 == param_2) {
    iVar1 = 0;
  }
  else {
    iVar1 = icc_set_bw(*(undefined8 *)(puVar2 + 4),0,
                       *(undefined4 *)(*(long *)(puVar2 + 8) + param_2 * 4));
    if (iVar1 < 0) {
      _dev_err(*(undefined8 *)(puVar2 + 6),"Error placing DDR freq%u. err:%d\n",
               *(undefined4 *)(*(long *)(puVar2 + 8) + param_2 * 4),iVar1);
    }
    else {
      *puVar2 = (uint)param_2;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 0010052c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ddr_cdev_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010055c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ddr_cdev_driver);
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
// callers: [ddr_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00102018 size=1
// signature: undefined of_icc_get(void)
// callers: [ddr_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102020 size=1
// signature: undefined of_find_property(void)
// callers: [ddr_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [ddr_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00102030 size=1
// signature: undefined icc_set_bw(void)
// callers: [ddr_cdev_probe, ddr_cdev_remove, ddr_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 00102038 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [ddr_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [ddr_cdev_probe, ddr_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 00102048 size=1
// signature: undefined icc_put(void)
// callers: [ddr_cdev_probe, ddr_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ddr_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00102058 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [ddr_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



