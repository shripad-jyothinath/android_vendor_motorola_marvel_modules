// Decompiled by Ghidra 12.2
// Program: mmi_info.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_storage_info_init @ 0010071c size=708
// signature: undefined mmi_storage_info_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_storage_info_init(void)

{
  void *pvVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  size_t sVar5;
  char *__s1;
  char *pcVar6;
  undefined8 *puVar7;
  
  lVar3 = of_find_node_opts_by_path("/chosen/mmi,storage",0);
  if (lVar3 != 0) {
    info = (void *)kmalloc_trace(_mmi_annotate_persist,0xdc0,0x80);
    if (info == (void *)0x0) {
      puVar4 = &DAT_001021f1;
    }
    else {
      for (puVar7 = *(undefined8 **)(lVar3 + 0x60); puVar7 != (undefined8 *)0x0;
          puVar7 = (undefined8 *)puVar7[3]) {
        __s1 = (char *)*puVar7;
        iVar2 = strcmp(__s1,"type");
        pvVar1 = info;
        if ((iVar2 == 0) && (pcVar6 = (char *)puVar7[2], pcVar6 != (char *)0x0)) {
          sVar5 = strlen(pcVar6);
          if (0xe < sVar5) {
            sVar5 = 0xf;
          }
          memcpy(pvVar1,pcVar6,sVar5);
          *(undefined1 *)((long)pvVar1 + sVar5) = 0;
          __s1 = (char *)*puVar7;
        }
        iVar2 = strcmp(__s1,"size");
        if ((iVar2 == 0) && (pcVar6 = (char *)puVar7[2], pcVar6 != (char *)0x0)) {
          pvVar1 = (void *)((long)info + 0x10);
          sVar5 = strlen(pcVar6);
          if (0xe < sVar5) {
            sVar5 = 0xf;
          }
          memcpy(pvVar1,pcVar6,sVar5);
          *(undefined1 *)((long)pvVar1 + sVar5) = 0;
          __s1 = (char *)*puVar7;
        }
        iVar2 = strcmp(__s1,"manufacturer");
        if ((iVar2 == 0) && (pcVar6 = (char *)puVar7[2], pcVar6 != (char *)0x0)) {
          pvVar1 = (void *)((long)info + 0x20);
          sVar5 = strlen(pcVar6);
          if (0x1e < sVar5) {
            sVar5 = 0x1f;
          }
          memcpy(pvVar1,pcVar6,sVar5);
          *(undefined1 *)((long)pvVar1 + sVar5) = 0;
          __s1 = (char *)*puVar7;
        }
        iVar2 = strcmp(__s1,"product");
        if ((iVar2 == 0) && (pcVar6 = (char *)puVar7[2], pcVar6 != (char *)0x0)) {
          pvVar1 = (void *)((long)info + 0x40);
          sVar5 = strlen(pcVar6);
          if (0x1e < sVar5) {
            sVar5 = 0x1f;
          }
          memcpy(pvVar1,pcVar6,sVar5);
          *(undefined1 *)((long)pvVar1 + sVar5) = 0;
          __s1 = (char *)*puVar7;
        }
        iVar2 = strcmp(__s1,"firmware");
        if ((iVar2 == 0) && (puVar7[2] != 0)) {
          strlcpy((long)info + 0x60,puVar7[2],0x20);
        }
      }
      _printk(&DAT_00102281,info,(long)info + 0x10,(long)info + 0x20,(long)info + 0x40,
              (long)info + 0x60);
      mmi_annotate_persist
                ("%s: %s %s %s FV=%s\n",info,(long)info + 0x10,(long)info + 0x20,(long)info + 0x40,
                 (long)info + 0x60);
      st_info_properties_kobj = kobject_create_and_add("storage",0);
      if (st_info_properties_kobj == 0) {
        puVar4 = &DAT_001022a9;
      }
      else {
        iVar2 = sysfs_create_group(st_info_properties_kobj,&st_info_properties_attr_group);
        puVar4 = &DAT_001022a9;
        if ((st_info_properties_kobj != 0) && (iVar2 == 0)) {
          return 0;
        }
      }
    }
    _printk(puVar4,"mmi_storage_info_init");
  }
  return 1;
}



//------------------------------------------------------------
// mmi_storage_info_exit @ 001009e4 size=76
// signature: undefined mmi_storage_info_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void mmi_storage_info_exit(void)

{
  kfree(info);
  info = 0;
  sysfs_remove_group(st_info_properties_kobj,&st_info_properties_attr_group);
  kobject_del(st_info_properties_kobj);
  return;
}



//------------------------------------------------------------
// fw_show @ 00100a34 size=60
// signature: undefined fw_show(void)
// callers: []
//------------------------------------------------------------

long fw_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x20,"%s\n",info + 0x60);
  return (long)iVar1;
}



//------------------------------------------------------------
// model_show @ 00100a74 size=60
// signature: undefined model_show(void)
// callers: []
//------------------------------------------------------------

long model_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x20,"%s\n",info + 0x40);
  return (long)iVar1;
}



