// Decompiled by Ghidra 12.2
// Program: coresight-csr.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_qdss_csr_enable_bam_to_usb @ 001007e4 size=184
// signature: undefined msm_qdss_csr_enable_bam_to_usb(void)
// callers: []
//------------------------------------------------------------

void msm_qdss_csr_enable_bam_to_usb(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((((param_1 != 0) && (param_1 != 0x68)) &&
      (param_1 - 0x68U < 0xfffffffffffff000 || param_1 == -0xf98)) &&
     (*(char *)(param_1 + 0x24) != '\0')) {
    uVar2 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar1 = *(uint *)(*(long *)(param_1 + -0x68) + 0x30) & 0xfffffffc | *(uint *)(param_1 + -0x28);
    *(uint *)(*(long *)(param_1 + -0x68) + 0x30) = uVar1;
    *(uint *)(*(long *)(param_1 + -0x68) + 0x30) = uVar1 | 4;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar2);
  }
  return;
}



//------------------------------------------------------------
// msm_qdss_csr_enable_flush @ 001008a0 size=260
// signature: undefined msm_qdss_csr_enable_flush(void)
// callers: []
//------------------------------------------------------------

void msm_qdss_csr_enable_flush(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((((param_1 != 0) && (param_1 != 0x68)) &&
      (param_1 - 0x68U < 0xfffffffffffff000 || param_1 == -0xf98)) &&
     (*(char *)(param_1 + 0x24) != '\0')) {
    uVar2 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    *(uint *)(*(long *)(param_1 + -0x68) + 0x34) =
         *(uint *)(*(long *)(param_1 + -0x68) + 0x34) & 0xfffc0003 | *(int *)(param_1 + -0x24) << 2;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar1 = 2;
    if (*(char *)(param_1 + 0x25) != '\0') {
      uVar1 = 0x40002;
    }
    *(uint *)(*(long *)(param_1 + -0x68) + 0x34) =
         uVar1 | *(uint *)(*(long *)(param_1 + -0x68) + 0x34);
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    *(undefined1 *)(param_1 + 0x29) = 1;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar2);
  }
  return;
}



//------------------------------------------------------------
// msm_qdss_csr_disable_bam_to_usb @ 001009a8 size=160
// signature: undefined msm_qdss_csr_disable_bam_to_usb(void)
// callers: []
//------------------------------------------------------------

void msm_qdss_csr_disable_bam_to_usb(long param_1)

{
  undefined8 uVar1;
  
  if ((((param_1 != 0) && (param_1 != 0x68)) &&
      (param_1 - 0x68U < 0xfffffffffffff000 || param_1 == -0xf98)) &&
     (*(char *)(param_1 + 0x24) != '\0')) {
    uVar1 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    *(uint *)(*(long *)(param_1 + -0x68) + 0x30) =
         *(uint *)(*(long *)(param_1 + -0x68) + 0x30) & 0xfffffffb;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_qdss_csr_disable_flush @ 00100a4c size=188
// signature: undefined msm_qdss_csr_disable_flush(void)
// callers: []
//------------------------------------------------------------

void msm_qdss_csr_disable_flush(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((((param_1 != 0) && (param_1 != 0x68)) &&
      (param_1 - 0x68U < 0xfffffffffffff000 || param_1 == -0xf98)) &&
     (*(char *)(param_1 + 0x24) != '\0')) {
    uVar2 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar1 = 0xfffffffd;
    if (*(char *)(param_1 + 0x25) != '\0') {
      uVar1 = 0xfffbfffd;
    }
    *(uint *)(*(long *)(param_1 + -0x68) + 0x34) =
         uVar1 & *(uint *)(*(long *)(param_1 + -0x68) + 0x34);
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    *(undefined1 *)(param_1 + 0x29) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar2);
  }
  return;
}



//------------------------------------------------------------
// msm_qdss_csr_enable_eth @ 00100b0c size=152
// signature: undefined msm_qdss_csr_enable_eth(void)
// callers: []
//------------------------------------------------------------

void msm_qdss_csr_enable_eth(long param_1)

{
  undefined8 uVar1;
  
  if (((param_1 != 0) && (param_1 != 0x68)) &&
     (param_1 - 0x68U < 0xfffffffffffff000 || param_1 == -0xf98)) {
    uVar1 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0x130) = 0x104;
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0x134) = 0x104;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_qdss_csr_disable_eth @ 00100ba8 size=148
// signature: undefined msm_qdss_csr_disable_eth(void)
// callers: []
//------------------------------------------------------------

void msm_qdss_csr_disable_eth(long param_1)

{
  undefined8 uVar1;
  
  if (((param_1 != 0) && (param_1 != 0x68)) &&
     (param_1 - 0x68U < 0xfffffffffffff000 || param_1 == -0xf98)) {
    uVar1 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0x130) = 0;
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0x134) = 0;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar1);
  }
  return;
}



