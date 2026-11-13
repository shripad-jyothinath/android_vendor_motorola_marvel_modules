// Decompiled by Ghidra 12.2
// Program: socinfo.ko
// Image base: 00100000

//------------------------------------------------------------
// socinfo_get_id @ 00100c84 size=28
// signature: undefined socinfo_get_id(void)
// callers: []
//------------------------------------------------------------

undefined4 socinfo_get_id(void)

{
  if (socinfo == 0) {
    return 0;
  }
  return *(undefined4 *)(socinfo + 4);
}



//------------------------------------------------------------
// socinfo_get_id_string @ 00100ca4 size=72
// signature: undefined socinfo_get_id_string(void)
// callers: []
//------------------------------------------------------------

undefined8 socinfo_get_id_string(void)

{
  int iVar1;
  long lVar2;
  
  iVar1 = 0;
  if (socinfo != 0) {
    iVar1 = *(int *)(socinfo + 4);
  }
  lVar2 = 0;
  do {
    if (*(int *)((long)&soc_id + lVar2) == iVar1) {
      return *(undefined8 *)(&UNK_00103c30 + lVar2);
    }
    lVar2 = lVar2 + 0x10;
  } while (lVar2 != 0xae0);
  return 0;
}



//------------------------------------------------------------
// socinfo_get_serial_number @ 00100cf0 size=28
// signature: undefined socinfo_get_serial_number(void)
// callers: []
//------------------------------------------------------------

undefined4 socinfo_get_serial_number(void)

{
  if (socinfo == 0) {
    return 0;
  }
  return *(undefined4 *)(socinfo + 0x60);
}



//------------------------------------------------------------
// socinfo_get_feature_code @ 00100d10 size=96
// signature: undefined socinfo_get_feature_code(void)
// callers: []
//------------------------------------------------------------

int socinfo_get_feature_code(void)

