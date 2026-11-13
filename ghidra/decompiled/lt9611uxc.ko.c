// Decompiled by Ghidra 12.2
// Program: lt9611uxc.ko
// Image base: 00100000

//------------------------------------------------------------
// lt9611uxc_hpd_work @ 00100854 size=340
// signature: undefined lt9611uxc_hpd_work(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_hpd_work(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  int *piVar6;
  undefined8 *local_a0;
  undefined8 *local_98;
  char *pcStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((param_1 != 0xa38) && (*(long *)(param_1 + -0x748) != 0)) &&
     (pcVar4 = *(code **)(*(long *)(param_1 + -0x748) + 0x10), pcVar4 != (code *)0x0)) {
    piVar6 = (int *)(param_1 + -0x818);
    lVar5 = *(long *)(param_1 + -0x8d8);
    iVar1 = *piVar6;
    if (*(int *)(pcVar4 + -4) != -0x2edbc73) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1008d4);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)((long *)(param_1 + -0x8d8),1);
    *piVar6 = iVar2;
    if ((iVar1 != iVar2) || (*(long *)(param_1 + -0x910) == 0)) {
      if (iVar2 != 1) {
        *(undefined1 *)(param_1 + 0x248) = 0;
        kfree(*(undefined8 *)(param_1 + -0x910));
        *(undefined8 *)(param_1 + -0x910) = 0;
      }
      scnprintf(&local_58,0x20,"name=%s",*(undefined8 *)(param_1 + -0x878));
      uVar3 = drm_get_connector_status_name(*piVar6);
      scnprintf(&local_78,0x20,"status=%s",uVar3);
      local_88 = 0;
      uStack_80 = 0;
      pcStack_90 = "HOTPLUG=1";
      local_a0 = &local_58;
      local_98 = &local_78;
      kobject_uevent_env(*(undefined8 *)(*(long *)(lVar5 + 0x40) + 8),2,&local_a0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_config @ 001009ac size=260
// signature: undefined lt9611uxc_config(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_config(long param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  undefined8 local_68;
  undefined8 *local_60;
  long local_58;
  
  lVar3 = sp_el0;
  lVar5 = 0;
  local_58 = *(long *)(lVar3 + 0x638);
  do {
    uVar2 = *(undefined2 *)((long)&DAT_001061c8 + lVar5);
    uVar1 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
    *(undefined8 *)(param_1 + 0xb80) = 0;
    *(undefined8 *)(param_1 + 0xb88) = 0;
    *(undefined8 *)(param_1 + 0xb90) = 0;
    *(undefined8 *)(param_1 + 0xb98) = 0;
    *(undefined8 *)(param_1 + 0xba0) = 0;
    *(undefined8 *)(param_1 + 0xba8) = 0;
    *(undefined8 *)(param_1 + 0xbb0) = 0;
    *(undefined8 *)(param_1 + 3000) = 0;
    *(undefined8 *)(param_1 + 0xbc0) = 0;
    *(undefined8 *)(param_1 + 0xbc8) = 0;
    *(undefined8 *)(param_1 + 0xbd0) = 0;
    *(undefined8 *)(param_1 + 0xbd8) = 0;
    *(undefined8 *)(param_1 + 0xbe0) = 0;
    *(undefined8 *)(param_1 + 0xbe8) = 0;
    *(undefined8 *)(param_1 + 0xbf0) = 0;
    *(undefined8 *)(param_1 + 0xbf8) = 0;
    *(undefined2 *)(param_1 + 0xb80) = uVar2;
    local_68 = (ulong)CONCAT24(2,(uint)uVar1);
    local_60 = (undefined8 *)(param_1 + 0xb80);
    iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_68,1);
    if (iVar4 < 1) {
      _printk(&DAT_00105b45,"lt9611uxc_write_byte");
    }
    lVar5 = lVar5 + 2;
  } while (lVar5 != 0xe);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_get_version @ 00100ab4 size=936
// signature: undefined lt9611uxc_get_version(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

undefined1 lt9611uxc_get_version(long param_1)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  long lVar5;
  undefined1 uVar6;
  undefined2 local_58;
  undefined6 uStack_56;
  undefined8 *local_50;
  undefined8 local_48;
  undefined1 *local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  _local_58 = CONCAT62(0x20000,uVar2);
  local_50 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_58,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x1ee;
  _local_58 = CONCAT62(0x20000,uVar2);
  local_50 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_58,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0xb0ff;
  _local_58 = CONCAT62(0x20000,uVar2);
  local_50 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_58,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar5 = *(long *)(param_1 + 0x918);
  uVar2 = *(undefined2 *)(lVar5 + 2);
  uVar3 = *(undefined2 *)(lVar5 + 2);
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xc78) = 0;
  *(undefined8 *)(param_1 + 0xc70) = 0;
  *(undefined8 *)(param_1 + 0xc68) = 0;
  *(undefined8 *)(param_1 + 0xc60) = 0;
  *(undefined8 *)(param_1 + 0xc58) = 0;
  *(undefined8 *)(param_1 + 0xc50) = 0;
  *(undefined8 *)(param_1 + 0xc48) = 0;
  *(undefined8 *)(param_1 + 0xc40) = 0;
  *(undefined8 *)(param_1 + 0xc38) = 0;
  *(undefined8 *)(param_1 + 0xc30) = 0;
  *(undefined8 *)(param_1 + 0xc28) = 0;
  *(undefined8 *)(param_1 + 0xc20) = 0;
  *(undefined8 *)(param_1 + 0xc18) = 0;
  *(undefined8 *)(param_1 + 0xc10) = 0;
  *(undefined8 *)(param_1 + 0xc08) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x21;
  *(undefined8 *)(param_1 + 0xc00) = 0;
  _local_58 = CONCAT62(0x10000,uVar2);
  local_48 = (ulong)CONCAT42(0x10001,uVar3);
  local_50 = puVar1;
  local_40 = (undefined1 *)(param_1 + 0xc00);
  iVar4 = i2c_transfer(*(undefined8 *)(lVar5 + 0x18),&local_58,2);
  if (iVar4 == 2) {
    uVar6 = *(undefined1 *)(param_1 + 0xc00);
    _printk(&DAT_0010529c,"lt9611uxc_get_version",uVar6);
  }
  else {
    _printk(&DAT_00106009,"lt9611uxc_read");
    _printk(&DAT_00105e6e,"lt9611uxc_get_version");
    uVar6 = 0;
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  _local_58 = CONCAT62(0x20000,uVar2);
  local_50 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_58,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0xee;
  _local_58 = CONCAT62(0x20000,uVar2);
  local_50 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_58,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  msleep(0x32);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// lt9611uxc_flash_write_en @ 00100e60 size=816
// signature: undefined lt9611uxc_flash_write_en(void)
// callers: [lt9611uxc_flash_write_config]
//------------------------------------------------------------

void lt9611uxc_flash_write_en(long param_1)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  undefined8 local_48;
  undefined8 *local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x81ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0xbf08;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  msleep(0x14);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0xff08;
  local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  msleep(0x14);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x45a;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x5a;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_block_erase @ 00101194 size=288
// signature: undefined lt9611uxc_block_erase(void)
// callers: [lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

void lt9611uxc_block_erase(long param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  undefined8 local_68;
  undefined8 *local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  _printk(&DAT_00105ab4,"lt9611uxc_block_erase");
  lVar4 = 0;
  do {
    uVar2 = *(undefined2 *)((long)&DAT_001061d6 + lVar4);
    uVar1 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
    *(undefined8 *)(param_1 + 0xb80) = 0;
    *(undefined8 *)(param_1 + 0xb88) = 0;
    *(undefined8 *)(param_1 + 0xb90) = 0;
    *(undefined8 *)(param_1 + 0xb98) = 0;
    *(undefined8 *)(param_1 + 0xba0) = 0;
    *(undefined8 *)(param_1 + 0xba8) = 0;
    *(undefined8 *)(param_1 + 0xbb0) = 0;
    *(undefined8 *)(param_1 + 3000) = 0;
    *(undefined8 *)(param_1 + 0xbc0) = 0;
    *(undefined8 *)(param_1 + 0xbc8) = 0;
    *(undefined8 *)(param_1 + 0xbd0) = 0;
    *(undefined8 *)(param_1 + 0xbd8) = 0;
    *(undefined8 *)(param_1 + 0xbe0) = 0;
    *(undefined8 *)(param_1 + 0xbe8) = 0;
    *(undefined8 *)(param_1 + 0xbf0) = 0;
    *(undefined8 *)(param_1 + 0xbf8) = 0;
    *(undefined2 *)(param_1 + 0xb80) = uVar2;
    local_68 = (ulong)CONCAT24(2,(uint)uVar1);
    local_60 = (undefined8 *)(param_1 + 0xb80);
    iVar3 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_68,1);
    if (iVar3 < 1) {
      _printk(&DAT_00105b45,"lt9611uxc_write_byte");
    }
    lVar4 = lVar4 + 2;
  } while (lVar4 != 0x12);
  msleep(3000);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_flash_read_addr_set @ 001012b8 size=340
// signature: undefined lt9611uxc_flash_read_addr_set(void)
// callers: [lt9611uxc_fw_read_back]
//------------------------------------------------------------

void lt9611uxc_flash_read_addr_set(long param_1,undefined8 param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  undefined8 local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined2 local_6c;
  undefined1 local_6a;
  undefined1 local_69;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  undefined1 local_65;
  undefined4 local_64;
  undefined2 local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  lVar4 = 0;
  local_70 = 0xa05a5f5e;
  local_6c = 0x805a;
  local_69 = (char)((ulong)param_2 >> 0x10);
  local_68 = 0x5c;
  local_66 = 0x5d;
  local_6a = 0x5b;
  local_67 = (char)((ulong)param_2 >> 8);
  local_65 = (char)param_2;
  local_64 = 0x805a905a;
  local_60 = 0x2158;
  do {
    uVar2 = *(undefined2 *)((long)&local_70 + lVar4);
    uVar1 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
    *(undefined8 *)(param_1 + 0xb80) = 0;
    *(undefined8 *)(param_1 + 0xb88) = 0;
    *(undefined8 *)(param_1 + 0xb90) = 0;
    *(undefined8 *)(param_1 + 0xb98) = 0;
    *(undefined8 *)(param_1 + 0xba0) = 0;
    *(undefined8 *)(param_1 + 0xba8) = 0;
    *(undefined8 *)(param_1 + 0xbb0) = 0;
    *(undefined8 *)(param_1 + 3000) = 0;
    *(undefined8 *)(param_1 + 0xbc0) = 0;
    *(undefined8 *)(param_1 + 0xbc8) = 0;
    *(undefined8 *)(param_1 + 0xbd0) = 0;
    *(undefined8 *)(param_1 + 0xbd8) = 0;
    *(undefined8 *)(param_1 + 0xbe0) = 0;
    *(undefined8 *)(param_1 + 0xbe8) = 0;
    *(undefined8 *)(param_1 + 0xbf0) = 0;
    *(undefined8 *)(param_1 + 0xbf8) = 0;
    *(undefined2 *)(param_1 + 0xb80) = uVar2;
    local_80 = (ulong)CONCAT24(2,(uint)uVar1);
    local_78 = (undefined8 *)(param_1 + 0xb80);
    iVar3 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_80,1);
    if (iVar3 < 1) {
      _printk(&DAT_00105b45,"lt9611uxc_write_byte");
    }
    lVar4 = lVar4 + 2;
  } while (lVar4 != 0x12);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_fw_read_back @ 00101410 size=912
// signature: undefined lt9611uxc_fw_read_back(void)
// callers: [lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

void lt9611uxc_fw_read_back(long param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  int iVar11;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 *local_80;
  undefined8 local_78;
  undefined8 *local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  uVar4 = param_3 + 0x1f;
  if (-1 < (int)param_3) {
    uVar4 = param_3;
  }
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar5 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  iVar11 = (int)uVar4 >> 5;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  if ((param_3 & 0x1f) != 0) {
    iVar11 = iVar11 + 1;
  }
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  local_88 = CONCAT62(0x20000,uVar5);
  local_80 = puVar1;
  iVar8 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_88,1);
  if (iVar8 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar6 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x1ee;
  local_88._0_4_ = (uint)uVar6;
  local_88._0_6_ = CONCAT24(2,(uint)local_88);
  local_88 = (ulong)(uint6)local_88;
  local_80 = puVar1;
  iVar8 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_88,1);
  if (iVar8 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar6 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x845a;
  local_88._0_4_ = (uint)uVar6;
  local_88._0_6_ = CONCAT24(2,(uint)local_88);
  local_88 = (ulong)(uint6)local_88;
  local_80 = puVar1;
  iVar8 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_88,1);
  if (iVar8 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar6 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x805a;
  local_88._0_4_ = (uint)uVar6;
  local_88._0_6_ = CONCAT24(2,(uint)local_88);
  local_88 = (ulong)(uint6)local_88;
  local_80 = puVar1;
  iVar8 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_88,1);
  if (iVar8 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  if (0 < iVar11) {
    uVar10 = 0;
    puVar2 = (undefined8 *)(param_1 + 0xc00);
    do {
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      lt9611uxc_flash_read_addr_set(param_1,uVar10 & 0xffffffff);
      lVar9 = *(long *)(param_1 + 0x918);
      uVar5 = *(undefined2 *)(lVar9 + 2);
      uVar7 = *(undefined2 *)(lVar9 + 2);
      *(undefined8 *)(param_1 + 0xbf0) = 0;
      *(undefined8 *)(param_1 + 0xbf8) = 0;
      *(undefined8 *)(param_1 + 0xbe0) = 0;
      *(undefined8 *)(param_1 + 0xbe8) = 0;
      *(undefined8 *)(param_1 + 0xbd0) = 0;
      *(undefined8 *)(param_1 + 0xbd8) = 0;
      *(undefined8 *)(param_1 + 0xbc0) = 0;
      *(undefined8 *)(param_1 + 0xbc8) = 0;
      *(undefined8 *)(param_1 + 0xbb0) = 0;
      *(undefined8 *)(param_1 + 3000) = 0;
      *(undefined8 *)(param_1 + 0xba0) = 0;
      *(undefined8 *)(param_1 + 0xba8) = 0;
      *(undefined8 *)(param_1 + 0xb90) = 0;
      *(undefined8 *)(param_1 + 0xb98) = 0;
      *puVar1 = 0;
      *(undefined8 *)(param_1 + 0xb88) = 0;
      *(undefined8 *)(param_1 + 0xc70) = 0;
      *(undefined8 *)(param_1 + 0xc78) = 0;
      *(undefined8 *)(param_1 + 0xc60) = 0;
      *(undefined8 *)(param_1 + 0xc68) = 0;
      *(undefined8 *)(param_1 + 0xc50) = 0;
      *(undefined8 *)(param_1 + 0xc58) = 0;
      *(undefined8 *)(param_1 + 0xc40) = 0;
      *(undefined8 *)(param_1 + 0xc48) = 0;
      *(undefined8 *)(param_1 + 0xc30) = 0;
      *(undefined8 *)(param_1 + 0xc38) = 0;
      *(undefined8 *)(param_1 + 0xc20) = 0;
      *(undefined8 *)(param_1 + 0xc28) = 0;
      *(undefined8 *)(param_1 + 0xc10) = 0;
      *(undefined8 *)(param_1 + 0xc18) = 0;
      *puVar2 = 0;
      *(undefined8 *)(param_1 + 0xc08) = 0;
      *(undefined1 *)(param_1 + 0xb80) = 0x5f;
      local_88 = CONCAT62(0x10000,uVar5);
      local_78 = (ulong)CONCAT42(0x200001,uVar7);
      local_80 = puVar1;
      local_70 = puVar2;
      iVar8 = i2c_transfer(*(undefined8 *)(lVar9 + 0x18),&local_88,2);
      if (iVar8 == 2) {
        local_a8 = *puVar2;
        uStack_a0 = *(undefined8 *)(param_1 + 0xc08);
        local_98 = *(undefined8 *)(param_1 + 0xc10);
        uStack_90 = *(undefined8 *)(param_1 + 0xc18);
      }
      else {
        _printk(&DAT_00106009,"lt9611uxc_read");
      }
      puVar3 = (undefined8 *)(param_2 + uVar10);
      uVar10 = uVar10 + 0x20;
      iVar11 = iVar11 + -1;
      *puVar3 = local_a8;
      puVar3[1] = uStack_a0;
      puVar3[2] = local_98;
      puVar3[3] = uStack_90;
    } while (iVar11 != 0);
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_flash_write_config @ 001017a4 size=692
// signature: undefined lt9611uxc_flash_write_config(void)
// callers: [lt9611uxc_firmware_write]
//------------------------------------------------------------

void lt9611uxc_flash_write_config(long param_1)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  undefined8 local_48;
  undefined8 *local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lt9611uxc_flash_write_en();
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0xdf5e;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x205a;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x5a;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x2158;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_flash_write_addr_set @ 00101a5c size=716
// signature: undefined lt9611uxc_flash_write_addr_set(void)
// callers: [lt9611uxc_firmware_write]
//------------------------------------------------------------

void lt9611uxc_flash_write_addr_set(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  undefined8 local_48;
  undefined8 *local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x5b;
  *(char *)(param_1 + 0xb81) = (char)(param_2 >> 0x10);
  local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x5c;
  *(char *)(param_1 + 0xb81) = (char)((param_2 & 0xffffffff) >> 8);
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x5d;
  *(char *)(param_1 + 0xb81) = (char)(param_2 & 0xffffffff);
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x105a;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar3 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0x5a;
  local_48._0_4_ = (uint)uVar3;
  local_48._0_6_ = CONCAT24(2,(uint)local_48);
  local_48 = (ulong)(uint6)local_48;
  local_40 = puVar1;
  iVar5 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar5 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_firmware_write @ 00101d2c size=592
// signature: undefined lt9611uxc_firmware_write(void)
// callers: [lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

void lt9611uxc_firmware_write(long param_1,void *param_2,int param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  uint uVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  iVar2 = param_3 + 0x1f;
  if (-1 < param_3) {
    iVar2 = param_3;
  }
  local_68 = *(long *)(lVar8 + 0x638);
  uVar7 = param_3 % 0x20;
  if (param_3 < 0x20) {
    uVar11 = 0;
  }
  else {
    uVar11 = 0;
    iVar10 = iVar2 >> 5;
    do {
      puVar1 = (undefined8 *)((long)param_2 + uVar11);
      lt9611uxc_flash_write_config(param_1);
      uVar6 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
      *(undefined1 *)(param_1 + 0xb80) = 0x59;
      uVar4 = puVar1[3];
      uVar3 = *puVar1;
      uVar5 = puVar1[1];
      local_88 = CONCAT62(0x210000,uVar6);
      *(undefined8 *)(param_1 + 0xb91) = puVar1[2];
      *(undefined8 *)(param_1 + 0xb99) = uVar4;
      *(undefined8 *)(param_1 + 0xb81) = uVar3;
      *(undefined8 *)(param_1 + 0xb89) = uVar5;
      local_80 = param_1 + 0xb80;
      iVar9 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_88,1);
      if (iVar9 < 1) {
        _printk(&DAT_00105b45,"lt9611uxc_write");
      }
      lt9611uxc_flash_write_addr_set(param_1,uVar11 & 0xffffffff);
      msleep(0x14);
      uVar11 = uVar11 + 0x20;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    param_2 = (void *)((long)param_2 + uVar11);
  }
  if (0 < (int)uVar7) {
    local_78 = 0xffffffffffffffff;
    uStack_70 = 0xffffffffffffffff;
    local_88 = 0xffffffffffffffff;
    local_80 = -1;
    if (0x20 < uVar7) {
      fortify_panic("memcpy");
      goto LAB_00101f78;
    }
    memcpy(&local_88,param_2,(ulong)uVar7);
    lt9611uxc_flash_write_config(param_1);
    local_90 = param_1 + 0xb80;
    uVar6 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
    *(undefined1 *)(param_1 + 0xb80) = 0x59;
    *(undefined8 *)(param_1 + 0xb81) = local_88;
    *(long *)(param_1 + 0xb89) = local_80;
    local_98 = CONCAT62(0x210000,uVar6);
    *(undefined8 *)(param_1 + 0xb91) = local_78;
    *(undefined8 *)(param_1 + 0xb99) = uStack_70;
    iVar10 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_98,1);
    if (iVar10 < 1) {
      _printk(&DAT_00105b45,"lt9611uxc_write");
    }
    lt9611uxc_flash_write_addr_set(param_1,uVar11 & 0xffffffff);
    msleep(0x14);
  }
  msleep(0x14);
  _printk(&DAT_0010544c,"lt9611uxc_firmware_write",param_3,iVar2 >> 5,(ulong)uVar7);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) == local_68) {
    return;
  }
LAB_00101f78:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// lt9611uxc_firmware_upgrade @ 00101f80 size=472
// signature: undefined lt9611uxc_firmware_upgrade(void)
// callers: [lt9611uxc_firmware_cb]
//------------------------------------------------------------

void lt9611uxc_firmware_upgrade(long param_1,ulong *param_2)

{
  undefined *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  void *__s2;
  ulong uVar5;
  long lVar6;
  undefined8 local_78;
  undefined8 *local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  uVar5 = *param_2;
  _printk(&DAT_0010516c,"lt9611uxc_firmware_upgrade",uVar5 & 0xffffffff);
  __s2 = (void *)__kmalloc((long)((uVar5 << 0x20) + 0x1f00000000) >> 0x20 & 0xffffffffffffffe0,0xdc0
                          );
  if (__s2 != (void *)0x0) {
    lVar6 = 0;
    *(undefined4 *)(param_1 + 0xc88) = 1;
    do {
      uVar3 = *(undefined2 *)((long)&DAT_001061c8 + lVar6);
      uVar2 = *(ushort *)(*(long *)(param_1 + 0x918) + 2);
      *(undefined8 *)(param_1 + 0xb80) = 0;
      *(undefined8 *)(param_1 + 0xb88) = 0;
      *(undefined8 *)(param_1 + 0xb90) = 0;
      *(undefined8 *)(param_1 + 0xb98) = 0;
      *(undefined8 *)(param_1 + 0xba0) = 0;
      *(undefined8 *)(param_1 + 0xba8) = 0;
      *(undefined8 *)(param_1 + 0xbb0) = 0;
      *(undefined8 *)(param_1 + 3000) = 0;
      *(undefined8 *)(param_1 + 0xbc0) = 0;
      *(undefined8 *)(param_1 + 0xbc8) = 0;
      *(undefined8 *)(param_1 + 0xbd0) = 0;
      *(undefined8 *)(param_1 + 0xbd8) = 0;
      *(undefined8 *)(param_1 + 0xbe0) = 0;
      *(undefined8 *)(param_1 + 0xbe8) = 0;
      *(undefined8 *)(param_1 + 0xbf0) = 0;
      *(undefined8 *)(param_1 + 0xbf8) = 0;
      *(undefined2 *)(param_1 + 0xb80) = uVar3;
      local_78 = (ulong)CONCAT24(2,(uint)uVar2);
      local_70 = (undefined8 *)(param_1 + 0xb80);
      iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_78,1);
      if (iVar4 < 1) {
        _printk(&DAT_00105b45,"lt9611uxc_write_byte");
      }
      lVar6 = lVar6 + 2;
    } while (lVar6 != 0xe);
    lt9611uxc_block_erase(param_1);
    lt9611uxc_block_erase(param_1);
    lt9611uxc_firmware_write(param_1,param_2[1],uVar5 & 0xffffffff);
    msleep(0x14);
    lt9611uxc_fw_read_back(param_1,__s2,uVar5 & 0xffffffff);
    iVar4 = bcmp((void *)param_2[1],__s2,(long)(uVar5 << 0x20) >> 0x20);
    puVar1 = &DAT_0010579f;
    if (iVar4 != 0) {
      puVar1 = &DAT_00105648;
    }
    *(uint *)(param_1 + 0xc88) = (uint)(iVar4 != 0) << 1;
    _printk(puVar1,"lt9611uxc_firmware_upgrade");
    kfree(__s2);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_edid_en @ 0010215c size=344
// signature: undefined lt9611uxc_edid_en(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

void lt9611uxc_edid_en(long param_1)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  undefined2 local_48;
  undefined6 uStack_46;
  undefined8 *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0xb0ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  _local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x100b;
  _local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_probe @ 001022b8 size=4596
// signature: undefined lt9611uxc_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong lt9611uxc_probe(long param_1)

{
  long lVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  char cVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  ulong uVar13;
  long *plVar14;
  long lVar15;
  undefined *puVar16;
  char *pcVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  code *pcVar21;
  long lVar22;
  uint uVar23;
  undefined8 uVar24;
  ulong *puVar25;
  ulong *puVar26;
  char *pcVar27;
  long *plVar28;
  long *plVar29;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  char *local_b8;
  long *local_b0;
  undefined8 local_a8;
  long *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if ((param_1 == 0) || (*(long *)(param_1 + 0x308) == 0)) {
    _printk(&DAT_001057c7,"lt9611uxc_probe");
    pcVar27 = (char *)0xffffffea;
    goto LAB_00102310;
  }
  pcVar21 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
  if (*(int *)(pcVar21 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar21 = (code *)SoftwareBreakpoint(0x8228,0x102370);
    (*pcVar21)();
  }
  uVar13 = (*pcVar21)();
  if ((uVar13 & 1) == 0) {
    _printk(&DAT_00105ebd,"lt9611uxc_probe");
    pcVar27 = (char *)0xffffffed;
    goto LAB_00102310;
  }
  lVar1 = param_1 + 0x20;
  _printk(&DAT_001053c1,"lt9611uxc_probe","lt9611uxc_probe");
  plVar14 = (long *)devm_kmalloc(lVar1,0xc90,0xdc0);
  if (plVar14 == (long *)0x0) {
    pcVar27 = (char *)0xfffffff4;
    goto LAB_00102310;
  }
  uVar24 = *(undefined8 *)(param_1 + 0x308);
  lVar15 = of_graph_get_endpoint_by_regs(uVar24,0,0);
  if (lVar15 == 0) {
    puVar16 = &DAT_00105dcb;
LAB_00102408:
    _printk(puVar16,"lt9611uxc_parse_dt");
    pcVar27 = (char *)0xffffffed;
LAB_00102418:
    puVar16 = &DAT_0010587a;
  }
  else {
    lVar15 = of_graph_get_remote_port_parent();
    plVar14[0x23] = lVar15;
    if (lVar15 == 0) {
      puVar16 = &DAT_0010548d;
      goto LAB_00102408;
    }
    uVar8 = of_get_named_gpio_flags(uVar24,"lt,irq-gpio",0,0);
    pcVar27 = (char *)0x0;
    *(uint *)((long)plVar14 + 0x8f4) = uVar8;
    if (0x1ff < uVar8) {
      _printk(&DAT_0010612f,"lt9611uxc_parse_dt");
      pcVar27 = (char *)0xffffffea;
    }
    uVar8 = of_get_named_gpio_flags(uVar24,"lt,reset-gpio",0,0);
    *(uint *)(plVar14 + 0x11f) = uVar8;
    if (0x1ff < uVar8) {
      _printk(&DAT_0010557c,"lt9611uxc_parse_dt");
      pcVar27 = (char *)0xffffffea;
    }
    uVar9 = of_get_named_gpio_flags(uVar24,"lt,hdmi-ps-gpio",0,0);
    *(undefined4 *)((long)plVar14 + 0x8fc) = uVar9;
    uVar9 = of_get_named_gpio_flags(uVar24,"lt,hdmi-en-gpio",0,0);
    *(undefined4 *)(plVar14 + 0x120) = uVar9;
    uVar9 = of_get_named_gpio_flags(uVar24,"lt,hdmi-3p3-en",0,0);
    *(undefined4 *)((long)plVar14 + 0x904) = uVar9;
    uVar9 = of_get_named_gpio_flags(uVar24,"lt,hdmi-1p2-en",0,0);
    *(undefined4 *)(plVar14 + 0x121) = uVar9;
    lVar15 = of_find_property(uVar24,"lt,ac-mode",0);
    plVar28 = plVar14 + 0x126;
    *(bool *)(plVar14 + 0x11e) = lVar15 != 0;
    plVar14[0x126] = (long)plVar28;
    plVar14[0x127] = (long)plVar28;
    local_c8 = 0;
    local_c0 = 0;
    local_d0 = 0;
    pcVar17 = (char *)of_get_child_by_name(uVar24,"lt,customize-modes");
    if (pcVar17 == (char *)0x0) {
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      local_a0 = (long *)0x0;
      local_b8 = (char *)0x0;
      local_b0 = (long *)0x0;
      iVar10 = __of_parse_phandle_with_args(uVar24,"lt,customize-modes",0,0,0,&local_b8);
      if ((iVar10 == 0) && (pcVar17 = local_b8, local_b8 != (char *)0x0)) goto LAB_001025ac;
      _printk(&DAT_00105ce1,"lt9611uxc_parse_dt_modes");
      if ((int)pcVar27 == 0) goto LAB_001028ec;
      goto LAB_00102418;
    }
LAB_001025ac:
    lVar15 = of_get_next_child(pcVar17,0);
    if (lVar15 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = 0;
      uVar8 = 0;
      do {
        lVar22 = kmalloc_trace(_regulator_is_enabled,0xdc0,0x78);
        if (lVar22 == 0) {
          _printk(&DAT_001053ef,"lt9611uxc_parse_dt_modes");
        }
        else {
          iVar12 = of_property_read_variable_u32_array(lVar15,"lt,mode-h-active",lVar22 + 4,1,0);
          if (iVar12 < 0) {
            puVar16 = &DAT_00105302;
          }
          else {
            iVar12 = of_property_read_variable_u32_array
                               (lVar15,"lt,mode-h-front-porch",(long)&local_c0 + 4,1,0);
            if (iVar12 < 0) {
              puVar16 = &DAT_00105b6e;
            }
            else {
              iVar12 = of_property_read_variable_u32_array
                                 (lVar15,"lt,mode-h-pulse-width",&local_c0,1,0);
              if (iVar12 < 0) {
                puVar16 = &DAT_00105dec;
              }
              else {
                iVar12 = of_property_read_variable_u32_array
                                   (lVar15,"lt,mode-h-back-porch",(long)&local_c8 + 4,1,0);
                if (iVar12 < 0) {
                  puVar16 = &DAT_00105e17;
                }
                else {
                  lVar18 = of_find_property(lVar15,"lt,mode-h-active-high",0);
                  iVar12 = of_property_read_variable_u32_array
                                     (lVar15,"lt,mode-v-active",lVar22 + 0xe,1,0);
                  if (iVar12 < 0) {
                    puVar16 = &DAT_00105939;
                  }
                  else {
                    iVar12 = of_property_read_variable_u32_array
                                       (lVar15,"lt,mode-v-front-porch",&local_c8,1,0);
                    if (iVar12 < 0) {
                      puVar16 = &DAT_00105332;
                    }
                    else {
                      iVar12 = of_property_read_variable_u32_array
                                         (lVar15,"lt,mode-v-pulse-width",(long)&local_d0 + 4,1,0);
                      if (iVar12 < 0) {
                        puVar16 = &DAT_001056ef;
                      }
                      else {
                        iVar12 = of_property_read_variable_u32_array
                                           (lVar15,"lt,mode-v-back-porch",&local_d0,1,0);
                        if (iVar12 < 0) {
                          puVar16 = &DAT_00105822;
                        }
                        else {
                          lVar19 = of_find_property(lVar15,"lt,mode-v-active-high",0);
                          iVar12 = of_property_read_variable_u32_array
                                             (lVar15,"lt,mode-clock-in-khz",lVar22,1,0);
                          if (-1 < iVar12) {
                            sVar2 = *(short *)(lVar22 + 4) + local_c0._4_2_;
                            sVar3 = *(short *)(lVar22 + 0xe) + (short)local_c8;
                            sVar4 = sVar2 + (short)local_c0;
                            *(short *)(lVar22 + 6) = sVar2;
                            *(short *)(lVar22 + 0x10) = sVar3;
                            uVar11 = 1;
                            if (lVar18 == 0) {
                              uVar11 = 2;
                            }
                            *(short *)(lVar22 + 10) = sVar4 + local_c8._4_2_;
                            sVar3 = sVar3 + local_d0._4_2_;
                            uVar23 = 8;
                            if (lVar19 != 0) {
                              uVar23 = 4;
                            }
                            *(short *)(lVar22 + 8) = sVar4;
                            uVar8 = uVar11 | uVar23 | uVar8;
                            lVar18 = lVar22 + 0x40;
                            *(short *)(lVar22 + 0x12) = sVar3;
                            plVar29 = (long *)plVar14[0x127];
                            *(uint *)(lVar22 + 0x18) = uVar8;
                            *(short *)(lVar22 + 0x14) = sVar3 + (short)local_d0;
                            uVar13 = __list_add_valid(lVar18,plVar29,plVar28);
                            if ((uVar13 & 1) != 0) {
                              *(long **)(lVar22 + 0x40) = plVar28;
                              *(long **)(lVar22 + 0x48) = plVar29;
                              plVar14[0x127] = lVar18;
                              *plVar29 = lVar18;
                            }
                            iVar10 = iVar10 + 1;
                            drm_mode_set_name(lVar22);
                            goto LAB_001025ec;
                          }
                          puVar16 = &DAT_001054aa;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          _printk(puVar16,"lt9611uxc_parse_dt_modes",iVar12);
          kfree(lVar22);
        }
LAB_001025ec:
        lVar15 = of_get_next_child(pcVar17,lVar15);
      } while (lVar15 != 0);
    }
    *(int *)(plVar14 + 0x125) = iVar10;
    if ((int)pcVar27 != 0) goto LAB_00102418;
LAB_001028ec:
    local_c0 = local_c0 & 0xffffffff;
    if (lVar1 == 0) {
      _printk(&DAT_0010571a,"lt9611uxc_get_dt_supply",0,plVar14);
      pcVar27 = (char *)0xffffffea;
      goto LAB_00102918;
    }
    uVar24 = *(undefined8 *)(param_1 + 0x308);
    *(undefined4 *)((long)plVar14 + 0x90c) = 0;
    lVar15 = of_get_child_by_name(uVar24,"lt,supply-entries");
    if (lVar15 == 0) {
      puVar16 = &DAT_001057dc;
LAB_0010298c:
      _printk(puVar16,"lt9611uxc_get_dt_supply");
LAB_00102998:
      plVar14[0x123] = param_1;
      *plVar14 = lVar1;
      uVar8 = lt9611uxc_gpio_configure(plVar14,1);
      if (uVar8 == 0) {
        if (*(uint *)(plVar14 + 0x120) < 0x200) {
          uVar24 = gpio_to_desc();
          gpiod_set_raw_value(uVar24,1);
          msleep(0x14);
        }
        puVar26 = (ulong *)plVar14[0x122];
        uVar8 = *(uint *)((long)plVar14 + 0x90c);
        if (*(uint *)((long)plVar14 + 0x904) < 0x200) {
          uVar24 = gpio_to_desc();
          gpiod_set_raw_value(uVar24,1);
        }
        if (*(uint *)(plVar14 + 0x121) < 0x200) {
          uVar24 = gpio_to_desc();
          gpiod_set_raw_value(uVar24,1);
        }
        if (0 < (int)uVar8) {
          pcVar27 = (char *)0x0;
          uVar13 = 0;
          if ((*puVar26 != 0) && (*puVar26 < 0xfffffffffffff001)) {
            uVar13 = 0;
            puVar25 = puVar26;
            do {
              iVar10 = regulator_is_enabled();
              if (((int)puVar25[7] != 0) && (iVar10 == 0)) {
                lVar15 = (long)((int)puVar25[7] * 1000);
                usleep_range_state(lVar15,lVar15,2);
              }
              uVar11 = regulator_set_load(*puVar25,(int)puVar25[6]);
              if ((int)uVar11 < 0) {
                pcVar27 = (char *)(ulong)uVar11;
                _printk(&DAT_00105419,"lt9611uxc_enable_vreg",puVar25 + 1);
                goto LAB_00102ae8;
              }
              uVar20 = regulator_enable(*puVar25);
              pcVar27 = (char *)(uVar20 & 0xffffffff);
              if ((*(int *)((long)puVar25 + 0x3c) != 0) && (iVar10 == 0)) {
                lVar15 = (long)(*(int *)((long)puVar25 + 0x3c) * 1000);
                usleep_range_state(lVar15,lVar15,2);
              }
              if ((int)uVar20 < 0) {
                _printk(&DAT_00105f61,"lt9611uxc_enable_vreg",puVar25 + 1);
                regulator_set_load(*puVar25,*(undefined4 *)((long)puVar25 + 0x34));
                goto LAB_00102ae8;
              }
              if ((ulong)uVar8 - 1 == uVar13) goto LAB_00102aec;
              puVar25 = puVar25 + 9;
              uVar13 = uVar13 + 1;
            } while ((*puVar25 != 0) && (*puVar25 < 0xfffffffffffff001));
          }
          _printk(&DAT_00105d59,"lt9611uxc_enable_vreg",puVar26 + (uVar13 & 0xffffffff) * 9 + 1,
                  pcVar27);
LAB_00102ae8:
          if ((int)uVar13 != 0) {
            lVar15 = uVar13 + 1;
            puVar26 = puVar26 + uVar13 * 9;
            do {
              puVar25 = puVar26 + -9;
              if ((int)puVar26[-1] != 0) {
                lVar22 = (long)((int)puVar26[-1] * 1000);
                usleep_range_state(lVar22,lVar22,2);
              }
              regulator_set_load(*puVar25,*(undefined4 *)((long)puVar26 + -0x14));
              regulator_disable(*puVar25);
              if (*(int *)((long)puVar26 + -4) != 0) {
                lVar22 = (long)(*(int *)((long)puVar26 + -4) * 1000);
                usleep_range_state(lVar22,lVar22,2);
              }
              lVar15 = lVar15 + -1;
              puVar26 = puVar25;
            } while (1 < lVar15);
          }
LAB_00102aec:
          if ((int)pcVar27 == 0) goto LAB_00102af4;
          _printk(&DAT_001052c8,"lt9611uxc_probe");
          goto LAB_00102e60;
        }
LAB_00102af4:
        uVar24 = gpio_to_desc((int)plVar14[0x11f]);
        gpiod_set_raw_value(uVar24,1);
        msleep(0x14);
        uVar24 = gpio_to_desc((int)plVar14[0x11f]);
        gpiod_set_raw_value(uVar24,0);
        msleep(0x14);
        uVar24 = gpio_to_desc((int)plVar14[0x11f]);
        gpiod_set_raw_value(uVar24,1);
        msleep(300);
        lt9611uxc_ctl_en(plVar14);
        plVar28 = plVar14 + 0x170;
        uVar5 = *(undefined2 *)(plVar14[0x123] + 2);
        plVar14[0x170] = 0;
        plVar14[0x171] = 0;
        plVar14[0x172] = 0;
        plVar14[0x173] = 0;
        plVar14[0x174] = 0;
        plVar14[0x175] = 0;
        plVar14[0x176] = 0;
        plVar14[0x177] = 0;
        plVar14[0x178] = 0;
        plVar14[0x179] = 0;
        plVar14[0x17a] = 0;
        plVar14[0x17b] = 0;
        plVar14[0x17c] = 0;
        plVar14[0x17d] = 0;
        plVar14[0x17e] = 0;
        *(undefined2 *)(plVar14 + 0x170) = 0x81ff;
        plVar14[0x17f] = 0;
        local_b8 = (char *)CONCAT62(0x20000,uVar5);
        local_b0 = plVar28;
        iVar10 = i2c_transfer(*(undefined8 *)(plVar14[0x123] + 0x18),&local_b8,1);
        if (iVar10 < 1) {
          _printk(&DAT_00105b45,"lt9611uxc_write_byte");
        }
        lVar15 = plVar14[0x123];
        uVar5 = *(undefined2 *)(lVar15 + 2);
        uVar6 = *(undefined2 *)(lVar15 + 2);
        plVar14[0x17e] = 0;
        plVar14[0x17f] = 0;
        plVar14[0x17c] = 0;
        plVar14[0x17d] = 0;
        plVar14[0x17a] = 0;
        plVar14[0x17b] = 0;
        plVar14[0x178] = 0;
        plVar14[0x179] = 0;
        plVar14[0x176] = 0;
        plVar14[0x177] = 0;
        plVar14[0x174] = 0;
        plVar14[0x175] = 0;
        plVar14[0x172] = 0;
        plVar14[0x173] = 0;
        *plVar28 = 0;
        plVar14[0x171] = 0;
        plVar14[399] = 0;
        plVar14[0x18e] = 0;
        plVar14[0x18d] = 0;
        plVar14[0x18c] = 0;
        plVar14[0x18b] = 0;
        plVar14[0x18a] = 0;
        plVar14[0x189] = 0;
        plVar14[0x188] = 0;
        plVar14[0x187] = 0;
        plVar14[0x186] = 0;
        plVar14[0x185] = 0;
        plVar14[0x184] = 0;
        plVar14[0x183] = 0;
        plVar14[0x182] = 0;
        plVar14[0x181] = 0;
        plVar14[0x180] = 0;
        *(undefined1 *)(plVar14 + 0x170) = 0;
        local_b8 = (char *)CONCAT62(0x10000,uVar5);
        local_a8._0_6_ = CONCAT42(0x10001,uVar6);
        local_a8 = (ulong)(uint6)local_a8;
        local_b0 = plVar28;
        local_a0 = plVar14 + 0x180;
        iVar10 = i2c_transfer(*(undefined8 *)(lVar15 + 0x18),&local_b8,2);
        if (iVar10 == 2) {
          lVar22 = plVar14[0x123];
          uVar5 = *(undefined2 *)(lVar22 + 2);
          uVar6 = *(undefined2 *)(lVar22 + 2);
          lVar15 = plVar14[0x180];
          plVar14[0x18e] = 0;
          plVar14[399] = 0;
          plVar14[0x18c] = 0;
          plVar14[0x18d] = 0;
          plVar14[0x18a] = 0;
          plVar14[0x18b] = 0;
          plVar14[0x188] = 0;
          plVar14[0x189] = 0;
          plVar14[0x186] = 0;
          plVar14[0x187] = 0;
          plVar14[0x184] = 0;
          plVar14[0x185] = 0;
          plVar14[0x182] = 0;
          plVar14[0x183] = 0;
          plVar14[0x180] = 0;
          plVar14[0x181] = 0;
          plVar14[0x17e] = 0;
          plVar14[0x17f] = 0;
          plVar14[0x17c] = 0;
          plVar14[0x17d] = 0;
          plVar14[0x17a] = 0;
          plVar14[0x17b] = 0;
          plVar14[0x178] = 0;
          plVar14[0x179] = 0;
          plVar14[0x176] = 0;
          plVar14[0x177] = 0;
          plVar14[0x174] = 0;
          plVar14[0x175] = 0;
          plVar14[0x172] = 0;
          plVar14[0x173] = 0;
          *plVar28 = 0;
          plVar14[0x171] = 0;
          *(undefined1 *)(plVar14 + 0x170) = 1;
          local_b8 = (char *)CONCAT62(0x10000,uVar5);
          local_a8._0_6_ = CONCAT42(0x10001,uVar6);
          local_a8 = (ulong)(uint6)local_a8;
          local_b0 = plVar28;
          local_a0 = plVar14 + 0x180;
          iVar10 = i2c_transfer(*(undefined8 *)(lVar22 + 0x18),&local_b8,2);
          if (iVar10 != 2) goto LAB_00102dd4;
          _printk(&DAT_00105f79,"lt9611uxc_read_device_id",
                  CONCAT11((char)lVar15,(char)plVar14[0x180]));
          lt9611uxc_ctl_disable(plVar14);
          msleep(0x32);
          *(long **)(param_1 + 0xb8) = plVar14;
          uVar8 = sysfs_create_group(lVar1,lt9611uxc_sysfs_attr_grp);
          if (uVar8 == 0) {
            cVar7 = lt9611uxc_get_version(plVar14);
            if (cVar7 == '\0') {
              uVar13 = request_firmware_nowait
                                 (&__this_module,1,"lt9611uxc_fw.bin",lVar1,0xcc0,plVar14,
                                  lt9611uxc_firmware_cb);
              pcVar27 = (char *)(uVar13 & 0xffffffff);
              if ((int)uVar13 == 0) goto LAB_00102310;
              _printk(&DAT_001058ff,"lt9611uxc_probe",pcVar27);
            }
            else {
              _printk(&DAT_00106020,"lt9611uxc_probe");
              __mutex_init(plVar14 + 0x26,"&pdata->lock",&lt9611uxc_probe___key);
              __init_waitqueue_head(plVar14 + 0x14d,"&pdata->edid_wq",&lt9611uxc_probe___key_36);
              plVar14[0x12] = *(long *)(param_1 + 0x308);
              plVar14[0x16] = (long)&lt9611uxc_bridge_funcs;
              drm_bridge_add(plVar14 + 1);
              lVar15 = alloc_workqueue(&DAT_00105605,0xe000a,1,"lt9611uxc_wk");
              plVar14[0x146] = lVar15;
              if (lVar15 != 0) {
                plVar14[0x147] = 0xfffffffe0;
                plVar14[0x148] = (long)(plVar14 + 0x148);
                plVar14[0x149] = (long)(plVar14 + 0x148);
                plVar14[0x14a] = (long)lt9611uxc_hpd_work;
                gpio_to_desc(*(undefined4 *)((long)plVar14 + 0x8f4));
                uVar24 = gpiod_to_irq();
                *(int *)((long)plVar14 + 0x8ec) = (int)uVar24;
                uVar13 = request_threaded_irq
                                   (uVar24,0,lt9611uxc_irq_thread_handler,0x2002,"lt9611uxc_irq",
                                    plVar14);
                pcVar27 = (char *)(uVar13 & 0xffffffff);
                if ((int)uVar13 == 0) goto LAB_00102310;
                puVar16 = &DAT_001052e5;
                goto LAB_00103290;
              }
              _printk(&DAT_001059f4,"lt9611uxc_probe");
              pcVar27 = (char *)0x0;
            }
          }
          else {
            pcVar27 = (char *)(ulong)uVar8;
            _printk(&DAT_001058d5,"lt9611uxc_sysfs_init","lt9611uxc_sysfs_init",pcVar27);
            puVar16 = &DAT_0010568f;
LAB_00103290:
            _printk(puVar16,"lt9611uxc_probe");
          }
        }
        else {
LAB_00102dd4:
          _printk(&DAT_00106009,"lt9611uxc_read");
          _printk(&DAT_00105b0c,"lt9611uxc_read_device_id");
          lt9611uxc_ctl_disable(plVar14);
          msleep(0x32);
          _printk(&DAT_00106110,"lt9611uxc_probe");
          pcVar27 = (char *)0xffffffff;
        }
LAB_00102e60:
        lt9611uxc_gpio_configure(plVar14,0);
      }
      else {
        pcVar27 = (char *)(ulong)uVar8;
        _printk(&DAT_0010566e,"lt9611uxc_probe");
      }
      lt9611uxc_put_dt_supply(lVar1,plVar14);
      goto LAB_00102310;
    }
    lVar22 = of_get_next_available_child(lVar15,0);
    if (lVar22 == 0) {
      *(undefined4 *)((long)plVar14 + 0x90c) = 0;
LAB_00102984:
      puVar16 = &DAT_00105baf;
      goto LAB_0010298c;
    }
    uVar8 = 0;
    do {
      uVar8 = uVar8 + 1;
      lVar22 = of_get_next_available_child(lVar15,lVar22);
    } while (lVar22 != 0);
    *(uint *)((long)plVar14 + 0x90c) = uVar8;
    if (uVar8 == 0) goto LAB_00102984;
    lVar22 = devm_kmalloc(lVar1,(ulong)uVar8 * 0x48,0xdc0);
    plVar14[0x122] = lVar22;
    if (lVar22 != 0) {
      puVar26 = (ulong *)of_get_next_available_child(lVar15,0);
      if (puVar26 != (ulong *)0x0) {
        iVar10 = 0;
        pcVar17 = s_lt_supply_post_on_sleep_00105c64;
        do {
          local_b8 = (char *)0x0;
          uVar8 = of_property_read_string(puVar26,"lt,supply-name",&local_b8);
          pcVar27 = local_b8;
          if (uVar8 != 0) {
            pcVar27 = (char *)(ulong)uVar8;
            _printk(&DAT_00105747,"lt9611uxc_get_dt_supply",pcVar27);
            goto LAB_00103494;
          }
          lVar22 = plVar14[0x122];
          uVar13 = strnlen(local_b8,0x20);
          if (uVar13 == 0xffffffffffffffff) {
            fortify_panic("strnlen");
LAB_00103454:
            fortify_panic("strscpy");
            plVar28 = plVar14;
            goto LAB_00103460;
          }
          if (uVar13 != 0x20) {
            uVar13 = uVar13 + 1;
          }
          if (0x20 < uVar13) goto LAB_00103454;
          strscpy(lVar22 + (long)iVar10 * 0x48 + 8,pcVar27);
          uVar8 = of_property_read_variable_u32_array
                            (puVar26,"lt,supply-min-voltage",(long)&local_c0 + 4,1,0);
          if ((int)uVar8 < 0) {
            pcVar27 = (char *)(ulong)uVar8;
            _printk(&DAT_00105efb,"lt9611uxc_get_dt_supply",pcVar27);
            goto LAB_00103494;
          }
          *(undefined4 *)(plVar14[0x122] + (long)iVar10 * 0x48 + 0x28) = local_c0._4_4_;
          uVar8 = of_property_read_variable_u32_array
                            (puVar26,"lt,supply-max-voltage",(long)&local_c0 + 4,1,0);
          if ((int)uVar8 < 0) {
            pcVar27 = (char *)(ulong)uVar8;
            _printk(&DAT_00105fa1,"lt9611uxc_get_dt_supply",pcVar27);
            goto LAB_00103494;
          }
          lVar22 = (long)iVar10 * 0x48;
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x2c) = local_c0._4_4_;
          iVar12 = of_property_read_variable_u32_array
                             (puVar26,"lt,supply-enable-load",(long)&local_c0 + 4,1,0);
          uVar9 = 0;
          if (-1 < iVar12) {
            uVar9 = local_c0._4_4_;
          }
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x30) = uVar9;
          iVar12 = of_property_read_variable_u32_array
                             (puVar26,"lt,supply-disable-load",(long)&local_c0 + 4,1,0);
          uVar9 = 0;
          if (-1 < iVar12) {
            uVar9 = local_c0._4_4_;
          }
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x34) = uVar9;
          iVar12 = of_property_read_variable_u32_array
                             (puVar26,"lt,supply-pre-on-sleep",(long)&local_c0 + 4,1,0);
          uVar9 = 0;
          if (-1 < iVar12) {
            uVar9 = local_c0._4_4_;
          }
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x38) = uVar9;
          iVar12 = of_property_read_variable_u32_array
                             (puVar26,"lt,supply-pre-off-sleep",(long)&local_c0 + 4,1,0);
          uVar9 = 0;
          if (-1 < iVar12) {
            uVar9 = local_c0._4_4_;
          }
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x40) = uVar9;
          iVar12 = of_property_read_variable_u32_array
                             (puVar26,s_lt_supply_post_on_sleep_00105c64,(long)&local_c0 + 4,1,0);
          uVar9 = 0;
          if (-1 < iVar12) {
            uVar9 = local_c0._4_4_;
          }
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x3c) = uVar9;
          iVar12 = of_property_read_variable_u32_array
                             (puVar26,"lt,supply-post-off-sleep",(long)&local_c0 + 4,1,0);
          iVar10 = iVar10 + 1;
          uVar9 = 0;
          if (-1 < iVar12) {
            uVar9 = local_c0._4_4_;
          }
          *(undefined4 *)(plVar14[0x122] + lVar22 + 0x44) = uVar9;
          puVar26 = (ulong *)of_get_next_available_child(lVar15,puVar26);
        } while (puVar26 != (ulong *)0x0);
      }
      puVar26 = (ulong *)plVar14[0x122];
      if ((puVar26 != (ulong *)0x0) && (uVar8 = *(uint *)((long)plVar14 + 0x90c), 0 < (int)uVar8)) {
        puVar25 = puVar26 + 1;
        uVar13 = regulator_get(lVar1,puVar25);
        plVar28 = (long *)0x0;
        *puVar26 = uVar13;
        pcVar17 = (char *)puVar26;
        if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
          pcVar27 = (char *)0x0;
LAB_001031e0:
          _printk(&DAT_00105a49,"lt9611uxc_config_vreg",puVar25,pcVar27);
          goto LAB_00103460;
        }
        uVar13 = regulator_set_voltage(uVar13,(int)puVar26[5],*(undefined4 *)((long)puVar26 + 0x2c))
        ;
        pcVar27 = (char *)(uVar13 & 0xffffffff);
        if ((int)uVar13 < 0) {
          plVar28 = (long *)0x0;
        }
        else {
          lVar15 = 0;
          plVar28 = (long *)0x0;
          do {
            if ((ulong)uVar8 * 0x48 + -0x48 == lVar15) goto LAB_00102998;
            puVar25 = (ulong *)((long)puVar26 + lVar15 + 0x50);
            uVar13 = regulator_get(lVar1,puVar25);
            *(ulong *)((long)puVar26 + lVar15 + 0x48) = uVar13;
            if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
              plVar28 = (long *)(ulong)((int)plVar28 + 1);
              pcVar17 = (char *)((long)puVar26 + lVar15 + 0x48);
              goto LAB_001031e0;
            }
            uVar13 = regulator_set_voltage
                               (uVar13,*(undefined4 *)((long)puVar26 + lVar15 + 0x70),
                                *(undefined4 *)((long)puVar26 + lVar15 + 0x74));
            pcVar27 = (char *)(uVar13 & 0xffffffff);
            lVar15 = lVar15 + 0x48;
            plVar28 = (long *)((long)plVar28 + 1);
          } while (-1 < (int)uVar13);
          pcVar17 = (char *)((long)puVar26 + lVar15);
          puVar25 = (ulong *)((long)pcVar17 + 8);
        }
        _printk(&DAT_00105bc6,"lt9611uxc_config_vreg",puVar25);
        while( true ) {
          regulator_put(*(ulong *)pcVar17);
LAB_00103460:
          uVar8 = (int)plVar28 - 1;
          plVar28 = (long *)(ulong)uVar8;
          *(ulong *)pcVar17 = 0;
          if ((int)uVar8 < 0) break;
          pcVar17 = (char *)(puVar26 + (long)plVar28 * 9);
          regulator_set_load(*(ulong *)pcVar17,0);
        }
        if ((int)pcVar27 != 0) {
LAB_00103494:
          if (plVar14[0x122] != 0) {
            plVar14[0x122] = 0;
            *(undefined4 *)((long)plVar14 + 0x90c) = 0;
          }
          goto LAB_00102918;
        }
      }
      goto LAB_00102998;
    }
    pcVar27 = (char *)0xfffffff4;
LAB_00102918:
    puVar16 = &DAT_001059d5;
  }
  _printk(puVar16,"lt9611uxc_probe");
LAB_00102310:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)pcVar27 & 0xffffffff;
}



//------------------------------------------------------------
// lt9611uxc_remove @ 001034b0 size=408
// signature: undefined lt9611uxc_remove(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_remove(long param_1)

{
  long *plVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  
  lVar4 = *(long *)(param_1 + 0xb8);
  if (lVar4 != 0) {
    mipi_dsi_detach(*(undefined8 *)(lVar4 + 0x120));
    mipi_dsi_device_unregister(*(undefined8 *)(lVar4 + 0x120));
    drm_bridge_remove(lVar4 + 8);
    param_1 = param_1 + 0x20;
    if (param_1 == 0) {
      _printk(&DAT_0010521a,"lt9611uxc_sysfs_remove","lt9611uxc_sysfs_remove");
    }
    else {
      sysfs_remove_group(param_1,lt9611uxc_sysfs_attr_grp);
    }
    disable_irq(*(undefined4 *)(lVar4 + 0x8ec));
    free_irq(*(undefined4 *)(lVar4 + 0x8ec),lVar4);
    lt9611uxc_gpio_configure(lVar4,0);
    if (param_1 == 0) {
      _printk(&DAT_0010571a,"lt9611uxc_put_dt_supply",0,lVar4);
    }
    else {
      lVar5 = *(long *)(lVar4 + 0x910);
      if ((lVar5 != 0) && (uVar3 = *(int *)(lVar4 + 0x90c) - 1, -1 < (int)uVar3)) {
        do {
          plVar6 = (long *)(lVar5 + (ulong)uVar3 * 0x48);
          if (*plVar6 != 0) {
            regulator_set_voltage(*plVar6,0,*(undefined4 *)(lVar5 + (ulong)uVar3 * 0x48 + 0x2c));
            regulator_put(*plVar6);
            *plVar6 = 0;
          }
          uVar3 = uVar3 - 1;
        } while (-1 < (int)uVar3);
        lVar5 = *(long *)(lVar4 + 0x910);
      }
      if (lVar5 != 0) {
        *(undefined8 *)(lVar4 + 0x910) = 0;
      }
      *(undefined4 *)(lVar4 + 0x90c) = 0;
    }
    plVar6 = *(long **)(lVar4 + 0x930);
    while (plVar6 != (long *)(lVar4 + 0x930)) {
      plVar7 = (long *)*plVar6;
      uVar2 = __list_del_entry_valid(plVar6);
      if ((uVar2 & 1) != 0) {
        lVar5 = *plVar6;
        plVar1 = (long *)plVar6[1];
        *(long **)(lVar5 + 8) = plVar1;
        *plVar1 = lVar5;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      kfree(plVar6 + -8);
      plVar6 = plVar7;
    }
    if (*(long *)(lVar4 + 0xa30) != 0) {
      destroy_workqueue();
    }
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_gpio_configure @ 00103648 size=708
// signature: undefined lt9611uxc_gpio_configure(void)
// callers: [lt9611uxc_remove, lt9611uxc_probe]
//------------------------------------------------------------

int lt9611uxc_gpio_configure(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if ((param_2 & 1) == 0) {
    if (*(uint *)(param_1 + 0x8f4) < 0x200) {
      gpio_free();
    }
    if (*(uint *)(param_1 + 0x8fc) < 0x200) {
      gpio_free();
    }
    if (*(uint *)(param_1 + 0x900) < 0x200) {
      gpio_free();
    }
    if (*(uint *)(param_1 + 0x8f8) < 0x200) {
      gpio_free();
    }
    if (*(uint *)(param_1 + 0x908) < 0x200) {
      gpio_free();
    }
    if (*(uint *)(param_1 + 0x904) < 0x200) {
      gpio_free();
    }
    return 0;
  }
  if (*(uint *)(param_1 + 0x904) < 0x200) {
    iVar1 = gpio_request(*(uint *)(param_1 + 0x904),"hdmi_3p3_en");
    if (iVar1 != 0) {
      puVar3 = &DAT_0010559c;
      goto LAB_0010387c;
    }
    uVar2 = gpio_to_desc(*(undefined4 *)(param_1 + 0x904));
    iVar1 = gpiod_direction_output_raw(uVar2,0);
    if (iVar1 == 0) goto LAB_00103690;
    puVar3 = &DAT_00105d26;
LAB_001038a8:
    _printk(puVar3,"lt9611uxc_gpio_configure");
  }
  else {
LAB_00103690:
    if (*(uint *)(param_1 + 0x908) < 0x200) {
      iVar1 = gpio_request(*(uint *)(param_1 + 0x908),"hdmi_1p2_en");
      if (iVar1 != 0) {
        puVar3 = &DAT_00105bde;
        goto LAB_0010387c;
      }
      uVar2 = gpio_to_desc(*(undefined4 *)(param_1 + 0x908));
      iVar1 = gpiod_direction_output_raw(uVar2,0);
      if (iVar1 != 0) {
        puVar3 = &DAT_001054cd;
        goto LAB_001038a8;
      }
    }
    iVar1 = gpio_request(*(undefined4 *)(param_1 + 0x8f8),"lt9611-reset-gpio");
    if (iVar1 != 0) {
      _printk(&DAT_001060b1,"lt9611uxc_gpio_configure");
      return iVar1;
    }
    uVar2 = gpio_to_desc(*(undefined4 *)(param_1 + 0x8f8));
    iVar1 = gpiod_direction_output_raw(uVar2,0);
    if (iVar1 != 0) {
      puVar3 = &DAT_0010614d;
LAB_0010387c:
      _printk(puVar3,"lt9611uxc_gpio_configure");
      goto LAB_001038f0;
    }
    if (*(uint *)(param_1 + 0x900) < 0x200) {
      iVar1 = gpio_request(*(uint *)(param_1 + 0x900),"lt9611-hdmi-en-gpio");
      if (iVar1 != 0) {
        puVar3 = &DAT_00105608;
        goto LAB_0010387c;
      }
      uVar2 = gpio_to_desc(*(undefined4 *)(param_1 + 0x900));
      iVar1 = gpiod_direction_output_raw(uVar2,1);
      if (iVar1 != 0) {
        puVar3 = &DAT_00105fdd;
        goto LAB_001038a8;
      }
    }
    if (*(uint *)(param_1 + 0x8fc) < 0x200) {
      iVar1 = gpio_request(*(uint *)(param_1 + 0x8fc),"lt9611-hdmi-ps-gpio");
      if (iVar1 != 0) {
        puVar3 = &DAT_00106177;
        goto LAB_001038a8;
      }
      gpio_to_desc(*(undefined4 *)(param_1 + 0x8fc));
      iVar1 = gpiod_direction_input();
      if (iVar1 == 0) goto LAB_00103744;
      puVar3 = &DAT_00105ae0;
LAB_001038c4:
      _printk(puVar3,"lt9611uxc_gpio_configure");
    }
    else {
LAB_00103744:
      iVar1 = gpio_request(*(undefined4 *)(param_1 + 0x8f4),"lt9611-irq-gpio");
      if (iVar1 != 0) {
        puVar3 = &DAT_001055be;
        goto LAB_001038c4;
      }
      gpio_to_desc(*(undefined4 *)(param_1 + 0x8f4));
      iVar1 = gpiod_direction_input();
      if (iVar1 == 0) {
        return 0;
      }
      _printk(&DAT_001058ad,"lt9611uxc_gpio_configure");
      gpio_free(*(undefined4 *)(param_1 + 0x8f4));
    }
    if (*(uint *)(param_1 + 0x8fc) < 0x200) {
      gpio_free();
    }
  }
  if (*(uint *)(param_1 + 0x900) < 0x200) {
    gpio_free();
  }
LAB_001038f0:
  gpio_free(*(undefined4 *)(param_1 + 0x8f8));
  return iVar1;
}



//------------------------------------------------------------
// lt9611uxc_firmware_cb @ 00103910 size=84
// signature: undefined lt9611uxc_firmware_cb(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_firmware_cb(long param_1,undefined8 param_2)

{
  if (param_1 == 0) {
    _printk(&DAT_00105500,"lt9611uxc_firmware_cb");
  }
  else {
    lt9611uxc_firmware_upgrade(param_2,param_1);
    release_firmware(param_1);
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_irq_thread_handler @ 00103968 size=1012
// signature: undefined lt9611uxc_irq_thread_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 lt9611uxc_irq_thread_handler(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  byte *pbVar3;
  char cVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  undefined2 local_78;
  undefined6 uStack_76;
  undefined8 *local_70;
  undefined8 local_68;
  byte *local_60;
  long local_58;
  
  lVar9 = sp_el0;
  lVar1 = param_2 + 0x130;
  local_58 = *(long *)(lVar9 + 0x638);
  mutex_lock(lVar1);
  cVar4 = *(char *)(param_2 + 0xc83);
  lt9611uxc_ctl_en(param_2);
  puVar2 = (undefined8 *)(param_2 + 0xb80);
  uVar5 = *(undefined2 *)(*(long *)(param_2 + 0x918) + 2);
  *(undefined8 *)(param_2 + 0xb80) = 0;
  *(undefined8 *)(param_2 + 0xb88) = 0;
  *(undefined8 *)(param_2 + 0xb90) = 0;
  *(undefined8 *)(param_2 + 0xb98) = 0;
  *(undefined8 *)(param_2 + 0xba0) = 0;
  *(undefined8 *)(param_2 + 0xba8) = 0;
  *(undefined8 *)(param_2 + 0xbb0) = 0;
  *(undefined8 *)(param_2 + 3000) = 0;
  *(undefined8 *)(param_2 + 0xbc0) = 0;
  *(undefined8 *)(param_2 + 0xbc8) = 0;
  *(undefined8 *)(param_2 + 0xbd0) = 0;
  *(undefined8 *)(param_2 + 0xbd8) = 0;
  *(undefined8 *)(param_2 + 0xbe0) = 0;
  *(undefined8 *)(param_2 + 0xbe8) = 0;
  *(undefined8 *)(param_2 + 0xbf0) = 0;
  *(undefined2 *)(param_2 + 0xb80) = 0xb0ff;
  *(undefined8 *)(param_2 + 0xbf8) = 0;
  _local_78 = CONCAT62(0x20000,uVar5);
  local_70 = puVar2;
  iVar7 = i2c_transfer(*(undefined8 *)(*(long *)(param_2 + 0x918) + 0x18),&local_78,1);
  if (iVar7 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar9 = *(long *)(param_2 + 0x918);
  pbVar3 = (byte *)(param_2 + 0xc00);
  uVar5 = *(undefined2 *)(lVar9 + 2);
  uVar6 = *(undefined2 *)(lVar9 + 2);
  *(undefined8 *)(param_2 + 0xbf0) = 0;
  *(undefined8 *)(param_2 + 0xbf8) = 0;
  *(undefined8 *)(param_2 + 0xbe0) = 0;
  *(undefined8 *)(param_2 + 0xbe8) = 0;
  *(undefined8 *)(param_2 + 0xbd0) = 0;
  *(undefined8 *)(param_2 + 0xbd8) = 0;
  *(undefined8 *)(param_2 + 0xbc0) = 0;
  *(undefined8 *)(param_2 + 0xbc8) = 0;
  *(undefined8 *)(param_2 + 0xbb0) = 0;
  *(undefined8 *)(param_2 + 3000) = 0;
  *(undefined8 *)(param_2 + 0xba0) = 0;
  *(undefined8 *)(param_2 + 0xba8) = 0;
  *(undefined8 *)(param_2 + 0xb90) = 0;
  *(undefined8 *)(param_2 + 0xb98) = 0;
  *puVar2 = 0;
  *(undefined8 *)(param_2 + 0xb88) = 0;
  *(undefined8 *)(param_2 + 0xc78) = 0;
  *(undefined8 *)(param_2 + 0xc70) = 0;
  *(undefined8 *)(param_2 + 0xc68) = 0;
  *(undefined8 *)(param_2 + 0xc60) = 0;
  *(undefined8 *)(param_2 + 0xc58) = 0;
  *(undefined8 *)(param_2 + 0xc50) = 0;
  *(undefined8 *)(param_2 + 0xc48) = 0;
  *(undefined8 *)(param_2 + 0xc40) = 0;
  *(undefined8 *)(param_2 + 0xc38) = 0;
  *(undefined8 *)(param_2 + 0xc30) = 0;
  *(undefined8 *)(param_2 + 0xc28) = 0;
  *(undefined8 *)(param_2 + 0xc20) = 0;
  *(undefined8 *)(param_2 + 0xc18) = 0;
  *(undefined8 *)(param_2 + 0xc10) = 0;
  *(undefined8 *)(param_2 + 0xc08) = 0;
  *(undefined1 *)(param_2 + 0xb80) = 0x22;
  *(undefined8 *)(param_2 + 0xc00) = 0;
  _local_78 = CONCAT62(0x10000,uVar5);
  local_68._0_6_ = CONCAT42(0x10001,uVar6);
  local_68 = (ulong)(uint6)local_68;
  local_70 = puVar2;
  local_60 = pbVar3;
  iVar7 = i2c_transfer(*(undefined8 *)(lVar9 + 0x18),&local_78,2);
  if (iVar7 == 2) {
    uVar10 = (uint)*pbVar3;
    if (*pbVar3 == 0) {
      _printk(&DAT_00105867,"lt9611uxc_irq_thread_handler");
    }
    else {
      uVar5 = *(undefined2 *)(*(long *)(param_2 + 0x918) + 2);
      *puVar2 = 0;
      *(undefined8 *)(param_2 + 0xb88) = 0;
      *(undefined8 *)(param_2 + 0xb90) = 0;
      *(undefined8 *)(param_2 + 0xb98) = 0;
      *(undefined8 *)(param_2 + 0xba0) = 0;
      *(undefined8 *)(param_2 + 0xba8) = 0;
      *(undefined8 *)(param_2 + 0xbb0) = 0;
      *(undefined8 *)(param_2 + 3000) = 0;
      *(undefined8 *)(param_2 + 0xbc0) = 0;
      *(undefined8 *)(param_2 + 0xbc8) = 0;
      *(undefined8 *)(param_2 + 0xbd0) = 0;
      *(undefined8 *)(param_2 + 0xbd8) = 0;
      *(undefined8 *)(param_2 + 0xbe0) = 0;
      *(undefined8 *)(param_2 + 0xbe8) = 0;
      *(undefined8 *)(param_2 + 0xbf0) = 0;
      *(undefined8 *)(param_2 + 0xbf8) = 0;
      *(undefined1 *)(param_2 + 0xb80) = 0x22;
      _local_78 = CONCAT62(0x20000,uVar5);
      local_70 = puVar2;
      iVar7 = i2c_transfer(*(undefined8 *)(*(long *)(param_2 + 0x918) + 0x18),&local_78,1);
      if (iVar7 < 1) {
        _printk(&DAT_00105b45,"lt9611uxc_write_byte");
      }
      lVar9 = *(long *)(param_2 + 0x918);
      uVar5 = *(undefined2 *)(lVar9 + 2);
      uVar6 = *(undefined2 *)(lVar9 + 2);
      *(undefined8 *)(param_2 + 0xc70) = 0;
      *(undefined8 *)(param_2 + 0xc78) = 0;
      *(undefined8 *)(param_2 + 0xc60) = 0;
      *(undefined8 *)(param_2 + 0xc68) = 0;
      *(undefined8 *)(param_2 + 0xc50) = 0;
      *(undefined8 *)(param_2 + 0xc58) = 0;
      *(undefined8 *)(param_2 + 0xc40) = 0;
      *(undefined8 *)(param_2 + 0xc48) = 0;
      *(undefined8 *)(param_2 + 0xc30) = 0;
      *(undefined8 *)(param_2 + 0xc38) = 0;
      *(undefined8 *)(param_2 + 0xc20) = 0;
      *(undefined8 *)(param_2 + 0xc28) = 0;
      *(undefined8 *)(param_2 + 0xc10) = 0;
      *(undefined8 *)(param_2 + 0xc18) = 0;
      *(undefined8 *)(param_2 + 0xc00) = 0;
      *(undefined8 *)(param_2 + 0xc08) = 0;
      *(undefined8 *)(param_2 + 0xbf0) = 0;
      *(undefined8 *)(param_2 + 0xbf8) = 0;
      *(undefined8 *)(param_2 + 0xbe0) = 0;
      *(undefined8 *)(param_2 + 0xbe8) = 0;
      *(undefined8 *)(param_2 + 0xbd0) = 0;
      *(undefined8 *)(param_2 + 0xbd8) = 0;
      *(undefined8 *)(param_2 + 0xbc0) = 0;
      *(undefined8 *)(param_2 + 0xbc8) = 0;
      *(undefined8 *)(param_2 + 0xbb0) = 0;
      *(undefined8 *)(param_2 + 3000) = 0;
      *(undefined8 *)(param_2 + 0xba0) = 0;
      *(undefined8 *)(param_2 + 0xba8) = 0;
      *(undefined8 *)(param_2 + 0xb90) = 0;
      *(undefined8 *)(param_2 + 0xb98) = 0;
      *puVar2 = 0;
      *(undefined8 *)(param_2 + 0xb88) = 0;
      *(undefined1 *)(param_2 + 0xb80) = 0x23;
      _local_78 = CONCAT62(0x10000,uVar5);
      local_68._0_6_ = CONCAT42(0x10001,uVar6);
      local_68 = (ulong)(uint6)local_68;
      local_70 = puVar2;
      local_60 = pbVar3;
      iVar7 = i2c_transfer(*(undefined8 *)(lVar9 + 0x18),&local_78,2);
      if (iVar7 == 2) {
        uVar8 = (uint)*pbVar3;
      }
      else {
        _printk(&DAT_00106009,"lt9611uxc_read");
        uVar8 = 0;
      }
      *(byte *)(param_2 + 0xc84) = (byte)(uVar8 >> 1) & 1;
      *(byte *)(param_2 + 0xc83) = (byte)uVar8 & 1;
      if ((uVar8 >> 1 & 1) == 0) {
        *(undefined1 *)(param_2 + 0xc87) = 0;
      }
      else {
        *(undefined1 *)(param_2 + 0xc87) = 1;
      }
    }
  }
  else {
    _printk(&DAT_00106009,"lt9611uxc_read");
    _printk(&DAT_00105372,"lt9611uxc_irq_thread_handler");
    uVar10 = 0;
  }
  lt9611uxc_ctl_disable(param_2);
  if ((*(char *)(param_2 + 0xc85) == '\0') && (*(char *)(param_2 + 0xc83) != '\0')) {
    *(undefined1 *)(param_2 + 0xc86) = 1;
  }
  if (cVar4 == '\0') {
    if (*(char *)(param_2 + 0xc83) != '\0') {
      *(undefined1 *)(param_2 + 0xc80) = 1;
      mutex_unlock(lVar1);
      __wake_up(param_2 + 0xa68,3,0,0);
      goto LAB_00103c68;
    }
LAB_00103c5c:
    *(undefined1 *)(param_2 + 0xc80) = 0;
  }
  else if (*(char *)(param_2 + 0xc83) == '\0') goto LAB_00103c5c;
  mutex_unlock(lVar1);
LAB_00103c68:
  msleep(0x32);
  if (((uVar10 >> 1 & 1) != 0) && (*(char *)(param_2 + 0xc85) != '\0')) {
    queue_work_on(0x20,*(undefined8 *)(param_2 + 0xa30),param_2 + 0xa38);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// lt9611uxc_put_dt_supply @ 00103d5c size=188
// signature: undefined lt9611uxc_put_dt_supply(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

void lt9611uxc_put_dt_supply(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  
  if (param_1 == 0) {
    _printk(&DAT_0010571a,"lt9611uxc_put_dt_supply",0,param_2);
  }
  else {
    lVar2 = *(long *)(param_2 + 0x910);
    if ((lVar2 != 0) && (uVar1 = *(int *)(param_2 + 0x90c) - 1, -1 < (int)uVar1)) {
      do {
        plVar3 = (long *)(lVar2 + (ulong)uVar1 * 0x48);
        if (*plVar3 != 0) {
          regulator_set_voltage(*plVar3,0,*(undefined4 *)(lVar2 + (ulong)uVar1 * 0x48 + 0x2c));
          regulator_put(*plVar3);
          *plVar3 = 0;
        }
        uVar1 = uVar1 - 1;
      } while (-1 < (int)uVar1);
      lVar2 = *(long *)(param_2 + 0x910);
    }
    if (lVar2 != 0) {
      *(undefined8 *)(param_2 + 0x910) = 0;
    }
    *(undefined4 *)(param_2 + 0x90c) = 0;
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_ctl_en @ 00103e18 size=344
// signature: undefined lt9611uxc_ctl_en(void)
// callers: [lt9611uxc_connector_get_modes, lt9611uxc_probe, lt9611uxc_irq_thread_handler, lt9611uxc_connector_detect]
//------------------------------------------------------------

void lt9611uxc_ctl_en(long param_1)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  undefined2 local_48;
  undefined6 uStack_46;
  undefined8 *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  _local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x1ee;
  _local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_ctl_disable @ 00103f70 size=344
// signature: undefined lt9611uxc_ctl_disable(void)
// callers: [lt9611uxc_connector_get_modes, lt9611uxc_probe, lt9611uxc_irq_thread_handler, lt9611uxc_connector_detect]
//------------------------------------------------------------

void lt9611uxc_ctl_disable(long param_1)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  long lVar3;
  int iVar4;
  undefined2 local_48;
  undefined6 uStack_46;
  undefined8 *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar1 = (undefined8 *)(param_1 + 0xb80);
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined2 *)(param_1 + 0xb80) = 0x80ff;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  _local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x918) + 2);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0xb88) = 0;
  *(undefined8 *)(param_1 + 0xb90) = 0;
  *(undefined8 *)(param_1 + 0xb98) = 0;
  *(undefined8 *)(param_1 + 0xba0) = 0;
  *(undefined8 *)(param_1 + 0xba8) = 0;
  *(undefined8 *)(param_1 + 0xbb0) = 0;
  *(undefined8 *)(param_1 + 3000) = 0;
  *(undefined8 *)(param_1 + 0xbc0) = 0;
  *(undefined8 *)(param_1 + 0xbc8) = 0;
  *(undefined8 *)(param_1 + 0xbd0) = 0;
  *(undefined8 *)(param_1 + 0xbd8) = 0;
  *(undefined8 *)(param_1 + 0xbe0) = 0;
  *(undefined8 *)(param_1 + 0xbe8) = 0;
  *(undefined8 *)(param_1 + 0xbf0) = 0;
  *(undefined8 *)(param_1 + 0xbf8) = 0;
  *(undefined1 *)(param_1 + 0xb80) = 0xee;
  _local_48 = CONCAT62(0x20000,uVar2);
  local_40 = puVar1;
  iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x918) + 0x18),&local_48,1);
  if (iVar4 < 1) {
    _printk(&DAT_00105b45,"lt9611uxc_write_byte");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dump_info_store @ 001040cc size=172
// signature: undefined dump_info_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dump_info_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (lVar1 == 0) {
    _printk(&DAT_00105c7c,"dump_info_store");
    param_4 = 0xffffffffffffffea;
  }
  else {
    print_hex_dump(&DAT_00105432,&DAT_00105768,0,0x10,1,lVar1 + 0xa80,0x80,0);
    print_hex_dump(&DAT_00105432,&DAT_00105768,0,0x10,1,lVar1 + 0xb00,0x80,0);
  }
  return param_4;
}



//------------------------------------------------------------
// firmware_upgrade_show @ 0010417c size=60
// signature: undefined firmware_upgrade_show(void)
// callers: []
//------------------------------------------------------------

long firmware_upgrade_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001055e4,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0xc88))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// firmware_upgrade_store @ 001041bc size=172
// signature: undefined firmware_upgrade_store(void)
// callers: []
//------------------------------------------------------------

undefined8
firmware_upgrade_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    _printk(&DAT_00105c7c,"firmware_upgrade_store");
    param_4 = 0xffffffffffffffea;
  }
  else {
    iVar1 = request_firmware_nowait
                      (&__this_module,1,"lt9611uxc_fw.bin",*(long *)(lVar2 + 0x918) + 0x20,0xcc0,
                       lVar2,lt9611uxc_firmware_cb);
    if (iVar1 == 0) {
      _printk(&DAT_001060d9,"firmware_upgrade_store");
    }
    else {
      _printk(&DAT_001058ff,"firmware_upgrade_store",iVar1);
    }
  }
  return param_4;
}



