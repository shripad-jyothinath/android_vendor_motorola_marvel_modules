// Decompiled by Ghidra 12.2
// Program: phy-msm-snps-eusb2.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_eusb2_phy_probe @ 0010054c size=1700
// signature: undefined msm_eusb2_phy_probe(void)
// callers: []
//------------------------------------------------------------

ulong msm_eusb2_phy_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  char *pcVar11;
  ulong uVar12;
  
  lVar10 = param_1 + 0x10;
  plVar3 = (long *)devm_kmalloc(lVar10,0x268,0xdc0);
  if (plVar3 == (long *)0x0) {
LAB_00100b24:
    uVar12 = 0xfffffff4;
  }
  else {
    *plVar3 = lVar10;
    uVar4 = devm_usb_get_optional_repeater_by_phandle(lVar10,"usb-repeater",0);
    if (uVar4 < 0xfffffffffffff001) {
      lVar5 = platform_get_resource_byname(param_1,0x200,"eusb2_phy_base");
      if (lVar5 == 0) {
        pcVar11 = "missing eusb2phy memory resource\n";
      }
      else {
        uVar12 = devm_ioremap_resource(lVar10,lVar5);
        plVar3[0x31] = uVar12;
        if (uVar12 < 0xfffffffffffff001) {
          plVar6 = (long *)platform_get_resource_byname(param_1,0x200,"eud_enable_reg");
          if (plVar6 != (long *)0x0) {
            uVar12 = devm_ioremap_resource(lVar10,plVar6);
            plVar3[0x33] = uVar12;
            if (0xfffffffffffff000 < uVar12) {
              _dev_err(lVar10,"eud_enable_reg ioremap err:%d\n",uVar12 & 0xffffffff);
              uVar12 = uVar12 & 0xffffffff;
              goto LAB_00100b28;
            }
            plVar3[0x32] = *plVar6;
          }
          lVar5 = platform_get_resource_byname(param_1,0x200,"eud_detect_reg");
          if (lVar5 != 0) {
            uVar12 = devm_ioremap_resource(lVar10,lVar5);
            plVar3[0x34] = uVar12;
            if (0xfffffffffffff000 < uVar12) {
              _dev_err(lVar10,"eud_detect_reg ioremap err:%d\n",uVar12 & 0xffffffff);
              goto LAB_00100b28;
            }
            *(undefined1 *)(plVar3 + 0x4a) = 1;
            device_property_read_u8_array(lVar10,"qcom,eud-det-val",plVar3 + 0x4a,1);
          }
          lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,port-num",0);
          if (lVar5 != 0) {
            device_property_read_u8_array(lVar10,"qcom,port-num",plVar3 + 0x4c,1);
            if (4 < *(byte *)(plVar3 + 0x4c)) {
              *(undefined1 *)(plVar3 + 0x4c) = 5;
            }
          }
          iVar1 = of_device_is_compatible
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,usb-snps-eusb2-fw-managed");
          if (iVar1 == 0) {
            uVar12 = devm_clk_get(lVar10,"ref_clk_src");
            plVar3[0x36] = uVar12;
            if (uVar12 < 0xfffffffffffff001) {
              uVar12 = devm_clk_get_optional(lVar10,"ref_clk");
              plVar3[0x37] = uVar12;
              if (uVar12 < 0xfffffffffffff001) {
                uVar12 = __devm_reset_control_get(lVar10,"phy_reset",0,0,0,1);
                plVar3[0x38] = uVar12;
                if (uVar12 < 0xfffffffffffff001) {
                  uVar2 = of_property_read_variable_u32_array
                                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,vdd-voltage-level",
                                     plVar3 + 0x3b,3,0);
                  if ((int)uVar2 < 0) {
                    uVar12 = (ulong)uVar2;
                    pcVar11 = "error reading qcom,vdd-voltage-level property\n";
                    goto LAB_00100bb0;
                  }
                  uVar12 = devm_regulator_get(lVar10,&DAT_00103a33);
                  plVar3[0x39] = uVar12;
                  if (uVar12 < 0xfffffffffffff001) {
                    uVar12 = devm_regulator_get(lVar10,"vdda12");
                    plVar3[0x3a] = uVar12;
                    if (uVar12 < 0xfffffffffffff001) goto LAB_00100964;
                    _dev_err(lVar10,"unable to get vdda12 supply\n");
                    uVar12 = (ulong)*(uint *)(plVar3 + 0x3a);
                  }
                  else {
                    _dev_err(lVar10,"unable to get vdd supply\n");
                    uVar12 = (ulong)*(uint *)(plVar3 + 0x39);
                  }
                }
                else {
                  uVar12 = uVar12 & 0xffffffff;
                }
              }
              else {
                _dev_err(lVar10,"clk get failed for ref_clk\n");
                uVar12 = (ulong)*(uint *)(plVar3 + 0x37);
              }
            }
            else {
              _dev_err(lVar10,"clk get failed for ref_clk_src\n");
              uVar12 = (ulong)*(uint *)(plVar3 + 0x36);
            }
          }
          else {
            lVar5 = *plVar3;
            *(undefined1 *)((long)plVar3 + 0x251) = 1;
            uVar2 = of_count_phandle_with_args(*(undefined8 *)(lVar5 + 0x2e8),"power-domains",0);
            *(uint *)((long)plVar3 + 0x254) = uVar2;
            if ((int)uVar2 < 2) {
              uVar12 = 0xffffffea;
            }
            else {
              lVar7 = devm_kmalloc(lVar5,(ulong)uVar2 << 3,0xdc0);
              plVar3[0x4b] = lVar7;
              if (lVar7 != 0) {
                if (0 < *(int *)((long)plVar3 + 0x254)) {
                  uVar12 = 0;
LAB_0010071c:
                  uVar8 = dev_pm_domain_attach_by_id(lVar5,uVar12 & 0xffffffff);
                  *(undefined8 *)(plVar3[0x4b] + uVar12 * 8) = uVar8;
                  if (*(ulong *)(plVar3[0x4b] + uVar12 * 8) < 0xfffffffffffff001)
                  goto code_r0x00100744;
                  if (*(char *)((long)plVar3 + 0x251) != '\0') {
                    if (*(int *)((long)plVar3 + 0x254) < 2) {
                      _dev_err(*plVar3,"%s: PD count invalid\n",
                               "msm_eusb2_phy_modeled_domain_detach");
                    }
                    else {
                      uVar2 = *(int *)((long)plVar3 + 0x254) - 1;
                      do {
                        uVar9 = *(ulong *)(plVar3[0x4b] + (ulong)uVar2 * 8);
                        if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) {
                          dev_pm_domain_detach(uVar9,1);
                        }
                        uVar2 = uVar2 - 1;
                      } while (-1 < (int)uVar2);
                    }
                  }
                  uVar12 = *(ulong *)(plVar3[0x4b] + uVar12 * 8);
                  if ((int)uVar12 == 0) goto LAB_00100964;
                  goto LAB_00100ba8;
                }
LAB_00100964:
                uVar2 = of_property_count_elems_of_size
                                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,param-override-seq",4);
                *(uint *)(plVar3 + 0x46) = uVar2;
                if ((uVar2 & 1) == 0) {
                  if (0 < (int)uVar2) {
                    lVar5 = devm_kmalloc(lVar10,(ulong)uVar2 << 2,0xdc0);
                    plVar3[0x45] = lVar5;
                    if (lVar5 == 0) goto LAB_00100b24;
                    uVar2 = of_property_read_variable_u32_array
                                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,param-override-seq",
                                       lVar5,(long)(int)plVar3[0x46],0);
                    if ((int)uVar2 < 0) {
                      uVar12 = (ulong)uVar2;
                      _dev_err(lVar10,"qcom,param-override-seq read failed %d\n",uVar12);
                      goto LAB_00100b28;
                    }
                  }
                  plVar3[0x23] = (long)msm_eusb2_phy_init;
                  plVar3[0x29] = (long)msm_eusb2_phy_notify_connect;
                  plVar3[0x2a] = (long)msm_eusb2_phy_notify_disconnect;
                  plVar3[0x49] = uVar4;
                  plVar3[0x26] = (long)msm_eusb2_phy_set_power;
                  plVar3[0x27] = (long)msm_eusb2_phy_set_suspend;
                  *(long **)(param_1 + 0xa8) = plVar3;
                  *(undefined4 *)((long)plVar3 + 0x14) = 1;
                  plVar3[0x3f] = 0xfffffffe0;
                  plVar3[0x40] = (long)(plVar3 + 0x40);
                  plVar3[0x41] = (long)(plVar3 + 0x40);
                  plVar3[0x42] = (long)msm_eusb2_phy_vbus_draw_work;
                  lVar10 = ((long *)*plVar3)[0xe];
                  if (lVar10 == 0) {
                    lVar10 = *(long *)*plVar3;
                  }
                  lVar10 = debugfs_create_dir(lVar10,0);
                  plVar3[0x47] = lVar10;
                  debugfs_create_x8("tx_pre_emphasis",0x1a4,lVar10,plVar3 + 0x48);
                  debugfs_create_x8("tx_rise_fall_time",0x1a4,plVar3[0x47],(long)plVar3 + 0x241);
                  debugfs_create_x8("tx_src_imp",0x1a4,plVar3[0x47],(long)plVar3 + 0x242);
                  debugfs_create_x8("tx_dc_vref",0x1a4,plVar3[0x47],(long)plVar3 + 0x243);
                  debugfs_create_x8("tx_xv",0x1a4,plVar3[0x47],(long)plVar3 + 0x244);
                  debugfs_create_file("apb_reg_rw",0x80,plVar3[0x47],plVar3,apb_reg_rw_fops);
                  if ((plVar3[0x33] != 0) && (uVar4 = readl_relaxed(), (uVar4 & 1) != 0)) {
                    msm_eusb2_phy_modeled_d3_to_d0(plVar3);
                    msm_eusb2_phy_power(plVar3,1);
                    msm_eusb2_phy_clocks(plVar3,1);
                    msm_eusb2_repeater_reset_and_init(plVar3);
                  }
                  uVar2 = usb_add_phy_dev(plVar3);
                  if (-1 < (int)uVar2) {
                    uVar12 = 0;
                    goto LAB_00100b8c;
                  }
                  uVar12 = (ulong)uVar2;
                }
                else {
                  _dev_err(lVar10,"invalid param_override_seq_len\n");
                  uVar12 = 0xffffffea;
                }
                goto LAB_00100b28;
              }
              uVar12 = 0xfffffff4;
            }
LAB_00100ba8:
            pcVar11 = "Failed to attach modeled domains. Bail out\n";
LAB_00100bb0:
            _dev_err(lVar10,pcVar11);
          }
          goto LAB_00100b28;
        }
        pcVar11 = "ioremap failed\n";
      }
      _dev_err(lVar10,pcVar11);
      uVar12 = 0xffffffed;
    }
    else {
      uVar12 = uVar4 & 0xffffffff;
    }
  }
