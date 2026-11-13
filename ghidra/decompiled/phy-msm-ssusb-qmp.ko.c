// Decompiled by Ghidra 12.2
// Program: phy-msm-ssusb-qmp.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_ssphy_qmp_probe @ 001004b4 size=2652
// signature: undefined msm_ssphy_qmp_probe(void)
// callers: []
//------------------------------------------------------------

ulong msm_ssphy_qmp_probe(long param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  char *pcVar10;
  ulong uVar11;
  long lVar12;
  undefined8 local_50;
  long local_48;
  
  lVar12 = sp_el0;
  lVar8 = param_1 + 0x10;
  local_48 = *(long *)(lVar12 + 0x638);
  local_50 = 0;
  plVar4 = (long *)devm_kmalloc(lVar8,0x2a8,0xdc0);
  if (plVar4 == (long *)0x0) {
LAB_00100c0c:
    uVar11 = 0xfffffff4;
    goto LAB_00100d64;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  *plVar4 = lVar8;
  *(undefined4 *)(plVar4 + 0x4f) = 0;
  iVar2 = of_device_is_compatible(uVar5,"qcom,usb-ssphy-qmp-dp-combo");
  if (iVar2 != 0) {
    *(undefined4 *)(plVar4 + 0x4f) = 2;
  }
  iVar2 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,usb-ssphy-qmp-usb3-or-dp");
  if (iVar2 != 0) {
    *(undefined4 *)(plVar4 + 0x4f) = 1;
  }
  iVar2 = of_device_is_compatible
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,usb-ssphy-qmp-dp-combo-fw-managed");
  if (iVar2 == 0) {
    if (*(char *)((long)plVar4 + 0x27d) != '\0') goto LAB_00100578;
    uVar11 = devm_clk_get(lVar8,"aux_clk");
    plVar4[0x41] = uVar11;
    if (0xfffffffffffff000 < uVar11) {
      plVar4[0x41] = 0;
      if ((int)uVar11 == -0x205) goto LAB_00100ce0;
      pcVar10 = "failed to get aux_clk\n";
LAB_00100720:
      _dev_err(lVar8,pcVar10);
LAB_001007fc:
      if ((int)uVar11 == 0) {
LAB_00100800:
        uVar9 = __devm_reset_control_get(lVar8,"phy_reset",0,0,0,1);
        plVar4[0x47] = uVar9;
        if (uVar9 < 0xfffffffffffff001) {
          if ((int)plVar4[0x4f] == 2) {
            uVar9 = __devm_reset_control_get(lVar8,"global_phy_reset",0,0,0,1);
            plVar4[0x49] = uVar9;
          }
          else {
            uVar9 = __devm_reset_control_get(lVar8,"phy_phy_reset",0,0,0,1);
            plVar4[0x48] = uVar9;
          }
          if (0xfffffffffffff000 < uVar9) goto LAB_0010082c;
        }
        else {
LAB_0010082c:
          uVar11 = uVar9 & 0xffffffff;
          if ((int)uVar9 != 0) goto LAB_00100ce4;
        }
        goto LAB_00100898;
      }
      goto LAB_00100ce4;
    }
    uVar5 = clk_round_rate(uVar11,0xffffffffffffffff);
    clk_set_rate(uVar11,uVar5);
    iVar2 = of_property_match_string(*(undefined8 *)(param_1 + 0x2f8),"clock-names","cfg_ahb_clk");
    if (-1 < iVar2) {
      uVar11 = devm_clk_get(lVar8,"cfg_ahb_clk");
      plVar4[0x43] = uVar11;
      if (uVar11 < 0xfffffffffffff001) goto LAB_001006ec;
      if ((int)uVar11 == -0x205) goto LAB_00100ce0;
      pcVar10 = "failed to get cfg_ahb_clk ret %d\n";
LAB_001007f0:
      uVar11 = uVar11 & 0xffffffff;
      _dev_err(lVar8,pcVar10,uVar11);
      goto LAB_001007fc;
    }
LAB_001006ec:
    uVar11 = devm_clk_get(lVar8,"pipe_clk");
    plVar4[0x44] = uVar11;
    if (uVar11 < 0xfffffffffffff001) {
      uVar9 = devm_clk_get(lVar8,"pipe_clk_mux");
      uVar11 = 0;
      if (uVar9 < 0xfffffffffffff001) {
        uVar11 = uVar9;
      }
      plVar4[0x45] = uVar11;
      uVar9 = devm_clk_get(lVar8,"pipe_clk_ext_src");
      uVar11 = 0;
      if (uVar9 < 0xfffffffffffff001) {
        uVar11 = uVar9;
      }
      plVar4[0x46] = uVar11;
      uVar9 = devm_clk_get(lVar8,"ref_clk_src");
      uVar11 = 0;
      if (uVar9 < 0xfffffffffffff001) {
        uVar11 = uVar9;
      }
      plVar4[0x3f] = uVar11;
      uVar9 = devm_clk_get(lVar8,"ref_clk");
      uVar11 = 0;
      if (uVar9 < 0xfffffffffffff001) {
        uVar11 = uVar9;
      }
      uVar5 = *(undefined8 *)(param_1 + 0x2f8);
      plVar4[0x40] = uVar11;
      iVar2 = of_property_match_string(uVar5,"clock-names","com_aux_clk");
      if (-1 < iVar2) {
        uVar11 = devm_clk_get(lVar8,"com_aux_clk");
        plVar4[0x42] = uVar11;
        if (0xfffffffffffff000 < uVar11) {
          if ((int)uVar11 != -0x205) {
            pcVar10 = "failed to get com_aux_clk ret %d\n";
            goto LAB_001007f0;
          }
          goto LAB_00100ce0;
        }
      }
      goto LAB_00100800;
    }
    plVar4[0x44] = 0;
    if ((int)uVar11 != -0x205) {
      uVar11 = uVar11 & 0xffffffff;
      pcVar10 = "failed to get pipe_clk\n";
      goto LAB_00100720;
    }
    goto LAB_00100ce0;
  }
  *(undefined4 *)(plVar4 + 0x4f) = 2;
  *(undefined1 *)((long)plVar4 + 0x27d) = 1;
LAB_00100578:
  lVar12 = *plVar4;
  uVar3 = of_count_phandle_with_args(*(undefined8 *)(lVar12 + 0x2e8),"power-domains",0);
  *(uint *)(plVar4 + 0x51) = uVar3;
  if ((int)uVar3 < 2) {
    uVar11 = 0xffffffea;
  }
  else {
    lVar6 = devm_kmalloc(lVar12,(ulong)uVar3 << 3,0xdc0);
    plVar4[0x50] = lVar6;
    if (lVar6 != 0) {
      if (0 < (int)plVar4[0x51]) {
        uVar11 = 0;
LAB_001005c4:
        uVar5 = dev_pm_domain_attach_by_id(lVar12,uVar11 & 0xffffffff);
        *(undefined8 *)(plVar4[0x50] + uVar11 * 8) = uVar5;
        if (*(ulong *)(plVar4[0x50] + uVar11 * 8) < 0xfffffffffffff001) goto code_r0x001005ec;
        if (*(char *)((long)plVar4 + 0x27d) != '\0') {
          if ((int)plVar4[0x51] < 2) {
            _dev_err(*plVar4,"%s: PD count invalid\n","msm_ssphy_modeled_domain_detach");
          }
          else {
            uVar3 = (int)plVar4[0x51] - 1;
            do {
              uVar9 = *(ulong *)(plVar4[0x50] + (ulong)uVar3 * 8);
              if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) {
                dev_pm_domain_detach(uVar9,1);
              }
              uVar3 = uVar3 - 1;
            } while (-1 < (int)uVar3);
          }
        }
        uVar11 = *(ulong *)(plVar4[0x50] + uVar11 * 8);
        if ((int)uVar11 == 0) goto LAB_00100898;
        goto LAB_00100c1c;
      }
LAB_00100898:
      of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,qmp-phy-reg-offset",(long)&local_50 + 4
                     );
      if (local_50._4_4_ == 0) {
        pcVar10 = "err provide qcom,qmp-phy-reg-offset\n";
        goto LAB_00100d58;
      }
      lVar12 = devm_kmalloc(lVar8,0x38,0xdc0);
      plVar4[0x4b] = lVar12;
      if (lVar12 == 0) {
        _dev_err(lVar8,"err mem alloc for qmp_phy_reg_offset\n");
        uVar11 = 0xfffffff4;
        goto LAB_00100d64;
      }
      *(int *)(plVar4 + 0x4c) = (int)local_50._4_4_ >> 2;
      if (0x3b < (int)local_50._4_4_) {
        pcVar10 = "invalid reg offset count\n";
        goto LAB_00100d58;
      }
      of_property_read_variable_u32_array
                (*(undefined8 *)(param_1 + 0x2f8),"qcom,qmp-phy-reg-offset",lVar12,
                 (long)((int)local_50._4_4_ >> 2),0);
      plVar7 = (long *)platform_get_resource_byname(param_1,0x200,"qmp_phy_base");
      if (plVar7 == (long *)0x0) {
        _dev_err(lVar8,"failed getting qmp_phy_base\n");
        uVar11 = 0xffffffed;
        goto LAB_00100d64;
      }
      uVar11 = devm_ioremap(lVar8,*plVar7,(plVar7[1] - *plVar7) + 1);
      plVar4[0x31] = uVar11;
      if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
        uVar11 = uVar11 & 0xffffffff;
LAB_00100ce4:
        if (*(char *)((long)plVar4 + 0x27d) != '\0') {
          if ((int)plVar4[0x51] < 2) {
            _dev_err(*plVar4,"%s: PD count invalid\n","msm_ssphy_modeled_domain_detach");
          }
          else {
            uVar3 = (int)plVar4[0x51] - 1;
            do {
              uVar9 = *(ulong *)(plVar4[0x50] + (ulong)uVar3 * 8);
              if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) {
                dev_pm_domain_detach(uVar9,1);
              }
              uVar3 = uVar3 - 1;
            } while (-1 < (int)uVar3);
          }
        }
      }
      else {
        lVar12 = platform_get_resource_byname(param_1,0x200,"vls_clamp_reg");
        if (lVar12 != 0) {
          uVar11 = devm_ioremap_resource(lVar8,lVar12);
          plVar4[0x32] = uVar11;
          if (0xfffffffffffff000 < uVar11) {
            _dev_err(lVar8,"err getting vls_clamp_reg address\n");
            uVar11 = (ulong)*(uint *)(plVar4 + 0x32);
            goto LAB_00100d64;
          }
        }
        lVar12 = platform_get_resource_byname(param_1,0x200,"pcs_clamp_enable_reg");
        if (lVar12 != 0) {
          uVar11 = devm_ioremap_resource(lVar8,lVar12);
          plVar4[0x33] = uVar11;
          if (0xfffffffffffff000 < uVar11) {
            _dev_err(lVar8,"err getting pcs_clamp_enable_reg address.\n");
            uVar11 = (ulong)*(uint *)(plVar4 + 0x33);
            goto LAB_00100d64;
          }
        }
        lVar12 = platform_get_resource_byname(param_1,0x200,"tcsr_usb3_dp_phymode");
        if (lVar12 != 0) {
          uVar11 = devm_ioremap_resource(lVar8,lVar12);
          plVar4[0x34] = uVar11;
          if (0xfffffffffffff000 < uVar11) {
            _dev_err(lVar8,"err getting tcsr_usb3_dp_phymode addr\n");
            uVar11 = (ulong)*(uint *)(plVar4 + 0x34);
            goto LAB_00100d64;
          }
        }
        of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,qmp-phy-init-seq",(long)&local_50 + 4
                       );
        if (local_50._4_4_ == 0) {
          pcVar10 = "error need qmp-phy-init-seq\n";
        }
        else {
          if (((long)(int)local_50._4_4_ & 3U) == 0) {
            lVar12 = devm_kmalloc(lVar8,(long)(int)local_50._4_4_,0xdc0);
            plVar4[0x4d] = lVar12;
            if (lVar12 == 0) goto LAB_00100c0c;
            uVar5 = *(undefined8 *)(param_1 + 0x2f8);
            *(int *)(plVar4 + 0x4e) = (int)local_50._4_4_ >> 2;
            of_property_read_variable_u32_array
                      (uVar5,"qcom,qmp-phy-init-seq",lVar12,
                       (long)((ulong)local_50._4_4_ << 0x20) >> 0x22,0);
            uVar5 = *(undefined8 *)(param_1 + 0x2f8);
            plVar4[0x3b] = 0x124f8000000000;
            *(undefined4 *)(plVar4 + 0x3c) = 1200000;
            lVar12 = of_get_property(uVar5,"qcom,core-voltage-level",&local_50);
            if (((lVar12 != 0) && ((int)local_50 == 0xc)) &&
               (uVar3 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,core-voltage-level",
                                   plVar4 + 0x3b,3,0), (int)uVar3 < 0)) {
              pcVar10 = "err qcom,core-voltage-level property\n";
LAB_00100ec4:
              uVar11 = (ulong)uVar3;
              _dev_err(lVar8,pcVar10);
              goto LAB_00100ce4;
            }
            piVar1 = (int *)((long)plVar4 + 0x1e4);
            iVar2 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,core-max-load-uA",piVar1,1,0);
            if ((iVar2 < 0) || (*piVar1 == 0)) {
              *piVar1 = 30000;
            }
            if (*(char *)((long)plVar4 + 0x27d) == '\0') {
              lVar12 = of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,vdd-voltage-level",
                                       &local_50);
              if ((lVar12 == 0) || ((int)local_50 != 0xc)) {
                _dev_err(lVar8,"error invalid inputs for vdd-voltage-level\n");
                uVar11 = 0xffffffea;
                goto LAB_00100ce4;
              }
              uVar3 = of_property_read_variable_u32_array
                                (*(undefined8 *)(param_1 + 0x2f8),"qcom,vdd-voltage-level",
                                 plVar4 + 0x36,3,0);
              if ((int)uVar3 < 0) {
                pcVar10 = "err qcom,vdd-voltage-level property\n";
                goto LAB_00100ec4;
              }
            }
            lVar12 = of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,refgen-voltage-level",
                                     &local_50);
            if (((lVar12 != 0) && ((int)local_50 == 0xc)) &&
               (iVar2 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,refgen-voltage-level",
                                   (long)plVar4 + 0x1bc,3,0), iVar2 < 0)) {
              _dev_err(lVar8,"err qcom,refgen-voltage-level property\n");
            }
            plVar7 = plVar4 + 0x39;
            iVar2 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,vdd-max-load-uA",plVar7,1,0);
            if ((iVar2 < 0) || ((int)*plVar7 == 0)) {
              *(undefined4 *)plVar7 = 30000;
            }
            lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,invert-ps-polarity",0);
            uVar5 = *(undefined8 *)(param_1 + 0x2f8);
            *(bool *)((long)plVar4 + 0x274) = lVar8 != 0;
            lVar8 = of_find_property(uVar5,"qcom,force-usb3",0);
            plVar4[0x23] = (long)msm_ssphy_qmp_init;
            *(bool *)((long)plVar4 + 0x27c) = lVar8 != 0;
            plVar4[0x27] = (long)msm_ssphy_qmp_set_suspend;
            plVar4[0x29] = (long)msm_ssphy_qmp_notify_connect;
            plVar4[0x2a] = (long)msm_ssphy_qmp_notify_disconnect;
            if (*(char *)((long)plVar4 + 0x27d) == '\0') {
              lVar8 = *plVar4;
              plVar4[0x3e] = 0;
              uVar9 = devm_regulator_get(lVar8,&DAT_001038e7);
              plVar4[0x35] = uVar9;
              if (uVar9 < 0xfffffffffffff001) {
                uVar9 = devm_regulator_get(lVar8,&DAT_0010332c);
                plVar4[0x3a] = uVar9;
                if (0xfffffffffffff000 < uVar9) {
                  if ((int)uVar9 == -0x205) goto LAB_00100ce0;
                  pcVar10 = "fail to get core ldo supply\n";
                  goto LAB_00100edc;
                }
                uVar11 = devm_regulator_get(lVar8,"usb3_dp_phy_gdsc");
                plVar4[0x3d] = uVar11;
                if ((uVar11 < 0xfffffffffffff001) || (iVar2 = (int)uVar11, iVar2 == -0x13)) {
                  lVar12 = of_find_property(*(undefined8 *)(lVar8 + 0x2e8),"refgen-supply",0);
                  if (lVar12 != 0) {
                    uVar11 = devm_regulator_get_optional(lVar8,"refgen");
                    plVar4[0x3e] = uVar11;
                    if (0xfffffffffffff000 < uVar11) {
                      _dev_err(lVar8,"fail to get refgen supply\n");
                    }
                  }
                  goto LAB_00100bf0;
                }
                uVar11 = uVar11 & 0xffffffff;
                _dev_err(lVar8,"fail to get usb3_dp_phy_gdsc(%d)\n",uVar11);
              }
              else {
                if ((int)uVar9 == -0x205) {
LAB_00100ce0:
                  uVar11 = 0xfffffdfb;
                  goto LAB_00100ce4;
                }
                pcVar10 = "fail to get vdd supply\n";
LAB_00100edc:
                uVar11 = uVar9 & 0xffffffff;
                _dev_err(lVar8,pcVar10);
                iVar2 = (int)uVar9;
              }
              if (iVar2 != 0) goto LAB_00100ce4;
            }
