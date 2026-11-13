// Decompiled by Ghidra 12.2
// Program: qcom_va_minidump.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_va_md_enabled @ 0010039c size=56
// signature: undefined qcom_va_md_enabled(void)
// callers: []
//------------------------------------------------------------

byte qcom_va_md_enabled(void)

{
  byte bVar1;
  ulong uVar2;
  
  uVar2 = msm_minidump_enabled();
  if ((uVar2 & 1) == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = DAT_001019aa & 1;
  }
  return bVar1;
}



//------------------------------------------------------------
// qcom_va_md_register @ 001003d8 size=624
// signature: undefined qcom_va_md_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_va_md_register(undefined8 param_1,long *param_2)

{
  long *plVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  undefined *puVar6;
  long *plVar7;
  long lVar8;
  long *plVar9;
  
  uVar3 = msm_minidump_enabled();
  if (((uVar3 & 1) == 0) || ((DAT_001019aa & 1) == 0)) {
    _printk(&DAT_00101a79,"qcom_va_md_register");
    return -0x13;
  }
  plVar4 = (long *)kmalloc_trace(_sysfs_create_group,0xdc0,0x28);
  if (plVar4 == (long *)0x0) {
    return -0xc;
  }
  lVar5 = param_2[1];
  lVar8 = param_2[2];
  *plVar4 = *param_2;
  plVar4[1] = lVar5;
  plVar4[2] = lVar8;
  mutex_lock(&va_md_lock);
  lVar5 = kset_find_obj(DAT_001019c0,param_1);
  if (lVar5 == 0) {
    lVar5 = kmalloc_trace(_mutex_lock,0xdc0,0x98);
    if (lVar5 == 0) {
      kfree(plVar4);
      iVar2 = -0xc;
      goto LAB_0010059c;
    }
    lVar8 = DAT_001019c0 + 0x18;
    *(long *)(lVar5 + 0x20) = DAT_001019c0;
    iVar2 = kobject_init_and_add(lVar5,va_md_kobj_type,lVar8,param_1);
    if (iVar2 == 0) {
      kobject_uevent(lVar5,0);
      iVar2 = sysfs_create_group(lVar5,va_md_s_attr_group);
      if (iVar2 == 0) {
        *(undefined4 *)(lVar5 + 0x60) = 0;
        *(undefined8 *)(lVar5 + 0x68) = 0;
        plVar1 = (long *)(lVar5 + 0x70);
        *(long *)(lVar5 + 0x80) = lVar5 + 0x80;
        *(long *)(lVar5 + 0x88) = lVar5 + 0x80;
        plVar7 = DAT_001019b8;
        *(undefined1 *)(lVar5 + 0x90) = 0;
        uVar3 = __list_add_valid(plVar1,plVar7,&DAT_001019b0);
        if ((uVar3 & 1) != 0) {
          DAT_001019b8 = plVar1;
          *(undefined8 **)(lVar5 + 0x70) = &DAT_001019b0;
          *(long **)(lVar5 + 0x78) = plVar7;
          *plVar7 = (long)plVar1;
        }
        goto LAB_00100500;
      }
      puVar6 = &DAT_001019cc;
    }
    else {
      puVar6 = &DAT_00101d85;
    }
    _printk(puVar6,"qcom_va_md_register","qcom_va_md_register");
    kobject_put(lVar5);
    kfree(plVar4);
  }
  else {
    _printk(&DAT_00101b9b,"qcom_va_md_register",param_1);
    kobject_put(lVar5);
LAB_00100500:
    plVar1 = (long *)(lVar5 + 0x80);
    plVar7 = plVar1;
    do {
      plVar7 = (long *)*plVar7;
      if (plVar7 == plVar1) {
        atomic_notifier_chain_register(lVar5 + 0x60,plVar4);
        plVar9 = *(long **)(lVar5 + 0x88);
        plVar7 = plVar4 + 3;
        uVar3 = __list_add_valid(plVar7,plVar9,plVar1);
        iVar2 = 0;
        if ((uVar3 & 1) != 0) {
          *(long **)(lVar5 + 0x88) = plVar7;
          plVar4[3] = (long)plVar1;
          plVar4[4] = (long)plVar9;
          *plVar9 = (long)plVar7;
        }
        goto LAB_0010059c;
      }
    } while (plVar7[-3] != *plVar4);
    _printk(&DAT_00101a09,"qcom_va_md_register",param_1);
    kfree(plVar4);
    iVar2 = -0x11;
  }
LAB_0010059c:
  mutex_unlock(&va_md_lock);
  return iVar2;
}