LAB_00100b28:
  if (*(char *)((long)plVar3 + 0x251) != '\0') {
    if (*(int *)((long)plVar3 + 0x254) < 2) {
      _dev_err(*plVar3,"%s: PD count invalid\n","msm_eusb2_phy_modeled_domain_detach");
    }
    else {
      uVar2 = *(int *)((long)plVar3 + 0x254) - 1;
      do {
        uVar4 = *(ulong *)(plVar3[0x4b] + (ulong)uVar2 * 8);
        if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
          dev_pm_domain_detach(uVar4,1);
        }
        uVar2 = uVar2 - 1;
      } while (-1 < (int)uVar2);
    }
  }
LAB_00100b8c:
  return uVar12 & 0xffffffff;
code_r0x00100744:
  uVar12 = uVar12 + 1;
  if ((long)*(int *)((long)plVar3 + 0x254) <= (long)uVar12) goto LAB_00100964;
  goto LAB_0010071c;
}



//------------------------------------------------------------
// msm_eusb2_phy_remove @ 00100bf4 size=328
// signature: undefined msm_eusb2_phy_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eusb2_phy_remove(long param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  if (puVar2 != (undefined8 *)0x0) {
    flush_work(puVar2 + 0x3f);
    if (puVar2[0x3d] != 0) {
      power_supply_put();
    }
    debugfs_remove(puVar2[0x47]);
    usb_remove_phy(puVar2);
    if (*(char *)((long)puVar2 + 0x251) == '\0') {
      uVar4 = puVar2[0x37];
      clk_disable(uVar4);
      clk_unprepare(uVar4);
      uVar4 = puVar2[0x36];
      clk_disable(uVar4);
      clk_unprepare(uVar4);
      if ((*(char *)((long)puVar2 + 0x251) == '\0') && (*(char *)((long)puVar2 + 0x1e4) != '\0')) {
        uVar4 = puVar2[0x37];
        clk_disable(uVar4);
        clk_unprepare(uVar4);
        uVar4 = puVar2[0x36];
        clk_disable(uVar4);
        clk_unprepare(uVar4);
        *(undefined1 *)((long)puVar2 + 0x1e4) = 0;
      }
      msm_eusb2_phy_power(puVar2,0);
    }
    else {
      __pm_runtime_idle(*(undefined8 *)puVar2[0x4b],4);
      __pm_runtime_idle(*(undefined8 *)(puVar2[0x4b] + 8),4);
      if (*(char *)((long)puVar2 + 0x251) != '\0') {
        if (*(int *)((long)puVar2 + 0x254) < 2) {
          _dev_err(*puVar2,"%s: PD count invalid\n","msm_eusb2_phy_modeled_domain_detach");
        }
        else {
          uVar3 = *(int *)((long)puVar2 + 0x254) - 1;
          do {
            uVar1 = *(ulong *)(puVar2[0x4b] + (ulong)uVar3 * 8);
            if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
              dev_pm_domain_detach(uVar1,1);
            }
            uVar3 = uVar3 - 1;
          } while (-1 < (int)uVar3);
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_eusb2_phy_init @ 00100d40 size=3408
// signature: undefined msm_eusb2_phy_init(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eusb2_phy_init(undefined8 *param_1)

{
  long *plVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  
  if ((param_1[0x33] != 0) && (uVar7 = readl_relaxed(), (uVar7 & 1) != 0)) {
    if ((*(byte *)(param_1 + 2) & 1) == 0) {
      msm_eusb2_phy_modeled_d3_to_d0(param_1);
      msm_eusb2_phy_power(param_1,1);
      msm_eusb2_phy_clocks(param_1,1);
      uVar8 = msm_eusb2_repeater_reset_and_init(param_1);
      return uVar8;
    }
    qcom_scm_io_writel(param_1[0x32],0);
    *(undefined1 *)(param_1 + 0x35) = 1;
  }
  msm_eusb2_phy_modeled_d3_to_d0(param_1);
  uVar8 = msm_eusb2_phy_power(param_1,1);
  if ((int)uVar8 != 0) {
    return uVar8;
  }
  uVar8 = msm_eusb2_repeater_reset_and_init(param_1);
  if ((int)uVar8 != 0) {
    return uVar8;
  }
  msm_eusb2_phy_clocks(param_1,1);
  if (*(char *)((long)param_1 + 0x251) == '\0') {
    iVar5 = reset_control_assert(param_1[0x38]);
    if (iVar5 != 0) {
      _dev_err(*param_1,"phy reset assert failed\n");
    }
    usleep_range_state(100,0x96,2);
    iVar5 = reset_control_deassert(param_1[0x38]);
    if (iVar5 != 0) {
      _dev_err(*param_1,"phy reset deassert failed\n");
    }
  }
  plVar1 = param_1 + 0x31;
  lVar9 = param_1[0x31] + 0x94;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 2,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 1 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",2,0x94);
  }
  lVar9 = *plVar1 + 0x50;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 2,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 1 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",2,0x50);
  }
  __const_udelay(0xa7c6);
  lVar9 = *plVar1 + 0x54;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 9,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if (((uVar6 ^ 0xffffffff) & 9) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",9,0x54);
  }
  lVar9 = *plVar1 + 0x130;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 4,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 2 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",4,0x130);
  }
  lVar9 = *plVar1 + 0x98;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffffbf,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 6 & 1) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x98);
  }
  lVar9 = *plVar1 + 0xb8;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 1,lVar9);
  uVar7 = readl_relaxed(lVar9);
  if ((uVar7 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",1,0xb8);
  }
  lVar9 = clk_get_rate(param_1[0x36]);
  if (lVar9 == 38400000) {
    lVar9 = *plVar1 + 0x54;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffff8f | 0x40,lVar9);
    uVar6 = readl_relaxed(lVar9);
    if ((uVar6 & 0x70) != 0x40) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x40,0x54);
    }
    lVar9 = *plVar1 + 0x5c;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffff00 | 200,lVar9);
    cVar3 = readl_relaxed(lVar9);
    if (cVar3 != -0x38) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",200,0x5c);
    }
    lVar9 = *plVar1 + 0x60;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xfffffff0,lVar9);
    uVar7 = readl_relaxed(lVar9);
    if ((uVar7 & 0xf) == 0) goto LAB_00101084;
    uVar8 = 0;
  }
  else {
    if (lVar9 != 19200000) {
      _dev_err(*param_1,"unsupported ref_clk_freq:%lu\n",lVar9);
      goto LAB_00101084;
    }
    lVar9 = *plVar1 + 0x54;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffff8f,lVar9);
    uVar7 = readl_relaxed(lVar9);
    if ((uVar7 & 0x70) != 0) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x54);
    }
    lVar9 = *plVar1 + 0x5c;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffff00 | 0x90,lVar9);
    cVar3 = readl_relaxed(lVar9);
    if (cVar3 != -0x70) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x90,0x5c);
    }
    lVar9 = *plVar1 + 0x60;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xfffffff0 | 1,lVar9);
    uVar6 = readl_relaxed(lVar9);
    if ((uVar6 & 0xf) == 1) goto LAB_00101084;
    uVar8 = 1;
  }
  _printk(&DAT_001037fe,"msm_eusb2_write_readback",uVar8,0x60);