{
  int iVar1;
  
  if (socinfo_format < 0x10) {
    _printk(&DAT_00105cd4);
    iVar1 = -0x16;
  }
  else if (socinfo == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (0xfffffeff < *(int *)(socinfo + 0xb0) - 0x101U) {
      iVar1 = *(int *)(socinfo + 0xb0);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// socinfo_get_pcode @ 00100d74 size=108
// signature: undefined socinfo_get_pcode(void)
// callers: []
//------------------------------------------------------------

int socinfo_get_pcode(void)

{
  int iVar1;
  
  if (socinfo_format < 0x10) {
    _printk(&DAT_00105f3b);
    iVar1 = -0x16;
  }
  else if (socinfo == 0) {
    iVar1 = 0x7fffffff;
  }
  else {
    iVar1 = 0;
    if (0x80000001 < *(int *)(socinfo + 0xb4) + 0x80000001U) {
      iVar1 = *(int *)(socinfo + 0xb4);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// socinfo_get_partinfo_part_name @ 00100de4 size=40
// signature: undefined socinfo_get_partinfo_part_name(void)
// callers: []
//------------------------------------------------------------

undefined8 socinfo_get_partinfo_part_name(uint param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0x1056d4;
  if (param_1 != 1) {
    uVar1 = 0;
  }
  uVar2 = 0;
  if (0xf < socinfo_format && param_1 < 0x11) {
    uVar2 = uVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// socinfo_get_partinfo_chip_id @ 00100e10 size=40
// signature: undefined socinfo_get_partinfo_chip_id(void)
// callers: []
//------------------------------------------------------------

undefined4 socinfo_get_partinfo_chip_id(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = partinfo._48_4_;
  if (param_1 != 1) {
    uVar1 = 0;
  }
  uVar2 = 0;
  if (0xf < socinfo_format && param_1 < 0x11) {
    uVar2 = uVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// socinfo_get_partinfo_vulkan_id @ 00100e3c size=32
// signature: undefined socinfo_get_partinfo_vulkan_id(void)
// callers: []
//------------------------------------------------------------

undefined4 socinfo_get_partinfo_vulkan_id(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0xf < socinfo_format && param_1 == 1) {
    uVar1 = partinfo._52_4_;
  }
  return uVar1;
}



//------------------------------------------------------------
// socinfo_get_cluster_info @ 00100e60 size=96
// signature: undefined socinfo_get_cluster_info(void)
// callers: []
//------------------------------------------------------------

undefined4 socinfo_get_cluster_info(int param_1)

{
  if (param_1 == 0) {
    if ((socinfo != 0 && 0xd < socinfo_format) &&
       (*(int *)(socinfo + 0x9c) != 0 && *(uint *)(socinfo + 0xa0) != 0)) {
      return *(undefined4 *)(socinfo + (ulong)*(uint *)(socinfo + 0xa0));
    }
  }
  else {
    _printk(&DAT_001066fb);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// socinfo_get_part_info @ 00100ec4 size=284
// signature: undefined socinfo_get_part_info(void)
// callers: []
//------------------------------------------------------------

uint socinfo_get_part_info(ulong param_1)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  
  if ((socinfo != 0 && 0xd < socinfo_format) && ((uint)param_1 - 1 < 0x10)) {
    uVar3 = *(uint *)(socinfo + 0xa4);
    if ((uint)param_1 < uVar3) {
      if (*(uint *)(socinfo + 0xa8) == 0) {
        uVar5 = 0xffffffea;
      }
      else {
        pbVar7 = (byte *)(socinfo + (ulong)*(uint *)(socinfo + 0xa8));
        if (1 < uVar3) {
          uVar6 = (ulong)uVar3 & 0xfffffffe;
          uVar5 = 0;
          uVar8 = 0;
          uVar9 = 0;
          do {
            lVar1 = uVar5 * 4;
            uVar2 = uVar5 + 1;
            uVar4 = uVar5 & 0x3f;
            uVar5 = uVar5 + 2;
            uVar8 = -(*(uint *)(pbVar7 + lVar1) & 1) & (uint)(1L << uVar4) | uVar8;
            uVar9 = -((byte)*(uint *)((long)(pbVar7 + lVar1) + 4) & 1) &
                    (uint)(1L << (uVar2 & 0x3f)) | uVar9;
          } while (uVar5 != uVar6);
          uVar9 = uVar9 | uVar8;
          pbVar7 = pbVar7 + uVar6 * 4;
          goto joined_r0x00100f8c;
        }
        uVar6 = 0;
        uVar9 = 0;
        do {
          uVar5 = uVar6 & 0x3f;
          uVar6 = uVar6 + 1;
          uVar9 = -(*pbVar7 & 1) & (uint)(1L << uVar5) | uVar9;
          pbVar7 = pbVar7 + 4;
joined_r0x00100f8c:
        } while (uVar6 != uVar3);
        uVar5 = (ulong)uVar9;
      }
      return (uint)(uVar5 >> (param_1 & 0x3f)) & 1;
    }
  }
  _printk(&DAT_001067e2);
  return 0;
}



//------------------------------------------------------------
// socinfo_get_part_count @ 00100fe4 size=100
// signature: undefined socinfo_get_part_count(void)
// callers: []
//------------------------------------------------------------

undefined8 socinfo_get_part_count(uint param_1)

{
  undefined8 uVar1;
  
  if (((socinfo == 0 || socinfo_format < 0xe) || (0xf < param_1 - 1)) ||
     (*(uint *)(socinfo + 0xa4) <= param_1)) {
    _printk(&DAT_001067e2);
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// socinfo_get_subpart_info @ 0010104c size=152
// signature: undefined socinfo_get_subpart_info(void)
// callers: []
//------------------------------------------------------------

undefined8 socinfo_get_subpart_info(uint param_1,undefined4 *param_2,int param_3)

{
  long lVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    if (((socinfo == 0 || socinfo_format < 0xe) || (0xf < param_1 - 1)) ||
       (*(uint *)(socinfo + 0xa4) <= param_1)) {
      _printk(&DAT_001067e2);
    }
    else {
      lVar1 = 0xdc;
      if (socinfo_format < 0x15) {
        lVar1 = 0xa8;
      }
      if (*(uint *)(socinfo + lVar1) != 0) {
        if (param_3 == 0) {
          return 0;
        }
        *param_2 = *(undefined4 *)(socinfo + (ulong)*(uint *)(socinfo + lVar1) + (ulong)param_1 * 4)
        ;
        return 0;
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// socinfo_enumerate_partinfo_details @ 001010e8 size=240
// signature: undefined socinfo_enumerate_partinfo_details(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

void socinfo_enumerate_partinfo_details(void)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  uint *puVar5;
  
  if (0xf < socinfo_format) {
    uVar4 = *(uint *)(socinfo + 0xbc);
    if (uVar4 < 0x12) {
      if (uVar4 != 0) {
        puVar5 = (uint *)(socinfo + (ulong)*(uint *)(socinfo + 0xb8));
        do {
          uVar1 = *puVar5;
          if (0x11 < (int)uVar1) {
            _printk(&DAT_0010653f);
LAB_001011d0:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1011d4);
            (*pcVar3)();
          }
          if (0x10 < uVar1) goto LAB_001011d0;
          if (0x2ec < (ulong)uVar1 * 0x2c) {
LAB_001011d4:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x1011d8);
            (*pcVar3)();
          }
          lVar2 = (ulong)uVar1 * 0x2c;
          *(uint *)(partinfo + lVar2) = uVar1;
          if ((0x2e8 < (ulong)uVar1 * 0x2c) ||
             (*(uint *)(partinfo + lVar2 + 4) = puVar5[1], 0x2e4 < (ulong)uVar1 * 0x2c))
          goto LAB_001011d4;
          *(uint *)(partinfo + lVar2 + 8) = puVar5[2];
          strscpy(lVar2 + 0x1056a8,puVar5 + 3,0x20);
          uVar4 = uVar4 - 1;
          puVar5 = puVar5 + 0xb;
        } while (uVar4 != 0);
      }
    }
    else {
      _printk(&DAT_00105e0a);
    }
  }
  return;
}



//------------------------------------------------------------
// qcom_socinfo_probe @ 001011dc size=2596
// signature: undefined qcom_socinfo_probe(void)
// callers: []
//------------------------------------------------------------

void qcom_socinfo_probe(long param_1)

{
  code *pcVar1;
  uint *puVar2;
  ulong *puVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined *puVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  undefined **ppuVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  ulong local_78 [3];
  
  lVar5 = sp_el0;
  local_78[2] = *(long *)(lVar5 + 0x638);
  local_78[0] = 0;
  puVar2 = (uint *)qcom_smem_get(0xffffffff,0x89,local_78);
  if ((uint *)0xfffffffffffff000 < puVar2) {
    _dev_err(param_1 + 0x10,"Couldn\'t find socinfo\n");
    uVar10 = (ulong)puVar2 & 0xffffffff;
    goto LAB_00101b9c;
  }
  lVar5 = param_1 + 0x10;
  socinfo_format = *puVar2;
  socinfo = puVar2;
  puVar3 = (ulong *)devm_kmalloc(lVar5,0xa8,0xdc0);
  if (puVar3 == (ulong *)0x0) {
LAB_00101364:
    uVar10 = 0xfffffff4;
    goto LAB_00101b9c;
  }
  lVar9 = 0;
  puVar3[2] = (ulong)"Snapdragon";
  do {
    if (*(uint *)((long)&soc_id + lVar9) == puVar2[1]) {
      uVar10 = *(ulong *)(&UNK_00103c30 + lVar9);
      goto LAB_001012a8;
    }
    lVar9 = lVar9 + 0x10;
  } while (lVar9 != 0xae0);
  uVar10 = 0;
LAB_001012a8:
  puVar3[1] = uVar10;
  uVar10 = devm_kasprintf(lVar5,0xcc0,&DAT_00105e4d,puVar2[1]);
  puVar3[5] = uVar10;
  uVar4 = devm_kasprintf(lVar5,0xcc0,"%u.%u",puVar2[2] >> 0x10,puVar2[2] & 0xffff);
  uVar10 = 0xfffffff4;
  puVar3[3] = uVar4;
  if ((puVar3[5] == 0) || (uVar4 == 0)) goto LAB_00101b9c;
  if (99 < local_78[0]) {
    uVar10 = devm_kasprintf(lVar5,0xcc0,&DAT_00105e4d,puVar2[0x18]);
    puVar3[4] = uVar10;
    if (uVar10 == 0) goto LAB_00101364;
  }
  if (0xf < socinfo_format) {
    socinfo_enumerate_partinfo_details(uVar10);
    lVar9 = 0;
    do {
      if (*(uint *)((long)&soc_id + lVar9) == puVar2[1]) {
        uVar6 = *(undefined8 *)(&UNK_00103c30 + lVar9);
        goto LAB_00101374;
      }
      lVar9 = lVar9 + 0x10;
    } while (lVar9 != 0xae0);
    uVar6 = 0;
LAB_00101374:
    puVar7 = (undefined *)0x0;
    uVar11 = 0x7fffffff;
    if ((socinfo != (uint *)0x0) && (0xf < socinfo_format)) {
      uVar11 = 0;
      if (0xfffffeff < socinfo[0x2c] - 0x101) {
        uVar11 = socinfo[0x2c];
      }
      uVar10 = (ulong)uVar11;
      if (uVar11 - 1 < 8) {
        ppuVar12 = &hw_platform_feature_code + uVar10;
        uVar4 = 0x48;
LAB_00101414:
        if (uVar4 <= uVar10 * 8) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x101c00);
          (*pcVar1)();
        }
        puVar7 = *ppuVar12;
      }
      else {
        uVar10 = (ulong)(uVar11 - 0xd1);
        if (uVar11 - 0xd1 < 0x10) {
          ppuVar12 = &hw_platform_wfeature_code + uVar10;
          uVar4 = 0x80;
          goto LAB_00101414;
        }
        uVar10 = (ulong)(uVar11 - 0xf1);
        if (0xf0 < uVar11) {
          ppuVar12 = &hw_platform_ifeature_code + uVar10;
          uVar4 = 0x80;
          goto LAB_00101414;
        }
        puVar7 = (undefined *)0x0;
      }
      uVar11 = 0;
      if (0x80000001 < socinfo[0x2d] + 0x80000001) {
        uVar11 = socinfo[0x2d];
      }
    }
    sku = devm_kasprintf(lVar5,0xcc0,"%s-%u-%s",uVar6,uVar11,puVar7);
  }
  uVar8 = 0;
  uVar11 = 0;
  uVar13 = 0;
  uVar14 = 0;
  uVar15 = 0;
  uVar16 = 0;
  uVar10 = 0;
  switch(socinfo_format) {
  case 1:
  case 2:
    break;
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x17:
    msm_custom_socinfo_attrs = &dev_attr_sku;
    DAT_00105998 = &dev_attr_feature_code;
    uVar8 = 3;
    DAT_001059a0 = &dev_attr_pcode;
  case 0xe:
  case 0xf:
    (&msm_custom_socinfo_attrs)[uVar8 + 1] = &dev_attr_ncluster_array_offset;
    (&msm_custom_socinfo_attrs)[uVar8 + 2] = &dev_attr_num_subset_parts;
    (&msm_custom_socinfo_attrs)[uVar8 + 3] = &dev_attr_nsubset_parts_array_offset;
    (&msm_custom_socinfo_attrs)[uVar8 | 4] = &dev_attr_subset_cores;
    (&msm_custom_socinfo_attrs)[uVar8 + 5] = &dev_attr_subset_parts;
    (&msm_custom_socinfo_attrs)[uVar8 + 6] = &dev_attr_gpu;
    (&msm_custom_socinfo_attrs)[uVar8 + 7] = &dev_attr_video;
    (&msm_custom_socinfo_attrs)[uVar8 | 8] = &dev_attr_camera;
    (&msm_custom_socinfo_attrs)[uVar8 + 9] = &dev_attr_display;
    (&msm_custom_socinfo_attrs)[uVar8 + 10] = &dev_attr_audio;
    (&msm_custom_socinfo_attrs)[uVar8 + 0xb] = &dev_attr_modem;
    (&msm_custom_socinfo_attrs)[uVar8 | 0xc] = &dev_attr_wlan;
    (&msm_custom_socinfo_attrs)[uVar8 + 0xd] = &dev_attr_comp;
    (&msm_custom_socinfo_attrs)[uVar8 + 0xe] = &dev_attr_sensors;
    (&msm_custom_socinfo_attrs)[uVar8 + 0xf] = &dev_attr_npu;
    (&msm_custom_socinfo_attrs)[uVar8 | 0x10] = &dev_attr_spss;
    (&msm_custom_socinfo_attrs)[uVar8 + 0x11] = &dev_attr_nav;
    (&msm_custom_socinfo_attrs)[uVar8 + 0x12] = &dev_attr_comp1;
    (&msm_custom_socinfo_attrs)[uVar8 + 0x13] = &dev_attr_display1;
    (&msm_custom_socinfo_attrs)[uVar8] = &dev_attr_num_clusters;
    uVar11 = uVar8 + 0x16;
    (&msm_custom_socinfo_attrs)[uVar8 | 0x14] = &dev_attr_nsp;
    (&msm_custom_socinfo_attrs)[uVar8 + 0x15] = &dev_attr_eva;
  case 0xd:
    uVar13 = uVar11 + 1;
    (&msm_custom_socinfo_attrs)[uVar11] = &dev_attr_chip_id;
  case 0xc:
    uVar14 = uVar13 + 1;
    (&msm_custom_socinfo_attrs)[uVar13] = &dev_attr_chip_family;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
    uVar15 = uVar14 + 2;
    (&msm_custom_socinfo_attrs)[uVar14] = &dev_attr_platform_subtype_id;
    (&msm_custom_socinfo_attrs)[uVar14 + 1] = &dev_attr_platform_subtype;
  case 4:
  case 5:
    uVar16 = uVar15 + 1;
    (&msm_custom_socinfo_attrs)[uVar15] = &dev_attr_platform_version;
  case 3:
    uVar10 = (ulong)(uVar16 + 1);
    (&msm_custom_socinfo_attrs)[uVar16] = &dev_attr_hw_platform;
    break;
  default:
    _printk(&DAT_00105c4e,socinfo_format >> 0x10,socinfo_format & 0xffff);
    uVar10 = 0;
  }
  (&msm_custom_socinfo_attrs)[uVar10] = (undefined **)0x0;
  puVar3[7] = (ulong)custom_soc_attr_group;
  uVar10 = soc_device_register(puVar3 + 1);
  uVar4 = local_78[0];
  *puVar3 = uVar10;
  if (uVar10 < 0xfffffffffffff001) {
    local_78[1] = 0;
    uVar10 = debugfs_create_dir("qcom_socinfo",0);
    puVar3[8] = uVar10;
    puVar17 = (uint *)((long)puVar3 + 0x6c);
    *puVar17 = *puVar2;
    debugfs_create_x32("info_fmt",0x124,uVar10,puVar17);
    switch(*puVar17) {
    case 0x14:
    case 0x15:
    case 0x17:
      *(uint *)(puVar3 + 0x14) = puVar2[0x36];
      debugfs_create_u32("raw_package_type",0x124,puVar3[8]);
    case 0x13:
      *(uint *)((long)puVar3 + 0x94) = puVar2[0x33];
      *(uint *)(puVar3 + 0x13) = puVar2[0x34];
      *(uint *)((long)puVar3 + 0x9c) = puVar2[0x35];
      debugfs_create_u32("num_func_clusters",0x124,puVar3[8]);
      debugfs_create_u32("boot_cluster",0x124,puVar3[8],puVar3 + 0x13);
      debugfs_create_u32("boot_core",0x124,puVar3[8],(uint *)((long)puVar3 + 0x9c));
    case 0x11:
    case 0x12:
      *(uint *)(puVar3 + 0x12) = puVar2[0x30];
      debugfs_create_u32("oem_variant",0x124,puVar3[8]);
    case 0x10:
      *(uint *)(puVar3 + 0x11) = puVar2[0x2c];
      *(uint *)((long)puVar3 + 0x8c) = puVar2[0x2d];
      debugfs_create_u32("feature_code",0x124,puVar3[8]);
      debugfs_create_u32("pcode",0x124,puVar3[8],(uint *)((long)puVar3 + 0x8c));
    case 0xf:
      *(uint *)((long)puVar3 + 0x84) = puVar2[0x2b];
      debugfs_create_u32("nmodem_supported",0x124,puVar3[8]);
    case 0xe:
      *(uint *)((long)puVar3 + 0x74) = puVar2[0x27];
      *(uint *)(puVar3 + 0xf) = puVar2[0x28];
      *(uint *)((long)puVar3 + 0x7c) = puVar2[0x29];
      *(uint *)(puVar3 + 0x10) = puVar2[0x2a];
      debugfs_create_u32("num_clusters",0x124,puVar3[8]);
      debugfs_create_u32("ncluster_array_offset",0x124,puVar3[8],puVar3 + 0xf);
      debugfs_create_u32("num_subset_parts",0x124,puVar3[8],(uint *)((long)puVar3 + 0x7c));
      debugfs_create_u32("nsubset_parts_array_offset",0x124,puVar3[8],puVar3 + 0x10);
    case 0xd:
      *(uint *)(puVar3 + 0xe) = puVar2[0x1e];
      debugfs_create_u32("nproduct_id",0x124,puVar3[8],puVar3 + 0xe);
      debugfs_create_file("chip_id",0x124,puVar3[8],puVar2,qcom_chip_id_ops);
    case 0xc:
      *(uint *)(puVar3 + 0xb) = puVar2[0x1b];
      *(uint *)(puVar3 + 9) = puVar2[0x1c];
      *(uint *)((long)puVar3 + 0x54) = puVar2[0x1d];
      debugfs_create_x32("chip_family",0x124,puVar3[8]);
      debugfs_create_x32("raw_device_family",0x124,puVar3[8],puVar3 + 9);
      debugfs_create_x32("raw_device_number",0x124,puVar3[8],(uint *)((long)puVar3 + 0x54));
    case 0xb:
      if ((ulong)puVar2[0x1a] + (ulong)(puVar2[0x19] << 1) * 4 <= uVar4) {
        debugfs_create_file("pmic_model_array",0x124,puVar3[8],puVar2,qcom_pmic_model_array_ops);
      }
    case 9:
    case 10:
      *(uint *)((long)puVar3 + 0x5c) = puVar2[0x17];
      debugfs_create_u32("foundry_id",0x124,puVar3[8]);
    case 7:
    case 8:
      debugfs_create_file("pmic_model",0x124,puVar3[8],puVar2,qcom_pmic_model_ops);
      debugfs_create_file("pmic_die_rev",0x124,puVar3[8],puVar2,qcom_pmic_die_rev_ops);
    case 6:
      *(uint *)((long)puVar3 + 0x4c) = puVar2[0x10];
      debugfs_create_u32("hardware_platform_subtype",0x124,puVar3[8]);
    case 5:
      *(uint *)(puVar3 + 10) = puVar2[0xf];
      debugfs_create_u32("accessory_chip",0x124,puVar3[8]);
    case 4:
      *(uint *)(puVar3 + 0xc) = puVar2[0xe];
      debugfs_create_u32("platform_version",0x124,puVar3[8]);
    case 3:
      *(uint *)(puVar3 + 0xd) = puVar2[0xd];
      debugfs_create_u32("hardware_platform",0x124,puVar3[8]);
    case 2:
      *(uint *)((long)puVar3 + 100) = puVar2[0xc];
      debugfs_create_u32("raw_version",0x124,puVar3[8]);
    case 1:
      debugfs_create_file("build_id",0x124,puVar3[8],puVar2,qcom_build_id_ops);
    default:
      lVar5 = qcom_smem_get(0xffffffff,0x1d5,local_78 + 1);
      uVar10 = 0;
      do {
        if ((0x603f4U >> (uVar10 & 0x3f) & 1) == 0) {
          uVar6 = debugfs_create_dir((&socinfo_image_names)[uVar10],puVar3[8]);
          debugfs_create_file(&DAT_00105f31,0x124,uVar6,lVar5,qcom_image_name_ops);
          debugfs_create_file("variant",0x124,uVar6,lVar5,qcom_image_variant_ops);
          debugfs_create_file(&DAT_00106644,0x124,uVar6,lVar5,qcom_image_oem_ops);
        }
        uVar10 = uVar10 + 1;
        lVar5 = lVar5 + 0x80;
      } while (uVar10 != 0x16);
      add_device_randomness(puVar2,local_78[0]);
      uVar10 = 0;
      *(ulong **)(param_1 + 0xa8) = puVar3;
    }
  }
LAB_00101b9c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_78[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// qcom_socinfo_remove @ 00101c04 size=56
// signature: undefined qcom_socinfo_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_socinfo_remove(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  soc_device_unregister(*puVar1);
  debugfs_remove(puVar1[8]);
  return 0;
}



//------------------------------------------------------------
// msm_get_sku @ 00101c40 size=68
// signature: undefined msm_get_sku(void)
// callers: []
//------------------------------------------------------------

long msm_get_sku(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = "Unknown";
  if (sku != (char *)0x0) {
    pcVar1 = sku;
  }
  iVar2 = sysfs_emit(param_3,&DAT_001063df,pcVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// msm_get_feature_code @ 00101c88 size=236
// signature: undefined msm_get_feature_code(void)
// callers: []
//------------------------------------------------------------

long msm_get_feature_code(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  char *pcVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  ulong uVar6;
  undefined **ppuVar7;
  
  if (socinfo == 0 || socinfo_format < 0x10) {
LAB_00101cb0:
    pcVar5 = (char *)0x0;
  }
  else {
    uVar1 = 0;
    if (0xfffffeff < *(uint *)(socinfo + 0xb0) - 0x101) {
      uVar1 = *(uint *)(socinfo + 0xb0);
    }
    uVar6 = (ulong)uVar1;
    if (uVar1 - 1 < 8) {
      ppuVar7 = &hw_platform_feature_code + uVar6;
      if (0x48 < uVar6 * 8 || uVar6 * -8 == -0x48) {
LAB_00101d4c:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x101d50);
        (*pcVar3)();
      }
    }
    else {
      uVar6 = (ulong)(uVar1 - 0xd1);
      if (uVar1 - 0xd1 < 0x10) {
        ppuVar7 = &hw_platform_wfeature_code + uVar6;
        if (0x80 < uVar6 * 8 || uVar6 * -8 == -0x80) goto LAB_00101d4c;
      }
      else {
        uVar6 = (ulong)(uVar1 - 0xf1);
        if (uVar1 < 0xf1) goto LAB_00101cb0;
        ppuVar7 = &hw_platform_ifeature_code + uVar6;
        if (0x80 < uVar6 * 8 || uVar6 * -8 == -0x80) goto LAB_00101d4c;
      }
    }
    pcVar5 = *ppuVar7;
  }
  pcVar2 = "Unknown";
  if (pcVar5 != (char *)0x0) {
    pcVar2 = pcVar5;
  }
  iVar4 = sysfs_emit(param_3,&DAT_001063df,pcVar2);
  return (long)iVar4;
}



//------------------------------------------------------------
// msm_get_pcode @ 00101d78 size=112
// signature: undefined msm_get_pcode(void)
// callers: []
//------------------------------------------------------------

long msm_get_pcode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  if (socinfo == 0 || socinfo_format < 0x10) {
    iVar1 = 0x7fffffff;
  }
  else {
    iVar1 = 0;
    if (0x80000001 < *(int *)(socinfo + 0xb4) + 0x80000001U) {
      iVar1 = *(int *)(socinfo + 0xb4);
    }
  }
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",iVar1);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_num_clusters @ 00101dec size=88
// signature: undefined msm_get_num_clusters(void)
// callers: []
//------------------------------------------------------------

long msm_get_num_clusters(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 0xe) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0x9c);
  }
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_ncluster_array_offset @ 00101e48 size=88
// signature: undefined msm_get_ncluster_array_offset(void)
// callers: []
//------------------------------------------------------------

long msm_get_ncluster_array_offset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 0xe) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0xa0);
  }
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_num_subset_parts @ 00101ea4 size=88
// signature: undefined msm_get_num_subset_parts(void)
// callers: []
//------------------------------------------------------------

long msm_get_num_subset_parts(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 0xe) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0xa4);
  }
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_nsubset_parts_array_offset @ 00101f00 size=88
// signature: undefined msm_get_nsubset_parts_array_offset(void)
// callers: []
//------------------------------------------------------------

long msm_get_nsubset_parts_array_offset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 0xe) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0xa8);
  }
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_subset_cores @ 00101f5c size=104
// signature: undefined msm_get_subset_cores(void)
// callers: []
//------------------------------------------------------------

long msm_get_subset_cores(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((socinfo == 0 || socinfo_format < 0xe) ||
     (*(int *)(socinfo + 0x9c) == 0 || *(uint *)(socinfo + 0xa0) == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + (ulong)*(uint *)(socinfo + 0xa0));
  }
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106442,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_subset_parts @ 00101fc8 size=260
// signature: undefined msm_get_subset_parts(void)
// callers: []
//------------------------------------------------------------

long msm_get_subset_parts(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  byte *pbVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  
  if (socinfo != 0 && 0xd < socinfo_format) {
    uVar9 = *(uint *)(socinfo + 0xa4);
    uVar4 = (ulong)uVar9;
    if (uVar9 != 0 && *(uint *)(socinfo + 0xa8) != 0) {
      pbVar3 = (byte *)(socinfo + (ulong)*(uint *)(socinfo + 0xa8));
      if (uVar9 < 2) {
        uVar7 = 0;
        uVar10 = 0;
        pbVar8 = pbVar3;
      }
      else {
        uVar7 = uVar4 & 0xfffffffe;
        uVar11 = 0;
        uVar9 = 0;
        uVar10 = 0;
        pbVar8 = pbVar3 + uVar7 * 4;
        do {
          lVar1 = uVar11 * 4;
          uVar2 = uVar11 + 1;
          uVar5 = uVar11 & 0x3f;
          uVar11 = uVar11 + 2;
          uVar9 = -(*(uint *)(pbVar3 + lVar1) & 1) & (uint)(1L << uVar5) | uVar9;
          uVar10 = -((byte)*(uint *)((long)(pbVar3 + lVar1) + 4) & 1) & (uint)(1L << (uVar2 & 0x3f))
                   | uVar10;
        } while (uVar11 != uVar7);
        uVar10 = uVar10 | uVar9;
        if (uVar7 == uVar4) goto LAB_00102008;
      }
      do {
        uVar11 = uVar7 & 0x3f;
        uVar7 = uVar7 + 1;
        uVar10 = -(*pbVar8 & 1) & (uint)(1L << uVar11) | uVar10;
        pbVar8 = pbVar8 + 4;
      } while (uVar4 != uVar7);
      goto LAB_00102008;
    }
  }
  uVar10 = 0xffffffea;
LAB_00102008:
  iVar6 = scnprintf(param_3,0x1000,&DAT_00106442,uVar10);
  return (long)iVar6;
}



//------------------------------------------------------------
// msm_get_gpu @ 001020d0 size=292
// signature: undefined msm_get_gpu(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_gpu(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 2)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 2)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 4);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_video @ 001021f8 size=292
// signature: undefined msm_get_video(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_video(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 3)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 3)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 8);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_camera @ 00102320 size=292
// signature: undefined msm_get_camera(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_camera(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 4)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 4)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0xc);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_display @ 00102448 size=292
// signature: undefined msm_get_display(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_display(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 5)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 5)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x10);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_audio @ 00102570 size=292
// signature: undefined msm_get_audio(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_audio(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 6)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 6)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x14);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_modem @ 00102698 size=292
// signature: undefined msm_get_modem(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_modem(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 7)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 7)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x18);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_wlan @ 001027c0 size=292
// signature: undefined msm_get_wlan(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_wlan(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 8)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 8)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x1c);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_comp @ 001028e8 size=292
// signature: undefined msm_get_comp(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_comp(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 9)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 9)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x20);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_sensors @ 00102a10 size=292
// signature: undefined msm_get_sensors(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_sensors(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 10)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 10)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x24);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_npu @ 00102b38 size=292
// signature: undefined msm_get_npu(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_npu(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0xb)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0xb)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x28);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_spss @ 00102c60 size=292
// signature: undefined msm_get_spss(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_spss(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0xc)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0xc)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x2c);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_nav @ 00102d88 size=292
// signature: undefined msm_get_nav(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_nav(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0xd)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0xd)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x30);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_comp1 @ 00102eb0 size=292
// signature: undefined msm_get_comp1(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_comp1(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0xe)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0xe)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x34);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_display1 @ 00102fd8 size=292
// signature: undefined msm_get_display1(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_display1(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0xf)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0xf)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x38);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_nsp @ 00103100 size=292
// signature: undefined msm_get_nsp(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_nsp(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0x10)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0x10)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x3c);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_eva @ 00103228 size=292
// signature: undefined msm_get_eva(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long msm_get_eva(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((socinfo == 0 || socinfo_format < 0xe) || (*(uint *)(socinfo + 0xa4) < 0x11)) {
    _printk(&DAT_001067e2);
  }
  else {
    puVar4 = (undefined4 *)kmalloc_trace(_seq_read,0xcc0,4);
    if (puVar4 != (undefined4 *)0x0) {
      if (((socinfo == 0) || (socinfo_format < 0xe)) || (*(uint *)(socinfo + 0xa4) < 0x11)) {
        _printk(&DAT_001067e2);
      }
      else {
        lVar1 = 0xdc;
        if (socinfo_format < 0x15) {
          lVar1 = 0xa8;
        }
        if (*(uint *)(socinfo + lVar1) != 0) {
          *puVar4 = *(undefined4 *)((ulong)*(uint *)(socinfo + lVar1) + socinfo + 0x40);
          iVar2 = scnprintf(param_3,0x1000,&DAT_00106736);
          iVar3 = scnprintf(param_3 + iVar2,0x1000 - (long)iVar2,&DAT_00106575);
          kfree(puVar4);
          return (long)(iVar3 + iVar2);
        }
      }
    }
    kfree(puVar4);
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_get_chip_id @ 00103350 size=92
// signature: undefined msm_get_chip_id(void)
// callers: []
//------------------------------------------------------------

long msm_get_chip_id(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar1 = (undefined *)(socinfo + 0x7c);
  if (socinfo_format < 0xd) {
    puVar1 = &DAT_00105f1c;
  }
  puVar2 = &DAT_00105f1c;
  if (socinfo != 0) {
    puVar2 = puVar1;
  }
  iVar3 = scnprintf(param_3,0x1000,"%-.32s\n",puVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// msm_get_chip_family @ 001033b0 size=88
// signature: undefined msm_get_chip_family(void)
// callers: []
//------------------------------------------------------------

long msm_get_chip_family(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 0xc) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0x6c);
  }
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_platform_subtype_id @ 0010340c size=88
// signature: undefined msm_get_platform_subtype_id(void)
// callers: []
//------------------------------------------------------------

long msm_get_platform_subtype_id(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 6) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0x40);
  }
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105d59,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_platform_subtype @ 00103468 size=240
// signature: undefined msm_get_platform_subtype(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00103538) */

long msm_get_platform_subtype(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  if (socinfo == 0 || socinfo_format < 6) {
    uVar4 = 0;
  }
  else {
    uVar4 = (ulong)*(uint *)(socinfo + 0x40);
  }
  uVar3 = (uint)uVar4;
  if ((socinfo == 0 || socinfo_format < 3) || (*(int *)(socinfo + 0x34) != 0xb)) {
    if (uVar3 < 4) {
      if (4 < uVar3) goto LAB_00103554;
    }
    else {
      _printk(&DAT_0010609b);
      uVar4 = 4;
    }
    ppuVar5 = &hw_platform_subtype;
  }
  else {
    if (uVar3 < 6) {
      if (uVar3 == 7) {
LAB_00103554:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x103558);
        (*pcVar1)();
      }
    }
    else {
      _printk(&DAT_0010633e);
      uVar4 = 6;
    }
    ppuVar5 = &qrd_hw_platform_subtype;
  }
  iVar2 = scnprintf(param_3,0x1000,"%-.32s\n",ppuVar5[uVar4]);
  return (long)iVar2;
}



