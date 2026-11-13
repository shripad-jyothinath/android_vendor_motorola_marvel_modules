// Decompiled by Ghidra 12.2
// Program: swr_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// __regmap_init_swr @ 00100a74 size=56
// signature: undefined __regmap_init_swr(void)
// callers: []
//------------------------------------------------------------

void __regmap_init_swr(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __regmap_init(param_1 + 0x48,&regmap_swr,param_1 + 0x48,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 00100ab0 size=56
// signature: undefined __devm_regmap_init_swr(void)
// callers: []
//------------------------------------------------------------

void __devm_regmap_init_swr(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __devm_regmap_init(param_1 + 0x48,&regmap_swr,param_1 + 0x48,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// regmap_swr_write @ 00100aec size=632
// signature: undefined regmap_swr_write(void)
// callers: []
//------------------------------------------------------------

int regmap_swr_write(long param_1,undefined2 *param_2,ulong param_3)

{
  undefined2 *puVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  ulong uVar8;
  char *pcVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  
  lVar12 = param_1 + -0x48;
  lVar6 = 0;
  if (param_1 != 0) {
    lVar6 = lVar12;
  }
  lVar5 = dev_get_regmap(param_1,0);
  if (lVar5 == 0) {
    iVar3 = ___ratelimit(regmap_swr_write__rs,"regmap_swr_write");
    if (iVar3 == 0) {
      return -0x16;
    }
    pcVar7 = "%s: regmap is NULL\n";
  }
  else {
    if (lVar6 != 0) {
      uVar10 = 2;
      if (*(char *)(lVar6 + 0x3e1) != '\0') {
        uVar10 = 4;
      }
      uVar8 = (ulong)uVar10;
      if (param_3 < uVar8) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100d60);
        (*pcVar2)();
      }
      if (param_3 <= (uVar10 | 1)) {
        iVar3 = regmap_swr_gather_write(param_1,param_2,uVar8,(long)param_2 + uVar8,param_3 - uVar8)
        ;
        return iVar3;
      }
      lVar6 = dev_get_regmap(param_1,0);
      if ((param_1 == 0) || (lVar12 == 0)) {
        iVar3 = ___ratelimit(regmap_swr_raw_multi_reg_write__rs,"regmap_swr_raw_multi_reg_write");
        if (iVar3 == 0) {
          return -0x16;
        }
        pcVar7 = "%s: swr device is NULL\n";
      }
      else {
        if (lVar6 != 0) {
          uVar8 = param_3 / 3;
          uVar13 = uVar8 * 2;
          lVar6 = __kmalloc(uVar13,0xdc0);
          if (lVar6 == 0) {
            return -0xc;
          }
          lVar5 = __kmalloc(uVar8,0xdc0);
          if (lVar5 == 0) {
            iVar3 = -0xc;
          }
          else {
            if (2 < param_3) {
              uVar11 = 0;
              do {
                if (((((long)uVar11 < 0) || (uVar13 <= uVar11 * 2)) || (uVar13 <= uVar11 * 2)) ||
                   (*(undefined2 *)(lVar6 + uVar11 * 2) = *param_2, uVar8 <= uVar11)) {
                    /* WARNING: Does not return */
                  pcVar2 = (code *)SoftwareBreakpoint(1,0x100d68);
                  (*pcVar2)();
                }
                puVar1 = param_2 + 1;
                param_2 = (undefined2 *)((long)param_2 + 3);
                *(undefined1 *)(lVar5 + uVar11) = *(undefined1 *)puVar1;
                uVar11 = (ulong)((int)uVar11 + 1);
              } while (uVar11 < uVar8);
            }
            iVar3 = swr_bulk_write(lVar12,*(undefined1 *)(param_1 + -8),lVar6,lVar5,uVar8);
            if ((iVar3 != 0) &&
               (iVar4 = ___ratelimit(regmap_swr_raw_multi_reg_write__rs_5,
                                     "regmap_swr_raw_multi_reg_write"), iVar4 != 0)) {
              _dev_err(param_1,"%s: multi reg write failed\n","regmap_swr_raw_multi_reg_write");
            }
            kfree(lVar5);
          }
          kfree(lVar6);
          return iVar3;
        }
        iVar3 = ___ratelimit(regmap_swr_raw_multi_reg_write__rs_4,"regmap_swr_raw_multi_reg_write");
        if (iVar3 == 0) {
          return -0x16;
        }
        pcVar7 = "%s: regmap is NULL\n";
      }
      pcVar9 = "regmap_swr_raw_multi_reg_write";
      goto LAB_00100c8c;
    }
    iVar3 = ___ratelimit(regmap_swr_write__rs_1,"regmap_swr_write");
    if (iVar3 == 0) {
      return -0x16;
    }
    pcVar7 = "%s: swr is NULL\n";
  }
  pcVar9 = "regmap_swr_write";
LAB_00100c8c:
  _dev_err(param_1,pcVar7,pcVar9);
  return -0x16;
}



//------------------------------------------------------------
// regmap_swr_gather_write @ 00100d6c size=504
// signature: undefined regmap_swr_gather_write(void)
// callers: [regmap_swr_write]
//------------------------------------------------------------

int regmap_swr_gather_write(long param_1,undefined8 param_2,long param_3,long param_4,ulong param_5)

{
  long lVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  int iVar7;
  ulong uVar8;
  ushort local_5c [2];
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = param_1 + -0x48;
  }
  lVar5 = dev_get_regmap(param_1,0);
  local_5c[0] = 0;
  if (lVar5 == 0) {
    iVar3 = ___ratelimit(regmap_swr_gather_write__rs,"regmap_swr_gather_write");
    if (iVar3 != 0) {
      pcVar6 = "%s: regmap is NULL\n";
LAB_00100e84:
      _dev_err(param_1,pcVar6,"regmap_swr_gather_write");
      iVar3 = -0x16;
      goto LAB_00100ee0;
    }
  }
  else if (lVar1 == 0) {
    iVar3 = ___ratelimit(regmap_swr_gather_write__rs_7,"regmap_swr_gather_write");
    if (iVar3 != 0) {
      pcVar6 = "%s: swr device is NULL\n";
      goto LAB_00100e84;
    }
  }
  else {
    if ((param_3 == 2) || (param_3 == 4)) {
      mutex_lock(swr_rw_lock);
      iVar3 = regmap_swr_reg_address_get(lVar1,local_5c,param_2,param_3);
      uVar2 = local_5c[0];
      if ((-1 < iVar3) && (param_5 != 0)) {
        uVar8 = 0;
        do {
          iVar7 = (int)uVar8;
          iVar3 = swr_write(lVar1,*(undefined1 *)(lVar1 + 0x40),(uint)uVar2 + iVar7,param_4 + uVar8)
          ;
          if (iVar3 < 0) {
            iVar4 = ___ratelimit(regmap_swr_gather_write__rs_10,"regmap_swr_gather_write");
            if (iVar4 != 0) {
              _dev_err(param_1,"%s: write reg 0x%x failed, err %d\n","regmap_swr_gather_write",
                       iVar7 + (uint)uVar2,iVar3);
            }
            break;
          }
          uVar8 = (ulong)(iVar7 + 1);
        } while (uVar8 < param_5);
      }
      mutex_unlock(swr_rw_lock);
      goto LAB_00100ee0;
    }
    iVar3 = ___ratelimit(regmap_swr_gather_write__rs_8,"regmap_swr_gather_write");
    if (iVar3 != 0) {
      _dev_err(param_1,"%s: reg size %zd bytes not supported\n","regmap_swr_gather_write",param_3);
      iVar3 = -0x16;
      goto LAB_00100ee0;
    }
  }
  iVar3 = -0x16;
LAB_00100ee0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// regmap_swr_read @ 00100f68 size=528
// signature: undefined regmap_swr_read(void)
// callers: []
//------------------------------------------------------------

int regmap_swr_read(long param_1,undefined4 *param_2,long param_3,undefined8 param_4,
                   undefined4 param_5)

{
  long lVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  undefined2 local_4c [2];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = param_1 + -0x48;
  }
  lVar5 = dev_get_regmap(param_1,0);
  local_4c[0] = 0;
  if (lVar5 == 0) {
    iVar3 = ___ratelimit(regmap_swr_read__rs,"regmap_swr_read");
    if (iVar3 != 0) {
      pcVar6 = "%s: regmap is NULL\n";
LAB_0010109c:
      _dev_err(param_1,pcVar6,"regmap_swr_read");
      iVar3 = -0x16;
      goto LAB_001010fc;
    }
  }
  else if (lVar1 == 0) {
    iVar3 = ___ratelimit(regmap_swr_read__rs_14,"regmap_swr_read");
    if (iVar3 != 0) {
      pcVar6 = "%s: swr is NULL\n";
      goto LAB_0010109c;
    }
  }
  else {
    if ((param_3 == 2) || (param_3 == 4)) {
      mutex_lock(swr_rw_lock);
      iVar3 = regmap_swr_reg_address_get(lVar1,local_4c,param_2,param_3);
      uVar2 = local_4c[0];
      if (iVar3 < 0) {
        iVar4 = ___ratelimit(regmap_swr_read__rs_16,"regmap_swr_read");
        if (iVar4 != 0) {
          _dev_err(param_1,"%s: regmap_swr_reg_address_get failed, reg: 0x%x\n","regmap_swr_read",
                   *param_2);
        }
      }
      else {
        iVar3 = swr_read(lVar1,*(undefined1 *)(lVar1 + 0x40),local_4c[0],param_4,param_5);
        if ((iVar3 < 0) &&
           (iVar4 = ___ratelimit(regmap_swr_read__rs_18,"regmap_swr_read"), iVar4 != 0)) {
          _dev_err(param_1,"%s: codec reg 0x%x read failed %d\n","regmap_swr_read",uVar2,iVar3);
        }
      }
      mutex_unlock(swr_rw_lock);
      goto LAB_001010fc;
    }
    iVar3 = ___ratelimit(regmap_swr_read__rs_15,"regmap_swr_read");
    if (iVar3 != 0) {
      _dev_err(param_1,"%s: reg size %zd bytes not supported\n","regmap_swr_read",param_3);
      iVar3 = -0x16;
      goto LAB_001010fc;
    }
  }
  iVar3 = -0x16;
LAB_001010fc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// regmap_swr_reg_address_get @ 00101178 size=320
// signature: undefined regmap_swr_reg_address_get(void)
// callers: [regmap_swr_gather_write, regmap_swr_read]
//------------------------------------------------------------

int regmap_swr_reg_address_get(long param_1,ushort *param_2,uint *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  ushort uVar4;
  uint uVar5;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (param_4 == 4) {
    uVar5 = *param_3;
    local_4c[0] = (undefined1)(uVar5 >> 0x17);
    local_50[0] = (undefined1)(uVar5 >> 0xf);
    if ((uVar5 & 0x7fff8000) == 0) goto LAB_001011e8;
    if ((uint)*(byte *)(param_1 + 0x3f2) != (uVar5 >> 0x17 & 0xff)) {
      iVar2 = swr_write(param_1,*(undefined1 *)(param_1 + 0x40),0x48,local_4c);
      if (-1 < iVar2) {
        *(undefined1 *)(param_1 + 0x3f2) = local_4c[0];
        goto LAB_00101214;
      }
      pcVar3 = "%s: write reg scp1_address failed, err %d\n";
LAB_001012a0:
      _dev_err(param_1 + 0x48,pcVar3,"regmap_swr_reg_address_get",iVar2);
      goto LAB_00101250;
    }
    iVar2 = 0;
LAB_00101214:
    if ((uint)*(byte *)(param_1 + 0x3f3) != (uVar5 >> 0xf & 0xff)) {
      iVar2 = swr_write(param_1,*(undefined1 *)(param_1 + 0x40),0x49,local_50);
      if (iVar2 < 0) {
        pcVar3 = "%s: write reg scp2_address failed, err %d\n";
        goto LAB_001012a0;
      }
      *(undefined1 *)(param_1 + 0x3f3) = local_50[0];
    }
    uVar4 = (ushort)*param_3 | 0x8000;
  }
  else {
    uVar5 = (uint)(ushort)*param_3;
LAB_001011e8:
    uVar4 = (ushort)uVar5;
    iVar2 = 0;
  }
  *param_2 = uVar4;
LAB_00101250:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// swr_remove_device @ 001012bc size=140
// signature: undefined swr_remove_device(void)
// callers: []
//------------------------------------------------------------

void swr_remove_device(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  lVar3 = param_1[4];
  plVar4 = *(long **)(lVar3 + 0x3d8);
  if (plVar4 != (long *)(lVar3 + 0x3d8)) {
    do {
      plVar5 = (long *)*plVar4;
      if (plVar4 + -6 == param_1) {
        uVar2 = __list_del_entry_valid(plVar4);
        if ((uVar2 & 1) != 0) {
          lVar3 = *plVar4;
          plVar1 = (long *)plVar4[1];
          *(long **)(lVar3 + 8) = plVar1;
          *plVar1 = lVar3;
        }
        *plVar4 = (long)plVar4;
        plVar4[1] = (long)plVar4;
        lVar3 = param_1[4];
      }
      plVar4 = plVar5;
    } while (plVar5 != (long *)(lVar3 + 0x3d8));
  }
  return;
}



//------------------------------------------------------------
// swr_new_device @ 0010134c size=520
// signature: undefined swr_new_device(void)
// callers: [swr_master_add_boarddevices, of_register_swr_devices]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * swr_new_device(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  void *pvVar5;
  size_t __n;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  
  if ((param_1 == 0) || (lVar4 = get_device(), lVar4 == 0)) {
    iVar2 = ___ratelimit(&swr_new_device__rs,"swr_new_device");
    if (iVar2 != 0) {
      _printk(&DAT_00103c7e,"swr_new_device");
    }
    return (void *)0x0;
  }
  pvVar5 = (void *)kmalloc_trace(_of_get_next_available_child,0xdc0,0x3f8);
  if (pvVar5 == (void *)0x0) {
    put_device(param_1);
    return (void *)0x0;
  }
  uVar7 = *(undefined8 *)(param_2 + 0x28);
  *(long *)((long)pvVar5 + 0x20) = param_1;
  *(undefined8 *)((long)pvVar5 + 0x3d8) = uVar7;
  __n = strnlen(param_2,0x20);
  if (__n < 0x21) {
    if (__n != 0x20) {
      memcpy(pvVar5,param_2,__n);
      uVar7 = *(undefined8 *)(param_2 + 0x30);
      *(undefined1 *)((long)pvVar5 + __n) = 0;
      *(long *)((long)pvVar5 + 0xa8) = param_1;
      *(undefined1 **)((long)pvVar5 + 0xc0) = swr_dev_type;
      *(undefined ***)((long)pvVar5 + 200) = &soundwire_type;
      *(code **)((long)pvVar5 + 0x370) = swr_dev_release;
      *(undefined8 *)((long)pvVar5 + 0x330) = uVar7;
      mutex_lock(param_1 + 0x3a8);
      plVar9 = *(long **)(param_1 + 0x3e0);
      lVar4 = (long)pvVar5 + 0x30;
      uVar6 = __list_add_valid(lVar4,plVar9,param_1 + 0x3d8);
      if ((uVar6 & 1) != 0) {
        *(long *)(param_1 + 0x3e0) = lVar4;
        *(long *)((long)pvVar5 + 0x30) = param_1 + 0x3d8;
        *(long **)((long)pvVar5 + 0x38) = plVar9;
        *plVar9 = lVar4;
      }
      mutex_unlock(param_1 + 0x3a8);
      dev_set_name((long)pvVar5 + 0x48,"%s.%lx",pvVar5,*(undefined8 *)((long)pvVar5 + 0x3d8));
      iVar2 = device_register((long)pvVar5 + 0x48);
      if (iVar2 == 0) {
        return pvVar5;
      }
      iVar3 = ___ratelimit(swr_new_device__rs_2,"swr_new_device");
      if (iVar3 != 0) {
        _dev_err(param_1,"device [%s] register failed err %d\n",pvVar5,iVar2);
      }
      put_device(param_1);
      uVar6 = __list_del_entry_valid(lVar4);
      if ((uVar6 & 1) != 0) {
        lVar8 = *(long *)((long)pvVar5 + 0x30);
        plVar9 = *(long **)((long)pvVar5 + 0x38);
        *(long **)(lVar8 + 8) = plVar9;
        *plVar9 = lVar8;
      }
      *(long *)((long)pvVar5 + 0x30) = (long)pvVar5 + 0x30;
      *(long *)((long)pvVar5 + 0x38) = lVar4;
      kfree(pvVar5);
      return (void *)0x0;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("__fortify_strlen");
  pvVar5 = (void *)func_0x03ca0d20();
  if (((pvVar5 != (void *)0x0) && ((long)pvVar5 + -0x48 != 0)) &&
     (*(long *)((long)pvVar5 + -0x28) != 0)) {
    lVar4 = *(long *)((long)pvVar5 + -0x28) + 0x3a8;
    mutex_lock(lVar4);
    lVar8 = (long)pvVar5 + -0x18;
    uVar6 = __list_del_entry_valid(lVar8);
    if ((uVar6 & 1) != 0) {
      lVar1 = *(long *)((long)pvVar5 + -0x18);
      plVar9 = *(long **)((long)pvVar5 + -0x10);
      *(long **)(lVar1 + 8) = plVar9;
      *plVar9 = lVar1;
    }
    *(long *)((long)pvVar5 + -0x18) = lVar8;
    *(long *)((long)pvVar5 + -0x10) = lVar8;
    mutex_unlock(lVar4);
    if (*(long *)((long)pvVar5 + -0x28) != 0) {
      put_device();
    }
    pvVar5 = (void *)kfree((long)pvVar5 + -0x48);
  }
  return pvVar5;
}



//------------------------------------------------------------
// swr_dev_release @ 00101558 size=140
// signature: undefined swr_dev_release(void)
// callers: []
//------------------------------------------------------------

void swr_dev_release(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  
  if (((param_1 != 0) && (param_1 + -0x48 != 0)) && (*(long *)(param_1 + -0x28) != 0)) {
    lVar1 = *(long *)(param_1 + -0x28) + 0x3a8;
    mutex_lock(lVar1);
    lVar5 = param_1 + -0x18;
    uVar4 = __list_del_entry_valid(lVar5);
    if ((uVar4 & 1) != 0) {
      lVar2 = *(long *)(param_1 + -0x18);
      plVar3 = *(long **)(param_1 + -0x10);
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *(long *)(param_1 + -0x18) = lVar5;
    *(long *)(param_1 + -0x10) = lVar5;
    mutex_unlock(lVar1);
    if (*(long *)(param_1 + -0x28) != 0) {
      put_device();
    }
    kfree(param_1 + -0x48);
  }
  return;
}



//------------------------------------------------------------
// of_register_swr_devices @ 001015e8 size=396
// signature: undefined of_register_swr_devices(void)
// callers: []
//------------------------------------------------------------

void of_register_swr_devices(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  if (*(long *)(param_1 + 0x2e8) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    lVar2 = of_get_next_available_child(*(long *)(param_1 + 0x2e8),0);
    uVar4 = 0;
    if (lVar2 != 0) {
      do {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        local_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b0 = 0;
        iVar1 = of_modalias_node(lVar2,&local_a8,0x20);
        if (iVar1 < 0) {
          iVar1 = ___ratelimit(of_register_swr_devices__rs,"of_register_swr_devices");
          if (iVar1 != 0) {
            pcVar5 = "of_swr:modalias failure %s\n";
            goto LAB_00101724;
          }
        }
        else {
          iVar1 = of_property_read_u64(lVar2,&DAT_00103a3b,&local_b0);
          if (iVar1 == 0) {
            local_80 = local_b0;
            local_78 = lVar2;
            lVar3 = swr_new_device(param_1,&local_a8);
            if ((lVar3 == 0) &&
               (iVar1 = ___ratelimit(of_register_swr_devices__rs_8,"of_register_swr_devices"),
               iVar1 != 0)) {
              pcVar5 = "of_swr: Register failed %s\n";
              goto LAB_00101724;
            }
          }
          else {
            iVar1 = ___ratelimit(of_register_swr_devices__rs_6,"of_register_swr_devices");
            if (iVar1 != 0) {
              pcVar5 = "of_swr:invalid reg %s\n";
LAB_00101724:
              _dev_err(param_1,pcVar5,*(undefined8 *)(lVar2 + 0x10));
            }
          }
        }
        lVar2 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2e8),lVar2);
        uVar4 = 0;
      } while (lVar2 != 0);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// swr_port_response @ 00101778 size=116
// signature: undefined swr_port_response(void)
// callers: []
//------------------------------------------------------------

void swr_port_response(long param_1,ulong param_2)

{
  int iVar1;
  
  if (*(long *)(*(long *)(param_1 + 0x20c8) + (param_2 & 0xff) * 8) == 0) {
    iVar1 = ___ratelimit(swr_port_response__rs,"swr_port_response");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: transaction is already NULL\n","swr_port_response");
    }
  }
  else {
    *(undefined8 *)(*(long *)(param_1 + 0x20c8) + (param_2 & 0xff) * 8) = 0;
    kfree();
  }
  return;
}



//------------------------------------------------------------
// swr_remove_from_group @ 001017f0 size=120
// signature: undefined swr_remove_from_group(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_remove_from_group(long param_1,char param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x20);
    if (lVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      if (((*(char *)(param_1 + 0x3e0) != '\0') && (*(char *)(lVar1 + 0x20db) == param_2)) &&
         (pcVar3 = *(code **)(lVar1 + 0x2120), pcVar3 != (code *)0x0)) {
        if (*(int *)(pcVar3 + -4) != -0xa0051da) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101844);
          (*pcVar3)();
        }
        (*pcVar3)();
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 0010186c size=144
// signature: undefined swr_slvdev_datapath_control(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_slvdev_datapath_control(long param_1,char param_2,uint param_3)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 == 0) {
    return 0xffffffea;
  }
  if (*(char *)(param_1 + 0x3e0) != '\0') {
    cVar1 = *(char *)(lVar2 + 0x20db);
    if (cVar1 != param_2) {
      if (cVar1 != '\0') {
        return 0;
      }
      *(char *)(lVar2 + 0x20db) = param_2;
    }
  }
  pcVar4 = *(code **)(lVar2 + 0x2118);
  if (pcVar4 == (code *)0x0) {
    return 0;
  }
  if (*(int *)(pcVar4 + -4) != -0x6f8e95e5) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1018d4);
    (*pcVar4)();
  }
  uVar3 = (*pcVar4)(lVar2,param_3 & 1);
  return uVar3;
}



//------------------------------------------------------------
// swr_connect_port @ 00101900 size=708
// signature: undefined swr_connect_port(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
swr_connect_port(long param_1,long param_2,byte param_3,long param_4,long param_5,long param_6,
                long param_7)

{
  byte *pbVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  code *pcVar6;
  int iVar7;
  byte *pbVar8;
  long lVar9;
  undefined8 uVar10;
  char *pcVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  byte local_6c;
  
  lVar14 = *(long *)(param_1 + 0x20);
  if (lVar14 == 0) {
    iVar7 = ___ratelimit(swr_connect_port__rs,"swr_connect_port");
    if (iVar7 != 0) {
      _printk(&DAT_00103bb6,"swr_connect_port");
    }
    return 0xffffffea;
  }
  if (0xe < param_3) {
    iVar7 = ___ratelimit(swr_connect_port__rs_12,"swr_connect_port");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    _dev_err(lVar14,"%s: num_port %d exceeds max port %d\n","swr_connect_port",param_3,0xe);
    return 0xffffffea;
  }
  pbVar8 = (byte *)kmalloc_trace(_put_device,0xdc0,0x74);
  if (pbVar8 != (byte *)0x0) {
    lVar13 = lVar14 + 0x3a8;
    mutex_lock();
    pbVar1 = (byte *)(lVar14 + 0x20d8);
    local_6c = *pbVar1;
    if (local_6c == 0) {
      uVar12 = 0;
      local_6c = 0;
    }
    else {
      uVar12 = 0;
      lVar9 = *(long *)(lVar14 + 0x20c8);
      do {
        if (*(long *)(lVar9 + uVar12 * 8) == 0) {
          local_6c = (byte)uVar12;
          goto LAB_00101a90;
        }
        uVar12 = uVar12 + 1;
      } while (local_6c != uVar12);
      uVar12 = (ulong)local_6c;
      if (local_6c == 0xff) {
        mutex_unlock(lVar13);
        kfree(pbVar8);
        iVar7 = ___ratelimit(swr_connect_port__rs_14,"swr_connect_port");
        if (iVar7 == 0) {
          return 0xfffffff4;
        }
        pcVar11 = "%s Max tid reached\n";
        goto LAB_00101ba8;
      }
    }
    lVar9 = krealloc(*(undefined8 *)(lVar14 + 0x20c8),uVar12 * 8 + 8,0xcc0);
    if (lVar9 != 0) {
      *(long *)(lVar14 + 0x20c8) = lVar9;
      *pbVar1 = *pbVar1 + 1;
LAB_00101a90:
      *(byte **)(lVar9 + uVar12 * 8) = pbVar8;
      mutex_unlock(lVar13);
      bVar3 = *(byte *)(param_1 + 0x40);
      pbVar8[2] = param_3;
      pbVar8[1] = bVar3;
      *pbVar8 = local_6c;
      if (param_3 != 0) {
        uVar12 = 0;
        do {
          if (uVar12 == 0xe) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x101bc4);
            (*pcVar6)();
          }
          lVar13 = uVar12 * 4;
          pbVar1 = pbVar8 + uVar12 + 0x58;
          bVar3 = *(byte *)(param_6 + uVar12);
          bVar4 = *(byte *)(param_4 + uVar12);
          uVar2 = *(undefined4 *)(param_5 + lVar13);
          pbVar1[-0x55] = *(byte *)(param_2 + uVar12);
          bVar5 = *(byte *)(param_7 + uVar12);
          uVar12 = uVar12 + 1;
          pbVar1[-0x47] = bVar3;
          *(undefined4 *)(pbVar8 + lVar13 + 0x20) = uVar2;
          *pbVar1 = bVar4;
          pbVar1[0xe] = bVar5;
        } while (param_3 != uVar12);
      }
      if (*(int *)(*(code **)(lVar14 + 0x20e0) + -4) != -0x2d468502) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101b30);
        (*pcVar6)();
      }
      uVar10 = (**(code **)(lVar14 + 0x20e0))(lVar14,pbVar8);
      return uVar10;
    }
    mutex_unlock(lVar13);
    kfree(pbVar8);
    iVar7 = ___ratelimit(swr_connect_port__rs_16,"swr_connect_port");
    if (iVar7 != 0) {
      pcVar11 = "%s Not able to allocate\nmaster port transaction memory\n";
LAB_00101ba8:
      _dev_err(lVar14,pcVar11,"swr_connect_port");
      return 0xfffffff4;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// swr_disconnect_port @ 00101bc8 size=664
// signature: undefined swr_disconnect_port(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 swr_disconnect_port(long param_1,long param_2,byte param_3,long param_4,long param_5)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  code *pcVar5;
  int iVar6;
  byte *pbVar7;
  long lVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulong uVar11;
  long lVar12;
  byte bVar13;
  
  lVar12 = *(long *)(param_1 + 0x20);
  if (lVar12 == 0) {
    iVar6 = ___ratelimit(swr_disconnect_port__rs,"swr_disconnect_port");
    if (iVar6 != 0) {
      _printk(&DAT_00103bb6,"swr_disconnect_port");
    }
    return 0xffffffea;
  }
  if (0xe < param_3) {
    iVar6 = ___ratelimit(swr_disconnect_port__rs_18,"swr_disconnect_port");
    if (iVar6 == 0) {
      return 0xffffffea;
    }
    _dev_err(lVar12,"%s: num_port %d exceeds max port %d\n","swr_disconnect_port",param_3,0xe);
    return 0xffffffea;
  }
  pbVar7 = (byte *)kmalloc_trace(_put_device,0xdc0,0x74);
  if (pbVar7 != (byte *)0x0) {
    lVar1 = lVar12 + 0x3a8;
    mutex_lock(lVar1);
    pbVar2 = (byte *)(lVar12 + 0x20d8);
    bVar13 = *pbVar2;
    if (bVar13 == 0) {
      uVar11 = 0;
      bVar13 = 0;
    }
    else {
      uVar11 = 0;
      lVar8 = *(long *)(lVar12 + 0x20c8);
      do {
        if (*(long *)(lVar8 + uVar11 * 8) == 0) {
          bVar13 = (byte)uVar11;
          goto LAB_00101d48;
        }
        uVar11 = uVar11 + 1;
      } while (bVar13 != uVar11);
      uVar11 = (ulong)bVar13;
      if (bVar13 == 0xff) {
        mutex_unlock(lVar1);
        kfree(pbVar7);
        iVar6 = ___ratelimit(swr_disconnect_port__rs_19,"swr_disconnect_port");
        if (iVar6 == 0) {
          return 0xfffffff4;
        }
        pcVar10 = "%s Max tid reached\n";
        goto LAB_00101e44;
      }
    }
    lVar8 = krealloc(*(undefined8 *)(lVar12 + 0x20c8),uVar11 * 8 + 8,0xcc0);
    if (lVar8 != 0) {
      *(long *)(lVar12 + 0x20c8) = lVar8;
      *pbVar2 = *pbVar2 + 1;
LAB_00101d48:
      *(byte **)(lVar8 + uVar11 * 8) = pbVar7;
      mutex_unlock(lVar1);
      bVar4 = *(byte *)(param_1 + 0x40);
      *pbVar7 = bVar13;
      pbVar7[2] = param_3;
      pbVar7[1] = bVar4;
      if (param_3 != 0) {
        uVar11 = 0;
        do {
          if (uVar11 == 0xe) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101e60);
            (*pcVar5)();
          }
          pbVar2 = (byte *)(param_2 + uVar11);
          pbVar3 = pbVar7 + uVar11 + 0x66;
          bVar13 = *(byte *)(param_4 + uVar11);
          bVar4 = *(byte *)(param_5 + uVar11);
          uVar11 = uVar11 + 1;
          pbVar3[-99] = *pbVar2;
          pbVar3[-0xe] = bVar13;
          *pbVar3 = bVar4;
        } while (param_3 != uVar11);
      }
      if (*(int *)(*(code **)(lVar12 + 0x20e8) + -4) != -0x2d468502) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101dcc);
        (*pcVar5)();
      }
      uVar9 = (**(code **)(lVar12 + 0x20e8))(lVar12,pbVar7);
      return uVar9;
    }
    mutex_unlock(lVar1);
    kfree(pbVar7);
    iVar6 = ___ratelimit(swr_disconnect_port__rs_20,"swr_disconnect_port");
    if (iVar6 != 0) {
      pcVar10 = "%s Not able to allocate\nmaster port transaction memory\n";
LAB_00101e44:
      _dev_err(lVar12,pcVar10,"swr_disconnect_port");
      return 0xfffffff4;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 00101e64 size=156
// signature: undefined swr_get_logical_dev_num(void)
// callers: []
//------------------------------------------------------------

undefined4 swr_get_logical_dev_num(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  if (lVar3 == 0) {
    _printk(&DAT_00103bb6,"swr_get_logical_dev_num");
    uVar2 = 0xffffffea;
  }
  else {
    mutex_lock(lVar3 + 0x3a8);
    if (*(int *)(*(code **)(lVar3 + 0x2108) + -4) != 0x524bea1a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101ebc);
      (*pcVar1)();
    }
    uVar2 = (**(code **)(lVar3 + 0x2108))(lVar3,param_2,param_3);
    mutex_unlock(lVar3 + 0x3a8);
  }
  return uVar2;
}



