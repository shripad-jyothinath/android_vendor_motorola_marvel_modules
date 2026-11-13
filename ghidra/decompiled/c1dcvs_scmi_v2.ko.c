// Decompiled by Ghidra 12.2
// Program: c1dcvs_scmi_v2.ko
// Image base: 00100000

//------------------------------------------------------------
// c1dcvs_enable @ 001003cc size=240
// signature: undefined c1dcvs_enable(void)
// callers: []
//------------------------------------------------------------

undefined4 c1dcvs_enable(uint param_1)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (ops < 0xfffffffffffff001) {
    param_1 = param_1 & 1;
    mutex_lock(&c1dcvs_lock);
    local_3c = user_c1dcvs_en;
    if (param_1 <= user_c1dcvs_en) {
      local_3c = param_1;
    }
    kernel_c1dcvs_en = param_1;
    if (*(int *)(*(code **)(ops + 0x10) + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x100478);
      (*pcVar2)();
    }
    uVar3 = (**(code **)(ops + 0x10))(ph,&local_3c,0x433144435653,1,4);
    mutex_unlock(&c1dcvs_lock);
  }
  else {
    uVar3 = 0xfffffdfb;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// scmi_c1dcvs_probe @ 001004c0 size=284
// signature: undefined scmi_c1dcvs_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong scmi_c1dcvs_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  
  uVar2 = get_qcom_scmi_device();
  sdev = uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    pcVar3 = *(code **)(*(long *)(uVar2 + 0x3a0) + 0x18);
    if (*(int *)(pcVar3 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10052c);
      (*pcVar3)();
    }
    ops = (*pcVar3)(uVar2,0x80,&ph);
    if (ops < 0xfffffffffffff001) {
      iVar1 = kobject_init_and_add(c1dcvs_kobj,c1dcvs_settings_ktype,__dev_err,"c1dcvs");
      if (iVar1 < 0) {
        _dev_err(param_1 + 0x10,"failed to init c1 dcvs kobj: %d\n",iVar1);
        kobject_put(c1dcvs_kobj);
      }
      uVar2 = 0;
      kernel_c1dcvs_en = 1;
      user_c1dcvs_en = 1;
    }
    else {
      uVar2 = ops & 0xffffffff;
      ops = 0;
    }
  }
  else if ((int)uVar2 == -0x205) {
    uVar2 = 0xfffffdfb;
  }
  else {
    _dev_err(param_1 + 0x10,"Error getting scmi_dev ret = %d\n",uVar2 & 0xffffffff);
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// attr_show @ 001005e0 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10060c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00100628 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100654);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_enable_c1dcvs @ 00100670 size=192
// signature: undefined show_enable_c1dcvs(void)
// callers: []
//------------------------------------------------------------

long show_enable_c1dcvs(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1006e0);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(ops + 8))(ph,&local_2c,0x433144435653,1,0,4);
  if (-1 < iVar3) {
    iVar3 = scnprintf(param_3,0x1000,&DAT_001016c1,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// store_enable_c1dcvs @ 00100734 size=264
// signature: undefined store_enable_c1dcvs(void)
// callers: []
//------------------------------------------------------------

void store_enable_c1dcvs(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  iVar3 = kstrtouint(param_3,10,&local_40);
  if (iVar3 < 0) {
    lVar4 = (long)iVar3;
  }
  else {
    mutex_lock(&c1dcvs_lock);
    local_3c = local_40;
    if (kernel_c1dcvs_en <= local_40) {
      local_3c = kernel_c1dcvs_en;
    }
    user_c1dcvs_en = local_40;
    if (*(int *)(*(code **)(ops + 0x10) + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x1007e8);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(ops + 0x10))(ph,&local_3c,0x433144435653,1,4);
    mutex_unlock(&c1dcvs_lock);
    lVar4 = (long)iVar3;
    if (-1 < iVar3) {
      lVar4 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// show_enable_trace @ 00100840 size=192
// signature: undefined show_enable_trace(void)
// callers: []
//------------------------------------------------------------

long show_enable_trace(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1008b0);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(ops + 8))(ph,&local_2c,0x433144435653,2,0,4);
  if (-1 < iVar3) {
    iVar3 = scnprintf(param_3,0x1000,&DAT_001016c1,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// store_enable_trace @ 00100904 size=196
// signature: undefined store_enable_trace(void)
// callers: []
//------------------------------------------------------------

void store_enable_trace(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    lVar4 = (long)iVar3;
  }
  else {
    if (*(int *)(*(code **)(ops + 0x10) + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100984);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(ops + 0x10))(ph,&local_2c,0x433144435653,2,4);
    lVar4 = (long)iVar3;
    if (-1 < iVar3) {
      lVar4 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// show_ipc_thresh @ 001009cc size=348
// signature: undefined show_ipc_thresh(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long show_ipc_thresh(undefined8 param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
  lVar5 = __kmalloc((uVar4 & 0xffffffff) << 2,0xdc0);
  if (lVar5 == 0) {
    lVar5 = -0xc;
  }
  else {
    uVar4 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
    if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100a6c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(ops + 8))(ph,lVar5,0x433144435653,3,0,(uVar4 & 0xffffffff) << 2);
    if (-1 < iVar2) {
      uVar7 = 0;
      iVar6 = 0;
      while ((uVar3 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids), uVar7 < uVar3 &&
             (*(int *)(lVar5 + (long)(int)uVar7 * 4) != 0))) {
        iVar2 = scnprintf(param_3 + iVar6,0x1000 - (long)iVar6,&DAT_0010177d);
        uVar7 = uVar7 + 1;
        iVar6 = iVar2 + iVar6;
      }
      iVar2 = scnprintf(param_3 + iVar6,0x1000 - (long)iVar6,&DAT_0010179c);
      iVar2 = iVar2 + iVar6;
    }
    kfree(lVar5);
    lVar5 = (long)iVar2;
  }
  return lVar5;
}



//------------------------------------------------------------
// store_ipc_thresh @ 00100b2c size=352
// signature: undefined store_ipc_thresh(void)
// callers: []
//------------------------------------------------------------

void store_ipc_thresh(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  ulong uVar8;
  char *local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  pcVar5 = (char *)kstrdup(param_3,0xcc0);
  local_40 = 0;
  local_48 = pcVar5;
  pcVar6 = strsep(&local_48," ");
  if (pcVar6 == (char *)0x0) {
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    iVar4 = kstrtouint(pcVar6,10,&local_40);
    if (iVar4 < 0) {
LAB_00100bc8:
      _printk(&DAT_0010175d,iVar4);
      goto LAB_00100c48;
    }
    pcVar6 = strsep(&local_48," ");
    if (pcVar6 != (char *)0x0) {
      iVar4 = kstrtouint(pcVar6,10,(ulong)&local_40 | 4);
      if (iVar4 < 0) goto LAB_00100bc8;
      strsep(&local_48," ");
    }
    uVar8 = local_40 & 0xffffffff;
    uVar7 = local_40._4_4_;
  }
  _printk(&DAT_001016c6,uVar7,uVar8);
  if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c40);
    (*pcVar3)();
  }
  iVar4 = (*(code *)*ops)(ph,&local_40,0x433144435653,3,8);
LAB_00100c48:
  kfree(pcVar5);
  lVar2 = sp_el0;
  lVar1 = (long)iVar4;
  if (-1 < iVar4) {
    lVar1 = param_4;
  }
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1);
  }
  return;
}



//------------------------------------------------------------
// show_efreq_thresh @ 00100c90 size=348
// signature: undefined show_efreq_thresh(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long show_efreq_thresh(undefined8 param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
  lVar5 = __kmalloc((uVar4 & 0xffffffff) << 2,0xdc0);
  if (lVar5 == 0) {
    lVar5 = -0xc;
  }
  else {
    uVar4 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
    if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100d30);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(ops + 8))(ph,lVar5,0x433144435653,4,0,(uVar4 & 0xffffffff) << 2);
    if (-1 < iVar2) {
      uVar7 = 0;
      iVar6 = 0;
      while ((uVar3 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids), uVar7 < uVar3 &&
             (*(int *)(lVar5 + (long)(int)uVar7 * 4) != 0))) {
        iVar2 = scnprintf(param_3 + iVar6,0x1000 - (long)iVar6,&DAT_0010177d);
        uVar7 = uVar7 + 1;
        iVar6 = iVar2 + iVar6;
      }
      iVar2 = scnprintf(param_3 + iVar6,0x1000 - (long)iVar6,&DAT_0010179c);
      iVar2 = iVar2 + iVar6;
    }
    kfree(lVar5);
    lVar5 = (long)iVar2;
  }
  return lVar5;
}