//------------------------------------------------------------
// edid_mode_show @ 0010426c size=100
// signature: undefined edid_mode_show(void)
// callers: []
//------------------------------------------------------------

long edid_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  uVar1 = *(undefined2 *)(lVar5 + 0x944);
  uVar2 = *(undefined2 *)(lVar5 + 0x94e);
  uVar3 = drm_mode_vrefresh(lVar5 + 0x940);
  iVar4 = scnprintf(param_3,0x1000,"%dx%d@%d\n",uVar1,uVar2,uVar3);
  return (long)iVar4;
}



//------------------------------------------------------------
// edid_mode_store @ 001042d4 size=204
// signature: undefined edid_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 edid_mode_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_30 [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30[0] = 0;
  local_30[1] = 0;
  if (lVar2 == 0) {
    _printk(&DAT_00105c7c,"edid_mode_store");
    param_4 = 0xffffffffffffffea;
  }
  else {
    iVar1 = sscanf(param_3,"%d %d",local_30 + 1,local_30);
    if (((iVar1 == 2) && (local_30[1] != 0)) && (local_30[0] != 0)) {
      *(short *)(lVar2 + 0x9bc) = (short)local_30[1];
      *(short *)(lVar2 + 0x9c6) = (short)local_30[0];
      *(undefined1 *)(lVar2 + 0xc82) = 1;
    }
    else {
      param_4 = 0xffffffffffffffea;
      *(undefined1 *)(lVar2 + 0xc82) = 0;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// lt9611uxc_bridge_attach @ 001043a4 size=456
// signature: undefined lt9611uxc_bridge_attach(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong lt9611uxc_bridge_attach(long param_1)

{
  uint uVar1;
  char *pcVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_58 = _s_lt9611_001067f0;
  uStack_50 = DAT_001067f8;
  local_48 = DAT_00106800;
  uStack_40 = DAT_00106808;
  if (*(long *)(param_1 + 0x70) == 0) {
    __drm_err("Parent encoder object not found");
    uVar5 = 0xffffffed;
  }
  else {
    lVar3 = param_1 + 0x158;
    uVar1 = drm_connector_init(*(undefined8 *)(param_1 + 0x68),lVar3,lt9611uxc_connector_funcs,0xb);
    if (uVar1 == 0) {
      *(undefined ***)(param_1 + 0x760) = &lt9611uxc_connector_helper_funcs;
      uVar1 = drm_connector_register(lVar3);
      if (uVar1 == 0) {
        *(undefined1 *)(param_1 + 0x758) = 2;
        uVar1 = drm_connector_attach_encoder(lVar3,*(undefined8 *)(param_1 + 0x70));
        if (uVar1 == 0) {
          lVar3 = of_find_mipi_dsi_host_by_node(*(undefined8 *)(param_1 + 0x110));
          if (lVar3 == 0) {
            __drm_err("failed to find dsi host\n");
            uVar5 = 0xfffffdfb;
          }
          else {
            uVar4 = mipi_dsi_device_register_full(lVar3,&local_58);
            if (uVar4 < 0xfffffffffffff001) {
              *(undefined8 *)(uVar4 + 0x3b0) = 4;
              *(undefined8 *)(uVar4 + 0x3b8) = 0x15;
              uVar1 = mipi_dsi_attach(uVar4);
              if ((int)uVar1 < 0) {
                uVar5 = (ulong)uVar1;
                _printk(&DAT_00105a90,"lt9611uxc_bridge_attach");
                mipi_dsi_device_unregister(uVar4);
              }
              else {
                *(ulong *)(param_1 + 0x118) = uVar4;
                *(undefined1 *)(param_1 + 0xc7d) = 1;
                _printk(&DAT_001051f8,"lt9611uxc_bridge_attach");
                uVar5 = 0;
              }
            }
            else {
              __drm_err("failed to create dsi device\n");
              uVar5 = uVar4;
            }
          }
          goto LAB_00104488;
        }
        uVar5 = (ulong)uVar1;
        pcVar2 = "Failed to link up connector to encoder: %d\n";
      }
      else {
        uVar5 = (ulong)uVar1;
        pcVar2 = "Failed to register connector: %d\n";
      }
    }
    else {
      uVar5 = (ulong)uVar1;
      pcVar2 = "Failed to initialize connector: %d\n";
    }
    __drm_err(pcVar2,uVar5);
  }
LAB_00104488:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// lt9611uxc_bridge_mode_fixup @ 00104570 size=8
// signature: undefined lt9611uxc_bridge_mode_fixup(void)
// callers: []
//------------------------------------------------------------

undefined8 lt9611uxc_bridge_mode_fixup(void)

{
  return 1;
}



//------------------------------------------------------------
// lt9611uxc_bridge_disable @ 0010457c size=4
// signature: undefined lt9611uxc_bridge_disable(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_bridge_disable(void)

{
  return;
}



//------------------------------------------------------------
// lt9611uxc_bridge_post_disable @ 00104584 size=4
// signature: undefined lt9611uxc_bridge_post_disable(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_bridge_post_disable(void)

{
  return;
}



//------------------------------------------------------------
// lt9611uxc_bridge_mode_set @ 0010458c size=36
// signature: undefined lt9611uxc_bridge_mode_set(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_bridge_mode_set(long param_1,undefined8 param_2,undefined8 param_3)

{
  drm_mode_copy(param_1 + 0x938,param_3);
  return;
}



//------------------------------------------------------------
// lt9611uxc_bridge_pre_enable @ 001045b4 size=108
// signature: undefined lt9611uxc_bridge_pre_enable(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_bridge_pre_enable(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x8f0));
  gpiod_set_raw_value(uVar1,1);
  msleep(0x14);
  uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x8f0));
  gpiod_set_raw_value(uVar1,0);
  msleep(0x14);
  uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x8f0));
  gpiod_set_raw_value(uVar1,1);
  msleep(300);
  return;
}