//------------------------------------------------------------
// qcom_va_md_unregister @ 0010064c size=452
// signature: undefined qcom_va_md_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_va_md_unregister(undefined8 param_1,long *param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  
  uVar4 = msm_minidump_enabled();
  if (((uVar4 & 1) == 0) || ((DAT_001019aa & 1) == 0)) {
    _printk(&DAT_00101a79,"qcom_va_md_unregister");
    uVar6 = 0xffffffed;
  }
  else {
    mutex_lock(&va_md_lock);
    lVar5 = kset_find_obj(DAT_001019c0,param_1);
    if (lVar5 == 0) {
      _printk(&DAT_00101db7,"qcom_va_md_unregister",param_1);
      mutex_unlock(&va_md_lock);
      uVar6 = 0xffffffea;
    }
    else {
      kobject_put();
      plVar1 = (long *)(lVar5 + 0x80);
      plVar7 = plVar1;
      do {
        plVar7 = (long *)*plVar7;
        if (plVar7 == plVar1) {
          _printk(&DAT_00101c24,"qcom_va_md_unregister",param_1);
          uVar6 = 0xffffffea;
          goto LAB_00100780;
        }
      } while (plVar7[-3] != *param_2);
      atomic_notifier_chain_unregister(lVar5 + 0x60,plVar7 + -3);
      uVar4 = __list_del_entry_valid(plVar7);
      if ((uVar4 & 1) != 0) {
        lVar2 = *plVar7;
        plVar3 = (long *)plVar7[1];
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      *plVar7 = -0x2152ffffffffff00;
      plVar7[1] = -0x2152fffffffffede;
      kfree(plVar7 + -3);
      if ((long *)*plVar1 == plVar1) {
        uVar4 = __list_del_entry_valid(plVar1);
        if ((uVar4 & 1) != 0) {
          lVar2 = *(long *)(lVar5 + 0x80);
          plVar1 = *(long **)(lVar5 + 0x88);
          *(long **)(lVar2 + 8) = plVar1;
          *plVar1 = lVar2;
        }
        *(undefined8 *)(lVar5 + 0x80) = 0xdead000000000100;
        *(undefined8 *)(lVar5 + 0x88) = 0xdead000000000122;
        sysfs_remove_group(lVar5,va_md_s_attr_group);
        kobject_put(lVar5);
        uVar4 = __list_del_entry_valid(lVar5 + 0x70);
        if ((uVar4 & 1) != 0) {
          lVar2 = *(long *)(lVar5 + 0x70);
          plVar1 = *(long **)(lVar5 + 0x78);
          *(long **)(lVar2 + 8) = plVar1;
          *plVar1 = lVar2;
        }
        *(undefined8 *)(lVar5 + 0x70) = 0xdead000000000100;
        *(undefined8 *)(lVar5 + 0x78) = 0xdead000000000122;
        kfree(lVar5);
      }
      uVar6 = 0;
LAB_00100780:
      mutex_unlock(&va_md_lock);
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// qcom_va_md_add_region @ 00100814 size=976
// signature: undefined qcom_va_md_add_region(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 qcom_va_md_add_region(ulong *param_1)

{
  uint *puVar1;
  uint *puVar2;
  long lVar3;
  ulong *puVar4;
  uint uVar5;
  long lVar6;
  size_t sVar7;
  undefined *puVar8;
  char *pcVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined4 uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  uint uVar17;
  ulong uVar18;
  
  lVar6 = DAT_00101938;
  if (DAT_001019a8 == '\0') {
    return 0xffffffea;
  }
  if (((*param_1 != 0) != (param_1[6] == 0)) || ((int)param_1[5] == 0)) {
    puVar8 = &DAT_00101ae4;
    pcVar9 = "qcom_va_md_add_region";
    *(undefined1 *)((long)param_1 + 0x27) = 0;
LAB_00100b9c:
    _printk(puVar8,pcVar9,param_1 + 1);
    return 0xffffffea;
  }
  uVar18 = (ulong)DAT_00101940;
  if (0xffff < DAT_00101940) {
    _printk(&DAT_00101cf9,"qcom_va_md_add_region");
    return 0xffffffe4;
  }
  if ((DAT_00101938 + (ulong)DAT_00101930) - 1 < DAT_00101938 + uVar18 * 0x40 + 0x3f) {
    _printk(&DAT_00101b14,"qcom_va_md_add_region");
    return 0xfffffff4;
  }
  if ((*param_1 == 0) || (DAT_00101940 == 0)) {
    sVar7 = strnlen((char *)(param_1 + 1),0x20);
    if (sVar7 < 0x21) {
      if (sVar7 != 0x20) {
        uVar10 = param_1[3];
        puVar4 = (ulong *)(lVar6 + uVar18 * 0x40);
        uVar18 = param_1[5];
        uVar12 = param_1[6];
        puVar4[4] = param_1[4];
        uVar11 = *param_1;
        uVar14 = param_1[1];
        uVar15 = param_1[2];
        puVar4[5] = uVar18;
        puVar4[6] = uVar12;
        *(undefined1 *)((long)puVar4 + 0x27) = 0;
        *puVar4 = uVar11;
        puVar4[1] = uVar14;
        puVar4[2] = uVar15;
        puVar4[3] = uVar10;
        uVar13 = 0xfffffffe;
        if (*param_1 != 0) {
          uVar13 = 0xffffffff;
        }
        *(undefined4 *)(puVar4 + 7) = uVar13;
        *(undefined4 *)((long)puVar4 + 0x3c) = uVar13;
        DAT_00101940 = DAT_00101940 + 1;
        return 0;
      }
      goto LAB_00100bd8;
    }
  }
  else {
    uVar10 = 0;
    do {
      lVar3 = lVar6 + uVar10 * 0x40;
      puVar1 = (uint *)(lVar3 + 0x38);
      puVar2 = (uint *)(lVar3 + 0x3c);
      while( true ) {
        uVar5 = *puVar1;
        uVar11 = (ulong)uVar5;
        uVar17 = (uint)uVar18;
        if ((uVar5 == 0xfffffffe) && (*puVar2 == 0xfffffffe)) {
          uVar11 = (ulong)((uint)uVar10 + 1);
          goto LAB_00100980;
        }
        uVar15 = *param_1;
        puVar4 = (ulong *)(DAT_00101938 + uVar10 * 0x40);
        uVar12 = *puVar4;
        uVar14 = (uVar12 + (uint)puVar4[5]) - 1;
        if (((uVar12 <= uVar15 && uVar15 <= uVar14) ||
            (uVar16 = (uVar15 + (uint)param_1[5]) - 1, uVar12 <= uVar16 && uVar16 <= uVar14)) ||
           ((uVar15 <= uVar12 && (uVar14 <= uVar16)))) {
          *(undefined1 *)((long)param_1 + 0x27) = 0;
          puVar8 = &DAT_00101d55;
          pcVar9 = "va_md_tree_insert";
          goto LAB_00100b9c;
        }
        if ((uVar15 < uVar12) && (uVar16 < uVar12)) {
          if (uVar5 != 0xffffffff) goto LAB_00100980;
          *puVar1 = uVar17;
          goto LAB_00100a40;
        }
        if ((uVar14 < uVar15 && uVar14 <= uVar16) && (uVar15 <= uVar14 || uVar16 != uVar14)) break;
        _printk(&DAT_00101e8d,"va_md_tree_insert");
        uVar18 = (ulong)DAT_00101940;
        lVar3 = DAT_00101938;
        if (DAT_00101940 <= (uint)uVar10) goto joined_r0x00100ac4;
      }
      uVar11 = (ulong)*puVar2;
      if (*puVar2 == 0xffffffff) {
        *puVar2 = uVar17;
LAB_00100a40:
        lVar6 = DAT_00101938;
        uVar18 = (ulong)DAT_00101940;
        sVar7 = strnlen((char *)(param_1 + 1),0x20);
        if (0x20 < sVar7) goto LAB_00100bcc;
        if (sVar7 == 0x20) goto LAB_00100bd8;
        uVar10 = param_1[3];
        puVar4 = (ulong *)(lVar6 + uVar18 * 0x40);
        uVar18 = param_1[5];
        uVar12 = param_1[6];
        puVar4[4] = param_1[4];
        uVar11 = *param_1;
        uVar14 = param_1[1];
        uVar15 = param_1[2];
        puVar4[5] = uVar18;
        puVar4[6] = uVar12;
        *(undefined1 *)((long)puVar4 + 0x27) = 0;
        *puVar4 = uVar11;
        puVar4[1] = uVar14;
        puVar4[2] = uVar15;
        puVar4[3] = uVar10;
        uVar13 = 0xfffffffe;
        if (*param_1 != 0) {
          uVar13 = 0xffffffff;
        }
        *(undefined4 *)(puVar4 + 7) = uVar13;
        *(undefined4 *)((long)puVar4 + 0x3c) = uVar13;
        DAT_00101940 = DAT_00101940 + 1;
        uVar18 = (ulong)DAT_00101940;
        va_md_tree_insert_num_nodes = va_md_tree_insert_num_nodes + 1;
        lVar3 = DAT_00101938;
        break;
      }
LAB_00100980:
      uVar10 = uVar11;
      lVar3 = DAT_00101938;
    } while ((uint)uVar11 < uVar17);
joined_r0x00100ac4:
    if (va_md_tree_insert_num_nodes != 0) {
      DAT_00101938 = lVar3;
      return 0;
    }
    DAT_00101938 = lVar3;
    sVar7 = strnlen((char *)(param_1 + 1),0x20);
    if (sVar7 < 0x21) {
      if (sVar7 != 0x20) {
        uVar10 = param_1[3];
        puVar4 = (ulong *)(lVar3 + uVar18 * 0x40);
        uVar18 = param_1[5];
        uVar12 = param_1[6];
        puVar4[4] = param_1[4];
        uVar11 = *param_1;
        uVar14 = param_1[1];
        uVar15 = param_1[2];
        puVar4[5] = uVar18;
        puVar4[6] = uVar12;
        *(undefined1 *)((long)puVar4 + 0x27) = 0;
        *puVar4 = uVar11;
        puVar4[1] = uVar14;
        puVar4[2] = uVar15;
        puVar4[3] = uVar10;
        uVar13 = 0xfffffffe;
        if (*param_1 != 0) {
          uVar13 = 0xffffffff;
        }
        *(undefined4 *)(puVar4 + 7) = uVar13;
        *(undefined4 *)((long)puVar4 + 0x3c) = uVar13;
        DAT_00101940 = DAT_00101940 + 1;
        va_md_tree_insert_num_nodes = va_md_tree_insert_num_nodes + 1;
        return 0;
      }
      goto LAB_00100bd8;
    }
  }
LAB_00100bcc:
  fortify_panic("strnlen");
LAB_00100bd8:
  fortify_panic("__fortify_strlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// attr_show @ 00100be8 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100c14);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00100c30 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100c5c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// enable_show @ 00100c78 size=56
// signature: undefined enable_show(void)
// callers: []
//------------------------------------------------------------

long enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"enable: %u\n",*(undefined1 *)(param_1 + 0x90));
  return (long)iVar1;
}



//------------------------------------------------------------
// enable_store @ 00100cb4 size=156
// signature: undefined enable_store(void)
// callers: []
//------------------------------------------------------------

long enable_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  iVar2 = kstrtobool(param_3,local_3c);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x90) = local_3c[0];
  }
  else {
    _printk(&DAT_00101df9,"enable_store");
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qcom_va_md_driver_probe @ 00100d54 size=992
// signature: undefined qcom_va_md_driver_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_va_md_driver_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined *puVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  ulong local_b8;
  undefined8 local_b0;
  int iStack_ac;
  long local_a8 [11];
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_a8[10] = *(long *)(lVar7 + 0x638);
  local_b8 = 0;
  iVar6 = dma_set_mask(lVar1,0xffffffffffffffff);
  if (iVar6 == 0) {
    dma_set_coherent_mask(lVar1,0xffffffffffffffff);
    local_b0 = 0;
    local_a8[0] = 0;
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[1] = 0;
    iVar6 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2f8),"memory-region",0,0,0,local_a8);
    lVar7 = local_a8[0];
    if (iVar6 != 0) {
      lVar7 = 0;
    }
    if ((lVar7 == 0) ||
       (iVar6 = of_reserved_mem_device_init_by_idx(lVar1,*(undefined8 *)(param_1 + 0x2f8),0),
       iVar6 == 0)) {
      iVar6 = of_property_read_variable_u32_array(lVar7,&DAT_00101ab8,&stack0xffffffffffffff50,2,0);
      if (-1 < iVar6) {
        uVar18 = 0xffffffe1;
        DAT_00101930 = iStack_ac;
        do {
          bVar5 = 0xfffffffe < uVar18;
          uVar18 = uVar18 + 1;
          if (bVar5) goto LAB_00100f20;
          lVar7 = dma_alloc_attrs(lVar1,DAT_00101930,&local_b8,0xcc0,0);
        } while (lVar7 == 0);
        dma_free_attrs(lVar1,DAT_00101930,lVar7,local_b8,0);
        lVar7 = _memstart_addr;
        lVar11 = *(long *)(param_1 + 0x2c0);
        uVar13 = local_b8;
        if (lVar11 != 0) {
          uVar13 = *(ulong *)(lVar11 + 0x10);
          if (uVar13 != 0) {
            plVar12 = (long *)(lVar11 + 0x18);
            do {
              if ((ulong)plVar12[-2] <= local_b8 && local_b8 - plVar12[-2] < uVar13) {
                uVar13 = *plVar12 + local_b8;
                goto LAB_00100ebc;
              }
              uVar13 = plVar12[3];
              plVar12 = plVar12 + 4;
            } while (uVar13 != 0);
          }
          uVar13 = 0xffffffffffffffff;
        }
LAB_00100ebc:
        uVar18 = DAT_00101930 + 0xfff;
        uVar3 = uVar18 >> 0xc;
        lVar11 = __kmalloc((ulong)(uVar3 << 3),0xcc0);
        if (lVar11 == 0) {
LAB_00100f20:
          iVar6 = -0xc;
        }
        else {
          if (0xfff < uVar18) {
            uVar18 = uVar3;
            if (uVar3 < 2) {
              uVar18 = 1;
            }
            uVar16 = (ulong)uVar18 - 1;
            uVar14 = (ulong)uVar3;
            if (uVar16 <= uVar3) {
              uVar14 = uVar16;
            }
            if (uVar14 < 2) {
              lVar15 = 0;
            }
            else {
              uVar16 = uVar14 + 1 & 1;
              uVar2 = 2;
              if (uVar16 != 0) {
                uVar2 = uVar16;
              }
              lVar17 = (lVar7 >> 0xc) * -0x40 + -0x200000000 + (uVar13 >> 0xc) * 0x40;
              lVar15 = (uVar14 + 1) - uVar2;
              plVar12 = (long *)(lVar11 + 8);
              lVar10 = ~uVar14 + uVar2;
              do {
                lVar10 = lVar10 + 2;
                plVar12[-1] = lVar17;
                *plVar12 = lVar17 + 0x40;
                plVar12 = plVar12 + 2;
                lVar17 = lVar17 + 0x80;
              } while (lVar10 != 0);
            }
            lVar10 = (ulong)uVar18 - lVar15;
            uVar14 = lVar15 << 3;
            lVar7 = lVar15 * 0x40 + (uVar13 >> 0xc) * 0x40 + (lVar7 >> 0xc) * -0x40 + -0x200000000;
            do {
              if (uVar3 << 3 <= uVar14) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(1,0x101130);
                (*pcVar4)();
              }
              *(long *)(lVar11 + uVar14) = lVar7;
              uVar14 = uVar14 + 8;
              lVar7 = lVar7 + 0x40;
              lVar10 = lVar10 + -1;
            } while (lVar10 != 0);
          }
          uVar8 = 0x6800000000070b;
          if (arm64_use_ng_mappings != '\0') {
            uVar8 = 0x68000000000f0b;
          }
          uVar8 = vmap(lVar11,uVar3,0x10,uVar8);
          kfree(lVar11);
          lVar7 = *(long *)(param_1 + 0x2c0);
          va_md_data = local_b8;
          if (lVar7 != 0) {
            uVar13 = *(ulong *)(lVar7 + 0x10);
            if (uVar13 != 0) {
              plVar12 = (long *)(lVar7 + 0x18);
              do {
                if ((ulong)plVar12[-2] <= local_b8 && local_b8 - plVar12[-2] < uVar13) {
                  va_md_data = *plVar12 + local_b8;
                  goto LAB_00101028;
                }
                uVar13 = plVar12[3];
                plVar12 = plVar12 + 4;
              } while (uVar13 != 0);
            }
            va_md_data = 0xffffffffffffffff;
          }
LAB_00101028:
          DAT_00101938 = uVar8;
          atomic_notifier_chain_register(&panic_notifier_list,&qcom_va_md_panic_blk);
          atomic_notifier_chain_register(&panic_notifier_list,&qcom_va_md_elf_panic_blk);
          DAT_001019b0 = &DAT_001019b0;
          DAT_001019b8 = &DAT_001019b0;
          DAT_001019c0 = kset_create_and_add("va-minidump",0,_kernel_kobj);
          if (DAT_001019c0 == 0) {
            _dev_err(lVar1,"Failed to create kset for va-minidump\n");
            vunmap(DAT_00101938);
            iVar6 = -0xc;
          }
          else {
            DAT_001019aa = 1;
            iVar6 = 0;
          }
        }
        goto LAB_001010d0;
      }
      puVar9 = &DAT_00101c8a;
    }
    else {
      puVar9 = &DAT_00101e54;
    }
    _printk(puVar9,"qcom_va_md_reserve_mem",iVar6);
    _dev_err(lVar1,"CMA for VA based minidump is not present\n");
  }
