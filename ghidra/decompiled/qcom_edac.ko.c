// Decompiled by Ghidra 12.2
// Program: qcom_edac.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_llcc_edac_probe @ 001001b4 size=640
// signature: undefined qcom_llcc_edac_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_llcc_edac_probe(long param_1)

{
  long *plVar1;
  undefined **ppuVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  
  lVar11 = *(long *)(param_1 + 0xa0);
  iVar4 = *(int *)(lVar11 + 0x74);
  uVar5 = *(undefined4 *)(lVar11 + 0x5c);
  ppuVar2 = &edac_reg_data_v2;
  if (0x14 < iVar4) {
    ppuVar2 = &edac_reg_data_v51;
  }
  puVar3 = edac_regs_v2;
  if (0x14 < iVar4) {
    puVar3 = edac_regs_v51;
  }
  bVar6 = 0x1d < iVar4 - 0x15U;
  edac_reg_data = (undefined *)&edac_reg_data_v21;
  if (bVar6) {
    edac_reg_data = (undefined *)ppuVar2;
  }
  edac_regs = edac_regs_v21;
  if (bVar6) {
    edac_regs = puVar3;
  }
  uVar7 = edac_device_alloc_index();
  lVar9 = edac_device_alloc_ctl_info(0,"qcom-llcc",1,&DAT_00101049,uVar5,1,0,0,uVar7);
  if (lVar9 == 0) {
    return -0xc;
  }
  plVar1 = (long *)(param_1 + 0x10);
  *(long **)(lVar9 + 0xe0) = plVar1;
  lVar10 = *(long *)(param_1 + 0x80);
  if (lVar10 == 0) {
    lVar10 = *plVar1;
  }
  *(long *)(lVar9 + 0xe8) = lVar10;
  lVar10 = *(long *)(param_1 + 0x80);
  if (lVar10 == 0) {
    lVar10 = *plVar1;
  }
  *(undefined **)(lVar9 + 0xf0) = &DAT_00100ea2;
  *(long *)(lVar9 + 0xf8) = lVar10;
  *(undefined4 *)(lVar9 + 0x24) = 1;
  iVar4 = *(int *)(lVar11 + 0x70);
  if (iVar4 < 0) {
    _dev_info(plVar1,"No ECC IRQ; defaulting to polling mode\n");
    uVar5 = poll_msec;
    *(code **)(lVar9 + 0xd8) = qcom_llcc_poll_cache_errors;
    *(undefined4 *)(lVar9 + 0x28) = uVar5;
  }
  iVar8 = edac_device_add_device(lVar9);
  if (iVar8 == 0) {
    if (iVar4 < 0) {
LAB_001003fc:
      *(long *)(param_1 + 0xa8) = lVar9;
      return 0;
    }
    uVar12 = *(undefined8 *)(lVar11 + 8);
    iVar8 = regmap_update_bits_base(uVar12,*(undefined4 *)(edac_regs + 0x24),1,1,0,0,0);
    if (iVar8 == 0) {
      iVar8 = regmap_update_bits_base(uVar12,*(undefined4 *)(edac_regs + 0x30),3,3,0,0,0);
      if (iVar8 == 0) {
        iVar8 = regmap_write(uVar12,*(undefined4 *)(edac_regs + 0x20),0x1000000);
        if (iVar8 == 0) {
          iVar8 = regmap_update_bits_base(uVar12,*(undefined4 *)(edac_regs + 0x24),0x40,0x40,0,0,0);
          if (iVar8 == 0) {
            iVar8 = regmap_write(uVar12,*(undefined4 *)(edac_regs + 0x2c),3);
            if (iVar8 == 0) {
              iVar8 = devm_request_threaded_irq
                                (plVar1,iVar4,llcc_ecc_irq_handler,0,0x2084,"llcc_ecc",lVar9);
              if (iVar8 == 0) goto LAB_001003fc;
            }
          }
        }
      }
    }
    edac_device_del_device(*(undefined8 *)(lVar9 + 0xe0));
  }
  edac_device_free_ctl_info(lVar9);
  return iVar8;
}



//------------------------------------------------------------
// qcom_llcc_edac_remove @ 00100438 size=56
// signature: undefined qcom_llcc_edac_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_llcc_edac_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  edac_device_del_device(*(undefined8 *)(lVar1 + 0xe0));
  edac_device_free_ctl_info(lVar1);
  return 0;
}



