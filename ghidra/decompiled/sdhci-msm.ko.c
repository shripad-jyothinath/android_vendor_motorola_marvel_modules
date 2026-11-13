// Decompiled by Ghidra 12.2
// Program: sdhci-msm.ko
// Image base: 00100000

//------------------------------------------------------------
// sdhci_msm_ice_disable @ 001012ec size=40
// signature: undefined sdhci_msm_ice_disable(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_ice_disable(long param_1)

{
  if ((*(byte *)(*(long *)(param_1 + 0x98) + 0x3eb) >> 3 & 1) != 0) {
    crypto_qti_disable();
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_cqe_sdhci_dumpregs @ 00101318 size=32
// signature: undefined sdhci_msm_cqe_sdhci_dumpregs(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_cqe_sdhci_dumpregs(long param_1)

{
  sdhci_dumpregs(param_1 + 0x740);
  return;
}



//------------------------------------------------------------
// sdhci_msm_mci_variant_readl_relaxed @ 0010133c size=36
// signature: undefined sdhci_msm_mci_variant_readl_relaxed(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_mci_variant_readl_relaxed(long param_1,uint param_2)

{
  readl_relaxed(*(long *)(param_1 + 0x588) + (ulong)param_2);
  return;
}



//------------------------------------------------------------
// sdhci_msm_mci_variant_writel_relaxed @ 00101364 size=36
// signature: undefined sdhci_msm_mci_variant_writel_relaxed(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_mci_variant_writel_relaxed(undefined8 param_1,long param_2,uint param_3)

{
  writel_relaxed(param_1,*(long *)(param_2 + 0x588) + (ulong)param_3);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00101388 size=124
// signature: undefined readl_relaxed(void)
// callers: [sdhci_msm_v5_variant_readl_relaxed, sdhci_msm_execute_tuning, sdhci_msm_hc_select_mode, msm_config_cm_dll_phase, sdhci_msm_set_uhs_signaling, sdhci_msm_handle_pwr_irq, sdhci_msm_enhanced_strobe_mask, __sdhci_msm_check_write, sdhci_msm_runtime_resume, sdhci_msm_registers_save, sdhci_msm_dump_vendor_regs, msm_init_cm_dll, sdhci_msm_probe, sdhci_msm_remove, sdhci_msm_mci_variant_readl_relaxed, sdhci_msm_cqe_add_host]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1013d0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00101404 size=132
// signature: undefined writel_relaxed(void)
// callers: [sdhci_msm_execute_tuning, sdhci_msm_hc_select_mode, msm_config_cm_dll_phase, sdhci_msm_set_uhs_signaling, sdhci_msm_registers_restore, sdhci_msm_handle_pwr_irq, sdhci_msm_enhanced_strobe_mask, __sdhci_msm_check_write, sdhci_msm_v5_variant_writel_relaxed, sdhci_msm_runtime_resume, sdhci_msm_dump_vendor_regs, sdhci_msm_mci_variant_writel_relaxed, msm_init_cm_dll, sdhci_msm_probe, sdhci_msm_cqe_add_host]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10141c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101458,uVar1);
  return;
}



//------------------------------------------------------------
// sdhci_msm_v5_variant_readl_relaxed @ 0010148c size=36
// signature: undefined sdhci_msm_v5_variant_readl_relaxed(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_v5_variant_readl_relaxed(long param_1,uint param_2)

{
  readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)param_2);
  return;
}



//------------------------------------------------------------
// sdhci_msm_v5_variant_writel_relaxed @ 001014b4 size=36
// signature: undefined sdhci_msm_v5_variant_writel_relaxed(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_v5_variant_writel_relaxed(undefined8 param_1,long param_2,uint param_3)

{
  writel_relaxed(param_1,*(long *)(param_2 + 0x18) + (ulong)param_3);
  return;
}



//------------------------------------------------------------
// sdhci_msm_probe @ 001014dc size=4332
// signature: undefined sdhci_msm_probe(void)
// callers: []
//------------------------------------------------------------

ulong sdhci_msm_probe(long param_1)

{
  bool bVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  ulong uVar11;
  byte *pbVar12;
  ulong uVar13;
  ulong uVar14;
  undefined1 *puVar15;
  long lVar16;
  long lVar17;
  long *plVar18;
  char *pcVar19;
  code *pcVar20;
  ulong uVar21;
  undefined8 uVar22;
  long lVar23;
  undefined8 uVar24;
  undefined4 *puVar25;
  long lVar26;
  int local_c8;
  int local_c4;
  undefined4 **local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 *local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  lVar2 = param_1 + 0x10;
  uVar22 = *(undefined8 *)(param_1 + 0x2f8);
  lVar10 = of_find_property(uVar22,"non-removable",0);
  if (lVar10 != 0) {
    local_c0 = (undefined4 **)0x0;
    local_78 = (undefined4 *)((ulong)local_78 & 0xffffffff00000000);
    uVar11 = nvmem_cell_get(lVar2,"boot_conf");
    if (uVar11 < 0xfffffffffffff001) {
      pbVar12 = (byte *)nvmem_cell_read(uVar11,&local_c0);
      if (pbVar12 < (byte *)0xfffffffffffff001) {
        iVar4 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"boot_device_type",&local_78,1,0);
        if (iVar4 < 0) {
          _dev_warn(lVar2,"boot_device_type not present\n");
        }
        else {
          is_bootdevice_sdhci = (uint)local_78 == (*pbVar12 >> 1 & 0x1f);
          if (!(bool)is_bootdevice_sdhci) {
            _dev_err(lVar2,"boot dev in reg = 0x%x boot dev in dtsi = 0x%x\n");
          }
        }
        kfree(pbVar12);
      }
      else {
        _dev_warn(lVar2,"nvmem cell read failed\n");
      }
      nvmem_cell_put(uVar11);
    }
    else {
      _dev_warn(lVar2,"nvmem cell get failed\n");
    }
    if (is_bootdevice_sdhci == '\0') {
      _dev_err(lVar2,"SDHCI is not boot dev.\n");
      uVar11 = 0;
      goto LAB_0010166c;
    }
  }
  uVar13 = sdhci_pltfm_init(param_1,&sdhci_msm_pdata,0x318);
  if (0xfffffffffffff000 < uVar13) {
    uVar11 = uVar13 & 0xffffffff;
    goto LAB_0010166c;
  }
  *(undefined4 *)(uVar13 + 0x4f8) = 0;
  *(undefined8 *)(uVar13 + 0x618) = *(undefined8 *)(uVar13 + 0x48);
  *(long *)(uVar13 + 0x580) = param_1;
  iVar4 = sysfs_create_group(lVar2,&sdhci_msm_sysfs_group);
  if (iVar4 != 0) {
    _dev_err(lVar2,"%s: Failed to create qcom sysfs group (err = %d)\n","sdhci_msm_init_sysfs",iVar4
            );
  }
  lVar10 = *(long *)(*(long *)(uVar13 + 0x48) + 0x78);
  if (lVar10 == 0) {
    lVar10 = *(long *)(*(long *)(uVar13 + 0x48) + 8);
  }
  lVar10 = ipc_log_context_create(10,lVar10,0);
  *(long *)(uVar13 + 0x828) = lVar10;
  if (lVar10 == 0) {
    _dev_warn(lVar2,"IPC Log init - failed\n");
  }
  lVar10 = *(long *)(uVar13 + 0x48);
  if ((*(long *)(lVar10 + 0x3d0) != 0) && ((*(byte *)(lVar10 + 0x3e5) & 1) == 0)) {
    wakeup_source_unregister(*(long *)(lVar10 + 0x3d0));
    *(undefined8 *)(*(long *)(uVar13 + 0x48) + 0x3d0) = 0;
    lVar10 = *(long *)(uVar13 + 0x48);
  }
  uVar14 = mmc_of_parse(lVar10);
  uVar11 = uVar14 & 0xffffffff;
  if ((int)uVar14 == 0) {
    lVar10 = uVar13 + 0x580;
    if (*(long *)(param_1 + 0x2f8) == 0) {
      uVar11 = 0;
    }
    else {
      uVar5 = of_alias_get_id(*(long *)(param_1 + 0x2f8),&DAT_0010b71a);
      uVar11 = (ulong)uVar5;
      if ((int)uVar5 < 0) {
        _dev_err(lVar2,"get slot index failed %d\n",uVar11);
      }
      else if (uVar5 < 3) {
        *(long *)(&sdhci_slot + uVar11 * 8) = lVar10;
      }
    }
    puVar15 = (undefined1 *)of_device_get_match_data(lVar2);
    if (puVar15 == (undefined1 *)0x0) {
      _dev_err(lVar2,"Compatible string not found\n");
    }
    else {
      *(undefined1 *)(uVar13 + 0x660) = *puVar15;
      *(undefined1 *)(uVar13 + 0x661) = puVar15[1];
      *(undefined8 *)(uVar13 + 0x668) = *(undefined8 *)(puVar15 + 8);
      puVar25 = *(undefined4 **)(puVar15 + 0x10);
      *(undefined4 **)(uVar13 + 0x670) = puVar25;
      sdhci_get_property(param_1);
      uVar24 = *(undefined8 *)(param_1 + 0x2f8);
      iVar4 = of_property_read_variable_u32_array
                        (uVar24,"qcom,ddr-config",(undefined4 *)(uVar13 + 0x820),1,0);
      if (iVar4 < 0) {
        *(undefined4 *)(uVar13 + 0x820) = 0x80040873;
      }
      of_property_read_variable_u32_array(uVar24,"qcom,dll-config",uVar13 + 0x81c,1,0);
      iVar4 = of_device_is_compatible(uVar24,"qcom,msm8916-sdhci");
      if (iVar4 != 0) {
        *(uint *)(uVar13 + 0xc) = *(uint *)(uVar13 + 0xc) | 0x200;
      }
      local_c8 = 0;
      *(undefined1 *)(uVar13 + 0x633) = 0xff;
      uVar24 = *(undefined8 *)(param_1 + 0x2f8);
      local_78 = (undefined4 *)0x0;
      lVar16 = devm_kmalloc(lVar2,0x10,0xdc0);
      *(long *)(uVar13 + 0x610) = lVar16;
      if (lVar16 == 0) {
        pcVar19 = "failed to allocate memory for vreg data\n";
LAB_00101c64:
        _dev_err(lVar2,pcVar19);
      }
      else {
        iVar4 = sdhci_msm_dt_parse_vreg_info(lVar2,lVar16,&DAT_0010bdb7);
        if (iVar4 != 0) {
          pcVar19 = "failed parsing vdd data\n";
          goto LAB_00101c64;
        }
        iVar4 = sdhci_msm_dt_parse_vreg_info(lVar2,*(long *)(uVar13 + 0x610) + 8,"vdd-io");
        if (iVar4 != 0) {
          pcVar19 = "failed parsing vdd-io data\n";
          goto LAB_00101c64;
        }
        lVar16 = of_get_property(uVar24,"qcom,core_3_0v_support",0);
        if (lVar16 != 0) {
          *(undefined1 *)(uVar13 + 0x7a1) = 1;
        }
        lVar16 = of_find_property(uVar24,"qcom,restore-after-cx-collapse",0);
        *(bool *)(uVar13 + 0x7b0) = lVar16 != 0;
        lVar16 = of_find_property(uVar24,"qcom,uses_level_shifter",0);
        *(bool *)(uVar13 + 0x819) = lVar16 != 0;
        if (lVar16 != 0) {
          lVar16 = of_find_property(uVar24,"qcom,external-fb-clk",0);
          *(bool *)(uVar13 + 0x831) = lVar16 != 0;
        }
        lVar16 = of_find_property(uVar24,"qcom,dll_lock_bist_fail_wa",0);
        local_c0 = (undefined4 **)0x0;
        *(bool *)(uVar13 + 0x81a) = lVar16 != 0;
        local_c4 = 0;
        iVar4 = sdhci_msm_dt_get_array(lVar2,"qcom,dll-hsr-list",&local_c0,&local_c4);
        if (iVar4 == 0) {
          if (local_c4 != 5) {
            _dev_err(lVar2,"Number of HSR entries are not matching\n");
            bVar1 = false;
            lVar16 = *(long *)(uVar13 + 0x7a8);
            goto joined_r0x00102168;
          }
          bVar1 = true;
          *(undefined4 ***)(uVar13 + 0x7a8) = local_c0;
          if (*(long *)(uVar13 + 0x7a8) != 0) goto LAB_001018e0;
LAB_0010216c:
          _dev_info(lVar2,"Failed to get dll hsr settings from dt\n");
          if (bVar1) {
LAB_001018e4:
            iVar4 = sdhci_msm_dt_get_array(lVar2,"qcom,ice-clk-rates",&local_78,&local_c8);
            if (((iVar4 == 0) && (local_78 != (undefined4 *)0x0)) && (local_c8 != 0)) {
              if (local_c8 != 2) {
                pcVar19 = "Need max and min frequencies\n";
                goto LAB_00101c64;
              }
              *(undefined4 **)(uVar13 + 0x800) = local_78;
              *(undefined1 *)(uVar13 + 0x808) = 2;
              *(undefined4 *)(uVar13 + 0x80c) = *local_78;
              *(undefined4 *)(uVar13 + 0x810) = local_78[1];
            }
            lVar16 = of_find_property(uVar24,"qcom,vbias-skip-wa",0);
            *(bool *)(uVar13 + 0x796) = lVar16 != 0;
            uVar11 = __devm_reset_control_get(lVar2,"core_reset",0,0,0,1);
            *(ulong *)(uVar13 + 0x798) = uVar11;
            if (0xfffffffffffff000 < uVar11) {
              _dev_err(lVar2,"core_reset unavailable,err = %d\n");
              *(undefined8 *)(uVar13 + 0x798) = 0;
            }
            sdhci_msm_gcc_reset(lVar2,uVar13);
            lVar17 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),
                                      "qcom,restore-after-cx-collapse",0);
            lVar26 = *(long *)(uVar13 + 0x580);
            lVar23 = *(long *)(uVar13 + 0x618);
            lVar16 = lVar26 + 0x10;
            *(bool *)(uVar13 + 0x7b0) = lVar17 != 0;
            uVar11 = devm_clk_get(lVar16,&DAT_0010a906);
            *(ulong *)(uVar13 + 0x5a8) = uVar11;
            if (uVar11 < 0xfffffffffffff001) {
              uVar14 = clk_set_rate(uVar11,0x7fffffff);
              uVar11 = uVar14 & 0xffffffff;
              if ((int)uVar14 == 0) {
                uVar21 = *(ulong *)(uVar13 + 0x5a8);
                uVar14 = clk_prepare(uVar21);
                uVar11 = uVar14 & 0xffffffff;
                if ((int)uVar14 == 0) {
                  uVar5 = clk_enable(uVar21);
                  if (uVar5 == 0) goto LAB_001019d8;
                  uVar11 = (ulong)uVar5;
                  goto LAB_001024d4;
                }
              }
            }
            else {
LAB_001019d8:
              uVar11 = devm_clk_get(lVar16,"iface");
              if (uVar11 < 0xfffffffffffff001) {
                *(ulong *)(uVar13 + 0x5d0) = uVar11;
                uVar11 = devm_clk_get(lVar16,&DAT_0010af3f);
                if (0xfffffffffffff000 < uVar11) {
                  _dev_err(lVar16,"SDC MMC clk setup failed (%d)\n",uVar11 & 0xffffffff);
                  goto LAB_00101ce8;
                }
                *(ulong *)(uVar13 + 0x5c0) = uVar11;
                uVar14 = dev_pm_opp_of_find_icc_paths(lVar16,0);
                uVar11 = uVar14 & 0xffffffff;
                if ((int)uVar14 != 0) goto LAB_00101ce8;
                local_c0 = &local_78;
                local_78 = (undefined4 *)&DAT_0010af3f;
                uStack_70 = 0;
                local_88 = 0;
                uStack_80 = 0;
                local_98 = 0;
                uStack_90 = 0;
                local_a8 = 0;
                uStack_a0 = 0;
                local_b8 = 0;
                uStack_b0 = 0;
                uVar5 = dev_pm_opp_set_config(lVar16,&local_c0);
                *(uint *)(uVar13 + 0x620) = uVar5;
                if ((int)uVar5 < 1) {
                  uVar11 = (ulong)uVar5;
                  goto LAB_00101ce8;
                }
                uVar5 = dev_pm_opp_of_add_table(lVar16);
                if (uVar5 != 0xffffffed) {
                  uVar11 = (ulong)uVar5;
                  if (uVar5 == 0) {
                    *(undefined1 *)(uVar13 + 0x624) = 1;
                    goto LAB_00101a84;
                  }
                  _dev_err(lVar16,"Invalid OPP table in Device tree\n");
                  cVar3 = *(char *)(uVar13 + 0x624);
joined_r0x0010251c:
                  if (cVar3 != '\0') {
                    dev_pm_opp_of_remove_table(lVar16);
                  }
                  dev_pm_opp_clear_config(*(undefined4 *)(uVar13 + 0x620));
                  goto LAB_00101ce8;
                }
LAB_00101a84:
                iVar4 = dev_pm_opp_set_rate(lVar16,0x7fffffff);
                if (iVar4 != 0) {
                  _dev_warn(lVar16,"core clock boost failed\n");
                }
                *(undefined8 *)(uVar13 + 0x5e0) = 0;
                uVar11 = devm_clk_get(lVar16,"ice_core");
                if (uVar11 < 0xfffffffffffff001) {
                  *(ulong *)(uVar13 + 0x5e0) = uVar11;
                  uVar5 = clk_set_rate(uVar11,*(undefined4 *)(uVar13 + 0x80c));
                  if (uVar5 != 0) {
                    uVar11 = (ulong)uVar5;
                    _dev_err(lVar16,"ICE_CLK rate set failed (%d) for %u\n",uVar11);
                    goto LAB_00101ce8;
                  }
                  *(undefined4 *)(uVar13 + 0x814) = *(undefined4 *)(uVar13 + 0x80c);
                }
                lVar17 = uVar13 + 0x5b8;
                uVar14 = devm_clk_get(lVar16,&DAT_0010b0b6);
                uVar11 = 0;
                if (uVar14 < 0xfffffffffffff001) {
                  uVar11 = uVar14;
                }
                *(ulong *)(uVar13 + 0x5f0) = uVar11;
                uVar14 = devm_clk_get(lVar16,"sleep");
                uVar11 = 0;
                if (uVar14 < 0xfffffffffffff001) {
                  uVar11 = uVar14;
                }
                *(ulong *)(uVar13 + 0x600) = uVar11;
                uVar14 = clk_bulk_prepare(5,lVar17);
                uVar11 = uVar14 & 0xffffffff;
                if ((int)uVar14 != 0) {
LAB_00101b38:
                  cVar3 = *(char *)(uVar13 + 0x624);
                  goto joined_r0x0010251c;
                }
                uVar5 = clk_bulk_enable(5,lVar17);
                if (uVar5 != 0) {
                  uVar11 = (ulong)uVar5;
LAB_00101b2c:
                  clk_bulk_unprepare(5,lVar17);
                  goto LAB_00101b38;
                }
                iVar4 = qcom_clk_set_flags(*(undefined8 *)(uVar13 + 0x5c0),3);
                if (iVar4 != 0) {
                  _dev_err(lVar16,"Failed to set core clk NORETAIN_MEM: %d\n",iVar4);
                }
                iVar4 = qcom_clk_set_flags(*(undefined8 *)(uVar13 + 0x5e0),2);
                if (iVar4 != 0) {
                  _dev_err(lVar16,"Failed to set ice clk RETAIN_MEM: %d\n",iVar4);
                }
                lVar23 = lVar23 + 0x740;
                uVar11 = devm_clk_get(lVar16,&DAT_0010b0ba);
                *(ulong *)(uVar13 + 0x5b0) = uVar11;
                if (0xfffffffffffff000 < uVar11) {
                  _dev_warn(lVar16,"TCXO clk not present (%d)\n",uVar11);
                }
                uVar5 = sdhci_msm_bus_register(lVar10,lVar26);
                if (uVar5 == 0) {
                  if (*(char *)(uVar13 + 0x681) == '\0') {
                    sdhci_msm_bus_voting(lVar23,1);
                  }
                }
                else if (*(char *)(uVar13 + 0x681) == '\0') {
                  uVar11 = (ulong)uVar5;
                  _dev_err(lVar16,"Bus registration failed (%d)\n",uVar11);
                  clk_bulk_disable(5,lVar17);
                  goto LAB_00101b2c;
                }
                if (*(char *)(uVar13 + 0x831) != '\0') {
                  sdhci_enable_ext_fb_clk(lVar23);
                }
              }
              else {
                _dev_err(lVar16,"Peripheral clk setup failed (%d)\n",uVar11 & 0xffffffff);
LAB_00101ce8:
                uVar14 = *(ulong *)(uVar13 + 0x5a8);
                if (uVar14 < 0xfffffffffffff001) {
                  clk_disable(uVar14);
                  clk_unprepare(uVar14);
                }
                if ((int)uVar11 != 0) goto LAB_00101664;
              }
              uVar5 = sdhci_msm_vreg_init(lVar2,lVar10,1);
              if (uVar5 == 0) {
                if (*(char *)(uVar13 + 0x660) == '\0') {
                  uVar11 = devm_platform_ioremap_resource(param_1,1);
                  *(ulong *)(uVar13 + 0x588) = uVar11;
                  if (0xfffffffffffff000 < uVar11) {
                    uVar11 = uVar11 & 0xffffffff;
                    goto LAB_00102458;
                  }
                }
                plVar18 = (long *)platform_get_resource_byname(param_1,0x200,"tlmm_mem");
                if (plVar18 != (long *)0x0) {
                  lVar16 = devm_ioremap(lVar2,*plVar18,(plVar18[1] - *plVar18) + 1);
                  if (lVar16 == 0) {
                    _dev_err(lVar2,"Failed to remap tlmm registers\n");
                    uVar11 = 0xfffffff4;
                    goto LAB_00102458;
                  }
                  uVar5 = readl_relaxed();
                  writel_relaxed(uVar5 | 2,lVar16);
                }
                writel_relaxed(0xa9c,*(long *)(uVar13 + 0x18) + (ulong)(uint)puVar25[0x11]);
                uVar5 = readl_relaxed(*(long *)(uVar13 + 0x18) + (ulong)(uint)puVar25[0x18]);
                writel_relaxed(uVar5 & 0xfffffbff,
                               *(long *)(uVar13 + 0x18) + (ulong)(uint)puVar25[0x18]);
                if (*(char *)(uVar13 + 0x660) == '\0') {
                  pcVar20 = *(code **)(*(long *)(uVar13 + 0x668) + 8);
                  if (*(int *)(pcVar20 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x101df8);
                    (*pcVar20)();
                  }
                  (*pcVar20)(1,uVar13,*puVar25);
                  if (*(int *)((code *)**(undefined8 **)(uVar13 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x101e24);
                    (*pcVar20)();
                  }
                  uVar5 = (*(code *)**(undefined8 **)(uVar13 + 0x668))(uVar13,*puVar25);
                  pcVar20 = *(code **)(*(long *)(uVar13 + 0x668) + 8);
                  if (*(int *)(pcVar20 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x101e54);
                    (*pcVar20)();
                  }
                  (*pcVar20)(uVar5 | 0x2000,uVar13,*puVar25);
                }
                lVar16 = of_find_property(uVar22,"is_rumi",0);
                if (lVar16 != 0) {
                  lVar16 = *(long *)(uVar13 + 0x670);
                  uVar5 = readl_relaxed(*(long *)(uVar13 + 0x18) + (ulong)*(uint *)(lVar16 + 0x58));
                  if ((*(byte *)(*(long *)(uVar13 + 0x48) + 0x3e5) & 1) == 0) {
                    writel_relaxed(uVar5 & 0xfffffff8,
                                   *(long *)(uVar13 + 0x18) + (ulong)*(uint *)(lVar16 + 0x58));
                  }
                }
                lVar16 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,no-partial-init",0)
                ;
                *(bool *)(uVar13 + 0x878) = lVar16 != 0;
                readw_relaxed(*(long *)(uVar13 + 0x18) + 0xfe);
                if (*(int *)((code *)**(undefined8 **)(uVar13 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
                  pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x101efc);
                  (*pcVar20)();
                }
                uVar11 = (*(code *)**(undefined8 **)(uVar13 + 0x668))(uVar13,puVar25[4]);
                lVar16 = *(long *)(uVar13 + 0x670);
                if (*(int *)((code *)**(undefined8 **)(uVar13 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
                  pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x101f30);
                  (*pcVar20)();
                }
                uVar6 = (*(code *)**(undefined8 **)(uVar13 + 0x668))
                                  (uVar13,*(undefined4 *)(lVar16 + 0x10));
                uVar7 = readl_relaxed(*(long *)(uVar13 + 0x18) + 0x40);
                uVar5 = uVar6 & 0xf0000000;
                if ((uVar5 == 0x10000000) && ((uVar6 & 0xff) < 0x34)) {
                  *(undefined1 *)(uVar13 + 0x634) = 1;
                }
                else if ((uVar5 == 0x10000000) && (0x41 < (uVar6 & 0xff))) {
                  *(undefined1 *)(uVar13 + 0x630) = 1;
                }
                if (*(char *)(uVar13 + 0x7a1) != '\0') {
                  uVar7 = uVar7 | 0x2000000;
                  uVar8 = readl_relaxed(*(long *)(uVar13 + 0x18) + 0x40);
                  writel_relaxed(uVar8 | uVar7,
                                 *(long *)(uVar13 + 0x18) + (ulong)*(uint *)(lVar16 + 0x54));
                }
                writel_relaxed(uVar7,*(long *)(uVar13 + 0x18) + (ulong)*(uint *)(lVar16 + 0x54));
                *(uint *)(uVar13 + 0x65c) = uVar7;
                if (((uVar5 == 0x10000000) && (uVar5 = (uVar6 & 0xff) - 0x6e, uVar5 < 5)) &&
                   ((1 << (ulong)(uVar5 & 0x1f) & 0x19U) != 0)) {
                  *(undefined1 *)(uVar13 + 0x7a2) = 1;
                }
                uVar5 = (uint)uVar11 & 0xff;
                if (((uVar11 & 0xffffffff) >> 0x1c != 0) && (uVar5 - 0x13 < 0xfffffffe)) {
                  uVar7 = readl_relaxed(*(long *)(uVar13 + 0x18) + 0x40);
                  writel_relaxed(uVar7 | 0x2040000,
                                 *(long *)(uVar13 + 0x18) + (ulong)(uint)puVar25[0x15]);
                }
                uVar7 = (uint)uVar11 & 0xf0000000;
                if ((uVar7 == 0x10000000) && (0x48 < uVar5)) {
                  *(undefined1 *)(uVar13 + 0x680) = 1;
                }
                bVar1 = (uVar7 == 0x10000000 && 0x69 < uVar5) &&
                        (uVar7 != 0x10000000 || uVar5 != 0x6a);
                if (bVar1) {
                  *(undefined1 *)(uVar13 + 0x794) = 1;
                }
                if ((uVar7 == 0x10000000) && (0x70 < uVar5)) {
                  *(undefined1 *)(uVar13 + 0x818) = 1;
                }
                uVar14 = mmc_regulator_get_supply(*(undefined8 *)(uVar13 + 0x618));
                uVar11 = uVar14 & 0xffffffff;
                if ((int)uVar14 == 0) {
                  lVar16 = *(long *)(uVar13 + 0x618);
                  uVar11 = *(ulong *)(lVar16 + 0x5c8);
                  if (uVar11 < 0xfffffffffffff001) {
                    lVar23 = *(long *)(uVar13 + 0x670);
                    iVar4 = regulator_is_supported_voltage(uVar11,1700000,0x1dc130);
                    iVar9 = regulator_is_supported_voltage(uVar11,2700000,3600000);
                    uVar5 = (uint)(iVar4 != 0) << 0x1a;
                    if (iVar9 != 0) {
                      uVar5 = (uint)(iVar4 != 0) << 0x1a | 0x2000000;
                    }
                    if (iVar9 == 0 && iVar4 == 0) {
                      lVar23 = *(long *)(lVar16 + 0x78);
                      if (lVar23 == 0) {
                        lVar23 = *(long *)(lVar16 + 8);
                      }
                      _printk(&DAT_0010b59b,lVar23);
                      uVar5 = 0;
                    }
                    else {
                      uVar7 = *(uint *)(uVar13 + 0x63c);
                      uVar6 = readl_relaxed(*(long *)(lVar16 + 0x758) +
                                            (ulong)*(uint *)(lVar23 + 0x44));
                      if (((uVar7 >> 3 & 1) == 0) || ((uVar5 >> 0x19 & 1) == 0)) {
                        uVar8 = uVar6 | 0x8000;
                        if (iVar4 != 0 || (uVar7 & 4) != 0) {
                          uVar8 = uVar6 | 0x18000;
                        }
                      }
                      else {
                        uVar8 = uVar6 & 0xfffeffff | 0x8000;
                      }
                      writel_relaxed(uVar8,*(long *)(lVar16 + 0x758) +
                                           (ulong)*(uint *)(lVar23 + 0x44));
                    }
                  }
                  else {
                    uVar5 = 0;
                  }
                  *(uint *)(uVar13 + 0x65c) = *(uint *)(uVar13 + 0x65c) | uVar5;
                  uVar14 = sdhci_msm_setup_pwr_irq(lVar10);
                  uVar11 = uVar14 & 0xffffffff;
                  if ((int)uVar14 == 0) {
                    *(uint *)(*(long *)(uVar13 + 0x618) + 0x3e4) =
                         *(uint *)(*(long *)(uVar13 + 0x618) + 0x3e4) | 0x80;
                    *(uint *)(*(long *)(uVar13 + 0x618) + 0x3e4) =
                         *(uint *)(*(long *)(uVar13 + 0x618) + 0x3e4) | 0x400200;
                    sdhci_msm_setup_pm(param_1,lVar10);
                    *(code **)(uVar13 + 0xa0) = sdhci_msm_start_signal_voltage_switch;
                    *(code **)(uVar13 + 0xb0) = sdhci_msm_execute_tuning;
                    lVar16 = alloc_workqueue(&DAT_0010acaf,0x40008,1,"sdhci_msm_generic_swq");
                    *(long *)(uVar13 + 0x718) = lVar16;
                    if (lVar16 == 0) {
                      _dev_err(lVar2,"Generic swq creation failed\n");
                    }
                    *(undefined4 *)(uVar13 + 0x790) = 10;
                    sdhci_msm_qos_init(lVar10);
                    sdhci_msm_init_sysfs_gating_qos(lVar2);
                    lVar10 = of_find_property(uVar22,"supports-cqe",0);
                    if (lVar10 == 0) {
                      uVar14 = sdhci_add_host(uVar13);
                    }
                    else {
                      uVar14 = sdhci_msm_cqe_add_host(uVar13,param_1);
                    }
                    uVar11 = uVar14 & 0xffffffff;
                    if ((int)uVar14 == 0) {
                      lVar10 = of_find_property(uVar22,"mmc-rst-n-disable",0);
                      *(bool *)(uVar13 + 0x879) = lVar10 != 0;
                      if (bVar1) {
                        *(undefined1 *)(uVar13 + 0x794) = 1;
                      }
                      *(undefined1 *)(uVar13 + 0x7a0) = 1;
                      uVar22 = ktime_get_mono_fast_ns();
                      *(undefined8 *)(param_1 + 0x230) = uVar22;
                      __pm_runtime_suspend(lVar2,0xd);
                      lVar10 = *(long *)(uVar13 + 0x48);
                      if ((*(byte *)(lVar10 + 0x3e5) & 1) != 0) {
                        android_rvh_probe_register
                                  (&__tracepoint_android_rvh_mmc_suspend,sdhci_msm_mmc_suspend,0);
                        android_rvh_probe_register
                                  (&__tracepoint_android_rvh_mmc_resume,sdhci_msm_mmc_resume,0);
                        lVar10 = *(long *)(uVar13 + 0x48);
                      }
                      if (((*(uint *)(lVar10 + 1000) ^ 0xffffffff) & 0x480000) != 0) {
                        uVar11 = 0;
                        goto LAB_0010166c;
                      }
                      *(code **)(uVar13 + 0x880) = sdhci_msm_hibernation_notifier;
                      uVar14 = register_pm_notifier(uVar13 + 0x880);
                      uVar11 = uVar14 & 0xffffffff;
                      if ((int)uVar14 == 0) goto LAB_0010166c;
                      _dev_err(lVar2,"%s: register pm notifier failed: %d\n","sdhci_msm_probe",
                               uVar11);
                    }
                    __pm_runtime_disable(lVar2,1);
                    __pm_runtime_set_status(lVar2,2);
                    pm_runtime_put_noidle(lVar2);
                  }
                }
              }
              else {
                uVar11 = (ulong)uVar5;
                _dev_err(lVar2,"Regulator setup failed (%d)\n",uVar11);
              }
LAB_00102458:
              if (*(char *)(uVar13 + 0x681) == '\0') {
                sdhci_msm_bus_get_and_set_vote(uVar13,0);
                lVar10 = *(long *)(uVar13 + 0x688);
                if (*(long *)(lVar10 + 0x28) != 0) {
                  icc_put();
                }
                if (*(long *)(lVar10 + 0x30) != 0) {
                  icc_put();
                }
              }
              clk_bulk_disable(5,uVar13 + 0x5b8);
              clk_bulk_unprepare(5,uVar13 + 0x5b8);
              if (*(char *)(uVar13 + 0x624) != '\0') {
                dev_pm_opp_of_remove_table(lVar2);
              }
              dev_pm_opp_clear_config(*(undefined4 *)(uVar13 + 0x620));
              uVar21 = *(ulong *)(uVar13 + 0x5a8);
              if (uVar21 < 0xfffffffffffff001) {
                clk_disable(uVar21);
LAB_001024d4:
                clk_unprepare(uVar21);
              }
            }
            goto LAB_00101664;
          }
        }
        else {
          bVar1 = true;
          lVar16 = *(long *)(uVar13 + 0x7a8);
joined_r0x00102168:
          if (lVar16 == 0) goto LAB_0010216c;
LAB_001018e0:
          if (bVar1) goto LAB_001018e4;
        }
      }
      _dev_err(lVar2,"DT parsing error\n");
      uVar11 = 1;
    }
  }
LAB_00101664:
  sdhci_pltfm_free(param_1);
LAB_0010166c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// sdhci_msm_remove @ 001025cc size=732
// signature: undefined sdhci_msm_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sdhci_msm_remove(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  undefined8 *puVar12;
  long lVar13;
  undefined8 *puVar14;
  uint uVar15;
  
  lVar10 = param_1 + 0x10;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"non-removable",0);
  if ((lVar8 == 0) || (is_bootdevice_sdhci != '\0')) {
    lVar8 = *(long *)(param_1 + 0xa8);
    puVar14 = *(undefined8 **)(lVar8 + 0x720);
    iVar5 = readl_relaxed(*(long *)(lVar8 + 0x18) + 0x30);
    if (((*(uint *)(*(long *)(lVar8 + 0x48) + 1000) ^ 0xffffffff) & 0x480000) == 0) {
      unregister_pm_notifier(lVar8 + 0x880);
    }
    sdhci_remove_host(lVar8,iVar5 == -1);
    if (*(char *)(lVar8 + 0x624) != '\0') {
      dev_pm_opp_of_remove_table(lVar10);
    }
    dev_pm_opp_clear_config(*(undefined4 *)(lVar8 + 0x620));
    __pm_runtime_resume(lVar10,4);
    if (puVar14 != (undefined8 *)0x0) {
      puVar12 = (undefined8 *)*puVar14;
      msleep(0x32);
      if (*(int *)(puVar14 + 1) != 0) {
        uVar15 = 0;
        do {
          lVar13 = puVar12[2];
          lVar9 = *(long *)(puVar12[4] + 0x2a8);
          if ((lVar9 != 0) && (*(char *)(puVar12[4] + 0x2b0) != '\0')) {
            ipc_log_string(lVar9,"%s: mask: 0x%08x type: %d vote: %u\n",
                           "sdhci_msm_update_qos_constraints",*puVar12,2,0x7fffffff);
          }
          iVar5 = 0;
          while (uVar6 = _find_next_bit(puVar12,_nr_cpu_ids,(long)iVar5), uVar7 = _nr_cpu_ids,
                uVar6 < _nr_cpu_ids) {
            iVar5 = dev_pm_qos_update_request(lVar13,0x7fffffff);
            if (iVar5 < 0) {
              uVar7 = _nr_cpu_ids;
              goto LAB_00102750;
            }
            lVar13 = lVar13 + 0x50;
            iVar5 = uVar6 + 1;
          }
          *(undefined1 *)(puVar12 + 3) = 0;
          *(undefined1 *)((long)puVar12 + 0x29) = 1;
LAB_00102750:
          iVar5 = 0;
          lVar13 = puVar12[2];
          while ((uVar7 = _find_next_bit(puVar12,uVar7,(long)iVar5), uVar7 < _nr_cpu_ids &&
                 ((*(long *)(lVar13 + 0x48) == 0 ||
                  (iVar5 = dev_pm_qos_remove_request(lVar13), -1 < iVar5))))) {
            lVar13 = lVar13 + 0x50;
            iVar5 = uVar7 + 1;
            uVar7 = _nr_cpu_ids;
          }
          uVar15 = uVar15 + 1;
          puVar12 = puVar12 + 6;
        } while (uVar15 < *(uint *)(puVar14 + 1));
      }
      destroy_workqueue(*(undefined8 *)(lVar8 + 0x718));
    }
    __pm_runtime_disable(lVar10,1);
    piVar1 = (int *)(param_1 + 0x208);
    iVar5 = *(int *)(param_1 + 0x208);
    do {
      if (iVar5 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar5) goto LAB_001027dc;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar5 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_001027dc:
      bVar4 = iVar5 != iVar2;
      iVar5 = iVar2;
    } while (bVar4);
    clk_bulk_disable(5,lVar8 + 0x5b8);
    clk_bulk_unprepare(5,lVar8 + 0x5b8);
    uVar11 = *(ulong *)(lVar8 + 0x5a8);
    if (uVar11 < 0xfffffffffffff001) {
      clk_disable(uVar11);
      clk_unprepare(uVar11);
    }
    if (*(char *)(lVar8 + 0x681) == '\0') {
      sdhci_msm_bus_get_and_set_vote(lVar8,0);
      lVar10 = *(long *)(lVar8 + 0x688);
      if (*(long *)(lVar10 + 0x28) != 0) {
        icc_put();
      }
      if (*(long *)(lVar10 + 0x30) != 0) {
        icc_put();
      }
    }
    sdhci_pltfm_free(param_1);
  }
  else {
    _dev_err(lVar10,"SDHCI is not boot dev.\n");
  }
  return 0;
}



