// Decompiled by Ghidra 12.2
// Program: qti_userspace_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// userspace_device_probe @ 00100134 size=668
// signature: undefined userspace_device_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

int userspace_device_probe(long param_1)

{
  uint uVar1;
  ulong *puVar2;
  undefined1 auVar3 [16];
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  long *plVar10;
  char *__string;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  
  uVar9 = *(undefined8 *)(param_1 + 0x2f8);
  param_1 = param_1 + 0x10;
  lVar5 = of_get_next_available_child(uVar9,0);
  if (lVar5 != 0) {
    uVar1 = 0;
    do {
      uVar11 = uVar1;
      uVar1 = uVar11 + 1;
      lVar5 = of_get_next_available_child(uVar9,lVar5);
    } while (lVar5 != 0);
    if (uVar1 != 0) {
      uVar12 = (ulong)(int)uVar1;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar12;
      if (SUB168(auVar3 * ZEXT816(0x30),8) != 0) {
        cdev_instances = 0;
        return -0xc;
      }
      cdev_instances = devm_kmalloc(param_1,(uVar12 + (long)(int)uVar1 * 2) * 0x10,0xdc0);
      if (cdev_instances == 0) {
        return -0xc;
      }
      inst_cnt = uVar1;
      puVar6 = (undefined8 *)of_get_next_available_child(uVar9,0);
      if (puVar6 == (undefined8 *)0x0) {
        return 0;
      }
      if (0x7ffffffe < uVar11) {
        return 0;
      }
      uVar13 = 0;
      lVar5 = 0x20;
      do {
        iVar4 = of_property_read_variable_u32_array
                          (puVar6,"qcom,max-level",cdev_instances + lVar5 + 0xc,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"error reading qcom,max-level. ret:%d\n",iVar4);
          lVar8 = cdev_instances;
LAB_00100340:
          inst_cnt = (uint)uVar13;
          if (0 < (int)inst_cnt) {
            lVar5 = 0;
            plVar10 = (long *)(lVar8 + 0x20);
            do {
              if (*plVar10 != 0) {
                thermal_cooling_device_unregister();
                uVar13 = (ulong)inst_cnt;
              }
              lVar5 = lVar5 + 1;
              *plVar10 = 0;
              plVar10 = plVar10 + 6;
            } while (lVar5 < (int)uVar13);
          }
          inst_cnt = 0;
          return iVar4;
        }
        lVar8 = cdev_instances + lVar5;
        *(undefined8 **)(lVar8 + -0x20) = puVar6;
        __string = (char *)*puVar6;
        uVar7 = strnlen(__string,0x14);
        if (uVar7 == 0xffffffffffffffff) {
          fortify_panic("strnlen");
LAB_001003c4:
          fortify_panic("strscpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        if (uVar7 != 0x14) {
          uVar7 = uVar7 + 1;
        }
        if (0x14 < uVar7) goto LAB_001003c4;
        strscpy(lVar8 + -0x18,__string);
        uVar7 = thermal_of_cooling_device_register
                          (puVar6,cdev_instances + lVar5 + -0x18,cdev_instances + lVar5 + -0x20,
                           &userspace_cdev_ops);
        puVar2 = (ulong *)(cdev_instances + lVar5);
        *puVar2 = uVar7;
        if (0xfffffffffffff000 < uVar7) {
          _dev_err(param_1,"Error registering cdev:%s err:%d\n",puVar2 + -3,uVar7);
          lVar8 = cdev_instances;
          iVar4 = 0;
          *(undefined8 *)(cdev_instances + lVar5) = 0;
          goto LAB_00100340;
        }
        _dev_info(param_1,"cdev:%s lvl:%d registered\n",puVar2 + -3,
                  *(undefined4 *)((long)puVar2 + 0xc));
        puVar6 = (undefined8 *)of_get_next_available_child(uVar9,puVar6);
        if (puVar6 == (undefined8 *)0x0) {
          return 0;
        }
        uVar13 = uVar13 + 1;
        lVar5 = lVar5 + 0x30;
        if ((long)uVar12 <= (long)uVar13) {
          return 0;
        }
      } while( true );
    }
  }
  _dev_err(param_1,"No child node to process\n");
  return -0xe;
}



//------------------------------------------------------------
// userspace_device_remove @ 001003d4 size=120
// signature: undefined userspace_device_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 userspace_device_remove(void)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  
  if (0 < inst_cnt) {
    lVar2 = 0;
    plVar3 = (long *)(cdev_instances + 0x20);
    iVar1 = inst_cnt;
    do {
      if (*plVar3 != 0) {
        thermal_cooling_device_unregister();
        iVar1 = inst_cnt;
      }
      lVar2 = lVar2 + 1;
      *plVar3 = 0;
      plVar3 = plVar3 + 6;
    } while (lVar2 < iVar1);
  }
  inst_cnt = 0;
  return 0;
}



//------------------------------------------------------------
// userspace_get_max_state @ 00100450 size=32
// signature: undefined userspace_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 userspace_get_max_state(long param_1,ulong *param_2)

{
  if (*(long *)(param_1 + 0x3b0) == 0) {
    return 0xffffffea;
  }
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x2c);
  return 0;
}



//------------------------------------------------------------
// userspace_get_cur_state @ 00100474 size=32
// signature: undefined userspace_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 userspace_get_cur_state(long param_1,ulong *param_2)

{
  if (*(long *)(param_1 + 0x3b0) == 0) {
    return 0xffffffea;
  }
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x28);
  return 0;
}



//------------------------------------------------------------
// userspace_set_cur_state @ 00100498 size=60
// signature: undefined userspace_set_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 userspace_set_cur_state(long param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x3b0);
  if ((lVar1 == 0) || (*(uint *)(lVar1 + 0x2c) < param_2)) {
    return 0xffffffea;
  }
  if (*(uint *)(lVar1 + 0x28) == param_2) {
    return 0;
  }
  *(int *)(lVar1 + 0x28) = (int)param_2;
  return 0;
}



//------------------------------------------------------------
// init_module @ 001004d8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&userspace_cdev_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100508 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&userspace_cdev_driver);
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
// of_get_next_available_child @ 00102010 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00102028 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00102030 size=1
// signature: undefined strscpy(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 00102038 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102040 size=1
// signature: undefined _dev_info(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00102050 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [userspace_device_remove, userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00102058 size=1
// signature: undefined fortify_panic(void)
// callers: [userspace_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



