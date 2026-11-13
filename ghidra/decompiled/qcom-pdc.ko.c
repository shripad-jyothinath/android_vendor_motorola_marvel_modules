// Decompiled by Ghidra 12.2
// Program: qcom-pdc.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_pdc_init @ 00100324 size=1264
// signature: undefined qcom_pdc_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_pdc_init(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  long local_120;
  long lStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  long local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar10 = sp_el0;
  local_70 = *(long *)(lVar10 + 0x638);
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  lStack_118 = 0;
  pdc_base = of_iomap(param_1,0);
  if (pdc_base == 0) {
    _printk(&DAT_00102226,param_1);
    iVar7 = -6;
    goto LAB_00100768;
  }
  uVar6 = readl_relaxed(pdc_base + 0x1000);
  enable_in_cfg = 0x20000 < (uVar6 & 0xff0000);
  lVar10 = 0;
  if (param_2 != 0) {
    lVar10 = param_2 + 0x18;
  }
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  uStack_b8 = 0;
  local_c0 = lVar10;
  lVar9 = irq_find_matching_fwspec(&local_c0,1);
  if (lVar9 == 0) {
    local_80 = 0;
    uStack_78 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_a0 = 0;
    uStack_98 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    uStack_b8 = 0;
    local_c0 = lVar10;
    lVar9 = irq_find_matching_fwspec(&local_c0,0);
    if (lVar9 != 0) goto LAB_001003fc;
    _printk(&DAT_001021a3,param_1);
    iVar7 = -6;
LAB_00100744:
    plVar11 = spi_cfg;
LAB_0010074c:
    if (plVar11 != (long *)0x0) {
LAB_00100750:
      kfree();
    }
  }
  else {
LAB_001003fc:
    uVar6 = of_property_count_elems_of_size(param_1,"qcom,pdc-ranges",4);
    iVar7 = -0x16;
    if (((int)uVar6 < 1) || (uVar6 % 3 != 0)) {
LAB_00100734:
      _printk(&DAT_001021cf,param_1);
      goto LAB_00100744;
    }
    pdc_region_cnt = uVar6 / 3;
    lVar10 = __kmalloc(((ulong)uVar6 / 3) * 0xc,0xdc0);
    pdc_region = lVar10;
    if (lVar10 == 0) {
      iVar7 = -0xc;
      pdc_region_cnt = 0;
      goto LAB_00100734;
    }
    if (0 < (int)pdc_region_cnt) {
      lVar14 = 0;
      do {
        iVar4 = (int)lVar14 * 3;
        iVar7 = of_property_read_u32_index(param_1,"qcom,pdc-ranges",iVar4,lVar10 + lVar14 * 0xc);
        if (((iVar7 != 0) ||
            (iVar7 = of_property_read_u32_index
                               (param_1,"qcom,pdc-ranges",iVar4 + 1,pdc_region + lVar14 * 0xc + 4),
            iVar7 != 0)) ||
           (iVar7 = of_property_read_u32_index
                              (param_1,"qcom,pdc-ranges",iVar4 + 2,pdc_region + lVar14 * 0xc + 8),
           iVar7 != 0)) {
          goto LAB_00100734;
        }
        lVar10 = pdc_region;
        if (*(int *)(pdc_region + lVar14 * 0xc + 8) != 0) {
          uVar6 = 0;
          do {
            uVar1 = uVar6 + *(int *)(lVar10 + lVar14 * 0xc);
            uVar13 = (ulong)uVar1;
            if ((enable_in_cfg & 1) == 0) {
              uVar2 = uVar1 + 0x1f;
              if (-1 < (int)uVar1) {
                uVar2 = uVar1;
              }
              lVar10 = (ulong)(uint)((int)uVar2 >> 5) * 4;
              uVar8 = readl_relaxed(pdc_base + lVar10 + 0x10);
              uVar8 = uVar8 & ((uint)(1L << ((ulong)(uVar1 - (uVar2 & 0x20)) & 0x3f)) ^ 0xffffffff);
              lVar12 = 0x10;
            }
            else {
              lVar10 = uVar13 * 4;
              uVar8 = readl_relaxed(pdc_base + lVar10 + 0x110);
              lVar12 = 0x110;
              uVar8 = uVar8 & 0xfffffff7;
            }
            writel_relaxed(uVar8,pdc_base + lVar12 + lVar10);
            lVar10 = pdc_region;
            if (0xff < uVar1) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10080c);
              (*pcVar5)();
            }
            if (0xbf8 < uVar13 * 0xc) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(1,0x100810);
              (*pcVar5)();
            }
            uVar6 = uVar6 + 1;
            lVar12 = pdc_region + lVar14 * 0xc;
            (&DAT_00101524)[uVar13 * 3] = 0;
          } while (uVar6 < *(uint *)(lVar12 + 8));
        }
        lVar14 = lVar14 + 1;
      } while (lVar14 < (int)pdc_region_cnt);
    }
    iVar7 = of_address_to_resource(param_1,1,&local_120);
    if (iVar7 != 0) goto LAB_001005f0;
    spi_cfg = (long *)kmalloc_trace(_kfree,0xdc0,0x18);
    if (spi_cfg != (long *)0x0) {
      lVar14 = of_find_property(param_1,"qcom,scm-spi-cfg",0);
      plVar11 = spi_cfg;
      *(bool *)(spi_cfg + 2) = lVar14 != 0;
      lVar10 = (lStack_118 - local_120) + 1;
      plVar11[1] = lVar10;
      if (lVar14 == 0) {
        uVar3 = 0x68000000000713;
        if (arm64_use_ng_mappings != '\0') {
          uVar3 = 0x68000000000f13;
        }
        lVar10 = ioremap_prot(local_120,lVar10,uVar3);
        plVar11 = spi_cfg;
        *spi_cfg = lVar10;
        if (lVar10 != 0) goto LAB_001005f0;
        iVar7 = -0xc;
        goto LAB_0010074c;
      }
      *plVar11 = local_120;
LAB_001005f0:
      lVar10 = 0;
      if (param_1 != 0) {
        lVar10 = param_1 + 0x18;
      }
      lVar10 = irq_domain_create_hierarchy(lVar9,0x10000,0x100,lVar10,qcom_pdc_ops,0);
      if (lVar10 != 0) {
        irq_domain_update_bus_token(lVar10,9);
        register_syscore_ops(pdc_syscore_ops);
        iVar7 = register_pm_notifier(&pdc_notifier_block);
        if (iVar7 != 0) {
          unregister_syscore_ops(pdc_syscore_ops);
        }
        pdc_ipc_log = ipc_log_context_create(2,&DAT_00102201,0);
        iVar7 = 0;
        goto LAB_00100768;
      }
      _printk(&DAT_0010224b,param_1);
      if (spi_cfg == (long *)0x0) goto LAB_001007d8;
      if (*spi_cfg != 0) {
        iounmap(*spi_cfg);
        iVar7 = -0xc;
        goto LAB_00100744;
      }
      iVar7 = -0xc;
      goto LAB_00100750;
    }