//------------------------------------------------------------
// sdhci_msm_gcc_reset @ 001028bc size=160
// signature: undefined sdhci_msm_gcc_reset(void)
// callers: [sdhci_msm_probe, sdhci_msm_hw_reset]
//------------------------------------------------------------

void sdhci_msm_gcc_reset(undefined8 param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x798);
  if (lVar3 == 0) {
    pcVar2 = "unable to acquire core_reset\n";
    iVar1 = -0x5f;
  }
  else {
    iVar1 = reset_control_assert(lVar3);
    if (iVar1 == 0) {
      usleep_range_state(200,0xd2,2);
      iVar1 = reset_control_deassert(lVar3);
      if (iVar1 == 0) {
        usleep_range_state(200,0xd2,2);
        return;
      }
      pcVar2 = "core_reset deassert failed\n";
    }
    else {
      pcVar2 = "core_reset assert failed\n";
    }
  }
  dev_err_probe(param_1,iVar1,pcVar2);
  return;
}



//------------------------------------------------------------
// sdhci_msm_vreg_init @ 0010295c size=384
// signature: undefined sdhci_msm_vreg_init(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

ulong sdhci_msm_vreg_init(undefined8 param_1,long param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 *puVar6;
  
  plVar5 = *(long **)(param_2 + 0x90);
  if ((plVar5 != (long *)0x0) && ((param_3 & 1) != 0)) {
    lVar1 = *plVar5;
    lVar2 = plVar5[1];
    if (lVar1 != 0) {
      if (*(long *)(lVar1 + 8) == 0) {
        puVar6 = (undefined8 *)(lVar1 + 0x10);
        uVar4 = devm_regulator_get(param_1,*puVar6);
        *(ulong *)(lVar1 + 8) = uVar4;
        if (0xfffffffffffff000 < uVar4) {
          _printk(&DAT_0010b872,"sdhci_msm_vreg_init_reg",*puVar6,uVar4 & 0xffffffff);
          if ((int)uVar4 == 0) goto LAB_001029e4;
          goto LAB_001029e8;
        }
        iVar3 = regulator_count_voltages(uVar4);
        if ((iVar3 < 1) ||
           ((*(undefined1 *)(lVar1 + 0x2b) = 1, *(int *)(lVar1 + 0x1c) != 0 &&
            (*(int *)(lVar1 + 0x24) != 0)))) goto LAB_001029dc;
LAB_00102a64:
        _printk(&DAT_0010b89f,"sdhci_msm_vreg_init_reg",*puVar6);
        uVar4 = 0xffffffea;
      }
      else {
LAB_001029dc:
        uVar4 = 0;
LAB_001029e4:
        if (lVar2 != 0) goto LAB_001029f4;
LAB_001029e8:
        if ((int)uVar4 == 0) goto LAB_00102a48;
      }
      _dev_err(param_1,"vreg reset failed (%d)\n",uVar4 & 0xffffffff);
      goto LAB_00102a48;
    }
    if (lVar2 != 0) {
LAB_001029f4:
      if (*(long *)(lVar2 + 8) == 0) {
        puVar6 = (undefined8 *)(lVar2 + 0x10);
        uVar4 = devm_regulator_get(param_1,*puVar6);
        *(ulong *)(lVar2 + 8) = uVar4;
        if (0xfffffffffffff000 < uVar4) {
          _printk(&DAT_0010b872,"sdhci_msm_vreg_init_reg",*puVar6,uVar4 & 0xffffffff);
          goto LAB_001029e8;
        }
        iVar3 = regulator_count_voltages(uVar4);
        if ((0 < iVar3) &&
           ((*(undefined1 *)(lVar2 + 0x2b) = 1, *(int *)(lVar2 + 0x1c) == 0 ||
            (*(int *)(lVar2 + 0x24) == 0)))) goto LAB_00102a64;
      }
    }
  }
  uVar4 = 0;
LAB_00102a48:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// readw_relaxed @ 00102adc size=124
// signature: undefined readw_relaxed(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

undefined2 readw_relaxed(undefined2 *param_1)

{
  ulong uVar1;
  undefined2 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x10,param_1,readw_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x10,param_1,0x102b24,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// sdhci_msm_setup_pwr_irq @ 00102b58 size=256
// signature: undefined sdhci_msm_setup_pwr_irq(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

int sdhci_msm_setup_pwr_irq(long *param_1)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *param_1;
  lVar1 = param_1[0x13] + 0x740;
  sdhci_msm_handle_pwr_irq(lVar1,0);
  DataSynchronizationBarrier(3,3,0);
  iVar4 = platform_get_irq_byname(lVar6,"pwr_irq");
  *(int *)(param_1 + 4) = iVar4;
  if (-1 < iVar4) {
    __init_waitqueue_head
              (param_1 + 0x18,"&msm_host->pwr_irq_wait",&sdhci_msm_init_pwr_irq_wait___key);
    if (*(int *)(*(code **)(param_1[0x1d] + 8) + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102be8);
      (*pcVar3)();
    }
    (**(code **)(param_1[0x1d] + 8))(0xf,lVar1,*(undefined4 *)(param_1[0x1e] + 0x2c));
    lVar5 = *(long *)(lVar6 + 0x80);
    plVar2 = (long *)(lVar6 + 0x10);
    if (lVar5 == 0) {
      lVar5 = *plVar2;
    }
    iVar4 = devm_request_threaded_irq(plVar2,(int)param_1[4],0,sdhci_msm_pwr_irq,0x2000,lVar5,lVar1)
    ;
    if (iVar4 != 0) {
      _dev_err(plVar2,"Request IRQ failed (%d)\n",iVar4);
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// sdhci_msm_setup_pm @ 00102c58 size=128
// signature: undefined sdhci_msm_setup_pm(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void sdhci_msm_setup_pm(long param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  
  lVar1 = param_1 + 0x10;
  piVar2 = (int *)(param_1 + 0x208);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar4) {
      *piVar2 = *piVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  __pm_runtime_set_status(lVar1,0);
  pm_runtime_enable(lVar1);
  if ((*(byte *)(*(long *)(param_2 + 0x98) + 0x3e6) >> 5 & 1) == 0) {
    pm_runtime_set_autosuspend_delay(lVar1,10);
    __pm_runtime_use_autosuspend(lVar1,1);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_start_signal_voltage_switch @ 00102ce8 size=384
// signature: undefined sdhci_msm_start_signal_voltage_switch(void)
// callers: []
//------------------------------------------------------------

undefined8 sdhci_msm_start_signal_voltage_switch(undefined8 *param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  
  if (1 < *(uint *)(param_1 + 0x147)) {
    puVar1 = param_1 + 0xe8;
    pcVar5 = *(code **)(param_1[0xf0] + 8);
    if (pcVar5 == (code *)0x0) {
      uVar2 = readw(param_1[0xeb] + 0x3e);
    }
    else {
      if (*(int *)(pcVar5 + -4) != -0x3310e391) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102de4);
        (*pcVar5)();
      }
      uVar2 = (*pcVar5)(puVar1,0x3e);
    }
    if (*(char *)(param_2 + 0x11) == '\x01') {
      if (-1 < *(char *)((long)param_1 + 0xa35)) {
        return 0xffffffea;
      }
      uVar2 = uVar2 | 8;
    }
    else {
      if ((*(char *)(param_2 + 0x11) != '\0') || ((*(byte *)((long)param_1 + 0xa35) >> 6 & 1) == 0))
      {
        return 0xffffffea;
      }
      uVar2 = uVar2 & 0xfffffff7;
    }
    pcVar5 = *(code **)(param_1[0xf0] + 0x20);
    if (pcVar5 == (code *)0x0) {
      writew(uVar2,param_1[0xeb] + 0x3e);
    }
    else {
      if (*(int *)(pcVar5 + -4) != -0x491fd948) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102e10);
        (*pcVar5)();
      }
      (*pcVar5)(puVar1,uVar2,0x3e);
    }
    usleep_range_state(5000,0x157c,2);
    pcVar5 = *(code **)(param_1[0xf0] + 8);
    if (pcVar5 == (code *)0x0) {
      uVar3 = readw(param_1[0xeb] + 0x3e);
    }
    else {
      if (*(int *)(pcVar5 + -4) != -0x3310e391) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102e38);
        (*pcVar5)();
      }
      uVar3 = (*pcVar5)(puVar1,0x3e);
    }
    if (((uVar3 ^ uVar2) >> 3 & 1) != 0) {
      lVar4 = param_1[0xf];
      if (lVar4 == 0) {
        lVar4 = param_1[1];
      }
      _dev_warn(*param_1,"%s: Regulator output did not became stable\n",lVar4);
      return 0xfffffff5;
    }
  }
  return 0;
}



//------------------------------------------------------------
// sdhci_msm_execute_tuning @ 00102e6c size=832
// signature: undefined sdhci_msm_execute_tuning(void)
// callers: []
//------------------------------------------------------------

uint sdhci_msm_execute_tuning(long param_1,undefined4 param_2)

{
  undefined4 uVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  uint *puVar12;
  int iVar13;
  undefined1 *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x788);
  local_78 = 0;
  uStack_70 = 0;
  lVar11 = *(long *)(param_1 + 0xdb0);
  bVar2 = *(byte *)(lVar8 + 0x420);
  uVar1 = *(undefined4 *)(lVar8 + 0x410);
  if ((bVar2 == 5) && ((*(byte *)(param_1 + 0xa34) >> 4 & 1) != 0)) {
    *(undefined1 *)(param_1 + 0xd71) = 0;
    *(undefined1 *)(param_1 + 0xdb8) = 1;
    uVar5 = readl_relaxed(*(long *)(param_1 + 0x758) + (ulong)*(uint *)(lVar11 + 0x44));
    writel_relaxed(uVar5 & 0xffc00000 | uVar5 & 0x3ffff | 0x240000,
                   *(long *)(param_1 + 0x758) + (ulong)*(uint *)(lVar11 + 0x44));
LAB_00102f88:
    local_80 = (undefined1 *)(param_1 + 0xd71);
    lVar8 = param_1 + 0x740;
    if ((*(byte *)(param_1 + 0xa35) >> 5 & 1) != 0) {
      sdhci_msm_hc_select_mode(lVar8);
      msm_set_clock_rate_for_bus_mode(lVar8,uVar1);
      *(uint *)(param_1 + 0xa34) = *(uint *)(param_1 + 0xa34) & 0xffffdfff;
    }
    puVar12 = (uint *)(lVar11 + 0x44);
    uVar5 = readl_relaxed(*(long *)(param_1 + 0x758) + (ulong)*puVar12);
    writel_relaxed(uVar5 & 0xfffffffd,*(long *)(param_1 + 0x758) + (ulong)*puVar12);
    uVar6 = msm_init_cm_dll(lVar8,0);
    if (uVar6 == 0) {
      iVar13 = 10;
      do {
        uVar10 = 0;
        uVar4 = 0;
        do {
          uVar6 = msm_config_cm_dll_phase(lVar8,uVar4);
          if (uVar6 != 0) goto LAB_0010309c;
          iVar7 = mmc_send_tuning(param_1,param_2,0);
          if (iVar7 == 0) {
            if (0xf < ((uint)uVar10 & 0xff)) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1031a8);
              (*pcVar3)();
            }
            uVar9 = uVar10 & 0xff;
            uVar10 = (ulong)((uint)uVar10 + 1);
            *(char *)((long)&local_78 + uVar9) = (char)uVar4;
          }
          uVar6 = uVar4 & 0xff;
          uVar4 = uVar4 + 1;
        } while (uVar6 < 0xf);
        if ((uVar10 & 0xff) == 0) {
          if (iVar13 == 1) {
            if ((*(long *)(param_1 + 0xf68) != 0) && (*(char *)(param_1 + 0xf70) != '\0')) {
              ipc_log_string(*(long *)(param_1 + 0xf68),"%s: No tuning point found\n",
                             "sdhci_msm_execute_tuning");
            }
            uVar6 = 0xfffffffb;
            break;
          }
        }
        else if ((((uint)uVar10 & 0xff) != 0x10) || (iVar13 == 1)) {
          uVar4 = msm_find_most_appropriate_phase(lVar8,&local_78,uVar10);
          if ((int)uVar4 < 0) {
            uVar6 = uVar4;
          }
          else {
            uVar6 = msm_config_cm_dll_phase(lVar8,uVar4);
            if (uVar6 == 0) {
              *(char *)(param_1 + 0xd73) = (char)uVar4;
              if ((*(long *)(param_1 + 0xf68) != 0) && (*(char *)(param_1 + 0xf70) != '\0')) {
                ipc_log_string(*(long *)(param_1 + 0xf68),"%s: Setting the tuning phase to %d\n",
                               "sdhci_msm_execute_tuning",uVar4 & 0xff);
              }
              *local_80 = 1;
              uVar6 = 0;
            }
          }
          break;
        }
        iVar13 = iVar13 + -1;
        uVar6 = msm_init_cm_dll(lVar8,0);
      } while (uVar6 == 0);
    }
LAB_0010309c:
    if ((uVar5 >> 1 & 1) == 0) goto LAB_001030c8;
    uVar5 = readl_relaxed(*(long *)(param_1 + 0x758) + (ulong)*puVar12);
    uVar5 = uVar5 | 2;
  }
  else {
    if ((((100000000 < *(uint *)(param_1 + 0xa4c)) && (bVar2 < 0xb)) &&
        ((1 << (ulong)(bVar2 & 0x1f) & 0x640U) != 0)) && (*(char *)(lVar8 + 0x423) == '\0')) {
      *(undefined1 *)(param_1 + 0xd71) = 0;
      *(undefined1 *)(param_1 + 0xdb8) = 1;
      goto LAB_00102f88;
    }
    *(undefined1 *)(param_1 + 0xdb8) = 0;
    puVar12 = (uint *)(lVar11 + 0x3c);
    uVar4 = readl_relaxed(*(long *)(param_1 + 0x758) + (ulong)*puVar12);
    uVar6 = 0;
    uVar5 = uVar4 & 0xfffdffff | 0x80000;
    if (uVar5 == uVar4) goto LAB_001030c8;
  }
  writel_relaxed(uVar5,*(long *)(param_1 + 0x758) + (ulong)*puVar12);
LAB_001030c8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// sdhci_msm_qos_init @ 001031ac size=1212
// signature: undefined sdhci_msm_qos_init(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdhci_msm_qos_init(long *param_1)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  long *plVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  undefined8 *puVar13;
  uint uVar14;
  char *pcVar15;
  ulong uVar16;
  long lVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  long lVar20;
  ulong uVar21;
  int local_6c;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  lVar20 = *param_1;
  local_6c = 0;
  uVar18 = *(undefined8 *)(lVar20 + 0x2f8);
  plVar8 = (long *)kmalloc_trace(_of_property_count_elems_of_size,0xdc0,0x10);
  if (plVar8 != (long *)0x0) {
    param_1[0x34] = (long)plVar8;
    lVar9 = of_get_next_available_child(uVar18,0);
    if (lVar9 == 0) {
      *(undefined4 *)(plVar8 + 1) = 0;
    }
    else {
      iVar3 = 0;
      do {
        lVar9 = of_get_next_available_child(uVar18,lVar9);
        iVar3 = iVar3 + -1;
      } while (lVar9 != 0);
      *(int *)(plVar8 + 1) = -iVar3;
      if (iVar3 != 0) {
        uVar21 = (ulong)(uint)-iVar3 * 0x30;
        plVar10 = (long *)__kmalloc(uVar21,0xdc0);
        if (plVar10 == (long *)0x0) {
          param_1[0x34] = 0;
          kfree(plVar8);
        }
        else {
          *plVar8 = (long)plVar10;
          lVar9 = of_get_next_available_child(uVar18,0);
          if (lVar9 != 0) {
            uVar16 = 0;
            do {
              iVar3 = of_property_read_variable_u32_array(lVar9,&DAT_0010a83b,&local_6c,1,0);
              uVar4 = _nr_cpu_ids;
              if (-1 < iVar3) {
                if ((uVar21 < uVar16) || (uVar21 - uVar16 < 8)) goto LAB_00103664;
                *plVar10 = (long)local_6c;
                uVar11 = __bitmap_subset(plVar10,&__cpu_possible_mask,uVar4);
                if ((uVar11 & 1) == 0) {
                  pcVar15 = "Invalid group mask\n";
                  goto LAB_00103594;
                }
                uVar4 = of_property_count_elems_of_size(lVar9,&DAT_0010b6fe,4);
                if ((int)uVar4 < 1) {
                  pcVar15 = "1 vote is needed, bailing out\n";
                  goto LAB_00103594;
                }
                lVar12 = __kmalloc((ulong)uVar4 << 2,0xcc0);
                uVar11 = uVar16 + 8;
                if ((uVar21 < uVar11) || (uVar21 - uVar11 < 8)) {
LAB_00103664:
                    /* WARNING: Does not return */
                  pcVar1 = (code *)SoftwareBreakpoint(1,0x103668);
                  (*pcVar1)();
                }
                plVar10[1] = lVar12;
                if (lVar12 == 0) goto LAB_0010359c;
                lVar12 = 0;
                iVar3 = 0;
                do {
                  if (uVar21 < uVar11 || uVar21 - uVar11 < 8) goto LAB_00103664;
                  iVar5 = of_property_read_u32_index(lVar9,&DAT_0010b6fe,iVar3,plVar10[1] + lVar12);
                  if (iVar5 != 0) goto LAB_0010359c;
                  iVar3 = iVar3 + 1;
                  lVar12 = lVar12 + 4;
                } while ((ulong)uVar4 * 4 != lVar12);
                if ((uVar21 < uVar16 + 0x20) || (uVar21 - (uVar16 + 0x20) < 8)) goto LAB_00103664;
                uVar16 = uVar16 + 0x30;
                plVar10[4] = (long)param_1;
                plVar10 = plVar10 + 6;
              }
              lVar9 = of_get_next_available_child(uVar18,lVar9);
            } while (lVar9 != 0);
          }
          plVar10 = (long *)param_1[0x34];
          if (plVar10 != (long *)0x0) {
            lVar12 = param_1[0x13];
            lVar9 = *plVar10;
            lVar17 = *param_1;
            iVar3 = __irq_apply_affinity_hint(*(undefined4 *)(lVar12 + 0x750),lVar9,1);
            if (iVar3 != 0) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103660);
              (*pcVar1)();
            }
            param_1[0x3c] = (long)sdhci_msm_irq_affinity_notify;
            param_1[0x3d] = (long)sdhci_msm_irq_affinity_release;
            irq_set_affinity_notifier(*(undefined4 *)(lVar12 + 0x750),param_1 + 0x35);
            if ((int)plVar10[1] == 0) {
LAB_001034f8:
              sdhci_msm_update_qos_constraints(*plVar10,0);
              uVar7 = _find_first_bit(*plVar10,_nr_cpu_ids);
              *(undefined4 *)((long)plVar10 + 0xc) = uVar7;
            }
            else {
              iVar3 = 0;
              uVar4 = 0;
              uVar14 = _nr_cpu_ids;
              while( true ) {
                uVar21 = __bitmap_weight(lVar9,uVar14);
                puVar13 = (undefined8 *)__kmalloc((uVar21 & 0xffffffff) * 0x50,0xdc0);
                *(undefined8 **)(lVar9 + 0x10) = puVar13;
                if (puVar13 == (undefined8 *)0x0) break;
                iVar5 = 0;
                puVar19 = puVar13;
                while (uVar6 = _find_next_bit(lVar9,_nr_cpu_ids,(long)iVar5), uVar14 = _nr_cpu_ids,
                      uVar6 < _nr_cpu_ids) {
                  puVar19[8] = 0;
                  puVar19[9] = 0;
                  puVar19[6] = 0;
                  puVar19[7] = 0;
                  puVar19[4] = 0;
                  puVar19[5] = 0;
                  puVar19[2] = 0;
                  puVar19[3] = 0;
                  *puVar19 = 0;
                  puVar19[1] = 0;
                  uVar18 = get_cpu_device(uVar6);
                  iVar5 = dev_pm_qos_add_request(uVar18,puVar19,1,0x7fffffff);
                  if (iVar5 < 0) {
                    _dev_err(lVar17 + 0x10,"Fail (%d) add qos-req: grp-%d\n",iVar5,uVar4);
                    if (uVar4 != 0) goto LAB_0010355c;
                    kfree(*(undefined8 *)(lVar9 + 0x10));
                    goto LAB_0010358c;
                  }
                  puVar19 = puVar19 + 10;
                  iVar5 = uVar6 + 1;
                }
                uVar4 = uVar4 + 1;
                iVar3 = iVar3 + -1;
                *(undefined1 *)(lVar9 + 0x28) = 1;
                lVar9 = lVar9 + 0x30;
                if (*(uint *)(plVar10 + 1) <= uVar4) goto LAB_001034f8;
              }
              _dev_err(lVar17 + 0x10,"Memory allocation failed\n");
              if (uVar4 == 0) goto LAB_0010358c;
LAB_0010355c:
              lVar12 = 0x10;
              do {
                kfree(*(undefined8 *)(lVar9 + lVar12));
                lVar12 = lVar12 + -0x30;
                bVar2 = iVar3 != -1;
                iVar3 = iVar3 + 1;
              } while (bVar2);
              if (puVar13 != (undefined8 *)0x0) {
LAB_0010358c:
                pcVar15 = "Failed to setup PM QoS.\n";
LAB_00103594:
                _dev_err(lVar20 + 0x10,pcVar15);
LAB_0010359c:
                lVar20 = *plVar8;
                if ((int)plVar8[1] != 0) {
                  uVar4 = 0;
                  puVar13 = (undefined8 *)(lVar20 + 8);
                  do {
                    kfree(*puVar13);
                    uVar4 = uVar4 + 1;
                    puVar13 = puVar13 + 6;
                  } while (uVar4 < *(uint *)(plVar8 + 1));
                  lVar20 = *plVar8;
                }
                kfree(lVar20);
                kfree(plVar8);
                param_1[0x34] = 0;
              }
            }
          }
        }
        goto LAB_001035ec;
      }
    }
    _dev_err(lVar20 + 0x10,"QoS groups undefined\n");
    kfree(plVar8);
    param_1[0x34] = 0;
  }