//------------------------------------------------------------
// vendor_show @ 00100ab4 size=60
// signature: undefined vendor_show(void)
// callers: []
//------------------------------------------------------------

long vendor_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x20,"%s\n",info + 0x20);
  return (long)iVar1;
}



//------------------------------------------------------------
// size_show @ 00100af4 size=60
// signature: undefined size_show(void)
// callers: []
//------------------------------------------------------------

long size_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x10,"%s\n",info + 0x10);
  return (long)iVar1;
}



//------------------------------------------------------------
// type_show @ 00100b34 size=56
// signature: undefined type_show(void)
// callers: []
//------------------------------------------------------------

long type_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x10,"%s\n",info);
  return (long)iVar1;
}



//------------------------------------------------------------
// mmi_ram_info_init @ 00100b70 size=504
// signature: undefined mmi_ram_info_init(void)
// callers: [init_module]
//------------------------------------------------------------

void mmi_ram_info_init(void)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined **ppuVar7;
  char *pcVar8;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  smem_ddr_info = (byte *)qcom_smem_get(0xffffffff,0x87,&local_40);
  uVar6 = local_40;
  if (smem_ddr_info == (byte *)0x0) {
    puVar4 = &DAT_00102100;
  }
  else if (local_40 < 0x14) {
    puVar4 = &DAT_00102516;
  }
  else {
    bVar1 = *smem_ddr_info;
    if (bVar1 < 0xf) {
      pcVar8 = (&mmi_ram_info_init_vendors)[bVar1];
    }
    else if (bVar1 == 0x13) {
      pcVar8 = "CXMT";
    }
    else if (bVar1 == 0xff) {
      pcVar8 = "Micron";
    }
    else if (bVar1 == 0xfe) {
      pcVar8 = "Numonyx";
    }
    else {
      pcVar8 = "unknown";
    }
    snprintf(sysfsram_vendor_name,0x14,"%s",pcVar8);
    if (uVar6 == 0x18) {
      uVar6 = (ulong)*(uint *)(smem_ddr_info + 0x14);
      if (*(uint *)(smem_ddr_info + 0x14) < 10) {
        ppuVar7 = &parse_ddr_type_v2_types;
        goto LAB_00100c4c;
      }
    }
    else {
      ppuVar7 = &parse_ddr_type_types;
      uVar6 = (ulong)*(uint *)(smem_ddr_info + 0xc) & 3;
LAB_00100c4c:
      snprintf(sysfsram_type_name,0x14,"%s",ppuVar7[uVar6]);
    }
    sysfsram_ramsize = *(undefined4 *)(smem_ddr_info + 0x10);
    mmi_annotate_persist
              ("RAM: %s, %s, %u MB, MR5:0x%02X, MR6:0x%02X, MR7:0x%02X, MR8:0x%02X\n",pcVar8,
               sysfsram_type_name,sysfsram_ramsize,*(undefined4 *)smem_ddr_info,
               *(undefined4 *)(smem_ddr_info + 4),*(undefined4 *)(smem_ddr_info + 8),
               *(undefined4 *)(smem_ddr_info + 0xc));
    ram_info_properties_kobj = kobject_create_and_add(&DAT_00102142,0);
    if (ram_info_properties_kobj == 0) {
      puVar4 = &DAT_00102099;
    }
    else {
      iVar3 = sysfs_create_group(ram_info_properties_kobj,ram_info_properties_attr_group);
      puVar4 = &DAT_00102099;
      if ((ram_info_properties_kobj != 0) && (iVar3 == 0)) {
        uVar5 = 0;
        goto LAB_00100d38;
      }
    }
  }
  _printk(puVar4,"mmi_ram_info_init");
  uVar5 = 1;
LAB_00100d38:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// mmi_ram_info_exit @ 00100d6c size=60
// signature: undefined mmi_ram_info_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void mmi_ram_info_exit(void)

{
  sysfs_remove_group(ram_info_properties_kobj,ram_info_properties_attr_group);
  kobject_del(ram_info_properties_kobj);
  return;
}



//------------------------------------------------------------
// mr_register_show @ 00100dac size=220
// signature: undefined mr_register_show(void)
// callers: []
//------------------------------------------------------------

long mr_register_show(undefined8 param_1,undefined8 *param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  uint param3;
  char *__string;
  uint *puVar3;
  
  puVar3 = smem_ddr_info;
  if (smem_ddr_info != (uint *)0x0) {
    __string = (char *)*param_2;
    sVar2 = strnlen(__string,4);
    if (sVar2 != 3) {
      if (sVar2 != 0xffffffffffffffff) goto switchD_00100e38_default;
      fortify_panic("strnlen");
    }
    if ((*__string == 'm') && (__string[1] == 'r')) {
      switch(__string[2]) {
      case '5':
        break;
      case '6':
        puVar3 = puVar3 + 1;
        break;
      case '7':
        puVar3 = puVar3 + 2;
        break;
      case '8':
        puVar3 = puVar3 + 3;
        break;
      default:
        goto switchD_00100e38_default;
      }
      param3 = *puVar3;
      goto LAB_00100e48;
    }
  }
switchD_00100e38_default:
  param3 = 0;
LAB_00100e48:
  iVar1 = snprintf(param_3,8,"0x%02x\n",param3);
  return (long)iVar1;
}