//------------------------------------------------------------
// swr_init_port_params @ 00101f04 size=172
// signature: undefined swr_init_port_params(void)
// callers: []
//------------------------------------------------------------

undefined4 swr_init_port_params(long param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20);
  if (lVar3 == 0) {
    _printk(&DAT_00103bb6,"swr_init_port_params");
    uVar2 = 0xffffffea;
  }
  else {
    mutex_lock(lVar3 + 0x3a8);
    if (*(int *)(*(code **)(lVar3 + 0x2110) + -4) != -0x9563d9b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101f68);
      (*pcVar1)();
    }
    uVar2 = (**(code **)(lVar3 + 0x2110))(lVar3,*(undefined1 *)(param_1 + 0x40),param_2,param_3);
    mutex_unlock(lVar3 + 0x3a8);
  }
  return uVar2;
}



//------------------------------------------------------------
// swr_device_wakeup_vote @ 00101fb4 size=144
// signature: undefined swr_device_wakeup_vote(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_device_wakeup_vote(long param_1)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 == 0) {
    _printk(&DAT_00103bb6,"swr_device_wakeup_vote");
    uVar3 = 0xffffffea;
  }
  else {
    mutex_lock(lVar2 + 0x3a8);
    pcVar1 = *(code **)(lVar2 + 0x2128);
    if (pcVar1 == (code *)0x0) {
      uVar3 = 0xffffffea;
    }
    else {
      if (*(int *)(pcVar1 + -4) != -0x7e896225) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101ffc);
        (*pcVar1)();
      }
      (*pcVar1)(lVar2);
      uVar3 = 0;
    }
    mutex_unlock(lVar2 + 0x3a8);
  }
  return uVar3;
}