LAB_001035ec:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_init_sysfs_gating_qos @ 0010366c size=136
// signature: undefined sdhci_msm_init_sysfs_gating_qos(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void sdhci_msm_init_sysfs_gating_qos(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  *(code **)(lVar3 + 0x780) = show_sdhci_msm_pm_qos;
  *(code **)(lVar3 + 0x788) = store_sdhci_msm_pm_qos;
  *(undefined2 *)(lVar3 + 0x778) = 0x1a4;
  *(char **)(lVar3 + 0x770) = "pm_qos";
  iVar1 = device_create_file(param_1,lVar3 + 0x770);
  if (iVar1 != 0) {
    lVar2 = *(long *)(*(long *)(lVar3 + 0x48) + 0x78);
    if (lVar2 == 0) {
      lVar2 = *(long *)(*(long *)(lVar3 + 0x48) + 8);
    }
    _printk(&DAT_0010b133,lVar2,"sdhci_msm_init_sysfs_gating_qos",iVar1);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_cqe_add_host @ 001036f4 size=924
// signature: undefined sdhci_msm_cqe_add_host(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

ulong sdhci_msm_cqe_add_host(long param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long *plVar5;
  char *pcVar6;
  long lVar7;
  code *pcVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  
  if ((*(byte *)(param_1 + 0x493) >> 4 & 1) != 0) {
    *(undefined4 *)(param_1 + 0x3e4) = 0x10;
  }
  uVar4 = sdhci_setup_host(param_1);
  uVar10 = uVar4 & 0xffffffff;
  if ((int)uVar4 != 0) goto LAB_00103810;
  plVar5 = (long *)cqhci_pltfm_init(param_2);
  if (plVar5 < (long *)0xfffffffffffff001) {
    *(uint *)(*(long *)(param_1 + 0x618) + 1000) =
         *(uint *)(*(long *)(param_1 + 0x618) + 1000) | 0x1800000;
    *plVar5 = (long)&sdhci_msm_cqhci_ops;
    *(long **)(param_1 + 0x628) = plVar5;
    *(undefined1 *)((long)plVar5 + 0x3e) = *(undefined1 *)(param_1 + 0x794);
    puVar12 = *(undefined8 **)(param_1 + 0x618);
    uVar3 = *(uint *)(param_1 + 0x2f4);
    pcVar8 = *(code **)(*plVar5 + 0x10);
    uVar9 = *puVar12;
    if (pcVar8 == (code *)0x0) {
      uVar2 = readl_relaxed(plVar5[1] + 4);
    }
    else {
      if (*(int *)(pcVar8 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1038c0);
        (*pcVar8)();
      }
      uVar2 = (*pcVar8)(plVar5,4);
    }
    if ((uVar2 >> 0x1c & 1) != 0) {
      lVar7 = platform_get_resource_byname(*(undefined8 *)(param_1 + 0x580),0x200,"cqhci_ice");
      if (lVar7 == 0) {
        pcVar6 = "ICE registers not found\n";
LAB_0010395c:
        uVar11 = uVar9;
LAB_00103960:
        _dev_warn(uVar11,pcVar6);
      }
      else {
        uVar4 = qcom_scm_ice_available();
        if ((uVar4 & 1) == 0) {
          pcVar6 = "ICE SCM interface not found\n";
          goto LAB_0010395c;
        }
        uVar10 = devm_ioremap_resource(uVar9,lVar7);
        *(ulong *)(param_1 + 0x590) = uVar10;
        if (0xfffffffffffff000 < uVar10) {
          _dev_err(uVar9,"Failed to map ICE registers; err=%d\n",uVar10 & 0xffffffff);
LAB_001039a8:
          if ((int)uVar10 != 0) goto LAB_00103808;
          goto LAB_0010379c;
        }
        plVar5[0x1b] = uVar10;
        lVar7 = platform_get_resource_byname
                          (*(undefined8 *)(param_1 + 0x580),0x200,"cqhci_ice_hwkm");
        if (lVar7 == 0) {
          pcVar6 = "ICE HWKM registers not found\n";
          goto LAB_0010395c;
        }
        uVar10 = devm_ioremap_resource(uVar9,lVar7);
        *(ulong *)(param_1 + 0x598) = uVar10;
        if (0xfffffffffffff000 < uVar10) {
          _dev_err(uVar9,"Failed to map ICE HWKM registers; err=%d\n",uVar10 & 0xffffffff);
          goto LAB_001039a8;
        }
        plVar5[0x1d] = uVar10;
        uVar11 = **(undefined8 **)(param_1 + 0x618);
        uVar4 = readl(*(long *)(param_1 + 0x590) + 8);
        uVar10 = uVar4 >> 0x18 & 0xff;
        if ((int)uVar10 == 3) {
          _dev_info(uVar11,"Found QC Inline Crypto Engine (ICE) v%d.%d.%d\n");
          uVar4 = readl(*(long *)(param_1 + 0x590) + 0x10);
          if ((uVar4 & 7) == 0) {
            *(uint *)(puVar12 + 0x7d) = *(uint *)(puVar12 + 0x7d) | 0x8000000;
            goto LAB_0010379c;
          }
          pcVar6 = "Fuses are blown; ICE is unusable!\n";
          goto LAB_00103960;
        }
        _dev_warn(uVar11,"Unsupported ICE version: v%d.%d.%d\n",uVar10,(uint)uVar4 >> 0x10 & 0xff,
                  (uint)uVar4 & 0xffff);
      }
      _dev_warn(uVar9,"Disabling inline encryption support\n");
    }
LAB_0010379c:
    uVar3 = cqhci_init(plVar5,*(undefined8 *)(param_1 + 0x48),uVar3 >> 0xc & 1);
    if (uVar3 == 0) {
      pcVar8 = *(code **)(*plVar5 + 0x10);
      if (pcVar8 == (code *)0x0) {
        uVar3 = readl_relaxed(plVar5[1] + 0xa00);
      }
      else {
        if (*(int *)(pcVar8 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103a44);
          (*pcVar8)();
        }
        uVar3 = (*pcVar8)(plVar5,0xa00);
      }
      pcVar8 = *(code **)(*plVar5 + 8);
      if (pcVar8 == (code *)0x0) {
        writel_relaxed(uVar3 | 0x6000,plVar5[1] + 0xa00);
        bVar1 = *(byte *)(param_1 + 0x2f5);
      }
      else {
        if (*(int *)(pcVar8 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x103a70);
          (*pcVar8)();
        }
        (*pcVar8)(plVar5,uVar3 | 0x6000,0xa00);
        bVar1 = *(byte *)(param_1 + 0x2f5);
      }
      if ((bVar1 >> 4 & 1) != 0) {
        *(undefined4 *)(param_1 + 0x3e0) = 0xc;
      }
      uVar4 = __sdhci_add_host(param_1);
      uVar10 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        lVar7 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
        if (lVar7 == 0) {
          lVar7 = *(long *)(*(long *)(param_1 + 0x48) + 8);
        }
        _dev_info(param_2 + 0x10,"%s: CQE init: success\n",lVar7);
        uVar10 = 0;
        goto LAB_00103810;
      }
    }
    else {
      uVar10 = (ulong)uVar3;
      lVar7 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
      if (lVar7 == 0) {
        lVar7 = *(long *)(*(long *)(param_1 + 0x48) + 8);
      }
      _dev_err(param_2 + 0x10,"%s: CQE init: failed (%d)\n",lVar7,uVar10);
    }
  }
  else {
    _dev_err(param_2 + 0x10,"cqhci-pltfm init: failed: %d\n",(ulong)plVar5 & 0xffffffff);
    uVar10 = (ulong)plVar5 & 0xffffffff;
  }
LAB_00103808:
  sdhci_cleanup_host(param_1);
LAB_00103810:
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// sdhci_msm_mmc_suspend @ 00103a94 size=216
// signature: undefined sdhci_msm_mmc_suspend(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_mmc_suspend(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (*(char *)(param_2 + 0xfb8) == '\0') {
    local_30 = 0;
    *(undefined4 *)(param_2 + 0xfb4) = *(undefined4 *)(param_2 + 0x420);
    *(undefined8 *)(param_2 + 0xfa4) = *(undefined8 *)(param_2 + 0x410);
    *(undefined8 *)(param_2 + 0xfac) = *(undefined8 *)(param_2 + 0x418);
    iVar1 = mmc_get_ext_csd(*(undefined8 *)(param_2 + 0x480),&local_30);
    if ((iVar1 == 0) && (local_30 != 0)) {
      *(undefined1 *)(param_2 + 4000) = *(undefined1 *)(local_30 + 0xf);
      *(undefined1 *)(param_2 + 0xfa1) = *(undefined1 *)(local_30 + 0x21);
      *(undefined1 *)(param_2 + 0xfa2) = *(undefined1 *)(local_30 + 0xb7);
      *(undefined1 *)(param_2 + 0xfa3) = *(undefined1 *)(local_30 + 0xb9);
      kfree();
    }
    else {
      lVar2 = *(long *)(param_2 + 0x78);
      if (lVar2 == 0) {
        lVar2 = *(long *)(param_2 + 8);
      }
      _printk(&DAT_0010ad23,lVar2,"mmc_cache_card_ext_csd",iVar1);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_mmc_resume @ 00103b70 size=800
// signature: undefined sdhci_msm_mmc_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdhci_msm_mmc_resume(undefined8 param_1,long param_2,undefined1 *param_3)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined1 uVar6;
  code *pcVar7;
  ulong uVar8;
  long *plVar9;
  long lVar10;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  if (_pm_suspend_target_state == 3) {
    pcVar7 = *(code **)(*(long *)(param_2 + 0x780) + 0xb0);
    if (*(int *)(pcVar7 + -4) != -0x1d377ef) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103bd4);
      (*pcVar7)();
    }
    (*pcVar7)(param_2 + 0x740);
  }
  else if (*(char *)(param_2 + 0xfb8) == '\0') {
    lVar10 = *(long *)(param_2 + 0x480);
    if (*(byte *)(lVar10 + 0x480) < 3) {
LAB_00103c2c:
      uVar6 = 1;
      goto LAB_00103be8;
    }
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    uVar1 = *(int *)(lVar10 + 0x490) + 9999;
    local_78 = 0;
    uStack_70 = 0;
    uVar8 = (ulong)uVar1 / 10000;
    mmc_retune_hold(param_2);
    local_80 = CONCAT44(*(int *)(lVar10 + 0x39c) << 0x10,5);
    uVar4 = mmc_prepare_busy_cmd(param_2,&local_80,uVar8);
    iVar5 = mmc_wait_for_cmd(param_2,&local_80,0);
    if (iVar5 != 0) {
      mmc_retune_release(param_2);
      goto LAB_00103be4;
    }
    if ((uVar4 & (*(byte *)(param_2 + 0x3e5) & 2) >> 1) == 1) {
      iVar5 = mmc_select_card(lVar10);
LAB_00103cf0:
      mmc_retune_release(param_2);
      if (iVar5 != 0) goto LAB_00103be4;
    }
    else {
      if (*(long *)(*(long *)(param_2 + 0x3a0) + 0x58) != 0) {
        iVar5 = __mmc_poll_for_busy(param_2,0,uVar8,mmc_sleep_busy_cb,param_2);
        goto LAB_00103cf0;
      }
      if (uVar1 < 210000) {
        usleep_range_state((int)uVar8 * 1000,(int)uVar8 * 0x4e2,2);
      }
      else {
        msleep(uVar8);
      }
      mmc_retune_release(param_2);
    }
    plVar9 = *(long **)(param_2 + 0x480);
    mmc_set_bus_width(param_2,*(undefined1 *)(param_2 + 0xfb3));
    mmc_set_timing(param_2,*(undefined1 *)(param_2 + 0xfb4));
    if (*(char *)(param_2 + 0xfb7) != '\0') {
      *(undefined1 *)(param_2 + 0x423) = 1;
      pcVar7 = *(code **)(*(long *)(param_2 + 0x3a0) + 0x90);
      if (pcVar7 != (code *)0x0) {
        if (*(int *)(pcVar7 + -4) != 0x5a31c00f) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103d98);
          (*pcVar7)();
        }
        (*pcVar7)(param_2,param_2 + 0x410);
      }
    }
    mmc_set_clock(param_2,*(undefined4 *)(param_2 + 0xfa4));
    mmc_set_bus_mode(param_2,*(undefined1 *)(param_2 + 0xfb0));
    lVar10 = *plVar9;
    if (((*(char *)(lVar10 + 0x423) == '\0') && (*(byte *)(lVar10 + 0x420) - 9 < 2)) &&
       (iVar5 = mmc_execute_tuning(plVar9), iVar5 != 0)) {
      lVar10 = *(long *)(param_2 + 0x78);
      if (lVar10 == 0) {
        lVar10 = *(long *)(param_2 + 8);
      }
      _printk(&DAT_0010bc70,lVar10,iVar5);
    }
    else {
      local_80 = 0;
      iVar5 = mmc_get_ext_csd(*(undefined8 *)(param_2 + 0x480),&local_80);
      if (iVar5 == 0) {
        if (((*(char *)(param_2 + 4000) == *(char *)(local_80 + 0xf)) &&
            (*(char *)(param_2 + 0xfa1) == *(char *)(local_80 + 0x21))) &&
           (*(char *)(param_2 + 0xfa2) == *(char *)(local_80 + 0xb7))) {
          cVar2 = *(char *)(param_2 + 0xfa3);
          cVar3 = *(char *)(local_80 + 0xb9);
          kfree();
          if (cVar2 == cVar3) goto LAB_00103c2c;
        }
        else {
          kfree();
        }
      }
      else {
        lVar10 = *(long *)(param_2 + 0x78);
        if (lVar10 == 0) {
          lVar10 = *(long *)(param_2 + 8);
        }
        _printk(&DAT_0010ad23,lVar10,"mmc_test_awake_ext_csd",iVar5);
      }
    }
  }
LAB_00103be4:
  uVar6 = 0;
LAB_00103be8:
  *param_3 = uVar6;
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_hibernation_notifier @ 00103e94 size=424
// signature: undefined sdhci_msm_hibernation_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 sdhci_msm_hibernation_notifier(long param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  
  if (param_1 == 0) {
    uVar5 = 0xffffffea;
  }
  else {
    if (param_2 == 2) {
      plVar7 = *(long **)(param_1 + -0x268);
      if (plVar7[0x90] == 0) {
        return 0;
      }
      lVar8 = plVar7[0xaa];
      mmc_get_card(plVar7[0x90],0);
      piVar1 = (int *)(plVar7[0x90] + 0x200);
      iVar6 = *(int *)(plVar7[0x90] + 0x200);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar6) goto LAB_00103f6c;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00103f6c:
        bVar4 = iVar6 != iVar2;
        iVar6 = iVar2;
      } while (bVar4);
      piVar1 = (int *)(*plVar7 + 0x1f8);
      iVar6 = *(int *)(*plVar7 + 0x1f8);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar6) goto LAB_00103fcc;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00103fcc:
        bVar4 = iVar6 != iVar2;
        iVar6 = iVar2;
      } while (bVar4);
      mmc_put_card(plVar7[0x90],0);
      if (-1 < (int)plVar7[0xa9]) {
        devm_request_threaded_irq
                  (*plVar7,(int)plVar7[0xa9],0,*(undefined8 *)(lVar8 + 0x10),0x2003,
                   *(undefined8 *)(lVar8 + 0x20),plVar7);
      }
    }
    else if (param_2 == 1) {
      plVar7 = *(long **)(param_1 + -0x268);
      if (plVar7[0x90] == 0) {
        return 0;
      }
      mmc_get_card(plVar7[0x90],0);
      piVar1 = (int *)(*plVar7 + 0x1f8);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = *piVar1 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      piVar1 = (int *)(plVar7[0x90] + 0x200);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = *piVar1 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      mmc_put_card(plVar7[0x90],0);
      if (-1 < (int)plVar7[0xa9]) {
        devm_free_irq(*plVar7,(int)plVar7[0xa9],plVar7);
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// pm_runtime_put_noidle @ 0010407c size=76
// signature: undefined pm_runtime_put_noidle(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void pm_runtime_put_noidle(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + 0x1f8);
  iVar5 = *(int *)(param_1 + 0x1f8);
  do {
    if (iVar5 == 0) {
      return;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar5) goto LAB_001040a4;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_001040a4:
    bVar4 = iVar5 == iVar2;
    iVar5 = iVar2;
    if (bVar4) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// sdhci_msm_bus_get_and_set_vote @ 001040dc size=280
// signature: undefined sdhci_msm_bus_get_and_set_vote(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_bus_voting, sdhci_msm_probe, sdhci_msm_set_clock, sdhci_msm_remove]
//------------------------------------------------------------

void sdhci_msm_bus_get_and_set_vote(long param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int iVar6;
  long lVar7;
  undefined4 *puVar8;
  
  lVar5 = *(long *)(param_1 + 0x688);
  if (lVar5 == 0) {
    return;
  }
  lVar4 = *(long *)(lVar5 + 0x28);
  if ((lVar4 == 0) && (*(long *)(lVar5 + 0x30) == 0)) {
    return;
  }
  iVar2 = *(int *)(lVar5 + 0x20);
  if (iVar2 == 0) {
    iVar6 = -1;
  }
  else {
    iVar6 = 0;
    do {
      if (param_2 <= *(uint *)(*(long *)(lVar5 + 0x18) + (long)iVar6 * 4)) goto LAB_00104148;
      iVar6 = iVar6 + 1;
    } while (iVar2 != iVar6);
    iVar6 = iVar2 + -1;
  }
LAB_00104148:
  if (*(int *)(lVar5 + 0x38) == iVar6) {
    return;
  }
  lVar7 = *(long *)(*(long *)(param_1 + 0x580) + 0xa8);
  puVar8 = *(undefined4 **)(*(long *)(lVar5 + 0x10) + (long)iVar6 * 0x10 + 8);
  if (lVar4 == 0) {
    iVar2 = 0;
    lVar4 = *(long *)(lVar5 + 0x30);
  }
  else {
    iVar2 = icc_set_bw(lVar4,*puVar8,puVar8[2]);
    lVar4 = *(long *)(lVar5 + 0x30);
  }
  if (lVar4 == 0) {
    bVar1 = false;
  }
  else {
    iVar3 = icc_set_bw(lVar4,puVar8[4],puVar8[6]);
    bVar1 = iVar3 != 0;
  }
  if ((iVar2 != 0) || (bVar1)) {
    lVar4 = *(long *)(lVar7 + 0x48);
    lVar5 = *(long *)(lVar4 + 0x78);
    if (lVar5 == 0) {
      lVar5 = *(long *)(lVar4 + 8);
    }
    _printk(&DAT_0010b063,lVar5);
  }
  else {
    *(int *)(lVar5 + 0x38) = iVar6;
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_writew @ 001041f8 size=92
// signature: undefined sdhci_msm_writew(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_writew(long param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = __sdhci_msm_check_write();
  writew_relaxed(param_2,*(long *)(param_1 + 0x18) + (long)param_3);
  if (iVar1 != 0) {
    sdhci_msm_check_power_status(param_1,iVar1);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_writeb @ 00104258 size=96
// signature: undefined sdhci_msm_writeb(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_writeb(long param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = __sdhci_msm_check_write(param_1,param_2 & 0xff);
  writeb_relaxed(param_2,*(long *)(param_1 + 0x18) + (long)param_3);
  if (iVar1 != 0) {
    sdhci_msm_check_power_status(param_1,iVar1);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_set_clock @ 001042bc size=288
// signature: undefined sdhci_msm_set_clock(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_set_clock(long param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  ulong uVar3;
  code *pcVar4;
  
  if (param_2 == 0) {
    *(undefined8 *)(param_1 + 0x608) = 0;
    *(undefined4 *)(*(long *)(param_1 + 0x48) + 0x5e0) = 0;
  }
  else {
    sdhci_msm_hc_select_mode(param_1);
    msm_set_clock_rate_for_bus_mode(param_1,param_2);
    if (*(char *)(param_1 + 0x681) == '\0') {
      uVar3 = *(ulong *)(param_1 + 0x608);
      cVar1 = *(char *)(*(long *)(param_1 + 0x48) + 0x41f);
      if (cVar1 == '\0') {
        uVar3 = uVar3 >> 3;
      }
      else if (cVar1 == '\x02') {
        uVar3 = uVar3 >> 1;
      }
      sdhci_msm_bus_get_and_set_vote(param_1,uVar3);
    }
  }
  pcVar4 = *(code **)(*(long *)(param_1 + 0x40) + 0x20);
  if (pcVar4 == (code *)0x0) {
    writew(0,*(long *)(param_1 + 0x18) + 0x2c);
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x491fd948) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1043a8);
      (*pcVar4)();
    }
    (*pcVar4)(param_1,0,0x2c);
  }
  if (param_2 != 0) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x40) + 8);
    if (pcVar4 == (code *)0x0) {
      uVar2 = readw(*(long *)(param_1 + 0x18) + 0x2c);
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x3310e391) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1043d4);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(param_1,0x2c);
    }
    sdhci_enable_clk(param_1,uVar2);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_cqe_irq @ 001043e0 size=176
// signature: undefined sdhci_msm_cqe_irq(void)
// callers: []
//------------------------------------------------------------

undefined4 sdhci_msm_cqe_irq(long param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(param_1 + 0x828),"%s: intmask: 0x%x\n","sdhci_msm_log_irq",param_2);
  }
  uVar2 = sdhci_cqe_irq(param_1,param_2,(long)&local_30 + 4,&local_30);
  if ((uVar2 & 1) != 0) {
    cqhci_irq(*(undefined8 *)(param_1 + 0x48),param_2,local_30._4_4_,local_30 & 0xffffffff);
    param_2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// sdhci_msm_get_max_clock @ 00104494 size=36
// signature: undefined sdhci_msm_get_max_clock(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_get_max_clock(long param_1)

{
  clk_round_rate(*(undefined8 *)(param_1 + 0x5c0),0xffffffffffffffff);
  return;
}



//------------------------------------------------------------
// sdhci_msm_get_min_clock @ 001044bc size=12
// signature: undefined sdhci_msm_get_min_clock(void)
// callers: []
//------------------------------------------------------------

undefined8 sdhci_msm_get_min_clock(void)

{
  return 400000;
}



//------------------------------------------------------------
// sdhci_msm_get_max_timeout_count @ 001044cc size=8
// signature: undefined sdhci_msm_get_max_timeout_count(void)
// callers: []
//------------------------------------------------------------

undefined8 sdhci_msm_get_max_timeout_count(void)

{
  return 0;
}



//------------------------------------------------------------
// sdhci_msm_set_timeout @ 001044d8 size=236
// signature: undefined sdhci_msm_set_timeout(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_set_timeout(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x48) + 0x5e0);
  if (uVar1 == 0) {
    uVar1 = *(uint *)(param_1 + 0x30c);
  }
  *(uint *)(param_1 + 0x300) = uVar1 / 4000;
  __sdhci_set_timeout(param_1,param_2);
  pcVar2 = *(code **)(*(long *)(param_1 + 0x40) + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = readb(*(long *)(param_1 + 0x18) + 0x2e);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x7ce07dd) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1045b8);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,0x2e);
  }
  if ((((param_2 != 0) && (*(long *)(param_2 + 0x28) != 0)) &&
      (*(int *)(param_1 + 0x30c) - 0x61a81U < 49600000)) &&
     ((uint)(*(int *)(param_1 + 0x30c) * 10) < (uint)(0x8000 << (ulong)(uVar1 & 0x1f)))) {
    *(undefined8 *)(param_1 + 0x500) = 22000000000;
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_reset @ 001045c8 size=116
// signature: undefined sdhci_msm_reset(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_reset(long param_1,uint param_2)

{
  long lVar1;
  
  if ((param_2 & 1) != 0) {
    if ((*(uint *)(*(long *)(param_1 + 0x48) + 1000) >> 0x17 & 1) != 0) {
      cqhci_deactivate();
    }
  }
  if ((((*(char *)(param_1 + 0x879) != '\0') && (*(long *)(param_1 + 0x48) != 0)) &&
      (lVar1 = *(long *)(*(long *)(param_1 + 0x48) + 0x480), lVar1 != 0)) &&
     (*(char *)(lVar1 + 0x488) != '\x01')) {
    *(undefined1 *)(lVar1 + 0x488) = 1;
  }
  sdhci_reset(param_1,param_2);
  return;
}



//------------------------------------------------------------
// sdhci_msm_set_uhs_signaling @ 00104640 size=1656
// signature: undefined sdhci_msm_set_uhs_signaling(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_set_uhs_signaling(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined *puVar5;
  char *pcVar6;
  code *pcVar7;
  uint uVar8;
  long lVar9;
  long *plVar10;
  long lVar11;
  
  lVar9 = *(long *)(param_1 + 0x48);
  lVar11 = *(long *)(param_1 + 0x670);
  pcVar7 = *(code **)(*(long *)(param_1 + 0x40) + 8);
  if (pcVar7 == (code *)0x0) {
    uVar1 = readw(*(long *)(param_1 + 0x18) + 0x3e);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x3310e391) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104c84);
      (*pcVar7)();
    }
    uVar1 = (*pcVar7)(param_1,0x3e);
  }
  uVar1 = uVar1 & 0xfffffff8;
  uVar8 = uVar1;
  switch(param_2) {
  case 4:
    uVar8 = uVar1 | 1;
    break;
  case 5:
    uVar8 = uVar1 | 2;
    break;
  case 6:
  case 9:
  case 10:
    uVar8 = uVar1 | 3;
    break;
  case 7:
  case 8:
    uVar8 = uVar1 | 4;
  }
  if (*(uint *)(param_1 + 0x30c) < 0x5f5e101) {
    if ((param_2 < 0xb) && ((1 << (ulong)(param_2 & 0x1f) & 0x640U) != 0)) {
      uVar8 = uVar1;
    }
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar11 + 0x3c));
    writel_relaxed(uVar1 | 0x40000000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar11 + 0x3c));
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar11 + 0x3c));
    writel_relaxed(uVar1 | 0x20000000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar11 + 0x3c));
    *(undefined1 *)(param_1 + 0x632) = 0;
  }
  pcVar7 = *(code **)(*(long *)(param_1 + 0x40) + 0x20);
  if (pcVar7 == (code *)0x0) {
    writew(uVar8,*(long *)(param_1 + 0x18) + 0x3e);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x491fd948) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104cb0);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,uVar8,0x3e);
  }
  if (*(char *)(lVar9 + 0x420) != '\n') {
    return;
  }
  if (*(uint *)(param_1 + 0x30c) < 0x5f5e101) {
    return;
  }
  if ((*(char *)(param_1 + 0x631) == '\0') && (*(char *)(lVar9 + 0x423) == '\0')) {
    return;
  }
  if (*(char *)(param_1 + 0x632) != '\0') {
    return;
  }
  lVar11 = *(long *)(param_1 + 0x48);
  lVar9 = *(long *)(param_1 + 0x670);
  iVar2 = msm_init_cm_dll(param_1,0);
  if (iVar2 != 0) goto LAB_00104c30;
  if (*(char *)(lVar11 + 0x423) == '\0') {
    iVar2 = msm_config_cm_dll_phase(param_1,*(undefined1 *)(param_1 + 0x633));
    if (iVar2 != 0) goto LAB_00104c30;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    writel_relaxed(uVar1 | 1,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
  }
  if (*(char *)(param_1 + 0x634) == '\0') {
    lVar4 = *(long *)(param_1 + 0x670);
    lVar11 = *(long *)(param_1 + 0x48);
    lVar9 = 0x6c;
    if (*(char *)(param_1 + 0x680) != '\0') {
      lVar9 = 0x70;
    }
    if ((*(long *)(param_1 + 0x7a8) == 0) ||
       (iVar2 = *(int *)(*(long *)(param_1 + 0x7a8) + 0x10), iVar2 == 0)) {
      iVar2 = -0x7ffbf78d;
    }
    writel_relaxed(iVar2,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + lVar9));
    if (*(char *)(lVar11 + 0x423) != '\0') {
      uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x5c));
      writel_relaxed(uVar1 | 2,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x5c));
    }
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 100));
    writel_relaxed(uVar1 | 1,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 100));
    lVar9 = ktime_get();
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x40));
    if ((uVar1 >> 0xb & 1) == 0) {
      do {
        lVar11 = ktime_get();
        if (lVar9 + 1000000 < lVar11) {
          uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x40));
          break;
        }
        usleep_range_state(3,10,2);
        Yield();
        uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x40));
      } while ((uVar1 >> 0xb & 1) == 0);
    }
    if ((uVar1 >> 0xb & 1) != 0) {
      if (*(char *)(param_1 + 0x630) == '\0') {
        uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x60));
        writel_relaxed(uVar1 | 8,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x60));
      }
      DataSynchronizationBarrier(3,2,0);