//------------------------------------------------------------
// coresight_csr_hwctrl_set @ 00100c40 size=300
// signature: undefined coresight_csr_hwctrl_set(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_csr_hwctrl_set(long param_1,long param_2,undefined4 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    plVar1 = (long *)(param_1 - 0x68);
    uVar4 = 0xffffffea;
    if (((plVar1 != (long *)0x0) && (plVar1 < (long *)0xfffffffffffff000 || param_1 == -0xf98)) &&
       (*(char *)(param_1 + 0x26) != '\0')) {
      uVar2 = _raw_spin_lock_irqsave(param_1 + 0x20);
      *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      lVar3 = *(long *)(param_1 + -0x60);
      if (lVar3 + 0x20 == param_2) {
        uVar4 = 0;
        *(undefined4 *)(*plVar1 + 0x20) = param_3;
      }
      else if (lVar3 + 0x24 == param_2) {
        uVar4 = 0;
        *(undefined4 *)(*plVar1 + 0x24) = param_3;
      }
      else if (lVar3 + 0x28 == param_2) {
        uVar4 = 0;
        *(undefined4 *)(*plVar1 + 0x28) = param_3;
      }
      else if (lVar3 + 0x2c == param_2) {
        uVar4 = 0;
        *(undefined4 *)(*plVar1 + 0x2c) = param_3;
      }
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar1 + 0xfb0) = 0;
      _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar2);
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// coresight_csr_set_byte_cntr @ 00100d70 size=216
// signature: undefined coresight_csr_set_byte_cntr(void)
// callers: []
//------------------------------------------------------------

void coresight_csr_set_byte_cntr(long param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if ((((param_1 != 0) && (plVar2 = (long *)(param_1 - 0x68), plVar2 != (long *)0x0)) &&
      (plVar2 < (long *)0xfffffffffffff000 || param_1 == -0xf98)) &&
     (*(char *)(param_1 + 0x27) != '\0')) {
    uVar4 = (ulong)param_2;
    uVar3 = _raw_spin_lock_irqsave(param_1 + 0x20);
    *(undefined4 *)(*(long *)(param_1 + -0x68) + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    if (*(char *)(param_1 + 0x2b) != '\0') {
      if (param_2 - 0x35 < 0x23) {
        uVar4 = (ulong)(param_2 - 0x14);
      }
      else {
        uVar1 = param_2 - 0x44;
        if (0x22 < param_2 - 0x81) {
          uVar1 = param_2;
        }
        uVar4 = (ulong)uVar1;
      }
    }
    *(undefined4 *)(*(long *)(param_1 + -0x68) + uVar4) = param_3;
    DataSynchronizationBarrier(3,3,0);
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar2 + 0xfb0) = 0;
    _raw_spin_unlock_irqrestore(param_1 + 0x20,uVar3);
  }
  return;
}



//------------------------------------------------------------
// coresight_csr_get @ 00100e4c size=132
// signature: undefined coresight_csr_get(void)
// callers: []
//------------------------------------------------------------

undefined ** coresight_csr_get(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  
  uVar2 = _raw_spin_lock_irqsave(&csr_spinlock);
  ppuVar3 = &csr_list;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &csr_list) {
      ppuVar3 = (undefined **)0xffffffffffffffea;
      goto LAB_00100ea8;
    }
    iVar1 = strcmp(ppuVar3[-1],param_1);
  } while (iVar1 != 0);
  ppuVar3 = ppuVar3 + -1;
LAB_00100ea8:
  _raw_spin_unlock_irqrestore(&csr_spinlock,uVar2);
  return ppuVar3;
}



//------------------------------------------------------------
// of_get_coresight_csr_name @ 00100ed4 size=168
// signature: undefined of_get_coresight_csr_name(void)
// callers: []
//------------------------------------------------------------

