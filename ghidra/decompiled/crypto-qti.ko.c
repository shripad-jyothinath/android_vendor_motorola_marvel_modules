// Decompiled by Ghidra 12.2
// Program: crypto-qti.ko
// Image base: 00100000

//------------------------------------------------------------
// crypto_qti_init_crypto @ 001004e4 size=224
// signature: undefined crypto_qti_init_crypto(void)
// callers: []
//------------------------------------------------------------

undefined8 crypto_qti_init_crypto(long param_1)

{
  ulong uVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  uVar1 = readl_relaxed(param_1 + 8);
  uVar4 = uVar1 >> 0x18 & 0xff;
  if ((uint)uVar4 < 3) {
    _printk(&DAT_001019f6,"ice_check_version",param_1,uVar4,(uint)uVar1 >> 0x10 & 0xff,
            (uint)uVar1 & 0xffff);
    puVar2 = &DAT_00101b77;
    uVar3 = 0xffffffed;
    uVar5 = 0xffffffed;
  }
  else {
    uVar1 = readl_relaxed(param_1 + 8);
    if (((((uint)(uVar1 >> 0x18) & 0xff) == 3) && ((uVar1 & 0xfe0000) != 0)) ||
       (uVar1 = readl_relaxed(param_1 + 0x10), (uVar1 & 7) == 0)) {
      return 0;
    }
    _printk(&DAT_00102059,"ice_check_fuse_setting");
    puVar2 = &DAT_0010232d;
    uVar3 = 0xffffffff;
    uVar5 = 0xffffffff;
  }
  _printk(puVar2,"crypto_qti_init_crypto",uVar3);
  return uVar5;
}



//------------------------------------------------------------
// crypto_qti_enable @ 001005c8 size=172
// signature: undefined crypto_qti_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 crypto_qti_enable(long param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  
  uVar1 = readl_relaxed(param_1 + 0x1000);
  writel_relaxed(uVar1 | 0xd807100,param_1 + 0x1000);
  DataSynchronizationBarrier(3,2,0);
  iVar3 = 100;
  do {
    uVar2 = readl_relaxed(param_1 + 0x70);
    if ((uVar2 >> 0x1c & 0xf) == 0) {
      if ((int)uVar2 == 0) {
        return 0;
      }
      break;
    }
    __const_udelay(0x346de);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _printk(&DAT_00102087,"ice_wait_bist_status",uVar2 & 0xffffffff);
  return 0xffffff92;
}



//------------------------------------------------------------
// crypto_qti_disable @ 00100678 size=28
// signature: undefined crypto_qti_disable(void)
// callers: []
//------------------------------------------------------------

void crypto_qti_disable(void)

{
  crypto_qti_disable_platform();
  return;
}



//------------------------------------------------------------
// crypto_qti_resume @ 00100698 size=132
// signature: undefined crypto_qti_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 crypto_qti_resume(long param_1)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = 100;
  do {
    uVar1 = readl_relaxed(param_1 + 0x70);
    if ((uVar1 >> 0x1c & 0xf) == 0) {
      if ((int)uVar1 == 0) {
        return 0;
      }
      break;
    }
    __const_udelay(0x346de);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _printk(&DAT_00102087,"ice_wait_bist_status",uVar1 & 0xffffffff);
  return 0xffffff92;
}



//------------------------------------------------------------
// crypto_qti_debug @ 00100720 size=1812
// signature: undefined crypto_qti_debug(void)
// callers: []
//------------------------------------------------------------