//------------------------------------------------------------
// lt9611uxc_bridge_enable @ 00104624 size=4
// signature: undefined lt9611uxc_bridge_enable(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_bridge_enable(void)

{
  return;
}



//------------------------------------------------------------
// lt9611uxc_connector_detect @ 0010462c size=564
// signature: undefined lt9611uxc_connector_detect(void)
// callers: []
//------------------------------------------------------------

void lt9611uxc_connector_detect(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  undefined2 local_68;
  undefined6 uStack_66;
  undefined8 *local_60;
  undefined8 local_58;
  byte *local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  *(undefined4 *)(param_1 + 0x7c0) = 2;
  if ((param_2 & 1) == 0) {
    uVar5 = 1;
    *(undefined4 *)(param_1 + 0x7c0) = 1;
  }
  else {
    mutex_lock(param_1 + -0x30);
    lt9611uxc_ctl_en(param_1 + -0x160);
    puVar1 = (undefined8 *)(param_1 + 0xa20);
    uVar2 = *(undefined2 *)(*(long *)(param_1 + 0x7b8) + 2);
    *(undefined8 *)(param_1 + 0xa20) = 0;
    *(undefined8 *)(param_1 + 0xa28) = 0;
    *(undefined8 *)(param_1 + 0xa30) = 0;
    *(undefined8 *)(param_1 + 0xa38) = 0;
    *(undefined8 *)(param_1 + 0xa40) = 0;
    *(undefined8 *)(param_1 + 0xa48) = 0;
    *(undefined8 *)(param_1 + 0xa50) = 0;
    *(undefined8 *)(param_1 + 0xa58) = 0;
    *(undefined8 *)(param_1 + 0xa60) = 0;
    *(undefined8 *)(param_1 + 0xa68) = 0;
    *(undefined8 *)(param_1 + 0xa70) = 0;
    *(undefined8 *)(param_1 + 0xa78) = 0;
    *(undefined8 *)(param_1 + 0xa80) = 0;
    *(undefined8 *)(param_1 + 0xa88) = 0;
    *(undefined8 *)(param_1 + 0xa90) = 0;
    *(undefined2 *)(param_1 + 0xa20) = 0xb0ff;
    *(undefined8 *)(param_1 + 0xa98) = 0;
    _local_68 = CONCAT62(0x20000,uVar2);
    local_60 = puVar1;
    iVar4 = i2c_transfer(*(undefined8 *)(*(long *)(param_1 + 0x7b8) + 0x18),&local_68,1);
    if (iVar4 < 1) {
      _printk(&DAT_00105b45,"lt9611uxc_write_byte");
    }
    lVar6 = *(long *)(param_1 + 0x7b8);
    uVar2 = *(undefined2 *)(lVar6 + 2);
    uVar3 = *(undefined2 *)(lVar6 + 2);
    *(undefined8 *)(param_1 + 0xa90) = 0;
    *(undefined8 *)(param_1 + 0xa98) = 0;
    *(undefined8 *)(param_1 + 0xa80) = 0;
    *(undefined8 *)(param_1 + 0xa88) = 0;
    *(undefined8 *)(param_1 + 0xa70) = 0;
    *(undefined8 *)(param_1 + 0xa78) = 0;
    *(undefined8 *)(param_1 + 0xa60) = 0;
    *(undefined8 *)(param_1 + 0xa68) = 0;
    *(undefined8 *)(param_1 + 0xa50) = 0;
    *(undefined8 *)(param_1 + 0xa58) = 0;
    *(undefined8 *)(param_1 + 0xa40) = 0;
    *(undefined8 *)(param_1 + 0xa48) = 0;
    *(undefined8 *)(param_1 + 0xa30) = 0;
    *(undefined8 *)(param_1 + 0xa38) = 0;
    *puVar1 = 0;
    *(undefined8 *)(param_1 + 0xa28) = 0;
    *(undefined8 *)(param_1 + 0xb18) = 0;
    *(undefined8 *)(param_1 + 0xb10) = 0;
    *(undefined8 *)(param_1 + 0xb08) = 0;
    *(undefined8 *)(param_1 + 0xb00) = 0;
    *(undefined8 *)(param_1 + 0xaf8) = 0;
    *(undefined8 *)(param_1 + 0xaf0) = 0;
    *(undefined8 *)(param_1 + 0xae8) = 0;
    *(undefined8 *)(param_1 + 0xae0) = 0;
    *(undefined8 *)(param_1 + 0xad8) = 0;
    *(undefined8 *)(param_1 + 0xad0) = 0;
    *(undefined8 *)(param_1 + 0xac8) = 0;
    *(undefined8 *)(param_1 + 0xac0) = 0;
    *(undefined8 *)(param_1 + 0xab8) = 0;
    *(undefined8 *)(param_1 + 0xab0) = 0;
    *(undefined8 *)(param_1 + 0xaa8) = 0;
    *(undefined1 *)(param_1 + 0xa20) = 0x23;
    *(undefined8 *)(param_1 + 0xaa0) = 0;
    _local_68 = CONCAT62(0x10000,uVar2);
    local_58 = (ulong)CONCAT42(0x10001,uVar3);
    local_60 = puVar1;
    local_50 = (byte *)(param_1 + 0xaa0);
    iVar4 = i2c_transfer(*(undefined8 *)(lVar6 + 0x18),&local_68,2);
    if (iVar4 == 2) {
      if ((*(byte *)(param_1 + 0xaa0) >> 1 & 1) != 0) {
        *(undefined4 *)(param_1 + 0x7c0) = 1;
      }
    }
    else {
      _printk(&DAT_00106009,"lt9611uxc_read");
      _printk(&DAT_00106087,"lt9611uxc_connector_detect");
    }
    lt9611uxc_ctl_disable(param_1 + -0x160);
    mutex_unlock(param_1 + -0x30);
    msleep(0x32);
    uVar5 = *(undefined4 *)(param_1 + 0x7c0);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lt9611uxc_connector_get_modes @ 00104864 size=1928
// signature: undefined lt9611uxc_connector_get_modes(void)
// callers: []
//------------------------------------------------------------

undefined4 lt9611uxc_connector_get_modes(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  char cVar4;
  undefined2 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 uVar11;
  long lVar12;
  long *plVar13;
  undefined8 *puVar14;
  long *plVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar12 = sp_el0;
  puVar17 = param_1 + -6;
  local_58 = *(long *)(lVar12 + 0x638);
  plVar13 = param_1 + -0x2c;
  mutex_lock(puVar17);
  if ((*(char *)((long)param_1 + 0xb26) == '\0') && (*(char *)(param_1 + 0x164) == '\0')) {
    if ((*(char *)((long)param_1 + 0xb23) == '\0') && (*(char *)((long)param_1 + 0xb27) != '\0')) {
      *(undefined1 *)((long)param_1 + 0xb27) = 0;
      mutex_unlock(puVar17);
      if (*(char *)(param_1 + 0x164) == '\0') {
        local_68 = (undefined8 *)0x0;
        uStack_60 = 0;
        local_78 = (undefined8 *)0x0;
        local_70 = 0;
        local_80 = (char *)0x0;
        init_wait_entry(&local_80,0);
        puVar16 = param_1 + 0x121;
        prepare_to_wait_event(puVar16,&local_80,2);
        if (*(char *)(param_1 + 0x164) == '\0') {
          lVar12 = 500;
          do {
            lVar12 = schedule_timeout(lVar12);
            prepare_to_wait_event(puVar16,&local_80,2);
            if (lVar12 == 0 && *(char *)(param_1 + 0x164) != '\0') {
              lVar12 = 1;
            }
          } while ((*(char *)(param_1 + 0x164) == '\0') && (lVar12 != 0));
          finish_wait(puVar16,&local_80);
          if (lVar12 == 0) goto LAB_00104cb0;
        }
        else {
          finish_wait(puVar16,&local_80);
        }
      }
      goto LAB_001048c4;
    }
    mutex_unlock(puVar17);
  }
  else {
    *(undefined1 *)((long)param_1 + 0xb26) = 0;
    *(undefined1 *)(param_1 + 0x164) = 0;
    mutex_unlock(puVar17);
LAB_001048c4:
    if (param_1[-7] == 0) {
      mutex_lock(puVar17);
      lt9611uxc_ctl_en(plVar13);
      lt9611uxc_edid_en(plVar13);
      param_1[0x143] = 0;
      param_1[0x142] = 0;
      puVar16 = param_1 + 0x144;
      param_1[0x141] = 0;
      param_1[0x140] = 0;
      param_1[0x13f] = 0;
      param_1[0x13e] = 0;
      param_1[0x13d] = 0;
      param_1[0x13c] = 0;
      param_1[0x13b] = 0;
      param_1[0x13a] = 0;
      param_1[0x139] = 0;
      param_1[0x138] = 0;
      param_1[0x137] = 0;
      param_1[0x136] = 0;
      param_1[0x135] = 0;
      param_1[0x134] = 0;
      param_1[0x133] = 0;
      param_1[0x132] = 0;
      param_1[0x131] = 0;
      param_1[0x130] = 0;
      param_1[0x12f] = 0;
      param_1[0x12e] = 0;
      param_1[0x12d] = 0;
      param_1[300] = 0;
      param_1[299] = 0;
      param_1[0x12a] = 0;
      param_1[0x129] = 0;
      param_1[0x128] = 0;
      param_1[0x127] = 0;
      param_1[0x126] = 0;
      param_1[0x125] = 0;
      param_1[0x124] = 0;
      uVar5 = *(undefined2 *)(param_1[0xf7] + 2);
      param_1[0x144] = 0;
      param_1[0x145] = 0;
      param_1[0x146] = 0;
      param_1[0x147] = 0;
      param_1[0x148] = 0;
      param_1[0x149] = 0;
      param_1[0x14a] = 0;
      param_1[0x14b] = 0;
      param_1[0x14c] = 0;
      param_1[0x14d] = 0;
      param_1[0x14e] = 0;
      param_1[0x14f] = 0;
      param_1[0x150] = 0;
      param_1[0x151] = 0;
      param_1[0x152] = 0;
      *(undefined2 *)(param_1 + 0x144) = 0xb0ff;
      param_1[0x153] = 0;
      local_80 = (char *)CONCAT62(0x20000,uVar5);
      local_78 = puVar16;
      iVar8 = i2c_transfer(*(undefined8 *)(param_1[0xf7] + 0x18),&local_80,1);
      if (iVar8 < 1) {
        _printk(&DAT_00105b45,"lt9611uxc_write_byte");
      }
      puVar14 = param_1 + 0x154;
      uVar6 = *(ushort *)(param_1[0xf7] + 2);
      *puVar16 = 0;
      param_1[0x145] = 0;
      param_1[0x146] = 0;
      param_1[0x147] = 0;
      param_1[0x148] = 0;
      param_1[0x149] = 0;
      param_1[0x14a] = 0;
      param_1[0x14b] = 0;
      param_1[0x14c] = 0;
      param_1[0x14d] = 0;
      param_1[0x14e] = 0;
      param_1[0x14f] = 0;
      param_1[0x150] = 0;
      param_1[0x151] = 0;
      param_1[0x152] = 0;
      param_1[0x153] = 0;
      *(undefined1 *)(param_1 + 0x144) = 10;
      local_80._0_4_ = (uint)uVar6;
      local_80._0_6_ = CONCAT24(2,(uint)local_80);
      local_80 = (char *)(ulong)(uint6)local_80;
      local_78 = puVar16;
      iVar8 = i2c_transfer(*(undefined8 *)(param_1[0xf7] + 0x18),&local_80,1);
      if (iVar8 < 1) {
        _printk(&DAT_00105b45,"lt9611uxc_write_byte");
      }
      lVar12 = param_1[0xf7];
      uVar5 = *(undefined2 *)(lVar12 + 2);
      uVar7 = *(undefined2 *)(lVar12 + 2);
      param_1[0x152] = 0;
      param_1[0x153] = 0;
      param_1[0x150] = 0;
      param_1[0x151] = 0;
      param_1[0x14e] = 0;
      param_1[0x14f] = 0;
      param_1[0x14c] = 0;
      param_1[0x14d] = 0;
      param_1[0x14a] = 0;
      param_1[0x14b] = 0;
      param_1[0x148] = 0;
      param_1[0x149] = 0;
      param_1[0x146] = 0;
      param_1[0x147] = 0;
      *puVar16 = 0;
      param_1[0x145] = 0;
      param_1[0x162] = 0;
      param_1[0x163] = 0;
      param_1[0x160] = 0;
      param_1[0x161] = 0;
      param_1[0x15e] = 0;
      param_1[0x15f] = 0;
      param_1[0x15c] = 0;
      param_1[0x15d] = 0;
      param_1[0x15a] = 0;
      param_1[0x15b] = 0;
      param_1[0x158] = 0;
      param_1[0x159] = 0;
      param_1[0x156] = 0;
      param_1[0x157] = 0;
      *(undefined1 *)(param_1 + 0x144) = 0xb0;
      *puVar14 = 0;
      param_1[0x155] = 0;
      local_80 = (char *)CONCAT62(0x10000,uVar5);
      local_70._0_6_ = CONCAT42(0x800001,uVar7);
      local_70 = (ulong)(uint6)local_70;
      local_78 = puVar16;
      local_68 = puVar14;
      iVar8 = i2c_transfer(*(undefined8 *)(lVar12 + 0x18),&local_80,2);
      if (iVar8 == 2) {
        param_1[0x130] = param_1[0x160];
        param_1[0x131] = param_1[0x161];
        param_1[0x132] = param_1[0x162];
        param_1[0x133] = param_1[0x163];
        param_1[300] = param_1[0x15c];
        param_1[0x12d] = param_1[0x15d];
        param_1[0x12e] = param_1[0x15e];
        param_1[0x12f] = param_1[0x15f];
        param_1[0x128] = param_1[0x158];
        param_1[0x129] = param_1[0x159];
        param_1[0x12a] = param_1[0x15a];
        param_1[299] = param_1[0x15b];
        param_1[0x124] = *puVar14;
        param_1[0x125] = param_1[0x155];
        param_1[0x126] = param_1[0x156];
        param_1[0x127] = param_1[0x157];
        cVar4 = *(char *)((long)param_1 + 0x99e);
      }
      else {
        _printk(&DAT_00106009,"lt9611uxc_read");
        cVar4 = *(char *)((long)param_1 + 0x99e);
      }
      if (cVar4 != '\0') {
        uVar6 = *(ushort *)(param_1[0xf7] + 2);
        *puVar16 = 0;
        param_1[0x145] = 0;
        param_1[0x146] = 0;
        param_1[0x147] = 0;
        param_1[0x148] = 0;
        param_1[0x149] = 0;
        param_1[0x14a] = 0;
        param_1[0x14b] = 0;
        param_1[0x14c] = 0;
        param_1[0x14d] = 0;
        param_1[0x14e] = 0;
        param_1[0x14f] = 0;
        param_1[0x150] = 0;
        param_1[0x151] = 0;
        param_1[0x152] = 0;
        param_1[0x153] = 0;
        *(undefined2 *)(param_1 + 0x144) = 0x800a;
        local_80._0_4_ = (uint)uVar6;
        local_80._0_6_ = CONCAT24(2,(uint)local_80);
        local_80 = (char *)(ulong)(uint6)local_80;
        local_78 = puVar16;
        iVar8 = i2c_transfer(*(undefined8 *)(param_1[0xf7] + 0x18),&local_80,1);
        if (iVar8 < 1) {
          _printk(&DAT_00105b45,"lt9611uxc_write_byte");
        }
        lVar12 = param_1[0xf7];
        uVar5 = *(undefined2 *)(lVar12 + 2);
        uVar7 = *(undefined2 *)(lVar12 + 2);
        param_1[0x162] = 0;
        param_1[0x163] = 0;
        param_1[0x160] = 0;
        param_1[0x161] = 0;
        param_1[0x15e] = 0;
        param_1[0x15f] = 0;
        param_1[0x15c] = 0;
        param_1[0x15d] = 0;
        param_1[0x15a] = 0;
        param_1[0x15b] = 0;
        param_1[0x158] = 0;
        param_1[0x159] = 0;
        param_1[0x156] = 0;
        param_1[0x157] = 0;
        param_1[0x154] = 0;
        param_1[0x155] = 0;
        param_1[0x152] = 0;
        param_1[0x153] = 0;
        param_1[0x150] = 0;
        param_1[0x151] = 0;
        param_1[0x14e] = 0;
        param_1[0x14f] = 0;
        param_1[0x14c] = 0;
        param_1[0x14d] = 0;
        param_1[0x14a] = 0;
        param_1[0x14b] = 0;
        param_1[0x148] = 0;
        param_1[0x149] = 0;
        param_1[0x146] = 0;
        param_1[0x147] = 0;
        *puVar16 = 0;
        param_1[0x145] = 0;
        *(undefined1 *)(param_1 + 0x144) = 0xb0;
        local_80 = (char *)CONCAT62(0x10000,uVar5);
        local_70._0_6_ = CONCAT42(0x800001,uVar7);
        local_70 = (ulong)(uint6)local_70;
        local_78 = puVar16;
        local_68 = puVar14;
        iVar8 = i2c_transfer(*(undefined8 *)(lVar12 + 0x18),&local_80,2);
        if (iVar8 == 2) {
          param_1[0x140] = param_1[0x160];
          param_1[0x141] = param_1[0x161];
          param_1[0x142] = param_1[0x162];
          param_1[0x143] = param_1[0x163];
          param_1[0x13c] = param_1[0x15c];
          param_1[0x13d] = param_1[0x15d];
          param_1[0x13e] = param_1[0x15e];
          param_1[0x13f] = param_1[0x15f];
          param_1[0x138] = param_1[0x158];
          param_1[0x139] = param_1[0x159];
          param_1[0x13a] = param_1[0x15a];
          param_1[0x13b] = param_1[0x15b];
          param_1[0x134] = *puVar14;
          param_1[0x135] = param_1[0x155];
          param_1[0x136] = param_1[0x156];
          param_1[0x137] = param_1[0x157];
        }
        else {
          _printk(&DAT_00106009,"lt9611uxc_read");
        }
      }
      lt9611uxc_ctl_disable(plVar13);
      mutex_unlock(puVar17);
      uVar11 = drm_do_get_edid(param_1,lt9611uxc_get_edid_block,plVar13);
      param_1[-7] = uVar11;
    }
  }
LAB_00104cb0:
  if (param_1[-7] == 0) {
    for (plVar15 = (long *)param_1[0xfa]; plVar15 != param_1 + 0xfa; plVar15 = (long *)*plVar15) {
      lVar12 = drm_mode_duplicate(*param_1,plVar15 + -8);
      if (lVar12 == 0) {
        _printk(&DAT_0010526d,"lt9611uxc_connector_get_modes",*(undefined2 *)((long)plVar15 + -0x3c)
                ,*(undefined2 *)((long)plVar15 + -0x32));
        break;
      }
      drm_mode_probed_add(param_1,lVar12);
    }
    uVar9 = *(undefined4 *)(param_1 + 0xf9);
  }
  else {
    drm_connector_update_edid_property(param_1);
    uVar9 = drm_add_edid_modes(param_1,param_1[-7]);
  }
  local_80 = (char *)0x0;
  if (param_1[-7] == 0) {
    iVar8 = of_property_read_string(*(undefined8 *)(*plVar13 + 0x2e8),"lt,preferred-mode",&local_80)
    ;
    param_1 = param_1 + 0x19;
    if (iVar8 == 0) {
      for (puVar17 = (undefined8 *)*param_1; puVar17 != param_1; puVar17 = (undefined8 *)*puVar17) {
        iVar8 = strcmp((char *)(puVar17 + 2),local_80);
        if (iVar8 == 0) {
          *(byte *)((long)puVar17 + -2) = *(byte *)((long)puVar17 + -2) | 8;
        }
      }
      goto LAB_00104e30;
    }
    puVar17 = param_1;
    puVar16 = (undefined8 *)0x0;
    do {
      puVar14 = puVar16;
      puVar17 = (undefined8 *)*puVar17;
      puVar16 = puVar17 + -8;
    } while (puVar17 != param_1);
  }
  else {
    param_1 = param_1 + 0x19;
    puVar17 = (undefined8 *)*param_1;
    if (puVar17 == param_1) goto LAB_00104e30;
    puVar14 = puVar17 + -8;
    puVar16 = puVar14;
    do {
      puVar17 = (undefined8 *)*puVar17;
      *(byte *)((long)puVar16 + 0x3e) = *(byte *)((long)puVar16 + 0x3e) & 0xf7;
      if (puVar16 == puVar14) {
        puVar14 = puVar16;
      }
      else {
        puVar3 = puVar16;
        if ((int)((uint)*(ushort *)((long)puVar16 + 0xe) * (uint)*(ushort *)((long)puVar16 + 4)) <=
            (int)((uint)*(ushort *)((long)puVar14 + 0xe) * (uint)*(ushort *)((long)puVar14 + 4))) {
          puVar3 = puVar14;
        }
        iVar8 = drm_mode_vrefresh(puVar16);
        iVar10 = drm_mode_vrefresh(puVar3);
        puVar14 = puVar3;
        if ((uint)*(ushort *)((long)puVar16 + 0xe) * (uint)*(ushort *)((long)puVar16 + 4) ==
            (uint)*(ushort *)((long)puVar3 + 0xe) * (uint)*(ushort *)((long)puVar3 + 4)) {
          iVar1 = 0x3c - iVar8;
          if (-1 < iVar8 + -0x3c) {
            iVar1 = iVar8 + -0x3c;
          }
          iVar2 = 0x3c - iVar10;
          if (-1 < iVar10 + -0x3c) {
            iVar2 = iVar10 + -0x3c;
          }
          if (0x3c < iVar8 || iVar2 <= iVar1) {
            puVar16 = puVar3;
          }
          puVar14 = puVar16;
        }
      }
      puVar16 = puVar17 + -8;
    } while (puVar17 != param_1);
  }
  *(byte *)((long)puVar14 + 0x3e) = *(byte *)((long)puVar14 + 0x3e) | 8;
LAB_00104e30:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// lt9611uxc_connector_mode_valid @ 00104ff0 size=220
// signature: undefined lt9611uxc_connector_mode_valid(void)
// callers: []
//------------------------------------------------------------

undefined8 lt9611uxc_connector_mode_valid(long param_1,int *param_2)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  
  if (*(char *)(param_1 + 0xb22) == '\0') {
    plVar4 = (long *)*(long *)(param_1 + 2000);
    do {
      do {
        plVar1 = plVar4;
        if (plVar1 == (long *)(param_1 + 2000)) {
          return 0xfffffffe;
        }
        plVar4 = (long *)*plVar1;
      } while ((*(short *)((long)param_2 + 0xe) != *(short *)((long)plVar1 + -0x32)) ||
              ((short)param_2[1] != *(short *)((long)plVar1 + -0x3c)));
      iVar2 = drm_mode_vrefresh(param_2);
      iVar3 = drm_mode_vrefresh(plVar1 + -8);
    } while ((iVar2 != iVar3) || (*param_2 != *(int *)(plVar1 + -8)));
  }
  else if ((*(short *)((long)param_2 + 0xe) != *(short *)(param_1 + 0x866)) ||
          ((short)param_2[1] != *(short *)(param_1 + 0x85c))) {
    return 0xfffffffe;
  }
  return 0;
}



//------------------------------------------------------------
// lt9611uxc_get_edid_block @ 001050d0 size=68
// signature: undefined lt9611uxc_get_edid_block(void)
// callers: []
//------------------------------------------------------------

undefined8 lt9611uxc_get_edid_block(long param_1,void *param_2,int param_3,size_t param_4)

{
  code *pcVar1;
  
  if (0x100 < (uint)(param_3 << 7)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x105114);
    (*pcVar1)();
  }
  memcpy(param_2,(void *)(param_1 + (ulong)(uint)(param_3 << 7) + 0xa80),param_4);
  return 0;
}



//------------------------------------------------------------
// init_module @ 00105118 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&lt9611uxc_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105148 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&lt9611uxc_driver);
  return;
}