//------------------------------------------------------------
// swr_device_wakeup_unvote @ 00102048 size=144
// signature: undefined swr_device_wakeup_unvote(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_device_wakeup_unvote(long param_1)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 == 0) {
    _printk(&DAT_00103bb6,"swr_device_wakeup_unvote");
    uVar3 = 0xffffffea;
  }
  else {
    mutex_lock(lVar2 + 0x3a8);
    pcVar1 = *(code **)(lVar2 + 0x2130);
    if (pcVar1 == (code *)0x0) {
      uVar3 = 0xffffffea;
    }
    else {
      if (*(int *)(pcVar1 + -4) != -0x7e896225) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102090);
        (*pcVar1)();
      }
      (*pcVar1)(lVar2);
      uVar3 = 0;
    }
    mutex_unlock(lVar2 + 0x3a8);
  }
  return uVar3;
}



//------------------------------------------------------------
// swr_read @ 001020dc size=72
// signature: undefined swr_read(void)
// callers: [regmap_swr_read]
//------------------------------------------------------------

undefined8 swr_read(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (*(long *)(param_1 + 0x20) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    pcVar2 = *(code **)(*(long *)(param_1 + 0x20) + 0x20f0);
    if (*(int *)(pcVar2 + -4) != 0x5a417381) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10210c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// swr_bulk_write @ 00102128 size=156
// signature: undefined swr_bulk_write(void)
// callers: [regmap_swr_write]
//------------------------------------------------------------

undefined8 swr_bulk_write(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x20), lVar1 == 0)) {
    return 0xffffffea;
  }
  if (*(byte *)(param_1 + 0x3e0) == 0) {
    uVar4 = param_2;
  }
  else {
    uVar5 = (uint)*(byte *)(lVar1 + 0x20db);
    uVar4 = (uint)*(byte *)(param_1 + 0x3e0);
    if (uVar5 != (param_2 & 0xff)) {
      if (uVar5 != 0) {
        return 0;
      }
      *(byte *)(lVar1 + 0x20db) = (byte)param_2;
      uVar4 = (uint)*(byte *)(param_1 + 0x3e0);
      pcVar3 = *(code **)(lVar1 + 0x2100);
      goto joined_r0x0010217c;
    }
  }
  pcVar3 = *(code **)(lVar1 + 0x2100);