LAB_00100bf0:
            uVar11 = usb_add_phy_dev(plVar4);
            if (-1 < (int)uVar11) {
              msm_ssphy_qmp_create_debugfs(plVar4);
              uVar11 = 0;
              goto LAB_00100d64;
            }
            uVar11 = uVar11 & 0xffffffff;
            goto LAB_00100ce4;
          }
          pcVar10 = "invalid init_seq_len\n";
        }
LAB_00100d58:
        _dev_err(lVar8,pcVar10);
        uVar11 = 0xffffffea;
      }
      goto LAB_00100d64;
    }
    uVar11 = 0xfffffff4;
  }
LAB_00100c1c:
  _dev_err(lVar8,"Failed to attach modeled domains. Bail out\n");
LAB_00100d64:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
code_r0x001005ec:
  uVar11 = uVar11 + 1;
  if ((long)(int)plVar4[0x51] <= (long)uVar11) goto LAB_00100898;
  goto LAB_001005c4;
}



//------------------------------------------------------------
// msm_ssphy_qmp_remove @ 00100f14 size=236
// signature: undefined msm_ssphy_qmp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ssphy_qmp_remove(long param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  if (puVar2 != (undefined8 *)0x0) {
    if (puVar2[0x53] != 0) {
      kfree();
      puVar2[0x53] = 0;
      *(undefined4 *)(puVar2 + 0x54) = 0;
    }
    debugfs_remove(puVar2[0x52]);
    usb_remove_phy(puVar2);
    if (*(char *)((long)puVar2 + 0x27d) != '\0') {
      __pm_runtime_idle(*(undefined8 *)puVar2[0x50],4);
      __pm_runtime_idle(*(undefined8 *)(puVar2[0x50] + 8),4);
      if (*(char *)((long)puVar2 + 0x27d) != '\0') {
        if (*(int *)(puVar2 + 0x51) < 2) {
          _dev_err(*puVar2,"%s: PD count invalid\n","msm_ssphy_modeled_domain_detach");
        }
        else {
          uVar3 = *(int *)(puVar2 + 0x51) - 1;
          do {
            uVar1 = *(ulong *)(puVar2[0x50] + (ulong)uVar3 * 8);
            if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
              dev_pm_domain_detach(uVar1,1);
            }
            uVar3 = uVar3 - 1;
          } while (-1 < (int)uVar3);
        }
      }
    }
    msm_ssphy_qmp_enable_clks(puVar2,0);
    msm_ssusb_qmp_ldo_enable(puVar2,0);
  }
  return 0;
}