LAB_001010d0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qcom_va_md_driver_remove @ 00101138 size=404
// signature: undefined qcom_va_md_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_va_md_driver_remove(void)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  
  mutex_lock(&va_md_lock);
  plVar4 = DAT_001019b0;
  if ((long **)DAT_001019b0 != &DAT_001019b0) {
    do {
      plVar7 = plVar4 + 2;
      plVar6 = plVar4 + -0xe;
      plVar9 = (long *)*plVar4;
      if ((long *)*plVar7 != plVar7) {
        plVar8 = (long *)*plVar7;
        do {
          plVar5 = (long *)*plVar8;
          atomic_notifier_chain_unregister(plVar4 + -2,plVar8 + -3);
          uVar3 = __list_del_entry_valid(plVar8);
          if ((uVar3 & 1) != 0) {
            lVar1 = *plVar8;
            plVar2 = (long *)plVar8[1];
            *(long **)(lVar1 + 8) = plVar2;
            *plVar2 = lVar1;
          }
          *plVar8 = -0x2152ffffffffff00;
          plVar8[1] = -0x2152fffffffffede;
          kfree(plVar8 + -3);
          plVar8 = plVar5;
        } while (plVar5 != plVar7);
      }
      uVar3 = __list_del_entry_valid(plVar7);
      if ((uVar3 & 1) != 0) {
        lVar1 = plVar4[2];
        plVar7 = (long *)plVar4[3];
        *(long **)(lVar1 + 8) = plVar7;
        *plVar7 = lVar1;
      }
      plVar4[2] = -0x2152ffffffffff00;
      plVar4[3] = -0x2152fffffffffede;
      sysfs_remove_group(plVar6,va_md_s_attr_group);
      kobject_put(plVar6);
      uVar3 = __list_del_entry_valid(plVar4);
      if ((uVar3 & 1) != 0) {
        lVar1 = *plVar4;
        plVar7 = (long *)plVar4[1];
        *(long **)(lVar1 + 8) = plVar7;
        *plVar7 = lVar1;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      kfree(plVar6);
      plVar4 = plVar9;
    } while ((long **)plVar9 != &DAT_001019b0);
  }
  mutex_unlock(&va_md_lock);
  kset_unregister(DAT_001019c0);
  atomic_notifier_chain_unregister(&panic_notifier_list,&qcom_va_md_elf_panic_blk);
  atomic_notifier_chain_unregister(&panic_notifier_list,&qcom_va_md_panic_blk);
  vunmap(DAT_00101938);
  return 0;
}



