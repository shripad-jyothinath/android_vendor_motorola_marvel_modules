// Decompiled by Ghidra 12.2
// Program: qcom_spss.ko
// Image base: 00100000

//------------------------------------------------------------
// get_spss_image_size @ 0010052c size=156
// signature: undefined get_spss_image_size(void)
// callers: []
//------------------------------------------------------------

int get_spss_image_size(int param_1)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  
  uVar1 = 0x68000000000713;
  if (arm64_use_ng_mappings != '\0') {
    uVar1 = 0x68000000000f13;
  }
  lVar3 = ioremap_prot(param_1 + 0x1008,4,uVar1);
  if (lVar3 == 0) {
    _printk(&DAT_00101b22);
    iVar4 = -0x16;
  }
  else {
    uVar2 = readl_relaxed();
    iounmap(lVar3);
    iVar4 = uVar2 << 2;
    if ((uVar2 & 0x3ff) != 0) {
      _printk(&DAT_00101b94);
      iVar4 = -0xe;
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// readl_relaxed @ 001005c8 size=124
// signature: undefined readl_relaxed(void)
// callers: [get_spss_image_size, read_sp2cl_debug_registers, spss_load]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100610,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_spss_set_fw_name @ 00100648 size=108
// signature: undefined qcom_spss_set_fw_name(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_spss_set_fw_name(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = kstrdup_const(param_2,0xcc0);
  if (lVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    mutex_lock(param_1 + 0x3d8);
    kfree(*(undefined8 *)(param_1 + 0x20));
    *(long *)(param_1 + 0x20) = lVar1;
    mutex_unlock(param_1 + 0x3d8);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_spss_probe @ 001006b8 size=1200
// signature: undefined qcom_spss_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_spss_probe(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  long local_f8;
  long lStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  long local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  puVar1 = param_1 + 2;
  local_48 = *(long *)(lVar7 + 0x638);
  puVar5 = (undefined8 *)of_device_get_match_data(puVar1);
  if (puVar5 == (undefined8 *)0x0) {
    uVar6 = 0xffffffea;
    goto LAB_00100b00;
  }
  uVar6 = qcom_scm_is_available();
  if ((uVar6 & 1) == 0) {
    uVar6 = 0xfffffdfb;
    goto LAB_00100b00;
  }
  lVar7 = rproc_alloc(puVar1,*param_1,spss_ops,*puVar5,0x1b0);
  if (lVar7 == 0) {
    _dev_err(puVar1,"unable to allocate remoteproc\n");
    uVar6 = 0xfffffff4;
    goto LAB_00100b00;
  }
  plVar10 = *(long **)(lVar7 + 0x28);
  *plVar10 = (long)puVar1;
  plVar10[1] = lVar7;
  uVar3 = *(undefined4 *)(puVar5 + 1);
  *(undefined4 *)(plVar10 + 6) = 0;
  *(undefined4 *)(plVar10 + 5) = uVar3;
  __init_swait_queue_head(plVar10 + 7,"&x->wait",&init_completion___key);
  param_1[0x15] = plVar10;
  *(undefined1 *)(lVar7 + 0x4f1) = *(undefined1 *)(puVar5 + 3);
  plVar10[0xf] = puVar5[4];
  *(undefined1 *)(lVar7 + 0x4c4) = 1;
  rproc_coredump_set_elf_info(lVar7,1,0);
  lVar11 = *plVar10;
  device_set_wakeup_capable(lVar11,1);
  uVar8 = device_wakeup_enable(lVar11);
  uVar6 = uVar8 & 0xffffffff;
  if ((int)uVar8 == 0) {
    uVar9 = platform_get_resource_byname(param_1,0x200,"rmb_general_purpose");
    uVar6 = devm_ioremap_resource(puVar1,uVar9);
    plVar10[0x34] = uVar6;
    if (uVar6 < 0xfffffffffffff001) {
      uVar9 = platform_get_resource_byname(param_1,0x200,"sp2soc_irq_status");
      uVar8 = devm_ioremap_resource(puVar1,uVar9);
      plVar10[0x2f] = uVar8;
      if (uVar8 < 0xfffffffffffff001) {
        uVar9 = platform_get_resource_byname(param_1,0x200,"sp2soc_irq_clr");
        uVar8 = devm_ioremap_resource(puVar1,uVar9);
        plVar10[0x30] = uVar8;
        if (uVar8 < 0xfffffffffffff001) {
          uVar9 = platform_get_resource_byname(param_1,0x200,"sp2soc_irq_mask");
          uVar8 = devm_ioremap_resource(puVar1,uVar9);
          plVar10[0x31] = uVar8;
          if (uVar8 < 0xfffffffffffff001) {
            uVar9 = platform_get_resource_byname(param_1,0x200,"rmb_err");
            uVar8 = devm_ioremap_resource(puVar1,uVar9);
            plVar10[0x32] = uVar8;
            if (uVar8 < 0xfffffffffffff001) {
              uVar9 = platform_get_resource_byname(param_1,0x200,"rmb_err_spare2");
              uVar8 = devm_ioremap_resource(puVar1,uVar9);
              plVar10[0x33] = uVar8;
              if (uVar8 < 0xfffffffffffff001) {
                uVar4 = of_property_read_variable_u32_array
                                  (param_1[0x5f],"qcom,spss-scsr-bits",plVar10 + 0x35,2,0);
                if (-1 < (int)uVar4) {
                  uVar4 = 0;
                }
                uVar6 = (ulong)uVar4;
                goto joined_r0x00100abc;
              }
            }
          }
        }
      }
      uVar6 = uVar8 & 0xffffffff;
      uVar4 = (uint)uVar8;
    }
    else {
      uVar4 = (uint)uVar6;
    }
joined_r0x00100abc:
    if (uVar4 == 0) {
      uVar3 = 6;
      if ((*(uint *)plVar10[0x34] & 1) != 0) {
        uVar3 = 0;
      }
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      local_c8 = 0;
      uStack_c0 = 0;
      local_d8 = 0;
      uStack_d0 = 0;
      *(undefined4 *)(lVar7 + 0x3cc) = uVar3;
      local_e8 = 0;
      uStack_e0 = 0;
      local_f8 = 0;
      lStack_f0 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      iVar2 = __of_parse_phandle_with_args
                        (*(undefined8 *)(*plVar10 + 0x2e8),"memory-region",0,0,0,&local_98);
      if ((iVar2 == 0) && (local_98 != 0)) {
        uVar8 = of_address_to_resource(local_98,0,&local_f8);
        uVar6 = uVar8 & 0xffffffff;
        if ((int)uVar8 == 0) {
          plVar10[10] = local_f8;
          plVar10[0xb] = local_f8;
          plVar10[0xd] = (lStack_f0 - local_f8) + 1;
          lVar11 = devm_ioremap_wc(*plVar10);
          plVar10[0xc] = lVar11;
          if (lVar11 == 0) {
            _dev_err(*plVar10,"unable to map memory region: %pa+%zx\n",&local_f8,plVar10[0xd]);
            uVar6 = 0xfffffff0;
          }
          else {
            uVar8 = spss_init_clock(plVar10);
            uVar6 = uVar8 & 0xffffffff;
            if ((int)uVar8 == 0) {
              uVar8 = init_regulator(*plVar10,plVar10 + 3);
              uVar6 = uVar8 & 0xffffffff;
              if ((int)uVar8 == 0) {
                lVar11 = of_find_property(param_1[0x5f],"qcom,signal-aop",0);
                if (lVar11 != 0) {
                  uVar8 = qmp_get(*plVar10);
                  uVar6 = 0;
                  plVar10[0x10] = uVar8;
                  if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) goto LAB_00100ae0;
                }
                qcom_add_glink_spss_subdev(lVar7,plVar10 + 0x11);
                qcom_add_ssr_subdev(lVar7,plVar10 + 0x1f,puVar5[2]);
                uVar6 = qcom_add_sysmon_subdev(lVar7,puVar5[2],0xffffffea);
                plVar10[0x2e] = uVar6;
                if (uVar6 < 0xfffffffffffff001) {
                  *(undefined4 *)plVar10[0x31] = 0xffffffff;
                  uVar3 = platform_get_irq(param_1,0);
                  *(undefined4 *)(plVar10 + 0xe) = uVar3;
                  uVar4 = devm_request_threaded_irq
                                    (puVar1,uVar3,0,spss_generic_handler,0x2001,"generic-irq",
                                     plVar10);
                  if (uVar4 == 0) {
                    uVar8 = rproc_add(lVar7);
                    uVar6 = uVar8 & 0xffffffff;
                    if ((int)uVar8 == 0) goto LAB_00100b00;
                  }
                  else {
                    uVar6 = (ulong)uVar4;
                    _dev_err(puVar1,"failed to acquire generic IRQ\n");
                  }
                  qcom_remove_sysmon_subdev(plVar10[0x2e]);
                }
                else {
                  _dev_err(*plVar10,"failed to add sysmon subdevice\n");
                  uVar6 = 0;
                }
              }
            }
          }
        }
      }
      else {
        _dev_err(*plVar10,"no memory-region specified\n");
        uVar6 = 0xffffffea;
      }
    }
LAB_00100ae0:
    lVar11 = *plVar10;
    device_wakeup_disable(lVar11);
    device_set_wakeup_capable(lVar11,0);
  }
  rproc_free(lVar7);
LAB_00100b00:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_spss_remove @ 00100b6c size=128
// signature: undefined qcom_spss_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_spss_remove(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  rproc_del(puVar2[1]);
  if (puVar2[0x19] != 0) {
    rproc_remove_subdev(puVar2[1],puVar2 + 0x11);
    kfree_const(puVar2[0x17]);
  }
  qcom_remove_ssr_subdev(puVar2[1],puVar2 + 0x1f);
  qcom_remove_sysmon_subdev(puVar2[0x2e]);
  uVar1 = *puVar2;
  device_wakeup_disable(uVar1);
  device_set_wakeup_capable(uVar1,0);
  rproc_free(puVar2[1]);
  return 0;
}



//------------------------------------------------------------
// spss_init_clock @ 00100bec size=112
// signature: undefined spss_init_clock(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

ulong spss_init_clock(undefined8 *param_1)

{
  ulong uVar1;
  
  uVar1 = devm_clk_get(*param_1,&DAT_00101c61);
  param_1[2] = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = 0;
  }
  else if ((int)uVar1 == -0x205) {
    uVar1 = 0xfffffdfb;
  }
  else {
    _dev_err(*param_1,"failed to get xo clock\n");
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// init_regulator @ 00100c5c size=300
// signature: undefined init_regulator(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

ulong init_regulator(long param_1,ulong *param_2)

{
  ulong uVar1;
  long lVar2;
  undefined4 local_7c;
  undefined8 local_78;
  char local_70 [56];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_7c = 0;
  local_70[0x30] = '\0';
  local_70[0x31] = '\0';
  local_70[0x20] = '\0';
  local_70[0x21] = '\0';
  local_70[0x22] = '\0';
  local_70[0x23] = '\0';
  local_70[0x24] = '\0';
  local_70[0x25] = '\0';
  local_70[0x26] = '\0';
  local_70[0x27] = '\0';
  local_70[0x28] = '\0';
  local_70[0x29] = '\0';
  local_70[0x2a] = '\0';
  local_70[0x2b] = '\0';
  local_70[0x2c] = '\0';
  local_70[0x2d] = '\0';
  local_70[0x2e] = '\0';
  local_70[0x2f] = '\0';
  local_70[0x10] = '\0';
  local_70[0x11] = '\0';
  local_70[0x12] = '\0';
  local_70[0x13] = '\0';
  local_70[0x14] = '\0';
  local_70[0x15] = '\0';
  local_70[0x16] = '\0';
  local_70[0x17] = '\0';
  local_70[0x18] = '\0';
  local_70[0x19] = '\0';
  local_70[0x1a] = '\0';
  local_70[0x1b] = '\0';
  local_70[0x1c] = '\0';
  local_70[0x1d] = '\0';
  local_70[0x1e] = '\0';
  local_70[0x1f] = '\0';
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_78 = 0;
  uVar1 = devm_regulator_get(param_1,&DAT_00101cd1);
  *param_2 = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    snprintf(local_70,0x32,"%s-uV-uA","cx");
    lVar2 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),local_70,&local_7c);
    if (lVar2 == 0) {
      uVar1 = 0xffffffea;
    }
    else {
      uVar1 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),local_70,&local_78,2,0);
      if ((int)uVar1 < 0) {
        uVar1 = uVar1 & 0xffffffff;
        _dev_err(param_1,"Failed to read uV-uA value(rc:%d)\n",uVar1);
      }
      else {
        if ((int)local_78 != 0) {
          *(int *)(param_2 + 1) = (int)local_78;
        }
        if (local_78._4_4_ == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = 0;
          *(int *)((long)param_2 + 0xc) = local_78._4_4_;
        }
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_add_glink_spss_subdev @ 00100d88 size=144
// signature: undefined qcom_add_glink_spss_subdev(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

void qcom_add_glink_spss_subdev(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = of_get_child_by_name(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),"glink-edge");
  *(long *)(param_2 + 0x40) = lVar1;
  if (lVar1 != 0) {
    lVar1 = kstrdup_const(&DAT_00101b43,0xcc0);
    *(long *)(param_2 + 0x30) = lVar1;
    if (lVar1 != 0) {
      *(long *)(param_2 + 0x38) = param_1 + 0x38;
      *(code **)(param_2 + 0x18) = glink_spss_subdev_start;
      *(code **)(param_2 + 0x20) = glink_spss_subdev_stop;
      *(code **)(param_2 + 0x28) = glink_spss_subdev_unprepare;
      rproc_add_subdev(param_1,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// spss_generic_handler @ 00100e1c size=496
// signature: undefined spss_generic_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 spss_generic_handler(undefined8 param_1,undefined8 *param_2)

{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = *(uint *)param_2[0x2f];
  if ((uVar2 >> ((ulong)*(uint *)(param_2 + 0x35) & 0x3f) & 1) != 0) {
    if (*(int *)param_2[0x33] == 0x44554d50) {
      _dev_err(*param_2,"wdog bite received from %s!\n",*(undefined8 *)(param_2[1] + 0x18));
      pcVar1 = "enabled and kick reovery process";
      if (*(char *)(param_2[1] + 0x4c4) != '\0') {
        pcVar1 = "disabled and lead to device crash";
      }
      _dev_err(*param_2,"rproc recovery state: %s\n",pcVar1);
      if (*(char *)(param_2[1] + 0x4c4) != '\0') {
        *(undefined4 *)(param_2[1] + 0x3cc) = 3;
                    /* WARNING: Subroutine does not return */
        panic("Panicking, remoterpoc %s crashed\n",*(undefined8 *)(param_2[1] + 0x18));
      }
      *(int *)param_2[0x30] = (int)(1L << ((ulong)*(uint *)(param_2 + 0x35) & 0x3f));
      rproc_report_crash(param_2[1],1);
    }
    else if (*(int *)param_2[0x33] == 0) {
      _dev_info(*param_2,"SW_INIT_DONE - 2nd phase loading [%s] completed ok\n",
                *(undefined8 *)(param_2[1] + 0x18));
      *(int *)param_2[0x30] = (int)(1L << ((ulong)*(uint *)(param_2 + 0x35) & 0x3f));
      complete(param_2 + 6);
    }
    else {
      _dev_info(*param_2,"SW_INIT_DONE - ERROR [%s] [0x%x].\n",*(undefined8 *)(param_2[1] + 0x18));
      _dev_err(*param_2,
               "spare0 register: 0x%08x, spare1 register: 0x%08x, spare2 register: 0x%08x\n",
               *(undefined4 *)(param_2[0x33] + -8),*(undefined4 *)(param_2[0x33] + -4),
               *(undefined4 *)param_2[0x33]);
      *(int *)param_2[0x30] = (int)(1L << ((ulong)*(uint *)(param_2 + 0x35) & 0x3f));
    }
  }
  if ((uVar2 >> ((ulong)*(uint *)((long)param_2 + 0x1ac) & 0x3f) & 1) != 0) {
    if (*(int *)param_2[0x32] == 0) {
      _dev_info(*param_2,"PBL_DONE - 1st phase loading [%s] completed ok\n",
                *(undefined8 *)(param_2[1] + 0x18));
    }
    else {
      _dev_err(*param_2,
               "PBL error status register: 0x%08x, spare0 register: 0x%08x, spare1 register: 0x%08x, spare2 register: 0x%08x\n"
               ,*(int *)param_2[0x32],*(undefined4 *)(param_2[0x33] + -8),
               *(undefined4 *)(param_2[0x33] + -4),*(undefined4 *)param_2[0x33]);
    }
    *(int *)param_2[0x30] = (int)(1L << ((ulong)*(uint *)((long)param_2 + 0x1ac) & 0x3f));
  }
  return 1;
}



//------------------------------------------------------------
// spss_start @ 00101010 size=436
// signature: undefined spss_start(void)
// callers: []
//------------------------------------------------------------

int spss_start(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  uVar3 = puVar2[2];
  iVar1 = clk_prepare(uVar3);
  if (iVar1 == 0) {
    iVar1 = clk_enable(uVar3);
    if (iVar1 == 0) {
      puVar4 = puVar2 + 3;
      regulator_set_voltage(*puVar4,*(undefined4 *)(puVar2 + 4),0x7fffffff);
      regulator_set_load(*puVar4,*(undefined4 *)((long)puVar2 + 0x24));
      iVar1 = regulator_enable(*puVar4);
      if (iVar1 == 0) {
        if ((puVar2[0x10] == 0) ||
           (iVar1 = qcom_rproc_toggle_load_state(puVar2[0x10],puVar2[0xf],1), iVar1 == 0)) {
          iVar1 = qcom_scm_pas_auth_and_reset(*(undefined4 *)(puVar2 + 5));
          if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
            panic("Panicking, auth and reset failed for remoteproc %s\n",
                  *(undefined8 *)(param_1 + 0x18));
          }
          *(uint *)puVar2[0x31] =
               ~((uint)(1L << ((ulong)*(uint *)((long)puVar2 + 0x1ac) & 0x3f)) |
                (uint)(1L << ((ulong)*(uint *)(puVar2 + 0x35) & 0x3f)));
          _dev_err(*puVar2,"trying to read spss registers\n");
          iVar1 = wait_for_completion_timeout(puVar2 + 6,0x4e2);
          read_sp2cl_debug_registers(puVar2);
          if ((*(char *)(param_1 + 0x4c4) != '\0') && (iVar1 == 0)) {
                    /* WARNING: Subroutine does not return */
            panic("Panicking, %s start timed out\n",*(undefined8 *)(param_1 + 0x18));
          }
          if (iVar1 == 0) {
            _dev_err(*puVar2,"start timed out\n");
            if ((puVar2[0x10] != 0) &&
               (iVar1 = qcom_rproc_toggle_load_state(puVar2[0x10],puVar2[0xf],0), iVar1 != 0)) {
              _dev_err(*puVar2,"Failed to signal AOP about spss status [%d]\n",iVar1);
            }
            iVar1 = -0x6e;
          }
          else {
            iVar1 = 0;
          }
          disable_regulator(puVar4);
        }
        else {
          _dev_err(*puVar2,"Failed to signal AOP about spss status [%d]\n",iVar1);
          iVar1 = 0;
        }
      }
      uVar3 = puVar2[2];
      clk_disable(uVar3);
    }
    clk_unprepare(uVar3);
  }
  return iVar1;
}



//------------------------------------------------------------
// spss_stop @ 001011c8 size=112
// signature: undefined spss_stop(void)
// callers: []
//------------------------------------------------------------

undefined8 spss_stop(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x28);
  iVar1 = qcom_scm_pas_shutdown(*(undefined4 *)(lVar2 + 0x28));
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    panic("Panicking, remoteproc %s failed to shutdown.\n",*(undefined8 *)(param_1 + 0x18));
  }
  **(undefined4 **)(lVar2 + 0x188) = 0xffffffff;
  if (*(long *)(lVar2 + 0x80) != 0) {
    qcom_rproc_toggle_load_state(*(long *)(lVar2 + 0x80),*(undefined8 *)(lVar2 + 0x78),0);
  }
  *(undefined4 *)(param_1 + 0x3cc) = 0;
  *(undefined4 *)(lVar2 + 0x30) = 0;
  return 0;
}



//------------------------------------------------------------
// spss_attach @ 0010123c size=532
// signature: undefined spss_attach(void)
// callers: []
//------------------------------------------------------------

uint spss_attach(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  long lVar6;
  
  puVar5 = *(undefined8 **)(param_1 + 0x28);
  uVar1 = *(uint *)puVar5[0x32];
  if (uVar1 >> 0x18 == 0xef) {
    _dev_err(*puVar5,"PBL error detected\n");
  }
  else {
    uVar4 = 1L << ((ulong)*(uint *)(puVar5 + 0x35) & 0x3f);
    uVar1 = (uint)uVar4;
    if ((uVar4 & *(uint *)puVar5[0x2f]) == 0 || *(int *)puVar5[0x33] != 0x44554d50) {
      if (puVar5[0x10] == 0) {
LAB_001012c4:
        *(uint *)puVar5[0x31] =
             ~((uint)(1L << ((ulong)*(uint *)((long)puVar5 + 0x1ac) & 0x3f)) | uVar1);
        iVar2 = wait_for_completion_timeout(puVar5 + 6,0x4e2);
        read_sp2cl_debug_registers(puVar5);
        if ((*(char *)(param_1 + 0x4c4) != '\0') && (iVar2 == 0)) {
          _dev_err(*puVar5,"%d ms timeout poked\n",5000);
                    /* WARNING: Subroutine does not return */
          panic("Panicking, %s attach timed out\n",*(undefined8 *)(param_1 + 0x18));
        }
        if (iVar2 != 0) {
          return 0;
        }
        _dev_err(*puVar5,"recovery disabled (after timeout)\n");
        if (puVar5[0x10] != 0) {
          qcom_rproc_toggle_load_state(puVar5[0x10],puVar5[0xf],0);
        }
        return 0xffffff92;
      }
      uVar1 = qcom_rproc_toggle_load_state(puVar5[0x10],puVar5[0xf],1);
      if (uVar1 == 0) {
        uVar1 = (uint)(1L << ((ulong)*(uint *)(puVar5 + 0x35) & 0x3f));
        goto LAB_001012c4;
      }
      _dev_err(*puVar5,"Failed to signal AOP about spss status [%d]\n",uVar1);
      lVar6 = *(long *)(param_1 + 0x28);
      iVar2 = qcom_scm_pas_shutdown(*(undefined4 *)(lVar6 + 0x28));
      if (iVar2 != 0) goto LAB_00101440;
      **(undefined4 **)(lVar6 + 0x188) = 0xffffffff;
      lVar3 = *(long *)(lVar6 + 0x80);
      goto joined_r0x00101394;
    }
    _dev_err(*puVar5,"wdog bite is pending\n");
    uVar1 = 0;
    *(int *)puVar5[0x30] = (int)(1L << ((ulong)*(uint *)(puVar5 + 0x35) & 0x3f));
  }
  _dev_err(*puVar5,"Failed to attach SPSS remote proc and shutdown\n");
  lVar6 = *(long *)(param_1 + 0x28);
  iVar2 = qcom_scm_pas_shutdown(*(undefined4 *)(lVar6 + 0x28));
  if (iVar2 != 0) {
LAB_00101440:
                    /* WARNING: Subroutine does not return */
    panic("Panicking, remoteproc %s failed to shutdown.\n",*(undefined8 *)(param_1 + 0x18));
  }
  **(undefined4 **)(lVar6 + 0x188) = 0xffffffff;
  lVar3 = *(long *)(lVar6 + 0x80);
joined_r0x00101394:
  if (lVar3 != 0) {
    qcom_rproc_toggle_load_state(lVar3,*(undefined8 *)(lVar6 + 0x78),0);
  }
  *(undefined4 *)(param_1 + 0x3cc) = 0;
  *(undefined4 *)(lVar6 + 0x30) = 0;
  return uVar1;
}



//------------------------------------------------------------
// spss_da_to_va @ 00101454 size=104
// signature: undefined spss_da_to_va(void)
// callers: []
//------------------------------------------------------------

long spss_da_to_va(long param_1,long param_2,long param_3)

{
  ulong uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x28);
  uVar1 = param_2 - *(long *)(lVar2 + 0x58);
  if (((int)uVar1 < 0) || (*(ulong *)(lVar2 + 0x68) < (uVar1 & 0xffffffff) + param_3)) {
    _dev_err(param_1 + 0x38,"offset: %llx, da: %llx, len: %llx\n",uVar1 & 0xffffffff,param_2);
    lVar2 = 0;
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x60) + (uVar1 & 0xffffffff);
  }
  return lVar2;
}