//------------------------------------------------------------
// msm_ssphy_qmp_init @ 00101004 size=1588
// signature: undefined msm_ssphy_qmp_init(void)
// callers: []
//------------------------------------------------------------

int msm_ssphy_qmp_init(long *param_1)

{
  long *plVar1;
  long *plVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  undefined4 *puVar13;
  
  if ((*(byte *)((long)param_1 + 0x11) >> 1 & 1) != 0) {
    _dev_info(*param_1,"QMP PHY currently in DP mode\n");
    return -0x10;
  }
  iVar6 = msm_ssusb_qmp_ldo_enable(param_1,1);
  if (iVar6 != 0) {
    _dev_err(*param_1,"msm_ssusb_qmp_ldo_enable(1) failed, ret=%d\n",iVar6);
    return iVar6;
  }
  msm_ssphy_qmp_enable_clks(param_1,1);
  msm_ssphy_modeled_d3_to_d0(param_1);
  if ((int)param_1[0x4f] == 2) {
    if ((*(byte *)((long)param_1 + 0x11) >> 2 & 1) == 0) {
      iVar6 = reset_control_assert(param_1[0x49]);
      if (iVar6 == 0) {
        iVar6 = reset_control_assert(param_1[0x47]);
        if (iVar6 != 0) goto LAB_0010117c;
        iVar6 = reset_control_deassert(param_1[0x47]);
        if (iVar6 != 0) {
          _dev_err(*param_1,"phy_reset deassert failed\n");
        }
        iVar6 = reset_control_deassert(param_1[0x49]);
        if (iVar6 == 0) goto LAB_00101100;
        pcVar9 = "global_phy_reset deassert failed\n";
      }
      else {
        pcVar9 = "global_phy_reset assert failed\n";
      }
    }
    else {
      iVar6 = reset_control_assert(param_1[0x47]);
      if (iVar6 == 0) {
        iVar6 = reset_control_deassert(param_1[0x47]);
        if (iVar6 != 0) {
          pcVar9 = "phy_reset deassert failed\n";
          goto LAB_00101354;
        }
LAB_00101100:
        uVar7 = *(uint *)(param_1 + 2);
        goto joined_r0x001011ac;
      }
LAB_0010117c:
      pcVar9 = "phy_reset assert failed\n";
    }
LAB_00101354:
    _dev_err(*param_1,pcVar9);
    uVar7 = *(uint *)(param_1 + 2);
    if ((uVar7 >> 2 & 1) == 0) goto LAB_00101108;
LAB_001011b0:
    uVar11 = 2;
LAB_001011b8:
    bVar5 = false;
    bVar4 = true;
  }
  else {
    iVar6 = reset_control_assert(param_1[0x48]);
    if (iVar6 == 0) {
      iVar6 = reset_control_assert(param_1[0x47]);
      if (iVar6 == 0) {
        if (param_1[0x34] != 0) {
          writel_relaxed(0);
        }
        iVar6 = reset_control_deassert(param_1[0x47]);
        if (iVar6 != 0) {
          pcVar9 = "phy_reset deassert failed\n";
          goto LAB_00101190;
        }
        iVar6 = reset_control_deassert(param_1[0x48]);
        if (iVar6 == 0) goto LAB_00101100;
LAB_001010dc:
        pcVar9 = "phy_phy_reset deassert failed\n";
        goto LAB_00101164;
      }
      pcVar9 = "phy_reset assert failed\n";
LAB_00101190:
      _dev_err(*param_1,pcVar9);
      iVar6 = reset_control_deassert(param_1[0x48]);
      if (iVar6 != 0) goto LAB_001010dc;
    }
    else {
      pcVar9 = "phy_phy_reset assert failed\n";
LAB_00101164:
      _dev_err(*param_1,pcVar9);
    }
    *(undefined1 *)((long)param_1 + 0x253) = 0;
    uVar7 = *(uint *)(param_1 + 2);
joined_r0x001011ac:
    if ((uVar7 >> 2 & 1) != 0) goto LAB_001011b0;
LAB_00101108:
    if ((uVar7 >> 3 & 1) != 0) {
      uVar11 = 3;
      goto LAB_001011b8;
    }
    bVar4 = false;
    uVar11 = 0xffffffea;
    bVar5 = true;
  }
  if (*(uint *)(param_1 + 0x4f) < 2) {
LAB_001011e4:
    writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0xc));
  }
  else {
    if (*(uint *)(param_1 + 0x4f) == 2) {
      writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x1c));
      goto LAB_001011e4;
    }
    _dev_err(*param_1,"phy_powerup: Unknown USB QMP PHY type\n");
  }
  DataSynchronizationBarrier(3,3,0);
  if ((int)param_1[0x4f] == 1) {
    if (!bVar4) goto LAB_001013e4;
    _dev_err(*param_1,"USB QMP PHY: Update TYPEC CTRL(%d)\n",uVar11);
    lVar10 = 6;
LAB_001013cc:
    writel_relaxed(uVar11,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + lVar10 * 4));
  }
  else if ((int)param_1[0x4f] == 2) {
    if ((bVar5) && (*(char *)((long)param_1 + 0x274) != '\0')) {
      writel_relaxed(4,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x2c));
    }
    plVar1 = param_1 + 0x31;
    writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x20));
    writel_relaxed(0,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x20));
    if (*(uint *)(param_1[0x4b] + 0x34) != 0) {
      readl_relaxed(*plVar1 + (ulong)*(uint *)(param_1[0x4b] + 0x34));
    }
    plVar2 = param_1 + 0x4b;
    if ((*(byte *)((long)param_1 + 0x11) >> 2 & 1) == 0) {
      writel_relaxed(0xf,*plVar1 + (ulong)*(uint *)(*plVar2 + 0x24));
      if (!bVar4) goto LAB_0010130c;
LAB_001012ac:
      _dev_err(*param_1,"USB DP QMP PHY: Update TYPEC CTRL(%d)\n",uVar11);
      writel_relaxed(uVar11,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x2c));
      if (bVar5) goto LAB_00101310;
