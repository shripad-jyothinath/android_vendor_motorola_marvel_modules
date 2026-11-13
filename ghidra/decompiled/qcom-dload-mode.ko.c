// Decompiled by Ghidra 12.2
// Program: qcom-dload-mode.ko
// Image base: 00100000

//------------------------------------------------------------
// get_dump_mode @ 001003c4 size=12
// signature: undefined get_dump_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 get_dump_mode(void)

{
  return dump_mode;
}



//------------------------------------------------------------
// param_set_download_mode @ 001003d4 size=148
// signature: undefined param_set_download_mode(void)
// callers: []
//------------------------------------------------------------

int param_set_download_mode(void)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  
  iVar1 = param_set_bool();
  uVar3 = dump_mode;
  if (iVar1 != 0) {
    return iVar1;
  }
  if (enable_dump == '\0') {
    uVar3 = 0;
  }
  else if (((dump_mode >> 5 & 1) != 0) && (uVar2 = msm_minidump_enabled(), (uVar2 & 1) == 0)) {
    uVar3 = uVar3 & 0xffffffdf;
    _printk(&DAT_00101829);
    if (uVar3 == 0) goto LAB_00100444;
  }
  current_download_mode = uVar3;
  qcom_scm_set_download_mode(uVar3,0);
LAB_00100444:
  if (enable_dump == '\0') {
    qcom_scm_disable_sdi();
  }
  return 0;
}



//------------------------------------------------------------
// msm_enable_dump_mode @ 00100468 size=104
// signature: undefined msm_enable_dump_mode(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

void msm_enable_dump_mode(ulong param_1)

{
  ulong uVar1;
  uint uVar2;
  
  uVar2 = dump_mode;
  if ((param_1 & 1) == 0) {
    uVar2 = 0;
  }
  else if (((dump_mode >> 5 & 1) != 0) && (uVar1 = msm_minidump_enabled(), (uVar1 & 1) == 0)) {
    uVar2 = uVar2 & 0xffffffdf;
    _printk(&DAT_00101829);
    if (uVar2 == 0) {
      return;
    }
  }
  current_download_mode = uVar2;
  qcom_scm_set_download_mode(uVar2,0);
  return;
}