void of_get_coresight_csr_name(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long local_78 [11];
  
  lVar1 = sp_el0;
  local_78[10] = *(long *)(lVar1 + 0x638);
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  iVar2 = __of_parse_phandle_with_args(param_1,"coresight-csr",0,0,0,local_78);
  uVar3 = 0xffffffea;
  if ((iVar2 == 0) && (local_78[0] != 0)) {
    uVar3 = of_property_read_string(local_78[0],"coresight-name",param_2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// coresight_csr_set_etr_atid @ 00100f80 size=612
// signature: undefined coresight_csr_set_etr_atid(void)
// callers: []
//------------------------------------------------------------

int coresight_csr_set_etr_atid(long param_1,int param_2,uint param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  char *__s2;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined **ppuVar9;
  undefined **ppuVar10;
  char *local_b0;
  long local_a8 [11];
  
  lVar4 = sp_el0;
  local_a8[10] = *(long *)(lVar4 + 0x638);
  local_b0 = (char *)0x0;
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
  iVar5 = __of_parse_phandle_with_args
                    (*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),"coresight-csr",0,0,0,
                     local_a8);
  iVar6 = -0x16;
  if ((iVar5 == 0) && (local_a8[0] != 0)) {
    iVar6 = of_property_read_string(local_a8[0],"coresight-name",&local_b0);
    __s2 = local_b0;
    if (iVar6 == 0) {
      uVar7 = _raw_spin_lock_irqsave(&csr_spinlock);
      ppuVar10 = &csr_list;
      do {
        ppuVar10 = (undefined **)*ppuVar10;
        if (ppuVar10 == &csr_list) {
          _raw_spin_unlock_irqrestore(&csr_spinlock,uVar7);
          ppuVar10 = (undefined **)0xffffffffffffffea;
          goto LAB_001010c4;
        }
        iVar5 = strcmp(ppuVar10[-1],__s2);
      } while (iVar5 != 0);
      ppuVar10 = ppuVar10 + -1;
      _raw_spin_unlock_irqrestore(&csr_spinlock,uVar7);
      if (ppuVar10 == (undefined **)0x0) {
        iVar6 = -0x16;
      }
      else {
LAB_001010c4:
        iVar6 = -0x16;
        if (((param_2 != 0) && (ppuVar9 = ppuVar10 + -0xd, ppuVar9 != (undefined **)0x0)) &&
           (ppuVar9 < (undefined **)0xfffffffffffff000 ||
            ppuVar10 == (undefined **)0xfffffffffffff068)) {
          uVar7 = _raw_spin_lock_irqsave(ppuVar10 + 4);
          *(undefined4 *)(ppuVar10[-0xd] + 0xfb0) = 0xc5acce55;
          DataSynchronizationBarrier(3,3,0);
          uVar1 = param_3 >> 3 & 0x1ffffffc;
          if (uVar1 < 0xd) {
            uVar1 = uVar1 + param_2;
            uVar8 = uVar1;
            if (*(char *)((long)ppuVar10 + 0x2b) != '\0') {
              if (uVar1 - 0x35 < 0x23) {
                uVar8 = uVar1 - 0x14;
              }
              else {
                uVar8 = uVar1 - 0x44;
                if (0x22 < uVar1 - 0x81) {
                  uVar8 = uVar1;
                }
              }
            }
            uVar3 = 1 << (ulong)(param_3 & 0x1f);
            uVar2 = *(uint *)(ppuVar10[-0xd] + uVar8) | uVar3;
            if ((param_4 & 1) == 0) {
              uVar2 = *(uint *)(ppuVar10[-0xd] + uVar8) & (uVar3 ^ 0xffffffff);
            }
            uVar8 = uVar1;
            if (*(char *)((long)ppuVar10 + 0x2b) != '\0') {
              if (uVar1 - 0x35 < 0x23) {
                uVar8 = uVar1 - 0x14;
              }
              else {
                uVar8 = uVar1 - 0x44;
                if (0x22 < uVar1 - 0x81) {
                  uVar8 = uVar1;
                }
              }
            }
            *(uint *)(ppuVar10[-0xd] + uVar8) = uVar2;
            DataSynchronizationBarrier(3,3,0);
            iVar6 = 0;
            *(undefined4 *)(*ppuVar9 + 0xfb0) = 0;
          }
          else {
            DataSynchronizationBarrier(3,3,0);
            *(undefined4 *)(*ppuVar9 + 0xfb0) = 0;
          }
          _raw_spin_unlock_irqrestore(ppuVar10 + 4,uVar7);
        }
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// csr_probe @ 001011e8 size=928
// signature: undefined csr_probe(void)
// callers: []
//------------------------------------------------------------

void csr_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  ulong *puVar8;
  undefined8 uVar9;
  ulong *puVar10;
  undefined4 *puVar11;
  ulong uVar12;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  long lStack_80;
  undefined **local_78;
  long local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar7 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = (undefined **)0x0;
  local_70 = 0;
  local_88 = 0;
  lStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  local_70 = coresight_alloc_device_name(csr_devs,lVar1);
  if (local_70 != 0) {
    uVar5 = coresight_get_platform_data(lVar1);
    if (0xfffffffffffff000 < uVar5) goto LAB_001014c4;
    *(ulong *)(param_1 + 0xa0) = uVar5;
    plVar6 = (long *)devm_kmalloc(lVar1,0x98,0xdc0);
    if (plVar6 != (long *)0x0) {
      plVar6[4] = lVar1;
      *(long **)(param_1 + 0xa8) = plVar6;
      lVar7 = devm_clk_get(lVar1,"apb_pclk");
      plVar6[0x10] = lVar7;
      puVar8 = (ulong *)platform_get_resource_byname(param_1,0x200,"csr-base");
      if (puVar8 == (ulong *)0x0) {
LAB_00101424:
        uVar5 = 0xffffffed;
        goto LAB_001014c4;
      }
      plVar6[1] = *puVar8;
      lVar7 = devm_ioremap(lVar1,*puVar8,(puVar8[1] - *puVar8) + 1);
      *plVar6 = lVar7;
      if (lVar7 != 0) {
        iVar4 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,blk-size",plVar6 + 8,1,0);
        if (iVar4 < 0) {
          *(undefined4 *)(plVar6 + 8) = 0;
        }
        lVar7 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,usb-bam-support",0);
        uVar9 = *(undefined8 *)(param_1 + 0x2f8);
        *(bool *)((long)plVar6 + 0x8c) = lVar7 != 0;
        lVar7 = of_find_property(uVar9,"qcom,hwctrl-set-support",0);
        uVar9 = *(undefined8 *)(param_1 + 0x2f8);
        *(bool *)((long)plVar6 + 0x8e) = lVar7 != 0;
        lVar7 = of_find_property(uVar9,"qcom,set-byte-cntr-support",0);
        uVar9 = *(undefined8 *)(param_1 + 0x2f8);
        *(bool *)((long)plVar6 + 0x8f) = lVar7 != 0;
        lVar7 = of_find_property(uVar9,"qcom,timestamp-support",0);
        uVar9 = *(undefined8 *)(param_1 + 0x2f8);
        *(bool *)(plVar6 + 0x12) = lVar7 != 0;
        lVar7 = of_find_property(uVar9,"qcom,perflsheot-set-support",0);
        uVar9 = *(undefined8 *)(param_1 + 0x2f8);
        *(bool *)((long)plVar6 + 0x8d) = lVar7 != 0;
        lVar7 = of_find_property(uVar9,"qcom,aodbg-csr-support",0);
        *(bool *)((long)plVar6 + 0x93) = lVar7 != 0;
        if (*(char *)((long)plVar6 + 0x8c) != '\0') {
          *(undefined4 *)((long)plVar6 + 0x44) = 1;
        }
        lVar7 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,msr-support",0);
        *(bool *)((long)plVar6 + 0x92) = lVar7 != 0;
        if (lVar7 == 0) {
LAB_0010147c:
          local_88 = *(undefined8 *)(param_1 + 0xa0);
          local_a0 = CONCAT44(local_a0._4_4_,4);
          if (((char)plVar6[0x12] == '\0') && (*(char *)((long)plVar6 + 0x92) == '\0')) {
            if (*(char *)((long)plVar6 + 0x8c) != '\0') {
              local_78 = &csr_attr_grps;
            }
          }
          else {
            local_78 = &swao_csr_attr_grps;
          }
          lStack_80 = lVar1;
          uVar5 = coresight_register(&local_a0);
          plVar6[5] = uVar5;
          if (uVar5 < 0xfffffffffffff001) {
            coresight_set_csr_ops(&csr_atid_ops);
            *(undefined4 *)(plVar6 + 0x11) = 0;
            plVar6[0xd] = local_70;
            _raw_spin_lock(&csr_spinlock);
            puVar3 = PTR_csr_list_001027c8;
            plVar2 = plVar6 + 0xe;
            uVar5 = __list_add_valid(plVar2,PTR_csr_list_001027c8,&csr_list);
            if ((uVar5 & 1) != 0) {
              PTR_csr_list_001027c8 = (undefined *)plVar2;
              plVar6[0xe] = (long)&csr_list;
              plVar6[0xf] = (long)puVar3;
              *(long **)puVar3 = plVar2;
            }
            _raw_spin_unlock(&csr_spinlock);
            _dev_info(lVar1,"CSR initialized: %s\n",plVar6[0xd]);
            uVar5 = 0;
          }
          goto LAB_001014c4;
        }
        puVar10 = (ulong *)platform_get_resource_byname(param_1,0x200,"msr-base");
        if (((puVar10 == (ulong *)0x0) || (lVar7 = *puVar10 - *puVar8, *puVar10 < *puVar8)) ||
           (puVar8[1] < puVar10[1])) goto LAB_00101424;
        plVar6[2] = lVar7;
        uVar5 = puVar10[1];
        uVar12 = *puVar8;
        plVar6[3] = uVar5 - uVar12;
        lVar7 = devm_kmalloc(lVar1,((uVar5 - uVar12) - lVar7) + 1 & 0xfffffffffffffffc,0xdc0);
        plVar6[6] = lVar7;
        if (lVar7 != 0) {
          puVar11 = (undefined4 *)devm_kmalloc(lVar1,4,0xdc0);
          plVar6[7] = (long)puVar11;
          if (puVar11 != (undefined4 *)0x0) {
            *puVar11 = 0;
            goto LAB_0010147c;
          }
        }
      }
    }
  }
  uVar5 = 0xfffffff4;
LAB_001014c4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// csr_remove @ 0010158c size=120
// signature: undefined csr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 csr_remove(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xa8);
  _raw_spin_lock(&csr_spinlock);
  uVar3 = __list_del_entry_valid(lVar4 + 0x70);
  if ((uVar3 & 1) != 0) {
    lVar1 = *(long *)(lVar4 + 0x70);
    plVar2 = *(long **)(lVar4 + 0x78);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(lVar4 + 0x70) = 0xdead000000000100;
  *(undefined8 *)(lVar4 + 0x78) = 0xdead000000000122;
  _raw_spin_unlock(&csr_spinlock);
  coresight_remove_csr_ops();
  coresight_unregister(*(undefined8 *)(lVar4 + 0x28));
  return 0;
}



//------------------------------------------------------------
// timestamp_show @ 00101608 size=424
// signature: undefined timestamp_show(void)
// callers: []
//------------------------------------------------------------

long timestamp_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar7 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar7)) ||
     ((char)plVar7[0x12] == '\0')) {
    _dev_err(param_1,"Invalid param\n");
    lVar6 = 0;
  }
  else {
    lVar6 = plVar7[0x10];
    iVar4 = clk_prepare(lVar6);
    if (iVar4 == 0) {
      iVar4 = clk_enable(lVar6);
      if (iVar4 == 0) {
        uVar5 = _raw_spin_lock_irqsave(plVar7 + 0x11);
        *(undefined4 *)(*plVar7 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        lVar6 = 0x38;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x24;
        }
        uVar1 = *(uint *)(*plVar7 + lVar6);
        lVar6 = 0x38;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x24;
        }
        *(uint *)(*plVar7 + lVar6) = uVar1 & 0xfffffffe;
        lVar6 = 0x38;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x24;
        }
        *(uint *)(*plVar7 + lVar6) = uVar1 | 1;
        lVar6 = 0x44;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x30;
        }
        uVar2 = *(undefined4 *)(*plVar7 + lVar6);
        lVar6 = 0x48;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x34;
        }
        uVar3 = *(undefined4 *)(*plVar7 + lVar6);
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar7 + 0xfb0) = 0;
        _raw_spin_unlock_irqrestore(plVar7 + 0x11,uVar5);
        lVar6 = plVar7[0x10];
        clk_disable(lVar6);
        clk_unprepare(lVar6);
        iVar4 = scnprintf(param_3,0x1000,"%llu\n",CONCAT44(uVar3,uVar2));
        return (long)iVar4;
      }
      clk_unprepare(lVar6);
    }
    lVar6 = (long)iVar4;
  }
  return lVar6;
}