//------------------------------------------------------------
// spss_load @ 001014c0 size=508
// signature: undefined spss_load(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int spss_load(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  void *__dest;
  ulong uVar6;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  puVar2 = *(undefined8 **)(param_1 + 0x28);
  iVar3 = qcom_mdt_load(*puVar2,param_2,*(undefined8 *)(param_1 + 0x20),*(undefined4 *)(puVar2 + 5),
                        puVar2[0xc],puVar2[10],puVar2[0xd],puVar2 + 0xb);
  if (iVar3 == 0) {
    if ((ssr_already_occurred_since_boot & 1) == 0) {
      uVar1 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar1 = 0x68000000000f13;
      }
      lVar5 = ioremap_prot(0x1881008,4,uVar1);
      if (lVar5 == 0) {
        _printk(&DAT_00101b22);
      }
      else {
        uVar4 = readl_relaxed();
        iounmap(lVar5);
        uVar6 = (ulong)(uVar4 << 2);
        if ((uVar4 & 0x3ff) == 0) {
          if (-1 < (int)(uVar4 << 2)) {
            __dest = (void *)kmalloc_trace(_DAT_00104250,0xdc0,0x1000);
            if (__dest == (void *)0x0) {
              iVar3 = -0xc;
            }
            else {
              lVar5 = puVar2[0xd];
              memcpy(__dest,(void *)(puVar2[0xc] + lVar5 + -0x1000),0x1000);
              local_60 = 8;
              uStack_58 = 0x600000003;
              local_50 = 0x60000001a;
              iVar3 = qcom_scm_assign_mem(puVar2[10] + uVar6,lVar5 - uVar6,&local_60,&uStack_58,2);
              if (iVar3 == 0) {
                memcpy((void *)(puVar2[0xc] + puVar2[0xd] + -0x1000),__dest,0x1000);
                kfree(__dest);
                ssr_already_occurred_since_boot = 1;
              }
              else {
                _dev_err(*puVar2,"qcom_scm_assign_mem failed %d\n",iVar3);
                kfree(__dest);
              }
            }
            goto LAB_00101664;
          }
        }
        else {
          _printk(&DAT_00101b94,uVar6);
        }
      }
      _dev_err(*puVar2,"failed to get pil_size.\n");
      iVar3 = -0xe;
    }
    else {
      iVar3 = 0;
    }
  }
  else {
    _dev_err(*puVar2,"qcom_mdt_load of SPSS image failed, error value %d\n",iVar3);
  }