LAB_00104bac:
      *(undefined1 *)(param_1 + 0x632) = 1;
      return;
    }
    lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
    if (lVar9 == 0) {
      lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 8);
    }
    puVar5 = &DAT_0010bb77;
    pcVar6 = "sdhci_msm_cm_dll_sdc4_calibration";
  }
  else {
    lVar9 = *(long *)(param_1 + 0x670);
    iVar2 = msm_init_cm_dll(param_1,0);
    if ((iVar2 != 0) ||
       (iVar2 = msm_config_cm_dll_phase(param_1,*(undefined1 *)(param_1 + 0x633)), iVar2 != 0))
    goto LAB_00104c30;
    plVar10 = (long *)(param_1 + 0x18);
    uVar1 = readl_relaxed(*plVar10 + (ulong)*(uint *)(lVar9 + 0x3c));
    writel_relaxed(uVar1 | 1,*plVar10 + (ulong)*(uint *)(lVar9 + 0x3c));
    uVar1 = readl_relaxed(*plVar10 + (ulong)*(uint *)(lVar9 + 0x5c));
    writel_relaxed(uVar1 & 0xfffffffe,*plVar10 + (ulong)*(uint *)(lVar9 + 0x5c));
    uVar1 = readl_relaxed(*plVar10 + 0x178);
    writel_relaxed(uVar1 & 0xfffffffe,*plVar10 + 0x178);
    uVar1 = readl_relaxed(*plVar10 + 0x178);
    writel_relaxed(uVar1 | 2,*plVar10 + 0x178);
    uVar1 = readl_relaxed(*plVar10 + (ulong)*(uint *)(lVar9 + 0x5c));
    writel_relaxed(uVar1 & 0xffffffbf,*plVar10 + (ulong)*(uint *)(lVar9 + 0x5c));
    writel_relaxed(0x11800ec,*plVar10 + 0x130);
    writel_relaxed(0x3011111,*plVar10 + 0x134);
    writel_relaxed(0x1201000,*plVar10 + 0x138);
    writel_relaxed(4,*plVar10 + 0x13c);
    writel_relaxed(0xcb732020,*plVar10 + 0x140);
    writel_relaxed(0xb19,*plVar10 + 0x144);
    writel_relaxed(0x4e2,*plVar10 + 0x150);
    writel_relaxed(0,*plVar10 + 0x14c);
    writel_relaxed(0x16334,*plVar10 + 0x160);
    uVar1 = readl_relaxed(*plVar10 + 0x130);
    writel_relaxed(uVar1 | 0x10000,*plVar10 + 0x130);
    uVar1 = readl_relaxed(*plVar10 + 0x130);
    writel_relaxed(uVar1 & 0xfffeffff,*plVar10 + 0x130);
    uVar1 = readl_relaxed(*plVar10 + 0x130);
    writel_relaxed(uVar1 | 0x20000,*plVar10 + 0x130);
    uVar1 = readl_relaxed(*plVar10 + 0x138);
    writel_relaxed(uVar1 | 0x10000,*plVar10 + 0x138);
    lVar11 = ktime_get();
    uVar3 = readl_relaxed(*plVar10 + 0x164);
    if ((uVar3 & 1) == 0) {
      do {
        lVar4 = ktime_get();
        if (lVar11 + 50000 < lVar4) {
          uVar3 = readl_relaxed(*plVar10 + 0x164);
          break;
        }
        usleep_range_state(1,1,2);
        Yield();
        uVar3 = readl_relaxed(*plVar10 + 0x164);
      } while ((uVar3 & 1) == 0);
    }
    if ((uVar3 & 1) != 0) {
      uVar1 = readl_relaxed(*plVar10 + 0x164);
      if ((uVar1 & 0x7000000) == 0) {
        uVar1 = readl_relaxed(*plVar10 + (ulong)*(uint *)(lVar9 + 0x5c));
        writel_relaxed(uVar1 | 0x40,*plVar10 + (ulong)*(uint *)(lVar9 + 0x5c));
        goto LAB_00104bac;
      }
      lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
      if (lVar9 == 0) {
        lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 8);
      }
      _printk(&DAT_0010b63f,lVar9,"sdhci_msm_cdclp533_calibration",uVar1 & 0x7000000);
      iVar2 = -0x16;
      goto LAB_00104c30;
    }
    lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
    if (lVar9 == 0) {
      lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 8);
    }
    puVar5 = &DAT_0010b7dd;
    pcVar6 = "sdhci_msm_cdclp533_calibration";
  }
  _printk(puVar5,lVar9,pcVar6);
  iVar2 = -0x6e;
LAB_00104c30:
  lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar9 == 0) {
    lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  _printk(&DAT_0010ad67,lVar9,iVar2);
  return;
}



//------------------------------------------------------------
// sdhci_msm_hw_reset @ 00104cbc size=232
// signature: undefined sdhci_msm_hw_reset(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdhci_msm_hw_reset(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  iVar1 = _pm_suspend_target_state;
  lVar3 = *(long *)(param_1 + 0x580);
  if (*(long *)(param_1 + 0x798) == 0) {
    _dev_err(lVar3 + 0x10,"%s: failed, err = %d\n","sdhci_msm_hw_reset",0xffffffa1);
  }
  else {
    *(undefined1 *)(param_1 + 0x795) = 1;
    sdhci_msm_registers_save();
    if ((*(char *)(*(long *)(param_1 + 0x48) + 0x3ea) < '\0') && (iVar1 != 3)) {
      pcVar2 = *(code **)(*(long *)(*(long *)(param_1 + 0x48) + 0x5f0) + 8);
      if (*(int *)(pcVar2 + -4) != 0x3af16e59) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104d28);
        (*pcVar2)();
      }
      (*pcVar2)();
      *(undefined1 *)(*(long *)(param_1 + 0x48) + 0x604) = 0;
    }
    sdhci_msm_gcc_reset(lVar3 + 0x10,param_1);
    sdhci_msm_registers_restore(param_1);
    *(undefined1 *)(param_1 + 0x795) = 0;
    if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
      ipc_log_string(*(long *)(param_1 + 0x828),"%s: HW reset done\n","sdhci_msm_hw_reset");
    }
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_dump_vendor_regs @ 00104da8 size=1536
// signature: undefined sdhci_msm_dump_vendor_regs(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_dump_vendor_regs(long param_1)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  long lVar8;
  uint uVar9;
  int iVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  long lVar15;
  long lVar16;
  uint uVar17;
  uint uVar18;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
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
  undefined8 local_c0;
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
  
  lVar8 = sp_el0;
  local_70 = *(long *)(lVar8 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  lVar16 = *(long *)(param_1 + 0x670);
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
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
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_160 = 0;
  uStack_158 = 0;
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  _printk(&DAT_0010b255,lVar8);
  plVar11 = *(long **)(param_1 + 0x628);
  if (plVar11 != (long *)0x0) {
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104e6c);
      (*pcVar2)();
    }
    bVar4 = (*(code *)**(undefined8 **)(param_1 + 0x668))
                      (param_1,*(undefined4 *)(*(long *)(param_1 + 0x670) + 0x10));
    uVar9 = 0;
    if (bVar4 < 0x49) {
      uVar9 = 0x48;
    }
    if (*(char *)((long)plVar11 + 0x3e) != '\0') {
      uVar9 = uVar9 | 0x900;
    }
    _printk(&DAT_0010baca);
    pcVar2 = *(code **)(*plVar11 + 0x10);
    if (pcVar2 == (code *)0x0) {
      uVar5 = readl_relaxed(plVar11[1] + (ulong)(uVar9 + 0x150));
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105378);
        (*pcVar2)();
      }
      uVar5 = (*pcVar2)(plVar11);
    }
    pcVar2 = *(code **)(*plVar11 + 0x10);
    if (pcVar2 == (code *)0x0) {
      uVar6 = readl_relaxed(plVar11[1] + (ulong)(uVar9 + 0x154));
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10539c);
        (*pcVar2)();
      }
      uVar6 = (*pcVar2)(plVar11);
    }
    _printk(&DAT_0010ac0d,uVar5,uVar6);
    uVar12 = 0;
    uVar13 = (ulong)(uVar9 + 0x110);
    do {
      pcVar2 = *(code **)(*plVar11 + 0x10);
      if (pcVar2 == (code *)0x0) {
        uVar5 = readl_relaxed(plVar11[1] + uVar13);
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104f5c);
          (*pcVar2)();
        }
        uVar5 = (*pcVar2)(plVar11,uVar13 & 0xffffffff);
      }
      _printk(&DAT_0010b554,uVar12 & 0xffffffff,uVar5);
      uVar12 = uVar12 + 1;
      uVar13 = uVar13 + 4;
    } while (uVar12 != 0x10);
    _printk(&DAT_0010a7a9);
  }
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 4));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0xc));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 8));
  _printk(&DAT_0010bbac,lVar8,uVar5,uVar6,uVar7);
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x40));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x3c));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 100));
  _printk(&DAT_0010aef7,lVar8,uVar5,uVar6,uVar7);
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x68));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x74));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x70));
  _printk(&DAT_0010ad9a,lVar8,uVar5,uVar6,uVar7);
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x10));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x48));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x4c));
  _printk(&DAT_0010ade6,lVar8,uVar5,uVar6,uVar7);
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x44));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x50));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x60));
  _printk(&DAT_0010abc0,lVar8,uVar5,uVar6,uVar7);
  lVar15 = *(long *)(param_1 + 0x670);
  lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar8 == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1051a0);
    (*pcVar2)();
  }
  uVar5 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar15 + 0x28));
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1051d0);
    (*pcVar2)();
  }
  uVar6 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar15 + 0x2c));
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105200);
    (*pcVar2)();
  }
  uVar7 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar15 + 0x34));
  _printk(&DAT_0010bd0a,lVar8,uVar5,uVar6,uVar7);
  iVar10 = 0;
  uVar12 = 0;
  do {
    uVar9 = (uint)uVar12;
    if ((int)uVar9 < 0x3c) {
      uVar17 = 0x3b - uVar9;
      uVar1 = 0;
      if (uVar9 < 0x3d) {
        uVar1 = 0x3c - uVar9;
      }
      if (6 < uVar17) {
        uVar17 = 7;
      }
      uVar18 = 0;
      uVar12 = uVar12 << 2;
      do {
        writel_relaxed(*(uint *)(lVar16 + 0x20) | uVar18 |
                       iVar10 << (ulong)(*(uint *)(lVar16 + 0x1c) & 0x1f),
                       *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x18));
        uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar16 + 0x38));
        if (uVar1 == uVar18) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105358);
          (*pcVar2)();
        }
        if (0xef < uVar12) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x10535c);
          (*pcVar2)();
        }
        *(undefined4 *)((long)&local_160 + uVar12) = uVar5;
        uVar18 = uVar18 + 1;
        uVar12 = uVar12 + 4;
      } while (uVar17 + 1 != uVar18);
      uVar12 = (ulong)(uVar9 + uVar18);
    }
    iVar10 = iVar10 + 1;
    if (iVar10 == 7) {
      uVar12 = 0;
      puVar14 = &uStack_158;
      do {
        lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
        if (lVar8 == 0) {
          lVar8 = *(long *)(*(long *)(param_1 + 0x48) + 8);
        }
        _printk(&DAT_0010ba87,lVar8,uVar12 & 0xffffffff,(int)uVar12 + 3,
                *(undefined4 *)(puVar14 + -1),*(undefined4 *)((long)puVar14 + -4),
                *(undefined4 *)puVar14,*(undefined4 *)((long)puVar14 + 4));
        bVar3 = uVar12 < 0x38;
        uVar12 = uVar12 + 4;
        puVar14 = puVar14 + 2;
      } while (bVar3);
      *(undefined1 *)(param_1 + 0x830) = 0;
      lVar8 = sp_el0;
      if (*(long *)(lVar8 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// __sdhci_msm_check_write @ 001053a8 size=364
// signature: undefined __sdhci_msm_check_write(void)
// callers: [sdhci_msm_writew, sdhci_msm_writeb]
//------------------------------------------------------------

undefined4 __sdhci_msm_check_write(long param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  
  uVar3 = 0;
  switch(param_3) {
  case 0xc:
    *(uint *)(param_1 + 0x67c) = param_2 & 0xffff;
    return 0;
  case 0xd:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
    goto switchD_001053ec_caseD_d;
  case 0xe:
    if ((((param_2 >> 3 & 1) != 0) && ((*(ushort *)(param_1 + 0x824) & 0xff) != 0)) &&
       ((*(ushort *)(param_1 + 0x824) >> 3 & 1) == 0)) {
      __const_udelay(0x8638);
    }
    *(short *)(param_1 + 0x824) = (short)param_2;
    if (*(char *)(param_1 + 0x678) != '\0') {
      if ((((*(byte *)(param_1 + 0x67c) >> 4 & 1) == 0) ||
          (uVar1 = (param_2 & 0xffff) >> 8 & 0x3f, uVar1 == 0x13)) || (uVar1 == 0x15)) {
        lVar4 = *(long *)(param_1 + 0x670);
        uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x3c));
        uVar1 = uVar2 & 0xfffdffff | 0x80000;
        if (uVar1 != uVar2) goto LAB_001054fc;
      }
      else {
        lVar4 = *(long *)(param_1 + 0x670);
        uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x3c));
        uVar1 = uVar2 & 0xfff7ffff | 0x20000;
        if (uVar1 != uVar2) {
LAB_001054fc:
          writel_relaxed(uVar1,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x3c));
          return 0;
        }
      }
    }
    return 0;
  case 0x29:
    uVar3 = 1;
    if ((param_2 & 0xffff) != 0) {
      uVar3 = 2;
    }
    break;
  case 0x2f:
    if ((param_2 & 1) == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x310) == '\0') {
      return 0;
    }
    uVar3 = 1;
    break;
  default:
    if (param_3 != 0x3e) {
      return 0;
    }
    uVar3 = 8;
    if ((param_2 & 8) != 0) {
      uVar3 = 4;
    }
  }
  *(undefined1 *)(param_1 + 0x658) = 0;
  DataSynchronizationBarrier(3,3,0);
switchD_001053ec_caseD_d:
  return uVar3;
}



//------------------------------------------------------------
// writew_relaxed @ 00105514 size=132
// signature: undefined writew_relaxed(void)
// callers: [sdhci_msm_writew]
//------------------------------------------------------------

void writew_relaxed(undefined2 param_1,undefined2 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x10,param_2,0x105530,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x10,param_2,0x105568,uVar1);
  return;
}



//------------------------------------------------------------
// sdhci_msm_check_power_status @ 00105598 size=656
// signature: undefined sdhci_msm_check_power_status(void)
// callers: [sdhci_msm_writew, sdhci_msm_writeb]
//------------------------------------------------------------

void sdhci_msm_check_power_status(long param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x48);
  lVar5 = *(long *)(param_1 + 0x670);
  if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(param_1 + 0x828),"%s: request %d curr_pwr_state %x curr_io_level %x\n",
                   "sdhci_msm_check_power_status",param_2,*(undefined4 *)(param_1 + 0x638),
                   *(undefined4 *)(param_1 + 0x63c));
  }
  if (*(char *)(param_1 + 0x660) == '\0') {
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1056ac);
      (*pcVar3)();
    }
    uVar1 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar5 + 0x14));
    if (((param_2 & 0xc) != 0) && ((uVar1 >> 0x1d & 1) == 0)) goto LAB_0010578c;
  }
  if (((param_2 >> 3 & 1) != 0) && (*(char *)(param_1 + 0x310) == '\0')) goto LAB_0010578c;
  if ((((*(uint *)(param_1 + 0x638) & param_2) == 0) &&
      ((*(uint *)(param_1 + 0x63c) & param_2) == 0)) && (*(char *)(param_1 + 0x658) == '\0')) {
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_70 = 0;
    init_wait_entry(&local_70,0);
    lVar5 = param_1 + 0x640;
    prepare_to_wait_event(lVar5,&local_70,2);
    if (*(char *)(param_1 + 0x658) == '\0') {
      lVar6 = 0x4e2;
      do {
        lVar6 = schedule_timeout(lVar6);
        prepare_to_wait_event(lVar5,&local_70,2);
        if (lVar6 == 0 && *(char *)(param_1 + 0x658) != '\0') {
          lVar6 = 1;
        }
      } while ((*(char *)(param_1 + 0x658) == '\0') && (lVar6 != 0));
      finish_wait(lVar5,&local_70);
      if (lVar6 != 0) goto LAB_0010570c;
      lVar5 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
      if (lVar5 == 0) {
        lVar5 = *(long *)(*(long *)(param_1 + 0x48) + 8);
      }
      _dev_warn(*(long *)(param_1 + 0x580) + 0x10,"%s: pwr_irq for req: (%d) timed out\n",lVar5,
                param_2);
      sdhci_msm_dump_pwr_ctrl_regs(param_1);
      lVar5 = *(long *)(lVar4 + 0x480);
    }
    else {
      finish_wait(lVar5,&local_70);
      lVar5 = *(long *)(lVar4 + 0x480);
    }
  }
  else {
LAB_0010570c:
    lVar5 = *(long *)(lVar4 + 0x480);
  }
  if ((lVar5 != 0) && (pcVar3 = *(code **)(*(long *)(lVar4 + 0x3a0) + 0x30), pcVar3 != (code *)0x0))
  {
    if (*(int *)(pcVar3 + -4) != 0x138bf33d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10573c);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(lVar4);
    if (((param_2 >> 1 & 1) != 0) && ((int)uVar2 == 0)) {
      *(undefined1 *)(param_1 + 0x310) = 0;
      pcVar3 = *(code **)(*(long *)(param_1 + 0x40) + 0x28);
      if (pcVar3 == (code *)0x0) {
        writeb(uVar2,*(long *)(param_1 + 0x18) + 0x29);
      }
      else {
        if (*(int *)(pcVar3 + -4) != 0x74405bc6) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10581c);
          (*pcVar3)();
        }
        (*pcVar3)(param_1,0,0x29);
      }
    }
  }
  if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(param_1 + 0x828),"%s: request %d done\n","sdhci_msm_check_power_status"
                   ,param_2);
  }
LAB_0010578c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_dump_pwr_ctrl_regs @ 00105828 size=240
// signature: undefined sdhci_msm_dump_pwr_ctrl_regs(void)
// callers: [sdhci_msm_check_power_status]
//------------------------------------------------------------

void sdhci_msm_dump_pwr_ctrl_regs(long param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x670);
  lVar5 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
  if (lVar5 == 0) {
    lVar5 = *(long *)(*(long *)(param_1 + 0x48) + 8);
  }
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105880);
    (*pcVar1)();
  }
  uVar2 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar6 + 0x28));
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1058b0);
    (*pcVar1)();
  }
  uVar3 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar6 + 0x2c));
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1058e0);
    (*pcVar1)();
  }
  uVar4 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar6 + 0x34));
  _printk(&DAT_0010bd0a,lVar5,uVar2,uVar3,uVar4);
  return;
}



//------------------------------------------------------------
// writeb @ 00105918 size=124
// signature: undefined writeb(void)
// callers: [sdhci_msm_check_power_status]
//------------------------------------------------------------

void writeb(undefined8 param_1,undefined1 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(0,8,param_2,writeb,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = 0;
  log_post_write_mmio(0,8,param_2,0x105968,uVar1);
  return;
}



//------------------------------------------------------------
// writeb_relaxed @ 00105994 size=132
// signature: undefined writeb_relaxed(void)
// callers: [sdhci_msm_writeb]
//------------------------------------------------------------

void writeb_relaxed(undefined1 param_1,undefined1 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,8,param_2,0x1059b0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,8,param_2,0x1059e8,uVar1);
  return;
}



//------------------------------------------------------------
// sdhci_msm_hc_select_mode @ 00105a18 size=516
// signature: undefined sdhci_msm_hc_select_mode(void)
// callers: [sdhci_msm_execute_tuning, sdhci_msm_set_clock]
//------------------------------------------------------------

void sdhci_msm_hc_select_mode(long param_1)

{
  byte bVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  if ((*(char *)(*(long *)(param_1 + 0x48) + 0x420) == '\n') ||
     ((*(byte *)(param_1 + 0x2f5) >> 5 & 1) != 0)) {
    lVar6 = *(long *)(param_1 + 0x670);
    bVar1 = *(byte *)(*(long *)(param_1 + 0x48) + 0x423);
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
    writel_relaxed(uVar2 | 0x300,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
    if (((*(char *)(param_1 + 0x631) == '\0') && ((bVar1 & 1) == 0)) ||
       (*(char *)(param_1 + 0x632) != '\0')) {
      lVar5 = *(long *)(param_1 + 0x608);
    }
    else {
      uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
      writel_relaxed(uVar2 | 0x340000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
      lVar5 = *(long *)(param_1 + 0x608);
    }
    if ((lVar5 == 0) && (*(char *)(param_1 + 0x634) == '\0')) {
      lVar5 = ktime_get();
      uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x40));
      if ((uVar3 & 0x880) == 0) {
        do {
          lVar4 = ktime_get();
          if (lVar5 + 1000000 < lVar4) {
            uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x40));
            break;
          }
          usleep_range_state(3,10,2);
          Yield();
          uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x40));
        } while ((uVar3 & 0x880) == 0);
      }
      if ((uVar3 & 0x880) == 0) {
        lVar6 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
        if (lVar6 == 0) {
          lVar6 = *(long *)(*(long *)(param_1 + 0x48) + 8);
        }
        _printk(&DAT_0010b515,lVar6);
      }
    }
    DataSynchronizationBarrier(3,2,0);
  }
  else {
    lVar6 = *(long *)(param_1 + 0x670);
    if (*(char *)(param_1 + 0x634) == '\0') {
      uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x60));
      writel_relaxed(uVar2 & 0xfffffff7,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x60));
    }
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
    writel_relaxed(uVar2 & 0xfffffcff | 0x200,
                   *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
    writel_relaxed(uVar2 & 0xffc3ffff,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar6 + 0x44));
    DataSynchronizationBarrier(3,2,0);
  }
  return;
}



//------------------------------------------------------------
// msm_set_clock_rate_for_bus_mode @ 00105c1c size=300
// signature: undefined msm_set_clock_rate_for_bus_mode(void)
// callers: [sdhci_msm_execute_tuning, sdhci_msm_set_clock]
//------------------------------------------------------------

void msm_set_clock_rate_for_bus_mode(long param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  
  bVar1 = *(byte *)(*(undefined8 **)(param_1 + 0x48) + 0x84);
  if (bVar1 < 0xb && (1 << (ulong)(bVar1 & 0x1f) & 0x580U) != 0) {
    uVar9 = 2;
    uVar5 = param_2 << 1;
  }
  else {
    uVar6 = 1;
    if ((*(byte *)(param_1 + 0x2f5) & 0x20) != 0) {
      uVar6 = 2;
    }
    uVar9 = (ulong)uVar6;
    uVar6 = uVar6 * param_2;
    uVar5 = uVar6;
    if (((bVar1 == 2) && (*(char *)(param_1 + 0x819) != '\0')) &&
       (uVar5 = 37500000, *(char *)(param_1 + 0x831) != '\0')) {
      uVar5 = uVar6;
    }
  }
  uVar7 = (ulong)uVar5;
  uVar8 = *(undefined8 *)(param_1 + 0x5c0);
  iVar3 = dev_pm_opp_set_rate(**(undefined8 **)(param_1 + 0x48),uVar7);
  if (iVar3 == 0) {
    uVar4 = clk_get_rate(uVar8);
    uVar2 = 0;
    if (uVar9 != 0) {
      uVar2 = (undefined4)(uVar4 / uVar9);
    }
    *(undefined4 *)(*(long *)(param_1 + 0x48) + 0x5e0) = uVar2;
    lVar10 = *(long *)(param_1 + 0x828);
    *(ulong *)(param_1 + 0x608) = uVar7;
    if ((lVar10 != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
      uVar8 = clk_get_rate(uVar8);
      ipc_log_string(lVar10,"%s: Setting clock at rate %lu at timing %d\n",
                     "msm_set_clock_rate_for_bus_mode",uVar8,bVar1);
    }
  }
  else {
    lVar10 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
    if (lVar10 == 0) {
      lVar10 = *(long *)(*(long *)(param_1 + 0x48) + 8);
    }
    _printk(&DAT_0010ba07,lVar10,uVar7,bVar1);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_bus_voting @ 00105d48 size=76
// signature: undefined sdhci_msm_bus_voting(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void sdhci_msm_bus_voting(long param_1,ulong param_2)

{
  char cVar1;
  ulong uVar2;
  
  if ((param_2 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(ulong *)(param_1 + 0x608);
    cVar1 = *(char *)(*(long *)(param_1 + 0x48) + 0x41f);
    if (cVar1 == '\0') {
      uVar2 = uVar2 >> 3;
    }
    else if (cVar1 == '\x02') {
      uVar2 = uVar2 >> 1;
    }
  }
  sdhci_msm_bus_get_and_set_vote(param_1,uVar2);
  return;
}



//------------------------------------------------------------
// writew @ 00105d94 size=136
// signature: undefined writew(void)
// callers: [sdhci_msm_start_signal_voltage_switch, sdhci_msm_set_uhs_signaling, sdhci_msm_set_clock]
//------------------------------------------------------------

void writew(undefined2 param_1,undefined2 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x10,param_2,0x105db0,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x10,param_2,0x105dec,uVar1);
  return;
}



//------------------------------------------------------------
// readw @ 00105e1c size=140
// signature: undefined readw(void)
// callers: [sdhci_msm_start_signal_voltage_switch, sdhci_msm_set_uhs_signaling, sdhci_msm_set_clock]
//------------------------------------------------------------

undefined2 readw(undefined2 *param_1)

{
  ulong uVar1;
  undefined2 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x10,param_1,readw,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x10,param_1,0x105e74,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readb @ 00105ea8 size=140
// signature: undefined readb(void)
// callers: [sdhci_msm_set_timeout]
//------------------------------------------------------------

undefined1 readb(undefined1 *param_1)

{
  ulong uVar1;
  undefined1 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(8,param_1,readb,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,8,param_1,0x105f00,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// msm_init_cm_dll @ 00105f34 size=1332
// signature: undefined msm_init_cm_dll(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_execute_tuning, sdhci_msm_set_uhs_signaling, sdhci_msm_registers_restore]
//------------------------------------------------------------

undefined8 msm_init_cm_dll(long param_1,int param_2)

{
  long lVar1;
  undefined4 uVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  undefined8 uVar12;
  long lVar13;
  undefined8 *puVar14;
  long *plVar15;
  
  puVar14 = *(undefined8 **)(param_1 + 0x48);
  lVar13 = *(long *)(param_1 + 0x670);
  cVar3 = *(char *)(puVar14 + 0x84);
  if (*(uint *)(param_1 + 0x30c) >> 7 < 0xc35) {
    uVar7 = 400000;
  }
  else {
    uVar12 = *(undefined8 *)(param_1 + 0x5c0);
    uVar8 = clk_get_rate(uVar12);
    uVar7 = clk_round_rate(uVar12,uVar8);
    uVar7 = uVar7 >> (ulong)(*(ulong *)(param_1 + 0x608) != (ulong)*(uint *)(param_1 + 0x30c));
  }
  lVar1 = param_1 + 0x2f0;
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  plVar15 = (long *)(param_1 + 0x18);
  uVar5 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x44));
  writel_relaxed(uVar5 & 0xfffffffd,*plVar15 + (ulong)*(uint *)(lVar13 + 0x44));
  if (*(char *)(param_1 + 0x630) != '\0') {
    uVar6 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x3c));
    writel_relaxed(uVar6 & 0xfffbffff,*plVar15 + (ulong)*(uint *)(lVar13 + 0x3c));
    uVar6 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 100));
    writel_relaxed(uVar6 | 0x200000,*plVar15 + (ulong)*(uint *)(lVar13 + 100));
  }
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar6 | 0x40000000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar6 | 0x20000000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  if (*(char *)(param_1 + 0x7a2) != '\0') {
    if (*(long *)(param_1 + 0x7a8) == 0) {
      writel_relaxed(0x10,*plVar15 + (ulong)*(uint *)(lVar13 + 0x68));
      uVar2 = 0x2c010800;
    }
    else {
      writel_relaxed(*(undefined4 *)(*(long *)(param_1 + 0x7a8) + 8),
                     *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x68));
      uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x7a8) + 0xc);
    }
    writel_relaxed(uVar2,*plVar15 + (ulong)*(uint *)(lVar13 + 0x74));
  }
  lVar10 = 0x6c;
  if (*(char *)(param_1 + 0x680) != '\0') {
    lVar10 = 0x70;
  }
  if ((*(long *)(param_1 + 0x7a8) == 0) ||
     (iVar11 = *(int *)(*(long *)(param_1 + 0x7a8) + 0x10), iVar11 == 0)) {
    iVar11 = -0x7ffbf78d;
  }
  writel_relaxed(iVar11,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + lVar10));
  if (*(char *)(param_1 + 0x630) != '\0') {
    if (param_2 == 0) {
      uVar9 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 100));
      lVar10 = 4;
      if ((uVar9 & 0x40000) != 0) {
        lVar10 = 8;
      }
      uVar9 = lVar10 * (ulong)uVar7;
      iVar11 = (int)(uVar9 / 19200000);
      if (9599999 < uVar9 % 19200000) {
        iVar11 = iVar11 + 1;
      }
      if (uVar7 < 100000000) {
        lVar10 = puVar14[0xf];
        if (lVar10 == 0) {
          lVar10 = puVar14[1];
        }
        _printk(&DAT_0010aa58,lVar10,"msm_init_cm_dll",(ulong)uVar7);
      }
      uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 100));
      writel_relaxed(uVar7 & 0xfffc03ff | iVar11 << 10,*plVar15 + (ulong)*(uint *)(lVar13 + 100));
    }
    if ((*(char *)(param_1 + 0x81a) != '\0') &&
       ((cVar3 == '\x06' || ((*(byte *)((long)puVar14 + 0x3e5) & 1) != 0)))) {
      uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 100));
      writel_relaxed(uVar7 | 0x80000,*plVar15 + (ulong)*(uint *)(lVar13 + 100));
    }
  }
  if (*(long *)(param_1 + 0x7a8) != 0) {
    uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
    writel_relaxed(**(ushort **)(param_1 + 0x7a8) | uVar7,
                   *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar8);
  usleep_range_state(0x37,0x3c,2);
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar7 & 0xbfffffff,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar7 & 0xdfffffff,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar7 | 0x40000000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar7 & 0xbfffffff,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  if (*(char *)(param_1 + 0x630) != '\0') {
    uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 100));
    writel_relaxed(uVar7 & 0xffdfffff,*plVar15 + (ulong)*(uint *)(lVar13 + 100));
  }
  uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar7 | 0x10000,*plVar15 + (ulong)*(uint *)(lVar13 + 0x3c));
  _raw_spin_unlock_irqrestore(lVar1,uVar8);
  usleep_range_state(0x2d,0x32,2);
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x3c));
  writel_relaxed(uVar7 | 0x40000,*plVar15 + (ulong)*(uint *)(lVar13 + 0x3c));
  uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x40));
  if ((uVar7 >> 7 & 1) == 0) {
    uVar7 = 0xffffffce;
    do {
      bVar4 = 0xfffffffe < uVar7;
      uVar7 = uVar7 + 1;
      if (bVar4) {
        lVar10 = puVar14[0xf];
        if (lVar10 == 0) {
          lVar10 = puVar14[1];
        }
        _dev_err(*puVar14,"%s: DLL failed to LOCK\n",lVar10);
        uVar12 = 0xffffff92;
        if ((uVar5 >> 1 & 1) == 0) goto LAB_001063e8;
        goto LAB_001063c4;
      }
      __const_udelay(0x10c7);
      uVar6 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x40));
    } while ((uVar6 >> 7 & 1) == 0);
  }
  uVar12 = 0;
  if ((uVar5 >> 1 & 1) != 0) {
LAB_001063c4:
    uVar7 = readl_relaxed(*plVar15 + (ulong)*(uint *)(lVar13 + 0x44));
    writel_relaxed(uVar7 | 2,*plVar15 + (ulong)*(uint *)(lVar13 + 0x44));
  }