//------------------------------------------------------------
// store_efreq_thresh @ 00100df0 size=352
// signature: undefined store_efreq_thresh(void)
// callers: []
//------------------------------------------------------------

void store_efreq_thresh(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 uVar7;
  ulong uVar8;
  char *local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  pcVar5 = (char *)kstrdup(param_3,0xcc0);
  local_40 = 0;
  local_48 = pcVar5;
  pcVar6 = strsep(&local_48," ");
  if (pcVar6 == (char *)0x0) {
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    iVar4 = kstrtouint(pcVar6,10,&local_40);
    if (iVar4 < 0) {
LAB_00100e8c:
      _printk(&DAT_0010175d,iVar4);
      goto LAB_00100f0c;
    }
    pcVar6 = strsep(&local_48," ");
    if (pcVar6 != (char *)0x0) {
      iVar4 = kstrtouint(pcVar6,10,(ulong)&local_40 | 4);
      if (iVar4 < 0) goto LAB_00100e8c;
      strsep(&local_48," ");
    }
    uVar8 = local_40 & 0xffffffff;
    uVar7 = local_40._4_4_;
  }
  _printk(&DAT_001016c6,uVar7,uVar8);
  if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100f04);
    (*pcVar3)();
  }
  iVar4 = (*(code *)*ops)(ph,&local_40,0x433144435653,4,8);