//------------------------------------------------------------
// qcom_dload_probe @ 001004d4 size=616
// signature: undefined qcom_dload_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_dload_probe(long param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  puVar5 = (undefined8 *)devm_kmalloc(param_1 + 0x10,0xd8,0xdc0);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0xc;
  }
  else {
    puVar1 = puVar5 + 9;
    puVar5[0x1a] = param_1 + 0x10;
    iVar4 = kobject_init_and_add(puVar1,qcom_dload_kobj_type,_kernel_kobj,"dload");
    if (iVar4 == 0) {
      iVar4 = sysfs_create_group(puVar1,qcom_dload_attr_group);
      if (iVar4 == 0) {
        uVar6 = map_prop_mem();
        puVar5[0x16] = uVar6;
        if (dump_mode_name == 0x6c6c7566 && DAT_00101a18 == '\0') {
          dump_mode = 0x10;
        }
        else if (dump_mode_name == 0x696e696d && DAT_00101a18 == '\0') {
          dump_mode = 0x20;
        }
        else {
          dump_mode = 0;
          if (dump_mode_name == 0x68746f62 && DAT_00101a18 == '\0') {
            dump_mode = 0x30;
          }
        }
        msm_enable_dump_mode(enable_dump);
        puVar2 = &local_4c;
        iVar4 = qcom_scm_get_download_mode(&local_4c,0);
        if (iVar4 != 0) {
          puVar2 = &dump_mode;
        }
        dump_mode = *puVar2;
        _printk(&DAT_001017e7,"qcom_dload_probe");
        if (enable_dump == '\0') {
          qcom_scm_disable_sdi();
        }
        *(undefined4 *)(puVar5 + 2) = 0x7fffffff;
        *puVar5 = qcom_dload_panic;
        atomic_notifier_chain_register(&panic_notifier_list,puVar5);
        *(undefined4 *)(puVar5 + 5) = 0xff;
        puVar5[3] = qcom_dload_reboot;
        register_reboot_notifier();
        *(undefined4 *)(puVar5 + 8) = 0xc9;
        puVar5[6] = qcom_dload_restart;
        register_restart_handler();
        *(undefined8 **)(param_1 + 0xa8) = puVar5;
        iVar4 = poweroff_init_regulator(puVar5);
        if (iVar4 != 0) {
          _printk(&DAT_001017a5);
        }
        iVar4 = 0;
      }
      else {
        _printk(&DAT_001018de,"qcom_dload_probe");
        kobject_del(puVar1);
      }
    }
    else {
      _printk(&DAT_001019b7,"qcom_dload_probe");
      kobject_put(puVar1);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qcom_dload_remove @ 00100740 size=84
// signature: undefined qcom_dload_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dload_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  atomic_notifier_chain_unregister(&panic_notifier_list,lVar1);
  unregister_restart_handler(lVar1 + 0x30);
  unregister_reboot_notifier(lVar1 + 0x18);
  if (*(long *)(lVar1 + 0xb0) != 0) {
    iounmap();
  }
  return 0;
}



//------------------------------------------------------------
// map_prop_mem @ 00100794 size=100
// signature: undefined map_prop_mem(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

long map_prop_mem(void)

{
  long lVar1;
  undefined *puVar2;
  
  lVar1 = of_find_compatible_node(0,0,"qcom,msm-imem-dload-type");
  if (lVar1 == 0) {
    puVar2 = &DAT_001016e0;
  }
  else {
    lVar1 = of_iomap(lVar1,0);
    if (lVar1 != 0) {
      return lVar1;
    }
    puVar2 = &DAT_00101756;
  }
  _printk(puVar2,"qcom,msm-imem-dload-type");
  return 0;
}



//------------------------------------------------------------
// qcom_dload_panic @ 001007fc size=120
// signature: undefined qcom_dload_panic(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dload_panic(long param_1)

{
  char cVar1;
  ulong uVar2;
  uint uVar3;
  
  cVar1 = enable_dump;
  *(undefined1 *)(param_1 + 0xa8) = 1;
  uVar3 = dump_mode;
  if (cVar1 != '\0') {
    if (((dump_mode >> 5 & 1) != 0) && (uVar2 = msm_minidump_enabled(), (uVar2 & 1) == 0)) {
      uVar3 = uVar3 & 0xffffffdf;
      _printk(&DAT_00101829);
      if (uVar3 == 0) {
        return 1;
      }
    }
    current_download_mode = uVar3;
    qcom_scm_set_download_mode(uVar3,0);
  }
  return 1;
}



//------------------------------------------------------------
// qcom_dload_reboot @ 00100878 size=564
// signature: undefined qcom_dload_reboot(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_dload_reboot(long param_1,undefined8 param_2,char *param_3)

{
  undefined8 *puVar1;
  undefined *__s1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  
  _printk(&DAT_0010170e,"qcom_dload_reboot",sys_restart_mode);
  __s1 = sys_restart_mode;
  iVar4 = strcmp(sys_restart_mode,"panic");
  if (iVar4 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100aa8);
    (*pcVar2)();
  }
  iVar4 = strcmp(__s1,"recovery_panic");
  if ((iVar4 == 0) && (iVar4 = strcmp(param_3,"recovery"), iVar4 == 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100aac);
    (*pcVar2)();
  }
  *(undefined1 *)(param_1 + 0x91) = 1;
  current_download_mode = 0;
  qcom_scm_set_download_mode(0,0);
  if (param_3 != (char *)0x0) {
    iVar4 = strcmp(param_3,"edl");
    if (iVar4 == 0) {
      *(undefined1 *)(param_1 + 0x92) = 1;
      _printk(&DAT_0010199e);
      if ((*(char *)(param_1 + 0x92) != '\0') && (0 < *(int *)(param_1 + 0xb0))) {
        lVar7 = 0;
        lVar8 = 0;
        do {
          puVar1 = (undefined8 *)(*(long *)(param_1 + 0xa8) + lVar7);
          regulator_set_voltage(*puVar1,*(undefined4 *)(puVar1 + 1),0x7fffffff);
          puVar1 = (undefined8 *)(*(long *)(param_1 + 0xa8) + lVar7);
          regulator_set_load(*puVar1,*(undefined4 *)((long)puVar1 + 0xc));
          iVar4 = regulator_enable(*(undefined8 *)(*(long *)(param_1 + 0xa8) + lVar7));
          if (iVar4 != 0) {
            _printk(&DAT_0010189a,iVar4);
            uVar6 = *(int *)(param_1 + 0xb0) - 1;
            if (-1 < (int)uVar6) {
              lVar8 = (ulong)uVar6 << 4;
              do {
                regulator_set_voltage
                          (*(undefined8 *)(*(long *)(param_1 + 0xa8) + lVar8),0,0x7fffffff);
                regulator_set_load(*(undefined8 *)(*(long *)(param_1 + 0xa8) + lVar8),0);
                regulator_disable(*(undefined8 *)(*(long *)(param_1 + 0xa8) + lVar8));
                bVar3 = lVar8 != 0;
                lVar8 = lVar8 + -0x10;
              } while (bVar3);
            }
            _dev_err(*(undefined8 *)(param_1 + 0xb8),"Regulator enable failed(rc:%d)\n",iVar4);
            break;
          }
          lVar8 = lVar8 + 1;
          lVar7 = lVar7 + 0x10;
        } while (lVar8 < *(int *)(param_1 + 0xb0));
      }
    }
    else {
      iVar4 = strcmp(param_3,"qcom_dload");
      uVar6 = dump_mode;
      if (iVar4 == 0) {
        if (((dump_mode >> 5 & 1) != 0) && (uVar5 = msm_minidump_enabled(), (uVar5 & 1) == 0)) {
          uVar6 = uVar6 & 0xffffffdf;
          _printk(&DAT_00101829);
          if (uVar6 == 0) goto LAB_00100960;
        }
        current_download_mode = uVar6;
        qcom_scm_set_download_mode(uVar6,0);
      }
    }
  }
LAB_00100960:
  if (current_download_mode != 0) {
    _reboot_mode = 1;
  }
  return 1;
}