LAB_00101664:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// read_sp2cl_debug_registers @ 001016bc size=444
// signature: undefined read_sp2cl_debug_registers(void)
// callers: [spss_attach, spss_start]
//------------------------------------------------------------

void read_sp2cl_debug_registers(undefined8 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar4 = 0x68000000000713;
  if (arm64_use_ng_mappings != '\0') {
    uVar4 = 0x68000000000f13;
  }
  lVar3 = ioremap_prot(0x1886020,8,uVar4);
  uVar4 = *param_1;
  if (lVar3 == 0) {
    _dev_err(uVar4,"Iteration: [0x%x], addr: [0x%x]\n",0,0);
  }
  else {
    uVar1 = readl_relaxed();
    uVar2 = readl_relaxed(lVar3 + 4);
    _dev_info(uVar4,"Iteration: [0x%x], Debug Data1: [0x%x], Debug Data2: [0x%x]\n",0,uVar1,uVar2);
    iounmap(lVar3);
  }
  uVar4 = 0x68000000000713;
  if (arm64_use_ng_mappings != '\0') {
    uVar4 = 0x68000000000f13;
  }
  lVar3 = ioremap_prot(0x1888020,8,uVar4);
  uVar4 = *param_1;
  if (lVar3 == 0) {
    _dev_err(uVar4,"Iteration: [0x%x], addr: [0x%x]\n",1,0);
  }
  else {
    uVar1 = readl_relaxed();
    uVar2 = readl_relaxed(lVar3 + 4);
    _dev_info(uVar4,"Iteration: [0x%x], Debug Data1: [0x%x], Debug Data2: [0x%x]\n",1,uVar1,uVar2);
    iounmap(lVar3);
  }
  uVar4 = 0x68000000000713;
  if (arm64_use_ng_mappings != '\0') {
    uVar4 = 0x68000000000f13;
  }
  lVar3 = ioremap_prot(0x188c020,8,uVar4);
  uVar4 = *param_1;
  if (lVar3 == 0) {
    _dev_err(uVar4,"Iteration: [0x%x], addr: [0x%x]\n",2,0);
  }
  else {
    uVar1 = readl_relaxed();
    uVar2 = readl_relaxed(lVar3 + 4);
    _dev_info(uVar4,"Iteration: [0x%x], Debug Data1: [0x%x], Debug Data2: [0x%x]\n",2,uVar1,uVar2);
    iounmap(lVar3);
  }
  return;
}