//------------------------------------------------------------
// clk_prepare_enable @ 001017b0 size=76
// signature: undefined clk_prepare_enable(void)
// callers: [msr_store]
//------------------------------------------------------------

int clk_prepare_enable(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = clk_prepare();
  if (iVar1 == 0) {
    iVar1 = clk_enable(param_1);
    if (iVar1 != 0) {
      clk_unprepare(param_1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// aotime_show @ 00101800 size=424
// signature: undefined aotime_show(void)
// callers: []
//------------------------------------------------------------

long aotime_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar7 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar7)) ||
     ((char)plVar7[0x12] == '\0')) {
    _dev_err(param_1,"Invalid param\n");
    lVar6 = 0;
  }
  else {
    lVar6 = plVar7[0x10];
    iVar4 = clk_prepare(lVar6);
    if (iVar4 == 0) {
      iVar4 = clk_enable(lVar6);
      if (iVar4 == 0) {
        uVar5 = _raw_spin_lock_irqsave(plVar7 + 0x11);
        *(undefined4 *)(*plVar7 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        lVar6 = 0x38;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x24;
        }
        uVar1 = *(uint *)(*plVar7 + lVar6);
        lVar6 = 0x38;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x24;
        }
        *(uint *)(*plVar7 + lVar6) = uVar1 & 0xfffffffe;
        lVar6 = 0x38;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x24;
        }
        *(uint *)(*plVar7 + lVar6) = uVar1 | 1;
        lVar6 = 0x3c;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x28;
        }
        uVar2 = *(undefined4 *)(*plVar7 + lVar6);
        lVar6 = 0x40;
        if (*(char *)((long)plVar7 + 0x93) != '\0') {
          lVar6 = 0x2c;
        }
        uVar3 = *(undefined4 *)(*plVar7 + lVar6);
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar7 + 0xfb0) = 0;
        _raw_spin_unlock_irqrestore(plVar7 + 0x11,uVar5);
        lVar6 = plVar7[0x10];
        clk_disable(lVar6);
        clk_unprepare(lVar6);
        iVar4 = scnprintf(param_3,0x1000,"%llu\n",CONCAT44(uVar3,uVar2));
        return (long)iVar4;
      }
      clk_unprepare(lVar6);
    }
    lVar6 = (long)iVar4;
  }
  return lVar6;
}