joined_r0x0010217c:
  if (pcVar3 == (code *)0x0) {
    uVar2 = 0xffffffa1;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x2200cb5c) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10219c);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(lVar1,uVar4);
  }
  return uVar2;
}



//------------------------------------------------------------
// swr_write @ 001021c8 size=136
// signature: undefined swr_write(void)
// callers: [regmap_swr_gather_write, regmap_swr_reg_address_get]
//------------------------------------------------------------

undefined8 swr_write(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  
  lVar2 = *(long *)(param_1 + 0x20);
  if (lVar2 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    if (*(byte *)(param_1 + 0x3e0) == 0) {
      uVar4 = param_2;
    }
    else {
      uVar5 = (uint)*(byte *)(lVar2 + 0x20db);
      uVar4 = (uint)*(byte *)(param_1 + 0x3e0);
      if (uVar5 != (param_2 & 0xff)) {
        if (uVar5 != 0) {
          return 0;
        }
        *(byte *)(lVar2 + 0x20db) = (byte)param_2;
        uVar4 = (uint)*(byte *)(param_1 + 0x3e0);
      }
    }
    if (*(int *)(*(code **)(lVar2 + 0x20f8) + -4) != -0x33b6b512) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102240);
      (*pcVar1)();
    }
    uVar3 = (**(code **)(lVar2 + 0x20f8))(lVar2,uVar4);
  }
  return uVar3;
}