//------------------------------------------------------------
// disable_regulator @ 00101878 size=72
// signature: undefined disable_regulator(void)
// callers: [spss_start]
//------------------------------------------------------------

void disable_regulator(undefined8 *param_1)

{
  regulator_set_voltage(*param_1,0,0x7fffffff);
  regulator_set_load(*param_1,0);
  regulator_disable(*param_1);
  return;
}



//------------------------------------------------------------
// glink_spss_subdev_start @ 001018c4 size=64
// signature: undefined glink_spss_subdev_start(void)
// callers: []
//------------------------------------------------------------

undefined4 glink_spss_subdev_start(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar1 = qcom_glink_spss_register(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x40));
  uVar2 = (undefined4)uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = 0;
  }
  *(ulong *)(param_1 + 0x48) = uVar1;
  return uVar2;
}



//------------------------------------------------------------
// glink_spss_subdev_stop @ 00101908 size=48
// signature: undefined glink_spss_subdev_stop(void)
// callers: []
//------------------------------------------------------------

void glink_spss_subdev_stop(long param_1)

{
  qcom_glink_spss_unregister(*(undefined8 *)(param_1 + 0x48));
  *(undefined8 *)(param_1 + 0x48) = 0;
  return;
}



//------------------------------------------------------------
// glink_spss_subdev_unprepare @ 0010193c size=32
// signature: undefined glink_spss_subdev_unprepare(void)
// callers: []
//------------------------------------------------------------