LAB_00101084:
  lVar9 = *plVar1 + 0x60;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffff0f,lVar9);
  uVar7 = readl_relaxed(lVar9);
  if ((uVar7 & 0xf0) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x60);
  }
  lVar9 = *plVar1 + 0x58;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffff01 | 2,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0xfe) != 2) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",2,0x58);
  }
  lVar9 = *plVar1 + 0x68;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffff03 | 0x20,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0xfc) != 0x20) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x20,0x68);
  }
  lVar9 = *plVar1 + 0x68;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffffc | 1,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 3) != 1) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",1,0x68);
  }
  lVar9 = *plVar1 + 0x6c;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffffe0 | 0x10,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0x1f) != 0x10) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x10,0x6c);
  }
  lVar9 = *plVar1 + 0x70;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffff8,lVar9);
  uVar7 = readl_relaxed(lVar9);
  if ((uVar7 & 7) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x70);
  }
  lVar9 = *plVar1 + 0x6c;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffff3f | 0x40,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0xc0) != 0x40) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x40,0x6c);
  }
  lVar9 = *plVar1 + 100;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 0x10,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 4 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x10,100);
  }
  lVar9 = *plVar1 + 0x7c;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffff8,lVar9);
  uVar7 = readl_relaxed(lVar9);
  if ((uVar7 & 7) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x7c);
  }
  lVar9 = *plVar1 + 0x7c;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffff9f | 0x40,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0x60) != 0x40) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x40,0x7c);
  }
  lVar9 = *plVar1 + 0x7c;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffffe7 | 8,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0x18) != 8) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",8,0x7c);
  }
  lVar9 = *plVar1 + 0x78;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffffc7 | 0x18,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 & 0x38) != 0x18) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0x18,0x78);
  }
  lVar9 = *plVar1 + 0x78;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xffffff3f,lVar9);
  uVar7 = readl_relaxed(lVar9);
  if ((uVar7 & 0xc0) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x78);
  }
  iVar5 = *(int *)(param_1 + 0x46);
  if (0 < iVar5) {
    iVar11 = 0;
    lVar9 = param_1[0x31];
    lVar12 = param_1[0x45];
    do {
      writel_relaxed(*(undefined4 *)(lVar12 + (long)iVar11 * 4),
                     lVar9 + (ulong)*(uint *)(lVar12 + (long)(iVar11 + 1) * 4));
      iVar11 = iVar11 + 2;
    } while (iVar11 < iVar5);
  }
  bVar2 = *(byte *)(param_1 + 0x48);
  if (bVar2 - 1 < 7) {
    lVar9 = *plVar1 + 0x7c;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xfffffff8 | (uint)bVar2,lVar9);
    bVar4 = readl_relaxed(lVar9);
    if ((bVar4 & 7) != bVar2) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",bVar2,0x7c);
    }
  }
  if (*(byte *)((long)param_1 + 0x241) - 1 < 4) {
    uVar10 = (uint)*(byte *)((long)param_1 + 0x241) << 5;
    lVar9 = *plVar1 + 0x7c;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffff9f | uVar10,lVar9);
    uVar6 = readl_relaxed(lVar9);
    if ((uVar6 & 0x60) != uVar10) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",uVar10,0x7c);
    }
  }
  if (*(byte *)((long)param_1 + 0x242) - 1 < 4) {
    uVar10 = (uint)*(byte *)((long)param_1 + 0x242) << 3;
    lVar9 = *plVar1 + 0x7c;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffffe7 | uVar10,lVar9);
    uVar6 = readl_relaxed(lVar9);
    if ((uVar6 & 0x18) != uVar10) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",uVar10,0x7c);
    }
  }
  if (*(byte *)((long)param_1 + 0x243) - 1 < 7) {
    uVar10 = (uint)*(byte *)((long)param_1 + 0x243) << 3;
    lVar9 = *plVar1 + 0x78;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffffc7 | uVar10,lVar9);
    uVar6 = readl_relaxed(lVar9);
    if ((uVar6 & 0x38) != uVar10) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",uVar10,0x78);
    }
  }
  if (*(byte *)((long)param_1 + 0x244) - 1 < 4) {
    uVar10 = (uint)*(byte *)((long)param_1 + 0x244) << 6;
    lVar9 = *plVar1 + 0x78;
    uVar6 = readl_relaxed(lVar9);
    writel_relaxed(uVar6 & 0xffffff3f | uVar10,lVar9);
    uVar6 = readl_relaxed(lVar9);
    if ((uVar6 & 0xc0) != uVar10) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",uVar10,0x78);
    }
  }
  lVar9 = *plVar1 + 100;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 0xc,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if (((uVar6 ^ 0xffffffff) & 0xc) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0xc,100);
  }
  lVar9 = *plVar1 + 0x3c;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 1,lVar9);
  uVar7 = readl_relaxed(lVar9);
  if ((uVar7 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",1,0x3c);
  }
  lVar9 = *plVar1 + 0x54;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 | 2,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 1 & 1) == 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",2,0x54);
  }
  lVar9 = *plVar1 + 0x54;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffffb,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 2 & 1) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x54);
  }
  lVar9 = *plVar1 + 0x50;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffffd,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 1 & 1) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x50);
  }
  lVar9 = *plVar1 + 100;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffff7,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 3 & 1) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,100);
  }
  lVar9 = *plVar1 + 0x94;
  uVar6 = readl_relaxed(lVar9);
  writel_relaxed(uVar6 & 0xfffffffd,lVar9);
  uVar6 = readl_relaxed(lVar9);
  if ((uVar6 >> 1 & 1) != 0) {
    _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x94);
  }
  return 0;
}