//------------------------------------------------------------
// size_show @ 00100e8c size=56
// signature: undefined size_show(void)
// callers: []
//------------------------------------------------------------

long size_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0xc,"%u\n",(ulong)sysfsram_ramsize);
  return (long)iVar1;
}



//------------------------------------------------------------
// type_show @ 00100ec8 size=56
// signature: undefined type_show(void)
// callers: []
//------------------------------------------------------------

long type_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x14,"%s\n",sysfsram_type_name);
  return (long)iVar1;
}



//------------------------------------------------------------
// info_show @ 00100f04 size=72
// signature: undefined info_show(void)
// callers: []
//------------------------------------------------------------

long info_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x3c,"%s:%s:%uMB\n",sysfsram_vendor_name,sysfsram_type_name,
                   sysfsram_ramsize);
  return (long)iVar1;
}



//------------------------------------------------------------
// mmi_unit_info_init @ 00100f50 size=1240
// signature: undefined mmi_unit_info_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_unit_info_init(void)

{
  void *__dest;
  void *__dest_00;
  void *__dest_01;
  undefined4 *__dest_02;
  undefined4 *__dest_03;
  long lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  code *pcVar5;
  int iVar6;
  size_t sVar7;
  undefined4 *__src;
  undefined1 *__src_00;
  char *local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_60 = (char *)0x0;
  iVar6 = mmi_get_bootarg("androidboot.radio=",&local_60);
  if (iVar6 == 0) {
    iVar6 = kstrtouint(local_60,0x10,&androidboot_radio);
    pcVar4 = local_60;
    if (iVar6 < 0) {
      androidboot_radio = 0;
    }
    sVar7 = strlen(local_60);
    if (0x1f < sVar7) {
      sVar7 = 0x20;
    }
    memcpy(androidboot_radio_str,pcVar4,sVar7);
    androidboot_radio_str[sVar7] = 0;
  }
  iVar6 = mmi_get_bootarg("androidboot.device=",&local_60);
  pcVar4 = local_60;
  if (iVar6 == 0) {
    sVar7 = strlen(local_60);
    if (0x1e < sVar7) {
      sVar7 = 0x1f;
    }
    memcpy(androidboot_device,pcVar4,sVar7);
    androidboot_device[sVar7] = 0;
  }
  mmi_get_bootarg("androidboot.baseband=",&local_60);
  iVar6 = mmi_get_bootarg("androidboot.carrier=",&local_60);
  pcVar4 = local_60;
  if (iVar6 == 0) {
    sVar7 = strlen(local_60);
    if (0x3f < sVar7) {
      sVar7 = 0x40;
    }
    memcpy(carrier,pcVar4,sVar7);
    carrier[sVar7] = 0;
  }
  iVar6 = mmi_get_bootarg("androidboot.serialno=",&local_60);
  pcVar4 = local_60;
  if (iVar6 == 0) {
    sVar7 = strlen(local_60);
    if (0x3e < sVar7) {
      sVar7 = 0x3f;
    }
    memcpy(serialno,pcVar4,sVar7);
    serialno[sVar7] = 0;
  }
  local_60 = (char *)0x0;
  __src = (undefined4 *)kmalloc_trace(_kfree,0xdc0,0x400);
  uVar3 = DAT_0010308c._4_4_;
  uVar2 = _mmi_chosen_data;
  if (__src == (undefined4 *)0x0) {
    _printk(&DAT_00102053,"mmi_unit_smem_setup");
    goto LAB_00101394;
  }
  *__src = 3;
  *(undefined1 *)(__src + 4) = 0;
  *(undefined8 *)(__src + 1) = uVar2;
  __src[3] = uVar3;
  sVar7 = strnlen(serialno,0x40);
  if (0x40 < sVar7) goto LAB_00101408;
  if (sVar7 == 0x40) goto LAB_00101414;
  __dest = (void *)((long)__src + 0x31);
  memcpy(__dest,serialno,sVar7);
  if (sVar7 - 0x3d0 < 0xfffffffffffffbff) goto LAB_00101420;
  *(undefined1 *)((long)__dest + sVar7) = 0;
  sVar7 = strnlen(&DAT_001030a4,0x61);
  if (0x61 < sVar7) goto LAB_00101408;
  if (sVar7 == 0x61) goto LAB_00101414;
  __dest_00 = (void *)((long)__src + 0xb3);
  memcpy(__dest_00,&DAT_001030a4,sVar7);
  if (sVar7 - 0x34e < 0xfffffffffffffbff) goto LAB_00101420;
  *(undefined1 *)((long)__dest_00 + sVar7) = 0;
  sVar7 = strnlen(carrier,0x41);
  if (0x41 < sVar7) goto LAB_00101408;
  if (sVar7 == 0x41) goto LAB_00101414;
  __dest_01 = (void *)((long)__src + 0x72);
  memcpy(__dest_01,carrier,sVar7);
  if (sVar7 - 0x38f < 0xfffffffffffffbff) goto LAB_00101420;
  *(undefined1 *)((long)__dest_01 + sVar7) = 0;
  sVar7 = strnlen(&DAT_00103145,0x21);
  if (0x21 < sVar7) goto LAB_00101408;
  if (sVar7 != 0x21) {
    __dest_02 = __src + 0x45;
    if (sVar7 == 0) {
      sVar7 = strnlen(androidboot_device,0x20);
      if (sVar7 < 0x21) {
        if (sVar7 == 0x20) goto LAB_00101414;
        __src_00 = androidboot_device;
LAB_00101298:
        memcpy(__dest_02,__src_00,sVar7);
        if (sVar7 - 0x2ec < 0xfffffffffffffc00) goto LAB_00101420;
        *(undefined1 *)((long)__dest_02 + sVar7) = 0;
        __src[0x4e] = androidboot_radio;
        sVar7 = strnlen(androidboot_radio_str,0x21);
        if (0x21 < sVar7) goto LAB_00101408;
        if (sVar7 == 0x21) goto LAB_00101414;
        __dest_03 = __src + 0x50;
        memcpy(__dest_03,androidboot_radio_str,sVar7);
        if (sVar7 - 0x2c1 < 0xfffffffffffffbff) goto LAB_00101420;
        *(undefined1 *)((long)__dest_03 + sVar7) = 0;
        uVar3 = DAT_00103094;
        __src[0x4f] = DAT_00103094;
        _printk(&DAT_00102313,*__src,__dest_02,__src[0x4e],__dest_03,__src[1],__src[3],__src[2],
                __src + 4,__dest,__dest_00,__dest_01,uVar3);
        iVar6 = qcom_smem_alloc(0xffffffff,0x86,0x400);
        if (iVar6 == 0) {
          mui = (void *)qcom_smem_get(0xffffffff,0x86,&local_60);
          if ((mui == (void *)0x0) || (local_60 != (char *)0x400)) goto LAB_001013f0;
          memcpy(mui,__src,0x400);
        }
        else {
LAB_001013f0:
          _printk(&DAT_0010258a,"mmi_unit_smem_setup");
        }
        kfree(__src);
LAB_00101394:
        unitinfo_procfs_file = proc_create("unitinfo",0x124,0,&unitinfo_operations);
        lVar1 = sp_el0;
        if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return 0;
      }
LAB_00101408:
      fortify_panic("strnlen");
    }
    else {
      sVar7 = strnlen(&DAT_00103145,0x21);
      if (0x21 < sVar7) goto LAB_00101408;
      if (sVar7 != 0x21) {
        __src_00 = &DAT_00103145;
        goto LAB_00101298;
      }
    }
  }
LAB_00101414:
  fortify_panic("__fortify_strlen");
LAB_00101420:
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(1,0x101424);
  (*pcVar5)();
}