//------------------------------------------------------------
// qcom_va_md_panic_handler @ 001012d0 size=700
// signature: undefined qcom_va_md_panic_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 qcom_va_md_panic_handler(void)

{
  uint *puVar1;
  void *pvVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  size_t sVar7;
  undefined8 *puVar8;
  ulong uVar9;
  char *__string;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  
  if (DAT_001019a8 == '\0') {
    DAT_001019a8 = '\x01';
    puVar8 = DAT_001019b0;
    if ((undefined8 **)DAT_001019b0 != &DAT_001019b0) {
      do {
        if (*(char *)(puVar8 + 4) != '\0') {
          atomic_notifier_call_chain(puVar8 + -2,0,0);
        }
        puVar8 = (undefined8 *)*puVar8;
      } while ((undefined8 **)puVar8 != &DAT_001019b0);
    }
    uVar3 = DAT_00101940;
    lVar12 = DAT_00101938;
    uVar9 = (ulong)DAT_00101940;
    if (DAT_00101940 != 0) {
      uVar10 = (ulong)DAT_00101930;
      pvVar2 = (void *)(DAT_00101938 + uVar9 * 0x40);
      if ((long)pvVar2 + 0x3fU <= (DAT_00101938 + uVar10) - 1) {
        sVar7 = strnlen((char *)(DAT_00101938 + 8),0x20);
        if (sVar7 < 0x21) {
          if (sVar7 != 0x20) {
            uVar11 = uVar9 * 0x40 + (ulong)((int)sVar7 + *(int *)(lVar12 + 0x28) + 0x142);
            if (uVar10 < uVar11) {
LAB_00101528:
              _printk(&DAT_00101b65,"qcom_va_md_calc_size");
              return 0;
            }
            DAT_00101970 = sVar7 + 10;
            DAT_00101958 = 3;
            DAT_00101960 = 1;
            DAT_00101968 = (ulong)*(uint *)(lVar12 + 0x28);
            DAT_00101950 = pvVar2;
            if (uVar3 == 1) {
              lVar12 = 0x13b;
            }
            else {
              lVar13 = 0;
              __string = (char *)(lVar12 + 0x48);
              lVar12 = uVar9 * 0x38 + 0x103;
              do {
                lVar5 = DAT_00101970;
                uVar4 = DAT_00101968;
                sVar7 = strnlen(__string,0x20);
                if (0x20 < sVar7) goto LAB_00101574;
                if (sVar7 == 0x20) goto LAB_00101580;
                uVar11 = uVar11 + ((int)sVar7 + *(int *)(__string + 0x20) + 0x79);
                if (uVar10 < uVar11) goto LAB_00101528;
                DAT_00101958 = lVar13 + 4;
                DAT_00101960 = lVar13 + 2;
                lVar13 = lVar13 + 1;
                lVar12 = lVar12 + 0x40;
                puVar1 = (uint *)(__string + 0x20);
                DAT_00101970 = lVar5 + sVar7 + 1;
                __string = __string + 0x40;
                DAT_00101968 = uVar4 + *puVar1;
              } while (uVar9 - 1 != lVar13);
            }
            memset(DAT_00101950,0,lVar12 + DAT_00101968 + DAT_00101970 & 0xfffffffffffffffc);
            strscpy(&DAT_00101978,"KVA_DUMP",9);
            DAT_00101998 = va_md_data + (ulong)DAT_00101940 * 0x40;
            DAT_001019a0 = DAT_00101960 * 0x38 + DAT_00101958 * 0x40 + DAT_00101968 + DAT_00101970 +
                           0x43 & 0xfffffffffffffffc;
            DAT_00101990 = DAT_00101950;
            iVar6 = msm_minidump_add_region(&DAT_00101978);
            if (iVar6 < 0) {
              _printk(&DAT_00101bda,"qcom_va_md_minidump_registration");
            }
            DAT_001019a9 = iVar6 >= 0;
            return 0;
          }
        }
        else {
LAB_00101574:
          fortify_panic("strnlen");
        }
LAB_00101580:
        fortify_panic("__fortify_strlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      _printk(&DAT_00101eea,"qcom_va_md_calc_elf_size");
    }
  }
  return 0;
}



//------------------------------------------------------------
// qcom_va_md_elf_panic_handler @ 00101590 size=744
// signature: undefined qcom_va_md_elf_panic_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_va_md_elf_panic_handler(void)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  long lVar5;
  void *__src;
  ushort uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  undefined4 *puVar10;
  ulong uVar11;
  uint *puVar12;
  long lVar13;
  ulong uVar14;
  size_t *psVar15;
  
  lVar13 = DAT_00101958;
  puVar2 = DAT_00101950;
  if ((DAT_00101940 != 0) && (DAT_001019a9 != '\0')) {
    DAT_00101950[2] = 0x100b70004;
    *puVar2 = 0x10102464c457f;
    *(undefined4 *)((long)puVar2 + 0x34) = 0x380040;
    *(undefined2 *)((long)puVar2 + 0x3e) = 1;
    lVar9 = DAT_00101938;
    puVar2[4] = lVar13 * 0x40 + 0x40;
    puVar2[5] = 0x40;
    puVar3 = DAT_00101950;
    *(undefined2 *)((long)puVar2 + 0x3a) = 0x40;
    DAT_00101948 = 1;
    lVar13 = puVar3[4] + DAT_00101960 * 0x38;
    puVar10 = (undefined4 *)
              ((long)puVar3 +
              (ulong)(ushort)(*(short *)((long)puVar3 + 0x3c) + 1) * 0x40 + puVar3[5]);
    *(short *)((long)puVar3 + 0x3c) = *(short *)((long)puVar3 + 0x3c) + 2;
    puVar10[1] = 3;
    *(long *)(puVar10 + 6) = lVar13;
    lVar8 = DAT_00101948;
    if (((ulong)*(ushort *)((long)puVar3 + 0x3e) == 0) ||
       (lVar5 = (long)puVar3 +
                *(long *)((long)puVar3 +
                         (ulong)*(ushort *)((long)puVar3 + 0x3e) * 0x40 + puVar3[5] + 0x18),
       lVar5 == 0)) {
      lVar8 = 0;
    }
    else {
      lVar5 = strscpy(lVar5 + DAT_00101948,"STR_TBL",8);
      DAT_00101948 = lVar8 + lVar5 + 1;
    }
    *puVar10 = (int)lVar8;
    *(long *)(puVar10 + 8) = DAT_00101970;
    if (DAT_00101958 != 2) {
      uVar11 = 0;
      uVar6 = *(ushort *)((long)puVar3 + 0x3c);
      puVar12 = (uint *)(lVar9 + 0x28);
      lVar13 = DAT_00101970 + lVar13;
      do {
        lVar8 = puVar3[5];
        uVar14 = (ulong)uVar6;
        puVar10 = (undefined4 *)((long)puVar3 + uVar14 * 0x40 + lVar8);
        puVar10[1] = 1;
        lVar9 = DAT_00101948;
        if (((ulong)*(ushort *)((long)puVar3 + 0x3e) == 0) ||
           (lVar5 = (long)puVar3 +
                    *(long *)((long)puVar3 +
                             (ulong)*(ushort *)((long)puVar3 + 0x3e) * 0x40 + puVar3[5] + 0x18),
           lVar5 == 0)) {
          lVar9 = 0;
        }
        else {
          lVar5 = strscpy(lVar5 + DAT_00101948,puVar12 + -8,0x20);
          DAT_00101948 = lVar9 + lVar5 + 1;
        }
        *puVar10 = (int)lVar9;
        psVar15 = (size_t *)(puVar10 + 8);
        *psVar15 = (ulong)*puVar12;
        *(undefined8 *)(puVar10 + 2) = 1;
        *(long *)(puVar10 + 6) = lVar13;
        lVar9 = puVar3[4];
        uVar7 = (ulong)*(ushort *)(puVar3 + 7);
        puVar10 = (undefined4 *)((long)puVar3 + uVar7 * 0x38 + lVar9);
        *puVar10 = 1;
        *(long *)(puVar10 + 2) = lVar13;
        uVar1 = *puVar12;
        *(ulong *)(puVar10 + 8) = (ulong)uVar1;
        *(ulong *)(puVar10 + 10) = (ulong)uVar1;
        puVar10[1] = 6;
        __src = *(void **)(puVar12 + -10);
        if (__src == (void *)0x0) {
          lVar5 = (long)DAT_00101950 + lVar13;
          *(long *)((long)puVar3 + uVar7 * 0x38 + lVar9 + 0x10) = lVar5;
          *(long *)((long)puVar3 + uVar14 * 0x40 + lVar8 + 0x10) = lVar5;
          if (*(int *)(*(code **)(puVar12 + 2) + -4) != 0x43dbf732) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x101768);
            (*pcVar4)();
          }
          (**(code **)(puVar12 + 2))((long)DAT_00101950 + lVar13,*psVar15);
        }
        else {
          *(void **)((long)puVar3 + uVar7 * 0x38 + lVar9 + 0x10) = __src;
          *(void **)((long)puVar3 + uVar14 * 0x40 + lVar8 + 0x10) = __src;
          memcpy((void *)((long)DAT_00101950 + lVar13),__src,*psVar15);
        }
        uVar11 = uVar11 + 1;
        puVar12 = puVar12 + 0x10;
        lVar13 = *psVar15 + lVar13;
        uVar6 = *(short *)((long)puVar3 + 0x3c) + 1;
        uVar14 = DAT_00101958 - 2;
        *(ushort *)((long)puVar3 + 0x3c) = uVar6;
        *(short *)(puVar3 + 7) = *(short *)(puVar3 + 7) + 1;
      } while (uVar11 < uVar14);
    }
  }
  DAT_001019a8 = 0;
  return 0;
}