//------------------------------------------------------------
// msm_eusb2_phy_set_suspend @ 00101a94 size=396
// signature: undefined msm_eusb2_phy_set_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eusb2_phy_set_suspend(long param_1,int param_2)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  if ((param_2 != 0) && (*(char *)(param_1 + 0x1e6) != '\0')) {
    return 0;
  }
  if (param_2 == 0) {
    msm_eusb2_phy_modeled_d3_to_d0(param_1);
    msm_eusb2_phy_power(param_1,1);
    msm_eusb2_phy_clocks(param_1,1);
  }
  else if ((*(char *)(param_1 + 0x1e7) == '\0') &&
          (uVar3 = *(uint *)(param_1 + 0x10), (uVar3 & 1) == 0)) {
    if (*(char *)(param_1 + 0x1a8) != '\0') {
      qcom_scm_io_writel(*(undefined8 *)(param_1 + 400),1);
      uVar3 = *(uint *)(param_1 + 0x10);
      *(undefined1 *)(param_1 + 0x1a8) = 0;
    }
    if (((uVar3 >> 6 & 1) == 0) &&
       ((*(long *)(param_1 + 0x198) == 0 || (uVar1 = readl_relaxed(), (uVar1 & 1) == 0)))) {
      msm_eusb2_phy_clocks(param_1,0);
      msm_eusb2_phy_power(param_1,0);
      msm_eusb2_phy_modeled_d0_to_d3(param_1);
      lVar2 = *(long *)(param_1 + 0x248);
      if (lVar2 != 0) {
        pcVar4 = *(code **)(lVar2 + 0x28);
        if (pcVar4 != (code *)0x0) {
          if (*(int *)(pcVar4 + -4) != 0x608ea566) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101b4c);
            (*pcVar4)();
          }
          (*pcVar4)(lVar2,0);
          lVar2 = *(long *)(param_1 + 0x248);
          if (lVar2 == 0) goto LAB_00101bbc;
        }
        pcVar4 = *(code **)(lVar2 + 0x48);
        if (pcVar4 != (code *)0x0) {
          if (*(int *)(pcVar4 + -4) != 0x60a42524) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101b78);
            (*pcVar4)();
          }
          (*pcVar4)();
        }
      }
    }
  }
  else {
    if (*(char *)(param_1 + 0x251) == '\0') {
      if (*(char *)(param_1 + 0x1e4) == '\0') goto LAB_00101bbc;
      uVar5 = *(undefined8 *)(param_1 + 0x1b8);
      clk_disable(uVar5);
      clk_unprepare(uVar5);
      uVar5 = *(undefined8 *)(param_1 + 0x1b0);
      clk_disable(uVar5);
      clk_unprepare(uVar5);
      *(undefined1 *)(param_1 + 0x1e4) = 0;
      if (*(char *)(param_1 + 0x251) == '\0') goto LAB_00101bbc;
    }
    __pm_runtime_idle(**(undefined8 **)(param_1 + 600),4);
  }