//------------------------------------------------------------
// msr_show @ 001019ac size=212
// signature: undefined msr_show(void)
// callers: []
//------------------------------------------------------------

long msr_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  lVar2 = -0x16;
  uVar4 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) && (*(char *)(uVar4 + 0x92) != '\0')) &&
     ((*(ulong *)(uVar4 + 0x30) != 0 && (*(ulong *)(uVar4 + 0x30) < 0xfffffffffffff001)))) {
    if ((*(long *)(uVar4 + 0x18) - *(long *)(uVar4 + 0x10)) + 1U < 4) {
      lVar2 = 0;
    }
    else {
      uVar3 = 0;
      lVar2 = 0;
      do {
        iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%d 0x%x\n",uVar3 & 0xffffffff,
                          *(undefined4 *)(*(long *)(uVar4 + 0x30) + uVar3 * 4));
        lVar2 = lVar2 + iVar1;
        uVar3 = (ulong)((int)uVar3 + 1);
      } while (uVar3 < (*(long *)(uVar4 + 0x18) - *(long *)(uVar4 + 0x10)) + 1U >> 2);
    }
  }
  return lVar2;
}



//------------------------------------------------------------
// msr_store @ 00101a84 size=492
// signature: undefined msr_store(void)
// callers: []
//------------------------------------------------------------