LAB_00100f0c:
  kfree(pcVar5);
  lVar2 = sp_el0;
  lVar1 = (long)iVar4;
  if (-1 < iVar4) {
    lVar1 = param_4;
  }
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1);
  }
  return;
}



//------------------------------------------------------------
// show_hysteresis @ 00100f54 size=192
// signature: undefined show_hysteresis(void)
// callers: []
//------------------------------------------------------------

long show_hysteresis(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100fc4);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(ops + 8))(ph,&local_2c,0x433144435653,5,0,4);
  if (-1 < iVar3) {
    iVar3 = scnprintf(param_3,0x1000,&DAT_001016c1,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// store_hysteresis @ 00101018 size=196
// signature: undefined store_hysteresis(void)
// callers: []
//------------------------------------------------------------

void store_hysteresis(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    lVar4 = (long)iVar3;
  }
  else {
    if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101098);
      (*pcVar2)();
    }
    iVar3 = (*(code *)*ops)(ph,&local_2c,0x433144435653,5,4);
    lVar4 = (long)iVar3;
    if (-1 < iVar3) {
      lVar4 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// show_c1dcvs_opt_mode @ 001010e0 size=192
// signature: undefined show_c1dcvs_opt_mode(void)
// callers: []
//------------------------------------------------------------

long show_c1dcvs_opt_mode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101150);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(ops + 8))(ph,&local_2c,0x433144435653,6,0,4);
  if (-1 < iVar3) {
    iVar3 = scnprintf(param_3,0x1000,&DAT_001016c1,local_2c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// store_c1dcvs_opt_mode @ 001011a4 size=196
// signature: undefined store_c1dcvs_opt_mode(void)
// callers: []
//------------------------------------------------------------

void store_c1dcvs_opt_mode(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    lVar4 = (long)iVar3;
  }
  else {
    if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101224);
      (*pcVar2)();
    }
    iVar3 = (*(code *)*ops)(ph,&local_2c,0x433144435653,6,4);
    lVar4 = (long)iVar3;
    if (-1 < iVar3) {
      lVar4 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0010127c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&c1dcvs_v2_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001012ac size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&c1dcvs_v2_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [store_enable_c1dcvs, c1dcvs_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103008 size=1
// signature: undefined mutex_unlock(void)
// callers: [store_enable_c1dcvs, c1dcvs_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [store_enable_trace, store_c1dcvs_opt_mode, store_hysteresis, show_enable_c1dcvs, store_efreq_thresh, show_c1dcvs_opt_mode, store_enable_c1dcvs, show_hysteresis, c1dcvs_enable, show_enable_trace, store_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103018 size=1
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
// platform_driver_unregister @ 00103020 size=1
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
// get_qcom_scmi_device @ 00103028 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [scmi_c1dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00103038 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [scmi_c1dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103040 size=1
// signature: undefined _dev_err(void)
// callers: [scmi_c1dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00103048 size=1
// signature: undefined kobject_put(void)
// callers: [scmi_c1dcvs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103050 size=1
// signature: undefined scnprintf(void)
// callers: [show_enable_c1dcvs, show_c1dcvs_opt_mode, show_hysteresis, show_efreq_thresh, show_enable_trace, show_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00103058 size=1
// signature: undefined kstrtouint(void)
// callers: [store_enable_trace, store_c1dcvs_opt_mode, store_hysteresis, store_efreq_thresh, store_enable_c1dcvs, store_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00103070 size=1
// signature: undefined __bitmap_weight(void)
// callers: [show_efreq_thresh, show_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103078 size=1
// signature: undefined __kmalloc(void)
// callers: [show_efreq_thresh, show_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103080 size=1
// signature: undefined kfree(void)
// callers: [store_efreq_thresh, show_efreq_thresh, show_ipc_thresh, store_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00103088 size=1
// signature: undefined kstrdup(void)
// callers: [store_efreq_thresh, store_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00103090 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [store_efreq_thresh, store_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103098 size=1
// signature: undefined _printk(void)
// callers: [store_efreq_thresh, store_ipc_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