LAB_001007d8:
    iVar7 = -0xc;
  }
  if (pdc_region != 0) {
    kfree();
  }
  iounmap(pdc_base);
LAB_00100768:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// readl_relaxed @ 00100814 size=124
// signature: undefined readl_relaxed(void)
// callers: [pdc_enable_intr, pdc_resume, qcom_pdc_init, qcom_pdc_gic_set_type]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x10085c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00100890 size=132
// signature: undefined writel_relaxed(void)
// callers: [pdc_enable_intr, pdc_resume, qcom_pdc_init, qcom_pdc_gic_set_type]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1008a8,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1008e4,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_pdc_alloc @ 00100918 size=396
// signature: undefined qcom_pdc_alloc(void)
// callers: []
//------------------------------------------------------------

void qcom_pdc_alloc(long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  ulong uVar5;
  uint local_94;
  long local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  int local_78;
  uint uStack_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  local_90 = 0;
  local_94 = 0;
  iVar2 = irq_domain_translate_twocell(param_1,param_4,&local_90,&local_94);
  if (iVar2 == 0) {
    if (local_90 != 0xffffffff) {
      iVar2 = irq_domain_set_hwirq_and_chip(param_1,param_2,local_90,&qcom_pdc_gic_chip,0);
      if (iVar2 != 0) goto LAB_00100a18;
      uVar5 = (ulong)pdc_region_cnt;
      if (0 < (int)pdc_region_cnt) {
        puVar4 = pdc_region;
        do {
          uVar3 = (uint)local_90;
          if ((*puVar4 <= uVar3) && (uVar3 < puVar4[2] + *puVar4)) {
            if (puVar4 != (uint *)0x0) {
              if ((local_94 & 3) == 0) {
                if ((local_94 & 0xc) != 0) {
                  local_94 = 4;
                }
              }
              else {
                local_94 = 1;
              }
              local_88 = *(undefined8 *)(*(long *)(param_1 + 0x50) + 0x30);
              uStack_80 = 3;
              local_78 = (puVar4[1] + uVar3) - *puVar4;
              uStack_74 = local_94;
              ipc_log_string(pdc_ipc_log,"Alloc: PIN=%lu");
              irq_domain_alloc_irqs_parent(param_1,param_2,param_3,&local_88);
              goto LAB_00100a18;
            }
            break;
          }
          puVar4 = puVar4 + 3;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      param_1 = *(long *)(param_1 + 0x50);
    }
    irq_domain_disconnect_hierarchy(param_1,param_2);
  }
LAB_00100a18:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_pdc_gic_enable @ 00100aa8 size=52
// signature: undefined qcom_pdc_gic_enable(void)
// callers: []
//------------------------------------------------------------

void qcom_pdc_gic_enable(undefined8 param_1)

{
  pdc_enable_intr(param_1,1);
  irq_chip_enable_parent(param_1);
  return;
}



//------------------------------------------------------------
// qcom_pdc_gic_disable @ 00100ae0 size=52
// signature: undefined qcom_pdc_gic_disable(void)
// callers: []
//------------------------------------------------------------

void qcom_pdc_gic_disable(undefined8 param_1)

{
  pdc_enable_intr(param_1,0);
  irq_chip_disable_parent(param_1);
  return;
}



//------------------------------------------------------------
// qcom_pdc_gic_set_type @ 00100b18 size=668
// signature: undefined qcom_pdc_gic_set_type(void)
// callers: []
//------------------------------------------------------------

void qcom_pdc_gic_set_type(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  int iVar12;
  undefined8 uVar13;
  uint uVar14;
  uint local_6c;
  long local_68;
  
  lVar6 = sp_el0;
  uVar4 = param_2 - 1;
  local_68 = *(long *)(lVar6 + 0x638);
  if ((7 < uVar4) || ((0x8fU >> (ulong)(uVar4 & 0x1f) & 1) == 0)) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x100b68);
    (*pcVar8)();
  }
  uVar11 = -(ulong)(uVar4 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar4 << 2;
  uVar2 = *(uint *)(&DAT_001024b0 + uVar11);
  uVar3 = *(uint *)(&DAT_001024d0 + uVar11);
  uVar13 = *(undefined8 *)(*(long *)(param_1 + 0x28) + 8);
  uVar9 = readl_relaxed(pdc_base + (*(ulong *)(param_1 + 8) & 0xffffffff) * 4 + 0x110);
  uVar3 = uVar9 & 0xfffffff8 | uVar3;
  writel_relaxed(uVar3,pdc_base + (*(ulong *)(param_1 + 8) & 0xffffffff) * 4 + 0x110);
  ipc_log_string(pdc_ipc_log,"Set type: PIN=%lu pdc_type=%d gic_type=%d",
                 *(undefined8 *)(param_1 + 8),uVar3,uVar2);
  uVar11 = *(ulong *)(param_1 + 8);
  if (0xff < uVar11) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x100db4);
    (*pcVar8)();
  }
  if ((0xbff < uVar11 * 0xc) ||
     ((&pdc_irq_config)[uVar11 * 3] = uVar3, plVar7 = spi_cfg,
     uVar11 * 0xc - 0xbfc < 0xfffffffffffff400)) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(1,0x100db0);
    (*pcVar8)();
  }
  iVar12 = (int)uVar13;
  iVar5 = iVar12 + -0x20;
  iVar12 = iVar12 + -1;
  if (-1 < iVar5) {
    iVar12 = iVar5;
  }
  (&DAT_00101520)[uVar11 * 0xc] = 1;
  if (plVar7 != (long *)0x0) {
    uVar11 = (ulong)(uint)((iVar12 >> 5) << 2);
    if ((ulong)plVar7[1] < uVar11) {
      uVar13 = 0xfffffff2;
      goto LAB_00100b68;
    }
    uVar13 = _raw_spin_lock_irqsave(&pdc_lock);
    if ((char)spi_cfg[2] == '\0') {
      uVar10 = readl(*spi_cfg + uVar11);
    }
    else {
      local_6c = 0;
      qcom_scm_io_readl(*spi_cfg + uVar11,&local_6c);
      uVar10 = local_6c;
    }
    uVar14 = (uint)(1L << ((ulong)(uint)(iVar5 % 0x20) & 0x3f));
    uVar1 = uVar10 | uVar14;
    if ((uVar4 & 0xfffffffb) != 3) {
      uVar1 = uVar10 & (uVar14 ^ 0xffffffff);
    }
    if ((char)spi_cfg[2] == '\0') {
      writel(uVar1,*spi_cfg + uVar11);
    }
    else {
      qcom_scm_io_writel(*spi_cfg + uVar11);
    }
    ipc_log_string(pdc_ipc_log,"SPI config: GIC-SPI=%d (reg=%d,bit=%d) val=%d",iVar5,iVar12 >> 5,
                   (ulong)(uint)(iVar5 % 0x20),uVar2 & 4);
    _raw_spin_unlock_irqrestore(&pdc_lock,uVar13);
  }
  uVar13 = irq_chip_set_type_parent(param_1,uVar2);
  if ((int)uVar13 == 0) {
    if (uVar9 != uVar3) {
      irq_chip_set_parent_state(param_1,0,0);
    }
    uVar13 = 0;
  }