void msr_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  int *piVar8;
  uint uVar9;
  long *plVar10;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = -0x16;
  local_40 = 0;
  plVar10 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar10 != (long *)0x0) && (plVar10 < (long *)0xfffffffffffff001)) &&
     (*(char *)((long)plVar10 + 0x92) != '\0')) {
    if ((plVar10[6] != 0) && ((ulong)plVar10[6] < 0xfffffffffffff001)) {
      iVar5 = sscanf(param_3,"%x %x",(uint *)((long)&local_40 + 4),(uint *)&local_40);
      if ((iVar5 == 2) && (local_40 >> 0x20 < (plVar10[3] - plVar10[2]) + 1U >> 2)) {
        if (*(int *)plVar10[7] == 0) {
          iVar5 = clk_prepare_enable(plVar10[0x10]);
          if (iVar5 != 0) {
            lVar6 = (long)iVar5;
            goto LAB_00101c20;
          }
          piVar8 = (int *)plVar10[7];
          Hint_Prefetch(piVar8,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar8,0x10);
            if (bVar3) {
              *piVar8 = *piVar8 + 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
        }
        uVar7 = _raw_spin_lock_irqsave(plVar10 + 0x11);
        *(undefined4 *)(*plVar10 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        uVar1 = (int)plVar10[2] + local_40._4_4_ * 4;
        uVar9 = uVar1;
        if (*(char *)((long)plVar10 + 0x93) != '\0') {
          if (uVar1 - 0x35 < 0x23) {
            uVar9 = uVar1 - 0x14;
          }
          else {
            uVar9 = uVar1 - 0x44;
            if (0x22 < uVar1 - 0x81) {
              uVar9 = uVar1;
            }
          }
        }
        *(uint *)(*plVar10 + (ulong)uVar9) = (uint)local_40;
        uVar1 = (int)plVar10[2] + local_40._4_4_ * 4;
        uVar9 = uVar1;
        if (*(char *)((long)plVar10 + 0x93) != '\0') {
          if (uVar1 - 0x35 < 0x23) {
            uVar9 = uVar1 - 0x14;
          }
          else {
            uVar9 = uVar1 - 0x44;
            if (0x22 < uVar1 - 0x81) {
              uVar9 = uVar1;
            }
          }
        }
        *(undefined4 *)(plVar10[6] + (ulong)local_40._4_4_ * 4) =
             *(undefined4 *)(*plVar10 + (ulong)uVar9);
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar10 + 0xfb0) = 0;
        _raw_spin_unlock_irqrestore(plVar10 + 0x11,uVar7);
        lVar6 = param_4;
      }
      else {
        lVar6 = -0x16;
      }
    }
  }
LAB_00101c20:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// msr_reset_store @ 00101c80 size=420
// signature: undefined msr_reset_store(void)
// callers: []
//------------------------------------------------------------

void msr_reset_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  uint uVar5;
  long lVar6;
  long *plVar7;
  long local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  uVar3 = 0xffffffffffffffea;
  local_40 = 0;
  plVar7 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar7 != (long *)0x0) && (plVar7 < (long *)0xfffffffffffff001)) &&
     (*(char *)((long)plVar7 + 0x92) != '\0')) {
    if ((plVar7[6] != 0) && ((ulong)plVar7[6] < 0xfffffffffffff001)) {
      iVar2 = kstrtoull(param_3,0,&local_40);
      uVar3 = 0xffffffffffffffea;
      if ((iVar2 == 0) && (local_40 == 1)) {
        if (*(int *)plVar7[7] != 0) {
          *(int *)plVar7[7] = 0;
          uVar3 = _raw_spin_lock_irqsave(plVar7 + 0x11);
          *(undefined4 *)(*plVar7 + 0xfb0) = 0xc5acce55;
          DataSynchronizationBarrier(3,3,0);
          lVar6 = plVar7[2];
          if (3 < (plVar7[3] - lVar6) + 1U) {
            uVar4 = 0;
            do {
              uVar1 = (int)lVar6 + (int)uVar4 * 4;
              uVar5 = uVar1;
              if (*(char *)((long)plVar7 + 0x93) != '\0') {
                if (uVar1 - 0x35 < 0x23) {
                  uVar5 = uVar1 - 0x14;
                }
                else {
                  uVar5 = uVar1 - 0x44;
                  if (0x22 < uVar1 - 0x81) {
                    uVar5 = uVar1;
                  }
                }
              }
              *(undefined4 *)(*plVar7 + (ulong)uVar5) = 0;
              *(undefined4 *)(plVar7[6] + uVar4 * 4) = 0;
              lVar6 = plVar7[2];
              uVar4 = (ulong)((int)uVar4 + 1);
            } while (uVar4 < (plVar7[3] - lVar6) + 1U >> 2);
          }
          DataSynchronizationBarrier(3,3,0);
          *(undefined4 *)(*plVar7 + 0xfb0) = 0;
          _raw_spin_unlock_irqrestore(plVar7 + 0x11,uVar3);
          lVar6 = plVar7[0x10];
          clk_disable(lVar6);
          clk_unprepare(lVar6);
          uVar3 = param_4;
        }
      }
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// hbeat_val0_show @ 00101e28 size=88
// signature: undefined hbeat_val0_show(void)
// callers: []
//------------------------------------------------------------

long hbeat_val0_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = -0x16;
  uVar3 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) && (*(char *)(uVar3 + 0x90) != '\0')) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00102ae1,*(undefined8 *)(uVar3 + 0x48));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// hbeat_val0_store @ 00101e84 size=304
// signature: undefined hbeat_val0_store(void)
// callers: []
//------------------------------------------------------------