//------------------------------------------------------------
// swr_device_up @ 00102254 size=112
// signature: undefined swr_device_up(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_device_up(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(param_1 + 0xd0);
    uVar1 = 0;
    if ((lVar2 != 0) && (lVar2 != 0x40)) {
      pcVar3 = *(code **)(lVar2 + -0x18);
      if (pcVar3 == (code *)0x0) {
        uVar1 = 0xffffffed;
      }
      else {
        lVar2 = 0;
        if (param_1 != -0x48) {
          lVar2 = param_1;
        }
        if (*(int *)(pcVar3 + -4) != -0x652cd95b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1022a4);
          (*pcVar3)();
        }
        uVar1 = (*pcVar3)(lVar2);
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// swr_device_down @ 001022c8 size=112
// signature: undefined swr_device_down(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_device_down(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(param_1 + 0xd0);
    uVar1 = 0;
    if ((lVar2 != 0) && (lVar2 != 0x40)) {
      pcVar3 = *(code **)(lVar2 + -0x10);
      if (pcVar3 == (code *)0x0) {
        uVar1 = 0xffffffed;
      }
      else {
        lVar2 = 0;
        if (param_1 != -0x48) {
          lVar2 = param_1;
        }
        if (*(int *)(pcVar3 + -4) != -0x652cd95b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102318);
          (*pcVar3)();
        }
        uVar1 = (*pcVar3)(lVar2);
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// swr_reset_device @ 0010233c size=112
// signature: undefined swr_reset_device(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_reset_device(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(param_1 + 0xd0);
    uVar1 = 0xffffffea;
    if ((lVar2 != 0) && (lVar2 != 0x40)) {
      pcVar3 = *(code **)(lVar2 + -8);
      if (pcVar3 == (code *)0x0) {
        uVar1 = 0xffffffed;
      }
      else {
        lVar2 = 0;
        if (param_1 != -0x48) {
          lVar2 = param_1;
        }
        if (*(int *)(pcVar3 + -4) != -0x652cd95b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x10238c);
          (*pcVar3)();
        }
        uVar1 = (*pcVar3)(lVar2);
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// swr_set_device_group @ 001023b0 size=56
// signature: undefined swr_set_device_group(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_set_device_group(long param_1,char param_2)

{
  if (param_1 == 0) {
    return 0xffffffea;
  }
  *(char *)(param_1 + 0x3e0) = param_2;
  if ((param_2 == '\0') && (*(long *)(param_1 + 0x20) != 0)) {
    *(undefined1 *)(*(long *)(param_1 + 0x20) + 0x20db) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// swr_driver_register @ 001023ec size=104
// signature: undefined swr_driver_register(void)
// callers: []
//------------------------------------------------------------

void swr_driver_register(long *param_1)

{
  param_1[9] = (long)&soundwire_type;
  if (*param_1 != 0) {
    param_1[0xf] = (long)swr_drv_probe;
  }
  if (param_1[1] != 0) {
    param_1[0x11] = (long)swr_drv_remove;
  }
  if (param_1[2] != 0) {
    param_1[0x12] = (long)swr_drv_shutdown;
  }
  driver_register(param_1 + 8);
  return;
}



//------------------------------------------------------------
// swr_drv_probe @ 00102458 size=104
// signature: undefined swr_drv_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_drv_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  
  uVar2 = 0xffffffea;
  if ((*(long *)(param_1 + 0x88) != 0) &&
     (puVar3 = (undefined8 *)(*(long *)(param_1 + 0x88) + -0x40), puVar3 != (undefined8 *)0x0)) {
    pcVar4 = (code *)*puVar3;
    if (pcVar4 == (code *)0x0) {
      uVar2 = 0xffffffed;
    }
    else {
      lVar1 = 0;
      if (param_1 != 0) {
        lVar1 = param_1 + -0x48;
      }
      if (*(int *)(pcVar4 + -4) != -0x652cd95b) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x1024a8);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(lVar1);
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// swr_drv_remove @ 001024c4 size=104
// signature: undefined swr_drv_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_drv_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(param_1 + 0x88);
  uVar1 = 0xffffffea;
  if ((lVar2 != 0) && (lVar2 != 0x40)) {
    pcVar3 = *(code **)(lVar2 + -0x38);
    if (pcVar3 == (code *)0x0) {
      uVar1 = 0xffffffed;
    }
    else {
      lVar2 = 0;
      if (param_1 != 0) {
        lVar2 = param_1 + -0x48;
      }
      if (*(int *)(pcVar3 + -4) != -0x652cd95b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102514);
        (*pcVar3)();
      }
      uVar1 = (*pcVar3)(lVar2);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// swr_drv_shutdown @ 00102530 size=88
// signature: undefined swr_drv_shutdown(void)
// callers: []
//------------------------------------------------------------

void swr_drv_shutdown(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = *(long *)(param_1 + 0x88);
  if (((lVar1 != 0) && (lVar1 != 0x40)) &&
     (pcVar2 = *(code **)(lVar1 + -0x30), pcVar2 != (code *)0x0)) {
    lVar1 = 0;
    if (param_1 != 0) {
      lVar1 = param_1 + -0x48;
    }
    if (*(int *)(pcVar2 + -4) != 0x645a9cc2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102578);
      (*pcVar2)();
    }
    (*pcVar2)(lVar1);
  }
  return;
}



//------------------------------------------------------------
// swr_driver_unregister @ 0010258c size=36
// signature: undefined swr_driver_unregister(void)
// callers: []
//------------------------------------------------------------

void swr_driver_unregister(long param_1)

{
  if (param_1 != 0) {
    driver_unregister(param_1 + 0x40);
  }
  return;
}



//------------------------------------------------------------
// swr_master_add_boarddevices @ 001025b4 size=216
// signature: undefined swr_master_add_boarddevices(void)
// callers: []
//------------------------------------------------------------

void swr_master_add_boarddevices(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  ulong uVar3;
  long lVar4;
  undefined **ppuVar5;
  
  mutex_lock(board_lock);
  puVar2 = PTR_swr_master_list_00103458;
  puVar1 = (undefined *)(param_1 + 0x390);
  uVar3 = __list_add_valid(puVar1,PTR_swr_master_list_00103458,&swr_master_list);
  if ((uVar3 & 1) != 0) {
    PTR_swr_master_list_00103458 = puVar1;
    *(undefined ***)(param_1 + 0x390) = &swr_master_list;
    *(undefined **)(param_1 + 0x398) = puVar2;
    *(undefined **)puVar2 = puVar1;
  }
  ppuVar5 = (undefined **)board_list;
  if ((undefined **)board_list != &board_list) {
    do {
      if ((*(int *)(param_1 + 0x3a0) == *(int *)(ppuVar5 + 6)) &&
         (lVar4 = swr_new_device(param_1,ppuVar5 + 2), lVar4 == 0)) {
        _dev_err(param_1,"can\'t create new device for %s\n",ppuVar5[9]);
      }
      ppuVar5 = (undefined **)*ppuVar5;
    } while (ppuVar5 != &board_list);
  }
  mutex_unlock(board_lock);
  return;
}



//------------------------------------------------------------
// get_matching_swr_slave_device @ 00102690 size=180
// signature: undefined get_matching_swr_slave_device(void)
// callers: []
//------------------------------------------------------------

undefined ** get_matching_swr_slave_device(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  mutex_lock(board_lock);
  ppuVar3 = (undefined **)swr_master_list;
  do {
    if (ppuVar3 == &swr_master_list) {
      ppuVar2 = (undefined **)0x0;
LAB_00102720:
      mutex_unlock(board_lock);
      return ppuVar2;
    }
    ppuVar1 = ppuVar3 + 3;
    mutex_lock(ppuVar1);
    ppuVar2 = ppuVar3 + 9;
    while (ppuVar2 = (undefined **)*ppuVar2, ppuVar2 != ppuVar3 + 9) {
      if (ppuVar2[0x60] == param_1) {
        ppuVar2 = ppuVar2 + -6;
        mutex_unlock(ppuVar1);
        goto LAB_00102720;
      }
    }
    mutex_unlock(ppuVar1);
    ppuVar3 = (undefined **)*ppuVar3;
  } while( true );
}



//------------------------------------------------------------
// swr_unregister_master @ 00102748 size=232
// signature: undefined swr_unregister_master(void)
// callers: []
//------------------------------------------------------------

void swr_unregister_master(long param_1)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  
  mutex_lock(swr_lock);
  lVar1 = idr_find(master_idr,*(undefined4 *)(param_1 + 0x3a0));
  mutex_unlock(swr_lock);
  if (lVar1 == param_1) {
    mutex_lock(board_lock);
    uVar2 = __list_del_entry_valid(param_1 + 0x390);
    if ((uVar2 & 1) != 0) {
      plVar3 = *(long **)(param_1 + 0x398);
      lVar1 = *(long *)(param_1 + 0x390);
      *(long **)(lVar1 + 8) = plVar3;
      *plVar3 = lVar1;
    }
    *(undefined8 *)(param_1 + 0x390) = 0xdead000000000100;
    *(undefined8 *)(param_1 + 0x398) = 0xdead000000000122;
    mutex_unlock(board_lock);
    mutex_lock(swr_lock);
    idr_remove(master_idr,*(undefined4 *)(param_1 + 0x3a0));
    mutex_unlock(swr_lock);
    device_for_each_child(param_1,0,__unregister);
    device_unregister(param_1);
  }
  return;
}



//------------------------------------------------------------
// __unregister @ 00102834 size=44
// signature: undefined __unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 __unregister(long param_1)

{
  if ((param_1 != 0) && (param_1 != 0x48)) {
    device_unregister();
  }
  return 0;
}



//------------------------------------------------------------
// swr_register_master @ 00102864 size=272
// signature: undefined swr_register_master(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int swr_register_master(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  mutex_lock(swr_lock);
  iVar2 = of_alias_get_id(*(undefined8 *)(param_1 + 0x2e8),&DAT_00103b2a);
  if (iVar2 < 0) {
    iVar2 = *(int *)(param_1 + 0x3a0);
  }
  else {
    *(int *)(param_1 + 0x3a0) = iVar2;
  }
  iVar2 = idr_alloc(master_idr,param_1,iVar2,iVar2 + 1,0xcc0);
  mutex_unlock(swr_lock);
  if (-1 < iVar2) {
    *(int *)(param_1 + 0x3a0) = iVar2;
    if (_DAT_001031e8 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102974);
      (*pcVar1)();
    }
    dev_set_name(param_1,"swr%u",iVar2);
    *(undefined1 **)(param_1 + 0x78) = swr_master_type;
    *(undefined ***)(param_1 + 0x80) = &soundwire_type;
    __mutex_init(param_1 + 0x3a8,"&master->mlock",&swr_register_master___key);
    iVar2 = device_register(param_1);
    if (iVar2 < 0) {
      idr_remove(master_idr,*(undefined4 *)(param_1 + 0x3a0));
    }
    else {
      iVar2 = 0;
      *(long *)(param_1 + 0x3d8) = param_1 + 0x3d8;
      *(long *)(param_1 + 0x3e0) = param_1 + 0x3d8;
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// swr_device_match @ 0010297c size=172
// signature: undefined swr_device_match(void)
// callers: []
//------------------------------------------------------------

ulong swr_device_match(long param_1,undefined8 *param_2)

{
  char cVar1;
  int iVar2;
  char *__s1;
  char *__s2;
  
  if (param_2 == (undefined8 *)0x0) {
    return 0xffffffea;
  }
  if (param_2 == (undefined8 *)0x40) {
    return 0xffffffea;
  }
  if (*(undefined1 **)(param_1 + 0x78) == swr_dev_type) {
    if (param_1 == 0) {
      return 0xffffffea;
    }
    __s1 = (char *)(param_1 + -0x48);
    if (__s1 == (char *)0x0) {
      return 0xffffffea;
    }
    __s2 = (char *)param_2[0x16];
    if (__s2 != (char *)0x0) {
      cVar1 = *__s2;
      while (cVar1 != '\0') {
        iVar2 = strcmp(__s1,__s2);
        if (iVar2 == 0) goto LAB_00102a00;
        __s2 = __s2 + 0x28;
        cVar1 = *__s2;
      }
      __s2 = (char *)0x0;
LAB_00102a00:
      return (ulong)(__s2 != (char *)0x0);
    }
    if ((char *)*param_2 != (char *)0x0) {
      iVar2 = strcmp(__s1,(char *)*param_2);
      return (ulong)(iVar2 == 0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// swr_master_release @ 00102a2c size=4
// signature: undefined swr_master_release(void)
// callers: []
//------------------------------------------------------------

void swr_master_release(void)

{
  return;
}



//------------------------------------------------------------
// swr_pm_suspend @ 00102a34 size=148
// signature: undefined swr_pm_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_pm_suspend(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(param_1 + 0x88);
  if ((lVar2 != 0) && (*(long *)(lVar2 + 0x78) != 0)) {
    uVar1 = pm_generic_suspend(param_1);
    return uVar1;
  }
  if (*(undefined1 **)(param_1 + 0x78) == swr_dev_type) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 + -0x48 == 0) {
      return 0;
    }
    if (lVar2 == 0) {
      return 0;
    }
    pcVar3 = *(code **)(lVar2 + -0x28);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x1a96ba08) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102ac0);
        (*pcVar3)();
      }
      uVar1 = (*pcVar3)(param_1 + -0x48,2);
      return uVar1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// swr_pm_resume @ 00102acc size=144
// signature: undefined swr_pm_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_pm_resume(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(param_1 + 0x88);
  if ((lVar2 != 0) && (*(long *)(lVar2 + 0x78) != 0)) {
    uVar1 = pm_generic_resume(param_1);
    return uVar1;
  }
  if (*(undefined1 **)(param_1 + 0x78) == swr_dev_type) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 + -0x48 == 0) {
      return 0;
    }
    if (lVar2 == 0) {
      return 0;
    }
    pcVar3 = *(code **)(lVar2 + -0x20);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x652cd95b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102b54);
        (*pcVar3)();
      }
      uVar1 = (*pcVar3)(param_1 + -0x48);
      return uVar1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00103d50 size=88
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = bus_register(&soundwire_type);
  if (iVar1 == 0) {
    iVar1 = device_register(soundwire_dev);
    if (iVar1 == 0) {
      return 0;
    }
  }
  bus_unregister(&soundwire_type);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00103dac size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  device_unregister(soundwire_dev);
  bus_unregister(&soundwire_type);
  return;
}



//------------------------------------------------------------
// __regmap_init @ 00105000 size=1
// signature: undefined __regmap_init(void)
// callers: [__regmap_init_swr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __regmap_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init @ 00105008 size=1
// signature: undefined __devm_regmap_init(void)
// callers: [__devm_regmap_init_swr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00105010 size=1
// signature: undefined dev_get_regmap(void)
// callers: [regmap_swr_write, regmap_swr_gather_write, regmap_swr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105018 size=1
// signature: undefined __kmalloc(void)
// callers: [regmap_swr_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00105020 size=1
// signature: undefined ___ratelimit(void)
// callers: [regmap_swr_write, swr_port_response, of_register_swr_devices, swr_disconnect_port, swr_connect_port, regmap_swr_gather_write, regmap_swr_read, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105028 size=1
// signature: undefined kfree(void)
// callers: [regmap_swr_write, swr_port_response, swr_dev_release, swr_disconnect_port, swr_connect_port, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105030 size=1
// signature: undefined _dev_err(void)
// callers: [regmap_swr_write, swr_master_add_boarddevices, swr_port_response, of_register_swr_devices, swr_disconnect_port, swr_connect_port, regmap_swr_gather_write, regmap_swr_reg_address_get, regmap_swr_read, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105038 size=1
// signature: undefined mutex_lock(void)
// callers: [swr_master_add_boarddevices, swr_dev_release, swr_connect_port, swr_device_wakeup_vote, regmap_swr_gather_write, regmap_swr_read, swr_unregister_master, get_matching_swr_slave_device, swr_device_wakeup_unvote, swr_register_master, swr_disconnect_port, swr_init_port_params, swr_get_logical_dev_num, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105040 size=1
// signature: undefined mutex_unlock(void)
// callers: [swr_master_add_boarddevices, swr_dev_release, swr_connect_port, swr_device_wakeup_vote, regmap_swr_gather_write, regmap_swr_read, swr_unregister_master, get_matching_swr_slave_device, swr_device_wakeup_unvote, swr_register_master, swr_disconnect_port, swr_init_port_params, swr_get_logical_dev_num, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [of_register_swr_devices, regmap_swr_gather_write, regmap_swr_reg_address_get, regmap_swr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105050 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [swr_remove_device, swr_dev_release, swr_new_device, swr_unregister_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 00105058 size=1
// signature: undefined get_device(void)
// callers: [swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [swr_disconnect_port, swr_connect_port, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00105070 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105078 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105080 size=1
// signature: undefined __list_add_valid(void)
// callers: [swr_master_add_boarddevices, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00105088 size=1
// signature: undefined dev_set_name(void)
// callers: [swr_register_master, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 00105090 size=1
// signature: undefined device_register(void)
// callers: [swr_register_master, init_module, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00105098 size=1
// signature: undefined put_device(void)
// callers: [swr_dev_release, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050a0 size=1
// signature: undefined _printk(void)
// callers: [swr_device_wakeup_unvote, swr_disconnect_port, swr_connect_port, swr_init_port_params, swr_device_wakeup_vote, swr_get_logical_dev_num, swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001050a8 size=1
// signature: undefined fortify_panic(void)
// callers: [swr_new_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001050b0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [of_register_swr_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_modalias_node @ 001050b8 size=1
// signature: undefined of_modalias_node(void)
// callers: [of_register_swr_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_modalias_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u64 @ 001050c0 size=1
// signature: undefined of_property_read_u64(void)
// callers: [of_register_swr_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 001050c8 size=1
// signature: undefined krealloc(void)
// callers: [swr_disconnect_port, swr_connect_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_register @ 001050d0 size=1
// signature: undefined driver_register(void)
// callers: [swr_driver_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 001050d8 size=1
// signature: undefined driver_unregister(void)
// callers: [swr_driver_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 001050e0 size=1
// signature: undefined idr_find(void)
// callers: [swr_unregister_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 001050e8 size=1
// signature: undefined idr_remove(void)
// callers: [swr_register_master, swr_unregister_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 001050f0 size=1
// signature: undefined device_for_each_child(void)
// callers: [swr_unregister_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 001050f8 size=1
// signature: undefined device_unregister(void)
// callers: [__unregister, swr_unregister_master, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_alias_get_id @ 00105100 size=1
// signature: undefined of_alias_get_id(void)
// callers: [swr_register_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_alias_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00105108 size=1
// signature: undefined idr_alloc(void)
// callers: [swr_register_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105110 size=1
// signature: undefined __mutex_init(void)
// callers: [swr_register_master]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105118 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [swr_device_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 00105120 size=1
// signature: undefined bus_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_unregister @ 00105128 size=1
// signature: undefined bus_unregister(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_generic_suspend @ 00105130 size=1
// signature: undefined pm_generic_suspend(void)
// callers: [swr_pm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_generic_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_generic_resume @ 00105138 size=1
// signature: undefined pm_generic_resume(void)
// callers: [swr_pm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_generic_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



