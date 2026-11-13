// Decompiled by Ghidra 12.2
// Program: qcom-spmi-pmic.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_pmic_get @ 0010012c size=76
// signature: undefined qcom_pmic_get(void)
// callers: []
//------------------------------------------------------------

long qcom_pmic_get(long param_1)

{
  long lVar1;
  
  lVar1 = of_match_device(&pmic_spmi_id_table,*(undefined8 *)(param_1 + 0x60));
  if (lVar1 == 0) {
    lVar1 = -0x16;
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 0x60) + 0x98) + 8;
  }
  return lVar1;
}



//------------------------------------------------------------
// pmic_spmi_probe @ 0010017c size=792
// signature: undefined pmic_spmi_probe(void)
// callers: []
//------------------------------------------------------------

ulong pmic_spmi_probe(long param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  int *piVar10;
  undefined8 uVar11;
  ulong uVar12;
  uint uVar13;
  int local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,can-sleep",0);
  puVar3 = spmi_regmap_config;
  if (lVar8 != 0) {
    puVar3 = spmi_regmap_can_sleep_config;
  }
  uVar9 = __devm_regmap_init_spmi_ext(param_1,puVar3,0,0);
  if (0xfffffffffffff000 < uVar9) {
    uVar9 = uVar9 & 0xffffffff;
    goto LAB_0010044c;
  }
  devm_regmap_qti_debugfs_register(param_1,uVar9);
  piVar10 = (int *)devm_kmalloc(param_1,0x28,0xdc0);
  if (piVar10 == (int *)0x0) {
    uVar9 = 0xfffffff4;
    goto LAB_0010044c;
  }
  iVar6 = of_device_get_match_data(param_1);
  iVar7 = 0;
  uVar13 = (uint)*(byte *)(param_1 + 0x398);
  if (iVar6 != 0) {
    iVar7 = (int)uVar13 / iVar6;
  }
  *piVar10 = iVar6;
  if (uVar13 == iVar7 * iVar6) {
    uVar12 = regmap_read(uVar9,0x104,piVar10 + 2);
    if (-1 < (int)uVar12) {
      if (piVar10[2] != 0x51) goto LAB_00100424;
      piVar1 = piVar10 + 3;
      uVar12 = regmap_read(uVar9,0x105,piVar1);
      if (-1 < (int)uVar12) {
        lVar8 = of_match_device(&pmic_spmi_id_table,param_1);
        *(long *)(piVar10 + 8) = lVar8 + 0x40;
        uVar12 = regmap_read(uVar9,0x101,piVar10 + 6);
        if (-1 < (int)uVar12) {
          uVar12 = regmap_read(uVar9,0x102,piVar10 + 5);
          if (-1 < (int)uVar12) {
            puVar2 = (uint *)(piVar10 + 4);
            uVar12 = regmap_read(uVar9,0x103,puVar2);
            if (-1 < (int)uVar12) {
              iVar7 = *piVar1;
              if ((iVar7 == 0x1b) || (iVar7 == 0x15)) {
                uVar12 = regmap_read(uVar9,0x1f2,piVar10 + 7);
                if ((int)uVar12 < 0) goto LAB_00100448;
                iVar7 = *piVar1;
              }
              if (iVar7 == 1) {
LAB_00100398:
                if (*puVar2 < 2) {
                  *puVar2 = *puVar2 + 1;
                }
              }
              else if (iVar7 == 5) {
                piVar10[5] = piVar10[6];
              }
              else if (iVar7 == 4) goto LAB_00100398;
              goto LAB_00100424;
            }
          }
        }
      }
    }
  }
  else {
    local_5c = 0;
    uVar11 = of_get_parent(*(undefined8 *)(param_1 + 0x2e8));
    lVar8 = of_get_next_child(uVar11,0);
    if (lVar8 != 0) {
      do {
        iVar7 = of_property_read_u32_index(lVar8,&DAT_001028d9,0,&local_5c);
        if (iVar7 != 0) {
          uVar12 = (ulong)iVar7;
LAB_001003c8:
          uVar9 = uVar12;
          if (uVar12 < 0xfffffffffffff001) {
            mutex_lock(pmic_spmi_revid_lock);
            lVar8 = *(long *)(uVar12 + 0x98);
            if (lVar8 == 0) {
              uVar9 = 0xfffffdfb;
            }
            else {
              uVar4 = *(undefined8 *)(lVar8 + 0x20);
              uVar9 = 0;
              uVar11 = *(undefined8 *)(lVar8 + 8);
              uVar5 = *(undefined8 *)(lVar8 + 0x10);
              *(undefined8 *)(piVar10 + 6) = *(undefined8 *)(lVar8 + 0x18);
              *(undefined8 *)(piVar10 + 8) = uVar4;
              *(undefined8 *)(piVar10 + 2) = uVar11;
              *(undefined8 *)(piVar10 + 4) = uVar5;
            }
            mutex_unlock(pmic_spmi_revid_lock);
            put_device(uVar12);
          }
          goto LAB_00100420;
        }
        if (local_5c == (uVar13 - iVar6) + 1) {
          uVar12 = spmi_device_from_of(lVar8);
          if (uVar12 != 0) goto LAB_001003c8;
          uVar9 = 0xfffffffffffffdfb;
          goto LAB_00100420;
        }
        lVar8 = of_get_next_child(uVar11,lVar8);
      } while (lVar8 != 0);
    }
    uVar9 = 0xffffffffffffffc3;
LAB_00100420:
    if ((int)uVar9 != 0) goto LAB_0010044c;
LAB_00100424:
    mutex_lock(pmic_spmi_revid_lock);
    *(int **)(param_1 + 0x98) = piVar10;
    mutex_unlock(pmic_spmi_revid_lock);
    uVar12 = devm_of_platform_populate(param_1);
  }
LAB_00100448:
  uVar9 = uVar12 & 0xffffffff;
LAB_0010044c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// pmic_spmi_remove @ 00100498 size=64
// signature: undefined pmic_spmi_remove(void)
// callers: []
//------------------------------------------------------------

void pmic_spmi_remove(long param_1)

{
  mutex_lock(pmic_spmi_revid_lock);
  *(undefined8 *)(param_1 + 0x98) = 0;
  mutex_unlock(pmic_spmi_revid_lock);
  return;
}



//------------------------------------------------------------
// init_module @ 001004ec size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __spmi_driver_register(&pmic_spmi_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010051c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  driver_unregister(&pmic_spmi_driver);
  return;
}



//------------------------------------------------------------
// of_match_device @ 00104000 size=1
// signature: undefined of_match_device(void)
// callers: [qcom_pmic_get, pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __spmi_driver_register @ 00104008 size=1
// signature: undefined __spmi_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __spmi_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 00104010 size=1
// signature: undefined driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104018 size=1
// signature: undefined of_find_property(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_spmi_ext @ 00104020 size=1
// signature: undefined __devm_regmap_init_spmi_ext(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_spmi_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 00104028 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104030 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00104038 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_parent @ 00104040 size=1
// signature: undefined of_get_parent(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 00104048 size=1
// signature: undefined of_get_next_child(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00104050 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00104058 size=1
// signature: undefined regmap_read(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_device_from_of @ 00104060 size=1
// signature: undefined spmi_device_from_of(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_device_from_of(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104068 size=1
// signature: undefined mutex_lock(void)
// callers: [pmic_spmi_probe, pmic_spmi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104070 size=1
// signature: undefined mutex_unlock(void)
// callers: [pmic_spmi_probe, pmic_spmi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00104078 size=1
// signature: undefined put_device(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_platform_populate @ 00104080 size=1
// signature: undefined devm_of_platform_populate(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pmic_spmi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