LAB_00100b68:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}



//------------------------------------------------------------
// pdc_enable_intr @ 00100db4 size=340
// signature: undefined pdc_enable_intr(void)
// callers: [qcom_pdc_gic_enable, qcom_pdc_gic_disable]
//------------------------------------------------------------

void pdc_enable_intr(long param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  
  uVar3 = _raw_spin_lock_irqsave(&pdc_lock);
  uVar8 = *(ulong *)(param_1 + 8);
  uVar7 = (uint)uVar8;
  if ((enable_in_cfg & 1) == 0) {
    uVar4 = uVar7 + 0x1f;
    if (-1 < (int)uVar7) {
      uVar4 = uVar7;
    }
    lVar9 = (ulong)(uint)((int)uVar4 >> 5) * 4;
    uVar2 = readl_relaxed(pdc_base + lVar9 + 0x10);
    uVar5 = (uint)(1L << ((ulong)(uVar7 - (uVar4 & 0x20)) & 0x3f));
    uVar4 = uVar5 | uVar2;
    if ((param_2 & 1) == 0) {
      uVar4 = uVar2 & (uVar5 ^ 0xffffffff);
    }
    lVar6 = 0x10;
  }
  else {
    lVar9 = (uVar8 & 0xffffffff) * 4;
    uVar2 = readl_relaxed(pdc_base + lVar9 + 0x110);
    uVar4 = 8;
    if ((param_2 & 1) == 0) {
      uVar4 = 0;
    }
    uVar4 = uVar2 & 0xfffffff7 | uVar4;
    lVar6 = 0x110;
  }
  writel_relaxed(uVar4,pdc_base + lVar6 + lVar9);
  if (0xff < uVar7) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100f04);
    (*pcVar1)();
  }
  if (0xbf8 < ((uVar8 & 0xffffffff) + (uVar8 & 0xffffffff) * 2) * 4) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0x100f08);
    (*pcVar1)();
  }
  (&DAT_00101524)[(uVar8 & 0xffffffff) * 3] = param_2 & 1;
  _raw_spin_unlock_irqrestore(&pdc_lock,uVar3);
  ipc_log_string(pdc_ipc_log,"PIN=%lu enable=%d",*(undefined8 *)(param_1 + 8),param_2 & 1);
  return;
}