LAB_00101bbc:
  *(bool *)(param_1 + 0x1e6) = param_2 != 0;
  return 0;
}



//------------------------------------------------------------
// msm_eusb2_phy_notify_connect @ 00101c24 size=720
// signature: undefined msm_eusb2_phy_notify_connect(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eusb2_phy_notify_connect(long param_1,uint param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 0x1e7) = 1;
  if ((4 < param_2) && ((*(uint *)(param_1 + 0x10) & 1) == 0)) {
    lVar1 = *(long *)(param_1 + 0x188) + 0x130;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\0') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x130);
    }
    lVar1 = *(long *)(param_1 + 0x188) + 0x138;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00 | 5,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\x05') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",5,0x138);
    }
    lVar1 = *(long *)(param_1 + 0x188) + 0x13c;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00 | 0xc0,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != -0x40) {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0xc0,0x13c);
    }
    lVar1 = *(long *)(param_1 + 0x188) + 0x130;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00 | 3,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\x03') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",3,0x130);
    }
    __const_udelay(0x218e);
    lVar1 = *(long *)(param_1 + 0x188) + 0x130;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\0') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x130);
    }
    lVar1 = *(long *)(param_1 + 0x188) + 0x13c;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\0') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x13c);
    }
    lVar1 = *(long *)(param_1 + 0x188) + 0x130;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00 | 3,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\x03') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",3,0x130);
    }
    __const_udelay(0x218e);
    lVar1 = *(long *)(param_1 + 0x188) + 0x130;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xffffff00,lVar1);
    cVar2 = readl_relaxed(lVar1);
    if (cVar2 != '\0') {
      _printk(&DAT_001037fe,"msm_eusb2_write_readback",0,0x130);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_eusb2_phy_notify_disconnect @ 00101ef8 size=120
// signature: undefined msm_eusb2_phy_notify_disconnect(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eusb2_phy_notify_disconnect(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  if ((((*(long *)(param_1 + 0x198) != 0) && (uVar2 = readl_relaxed(), (uVar2 & 1) != 0)) &&
      ((*(byte *)(param_1 + 0x10) >> 6 & 1) == 0)) && (*(long *)(param_1 + 0x1a0) != 0)) {
    uVar1 = readl_relaxed();
    writel_relaxed(uVar1 & 0xfffffffe,*(undefined8 *)(param_1 + 0x1a0));
    DataSynchronizationBarrier(3,3,0);
    if (*(long *)(param_1 + 0x1a0) != 0) {
      DataSynchronizationBarrier(3,3,0);
      writel_relaxed(*(undefined1 *)(param_1 + 0x250),*(undefined8 *)(param_1 + 0x1a0));
    }
  }
  *(undefined1 *)(param_1 + 0x1e7) = 0;
  return 0;
}



//------------------------------------------------------------
// msm_eusb2_phy_set_power @ 00101f74 size=68
// signature: undefined msm_eusb2_phy_set_power(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_eusb2_phy_set_power(long param_1,int param_2)

{
  if ((param_2 != 0) || (*(char *)(param_1 + 0x1e7) == '\0')) {
    *(int *)(param_1 + 0x1f0) = param_2;
    queue_work_on(0x20,_system_wq,param_1 + 0x1f8);
  }
  return 0;
}



//------------------------------------------------------------
// msm_eusb2_phy_vbus_draw_work @ 00101fbc size=252
// signature: undefined msm_eusb2_phy_vbus_draw_work(void)
// callers: []
//------------------------------------------------------------

void msm_eusb2_phy_vbus_draw_work(long param_1)