LAB_001063e8:
  _raw_spin_unlock_irqrestore(lVar1,uVar8);
  return uVar12;
}



//------------------------------------------------------------
// msm_config_cm_dll_phase @ 00106468 size=564
// signature: undefined msm_config_cm_dll_phase(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_execute_tuning, sdhci_msm_set_uhs_signaling, sdhci_msm_registers_restore]
//------------------------------------------------------------

undefined8 msm_config_cm_dll_phase(long param_1,byte param_2)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  long lVar9;
  undefined8 *puVar10;
  int iVar11;
  long lVar12;
  
  if (param_2 < 0x10) {
    puVar8 = *(undefined8 **)(param_1 + 0x48);
    lVar9 = *(long *)(param_1 + 0x670);
    uVar5 = _raw_spin_lock_irqsave(param_1 + 0x2f0);
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    writel_relaxed(uVar3 & 0xfff00000 | uVar3 & 0xffff | 0x90000,
                   *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    lVar12 = *(long *)(param_1 + 0x670);
    puVar10 = *(undefined8 **)(param_1 + 0x48);
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar12 + 0x3c));
    if ((uVar3 >> 0x12 & 1) != 0) {
      uVar3 = 0xffffffce;
      do {
        bVar2 = 0xfffffffe < uVar3;
        uVar3 = uVar3 + 1;
        if (bVar2) {
          lVar9 = puVar10[0xf];
          uVar7 = *puVar10;
          if (lVar9 == 0) {
            lVar9 = puVar10[1];
          }
          uVar6 = 0;
          goto LAB_0010666c;
        }
        __const_udelay(0x10c7);
        uVar4 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar12 + 0x3c));
      } while ((uVar4 >> 0x12 & 1) != 0);
    }
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    if (0xf < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10669c);
      (*pcVar1)();
    }
    writel_relaxed(uVar3 & 0xff0fffff |
                   (uint)(byte)(&msm_config_cm_dll_phase_grey_coded_phase_table)[param_2] << 0x14,
                   *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    writel_relaxed(uVar3 | 0x40000,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    lVar12 = *(long *)(param_1 + 0x670);
    puVar10 = *(undefined8 **)(param_1 + 0x48);
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar12 + 0x3c));
    if ((uVar3 >> 0x12 & 1) == 0) {
      iVar11 = -0x32;
LAB_001065b0:
      bVar2 = iVar11 != -1;
      iVar11 = iVar11 + 1;
      if (bVar2) goto code_r0x001065b8;
      lVar9 = puVar10[0xf];
      uVar7 = *puVar10;
      if (lVar9 == 0) {
        lVar9 = puVar10[1];
      }
      uVar6 = 1;
LAB_0010666c:
      _dev_err(uVar7,"%s: CK_OUT_EN bit is not %d\n",lVar9,uVar6);
      lVar9 = puVar8[0xf];
      if (lVar9 == 0) {
        lVar9 = puVar8[1];
      }
      _dev_err(*puVar8,"%s: Failed to set DLL phase: %d\n",lVar9,param_2);
      uVar7 = 0xffffff92;
      goto LAB_00106600;
    }
LAB_001065d4:
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    writel_relaxed(uVar3 & 0xfff7ffff | 0x20000,
                   *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar9 + 0x3c));
    uVar7 = 0;
LAB_00106600:
    _raw_spin_unlock_irqrestore(param_1 + 0x2f0,uVar5);
  }
  else {
    uVar7 = 0xffffffea;
  }
  return uVar7;
code_r0x001065b8:
  __const_udelay(0x10c7);
  uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar12 + 0x3c));
  if ((uVar3 >> 0x12 & 1) != 0) goto LAB_001065d4;
  goto LAB_001065b0;
}



//------------------------------------------------------------
// sdhci_msm_registers_save @ 0010669c size=904
// signature: undefined sdhci_msm_registers_save(void)
// callers: [sdhci_msm_runtime_suspend, sdhci_msm_hw_reset]
//------------------------------------------------------------

void sdhci_msm_registers_save(long param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x670);
  plVar3 = *(long **)(*(long *)(param_1 + 0x48) + 0x5f8);
  if ((*(char *)(param_1 + 0x7b0) != '\0') || (*(char *)(param_1 + 0x795) != '\0')) {
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x44));
    *(undefined4 *)(param_1 + 0x7c0) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x2c));
    *(undefined4 *)(param_1 + 0x7b4) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x50));
    *(undefined4 *)(param_1 + 0x7c4) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x60));
    *(undefined4 *)(param_1 + 0x7c8) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x2c);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x106904);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x2c);
    }
    *(undefined4 *)(param_1 + 0x7cc) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x3c);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10692c);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x3c);
    }
    *(undefined4 *)(param_1 + 0x7dc) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x34));
    *(undefined4 *)(param_1 + 0x7b8) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x38);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x106954);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x38);
    }
    *(undefined4 *)(param_1 + 0x7d8) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x34);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10697c);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x34);
    }
    *(undefined4 *)(param_1 + 0x7d4) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x28);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1069a4);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x28);
    }
    *(undefined4 *)(param_1 + 2000) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x54));
    *(undefined4 *)(param_1 + 0x7bc) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x44);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1069cc);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x44);
    }
    *(undefined4 *)(param_1 + 0x7e0) = uVar1;
    pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
    if (pcVar2 == (code *)0x0) {
      uVar1 = readl(*(long *)(param_1 + 0x18) + 0x260);
    }
    else {
      if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1069f4);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,0x260);
    }
    *(undefined4 *)(param_1 + 0x7f8) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x18));
    *(undefined4 *)(param_1 + 0x7e4) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x3c));
    *(undefined4 *)(param_1 + 0x7e8) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 100));
    *(undefined4 *)(param_1 + 0x7ec) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x3c));
    *(undefined4 *)(param_1 + 0x7e8) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x68));
    *(undefined4 *)(param_1 + 0x7f0) = uVar1;
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar4 + 0x74));
    *(undefined4 *)(param_1 + 0x7f4) = uVar1;
    if (plVar3 != (long *)0x0) {
      pcVar2 = *(code **)(*plVar3 + 0x10);
      if (pcVar2 == (code *)0x0) {
        uVar1 = readl_relaxed(plVar3[1] + 0xa00);
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x7658050d) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x106a1c);
          (*pcVar2)();
        }
        uVar1 = (*pcVar2)(plVar3,0xa00);
      }
      *(undefined4 *)(param_1 + 0x7fc) = uVar1;
    }
    *(undefined1 *)(param_1 + 0x7b1) = 1;
    if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
      ipc_log_string(*(long *)(param_1 + 0x828),"%s: Registers saved\n","sdhci_msm_registers_save");
    }
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_registers_restore @ 00106a24 size=1492
// signature: undefined sdhci_msm_registers_restore(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_hw_reset]
//------------------------------------------------------------

void sdhci_msm_registers_restore(long param_1)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  long lVar9;
  code *pcVar10;
  long *plVar11;
  uint uVar12;
  long lVar13;
  
  lVar9 = *(long *)(param_1 + 0x48);
  lVar13 = *(long *)(param_1 + 0x670);
  uVar1 = *(uint *)(lVar9 + 0x410);
  bVar2 = *(byte *)(lVar9 + 0x420);
  plVar11 = *(long **)(lVar9 + 0x5f8);
  if (((*(char *)(param_1 + 0x7b0) == '\0') || (*(char *)(param_1 + 0x7b1) == '\0')) &&
     (*(char *)(param_1 + 0x795) == '\0')) {
    return;
  }
  writel_relaxed(0,*(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x2c));
  writel_relaxed(*(undefined4 *)(param_1 + 0x7c0),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x44));
  writel_relaxed(*(undefined4 *)(param_1 + 0x7c4),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x50));
  writel_relaxed(*(undefined4 *)(param_1 + 0x7c8),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x60));
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 0x7cc),*(long *)(param_1 + 0x18) + 0x2c);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106eb8);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 0x7cc),0x2c);
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 0x7dc),*(long *)(param_1 + 0x18) + 0x3c);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106ee4);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 0x7dc),0x3c);
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 0x7d8),*(long *)(param_1 + 0x18) + 0x38);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106f10);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 0x7d8),0x38);
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 0x7d4),*(long *)(param_1 + 0x18) + 0x34);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106f3c);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 0x7d4),0x34);
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 2000),*(long *)(param_1 + 0x18) + 0x28);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106f68);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 2000),0x28);
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 0x7f8),*(long *)(param_1 + 0x18) + 0x260);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106f94);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 0x7f8),0x260);
  }
  writel_relaxed(*(undefined4 *)(param_1 + 0x7bc),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x54));
  pcVar10 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar10 == (code *)0x0) {
    writel(*(undefined4 *)(param_1 + 0x7e0),*(long *)(param_1 + 0x18) + 0x44);
  }
  else {
    if (*(int *)(pcVar10 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106fc0);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,*(undefined4 *)(param_1 + 0x7e0),0x44);
  }
  writel_relaxed(*(undefined4 *)(param_1 + 0x7e4),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x18));
  *(undefined1 *)(param_1 + 0x7b1) = 0;
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106bf8);
    (*pcVar10)();
  }
  uVar4 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar13 + 0x28));
  lVar9 = *(long *)(param_1 + 0x670);
  uVar4 = uVar4 & 0xf;
  uVar12 = 0xfffffff5;
  do {
    bVar3 = 0xfffffffe < uVar12;
    uVar12 = uVar12 + 1;
    if (bVar3) {
      lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
      if (lVar9 == 0) {
        lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 8);
      }
      _printk(&DAT_0010afb4,lVar9,uVar4);
      lVar13 = *(long *)(param_1 + 0x670);
      lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
      if (lVar9 == 0) {
        lVar9 = *(long *)(*(long *)(param_1 + 0x48) + 8);
      }
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106e0c);
        (*pcVar10)();
      }
      uVar6 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar13 + 0x28));
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106e3c);
        (*pcVar10)();
      }
      uVar7 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar13 + 0x2c));
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) == -0x4b30ea5b) {
        uVar8 = (*(code *)**(undefined8 **)(param_1 + 0x668))
                          (param_1,*(undefined4 *)(lVar13 + 0x34));
        _printk(&DAT_0010bd0a,lVar9,uVar6,uVar7,uVar8);
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x800,0x106e90);
        (*pcVar10)();
      }
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106e6c);
      (*pcVar10)();
    }
    pcVar10 = *(code **)(*(long *)(param_1 + 0x668) + 8);
    if (*(int *)(pcVar10 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106c3c);
      (*pcVar10)();
    }
    (*pcVar10)(uVar4,param_1,*(undefined4 *)(lVar9 + 0x30));
    DataSynchronizationBarrier(3,3,0);
    __const_udelay(0xa7c6);
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106c74);
      (*pcVar10)();
    }
    uVar5 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar9 + 0x28));
  } while ((uVar5 & uVar4) != 0);
  writel_relaxed(*(undefined4 *)(param_1 + 0x7b8),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x34));
  writel_relaxed(*(undefined4 *)(param_1 + 0x7b4),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x2c));
  uVar12 = (uint)bVar2;
  if (plVar11 == (long *)0x0) {
LAB_00106cd0:
    if (uVar12 != 5) goto LAB_00106ce0;
LAB_00106cd8:
    if ((*(byte *)(param_1 + 0x2f4) >> 4 & 1) == 0) goto LAB_00106ce0;
  }
  else {
    pcVar10 = *(code **)(*plVar11 + 8);
    uVar4 = *(uint *)(param_1 + 0x7fc) & 0x7fffffff;
    if (pcVar10 == (code *)0x0) {
      writel_relaxed(uVar4,plVar11[1] + 0xa00);
      goto LAB_00106cd0;
    }
    if (*(int *)(pcVar10 + -4) != -0x70df82e2) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8229,0x106fec);
      (*pcVar10)();
    }
    (*pcVar10)(plVar11,uVar4,0xa00);
    if (uVar12 == 5) goto LAB_00106cd8;
LAB_00106ce0:
    if ((1 < uVar12 - 9 && uVar12 != 6) || (uVar1 < 0x5f5e101)) goto LAB_00106d6c;
  }
  writel_relaxed(*(undefined4 *)(param_1 + 0x7ec),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 100));
  writel_relaxed(*(undefined4 *)(param_1 + 0x7f0),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x68));
  writel_relaxed(*(undefined4 *)(param_1 + 0x7f4),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x74));
  writel_relaxed(*(uint *)(param_1 + 0x7e8) & 0x9fffffff,
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(lVar13 + 0x3c));
  msm_init_cm_dll(param_1,1);
  msm_config_cm_dll_phase(param_1,*(undefined1 *)(param_1 + 0x633));
LAB_00106d6c:
  if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(param_1 + 0x828),"%s: Registers restored\n",
                   "sdhci_msm_registers_restore");
  }
  return;
}



//------------------------------------------------------------
// readl @ 00106ffc size=140
// signature: undefined readl(void)
// callers: [sdhci_msm_registers_save, sdhci_msm_cqe_disable, sdhci_msm_ice_wait_bist_status, sdhci_enable_ext_fb_clk, sdhci_msm_cqe_add_host, sdhci_msm_cqe_enable]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x107054,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00107088 size=136
// signature: undefined writel(void)
// callers: [sdhci_msm_cqe_disable, sdhci_msm_registers_restore, sdhci_enable_ext_fb_clk, sdhci_msm_cqe_enable]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1070a0,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1070e0,uVar1);
  return;
}



//------------------------------------------------------------
// dbg_state_show @ 00107114 size=60
// signature: undefined dbg_state_show(void)
// callers: []
//------------------------------------------------------------

long dbg_state_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010ac56,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0x830))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// dbg_state_store @ 00107154 size=156
// signature: undefined dbg_state_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dbg_state_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined1 local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c[0] = 0;
  uVar2 = capable(0x15);
  if ((uVar2 & 1) == 0) {
    param_4 = 0xfffffffffffffff3;
  }
  else {
    iVar1 = kstrtobool(param_3,local_3c);
    if (iVar1 == 0) {
      *(undefined1 *)(lVar3 + 0x830) = local_3c[0];
    }
    else {
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sdhci_msm_dt_parse_vreg_info @ 001071f0 size=648
// signature: undefined sdhci_msm_dt_parse_vreg_info(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void sdhci_msm_dt_parse_vreg_info(long param_1,undefined8 *param_2,char *param_3)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  uint *puVar5;
  undefined8 uVar6;
  long lVar7;
  int local_bc;
  char local_b8 [32];
  long local_98 [11];
  
  lVar7 = sp_el0;
  local_98[10] = *(long *)(lVar7 + 0x638);
  uVar6 = *(undefined8 *)(param_1 + 0x2e8);
  local_bc = 0;
  lVar7 = *(long *)(param_1 + 0x98);
  local_b8[0x10] = '\0';
  local_b8[0x11] = '\0';
  local_b8[0x12] = '\0';
  local_b8[0x13] = '\0';
  local_b8[0x14] = '\0';
  local_b8[0x15] = '\0';
  local_b8[0x16] = '\0';
  local_b8[0x17] = '\0';
  local_b8[0x18] = '\0';
  local_b8[0x19] = '\0';
  local_b8[0x1a] = '\0';
  local_b8[0x1b] = '\0';
  local_b8[0x1c] = '\0';
  local_b8[0x1d] = '\0';
  local_b8[0x1e] = '\0';
  local_b8[0x1f] = '\0';
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b8[8] = '\0';
  local_b8[9] = '\0';
  local_b8[10] = '\0';
  local_b8[0xb] = '\0';
  local_b8[0xc] = '\0';
  local_b8[0xd] = '\0';
  local_b8[0xe] = '\0';
  local_b8[0xf] = '\0';
  snprintf(local_b8,0x20,"%s-supply",param_3);
  local_98[8] = 0;
  local_98[9] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  iVar3 = __of_parse_phandle_with_args(uVar6,local_b8,0,0,0,local_98);
  if ((iVar3 == 0) && (local_98[0] != 0)) {
    plVar4 = (long *)devm_kmalloc(param_1,0x30,0xdc0);
    if (plVar4 == (long *)0x0) {
      uVar6 = 0xfffffff4;
    }
    else {
      plVar4[2] = (long)param_3;
      *plVar4 = lVar7 + 0x580;
      snprintf(local_b8,0x20,"qcom,%s-always-on",param_3);
      lVar7 = of_get_property(uVar6,local_b8,0);
      if (lVar7 != 0) {
        *(undefined1 *)((long)plVar4 + 0x29) = 1;
      }
      snprintf(local_b8,0x20,"qcom,%s-lpm-sup",param_3);
      lVar7 = of_get_property(uVar6,local_b8,0);
      if (lVar7 != 0) {
        *(undefined1 *)((long)plVar4 + 0x2a) = 1;
      }
      snprintf(local_b8,0x20,"qcom,%s-voltage-level",param_3);
      puVar5 = (uint *)of_get_property(uVar6,local_b8,&local_bc);
      if ((puVar5 == (uint *)0x0) || (local_bc != 8)) {
        pcVar1 = "no";
        if (puVar5 != (uint *)0x0) {
          pcVar1 = "invalid format";
        }
        _dev_warn(param_1,"%s %s property\n",pcVar1,local_b8);
      }
      else {
        uVar2 = (*puVar5 & 0xff00ff00) >> 8 | (*puVar5 & 0xff00ff) << 8;
        *(uint *)(plVar4 + 3) = uVar2 >> 0x10 | uVar2 << 0x10;
        uVar2 = (puVar5[1] & 0xff00ff00) >> 8 | (puVar5[1] & 0xff00ff) << 8;
        *(uint *)((long)plVar4 + 0x1c) = uVar2 >> 0x10 | uVar2 << 0x10;
      }
      snprintf(local_b8,0x20,"qcom,%s-current-level",param_3);
      puVar5 = (uint *)of_get_property(uVar6,local_b8,&local_bc);
      if ((puVar5 == (uint *)0x0) || (local_bc != 8)) {
        pcVar1 = "no";
        if (puVar5 != (uint *)0x0) {
          pcVar1 = "invalid format";
        }
        _dev_warn(param_1,"%s %s property\n",pcVar1,local_b8);
      }
      else {
        uVar2 = (*puVar5 & 0xff00ff00) >> 8 | (*puVar5 & 0xff00ff) << 8;
        *(uint *)(plVar4 + 4) = uVar2 >> 0x10 | uVar2 << 0x10;
        uVar2 = (puVar5[1] & 0xff00ff00) >> 8 | (puVar5[1] & 0xff00ff) << 8;
        *(uint *)((long)plVar4 + 0x24) = uVar2 >> 0x10 | uVar2 << 0x10;
      }
      uVar6 = 0;
      *param_2 = plVar4;
    }
  }
  else {
    _dev_info(param_1,"No vreg data found for %s\n",param_3);
    uVar6 = 0;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_dt_get_array @ 00107478 size=260
// signature: undefined sdhci_msm_dt_get_array(void)
// callers: [sdhci_msm_bus_register, sdhci_msm_probe]
//------------------------------------------------------------

int sdhci_msm_dt_get_array(long param_1,undefined8 param_2,long *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar5 = *(undefined8 *)(param_1 + 0x2e8);
  lVar3 = of_get_property(uVar5,param_2,param_4);
  if (lVar3 == 0) {
    iVar2 = -0x16;
  }
  else {
    uVar1 = *param_4;
    *param_4 = (int)uVar1 >> 2;
    if (uVar1 < 4) {
      _dev_err(param_1,"%s invalid size\n",param_2);
      iVar2 = -0x16;
    }
    else {
      lVar3 = (long)((ulong)uVar1 << 0x20) >> 0x22;
      lVar4 = devm_kmalloc(param_1,lVar3 << 2,0xdc0);
      if (lVar4 == 0) {
        iVar2 = -0xc;
      }
      else {
        iVar2 = of_property_read_variable_u32_array(uVar5,param_2,lVar4,lVar3,0);
        if (-1 < iVar2) {
          *param_3 = lVar4;
          return 0;
        }
        _dev_err(param_1,"%s failed reading array %d\n",param_2,iVar2);
      }
    }
  }
  *param_4 = 0;
  return iVar2;
}



//------------------------------------------------------------
// sdhci_msm_bus_register @ 0010757c size=788
// signature: undefined sdhci_msm_bus_register(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void sdhci_msm_bus_register(long param_1,long param_2)

{
  long lVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  int iVar12;
  ulong uVar13;
  long *plVar14;
  long lVar15;
  undefined8 uVar16;
  undefined8 local_60;
  long local_58;
  
  lVar6 = sp_el0;
  lVar1 = param_2 + 0x10;
  local_58 = *(long *)(lVar6 + 0x638);
  uVar16 = *(undefined8 *)(param_2 + 0x2f8);
  local_60 = 0;
  if (param_2 == 0) {
    pcVar10 = "Null platform device!\n";
LAB_001077ec:
    _dev_err(lVar1,pcVar10);
  }
  else {
    lVar6 = devm_kmalloc(lVar1,0x40,0xdc0);
    if (lVar6 != 0) {
      iVar5 = sdhci_msm_dt_get_array(lVar1,"qcom,bus-bw-vectors-bps",lVar6 + 0x18,lVar6 + 0x20);
      if (iVar5 == 0) {
        iVar5 = of_property_read_string(uVar16,"qcom,msm-bus,name",lVar6);
        if (iVar5 == 0) {
          puVar2 = (uint *)(lVar6 + 8);
          iVar5 = of_property_read_variable_u32_array(uVar16,"qcom,msm-bus,num-cases",puVar2,1,0);
          if (iVar5 < 0) {
            pcVar10 = "num-usecases not found err:(%d)\n";
          }
          else {
            lVar7 = devm_kmalloc(lVar1,(ulong)*puVar2 << 4,0xdc0);
            if (lVar7 == 0) goto LAB_001077f4;
            iVar5 = of_property_read_variable_u32_array
                              (uVar16,"qcom,msm-bus,num-paths",(long)&local_60 + 4,1,0);
            if (-1 < iVar5) {
              lVar8 = of_get_property(uVar16,"qcom,msm-bus,vectors-KBps",&local_60);
              if (lVar8 != 0) {
                if (*puVar2 != 0) {
                  iVar5 = 0;
                  uVar13 = 0;
                  uVar11 = local_60 >> 0x20;
                  do {
                    iVar12 = (int)uVar13;
                    *(int *)(lVar7 + (-(uVar13 >> 0x1f) & 0xfffffff000000000 | uVar13 << 4)) =
                         (int)uVar11;
                    if ((int)uVar11 < 0) {
                      *(undefined8 *)(lVar7 + (long)iVar12 * 0x10 + 8) = 0;
                      goto LAB_001077f4;
                    }
                    lVar9 = devm_kmalloc(lVar1,uVar11 << 4,0xdc0);
                    plVar14 = (long *)(lVar7 + (long)iVar12 * 0x10 + 8);
                    *plVar14 = lVar9;
                    if (lVar9 == 0) goto LAB_001077f4;
                    uVar11 = (ulong)local_60._4_4_;
                    if (0 < (int)local_60._4_4_) {
                      lVar9 = 0;
                      do {
                        iVar3 = local_60._4_4_ * iVar5 + (int)lVar9;
                        lVar15 = lVar9 * 8;
                        lVar9 = lVar9 + 2;
                        uVar4 = *(uint *)(lVar8 + (long)iVar3 * 4);
                        uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
                        *(ulong *)(*plVar14 + lVar15) = (ulong)(uVar4 >> 0x10 | uVar4 << 0x10);
                        uVar4 = *(uint *)(lVar8 + (long)(iVar3 + 1) * 4);
                        uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
                        *(ulong *)(*plVar14 + lVar15 + 8) = (ulong)(uVar4 >> 0x10 | uVar4 << 0x10);
                      } while (uVar11 * 2 != lVar9);
                    }
                    uVar13 = (ulong)(iVar12 + 1U);
                    iVar5 = iVar5 + 2;
                  } while (iVar12 + 1U < *puVar2);
                }
                *(long *)(lVar6 + 0x10) = lVar7;
                *(long *)(param_1 + 0x108) = lVar6;
                uVar11 = of_icc_get(lVar1,"sdhc-ddr");
                *(ulong *)(lVar6 + 0x28) = uVar11;
                if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
                  _dev_info(lVar1,"(%ld): failed getting %s path\n",uVar11,"sdhc-ddr");
                  *(undefined8 *)(lVar6 + 0x28) = 0;
                }
                uVar11 = of_icc_get(lVar1,"cpu-sdhc");
                *(ulong *)(lVar6 + 0x30) = uVar11;
                if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
                  _dev_info(lVar1,"(%ld): failed getting %s path\n",uVar11,"cpu-sdhc");
                  uVar16 = 0;
                  *(undefined8 *)(lVar6 + 0x30) = 0;
                }
                else {
                  uVar16 = 0;
                }
                goto LAB_00107808;
              }
              pcVar10 = "Vector array not found\n";
              goto LAB_001077ec;
            }
            pcVar10 = "num_paths not found err:(%d)\n";
          }
        }
        else {
          pcVar10 = "Bus name missing err:(%d)\n";
        }
        _dev_err(lVar1,pcVar10,iVar5);
      }
      else if (iVar5 == -0x16) {
        *(undefined1 *)(param_1 + 0x101) = 1;
      }
    }
  }
LAB_001077f4:
  _dev_err(lVar1,"Failed to get bus_scale data\n");
  uVar16 = 0xffffffea;
LAB_00107808:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar16);
  }
  return;
}



//------------------------------------------------------------
// sdhci_enable_ext_fb_clk @ 00107890 size=176
// signature: undefined sdhci_enable_ext_fb_clk(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