void glink_spss_subdev_unprepare(long param_1)

{
  qcom_glink_ssr_notify(*(undefined8 *)(param_1 + 0x30));
  return;
}



//------------------------------------------------------------
// init_module @ 001019c4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&spss_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001019f4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&spss_driver);
  return;
}



//------------------------------------------------------------
// ioremap_prot @ 00104008 size=1
// signature: undefined ioremap_prot(void)
// callers: [get_spss_image_size, read_sp2cl_debug_registers, spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00104010 size=1
// signature: undefined iounmap(void)
// callers: [get_spss_image_size, read_sp2cl_debug_registers, spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104018 size=1
// signature: undefined _printk(void)
// callers: [get_spss_image_size, spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00104020 size=1
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
// log_post_read_mmio @ 00104028 size=1
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
// kstrdup_const @ 00104030 size=1
// signature: undefined kstrdup_const(void)
// callers: [qcom_add_glink_spss_subdev, qcom_spss_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104038 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_spss_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104040 size=1
// signature: undefined kfree(void)
// callers: [qcom_spss_set_fw_name, spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104048 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_spss_set_fw_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104050 size=1
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
// platform_driver_unregister @ 00104058 size=1
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
// of_device_get_match_data @ 00104060 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_is_available @ 00104068 size=1
// signature: undefined qcom_scm_is_available(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_alloc @ 00104070 size=1
// signature: undefined rproc_alloc(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104078 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_set_elf_info @ 00104080 size=1
// signature: undefined rproc_coredump_set_elf_info(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_set_elf_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00104088 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [qcom_spss_remove, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00104090 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00104098 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001040a0 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001040a8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 001040b0 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_wc @ 001040b8 size=1
// signature: undefined devm_ioremap_wc(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_wc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001040c0 size=1
// signature: undefined of_find_property(void)
// callers: [init_regulator, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_get @ 001040c8 size=1
// signature: undefined qmp_get(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_add_ssr_subdev @ 001040d0 size=1
// signature: undefined qcom_add_ssr_subdev(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_add_ssr_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_add_sysmon_subdev @ 001040d8 size=1
// signature: undefined qcom_add_sysmon_subdev(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_add_sysmon_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 001040e0 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001040e8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_add @ 001040f0 size=1
// signature: undefined rproc_add(void)
// callers: [qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_remove_sysmon_subdev @ 001040f8 size=1
// signature: undefined qcom_remove_sysmon_subdev(void)
// callers: [qcom_spss_remove, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_remove_sysmon_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104100 size=1
// signature: undefined _dev_err(void)
// callers: [init_regulator, spss_attach, spss_init_clock, spss_da_to_va, spss_generic_handler, read_sp2cl_debug_registers, spss_load, qcom_spss_probe, spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104108 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [init_regulator, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00104110 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [qcom_spss_remove, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_free @ 00104118 size=1
// signature: undefined rproc_free(void)
// callers: [qcom_spss_remove, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104120 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [init_regulator, spss_load, qcom_spss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_del @ 00104128 size=1
// signature: undefined rproc_del(void)
// callers: [qcom_spss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_remove_subdev @ 00104130 size=1
// signature: undefined rproc_remove_subdev(void)
// callers: [qcom_spss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_remove_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_const @ 00104138 size=1
// signature: undefined kfree_const(void)
// callers: [qcom_spss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_remove_ssr_subdev @ 00104140 size=1
// signature: undefined qcom_remove_ssr_subdev(void)
// callers: [qcom_spss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_remove_ssr_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00104148 size=1
// signature: undefined devm_clk_get(void)
// callers: [spss_init_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00104150 size=1
// signature: undefined devm_regulator_get(void)
// callers: [init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00104158 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 00104160 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [qcom_add_glink_spss_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_add_subdev @ 00104168 size=1
// signature: undefined rproc_add_subdev(void)
// callers: [qcom_add_glink_spss_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_add_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00104170 size=1
// signature: undefined _dev_info(void)
// callers: [spss_generic_handler, read_sp2cl_debug_registers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00104178 size=1
// signature: undefined complete(void)
// callers: [spss_generic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_report_crash @ 00104180 size=1
// signature: undefined rproc_report_crash(void)
// callers: [spss_generic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_report_crash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00104188 size=1
// signature: noreturn undefined panic(void)
// callers: [spss_attach, spss_stop, spss_generic_handler, spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00104190 size=1
// signature: undefined clk_prepare(void)
// callers: [spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00104198 size=1
// signature: undefined clk_enable(void)
// callers: [spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001041a0 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [disable_regulator, spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 001041a8 size=1
// signature: undefined regulator_set_load(void)
// callers: [disable_regulator, spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001041b0 size=1
// signature: undefined regulator_enable(void)
// callers: [spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001041b8 size=1
// signature: undefined clk_disable(void)
// callers: [spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001041c0 size=1
// signature: undefined clk_unprepare(void)
// callers: [spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_rproc_toggle_load_state @ 001041c8 size=1
// signature: undefined qcom_rproc_toggle_load_state(void)
// callers: [spss_attach, spss_stop, spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_rproc_toggle_load_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_auth_and_reset @ 001041d0 size=1
// signature: undefined qcom_scm_pas_auth_and_reset(void)
// callers: [spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_auth_and_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 001041d8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [spss_attach, spss_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown @ 001041e0 size=1
// signature: undefined qcom_scm_pas_shutdown(void)
// callers: [spss_attach, spss_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_pas_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_mdt_load @ 001041e8 size=1
// signature: undefined qcom_mdt_load(void)
// callers: [spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_mdt_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001041f8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104200 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00104208 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [spss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00104210 size=1
// signature: undefined regulator_disable(void)
// callers: [disable_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_spss_register @ 00104218 size=1
// signature: undefined qcom_glink_spss_register(void)
// callers: [glink_spss_subdev_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_spss_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_spss_unregister @ 00104220 size=1
// signature: undefined qcom_glink_spss_unregister(void)
// callers: [glink_spss_subdev_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_spss_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_ssr_notify @ 00104228 size=1
// signature: undefined qcom_glink_ssr_notify(void)
// callers: [glink_spss_subdev_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_ssr_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