{
  long lVar1;
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_2c = 0;
  local_30 = 0;
  if (*(byte *)(param_1 + 0x68) - 2 < 3) {
    snprintf((char *)&local_30,6,"usb-%u",(uint)*(byte *)(param_1 + 0x68));
    lVar1 = *(long *)(param_1 + -0x10);
  }
  else {
    local_30 = 0x627375;
    lVar1 = *(long *)(param_1 + -0x10);
  }
  if (lVar1 == 0) {
    lVar1 = power_supply_get_by_name(&local_30);
    *(long *)(param_1 + -0x10) = lVar1;
    if (lVar1 == 0) {
      _dev_err(*(undefined8 *)(param_1 + -0x1f8),"Could not get usb psy\n");
      goto LAB_0010208c;
    }
  }
  _dev_info(*(undefined8 *)(param_1 + -0x1f8),"Avail curr from USB = %u\n",
            *(undefined4 *)(param_1 + -8));
  local_38 = CONCAT44(local_38._4_4_,*(int *)(param_1 + -8) * 1000);
  power_supply_set_property(*(undefined8 *)(param_1 + -0x10),0x26,&local_38);
LAB_0010208c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_eusb2_phy_modeled_d3_to_d0 @ 001020b8 size=236
// signature: undefined msm_eusb2_phy_modeled_d3_to_d0(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_init, msm_eusb2_phy_set_suspend]
//------------------------------------------------------------

void msm_eusb2_phy_modeled_d3_to_d0(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  
  if (*(char *)(param_1 + 0x251) != '\0') {
    lVar6 = **(long **)(param_1 + 600);
    iVar5 = __pm_runtime_resume(lVar6,4);
    if (iVar5 < 0) {
      piVar1 = (int *)(lVar6 + 0x1f8);
      iVar5 = *(int *)(lVar6 + 0x1f8);
      do {
        if (iVar5 == 0) {
          return;
        }
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar5) goto LAB_0010213c;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar5 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010213c:
        bVar4 = iVar5 != iVar2;
        iVar5 = iVar2;
      } while (bVar4);
    }
    else {
      lVar6 = *(long *)(*(long *)(param_1 + 600) + 8);
      iVar5 = __pm_runtime_resume(lVar6,4);
      if (iVar5 < 0) {
        piVar1 = (int *)(lVar6 + 0x1f8);
        iVar5 = *(int *)(lVar6 + 0x1f8);
        do {
          if (iVar5 == 0) {
            return;
          }
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar5) goto LAB_00102198;
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = iVar5 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_00102198:
          bVar4 = iVar5 != iVar2;
          iVar5 = iVar2;
        } while (bVar4);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// msm_eusb2_phy_power @ 001021cc size=632
// signature: undefined msm_eusb2_phy_power(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_init, msm_eusb2_phy_set_suspend, msm_eusb2_phy_remove]
//------------------------------------------------------------

int msm_eusb2_phy_power(undefined8 *param_1,byte param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 uVar6;
  
  if ((*(char *)((long)param_1 + 0x251) != '\0') ||
     (*(byte *)((long)param_1 + 0x1e5) == (param_2 & 1))) {
    return 0;
  }
  if ((param_2 & 1) == 0) {
    if (param_1[0x34] != 0) {
      uVar3 = readl_relaxed();
      writel_relaxed(uVar3 & 0xfffffffe,param_1[0x34]);
      DataSynchronizationBarrier(3,3,0);
    }
    iVar2 = regulator_disable(param_1[0x3a]);
    if (iVar2 != 0) {
      uVar4 = *param_1;
      pcVar5 = "Unable to disable vdda12:%d\n";
LAB_0010243c:
      _dev_err(uVar4,pcVar5,iVar2);
    }
    iVar2 = regulator_set_voltage(param_1[0x3a],0,1200000);
    if (iVar2 != 0) {
      uVar4 = *param_1;
      pcVar5 = "Unable to set (0) voltage for vdda12:%d\n";
LAB_00102424:
      _dev_err(uVar4,pcVar5,iVar2);
    }
    iVar2 = regulator_set_load(param_1[0x3a],0);
    if (iVar2 < 0) {
      _dev_err(*param_1,"Unable to set LPM of vdda12\n");
    }
LAB_001022f0:
    iVar2 = regulator_disable(param_1[0x39]);
    if (iVar2 != 0) {
      _dev_err(*param_1,"Unable to disable vdd:%d\n",iVar2);
    }
LAB_001022fc:
    iVar2 = regulator_set_voltage
                      (param_1[0x39],*(undefined4 *)(param_1 + 0x3b),*(undefined4 *)(param_1 + 0x3c)
                      );
    if (iVar2 != 0) {
      pcVar5 = "unable to set voltage for hsusb vdd\n";
LAB_001023c8:
      _dev_err(*param_1,pcVar5);
    }
    iVar2 = regulator_set_load(param_1[0x39],0);
    if (iVar2 < 0) {
      _dev_err(*param_1,"Unable to set LPM of vdd\n");
      cVar1 = *(char *)((long)param_1 + 0x1e5);
    }
    else {
      cVar1 = *(char *)((long)param_1 + 0x1e5);
    }
    if (cVar1 == '\0') {
      return -0x16;
    }
  }
  else {
    iVar2 = regulator_set_load(param_1[0x39],0x1e4d);
    if (-1 < iVar2) {
      iVar2 = regulator_set_voltage
                        (param_1[0x39],*(undefined4 *)((long)param_1 + 0x1dc),
                         *(undefined4 *)(param_1 + 0x3c));
      if (iVar2 == 0) {
        iVar2 = regulator_enable(param_1[0x39]);
        if (iVar2 == 0) {
          iVar2 = regulator_set_load(param_1[0x3a],0x1711);
          if (-1 < iVar2) {
            iVar2 = regulator_set_voltage(param_1[0x3a],1200000,1200000);
            if (iVar2 == 0) {
              iVar2 = regulator_enable(param_1[0x3a]);
              if (iVar2 == 0) {
                if (param_1[0x34] != 0) {
                  DataSynchronizationBarrier(3,3,0);
                  writel_relaxed(*(undefined1 *)(param_1 + 0x4a),param_1[0x34]);
                }
                iVar2 = 0;
                uVar6 = 1;
                goto LAB_00102330;
              }
              uVar4 = *param_1;
              pcVar5 = "Unable to enable vdda12:%d\n";
              goto LAB_0010243c;
            }
            uVar4 = *param_1;
            pcVar5 = "Unable to set voltage for vdda12:%d\n";
            goto LAB_00102424;
          }
          _dev_err(*param_1,"Unable to set HPM of vdda12:%d\n",iVar2);
          goto LAB_001022f0;
        }
        _dev_err(*param_1,"Unable to enable VDD\n");
        goto LAB_001022fc;
      }
      pcVar5 = "Unable to set voltage for hsusb vdd\n";
      goto LAB_001023c8;
    }
    _dev_err(*param_1,"Unable to set HPM of vdd:%d\n",iVar2);
  }
  uVar6 = 0;
LAB_00102330:
  *(undefined1 *)((long)param_1 + 0x1e5) = uVar6;
  return iVar2;
}



//------------------------------------------------------------
// msm_eusb2_phy_clocks @ 00102444 size=184
// signature: undefined msm_eusb2_phy_clocks(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_init, msm_eusb2_phy_set_suspend]
//------------------------------------------------------------

void msm_eusb2_phy_clocks(long param_1,byte param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x251) != '\0') {
    return;
  }
  if (*(byte *)(param_1 + 0x1e4) == (param_2 & 1)) {
    return;
  }
  if ((param_2 & 1) == 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x1b8);
    clk_disable(uVar2);
    clk_unprepare(uVar2);
    uVar2 = *(undefined8 *)(param_1 + 0x1b0);
    clk_disable(uVar2);
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x1b0);
    iVar1 = clk_prepare(uVar2);
    if ((iVar1 == 0) && (iVar1 = clk_enable(uVar2), iVar1 != 0)) {
      clk_unprepare(uVar2);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x1b8);
    iVar1 = clk_prepare(uVar2);
    if ((iVar1 != 0) || (iVar1 = clk_enable(uVar2), iVar1 == 0)) goto LAB_001024e4;
  }
  clk_unprepare(uVar2);