//------------------------------------------------------------
// mmi_unit_info_exit @ 0010142c size=52
// signature: undefined mmi_unit_info_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void mmi_unit_info_exit(void)

{
  if (unitinfo_procfs_file != 0) {
    remove_proc_entry("unitinfo",0);
  }
  return;
}



//------------------------------------------------------------
// unitinfo_open @ 00101464 size=48
// signature: undefined unitinfo_open(void)
// callers: []
//------------------------------------------------------------

void unitinfo_open(long param_1,undefined8 param_2)

{
  single_open(param_2,unitinfo_seq_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// unitinfo_seq_show @ 00101498 size=196
// signature: undefined unitinfo_seq_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 unitinfo_seq_show(undefined8 param_1)

{
  size_t sVar1;
  
  seq_printf(param_1,"Revision\t: %04x\n",mmi_chosen_data);
  seq_printf(param_1,"Serial\t\t: %08x%08x\n",DAT_0010308c._4_4_,(undefined4)DAT_0010308c);
  seq_printf(param_1,"Device\t\t: %s\n",androidboot_device);
  sVar1 = strnlen(androidboot_radio_str,0x21);
  if (0x21 < sVar1) {
    fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (sVar1 != 0) {
    seq_printf(param_1,"Radio\t\t: %s\n",androidboot_radio_str);
  }
  seq_printf(param_1,"MSM Hardware\t: %s\n",&DAT_00103105);
  return 0;
}



//------------------------------------------------------------
// bi_powerup_reason @ 00101560 size=12
// signature: undefined bi_powerup_reason(void)
// callers: []
//------------------------------------------------------------

undefined4 bi_powerup_reason(void)

{
  return DAT_00103094;
}



//------------------------------------------------------------
// bi_mbm_version @ 00101570 size=12
// signature: undefined bi_mbm_version(void)
// callers: []
//------------------------------------------------------------

undefined4 bi_mbm_version(void)

{
  return DAT_0010309c;
}



//------------------------------------------------------------
// bi_boot_seq @ 00101580 size=12
// signature: undefined bi_boot_seq(void)
// callers: []
//------------------------------------------------------------

undefined4 bi_boot_seq(void)

{
  return DAT_001030a0;
}



//------------------------------------------------------------
// bi_add_bl_build_sig @ 00101590 size=288
// signature: undefined bi_add_bl_build_sig(void)
// callers: [mmi_boot_info_init]
//------------------------------------------------------------

void bi_add_bl_build_sig(void *param_1)

{
  byte bVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  void *pvVar5;
  
  uVar3 = bl_build_sig_count;
  if (((param_1 != (void *)0x0) && (bl_build_sig_count < 0x14)) &&
     (pvVar5 = memchr(param_1,0x3d,0x14), pvVar5 != (void *)0x0)) {
    strlcpy(bl_build_sigs + (ulong)uVar3 * 100,param_1,(long)(((int)pvVar5 - (int)param_1) + 1));
    if ((2000 < (ulong)uVar3 * 100) || (uVar3 == 0x14)) {
LAB_001016a8:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x1016ac);
      (*pcVar4)();
    }
    bVar1 = bl_build_sigs[(ulong)uVar3 * 100];
    uVar2 = (ulong)uVar3 * 100;
    while (bVar1 != 0) {
      if (1999 < uVar2) goto LAB_001016a8;
      if (((&_ctype)[bVar1] & 2) != 0) {
        bVar1 = bVar1 - 0x20;
      }
      bl_build_sigs[uVar2] = bVar1;
      if (uVar2 - 1999 < 0xfffffffffffff830) goto LAB_001016a8;
      bVar1 = bl_build_sigs[uVar2 + 1];
      uVar2 = uVar2 + 1;
    }
    if (0x13 < bl_build_sig_count) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1016b0);
      (*pcVar4)();
    }
    strlcpy((ulong)bl_build_sig_count * 100 + 0x102840,(long)pvVar5 + 1,0x50);
    bl_build_sig_count = bl_build_sig_count + 1;
  }
  return;
}