//------------------------------------------------------------
// readl @ 00100f08 size=140
// signature: undefined readl(void)
// callers: [qcom_pdc_gic_set_type]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x100f60,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00100f94 size=136
// signature: undefined writel(void)
// callers: [qcom_pdc_gic_set_type]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100fac,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100fec,uVar1);
  return;
}



//------------------------------------------------------------
// pdc_resume @ 00101020 size=296
// signature: undefined pdc_resume(void)
// callers: []
//------------------------------------------------------------

void pdc_resume(void)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (pdc_save_restore == '\x01') {
    uVar4 = 0;
    do {
      if ((&DAT_00101520)[uVar4 * 0xc] != '\0') {
        uVar5 = uVar4 * 4;
        writel_relaxed((&pdc_irq_config)[uVar4 * 3],pdc_base + uVar5 + 0x110);
        while( true ) {
          iVar1 = readl_relaxed(pdc_base + uVar5 + 0x110);
          if (iVar1 == (&pdc_irq_config)[uVar4 * 3]) break;
          __const_udelay(0x53e3);
        }
        if ((&DAT_00101524)[uVar4 * 3] != 0) {
          if ((enable_in_cfg & 1) == 0) {
            uVar5 = uVar4 >> 3 & 0x1ffffffc;
            uVar2 = readl_relaxed(pdc_base + uVar5 + 0x10);
            uVar2 = uVar2 | 1 << (ulong)((uint)uVar4 & 0x1f);
            lVar3 = 0x10;
          }
          else {
            uVar2 = readl_relaxed(pdc_base + uVar5 + 0x110);
            lVar3 = 0x110;
            uVar2 = uVar2 | 8;
          }
          writel_relaxed(uVar2,pdc_base + lVar3 + uVar5);
          (&DAT_00101524)[uVar4 * 3] = 1;
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0x100);
  }
  return;
}



//------------------------------------------------------------
// pdc_suspend_notifier @ 0010114c size=88
// signature: undefined pdc_suspend_notifier(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pdc_suspend_notifier(undefined8 param_1,long param_2)

{
  if (param_2 == 1) {
LAB_0010117c:
    pdc_save_restore = 1;
  }
  else {
    if (param_2 != 2) {
      if ((param_2 == 3) && (_pm_suspend_target_state == 3)) goto LAB_0010117c;
      if (param_2 != 4) {
        return 1;
      }
      if (_pm_suspend_target_state != 3) {
        return 1;
      }
    }
    pdc_save_restore = 0;
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 001011b0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_pdc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// of_iomap @ 00104008 size=1
// signature: undefined of_iomap(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_find_matching_fwspec @ 00104010 size=1
// signature: undefined irq_find_matching_fwspec(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_find_matching_fwspec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00104018 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00104020 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00104028 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00104030 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_create_hierarchy @ 00104038 size=1
// signature: undefined irq_domain_create_hierarchy(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_create_hierarchy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_update_bus_token @ 00104040 size=1
// signature: undefined irq_domain_update_bus_token(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_update_bus_token(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_syscore_ops @ 00104048 size=1
// signature: undefined register_syscore_ops(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00104050 size=1
// signature: undefined register_pm_notifier(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_syscore_ops @ 00104058 size=1
// signature: undefined unregister_syscore_ops(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00104060 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104070 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104078 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00104088 size=1
// signature: undefined ioremap_prot(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104090 size=1
// signature: undefined _printk(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104098 size=1
// signature: undefined kfree(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 001040a0 size=1
// signature: undefined iounmap(void)
// callers: [qcom_pdc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_pdc_init, qcom_pdc_alloc, qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001040b0 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 001040b8 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001040c0 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 001040c8 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_translate_twocell @ 001040d0 size=1
// signature: undefined irq_domain_translate_twocell(void)
// callers: [qcom_pdc_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_translate_twocell(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_set_hwirq_and_chip @ 001040d8 size=1
// signature: undefined irq_domain_set_hwirq_and_chip(void)
// callers: [qcom_pdc_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_set_hwirq_and_chip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_disconnect_hierarchy @ 001040e0 size=1
// signature: undefined irq_domain_disconnect_hierarchy(void)
// callers: [qcom_pdc_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_disconnect_hierarchy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001040e8 size=1
// signature: undefined ipc_log_string(void)
// callers: [pdc_enable_intr, qcom_pdc_alloc, qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_alloc_irqs_parent @ 001040f0 size=1
// signature: undefined irq_domain_alloc_irqs_parent(void)
// callers: [qcom_pdc_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_alloc_irqs_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_enable_parent @ 001040f8 size=1
// signature: undefined irq_chip_enable_parent(void)
// callers: [qcom_pdc_gic_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_enable_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_disable_parent @ 00104100 size=1
// signature: undefined irq_chip_disable_parent(void)
// callers: [qcom_pdc_gic_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_disable_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104108 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [pdc_enable_intr, qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 00104110 size=1
// signature: undefined qcom_scm_io_readl(void)
// callers: [qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_readl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 00104118 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104120 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [pdc_enable_intr, qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_type_parent @ 00104128 size=1
// signature: undefined irq_chip_set_type_parent(void)
// callers: [qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_type_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_parent_state @ 00104130 size=1
// signature: undefined irq_chip_set_parent_state(void)
// callers: [qcom_pdc_gic_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_parent_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00104138 size=1
// signature: undefined __const_udelay(void)
// callers: [pdc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