//------------------------------------------------------------
// msm_get_platform_version @ 0010355c size=88
// signature: undefined msm_get_platform_version(void)
// callers: []
//------------------------------------------------------------

long msm_get_platform_version(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (socinfo == 0 || socinfo_format < 4) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(socinfo + 0x38);
  }
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105d59,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// msm_get_hw_platform @ 001035b8 size=128
// signature: undefined msm_get_hw_platform(void)
// callers: []
//------------------------------------------------------------

long msm_get_hw_platform(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if (socinfo == 0 || socinfo_format < 3) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(socinfo + 0x34);
    if (0x2c < uVar3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103638);
      (*pcVar1)();
    }
  }
  if (0x2c < uVar3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(1,0x103634);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,"%-.32s\n",(&hw_platform)[uVar3]);
  return (long)iVar2;
}



//------------------------------------------------------------
// soc_info_attribute @ 0010363c size=8
// signature: undefined soc_info_attribute(void)
// callers: []
//------------------------------------------------------------

undefined2 soc_info_attribute(undefined8 param_1,long param_2)

{
  return *(undefined2 *)(param_2 + 8);
}



//------------------------------------------------------------
// qcom_open_chip_id @ 00103648 size=48
// signature: undefined qcom_open_chip_id(void)
// callers: []
//------------------------------------------------------------