void hbeat_val0_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = 0xffffffffffffffea;
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar4 != (long *)0x0) && (plVar4 < (long *)0xfffffffffffff001)) &&
     ((char)plVar4[0x12] != '\0')) {
    iVar2 = kstrtoull(param_3,0x10,&local_40);
    if (iVar2 == 0) {
      uVar3 = _raw_spin_lock_irqsave(plVar4 + 0x11);
      plVar4[9] = local_40;
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      lVar1 = 0x84;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x40;
      }
      *(int *)(*plVar4 + lVar1) = (int)local_40;
      lVar1 = 0x88;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x44;
      }
      *(int *)(*plVar4 + lVar1) = (int)((ulong)local_40 >> 0x20);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      _raw_spin_unlock_irqrestore(plVar4 + 0x11,uVar3);
      uVar3 = param_4;
    }
    else {
      uVar3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// hbeat_val1_show @ 00101fb8 size=88
// signature: undefined hbeat_val1_show(void)
// callers: []
//------------------------------------------------------------

long hbeat_val1_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = -0x16;
  uVar3 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) && (*(char *)(uVar3 + 0x90) != '\0')) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00102ae1,*(undefined8 *)(uVar3 + 0x50));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// hbeat_val1_store @ 00102014 size=304
// signature: undefined hbeat_val1_store(void)
// callers: []
//------------------------------------------------------------

void hbeat_val1_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = 0xffffffffffffffea;
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar4 != (long *)0x0) && (plVar4 < (long *)0xfffffffffffff001)) &&
     ((char)plVar4[0x12] != '\0')) {
    iVar2 = kstrtoull(param_3,0x10,&local_40);
    if (iVar2 == 0) {
      uVar3 = _raw_spin_lock_irqsave(plVar4 + 0x11);
      plVar4[10] = local_40;
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      lVar1 = 0x8c;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x48;
      }
      *(int *)(*plVar4 + lVar1) = (int)local_40;
      lVar1 = 0x90;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x4c;
      }
      *(int *)(*plVar4 + lVar1) = (int)((ulong)local_40 >> 0x20);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      _raw_spin_unlock_irqrestore(plVar4 + 0x11,uVar3);
      uVar3 = param_4;
    }
    else {
      uVar3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// hbeat_mask0_show @ 00102148 size=88
// signature: undefined hbeat_mask0_show(void)
// callers: []
//------------------------------------------------------------

long hbeat_mask0_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = -0x16;
  uVar3 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) && (*(char *)(uVar3 + 0x90) != '\0')) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00102ae1,*(undefined8 *)(uVar3 + 0x58));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// hbeat_mask0_store @ 001021a4 size=304
// signature: undefined hbeat_mask0_store(void)
// callers: []
//------------------------------------------------------------

void hbeat_mask0_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = 0xffffffffffffffea;
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar4 != (long *)0x0) && (plVar4 < (long *)0xfffffffffffff001)) &&
     ((char)plVar4[0x12] != '\0')) {
    iVar2 = kstrtoull(param_3,0x10,&local_40);
    if (iVar2 == 0) {
      uVar3 = _raw_spin_lock_irqsave(plVar4 + 0x11);
      plVar4[0xb] = local_40;
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      lVar1 = 0x94;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x50;
      }
      *(int *)(*plVar4 + lVar1) = (int)local_40;
      lVar1 = 0x98;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x54;
      }
      *(int *)(*plVar4 + lVar1) = (int)((ulong)local_40 >> 0x20);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      _raw_spin_unlock_irqrestore(plVar4 + 0x11,uVar3);
      uVar3 = param_4;
    }
    else {
      uVar3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// hbeat_mask1_show @ 001022d8 size=88
// signature: undefined hbeat_mask1_show(void)
// callers: []
//------------------------------------------------------------

long hbeat_mask1_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = -0x16;
  uVar3 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) && (*(char *)(uVar3 + 0x90) != '\0')) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00102ae1,*(undefined8 *)(uVar3 + 0x60));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// hbeat_mask1_store @ 00102334 size=304
// signature: undefined hbeat_mask1_store(void)
// callers: []
//------------------------------------------------------------

void hbeat_mask1_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = 0xffffffffffffffea;
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar4 != (long *)0x0) && (plVar4 < (long *)0xfffffffffffff001)) &&
     ((char)plVar4[0x12] != '\0')) {
    iVar2 = kstrtoull(param_3,0x10,&local_40);
    if (iVar2 == 0) {
      uVar3 = _raw_spin_lock_irqsave(plVar4 + 0x11);
      plVar4[0xc] = local_40;
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      lVar1 = 0x9c;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x58;
      }
      *(int *)(*plVar4 + lVar1) = (int)local_40;
      lVar1 = 0xa0;
      if (*(char *)((long)plVar4 + 0x93) != '\0') {
        lVar1 = 0x5c;
      }
      *(int *)(*plVar4 + lVar1) = (int)((ulong)local_40 >> 0x20);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      _raw_spin_unlock_irqrestore(plVar4 + 0x11,uVar3);
      uVar3 = param_4;
    }
    else {
      uVar3 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// flushperiod_show @ 00102468 size=104
// signature: undefined flushperiod_show(void)
// callers: []
//------------------------------------------------------------

long flushperiod_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  uVar3 = *(ulong *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) || (*(char *)(uVar3 + 0x8c) == '\0')) {
    _dev_err(param_1,"Invalid param\n");
    lVar2 = -0x16;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%#lx\n",*(undefined4 *)(uVar3 + 0x44));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// flushperiod_store @ 001024d4 size=336
// signature: undefined flushperiod_store(void)
// callers: []
//------------------------------------------------------------

undefined8 flushperiod_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  ulong local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  plVar5 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((plVar5 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar5)) ||
     (*(char *)((long)plVar5 + 0x8c) == '\0')) {
    _dev_err(param_1,"Invalid param\n");
  }
  else {
    plVar1 = plVar5 + 0x11;
    uVar4 = _raw_spin_lock_irqsave(plVar1);
    iVar3 = kstrtoull(param_3,0,&local_50);
    if ((iVar3 == 0) && (local_50 < 0x10000)) {
      if ((local_50 != *(uint *)((long)plVar5 + 0x44)) &&
         (*(int *)((long)plVar5 + 0x44) = (int)local_50, *(char *)((long)plVar5 + 0x91) != '\0')) {
        *(undefined4 *)(*plVar5 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(uint *)(*plVar5 + 0x34) =
             *(uint *)(*plVar5 + 0x34) & 0xfffc0003 | *(int *)((long)plVar5 + 0x44) << 2;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar5 + 0xfb0) = 0;
      }
      _raw_spin_unlock_irqrestore(plVar1,uVar4);
      goto LAB_001025ec;
    }
    _raw_spin_unlock_irqrestore(plVar1,uVar4);
  }
  param_4 = 0xffffffffffffffea;