//------------------------------------------------------------
// qcom_dload_restart @ 00100ab0 size=68
// signature: undefined qcom_dload_restart(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dload_restart(long param_1)

{
  if ((*(char *)(param_1 + 0x78) == '\0') && (*(char *)(param_1 + 0x79) == '\0')) {
    qcom_scm_disable_sdi();
    current_download_mode = 0;
    qcom_scm_set_download_mode(0,0);
  }
  return 1;
}



//------------------------------------------------------------
// poweroff_init_regulator @ 00100af4 size=520
// signature: undefined poweroff_init_regulator(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

int poweroff_init_regulator(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  char *local_98;
  undefined4 local_8c;
  undefined8 local_88;
  char local_80 [56];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_8c = 0;
  local_80[0x30] = '\0';
  local_80[0x31] = '\0';
  local_80[0x20] = '\0';
  local_80[0x21] = '\0';
  local_80[0x22] = '\0';
  local_80[0x23] = '\0';
  local_80[0x24] = '\0';
  local_80[0x25] = '\0';
  local_80[0x26] = '\0';
  local_80[0x27] = '\0';
  local_80[0x28] = '\0';
  local_80[0x29] = '\0';
  local_80[0x2a] = '\0';
  local_80[0x2b] = '\0';
  local_80[0x2c] = '\0';
  local_80[0x2d] = '\0';
  local_80[0x2e] = '\0';
  local_80[0x2f] = '\0';
  local_80[0x10] = '\0';
  local_80[0x11] = '\0';
  local_80[0x12] = '\0';
  local_80[0x13] = '\0';
  local_80[0x14] = '\0';
  local_80[0x15] = '\0';
  local_80[0x16] = '\0';
  local_80[0x17] = '\0';
  local_80[0x18] = '\0';
  local_80[0x19] = '\0';
  local_80[0x1a] = '\0';
  local_80[0x1b] = '\0';
  local_80[0x1c] = '\0';
  local_80[0x1d] = '\0';
  local_80[0x1e] = '\0';
  local_80[0x1f] = '\0';
  local_80[0] = '\0';
  local_80[1] = '\0';
  local_80[2] = '\0';
  local_80[3] = '\0';
  local_80[4] = '\0';
  local_80[5] = '\0';
  local_80[6] = '\0';
  local_80[7] = '\0';
  local_80[8] = '\0';
  local_80[9] = '\0';
  local_80[10] = '\0';
  local_80[0xb] = '\0';
  local_80[0xc] = '\0';
  local_80[0xd] = '\0';
  local_80[0xe] = '\0';
  local_80[0xf] = '\0';
  local_88 = 0;
  local_98 = (char *)0x0;
  uVar1 = of_property_read_string_helper
                    (*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x2e8),"reg-names",0,0,0);
  *(uint *)(param_1 + 200) = uVar1;
  if ((int)uVar1 < 1) {
    _printk(&DAT_0010192a);
  }
  else {
    lVar3 = devm_kmalloc(*(undefined8 *)(param_1 + 0xd0),(ulong)uVar1 << 4,0xdc0);
    *(long *)(param_1 + 0xc0) = lVar3;
    if (lVar3 == 0) {
      iVar2 = -0xc;
      goto LAB_00100c90;
    }
    if (0 < *(int *)(param_1 + 200)) {
      lVar3 = 0;
      uVar6 = 0;
      do {
        of_property_read_string_helper
                  (*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x2e8),"reg-names",&local_98,1,
                   uVar6 & 0xffffffff);
        uVar4 = devm_regulator_get(*(undefined8 *)(param_1 + 0xd0),local_98);
        *(undefined8 *)(*(long *)(param_1 + 0xc0) + lVar3) = uVar4;
        if (0xfffffffffffff000 < *(ulong *)(*(long *)(param_1 + 0xc0) + lVar3)) {
          _printk(&DAT_001018bc,local_98);
          iVar2 = *(int *)(*(long *)(param_1 + 0xc0) + lVar3);
          goto LAB_00100c90;
        }
        snprintf(local_80,0x32,"%s-uV-uA",local_98);
        lVar5 = of_find_property(*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x2e8),local_80,
                                 &local_8c);
        if (lVar5 != 0) {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0x2e8),local_80,&local_88,2
                             ,0);
          if (iVar2 < 0) {
            _printk(&DAT_00101847,iVar2);
            goto LAB_00100c90;
          }
          if ((int)local_88 != 0) {
            *(int *)(*(long *)(param_1 + 0xc0) + lVar3 + 8) = (int)local_88;
          }
          if (local_88._4_4_ != 0) {
            *(int *)(*(long *)(param_1 + 0xc0) + lVar3 + 0xc) = local_88._4_4_;
          }
        }
        uVar6 = uVar6 + 1;
        lVar3 = lVar3 + 0x10;
      } while ((long)uVar6 < (long)*(int *)(param_1 + 200));
    }
  }
  iVar2 = 0;