undefined8 crypto_qti_debug(long *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  
  lVar4 = *param_1;
  _printk(&DAT_00102475,"crypto_qti_debug");
  uVar1 = readl_relaxed(lVar4);
  uVar2 = readl_relaxed(lVar4 + 4);
  _printk(&DAT_00101d1a,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 8);
  _printk(&DAT_00101eb2,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x14);
  uVar2 = readl_relaxed(lVar4 + 0x18);
  _printk(&DAT_00101991,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1c);
  uVar2 = readl_relaxed(lVar4 + 0x20);
  _printk(&DAT_00101965,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x24);
  uVar2 = readl_relaxed(lVar4 + 0x40);
  _printk(&DAT_00101aa1,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x44);
  uVar2 = readl_relaxed(lVar4 + 0x48);
  _printk(&DAT_0010240e,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x30);
  _printk(&DAT_00101fdc,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x40);
  _printk(&DAT_00101acf,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x70);
  uVar2 = readl_relaxed(lVar4 + 0x74);
  _printk(&DAT_00101dee,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1000);
  uVar2 = readl_relaxed(lVar4 + 0x1004);
  _printk(&DAT_00101b0e,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x50);
  uVar2 = readl_relaxed(lVar4 + 0x58);
  _printk(&DAT_00102375,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x54);
  uVar2 = readl_relaxed(lVar4 + 0x5c);
  _printk(&DAT_00101d45,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x80);
  uVar2 = readl_relaxed(lVar4 + 0x84);
  _printk(&DAT_00101e46,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1100);
  uVar2 = readl_relaxed(lVar4 + 0x1104);
  _printk(&DAT_001021ed,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1108);
  uVar2 = readl_relaxed(lVar4 + 0x110c);
  _printk(&DAT_0010227c,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1200);
  uVar2 = readl_relaxed(lVar4 + 0x1204);
  _printk(&DAT_0010243c,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1208);
  uVar2 = readl_relaxed(lVar4 + 0x120c);
  _printk(&DAT_00101f51,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1110);
  uVar2 = readl_relaxed(lVar4 + 0x1114);
  _printk(&DAT_00101b9b,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1118);
  uVar2 = readl_relaxed(lVar4 + 0x111c);
  _printk(&DAT_00102001,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1120);
  uVar2 = readl_relaxed(lVar4 + 0x1124);
  _printk(&DAT_001018c4,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1128);
  uVar2 = readl_relaxed(lVar4 + 0x112c);
  _printk(&DAT_00101bd4,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1130);
  uVar2 = readl_relaxed(lVar4 + 0x1134);
  _printk(&DAT_00102226,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1210);
  uVar2 = readl_relaxed(lVar4 + 0x1214);
  _printk(&DAT_00102176,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1218);
  uVar2 = readl_relaxed(lVar4 + 0x121c);
  _printk(&DAT_00101c0d,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1220);
  uVar2 = readl_relaxed(lVar4 + 0x1224);
  _printk(&DAT_001022b5,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1228);
  uVar2 = readl_relaxed(lVar4 + 0x122c);
  _printk(&DAT_001019bd,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x1230);
  uVar2 = readl_relaxed(lVar4 + 0x1234);
  _printk(&DAT_00101c9e,uVar1,uVar2);
  uVar1 = readl_relaxed(lVar4 + 0x123c);
  _printk(&DAT_0010234e,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x1248);
  _printk(&DAT_001018fd,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x1254);
  _printk(&DAT_001020d4,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x100);
  _printk(&DAT_00101d80,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x104);
  _printk(&DAT_001023b0,uVar1);
  uVar1 = readl_relaxed(lVar4 + 0x1400);
  _printk(&DAT_00101b40,uVar1);
  uVar3 = readl_relaxed(lVar4 + 8);
  if (((uVar3 & 0xfe0000) == 0 || ((uint)(uVar3 >> 0x18) & 0xff) != 3) && ((uint)uVar3 >> 0x1a == 0)
     ) {
    uVar3 = 0;
    lVar6 = lVar4 + 0x2044;
    do {
      uVar1 = readl_relaxed(lVar6 + -4);
      _printk(&DAT_001020fa,uVar3 & 0xffffffff,uVar1);
      uVar1 = readl_relaxed(lVar6);
      _printk(&DAT_00101e20,uVar3 & 0xffffffff,uVar1);
      uVar3 = uVar3 + 1;
      lVar6 = lVar6 + 0x80;
    } while (uVar3 != 0x20);
  }
  else {
    uVar3 = 0;
    lVar6 = lVar4 + 0x4044;
    do {
      uVar1 = readl_relaxed(lVar6 + -4);
      _printk(&DAT_001020fa,uVar3 & 0xffffffff,uVar1);
      uVar1 = readl_relaxed(lVar6);
      _printk(&DAT_00101e20,uVar3 & 0xffffffff,uVar1);
      uVar3 = uVar3 + 1;
      lVar6 = lVar6 + 0x80;
    } while (uVar3 != 0x40);
  }
  _printk(&DAT_001023f8);
  iVar7 = 0x10;
  iVar5 = 1;
  do {
    if (iVar7 != 3) {
      writel_relaxed(iVar5,lVar4 + 0x1010);
      DataSynchronizationBarrier(3,2,0);
      uVar1 = readl_relaxed(lVar4 + 0x1014);
      _printk(&DAT_00101edb,iVar5,uVar1);
    }
    iVar7 = iVar7 + -1;
    iVar5 = iVar5 + 0x10000000;
  } while (iVar7 != 0);
  _printk(&DAT_00101a6b);
  uVar8 = 0;
  do {
    writel_relaxed(uVar8 | 0xd0000001,lVar4 + 0x1010);
    DataSynchronizationBarrier(3,2,0);
    uVar1 = readl_relaxed(lVar4 + 0x1014);
    _printk(&DAT_00101edb,uVar8 | 0xd0000001,uVar1);
    uVar8 = uVar8 + 0x10000;
  } while (uVar8 != 0x100000);
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00100e34 size=124
// signature: undefined readl_relaxed(void)
// callers: [crypto_qti_enable, crypto_qti_resume, crypto_qti_init_crypto, crypto_qti_debug]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100e7c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// crypto_qti_keyslot_program @ 00100eb4 size=148
// signature: undefined crypto_qti_keyslot_program(void)
// callers: []
//------------------------------------------------------------

int crypto_qti_keyslot_program
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = crypto_qti_program_key();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _printk(&DAT_00101cd7,"crypto_qti_keyslot_program",iVar1);
    iVar1 = crypto_qti_invalidate_key(param_1,param_3,param_6);
    if (iVar1 != 0) {
      _printk(&DAT_001023cd,"crypto_qti_keyslot_program",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// crypto_qti_keyslot_evict @ 00100f4c size=76
// signature: undefined crypto_qti_keyslot_evict(void)
// callers: []
//------------------------------------------------------------

int crypto_qti_keyslot_evict(void)

{
  int iVar1;
  
  iVar1 = crypto_qti_invalidate_key();
  if (iVar1 != 0) {
    _printk(&DAT_001023cd,"crypto_qti_keyslot_evict",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// crypto_qti_derive_raw_secret @ 00100f9c size=132
// signature: undefined crypto_qti_derive_raw_secret(void)
// callers: []
//------------------------------------------------------------

undefined8
crypto_qti_derive_raw_secret
          (undefined8 param_1,undefined8 *param_2,ulong param_3,undefined8 *param_4,uint param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  
  if ((uint)param_3 < 0x21) {
    puVar4 = &DAT_001021af;
  }
  else {
    if (param_5 == 0x20) {
      if ((uint)param_3 < 0x41) {
        uVar1 = param_2[3];
        uVar3 = *param_2;
        uVar2 = param_2[1];
        param_4[2] = param_2[2];
        param_4[3] = uVar1;
        *param_4 = uVar3;
        param_4[1] = uVar2;
        return 0;
      }
      uVar3 = crypto_qti_derive_raw_secret_platform();
      return uVar3;
    }
    puVar4 = &DAT_0010203a;
    param_3 = (ulong)param_5;
  }
  _printk(puVar4,"crypto_qti_derive_raw_secret",param_3);
  return 0xffffffea;
}



//------------------------------------------------------------
// writel_relaxed @ 00101020 size=132
// signature: undefined writel_relaxed(void)
// callers: [crypto_qti_enable, crypto_qti_debug]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101038,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101074,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_crypto_hibernate_restore @ 001010a8 size=108
// signature: undefined qcom_crypto_hibernate_restore(void)
// callers: []
//------------------------------------------------------------

int qcom_crypto_hibernate_restore(void)

{
  int iVar1;
  
  iVar1 = qcom_scm_hibernate_exit();
  if (iVar1 != 0) {
    if (iVar1 == -5) {
      _printk(&DAT_00101e81,"crypto_qti_hibernate_exit");
    }
    else {
      _printk(&DAT_00101949,"crypto_qti_hibernate_exit",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// crypto_qti_get_hwkm_raw_secret_tz @ 0010111c size=324
// signature: undefined crypto_qti_get_hwkm_raw_secret_tz(void)
// callers: [crypto_qti_derive_raw_secret_platform]
//------------------------------------------------------------

int crypto_qti_get_hwkm_raw_secret_tz(void *param_1,ulong param_2,void *param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_68;
  void *local_60;
  undefined8 local_58;
  undefined8 local_50;
  void *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  param_2 = param_2 & 0xffffffff;
  local_38 = *(long *)(lVar1 + 0x638);
  param_4 = param_4 & 0xffffffff;
  local_48 = (void *)0x0;
  uStack_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = (void *)0x0;
  iVar2 = qtee_shmbridge_allocate_shm(param_2,&local_50);
  if (iVar2 == 0) {
    iVar2 = qtee_shmbridge_allocate_shm(param_4,&local_68);
    if (iVar2 == 0) {
      memcpy(local_48,param_1,param_2);
      qtee_shmbridge_flush_shm_buf(&local_50);
      memset(local_60,0,param_4);
      qtee_shmbridge_flush_shm_buf(&local_68);
      iVar2 = qcom_scm_derive_raw_secret(local_50,param_2,local_68,param_4);
      if (iVar2 == 0) {
        qtee_shmbridge_inv_shm_buf(&local_68);
        memcpy(param_3,local_60,param_4);
        qtee_shmbridge_inv_shm_buf(&local_50);
      }
      else {
        _printk(&DAT_00101f8a,"crypto_qti_get_hwkm_raw_secret_tz",iVar2);
      }
      qtee_shmbridge_free_shm(&local_50);
      puVar3 = &local_68;
    }
    else {
      iVar2 = -0xc;
      puVar3 = &local_50;
    }
    qtee_shmbridge_free_shm(puVar3);
  }
  else {
    iVar2 = -0xc;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// crypto_qti_program_key @ 00101264 size=652
// signature: undefined crypto_qti_program_key(void)
// callers: [crypto_qti_keyslot_program]
//------------------------------------------------------------

int crypto_qti_program_key(long *param_1,long param_2,int param_3,uint param_4,uint param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined *puVar6;
  undefined8 local_70;
  void *local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  uVar2 = *(uint *)(param_2 + 0x14);
  if (uVar2 < 0x21) {
    puVar6 = &DAT_00102310;
LAB_001014d8:
    _printk(puVar6,"crypto_qti_program_key",uVar2);
    iVar3 = -0x16;
    goto LAB_001013e4;
  }
  uVar5 = qti_hwkm_init_required();
  if (((uVar5 & 1) != 0) || (uVar5 = qti_hwkm_is_ice_tpkey_set(param_1), (uVar5 & 1) == 0)) {
    uVar2 = qti_hwkm_init(param_1);
    if (uVar2 != 0) {
      puVar6 = &DAT_00101aef;
      goto LAB_001014d8;
    }
    qti_hwkm_init_done = 1;
    offset = 0;
    iVar3 = qti_hwkm_get_reg_data(param_1[1],0,0x10,0xff0000,0x80);
    iVar4 = qti_hwkm_get_reg_data(param_1[1],0,0x18,0xff000000,0x80);
    if (iVar4 == 1) {
      offset = 10;
    }
    else if ((iVar4 == 2) && (offset = 0, iVar3 < 1)) {
      offset = 10;
    }
  }
  uVar5 = (ulong)(param_3 * 0x80 + 0x4040);
  writel_relaxed(0,*param_1 + uVar5);
  iVar4 = offset;
  DataSynchronizationBarrier(3,2,0);
  local_68 = (void *)0x0;
  uStack_60 = 0;
  local_70 = 0;
  iVar3 = qtee_shmbridge_allocate_shm(*(undefined4 *)(param_2 + 0x14),&local_70);
  if (iVar3 == 0) {
    iVar4 = iVar4 + param_3 * 2;
    memcpy(local_68,(void *)(param_2 + 0x18),(ulong)*(uint *)(param_2 + 0x14));
    qtee_shmbridge_flush_shm_buf(&local_70);
    iVar3 = qcom_scm_config_set_ice_key(iVar4,local_70,*(undefined4 *)(param_2 + 0x14),0,0,0);
    if (iVar3 == 0) {
      qtee_shmbridge_inv_shm_buf(&local_70);
      qtee_shmbridge_free_shm(&local_70);
    }
    else {
      _printk(&DAT_00101dba,"crypto_qti_program_hwkm_tz",iVar3);
      _printk(&DAT_00101f16,"print_key",iVar4);
      if (*(int *)(param_2 + 0x14) != 0) {
        uVar2 = 0;
        do {
          _printk(&DAT_00102148,uVar2,*(undefined1 *)(param_2 + (int)uVar2 + 0x18));
          uVar2 = uVar2 + 1;
        } while (uVar2 < *(uint *)(param_2 + 0x14));
      }
      qtee_shmbridge_inv_shm_buf(&local_70);
      qtee_shmbridge_free_shm(&local_70);
      if (iVar3 != 0) goto LAB_0010142c;
    }
    writel_relaxed(param_4 & 0xff | (param_5 & 0xff) << 8 | 0x80000000,*param_1 + uVar5);
    DataSynchronizationBarrier(3,2,0);
    iVar3 = 0;
  }
  else {
    iVar3 = -0xc;
LAB_0010142c:
    _printk(&DAT_00101a3a,"crypto_qti_program_key",iVar3);
  }
LAB_001013e4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// writel_relaxed @ 001014f0 size=132
// signature: undefined writel_relaxed(void)
// callers: [crypto_qti_program_key]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101508,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101544,uVar1);
  return;
}



//------------------------------------------------------------
// crypto_qti_invalidate_key @ 00101578 size=148
// signature: undefined crypto_qti_invalidate_key(void)
// callers: [crypto_qti_keyslot_program, crypto_qti_keyslot_evict]
//------------------------------------------------------------

int crypto_qti_invalidate_key(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (qti_hwkm_init_done == '\x01') {
    iVar1 = qcom_scm_clear_ice_key(offset + param_2 * 2,0);
    iVar2 = 0;
    if (iVar1 != 0) {
      _printk(&DAT_0010249d,"crypto_qti_hwkm_evict_slot",iVar1);
      _printk(&DAT_00102120,"crypto_qti_invalidate_key",iVar1,param_2);
      iVar2 = iVar1;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// crypto_qti_disable_platform @ 00101610 size=12
// signature: undefined crypto_qti_disable_platform(void)
// callers: [crypto_qti_disable]
//------------------------------------------------------------

void crypto_qti_disable_platform(void)

{
  qti_hwkm_init_done = 0;
  return;
}



//------------------------------------------------------------
// crypto_qti_derive_raw_secret_platform @ 00101620 size=296
// signature: undefined crypto_qti_derive_raw_secret_platform(void)
// callers: [crypto_qti_derive_raw_secret]
//------------------------------------------------------------

int crypto_qti_derive_raw_secret_platform
              (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
              undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  if ((qti_hwkm_init_done & 1) == 0) {
    iVar1 = qti_hwkm_init();
    if (iVar1 != 0) {
      _printk(&DAT_00101aef,"crypto_qti_derive_raw_secret_platform",iVar1);
      return -0x16;
    }
    qti_hwkm_init_done = 1;
    offset = 0;
    iVar1 = qti_hwkm_get_reg_data(*(undefined8 *)(param_1 + 8),0,0x10,0xff0000,0x80);
    iVar2 = qti_hwkm_get_reg_data(*(undefined8 *)(param_1 + 8),0,0x18,0xff000000,0x80);
    if (iVar2 == 1) {
      offset = 10;
    }
    else if ((iVar2 == 2) && (offset = 0, iVar1 < 1)) {
      offset = 10;
    }
  }
  iVar1 = crypto_qti_get_hwkm_raw_secret_tz(param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    _printk(&DAT_00101c60,"crypto_qti_derive_raw_secret_platform",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00101870 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qti_crypto_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001018a0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qti_crypto_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00104000 size=1
// signature: undefined _printk(void)
// callers: [crypto_qti_keyslot_program, crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_enable, crypto_qti_resume, crypto_qti_init_crypto, crypto_qti_keyslot_evict, crypto_qti_invalidate_key, crypto_qti_derive_raw_secret, crypto_qti_derive_raw_secret_platform, qcom_crypto_hibernate_restore, crypto_qti_debug, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00104008 size=1
// signature: undefined __const_udelay(void)
// callers: [crypto_qti_enable, crypto_qti_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00104010 size=1
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
// log_post_read_mmio @ 00104018 size=1
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
// __platform_driver_register @ 00104020 size=1
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
// platform_driver_unregister @ 00104028 size=1
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
// log_write_mmio @ 00104030 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00104038 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_hibernate_exit @ 00104040 size=1
// signature: undefined qcom_scm_hibernate_exit(void)
// callers: [qcom_crypto_hibernate_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_hibernate_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_allocate_shm @ 00104048 size=1
// signature: undefined qtee_shmbridge_allocate_shm(void)
// callers: [crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_allocate_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104050 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_flush_shm_buf @ 00104058 size=1
// signature: undefined qtee_shmbridge_flush_shm_buf(void)
// callers: [crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_flush_shm_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104060 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [crypto_qti_get_hwkm_raw_secret_tz]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_derive_raw_secret @ 00104068 size=1
// signature: undefined qcom_scm_derive_raw_secret(void)
// callers: [crypto_qti_get_hwkm_raw_secret_tz]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_derive_raw_secret(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_inv_shm_buf @ 00104070 size=1
// signature: undefined qtee_shmbridge_inv_shm_buf(void)
// callers: [crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_inv_shm_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_free_shm @ 00104078 size=1
// signature: undefined qtee_shmbridge_free_shm(void)
// callers: [crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_free_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [crypto_qti_get_hwkm_raw_secret_tz, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_hwkm_init_required @ 00104088 size=1
// signature: undefined qti_hwkm_init_required(void)
// callers: [crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_hwkm_init_required(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_hwkm_is_ice_tpkey_set @ 00104090 size=1
// signature: undefined qti_hwkm_is_ice_tpkey_set(void)
// callers: [crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_hwkm_is_ice_tpkey_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_hwkm_init @ 00104098 size=1
// signature: undefined qti_hwkm_init(void)
// callers: [crypto_qti_derive_raw_secret_platform, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_hwkm_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_hwkm_get_reg_data @ 001040a0 size=1
// signature: undefined qti_hwkm_get_reg_data(void)
// callers: [crypto_qti_derive_raw_secret_platform, crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_hwkm_get_reg_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_config_set_ice_key @ 001040a8 size=1
// signature: undefined qcom_scm_config_set_ice_key(void)
// callers: [crypto_qti_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_config_set_ice_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_clear_ice_key @ 001040b0 size=1
// signature: undefined qcom_scm_clear_ice_key(void)
// callers: [crypto_qti_invalidate_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_clear_ice_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