void sdhci_enable_ext_fb_clk(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  pcVar2 = (code *)**(undefined8 **)(param_1 + 0x40);
  if (pcVar2 == (code *)0x0) {
    uVar1 = readl(*(long *)(param_1 + 0x18) + 0x260);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10790c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,0x260);
  }
  pcVar2 = *(code **)(*(long *)(param_1 + 0x40) + 0x18);
  if (pcVar2 == (code *)0x0) {
    writel(uVar1 | 0x1000000,*(long *)(param_1 + 0x18) + 0x260);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x107938);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,uVar1 | 0x1000000,0x260);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_handle_pwr_irq @ 00107940 size=2096
// signature: undefined sdhci_msm_handle_pwr_irq(void)
// callers: [sdhci_msm_pwr_irq, sdhci_msm_setup_pwr_irq]
//------------------------------------------------------------

void sdhci_msm_handle_pwr_irq(long param_1,undefined4 param_2)

{
  long *plVar1;
  uint uVar2;
  bool bVar3;
  undefined *puVar4;
  bool bVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  ulong uVar17;
  char *pcVar18;
  undefined8 uVar19;
  undefined1 uVar20;
  undefined8 *puVar21;
  uint uVar22;
  uint uVar23;
  long lVar24;
  uint *puVar25;
  long lVar26;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  long local_68;
  
  lVar24 = sp_el0;
  local_68 = *(long *)(lVar24 + 0x638);
  lVar24 = *(long *)(param_1 + 0x670);
  puVar21 = *(undefined8 **)(param_1 + 0x48);
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1079a4);
    (*pcVar6)();
  }
  uVar10 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar24 + 0x28));
  uVar2 = uVar10 & 0xf;
  if ((*(long *)(param_1 + 0x828) != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(param_1 + 0x828),"%s: Received IRQ(%d), irq_status=0x%x\n",
                   "sdhci_msm_handle_pwr_irq",param_2,uVar2);
  }
  pcVar6 = *(code **)(*(long *)(param_1 + 0x668) + 8);
  if (*(int *)(pcVar6 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107a08);
    (*pcVar6)();
  }
  (*pcVar6)(uVar2,param_1,*(undefined4 *)(lVar24 + 0x30));
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107a34);
    (*pcVar6)();
  }
  uVar11 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar24 + 0x28));
  if ((uVar11 & uVar2) != 0) {
    uVar11 = 0xfffffff5;
    do {
      bVar7 = 0xfffffffe < uVar11;
      uVar11 = uVar11 + 1;
      if (bVar7) {
        lVar24 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
        if (lVar24 == 0) {
          lVar24 = *(long *)(*(long *)(param_1 + 0x48) + 8);
        }
        _printk(&DAT_0010afb4,lVar24,uVar2);
        lVar24 = *(long *)(param_1 + 0x670);
        lVar26 = *(long *)(*(long *)(param_1 + 0x48) + 0x78);
        if (lVar26 == 0) {
          lVar26 = *(long *)(*(long *)(param_1 + 0x48) + 8);
        }
        if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107b88);
          (*pcVar6)();
        }
        uVar14 = (*(code *)**(undefined8 **)(param_1 + 0x668))
                           (param_1,*(undefined4 *)(lVar24 + 0x28));
        if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107bb8);
          (*pcVar6)();
        }
        uVar15 = (*(code *)**(undefined8 **)(param_1 + 0x668))
                           (param_1,*(undefined4 *)(lVar24 + 0x2c));
        if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) == -0x4b30ea5b) {
          uVar16 = (*(code *)**(undefined8 **)(param_1 + 0x668))
                             (param_1,*(undefined4 *)(lVar24 + 0x34));
          _printk(&DAT_0010bd0a,lVar26,uVar14,uVar15,uVar16);
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x107c0c);
          (*pcVar6)();
        }
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107be8);
        (*pcVar6)();
      }
      pcVar6 = *(code **)(*(long *)(param_1 + 0x668) + 8);
      if (*(int *)(pcVar6 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107a78);
        (*pcVar6)();
      }
      (*pcVar6)(uVar2,param_1,*(undefined4 *)(lVar24 + 0x30));
      __const_udelay(0xa7c6);
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0x668) + -4) != -0x4b30ea5b) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107aac);
        (*pcVar6)();
      }
      uVar12 = (*(code *)**(undefined8 **)(param_1 + 0x668))(param_1,*(undefined4 *)(lVar24 + 0x28))
      ;
    } while ((uVar12 & uVar2) != 0);
  }
  if ((puVar21[0x90] != 0) && (pcVar6 = *(code **)(puVar21[0x74] + 0x30), pcVar6 != (code *)0x0)) {
    if (*(int *)(pcVar6 + -4) != 0x138bf33d) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107ae8);
      (*pcVar6)();
    }
    iVar13 = (*pcVar6)(puVar21);
    if ((iVar13 == 0) && ((uVar10 >> 1 & 1) != 0)) {
      pcVar6 = *(code **)(*(long *)(param_1 + 0x668) + 8);
      if (*(int *)(pcVar6 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107b20);
        (*pcVar6)();
      }
      (*pcVar6)(2,param_1,*(undefined4 *)(lVar24 + 0x34));
      goto LAB_00107fd0;
    }
  }
  plVar1 = (long *)(param_1 + 0x580);
  if ((uVar2 >> 1 & 1) == 0) {
    iVar13 = 0;
    uVar11 = 0;
    bVar7 = false;
    uVar12 = 0;
    uVar23 = 0;
    uVar22 = 0;
    if ((uVar10 & 1) != 0) {
LAB_00107c90:
      if (((*(byte *)(*(long *)(param_1 + 0x48) + 0x3e5) & 1) == 0) ||
         (*(char *)(param_1 + 0x7a0) != '\0')) {
        iVar13 = sdhci_msm_setup_vreg(plVar1,0);
      }
      if (iVar13 == 0) {
        iVar13 = sdhci_msm_set_vdd_io_vol(plVar1,0);
      }
      uVar23 = 1;
      uVar10 = 1;
      if (iVar13 != 0) {
        uVar10 = 2;
      }
      uVar12 = 4;
      uVar11 = uVar10 | uVar11;
      goto LAB_00107cd4;
    }
joined_r0x00107e7c:
    if ((uVar2 >> 2 & 1) == 0) goto LAB_00107c44;
LAB_00107e80:
    iVar13 = sdhci_msm_set_vdd_io_vol(plVar1,0);
    if (iVar13 == 0) {
      uVar22 = uVar22 | 4;
    }
    else {
      uVar22 = uVar22 | 8;
    }
    uVar12 = 4;
    if (uVar2 < 8) goto LAB_00107c4c;
LAB_00107ea8:
    iVar13 = sdhci_msm_set_vdd_io_vol(plVar1,1);
    if (iVar13 == 0) {
      uVar22 = uVar22 | 4;
    }
    else {
      uVar22 = uVar22 | 8;
    }
    uVar12 = 8;
LAB_00107ec8:
    bVar5 = bVar7;
    if (0xfffffffffffff000 < (ulong)puVar21[0xb9]) {
      bVar5 = true;
    }
    if ((bVar5) || (iVar13 = mmc_regulator_set_vqmmc(puVar21,puVar21 + 0x82), -1 < iVar13)) {
      bVar5 = false;
    }
    else {
      lVar26 = puVar21[0xf];
      if (lVar26 == 0) {
        lVar26 = puVar21[1];
      }
      _dev_err(*puVar21,
               "%s: IO_level setting failed(%d). signal_voltage: %d, vdd: %d irq_status: 0x%08x\n",
               lVar26,iVar13,*(undefined1 *)((long)puVar21 + 0x421),
               *(undefined2 *)((long)puVar21 + 0x414),uVar2);
      bVar5 = false;
      uVar22 = uVar22 | 8;
    }
  }
  else {
    iVar13 = sdhci_msm_setup_vreg(plVar1,1);
    if (iVar13 == 0) {
      iVar13 = sdhci_msm_set_vdd_io_vol(plVar1,1);
    }
    uVar11 = 1;
    if (iVar13 != 0) {
      uVar11 = 2;
    }
    if ((uVar10 & 1) != 0) goto LAB_00107c90;
    uVar23 = 2;
    uVar12 = 8;
LAB_00107cd4:
    uVar17 = puVar21[0xb8];
    uVar10 = uVar23 & 2;
    if (uVar17 < 0xfffffffffffff001) {
      if (uVar10 == 0) {
        uVar19 = 0;
LAB_00107d1c:
        regulator_set_load(uVar17,uVar19);
        uVar17 = puVar21[0xb8];
      }
      else {
        uVar19 = 800000;
        if (puVar21[0x90] == 0) goto LAB_00107d1c;
        iVar13 = *(int *)(puVar21[0x90] + 0x3a0);
        if (iVar13 == 0) {
          uVar19 = 570000;
          goto LAB_00107d1c;
        }
        if (iVar13 == 1) goto LAB_00107d1c;
      }
      iVar13 = mmc_regulator_set_ocr(puVar21,uVar17,*(undefined2 *)((long)puVar21 + 0x414));
      if (iVar13 == 0) goto LAB_00107d3c;
    }
    else {
LAB_00107d3c:
      uVar17 = puVar21[0xb9];
      if ((uVar17 < 0xfffffffffffff001) && (*(char *)((long)puVar21 + 0x41e) != '\x03')) {
        if (((*(byte *)((long)puVar21 + 0x3e5) & 1) == 0) ||
           ((puVar21[0x90] == 0 || (*(int *)(puVar21[0x90] + 0x3a0) != 0)))) {
          local_70 = 0;
          local_80 = 0;
          uStack_78 = 0;
          if ((uint)*(byte *)(param_1 + 0x826) == uVar23 >> 1) goto LAB_00107e44;
          if (uVar10 == 0) {
            regulator_set_load(uVar17,0);
            iVar13 = regulator_disable(puVar21[0xb9]);
          }
          else {
            if (puVar21[0x90] == 0) {
              uVar19 = 0x4f588;
LAB_00107df4:
              regulator_set_load(uVar17,uVar19);
            }
            else if (*(int *)(puVar21[0x90] + 0x3a0) == 1) {
              uVar19 = 22000;
              goto LAB_00107df4;
            }
            uVar22 = *(uint *)(param_1 + 0x65c);
            if ((uVar22 >> 0x19 & 1) == 0) {
              if ((uVar22 >> 0x1a & 1) != 0) {
                uVar20 = 1;
                goto LAB_00107e10;
              }
            }
            else {
              uVar20 = 0;
LAB_00107e10:
              local_70._0_2_ = CONCAT11(uVar20,(undefined1)local_70);
            }
            if (((uVar22 & 0x6000000) != 0) &&
               (iVar13 = mmc_regulator_set_vqmmc(puVar21,&local_80), iVar13 < 0)) {
              lVar26 = puVar21[0xf];
              uVar19 = *puVar21;
              if (lVar26 == 0) {
                lVar26 = puVar21[1];
              }
              pcVar18 = "%s: vqmmc set volgate failed: %d\n";
              goto LAB_00108170;
            }
            iVar13 = regulator_enable(puVar21[0xb9]);
          }
          if (iVar13 == 0) {
            *(char *)(param_1 + 0x826) = (char)(uVar23 >> 1);
            goto LAB_00107e44;
          }
          lVar26 = puVar21[0xf];
          if (lVar26 == 0) {
            lVar26 = puVar21[1];
          }
          puVar4 = &DAT_0010a74f;
          if (uVar10 != 0) {
            puVar4 = &DAT_0010a877;
          }
          _dev_err(*puVar21,"%s: vqmm %sable failed: %d\n",lVar26,puVar4,iVar13);
        }
        else {
          uVar14 = 0;
          if (uVar10 != 0) {
            uVar14 = 0x4f588;
          }
          iVar13 = regulator_set_load(uVar17,uVar14);
          if (iVar13 == 0) goto LAB_00107e44;
          lVar26 = puVar21[0xf];
          uVar19 = *puVar21;
          if (lVar26 == 0) {
            lVar26 = puVar21[1];
          }
          pcVar18 = "%s: vqmmc set load failed: %d\n";
LAB_00108170:
          _dev_err(uVar19,pcVar18,lVar26,iVar13);
        }
      }
      else {
LAB_00107e44:
        if (uVar10 == 0) {
          iVar13 = pinctrl_pm_select_sleep_state();
        }
        else {
          iVar13 = pinctrl_pm_select_default_state(*plVar1 + 0x10);
        }
        if (iVar13 == 0) {
          uVar22 = uVar11 | 1;
          bVar7 = true;
          goto joined_r0x00107e7c;
        }
      }
    }
    uVar22 = uVar11 | 2;
    bVar7 = true;
    if ((uVar2 >> 2 & 1) != 0) goto LAB_00107e80;
LAB_00107c44:
    if (7 < uVar2) goto LAB_00107ea8;
LAB_00107c4c:
    if (uVar12 != 0) goto LAB_00107ec8;
    bVar5 = true;
  }
  pcVar6 = *(code **)(*(long *)(param_1 + 0x668) + 8);
  if (*(int *)(pcVar6 + -4) != -0x78d64671) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x107f18);
    (*pcVar6)();
  }
  (*pcVar6)(uVar22,param_1,*(undefined4 *)(lVar24 + 0x34));
  if ((*(byte *)(param_1 + 0x65f) & 6) != 0) {
    puVar25 = (uint *)(lVar24 + 0x44);
    uVar10 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*puVar25);
    if (uVar12 >> 3 == 0) {
      if ((uVar12 >> 2 & 1) == 0) {
        uVar11 = *(uint *)(param_1 + 0x65c);
LAB_00107f60:
        if ((uVar11 >> 0x1a & 1) == 0) goto LAB_00107f80;
      }
      uVar11 = uVar10 | 0x10000;
joined_r0x00108090:
      uVar17 = (ulong)uVar11;
      if (uVar10 == uVar11) goto LAB_00107f80;
    }
    else {
      uVar11 = *(uint *)(param_1 + 0x65c);
      if (((uVar11 >> 0x19 & 1) == 0) || (*(char *)(param_1 + 0x7a1) != '\0')) goto LAB_00107f60;
      if (*(char *)(param_1 + 0x796) == '\0') {
        uVar11 = uVar10 & 0xfffeffff;
        goto joined_r0x00108090;
      }
      lVar24 = *(long *)(param_1 + 0x48);
      lVar26 = *(long *)(param_1 + 0x670);
      pcVar6 = *(code **)(*(long *)(lVar24 + 0x3a0) + 0x30);
      if (pcVar6 == (code *)0x0) {
        bVar8 = false;
      }
      else {
        if (*(int *)(pcVar6 + -4) != 0x138bf33d) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x108040);
          (*pcVar6)();
        }
        iVar13 = (*pcVar6)(lVar24);
        bVar8 = iVar13 != 0;
      }
      puVar25 = (uint *)(lVar26 + 0x44);
      uVar17 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)*puVar25);
      uVar10 = (uint)uVar17;
      if ((*(long *)(lVar24 + 0x480) == 0) && (bVar8)) {
        if (*(char *)(lVar24 + 0x41e) == '\x01') {
LAB_00108114:
          uVar17 = (ulong)(uVar10 & 0xfffeffff);
        }
        else {
          bVar9 = false;
LAB_001080f8:
          if (!bVar9 && !bVar8) {
            uVar11 = uVar10 | 0x10000;
            if (*(char *)(lVar24 + 0x41e) != '\0') {
              uVar11 = uVar10;
            }
            uVar17 = (ulong)uVar11;
          }
        }
      }
      else {
        bVar9 = *(long *)(lVar24 + 0x480) != 0;
        bVar3 = false;
        if (bVar9) {
          bVar3 = bVar8;
        }
        if (!bVar3) goto LAB_001080f8;
        if (*(char *)(lVar24 + 0x41e) == '\x01') goto LAB_00108114;
        if (*(char *)(lVar24 + 0x41e) == '\0') {
          uVar17 = (ulong)(uVar10 | 0x10000);
        }
      }
    }
    writel_relaxed(uVar17,*(long *)(param_1 + 0x18) + (ulong)*puVar25);
  }
LAB_00107f80:
  if (bVar7) {
    *(uint *)(param_1 + 0x638) = uVar23;
    if (bVar5) goto LAB_00107fa0;
LAB_00107f8c:
    *(uint *)(param_1 + 0x63c) = uVar12;
    lVar24 = *(long *)(param_1 + 0x828);
  }
  else {
    if (!bVar5) goto LAB_00107f8c;
LAB_00107fa0:
    lVar24 = *(long *)(param_1 + 0x828);
  }
  if ((lVar24 != 0) && (*(char *)(param_1 + 0x830) != '\0')) {
    ipc_log_string(lVar24,"%s: Handled IRQ(%d), irq_status=0x%x, ack=0x%x\n",
                   "sdhci_msm_handle_pwr_irq",param_2,uVar2,uVar22);
  }
