// Ghidra 12.2 symbol-driven decompilation
// Program: msm_drm.ko regex=^(dsi_display_(bind|check_status|init)|dsi_panel_get(_mode)?|sde_kms_hw_init|sde_connector_init|sde_crtc_init|sde_encoder_init|sde_plane_init|sde_rm_init|msm_drm.*|.*backlight.*|.*esd.*)$
//------------------------------------------------------------
// sde_crtc_init @ 0018f618 size=4300
// signature: undefined sde_crtc_init(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * sde_crtc_init(long param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  ulong *puVar5;
  undefined **ppuVar6;
  char cVar7;
  uint uVar8;
  bool bVar9;
  int iVar10;
  long *plVar11;
  undefined8 *puVar12;
  ulong uVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined8 uVar16;
  long lVar17;
  long lVar18;
  undefined4 *puVar19;
  long lVar20;
  long lVar21;
  undefined8 local_170;
  undefined8 uStack_168;
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
  
  lVar17 = sp_el0;
  local_70 = *(long *)(lVar17 + 0x638);
  lVar17 = *(long *)(param_1 + 0x38);
  lVar20 = *(long *)(lVar17 + 8);
  plVar11 = (long *)kmalloc_trace(_kthread_unpark,0xdc0,0x1908);
  if (plVar11 == (long *)0x0) {
    plVar11 = (long *)0xfffffffffffffff4;
    goto LAB_00190548;
  }
  *plVar11 = param_1;
  __mutex_init(plVar11 + 0x183,"&sde_crtc->crtc_lock",&sde_crtc_init___key);
  plVar11[0x234] = 0;
  *(undefined4 *)(plVar11 + 399) = 0;
  uVar16 = _kthread_unpark;
  *(undefined1 *)(plVar11 + 0x176) = 0;
  *(undefined1 *)(plVar11 + 0x235) = 0;
  *(undefined4 *)((long)plVar11 + 0xb84) = 1000000;
  puVar12 = (undefined8 *)kmalloc_trace(uVar16,0xcc0,8000);
  plVar11[0x171] = (long)puVar12;
  if (puVar12 == (undefined8 *)0x0) {
    _printk(&DAT_002fb679,"sde_crtc_init",0x208e);
  }
  else {
    *puVar12 = 0;
  }
  plVar1 = plVar11 + 0x1e8;
  plVar11[0x1e8] = (long)plVar1;
  plVar11[0x1e9] = (long)plVar1;
  plVar11[0x181] = (long)(plVar11 + 0x181);
  plVar11[0x182] = (long)(plVar11 + 0x181);
  lVar21 = 0;
  do {
    lVar2 = (long)plVar11 + lVar21 + 0xcb8;
    *(long *)((long)plVar11 + lVar21 + 0xcb8) = lVar2;
    *(long *)((long)plVar11 + lVar21 + 0xcc0) = lVar2;
    lVar18 = plVar11[0x1e8];
    uVar13 = __list_add_valid(lVar2,plVar1,lVar18);
    if ((uVar13 & 1) != 0) {
      *(long *)(lVar18 + 8) = lVar2;
      *(long *)((long)plVar11 + lVar21 + 0xcb8) = lVar18;
      *(long **)((long)plVar11 + lVar21 + 0xcc0) = plVar1;
      *plVar1 = lVar2;
    }
    lVar2 = (long)plVar11 + lVar21 + 0xc80;
    lVar18 = lVar21 + 0x58;
    *(undefined8 *)((long)plVar11 + lVar21 + 0xca0) = 0;
    *(undefined8 *)((long)plVar11 + lVar21 + 0xc98) = 0;
    *(long *)lVar2 = lVar2;
    *(long *)((long)plVar11 + lVar21 + 0xc88) = lVar2;
    *(code **)((long)plVar11 + lVar21 + 0xc90) = sde_crtc_frame_event_work;
    lVar21 = lVar18;
  } while (lVar18 != 0x2c0);
  plVar1 = plVar11 + 0x232;
  plVar11[0x232] = (long)plVar1;
  plVar11[0x233] = (long)plVar1;
  lVar21 = 0;
  do {
    lVar2 = (long)plVar11 + lVar21 + 0xf80;
    *(long *)((long)plVar11 + lVar21 + 0xf80) = lVar2;
    *(long *)((long)plVar11 + lVar21 + 0xf88) = lVar2;
    lVar18 = plVar11[0x232];
    uVar13 = __list_add_valid(lVar2,plVar1,lVar18);
    if ((uVar13 & 1) != 0) {
      *(long *)(lVar18 + 8) = lVar2;
      *(long *)((long)plVar11 + lVar21 + 0xf80) = lVar18;
      *(long **)((long)plVar11 + lVar21 + 0xf88) = plVar1;
      *plVar1 = lVar2;
    }
    lVar2 = (long)plVar11 + lVar21 + 0xf50;
    lVar18 = lVar21 + 0x48;
    *(undefined8 *)((long)plVar11 + lVar21 + 0xf70) = 0;
    *(undefined8 *)((long)plVar11 + lVar21 + 0xf68) = 0;
    *(long *)lVar2 = lVar2;
    *(long *)((long)plVar11 + lVar21 + 0xf58) = lVar2;
    *(code **)((long)plVar11 + lVar21 + 0xf60) = sde_crtc_vblank_notify_work;
    lVar21 = lVar18;
  } while (lVar18 != 0x240);
  ppuVar6 = &sde_crtc_funcs;
  if ((*(ulong *)(*(long *)(lVar20 + 0x90) + 0x5220) & 0x1000000) != 0) {
    ppuVar6 = &sde_crtc_funcs_v1;
  }
  drm_crtc_init_with_planes(param_1,plVar11,param_2,0,ppuVar6,0);
  plVar11[0x38] = (long)sde_crtc_helper_funcs;
  if (*(int *)(*(long *)(lVar20 + 0x90) + 0x30) != 0) {
    puVar5 = (ulong *)(plVar11 + 0x31d);
    Hint_Prefetch(puVar5,2,0,1);
    do {
      cVar7 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(puVar5,0x10);
      if (bVar9) {
        *puVar5 = *puVar5 | 1;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
    puVar5 = (ulong *)(plVar11 + 0x31d);
    Hint_Prefetch(puVar5,2,0,1);
    do {
      cVar7 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(puVar5,0x10);
      if (bVar9) {
        *puVar5 = *puVar5 | 2;
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
  }
  plVar1 = plVar11 + 0xd0;
  snprintf((char *)plVar1,0xc,"crtc%u",*(uint *)(plVar11 + 0xe));
  lVar21 = 0;
  plVar3 = plVar11 + 0x2d7;
  *(undefined4 *)(plVar11 + 0x2d9) = 0;
  plVar11[0x2d7] = (long)plVar3;
  plVar11[0x2d8] = (long)plVar3;
  do {
    puVar12 = (undefined8 *)plVar11[0x2d8];
    plVar4 = (long *)((long)plVar11 + lVar21 + 0x11b8);
    uVar13 = __list_add_valid(plVar4,puVar12,plVar3);
    if ((uVar13 & 1) != 0) {
      plVar11[0x2d8] = (long)plVar4;
      *plVar4 = (long)plVar3;
      *(undefined8 **)((long)plVar11 + lVar21 + 0x11c0) = puVar12;
      *puVar12 = plVar4;
    }
    lVar21 = lVar21 + 0x50;
  } while (lVar21 != 0x500);
  uVar13 = sde_fence_init(plVar1,(int)plVar11[0xe]);
  plVar11[0x136] = uVar13;
  if (0xfffffffffffff000 < uVar13) {
    _printk(&DAT_002d0143,"sde_crtc_init",0x20c0,uVar13 & 0xffffffff);
    drm_crtc_cleanup(plVar11);
    kfree(plVar11);
    plVar11 = (long *)(long)(int)uVar13;
    goto LAB_00190548;
  }
  plVar3 = plVar11 + 0xed;
  msm_property_init(plVar3,plVar11 + 0xe,param_1,lVar17 + 0x10f8,plVar11 + 0xfd,0x1c,5,0x14b0);
  puVar19 = *(undefined4 **)(lVar20 + 0x90);
  if ((__drm_debug >> 2 & 1) != 0) {
    ___drm_dbg(0,0,&DAT_002f0eab);
  }
  if (puVar19 == (undefined4 *)0x0) {
    _printk(&DAT_002cd337,"sde_crtc_install_properties",0x1ab5);
  }
  else {
    if ((*plVar11 == 0) || (lVar17 = *(long *)(*plVar11 + 0x38), lVar17 == 0)) {
      puVar15 = &DAT_002b4a7a;
      uVar16 = 0x90;
    }
    else {
      lVar17 = *(long *)(lVar17 + 8);
      if (lVar17 != 0) {
        lVar20 = vzalloc(0x400c);
        if (lVar20 == 0) {
          _printk(&DAT_002c1119,"sde_crtc_install_properties",0x1ac2);
          goto LAB_001904a4;
        }
        sde_kms_info_reset();
        sde_kms_info_add_keyint(lVar20,"hw_version",*puVar19);
        sde_kms_info_add_keyint(lVar20,"max_linewidth",puVar19[0x141e]);
        sde_kms_info_add_keyint(lVar20,"max_blendstages",puVar19[0x141f]);
        iVar10 = puVar19[3];
        if (iVar10 == 2) {
          sde_kms_info_add_keystr(lVar20,"qseed_type","qseed2");
          iVar10 = puVar19[3];
        }
        if (iVar10 == 3) {
          sde_kms_info_add_keystr(lVar20,"qseed_type","qseed3");
          iVar10 = puVar19[3];
        }
        if (iVar10 == 0x16) {
          sde_kms_info_add_keystr(lVar20,"qseed_type","qseed3lite");
        }
        if (puVar19[1] != 0) {
          sde_kms_info_add_keyint(lVar20,"UBWC version");
          sde_kms_info_add_keyint(lVar20,"UBWC macrotile_mode",puVar19[0x1423]);
          sde_kms_info_add_keyint(lVar20,"UBWC highest banking bit",puVar19[0xac]);
          sde_kms_info_add_keyint(lVar20,"UBWC swizzle",puVar19[0xae]);
        }
        local_170 = (ulong)local_170._4_4_ << 0x20;
        lVar21 = of_find_node_opts_by_path("/memory",0);
        if ((lVar21 == 0) ||
           (iVar10 = of_property_read_variable_u32_array(lVar21,"ddr_device_type",&local_170,1,0),
           iVar10 < 0)) {
          uVar13 = 0xfffffffe;
LAB_001905a0:
          if ((__drm_debug >> 2 & 1) == 0) {
            _printk(&DAT_002d023c,"sde_crtc_setup_capabilities_blob",0x1a3d);
          }
          else {
            _printk(&DAT_002b4c82,uVar13);
          }
        }
        else {
          uVar13 = local_170 & 0xffffffff;
          if ((int)local_170 == 9) {
            pcVar14 = "DDR5X";
          }
          else if ((int)local_170 == 8) {
            pcVar14 = "DDR5";
          }
          else {
            if ((int)local_170 != 7) goto LAB_001905a0;
            pcVar14 = "DDR4";
          }
          sde_kms_info_add_keystr(lVar20,"DDR version",pcVar14);
        }
        uVar13 = sde_is_custom_client();
        if ((uVar13 & 1) != 0) {
          if (puVar19[5] == 0xb) {
            pcVar14 = "smart_dma_v2";
          }
          else {
            if (puVar19[5] != 0xc) goto LAB_0018fb6c;
            pcVar14 = "smart_dma_v2p5";
          }
          sde_kms_info_add_keystr(lVar20,"smart_dma_rev",pcVar14);
        }
LAB_0018fb6c:
        sde_kms_info_add_keyint(lVar20,"has_src_split",*(ulong *)(puVar19 + 0x1488) >> 0x10 & 1);
        sde_kms_info_add_keyint(lVar20,"has_hdr",*(ulong *)(puVar19 + 0x1488) >> 0x13 & 1);
        sde_kms_info_add_keyint(lVar20,"has_hdr_plus",*(ulong *)(puVar19 + 0x1488) >> 0x14 & 1);
        sde_kms_info_add_keyint
                  (lVar20,"skip_inline_rot_threshold",*(ulong *)(puVar19 + 0x1488) >> 0x1d & 1);
        if (puVar19[0x1426] != 0) {
          sde_kms_info_add_keyint(lVar20,"allowed_dsc_reservation_switch");
        }
        if (puVar19[0x1480] != 0) {
          sde_kms_info_add_keyint(lVar20,"has_uidle",1);
        }
        sde_kms_info_add_keystr(lVar20,"core_ib_ff",*(undefined8 *)(puVar19 + 0x1442));
        sde_kms_info_add_keystr(lVar20,"core_clk_ff",*(undefined8 *)(puVar19 + 0x1444));
        sde_kms_info_add_keystr(lVar20,"comp_ratio_rt",*(undefined8 *)(puVar19 + 0x1446));
        sde_kms_info_add_keystr(lVar20,"comp_ratio_nrt",*(undefined8 *)(puVar19 + 0x1448));
        sde_kms_info_add_keyint(lVar20,"dest_scale_prefill_lines",puVar19[0x144c]);
        sde_kms_info_add_keyint(lVar20,"undersized_prefill_lines",puVar19[0x144a]);
        sde_kms_info_add_keyint(lVar20,"macrotile_prefill_lines",puVar19[0x144d]);
        sde_kms_info_add_keyint(lVar20,"yuv_nv12_prefill_lines",puVar19[0x144e]);
        sde_kms_info_add_keyint(lVar20,"linear_prefill_lines",puVar19[0x144f]);
        sde_kms_info_add_keyint(lVar20,"downscaling_prefill_lines",puVar19[0x1450]);
        sde_kms_info_add_keyint(lVar20,"xtra_prefill_lines",puVar19[0x144b]);
        sde_kms_info_add_keyint(lVar20,"amortizable_threshold",puVar19[0x1451]);
        sde_kms_info_add_keyint(lVar20,"min_prefill_lines",puVar19[0x1452]);
        sde_kms_info_add_keyint(lVar20,"num_mnoc_ports",puVar19[0x1469]);
        sde_kms_info_add_keyint(lVar20,"axi_bus_width",puVar19[0x1468]);
        sde_kms_info_add_keyint(lVar20,"sec_ui_blendstage",puVar19[0x1413]);
        if (puVar19[2] != 0) {
          sde_kms_info_add_keyint(lVar20,"ubwc_bw_calc_ver");
        }
        msm_property_install_range(plVar3,"input_fence_timeout",0,0,10000,10000,5);
        msm_property_install_volatile_range(plVar3,"output_fence",0,0,0xffffffffffffffff,0,6);
        msm_property_install_range(plVar3,"output_fence_offset",0,0,1,0,7);
        msm_property_install_range
                  (plVar3,"core_clk",0,0,0xffffffffffffffff,*(undefined8 *)(lVar17 + 0x7b8),9);
        msm_property_install_range
                  (plVar3,"core_ab",0,0,0xffffffffffffffff,(ulong)(uint)puVar19[0x143d] * 1000,10);
        msm_property_install_range
                  (plVar3,"core_ib",0,0,0xffffffffffffffff,(ulong)(uint)puVar19[0x143d] * 1000,0xb);
        msm_property_install_range
                  (plVar3,"llcc_ab",0,0,0xffffffffffffffff,(ulong)(uint)puVar19[0x143d] * 1000,0xc);
        msm_property_install_range
                  (plVar3,"llcc_ib",0,0,0xffffffffffffffff,(ulong)(uint)puVar19[0x143d] * 1000,0xd);
        msm_property_install_range
                  (plVar3,"dram_ab",0,0,0xffffffffffffffff,(ulong)(uint)puVar19[0x143d] * 1000,0xe);
        msm_property_install_range
                  (plVar3,"dram_ib",0,0,0xffffffffffffffff,(ulong)(uint)puVar19[0x143d] * 1000,0xf);
        msm_property_install_range
                  (plVar3,"rot_prefill_bw",0,0,0xffffffffffffffff,
                   (ulong)(uint)puVar19[0x143d] * 1000,0x10);
        msm_property_install_range
                  (plVar3,"rot_clk",0,0,0xffffffffffffffff,*(undefined8 *)(lVar17 + 0x7b8),0x11);
        if (puVar19[0x143c] != 0) {
          sde_kms_info_add_keyint(lVar20,"max_bandwidth_low",(ulong)(uint)puVar19[0x143c] * 1000);
        }
        if (puVar19[0x143d] != 0) {
          sde_kms_info_add_keyint(lVar20,"max_bandwidth_high",(ulong)(uint)puVar19[0x143d] * 1000);
        }
        if (puVar19[0x143e] != 0) {
          sde_kms_info_add_keyint(lVar20,"min_core_ib",(ulong)(uint)puVar19[0x143e] * 1000);
        }
        if (puVar19[0x143f] != 0) {
          sde_kms_info_add_keyint(lVar20,"min_llcc_ib",(ulong)(uint)puVar19[0x143f] * 1000);
        }
        if (puVar19[0x1440] != 0) {
          sde_kms_info_add_keyint(lVar20,"min_dram_ib",(ulong)(uint)puVar19[0x1440] * 1000);
        }
        if (*(long *)(lVar17 + 0x7b8) != 0) {
          sde_kms_info_add_keyint(lVar20,"max_mdp_clk");
        }
        if ((*(ulong *)(puVar19 + 0x1488) >> 0x23 & 1) == 0) {
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 9 & 1) != 0) goto LAB_00190074;
LAB_0018fff0:
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 6 & 1) != 0) goto LAB_001900a8;
LAB_0018fff8:
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 3 & 1) != 0) {
            puVar15 = sde_crtc_install_properties_e_cwb_data_points;
            uVar16 = 2;
            goto LAB_001900c8;
          }
        }
        else {
          if (*(long *)(lVar17 + 0x90) == 0) {
            bVar9 = false;
          }
          else {
            bVar9 = *(char *)(*(long *)(lVar17 + 0x90) + 0x4ac8) != '\0';
          }
          msm_property_install_enum
                    (plVar3,"vm_request_state",0,0,sde_crtc_install_properties_e_vm_req_state,3,
                     bVar9,0x18);
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 9 & 1) == 0) goto LAB_0018fff0;
LAB_00190074:
          msm_property_install_enum
                    (plVar3,"idle_pc_state",0,0,sde_crtc_install_properties_e_idle_pc_state,3,0,0x16
                    );
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 6 & 1) == 0) goto LAB_0018fff8;
LAB_001900a8:
          puVar15 = sde_crtc_install_properties_e_dcwb_data_points;
          uVar16 = 3;
LAB_001900c8:
          msm_property_install_enum(plVar3,"capture_mode",0,0,puVar15,uVar16,0,0x15);
        }
        msm_property_install_enum
                  (plVar3,"fence_error_handle_flag",0,0,
                   sde_crtc_install_properties_e_fence_error_handle_flag,2,0,0x1b);
        msm_property_install_volatile_range(plVar3,"sde_drm_roi_v1",0,0,0xffffffffffffffff,0,0x12);
        msm_property_install_enum
                  (plVar3,"security_level",0,0,sde_crtc_install_properties_e_secure_level,2,0,0x13);
        if ((*(ulong *)(puVar19 + 0x143a) & 1) == 0) {
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 1 & 1) != 0) goto LAB_001901a0;
LAB_00190160:
          cVar7 = *(char *)(puVar19 + 0xaf);
        }
        else {
          msm_property_install_enum
                    (plVar3,"cache_state",0,0,sde_crtc_install_properties_e_cache_state,2,0,0x17);
          if (((uint)*(undefined8 *)(puVar19 + 0x1488) >> 1 & 1) == 0) goto LAB_00190160;
LAB_001901a0:
          msm_property_install_volatile_range(plVar3,"dim_layer_v1",0,0,0xffffffffffffffff,0,8);
          sde_kms_info_add_keyint(lVar20,"dim_layer_v1_max_layers",7);
          cVar7 = *(char *)(puVar19 + 0xaf);
        }
        if (cVar7 != '\0') {
          sde_kms_info_add_keyint(lVar20,"has_dest_scaler");
          sde_kms_info_add_keyint(lVar20,"dest_scaler_count",puVar19[0x7d6]);
          if (*(long *)(puVar19 + 0x7e6) != 0) {
            sde_kms_info_add_keyint
                      (lVar20,"max_dest_scaler_input_width",
                       *(undefined4 *)(*(long *)(puVar19 + 0x7e6) + 0x34));
            sde_kms_info_add_keyint
                      (lVar20,"max_dest_scaler_output_width",
                       *(undefined4 *)(*(long *)(puVar19 + 0x7e6) + 0x38));
            sde_kms_info_add_keyint
                      (lVar20,"max_dest_scale_up",*(undefined4 *)(*(long *)(puVar19 + 0x7e6) + 0x3c)
                      );
          }
          if (((uint)*(undefined8 *)(puVar19 + 0x7e0) >> 3 & 1) == 0) {
            if (((uint)*(undefined8 *)(puVar19 + 0x7e0) >> 0x16 & 1) != 0) {
              msm_property_install_volatile_range
                        (plVar3,"dest_scaler",0,0,0xffffffffffffffff,0,0x14);
            }
          }
          else {
            msm_property_install_volatile_range(plVar3,"dest_scaler",0,0,0xffffffffffffffff,0,0x14);
            msm_property_install_blob(plVar3,"ds_lut_ed",0,1);
            msm_property_install_blob(plVar3,"ds_lut_cir",0,2);
            msm_property_install_blob(plVar3,"ds_lut_sep",0,3);
          }
        }
        if (puVar19[0x72c] != 0) {
          sde_kms_info_add_keyint(lVar20,"dspp_count");
          if (puVar19[0x1299] != 0) {
            sde_kms_info_add_keyint(lVar20,"rc_count");
            sde_kms_info_add_keyint
                      (lVar20,"rc_mem_size",*(undefined4 *)(*(long *)(puVar19 + 0x73a) + 0x1f8));
          }
          if (puVar19[0x129b] != 0) {
            sde_kms_info_add_keyint(lVar20,"demura_count");
          }
        }
        sde_kms_info_add_keyint(lVar20,"dsc_block_count",puVar19[0x95a]);
        msm_property_install_blob(plVar3,"capabilities",4,0);
        sde_kms_info_add_keyint
                  (lVar20,"use_baselayer_for_stage",*(ulong *)(puVar19 + 0x1488) >> 0xe & 1);
        msm_property_set_blob(plVar3,plVar11 + 0x135,lVar20,*(int *)(lVar20 + 0x4000) + 1,0);
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_a0 = 0;
        uStack_98 = 0;
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
        local_170 = 0;
        uStack_168 = 0;
        if ((puVar19[0x614] == 0) || ((*(byte *)((long)puVar19 + 0x1879) >> 2 & 1) == 0)) {
LAB_00190470:
          uVar13 = *(ulong *)(puVar19 + 0x1488);
        }
        else {
          uVar8 = *(uint *)(*(long *)(puVar19 + 0x622) + 0x7c) >> 0x10;
          snprintf((char *)&local_170,0x100,"%s%d","noise_layer_v",uVar8);
          if (uVar8 == 1) {
            sde_kms_info_add_keyint(lVar20,"has_noise_layer",1);
            msm_property_install_volatile_range(plVar3,&local_170,0,0,0xffffffffffffffff,0,0x19);
            goto LAB_00190470;
          }
          _printk(&DAT_002ae74f,"sde_crtc_install_noise_layer_properties",0x2219,uVar8);
          uVar13 = *(ulong *)(puVar19 + 0x1488);
        }
        if ((uVar13 >> 0x26 & 1) != 0) {
          msm_property_install_range(plVar3,"frame_data",0,0,0xffffffffffffffff,0,0x1a);
        }
        vfree(lVar20);
        goto LAB_001904a4;
      }
      puVar15 = &DAT_002dea1e;
      uVar16 = 0x95;
    }
    _printk(puVar15,"_sde_crtc_get_kms",uVar16);
    _printk(&DAT_002e50c5,"sde_crtc_install_properties",0x1abc);
  }
LAB_001904a4:
  sde_cp_crtc_init(plVar11);
  sde_cp_crtc_install_properties(plVar11);
  *(undefined2 *)(plVar11 + 0x2e3) = 0;
  *(undefined2 *)(plVar11 + 0x2eb) = 0;
  *(undefined1 *)((long)plVar11 + 0x171a) = 0;
  *(undefined1 *)((long)plVar11 + 0x175a) = 0;
  plVar11[0x309] = 0;
  plVar11[0x30a] = 0;
  plVar11[0x306] = (long)(plVar11 + 0x306);
  plVar11[0x307] = (long)(plVar11 + 0x306);
  plVar11[0x308] = (long)__sde_crtc_static_cache_read_work;
  init_timer_key(plVar11 + 0x30b,&kthread_delayed_work_timer_fn,0x200000,0,0);
  if ((__drm_debug >> 2 & 1) != 0) {
    ___drm_dbg(0,0,"%s: successfully initialized crtc, hwfence_out:%d, hwfence_in:%d\n",plVar1,
               (uint)plVar11[0x31d] & 1,(uint)plVar11[0x31d] >> 1 & 1);
  }
LAB_00190548:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar11;
}



//------------------------------------------------------------
// sde_crtc_backlight_notify @ 00191d2c size=112
// signature: undefined sde_crtc_backlight_notify(void)
//------------------------------------------------------------

void sde_crtc_backlight_notify(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  sde_evtlog_log(sde_dbg_base_evtlog,"sde_crtc_backlight_notify",0x22b1,0xffffffff,param_2,param_3,
                 0xc0debeef);
  sde_cp_backlight_notification(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// sde_encoder_init @ 001a6550 size=3180
// signature: undefined sde_encoder_init(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long sde_encoder_init(long param_1,undefined4 *param_2)

{
  long lVar1;
  bool bVar2;
  byte bVar3;
  long lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined4 uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  code *pcVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  int iVar16;
  int iVar17;
  ulong uVar18;
  undefined4 uVar19;
  long local_c8;
  long lStack_c0;
  undefined *local_b8;
  undefined *puStack_b0;
  undefined *local_a8;
  undefined *puStack_a0;
  undefined8 local_98;
  undefined8 local_90;
  long local_88;
  long lStack_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_78 = 0;
  lVar15 = *(long *)(*(long *)(param_1 + 0x38) + 8);
  local_70 = 0;
  lVar4 = kmalloc_trace(_kthread_unpark,0xdc0,0x12e8);
  if (lVar4 == 0) {
    iVar16 = -0xc;
  }
  else {
    lVar14 = lVar4 + 0x1e8;
    __mutex_init(lVar14,"&sde_enc->enc_lock",&sde_encoder_init___key);
    local_88 = 0;
    lStack_80 = 0;
    local_98 = 0;
    local_90 = 0;
    local_a8 = (undefined *)0x0;
    puStack_a0 = (undefined *)0x0;
    local_b8 = (undefined *)0x0;
    puStack_b0 = (undefined *)0x0;
    local_c8 = 0;
    lStack_c0 = 0;
    if (lVar15 == 0) {
      _printk(&DAT_002fba25,"sde_encoder_setup_display",0x17e0,0,1);
LAB_001a7018:
      iVar16 = -0x16;
    }
    else {
      lVar1 = lVar4 + 0x80;
      local_98 = 0;
      local_90 = 0;
      local_b8 = PTR_sde_encoder_vblank_callback_0030ca08;
      puStack_b0 = PTR_sde_encoder_underrun_callback_0030ca10;
      local_88 = lVar4 + 0x78;
      local_a8 = PTR_sde_encoder_frame_done_callback_0030ca18;
      puStack_a0 = PTR__sde_encoder_get_qsync_fps_callback_0030ca20;
      *(undefined4 *)(lVar4 + 0x3e4) = 0;
      local_c8 = lVar15;
      lStack_c0 = lVar4;
      lStack_80 = lVar1;
      if ((__drm_debug >> 2 & 1) != 0) {
        ___drm_dbg(0,0,&DAT_002f0eab);
      }
      bVar3 = __drm_debug;
      bVar2 = false;
      iVar17 = 1;
      uVar8 = 6;
      switch(*param_2) {
      case 10:
        bVar2 = false;
        iVar17 = 10;
        uVar8 = 2;
        if ((*(byte *)(param_2 + 1) & 0x20) != 0) {
          uVar8 = 7;
        }
        break;
      case 0xb:
        bVar2 = false;
        iVar17 = 3;
        uVar8 = 2;
        break;
      default:
        _printk(&DAT_002c1231,"sde_encoder_setup_display",0x17fe,*(undefined4 *)(lVar4 + 0x18));
        goto LAB_001a7018;
      case 0xf:
        iVar17 = 0x100;
        bVar2 = true;
        uVar8 = 5;
        break;
      case 0x10:
        break;
      }
      if (param_2[3] == 0) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x800,0x1a71b0);
        (*pcVar12)();
      }
      uVar19 = param_2[0x61];
      *(undefined4 *)(lVar4 + 0xb4) = param_2[3];
      *(undefined4 *)(lVar4 + 0xb8) = uVar19;
      if ((bVar3 >> 2 & 1) != 0) {
        ___drm_dbg(0,0,"dsi_info->num_of_h_tiles %d\n");
      }
      *(byte *)(lVar4 + 0x3f0) =
           (byte)((uint)*(undefined8 *)(*(long *)(lVar15 + 0x90) + 0x5220) >> 9) & 1;
      *(byte *)(lVar4 + 0x3f1) =
           (byte)((uint)*(undefined8 *)(*(long *)(lVar15 + 0x90) + 0x5220) >> 0xf) & 1;
      *(byte *)(lVar4 + 0x12da) =
           (byte)((ulong)*(undefined8 *)(*(long *)(lVar15 + 0x90) + 0x5220) >> 0x28) & 1;
      mutex_lock(lVar14);
      uVar9 = (ulong)(uint)param_2[3];
      if (param_2[3] != 0) {
        uVar18 = 0;
LAB_001a6734:
        if (uVar18 == 2) goto LAB_001a71b8;
        uVar7 = param_2[uVar18 + 4];
        uVar19 = 1;
        if (uVar18 != 0) {
          uVar19 = 2;
        }
        if ((uint)uVar9 < 2) {
          uVar19 = 0;
        }
        local_98 = CONCAT44(local_98._4_4_,uVar19);
        if ((__drm_debug >> 2 & 1) != 0) {
          ___drm_dbg(0,0,"h_tile_instance %d = %d, split_role %d\n",uVar18 & 0xffffffff,uVar7);
        }
        if (bVar2) {
          local_98 = CONCAT44(8,(undefined4)local_98);
          if (uVar7 < *(uint *)(*(long *)(lVar15 + 0x90) + 0x3430)) {
            if (0xb < uVar7) goto LAB_001a71b8;
            iVar16 = *(int *)(*(long *)(lVar15 + 0x90) + (ulong)uVar7 * 0x58 + 0x3448);
            local_90 = CONCAT44(local_90._4_4_,iVar16);
            if (iVar16 != 5) {
              if ((__drm_debug >> 2 & 1) != 0) {
                ___drm_dbg(0,0,"enc%d \n",*(undefined4 *)(lVar4 + 0x18));
              }
              if (*(int *)(lVar4 + 0xbc) - 3U < 0xfffffffc) {
                _printk(&DAT_002f19f6,"sde_encoder_virt_add_phys_enc_wb",0x17bc,
                        *(undefined4 *)(lVar4 + 0x18));
                iVar16 = -0x16;
              }
              else {
                uVar9 = sde_encoder_phys_wb_init(&local_c8);
                if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) {
                  uVar7 = *(uint *)(lVar4 + 0xbc);
                  uVar10 = (ulong)uVar7;
                  if (uVar7 < 4) goto LAB_001a6b24;
                  goto LAB_001a71b8;
                }
                _printk(&DAT_002eb2f9,"sde_encoder_virt_add_phys_enc_wb",0x17c4,
                        *(undefined4 *)(lVar4 + 0x18),uVar9);
joined_r0x001a6ba8:
                if (uVar9 == 0) {
                  iVar16 = -0x16;
                }
                else {
                  iVar16 = (int)uVar9;
                  if (iVar16 == 0) goto LAB_001a6b50;
                }
              }
LAB_001a7148:
              _printk(&DAT_002f19be,"sde_encoder_setup_display",0x1849,*(undefined4 *)(lVar4 + 0x18)
                     );
              goto LAB_001a6bb8;
            }
          }
          else {
            local_90 = CONCAT44(local_90._4_4_,5);
          }
          uVar19 = *(undefined4 *)(lVar4 + 0x18);
          uVar6 = 0x182e;
          iVar17 = 0x100;
LAB_001a719c:
          _printk(&DAT_002d2f94,"sde_encoder_setup_display",uVar6,uVar19,iVar17,uVar7);
          iVar16 = -0x16;
          goto LAB_001a6bb8;
        }
        lVar11 = *(long *)(lVar15 + 0x90);
        iVar16 = *(int *)(lVar11 + 0x3128);
        local_90 = CONCAT44(local_90._4_4_,5);
        if (iVar16 != 0) {
          if ((*(int *)(lVar11 + 0x3160) == iVar17) && (*(uint *)(lVar11 + 0x3164) == uVar7)) {
            lVar13 = 0;
LAB_001a6a20:
            iVar16 = *(int *)(lVar11 + lVar13 * 0x40 + 0x3140);
            local_98 = CONCAT44(iVar16,(undefined4)local_98);
            if (iVar16 == 8) goto LAB_001a7180;
            uVar7 = param_2[1];
            if ((__drm_debug >> 2 & 1) != 0) {
              ___drm_dbg(0,0,"enc%d \n",*(undefined4 *)(lVar4 + 0x18));
            }
            uVar10 = (ulong)*(uint *)(lVar4 + 0xbc);
            if (*(uint *)(lVar4 + 0xbc) - 2 < 0xfffffffc) {
              _printk(&DAT_002f19f6,"sde_encoder_virt_add_phys_encs",0x1767,
                      *(undefined4 *)(lVar4 + 0x18));
              iVar16 = -0x16;
              goto LAB_001a7148;
            }
            if ((uVar7 & 1) != 0) {
              uVar9 = sde_encoder_phys_vid_init(&local_c8);
              if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
                uVar19 = *(undefined4 *)(lVar4 + 0x18);
                puVar5 = &DAT_002b4e05;
                uVar6 = 6000;
LAB_001a6b98:
                _printk(puVar5,"sde_encoder_virt_add_phys_encs",uVar6,uVar19,uVar9);
                goto joined_r0x001a6ba8;
              }
              uVar10 = (ulong)*(uint *)(lVar4 + 0xbc);
              if (*(uint *)(lVar4 + 0xbc) < 4) {
                *(ulong *)(lVar4 + uVar10 * 8 + 0xe0) = uVar9;
                goto LAB_001a6a9c;
              }
              goto LAB_001a71b8;
            }
LAB_001a6a9c:
            if ((uVar7 >> 1 & 1) != 0) {
              uVar9 = sde_encoder_phys_cmd_init(&local_c8);
              if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
                uVar19 = *(undefined4 *)(lVar4 + 0x18);
                puVar5 = &DAT_002c7545;
                uVar6 = 0x177c;
                goto LAB_001a6b98;
              }
              uVar10 = (ulong)*(uint *)(lVar4 + 0xbc);
              if (3 < *(uint *)(lVar4 + 0xbc)) goto LAB_001a71b8;
              *(ulong *)(lVar4 + uVar10 * 8 + 0x100) = uVar9;
            }
            uVar7 = (uint)uVar10;
            if (param_2[2] == 1) {
              if (3 < uVar7) goto LAB_001a71b8;
              uVar9 = uVar10 * 8 + 0xe0;
            }
            else {
              if (3 < uVar7) goto LAB_001a71b8;
              uVar9 = uVar10 * 8 + 0x100;
            }
            if (0x12e0 < uVar9) goto LAB_001a71bc;
            uVar9 = *(ulong *)(uVar9 + lVar4);
LAB_001a6b24:
            if ((uVar10 * 8 - 0x1229 < 0xffffffffffffed17) || (uVar10 == 0x245)) {
LAB_001a71bc:
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(1,0x1a71c0);
              (*pcVar12)();
            }
            *(ulong *)(lVar4 + uVar10 * 8 + 0xc0) = uVar9;
            *(uint *)(lVar4 + 0xbc) = uVar7 + 1;
LAB_001a6b50:
            uVar9 = (ulong)(uint)param_2[3];
            uVar18 = uVar18 + 1;
            if (uVar9 <= uVar18) goto LAB_001a6bb4;
            goto LAB_001a6734;
          }
          if (iVar16 != 1) {
            if ((*(int *)(lVar11 + 0x31a0) == iVar17) && (*(uint *)(lVar11 + 0x31a4) == uVar7)) {
              lVar13 = 1;
              goto LAB_001a6a20;
            }
            if (iVar16 == 2) goto LAB_001a7178;
            if ((*(int *)(lVar11 + 0x31e0) == iVar17) && (*(uint *)(lVar11 + 0x31e4) == uVar7)) {
              lVar13 = 2;
              goto LAB_001a6a20;
            }
            if (iVar16 != 3) {
              if ((*(int *)(lVar11 + 0x3220) == iVar17) && (*(uint *)(lVar11 + 0x3224) == uVar7)) {
                lVar13 = 3;
                goto LAB_001a6a20;
              }
              if (iVar16 != 4) {
                if ((*(int *)(lVar11 + 0x3260) == iVar17) && (*(uint *)(lVar11 + 0x3264) == uVar7))
                {
                  lVar13 = 4;
                  goto LAB_001a6a20;
                }
                if (iVar16 != 5) {
                  if ((*(int *)(lVar11 + 0x32a0) == iVar17) && (*(uint *)(lVar11 + 0x32a4) == uVar7)
                     ) {
                    lVar13 = 5;
                    goto LAB_001a6a20;
                  }
                  if (iVar16 != 6) {
                    if ((*(int *)(lVar11 + 0x32e0) == iVar17) &&
                       (*(uint *)(lVar11 + 0x32e4) == uVar7)) {
                      lVar13 = 6;
                      goto LAB_001a6a20;
                    }
                    if (iVar16 != 7) {
                      if ((*(int *)(lVar11 + 0x3320) == iVar17) &&
                         (*(uint *)(lVar11 + 0x3324) == uVar7)) {
                        lVar13 = 7;
                        goto LAB_001a6a20;
                      }
                      if (iVar16 != 8) {
                        if ((*(int *)(lVar11 + 0x3360) == iVar17) &&
                           (*(uint *)(lVar11 + 0x3364) == uVar7)) {
                          lVar13 = 8;
                          goto LAB_001a6a20;
                        }
                        if (iVar16 != 9) {
                          if ((*(int *)(lVar11 + 0x33a0) == iVar17) &&
                             (*(uint *)(lVar11 + 0x33a4) == uVar7)) {
                            lVar13 = 9;
                            goto LAB_001a6a20;
                          }
                          if (iVar16 != 10) {
                            if ((*(int *)(lVar11 + 0x33e0) == iVar17) &&
                               (*(uint *)(lVar11 + 0x33e4) == uVar7)) {
                              lVar13 = 10;
                              goto LAB_001a6a20;
                            }
                            if (iVar16 != 0xb) {
                              if ((*(int *)(lVar11 + 0x3420) == iVar17) &&
                                 (*(uint *)(lVar11 + 0x3424) == uVar7)) {
                                lVar13 = 0xb;
                                goto LAB_001a6a20;
                              }
                              if (iVar16 != 0xc) goto LAB_001a71b8;
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
LAB_001a7178:
        local_98 = CONCAT44(8,(undefined4)local_98);
LAB_001a7180:
        uVar19 = *(undefined4 *)(lVar4 + 0x18);
        uVar6 = 0x1839;
        goto LAB_001a719c;
      }
LAB_001a6bb4:
      iVar16 = 0;
LAB_001a6bb8:
      if (*(int *)(lVar4 + 0xbc) != 0) {
        lVar13 = *(long *)(lVar4 + 0xe0);
        lVar11 = *(long *)(lVar4 + 0x100);
        if (lVar13 != 0) {
          *(undefined4 *)(lVar13 + 0x328) = 0;
          *(undefined4 *)(lVar13 + 0x338) = 0;
        }
        if (lVar11 != 0) {
          *(undefined4 *)(lVar11 + 0x328) = 0;
          *(undefined4 *)(lVar11 + 0x338) = 0;
        }
        if (1 < *(uint *)(lVar4 + 0xbc)) {
          lVar13 = *(long *)(lVar4 + 0xe8);
          lVar11 = *(long *)(lVar4 + 0x108);
          if (lVar13 != 0) {
            *(undefined4 *)(lVar13 + 0x328) = 0;
            *(undefined4 *)(lVar13 + 0x338) = 0;
          }
          if (lVar11 != 0) {
            *(undefined4 *)(lVar11 + 0x328) = 0;
            *(undefined4 *)(lVar11 + 0x338) = 0;
          }
          if (2 < *(uint *)(lVar4 + 0xbc)) {
            lVar13 = *(long *)(lVar4 + 0xf0);
            lVar11 = *(long *)(lVar4 + 0x110);
            if (lVar13 != 0) {
              *(undefined4 *)(lVar13 + 0x328) = 0;
              *(undefined4 *)(lVar13 + 0x338) = 0;
            }
            if (lVar11 != 0) {
              *(undefined4 *)(lVar11 + 0x328) = 0;
              *(undefined4 *)(lVar11 + 0x338) = 0;
            }
            if (3 < *(uint *)(lVar4 + 0xbc)) {
              lVar13 = *(long *)(lVar4 + 0xf8);
              lVar11 = *(long *)(lVar4 + 0x118);
              if (lVar13 != 0) {
                *(undefined4 *)(lVar13 + 0x328) = 0;
                *(undefined4 *)(lVar13 + 0x338) = 0;
              }
              if (lVar11 != 0) {
                *(undefined4 *)(lVar11 + 0x328) = 0;
                *(undefined4 *)(lVar11 + 0x338) = 0;
              }
              if (4 < *(uint *)(lVar4 + 0xbc)) goto LAB_001a71b8;
            }
          }
        }
      }
      mutex_unlock(lVar14);
      if (iVar16 == 0) {
        *(undefined8 *)(lVar4 + 0x120) = 0;
        *(undefined4 *)(lVar4 + 0x78) = 0;
        __mutex_init(lVar1,"&sde_enc->vblank_ctl_lock",&sde_encoder_init___key_75);
        *(undefined4 *)(lVar4 + 0x218) = 0;
        *(undefined4 *)(lVar4 + 0x21c) = 0;
        *(undefined4 *)(lVar4 + 0x220) = 0;
        *(undefined4 *)(lVar4 + 0x224) = 0;
        drm_encoder_init(param_1,lVar4,sde_encoder_funcs,uVar8,0);
        *(undefined1 **)(lVar4 + 0x70) = sde_encoder_helper_funcs;
        if (*(int *)(lVar4 + 0xbc) == 0) {
          iVar16 = 8;
        }
        else {
          lVar14 = *(long *)(lVar4 + 0xc0);
          if ((lVar14 == 0) || (pcVar12 = *(code **)(lVar14 + 0x20), pcVar12 == (code *)0x0)) {
LAB_001a6d1c:
            iVar16 = 8;
          }
          else {
            if (*(int *)(pcVar12 + -4) != -0x4699aa10) {
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1a6d08);
              (*pcVar12)();
            }
            uVar9 = (*pcVar12)(lVar14);
            if ((uVar9 & 1) == 0) goto LAB_001a6d1c;
            iVar16 = *(int *)(lVar14 + 0x278) + -1;
          }
          if (1 < *(uint *)(lVar4 + 0xbc)) {
            lVar14 = *(long *)(lVar4 + 200);
            if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x20), pcVar12 != (code *)0x0)) {
              if (*(int *)(pcVar12 + -4) != -0x4699aa10) {
                    /* WARNING: Does not return */
                pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1a6d58);
                (*pcVar12)();
              }
              uVar9 = (*pcVar12)(lVar14);
              if ((uVar9 & 1) != 0) {
                iVar16 = *(int *)(lVar14 + 0x278) + -1;
              }
            }
            if (2 < *(uint *)(lVar4 + 0xbc)) {
              lVar14 = *(long *)(lVar4 + 0xd0);
              if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x20), pcVar12 != (code *)0x0)) {
                if (*(int *)(pcVar12 + -4) != -0x4699aa10) {
                    /* WARNING: Does not return */
                  pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1a6da0);
                  (*pcVar12)();
                }
                uVar9 = (*pcVar12)(lVar14);
                if ((uVar9 & 1) != 0) {
                  iVar16 = *(int *)(lVar14 + 0x278) + -1;
                }
              }
              if (3 < *(uint *)(lVar4 + 0xbc)) {
                lVar14 = *(long *)(lVar4 + 0xd8);
                if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x20), pcVar12 != (code *)0x0))
                {
                  if (*(int *)(pcVar12 + -4) != -0x4699aa10) {
                    /* WARNING: Does not return */
                    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1a6de8);
                    (*pcVar12)();
                  }
                  uVar9 = (*pcVar12)(lVar14);
                  if ((uVar9 & 1) != 0) {
                    iVar16 = *(int *)(lVar14 + 0x278) + -1;
                  }
                }
                if (4 < *(uint *)(lVar4 + 0xbc)) {
LAB_001a71b8:
                    /* WARNING: Does not return */
                  pcVar12 = (code *)SoftwareBreakpoint(0x5512,0x1a71bc);
                  (*pcVar12)();
                }
              }
            }
          }
        }
        snprintf((char *)&local_78,0xc,"rsc_enc%u",*(uint *)(lVar4 + 0x18));
        uVar9 = sde_rsc_client_create(0,&local_78,param_2[0x54] != 1,iVar16 + 1);
        *(ulong *)(lVar4 + 0x240) = uVar9;
        if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
          if ((__drm_debug >> 2 & 1) != 0) {
            ___drm_dbg(0,0,"sde rsc client create failed :%ld\n");
          }
          *(undefined8 *)(lVar4 + 0x240) = 0;
        }
        if (((*(byte *)(param_2 + 1) >> 1 & 1) != 0) && (*(char *)(lVar4 + 0x3f1) != '\0')) {
          if (*(long *)(lVar4 + 0x508) == 0) {
            lVar14 = kmalloc_trace(____drm_dbg,0xdc0,0x80);
            if (lVar14 != 0) {
              *(long *)(lVar4 + 0x508) = lVar14;
              *(code **)(lVar14 + 8) = sde_encoder_input_event_handler;
              *(code **)(lVar14 + 0x28) = _sde_encoder_input_connect;
              *(code **)(lVar14 + 0x30) = _sde_encoder_input_disconnect;
              *(undefined1 **)(lVar14 + 0x48) = &DAT_002d5f01;
              *(undefined1 **)(lVar14 + 0x50) = sde_input_ids;
              goto LAB_001a6edc;
            }
            uVar6 = 0xfffffff4;
          }
          else {
            _printk(&DAT_00304af5,"_sde_encoder_input_handler",0xd06,*(undefined4 *)(lVar4 + 0x18));
            uVar6 = 0xffffffea;
          }
          _printk(&DAT_002c4521,"sde_encoder_init",0x18a5,uVar6);
        }
LAB_001a6edc:
        if (*(char *)(*(long *)(lVar15 + 0x90) + 0x4a30) != '\0') {
          *(undefined4 *)(lVar4 + 0x514) = 2;
        }
        __mutex_init(lVar4 + 0x3f8,"&sde_enc->rc_lock",&sde_encoder_init___key_80);
        *(undefined8 *)(lVar4 + 0x450) = 0;
        *(undefined8 *)(lVar4 + 0x448) = 0;
        *(long *)(lVar4 + 0x430) = lVar4 + 0x430;
        *(long *)(lVar4 + 0x438) = lVar4 + 0x430;
        *(code **)(lVar4 + 0x440) = sde_encoder_off_work;
        init_timer_key(lVar4 + 0x458,&kthread_delayed_work_timer_fn,0x200000,0,0);
        *(undefined1 *)(lVar4 + 0x510) = 0;
        *(undefined1 *)(lVar4 + 0x1cd) = 0;
        *(undefined8 *)(lVar4 + 0x4d0) = 0;
        *(undefined8 *)(lVar4 + 0x4d8) = 0;
        *(long *)(lVar4 + 0x4b8) = lVar4 + 0x4b8;
        *(long *)(lVar4 + 0x4c0) = lVar4 + 0x4b8;
        *(undefined8 *)(lVar4 + 0x4a8) = 0;
        *(undefined8 *)(lVar4 + 0x4b0) = 0;
        *(code **)(lVar4 + 0x4c8) = sde_encoder_input_event_work_handler;
        *(long *)(lVar4 + 0x490) = lVar4 + 0x490;
        *(long *)(lVar4 + 0x498) = lVar4 + 0x490;
        *(undefined8 *)(lVar4 + 0x4e0) = 0;
        *(undefined8 *)(lVar4 + 0x4e8) = 0;
        *(undefined8 *)(lVar4 + 0x4f0) = 0;
        *(code **)(lVar4 + 0x4a0) = sde_encoder_early_wakeup_work_handler;
        *(undefined8 *)(lVar4 + 0x4f8) = 0;
        *(undefined8 *)(lVar4 + 0x500) = 0;
        *(long *)(lVar4 + 0x4e0) = lVar4 + 0x4e0;
        *(long *)(lVar4 + 0x4e8) = lVar4 + 0x4e0;
        *(code **)(lVar4 + 0x4f0) = sde_encoder_esd_trigger_work_handler;
        memcpy((void *)(lVar4 + 0x250),param_2,400);
        if ((__drm_debug >> 2 & 1) != 0) {
          ___drm_dbg(0,0,"enc%d created\n",*(undefined4 *)(lVar4 + 0x18));
        }
        goto LAB_001a7038;
      }
    }
  }
  _printk(&DAT_002d5e21,"sde_encoder_init",0x18c5);
  lVar4 = (long)iVar16;
LAB_001a7038:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// sde_encoder_esd_trigger_work_handler @ 001a757c size=68
// signature: undefined sde_encoder_esd_trigger_work_handler(void)
//------------------------------------------------------------

void sde_encoder_esd_trigger_work_handler(long param_1)

{
  if (param_1 + -0x4e0 == 0) {
    _printk(&DAT_002d5e54,"sde_encoder_esd_trigger_work_handler",0x12f9);
  }
  else {
    sde_encoder_resource_control(param_1 + -0x4e0,1);
  }
  return;
}



//------------------------------------------------------------
// sde_rm_init @ 001bef00 size=2284
// signature: undefined sde_rm_init(void)
//------------------------------------------------------------

ulong sde_rm_init(long *param_1)

{
  undefined1 *puVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined8 uVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  int *piVar13;
  undefined4 *puVar14;
  undefined8 local_98;
  long local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  long local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  if ((((param_1 == (long *)0x0) || (lVar9 = param_1[-0xf4], lVar9 == 0)) ||
      (lVar10 = param_1[-0x2e], lVar10 == 0)) || (lVar11 = param_1[-0xf6], lVar11 == 0)) {
    _printk(&DAT_002a817f,"sde_rm_init",0x3b9);
    uVar4 = 0xffffffea;
  }
  else {
    memset(param_1,0,0x178);
    __mutex_init(param_1 + 0x23,"&rm->rm_lock",&sde_rm_init___key);
    param_1[1] = (long)(param_1 + 1);
    param_1[2] = (long)(param_1 + 1);
    param_1[3] = (long)(param_1 + 3);
    param_1[4] = (long)(param_1 + 3);
    param_1[5] = (long)(param_1 + 5);
    param_1[6] = (long)(param_1 + 5);
    param_1[7] = (long)(param_1 + 7);
    param_1[8] = (long)(param_1 + 7);
    param_1[9] = (long)(param_1 + 9);
    param_1[10] = (long)(param_1 + 9);
    param_1[0xb] = (long)(param_1 + 0xb);
    param_1[0xc] = (long)(param_1 + 0xb);
    param_1[0xd] = (long)(param_1 + 0xd);
    param_1[0xe] = (long)(param_1 + 0xd);
    param_1[0xf] = (long)(param_1 + 0xf);
    param_1[0x10] = (long)(param_1 + 0xf);
    param_1[0x11] = (long)(param_1 + 0x11);
    param_1[0x12] = (long)(param_1 + 0x11);
    param_1[0x13] = (long)(param_1 + 0x13);
    param_1[0x14] = (long)(param_1 + 0x13);
    param_1[0x15] = (long)(param_1 + 0x15);
    param_1[0x16] = (long)(param_1 + 0x15);
    param_1[0x17] = (long)(param_1 + 0x17);
    param_1[0x18] = (long)(param_1 + 0x17);
    param_1[0x19] = (long)(param_1 + 0x19);
    param_1[0x1a] = (long)(param_1 + 0x19);
    param_1[0x1b] = (long)(param_1 + 0x1b);
    param_1[0x1c] = (long)(param_1 + 0x1b);
    param_1[0x1d] = (long)(param_1 + 0x1d);
    param_1[0x1e] = (long)(param_1 + 0x1d);
    param_1[0x1f] = (long)(param_1 + 0x1f);
    param_1[0x20] = (long)(param_1 + 0x1f);
    *param_1 = lVar11;
    puVar1 = g_top_table_v1;
    if (*(int *)(lVar9 + 0x18) != 0x100) {
      puVar1 = g_top_table;
    }
    param_1[0x29] = (long)puVar1;
    uVar4 = sde_hw_mdptop_init(1,lVar10,lVar9);
    param_1[0x21] = uVar4;
    if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
      param_1[0x21] = 0;
      puVar5 = &DAT_00304cf5;
      pcVar6 = "sde_rm_init";
      uVar7 = 0x3d2;
LAB_001bf79c:
      _printk(puVar5,pcVar6,uVar7);
LAB_001bf7a0:
      sde_rm_destroy(param_1);
    }
    else {
      if (*(int *)(lVar9 + 0x1850) != 0) {
        uVar12 = 0;
        puVar14 = (undefined4 *)(lVar9 + 0x1868);
        do {
          if (puVar14[0xb] == 0xc) {
            _printk(&DAT_002b1cb9,"sde_rm_init",0x3db,*puVar14);
            uVar4 = 0;
            goto LAB_001bf7a0;
          }
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,2,*puVar14);
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002ee82c;
            pcVar6 = "sde_rm_init";
            uVar7 = 0x3e2;
            goto LAB_001bf79c;
          }
          uVar8 = **(uint **)(puVar14 + 8);
          if (*(uint *)(param_1 + 0x22) == 0) {
LAB_001bf0b4:
            *(uint *)(param_1 + 0x22) = uVar8;
          }
          else if (*(uint *)(param_1 + 0x22) != uVar8) {
            _printk(&DAT_002c1473,"sde_rm_init",0x3ed);
            uVar8 = **(uint **)(puVar14 + 8);
            if (uVar8 < *(uint *)(param_1 + 0x22)) goto LAB_001bf0b4;
          }
          uVar12 = uVar12 + 1;
          puVar14 = puVar14 + 0x16;
        } while (uVar12 < *(uint *)(lVar9 + 0x1850));
      }
      if (*(int *)(lVar9 + 0x1cb0) != 0) {
        uVar12 = 0;
        lVar11 = 0x1cc8;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,3,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002bb10f;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x30d;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x38;
        } while (uVar12 < *(uint *)(lVar9 + 0x1cb0));
      }
      if ((*(char *)(lVar9 + 700) != '\0') && (*(int *)(lVar9 + 0x1f58) != 0)) {
        uVar12 = 0;
        lVar11 = 0x1f70;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,4,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002e2757;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x317;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x40;
        } while (uVar12 < *(uint *)(lVar9 + 0x1f58));
      }
      if (*(int *)(lVar9 + 0x2260) != 0) {
        uVar12 = 0;
        lVar11 = 0x2278;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,7,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002d31aa;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x321;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x40;
        } while (uVar12 < *(uint *)(lVar9 + 0x2260));
      }
      if (*(int *)(lVar9 + 0x2568) != 0) {
        uVar12 = 0;
        lVar11 = 0x2580;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,10,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002ab1dc;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x32a;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x40;
        } while (uVar12 < *(uint *)(lVar9 + 0x2568));
      }
      if (*(int *)(lVar9 + 0x2870) != 0) {
        uVar12 = 0;
        lVar11 = 0x2888;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,0xb,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002a81ae;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x333;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x38;
        } while (uVar12 < *(uint *)(lVar9 + 0x2870));
      }
      if (*(int *)(lVar9 + 0x3128) != 0) {
        uVar12 = 0;
        piVar13 = (int *)(lVar9 + 0x3160);
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          if (*piVar13 == 0) {
            if ((__drm_debug >> 2 & 1) != 0) {
              ___drm_dbg(0,0,"skip intf %d with type none\n",uVar12 & 0xffffffff);
            }
          }
          else {
            uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,8,piVar13[-8]);
            if ((int)uVar4 != 0) {
              uVar4 = uVar4 & 0xffffffff;
              puVar5 = &DAT_002eb54a;
              pcVar6 = "_sde_rm_hw_blk_create_new";
              uVar7 = 0x341;
              goto LAB_001bf79c;
            }
          }
          uVar12 = uVar12 + 1;
          piVar13 = piVar13 + 0x10;
        } while (uVar12 < *(uint *)(lVar9 + 0x3128));
      }
      if (*(int *)(lVar9 + 0x3430) != 0) {
        uVar12 = 0;
        lVar11 = 0x3448;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,9,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002c1524;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x34a;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x58;
        } while (uVar12 < *(uint *)(lVar9 + 0x3430));
      }
      if (*(int *)(lVar9 + 0x12a0) != 0) {
        uVar12 = 0;
        lVar11 = 0x12b8;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,5,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_00304d9c;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x353;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x30;
        } while (uVar12 < *(uint *)(lVar9 + 0x12a0));
      }
      if (*(int *)(lVar9 + 0x30) != 0) {
        uVar12 = *(ulong *)(lVar9 + 0x5220);
        local_90 = 0;
        local_98 = 0;
        uStack_88 = 0x500000000;
        uVar4 = _sde_rm_get_hw_locked(param_1,&local_98,1);
        if ((uVar4 & 1) != 0) {
          do {
            lVar11 = *(long *)(local_90 + 0x28);
            if ((param_1[-0x34] == 0) || (*(long *)(param_1[-0x34] + 0x100) == 0)) {
              if ((__drm_debug >> 2 & 1) != 0) {
                pcVar6 = "failed to init hw_fence idx:%d, no aspace to map memory\n";
LAB_001bf5ec:
                ___drm_dbg(0,0,pcVar6,*(undefined4 *)(lVar11 + 0x20));
              }
LAB_001bf5fc:
              local_78 = 0;
              local_80 = 0;
              uStack_70 = 0x500000000;
              while (uVar4 = _sde_rm_get_hw_locked(param_1,&local_80,1), (uVar4 & 1) != 0) {
                sde_hw_fence_deinit(*(undefined8 *)(local_78 + 0x28));
              }
              if ((__drm_debug >> 2 & 1) == 0) {
                _printk(&DAT_002f88f4,"_sde_rm_hw_blk_create_new",0x35b);
              }
              else {
                _printk(&DAT_002fbc45);
              }
              *(undefined4 *)(lVar9 + 0x30) = 0;
              break;
            }
            iVar3 = sde_hw_fence_init(lVar11,param_1 + -0x106,uVar12 >> 0x2b & 1);
            uVar8 = (uint)CONCAT71(uRam00000000003330e9,__drm_debug);
            if (iVar3 != 0) {
              if ((uVar8 >> 2 & 1) != 0) {
                pcVar6 = "failed to init hw_fence idx:%d\n";
                goto LAB_001bf5ec;
              }
              goto LAB_001bf5fc;
            }
            if ((uVar8 >> 2 & 1) != 0) {
              ___drm_dbg(0,0,"init hw-fence for ctl %d",*(undefined4 *)(local_90 + 0x24));
            }
            uVar4 = _sde_rm_get_hw_locked(param_1,&local_98,1);
          } while ((uVar4 & 1) != 0);
        }
      }
      if (*(int *)(lVar9 + 0x2b18) != 0) {
        uVar12 = 0;
        lVar11 = 0x2b30;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,6,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002cd57a;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x364;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x40;
        } while (uVar12 < *(uint *)(lVar9 + 0x2b18));
      }
      if (*(int *)(lVar9 + 0x2e20) != 0) {
        uVar12 = 0;
        lVar11 = 0x2e38;
        do {
          if (uVar12 == 0xc) goto LAB_001bf7e4;
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,0xe,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_002b802a;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x36d;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x40;
        } while (uVar12 < *(uint *)(lVar9 + 0x2e20));
      }
      if (*(uint *)(lVar9 + 0x47c8) != 0) {
        uVar12 = 0;
        lVar11 = 0x47e0;
        do {
          if (uVar12 == 0xc) {
LAB_001bf7e4:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1bf7e8);
            (*pcVar2)();
          }
          uVar4 = _sde_rm_hw_blk_create(param_1,lVar9,lVar10,0xd,*(undefined4 *)(lVar9 + lVar11));
          if ((int)uVar4 != 0) {
            uVar4 = uVar4 & 0xffffffff;
            puVar5 = &DAT_00304dd3;
            pcVar6 = "_sde_rm_hw_blk_create_new";
            uVar7 = 0x376;
            goto LAB_001bf79c;
          }
          uVar12 = uVar12 + 1;
          lVar11 = lVar11 + 0x30;
        } while (uVar12 < *(uint *)(lVar9 + 0x47c8));
      }
      uVar4 = 0;
    }
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// sde_kms_hw_init @ 001c9754 size=7112
// signature: undefined sde_kms_hw_init(void)
//------------------------------------------------------------

ulong sde_kms_hw_init(long param_1)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined *puVar10;
  undefined4 *puVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  undefined8 *puVar15;
  long lVar16;
  undefined8 uVar17;
  char *pcVar18;
  undefined8 uVar19;
  ulong *puVar20;
  long *plVar21;
  ulong uVar22;
  uint uVar23;
  byte *pbVar24;
  long lVar25;
  long lVar26;
  long lVar27;
  ulong uVar28;
  long lVar29;
  uint uVar30;
  undefined8 uVar31;
  ulong *puVar32;
  uint uVar33;
  ulong uVar34;
  undefined8 local_340;
  undefined8 uStack_338;
  undefined8 local_330;
  undefined8 uStack_328;
  undefined8 local_320;
  undefined8 uStack_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 local_300;
  undefined8 uStack_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined8 local_2b0;
  undefined8 uStack_2a8;
  ulong local_2a0 [20];
  undefined1 auStack_200 [4];
  uint local_1fc;
  int local_1f0;
  int local_78;
  int local_74;
  long local_70;
  
  lVar26 = sp_el0;
  local_70 = *(long *)(lVar26 + 0x638);
  if (param_1 == 0) {
    puVar10 = &DAT_002dea1e;
    uVar19 = 0x14ef;
LAB_001c97c8:
    _printk(puVar10,"sde_kms_hw_init",uVar19);
    uVar28 = 0xffffffea;
    goto LAB_001c97d0;
  }
  lVar26 = *(long *)(param_1 + 0x80);
  if ((lVar26 == 0) || (*(long *)(lVar26 + 8) == 0)) {
    puVar10 = &DAT_002f1c68;
    uVar19 = 0x14f6;
    goto LAB_001c97c8;
  }
  lVar27 = *(long *)(lVar26 + 0x38);
  if (lVar27 == 0) {
    puVar10 = &DAT_002e2856;
    uVar19 = 0x14fd;
    goto LAB_001c97c8;
  }
  lVar25 = *(long *)(lVar26 + 8) + -0x10;
  uVar28 = msm_ioremap(lVar25,"mdp_phys","mdp_phys");
  *(ulong *)(param_1 + 0x6c0) = uVar28;
  if (uVar28 < 0xfffffffffffff001) {
    _printk(&DAT_002f554f,uVar28);
    uVar19 = msm_iomap_size(lVar25,"mdp_phys");
    *(undefined8 *)(param_1 + 0x6e8) = uVar19;
    uVar31 = *(undefined8 *)(param_1 + 0x6c0);
    uVar17 = msm_get_phys_addr(lVar25,"mdp_phys");
    iVar5 = sde_dbg_reg_register_base(&DAT_0030d8c0,uVar31,uVar19,uVar17,1);
    if (iVar5 != 0) {
      _printk(&DAT_002f8a57,"_sde_kms_hw_init_ioremap",0x139c,iVar5);
    }
    uVar28 = msm_ioremap(lVar25,"vbif_phys","vbif_phys");
    *(ulong *)(param_1 + 0x6c8) = uVar28;
    if (0xfffffffffffff000 < uVar28) {
      puVar15 = (undefined8 *)(param_1 + 0x6c8);
      puVar10 = &DAT_00301f0f;
      uVar19 = 0x13a1;
      goto LAB_001c986c;
    }
    uVar19 = msm_iomap_size(lVar25,"vbif_phys");
    *(undefined8 *)(param_1 + 0x6f0) = uVar19;
    uVar31 = *(undefined8 *)(param_1 + 0x6c8);
    uVar17 = msm_get_phys_addr(lVar25,"vbif_phys");
    uVar13 = sde_dbg_reg_register_base("vbif_rt",uVar31,uVar19,uVar17,0x10);
    uVar28 = uVar13 & 0xffffffff;
    if ((int)uVar13 != 0) {
      _printk(&DAT_002b5060,"_sde_kms_hw_init_ioremap",0x13ab,uVar28);
    }
    uVar13 = msm_ioremap(lVar25,"vbif_nrt_phys","vbif_nrt_phys");
    *(ulong *)(param_1 + 0x6d0) = uVar13;
    if (uVar13 < 0xfffffffffffff001) {
      uVar19 = msm_iomap_size(lVar25,"vbif_nrt_phys");
      *(undefined8 *)(param_1 + 0x6f8) = uVar19;
    }
    else {
      *(undefined8 *)(param_1 + 0x6d0) = 0;
      if ((__drm_debug >> 2 & 1) != 0) {
        ___drm_dbg(0,0,"VBIF NRT is not defined");
      }
    }
    uVar13 = msm_ioremap(lVar25,"regdma_phys","regdma_phys");
    *(ulong *)(param_1 + 0x6d8) = uVar13;
    bVar2 = __drm_debug;
    if (uVar13 < 0xfffffffffffff001) {
      lVar12 = msm_get_phys_addr(lVar25,"mdp_phys");
      uVar19 = msm_iomap_size(lVar25,"regdma_phys");
      *(undefined8 *)(param_1 + 0x700) = uVar19;
      lVar29 = msm_get_phys_addr(lVar25,"regdma_phys");
      uVar31 = *(undefined8 *)(param_1 + 0x6d8);
      uVar17 = *(undefined8 *)(param_1 + 0x700);
      *(long *)(param_1 + 0x710) = lVar29 - lVar12;
      uVar19 = msm_get_phys_addr(lVar25,"regdma_phys");
      uVar13 = sde_dbg_reg_register_base("reg_dma",uVar31,uVar17,uVar19,8);
      uVar28 = uVar13 & 0xffffffff;
      if ((int)uVar13 != 0) {
        _printk(&DAT_002dc265,"_sde_kms_hw_init_ioremap",0x13c2,uVar28);
      }
    }
    else {
      *(undefined8 *)(param_1 + 0x6d8) = 0;
      if ((bVar2 >> 2 & 1) != 0) {
        ___drm_dbg(0,0,"REG_DMA is not defined");
      }
    }
    uVar13 = msm_ioremap(lVar25,"sid_phys","sid_phys");
    *(ulong *)(param_1 + 0x6e0) = uVar13;
    if (0xfffffffffffff000 < uVar13) {
      puVar15 = (undefined8 *)(param_1 + 0x6e0);
      if ((__drm_debug >> 2 & 1) != 0) {
        ___drm_dbg(0,0,"sid register is not defined: %d\n",uVar28);
      }
      goto LAB_001c9aa0;
    }
    uVar19 = msm_iomap_size(lVar25,"sid_phys");
    *(undefined8 *)(param_1 + 0x708) = uVar19;
    uVar31 = *(undefined8 *)(param_1 + 0x6e0);
    uVar17 = msm_get_phys_addr(lVar25,"sid_phys");
    uVar6 = sde_dbg_reg_register_base(&DAT_002f8a92,uVar31,uVar19,uVar17,4);
    if (uVar6 == 0) goto LAB_001c9b64;
    uVar28 = (ulong)uVar6;
    puVar10 = &DAT_00304e7b;
    pcVar18 = "_sde_kms_hw_init_ioremap";
    uVar19 = 0x13d0;
    goto LAB_001cb290;
  }
  puVar15 = (undefined8 *)(param_1 + 0x6c0);
  puVar10 = &DAT_00304e3e;
  uVar19 = 0x1390;
LAB_001c986c:
  _printk(puVar10,"_sde_kms_hw_init_ioremap",uVar19,uVar28 & 0xffffffff);
LAB_001c9aa0:
  *puVar15 = 0;
  if ((int)uVar28 == 0) {
LAB_001c9b64:
    iVar5 = _sde_kms_get_splash_data(param_1 + 0x9b0);
    if ((iVar5 != 0) && ((__drm_debug >> 2 & 1) != 0)) {
      ___drm_dbg(0,0,"sde splash data fetch failed: %d\n",iVar5);
    }
    puVar11 = (undefined4 *)sde_hw_catalog_init(lVar26);
    puVar20 = (ulong *)(param_1 + 0x90);
    *puVar20 = (ulong)puVar11;
    if ((puVar11 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < puVar11)) {
      uVar6 = 0xffffffea;
      if (puVar11 != (undefined4 *)0x0) {
        uVar6 = (uint)puVar11;
      }
      uVar28 = (ulong)uVar6;
      _printk(&DAT_002fed07,"_sde_kms_hw_init_blocks",0x1403,uVar28);
      puVar32 = puVar20;
LAB_001c9ccc:
      *puVar32 = 0;
      if ((int)uVar28 != 0) goto LAB_001c9aa8;
      goto LAB_001cb16c;
    }
    *(undefined4 *)(param_1 + 0x88) = *puVar11;
    _printk(&DAT_002b1da5,"_sde_kms_hw_init_blocks",0x1409);
    lVar12 = of_find_property(*(undefined8 *)(*(long *)(lVar26 + 8) + 0x2e8),"#power-domain-cells",0
                             );
    if (lVar12 != 0) {
      lVar12 = param_1 + 0x98;
      uVar19 = *(undefined8 *)(lVar26 + 0x70);
      *(code **)(param_1 + 0x5d0) = sde_kms_pd_disable;
      *(undefined8 *)(param_1 + 0x5a8) = uVar19;
      *(code **)(param_1 + 0x5d8) = sde_kms_pd_enable;
      uVar6 = pm_genpd_init(lVar12,0,1);
      if ((int)uVar6 < 0) {
        uVar28 = (ulong)uVar6;
        _printk(&DAT_002b81f4,"_sde_kms_hw_init_power_helper",0x13e4,
                *(undefined8 *)(param_1 + 0x5a8),uVar28);
      }
      else {
        uVar13 = of_genpd_add_provider_simple(*(undefined8 *)(*(long *)(lVar26 + 8) + 0x2e8),lVar12)
        ;
        bVar2 = __drm_debug;
        uVar28 = uVar13 & 0xffffffff;
        if ((int)uVar13 < 0) {
          _printk(&DAT_002aee31,"_sde_kms_hw_init_power_helper",0x13ec,
                  *(undefined8 *)(param_1 + 0x5a8),uVar28);
          pm_genpd_remove(lVar12);
        }
        else {
          *(undefined1 *)(param_1 + 0x688) = 1;
          if ((bVar2 >> 2 & 1) != 0) {
            ___drm_dbg(0,0,"added genpd provider %s\n",*(undefined8 *)(param_1 + 0x5a8));
          }
          if ((int)uVar13 == 0) goto LAB_001c9c74;
        }
      }
      puVar10 = &DAT_002b1dcf;
      uVar19 = 0x140e;
      goto LAB_001cb2b0;
    }
LAB_001c9c74:
    if ((*(long *)(param_1 + 0x80) != 0) && (*(long *)(*(long *)(param_1 + 0x80) + 8) != 0)) {
      uVar13 = 0;
      do {
        plVar14 = (long *)msm_smmu_new(*(undefined8 *)(*(long *)(param_1 + 0x80) + 8),
                                       uVar13 & 0xffffffff);
        if (plVar14 < (long *)0xfffffffffffff001) {
          uVar28 = msm_gem_smmu_address_space_create
                             (*(undefined8 *)(param_1 + 0x80),plVar14,&DAT_0030d8c0);
          if (uVar28 < 0xfffffffffffff001) {
            *(ulong *)(param_1 + uVar13 * 8 + 0x690) = uVar28;
            *(undefined1 *)(uVar28 + 0x10c) = 1;
            if (uVar13 == 0) {
              if ((*(int *)(param_1 + 0x9b4) != 0) && (*(int *)(param_1 + 0x9b8) != 0)) {
                uVar6 = 0;
                do {
                  uVar28 = _sde_kms_splash_mem_get
                                     (param_1,*(undefined8 *)
                                               (param_1 + (long)(int)uVar6 * 0x50 + 0xa70));
                  if (((int)uVar28 != 0) ||
                     ((*(long *)(param_1 + (long)(int)uVar6 * 0x50 + 0xa78) != 0 &&
                      (uVar28 = _sde_kms_splash_mem_get(param_1), (int)uVar28 != 0)))) {
                    uVar28 = uVar28 & 0xffffffff;
                    puVar10 = &DAT_002c1628;
                    uVar19 = 0x11fe;
                    goto LAB_001c9fbc;
                  }
                  uVar6 = uVar6 + 1;
                } while (uVar6 < *(uint *)(param_1 + 0x9b8));
              }
              if (*(int *)(*puVar20 + 0x30) != 0) {
                puVar15 = (undefined8 *)
                          platform_get_resource_byname
                                    (*(long *)(*(long *)(param_1 + 0x80) + 8) + -0x10,0x200,
                                     "ipcc_reg");
                if (puVar15 == (undefined8 *)0x0) {
                  if ((__drm_debug >> 2 & 1) != 0) {
                    ___drm_dbg(0,0,"failed to get resource ipcc_reg, cannot map ipcc\n");
                  }
                }
                else {
                  *(undefined8 *)(param_1 + 0x1840) = *puVar15;
                  if ((*(long *)(param_1 + 0x690) == 0) ||
                     (plVar21 = *(long **)(*(long *)(param_1 + 0x690) + 0x100),
                     plVar21 == (long *)0x0)) {
                    puVar10 = &DAT_002fed39;
                    uVar19 = 0x328;
                  }
                  else {
                    if ((*plVar21 != 0) &&
                       (pcVar3 = *(code **)(*plVar21 + 0x58), pcVar3 != (code *)0x0)) {
                      iVar5 = *(int *)(*(long *)(param_1 + 0x90) + 0x5274) * 0x40000 +
                              *(int *)(*(long *)(param_1 + 0x90) + 0x5278) * 0x1000 + (int)*puVar15;
                      if (*(int *)(pcVar3 + -4) != 0x78bb849a) {
                    /* WARNING: Does not return */
                        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1c9ef0);
                        (*pcVar3)();
                      }
                      iVar5 = (*pcVar3)(plVar21,iVar5,iVar5,
                                        (*(int *)(puVar15 + 1) - (int)*puVar15) + 1,3);
                      if (iVar5 == 0) goto LAB_001c9d38;
                      _printk(&DAT_002d05ef,"_sde_kms_one2one_mem_map_ipcc_reg",0x33a,iVar5);
                      goto LAB_001c9d2c;
                    }
                    puVar10 = &DAT_002fbe71;
                    uVar19 = 0x333;
                  }
                  _printk(puVar10,"_sde_kms_one2one_mem_map_ipcc_reg",uVar19);
                }
LAB_001c9d2c:
                *(undefined4 *)(*puVar20 + 0x30) = 0;
              }
            }
LAB_001c9d38:
            if (*(int *)(*(code **)(*plVar14 + 0x50) + -4) != -0x22d4fea2) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1c9d5c);
              (*pcVar3)();
            }
            uVar6 = (**(code **)(*plVar14 + 0x50))(plVar14);
            if (uVar6 == 0) goto LAB_001c9d64;
            uVar28 = (ulong)uVar6;
            puVar10 = &DAT_002e5788;
            uVar19 = 0x121e;
LAB_001c9fbc:
            _printk(puVar10,"_sde_kms_mmu_init",uVar19,uVar28);
            _sde_kms_unmap_all_splash_regions(param_1);
          }
          else {
            if (*(int *)(*(code **)(*plVar14 + 0x40) + -4) != -0x29f3230d) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1c9f80);
              (*pcVar3)();
            }
            (**(code **)(*plVar14 + 0x40))(plVar14);
          }
          if (*(long *)(param_1 + 0x6a8) != 0) {
            msm_gem_address_space_put();
            *(undefined8 *)(param_1 + 0x6a8) = 0;
          }
          if (*(long *)(param_1 + 0x6a0) != 0) {
            msm_gem_address_space_put();
            *(undefined8 *)(param_1 + 0x6a0) = 0;
          }
          if (*(long *)(param_1 + 0x698) != 0) {
            msm_gem_address_space_put();
            *(undefined8 *)(param_1 + 0x698) = 0;
          }
          if (*(long *)(param_1 + 0x690) != 0) {
            msm_gem_address_space_put();
            *(undefined8 *)(param_1 + 0x690) = 0;
          }
          if ((int)uVar28 != 0) goto LAB_001c9f8c;
          goto LAB_001ca010;
        }
        if ((__drm_debug >> 2 & 1) != 0) {
          ___drm_dbg(0,0,"failed to init iommu id %d: rc:%d\n",uVar13 & 0xffffffff,
                     (ulong)plVar14 & 0xffffffff);
        }
LAB_001c9d64:
        uVar13 = uVar13 + 1;
      } while (uVar13 != 4);
      *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x690);
LAB_001ca010:
      *(int *)(*(long *)(param_1 + 0x90) + 0x4a54) = (int)*(undefined8 *)(param_1 + 0x710);
      uVar6 = sde_reg_dma_init(*(undefined8 *)(param_1 + 0x6d8),*(undefined8 *)(param_1 + 0x90),
                               *(undefined8 *)(param_1 + 0x80));
      if (uVar6 != 0) {
        uVar28 = (ulong)uVar6;
        _printk(&DAT_002c15cf,"_sde_kms_hw_init_blocks",0x141d);
        goto LAB_001c9aa8;
      }
      sde_dbg_init_dbg_buses(*(undefined4 *)(param_1 + 0x88));
      lVar12 = param_1 + 0x830;
      uVar6 = sde_rm_init(lVar12);
      if (uVar6 != 0) {
        uVar28 = (ulong)uVar6;
        puVar10 = &DAT_002a5002;
        pcVar18 = "_sde_kms_hw_init_blocks";
        uVar19 = 0x1425;
        goto LAB_001cb290;
      }
      *(undefined1 *)(param_1 + 0x9a8) = 1;
      uVar28 = sde_hw_intr_init(*(undefined8 *)(param_1 + 0x6c0),*(undefined8 *)(param_1 + 0x90));
      *(ulong *)(param_1 + 0x740) = uVar28;
      if ((uVar28 == 0) || (0xfffffffffffff000 < uVar28)) {
        puVar32 = (ulong *)(param_1 + 0x740);
        puVar10 = &DAT_002fbe3f;
        uVar19 = 0x142e;
LAB_001ca5e4:
        _printk(puVar10,"_sde_kms_hw_init_blocks",uVar19,uVar28 & 0xffffffff);
        goto LAB_001c9ccc;
      }
      if (*(int *)(param_1 + 0x9b4) != 0) {
        uVar6 = *(uint *)(param_1 + 0x9b8);
        iVar5 = sde_rm_cont_splash_res_init
                          (lVar27,lVar12,param_1 + 0x9b0,*(undefined8 *)(param_1 + 0x90));
        if (0 < (int)uVar6) {
          lVar29 = 0;
          do {
            if (*(char *)(param_1 + 0xa60 + lVar29) == '\0' || iVar5 != 0) {
              _sde_kms_free_splash_display_data(param_1);
            }
            lVar29 = lVar29 + 0x50;
          } while ((ulong)uVar6 * 0x50 != lVar29);
        }
      }
      uVar28 = sde_rm_get_mdp(lVar12);
      *(ulong *)(param_1 + 0xd30) = uVar28;
      if ((uVar28 == 0) || (0xfffffffffffff000 < uVar28)) {
        puVar32 = (ulong *)(param_1 + 0xd30);
        uVar6 = 0xffffffea;
        if (uVar28 != 0) {
          uVar6 = (uint)uVar28;
        }
        uVar28 = (ulong)uVar6;
        puVar10 = &DAT_002f1e2f;
        uVar19 = 0x1451;
        goto LAB_001ca5e4;
      }
      uVar28 = *puVar20;
      if (*(int *)(uVar28 + 0x3858) != 0) {
        uVar6 = *(uint *)(uVar28 + 0x3870);
        uVar13 = (ulong)uVar6;
        if (1 < uVar6) goto LAB_001cb318;
        uVar19 = sde_hw_vbif_init(uVar6,*(undefined8 *)(param_1 + uVar13 * 8 + 0x6c8),uVar28);
        *(undefined8 *)(param_1 + 0xd20) = uVar19;
        puVar32 = (ulong *)(param_1 + 0xd20 + uVar13 * 8);
        uVar28 = *puVar32;
        bVar4 = uVar28 == 0;
        if ((uVar28 == 0) || (0xfffffffffffff000 < uVar28)) {
LAB_001ca658:
          uVar6 = 0xffffffea;
          if (!bVar4) {
            uVar6 = (uint)uVar28;
          }
          uVar28 = (ulong)uVar6;
          _printk(&DAT_002f8abe,"_sde_kms_hw_init_blocks",0x145f,uVar13,uVar28);
          goto LAB_001c9ccc;
        }
        uVar28 = *puVar20;
        if (1 < *(uint *)(uVar28 + 0x3858)) {
          uVar13 = (ulong)*(uint *)(uVar28 + 0x3988);
          if (1 < *(uint *)(uVar28 + 0x3988)) goto LAB_001cb318;
          lVar12 = param_1 + uVar13 * 8;
          uVar19 = sde_hw_vbif_init(uVar13,*(undefined8 *)(lVar12 + 0x6c8),uVar28);
          *(undefined8 *)(param_1 + 0xd28) = uVar19;
          puVar32 = (ulong *)(lVar12 + 0xd20);
          uVar28 = *(ulong *)(lVar12 + 0xd20);
          bVar4 = uVar28 == 0;
          if ((uVar28 == 0) || (0xfffffffffffff000 < uVar28)) goto LAB_001ca658;
          uVar28 = *puVar20;
          if (2 < *(uint *)(uVar28 + 0x3858)) {
            uVar6 = *(uint *)(uVar28 + 0x3aa0);
            if (uVar6 < 2) {
              sde_hw_vbif_init((ulong)uVar6,*(undefined8 *)(param_1 + (ulong)uVar6 * 8 + 0x6c8),
                               uVar28);
            }
            goto LAB_001cb318;
          }
        }
      }
      if (*(int *)(uVar28 + 0x5200) == 0) {
LAB_001ca214:
        *(undefined8 *)(param_1 + 0xd38) = 0;
      }
      else {
        uVar28 = sde_hw_uidle_init(1,*(undefined8 *)(param_1 + 0x6c0),
                                   *(undefined8 *)(param_1 + 0x6e8));
        *(ulong *)(param_1 + 0xd38) = uVar28;
        if ((uVar28 == 0) || (0xfffffffffffff000 < uVar28)) {
          uVar7 = 0xffffffea;
          if (uVar28 != 0) {
            uVar7 = (undefined4)uVar28;
          }
          _printk(&DAT_002e8660,"_sde_kms_hw_init_blocks",0x146d,uVar7);
          goto LAB_001ca214;
        }
      }
      if (*(long *)(param_1 + 0x6e0) != 0) {
        uVar28 = sde_hw_sid_init(*(long *)(param_1 + 0x6e0),*(undefined4 *)(param_1 + 0x708),
                                 *(undefined8 *)(param_1 + 0x90));
        *(ulong *)(param_1 + 0xd40) = uVar28;
        if ((uVar28 == 0) || (0xfffffffffffff000 < uVar28)) {
          _printk(&DAT_002e5758,"_sde_kms_hw_init_blocks",0x147a,uVar28 & 0xffffffff);
          puVar32 = (ulong *)(param_1 + 0xd40);
          goto LAB_001c9ccc;
        }
      }
      uVar6 = sde_core_perf_init(param_1 + 0x780,lVar26,*(undefined8 *)(param_1 + 0x90),
                                 lVar27 + 0x10,"core_clk");
      if (uVar6 != 0) {
        uVar28 = (ulong)uVar6;
        puVar10 = &DAT_002ca7ee;
        pcVar18 = "_sde_kms_hw_init_blocks";
        uVar19 = 0x1483;
        goto LAB_001cb290;
      }
      if (((uint)*(undefined8 *)(*puVar20 + 0x5220) >> 0x18 & 1) != 0) {
        *(undefined1 *)(lVar26 + 0x170) = 1;
      }
      lVar27 = *(long *)(param_1 + 0x80);
      local_2a0[0x12] = 0;
      local_2a0[0x13] = 0;
      local_2a0[0x10] = 0;
      local_2a0[0x11] = 0;
      local_2a0[0xe] = 0;
      local_2a0[0xf] = 0;
      local_2a0[0xc] = 0;
      local_2a0[0xd] = 0;
      local_2a0[10] = 0;
      local_2a0[0xb] = 0;
      local_2a0[8] = 0;
      local_2a0[9] = 0;
      local_2a0[6] = 0;
      local_2a0[7] = 0;
      local_2a0[4] = 0;
      local_2a0[5] = 0;
      local_2a0[2] = 0;
      local_2a0[3] = 0;
      local_2a0[0] = 0;
      local_2a0[1] = 0;
      local_2b0 = 0;
      uStack_2a8 = 0;
      local_2c0 = 0;
      uStack_2b8 = 0;
      local_2d0 = 0;
      uStack_2c8 = 0;
      local_2e0 = 0;
      uStack_2d8 = 0;
      local_2f0 = 0;
      uStack_2e8 = 0;
      local_300 = 0;
      uStack_2f8 = 0;
      local_310 = 0;
      uStack_308 = 0;
      local_320 = 0;
      uStack_318 = 0;
      local_330 = 0;
      uStack_328 = 0;
      local_340 = 0;
      uStack_338 = 0;
      if ((lVar27 != 0) && (*(long *)(lVar27 + 8) != 0)) {
        lVar12 = *(long *)(param_1 + 0x90);
        lVar29 = *(long *)(lVar27 + 0x38);
        uVar28 = sde_core_irq_domain_add(param_1);
        if ((int)uVar28 != 0) {
          uVar28 = uVar28 & 0xffffffff;
          sde_core_irq_domain_fini(param_1);
          goto LAB_001cb29c;
        }
        *(undefined8 *)(param_1 + 0xd50) = 0;
        uVar28 = dsi_display_get_num_of_displays();
        iVar5 = (int)uVar28;
        *(int *)(param_1 + 0xd48) = iVar5;
        if (iVar5 == 0) {
LAB_001ca328:
          *(undefined8 *)(param_1 + 0xd60) = 0;
          uVar28 = sde_wb_get_num_of_displays();
          iVar5 = (int)uVar28;
          *(int *)(param_1 + 0xd58) = iVar5;
          if (iVar5 != 0) {
            if (iVar5 < 0) {
              *(undefined8 *)(param_1 + 0xd60) = 0;
            }
            else {
              lVar16 = __kmalloc(-(uVar28 >> 0x1f & 1) & 0xfffffff800000000 |
                                 (uVar28 & 0xffffffff) << 3,0xdc0);
              *(long *)(param_1 + 0xd60) = lVar16;
              if (lVar16 != 0) {
                uVar7 = wb_display_get_displays(lVar16,*(undefined4 *)(param_1 + 0xd58));
                *(undefined4 *)(param_1 + 0xd58) = uVar7;
                goto LAB_001ca35c;
              }
            }
            _printk(&DAT_002ca835,"_sde_kms_get_displays",0x71c);
LAB_001caca4:
            kfree(*(undefined8 *)(param_1 + 0xd60));
            *(undefined4 *)(param_1 + 0xd58) = 0;
            *(undefined8 *)(param_1 + 0xd60) = 0;
            goto LAB_001cacb4;
          }
LAB_001ca35c:
          *(undefined8 *)(param_1 + 0xd70) = 0;
          uVar28 = dp_display_get_num_of_displays();
          iVar5 = (int)uVar28;
          *(int *)(param_1 + 0xd68) = iVar5;
          if (iVar5 != 0) {
            if (iVar5 < 0) {
              *(undefined8 *)(param_1 + 0xd70) = 0;
            }
            else {
              lVar16 = __kmalloc(-(uVar28 >> 0x1f & 1) & 0xfffffff800000000 |
                                 (uVar28 & 0xffffffff) << 3,0xdc0);
              *(long *)(param_1 + 0xd70) = lVar16;
              if (lVar16 != 0) {
                uVar7 = dp_display_get_displays(lVar16,*(undefined4 *)(param_1 + 0xd68));
                *(undefined4 *)(param_1 + 0xd68) = uVar7;
                uVar7 = dp_display_get_num_of_streams();
                *(undefined4 *)(param_1 + 0xd78) = uVar7;
                goto LAB_001ca398;
              }
            }
            _printk(&DAT_002e57ca,"_sde_kms_get_displays",0x72b);
            kfree(*(undefined8 *)(param_1 + 0xd70));
            *(undefined4 *)(param_1 + 0xd78) = 0;
            *(undefined4 *)(param_1 + 0xd68) = 0;
            *(undefined8 *)(param_1 + 0xd70) = 0;
            goto LAB_001caca4;
          }
LAB_001ca398:
          memset(auStack_200,0,400);
          if (lVar29 == 0) {
            _printk(&DAT_002aacb3,"_sde_kms_setup_displays",0x7c6);
          }
          else {
            iVar5 = *(int *)(param_1 + 0xd58);
            uVar6 = iVar5 + *(int *)(param_1 + 0xd48) +
                    *(int *)(param_1 + 0xd68) + *(int *)(param_1 + 0xd78);
            if (0x10 < uVar6) {
              uVar6 = 0x10;
              _printk(&DAT_002a82e5,"_sde_kms_setup_displays",1999,0x10);
              iVar5 = *(int *)(param_1 + 0xd58);
            }
            if (0 < iVar5) {
              uVar28 = 0;
              do {
                if (uVar6 <= *(uint *)(lVar29 + 0xe08)) break;
                uVar19 = *(undefined8 *)(*(long *)(param_1 + 0xd60) + uVar28 * 8);
                memset(auStack_200,0,400);
                iVar5 = sde_wb_get_info(0,auStack_200,uVar19);
                if (iVar5 == 0) {
                  uVar13 = sde_encoder_init(lVar27,auStack_200);
                  if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
                    puVar10 = &DAT_002c1657;
                    uVar19 = 0x7e1;
                    goto LAB_001ca408;
                  }
                  iVar5 = sde_wb_drm_init(uVar19,uVar13);
                  if (iVar5 == 0) {
                    lVar16 = sde_connector_init(lVar27,uVar13,0,uVar19,
                                                &_sde_kms_setup_displays_wb_ops,1,0xf);
                    if (lVar16 == 0) {
                      _printk(&DAT_002fedae,"_sde_kms_setup_displays",0x7f7,uVar28 & 0xffffffff);
                      sde_wb_drm_deinit(uVar19);
                      goto LAB_001ca53c;
                    }
                    uVar30 = *(uint *)(lVar29 + 0xe08);
                    *(uint *)(lVar29 + 0xe08) = uVar30 + 1;
                    if (0xf < uVar30) goto LAB_001cb318;
                    *(ulong *)(lVar29 + (ulong)uVar30 * 8 + 0xe10) = uVar13;
                    uVar30 = *(uint *)(lVar29 + 0xf18);
                    *(uint *)(lVar29 + 0xf18) = uVar30 + 1;
                    if (0xf < uVar30) goto LAB_001cb318;
                    *(long *)(lVar29 + (ulong)uVar30 * 8 + 0xf20) = lVar16;
                  }
                  else {
                    _printk(&DAT_002e5803,"_sde_kms_setup_displays",0x7e7,uVar28 & 0xffffffff,iVar5)
                    ;
LAB_001ca53c:
                    sde_encoder_destroy(uVar13);
                  }
                }
                else {
                  puVar10 = &DAT_002ab316;
                  uVar19 = 0x7db;
LAB_001ca408:
                  _printk(puVar10,"_sde_kms_setup_displays",uVar19,uVar28 & 0xffffffff);
                }
                uVar28 = uVar28 + 1;
              } while ((long)uVar28 < (long)*(int *)(param_1 + 0xd58));
            }
            if (*(int *)(param_1 + 0xd48) < 1) {
              uVar33 = 0;
              uVar30 = 0;
            }
            else {
              uVar28 = 0;
              uVar30 = 0;
              uVar33 = 0;
              do {
                if (uVar6 <= *(uint *)(lVar29 + 0xe08)) break;
                uVar19 = *(undefined8 *)(*(long *)(param_1 + 0xd50) + uVar28 * 8);
                memset(auStack_200,0,400);
                iVar5 = dsi_display_get_info(0,auStack_200,uVar19);
                if (iVar5 == 0) {
                  uVar13 = sde_encoder_init(lVar27,auStack_200);
                  if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
                    puVar10 = &DAT_00304f15;
                    uVar19 = 0x80c;
                    goto LAB_001ca89c;
                  }
                  iVar5 = dsi_display_drm_bridge_init(uVar19,uVar13);
                  if (iVar5 == 0) {
                    uVar17 = dsi_display_get_drm_panel(uVar19);
                    lVar16 = sde_connector_init(lVar27,uVar13,uVar17,uVar19,
                                                _sde_kms_setup_displays_dsi_ops,1,0x10);
                    if (lVar16 == 0) {
                      _printk(&DAT_002fbede,"_sde_kms_setup_displays",0x822,uVar28 & 0xffffffff);
                      dsi_display_drm_bridge_deinit(uVar19);
                      sde_encoder_destroy(uVar13);
                    }
                    else {
                      uVar23 = *(uint *)(lVar29 + 0xe08);
                      *(uint *)(lVar29 + 0xe08) = uVar23 + 1;
                      if (0xf < uVar23) goto LAB_001cb318;
                      *(ulong *)(lVar29 + (ulong)uVar23 * 8 + 0xe10) = uVar13;
                      uVar23 = *(uint *)(lVar29 + 0xf18);
                      *(uint *)(lVar29 + 0xf18) = uVar23 + 1;
                      if (0xf < uVar23) goto LAB_001cb318;
                      *(long *)(lVar29 + (ulong)uVar23 * 8 + 0xf20) = lVar16;
                      iVar5 = dsi_display_drm_ext_bridge_init(uVar19,uVar13,lVar16);
                      if (iVar5 != 0) {
                        _printk(&DAT_002d067b,"_sde_kms_setup_displays",0x82b,iVar5);
                        dsi_display_drm_bridge_deinit(uVar19);
                        sde_connector_destroy(lVar16);
                        sde_encoder_destroy(uVar13);
                      }
                      uVar30 = local_78 + uVar30;
                      uVar33 = local_74 + uVar33;
                      uVar13 = dsi_display_has_dsc_switch_support(uVar19);
                      if ((uVar13 & 1) != 0) {
                        *(undefined1 *)(param_1 + 0xd7c) = 1;
                      }
                    }
                  }
                  else {
                    _printk(&DAT_002d0643,"_sde_kms_setup_displays",0x812,uVar28 & 0xffffffff,iVar5)
                    ;
                    sde_encoder_destroy(uVar13);
                  }
                }
                else {
                  puVar10 = &DAT_002f1e96;
                  uVar19 = 0x806;
LAB_001ca89c:
                  _printk(puVar10,"_sde_kms_setup_displays",uVar19,uVar28 & 0xffffffff);
                }
                uVar28 = uVar28 + 1;
              } while ((long)uVar28 < (long)*(int *)(param_1 + 0xd48));
            }
            uVar28 = *puVar20;
            uVar23 = *(uint *)(uVar28 + 0x5098);
            if ((uVar23 != 0) && (*(char *)(param_1 + 0xd7c) == '\0')) {
              if ((__drm_debug >> 2 & 1) != 0) {
                ___drm_dbg(0,0,"dsc switch not supported\n");
                uVar28 = *puVar20;
              }
              *(undefined4 *)(uVar28 + 0x5098) = 0;
              uVar28 = *puVar20;
              uVar23 = *(uint *)(uVar28 + 0x5098);
            }
            uVar1 = *(uint *)(uVar28 + 0x2568);
            iVar5 = 0;
            if (uVar33 <= *(uint *)(uVar28 + 0x1850)) {
              iVar5 = *(uint *)(uVar28 + 0x1850) - uVar33;
            }
            uVar33 = 0;
            if (uVar30 <= uVar1) {
              uVar33 = uVar1 - uVar30;
            }
            if ((uVar23 & 1) != 0) {
              uVar33 = uVar1;
            }
            if (0 < *(int *)(param_1 + 0xd68)) {
              uVar28 = 0;
              do {
                if (uVar6 <= *(uint *)(lVar29 + 0xe08)) break;
                uVar19 = *(undefined8 *)(*(long *)(param_1 + 0xd70) + uVar28 * 8);
                memset(auStack_200,0,400);
                iVar8 = dp_connector_get_info(0,auStack_200,uVar19);
                if (iVar8 == 0) {
                  uVar13 = sde_encoder_init(lVar27,auStack_200);
                  if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
                    puVar10 = &DAT_002d93b8;
                    uVar19 = 0x857;
                    goto LAB_001ca9b8;
                  }
                  iVar8 = dp_drm_bridge_init(uVar19,uVar13,iVar5,uVar33);
                  if (iVar8 == 0) {
                    lVar16 = sde_connector_init(lVar27,uVar13,0,uVar19,
                                                &_sde_kms_setup_displays_dp_ops,1,10);
                    if (lVar16 == 0) {
                      _printk(&DAT_002b50e9,"_sde_kms_setup_displays",0x86e,uVar28 & 0xffffffff);
                      dp_drm_bridge_deinit(uVar19);
                      sde_encoder_destroy(uVar13);
                    }
                    else {
                      uVar30 = *(uint *)(lVar29 + 0xe08);
                      *(uint *)(lVar29 + 0xe08) = uVar30 + 1;
                      if (0xf < uVar30) goto LAB_001cb318;
                      *(ulong *)(lVar29 + (ulong)uVar30 * 8 + 0xe10) = uVar13;
                      uVar30 = *(uint *)(lVar29 + 0xf18);
                      *(uint *)(lVar29 + 0xf18) = uVar30 + 1;
                      if (0xf < uVar30) goto LAB_001cb318;
                      *(long *)(lVar29 + (ulong)uVar30 * 8 + 0xf20) = lVar16;
                    }
                    local_1fc = local_1fc | 0x20;
                    if (0 < *(int *)(param_1 + 0xd78)) {
                      iVar8 = 0;
                      do {
                        if (uVar6 <= *(uint *)(lVar29 + 0xe08)) break;
                        local_1f0 = iVar8;
                        uVar13 = sde_encoder_init(lVar27,auStack_200);
                        if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
                          _printk(&DAT_002e8695,"_sde_kms_setup_displays",0x87b,uVar28 & 0xffffffff)
                          ;
                        }
                        else {
                          iVar9 = dp_mst_drm_bridge_init(uVar19,uVar13);
                          if (iVar9 == 0) {
                            uVar30 = *(uint *)(lVar29 + 0xe08);
                            *(uint *)(lVar29 + 0xe08) = uVar30 + 1;
                            if (0xf < uVar30) goto LAB_001cb318;
                            *(ulong *)(lVar29 + (ulong)uVar30 * 8 + 0xe10) = uVar13;
                          }
                          else {
                            _printk(&DAT_002c168f,"_sde_kms_setup_displays",0x882,
                                    uVar28 & 0xffffffff,iVar9);
                            sde_encoder_destroy(uVar13);
                          }
                        }
                        iVar8 = iVar8 + 1;
                      } while (iVar8 < *(int *)(param_1 + 0xd78));
                    }
                  }
                  else {
                    _printk(&DAT_002fbf15,"_sde_kms_setup_displays",0x85e,uVar28 & 0xffffffff,iVar8)
                    ;
                    sde_encoder_destroy(uVar13);
                  }
                }
                else {
                  puVar10 = &DAT_002eea31;
                  uVar19 = 0x851;
LAB_001ca9b8:
                  _printk(puVar10,"_sde_kms_setup_displays",uVar19,uVar28 & 0xffffffff);
                }
                uVar28 = uVar28 + 1;
              } while ((long)uVar28 < (long)*(int *)(param_1 + 0xd68));
            }
          }
        }
        else {
          if (iVar5 < 0) {
            *(undefined8 *)(param_1 + 0xd50) = 0;
          }
          else {
            lVar16 = __kmalloc(-(uVar28 >> 0x1f & 1) & 0xfffffff800000000 |
                               (uVar28 & 0xffffffff) << 3,0xdc0);
            *(long *)(param_1 + 0xd50) = lVar16;
            if (lVar16 != 0) {
              uVar7 = dsi_display_get_active_displays(lVar16,*(undefined4 *)(param_1 + 0xd48));
              *(undefined4 *)(param_1 + 0xd48) = uVar7;
              goto LAB_001ca328;
            }
          }
          _printk(&DAT_002eb624,"_sde_kms_get_displays",0x70c);
LAB_001cacb4:
          kfree(*(undefined8 *)(param_1 + 0xd50));
          *(undefined4 *)(param_1 + 0xd48) = 0;
          *(undefined8 *)(param_1 + 0xd50) = 0;
        }
        uVar6 = *(uint *)(lVar12 + 0x1850);
        uVar28 = (ulong)uVar6;
        if (uVar6 == 0) {
          iVar5 = 0;
        }
        else {
          if (uVar6 - 0xd < 0xfffffff4) {
LAB_001cb318:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1cb31c);
            (*pcVar3)();
          }
          iVar5 = 0;
          pbVar24 = (byte *)(lVar12 + 0x18a0);
          do {
            uVar28 = uVar28 - 1;
            iVar5 = iVar5 + (uint)*pbVar24;
            pbVar24 = pbVar24 + 0x58;
          } while (uVar28 != 0);
        }
        uVar6 = uVar6 - iVar5;
        if (*(int *)(lVar12 + 0x14e8) == 0) {
          uVar30 = 0;
        }
        else {
          uVar13 = 0;
          uVar34 = 0;
          uVar22 = ~(-1L << ((ulong)uVar6 & 0x3f));
          uVar30 = 0;
          puVar11 = (undefined4 *)(lVar12 + 0x1500);
          do {
            if (uVar13 == 0xc) goto LAB_001cb318;
            uVar28 = sde_plane_init(lVar27,*puVar11,(int)uVar30 < (int)uVar6,uVar22,0);
            if (0xfffffffffffff000 < uVar28) {
              puVar10 = &DAT_002eea01;
              uVar19 = 0x8e4;
              goto LAB_001cafdc;
            }
            uVar33 = *(uint *)(lVar29 + 0x270);
            *(uint *)(lVar29 + 0x270) = uVar33 + 1;
            if (0x13 < uVar33) goto LAB_001cb318;
            *(ulong *)(lVar29 + (ulong)uVar33 * 8 + 0x278) = uVar28;
            if ((int)uVar30 < (int)uVar6) {
              if (0x13 < uVar30) goto LAB_001cb318;
              local_2a0[uVar30] = uVar28;
              uVar30 = uVar30 + 1;
            }
            if ((((((uint)*(undefined8 *)(puVar11 + 4) >> 10 & 1) != 0) ||
                 (((uint)*(undefined8 *)(puVar11 + 4) >> 0xb & 1) != 0)) ||
                (((uint)*(undefined8 *)(puVar11 + 4) >> 0xc & 1) != 0)) && (sdecustom != '\0')) {
              uVar33 = *(int *)(*(long *)(puVar11 + 8) + 0x24) - 1;
              if (0x13 < uVar33) goto LAB_001cb318;
              lVar16 = (ulong)uVar33 * 4;
              uVar34 = (ulong)((int)uVar34 + 1);
              uVar7 = *(undefined4 *)(uVar28 + 0x68);
              *(undefined4 *)((long)local_2a0 + lVar16 + -0x50) = *puVar11;
              *(undefined4 *)((long)&local_340 + lVar16) = uVar7;
            }
            uVar13 = uVar13 + 1;
            puVar11 = puVar11 + 0x12;
          } while (uVar13 < *(uint *)(lVar12 + 0x14e8));
          if ((int)uVar34 != 0) {
            lVar16 = 0;
LAB_001cae2c:
            if (lVar16 != 0x50) {
              if (lVar16 == 0x50) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(1,0x1cb2fc);
                (*pcVar3)();
              }
              uVar28 = sde_plane_init(lVar27,*(undefined4 *)((long)local_2a0 + lVar16 + -0x50),0,
                                      uVar22,*(undefined4 *)((long)&local_340 + lVar16));
              if (0xfffffffffffff000 < uVar28) {
                puVar10 = &DAT_002a5048;
                uVar19 = 0x8fc;
LAB_001cafdc:
                _printk(puVar10,"_sde_kms_drm_obj_init",uVar19);
                goto LAB_001cafe0;
              }
              uVar33 = *(uint *)(lVar29 + 0x270);
              *(uint *)(lVar29 + 0x270) = uVar33 + 1;
              if (uVar33 < 0x14) goto code_r0x001cae78;
            }
            goto LAB_001cb318;
          }
        }
LAB_001cae94:
        if ((int)uVar30 <= (int)uVar6) {
          uVar6 = uVar30;
        }
        if (0 < (int)uVar6) {
          lVar16 = 0;
          do {
            if (lVar16 == 0xa0) goto LAB_001cb318;
            uVar28 = sde_crtc_init(lVar27,*(undefined8 *)((long)local_2a0 + lVar16));
            if (0xfffffffffffff000 < uVar28) goto LAB_001cafe0;
            uVar30 = *(uint *)(lVar29 + 0x318);
            *(uint *)(lVar29 + 0x318) = uVar30 + 1;
            if (0xf < uVar30) goto LAB_001cb318;
            lVar16 = lVar16 + 8;
            *(ulong *)(lVar29 + (ulong)uVar30 * 8 + 800) = uVar28;
          } while ((ulong)uVar6 * 8 != lVar16);
        }
        if ((sdecustom != '\0') && (*(int *)(lVar29 + 0x270) != 0)) {
          uVar28 = 0;
          do {
            if (uVar28 == 0x14) goto LAB_001cb318;
            lVar27 = uVar28 * 8;
            uVar28 = uVar28 + 1;
            *(int *)(*(long *)(lVar29 + 0x278 + lVar27) + 0x88) =
                 ~(-1 << (ulong)(*(uint *)(lVar29 + 0x318) & 0x1f));
          } while (uVar28 < *(uint *)(lVar29 + 0x270));
        }
        if (*(int *)(lVar29 + 0xe08) != 0) {
          uVar28 = 0;
          lVar27 = lVar29 + 0xe10;
          do {
            if (uVar28 == 0x10) goto LAB_001cb318;
            *(int *)(*(long *)(lVar27 + uVar28 * 8) + 0x48) =
                 ~(-1 << (ulong)(*(uint *)(lVar29 + 0x318) & 0x1f));
            if (*(int *)(lVar12 + 0x5080) != 0) {
              uVar7 = sde_encoder_get_clones(*(undefined8 *)(lVar27 + uVar28 * 8));
              *(undefined4 *)(*(long *)(lVar27 + uVar28 * 8) + 0x4c) = uVar7;
            }
            uVar28 = uVar28 + 1;
          } while (uVar28 < *(uint *)(lVar29 + 0xe08));
        }
        goto LAB_001cb16c;
      }
      _printk(&DAT_002de9f4,"_sde_kms_drm_obj_init",0x8c2);
      uVar28 = 0xffffffea;
      goto LAB_001cb29c;
    }
    uVar28 = 0xffffffea;
LAB_001c9f8c:
    puVar10 = &DAT_002b1e12;
    pcVar18 = "_sde_kms_hw_init_blocks";
    uVar19 = 0x1414;
    goto LAB_001cb290;
  }
  goto LAB_001c9aa8;
code_r0x001cae78:
  lVar16 = lVar16 + 4;
  *(ulong *)(lVar29 + (ulong)uVar33 * 8 + 0x278) = uVar28;
  if (uVar34 * 4 == lVar16) goto LAB_001cae94;
  goto LAB_001cae2c;
LAB_001cafe0:
  if (*(long *)(param_1 + 0x80) == 0) {
    puVar10 = &DAT_002f5132;
    uVar19 = 0x896;
LAB_001cb2f0:
    _printk(puVar10,"_sde_kms_drm_obj_destroy",uVar19);
  }
  else {
    lVar27 = *(long *)(*(long *)(param_1 + 0x80) + 0x38);
    if (lVar27 == 0) {
      puVar10 = &DAT_002f1aa1;
      uVar19 = 0x899;
      goto LAB_001cb2f0;
    }
    if (*(int *)(lVar27 + 0x318) != 0) {
      uVar13 = 0;
      do {
        if (uVar13 == 0x10) goto LAB_001cb318;
        pcVar3 = *(code **)(*(long *)(*(long *)(lVar27 + 800 + uVar13 * 8) + 0x1a8) + 0x28);
        if (*(int *)(pcVar3 + -4) != -0x727df461) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1cb02c);
          (*pcVar3)();
        }
        (*pcVar3)();
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(uint *)(lVar27 + 0x318));
    }
    *(undefined4 *)(lVar27 + 0x318) = 0;
    if (*(int *)(lVar27 + 0x270) != 0) {
      uVar13 = 0;
      do {
        if (uVar13 == 0x14) goto LAB_001cb318;
        pcVar3 = *(code **)(*(long *)(*(long *)(lVar27 + 0x278 + uVar13 * 8) + 200) + 0x10);
        if (*(int *)(pcVar3 + -4) != 0x2bdb1eea) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1cb080);
          (*pcVar3)();
        }
        (*pcVar3)();
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(uint *)(lVar27 + 0x270));
    }
    *(undefined4 *)(lVar27 + 0x270) = 0;
    if (*(int *)(lVar27 + 0xf18) != 0) {
      uVar13 = 0;
      do {
        if (uVar13 == 0x10) goto LAB_001cb318;
        pcVar3 = *(code **)(*(long *)(*(long *)(lVar27 + 0xf20 + uVar13 * 8) + 400) + 0x40);
        if (*(int *)(pcVar3 + -4) != -0x7a23270a) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1cb0d4);
          (*pcVar3)();
        }
        (*pcVar3)();
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(uint *)(lVar27 + 0xf18));
    }
    *(undefined4 *)(lVar27 + 0xf18) = 0;
    if (*(int *)(lVar27 + 0xe08) != 0) {
      uVar13 = 0;
      do {
        if (uVar13 == 0x10) goto LAB_001cb318;
        pcVar3 = *(code **)(*(long *)(*(long *)(lVar27 + 0xe10 + uVar13 * 8) + 0x68) + 8);
        if (*(int *)(pcVar3 + -4) != 0x66c7290e) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1cb128);
          (*pcVar3)();
        }
        (*pcVar3)();
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(uint *)(lVar27 + 0xe08));
    }
    *(undefined4 *)(lVar27 + 0xe08) = 0;
    kfree(*(undefined8 *)(param_1 + 0xd60));
    *(undefined8 *)(param_1 + 0xd60) = 0;
    *(undefined4 *)(param_1 + 0xd58) = 0;
    kfree(*(undefined8 *)(param_1 + 0xd50));
    *(undefined8 *)(param_1 + 0xd50) = 0;
    *(undefined4 *)(param_1 + 0xd48) = 0;
  }
  sde_core_irq_domain_fini(param_1);
  if ((int)uVar28 == 0) {
LAB_001cb16c:
    *(undefined4 *)(lVar26 + 0x398) = *(undefined4 *)(*(long *)(param_1 + 0x90) + 0x5058);
    *(undefined4 *)(lVar26 + 0x39c) = *(undefined4 *)(*(long *)(param_1 + 0x90) + 0x505c);
    *(undefined4 *)(lVar26 + 0x3a0) = *(undefined4 *)(*(long *)(param_1 + 0x90) + 0x5050);
    *(undefined4 *)(lVar26 + 0x3a4) = *(undefined4 *)(*(long *)(param_1 + 0x90) + 0x5054);
    __mutex_init(param_1 + 0xda8,"&sde_kms->secure_transition_lock",&sde_kms_hw_init___key);
    *(undefined4 *)(param_1 + 0xd9c) = 0;
    *(undefined4 *)(param_1 + 0xda0) = 0;
    *(undefined4 *)(param_1 + 0xde8) = 0;
    *(code **)(param_1 + 0x1828) = sde_kms_irq_affinity_notify;
    *(code **)(param_1 + 0x1830) = sde_kms_irq_affinity_release;
    uVar7 = platform_get_irq(*(long *)(*(long *)(param_1 + 0x80) + 8) + -0x10,0);
    if ((__drm_debug >> 2 & 1) != 0) {
      ___drm_dbg(0,0,"Registering for notification of irq_num: %d\n",uVar7);
    }
    irq_set_affinity_notifier(uVar7,param_1 + 0x17f0);
    if ((*puVar20 == 0) || (*(char *)(*puVar20 + 0x4ac8) == '\0')) {
      uVar13 = sde_vm_primary_init(param_1);
      uVar19 = 1;
    }
    else {
      uVar13 = sde_vm_trusted_init(param_1);
      uVar19 = 0;
    }
    uVar28 = uVar13 & 0xffffffff;
    sde_dbg_set_hw_ownership_status(uVar19);
    if ((int)uVar13 == 0) goto LAB_001c97d0;
    puVar10 = &DAT_002c4a5f;
    pcVar18 = "sde_kms_hw_init";
    uVar19 = 0x152e;
LAB_001cb290:
    _printk(puVar10,pcVar18,uVar19,uVar28 & 0xffffffff);
  }
  else {
LAB_001cb29c:
    puVar10 = &DAT_002e28a4;
    uVar19 = 0x1495;
LAB_001cb2b0:
    _printk(puVar10,"_sde_kms_hw_init_blocks",uVar19,uVar28 & 0xffffffff);
    sde_core_perf_destroy(param_1 + 0x780);
  }
LAB_001c9aa8:
  _sde_kms_hw_destroy(param_1,lVar25);
LAB_001c97d0:
  lVar26 = sp_el0;
  if (*(long *)(lVar26 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar28 & 0xffffffff;
}



//------------------------------------------------------------
// sde_plane_init @ 001d6950 size=4980
// signature: undefined sde_plane_init(void)
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long sde_plane_init(long param_1,undefined4 param_2,uint param_3,undefined8 param_4,int param_5)

{
  ulong *puVar1;
  char cVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  long lVar14;
  uint uVar15;
  long lVar16;
  long lVar17;
  int *piVar18;
  long lVar19;
  long *plVar20;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
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
  
  lVar17 = sp_el0;
  local_70 = *(long *)(lVar17 + 0x638);
  local_180 = 0;
  uStack_178 = 0;
  local_190 = 0;
  local_188 = 0;
  if (param_1 == 0) {
    puVar11 = &DAT_002cd771;
    uVar13 = 0x13d6;
LAB_001d6d60:
    _printk(puVar11,"sde_plane_init",uVar13,param_2);
    iVar7 = -0x16;
  }
  else {
    lVar17 = *(long *)(param_1 + 0x38);
    if (lVar17 == 0) {
      puVar11 = &DAT_002df292;
      uVar13 = 0x13dc;
      goto LAB_001d6d60;
    }
    lVar19 = *(long *)(lVar17 + 8);
    if (lVar19 == 0) {
      puVar11 = &DAT_002e590d;
      uVar13 = 0x13e1;
      goto LAB_001d6d60;
    }
    if (*(long *)(lVar19 + 0x90) == 0) {
      puVar11 = &DAT_002eb6a7;
      uVar13 = 0x13e7;
      goto LAB_001d6d60;
    }
    lVar8 = kmalloc_trace(_kthread_park,0xdc0,0xd20);
    if (lVar8 == 0) {
      _printk(&DAT_002f579c,"sde_plane_init",0x13ee,param_2);
      iVar7 = -0xc;
    }
    else {
      lVar16 = lVar8 + 0x718;
      *(undefined4 *)(lVar8 + 0x558) = param_2;
      *(bool *)(lVar8 + 0x714) = param_5 != 0;
      *(long *)(lVar8 + 0x718) = lVar16;
      *(long *)(lVar8 + 0x720) = lVar16;
      lVar9 = drm_mode_object_find(param_1,0,param_5,0xeeeeeeee);
      if ((lVar9 != 0) && (lVar9 != 0x68)) {
        plVar20 = *(long **)(lVar9 + 0x6b8);
        uVar10 = __list_add_valid(lVar16,plVar20,lVar9 + 0x6b0);
        if ((uVar10 & 1) != 0) {
          *(long *)(lVar9 + 0x6b8) = lVar16;
          *(long *)(lVar8 + 0x718) = lVar9 + 0x6b0;
          *(long **)(lVar8 + 0x720) = plVar20;
          *plVar20 = lVar16;
        }
      }
      uVar10 = sde_hw_sspp_init(param_2,*(undefined8 *)(lVar19 + 0x6c0),
                                *(undefined8 *)(lVar19 + 0x90),*(undefined1 *)(lVar8 + 0x714),
                                &local_190);
      *(ulong *)(lVar8 + 0x670) = uVar10;
      if (uVar10 < 0xfffffffffffff001) {
        lVar16 = *(long *)(uVar10 + 0x38);
        if ((lVar16 == 0) || (*(long *)(lVar16 + 0x30) == 0)) {
          _printk(&DAT_002d94af,"sde_plane_init",0x1407,param_2);
          iVar7 = -0x16;
LAB_001d6cd8:
          lVar17 = *(long *)(lVar8 + 0x670);
        }
        else {
          if ((*(ulong *)(*(long *)(lVar19 + 0x90) + 0x5220) >> 0x27 & 1) == 0) {
            iVar7 = -0x16;
LAB_001d6aa4:
            *(undefined8 *)(lVar8 + 0x560) = *(undefined8 *)(lVar16 + 0x20);
            *(int *)(lVar8 + 0x568) = (int)*(undefined8 *)(*(long *)(uVar10 + 0x38) + 0x28);
            lVar16 = *(long *)(*(long *)(uVar10 + 0x38) + 0x30);
            *(long *)(lVar8 + 0x9b8) = lVar16;
            if (lVar16 == 0) {
              puVar11 = &DAT_002b82dd;
              uVar13 = 0x1419;
            }
            else {
              lVar9 = 0x4c8;
              if (*(char *)(lVar8 + 0x714) != '\0') {
                lVar9 = 0x4d0;
              }
              iVar6 = sde_populate_formats(*(undefined8 *)(lVar16 + lVar9),lVar8 + 0x570,0,0x40);
              *(int *)(lVar8 + 0x56c) = iVar6;
              if (iVar6 != 0) {
                iVar7 = drm_universal_plane_init
                                  (param_1,lVar8,0xff,&sde_plane_funcs,lVar8 + 0x570,iVar6,0,
                                   param_3 & 1,0);
                if (iVar7 != 0) goto LAB_001d6cd8;
                DAT_00319f48 = 0x200000001;
                DAT_00319f60 = 0x100000000;
                DAT_00319f38 = 0x800000001;
                plane_prop_array = 0x200000002;
                DAT_00319ed4 = 0x100000000;
                lVar16 = lVar8 + 0x9d0;
                DAT_00319f14 = 0xfff8021f00000000;
                DAT_00319f1c = 0x100000001;
                DAT_00319ef0 = 0x4000000020;
                DAT_00319f40 = 0x100000008;
                DAT_00319f28 = 0xfff8021f;
                DAT_00319f2c = 0xfff8021f;
                DAT_00319eec = 0xfff8021f;
                DAT_00319f68 = 0xfff8021f00000010;
                DAT_00319f30 = 0xfff8021ffff8021f;
                DAT_00319edc = 0x100000001;
                DAT_00319ee4 = 0xfff8021ffff8021f;
                DAT_00319f00 = 0x100000000800;
                DAT_00319ef8 = 0x10000000080;
                DAT_00319f24 = 0;
                DAT_00319f50 = 0x400;
                DAT_00319f54 = 0x2000000002000;
                DAT_00319f70 = 0x800000004000;
                DAT_00319f08 = 1;
                DAT_00319f0c = 0x10000;
                DAT_00319f10 = 1;
                DAT_00319f5c = 0x40000;
                *(undefined ***)(lVar8 + 0x4e0) = &sde_plane_helper_funcs;
                msm_property_init(lVar16,(undefined4 *)(lVar8 + 0x68),param_1,lVar17 + 4000,
                                  lVar8 + 0xa50,0x2b,0x11,0x9b0);
                if (*(long *)(lVar8 + 0x670) == 0) {
                  bVar5 = *(long *)(lVar8 + 0x9b8) == 0;
LAB_001d7c60:
                  _printk(&DAT_002c7ba6,"_sde_plane_install_properties",0x100e,
                          *(long *)(lVar8 + 0x670) == 0,bVar5);
                }
                else {
                  if (*(long *)(lVar8 + 0x9b8) == 0) {
                    bVar5 = true;
                    goto LAB_001d7c60;
                  }
                  lVar17 = *(long *)(lVar19 + 0x90);
                  if (lVar17 == 0) {
                    _printk(&DAT_002dc433,"_sde_plane_install_properties",0x1011);
                  }
                  else {
                    cVar2 = *(char *)(lVar8 + 0x714);
                    *(long *)(lVar8 + 0x728) = lVar17;
                    lVar19 = vzalloc(0x400c);
                    if (lVar19 == 0) {
                      _printk(&DAT_002c1119,"_sde_plane_install_properties",0x101a);
                    }
                    else {
                      uVar10 = sde_is_custom_client();
                      if ((uVar10 & 1) == 0) {
                        if (*(int *)(lVar8 + 0x4d8) == 1) goto LAB_001d6cfc;
                        lVar9 = (long)(*(int *)(lVar8 + 0x4dc) + 1);
LAB_001d6e00:
                        lVar14 = 0xff;
                      }
                      else {
                        if ((*(int *)(lVar17 + 0x1850) == 0) ||
                           (iVar7 = *(int *)(*(long *)(lVar17 + 0x1888) + 4), iVar7 == 0)) {
LAB_001d6cfc:
                          lVar9 = 0;
                          goto LAB_001d6e00;
                        }
                        iVar7 = iVar7 + -1;
                        if ((((uint)*(undefined8 *)(lVar17 + 0x5220) >> 0xe & 1) == 0) ||
                           (iVar7 < 0xc)) {
                          if (9 < iVar7) {
                            iVar7 = 10;
                          }
                          lVar9 = 0;
                          lVar14 = (long)iVar7;
                        }
                        else {
                          lVar9 = 0;
                          lVar14 = 0xb;
                        }
                      }
                      puVar1 = (ulong *)(lVar8 + 0x560);
                      plVar20 = (long *)(lVar8 + 0x9b8);
                      msm_property_install_range(lVar16,&DAT_002fefaf,0,0,lVar14,lVar9,0x11);
                      msm_property_install_range(lVar16,"alpha",0,0,0xff,0xff,0x12);
                      msm_property_install_range(lVar16,"input_fence",0,0,0x1000,0,0x16);
                      if (cVar2 == '\0') {
                        lVar9 = *plVar20;
                        local_80 = 0;
                        uStack_78 = 0;
                        local_90 = 0;
                        uStack_88 = 0;
                        local_a0 = 0;
                        uStack_98 = 0;
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
                        local_170 = 0;
                        uStack_168 = 0;
                        if (*(int *)(lVar9 + 0x1c) != 0) {
                          msm_property_install_range
                                    (lVar16,"h_decimate",0,0,*(int *)(lVar9 + 0x1c),0,0x14);
                          lVar9 = *plVar20;
                        }
                        if (*(int *)(lVar9 + 0x20) != 0) {
                          msm_property_install_range
                                    (lVar16,"v_decimate",0,0,*(int *)(lVar9 + 0x20),0,0x15);
                        }
                        uVar15 = (uint)*puVar1;
                        if ((uVar15 >> 3 & 1) == 0) {
                          if ((uVar15 >> 0x16 & 1) != 0) {
                            msm_property_install_range
                                      (lVar16,"scaler_v2",0,0,0xffffffffffffffff,0,0x1f);
                            goto LAB_001d7074;
                          }
                          if ((*puVar1 & 0x40000c) != 0) {
                            msm_property_install_range
                                      (lVar16,"scaler_v1",0,0,0xffffffffffffffff,0,0x1e);
                          }
                        }
                        else {
                          msm_property_install_range
                                    (lVar16,"scaler_v2",0,0,0xffffffffffffffff,0,0x1f);
                          msm_property_install_blob(lVar16,"lut_ed",0,3);
                          msm_property_install_blob(lVar16,"lut_cir",0,4);
LAB_001d7074:
                          msm_property_install_blob(lVar16,"lut_sep",0,5);
                        }
                        uVar15 = (uint)*puVar1;
                        if ((*puVar1 & 0x30) != 0) {
                          msm_property_install_volatile_range
                                    (lVar16,"csc_v1",0,0,0xffffffffffffffff,0,0);
                          uVar15 = (uint)*puVar1;
                        }
                        if ((uVar15 >> 6 & 1) != 0) {
                          snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_HUE_V",
                                   (ulong)*(ushort *)(*plVar20 + 0xc2));
                          msm_property_install_range(lVar16,&local_170,0,0,0xffffffff,0,0x17);
                          snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_SATURATION_V",
                                   (ulong)*(ushort *)(*plVar20 + 0xc2));
                          msm_property_install_range(lVar16,&local_170,0,0,0xffffffff,0,0x18);
                          snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_VALUE_V",
                                   (ulong)*(ushort *)(*plVar20 + 0xc2));
                          msm_property_install_range(lVar16,&local_170,0,0,0xffffffff,0,0x19);
                          snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_CONTRAST_V",
                                   (ulong)*(ushort *)(*plVar20 + 0xc2));
                          msm_property_install_range(lVar16,&local_170,0,0,0xffffffff,0,0x1a);
                        }
                      }
                      else {
                        msm_property_install_enum
                                  (lVar16,"multirect_mode",0,0,
                                   _sde_plane_install_properties_e_multirect_mode,3,0,0x28);
                      }
                      if ((*(byte *)(lVar8 + 0x561) >> 1 & 1) != 0) {
                        msm_property_install_volatile_range
                                  (lVar16,"excl_rect_v1",0,0,0xffffffffffffffff,0,0x1b);
                      }
                      uVar12 = 0x35;
                      if ((*(char *)(lVar8 + 0x714) == '\0') &&
                         (uVar12 = 0x35, (*(byte *)(lVar8 + 0x562) & 0x80) != 0)) {
                        uVar12 = 0x3f;
                      }
                      iVar7 = drm_plane_create_rotation_property(lVar8,1,uVar12);
                      if (iVar7 != 0) {
                        __drm_err("create rotation property failed: %d\n",iVar7);
                      }
                      msm_property_install_enum
                                (lVar16,"blend_op",0,0,_sde_plane_install_properties_e_blend_op,5,0,
                                 0x25);
                      msm_property_install_enum
                                (lVar16,"src_config",0,1,_sde_plane_install_properties_e_src_config,
                                 1,0,0x26);
                      if (*(long *)(*(long *)(lVar8 + 0x670) + 0x78) != 0) {
                        msm_property_install_range(lVar16,"color_fill",0,0,0xffffffff,0,0x13);
                      }
                      msm_property_install_range
                                (lVar16,"prefill_size",0,0,0xffffffffffffffff,0,0x1c);
                      msm_property_install_range
                                (lVar16,"prefill_time",0,0,0xffffffffffffffff,0,0x1d);
                      msm_property_install_blob(lVar16,"capabilities",4,2);
                      sde_kms_info_reset(lVar19);
                      if (*(char *)(lVar8 + 0x714) == '\0') {
                        piVar18 = *(int **)(*(long *)(lVar8 + 0x9b8) + 0x4c8);
                      }
                      else {
                        piVar18 = *(int **)(*(long *)(lVar8 + 0x9b8) + 0x4d0);
                        sde_kms_info_add_keyint(lVar19,"primary_smart_plane_id",param_5);
                      }
                      if (piVar18 != (int *)0x0) {
                        sde_kms_info_start(lVar19,"pixel_formats");
                        iVar7 = *piVar18;
                        if (iVar7 != 0) {
                          do {
                            sde_kms_info_append_format(lVar19,iVar7,*(undefined8 *)(piVar18 + 2));
                            iVar7 = piVar18[4];
                            piVar18 = piVar18 + 4;
                          } while (iVar7 != 0);
                        }
                        sde_kms_info_stop(lVar19);
                      }
                      if ((*(long *)(lVar8 + 0x670) != 0) && (*(int *)(lVar17 + 0x10) != 0)) {
                        sde_kms_info_add_keyint(lVar19,"scaler_step_ver");
                      }
                      sde_kms_info_add_keyint
                                (lVar19,"max_linewidth",**(undefined4 **)(lVar8 + 0x9b8));
                      sde_kms_info_add_keyint
                                (lVar19,"max_upscale",
                                 *(undefined4 *)(*(long *)(lVar8 + 0x9b8) + 0x18));
                      sde_kms_info_add_keyint
                                (lVar19,"max_downscale",
                                 *(undefined4 *)(*(long *)(lVar8 + 0x9b8) + 0x14));
                      sde_kms_info_add_keyint
                                (lVar19,"max_horizontal_deci",
                                 *(undefined4 *)(*(long *)(lVar8 + 0x9b8) + 0x1c));
                      sde_kms_info_add_keyint
                                (lVar19,"max_vertical_deci",
                                 *(undefined4 *)(*(long *)(lVar8 + 0x9b8) + 0x20));
                      sde_kms_info_add_keyint
                                (lVar19,"max_per_pipe_bw",
                                 (ulong)*(uint *)(*(long *)(lVar8 + 0x9b8) + 0x28) * 1000);
                      sde_kms_info_add_keyint
                                (lVar19,"max_per_pipe_bw_high",
                                 (ulong)*(uint *)(*(long *)(lVar8 + 0x9b8) + 0x2c) * 1000);
                      uVar3 = *(int *)(lVar8 + 0x558) - 5;
                      uVar15 = *(int *)(lVar8 + 0x558) - 1;
                      if (5 < uVar3) {
                        uVar3 = 0xffffffff;
                      }
                      if (3 < uVar15) {
                        uVar15 = uVar3;
                      }
                      sde_kms_info_add_keyint(lVar19,"pipe_idx",(long)(int)uVar15);
                      if (((uint)*(undefined8 *)(lVar17 + 0x5220) >> 0x17 & 1) != 0) {
                        if (10 < *(uint *)(lVar8 + 0x558)) {
                    /* WARNING: Does not return */
                          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1d7cc4);
                          (*pcVar4)();
                        }
                        if (*(int *)(lVar17 + (ulong)*(uint *)(lVar8 + 0x558) * 8 +
                                     (ulong)(param_5 != 0) * 4 + 0x4a70) != -1) {
                          sde_kms_info_add_keyint(lVar19,"demura_block");
                        }
                      }
                      uVar15 = (uint)*puVar1;
                      if ((uVar15 >> 0x14 & 1) != 0) {
                        sde_kms_info_add_keyint(lVar19,"sec_ui_allowed",1);
                        uVar15 = (uint)*puVar1;
                      }
                      if ((uVar15 >> 0x15 & 1) != 0) {
                        sde_kms_info_add_keyint(lVar19,"block_sec_ui",1);
                        uVar15 = (uint)*puVar1;
                      }
                      if ((uVar15 >> 0x17 & 1) != 0) {
                        sde_kms_info_add_keyint
                                  (lVar19,"true_inline_rot_rev",*(undefined4 *)(lVar17 + 0x28));
                        uVar15 = *(uint *)(*plVar20 + 0x4e4);
                        uVar3 = 0;
                        if (uVar15 != 0) {
                          uVar3 = *(uint *)(*plVar20 + 0x4e0) / uVar15;
                        }
                        sde_kms_info_add_keyint(lVar19,"true_inline_dwnscale_rt",(long)(int)uVar3);
                        sde_kms_info_add_keyint
                                  (lVar19,"true_inline_dwnscale_rt_numerator",
                                   *(undefined4 *)(*plVar20 + 0x4e0));
                        sde_kms_info_add_keyint
                                  (lVar19,"true_inline_dwnscale_rt_denominator",
                                   *(undefined4 *)(*plVar20 + 0x4e4));
                        sde_kms_info_add_keyint
                                  (lVar19,"true_inline_dwnscale_nrt",
                                   *(undefined4 *)(*plVar20 + 0x4e8));
                        sde_kms_info_add_keyint
                                  (lVar19,"true_inline_max_height",*(undefined4 *)(*plVar20 + 0x4f4)
                                  );
                        piVar18 = *(int **)(*plVar20 + 0x4d8);
                        if (piVar18 != (int *)0x0) {
                          sde_kms_info_start(lVar19,"inline_rot_pixel_formats");
                          iVar7 = *piVar18;
                          if (iVar7 != 0) {
                            do {
                              sde_kms_info_append_format(lVar19,iVar7,*(undefined8 *)(piVar18 + 2));
                              iVar7 = piVar18[4];
                              piVar18 = piVar18 + 4;
                            } while (iVar7 != 0);
                          }
                          sde_kms_info_stop(lVar19);
                        }
                      }
                      uVar10 = *(ulong *)(lVar8 + 0x560);
                      local_80 = 0;
                      uStack_78 = 0;
                      local_90 = 0;
                      uStack_88 = 0;
                      local_a0 = 0;
                      uStack_98 = 0;
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
                      local_170 = 0;
                      uStack_168 = 0;
                      if (((uVar10 & 0x20000) == 0 || *(char *)(lVar8 + 0x714) != '\0') &&
                         (((uint)uVar10 >> 0x12 & 1) == 0)) {
                        if (((uint)uVar10 >> 0x13 & 1) != 0) goto LAB_001d7810;
LAB_001d7664:
                        if (((uint)uVar10 >> 7 & 1) != 0) goto LAB_001d7850;
LAB_001d7668:
                        if (((uint)uVar10 >> 0xe & 1) != 0) goto LAB_001d78fc;
LAB_001d766c:
                        if (((uint)uVar10 >> 0xd & 1) != 0) goto LAB_001d793c;
LAB_001d7670:
                        if (((uint)uVar10 >> 0xf & 1) != 0) goto LAB_001d797c;
LAB_001d7674:
                        if (((uint)uVar10 >> 0x10 & 1) != 0) goto LAB_001d79bc;
LAB_001d7678:
                        if (((uint)uVar10 >> 0x1c & 1) != 0) goto LAB_001d79fc;
LAB_001d767c:
                        if (((uint)uVar10 >> 0x1d & 1) != 0) goto LAB_001d7a48;
LAB_001d7680:
                        if (((uint)uVar10 >> 0x1e & 1) != 0) goto LAB_001d7a88;
LAB_001d7684:
                        iVar7 = (int)uVar10;
                      }
                      else {
                        msm_property_install_range(lVar16,"inverse_pma",0,0,1,0,0x20);
                        sde_kms_info_add_keyint(lVar19,"inverse_pma",1);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0x13 & 1) == 0) goto LAB_001d7664;
LAB_001d7810:
                        msm_property_install_volatile_range
                                  (lVar16,"csc_dma_v1",0,0,0xffffffffffffffff,0,1);
                        sde_kms_info_add_keyint(lVar19,"csc_dma_v1",1);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 7 & 1) == 0) goto LAB_001d7668;
LAB_001d7850:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_SKIN_COLOR_V",
                                 (ulong)*(ushort *)(*plVar20 + 0xe6));
                        msm_property_install_blob(lVar16,&local_170,0,6);
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_SKY_COLOR_V",
                                 (ulong)*(ushort *)(*plVar20 + 0xe6));
                        msm_property_install_blob(lVar16,&local_170,0,7);
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_FOLIAGE_COLOR_V",
                                 (ulong)*(ushort *)(*plVar20 + 0xe6));
                        msm_property_install_blob(lVar16,&local_170,0,8);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0xe & 1) == 0) goto LAB_001d766c;
LAB_001d78fc:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_VIG_3D_LUT_GAMUT_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x12e));
                        msm_property_install_blob(lVar16,&local_170,0,9);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0xd & 1) == 0) goto LAB_001d7670;
LAB_001d793c:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_VIG_1D_LUT_IGC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x156));
                        msm_property_install_blob(lVar16,&local_170,0,10);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0xf & 1) == 0) goto LAB_001d7674;
LAB_001d797c:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_DGM_1D_LUT_IGC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x156));
                        msm_property_install_blob(lVar16,&local_170,0,0xb);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0x10 & 1) == 0) goto LAB_001d7678;
LAB_001d79bc:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_DGM_1D_LUT_GC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x1a2));
                        msm_property_install_blob(lVar16,&local_170,0,0xc);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0x1c & 1) == 0) goto LAB_001d767c;
LAB_001d79fc:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_FP16_IGC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x23a));
                        msm_property_install_range(lVar16,&local_170,0,0,1,0,0x21);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0x1d & 1) == 0) goto LAB_001d7680;
LAB_001d7a48:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_FP16_GC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x286));
                        msm_property_install_blob(lVar16,&local_170,0,0xd);
                        uVar10 = *puVar1;
                        if (((uint)uVar10 >> 0x1e & 1) == 0) goto LAB_001d7684;
LAB_001d7a88:
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_FP16_CSC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x2d2));
                        msm_property_install_blob(lVar16,&local_170,0,0xe);
                        uVar10 = *puVar1;
                        iVar7 = (int)uVar10;
                      }
                      if (iVar7 < 0) {
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_FP16_UNMULT_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x31e));
                        msm_property_install_range(lVar16,&local_170,0,0,1,0,0x22);
                        uVar10 = *puVar1;
                      }
                      if ((uVar10 >> 0x23 & 1) != 0) {
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_UCSC_IGC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x36a));
                        msm_property_install_volatile_enum
                                  (lVar16,&local_170,0,0,
                                   _sde_plane_install_colorproc_properties_ucsc_igc,6,0,0x29);
                        uVar10 = *puVar1;
                      }
                      if ((uVar10 >> 0x24 & 1) != 0) {
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_UCSC_GC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x3b6));
                        msm_property_install_volatile_enum
                                  (lVar16,&local_170,0,0,
                                   _sde_plane_install_colorproc_properties_ucsc_gc,5,0,0x2a);
                        uVar10 = *puVar1;
                      }
                      if ((uVar10 >> 0x25 & 1) != 0) {
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_UCSC_CSC_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x402));
                        msm_property_install_blob(lVar16,&local_170,0,0x10);
                        uVar10 = *puVar1;
                      }
                      if ((uVar10 >> 0x26 & 1) != 0) {
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_UCSC_UNMULT_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x44e));
                        msm_property_install_volatile_range(lVar16,&local_170,0,0,1,0,0x23);
                        uVar10 = *puVar1;
                      }
                      if ((uVar10 >> 0x27 & 1) != 0) {
                        snprintf((char *)&local_170,0x100,"%s%d","SDE_SSPP_UCSC_ALPHA_DITHER_V",
                                 (ulong)*(ushort *)(*plVar20 + 0x49a));
                        msm_property_install_volatile_range(lVar16,&local_170,0,0,1,0,0x24);
                      }
                      msm_property_set_blob
                                (lVar16,lVar8 + 0xd00,lVar19,*(int *)(lVar19 + 0x4000) + 1,2);
                      msm_property_install_enum
                                (lVar16,"fb_translation_mode",0,0,
                                 _sde_plane_install_properties_e_fb_translation_mode,4,0,0x27);
                      if (*(long *)(*(long *)(lVar8 + 0x670) + 0x178) != 0) {
                        msm_property_install_volatile_range
                                  (lVar16,"ubwc_stats_roi",0,0,0xffffffffffffffff,0,0xf);
                      }
                      vfree(lVar19);
                    }
                  }
                }
                snprintf((char *)(lVar8 + 0x9c0),0xc,"plane%u",*(uint *)(lVar8 + 0x68));
                __mutex_init(lVar8 + 0x528,"&psde->lock",&sde_plane_init___key);
                if ((__drm_debug >> 2 & 1) != 0) {
                  ___drm_dbg(0,0,"%s created for pipe:%u id:%u master:%u\n",(char *)(lVar8 + 0x9c0),
                             param_2,*(undefined4 *)(lVar8 + 0x68),param_5);
                }
                goto LAB_001d6d70;
              }
              puVar11 = &DAT_002aefb8;
              uVar13 = 0x1428;
            }
          }
          else {
            iVar7 = sde_vbif_clk_register(lVar19,&local_190);
            if (iVar7 == 0) {
              uVar10 = *(ulong *)(lVar8 + 0x670);
              lVar16 = *(long *)(uVar10 + 0x38);
              goto LAB_001d6aa4;
            }
            puVar11 = &DAT_00304d60;
            uVar13 = 0x140f;
            param_2 = (undefined4)local_188;
          }
          _printk(puVar11,"sde_plane_init",uVar13,param_2);
          lVar17 = *(long *)(lVar8 + 0x670);
        }
        if (lVar17 != 0) {
          sde_hw_sspp_destroy();
        }
      }
      else {
        _printk(&DAT_002b82ae,"sde_plane_init",0x1403,param_2);
        iVar7 = *(int *)(lVar8 + 0x670);
      }
      kfree(lVar8);
    }
  }
  lVar8 = (long)iVar7;
LAB_001d6d70:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar8;
}



//------------------------------------------------------------
// sde_connector_esd_status @ 001dd5fc size=528
// signature: undefined sde_connector_esd_status(void)
//------------------------------------------------------------

undefined8 sde_connector_esd_status(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined1 auStack_1c8 [4];
  byte local_1c4;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar5 = 0;
  if (param_1 != 0) {
    if (*(long *)(param_1 + 0x8b8) == 0) {
      uVar5 = 0;
    }
    else {
      lVar1 = param_1 + 0x7d8;
      lVar6 = *(long *)(param_1 + 0x7a0);
      mutex_lock(lVar1);
      if (*(int *)(*(long *)(lVar6 + 0x110) + 0x8c0) == 0) {
        if (*(int *)(*(code **)(param_1 + 0x8b8) + -4) != 0x6a15147) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1dd674);
          (*pcVar2)();
        }
        iVar3 = (**(code **)(param_1 + 0x8b8))(param_1,*(undefined8 *)(param_1 + 0x7a0),1);
        mutex_unlock(lVar1);
        if (iVar3 < 1) {
          memset(auStack_1c8,0,400);
          if (*(char *)(param_1 + 0xe5d) != '\0') {
            if ((*(long *)(param_1 + 0x7a0) == 0) ||
               (pcVar2 = *(code **)(param_1 + 0x858), pcVar2 == (code *)0x0)) {
              _printk(&DAT_002c4d3f,"sde_connector_get_info",0x259);
              pcVar2 = *(code **)(param_1 + 0x8d8);
            }
            else {
              if (*(int *)(pcVar2 + -4) != -0x837836f) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1dd708);
                (*pcVar2)();
              }
              (*pcVar2)(param_1,auStack_1c8,*(long *)(param_1 + 0x7a0));
              pcVar2 = *(code **)(param_1 + 0x8d8);
            }
            if (pcVar2 != (code *)0x0) {
              if (*(int *)(pcVar2 + -4) != -0x672c52fe) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1dd730);
                (*pcVar2)();
              }
              uVar4 = (*pcVar2)(*(undefined8 *)(param_1 + 0x7a0));
              if ((((uVar4 & 1) == 0) && (*(long *)(param_1 + 0x8b8) != 0)) &&
                 ((local_1c4 >> 4 & 1) != 0)) {
                cancel_delayed_work_sync(param_1 + 0xdd0);
                *(undefined1 *)(param_1 + 0xe5d) = 0;
              }
            }
          }
          sde_connector_report_panel_dead(param_1,1);
          uVar5 = 0xffffff92;
        }
        else {
          if ((__drm_debug >> 2 & 1) != 0) {
            ___drm_dbg(0,0,"Successfully received TE from panel\n");
          }
          uVar5 = 0;
        }
        sde_evtlog_log(sde_dbg_base_evtlog,"sde_connector_esd_status",0xb92,0xffffffff,uVar5,
                       0xc0debeef);
      }
      else {
        _printk(&DAT_002d645f,"sde_connector_esd_status",0xb81);
        mutex_unlock(lVar1);
        uVar5 = 0xffffff92;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// sde_connector_init @ 001ddd80 size=4400
// signature: undefined sde_connector_init(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * sde_connector_init(long param_1,long param_2,long param_3,long param_4,void *param_5,
                         undefined1 param_6,int param_7)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined *puVar12;
  char *pcVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  long *plVar16;
  undefined **ppuVar17;
  code *pcVar18;
  long lVar19;
  char *__s1;
  long lVar20;
  long lVar21;
  long lVar22;
  uint *puVar23;
  undefined8 local_240;
  undefined4 uStack_238;
  undefined8 local_234;
  undefined8 local_22c;
  undefined1 auStack_220 [4];
  uint local_21c;
  int local_d0;
  ulong local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong local_78;
  long local_70;
  
  lVar21 = sp_el0;
  local_70 = *(long *)(lVar21 + 0x638);
  memset(auStack_220,0,400);
  if (((param_1 == 0) || (param_2 == 0)) || (lVar21 = *(long *)(param_1 + 0x38), lVar21 == 0)) {
    _printk(&DAT_002eb7f1,"sde_connector_init",0xda9,param_1,param_2);
    plVar9 = (long *)0xffffffffffffffea;
    goto LAB_001deba8;
  }
  if (*(long *)(lVar21 + 8) == 0) {
    _printk(&DAT_002af0e2,"sde_connector_init",0xdaf);
    plVar9 = (long *)0xffffffffffffffea;
    goto LAB_001deba8;
  }
  plVar9 = (long *)kmalloc_trace(_kthread_unpark,0xdc0,0x1030);
  if (plVar9 == (long *)0x0) {
    _printk(&DAT_002e2b1e,"sde_connector_init",0xdb5);
    plVar9 = (long *)0xfffffffffffffff4;
    goto LAB_001deba8;
  }
  memset(auStack_220,0,400);
  iVar4 = drm_connector_init(param_1,plVar9,sde_connector_ops,param_7);
  if (iVar4 == 0) {
    *(undefined4 *)(plVar9 + 0x1b3) = 0;
    plVar9[0xf3] = param_3;
    *(int *)(plVar9 + 0xf1) = param_7;
    plVar9[0xf2] = param_2;
    plVar9[0xf4] = param_4;
    plVar9[0x12f] = 0;
    *(undefined4 *)(plVar9 + 0x130) = 0;
    lVar22 = *(long *)(lVar21 + 8);
    if (*(long *)(lVar22 + 0x6d0) == 0) {
      lVar19 = *(long *)(lVar22 + 0x690);
      plVar16 = (long *)(lVar22 + 0x6a0);
    }
    else {
      lVar19 = *(long *)(lVar22 + 0x698);
      plVar16 = (long *)(lVar22 + 0x6a8);
    }
    plVar9[0xf7] = lVar19;
    plVar9[0xf8] = *plVar16;
    if (((param_5 == (void *)0x0) ||
        (memcpy(plVar9 + 0x102,param_5,0x168), *(long *)((long)param_5 + 0xe0) == 0)) ||
       (*(long *)((long)param_5 + 0xe8) == 0)) {
      ppuVar17 = &sde_connector_helper_ops;
    }
    else {
      ppuVar17 = &sde_connector_helper_ops_v2;
    }
    puVar23 = (uint *)(plVar9 + 8);
    plVar9[0xc1] = (long)ppuVar17;
    *(undefined1 *)(plVar9 + 0xc0) = param_6;
    *(undefined2 *)((long)plVar9 + 0xa4) = 0;
    *(undefined4 *)(plVar9 + 0x1d5) = *(undefined4 *)(*(long *)(lVar22 + 0x90) + 0x5288);
    snprintf((char *)(plVar9 + 0xf9),0x10,"conn%u",*puVar23);
    uVar10 = sde_fence_init(plVar9 + 0xf9,*puVar23);
    plVar9[0x101] = uVar10;
    if (uVar10 < 0xfffffffffffff001) {
      __mutex_init(plVar9 + 0xfb,"&c_conn->lock",&sde_connector_init___key);
      uVar5 = drm_connector_attach_encoder(plVar9,param_2);
      if (uVar5 == 0) {
        local_80 = 0;
        local_78 = 0;
        local_90 = 0;
        local_88 = 0;
        if ((*plVar9 == 0) || (lVar19 = *(long *)(*plVar9 + 0x38), lVar19 == 0)) {
          puVar12 = &DAT_003051d2;
          uVar11 = 0x33d;
LAB_001decb4:
          _printk(puVar12,"sde_connector_get_kms",uVar11);
          _printk(&DAT_002dea1e,"sde_backlight_setup",0xf3);
          uVar10 = 0xffffffea;
LAB_001decd4:
          puVar12 = &DAT_002b5262;
          uVar11 = 0xdff;
          goto LAB_001dece8;
        }
        lVar19 = *(long *)(lVar19 + 8);
        if (lVar19 == 0) {
          puVar12 = &DAT_002dea1e;
          uVar11 = 0x343;
          goto LAB_001decb4;
        }
        if (((int)plVar9[0xf1] == 0x10) &&
           (((lVar20 = *(long *)(plVar9[0xf4] + 0x110), *(int *)(lVar20 + 0x5a0) == 2 ||
             (*(long *)(lVar19 + 0x90) == 0)) ||
            (*(char *)(*(long *)(lVar19 + 0x90) + 0x4ac8) == '\0')))) {
          local_22c = 0;
          local_234 = 0x100000000;
          uStack_238 = 0;
          local_240 = CONCAT44(*(undefined4 *)(lVar20 + 0x5b4),*(undefined4 *)(lVar20 + 0x5bc));
          snprintf((char *)&local_90,0x20,"panel%u-backlight",sde_backlight_setup_display_count);
          uVar10 = backlight_device_register
                             (&local_90,*(undefined8 *)(param_1 + 8),plVar9,sde_backlight_device_ops
                              ,&local_240);
          plVar9[0x1b4] = uVar10;
          if ((uVar10 != 0) && (uVar10 < 0xfffffffffffff001)) {
            plVar9[0x1b9] = (ulong)*(uint *)(lVar20 + 0x5b4);
            if ((*(long *)(lVar19 + 0x90) == 0) ||
               (*(char *)(*(long *)(lVar19 + 0x90) + 0x4ac8) == '\0')) {
              uVar11 = *(undefined8 *)(param_1 + 8);
              plVar9[0x1b6] = (long)sde_backlight_cooling_cb;
              uVar10 = backlight_cdev_register(uVar11,uVar10,plVar9 + 0x1b6);
              plVar9[0x1b5] = uVar10;
              if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
                if ((__drm_debug >> 2 & 1) == 0) {
                  _printk(&DAT_002d9645,"sde_backlight_setup",0x11d);
                }
                else {
                  _printk(&DAT_002eb8b3,uVar10);
                }
                plVar9[0x1b5] = 0;
              }
            }
            sde_backlight_setup_display_count = sde_backlight_setup_display_count + 1;
            goto LAB_001de09c;
          }
          _printk(&DAT_002cabba,"sde_backlight_setup",0x10b);
          uVar10 = 0xffffffed;
          plVar9[0x1b4] = 0;
          goto LAB_001decd4;
        }
LAB_001de09c:
        plVar16 = plVar9 + 0x131;
        msm_property_init(plVar16,puVar23,param_1,lVar21 + 0x11d8,plVar9 + 0x141,0x31,10,0xe48);
        pcVar18 = (code *)plVar9[0x102];
        if (pcVar18 != (code *)0x0) {
          if (*(int *)(pcVar18 + -4) != -0x7686c9b3) {
                    /* WARNING: Does not return */
            pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x1de0f4);
            (*pcVar18)();
          }
          uVar5 = (*pcVar18)(plVar9,param_4);
          if (uVar5 != 0) {
            uVar10 = (ulong)uVar5;
            puVar12 = &DAT_002be654;
            uVar11 = 0xe0c;
            goto LAB_001dece8;
          }
        }
        if ((int)plVar9[0xf1] == 0x10) {
          iVar4 = 0;
          pcVar13 = (char *)(*(long *)(*(long *)(plVar9[0xf4] + 0x110) + 0xb30) + 0x16);
LAB_001de17c:
          if ((__drm_debug >> 2 & 1) != 0) {
            ___drm_dbg(0,0,"%s:i = %d param_name = %s is_support=%d\n",
                       "sde_connector_install_panel_params",iVar4,*(undefined8 *)(pcVar13 + -0x16),
                       *pcVar13);
          }
          __s1 = *(char **)(pcVar13 + -0x16);
          iVar6 = strncmp(__s1,"HBM",3);
          if (iVar6 == 0) {
            uVar11 = 0x2c;
            cVar2 = *pcVar13;
          }
          else {
            iVar6 = strncmp(__s1,"CABC",4);
            if (iVar6 == 0) {
              uVar11 = 0x2d;
              cVar2 = *pcVar13;
joined_r0x001de234:
              if (cVar2 != '\0') goto LAB_001de150;
LAB_001de258:
              uVar14 = 0;
              uVar15 = 0xffff;
              goto LAB_001de158;
            }
            iVar6 = strncmp(__s1,"ACL",3);
            if (iVar6 == 0) {
              uVar11 = 0x2e;
              cVar2 = *pcVar13;
              goto joined_r0x001de14c;
            }
            iVar6 = strncmp(__s1,"DC",2);
            if (iVar6 != 0) {
              iVar6 = strncmp(__s1,"COLOR",5);
              if (iVar6 == 0) {
                uVar11 = 0x30;
                cVar2 = *pcVar13;
                goto joined_r0x001de234;
              }
              _printk(&DAT_002d3549,"sde_connector_install_panel_params",0xc51,__s1);
              uVar5 = *puVar23;
              puVar12 = &DAT_0030526c;
              pcVar13 = "sde_connector_init";
              uVar11 = 0xe15;
              uVar10 = 0xffffffea;
              goto LAB_001ded24;
            }
            uVar11 = 0x2f;
            cVar2 = *pcVar13;
          }
joined_r0x001de14c:
          if (cVar2 == '\0') goto LAB_001de258;
LAB_001de150:
          uVar14 = *(undefined2 *)(pcVar13 + -6);
          uVar15 = *(undefined2 *)(pcVar13 + -4);
LAB_001de158:
          msm_property_install_volatile_range(plVar16,__s1,0,0,uVar14,uVar15,uVar11);
          iVar4 = iVar4 + 1;
          pcVar13 = pcVar13 + 0x18;
          if (iVar4 == 5) goto LAB_001de264;
          goto LAB_001de17c;
        }
LAB_001de264:
        plVar1 = plVar9 + 0x1b3;
        if ((plVar9[0xf4] == 0) || (pcVar18 = (code *)plVar9[0x10b], pcVar18 == (code *)0x0)) {
          _printk(&DAT_002c4d3f,"sde_connector_get_info",0x259);
          bVar3 = param_7 == 0x10;
        }
        else {
          if (*(int *)(pcVar18 + -4) != -0x837836f) {
                    /* WARNING: Does not return */
            pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x1de29c);
            (*pcVar18)();
          }
          iVar4 = (*pcVar18)(plVar9,auStack_220,plVar9[0xf4]);
          bVar3 = param_7 == 0x10;
          if ((bVar3) && (iVar4 == 0)) {
            if ((local_21c & 1) != 0) {
              uVar11 = _raw_spin_lock_irqsave(plVar1);
              plVar9[0x1ae] = (long)plVar9;
              plVar9[0x1ad] = (long)sde_connector_handle_disp_recovery;
              _raw_spin_unlock_irqrestore(plVar1,uVar11);
              pcVar18 = (code *)plVar9[0x10d];
              if ((pcVar18 != (code *)0x0) && (plVar9[0xf4] != 0)) {
                bVar3 = true;
                if (*(int *)(pcVar18 + -4) != -0x5e0850a2) {
                    /* WARNING: Does not return */
                  pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x1de320);
                  (*pcVar18)();
                }
                (*pcVar18)(plVar9,2,1);
                goto LAB_001de3b8;
              }
            }
            bVar3 = true;
          }
        }
LAB_001de3b8:
        local_240 = 0xffffffffffffffff;
        msm_property_install_blob(plVar16,"capabilities",4,0);
        uVar7 = sde_connector_set_blob_data(plVar9,0,0);
        if (uVar7 == 0) {
          msm_property_install_blob(plVar16,"mode_properties",4,1);
          if (param_7 == 0x10) {
            if ((param_4 != 0) && (*(long *)(param_4 + 0x110) != 0)) {
              msm_property_install_blob(plVar16,"dimming_bl_lut",0x10,8);
              msm_property_install_range(plVar16,"dimming_dyn_ctrl",0,0,0xffffffffffffffff,0,0x16);
              msm_property_install_range
                        (plVar16,"dimming_min_bl",0,0,
                         *(undefined4 *)(*(long *)(param_4 + 0x110) + 0x5b4),0,0x17);
              lVar21 = *(long *)(param_4 + 0x110);
              if (lVar21 != 0) {
                if (*(int *)(lVar21 + 0x668) == 1) {
                  msm_property_install_blob(plVar16,"hdr_properties",4,2);
                  msm_property_set_blob
                            (plVar16,plVar9 + 0x1a4,*(long *)(param_4 + 0x110) + 0x668,0x2c,2);
                  lVar21 = *(long *)(param_4 + 0x110);
                  if (lVar21 == 0) goto LAB_001de504;
                }
                if (*(char *)(lVar21 + 0x560) != '\0') {
                  msm_property_install_range(plVar16,"dyn_bit_clk",0,0,0xffffffffffffffff,0,0x15);
                }
              }
            }
LAB_001de504:
            msm_property_install_range(plVar16,"dyn_transfer_time",0,0,1000000,0,0x19);
            mutex_lock(*plVar9 + 0x1a8);
            sde_connector_fill_modes
                      (plVar9,*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x3a4));
            mutex_unlock(*plVar9 + 0x1a8);
            lVar21 = param_4;
          }
          else {
            lVar21 = 0;
          }
          msm_property_install_volatile_range
                    (plVar16,"sde_drm_roi_v1",0,0,0xffffffffffffffff,0,0x11);
          local_80 = 0;
          local_78 = 0;
          local_90 = 0;
          local_88 = 0;
          if (lVar22 == 0) {
            _printk(&DAT_002e5ab1,"_sde_connector_install_dither_property",0x17c,param_1,0,plVar9);
          }
          else {
            uVar5 = *(uint *)(*(long *)(*(long *)(lVar22 + 0x90) + 0x2298) + 0x8c) >> 0x10;
            snprintf((char *)&local_90,0x20,"%s%d","SDE_PP_DITHER_V",uVar5);
            if (uVar5 - 1 < 2) {
              msm_property_install_blob(plVar16,&local_90,0x10,4);
            }
            else {
              _printk(&DAT_002a8447,"_sde_connector_install_dither_property",0x18d,uVar5);
            }
          }
          if (param_7 == 10) {
            local_78 = local_78 & 0xffffffff00000000;
            local_88 = 0;
            local_80 = 0;
            local_90 = 0;
            *(undefined1 *)((long)plVar9 + 0xeae) = 1;
            msm_property_install_blob(plVar16,"ext_hdr_properties",4,3);
            msm_property_set_blob(plVar16,plVar9 + 0x1a5,&local_90,0x1c,3);
            pcVar18 = (code *)plVar9[0x126];
            if (pcVar18 != (code *)0x0) {
              if (*(int *)(pcVar18 + -4) != 0x34b19c16) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x1de650);
                (*pcVar18)();
              }
              (*pcVar18)(param_4,plVar9);
            }
          }
          msm_property_install_volatile_range(plVar16,"hdr_metadata",0,0,0xffffffffffffffff,0,6);
          msm_property_install_volatile_range(plVar16,"RETIRE_FENCE",0,0,0xffffffffffffffff,0,0xb);
          msm_property_install_volatile_range
                    (plVar16,"RETIRE_FENCE_OFFSET",0,0,0xffffffffffffffff,0,0xc);
          msm_property_install_range(plVar16,"autorefresh",0,0,6,0,0x1d);
          if (param_7 == 0x10) {
            lVar19 = *(long *)(lVar22 + 0x90);
            if ((((lVar21 != 0) && (((uint)*(undefined8 *)(lVar19 + 0x5220) >> 0x15 & 1) != 0)) &&
                (*(long *)(lVar21 + 0x110) != 0)) &&
               (*(char *)(*(long *)(lVar21 + 0x110) + 0x8c8) != '\0')) {
              msm_property_install_enum(plVar16,"qsync_mode",0,0,e_qsync_mode,3,0,0x20);
              lVar19 = *(long *)(lVar22 + 0x90);
              if ((((uint)*(undefined8 *)(lVar19 + 0x5220) >> 0x16 & 1) != 0) &&
                 ((local_21c & 1) != 0)) {
                msm_property_install_enum
                          (plVar16,"avr_step_state",0,0,
                           _sde_connector_install_qsync_properties_e_avr_step_state,3,0,0x23);
                lVar19 = *(long *)(lVar22 + 0x90);
              }
              if (((*(ulong *)(lVar19 + 0x5220) >> 0x25 & 1) != 0) &&
                 (((byte)local_21c >> 1 & 1) != 0)) {
                msm_property_install_range(plVar16,"EPT_FPS",0,0,0xffffffff,0,0x25);
                lVar19 = *(long *)(lVar22 + 0x90);
              }
            }
            if ((*(ulong *)(lVar19 + 0x5220) >> 0x24 & 1) != 0) {
              msm_property_install_range(plVar16,&DAT_002e5aad,0,0,0xffffffffffffffff,0,0x24);
            }
            msm_property_install_enum(plVar16,"dsc_mode",0,0,e_dsc_mode,3,0,0x27);
            if (((lVar21 != 0) && (*(long *)(lVar21 + 0x110) != 0)) &&
               (((local_21c ^ 0xffffffff) & 3) == 0)) {
              msm_property_install_enum
                        (plVar16,"panel_mode",0,0,e_panel_mode,3,
                         *(int *)(*(long *)(lVar21 + 0x110) + 0x4ec) != 1,0x22);
            }
            msm_property_install_enum(plVar16,"bpp_mode",0,0,e_bpp_mode,3,0,0x2b);
            if (((uint)*(undefined8 *)(*(long *)(lVar22 + 0x90) + 0x5220) >> 0x17 & 1) != 0) {
              msm_property_install_blob(plVar16,"DEMURA_PANEL_ID",4,7);
              msm_property_set_blob(plVar16,plVar9 + 0x1a8,&local_240,8,7);
            }
          }
          if ((param_7 == 0xf) || ((local_21c >> 1 & 1) != 0)) {
            msm_property_install_enum
                      (plVar16,"frame_trigger_mode",0,0,e_frame_trigger_mode,3,0,0x21);
          }
          msm_property_install_range(plVar16,"bl_scale",0,0,0x400,0x400,0x12);
          msm_property_install_range(plVar16,"sv_bl_scale",0,0,0xffffffff,0xffff,0x13);
          *(undefined1 *)((long)plVar9 + 0xe64) = 0;
          plVar9[0x1cd] = 0xffff00000400;
          if (param_7 == 10) {
            msm_property_install_range(plVar16,"supported_colorspaces",4,0,0xffff,0,0x14);
          }
          msm_property_install_enum(plVar16,"topology_name",4,0,&e_topology_name,0xf,0,0x1b);
          msm_property_install_enum(plVar16,"topology_control",0,1,e_topology_control,6,0,0x1c);
          msm_property_install_enum(plVar16,&DAT_002ab704,0,0,e_power_mode,4,0,0x1e);
          if (((param_4 != 0) && (param_7 == 0x10)) && (*(long *)(param_4 + 0x110) != 0)) {
            msm_property_install_range(plVar16,"brightness",0,0,0xffff,0,0x1a);
          }
          if ((bVar3) &&
             (((uint)*(undefined8 *)(*(long *)(lVar22 + 0x90) + 0x5220) >> 0x17 & 1) != 0)) {
            uVar11 = _raw_spin_lock_irqsave(plVar1);
            plVar9[0x1b2] = (long)plVar9;
            plVar9[0x1b1] = (long)sde_connector_handle_panel_id;
            _raw_spin_unlock_irqrestore(plVar1,uVar11);
            pcVar18 = (code *)plVar9[0x10d];
            if ((pcVar18 != (code *)0x0) && (plVar9[0xf4] != 0)) {
              if (*(int *)(pcVar18 + -4) != -0x5e0850a2) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x1deaa8);
                (*pcVar18)();
              }
              (*pcVar18)(plVar9,4,1);
            }
          }
          uVar5 = msm_property_install_get_status(plVar16);
          if (uVar5 == 0) {
            local_90 = local_90 & 0xffffffff00000000;
            if ((lVar22 == 0) || (pcVar18 = (code *)plVar9[0x124], pcVar18 == (code *)0x0)) {
              if ((__drm_debug >> 2 & 1) != 0) {
                pcVar13 = "invalid input params";
LAB_001deb0c:
                ___drm_dbg(0,0,pcVar13);
              }
            }
            else if (local_d0 - 3U < 0xfffffffe) {
              if ((__drm_debug >> 2 & 1) != 0) {
                pcVar13 = "invalid display_type";
                goto LAB_001deb0c;
              }
            }
            else {
              if (*(int *)(pcVar18 + -4) != -0x6a6f7534) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x1dec04);
                (*pcVar18)();
              }
              iVar4 = (*pcVar18)(plVar9[0xf4],&local_90);
              if ((iVar4 == 0) && ((uint)local_90 != 0)) {
                if (*(uint *)(*(long *)(lVar22 + 0x90) + 0x1850) < (uint)local_90) {
                  if ((__drm_debug >> 2 & 1) != 0) {
                    ___drm_dbg(0,0,"topology requesting more lms [%d] than hw exists [%d]");
                  }
                }
                else {
                  uVar8 = sde_hw_mixer_set_preference
                                    (*(long *)(lVar22 + 0x90),local_90 & 0xffffffff,local_d0);
                  *(undefined4 *)((long)plVar9 + 0xe94) = uVar8;
                }
              }
              else if ((__drm_debug >> 2 & 1) != 0) {
                pcVar13 = "failed to get default lm count";
                goto LAB_001deb0c;
              }
            }
            if (((int)plVar9[0xf1] == 0xf) && (*(int *)(*(long *)(lVar22 + 0x90) + 0x30) != 0)) {
              *(undefined1 *)(plVar9 + 0x205) = 1;
            }
            if ((__drm_debug >> 2 & 1) != 0) {
              ___drm_dbg(0,0,"connector %d attach encoder %d, wb hwfences:%d\n",(int)plVar9[8],
                         *(undefined4 *)(param_2 + 0x18),(char)plVar9[0x205]);
            }
            plVar9[0x1ba] = 0xfffffffe0;
            plVar9[0x1bb] = (long)(plVar9 + 0x1bb);
            plVar9[0x1bc] = (long)(plVar9 + 0x1bb);
            plVar9[0x1bd] = (long)sde_connector_check_status_work;
            init_timer_key(plVar9 + 0x1c0,&delayed_work_timer_fn,0x200000,0,0);
            goto LAB_001deba8;
          }
          uVar10 = (ulong)uVar5;
          _printk(&DAT_002ab614,"sde_connector_init",0xe31);
          if (plVar9[0x1a3] != 0) {
            drm_property_blob_put();
          }
          if (plVar9[0x1a4] != 0) {
            drm_property_blob_put();
          }
          if (plVar9[0x1a6] != 0) {
            drm_property_blob_put();
          }
          if (plVar9[0x1a7] != 0) {
            drm_property_blob_put();
          }
          if (plVar9[0x1a5] != 0) {
            drm_property_blob_put();
          }
          msm_property_destroy(plVar16);
        }
        else {
          uVar5 = *puVar23;
          uVar10 = (ulong)uVar7;
          puVar12 = &DAT_002f2331;
          pcVar13 = "_sde_connector_install_properties";
          uVar11 = 0xce7;
LAB_001ded24:
          _printk(puVar12,pcVar13,uVar11,uVar5,uVar10);
        }
      }
      else {
        uVar10 = (ulong)uVar5;
        puVar12 = &DAT_002ab5d0;
        uVar11 = 0xdf9;
LAB_001dece8:
        _printk(puVar12,"sde_connector_init",uVar11,uVar10);
      }
      sde_fence_deinit(plVar9[0x101]);
    }
    else {
      _printk(&DAT_002d0143,"sde_connector_init",0xdf1,uVar10 & 0xffffffff);
    }
    iVar4 = (int)uVar10;
    drm_connector_cleanup(plVar9);
  }
  kfree(plVar9);
  plVar9 = (long *)(long)iVar4;
LAB_001deba8:
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar9;
}



//------------------------------------------------------------
// sde_backlight_cooling_cb @ 001e221c size=128
// signature: undefined sde_backlight_cooling_cb(void)
//------------------------------------------------------------

undefined8 sde_backlight_cooling_cb(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_3 + 0x148);
  if ((__drm_debug >> 2 & 1) == 0) {
    _printk(&DAT_002d969e,"sde_backlight_cooling_cb",0xe0,param_2);
  }
  else {
    _printk(&DAT_002cdadb,param_2);
  }
  *(undefined8 *)(lVar1 + 0xdc8) = param_2;
  sde_backlight_device_update_status(param_3);
  return 0;
}



//------------------------------------------------------------
// sde_backlight_device_update_status @ 001e22a0 size=692
// signature: undefined sde_backlight_device_update_status(void)
//------------------------------------------------------------

int sde_backlight_device_update_status(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  undefined *puVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  code *pcVar11;
  uint uVar12;
  long *plVar13;
  long *plVar14;
  undefined8 local_58;
  uint local_4c;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  plVar13 = *(long **)(param_1 + 0x52);
  local_58 = 0;
  if (((plVar13 == (long *)0x0) || (*plVar13 == 0)) ||
     (lVar9 = *(long *)(*plVar13 + 0x38), lVar9 == 0)) {
    puVar7 = &DAT_003051d2;
    uVar8 = 0x33d;
  }
  else {
    lVar9 = *(long *)(lVar9 + 8);
    if (lVar9 != 0) {
      if ((param_1[2] == 0) && ((param_1[5] & 3) == 0)) {
        lVar10 = *(long *)(plVar13[0xf4] + 0x110);
        plVar14 = (long *)(plVar13[0xf4] + 0x110);
        uVar12 = *(uint *)(lVar10 + 0x5b4);
        local_4c = *param_1;
        if (uVar12 < *param_1) {
          local_4c = uVar12;
        }
      }
      else {
        local_4c = 0;
        lVar10 = *(long *)(plVar13[0xf4] + 0x110);
        plVar14 = (long *)(plVar13[0xf4] + 0x110);
        uVar12 = *(uint *)(lVar10 + 0x5b4);
      }
      if ((ulong)plVar13[0x1b9] < (ulong)(long)(int)local_4c) {
        local_4c = (uint)plVar13[0x1b9];
      }
      if ((local_4c != 0) && (local_4c < *(uint *)(lVar10 + 0x5ac))) {
        local_4c = *(uint *)(lVar10 + 0x5ac);
      }
      uVar4 = local_4c;
      uVar2 = 0;
      if (uVar12 != 0) {
        uVar2 = local_4c / uVar12;
      }
      uVar3 = 0;
      if (uVar12 != 0) {
        uVar3 = (*(int *)(lVar10 + 0x5b0) * (local_4c - uVar2 * uVar12)) / uVar12;
      }
      iVar1 = uVar3 + *(int *)(lVar10 + 0x5b0) * uVar2;
      if (local_4c != 0 && iVar1 == 0) {
        iVar1 = 1;
      }
      if (*(char *)((long)plVar13 + 0xe74) == '\0') {
        iVar5 = 0;
        *(int *)(plVar13 + 0x1ce) = iVar1;
        goto LAB_001e2500;
      }
      if (*(long *)(lVar9 + 0x1838) == 0) {
LAB_001e23c8:
        pcVar11 = (code *)plVar13[0x10e];
        if (pcVar11 != (code *)0x0) {
          if (uVar4 != 0) {
            local_58 = 0x480000003;
            msm_mode_object_event_notify(plVar13 + 8,*plVar13,&local_58,&local_4c);
            pcVar11 = (code *)plVar13[0x10e];
          }
          if (*(int *)(pcVar11 + -4) != 0x7fd220f5) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1e2420);
            (*pcVar11)();
          }
          iVar5 = (*pcVar11)(plVar13,plVar13[0xf4],iVar1);
          if (iVar5 == 0) {
            sde_dimming_bl_notify(plVar13,*plVar14 + 0x5a0);
            if ((plVar13[0xe8] != 0) && (lVar9 = *(long *)(plVar13[0xe8] + 8), lVar9 != 0)) {
              sde_crtc_backlight_notify(lVar9,local_4c,*(undefined4 *)(*plVar14 + 0x5b4));
            }
          }
          *(undefined4 *)(plVar13 + 0x1ce) = 0;
          goto LAB_001e2500;
        }
      }
      else {
        mutex_lock();
        if (*(long *)(lVar9 + 0x1838) == 0) goto LAB_001e23c8;
        pcVar11 = *(code **)(*(long *)(lVar9 + 0x1838) + 0x58);
        if (pcVar11 == (code *)0x0) {
LAB_001e23c4:
          mutex_unlock();
          goto LAB_001e23c8;
        }
        if (*(int *)(pcVar11 + -4) != -0x56e84354) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1e23b0);
          (*pcVar11)();
        }
        uVar6 = (*pcVar11)(lVar9);
        if ((uVar6 & 1) != 0) {
          if (*(long *)(lVar9 + 0x1838) == 0) goto LAB_001e23c8;
          goto LAB_001e23c4;
        }
        if (*(long *)(lVar9 + 0x1838) != 0) {
          mutex_unlock();
        }
        if ((__drm_debug >> 2 & 1) != 0) {
          ___drm_dbg(0,0,"skipping bl update due to HW unavailablity\n");
          iVar5 = 0;
          goto LAB_001e2500;
        }
      }
      iVar5 = 0;
      goto LAB_001e2500;
    }
    puVar7 = &DAT_002dea1e;
    uVar8 = 0x343;
  }
  _printk(puVar7,"sde_connector_get_kms",uVar8);
  _printk(&DAT_002dea1e,"sde_backlight_device_update_status",0x8b);
  iVar5 = -0x16;
LAB_001e2500:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// sde_backlight_device_get_brightness @ 001e2558 size=8
// signature: undefined sde_backlight_device_get_brightness(void)
//------------------------------------------------------------

undefined8 sde_backlight_device_get_brightness(void)

{
  return 0;
}



//------------------------------------------------------------
// _set_dspp_ad_backlight_feature @ 001e76c8 size=136
// signature: undefined _set_dspp_ad_backlight_feature(void)
//------------------------------------------------------------

void _set_dspp_ad_backlight_feature(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  if ((param_1 == 0) || (pcVar3 = *(code **)(param_1 + 0xe8), pcVar3 == (code *)0x0)) {
    uVar2 = 0xffffffea;
  }
  else {
    local_28 = 6;
    uStack_20 = param_2;
    if (*(int *)(pcVar3 + -4) != 0x72f147c9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1e7718);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,&local_28);
    uVar2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// sde_cp_backlight_notification @ 001ebdc0 size=100
// signature: undefined sde_cp_backlight_notification(void)
//------------------------------------------------------------

void sde_cp_backlight_notification(long param_1,int param_2,undefined4 param_3)

{
  mutex_lock(param_1 + 0xc48);
  if (*(int *)(param_1 + 0x18fc) != param_2) {
    *(int *)(param_1 + 0x18fc) = param_2;
    *(undefined4 *)(param_1 + 0x1900) = param_3;
    *(undefined4 *)(param_1 + 0x1904) = 1;
  }
  mutex_unlock(param_1 + 0xc48);
  return;
}



//------------------------------------------------------------
// sde_demura_backlight_cfg @ 0020a3d0 size=392
// signature: undefined sde_demura_backlight_cfg(void)
//------------------------------------------------------------

void sde_demura_backlight_cfg(long param_1,uint param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  if (param_1 == 0) {
    __drm_err("invalid parameter ctx %pK",0);
  }
  else if (param_3 == (long *)0x0) {
    __drm_err("invalid parameter hw_cfg");
  }
  else {
    lVar3 = *param_3;
    if (lVar3 == 0) {
      ___drm_dbg(0,1,"disable demura feature\n");
    }
    else {
      sde_reg_write(param_1,*(int *)(*(long *)(*(long *)(param_1 + 0x48) + 0x30) + 0x214) + 8,
                    param_2,"ctx->cap->sblk->demura.base + 0x8");
      if ((param_2 & 0xffff) < 0x2a) {
        uVar1 = 0x3000000;
        uVar2 = 0x1010202;
      }
      else if ((param_2 & 0xffff) < 0xa5) {
        uVar1 = 0x2000000;
        uVar2 = 0x3020101;
      }
      else {
        uVar2 = 0x7f;
        if (*(int *)(*(long *)(*(long *)(param_1 + 0x48) + 0x30) + 0x220) != 0x20000) {
          uVar2 = 0x1f;
        }
        uVar1 = uVar2 & *(uint *)(lVar3 + 0x18c8) | (uVar2 & *(uint *)(lVar3 + 0x18cc)) << 8 |
                (uVar2 & *(uint *)(lVar3 + 0x18d0)) << 0x10 |
                (uVar2 & *(uint *)(lVar3 + 0x18d4)) << 0x18;
        uVar2 = uVar2 & *(uint *)(lVar3 + 0x18d8) | (uVar2 & *(uint *)(lVar3 + 0x18dc)) << 8 |
                (uVar2 & *(uint *)(lVar3 + 0x18e0)) << 0x10 |
                (uVar2 & *(uint *)(lVar3 + 0x18e4)) << 0x18;
      }
      sde_reg_write(param_1,*(int *)(*(long *)(*(long *)(param_1 + 0x48) + 0x30) + 0x214) + 0x4c,
                    uVar1,"ctx->cap->sblk->demura.base + 0x4c");
      sde_reg_write(param_1,*(int *)(*(long *)(*(long *)(param_1 + 0x48) + 0x30) + 0x214) + 0x50,
                    uVar2,"ctx->cap->sblk->demura.base + 0x50");
    }
  }
  return;
}



//------------------------------------------------------------
// ad4_backlight_setup @ 0020c090 size=176
// signature: undefined ad4_backlight_setup(void)
//------------------------------------------------------------

undefined8 ad4_backlight_setup(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  ushort *puVar4;
  
  puVar4 = (ushort *)**(undefined8 **)(param_2 + 8);
  if (*(int *)(*(undefined8 **)(param_2 + 8) + 1) == 8) {
    if (puVar4 != (ushort *)0x0) {
      uVar3 = (ulong)*puVar4;
      goto LAB_0020c0dc;
    }
  }
  else if (puVar4 != (ushort *)0x0) {
    __drm_err("invalid sz param exp %zd given %d cfg %pK\n",8);
    return 0xffffffea;
  }
  uVar3 = 0;
LAB_0020c0dc:
  uVar1 = *(uint *)(param_1 + 0x40);
  if (4 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x20c13c);
    (*pcVar2)();
  }
  if (0x298 < (ulong)uVar1 * 0x90) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x20c140);
    (*pcVar2)();
  }
  *(ulong *)(&DAT_0031a9c8 + (ulong)uVar1 * 0x90) = uVar3;
  sde_reg_write(param_1,*(int *)(*(long *)(*(long *)(param_1 + 0x48) + 0x30) + 0x158) + 0x2c,uVar3,
                "dspp->cap->sblk->ad.base + blk_offset");
  return 0;
}



//------------------------------------------------------------
// ad4_backlight_setup_ipcr @ 0020e4a4 size=192
// signature: undefined ad4_backlight_setup_ipcr(void)
//------------------------------------------------------------

undefined8 ad4_backlight_setup_ipcr(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  ushort *puVar3;
  ulong uVar4;
  ulong uVar5;
  
  puVar3 = (ushort *)**(undefined8 **)(param_2 + 8);
  if (*(int *)(*(undefined8 **)(param_2 + 8) + 1) == 8) {
    if (puVar3 != (ushort *)0x0) {
      uVar4 = (ulong)*puVar3;
      goto LAB_0020e4f0;
    }
  }
  else if (puVar3 != (ushort *)0x0) {
    __drm_err("invalid sz param exp %zd given %d cfg %pK\n",8);
    return 0xffffffea;
  }
  uVar4 = 0;
LAB_0020e4f0:
  uVar1 = *(uint *)(param_1 + 0x40);
  if (4 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x20e564);
    (*pcVar2)();
  }
  uVar5 = (ulong)uVar1 * 0x90;
  if ((0x290 < uVar5) || (*(ulong *)(&DAT_0031a9d0 + uVar5) = uVar4, 0x298 < uVar5)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x20e560);
    (*pcVar2)();
  }
  sde_reg_write(param_1,*(int *)(*(long *)(*(long *)(param_1 + 0x48) + 0x30) + 0x158) + 0x2c,
                *(undefined4 *)(&DAT_0031a9c8 + (ulong)uVar1 * 0x90),
                "dspp->cap->sblk->ad.base + blk_offset");
  return 0;
}



//------------------------------------------------------------
// dsi_display_set_backlight @ 0026de0c size=580
// signature: undefined dsi_display_set_backlight(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int dsi_display_set_backlight(long param_1,long param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  uint *puVar6;
  undefined8 *puVar7;
  uint uVar8;
  
  uVar5 = jiffies_to_msecs(_jiffies);
  if ((param_2 == 0) || (puVar7 = *(undefined8 **)(param_2 + 0x110), puVar7 == (undefined8 *)0x0)) {
    iVar4 = -0x16;
  }
  else {
    mutex_lock(puVar7 + 0x7f);
    cVar3 = dsi_display_set_backlight_lastTrend;
    if (*(char *)((long)puVar7 + 0x8c4) == '\0') {
      drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: Ignor bl_level %u as panel is not init.\n",
                     param_3);
      iVar4 = -0x16;
    }
    else {
      uVar8 = *(uint *)(puVar7 + 0xb8);
      bVar2 = dsi_display_set_backlight_lastTrend != '\0';
      if (param_3 != uVar8) {
        bVar2 = 0 < (int)(param_3 - uVar8);
      }
      if ((((param_3 != 0) == (uVar8 == 0)) ||
          (500 < (uVar5 & 0xffffffff) - dsi_display_set_backlight_lasttimejiffies)) ||
         ((bool)dsi_display_set_backlight_lastTrend != bVar2)) {
        if (param_3 != 0) {
          *(uint *)((long)puVar7 + 0x614) = uVar8;
        }
        _printk(&DAT_002ec8b0,uVar8,param_3,bVar2,cVar3,*(undefined4 *)(puVar7 + 0xb6),
                *(undefined4 *)((long)puVar7 + 0x5b4),*(undefined8 *)(param_1 + 0xdc8),*puVar7);
        uVar8 = *(uint *)(puVar7 + 0xb8);
        dsi_display_set_backlight_lasttimejiffies = uVar5 & 0xffffffff;
      }
      if ((param_3 != 0) && (uVar8 == 0)) {
        *(uint *)((long)puVar7 + 0x614) = param_3;
        *(undefined1 *)((long)puVar7 + 0x7f1) = 0;
      }
      iVar4 = *(int *)((long)puVar7 + 0x5c4);
      iVar1 = *(int *)(puVar7 + 0xb9);
      dsi_display_set_backlight_lastTrend = bVar2;
      *(uint *)(puVar7 + 0xb8) = param_3;
      uVar8 = (iVar4 * param_3 >> 10) * iVar1;
      if (((0xfffe < uVar8) && (puVar6 = (uint *)puVar7[0xba], puVar6 != (uint *)0x0)) &&
         (uVar8 / 0xffff < *puVar6)) {
        __drm_dev_dbg(0,0,0,
                      "[msm-dsi-debug]: before dimming bl_temp = %u, after dimming bl_temp = %lu\n",
                      (ulong)uVar8 / 0xffff,puVar6[(ulong)uVar8 / 0xffff + 1]);
      }
      uVar8 = *(uint *)(puVar7 + 0xb6);
      if (param_3 <= *(uint *)(puVar7 + 0xb6)) {
        uVar8 = param_3;
      }
      if (uVar8 == 0) {
        uVar8 = 0;
      }
      else if (uVar8 <= *(uint *)((long)puVar7 + 0x5ac)) {
        uVar8 = *(uint *)((long)puVar7 + 0x5ac);
      }
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: bl_scale = %u, bl_scale_sv = %u, bl_lvl = %u\n",iVar4,
                    iVar1,uVar8);
      iVar4 = dsi_panel_set_backlight(puVar7,uVar8);
      if (iVar4 != 0) {
        drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: unable to set backlight\n");
      }
    }
    mutex_unlock(puVar7 + 0x7f);
  }
  return iVar4;
}



//------------------------------------------------------------
// dsi_display_check_status @ 0026e86c size=840
// signature: undefined dsi_display_check_status(void)
//------------------------------------------------------------

int dsi_display_check_status(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  
  if ((param_2 == 0) || (lVar5 = *(long *)(param_2 + 0x110), lVar5 == 0)) {
    return -0x16;
  }
  if ((*(int *)(param_2 + 0x30) == 1) && (*(char *)(lVar5 + 0xb65) == '\0')) {
    drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: cli panel ignore esd check\n");
    *(undefined1 *)(lVar5 + 0xb65) = 1;
    return 1;
  }
  if (*(char *)(lVar5 + 0xbec) != '\0') {
    drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: cli panel AOD LP1 ignore esd check\n");
    return 1;
  }
  mutex_lock(lVar5 + 0x3f8);
  if (*(char *)(lVar5 + 0x8c4) == '\0') {
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: Panel not initialized\n");
    iVar1 = 1;
    goto LAB_0026e988;
  }
  if (((*(int *)(lVar5 + 0x8c0) != 0) || (iVar1 = *(int *)(lVar5 + 0x69c), iVar1 == 4)) ||
     ((lVar3 = *(long *)(param_2 + 0x110), lVar3 != 0 &&
      ((*(char *)(lVar3 + 0x8c5) != '\0' || (*(char *)(lVar3 + 0x3f0) != '\0')))))) {
    iVar1 = 1;
    goto LAB_0026e988;
  }
  if (iVar1 == 5) {
    iVar1 = -0x16;
    goto LAB_0026e988;
  }
  sde_evtlog_log(sde_dbg_base_evtlog,"dsi_display_check_status",0x489,0xffffffff,0x1111,iVar1,
                 param_3 & 1,0xc0debeef);
  if (*(char *)(param_2 + 0x671) == '\0') {
    uVar4 = 5;
    if ((param_3 & 1) == 0) {
      uVar4 = 1;
    }
    if (*(int *)(lVar5 + 0x4ec) == 1) goto LAB_0026ea18;
  }
  else {
LAB_0026ea18:
    uVar4 = 0;
  }
  uVar2 = *(uint *)(param_2 + 0xac);
  if (uVar2 != 0) {
    if (param_2 != -0xb0) {
      *(undefined1 *)(*(long *)(param_2 + 0xb0) + 0x709) = 1;
      uVar2 = *(uint *)(param_2 + 0xac);
    }
    if ((1 < uVar2) && ((long *)(param_2 + 0xe0) != (long *)0x0)) {
      *(undefined1 *)(*(long *)(param_2 + 0xe0) + 0x709) = 1;
    }
  }
  *(undefined1 *)(param_2 + 0x514) = 1;
  dsi_display_clk_ctrl(*(undefined8 *)(param_2 + 0x4f0),3,1);
  dsi_display_toggle_error_interrupt_status(param_2,0);
  uVar2 = 0;
  switch(iVar1) {
  case 0:
switchD_0026ea9c_caseD_0:
    iVar1 = dsi_display_status_reg_read(param_2);
    break;
  case 1:
    iVar1 = dsi_display_status_check_te(param_2,uVar4);
    if (0 < iVar1) goto switchD_0026ea9c_caseD_0;
    break;
  case 2:
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]:  ++\n");
    iVar1 = 0;
    break;
  case 3:
    goto switchD_0026ea9c_caseD_3;
  default:
    _printk(&DAT_002b60ee,iVar1);
    iVar1 = 1;
    *(undefined1 *)(lVar5 + 0x698) = 0;
    uVar2 = *(uint *)(param_2 + 0xac);
    goto joined_r0x0026ebac;
  }
  if ((iVar1 < 1) && ((param_3 & 1) != 0)) {
    uVar2 = 1;
switchD_0026ea9c_caseD_3:
    param_3 = uVar2;
    iVar1 = dsi_display_status_check_te(param_2,uVar4);
  }
  if (iVar1 < 1) {
LAB_0026eb74:
    *(undefined4 *)(lVar5 + 0x8c0) = 1;
  }
  else {
    uVar2 = *(uint *)(param_2 + 0xac);
joined_r0x0026ebac:
    if (uVar2 != 0) {
      if (param_2 != -0xb0) {
        *(undefined1 *)(*(long *)(param_2 + 0xb0) + 0x709) = 0;
        uVar2 = *(uint *)(param_2 + 0xac);
      }
      if ((1 < uVar2) && ((long *)(param_2 + 0xe0) != (long *)0x0)) {
        *(undefined1 *)(*(long *)(param_2 + 0xe0) + 0x709) = 0;
      }
    }
    if ((((param_3 & 1) != 0) && (*(char *)(lVar5 + 0x698) == '\0')) &&
       (iVar1 = dsi_display_status_check_te(param_2,uVar4), iVar1 < 1)) goto LAB_0026eb74;
    dsi_display_toggle_error_interrupt_status(param_2,1);
  }
  dsi_display_clk_ctrl(*(undefined8 *)(param_2 + 0x4f0),3,0);
LAB_0026e988:
  mutex_unlock(lVar5 + 0x3f8);
  sde_evtlog_log(sde_dbg_base_evtlog,"dsi_display_check_status",0x4be,0xffffffff,0x2222,iVar1,
                 0xc0debeef);
  return iVar1;
}



//------------------------------------------------------------
// dsi_display_force_esd_disable @ 0026ee0c size=24
// signature: undefined dsi_display_force_esd_disable(void)
//------------------------------------------------------------

bool dsi_display_force_esd_disable(long param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(char *)(*(long *)(param_1 + 0x110) + 0xa00) == '\0';
  }
  return bVar1;
}



//------------------------------------------------------------
// dsi_display_init @ 002729d4 size=3388
// signature: undefined dsi_display_init(void)
//------------------------------------------------------------

ulong dsi_display_init(long *param_1)

{
  long *plVar1;
  char *pcVar2;
  char *pcVar3;
  byte bVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  size_t sVar12;
  ulong uVar13;
  char *pcVar14;
  ulong *puVar15;
  long *plVar16;
  undefined8 uVar17;
  long lVar18;
  int iVar19;
  ulong *puVar20;
  undefined4 *puVar21;
  long lVar22;
  char *local_b8;
  ulong local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar22 = sp_el0;
  local_68 = *(long *)(lVar22 + 0x638);
  plVar16 = param_1 + 10;
  lVar22 = *param_1;
  __mutex_init(plVar16,"&display->display_lock",&dsi_display_init___key);
  if (param_1 == (long *)0x0) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid display\n");
    uVar11 = 0xffffffea;
  }
  else {
    if ((param_1[0x23] == 0) && (param_1[199] == 0)) {
LAB_002735e0:
      if ((param_1[0x22] == 0) ||
         (uVar9 = dsi_pwr_enable_regulator(param_1[0x22] + 0x590,1), uVar9 == 0)) {
        uVar13 = component_add(lVar22 + 0x10,&dsi_display_comp_ops);
        uVar11 = uVar13 & 0xffffffff;
        if ((int)uVar13 != 0) {
          drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: component add failed, rc=%d\n",
                         uVar11);
        }
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: component add success: %s\n",param_1[4]);
      }
      else {
        uVar11 = (ulong)uVar9;
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] failed to enable vregs, rc=%d\n",
                       *(undefined8 *)param_1[0x22],uVar11);
      }
      goto LAB_00272d80;
    }
    mutex_lock(plVar16);
    lVar10 = dsi_parser_get(*param_1 + 0x10);
    puVar21 = (undefined4 *)param_1[199];
    param_1[200] = lVar10;
    if ((puVar21 != (undefined4 *)0x0) && (lVar10 != 0)) {
      lVar10 = dsi_parser_get_head_node(lVar10,*(undefined8 *)(puVar21 + 2),*puVar21);
      puVar21 = (undefined4 *)param_1[199];
      param_1[0x24] = lVar10;
    }
    uVar17 = *(undefined8 *)(*param_1 + 0x2f8);
    iVar6 = strcmp((char *)param_1[5],"primary");
    pcVar14 = "qcom,dsi-ctrl-num";
    if (iVar6 != 0) {
      pcVar14 = "qcom,dsi-sec-ctrl-num";
    }
    pcVar2 = "qcom,dsi-phy-num";
    if (iVar6 != 0) {
      pcVar2 = "qcom,dsi-sec-phy-num";
    }
    if (puVar21 == (undefined4 *)0x0) {
      uVar7 = of_property_count_elems_of_size(param_1[0x23],pcVar14,4);
    }
    else {
      uVar7 = dsi_parser_count_u32_elems(param_1[0x24],pcVar14);
    }
    *(undefined4 *)((long)param_1 + 0xac) = uVar7;
    if (param_1[199] == 0) {
      iVar6 = of_property_count_elems_of_size(param_1[0x23],pcVar2,4);
    }
    else {
      iVar6 = dsi_parser_count_u32_elems(param_1[0x24],pcVar2);
    }
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: ctrl count=%d, phy count=%d\n",
                  *(undefined4 *)((long)param_1 + 0xac),iVar6);
    if ((iVar6 == 0) || (*(int *)((long)param_1 + 0xac) == 0)) {
      pcVar14 = "*ERROR* [msm-dsi-error]: no ctrl/phys found\n";
LAB_00272d28:
      drm_dev_printk(0,&DAT_002b5e64,pcVar14);
      lVar22 = param_1[4];
      pcVar14 = "*ERROR* [msm-dsi-error]: [%s] failed to parse dt, rc=%d\n";
      uVar13 = 0xffffffed;
      uVar11 = 0xffffffed;
    }
    else {
      if (iVar6 != *(int *)((long)param_1 + 0xac)) {
        pcVar14 = "*ERROR* [msm-dsi-error]: different ctrl and phy counts\n";
        goto LAB_00272d28;
      }
      uVar7 = dsi_display_get_phandle_index(param_1,pcVar14,iVar6,0);
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = (char *)0x0;
      local_b0 = 0;
      iVar6 = __of_parse_phandle_with_args(uVar17,"qcom,dsi-ctrl",0,0,uVar7,&local_b8);
      pcVar3 = local_b8;
      if (iVar6 != 0) {
        pcVar3 = (char *)0x0;
      }
      param_1[0x17] = (long)pcVar3;
      uVar7 = dsi_display_get_phandle_index(param_1,pcVar2,*(undefined4 *)((long)param_1 + 0xac),0);
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = (char *)0x0;
      local_b0 = 0;
      iVar6 = __of_parse_phandle_with_args(uVar17,"qcom,dsi-phy",0,0,uVar7,&local_b8);
      pcVar3 = local_b8;
      if (iVar6 != 0) {
        pcVar3 = (char *)0x0;
      }
      param_1[0x1a] = (long)pcVar3;
      if (1 < *(uint *)((long)param_1 + 0xac)) {
        uVar7 = dsi_display_get_phandle_index(param_1,pcVar14,*(uint *)((long)param_1 + 0xac),1);
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = (char *)0x0;
        local_b0 = 0;
        iVar6 = __of_parse_phandle_with_args(uVar17,"qcom,dsi-ctrl",0,0,uVar7,&local_b8);
        pcVar14 = local_b8;
        if (iVar6 != 0) {
          pcVar14 = (char *)0x0;
        }
        param_1[0x1d] = (long)pcVar14;
        uVar7 = dsi_display_get_phandle_index
                          (param_1,pcVar2,*(undefined4 *)((long)param_1 + 0xac),1);
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = (char *)0x0;
        local_b0 = 0;
        iVar6 = __of_parse_phandle_with_args(uVar17,"qcom,dsi-phy",0,0,uVar7,&local_b8);
        pcVar14 = local_b8;
        if (iVar6 != 0) {
          pcVar14 = (char *)0x0;
        }
        param_1[0x20] = (long)pcVar14;
      }
      lVar10 = *param_1;
      local_b8 = (char *)((ulong)local_b8 & 0xffffffff00000000);
      if (lVar10 == 0) {
        drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: Invalid platform device\n");
      }
      else {
        uVar7 = of_get_named_gpio_flags(*(undefined8 *)(lVar10 + 0x2f8),"qcom,platform-te-gpio",0,0)
        ;
        *(undefined4 *)(param_1 + 0x10) = uVar7;
        if (param_1[199] == 0) {
          iVar6 = of_property_read_variable_u32_array
                            (*(undefined8 *)(lVar10 + 0x2f8),"qcom,panel-te-source",&local_b8,1,0);
          if (-1 < iVar6) {
            iVar6 = 0;
          }
          if (iVar6 == 0) goto LAB_00272e00;
LAB_00272e0c:
          drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid vsync source selection\n"
                        );
          uVar9 = 0;
        }
        else {
          iVar6 = dsi_parser_read_u32(param_1[0x24],"qcom,panel-te-source",&local_b8);
          if (iVar6 != 0) goto LAB_00272e0c;
LAB_00272e00:
          uVar9 = (uint)local_b8;
          if (2 < (uint)local_b8) goto LAB_00272e0c;
        }
        *(uint *)(param_1 + 0xca) = uVar9;
      }
      if (*(int *)((long)param_1 + 0xac) != 0) {
        lVar10 = of_graph_get_remote_node(uVar17,0,0);
        param_1[0x26] = lVar10;
        if ((lVar10 != 0) &&
           (*(int *)(param_1 + 0x61) = (int)param_1[0x61] + 1, 1 < *(uint *)((long)param_1 + 0xac)))
        {
          lVar10 = of_graph_get_remote_node(uVar17,0,1);
          param_1[0x44] = lVar10;
          if (lVar10 != 0) {
            *(int *)(param_1 + 0x61) = (int)param_1[0x61] + 1;
          }
        }
      }
      param_1[0xcd] = -1;
      if (param_1[199] == 0) {
        plVar1 = param_1 + 0xcd;
        iVar6 = of_property_read_u64
                          (*(undefined8 *)(*param_1 + 0x2f8),"qcom,demura-panel-id",plVar1);
        if (iVar6 != 0) {
          pcVar14 = "[msm-dsi-debug]: No panel ID is present for this display\n";
          goto LAB_00272ecc;
        }
        if (*plVar1 == 0) {
          __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: Dummy panel ID node present for this display\n");
          *plVar1 = -1;
        }
        else {
          __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: panel id found: %lx\n");
        }
      }
      else {
        pcVar14 = "[msm-dsi-debug]: FW definition unsupported for Demura panel data\n";
LAB_00272ecc:
        __drm_dev_dbg(0,0,0,pcVar14);
      }
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: success\n");
      if (*(int *)((long)param_1 + 0xac) == 0) {
        iVar6 = 0;
LAB_00272fa0:
        pcVar14 = (char *)param_1[5];
        iVar8 = strcmp(pcVar14,"primary");
        if (iVar8 == 0) {
          uVar17 = 0;
        }
        else {
          iVar8 = strcmp(pcVar14,"secondary");
          if (iVar8 == 0) {
            uVar17 = 1;
          }
          else {
            _printk(&DAT_002fcfb7);
            uVar17 = 0;
            pcVar14 = (char *)param_1[5];
          }
        }
        uVar11 = dsi_panel_get(*param_1 + 0x10,param_1[0x23],param_1[0x24],pcVar14,
                               (int)param_1[0x90],*(undefined1 *)((long)param_1 + 0x671),uVar17);
        param_1[0x22] = uVar11;
        if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
          drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: failed to get panel, rc=%d\n",
                         uVar11 & 0xffffffff);
          param_1[0x22] = 0;
          goto LAB_00273578;
        }
        *(byte *)(uVar11 + 0x8c5) = *(byte *)(uVar11 + 0x8c5) | *(byte *)((long)param_1 + 0x4b);
        lVar10 = param_1[0x22];
        if ((((lVar10 == 0) ||
             ((*(char *)(lVar10 + 0x8c5) == '\0' && (*(char *)(lVar10 + 0x3f0) == '\0')))) &&
            (*(char *)(lVar10 + 0x49a) == '\0')) && (0x1ff < *(uint *)(lVar10 + 0x62c))) {
          drm_dev_printk(0,&DAT_002b5e64,
                         "*ERROR* [msm-dsi-error]: invalid reset gpio for the panel\n");
          uVar11 = 0xffffffea;
LAB_00273570:
          dsi_panel_put(param_1[0x22]);
          goto LAB_00273578;
        }
        if (*(int *)((long)param_1 + 0xac) == 0) {
          iVar6 = 0;
        }
        else {
          lVar18 = param_1[0x19];
          *(undefined1 *)(lVar18 + 0x2b8) = *(undefined1 *)(lVar10 + 0x49b);
          *(undefined4 *)(lVar18 + 700) = *(undefined4 *)(param_1[0x22] + 0x49c);
          if ((*(char *)(param_1[0x22] + 0x560) != '\0') && (*(int *)(param_1[0x22] + 0x4ec) == 1))
          {
            dsi_phy_pll_parse_dfps_data(lVar18);
          }
          *(undefined1 *)(lVar18 + 0x2c8) = *(undefined1 *)(lVar10 + 0x4a0);
          *(undefined4 *)(lVar18 + 0x2cc) = *(undefined4 *)(lVar10 + 0x4a4);
          *(undefined4 *)(lVar18 + 0x2d0) = *(undefined4 *)(lVar10 + 0x4a8);
          if (*(uint *)((long)param_1 + 0xac) < 2) {
            iVar6 = 1;
          }
          else {
            lVar18 = param_1[0x22];
            lVar10 = param_1[0x1f];
            *(undefined1 *)(lVar10 + 0x2b8) = *(undefined1 *)(lVar18 + 0x49b);
            *(undefined4 *)(lVar10 + 700) = *(undefined4 *)(param_1[0x22] + 0x49c);
            if ((*(char *)(param_1[0x22] + 0x560) != '\0') && (*(int *)(param_1[0x22] + 0x4ec) == 1)
               ) {
              dsi_phy_pll_parse_dfps_data(lVar10);
            }
            *(undefined1 *)(lVar10 + 0x2c8) = *(undefined1 *)(lVar18 + 0x4a0);
            *(undefined4 *)(lVar10 + 0x2cc) = *(undefined4 *)(lVar18 + 0x4a4);
            iVar6 = 2;
            *(undefined4 *)(lVar10 + 0x2d0) = *(undefined4 *)(lVar18 + 0x4a8);
          }
          lVar10 = param_1[0x22];
        }
        iVar8 = strcmp((char *)param_1[5],"primary");
        dsi_panel_parse_panel_cfg(lVar10,iVar8 == 0);
        local_b8 = (char *)0x0;
        local_b0 = 0;
        if (*(int *)(*(code **)(param_1[0x22] + 0x860) + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x273210);
          (*pcVar5)();
        }
        iVar8 = (**(code **)(param_1[0x22] + 0x860))
                          (*(undefined8 *)(*param_1 + 0x2f8),"qcom,lane-map-v2",&local_b8,4);
        if (iVar8 == -0x16) {
          pcVar14 = (char *)of_get_property(*(undefined8 *)(*param_1 + 0x2f8),"qcom,lane-map",0);
          if (pcVar14 == (char *)0x0) goto LAB_00273320;
          iVar8 = strcmp(pcVar14,"lane_map_3012");
          if (iVar8 == 0) {
            lVar10 = 0x108040200000001;
          }
          else {
            iVar8 = strcmp(pcVar14,"lane_map_2301");
            if (iVar8 == 0) {
              lVar10 = 0x201080400000002;
            }
            else {
              iVar8 = strcmp(pcVar14,"lane_map_1230");
              if (iVar8 == 0) {
                lVar10 = 0x402010800000003;
              }
              else {
                iVar8 = strcmp(pcVar14,"lane_map_0321");
                if (iVar8 == 0) {
                  lVar10 = 0x204080100000004;
                }
                else {
                  iVar8 = strcmp(pcVar14,"lane_map_1032");
                  if (iVar8 == 0) {
                    lVar10 = 0x408010200000005;
                  }
                  else {
                    iVar8 = strcmp(pcVar14,"lane_map_2103");
                    if (iVar8 == 0) {
                      lVar10 = 0x801020400000006;
                    }
                    else {
                      iVar8 = strcmp(pcVar14,"lane_map_3210");
                      if (iVar8 != 0) {
                        _printk(&DAT_002d1910,"dsi_display_parse_lane_map",pcVar14);
                        goto LAB_00273320;
                      }
                      lVar10 = 0x102040800000007;
                    }
                  }
                }
              }
            }
          }
LAB_00273328:
          param_1[0x8f] = lVar10;
        }
        else {
          if (iVar8 != 0) {
            __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: Incorrect mapping, configuring default\n");
LAB_00273320:
            lVar10 = 0x804020100000000;
            goto LAB_00273328;
          }
          *(char *)((long)param_1 + 0x47c) = (char)(1L << ((ulong)local_b8 & 0x3f));
          *(char *)((long)param_1 + 0x47d) = (char)(1L << ((ulong)local_b8 >> 0x20 & 0x3f));
          *(char *)((long)param_1 + 0x47e) = (char)(1L << (local_b0 & 0x3f));
          *(char *)((long)param_1 + 0x47f) = (char)(1L << (local_b0 >> 0x20 & 0x3f));
        }
        local_b8 = (char *)0x0;
        iVar8 = strcmp((char *)param_1[5],"primary");
        pcVar14 = "qcom,dsi-select-clocks";
        if (iVar8 != 0) {
          pcVar14 = "qcom,dsi-select-sec-clocks";
        }
        if (param_1[199] == 0) {
          iVar8 = of_property_read_string_helper(param_1[0x23],pcVar14,0,0,0);
        }
        else {
          iVar8 = dsi_parser_count_strings(param_1[0x24],pcVar14);
        }
        if (0 < iVar8) {
          iVar19 = 0;
          do {
            if (param_1[199] == 0) {
              of_property_read_string_helper(param_1[0x23],pcVar14,&local_b8,1,iVar19);
            }
            else {
              dsi_parser_read_string_index(param_1[0x24],pcVar14,iVar19,&local_b8);
            }
            __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: clock name:%s\n",local_b8);
            uVar11 = devm_clk_get(*param_1 + 0x10,local_b8);
            if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
              drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: failed to get %s, rc=%d\n",
                             local_b8,uVar11 & 0xffffffff);
              pcVar2 = local_b8;
              sVar12 = strlen(local_b8);
              lVar10 = strnstr(pcVar2,"pll_byte",sVar12);
              pcVar2 = local_b8;
              puVar15 = (ulong *)(param_1 + 0x67);
              if (lVar10 == 0) {
                sVar12 = strlen(local_b8);
                lVar10 = strnstr(pcVar2,"pll_dsi",sVar12);
                if (lVar10 == 0) goto LAB_0027349c;
                puVar15 = (ulong *)(param_1 + 0x68);
              }
              *puVar15 = 0;
              if ((int)uVar11 != 0) {
                drm_dev_printk(0,&DAT_002b5e64,
                               "*ERROR* [msm-dsi-error]: Failed to parse clock data, rc=%d\n",
                               uVar11 & 0xffffffff);
                goto LAB_00273570;
              }
              break;
            }
LAB_0027349c:
            pcVar2 = local_b8;
            sVar12 = strlen(local_b8);
            lVar10 = strnstr(pcVar2,"pll_byte",sVar12);
            pcVar2 = local_b8;
            puVar15 = (ulong *)(param_1 + 0x67);
            if (lVar10 == 0) {
              sVar12 = strlen(local_b8);
              lVar10 = strnstr(pcVar2,"pll_dsi",sVar12);
              puVar15 = (ulong *)(param_1 + 0x68);
              if (lVar10 != 0) goto LAB_002733b4;
            }
            else {
LAB_002733b4:
              *puVar15 = uVar11;
            }
            iVar19 = iVar19 + 1;
          } while (iVar8 != iVar19);
        }
        bVar4 = *(byte *)((long)param_1 + 0x671) ^ 1;
        *(byte *)(param_1 + 0xce) = bVar4;
        *(byte *)((long)param_1 + 0x672) = bVar4;
LAB_002735d8:
        mutex_unlock(plVar16);
        goto LAB_002735e0;
      }
      uVar11 = dsi_ctrl_get(param_1[0x17]);
      iVar6 = 0;
      puVar15 = (ulong *)(param_1 + 0x16);
      *puVar15 = uVar11;
      if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
LAB_00272fd4:
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: failed to get dsi controller, rc=%d\n",
                       uVar11 & 0xffffffff);
        *puVar15 = 0;
      }
      else {
        uVar11 = dsi_phy_get(param_1[0x1a]);
        iVar6 = 0;
        puVar20 = (ulong *)(param_1 + 0x19);
        *puVar20 = uVar11;
        if ((uVar11 != 0) && (uVar11 < 0xfffffffffffff001)) {
          if (*(uint *)((long)param_1 + 0xac) < 2) {
            iVar6 = 1;
          }
          else {
            uVar11 = dsi_ctrl_get(param_1[0x1d]);
            iVar6 = 1;
            puVar15 = (ulong *)(param_1 + 0x1c);
            *puVar15 = uVar11;
            if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) goto LAB_00272fd4;
            uVar11 = dsi_phy_get(param_1[0x20]);
            puVar20 = (ulong *)(param_1 + 0x1f);
            *puVar20 = uVar11;
            if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) goto LAB_0027314c;
            iVar6 = 2;
          }
          goto LAB_00272fa0;
        }
LAB_0027314c:
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: failed to get phy controller, rc=%d\n",
                       uVar11 & 0xffffffff);
        dsi_ctrl_put(*puVar15);
        *puVar20 = 0;
      }
LAB_00273578:
      uVar9 = iVar6 - 1;
      if (iVar6 != 0) {
        dsi_ctrl_put(param_1[(ulong)uVar9 * 6 + 0x16]);
        dsi_phy_put(param_1[(ulong)uVar9 * 6 + 0x19]);
        if (uVar9 != 0) {
          dsi_ctrl_put(param_1[(ulong)uVar9 * 6 + 0x10]);
          dsi_phy_put(param_1[(ulong)uVar9 * 6 + 0x13]);
        }
      }
      if ((int)uVar11 == 0) goto LAB_002735d8;
      lVar22 = param_1[4];
      pcVar14 = "*ERROR* [msm-dsi-error]: [%s] failed to initialize resources, rc=%d\n";
      uVar13 = uVar11 & 0xffffffff;
    }
    drm_dev_printk(0,&DAT_002b5e64,pcVar14,lVar22,uVar13);
    mutex_unlock(plVar16);
  }
  drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: device init failed, rc=%d\n",
                 uVar11 & 0xffffffff);
LAB_00272d80:
  lVar22 = sp_el0;
  if (*(long *)(lVar22 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// dsi_display_chk_esd_recovery @ 00279c3c size=352
// signature: undefined dsi_display_chk_esd_recovery(void)
//------------------------------------------------------------

void dsi_display_chk_esd_recovery(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined8 local_38;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (*(int *)(*(long *)(param_1 + 0x110) + 0x69c) == 1) {
    dsi_display_chk_esd_recovery_disp_esd_trigger =
         dsi_display_chk_esd_recovery_disp_esd_trigger + 1;
    iVar3 = dsi_display_status_check_te(param_1,1);
    if (iVar3 < 1) {
      pcVar4 = "*ERROR* [msm-dsi-error]: ESD: TE Check is still failed. disp_esd_trigger=%d\n";
    }
    else {
      iVar3 = dsi_display_status_reg_read(param_1);
      if (0 < iVar3) {
        *(undefined1 *)(param_1 + 0x514) = 0;
        drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: ESD_MODE_TE_CHK_REG_RD is good\n");
        dsi_display_chk_esd_recovery_disp_esd_trigger = 0;
        *(undefined1 *)(param_1 + 0x514) = 0;
        goto LAB_00279d08;
      }
      pcVar4 = "*ERROR* [msm-dsi-error]: ESD: REG_READ is still failed. disp_esd_trigger=%d\n";
    }
    drm_dev_printk(0,&DAT_002b5e64,pcVar4,dsi_display_chk_esd_recovery_disp_esd_trigger);
    if (dsi_display_chk_esd_recovery_disp_esd_trigger - 1U < 4) {
      _printk(&DAT_002fa068,dsi_display_chk_esd_recovery_disp_esd_trigger);
      local_38 = 0x480000006;
      local_2c[0] = 1;
      msm_mode_object_event_notify
                (*(undefined8 **)(param_1 + 0x10) + 8,**(undefined8 **)(param_1 + 0x10),&local_38,
                 local_2c);
      _printk(&DAT_002e062a);
    }
    else if (4 < dsi_display_chk_esd_recovery_disp_esd_trigger) {
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: ESD: disp_esd_trigger=%d is Max, calling BUG\n");
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x279d9c);
      (*pcVar2)();
    }
  }
LAB_00279d08:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dsi_display_bind @ 0027bd80 size=3096
// signature: undefined dsi_display_bind(void)
//------------------------------------------------------------

ulong dsi_display_bind(long param_1,long param_2)

{
  undefined8 *puVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  size_t __n;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  char *pcVar14;
  long *plVar15;
  undefined *local_2e8;
  undefined *puStack_2e0;
  undefined8 local_2d8;
  undefined *puStack_2d0;
  char acStack_2c8 [32];
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  long local_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  long local_250;
  undefined8 local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined4 local_208;
  undefined4 local_204;
  code *local_200;
  code *pcStack_1f8;
  code *local_1f0;
  code *pcStack_1e8;
  code *local_1e0;
  code *pcStack_1d8;
  long local_1d0;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_1c0;
  undefined7 local_1b8;
  undefined4 uStack_1b1;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  char local_a8 [64];
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  memset(acStack_2c8,0,0x110);
  local_2e8 = PTR_dsi_display_pre_release_00315288;
  puStack_2e0 = PTR_dsi_display_pre_acquire_00315290;
  local_2d8 = DAT_00315298;
  puStack_2d0 = PTR_dsi_display_get_io_resources_003152a0;
  if (((param_2 == 0) || (param_1 == 0)) || (param_1 + -0x10 == 0)) {
    drm_dev_printk(0,&DAT_002b5e64,
                   "*ERROR* [msm-dsi-error]: invalid param(s), dev %pK, pdev %pK, master %pK\n",
                   param_1,param_1 + -0x10,param_2);
    uVar10 = 0xffffffea;
    goto LAB_0027c774;
  }
  lVar13 = *(long *)(param_2 + 0x98);
  lVar12 = *(long *)(param_1 + 0x98);
  if ((lVar13 == 0) || (lVar12 == 0)) {
    drm_dev_printk(0,&DAT_002b5e64,
                   "*ERROR* [msm-dsi-error]: invalid param(s), drm %pK, display %pK\n",lVar13,lVar12
                  );
    uVar10 = 0xffffffea;
    goto LAB_0027c774;
  }
  if (*(undefined8 **)(lVar12 + 0x118) == (undefined8 *)0x0) {
    if (*(long *)(lVar12 + 0x638) == 0) {
      uVar10 = 0;
      goto LAB_0027c774;
    }
  }
  else if (*(long *)(lVar12 + 0x638) == 0) {
    *(undefined8 *)(lVar12 + 0x20) = **(undefined8 **)(lVar12 + 0x118);
  }
  if (((*(long *)(lVar12 + 0x110) != 0) && (*(char *)(*(long *)(lVar12 + 0x110) + 0x49a) != '\0'))
     && (*(int *)(lVar12 + 0x308) != 0)) {
    lVar8 = of_drm_find_bridge(*(undefined8 *)(lVar12 + 0x130));
    if (lVar8 == 0) {
      uVar11 = 0;
      plVar15 = (long *)(lVar12 + 0x130);
LAB_0027c390:
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: defer for bridge[%d] %s\n",uVar11,
                    *(undefined8 *)(*plVar15 + 0x10));
      uVar10 = 0xfffffdfb;
      goto LAB_0027c774;
    }
    if (1 < *(uint *)(lVar12 + 0x308)) {
      lVar8 = of_drm_find_bridge(*(undefined8 *)(lVar12 + 0x220));
      if (lVar8 == 0) {
        plVar15 = (long *)(lVar12 + 0x220);
        uVar11 = 1;
        goto LAB_0027c390;
      }
      if (2 < *(uint *)(lVar12 + 0x308)) goto LAB_0027c974;
    }
  }
  mutex_lock(lVar12 + 0x50);
  lVar8 = *(long *)(lVar12 + 0x110);
  if (*(char *)(lVar8 + 0x4a0) == '\0') {
LAB_0027bf54:
    local_a8[0x30] = '\0';
    local_a8[0x31] = '\0';
    local_a8[0x32] = '\0';
    local_a8[0x33] = '\0';
    local_a8[0x34] = '\0';
    local_a8[0x35] = '\0';
    local_a8[0x36] = '\0';
    local_a8[0x37] = '\0';
    local_a8[0x38] = '\0';
    local_a8[0x39] = '\0';
    local_a8[0x3a] = '\0';
    local_a8[0x3b] = '\0';
    local_a8[0x3c] = '\0';
    local_a8[0x3d] = '\0';
    local_a8[0x3e] = '\0';
    local_a8[0x3f] = '\0';
    local_a8[0x20] = '\0';
    local_a8[0x21] = '\0';
    local_a8[0x22] = '\0';
    local_a8[0x23] = '\0';
    local_a8[0x24] = '\0';
    local_a8[0x25] = '\0';
    local_a8[0x26] = '\0';
    local_a8[0x27] = '\0';
    local_a8[0x28] = '\0';
    local_a8[0x29] = '\0';
    local_a8[0x2a] = '\0';
    local_a8[0x2b] = '\0';
    local_a8[0x2c] = '\0';
    local_a8[0x2d] = '\0';
    local_a8[0x2e] = '\0';
    local_a8[0x2f] = '\0';
    local_b0 = 0;
    local_b8 = 0;
    local_c0 = 0;
    local_c8 = 0;
    local_d0 = 0;
    local_d8 = 0;
    local_e0 = 0;
    local_e8 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    local_108 = 0;
    uStack_100 = 0;
    local_118 = 0;
    uStack_110 = 0;
    local_128 = 0;
    uStack_120 = 0;
    local_138 = 0;
    uStack_130 = 0;
    local_148 = 0;
    uStack_140 = 0;
    local_158 = 0;
    uStack_150 = 0;
    local_168 = 0;
    uStack_160 = 0;
    local_178 = 0;
    uStack_170 = 0;
    local_188 = 0;
    uStack_180 = 0;
    pcVar14 = *(char **)(lVar12 + 0x20);
    local_1b8 = s__secondary_002ceb1b._0_7_;
    local_a8[0x10] = '\0';
    local_a8[0x11] = '\0';
    local_a8[0x12] = '\0';
    local_a8[0x13] = '\0';
    local_a8[0x14] = '\0';
    local_a8[0x15] = '\0';
    local_a8[0x16] = '\0';
    local_a8[0x17] = '\0';
    local_a8[0x18] = '\0';
    local_a8[0x19] = '\0';
    local_a8[0x1a] = '\0';
    local_a8[0x1b] = '\0';
    local_a8[0x1c] = '\0';
    local_a8[0x1d] = '\0';
    local_a8[0x1e] = '\0';
    local_a8[0x1f] = '\0';
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a8[8] = '\0';
    local_a8[9] = '\0';
    local_a8[10] = '\0';
    local_a8[0xb] = '\0';
    local_a8[0xc] = '\0';
    local_a8[0xd] = '\0';
    local_a8[0xe] = '\0';
    local_a8[0xf] = '\0';
    local_198 = 0;
    uStack_190 = 0;
    local_1a8 = 0;
    uStack_1a0 = 0;
    uStack_1b1 = 0x797261;
    __n = strlen(pcVar14);
    if (0xfe < __n) {
      __n = 0xff;
    }
    memcpy(&local_1a8,pcVar14,__n);
    *(undefined1 *)((long)&local_1a8 + __n) = 0;
    iVar6 = strcmp(*(char **)(lVar12 + 0x28),"secondary");
    if (iVar6 == 0) {
      strlcat(&local_1a8,&local_1b8,0x100);
    }
    uVar9 = debugfs_create_dir(&local_1a8,0);
    if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: [%s] debugfs create dir failed, rc = %d\n",
                     *(undefined8 *)(lVar12 + 0x20),uVar9 & 0xffffffff);
      uVar10 = uVar9 & 0xffffffff;
      if ((int)uVar9 == 0) goto LAB_0027c3fc;
LAB_0027c2b4:
      uVar11 = *(undefined8 *)(lVar12 + 0x20);
      pcVar14 = "*ERROR* [msm-dsi-error]: [%s] debugfs init failed, rc=%d\n";
    }
    else {
      uVar10 = debugfs_create_file("dump_info",0x100,uVar9,lVar12,dump_info_fops);
      if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] debugfs create dump info file failed, rc=%d\n"
                       ,*(undefined8 *)(lVar12 + 0x20),uVar10 & 0xffffffff);
      }
      else {
        uVar10 = debugfs_create_file("esd_trigger",0x1a4,uVar9,lVar12,esd_trigger_fops);
        if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
          uVar11 = *(undefined8 *)(lVar12 + 0x20);
          pcVar14 = "*ERROR* [msm-dsi-error]: [%s] debugfs for esd trigger file failed, rc=%d\n";
        }
        else {
          uVar10 = debugfs_create_file("esd_check_mode",0x1a4,uVar9,lVar12,esd_check_mode_fops);
          if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
            uVar11 = *(undefined8 *)(lVar12 + 0x20);
            pcVar14 = "*ERROR* [msm-dsi-error]: [%s] debugfs for esd check mode failed, rc=%d\n";
          }
          else {
            uVar10 = debugfs_create_file("cmd_sched_params",0x1a4,uVar9,lVar12,
                                         dsi_command_scheduling_fops);
            if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
              uVar11 = *(undefined8 *)(lVar12 + 0x20);
              pcVar14 = 
              "*ERROR* [msm-dsi-error]: [%s] debugfs for cmd scheduling file failed, rc=%d\n";
            }
            else {
              uVar10 = debugfs_create_file("misr_data",0x180,uVar9,lVar12,misr_data_fops);
              if ((uVar10 != 0) && (uVar10 < 0xfffffffffffff001)) {
                uVar7 = *(uint *)(lVar12 + 0xac);
                if (uVar7 != 0) {
                  lVar8 = *(long *)(lVar12 + 200);
                  if ((lVar8 != 0) && (*(char **)(lVar8 + 0x10) != (char *)0x0)) {
                    snprintf(local_a8,0x40,"%s_allow_phy_power_off",*(char **)(lVar8 + 0x10));
                    debugfs_create_bool(local_a8,0x180,uVar9,lVar8 + 0x3a8);
                    snprintf(local_a8,0x40,"%s_regulator_min_datarate_bps",*(char **)(lVar8 + 0x10))
                    ;
                    debugfs_create_u32(local_a8,0x180,uVar9,lVar8 + 0x3ac);
                    uVar7 = *(uint *)(lVar12 + 0xac);
                  }
                  if (((1 < uVar7) && (lVar8 = *(long *)(lVar12 + 0xf8), lVar8 != 0)) &&
                     (*(char **)(lVar8 + 0x10) != (char *)0x0)) {
                    snprintf(local_a8,0x40,"%s_allow_phy_power_off",*(char **)(lVar8 + 0x10));
                    debugfs_create_bool(local_a8,0x180,uVar9,lVar8 + 0x3a8);
                    snprintf(local_a8,0x40,"%s_regulator_min_datarate_bps",*(char **)(lVar8 + 0x10))
                    ;
                    debugfs_create_u32(local_a8,0x180,uVar9,lVar8 + 0x3ac);
                  }
                }
                debugfs_create_bool("ulps_feature_enable",0x180,uVar9,
                                    *(long *)(lVar12 + 0x110) + 0x8b9);
                debugfs_create_bool("ulps_suspend_feature_enable",0x180,uVar9,
                                    *(long *)(lVar12 + 0x110) + 0x8ba);
                debugfs_create_bool("ulps_status",0x100,uVar9,lVar12 + 0x48a);
                debugfs_create_u32("clk_gating_config",0x180,uVar9,lVar12 + 0x654);
                *(ulong *)(lVar12 + 0x500) = uVar9;
                dsi_parser_dbg_init(*(undefined8 *)(lVar12 + 0x640),uVar9);
                goto LAB_0027c3fc;
              }
              uVar11 = *(undefined8 *)(lVar12 + 0x20);
              pcVar14 = "*ERROR* [msm-dsi-error]: [%s] debugfs create misr datafile failed, rc=%d\n"
              ;
            }
          }
        }
        drm_dev_printk(0,&DAT_002b5e64,pcVar14,uVar11,uVar10 & 0xffffffff);
      }
      debugfs_remove(uVar9);
      if ((int)uVar10 != 0) goto LAB_0027c2b4;
LAB_0027c3fc:
      *(undefined4 *)(lVar12 + 0x334) = 0;
      *(undefined4 *)(lVar12 + 0x330) = 0;
      memset(acStack_2c8,0,0x110);
      if (*(int *)(lVar12 + 0xac) != 0) {
        plVar15 = (long *)(lVar12 + 0xb0);
        uVar7 = dsi_ctrl_drv_init(*plVar15,*(undefined8 *)(lVar12 + 0x500));
        if (uVar7 == 0) {
          *(undefined4 *)(*(long *)(lVar12 + 0xb0) + 0xc) = 0;
          uVar7 = dsi_phy_drv_init(*(undefined8 *)(lVar12 + 200));
          if (uVar7 == 0) {
            lVar8 = *(long *)(lVar12 + 0xb0);
            local_298 = *(undefined8 *)(lVar8 + 0x4d8);
            uStack_290 = *(undefined8 *)(lVar8 + 0x4e0);
            local_288 = *(undefined8 *)(lVar8 + 0x4e8);
            local_2a8 = *(undefined8 *)(lVar8 + 0x4c8);
            uStack_2a0 = *(undefined8 *)(lVar8 + 0x4d0);
            lVar8 = *(long *)(lVar12 + 0xb0);
            local_238 = *(undefined8 *)(lVar8 + 0x4f8);
            uStack_230 = *(undefined8 *)(lVar8 + 0x500);
            local_228 = *(undefined8 *)(lVar8 + 0x508);
            local_248 = *(undefined8 *)(*(long *)(lVar12 + 0xb0) + 0x510);
            local_208 = *(undefined4 *)(*(long *)(lVar12 + 0xb0) + 8);
            local_280 = lVar13;
            if (*(uint *)(lVar12 + 0xac) < 2) {
              iVar6 = 1;
            }
            else {
              plVar15 = (long *)(lVar12 + 0xe0);
              uVar7 = dsi_ctrl_drv_init(*plVar15,*(undefined8 *)(lVar12 + 0x500));
              iVar6 = 1;
              if (uVar7 != 0) goto LAB_0027c438;
              *(undefined4 *)(*(long *)(lVar12 + 0xe0) + 0xc) = 1;
              uVar7 = dsi_phy_drv_init(*(undefined8 *)(lVar12 + 0xf8));
              if (uVar7 != 0) goto LAB_0027c5c8;
              lVar8 = *plVar15;
              iVar6 = 2;
              local_268 = *(undefined8 *)(lVar8 + 0x4d8);
              uStack_260 = *(undefined8 *)(lVar8 + 0x4e0);
              local_258 = *(undefined8 *)(lVar8 + 0x4e8);
              local_278 = *(undefined8 *)(lVar8 + 0x4c8);
              uStack_270 = *(undefined8 *)(lVar8 + 0x4d0);
              lVar8 = *plVar15;
              local_220 = *(undefined8 *)(lVar8 + 0x4f8);
              uStack_218 = *(undefined8 *)(lVar8 + 0x500);
              local_210 = *(undefined8 *)(lVar8 + 0x508);
              local_240 = *(undefined8 *)(*plVar15 + 0x510);
              local_204 = *(undefined4 *)(*plVar15 + 8);
              local_250 = lVar13;
            }
            goto LAB_0027c464;
          }
          iVar6 = 0;
LAB_0027c5c8:
          uVar10 = (ulong)uVar7;
          drm_dev_printk(0,&DAT_002b5e64,
                         "*ERROR* [msm-dsi-error]: [%s] Failed to initialize phy[%d], rc=%d\n",
                         *(undefined8 *)(lVar12 + 0x20),iVar6,uVar10);
          dsi_ctrl_drv_deinit(*plVar15);
        }
        else {
          iVar6 = 0;
LAB_0027c438:
          uVar10 = (ulong)uVar7;
          drm_dev_printk(0,&DAT_002b5e64,
                         "*ERROR* [msm-dsi-error]: [%s] failed to initialize ctrl[%d], rc=%d\n",
                         *(undefined8 *)(lVar12 + 0x20),iVar6,uVar10);
        }
LAB_0027c700:
        if (iVar6 != 0) {
          lVar13 = lVar12 + (ulong)(iVar6 - 1U) * 0x30;
          dsi_phy_drv_deinit(*(undefined8 *)(lVar13 + 200));
          dsi_ctrl_drv_deinit(*(undefined8 *)(lVar13 + 0xb0));
          dsi_ctrl_put(*(undefined8 *)(lVar13 + 0xb0));
          dsi_phy_put(*(undefined8 *)(lVar13 + 200));
          if (iVar6 - 1U != 0) {
            lVar13 = lVar12 + (ulong)(iVar6 - 2) * 0x30;
            dsi_phy_drv_deinit(*(undefined8 *)(lVar13 + 200));
            dsi_ctrl_drv_deinit(*(undefined8 *)(lVar13 + 0xb0));
            dsi_ctrl_put(*(undefined8 *)(lVar13 + 0xb0));
            dsi_phy_put(*(undefined8 *)(lVar13 + 200));
          }
        }
        if (*(long *)(lVar12 + 0x500) != 0) {
          debugfs_remove();
          *(undefined8 *)(lVar12 + 0x500) = 0;
        }
        goto LAB_0027c76c;
      }
      iVar6 = 0;
LAB_0027c464:
      local_200 = dsi_pre_clkoff_cb;
      pcStack_1f8 = dsi_post_clkoff_cb;
      local_1c8 = *(undefined4 *)(lVar12 + 0x31c);
      local_1f0 = dsi_post_clkon_cb;
      pcStack_1e8 = dsi_pre_clkon_cb;
      local_1e0 = dsi_display_phy_configure;
      pcStack_1d8 = dsi_display_phy_pll_toggle;
      local_1c4 = *(undefined4 *)(lVar12 + 0xac);
      local_1d0 = lVar12;
      if (1 < *(uint *)(lVar12 + 800)) {
LAB_0027c974:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x27c978);
        (*pcVar5)();
      }
      local_1c0 = *(undefined1 *)
                   (*(long *)(lVar12 + (ulong)*(uint *)(lVar12 + 800) * 0x30 + 200) + 0x78);
      snprintf(acStack_2c8,0x20,"DSI_MNGR-%s",*(char **)(lVar12 + 0x20));
      uVar10 = dsi_display_clk_mngr_register(acStack_2c8);
      *(ulong *)(lVar12 + 0x4e8) = uVar10;
      if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
        *(undefined8 *)(lVar12 + 0x4e8) = 0;
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: dsi clock registration failed, rc = %d\n",
                       uVar10 & 0xffffffff);
        goto LAB_0027c700;
      }
      uVar10 = dsi_register_clk_handle(uVar10,"dsi_clk_client");
      if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: failed to register %s client, rc = %d\n",
                       "dsi_clk_client",uVar10 & 0xffffffff);
LAB_0027c6f8:
        dsi_display_clk_mngr_deregister(*(undefined8 *)(lVar12 + 0x4e8));
        goto LAB_0027c700;
      }
      *(ulong *)(lVar12 + 0x4f0) = uVar10;
      uVar10 = dsi_register_clk_handle(*(undefined8 *)(lVar12 + 0x4e8),"mdp_event_client");
      if ((uVar10 == 0) || (0xfffffffffffff000 < uVar10)) {
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: failed to register %s client, rc = %d\n",
                       "mdp_event_client",uVar10 & 0xffffffff);
LAB_0027c6f0:
        dsi_deregister_clk_handle(*(undefined8 *)(lVar12 + 0x4f0));
        goto LAB_0027c6f8;
      }
      *(ulong *)(lVar12 + 0x4f8) = uVar10;
      if (2 < *(uint *)(lVar12 + 800)) goto LAB_0027c974;
      lVar8 = *(long *)(lVar12 + 0x110);
      dsi_phy_get_version(*(undefined8 *)(lVar12 + (ulong)*(uint *)(lVar12 + 800) * 0x30 + 200));
      *(undefined4 *)(lVar8 + 0x4b4) = 2;
      uVar7 = dsi_display_mipi_host_init(lVar12);
      if (uVar7 != 0) {
        uVar10 = (ulong)uVar7;
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] failed to initialize mipi host, rc=%d\n",
                       *(undefined8 *)(lVar12 + 0x20),uVar10);
        goto LAB_0027c700;
      }
      puVar1 = (undefined8 *)(lVar12 + 0x4b8);
      uVar9 = dsi_panel_drv_init(*(undefined8 *)(lVar12 + 0x110),puVar1);
      uVar10 = uVar9 & 0xffffffff;
      if ((int)uVar9 == -0x205) {
LAB_0027c8e0:
        mipi_dsi_host_unregister(puVar1);
        *puVar1 = 0;
        *(undefined8 *)(lVar12 + 0x4c0) = 0;
        goto LAB_0027c6f0;
      }
      if ((int)uVar9 != 0) {
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] failed to initialize panel driver, rc=%d\n",
                       *(undefined8 *)(lVar12 + 0x20),uVar9 & 0xffffffff);
        goto LAB_0027c8e0;
      }
      pcVar14 = "";
      if (*(char *)(*(long *)(lVar12 + 0x110) + 0x8c5) != '\0') {
        pcVar14 = "as sim panel";
      }
      drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: Successfully bind display panel \'%s %s\'\n",
                     *(undefined8 *)(lVar12 + 0x20),pcVar14);
      dsi_display_is_probed(lVar12);
      uVar7 = *(uint *)(lVar12 + 0xac);
      *(long *)(lVar12 + 8) = lVar13;
      if (uVar7 == 0) {
LAB_0027c954:
        msm_register_vm_event(param_2,param_1,&local_2e8,lVar12);
        uVar10 = 0;
        goto LAB_0027c76c;
      }
      if ((*(long *)(lVar12 + 200) == 0) || (*(long *)(lVar12 + 0xb0) == 0)) {
LAB_0027c858:
        if (((1 < uVar7) && (*(long *)(lVar12 + 0xf8) != 0)) && (*(long *)(lVar12 + 0xe0) != 0)) {
          *(long *)(*(long *)(lVar12 + 0xe0) + 0x50) = lVar13;
          uVar10 = dsi_phy_set_clk_freq
                             (*(undefined8 *)(lVar12 + 0xf8),*(long *)(lVar12 + 0xe0) + 0x578);
          if ((int)uVar10 != 0) goto LAB_0027c88c;
        }
        goto LAB_0027c954;
      }
      *(long *)(*(long *)(lVar12 + 0xb0) + 0x50) = lVar13;
      uVar10 = dsi_phy_set_clk_freq(*(undefined8 *)(lVar12 + 200),*(long *)(lVar12 + 0xb0) + 0x578);
      if ((int)uVar10 == 0) {
        uVar7 = *(uint *)(lVar12 + 0xac);
        goto LAB_0027c858;
      }
LAB_0027c88c:
      uVar10 = uVar10 & 0xffffffff;
      uVar11 = *(undefined8 *)(lVar12 + 0x20);
      pcVar14 = "*ERROR* [msm-dsi-error]: [%s] failed to set phy clk freq, rc=%d\n";
    }
    drm_dev_printk(0,&DAT_002b5e64,pcVar14,uVar11,uVar10 & 0xffffffff);
  }
  else {
    if (*(int *)(lVar12 + 0xac) == 0) {
LAB_0027bf3c:
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: Split link is enabled\n");
      goto LAB_0027bf54;
    }
    if (*(char *)(*(long *)(lVar12 + 0xb0) + 0x777) != '\0') {
      puVar2 = (ulong *)(*(long *)(lVar12 + 200) + 0x88);
      Hint_Prefetch(puVar2,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
        if (bVar4) {
          *puVar2 = *puVar2 | 4;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      *(undefined4 *)(lVar8 + 0x4b0) = *(undefined4 *)(*(long *)(lVar12 + 0x110) + 0x4ec);
      if (1 < *(uint *)(lVar12 + 0xac)) {
        if (*(char *)(*(long *)(lVar12 + 0xe0) + 0x777) == '\0') goto LAB_0027c2fc;
        puVar2 = (ulong *)(*(long *)(lVar12 + 0xf8) + 0x88);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar4) {
            *puVar2 = *puVar2 | 4;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        *(undefined4 *)(lVar8 + 0x4b0) = *(undefined4 *)(*(long *)(lVar12 + 0x110) + 0x4ec);
      }
      goto LAB_0027bf3c;
    }
LAB_0027c2fc:
    drm_dev_printk(0,&DAT_002b5e64,
                   "*ERROR* [msm-dsi-error]: [%s] split link is not supported by hw\n",
                   *(undefined8 *)(lVar12 + 0x20));
    *(undefined1 *)(lVar8 + 0x4a0) = 0;
    uVar10 = 0xfffffdf4;
    drm_dev_printk(0,&DAT_002b5e64,
                   "*ERROR* [msm-dsi-error]: [%s] split link validation failed, rc=%d\n",
                   *(undefined8 *)(lVar12 + 0x20),0xfffffdf4);
  }
LAB_0027c76c:
  mutex_unlock(lVar12 + 0x50);
LAB_0027c774:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// debugfs_esd_trigger_check @ 0027d1fc size=768
// signature: undefined debugfs_esd_trigger_check(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void debugfs_esd_trigger_check(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 *puVar6;
  code *pcVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  int local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar10 = *(long *)(param_1 + 0xd8);
  local_4c = 0;
  lVar5 = *(long *)(lVar10 + 0x110);
  if (lVar10 == 0) {
    uVar8 = 0xffffffffffffffed;
    goto LAB_0027d280;
  }
  if (*param_4 != 0) {
    uVar8 = 0;
    goto LAB_0027d280;
  }
  if (4 < param_3) {
LAB_0027d258:
    uVar8 = 0xffffffffffffffea;
    goto LAB_0027d280;
  }
  uVar8 = 0xffffffffffffffea;
  if ((param_2 == 0) || (param_3 == 0)) goto LAB_0027d280;
  if ((lVar5 == 0) || (*(int *)(lVar5 + 0x8c0) != 0)) {
    uVar8 = param_3;
    goto LAB_0027d280;
  }
  if (*(char *)(lVar5 + 0x698) == '\0') {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: ESD feature is not enabled\n");
    goto LAB_0027d258;
  }
  lVar5 = kmalloc_trace(___drm_debug,0xdc0,10);
  if (lVar5 == 0) {
    uVar8 = 0xfffffffffffffff4;
    goto LAB_0027d280;
  }
  __check_object_size(lVar5,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar8 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (0x8000000000 - param_3 < uVar8) {
LAB_0027d4c4:
    memset((void *)(lVar5 + (param_3 - uVar4)),0,uVar4);
    iVar3 = -0x16;
  }
  else {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    uVar4 = __arch_copy_from_user(puVar6,lVar5,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    if (uVar4 != 0) goto LAB_0027d4c4;
    if (9 < param_3) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(1,0x27d4e4);
      (*pcVar7)();
    }
    *(undefined1 *)(lVar5 + param_3) = 0;
    iVar2 = kstrtouint(lVar5,10,&local_4c);
    iVar3 = -0x16;
    if (iVar2 == 0) {
      if (local_4c == 1) {
        *(undefined4 *)(lVar10 + 0x510) = 1;
        mutex_lock(lVar10 + 0x50);
        if (*(char *)(lVar10 + 0x672) == '\0') {
          __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] op not supported due to HW unavailability\n",
                        *(undefined8 *)(lVar10 + 0x20));
          param_3 = 0xffffffa1;
        }
        else if (*(int *)(lVar10 + 0x510) != 0) {
          lVar9 = *(long *)(lVar10 + 0x110);
          drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: ESD attack triggered by user\n");
          pcVar7 = *(code **)(lVar9 + 0x9e8);
          if (*(int *)(pcVar7 + -4) != -0x366e12b8) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x27d43c);
            (*pcVar7)();
          }
          iVar3 = (*pcVar7)(lVar9);
          if (iVar3 != 0) {
            drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: Failed to trigger ESD attack\n"
                          );
            goto LAB_0027d4b4;
          }
        }
        mutex_unlock(lVar10 + 0x50);
        iVar3 = (int)param_3;
      }
    }
  }
LAB_0027d4b4:
  kfree(lVar5);
  uVar8 = (ulong)iVar3;
LAB_0027d280:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// debugfs_read_esd_check_mode @ 0027d518 size=640
// signature: undefined debugfs_read_esd_check_mode(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t debugfs_read_esd_check_mode(long param_1,ulong param_2,size_t param_3,long *param_4)

{
  ulong uVar1;
  int iVar2;
  char *__s;
  size_t sVar3;
  char *pcVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0xd8);
  if (lVar7 == 0) {
    param_3 = 0xffffffffffffffed;
  }
  else if (*param_4 == 0) {
    if (*(long *)(lVar7 + 0x110) == 0) {
      drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid panel data\n");
      param_3 = 0xffffffffffffffea;
    }
    else {
      __s = (char *)kmalloc_trace(_drm_dp_dpcd_read,0xdc0,0x100);
      if (__s < (char *)0x11) {
        param_3 = 0xfffffffffffffff4;
      }
      else {
        pcVar4 = (char *)(*(long *)(lVar7 + 0x110) + 0x698);
        if (pcVar4 == (char *)0x0) {
          drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: Invalid panel esd config\n");
          param_3 = 0;
        }
        else {
          if (0xfe < param_3) {
            param_3 = 0xff;
          }
          if (*pcVar4 == '\0') {
            pcVar4 = "ESD feature not enabled";
          }
          else {
            pcVar4 = "reg_read";
            switch(*(undefined4 *)(*(long *)(lVar7 + 0x110) + 0x69c)) {
            case 0:
              break;
            case 1:
              snprintf(__s,param_3,"te_chk_reg_rd");
            default:
              pcVar4 = "invalid";
              break;
            case 3:
              pcVar4 = "te_signal_check";
              break;
            case 4:
              pcVar4 = "esd_sw_sim_success";
              break;
            case 5:
              pcVar4 = "esd_sw_sim_failure";
            }
          }
          iVar2 = snprintf(__s,param_3,pcVar4);
          if (iVar2 != 0) {
            __check_object_size(__s,param_3,1);
            puVar5 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
               (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
              uVar6 = param_2 & (long)(param_2 << 8) >> 8;
            }
            sVar3 = param_3;
            if (uVar6 <= 0x8000000000 - param_3) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar6 = daif;
                if ((uVar6 & 0x80) == 0) {
                  uVar1 = daif;
                  daif = uVar1 | 0xc0;
                }
                puVar5 = (undefined8 *)puVar5[1];
                uVar1 = ttbr1_el1;
                ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar5;
                InstructionSynchronizationBarrier();
                daif = uVar6;
              }
              sVar3 = __arch_copy_to_user(puVar5,param_2 & 0xff7fffffffffffff,__s,param_3);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar6 = daif;
                if ((uVar6 & 0x80) == 0) {
                  uVar1 = daif;
                  daif = uVar1 | 0xc0;
                }
                uVar1 = ttbr1_el1;
                ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar1 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar6;
              }
            }
            if (sVar3 == 0) {
              *param_4 = *param_4 + param_3;
            }
          }
        }
        kfree(__s);
      }
    }
  }
  else {
    param_3 = 0;
  }
  return param_3;
}



//------------------------------------------------------------
// debugfs_alter_esd_check_mode @ 0027d7b4 size=704
// signature: undefined debugfs_alter_esd_check_mode(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long debugfs_alter_esd_check_mode(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  char *__s1;
  ulong uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = *(long *)(param_1 + 0xd8);
  if (lVar9 == 0) {
    return -0x13;
  }
  if (*param_4 != 0) {
    return 0;
  }
  __s1 = (char *)kmalloc_trace(_drm_dp_dpcd_read,0xdc0,0x100);
  if (__s1 < (char *)0x11) {
    return -0xc;
  }
  uVar1 = param_3;
  if (0xfe < param_3) {
    uVar1 = 0xff;
  }
  __check_object_size(__s1,uVar1,0);
  puVar7 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
    uVar8 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = uVar1;
  if (uVar8 <= 0x8000000000 - uVar1) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar7 = (undefined8 *)puVar7[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar7;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    uVar4 = __arch_copy_from_user(puVar7,__s1,param_2 & 0xff7fffffffffffff,uVar1);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
  }
  if (uVar4 == 0) {
    __s1[uVar1] = '\0';
    lVar10 = *(long *)(lVar9 + 0x110);
    if (lVar10 != 0) {
      if ((char *)(lVar10 + 0x698) == (char *)0x0) {
        puVar5 = &DAT_002b5e64;
        pcVar6 = "*ERROR* [msm-dsi-error]: Invalid panel esd config\n";
      }
      else {
        if (*(char *)(lVar10 + 0x698) == '\0') goto LAB_0027d9ac;
        iVar3 = strcmp(__s1,"te_signal_check\n");
        if (iVar3 != 0) {
          iVar3 = strcmp(__s1,"reg_read\n");
          if (iVar3 == 0) {
            drm_dev_printk(0,&DAT_002cdc0f,
                           "[msm-dsi-info]: ESD check is switched to reg read by user\n");
            iVar3 = dsi_panel_parse_esd_reg_read_configs(*(undefined8 *)(lVar9 + 0x110));
            if (iVar3 != 0) {
              drm_dev_printk(0,&DAT_002b5e64,
                             "*ERROR* [msm-dsi-error]: failed to alter esd check mode,rc=%d\n",iVar3
                            );
              goto LAB_0027d9b0;
            }
            *(undefined4 *)(lVar10 + 0x69c) = 0;
            uVar8 = dsi_display_is_te_based_esd(lVar9);
            if ((uVar8 & 1) != 0) {
              dsi_display_change_te_irq_status(lVar9,0);
            }
          }
          iVar3 = strcmp(__s1,"esd_sw_sim_success\n");
          if (iVar3 == 0) {
            *(undefined4 *)(lVar10 + 0x69c) = 4;
          }
          iVar3 = strcmp(__s1,"esd_sw_sim_failure\n");
          param_3 = uVar1;
          if (iVar3 == 0) {
            *(undefined4 *)(lVar10 + 0x69c) = 5;
          }
          goto LAB_0027d9b0;
        }
        puVar5 = &DAT_002cdc0f;
        pcVar6 = "[msm-dsi-info]: TE based ESD check for panels is not allowed\n";
      }
      drm_dev_printk(0,puVar5,pcVar6);
    }
  }
  else {
    memset(__s1 + (uVar1 - uVar4),0,uVar4);
  }
LAB_0027d9ac:
  param_3 = 0xffffffffffffffea;
LAB_0027d9b0:
  kfree(__s1);
  return (long)(int)param_3;
}



//------------------------------------------------------------
// dsi_display_is_te_based_esd @ 0027da8c size=96
// signature: undefined dsi_display_is_te_based_esd(void)
//------------------------------------------------------------

undefined8 dsi_display_is_te_based_esd(long param_1)

{
  if (*(long *)(param_1 + 0x110) == 0) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: Invalid panel data\n");
  }
  else if (((*(uint *)(*(long *)(param_1 + 0x110) + 0x69c) & 0xfffffffd) == 1) &&
          (*(uint *)(param_1 + 0x80) < 0x200)) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// dsi_panel_set_backlight @ 0027fea8 size=1020
// signature: undefined dsi_panel_set_backlight(void)
//------------------------------------------------------------

int dsi_panel_set_backlight(undefined8 *param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  ulong local_50;
  ulong uStack_48;
  undefined1 local_40 [5];
  undefined3 uStack_3b;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  if (*(char *)((long)param_1 + 0x49a) != '\0') goto LAB_0027fed4;
  if (*(char *)(param_1 + 0xdd) != '\0') {
    *(int *)(param_1 + 0xde) = param_2;
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: backlight type:%d dbv lvl:%d\n",
                  *(undefined4 *)(param_1 + 0xb4),param_2);
  }
  if (DAT_0031f1b6 == '\0') {
LAB_0027ff7c:
    *(int *)(param_1 + 0xc3) = param_2;
    if ((1 < *(int *)((long)param_1 + 0x99c) - 1U) || (*(char *)((long)param_1 + 0xbec) != '\0')) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: backlight type:%d lvl:%d\n",
                    *(undefined4 *)(param_1 + 0xb4),param_2);
      iVar5 = 0;
      switch(*(undefined4 *)(param_1 + 0xb4)) {
      case 0:
        if (param_1 == (undefined8 *)0x0) {
          pcVar7 = "*ERROR* [msm-dsi-error]: Invalid Params\n";
        }
        else {
          lVar6 = param_1[0xbd];
          if (lVar6 != 0) {
            uVar3 = *(int *)((long)param_1 + 0x5f4) * 1000;
            uVar4 = 0;
            if (*(uint *)(param_1 + 0xb6) != 0) {
              uVar4 = (uVar3 * param_2) / *(uint *)(param_1 + 0xb6);
            }
            if ((int)(uVar4 | uVar3) < 0) {
              iVar5 = -0x16;
LAB_002801b0:
              uVar8 = *param_1;
              pcVar7 = "*ERROR* [msm-dsi-error]: [%s] failed to change pwm config, rc=%d\n";
            }
            else {
              local_50 = *(ulong *)(lVar6 + 0x38);
              uStack_48 = *(ulong *)(lVar6 + 0x40);
              _local_40 = *(undefined8 *)(lVar6 + 0x48);
              if (((uStack_48 != uVar4) || (local_50 != uVar3)) &&
                 (local_50 = (ulong)uVar3, uStack_48 = (ulong)uVar4,
                 iVar5 = pwm_apply_state(lVar6,&local_50), iVar5 != 0)) goto LAB_002801b0;
              if (param_2 == 0) {
                if (*(char *)(param_1 + 0xbe) != '\0') {
                  lVar6 = param_1[0xbd];
                  if (lVar6 != 0) {
                    uVar8 = *(undefined8 *)(lVar6 + 0x48);
                    local_50 = *(ulong *)(lVar6 + 0x38);
                    uStack_48 = *(ulong *)(lVar6 + 0x40);
                    local_40[4] = (char)((ulong)uVar8 >> 0x20);
                    bVar1 = local_40[4] != '\0';
                    _local_40 = uVar8;
                    if (bVar1) {
                      uStack_3b = (undefined3)((ulong)uVar8 >> 0x28);
                      local_40._0_4_ = SUB84(uVar8,0);
                      local_40 = (undefined1  [5])CONCAT14(0,local_40._0_4_);
                      pwm_apply_state(lVar6,&local_50);
                    }
                  }
                  iVar5 = 0;
                  *(undefined1 *)(param_1 + 0xbe) = 0;
                  break;
                }
LAB_00280210:
                iVar5 = 0;
                break;
              }
              if (*(char *)(param_1 + 0xbe) != '\0') goto LAB_00280210;
              lVar6 = param_1[0xbd];
              if (lVar6 != 0) {
                uVar8 = *(undefined8 *)(lVar6 + 0x48);
                local_50 = *(ulong *)(lVar6 + 0x38);
                uStack_48 = *(ulong *)(lVar6 + 0x40);
                local_40[4] = (char)((ulong)uVar8 >> 0x20);
                bVar1 = local_40[4] == '\0';
                _local_40 = uVar8;
                if (bVar1) {
                  uStack_3b = (undefined3)((ulong)uVar8 >> 0x28);
                  local_40._0_4_ = SUB84(uVar8,0);
                  local_40 = (undefined1  [5])CONCAT14(1,local_40._0_4_);
                  iVar5 = pwm_apply_state(lVar6,&local_50);
                  if (iVar5 != 0) goto LAB_00280288;
                }
                iVar5 = 0;
                *(undefined1 *)(param_1 + 0xbe) = 1;
                break;
              }
              iVar5 = -0x16;
LAB_00280288:
              uVar8 = *param_1;
              pcVar7 = "*ERROR* [msm-dsi-error]: [%s] failed to enable pwm, rc=%d\n";
            }
            drm_dev_printk(0,&DAT_002b5e64,pcVar7,uVar8,iVar5);
            break;
          }
          pcVar7 = "*ERROR* [msm-dsi-error]: pwm device not found\n";
        }
        drm_dev_printk(0,&DAT_002b5e64,pcVar7);
        iVar5 = -0x16;
        break;
      case 1:
        iVar5 = backlight_device_set_brightness(param_1[0xc0],param_2);
        break;
      case 2:
        if (*(char *)(param_1 + 0xee) == '\0') {
          iVar5 = 0;
          cVar2 = *(char *)((long)param_1 + 0x7a9);
        }
        else {
          iVar5 = dsi_panel_set_apl(param_1,param_2);
          cVar2 = *(char *)((long)param_1 + 0x7a9);
        }
        if ((cVar2 == '\0') || (*(char *)((long)param_1 + 0x7aa) == '\0')) {
          if (*(char *)(param_1 + 0xf7) != '\0') {
            iVar5 = dsi_panel_set_od(param_1,param_2);
          }
          if (*(char *)(param_1 + 0xfe) == '\0') {
            iVar5 = dsi_panel_update_backlight(param_1,param_2);
          }
        }
        break;
      case 3:
      case 4:
        break;
      default:
        drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: Backlight type(%d) not supported\n"
                      );
        iVar5 = -0x20c;
      }
      if ((*(char *)((long)param_1 + 0x809) != '\0') && (*(char *)((long)param_1 + 0xbec) != '\0'))
      {
        dsi_panel_aod_backlight_update(param_1,0x39);
        iVar5 = dsi_panel_tx_cmd_set(param_1,0x39);
        if (iVar5 != 0) {
          drm_dev_printk(0,&DAT_002b5e64,
                         "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_CMD_BACKLIGHT cmds, rc=%d\n"
                         ,*param_1,iVar5);
        }
      }
      goto LAB_0027fed8;
    }
    drm_dev_printk(0,&DAT_002cdc0f,
                   "[msm-dsi-info]: %s: power_mode %d, panel_trueaod_state %d, skip set backlight to %d\n"
                   ,"dsi_panel_set_backlight",*(int *)((long)param_1 + 0x99c),0,param_2);
  }
  else if (param_2 == -2) {
    if (*(int *)((long)param_1 + 0xb24) != 0) {
LAB_0027ff68:
      lVar6 = 0x5b0;
      if (param_2 != -2) {
        lVar6 = 0xb28;
      }
      param_2 = *(int *)((long)param_1 + lVar6);
      goto LAB_0027ff7c;
    }
  }
  else {
    if (param_2 + 3U < 2) goto LAB_0027ff68;
    *(int *)(param_1 + 0x165) = param_2;
    if (DAT_0031f1b4 == 0) goto LAB_0027ff7c;
    drm_dev_printk(0,&DAT_002cdc0f,
                   "[msm-dsi-info]: HBM is on.. ignore setting backlight. bl_vl=%d\n",param_2);
  }
LAB_0027fed4:
  iVar5 = 0;
LAB_0027fed8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// dsi_panel_update_backlight @ 002804d4 size=320
// signature: undefined dsi_panel_update_backlight(void)
//------------------------------------------------------------

int dsi_panel_update_backlight(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  
  if ((param_1 == 0) || (0xffff < param_2)) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid params\n");
    return -0x16;
  }
  if (*(char *)(param_1 + 0x608) == '\0') {
    uVar5 = 0;
  }
  else {
    uVar5 = *(ulong *)(param_1 + 0x3d0);
    *(ulong *)(param_1 + 0x3d0) = uVar5 | 0x800;
  }
  iVar2 = *(int *)(param_1 + 0x60c);
  *(uint *)(param_1 + 0x60c) = param_2;
  uVar1 = param_2;
  if (*(char *)(param_1 + 0x5cc) != '\0') {
    uVar1 = (param_2 & 0xff) << 8 | param_2 >> 8;
  }
  if (*(char *)(param_1 + 0x5a8) != '\0') {
    uVar1 = ((uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8) & 0xffff;
  }
  iVar4 = mipi_dsi_dcs_set_display_brightness(param_1 + 0x18,uVar1);
  if (((*(char *)(param_1 + 0x610) != '\0') && (param_2 != 0)) && (iVar2 == 0)) {
    _printk(&DAT_00306624,*(undefined4 *)(param_1 + 0x60c));
    iVar4 = mipi_dsi_dcs_set_display_brightness(param_1 + 0x18,uVar1);
  }
  if (iVar4 < 0) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: failed to update dcs backlight:%d\n",
                   uVar1);
    cVar3 = *(char *)(param_1 + 0x608);
  }
  else {
    cVar3 = *(char *)(param_1 + 0x608);
  }
  if (cVar3 != '\0') {
    *(ulong *)(param_1 + 0x3d0) = uVar5;
  }
  return iVar4;
}



//------------------------------------------------------------
// dsi_panel_parse_esd_reg_read_configs @ 0028182c size=932
// signature: undefined dsi_panel_parse_esd_reg_read_configs(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dsi_panel_parse_esd_reg_read_configs(long param_1)

{
  int *piVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  char *pcVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  int iVar16;
  uint uVar17;
  undefined8 uVar18;
  uint local_4c;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  local_4c = 0;
  if (param_1 == 0) {
    pcVar9 = "*ERROR* [msm-dsi-error]: Invalid Params\n";
LAB_00281930:
    drm_dev_printk(0,&DAT_002b5e64,pcVar9);
    uVar18 = 0xffffffea;
    goto LAB_00281ab0;
  }
  if (param_1 == -0x698) {
    uVar18 = 0xffffffea;
    goto LAB_00281ab0;
  }
  lVar10 = param_1 + 0x828;
  dsi_panel_parse_cmd_sets_sub(param_1,param_1 + 0x6a0,0xf,lVar10);
  if (*(int *)(param_1 + 0x6a8) == 0) {
    pcVar9 = "*ERROR* [msm-dsi-error]: panel status command parsing failed\n";
    goto LAB_00281930;
  }
  plVar2 = (long *)(param_1 + 0x6b8);
  uVar8 = dsi_panel_parse_esd_status_len(lVar10,"qcom,mdss-dsi-panel-status-read-length",plVar2);
  if ((uVar8 & 1) == 0) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: Invalid status read length\n");
    uVar18 = 0xffffffea;
  }
  else {
    plVar3 = (long *)(param_1 + 0x6c0);
    uVar8 = dsi_panel_parse_esd_status_len
                      (lVar10,"qcom,mdss-dsi-panel-status-valid-params",plVar3,
                       *(undefined4 *)(param_1 + 0x6a8));
    if (((uVar8 & 1) == 0) || (uVar17 = *(uint *)(param_1 + 0x6a8), uVar17 == 0)) {
LAB_002819a4:
      lVar10 = *plVar3;
      if (lVar10 == 0) {
        lVar10 = *plVar2;
      }
      uVar17 = *(uint *)(param_1 + 0x6a8);
      uVar8 = (ulong)uVar17;
      if (uVar17 == 0) goto LAB_00281a94;
      if (uVar17 == 1) {
        uVar14 = 0;
        uVar17 = 0;
LAB_00281a04:
        lVar12 = uVar8 - uVar14;
        piVar11 = (int *)(lVar10 + uVar14 * 4);
        do {
          lVar12 = lVar12 + -1;
          uVar17 = *piVar11 + uVar17;
          piVar11 = piVar11 + 1;
        } while (lVar12 != 0);
      }
      else {
        uVar14 = uVar8 & 0xfffffffe;
        iVar7 = 0;
        iVar16 = 0;
        piVar11 = (int *)(lVar10 + 4);
        uVar15 = uVar14;
        do {
          piVar1 = piVar11 + -1;
          iVar4 = *piVar11;
          piVar11 = piVar11 + 2;
          uVar15 = uVar15 - 2;
          iVar7 = *piVar1 + iVar7;
          iVar16 = iVar4 + iVar16;
        } while (uVar15 != 0);
        uVar17 = iVar16 + iVar7;
        if (uVar14 != uVar8) goto LAB_00281a04;
      }
      if (uVar17 == 0) goto LAB_00281a94;
      if (*(int *)(*(code **)(param_1 + 0x888) + -4) != 0x31beb620) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x281a4c);
        (*pcVar6)();
      }
      uVar8 = (**(code **)(param_1 + 0x888))
                        (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-panel-status-value",
                         &local_4c);
      uVar13 = local_4c >> 2;
      if (((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) || (local_4c < 4)) {
LAB_00281a7c:
        local_4c = uVar13;
        drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: error parse panel-status-value\n");
        goto LAB_00281a94;
      }
      uVar5 = 0;
      if (uVar17 != 0) {
        uVar5 = uVar13 / uVar17;
      }
      if (uVar13 != uVar5 * uVar17) goto LAB_00281a7c;
      *(uint *)(param_1 + 0x6e0) = uVar5;
      local_4c = uVar13;
      lVar10 = __kmalloc((ulong)uVar17 * (ulong)uVar5 * 4,0xdc0);
      *(long *)(param_1 + 0x6c8) = lVar10;
      if (lVar10 == 0) {
        uVar18 = 0xfffffff4;
      }
      else {
        lVar10 = __kmalloc(*(int *)(param_1 + 0x6e0) * uVar17,0xdc0);
        *(long *)(param_1 + 0x6d0) = lVar10;
        if (lVar10 != 0) {
          lVar10 = kmalloc_trace(_kthread_park,0xdc0,0x1000);
          *(long *)(param_1 + 0x6d8) = lVar10;
          if (lVar10 != 0) {
            if (*(int *)(*(code **)(param_1 + 0x860) + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x281b68);
              (*pcVar6)();
            }
            iVar7 = (**(code **)(param_1 + 0x860))
                              (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-panel-status-value",
                               *(undefined8 *)(param_1 + 0x6c8),*(int *)(param_1 + 0x6e0) * uVar17);
            if (iVar7 == 0) {
              uVar18 = 0;
            }
            else {
              __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: error reading panel status values\n");
              memset(*(void **)(param_1 + 0x6c8),0,(ulong)(*(int *)(param_1 + 0x6e0) * uVar17));
              uVar18 = 0;
            }
            goto LAB_00281ab0;
          }
          kfree(*(undefined8 *)(param_1 + 0x6d0));
        }
        kfree(*(undefined8 *)(param_1 + 0x6c8));
        uVar18 = 0xfffffff4;
      }
    }
    else {
      if (*(uint *)*plVar2 < *(uint *)*plVar3) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: ignore valid params\n");
      }
      else {
        uVar8 = 1;
        do {
          uVar13 = (uint)uVar8;
          if (uVar17 == uVar13) goto LAB_002819a4;
          uVar15 = -(uVar8 >> 0x1f) & 0xfffffffc00000000 | uVar8 << 2;
          uVar8 = (ulong)(uVar13 + 1);
        } while (*(uint *)(*plVar3 + uVar15) <= *(uint *)(*plVar2 + uVar15));
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: ignore valid params\n");
        if (uVar17 <= uVar13) goto LAB_002819a4;
      }
LAB_00281a94:
      uVar18 = 0xffffffea;
    }
    kfree(*plVar3);
    kfree(*plVar2);
  }
  kfree(*(undefined8 *)(param_1 + 0x6b0));
LAB_00281ab0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar18;
}



//------------------------------------------------------------
// dsi_panel_parse_esd_status_len @ 00281f20 size=368
// signature: undefined dsi_panel_parse_esd_status_len(void)
//------------------------------------------------------------

void dsi_panel_parse_esd_status_len
               (undefined8 *param_1,undefined8 param_2,ulong *param_3,uint param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  if (*(int *)((code *)param_1[0xc] + -4) != 0x31beb620) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x281f7c);
    (*pcVar2)();
  }
  lVar4 = (*(code *)param_1[0xc])(*param_1,param_2,&local_3c);
  uVar6 = 0;
  if (lVar4 != 0) {
    uVar1 = (int)local_3c >> 2;
    if (uVar1 == param_4) {
      if ((int)local_3c < 0) {
        *param_3 = 0;
        local_3c = uVar1;
      }
      else {
        local_3c = uVar1;
        uVar5 = __kmalloc(-(ulong)(param_4 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_4 << 2,0xdc0
                         );
        *param_3 = uVar5;
        if ((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) {
          if (*(int *)((code *)param_1[7] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x281fe4);
            (*pcVar2)();
          }
          iVar3 = (*(code *)param_1[7])(*param_1,param_2,uVar5,(long)(int)local_3c);
          if (iVar3 == 0) {
            uVar6 = 1;
          }
          else {
            drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: cannot get values from dts\n");
            kfree(*param_3);
            uVar6 = 0;
            *param_3 = 0;
          }
          goto LAB_00282060;
        }
      }
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: Error allocating memory for property\n");
    }
    else {
      local_3c = uVar1;
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: request property(%d) do not match cmd count(%d)\n",
                     uVar1,param_4);
    }
    uVar6 = 0;
  }
LAB_00282060:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// dsi_panel_get @ 00282094 size=11360
// signature: undefined dsi_panel_get(void)
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
dsi_panel_get(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
             undefined8 param_5,ulong param_6,uint param_7)

{
  undefined8 *__dest;
  int *piVar1;
  undefined8 *puVar2;
  ushort *puVar3;
  undefined **ppuVar4;
  uint uVar5;
  char cVar6;
  ushort uVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  byte bVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined8 *puVar15;
  char *pcVar16;
  char *pcVar17;
  size_t __n;
  undefined8 uVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  char *pcVar22;
  undefined1 uVar23;
  undefined4 uVar24;
  code *pcVar25;
  undefined1 *puVar26;
  ulong uVar27;
  code *pcVar28;
  undefined8 uVar29;
  code *pcVar30;
  uint *puVar31;
  uint uVar32;
  code *pcVar33;
  ulong uVar34;
  code *pcVar35;
  code *pcVar36;
  code *pcVar37;
  code *pcVar38;
  code *pcVar39;
  long *plVar40;
  undefined4 uVar41;
  undefined *puVar42;
  ulong uVar43;
  ulong uVar44;
  ulong uVar45;
  ulong uVar46;
  undefined8 local_80;
  undefined4 local_74;
  undefined8 uStack_70;
  long local_68;
  
  lVar19 = sp_el0;
  local_68 = *(long *)(lVar19 + 0x638);
  puVar15 = (undefined8 *)kmalloc_trace(_kthread_park,0xdc0,0xbf0);
  if (puVar15 != (undefined8 *)0x0) {
    if ((param_6 & 1) == 0) {
      pcVar25 = dsi_panel_trigger_esd_attack;
      pcVar28 = dsi_panel_parse_power_cfg;
      pcVar30 = dsi_panel_parse_gpios;
      pcVar33 = dsi_panel_bl_unregister;
      pcVar35 = dsi_panel_bl_register;
      pcVar36 = dsi_panel_gpio_release;
      pcVar37 = dsi_panel_pinctrl_deinit;
      pcVar39 = dsi_panel_gpio_request;
      pcVar38 = dsi_panel_pinctrl_init;
    }
    else {
      pcVar38 = dsi_panel_vm_stub;
      pcVar39 = dsi_panel_vm_stub;
      pcVar37 = dsi_panel_vm_stub;
      pcVar36 = dsi_panel_vm_stub;
      pcVar35 = dsi_panel_vm_stub;
      pcVar33 = dsi_panel_vm_stub;
      pcVar30 = dsi_panel_vm_stub;
      pcVar28 = dsi_panel_vm_stub;
      pcVar25 = dsi_panel_vm_trigger_esd_attack;
    }
    puVar15[0x8c] = param_1;
    __dest = puVar15 + 0x105;
    puVar15[0x135] = pcVar38;
    puVar15[0x136] = pcVar39;
    puVar15[0x137] = pcVar37;
    puVar15[0x138] = pcVar36;
    puVar15[0x139] = pcVar35;
    puVar15[0x13a] = pcVar33;
    puVar15[0x13b] = pcVar30;
    puVar15[0x13c] = pcVar28;
    puVar15[0x13d] = pcVar25;
    puVar15[1] = param_4;
    puVar15[2] = param_2;
    if (param_3 == 0) {
      memcpy(__dest,dsi_parser_get_of_utils_of_utils,0x90);
      pcVar25 = of_get_property;
      *__dest = param_2;
      uVar18 = param_2;
      uVar29 = param_2;
    }
    else {
      memcpy(__dest,dsi_parser_get_parser_utils_parser_utils,0x90);
      puVar15[0x105] = param_3;
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: switching to parser APIs\n");
      pcVar25 = (code *)puVar15[0x107];
      uVar18 = puVar15[0x105];
      uVar29 = puVar15[2];
    }
    puVar15[0x106] = uVar29;
    if (*(int *)(pcVar25 + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282240);
      (*pcVar25)();
    }
    pcVar16 = (char *)(*pcVar25)(uVar18,"qcom,mdss-dsi-panel-name",0);
    pcVar17 = "Default dsi panel";
    if (pcVar16 != (char *)0x0) {
      pcVar17 = pcVar16;
    }
    *puVar15 = pcVar17;
    if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282284);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-panel-supplier",0);
    if ((pcVar17 == (char *)0x0) || (*pcVar17 == '\0')) {
      _printk(&DAT_002b921c);
      puVar26 = (undefined1 *)((long)puVar15 + 0xaa3);
      *(undefined4 *)((long)puVar15 + 0xa9c) = 0x6e6b6e75;
      *(undefined4 *)((long)puVar15 + 0xa9f) = 0x6e776f6e;
    }
    else {
      __n = strlen(pcVar17);
      if (0x7e < __n) {
        __n = 0x7f;
      }
      memcpy((void *)((long)puVar15 + 0xa9c),pcVar17,__n);
      puVar26 = (undefined1 *)((long)puVar15 + 0xa9c + __n);
    }
    pcVar25 = (code *)puVar15[0x107];
    uVar18 = puVar15[0x105];
    *puVar26 = 0;
    *(undefined4 *)(puVar15 + 0x134) = 0;
    if (*(int *)(pcVar25 + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x2822f8);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*pcVar25)(uVar18,"qcom,mdss-dsi-panel-physical-type",0);
    if ((pcVar17 != (char *)0x0) && (iVar12 = strcmp(pcVar17,"oled"), iVar12 == 0)) {
      *(undefined4 *)(puVar15 + 0x134) = 1;
    }
    piVar1 = (int *)((long)puVar15 + 0xb1c);
    iVar12 = of_property_read_variable_u32_array
                       (param_2,"qcom,mdss-dsi-panel-on-check-value",piVar1,1,0);
    if (iVar12 < 0) {
      if (((*(int *)(puVar15 + 0xd5) == 1) && ((int *)puVar15[0xd9] != (int *)0x0)) &&
         (iVar12 = *(int *)puVar15[0xd9], iVar12 != 0)) {
        *piVar1 = iVar12;
        drm_dev_printk(0,&DAT_002cdc0f,
                       "[msm-dsi-info]: disp_on_chk_val is set with ESD\'s chk value\n");
      }
      else {
        drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: hardcode disp_on_chk_val\n");
        *piVar1 = 0x9c;
      }
    }
    else {
      drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: disp_on_chk_val = 0x%x is defined\n",*piVar1);
    }
    lVar19 = of_find_property(param_2,"qcom,mdss-dsi-no-panel-on-read-support",0);
    *(bool *)(puVar15 + 0x164) = lVar19 != 0;
    lVar19 = of_find_property(param_2,"qcom,mdss-dsi-hbm-dim-off",0);
    *(bool *)((long)puVar15 + 0xb22) = lVar19 != 0;
    lVar19 = of_find_property(param_2,"qcom,tp_state_check_enable",0);
    puVar2 = puVar15 + 0x169;
    *(bool *)((long)puVar15 + 0xb3c) = lVar19 != 0;
    iVar12 = of_property_read_variable_u32_array
                       (param_2,"qcom,mdss-dsi-panel-param-verision",puVar2,1,0);
    if (iVar12 < 0) {
      drm_dev_printk(0,&DAT_002cdc0f,
                     "[msm-dsi-info]: qcom,mdss-dsi-panel-param-verision not found, set param version to max value 991231\n"
                    );
      *(undefined4 *)puVar2 = 0xf1fff;
    }
    else {
      drm_dev_printk(0,&DAT_002cdc0f,
                     "[msm-dsi-info]: got paramVersion %d from qcom,mdss-dsi-panel-param-verision\n"
                     ,*(undefined4 *)puVar2);
    }
    lVar19 = of_find_property(param_2,"qcom,mot_nt37705A_read_cellid",0);
    *(undefined1 *)((long)puVar15 + 0xb65) = 0;
    *(bool *)((long)puVar15 + 0xb4c) = lVar19 != 0;
    lVar19 = of_find_property(param_2,"qcom,check_pcd",0);
    *(bool *)((long)puVar15 + 0xb66) = lVar19 != 0;
    iVar12 = of_property_read_variable_u32_array
                       (param_2,"qcom,mdss-dsi-panel-sf-brightnesszone-enable",puVar15 + 0x17d,1,0);
    if (iVar12 < 0) {
      drm_dev_printk(0,&DAT_002cdc0f,
                     "[msm-dsi-info]: qcom,mdss-dsi-panel-sf-brightnesszone-enable not found, set value 0xF\n"
                    );
      *(undefined4 *)(puVar15 + 0x17d) = 0xf;
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse mot_panel_config, rc = %d\n",iVar12);
    }
    if (param_7 < 3) {
      puVar15[0x166] = &dsi_panel_param + (ulong)param_7 * 0xf;
      lVar19 = of_find_property(param_2,"qcom,mdss-dsi-hbm-fod",0);
      *(bool *)((long)puVar15 + 0xb21) = lVar19 != 0;
      if (param_7 != 2) {
        uVar34 = (ulong)param_7;
        uVar44 = 0;
        lVar19 = uVar34 * 0x78;
LAB_002825b8:
        if (uVar44 != uVar34 * -0x28 - 0x10a5e0 >> 3) {
          if (uVar44 == 0) {
            lVar20 = of_find_property(param_2,"qcom,mdss-dsi-hbm-fod",0);
            *(bool *)((long)puVar15 + 0xb21) = lVar20 != 0;
            pcVar17 = (char *)of_get_property(param_2,"qcom,mdss-dsi-hbm-type",0);
            if (pcVar17 == (char *)0x0) {
LAB_00282654:
              uVar41 = 0;
            }
            else {
              iVar12 = strcmp(pcVar17,"lcd-dcs-wled");
              if (iVar12 == 0) {
                uVar41 = 1;
              }
              else {
                iVar12 = strcmp(pcVar17,"lcd-dcs-only");
                if (iVar12 == 0) {
                  uVar41 = 2;
                }
                else {
                  iVar12 = strcmp(pcVar17,"lcd-wled-only");
                  if (iVar12 == 0) {
                    uVar41 = 3;
                  }
                  else {
                    iVar12 = strcmp(pcVar17,"lcd-dcs-gpio");
                    if (iVar12 != 0) goto LAB_00282654;
                    uVar41 = 4;
                  }
                }
              }
            }
            *(undefined4 *)((long)puVar15 + 0xb24) = uVar41;
            *(undefined4 *)(puVar15 + 0x165) = *(undefined4 *)(puVar15 + 0xb6);
          }
          uVar27 = uVar44 * 0x18 + lVar19;
          if (uVar27 - 0xdf < 0xffffffffffffff11) goto LAB_002829d8;
          uVar46 = (lVar19 + uVar44 * 0x18) - 0xdf;
          if (uVar46 < 0xffffffffffffff11) goto LAB_002829d8;
          puVar3 = (ushort *)(&DAT_0031f1b0 + uVar34 * 0x78 + uVar44 * 0x18);
          uVar43 = lVar19 + uVar44 * 0x18;
          ppuVar4 = &dsi_panel_param + uVar34 * 0xf + uVar44 * 3;
          if (*puVar3 != 0) {
            if ((0xffffffffffffff16 < uVar27 - 0xe1) &&
               (uVar45 = (lVar19 + uVar44 * 0x18) - 0xe1, 0xffffffffffffff16 < uVar45)) {
              lVar20 = 0;
              iVar12 = -0x16;
              do {
                puVar42 = (&PTR_hbm_map_0031f1a8)[uVar44 * 3 + uVar34 * 0xf];
                plVar40 = (long *)(puVar42 + lVar20 * 0x10 + 8);
                *plVar40 = 0;
                if (uVar46 < 0xffffffffffffff11) break;
                lVar21 = __kmalloc((ulong)*puVar3 * 0x18,0xdc0);
                if (lVar21 == 0) goto LAB_00282a30;
                *plVar40 = lVar21;
                uVar13 = *(uint *)(puVar42 + lVar20 * 0x10 + 4);
                if (0x3d < uVar13) goto LAB_00284cc8;
                if ((&cmd_set_prop_map)[uVar13] == (undefined *)0x0) {
                  if (uVar46 < 0xffffffffffffff11) break;
                  uVar7 = *puVar3;
joined_r0x00282804:
                  if ((uVar7 == 0) || ((ulong)uVar7 <= lVar20 + 1U)) goto LAB_0028282c;
                }
                else {
                  if ((uVar13 == 0x1a) && (*(char *)((long)puVar15 + 0xb21) == '\0')) {
                    if (0xffffffffffffff10 < uVar46) {
                      uVar7 = *puVar3 - 1;
                      *puVar3 = uVar7;
                      goto joined_r0x00282804;
                    }
                    break;
                  }
                  iVar12 = dsi_panel_parse_cmd_sets_sub(puVar15,lVar21,(ulong)uVar13,__dest);
                  if (iVar12 != 0) {
                    if ((0xe8 < uVar27) || (0xe8 < uVar43)) break;
                    _printk(&DAT_002b0408,*ppuVar4);
                    goto LAB_002828e4;
                  }
                  if (uVar46 < 0xffffffffffffff11) break;
                  if (((ulong)*puVar3 == 0) || ((ulong)*puVar3 <= lVar20 + 1U)) goto LAB_00282830;
                  iVar12 = 0;
                }
                lVar20 = lVar20 + 1;
                if (uVar45 < 0xffffffffffffff17) break;
              } while( true );
            }
            goto LAB_002829d8;
          }
          goto LAB_002828e4;
        }
        _printk(&DAT_002d47cb);
        goto LAB_00282a30;
      }
    }
LAB_00284cc8:
                    /* WARNING: Does not return */
    pcVar25 = (code *)SoftwareBreakpoint(0x5512,0x284ccc);
    (*pcVar25)();
  }
  puVar15 = (undefined8 *)0xfffffffffffffff4;
  goto LAB_00282adc;
LAB_0028282c:
  if (iVar12 == 0) {
LAB_00282830:
    if ((uVar27 - 0xdb < 0xffffffffffffff0f) ||
       ((((lVar19 + uVar44 * 0x18) - 0xdb < 0xffffffffffffff0f ||
         ((&DAT_0031f1b6)[uVar34 * 0x78 + uVar44 * 0x18] = 1, 0xe8 < uVar27)) || (0xe8 < uVar43))))
    goto LAB_002829d8;
    drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: %s: feature enabled.\n",*ppuVar4);
  }
  else {
LAB_002828e4:
    if (((uVar27 - 0xdb < 0xffffffffffffff0f) ||
        ((lVar19 + uVar44 * 0x18) - 0xdb < 0xffffffffffffff0f)) ||
       (((&DAT_0031f1b6)[uVar34 * 0x78 + uVar44 * 0x18] = 0, 0xe8 < uVar27 ||
        ((0xe8 < uVar43 || (_printk(&DAT_002c5e4b,*ppuVar4), uVar46 < 0xffffffffffffff11)))))) {
LAB_002829d8:
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(1,0x2829dc);
      (*pcVar25)();
    }
    uVar27 = (ulong)*puVar3;
    if (*puVar3 != 0) {
      uVar43 = 0;
      lVar20 = 8;
      uVar45 = (lVar19 + uVar44 * 0x18) - 0xe1;
      do {
        if (uVar45 < 0xffffffffffffff17) goto LAB_002829d8;
        if (*(long *)((&PTR_hbm_map_0031f1a8)[uVar44 * 3 + uVar34 * 0xf] + lVar20) != 0) {
          kfree();
          if ((uVar45 < 0xffffffffffffff17) ||
             (*(undefined8 *)((&PTR_hbm_map_0031f1a8)[uVar44 * 3 + uVar34 * 0xf] + lVar20) = 0,
             uVar46 < 0xffffffffffffff11)) goto LAB_002829d8;
          uVar27 = (ulong)*puVar3;
        }
        uVar43 = uVar43 + 1;
        lVar20 = lVar20 + 0x10;
      } while (uVar43 < uVar27);
    }
  }
  uVar44 = uVar44 + 1;
  if (uVar44 == 5) goto LAB_00282a0c;
  goto LAB_002825b8;
LAB_00282a0c:
  lVar19 = of_find_property(param_2,"qcom,mdss-dsi-hbm-fod",0);
  *(bool *)((long)puVar15 + 0xb21) = lVar19 != 0;
LAB_00282a30:
  uStack_70._0_4_ = 0;
  uVar18 = *puVar15;
  if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
    pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282a68);
    (*pcVar25)();
  }
  iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-bpp",&uStack_70);
  if (iVar12 == 0) {
    *(char *)((long)puVar15 + 0x471) = (char)(uint)uStack_70;
    uVar41 = 4;
    switch((uint)uStack_70) {
    case 3:
      break;
    default:
      uVar41 = 3;
      break;
    case 8:
      uVar41 = 5;
      break;
    case 0xc:
      uVar41 = 6;
      break;
    case 0x10:
      uVar41 = 0;
      break;
    case 0x12:
      if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282b94);
        (*pcVar25)();
      }
      pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-pixel-packing",0);
      uVar41 = 1;
      if (pcVar17 != (char *)0x0) {
        iVar12 = strcmp(pcVar17,"loose");
        uVar41 = 1;
        if (iVar12 == 0) {
          uVar41 = 2;
        }
      }
      break;
    case 0x1e:
      uVar41 = 7;
    }
    *(undefined4 *)(puVar15 + 0x8d) = uVar41;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282be8);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-bpp-switch");
    uVar18 = *puVar15;
    *(byte *)((long)puVar15 + 0x472) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x282c20);
      (*pcVar25)();
    }
    uVar13 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-lane-0-state");
    *(uint *)((long)puVar15 + 0x46c) = *(uint *)((long)puVar15 + 0x46c) | uVar13 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x282c5c);
      (*pcVar25)();
    }
    uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-lane-1-state");
    uVar13 = 2;
    if ((uVar44 & 1) == 0) {
      uVar13 = 0;
    }
    *(uint *)((long)puVar15 + 0x46c) = *(uint *)((long)puVar15 + 0x46c) | uVar13;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x282ca0);
      (*pcVar25)();
    }
    uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-lane-2-state");
    uVar13 = 4;
    if ((uVar44 & 1) == 0) {
      uVar13 = 0;
    }
    *(uint *)((long)puVar15 + 0x46c) = *(uint *)((long)puVar15 + 0x46c) | uVar13;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x282ce4);
      (*pcVar25)();
    }
    uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-lane-3-state");
    uVar32 = *(uint *)((long)puVar15 + 0x46c);
    uVar13 = 8;
    if ((uVar44 & 1) == 0) {
      uVar13 = 0;
    }
    *(uint *)((long)puVar15 + 0x46c) = uVar32 | uVar13;
    *(byte *)(puVar15 + 0x8e) =
         ((byte)(uVar32 >> 1) & 1) + ((byte)uVar32 & 1) + ((byte)(uVar32 >> 2) & 1) +
         (char)((uVar32 & 8 | uVar13) >> 3);
    if ((uVar32 | uVar13) == 0) {
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: [%s] No data lanes are enabled, rc=%d\n",uVar18,0);
      uVar18 = *puVar15;
      pcVar17 = "*ERROR* [msm-dsi-error]: [%s] failed to parse lane states, rc=%d\n";
LAB_00282e30:
      iVar12 = -0x16;
      goto LAB_00282ab0;
    }
    uVar18 = *puVar15;
    if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282d54);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-color-order",0);
    if (pcVar17 == (char *)0x0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Falling back to default color order\n",uVar18);
      uVar41 = 0;
    }
    else {
      iVar12 = strcmp(pcVar17,"rgb_swap_rgb");
      if (iVar12 == 0) {
        uVar41 = 0;
      }
      else {
        iVar12 = strcmp(pcVar17,"rgb_swap_rbg");
        if (iVar12 == 0) {
          uVar41 = 1;
        }
        else {
          iVar12 = strcmp(pcVar17,"rgb_swap_brg");
          if (iVar12 == 0) {
            uVar41 = 3;
          }
          else {
            iVar12 = strcmp(pcVar17,"rgb_swap_grb");
            if (iVar12 == 0) {
              uVar41 = 4;
            }
            else {
              iVar12 = strcmp(pcVar17,"rgb_swap_gbr");
              if (iVar12 != 0) {
                drm_dev_printk(0,&DAT_002b5e64,
                               "*ERROR* [msm-dsi-error]: [%s] Unrecognized color order-%s\n",uVar18,
                               pcVar17);
                uVar18 = *puVar15;
                *(undefined2 *)((long)puVar15 + 0x48c) = 0;
                *(undefined1 *)((long)puVar15 + 0x48e) = 0;
                pcVar17 = "*ERROR* [msm-dsi-error]: [%s] failed to parse color swap config, rc=%d\n"
                ;
                goto LAB_00282e30;
              }
              uVar41 = 5;
            }
          }
        }
      }
    }
    uVar18 = *puVar15;
    *(undefined4 *)(puVar15 + 0x91) = uVar41;
    *(undefined2 *)((long)puVar15 + 0x48c) = 0;
    *(undefined1 *)((long)puVar15 + 0x48e) = 0;
    if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x282ec8);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-mdp-trigger",0);
    if (pcVar17 == (char *)0x0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Falling back to default MDP trigger\n",uVar18);
LAB_00282f5c:
      uVar41 = 3;
LAB_00282f78:
      *(undefined4 *)((long)puVar15 + 0x47c) = uVar41;
    }
    else {
      iVar12 = strcmp(pcVar17,"none");
      if (iVar12 != 0) {
        iVar12 = strcmp(pcVar17,"trigger_te");
        if (iVar12 == 0) {
          uVar41 = 1;
        }
        else {
          iVar12 = strcmp(pcVar17,"trigger_sw");
          if (iVar12 == 0) goto LAB_00282f5c;
          iVar12 = strcmp(pcVar17,"trigger_sw_te");
          if (iVar12 != 0) {
            drm_dev_printk(0,&DAT_002b5e64,
                           "*ERROR* [msm-dsi-error]: [%s] Unrecognized mdp trigger type (%s)\n",
                           uVar18,pcVar17);
            goto LAB_00282f7c;
          }
          uVar41 = 5;
        }
        goto LAB_00282f78;
      }
      *(undefined4 *)((long)puVar15 + 0x47c) = 0;
    }
LAB_00282f7c:
    if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x282fa8);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-dma-trigger",0);
    if (pcVar17 == (char *)0x0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Falling back to default MDP trigger\n",uVar18);
LAB_00283050:
      uVar41 = 3;
LAB_00283074:
      *(undefined4 *)(puVar15 + 0x90) = uVar41;
    }
    else {
      iVar12 = strcmp(pcVar17,"none");
      if (iVar12 != 0) {
        iVar12 = strcmp(pcVar17,"trigger_te");
        if (iVar12 == 0) {
          uVar41 = 1;
        }
        else {
          iVar12 = strcmp(pcVar17,"trigger_sw");
          if (iVar12 == 0) goto LAB_00283050;
          iVar12 = strcmp(pcVar17,"trigger_sw_seof");
          if (iVar12 == 0) {
            uVar41 = 4;
          }
          else {
            iVar12 = strcmp(pcVar17,"trigger_sw_te");
            if (iVar12 != 0) {
              drm_dev_printk(0,&DAT_002b5e64,
                             "*ERROR* [msm-dsi-error]: [%s] Unrecognized mdp trigger type (%s)\n",
                             uVar18,pcVar17);
              goto LAB_00283078;
            }
            uVar41 = 5;
          }
        }
        goto LAB_00283074;
      }
      *(undefined4 *)(puVar15 + 0x90) = 0;
    }
LAB_00283078:
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2830a8);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-te-pin-select",puVar15 + 0x8f);
    if (iVar12 != 0) {
      _printk(&DAT_002d4838,uVar18);
      *(undefined4 *)(puVar15 + 0x8f) = 1;
    }
    uVar18 = *puVar15;
    local_74 = 0;
    uStack_70._0_4_ = 0;
    local_80 = (size_t *)((ulong)local_80._4_4_ << 0x20);
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2830e8);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-t-clk-post",&uStack_70);
    if (iVar12 == 0) {
      *(uint *)(puVar15 + 0x92) = (uint)uStack_70;
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] t_clk_post = %d\n",uVar18);
    }
    uStack_70._0_4_ = 0;
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283144);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-t-clk-pre",&uStack_70);
    if (iVar12 == 0) {
      *(uint *)((long)puVar15 + 0x494) = (uint)uStack_70;
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] t_clk_pre = %d\n",uVar18);
    }
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283198);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-rx-eot-ignore");
    *(byte *)(puVar15 + 0x93) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2831cc);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-tx-eot-append");
    *(byte *)((long)puVar15 + 0x499) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283200);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-ext-bridge-mode");
    *(byte *)((long)puVar15 + 0x49a) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283234);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-force-clock-lane-hs");
    *(byte *)((long)puVar15 + 0x49b) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283268);
      (*pcVar25)();
    }
    uVar13 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,panel-cphy-mode");
    *(uint *)((long)puVar15 + 0x49c) = uVar13 & 1;
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2832a0);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-dma-schedule-line",&local_80);
    uVar41 = (int)local_80;
    if (iVar12 != 0) {
      uVar41 = 0;
    }
    *(undefined4 *)(puVar15 + 0x97) = uVar41;
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x2832e0);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-dma-schedule-window",&local_74)
    ;
    uVar41 = local_74;
    if (iVar12 != 0) {
      uVar41 = 0;
    }
    *(undefined4 *)((long)puVar15 + 0x4bc) = uVar41;
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283324);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,vert-padding-value",puVar15 + 0x98);
    bVar9 = false;
    if (iVar12 == 0) {
      bVar9 = *(int *)(puVar15 + 0x98) != 0;
    }
    *(bool *)((long)puVar15 + 0x4c4) = bVar9;
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] DMA scheduling parameters Line: %d Window: %d\n",
                  uVar18,*(undefined4 *)(puVar15 + 0x97),*(undefined4 *)((long)puVar15 + 0x4bc));
    uVar18 = *puVar15;
    uStack_70._0_4_ = 0;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283394);
      (*pcVar25)();
    }
    uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,split-link-enabled");
    if ((uVar44 & 1) == 0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Split link is not supported\n",uVar18);
      uVar23 = 0;
    }
    else {
      if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2833c8);
        (*pcVar25)();
      }
      iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,sublinks-count",&uStack_70);
      if ((iVar12 != 0) || (uVar13 = (uint)uStack_70, (uint)uStack_70 == 0)) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Using default sublinks count\n",uVar18);
        uVar13 = 2;
      }
      *(uint *)((long)puVar15 + 0x4a4) = uVar13;
      if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283428);
        (*pcVar25)();
      }
      iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,lanes-per-sublink",&uStack_70);
      if ((iVar12 != 0) || (uVar13 = (uint)uStack_70, (uint)uStack_70 == 0)) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Using default lanes per sublink\n",uVar18);
        uVar13 = 2;
      }
      *(uint *)(puVar15 + 0x95) = uVar13;
      if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283484);
        (*pcVar25)();
      }
      uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,split-link-sublink-swap");
      if ((uVar44 & 1) == 0) {
        *(undefined1 *)((long)puVar15 + 0x4a1) = 0;
      }
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Split link is supported %d-%d\n",uVar18,
                    *(undefined4 *)((long)puVar15 + 0x4a4),*(undefined4 *)(puVar15 + 0x95));
      uVar23 = 1;
    }
    *(undefined1 *)(puVar15 + 0x94) = uVar23;
    if (*(char *)((long)puVar15 + 0x8bd) != '\0') {
      pcVar17 = (char *)puVar15[1];
      local_80 = (size_t *)0x0;
      iVar12 = strcmp(pcVar17,"primary");
      if (iVar12 == 0) {
        pcVar17 = "dsi_calib_data";
LAB_0028352c:
        iVar12 = firmware_request_nowarn(&local_80,pcVar17,puVar15[0x8c]);
        if (iVar12 == 0) {
          drm_dev_printk(0,&DAT_002cdc0f,
                         "[msm-dsi-info]: found calibration data for %s display, size: %llu\n",
                         puVar15[1],*local_80);
          uVar44 = *local_80;
          pcVar17 = (char *)kvmalloc_node(uVar44,0xdc0,0xffffffff);
          if (pcVar17 == (char *)0x0) {
            drm_dev_printk(0,&DAT_002b5e64,
                           "*ERROR* [msm-dsi-error]: failed to allocated memory for %s display calib data\n"
                           ,puVar15[1]);
            iVar12 = -0xc;
          }
          else {
            memcpy(pcVar17,(void *)local_80[1],*local_80);
            uStack_70._0_4_ = (uint)pcVar17;
            uStack_70._4_4_ = (undefined4)((ulong)pcVar17 >> 0x20);
            if (uVar44 == 0) {
              iVar12 = -0x16;
            }
            else {
              puVar15[0x13f] = 0;
              lVar19 = kvmalloc_node(uVar44 / 3 + 1,0xdc0,0xffffffff);
              puVar15[0x13e] = lVar19;
              if (lVar19 == 0) {
                drm_dev_printk(0,&DAT_002b5e64,
                               "*ERROR* [msm-dsi-error]: failed to allocated memory for display %s calibration data\n"
                               ,puVar15[1]);
                iVar12 = -0xc;
              }
              else {
                pcVar16 = pcVar17;
                do {
                  while( true ) {
                    if (*pcVar16 == '\0') goto LAB_00283644;
                    local_74 = 0;
                    if (*pcVar16 == '#') break;
                    pcVar16 = strsep((char **)&uStack_70,"\n");
                    iVar12 = kstrtoint(pcVar16,0x10,&local_74);
                    if (iVar12 != 0) {
                      drm_dev_printk(0,&DAT_002b5e64,
                                     "*ERROR* [msm-dsi-error]: Error converting %s: %d, aborting calibration data\n"
                                     ,iVar12,pcVar16);
                      kvfree(puVar15[0x13e]);
                      puVar15[0x13e] = 0;
                      puVar15[0x13f] = 0;
                      goto LAB_002836c0;
                    }
                    lVar19 = puVar15[0x13f];
                    puVar15[0x13f] = lVar19 + 1;
                    *(char *)(puVar15[0x13e] + lVar19) = (char)local_74;
                    pcVar16 = (char *)CONCAT44(uStack_70._4_4_,(uint)uStack_70);
                    if (pcVar16 == (char *)0x0) goto LAB_00283644;
                  }
                  pcVar22 = strchr(pcVar16,10);
                  pcVar16 = (char *)0x0;
                  if (pcVar22 != (char *)0x0) {
                    pcVar16 = pcVar22 + 1;
                  }
                  uStack_70._0_4_ = (uint)pcVar16;
                  uStack_70._4_4_ = (undefined4)((ulong)pcVar16 >> 0x20);
                } while (pcVar16 != (char *)0x0);
LAB_00283644:
                iVar12 = 0;
              }
            }
LAB_002836c0:
            kvfree(pcVar17);
            release_firmware(local_80);
            if (iVar12 == 0) {
              drm_dev_printk(0,&DAT_002cdc0f,
                             "[msm-dsi-info]: calibration data loaded for: %s display\n",puVar15[1])
              ;
              goto LAB_002836f0;
            }
          }
        }
      }
      else {
        iVar12 = strcmp(pcVar17,"secondary");
        if (iVar12 == 0) {
          pcVar17 = "dsi_calib_data_sec";
          goto LAB_0028352c;
        }
        iVar12 = -2;
      }
      _printk(&DAT_002fd1b7,puVar15[1],iVar12);
    }
LAB_002836f0:
    if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x28371c);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-panel-type",0);
    if (pcVar17 != (char *)0x0) {
      iVar12 = strcmp(pcVar17,"dsi_video_mode");
      if (iVar12 == 0) goto LAB_0028378c;
      iVar12 = strcmp(pcVar17,"dsi_cmd_mode");
      if (iVar12 == 0) {
        bVar9 = false;
        uVar41 = 2;
        bVar8 = true;
        goto LAB_00283798;
      }
      drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: [%s] Unrecognized panel type-%s\n",
                     *puVar15,pcVar17);
      iVar12 = -0x16;
LAB_00283d80:
      pcVar17 = "*ERROR* [msm-dsi-error]: failed to parse panel mode configuration, rc=%d\n";
      goto LAB_00282acc;
    }
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Fallback to default panel mode\n",*puVar15);
LAB_0028378c:
    bVar8 = false;
    bVar9 = true;
    uVar41 = 1;
LAB_00283798:
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2837c0);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-panel-mode-switch");
    pcVar17 = "enabled";
    if ((bVar10 & 1) == 0) {
      pcVar17 = "disabled";
    }
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: %s: panel operating mode switch feature %s\n",
                  "dsi_panel_parse_panel_mode",pcVar17);
    if ((bVar9) || ((bVar10 & 1) != 0)) {
      uVar18 = *puVar15;
      uStack_70._0_4_ = 0;
      local_80 = (size_t *)((ulong)local_80 & 0xffffffff00000000);
      if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2838a8);
        (*pcVar25)();
      }
      iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-h-sync-pulse",&local_80);
      if (iVar12 == 0) {
        uVar23 = SUB81(local_80,0);
        if (((int)local_80 == 1) || ((int)local_80 == 0)) goto LAB_002838d0;
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] Unrecognized value for mdss-dsi-h-sync-pulse\n"
                       ,uVar18);
LAB_00283adc:
        iVar12 = -0x16;
      }
      else {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] fallback to default h-sync-pulse\n",uVar18);
        uVar23 = 0;
LAB_002838d0:
        *(undefined1 *)((long)puVar15 + 0x4c9) = uVar23;
        if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x2838fc);
          (*pcVar25)();
        }
        bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-hfp-power-mode");
        *(byte *)((long)puVar15 + 0x4ca) = bVar11 & 1;
        if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283930);
          (*pcVar25)();
        }
        bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-hbp-power-mode");
        *(byte *)((long)puVar15 + 0x4cb) = bVar11 & 1;
        if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283964);
          (*pcVar25)();
        }
        bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-hsa-power-mode");
        *(byte *)((long)puVar15 + 0x4cc) = bVar11 & 1;
        if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283998);
          (*pcVar25)();
        }
        bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-last-line-interleave");
        *(byte *)(puVar15 + 0x99) = bVar11 & 1;
        if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2839cc);
          (*pcVar25)();
        }
        bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-bllp-eof-power-mode");
        *(byte *)((long)puVar15 + 0x4cd) = bVar11 & 1;
        if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283a00);
          (*pcVar25)();
        }
        bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-bllp-power-mode");
        *(byte *)((long)puVar15 + 0x4ce) = bVar11 & 1;
        if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283a38);
          (*pcVar25)();
        }
        pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-traffic-mode",0);
        if (pcVar17 == (char *)0x0) {
          __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Falling back to default traffic mode\n",uVar18)
          ;
          uVar24 = 0;
        }
        else {
          iVar12 = strcmp(pcVar17,"non_burst_sync_pulse");
          if (iVar12 == 0) {
            uVar24 = 0;
          }
          else {
            iVar12 = strcmp(pcVar17,"non_burst_sync_event");
            if (iVar12 == 0) {
              uVar24 = 1;
            }
            else {
              iVar12 = strcmp(pcVar17,"burst_mode");
              if (iVar12 != 0) {
                drm_dev_printk(0,&DAT_002b5e64,
                               "*ERROR* [msm-dsi-error]: [%s] Unrecognized traffic mode-%s\n",uVar18
                               ,pcVar17);
                goto LAB_00283adc;
              }
              uVar24 = 2;
            }
          }
        }
        *(undefined4 *)(puVar15 + 0x9a) = uVar24;
        if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283d34);
          (*pcVar25)();
        }
        iVar12 = (*(code *)puVar15[0x109])
                           (puVar15[0x105],"qcom,mdss-dsi-virtual-channel-id",&uStack_70);
        if (iVar12 == 0) {
          *(uint *)((long)puVar15 + 0x4d4) = (uint)uStack_70;
          goto joined_r0x00283da0;
        }
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Fallback to default vc id\n",uVar18);
        *(undefined4 *)((long)puVar15 + 0x4d4) = 0;
      }
      uVar18 = *puVar15;
      pcVar17 = "*ERROR* [msm-dsi-error]: [%s] Failed to parse video host cfg, rc=%d\n";
LAB_00283d74:
      drm_dev_printk(0,&DAT_002b5e64,pcVar17,uVar18,iVar12);
      goto LAB_00283d80;
    }
joined_r0x00283da0:
    if (bVar8 || (bVar10 & 1) != 0) {
      uVar18 = *puVar15;
      uStack_70._0_4_ = 0;
      if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283844);
        (*pcVar25)();
      }
      iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-wr-mem-start",&uStack_70);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Fallback to default wr-mem-start\n",uVar18);
        uStack_70._0_4_ = 0x2c;
      }
      *(uint *)((long)puVar15 + 0x4dc) = (uint)uStack_70;
      uStack_70._0_4_ = 0;
      if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283b3c);
        (*pcVar25)();
      }
      iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-wr-mem-continue",&uStack_70);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Fallback to default wr-mem-continue\n",uVar18);
        uStack_70._0_4_ = 0x3c;
      }
      *(uint *)(puVar15 + 0x9c) = (uint)uStack_70;
      *(undefined4 *)(puVar15 + 0x9b) = 0;
      uStack_70._0_4_ = 0;
      if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283ba4);
        (*pcVar25)();
      }
      iVar12 = (*(code *)puVar15[0x109])(puVar15[0x105],"qcom,mdss-dsi-te-dcs-command",&uStack_70);
      if (iVar12 == 0) {
        uVar23 = (undefined1)(uint)uStack_70;
        if (((uint)uStack_70 == 1) || ((uint)uStack_70 == 0)) goto LAB_00283bd0;
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] Unrecognized value for mdss-dsi-te-dcs-command\n"
                       ,uVar18);
        iVar12 = -0x16;
LAB_00283ca4:
        uVar18 = *puVar15;
        pcVar17 = "*ERROR* [msm-dsi-error]: [%s] Failed to parse cmd host config, rc=%d\n";
        goto LAB_00283d74;
      }
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] fallback to default te-dcs-cmd\n",uVar18);
      uVar23 = 1;
LAB_00283bd0:
      *(undefined1 *)((long)puVar15 + 0x4e4) = uVar23;
      if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283bfc);
        (*pcVar25)();
      }
      bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-mdp-idle-ctrl-en");
      *(byte *)((long)puVar15 + 0x4e5) = bVar11 & 1;
      if ((bVar11 & 1) == 0) {
        if (iVar12 != 0) goto LAB_00283ca4;
      }
      else {
        uStack_70._0_4_ = 0;
        if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283c3c);
          (*pcVar25)();
        }
        iVar12 = (*(code *)puVar15[0x109])
                           (puVar15[0x105],"qcom,mdss-dsi-mdp-idle-ctrl-len",&uStack_70);
        if (iVar12 == 0) {
          *(uint *)(puVar15 + 0x9d) = (uint)uStack_70;
        }
        else {
          __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] mdp idle ctrl len is not defined\n",uVar18);
          *(undefined1 *)((long)puVar15 + 0x4e5) = 0;
          *(undefined4 *)(puVar15 + 0x9d) = 0;
        }
      }
    }
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283dcc);
      (*pcVar25)();
    }
    bVar11 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,poms-align-panel-vsync");
    *(undefined4 *)((long)puVar15 + 0x4ec) = uVar41;
    *(byte *)((long)puVar15 + 0x4f1) = bVar11 & 1;
    *(byte *)(puVar15 + 0x9e) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283e08);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,panel-ack-disabled");
    uVar18 = *puVar15;
    *(byte *)(puVar15 + 0x7e) = bVar10 & 1;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283e40);
      (*pcVar25)();
    }
    uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-pan-enable-dynamic-fps");
    if ((uVar44 & 1) == 0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] DFPS is not supported\n",uVar18);
      *(undefined1 *)((long)puVar15 + 0x514) = 0;
    }
    else {
      if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283e74);
        (*pcVar25)();
      }
      pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-pan-fps-update",0);
      if (pcVar17 == (char *)0x0) {
        pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps type not defined\n";
LAB_00284004:
        drm_dev_printk(0,&DAT_002b5e64,pcVar17,uVar18);
        uVar18 = 0xffffffea;
      }
      else {
        iVar12 = strcmp(pcVar17,"dfps_suspend_resume_mode");
        if (iVar12 == 0) {
          uVar41 = 1;
        }
        else {
          iVar12 = strcmp(pcVar17,"dfps_immediate_clk_mode");
          if (iVar12 == 0) {
            uVar41 = 2;
          }
          else {
            iVar12 = strcmp(pcVar17,"dfps_immediate_porch_mode_hfp");
            if (iVar12 == 0) {
              uVar41 = 3;
            }
            else {
              iVar12 = strcmp(pcVar17,"dfps_immediate_porch_mode_vfp");
              if (iVar12 == 0) {
                uVar41 = 4;
              }
              else {
                iVar12 = strcmp(pcVar17,"dfps_immediate_porch_mode_cus");
                if (iVar12 != 0) {
                  pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps type is not recognized\n";
                  goto LAB_00284004;
                }
                uVar41 = 5;
              }
            }
          }
        }
        *(undefined4 *)(puVar15 + 0x9f) = uVar41;
        if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
          pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x283f98);
          (*pcVar25)();
        }
        uVar13 = (*(code *)puVar15[0x113])(puVar15[0x105],"qcom,dsi-supported-dfps-list");
        *(uint *)(puVar15 + 0xa2) = uVar13;
        if (uVar13 == 0) {
          pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps refresh list not present\n";
          goto LAB_00284004;
        }
        lVar19 = __kmalloc((ulong)uVar13 << 2,0xdc0);
        puVar15[0xa1] = lVar19;
        if (lVar19 != 0) {
          if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
            pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x283fe8);
            (*pcVar25)();
          }
          iVar12 = (*(code *)puVar15[0x10c])
                             (puVar15[0x105],"qcom,dsi-supported-dfps-list",lVar19,
                              *(undefined4 *)(puVar15 + 0xa2));
          if (iVar12 == 0) {
            puVar31 = (uint *)puVar15[0xa1];
            *(undefined1 *)((long)puVar15 + 0x514) = 1;
            uVar13 = *puVar31;
            *(uint *)(puVar15 + 0xa0) = uVar13;
            uVar32 = *puVar31;
            *(uint *)((long)puVar15 + 0x4fc) = uVar32;
            if (1 < *(uint *)(puVar15 + 0xa2)) {
              lVar19 = (ulong)*(uint *)(puVar15 + 0xa2) - 1;
              do {
                puVar31 = puVar31 + 1;
                uVar5 = *puVar31;
                if (uVar5 < uVar32) {
                  *(uint *)((long)puVar15 + 0x4fc) = uVar5;
                  uVar32 = uVar5;
                }
                else {
                  if (uVar13 < uVar5) {
                    *(uint *)(puVar15 + 0xa0) = uVar5;
                    uVar13 = uVar5;
                  }
                }
                lVar19 = lVar19 + -1;
              } while (lVar19 != 0);
            }
            if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284918);
              (*pcVar25)();
            }
            bVar10 = (*(code *)puVar15[0x10b])
                               (puVar15[0x105],"qcom,mdss-dsi-pan-dfps-send-command-with-te-async");
            *(byte *)((long)puVar15 + 0x516) = bVar10 & 1;
            if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x28494c);
              (*pcVar25)();
            }
            bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,mdss-dsi-pan-dfps-send-command")
            ;
            *(byte *)((long)puVar15 + 0x515) = bVar10 & 1;
            if ((bVar10 & 1) != 0) {
              uVar41 = *(undefined4 *)puVar15[0xa1];
              *(undefined4 *)(puVar15 + 0xa3) = uVar41;
              *(undefined4 *)((long)puVar15 + 0x51c) = uVar41;
            }
            *(undefined1 *)((long)puVar15 + 0x517) = 0;
            if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284998);
              (*pcVar25)();
            }
            uVar13 = (*(code *)puVar15[0x113])
                               (puVar15[0x105],"qcom,dsi-supported-dfps-cmd-delay-effect-list");
            *(uint *)(puVar15 + 0xa9) = uVar13;
            if (0 < (int)uVar13) {
              lVar19 = __kmalloc((ulong)uVar13 << 2,0xdc0);
              puVar15[0xa8] = lVar19;
              if (lVar19 == 0) goto LAB_00284c1c;
              if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
                pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2849ec);
                (*pcVar25)();
              }
              iVar12 = (*(code *)puVar15[0x10c])
                                 (puVar15[0x105],"qcom,dsi-supported-dfps-cmd-delay-effect-list",
                                  lVar19,(long)*(int *)(puVar15 + 0xa9));
              if (iVar12 != 0) {
                pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps cmd delay effect list parse failed\n";
                goto LAB_00284004;
              }
              *(undefined1 *)((long)puVar15 + 0x517) = 1;
              drm_dev_printk(0,&DAT_002cdc0f,
                             "[msm-dsi-info]: [%s] dfps cmd delay effect list parse success\n",
                             uVar18);
            }
            if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284b00);
              (*pcVar25)();
            }
            uVar13 = (*(code *)puVar15[0x113])
                               (puVar15[0x105],"qcom,dsi-supported-dfps-update-wait-te-list");
            *(uint *)(puVar15 + 0xab) = uVar13;
            if (0 < (int)uVar13) {
              lVar19 = __kmalloc((ulong)uVar13 << 2,0xdc0);
              puVar15[0xaa] = lVar19;
              if (lVar19 == 0) goto LAB_00284c1c;
              if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
                pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284b54);
                (*pcVar25)();
              }
              iVar12 = (*(code *)puVar15[0x10c])
                                 (puVar15[0x105],"qcom,dsi-supported-dfps-update-wait-te-list",
                                  lVar19,(long)*(int *)(puVar15 + 0xab));
              if (iVar12 != 0) {
                pcVar17 = 
                "*ERROR* [msm-dsi-error]: [%s] failed to parse \'qcom,dsi-supported-dfps-update-wait-te-list\'\n"
                ;
                goto LAB_00284004;
              }
              drm_dev_printk(0,&DAT_002cdc0f,
                             "[msm-dsi-info]: [%s] dfps update check te list parse success\n",uVar18
                            );
            }
            if (*(int *)(puVar15 + 0x9f) != 5) goto LAB_00284034;
            if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284bb8);
              (*pcVar25)();
            }
            uVar13 = (*(code *)puVar15[0x113])(puVar15[0x105],"qcom,dsi-supported-dfps-vfp-list");
            *(uint *)(puVar15 + 0xa5) = uVar13;
            if (uVar13 == 0) {
              pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps refresh vfp list not present\n";
            }
            else {
              lVar19 = __kmalloc((ulong)uVar13 << 2,0xdc0);
              puVar15[0xa4] = lVar19;
              if (lVar19 == 0) goto LAB_00284c1c;
              if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
                pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284c08);
                (*pcVar25)();
              }
              iVar12 = (*(code *)puVar15[0x10c])
                                 (puVar15[0x105],"qcom,dsi-supported-dfps-vfp-list",lVar19,
                                  *(undefined4 *)(puVar15 + 0xa5));
              if (iVar12 == 0) {
                if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
                  pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284c58);
                  (*pcVar25)();
                }
                uVar13 = (*(code *)puVar15[0x113])
                                   (puVar15[0x105],"qcom,dsi-supported-dfps-hfp-list");
                *(uint *)(puVar15 + 0xa7) = uVar13;
                if (uVar13 == 0) {
                  pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps refresh hfp list not present\n";
                }
                else {
                  lVar19 = __kmalloc((ulong)uVar13 << 2,0xdc0);
                  puVar15[0xa6] = lVar19;
                  if (lVar19 == 0) {
                    uVar18 = 0xfffffff4;
                    goto LAB_0028401c;
                  }
                  if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
                    pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284cb0);
                    (*pcVar25)();
                  }
                  iVar12 = (*(code *)puVar15[0x10c])
                                     (puVar15[0x105],"qcom,dsi-supported-dfps-hfp-list",lVar19,
                                      *(undefined4 *)(puVar15 + 0xa7));
                  if (iVar12 == 0) goto LAB_00284034;
                  pcVar17 = 
                  "*ERROR* [msm-dsi-error]: [%s] dfps refresh rate hfp list parse failed\n";
                }
              }
              else {
                pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps refresh rate vfp list parse failed\n";
              }
            }
          }
          else {
            pcVar17 = "*ERROR* [msm-dsi-error]: [%s] dfps refresh rate list parse failed\n";
          }
          goto LAB_00284004;
        }
LAB_00284c1c:
        uVar18 = 0xfffffff4;
      }
LAB_0028401c:
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: failed to parse dfps configuration, rc=%d\n",uVar18);
    }
LAB_00284034:
    uVar18 = *puVar15;
    uStack_70._0_4_ = 0;
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284064);
      (*pcVar25)();
    }
    bVar10 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,qsync-enable");
    *(byte *)(puVar15 + 0x119) = bVar10 & 1;
    if ((bVar10 & 1) == 0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: qsync feature not enabled\n");
    }
    else {
      iVar14 = of_property_read_variable_u32_array
                         (param_2,"qcom,mdss-dsi-qsync-min-refresh-rate",&uStack_70,1,0);
      iVar12 = iVar14;
      if (-1 < iVar14) {
        iVar12 = 0;
      }
      if (iVar14 < 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] qsync min fps not defined rc:%d\n",*puVar15,
                      iVar12);
      }
      *(uint *)((long)puVar15 + 0x8cc) = (uint)uStack_70;
      if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x2840ec);
        (*pcVar25)();
      }
      uVar13 = (*(code *)puVar15[0x113])(puVar15[0x105],"qcom,dsi-supported-qsync-min-fps-list");
      *(uint *)(puVar15 + 0x11b) = uVar13;
      if ((int)uVar13 < 1) {
        *(undefined4 *)(puVar15 + 0x11b) = 0;
        cVar6 = *(char *)((long)puVar15 + 0x514);
joined_r0x00284134:
        if ((cVar6 != '\0') && (*(int *)(puVar15 + 0x9f) != 4)) {
          *(undefined1 *)(puVar15 + 0x119) = 0;
          *(undefined4 *)((long)puVar15 + 0x8cc) = 0;
        }
        if (-1 < iVar12) goto LAB_002841fc;
      }
      else {
        if (*(int *)((long)puVar15 + 0x8cc) == 0) {
          if (*(uint *)(puVar15 + 0xa2) == uVar13) {
            lVar19 = __kmalloc((ulong)uVar13 << 2,0xdc0);
            puVar15[0x11a] = lVar19;
            if (lVar19 == 0) {
              iVar12 = -0xc;
              goto LAB_002841d8;
            }
            if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2841a4);
              (*pcVar25)();
            }
            iVar12 = (*(code *)puVar15[0x10c])
                               (puVar15[0x105],"qcom,dsi-supported-qsync-min-fps-list",lVar19,
                                (long)*(int *)(puVar15 + 0x11b));
            if (iVar12 == 0) {
              puVar31 = (uint *)puVar15[0x11a];
              uVar13 = *puVar31;
              *(uint *)((long)puVar15 + 0x8cc) = uVar13;
              if (1 < *(uint *)(puVar15 + 0x11b)) {
                lVar19 = (ulong)*(uint *)(puVar15 + 0x11b) - 1;
                do {
                  puVar31 = puVar31 + 1;
                  uVar32 = *puVar31;
                  if (uVar32 < uVar13) {
                    *(uint *)((long)puVar15 + 0x8cc) = uVar32;
                    uVar13 = uVar32;
                  }
                  lVar19 = lVar19 + -1;
                } while (lVar19 != 0);
              }
              iVar12 = 0;
              cVar6 = *(char *)((long)puVar15 + 0x514);
              goto joined_r0x00284134;
            }
            pcVar17 = "*ERROR* [msm-dsi-error]: [%s] Qsync min fps list parse failed\n";
          }
          else {
            pcVar17 = "*ERROR* [msm-dsi-error]: [%s] Qsync min fps list mismatch with dfps\n";
          }
        }
        else {
          pcVar17 = "*ERROR* [msm-dsi-error]: [%s] Both qsync nodes are defined\n";
        }
        drm_dev_printk(0,&DAT_002b5e64,pcVar17,uVar18);
        iVar12 = -0x16;
      }
LAB_002841d8:
      *(undefined4 *)((long)puVar15 + 0x8cc) = 0;
      *(undefined4 *)(puVar15 + 0x11b) = 0;
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse qsync features, rc=%d\n",iVar12);
    }
LAB_002841fc:
    uStack_70._0_4_ = 0;
    iVar12 = of_property_read_variable_u32_array
                       (param_2,"qcom,dsi-qsync-avr-step-fps",&uStack_70,1,0);
    if (iVar12 < 0) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] avr step fps not defined rc:%d\n",*puVar15,iVar12);
    }
    *(uint *)(puVar15 + 0x11c) = (uint)uStack_70 & (iVar12 >> 0x1f ^ 0xffffffffU);
    if (*(int *)((code *)puVar15[0x113] + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x284278);
      (*pcVar25)();
    }
    uStack_70._0_4_ = (*(code *)puVar15[0x113])(puVar15[0x105],"qcom,dsi-qsync-avr-step-list");
    uVar44 = (ulong)(uint)uStack_70;
    if ((int)(uint)uStack_70 < 1) {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] optional avr step list not defined, val:%d\n",
                    *puVar15,uVar44);
    }
    else {
      if (((uint)uStack_70 == 1) || ((uint)uStack_70 == *(uint *)(puVar15 + 0xa2))) {
        if (*(int *)(puVar15 + 0x11c) == 0) {
          lVar19 = __kmalloc(uVar44 << 2,0xdc0);
          puVar15[0x11d] = lVar19;
          if (lVar19 == 0) {
            iVar12 = -0xc;
          }
          else {
            if (*(int *)((code *)puVar15[0x10c] + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
              pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x284334);
              (*pcVar25)();
            }
            iVar12 = (*(code *)puVar15[0x10c])
                               (puVar15[0x105],"qcom,dsi-qsync-avr-step-list",lVar19,
                                (long)(int)(uint)uStack_70);
            if (iVar12 == 0) {
              *(uint *)(puVar15 + 0x11e) = (uint)uStack_70;
              goto LAB_00284394;
            }
            kfree(puVar15[0x11d]);
          }
        }
        else {
          drm_dev_printk(0,&DAT_002b5e64,
                         "*ERROR* [msm-dsi-error]: [%s] both modes of avr-steps are defined\n",
                         *puVar15);
          iVar12 = -0x16;
        }
      }
      else {
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: [%s] avr step list size %d not same as dfps list %d\n"
                       ,*puVar15,uVar44);
        iVar12 = -0x16;
      }
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: failed to parse AVR features, rc=%d\n",iVar12);
    }
LAB_00284394:
    if (*(int *)((code *)puVar15[0x10b] + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2843bc);
      (*pcVar25)();
    }
    uVar44 = (*(code *)puVar15[0x10b])(puVar15[0x105],"qcom,dsi-dyn-clk-enable");
    if ((uVar44 & 1) == 0) {
      *(undefined1 *)(puVar15 + 0xac) = 0;
    }
    else {
      *(undefined1 *)(puVar15 + 0xac) = 1;
      if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
        pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x2843f8);
        (*pcVar25)();
      }
      pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,dsi-dyn-clk-type",0);
      if (pcVar17 == (char *)0x0) {
        *(undefined4 *)((long)puVar15 + 0x564) = 0;
        *(undefined1 *)(puVar15 + 0xad) = 0;
      }
      else {
        iVar12 = strcmp(pcVar17,"constant-fps-adjust-hfp");
        if (iVar12 == 0) {
          *(undefined4 *)((long)puVar15 + 0x564) = 1;
          *(undefined1 *)(puVar15 + 0xad) = 1;
        }
        else {
          iVar12 = strcmp(pcVar17,"constant-fps-adjust-vfp");
          if (iVar12 == 0) {
            *(undefined4 *)((long)puVar15 + 0x564) = 2;
            *(undefined1 *)(puVar15 + 0xad) = 1;
          }
          else {
            *(undefined4 *)((long)puVar15 + 0x564) = 0;
            *(undefined1 *)(puVar15 + 0xad) = 0;
          }
        }
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: Dynamic clock type is [%s]\n",pcVar17);
      }
    }
    uVar18 = *puVar15;
    uStack_70._0_4_ = 0;
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x2844b8);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])
                       (puVar15[0x105],"qcom,mdss-pan-physical-width-dimension",&uStack_70);
    if (iVar12 == 0) {
      uVar13 = (uint)uStack_70;
    }
    else {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Physical panel width is not defined\n",uVar18);
      uVar13 = 0;
    }
    *(uint *)((long)puVar15 + 0x56c) = uVar13;
    if (*(int *)((code *)puVar15[0x109] + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x284518);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x109])
                       (puVar15[0x105],"qcom,mdss-pan-physical-height-dimension",&uStack_70);
    if (iVar12 == 0) {
      uVar13 = (uint)uStack_70;
    }
    else {
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: [%s] Physical panel height is not defined\n",uVar18);
      uVar13 = 0;
    }
    *(uint *)(puVar15 + 0xae) = uVar13;
    if (*(int *)((code *)puVar15[0x107] + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x284578);
      (*pcVar25)();
    }
    pcVar17 = (char *)(*(code *)puVar15[0x107])(puVar15[0x105],"qcom,mdss-dsi-panel-orientation",0);
    if (pcVar17 != (char *)0x0) {
      iVar12 = strcmp(pcVar17,"180");
      if (iVar12 == 0) {
        uVar41 = 1;
        goto LAB_00284618;
      }
      iVar12 = strcmp(pcVar17,"hflip");
      if (iVar12 == 0) {
        uVar41 = 2;
        goto LAB_00284618;
      }
      iVar12 = strcmp(pcVar17,"vflip");
      if (iVar12 == 0) {
        uVar41 = 3;
        goto LAB_00284618;
      }
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: [%s] Unrecognized panel rotation-%s\n",uVar18,pcVar17
                    );
      pcVar17 = "*ERROR* [msm-dsi-error]: failed to parse panel physical dimension, rc=%d\n";
      iVar12 = -0x16;
      goto LAB_00282acc;
    }
    uVar41 = 0;
LAB_00284618:
    *(undefined4 *)((long)puVar15 + 0x574) = uVar41;
    if (*(int *)((code *)puVar15[0x13b] + -4) != -0x366e12b8) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8229,0x28463c);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x13b])(puVar15);
    if (iVar12 != 0) {
      pcVar17 = "*ERROR* [msm-dsi-error]: failed to parse panel gpios, rc=%d\n";
      goto LAB_00282acc;
    }
    if (*(int *)((code *)puVar15[0x13c] + -4) != -0x366e12b8) {
                    /* WARNING: Does not return */
      pcVar25 = (code *)SoftwareBreakpoint(0x8228,0x28467c);
      (*pcVar25)();
    }
    iVar12 = (*(code *)puVar15[0x13c])(puVar15);
    if (iVar12 != 0) {
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: failed to parse power config, rc=%d\n",iVar12);
    }
    iVar12 = dsi_panel_parse_bl_config(puVar15);
    if ((iVar12 == 0) ||
       (drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: failed to parse backlight config, rc=%d\n",iVar12),
       iVar12 != -0x205)) {
      dsi_panel_parse_misc_features(puVar15);
      iVar12 = dsi_panel_parse_hdr_config(puVar15);
      if (iVar12 != 0) {
        drm_dev_printk(0,&DAT_002b5e64,
                       "*ERROR* [msm-dsi-error]: failed to parse hdr config, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_get_mode_count(puVar15);
      if (iVar12 != 0) {
        pcVar17 = "*ERROR* [msm-dsi-error]: failed to get mode count, rc=%d\n";
        goto LAB_00282acc;
      }
      iVar12 = dsi_panel_parse_dms_info(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to get dms info, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_parse_esd_config(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse esd config, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_parse_local_hbm_config(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse local hbm config, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_parse_cellid_config(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse local cellid config, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_parse_pcd_config(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse pcd reg config, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_parse_apl_config(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse local apl config, rc=%d\n",iVar12);
      }
      iVar12 = dsi_panel_parse_od_config(puVar15);
      if (iVar12 != 0) {
        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: failed to parse local od config, rc=%d\n",iVar12);
      }
      dsi_panel_parse_aod_config(puVar15);
      iVar12 = dsi_panel_vreg_get(puVar15);
      if (iVar12 == 0) {
        *(undefined4 *)((long)puVar15 + 0x99c) = 5;
        drm_panel_init(puVar15 + 0x85,puVar15 + 4,0,0x10);
        puVar15[0x61] = param_2;
        drm_panel_add(puVar15 + 0x85);
        __mutex_init(puVar15 + 0x7f,"&panel->panel_lock",&dsi_panel_get___key);
        goto LAB_00282adc;
      }
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: [%s] failed to get panel regulators, rc=%d\n",
                     *puVar15,iVar12);
    }
    else {
      iVar12 = -0x205;
    }
  }
  else {
    drm_dev_printk(0,&DAT_002b5e64,
                   "*ERROR* [msm-dsi-error]: [%s] failed to read qcom,mdss-dsi-bpp, rc=%d\n",uVar18,
                   iVar12);
    uVar18 = *puVar15;
    pcVar17 = "*ERROR* [msm-dsi-error]: [%s] failed to get pixel format, rc=%d\n";
LAB_00282ab0:
    drm_dev_printk(0,&DAT_002b5e64,pcVar17,uVar18,iVar12);
    pcVar17 = "*ERROR* [msm-dsi-error]: failed to parse host configuration, rc=%d\n";
LAB_00282acc:
    drm_dev_printk(0,&DAT_002b5e64,pcVar17,iVar12);
  }
  kfree(puVar15);
  puVar15 = (undefined8 *)(long)iVar12;
LAB_00282adc:
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar15;
}



//------------------------------------------------------------
// dsi_panel_parse_esd_config @ 00285d48 size=608
// signature: undefined dsi_panel_parse_esd_config(void)
//------------------------------------------------------------

int dsi_panel_parse_esd_config(long param_1)

{
  long lVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = (char *)0x0;
  *(undefined4 *)(param_1 + 0x69c) = 6;
  if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x285da0);
    (*pcVar2)();
  }
  bVar3 = (**(code **)(param_1 + 0x858))(*(undefined8 *)(param_1 + 0x828),"qcom,esd-check-enabled");
  *(byte *)(param_1 + 0x698) = bVar3 & 1;
  if ((bVar3 & 1) == 0) {
LAB_00285eac:
    iVar4 = 0;
    goto LAB_00285eb0;
  }
  if (*(int *)(*(code **)(param_1 + 0x868) + -4) != -0x6abc71db) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x285ddc);
    (*pcVar2)();
  }
  iVar4 = (**(code **)(param_1 + 0x868))
                    (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-panel-status-check-mode",
                     &local_30);
  pcVar5 = local_30;
  if (iVar4 == 0) {
    iVar4 = strcmp(local_30,"bta_check");
    if (iVar4 == 0) {
      uVar6 = 2;
      pcVar5 = "bta_trigger";
      goto LAB_00285e90;
    }
    iVar4 = strcmp(pcVar5,"reg_read");
    if (iVar4 != 0) {
      iVar4 = strcmp(pcVar5,"te_chk_reg_rd");
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x4ec) == 2) {
          *(undefined4 *)(param_1 + 0x69c) = 1;
          iVar4 = dsi_panel_parse_esd_reg_read_configs(param_1);
          if (iVar4 != 0) goto LAB_00285f18;
          pcVar5 = "te_chk_reg_rd";
          goto LAB_00285e94;
        }
        pcVar5 = "*ERROR* [msm-dsi-error]: TE-CHK_REG_RD ESD not valid for video mode\n";
      }
      else {
        iVar4 = strcmp(pcVar5,"te_signal_check");
        if (iVar4 == 0) {
          if (*(int *)(param_1 + 0x4ec) == 2) {
            uVar6 = 3;
            pcVar5 = "te_check";
            goto LAB_00285e90;
          }
          pcVar5 = "*ERROR* [msm-dsi-error]: TE-ESD not valid for video mode\n";
        }
        else {
          iVar4 = strcmp(pcVar5,"esd_sw_sim_success");
          if (iVar4 == 0) {
            uVar6 = 4;
            pcVar5 = "sim_success";
LAB_00285e90:
            *(undefined4 *)(param_1 + 0x69c) = uVar6;
            goto LAB_00285e94;
          }
          pcVar5 = "*ERROR* [msm-dsi-error]: No valid panel-status-check-mode string\n";
        }
      }
      drm_dev_printk(0,&DAT_002b5e64,pcVar5);
      goto LAB_00285dfc;
    }
    *(undefined4 *)(param_1 + 0x69c) = 0;
    iVar4 = dsi_panel_parse_esd_reg_read_configs(param_1);
    if (iVar4 == 0) {
      pcVar5 = "register_read";
LAB_00285e94:
      __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: ESD enabled with mode: %s\n",pcVar5);
      goto LAB_00285eac;
    }
LAB_00285f18:
    drm_dev_printk(0,&DAT_002b5e64,
                   "*ERROR* [msm-dsi-error]: failed to parse esd reg read mode params, rc=%d\n",
                   iVar4);
  }
  else {
    __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: status check method not defined!\n");
LAB_00285dfc:
    iVar4 = -0x16;
  }
  *(undefined1 *)(param_1 + 0x698) = 0;
LAB_00285eb0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// dsi_panel_get_mode @ 00287de8 size=10296
// signature: undefined dsi_panel_get_mode(void)
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int dsi_panel_get_mode(long param_1,uint param_2,uint *param_3,uint param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  undefined8 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  char cVar14;
  ushort uVar15;
  bool bVar16;
  code *pcVar17;
  byte bVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  int iVar22;
  long lVar23;
  long lVar24;
  ulong uVar25;
  undefined4 *puVar26;
  undefined4 *puVar27;
  long lVar28;
  long lVar29;
  char *pcVar30;
  undefined1 uVar31;
  uint uVar32;
  uint uVar33;
  undefined8 uVar34;
  long lVar35;
  undefined4 *puVar36;
  uint uVar37;
  ulong uVar38;
  int local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar23 = sp_el0;
  local_70 = *(long *)(lVar23 + 0x638);
  if ((param_1 == 0) || (param_3 == (uint *)0x0)) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid params\n");
    iVar19 = -0x16;
    goto LAB_0028a5dc;
  }
  mutex_lock(param_1 + 0x3f8);
  puVar36 = *(undefined4 **)(param_3 + 0x2e);
  puVar1 = (undefined8 *)(param_1 + 0x828);
  if (*(int *)(*(code **)(param_1 + 0x878) + -4) != -0x1e7d0cec) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x287e6c);
    (*pcVar17)();
  }
  lVar23 = (**(code **)(param_1 + 0x878))
                     (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-display-timings");
  if (lVar23 == 0) {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: no display timing nodes defined\n");
LAB_00287fb8:
    uVar34 = 0;
    iVar19 = -0x16;
  }
  else {
    if (*(int *)(*(code **)(param_1 + 0x880) + -4) != 0x310e14dc) {
                    /* WARNING: Does not return */
      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x287e94);
      (*pcVar17)();
    }
    iVar19 = (**(code **)(param_1 + 0x880))();
    if ((iVar19 == 0) || (0x20 < iVar19)) {
      drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid count of timing nodes: %d\n")
      ;
      goto LAB_00287fb8;
    }
    uVar13 = *(undefined4 *)(param_1 + 0x4d0);
    uVar34 = *(undefined8 *)(param_1 + 0x828);
    if (*(int *)(*(code **)(param_1 + 0x890) + -4) != -0x11824650) {
                    /* WARNING: Does not return */
      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x287ed8);
      (*pcVar17)();
    }
    lVar24 = (**(code **)(param_1 + 0x890))(lVar23,0);
    if (lVar24 == 0) {
      iVar19 = 0;
    }
    else {
      iVar19 = 0;
      puVar2 = (undefined8 *)(param_1 + 0x848);
      puVar3 = param_3 + 0x10;
      puVar4 = param_3 + 6;
      puVar5 = param_3 + 7;
      puVar6 = param_3 + 9;
      puVar7 = param_3 + 8;
      uVar32 = 0;
      do {
        if (uVar32 == param_2) {
          *(long *)(param_1 + 0x828) = lVar24;
          if (*(char *)(param_1 + 0x4f0) == '\0') {
            uVar20 = *(uint *)(param_1 + 0x4ec);
LAB_00288110:
            param_3[0x28] = uVar20;
          }
          else if (*(long *)(param_3 + 0x2e) == 0) {
            drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid arguments\n");
LAB_00288138:
            param_3[0x28] = *(uint *)(param_1 + 0x4ec);
            drm_dev_printk(0,&DAT_002cdc0f,
                           "[msm-dsi-info]: panel mode isn\'t specified in timing[%d]\n",uVar32 + 1)
            ;
          }
          else {
            if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2880bc);
              (*pcVar17)();
            }
            uVar25 = (**(code **)(param_1 + 0x858))(lVar24,"qcom,mdss-dsi-video-mode");
            if ((uVar25 & 1) != 0) {
              param_3[0x28] = param_3[0x28] | 1;
            }
            if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2880f8);
              (*pcVar17)();
            }
            uVar25 = (**(code **)(param_1 + 0x858))
                               (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-cmd-mode");
            if ((uVar25 & 1) != 0) {
              uVar20 = param_3[0x28] | 2;
              goto LAB_00288110;
            }
            if (param_3[0x28] == 0) goto LAB_00288138;
          }
          if (*(char *)(param_1 + 0x472) == '\0') {
            uVar20 = *(uint *)(param_1 + 0x468);
LAB_002881e0:
            param_3[0x29] = uVar20;
            if (uVar20 < 8) {
              uVar20 = *(uint *)(&bits_per_pixel + (long)(int)uVar20 * 4);
            }
            else {
              uVar20 = 0x18;
            }
            param_3[0x2a] = uVar20;
            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288234);
              (*pcVar17)();
            }
            iVar19 = (*(code *)*puVar2)(*puVar1,"cell-index",param_3 + 0x2c);
            if (iVar19 != 0) {
              param_3[0x2c] = param_2;
            }
            lVar35 = *(long *)(param_3 + 0x2e);
            local_88 = 0;
            if (*(int *)(*(code **)(param_1 + 0x840) + -4) != 0x297cb585) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288274);
              (*pcVar17)();
            }
            iVar19 = (**(code **)(param_1 + 0x840))
                               (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-panel-clockrate",
                                &local_88);
            if (iVar19 == -0x4b) {
              local_88 = 0;
              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2882b0);
                (*pcVar17)();
              }
              iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-panel-clockrate",&local_88);
            }
            uVar25 = local_88;
            if (iVar19 != 0) {
              uVar25 = 0;
            }
            *(ulong *)(param_3 + 0xc) = uVar25;
            *(ulong *)(*(long *)(param_3 + 0x2e) + 0x600) = uVar25;
            param_3[0x18] = 1;
            param_3[0x19] = 1;
            *(undefined8 *)(*(long *)(param_3 + 0x2e) + 0x9d4) = 0x100000001;
            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288310);
              (*pcVar17)();
            }
            iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-mdp-transfer-time-us",puVar3);
            if (iVar19 != 0) {
              *puVar3 = 0;
            }
            puVar8 = (uint *)(lVar35 + 0x5ec);
            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28834c);
              (*pcVar17)();
            }
            iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-mdp-transfer-time-us-min",puVar8);
            if (iVar19 == 0) {
              if (*puVar3 < *puVar8) {
                *puVar3 = *puVar8;
              }
            }
            else {
              *puVar8 = 0;
            }
            puVar8 = (uint *)(lVar35 + 0x5f0);
            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2883a0);
              (*pcVar17)();
            }
            iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-mdp-transfer-time-us-max",puVar8);
            if (iVar19 == 0) {
              if (*puVar8 < *puVar3) {
                *puVar3 = *puVar8;
              }
            }
            else {
              *puVar8 = 0;
            }
            if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2883ec);
              (*pcVar17)();
            }
            bVar18 = (**(code **)(param_1 + 0x858))
                               (*(undefined8 *)(param_1 + 0x828),"qcom,disable-rsc-solver");
            *(byte *)(lVar35 + 0xa04) = bVar18 & 1;
            if (*(int *)(*(code **)(param_1 + 0x848) + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288428);
              (*pcVar17)();
            }
            iVar19 = (**(code **)(param_1 + 0x848))
                               (*(undefined8 *)(param_1 + 0x828),"qcom,mdss-dsi-panel-framerate",
                                param_3 + 0xb);
            if (iVar19 == 0) {
              uVar20 = param_3[0xb];
              uVar33 = 0;
              if (uVar20 != 0) {
                uVar33 = (uVar20 + 999999) / uVar20;
              }
              uVar20 = *puVar3;
              if (uVar33 < uVar20) {
                uVar20 = 0;
                *puVar3 = 0;
              }
              *(uint *)(lVar35 + 0x5e8) = uVar20;
              param_3[0x24] = 0x20;
              if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28848c);
                (*pcVar17)();
              }
              uVar25 = (**(code **)(param_1 + 0x858))
                                 (*(undefined8 *)(param_1 + 0x828),
                                  "qcom,framerate-group-no-duplicated");
              if ((uVar25 & 1) != 0) {
                param_3[0x24] = param_3[0x24] | 1;
              }
              if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2884c8);
                (*pcVar17)();
              }
              uVar25 = (**(code **)(param_1 + 0x858))
                                 (*(undefined8 *)(param_1 + 0x828),
                                  "qcom,framerate-group-120hz-based");
              if ((uVar25 & 1) != 0) {
                param_3[0x24] = param_3[0x24] | 2;
              }
              if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288504);
                (*pcVar17)();
              }
              uVar25 = (**(code **)(param_1 + 0x858))
                                 (*(undefined8 *)(param_1 + 0x828),"qcom,framerate-group-90hz-based"
                                 );
              if ((uVar25 & 1) != 0) {
                param_3[0x24] = param_3[0x24] | 4;
              }
              if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288540);
                (*pcVar17)();
              }
              uVar25 = (**(code **)(param_1 + 0x858))
                                 (*(undefined8 *)(param_1 + 0x828),
                                  "qcom,framerate-group-special-idle-1hz");
              if ((uVar25 & 1) != 0) {
                param_3[0x24] = param_3[0x24] | 8;
              }
              if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28857c);
                (*pcVar17)();
              }
              uVar25 = (**(code **)(param_1 + 0x858))
                                 (*(undefined8 *)(param_1 + 0x828),
                                  "qcom,framerate-group-special-idle-10hz");
              uVar20 = param_3[0x24] | 0x10;
              if ((uVar25 & 1) == 0) {
                uVar20 = param_3[0x24];
              }
              if (((uVar25 & 1) != 0) || (0x20 < uVar20)) {
                uVar33 = uVar20 & 0xffffffdf;
                if (uVar20 < 0x21) {
                  uVar33 = uVar20;
                }
                param_3[0x24] = uVar33;
              }
              if (*(int *)(*(code **)(param_1 + 0x858) + -4) != -0x75d5d1c9) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2885d4);
                (*pcVar17)();
              }
              uVar25 = (**(code **)(param_1 + 0x858))
                                 (*(undefined8 *)(param_1 + 0x828),
                                  "qcom,framerate-group-unrestricted");
              if ((uVar25 & 1) != 0) {
                param_3[0x24] = 0;
              }
              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28860c);
                (*pcVar17)();
              }
              iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-panel-width",param_3);
              if (iVar19 == 0) {
                if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288640);
                  (*pcVar17)();
                }
                iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-h-front-porch",param_3 + 3);
                if (iVar19 == 0) {
                  uVar25 = dsi_panel_is_gsi_mode();
                  if (((uVar25 & 1) != 0) && ((param_3[0x24] & 0x18) != 0)) {
                    param_3[3] = 0x20;
                  }
                  if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288694);
                    (*pcVar17)();
                  }
                  iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-h-back-porch",param_3 + 1);
                  if (iVar19 == 0) {
                    if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2886c8);
                      (*pcVar17)();
                    }
                    iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-h-pulse-width",param_3 + 2);
                    if (iVar19 == 0) {
                      if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2886fc);
                        (*pcVar17)();
                      }
                      iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-h-sync-skew",param_3 + 4);
                      if (iVar19 != 0) {
                        __drm_dev_dbg(0,0,0,
                                      "[msm-dsi-debug]: qcom,mdss-dsi-h-sync-skew is not defined, rc=%d\n"
                                      ,iVar19);
                      }
                      drm_dev_printk(0,&DAT_002cdc0f,
                                     "[msm-dsi-info]: panel horz active:%d front_portch:%d back_porch:%d sync_skew:%d, refreshrate:%d:0x%x\n"
                                     ,*param_3,param_3[3],param_3[1],param_3[2],param_3[0xb],
                                     param_3[0x24]);
                      if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288778);
                        (*pcVar17)();
                      }
                      iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-panel-height",puVar4);
                      if (iVar19 == 0) {
                        if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2887ac);
                          (*pcVar17)();
                        }
                        iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-v-back-porch",puVar5);
                        if (iVar19 == 0) {
                          if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2887e0);
                            (*pcVar17)();
                          }
                          iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-v-front-porch",puVar6);
                          if (iVar19 == 0) {
                            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288814);
                              (*pcVar17)();
                            }
                            iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-v-pulse-width",puVar7
                                                       );
                            if (iVar19 != 0) {
                              pcVar30 = 
                              "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-v-pulse-width, rc=%d\n"
                              ;
                              goto LAB_0028a284;
                            }
                            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288848);
                              (*pcVar17)();
                            }
                            iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,qsync-mode-min-refresh-rate",
                                                        param_3 + 0x22);
                            if (iVar19 != 0) {
                              __drm_dev_dbg(0,0,0,
                                            "[msm-dsi-debug]: qsync min fps not defined in timing node\n"
                                           );
                            }
                            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288894);
                              (*pcVar17)();
                            }
                            iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,dsi-qsync-mode-avr-step-fps",
                                                        param_3 + 0x23);
                            if (iVar19 != 0) {
                              __drm_dev_dbg(0,0,0,
                                            "[msm-dsi-debug]: avr step fps not defined in timing node\n"
                                           );
                            }
                            __drm_dev_dbg(0,0,0,
                                          "[msm-dsi-debug]: panel vert active:%d front_portch:%d back_porch:%d pulse_width:%d\n"
                                          ,*puVar4,*puVar6,*puVar5,*puVar7);
                            if (*(char *)(param_1 + 0x560) != '\0') {
                              lVar35 = *(long *)(param_3 + 0x2e);
                              if (lVar35 == 0) {
                                pcVar30 = "*ERROR* [msm-dsi-error]: invalid arguments\n";
LAB_0028896c:
                                drm_dev_printk(0,&DAT_002b5e64,pcVar30);
                                iVar19 = -0x16;
                              }
                              else {
                                if (*(int *)(*(code **)(param_1 + 0x898) + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
                                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288924);
                                  (*pcVar17)();
                                }
                                uVar20 = (**(code **)(param_1 + 0x898))
                                                   (*(undefined8 *)(param_1 + 0x828),
                                                    "qcom,dsi-dyn-clk-list");
                                *(uint *)(lVar35 + 0x610) = uVar20;
                                if (uVar20 - 0x65 < 0xffffff9c) {
                                  pcVar30 = 
                                  "*ERROR* [msm-dsi-error]: invalid number of bit clock values, must be between 1 and 100\n"
                                  ;
                                  goto LAB_0028896c;
                                }
                                lVar28 = __kmalloc((ulong)uVar20 << 2,0xdc0);
                                *(long *)(lVar35 + 0x618) = lVar28;
                                if (lVar28 == 0) {
                                  pcVar30 = 
                                  "*ERROR* [msm-dsi-error]: failed to allocate space for bit clock list\n"
                                  ;
LAB_00288a50:
                                  drm_dev_printk(0,&DAT_002b5e64,pcVar30);
                                  iVar19 = -0xc;
                                }
                                else {
                                  lVar28 = __kmalloc((ulong)*(uint *)(lVar35 + 0x610) << 2,0xdc0);
                                  *(long *)(lVar35 + 0x628) = lVar28;
                                  if (lVar28 == 0) {
                                    pcVar30 = 
                                    "*ERROR* [msm-dsi-error]: failed to allocate space for front porch list\n"
                                    ;
                                    goto LAB_00288a50;
                                  }
                                  lVar28 = __kmalloc((ulong)*(uint *)(lVar35 + 0x610) << 2,0xdc0);
                                  *(long *)(lVar35 + 0x630) = lVar28;
                                  if (lVar28 == 0) {
                                    pcVar30 = 
                                    "*ERROR* [msm-dsi-error]: failed to allocate space for pclk list\n"
                                    ;
                                    goto LAB_00288a50;
                                  }
                                  if (*(int *)(*(code **)(param_1 + 0x860) + -4) != -0x2eed9d8) {
                    /* WARNING: Does not return */
                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2889ec);
                                    (*pcVar17)();
                                  }
                                  iVar19 = (**(code **)(param_1 + 0x860))
                                                     (*(undefined8 *)(param_1 + 0x828),
                                                      "qcom,dsi-dyn-clk-list",
                                                      *(undefined8 *)(lVar35 + 0x618),
                                                      *(undefined4 *)(lVar35 + 0x610));
                                  if (iVar19 == 0) {
                                    if (*(int *)(lVar35 + 0x610) != 0) {
                                      uVar20 = 0;
                                      do {
                                        __drm_dev_dbg(0,0,0,"[msm-dsi-debug]: bit clk rate[%d]:%d\n"
                                                      ,uVar20,*(undefined4 *)
                                                               (*(long *)(lVar35 + 0x618) +
                                                               (long)(int)uVar20 * 4));
                                        uVar20 = uVar20 + 1;
                                      } while (uVar20 < *(uint *)(lVar35 + 0x610));
                                    }
                                    goto LAB_00288a94;
                                  }
                                  drm_dev_printk(0,&DAT_002b5e64,
                                                 "*ERROR* [msm-dsi-error]: failed to parse supported bit clk list values, rc=%d\n"
                                                 ,iVar19);
                                }
                                *(undefined4 *)(lVar35 + 0x610) = 0;
                                kfree(*(undefined8 *)(lVar35 + 0x618));
                                kfree(*(undefined8 *)(lVar35 + 0x628));
                                kfree(*(undefined8 *)(lVar35 + 0x630));
                              }
                              drm_dev_printk(0,&DAT_002b5e64,
                                             "*ERROR* [msm-dsi-error]: failed to parse dynamic clk rates, rc=%d\n"
                                             ,iVar19);
                            }
LAB_00288a94:
                            lVar35 = *(long *)(param_3 + 0x2e);
                            local_88 = local_88 & 0xffffffff00000000;
                            if (lVar35 == 0) {
LAB_0028a5ac:
                              iVar19 = -0x16;
                            }
                            else {
                              *(undefined1 *)(lVar35 + 0x9d0) = 0;
                              if (*(int *)(*(code **)(param_1 + 0x838) + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288ad0);
                                (*pcVar17)();
                              }
                              pcVar30 = (char *)(**(code **)(param_1 + 0x838))
                                                          (*(undefined8 *)(param_1 + 0x828),
                                                           "qcom,compression-mode",0);
                              if ((pcVar30 == (char *)0x0) ||
                                 (iVar19 = strcmp(pcVar30,"dsc"), iVar19 != 0)) {
                                if (*(char *)(lVar35 + 0x9d0) != '\0') goto LAB_00288b14;
                                __drm_dev_dbg(0,0,0,
                                              "[msm-dsi-debug]: dsc compression is not enabled for the mode\n"
                                             );
LAB_00288f68:
                                lVar35 = *(long *)(param_3 + 0x2e);
                                local_88 = local_88 & 0xffffffff00000000;
                                if (lVar35 == 0) {
LAB_0028a570:
                                  iVar19 = -0x16;
                                }
                                else {
                                  *(undefined1 *)(lVar35 + 0x9d1) = 0;
                                  if (*(int *)(*(code **)(param_1 + 0x838) + -4) != 0x5ba6584b) {
                    /* WARNING: Does not return */
                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288fa4);
                                    (*pcVar17)();
                                  }
                                  pcVar30 = (char *)(**(code **)(param_1 + 0x838))
                                                              (*(undefined8 *)(param_1 + 0x828),
                                                               "qcom,compression-mode",0);
                                  if ((pcVar30 == (char *)0x0) ||
                                     (iVar19 = strcmp(pcVar30,"vdc"), iVar19 != 0)) {
                                    if (*(char *)(lVar35 + 0x9d1) != '\0') goto LAB_00288fe8;
                                    __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: vdc compression is not enabled for the mode\n"
                                                 );
LAB_00289398:
                                    local_88 = local_88 & 0xffffffff00000000;
                                    if (*(int *)(*(code **)(param_1 + 0x898) + -4) != -0x19258d88) {
                    /* WARNING: Does not return */
                                      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2893c4);
                                      (*pcVar17)();
                                    }
                                    uVar20 = (**(code **)(param_1 + 0x898))
                                                       (*(undefined8 *)(param_1 + 0x828),
                                                        "qcom,display-topology");
                                    if ((((int)uVar20 < 1) || (0xf < uVar20)) || (uVar20 % 3 != 0))
                                    {
                                      iVar19 = -0x16;
                                      drm_dev_printk(0,&DAT_002b5e64,
                                                                                                          
                                                  "*ERROR* [msm-dsi-error]: invalid topology list for the panel, rc = %d\n"
                                                  ,0xffffffea);
                                    }
                                    else {
                                      puVar26 = (undefined4 *)__kmalloc((ulong)uVar20 << 2,0xdc0);
                                      if (puVar26 == (undefined4 *)0x0) {
                                        iVar19 = -0xc;
                                      }
                                      else {
                                        if (*(int *)(*(code **)(param_1 + 0x860) + -4) != -0x2eed9d8
                                           ) {
                    /* WARNING: Does not return */
                                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28943c);
                                          (*pcVar17)();
                                        }
                                        iVar19 = (**(code **)(param_1 + 0x860))
                                                           (*(undefined8 *)(param_1 + 0x828),
                                                            "qcom,display-topology",puVar26,uVar20);
                                        if (iVar19 == 0) {
                                          uVar25 = (ulong)uVar20 & 0xff;
                                          uVar38 = uVar25 / 3;
                                          puVar27 = (undefined4 *)__kmalloc(uVar38 << 4,0xdc0);
                                          if (puVar27 != (undefined4 *)0x0) {
                                            uVar33 = uVar20 & 0xff;
                                            uVar37 = (uint)uVar38;
                                            if (2 < uVar33) {
                                              uVar11 = uVar37;
                                              if ((uint)(uVar25 / 3) < 2) {
                                                uVar11 = 1;
                                              }
                                              *puVar27 = *puVar26;
                                              if ((((uVar20 < 2) || (uVar33 < 3)) ||
                                                  ((uVar20 < 2 ||
                                                   ((uVar33 < 3 ||
                                                    (puVar27[1] = puVar26[1], uVar20 < 3)))))) ||
                                                 ((uVar33 < 3 || ((uVar20 < 3 || (uVar33 < 3)))))) {
LAB_0028a61c:
                    /* WARNING: Does not return */
                                                pcVar17 = (code *)SoftwareBreakpoint(1,0x28a620);
                                                (*pcVar17)();
                                              }
                                              puVar27[2] = puVar26[2];
                                              if (5 < uVar33) {
                                                if ((((((uVar20 < 4) || (uVar33 - 3 < 3)) ||
                                                      (uVar20 < 4)) ||
                                                     ((uVar33 < 6 ||
                                                      (puVar27[4] = puVar26[3], uVar20 < 5)))) ||
                                                    (uVar33 < 6)) ||
                                                   (((uVar20 < 5 || (uVar33 < 6)) ||
                                                    ((puVar27[5] = puVar26[4], uVar20 < 6 ||
                                                     (((uVar33 < 6 || (uVar20 < 6)) || (uVar33 < 6))
                                                     )))))) goto LAB_0028a61c;
                                                puVar27[6] = puVar26[5];
                                                if (uVar11 != 2) {
                                                  if ((((uVar20 < 7) || (uVar33 - 6 < 3)) ||
                                                      ((uVar20 < 7 ||
                                                       ((uVar33 < 9 ||
                                                        (puVar27[8] = puVar26[6], uVar20 < 8))))))
                                                     || ((uVar33 < 9 ||
                                                         ((((uVar20 < 8 || (uVar33 < 9)) ||
                                                           (puVar27[9] = puVar26[7], uVar20 < 9)) ||
                                                          (((uVar33 < 9 || (uVar20 < 9)) ||
                                                           (uVar33 < 9)))))))) goto LAB_0028a61c;
                                                  puVar27[10] = puVar26[8];
                                                  if (uVar11 != 3) {
                                                    if (((uVar20 < 10) || (uVar33 - 9 < 3)) ||
                                                       (((((uVar20 < 10 ||
                                                           ((((uVar33 < 0xc ||
                                                              (puVar27[0xc] = puVar26[9],
                                                              uVar20 < 0xb)) || (uVar33 < 0xc)) ||
                                                            ((uVar20 < 0xb || (uVar33 < 0xc)))))) ||
                                                          (puVar27[0xd] = puVar26[10], uVar20 < 0xc)
                                                          ) || ((uVar33 < 0xc || (uVar20 < 0xc))))
                                                        || (uVar33 < 0xc)))) goto LAB_0028a61c;
                                                    puVar27[0xe] = puVar26[0xb];
                                                    if (uVar11 != 4) {
                                                      if (((((uVar20 < 0xd) || (uVar33 - 0xc < 3))
                                                           || (uVar20 < 0xd)) ||
                                                          ((((uVar33 < 0xf ||
                                                             (puVar27[0x10] = puVar26[0xc],
                                                             uVar20 < 0xe)) ||
                                                            ((uVar33 < 0xf ||
                                                             ((uVar20 < 0xe || (uVar33 < 0xf))))))
                                                           || (puVar27[0x11] = puVar26[0xd],
                                                              uVar20 < 0xf)))) ||
                                                         (((uVar33 < 0xf || (uVar20 < 0xf)) ||
                                                          (uVar33 < 0xf)))) goto LAB_0028a61c;
                                                      puVar27[0x12] = puVar26[0xe];
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                            if (((int)param_4 < 0) || (uVar37 <= param_4)) {
                                              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289770
                                                                                    );
                                                (*pcVar17)();
                                              }
                                              iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,default-topology-index",&local_88);
                                              if (iVar19 == 0) {
                                                uVar20 = (uint)local_88;
                                                if ((uint)local_88 < uVar37) goto LAB_00289724;
                                                iVar19 = -0x16;
                                                drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                              
                                                  "*ERROR* [msm-dsi-error]: default topology is specified is not valid, rc = %d\n"
                                                  ,0xffffffea);
                                              }
                                              else {
                                                drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                              
                                                  "*ERROR* [msm-dsi-error]: no default topology selected, rc = %d\n"
                                                  ,iVar19);
                                              }
                                            }
                                            else {
                                              puVar10 = puVar27 + (ulong)param_4 * 4;
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: override topology: cfg:%d lm:%d comp_enc:%d intf:%d\n"
                                                  ,param_4,*puVar10,puVar10[1],puVar10[2]);
                                              local_88 = CONCAT44(local_88._4_4_,param_4);
                                              uVar20 = param_4;
LAB_00289724:
                                              uVar25 = (ulong)uVar20;
                                              if (*(char *)(puVar36 + 0x274) == '\0') {
                                                cVar14 = *(char *)((long)puVar36 + 0x9d1);
                                                iVar19 = puVar27[uVar25 * 4 + 1];
                                                if ((cVar14 != '\0') == (iVar19 == 0))
                                                goto LAB_00289844;
                                                if (cVar14 != '\0') {
                                                  uVar21 = 2;
                                                  goto LAB_002897c8;
                                                }
                                              }
                                              else {
                                                iVar19 = puVar27[uVar25 * 4 + 1];
                                                if (iVar19 == 0) {
                                                  cVar14 = *(char *)((long)puVar36 + 0x9d1);
LAB_00289844:
                                                  drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                                  
                                                  "*ERROR* [msm-dsi-error]: topology and compression info mismatch dsc:%d vdc:%d num_enc:%d\n"
                                                  ,*(char *)(puVar36 + 0x274),cVar14);
                                                  iVar19 = 0;
                                                  goto LAB_00289860;
                                                }
                                                uVar21 = 1;
LAB_002897c8:
                                                puVar27[uVar25 * 4 + 3] = uVar21;
                                              }
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: default topology: lm: %d comp_enc:%d intf: %d\n"
                                                  ,puVar27[uVar25 * 4],iVar19,
                                                  (puVar27 + uVar25 * 4)[2]);
                                              iVar19 = 0;
                                              uVar12 = *(undefined8 *)
                                                        ((long)(puVar27 +
                                                               (local_88 & 0xffffffff) * 4) + 8);
                                              *(undefined8 *)(puVar36 + 399) =
                                                   *(undefined8 *)
                                                    (puVar27 + (local_88 & 0xffffffff) * 4);
                                              *(undefined8 *)(puVar36 + 0x191) = uVar12;
                                            }
LAB_00289860:
                                            kfree(puVar27);
                                            kfree(puVar26);
                                            if (iVar19 != 0) goto LAB_0028a384;
                                            if (puVar36 == (undefined4 *)0x0) {
                                              drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                          
                                                  "*ERROR* [msm-dsi-error]: invalid mode priv info\n"
                                                  );
                                              pcVar30 = 
                                              "*ERROR* [msm-dsi-error]: failed to parse command sets, rc=%d\n"
                                              ;
                                              goto LAB_0028a3f0;
                                            }
                                            uVar25 = 0;
                                            puVar26 = puVar36;
                                            do {
                                              *puVar26 = (int)uVar25;
                                              puVar26[2] = 0;
                                              if (uVar25 == 0x13) {
                                                lVar35 = kmalloc_trace(___drm_debug,0xdc0,0x40);
                                                *(long *)(puVar36 + 0x76) = lVar35;
                                                if (lVar35 == 0) {
                                                  drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                                  
                                                  "*ERROR* [msm-dsi-error]: failed to allocate cmd set %d, rc = %d\n"
                                                  ,0x13,0xfffffff4);
                                                  puVar36[0x73] = 0;
                                                }
                                                else {
                                                  puVar36[0x73] = 0;
                                                  puVar36[0x74] = 1;
                                                }
                                              }
                                              else {
                                                iVar19 = dsi_panel_parse_cmd_sets_sub
                                                                   (param_1,puVar26,
                                                                    uVar25 & 0xffffffff,puVar1);
                                                if (iVar19 != 0) {
                                                  __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: failed to parse set %d\n",
                                                  uVar25 & 0xffffffff);
                                                }
                                              }
                                              uVar25 = uVar25 + 1;
                                              puVar26 = puVar26 + 6;
                                            } while (uVar25 != 0x3e);
                                            lVar35 = *(long *)(param_3 + 0x2e);
                                            local_90 = 0;
                                            if (*(int *)(*(code **)(param_1 + 0x860) + -4) !=
                                                -0x2eed9d8) {
                    /* WARNING: Does not return */
                                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289968);
                                              (*pcVar17)();
                                            }
                                            iVar19 = (**(code **)(param_1 + 0x860))
                                                               (*(undefined8 *)(param_1 + 0x828),
                                                                "qcom,mdss-dsi-panel-jitter",
                                                                &local_90,2);
                                            if (iVar19 == 0) {
                                              uVar20 = 0;
                                              if (local_90._4_4_ != 0) {
                                                uVar20 = (uint)local_90 / local_90._4_4_;
                                              }
                                            }
                                            else {
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: panel jitter not defined rc=%d\n"
                                                  ,iVar19);
                                              uVar20 = 0;
                                            }
                                            if (*(char *)(param_1 + 0x8c5) == '\0') {
                                              if (((iVar19 == 0) && (uVar20 != 0)) && (uVar20 < 0xb)
                                                 ) {
                                                *(uint *)(lVar35 + 0x5dc) = (uint)local_90;
                                                *(uint *)(lVar35 + 0x5e0) = local_90._4_4_;
                                              }
                                              else {
                                                *(undefined8 *)(lVar35 + 0x5dc) = 0x100000002;
                                              }
                                            }
                                            else {
                                              local_94 = 0;
                                              local_88 = 0x100000000;
                                              if (*(int *)(*(code **)(param_1 + 0x858) + -4) !=
                                                  -0x75d5d1c9) {
                    /* WARNING: Does not return */
                                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2899e0
                                                                                    );
                                                (*pcVar17)();
                                              }
                                              uVar25 = (**(code **)(param_1 + 0x858))
                                                                 (*(undefined8 *)(param_1 + 0x828),
                                                                  "qcom,dsi-wd-jitter-enable");
                                              if ((uVar25 & 1) == 0) {
                                                *(undefined4 *)(lVar35 + 0x5dc) = 2;
                                                uVar21 = 1;
                                              }
                                              else {
                                                if (*(int *)(*(code **)(param_1 + 0x860) + -4) !=
                                                    -0x2eed9d8) {
                    /* WARNING: Does not return */
                                                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x289a18);
                                                  (*pcVar17)();
                                                }
                                                iVar19 = (**(code **)(param_1 + 0x860))
                                                                   (*(undefined8 *)(param_1 + 0x828)
                                                                    ,"qcom,dsi-wd-ltj-max-jitter",
                                                                    &local_88,2);
                                                if (*(int *)(*(code **)(param_1 + 0x848) + -4) !=
                                                    -0x40f69a0d) {
                    /* WARNING: Does not return */
                                                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x289a4c);
                                                  (*pcVar17)();
                                                }
                                                iVar22 = (**(code **)(param_1 + 0x848))
                                                                   (*(undefined8 *)(param_1 + 0x828)
                                                                    ,"qcom,dsi-wd-ltj-time-sec",
                                                                    &local_94);
                                                if (((iVar22 == 0 && iVar19 == 0) &&
                                                    (local_88._4_4_ != 0)) && (local_94 != 0)) {
                                                  uVar20 = 0;
                                                  if (local_88._4_4_ != 0) {
                                                    uVar20 = (uint)local_88 / local_88._4_4_;
                                                  }
                                                  if (9 < uVar20) goto LAB_00289a78;
                                                  *(uint *)(lVar35 + 0x9c8) = local_88._4_4_;
                                                  bVar16 = true;
                                                  *(int *)(lVar35 + 0x9cc) = local_94;
                                                  *(uint *)(lVar35 + 0x9c4) = (uint)local_88;
                                                  *(undefined4 *)(lVar35 + 0x9b8) = 4;
                                                }
                                                else {
LAB_00289a78:
                                                  __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: No valid long term jitter defined\n"
                                                  );
                                                  bVar16 = false;
                                                  *(undefined8 *)(lVar35 + 0x5dc) = 0x100000002;
                                                }
                                                if (((uint)local_90 == 0) || (local_90._4_4_ == 0))
                                                {
                                                  if (!bVar16) {
                                                    *(undefined8 *)(lVar35 + 0x9bc) = 0x100000002;
                                                    *(uint *)(lVar35 + 0x9b8) =
                                                         *(uint *)(lVar35 + 0x9b8) | 2;
                                                    goto LAB_00289b6c;
                                                  }
LAB_00289b48:
                                                  puVar26 = (undefined4 *)(lVar35 + 0x9c4);
                                                }
                                                else {
                                                  uVar20 = 0;
                                                  if (local_90._4_4_ != 0) {
                                                    uVar20 = (uint)local_90 / local_90._4_4_;
                                                  }
                                                  uVar33 = 2;
                                                  if (uVar20 < 0xb) {
                                                    uVar20 = local_90._4_4_;
                                                    uVar33 = (uint)local_90;
                                                  }
                                                  else {
                                                    uVar20 = 1;
                                                  }
                                                  *(uint *)(lVar35 + 0x9bc) = uVar33;
                                                  *(uint *)(lVar35 + 0x9c0) = uVar20;
                                                  *(uint *)(lVar35 + 0x9b8) =
                                                       *(uint *)(lVar35 + 0x9b8) | 2;
                                                  if (bVar16) goto LAB_00289b48;
LAB_00289b6c:
                                                  puVar26 = (undefined4 *)(lVar35 + 0x9bc);
                                                }
                                                lVar28 = 0x9c8;
                                                if (!bVar16) {
                                                  lVar28 = 0x9c0;
                                                }
                                                *(undefined4 *)(lVar35 + 0x5dc) = *puVar26;
                                                uVar21 = *(undefined4 *)(lVar35 + lVar28);
                                              }
                                              *(undefined4 *)(lVar35 + 0x5e0) = uVar21;
                                            }
                                            puVar8 = (uint *)(lVar35 + 0x5e4);
                                            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289bc0);
                                              (*pcVar17)();
                                            }
                                            iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,mdss-dsi-panel-prefill-lines",puVar8);
                                            if (iVar19 == 0) {
                                              if (*puVar5 + *puVar4 + *puVar7 + *puVar6 <= *puVar8)
                                              {
                                                uVar20 = 0x19;
                                                __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: invalid prefill lines config=%d setting to:%d\n"
                                                  ,*puVar8,0x19);
                                                goto LAB_00289c54;
                                              }
                                            }
                                            else {
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: panel prefill lines are not defined rc=%d\n"
                                                  ,iVar19);
                                              uVar20 = *puVar7 + *puVar5 + *puVar6;
LAB_00289c54:
                                              *puVar8 = uVar20;
                                            }
                                            lVar35 = *(long *)(param_3 + 0x2e);
                                            local_88 = local_88 & 0xffffffff00000000;
                                            if (lVar35 == 0) {
                                              iVar19 = -0x16;
LAB_00289cbc:
                                              drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                          
                                                  "*ERROR* [msm-dsi-error]: failed to parse panel phy ldo rc=%d\n"
                                                  ,iVar19);
                                            }
                                            else {
                                              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289c90
                                                                                    );
                                                (*pcVar17)();
                                              }
                                              iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,mdss-dsi-panel-phy-drive-strength",&local_88
                                                  );
                                              if (iVar19 != 0) {
                                                __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: Unsupport to set Phy Driver Strength\n"
                                                  );
                                                goto LAB_00289cbc;
                                              }
                                              *(uint *)(lVar35 + 0x638) = (uint)local_88;
                                            }
                                            lVar35 = *(long *)(param_3 + 0x2e);
                                            local_88 = local_88 & 0xffffffff00000000;
                                            if (lVar35 == 0) {
LAB_0028a2cc:
                                              pcVar30 = 
                                              "*ERROR* [msm-dsi-error]: failed to parse panel phy timings, rc=%d\n"
                                              ;
                                              goto LAB_0028a3f0;
                                            }
                                            if (*(int *)(*(code **)(param_1 + 0x838) + -4) !=
                                                0x5ba6584b) {
                    /* WARNING: Does not return */
                                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289d1c);
                                              (*pcVar17)();
                                            }
                                            lVar28 = (**(code **)(param_1 + 0x838))
                                                               (*(undefined8 *)(param_1 + 0x828),
                                                                "qcom,mdss-dsi-panel-phy-timings",
                                                                &local_88);
                                            if (lVar28 == 0) {
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: Unable to read Phy timing settings\n"
                                                  );
                                            }
                                            else {
                                              lVar29 = __kmalloc((local_88 & 0xffffffff) << 2,0xdc0)
                                              ;
                                              *(long *)(lVar35 + 0x5d0) = lVar29;
                                              if (lVar29 == 0) goto LAB_0028a2cc;
                                              if ((uint)local_88 == 0) {
                                                iVar19 = 0;
                                              }
                                              else {
                                                uVar25 = 0;
                                                do {
                                                  *(uint *)(*(long *)(lVar35 + 0x5d0) + uVar25 * 4)
                                                       = (uint)*(byte *)(lVar28 + uVar25);
                                                  uVar25 = uVar25 + 1;
                                                  iVar19 = (uint)local_88;
                                                } while (uVar25 < (local_88 & 0xffffffff));
                                              }
                                              *(int *)(lVar35 + 0x5d8) = iVar19;
                                            }
                                            if ((param_3[0x28] & 1) != 0) {
                                              if (((char)param_3[0x12] == '\0') ||
                                                 (*(long *)(param_3 + 0x14) == 0)) {
                                                if ((*(char *)((long)param_3 + 0x49) == '\0') ||
                                                   (*(long *)(param_3 + 0x16) == 0)) {
                                                  uVar25 = (ulong)*param_3;
                                                }
                                                else {
                                                  uVar25 = (ulong)*(int *)(*(long *)(param_3 + 0x16)
                                                                          + 500);
                                                }
                                              }
                                              else {
                                                uVar25 = (ulong)*(int *)(*(long *)(param_3 + 0x14) +
                                                                        0xa0);
                                              }
                                              param_3[0x26] =
                                                   (uint)(((uVar25 + (param_3[3] + param_3[1] +
                                                                     param_3[2])) *
                                                           (ulong)(param_3[7] + param_3[6] +
                                                                  param_3[8] + param_3[9]) *
                                                          (ulong)param_3[0xb]) / 1000);
                                            }
                                            lVar35 = *(long *)(param_3 + 0x2e);
                                            if (lVar35 == 0) {
                                              drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                          
                                                  "*ERROR* [msm-dsi-error]: invalid arguments\n");
                                              iVar19 = -0x16;
                                            }
                                            else {
                                              puVar9 = (undefined8 *)(lVar35 + 0x9dc);
                                              *(undefined8 *)(lVar35 + 0x9ec) = 0;
                                              *(undefined8 *)(lVar35 + 0x9f4) = 0;
                                              *puVar9 = 0;
                                              *(undefined8 *)(lVar35 + 0x9e4) = 0;
                                              if (*(int *)(*(code **)(param_1 + 0x838) + -4) !=
                                                  0x5ba6584b) {
                    /* WARNING: Does not return */
                                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289e5c
                                                                                    );
                                                (*pcVar17)();
                                              }
                                              pcVar30 = (char *)(**(code **)(param_1 + 0x838))
                                                                          (*(undefined8 *)
                                                                            (param_1 + 0x828),
                                                                                                                                                      
                                                  "qcom,partial-update-enabled",0);
                                              if (pcVar30 == (char *)0x0) {
                                                __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: partial update disabled as the property is not set\n"
                                                  );
LAB_00287fe0:
                                                iVar19 = 0;
                                                goto LAB_00287ff4;
                                              }
                                              iVar19 = strcmp(pcVar30,"dual_roi");
                                              if (iVar19 == 0) {
                                                uVar21 = 2;
                                              }
                                              else {
                                                iVar19 = strcmp(pcVar30,"single_roi");
                                                if (iVar19 != 0) {
                                                  drm_dev_printk(0,&DAT_002cdc0f,
                                                                                                                                  
                                                  "[msm-dsi-info]: invalid value for qcom,partial-update-enabled: %s\n"
                                                  ,pcVar30);
                                                  goto LAB_00287fe0;
                                                }
                                                uVar21 = 1;
                                              }
                                              *(undefined4 *)(lVar35 + 0x9e0) = uVar21;
                                              if (*(int *)(*(code **)(param_1 + 0x858) + -4) !=
                                                  -0x75d5d1c9) {
                    /* WARNING: Does not return */
                                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289f1c
                                                                                    );
                                                (*pcVar17)();
                                              }
                                              bVar18 = (**(code **)(param_1 + 0x858))
                                                                 (*(undefined8 *)(param_1 + 0x828),
                                                                  "qcom,partial-update-roi-merge");
                                              *(byte *)(lVar35 + 0x9dd) = bVar18 & 1;
                                              *(bool *)(lVar35 + 0x9dc) =
                                                   *(int *)(lVar35 + 0x9e0) != 0;
                                              if (*(int *)(lVar35 + 0x9e0) == 0) {
LAB_0028a0fc:
                                                lVar28 = *(long *)(param_3 + 0x2e);
                                                if (*(char *)(lVar28 + 0x9d0) != '\0') {
                                                  uVar15 = *(ushort *)(lVar28 + 0x650);
                                                  uVar20 = 0;
                                                  if (uVar15 != 0) {
                                                    uVar20 = *(uint *)(lVar35 + 0x9f4) /
                                                             (uint)uVar15;
                                                  }
                                                  if (*(uint *)(lVar35 + 0x9f4) == uVar20 * uVar15)
                                                  {
                                                    uVar15 = *(ushort *)(lVar28 + 0x652);
                                                    uVar20 = 0;
                                                    if (uVar15 != 0) {
                                                      uVar20 = *(uint *)(lVar35 + 0x9f8) /
                                                               (uint)uVar15;
                                                    }
                                                    if (*(uint *)(lVar35 + 0x9f8) == uVar20 * uVar15
                                                       ) goto LAB_0028a150;
                                                  }
                                                  *(undefined8 *)(lVar35 + 0x9ec) = 0;
                                                  *(undefined8 *)(lVar35 + 0x9f4) = 0;
                                                  *puVar9 = 0;
                                                  *(undefined8 *)(lVar35 + 0x9e4) = 0;
                                                  drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                                  
                                                  "*ERROR* [msm-dsi-error]: panel roi can\'t match DSC slice settings,disable partial update\n"
                                                  );
                                                }
LAB_0028a150:
                                                iVar19 = 0;
                                              }
                                              else {
                                                local_90 = local_90 & 0xffffffff00000000;
                                                *(undefined8 *)(lVar35 + 0x9e4) = 0;
                                                *(undefined8 *)(lVar35 + 0x9ec) = 0;
                                                *(undefined8 *)(lVar35 + 0x9f4) = 0;
                                                local_80 = 0;
                                                local_78 = 0;
                                                local_88 = 0;
                                                if (*(int *)(*(code **)(param_1 + 0x888) + -4) !=
                                                    0x31beb620) {
                    /* WARNING: Does not return */
                                                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x289f84);
                                                  (*pcVar17)();
                                                }
                                                lVar28 = (**(code **)(param_1 + 0x888))
                                                                   (*(undefined8 *)(param_1 + 0x828)
                                                                    ,"qcom,panel-roi-alignment",
                                                                    &local_90);
                                                iVar19 = (int)(uint)local_90 >> 2;
                                                local_90 = CONCAT44(local_90._4_4_,iVar19);
                                                if (lVar28 == 0) {
                                                  drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                                  
                                                  "*ERROR* [msm-dsi-error]: panel roi alignment not found\n"
                                                  );
LAB_0028a068:
                                                  iVar19 = -0x16;
                                                }
                                                else {
                                                  if (iVar19 != 6) {
                                                    drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                                      
                                                  "*ERROR* [msm-dsi-error]: incorrect roi alignment len %d\n"
                                                  );
                                                  goto LAB_0028a068;
                                                  }
                                                  if (*(int *)(*(code **)(param_1 + 0x860) + -4) !=
                                                      -0x2eed9d8) {
                    /* WARNING: Does not return */
                                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x289fd0);
                                                  (*pcVar17)();
                                                  }
                                                  iVar19 = (**(code **)(param_1 + 0x860))
                                                                     (*(undefined8 *)
                                                                       (param_1 + 0x828),
                                                                      "qcom,panel-roi-alignment",
                                                                      &local_88,6);
                                                  if (iVar19 == 0) {
                                                    *(uint *)(lVar35 + 0x9e4) = (uint)local_88;
                                                    *(uint *)(lVar35 + 0x9ec) = local_88._4_4_;
                                                    *(undefined4 *)(lVar35 + 0x9e8) =
                                                         (undefined4)local_80;
                                                    *(undefined4 *)(lVar35 + 0x9f0) = local_80._4_4_
                                                    ;
                                                    *(undefined4 *)(lVar35 + 0x9f4) =
                                                         (undefined4)local_78;
                                                    *(undefined4 *)(lVar35 + 0x9f8) = local_78._4_4_
                                                    ;
                                                    drm_dev_printk(0,&DAT_002cdc0f,
                                                                                                                                      
                                                  "[msm-dsi-info]: roi alignment: [%d, %d, %d, %d, %d, %d]\n"
                                                  );
                                                  goto LAB_0028a0fc;
                                                  }
                                                  __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: error reading panel roi alignment values\n"
                                                  );
                                                  drm_dev_printk(0,&DAT_002cdc0f,
                                                                                                                                  
                                                  "[msm-dsi-info]: roi alignment: [%d, %d, %d, %d, %d, %d]\n"
                                                  ,*(undefined4 *)(lVar35 + 0x9e4),
                                                  *(undefined4 *)(lVar35 + 0x9e8),
                                                  *(undefined4 *)(lVar35 + 0x9ec),
                                                  *(undefined4 *)(lVar35 + 0x9f0),
                                                  *(undefined4 *)(lVar35 + 0x9f4),
                                                  *(undefined4 *)(lVar35 + 0x9f8));
                                                }
                                                *(undefined8 *)(lVar35 + 0x9ec) = 0;
                                                *(undefined8 *)(lVar35 + 0x9f4) = 0;
                                                *puVar9 = 0;
                                                *(undefined8 *)(lVar35 + 0x9e4) = 0;
                                              }
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: partial update num_rois=%d enabled=%d\n"
                                                  ,*(undefined4 *)(lVar35 + 0x9e0),
                                                  *(undefined1 *)(lVar35 + 0x9dc));
                                              if (iVar19 == 0) goto LAB_00287ff4;
                                            }
                                            drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                      
                                                  "*ERROR* [msm-dsi-error]: failed to partial update caps, rc=%d\n"
                                                  ,iVar19);
                                            goto LAB_00287ff4;
                                          }
                                          iVar19 = -0xc;
                                        }
                                        else {
                                          drm_dev_printk(0,&DAT_002b5e64,
                                                                                                                  
                                                  "*ERROR* [msm-dsi-error]: unable to read the display topologies, rc = %d\n"
                                                  ,iVar19);
                                        }
                                        kfree(puVar26);
                                      }
                                    }
LAB_0028a384:
                                    pcVar30 = 
                                    "*ERROR* [msm-dsi-error]: failed to parse panel topology, rc=%d\n"
                                    ;
                                    goto LAB_0028a5c8;
                                  }
                                  *(undefined1 *)(lVar35 + 0x9d1) = 1;
LAB_00288fe8:
                                  *(char *)(lVar35 + 0x730) = (char)uVar13;
                                  if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28901c);
                                    (*pcVar17)();
                                  }
                                  iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,vdc-version",&local_88);
                                  if (iVar19 == 0) {
                                    uVar20 = (uint)local_88 >> 4 & 0xf;
                                    *(char *)(lVar35 + 0x720) = (char)uVar20;
                                    *(char *)(lVar35 + 0x721) = (char)((uint)local_88 & 0xf);
                                    if ((uVar20 != 1) && (((uint)local_88 & 0xf) != 2)) {
                                      drm_dev_printk(0,&DAT_002b5e64,
                                                                                                          
                                                  "*ERROR* [msm-dsi-error]: %s:unsupported major:%d minor:%d version\n"
                                                  ,"dsi_panel_parse_vdc_params");
                                      goto LAB_0028a570;
                                    }
                                  }
                                  else {
                                    *(undefined4 *)(lVar35 + 0x9a4) = 0;
                                    *(undefined2 *)(lVar35 + 0x720) = 0x201;
                                  }
                                  if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289084);
                                    (*pcVar17)();
                                  }
                                  iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,vdc-version-release",
                                                              &local_88);
                                  if (iVar19 == 0) {
                                    *(uint *)(lVar35 + 0x9a4) = (uint)(byte)local_88;
                                    if ((byte)local_88 == 0) goto LAB_002890a0;
                                    pcVar30 = 
                                    "*ERROR* [msm-dsi-error]: unsupported vdc release version %d\n";
LAB_0028a568:
                                    drm_dev_printk(0,&DAT_002b5e64,pcVar30);
                                    goto LAB_0028a570;
                                  }
                                  *(undefined4 *)(lVar35 + 0x9a4) = 0;
LAB_002890a0:
                                  drm_dev_printk(0,&DAT_002cdc0f,
                                                 "[msm-dsi-info]: vdc major: 0x%x minor : 0x%x release : 0x%x\n"
                                                 ,*(undefined1 *)(lVar35 + 0x720),
                                                 *(undefined1 *)(lVar35 + 0x721),0);
                                  if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2890f0);
                                    (*pcVar17)();
                                  }
                                  iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,vdc-slice-height",
                                                              &local_88);
                                  if (iVar19 == 0) {
                                    *(uint *)(lVar35 + 0x8f8) = (uint)local_88;
                                    if ((int)(uint)local_88 < 0x10) {
                                      pcVar30 = "*ERROR* [msm-dsi-error]: invalid slice height %d\n"
                                      ;
                                      goto LAB_0028a568;
                                    }
                                    if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289134);
                                      (*pcVar17)();
                                    }
                                    iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,vdc-slice-width",
                                                                &local_88);
                                    if (iVar19 == 0) {
                                      *(uint *)(lVar35 + 0x8fc) = (uint)local_88;
                                      if (((int)(uint)local_88 < 0x40) || ((local_88 & 7) != 0)) {
                                        pcVar30 = 
                                        "*ERROR* [msm-dsi-error]: invalid slice width:%d\n";
                                        goto LAB_0028a568;
                                      }
                                      if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289180);
                                        (*pcVar17)();
                                      }
                                      iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,vdc-slice-per-pkt",
                                                                  &local_88);
                                      if (iVar19 == 0) {
                                        if ((uint)local_88 - 3 < 0xfffffffe) {
                                          pcVar30 = 
                                          "*ERROR* [msm-dsi-error]: invalid vdc slice-per-pkt:%d\n";
                                          goto LAB_0028a568;
                                        }
                                        uVar20 = *param_3;
                                        *(uint *)(lVar35 + 0x918) = (uint)local_88;
                                        *(uint *)(lVar35 + 0x900) = *param_3;
                                        *(uint *)(lVar35 + 0x904) = param_3[6];
                                        if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2891dc);
                                          (*pcVar17)();
                                        }
                                        iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,vdc-bit-per-component",&local_88);
                                        if (iVar19 == 0) {
                                          *(char *)(lVar35 + 0x8b3) = (char)local_88;
                                          if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289218);
                                            (*pcVar17)();
                                          }
                                          iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,mdss-pps-delay-ms",&local_88);
                                          if (iVar19 == 0) {
                                            uVar21 = (uint)local_88;
                                          }
                                          else {
                                            __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: pps-delay-ms not specified, defaulting to 0\n"
                                                  );
                                            local_88 = local_88 & 0xffffffff00000000;
                                            uVar21 = 0;
                                          }
                                          *(undefined4 *)(lVar35 + 0x9a0) = uVar21;
                                          if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                            pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289278);
                                            (*pcVar17)();
                                          }
                                          iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,vdc-bit-per-pixel",&local_88);
                                          if (iVar19 == 0) {
                                            *(short *)(lVar35 + 0x8e6) = (short)local_88 << 4;
                                            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x2892b8);
                                              (*pcVar17)();
                                            }
                                            iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,src-chroma-format",&local_88);
                                            if (iVar19 == 0) {
                                              uVar31 = (byte)local_88;
                                            }
                                            else {
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: failed to parse qcom,src-chroma-format\n"
                                                  );
                                              local_88 = local_88 & 0xffffffff00000000;
                                              uVar31 = 0;
                                            }
                                            *(undefined1 *)(lVar35 + 0x723) = uVar31;
                                            if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                              pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x289318);
                                              (*pcVar17)();
                                            }
                                            iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,src-color-space",&local_88);
                                            if (iVar19 == 0) {
                                              uVar31 = (undefined1)local_88;
                                            }
                                            else {
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: failed to parse qcom,src-color-space\n"
                                                  );
                                              uVar31 = 0;
                                              local_88 = local_88 & 0xffffffff00000000;
                                            }
                                            *(undefined1 *)(lVar35 + 0x722) = uVar31;
                                            iVar19 = sde_vdc_populate_config
                                                               (lVar35 + 0x720,uVar20,uVar13);
                                            if (iVar19 != 0) {
                                              __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: failed populating vdc config\n")
                                              ;
                                              goto LAB_0028a570;
                                            }
                                            *(uint *)(lVar35 + 0x9d4) =
                                                 (uint)(*(ushort *)(lVar35 + 0x8e6) >> 4);
                                            uVar21 = msm_get_src_bpc(*(undefined1 *)(lVar35 + 0x723)
                                                                     ,*(undefined1 *)
                                                                       (lVar35 + 0x8b3));
                                            *(undefined4 *)(lVar35 + 0x9d8) = uVar21;
                                            *(long *)(param_3 + 0x16) = lVar35 + 0x720;
                                            *(undefined1 *)((long)param_3 + 0x49) = 1;
                                            *(undefined8 *)(param_3 + 0x18) =
                                                 *(undefined8 *)(lVar35 + 0x9d4);
                                            goto LAB_00289398;
                                          }
                                          pcVar30 = 
                                          "*ERROR* [msm-dsi-error]: failed to parse qcom,vdc-bit-per-pixel\n"
                                          ;
                                        }
                                        else {
                                          pcVar30 = 
                                          "*ERROR* [msm-dsi-error]: failed to parse qcom,vdc-bit-per-component\n"
                                          ;
                                        }
                                      }
                                      else {
                                        pcVar30 = 
                                        "*ERROR* [msm-dsi-error]: failed to parse qcom,vdc-slice-per-pkt\n"
                                        ;
                                      }
                                    }
                                    else {
                                      pcVar30 = 
                                      "*ERROR* [msm-dsi-error]: failed to parse qcom,vdc-slice-width\n"
                                      ;
                                    }
                                  }
                                  else {
                                    pcVar30 = 
                                    "*ERROR* [msm-dsi-error]: failed to parse qcom,vdc-slice-height\n"
                                    ;
                                  }
                                  drm_dev_printk(0,&DAT_002b5e64,pcVar30);
                                }
                                pcVar30 = 
                                "*ERROR* [msm-dsi-error]: failed to parse vdc params, rc=%d\n";
                                goto LAB_0028a5c8;
                              }
                              *(undefined1 *)(lVar35 + 0x9d0) = 1;
LAB_00288b14:
                              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288b40);
                                (*pcVar17)();
                              }
                              iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsc-version",&local_88)
                              ;
                              if (iVar19 == 0) {
                                uVar20 = (uint)local_88 >> 4 & 0xf;
                                *(char *)(lVar35 + 0x6cb) = (char)uVar20;
                                *(char *)(lVar35 + 0x6ca) = (char)((uint)local_88 & 0xf);
                                if ((uVar20 != 1) || (1 < ((uint)local_88 & 0xf) - 1)) {
                                  drm_dev_printk(0,&DAT_002b5e64,
                                                 "*ERROR* [msm-dsi-error]: %s:unsupported major:%d minor:%d version\n"
                                                 ,"dsi_panel_parse_dsc_params");
                                  goto LAB_0028a5ac;
                                }
                              }
                              else {
                                *(undefined2 *)(lVar35 + 0x6ca) = 0x101;
                              }
                              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288ba8);
                                (*pcVar17)();
                              }
                              iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsc-scr-version",
                                                          &local_88);
                              if (iVar19 == 0) {
                                *(char *)(lVar35 + 0x6d4) = (char)local_88;
                                if (1 < ((uint)local_88 & 0xff)) {
                                  drm_dev_printk(0,&DAT_002b5e64,
                                                 "*ERROR* [msm-dsi-error]: %s: DSC scr version:%d not supported\n"
                                                 ,"dsi_panel_parse_dsc_params");
                                  goto LAB_0028a5ac;
                                }
                              }
                              else {
                                *(undefined1 *)(lVar35 + 0x6d4) = 0;
                              }
                              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288bf8);
                                (*pcVar17)();
                              }
                              iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsc-slice-height",
                                                          &local_88);
                              if (iVar19 == 0) {
                                *(short *)(lVar35 + 0x652) = (short)local_88;
                                if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288c34);
                                  (*pcVar17)();
                                }
                                iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsc-slice-width",
                                                            &local_88);
                                if (iVar19 == 0) {
                                  *(short *)(lVar35 + 0x650) = (short)local_88;
                                  uVar20 = *param_3;
                                  iVar19 = 0;
                                  if ((local_88 & 0xffff) != 0) {
                                    iVar19 = (int)uVar20 / (int)((uint)local_88 & 0xffff);
                                  }
                                  if (uVar20 != iVar19 * ((uint)local_88 & 0xffff)) {
                                    drm_dev_printk(0,&DAT_002b5e64,
                                                                                                      
                                                  "*ERROR* [msm-dsi-error]: invalid slice width for the intf width:%d slice width:%d\n"
                                                  ,uVar20);
                                    goto LAB_0028a5ac;
                                  }
                                  *(short *)(lVar35 + 0x656) = (short)uVar20;
                                  *(short *)(lVar35 + 0x658) = (short)*puVar4;
                                  if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288c94);
                                    (*pcVar17)();
                                  }
                                  iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsc-slice-per-pkt",
                                                              &local_88);
                                  if (iVar19 == 0) {
                                    if ((uint)local_88 - 3 < 0xfffffffe) {
                                      drm_dev_printk(0,&DAT_002b5e64,
                                                                                                          
                                                  "*ERROR* [msm-dsi-error]: invalid dsc slice-per-pkt:%d\n"
                                                  );
                                      goto LAB_00288f68;
                                    }
                                    *(uint *)(lVar35 + 0x6f4) = (uint)local_88;
                                    if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288cf8);
                                      (*pcVar17)();
                                    }
                                    iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,mdss-dsc-bit-per-component",&local_88);
                                    if (iVar19 == 0) {
                                      *(char *)(lVar35 + 0x64d) = (char)local_88;
                                      if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288d34);
                                        (*pcVar17)();
                                      }
                                      iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-pps-delay-ms",
                                                                  &local_88);
                                      if (iVar19 == 0) {
                                        uVar21 = (uint)local_88;
                                      }
                                      else {
                                        __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: pps-delay-ms not specified, defaulting to 0\n"
                                                  );
                                        local_88 = local_88 & 0xffffffff00000000;
                                        uVar21 = 0;
                                      }
                                      *(undefined4 *)(lVar35 + 0x70c) = uVar21;
                                      if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288d94);
                                        (*pcVar17)();
                                      }
                                      iVar19 = (*(code *)*puVar2)(*puVar1,
                                                  "qcom,mdss-dsc-bit-per-pixel",&local_88);
                                      if (iVar19 == 0) {
                                        *(short *)(lVar35 + 0x65c) = (short)local_88 << 4;
                                        if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288dd4);
                                          (*pcVar17)();
                                        }
                                        iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,src-chroma-format"
                                                                    ,&local_88);
                                        if (iVar19 == 0) {
                                          iVar19 = (uint)local_88;
                                          if ((uint)local_88 == 2) {
                                            *(undefined1 *)(lVar35 + 0x6cd) = 1;
                                          }
                                          else if ((uint)local_88 == 1) {
                                            *(undefined1 *)(lVar35 + 0x6cc) = 1;
                                          }
                                        }
                                        else {
                                          __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: failed to parse qcom,src-chroma-format\n"
                                                  );
                                          local_88 = local_88 & 0xffffffff00000000;
                                          iVar19 = 0;
                                        }
                                        *(int *)(lVar35 + 0x700) = iVar19;
                                        if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288e2c);
                                          (*pcVar17)();
                                        }
                                        iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,src-color-space",
                                                                    &local_88);
                                        if (iVar19 == 0) {
                                          uVar21 = (uint)local_88;
                                        }
                                        else {
                                          __drm_dev_dbg(0,0,0,
                                                  "[msm-dsi-debug]: failed to parse qcom,src-color-space\n"
                                                  );
                                          local_88 = local_88 & 0xffffffff00000000;
                                          uVar21 = 0;
                                        }
                                        *(undefined4 *)(lVar35 + 0x6fc) = uVar21;
                                        lVar28 = lVar35 + 0x64c;
                                        if (*(int *)(*(code **)(param_1 + 0x858) + -4) !=
                                            -0x75d5d1c9) {
                    /* WARNING: Does not return */
                                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288ea8);
                                          (*pcVar17)();
                                        }
                                        bVar18 = (**(code **)(param_1 + 0x858))
                                                           (*(undefined8 *)(param_1 + 0x828),
                                                            "qcom,mdss-dsc-block-prediction-enable")
                                        ;
                                        uVar15 = *(ushort *)(lVar35 + 0x650);
                                        *(byte *)(lVar35 + 0x666) = bVar18 & 1;
                                        uVar31 = 0;
                                        if (uVar15 != 0) {
                                          uVar31 = (undefined1)
                                                   ((int)(uVar20 + uVar15 + -1) / (int)(uint)uVar15)
                                          ;
                                        }
                                        *(undefined1 *)(lVar35 + 0x64f) = uVar31;
                                        if (*(int *)(*(code **)(param_1 + 0x858) + -4) !=
                                            -0x75d5d1c9) {
                    /* WARNING: Does not return */
                                          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x288ef0);
                                          (*pcVar17)();
                                        }
                                        bVar18 = (**(code **)(param_1 + 0x858))
                                                           (*(undefined8 *)(param_1 + 0x828),
                                                            "qcom,mdss-dsc-novateck-ic");
                                        *(byte *)(lVar35 + 0x71d) = bVar18 & 1;
                                        if ((bVar18 & 1) == 0) {
                                          iVar19 = sde_dsc_populate_dsc_config
                                                             (lVar28,*(undefined1 *)(lVar35 + 0x6d4)
                                                             );
                                          if (iVar19 == 0) goto LAB_00288f20;
                                          pcVar30 = 
                                          "[msm-dsi-debug]: failed populating dsc params\n";
                                        }
                                        else {
                                          iVar19 = sde_dsc_populate_dsc_config_nt(lVar28);
                                          if (iVar19 == 0) {
LAB_00288f20:
                                            iVar19 = sde_dsc_populate_dsc_private_params
                                                               (lVar28,uVar20,
                                                                *(undefined1 *)(lVar35 + 0x9fc));
                                            if (iVar19 == 0) {
                                              *(uint *)(lVar35 + 0x9d4) =
                                                   (uint)(*(ushort *)(lVar35 + 0x65c) >> 4);
                                              uVar21 = msm_get_src_bpc(*(undefined4 *)
                                                                        (lVar35 + 0x700),
                                                                       *(undefined1 *)
                                                                        (lVar35 + 0x64d));
                                              *(undefined4 *)(lVar35 + 0x9d8) = uVar21;
                                              *(long *)(param_3 + 0x14) = lVar28;
                                              *(undefined1 *)(param_3 + 0x12) = 1;
                                              *(undefined8 *)(param_3 + 0x18) =
                                                   *(undefined8 *)(lVar35 + 0x9d4);
                                              goto LAB_00288f68;
                                            }
                                            pcVar30 = 
                                            "[msm-dsi-debug]: failed populating other dsc params\n";
                                          }
                                          else {
                                            pcVar30 = 
                                            "[msm-dsi-debug]: failed populating dsc params(nt)\n";
                                          }
                                        }
                                        __drm_dev_dbg(0,0,0,pcVar30);
                                        goto LAB_0028a5ac;
                                      }
                                      pcVar30 = 
                                      "*ERROR* [msm-dsi-error]: failed to parse qcom,mdss-dsc-bit-per-pixel\n"
                                      ;
                                    }
                                    else {
                                      pcVar30 = 
                                      "*ERROR* [msm-dsi-error]: failed to parse qcom,mdss-dsc-bit-per-component\n"
                                      ;
                                    }
                                  }
                                  else {
                                    pcVar30 = 
                                    "*ERROR* [msm-dsi-error]: failed to parse qcom,mdss-dsc-slice-per-pkt\n"
                                    ;
                                  }
                                }
                                else {
                                  pcVar30 = 
                                  "*ERROR* [msm-dsi-error]: failed to parse qcom,mdss-dsc-slice-width\n"
                                  ;
                                }
                              }
                              else {
                                pcVar30 = 
                                "*ERROR* [msm-dsi-error]: failed to parse qcom,mdss-dsc-slice-height\n"
                                ;
                              }
                              drm_dev_printk(0,&DAT_002b5e64,pcVar30);
                            }
                            pcVar30 = "*ERROR* [msm-dsi-error]: failed to parse dsc params, rc=%d\n"
                            ;
                            goto LAB_0028a5c8;
                          }
                        }
                        pcVar30 = 
                        "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-v-back-porch, rc=%d\n"
                        ;
                      }
                      else {
                        pcVar30 = 
                        "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-panel-height, rc=%d\n"
                        ;
                      }
                    }
                    else {
                      pcVar30 = 
                      "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-h-pulse-width, rc=%d\n"
                      ;
                    }
                  }
                  else {
                    pcVar30 = 
                    "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-h-back-porch, rc=%d\n";
                  }
                }
                else {
                  pcVar30 = 
                  "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-h-front-porch, rc=%d\n";
                }
              }
              else {
                pcVar30 = 
                "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-panel-width, rc=%d\n";
              }
            }
            else {
              pcVar30 = 
              "*ERROR* [msm-dsi-error]: failed to read qcom,mdss-dsi-panel-framerate, rc=%d\n";
            }
LAB_0028a284:
            drm_dev_printk(0,&DAT_002b5e64,pcVar30,iVar19);
            pcVar30 = "*ERROR* [msm-dsi-error]: failed to parse panel timing, rc=%d\n";
          }
          else {
            local_88 = local_88 & 0xffffffff00000000;
            if (*(long *)(param_3 + 0x2e) != 0) {
              if (*(int *)((code *)*puVar2 + -4) != -0x40f69a0d) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28819c);
                (*pcVar17)();
              }
              iVar19 = (*(code *)*puVar2)(*puVar1,"qcom,mdss-dsi-bpp-mode",&local_88);
              if (iVar19 == 0) {
                uVar20 = 7;
                if ((uint)local_88 != 0x1e) {
                  uVar20 = 3;
                }
              }
              else {
                __drm_dev_dbg(0,0,0,
                              "[msm-dsi-debug]: bpp mode not defined in timing node, setting default 24bpp\n"
                             );
                uVar20 = 3;
              }
              goto LAB_002881e0;
            }
            drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: invalid arguments\n");
            pcVar30 = "*ERROR* [msm-dsi-error]: failed to parse bpp mode caps, rc=%d\n";
LAB_0028a3f0:
            iVar19 = -0x16;
          }
LAB_0028a5c8:
          drm_dev_printk(0,&DAT_002b5e64,pcVar30,iVar19);
          break;
        }
LAB_00287ff4:
        if (*(int *)(*(code **)(param_1 + 0x890) + -4) != -0x11824650) {
                    /* WARNING: Does not return */
          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x28803c);
          (*pcVar17)();
        }
        lVar24 = (**(code **)(param_1 + 0x890))(lVar23,lVar24);
        uVar32 = uVar32 + 1;
      } while (lVar24 != 0);
    }
  }
  *puVar1 = uVar34;
  mutex_unlock(param_1 + 0x3f8);
LAB_0028a5dc:
  lVar23 = sp_el0;
  if (*(long *)(lVar23 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar19;
}



//------------------------------------------------------------
// dsi_panel_vm_trigger_esd_attack @ 0028d8d0 size=276
// signature: undefined dsi_panel_vm_trigger_esd_attack(void)
//------------------------------------------------------------

int dsi_panel_vm_trigger_esd_attack(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  if (*(int *)((code *)param_1[0x115] + -4) != 0x2d7e5b10) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x28d910);
    (*pcVar1)();
  }
  uVar3 = (*(code *)param_1[0x115])(param_1[0x105],"qcom,platform-reset-gpio",0);
  if ((uint)uVar3 < 0x200) {
    iVar2 = gpio_request(uVar3,"reset_gpio");
    if (iVar2 == 0) {
      uVar4 = gpio_to_desc(uVar3 & 0xffffffff);
      gpiod_set_raw_value_cansleep(uVar4,0);
      sde_evtlog_log(sde_dbg_base_evtlog,"dsi_panel_trigger_esd_attack_sub",0x15b,0xffffffff,0x3333,
                     0xc0debeef);
      drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: GPIO pulled low to simulate ESD\n");
      gpio_free(uVar3 & 0xffffffff);
    }
    else {
      drm_dev_printk(0,&DAT_002b5e64,
                     "*ERROR* [msm-dsi-error]: request for reset_gpio failed, rc=%d\n",iVar2);
    }
  }
  else {
    drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: [%s] reset gpio not provided\n",
                   *param_1);
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// dsi_panel_trigger_esd_attack @ 0028e584 size=208
// signature: undefined dsi_panel_trigger_esd_attack(void)
//------------------------------------------------------------

undefined8 dsi_panel_trigger_esd_attack(long param_1)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    pcVar2 = "*ERROR* [msm-dsi-error]: Invalid panel param\n";
  }
  else {
    if (param_1 != -0x620) {
      if (*(uint *)(param_1 + 0x62c) < 0x200) {
        uVar1 = gpio_to_desc();
        gpiod_set_raw_value_cansleep(uVar1,0);
        sde_evtlog_log(sde_dbg_base_evtlog,"dsi_panel_trigger_esd_attack_sub",0x15b,0xffffffff,
                       0x3333,0xc0debeef);
        uVar1 = 0;
        pcVar2 = "[msm-dsi-info]: GPIO pulled low to simulate ESD\n";
      }
      else {
        uVar1 = 0xffffffea;
        pcVar2 = "[msm-dsi-info]: failed to pull down the reset gpio\n";
      }
      drm_dev_printk(0,&DAT_002cdc0f,pcVar2);
      return uVar1;
    }
    pcVar2 = "*ERROR* [msm-dsi-error]: Invalid panel reset configuration\n";
  }
  drm_dev_printk(0,&DAT_002b5e64,pcVar2);
  return 0xffffffea;
}



//------------------------------------------------------------
// dsi_panel_aod_backlight_update @ 0029289c size=884
// signature: undefined dsi_panel_aod_backlight_update(void)
//------------------------------------------------------------

void dsi_panel_aod_backlight_update(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  code *pcVar6;
  bool bVar7;
  undefined *puVar8;
  byte bVar9;
  long lVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  undefined8 *puVar15;
  
  drm_dev_printk(0,&DAT_002cdc0f,"[msm-dsi-info]: %s \n","dsi_panel_aod_backlight_update");
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  if (param_1[0xb0] == 0) {
    return;
  }
  if (0x3d < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x292c10);
    (*pcVar6)();
  }
  lVar10 = *(long *)(param_1[0xb0] + 0xb8) + (ulong)param_2 * 0x18;
  iVar13 = *(int *)(lVar10 + 8);
  if (iVar13 == 0) {
    __drm_dev_dbg(0,0,0,
                  "[msm-dsi-debug]: [%s] No commands to be sent for state DSI_CMD_SET_TIMING_SWITCH\n"
                  ,*param_1);
    return;
  }
  uVar12 = *(uint *)(param_1 + 0xb8);
  lVar10 = *(long *)(lVar10 + 0x10);
  if ((uVar12 != 0) || (uVar12 = *(uint *)((long)param_1 + 0x614), uVar12 != 0)) {
    if (uVar12 < *(uint *)((long)param_1 + 0x80c)) {
      puVar11 = (uint *)((long)param_1 + 0x814);
      goto LAB_00292994;
    }
    if (*(uint *)(param_1 + 0x102) < uVar12) {
      puVar11 = (uint *)((long)param_1 + 0x81c);
      goto LAB_00292994;
    }
  }
  puVar11 = (uint *)(param_1 + 0x103);
LAB_00292994:
  uVar2 = *puVar11;
  _printk(&DAT_002e9d2e,"dsi_panel_aod_backlight_update",*(undefined4 *)((long)param_1 + 0x614));
  uVar5 = uVar2 >> 8 & 0xff;
  puVar15 = (undefined8 *)(lVar10 + 0x10);
  uVar1 = uVar2 & 0xff;
  uVar4 = (ushort)(uVar2 >> 8) & 0xff | (ushort)((uVar2 & 0xff00ff) << 8);
  do {
    pbVar14 = (byte *)*puVar15;
    bVar9 = *pbVar14;
    if (bVar9 == 0x51) {
      if ((param_2 < 0x39) && ((1L << ((ulong)param_2 & 0x3f) & 0x100000000030000U) != 0)) {
        *(ushort *)(pbVar14 + 1) = uVar4;
        _printk(&DAT_002c317d,"dsi_panel_aod_backlight_update",*param_1,uVar5,uVar1);
        bVar9 = *pbVar14;
      }
      bVar7 = bVar9 == 0x51;
      if ((param_2 != 0x12) || (bVar9 != 0x51)) goto joined_r0x00292a78;
      if (uVar12 == 0) {
        uVar12 = *(uint *)(param_1 + 0x103);
      }
      *(ushort *)(pbVar14 + 1) = (ushort)(uVar12 >> 8) & 0xff | (ushort)((uVar12 & 0xff00ff) << 8);
      _printk(&DAT_002c317d,"dsi_panel_aod_backlight_update",*param_1,uVar12 >> 8 & 0xff,
              uVar12 & 0xff);
    }
    else {
      bVar7 = false;
joined_r0x00292a78:
      if (1 < param_2 - 0x39) {
        if (param_2 == 0xe) {
          if (bVar7) {
            uVar12 = *(uint *)(param_1 + 0xb8);
            if (uVar12 == 0) {
              uVar12 = *(uint *)((long)param_1 + 0x614);
              if (uVar12 == 0) goto LAB_00292ae0;
              *(uint *)(param_1 + 0xb8) = uVar12;
              *(uint *)(param_1 + 0xde) = uVar12;
              *(uint *)(param_1 + 0x165) = uVar12;
              *(uint *)(param_1 + 0xc3) = uVar12;
              _printk(&DAT_002f3b93,"dsi_panel_aod_backlight_update",uVar12);
              bVar9 = *pbVar14;
            }
            else {
              bVar9 = 0x51;
            }
            *(ushort *)(pbVar14 + 1) =
                 (ushort)(uVar12 >> 8) & 0xff | (ushort)((uVar12 & 0xff00ff) << 8);
            _printk(&DAT_003037ba,"dsi_panel_aod_backlight_update",*param_1,bVar9,uVar12 >> 8 & 0xff
                    ,uVar12 & 0xff);
            cVar3 = *(char *)((long)param_1 + 0x7f2);
          }
          else {
LAB_00292ae0:
            cVar3 = *(char *)((long)param_1 + 0x7f2);
          }
          if ((cVar3 != '\0') && (*(uint *)((long)param_1 + 0x7f4) == (uint)*pbVar14)) {
            if (*(uint *)((long)param_1 + 0x7bc) < uVar12) {
              pbVar14[1] = (byte)*(undefined4 *)((long)param_1 + 0x7fc);
              *(undefined1 *)((long)param_1 + 0x7f1) = 0;
            }
            else {
              pbVar14[1] = (byte)*(undefined4 *)(param_1 + 0xff);
              *(undefined1 *)((long)param_1 + 0x7f1) = 1;
            }
          }
          goto LAB_002929f4;
        }
        if (param_2 != 0xd) goto LAB_002929f4;
      }
      if (bVar9 == 0xa9) {
        if (pbVar14[3] == 0x51) {
          puVar8 = &DAT_002bcda7;
          *(ushort *)(pbVar14 + 6) = uVar4;
          goto LAB_00292b84;
        }
      }
      else if (bVar9 == 0x51) {
        puVar8 = &DAT_002f6fea;
        *(ushort *)(pbVar14 + 1) = uVar4;
LAB_00292b84:
        _printk(puVar8,"dsi_panel_aod_backlight_update",*param_1,uVar5,uVar1);
      }
      else if (bVar9 == 0x6d) {
        pbVar14[1] = (byte)uVar2;
        _printk(&DAT_002e0f41,"dsi_panel_aod_backlight_update",*param_1,uVar1);
      }
    }
LAB_002929f4:
    puVar15 = puVar15 + 8;
    iVar13 = iVar13 + -1;
    if (iVar13 == 0) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// dsi_panel_apl_backlight_update @ 00292c14 size=256
// signature: undefined dsi_panel_apl_backlight_update(void)
//------------------------------------------------------------

void dsi_panel_apl_backlight_update(long param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  byte *pbVar6;
  undefined8 *puVar7;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = *(uint *)(param_1 + 0x7b0);
    uVar3 = (ulong)uVar1;
    if (uVar1 == 0) {
      _printk(&DAT_002b083e,"dsi_panel_apl_backlight_update","dsi_panel_apl_backlight_update");
    }
    else {
      iVar5 = *(int *)(param_2 + 8);
      if (iVar5 == 0) {
        drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: %s: apl commands count 0\n",
                       "dsi_panel_apl_backlight_update");
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + 0x5c0);
        puVar7 = (undefined8 *)(*(long *)(param_2 + 0x10) + 0x10);
        do {
          pbVar6 = (byte *)*puVar7;
          if (*(uint *)(param_1 + 0x7ac) == (uint)*pbVar6) {
            uVar4 = (ulong)(uVar1 + 1);
            if (*(uint *)(puVar7 + -1) < uVar1 + 1) {
              _printk(&DAT_002a6c71,"dsi_panel_apl_backlight_update",
                      "dsi_panel_apl_backlight_update");
              return;
            }
            pbVar6[uVar3] = (byte)((uint)uVar2 >> 8);
            pbVar6[uVar4] = (byte)uVar2;
            *(undefined1 *)(param_1 + 0x7aa) = 1;
            _printk(&DAT_002e9d7a,"dsi_panel_apl_backlight_update","dsi_panel_apl_backlight_update",
                    uVar3,pbVar6[uVar3],uVar4,pbVar6[uVar4]);
            return;
          }
          puVar7 = puVar7 + 8;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// dsi_panel_od_backlight_update @ 00292d18 size=140
// signature: undefined dsi_panel_od_backlight_update(void)
//------------------------------------------------------------

void dsi_panel_od_backlight_update(long param_1,long param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = *(int *)(param_2 + 8);
    if (iVar1 == 0) {
      drm_dev_printk(0,&DAT_002b5e64,"*ERROR* [msm-dsi-error]: %s: od commands count 0\n",
                     "dsi_panel_od_backlight_update");
    }
    else {
      puVar2 = (undefined8 *)(*(long *)(param_2 + 0x10) + 0x10);
      do {
        if (*(char *)*puVar2 == 'Q') {
          *(ushort *)((char *)*puVar2 + 1) =
               (ushort)(*(uint *)(param_1 + 0x5c0) >> 8) & 0xff |
               (ushort)((*(uint *)(param_1 + 0x5c0) & 0xff00ff) << 8);
          *(undefined1 *)(param_1 + 0x7f0) = 1;
          return;
        }
        puVar2 = puVar2 + 8;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}



//------------------------------------------------------------
// backlight_cdev_register @ 00297194 size=304
// signature: undefined backlight_cdev_register(void)
//------------------------------------------------------------

long backlight_cdev_register(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  
  lVar6 = -0x16;
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"delete-cooling-cells",0);
    if ((lVar6 == 0) &&
       (lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"#cooling-cells",0), lVar6 != 0))
    {
      lVar6 = devm_kmalloc(param_1,0x68,0xdc0);
      if (lVar6 == 0) {
        lVar6 = -0xc;
      }
      else {
        uVar1 = *(uint *)(param_2 + 4);
        lVar4 = *(long *)(param_2 + 0x120);
        uVar2 = *(undefined8 *)(param_1 + 0x2e8);
        *(long *)(lVar6 + 0x50) = param_2;
        *(undefined8 *)(lVar6 + 0x58) = 0;
        uVar5 = uVar1 / 0xff;
        if ((int)uVar1 < 0x100) {
          uVar5 = 1;
        }
        *(uint *)(lVar6 + 0x60) = uVar5;
        if (lVar4 == 0) {
          lVar4 = *(long *)(param_2 + 0xb0);
        }
        uVar3 = thermal_of_cooling_device_register(uVar2,lVar4,lVar6,&sde_cdev_ops);
        *(ulong *)(lVar6 + 0x48) = uVar3;
        if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
          _printk(&DAT_002ad17f);
          lVar6 = *(long *)(lVar6 + 0x48);
        }
        else {
          __init_rwsem(lVar6,"&(&disp_cdev->notifier_head)->rwsem",&backlight_cdev_register___key);
          *(undefined8 *)(lVar6 + 0x40) = 0;
          blocking_notifier_chain_register(lVar6,param_3);
        }
      }
    }
    else {
      lVar6 = -0x13;
    }
  }
  return lVar6;
}



//------------------------------------------------------------
// backlight_cdev_unregister @ 002972c8 size=36
// signature: undefined backlight_cdev_unregister(void)
//------------------------------------------------------------

void backlight_cdev_unregister(long param_1)

{
  if (param_1 != 0) {
    thermal_cooling_device_unregister(*(undefined8 *)(param_1 + 0x48));
  }
  return;
}



//------------------------------------------------------------
// msm_drm_bind @ 0029cd08 size=2800
// signature: undefined msm_drm_bind(void)
//------------------------------------------------------------

int msm_drm_bind(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  int iVar6;
  char cVar7;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  long *plVar13;
  ulong uVar14;
  char *pcVar15;
  ulong uVar16;
  long *plVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  ulong local_c8;
  long lStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar18 = sp_el0;
  local_68 = *(long *)(lVar18 + 0x638);
  lVar21 = *(long *)(param_1 + 0x98);
  lVar18 = *(long *)(lVar21 + 0x38);
  uVar12 = alloc_workqueue("msm_drm",0xa0002,1);
  *(undefined8 *)(lVar18 + 0x248) = uVar12;
  __init_waitqueue_head(lVar18 + 600,"&priv->pending_crtcs_event",&msm_drm_component_init___key);
  *(long *)(lVar18 + 0x14d8) = lVar18 + 0x14d8;
  *(long *)(lVar18 + 0x14e0) = lVar18 + 0x14d8;
  *(long *)(lVar18 + 0x208) = lVar18 + 0x208;
  *(long *)(lVar18 + 0x210) = lVar18 + 0x208;
  *(long *)(lVar18 + 0x1530) = lVar18 + 0x1530;
  *(long *)(lVar18 + 0x1538) = lVar18 + 0x1530;
  *(long *)(lVar18 + 0x1570) = lVar18 + 0x1570;
  *(long *)(lVar18 + 0x1578) = lVar18 + 0x1570;
  __mutex_init(lVar18 + 0x218,"&priv->mm_lock",&msm_drm_component_init___key_74);
  __mutex_init(lVar18 + 0x1500,"&priv->vm_client_lock",&msm_drm_component_init___key_76);
  __mutex_init(lVar18 + 0x1540,"&priv->fence_error_client_lock",&msm_drm_component_init___key_78);
  iVar10 = component_bind_all(param_1,lVar21);
  if (iVar10 != 0) {
    __drm_err("component_bind_all failed: %d\n",iVar10);
    if (iVar10 == -0x205) {
      destroy_workqueue(*(undefined8 *)(lVar18 + 0x248));
    }
    else {
      sde_dbg_destroy();
      sde_power_resource_deinit(param_1 + -0x10,lVar18 + 0x10);
      drm_dev_put(lVar21);
      kfree(lVar18);
    }
    goto LAB_0029d3e8;
  }
  lVar19 = *(long *)(lVar21 + 0x38);
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  lStack_c0 = 0;
  iVar10 = __of_parse_phandle_with_args
                     (*(undefined8 *)(*(long *)(lVar21 + 8) + 0x2e8),"memory-region",0,0,0,&local_c8
                     );
  uVar16 = local_c8;
  if ((iVar10 == 0) && (local_c8 != 0)) {
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_c8 = 0;
    lStack_c0 = 0;
    iVar10 = of_address_to_resource(uVar16,0,&local_c8);
    if (iVar10 == 0) {
      uVar16 = lStack_c0 - local_c8;
      _printk(&DAT_002c945e,uVar16,&local_c8);
      goto LAB_0029d714;
    }
  }
  else {
    uVar16 = iommu_present(&platform_bus_type);
    if ((uVar16 & 1) == 0) {
      local_c8 = local_c8 & 0xffffffff00000000;
      iVar10 = of_property_read_variable_u32_array
                         (*(undefined8 *)(*(long *)(lVar21 + 8) + 0x2e8),"qcom,vram-size",&local_c8,
                          1,0);
      if (iVar10 < 0) {
        uVar16 = memparse(vram,0);
      }
      else {
        uVar16 = local_c8 & 0xffffffff;
      }
      _printk(&DAT_002e1073,uVar16);
LAB_0029d714:
      if (uVar16 != 0) {
        *(ulong *)(lVar19 + 0x1368) = uVar16;
        drm_mm_init(lVar19 + 0x1378,0,(uVar16 >> 0xc) - 1);
        *(undefined4 *)(lVar19 + 0x1468) = 0;
        piVar5 = (int *)(lVar19 + 0x1370);
        lVar19 = dma_alloc_attrs(*(undefined8 *)(lVar21 + 8),uVar16,piVar5,0xcc0,0x14);
        if (lVar19 == 0) {
          _dev_err(*(undefined8 *)(lVar21 + 8),"[%s:%d] failed to allocate VRAM\n","msm_init_vram",
                   0x294);
          iVar10 = -0xc;
          piVar5[0] = 0;
          piVar5[1] = 0;
          goto LAB_0029d3e0;
        }
        _dev_info(*(undefined8 *)(lVar21 + 8),"VRAM: %08x->%08x\n",*piVar5,*piVar5 + (int)uVar16);
      }
    }
    *(undefined ***)(lVar21 + 0x3a8) = &mode_config_funcs;
    *(undefined ***)(lVar21 + 0x670) = &mode_config_helper_funcs;
    lVar19 = of_match_node(get_mdp_ver_match_types,*(undefined8 *)(param_1 + 0x2e8));
    if (lVar19 == 0) {
LAB_0029cfac:
      plVar13 = (long *)0x0;
LAB_0029d018:
      _dev_err(param_1,"[%s:%d] failed to load kms\n","_msm_drm_component_init_helper",0x32e);
    }
    else {
      if (*(int *)(lVar19 + 0xc0) != 3) {
        if (*(int *)(lVar19 + 0xc0) - 4U < 2) goto LAB_0029cfac;
        plVar13 = (long *)&DAT_ffffffffffffffed;
        goto LAB_0029d018;
      }
      plVar13 = (long *)sde_kms_init(lVar21);
      if ((plVar13 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar13)) goto LAB_0029d018;
      *(long **)(lVar18 + 8) = plVar13;
      *(undefined ***)(lVar21 + 0x3a8) = &mode_config_funcs;
      if (*(int *)(*(code **)*plVar13 + -4) != 0x48e7453) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x29cf6c);
        (*pcVar8)();
      }
      iVar10 = (**(code **)*plVar13)(plVar13);
      if (iVar10 != 0) {
        _dev_err(param_1,"[%s:%d] kms hw init failed: %d\n","_msm_drm_component_init_helper",0x33e,
                 iVar10);
        plVar13 = (long *)(long)iVar10;
      }
    }
    if ((plVar13 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar13)) {
      _dev_err(param_1,"[%s:%d] msm_drm_component_init_helper failed\n","msm_drm_component_init",
               0x3c1);
      iVar10 = 0;
    }
    else {
      if (*(int *)(lVar18 + 0x318) != 0) {
        lVar20 = 0;
        uVar16 = 0;
        lVar19 = lVar18 + 0xde0;
        do {
          if (lVar20 == 0x500) goto LAB_0029d7fc;
          lVar2 = lVar18 + uVar16 * 8;
          lVar3 = lVar18 + lVar20;
          lVar1 = lVar3 + 0x3b8;
          *(undefined4 *)(lVar3 + 0x3b0) = *(undefined4 *)(*(long *)(lVar2 + 800) + 0x70);
          __kthread_init_worker
                    (lVar1,"(&priv->disp_thread[i].worker)->lock",
                     &msm_drm_display_thread_create___key);
          *(long *)(lVar3 + 0x3a0) = lVar21;
          uVar14 = kthread_create_on_node
                             (&kthread_worker_fn,lVar1,0xffffffff,"crtc_commit:%d",
                              *(undefined4 *)(lVar3 + 0x3b0));
          if (uVar14 < 0xfffffffffffff001) {
            wake_up_process(uVar14);
          }
          *(ulong *)(lVar3 + 0x3a8) = uVar14;
          *(undefined8 *)(lVar18 + 0xdf8) = 0;
          *(undefined8 *)(lVar18 + 0xe00) = 0;
          *(long *)(lVar18 + 0xde0) = lVar18 + 0xde0;
          *(long *)(lVar18 + 0xde8) = lVar19;
          *(code **)(lVar18 + 0xdf0) = msm_drm_display_thread_priority_worker;
          kthread_queue_work(lVar1,lVar19);
          kthread_flush_work(lVar19);
          if (0xfffffffffffff000 < *(ulong *)(lVar3 + 0x3a8)) {
            _dev_err(param_1,"[%s:%d] failed to create crtc_commit kthread\n",
                     "msm_drm_display_thread_create",0x2c9);
            *(undefined8 *)(lVar3 + 0x3a8) = 0;
          }
          lVar4 = lVar18 + lVar20;
          lVar1 = lVar4 + 0x8b8;
          *(undefined4 *)(lVar4 + 0x8b0) = *(undefined4 *)(*(long *)(lVar2 + 800) + 0x70);
          __kthread_init_worker
                    (lVar1,"(&priv->event_thread[i].worker)->lock",
                     &msm_drm_display_thread_create___key_103);
          *(long *)(lVar4 + 0x8a0) = lVar21;
          uVar14 = kthread_create_on_node
                             (&kthread_worker_fn,lVar1,0xffffffff,"crtc_event:%d",
                              *(undefined4 *)(lVar4 + 0x8b0));
          if (uVar14 < 0xfffffffffffff001) {
            wake_up_process(uVar14);
          }
          *(ulong *)(lVar4 + 0x8a8) = uVar14;
          *(undefined8 *)(lVar18 + 0xdf8) = 0;
          *(undefined8 *)(lVar18 + 0xe00) = 0;
          *(long *)(lVar18 + 0xde0) = lVar18 + 0xde0;
          *(long *)(lVar18 + 0xde8) = lVar19;
          *(code **)(lVar18 + 0xdf0) = msm_drm_display_thread_priority_worker;
          kthread_queue_work(lVar1,lVar19);
          kthread_flush_work(lVar19);
          if (0xfffffffffffff000 < *(ulong *)(lVar4 + 0x8a8)) {
            _dev_err(param_1,"[%s:%d] failed to create crtc_event kthread\n",
                     "msm_drm_display_thread_create",0x2e2);
            *(undefined8 *)(lVar18 + lVar20 + 0x8a8) = 0;
LAB_0029d690:
            if (0xf < uVar16) {
LAB_0029d7fc:
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x29d800);
              (*pcVar8)();
            }
            lVar18 = lVar18 + lVar20;
            lVar21 = uVar16 + 1;
            do {
              if (*(long *)(lVar18 + 0x3a8) != 0) {
                kthread_stop();
                *(undefined8 *)(lVar18 + 0x3a8) = 0;
              }
              if (*(long *)(lVar18 + 0x8a8) != 0) {
                kthread_stop();
                *(undefined8 *)(lVar18 + 0x8a8) = 0;
              }
              lVar21 = lVar21 + -1;
              lVar18 = lVar18 + -0x50;
            } while (0 < lVar21);
            iVar10 = -0x16;
            goto LAB_0029d6e0;
          }
          if ((*(long *)(lVar3 + 0x3a8) == 0) || (*(ulong *)(lVar4 + 0x8a8) == 0))
          goto LAB_0029d690;
          uVar16 = uVar16 + 1;
          lVar20 = lVar20 + 0x50;
        } while (uVar16 < *(uint *)(lVar18 + 0x318));
      }
      lVar19 = lVar18 + 0xda8;
      __kthread_init_worker
                (lVar19,"(&priv->pp_event_worker)->lock",&msm_drm_display_thread_create___key_107);
      uVar16 = kthread_create_on_node(&kthread_worker_fn,lVar19,0xffffffff,"pp_event");
      if (uVar16 < 0xfffffffffffff001) {
        wake_up_process(uVar16);
      }
      *(ulong *)(lVar18 + 0xda0) = uVar16;
      lVar20 = lVar18 + 0xde0;
      *(undefined8 *)(lVar18 + 0xdf8) = 0;
      *(undefined8 *)(lVar18 + 0xe00) = 0;
      *(long *)(lVar18 + 0xde0) = lVar20;
      *(long *)(lVar18 + 0xde8) = lVar20;
      *(code **)(lVar18 + 0xdf0) = msm_drm_display_thread_priority_worker;
      kthread_queue_work(lVar19,lVar20);
      kthread_flush_work(lVar20);
      if (0xfffffffffffff000 < *(ulong *)(lVar18 + 0xda0)) {
        _dev_err(param_1,"[%s:%d] failed to create pp_event kthread\n",
                 "msm_drm_display_thread_create",0x307);
        iVar10 = *(int *)(lVar18 + 0xda0);
        *(undefined8 *)(lVar18 + 0xda0) = 0;
        if (iVar10 != 0) {
LAB_0029d6e0:
          _dev_err(param_1,"[%s:%d] msm_drm_display_thread_create failed\n","msm_drm_component_init"
                   ,0x3cb);
          goto LAB_0029d3e0;
        }
      }
      iVar10 = drm_vblank_init(lVar21,*(undefined4 *)(lVar18 + 0x318));
      if (iVar10 < 0) {
        _dev_err(param_1,"[%s:%d] failed to initialize vblank\n","msm_drm_component_init",0x3d1);
      }
      else {
        for (plVar17 = *(long **)(lVar21 + 0x368); plVar17 != (long *)(lVar21 + 0x368);
            plVar17 = (long *)*plVar17) {
          drm_crtc_vblank_reset(plVar17 + -2);
        }
        iVar10 = __pm_runtime_resume(param_1,4);
        if (iVar10 < 0) {
          piVar5 = (int *)(param_1 + 0x1f8);
          iVar11 = *(int *)(param_1 + 0x1f8);
          do {
            if (iVar11 == 0) break;
            Hint_Prefetch(piVar5,2,0,1);
            do {
              iVar6 = *piVar5;
              if (iVar6 != iVar11) goto LAB_0029d5d8;
              cVar7 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(piVar5,0x10);
              if (bVar9) {
                *piVar5 = iVar11 + -1;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            DataMemoryBarrier(2,3);
LAB_0029d5d8:
            bVar9 = iVar11 != iVar6;
            iVar11 = iVar6;
          } while (bVar9);
          pcVar15 = "[%s:%d] failed to enable power resource %d\n";
          uVar12 = 0x3db;
LAB_0029d624:
          _dev_err(param_1,pcVar15,"msm_drm_component_init",uVar12,iVar10);
        }
        else {
          iVar11 = platform_get_irq(param_1 + -0x10,0);
          if (iVar11 == -0x80000000) {
            __pm_runtime_idle(param_1,4);
            iVar10 = -0x6b;
LAB_0029d640:
            _dev_err(param_1,"[%s:%d] failed to install IRQ handler\n","msm_drm_component_init",
                     0x3e6);
          }
          else {
            plVar17 = *(long **)(*(long *)(lVar21 + 0x38) + 8);
            if (plVar17 == (long *)0x0) {
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x800,0x29d808);
              (*pcVar8)();
            }
            pcVar8 = *(code **)(*plVar17 + 0x10);
            if (*(int *)(pcVar8 + -4) != -0x6b131a6c) {
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x29d328);
              (*pcVar8)();
            }
            (*pcVar8)();
            iVar10 = request_threaded_irq
                               (iVar11,msm_irq,0,0,*(undefined8 *)(*(long *)(lVar21 + 0x30) + 0xa0),
                                lVar21);
            if (iVar10 == 0) {
              plVar17 = *(long **)(*(long *)(lVar21 + 0x38) + 8);
              if (plVar17 == (long *)0x0) {
                    /* WARNING: Does not return */
                pcVar8 = (code *)SoftwareBreakpoint(0x800,0x29d80c);
                (*pcVar8)();
              }
              pcVar8 = *(code **)(*plVar17 + 0x18);
              if (pcVar8 != (code *)0x0) {
                if (*(int *)(pcVar8 + -4) != 0x48e7453) {
                    /* WARNING: Does not return */
                  pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x29d39c);
                  (*pcVar8)();
                }
                iVar10 = (*pcVar8)();
                if (iVar10 != 0) {
                  free_irq(iVar11,lVar21);
                  goto LAB_0029d358;
                }
              }
              __pm_runtime_idle(param_1,4);
            }
            else {
LAB_0029d358:
              __pm_runtime_idle(param_1,4);
              if (iVar10 < 0) goto LAB_0029d640;
            }
            drm_mode_config_reset(lVar21);
            iVar10 = drm_dev_register(lVar21,0);
            if (iVar10 == 0) {
              *(undefined1 *)(lVar18 + 0x14e8) = 1;
              if ((*plVar13 != 0) && (pcVar8 = *(code **)(*plVar13 + 0x110), pcVar8 != (code *)0x0))
              {
                if (*(int *)(pcVar8 + -4) != 0x534c46c1) {
                    /* WARNING: Does not return */
                  pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x29d460);
                  (*pcVar8)();
                }
                iVar10 = (*pcVar8)(plVar13,0);
                if (iVar10 != 0) {
                  _dev_err(param_1,"[%s:%d] kms cont_splash config failed.\n",
                           "msm_drm_component_init",0x3f5);
                  goto LAB_0029d3e0;
                }
              }
              if (*(long *)(lVar18 + 0x1e8) == 0) {
                plVar17 = plVar13 + 3;
                iVar10 = drm_client_init(lVar21,plVar17,"kms_client",0);
                if (iVar10 != 0) {
                  __drm_err("failed to init kms_client: %d\n",iVar10);
                  *plVar17 = 0;
                  goto LAB_0029d3e0;
                }
                drm_client_register(plVar17);
              }
              iVar10 = sde_dbg_debugfs_register(param_1);
              if (iVar10 != 0) {
                pcVar15 = "[%s:%d] failed to reg sde dbg debugfs: %d\n";
                uVar12 = 0x40d;
                goto LAB_0029d624;
              }
              if ((*plVar13 != 0) && (pcVar8 = *(code **)(*plVar13 + 8), pcVar8 != (code *)0x0)) {
                if (*(int *)(pcVar8 + -4) != 0x48e7453) {
                    /* WARNING: Does not return */
                  pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x29d4a8);
                  (*pcVar8)();
                }
                iVar10 = (*pcVar8)(plVar13);
                if (iVar10 != 0) {
                  _printk(&DAT_002b3a26,iVar10);
                  goto LAB_0029d3e0;
                }
              }
              drm_kms_helper_poll_init(lVar21);
              *(undefined8 *)(lVar18 + 0x1588) = 0;
              *(code **)(lVar18 + 0x1580) = msm_drv_shutdown_notifier_cb;
              *(undefined4 *)(lVar18 + 0x1590) = 1;
              iVar10 = register_reboot_notifier(lVar18 + 0x1580);
              if (iVar10 == 0) goto LAB_0029d3e8;
              _dev_err(param_1,"Failed to register for reboot_notifier. ret = %d\n",iVar10);
            }
          }
        }
      }
    }
  }
LAB_0029d3e0:
  msm_drm_uninit(param_1);
LAB_0029d3e8:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar10;
}



//------------------------------------------------------------
// msm_drm_unbind @ 0029d810 size=28
// signature: undefined msm_drm_unbind(void)
//------------------------------------------------------------

void msm_drm_unbind(void)

{
  msm_drm_uninit();
  return;
}



//------------------------------------------------------------
// msm_drm_uninit @ 0029d8ac size=692
// signature: undefined msm_drm_uninit(void)
//------------------------------------------------------------

void msm_drm_uninit(long param_1)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar4 = *(long *)(lVar3 + 0x38);
  plVar5 = *(long **)(lVar4 + 8);
  __flush_workqueue(*(undefined8 *)(lVar4 + 0x248));
  __pm_runtime_resume(param_1,4);
  if (*(int *)(lVar4 + 0x318) != 0) {
    uVar7 = 0;
    lVar6 = lVar4 + 0x8b8;
    do {
      if (uVar7 == 0x10) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x29db60);
        (*pcVar2)();
      }
      plVar8 = (long *)(lVar6 + -0x510);
      if (*plVar8 != 0) {
        kthread_flush_worker(lVar6 + -0x500);
        kthread_stop(*plVar8);
        *plVar8 = 0;
      }
      if (*(long *)(lVar6 + -0x10) != 0) {
        kthread_flush_worker(lVar6);
        kthread_stop(*(undefined8 *)(lVar6 + -0x10));
        *(undefined8 *)(lVar6 + -0x10) = 0;
      }
      uVar7 = uVar7 + 1;
      lVar6 = lVar6 + 0x50;
    } while (uVar7 < *(uint *)(lVar4 + 0x318));
  }
  drm_kms_helper_poll_fini(lVar3);
  if ((plVar5 != (long *)0x0) && (*plVar5 != 0)) {
    pcVar2 = *(code **)(*plVar5 + 0x108);
    if (*(int *)(pcVar2 + -4) != -0x6b131a6c) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x29d990);
      (*pcVar2)();
    }
    (*pcVar2)(plVar5);
  }
  sde_dbg_destroy();
  debugfs_remove(*(undefined8 *)(lVar4 + 0x14f0));
  drm_mode_config_cleanup(lVar3);
  if (*(char *)(lVar4 + 0x14e8) != '\0') {
    drm_dev_unregister(lVar3);
    *(char *)(lVar4 + 0x14e8) = '\0';
  }
  if (*(long *)(lVar4 + 0x1580) != 0) {
    unregister_reboot_notifier((undefined8 *)(lVar4 + 0x1580));
    *(undefined8 *)(lVar4 + 0x1580) = 0;
  }
  drm_atomic_helper_shutdown(lVar3);
  plVar8 = *(long **)(*(long *)(lVar3 + 0x38) + 8);
  if (*(int *)(*(code **)(*plVar8 + 0x20) + -4) != -0x6b131a6c) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x29da18);
    (*pcVar2)();
  }
  (**(code **)(*plVar8 + 0x20))(plVar8);
  free_irq((int)plVar8[1],lVar3);
  if ((plVar5 != (long *)0x0) && (*plVar5 != 0)) {
    pcVar2 = *(code **)(*plVar5 + 0xe8);
    if (*(int *)(pcVar2 + -4) != -0x6b131a6c) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x29da54);
      (*pcVar2)();
    }
    (*pcVar2)(plVar5);
    *(undefined8 *)(lVar4 + 8) = 0;
  }
  if (*(long *)(lVar4 + 0x1370) != 0) {
    drm_mm_takedown(lVar4 + 0x1378);
    dma_free_attrs(param_1,*(undefined8 *)(lVar4 + 0x1368),0,*(undefined8 *)(lVar4 + 0x1370),0x10);
  }
  component_unbind_all(param_1,lVar3);
  __pm_runtime_idle(param_1,4);
  sde_power_resource_deinit(param_1 + -0x10,lVar4 + 0x10);
  mutex_lock(lVar4 + 0x1500);
  plVar5 = *(long **)(lVar4 + 0x1530);
  while (plVar5 != (long *)(lVar4 + 0x1530)) {
    plVar8 = (long *)*plVar5;
    uVar7 = __list_del_entry_valid(plVar5);
    if ((uVar7 & 1) != 0) {
      lVar6 = *plVar5;
      plVar1 = (long *)plVar5[1];
      *(long **)(lVar6 + 8) = plVar1;
      *plVar1 = lVar6;
    }
    *plVar5 = (long)&DAT_dead000000000100;
    plVar5[1] = -0x2152fffffffffede;
    kfree(plVar5 + -6);
    plVar5 = plVar8;
  }
  mutex_unlock(lVar4 + 0x1500);
  *(undefined8 *)(lVar3 + 0x38) = 0;
  destroy_workqueue(*(undefined8 *)(lVar4 + 0x248));
  kfree(lVar4);
  drm_dev_put(lVar3);
  return;
}



//------------------------------------------------------------
// msm_drm_display_thread_priority_worker @ 0029db94 size=140
// signature: undefined msm_drm_display_thread_priority_worker(void)
//------------------------------------------------------------

void msm_drm_display_thread_priority_worker(void)

{
  long lVar1;
  int iVar2;
  long lVar3;
  sched_param local_30 [2];
  long local_28;
  
  lVar3 = sp_el0;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(lVar1 + 0x670);
  local_30[0].__sched_priority = 0x10;
  iVar2 = sched_setscheduler((__pid_t)lVar3,1,local_30);
  if (iVar2 != 0) {
    _printk(&DAT_002a9dc4,*(undefined4 *)(lVar1 + 0x634),lVar3 + 0x848,iVar2);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// backlight_device_set_brightness @ 00333dc8 size=1
// signature: undefined backlight_device_set_brightness(void)
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void backlight_device_set_brightness(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// backlight_device_unregister @ 00333dd0 size=1
// signature: undefined backlight_device_unregister(void)
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void backlight_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// backlight_device_register @ 00333df0 size=1
// signature: undefined backlight_device_register(void)
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void backlight_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// backlight_device_get_by_type @ 00334230 size=1
// signature: undefined backlight_device_get_by_type(void)
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void backlight_device_get_by_type(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