LAB_0010131c:
      if (*(char *)((long)param_1 + 0x27c) == '\0') goto LAB_00101390;
LAB_00101324:
      uVar11 = 1;
    }
    else {
      if (bVar4) goto LAB_001012ac;
LAB_0010130c:
      if (!bVar5) goto LAB_0010131c;
LAB_00101310:
      if (*(long *)(*param_1 + 0x278) != 0) goto LAB_0010131c;
      _dev_err(*param_1,"USB DP QMP PHY: NO SW PORTSELECT\n");
      if (*(char *)((long)param_1 + 0x27c) != '\0') goto LAB_00101324;
LAB_00101390:
      if ((*(byte *)((long)param_1 + 0x11) >> 2 & 1) != 0) goto LAB_001013e4;
      uVar11 = 3;
    }
    writel_relaxed(uVar11,*plVar1 + (ulong)*(uint *)(*plVar2 + 0x28));
    readl_relaxed(*plVar1 + (ulong)*(uint *)(*plVar2 + 0x28));
    uVar11 = 0;
    lVar10 = 9;
    goto LAB_001013cc;
  }
LAB_001013e4:
  DataSynchronizationBarrier(3,3,0);
  if (1 < *(uint *)(param_1 + 0x4f)) {
    if (*(uint *)(param_1 + 0x4f) != 2) {
      _dev_err(*param_1,"phy_powerup: Unknown USB QMP PHY type\n");
      goto LAB_00101428;
    }
    writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x1c));
  }
  writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0xc));
LAB_00101428:
  DataSynchronizationBarrier(3,3,0);
  if (param_1[0x4d] == 0) {
    _dev_err(*param_1,"NULL PHY configuration\n");
    _dev_err(*param_1,"Failed the main PHY configuration\n");
    iVar6 = -0x16;
  }
  else {
    if (1 < (int)param_1[0x4e]) {
      iVar6 = 0;
      puVar13 = (undefined4 *)(param_1[0x4d] + 4);
      do {
        writel_relaxed(*puVar13,param_1[0x31] + (ulong)(uint)puVar13[-1]);
        iVar3 = (int)param_1[0x4e];
        iVar6 = iVar6 + 1;
        puVar13 = puVar13 + 2;
        if (iVar3 < 0) {
          iVar3 = iVar3 + 1;
        }
      } while (iVar6 < iVar3 >> 1);
    }
    iVar6 = (int)param_1[0x54];
    if (0 < iVar6) {
      lVar12 = 0;
      lVar10 = 0;
      do {
        uVar7 = *(uint *)(param_1[0x53] + lVar12 + 4);
        if ((uVar7 & 0xfff0000) != 0xdef0000) {
          writel_relaxed(uVar7,param_1[0x31] + (ulong)*(uint *)(param_1[0x53] + lVar12));
          iVar6 = (int)param_1[0x54];
        }
        lVar10 = lVar10 + 1;
        lVar12 = lVar12 + 8;
      } while (lVar10 < iVar6);
    }
    writel_relaxed(0,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x10));
    writel_relaxed(3,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x14));
    DataSynchronizationBarrier(3,3,0);
    iVar6 = -1000;
    do {
      uVar7 = readl_relaxed(param_1[0x31] + (ulong)*(uint *)param_1[0x4b]);
      if ((uVar7 >> 6 & 1) == 0) {
        return 0;
      }
      usleep_range_state(1,2,2);
      bVar5 = iVar6 != -1;
      iVar6 = iVar6 + 1;
    } while (bVar5);
    _dev_err(*param_1,"QMP PHY initialization timeout\n");
    lVar10 = *param_1;
    uVar8 = readl_relaxed(param_1[0x31] + (ulong)*(uint *)param_1[0x4b]);
    _dev_err(lVar10,"USB3_PHY_PCS_STATUS:%x\n",uVar8);
    iVar6 = -0x10;
  }
  *(undefined1 *)((long)param_1 + 0x253) = 1;
  writel_relaxed(0,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0xc));
  msm_ssphy_qmp_enable_clks(param_1,0);
  msm_ssusb_qmp_ldo_enable(param_1,0);
  if (*(char *)((long)param_1 + 0x27d) != '\0') {
    __pm_runtime_idle(*(undefined8 *)param_1[0x50],4);
    __pm_runtime_idle(*(undefined8 *)(param_1[0x50] + 8),4);
  }
  return iVar6;
}