LAB_001024e4:
  *(byte *)(param_1 + 0x1e4) = param_2 & 1;
  return;
}



//------------------------------------------------------------
// msm_eusb2_repeater_reset_and_init @ 001024fc size=296
// signature: undefined msm_eusb2_repeater_reset_and_init(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_init]
//------------------------------------------------------------

int msm_eusb2_repeater_reset_and_init(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  
  if (*(char *)((long)param_1 + 0x251) != '\0') {
    return 0;
  }
  if (param_1[0x49] == 0) {
    return 0;
  }
  *(undefined4 *)(param_1[0x49] + 0x10) = *(undefined4 *)(param_1 + 2);
  if (param_1[0x49] == 0) {
    return 0;
  }
  pcVar3 = *(code **)(param_1[0x49] + 0x40);
  if (pcVar3 == (code *)0x0) {
LAB_00102570:
    lVar2 = param_1[0x49];
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x60a42524) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102568);
      (*pcVar3)();
    }
    iVar1 = (*pcVar3)();
    if (iVar1 == 0) goto LAB_00102570;
    _dev_err(*param_1,"repeater powerup failed.\n");
    lVar2 = param_1[0x49];
  }
  if (lVar2 == 0) {
    return 0;
  }
  pcVar3 = *(code **)(lVar2 + 0x28);
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != 0x608ea566) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10259c);
      (*pcVar3)();
    }
    iVar1 = (*pcVar3)(lVar2,1);
    if (iVar1 != 0) {
      _dev_err(*param_1,"repeater reset failed.\n");
      lVar2 = param_1[0x49];
      goto joined_r0x001025a8;
    }
  }
  lVar2 = param_1[0x49];
joined_r0x001025a8:
  if ((lVar2 == 0) || (pcVar3 = *(code **)(lVar2 + 0x30), pcVar3 == (code *)0x0)) {
    return 0;
  }
  if (*(int *)(pcVar3 + -4) != 0x60a42524) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1025cc);
    (*pcVar3)();
  }
  iVar1 = (*pcVar3)();
  if (iVar1 == 0) {
    return 0;
  }
  _dev_err(*param_1,"repeater init failed.\n");
  return iVar1;
}



//------------------------------------------------------------
// readl_relaxed @ 00102624 size=124
// signature: undefined readl_relaxed(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_power, msm_eusb2_phy_init, msm_eusb2_phy_notify_disconnect, msm_eusb2_phy_notify_connect, msm_eusb2_phy_set_suspend]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10266c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 001026a0 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_eusb2_phy_power, msm_eusb2_phy_init, msm_eusb2_phy_notify_disconnect, msm_eusb2_phy_notify_connect]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1026b8,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1026f4,uVar1);
  return;
}



//------------------------------------------------------------
// msm_eusb2_phy_modeled_d0_to_d3 @ 00102724 size=76
// signature: undefined msm_eusb2_phy_modeled_d0_to_d3(void)
// callers: [msm_eusb2_phy_set_suspend]
//------------------------------------------------------------

void msm_eusb2_phy_modeled_d0_to_d3(long param_1)

{
  if (*(char *)(param_1 + 0x251) != '\0') {
    __pm_runtime_idle(**(undefined8 **)(param_1 + 600),4);
    __pm_runtime_idle(*(undefined8 *)(*(long *)(param_1 + 600) + 8),4);
  }
  return;
}



//------------------------------------------------------------
// apb_reg_rw_write @ 00102774 size=984
// signature: undefined apb_reg_rw_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong apb_reg_rw_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  ushort uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  char *pcVar9;
  undefined8 *puVar10;
  ulong uVar11;
  undefined8 *puVar12;
  ushort local_78 [2];
  undefined1 local_74 [4];
  char *local_70;
  char local_68 [32];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  local_74[0] = 0;
  puVar12 = *(undefined8 **)(*(long *)(param_1 + 0xd8) + 0x80);
  local_78[0] = 0;
  if (*(char *)((long)puVar12 + 0x1e7) == '\0') {
    _dev_err(*puVar12,"eUSB2 PHY is not out of reset.\n");
    param_3 = 0xffffffffffffffea;
  }
  else {
    uVar8 = param_3;
    if (0x1e < param_3) {
      uVar8 = 0x1f;
    }
    __check_object_size(local_68,uVar8,0);
    puVar10 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar11 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar11 <= 0x8000000000 - uVar8) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        puVar10 = (undefined8 *)puVar10[1];
        uVar2 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      uVar8 = __arch_copy_from_user(puVar10,local_68,param_2 & 0xff7fffffffffffff,uVar8);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
    }
    if (uVar8 == 0) {
      local_70 = local_68;
      pcVar9 = strsep(&local_70," ");
      if (((pcVar9 != (char *)0x0) && (*pcVar9 != '\0')) &&
         ((iVar5 = strcmp(pcVar9,"read"), iVar5 == 0 || (iVar6 = strcmp(pcVar9,"write"), iVar6 == 0)
          ))) {
        pcVar9 = strsep(&local_70," ");
        if (pcVar9 == (char *)0x0) {
          pcVar9 = "Provide register offset\n";
        }
        else {
          iVar6 = kstrtou8(pcVar9,0x10,local_74);
          uVar4 = local_74[0];
          if (iVar6 == 0) {
            if (iVar5 == 0) {
              writel(local_74[0],puVar12[0x31] + 0x138);
              writel(2,puVar12[0x31] + 0x130);
              ktime_get();
              readl(puVar12[0x31] + 0x134);
              uVar7 = readl(puVar12[0x31] + 0x144);
              iVar5 = readl(puVar12[0x31] + 0x148);
              writel(0,puVar12[0x31] + 0x130);
              _dev_info(*puVar12,"APB reg(%x) read success, val:%x\n",uVar4,uVar7 | iVar5 << 8);
              goto LAB_00102a34;
            }
            pcVar9 = strsep(&local_70," ");
            if (pcVar9 == (char *)0x0) {
              pcVar9 = "Provide value to update register\n";
            }
            else {
              iVar5 = kstrtou16(pcVar9,0x10,local_78);
              uVar4 = local_74[0];
              uVar3 = local_78[0];
              if (iVar5 == 0) {
                writel(local_74[0],puVar12[0x31] + 0x138);
                writel(uVar3 >> 8 & 0xf,puVar12[0x31] + 0x140);
                writel(uVar3 & 0xf,puVar12[0x31] + 0x13c);
                writel(3,puVar12[0x31] + 0x130);
                ktime_get();
                readl(puVar12[0x31] + 0x134);
                writel(0,puVar12[0x31] + 0x130);
                _dev_info(*puVar12,"APB reg(%x) updated with %x\n",uVar4,uVar3);
                goto LAB_00102a34;
              }
              pcVar9 = "Invalid value\n";
            }
          }
          else {
            pcVar9 = "Invalid register offset\n";
          }
        }
        _dev_err(*puVar12,pcVar9);
      }
      _printk(&DAT_0010337a,"apb_reg_rw_write");
      _printk(&DAT_00103773,"apb_reg_rw_write");
      _printk(&DAT_001033c6,"apb_reg_rw_write");
      _printk(&DAT_001039fd,"apb_reg_rw_write");
      _printk(&DAT_00103332,"apb_reg_rw_write");
    }
    else {
      param_3 = 0xfffffffffffffff2;
    }
  }