//------------------------------------------------------------
// bi_hwrev @ 001016b4 size=12
// signature: undefined bi_hwrev(void)
// callers: []
//------------------------------------------------------------

undefined4 bi_hwrev(void)

{
  return mmi_chosen_data;
}



//------------------------------------------------------------
// bi_chipid @ 001016c4 size=12
// signature: undefined bi_chipid(void)
// callers: []
//------------------------------------------------------------

undefined * bi_chipid(void)

{
  return &DAT_00103125;
}



//------------------------------------------------------------
// bi_bootreason @ 001016d4 size=12
// signature: undefined bi_bootreason(void)
// callers: []
//------------------------------------------------------------

undefined1 * bi_bootreason(void)

{
  return bootreason;
}



//------------------------------------------------------------
// bi_bootmode @ 001016e4 size=12
// signature: undefined bi_bootmode(void)
// callers: []
//------------------------------------------------------------

undefined1 * bi_bootmode(void)

{
  return bootmode;
}



//------------------------------------------------------------
// mmi_boot_info_init @ 001016f4 size=664
// signature: undefined mmi_boot_info_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 mmi_boot_info_init(void)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  size_t sVar5;
  undefined8 *puVar6;
  ulong uVar7;
  char *local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  if ((bl_build_sig_count == 0) &&
     (lVar4 = of_find_node_opts_by_path("/chosen/mmi,bl_sigs",0), lVar4 != 0)) {
    for (puVar6 = *(undefined8 **)(lVar4 + 0x60); puVar6 != (undefined8 *)0x0;
        puVar6 = (undefined8 *)puVar6[3]) {
      iVar3 = strcmp((char *)*puVar6,"name");
      if (iVar3 != 0) {
        bi_add_bl_build_sig(puVar6[2]);
      }
    }
  }
  local_60 = (char *)0x0;
  iVar3 = mmi_get_bootarg("androidboot.bootreason=",&local_60);
  pcVar1 = local_60;
  if (iVar3 == 0) {
    sVar5 = strlen(local_60);
    if (0x3e < sVar5) {
      sVar5 = 0x3f;
    }
    memcpy(bootreason,pcVar1,sVar5);
    bootreason[sVar5] = 0;
  }
  iVar3 = mmi_get_bootarg("androidboot.mode=",&local_60);
  pcVar1 = local_60;
  if (iVar3 == 0) {
    sVar5 = strlen(local_60);
    if (0x3e < sVar5) {
      sVar5 = 0x3f;
    }
    memcpy(bootmode,pcVar1,sVar5);
    bootmode[sVar5] = 0;
  }
  proc_bootinfo = proc_create("bootinfo",0x124,0,&bootinfo_proc_fops);
  if (bl_build_sig_count != 0) {
    lVar4 = 0;
    uVar7 = 0;
    do {
      if (lVar4 == 2000) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101988);
        (*pcVar2)();
      }
      if ((lVar4 - 0x7beU < 0xfffffffffffff82f) ||
         (bl_build_sigs[lVar4 + 0x13] = 0, lVar4 - 0x76eU < 0xfffffffffffff82f)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x101984);
        (*pcVar2)();
      }
      bl_build_sigs[lVar4 + 99] = 0;
      mmi_annotate_persist();
      mmi_annotate_persist(&DAT_00101f7e);
      mmi_annotate_persist(lVar4 + 0x102840);
      mmi_annotate_persist(&DAT_0010262e);
      uVar7 = uVar7 + 1;
      lVar4 = lVar4 + 100;
    } while (uVar7 < bl_build_sig_count);
  }
  mmi_annotate_persist("MBM_VERSION: 0x%08x\n",DAT_0010309c);
  mmi_annotate_persist("SERIAL: 0x%llx\n",DAT_0010308c);
  mmi_annotate_persist("HW_REV: 0x%04x\n",mmi_chosen_data);
  mmi_annotate_persist("BOOT_SEQ: %d\n",DAT_001030a0);
  mmi_annotate_persist("CHIPID: %s\n",&DAT_00103125);
  mmi_annotate("POWERUPREASON: 0x%08x\n",DAT_00103094);
  mmi_annotate("Last boot reason: %s\n\n",bootreason);
  _printk(&DAT_001024dd,DAT_001030a0);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// mmi_boot_info_exit @ 00101990 size=52