//------------------------------------------------------------
// msm_ssphy_qmp_set_suspend @ 0010163c size=472
// signature: undefined msm_ssphy_qmp_set_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ssphy_qmp_set_suspend(undefined8 *param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  
  if (*(byte *)((long)param_1 + 0x253) != param_2) {
    if (param_2 == 0) {
      if ((*(byte *)((long)param_1 + 0x11) >> 1 & 1) != 0) {
        _dev_info(*param_1,"QMP PHY currently in DP mode\n");
        return 0xfffffff0;
      }
      msm_ssphy_modeled_d3_to_d0(param_1);
      if ((((*(byte *)(param_1 + 2) & 1) == 0) && (*(char *)((long)param_1 + 0x252) == '\0')) &&
         (iVar2 = msm_ssusb_qmp_ldo_enable(param_1,1), iVar2 != 0)) {
        _dev_err(*param_1,"msm_ssusb_qmp_ldo_enable(1) failed, ret=%d\n",iVar2);
      }
      msm_ssphy_qmp_enable_clks(param_1,1);
      if (*(char *)((long)param_1 + 0x252) == '\0') {
        writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0xc));
      }
      else {
        msm_ssusb_qmp_enable_autonomous(param_1,0);
      }
      DataSynchronizationBarrier(3,2,0);
      *(undefined1 *)((long)param_1 + 0x253) = 0;
      return 0;
    }
    if (*(char *)((long)param_1 + 0x252) == '\0') {
      if ((*(int *)(param_1 + 0x4f) == 2) && ((*(byte *)((long)param_1 + 0x11) & 6) == 0)) {
        writel_relaxed(1,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x28));
        readl_relaxed(param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0x28));
      }
      writel_relaxed(0,param_1[0x31] + (ulong)*(uint *)(param_1[0x4b] + 0xc));
    }
    else {
      msm_ssusb_qmp_enable_autonomous(param_1,1);
    }
    DataSynchronizationBarrier(3,2,0);
    msm_ssphy_qmp_enable_clks(param_1,0);
    *(undefined1 *)((long)param_1 + 0x253) = 1;
    if ((((*(byte *)(param_1 + 2) & 1) == 0) && (*(char *)((long)param_1 + 0x252) == '\0')) &&
       (iVar2 = msm_ssusb_qmp_ldo_enable(param_1,0), iVar2 != 0)) {
      _dev_err(*param_1,"msm_ssusb_qmp_ldo_enable(0) failed, ret=%d\n",iVar2);
      cVar1 = *(char *)((long)param_1 + 0x27d);
    }
    else {
      cVar1 = *(char *)((long)param_1 + 0x27d);
    }
    if (cVar1 != '\0') {
      __pm_runtime_idle(*(undefined8 *)param_1[0x50],4);
      __pm_runtime_idle(*(undefined8 *)(param_1[0x50] + 8),4);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_ssphy_qmp_notify_connect @ 00101818 size=52
// signature: undefined msm_ssphy_qmp_notify_connect(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ssphy_qmp_notify_connect(long param_1)

{
  *(undefined1 *)(param_1 + 0x252) = 1;
  atomic_notifier_call_chain(param_1 + 0xf0,1);
  return 0;
}



//------------------------------------------------------------
// msm_ssphy_qmp_notify_disconnect @ 00101850 size=148
// signature: undefined msm_ssphy_qmp_notify_disconnect(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ssphy_qmp_notify_disconnect(long param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x251);
  atomic_notifier_call_chain(param_1 + 0xf0,0,param_1);
  if ((*(byte *)(param_1 + 0x10) & 1) != 0) {
    if (cVar1 == '\0') {
      msm_ssphy_qmp_enable_clks(param_1,1);
    }
    writel_relaxed(0,*(long *)(param_1 + 0x188) + (ulong)*(uint *)(*(long *)(param_1 + 600) + 0xc));
    readl_relaxed(*(long *)(param_1 + 0x188) + (ulong)*(uint *)(*(long *)(param_1 + 600) + 0xc));
    if (cVar1 == '\0') {
      msm_ssphy_qmp_enable_clks(param_1,0);
    }
  }
  *(undefined1 *)(param_1 + 0x252) = 0;
  return 0;
}



//------------------------------------------------------------
// msm_ssphy_qmp_create_debugfs @ 001018e4 size=96
// signature: undefined msm_ssphy_qmp_create_debugfs(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

void msm_ssphy_qmp_create_debugfs(undefined8 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = ((long *)*param_1)[0xe];
  if (lVar1 == 0) {
    lVar1 = *(long *)*param_1;
  }
  uVar2 = debugfs_create_dir(lVar1,0);
  param_1[0x52] = uVar2;
  debugfs_create_file("phy_tune_reg",0x1a4,uVar2,param_1,msm_ssphy_qmp_tune_reg_fops);
  return;
}



//------------------------------------------------------------
// msm_ssusb_qmp_ldo_enable @ 00101944 size=892
// signature: undefined msm_ssusb_qmp_ldo_enable(void)
// callers: [msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init, msm_ssphy_qmp_remove]
//------------------------------------------------------------