//------------------------------------------------------------
// qcom_llcc_poll_cache_errors @ 00100474 size=32
// signature: undefined qcom_llcc_poll_cache_errors(void)
// callers: []
//------------------------------------------------------------

void qcom_llcc_poll_cache_errors(undefined8 param_1)

{
  llcc_ecc_irq_handler(param_1,param_1);
  return;
}



//------------------------------------------------------------
// llcc_ecc_irq_handler @ 00100498 size=420
// signature: undefined llcc_ecc_irq_handler(void)
// callers: [qcom_llcc_poll_cache_errors]
//------------------------------------------------------------

void llcc_ecc_irq_handler(undefined8 param_1,long param_2)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_70 = 0;
  puVar8 = *(undefined8 **)(*(long *)(param_2 + 0xe0) + 0x90);
  if (*(int *)((long)puVar8 + 0x5c) == 0) {
    bVar2 = 0;
  }
  else {
    uVar6 = 0;
    bVar2 = 0;
    do {
      iVar3 = regmap_read(*puVar8,*(int *)(edac_regs + 0x14) + *(int *)(puVar8[0xd] + uVar6 * 4),
                          (long)&local_70 + 4);
      if (iVar3 == 0) {
        if ((local_70 & 0x100000000) == 0) {
          if ((local_70._4_4_ >> 1 & 1) == 0) {
            iVar3 = 0;
            goto LAB_00100564;
          }
          uVar7 = 1;
          puVar5 = &DAT_001010bf;
        }
        else {
          uVar7 = 0;
          puVar5 = &DAT_0010104e;
        }
        _printk(puVar5);
        iVar3 = dump_syn_reg(param_2,uVar7,uVar6 & 0xffffffff);
      }
LAB_00100564:
      iVar4 = regmap_read(*puVar8,*(int *)(edac_regs + 0x38) + *(int *)(puVar8[0xd] + uVar6 * 4),
                          &local_70);
      if (iVar4 == 0) {
        if ((local_70 & 1) == 0) {
          if (((uint)local_70 >> 1 & 1) == 0) {
            iVar4 = 0;
            goto LAB_0010050c;
          }
          uVar7 = 3;
          puVar5 = &DAT_00101087;
        }
        else {
          uVar7 = 2;
          puVar5 = &DAT_00100fe2;
        }
        _printk(puVar5);
        iVar4 = dump_syn_reg(param_2,uVar7,uVar6 & 0xffffffff);
      }
LAB_0010050c:
      uVar6 = uVar6 + 1;
      bVar2 = (iVar4 == 0 || iVar3 == 0) | bVar2;
    } while (uVar6 < *(uint *)((long)puVar8 + 0x5c));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// dump_syn_reg @ 0010063c size=680
// signature: undefined dump_syn_reg(void)
// callers: [llcc_ecc_irq_handler]
//------------------------------------------------------------

void dump_syn_reg(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  char *pcVar12;
  undefined8 *puVar13;
  int iVar14;
  undefined8 *puVar15;
  ulong uVar16;
  undefined4 local_74;
  uint local_70;
  uint uStack_6c;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  puVar13 = (undefined8 *)(edac_reg_data + (ulong)param_2 * 0x30);
  puVar15 = *(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x90);
  uVar11 = puVar13[2];
  uVar3 = puVar13[3];
  uVar2 = *puVar13;
  uVar16 = puVar13[1];
  iVar10 = *(int *)(puVar13 + 4);
  uVar1 = *(uint *)((long)puVar13 + 0x24);
  uVar4 = *(uint *)(puVar13 + 5);
  bVar6 = *(byte *)((long)puVar13 + 0x2c);
  bVar7 = *(byte *)((long)puVar13 + 0x2d);
  local_70 = 0;
  uStack_6c = 0;
  local_74 = 0;
  if (iVar10 != 0) {
    iVar14 = 0;
    do {
      iVar9 = regmap_read(*puVar15,(int)uVar16 + *(int *)(puVar15[0xd] + (ulong)param_3 * 4),
                          &local_74);
      if (iVar9 != 0) goto LAB_0010072c;
      _printk(&DAT_00100eff,uVar2,iVar14,local_74);
      iVar14 = iVar14 + 1;
      uVar16 = (ulong)((int)uVar16 + 4);
    } while (iVar10 != iVar14);
  }
  iVar10 = regmap_read(*puVar15,*(int *)(puVar15[0xd] + (ulong)param_3 * 4) + (int)uVar11,&uStack_6c
                      );
  if (iVar10 == 0) {
    uStack_6c = (int)(uStack_6c & uVar1) >> (bVar6 & 0x1f);
    _printk(&DAT_00100e78,uVar2);
    iVar10 = regmap_read(*puVar15,*(int *)(puVar15[0xd] + (ulong)param_3 * 4) + (int)uVar3,&local_70
                        );
    if (iVar10 == 0) {
      local_70 = (int)(local_70 & uVar4) >> (bVar7 & 0x1f);
      _printk(&DAT_00100f27,uVar2);
    }
  }
LAB_0010072c:
  if (1 < param_2 - 2) {
    if (param_2 < 2) {
      uVar11 = regmap_write(puVar15[1],*(undefined4 *)(edac_regs + 0x18),3);
      if ((int)uVar11 != 0) goto LAB_001008a8;
      uVar11 = puVar15[1];
      uVar5 = *(undefined4 *)(edac_regs + 0x1c);
      goto LAB_00100794;
    }
switchD_001007c0_default:
    _printk(&DAT_00100fa5,param_2);
    uVar11 = 0xffffffea;
    goto LAB_001008a8;
  }
  uVar11 = regmap_write(puVar15[1],*(undefined4 *)(edac_regs + 0x34),3);
  if ((int)uVar11 != 0) goto LAB_001008a8;
  uVar11 = puVar15[1];
  uVar5 = *(undefined4 *)(edac_regs + 0x3c);
LAB_00100794:
  uVar11 = regmap_write(uVar11,uVar5,3);
  if ((int)uVar11 != 0) goto LAB_001008a8;
  switch(param_2) {
  case 0:
    pcVar12 = "LLCC Data RAM correctable Error";
    break;
  case 1:
    pcVar12 = "LLCC Data RAM uncorrectable Error";
    goto LAB_00100808;
  case 2:
    pcVar12 = "LLCC Tag RAM correctable Error";
    break;
  case 3:
    pcVar12 = "LLCC Tag RAM uncorrectable Error";
LAB_00100808:
    edac_device_handle_ue_count(param_1,1,0,param_3,pcVar12);
    uVar11 = 0;
    goto LAB_001008a8;
  default:
    goto switchD_001007c0_default;
  }
  edac_device_handle_ce_count(param_1,1,0,param_3,pcVar12);
  uVar11 = 0;
LAB_001008a8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001008e8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_llcc_edac_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100918 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_llcc_edac_driver);
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
// edac_device_alloc_index @ 00102010 size=1
// signature: undefined edac_device_alloc_index(void)
// callers: [qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_alloc_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// edac_device_alloc_ctl_info @ 00102018 size=1
// signature: undefined edac_device_alloc_ctl_info(void)
// callers: [qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_alloc_ctl_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// edac_device_add_device @ 00102020 size=1
// signature: undefined edac_device_add_device(void)
// callers: [qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_add_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00102028 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00102030 size=1
// signature: undefined regmap_write(void)
// callers: [dump_syn_reg, qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00102038 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// edac_device_del_device @ 00102040 size=1
// signature: undefined edac_device_del_device(void)
// callers: [qcom_llcc_edac_remove, qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_del_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// edac_device_free_ctl_info @ 00102048 size=1
// signature: undefined edac_device_free_ctl_info(void)
// callers: [qcom_llcc_edac_remove, qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_free_ctl_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102050 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_llcc_edac_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00102058 size=1
// signature: undefined regmap_read(void)
// callers: [dump_syn_reg, llcc_ecc_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102060 size=1
// signature: undefined _printk(void)
// callers: [dump_syn_reg, llcc_ecc_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [dump_syn_reg, llcc_ecc_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// edac_device_handle_ce_count @ 00102070 size=1
// signature: undefined edac_device_handle_ce_count(void)
// callers: [dump_syn_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_handle_ce_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// edac_device_handle_ue_count @ 00102078 size=1
// signature: undefined edac_device_handle_ue_count(void)
// callers: [dump_syn_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void edac_device_handle_ue_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