//------------------------------------------------------------
// kfree @ 00109000 size=1
// signature: undefined kfree(void)
// callers: [lt9611uxc_hpd_work, lt9611uxc_remove, lt9611uxc_probe, lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00109008 size=1
// signature: undefined scnprintf(void)
// callers: [lt9611uxc_hpd_work, edid_mode_show, firmware_upgrade_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_get_connector_status_name @ 00109010 size=1
// signature: undefined drm_get_connector_status_name(void)
// callers: [lt9611uxc_hpd_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_get_connector_status_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 00109018 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [lt9611uxc_hpd_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lt9611uxc_hpd_work, lt9611uxc_flash_write_addr_set, lt9611uxc_block_erase, lt9611uxc_flash_write_config, lt9611uxc_config, lt9611uxc_edid_en, lt9611uxc_ctl_disable, lt9611uxc_flash_read_addr_set, lt9611uxc_probe, lt9611uxc_ctl_en, lt9611uxc_get_version, lt9611uxc_fw_read_back, lt9611uxc_firmware_write, lt9611uxc_bridge_attach, lt9611uxc_connector_get_modes, edid_mode_store, lt9611uxc_flash_write_en, lt9611uxc_irq_thread_handler, lt9611uxc_firmware_upgrade, lt9611uxc_connector_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 00109028 size=1
// signature: undefined i2c_transfer(void)
// callers: [lt9611uxc_flash_write_addr_set, lt9611uxc_block_erase, lt9611uxc_flash_write_config, lt9611uxc_config, lt9611uxc_edid_en, lt9611uxc_ctl_disable, lt9611uxc_flash_read_addr_set, lt9611uxc_probe, lt9611uxc_ctl_en, lt9611uxc_get_version, lt9611uxc_fw_read_back, lt9611uxc_firmware_write, lt9611uxc_connector_get_modes, lt9611uxc_flash_write_en, lt9611uxc_irq_thread_handler, lt9611uxc_firmware_upgrade, lt9611uxc_connector_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109030 size=1
// signature: undefined _printk(void)
// callers: [lt9611uxc_put_dt_supply, lt9611uxc_block_erase, lt9611uxc_config, lt9611uxc_ctl_disable, lt9611uxc_ctl_en, lt9611uxc_gpio_configure, lt9611uxc_fw_read_back, edid_mode_store, lt9611uxc_connector_detect, lt9611uxc_flash_write_addr_set, lt9611uxc_flash_write_config, lt9611uxc_remove, lt9611uxc_edid_en, lt9611uxc_flash_read_addr_set, lt9611uxc_probe, firmware_upgrade_store, dump_info_store, lt9611uxc_firmware_cb, lt9611uxc_get_version, lt9611uxc_firmware_write, lt9611uxc_bridge_attach, lt9611uxc_connector_get_modes, lt9611uxc_flash_write_en, lt9611uxc_irq_thread_handler, lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00109038 size=1
// signature: undefined msleep(void)
// callers: [lt9611uxc_get_version, lt9611uxc_firmware_write, lt9611uxc_block_erase, lt9611uxc_flash_write_en, lt9611uxc_probe, lt9611uxc_irq_thread_handler, lt9611uxc_bridge_pre_enable, lt9611uxc_firmware_upgrade, lt9611uxc_connector_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00109040 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lt9611uxc_get_edid_block, lt9611uxc_firmware_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00109048 size=1
// signature: undefined fortify_panic(void)
// callers: [lt9611uxc_firmware_write, lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00109050 size=1
// signature: undefined __kmalloc(void)
// callers: [lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bcmp @ 00109058 size=1
// signature: int bcmp(void * __s1, void * __s2, size_t __n)
// callers: [lt9611uxc_firmware_upgrade]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 00109060 size=1
// signature: undefined i2c_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 00109068 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00109070 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_get_endpoint_by_regs @ 00109078 size=1
// signature: undefined of_graph_get_endpoint_by_regs(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_get_endpoint_by_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_get_remote_port_parent @ 00109080 size=1
// signature: undefined of_graph_get_remote_port_parent(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_get_remote_port_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00109088 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00109090 size=1
// signature: undefined of_find_property(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 00109098 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001090a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 001090a8 size=1
// signature: undefined of_get_next_child(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_mode_set_name @ 001090b0 size=1
// signature: undefined drm_mode_set_name(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_mode_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001090c0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001090c8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001090d0 size=1
// signature: undefined __list_add_valid(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001090d8 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 001090e0 size=1
// signature: undefined gpio_to_desc(void)
// callers: [lt9611uxc_gpio_configure, lt9611uxc_probe, lt9611uxc_bridge_pre_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 001090e8 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [lt9611uxc_probe, lt9611uxc_bridge_pre_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled @ 001090f0 size=1
// signature: undefined regulator_is_enabled(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001090f8 size=1
// signature: undefined usleep_range_state(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00109100 size=1
// signature: undefined regulator_set_load(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00109108 size=1
// signature: undefined regulator_enable(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00109110 size=1
// signature: undefined sysfs_create_group(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware_nowait @ 00109118 size=1
// signature: undefined request_firmware_nowait(void)
// callers: [lt9611uxc_probe, firmware_upgrade_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware_nowait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00109120 size=1
// signature: undefined regulator_disable(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 00109128 size=1
// signature: undefined regulator_get(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00109130 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [lt9611uxc_put_dt_supply, lt9611uxc_remove, lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00109138 size=1
// signature: undefined of_property_read_string(void)
// callers: [lt9611uxc_connector_get_modes, lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00109140 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00109148 size=1
// signature: undefined strscpy(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00109150 size=1
// signature: undefined __mutex_init(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00109158 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_bridge_add @ 00109160 size=1
// signature: undefined drm_bridge_add(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_bridge_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00109168 size=1
// signature: undefined alloc_workqueue(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 00109170 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00109178 size=1
// signature: undefined request_threaded_irq(void)
// callers: [lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00109180 size=1
// signature: undefined regulator_put(void)
// callers: [lt9611uxc_put_dt_supply, lt9611uxc_remove, lt9611uxc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mipi_dsi_detach @ 00109188 size=1
// signature: undefined mipi_dsi_detach(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mipi_dsi_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mipi_dsi_device_unregister @ 00109190 size=1
// signature: undefined mipi_dsi_device_unregister(void)
// callers: [lt9611uxc_bridge_attach, lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mipi_dsi_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_bridge_remove @ 00109198 size=1
// signature: undefined drm_bridge_remove(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_bridge_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 001091a0 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001091a8 size=1
// signature: undefined disable_irq(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 001091b0 size=1
// signature: undefined free_irq(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001091b8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001091c0 size=1
// signature: undefined destroy_workqueue(void)
// callers: [lt9611uxc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 001091c8 size=1
// signature: undefined gpio_request(void)
// callers: [lt9611uxc_gpio_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 001091d0 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [lt9611uxc_gpio_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 001091d8 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [lt9611uxc_gpio_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 001091e0 size=1
// signature: undefined gpio_free(void)
// callers: [lt9611uxc_gpio_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 001091e8 size=1
// signature: undefined release_firmware(void)
// callers: [lt9611uxc_firmware_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001091f0 size=1
// signature: undefined mutex_lock(void)
// callers: [lt9611uxc_connector_get_modes, lt9611uxc_irq_thread_handler, lt9611uxc_connector_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001091f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [lt9611uxc_connector_get_modes, lt9611uxc_irq_thread_handler, lt9611uxc_connector_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00109200 size=1
// signature: undefined __wake_up(void)
// callers: [lt9611uxc_irq_thread_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00109208 size=1
// signature: undefined queue_work_on(void)
// callers: [lt9611uxc_irq_thread_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 00109210 size=1
// signature: undefined print_hex_dump(void)
// callers: [dump_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_mode_vrefresh @ 00109218 size=1
// signature: undefined drm_mode_vrefresh(void)
// callers: [lt9611uxc_connector_get_modes, edid_mode_show, lt9611uxc_connector_mode_valid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_mode_vrefresh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00109220 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [edid_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_connector_init @ 00109228 size=1
// signature: undefined drm_connector_init(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_connector_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __drm_err @ 00109230 size=1
// signature: undefined __drm_err(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __drm_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_connector_register @ 00109238 size=1
// signature: undefined drm_connector_register(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_connector_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_connector_attach_encoder @ 00109240 size=1
// signature: undefined drm_connector_attach_encoder(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_connector_attach_encoder(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_mipi_dsi_host_by_node @ 00109248 size=1
// signature: undefined of_find_mipi_dsi_host_by_node(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_mipi_dsi_host_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mipi_dsi_device_register_full @ 00109250 size=1
// signature: undefined mipi_dsi_device_register_full(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mipi_dsi_device_register_full(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mipi_dsi_attach @ 00109258 size=1
// signature: undefined mipi_dsi_attach(void)
// callers: [lt9611uxc_bridge_attach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mipi_dsi_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_mode_copy @ 00109260 size=1
// signature: undefined drm_mode_copy(void)
// callers: [lt9611uxc_bridge_mode_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_mode_copy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_do_get_edid @ 00109268 size=1
// signature: undefined drm_do_get_edid(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_do_get_edid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_connector_update_edid_property @ 00109270 size=1
// signature: undefined drm_connector_update_edid_property(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_connector_update_edid_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_add_edid_modes @ 00109278 size=1
// signature: undefined drm_add_edid_modes(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_add_edid_modes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_mode_duplicate @ 00109280 size=1
// signature: undefined drm_mode_duplicate(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_mode_duplicate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_mode_probed_add @ 00109288 size=1
// signature: undefined drm_mode_probed_add(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_mode_probed_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00109290 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00109298 size=1
// signature: undefined init_wait_entry(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 001092a0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001092a8 size=1
// signature: undefined finish_wait(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 001092b0 size=1
// signature: undefined schedule_timeout(void)
// callers: [lt9611uxc_connector_get_modes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