//------------------------------------------------------------
// init_module @ 001018d0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_va_md_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101900 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_va_md_driver);
  return;
}



//------------------------------------------------------------
// msm_minidump_enabled @ 00104000 size=1
// signature: undefined msm_minidump_enabled(void)
// callers: [qcom_va_md_register, qcom_va_md_unregister, qcom_va_md_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104010 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_va_md_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104018 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_va_md_register, qcom_va_md_driver_remove, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kset_find_obj @ 00104020 size=1
// signature: undefined kset_find_obj(void)
// callers: [qcom_va_md_register, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kset_find_obj(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00104028 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_va_md_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent @ 00104030 size=1
// signature: undefined kobject_uevent(void)
// callers: [qcom_va_md_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00104038 size=1
// signature: undefined sysfs_create_group(void)
// callers: [qcom_va_md_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104040 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_va_md_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104048 size=1
// signature: undefined _printk(void)
// callers: [qcom_va_md_add_region, qcom_va_md_register, qcom_va_md_unregister, qcom_va_md_panic_handler, qcom_va_md_driver_probe, enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104050 size=1
// signature: undefined kfree(void)
// callers: [qcom_va_md_register, qcom_va_md_driver_remove, qcom_va_md_unregister, qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00104058 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [qcom_va_md_register, qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104060 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_va_md_register, qcom_va_md_driver_remove, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00104068 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_va_md_register, qcom_va_md_driver_remove, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 00104070 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [qcom_va_md_driver_remove, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104078 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_va_md_driver_remove, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00104080 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [qcom_va_md_driver_remove, qcom_va_md_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104088 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [qcom_va_md_add_region, qcom_va_md_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104090 size=1
// signature: undefined fortify_panic(void)
// callers: [qcom_va_md_add_region, qcom_va_md_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104098 size=1
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
// platform_driver_unregister @ 001040a0 size=1
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
// scnprintf @ 001040a8 size=1
// signature: undefined scnprintf(void)
// callers: [enable_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 001040b0 size=1
// signature: undefined kstrtobool(void)
// callers: [enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040b8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_va_md_driver_probe, enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 001040c0 size=1
// signature: undefined dma_set_mask(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 001040c8 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001040d0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 001040d8 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001040e0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 001040e8 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001040f0 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00104100 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmap @ 00104110 size=1
// signature: undefined vmap(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kset_create_and_add @ 00104128 size=1
// signature: undefined kset_create_and_add(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kset_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104130 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vunmap @ 00104138 size=1
// signature: undefined vunmap(void)
// callers: [qcom_va_md_driver_remove, qcom_va_md_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kset_unregister @ 00104140 size=1
// signature: undefined kset_unregister(void)
// callers: [qcom_va_md_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kset_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_call_chain @ 00104148 size=1
// signature: undefined atomic_notifier_call_chain(void)
// callers: [qcom_va_md_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104150 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_va_md_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104158 size=1
// signature: undefined strscpy(void)
// callers: [qcom_va_md_elf_panic_handler, qcom_va_md_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 00104160 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [qcom_va_md_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104168 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_va_md_elf_panic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