// signature: undefined mmi_boot_info_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void mmi_boot_info_exit(void)

{
  if (proc_bootinfo != 0) {
    remove_proc_entry("bootinfo",0);
  }
  return;
}



//------------------------------------------------------------
// bootinfo_proc_open @ 001019c8 size=48
// signature: undefined bootinfo_proc_open(void)
// callers: []
//------------------------------------------------------------

void bootinfo_proc_open(long param_1,undefined8 param_2)

{
  single_open(param_2,get_bootinfo,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// get_bootinfo @ 001019fc size=332
// signature: undefined get_bootinfo(void)
// callers: []
//------------------------------------------------------------

undefined8 get_bootinfo(undefined8 param_1)

{
  code *pcVar1;
  char *pcVar2;
  ulong uVar3;
  
  seq_printf(param_1,"SERIAL: 0x%llx\n",DAT_0010308c);
  seq_printf(param_1,"HW_REV: 0x%04x\n",mmi_chosen_data);
  seq_printf(param_1,"POWERUPREASON: 0x%08x\n",DAT_00103094);
  seq_printf(param_1,"MBM_VERSION: 0x%08x\n",DAT_0010309c);
  if (bl_build_sig_count != 0) {
    uVar3 = 0;
    pcVar2 = bl_build_sigs + 0x14;
    do {
      if (uVar3 == 0x14) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101b48);
        (*pcVar1)();
      }
      if (*pcVar2 == '\0') {
        seq_printf(param_1,"%s: UNKNOWN\n",pcVar2 + -0x14);
      }
      else {
        seq_printf(param_1,"%s: %s\n",pcVar2 + -0x14,pcVar2);
      }
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 100;
    } while (uVar3 < bl_build_sig_count);
  }
  seq_printf(param_1,"BOOT_SEQ: %d\n",DAT_001030a0);
  seq_printf(param_1,"CHIPID: %s\n",&DAT_00103125);
  seq_printf(param_1,"Last boot reason: %s\n",bootreason);
  return 0;
}



//------------------------------------------------------------
// mmi_device_is_available @ 00101b4c size=344
// signature: undefined mmi_device_is_available(void)
// callers: [mmi_check_dynamic_device_node]
//------------------------------------------------------------

bool mmi_device_is_available(long param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  char *__s1;
  long lVar4;
  char *__s2;
  char *pcVar5;
  undefined8 uVar6;
  int iVar7;
  int local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  if (param_1 == 0) {
    bVar1 = true;
  }
  else {
    lVar3 = of_find_property(param_1,"mmi,status",&local_4c);
    bVar1 = true;
    if ((lVar3 != 0) && (-1 < local_4c)) {
      uVar6 = *(undefined8 *)(lVar3 + 0x10);
      __s1 = (char *)of_prop_next_string(lVar3,uVar6);
      if ((__s1 == (char *)0x0) || (lVar4 = of_find_node_opts_by_path(uVar6,0), lVar4 == 0)) {
        bVar1 = false;
      }
      else {
        __s2 = (char *)of_get_property(lVar4,__s1,&local_4c);
        bVar1 = false;
        if ((__s2 != (char *)0x0) && (0 < local_4c)) {
          iVar7 = 0;
LAB_00101bf4:
          do {
            while( true ) {
              __s1 = (char *)of_prop_next_string(lVar3,__s1);
              bVar1 = __s1 != (char *)0x0;
              if (__s1 == (char *)0x0) goto LAB_00101c6c;
              if (iVar7 != 1) break;
LAB_00101c44:
              iVar2 = strcmp(__s1,__s2);
              iVar7 = 1;
              bVar1 = true;
              if (iVar2 == 0) goto LAB_00101c6c;
            }
            if (iVar7 == 0) {
              iVar2 = strcmp(__s1,"contains");
              iVar7 = 2;
              if (iVar2 != 0) goto LAB_00101c44;
              goto LAB_00101bf4;
            }
            pcVar5 = strstr(__s2,__s1);
          } while (pcVar5 == (char *)0x0);
        }
      }
    }
  }
LAB_00101c6c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar1;
}