void qcom_open_chip_id(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_show_chip_id,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_show_chip_id @ 0010367c size=48
// signature: undefined qcom_show_chip_id(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_show_chip_id(long param_1)

{
  seq_printf(param_1,&DAT_001063df,*(long *)(param_1 + 0x80) + 0x7c);
  return 0;
}



//------------------------------------------------------------
// qcom_open_pmic_model_array @ 001036b0 size=48
// signature: undefined qcom_open_pmic_model_array(void)
// callers: []
//------------------------------------------------------------

void qcom_open_pmic_model_array(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_show_pmic_model_array,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_show_pmic_model_array @ 001036e4 size=200
// signature: undefined qcom_show_pmic_model_array(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_show_pmic_model_array(long param_1)

{
  uint uVar1;
  ushort uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  lVar3 = *(long *)(param_1 + 0x80);
  iVar4 = *(int *)(lVar3 + 100);
  if (iVar4 != 0) {
    iVar5 = 1;
    lVar3 = lVar3 + (ulong)*(uint *)(lVar3 + 0x68);
    do {
      uVar2 = *(ushort *)
               (lVar3 + (-(ulong)(iVar5 - 1U >> 0x1f) & 0xfffffffc00000000 |
                        (ulong)(iVar5 - 1U) << 2));
      if ((uVar2 < 100) && ((&pmic_models)[uVar2] != (undefined *)0x0)) {
        uVar1 = *(uint *)(lVar3 + (long)iVar5 * 4);
        seq_printf(param_1,"%s %u.%u\n",(&pmic_models)[uVar2],uVar1 >> 0x10,uVar1 & 0xffff);
      }
      else {
        seq_printf(param_1,"unknown (%d)\n");
      }
      iVar4 = iVar4 + -1;
      iVar5 = iVar5 + 2;
    } while (iVar4 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_open_pmic_model @ 001037b0 size=48
// signature: undefined qcom_open_pmic_model(void)
// callers: []
//------------------------------------------------------------

void qcom_open_pmic_model(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_show_pmic_model,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_show_pmic_model @ 001037e4 size=92
// signature: undefined qcom_show_pmic_model(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_show_pmic_model(long param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(*(long *)(param_1 + 0x80) + 0x44);
  if ((uVar1 < 100) && ((&pmic_models)[uVar1] != (undefined *)0x0)) {
    seq_printf(param_1,&DAT_001063df,(&pmic_models)[uVar1]);
  }
  else {
    seq_printf(param_1,"unknown (%d)\n");
  }
  return 0;
}



//------------------------------------------------------------
// qcom_open_pmic_die_rev @ 00103844 size=48
// signature: undefined qcom_open_pmic_die_rev(void)
// callers: []
//------------------------------------------------------------

void qcom_open_pmic_die_rev(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_show_pmic_die_revision,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_show_pmic_die_revision @ 00103878 size=56
// signature: undefined qcom_show_pmic_die_revision(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_show_pmic_die_revision(long param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x80) + 0x48);
  seq_printf(param_1,"%u.%u\n",uVar1 >> 0x10,uVar1 & 0xffff);
  return 0;
}



//------------------------------------------------------------
// qcom_open_build_id @ 001038b4 size=48
// signature: undefined qcom_open_build_id(void)
// callers: []
//------------------------------------------------------------

void qcom_open_build_id(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_show_build_id,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_show_build_id @ 001038e8 size=48
// signature: undefined qcom_show_build_id(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_show_build_id(long param_1)

{
  seq_printf(param_1,&DAT_001063df,*(long *)(param_1 + 0x80) + 0xc);
  return 0;
}



//------------------------------------------------------------
// open_image_name @ 0010391c size=48
// signature: undefined open_image_name(void)
// callers: []
//------------------------------------------------------------

void open_image_name(long param_1,undefined8 param_2)

{
  single_open(param_2,show_image_name,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// show_image_name @ 00103950 size=52
// signature: undefined show_image_name(void)
// callers: []
//------------------------------------------------------------

undefined8 show_image_name(long param_1)

{
  if (**(char **)(param_1 + 0x80) != '\0') {
    seq_printf(param_1,&DAT_001063df);
  }
  return 0;
}



//------------------------------------------------------------
// open_image_variant @ 00103988 size=48
// signature: undefined open_image_variant(void)
// callers: []
//------------------------------------------------------------

void open_image_variant(long param_1,undefined8 param_2)

{
  single_open(param_2,show_image_variant,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// show_image_variant @ 001039bc size=52
// signature: undefined show_image_variant(void)
// callers: []
//------------------------------------------------------------

undefined8 show_image_variant(long param_1)

{
  if (*(char *)(*(long *)(param_1 + 0x80) + 0x4b) != '\0') {
    seq_printf(param_1,&DAT_001063df);
  }
  return 0;
}



//------------------------------------------------------------
// open_image_oem @ 001039f4 size=48
// signature: undefined open_image_oem(void)
// callers: []
//------------------------------------------------------------

void open_image_oem(long param_1,undefined8 param_2)

{
  single_open(param_2,show_image_oem,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// show_image_oem @ 00103a28 size=52
// signature: undefined show_image_oem(void)
// callers: []
//------------------------------------------------------------

undefined8 show_image_oem(long param_1)

{
  if (*(char *)(*(long *)(param_1 + 0x80) + 0x60) != '\0') {
    seq_printf(param_1,&DAT_001063df);
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00103b88 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_socinfo_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103bb8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_socinfo_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00108000 size=1
// signature: undefined _printk(void)
// callers: [socinfo_get_feature_code, msm_get_nsp, msm_get_eva, qcom_socinfo_probe, msm_get_wlan, msm_get_nav, socinfo_get_cluster_info, socinfo_enumerate_partinfo_details, socinfo_get_part_info, msm_get_display, msm_get_sensors, msm_get_platform_subtype, socinfo_get_subpart_info, msm_get_modem, msm_get_comp1, socinfo_get_part_count, msm_get_gpu, msm_get_audio, msm_get_video, msm_get_comp, msm_get_spss, msm_get_camera, socinfo_get_pcode, msm_get_display1, msm_get_npu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00108008 size=1
// signature: undefined strscpy(void)
// callers: [socinfo_enumerate_partinfo_details]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00108010 size=1
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
// platform_driver_unregister @ 00108018 size=1
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
// qcom_smem_get @ 00108020 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00108028 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kasprintf @ 00108030 size=1
// signature: undefined devm_kasprintf(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00108038 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// soc_device_register @ 00108040 size=1
// signature: undefined soc_device_register(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void soc_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00108048 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x32 @ 00108050 size=1
// signature: undefined debugfs_create_x32(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00108058 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00108060 size=1
// signature: undefined debugfs_create_file(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_device_randomness @ 00108068 size=1
// signature: undefined add_device_randomness(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_device_randomness(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_socinfo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// soc_device_unregister @ 00108078 size=1
// signature: undefined soc_device_unregister(void)
// callers: [qcom_socinfo_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void soc_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00108080 size=1
// signature: undefined debugfs_remove(void)
// callers: [qcom_socinfo_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00108088 size=1
// signature: undefined sysfs_emit(void)
// callers: [msm_get_sku, msm_get_feature_code]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00108090 size=1
// signature: undefined scnprintf(void)
// callers: [msm_get_nsp, msm_get_eva, msm_get_wlan, msm_get_nav, msm_get_platform_version, msm_get_display, msm_get_chip_family, msm_get_nsubset_parts_array_offset, msm_get_sensors, msm_get_platform_subtype, msm_get_modem, msm_get_comp1, msm_get_platform_subtype_id, msm_get_gpu, msm_get_audio, msm_get_pcode, msm_get_num_clusters, msm_get_video, msm_get_comp, msm_get_chip_id, msm_get_subset_parts, msm_get_spss, msm_get_hw_platform, msm_get_num_subset_parts, msm_get_camera, msm_get_display1, msm_get_subset_cores, msm_get_npu, msm_get_ncluster_array_offset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001080a0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_get_sensors, msm_get_modem, msm_get_comp1, msm_get_nsp, msm_get_eva, msm_get_gpu, msm_get_audio, msm_get_wlan, msm_get_nav, msm_get_video, msm_get_comp, msm_get_spss, msm_get_camera, msm_get_display, msm_get_display1, msm_get_npu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001080a8 size=1
// signature: undefined kfree(void)
// callers: [msm_get_sensors, msm_get_modem, msm_get_comp1, msm_get_nsp, msm_get_eva, msm_get_gpu, msm_get_audio, msm_get_wlan, msm_get_nav, msm_get_video, msm_get_comp, msm_get_spss, msm_get_camera, msm_get_display, msm_get_display1, msm_get_npu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001080b0 size=1
// signature: undefined single_open(void)
// callers: [qcom_open_pmic_model, open_image_oem, qcom_open_pmic_model_array, qcom_open_build_id, open_image_name, qcom_open_chip_id, qcom_open_pmic_die_rev, open_image_variant]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001080b8 size=1
// signature: undefined seq_printf(void)
// callers: [qcom_show_chip_id, qcom_show_pmic_die_revision, show_image_variant, qcom_show_build_id, show_image_name, show_image_oem, qcom_show_pmic_model_array, qcom_show_pmic_model]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