int msm_ssusb_qmp_ldo_enable(undefined8 *param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (*(char *)((long)param_1 + 0x27d) != '\0') {
    return 0;
  }
  if (*(byte *)(param_1 + 0x4a) == param_2) {
    return 0;
  }
  *(bool *)(param_1 + 0x4a) = param_2 != 0;
  if (param_2 == 0) {
    if (param_1[0x3e] != 0) {
      iVar1 = regulator_disable();
      if (iVar1 != 0) {
        _dev_err(*param_1,"Unable to disable refgen\n");
      }
LAB_00101a78:
      iVar1 = regulator_set_voltage
                        (param_1[0x3e],*(undefined4 *)((long)param_1 + 0x1bc),
                         *(undefined4 *)((long)param_1 + 0x1c4));
      if (iVar1 != 0) {
        _dev_err(*param_1,"Unable to set (0) voltage for refgen:refgen\n");
      }
LAB_00101a8c:
      iVar1 = regulator_set_load(param_1[0x3e],0);
      if (iVar1 < 0) {
        _dev_err(*param_1,"Unable to set (0) HPM of refgen\n");
      }
    }
LAB_00101a9c:
    iVar1 = regulator_disable(param_1[0x3a]);
    if (iVar1 != 0) {
      pcVar2 = "Unable to disable %s\n";
LAB_00101bf8:
      _dev_err(*param_1,pcVar2,"core_ldo");
    }
    iVar1 = regulator_set_voltage
                      (param_1[0x3a],*(undefined4 *)(param_1 + 0x3b),*(undefined4 *)(param_1 + 0x3c)
                      );
    if (iVar1 != 0) {
LAB_00101b50:
      _dev_err(*param_1,"Unable to set voltage for %s\n","core_ldo");
    }
    iVar1 = regulator_set_load(param_1[0x3a],0);
    if (iVar1 < 0) {
      pcVar2 = "Unable to set LPM of %s\n";
LAB_00101bd0:
      _dev_err(*param_1,pcVar2,"core_ldo");
    }
    iVar1 = regulator_disable(param_1[0x35]);
    if (iVar1 != 0) {
      pcVar2 = "Unable to disable %s\n";
LAB_00101bb4:
      _dev_err(*param_1,pcVar2,&DAT_001038e7);
    }
    iVar1 = regulator_set_voltage
                      (param_1[0x35],
                       *(undefined4 *)((long)param_1 + (ulong)(param_2 != 0) * 4 + 0x1b0),
                       *(undefined4 *)(param_1 + 0x37));
    if (iVar1 != 0) {
LAB_00101b34:
      _dev_err(*param_1,"Unable to set voltage for %s\n",&DAT_001038e7);
    }
    iVar1 = regulator_set_load(param_1[0x35],0);
    if (-1 < iVar1) goto LAB_00101b08;
    pcVar2 = "Unable to set LPM of %s\n";
  }
  else {
    if ((((param_1[0x3d] != 0) && ((ulong)param_1[0x3d] < 0xfffffffffffff001)) &&
        (iVar1 = regulator_enable(), iVar1 != 0)) &&
       (_dev_err(*param_1,"err:%d fail to %s usb3_dp_phy_gdsc\n",iVar1,"enable"), iVar1 < 0)) {
      return iVar1;
    }
    iVar1 = regulator_set_load(param_1[0x35],*(undefined4 *)(param_1 + 0x39));
    if (-1 < iVar1) {
      iVar1 = regulator_set_voltage
                        (param_1[0x35],*(undefined4 *)((long)param_1 + 0x1b4),
                         *(undefined4 *)(param_1 + 0x37));
      if (iVar1 == 0) {
        iVar1 = regulator_enable(param_1[0x35]);
        if (iVar1 == 0) {
          iVar1 = regulator_set_load(param_1[0x3a],*(undefined4 *)((long)param_1 + 0x1e4));
          if (-1 < iVar1) {
            iVar1 = regulator_set_voltage
                              (param_1[0x3a],*(undefined4 *)((long)param_1 + 0x1dc),
                               *(undefined4 *)(param_1 + 0x3c));
            if (iVar1 == 0) {
              iVar1 = regulator_enable(param_1[0x3a]);
              if (iVar1 == 0) {
                if (param_1[0x3e] == 0) {
                  return 0;
                }
                iVar1 = regulator_set_load(param_1[0x3e],1200000);
                if (-1 < iVar1) {
                  iVar1 = regulator_set_voltage
                                    (param_1[0x3e],*(undefined4 *)(param_1 + 0x38),
                                     *(undefined4 *)((long)param_1 + 0x1c4));
                  if (iVar1 == 0) {
                    iVar1 = regulator_enable(param_1[0x3e]);
                    if (iVar1 == 0) {
                      return 0;
                    }
                    _dev_err(*param_1,"Unable to enable refgen:%d\n",iVar1);
                    goto LAB_00101a78;
                  }
                  _dev_err(*param_1,"Unable to set voltage for refgen:%d\n",iVar1);
                  goto LAB_00101a8c;
                }
                _dev_err(*param_1,"Unable to set HPM of refgen:%d\n",iVar1);
                goto LAB_00101a9c;
              }
              pcVar2 = "Unable to enable %s\n";
              goto LAB_00101bf8;
            }
            goto LAB_00101b50;
          }
          pcVar2 = "Unable to set HPM of %s\n";
          goto LAB_00101bd0;
        }
        pcVar2 = "Unable to enable %s\n";
        goto LAB_00101bb4;
      }
      goto LAB_00101b34;
    }
    pcVar2 = "Unable to set HPM of %s\n";
  }
  _dev_err(*param_1,pcVar2,&DAT_001038e7);
LAB_00101b08:
  iVar1 = 0;
  if (((param_1[0x3d] != 0) && ((ulong)param_1[0x3d] < 0xfffffffffffff001)) &&
     (iVar1 = regulator_disable(), iVar1 != 0)) {
    _dev_err(*param_1,"err:%d fail to %s usb3_dp_phy_gdsc\n",iVar1,"disable");
  }
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_ssphy_qmp_enable_clks @ 00101cc0 size=480
// signature: undefined msm_ssphy_qmp_enable_clks(void)
// callers: [msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init, msm_ssphy_qmp_remove, msm_ssphy_qmp_notify_disconnect]
//------------------------------------------------------------

void msm_ssphy_qmp_enable_clks(long param_1,ulong param_2)

{
  int iVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + 0x27d) == '\0') {
    cVar2 = *(char *)(param_1 + 0x251);
    if ((cVar2 == '\0') && ((param_2 & 1) != 0)) {
      lVar3 = *(long *)(param_1 + 0x1f8);
      if ((lVar3 != 0) &&
         ((iVar1 = clk_prepare(lVar3), iVar1 == 0 && (iVar1 = clk_enable(lVar3), iVar1 != 0)))) {
        clk_unprepare(lVar3);
      }
      lVar3 = *(long *)(param_1 + 0x200);
      if (((lVar3 != 0) && (iVar1 = clk_prepare(lVar3), iVar1 == 0)) &&
         (iVar1 = clk_enable(lVar3), iVar1 != 0)) {
        clk_unprepare(lVar3);
      }
      lVar3 = *(long *)(param_1 + 0x210);
      if (((lVar3 != 0) && (iVar1 = clk_prepare(lVar3), iVar1 == 0)) &&
         (iVar1 = clk_enable(lVar3), iVar1 != 0)) {
        clk_unprepare(lVar3);
      }
      uVar4 = *(undefined8 *)(param_1 + 0x208);
      iVar1 = clk_prepare(uVar4);
      if ((iVar1 == 0) && (iVar1 = clk_enable(uVar4), iVar1 != 0)) {
        clk_unprepare(uVar4);
      }
      lVar3 = *(long *)(param_1 + 0x218);
      if (((lVar3 != 0) && (iVar1 = clk_prepare(lVar3), iVar1 == 0)) &&
         (iVar1 = clk_enable(lVar3), iVar1 != 0)) {
        clk_unprepare(lVar3);
      }
      clk_set_parent(*(undefined8 *)(param_1 + 0x228),*(undefined8 *)(param_1 + 0x230));
      uVar4 = *(undefined8 *)(param_1 + 0x220);
      iVar1 = clk_prepare(uVar4);
      if ((iVar1 == 0) && (iVar1 = clk_enable(uVar4), iVar1 != 0)) {
        clk_unprepare(uVar4);
      }
      cVar2 = '\x01';
      *(undefined1 *)(param_1 + 0x251) = 1;
    }
    if ((cVar2 != '\0') && ((param_2 & 1) == 0)) {
      uVar4 = *(undefined8 *)(param_1 + 0x220);
      clk_disable(uVar4);
      clk_unprepare(uVar4);
      clk_set_parent(*(undefined8 *)(param_1 + 0x228),*(undefined8 *)(param_1 + 0x1f8));
      lVar3 = *(long *)(param_1 + 0x218);
      if (lVar3 != 0) {
        clk_disable(lVar3);
        clk_unprepare(lVar3);
      }
      uVar4 = *(undefined8 *)(param_1 + 0x208);
      clk_disable(uVar4);
      clk_unprepare(uVar4);
      lVar3 = *(long *)(param_1 + 0x210);
      if (lVar3 != 0) {
        clk_disable(lVar3);
        clk_unprepare(lVar3);
      }
      lVar3 = *(long *)(param_1 + 0x200);
      if (lVar3 != 0) {
        clk_disable(lVar3);
        clk_unprepare(lVar3);
      }
      lVar3 = *(long *)(param_1 + 0x1f8);
      if (lVar3 != 0) {
        clk_disable(lVar3);
        clk_unprepare(lVar3);
      }
      *(undefined1 *)(param_1 + 0x251) = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// msm_ssphy_modeled_d3_to_d0 @ 00101ea0 size=256
// signature: undefined msm_ssphy_modeled_d3_to_d0(void)
// callers: [msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init]
//------------------------------------------------------------

void msm_ssphy_modeled_d3_to_d0(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  
  if (*(char *)((long)param_1 + 0x27d) != '\0') {
    lVar6 = *(long *)param_1[0x50];
    iVar5 = __pm_runtime_resume(lVar6,4);
    if (iVar5 < 0) {
      piVar1 = (int *)(lVar6 + 0x1f8);
      iVar5 = *(int *)(lVar6 + 0x1f8);
      do {
        if (iVar5 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar5) goto LAB_00101f24;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar5 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00101f24:
        bVar4 = iVar5 != iVar2;
        iVar5 = iVar2;
      } while (bVar4);
    }
    else {
      lVar6 = *(long *)(param_1[0x50] + 8);
      iVar5 = __pm_runtime_resume(lVar6,4);
      if (-1 < iVar5) {
        return;
      }
      piVar1 = (int *)(lVar6 + 0x1f8);
      iVar5 = *(int *)(lVar6 + 0x1f8);
      do {
        if (iVar5 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar5) goto LAB_00101f80;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar5 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00101f80:
        bVar4 = iVar5 != iVar2;
        iVar5 = iVar2;
      } while (bVar4);
    }
    _dev_err(*param_1,"Failed to change power state from d3 to d0\n");
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00101fc8 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_ssusb_qmp_enable_autonomous, msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init, msm_ssphy_qmp_notify_disconnect]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101fe0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10201c,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 0010204c size=124
// signature: undefined readl_relaxed(void)
// callers: [msm_ssusb_qmp_enable_autonomous, msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_tune_reg_show, msm_ssphy_qmp_init, msm_ssphy_qmp_notify_disconnect]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102094,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// msm_ssusb_qmp_enable_autonomous @ 001020c8 size=344
// signature: undefined msm_ssusb_qmp_enable_autonomous(void)
// callers: [msm_ssphy_qmp_set_suspend]
//------------------------------------------------------------

void msm_ssusb_qmp_enable_autonomous(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = *(long *)(param_1 + 600);
  uVar4 = (ulong)*(uint *)(lVar3 + 4);
  if (param_2 == 0) {
    if (*(uint *)(param_1 + 0x278) < 2) {
      if (*(long *)(param_1 + 400) != 0) {
        writel_relaxed(0);
      }
      lVar3 = *(long *)(param_1 + 0x198);
      if (lVar3 != 0) {
LAB_001021c4:
        writel_relaxed(1,lVar3);
      }
    }
    else if (*(uint *)(param_1 + 0x278) == 2) {
      lVar3 = *(long *)(param_1 + 0x188) + (ulong)*(uint *)(lVar3 + 0x30);
      goto LAB_001021c4;
    }
    writel_relaxed(0,*(long *)(param_1 + 0x188) + uVar4);
    writel_relaxed(1,*(long *)(param_1 + 0x188) + (ulong)*(uint *)(*(long *)(param_1 + 600) + 8));
    DataSynchronizationBarrier(3,2,0);
    lVar3 = *(long *)(param_1 + 0x188);
    uVar2 = *(uint *)(*(long *)(param_1 + 600) + 8);
  }
  else {
    writel_relaxed(1,*(long *)(param_1 + 0x188) + (ulong)*(uint *)(lVar3 + 8));
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_1 + 0x188) + (ulong)*(uint *)(*(long *)(param_1 + 600) + 8));
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x188) + uVar4);
    uVar2 = 0x11;
    if ((*(uint *)(param_1 + 0x10) & 2) != 0) {
      uVar2 = 3;
    }
    writel_relaxed(uVar2 | uVar1 & 0xffffffec,*(long *)(param_1 + 0x188) + uVar4);
    if (*(uint *)(param_1 + 0x278) < 2) {
      if (*(long *)(param_1 + 400) != 0) {
        writel_relaxed(1);
      }
      lVar3 = *(long *)(param_1 + 0x198);
      if (lVar3 == 0) {
        return;
      }
      goto LAB_00102208;
    }
    if (*(uint *)(param_1 + 0x278) != 2) {
      return;
    }
    lVar3 = *(long *)(param_1 + 0x188);
    uVar2 = *(uint *)(*(long *)(param_1 + 600) + 0x30);
  }
  lVar3 = lVar3 + (ulong)uVar2;