//------------------------------------------------------------
// mmi_check_dynamic_device_node @ 00101ca8 size=288
// signature: undefined mmi_check_dynamic_device_node(void)
// callers: []
//------------------------------------------------------------

uint mmi_check_dynamic_device_node(char *param_1)

{
  uint uVar1;
  long lVar2;
  char *pcVar3;
  char *__haystack;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  lVar2 = of_find_node_opts_by_path("/chosen",0);
  if (lVar2 != 0) {
    lVar2 = of_find_property(lVar2,"mmi,dynamic_devices",&local_3c);
    if ((lVar2 == 0) || (local_3c < 0)) {
      _printk(&DAT_001025ce,"mmi_check_dynamic_device_node");
    }
    else {
      __haystack = (char *)0x0;
      do {
        __haystack = (char *)of_prop_next_string(lVar2,__haystack);
        if (__haystack == (char *)0x0) goto LAB_00101da8;
        pcVar3 = strstr(__haystack,param_1);
      } while (pcVar3 == (char *)0x0);
      _printk(&DAT_00101fbe,"mmi_check_dynamic_device_node",__haystack);
      lVar2 = of_find_node_opts_by_path(__haystack,0);
      if (lVar2 != 0) {
        uVar1 = mmi_device_is_available();
        goto LAB_00101cec;
      }
LAB_00101da8:
      _printk(&DAT_00102164,"mmi_check_dynamic_device_node",param_1);
    }
  }
  uVar1 = 1;
LAB_00101cec:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// mmi_get_bootarg @ 00101dcc size=332
// signature: undefined mmi_get_bootarg(void)
// callers: [mmi_boot_info_init, mmi_unit_info_init]
//------------------------------------------------------------

void mmi_get_bootarg(undefined8 param_1,undefined8 *param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char *pcVar5;
  char *local_60;
  char *local_58;
  char *local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = (char *)0x0;
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar3 != 0) &&
     (iVar2 = of_property_read_string(lVar3,"mmi,bootconfig",&local_50), pcVar5 = local_50,
     iVar2 == 0)) {
    sVar4 = strlen(local_50);
    if (bootargs_str == (char *)0x0) {
      bootargs_str = (char *)__kmalloc(sVar4 + 1,0xdc0);
      if (bootargs_str == (char *)0x0) goto LAB_00101e28;
      pcVar5 = local_50;
    }
    strlcpy(bootargs_str,pcVar5,sVar4 + 1);
    pcVar5 = bootargs_str;
    sVar4 = strlen(bootargs_str);
    local_58 = (char *)strnstr(pcVar5,param_1,sVar4);
    if (local_58 != (char *)0x0) {
      local_60 = strsep(&local_58," ");
      if ((local_60 != (char *)0x0) && (pcVar5 = strsep(&local_60,"="), pcVar5 != (char *)0x0)) {
        pcVar5 = strsep(&local_60,"\n");
        bVar1 = pcVar5 == (char *)0x0;
        *param_2 = pcVar5;
        goto LAB_00101e2c;
      }
    }
  }
LAB_00101e28:
  bVar1 = true;
LAB_00101e2c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101f1c size=52
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  mmi_storage_info_exit();
  mmi_ram_info_exit();
  mmi_unit_info_exit();
  mmi_boot_info_exit();
  kfree(bootargs_str);
  return;
}