LAB_00102a34:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// apb_reg_rw_open @ 00102b68 size=40
// signature: undefined apb_reg_rw_open(void)
// callers: []
//------------------------------------------------------------

void apb_reg_rw_open(long param_1,undefined8 param_2)

{
  single_open(param_2,0,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// writel @ 00102b90 size=136
// signature: undefined writel(void)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102ba8,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102be8,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 00102c18 size=140
// signature: undefined readl(void)
// callers: [apb_reg_rw_write]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102c70,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00102cd8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_eusb2_phy_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102d08 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_eusb2_phy_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00106000 size=1
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
// platform_driver_unregister @ 00106008 size=1
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
// devm_kmalloc @ 00106010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_usb_get_optional_repeater_by_phandle @ 00106018 size=1
// signature: undefined devm_usb_get_optional_repeater_by_phandle(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_usb_get_optional_repeater_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00106020 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00106028 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_read_u8_array @ 00106030 size=1
// signature: undefined device_property_read_u8_array(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_u8_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00106038 size=1
// signature: undefined of_find_property(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00106040 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00106048 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_attach_by_id @ 00106050 size=1
// signature: undefined dev_pm_domain_attach_by_id(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_attach_by_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00106058 size=1
// signature: undefined devm_clk_get(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get_optional @ 00106060 size=1
// signature: undefined devm_clk_get_optional(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 00106068 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_detach @ 00106070 size=1
// signature: undefined dev_pm_domain_detach(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00106078 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00106080 size=1
// signature: undefined devm_regulator_get(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106088 size=1
// signature: undefined _dev_err(void)
// callers: [msm_eusb2_phy_probe, msm_eusb2_phy_power, msm_eusb2_phy_vbus_draw_work, msm_eusb2_phy_init, msm_eusb2_repeater_reset_and_init, apb_reg_rw_write, msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00106090 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00106098 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x8 @ 001060a0 size=1
// signature: undefined debugfs_create_x8(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001060a8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_phy_dev @ 001060b0 size=1
// signature: undefined usb_add_phy_dev(void)
// callers: [msm_eusb2_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_phy_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 001060b8 size=1
// signature: undefined flush_work(void)
// callers: [msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 001060c0 size=1
// signature: undefined power_supply_put(void)
// callers: [msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001060c8 size=1
// signature: undefined debugfs_remove(void)
// callers: [msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_phy @ 001060d0 size=1
// signature: undefined usb_remove_phy(void)
// callers: [msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_phy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001060d8 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [msm_eusb2_phy_modeled_d0_to_d3, msm_eusb2_phy_set_suspend, msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001060e0 size=1
// signature: undefined clk_disable(void)
// callers: [msm_eusb2_phy_clocks, msm_eusb2_phy_set_suspend, msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001060e8 size=1
// signature: undefined clk_unprepare(void)
// callers: [msm_eusb2_phy_clocks, msm_eusb2_phy_set_suspend, msm_eusb2_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 001060f0 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [msm_eusb2_phy_init, msm_eusb2_phy_set_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 001060f8 size=1
// signature: undefined reset_control_assert(void)
// callers: [msm_eusb2_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00106100 size=1
// signature: undefined usleep_range_state(void)
// callers: [msm_eusb2_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 00106108 size=1
// signature: undefined reset_control_deassert(void)
// callers: [msm_eusb2_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00106110 size=1
// signature: undefined __const_udelay(void)
// callers: [msm_eusb2_phy_init, msm_eusb2_phy_notify_connect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 00106118 size=1
// signature: undefined clk_get_rate(void)
// callers: [msm_eusb2_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106120 size=1
// signature: undefined _printk(void)
// callers: [msm_eusb2_phy_init, msm_eusb2_phy_notify_connect, apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00106130 size=1
// signature: undefined queue_work_on(void)
// callers: [msm_eusb2_phy_set_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00106138 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [msm_eusb2_phy_vbus_draw_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00106140 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [msm_eusb2_phy_vbus_draw_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00106148 size=1
// signature: undefined _dev_info(void)
// callers: [msm_eusb2_phy_vbus_draw_work, apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_set_property @ 00106150 size=1
// signature: undefined power_supply_set_property(void)
// callers: [msm_eusb2_phy_vbus_draw_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_set_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106158 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_eusb2_phy_vbus_draw_work, apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00106160 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [msm_eusb2_phy_modeled_d3_to_d0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00106170 size=1
// signature: undefined regulator_set_load(void)
// callers: [msm_eusb2_phy_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00106178 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [msm_eusb2_phy_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00106180 size=1
// signature: undefined regulator_enable(void)
// callers: [msm_eusb2_phy_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00106188 size=1
// signature: undefined regulator_disable(void)
// callers: [msm_eusb2_phy_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00106190 size=1
// signature: undefined clk_prepare(void)
// callers: [msm_eusb2_phy_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00106198 size=1
// signature: undefined clk_enable(void)
// callers: [msm_eusb2_phy_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001061a0 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 001061a8 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001061b0 size=1
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
// log_post_write_mmio @ 001061b8 size=1
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
// __check_object_size @ 001061c0 size=1
// signature: undefined __check_object_size(void)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001061d0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 001061d8 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001061e0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 001061e8 size=1
// signature: undefined kstrtou8(void)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001061f0 size=1
// signature: undefined ktime_get(void)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 001061f8 size=1
// signature: undefined kstrtou16(void)
// callers: [apb_reg_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00106208 size=1
// signature: undefined single_open(void)
// callers: [apb_reg_rw_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