LAB_001025ec:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00102768 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&csr_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102798 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&csr_driver);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [msm_qdss_csr_enable_bam_to_usb, msr_reset_store, coresight_csr_set_etr_atid, msm_qdss_csr_disable_flush, hbeat_val0_store, flushperiod_store, coresight_csr_hwctrl_set, msr_store, timestamp_show, hbeat_val1_store, msm_qdss_csr_enable_flush, msm_qdss_csr_disable_eth, hbeat_mask0_store, aotime_show, msm_qdss_csr_enable_eth, coresight_csr_get, hbeat_mask1_store, msm_qdss_csr_disable_bam_to_usb, coresight_csr_set_byte_cntr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [msm_qdss_csr_enable_bam_to_usb, msr_reset_store, coresight_csr_set_etr_atid, msm_qdss_csr_disable_flush, hbeat_val0_store, flushperiod_store, coresight_csr_hwctrl_set, msr_store, timestamp_show, hbeat_val1_store, msm_qdss_csr_enable_flush, msm_qdss_csr_disable_eth, hbeat_mask0_store, aotime_show, msm_qdss_csr_enable_eth, coresight_csr_get, hbeat_mask1_store, msm_qdss_csr_disable_bam_to_usb, coresight_csr_set_byte_cntr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104010 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [coresight_csr_set_etr_atid, coresight_csr_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104018 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [of_get_coresight_csr_name, coresight_csr_set_etr_atid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00104020 size=1
// signature: undefined of_property_read_string(void)
// callers: [of_get_coresight_csr_name, coresight_csr_set_etr_atid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msr_store, msr_reset_store, of_get_coresight_csr_name, hbeat_val1_store, hbeat_mask0_store, csr_probe, coresight_csr_set_etr_atid, hbeat_val0_store, hbeat_mask1_store, flushperiod_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104030 size=1
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
// platform_driver_unregister @ 00104038 size=1
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
// coresight_alloc_device_name @ 00104040 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00104048 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104050 size=1
// signature: undefined devm_kmalloc(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00104058 size=1
// signature: undefined devm_clk_get(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00104060 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00104068 size=1
// signature: undefined devm_ioremap(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104078 size=1
// signature: undefined of_find_property(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00104080 size=1
// signature: undefined coresight_register(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_set_csr_ops @ 00104088 size=1
// signature: undefined coresight_set_csr_ops(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_set_csr_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00104090 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [csr_remove, csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104098 size=1
// signature: undefined __list_add_valid(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001040a0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [csr_remove, csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001040a8 size=1
// signature: undefined _dev_info(void)
// callers: [csr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040b0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [csr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_remove_csr_ops @ 001040b8 size=1
// signature: undefined coresight_remove_csr_ops(void)
// callers: [csr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_remove_csr_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 001040c0 size=1
// signature: undefined coresight_unregister(void)
// callers: [csr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001040c8 size=1
// signature: undefined clk_prepare(void)
// callers: [timestamp_show, aotime_show, clk_prepare_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001040d0 size=1
// signature: undefined clk_enable(void)
// callers: [timestamp_show, aotime_show, clk_prepare_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001040d8 size=1
// signature: undefined clk_unprepare(void)
// callers: [msr_reset_store, timestamp_show, aotime_show, clk_prepare_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001040e0 size=1
// signature: undefined _dev_err(void)
// callers: [timestamp_show, flushperiod_show, aotime_show, flushperiod_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001040e8 size=1
// signature: undefined clk_disable(void)
// callers: [msr_reset_store, timestamp_show, aotime_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001040f0 size=1
// signature: undefined scnprintf(void)
// callers: [hbeat_mask0_show, timestamp_show, hbeat_val0_show, flushperiod_show, msr_show, aotime_show, hbeat_val1_show, hbeat_mask1_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 001040f8 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [msr_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00104108 size=1
// signature: undefined kstrtoull(void)
// callers: [msr_reset_store, hbeat_val1_store, hbeat_mask0_store, hbeat_val0_store, hbeat_mask1_store, flushperiod_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