//------------------------------------------------------------
// init_module @ 00103620 size=656
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = (char *)0x0;
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  if (lVar3 != 0) {
    of_property_read_variable_u32_array(lVar3,"mmi,powerup_reason",&DAT_00103094,1,0);
    of_property_read_variable_u32_array(lVar3,"mmi,mbmversion",&DAT_0010309c,1,0);
    of_property_read_variable_u32_array(lVar3,"mmi,boot_seq",&DAT_001030a0,1,0);
    of_property_read_variable_u32_array(lVar3,"mmi,prod_id",&DAT_00103098,1,0);
    of_property_read_variable_u32_array(lVar3,"linux,hwrev",&mmi_chosen_data,1,0);
    of_property_read_variable_u32_array(lVar3,"linux,seriallow",&DAT_0010308c,1,0);
    of_property_read_variable_u32_array(lVar3,"linux,serialhigh",0x103090,1,0);
    iVar2 = of_property_read_string(lVar3,"mmi,baseband",&local_40);
    pcVar1 = local_40;
    if (iVar2 == 0) {
      sVar4 = strlen(local_40);
      if (0x5f < sVar4) {
        sVar4 = 0x60;
      }
      memcpy(&DAT_001030a4,pcVar1,sVar4);
      (&DAT_001030a4)[sVar4] = 0;
    }
    iVar2 = of_property_read_string(lVar3,"mmi,msm_hw",&local_40);
    pcVar1 = local_40;
    if (iVar2 == 0) {
      sVar4 = strlen(local_40);
      if (0x1e < sVar4) {
        sVar4 = 0x1f;
      }
      memcpy(&DAT_00103105,pcVar1,sVar4);
      (&DAT_00103105)[sVar4] = 0;
    }
    iVar2 = of_property_read_string(lVar3,"mmi,chipid",&local_40);
    pcVar1 = local_40;
    if (iVar2 == 0) {
      sVar4 = strlen(local_40);
      if (0x1e < sVar4) {
        sVar4 = 0x1f;
      }
      memcpy(&DAT_00103125,pcVar1,sVar4);
      (&DAT_00103125)[sVar4] = 0;
    }
    iVar2 = of_property_read_string(lVar3,"mmi,hardware_name",&local_40);
    pcVar1 = local_40;
    if (iVar2 == 0) {
      sVar4 = strlen(local_40);
      if (0x1f < sVar4) {
        sVar4 = 0x20;
      }
      memcpy(&DAT_00103145,pcVar1,sVar4);
      (&DAT_00103145)[sVar4] = 0;
      _printk(&DAT_001021c8,pcVar1);
    }
  }
  mmi_storage_info_init();
  mmi_ram_info_init();
  mmi_unit_info_init();
  mmi_boot_info_init();
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00105000 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [mmi_check_dynamic_device_node, mmi_get_bootarg, mmi_boot_info_init, mmi_device_is_available, init_module, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105010 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mmi_unit_info_init, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105018 size=1
// signature: undefined _printk(void)
// callers: [mmi_check_dynamic_device_node, mmi_boot_info_init, mmi_ram_info_init, mmi_unit_info_init, init_module, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105020 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mmi_boot_info_init, mmi_device_is_available, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00105028 size=1
// signature: size_t strlen(char * __s)
// callers: [mmi_get_bootarg, mmi_boot_info_init, mmi_unit_info_init, init_module, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105030 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mmi_boot_info_init, mmi_unit_info_init, init_module, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 00105038 size=1
// signature: undefined strlcpy(void)
// callers: [mmi_get_bootarg, bi_add_bl_build_sig, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_annotate_persist @ 00105040 size=1
// signature: undefined mmi_annotate_persist(void)
// callers: [mmi_boot_info_init, mmi_ram_info_init, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_annotate_persist(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00105048 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [mmi_ram_info_init, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00105050 size=1
// signature: undefined sysfs_create_group(void)
// callers: [mmi_ram_info_init, mmi_storage_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105058 size=1
// signature: undefined kfree(void)
// callers: [mmi_storage_info_exit, mmi_unit_info_init, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00105060 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [mmi_storage_info_exit, mmi_ram_info_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_del @ 00105068 size=1
// signature: undefined kobject_del(void)
// callers: [mmi_storage_info_exit, mmi_ram_info_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00105070 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [info_show, type_show, model_show, mr_register_show, fw_show, size_show, mmi_ram_info_init, vendor_show, type_show, size_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00105078 size=1
// signature: undefined qcom_smem_get(void)
// callers: [mmi_ram_info_init, mmi_unit_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mmi_check_dynamic_device_node, mmi_get_bootarg, mmi_boot_info_init, mmi_device_is_available, mmi_ram_info_init, mmi_unit_info_init, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00105088 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [unitinfo_seq_show, mr_register_show, mmi_unit_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00105090 size=1
// signature: undefined fortify_panic(void)
// callers: [unitinfo_seq_show, mr_register_show, mmi_unit_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00105098 size=1
// signature: undefined kstrtouint(void)
// callers: [mmi_unit_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_alloc @ 001050a0 size=1
// signature: undefined qcom_smem_alloc(void)
// callers: [mmi_unit_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create @ 001050a8 size=1
// signature: undefined proc_create(void)
// callers: [mmi_boot_info_init, mmi_unit_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 001050b0 size=1
// signature: undefined remove_proc_entry(void)
// callers: [mmi_unit_info_exit, mmi_boot_info_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001050b8 size=1
// signature: undefined single_open(void)
// callers: [bootinfo_proc_open, unitinfo_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001050c0 size=1
// signature: undefined seq_printf(void)
// callers: [unitinfo_seq_show, get_bootinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memchr @ 001050e0 size=1
// signature: void * memchr(void * __s, int __c, size_t __n)
// callers: [bi_add_bl_build_sig]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memchr(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_annotate @ 001050f0 size=1
// signature: undefined mmi_annotate(void)
// callers: [mmi_boot_info_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_annotate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001050f8 size=1
// signature: undefined of_find_property(void)
// callers: [mmi_check_dynamic_device_node, mmi_device_is_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_prop_next_string @ 00105100 size=1
// signature: undefined of_prop_next_string(void)
// callers: [mmi_check_dynamic_device_node, mmi_device_is_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_prop_next_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00105108 size=1
// signature: undefined of_get_property(void)
// callers: [mmi_device_is_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 00105110 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [mmi_check_dynamic_device_node, mmi_device_is_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105118 size=1
// signature: undefined of_property_read_string(void)
// callers: [mmi_get_bootarg, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105120 size=1
// signature: undefined __kmalloc(void)
// callers: [mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00105128 size=1
// signature: undefined strnstr(void)
// callers: [mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00105130 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105138 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