LAB_00100c90:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// attr_show @ 00100d00 size=68
// signature: undefined attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_show(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x40e7484a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100d2c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00100d48 size=68
// signature: undefined attr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_store(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5800598) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100d74);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// emmc_dload_show @ 00100d90 size=80
// signature: undefined emmc_dload_show(void)
// callers: []
//------------------------------------------------------------

long emmc_dload_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(int **)(param_1 + 0x68) == (int *)0x0) {
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010170a,**(int **)(param_1 + 0x68) == 2);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// emmc_dload_store @ 00100de4 size=172
// signature: undefined emmc_dload_store(void)
// callers: []
//------------------------------------------------------------

long emmc_dload_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  if (*(long *)(param_1 + 0x68) == 0) {
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtobool(param_3,local_2c);
    if (iVar2 < 0) {
      param_4 = (long)iVar2;
    }
    else {
      puVar3 = *(undefined4 **)(param_1 + 0x68);
      if (local_2c[0] == '\0') {
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = 0;
        }
      }
      else if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = 2;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dload_mode_show @ 00100e94 size=124
// signature: undefined dload_mode_show(void)
// callers: []
//------------------------------------------------------------

long dload_mode_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  
  if (dump_mode == 0x10) {
    pcVar2 = "full";
  }
  else if (dump_mode == 0x30) {
    pcVar2 = "both";
  }
  else if (dump_mode == 0x20) {
    pcVar2 = "mini";
  }
  else {
    pcVar2 = "unknown";
  }
  iVar1 = scnprintf(param_3,0x1000,"DLOAD dump type: %s\n",pcVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// dload_mode_store @ 00100f14 size=424
// signature: undefined dload_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8
dload_mode_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  long lVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar6 = sysfs_streq(param_3,&DAT_001017d1);
  if ((uVar6 & 1) == 0) {
    uVar7 = sysfs_streq(param_3,&DAT_00101895);
    if ((uVar7 & 1) == 0) {
      uVar7 = sysfs_streq(param_3,&DAT_00101842);
      if ((uVar7 & 1) == 0) {
        _printk(&DAT_00101875);
        _printk(&DAT_0010194c);
        uVar8 = 0xffffffffffffffea;
        goto LAB_00101024;
      }
      uVar9 = 0x30;
    }
    else {
      uVar9 = 0x20;
    }
    local_3c = 0;
    if (enable_dump == '\0') goto LAB_00101018;
    if (((uVar6 & 1) == 0) && (uVar6 = msm_minidump_enabled(), (uVar6 & 1) == 0)) {
      _printk(&DAT_00101829);
      if ((uVar9 >> 4 & 1) != 0) {
        uVar4 = uVar9 & 0x10;
        goto LAB_00100fc8;
      }
      bVar3 = false;
      uVar8 = 0xffffffffffffffed;
      if (dump_mode != uVar9) goto LAB_0010109c;
    }
    else {
      uVar4 = uVar9;
LAB_00100fc8:
      current_download_mode = uVar4;
      qcom_scm_set_download_mode(current_download_mode,0);
      puVar1 = &local_3c;
      iVar5 = qcom_scm_get_download_mode(&local_3c,0);
      uVar8 = 0;
      if (iVar5 != 0) {
        puVar1 = &dump_mode;
      }
      bVar3 = true;
      dump_mode = *puVar1;
      if (dump_mode != uVar9) {
LAB_0010109c:
        _printk(&DAT_00101806);
      }
    }
    if (!bVar3) goto LAB_00101024;
  }
  else {
    uVar9 = 0x10;
    local_3c = 0;
    uVar4 = 0x10;
    if (enable_dump != '\0') goto LAB_00100fc8;
LAB_00101018:
    local_3c = 0;
    dump_mode = uVar9;
  }
  uVar8 = param_4;
LAB_00101024:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// init_module @ 001010d4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_dload_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101104 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_dload_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// param_set_bool @ 00103010 size=1
// signature: undefined param_set_bool(void)
// callers: [param_set_download_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void param_set_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_enabled @ 00103018 size=1
// signature: undefined msm_minidump_enabled(void)
// callers: [param_set_download_mode, msm_enable_dump_mode, qcom_dload_panic, dload_mode_store, qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103020 size=1
// signature: undefined _printk(void)
// callers: [param_set_download_mode, msm_enable_dump_mode, map_prop_mem, qcom_dload_panic, poweroff_init_regulator, qcom_dload_probe, dload_mode_store, qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_set_download_mode @ 00103028 size=1
// signature: undefined qcom_scm_set_download_mode(void)
// callers: [param_set_download_mode, msm_enable_dump_mode, qcom_dload_panic, dload_mode_store, qcom_dload_restart, qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_set_download_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_disable_sdi @ 00103030 size=1
// signature: undefined qcom_scm_disable_sdi(void)
// callers: [param_set_download_mode, qcom_dload_probe, qcom_dload_restart]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_disable_sdi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103038 size=1
// signature: undefined devm_kmalloc(void)
// callers: [poweroff_init_regulator, qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00103048 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00103050 size=1
// signature: undefined sysfs_create_group(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00103058 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_del @ 00103060 size=1
// signature: undefined kobject_del(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_get_download_mode @ 00103068 size=1
// signature: undefined qcom_scm_get_download_mode(void)
// callers: [qcom_dload_probe, dload_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_get_download_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00103078 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 00103080 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_restart_handler @ 00103088 size=1
// signature: undefined register_restart_handler(void)
// callers: [qcom_dload_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103090 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [poweroff_init_regulator, qcom_dload_probe, emmc_dload_store, dload_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00103098 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [qcom_dload_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_restart_handler @ 001030a0 size=1
// signature: undefined unregister_restart_handler(void)
// callers: [qcom_dload_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 001030a8 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [qcom_dload_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 001030b0 size=1
// signature: undefined iounmap(void)
// callers: [qcom_dload_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 001030b8 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [map_prop_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 001030c0 size=1
// signature: undefined of_iomap(void)
// callers: [map_prop_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001030c8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001030d8 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 001030e0 size=1
// signature: undefined regulator_set_load(void)
// callers: [qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001030e8 size=1
// signature: undefined regulator_enable(void)
// callers: [qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001030f0 size=1
// signature: undefined regulator_disable(void)
// callers: [qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030f8 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_dload_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00103100 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [poweroff_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00103108 size=1
// signature: undefined devm_regulator_get(void)
// callers: [poweroff_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103110 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [poweroff_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103118 size=1
// signature: undefined of_find_property(void)
// callers: [poweroff_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103120 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [poweroff_init_regulator]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103128 size=1
// signature: undefined scnprintf(void)
// callers: [dload_mode_show, emmc_dload_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 00103130 size=1
// signature: undefined kstrtobool(void)
// callers: [emmc_dload_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_streq @ 00103138 size=1
// signature: undefined sysfs_streq(void)
// callers: [dload_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_streq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