LAB_00107fd0:
  lVar24 = sp_el0;
  if (*(long *)(lVar24 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_pwr_irq @ 00108180 size=80
// signature: undefined sdhci_msm_pwr_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 sdhci_msm_pwr_irq(undefined4 param_1,long param_2)

{
  sdhci_msm_handle_pwr_irq(param_2,param_1);
  *(undefined1 *)(param_2 + 0x658) = 1;
  __wake_up(param_2 + 0x640,3,1,0);
  return 1;
}



//------------------------------------------------------------
// sdhci_msm_setup_vreg @ 001081d0 size=1056
// signature: undefined sdhci_msm_setup_vreg(void)
// callers: [sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

int sdhci_msm_setup_vreg(long param_1,ulong param_2)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  long *plVar8;
  long lVar9;
  undefined4 uVar10;
  long lVar11;
  long local_78 [3];
  
  lVar11 = sp_el0;
  local_78[2] = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x98);
  if ((*(long *)(param_1 + 0x2a8) != 0) && (*(char *)(param_1 + 0x2b0) != '\0')) {
    pcVar6 = "Enabling";
    if ((param_2 & 1) == 0) {
      pcVar6 = "Disabling";
    }
    ipc_log_string(*(long *)(param_1 + 0x2a8),"%s: %s regulators\n","sdhci_msm_setup_vreg",pcVar6);
  }
  plVar8 = *(long **)(param_1 + 0x90);
  if (plVar8 != (long *)0x0) {
    local_78[1] = plVar8[1];
    local_78[0] = *plVar8;
    if ((((param_2 & 1) == 0) && (*(char *)(local_78[1] + 0x29) != '\0')) &&
       (*(long *)(lVar11 + 0x480) == 0)) {
      *(undefined1 *)(local_78[1] + 0x29) = 0;
      lVar9 = *(long *)(lVar11 + 0x480);
    }
    else {
      lVar9 = *(long *)(lVar11 + 0x480);
    }
    if (((lVar9 == 0) || (*(char *)(lVar9 + 0x49c) != '\0')) ||
       ((*(byte *)(lVar11 + 0x3e5) & 1) == 0)) {
      if (((param_2 & 1) == 0) && ((*(byte *)(lVar11 + 0x3e5) & 1) == 0)) {
        uVar3 = msm_spare_read(2);
        msm_spare_write(2,uVar3 & 0xffff7fff);
      }
      lVar9 = 0;
      bVar2 = true;
LAB_001082e4:
      do {
        bVar1 = bVar2;
        plVar8 = (long *)local_78[lVar9];
        if (plVar8 != (long *)0x0) {
          if ((param_2 & 1) != 0) {
            uVar10 = *(undefined4 *)((long)plVar8 + 0x24);
            lVar9 = *(long *)(*plVar8 + 0x2a8);
            if ((lVar9 != 0) && (*(char *)(*plVar8 + 0x2b0) != '\0')) {
              ipc_log_string(lVar9,"%s: reg=%s uA_load=%d\n","sdhci_msm_vreg_set_optimum_mode",
                             plVar8[2],uVar10);
            }
            if ((*(char *)((long)plVar8 + 0x2b) != '\0') &&
               (iVar4 = regulator_set_load(plVar8[1],uVar10), iVar4 < 0)) {
LAB_0010855c:
              lVar11 = plVar8[2];
LAB_00108578:
              _printk(&DAT_0010a9be,"sdhci_msm_vreg_set_optimum_mode",lVar11,uVar10,iVar4);
              goto LAB_001084fc;
            }
            if ((char)plVar8[5] == '\0') {
              uVar10 = *(undefined4 *)((long)plVar8 + 0x1c);
              lVar9 = *(long *)(*plVar8 + 0x2a8);
              if ((lVar9 != 0) && (*(char *)(*plVar8 + 0x2b0) != '\0')) {
                ipc_log_string(lVar9,"%s: reg=%s min_uV=%d max_uV=%d\n","sdhci_msm_vreg_set_voltage"
                               ,plVar8[2],uVar10,uVar10);
              }
              if ((*(char *)((long)plVar8 + 0x2b) != '\0') &&
                 (iVar4 = regulator_set_voltage(plVar8[1],uVar10,uVar10), iVar4 != 0)) {
                lVar11 = plVar8[2];
                uVar7 = uVar10;
LAB_001085bc:
                _printk(&DAT_0010b003,"sdhci_msm_vreg_set_voltage",lVar11,uVar7,uVar10,iVar4);
                goto LAB_001084fc;
              }
            }
            iVar4 = regulator_enable(plVar8[1]);
            if (iVar4 != 0) {
              lVar11 = plVar8[2];
              puVar5 = &DAT_0010b8c7;
              pcVar6 = "sdhci_msm_vreg_enable";
LAB_00108550:
              _printk(puVar5,pcVar6,lVar11,iVar4);
              goto LAB_001084fc;
            }
            lVar9 = 1;
            *(undefined1 *)(plVar8 + 5) = 1;
            bVar2 = false;
            if (!bVar1) goto LAB_001084dc;
            goto LAB_001082e4;
          }
          if ((char)plVar8[5] != '\0') {
            if (*(char *)((long)plVar8 + 0x29) == '\0') {
              iVar4 = regulator_disable(plVar8[1]);
              if (iVar4 != 0) {
                lVar11 = plVar8[2];
                puVar5 = &DAT_0010ab1a;
                pcVar6 = "sdhci_msm_vreg_disable";
                goto LAB_00108550;
              }
              *(undefined1 *)(plVar8 + 5) = 0;
              lVar9 = *(long *)(*plVar8 + 0x2a8);
              if ((lVar9 != 0) && (*(char *)(*plVar8 + 0x2b0) != '\0')) {
                ipc_log_string(lVar9,"%s: reg=%s uA_load=%d\n","sdhci_msm_vreg_set_optimum_mode",
                               plVar8[2],0);
              }
              if ((*(char *)((long)plVar8 + 0x2b) != '\0') &&
                 (iVar4 = regulator_set_load(plVar8[1],0), iVar4 < 0)) {
                lVar11 = plVar8[2];
                uVar10 = 0;
                goto LAB_00108578;
              }
              uVar10 = *(undefined4 *)((long)plVar8 + 0x1c);
              lVar9 = *(long *)(*plVar8 + 0x2a8);
              if ((lVar9 != 0) && (*(char *)(*plVar8 + 0x2b0) != '\0')) {
                ipc_log_string(lVar9,"%s: reg=%s min_uV=%d max_uV=%d\n","sdhci_msm_vreg_set_voltage"
                               ,plVar8[2],0,uVar10);
              }
              if ((*(char *)((long)plVar8 + 0x2b) != '\0') &&
                 (iVar4 = regulator_set_voltage(plVar8[1],0,uVar10), iVar4 != 0)) {
                lVar11 = plVar8[2];
                uVar7 = 0;
                goto LAB_001085bc;
              }
            }
            else if (*(char *)((long)plVar8 + 0x2a) != '\0') {
              uVar10 = (undefined4)plVar8[4];
              lVar9 = *(long *)(*plVar8 + 0x2a8);
              if ((lVar9 != 0) && (*(char *)(*plVar8 + 0x2b0) != '\0')) {
                ipc_log_string(lVar9,"%s: reg=%s uA_load=%d\n","sdhci_msm_vreg_set_optimum_mode",
                               plVar8[2],uVar10);
              }
              if ((*(char *)((long)plVar8 + 0x2b) != '\0') &&
                 (iVar4 = regulator_set_load(plVar8[1],uVar10), iVar4 < 0)) goto LAB_0010855c;
            }
          }
        }
        lVar9 = 1;
        bVar2 = false;
      } while (bVar1);
      if ((param_2 & 1) != 0) {
LAB_001084dc:
        if ((*(byte *)(lVar11 + 0x3e5) & 1) == 0) {
          uVar3 = msm_spare_read(2);
          msm_spare_write(2,uVar3 | 0x8000);
        }
      }
    }
  }
  iVar4 = 0;
LAB_001084fc:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_78[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// sdhci_msm_set_vdd_io_vol @ 001085f0 size=256
// signature: undefined sdhci_msm_set_vdd_io_vol(void)
// callers: [sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

int sdhci_msm_set_vdd_io_vol(long param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  if (((*(long *)(param_1 + 0x90) != 0) &&
      (plVar5 = *(long **)(*(long *)(param_1 + 0x90) + 8), plVar5 != (long *)0x0)) &&
     ((char)plVar5[5] != '\0')) {
    if (param_2 == 1) {
      plVar4 = (long *)((long)plVar5 + 0x1c);
    }
    else {
      if (param_2 != 0) {
        _printk(&DAT_0010b4f2,"sdhci_msm_set_vdd_io_vol");
        return -0x16;
      }
      plVar4 = plVar5 + 3;
    }
    uVar1 = (undefined4)*plVar4;
    lVar3 = *(long *)(*plVar5 + 0x2a8);
    if ((lVar3 != 0) && (*(char *)(*plVar5 + 0x2b0) != '\0')) {
      ipc_log_string(lVar3,"%s: reg=%s min_uV=%d max_uV=%d\n","sdhci_msm_vreg_set_voltage",plVar5[2]
                     ,uVar1,uVar1);
    }
    if (*(char *)((long)plVar5 + 0x2b) != '\0') {
      iVar2 = regulator_set_voltage(plVar5[1],uVar1,uVar1);
      if (iVar2 == 0) {
        return 0;
      }
      _printk(&DAT_0010b003,"sdhci_msm_vreg_set_voltage",plVar5[2],uVar1,uVar1,iVar2);
      return iVar2;
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_find_most_appropriate_phase @ 001086f0 size=1384
// signature: undefined msm_find_most_appropriate_phase(void)
// callers: [sdhci_msm_execute_tuning]
//------------------------------------------------------------

ulong msm_find_most_appropriate_phase(long param_1,byte *param_2,byte param_3)

{
  ulong uVar1;
  char cVar2;
  byte bVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  long lVar7;
  undefined8 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 local_138;
  char acStack_130 [264];
  long local_28;
  
  lVar7 = sp_el0;
  local_28 = *(long *)(lVar7 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0x48);
  acStack_130[0xf8] = '\0';
  acStack_130[0xf9] = '\0';
  acStack_130[0xfa] = '\0';
  acStack_130[0xfb] = '\0';
  acStack_130[0xfc] = '\0';
  acStack_130[0xfd] = '\0';
  acStack_130[0xfe] = '\0';
  acStack_130[0xff] = '\0';
  acStack_130[0x100] = '\0';
  acStack_130[0x101] = '\0';
  acStack_130[0x102] = '\0';
  acStack_130[0x103] = '\0';
  acStack_130[0x104] = '\0';
  acStack_130[0x105] = '\0';
  acStack_130[0x106] = '\0';
  acStack_130[0x107] = '\0';
  acStack_130[0xe8] = '\0';
  acStack_130[0xe9] = '\0';
  acStack_130[0xea] = '\0';
  acStack_130[0xeb] = '\0';
  acStack_130[0xec] = '\0';
  acStack_130[0xed] = '\0';
  acStack_130[0xee] = '\0';
  acStack_130[0xef] = '\0';
  acStack_130[0xf0] = '\0';
  acStack_130[0xf1] = '\0';
  acStack_130[0xf2] = '\0';
  acStack_130[0xf3] = '\0';
  acStack_130[0xf4] = '\0';
  acStack_130[0xf5] = '\0';
  acStack_130[0xf6] = '\0';
  acStack_130[0xf7] = '\0';
  acStack_130[0xd8] = '\0';
  acStack_130[0xd9] = '\0';
  acStack_130[0xda] = '\0';
  acStack_130[0xdb] = '\0';
  acStack_130[0xdc] = '\0';
  acStack_130[0xdd] = '\0';
  acStack_130[0xde] = '\0';
  acStack_130[0xdf] = '\0';
  acStack_130[0xe0] = '\0';
  acStack_130[0xe1] = '\0';
  acStack_130[0xe2] = '\0';
  acStack_130[0xe3] = '\0';
  acStack_130[0xe4] = '\0';
  acStack_130[0xe5] = '\0';
  acStack_130[0xe6] = '\0';
  acStack_130[0xe7] = '\0';
  acStack_130[200] = '\0';
  acStack_130[0xc9] = '\0';
  acStack_130[0xca] = '\0';
  acStack_130[0xcb] = '\0';
  acStack_130[0xcc] = '\0';
  acStack_130[0xcd] = '\0';
  acStack_130[0xce] = '\0';
  acStack_130[0xcf] = '\0';
  acStack_130[0xd0] = '\0';
  acStack_130[0xd1] = '\0';
  acStack_130[0xd2] = '\0';
  acStack_130[0xd3] = '\0';
  acStack_130[0xd4] = '\0';
  acStack_130[0xd5] = '\0';
  acStack_130[0xd6] = '\0';
  acStack_130[0xd7] = '\0';
  acStack_130[0xb8] = '\0';
  acStack_130[0xb9] = '\0';
  acStack_130[0xba] = '\0';
  acStack_130[0xbb] = '\0';
  acStack_130[0xbc] = '\0';
  acStack_130[0xbd] = '\0';
  acStack_130[0xbe] = '\0';
  acStack_130[0xbf] = '\0';
  acStack_130[0xc0] = '\0';
  acStack_130[0xc1] = '\0';
  acStack_130[0xc2] = '\0';
  acStack_130[0xc3] = '\0';
  acStack_130[0xc4] = '\0';
  acStack_130[0xc5] = '\0';
  acStack_130[0xc6] = '\0';
  acStack_130[199] = '\0';
  acStack_130[0xa8] = '\0';
  acStack_130[0xa9] = '\0';
  acStack_130[0xaa] = '\0';
  acStack_130[0xab] = '\0';
  acStack_130[0xac] = '\0';
  acStack_130[0xad] = '\0';
  acStack_130[0xae] = '\0';
  acStack_130[0xaf] = '\0';
  acStack_130[0xb0] = '\0';
  acStack_130[0xb1] = '\0';
  acStack_130[0xb2] = '\0';
  acStack_130[0xb3] = '\0';
  acStack_130[0xb4] = '\0';
  acStack_130[0xb5] = '\0';
  acStack_130[0xb6] = '\0';
  acStack_130[0xb7] = '\0';
  acStack_130[0x98] = '\0';
  acStack_130[0x99] = '\0';
  acStack_130[0x9a] = '\0';
  acStack_130[0x9b] = '\0';
  acStack_130[0x9c] = '\0';
  acStack_130[0x9d] = '\0';
  acStack_130[0x9e] = '\0';
  acStack_130[0x9f] = '\0';
  acStack_130[0xa0] = '\0';
  acStack_130[0xa1] = '\0';
  acStack_130[0xa2] = '\0';
  acStack_130[0xa3] = '\0';
  acStack_130[0xa4] = '\0';
  acStack_130[0xa5] = '\0';
  acStack_130[0xa6] = '\0';
  acStack_130[0xa7] = '\0';
  acStack_130[0x88] = '\0';
  acStack_130[0x89] = '\0';
  acStack_130[0x8a] = '\0';
  acStack_130[0x8b] = '\0';
  acStack_130[0x8c] = '\0';
  acStack_130[0x8d] = '\0';
  acStack_130[0x8e] = '\0';
  acStack_130[0x8f] = '\0';
  acStack_130[0x90] = '\0';
  acStack_130[0x91] = '\0';
  acStack_130[0x92] = '\0';
  acStack_130[0x93] = '\0';
  acStack_130[0x94] = '\0';
  acStack_130[0x95] = '\0';
  acStack_130[0x96] = '\0';
  acStack_130[0x97] = '\0';
  acStack_130[0x78] = '\0';
  acStack_130[0x79] = '\0';
  acStack_130[0x7a] = '\0';
  acStack_130[0x7b] = '\0';
  acStack_130[0x7c] = '\0';
  acStack_130[0x7d] = '\0';
  acStack_130[0x7e] = '\0';
  acStack_130[0x7f] = '\0';
  acStack_130[0x80] = '\0';
  acStack_130[0x81] = '\0';
  acStack_130[0x82] = '\0';
  acStack_130[0x83] = '\0';
  acStack_130[0x84] = '\0';
  acStack_130[0x85] = '\0';
  acStack_130[0x86] = '\0';
  acStack_130[0x87] = '\0';
  acStack_130[0x68] = '\0';
  acStack_130[0x69] = '\0';
  acStack_130[0x6a] = '\0';
  acStack_130[0x6b] = '\0';
  acStack_130[0x6c] = '\0';
  acStack_130[0x6d] = '\0';
  acStack_130[0x6e] = '\0';
  acStack_130[0x6f] = '\0';
  acStack_130[0x70] = '\0';
  acStack_130[0x71] = '\0';
  acStack_130[0x72] = '\0';
  acStack_130[0x73] = '\0';
  acStack_130[0x74] = '\0';
  acStack_130[0x75] = '\0';
  acStack_130[0x76] = '\0';
  acStack_130[0x77] = '\0';
  acStack_130[0x58] = '\0';
  acStack_130[0x59] = '\0';
  acStack_130[0x5a] = '\0';
  acStack_130[0x5b] = '\0';
  acStack_130[0x5c] = '\0';
  acStack_130[0x5d] = '\0';
  acStack_130[0x5e] = '\0';
  acStack_130[0x5f] = '\0';
  acStack_130[0x60] = '\0';
  acStack_130[0x61] = '\0';
  acStack_130[0x62] = '\0';
  acStack_130[99] = '\0';
  acStack_130[100] = '\0';
  acStack_130[0x65] = '\0';
  acStack_130[0x66] = '\0';
  acStack_130[0x67] = '\0';
  acStack_130[0x48] = '\0';
  acStack_130[0x49] = '\0';
  acStack_130[0x4a] = '\0';
  acStack_130[0x4b] = '\0';
  acStack_130[0x4c] = '\0';
  acStack_130[0x4d] = '\0';
  acStack_130[0x4e] = '\0';
  acStack_130[0x4f] = '\0';
  acStack_130[0x50] = '\0';
  acStack_130[0x51] = '\0';
  acStack_130[0x52] = '\0';
  acStack_130[0x53] = '\0';
  acStack_130[0x54] = '\0';
  acStack_130[0x55] = '\0';
  acStack_130[0x56] = '\0';
  acStack_130[0x57] = '\0';
  acStack_130[0x38] = '\0';
  acStack_130[0x39] = '\0';
  acStack_130[0x3a] = '\0';
  acStack_130[0x3b] = '\0';
  acStack_130[0x3c] = '\0';
  acStack_130[0x3d] = '\0';
  acStack_130[0x3e] = '\0';
  acStack_130[0x3f] = '\0';
  acStack_130[0x40] = '\0';
  acStack_130[0x41] = '\0';
  acStack_130[0x42] = '\0';
  acStack_130[0x43] = '\0';
  acStack_130[0x44] = '\0';
  acStack_130[0x45] = '\0';
  acStack_130[0x46] = '\0';
  acStack_130[0x47] = '\0';
  acStack_130[0x28] = '\0';
  acStack_130[0x29] = '\0';
  acStack_130[0x2a] = '\0';
  acStack_130[0x2b] = '\0';
  acStack_130[0x2c] = '\0';
  acStack_130[0x2d] = '\0';
  acStack_130[0x2e] = '\0';
  acStack_130[0x2f] = '\0';
  acStack_130[0x30] = '\0';
  acStack_130[0x31] = '\0';
  acStack_130[0x32] = '\0';
  acStack_130[0x33] = '\0';
  acStack_130[0x34] = '\0';
  acStack_130[0x35] = '\0';
  acStack_130[0x36] = '\0';
  acStack_130[0x37] = '\0';
  acStack_130[0x18] = '\0';
  acStack_130[0x19] = '\0';
  acStack_130[0x1a] = '\0';
  acStack_130[0x1b] = '\0';
  acStack_130[0x1c] = '\0';
  acStack_130[0x1d] = '\0';
  acStack_130[0x1e] = '\0';
  acStack_130[0x1f] = '\0';
  acStack_130[0x20] = '\0';
  acStack_130[0x21] = '\0';
  acStack_130[0x22] = '\0';
  acStack_130[0x23] = '\0';
  acStack_130[0x24] = '\0';
  acStack_130[0x25] = '\0';
  acStack_130[0x26] = '\0';
  acStack_130[0x27] = '\0';
  acStack_130[8] = '\0';
  acStack_130[9] = '\0';
  acStack_130[10] = '\0';
  acStack_130[0xb] = '\0';
  acStack_130[0xc] = '\0';
  acStack_130[0xd] = '\0';
  acStack_130[0xe] = '\0';
  acStack_130[0xf] = '\0';
  acStack_130[0x10] = '\0';
  acStack_130[0x11] = '\0';
  acStack_130[0x12] = '\0';
  acStack_130[0x13] = '\0';
  acStack_130[0x14] = '\0';
  acStack_130[0x15] = '\0';
  acStack_130[0x16] = '\0';
  acStack_130[0x17] = '\0';
  local_138 = 0;
  acStack_130[0] = '\0';
  acStack_130[1] = '\0';
  acStack_130[2] = '\0';
  acStack_130[3] = '\0';
  acStack_130[4] = '\0';
  acStack_130[5] = '\0';
  acStack_130[6] = '\0';
  acStack_130[7] = '\0';
  if (0x10 < param_3) {
    lVar7 = puVar8[0xf];
    if (lVar7 == 0) {
      lVar7 = puVar8[1];
    }
    _dev_err(*puVar8,"%s: Invalid argument: total_phases=%d\n",lVar7);
    uVar12 = 0xffffffea;
    goto LAB_001088b4;
  }
  if (param_3 == 0) {
    uVar9 = 0;
    goto LAB_00108818;
  }
  uVar12 = 0;
  uVar9 = 0;
  uVar14 = (ulong)param_3;
  do {
    if ((0xf < uVar9) || (0xf < uVar12)) goto LAB_00108c50;
    if (0xff < uVar12 + (ulong)uVar9 * 0x10) goto LAB_00108c4c;
    uVar15 = (ulong)uVar9;
    bVar3 = *param_2;
    acStack_130[uVar12 + uVar15 * 0x10 + 8] = bVar3;
    if (0xf < uVar9) goto LAB_00108c4c;
    uVar1 = uVar12 + 1;
    acStack_130[uVar15 - 8] = acStack_130[uVar15 - 8] + '\x01';
    uVar12 = uVar1;
    if (uVar14 != 1) {
      bVar6 = (ulong)bVar3 + 1 != (ulong)param_2[1];
      if (bVar6) {
        uVar9 = uVar9 + 1;
      }
      uVar12 = 0;
      if (!bVar6) {
        uVar12 = uVar1;
      }
    }
    uVar14 = uVar14 - 1;
    param_2 = param_2 + 1;
  } while (uVar14 != 0);
  if (0xf < uVar9) {
LAB_00108800:
    uVar12 = 0xffffffea;
    goto LAB_001088b4;
  }
  if ((acStack_130[8] == '\0') && (uVar9 != 0)) {
    uVar15 = 0;
    bVar6 = false;
    uVar12 = 0x1f;
    uVar14 = 1;
    do {
      if (uVar12 == 0x10f) goto LAB_00108c50;
      cVar2 = acStack_130[uVar14 - 8];
      if (cVar2 != '\0') {
        if (uVar12 == 0x10f) goto LAB_00108c4c;
        if (acStack_130[uVar12 - 7] == '\x0f') {
LAB_00108908:
          bVar6 = true;
          uVar15 = uVar14 & 0xffffffff;
        }
        else if (cVar2 != '\x01') {
          if (0x100 < uVar12 - 0xe) goto LAB_00108c4c;
          if (acStack_130[uVar12 - 6] == '\x0f') goto LAB_00108908;
          if (cVar2 != '\x02') {
            if (0x100 < uVar12 - 0xd) goto LAB_00108c4c;
            if (acStack_130[uVar12 - 5] == '\x0f') goto LAB_00108908;
            if (cVar2 != '\x03') {
              if (0x100 < uVar12 - 0xc) goto LAB_00108c4c;
              if (acStack_130[uVar12 - 4] == '\x0f') goto LAB_00108908;
              if (cVar2 != '\x04') {
                if (0x100 < uVar12 - 0xb) goto LAB_00108c4c;
                if (acStack_130[uVar12 - 3] == '\x0f') goto LAB_00108908;
                if (cVar2 != '\x05') {
                  if (0x100 < uVar12 - 10) goto LAB_00108c4c;
                  if (acStack_130[uVar12 - 2] == '\x0f') goto LAB_00108908;
                  if (cVar2 != '\x06') {
                    if (0x100 < uVar12 - 9) goto LAB_00108c4c;
                    if (acStack_130[uVar12 - 1] == '\x0f') goto LAB_00108908;
                    if (cVar2 != '\a') {
                      if (0x100 < uVar12 - 8) goto LAB_00108c4c;
                      if (acStack_130[uVar12] == '\x0f') goto LAB_00108908;
                      if (cVar2 != '\b') {
                        if (0x100 < uVar12 - 7) goto LAB_00108c4c;
                        if (acStack_130[uVar12 + 1] == '\x0f') goto LAB_00108908;
                        if (cVar2 != '\t') {
                          if (0x100 < uVar12 - 6) goto LAB_00108c4c;
                          if (acStack_130[uVar12 + 2] == '\x0f') goto LAB_00108908;
                          if (cVar2 != '\n') {
                            if (0x100 < uVar12 - 5) goto LAB_00108c4c;
                            if (acStack_130[uVar12 + 3] == '\x0f') goto LAB_00108908;
                            if (cVar2 != '\v') {
                              if (0x100 < uVar12 - 4) goto LAB_00108c4c;
                              if (acStack_130[uVar12 + 4] == '\x0f') goto LAB_00108908;
                              if (cVar2 != '\f') {
                                if (0x100 < uVar12 - 3) goto LAB_00108c4c;
                                if (acStack_130[uVar12 + 5] == '\x0f') goto LAB_00108908;
                                if (cVar2 != '\r') {
                                  if (0x100 < uVar12 - 2) goto LAB_00108c4c;
                                  if (acStack_130[uVar12 + 6] == '\x0f') goto LAB_00108908;
                                  if (cVar2 != '\x0e') {
                                    if (0x100 < uVar12 - 1) goto LAB_00108c4c;
                                    if (acStack_130[uVar12 + 7] == '\x0f') goto LAB_00108908;
                                    if (cVar2 != '\x0f') {
                                      if (0x100 < uVar12) goto LAB_00108c4c;
                                      if (acStack_130[uVar12 + 8] == '\x0f') goto LAB_00108908;
                                      if (cVar2 != '\x10') goto LAB_00108c50;
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      bVar5 = uVar14 < uVar9;
      uVar12 = uVar12 + 0x10;
      uVar14 = uVar14 + 1;
    } while (bVar5);
    if (bVar6) {
      uVar13 = (uint)uVar15;
      if (0xf < uVar13) goto LAB_00108c50;
      lVar7 = (long)(int)uVar13;
      bVar3 = acStack_130[lVar7 + -8];
      uVar10 = (uint)bVar3 + (uint)(byte)local_138;
      if (0xf < uVar10) goto LAB_00108800;
      if ((byte)local_138 != 0) {
        uVar12 = 0;
        uVar14 = (ulong)bVar3 + lVar7 * 0x10;
        do {
          if ((0xf < uVar12) || (uVar15 = bVar3 + uVar12, 0xf < uVar15)) goto LAB_00108c50;
          if (0xff < uVar14) goto LAB_00108c4c;
          acStack_130[uVar14 + 8] = acStack_130[uVar12 + 8];
          if (uVar15 == 0xf) break;
          uVar12 = uVar12 + 1;
          uVar14 = uVar14 + 1;
        } while ((local_138 & 0xff) != uVar12);
      }
      local_138 = local_138 & 0xffffffffffffff00;
      if (0xf < uVar13) goto LAB_00108c4c;
      acStack_130[lVar7 + -8] = (char)uVar10;
    }
    if (-1 < (int)uVar9) goto LAB_00108818;
    uVar11 = 0;
LAB_0010886c:
    uVar9 = 0;
  }
  else {
LAB_00108818:
    uVar12 = 0;
    uVar13 = 0;
    uVar10 = 0;
    do {
      if (0xf < uVar9) goto LAB_00108c50;
      if (0xf < uVar12) goto LAB_00108c4c;
      bVar3 = acStack_130[uVar12 - 8];
      uVar11 = (uint)uVar12;
      if (bVar3 <= uVar13) {
        uVar11 = uVar10;
      }
      if (uVar13 <= bVar3) {
        uVar13 = (uint)bVar3;
      }
      uVar12 = uVar12 + 1;
      uVar10 = uVar11;
    } while ((ulong)uVar9 + 1 != uVar12);
    if (uVar13 * 3 < 4) goto LAB_0010886c;
    uVar9 = (uVar13 * 3 >> 2) - 1;
  }
  if ((0xf < uVar11) || (0xf < uVar9)) {
LAB_00108c50:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x108c54);
    (*pcVar4)();
  }
  if (0xff < (ulong)uVar9 + (ulong)uVar11 * 0x10) {
LAB_00108c4c:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x108c50);
    (*pcVar4)();
  }
  uVar12 = (ulong)(byte)acStack_130[(ulong)uVar9 + (ulong)uVar11 * 0x10 + 8];
  if (0xf < (byte)acStack_130[(ulong)uVar9 + (ulong)uVar11 * 0x10 + 8]) {
    lVar7 = puVar8[0xf];
    if (lVar7 == 0) {
      lVar7 = puVar8[1];
    }
    uVar12 = 0xffffffea;
    _dev_err(*puVar8,"%s: Invalid phase selected=%d\n",lVar7,0xffffffea);
  }
LAB_001088b4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// sdhci_msm_irq_affinity_notify @ 00108c5c size=384
// signature: undefined sdhci_msm_irq_affinity_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdhci_msm_irq_affinity_notify(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  
  puVar8 = *(undefined8 **)(param_1 + -8);
  if (puVar8 != (undefined8 *)0x0) {
    lVar6 = *(long *)(param_1 + -0x1a8);
    uVar1 = _find_first_bit(param_2,_nr_cpu_ids);
    *(undefined4 *)(*(long *)(param_1 + -8) + 0xc) = uVar1;
    if (*(int *)(lVar6 + 0x21c) != 2) {
      if (*(int *)(puVar8 + 1) != 0) {
        uVar5 = 0;
        puVar7 = (undefined8 *)*puVar8;
        do {
          lVar6 = puVar7[2];
          lVar4 = *(long *)(puVar7[4] + 0x2a8);
          if ((lVar4 != 0) && (*(char *)(puVar7[4] + 0x2b0) != '\0')) {
            ipc_log_string(lVar4,"%s: mask: 0x%08x type: %d vote: %u\n",
                           "sdhci_msm_update_qos_constraints",*puVar7,2,0x7fffffff);
          }
          iVar3 = 0;
          while (uVar2 = _find_next_bit(puVar7,_nr_cpu_ids,(long)iVar3), uVar2 < _nr_cpu_ids) {
            iVar3 = dev_pm_qos_update_request(lVar6,0x7fffffff);
            if (iVar3 < 0) {
              lVar6 = *(long *)(*(long *)(param_1 + -0x110) + 0x78);
              if (lVar6 == 0) {
                lVar6 = *(long *)(*(long *)(param_1 + -0x110) + 8);
              }
              _printk(&DAT_0010af44,lVar6,iVar3,uVar5);
              goto LAB_00108d60;
            }
            lVar6 = lVar6 + 0x50;
            iVar3 = uVar2 + 1;
          }
          *(undefined1 *)(puVar7 + 3) = 0;
          *(undefined1 *)((long)puVar7 + 0x29) = 1;
LAB_00108d60:
          uVar5 = uVar5 + 1;
          puVar7 = puVar7 + 6;
        } while (uVar5 < *(uint *)(puVar8 + 1));
      }
      sdhci_msm_vote_pmqos
                (*(undefined8 *)(param_1 + -0x110),*(undefined4 *)(*(long *)(param_1 + -8) + 0xc));
    }
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_irq_affinity_release @ 00108de0 size=4
// signature: undefined sdhci_msm_irq_affinity_release(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_irq_affinity_release(void)

{
  return;
}



//------------------------------------------------------------
// sdhci_msm_update_qos_constraints @ 00108de4 size=248
// signature: undefined sdhci_msm_update_qos_constraints(void)
// callers: [sdhci_msm_qos_init, sdhci_msm_vote_pmqos]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sdhci_msm_update_qos_constraints(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  
  lVar5 = param_1[2];
  if (param_2 == 2) {
    uVar6 = 0x7fffffff;
  }
  else {
    uVar6 = *(uint *)(param_1[1] + (ulong)param_2 * 4);
    if (uVar6 == *(byte *)((long)param_1 + 0x29)) {
      return 0;
    }
  }
  lVar2 = *(long *)(param_1[4] + 0x2a8);
  if ((lVar2 != 0) && (*(char *)(param_1[4] + 0x2b0) != '\0')) {
    ipc_log_string(lVar2,"%s: mask: 0x%08x type: %d vote: %u\n","sdhci_msm_update_qos_constraints",
                   *param_1,param_2,uVar6);
  }
  iVar4 = 0;
  while( true ) {
    uVar1 = _find_next_bit(param_1,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar1) {
      *(bool *)(param_1 + 3) = param_2 != 2;
      *(bool *)((long)param_1 + 0x29) = uVar6 != 0;
      return 0;
    }
    uVar3 = dev_pm_qos_update_request(lVar5,uVar6);
    if ((int)uVar3 < 0) break;
    lVar5 = lVar5 + 0x50;
    iVar4 = uVar1 + 1;
  }
  return uVar3;
}



//------------------------------------------------------------
// sdhci_msm_vote_pmqos @ 00108edc size=244
// signature: undefined sdhci_msm_vote_pmqos(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_irq_affinity_notify]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sdhci_msm_vote_pmqos(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  
  if (-1 < (int)param_2) {
    plVar6 = *(long **)(param_1 + 0xe60);
    lVar7 = *plVar6;
    uVar1 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
    if ((param_2 <= uVar1) && ((int)plVar6[1] != 0)) {
      iVar3 = 0;
      puVar4 = (ulong *)(lVar7 + ((ulong)(param_2 >> 3) & 0x1ffffff8));
      do {
        if ((*puVar4 & 1L << ((ulong)param_2 & 0x3f)) != 0) {
          lVar5 = *plVar6;
          lVar7 = lVar5 + (long)iVar3 * 0x30;
          if (lVar7 == 0) {
            return;
          }
          if (*(char *)(lVar5 + (long)iVar3 * 0x30 + 0x18) != '\0') {
            return;
          }
          iVar2 = sdhci_msm_update_qos_constraints(lVar7,0);
          if (iVar2 == 0) {
            return;
          }
          _dev_err(**(long **)(lVar5 + (long)iVar3 * 0x30 + 0x20) + 0x10,"%s: update qos - failed\n"
                   ,"sdhci_msm_vote_pmqos");
          return;
        }
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 6;
      } while ((int)plVar6[1] != iVar3);
    }
  }
  return;
}



//------------------------------------------------------------
// show_sdhci_msm_pm_qos @ 00108fd4 size=60
// signature: undefined show_sdhci_msm_pm_qos(void)
// callers: []
//------------------------------------------------------------

long show_sdhci_msm_pm_qos(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010aa1a,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x790))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// store_sdhci_msm_pm_qos @ 00109014 size=156
// signature: undefined store_sdhci_msm_pm_qos(void)
// callers: []
//------------------------------------------------------------

undefined8
store_sdhci_msm_pm_qos(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x790) = local_3c;
    _dev_info(param_1,"set pm qos work delay (%u)\n");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sdhci_msm_cqe_enable @ 001090b4 size=156
// signature: undefined sdhci_msm_cqe_enable(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_cqe_enable(long param_1)

{
  uint uVar1;
  
  sdhci_cqe_enable();
  if ((*(byte *)(*(long *)(param_1 + 0xd58) + 0x3eb) >> 3 & 1) != 0) {
    uVar1 = readl(*(long *)(param_1 + 0xcd0) + 0x1000);
    writel(uVar1 | 0x7000,*(long *)(param_1 + 0xcd0) + 0x1000);
    uVar1 = readl(*(long *)(param_1 + 0xcd0) + 0x1000);
    __const_udelay(0x53e3);
    writel(uVar1 | 0xd807100,*(long *)(param_1 + 0xcd0) + 0x1000);
    __const_udelay(0x53e3);
    sdhci_msm_ice_wait_bist_status(param_1 + 0xcc0);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_cqe_disable @ 00109154 size=328
// signature: undefined sdhci_msm_cqe_disable(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_cqe_disable(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  lVar1 = param_1 + 0x740;
  if ((*(byte *)(param_1 + 0xa35) >> 4 & 1) != 0) {
    *(undefined4 *)(param_1 + 0xb20) = 0x10;
  }
  uVar3 = _raw_spin_lock_irqsave(param_1 + 0xa30);
  pcVar4 = (code *)**(undefined8 **)(param_1 + 0x780);
  if (pcVar4 == (code *)0x0) {
    uVar2 = readl(*(long *)(param_1 + 0x758) + 0x34);
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x39faa4ed) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10923c);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(lVar1,0x34);
  }
  pcVar4 = *(code **)(*(long *)(param_1 + 0x780) + 0x18);
  if (pcVar4 == (code *)0x0) {
    writel(uVar2 | 1,*(long *)(param_1 + 0x758) + 0x34);
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x109268);
      (*pcVar4)();
    }
    (*pcVar4)(lVar1,uVar2 | 1,0x34);
  }
  pcVar4 = *(code **)(*(long *)(param_1 + 0x780) + 0x18);
  if (pcVar4 == (code *)0x0) {
    writel(1,*(long *)(param_1 + 0x758) + 0x30);
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x53cf0300) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x109294);
      (*pcVar4)();
    }
    (*pcVar4)(lVar1,1,0x30);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0xa30,uVar3);
  sdhci_cqe_disable(param_1,param_2 & 1);
  return;
}



//------------------------------------------------------------
// sdhci_msm_program_key @ 001092a0 size=412
// signature: undefined sdhci_msm_program_key(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_program_key(long param_1,undefined8 *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  if (*(char *)((long)param_2 + 0x43) < '\0') {
    pcVar1 = (char *)(*(long *)(param_1 + 200) + (ulong)*(byte *)((long)param_2 + 0x41) * 4);
    cVar2 = *pcVar1;
    cVar3 = pcVar1[2];
    if (cVar2 == '\0' && cVar3 == '\x03') {
      uVar9 = (uint)*param_2;
      uVar9 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
      uVar10 = (uint)((ulong)*param_2 >> 0x20);
      uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
      local_70._0_4_ = (uint)param_2[1];
      local_70._4_4_ = (uint)((ulong)param_2[1] >> 0x20);
      local_78 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
      local_68._0_4_ = (uint)param_2[2];
      local_68._4_4_ = (uint)((ulong)param_2[2] >> 0x20);
      uVar9 = ((uint)local_70 & 0xff00ff00) >> 8 | ((uint)local_70 & 0xff00ff) << 8;
      uVar10 = (local_70._4_4_ & 0xff00ff00) >> 8 | (local_70._4_4_ & 0xff00ff) << 8;
      local_70 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
      uVar9 = ((uint)local_68 & 0xff00ff00) >> 8 | ((uint)local_68 & 0xff00ff) << 8;
      local_60._0_4_ = (uint)param_2[3];
      local_60._4_4_ = (uint)((ulong)param_2[3] >> 0x20);
      uVar10 = (local_68._4_4_ & 0xff00ff00) >> 8 | (local_68._4_4_ & 0xff00ff) << 8;
      local_58._0_4_ = (uint)param_2[4];
      local_58._4_4_ = (uint)((ulong)param_2[4] >> 0x20);
      uVar4 = ((uint)local_60 & 0xff00ff00) >> 8 | ((uint)local_60 & 0xff00ff) << 8;
      local_68 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
      uVar9 = (local_60._4_4_ & 0xff00ff00) >> 8 | (local_60._4_4_ & 0xff00ff) << 8;
      uVar10 = ((uint)local_58 & 0xff00ff00) >> 8 | ((uint)local_58 & 0xff00ff) << 8;
      uVar5 = (local_58._4_4_ & 0xff00ff00) >> 8 | (local_58._4_4_ & 0xff00ff) << 8;
      local_60 = CONCAT44(uVar9 >> 0x10 | uVar9 << 0x10,uVar4 >> 0x10 | uVar4 << 0x10);
      local_50._0_4_ = (uint)param_2[5];
      local_50._4_4_ = (uint)((ulong)param_2[5] >> 0x20);
      local_58 = CONCAT44(uVar5 >> 0x10 | uVar5 << 0x10,uVar10 >> 0x10 | uVar10 << 0x10);
      local_40._0_4_ = (uint)param_2[7];
      local_40._4_4_ = (uint)((ulong)param_2[7] >> 0x20);
      uVar9 = ((uint)local_50 & 0xff00ff00) >> 8 | ((uint)local_50 & 0xff00ff) << 8;
      uVar10 = (local_50._4_4_ & 0xff00ff00) >> 8 | (local_50._4_4_ & 0xff00ff) << 8;
      local_48._0_4_ = (uint)param_2[6];
      local_48._4_4_ = (uint)((ulong)param_2[6] >> 0x20);
      local_50 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
      uVar9 = ((uint)local_40 & 0xff00ff00) >> 8 | ((uint)local_40 & 0xff00ff) << 8;
      uVar10 = (local_40._4_4_ & 0xff00ff00) >> 8 | (local_40._4_4_ & 0xff00ff) << 8;
      uVar4 = ((uint)local_48 & 0xff00ff00) >> 8 | ((uint)local_48 & 0xff00ff) << 8;
      uVar5 = (local_48._4_4_ & 0xff00ff00) >> 8 | (local_48._4_4_ & 0xff00ff) << 8;
      local_40 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
      local_48 = CONCAT44(uVar5 >> 0x10 | uVar5 << 0x10,uVar4 >> 0x10 | uVar4 << 0x10);
      uVar8 = qcom_scm_ice_set_key(param_3,&local_78,0x40,3,*(undefined1 *)(param_2 + 8));
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
    }
    else {
      uVar8 = **(undefined8 **)(param_1 + 0x10);
      iVar7 = ___ratelimit(sdhci_msm_program_key__rs,"sdhci_msm_program_key");
      if (iVar7 == 0) {
        uVar8 = 0xffffffea;
      }
      else {
        _dev_err(uVar8,"Unhandled crypto capability; algorithm_id=%d, key_size=%d\n",cVar2,cVar3);
        uVar8 = 0xffffffea;
      }
    }
  }
  else {
    uVar8 = qcom_scm_ice_invalidate_key(param_3);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_enhanced_strobe_mask @ 00109440 size=112
// signature: undefined sdhci_msm_enhanced_strobe_mask(void)
// callers: []
//------------------------------------------------------------

void sdhci_msm_enhanced_strobe_mask(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  if (*(char *)(param_1 + 0x423) != '\0') {
    lVar3 = *(long *)(param_1 + 0xdb0);
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x758) + (ulong)*(uint *)(lVar3 + 0x60));
    uVar2 = 0x2000;
    if ((param_2 & 1) == 0) {
      uVar2 = 0;
    }
    writel_relaxed(uVar1 & 0xffffdfff | uVar2,
                   *(long *)(param_1 + 0x758) + (ulong)*(uint *)(lVar3 + 0x60));
  }
  return;
}



//------------------------------------------------------------
// sdhci_msm_ice_wait_bist_status @ 001094b0 size=180
// signature: undefined sdhci_msm_ice_wait_bist_status(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_cqe_enable]
//------------------------------------------------------------

undefined8 sdhci_msm_ice_wait_bist_status(long param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = ktime_get();
  uVar2 = readl(*(long *)(param_1 + 0x10) + 0x70);
  if ((uVar2 >> 0x1c & 0xf) != 0) {
    do {
      lVar3 = ktime_get();
      if (lVar1 + 5000000 < lVar3) {
        uVar2 = readl(*(long *)(param_1 + 0x10) + 0x70);
        if ((uVar2 >> 0x1c & 0xf) == 0) {
          return 0;
        }
        _dev_err(**(undefined8 **)(param_1 + 0x98),
                 "Timed out waiting for ICE self-test to complete\n");
        return 0xffffff92;
      }
      usleep_range_state(0xd,0x32,2);
      Yield();
      uVar2 = readl(*(long *)(param_1 + 0x10) + 0x70);
    } while ((uVar2 >> 0x1c & 0xf) != 0);
  }
  return 0;
}



//------------------------------------------------------------
// mmc_sleep_busy_cb @ 00109568 size=92
// signature: undefined mmc_sleep_busy_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 mmc_sleep_busy_cb(long param_1,undefined8 param_2)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 0x3a0) + 0x58);
  if (*(int *)(pcVar2 + -4) != 0x138bf33d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10959c);
    (*pcVar2)();
  }
  iVar1 = (*pcVar2)();
  *(bool *)param_2 = iVar1 != 0;
  return 0;
}



//------------------------------------------------------------
// sdhci_msm_wrapper_suspend_late @ 001095c8 size=136
// signature: undefined sdhci_msm_wrapper_suspend_late(void)
// callers: []
//------------------------------------------------------------

undefined8 sdhci_msm_wrapper_suspend_late(long param_1)

{
  long lVar1;
  
  lVar1 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"non-removable",0);
  if ((lVar1 == 0) || (is_bootdevice_sdhci != '\0')) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x828);
    if ((lVar1 != 0) && (*(char *)(*(long *)(param_1 + 0x98) + 0x830) != '\0')) {
      ipc_log_string(lVar1,"%s: Enter\n","sdhci_msm_suspend_late");
    }
  }
  else {
    _dev_info(param_1,"SDHCI is not boot dev.\n");
  }
  return 0;
}



//------------------------------------------------------------
// sdhci_msm_runtime_suspend @ 00109654 size=428
// signature: undefined sdhci_msm_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sdhci_msm_runtime_suspend(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar7 = *(long *)(lVar5 + 0x720);
  uVar3 = _raw_spin_lock_irqsave(lVar5 + 0x2f0);
  *(undefined1 *)(lVar5 + 0x313) = 1;
  _raw_spin_unlock_irqrestore(lVar5 + 0x2f0,uVar3);
  if ((*(long *)(lVar5 + 0x828) != 0) && (*(char *)(lVar5 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(lVar5 + 0x828),"%s: Enter\n","sdhci_msm_runtime_suspend");
  }
  if (((lVar7 != 0) && (puVar9 = *(undefined8 **)(lVar5 + 0x720), puVar9 != (undefined8 *)0x0)) &&
     (*(int *)(puVar9 + 1) != 0)) {
    uVar6 = 0;
    puVar8 = (undefined8 *)*puVar9;
    do {
      if (*(char *)(puVar8 + 5) == '\0') break;
      lVar7 = puVar8[2];
      lVar4 = *(long *)(puVar8[4] + 0x2a8);
      if ((lVar4 != 0) && (*(char *)(puVar8[4] + 0x2b0) != '\0')) {
        ipc_log_string(lVar4,"%s: mask: 0x%08x type: %d vote: %u\n",
                       "sdhci_msm_update_qos_constraints",*puVar8,2,0x7fffffff);
      }
      iVar2 = 0;
      while (uVar1 = _find_next_bit(puVar8,_nr_cpu_ids,(long)iVar2), uVar1 < _nr_cpu_ids) {
        iVar2 = dev_pm_qos_update_request(lVar7,0x7fffffff);
        if (iVar2 < 0) {
          _dev_err(*(long *)(lVar5 + 0x580) + 0x10,"Failed (%d) removing qos vote(%d)\n",iVar2,uVar6
                  );
          goto LAB_00109774;
        }
        lVar7 = lVar7 + 0x50;
        iVar2 = uVar1 + 1;
      }
      *(undefined1 *)(puVar8 + 3) = 0;
      *(undefined1 *)((long)puVar8 + 0x29) = 1;
LAB_00109774:
      uVar6 = uVar6 + 1;
      puVar8 = puVar8 + 6;
    } while (uVar6 < *(uint *)(puVar9 + 1));
  }
  sdhci_msm_registers_save(lVar5);
  dev_pm_opp_set_rate(param_1,0);
  clk_bulk_disable(5,lVar5 + 0x5b8);
  clk_bulk_unprepare(5,lVar5 + 0x5b8);
  return 0;
}



//------------------------------------------------------------
// sdhci_msm_runtime_resume @ 00109804 size=540
// signature: undefined sdhci_msm_runtime_resume(void)
// callers: []
//------------------------------------------------------------

int sdhci_msm_runtime_resume(long param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar7 = *(long *)(lVar5 + 0x720);
  if ((*(long *)(lVar5 + 0x828) != 0) && (*(char *)(lVar5 + 0x830) != '\0')) {
    ipc_log_string(*(long *)(lVar5 + 0x828),"%s: Enter\n","sdhci_msm_runtime_resume");
  }
  lVar6 = lVar5 + 0x5b8;
  iVar2 = clk_bulk_prepare(5,lVar6);
  if (iVar2 == 0) {
    iVar2 = clk_bulk_enable(5,lVar6);
    if (iVar2 == 0) {
      sdhci_msm_registers_restore(lVar5);
      lVar6 = *(long *)(lVar5 + 0x670);
      if (((*(char *)(lVar5 + 0x631) != '\0') ||
          ((*(byte *)(*(long *)(lVar5 + 0x48) + 0x423) & 1) != 0)) &&
         (*(char *)(*(long *)(lVar5 + 0x48) + 0x420) == '\n')) {
        uVar3 = readl_relaxed(*(long *)(lVar5 + 0x18) + (ulong)*(uint *)(lVar6 + 0x68));
        writel_relaxed(uVar3 | 2,*(long *)(lVar5 + 0x18) + (ulong)*(uint *)(lVar6 + 0x68));
        DataSynchronizationBarrier(3,2,0);
        __const_udelay(0x218e);
        uVar3 = readl_relaxed(*(long *)(lVar5 + 0x18) + (ulong)*(uint *)(lVar6 + 0x68));
        writel_relaxed(uVar3 & 0xfffffffd,*(long *)(lVar5 + 0x18) + (ulong)*(uint *)(lVar6 + 0x68));
      }
      if ((*(char *)(lVar5 + 0x661) != '\0') && (*(long *)(lVar5 + 0x608) != 0)) {
        bVar1 = *(byte *)(*(long *)(lVar5 + 0x48) + 0x420);
        if ((((bVar1 == 5) && ((*(byte *)(lVar5 + 0x2f4) >> 4 & 1) != 0)) ||
            ((((100000000 < *(uint *)(lVar5 + 0x30c) && (bVar1 < 0xb)) &&
              ((1 << (ulong)(bVar1 & 0x1f) & 0x640U) != 0)) &&
             (*(char *)(*(long *)(lVar5 + 0x48) + 0x423) == '\0')))) &&
           (iVar2 = msm_init_cm_dll(lVar5,0), iVar2 == 0)) {
          msm_config_cm_dll_phase(lVar5,*(undefined1 *)(lVar5 + 0x633));
        }
      }
      dev_pm_opp_set_rate(param_1,*(undefined8 *)(lVar5 + 0x608));
      if (lVar7 != 0) {
        sdhci_msm_vote_pmqos
                  (*(undefined8 *)(lVar5 + 0x618),*(undefined4 *)(*(long *)(lVar5 + 0x720) + 0xc));
      }
      if (((*(byte *)(*(long *)(lVar5 + 0x618) + 0x3eb) >> 3 & 1) == 0) ||
         (iVar2 = sdhci_msm_ice_wait_bist_status(lVar5 + 0x580), iVar2 == 0)) {
        uVar4 = _raw_spin_lock_irqsave(lVar5 + 0x2f0);
        *(undefined1 *)(lVar5 + 0x313) = 0;
        _raw_spin_unlock_irqrestore(lVar5 + 0x2f0,uVar4);
        return 0;
      }
      return iVar2;
    }
    clk_bulk_unprepare(5,lVar6);
  }
  _dev_err(param_1,"Failed to enable clocks %d\n",iVar2);
  sdhci_msm_bus_get_and_set_vote(lVar5,0);
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00109a38 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&sdhci_msm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00109a68 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&sdhci_msm_driver);
  return;
}



//------------------------------------------------------------
// crypto_qti_disable @ 0010f000 size=1
// signature: undefined crypto_qti_disable(void)
// callers: [sdhci_msm_ice_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_dumpregs @ 0010f008 size=1
// signature: undefined sdhci_dumpregs(void)
// callers: [sdhci_msm_cqe_sdhci_dumpregs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_dumpregs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010f010 size=1
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
// platform_driver_unregister @ 0010f018 size=1
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
// log_read_mmio @ 0010f020 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readw_relaxed, readl_relaxed, readb, readw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010f028 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readw_relaxed, readl_relaxed, readb, readw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010f030 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writew, writeb, writew_relaxed, writeb_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010f038 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writew, writeb, writew_relaxed, writeb_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010f040 size=1
// signature: undefined of_find_property(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove, sdhci_msm_wrapper_suspend_late]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 0010f048 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 0010f050 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010f058 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [sdhci_msm_bus_register, sdhci_msm_qos_init, sdhci_msm_probe, sdhci_msm_dt_get_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010f060 size=1
// signature: undefined kfree(void)
// callers: [sdhci_msm_qos_init, sdhci_msm_mmc_resume, sdhci_msm_probe, sdhci_msm_mmc_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 0010f068 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_pltfm_init @ 0010f070 size=1
// signature: undefined sdhci_pltfm_init(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_pltfm_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0010f078 size=1
// signature: undefined sysfs_create_group(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010f080 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 0010f088 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_of_parse @ 0010f090 size=1
// signature: undefined mmc_of_parse(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_of_parse(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_pltfm_free @ 0010f098 size=1
// signature: undefined sdhci_pltfm_free(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_pltfm_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_alias_get_id @ 0010f0a0 size=1
// signature: undefined of_alias_get_id(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_alias_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 0010f0a8 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_get_property @ 0010f0b0 size=1
// signature: undefined sdhci_get_property(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 0010f0b8 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010f0c0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [sdhci_msm_bus_register, sdhci_msm_dt_parse_vreg_info, sdhci_msm_probe, sdhci_msm_dt_get_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0010f0c8 size=1
// signature: undefined of_get_property(void)
// callers: [sdhci_msm_bus_register, sdhci_msm_dt_parse_vreg_info, sdhci_msm_probe, sdhci_msm_dt_get_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 0010f0d0 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010f0d8 size=1
// signature: undefined devm_clk_get(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_find_icc_paths @ 0010f0e0 size=1
// signature: undefined dev_pm_opp_of_find_icc_paths(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_find_icc_paths(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_set_config @ 0010f0e8 size=1
// signature: undefined dev_pm_opp_set_config(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_set_config(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_add_table @ 0010f0f0 size=1
// signature: undefined dev_pm_opp_of_add_table(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_add_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_set_rate @ 0010f0f8 size=1
// signature: undefined dev_pm_opp_set_rate(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_runtime_suspend, sdhci_msm_probe, msm_set_clock_rate_for_bus_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 0010f100 size=1
// signature: undefined clk_set_rate(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_prepare @ 0010f108 size=1
// signature: undefined clk_bulk_prepare(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_enable @ 0010f110 size=1
// signature: undefined clk_bulk_enable(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_unprepare @ 0010f118 size=1
// signature: undefined clk_bulk_unprepare(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_runtime_suspend, sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_of_remove_table @ 0010f120 size=1
// signature: undefined dev_pm_opp_of_remove_table(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_of_remove_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_clear_config @ 0010f128 size=1
// signature: undefined dev_pm_opp_clear_config(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_clear_config(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0010f130 size=1
// signature: undefined clk_prepare(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0010f138 size=1
// signature: undefined clk_enable(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0010f140 size=1
// signature: undefined _dev_warn(void)
// callers: [sdhci_msm_start_signal_voltage_switch, sdhci_msm_check_power_status, sdhci_msm_dt_parse_vreg_info, sdhci_msm_probe, sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010f148 size=1
// signature: undefined _dev_err(void)
// callers: [sdhci_msm_program_key, msm_config_cm_dll_phase, sdhci_msm_ice_wait_bist_status, sdhci_msm_handle_pwr_irq, msm_find_most_appropriate_phase, sdhci_msm_runtime_resume, sdhci_msm_bus_register, sdhci_msm_runtime_suspend, sdhci_msm_qos_init, msm_init_cm_dll, sdhci_msm_vote_pmqos, sdhci_msm_probe, sdhci_msm_dt_get_array, sdhci_msm_hw_reset, sdhci_msm_vreg_init, sdhci_msm_remove, sdhci_msm_setup_pwr_irq, sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0010f150 size=1
// signature: undefined clk_disable(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0010f158 size=1
// signature: undefined clk_unprepare(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 0010f160 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 0010f168 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [sdhci_msm_probe, sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0010f170 size=1
// signature: undefined devm_ioremap(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_regulator_get_supply @ 0010f178 size=1
// signature: undefined mmc_regulator_get_supply(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_regulator_get_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_supported_voltage @ 0010f180 size=1
// signature: undefined regulator_is_supported_voltage(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_supported_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010f188 size=1
// signature: undefined _dev_info(void)
// callers: [sdhci_msm_bus_register, sdhci_msm_dt_parse_vreg_info, sdhci_msm_probe, store_sdhci_msm_pm_qos, sdhci_msm_wrapper_suspend_late, sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_clk_set_flags @ 0010f190 size=1
// signature: undefined qcom_clk_set_flags(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_clk_set_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_disable @ 0010f198 size=1
// signature: undefined clk_bulk_disable(void)
// callers: [sdhci_msm_runtime_suspend, sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010f1a0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_add_host @ 0010f1a8 size=1
// signature: undefined sdhci_add_host(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_add_host(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0010f1b0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0010f1b8 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [sdhci_msm_probe, sdhci_msm_setup_pm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010f1c0 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010f1c8 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// android_rvh_probe_register @ 0010f1d8 size=1
// signature: undefined android_rvh_probe_register(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void android_rvh_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 0010f1e8 size=1
// signature: undefined register_pm_notifier(void)
// callers: [sdhci_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 0010f1f0 size=1
// signature: undefined icc_put(void)
// callers: [sdhci_msm_probe, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010f1f8 size=1
// signature: undefined _printk(void)
// callers: [sdhci_msm_irq_affinity_notify, sdhci_msm_hc_select_mode, msm_set_clock_rate_for_bus_mode, sdhci_msm_set_uhs_signaling, sdhci_msm_registers_restore, sdhci_msm_handle_pwr_irq, sdhci_msm_set_vdd_io_vol, sdhci_msm_setup_vreg, sdhci_msm_dump_vendor_regs, msm_init_cm_dll, sdhci_msm_mmc_resume, sdhci_msm_probe, sdhci_msm_dump_pwr_ctrl_regs, sdhci_msm_mmc_suspend, sdhci_msm_vreg_init, sdhci_msm_bus_get_and_set_vote, sdhci_msm_init_sysfs_gating_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010f200 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [sdhci_msm_program_key, sdhci_msm_dt_parse_vreg_info, sdhci_msm_cqe_irq, sdhci_msm_execute_tuning, dbg_state_store, sdhci_msm_handle_pwr_irq, msm_find_most_appropriate_phase, sdhci_msm_bus_register, sdhci_msm_setup_vreg, sdhci_msm_dump_vendor_regs, sdhci_msm_qos_init, sdhci_msm_mmc_resume, sdhci_msm_check_power_status, sdhci_msm_probe, store_sdhci_msm_pm_qos, sdhci_msm_mmc_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 0010f208 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_remove_host @ 0010f210 size=1
// signature: undefined sdhci_remove_host(void)
// callers: [sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_remove_host(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010f218 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010f220 size=1
// signature: undefined msleep(void)
// callers: [sdhci_msm_mmc_resume, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010f230 size=1
// signature: undefined ipc_log_string(void)
// callers: [sdhci_msm_irq_affinity_notify, sdhci_msm_cqe_irq, sdhci_msm_execute_tuning, msm_set_clock_rate_for_bus_mode, sdhci_msm_registers_restore, sdhci_msm_handle_pwr_irq, sdhci_msm_set_vdd_io_vol, sdhci_msm_update_qos_constraints, sdhci_msm_runtime_resume, sdhci_msm_runtime_suspend, sdhci_msm_setup_vreg, sdhci_msm_registers_save, sdhci_msm_check_power_status, sdhci_msm_hw_reset, sdhci_msm_remove, sdhci_msm_wrapper_suspend_late]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0010f238 size=1
// signature: undefined _find_next_bit(void)
// callers: [sdhci_msm_update_qos_constraints, sdhci_msm_runtime_suspend, sdhci_msm_qos_init, sdhci_msm_irq_affinity_notify, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_update_request @ 0010f240 size=1
// signature: undefined dev_pm_qos_update_request(void)
// callers: [sdhci_msm_update_qos_constraints, sdhci_msm_runtime_suspend, sdhci_msm_irq_affinity_notify, sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_remove_request @ 0010f248 size=1
// signature: undefined dev_pm_qos_remove_request(void)
// callers: [sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0010f250 size=1
// signature: undefined destroy_workqueue(void)
// callers: [sdhci_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 0010f260 size=1
// signature: undefined reset_control_assert(void)
// callers: [sdhci_msm_gcc_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010f268 size=1
// signature: undefined usleep_range_state(void)
// callers: [sdhci_msm_start_signal_voltage_switch, msm_init_cm_dll, sdhci_msm_mmc_resume, sdhci_msm_gcc_reset, sdhci_msm_hc_select_mode, sdhci_msm_set_uhs_signaling, sdhci_msm_ice_wait_bist_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 0010f270 size=1
// signature: undefined reset_control_deassert(void)
// callers: [sdhci_msm_gcc_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 0010f278 size=1
// signature: undefined dev_err_probe(void)
// callers: [sdhci_msm_gcc_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 0010f280 size=1
// signature: undefined devm_regulator_get(void)
// callers: [sdhci_msm_vreg_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 0010f288 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [sdhci_msm_vreg_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 0010f290 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [sdhci_msm_setup_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010f298 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [sdhci_msm_setup_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010f2a0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [sdhci_msm_hibernation_notifier, sdhci_msm_setup_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010f2a8 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [sdhci_msm_setup_pm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010f2b0 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [sdhci_msm_setup_pm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0010f2b8 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [sdhci_msm_setup_pm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_send_tuning @ 0010f2c0 size=1
// signature: undefined mmc_send_tuning(void)
// callers: [sdhci_msm_execute_tuning]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_send_tuning(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010f2d0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010f2d8 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010f2e0 size=1
// signature: undefined __kmalloc(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_subset @ 0010f2f0 size=1
// signature: undefined __bitmap_subset(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_subset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0010f2f8 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0010f300 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_apply_affinity_hint @ 0010f308 size=1
// signature: undefined __irq_apply_affinity_hint(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_apply_affinity_hint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_affinity_notifier @ 0010f310 size=1
// signature: undefined irq_set_affinity_notifier(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_affinity_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 0010f318 size=1
// signature: undefined __bitmap_weight(void)
// callers: [sdhci_msm_qos_init, sdhci_msm_vote_pmqos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 0010f320 size=1
// signature: undefined get_cpu_device(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_request @ 0010f328 size=1
// signature: undefined dev_pm_qos_add_request(void)
// callers: [sdhci_msm_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 0010f330 size=1
// signature: undefined _find_first_bit(void)
// callers: [sdhci_msm_qos_init, sdhci_msm_irq_affinity_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 0010f338 size=1
// signature: undefined device_create_file(void)
// callers: [sdhci_msm_init_sysfs_gating_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_setup_host @ 0010f340 size=1
// signature: undefined sdhci_setup_host(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_setup_host(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cqhci_pltfm_init @ 0010f348 size=1
// signature: undefined cqhci_pltfm_init(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cqhci_pltfm_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cqhci_init @ 0010f350 size=1
// signature: undefined cqhci_init(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cqhci_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sdhci_add_host @ 0010f358 size=1
// signature: undefined __sdhci_add_host(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sdhci_add_host(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_cleanup_host @ 0010f360 size=1
// signature: undefined sdhci_cleanup_host(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_cleanup_host(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_ice_available @ 0010f368 size=1
// signature: undefined qcom_scm_ice_available(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_ice_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0010f370 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [sdhci_msm_cqe_add_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_get_ext_csd @ 0010f378 size=1
// signature: undefined mmc_get_ext_csd(void)
// callers: [sdhci_msm_mmc_resume, sdhci_msm_mmc_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_get_ext_csd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_retune_hold @ 0010f388 size=1
// signature: undefined mmc_retune_hold(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_retune_hold(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_prepare_busy_cmd @ 0010f390 size=1
// signature: undefined mmc_prepare_busy_cmd(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_prepare_busy_cmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_wait_for_cmd @ 0010f398 size=1
// signature: undefined mmc_wait_for_cmd(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_wait_for_cmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_retune_release @ 0010f3a0 size=1
// signature: undefined mmc_retune_release(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_retune_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_select_card @ 0010f3a8 size=1
// signature: undefined mmc_select_card(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_select_card(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mmc_poll_for_busy @ 0010f3b0 size=1
// signature: undefined __mmc_poll_for_busy(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mmc_poll_for_busy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_set_bus_width @ 0010f3b8 size=1
// signature: undefined mmc_set_bus_width(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_set_bus_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_set_timing @ 0010f3c0 size=1
// signature: undefined mmc_set_timing(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_set_timing(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_set_clock @ 0010f3c8 size=1
// signature: undefined mmc_set_clock(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_set_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_set_bus_mode @ 0010f3d0 size=1
// signature: undefined mmc_set_bus_mode(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_set_bus_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_execute_tuning @ 0010f3d8 size=1
// signature: undefined mmc_execute_tuning(void)
// callers: [sdhci_msm_mmc_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_execute_tuning(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_get_card @ 0010f3e0 size=1
// signature: undefined mmc_get_card(void)
// callers: [sdhci_msm_hibernation_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_get_card(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_put_card @ 0010f3e8 size=1
// signature: undefined mmc_put_card(void)
// callers: [sdhci_msm_hibernation_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_put_card(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 0010f3f0 size=1
// signature: undefined devm_free_irq(void)
// callers: [sdhci_msm_hibernation_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0010f3f8 size=1
// signature: undefined icc_set_bw(void)
// callers: [sdhci_msm_bus_get_and_set_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_enable_clk @ 0010f400 size=1
// signature: undefined sdhci_enable_clk(void)
// callers: [sdhci_msm_set_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_enable_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_cqe_irq @ 0010f408 size=1
// signature: undefined sdhci_cqe_irq(void)
// callers: [sdhci_msm_cqe_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_cqe_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cqhci_irq @ 0010f410 size=1
// signature: undefined cqhci_irq(void)
// callers: [sdhci_msm_cqe_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cqhci_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_round_rate @ 0010f418 size=1
// signature: undefined clk_round_rate(void)
// callers: [sdhci_msm_get_max_clock, msm_init_cm_dll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sdhci_set_timeout @ 0010f420 size=1
// signature: undefined __sdhci_set_timeout(void)
// callers: [sdhci_msm_set_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sdhci_set_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cqhci_deactivate @ 0010f428 size=1
// signature: undefined cqhci_deactivate(void)
// callers: [sdhci_msm_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cqhci_deactivate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_reset @ 0010f430 size=1
// signature: undefined sdhci_reset(void)
// callers: [sdhci_msm_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0010f438 size=1
// signature: undefined ktime_get(void)
// callers: [sdhci_msm_hc_select_mode, sdhci_msm_set_uhs_signaling, sdhci_msm_ice_wait_bist_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0010f440 size=1
// signature: undefined __const_udelay(void)
// callers: [sdhci_msm_runtime_resume, msm_init_cm_dll, msm_config_cm_dll_phase, sdhci_msm_registers_restore, sdhci_msm_handle_pwr_irq, __sdhci_msm_check_write, sdhci_msm_cqe_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010f448 size=1
// signature: undefined init_wait_entry(void)
// callers: [sdhci_msm_check_power_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010f450 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [sdhci_msm_check_power_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010f458 size=1
// signature: undefined finish_wait(void)
// callers: [sdhci_msm_check_power_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010f460 size=1
// signature: undefined schedule_timeout(void)
// callers: [sdhci_msm_check_power_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 0010f468 size=1
// signature: undefined clk_get_rate(void)
// callers: [msm_init_cm_dll, msm_set_clock_rate_for_bus_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010f470 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_runtime_suspend, msm_init_cm_dll, sdhci_msm_cqe_disable, msm_config_cm_dll_phase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010f478 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [sdhci_msm_runtime_resume, sdhci_msm_runtime_suspend, msm_init_cm_dll, sdhci_msm_cqe_disable, msm_config_cm_dll_phase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010f480 size=1
// signature: undefined scnprintf(void)
// callers: [dbg_state_show, show_sdhci_msm_pm_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// capable @ 0010f488 size=1
// signature: undefined capable(void)
// callers: [dbg_state_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 0010f490 size=1
// signature: undefined kstrtobool(void)
// callers: [dbg_state_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010f498 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [sdhci_msm_dt_parse_vreg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010f4a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [sdhci_msm_dt_parse_vreg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010f4a8 size=1
// signature: undefined of_property_read_string(void)
// callers: [sdhci_msm_bus_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 0010f4b0 size=1
// signature: undefined of_icc_get(void)
// callers: [sdhci_msm_bus_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 0010f4b8 size=1
// signature: undefined regulator_set_load(void)
// callers: [sdhci_msm_setup_vreg, sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_regulator_set_ocr @ 0010f4c0 size=1
// signature: undefined mmc_regulator_set_ocr(void)
// callers: [sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_regulator_set_ocr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0010f4c8 size=1
// signature: undefined regulator_disable(void)
// callers: [sdhci_msm_setup_vreg, sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmc_regulator_set_vqmmc @ 0010f4d0 size=1
// signature: undefined mmc_regulator_set_vqmmc(void)
// callers: [sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmc_regulator_set_vqmmc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0010f4d8 size=1
// signature: undefined regulator_enable(void)
// callers: [sdhci_msm_setup_vreg, sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_pm_select_sleep_state @ 0010f4e0 size=1
// signature: undefined pinctrl_pm_select_sleep_state(void)
// callers: [sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_pm_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_pm_select_default_state @ 0010f4e8 size=1
// signature: undefined pinctrl_pm_select_default_state(void)
// callers: [sdhci_msm_handle_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_pm_select_default_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010f4f0 size=1
// signature: undefined __wake_up(void)
// callers: [sdhci_msm_pwr_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_spare_read @ 0010f4f8 size=1
// signature: undefined msm_spare_read(void)
// callers: [sdhci_msm_setup_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_spare_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_spare_write @ 0010f500 size=1
// signature: undefined msm_spare_write(void)
// callers: [sdhci_msm_setup_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_spare_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 0010f508 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [sdhci_msm_setup_vreg, sdhci_msm_set_vdd_io_vol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010f510 size=1
// signature: undefined kstrtouint(void)
// callers: [store_sdhci_msm_pm_qos]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_cqe_enable @ 0010f518 size=1
// signature: undefined sdhci_cqe_enable(void)
// callers: [sdhci_msm_cqe_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_cqe_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdhci_cqe_disable @ 0010f520 size=1
// signature: undefined sdhci_cqe_disable(void)
// callers: [sdhci_msm_cqe_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdhci_cqe_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_ice_invalidate_key @ 0010f528 size=1
// signature: undefined qcom_scm_ice_invalidate_key(void)
// callers: [sdhci_msm_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_ice_invalidate_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010f530 size=1
// signature: undefined ___ratelimit(void)
// callers: [sdhci_msm_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_ice_set_key @ 0010f538 size=1
// signature: undefined qcom_scm_ice_set_key(void)
// callers: [sdhci_msm_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_ice_set_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