LAB_00102208:
  writel_relaxed(0,lVar3);
  return;
}



//------------------------------------------------------------
// msm_ssphy_qmp_tune_reg_write @ 00102224 size=596
// signature: undefined msm_ssphy_qmp_tune_reg_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong msm_ssphy_qmp_tune_reg_write(long param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  void *__dest;
  undefined8 *puVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  uint *puVar10;
  undefined8 local_90;
  char local_88 [64];
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_88[0x30] = '\0';
  local_88[0x31] = '\0';
  local_88[0x32] = '\0';
  local_88[0x33] = '\0';
  local_88[0x34] = '\0';
  local_88[0x35] = '\0';
  local_88[0x36] = '\0';
  local_88[0x37] = '\0';
  local_88[0x38] = '\0';
  local_88[0x39] = '\0';
  local_88[0x3a] = '\0';
  local_88[0x3b] = '\0';
  local_88[0x3c] = '\0';
  local_88[0x3d] = '\0';
  local_88[0x3e] = '\0';
  local_88[0x3f] = '\0';
  local_88[0x20] = '\0';
  local_88[0x21] = '\0';
  local_88[0x22] = '\0';
  local_88[0x23] = '\0';
  local_88[0x24] = '\0';
  local_88[0x25] = '\0';
  local_88[0x26] = '\0';
  local_88[0x27] = '\0';
  local_88[0x28] = '\0';
  local_88[0x29] = '\0';
  local_88[0x2a] = '\0';
  local_88[0x2b] = '\0';
  local_88[0x2c] = '\0';
  local_88[0x2d] = '\0';
  local_88[0x2e] = '\0';
  local_88[0x2f] = '\0';
  lVar8 = *(long *)(*(long *)(param_1 + 0xd8) + 0x80);
  uVar5 = param_3;
  if (0x3e < param_3) {
    uVar5 = 0x3f;
  }
  local_88[0x10] = '\0';
  local_88[0x11] = '\0';
  local_88[0x12] = '\0';
  local_88[0x13] = '\0';
  local_88[0x14] = '\0';
  local_88[0x15] = '\0';
  local_88[0x16] = '\0';
  local_88[0x17] = '\0';
  local_88[0x18] = '\0';
  local_88[0x19] = '\0';
  local_88[0x1a] = '\0';
  local_88[0x1b] = '\0';
  local_88[0x1c] = '\0';
  local_88[0x1d] = '\0';
  local_88[0x1e] = '\0';
  local_88[0x1f] = '\0';
  puVar10 = *(uint **)(lVar8 + 0x298);
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\0';
  local_88[4] = '\0';
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_88[8] = '\0';
  local_88[9] = '\0';
  local_88[10] = '\0';
  local_88[0xb] = '\0';
  local_88[0xc] = '\0';
  local_88[0xd] = '\0';
  local_88[0xe] = '\0';
  local_88[0xf] = '\0';
  uVar2 = *(uint *)(lVar8 + 0x2a0);
  uVar9 = (ulong)uVar2;
  local_90 = 0;
  __check_object_size(local_88,uVar5,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar7 <= 0x8000000000 - uVar5) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar3 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    uVar5 = __arch_copy_from_user(puVar6,local_88,param_2 & 0xff7fffffffffffff,uVar5);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
  }
  if (uVar5 == 0) {
    iVar4 = sscanf(local_88,"%x, %x",(uint *)&local_90,(uint *)((ulong)&local_90 | 4));
    if (iVar4 == 2) {
      if (0 < (int)uVar2) {
        do {
          if (*puVar10 == (uint)local_90) {
            *(undefined8 *)puVar10 = local_90;
            goto LAB_0010240c;
          }
          puVar10 = puVar10 + 2;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      uVar1 = uVar2 + 1;
      __dest = (void *)__kmalloc(-(ulong)(uVar1 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar1 << 3,
                                 0xdc0);
      if (__dest == (void *)0x0) {
        param_3 = 0xfffffffffffffff4;
      }
      else {
        if (*(long *)(lVar8 + 0x298) != 0) {
          memcpy(__dest,*(void **)(lVar8 + 0x298),(long)(int)uVar2 << 3);
          kfree(*(undefined8 *)(lVar8 + 0x298));
        }
        *(undefined8 *)((long)__dest + (long)(int)uVar2 * 8) = local_90;
        *(void **)(lVar8 + 0x298) = __dest;
        *(uint *)(lVar8 + 0x2a0) = uVar1;
      }
    }
    else {
      _printk(&DAT_001036ef);
      param_3 = 0xffffffffffffffea;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
LAB_0010240c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_ssphy_qmp_tune_reg_open @ 00102494 size=48
// signature: undefined msm_ssphy_qmp_tune_reg_open(void)
// callers: []
//------------------------------------------------------------

void msm_ssphy_qmp_tune_reg_open(long param_1,undefined8 param_2)

{
  single_open(param_2,msm_ssphy_qmp_tune_reg_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// msm_ssphy_qmp_tune_reg_show @ 001024c8 size=140
// signature: undefined msm_ssphy_qmp_tune_reg_show(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ssphy_qmp_tune_reg_show(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  uint *puVar4;
  
  lVar2 = *(long *)(param_1 + 0x80);
  if (0 < *(int *)(lVar2 + 0x2a0)) {
    lVar3 = 0;
    puVar4 = *(uint **)(lVar2 + 0x298);
    do {
      uVar1 = readl_relaxed(*(long *)(lVar2 + 0x188) + (ulong)*puVar4);
      seq_printf(param_1,"reg[0x%04x] = 0x%08x(0x%08x)\n",*puVar4,uVar1,puVar4[1]);
      lVar3 = lVar3 + 1;
      puVar4 = puVar4 + 2;
    } while (lVar3 < *(int *)(lVar2 + 0x2a0));
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102584 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_ssphy_qmp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001025b4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_ssphy_qmp_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00105000 size=1
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
// platform_driver_unregister @ 00105008 size=1
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
// devm_kmalloc @ 00105010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00105018 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00105020 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_attach_by_id @ 00105028 size=1
// signature: undefined dev_pm_domain_attach_by_id(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_attach_by_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_detach @ 00105030 size=1
// signature: undefined dev_pm_domain_detach(void)
// callers: [msm_ssphy_qmp_probe, msm_ssphy_qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00105038 size=1
// signature: undefined devm_clk_get(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_round_rate @ 00105040 size=1
// signature: undefined clk_round_rate(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 00105048 size=1
// signature: undefined clk_set_rate(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 00105050 size=1
// signature: undefined of_property_match_string(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105058 size=1
// signature: undefined _dev_err(void)
// callers: [msm_ssphy_modeled_d3_to_d0, msm_ssusb_qmp_ldo_enable, msm_ssphy_qmp_probe, msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init, msm_ssphy_qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 00105060 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00105068 size=1
// signature: undefined of_get_property(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00105078 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00105080 size=1
// signature: undefined devm_ioremap(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00105088 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105090 size=1
// signature: undefined of_find_property(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_phy_dev @ 00105098 size=1
// signature: undefined usb_add_phy_dev(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_phy_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 001050a0 size=1
// signature: undefined devm_regulator_get(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_optional @ 001050a8 size=1
// signature: undefined devm_regulator_get_optional(void)
// callers: [msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050b0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_ssphy_qmp_tune_reg_write, msm_ssphy_qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050b8 size=1
// signature: undefined kfree(void)
// callers: [msm_ssphy_qmp_tune_reg_write, msm_ssphy_qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001050c0 size=1
// signature: undefined debugfs_remove(void)
// callers: [msm_ssphy_qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_phy @ 001050c8 size=1
// signature: undefined usb_remove_phy(void)
// callers: [msm_ssphy_qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_phy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001050d0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init, msm_ssphy_qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 001050d8 size=1
// signature: undefined reset_control_assert(void)
// callers: [msm_ssphy_qmp_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 001050e0 size=1
// signature: undefined reset_control_deassert(void)
// callers: [msm_ssphy_qmp_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001050e8 size=1
// signature: undefined _dev_info(void)
// callers: [msm_ssphy_qmp_set_suspend, msm_ssphy_qmp_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001050f0 size=1
// signature: undefined usleep_range_state(void)
// callers: [msm_ssphy_qmp_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_call_chain @ 001050f8 size=1
// signature: undefined atomic_notifier_call_chain(void)
// callers: [msm_ssphy_qmp_notify_connect, msm_ssphy_qmp_notify_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00105100 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [msm_ssphy_qmp_create_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00105108 size=1
// signature: undefined debugfs_create_file(void)
// callers: [msm_ssphy_qmp_create_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00105110 size=1
// signature: undefined regulator_enable(void)
// callers: [msm_ssusb_qmp_ldo_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00105118 size=1
// signature: undefined regulator_set_load(void)
// callers: [msm_ssusb_qmp_ldo_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00105120 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [msm_ssusb_qmp_ldo_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00105128 size=1
// signature: undefined regulator_disable(void)
// callers: [msm_ssusb_qmp_ldo_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00105130 size=1
// signature: undefined clk_prepare(void)
// callers: [msm_ssphy_qmp_enable_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00105138 size=1
// signature: undefined clk_enable(void)
// callers: [msm_ssphy_qmp_enable_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00105140 size=1
// signature: undefined clk_unprepare(void)
// callers: [msm_ssphy_qmp_enable_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_parent @ 00105148 size=1
// signature: undefined clk_set_parent(void)
// callers: [msm_ssphy_qmp_enable_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00105150 size=1
// signature: undefined clk_disable(void)
// callers: [msm_ssphy_qmp_enable_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00105158 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [msm_ssphy_modeled_d3_to_d0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00105168 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00105170 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00105178 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00105180 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00105188 size=1
// signature: undefined __check_object_size(void)
// callers: [msm_ssphy_qmp_tune_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00105198 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [msm_ssphy_qmp_tune_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 001051a0 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [msm_ssphy_qmp_tune_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001051a8 size=1
// signature: undefined __kmalloc(void)
// callers: [msm_ssphy_qmp_tune_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001051b0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [msm_ssphy_qmp_tune_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001051b8 size=1
// signature: undefined _printk(void)
// callers: [msm_ssphy_qmp_tune_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001051c8 size=1
// signature: undefined single_open(void)
// callers: [msm_ssphy_qmp_tune_reg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001051d0 size=1
// signature: undefined seq_printf(void)
// callers: [msm_ssphy_qmp_tune_reg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



