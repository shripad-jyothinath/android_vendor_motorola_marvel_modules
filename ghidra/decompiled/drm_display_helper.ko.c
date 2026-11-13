// Decompiled by Ghidra 12.2
// Program: drm_display_helper.ko
// Image base: 00100000

//------------------------------------------------------------
// drm_dp_dual_mode_read @ 0010306c size=292
// signature: undefined drm_dp_dual_mode_read(void)
// callers: []
//------------------------------------------------------------

void drm_dp_dual_mode_read(undefined8 param_1,byte param_2,void *param_3,size_t param_4)

{
  long lVar1;
  int iVar2;
  void *pvVar3;
  long lVar4;
  undefined1 local_6c [4];
  undefined8 local_68;
  undefined1 *puStack_60;
  undefined4 local_58;
  uint uStack_54;
  void *local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = param_2 + param_4;
  puStack_60 = local_6c;
  local_6c[0] = 0;
  local_68 = 0x100000040;
  _local_58 = CONCAT44((uint)lVar4 & 0xffff,0x10040);
  local_50 = param_3;
  if (param_2 == 0) {
    iVar2 = i2c_transfer(param_1,&local_68,2);
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)__kmalloc(lVar4,0xcc0);
    if (pvVar3 == (void *)0x0) {
      lVar4 = -0xc;
      goto LAB_0010315c;
    }
    local_50 = pvVar3;
    iVar2 = i2c_transfer(param_1,&local_68,2);
    memcpy(param_3,(void *)((long)pvVar3 + (ulong)param_2),param_4);
  }
  kfree(pvVar3);
  if (iVar2 < 0) {
    lVar4 = (long)iVar2;
  }
  else {
    lVar4 = 0;
    if (iVar2 != 2) {
      lVar4 = -0x47;
    }
  }
LAB_0010315c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_dual_mode_write @ 00103194 size=228
// signature: undefined drm_dp_dual_mode_write(void)
// callers: []
//------------------------------------------------------------

void drm_dp_dual_mode_write(undefined8 param_1,undefined1 param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  long lVar5;
  undefined8 local_58;
  undefined1 *local_50;
  long local_48;
  
  lVar5 = sp_el0;
  uVar1 = (int)param_4 + 1;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = (ulong)CONCAT24((short)uVar1,0x40);
  puVar4 = (undefined1 *)__kmalloc(uVar1 & 0xffff,0xcc0);
  if (puVar4 == (undefined1 *)0x0) {
    lVar5 = -0xc;
  }
  else {
    *puVar4 = param_2;
    local_50 = puVar4;
    memcpy(puVar4 + 1,param_3,param_4);
    iVar3 = i2c_transfer(param_1,&local_58,1);
    kfree(puVar4);
    if (iVar3 < 0) {
      lVar5 = (long)iVar3;
    }
    else {
      lVar5 = 0;
      if (iVar3 != 1) {
        lVar5 = -0x47;
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_dual_mode_detect @ 0010327c size=636
// signature: undefined drm_dp_dual_mode_detect(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_dual_mode_detect(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  char cVar6;
  long lVar7;
  undefined1 local_7c [4];
  long local_78;
  long lStack_70;
  undefined8 local_68;
  undefined1 *local_60;
  undefined8 local_58;
  long *local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_60 = local_7c;
  local_78 = 0;
  lStack_70 = 0;
  local_7c[0] = 0;
  local_68 = 0x100000040;
  local_50 = &local_78;
  local_58 = 0x1000010040;
  iVar2 = i2c_transfer(param_2,&local_68,2);
  kfree(0);
  lVar7 = 0;
  if (iVar2 != 2) {
    lVar7 = -0x47;
  }
  lVar1 = (long)iVar2;
  if (-1 < iVar2) {
    lVar1 = lVar7;
  }
  if (param_1 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 8);
  }
  __drm_dev_dbg(0,uVar4,2,"DP dual mode HDMI ID: %*pE (err %zd)\n",(ulong)(lVar1 == 0) << 4,
                &local_78,lVar1);
  uVar5 = 1;
  if (lVar1 != 0) goto LAB_0010349c;
  local_60 = local_7c;
  local_68 = 0x100000040;
  local_7c[0] = 0;
  local_58 = 0x1100010040;
  plVar3 = (long *)kmalloc_trace(_mutex_unlock,0xcc0,0x11);
  if (plVar3 == (long *)0x0) {
    cVar6 = '\0';
    lVar7 = -0xc;
joined_r0x001033ec:
    if (param_1 != 0) goto LAB_001033f0;
LAB_00103400:
    uVar4 = 0;
  }
  else {
    local_50 = plVar3;
    iVar2 = i2c_transfer(param_2,&local_68,2);
    cVar6 = (char)plVar3[2];
    kfree(plVar3);
    if (iVar2 < 0) {
      lVar7 = (long)iVar2;
      goto joined_r0x001033ec;
    }
    lVar7 = 0;
    if (iVar2 != 2) {
      lVar7 = -0x47;
    }
    if (param_1 == 0) goto LAB_00103400;
LAB_001033f0:
    uVar4 = *(undefined8 *)(param_1 + 8);
  }
  __drm_dev_dbg(0,uVar4,2,"DP dual mode adaptor ID: %02x (err %zd)\n",cVar6,lVar7);
  if (lVar7 == 0) {
    if ((cVar6 == -0x58) && (local_78 == 0x20494d44482d5044 && lStack_70 == 0x4524f5450414441)) {
      uVar5 = 6;
      goto LAB_0010349c;
    }
    if (cVar6 == -0x60) {
      uVar5 = 4;
      if (local_78 == 0x20494d44482d5044 && lStack_70 == 0x4524f5450414441) {
        uVar5 = 5;
      }
      goto LAB_0010349c;
    }
    if (1 < (byte)(cVar6 + 1U)) {
      _dev_err(*(undefined8 *)(param_1 + 8),
               "[drm] *ERROR* Unexpected DP dual mode adaptor ID %02x\n",cVar6);
    }
  }
  uVar5 = 2;
  if (local_78 == 0x20494d44482d5044 && lStack_70 == 0x4524f5450414441) {
    uVar5 = 3;
  }
LAB_0010349c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_dual_mode_max_tmds_clock @ 001034fc size=316
// signature: undefined drm_dp_dual_mode_max_tmds_clock(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_dual_mode_max_tmds_clock(long param_1,uint param_2,undefined8 param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  undefined1 local_6c [4];
  undefined8 local_68;
  undefined1 *puStack_60;
  undefined8 local_58;
  long local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  if (param_2 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0x28488;
    if (3 < param_2) {
      puStack_60 = local_6c;
      local_68 = 0x100000040;
      local_58 = 0x1e00010040;
      local_6c[0] = 0;
      lVar3 = kmalloc_trace(_mutex_unlock,0xcc0,0x1e);
      if (lVar3 != 0) {
        local_50 = lVar3;
        iVar2 = i2c_transfer(param_3,&local_68,2);
        bVar1 = *(byte *)(lVar3 + 0x1d);
        kfree(lVar3);
        if (((iVar2 == 2) && (bVar1 != 0xff)) && (bVar1 != 0)) {
          iVar5 = (uint)bVar1 * 0x9c4;
          goto LAB_001035f4;
        }
      }
      if (param_1 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined8 *)(param_1 + 8);
      }
      __drm_dev_dbg(0,uVar4,2,"Failed to query max TMDS clock\n");
    }
  }
LAB_001035f4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// drm_dp_dual_mode_get_tmds_output @ 0010363c size=320
// signature: undefined drm_dp_dual_mode_get_tmds_output(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_dual_mode_get_tmds_output(long param_1,uint param_2,undefined8 param_3,byte *param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  byte bVar4;
  undefined1 local_6c [4];
  undefined8 local_68;
  undefined1 *puStack_60;
  undefined8 local_58;
  long local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  if (param_2 < 4) {
    bVar4 = 1;
LAB_00103674:
    iVar1 = 0;
    *param_4 = bVar4;
    goto LAB_00103744;
  }
  puStack_60 = local_6c;
  local_68 = 0x100000040;
  local_58 = 0x2100010040;
  local_6c[0] = 0;
  lVar2 = kmalloc_trace(_mutex_unlock,0xcc0,0x21);
  if (lVar2 == 0) {
    iVar1 = -0xc;
LAB_00103718:
    if (param_1 == 0) goto LAB_0010372c;
LAB_0010371c:
    uVar3 = *(undefined8 *)(param_1 + 8);
  }
  else {
    local_50 = lVar2;
    iVar1 = i2c_transfer(param_3,&local_68,2);
    bVar4 = *(byte *)(lVar2 + 0x20);
    kfree(lVar2);
    if (iVar1 < 0) goto LAB_00103718;
    if (iVar1 == 2) {
      bVar4 = (bVar4 ^ 0xff) & 1;
      goto LAB_00103674;
    }
    iVar1 = -0x47;
    if (param_1 != 0) goto LAB_0010371c;
LAB_0010372c:
    uVar3 = 0;
  }
  __drm_dev_dbg(0,uVar3,2,"Failed to query state of TMDS output buffers\n");
LAB_00103744:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dp_dual_mode_set_tmds_output @ 00103780 size=636
// signature: undefined drm_dp_dual_mode_set_tmds_output(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_dual_mode_set_tmds_output(long param_1,uint param_2,undefined8 param_3,byte param_4)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined8 uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  byte local_90 [4];
  undefined1 local_8c [4];
  undefined8 local_88;
  undefined1 *local_80;
  undefined8 local_78;
  byte *local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  if (param_2 < 4) {
LAB_001037b8:
    iVar3 = 0;
  }
  else {
    bVar1 = (param_4 ^ 0xff) & 1;
    iVar10 = 1;
    do {
      local_90[0] = 0;
      local_88 = 0x200000040;
      puVar4 = (undefined1 *)kmalloc_trace(_mutex_unlock,0xcc0,2);
      if (puVar4 == (undefined1 *)0x0) {
        iVar3 = -0xc;
LAB_001038f4:
        if (param_1 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined8 *)(param_1 + 8);
        }
        pcVar8 = "disable";
        pcVar9 = "enable";
        pcVar7 = "Failed to %s TMDS output buffers (%d attempts)\n";
LAB_0010396c:
        if ((param_4 & 1) == 0) {
          pcVar9 = pcVar8;
        }
        __drm_dev_dbg(0,uVar6,2,pcVar7,pcVar9,iVar10);
        goto LAB_00103980;
      }
      *puVar4 = 0x20;
      puVar4[1] = bVar1;
      local_80 = puVar4;
      iVar3 = i2c_transfer(param_3,&local_88,1);
      kfree(puVar4);
      if (iVar3 < 0) goto LAB_001038f4;
      if (iVar3 != 1) {
        iVar3 = -0x47;
        goto LAB_001038f4;
      }
      local_8c[0] = 0;
      local_80 = local_8c;
      local_88 = 0x100000040;
      local_78 = 0x2100010040;
      local_70 = local_90;
      pbVar5 = (byte *)kmalloc_trace(_mutex_unlock,0xcc0,0x21);
      if (pbVar5 == (byte *)0x0) {
        iVar3 = -0xc;
LAB_00103938:
        if (param_1 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined8 *)(param_1 + 8);
        }
        pcVar8 = "disabling";
        pcVar9 = "enabling";
        pcVar7 = "I2C read failed during TMDS output buffer %s (%d attempts)\n";
        goto LAB_0010396c;
      }
      local_70 = pbVar5;
      iVar3 = i2c_transfer(param_3,&local_88,2);
      local_90[0] = pbVar5[0x20];
      kfree(pbVar5);
      if (iVar3 < 0) goto LAB_00103938;
      if (iVar3 != 2) {
        iVar3 = -0x47;
        goto LAB_00103938;
      }
      if (local_90[0] == bVar1) goto LAB_001037b8;
      iVar10 = iVar10 + 1;
    } while (iVar10 != 4);
    if (param_1 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined8 *)(param_1 + 8);
    }
    pcVar9 = "enabling";
    if ((param_4 & 1) == 0) {
      pcVar9 = "disabling";
    }
    __drm_dev_dbg(0,uVar6,2,"I2C write value mismatch during TMDS output buffer %s\n",pcVar9);
    iVar3 = -5;
  }
LAB_00103980:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// drm_dp_get_dual_mode_type_name @ 00103a00 size=36
// signature: undefined drm_dp_get_dual_mode_type_name(void)
// callers: []
//------------------------------------------------------------

undefined * drm_dp_get_dual_mode_type_name(uint param_1)

{
  code *pcVar1;
  
  if (6 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103a24);
    (*pcVar1)();
  }
  return (&PTR_DAT_001158a0)[(int)param_1];
}



//------------------------------------------------------------
// drm_lspcon_get_mode @ 00103a2c size=540
// signature: undefined drm_lspcon_get_mode(void)
// callers: [drm_lspcon_set_mode]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_lspcon_get_mode(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  byte local_90 [4];
  undefined1 local_8c [4];
  undefined8 local_88;
  undefined1 *puStack_80;
  undefined8 local_78;
  byte *local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_90[0] = 0;
  if (param_3 == (undefined4 *)0x0) {
    _dev_err(*(undefined8 *)(param_1 + 8),"[drm] *ERROR* NULL input\n");
    uVar5 = 0xffffffea;
  }
  else {
    puStack_80 = local_8c;
    local_88 = 0x100000040;
    local_8c[0] = 0;
    local_78 = 0x4200010040;
    pbVar4 = (byte *)kmalloc_trace(_drm_display_mode_from_cea_vic,0xcc0,0x42);
    if (pbVar4 != (byte *)0x0) {
      local_70 = pbVar4;
      iVar2 = i2c_transfer(param_2,&local_88,2);
      local_90[0] = pbVar4[0x41];
      kfree(pbVar4);
      if (iVar2 == 2) {
LAB_00103ba8:
        uVar5 = 0;
        uVar6 = 1;
        if ((local_90[0] & 1) != 0) {
          uVar6 = 2;
        }
        *param_3 = uVar6;
        goto LAB_00103bf4;
      }
    }
    iVar2 = 1;
    do {
      while( true ) {
        usleep_range_state(500,1000,2);
        local_8c[0] = 0;
        local_88 = 0x100000040;
        local_78 = 0x4200010040;
        puStack_80 = local_8c;
        local_70 = local_90;
        pbVar4 = (byte *)kmalloc_trace(_drm_display_mode_from_cea_vic,0xcc0,0x42);
        if (pbVar4 == (byte *)0x0) break;
        local_70 = pbVar4;
        iVar3 = i2c_transfer(param_2,&local_88,2);
        local_90[0] = pbVar4[0x41];
        kfree(pbVar4);
        if (iVar3 == 2) goto LAB_00103ba8;
        iVar2 = iVar2 + 1;
        if (iVar2 == 6) {
          if (iVar3 == 2) goto LAB_00103ba8;
          goto LAB_00103bc8;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 6);
LAB_00103bc8:
    if (param_1 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined8 *)(param_1 + 8);
    }
    __drm_dev_dbg(0,uVar5,2,"LSPCON read(0x80, 0x41) failed\n");
    uVar5 = 0xfffffff2;
  }
LAB_00103bf4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// drm_lspcon_set_mode @ 00103c4c size=416
// signature: undefined drm_lspcon_set_mode(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_lspcon_set_mode(long param_1,undefined8 param_2,int param_3)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  int iVar6;
  int local_5c;
  undefined8 local_58;
  undefined1 *local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_5c = 0;
  local_58 = 0x200000040;
  puVar4 = (undefined1 *)kmalloc_trace(_mutex_unlock,0xcc0,2);
  if (puVar4 == (undefined1 *)0x0) {
    iVar3 = -0xc;
  }
  else {
    *puVar4 = 0x40;
    puVar4[1] = param_3 == 2;
    local_50 = puVar4;
    iVar3 = i2c_transfer(param_2,&local_58,1);
    kfree(puVar4);
    iVar6 = 0;
    if (iVar3 != 1) {
      iVar6 = -0x47;
    }
    if (-1 < iVar3) {
      iVar3 = iVar6;
    }
    if (-1 < iVar3) {
      iVar6 = -200;
      do {
        iVar3 = drm_lspcon_get_mode(param_1,param_2,&local_5c);
        if (iVar3 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 8),"[drm] *ERROR* can\'t confirm LSPCON mode change\n")
          ;
          goto LAB_00103d84;
        }
        if (local_5c == param_3) {
          if (param_1 == 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = *(undefined8 *)(param_1 + 8);
          }
          puVar1 = &DAT_001152c4;
          if (param_3 != 1) {
            puVar1 = &DAT_001138d8;
          }
          __drm_dev_dbg(0,uVar5,2,"LSPCON mode changed to %s\n",puVar1);
          iVar3 = 0;
          goto LAB_00103d84;
        }
        msleep(10);
        iVar6 = iVar6 + 10;
      } while (iVar6 != 0);
      _dev_err(*(undefined8 *)(param_1 + 8),"[drm] *ERROR* LSPCON mode change timed out\n");
      iVar3 = -0x6e;
      goto LAB_00103d84;
    }
  }
  _dev_err(*(undefined8 *)(param_1 + 8),"[drm] *ERROR* LSPCON mode change failed\n");
LAB_00103d84:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// drm_dp_channel_eq_ok @ 00103df0 size=100
// signature: undefined drm_dp_channel_eq_ok(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_channel_eq_ok(long param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  
  if ((*(byte *)(param_1 + 2) & 1) == 0) {
    return false;
  }
  if (param_2 < 1) {
    return true;
  }
  uVar3 = 0;
  uVar5 = 0;
  do {
    uVar1 = uVar3 & 4;
    uVar3 = uVar3 + 4;
    iVar4 = (int)uVar5;
    bVar2 = (*(byte *)(param_1 + (uVar5 >> 1)) >> (ulong)uVar1 & 7) == 7;
    uVar5 = (ulong)(iVar4 + 1);
  } while (bVar2 && param_2 + -1 != iVar4);
  return bVar2;
}



//------------------------------------------------------------
// drm_dp_clock_recovery_ok @ 00103e58 size=96
// signature: undefined drm_dp_clock_recovery_ok(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_clock_recovery_ok(byte *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((int)param_2 < 1) {
    return true;
  }
  if ((*param_1 & 1) == 0) {
    return false;
  }
  uVar3 = 4;
  uVar2 = 1;
  do {
    uVar4 = uVar2;
    if (param_2 == uVar4) break;
    uVar1 = uVar3 & 4;
    uVar3 = uVar3 + 4;
    uVar2 = uVar4 + 1;
  } while ((param_1[uVar4 >> 1] >> (ulong)uVar1 & 1) != 0);
  return (int)param_2 <= (int)uVar4;
}



//------------------------------------------------------------
// drm_dp_get_adjust_request_voltage @ 00103ebc size=28
// signature: undefined drm_dp_get_adjust_request_voltage(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_get_adjust_request_voltage(long param_1,uint param_2)

{
  return *(byte *)(param_1 + ((int)param_2 >> 1) + 4) >> (ulong)((param_2 & 1) << 2) & 3;
}



//------------------------------------------------------------
// drm_dp_get_adjust_request_pre_emphasis @ 00103edc size=40
// signature: undefined drm_dp_get_adjust_request_pre_emphasis(void)
// callers: []
//------------------------------------------------------------

int drm_dp_get_adjust_request_pre_emphasis(long param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = 2;
  if ((param_2 & 1) != 0) {
    lVar1 = 6;
  }
  return (*(byte *)(param_1 + ((int)param_2 >> 1) + 4) >> lVar1 & 3) << 3;
}



//------------------------------------------------------------
// drm_dp_get_adjust_tx_ffe_preset @ 00103f08 size=28
// signature: undefined drm_dp_get_adjust_tx_ffe_preset(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_get_adjust_tx_ffe_preset(long param_1,uint param_2)

{
  return *(byte *)(param_1 + ((int)param_2 >> 1) + 4) >> (ulong)((param_2 & 1) << 2) & 0xf;
}



//------------------------------------------------------------
// drm_dp_128b132b_lane_channel_eq_done @ 00103f28 size=104
// signature: undefined drm_dp_128b132b_lane_channel_eq_done(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_128b132b_lane_channel_eq_done(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  if ((*(byte *)(param_1 + 2) & 1) == 0) {
    return false;
  }
  if (param_2 < 1) {
    return true;
  }
  uVar2 = 0;
  uVar4 = 0;
  do {
    uVar1 = uVar2 & 4;
    iVar3 = (int)uVar4;
    uVar2 = uVar2 + 4;
    uVar1 = 2 << (ulong)uVar1 & (uint)*(byte *)(param_1 + (uVar4 >> 1));
    uVar4 = (ulong)(iVar3 + 1);
  } while (uVar1 != 0 && param_2 + -1 != iVar3);
  return uVar1 != 0;
}



//------------------------------------------------------------
// drm_dp_128b132b_lane_symbol_locked @ 00103f94 size=96
// signature: undefined drm_dp_128b132b_lane_symbol_locked(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_128b132b_lane_symbol_locked(byte *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((int)param_2 < 1) {
    return true;
  }
  if ((*param_1 >> 2 & 1) == 0) {
    return false;
  }
  uVar3 = 4;
  uVar2 = 1;
  do {
    uVar4 = uVar2;
    if (param_2 == uVar4) break;
    uVar1 = uVar3 & 4;
    uVar3 = uVar3 + 4;
    uVar2 = uVar4 + 1;
  } while (((param_1[uVar4 >> 1] >> (ulong)uVar1) >> 2 & 1) != 0);
  return (int)param_2 <= (int)uVar4;
}



//------------------------------------------------------------
// drm_dp_128b132b_eq_interlane_align_done @ 00103ff8 size=12
// signature: undefined drm_dp_128b132b_eq_interlane_align_done(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_128b132b_eq_interlane_align_done(long param_1)

{
  return *(byte *)(param_1 + 2) >> 2 & 1;
}



//------------------------------------------------------------
// drm_dp_128b132b_cds_interlane_align_done @ 00104008 size=12
// signature: undefined drm_dp_128b132b_cds_interlane_align_done(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_128b132b_cds_interlane_align_done(long param_1)

{
  return *(byte *)(param_1 + 2) >> 3 & 1;
}



//------------------------------------------------------------
// drm_dp_128b132b_link_training_failed @ 00104018 size=12
// signature: undefined drm_dp_128b132b_link_training_failed(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_128b132b_link_training_failed(long param_1)

{
  return *(byte *)(param_1 + 2) >> 4 & 1;
}



//------------------------------------------------------------
// drm_dp_read_clock_recovery_delay @ 00104028 size=304
// signature: undefined drm_dp_read_clock_recovery_delay(void)
// callers: []
//------------------------------------------------------------

void drm_dp_read_clock_recovery_delay(undefined8 *param_1,byte *param_2,int param_3,ulong param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  code *pcVar5;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c[0] = 0;
  if (param_3 == 0) {
    if (((param_4 & 1) != 0) || (0x13 < *param_2)) goto LAB_0010408c;
    uVar4 = 0xe;
    pcVar5 = __8b10b_clock_recovery_delay_us;
LAB_001040cc:
    local_2c[0] = param_2[uVar4];
  }
  else {
    if ((param_4 & 1) == 0) {
LAB_0010408c:
      uVar3 = 100;
      goto LAB_001040f8;
    }
    uVar1 = param_3 * 0x50 + 0xeffd2;
    uVar4 = (ulong)uVar1;
    if (uVar1 < 0xf) {
      pcVar5 = __128b132b_channel_eq_delay_us;
      goto LAB_001040cc;
    }
    lVar2 = drm_dp_dpcd_read(param_1,uVar4,local_2c,1);
    if (lVar2 != 1) {
      if (param_1[0x9a] == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"%s: failed rd interval read\n",*param_1);
      uVar3 = 400;
      goto LAB_001040f8;
    }
    pcVar5 = __128b132b_channel_eq_delay_us;
  }
  if (*(int *)(pcVar5 + -4) != -0x686d8604) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x1040f4);
    (*pcVar5)();
  }
  uVar3 = (*pcVar5)(param_1,local_2c[0] & 0x7f);
LAB_001040f8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_read_channel_eq_delay @ 0010415c size=308
// signature: undefined drm_dp_read_channel_eq_delay(void)
// callers: []
//------------------------------------------------------------

void drm_dp_read_channel_eq_delay(undefined8 *param_1,long param_2,int param_3,ulong param_4)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  bool bVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  byte local_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_2c[0] = 0;
  if (param_3 == 0) {
    if ((param_4 & 1) != 0) {
      uVar7 = 0x2216;
      pcVar3 = __128b132b_channel_eq_delay_us;
      goto LAB_001041d4;
    }
    uVar7 = 0xe;
    pcVar3 = __8b10b_channel_eq_delay_us;
LAB_00104214:
    local_2c[0] = *(byte *)(param_2 + uVar7);
  }
  else {
    bVar4 = (param_4 & 1) == 0;
    iVar1 = 0xeffd2;
    if (bVar4) {
      iVar1 = 0xeffd0;
    }
    uVar2 = iVar1 + param_3 * 0x50;
    uVar7 = (ulong)uVar2;
    pcVar3 = __128b132b_channel_eq_delay_us;
    if (bVar4) {
      pcVar3 = __8b10b_channel_eq_delay_us;
    }
    if (uVar2 < 0xf) goto LAB_00104214;
LAB_001041d4:
    lVar5 = drm_dp_dpcd_read(param_1,uVar7,local_2c,1);
    if (lVar5 != 1) {
      if (param_1[0x9a] == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar6,2,"%s: failed rd interval read\n",*param_1);
      uVar6 = 400;
      goto LAB_00104264;
    }
  }
  if (*(int *)(pcVar3 + -4) != -0x686d8604) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8234,0x10423c);
    (*pcVar3)();
  }
  uVar6 = (*pcVar3)(param_1,local_2c[0] & 0x7f);
LAB_00104264:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_128b132b_read_aux_rd_interval @ 00104294 size=172
// signature: undefined drm_dp_128b132b_read_aux_rd_interval(void)
// callers: []
//------------------------------------------------------------

int drm_dp_128b132b_read_aux_rd_interval(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  lVar1 = drm_dp_dpcd_read(param_1,0x2216,local_2c,1);
  if (lVar1 == 1) {
    iVar2 = (local_2c[0] & 0x7f) + 1;
    if ((char)local_2c[0] < '\0') {
      iVar3 = 1000;
      goto LAB_001042f0;
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1[0x9a] + 8),"[drm] *ERROR* %s: failed rd interval read\n",
             *param_1);
    iVar2 = 0x80;
  }
  iVar3 = 2000;
LAB_001042f0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3 * iVar2;
}



//------------------------------------------------------------
// drm_dp_link_train_clock_recovery_delay @ 00104344 size=152
// signature: undefined drm_dp_link_train_clock_recovery_delay(void)
// callers: []
//------------------------------------------------------------

void drm_dp_link_train_clock_recovery_delay(undefined8 *param_1,byte *param_2)

{
  uint uVar1;
  byte bVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (*param_2 < 0x14) {
    bVar2 = param_2[0xe];
    uVar1 = bVar2 & 0x7f;
    if (4 < uVar1) {
      if (param_1[0x9a] == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"%s: invalid AUX interval 0x%02x (max 4)\n",*param_1,uVar1);
    }
    iVar4 = 100;
    if ((bVar2 & 0x7f) != 0) {
      iVar4 = uVar1 * 4000;
    }
  }
  else {
    iVar4 = 100;
  }
  usleep_range_state(iVar4,iVar4 << 1,2);
  return;
}



//------------------------------------------------------------
// __8b10b_clock_recovery_delay_us @ 001043e0 size=116
// signature: undefined __8b10b_clock_recovery_delay_us(void)
// callers: []
//------------------------------------------------------------

int __8b10b_clock_recovery_delay_us(undefined8 *param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar1 = (uint)param_2;
  if (4 < uVar1) {
    if (param_1[0x9a] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar3,2,"%s: invalid AUX interval 0x%02x (max 4)\n",*param_1,uVar1);
  }
  iVar2 = 100;
  if (param_2 != 0) {
    iVar2 = uVar1 * 4000;
  }
  return iVar2;
}



//------------------------------------------------------------
// drm_dp_link_train_channel_eq_delay @ 00104458 size=128
// signature: undefined drm_dp_link_train_channel_eq_delay(void)
// callers: []
//------------------------------------------------------------

void drm_dp_link_train_channel_eq_delay(undefined8 *param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined8 uVar4;
  
  bVar3 = *(byte *)(param_2 + 0xe);
  uVar1 = bVar3 & 0x7f;
  if (4 < uVar1) {
    if (param_1[0x9a] == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar4,2,"%s: invalid AUX interval 0x%02x (max 4)\n",*param_1,uVar1);
  }
  iVar2 = 400;
  if ((bVar3 & 0x7f) != 0) {
    iVar2 = uVar1 * 4000;
  }
  usleep_range_state(iVar2,iVar2 << 1,2);
  return;
}



//------------------------------------------------------------
// drm_dp_phy_name @ 001044dc size=36
// signature: undefined drm_dp_phy_name(void)
// callers: []
//------------------------------------------------------------

char * drm_dp_phy_name(uint param_1)

{
  if (param_1 < 9) {
    return (&drm_dp_phy_name_phy_names)[param_1];
  }
  return "<INVALID DP PHY>";
}



//------------------------------------------------------------
// drm_dp_lttpr_link_train_clock_recovery_delay @ 00104504 size=40
// signature: undefined drm_dp_lttpr_link_train_clock_recovery_delay(void)
// callers: []
//------------------------------------------------------------

void drm_dp_lttpr_link_train_clock_recovery_delay(void)

{
  usleep_range_state(100,200,2);
  return;
}



//------------------------------------------------------------
// drm_dp_lttpr_link_train_channel_eq_delay @ 00104530 size=128
// signature: undefined drm_dp_lttpr_link_train_channel_eq_delay(void)
// callers: []
//------------------------------------------------------------

void drm_dp_lttpr_link_train_channel_eq_delay(undefined8 *param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  undefined8 uVar4;
  
  bVar3 = *param_2;
  uVar1 = bVar3 & 0x7f;
  if (4 < uVar1) {
    if (param_1[0x9a] == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar4,2,"%s: invalid AUX interval 0x%02x (max 4)\n",*param_1,uVar1);
  }
  iVar2 = 400;
  if ((bVar3 & 0x7f) != 0) {
    iVar2 = uVar1 * 4000;
  }
  usleep_range_state(iVar2,iVar2 << 1,2);
  return;
}



//------------------------------------------------------------
// drm_dp_link_rate_to_bw_code @ 001045b4 size=100
// signature: undefined drm_dp_link_rate_to_bw_code(void)
// callers: []
//------------------------------------------------------------

int drm_dp_link_rate_to_bw_code(int param_1)

{
  if (param_1 == 1000000) {
    return 1;
  }
  if (param_1 == 2000000) {
    return 2;
  }
  if (param_1 == 0x149970) {
    return 4;
  }
  return param_1 / 27000;
}



//------------------------------------------------------------
// drm_dp_bw_code_to_link_rate @ 0010461c size=80
// signature: undefined drm_dp_bw_code_to_link_rate(void)
// callers: []
//------------------------------------------------------------

int drm_dp_bw_code_to_link_rate(byte param_1)

{
  if (param_1 == 1) {
    return 1000000;
  }
  if (param_1 == 2) {
    return 2000000;
  }
  if (param_1 == 4) {
    return 0x149970;
  }
  return (uint)param_1 * 27000;
}



//------------------------------------------------------------
// drm_dp_dpcd_probe @ 00104670 size=284
// signature: undefined drm_dp_dpcd_probe(void)
// callers: [drm_dp_dpcd_read]
//------------------------------------------------------------

void drm_dp_dpcd_probe(undefined8 *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  long lVar6;
  undefined1 local_3c [4];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_3c[0] = 0;
  iVar2 = drm_dp_dpcd_access(param_1,9,param_2,local_3c,1);
  if (iVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x104728);
    (*pcVar1)();
  }
  lVar6 = param_1[0x9a];
  if (iVar2 < 1) {
    if (lVar6 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(lVar6 + 8);
    }
    uVar5 = *param_1;
    pcVar4 = "%s: 0x%05x AUX %s (ret=%3d)\n";
  }
  else {
    if (lVar6 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(lVar6 + 8);
    }
    uVar5 = *param_1;
    pcVar4 = "%s: 0x%05x AUX %s (ret=%3d) %*ph\n";
  }
  __drm_dev_dbg(0,uVar3,8,pcVar4,uVar5,param_2,&DAT_001152e0,iVar2);
  lVar6 = sp_el0;
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_dpcd_access @ 00104794 size=348
// signature: undefined drm_dp_dpcd_access(void)
// callers: [drm_dp_dpcd_write, drm_dp_dpcd_read, drm_dp_dpcd_probe]
//------------------------------------------------------------

uint drm_dp_dpcd_access(undefined8 *param_1,undefined1 param_2,undefined4 param_3,undefined8 param_4
                       ,ulong param_5)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  undefined8 local_60;
  undefined8 uStack_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_60 = (ulong)CONCAT14(param_2,param_3);
  uStack_58 = param_4;
  local_50 = param_5;
  mutex_lock(param_1 + 0x9c);
  if (*(char *)((long)param_1 + 0x629) == '\0') {
    uVar3 = 0;
    iVar7 = 0x20;
    uVar6 = 0;
    do {
      if ((uVar3 != 0xffffff92) && (uVar3 != 0)) {
        usleep_range_state(500,600,2);
      }
      if (*(int *)((code *)param_1[0xa9] + -4) != 0x432a15d1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104854);
        (*pcVar2)();
      }
      uVar4 = (*(code *)param_1[0xa9])(param_1,&local_60);
      uVar3 = uVar4;
      if (-1 < (int)uVar4) {
        if ((local_60 & 0x30000000000) == 0) {
          if (param_5 == uVar4) goto LAB_001048a8;
          uVar3 = 0xffffffb9;
        }
        else {
          uVar3 = 0xfffffffb;
        }
      }
      uVar4 = uVar3;
      if (uVar6 != 0) {
        uVar4 = uVar6;
      }
      iVar7 = iVar7 + -1;
      uVar6 = uVar4;
    } while (iVar7 != 0);
    if (param_1[0x9a] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar5,2,"%s: Too many retries, giving up. First error: %d\n",*param_1,uVar4);
  }
  else {
    uVar4 = 0xfffffff0;
  }
LAB_001048a8:
  mutex_unlock(param_1 + 0x9c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// drm_dp_dpcd_set_powered @ 001048f4 size=84
// signature: undefined drm_dp_dpcd_set_powered(void)
// callers: []
//------------------------------------------------------------

void drm_dp_dpcd_set_powered(long param_1,byte param_2)

{
  if (param_1 != 0) {
    mutex_lock(param_1 + 0x4e0);
    *(byte *)(param_1 + 0x629) = (param_2 ^ 0xff) & 1;
    mutex_unlock(param_1 + 0x4e0);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_dpcd_read @ 0010494c size=316
// signature: undefined drm_dp_dpcd_read(void)
// callers: [drm_dp_dpcd_read_phy_link_status, drm_dp_read_clock_recovery_delay, drm_dp_read_dpcd_caps, drm_dp_mst_dump_topology, drm_dp_128b132b_read_aux_rd_interval, drm_dp_downstream_debug, drm_dp_read_mst_cap, drm_dp_pcon_frl_configure_1, drm_dp_pcon_pps_default, drm_dp_pcon_pps_override_param, drm_edp_backlight_set_enable, drm_dp_mst_topology_mgr_resume, drm_dp_aux_crc_work, drm_dp_dpcd_read_link_status, drm_dp_check_act_status, drm_dp_downstream_id, drm_panel_dp_aux_backlight, drm_dp_pcon_is_frl_ready, drm_dp_stop_crc, drm_dp_read_channel_eq_delay, drm_dp_get_one_sb_msg, drm_dp_pcon_hdmi_frl_link_error_count, drm_edp_backlight_init, drm_dp_start_crc, drm_dp_read_desc, drm_dp_pcon_pps_override_buf, drm_dp_read_sink_count, drm_dp_get_phy_test_pattern, drm_dp_pcon_convert_rgb_to_ycbcr, drm_dp_send_real_edid_checksum, drm_dp_dpcd_write_payload, drm_dp_pcon_hdmi_link_mode, drm_dp_pcon_hdmi_link_active, drm_dp_read_lttpr_phy_caps, drm_dp_mst_dsc_aux_for_port, drm_dp_pcon_frl_enable, drm_dp_read_lttpr_common_caps, drm_dp_read_downstream_info]
//------------------------------------------------------------

long drm_dp_dpcd_read(undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (*(char *)(param_1 + 0xc5) == '\0') {
    iVar1 = drm_dp_dpcd_probe(param_1,0);
    if (iVar1 < 0) goto LAB_00104a68;
    if (*(char *)(param_1 + 0xc5) != '\0') goto LAB_00104980;
    iVar1 = drm_dp_dpcd_access(param_1,9,param_2,param_3,param_4);
  }
  else {
LAB_00104980:
    iVar1 = drm_dp_mst_dpcd_read(param_1,param_2,param_3,param_4);
  }
  lVar5 = param_1[0x9a];
  if (iVar1 < 1) {
    if (lVar5 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar5 + 8);
    }
    uVar4 = *param_1;
    pcVar3 = "%s: 0x%05x AUX %s (ret=%3d)\n";
  }
  else {
    if (lVar5 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar5 + 8);
    }
    uVar4 = *param_1;
    pcVar3 = "%s: 0x%05x AUX %s (ret=%3d) %*ph\n";
  }
  __drm_dev_dbg(0,uVar2,8,pcVar3,uVar4,param_2,&DAT_001152e0,iVar1);
LAB_00104a68:
  return (long)iVar1;
}



//------------------------------------------------------------
// drm_dp_dpcd_write @ 00104a8c size=264
// signature: undefined drm_dp_dpcd_write(void)
// callers: [drm_dp_pcon_reset_frl_config, drm_dp_stop_crc, drm_dp_pcon_frl_configure_2, drm_edp_backlight_init, drm_dp_start_crc, drm_dp_pcon_pps_override_buf, drm_edp_backlight_set_level, drm_dp_pcon_frl_prepare, drm_dp_pcon_convert_rgb_to_ycbcr, drm_dp_mst_topology_mgr_set_mst, drm_dp_send_real_edid_checksum, drm_dp_pcon_pps_default, drm_dp_pcon_pps_override_param, drm_dp_pcon_frl_configure_1, drm_dp_dpcd_write_payload, drm_edp_backlight_set_enable, drm_dp_mst_topology_mgr_resume, dp_aux_backlight_update_status, drm_dp_mst_topology_mgr_suspend, drm_edp_backlight_enable, process_single_tx_qlock, drm_dp_pcon_frl_enable, drm_dp_send_link_address, drm_dp_set_phy_test_pattern]
//------------------------------------------------------------

long drm_dp_dpcd_write(undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (*(char *)(param_1 + 0xc5) == '\0') {
    iVar1 = drm_dp_dpcd_access(param_1,8,param_2,param_3);
  }
  else {
    iVar1 = drm_dp_mst_dpcd_write(param_1,param_2,param_3,param_4);
  }
  lVar5 = param_1[0x9a];
  if (iVar1 < 1) {
    if (lVar5 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar5 + 8);
    }
    uVar4 = *param_1;
    pcVar3 = "%s: 0x%05x AUX %s (ret=%3d)\n";
  }
  else {
    if (lVar5 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(lVar5 + 8);
    }
    uVar4 = *param_1;
    pcVar3 = "%s: 0x%05x AUX %s (ret=%3d) %*ph\n";
  }
  __drm_dev_dbg(0,uVar2,8,pcVar3,uVar4,param_2,&DAT_00114ed1,iVar1);
  return (long)iVar1;
}



//------------------------------------------------------------
// drm_dp_dpcd_read_link_status @ 00104b98 size=40
// signature: undefined drm_dp_dpcd_read_link_status(void)
// callers: []
//------------------------------------------------------------

void drm_dp_dpcd_read_link_status(undefined8 param_1,undefined8 param_2)

{
  drm_dp_dpcd_read(param_1,0x202,param_2,6);
  return;
}



//------------------------------------------------------------
// drm_dp_dpcd_read_phy_link_status @ 00104bc4 size=144
// signature: undefined drm_dp_dpcd_read_phy_link_status(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_dpcd_read_phy_link_status(undefined8 param_1,int param_2,long param_3)

{
  undefined2 uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    uVar3 = drm_dp_dpcd_read(param_1,0x202,param_3,6);
    if (-1 < (int)uVar3) {
      if ((int)uVar3 != 6) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104c58);
        (*pcVar2)();
      }
      uVar3 = 0;
    }
  }
  else {
    uVar3 = drm_dp_dpcd_read(param_1,param_2 * 0x50 + 0xeffe0,param_3,5);
    if (-1 < (int)uVar3) {
      if ((int)uVar3 != 5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104c4c);
        (*pcVar2)();
      }
      uVar3 = 0;
      uVar1 = *(undefined2 *)(param_3 + 3);
      *(undefined1 *)(param_3 + 3) = 0;
      *(undefined2 *)(param_3 + 4) = uVar1;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// drm_dp_downstream_is_type @ 00104c60 size=48
// signature: undefined drm_dp_downstream_is_type(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_downstream_is_type(byte *param_1,byte *param_2,byte param_3)

{
  if (((param_1[5] & 1) == 0) || (*param_1 < 0x11)) {
    return false;
  }
  return (*param_2 & 7) == param_3;
}



//------------------------------------------------------------
// drm_dp_downstream_is_tmds @ 00104c94 size=108
// signature: undefined drm_dp_downstream_is_tmds(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_downstream_is_tmds(byte *param_1,byte *param_2,long param_3)

{
  if (*param_1 < 0x11) {
    return (param_1[5] & 6) == 4;
  }
  if (((*param_2 & 7) - 2 < 2) ||
     (((*param_2 & 7) == 5 &&
      (((param_3 == 0 || (*(byte *)(param_3 + 0x13) < 4)) ||
       ((*(byte *)(param_3 + 0x14) & 0x87) != 0x85)))))) {
    return true;
  }
  return false;
}



//------------------------------------------------------------
// drm_dp_send_real_edid_checksum @ 00104d04 size=448
// signature: undefined drm_dp_send_real_edid_checksum(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_send_real_edid_checksum(undefined8 *param_1,undefined1 param_2)

{
  byte bVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 local_38 [4];
  byte local_34 [4];
  byte local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30[0] = 0;
  local_34[0] = 0;
  local_2c[0] = param_2;
  lVar2 = drm_dp_dpcd_read(param_1,0x201,local_34,1);
  if (lVar2 < 1) {
    lVar2 = param_1[0x9a];
    pcVar3 = "[drm] *ERROR* %s: DPCD failed read at register 0x%x\n";
LAB_00104e68:
    uVar5 = *param_1;
    uVar4 = 0x201;
LAB_00104e88:
    _dev_err(*(undefined8 *)(lVar2 + 8),pcVar3,uVar5,uVar4);
  }
  else {
    local_34[0] = local_34[0] & 2;
    lVar2 = drm_dp_dpcd_read(param_1,0x218,local_30,1);
    if (lVar2 < 1) {
      lVar2 = param_1[0x9a];
      pcVar3 = "[drm] *ERROR* %s: DPCD failed read at register 0x%x\n";
      uVar5 = *param_1;
      uVar4 = 0x218;
      goto LAB_00104e88;
    }
    bVar1 = local_30[0] & 4;
    local_30[0] = local_30[0] & 4;
    if ((local_34[0] != 0) && (bVar1 != 0)) {
      lVar2 = drm_dp_dpcd_write(param_1,0x201,local_34,1);
      if (lVar2 < 1) {
        lVar2 = param_1[0x9a];
        pcVar3 = "[drm] *ERROR* %s: DPCD failed write at register 0x%x\n";
        goto LAB_00104e68;
      }
      lVar2 = drm_dp_dpcd_write(param_1,0x261,local_2c,1);
      if (lVar2 < 1) {
        lVar2 = param_1[0x9a];
        pcVar3 = "[drm] *ERROR* %s: DPCD failed write at register 0x%x\n";
        uVar5 = *param_1;
        uVar4 = 0x261;
      }
      else {
        uVar5 = 1;
        local_38[0] = 4;
        lVar2 = drm_dp_dpcd_write(param_1,0x260,local_38,1);
        if (0 < lVar2) goto LAB_00104e94;
        lVar2 = param_1[0x9a];
        pcVar3 = "[drm] *ERROR* %s: DPCD failed write at register 0x%x\n";
        uVar5 = *param_1;
        uVar4 = 0x260;
      }
      goto LAB_00104e88;
    }
    if (param_1[0x9a] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar5,2,"%s: Source DUT does not support TEST_EDID_READ\n",*param_1);
  }
  uVar5 = 0;
LAB_00104e94:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// drm_dp_read_dpcd_caps @ 00104ec8 size=396
// signature: undefined drm_dp_read_dpcd_caps(void)
// callers: [drm_dp_mst_topology_mgr_set_mst, drm_dp_mst_topology_mgr_resume, drm_dp_mst_dsc_aux_for_port, drm_dp_mst_dump_topology]
//------------------------------------------------------------

void drm_dp_read_dpcd_caps(undefined8 *param_1,byte *param_2)

{
  long lVar1;
  undefined8 uVar2;
  byte local_38;
  undefined6 uStack_37;
  undefined1 uStack_31;
  undefined7 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar2 = drm_dp_dpcd_read(param_1,0,param_2,0xf);
  if ((int)uVar2 < 0) goto LAB_00104fa4;
  if (((int)uVar2 == 0xf) && (*param_2 != 0)) {
    uStack_30 = 0;
    local_38 = 0;
    uStack_37 = 0;
    uStack_31 = 0;
    if ((char)param_2[0xe] < '\0') {
      uVar2 = drm_dp_dpcd_read(param_1,0x2200,&local_38,0xf);
      if ((int)uVar2 < 0) goto LAB_00104fa4;
      if ((int)uVar2 != 0xf) goto LAB_00104f74;
      if (local_38 < *param_2) {
        if (param_1[0x9a] == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = *(undefined8 *)(param_1[0x9a] + 8);
        }
        __drm_dev_dbg(0,uVar2,2,"%s: Extended DPCD rev less than base DPCD rev (%d > %d)\n",*param_1
                     );
      }
      else if (*(long *)param_2 != CONCAT17(uStack_31,CONCAT61(uStack_37,local_38)) ||
               *(long *)(param_2 + 7) != CONCAT71(uStack_30,uStack_31)) {
        if (param_1[0x9a] == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = *(undefined8 *)(param_1[0x9a] + 8);
        }
        __drm_dev_dbg(0,uVar2,2,"%s: Base DPCD: %*ph\n",*param_1,0xf,param_2);
        *(ulong *)param_2 = CONCAT17(uStack_31,CONCAT61(uStack_37,local_38));
        *(ulong *)(param_2 + 7) = CONCAT71(uStack_30,uStack_31);
      }
    }
    if (param_1[0x9a] == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar2,2,"%s: DPCD: %*ph\n",*param_1,0xf,param_2);
    uVar2 = 0;
  }
  else {
LAB_00104f74:
    uVar2 = 0xfffffffb;
  }
LAB_00104fa4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_read_downstream_info @ 00105058 size=208
// signature: undefined drm_dp_read_downstream_info(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_read_downstream_info(undefined8 *param_1,char *param_2,undefined8 *param_3)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  *param_3 = 0;
  param_3[1] = 0;
  bVar2 = param_2[5];
  if (((bVar2 & 1) != 0) && (*param_2 != '\x10')) {
    uVar1 = 4;
    if ((4 < ((byte)param_2[7] & 0xf) & bVar2 >> 4) == 0) {
      uVar1 = (byte)param_2[7] & 0xf;
    }
    if (uVar1 != 0) {
      if ((bVar2 & 0x10) != 0) {
        uVar1 = uVar1 << 2;
      }
      uVar3 = drm_dp_dpcd_read(param_1,0x80,param_3,uVar1);
      if ((int)(uint)uVar3 < 0) goto LAB_00105110;
      if ((uint)uVar3 != uVar1) {
        uVar3 = 0xfffffffb;
        goto LAB_00105110;
      }
      if (param_1[0x9a] == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar4,2,"%s: DPCD DFP: %*ph\n",*param_1,uVar3,param_3);
    }
  }
  uVar3 = 0;
LAB_00105110:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// drm_dp_downstream_max_dotclock @ 0010512c size=76
// signature: undefined drm_dp_downstream_max_dotclock(void)
// callers: []
//------------------------------------------------------------

int drm_dp_downstream_max_dotclock(byte *param_1,byte *param_2)

{
  int iVar1;
  
  if ((param_1[5] & 1) == 0) {
    return 0;
  }
  if (*param_1 < 0x11) {
    return 0;
  }
  iVar1 = 0;
  if (((*param_2 & 7) == 1) && ((param_1[5] >> 4 & 1) != 0)) {
    iVar1 = (uint)param_2[1] * 8000;
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dp_downstream_max_tmds_clock @ 0010517c size=164
// signature: undefined drm_dp_downstream_max_tmds_clock(void)
// callers: []
//------------------------------------------------------------

int drm_dp_downstream_max_tmds_clock(byte *param_1,byte *param_2,long param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = param_1[5];
  if ((bVar2 & 1) == 0) {
    return 0;
  }
  if (*param_1 < 0x11) {
    iVar3 = 0x28488;
    if ((bVar2 & 6) != 4) {
      iVar3 = 0;
    }
    return iVar3;
  }
  bVar1 = *param_2 & 7;
  if (bVar1 == 2) {
    if ((bVar2 >> 4 & 1) == 0) {
      return 0x28488;
    }
  }
  else {
    if (bVar1 != 3) {
      if (bVar1 != 5) {
        return 0;
      }
      if (((param_3 != 0) && (3 < *(byte *)(param_3 + 0x13))) &&
         ((*(byte *)(param_3 + 0x14) & 0x87) == 0x85)) {
        return 0;
      }
    }
    if ((bVar2 >> 4 & 1) == 0) {
      return 300000;
    }
  }
  return (uint)param_2[1] * 0x9c4;
}



//------------------------------------------------------------
// drm_dp_downstream_min_tmds_clock @ 00105224 size=120
// signature: undefined drm_dp_downstream_min_tmds_clock(void)
// callers: []
//------------------------------------------------------------

undefined4 drm_dp_downstream_min_tmds_clock(byte *param_1,byte *param_2,long param_3)

{
  undefined4 uVar1;
  
  if ((param_1[5] & 1) != 0) {
    if (*param_1 < 0x11) {
      uVar1 = 25000;
      if ((param_1[5] & 6) != 4) {
        uVar1 = 0;
      }
      return uVar1;
    }
    if (((*param_2 & 7) - 2 < 2) ||
       (((*param_2 & 7) == 5 &&
        (((param_3 == 0 || (*(byte *)(param_3 + 0x13) < 4)) ||
         ((*(byte *)(param_3 + 0x14) & 0x87) != 0x85)))))) {
      return 25000;
    }
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_downstream_max_bpc @ 001052a0 size=152
// signature: undefined drm_dp_downstream_max_bpc(void)
// callers: []
//------------------------------------------------------------

uint drm_dp_downstream_max_bpc(byte *param_1,byte *param_2,long param_3)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = param_1[5];
  if ((bVar2 & 1) == 0) {
    return 0;
  }
  if (*param_1 < 0x11) {
    return (uint)((bVar2 & 6) != 0) << 3;
  }
  uVar1 = *param_2 & 7;
  if (2 < uVar1 - 1) {
    if ((*param_2 & 7) == 0) {
      return uVar1;
    }
    if (uVar1 != 5) {
      return 8;
    }
    if (((param_3 != 0) && (3 < *(byte *)(param_3 + 0x13))) &&
       ((*(byte *)(param_3 + 0x14) & 0x87) == 0x85)) {
      return 0;
    }
  }
  if ((bVar2 >> 4 & 1) == 0) {
    return 8;
  }
  return *(uint *)(&DAT_00116210 + ((ulong)param_2[2] & 3) * 4);
}



//------------------------------------------------------------
// drm_dp_downstream_420_passthrough @ 0010533c size=72
// signature: undefined drm_dp_downstream_420_passthrough(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_downstream_420_passthrough(byte *param_1,byte *param_2)

{
  if (((param_1[5] & 1) != 0) && (0x12 < *param_1)) {
    if ((*param_2 & 7) == 0) {
      return 1;
    }
    if (((*param_2 & 7) == 3) && ((param_1[5] >> 4 & 1) != 0)) {
      return param_2[3] >> 2 & 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_downstream_444_to_420_conversion @ 00105388 size=72
// signature: undefined drm_dp_downstream_444_to_420_conversion(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_downstream_444_to_420_conversion(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  if ((param_1[5] & 1) == 0) {
    return 0;
  }
  if (*param_1 < 0x13) {
    return 0;
  }
  bVar1 = 0;
  if (((*param_2 & 7) == 3) && ((param_1[5] >> 4 & 1) != 0)) {
    bVar1 = param_2[3] >> 4 & 1;
  }
  return bVar1;
}



//------------------------------------------------------------
// drm_dp_downstream_rgb_to_ycbcr_conversion @ 001053d4 size=76
// signature: undefined drm_dp_downstream_rgb_to_ycbcr_conversion(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_downstream_rgb_to_ycbcr_conversion(byte *param_1,byte *param_2,byte param_3)

{
  bool bVar1;
  
  if ((param_1[5] & 1) == 0) {
    return false;
  }
  if (*param_1 < 0x13) {
    return false;
  }
  bVar1 = false;
  if (((*param_2 & 7) == 3) && ((param_1[5] >> 4 & 1) != 0)) {
    bVar1 = (param_3 & param_2[3]) != 0;
  }
  return bVar1;
}



//------------------------------------------------------------
// drm_dp_downstream_mode @ 00105424 size=128
// signature: undefined drm_dp_downstream_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_downstream_mode(undefined8 param_1,byte *param_2,byte *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (((((param_2[5] & 1) == 0) || (*param_2 < 0x11)) || ((*param_3 & 7) != 4)) ||
     ((uVar1 = (*param_3 & 0xf0) - 0x10, 0x6f < uVar1 ||
      ((0x5fU >> (ulong)(uVar1 >> 4 & 0x1f) & 1) == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = drm_display_mode_from_cea_vic(param_1,0x13060414051506 >> ((ulong)(uVar1 >> 1) & 0x3f));
  }
  return uVar2;
}



//------------------------------------------------------------
// drm_dp_downstream_id @ 001054a8 size=40
// signature: undefined drm_dp_downstream_id(void)
// callers: []
//------------------------------------------------------------

void drm_dp_downstream_id(undefined8 param_1,undefined8 param_2)

{
  drm_dp_dpcd_read(param_1,0x503,param_2,6);
  return;
}



//------------------------------------------------------------
// drm_dp_downstream_debug @ 001054d4 size=880
// signature: undefined drm_dp_downstream_debug(void)
// callers: []
//------------------------------------------------------------

void drm_dp_downstream_debug
               (undefined8 param_1,byte *param_2,byte *param_3,long param_4,undefined8 param_5)

{
  uint uVar1;
  undefined *puVar2;
  byte bVar3;
  byte bVar4;
  long lVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined2 local_64;
  undefined4 uStack_60;
  undefined3 uStack_5c;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  bVar3 = param_2[5];
  bVar4 = *param_3;
  uStack_5c = 0;
  puVar2 = &DAT_00114c10;
  if ((bVar3 & 1) != 0) {
    puVar2 = &DAT_00113fc5;
  }
  uStack_60 = 0;
  local_64 = 0;
  seq_printf(param_1,"\tDP branch device present: %s\n",puVar2);
  if ((bVar3 & 1) == 0) goto LAB_00105794;
  if ((int)((ulong)bVar4 & 7) == 7) {
    pcVar7 = "\t\tType: N/A\n";
  }
  else {
    pcVar7 = (&PTR_s_Type__DisplayPort_00115a50)[(ulong)bVar4 & 7];
  }
  seq_puts(param_1,pcVar7);
  uStack_5c = 0;
  uStack_60 = 0;
  drm_dp_dpcd_read(param_5,0x503,&uStack_60,6);
  seq_printf(param_1,"\t\tID: %s\n",&uStack_60);
  iVar6 = drm_dp_dpcd_read(param_5,0x509,&local_64,1);
  if (0 < iVar6) {
    seq_printf(param_1,"\t\tHW: %d.%d\n",(byte)local_64 >> 4,(byte)local_64 & 0xf);
  }
  iVar6 = drm_dp_dpcd_read(param_5,0x50a,&local_64,2);
  if (0 < iVar6) {
    seq_printf(param_1,"\t\tSW: %d.%d\n",(byte)local_64,local_64._1_1_);
  }
  if ((bVar3 >> 4 & 1) == 0) goto LAB_00105794;
  bVar3 = param_2[5];
  uVar9 = (uint)bVar3;
  if ((bVar3 & 1) == 0) goto LAB_00105794;
  if (*param_2 < 0x11) {
LAB_00105678:
    if ((uVar9 & 6) == 4) {
LAB_00105684:
      iVar6 = 0x28488;
      goto LAB_0010568c;
    }
  }
  else {
    if ((((*param_3 & 7) == 1) && ((bVar3 >> 4 & 1) != 0)) && (param_3[1] != 0)) {
      seq_printf(param_1,"\t\tMax dot clock: %d kHz\n",(uint)param_3[1] * 8000);
      uVar9 = (uint)param_2[5];
      if ((param_2[5] & 1) == 0) goto LAB_00105794;
    }
    if (*param_2 < 0x11) goto LAB_00105678;
    bVar3 = *param_3 & 7;
    if (bVar3 == 2) {
      if ((uVar9 >> 4 & 1) != 0) {
LAB_0010582c:
        if (param_3[1] != 0) {
          iVar6 = (uint)param_3[1] * 0x9c4;
          goto LAB_0010568c;
        }
        goto LAB_001056a4;
      }
      goto LAB_00105684;
    }
    if ((bVar3 != 3) &&
       ((bVar3 != 5 ||
        (((param_4 != 0 && (3 < *(byte *)(param_4 + 0x13))) &&
         ((*(byte *)(param_4 + 0x14) & 0x87) == 0x85)))))) goto LAB_001056a4;
    if ((uVar9 >> 4 & 1) != 0) goto LAB_0010582c;
    iVar6 = 300000;
LAB_0010568c:
    seq_printf(param_1,"\t\tMax TMDS clock: %d kHz\n",iVar6);
    uVar9 = (uint)param_2[5];
    if ((param_2[5] & 1) == 0) goto LAB_00105794;
  }
LAB_001056a4:
  if (*param_2 < 0x11) {
    if ((uVar9 & 6) == 4) {
LAB_001056d4:
      seq_printf(param_1,"\t\tMin TMDS clock: %d kHz\n",25000);
      uVar9 = (uint)param_2[5];
      if ((param_2[5] & 1) == 0) goto LAB_00105794;
      goto LAB_0010576c;
    }
LAB_00105778:
    if ((uVar9 & 6) == 0) goto LAB_00105794;
LAB_00105780:
    uVar8 = 8;
  }
  else {
    if (((*param_3 & 7) - 2 < 2) ||
       (((*param_3 & 7) == 5 &&
        (((param_4 == 0 || (*(byte *)(param_4 + 0x13) < 4)) ||
         ((*(byte *)(param_4 + 0x14) & 0x87) != 0x85)))))) goto LAB_001056d4;
LAB_0010576c:
    if (*param_2 < 0x11) goto LAB_00105778;
    uVar1 = *param_3 & 7;
    if (2 < uVar1 - 1) {
      if ((*param_3 & 7) == 0) goto LAB_00105794;
      if (uVar1 == 5) {
        if (((param_4 != 0) && (3 < *(byte *)(param_4 + 0x13))) &&
           ((*(byte *)(param_4 + 0x14) & 0x87) == 0x85)) goto LAB_00105794;
        goto LAB_001057dc;
      }
      goto LAB_00105780;
    }
LAB_001057dc:
    if ((uVar9 >> 4 & 1) == 0) goto LAB_00105780;
    uVar8 = *(undefined4 *)(&DAT_00116210 + ((ulong)param_3[2] & 3) * 4);
  }
  seq_printf(param_1,"\t\tMax bpc: %d\n",uVar8);
LAB_00105794:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_subconnector_type @ 00105848 size=96
// signature: undefined drm_dp_subconnector_type(void)
// callers: []
//------------------------------------------------------------

undefined4 drm_dp_subconnector_type(char *param_1,byte *param_2)

{
  ulong uVar1;
  undefined *puVar2;
  
  if ((param_1[5] & 1U) == 0) {
    return 0xf;
  }
  if (*param_1 == '\x10') {
    uVar1 = (ulong)(byte)param_1[5] & 6;
    if (4 < (uint)uVar1) {
      return 0;
    }
    puVar2 = &DAT_00115a88;
  }
  else {
    uVar1 = (ulong)*param_2 & 7;
    if ((int)uVar1 == 7) {
      return 0;
    }
    puVar2 = &DAT_00115a9c;
  }
  return *(undefined4 *)(puVar2 + uVar1 * 4);
}



//------------------------------------------------------------
// drm_dp_set_subconnector_property @ 001058ac size=136
// signature: undefined drm_dp_set_subconnector_property(void)
// callers: []
//------------------------------------------------------------

void drm_dp_set_subconnector_property(long *param_1,int param_2,char *param_3,byte *param_4)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined *puVar3;
  
  if (param_2 != 1) goto LAB_00105904;
  if ((param_3[5] & 1U) == 0) {
    uVar1 = 0xf;
    goto LAB_00105908;
  }
  if (*param_3 == '\x10') {
    uVar2 = (ulong)(byte)param_3[5] & 6;
    if (4 < (uint)uVar2) {
LAB_00105904:
      uVar1 = 0;
      goto LAB_00105908;
    }
    puVar3 = &DAT_00115ab8;
  }
  else {
    uVar2 = (ulong)*param_4 & 7;
    if ((int)uVar2 == 7) goto LAB_00105904;
    puVar3 = &DAT_00115ae0;
  }
  uVar1 = *(undefined8 *)(puVar3 + uVar2 * 8);
LAB_00105908:
  drm_object_property_set_value(param_1 + 8,*(undefined8 *)(*param_1 + 0x548),uVar1);
  return;
}



//------------------------------------------------------------
// drm_dp_read_sink_count_cap @ 00105938 size=56
// signature: undefined drm_dp_read_sink_count_cap(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_read_sink_count_cap(long param_1,byte *param_2,long param_3)

{
  if (((*(int *)(param_1 + 0x9c) == 0xe) || (*param_2 < 0x11)) || ((param_2[5] & 1) == 0)) {
    return false;
  }
  return (*(byte *)(param_3 + 0xc) & 4) == 0;
}



//------------------------------------------------------------
// drm_dp_read_sink_count @ 00105974 size=124
// signature: undefined drm_dp_read_sink_count(void)
// callers: []
//------------------------------------------------------------

void drm_dp_read_sink_count(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  uVar2 = drm_dp_dpcd_read(param_1,0x200,local_1c,1);
  if (-1 < (int)uVar2) {
    if ((int)uVar2 == 1) {
      uVar2 = (ulong)(local_1c[0] & 0x3f | (uint)(local_1c[0] >> 7) << 6);
    }
    else {
      uVar2 = 0xfffffffb;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_remote_aux_init @ 001059f4 size=36
// signature: undefined drm_dp_remote_aux_init(void)
// callers: [drm_dp_mst_add_port]
//------------------------------------------------------------

void drm_dp_remote_aux_init(long param_1)

{
  *(undefined8 *)(param_1 + 0x510) = 0xfffffffe0;
  *(long *)(param_1 + 0x518) = param_1 + 0x518;
  *(long *)(param_1 + 0x520) = param_1 + 0x518;
  *(code **)(param_1 + 0x528) = drm_dp_aux_crc_work;
  return;
}



//------------------------------------------------------------
// drm_dp_aux_crc_work @ 00105a1c size=600
// signature: undefined drm_dp_aux_crc_work(void)
// callers: []
//------------------------------------------------------------

void drm_dp_aux_crc_work(long param_1)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  undefined8 *puVar8;
  byte local_64 [4];
  undefined4 local_60;
  ushort local_5c;
  ulong local_58;
  uint local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + -0x38);
  local_5c = 0;
  local_60 = 0;
  local_50 = 0;
  local_58 = 0;
  if (lVar7 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105c48);
    (*pcVar1)();
  }
  if (*(char *)(lVar7 + 0x610) != '\0') {
    puVar8 = (undefined8 *)(param_1 + -0x510);
    do {
      drm_crtc_wait_one_vblank(lVar7);
      if (*(char *)(lVar7 + 0x610) == '\0') break;
      local_64[0] = 0;
      uVar2 = drm_dp_dpcd_read(puVar8,0x270,local_64,1);
      uVar6 = (ulong)uVar2;
      if ((int)uVar2 < 0) {
LAB_00105b34:
        if ((int)uVar6 == -0xb) goto LAB_00105b3c;
LAB_00105ba8:
        if ((int)uVar6 != 0) goto LAB_00105bac;
LAB_00105c08:
        local_58 = (ulong)(CONCAT24(local_60._2_2_,local_60) & 0xffff0000ffff);
        local_50 = (uint)local_5c;
        drm_crtc_add_crc_entry(lVar7,0,0,&local_58);
      }
      else {
        if ((local_64[0] & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105c38);
          (*pcVar1)();
        }
        uVar6 = drm_dp_dpcd_read(puVar8,0x246,local_64,1);
        if ((int)uVar6 < 0) goto LAB_00105b34;
        if ((local_64[0] & 0xf) != *(byte *)(param_1 + 0x30)) {
          *(byte *)(param_1 + 0x30) = local_64[0] & 0xf;
          uVar2 = drm_dp_dpcd_read(puVar8,0x240,&local_60,6);
          if (-1 < (int)uVar2) {
            uVar2 = 0;
          }
          uVar6 = (ulong)uVar2;
          goto LAB_00105b34;
        }
LAB_00105b3c:
        usleep_range_state(1000,2000,2);
        local_64[0] = 0;
        uVar2 = drm_dp_dpcd_read(puVar8,0x270,local_64,1);
        uVar6 = (ulong)uVar2;
        if ((int)uVar2 < 0) goto LAB_00105ba8;
        if ((local_64[0] & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105c40);
          (*pcVar1)();
        }
        uVar2 = drm_dp_dpcd_read(puVar8,0x246,local_64,1);
        uVar6 = (ulong)uVar2;
        if ((int)uVar2 < 0) goto LAB_00105ba8;
        if ((local_64[0] & 0xf) == *(byte *)(param_1 + 0x30)) {
          uVar6 = 0xfffffff5;
          goto LAB_00105ba8;
        }
        *(byte *)(param_1 + 0x30) = local_64[0] & 0xf;
        uVar2 = drm_dp_dpcd_read(puVar8,0x240,&local_60,6);
        if (-1 < (int)uVar2) {
          uVar2 = 0;
        }
        uVar6 = (ulong)uVar2;
        if (uVar2 == 0) goto LAB_00105c08;
LAB_00105bac:
        if ((int)uVar6 == -0xb) {
          if (*(long *)(param_1 + -0x40) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined8 *)(*(long *)(param_1 + -0x40) + 8);
          }
          uVar5 = *puVar8;
          pcVar4 = "%s: Get CRC failed after retrying: %d\n";
          uVar6 = 0xfffffff5;
        }
        else {
          if (*(long *)(param_1 + -0x40) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined8 *)(*(long *)(param_1 + -0x40) + 8);
          }
          uVar5 = *puVar8;
          pcVar4 = "%s: Failed to get a CRC: %d\n";
        }
        __drm_dev_dbg(0,uVar3,2,pcVar4,uVar5,uVar6);
      }
    } while (*(char *)(lVar7 + 0x610) != '\0');
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_aux_init @ 00105c80 size=148
// signature: undefined drm_dp_aux_init(void)
// callers: []
//------------------------------------------------------------

void drm_dp_aux_init(long param_1)

{
  __mutex_init(param_1 + 0x4e0,"&aux->hw_mutex",&drm_dp_aux_init___key);
  __mutex_init(param_1 + 0x560,"&aux->cec.lock",&drm_dp_aux_init___key_37);
  *(undefined8 *)(param_1 + 0x510) = 0xfffffffe0;
  *(long *)(param_1 + 0x518) = param_1 + 0x518;
  *(long *)(param_1 + 0x520) = param_1 + 0x518;
  *(code **)(param_1 + 0x528) = drm_dp_aux_crc_work;
  *(undefined ***)(param_1 + 0x18) = &drm_dp_i2c_algo;
  *(long *)(param_1 + 0x20) = param_1;
  *(undefined4 *)(param_1 + 0x74) = 3;
  *(undefined ***)(param_1 + 0x28) = &drm_dp_i2c_lock_ops;
  return;
}



//------------------------------------------------------------
// drm_dp_aux_register @ 00105d18 size=280
// signature: undefined drm_dp_aux_register(void)
// callers: []
//------------------------------------------------------------

void drm_dp_aux_register(long *param_1)

{
  code *pcVar1;
  size_t __n;
  undefined8 *puVar2;
  char *__s;
  
  if (param_1[0x9a] == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105e30);
    (*pcVar1)();
  }
  if (param_1[3] == 0) {
    __mutex_init(param_1 + 0x9c,"&aux->hw_mutex",&drm_dp_aux_init___key);
    __mutex_init(param_1 + 0xac,"&aux->cec.lock",&drm_dp_aux_init___key_37);
    param_1[0xa2] = 0xfffffffe0;
    param_1[0xa3] = (long)(param_1 + 0xa3);
    param_1[0xa4] = (long)(param_1 + 0xa3);
    param_1[0xa5] = (long)drm_dp_aux_crc_work;
    param_1[3] = (long)&drm_dp_i2c_algo;
    param_1[4] = (long)param_1;
    *(undefined4 *)((long)param_1 + 0x74) = 3;
    param_1[5] = (long)&drm_dp_i2c_lock_ops;
  }
  puVar2 = (undefined8 *)param_1[0x99];
  __s = (char *)*param_1;
  param_1[1] = (long)&__this_module;
  *(undefined4 *)(param_1 + 2) = 8;
  param_1[0x1b] = (long)puVar2;
  if ((__s == (char *)0x0) && (__s = (char *)puVar2[0xe], __s == (char *)0x0)) {
    __s = (char *)*puVar2;
  }
  __n = strlen(__s);
  if (0x2e < __n) {
    __n = 0x2f;
  }
  memcpy((void *)((long)param_1 + 0x414),__s,__n);
  *(undefined1 *)((long)param_1 + 0x414 + __n) = 0;
  i2c_add_adapter(param_1 + 1);
  return;
}



//------------------------------------------------------------
// drm_dp_aux_unregister @ 00105e38 size=32
// signature: undefined drm_dp_aux_unregister(void)
// callers: []
//------------------------------------------------------------

void drm_dp_aux_unregister(long param_1)

{
  i2c_del_adapter(param_1 + 8);
  return;
}



//------------------------------------------------------------
// drm_dp_psr_setup_time @ 00105e5c size=40
// signature: undefined drm_dp_psr_setup_time(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_psr_setup_time(long param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)(*(byte *)(param_1 + 1) >> 1) & 7;
  if ((int)uVar1 == 7) {
    return 0xffffffea;
  }
  return (ulong)*(ushort *)(&drm_dp_psr_setup_time_psr_setup_time_us + uVar1 * 2);
}



//------------------------------------------------------------
// drm_dp_start_crc @ 00105e88 size=180
// signature: undefined drm_dp_start_crc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_start_crc(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0;
  uVar2 = drm_dp_dpcd_read(param_1,0x270,local_30,1);
  if (-1 < (int)uVar2) {
    local_2c[0] = local_30[0] | 1;
    uVar2 = drm_dp_dpcd_write(param_1,0x270,local_2c,1);
    if (-1 < (int)uVar2) {
      *(undefined1 *)(param_1 + 0x540) = 0;
      *(undefined8 *)(param_1 + 0x4d8) = param_2;
      queue_work_on(0x20,_system_wq,param_1 + 0x510);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_stop_crc @ 00105f40 size=160
// signature: undefined drm_dp_stop_crc(void)
// callers: []
//------------------------------------------------------------

void drm_dp_stop_crc(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0;
  uVar2 = drm_dp_dpcd_read(param_1,0x270,local_30,1);
  if (-1 < (int)uVar2) {
    local_2c[0] = local_30[0] & 0xfe;
    uVar2 = drm_dp_dpcd_write(param_1,0x270,local_2c,1);
    if (-1 < (int)uVar2) {
      flush_work(param_1 + 0x510);
      uVar2 = 0;
      *(undefined8 *)(param_1 + 0x4d8) = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_read_desc @ 00105fe4 size=476
// signature: undefined drm_dp_read_desc(void)
// callers: [drm_dp_mst_dsc_aux_for_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_dp_read_desc(undefined8 *param_1,short *param_2,byte param_3)

{
  int *__string;
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  size_t sVar4;
  long lVar5;
  ulong uVar6;
  undefined4 uVar7;
  short *psVar8;
  uint uVar9;
  
  lVar5 = sp_el0;
  lVar5 = *(long *)(lVar5 + 0x638);
  uVar7 = 0x500;
  if ((param_3 & 1) == 0) {
    uVar7 = 0x400;
  }
  uVar3 = drm_dp_dpcd_read(param_1,uVar7,param_2,0xc);
  if (-1 < (int)uVar3) {
    uVar6 = 0;
    uVar9 = 0;
    __string = (int *)((long)param_2 + 3);
    psVar8 = &dpcd_quirk_list;
    do {
      if (((((uVar6 & 0x7ffffffb) != 0) != (bool)(param_3 & 1)) &&
          (*psVar8 == *param_2 && (char)psVar8[1] == (char)param_2[1])) &&
         ((*(int *)((long)psVar8 + 3) == 0 && *(short *)((long)psVar8 + 7) == 0 ||
          (*(int *)((long)psVar8 + 3) == *__string &&
           *(short *)((long)psVar8 + 7) == *(short *)((long)param_2 + 7))))) {
        uVar9 = *(uint *)(psVar8 + 6) | uVar9;
      }
      uVar6 = uVar6 + 1;
      psVar8 = psVar8 + 8;
    } while (uVar6 != 6);
    *(uint *)(param_2 + 6) = uVar9;
    sVar4 = strnlen((char *)__string,6);
    if (6 < sVar4) {
      fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (param_1[0x9a] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    pcVar1 = "branch";
    if ((param_3 & 1) == 0) {
      pcVar1 = "sink";
    }
    __drm_dev_dbg(0,uVar3,2,
                  "%s: DP %s: OUI %*phD dev-ID %*pE HW-rev %d.%d SW-rev %d.%d quirks 0x%04x\n",
                  *param_1,pcVar1,3,param_2,(int)sVar4,__string,*(byte *)((long)param_2 + 9) >> 4,
                  *(byte *)((long)param_2 + 9) & 0xf,(char)param_2[5],
                  *(undefined1 *)((long)param_2 + 0xb),uVar9);
    uVar3 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_dsc_sink_max_slice_count @ 001061c4 size=152
// signature: undefined drm_dp_dsc_sink_max_slice_count(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_dsc_sink_max_slice_count(long param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 4);
  if ((param_2 & 1) == 0) {
    bVar2 = *(byte *)(param_1 + 0xd);
    if ((bVar2 >> 2 & 1) != 0) {
      return 0x18;
    }
    if ((bVar2 >> 1 & 1) != 0) {
      return 0x14;
    }
    if ((bVar2 & 1) != 0) {
      return 0x10;
    }
    if ((char)bVar1 < '\0') {
      return 0xc;
    }
    if ((bVar1 >> 6 & 1) != 0) {
      return 10;
    }
    if ((bVar1 >> 5 & 1) != 0) {
      return 8;
    }
    if ((bVar1 >> 4 & 1) != 0) {
      return 6;
    }
  }
  if ((bVar1 >> 3 & 1) != 0) {
    return 4;
  }
  if ((bVar1 >> 1 & 1) != 0) {
    return 2;
  }
  if ((bVar1 & 1) == 0) {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// drm_dp_dsc_sink_line_buf_depth @ 00106260 size=40
// signature: undefined drm_dp_dsc_sink_line_buf_depth(void)
// callers: []
//------------------------------------------------------------

undefined1 drm_dp_dsc_sink_line_buf_depth(long param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)*(byte *)(param_1 + 5) & 0xf;
  if ((uint)uVar1 < 9) {
    return (&DAT_00115b18)[uVar1];
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_dsc_sink_supported_input_bpcs @ 0010628c size=80
// signature: undefined drm_dp_dsc_sink_supported_input_bpcs(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_dsc_sink_supported_input_bpcs(long param_1,undefined1 *param_2)

{
  bool bVar1;
  byte bVar2;
  ulong uVar3;
  
  bVar2 = *(byte *)(param_1 + 10);
  bVar1 = (bVar2 >> 3 & 1) != 0;
  if (bVar1) {
    *param_2 = 0xc;
  }
  uVar3 = (ulong)bVar1;
  if ((bVar2 >> 2 & 1) != 0) {
    param_2[uVar3] = 10;
    uVar3 = (ulong)(bVar1 + 1);
  }
  if ((bVar2 >> 1 & 1) == 0) {
    return uVar3;
  }
  param_2[uVar3] = 8;
  return (ulong)((int)uVar3 + 1);
}



//------------------------------------------------------------
// drm_dp_read_lttpr_common_caps @ 001062e0 size=124
// signature: undefined drm_dp_read_lttpr_common_caps(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_read_lttpr_common_caps(undefined8 param_1,byte *param_2,long param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 8;
  if (*param_2 < 0x14) {
    iVar3 = 1;
  }
  while( true ) {
    uVar2 = drm_dp_dpcd_read(param_1,uVar4 + 0xf0000,param_3 + (ulong)uVar4,iVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (iVar3 != (int)uVar2) break;
    uVar4 = uVar4 + iVar3;
    if (7 < (int)uVar4) {
      return 0;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106344);
  (*pcVar1)();
}



//------------------------------------------------------------
// drm_dp_read_lttpr_phy_caps @ 00106364 size=220
// signature: undefined drm_dp_read_lttpr_phy_caps(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_read_lttpr_phy_caps(undefined8 param_1,byte *param_2,int param_3,long param_4)

{
  byte bVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 uVar4;
  uint uVar5;
  ulong uVar6;
  
  bVar1 = *param_2;
  uVar2 = param_3 * 0x50 + 0xeffd0;
  uVar5 = 3;
  if (bVar1 < 0x14) {
    uVar5 = 1;
  }
  uVar6 = (ulong)uVar5;
  uVar4 = drm_dp_dpcd_read(param_1,uVar2,param_4,uVar6);
  if (-1 < (int)(uint)uVar4) {
    if (uVar5 != (uint)uVar4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x106434);
      (*pcVar3)();
    }
    if (bVar1 < 0x14) {
      uVar4 = drm_dp_dpcd_read(param_1,uVar2 | uVar5,param_4 + uVar6,uVar6);
      if ((int)(uint)uVar4 < 0) {
        return uVar4;
      }
      if (uVar5 != (uint)uVar4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x106444);
        (*pcVar3)();
      }
      if (bVar1 < 0x14) {
        uVar4 = drm_dp_dpcd_read(param_1,uVar2 | (uint)(uVar6 * 2),param_4 + uVar6 * 2,uVar6);
        if ((int)(uint)uVar4 < 0) {
          return uVar4;
        }
        if (uVar5 != (uint)uVar4) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x106458);
          (*pcVar3)();
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// drm_dp_lttpr_count @ 00106460 size=100
// signature: undefined drm_dp_lttpr_count(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_lttpr_count(long param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  ulong uVar4;
  
  bVar2 = *(byte *)(param_1 + 2);
  uVar4 = __sw_hweight8(bVar2);
  iVar3 = (int)uVar4;
  if (iVar3 != 0) {
    if (iVar3 == 8) {
      uVar4 = 0xffffffde;
    }
    else if (iVar3 == 1) {
      uVar1 = 9;
      if (bVar2 != 0) {
        uVar1 = (int)LZCOUNT((uint)bVar2) - 0x17;
      }
      uVar4 = (ulong)uVar1;
    }
    else {
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// drm_dp_lttpr_max_link_rate @ 001064c8 size=76
// signature: undefined drm_dp_lttpr_max_link_rate(void)
// callers: []
//------------------------------------------------------------

int drm_dp_lttpr_max_link_rate(long param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 == 1) {
    return 1000000;
  }
  if (bVar1 == 2) {
    return 2000000;
  }
  if (bVar1 == 4) {
    return 0x149970;
  }
  return (uint)bVar1 * 27000;
}



//------------------------------------------------------------
// drm_dp_lttpr_max_lane_count @ 00106518 size=12
// signature: undefined drm_dp_lttpr_max_lane_count(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_lttpr_max_lane_count(long param_1)

{
  return *(byte *)(param_1 + 4) & 0x1f;
}



//------------------------------------------------------------
// drm_dp_lttpr_voltage_swing_level_3_supported @ 00106528 size=12
// signature: undefined drm_dp_lttpr_voltage_swing_level_3_supported(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_lttpr_voltage_swing_level_3_supported(long param_1)

{
  return *(byte *)(param_1 + 1) & 1;
}



//------------------------------------------------------------
// drm_dp_lttpr_pre_emphasis_level_3_supported @ 00106538 size=12
// signature: undefined drm_dp_lttpr_pre_emphasis_level_3_supported(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_lttpr_pre_emphasis_level_3_supported(long param_1)

{
  return *(byte *)(param_1 + 1) >> 1 & 1;
}



//------------------------------------------------------------
// drm_dp_get_phy_test_pattern @ 00106548 size=352
// signature: undefined drm_dp_get_phy_test_pattern(void)
// callers: []
//------------------------------------------------------------

void drm_dp_get_phy_test_pattern(undefined8 param_1,int *param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  byte local_40 [4];
  byte local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c[0] = 0;
  local_40[0] = 0;
  uVar3 = drm_dp_dpcd_read(param_1,0x219,local_3c,1);
  if ((int)uVar3 < 0) goto LAB_00106678;
  if (local_3c[0] == 1) {
    iVar5 = 1000000;
  }
  else if (local_3c[0] == 2) {
    iVar5 = 2000000;
  }
  else if (local_3c[0] == 4) {
    iVar5 = 0x149970;
  }
  else {
    iVar5 = (uint)local_3c[0] * 27000;
  }
  *param_2 = iVar5;
  uVar3 = drm_dp_dpcd_read(param_1,0x220,local_40,1);
  if ((int)uVar3 < 0) goto LAB_00106678;
  *(byte *)(param_2 + 1) = local_40[0] & 0x1f;
  if ((char)local_40[0] < '\0') {
    *(undefined1 *)((long)param_2 + 0x12) = 1;
  }
  uVar3 = drm_dp_dpcd_read(param_1,0x248,(char *)((long)param_2 + 5),1);
  if ((int)uVar3 < 0) goto LAB_00106678;
  cVar1 = *(char *)((long)param_2 + 5);
  if (cVar1 == '\x05') {
    param_2 = (int *)((long)param_2 + 6);
    uVar3 = 0x24a;
    uVar4 = 2;
LAB_00106668:
    uVar3 = drm_dp_dpcd_read(param_1,uVar3,param_2,uVar4);
    if ((int)uVar3 < 0) goto LAB_00106678;
  }
  else if (cVar1 == '\x04') {
    param_2 = param_2 + 2;
    uVar3 = 0x250;
    uVar4 = 10;
    goto LAB_00106668;
  }
  uVar3 = 0;
LAB_00106678:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_set_phy_test_pattern @ 001066ac size=208
// signature: undefined drm_dp_set_phy_test_pattern(void)
// callers: []
//------------------------------------------------------------

void drm_dp_set_phy_test_pattern(undefined8 param_1,long param_2,byte param_3)

{
  byte bVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  char local_40 [4];
  byte local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  bVar1 = *(byte *)(param_2 + 5);
  if (param_3 < 0x12) {
    local_40[0] = (bVar1 & 3) << 2;
    uVar3 = drm_dp_dpcd_write(param_1,0x102,local_40,1);
    if ((int)uVar3 < 0) goto LAB_00106748;
  }
  else if (*(char *)(param_2 + 4) != '\0') {
    uVar4 = 0;
    do {
      local_3c[0] = bVar1;
      uVar3 = drm_dp_dpcd_write(param_1,uVar4 + 0x10b,local_3c,1);
      if ((int)uVar3 < 0) goto LAB_00106748;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(byte *)(param_2 + 4));
  }
  uVar3 = 0;
LAB_00106748:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_vsc_sdp_log @ 00106780 size=568
// signature: undefined drm_dp_vsc_sdp_log(void)
// callers: []
//------------------------------------------------------------

void drm_dp_vsc_sdp_log(undefined8 param_1,undefined8 param_2,long param_3)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  undefined **ppuVar4;
  
  _dev_printk(param_1,param_2,"DP SDP: %s, revision %u, length %u\n",&DAT_001147be,
              *(undefined1 *)(param_3 + 1),*(undefined1 *)(param_3 + 2));
  uVar2 = *(uint *)(param_3 + 4);
  if (uVar2 < 7) {
    if (uVar2 == 6) {
      pcVar3 = "Reserved";
    }
    else {
      pcVar3 = (&PTR_DAT_00115b28)[(int)uVar2];
    }
  }
  else {
    pcVar3 = "Invalid";
  }
  _dev_printk(param_1,param_2,"    pixelformat: %s\n",pcVar3);
  uVar2 = *(uint *)(param_3 + 4);
  pcVar3 = "Invalid";
  if (6 < uVar2) goto LAB_00106908;
  switch(*(undefined4 *)(param_3 + 8)) {
  case 0:
    if (5 < uVar2) {
LAB_001068d4:
      pcVar3 = "Reserved";
      goto LAB_00106908;
    }
    ppuVar4 = &PTR_DAT_00115b58;
    break;
  case 1:
    if (3 < uVar2) goto LAB_001068d4;
    ppuVar4 = &PTR_s_Wide_Fixed_00115b88;
    break;
  case 2:
    if (3 < uVar2) goto LAB_001068d4;
    ppuVar4 = &PTR_s_Wide_Float_00115ba8;
    break;
  case 3:
    if (3 < uVar2) goto LAB_001068d4;
    ppuVar4 = &PTR_s_OpRGB_00115bc8;
    break;
  case 4:
    if (3 < uVar2) goto LAB_001068d4;
    ppuVar4 = &PTR_s_DCI_P3_00115be8;
    break;
  case 5:
    if (3 < uVar2) goto LAB_001068d4;
    ppuVar4 = &PTR_s_Custom_Profile_00115c08;
    break;
  case 6:
    if (3 < uVar2) goto LAB_001068d4;
    ppuVar4 = &PTR_s_BT_2020_RGB_00115c28;
    break;
  case 7:
    pcVar3 = "BT.2020 YCC";
    if (2 < uVar2 - 1) {
      pcVar3 = "Reserved";
    }
    goto LAB_00106908;
  default:
    pcVar3 = "Invalid";
    goto LAB_00106908;
  }
  pcVar3 = ppuVar4[(int)uVar2];
LAB_00106908:
  _dev_printk(param_1,param_2,"    colorimetry: %s\n",pcVar3);
  _dev_printk(param_1,param_2,"    bpc: %u\n",*(undefined4 *)(param_3 + 0xc));
  pcVar3 = "CTA range";
  if (*(int *)(param_3 + 0x10) != 1) {
    pcVar3 = "Invalid";
  }
  pcVar1 = "VESA range";
  if (*(int *)(param_3 + 0x10) != 0) {
    pcVar1 = pcVar3;
  }
  _dev_printk(param_1,param_2,"    dynamic range: %s\n",pcVar1);
  if (*(uint *)(param_3 + 0x14) < 5) {
    pcVar3 = (&PTR_s_Not_defined_00115c48)[(int)*(uint *)(param_3 + 0x14)];
  }
  else {
    pcVar3 = "Reserved";
  }
  _dev_printk(param_1,param_2,"    content type: %s\n",pcVar3);
  return;
}



//------------------------------------------------------------
// drm_dp_get_pcon_max_frl_bw @ 001069bc size=44
// signature: undefined drm_dp_get_pcon_max_frl_bw(void)
// callers: []
//------------------------------------------------------------

undefined4 drm_dp_get_pcon_max_frl_bw(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = ((ulong)(*(byte *)(param_2 + 2) >> 2) & 7) - 1;
  if ((uint)lVar1 < 6) {
    return *(undefined4 *)(&DAT_00115c70 + lVar1 * 4);
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_pcon_frl_prepare @ 001069ec size=104
// signature: undefined drm_dp_pcon_frl_prepare(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_frl_prepare(undefined8 param_1,ulong param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0x68;
  if ((param_2 & 1) == 0) {
    local_1c[0] = 0x28;
  }
  drm_dp_dpcd_write(param_1,0x305a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_is_frl_ready @ 00106a58 size=104
// signature: undefined drm_dp_pcon_is_frl_ready(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_is_frl_ready(undefined8 param_1)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  byte local_1c [4];
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_1c[0] = 0;
  iVar3 = drm_dp_dpcd_read(param_1,0x303b,local_1c,1);
  lVar2 = sp_el0;
  bVar1 = 0;
  if (-1 < iVar3) {
    bVar1 = local_1c[0] >> 1 & 1;
  }
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_frl_configure_1 @ 00106ac4 size=268
// signature: undefined drm_dp_pcon_frl_configure_1(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_frl_configure_1(undefined8 param_1,undefined4 param_2,char param_3)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  byte local_40 [4];
  byte local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0;
  uVar3 = drm_dp_dpcd_read(param_1,0x305a,local_40,1);
  if (-1 < (int)uVar3) {
    uVar3 = 0xffffffea;
    local_40[0] = local_40[0] & 0xe0 | local_40[0] & 0xf | (param_3 == '\x10') << 4;
    switch(param_2) {
    case 0:
      break;
    default:
      goto switchD_00106b48_caseD_1;
    case 9:
      local_40[0] = local_40[0] | 1;
      break;
    case 0x12:
      local_40[0] = local_40[0] | 2;
      break;
    case 0x18:
      local_40[0] = local_40[0] | 3;
      break;
    case 0x20:
      local_40[0] = local_40[0] | 4;
      break;
    case 0x28:
      local_40[0] = local_40[0] | 5;
      break;
    case 0x30:
      local_40[0] = local_40[0] | 6;
    }
    local_3c[0] = local_40[0];
    uVar2 = drm_dp_dpcd_write(param_1,0x305a,local_3c,1);
    if (-1 < (int)uVar2) {
      uVar2 = 0;
    }
    uVar3 = (ulong)uVar2;
  }
switchD_00106b48_caseD_1:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_frl_configure_2 @ 00106bd4 size=116
// signature: undefined drm_dp_pcon_frl_configure_2(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_frl_configure_2(undefined8 param_1,byte param_2,char param_3)

{
  long lVar1;
  int iVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2 & 0xbf | (param_3 == '@') << 6;
  iVar2 = drm_dp_dpcd_write(param_1,0x305b,local_1c,1);
  lVar1 = sp_el0;
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_reset_frl_config @ 00106c4c size=96
// signature: undefined drm_dp_pcon_reset_frl_config(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_reset_frl_config(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  iVar2 = drm_dp_dpcd_write(param_1,0x305a,local_1c,1);
  lVar1 = sp_el0;
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_frl_enable @ 00106cb0 size=204
// signature: undefined drm_dp_pcon_frl_enable(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_frl_enable(undefined8 *param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0;
  uVar3 = drm_dp_dpcd_read(param_1,0x305a,local_30,1);
  if (-1 < (int)uVar3) {
    if ((local_30[0] >> 3 & 1) == 0) {
      if (param_1[0x9a] == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar4,2,"%s: PCON in Autonomous mode, can\'t enable FRL\n",*param_1);
      uVar3 = 0xffffffea;
    }
    else {
      local_30[0] = local_30[0] | 0x80;
      local_2c[0] = local_30[0];
      uVar2 = drm_dp_dpcd_write(param_1,0x305a,local_2c,1);
      if (-1 < (int)uVar2) {
        uVar2 = 0;
      }
      uVar3 = (ulong)uVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_hdmi_link_active @ 00106d80 size=104
// signature: undefined drm_dp_pcon_hdmi_link_active(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_pcon_hdmi_link_active(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  iVar2 = drm_dp_dpcd_read(param_1,0x303b,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return -1 < iVar2 & local_1c[0];
}



//------------------------------------------------------------
// drm_dp_pcon_hdmi_link_mode @ 00106dec size=128
// signature: undefined drm_dp_pcon_hdmi_link_mode(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_hdmi_link_mode(undefined8 param_1,byte *param_2)

{
  long lVar1;
  int iVar2;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = drm_dp_dpcd_read(param_1,0x3036,local_2c,1);
  if (-1 < iVar2) {
    if ((param_2 != (byte *)0x0) && ((local_2c[0] & 1) != 0)) {
      *param_2 = local_2c[0] >> 1 & 0x3f;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_hdmi_frl_link_error_count @ 00106e70 size=232
// signature: undefined drm_dp_pcon_hdmi_frl_link_error_count(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_hdmi_frl_link_error_count(undefined8 *param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  byte local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c[0] = 0;
  if (*(char *)(param_2 + 0x162) != '\0') {
    uVar3 = 0;
    do {
      lVar1 = drm_dp_dpcd_read(param_1,uVar3 + 0x3037,local_4c,1);
      if (lVar1 < 0) break;
      lVar1 = ((ulong)local_4c[0] & 7) - 1;
      if ((uint)lVar1 < 4) {
        uVar2 = *(undefined4 *)(&DAT_00116200 + lVar1 * 4);
      }
      else {
        uVar2 = 0;
      }
      _dev_err(*(undefined8 *)(param_1[0x9a] + 8),
               "[drm] *ERROR* %s: More than %d errors since the last read for lane %d",*param_1,
               uVar2,uVar3);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(byte *)(param_2 + 0x162));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_enc_is_dsc_1_2 @ 00106f5c size=16
// signature: undefined drm_dp_pcon_enc_is_dsc_1_2(void)
// callers: []
//------------------------------------------------------------

bool drm_dp_pcon_enc_is_dsc_1_2(long param_1)

{
  return *(char *)(param_1 + 1) == '!';
}



//------------------------------------------------------------
// drm_dp_pcon_dsc_max_slices @ 00106f70 size=124
// signature: undefined drm_dp_pcon_dsc_max_slices(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_pcon_dsc_max_slices(long param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = *(byte *)(param_1 + 10);
  if ((bVar1 >> 2 & 1) != 0) {
    return 0x18;
  }
  if ((bVar1 >> 1 & 1) != 0) {
    return 0x14;
  }
  if ((bVar1 & 1) != 0) {
    return 0x10;
  }
  bVar1 = *(byte *)(param_1 + 4);
  if ((char)bVar1 < '\0') {
    return 0xc;
  }
  if ((bVar1 >> 6 & 1) != 0) {
    return 10;
  }
  if ((bVar1 >> 5 & 1) != 0) {
    return 8;
  }
  if ((bVar1 >> 4 & 1) != 0) {
    return 6;
  }
  if ((bVar1 >> 3 & 1) != 0) {
    return 4;
  }
  bVar2 = bVar1 & 1;
  if ((bVar1 & 2) != 0) {
    bVar2 = 2;
  }
  return bVar2;
}



//------------------------------------------------------------
// drm_dp_pcon_dsc_max_slice_width @ 00106ff0 size=16
// signature: undefined drm_dp_pcon_dsc_max_slice_width(void)
// callers: []
//------------------------------------------------------------

int drm_dp_pcon_dsc_max_slice_width(long param_1)

{
  return (uint)*(byte *)(param_1 + 9) * 0x140;
}



//------------------------------------------------------------
// drm_dp_pcon_dsc_bpp_incr @ 00107004 size=40
// signature: undefined drm_dp_pcon_dsc_bpp_incr(void)
// callers: []
//------------------------------------------------------------

undefined4 drm_dp_pcon_dsc_bpp_incr(long param_1)

{
  ulong uVar1;
  
  uVar1 = (ulong)*(byte *)(param_1 + 0xc) & 7;
  if ((uint)uVar1 < 5) {
    return *(undefined4 *)(&DAT_00115c88 + uVar1 * 4);
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_pcon_pps_default @ 00107030 size=152
// signature: undefined drm_dp_pcon_pps_default(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_pps_default(undefined8 param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0;
  uVar3 = drm_dp_dpcd_read(param_1,0x3052,local_30,1);
  if (-1 < (int)uVar3) {
    local_30[0] = local_30[0] & 0xf1 | 2;
    local_2c[0] = local_30[0];
    uVar2 = drm_dp_dpcd_write(param_1,0x3052,local_2c,1);
    if (-1 < (int)uVar2) {
      uVar2 = 0;
    }
    uVar3 = (ulong)uVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_pps_override_buf @ 001070cc size=184
// signature: undefined drm_dp_pcon_pps_override_buf(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_pps_override_buf(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 local_38;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = param_2;
  uVar3 = drm_dp_dpcd_write(param_1,0x3100,&local_38,0x80);
  if (-1 < (int)uVar3) {
    local_30[0] = 0;
    uVar3 = drm_dp_dpcd_read(param_1,0x3052,local_30,1);
    if (-1 < (int)uVar3) {
      local_30[0] = local_30[0] & 0xf0 | local_30[0] & 1 | 10;
      local_2c[0] = local_30[0];
      uVar2 = drm_dp_dpcd_write(param_1,0x3052,local_2c,1);
      if (-1 < (int)uVar2) {
        uVar2 = 0;
      }
      uVar3 = (ulong)uVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_pps_override_param @ 00107188 size=236
// signature: undefined drm_dp_pcon_pps_override_param(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_pps_override_param(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = drm_dp_dpcd_write(param_1,0x3180,param_2,2);
  if (((-1 < (int)uVar3) &&
      (uVar3 = drm_dp_dpcd_write(param_1,0x3182,param_2 + 2,2), -1 < (int)uVar3)) &&
     (uVar3 = drm_dp_dpcd_write(param_1,0x3184,param_2 + 4,2), -1 < (int)uVar3)) {
    local_30[0] = 0;
    uVar3 = drm_dp_dpcd_read(param_1,0x3052,local_30,1);
    if (-1 < (int)uVar3) {
      local_30[0] = local_30[0] & 0xf0 | local_30[0] & 1 | 10;
      local_2c[0] = local_30[0];
      uVar2 = drm_dp_dpcd_write(param_1,0x3052,local_2c,1);
      if (-1 < (int)uVar2) {
        uVar2 = 0;
      }
      uVar3 = (ulong)uVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_pcon_convert_rgb_to_ycbcr @ 00107278 size=164
// signature: undefined drm_dp_pcon_convert_rgb_to_ycbcr(void)
// callers: []
//------------------------------------------------------------

void drm_dp_pcon_convert_rgb_to_ycbcr(undefined8 param_1,byte param_2)

{
  byte bVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30[0] = 0;
  uVar4 = drm_dp_dpcd_read(param_1,0x3052,local_30,1);
  if (-1 < (int)uVar4) {
    bVar1 = local_30[0] | param_2 & 0x70;
    local_30[0] = local_30[0] & 0x8f;
    if ((param_2 & 0x70) != 0) {
      local_30[0] = bVar1;
    }
    local_2c[0] = local_30[0];
    uVar3 = drm_dp_dpcd_write(param_1,0x3052,local_2c,1);
    if (-1 < (int)uVar3) {
      uVar3 = 0;
    }
    uVar4 = (ulong)uVar3;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// drm_edp_backlight_set_level @ 00107320 size=200
// signature: undefined drm_edp_backlight_set_level(void)
// callers: []
//------------------------------------------------------------

void drm_edp_backlight_set_level(undefined8 *param_1,long param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  short local_2c [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  iVar2 = 0;
  local_2c[0] = 0;
  if ((*(byte *)(param_2 + 4) >> 2 & 1) != 0) {
    if ((*(byte *)(param_2 + 4) & 1) != 0) {
      local_2c[0] = (ushort)(byte)param_3 << 8;
      param_3 = param_3 >> 8 & 0xff;
    }
    local_2c[0] = CONCAT11(local_2c[0]._1_1_,(char)param_3);
    iVar2 = drm_dp_dpcd_write(param_1,0x722,local_2c,2);
    if (iVar2 == 2) {
      iVar2 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(param_1[0x9a] + 8),
               "[drm] *ERROR* %s: Failed to write aux backlight level: %d\n",*param_1,iVar2);
      if (-1 < iVar2) {
        iVar2 = -5;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_edp_backlight_enable @ 001073ec size=528
// signature: undefined drm_edp_backlight_enable(void)
// callers: [dp_aux_backlight_update_status]
//------------------------------------------------------------

void drm_edp_backlight_enable(undefined8 *param_1,char *param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  byte bVar4;
  char local_48 [4];
  char local_44 [4];
  byte local_40 [4];
  short local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  bVar4 = (byte)param_2[4] >> 1 & 2;
  if (*param_2 != '\0') {
    local_48[0] = *param_2;
    iVar2 = drm_dp_dpcd_write(param_1,0x724,local_48,1);
    if (iVar2 != 1) {
      if (param_1[0x9a] == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"%s: Failed to write aux pwmgen bit count: %d\n",*param_1);
    }
  }
  if (param_2[1] != '\0') {
    local_44[0] = param_2[1];
    iVar2 = drm_dp_dpcd_write(param_1,0x728,local_44,1);
    if (iVar2 == 1) {
      bVar4 = bVar4 | 8;
    }
    else {
      if (param_1[0x9a] == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"%s: Failed to write aux backlight frequency: %d\n",*param_1);
    }
  }
  local_40[0] = bVar4;
  iVar2 = drm_dp_dpcd_write(param_1,0x721,local_40,1);
  if (iVar2 == 1) {
    local_3c[0] = 0;
    if (((byte)param_2[4] >> 2 & 1) != 0) {
      if ((param_2[4] & 1U) != 0) {
        local_3c[0] = (ushort)(byte)param_3 << 8;
        param_3 = param_3 >> 8 & 0xff;
      }
      local_3c[0] = CONCAT11(local_3c[0]._1_1_,(char)param_3);
      iVar2 = drm_dp_dpcd_write(param_1,0x722,local_3c,2);
      if (iVar2 != 2) {
        _dev_err(*(undefined8 *)(param_1[0x9a] + 8),
                 "[drm] *ERROR* %s: Failed to write aux backlight level: %d\n",*param_1,iVar2);
        if (-1 < iVar2) {
          iVar2 = -5;
        }
        goto LAB_001075a0;
      }
    }
    iVar2 = drm_edp_backlight_set_enable(param_1,param_2,1);
    if (-1 < iVar2) {
      iVar2 = 0;
    }
  }
  else {
    if (param_1[0x9a] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar3,2,"%s: Failed to write aux backlight mode: %d\n",*param_1,iVar2);
    if (-1 < iVar2) {
      iVar2 = -5;
    }
  }
LAB_001075a0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_edp_backlight_set_enable @ 001075fc size=280
// signature: undefined drm_edp_backlight_set_enable(void)
// callers: [dp_aux_backlight_update_status, drm_edp_backlight_enable, drm_edp_backlight_disable]
//------------------------------------------------------------

void drm_edp_backlight_set_enable(undefined8 *param_1,long param_2,byte param_3)

{
  long lVar1;
  int iVar2;
  byte local_40 [4];
  byte local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  iVar2 = 0;
  local_40[0] = 0;
  if ((*(byte *)(param_2 + 4) >> 1 & 1) != 0) {
    iVar2 = drm_dp_dpcd_read(param_1,0x720,local_40,1);
    if (iVar2 == 1) {
      local_40[0] = local_40[0] & 0xfe | param_3 & 1;
      local_3c[0] = local_40[0];
      iVar2 = drm_dp_dpcd_write(param_1,0x720,local_3c,1);
      if (iVar2 == 1) {
        iVar2 = 0;
      }
      else {
        _dev_err(*(undefined8 *)(param_1[0x9a] + 8),
                 "[drm] *ERROR* %s: Failed to write eDP display control register: %d\n",*param_1,
                 iVar2);
        if (-1 < iVar2) {
          iVar2 = -5;
        }
      }
    }
    else {
      _dev_err(*(undefined8 *)(param_1[0x9a] + 8),
               "[drm] *ERROR* %s: Failed to read eDP display control register: %d\n",*param_1,iVar2)
      ;
      if (-1 < iVar2) {
        iVar2 = -5;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// drm_edp_backlight_disable @ 00107718 size=40
// signature: undefined drm_edp_backlight_disable(void)
// callers: []
//------------------------------------------------------------

int drm_edp_backlight_disable(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = drm_edp_backlight_set_enable(param_1,param_2,0);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_edp_backlight_init @ 00107744 size=1324
// signature: undefined drm_edp_backlight_init(void)
// callers: [drm_panel_dp_aux_backlight]
//------------------------------------------------------------

void drm_edp_backlight_init
               (undefined8 *param_1,byte *param_2,ushort param_3,long param_4,ushort *param_5,
               byte *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 uVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  byte local_70 [4];
  byte local_6c [4];
  byte local_68 [4];
  byte local_64 [4];
  byte local_60 [4];
  undefined2 local_5c;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  if ((*(byte *)(param_4 + 1) >> 2 & 1) == 0) {
    bVar14 = *(byte *)(param_4 + 2);
    if ((bVar14 >> 1 & 1) != 0) goto LAB_001077d0;
LAB_00107798:
    uVar12 = (uint)param_2[4];
    uVar13 = uVar12;
    if ((bVar14 >> 2 & 1) != 0) goto LAB_001077e8;
LAB_001077a0:
    if ((uVar12 >> 2 & 1) != 0) goto LAB_001077f4;
LAB_001077a4:
    if ((*(byte *)(param_4 + 2) & 1) == 0) {
      if (param_1[0x9a] == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar7,2,"%s: Panel supports neither AUX or PWM brightness control? Aborting\n"
                    ,*param_1);
      iVar5 = -0x16;
      goto LAB_00107b18;
    }
  }
  else {
    param_2[4] = param_2[4] | 2;
    bVar14 = *(byte *)(param_4 + 2);
    if ((bVar14 >> 1 & 1) == 0) goto LAB_00107798;
LAB_001077d0:
    param_2[4] = param_2[4] | 4;
    uVar13 = (uint)param_2[4];
    uVar12 = (uint)param_2[4];
    if ((*(byte *)(param_4 + 2) >> 2 & 1) == 0) goto LAB_001077a0;
LAB_001077e8:
    param_2[4] = (byte)uVar13 | 1;
    if ((uVar13 >> 2 & 1) == 0) goto LAB_001077a4;
LAB_001077f4:
    local_68[0] = 0;
    local_6c[0] = 0;
    local_70[0] = 0;
    iVar5 = drm_dp_dpcd_read(param_1,0x724,local_68,1);
    if (iVar5 != 1) {
      if (param_1[0x9a] == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar7,2,"%s: Failed to read pwmgen bit count cap: %d\n",*param_1);
      iVar5 = -0x13;
      goto LAB_00107b18;
    }
    bVar14 = local_68[0] & 0x1f;
    *(ushort *)(param_2 + 2) = ~(ushort)(-1 << (ulong)(local_68[0] & 0x1f));
    local_68[0] = bVar14;
    if (param_3 != 0) {
      uVar6 = drm_dp_dpcd_read(param_1,0x725,local_6c,1);
      if ((int)uVar6 == 1) {
        uVar6 = drm_dp_dpcd_read(param_1,0x726,local_70,1);
        if ((int)uVar6 == 1) {
          uVar13 = 0;
          if (param_3 != 0) {
            uVar13 = ((param_3 >> 1) + 27000000) / (uint)param_3;
          }
          uVar15 = (uint)local_6c[0];
          uVar12 = uVar15 & 0x1f;
          uVar11 = local_70[0] & 0x1f;
          local_6c[0] = (byte)uVar12;
          local_70[0] = (byte)uVar11;
          uVar2 = uVar13 * 3 + 2 >> 2;
          if (((int)uVar2 < 1 << (ulong)(uVar15 & 0x1f)) ||
             (uVar15 = uVar13 * 5 + 2 >> 2, 0xff << (ulong)uVar11 < (int)uVar15)) {
            if (param_1[0x9a] == 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
            }
            uVar9 = *param_1;
            pcVar8 = "%s: Driver defined backlight frequency (%d) out of range\n";
          }
          else {
            if (uVar11 < uVar12) {
              iVar5 = 1;
            }
            else {
              do {
                iVar1 = 1 << (ulong)(uVar11 & 0x1f);
                iVar5 = 2;
                if ((uVar11 & 0xff) == 0x1f) {
                  iVar5 = -2;
                }
                iVar3 = 0;
                if (iVar5 != 0) {
                  iVar3 = iVar1 / iVar5;
                }
                iVar5 = 0;
                if (iVar1 != 0) {
                  iVar5 = (int)(iVar3 + uVar13) / iVar1;
                }
                if (iVar5 < 2) {
                  iVar5 = 1;
                }
                if (0xfe < iVar5) {
                  iVar5 = 0xff;
                }
                iVar1 = iVar5 << (ulong)(uVar11 & 0x1f);
              } while ((iVar1 < (int)uVar2 || (int)uVar15 < iVar1) &&
                      (uVar11 = uVar11 - 1, uVar12 <= (uVar11 & 0xff)));
            }
            local_68[0] = (byte)uVar11;
            local_64[0] = local_68[0];
            uVar6 = drm_dp_dpcd_write(param_1,0x724,local_64,1);
            if ((int)uVar6 != 1) {
              if (param_1[0x9a] == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
              }
              uVar9 = *param_1;
              pcVar8 = "%s: Failed to write aux pwmgen bit count: %d\n";
              goto LAB_001079bc;
            }
            *param_2 = local_68[0];
            *(ushort *)(param_2 + 2) = ~(ushort)(-1 << (ulong)(local_68[0] & 0x1f));
            if ((*(byte *)(param_4 + 2) >> 5 & 1) == 0) goto LAB_001079c0;
            param_2[1] = (byte)iVar5;
            if (param_1[0x9a] == 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
            }
            uVar9 = *param_1;
            pcVar8 = "%s: Using backlight frequency from driver (%dHz)\n";
          }
          uVar6 = (ulong)(uint)param_3;
        }
        else {
          if (param_1[0x9a] == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
          }
          uVar9 = *param_1;
          pcVar8 = "%s: Failed to read pwmgen bit count cap max: %d\n";
        }
      }
      else {
        if (param_1[0x9a] == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
        }
        uVar9 = *param_1;
        pcVar8 = "%s: Failed to read pwmgen bit count cap min: %d\n";
      }
LAB_001079bc:
      __drm_dev_dbg(0,uVar7,2,pcVar8,uVar9,uVar6);
    }
  }
LAB_001079c0:
  local_5c = 0;
  local_60[0] = 0;
  iVar5 = drm_dp_dpcd_read(param_1,0x721,local_60,1);
  if (iVar5 == 1) {
    *param_6 = local_60[0] & 3;
    if ((param_2[4] >> 2 & 1) == 0) {
      uVar10 = 0;
    }
    else if ((local_60[0] & 3) == 2) {
      iVar1 = (param_2[4] & 1) + 1;
      iVar5 = drm_dp_dpcd_read(param_1,0x722,&local_5c,iVar1);
      if (iVar5 != iVar1) {
        if (param_1[0x9a] == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
        }
        uVar9 = *param_1;
        pcVar8 = "%s: Failed to read backlight level: %d\n";
        goto LAB_00107a68;
      }
      uVar10 = local_5c & 0xff;
      if ((param_2[4] & 1) != 0) {
        uVar10 = CONCAT11((undefined1)local_5c,local_5c._1_1_);
      }
    }
    else {
      uVar10 = *(ushort *)(param_2 + 2);
    }
    *param_5 = uVar10;
    if (param_1[0x9a] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar7,2,"%s: Found backlight: aux_set=%d aux_enable=%d mode=%d\n",*param_1,
                  param_2[4] >> 2 & 1,param_2[4] >> 1 & 1,*param_6);
    if ((param_2[4] >> 2 & 1) != 0) {
      if (param_1[0x9a] == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar7,2,
                    "%s: Backlight caps: level=%d/%d pwm_freq_pre_divider=%d lsb_reg_used=%d\n",
                    *param_1,*param_5,*(undefined2 *)(param_2 + 2),param_2[1],param_2[4] & 1);
    }
    iVar5 = 0;
  }
  else {
    if (param_1[0x9a] == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    uVar9 = *param_1;
    pcVar8 = "%s: Failed to read backlight mode: %d\n";
LAB_00107a68:
    __drm_dev_dbg(0,uVar7,2,pcVar8,uVar9,iVar5);
    if (-1 < iVar5) {
      iVar5 = -5;
    }
  }
LAB_00107b18:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar5);
  }
  return;
}



//------------------------------------------------------------
// drm_panel_dp_aux_backlight @ 00107c74 size=464
// signature: undefined drm_panel_dp_aux_backlight(void)
// callers: []
//------------------------------------------------------------

void drm_panel_dp_aux_backlight(long *param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  ulong *puVar3;
  code *pcVar4;
  ulong uVar5;
  undefined1 local_60 [4];
  ushort local_5c [2];
  uint local_58;
  uint uStack_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  ushort local_3c;
  undefined1 local_3a;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_50 = 0;
  local_48 = 0;
  local_5c[0] = 0;
  local_60[0] = 0;
  local_3a = 0;
  local_3c = 0;
  if (param_1 == (long *)0x0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0xffffffea;
    if (((param_2 != 0) && (*param_1 != 0)) &&
       (uVar2 = drm_dp_dpcd_read(param_2,0x700,&local_3c,3), -1 < (int)uVar2)) {
      if ((local_3c & 0x100) == 0) {
        drm_dev_printk(*param_1,&DAT_001142a4,"DP AUX backlight is not supported\n");
        uVar2 = 0;
      }
      else {
        puVar3 = (ulong *)devm_kmalloc(*param_1,0x18,0xdc0);
        if (puVar3 == (ulong *)0x0) {
          uVar2 = 0xfffffff4;
        }
        else {
          puVar3[1] = param_2;
          uVar2 = drm_edp_backlight_init(param_2,puVar3 + 2,0,&local_3c,local_5c,local_60);
          if (-1 < (int)uVar2) {
            local_48 = CONCAT44(local_48._4_4_,1);
            local_58 = (uint)local_5c[0];
            uStack_54 = (uint)*(ushort *)((long)puVar3 + 0x12);
            uVar2 = devm_backlight_device_register
                              (*param_1,"dp_aux_backlight",*param_1,puVar3,dp_aux_bl_ops,&local_58);
            *puVar3 = uVar2;
            if (uVar2 < 0xfffffffffffff001) {
              if (uVar2 == 0) {
                uVar5 = 0;
              }
              else {
                *(undefined8 *)(uVar2 + 8) = 0x400000004;
                *(uint *)(uVar2 + 0x14) = *(uint *)(uVar2 + 0x14) | 2;
                mutex_lock(uVar2 + 0x20);
                if ((*(long *)(uVar2 + 0x80) != 0) &&
                   (pcVar4 = *(code **)(*(long *)(uVar2 + 0x80) + 8), pcVar4 != (code *)0x0)) {
                  if (*(int *)(pcVar4 + -4) != -0xbdeb3af) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x107e1c);
                    (*pcVar4)();
                  }
                  (*pcVar4)(uVar2);
                }
                mutex_unlock(uVar2 + 0x20);
                uVar5 = *puVar3;
              }
              uVar2 = 0;
              param_1[1] = uVar5;
            }
            else {
              uVar2 = uVar2 & 0xffffffff;
            }
          }
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// __128b132b_channel_eq_delay_us @ 00107e48 size=104
// signature: undefined __128b132b_channel_eq_delay_us(void)
// callers: [drm_dp_read_clock_recovery_delay]
//------------------------------------------------------------

undefined4 __128b132b_channel_eq_delay_us(undefined8 *param_1,byte param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (param_2 < 7) {
    uVar1 = *(undefined4 *)(&DAT_00115c9c + (long)(char)param_2 * 4);
  }
  else {
    if (param_1[0x9a] == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar2,2,"%s: invalid AUX interval 0x%02x\n",*param_1);
    uVar1 = 400;
  }
  return uVar1;
}



//------------------------------------------------------------
// __8b10b_channel_eq_delay_us @ 00107eb4 size=116
// signature: undefined __8b10b_channel_eq_delay_us(void)
// callers: [drm_dp_read_channel_eq_delay]
//------------------------------------------------------------

int __8b10b_channel_eq_delay_us(undefined8 *param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar1 = (uint)param_2;
  if (4 < uVar1) {
    if (param_1[0x9a] == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(param_1[0x9a] + 8);
    }
    __drm_dev_dbg(0,uVar3,2,"%s: invalid AUX interval 0x%02x (max 4)\n",*param_1,uVar1);
  }
  iVar2 = 400;
  if (param_2 != 0) {
    iVar2 = uVar1 * 4000;
  }
  return iVar2;
}



//------------------------------------------------------------
// drm_dp_i2c_xfer @ 00107f2c size=644
// signature: undefined drm_dp_i2c_xfer(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_i2c_xfer(long param_1,long param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  ushort uVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  undefined8 uVar8;
  byte bVar9;
  undefined8 *puVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  short *psVar14;
  ulong uVar15;
  ushort *puVar16;
  undefined8 local_98;
  long local_90;
  ulong local_88;
  undefined8 local_80;
  long local_78;
  ulong local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  puVar10 = *(undefined8 **)(param_1 + 0x18);
  if (*(char *)((long)puVar10 + 0x629) == '\0') {
    local_98 = 0;
    if ((int)dp_aux_i2c_transfer_size < 2) {
      dp_aux_i2c_transfer_size = 1;
    }
    if (0xf < (int)dp_aux_i2c_transfer_size) {
      dp_aux_i2c_transfer_size = 0x10;
    }
    if (param_3 == 0) {
      bVar9 = 0;
      uVar12 = 0;
    }
    else {
      uVar15 = 0;
      do {
        local_90 = 0;
        local_88 = 0;
        psVar14 = (short *)(param_2 + uVar15 * 0x10 + 2);
        bVar4 = (byte)*psVar14;
        bVar9 = bVar4 & 1;
        if (-1 < *psVar14) {
          bVar9 = bVar4 & 1 | 4;
        }
        local_98._0_5_ = CONCAT14(bVar9,(uint)*(ushort *)(param_2 + uVar15 * 0x10));
        uVar7 = drm_dp_i2c_do_msg(puVar10,&local_98);
        bVar4 = (byte)*psVar14;
        bVar9 = bVar4 & 1;
        if (-1 < *psVar14) {
          bVar9 = bVar4 & 1 | 4;
        }
        local_98._0_5_ = CONCAT14(bVar9,(undefined4)local_98);
        if ((int)uVar7 < 0) {
          uVar12 = (ulong)uVar7;
          goto LAB_00108148;
        }
        lVar1 = param_2 + uVar15 * 0x10;
        puVar16 = (ushort *)(lVar1 + 4);
        uVar3 = *puVar16;
        uVar7 = (uint)uVar3;
        if (uVar3 != 0) {
          uVar11 = 0;
          uVar12 = (ulong)dp_aux_i2c_transfer_size;
          do {
            uVar2 = (uint)uVar12;
            if (uVar7 - uVar11 <= (uint)uVar12) {
              uVar2 = uVar7 - uVar11;
            }
            uVar12 = (ulong)uVar2;
            local_90 = *(long *)(lVar1 + 8) + (ulong)uVar11;
            local_80 = local_98;
            local_88 = uVar12;
            local_78 = local_90;
            local_70 = uVar12;
            if (uVar2 != 0) {
              do {
                uVar7 = drm_dp_i2c_do_msg(puVar10,&local_80);
                uVar13 = (ulong)uVar7;
                if ((int)uVar7 < 1) {
                  uVar2 = 0xffffffb9;
                  if (uVar7 != 0) {
                    uVar2 = uVar7;
                  }
                  uVar12 = (ulong)uVar2;
                  break;
                }
                bVar5 = false;
                bVar6 = false;
                if (uVar13 < local_70) {
                  bVar6 = SBORROW4(uVar7,(int)uVar12);
                  bVar5 = (int)(uVar7 - (int)uVar12) < 0;
                }
                if (bVar5 != bVar6) {
                  if (puVar10[0x9a] == 0) {
                    uVar8 = 0;
                  }
                  else {
                    uVar8 = *(undefined8 *)(puVar10[0x9a] + 8);
                  }
                  __drm_dev_dbg(0,uVar8,2,
                                "%s: Partial I2C reply: requested %zu bytes got %d bytes\n",*puVar10
                                ,local_70,uVar13);
                  uVar12 = uVar13;
                }
                local_70 = local_70 - uVar13;
                local_78 = local_78 + uVar13;
              } while (local_70 != 0);
            }
            bVar4 = (byte)*psVar14;
            bVar9 = bVar4 & 1;
            if (-1 < *psVar14) {
              bVar9 = bVar4 & 1 | 4;
            }
            local_98._0_5_ = CONCAT14(bVar9,(undefined4)local_98);
            if ((int)uVar12 < 0) goto LAB_00108148;
            uVar7 = (uint)*puVar16;
            uVar11 = uVar11 + (int)local_88;
          } while (uVar11 < uVar7);
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 != param_3);
      uVar12 = (ulong)param_3;
    }
LAB_00108148:
    local_90 = 0;
    local_88 = 0;
    local_98 = CONCAT35(local_98._5_3_,CONCAT14(bVar9,(undefined4)local_98)) & 0xffffff03ffffffff;
    drm_dp_i2c_do_msg(puVar10,&local_98);
  }
  else {
    uVar12 = 0xfffffff0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// drm_dp_i2c_functionality @ 001081b4 size=12
// signature: undefined drm_dp_i2c_functionality(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_i2c_functionality(void)

{
  return 0xfff800b;
}



//------------------------------------------------------------
// drm_dp_i2c_do_msg @ 001081c0 size=896
// signature: undefined drm_dp_i2c_do_msg(void)
// callers: [drm_dp_i2c_xfer]
//------------------------------------------------------------

uint drm_dp_i2c_do_msg(undefined8 *param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  
  uVar9 = (ulong)dp_aux_i2c_speed_khz;
  uVar12 = 0;
  uVar13 = 0;
  iVar6 = (int)*(long *)(param_2 + 0x10) * 8;
  iVar2 = 0;
  if (uVar9 != 0) {
    iVar2 = (int)((uVar9 + *(long *)(param_2 + 0x10) * 9000 + 10999) / uVar9);
  }
  iVar11 = iVar6 + 0x236;
  iVar3 = 0x2a;
  if ((*(byte *)(param_2 + 4) & 1) != 0) {
    iVar11 = 0x236;
    iVar3 = iVar6 + 0x2a;
  }
  iVar11 = iVar11 + iVar3;
  iVar6 = 0;
  if (iVar11 != 0) {
    iVar6 = (iVar2 + iVar11 + -1) / iVar11;
  }
  if (iVar6 < 8) {
    iVar6 = 7;
  }
  do {
    if (*(int *)((code *)param_1[0xa9] + -4) != 0x432a15d1) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10829c);
      (*pcVar4)();
    }
    uVar5 = (*(code *)param_1[0xa9])(param_1,param_2);
    if ((int)uVar5 < 0) {
      if (uVar5 != 0xfffffff0) {
        if (uVar5 != 0xffffff92) {
          if (param_1[0x9a] == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
          }
          __drm_dev_dbg(0,uVar7,2,"%s: transaction failed: %d\n",*param_1,uVar5);
          return uVar5;
        }
        if ((__drm_debug >> 2 & 1) != 0) {
          lVar10 = param_1[0x9a];
          iVar6 = ___ratelimit(drm_dp_i2c_do_msg_rs_,"drm_dp_i2c_do_msg");
          if (iVar6 != 0) {
            if (lVar10 == 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = *(undefined8 *)(lVar10 + 8);
            }
            drm_dev_printk(uVar7,&DAT_001152e3,"%s: transaction timed out\n",*param_1);
            return 0xffffff92;
          }
        }
        return 0xffffff92;
      }
    }
    else {
      bVar1 = *(byte *)(param_2 + 5);
      if ((bVar1 & 3) == 0) {
        if ((bVar1 & 0xc) != 8) {
          if ((bVar1 & 0xc) == 4) {
            if (param_1[0x9a] == 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
            }
            __drm_dev_dbg(0,uVar7,2,"%s: I2C nack (result=%d, size=%zu)\n",*param_1,uVar5,
                          *(undefined8 *)(param_2 + 0x10));
            *(int *)(param_1 + 0xab) = *(int *)(param_1 + 0xab) + 1;
            return 0xffffff87;
          }
          if ((bVar1 & 0xc) == 0) {
            if (*(ulong *)(param_2 + 0x10) == (ulong)uVar5) {
              return uVar5;
            }
            if ((*(byte *)(param_2 + 4) & 0xfb) == 0) {
              *(byte *)(param_2 + 4) = *(byte *)(param_2 + 4) & 4 | 2;
              return uVar5;
            }
            return uVar5;
          }
          lVar10 = param_1[0x9a];
          pcVar8 = "[drm] *ERROR* %s: invalid I2C reply %#04x\n";
          goto LAB_00108530;
        }
        if (param_1[0x9a] == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
        }
        __drm_dev_dbg(0,uVar7,2,"%s: I2C defer\n",*param_1);
        if (uVar12 < 7) {
          uVar12 = uVar12 + 1;
        }
        *(int *)((long)param_1 + 0x55c) = *(int *)((long)param_1 + 0x55c) + 1;
        usleep_range_state(500,600,2);
        if ((*(byte *)(param_2 + 4) & 0xfb) == 0) {
          *(byte *)(param_2 + 4) = *(byte *)(param_2 + 4) & 4 | 2;
        }
      }
      else {
        if ((bVar1 & 3) != 2) {
          if ((bVar1 & 3) == 1) {
            if (param_1[0x9a] == 0) {
              uVar7 = 0;
            }
            else {
              uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
            }
            __drm_dev_dbg(0,uVar7,2,"%s: native nack (result=%d, size=%zu)\n",*param_1,uVar5,
                          *(undefined8 *)(param_2 + 0x10));
            return 0xffffff87;
          }
          lVar10 = param_1[0x9a];
          pcVar8 = "[drm] *ERROR* %s: invalid native reply %#04x\n";
LAB_00108530:
          _dev_err(*(undefined8 *)(lVar10 + 8),pcVar8,*param_1);
          return 0xffffff87;
        }
        if (param_1[0x9a] == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
        }
        __drm_dev_dbg(0,uVar7,2,"%s: native defer\n",*param_1);
        usleep_range_state(500,600,2);
      }
    }
    uVar13 = uVar13 + 1;
    if (uVar12 + iVar6 <= uVar13) {
      if (param_1[0x9a] == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined8 *)(param_1[0x9a] + 8);
      }
      __drm_dev_dbg(0,uVar7,2,"%s: Too many retries, giving up\n",*param_1);
      return 0xffffff87;
    }
  } while( true );
}



//------------------------------------------------------------
// lock_bus @ 00108544 size=32
// signature: undefined lock_bus(void)
// callers: []
//------------------------------------------------------------

void lock_bus(long param_1)

{
  mutex_lock(param_1 + 0x4d8);
  return;
}



//------------------------------------------------------------
// trylock_bus @ 00108568 size=32
// signature: undefined trylock_bus(void)
// callers: []
//------------------------------------------------------------

void trylock_bus(long param_1)

{
  mutex_trylock(param_1 + 0x4d8);
  return;
}



//------------------------------------------------------------
// unlock_bus @ 0010858c size=32
// signature: undefined unlock_bus(void)
// callers: []
//------------------------------------------------------------

void unlock_bus(long param_1)

{
  mutex_unlock(param_1 + 0x4d8);
  return;
}



//------------------------------------------------------------
// dp_aux_backlight_update_status @ 001085b0 size=328
// signature: undefined dp_aux_backlight_update_status(void)
// callers: []
//------------------------------------------------------------

void dp_aux_backlight_update_status(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  long lVar5;
  short local_2c [2];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x52);
  if ((param_1[2] == 0) && (param_1[3] == 0)) {
    if ((param_1[5] & 3) == 0) {
      uVar2 = *param_1;
    }
    else {
      uVar2 = 0;
    }
    if ((param_1[5] & 3) != 0) goto LAB_00108608;
    puVar4 = *(undefined8 **)(lVar5 + 8);
    if (*(char *)(lVar5 + 0x16) == '\0') {
      drm_edp_backlight_enable(puVar4,lVar5 + 0x10);
      iVar1 = 0;
      *(undefined1 *)(lVar5 + 0x16) = 1;
      goto LAB_001086a0;
    }
    iVar1 = 0;
    local_2c[0] = 0;
    if ((*(byte *)(lVar5 + 0x14) >> 2 & 1) == 0) goto LAB_001086a0;
    if ((*(byte *)(lVar5 + 0x14) & 1) == 0) {
      uVar3 = uVar2;
    }
    else {
      uVar3 = uVar2 >> 8 & 0xff;
      local_2c[0] = (ushort)(byte)uVar2 << 8;
    }
    local_2c[0] = CONCAT11(local_2c[0]._1_1_,(char)uVar3);
    iVar1 = drm_dp_dpcd_write(puVar4,0x722,local_2c,2);
    if (iVar1 != 2) {
      _dev_err(*(undefined8 *)(puVar4[0x9a] + 8),
               "[drm] *ERROR* %s: Failed to write aux backlight level: %d\n",*puVar4,iVar1);
      if (-1 < iVar1) {
        iVar1 = -5;
      }
      goto LAB_001086a0;
    }
  }
  else {
LAB_00108608:
    if (*(char *)(lVar5 + 0x16) != '\0') {
      drm_edp_backlight_set_enable(*(undefined8 *)(lVar5 + 8),lVar5 + 0x10,0);
      iVar1 = 0;
      *(undefined1 *)(lVar5 + 0x16) = 0;
      goto LAB_001086a0;
    }
  }
  iVar1 = 0;
LAB_001086a0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_encode_sideband_req @ 001086fc size=940
// signature: undefined drm_dp_encode_sideband_req(void)
// callers: [drm_dp_mst_link_probe_work, drm_dp_send_query_stream_enc_status, drm_dp_send_dpcd_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_send_link_address, drm_dp_payload_send_msg, drm_dp_send_power_updown_phy, drm_dp_send_enum_path_resources]
//------------------------------------------------------------

void drm_dp_encode_sideband_req(byte *param_1,byte *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  byte *pbVar8;
  
  iVar4 = 1;
  *param_2 = *param_1 & 0x7f;
  switch(*param_1) {
  case 0x10:
  case 0x24:
  case 0x25:
    iVar4 = 2;
    param_2[1] = param_1[8] << 4;
    break;
  case 0x11:
    param_2[1] = param_1[9] & 0xf | param_1[8] << 4;
    param_2[2] = param_1[10] & 0x7f;
    param_2[3] = param_1[0xd];
    param_2[4] = param_1[0xc];
    bVar3 = param_1[9];
    if (bVar3 < 2) {
      lVar5 = 5;
    }
    else {
      lVar5 = 5;
      pbVar8 = param_1 + 0xf;
      do {
        param_2[lVar5] = *pbVar8 & 0xf | pbVar8[-1] << 4;
        uVar6 = lVar5 - 4;
        bVar3 = param_1[9];
        lVar5 = lVar5 + 1;
        pbVar8 = pbVar8 + 2;
      } while (uVar6 < bVar3 >> 1);
    }
    iVar4 = (int)lVar5;
    if ((bVar3 & 1) != 0) {
      param_2[iVar4] = param_1[(ulong)(bVar3 - 1) + 0xe] << 4;
      iVar4 = iVar4 + 1;
    }
    break;
  case 0x12:
    param_2[1] = param_1[8] << 4;
    iVar4 = 3;
    param_2[2] = param_1[9] & 0x7f;
    break;
  case 0x20:
    bVar3 = param_1[8];
    param_2[1] = bVar3 << 4;
    param_2[1] = bVar3 << 4 | param_1[0xe] & 0xf;
    param_2[2] = (byte)((uint)*(undefined4 *)(param_1 + 0xc) >> 8);
    param_2[3] = (byte)*(undefined4 *)(param_1 + 0xc);
    iVar4 = 5;
    param_2[4] = param_1[0x10];
    break;
  case 0x21:
    bVar3 = param_1[8];
    param_2[1] = bVar3 << 4;
    param_2[1] = bVar3 << 4 | param_1[0xe] & 0xf;
    param_2[2] = (byte)((uint)*(undefined4 *)(param_1 + 0xc) >> 8);
    param_2[3] = (byte)*(undefined4 *)(param_1 + 0xc);
    param_2[4] = param_1[0x10];
    memcpy(param_2 + 5,*(void **)(param_1 + 0x18),(ulong)param_1[0x10]);
    iVar4 = param_1[0x10] + 5;
    break;
  case 0x22:
    bVar3 = param_1[9];
    param_2[1] = bVar3 << 4;
    param_2[1] = bVar3 << 4 | param_1[8] & 3;
    if ((param_1[8] & 3) == 0) {
      uVar6 = 2;
    }
    else {
      param_2[2] = param_1[0x10] & 0x7f;
      param_2[3] = param_1[0x11];
      memcpy(param_2 + 4,*(void **)(param_1 + 0x18),(ulong)param_1[0x11]);
      uVar7 = (ulong)param_1[0x11];
      bVar3 = param_1[0x20];
      param_2[uVar7 + 4] = (byte)((bVar3 & 1) << 4);
      uVar6 = uVar7 + 5;
      param_2[uVar7 + 4] = param_1[0x21] & 0xf | (byte)((bVar3 & 1) << 4);
      if ((param_1[8] >> 1 & 1) != 0) {
        param_2[uVar6] = param_1[0x28] & 0x7f;
        param_2[uVar7 + 6] = param_1[0x29];
        memcpy(param_2 + uVar7 + 7,*(void **)(param_1 + 0x30),(ulong)param_1[0x29]);
        bVar3 = param_1[0x38];
        lVar5 = uVar7 + 7 + (ulong)param_1[0x29];
        param_2[lVar5] = (byte)((bVar3 & 1) << 4);
        uVar6 = lVar5 + 1;
        param_2[lVar5] = param_1[0x39] & 0xf | (byte)((bVar3 & 1) << 4);
        if (((param_1[8] ^ 0xff) & 3) == 0) {
          param_2[uVar6] = param_1[0x40] & 0x7f;
          param_2[lVar5 + 2] = param_1[0x41];
          memcpy(param_2 + lVar5 + 3,*(void **)(param_1 + 0x48),(ulong)param_1[0x41]);
          bVar3 = param_1[0x50];
          lVar5 = lVar5 + 3 + (ulong)param_1[0x41];
          param_2[lVar5] = (byte)((bVar3 & 1) << 4);
          uVar6 = (ulong)((int)lVar5 + 1);
          param_2[lVar5] = param_1[0x51] & 0xf | (byte)((bVar3 & 1) << 4);
        }
      }
    }
    param_2[uVar6] = param_1[0x70] & 0x7f;
    iVar4 = (int)uVar6 + 2;
    param_2[(int)uVar6 + 1] = param_1[0x71];
    break;
  case 0x23:
    param_2[1] = param_1[8] << 4;
    param_2[2] = param_1[9] & 0x7f;
    param_2[3] = param_1[10];
    memcpy(param_2 + 4,*(void **)(param_1 + 0x10),(ulong)param_1[10]);
    iVar4 = param_1[10] + 4;
    break;
  case 0x38:
    param_2[1] = param_1[8];
    uVar1 = *(undefined4 *)(param_1 + 0xc);
    uVar2 = *(undefined4 *)(param_1 + 9);
    param_2[9] = 0;
    *(undefined4 *)(param_2 + 5) = uVar1;
    *(undefined4 *)(param_2 + 2) = uVar2;
    bVar3 = param_1[0x10];
    param_2[9] = bVar3 & 3;
    bVar3 = bVar3 & 3 | param_1[0x11] << 2;
    param_2[9] = bVar3;
    bVar3 = (param_1[0x12] & 3) << 3 | bVar3;
    param_2[9] = bVar3;
    iVar4 = 10;
    param_2[9] = bVar3 | (param_1[0x13] != 0) << 5;
  }
  param_2[0x131] = (byte)iVar4;
  return;
}



//------------------------------------------------------------
// drm_dp_decode_sideband_req @ 00108aac size=920
// signature: undefined drm_dp_decode_sideband_req(void)
// callers: [drm_dp_mst_dump_sideband_msg_tx]
//------------------------------------------------------------

undefined8 drm_dp_decode_sideband_req(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  byte *pbVar8;
  
  bVar1 = *param_1;
  *param_2 = bVar1 & 0x7f;
  switch(bVar1 & 0x7f) {
  case 0x10:
  case 0x24:
  case 0x25:
    param_2[8] = param_1[1] >> 4;
    break;
  case 0x11:
    bVar1 = param_1[1];
    uVar3 = bVar1 & 0xf;
    param_2[9] = (byte)uVar3;
    param_2[8] = param_1[1] >> 4;
    if ((char)param_1[2] < '\0') {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x108e3c);
      (*pcVar4)();
    }
    param_2[10] = param_1[2] & 0x7f;
    bVar2 = param_1[3];
    *(ushort *)(param_2 + 0xc) = (ushort)bVar2 << 8;
    *(ushort *)(param_2 + 0xc) = CONCAT11(bVar2,param_1[4]);
    if ((bVar1 & 0xf) != 0) {
      uVar7 = 0;
      do {
        param_2[uVar7 + 0xe] =
             param_1[(uVar7 >> 1 & 0x7fffffff) + 5] >> (ulong)(((int)uVar7 << 2 ^ 0xffffffffU) & 4)
             & 0xf;
        uVar7 = uVar7 + 1;
      } while (uVar3 != uVar7);
    }
    break;
  case 0x12:
    param_2[8] = param_1[1] >> 4;
    if ((char)param_1[2] < '\0') {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x108e4c);
      (*pcVar4)();
    }
    param_2[9] = param_1[2] & 0x7f;
    break;
  case 0x20:
    param_2[8] = param_1[1] >> 4;
    uVar3 = (param_1[1] & 0xf) << 0x10;
    *(uint *)(param_2 + 0xc) = uVar3;
    uVar3 = uVar3 | (uint)param_1[2] << 8;
    *(uint *)(param_2 + 0xc) = uVar3;
    *(uint *)(param_2 + 0xc) = uVar3 | param_1[3];
    param_2[0x10] = param_1[4];
    break;
  case 0x21:
    param_2[8] = param_1[1] >> 4;
    uVar3 = (param_1[1] & 0xf) << 0x10;
    *(uint *)(param_2 + 0xc) = uVar3;
    uVar3 = uVar3 | (uint)param_1[2] << 8;
    *(uint *)(param_2 + 0xc) = uVar3;
    *(uint *)(param_2 + 0xc) = uVar3 | param_1[3];
    bVar1 = param_1[4];
    param_2[0x10] = bVar1;
    lVar5 = kmemdup(param_1 + 5,bVar1,0xcc0);
    *(long *)(param_2 + 0x18) = lVar5;
    goto joined_r0x00108d0c;
  case 0x22:
    bVar1 = param_1[1];
    param_2[8] = bVar1 & 3;
    param_2[9] = param_1[1] >> 4;
    if ((bVar1 & 3) == 0) {
      iVar6 = 1;
    }
    else {
      uVar7 = 0;
      pbVar8 = param_2 + 0x10;
      iVar6 = 1;
      do {
        if (uVar7 == 5) {
LAB_00108e54:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x108e58);
          (*pcVar4)();
        }
        *pbVar8 = param_1[iVar6 + 1] & 0x7f;
        bVar1 = param_1[iVar6 + 2];
        pbVar8[1] = bVar1;
        lVar5 = kmemdup(param_1 + (iVar6 + 3),bVar1,0xcc0);
        *(long *)(pbVar8 + 8) = lVar5;
        if (lVar5 == 0) {
          if (param_2[8] == 0) {
            return 0xfffffff4;
          }
          kfree(*(undefined8 *)(param_2 + 0x18));
          if (param_2[8] < 2) {
            return 0xfffffff4;
          }
          kfree(*(undefined8 *)(param_2 + 0x30));
          if (param_2[8] < 3) {
            return 0xfffffff4;
          }
          kfree(*(undefined8 *)(param_2 + 0x48));
          if (param_2[8] < 4) {
            return 0xfffffff4;
          }
          kfree(*(undefined8 *)(param_2 + 0x60));
          if (param_2[8] < 5) {
            return 0xfffffff4;
          }
          kfree(*(undefined8 *)(param_2 + 0x78));
          if (param_2[8] < 6) {
            return 0xfffffff4;
          }
          goto LAB_00108e54;
        }
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 3 + (uint)pbVar8[1];
        pbVar8[0x10] = param_1[iVar6] >> 5 & 1;
        pbVar8[0x11] = param_1[iVar6] & 0xf;
        pbVar8 = pbVar8 + 0x18;
      } while (uVar7 < param_2[8]);
    }
    param_2[0x70] = param_1[iVar6 + 1] & 0x7f;
    param_2[0x71] = param_1[iVar6 + 2];
    break;
  case 0x23:
    param_2[8] = param_1[1] >> 4;
    param_2[9] = param_1[2] & 0x7f;
    bVar1 = param_1[3];
    param_2[10] = bVar1;
    lVar5 = kmemdup(param_1 + 4,bVar1,0xcc0);
    *(long *)(param_2 + 0x10) = lVar5;
joined_r0x00108d0c:
    if (lVar5 == 0) {
      return 0xfffffff4;
    }
    break;
  case 0x38:
    param_2[8] = param_1[1];
    param_2[9] = param_1[2];
    param_2[10] = param_1[3];
    param_2[0xb] = param_1[4];
    param_2[0xc] = param_1[5];
    param_2[0xd] = param_1[6];
    param_2[0xe] = param_1[7];
    param_2[0xf] = param_1[8];
    param_2[0x10] = param_1[9] & 3;
    param_2[0x11] = param_1[9] >> 2 & 1;
    param_2[0x12] = param_1[9] >> 3 & 3;
    param_2[0x13] = param_1[9] >> 5 & 1;
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_dump_sideband_msg_req_body @ 00108e5c size=1012
// signature: undefined drm_dp_dump_sideband_msg_req_body(void)
// callers: [drm_dp_mst_dump_sideband_msg_tx]
//------------------------------------------------------------

void drm_dp_dump_sideband_msg_req_body(byte *param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  char *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar8;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar9;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 uVar10;
  
  uVar8 = (undefined4)((ulong)in_stack_ffffffffffffffb0 >> 0x20);
  uVar9 = (undefined4)((ulong)in_stack_ffffffffffffffb8 >> 0x20);
  uVar10 = (undefined4)((ulong)in_stack_ffffffffffffffc0 >> 0x20);
  bVar2 = *param_1;
  if (bVar2 == 1) {
    drm_printf(param_3,"%.*stype=%s\n",param_2,"\t\t\t\t\tX","LINK_ADDRESS");
    return;
  }
  pcVar5 = "unknown";
  if ((bVar2 < 0x39) &&
     (pcVar5 = (&drm_dp_mst_req_type_str_req_type_str)[bVar2],
     (0xfeffc0ffe0fff8U >> ((ulong)bVar2 & 0x3f) & 1) != 0)) {
    pcVar5 = "unknown";
  }
  drm_printf(param_3,"%.*stype=%s contents:\n",param_2,"\t\t\t\t\tX",pcVar5);
  iVar1 = param_2 + 1;
  switch(*param_1) {
  case 0x10:
  case 0x24:
  case 0x25:
    drm_printf(param_3,"%.*sport=%d\n",iVar1,"\t\t\t\t\tX",param_1[8]);
    break;
  case 0x11:
    drm_printf(param_3,"%.*sport=%d vcpi=%d pbn=%d sdp_streams=%d %*ph\n",iVar1,"\t\t\t\t\tX",
               param_1[8],param_1[10],*(undefined2 *)(param_1 + 0xc),param_1[9],
               CONCAT44(uVar8,(uint)param_1[9]),param_1 + 0xe);
    break;
  case 0x12:
    drm_printf(param_3,"%.*sport=%d vcpi=%d\n",iVar1,"\t\t\t\t\tX",param_1[8],param_1[9]);
    break;
  default:
    drm_printf(param_3,"%.*s???\n",iVar1,"\t\t\t\t\tX");
    break;
  case 0x20:
    drm_printf(param_3,"%.*sport=%d dpcd_addr=%05x len=%d\n",iVar1,"\t\t\t\t\tX",param_1[8],
               *(undefined4 *)(param_1 + 0xc),param_1[0x10]);
    break;
  case 0x21:
    bVar2 = param_1[8];
    pcVar5 = "%.*sport=%d addr=%05x len=%d: %*ph\n";
    uVar6 = *(uint *)(param_1 + 0xc);
    bVar3 = param_1[0x10];
    uVar7 = *(undefined8 *)(param_1 + 0x18);
    goto LAB_001091dc;
  case 0x22:
    drm_printf(param_3,"%.*sport=%d num_tx=%d id=%d size=%d:\n",iVar1,"\t\t\t\t\tX",param_1[9],
               param_1[8],param_1[0x70],param_1[0x71]);
    if (param_1[8] != 0) {
      param_2 = param_2 + 2;
      drm_printf(param_3,"%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",param_2,
                 "\t\t\t\t\tX",0,param_1[0x10],param_1[0x11],param_1[0x20],
                 CONCAT44(uVar8,(uint)param_1[0x21]),CONCAT44(uVar9,(uint)param_1[0x11]),
                 *(undefined8 *)(param_1 + 0x18));
      if ((((1 < param_1[8]) &&
           (drm_printf(param_3,"%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                       param_2,"\t\t\t\t\tX",1,param_1[0x28],param_1[0x29],param_1[0x38],
                       param_1[0x39],param_1[0x29],*(undefined8 *)(param_1 + 0x30)), 2 < param_1[8])
           ) && (drm_printf(param_3,"%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n"
                            ,param_2,"\t\t\t\t\tX",2,param_1[0x40],param_1[0x41],param_1[0x50],
                            param_1[0x51],param_1[0x41],*(undefined8 *)(param_1 + 0x48)),
                3 < param_1[8])) &&
         ((drm_printf(param_3,"%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                      param_2,"\t\t\t\t\tX",3,param_1[0x58],param_1[0x59],param_1[0x68],
                      param_1[0x69],param_1[0x59],*(undefined8 *)(param_1 + 0x60)), 4 < param_1[8]
          && (drm_printf(param_3,"%.*s%d: id=%03d size=%03d no_stop_bit=%d tx_delay=%03d: %*ph\n",
                         param_2,"\t\t\t\t\tX",4,param_1[0x70],param_1[0x71],param_1[0x80],
                         param_1[0x81],param_1[0x71],*(undefined8 *)(param_1 + 0x78)),
             5 < param_1[8])))) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1091c4);
        (*pcVar4)();
      }
    }
    break;
  case 0x23:
    bVar2 = param_1[8];
    pcVar5 = "%.*sport=%d id=%d size=%d: %*ph\n";
    uVar6 = (uint)param_1[9];
    bVar3 = param_1[10];
    uVar7 = *(undefined8 *)(param_1 + 0x10);
LAB_001091dc:
    drm_printf(param_3,pcVar5,iVar1,"\t\t\t\t\tX",bVar2,uVar6,bVar3,bVar3,uVar7);
    break;
  case 0x38:
    drm_printf(param_3,
               "%.*sstream_id=%u client_id=%*ph stream_event=%x valid_event=%d stream_behavior=%x valid_behavior=%d"
               ,iVar1,"\t\t\t\t\tX",param_1[8],7,param_1 + 9,param_1[0x10],
               CONCAT44(uVar8,(uint)param_1[0x11]),CONCAT44(uVar9,(uint)param_1[0x12]),
               CONCAT44(uVar10,(uint)param_1[0x13]));
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_get_port_malloc @ 00109254 size=152
// signature: undefined drm_dp_mst_get_port_malloc(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_get_port_malloc(long param_1)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  
  puVar1 = (uint *)(param_1 + 4);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 0) {
    uVar5 = 2;
  }
  else {
    if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00109288;
    uVar5 = 1;
  }
  refcount_warn_saturate(puVar1,uVar5);
LAB_00109288:
  lVar6 = *(long *)(*(long *)(param_1 + 0x678) + 0x68);
  if (lVar6 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined8 *)(lVar6 + 8);
  }
  __drm_dev_dbg(0,uVar5,1,"port %p (%d)\n",param_1,*(undefined4 *)(param_1 + 4));
  return;
}



//------------------------------------------------------------
// drm_dp_mst_put_port_malloc @ 001092fc size=248
// signature: undefined drm_dp_mst_put_port_malloc(void)
// callers: [drm_dp_mst_destroy_state, drm_dp_mst_duplicate_state, drm_dp_remove_payload, drm_dp_free_mst_branch_device, drm_dp_mst_topology_put_port, drm_dp_delayed_destroy_work]
//------------------------------------------------------------

void drm_dp_mst_put_port_malloc(long param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  int *piVar7;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x678) + 0x68);
  if (lVar5 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(lVar5 + 8);
  }
  piVar7 = (int *)(param_1 + 4);
  __drm_dev_dbg(0,uVar4,1,"port %p (%d)\n",param_1,*piVar7 + -1);
  Hint_Prefetch(piVar7,2,0,1);
  do {
    iVar1 = *piVar7;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar7,0x10);
    if (bVar3) {
      *piVar7 = iVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (iVar1 == 1) {
    DataMemoryBarrier(2,1);
    lVar5 = *(long *)(param_1 + 0x668);
    lVar6 = *(long *)(*(long *)(lVar5 + 0x40) + 0x68);
    if (lVar6 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(lVar6 + 8);
    }
    __drm_dev_dbg(0,uVar4,1,"mstb %p (%d)\n",lVar5,*(int *)(lVar5 + 4) + -1);
    kref_put((int *)(lVar5 + 4),drm_dp_free_mst_branch_device);
    kfree(param_1);
  }
  else if (iVar1 < 1) {
    refcount_warn_saturate(piVar7,3);
  }
  return;
}



//------------------------------------------------------------
// kref_put @ 00109404 size=116
// signature: undefined kref_put(void)
// callers: [drm_dp_mst_put_port_malloc]
//------------------------------------------------------------

void kref_put(int *param_1,code *param_2)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  
  Hint_Prefetch(param_1,2,0,1);
  do {
    iVar1 = *param_1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
    if (bVar3) {
      *param_1 = iVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (iVar1 == 1) {
    DataMemoryBarrier(2,1);
    if (*(int *)(param_2 + -4) != -0x214e6a45) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8221,0x109440);
      (*pcVar4)();
    }
    (*param_2)();
  }
  else if (iVar1 < 1) {
    refcount_warn_saturate(param_1,3);
  }
  return;
}



//------------------------------------------------------------
// drm_atomic_get_mst_payload_state @ 0010948c size=48
// signature: undefined drm_atomic_get_mst_payload_state(void)
// callers: []
//------------------------------------------------------------

long drm_atomic_get_mst_payload_state(long param_1,long param_2)

{
  long *plVar1;
  
  plVar1 = (long *)(param_1 + 0x38);
  do {
    plVar1 = (long *)*plVar1;
    if (plVar1 == (long *)(param_1 + 0x38)) {
      return 0;
    }
  } while (plVar1[-3] != param_2);
  return (long)(plVar1 + -3);
}



//------------------------------------------------------------
// drm_dp_mst_dpcd_read @ 001094c0 size=484
// signature: undefined drm_dp_mst_dpcd_read(void)
// callers: [drm_dp_dpcd_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long drm_dp_mst_dpcd_read(long param_1,undefined4 param_2,void *param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  size_t __n;
  undefined8 local_d0;
  uint local_c8;
  undefined4 local_c4;
  ulong local_c0;
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
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  lVar7 = *(long *)(param_1 + 0x648);
  uVar6 = *(undefined8 *)(param_1 + 0x638);
  lVar5 = lVar7 + 800;
  mutex_lock(lVar5);
  if (((*(long *)(lVar7 + 0x388) == 0) ||
      (lVar4 = drm_dp_mst_topology_get_mstb_validated_locked(*(long *)(lVar7 + 0x388),uVar6),
      lVar4 == 0)) || (iVar2 = drm_dp_mst_topology_try_get_mstb(), iVar2 == 0)) {
    mutex_unlock(lVar5);
    iVar2 = -0x16;
  }
  else {
    mutex_unlock(lVar5);
    lVar5 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
    if (lVar5 == 0) {
      iVar2 = -0xc;
    }
    else {
      local_68 = 0;
      uStack_60 = 0;
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
      local_d0 = 0x20;
      _local_c8 = CONCAT44(param_2,(uint)*(byte *)(param_1 + -0x28));
      local_c0 = (ulong)(byte)param_4;
      drm_dp_encode_sideband_req(&local_d0,lVar5);
      *(undefined8 *)(lVar5 + 0x138) = *(undefined8 *)(param_1 + 0x638);
      drm_dp_queue_down_tx(lVar7,lVar5);
      uVar3 = drm_dp_mst_wait_tx_reply(lVar4,lVar5);
      if ((int)uVar3 < 0) {
        __n = (size_t)uVar3;
      }
      else if (*(char *)(lVar5 + 0x15a) == '\x01') {
        if (*(long *)(lVar7 + 0x68) == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined8 *)(*(long *)(lVar7 + 0x68) + 8);
        }
        __drm_dev_dbg(0,uVar6,2,"mstb %p port %d: DPCD read on addr 0x%x for %d bytes NAKed\n",lVar4
                      ,*(undefined1 *)(param_1 + -0x28),param_2,param_4);
        __n = 0xfffffffb;
      }
      else {
        bVar1 = *(byte *)(lVar5 + 0x15d);
        if (bVar1 == param_4) {
          __n = (ulong)bVar1;
          if ((ulong)param_4 <= (ulong)bVar1) {
            __n = (ulong)param_4;
          }
          memcpy(param_3,(void *)(lVar5 + 0x15e),__n);
        }
        else {
          __n = 0xffffffb9;
        }
      }
      iVar2 = (int)__n;
      kfree(lVar5);
    }
    drm_dp_mst_topology_put_mstb(lVar4);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// drm_dp_mst_dpcd_write @ 001096a8 size=48
// signature: undefined drm_dp_mst_dpcd_write(void)
// callers: [drm_dp_dpcd_write]
//------------------------------------------------------------

long drm_dp_mst_dpcd_write(long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = drm_dp_send_dpcd_write
                    (*(undefined8 *)(param_1 + 0x648),param_1 + -0x30,param_2,param_4,param_3);
  return (long)iVar1;
}



//------------------------------------------------------------
// drm_dp_send_dpcd_write @ 001096d8 size=376
// signature: undefined drm_dp_send_dpcd_write(void)
// callers: [drm_dp_mst_topology_mgr_resume, drm_dp_mst_dpcd_write, drm_dp_send_link_address]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_send_dpcd_write
              (long param_1,long param_2,undefined4 param_3,int param_4,undefined8 param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 local_d0;
  uint local_c8;
  undefined4 local_c4;
  ulong local_c0;
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
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  lVar3 = param_1 + 800;
  local_58 = *(long *)(lVar2 + 0x638);
  uVar4 = *(undefined8 *)(param_2 + 0x668);
  mutex_lock(lVar3);
  if (((*(long *)(param_1 + 0x388) == 0) ||
      (lVar2 = drm_dp_mst_topology_get_mstb_validated_locked(*(long *)(param_1 + 0x388),uVar4),
      lVar2 == 0)) || (iVar1 = drm_dp_mst_topology_try_get_mstb(), iVar1 == 0)) {
    mutex_unlock(lVar3);
    iVar1 = -0x16;
  }
  else {
    mutex_unlock(lVar3);
    lVar3 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
    if (lVar3 == 0) {
      iVar1 = -0xc;
    }
    else {
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      uStack_b0 = 0;
      local_d0 = 0x21;
      _local_c8 = CONCAT44(param_3,(uint)*(byte *)(param_2 + 8));
      local_c0 = (ulong)(byte)param_4;
      local_b8 = param_5;
      drm_dp_encode_sideband_req(&local_d0,lVar3);
      *(long *)(lVar3 + 0x138) = lVar2;
      drm_dp_queue_down_tx(param_1,lVar3);
      iVar1 = drm_dp_mst_wait_tx_reply(lVar2,lVar3);
      if ((0 < iVar1) && (iVar1 = -5, *(char *)(lVar3 + 0x15a) != '\x01')) {
        iVar1 = param_4;
      }
      kfree(lVar3);
    }
    drm_dp_mst_topology_put_mstb(lVar2);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dp_mst_connector_late_register @ 00109854 size=108
// signature: undefined drm_dp_mst_connector_late_register(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_mst_connector_late_register(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_2 + 0x678) + 0x68);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined8 *)(lVar2 + 8);
  }
  __drm_dev_dbg(0,uVar1,2,"registering %s remote bus for %s\n",*(undefined8 *)(param_2 + 0x30),
                **(undefined8 **)(param_1 + 8));
  *(undefined8 *)(param_2 + 0x4f8) = *(undefined8 *)(param_1 + 8);
  return 0;
}



//------------------------------------------------------------
// drm_dp_mst_connector_early_unregister @ 001098c4 size=76
// signature: undefined drm_dp_mst_connector_early_unregister(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_connector_early_unregister(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(param_2 + 0x678) + 0x68);
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  __drm_dev_dbg(0,uVar2,2,"unregistering %s remote bus for %s\n",*(undefined8 *)(param_2 + 0x30),
                **(undefined8 **)(param_1 + 8));
  return;
}



//------------------------------------------------------------
// drm_dp_send_power_updown_phy @ 00109914 size=368
// signature: undefined drm_dp_send_power_updown_phy(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_send_power_updown_phy(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  byte bVar4;
  ulong local_b0;
  ulong local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
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
  
  lVar2 = sp_el0;
  lVar3 = param_1 + 800;
  local_38 = *(long *)(lVar2 + 0x638);
  mutex_lock(lVar3);
  if (((*(long *)(param_1 + 0x388) == 0) ||
      (lVar2 = drm_dp_mst_topology_get_port_validated_locked(*(long *)(param_1 + 0x388),param_2),
      lVar2 == 0)) || (iVar1 = drm_dp_mst_topology_try_get_port(), iVar1 == 0)) {
    mutex_unlock(lVar3);
    iVar1 = -0x16;
  }
  else {
    mutex_unlock(lVar3);
    lVar3 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
    if (lVar3 == 0) {
      drm_dp_mst_topology_put_port(lVar2);
      iVar1 = -0xc;
    }
    else {
      bVar4 = 0x24;
      if ((param_3 & 1) == 0) {
        bVar4 = 0x25;
      }
      *(undefined8 *)(lVar3 + 0x138) = *(undefined8 *)(lVar2 + 0x668);
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a0 = 0;
      local_b0 = (ulong)bVar4;
      local_a8 = (ulong)*(byte *)(lVar2 + 8);
      drm_dp_encode_sideband_req(&local_b0,lVar3);
      *(undefined1 *)(lVar3 + 0x158) = 1;
      drm_dp_queue_down_tx(param_1,lVar3);
      iVar1 = drm_dp_mst_wait_tx_reply(*(undefined8 *)(lVar2 + 0x668),lVar3);
      if ((0 < iVar1) && (iVar1 = -0x16, *(char *)(lVar3 + 0x15a) != '\x01')) {
        iVar1 = 0;
      }
      kfree(lVar3);
      drm_dp_mst_topology_put_port(lVar2);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dp_mst_topology_put_port @ 00109a84 size=288
// signature: undefined drm_dp_mst_topology_put_port(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_mst_detect_port, drm_dp_add_payload_part2, drm_dp_mst_get_edid, drm_dp_send_link_address, drm_dp_delayed_destroy_work, drm_dp_mst_up_req_work, drm_dp_send_power_updown_phy, drm_dp_add_payload_part1]
//------------------------------------------------------------

void drm_dp_mst_topology_put_port(int *param_1)

{
  int *piVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  if (*(long *)(*(long *)(param_1 + 0x19e) + 0x68) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x19e) + 0x68) + 8);
  }
  __drm_dev_dbg(0,uVar7,1,"port %p (%d)\n",param_1,*param_1 + -1);
  Hint_Prefetch(param_1,2,0,1);
  do {
    iVar3 = *param_1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(param_1,0x10);
    if (bVar5) {
      *param_1 = iVar3 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (iVar3 == 1) {
    DataMemoryBarrier(2,1);
    if (*(char *)((long)param_1 + 9) == '\0') {
      lVar9 = *(long *)(param_1 + 0x19e);
      kfree(*(undefined8 *)(param_1 + 0x1a0));
      mutex_lock(lVar9 + 0x480);
      lVar8 = *(long *)(lVar9 + 0x460);
      piVar1 = param_1 + 6;
      plVar2 = (long *)(lVar9 + 0x460);
      uVar6 = __list_add_valid(piVar1,plVar2,lVar8);
      if ((uVar6 & 1) != 0) {
        *(int **)(lVar8 + 8) = piVar1;
        *(long *)(param_1 + 6) = lVar8;
        *(long **)(param_1 + 8) = plVar2;
        *plVar2 = (long)piVar1;
      }
      mutex_unlock(lVar9 + 0x480);
      queue_work_on(0x20,*(undefined8 *)(lVar9 + 0x4b0),lVar9 + 0x4b8);
    }
    else {
      drm_dp_mst_put_port_malloc(param_1);
    }
  }
  else if (iVar3 < 1) {
    refcount_warn_saturate(param_1,3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_queue_down_tx @ 00109bb4 size=244
// signature: undefined drm_dp_queue_down_tx(void)
// callers: [drm_dp_mst_link_probe_work, drm_dp_send_query_stream_enc_status, drm_dp_send_dpcd_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_send_link_address, drm_dp_payload_send_msg, drm_dp_send_power_updown_phy, drm_dp_send_enum_path_resources]
//------------------------------------------------------------

void drm_dp_queue_down_tx(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  undefined *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  char *pcStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  mutex_lock(param_1 + 0x3a8);
  plVar4 = *(long **)(param_1 + 0x3e0);
  lVar1 = param_2 + 0x140;
  plVar2 = (long *)(param_1 + 0x3d8);
  uVar3 = __list_add_valid(lVar1,plVar4,plVar2);
  if ((uVar3 & 1) != 0) {
    *(long *)(param_1 + 0x3e0) = lVar1;
    *(long **)(param_2 + 0x140) = plVar2;
    *(long **)(param_2 + 0x148) = plVar4;
    *plVar4 = lVar1;
  }
  if ((DAT_00118109 & 1) != 0) {
    local_68 = &__drm_printfn_debug;
    uStack_60 = 0;
    local_58 = 0;
    pcStack_50 = "[dp_mst]";
    drm_dp_mst_dump_sideband_msg_tx(&local_68,param_2);
  }
  if (((long *)*plVar2 != plVar2) && ((long *)*plVar2 == (long *)*(long *)(param_1 + 0x3e0))) {
    process_single_down_tx_qlock(param_1);
  }
  mutex_unlock(param_1 + 0x3a8);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_wait_tx_reply @ 00109ca8 size=608
// signature: undefined drm_dp_mst_wait_tx_reply(void)
// callers: [drm_dp_mst_link_probe_work, drm_dp_send_query_stream_enc_status, drm_dp_send_dpcd_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_send_link_address, drm_dp_payload_send_msg, drm_dp_send_power_updown_phy, drm_dp_send_enum_path_resources]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong drm_dp_mst_wait_tx_reply(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long lVar8;
  undefined *local_80;
  undefined8 local_78;
  undefined8 local_70;
  char *local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar8 = *(long *)(param_1 + 0x40);
  lVar1 = lVar8 + 1000;
  lVar2 = _jiffies + 1000;
  while( true ) {
    uVar5 = 1000;
    if (*(long *)(*(long *)(lVar8 + 0x70) + 8) != 0) {
      uVar5 = 0xd;
    }
    if (1 < *(int *)(param_2 + 0x154) - 3U) {
      local_68 = (char *)0x0;
      uStack_60 = 0;
      local_78 = 0;
      local_70 = 0;
      local_80 = (undefined *)0x0;
      uVar5 = 1000;
      if (*(long *)(*(long *)(lVar8 + 0x70) + 8) != 0) {
        uVar5 = 0xd;
      }
      init_wait_entry(&local_80,0);
      prepare_to_wait_event(lVar1,&local_80,2);
      if (1 < *(int *)(param_2 + 0x154) - 3U) {
        do {
          uVar5 = schedule_timeout(uVar5);
          prepare_to_wait_event(lVar1,&local_80,2);
          uVar4 = *(int *)(param_2 + 0x154) - 3;
          if (uVar5 == 0 && uVar4 < 2) {
            uVar5 = 1;
          }
        } while ((1 < uVar4) && (uVar5 != 0));
      }
      finish_wait(lVar1,&local_80);
    }
    if ((int)uVar5 != 0) break;
    pcVar7 = *(code **)(*(long *)(lVar8 + 0x70) + 8);
    if ((pcVar7 == (code *)0x0) || (lVar2 - _jiffies < 0)) {
      mutex_lock(lVar8 + 0x3a8);
LAB_00109dec:
      if (*(long *)(lVar8 + 0x68) == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined8 *)(*(long *)(lVar8 + 0x68) + 8);
      }
      __drm_dev_dbg(0,uVar6,2,"timedout msg send %p %d %d\n",param_2,
                    *(undefined4 *)(param_2 + 0x154),*(undefined4 *)(param_2 + 0x150));
      if (*(uint *)(param_2 + 0x154) < 3) {
        uVar5 = __list_del_entry_valid(param_2 + 0x140);
        if ((uVar5 & 1) != 0) {
          lVar1 = *(long *)(param_2 + 0x140);
          plVar3 = *(long **)(param_2 + 0x148);
          *(long **)(lVar1 + 8) = plVar3;
          *plVar3 = lVar1;
        }
        *(undefined8 *)(param_2 + 0x140) = 0xdead000000000100;
        *(undefined8 *)(param_2 + 0x148) = 0xdead000000000122;
      }
      goto LAB_00109e7c;
    }
    if (*(int *)(pcVar7 + -4) != -0x1a17de97) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x109dd8);
      (*pcVar7)();
    }
    (*pcVar7)(lVar8);
  }
  mutex_lock(lVar8 + 0x3a8);
  if ((int)uVar5 < 1) goto LAB_00109dec;
  if (*(int *)(param_2 + 0x154) != 4) goto LAB_00109eb0;
LAB_00109e7c:
  if ((DAT_00118109 & 1) != 0) {
    local_80 = &__drm_printfn_debug;
    local_78 = 0;
    local_70 = 0;
    local_68 = "[dp_mst]";
    drm_dp_mst_dump_sideband_msg_tx(&local_80,param_2);
  }
  uVar5 = 0xfffffffb;
LAB_00109eb0:
  mutex_unlock(lVar8 + 0x3a8);
  queue_work_on(0x20,_system_long_wq,lVar8 + 0x430);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// drm_dp_send_query_stream_enc_status @ 00109f0c size=524
// signature: undefined drm_dp_send_query_stream_enc_status(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_send_query_stream_enc_status(long param_1,undefined8 param_2,undefined8 *param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  undefined4 uStack_c8;
  undefined3 uStack_c4;
  undefined8 local_c0;
  undefined1 local_b8;
  undefined4 uStack_b7;
  undefined3 uStack_b3;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  uStack_c4 = 0;
  uStack_c8 = 0;
  lVar4 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
  if (lVar4 == 0) {
    iVar3 = -0xc;
  }
  else {
    lVar7 = param_1 + 800;
    mutex_lock(lVar7);
    if (((*(long *)(param_1 + 0x388) == 0) ||
        (lVar5 = drm_dp_mst_topology_get_port_validated_locked(*(long *)(param_1 + 0x388),param_2),
        lVar5 == 0)) || (iVar3 = drm_dp_mst_topology_try_get_port(), iVar3 == 0)) {
      mutex_unlock(lVar7);
      iVar3 = -0x16;
    }
    else {
      mutex_unlock(lVar7);
      get_random_bytes(&uStack_c8,7);
      drm_modeset_lock(param_1 + 0x10,0);
      plVar1 = (long *)(*(long *)(param_1 + 0x58) + 0x38);
      plVar8 = plVar1;
      do {
        plVar8 = (long *)*plVar8;
        if (plVar8 == plVar1) {
          lVar7 = 0;
          goto LAB_00109ffc;
        }
      } while (plVar8[-3] != lVar5);
      lVar7 = (long)(plVar8 + -3);
LAB_00109ffc:
      *(undefined8 *)(lVar4 + 0x138) = *(undefined8 *)(param_1 + 0x388);
      local_58 = 0;
      uStack_50 = 0;
      local_c0 = 0x38;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b0 = 0;
      _local_b8 = CONCAT35(uStack_c4,CONCAT41(uStack_c8,*(undefined1 *)(lVar7 + 9)));
      drm_dp_encode_sideband_req(&local_c0,lVar4);
      drm_dp_queue_down_tx(param_1,lVar4);
      iVar3 = drm_dp_mst_wait_tx_reply(*(undefined8 *)(param_1 + 0x388),lVar4);
      if (-1 < iVar3) {
        if (*(char *)(lVar4 + 0x15a) == '\x01') {
          if (*(long *)(param_1 + 0x68) == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
          }
          __drm_dev_dbg(0,uVar6,2,"query encryption status nak received\n");
          iVar3 = -6;
        }
        else {
          iVar3 = 0;
          uVar2 = *(undefined4 *)(lVar4 + 0x163);
          *param_3 = *(undefined8 *)(lVar4 + 0x15c);
          *(undefined4 *)((long)param_3 + 7) = uVar2;
        }
      }
      drm_modeset_unlock(param_1 + 0x10);
      drm_dp_mst_topology_put_port(lVar5);
    }
    kfree(lVar4);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// drm_dp_add_payload_part1 @ 0010a11c size=324
// signature: undefined drm_dp_add_payload_part1(void)
// callers: []
//------------------------------------------------------------

int drm_dp_add_payload_part1(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar1 = param_1 + 800;
  uVar5 = *param_3;
  mutex_lock(lVar1);
  if (((*(long *)(param_1 + 0x388) == 0) ||
      (lVar4 = drm_dp_mst_topology_get_port_validated_locked(*(long *)(param_1 + 0x388),uVar5),
      lVar4 == 0)) || (iVar3 = drm_dp_mst_topology_try_get_port(), iVar3 == 0)) {
    mutex_unlock(lVar1);
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar5,2,"VCPI %d for port %p not in topology, not creating a payload\n",
                  *(undefined1 *)((long)param_3 + 9),*param_3);
    iVar3 = 0;
    *(undefined1 *)(param_3 + 1) = 0xff;
  }
  else {
    mutex_unlock(lVar1);
    if (*(char *)(param_1 + 0x381) == '\0') {
      uVar2 = *(undefined1 *)(param_2 + 0x49);
      *(undefined1 *)(param_1 + 0x382) = uVar2;
    }
    else {
      uVar2 = *(undefined1 *)(param_1 + 0x382);
    }
    *(undefined1 *)(param_3 + 1) = uVar2;
    iVar3 = drm_dp_dpcd_write_payload
                      (param_1,*(undefined1 *)((long)param_3 + 9),uVar2,
                       *(undefined4 *)((long)param_3 + 0xc));
    drm_dp_mst_topology_put_port(lVar4);
    if (iVar3 < 0) {
      _dev_warn(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
                "[drm] Failed to create MST payload for port %p: %d\n",*param_3,iVar3);
      *(undefined1 *)(param_3 + 1) = 0xff;
    }
    else {
      iVar3 = 0;
      *(char *)(param_1 + 0x381) = *(char *)(param_1 + 0x381) + '\x01';
      *(char *)(param_1 + 0x382) = *(char *)(param_1 + 0x382) + *(char *)((long)param_3 + 0xc);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// drm_dp_remove_payload @ 0010a264 size=380
// signature: undefined drm_dp_remove_payload(void)
// callers: []
//------------------------------------------------------------

void drm_dp_remove_payload(long param_1,long param_2,long param_3,long *param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((char)param_4[1] != -1) {
    lVar1 = param_1 + 800;
    mutex_lock(lVar1);
    lVar4 = *param_4;
    do {
      lVar4 = *(long *)(lVar4 + 0x668);
      if (lVar4 == 0) break;
      if (lVar4 == *(long *)(param_1 + 0x388)) {
        mutex_unlock(lVar1);
        if (*(long *)(param_1 + 0x68) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
        }
        __drm_dev_dbg(0,uVar2,2,&DAT_00115167);
        drm_dp_payload_send_msg(param_1,*param_4,*(undefined1 *)((long)param_4 + 9),0);
        drm_dp_dpcd_write_payload(param_1,*(undefined1 *)((long)param_4 + 9),(char)param_4[1],0);
        goto LAB_0010a354;
      }
      lVar4 = *(long *)(lVar4 + 0x38);
    } while (lVar4 != 0);
    mutex_unlock(lVar1);
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar2,2,"Payload for VCPI %d not in topology, not sending remove\n",
                  *(undefined1 *)((long)param_4 + 9));
LAB_0010a354:
    for (puVar3 = *(undefined8 **)(param_2 + 0x38); puVar3 != (undefined8 *)(param_2 + 0x38);
        puVar3 = (undefined8 *)*puVar3) {
      if ((puVar3 + -3 != param_4) && ((int)(char)param_4[1] < (int)(uint)*(byte *)(puVar3 + -2))) {
        *(byte *)(puVar3 + -2) = *(byte *)(puVar3 + -2) - *(char *)(param_3 + 0xc);
      }
    }
    *(undefined1 *)(param_4 + 1) = 0xff;
    *(char *)(param_1 + 0x381) = *(char *)(param_1 + 0x381) + -1;
    *(char *)(param_1 + 0x382) = *(char *)(param_1 + 0x382) - *(char *)(param_3 + 0xc);
    if ((*(byte *)((long)param_4 + 0x14) & 1) != 0) {
      drm_dp_mst_put_port_malloc(*param_4);
    }
  }
  return;
}



//------------------------------------------------------------
// drm_dp_add_payload_part2 @ 0010a3e4 size=316
// signature: undefined drm_dp_add_payload_part2(void)
// callers: []
//------------------------------------------------------------

int drm_dp_add_payload_part2(long param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if ((char)param_3[1] == -1) {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar2,2,"Part 1 of payload creation for %s failed, skipping part 2\n",
                  *(undefined8 *)(*(long *)(*param_3 + 0x670) + 0x60));
    iVar1 = -5;
  }
  else {
    lVar3 = param_1 + 800;
    lVar4 = *param_3;
    mutex_lock(lVar3);
    if (((*(long *)(param_1 + 0x388) == 0) ||
        (lVar4 = drm_dp_mst_topology_get_port_validated_locked(*(long *)(param_1 + 0x388),lVar4),
        lVar4 == 0)) || (iVar1 = drm_dp_mst_topology_try_get_port(), iVar1 == 0)) {
      mutex_unlock(lVar3);
      iVar1 = -5;
    }
    else {
      mutex_unlock(lVar3);
      iVar1 = drm_dp_payload_send_msg
                        (param_1,lVar4,*(undefined1 *)((long)param_3 + 9),(int)param_3[2]);
      drm_dp_mst_topology_put_port(lVar4);
      if (-1 < iVar1) {
        return iVar1;
      }
    }
    lVar3 = *(long *)(param_1 + 0x68);
    if ((*(byte *)((long)param_3 + 0x14) & 1) == 0) {
      _dev_err(*(undefined8 *)(lVar3 + 8),
               "[drm] *ERROR* Step 2 of creating MST payload for %p failed: %d\n",*param_3,iVar1);
    }
    else {
      if (lVar3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(undefined8 *)(lVar3 + 8);
      }
      __drm_dev_dbg(0,uVar2,2,"Step 2 of removing MST payload for %p failed: %d\n",*param_3,iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dp_get_vc_payload_bw @ 0010a524 size=128
// signature: undefined drm_dp_get_vc_payload_bw(void)
// callers: []
//------------------------------------------------------------

int drm_dp_get_vc_payload_bw(long param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 == 0) || (param_3 == 0)) {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar1,2,"invalid link rate/lane count: (%d / %d)\n",param_2,param_3);
  }
  return (param_3 * param_2) / 54000;
}



//------------------------------------------------------------
// drm_dp_read_mst_cap @ 0010a5a8 size=132
// signature: undefined drm_dp_read_mst_cap(void)
// callers: []
//------------------------------------------------------------

byte drm_dp_read_mst_cap(undefined8 param_1,byte *param_2)

{
  long lVar1;
  byte bVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  bVar2 = 0;
  local_1c[0] = 0;
  if (0x11 < *param_2) {
    lVar1 = drm_dp_dpcd_read(param_1,0x21,local_1c,1);
    if (lVar1 == 1) {
      bVar2 = local_1c[0] & 1;
    }
    else {
      bVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar2;
}



//------------------------------------------------------------
// drm_dp_mst_topology_mgr_set_mst @ 0010a630 size=620
// signature: undefined drm_dp_mst_topology_mgr_set_mst(void)
// callers: [drm_dp_mst_topology_mgr_destroy]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_mst_topology_mgr_set_mst(long param_1,byte param_2)

{
  long lVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  uint *puVar10;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 800;
  local_48 = *(long *)(lVar5 + 0x638);
  mutex_lock(lVar1);
  if ((((*(byte *)(param_1 + 0x380) & 1) == 0 ^ param_2) & 1) != 0) {
    iVar7 = 0;
    goto LAB_0010a684;
  }
  puVar10 = *(uint **)(param_1 + 0x388);
  *(byte *)(param_1 + 0x380) = *(byte *)(param_1 + 0x380) & 0xfe | param_2 & 1;
  if ((param_2 & 1) == 0) {
    *(undefined8 *)(param_1 + 0x388) = 0;
    local_4c[0] = 0;
    drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),0x111,local_4c,1);
    *(byte *)(param_1 + 0x380) = *(byte *)(param_1 + 0x380) & 0xf9 | 4;
    mutex_unlock(lVar1);
    iVar7 = 0;
    iVar8 = 0;
    if (puVar10 == (uint *)0x0) goto LAB_0010a810;
LAB_0010a804:
    iVar7 = iVar8;
    drm_dp_mst_topology_put_mstb(puVar10);
  }
  else {
    if (puVar10 != (uint *)0x0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10a870);
      (*pcVar6)();
    }
    iVar7 = drm_dp_read_dpcd_caps(*(undefined8 *)(param_1 + 0x80),param_1 + 0x390);
    if (iVar7 < 0) {
      if (*(long *)(param_1 + 0x68) == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
      }
      __drm_dev_dbg(0,uVar9,2,"%s: failed to read DPCD, ret %d\n",**(undefined8 **)(param_1 + 0x80),
                    iVar7);
    }
    else {
      puVar10 = (uint *)kmalloc_trace(_drm_display_mode_from_cea_vic,0xdc0,0x60);
      if (puVar10 != (uint *)0x0) {
        *(undefined1 *)(puVar10 + 8) = 1;
        *(uint **)(puVar10 + 10) = puVar10 + 10;
        *(uint **)(puVar10 + 0xc) = puVar10 + 10;
        *puVar10 = 1;
        puVar10[1] = 1;
        *(long *)(puVar10 + 0x10) = param_1;
        *(uint **)(param_1 + 0x388) = puVar10;
        if (*puVar10 == 0) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10a878);
          (*pcVar6)();
        }
        Hint_Prefetch(puVar10,2,0,1);
        do {
          uVar2 = *puVar10;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
          if (bVar4) {
            *puVar10 = uVar2 + 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (uVar2 == 0) {
          uVar9 = 2;
LAB_0010a8a4:
          refcount_warn_saturate(puVar10,uVar9);
        }
        else if ((int)(uVar2 + 1 | uVar2) < 0) {
          uVar9 = 1;
          goto LAB_0010a8a4;
        }
        if (*(long *)(*(long *)(puVar10 + 0x10) + 0x68) == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = *(undefined8 *)(*(long *)(*(long *)(puVar10 + 0x10) + 0x68) + 8);
        }
        __drm_dev_dbg(0,uVar9,1,"mstb %p (%d)\n",puVar10,*puVar10);
        local_50[0] = 7;
        iVar8 = drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),0x111,local_50,1);
        if (-1 < iVar8) {
          drm_dp_dpcd_write_payload(param_1,0,0,0x3f);
          queue_work_on(0x20,_system_long_wq,param_1 + 0x400);
          iVar8 = 0;
        }
        mutex_unlock(lVar1);
        goto LAB_0010a804;
      }
      iVar7 = -0xc;
    }
LAB_0010a684:
    mutex_unlock(lVar1);
  }
LAB_0010a810:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// drm_dp_dpcd_write_payload @ 0010a8b0 size=404
// signature: undefined drm_dp_dpcd_write_payload(void)
// callers: [drm_dp_mst_topology_mgr_set_mst, drm_dp_remove_payload, drm_dp_add_payload_part1]
//------------------------------------------------------------

int drm_dp_dpcd_write_payload(long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  int iVar5;
  byte local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_44[0] = 0;
  local_40[0] = 1;
  drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),0x2c0,local_40,1);
  local_3c = param_2;
  local_3b = param_3;
  local_3a = param_4;
  iVar2 = drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),0x1c0,&local_3c,3);
  if (iVar2 == 3) {
    iVar2 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),0x2c0,local_44,1);
    if (-1 < iVar2) {
      iVar5 = 0x14;
      do {
        if ((local_44[0] & 1) != 0) {
          iVar2 = 0;
          goto LAB_0010a9d8;
        }
        iVar5 = iVar5 + -1;
        if (iVar5 == 0) {
          if (*(long *)(param_1 + 0x68) == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
          }
          __drm_dev_dbg(0,uVar3,2,"status not set after read payload table status %d\n");
          iVar2 = -0x16;
          goto LAB_0010a9d8;
        }
        usleep_range_state(10000,20000,2);
        iVar2 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),0x2c0,local_44,1);
      } while (-1 < iVar2);
    }
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    pcVar4 = "failed to read payload table status %d\n";
  }
  else {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    pcVar4 = "failed to write payload allocation %d\n";
  }
  __drm_dev_dbg(0,uVar3,2,pcVar4,iVar2);
LAB_0010a9d8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// drm_dp_mst_topology_put_mstb @ 0010aa44 size=268
// signature: undefined drm_dp_mst_topology_put_mstb(void)
// callers: [drm_dp_mst_topology_mgr_set_mst, drm_dp_mst_link_probe_work, drm_dp_send_dpcd_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_port_set_pdt, drm_dp_delayed_destroy_work, drm_dp_payload_send_msg, drm_dp_mst_up_req_work, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

void drm_dp_mst_topology_put_mstb(int *param_1)

{
  int *piVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  if (*(long *)(*(long *)(param_1 + 0x10) + 0x68) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x68) + 8);
  }
  __drm_dev_dbg(0,uVar7,1,"mstb %p (%d)\n",param_1,*param_1 + -1);
  Hint_Prefetch(param_1,2,0,1);
  do {
    iVar3 = *param_1;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(param_1,0x10);
    if (bVar5) {
      *param_1 = iVar3 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (iVar3 == 1) {
    DataMemoryBarrier(2,1);
    piVar1 = param_1 + 2;
    lVar9 = *(long *)(param_1 + 0x10);
    *(int **)(param_1 + 2) = piVar1;
    *(int **)(param_1 + 4) = piVar1;
    mutex_lock(lVar9 + 0x480);
    lVar8 = *(long *)(lVar9 + 0x470);
    plVar2 = (long *)(lVar9 + 0x470);
    uVar6 = __list_add_valid(piVar1,plVar2,lVar8);
    if ((uVar6 & 1) != 0) {
      *(int **)(lVar8 + 8) = piVar1;
      *(long *)(param_1 + 2) = lVar8;
      *(long **)(param_1 + 4) = plVar2;
      *plVar2 = (long)piVar1;
    }
    mutex_unlock(lVar9 + 0x480);
    queue_work_on(0x20,*(undefined8 *)(lVar9 + 0x4b0),lVar9 + 0x4b8);
  }
  else if (iVar3 < 1) {
    refcount_warn_saturate(param_1,3);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_topology_mgr_suspend @ 0010ab64 size=188
// signature: undefined drm_dp_mst_topology_mgr_suspend(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_topology_mgr_suspend(long param_1)

{
  long lVar1;
  long lVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 800;
  local_28 = *(long *)(lVar2 + 0x638);
  mutex_lock(lVar1);
  local_2c[0] = 5;
  drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),0x111,local_2c,1);
  mutex_unlock(lVar1);
  flush_work(param_1 + 0x528);
  flush_work(param_1 + 0x400);
  flush_work(param_1 + 0x4b8);
  mutex_lock(lVar1);
  if (((*(byte *)(param_1 + 0x380) & 1) != 0) && (*(long *)(param_1 + 0x388) != 0)) {
    drm_dp_mst_topology_mgr_invalidate_mstb();
  }
  mutex_unlock(lVar1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_topology_mgr_invalidate_mstb @ 0010ac20 size=80
// signature: undefined drm_dp_mst_topology_mgr_invalidate_mstb(void)
// callers: [drm_dp_mst_topology_mgr_invalidate_mstb, drm_dp_mst_topology_mgr_suspend]
//------------------------------------------------------------

void drm_dp_mst_topology_mgr_invalidate_mstb(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0x28);
  *(undefined1 *)(param_1 + 0x48) = 0;
  for (; plVar1 != (long *)(param_1 + 0x28); plVar1 = (long *)*plVar1) {
    if (plVar1[2] != 0) {
      drm_dp_mst_topology_mgr_invalidate_mstb();
    }
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_topology_mgr_resume @ 0010ac74 size=532
// signature: undefined drm_dp_mst_topology_mgr_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_mst_topology_mgr_resume(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined1 local_5c [4];
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  lVar1 = param_1 + 800;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  mutex_lock(lVar1);
  if (*(long *)(param_1 + 0x388) != 0) {
    iVar2 = drm_dp_read_dpcd_caps(*(undefined8 *)(param_1 + 0x80),param_1 + 0x390);
    if (iVar2 < 0) {
LAB_0010ad5c:
      if (*(long *)(param_1 + 0x68) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
      }
      pcVar6 = "dpcd read failed - undocked during suspend?\n";
    }
    else {
      local_5c[0] = 7;
      iVar2 = drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),0x111,local_5c,1);
      if (-1 < iVar2) {
        iVar2 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),0x30,&local_58,0x10);
        if (iVar2 == 0x10) {
          lVar8 = *(long *)(param_1 + 0x388);
          puVar7 = (undefined8 *)(lVar8 + 0x49);
          *puVar7 = local_58;
          *(undefined8 *)(lVar8 + 0x51) = uStack_50;
          lVar4 = memchr_inv(puVar7,0,0x10);
          uVar5 = _jiffies;
          if (lVar4 == 0) {
            *(undefined8 *)(lVar8 + 0x49) = _jiffies;
            *(undefined8 *)(lVar8 + 0x51) = uVar5;
            if (*(long *)(lVar8 + 0x38) == 0) {
              uVar3 = drm_dp_dpcd_write(*(undefined8 *)(*(long *)(lVar8 + 0x40) + 0x80),0x30,puVar7,
                                        0x10);
            }
            else {
              uVar3 = drm_dp_send_dpcd_write
                                (*(long *)(lVar8 + 0x40),*(long *)(lVar8 + 0x38),0x30,0x10,puVar7);
            }
            if ((0xfffffff0 < uVar3 - 0x10) || ((uVar3 & 0xffffffef) != 0)) {
              if (*(long *)(param_1 + 0x68) == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
              }
              pcVar6 = "check mstb failed - undocked during suspend?\n";
              goto LAB_0010ad98;
            }
          }
          queue_work_on(0x20,_system_long_wq,param_1 + 0x400);
          mutex_unlock(lVar1);
          if ((param_2 & 1) != 0) {
            if (*(long *)(param_1 + 0x68) == 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
            }
            __drm_dev_dbg(0,uVar5,2,"Waiting for link probe work to finish re-syncing topology...\n"
                         );
            flush_work(param_1 + 0x400);
          }
          uVar5 = 0;
          goto LAB_0010adb0;
        }
        goto LAB_0010ad5c;
      }
      if (*(long *)(param_1 + 0x68) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
      }
      pcVar6 = "mst write failed - undocked during suspend?\n";
    }
LAB_0010ad98:
    __drm_dev_dbg(0,uVar5,2,pcVar6);
  }
  mutex_unlock(lVar1);
  uVar5 = 0xffffffff;
LAB_0010adb0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_hpd_irq_handle_event @ 0010ae8c size=3356
// signature: undefined drm_dp_mst_hpd_irq_handle_event(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_mst_hpd_irq_handle_event(long param_1,byte *param_2,long param_3,undefined1 *param_4)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  ulong uVar4;
  long *plVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  ulong uVar12;
  undefined8 *puVar13;
  byte *pbVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  uint uVar17;
  char *pcVar18;
  char *pcVar19;
  long lVar20;
  byte bVar21;
  long lVar22;
  ulong uVar23;
  long *plVar24;
  byte *pbVar25;
  uint uVar26;
  ulong uVar27;
  undefined8 in_stack_ffffffffffffff20;
  undefined4 uVar28;
  long local_c0;
  char local_b8 [64];
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  uVar28 = (undefined4)((ulong)in_stack_ffffffffffffff20 >> 0x20);
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  *param_4 = 0;
  bVar6 = *param_2 & 0x3f | (*param_2 >> 7) << 6;
  if (bVar6 != *(byte *)(param_1 + 0x39f)) {
    *(byte *)(param_1 + 0x39f) = bVar6;
    *param_4 = 1;
  }
  lVar2 = param_1 + 800;
  mutex_lock(lVar2);
  if ((*(byte *)(param_1 + 0x380) >> 2 & 1) != 0) {
    *(byte *)(param_1 + 0x380) = *(byte *)(param_1 + 0x380) & 0xfb;
    memset((void *)(param_1 + 0x1d6),0,0x146);
    memset((void *)(param_1 + 0x90),0,0x146);
  }
  mutex_unlock(lVar2);
  bVar6 = param_2[1];
  if ((bVar6 >> 4 & 1) == 0) goto LAB_0010b018;
  local_c0 = 0;
  uVar12 = drm_dp_get_one_sb_msg(param_1,0,&local_c0);
  if ((uVar12 & 1) == 0) goto LAB_0010afe4;
  if (*(char *)(param_1 + 0x30b) == '\0') {
LAB_0010aff4:
    if (local_c0 != 0) {
      drm_dp_mst_topology_put_mstb();
    }
    goto LAB_0010b000;
  }
  lVar20 = param_1 + 0x3a8;
  mutex_lock(lVar20);
  plVar24 = *(long **)(param_1 + 0x3d8);
  mutex_unlock(lVar20);
  if (((plVar24 == (long *)(param_1 + 0x3d8)) || ((byte *)(plVar24 + -0x28) == (byte *)0x0)) ||
     (lVar22 = plVar24[-1], lVar22 != local_c0)) {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    uVar16 = CONCAT44(uVar28,(uint)*(byte *)(param_1 + 0x206));
    __drm_dev_dbg(0,uVar15,2,"Got MST reply with no msg %p %d %d %02x %02x\n",local_c0,
                  *(undefined1 *)(param_1 + 0x31b),*(undefined1 *)(param_1 + 0x30c),
                  *(undefined1 *)(param_1 + 0x30e),uVar16);
    uVar28 = (undefined4)((ulong)uVar16 >> 0x20);
LAB_0010afe4:
    memset((void *)(param_1 + 0x1d6),0,0x146);
    goto LAB_0010aff4;
  }
  uVar12 = (ulong)*(byte *)(plVar24 + -0x28);
  local_b8[0x30] = '\0';
  local_b8[0x31] = '\0';
  local_b8[0x32] = '\0';
  local_b8[0x33] = '\0';
  local_b8[0x34] = '\0';
  local_b8[0x35] = '\0';
  local_b8[0x36] = '\0';
  local_b8[0x37] = '\0';
  local_b8[0x38] = '\0';
  local_b8[0x39] = '\0';
  local_b8[0x3a] = '\0';
  local_b8[0x3b] = '\0';
  local_b8[0x3c] = '\0';
  local_b8[0x3d] = '\0';
  local_b8[0x3e] = '\0';
  local_b8[0x3f] = '\0';
  bVar6 = *(byte *)(param_1 + 0x206);
  local_b8[0x20] = '\0';
  local_b8[0x21] = '\0';
  local_b8[0x22] = '\0';
  local_b8[0x23] = '\0';
  local_b8[0x24] = '\0';
  local_b8[0x25] = '\0';
  local_b8[0x26] = '\0';
  local_b8[0x27] = '\0';
  local_b8[0x28] = '\0';
  local_b8[0x29] = '\0';
  local_b8[0x2a] = '\0';
  local_b8[0x2b] = '\0';
  local_b8[0x2c] = '\0';
  local_b8[0x2d] = '\0';
  local_b8[0x2e] = '\0';
  local_b8[0x2f] = '\0';
  local_b8[0x10] = '\0';
  local_b8[0x11] = '\0';
  local_b8[0x12] = '\0';
  local_b8[0x13] = '\0';
  local_b8[0x14] = '\0';
  local_b8[0x15] = '\0';
  local_b8[0x16] = '\0';
  local_b8[0x17] = '\0';
  local_b8[0x18] = '\0';
  local_b8[0x19] = '\0';
  local_b8[0x1a] = '\0';
  local_b8[0x1b] = '\0';
  local_b8[0x1c] = '\0';
  local_b8[0x1d] = '\0';
  local_b8[0x1e] = '\0';
  local_b8[0x1f] = '\0';
  uVar23 = uVar12 & 0x7f;
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b8[8] = '\0';
  local_b8[9] = '\0';
  local_b8[10] = '\0';
  local_b8[0xb] = '\0';
  local_b8[0xc] = '\0';
  local_b8[0xd] = '\0';
  local_b8[0xe] = '\0';
  local_b8[0xf] = '\0';
  uVar27 = (ulong)bVar6 & 0x7f;
  uVar17 = (uint)uVar23;
  uVar26 = (uint)uVar27;
  if (uVar17 != uVar26) {
    bVar7 = *(byte *)(lVar22 + 0x20);
    local_78 = 0;
    uStack_70 = 0;
    if (1 < (ulong)bVar7) {
      lVar20 = 0;
      do {
        uVar4 = lVar20 + 1;
        if ((uVar4 & 1) == 0) {
          if (0xf < uVar4) goto LAB_0010bba4;
          uVar9 = (int)uVar4 - 1;
          bVar21 = *(byte *)(lVar22 + 0x18 +
                            ((ulong)((uint)(int)(char)((char)uVar9 + (char)((uVar9 & 0x80) >> 7)) >>
                                    1) & 0xff)) & 0xf;
        }
        else {
          if (0xf < uVar4) goto LAB_0010bba4;
          bVar21 = *(byte *)(lVar22 + 0x18 + ((ulong)((int)lVar20 + 0x100U >> 1) & 0x7f)) >> 4;
        }
        *(byte *)(((ulong)&local_78 | 1) + lVar20) = bVar21;
        lVar20 = lVar20 + 1;
      } while ((ulong)bVar7 - 1 != lVar20);
    }
    snprintf(local_b8,0x40,"%*phC",(uint)bVar7,&local_78);
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    pcVar18 = "unknown";
    if ((uVar26 < 0x39) &&
       (pcVar18 = (&drm_dp_mst_req_type_str_req_type_str)[uVar27],
       (0xfeffc0ffe0fff8U >> ((ulong)bVar6 & 0x3f) & 1) != 0)) {
      pcVar18 = "unknown";
    }
    pcVar19 = "unknown";
    if ((uVar17 < 0x39) &&
       (pcVar19 = (&drm_dp_mst_req_type_str_req_type_str)[uVar23],
       (0xfeffc0ffe0fff8U >> (uVar12 & 0x3f) & 1) != 0)) {
      pcVar19 = "unknown";
    }
    __drm_dev_dbg(0,uVar15,2,
                  "Got unexpected MST reply, mstb: %p seqno: %d lct: %d rad: %s rx_req_type: %s (%02x) != tx_req_type: %s (%02x)\n"
                  ,lVar22,*(undefined1 *)(param_1 + 0x31b),*(undefined1 *)(lVar22 + 0x20),local_b8,
                  pcVar18,uVar26,pcVar19,uVar17);
    uVar28 = (undefined4)((ulong)pcVar18 >> 0x20);
    goto LAB_0010afe4;
  }
  memset((char *)((long)plVar24 + 0x1a),0,0x1a4);
  cVar8 = -(*(char *)(param_1 + 0x206) >> 7);
  *(char *)((long)plVar24 + 0x1a) = cVar8;
  bVar6 = *(byte *)(param_1 + 0x206);
  uVar12 = (ulong)bVar6 & 0x7f;
  *(char *)((long)plVar24 + 0x1b) = (char)uVar12;
  if (cVar8 == '\x01') {
    uVar15 = *(undefined8 *)(param_1 + 0x207);
    *(undefined8 *)((long)plVar24 + 0x24) = *(undefined8 *)(param_1 + 0x20f);
    *(undefined8 *)((long)plVar24 + 0x1c) = uVar15;
    *(undefined1 *)((long)plVar24 + 0x2c) = *(undefined1 *)(param_1 + 0x217);
    *(undefined1 *)((long)plVar24 + 0x2d) = *(undefined1 *)(param_1 + 0x218);
    goto switchD_0010b424_caseD_14;
  }
  switch((uint)uVar12) {
  case 1:
    uVar15 = *(undefined8 *)(param_1 + 0x207);
    *(undefined8 *)((long)plVar24 + 0x24) = *(undefined8 *)(param_1 + 0x20f);
    *(undefined8 *)((long)plVar24 + 0x1c) = uVar15;
    uVar23 = (ulong)*(byte *)(param_1 + 0x217) & 0xf;
    *(char *)((long)plVar24 + 0x2c) = (char)uVar23;
    if (*(byte *)(param_1 + 0x309) < 0x12) {
      uVar12 = 0x12;
      goto LAB_0010ba28;
    }
    if ((int)uVar23 != 0) {
      pcVar18 = (char *)((long)plVar24 + 0x2d);
      uVar12 = 0x12;
LAB_0010b7f0:
      uVar17 = (uint)uVar12;
      if (0xff < uVar17) {
LAB_0010bba4:
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x10bba8);
        (*pcVar10)();
      }
      cVar8 = *(char *)(param_1 + uVar12 + 0x206);
      uVar26 = (uint)cVar8;
      pbVar25 = (byte *)(param_1 + uVar12 + 0x206);
      if (cVar8 < '\0') {
        *pcVar18 = '\x01';
        uVar26 = (uint)*pbVar25;
      }
      pcVar18[1] = (byte)(uVar26 >> 4) & 7;
      pcVar18[2] = *pbVar25 & 0xf;
      uVar26 = uVar17 + 1;
      if (uVar17 < *(byte *)(param_1 + 0x309)) {
        lVar1 = param_1 + (ulong)uVar26;
        pcVar18[3] = *(byte *)(lVar1 + 0x206) >> 7;
        pcVar18[4] = *(byte *)(lVar1 + 0x206) >> 6 & 1;
        if (*pcVar18 != '\0') {
          bVar6 = *(byte *)(param_1 + 0x309);
          uVar12 = (ulong)(uVar17 + 2);
          if ((uint)bVar6 < uVar17 + 2) goto LAB_0010ba28;
LAB_0010b900:
          if ((uint)bVar6 < (uint)uVar12) goto LAB_0010ba28;
          pcVar18 = pcVar18 + 0x19;
          uVar23 = uVar23 - 1;
          if (uVar23 == 0) break;
          goto LAB_0010b7f0;
        }
        pcVar18[5] = *(byte *)(lVar1 + 0x206) >> 5 & 1;
        uVar26 = uVar17 + 2;
        if (uVar26 <= *(byte *)(param_1 + 0x309)) {
          if (0xfd < uVar17) goto LAB_0010bba4;
          pcVar18[6] = *(char *)(param_1 + (ulong)uVar26 + 0x206);
          uVar26 = uVar17 + 3;
          if (*(byte *)(param_1 + 0x309) < uVar26) goto LAB_0010ba24;
          uVar15 = *(undefined8 *)(param_1 + (ulong)uVar26 + 0x20e);
          *(undefined8 *)(pcVar18 + 7) = *(undefined8 *)(param_1 + (ulong)uVar26 + 0x206);
          uVar26 = uVar17 + 0x13;
          *(undefined8 *)(pcVar18 + 0xf) = uVar15;
          if (uVar26 <= *(byte *)(param_1 + 0x309)) {
            if (uVar17 < 0xed) {
              uVar12 = (ulong)(uVar17 + 0x14);
              pcVar18[0x17] = *(byte *)(param_1 + (ulong)uVar26 + 0x206) >> 4;
              pcVar18[0x18] = *(byte *)(param_1 + (ulong)uVar26 + 0x206) & 0xf;
              bVar6 = *(byte *)(param_1 + 0x309);
              goto LAB_0010b900;
            }
            goto LAB_0010bba4;
          }
        }
      }
LAB_0010ba24:
      uVar12 = (ulong)uVar26;
      goto LAB_0010ba28;
    }
    break;
  default:
    pcVar18 = "unknown";
    if (((uint)uVar12 < 0x39) &&
       (pcVar18 = (&drm_dp_mst_req_type_str_req_type_str)[uVar12],
       (0xfeffc0ffe0fff8U >> ((ulong)bVar6 & 0x3f) & 1) != 0)) {
      pcVar18 = "unknown";
    }
    _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
             "[drm] *ERROR* Got unknown reply 0x%02x (%s)\n",uVar12,pcVar18);
    break;
  case 0x10:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) >> 4;
    *(byte *)((long)plVar24 + 0x1d) = *(byte *)(param_1 + 0x207) & 1;
    if (*(byte *)(param_1 + 0x309) < 2) {
      uVar12 = 2;
    }
    else {
      *(ushort *)((long)plVar24 + 0x1e) =
           *(ushort *)(param_1 + 0x208) >> 8 | *(ushort *)(param_1 + 0x208) << 8;
      if (*(byte *)(param_1 + 0x309) < 4) {
        uVar12 = 4;
      }
      else {
        *(ushort *)(plVar24 + 4) =
             *(ushort *)(param_1 + 0x20a) >> 8 | *(ushort *)(param_1 + 0x20a) << 8;
        if (5 < *(byte *)(param_1 + 0x309)) break;
        uVar12 = 6;
      }
    }
    pcVar18 = "enum resource parse length fail %d %d\n";
    goto LAB_0010ba38;
  case 0x11:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) >> 4;
    if (*(byte *)(param_1 + 0x309) < 2) {
      uVar12 = 2;
    }
    else {
      *(undefined1 *)((long)plVar24 + 0x1d) = *(undefined1 *)(param_1 + 0x208);
      if (*(byte *)(param_1 + 0x309) < 3) {
        uVar12 = 3;
      }
      else {
        *(ushort *)((long)plVar24 + 0x1e) =
             *(ushort *)(param_1 + 0x209) >> 8 | *(ushort *)(param_1 + 0x209) << 8;
        if (4 < *(byte *)(param_1 + 0x309)) break;
        uVar12 = 5;
      }
    }
    pcVar18 = "allocate payload parse length fail %d %d\n";
    goto LAB_0010ba38;
  case 0x12:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) >> 4;
    if (*(byte *)(param_1 + 0x309) < 2) {
      uVar12 = 2;
    }
    else {
      *(ushort *)((long)plVar24 + 0x1e) =
           *(ushort *)(param_1 + 0x208) >> 8 | *(ushort *)(param_1 + 0x208) << 8;
      if (3 < *(byte *)(param_1 + 0x309)) break;
      uVar12 = 4;
    }
    pcVar18 = "query payload parse length fail %d %d\n";
    goto LAB_0010ba38;
  case 0x14:
  case 0x23:
    break;
  case 0x20:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) & 0xf;
    if (*(byte *)(param_1 + 0x309) < 2) {
      uVar12 = 2;
    }
    else {
      bVar6 = *(byte *)(param_1 + 0x208);
      *(byte *)((long)plVar24 + 0x1d) = bVar6;
      if (2 < *(byte *)(param_1 + 0x309)) {
        memcpy((void *)((long)plVar24 + 0x1e),(void *)(param_1 + 0x209),(ulong)bVar6);
        break;
      }
      uVar12 = 3;
    }
LAB_0010ba28:
    pcVar18 = "link address reply parse length fail %d %d\n";
LAB_0010ba38:
    ___drm_dbg(0,2,pcVar18,uVar12);
    break;
  case 0x21:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) & 0xf;
    if (*(byte *)(param_1 + 0x309) < 2) {
      pcVar18 = "parse length fail %d %d\n";
LAB_0010b9a8:
      uVar12 = 2;
      goto LAB_0010ba38;
    }
    break;
  case 0x22:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) & 0xf;
    if (*(byte *)(param_1 + 0x309) < 2) {
      pcVar18 = "remote i2c reply parse length fail %d %d\n";
      goto LAB_0010b9a8;
    }
    bVar6 = *(byte *)(param_1 + 0x208);
    *(byte *)((long)plVar24 + 0x1d) = bVar6;
    memcpy((void *)((long)plVar24 + 0x1e),(void *)(param_1 + 0x209),(ulong)bVar6);
    break;
  case 0x24:
  case 0x25:
    *(byte *)((long)plVar24 + 0x1c) = *(byte *)(param_1 + 0x207) >> 4;
    if (*(byte *)(param_1 + 0x309) < 2) {
      pcVar18 = "power up/down phy parse length fail %d %d\n";
      goto LAB_0010b9a8;
    }
    break;
  case 0x38:
    *(undefined1 *)((long)plVar24 + 0x1c) = *(undefined1 *)(param_1 + 0x209);
    *(byte *)((long)plVar24 + 0x1d) = *(byte *)(param_1 + 0x208) & 1;
    *(byte *)((long)plVar24 + 0x21) = *(byte *)(param_1 + 0x208) >> 4 & 1;
    *(byte *)((long)plVar24 + 0x22) = *(byte *)(param_1 + 0x208) >> 3 & 1;
    *(byte *)(plVar24 + 4) = *(byte *)(param_1 + 0x208) >> 5 & 1;
    *(byte *)((long)plVar24 + 0x1f) = *(byte *)(param_1 + 0x208) >> 6 & 1;
    *(byte *)((long)plVar24 + 0x1e) = *(byte *)(param_1 + 0x208) >> 7;
    *(byte *)((long)plVar24 + 0x23) = *(byte *)(param_1 + 0x207) >> 3 & 1;
    *(byte *)((long)plVar24 + 0x24) = *(byte *)(param_1 + 0x207) >> 4 & 1;
    *(byte *)((long)plVar24 + 0x25) = *(byte *)(param_1 + 0x207) >> 5 & 1;
    *(byte *)((long)plVar24 + 0x26) = *(byte *)(param_1 + 0x207) >> 6;
  }
switchD_0010b424_caseD_14:
  if (*(char *)((long)plVar24 + 0x1a) == '\x01') {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    uVar12 = (ulong)*(byte *)((long)plVar24 + 0x1b);
    pcVar18 = "unknown";
    if ((*(byte *)((long)plVar24 + 0x1b) < 0x39) &&
       (pcVar18 = (&drm_dp_mst_req_type_str_req_type_str)[uVar12],
       (0xfeffc0ffe0fff8U >> (uVar12 & 0x3f) & 1) != 0)) {
      pcVar18 = "unknown";
    }
    bVar6 = *(byte *)((long)plVar24 + 0x2c);
    pcVar19 = "unknown";
    if (bVar6 < 0xb) {
      pcVar19 = "unknown";
      if (bVar6 != 0) {
        pcVar19 = *(char **)(drm_dp_mst_nak_reason_str_nak_reason_str + (ulong)bVar6 * 8);
      }
    }
    uVar16 = CONCAT44(uVar28,(uint)*(byte *)((long)plVar24 + 0x2d));
    __drm_dev_dbg(0,uVar15,2,"Got NAK reply: req 0x%02x (%s), reason 0x%02x (%s), nak data 0x%02x\n"
                  ,uVar12,pcVar18,(ulong)bVar6,pcVar19,uVar16);
    uVar28 = (undefined4)((ulong)uVar16 >> 0x20);
  }
  memset((void *)(param_1 + 0x1d6),0,0x146);
  drm_dp_mst_topology_put_mstb(lVar22);
  mutex_lock(lVar20);
  *(undefined4 *)((long)plVar24 + 0x14) = 3;
  uVar12 = __list_del_entry_valid(plVar24);
  if ((uVar12 & 1) != 0) {
    lVar22 = *plVar24;
    plVar5 = (long *)plVar24[1];
    *(long **)(lVar22 + 8) = plVar5;
    *plVar5 = lVar22;
  }
  *plVar24 = -0x2152ffffffffff00;
  plVar24[1] = -0x2152fffffffffede;
  mutex_unlock(lVar20);
  __wake_up(param_1 + 1000,3,0,0);
LAB_0010b000:
  *param_4 = 1;
  *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x10;
  bVar6 = param_2[1];
LAB_0010b018:
  if ((bVar6 >> 5 & 1) == 0) {
    uVar15 = 0;
    goto LAB_0010b5c0;
  }
  uVar12 = drm_dp_get_one_sb_msg(param_1,1,0);
  if ((uVar12 & 1) == 0) {
LAB_0010b598:
    memset((void *)(param_1 + 0x90),0,0x146);
LAB_0010b5a8:
    uVar15 = 0;
  }
  else {
    if (*(char *)(param_1 + 0x1c5) == '\0') goto LAB_0010b5a8;
    puVar13 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x98);
    if (puVar13 != (undefined8 *)0x0) {
      pbVar25 = (byte *)(puVar13 + 2);
      pbVar25[0] = 0;
      pbVar25[1] = 0;
      pbVar25[2] = 0;
      pbVar25[3] = 0;
      pbVar25[4] = 0;
      pbVar25[5] = 0;
      pbVar25[6] = 0;
      pbVar25[7] = 0;
      puVar3 = puVar13 + 0x11;
      puVar13[0x11] = puVar3;
      puVar13[0x12] = puVar3;
      bVar6 = *(byte *)(param_1 + 0xc0);
      puVar13[3] = 0;
      puVar13[4] = 0;
      puVar13[5] = 0;
      puVar13[6] = 0;
      puVar13[7] = 0;
      puVar13[8] = 0;
      uVar12 = (ulong)bVar6 & 0x7f;
      puVar13[9] = 0;
      puVar13[10] = 0;
      uVar17 = (uint)uVar12;
      puVar13[0xb] = 0;
      puVar13[0xc] = 0;
      puVar13[0xd] = 0;
      puVar13[0xe] = 0;
      puVar13[0xf] = 0;
      puVar13[0x10] = 0;
      *pbVar25 = (byte)uVar12;
      if (uVar17 == 0x13) {
        bVar6 = *(byte *)(param_1 + 0x1c3);
        *(byte *)(puVar13 + 3) = *(byte *)(param_1 + 0xc1) >> 4;
        if (bVar6 < 2) {
          uVar15 = 2;
          lVar20 = *(long *)(param_1 + 0x68);
          if (lVar20 == 0) goto LAB_0010b1e4;
LAB_0010b100:
          uVar16 = *(undefined8 *)(lVar20 + 8);
        }
        else {
          uVar15 = *(undefined8 *)(param_1 + 0xca);
          *(undefined8 *)((long)puVar13 + 0x19) = *(undefined8 *)(param_1 + 0xc2);
          *(undefined8 *)((long)puVar13 + 0x21) = uVar15;
          if (0x11 < bVar6) {
            *(ushort *)((long)puVar13 + 0x2a) =
                 *(ushort *)(param_1 + 0xd2) >> 8 | *(ushort *)(param_1 + 0xd2) << 8;
            goto LAB_0010b1fc;
          }
          uVar15 = 0x12;
          lVar20 = *(long *)(param_1 + 0x68);
          if (lVar20 != 0) goto LAB_0010b100;
LAB_0010b1e4:
          uVar16 = 0;
        }
        pcVar18 = "resource status reply parse length fail %d %d\n";
LAB_0010b1f0:
        __drm_dev_dbg(0,uVar16,2,pcVar18,uVar15);
      }
      else {
        if (uVar17 == 2) {
          bVar6 = *(byte *)(param_1 + 0x1c3);
          *(byte *)(puVar13 + 5) = *(byte *)(param_1 + 0xc1) >> 4;
          if (bVar6 < 2) {
            uVar15 = 2;
            lVar20 = *(long *)(param_1 + 0x68);
          }
          else {
            uVar15 = *(undefined8 *)(param_1 + 0xca);
            puVar13[3] = *(undefined8 *)(param_1 + 0xc2);
            puVar13[4] = uVar15;
            if (0x11 < bVar6) {
              bVar6 = *(byte *)(param_1 + 0xd2);
              *(byte *)((long)puVar13 + 0x29) = bVar6 >> 6 & 1;
              *(byte *)((long)puVar13 + 0x2a) = bVar6 >> 5 & 1;
              *(byte *)((long)puVar13 + 0x2b) = bVar6 >> 4 & 1;
              *(byte *)((long)puVar13 + 0x2c) = bVar6 >> 3 & 1;
              *(byte *)((long)puVar13 + 0x2d) = bVar6 & 7;
              goto LAB_0010b1fc;
            }
            uVar15 = 0x12;
            lVar20 = *(long *)(param_1 + 0x68);
          }
          if (lVar20 == 0) {
            uVar16 = 0;
          }
          else {
            uVar16 = *(undefined8 *)(lVar20 + 8);
          }
          pcVar18 = "connection status reply parse length fail %d %d\n";
          goto LAB_0010b1f0;
        }
        pcVar18 = "unknown";
        if ((uVar17 < 0x39) &&
           (pcVar18 = (&drm_dp_mst_req_type_str_req_type_str)[uVar12],
           (0xfeffc0ffe0fff8U >> ((ulong)bVar6 & 0x3f) & 1) != 0)) {
          pcVar18 = "unknown";
        }
        _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
                 "[drm] *ERROR* Got unknown request 0x%02x (%s)\n",uVar12,pcVar18);
      }
LAB_0010b1fc:
      if ((*pbVar25 == 2) || (*pbVar25 == 0x13)) {
        mutex_lock(lVar2);
        lVar20 = *(long *)(param_1 + 0x388);
        if ((lVar20 != 0) && (iVar11 = drm_dp_mst_topology_try_get_mstb(lVar20), iVar11 != 0)) {
          mutex_unlock(lVar2);
          bVar6 = *pbVar25;
          pbVar14 = (byte *)kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
          if (pbVar14 != (byte *)0x0) {
            *(long *)(pbVar14 + 0x138) = lVar20;
            *pbVar14 = bVar6 & 0x7f;
            pbVar14[0x131] = 1;
            mutex_lock(param_1 + 0x3a8);
            process_single_tx_qlock(param_1,pbVar14,1);
            mutex_unlock(param_1 + 0x3a8);
            kfree(pbVar14);
          }
          drm_dp_mst_topology_put_mstb(lVar20);
          if (*pbVar25 == 0x13) {
            if (*(long *)(param_1 + 0x68) == 0) {
              uVar15 = 0;
            }
            else {
              uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
            }
            __drm_dev_dbg(0,uVar15,2,"Got RSN: pn: %d avail_pbn %d\n",*(undefined1 *)(puVar13 + 3),
                          *(undefined2 *)((long)puVar13 + 0x2a));
          }
          else if (*pbVar25 == 2) {
            if (*(long *)(param_1 + 0x68) == 0) {
              uVar15 = 0;
            }
            else {
              uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
            }
            __drm_dev_dbg(0,uVar15,2,"Got CSN: pn: %d ldps:%d ddps: %d mcs: %d ip: %d pdt: %d\n",
                          *(undefined1 *)(puVar13 + 5),*(undefined1 *)((long)puVar13 + 0x29),
                          *(undefined1 *)((long)puVar13 + 0x2a),
                          *(undefined1 *)((long)puVar13 + 0x2b),
                          CONCAT44(uVar28,(uint)*(byte *)((long)puVar13 + 0x2c)),
                          *(undefined1 *)((long)puVar13 + 0x2d));
          }
          uVar15 = *(undefined8 *)(param_1 + 0x1ce);
          *puVar13 = *(undefined8 *)(param_1 + 0x1c6);
          puVar13[1] = uVar15;
          mutex_lock(param_1 + 0x4f8);
          plVar24 = *(long **)(param_1 + 0x4f0);
          uVar12 = __list_add_valid(puVar3,plVar24,param_1 + 0x4e8);
          if ((uVar12 & 1) != 0) {
            *(undefined8 **)(param_1 + 0x4f0) = puVar3;
            puVar13[0x11] = param_1 + 0x4e8;
            puVar13[0x12] = plVar24;
            *plVar24 = (long)puVar3;
          }
          mutex_unlock(param_1 + 0x4f8);
          queue_work_on(0x20,_system_long_wq,param_1 + 0x528);
          goto LAB_0010b598;
        }
        mutex_unlock(lVar2);
      }
      else {
        if (*(long *)(param_1 + 0x68) == 0) {
          uVar15 = 0;
        }
        else {
          uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
        }
        __drm_dev_dbg(0,uVar15,2,"Received unknown up req type, ignoring: %x\n");
      }
      kfree(puVar13);
      goto LAB_0010b598;
    }
    uVar15 = 0xfffffff4;
  }
  *param_4 = 1;
  *(byte *)(param_3 + 1) = *(byte *)(param_3 + 1) | 0x20;
LAB_0010b5c0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar15);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_hpd_irq_send_new_request @ 0010bbac size=128
// signature: undefined drm_dp_mst_hpd_irq_send_new_request(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_mst_hpd_irq_send_new_request(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = param_1 + 0x3a8;
  mutex_lock(lVar1);
  lVar2 = *(long *)(param_1 + 0x3d8);
  if (((lVar2 == param_1 + 0x3d8) || (lVar2 == 0x140)) || (*(int *)(lVar2 + 0x14) - 1U < 2)) {
    mutex_unlock(lVar1);
  }
  else {
    mutex_unlock(lVar1);
    queue_work_on(0x20,_system_long_wq,param_1 + 0x430);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_detect_port @ 0010bc30 size=296
// signature: undefined drm_dp_mst_detect_port(void)
// callers: []
//------------------------------------------------------------

int drm_dp_mst_detect_port(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar1 = param_3 + 800;
  mutex_lock(lVar1);
  if (((*(long *)(param_3 + 0x388) == 0) ||
      (lVar4 = drm_dp_mst_topology_get_port_validated_locked(*(long *)(param_3 + 0x388),param_4),
      lVar4 == 0)) || (iVar3 = drm_dp_mst_topology_try_get_port(), iVar3 == 0)) {
    mutex_unlock(lVar1);
    return 2;
  }
  mutex_unlock(lVar1);
  iVar3 = drm_modeset_lock(param_3 + 0x10,param_2);
  if (iVar3 != 0) goto LAB_0010bd34;
  if (*(char *)(lVar4 + 0xb) != '\0') {
    cVar2 = *(char *)(lVar4 + 0xc);
    if (cVar2 == '\x04') {
      iVar3 = 1;
      if (*(char *)(lVar4 + 0xd) == '\0') {
        iVar3 = 2;
      }
      goto LAB_0010bd34;
    }
    if (cVar2 == '\x03') {
      if ((*(byte *)(lVar4 + 8) < 8) || (*(long *)(lVar4 + 0x680) != 0)) {
        iVar3 = 1;
      }
      else {
        uVar5 = drm_get_edid(param_1,lVar4 + 0x38);
        iVar3 = 1;
        *(undefined8 *)(lVar4 + 0x680) = uVar5;
      }
      goto LAB_0010bd34;
    }
    if (cVar2 == '\x02') {
      iVar3 = 1;
      if (*(char *)(lVar4 + 10) != '\0') {
        iVar3 = 2;
      }
      goto LAB_0010bd34;
    }
  }
  iVar3 = 2;
LAB_0010bd34:
  drm_dp_mst_topology_put_port(lVar4);
  return iVar3;
}



//------------------------------------------------------------
// drm_dp_mst_get_edid @ 0010bd5c size=176
// signature: undefined drm_dp_mst_get_edid(void)
// callers: [drm_dp_mst_dump_topology]
//------------------------------------------------------------

undefined8 drm_dp_mst_get_edid(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar1 = param_2 + 800;
  mutex_lock(lVar1);
  if (((*(long *)(param_2 + 0x388) == 0) ||
      (lVar4 = drm_dp_mst_topology_get_port_validated_locked(*(long *)(param_2 + 0x388),param_3),
      lVar4 == 0)) || (iVar3 = drm_dp_mst_topology_try_get_port(), iVar3 == 0)) {
    mutex_unlock(lVar1);
    uVar5 = 0;
  }
  else {
    mutex_unlock(lVar1);
    if (*(long *)(lVar4 + 0x680) == 0) {
      uVar5 = drm_get_edid(param_1,lVar4 + 0x38);
    }
    else {
      uVar5 = drm_edid_duplicate();
    }
    bVar2 = drm_detect_monitor_audio();
    *(byte *)(lVar4 + 0x688) = bVar2 & 1;
    drm_dp_mst_topology_put_port(lVar4);
  }
  return uVar5;
}



//------------------------------------------------------------
// drm_dp_atomic_find_time_slots @ 0010be10 size=660
// signature: undefined drm_dp_atomic_find_time_slots(void)
// callers: [drm_dp_mst_atomic_enable_dsc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong drm_dp_atomic_find_time_slots(long param_1,long param_2,long param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  ulong uVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  undefined4 uVar16;
  
  uVar8 = drm_atomic_get_private_obj_state();
  if (0xfffffffffffff000 < uVar8) goto LAB_0010c024;
  iVar2 = *(int *)(*(long *)(param_3 + 0x670) + 0x98);
  if (iVar2 < *(int *)(param_1 + 0x28)) {
    lVar13 = *(long *)(*(long *)(param_1 + 0x30) + (long)iVar2 * 0x28 + 0x18);
  }
  else {
    lVar13 = 0;
  }
  plVar15 = (long *)(uVar8 + 0x38);
  *(uint *)(uVar8 + 0x18) =
       *(uint *)(uVar8 + 0x18) | 1 << (ulong)(*(uint *)(*(long *)(lVar13 + 8) + 0xa0) & 0x1f);
  plVar14 = plVar15;
  do {
    plVar14 = (long *)*plVar14;
    if (plVar14 == plVar15) {
      plVar9 = (long *)0x0;
      goto LAB_0010bed8;
    }
  } while (plVar14[-3] != param_3);
  plVar9 = plVar14 + -3;
  if (plVar9 == (long *)0x0) {
LAB_0010bed8:
    uVar12 = 0;
    uVar16 = 0;
    bVar6 = true;
  }
  else {
    if ((*(byte *)((long)plVar14 + -4) & 1) != 0) {
      uVar11 = dev_driver_string(*(undefined8 *)(*(long *)(param_2 + 0x68) + 8));
      plVar15 = *(long **)(*(long *)(param_2 + 0x68) + 8);
      lVar13 = plVar15[0xe];
      if (lVar13 == 0) {
        lVar13 = *plVar15;
      }
      __warn_printk("%s %s: %s",uVar11,lVar13,"drm_WARN_ON(payload->delete)");
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10c08c);
      (*pcVar7)();
    }
    uVar12 = *(undefined4 *)((long)plVar14 + -0xc);
    uVar16 = (undefined4)plVar14[-1];
    bVar6 = false;
  }
  iVar2 = *(int *)(uVar8 + 0x4c);
  uVar4 = 0;
  if (iVar2 != 0) {
    uVar4 = (param_4 + iVar2 + -1) / iVar2;
  }
  uVar8 = (ulong)uVar4;
  if (*(long *)(param_2 + 0x68) == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = *(undefined8 *)(*(long *)(param_2 + 0x68) + 8);
  }
  __drm_dev_dbg(0,uVar11,4,"[CONNECTOR:%d:%s] [MST PORT:%p] TU %d -> %d\n",
                *(undefined4 *)(*(long *)(param_3 + 0x670) + 0x40),
                *(undefined8 *)(*(long *)(param_3 + 0x670) + 0x60),param_3,uVar12,uVar4);
  if (*(long *)(param_2 + 0x68) == 0) {
    uVar11 = 0;
  }
  else {
    uVar11 = *(undefined8 *)(*(long *)(param_2 + 0x68) + 8);
  }
  __drm_dev_dbg(0,uVar11,4,"[CONNECTOR:%d:%s] [MST PORT:%p] PBN %d -> %d\n",
                *(undefined4 *)(*(long *)(param_3 + 0x670) + 0x40),
                *(undefined8 *)(*(long *)(param_3 + 0x670) + 0x60),param_3,uVar16,param_4);
  if (bVar6) {
    plVar9 = (long *)kmalloc_trace(_mutex_unlock,0xdc0,0x28);
    if (plVar9 == (long *)0x0) {
      uVar8 = 0xfffffff4;
      goto LAB_0010c024;
    }
    puVar1 = (uint *)(param_3 + 4);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar3 = *puVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar6) {
        *puVar1 = uVar3 + 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    if (uVar3 == 0) {
      uVar11 = 2;
LAB_0010c0c8:
      refcount_warn_saturate(puVar1,uVar11);
    }
    else if ((int)(uVar3 + 1 | uVar3) < 0) {
      uVar11 = 1;
      goto LAB_0010c0c8;
    }
    lVar13 = *(long *)(*(long *)(param_3 + 0x678) + 0x68);
    if (lVar13 == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = *(undefined8 *)(lVar13 + 8);
    }
    __drm_dev_dbg(0,uVar11,1,"port %p (%d)\n",param_3,*(undefined4 *)(param_3 + 4));
    *plVar9 = param_3;
    plVar14 = plVar9 + 3;
    *(undefined1 *)(plVar9 + 1) = 0xff;
    lVar13 = *plVar15;
    uVar10 = __list_add_valid(plVar14,plVar15,lVar13);
    if ((uVar10 & 1) != 0) {
      *(long **)(lVar13 + 8) = plVar14;
      plVar9[3] = lVar13;
      plVar9[4] = (long)plVar15;
      *plVar15 = (long)plVar14;
    }
  }
  *(uint *)((long)plVar9 + 0xc) = uVar4;
  *(int *)(plVar9 + 2) = param_4;
LAB_0010c024:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// drm_atomic_get_mst_topology_state @ 0010c0d4 size=28
// signature: undefined drm_atomic_get_mst_topology_state(void)
// callers: []
//------------------------------------------------------------

void drm_atomic_get_mst_topology_state(void)

{
  drm_atomic_get_private_obj_state();
  return;
}



//------------------------------------------------------------
// drm_dp_atomic_release_time_slots @ 0010c0f4 size=400
// signature: undefined drm_dp_atomic_release_time_slots(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong drm_dp_atomic_release_time_slots(long param_1,long param_2,long param_3)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  
  iVar2 = *(int *)(*(long *)(param_3 + 0x670) + 0x98);
  if (iVar2 < *(int *)(param_1 + 0x28)) {
    plVar9 = (long *)(*(long *)(*(long *)(param_1 + 0x30) + (long)iVar2 * 0x28 + 0x10) + 8);
    if (*plVar9 != 0) {
      plVar8 = (long *)(*(long *)(*(long *)(param_1 + 0x30) + (long)iVar2 * 0x28 + 0x18) + 8);
      lVar7 = *plVar8;
      if (*plVar8 != 0) goto LAB_0010c16c;
      bVar4 = true;
LAB_0010c19c:
      uVar5 = drm_atomic_get_private_obj_state(param_1,param_2);
      if (0xfffffffffffff000 < uVar5) goto LAB_0010c264;
      *(uint *)(uVar5 + 0x18) =
           *(uint *)(uVar5 + 0x18) | 1 << (ulong)(*(uint *)(*plVar9 + 0xa0) & 0x1f);
      if (bVar4) {
        plVar9 = (long *)(uVar5 + 0x38);
        do {
          plVar9 = (long *)*plVar9;
          if (plVar9 == (long *)(uVar5 + 0x38)) goto LAB_0010c280;
        } while (plVar9[-3] != param_3);
        if (plVar9 == (long *)0x18) {
LAB_0010c280:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10c284);
          (*pcVar3)();
        }
        if (*plVar8 == 0) {
          if (*(long *)(param_2 + 0x68) == 0) {
            uVar6 = 0;
          }
          else {
            uVar6 = *(undefined8 *)(*(long *)(param_2 + 0x68) + 8);
          }
          __drm_dev_dbg(0,uVar6,4,"[MST PORT:%p] TU %d -> 0\n",param_3,
                        *(undefined4 *)((long)plVar9 + -0xc));
          if ((*(byte *)((long)plVar9 + -4) & 1) == 0) {
            *(undefined4 *)(plVar9 + -1) = 0;
            *(byte *)((long)plVar9 + -4) = *(byte *)((long)plVar9 + -4) | 1;
            *(uint *)(uVar5 + 0x30) =
                 *(uint *)(uVar5 + 0x30) &
                 ((uint)(1L << ((ulong)(*(byte *)((long)plVar9 + -0xf) - 1) & 0x3f)) ^ 0xffffffff);
          }
        }
      }
    }
  }
  else {
    plVar8 = (long *)&DAT_00000008;
    plVar9 = (long *)&DAT_00000008;
    lVar7 = _DAT_00000008;
    if (_DAT_00000008 != 0) {
LAB_0010c16c:
      lVar7 = *(long *)(*(long *)(param_1 + 0x20) + (ulong)*(uint *)(lVar7 + 0xa0) * 0x38 + 0x18);
      if (lVar7 != 0) {
        bVar1 = *(byte *)(lVar7 + 10);
        if ((bVar1 & 0xe) != 0) {
          bVar4 = (bVar1 & 10) != 0;
          goto LAB_0010c19c;
        }
      }
    }
  }
  uVar5 = 0;
LAB_0010c264:
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// drm_dp_mst_atomic_setup_commit @ 0010c2ac size=392
// signature: undefined drm_dp_mst_atomic_setup_commit(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_mst_atomic_setup_commit(long param_1)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  if (0 < *(int *)(param_1 + 0x38)) {
    lVar9 = 0;
    do {
      if ((*(undefined ***)(*(long *)(*(long *)(param_1 + 0x40) + lVar9 * 0x20) + 0x60) ==
           &drm_dp_mst_topology_state_funcs) &&
         (lVar10 = *(long *)(*(long *)(param_1 + 0x40) + lVar9 * 0x20 + 0x18),
         *(int *)(lVar10 + 0x18) != 0)) {
        iVar5 = __sw_hweight32();
        if (iVar5 < 0) {
          *(undefined8 *)(lVar10 + 0x20) = 0;
          return 0xfffffff4;
        }
        lVar6 = __kmalloc((long)iVar5 << 3,0xcc0);
        *(long *)(lVar10 + 0x20) = lVar6;
        if (lVar6 == 0) {
          return 0xfffffff4;
        }
        *(long *)(lVar10 + 0x28) = (long)iVar5;
        lVar6 = *(long *)(param_1 + 8);
        if (0 < *(int *)(lVar6 + 0x360)) {
          lVar11 = 0;
          lVar12 = 0;
          iVar5 = 0;
          do {
            lVar8 = *(long *)(*(long *)(param_1 + 0x20) + lVar11);
            if ((lVar8 != 0) &&
               ((*(uint *)(lVar10 + 0x18) >> (ulong)(*(uint *)(lVar8 + 0xa0) & 0x1f) & 1) != 0)) {
              lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x20) + lVar11 + 0x18) + 0x140);
              puVar1 = (uint *)(lVar6 + 8);
              Hint_Prefetch(puVar1,2,0,1);
              do {
                uVar2 = *puVar1;
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                if (bVar4) {
                  *puVar1 = uVar2 + 1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              if (uVar2 == 0) {
                uVar7 = 2;
LAB_0010c370:
                refcount_warn_saturate(puVar1,uVar7);
              }
              else if ((int)(uVar2 + 1 | uVar2) < 0) {
                uVar7 = 1;
                goto LAB_0010c370;
              }
              *(long *)(*(long *)(lVar10 + 0x20) + (long)iVar5 * 8) = lVar6;
              lVar6 = *(long *)(param_1 + 8);
              iVar5 = iVar5 + 1;
            }
            lVar12 = lVar12 + 1;
            lVar11 = lVar11 + 0x38;
          } while (lVar12 < *(int *)(lVar6 + 0x360));
        }
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 < *(int *)(param_1 + 0x38));
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_mst_atomic_wait_for_dependencies @ 0010c440 size=328
// signature: undefined drm_dp_mst_atomic_wait_for_dependencies(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_atomic_wait_for_dependencies(long param_1)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  
  if (0 < *(int *)(param_1 + 0x38)) {
    lVar7 = 0;
    do {
      if (*(undefined ***)(*(long *)(*(long *)(param_1 + 0x40) + lVar7 * 0x20) + 0x60) ==
          &drm_dp_mst_topology_state_funcs) {
        lVar5 = *(long *)(param_1 + 0x40) + lVar7 * 0x20;
        lVar2 = *(long *)(lVar5 + 0x10);
        lVar5 = *(long *)(lVar5 + 0x18);
        if (*(long *)(lVar2 + 0x28) != 0) {
          uVar9 = 0;
          do {
            iVar3 = drm_crtc_commit_wait(*(undefined8 *)(*(long *)(lVar2 + 0x20) + uVar9 * 8));
            if (iVar3 < 0) {
              _dev_err(*(undefined8 *)(*(long *)(param_1 + 8) + 8),
                       "[drm] *ERROR* Failed to wait for %s: %d\n",
                       *(undefined8 *)(**(long **)(*(long *)(lVar2 + 0x20) + uVar9 * 8) + 0x20),
                       iVar3);
            }
            uVar9 = (ulong)((int)uVar9 + 1);
          } while (uVar9 < *(ulong *)(lVar2 + 0x28));
        }
        plVar8 = (long *)(lVar2 + 0x38);
        plVar4 = (long *)*plVar8;
        if (plVar4 != plVar8) {
          plVar1 = (long *)(lVar5 + 0x38);
          do {
            if ((*(byte *)((long)plVar4 + -4) & 1) == 0) {
              plVar6 = plVar1;
              do {
                plVar6 = (long *)*plVar6;
                if (plVar6 == plVar1) {
                  lVar5 = 0;
                  goto LAB_0010c528;
                }
              } while (plVar6[-3] != plVar4[-3]);
              lVar5 = (long)(plVar6 + -3);
LAB_0010c528:
              *(char *)(lVar5 + 8) = (char)plVar4[-2];
            }
            plVar4 = (long *)*plVar4;
          } while (plVar4 != plVar8);
        }
      }
      lVar7 = lVar7 + 1;
    } while (lVar7 < *(int *)(param_1 + 0x38));
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_root_conn_atomic_check @ 0010c58c size=312
// signature: undefined drm_dp_mst_root_conn_atomic_check(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_mst_root_conn_atomic_check(long *param_1,undefined8 param_2)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = param_1[4];
  if (*(int *)(*param_1 + 0x98) < *(int *)(lVar4 + 0x28)) {
    lVar5 = *(long *)(*(long *)(lVar4 + 0x30) + (long)*(int *)(*param_1 + 0x98) * 0x28 + 0x10);
    lVar3 = param_1[1];
  }
  else {
    lVar5 = 0;
    lVar3 = param_1[1];
  }
  if (((lVar3 == 0) ||
      (lVar3 = *(long *)(*(long *)(lVar4 + 0x20) + (ulong)*(uint *)(lVar3 + 0xa0) * 0x38 + 0x18),
      lVar3 == 0)) || ((*(byte *)(lVar3 + 10) & 0xe) == 0)) {
    uVar1 = 0;
    lVar3 = *(long *)(lVar5 + 8);
  }
  else {
    uVar1 = drm_atomic_get_private_obj_state(lVar4,param_2);
    if (0xfffffffffffff000 < uVar1) {
      return uVar1;
    }
    *(uint *)(uVar1 + 0x18) =
         *(uint *)(uVar1 + 0x18) | 1 << (ulong)(*(uint *)(param_1[1] + 0xa0) & 0x1f);
    lVar3 = *(long *)(lVar5 + 8);
  }
  if (lVar3 != 0) {
    uVar2 = *(uint *)(lVar3 + 0xa0);
    lVar3 = *(long *)(*(long *)(lVar4 + 0x20) + (ulong)uVar2 * 0x38 + 0x18);
    if ((lVar3 != 0) && ((*(byte *)(lVar3 + 10) & 0xe) != 0)) {
      if (uVar1 == 0) {
        uVar1 = drm_atomic_get_private_obj_state(lVar4,param_2);
        if (0xfffffffffffff000 < uVar1) {
          return uVar1;
        }
        uVar2 = *(uint *)(*(long *)(lVar5 + 8) + 0xa0);
      }
      *(uint *)(uVar1 + 0x18) = *(uint *)(uVar1 + 0x18) | 1 << (ulong)(uVar2 & 0x1f);
    }
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_mst_update_slots @ 0010c6c8 size=96
// signature: undefined drm_dp_mst_update_slots(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_update_slots(long param_1,char param_2)

{
  char *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  
  bVar2 = param_2 != '\x02';
  uVar3 = 0x3f;
  if (!bVar2) {
    uVar3 = 0x40;
  }
  pcVar1 = "8b/10b";
  if (!bVar2) {
    pcVar1 = "128b/132b";
  }
  *(bool *)(param_1 + 0x49) = bVar2;
  *(undefined1 *)(param_1 + 0x48) = uVar3;
  ___drm_dbg(0,2,"%s encoding format on mst_state 0x%p\n",pcVar1,param_1);
  return;
}



//------------------------------------------------------------
// drm_dp_check_act_status @ 0010c72c size=380
// signature: undefined drm_dp_check_act_status(void)
// callers: []
//------------------------------------------------------------

uint drm_dp_check_act_status(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  byte local_40 [4];
  byte local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = ktime_get();
  local_40[0] = 0;
  uVar1 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),0x2c0,local_40,1);
  if (-1 < (int)uVar1) {
    uVar1 = (uint)local_40[0];
  }
  if ((uVar1 & 0x80000002) == 0) {
    do {
      lVar3 = ktime_get();
      if (lVar2 + 3000000000 < lVar3) {
        local_3c[0] = 0;
        uVar1 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),0x2c0,local_3c,1);
        if (-1 < (int)uVar1) {
          uVar1 = (uint)local_3c[0];
        }
        break;
      }
      usleep_range_state(0x33,200,2);
      Yield();
      local_40[0] = 0;
      uVar1 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),0x2c0,local_40,1);
      if (-1 < (int)uVar1) {
        uVar1 = (uint)local_40[0];
      }
    } while ((uVar1 & 0x80000002) == 0);
  }
  if ((uVar1 & 0x80000002) == 0) {
    _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
             "[drm] *ERROR* Failed to get ACT after %dms, last status: %02x\n",3000,uVar1);
    uVar1 = 0xffffffea;
  }
  else if ((int)uVar1 < 0) {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar4,2,"Failed to read payload table status: %d\n",uVar1);
  }
  else {
    uVar1 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}



//------------------------------------------------------------
// drm_dp_calc_pbn_mode @ 0010c8ac size=56
// signature: undefined drm_dp_calc_pbn_mode(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_calc_pbn_mode(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = param_2 + 0xf;
  if (-1 < param_2) {
    iVar1 = param_2;
  }
  iVar1 = iVar1 >> 4;
  if ((param_3 & 1) == 0) {
    iVar1 = param_2;
  }
  return ((ulong)(uint)(iVar1 * param_1) * 0xfb80 + 431999999) / 432000000;
}



//------------------------------------------------------------
// drm_dp_mst_dump_topology @ 0010c8e8 size=1116
// signature: undefined drm_dp_mst_dump_topology(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_dump_topology(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  long *plVar8;
  uint uVar9;
  char local_a8 [16];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  lVar1 = param_2 + 800;
  local_68 = *(long *)(lVar7 + 0x638);
  mutex_lock(lVar1);
  if (*(long *)(param_2 + 0x388) != 0) {
    drm_dp_mst_dump_mstb(param_1);
  }
  mutex_unlock(lVar1);
  iVar4 = drm_modeset_lock_single_interruptible(param_2 + 0x10);
  if (iVar4 < 0) goto LAB_0010cd08;
  lVar7 = *(long *)(param_2 + 0x58);
  seq_printf(param_1,"\n*** Atomic state info ***\n");
  seq_printf(param_1,"payload_mask: %x, max_payloads: %d, start_slot: %u, pbn_div: %d\n",
             *(undefined4 *)(lVar7 + 0x30),*(undefined4 *)(param_2 + 0x88),
             *(undefined1 *)(lVar7 + 0x49),*(undefined4 *)(lVar7 + 0x4c));
  seq_printf(param_1,"\n| idx | port | vcpi | slots | pbn | dsc |     sink name     |\n");
  iVar4 = *(int *)(param_2 + 0x88);
  if (0 < iVar4) {
    uVar9 = 0;
    plVar2 = (long *)(lVar7 + 0x38);
    do {
      plVar8 = (long *)*plVar2;
      if (plVar8 != plVar2) {
        do {
          local_a8[8] = 0;
          local_a8[9] = 0;
          local_a8[10] = 0;
          local_a8[0xb] = 0;
          local_a8[0xc] = '\0';
          local_a8[0xd] = '\0';
          local_a8[0] = '\0';
          local_a8[1] = '\0';
          local_a8[2] = '\0';
          local_a8[3] = '\0';
          local_a8[4] = '\0';
          local_a8[5] = '\0';
          local_a8[6] = '\0';
          local_a8[7] = '\0';
          if ((uVar9 == *(byte *)((long)plVar8 + -0xf)) && ((*(byte *)((long)plVar8 + -4) & 1) == 0)
             ) {
            uVar5 = drm_dp_mst_get_edid(*(undefined8 *)(plVar8[-3] + 0x670),param_2);
            drm_edid_get_monitor_name(uVar5,local_a8,0xe);
            kfree(uVar5);
            puVar3 = &DAT_00114f62;
            if ((*(byte *)((long)plVar8 + -4) & 2) != 0) {
              puVar3 = &DAT_00115132;
            }
            pcVar6 = "Unknown";
            if (local_a8[0] != '\0') {
              pcVar6 = local_a8;
            }
            seq_printf(param_1," %5d %6d %6d %02d - %02d %5d %5s %19s\n",uVar9,
                       *(undefined1 *)(plVar8[-3] + 8),*(undefined1 *)((long)plVar8 + -0xf),
                       *(byte *)(plVar8 + -2),
                       (uint)*(byte *)(plVar8 + -2) + *(int *)((long)plVar8 + -0xc) + -1,
                       (int)plVar8[-1],puVar3,pcVar6);
          }
          plVar8 = (long *)*plVar8;
        } while (plVar8 != plVar2);
        iVar4 = *(int *)(param_2 + 0x88);
      }
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < iVar4);
  }
  seq_printf(param_1,"\n*** DPCD Info ***\n");
  mutex_lock(lVar1);
  if (*(long *)(param_2 + 0x388) != 0) {
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8[0] = '\0';
    local_a8[1] = '\0';
    local_a8[2] = '\0';
    local_a8[3] = '\0';
    local_a8[4] = '\0';
    local_a8[5] = '\0';
    local_a8[6] = '\0';
    local_a8[7] = '\0';
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[10] = 0;
    local_a8[0xb] = 0;
    local_a8[0xc] = '\0';
    local_a8[0xd] = '\0';
    local_a8[0xe] = '\0';
    local_a8[0xf] = '\0';
    iVar4 = drm_dp_read_dpcd_caps(*(undefined8 *)(param_2 + 0x80),local_a8);
    if (iVar4 < 0) {
      pcVar6 = "dpcd read failed\n";
    }
    else {
      seq_printf(param_1,"dpcd: %*ph\n",0xf,local_a8);
      iVar4 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x20,local_a8,2);
      if (iVar4 == 2) {
        seq_printf(param_1,"faux/mst: %*ph\n",2,local_a8);
        iVar4 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x111,local_a8,1);
        if (iVar4 == 1) {
          seq_printf(param_1,"mst ctrl: %*ph\n",1,local_a8);
          iVar4 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x500,local_a8,0xc);
          if (iVar4 == 0xc) {
            seq_printf(param_1,"branch oui: %*phN devid: ",3,local_a8);
            if ((((local_a8[3] != '\0') && (seq_printf(param_1,&DAT_0011425f), local_a8[4] != '\0'))
                && (seq_printf(param_1,&DAT_0011425f), local_a8[5] != '\0')) &&
               ((seq_printf(param_1,&DAT_0011425f), local_a8[6] != '\0' &&
                (seq_printf(param_1,&DAT_0011425f), local_a8[7] != '\0')))) {
              seq_printf(param_1,&DAT_0011425f);
            }
            seq_printf(param_1," revision: hw: %x.%x sw: %x.%x\n",(byte)local_a8[9] >> 4,
                       local_a8[9] & 0xf,local_a8[10],local_a8[0xb]);
            lVar7 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x2c0,local_a8,0x10);
            if (((lVar7 == 0x10) &&
                (lVar7 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x2d0,&local_98,0x10),
                lVar7 == 0x10)) &&
               ((lVar7 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x2e0,&local_88,0x10),
                lVar7 == 0x10 &&
                (lVar7 = drm_dp_dpcd_read(*(undefined8 *)(param_2 + 0x80),0x2f0,&local_78,0x10),
                lVar7 == 0x10)))) {
              seq_printf(param_1,"payload table: %*ph\n",0x40,local_a8);
            }
            goto LAB_0010ccf8;
          }
          pcVar6 = "branch oui read failed\n";
        }
        else {
          pcVar6 = "mst ctrl read failed\n";
        }
      }
      else {
        pcVar6 = "faux/mst read failed\n";
      }
    }
    seq_printf(param_1,pcVar6);
  }
LAB_0010ccf8:
  mutex_unlock(lVar1);
  drm_modeset_unlock(param_2 + 0x10);
LAB_0010cd08:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_dump_mstb @ 0010cd44 size=568
// signature: undefined drm_dp_mst_dump_mstb(void)
// callers: [drm_dp_mst_dump_mstb, drm_dp_mst_dump_topology]
//------------------------------------------------------------

void drm_dp_mst_dump_mstb(undefined8 param_1,long param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  char cVar4;
  code *pcVar5;
  undefined *puVar6;
  long lVar7;
  long *plVar8;
  undefined8 local_78;
  undefined2 local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  cVar4 = *(char *)(param_2 + 0x20);
  local_70 = 0;
  local_78 = 0;
  if (cVar4 == '\0') {
    lVar7 = 0;
  }
  else {
    local_78 = 9;
    if (cVar4 == '\x01') {
      lVar7 = 1;
    }
    else {
      local_78 = 0x909;
      if (cVar4 == '\x02') {
        lVar7 = 2;
      }
      else {
        local_78 = 0x90909;
        if (cVar4 == '\x03') {
          lVar7 = 3;
        }
        else {
          local_78 = 0x9090909;
          if (cVar4 == '\x04') {
            lVar7 = 4;
          }
          else {
            local_78 = 0x909090909;
            if (cVar4 == '\x05') {
              lVar7 = 5;
            }
            else {
              local_78 = 0x90909090909;
              if (cVar4 == '\x06') {
                lVar7 = 6;
              }
              else {
                local_78 = 0x9090909090909;
                if (cVar4 == '\a') {
                  lVar7 = 7;
                }
                else {
                  local_78 = 0x909090909090909;
                  if (cVar4 == '\b') {
                    lVar7 = 8;
                  }
                  else {
                    lVar7 = 9;
                    local_70 = 9;
                    if (cVar4 != '\t') {
                    /* WARNING: Does not return */
                      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10cf7c);
                      (*pcVar5)();
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
  uVar3 = *(undefined4 *)(param_2 + 0x24);
  *(undefined1 *)((long)&local_78 + lVar7) = 0;
  seq_printf(param_1,"%smstb - [%p]: num_ports: %d\n",&local_78,param_2,uVar3);
  for (plVar8 = *(long **)(param_2 + 0x28); plVar8 != (long *)(param_2 + 0x28);
      plVar8 = (long *)*plVar8) {
    puVar6 = &UNK_001155de;
    pcVar1 = "output";
    if (*(char *)((long)plVar8 + -0xf) != '\0') {
      pcVar1 = "input";
    }
    if ((ulong)(long)*(char *)((long)plVar8 + -0xc) < 5) {
      puVar6 = (&PTR_DAT_001160b0)[*(char *)((long)plVar8 + -0xc)];
    }
    pcVar2 = "false";
    if (*(char *)((long)plVar8 + 0x671) != '\0') {
      pcVar2 = "true";
    }
    seq_printf(param_1,
               "%sport %d - [%p] (%s - %s): ddps: %d, ldps: %d, sdp: %d/%d, fec: %s, conn: %p\n",
               &local_78,*(undefined1 *)(plVar8 + -2),plVar8 + -3,pcVar1,puVar6,
               *(undefined1 *)((long)plVar8 + -0xd),*(undefined1 *)((long)plVar8 + -0xb),
               *(undefined1 *)((long)plVar8 + -9),*(undefined1 *)(plVar8 + -1),pcVar2,plVar8[0xcb]);
    if (plVar8[2] != 0) {
      drm_dp_mst_dump_mstb(param_1);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_add_affected_dsc_crtcs @ 0010cf80 size=280
// signature: undefined drm_dp_mst_add_affected_dsc_crtcs(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_mst_add_affected_dsc_crtcs(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  
  puVar1 = (undefined8 *)drm_atomic_get_private_obj_state();
  if (puVar1 < (undefined8 *)0xfffffffffffff001) {
    for (plVar6 = (long *)puVar1[7]; plVar6 != puVar1 + 7; plVar6 = (long *)*plVar6) {
      if (*(long *)(plVar6[-3] + 0x670) == 0) {
        puVar1 = (undefined8 *)0xffffffea;
        goto LAB_0010d078;
      }
      uVar2 = drm_atomic_get_connector_state(param_1);
      if (0xfffffffffffff000 < uVar2) {
        puVar1 = (undefined8 *)(uVar2 & 0xffffffff);
        goto LAB_0010d078;
      }
      lVar5 = *(long *)(uVar2 + 8);
      if ((lVar5 != 0) && (lVar3 = drm_dp_mst_dsc_aux_for_port(plVar6[-3]), lVar3 != 0)) {
        uVar2 = drm_atomic_get_crtc_state(*puVar1,lVar5);
        if (0xfffffffffffff000 < uVar2) {
          puVar1 = (undefined8 *)(uVar2 & 0xffffffff);
          goto LAB_0010d078;
        }
        if (*(long *)(param_2 + 0x68) == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = *(undefined8 *)(*(long *)(param_2 + 0x68) + 8);
        }
        __drm_dev_dbg(0,uVar4,4,"[MST MGR:%p] Setting mode_changed flag on CRTC %p\n",param_2,lVar5)
        ;
        *(byte *)(uVar2 + 10) = *(byte *)(uVar2 + 10) | 2;
      }
    }
    puVar1 = (undefined8 *)0x0;
  }
LAB_0010d078:
  return (ulong)puVar1 & 0xffffffff;
}



//------------------------------------------------------------
// drm_dp_mst_dsc_aux_for_port @ 0010d09c size=536
// signature: undefined drm_dp_mst_dsc_aux_for_port(void)
// callers: [drm_dp_mst_add_affected_dsc_crtcs]
//------------------------------------------------------------

long drm_dp_mst_dsc_aux_for_port(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  byte local_60 [4];
  byte local_5c [4];
  undefined8 local_58;
  undefined8 uStack_50;
  byte local_48 [16];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_5c[0] = 0;
  local_60[0] = 0;
  if (param_1 != 0) {
    lVar5 = *(long *)(*(long *)(param_1 + 0x668) + 0x38);
    if (lVar5 != 0) {
      lVar4 = lVar5;
      do {
        uVar2 = drm_dp_mst_is_virtual_dpcd(lVar4);
        if (((uVar2 & 1) == 0) && (*(char *)(lVar4 + 0x689) == '\0')) goto LAB_0010d274;
        lVar4 = *(long *)(*(long *)(lVar4 + 0x668) + 0x38);
      } while (lVar4 != 0);
    }
    uVar2 = drm_dp_mst_is_virtual_dpcd(lVar5);
    if ((uVar2 & 1) == 0) {
      uVar2 = drm_dp_mst_is_virtual_dpcd(param_1);
      if ((uVar2 & 1) != 0) {
        lVar4 = param_1 + 0x30;
        goto LAB_0010d278;
      }
      iVar1 = drm_dp_read_desc(*(undefined8 *)(*(long *)(param_1 + 0x678) + 0x80),&local_58,1);
      if (iVar1 == 0) {
        if ((((uStack_50._4_1_ >> 3 & 1) != 0) &&
            (lVar5 = *(long *)(param_1 + 0x678), 0x13 < *(byte *)(lVar5 + 0x390))) &&
           (*(long *)(param_1 + 0x668) == *(long *)(lVar5 + 0x388))) {
          local_48[8] = 0;
          local_48[9] = 0;
          local_48[10] = 0;
          local_48[0xb] = 0;
          local_48[0xc] = 0;
          local_48[0xd] = 0;
          local_48[0xe] = 0;
          local_48[0] = 0;
          local_48[1] = 0;
          local_48[2] = 0;
          local_48[3] = 0;
          local_48[4] = 0;
          local_48[5] = 0;
          local_48[6] = 0;
          local_48[7] = 0;
          iVar1 = drm_dp_read_dpcd_caps(*(undefined8 *)(lVar5 + 0x80),local_48);
          if (iVar1 < 0) goto LAB_0010d274;
          if (((local_48[5] & 1) != 0) && ((local_48[5] & 6) != 2)) {
            lVar4 = *(long *)(*(long *)(param_1 + 0x678) + 0x80);
            goto LAB_0010d278;
          }
        }
        lVar4 = param_1 + 0x30;
        lVar5 = drm_dp_dpcd_read(lVar4,0x60,local_60,1);
        if (((lVar5 == 1) && (lVar5 = drm_dp_dpcd_read(lVar4,0x90,local_5c,1), lVar5 == 1)) &&
           (((local_60[0] & 1) != 0 && ((local_5c[0] & 1) != 0)))) goto LAB_0010d278;
      }
    }
    else {
      lVar4 = param_1 + 0x30;
      local_48[0] = 0;
      lVar3 = drm_dp_dpcd_read(lVar4,0x60,local_60,1);
      if ((lVar3 == 1) && (lVar3 = drm_dp_dpcd_read(lVar4,0x90,local_5c,1), lVar3 == 1)) {
        lVar5 = lVar5 + 0x30;
        lVar3 = drm_dp_dpcd_read(lVar5,0x60,local_48,1);
        if (lVar3 == 1) {
          if ((((local_60[0] & 1) == 0) || ((local_5c[0] & 1) == 0)) ||
             ((local_48[0] >> 1 & 1) == 0)) {
            lVar4 = lVar5;
          }
          else {
            *(long *)(param_1 + 0x660) = lVar5;
          }
          goto LAB_0010d278;
        }
      }
    }
  }
LAB_0010d274:
  lVar4 = 0;
LAB_0010d278:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// drm_dp_mst_atomic_enable_dsc @ 0010d2b8 size=376
// signature: undefined drm_dp_mst_atomic_enable_dsc(void)
// callers: []
//------------------------------------------------------------

ulong drm_dp_mst_atomic_enable_dsc(long param_1,long param_2,undefined4 param_3,byte param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  byte bVar4;
  long *plVar5;
  
  uVar1 = drm_atomic_get_private_obj_state(param_1,*(undefined8 *)(param_2 + 0x678));
  if (0xfffffffffffff000 < uVar1) goto LAB_0010d414;
  plVar5 = (long *)(uVar1 + 0x38);
  do {
    plVar5 = (long *)*plVar5;
    if (plVar5 == (long *)(uVar1 + 0x38)) goto LAB_0010d344;
  } while (plVar5[-3] != param_2);
  if (plVar5 == (long *)0x18) {
LAB_0010d344:
    if (*(long *)(param_1 + 8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(*(long *)(param_1 + 8) + 8);
    }
    __drm_dev_dbg(0,uVar3,4,"[MST PORT:%p] Couldn\'t find payload in mst state %p\n",param_2,uVar1);
LAB_0010d374:
    uVar1 = 0xffffffea;
  }
  else {
    if (((*(byte *)((long)plVar5 + -4) & 2) == 0) == (bool)(param_4 & 1)) {
      uVar1 = 0;
      if ((param_4 & 1) == 0) goto LAB_0010d384;
LAB_0010d3b4:
      uVar2 = drm_dp_atomic_find_time_slots
                        (param_1,*(undefined8 *)(param_2 + 0x678),param_2,param_3);
      uVar1 = uVar2 & 0xffffffff;
      if (*(long *)(param_1 + 8) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(*(long *)(param_1 + 8) + 8);
      }
      __drm_dev_dbg(0,uVar3,4,
                    "[MST PORT:%p] Enabling DSC flag, reallocating %d time slots on the port\n",
                    param_2,uVar1);
      if ((int)uVar2 < 0) goto LAB_0010d374;
      bVar4 = 2;
    }
    else {
      if (*(long *)(param_1 + 8) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(*(long *)(param_1 + 8) + 8);
      }
      __drm_dev_dbg(0,uVar3,4,
                    "[MST PORT:%p] DSC flag is already set to %d, returning %d time slots\n",param_2
                    ,param_4 & 1,*(undefined4 *)((long)plVar5 + -0xc));
      uVar1 = (ulong)*(uint *)((long)plVar5 + -0xc);
      if ((param_4 & 1) != 0) goto LAB_0010d3b4;
LAB_0010d384:
      bVar4 = 0;
    }
    *(byte *)((long)plVar5 + -4) = *(byte *)((long)plVar5 + -4) & 0xfd | bVar4;
  }
LAB_0010d414:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// drm_dp_mst_atomic_check @ 0010d434 size=696
// signature: undefined drm_dp_mst_atomic_check(void)
// callers: []
//------------------------------------------------------------

int drm_dp_mst_atomic_check(long param_1)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  
  iVar3 = *(int *)(param_1 + 0x38);
  if (0 < iVar3) {
    lVar10 = 0;
    do {
      lVar9 = *(long *)(*(long *)(param_1 + 0x40) + lVar10 * 0x20);
      if ((*(undefined ***)(lVar9 + 0x60) == &drm_dp_mst_topology_state_funcs) &&
         ((*(byte *)(lVar9 + 0x380) & 1) != 0)) {
        lVar7 = *(long *)(*(long *)(param_1 + 0x40) + lVar10 * 0x20 + 0x18);
        plVar6 = (long *)(lVar7 + 0x38);
        plVar11 = (long *)*plVar6;
        uVar8 = (uint)*(byte *)(lVar7 + 0x48);
        if (plVar11 == plVar6) {
LAB_0010d5dc:
          *(undefined4 *)(lVar7 + 0x4c) = 0;
          lVar5 = *(long *)(lVar9 + 0x68);
          if (lVar5 != 0) goto LAB_0010d5d4;
LAB_0010d5e8:
          uVar4 = 0;
        }
        else {
          iVar3 = 0;
          do {
            lVar5 = *(long *)(lVar9 + 0x68);
            if ((*(byte *)((long)plVar11 + -4) & 1) == 0) {
              if (lVar5 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(undefined8 *)(lVar5 + 8);
              }
              __drm_dev_dbg(0,uVar4,4,"[MST PORT:%p] requires %d time slots\n",plVar11[-3],
                            *(undefined4 *)((long)plVar11 + -0xc));
              uVar2 = uVar8 - *(int *)((long)plVar11 + -0xc);
              if ((int)uVar2 < 0) {
                if (*(long *)(lVar9 + 0x68) == 0) {
                  uVar4 = 0;
                }
                else {
                  uVar4 = *(undefined8 *)(*(long *)(lVar9 + 0x68) + 8);
                }
                __drm_dev_dbg(0,uVar4,4,
                              "[MST PORT:%p] not enough time slots in mst state %p (avail=%d)\n",
                              plVar11[-3],lVar7,uVar8);
                return -0x1c;
              }
              iVar3 = iVar3 + 1;
              if (*(int *)(lVar9 + 0x88) < iVar3) {
                if (*(long *)(lVar9 + 0x68) == 0) {
                  uVar4 = 0;
                }
                else {
                  uVar4 = *(undefined8 *)(*(long *)(lVar9 + 0x68) + 8);
                }
                __drm_dev_dbg(0,uVar4,4,"[MST MGR:%p] state %p has too many payloads (max=%d)\n",
                              lVar9,lVar7);
                return -0x16;
              }
              uVar8 = uVar2;
              if (*(char *)((long)plVar11 + -0xf) == '\0') {
                uVar1 = ((ulong)~*(uint *)(lVar7 + 0x30) & 0xaaaaaaaaaaaaaaaa) >> 1 |
                        ((ulong)~*(uint *)(lVar7 + 0x30) & 0x5555555555555555) << 1;
                uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
                uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
                uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
                *(char *)((long)plVar11 + -0xf) =
                     (char)LZCOUNT((uVar1 >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10) << 0x20) +
                     '\x01';
                if (*(long *)(lVar9 + 0x68) == 0) {
                  uVar4 = 0;
                }
                else {
                  uVar4 = *(undefined8 *)(*(long *)(lVar9 + 0x68) + 8);
                }
                __drm_dev_dbg(0,uVar4,4,"[MST PORT:%p] assigned VCPI #%d\n",plVar11[-3]);
                *(uint *)(lVar7 + 0x30) =
                     *(uint *)(lVar7 + 0x30) |
                     (uint)(1L << ((ulong)(*(byte *)((long)plVar11 + -0xf) - 1) & 0x3f));
              }
            }
            else {
              if (lVar5 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(undefined8 *)(lVar5 + 8);
              }
              __drm_dev_dbg(0,uVar4,4,"[MST PORT:%p] releases all time slots\n",plVar11[-3]);
            }
            plVar11 = (long *)*plVar11;
          } while (plVar11 != plVar6);
          if (iVar3 == 0) goto LAB_0010d5dc;
          lVar5 = *(long *)(lVar9 + 0x68);
          if (lVar5 == 0) goto LAB_0010d5e8;
LAB_0010d5d4:
          uVar4 = *(undefined8 *)(lVar5 + 8);
        }
        __drm_dev_dbg(0,uVar4,4,"[MST MGR:%p] mst state %p TU pbn_div=%d avail=%d used=%d\n",lVar9,
                      lVar7,*(undefined4 *)(lVar7 + 0x4c),uVar8,*(byte *)(lVar7 + 0x48) - uVar8);
        mutex_lock(lVar9 + 800);
        iVar3 = drm_dp_mst_atomic_check_mstb_bw_limit(*(undefined8 *)(lVar9 + 0x388),lVar7);
        mutex_unlock(lVar9 + 800);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = *(int *)(param_1 + 0x38);
      }
      lVar10 = lVar10 + 1;
    } while (lVar10 < iVar3);
  }
  return 0;
}



//------------------------------------------------------------
// drm_dp_mst_atomic_check_mstb_bw_limit @ 0010d6ec size=588
// signature: undefined drm_dp_mst_atomic_check_mstb_bw_limit(void)
// callers: [drm_dp_mst_atomic_check_mstb_bw_limit, drm_dp_mst_atomic_check]
//------------------------------------------------------------

int drm_dp_mst_atomic_check_mstb_bw_limit(long param_1,long param_2)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  int iVar11;
  
  plVar9 = (long *)(param_2 + 0x38);
  plVar4 = (long *)*plVar9;
  do {
    if (plVar4 == plVar9) {
      return 0;
    }
    if (*(int *)(plVar4 + -1) != 0) {
      lVar7 = plVar4[-3];
      do {
        lVar7 = *(long *)(lVar7 + 0x668);
        if (lVar7 == 0) break;
        if (lVar7 == param_1) {
          lVar7 = *(long *)(param_1 + 0x38);
          lVar5 = *(long *)(*(long *)(param_1 + 0x40) + 0x68);
          if (lVar7 == 0) {
            if (lVar5 == 0) {
              uVar3 = 0;
            }
            else {
              uVar3 = *(undefined8 *)(lVar5 + 8);
            }
            __drm_dev_dbg(0,uVar3,4,"[MSTB:%p] Checking bandwidth limits\n",param_1);
          }
          else {
            if (lVar5 == 0) {
              uVar3 = 0;
            }
            else {
              uVar3 = *(undefined8 *)(lVar5 + 8);
            }
            __drm_dev_dbg(0,uVar3,4,
                          "[MSTB:%p] [MST PORT:%p] Checking bandwidth limits on [MSTB:%p]\n",
                          *(undefined8 *)(lVar7 + 0x668),lVar7,param_1);
          }
          plVar4 = (long *)(param_1 + 0x28);
          plVar10 = (long *)*plVar4;
          if (plVar10 == plVar4) {
            return 0;
          }
          iVar11 = 0;
          goto LAB_0010d7f0;
        }
        lVar7 = *(long *)(lVar7 + 0x38);
      } while (lVar7 != 0);
    }
    plVar4 = (long *)*plVar4;
  } while( true );
LAB_0010d7f0:
  if (*(char *)((long)plVar10 + -0xc) == '\0') {
LAB_0010d7d8:
    iVar2 = 0;
  }
  else {
    plVar8 = plVar10 + -3;
    if ((*(char *)((long)plVar10 + -0xc) == '\x02') && (*(char *)((long)plVar10 + -0xe) != '\0')) {
      iVar2 = drm_dp_mst_atomic_check_mstb_bw_limit(plVar10[2],param_2);
      if (0 < iVar2) {
        uVar1 = *(ushort *)((long)plVar10 + -6);
        goto LAB_0010d85c;
      }
    }
    else {
      plVar6 = plVar9;
      do {
        plVar6 = (long *)*plVar6;
        if (plVar6 == plVar9) goto LAB_0010d7d8;
      } while ((long *)plVar6[-3] != plVar8);
      if (plVar6 == (long *)0x18) goto LAB_0010d7d8;
      uVar1 = *(ushort *)((long)plVar10 + -6);
      if (uVar1 == 0) {
        if (*(long *)(plVar10[0xcc] + 0x68) == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined8 *)(*(long *)(plVar10[0xcc] + 0x68) + 8);
        }
        __drm_dev_dbg(0,uVar3,4,"[MSTB:%p] [MST PORT:%p] no BW available for the port\n",
                      plVar10[0xca],plVar8);
        return -0x16;
      }
      iVar2 = (int)plVar6[-1];
LAB_0010d85c:
      lVar7 = *(long *)(plVar10[0xcc] + 0x68);
      if ((int)(uint)uVar1 < iVar2) {
        if (lVar7 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(undefined8 *)(lVar7 + 8);
        }
        __drm_dev_dbg(0,uVar3,4,
                      "[MSTB:%p] [MST PORT:%p] required PBN of %d exceeds port limit of %d\n",
                      plVar10[0xca],plVar8,iVar2);
        return -0x1c;
      }
      if (lVar7 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(lVar7 + 8);
      }
      __drm_dev_dbg(0,uVar3,4,"[MSTB:%p] [MST PORT:%p] uses %d out of %d PBN\n",plVar10[0xca],plVar8
                    ,iVar2);
    }
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  iVar11 = iVar2 + iVar11;
  plVar10 = (long *)*plVar10;
  if (plVar10 == plVar4) {
    return iVar11;
  }
  goto LAB_0010d7f0;
}



//------------------------------------------------------------
// drm_dp_mst_duplicate_state @ 0010d93c size=420
// signature: undefined drm_dp_mst_duplicate_state(void)
// callers: []
//------------------------------------------------------------

long drm_dp_mst_duplicate_state(long param_1)

{
  long *plVar1;
  uint *puVar2;
  long *plVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  long *plVar14;
  
  lVar12 = *(long *)(param_1 + 0x58);
  lVar7 = kmemdup(lVar12,0x50,0xcc0);
  if (lVar7 != 0) {
    __drm_atomic_helper_private_obj_duplicate_state(param_1,lVar7);
    plVar1 = (long *)(lVar7 + 0x38);
    *(long **)(lVar7 + 0x38) = plVar1;
    *(long **)(lVar7 + 0x40) = plVar1;
    *(undefined4 *)(lVar7 + 0x18) = 0;
    *(undefined8 *)(lVar7 + 0x20) = 0;
    *(undefined8 *)(lVar7 + 0x28) = 0;
    plVar13 = (long *)(lVar12 + 0x38);
    for (plVar14 = (long *)*plVar13; plVar14 != plVar13; plVar14 = (long *)*plVar14) {
      if ((*(byte *)((long)plVar14 + -4) & 1) == 0) {
        plVar8 = (long *)kmemdup(plVar14 + -3,0x28,0xcc0);
        if (plVar8 == (long *)0x0) {
          plVar14 = (long *)*plVar1;
          while (plVar14 != plVar1) {
            plVar13 = (long *)*plVar14;
            drm_dp_mst_put_port_malloc(plVar14[-3]);
            kfree(plVar14 + -3);
            plVar14 = plVar13;
          }
          kfree(lVar7);
          return 0;
        }
        lVar12 = *plVar8;
        puVar2 = (uint *)(lVar12 + 4);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          uVar4 = *puVar2;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar6) {
            *puVar2 = uVar4 + 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (uVar4 == 0) {
          uVar10 = 2;
LAB_0010da84:
          refcount_warn_saturate(puVar2,uVar10);
        }
        else if ((int)(uVar4 + 1 | uVar4) < 0) {
          uVar10 = 1;
          goto LAB_0010da84;
        }
        lVar11 = *(long *)(*(long *)(lVar12 + 0x678) + 0x68);
        if (lVar11 == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = *(undefined8 *)(lVar11 + 8);
        }
        __drm_dev_dbg(0,uVar10,1,"port %p (%d)\n",lVar12,*(undefined4 *)(lVar12 + 4));
        lVar12 = *plVar1;
        plVar3 = plVar8 + 3;
        uVar9 = __list_add_valid(plVar3,plVar1,lVar12);
        if ((uVar9 & 1) != 0) {
          *(long **)(lVar12 + 8) = plVar3;
          plVar8[3] = lVar12;
          plVar8[4] = (long)plVar1;
          *plVar1 = (long)plVar3;
        }
      }
    }
  }
  return lVar7;
}



//------------------------------------------------------------
// drm_dp_mst_destroy_state @ 0010daec size=244
// signature: undefined drm_dp_mst_destroy_state(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_destroy_state(undefined8 param_1,long param_2)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  long *plVar6;
  ulong uVar7;
  undefined8 *puVar8;
  
  plVar6 = *(long **)(param_2 + 0x38);
  while (plVar6 != (long *)(param_2 + 0x38)) {
    pbVar1 = (byte *)((long)plVar6 + -4);
    puVar8 = plVar6 + -3;
    plVar6 = (long *)*plVar6;
    if ((*pbVar1 & 1) == 0) {
      drm_dp_mst_put_port_malloc(*puVar8);
    }
    kfree(puVar8);
  }
  if (*(long *)(param_2 + 0x28) != 0) {
    uVar7 = 0;
    do {
      piVar2 = (int *)(*(long *)(*(long *)(param_2 + 0x20) + uVar7 * 8) + 8);
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar3 = *piVar2;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar5) {
          *piVar2 = iVar3 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar3 == 1) {
        DataMemoryBarrier(2,1);
        __drm_crtc_commit_free();
      }
      else if (iVar3 < 1) {
        refcount_warn_saturate(piVar2,3);
      }
      uVar7 = (ulong)((int)uVar7 + 1);
    } while (uVar7 < *(ulong *)(param_2 + 0x28));
  }
  kfree(*(undefined8 *)(param_2 + 0x20));
  kfree(param_2);
  return;
}



//------------------------------------------------------------
// drm_atomic_get_old_mst_topology_state @ 0010dbf0 size=28
// signature: undefined drm_atomic_get_old_mst_topology_state(void)
// callers: []
//------------------------------------------------------------

void drm_atomic_get_old_mst_topology_state(void)

{
  drm_atomic_get_old_private_obj_state();
  return;
}



//------------------------------------------------------------
// drm_atomic_get_new_mst_topology_state @ 0010dc10 size=28
// signature: undefined drm_atomic_get_new_mst_topology_state(void)
// callers: []
//------------------------------------------------------------

void drm_atomic_get_new_mst_topology_state(void)

{
  drm_atomic_get_new_private_obj_state();
  return;
}



//------------------------------------------------------------
// drm_dp_mst_topology_mgr_init @ 0010dc30 size=512
// signature: undefined drm_dp_mst_topology_mgr_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
drm_dp_mst_topology_mgr_init
          (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined8 uVar1;
  long lVar2;
  
  __mutex_init(param_1 + 800,"&mgr->lock",&drm_dp_mst_topology_mgr_init___key);
  __mutex_init(param_1 + 0x3a8,"&mgr->qlock",&drm_dp_mst_topology_mgr_init___key_76);
  __mutex_init(param_1 + 0x480,"&mgr->delayed_destroy_lock",&drm_dp_mst_topology_mgr_init___key_78);
  __mutex_init(param_1 + 0x4f8,"&mgr->up_req_lock",&drm_dp_mst_topology_mgr_init___key_80);
  __mutex_init(param_1 + 0x350,"&mgr->probe_lock",&drm_dp_mst_topology_mgr_init___key_82);
  *(long *)(param_1 + 0x3d8) = param_1 + 0x3d8;
  *(long *)(param_1 + 0x3e0) = param_1 + 0x3d8;
  *(long *)(param_1 + 0x460) = param_1 + 0x460;
  *(long *)(param_1 + 0x468) = param_1 + 0x460;
  *(long *)(param_1 + 0x470) = param_1 + 0x470;
  *(long *)(param_1 + 0x478) = param_1 + 0x470;
  *(long *)(param_1 + 0x4e8) = param_1 + 0x4e8;
  *(long *)(param_1 + 0x4f0) = param_1 + 0x4e8;
  lVar2 = alloc_workqueue("drm_dp_mst_wq",0xa0002,1);
  *(long *)(param_1 + 0x4b0) = lVar2;
  if (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0x400) = 0xfffffffe0;
    *(long *)(param_1 + 0x408) = param_1 + 0x408;
    *(long *)(param_1 + 0x410) = param_1 + 0x408;
    *(code **)(param_1 + 0x418) = drm_dp_mst_link_probe_work;
    *(undefined8 *)(param_1 + 0x430) = 0xfffffffe0;
    *(long *)(param_1 + 0x438) = param_1 + 0x438;
    *(long *)(param_1 + 0x440) = param_1 + 0x438;
    *(code **)(param_1 + 0x448) = drm_dp_tx_work;
    *(undefined8 *)(param_1 + 0x4b8) = 0xfffffffe0;
    *(long *)(param_1 + 0x4c0) = param_1 + 0x4c0;
    *(long *)(param_1 + 0x4c8) = param_1 + 0x4c0;
    *(undefined8 *)(param_1 + 0x528) = 0xfffffffe0;
    *(code **)(param_1 + 0x4d0) = drm_dp_delayed_destroy_work;
    *(long *)(param_1 + 0x530) = param_1 + 0x530;
    *(long *)(param_1 + 0x538) = param_1 + 0x530;
    *(code **)(param_1 + 0x540) = drm_dp_mst_up_req_work;
    __init_waitqueue_head(param_1 + 1000,"&mgr->tx_waitq",&drm_dp_mst_topology_mgr_init___key_85);
    *(undefined8 *)(param_1 + 0x68) = param_2;
    *(undefined8 *)(param_1 + 0x80) = param_3;
    uVar1 = _drm_display_mode_from_cea_vic;
    *(undefined4 *)(param_1 + 0x78) = param_4;
    *(undefined4 *)(param_1 + 0x88) = param_5;
    *(undefined4 *)(param_1 + 0x8c) = param_6;
    lVar2 = kmalloc_trace(uVar1,0xdc0,0x50);
    if (lVar2 != 0) {
      *(long *)(lVar2 + 0x10) = param_1;
      *(undefined2 *)(lVar2 + 0x48) = 0x13f;
      *(long *)(lVar2 + 0x38) = lVar2 + 0x38;
      *(long *)(lVar2 + 0x40) = lVar2 + 0x38;
      drm_atomic_private_obj_init(param_2,param_1,lVar2,&drm_dp_mst_topology_state_funcs);
      return 0;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// drm_dp_mst_link_probe_work @ 0010de34 size=472
// signature: undefined drm_dp_mst_link_probe_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_mst_link_probe_work(long param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
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
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  lVar6 = param_1 + -0xb0;
  lVar5 = *(long *)(param_1 + -0x398);
  mutex_lock(lVar6);
  lVar8 = param_1 + -0xe0;
  mutex_lock(lVar8);
  bVar1 = *(byte *)(param_1 + -0x80);
  lVar7 = *(long *)(param_1 + -0x78);
  *(byte *)(param_1 + -0x80) = bVar1 | 2;
  if ((lVar7 == 0) || (iVar2 = drm_dp_mst_topology_try_get_mstb(lVar7), iVar2 == 0)) {
    mutex_unlock(lVar8);
    mutex_unlock(lVar6);
  }
  else {
    mutex_unlock(lVar8);
    if ((bVar1 >> 1 & 1) == 0) {
      if (lVar5 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(lVar5 + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"Clearing payload ID table\n");
      lVar8 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
      if (lVar8 != 0) {
        *(long *)(lVar8 + 0x138) = lVar7;
        local_68 = 0;
        uStack_60 = 0;
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
        uStack_c0 = 0;
        local_d0 = 0x14;
        drm_dp_encode_sideband_req(&local_d0,lVar8);
        *(undefined1 *)(lVar8 + 0x158) = 1;
        drm_dp_queue_down_tx(param_1 + -0x400,lVar8);
        iVar2 = drm_dp_mst_wait_tx_reply(lVar7,lVar8);
        if ((0 < iVar2) && (*(char *)(lVar8 + 0x15a) == '\x01')) {
          lVar4 = *(long *)(param_1 + -0x398);
          if (lVar4 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined8 *)(lVar4 + 8);
          }
          __drm_dev_dbg(0,uVar3,2,"clear payload table id nak received\n");
        }
        kfree(lVar8);
      }
    }
    iVar2 = drm_dp_check_and_send_link_address(param_1 + -0x400,lVar7);
    drm_dp_mst_topology_put_mstb(lVar7);
    mutex_unlock(lVar6);
    if (0 < iVar2) {
      drm_kms_helper_hotplug_event(lVar5);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_tx_work @ 0010e010 size=80
// signature: undefined drm_dp_tx_work(void)
// callers: []
//------------------------------------------------------------

void drm_dp_tx_work(long param_1)

{
  mutex_lock(param_1 + -0x88);
  if (*(long **)(param_1 + -0x58) != (long *)(param_1 + -0x58)) {
    process_single_down_tx_qlock(param_1 + -0x430);
  }
  mutex_unlock(param_1 + -0x88);
  return;
}



//------------------------------------------------------------
// drm_dp_delayed_destroy_work @ 0010e064 size=960
// signature: undefined drm_dp_delayed_destroy_work(void)
// callers: []
//------------------------------------------------------------

void drm_dp_delayed_destroy_work(long param_1)

{
  bool bVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  ulong uVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  bool bVar13;
  long *plVar14;
  long *plVar15;
  long *plVar16;
  int *piVar17;
  bool bVar18;
  long lVar19;
  
  lVar10 = param_1 + -0x38;
  plVar9 = (long *)(param_1 + -0x48);
  plVar14 = (long *)(param_1 + -0x58);
  bVar6 = false;
  do {
    mutex_lock(lVar10);
    plVar12 = (long *)*plVar9;
    plVar15 = plVar12 + -1;
    bVar1 = plVar12 != plVar9 && plVar15 != (long *)0x0;
    if (plVar12 != plVar9 && plVar15 != (long *)0x0) {
      bVar13 = bVar1;
      do {
        uVar7 = __list_del_entry_valid(plVar12);
        if ((uVar7 & 1) != 0) {
          lVar19 = *plVar12;
          plVar16 = (long *)plVar12[1];
          *(long **)(lVar19 + 8) = plVar16;
          *plVar16 = lVar19;
        }
        *plVar12 = -0x2152ffffffffff00;
        plVar12[1] = -0x2152fffffffffede;
        mutex_unlock(lVar10);
        lVar19 = plVar12[7];
        mutex_lock(lVar19 + 800);
        plVar16 = (long *)plVar12[4];
        while (plVar16 != plVar12 + 4) {
          plVar11 = (long *)*plVar16;
          uVar7 = __list_del_entry_valid(plVar16);
          if ((uVar7 & 1) != 0) {
            lVar2 = *plVar16;
            plVar3 = (long *)plVar16[1];
            *(long **)(lVar2 + 8) = plVar3;
            *plVar3 = lVar2;
          }
          *plVar16 = -0x2152ffffffffff00;
          plVar16[1] = -0x2152fffffffffede;
          drm_dp_mst_topology_put_port(plVar16 + -3);
          plVar16 = plVar11;
        }
        mutex_unlock(lVar19 + 800);
        mutex_lock(plVar12[7] + 0x3a8);
        if (*(long **)(lVar19 + 0x3d8) == (long *)(lVar19 + 0x3d8)) {
          mutex_unlock(plVar12[7] + 0x3a8);
        }
        else {
          bVar18 = false;
          plVar16 = *(long **)(lVar19 + 0x3d8);
          do {
            plVar11 = (long *)*plVar16;
            if ((long *)plVar16[-1] == plVar15) {
              *(undefined4 *)((long)plVar16 + 0x14) = 4;
              uVar7 = __list_del_entry_valid(plVar16);
              if ((uVar7 & 1) != 0) {
                lVar2 = *plVar16;
                plVar3 = (long *)plVar16[1];
                *(long **)(lVar2 + 8) = plVar3;
                *plVar3 = lVar2;
              }
              bVar18 = true;
              *plVar16 = -0x2152ffffffffff00;
              plVar16[1] = -0x2152fffffffffede;
            }
            plVar16 = plVar11;
          } while (plVar11 != (long *)(lVar19 + 0x3d8));
          mutex_unlock(plVar12[7] + 0x3a8);
          if (bVar18) {
            __wake_up(plVar12[7] + 1000,3,0,0);
          }
        }
        if (*(long *)(plVar12[7] + 0x68) == 0) {
          uVar8 = 0;
        }
        else {
          uVar8 = *(undefined8 *)(*(long *)(plVar12[7] + 0x68) + 8);
        }
        piVar17 = (int *)((long)plVar12 + -4);
        __drm_dev_dbg(0,uVar8,1,"mstb %p (%d)\n",plVar15,*piVar17 + -1);
        Hint_Prefetch(piVar17,2,0,1);
        do {
          iVar4 = *piVar17;
          cVar5 = '\x01';
          bVar18 = (bool)ExclusiveMonitorPass(piVar17,0x10);
          if (bVar18) {
            *piVar17 = iVar4 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (iVar4 == 1) {
          DataMemoryBarrier(2,1);
          if (plVar12[6] != 0) {
            drm_dp_mst_put_port_malloc();
          }
          kfree(plVar15);
        }
        else if (iVar4 < 1) {
          refcount_warn_saturate(piVar17,3);
        }
        if (!bVar13) {
          bVar1 = true;
          goto LAB_0010e310;
        }
        mutex_lock(lVar10);
        plVar12 = (long *)*plVar9;
        plVar15 = plVar12 + -1;
        bVar13 = plVar12 != plVar9 && plVar15 != (long *)0x0;
      } while (plVar12 != plVar9 && plVar15 != (long *)0x0);
    }
    mutex_unlock(lVar10);
LAB_0010e310:
    mutex_lock(lVar10);
    plVar12 = (long *)*plVar14;
    if ((plVar12 == plVar14) || (plVar15 = plVar12 + -3, plVar15 == (long *)0x0)) {
      mutex_unlock(lVar10);
      if (!bVar1) {
        if (bVar6) {
          drm_kms_helper_hotplug_event(*(undefined8 *)(param_1 + -0x450));
        }
        return;
      }
    }
    else {
      do {
        uVar7 = __list_del_entry_valid(plVar12);
        if ((uVar7 & 1) != 0) {
          lVar19 = *plVar12;
          plVar16 = (long *)plVar12[1];
          *(long **)(lVar19 + 8) = plVar16;
          *plVar16 = lVar19;
        }
        *plVar12 = -0x2152ffffffffff00;
        plVar12[1] = -0x2152fffffffffede;
        mutex_unlock(lVar10);
        if (*(char *)((long)plVar12 + -0xc) != '\0') {
          cVar5 = *(char *)((long)plVar12 + -0xe);
          if ((cVar5 == '\0') || (*(char *)((long)plVar12 + -0xc) != '\x02')) {
            i2c_del_adapter(plVar12 + 4);
          }
          else {
            lVar19 = plVar12[0xcc];
            mutex_lock(lVar19 + 800);
            drm_dp_mst_topology_put_mstb(plVar12[2]);
            plVar12[2] = 0;
            mutex_unlock(lVar19 + 800);
          }
          *(undefined1 *)((long)plVar12 + -0xc) = 0;
          *(char *)((long)plVar12 + -0xe) = cVar5;
        }
        if (plVar12[0xcb] != 0) {
          drm_connector_unregister();
          drm_mode_object_put(plVar12[0xcb] + 0x40);
        }
        drm_dp_mst_put_port_malloc(plVar15);
        mutex_lock(lVar10);
        plVar12 = (long *)*plVar14;
      } while ((plVar12 != plVar14) && (plVar15 = plVar12 + -3, plVar15 != (long *)0x0));
      mutex_unlock(lVar10);
      bVar6 = true;
    }
  } while( true );
}



//------------------------------------------------------------
// drm_dp_mst_up_req_work @ 0010e438 size=1192
// signature: undefined drm_dp_mst_up_req_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void drm_dp_mst_up_req_work(long param_1)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  byte bVar10;
  char cVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long *plVar19;
  long *plVar20;
  long *plVar21;
  long *plVar22;
  bool bVar23;
  long lVar24;
  
  lVar17 = param_1 + -0x1d8;
  mutex_lock(lVar17);
  lVar16 = param_1 + -0x30;
  mutex_lock(lVar16);
  plVar20 = (long *)(param_1 + -0x40);
  plVar22 = (long *)*plVar20;
  if ((plVar22 == plVar20) || (plVar19 = plVar22 + -0x11, plVar19 == (long *)0x0)) {
    mutex_unlock(lVar16);
    mutex_unlock(lVar17);
  }
  else {
    plVar12 = (long *)(param_1 + -0x1a0);
    bVar23 = false;
    lVar18 = param_1 + -0x208;
    plVar13 = (long *)(param_1 + -0x4c0);
    do {
      uVar6 = __list_del_entry_valid(plVar22);
      if ((uVar6 & 1) != 0) {
        lVar24 = *plVar22;
        plVar21 = (long *)plVar22[1];
        *(long **)(lVar24 + 8) = plVar21;
        *plVar21 = lVar24;
      }
      *plVar22 = -0x2152ffffffffff00;
      plVar22[1] = -0x2152fffffffffede;
      mutex_unlock(lVar16);
      if (*(char *)((long)plVar22 + -0x7e) == '\0') {
        lVar24 = drm_dp_get_mst_branch_device(param_1 + -0x528,(char)*plVar19,(long)plVar22 + -0x86)
        ;
        if (lVar24 == 0) goto LAB_0010e62c;
LAB_0010e580:
        if ((char)plVar22[-0xf] != '\x02') {
LAB_0010e694:
          drm_dp_mst_topology_put_mstb(lVar24);
          goto LAB_0010e69c;
        }
        mutex_lock(lVar18);
        if ((*plVar12 == 0) || (iVar5 = drm_dp_mst_topology_try_get_mstb(), iVar5 == 0)) {
          mutex_unlock(lVar18);
LAB_0010e668:
          if (*plVar13 == 0) {
            uVar9 = 0;
          }
          else {
            uVar9 = *(undefined8 *)(*plVar13 + 8);
          }
          __drm_dev_dbg(0,uVar9,2,"Got CSN before finish topology probing. Skip it.\n");
          goto LAB_0010e694;
        }
        cVar11 = *(char *)(*plVar12 + 0x48);
        drm_dp_mst_topology_put_mstb();
        mutex_unlock(lVar18);
        if (cVar11 == '\0') goto LAB_0010e668;
        lVar7 = *(long *)(lVar24 + 0x40);
        plVar21 = (long *)(lVar24 + 0x28);
        do {
          plVar21 = (long *)*plVar21;
          if (plVar21 == (long *)(lVar24 + 0x28)) goto LAB_0010e6cc;
        } while ((char)plVar21[-2] != (char)plVar22[-0xc]);
        plVar15 = plVar21 + -3;
        iVar5 = drm_dp_mst_topology_try_get_port(plVar15);
        if ((plVar15 == (long *)0x0) || (iVar5 == 0)) {
LAB_0010e6cc:
          drm_dp_mst_topology_put_mstb(lVar24);
          bVar10 = 1;
        }
        else {
          if (plVar21[0xcb] == 0) {
            if ((*(char *)((long)plVar21 + -0xf) == '\0') ||
               (*(char *)((long)plVar22 + -0x5c) != '\0')) {
              bVar3 = false;
            }
            else {
              *(undefined1 *)(lVar24 + 0x48) = 0;
              bVar3 = true;
            }
LAB_0010e774:
            cVar11 = *(char *)((long)plVar22 + -0x5c);
            cVar1 = *(char *)((long)plVar21 + -0xd);
            *(char *)((long)plVar21 + -0xf) = cVar11;
            *(undefined1 *)((long)plVar21 + -0xb) = *(undefined1 *)((long)plVar22 + -0x5f);
            cVar2 = *(char *)((long)plVar22 + -0x5e);
            *(char *)((long)plVar21 + -0xd) = cVar2;
            if (cVar1 == cVar2) {
LAB_0010e7b4:
              if (cVar11 != '\0') goto LAB_0010e7b8;
LAB_0010e7c8:
              uVar8 = *(undefined1 *)((long)plVar22 + -0x5b);
            }
            else {
              if ((cVar11 == '\0') && (cVar2 != '\0')) {
                drm_dp_send_enum_path_resources(lVar7,lVar24,plVar15);
                cVar11 = *(char *)((long)plVar21 + -0xf);
                goto LAB_0010e7b4;
              }
              *(undefined2 *)((long)plVar21 + -6) = 0;
              if (cVar11 == '\0') goto LAB_0010e7c8;
LAB_0010e7b8:
              uVar8 = 0;
            }
            iVar5 = drm_dp_port_set_pdt(plVar15,uVar8,*(undefined1 *)((long)plVar22 + -0x5d));
            if (iVar5 == 1) {
              bVar4 = true;
              lVar14 = plVar21[0xcb];
joined_r0x0010e880:
              if (lVar14 == 0) goto LAB_0010e7ec;
LAB_0010e81c:
              drm_modeset_unlock(lVar7 + 0x10);
            }
            else {
              if (iVar5 < 0) {
                _dev_err(*(undefined8 *)(*(long *)(lVar7 + 0x68) + 8),
                         "[drm] *ERROR* Failed to change PDT for port %p: %d\n",plVar15,iVar5);
                bVar4 = false;
                lVar14 = plVar21[0xcb];
                goto joined_r0x0010e880;
              }
              bVar4 = bVar3;
              if (plVar21[0xcb] != 0) goto LAB_0010e81c;
LAB_0010e7ec:
              if (bVar3) {
                drm_dp_mst_port_add_connector(lVar24,plVar15);
              }
            }
            drm_dp_mst_topology_put_port(plVar15);
            drm_dp_mst_topology_put_mstb(lVar24);
            if (bVar4) goto LAB_0010e840;
          }
          else {
            if ((*(char *)((long)plVar21 + -0xf) != '\0') ||
               (*(char *)((long)plVar22 + -0x5c) == '\0')) {
              drm_modeset_lock(lVar7 + 0x10,0);
              bVar3 = false;
              goto LAB_0010e774;
            }
            mutex_lock(lVar7 + 800);
            *(int *)(plVar21[0xca] + 0x24) = *(int *)(plVar21[0xca] + 0x24) + -1;
            uVar6 = __list_del_entry_valid(plVar21);
            if ((uVar6 & 1) != 0) {
              lVar14 = *plVar21;
              plVar22 = (long *)plVar21[1];
              *(long **)(lVar14 + 8) = plVar22;
              *plVar22 = lVar14;
            }
            *plVar21 = -0x2152ffffffffff00;
            plVar21[1] = -0x2152fffffffffede;
            mutex_unlock(lVar7 + 800);
            drm_dp_mst_topology_put_port(plVar15);
            *(undefined1 *)(lVar24 + 0x48) = 0;
            drm_dp_mst_topology_put_port(plVar15);
            drm_dp_mst_topology_put_mstb(lVar24);
LAB_0010e840:
            queue_work_on(0x20,_system_long_wq,param_1 + -0x128);
          }
          bVar10 = 1;
        }
      }
      else {
        if ((char)plVar22[-0xf] == '\x02') {
          plVar21 = plVar22 + -0xe;
        }
        else {
          if ((char)plVar22[-0xf] != '\x13') goto LAB_0010e62c;
          plVar21 = (long *)((long)plVar22 + -0x6f);
        }
        if (plVar21 != (long *)0x0) {
          mutex_lock(lVar18);
          lVar7 = get_mst_branch_device_by_guid_helper(*plVar12,plVar21);
          if (lVar7 == 0) {
            lVar24 = 0;
          }
          else {
            iVar5 = drm_dp_mst_topology_try_get_mstb();
            lVar24 = 0;
            if (iVar5 != 0) {
              lVar24 = lVar7;
            }
          }
          mutex_unlock(lVar18);
          if (lVar24 != 0) goto LAB_0010e580;
        }
LAB_0010e62c:
        if (*plVar13 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = *(undefined8 *)(*plVar13 + 8);
        }
        __drm_dev_dbg(0,uVar9,2,"Got MST reply from unknown device %d\n",(char)*plVar19);
LAB_0010e69c:
        bVar10 = 0;
      }
      bVar23 = (bool)(bVar23 | bVar10);
      kfree(plVar19);
      mutex_lock(lVar16);
      plVar22 = (long *)*plVar20;
    } while ((plVar22 != plVar20) && (plVar19 = plVar22 + -0x11, plVar19 != (long *)0x0));
    mutex_unlock(lVar16);
    mutex_unlock(lVar17);
    if (bVar23) {
      drm_kms_helper_hotplug_event(*plVar13);
    }
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_topology_mgr_destroy @ 0010e8e4 size=88
// signature: undefined drm_dp_mst_topology_mgr_destroy(void)
// callers: []
//------------------------------------------------------------

void drm_dp_mst_topology_mgr_destroy(long param_1)

{
  drm_dp_mst_topology_mgr_set_mst(param_1,0);
  flush_work(param_1 + 0x400);
  if (*(long *)(param_1 + 0x4b0) != 0) {
    destroy_workqueue();
    *(undefined8 *)(param_1 + 0x4b0) = 0;
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  drm_atomic_private_obj_fini(param_1);
  *(undefined8 *)(param_1 + 0x3a0) = 0;
  return;
}



//------------------------------------------------------------
// drm_dp_mst_is_virtual_dpcd @ 0010e93c size=224
// signature: undefined drm_dp_mst_is_virtual_dpcd(void)
// callers: [drm_dp_mst_dsc_aux_for_port]
//------------------------------------------------------------

undefined8 drm_dp_mst_is_virtual_dpcd(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if ((param_1 == 0) || (*(byte *)(param_1 + 0xe) < 0x14)) {
    uVar3 = 0;
  }
  else if ((*(byte *)(param_1 + 8) < 8) &&
          (((*(char *)(param_1 + 0xc) != '\x04' || (*(char *)(param_1 + 10) != '\0')) ||
           (*(char *)(param_1 + 0xd) == '\0')))) {
    mutex_lock(*(long *)(param_1 + 0x678) + 800);
    if (((*(char *)(param_1 + 0xc) == '\x02') && (lVar1 = *(long *)(param_1 + 0x28), lVar1 != 0)) &&
       (*(int *)(lVar1 + 0x24) == 2)) {
      for (puVar2 = *(undefined8 **)(lVar1 + 0x28); puVar2 != (undefined8 *)(lVar1 + 0x28);
          puVar2 = (undefined8 *)*puVar2) {
        if ((*(char *)((long)puVar2 + -0xc) == '\x03') && (*(char *)((long)puVar2 + -0xf) == '\0'))
        {
          uVar3 = 1;
          goto LAB_0010e9f0;
        }
      }
    }
    uVar3 = 0;
LAB_0010e9f0:
    mutex_unlock(*(long *)(param_1 + 0x678) + 800);
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



//------------------------------------------------------------
// drm_dp_free_mst_branch_device @ 0010ea20 size=56
// signature: undefined drm_dp_free_mst_branch_device(void)
// callers: []
//------------------------------------------------------------

void drm_dp_free_mst_branch_device(long param_1)

{
  if (*(long *)(param_1 + 0x34) != 0) {
    drm_dp_mst_put_port_malloc();
  }
  kfree(param_1 + -4);
  return;
}



//------------------------------------------------------------
// drm_dp_mst_topology_get_port_validated_locked @ 0010ea58 size=124
// signature: undefined drm_dp_mst_topology_get_port_validated_locked(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_mst_detect_port, drm_dp_add_payload_part2, drm_dp_mst_topology_get_port_validated_locked, drm_dp_mst_get_edid, drm_dp_send_power_updown_phy, drm_dp_add_payload_part1]
//------------------------------------------------------------

long drm_dp_mst_topology_get_port_validated_locked(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x28);
  while( true ) {
    if (plVar2 == (long *)(param_1 + 0x28)) {
      return 0;
    }
    if (plVar2 + -3 == (long *)param_2) break;
    if ((plVar2[2] != 0) &&
       (lVar1 = drm_dp_mst_topology_get_port_validated_locked(plVar2[2],param_2), lVar1 != 0)) {
      return lVar1;
    }
    plVar2 = (long *)*plVar2;
  }
  return param_2;
}



//------------------------------------------------------------
// drm_dp_mst_topology_try_get_port @ 0010ead4 size=212
// signature: undefined drm_dp_mst_topology_try_get_port(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_mst_detect_port, drm_dp_add_payload_part2, drm_dp_mst_get_edid, drm_dp_send_link_address, drm_dp_mst_up_req_work, drm_dp_send_power_updown_phy, drm_dp_add_payload_part1]
//------------------------------------------------------------

bool drm_dp_mst_topology_try_get_port(uint *param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *param_1;
  if (*param_1 == 0) {
    uVar6 = 0;
  }
  else {
    do {
      Hint_Prefetch(param_1,2,0,1);
      do {
        uVar1 = *param_1;
        if (uVar1 != uVar5) break;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
        if (bVar3) {
          *param_1 = uVar5 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      uVar6 = uVar5;
    } while ((uVar5 != uVar1) && (uVar6 = 0, uVar5 = uVar1, uVar1 != 0));
  }
  if ((int)(uVar6 + 1 | uVar6) < 0) {
    refcount_warn_saturate(param_1,0);
  }
  if (uVar6 != 0) {
    if (*(long *)(*(long *)(param_1 + 0x19e) + 0x68) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x19e) + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar4,1,"port %p (%d)\n",param_1,*param_1);
  }
  return uVar6 != 0;
}



//------------------------------------------------------------
// drm_dp_mst_dump_sideband_msg_tx @ 0010ebbc size=556
// signature: undefined drm_dp_mst_dump_sideband_msg_tx(void)
// callers: [drm_dp_mst_wait_tx_reply, process_single_tx_qlock, drm_dp_queue_down_tx]
//------------------------------------------------------------

void drm_dp_mst_dump_sideband_msg_tx(undefined8 param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  long lVar9;
  byte bVar10;
  char local_f0 [64];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_f0[0x38] = '\0';
  local_f0[0x39] = '\0';
  local_f0[0x3a] = '\0';
  local_f0[0x3b] = '\0';
  local_f0[0x3c] = '\0';
  local_f0[0x3d] = '\0';
  local_f0[0x3e] = '\0';
  local_f0[0x3f] = '\0';
  local_b0 = 0;
  local_f0[0x28] = '\0';
  local_f0[0x29] = '\0';
  local_f0[0x2a] = '\0';
  local_f0[0x2b] = '\0';
  local_f0[0x2c] = '\0';
  local_f0[0x2d] = '\0';
  local_f0[0x2e] = '\0';
  local_f0[0x2f] = '\0';
  local_f0[0x30] = '\0';
  local_f0[0x31] = '\0';
  local_f0[0x32] = '\0';
  local_f0[0x33] = '\0';
  local_f0[0x34] = '\0';
  local_f0[0x35] = '\0';
  local_f0[0x36] = '\0';
  local_f0[0x37] = '\0';
  local_f0[0x18] = '\0';
  local_f0[0x19] = '\0';
  local_f0[0x1a] = '\0';
  local_f0[0x1b] = '\0';
  local_f0[0x1c] = '\0';
  local_f0[0x1d] = '\0';
  local_f0[0x1e] = '\0';
  local_f0[0x1f] = '\0';
  local_f0[0x20] = '\0';
  local_f0[0x21] = '\0';
  local_f0[0x22] = '\0';
  local_f0[0x23] = '\0';
  local_f0[0x24] = '\0';
  local_f0[0x25] = '\0';
  local_f0[0x26] = '\0';
  local_f0[0x27] = '\0';
  bVar3 = *(byte *)(*(long *)(param_2 + 0x138) + 0x20);
  local_a8 = 0;
  local_a0 = 0;
  local_f0[8] = '\0';
  local_f0[9] = '\0';
  local_f0[10] = '\0';
  local_f0[0xb] = '\0';
  local_f0[0xc] = '\0';
  local_f0[0xd] = '\0';
  local_f0[0xe] = '\0';
  local_f0[0xf] = '\0';
  local_f0[0x10] = '\0';
  local_f0[0x11] = '\0';
  local_f0[0x12] = '\0';
  local_f0[0x13] = '\0';
  local_f0[0x14] = '\0';
  local_f0[0x15] = '\0';
  local_f0[0x16] = '\0';
  local_f0[0x17] = '\0';
  local_f0[0] = '\0';
  local_f0[1] = '\0';
  local_f0[2] = '\0';
  local_f0[3] = '\0';
  local_f0[4] = '\0';
  local_f0[5] = '\0';
  local_f0[6] = '\0';
  local_f0[7] = '\0';
  local_38 = 0;
  uStack_30 = 0;
  if (1 < (ulong)bVar3) {
    lVar9 = 0;
    lVar1 = *(long *)(param_2 + 0x138) + 0x18;
    do {
      uVar2 = lVar9 + 1;
      if ((uVar2 & 1) == 0) {
        if (0xf < uVar2) goto LAB_0010eda8;
        uVar4 = (int)uVar2 - 1;
        bVar10 = *(byte *)(lVar1 + ((ulong)((uint)(int)(char)((char)uVar4 +
                                                             (char)((uVar4 & 0x80) >> 7)) >> 1) &
                                   0xff)) & 0xf;
      }
      else {
        if (0xf < uVar2) goto LAB_0010eda8;
        bVar10 = *(byte *)(lVar1 + ((ulong)((int)lVar9 + 0x100U >> 1) & 0x7f)) >> 4;
      }
      *(byte *)(((ulong)&local_38 | 1) + lVar9) = bVar10;
      lVar9 = lVar9 + 1;
    } while ((ulong)bVar3 - 1 != lVar9);
  }
  snprintf(local_f0,0x40,"%*phC",(uint)bVar3,&local_38);
  if (*(uint *)(param_2 + 0x154) < 5) {
    pcVar8 = (&drm_dp_mst_sideband_tx_state_str_sideband_reason_str)[*(uint *)(param_2 + 0x154)];
  }
  else {
    pcVar8 = "unknown";
  }
  drm_printf(param_1,"txmsg cur_offset=%x cur_len=%x seqno=%x state=%s path_msg=%d dst=%s\n",
             *(undefined1 *)(param_2 + 0x130),*(undefined1 *)(param_2 + 0x131),
             *(undefined4 *)(param_2 + 0x150),pcVar8,*(undefined1 *)(param_2 + 0x158),local_f0);
  iVar6 = drm_dp_decode_sideband_req(param_2,&local_b0);
  if (iVar6 == 0) {
    drm_dp_dump_sideband_msg_req_body(&local_b0,1,param_1);
    if ((char)local_b0 == '!') {
      uVar7 = local_98;
    }
    else {
      if ((char)local_b0 != '#') {
        if (((char)local_b0 == '\"') && ((byte)local_a8 != '\0')) {
          kfree(local_98);
          if (1 < (byte)local_a8) {
            kfree(local_80);
            if (2 < (byte)local_a8) {
              kfree(local_68);
              if ((3 < (byte)local_a8) && (kfree(local_50), 4 < (byte)local_a8)) {
LAB_0010eda8:
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10edac);
                (*pcVar5)();
              }
            }
          }
        }
        goto LAB_0010edbc;
      }
      uVar7 = local_a0;
    }
    kfree(uVar7);
  }
  else {
    drm_printf(param_1,"<failed to decode sideband req: %d>\n",iVar6);
  }
LAB_0010edbc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// process_single_down_tx_qlock @ 0010ede8 size=204
// signature: undefined process_single_down_tx_qlock(void)
// callers: [drm_dp_tx_work, drm_dp_queue_down_tx]
//------------------------------------------------------------

void process_single_down_tx_qlock(long param_1)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  
  uVar5 = mutex_is_locked(param_1 + 0x3a8);
  if ((uVar5 & 1) == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10eeb4);
    (*pcVar3)();
  }
  plVar7 = *(long **)(param_1 + 0x3d8);
  if ((plVar7 != (long *)(param_1 + 0x3d8)) &&
     (iVar4 = process_single_tx_qlock(param_1,plVar7 + -0x28,0), iVar4 < 0)) {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar6,2,"failed to send msg in q %d\n",iVar4);
    uVar5 = __list_del_entry_valid(plVar7);
    if ((uVar5 & 1) != 0) {
      lVar1 = *plVar7;
      plVar2 = (long *)plVar7[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *(undefined4 *)((long)plVar7 + 0x14) = 4;
    *plVar7 = -0x2152ffffffffff00;
    plVar7[1] = -0x2152fffffffffede;
    __wake_up(param_1 + 1000,3,0,0);
  }
  return;
}



//------------------------------------------------------------
// process_single_tx_qlock @ 0010eeb8 size=1260
// signature: undefined process_single_tx_qlock(void)
// callers: [process_single_down_tx_qlock, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

void process_single_tx_qlock(long param_1,byte *param_2,ulong param_3)

{
  uint uVar1;
  byte *__dest;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  code *pcVar6;
  bool bVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  undefined8 uVar11;
  uint uVar12;
  ulong uVar13;
  int iVar14;
  uint uVar15;
  long lVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  char *pcStack_b0;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined1 local_a5;
  undefined1 local_a4;
  undefined1 local_a3;
  undefined1 local_a2;
  undefined1 uStack_a1;
  char cStack_a0;
  byte bStack_9f;
  undefined1 uStack_9e;
  char cStack_9d;
  char cStack_9c;
  char cStack_9b;
  byte local_98 [48];
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  local_98[0x20] = 0;
  local_98[0x21] = 0;
  local_98[0x22] = 0;
  local_98[0x23] = 0;
  local_98[0x24] = 0;
  local_98[0x25] = 0;
  local_98[0x26] = 0;
  local_98[0x27] = 0;
  local_98[0x28] = 0;
  local_98[0x29] = 0;
  local_98[0x2a] = 0;
  local_98[0x2b] = 0;
  local_98[0x2c] = 0;
  local_98[0x2d] = 0;
  local_98[0x2e] = 0;
  local_98[0x2f] = 0;
  local_98[0x10] = 0;
  local_98[0x11] = 0;
  local_98[0x12] = 0;
  local_98[0x13] = 0;
  local_98[0x14] = 0;
  local_98[0x15] = 0;
  local_98[0x16] = 0;
  local_98[0x17] = 0;
  local_98[0x18] = 0;
  local_98[0x19] = 0;
  local_98[0x1a] = 0;
  local_98[0x1b] = 0;
  local_98[0x1c] = 0;
  local_98[0x1d] = 0;
  local_98[0x1e] = 0;
  local_98[0x1f] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  local_98[8] = 0;
  local_98[9] = 0;
  local_98[10] = 0;
  local_98[0xb] = 0;
  local_98[0xc] = 0;
  local_98[0xd] = 0;
  local_98[0xe] = 0;
  local_98[0xf] = 0;
  if (*(int *)(param_2 + 0x154) == 2) {
LAB_0010f2bc:
    uVar11 = 0;
  }
  else {
    uStack_9e = 0;
    cStack_9d = '\0';
    cStack_9c = '\0';
    cStack_9b = '\0';
    local_a8 = 0;
    local_a7 = 0;
    local_a6 = 0;
    local_a5 = 0;
    local_a4 = 0;
    local_a3 = 0;
    local_a2 = 0;
    uStack_a1 = 0;
    if (*(int *)(param_2 + 0x154) == 0) {
      param_2[0x154] = 1;
      param_2[0x155] = 0;
      param_2[0x156] = 0;
      param_2[0x157] = 0;
    }
    bVar8 = 6;
    cStack_a0 = '\x01';
    if ((*param_2 & 0x7f) == 2) {
      uVar18 = 1;
    }
    else {
      uVar18 = 1;
      if ((*param_2 & 0x7f) - 0x15 < 0xfffffffe) {
        bVar8 = *(byte *)(*(long *)(param_2 + 0x138) + 0x20);
        uVar18 = (uint)bVar8;
        cStack_a0 = '\0';
        bVar8 = bVar8 - 1;
      }
    }
    bStack_9f = param_2[0x158];
    if (0x1d < uVar18) {
      fortify_panic("memcpy");
LAB_0010f3a4:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10f3a8);
      (*pcVar6)();
    }
    uVar9 = uVar18 >> 1;
    if ((0x11 < uVar18) && ((set_hdr_from_dst_qlock___already_done & 1) == 0)) {
      set_hdr_from_dst_qlock___already_done = 1;
      __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                    (ulong)uVar9,
                    "field \"hdr->rad\" at drivers/gpu/drm/display/drm_dp_mst_topology.c:2777",8);
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10f38c);
      (*pcVar6)();
    }
    memcpy(&local_a8,(void *)(*(long *)(param_2 + 0x138) + 0x18),(ulong)uVar9);
    uVar11 = local_98._0_8_;
    uVar9 = 0x2c - uVar9;
    uVar15 = (uint)param_2[0x131] - (uint)param_2[0x130];
    uVar3 = uVar15;
    if ((int)uVar9 <= (int)uVar15) {
      uVar3 = uVar9;
    }
    if (param_2[0x130] == 0) {
      cStack_9d = '\x01';
    }
    if ((int)uVar15 <= (int)uVar9) {
      cStack_9c = '\x01';
    }
    bVar8 = bVar8 & 0xf | (byte)(uVar18 << 4);
    local_98[0] = bVar8;
    if (uVar18 < 2) {
      lVar16 = 1;
    }
    else {
      local_98._2_6_ = SUB86(uVar11,2);
      local_98[1] = local_a8;
      if (uVar18 < 4) {
        lVar16 = 2;
      }
      else {
        local_98._3_5_ = SUB85(uVar11,3);
        local_98[2] = local_a7;
        if (uVar18 < 6) {
          lVar16 = 3;
        }
        else {
          local_98._4_4_ = SUB84(uVar11,4);
          local_98[3] = local_a6;
          if (uVar18 < 8) {
            lVar16 = 4;
          }
          else {
            local_98._5_3_ = SUB83(uVar11,5);
            local_98[4] = local_a5;
            if (uVar18 < 10) {
              lVar16 = 5;
            }
            else {
              local_98._6_2_ = SUB82(uVar11,6);
              local_98[5] = local_a4;
              if (uVar18 < 0xc) {
                lVar16 = 6;
              }
              else {
                local_98[7] = SUB81(uVar11,7);
                local_98[6] = local_a3;
                if (uVar18 < 0xe) {
                  lVar16 = 7;
                }
                else {
                  local_98[7] = local_a2;
                  if (uVar18 < 0x10) {
                    lVar16 = 8;
                  }
                  else {
                    local_98[8] = uStack_a1;
                    if (0x11 < uVar18) goto LAB_0010f3a4;
                    lVar16 = 9;
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar15 = 0;
    bVar8 = 0;
    bVar5 = cStack_9c << 6 | cStack_9d << 7 | cStack_9b << 4;
    uVar18 = (int)lVar16 + 2;
    iVar14 = (int)lVar16 * -8 + -0xc;
    uVar12 = 7;
    uVar9 = 0x80;
    local_98[lVar16] = (byte)(uVar3 + 1) & 0x3f | cStack_a0 << 7 | bStack_9f << 6;
    local_98[lVar16 + 1] = bVar5;
    do {
      if (0x2f < bVar8) goto LAB_0010f390;
      uVar2 = uVar9 & local_98[bVar8];
      uVar1 = uVar9 >> 1;
      uVar9 = 0x80;
      if (uVar1 != 0) {
        uVar9 = uVar1;
      }
      uVar15 = uVar2 >> (ulong)(uVar12 & 0x1f) | uVar15 << 1;
      uVar12 = uVar12 - 1;
      if (uVar1 == 0) {
        bVar8 = bVar8 + 1;
        uVar12 = 7;
      }
      if ((uVar15 & 0x10) != 0) {
        uVar15 = uVar15 ^ 0x13;
      }
      bVar7 = iVar14 != -1;
      iVar14 = iVar14 + 1;
    } while (bVar7);
    uVar9 = uVar15 << 1;
    if ((uVar15 & 8) != 0) {
      uVar9 = uVar15 << 1 ^ 0x13;
    }
    __dest = local_98 + uVar18;
    uVar15 = uVar9 << 1;
    if ((uVar9 & 8) != 0) {
      uVar15 = uVar9 << 1 ^ 0x13;
    }
    bVar8 = param_2[0x130];
    uVar9 = uVar15 << 1;
    if ((uVar15 & 8) != 0) {
      uVar9 = uVar15 << 1 ^ 0x13;
    }
    bVar4 = (byte)(uVar9 << 1);
    if ((uVar9 & 8) != 0) {
      bVar4 = bVar4 ^ 3;
    }
    local_98[lVar16 + 1] = bVar4 & 0xf | bVar5;
    memcpy(__dest,param_2 + bVar8,(long)(int)uVar3);
    bVar8 = drm_dp_msg_data_crc4(__dest,(ulong)uVar3);
    uVar13 = (ulong)uVar3 & 0xff;
    if (0x2f < uVar18 + uVar13) {
LAB_0010f390:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(1,0x10f394);
      (*pcVar6)();
    }
    iVar14 = 0x1200;
    if ((param_3 & 1) == 0) {
      iVar14 = 0x1000;
    }
    __dest[uVar13] = bVar8;
    uVar9 = 0;
    do {
      iVar17 = 0;
      iVar19 = uVar18 + uVar3 + 1;
      while( true ) {
        iVar20 = iVar19;
        if (*(int *)(param_1 + 0x78) <= iVar19) {
          iVar20 = *(int *)(param_1 + 0x78);
        }
        if (0xf < iVar20) {
          iVar20 = 0x10;
        }
        iVar10 = drm_dp_dpcd_write(*(undefined8 *)(param_1 + 0x80),iVar17 + iVar14,local_98 + iVar17
                                   ,(long)iVar20);
        if (iVar20 != iVar10) break;
        iVar17 = iVar20 + iVar17;
        iVar19 = iVar19 - iVar20;
        if (iVar19 < 1) {
          bVar8 = param_2[0x130];
          param_2[0x130] = (byte)(bVar8 + uVar3);
          if ((uint)param_2[0x131] != (bVar8 + uVar3 & 0xff)) goto LAB_0010f2bc;
          uVar11 = 1;
          param_2[0x154] = 2;
          param_2[0x155] = 0;
          param_2[0x156] = 0;
          param_2[0x157] = 0;
          goto LAB_0010f2c0;
        }
      }
      bVar7 = uVar9 < 5;
      uVar9 = uVar9 + 1;
    } while (iVar10 == -5 && bVar7);
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar11,2,"failed to dpcd write %d %d\n",iVar20);
    if ((DAT_00118109 & 1) == 0) {
      uVar11 = 0xfffffffb;
    }
    else {
      local_c8 = &__drm_printfn_debug;
      uStack_c0 = 0;
      local_b8 = 0;
      pcStack_b0 = "[dp_mst]";
      drm_printf(&local_c8,"sideband msg failed to send\n");
      drm_dp_mst_dump_sideband_msg_tx(&local_c8,param_2);
      uVar11 = 0xfffffffb;
    }
  }
LAB_0010f2c0:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_msg_data_crc4 @ 0010f3a8 size=248
// signature: undefined drm_dp_msg_data_crc4(void)
// callers: [drm_dp_sideband_append_payload, process_single_tx_qlock]
//------------------------------------------------------------

uint drm_dp_msg_data_crc4(long param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  
  if (param_2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0;
    iVar6 = (uint)param_2 * -8;
    uVar8 = 0;
    uVar5 = 7;
    uVar9 = 0x80;
    do {
      uVar2 = uVar5 - 1;
      uVar7 = uVar9 & *(byte *)(param_1 + (uVar8 & 0xff));
      uVar1 = uVar9 >> 1;
      uVar9 = 0x80;
      if (uVar1 != 0) {
        uVar9 = uVar1;
      }
      uVar4 = uVar7 >> (ulong)(uVar5 & 0x1f) | uVar4 << 1;
      uVar5 = 7;
      uVar7 = (uint)uVar8;
      if (uVar1 != 0) {
        uVar5 = uVar2;
      }
      else {
        uVar7 = uVar7 + 1;
      }
      uVar8 = (ulong)uVar7;
      if ((uVar4 & 0x100) != 0) {
        uVar4 = uVar4 ^ 0xd5;
      }
      bVar3 = iVar6 != -1;
      iVar6 = iVar6 + 1;
    } while (bVar3);
  }
  uVar9 = uVar4 << 1;
  if ((uVar4 & 0x80) != 0) {
    uVar9 = uVar4 << 1 ^ 0xd5;
  }
  uVar4 = uVar9 << 1;
  if ((uVar9 & 0x80) != 0) {
    uVar4 = uVar9 << 1 ^ 0xd5;
  }
  uVar9 = uVar4 << 1;
  if ((uVar4 & 0x80) != 0) {
    uVar9 = uVar4 << 1 ^ 0xd5;
  }
  uVar4 = uVar9 << 1;
  if ((uVar9 & 0x80) != 0) {
    uVar4 = uVar9 << 1 ^ 0xd5;
  }
  uVar9 = uVar4 << 1;
  if ((uVar4 & 0x80) != 0) {
    uVar9 = uVar4 << 1 ^ 0xd5;
  }
  uVar4 = uVar9 << 1;
  if ((uVar9 & 0x80) != 0) {
    uVar4 = uVar9 << 1 ^ 0xd5;
  }
  uVar9 = uVar4 << 1;
  if ((uVar4 & 0x80) != 0) {
    uVar9 = uVar4 << 1 ^ 0xd5;
  }
  uVar4 = uVar9 << 1;
  if ((uVar9 & 0x80) != 0) {
    uVar4 = uVar9 << 1 ^ 0xd5;
  }
  return uVar4;
}



//------------------------------------------------------------
// drm_dp_payload_send_msg @ 0010f4a0 size=756
// signature: undefined drm_dp_payload_send_msg(void)
// callers: [drm_dp_add_payload_part2, drm_dp_remove_payload]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_payload_send_msg(long param_1,long param_2,byte param_3,undefined2 param_4)

{
  byte bVar1;
  uint6 uVar2;
  ulong uVar3;
  ulong uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  undefined1 uVar12;
  ulong local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined1 local_d8 [4];
  undefined2 local_d4;
  undefined1 auStack_d2 [2];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
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
  
  lVar7 = sp_el0;
  lVar9 = param_1 + 800;
  local_68 = *(long *)(lVar7 + 0x638);
  uVar12 = *(undefined1 *)(param_2 + 8);
  local_f0 = 0;
  local_e8 = 0;
  uVar10 = *(undefined8 *)(param_2 + 0x668);
  mutex_lock(lVar9);
  if (((*(long *)(param_1 + 0x388) == 0) ||
      (lVar7 = drm_dp_mst_topology_get_mstb_validated_locked(*(long *)(param_1 + 0x388),uVar10),
      lVar7 == 0)) || (iVar6 = drm_dp_mst_topology_try_get_mstb(), iVar6 == 0)) {
    mutex_unlock(lVar9);
    lVar11 = *(long *)(param_2 + 0x668);
    mutex_lock(lVar9);
    if (*(long *)(param_1 + 0x388) == 0) {
LAB_0010f534:
      mutex_unlock(lVar9);
      iVar6 = -0x16;
      goto LAB_0010f750;
    }
    do {
      while( true ) {
        lVar8 = drm_dp_get_last_connected_port_to_mstb(lVar11);
        if (lVar8 == 0) goto LAB_0010f534;
        iVar6 = drm_dp_mst_topology_try_get_mstb(*(undefined8 *)(lVar8 + 0x668));
        lVar7 = *(long *)(lVar8 + 0x668);
        if (iVar6 != 0) break;
        lVar11 = lVar7;
      }
      uVar12 = *(undefined1 *)(lVar8 + 8);
    } while (lVar7 == 0);
  }
  mutex_unlock(lVar9);
  lVar9 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
  uVar10 = local_e8;
  uVar4 = local_f0;
  if (lVar9 == 0) {
    iVar6 = -0xc;
  }
  else {
    bVar1 = *(byte *)(param_2 + 0xf);
    if (bVar1 != 0) {
      uVar3 = local_f0 >> 0x10;
      local_f0 = local_f0 & 0xffffffffffffff00;
      if ((bVar1 != 1) && (local_f0 = CONCAT62((int6)uVar3,0x100), bVar1 != 2)) {
        local_f0 = CONCAT53(SUB85(uVar4,3),0x20100);
        if (bVar1 != 3) {
          local_f0 = CONCAT44(SUB84(uVar4,4),0x3020100);
          if (bVar1 != 4) {
            local_f0 = CONCAT35(SUB83(uVar4,5),0x403020100);
            if (bVar1 != 5) {
              local_f0 = CONCAT26(SUB82(uVar4,6),0x50403020100);
              if (bVar1 != 6) {
                local_f0 = CONCAT17(SUB81(uVar4,7),0x6050403020100);
                if ((bVar1 != 7) && (local_f0 = 0x706050403020100, bVar1 != 8)) {
                  local_e8 = CONCAT71(local_e8._1_7_,8);
                  if (bVar1 != 9) {
                    local_e8 = CONCAT62(SUB86(uVar10,2),0x908);
                    if (bVar1 != 10) {
                      local_e8 = CONCAT53(SUB85(uVar10,3),0xa0908);
                      if (bVar1 != 0xb) {
                        local_e8 = CONCAT44(SUB84(uVar10,4),0xb0a0908);
                        if (bVar1 != 0xc) {
                          local_e8 = CONCAT35(SUB83(uVar10,5),0xc0b0a0908);
                          if (bVar1 != 0xd) {
                            local_e8 = CONCAT26(SUB82(uVar10,6),0xd0c0b0a0908);
                            if (bVar1 != 0xe) {
                              local_e8 = CONCAT17(SUB81(uVar10,7),0xe0d0c0b0a0908);
                              if ((bVar1 != 0xf) && (local_e8 = 0xf0e0d0c0b0a0908, bVar1 != 0x10)) {
                    /* WARNING: Does not return */
                                pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10f794);
                                (*pcVar5)();
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
        }
      }
    }
    *(long *)(lVar9 + 0x138) = lVar7;
    local_78 = 0;
    uStack_70 = 0;
    local_e0 = 0x11;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    local_d0 = 0;
    _local_d8 = CONCAT24(param_4,(uint)param_3 << 0x10);
    uVar2 = _local_d8 >> 0x10;
    local_d8._0_2_ = CONCAT11(bVar1,uVar12);
    _local_d8 = CONCAT62(uVar2,local_d8._0_2_);
    memcpy(auStack_d2,&local_f0,(ulong)bVar1);
    drm_dp_encode_sideband_req(&local_e0,lVar9);
    *(undefined1 *)(lVar9 + 0x158) = 1;
    drm_dp_queue_down_tx(param_1,lVar9);
    iVar6 = drm_dp_mst_wait_tx_reply(lVar7,lVar9);
    if ((0 < iVar6) && (iVar6 = -0x16, *(char *)(lVar9 + 0x15a) != '\x01')) {
      iVar6 = 0;
    }
    kfree(lVar9);
  }
  drm_dp_mst_topology_put_mstb(lVar7);
LAB_0010f750:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// drm_dp_mst_topology_get_mstb_validated_locked @ 0010f794 size=112
// signature: undefined drm_dp_mst_topology_get_mstb_validated_locked(void)
// callers: [drm_dp_mst_topology_get_mstb_validated_locked, drm_dp_send_dpcd_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_payload_send_msg]
//------------------------------------------------------------

long drm_dp_mst_topology_get_mstb_validated_locked(long param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_2 != param_1) {
    for (puVar2 = *(undefined8 **)(param_1 + 0x28); puVar2 != (undefined8 *)(param_1 + 0x28);
        puVar2 = (undefined8 *)*puVar2) {
      if ((puVar2[2] != 0) &&
         (lVar1 = drm_dp_mst_topology_get_mstb_validated_locked(puVar2[2],param_2), lVar1 != 0)) {
        return lVar1;
      }
    }
    param_2 = 0;
  }
  return param_2;
}



//------------------------------------------------------------
// drm_dp_mst_topology_try_get_mstb @ 0010f804 size=212
// signature: undefined drm_dp_mst_topology_try_get_mstb(void)
// callers: [drm_dp_mst_link_probe_work, drm_dp_send_dpcd_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_get_mst_branch_device, drm_dp_payload_send_msg, drm_dp_mst_up_req_work, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

bool drm_dp_mst_topology_try_get_mstb(uint *param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = *param_1;
  if (*param_1 == 0) {
    uVar6 = 0;
  }
  else {
    do {
      Hint_Prefetch(param_1,2,0,1);
      do {
        uVar1 = *param_1;
        if (uVar1 != uVar5) break;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
        if (bVar3) {
          *param_1 = uVar5 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      uVar6 = uVar5;
    } while ((uVar5 != uVar1) && (uVar6 = 0, uVar5 = uVar1, uVar1 != 0));
  }
  if ((int)(uVar6 + 1 | uVar6) < 0) {
    refcount_warn_saturate(param_1,0);
  }
  if (uVar6 != 0) {
    if (*(long *)(*(long *)(param_1 + 0x10) + 0x68) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar4,1,"mstb %p (%d)\n",param_1,*param_1);
  }
  return uVar6 != 0;
}



//------------------------------------------------------------
// drm_dp_get_last_connected_port_to_mstb @ 0010f8ec size=56
// signature: undefined drm_dp_get_last_connected_port_to_mstb(void)
// callers: [drm_dp_get_last_connected_port_to_mstb, drm_dp_payload_send_msg]
//------------------------------------------------------------

void drm_dp_get_last_connected_port_to_mstb(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x38);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x28) == param_1)) {
    drm_dp_get_last_connected_port_to_mstb(*(undefined8 *)(lVar1 + 0x668));
  }
  return;
}



//------------------------------------------------------------
// drm_dp_get_one_sb_msg @ 0010f924 size=1320
// signature: undefined drm_dp_get_one_sb_msg(void)
// callers: [drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

void drm_dp_get_one_sb_msg(long param_1,ulong param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  long lVar5;
  ulong uVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  byte bVar19;
  uint uVar20;
  int iVar21;
  long lVar22;
  undefined8 local_98;
  undefined8 local_90;
  byte local_88 [32];
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  bVar8 = (param_2 & 1) == 0;
  lVar5 = param_1 + 0x90;
  if (bVar8) {
    lVar5 = param_1 + 0x1d6;
  }
  local_88[0x10] = 0;
  local_88[0x11] = 0;
  local_88[0x12] = 0;
  local_88[0x13] = 0;
  local_88[0x14] = 0;
  local_88[0x15] = 0;
  local_88[0x16] = 0;
  local_88[0x17] = 0;
  local_88[0x18] = 0;
  local_88[0x19] = 0;
  local_88[0x1a] = 0;
  local_88[0x1b] = 0;
  local_88[0x1c] = 0;
  local_88[0x1d] = 0;
  local_88[0x1e] = 0;
  local_88[0x1f] = 0;
  iVar16 = 0x1600;
  if (bVar8) {
    iVar16 = 0x1400;
  }
  local_88[0] = 0;
  local_88[1] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[8] = 0;
  local_88[9] = 0;
  local_88[10] = 0;
  local_88[0xb] = 0;
  local_88[0xc] = 0;
  local_88[0xd] = 0;
  local_88[0xe] = 0;
  local_88[0xf] = 0;
  local_98 = 0;
  local_90 = 0;
  if ((param_2 & 1) == 0) {
    *param_3 = 0;
  }
  iVar17 = *(int *)(param_1 + 0x78);
  if (0xf < iVar17) {
    iVar17 = 0x10;
  }
  iVar9 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),iVar16,local_88,(long)iVar17);
  if (iVar17 == iVar9) {
    if (local_88[0] != 0) {
      bVar3 = local_88[0] >> 5;
      uVar18 = (uint)bVar3;
      if ((int)(uVar18 + 3) <= iVar17) {
        uVar20 = 0;
        bVar19 = 0;
        iVar9 = -0x14 - (local_88[0] >> 2 & 0x38);
        uVar14 = 7;
        uVar13 = 0x80;
        do {
          if (0x1f < bVar19) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(1,0x10fe48);
            (*pcVar7)();
          }
          uVar2 = uVar13 & local_88[bVar19];
          uVar1 = uVar13 >> 1;
          uVar13 = 0x80;
          if (uVar1 != 0) {
            uVar13 = uVar1;
          }
          uVar20 = uVar2 >> (ulong)(uVar14 & 0x1f) | uVar20 << 1;
          uVar14 = uVar14 - 1;
          if (uVar1 == 0) {
            bVar19 = bVar19 + 1;
            uVar14 = 7;
          }
          if ((uVar20 & 0x10) != 0) {
            uVar20 = uVar20 ^ 0x13;
          }
          bVar8 = iVar9 != -1;
          iVar9 = iVar9 + 1;
        } while (bVar8);
        uVar13 = uVar20 << 1;
        if ((uVar20 & 8) != 0) {
          uVar13 = uVar20 << 1 ^ 0x13;
        }
        uVar20 = uVar13 << 1;
        if ((uVar13 & 8) != 0) {
          uVar20 = uVar13 << 1 ^ 0x13;
        }
        uVar13 = uVar20 << 1;
        if ((uVar20 & 8) != 0) {
          uVar13 = uVar20 << 1 ^ 0x13;
        }
        uVar20 = uVar13 << 1;
        if ((uVar13 & 8) != 0) {
          uVar20 = uVar13 << 1 ^ 0x13;
        }
        if ((uVar20 & 0xf) == (local_88[uVar18 + 2] & 0xf)) {
          bVar19 = local_88[0] >> 4;
          local_98 = CONCAT62(local_98._2_6_,CONCAT11(local_88[0],bVar19)) & 0xffffffffffff0fff;
          uVar6 = local_98;
          if (local_88[0] < 0x20) {
            lVar22 = 1;
          }
          else {
            if (uVar18 < 2) {
              bVar3 = 1;
            }
            local_98._0_3_ = CONCAT12(local_88[1],(undefined2)local_98);
            if (local_88[0] < 0x40) {
              lVar22 = 2;
            }
            else {
              local_98._4_4_ = SUB84(uVar6,4);
              local_98._0_4_ = CONCAT13(local_88[2],(undefined3)local_98);
              if (bVar3 == 2) {
                lVar22 = 3;
              }
              else {
                local_98._5_3_ = SUB83(uVar6,5);
                local_98._0_5_ = CONCAT14(local_88[3],(undefined4)local_98);
                if (bVar3 == 3) {
                  lVar22 = 4;
                }
                else {
                  local_98._6_2_ = SUB82(uVar6,6);
                  local_98._0_6_ = CONCAT15(local_88[4],(undefined5)local_98);
                  if (bVar3 == 4) {
                    lVar22 = 5;
                  }
                  else {
                    local_98._7_1_ = SUB81(uVar6,7);
                    local_98._0_7_ = CONCAT16(local_88[5],(undefined6)local_98);
                    if (bVar3 == 5) {
                      lVar22 = 6;
                    }
                    else {
                      local_98 = CONCAT17(local_88[6],(undefined7)local_98);
                      if (bVar3 == 6) {
                        lVar22 = 7;
                      }
                      else {
                        lVar22 = 8;
                        local_90 = CONCAT71(local_90._1_7_,local_88[7]);
                      }
                    }
                  }
                }
              }
            }
          }
          uVar6 = local_90;
          bVar3 = local_88[lVar22];
          uVar18 = bVar3 & 0x3f;
          local_90._0_3_ = CONCAT12(bVar3 >> 7,(undefined2)local_90);
          local_90._4_4_ = SUB84(uVar6,4);
          local_90 = CONCAT44(local_90._4_4_,CONCAT13(bVar3 >> 6,(undefined3)local_90)) &
                     0xffffffff01ffffff;
          uVar4 = (undefined1)uVar18;
          local_90._0_5_ = CONCAT14(uVar4,(undefined4)local_90);
          if ((bVar3 & 0x3f) != 0) {
            bVar3 = local_88[lVar22 + 1];
            local_90._0_6_ = CONCAT15(bVar3 >> 7,(undefined5)local_90);
            local_90 = CONCAT17(bVar3 >> 4,CONCAT16(bVar3 >> 6,(undefined6)local_90)) &
                       0x101ffffffffffff;
            if ((param_2 & 1) != 0) {
LAB_0010fc40:
              uVar13 = (int)lVar22 + 2;
              if ((char)bVar3 < '\0') {
                *(undefined1 *)(lVar5 + 0x131) = 0;
                *(undefined1 *)(lVar5 + 0x130) = uVar4;
                *(char *)(lVar5 + 0x132) = (char)uVar13;
                if (*(char *)(lVar5 + 0x134) != '\0') goto LAB_0010fd04;
                *(undefined1 *)(lVar5 + 0x134) = 1;
                *(ulong *)(lVar5 + 0x136) = local_98;
                *(ulong *)(lVar5 + 0x13e) = local_90;
              }
              else {
                if (*(char *)(lVar5 + 0x134) == '\0') {
LAB_0010fd04:
                  if (*(long *)(param_1 + 0x68) == 0) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
                  }
                  pcVar15 = "sideband msg set header failed %d\n";
                  bVar19 = local_88[0];
                  goto LAB_0010fe18;
                }
                *(undefined1 *)(lVar5 + 0x131) = 0;
                *(undefined1 *)(lVar5 + 0x130) = uVar4;
                *(char *)(lVar5 + 0x132) = (char)uVar13;
              }
              if ((bVar3 >> 6 & 1) != 0) {
                *(undefined1 *)(lVar5 + 0x135) = 1;
              }
              uVar20 = iVar17 - uVar13 & 0xff;
              if (uVar20 <= uVar18) {
                uVar18 = uVar20;
              }
              drm_dp_sideband_append_payload(lVar5,local_88 + uVar13,uVar18);
              iVar9 = ((uint)*(byte *)(lVar5 + 0x132) - iVar17) + (uint)*(byte *)(lVar5 + 0x130);
              if (iVar9 < 1) {
                uVar12 = 1;
              }
              else {
                do {
                  iVar21 = *(int *)(param_1 + 0x78);
                  if (iVar9 <= *(int *)(param_1 + 0x78)) {
                    iVar21 = iVar9;
                  }
                  if (0xf < iVar21) {
                    iVar21 = 0x10;
                  }
                  iVar10 = drm_dp_dpcd_read(*(undefined8 *)(param_1 + 0x80),iVar17 + iVar16,local_88
                                            ,(long)iVar21);
                  if (iVar21 != iVar10) {
                    if (*(long *)(param_1 + 0x68) == 0) {
                      uVar12 = 0;
                    }
                    else {
                      uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
                    }
                    pcVar15 = "failed to read a chunk (len %d, ret %d)\n";
                    iVar17 = iVar21;
                    goto LAB_0010fb00;
                  }
                  drm_dp_sideband_append_payload(lVar5,local_88,iVar21);
                  iVar17 = iVar21 + iVar17;
                  iVar9 = iVar9 - iVar21;
                  uVar12 = 1;
                } while (0 < iVar9);
              }
              goto LAB_0010fcb8;
            }
            lVar11 = drm_dp_get_mst_branch_device(param_1,bVar19,(ulong)&local_98 | 2);
            *param_3 = lVar11;
            if (lVar11 != 0) goto LAB_0010fc40;
            if (*(long *)(param_1 + 0x68) == 0) {
              uVar12 = 0;
            }
            else {
              uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
            }
            pcVar15 = "Got MST reply from unknown device %d\n";
LAB_0010fe18:
            __drm_dev_dbg(0,uVar12,2,pcVar15,bVar19);
            goto LAB_0010fcb4;
          }
        }
        else {
          if (*(long *)(param_1 + 0x68) == 0) {
            uVar12 = 0;
          }
          else {
            uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
          }
          __drm_dev_dbg(0,uVar12,2,"crc4 mismatch 0x%x 0x%x\n",uVar20 & 0xff);
        }
      }
    }
    print_hex_dump(&DAT_001152e3,"failed hdr",0,0x10,1,local_88,(long)iVar17,0);
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar12,2,"ERROR: failed header\n");
  }
  else {
    if (*(long *)(param_1 + 0x68) == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
    }
    pcVar15 = "failed to read DPCD down rep %d %d\n";
LAB_0010fb00:
    __drm_dev_dbg(0,uVar12,2,pcVar15,iVar17);
  }
LAB_0010fcb4:
  uVar12 = 0;
LAB_0010fcb8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar12);
  }
  return;
}



//------------------------------------------------------------
// drm_dp_get_mst_branch_device @ 0010fe4c size=244
// signature: undefined drm_dp_get_mst_branch_device(void)
// callers: [drm_dp_get_one_sb_msg, drm_dp_mst_up_req_work]
//------------------------------------------------------------

long drm_dp_get_mst_branch_device(long param_1,uint param_2,undefined1 *param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  
  mutex_lock(param_1 + 800);
  lVar6 = *(long *)(param_1 + 0x388);
  if (lVar6 == 0) {
LAB_0010ff04:
    lVar5 = 0;
  }
  else {
    param_2 = param_2 & 0xff;
    if (1 < param_2) {
      uVar3 = 0;
      do {
        plVar4 = (long *)(lVar6 + 0x28);
        do {
          plVar4 = (long *)*plVar4;
          if (plVar4 == (long *)(lVar6 + 0x28)) goto LAB_0010fe9c;
        } while (((byte)param_3[uVar3 >> 1] >> (ulong)((uVar3 << 2 ^ 0xffffffff) & 4) & 0xf) !=
                 *(byte *)(plVar4 + -2));
        lVar6 = plVar4[2];
        if (lVar6 == 0) {
          _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
                   "[drm] *ERROR* failed to lookup MSTB with lct %d, rad %02x\n",param_2,*param_3);
          goto LAB_0010ff04;
        }
LAB_0010fe9c:
        bVar1 = uVar3 != param_2 - 2;
        uVar3 = uVar3 + 1;
      } while (bVar1);
    }
    iVar2 = drm_dp_mst_topology_try_get_mstb(lVar6);
    lVar5 = 0;
    if (iVar2 != 0) {
      lVar5 = lVar6;
    }
  }
  mutex_unlock(param_1 + 800);
  return lVar5;
}



//------------------------------------------------------------
// drm_dp_sideband_append_payload @ 0010ff40 size=240
// signature: undefined drm_dp_sideband_append_payload(void)
// callers: [drm_dp_get_one_sb_msg]
//------------------------------------------------------------

void drm_dp_sideband_append_payload(void *param_1,void *param_2,byte param_3)

{
  byte bVar1;
  code *pcVar2;
  char cVar3;
  size_t __n;
  
  if ((0x30 < *(byte *)((long)param_1 + 0x131)) || (0x30 < (ulong)*(byte *)((long)param_1 + 0x131)))
  {
LAB_0011002c:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x110030);
    (*pcVar2)();
  }
  memcpy((void *)((long)param_1 + (ulong)*(byte *)((long)param_1 + 0x131)),param_2,(ulong)param_3);
  bVar1 = *(byte *)((long)param_1 + 0x130);
  param_3 = *(char *)((long)param_1 + 0x131) + param_3;
  *(byte *)((long)param_1 + 0x131) = param_3;
  if (bVar1 <= param_3) {
    cVar3 = drm_dp_msg_data_crc4(param_1,bVar1 - 1);
    __n = (ulong)bVar1 - 1;
    if (0x2f < __n) goto LAB_0011002c;
    if (*(char *)((long)param_1 + __n) != cVar3) {
      print_hex_dump(&DAT_001152e3,"wrong crc",0,0x10,1,param_1,(ulong)bVar1,0);
      __n = (ulong)*(byte *)((long)param_1 + 0x130) - 1;
    }
    memcpy((void *)((long)param_1 + (ulong)*(byte *)((long)param_1 + 0x133) + 0x30),param_1,__n);
    *(char *)((long)param_1 + 0x133) =
         *(char *)((long)param_1 + 0x130) + *(char *)((long)param_1 + 0x133) + -1;
  }
  return;
}



//------------------------------------------------------------
// drm_dp_check_and_send_link_address @ 00110030 size=188
// signature: undefined drm_dp_check_and_send_link_address(void)
// callers: [drm_dp_mst_link_probe_work, drm_dp_check_and_send_link_address]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 drm_dp_check_and_send_link_address(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long *plVar3;
  
  if (*(char *)(param_2 + 0x48) == '\0') {
    uVar2 = drm_dp_send_link_address(param_1,param_2);
    if ((int)uVar2 == 1) {
      uVar2 = 1;
      goto LAB_00110074;
    }
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  uVar2 = 0;
LAB_00110074:
  plVar3 = *(long **)(param_2 + 0x28);
  do {
    while( true ) {
      if (plVar3 == (undefined8 *)(param_2 + 0x28)) {
        return uVar2;
      }
      if (((*(char *)((long)plVar3 + -0xf) == '\0') && (*(char *)((long)plVar3 + -0xd) != '\0')) &&
         (plVar3[2] != 0)) break;
LAB_00110088:
      plVar3 = (long *)*plVar3;
    }
    uVar1 = drm_dp_check_and_send_link_address(param_1);
    if ((int)uVar1 != 1) {
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      goto LAB_00110088;
    }
    plVar3 = (long *)*plVar3;
    uVar2 = 1;
  } while( true );
}



//------------------------------------------------------------
// drm_dp_send_link_address @ 001100ec size=2976
// signature: undefined drm_dp_send_link_address(void)
// callers: [drm_dp_check_and_send_link_address, drm_dp_send_link_address]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint drm_dp_send_link_address(long param_1,long param_2)

{
  byte *pbVar1;
  char *pcVar2;
  long lVar3;
  long *plVar4;
  char cVar5;
  byte bVar6;
  code *pcVar7;
  bool bVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  uint *puVar15;
  undefined8 uVar16;
  ulong uVar17;
  char cVar18;
  long lVar19;
  uint uVar20;
  byte bVar21;
  char cVar22;
  uint uVar23;
  ulong uVar24;
  long lVar25;
  char *pcVar26;
  long *plVar27;
  ulong uVar28;
  undefined8 *puVar29;
  uint *puVar30;
  long lVar31;
  undefined1 uVar32;
  long *plVar33;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
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
  
  lVar13 = sp_el0;
  local_70 = *(long *)(lVar13 + 0x638);
  lVar13 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
  if (lVar13 == 0) {
    uVar10 = 0xfffffff4;
    goto LAB_00110c54;
  }
  *(long *)(lVar13 + 0x138) = param_2;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  local_c8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_f0 = 0;
  local_e8 = 0;
  local_f8 = 1;
  drm_dp_encode_sideband_req(&local_f8,lVar13);
  *(undefined1 *)(param_2 + 0x48) = 1;
  drm_dp_queue_down_tx(param_1,lVar13);
  uVar10 = drm_dp_mst_wait_tx_reply(param_2,lVar13);
  if ((int)uVar10 < 0) {
    _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
             "[drm] *ERROR* Sending link address failed with %d\n",uVar10);
  }
  else {
    if (*(char *)(lVar13 + 0x15a) != '\x01') {
      if (*(long *)(param_1 + 0x68) == 0) {
        uVar16 = 0;
      }
      else {
        uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
      }
      __drm_dev_dbg(0,uVar16,2,"link address reply: %d\n",*(undefined1 *)(lVar13 + 0x16c));
      if (*(char *)(lVar13 + 0x16c) != '\0') {
        uVar28 = 0;
        lVar14 = lVar13 + 0x16d;
        uVar24 = 0xfffffffffffffe6d;
        do {
          if (*(long *)(param_1 + 0x68) == 0) {
            uVar16 = 0;
          }
          else {
            uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
          }
          if ((((((uVar24 < 0xfffffffffffffd00) || (uVar24 + 1 < 0xfffffffffffffd00)) ||
                (uVar24 + 2 < 0xfffffffffffffd00)) ||
               ((uVar24 + 6 < 0xfffffffffffffd00 || (uVar24 + 3 < 0xfffffffffffffd00)))) ||
              ((uVar24 + 4 < 0xfffffffffffffd00 ||
               ((uVar24 + 5 < 0xfffffffffffffd00 || (uVar24 + 0x17 < 0xfffffffffffffd00)))))) ||
             (uVar24 + 0x18 < 0xfffffffffffffd00)) goto LAB_00110c90;
          __drm_dev_dbg(0,uVar16,2,
                        "port %d: input %d, pdt: %d, pn: %d, dpcd_rev: %02x, mcs: %d, ddps: %d, ldps %d, sdp %d/%d\n"
                        ,uVar28 & 0xffffffff,*(undefined1 *)(lVar14 + uVar24 + 0x193),
                        *(undefined1 *)(lVar14 + uVar24 + 0x194),
                        *(undefined1 *)(lVar14 + uVar24 + 0x195),
                        *(undefined1 *)(lVar14 + uVar24 + 0x199),
                        *(undefined1 *)(lVar14 + uVar24 + 0x196),
                        *(undefined1 *)(lVar14 + uVar24 + 0x197),
                        *(undefined1 *)(lVar14 + uVar24 + 0x198),
                        *(undefined1 *)(lVar14 + uVar24 + 0x1aa),
                        *(undefined1 *)(lVar14 + uVar24 + 0x1ab));
          uVar28 = uVar28 + 1;
          uVar24 = uVar24 + 0x19;
        } while (uVar28 < *(byte *)(lVar13 + 0x16c));
      }
      uVar16 = *(undefined8 *)(lVar13 + 0x164);
      puVar29 = (undefined8 *)(param_2 + 0x49);
      *puVar29 = *(undefined8 *)(lVar13 + 0x15c);
      *(undefined8 *)(param_2 + 0x51) = uVar16;
      lVar14 = memchr_inv(puVar29,0,0x10);
      uVar16 = _jiffies;
      if (lVar14 == 0) {
        *(undefined8 *)(param_2 + 0x49) = _jiffies;
        *(undefined8 *)(param_2 + 0x51) = uVar16;
        if (*(long *)(param_2 + 0x38) == 0) {
          uVar11 = drm_dp_dpcd_write(*(undefined8 *)(*(long *)(param_2 + 0x40) + 0x80),0x30,puVar29,
                                     0x10);
        }
        else {
          uVar11 = drm_dp_send_dpcd_write
                             (*(long *)(param_2 + 0x40),*(long *)(param_2 + 0x38),0x30,0x10,puVar29)
          ;
        }
        if (uVar11 - 1 < 0xf) {
          uVar10 = 0xffffffb9;
        }
        else {
          uVar10 = 0;
          if (uVar11 != 0x10) {
            uVar10 = uVar11;
          }
          if (uVar10 == 0) goto LAB_00110378;
        }
        bVar6 = *(byte *)(param_2 + 0x20);
        local_c8 = 0;
        local_c0 = 0;
        local_d8 = 0;
        local_d0 = 0;
        local_e8 = 0;
        local_e0 = 0;
        local_f8 = 0;
        local_f0 = 0;
        local_80 = 0;
        uStack_78 = 0;
        if (1 < (ulong)bVar6) {
          lVar14 = 0;
          do {
            uVar28 = lVar14 + 1;
            if ((uVar28 & 1) == 0) {
              if (0xf < uVar28) goto LAB_00110c94;
              uVar11 = (int)uVar28 - 1;
              bVar21 = *(byte *)(param_2 + 0x18 +
                                ((ulong)((uint)(int)(char)((char)uVar11 +
                                                          (char)((uVar11 & 0x80) >> 7)) >> 1) & 0xff
                                )) & 0xf;
            }
            else {
              if (0xf < uVar28) {
LAB_00110c94:
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x110c98);
                (*pcVar7)();
              }
              bVar21 = *(byte *)(param_2 + 0x18 + ((ulong)((int)lVar14 + 0x100U >> 1) & 0x7f)) >> 4;
            }
            *(byte *)(((ulong)&local_80 | 1) + lVar14) = bVar21;
            lVar14 = lVar14 + 1;
          } while ((ulong)bVar6 - 1 != lVar14);
        }
        snprintf((char *)&local_f8,0x40,"%*phC",(uint)bVar6,&local_80);
        _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
                 "[drm] *ERROR* GUID check on %s failed: %d\n",&local_f8,uVar10);
        if ((int)uVar10 < 0) goto LAB_00110c48;
        uVar10 = 0;
      }
      else {
LAB_00110378:
        if (*(char *)(lVar13 + 0x16c) == '\0') {
          uVar28 = 0;
          uVar11 = 0;
        }
        else {
          lVar14 = lVar13 + 0x16d;
          uVar28 = 0;
          uVar11 = 0;
          uVar20 = 0;
          plVar27 = (long *)(param_2 + 0x28);
          do {
            lVar31 = uVar28 * 0x19;
            uVar24 = lVar31 - 0x191;
            if (uVar24 < 0xfffffffffffffd00) {
LAB_00110c90:
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(1,0x110c94);
              (*pcVar7)();
            }
            pcVar2 = (char *)(lVar14 + lVar31);
            pbVar1 = (byte *)(pcVar2 + 2);
            lVar25 = *(long *)(param_1 + 0x68);
            uVar17 = (ulong)*pbVar1;
            uVar20 = uVar20 | (uint)(1L << (uVar17 & 0x3f));
            lVar19 = *(long *)(param_2 + 0x40);
            plVar33 = plVar27;
            do {
              plVar33 = (long *)*plVar33;
              if (plVar33 == plVar27) goto LAB_001104bc;
            } while (*(byte *)(plVar33 + -2) != *pbVar1);
            puVar15 = (uint *)(plVar33 + -3);
            iVar12 = drm_dp_mst_topology_try_get_port(puVar15);
            if ((puVar15 == (uint *)0x0) || (iVar12 == 0)) {
              if (uVar24 < 0xfffffffffffffd00) goto LAB_00110c90;
              uVar17 = (ulong)*pbVar1;
LAB_001104bc:
              puVar15 = (uint *)drm_dp_mst_add_port(lVar25,lVar19,param_2,uVar17);
              if (puVar15 == (uint *)0x0) {
                uVar10 = 0xfffffff4;
                goto LAB_00110c48;
              }
              cVar22 = '\0';
              bVar8 = true;
LAB_001104d4:
              uVar23 = 1;
LAB_001104d8:
              if (lVar31 - 0x193U < 0xfffffffffffffd00) goto LAB_00110c90;
              cVar5 = *pcVar2;
              pcVar26 = (char *)((long)puVar15 + 9);
              *pcVar26 = cVar5;
              if (cVar5 == '\0') goto LAB_00110504;
              uVar32 = 0;
            }
            else {
              bVar8 = lVar31 - 0x193U < 0xfffffffffffffd00;
              pcVar26 = (char *)((long)plVar33 + -0xf);
              if (*pcVar26 == '\0') {
                if (!bVar8) {
                  if ((*pcVar2 == '\0') || (plVar33[0xcb] == 0)) {
LAB_00110818:
                    if (plVar33[0xcb] == 0) {
                      cVar22 = '\0';
LAB_00110944:
                      bVar8 = false;
                      uVar23 = 0;
                      goto LAB_001104d8;
                    }
                    drm_modeset_lock(lVar19 + 0x10,0);
                    if (0xfffffffffffffcff < uVar28 * 0x19 - 399) {
                      cVar22 = *(char *)((long)plVar33 + -0xd);
                      if (cVar22 != *(char *)(lVar14 + uVar28 * 0x19 + 4)) {
                        bVar8 = false;
                        goto LAB_001104d4;
                      }
                      if (cVar22 == '\0') goto LAB_00110944;
                      if (uVar28 * 0x19 - 0x18e < 0xfffffffffffffd00) goto LAB_00110c90;
                      if (*(char *)((long)plVar33 + -0xb) == *(char *)(lVar14 + uVar28 * 0x19 + 5))
                      {
                        if (uVar28 * 0x19 - 0x18d < 0xfffffffffffffd00) goto LAB_00110c90;
                        if (*(char *)((long)plVar33 + -10) == *(char *)(lVar14 + uVar28 * 0x19 + 6))
                        {
                          if (uVar28 * 0x19 - 400 < 0xfffffffffffffd00) goto LAB_00110c90;
                          if (*(char *)((long)plVar33 + -0xe) ==
                              *(char *)(lVar14 + uVar28 * 0x19 + 3)) {
                            if (uVar28 * 0x19 - 0x192 < 0xfffffffffffffd00) goto LAB_00110c90;
                            if (*(char *)((long)plVar33 + -0xc) ==
                                *(char *)(lVar14 + uVar28 * 0x19 + 1)) {
                              if (0xfffffffffffffcff < uVar28 * 0x19 - 0x17b) {
                                bVar8 = false;
                                cVar22 = '\x01';
                                uVar23 = (uint)((char)plVar33[-1] !=
                                               *(char *)(lVar14 + uVar28 * 0x19 + 0x18));
                                goto LAB_001104d8;
                              }
                              goto LAB_00110c90;
                            }
                          }
                        }
                      }
                      bVar8 = false;
                      cVar22 = '\x01';
                      goto LAB_001104d4;
                    }
                  }
                  else {
                    mutex_lock(lVar19 + 800);
                    *(int *)(plVar33[0xca] + 0x24) = *(int *)(plVar33[0xca] + 0x24) + -1;
                    uVar17 = __list_del_entry_valid(plVar33);
                    if ((uVar17 & 1) != 0) {
                      lVar3 = *plVar33;
                      plVar4 = (long *)plVar33[1];
                      *(long **)(lVar3 + 8) = plVar4;
                      *plVar4 = lVar3;
                    }
                    *plVar33 = -0x2152ffffffffff00;
                    plVar33[1] = -0x2152fffffffffede;
                    mutex_unlock(lVar19 + 800);
                    drm_dp_mst_topology_put_port(puVar15);
                    drm_dp_mst_topology_put_port(puVar15);
                    if (0xfffffffffffffcff < uVar24) {
                      uVar17 = (ulong)*pbVar1;
                      goto LAB_001104bc;
                    }
                  }
                }
                goto LAB_00110c90;
              }
              if (bVar8) goto LAB_00110c90;
              if (*pcVar2 != '\0') goto LAB_00110818;
              bVar8 = false;
              cVar22 = '\0';
              uVar23 = 1;
              *pcVar26 = '\0';
LAB_00110504:
              if (uVar28 * 0x19 - 0x192 < 0xfffffffffffffd00) goto LAB_00110c90;
              uVar32 = *(undefined1 *)(lVar14 + uVar28 * 0x19 + 1);
            }
            if ((uVar28 * 0x19 - 400 < 0xfffffffffffffd00) ||
               (uVar28 * 0x19 - 399 < 0xfffffffffffffd00)) goto LAB_00110c90;
            cVar5 = *(char *)(lVar14 + uVar28 * 0x19 + 3);
            cVar18 = *(char *)(lVar14 + uVar28 * 0x19 + 4);
            *(char *)((long)puVar15 + 0xb) = cVar18;
            if ((uVar28 * 0x19 - 0x18e < 0xfffffffffffffd00) ||
               (((*(undefined1 *)((long)puVar15 + 0xd) = *(undefined1 *)(lVar14 + uVar28 * 0x19 + 5)
                 , uVar28 * 0x19 - 0x18d < 0xfffffffffffffd00 ||
                 (*(undefined1 *)((long)puVar15 + 0xe) = *(undefined1 *)(lVar14 + uVar28 * 0x19 + 6)
                 , uVar28 * 0x19 - 0x17c < 0xfffffffffffffd00)) ||
                (*(undefined1 *)((long)puVar15 + 0xf) =
                      *(undefined1 *)(lVar14 + uVar28 * 0x19 + 0x17),
                uVar28 * 0x19 - 0x17b < 0xfffffffffffffd00)))) goto LAB_00110c90;
            *(undefined1 *)(puVar15 + 4) = *(undefined1 *)(lVar14 + uVar28 * 0x19 + 0x18);
            if (!bVar8) {
LAB_001106b0:
              if ((cVar18 == '\0') || (*pcVar26 != '\0')) {
                *(undefined2 *)((long)puVar15 + 0x12) = 0;
              }
              else {
                iVar12 = drm_dp_send_enum_path_resources(lVar19,param_2,puVar15);
                if (iVar12 == 1) {
                  uVar23 = 1;
                }
              }
              uVar10 = drm_dp_port_set_pdt(puVar15,uVar32,cVar5 != '\0');
              bVar9 = uVar10 == 1;
              if (-1 < (int)uVar10) {
                if ((!bVar8) && ((char)puVar15[3] == '\x02')) {
                  bVar9 = *(char *)((long)puVar15 + 10) != '\0' || uVar10 == 1;
                }
                goto LAB_00110724;
              }
LAB_00110bb0:
              _dev_err(*(undefined8 *)(lVar25 + 8),
                       "[drm] *ERROR* Failed to change PDT on port %p: %d\n",puVar15,uVar10);
              mutex_lock(lVar19 + 800);
              *(int *)(*(long *)(puVar15 + 0x19a) + 0x24) =
                   *(int *)(*(long *)(puVar15 + 0x19a) + 0x24) + -1;
              uVar28 = __list_del_entry_valid(puVar15 + 6);
              if ((uVar28 & 1) != 0) {
                lVar14 = *(long *)(puVar15 + 6);
                plVar27 = *(long **)(puVar15 + 8);
                *(long **)(lVar14 + 8) = plVar27;
                *plVar27 = lVar14;
              }
              puVar15[6] = 0x100;
              puVar15[7] = 0xdead0000;
              puVar15[8] = 0x122;
              puVar15[9] = 0xdead0000;
              mutex_unlock(lVar19 + 800);
              drm_dp_mst_topology_put_port(puVar15);
              if (*(long *)(puVar15 + 0x19c) != 0) {
                drm_modeset_unlock(lVar19 + 0x10);
              }
LAB_00110c3c:
              drm_dp_mst_topology_put_port(puVar15);
              goto LAB_00110c48;
            }
            mutex_lock(lVar19 + 800);
            if (*puVar15 == 0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x800,0x110968);
              (*pcVar7)();
            }
            Hint_Prefetch(puVar15,2,0,1);
            do {
              uVar10 = *puVar15;
              cVar18 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar15,0x10);
              if (bVar9) {
                *puVar15 = uVar10 + 1;
                cVar18 = ExclusiveMonitorsStatus();
              }
            } while (cVar18 != '\0');
            if (uVar10 == 0) {
              uVar16 = 2;
LAB_00110990:
              refcount_warn_saturate(puVar15,uVar16);
            }
            else if ((int)(uVar10 + 1 | uVar10) < 0) {
              uVar16 = 1;
              goto LAB_00110990;
            }
            if (*(long *)(*(long *)(puVar15 + 0x19e) + 0x68) == 0) {
              uVar16 = 0;
            }
            else {
              uVar16 = *(undefined8 *)(*(long *)(*(long *)(puVar15 + 0x19e) + 0x68) + 8);
            }
            puVar30 = puVar15 + 6;
            __drm_dev_dbg(0,uVar16,1,"port %p (%d)\n",puVar15,*puVar15);
            lVar31 = *plVar27;
            uVar24 = __list_add_valid(puVar30,plVar27,lVar31);
            if ((uVar24 & 1) != 0) {
              *(uint **)(lVar31 + 8) = puVar30;
              *(long *)(puVar15 + 6) = lVar31;
              *(long **)(puVar15 + 8) = plVar27;
              *plVar27 = (long)puVar30;
            }
            *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
            mutex_unlock(lVar19 + 800);
            cVar18 = *(char *)((long)puVar15 + 0xb);
            if (cVar22 != cVar18) goto LAB_001106b0;
            uVar10 = drm_dp_port_set_pdt(puVar15,uVar32,cVar5 != '\0');
            bVar9 = uVar10 == 1;
            if ((int)uVar10 < 0) goto LAB_00110bb0;
LAB_00110724:
            if (*(long *)(puVar15 + 0x19c) == 0) {
              if (*pcVar26 == '\0') {
                drm_dp_mst_port_add_connector(param_2,puVar15);
                goto joined_r0x00110780;
              }
              if (bVar9) goto LAB_0011074c;
LAB_001103c8:
              drm_dp_mst_topology_put_port(puVar15);
              uVar11 = uVar23 | uVar11;
            }
            else {
              drm_modeset_unlock(lVar19 + 0x10);
joined_r0x00110780:
              if (!bVar9) goto LAB_001103c8;
LAB_0011074c:
              if (*(long *)(puVar15 + 10) == 0) goto LAB_001103c8;
              uVar10 = drm_dp_send_link_address(lVar19);
              if (uVar10 != 1) {
                if ((int)uVar10 < 0) goto LAB_00110c3c;
                goto LAB_001103c8;
              }
              drm_dp_mst_topology_put_port(puVar15);
              uVar11 = 1;
            }
            uVar28 = uVar28 + 1;
          } while (uVar28 < *(byte *)(lVar13 + 0x16c));
          uVar28 = (ulong)(int)uVar20;
        }
        mutex_lock(param_1 + 800);
        plVar27 = *(long **)(param_2 + 0x28);
        uVar10 = uVar11;
        while (plVar33 = plVar27, plVar33 != (long *)(param_2 + 0x28)) {
          plVar27 = (long *)*plVar33;
          if ((uVar28 >> ((ulong)*(byte *)(plVar33 + -2) & 0x3f) & 1) == 0) {
            if (*(long *)(param_1 + 0x68) == 0) {
              uVar16 = 0;
            }
            else {
              uVar16 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
            }
            __drm_dev_dbg(0,uVar16,2,"port %d was not in link address, removing\n");
            uVar24 = __list_del_entry_valid(plVar33);
            if ((uVar24 & 1) != 0) {
              lVar14 = *plVar33;
              plVar4 = (long *)plVar33[1];
              *(long **)(lVar14 + 8) = plVar4;
              *plVar4 = lVar14;
            }
            *plVar33 = -0x2152ffffffffff00;
            plVar33[1] = -0x2152fffffffffede;
            drm_dp_mst_topology_put_port(plVar33 + -3);
            uVar10 = 1;
          }
        }
        mutex_unlock(param_1 + 800);
      }
      kfree(lVar13);
      goto LAB_00110c54;
    }
    _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x68) + 8),
             "[drm] *ERROR* link address NAK received\n");
    uVar10 = 0xfffffffb;
  }
LAB_00110c48:
  *(undefined1 *)(param_2 + 0x48) = 0;
  kfree(lVar13);
LAB_00110c54:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// drm_dp_mst_add_port @ 00110c9c size=272
// signature: undefined drm_dp_mst_add_port(void)
// callers: [drm_dp_send_link_address]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * drm_dp_mst_add_port(long param_1,undefined8 param_2,long param_3,undefined1 param_4)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined4 *puVar5;
  long lVar6;
  undefined8 uVar7;
  
  puVar5 = (undefined4 *)kmalloc_trace(_drm_crtc_wait_one_vblank,0xdc0,0x690);
  if (puVar5 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar5 = 1;
  puVar5[1] = 1;
  uVar7 = *(undefined8 *)(param_1 + 8);
  *(long *)(puVar5 + 0x19a) = param_3;
  *(undefined1 *)(puVar5 + 2) = param_4;
  *(undefined8 *)(puVar5 + 0x19e) = param_2;
  *(char **)(puVar5 + 0xc) = "DPMST";
  *(undefined1 *)(puVar5 + 0x196) = 1;
  *(undefined8 *)(puVar5 + 0x13e) = uVar7;
  *(long *)(puVar5 + 0x140) = param_1;
  drm_dp_remote_aux_init();
  puVar1 = (uint *)(param_3 + 4);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = uVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar2 == 0) {
    uVar7 = 2;
  }
  else {
    if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00110d3c;
    uVar7 = 1;
  }
  refcount_warn_saturate(puVar1,uVar7);
LAB_00110d3c:
  lVar6 = *(long *)(*(long *)(param_3 + 0x40) + 0x68);
  if (lVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(undefined8 *)(lVar6 + 8);
  }
  __drm_dev_dbg(0,uVar7,1,"mstb %p (%d)\n",param_3,*(undefined4 *)(param_3 + 4));
  return puVar5;
}



//------------------------------------------------------------
// drm_dp_send_enum_path_resources @ 00110db8 size=456
// signature: undefined drm_dp_send_enum_path_resources(void)
// callers: [drm_dp_send_link_address, drm_dp_mst_up_req_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_send_enum_path_resources(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  undefined8 local_b0;
  ulong local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
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
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
  if (lVar2 == 0) {
    iVar1 = -0xc;
    goto LAB_00110f4c;
  }
  *(undefined8 *)(lVar2 + 0x138) = param_2;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  local_b0 = 0x10;
  local_a8 = (ulong)*(byte *)(param_3 + 8);
  drm_dp_encode_sideband_req(&local_b0,lVar2);
  *(undefined1 *)(lVar2 + 0x158) = 1;
  drm_dp_queue_down_tx(param_1,lVar2);
  iVar1 = drm_dp_mst_wait_tx_reply(param_2,lVar2);
  if (0 < iVar1) {
    if (*(char *)(lVar2 + 0x15a) == '\x01') {
      if (*(long *)(param_1 + 0x68) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"enum path resources nak received\n");
      iVar1 = 0;
    }
    else {
      if (*(char *)(param_3 + 8) != *(char *)(lVar2 + 0x15c)) {
        __drm_err("got incorrect port in response\n");
      }
      if (*(long *)(param_1 + 0x68) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x68) + 8);
      }
      __drm_dev_dbg(0,uVar3,2,"enum path resources %d: %d %d\n",*(undefined1 *)(lVar2 + 0x15c),
                    *(undefined2 *)(lVar2 + 0x15e),*(undefined2 *)(lVar2 + 0x160));
      if (*(short *)(param_3 + 0x12) == *(short *)(lVar2 + 0x15e)) {
        cVar4 = *(char *)(lVar2 + 0x15d);
        if (*(char *)(param_3 + 0x689) != cVar4) goto LAB_00110f38;
        iVar1 = 0;
        cVar4 = *(char *)(param_3 + 0x689);
      }
      else {
        cVar4 = *(char *)(lVar2 + 0x15d);
LAB_00110f38:
        iVar1 = 1;
      }
      *(short *)(param_3 + 0x12) = *(short *)(lVar2 + 0x15e);
      *(char *)(param_3 + 0x689) = cVar4;
    }
  }
  kfree(lVar2);
LAB_00110f4c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dp_port_set_pdt @ 00110f80 size=852
// signature: undefined drm_dp_port_set_pdt(void)
// callers: [drm_dp_send_link_address, drm_dp_mst_up_req_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int drm_dp_port_set_pdt(long param_1,char param_2,byte param_3)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  size_t __n;
  undefined4 *puVar7;
  uint *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  ulong uVar12;
  char *__s;
  ulong uVar13;
  long lVar14;
  ulong local_50;
  long local_48;
  
  lVar14 = sp_el0;
  bVar2 = param_3 & 1;
  local_48 = *(long *)(lVar14 + 0x638);
  cVar1 = *(char *)(param_1 + 0xc);
  local_50 = 0;
  lVar14 = *(long *)(param_1 + 0x678);
  if ((cVar1 != param_2) || (*(byte *)(param_1 + 10) != bVar2)) {
    if (cVar1 != '\0') {
      if ((cVar1 == '\x02') && (*(char *)(param_1 + 10) != '\0')) {
        mutex_lock(lVar14 + 800);
        drm_dp_mst_topology_put_mstb(*(undefined8 *)(param_1 + 0x28));
        *(undefined8 *)(param_1 + 0x28) = 0;
        mutex_unlock(lVar14 + 800);
      }
      else {
        if ((param_2 != '\0') && ((param_2 == '\x02' & param_3) == 0)) {
          iVar6 = 0;
          *(char *)(param_1 + 0xc) = param_2;
          *(byte *)(param_1 + 10) = bVar2;
          goto LAB_00111248;
        }
        i2c_del_adapter(param_1 + 0x38);
      }
    }
    *(char *)(param_1 + 0xc) = param_2;
    *(byte *)(param_1 + 10) = bVar2;
    if (param_2 != '\0') {
      if ((param_2 != '\x02') || ((param_3 & 1) == 0)) {
        puVar10 = *(undefined8 **)(*(long *)(*(long *)(param_1 + 0x678) + 0x68) + 8);
        *(undefined8 *)(param_1 + 0x38) = &__this_module;
        *(undefined4 *)(param_1 + 0xa4) = 3;
        *(undefined4 *)(param_1 + 0x40) = 8;
        __s = *(char **)(param_1 + 0x30);
        *(undefined ***)(param_1 + 0x48) = &drm_dp_mst_i2c_algo;
        *(long **)(param_1 + 0x50) = (long *)(param_1 + 0x30);
        *(undefined8 **)(param_1 + 0x108) = puVar10;
        *(undefined8 *)(param_1 + 0x390) = puVar10[0x5d];
        if ((__s == (char *)0x0) && (__s = (char *)puVar10[0xe], __s == (char *)0x0)) {
          __s = (char *)*puVar10;
        }
        __n = strlen(__s);
        if (0x2e < __n) {
          __n = 0x2f;
        }
        memcpy((void *)(param_1 + 0x444),__s,__n);
        *(undefined1 *)(param_1 + 0x444 + __n) = 0;
        iVar6 = i2c_add_adapter((undefined8 *)(param_1 + 0x38));
        if (iVar6 < 0) {
          *(undefined1 *)(param_1 + 0xc) = 0;
        }
        goto LAB_00111248;
      }
      bVar2 = *(byte *)(*(long *)(param_1 + 0x668) + 0x20);
      uVar12 = (ulong)bVar2;
      uVar4 = bVar2 - 1;
      uVar4 = (int)(uVar4 + ((uVar4 & 0x8000) >> 0xf)) >> 1;
      if (bVar2 < 2) {
        uVar9 = 4;
        local_50 = local_50 & 0xffffffffffffff00;
LAB_00111150:
        uVar13 = (ulong)uVar4 & 0xffff;
        if (7 < uVar13) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x1112b0);
          (*pcVar5)();
        }
        *(byte *)((long)&local_50 + uVar13) =
             *(char *)(param_1 + 8) << (ulong)uVar9 | *(byte *)((long)&local_50 + uVar13);
        puVar7 = (undefined4 *)kmalloc_trace(_drm_display_mode_from_cea_vic,0xdc0,0x60);
        if (puVar7 == (undefined4 *)0x0) {
          _dev_err(*(undefined8 *)(*(long *)(lVar14 + 0x68) + 8),
                   "[drm] *ERROR* Failed to create MSTB for port %p",param_1);
          iVar6 = -0xc;
          *(undefined1 *)(param_1 + 0xc) = 0;
          goto LAB_00111248;
        }
        uVar4 = bVar2 + 1;
        *(char *)(puVar7 + 8) = (char)uVar4;
        if (1 < (uVar4 & 0xff)) {
          if (0x11 < (uVar4 & 0xff)) goto LAB_001112b0;
          memcpy(puVar7 + 6,&local_50,(ulong)(uVar4 >> 1 & 0x7f));
        }
        uVar12 = lVar14 + 800;
        *(undefined4 **)(puVar7 + 10) = puVar7 + 10;
        *(undefined4 **)(puVar7 + 0xc) = puVar7 + 10;
        *puVar7 = 1;
        puVar7[1] = 1;
        mutex_lock(uVar12);
        uVar11 = *(undefined8 *)(param_1 + 0x678);
        puVar8 = (uint *)(param_1 + 4);
        *(undefined4 **)(param_1 + 0x28) = puVar7;
        *(long *)(puVar7 + 0xe) = param_1;
        *(undefined8 *)(puVar7 + 0x10) = uVar11;
      }
      else {
        if (uVar4 < 8) {
          memcpy(&local_50,(void *)(*(long *)(param_1 + 0x668) + 0x18),((ulong)uVar4 & 0xffff) + 1);
          uVar9 = (bVar2 & 1) << 2;
          goto LAB_00111150;
        }
LAB_001112b0:
        puVar8 = (uint *)fortify_panic("memcpy");
      }
      Hint_Prefetch(puVar8,2,0,1);
      do {
        uVar4 = *puVar8;
        cVar1 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar8,0x10);
        if (bVar3) {
          *puVar8 = uVar4 + 1;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      if (uVar4 == 0) {
        uVar11 = 2;
LAB_001112d8:
        refcount_warn_saturate(puVar8,uVar11);
      }
      else if ((int)(uVar4 + 1 | uVar4) < 0) {
        uVar11 = 1;
        goto LAB_001112d8;
      }
      lVar14 = *(long *)(*(long *)(param_1 + 0x678) + 0x68);
      if (lVar14 == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = *(undefined8 *)(lVar14 + 8);
      }
      iVar6 = 1;
      __drm_dev_dbg(0,uVar11,1,"port %p (%d)\n",param_1,*(undefined4 *)(param_1 + 4));
      mutex_unlock(uVar12);
      goto LAB_00111248;
    }
  }
  iVar6 = 0;
LAB_00111248:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// drm_dp_mst_port_add_connector @ 001112e0 size=536
// signature: undefined drm_dp_mst_port_add_connector(void)
// callers: [drm_dp_send_link_address, drm_dp_mst_up_req_work]
//------------------------------------------------------------

void drm_dp_mst_port_add_connector(long param_1,long param_2)

{
  byte bVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  char local_170 [256];
  char local_70 [8];
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  local_170[0xf8] = '\0';
  local_170[0xf9] = '\0';
  local_170[0xfa] = '\0';
  local_170[0xfb] = '\0';
  local_170[0xfc] = '\0';
  local_170[0xfd] = '\0';
  local_170[0xfe] = '\0';
  local_170[0xe8] = '\0';
  local_170[0xe9] = '\0';
  local_170[0xea] = '\0';
  local_170[0xeb] = '\0';
  local_170[0xec] = '\0';
  local_170[0xed] = '\0';
  local_170[0xee] = '\0';
  local_170[0xef] = '\0';
  local_170[0xf0] = '\0';
  local_170[0xf1] = '\0';
  local_170[0xf2] = '\0';
  local_170[0xf3] = '\0';
  local_170[0xf4] = '\0';
  local_170[0xf5] = '\0';
  local_170[0xf6] = '\0';
  local_170[0xf7] = 0;
  lVar5 = *(long *)(param_2 + 0x678);
  local_170[0xd8] = '\0';
  local_170[0xd9] = '\0';
  local_170[0xda] = '\0';
  local_170[0xdb] = '\0';
  local_170[0xdc] = '\0';
  local_170[0xdd] = '\0';
  local_170[0xde] = '\0';
  local_170[0xdf] = '\0';
  local_170[0xe0] = '\0';
  local_170[0xe1] = '\0';
  local_170[0xe2] = '\0';
  local_170[0xe3] = '\0';
  local_170[0xe4] = '\0';
  local_170[0xe5] = '\0';
  local_170[0xe6] = '\0';
  local_170[0xe7] = '\0';
  bVar1 = *(byte *)(param_2 + 8);
  local_170[200] = '\0';
  local_170[0xc9] = '\0';
  local_170[0xca] = '\0';
  local_170[0xcb] = '\0';
  local_170[0xcc] = '\0';
  local_170[0xcd] = '\0';
  local_170[0xce] = '\0';
  local_170[0xcf] = '\0';
  local_170[0xd0] = '\0';
  local_170[0xd1] = '\0';
  local_170[0xd2] = '\0';
  local_170[0xd3] = '\0';
  local_170[0xd4] = '\0';
  local_170[0xd5] = '\0';
  local_170[0xd6] = '\0';
  local_170[0xd7] = '\0';
  local_170[0xb8] = '\0';
  local_170[0xb9] = '\0';
  local_170[0xba] = '\0';
  local_170[0xbb] = '\0';
  local_170[0xbc] = '\0';
  local_170[0xbd] = '\0';
  local_170[0xbe] = '\0';
  local_170[0xbf] = '\0';
  local_170[0xc0] = '\0';
  local_170[0xc1] = '\0';
  local_170[0xc2] = '\0';
  local_170[0xc3] = '\0';
  local_170[0xc4] = '\0';
  local_170[0xc5] = '\0';
  local_170[0xc6] = '\0';
  local_170[199] = '\0';
  local_170[0xa8] = '\0';
  local_170[0xa9] = '\0';
  local_170[0xaa] = '\0';
  local_170[0xab] = '\0';
  local_170[0xac] = '\0';
  local_170[0xad] = '\0';
  local_170[0xae] = '\0';
  local_170[0xaf] = '\0';
  local_170[0xb0] = '\0';
  local_170[0xb1] = '\0';
  local_170[0xb2] = '\0';
  local_170[0xb3] = '\0';
  local_170[0xb4] = '\0';
  local_170[0xb5] = '\0';
  local_170[0xb6] = '\0';
  local_170[0xb7] = '\0';
  local_170[0x98] = '\0';
  local_170[0x99] = '\0';
  local_170[0x9a] = '\0';
  local_170[0x9b] = '\0';
  local_170[0x9c] = '\0';
  local_170[0x9d] = '\0';
  local_170[0x9e] = '\0';
  local_170[0x9f] = '\0';
  local_170[0xa0] = '\0';
  local_170[0xa1] = '\0';
  local_170[0xa2] = '\0';
  local_170[0xa3] = '\0';
  local_170[0xa4] = '\0';
  local_170[0xa5] = '\0';
  local_170[0xa6] = '\0';
  local_170[0xa7] = '\0';
  local_170[0x88] = '\0';
  local_170[0x89] = '\0';
  local_170[0x8a] = '\0';
  local_170[0x8b] = '\0';
  local_170[0x8c] = '\0';
  local_170[0x8d] = '\0';
  local_170[0x8e] = '\0';
  local_170[0x8f] = '\0';
  local_170[0x90] = '\0';
  local_170[0x91] = '\0';
  local_170[0x92] = '\0';
  local_170[0x93] = '\0';
  local_170[0x94] = '\0';
  local_170[0x95] = '\0';
  local_170[0x96] = '\0';
  local_170[0x97] = '\0';
  local_170[0x78] = '\0';
  local_170[0x79] = '\0';
  local_170[0x7a] = '\0';
  local_170[0x7b] = '\0';
  local_170[0x7c] = '\0';
  local_170[0x7d] = '\0';
  local_170[0x7e] = '\0';
  local_170[0x7f] = '\0';
  local_170[0x80] = '\0';
  local_170[0x81] = '\0';
  local_170[0x82] = '\0';
  local_170[0x83] = '\0';
  local_170[0x84] = '\0';
  local_170[0x85] = '\0';
  local_170[0x86] = '\0';
  local_170[0x87] = '\0';
  local_170[0x68] = '\0';
  local_170[0x69] = '\0';
  local_170[0x6a] = '\0';
  local_170[0x6b] = '\0';
  local_170[0x6c] = '\0';
  local_170[0x6d] = '\0';
  local_170[0x6e] = '\0';
  local_170[0x6f] = '\0';
  local_170[0x70] = '\0';
  local_170[0x71] = '\0';
  local_170[0x72] = '\0';
  local_170[0x73] = '\0';
  local_170[0x74] = '\0';
  local_170[0x75] = '\0';
  local_170[0x76] = '\0';
  local_170[0x77] = '\0';
  local_170[0x58] = '\0';
  local_170[0x59] = '\0';
  local_170[0x5a] = '\0';
  local_170[0x5b] = '\0';
  local_170[0x5c] = '\0';
  local_170[0x5d] = '\0';
  local_170[0x5e] = '\0';
  local_170[0x5f] = '\0';
  local_170[0x60] = '\0';
  local_170[0x61] = '\0';
  local_170[0x62] = '\0';
  local_170[99] = '\0';
  local_170[100] = '\0';
  local_170[0x65] = '\0';
  local_170[0x66] = '\0';
  local_170[0x67] = '\0';
  local_170[0x48] = '\0';
  local_170[0x49] = '\0';
  local_170[0x4a] = '\0';
  local_170[0x4b] = '\0';
  local_170[0x4c] = '\0';
  local_170[0x4d] = '\0';
  local_170[0x4e] = '\0';
  local_170[0x4f] = '\0';
  local_170[0x50] = '\0';
  local_170[0x51] = '\0';
  local_170[0x52] = '\0';
  local_170[0x53] = '\0';
  local_170[0x54] = '\0';
  local_170[0x55] = '\0';
  local_170[0x56] = '\0';
  local_170[0x57] = '\0';
  local_170[0x38] = '\0';
  local_170[0x39] = '\0';
  local_170[0x3a] = '\0';
  local_170[0x3b] = '\0';
  local_170[0x3c] = '\0';
  local_170[0x3d] = '\0';
  local_170[0x3e] = '\0';
  local_170[0x3f] = '\0';
  local_170[0x40] = '\0';
  local_170[0x41] = '\0';
  local_170[0x42] = '\0';
  local_170[0x43] = '\0';
  local_170[0x44] = '\0';
  local_170[0x45] = '\0';
  local_170[0x46] = '\0';
  local_170[0x47] = '\0';
  local_170[0x28] = '\0';
  local_170[0x29] = '\0';
  local_170[0x2a] = '\0';
  local_170[0x2b] = '\0';
  local_170[0x2c] = '\0';
  local_170[0x2d] = '\0';
  local_170[0x2e] = '\0';
  local_170[0x2f] = '\0';
  local_170[0x30] = '\0';
  local_170[0x31] = '\0';
  local_170[0x32] = '\0';
  local_170[0x33] = '\0';
  local_170[0x34] = '\0';
  local_170[0x35] = '\0';
  local_170[0x36] = '\0';
  local_170[0x37] = '\0';
  local_170[0x18] = '\0';
  local_170[0x19] = '\0';
  local_170[0x1a] = '\0';
  local_170[0x1b] = '\0';
  local_170[0x1c] = '\0';
  local_170[0x1d] = '\0';
  local_170[0x1e] = '\0';
  local_170[0x1f] = '\0';
  local_170[0x20] = '\0';
  local_170[0x21] = '\0';
  local_170[0x22] = '\0';
  local_170[0x23] = '\0';
  local_170[0x24] = '\0';
  local_170[0x25] = '\0';
  local_170[0x26] = '\0';
  local_170[0x27] = '\0';
  local_170[8] = '\0';
  local_170[9] = '\0';
  local_170[10] = '\0';
  local_170[0xb] = '\0';
  local_170[0xc] = '\0';
  local_170[0xd] = '\0';
  local_170[0xe] = '\0';
  local_170[0xf] = '\0';
  local_170[0x10] = '\0';
  local_170[0x11] = '\0';
  local_170[0x12] = '\0';
  local_170[0x13] = '\0';
  local_170[0x14] = '\0';
  local_170[0x15] = '\0';
  local_170[0x16] = '\0';
  local_170[0x17] = '\0';
  local_170[0] = '\0';
  local_170[1] = '\0';
  local_170[2] = '\0';
  local_170[3] = '\0';
  local_170[4] = '\0';
  local_170[5] = '\0';
  local_170[6] = '\0';
  local_170[7] = '\0';
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  snprintf(local_170,0xff,"mst:%d",*(int *)(*(long *)(param_1 + 0x40) + 0x8c));
  if (1 < *(byte *)(param_1 + 0x20)) {
    uVar6 = 0;
    uVar7 = 0;
    do {
      if (uVar7 == 0x10) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1114f4);
        (*pcVar2)();
      }
      snprintf(local_70,8,"-%d",
               (ulong)(*(byte *)(param_1 + (ulong)(uVar7 >> 1) + 0x18) >>
                       (ulong)((uVar6 ^ 0xffffffff) & 4) & 0xf));
      strlcat(local_170,local_70,0xff);
      uVar7 = uVar7 + 1;
      uVar6 = uVar6 + 4;
    } while ((int)uVar7 < (int)(*(byte *)(param_1 + 0x20) - 1));
  }
  snprintf(local_70,8,"-%d",(ulong)bVar1);
  strlcat(local_170,local_70,0xff);
  if (*(int *)((code *)**(undefined8 **)(lVar5 + 0x70) + -4) != -0xa28c40b) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x111450);
    (*pcVar2)();
  }
  lVar3 = (*(code *)**(undefined8 **)(lVar5 + 0x70))(lVar5,param_2,local_170);
  *(long *)(param_2 + 0x670) = lVar3;
  if (lVar3 == 0) {
    _dev_err(*(undefined8 *)(*(long *)(lVar5 + 0x68) + 8),
             "[drm] *ERROR* Failed to create connector for port %p: %d\n",param_2,0xfffffff4);
  }
  else {
    if ((*(char *)(param_2 + 0xc) != '\0') &&
       (((*(char *)(param_2 + 0xc) != '\x02' || (*(char *)(param_2 + 10) == '\0')) &&
        (7 < *(byte *)(param_2 + 8))))) {
      uVar4 = drm_get_edid(lVar3,param_2 + 0x38);
      lVar3 = *(long *)(param_2 + 0x670);
      *(undefined8 *)(param_2 + 0x680) = uVar4;
    }
    drm_connector_register(lVar3);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// drm_dp_mst_i2c_xfer @ 001114fc size=1128
// signature: undefined drm_dp_mst_i2c_xfer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong drm_dp_mst_i2c_xfer(long param_1,undefined1 *param_2,uint param_3)

{
  long lVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  void *__s;
  ulong uVar7;
  ushort *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong *puVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  ulong local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  ulong local_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulong local_68;
  undefined8 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  uVar9 = (ulong)param_3;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar13 = *(long *)(param_1 + 0x18);
  lVar12 = *(long *)(lVar13 + 0x648);
  uVar10 = *(undefined8 *)(lVar13 + 0x638);
  lVar1 = lVar12 + 800;
  mutex_lock(lVar1);
  if (((*(long *)(lVar12 + 0x388) == 0) ||
      (lVar6 = drm_dp_mst_topology_get_mstb_validated_locked(*(long *)(lVar12 + 0x388),uVar10),
      lVar6 == 0)) || (iVar5 = drm_dp_mst_topology_try_get_mstb(), iVar5 == 0)) {
    mutex_unlock(lVar1);
    uVar9 = 0xffffff87;
    goto LAB_001118cc;
  }
  mutex_unlock(lVar1);
  uVar3 = param_3 - 1;
  uVar14 = (ulong)uVar3;
  if ((int)uVar3 < 5) {
    if (0 < (int)uVar3) {
      puVar8 = (ushort *)(param_2 + 4);
      uVar7 = uVar14;
      do {
        if (((puVar8[-1] & 1) != 0) || (0xff < *puVar8)) goto LAB_00111750;
        uVar7 = uVar7 - 1;
        puVar8 = puVar8 + 8;
      } while (uVar7 != 0);
    }
    if (((*(ushort *)(param_2 + (long)(int)uVar3 * 0x10 + 2) & 1) == 0) ||
       (0xff < *(ushort *)(param_2 + (long)(int)uVar3 * 0x10 + 4))) {
LAB_00111750:
      if (0 < (int)uVar3) goto LAB_00111758;
      goto LAB_00111788;
    }
    uVar10 = *(undefined8 *)(lVar13 + 0x648);
    local_68 = 0;
    local_60 = 0;
    local_78 = 0;
    local_70 = 0;
    local_88 = 0;
    local_80 = 0;
    local_98 = 0;
    local_90 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_c0 = 0;
    local_d0 = 0x22;
    local_c8 = (ulong)CONCAT11(*(undefined1 *)(lVar13 + -0x28),(char)uVar3);
    if (uVar3 != 0) {
      local_b8 = *(undefined8 *)(param_2 + 8);
      local_c0 = (ulong)CONCAT11(param_2[4],*param_2);
      local_b0 = (ulong)(byte)((byte)((ushort)*(undefined2 *)(param_2 + 2) >> 0xf) ^ 1);
      if (uVar3 != 1) {
        local_a0 = *(undefined8 *)(param_2 + 0x18);
        local_a8 = (ulong)CONCAT11(param_2[0x14],param_2[0x10]);
        local_98 = (ulong)(byte)((byte)((ushort)*(undefined2 *)(param_2 + 0x12) >> 0xf) ^ 1);
        if (uVar3 != 2) {
          local_88 = *(undefined8 *)(param_2 + 0x28);
          local_90 = (ulong)CONCAT11(param_2[0x24],param_2[0x20]);
          local_80 = (ulong)(byte)((byte)((ushort)*(undefined2 *)(param_2 + 0x22) >> 0xf) ^ 1);
          if (uVar3 != 3) {
            local_70 = *(undefined8 *)(param_2 + 0x38);
            local_78 = (ulong)CONCAT11(param_2[0x34],param_2[0x30]);
            local_68 = (ulong)(byte)((byte)((ushort)*(undefined2 *)(param_2 + 0x32) >> 0xf) ^ 1);
            if (uVar3 != 4) goto LAB_00111960;
          }
        }
      }
    }
    local_60 = (ulong)CONCAT11((char)*(ushort *)(param_2 + uVar14 * 0x10 + 4),param_2[uVar14 * 0x10]
                              );
    __s = (void *)kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
    if (__s == (void *)0x0) {
LAB_00111904:
      uVar9 = 0xfffffff4;
    }
    else {
      *(long *)((long)__s + 0x138) = lVar6;
      drm_dp_encode_sideband_req(&local_d0,__s);
      drm_dp_queue_down_tx(uVar10,__s);
      uVar7 = drm_dp_mst_wait_tx_reply(lVar6,__s);
      if ((int)uVar7 < 1) {
LAB_0011190c:
        uVar9 = uVar7 & 0xffffffff;
      }
      else if (*(char *)((long)__s + 0x15a) == '\x01') {
LAB_00111738:
        uVar9 = 0xffffff87;
      }
      else {
        uVar2 = *(ushort *)(param_2 + uVar14 * 0x10 + 4);
        if (uVar2 == *(byte *)((long)__s + 0x15d)) {
          if (0x1a2 < uVar2) {
            fortify_panic("memcpy");
LAB_00111960:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x111964);
            (*pcVar4)();
          }
          memcpy(*(void **)(param_2 + uVar14 * 0x10 + 8),(void *)((long)__s + 0x15e),(ulong)uVar2);
        }
        else {
          uVar9 = 0xfffffffb;
        }
      }
    }
LAB_00111910:
    kfree(__s);
  }
  else {
LAB_00111758:
    puVar8 = (ushort *)(param_2 + 4);
    do {
      if (((puVar8[-1] & 0x8001) != 0x8000) || (0xff < *puVar8)) goto LAB_00111898;
      uVar14 = uVar14 - 1;
      puVar8 = puVar8 + 8;
    } while (uVar14 != 0);
LAB_00111788:
    if (((*(ushort *)(param_2 + (long)(int)uVar3 * 0x10 + 2) & 1) == 0) &&
       (*(ushort *)(param_2 + (long)(int)uVar3 * 0x10 + 4) < 0x100)) {
      uVar10 = *(undefined8 *)(lVar13 + 0x648);
      local_68 = 0;
      local_60 = 0;
      local_78 = 0;
      local_70 = 0;
      local_88 = 0;
      local_80 = 0;
      local_98 = 0;
      local_90 = 0;
      local_a8 = 0;
      local_a0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      local_c8 = 0;
      local_c0 = 0;
      local_d0 = 0;
      __s = (void *)kmalloc_trace(_drm_object_property_set_value,0xdc0,0x300);
      if (__s == (void *)0x0) goto LAB_00111904;
      if (param_3 != 0) {
        puVar11 = (ulong *)(param_2 + 8);
        uVar14 = uVar9;
        do {
          local_68 = 0;
          local_60 = 0;
          local_78 = 0;
          local_70 = 0;
          local_88 = 0;
          local_80 = 0;
          local_98 = 0;
          local_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          local_b8 = 0;
          local_b0 = 0;
          local_d0 = 0x23;
          local_c8 = (ulong)CONCAT21(CONCAT11(*(undefined1 *)((long)puVar11 + -4),(char)puVar11[-1])
                                     ,*(undefined1 *)(lVar13 + -0x28));
          local_c0 = *puVar11;
          memset(__s,0,0x300);
          *(long *)((long)__s + 0x138) = lVar6;
          drm_dp_encode_sideband_req(&local_d0,__s);
          drm_dp_queue_down_tx(uVar10,__s);
          uVar7 = drm_dp_mst_wait_tx_reply(lVar6,__s);
          if ((int)uVar7 < 1) goto LAB_0011190c;
          if (*(char *)((long)__s + 0x15a) == '\x01') goto LAB_00111738;
          uVar14 = uVar14 - 1;
          puVar11 = puVar11 + 2;
        } while (uVar14 != 0);
      }
      goto LAB_00111910;
    }
LAB_00111898:
    if (*(long *)(lVar12 + 0x68) == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = *(undefined8 *)(*(long *)(lVar12 + 0x68) + 8);
    }
    __drm_dev_dbg(0,uVar10,2,"Unsupported I2C transaction for MST device\n");
    uVar9 = 0xfffffffb;
  }
  drm_dp_mst_topology_put_mstb(lVar6);
LAB_001118cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// drm_dp_mst_i2c_functionality @ 00111968 size=12
// signature: undefined drm_dp_mst_i2c_functionality(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dp_mst_i2c_functionality(void)

{
  return 0xfff800b;
}



//------------------------------------------------------------
// get_mst_branch_device_by_guid_helper @ 00111974 size=116
// signature: undefined get_mst_branch_device_by_guid_helper(void)
// callers: [get_mst_branch_device_by_guid_helper, drm_dp_mst_up_req_work]
//------------------------------------------------------------

long get_mst_branch_device_by_guid_helper(long param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  
  if ((param_1 != 0) &&
     (*(long *)(param_1 + 0x49) != *param_2 || *(long *)(param_1 + 0x51) != param_2[1])) {
    plVar1 = (long *)(param_1 + 0x28);
    plVar2 = plVar1;
    do {
      plVar2 = (long *)*plVar2;
      if (plVar2 == plVar1) {
        return 0;
      }
      param_1 = get_mst_branch_device_by_guid_helper(plVar2[2],param_2);
    } while (param_1 == 0);
  }
  return param_1;
}



//------------------------------------------------------------
// drm_dsc_dp_pps_header_init @ 001119ec size=16
// signature: undefined drm_dsc_dp_pps_header_init(void)
// callers: []
//------------------------------------------------------------

void drm_dsc_dp_pps_header_init(undefined4 *param_1)

{
  *param_1 = 0x7f1000;
  return;
}



//------------------------------------------------------------
// drm_dsc_dp_rc_buffer_size @ 00111a00 size=84
// signature: undefined drm_dsc_dp_rc_buffer_size(void)
// callers: []
//------------------------------------------------------------

int drm_dsc_dp_rc_buffer_size(byte param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 < 4) {
    iVar1 = (param_2 & 0xff) * 0x400 + 0x400;
    switch(param_1) {
    case 1:
      return iVar1 * 4;
    case 2:
      return iVar1 * 0x10;
    case 3:
      return iVar1 * 0x40;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// drm_dsc_pps_payload_pack @ 00111a58 size=640
// signature: undefined drm_dsc_pps_payload_pack(void)
// callers: []
//------------------------------------------------------------

void drm_dsc_pps_payload_pack(byte *param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  long lVar3;
  byte *pbVar4;
  
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0x7d] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x66] = 0;
  param_1[0x67] = 0;
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  lVar3 = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *param_1 = param_2[0x7e] | param_2[0x7f] << 4;
  param_1[3] = *param_2 | param_2[1] << 4;
  param_1[4] = param_2[0x11] & 3 | param_2[0x78] << 2 | param_2[8] << 3 | param_2[2] << 4 |
               param_2[0x1a] << 5;
  param_1[5] = param_2[0x10];
  *(ushort *)(param_1 + 6) = *(ushort *)(param_2 + 0xc) >> 8 | *(ushort *)(param_2 + 0xc) << 8;
  *(ushort *)(param_1 + 8) = *(ushort *)(param_2 + 10) >> 8 | *(ushort *)(param_2 + 10) << 8;
  *(ushort *)(param_1 + 10) = *(ushort *)(param_2 + 6) >> 8 | *(ushort *)(param_2 + 6) << 8;
  *(ushort *)(param_1 + 0xc) = *(ushort *)(param_2 + 4) >> 8 | *(ushort *)(param_2 + 4) << 8;
  *(ushort *)(param_1 + 0xe) = *(ushort *)(param_2 + 0x7a) >> 8 | *(ushort *)(param_2 + 0x7a) << 8;
  param_1[0x10] = param_2[0x17] & 3;
  param_1[0x11] = param_2[0x16];
  *(ushort *)(param_1 + 0x12) = *(ushort *)(param_2 + 0x18) >> 8 | *(ushort *)(param_2 + 0x18) << 8;
  param_1[0x15] = param_2[0x6c];
  *(ushort *)(param_1 + 0x16) = *(ushort *)(param_2 + 0x70) >> 8 | *(ushort *)(param_2 + 0x70) << 8;
  param_1[0x18] = param_2[0x6f] & 0xf;
  param_1[0x19] = param_2[0x6e];
  param_1[0x1b] = param_2[0x1b];
  *(ushort *)(param_1 + 0x1c) = *(ushort *)(param_2 + 0x72) >> 8 | *(ushort *)(param_2 + 0x72) << 8;
  *(ushort *)(param_1 + 0x1e) = *(ushort *)(param_2 + 0x74) >> 8 | *(ushort *)(param_2 + 0x74) << 8;
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_2 + 0x1c) >> 8 | *(ushort *)(param_2 + 0x1c) << 8;
  *(ushort *)(param_1 + 0x22) = *(ushort *)(param_2 + 0x76) >> 8 | *(ushort *)(param_2 + 0x76) << 8;
  param_1[0x24] = param_2[0x6a];
  param_1[0x25] = param_2[0x6b];
  uVar2 = *(ushort *)(param_2 + 0x68);
  param_1[0x28] = 6;
  *(ushort *)(param_1 + 0x26) = uVar2 >> 8 | uVar2 << 8;
  param_1[0x29] = param_2[0x14];
  bVar1 = param_2[0x13];
  param_1[0x2b] = 0x33;
  param_1[0x2a] = bVar1;
  param_1[0x2c] = param_2[0x1e];
  param_1[0x2d] = param_2[0x20];
  param_1[0x2e] = param_2[0x22];
  param_1[0x2f] = param_2[0x24];
  param_1[0x30] = param_2[0x26];
  param_1[0x31] = param_2[0x28];
  param_1[0x32] = param_2[0x2a];
  param_1[0x33] = param_2[0x2c];
  param_1[0x34] = param_2[0x2e];
  param_1[0x35] = param_2[0x30];
  param_1[0x36] = param_2[0x32];
  param_1[0x37] = param_2[0x34];
  param_1[0x38] = param_2[0x36];
  param_1[0x39] = param_2[0x38];
  pbVar4 = param_2 + 0x3c;
  do {
    *(ushort *)(param_1 + lVar3 + 0x3a) =
         (ushort)(((uint)pbVar4[-1] << 6) >> 8) | (ushort)(((uint)pbVar4[-2] << 0xb) >> 8) & 0xff |
         (ushort)(((uint)pbVar4[-1] << 6 & 0xff | (uint)*pbVar4) << 8);
    lVar3 = lVar3 + 2;
    pbVar4 = pbVar4 + 3;
  } while (lVar3 != 0x1e);
  param_1[0x58] = param_2[0x80] | param_2[0x81] << 1;
  param_1[0x59] = param_2[0x82];
  *(ushort *)(param_1 + 0x5a) = *(ushort *)(param_2 + 0x84) >> 8 | *(ushort *)(param_2 + 0x84) << 8;
  *(ushort *)(param_1 + 0x5c) = *(ushort *)(param_2 + 0x86) >> 8 | *(ushort *)(param_2 + 0x86) << 8;
  return;
}



//------------------------------------------------------------
// drm_dsc_compute_rc_parameters @ 00111cdc size=620
// signature: undefined drm_dsc_compute_rc_parameters(void)
// callers: []
//------------------------------------------------------------

undefined8 drm_dsc_compute_rc_parameters(long param_1)

{
  long lVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 uVar11;
  uint uVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  undefined2 uVar18;
  
  if ((*(char *)(param_1 + 0x81) == '\0') && (*(char *)(param_1 + 0x80) == '\0')) {
    uVar9 = (uint)*(ushort *)(param_1 + 4);
    uVar12 = (uint)*(ushort *)(param_1 + 0x10);
    iVar5 = uVar12 * uVar9 + 0x7f;
    iVar4 = uVar12 * uVar9 + 0xfe;
    if (-1 < iVar5) {
      iVar4 = iVar5;
    }
    uVar14 = iVar4 >> 7;
  }
  else {
    uVar12 = (uint)*(ushort *)(param_1 + 0x10);
    uVar9 = (uint)(*(ushort *)(param_1 + 4) >> 1);
    uVar14 = uVar9 * *(ushort *)(param_1 + 0x10) + 0x7f >> 7;
  }
  *(short *)(param_1 + 0x7a) = (short)uVar14;
  if (*(char *)(param_1 + 2) == '\0') {
    uVar16 = (ulong)*(byte *)(param_1 + 0x79);
    uVar10 = uVar16 * 3 + (ulong)*(byte *)(param_1 + 1) * 0xc + 2;
    if (*(char *)(param_1 + 0x80) != '\0') {
      uVar10 = (ulong)*(byte *)(param_1 + 1) * 0x10 + uVar16 * 4 | 2;
    }
  }
  else {
    uVar16 = (ulong)*(byte *)(param_1 + 0x79);
    uVar10 = (uVar16 + (ulong)*(byte *)(param_1 + 1) * 4) * 3 + 6;
  }
  uVar13 = (ulong)(uVar9 + 2) / 3;
  uVar2 = *(ushort *)(param_1 + 6);
  uVar8 = (uint)uVar2;
  if (uVar10 != 0) {
    uVar17 = (long)(int)((uVar14 & 0xffff) * 8 * uVar8) - uVar10;
    do {
      uVar6 = 0;
      if (uVar16 != 0) {
        uVar6 = uVar17 / uVar16;
      }
      if (uVar17 == uVar6 * uVar16) break;
      uVar10 = uVar10 - 1;
      uVar17 = uVar17 + 1;
    } while (uVar10 != 0);
  }
  uVar16 = (ulong)*(byte *)(param_1 + 0x6c);
  if (uVar13 < uVar16 - 8) {
    uVar14 = (uint)uVar13 + 8;
    uVar16 = (ulong)uVar14;
    *(char *)(param_1 + 0x6c) = (char)uVar14;
  }
  uVar14 = (uint)uVar16 & 0xff;
  if (uVar14 < 9) {
    uVar18 = 0xfff;
  }
  else {
    uVar14 = uVar14 - 8;
    uVar18 = 0;
    if (uVar14 != 0) {
      uVar18 = (undefined2)((uint)uVar13 / uVar14);
    }
  }
  *(undefined2 *)(param_1 + 0x6e) = uVar18;
  uVar3 = *(ushort *)(param_1 + 0x68);
  iVar4 = uVar12 * *(ushort *)(param_1 + 0x16);
  iVar5 = iVar4 + 0x17;
  if (-1 < iVar4 + 8) {
    iVar5 = iVar4 + 8;
  }
  lVar1 = uVar10 + ((uint)uVar3 - (iVar5 >> 4));
  uVar14 = (uint)lVar1 & 0xffff;
  *(short *)(param_1 + 0x76) = (short)lVar1;
  if (uVar14 < uVar3) {
    uVar15 = (uint)uVar3;
    iVar5 = uVar15 - uVar14;
    uVar14 = 0;
    if (iVar5 != 0) {
      uVar14 = (int)(uVar15 << 3) / iVar5;
    }
    if (uVar8 < 2) {
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
      if (uVar8 - 1 != 0) {
        uVar7 = (ushort)(((uVar8 + (uint)*(byte *)(param_1 + 0x1b) * 0x800) - 2) / (uVar8 - 1));
      }
    }
    *(ushort *)(param_1 + 0x72) = uVar7;
    uVar9 = (uVar9 + 2) / 3;
    uVar17 = (ulong)uVar9 * (ulong)uVar2;
    uVar16 = 0;
    if (uVar17 != 0) {
      uVar16 = ((((uVar10 + uVar15) - (ulong)*(ushort *)(param_1 + 0x1c)) * 0x800 + uVar13 * uVar2)
               - 1) / uVar17;
    }
    *(short *)(param_1 + 0x74) = (short)uVar16;
    if (uVar14 < 10) {
      uVar18 = 0;
    }
    else {
      uVar10 = ((uVar16 & 0xffff) + (ulong)uVar7) * ((long)(int)uVar14 + -9);
      uVar18 = 0;
      if (uVar10 != 0) {
        uVar18 = (undefined2)((lVar1 * 0x800 & 0x7fff800U) / uVar10);
      }
    }
    uVar11 = 0;
    iVar5 = iVar4 + 0x1e;
    if (-1 < iVar4 + 0xf) {
      iVar5 = iVar4 + 0xf;
    }
    *(undefined2 *)(param_1 + 0x70) = uVar18;
    uVar10 = (ulong)uVar12;
    iVar4 = 0;
    if (uVar10 != 0) {
      iVar4 = (int)(((uVar10 + ((((ulong)uVar3 + (long)(iVar5 >> 4)) -
                                (ulong)*(ushort *)(param_1 + 0x1c)) +
                               (ulong)*(byte *)(param_1 + 0x1b) * (ulong)uVar9) * 0x10) - 1) /
                   uVar10);
    }
    *(ushort *)(param_1 + 0x18) = (short)iVar4 - *(ushort *)(param_1 + 0x16);
    *(short *)(param_1 + 0x7c) = (short)(iVar4 * uVar12 >> 4);
  }
  else {
    ___drm_dbg(0,2,"FinalOfs < RcModelSze for this InitialXmitDelay\n");
    uVar11 = 0xffffffde;
  }
  return uVar11;
}



//------------------------------------------------------------
// init_module @ 00111f4c size=8
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00111f58 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// __kmalloc @ 00118000 size=1
// signature: undefined __kmalloc(void)
// callers: [drm_dp_mst_atomic_setup_commit, drm_dp_dual_mode_read, drm_dp_dual_mode_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 00118008 size=1
// signature: undefined i2c_transfer(void)
// callers: [drm_dp_dual_mode_read, drm_dp_dual_mode_max_tmds_clock, drm_dp_dual_mode_write, drm_dp_dual_mode_detect, drm_dp_dual_mode_set_tmds_output, drm_lspcon_get_mode, drm_lspcon_set_mode, drm_dp_dual_mode_get_tmds_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00118010 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [drm_dp_aux_register, drm_dp_dual_mode_read, drm_dp_dual_mode_write, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_sideband_append_payload, drm_dp_port_set_pdt, process_single_tx_qlock, drm_dp_payload_send_msg, drm_dp_encode_sideband_req, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00118018 size=1
// signature: undefined kfree(void)
// callers: [drm_dp_dual_mode_read, drm_dp_dual_mode_write, drm_dp_send_query_stream_enc_status, drm_dp_mst_dump_sideband_msg_tx, drm_dp_mst_put_port_malloc, drm_dp_free_mst_branch_device, drm_dp_mst_dump_topology, drm_lspcon_get_mode, drm_dp_decode_sideband_req, drm_dp_dual_mode_get_tmds_output, drm_dp_send_enum_path_resources, drm_dp_dual_mode_max_tmds_clock, drm_dp_mst_i2c_xfer, drm_dp_dual_mode_detect, drm_dp_send_link_address, drm_dp_delayed_destroy_work, drm_dp_dual_mode_set_tmds_output, drm_dp_payload_send_msg, drm_lspcon_set_mode, drm_dp_mst_destroy_state, drm_dp_send_dpcd_write, drm_dp_mst_hpd_irq_handle_event, drm_dp_mst_link_probe_work, drm_dp_mst_duplicate_state, drm_dp_mst_dpcd_read, drm_dp_mst_topology_put_port, drm_dp_mst_up_req_work, drm_dp_send_power_updown_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00118020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [drm_dp_dual_mode_read, drm_dp_send_query_stream_enc_status, drm_dp_mst_dump_sideband_msg_tx, drm_dp_read_dpcd_caps, drm_lspcon_get_mode, drm_dp_dual_mode_get_tmds_output, drm_dp_mst_port_add_connector, drm_dp_send_enum_path_resources, drm_dp_read_mst_cap, drm_dp_pcon_frl_prepare, drm_dp_dual_mode_max_tmds_clock, drm_dp_pcon_frl_configure_1, drm_dp_pcon_pps_default, drm_dp_pcon_pps_override_param, drm_dp_dpcd_access, drm_dp_mst_topology_mgr_resume, drm_dp_mst_topology_mgr_suspend, drm_dp_mst_i2c_xfer, drm_dp_dual_mode_detect, drm_dp_aux_crc_work, drm_dp_check_act_status, process_single_tx_qlock, drm_lspcon_set_mode, drm_dp_set_phy_test_pattern, drm_dp_pcon_is_frl_ready, drm_dp_i2c_xfer, drm_dp_read_channel_eq_delay, drm_dp_queue_down_tx, drm_dp_pcon_hdmi_frl_link_error_count, drm_edp_backlight_init, drm_dp_start_crc, drm_dp_read_desc, drm_dp_read_sink_count, drm_dp_dpcd_probe, drm_dp_mst_topology_mgr_set_mst, drm_dp_dpcd_write_payload, drm_dp_mst_dpcd_read, drm_dp_pcon_hdmi_link_active, drm_dp_mst_dsc_aux_for_port, drm_dp_dual_mode_write, drm_dp_pcon_reset_frl_config, drm_dp_read_clock_recovery_delay, drm_dp_mst_wait_tx_reply, drm_dp_mst_dump_mstb, drm_dp_port_set_pdt, drm_dp_mst_dump_topology, drm_dp_128b132b_read_aux_rd_interval, drm_edp_backlight_set_level, drm_dp_downstream_debug, drm_edp_backlight_set_enable, drm_edp_backlight_enable, drm_dp_send_link_address, drm_dp_dual_mode_set_tmds_output, drm_dp_payload_send_msg, drm_panel_dp_aux_backlight, drm_dp_send_dpcd_write, drm_dp_stop_crc, drm_dp_pcon_frl_configure_2, drm_dp_get_one_sb_msg, drm_dp_pcon_pps_override_buf, drm_dp_get_phy_test_pattern, drm_dp_mst_hpd_irq_handle_event, drm_dp_pcon_convert_rgb_to_ycbcr, drm_dp_mst_link_probe_work, drm_dp_send_real_edid_checksum, drm_dp_pcon_hdmi_link_mode, dp_aux_backlight_update_status, drm_dp_pcon_frl_enable, drm_dp_send_power_updown_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __drm_dev_dbg @ 00118028 size=1
// signature: undefined __drm_dev_dbg(void)
// callers: [drm_dp_mst_atomic_check_mstb_bw_limit, drm_dp_send_query_stream_enc_status, drm_dp_mst_put_port_malloc, drm_dp_mst_add_affected_dsc_crtcs, __8b10b_channel_eq_delay_us, __8b10b_clock_recovery_delay_us, drm_dp_read_dpcd_caps, drm_lspcon_get_mode, drm_dp_dual_mode_get_tmds_output, drm_dp_send_enum_path_resources, drm_dp_dual_mode_max_tmds_clock, drm_dp_dpcd_access, drm_dp_mst_topology_mgr_resume, drm_dp_mst_i2c_xfer, drm_dp_dual_mode_detect, drm_dp_mst_topology_put_mstb, drm_dp_aux_crc_work, drm_dp_mst_connector_early_unregister, drm_dp_check_act_status, process_single_tx_qlock, drm_dp_delayed_destroy_work, drm_lspcon_set_mode, __128b132b_channel_eq_delay_us, drm_dp_atomic_release_time_slots, drm_dp_i2c_xfer, drm_dp_dpcd_write, drm_dp_read_channel_eq_delay, drm_dp_dpcd_read, drm_edp_backlight_init, drm_dp_read_desc, drm_dp_dpcd_probe, drm_dp_mst_topology_mgr_set_mst, drm_dp_dpcd_write_payload, drm_dp_mst_dpcd_read, drm_dp_mst_topology_put_port, drm_dp_mst_connector_late_register, drm_dp_mst_up_req_work, drm_dp_add_payload_part1, drm_dp_link_train_channel_eq_delay, drm_dp_mst_topology_try_get_mstb, drm_dp_read_clock_recovery_delay, drm_dp_mst_wait_tx_reply, drm_dp_port_set_pdt, drm_dp_atomic_find_time_slots, process_single_down_tx_qlock, drm_dp_add_payload_part2, drm_edp_backlight_enable, drm_dp_remove_payload, drm_dp_mst_topology_try_get_port, drm_dp_send_link_address, drm_dp_dual_mode_set_tmds_output, drm_dp_mst_atomic_enable_dsc, drm_dp_get_one_sb_msg, drm_dp_lttpr_link_train_channel_eq_delay, drm_dp_i2c_do_msg, drm_dp_mst_hpd_irq_handle_event, drm_dp_link_train_clock_recovery_delay, drm_dp_mst_link_probe_work, drm_dp_send_real_edid_checksum, drm_dp_get_vc_payload_bw, drm_dp_mst_duplicate_state, drm_dp_pcon_frl_enable, drm_dp_mst_get_port_malloc, drm_dp_mst_atomic_check, drm_dp_read_downstream_info, drm_dp_mst_add_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __drm_dev_dbg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00118038 size=1
// signature: undefined kmalloc_trace(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_send_dpcd_write, drm_dp_port_set_pdt, drm_lspcon_get_mode, drm_dp_dual_mode_get_tmds_output, drm_dp_mst_hpd_irq_handle_event, drm_dp_mst_topology_mgr_init, drm_dp_send_enum_path_resources, drm_dp_mst_topology_mgr_set_mst, drm_dp_mst_link_probe_work, drm_dp_dual_mode_max_tmds_clock, drm_dp_atomic_find_time_slots, drm_dp_mst_dpcd_read, drm_dp_mst_i2c_xfer, drm_dp_dual_mode_detect, drm_dp_send_link_address, drm_dp_dual_mode_set_tmds_output, drm_dp_payload_send_msg, drm_lspcon_set_mode, drm_dp_send_power_updown_phy, drm_dp_mst_add_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00118040 size=1
// signature: undefined _dev_err(void)
// callers: [drm_dp_port_set_pdt, drm_dp_i2c_do_msg, drm_dp_get_mst_branch_device, drm_dp_pcon_hdmi_frl_link_error_count, drm_lspcon_get_mode, drm_dp_mst_port_add_connector, drm_dp_128b132b_read_aux_rd_interval, drm_edp_backlight_set_level, drm_dp_mst_hpd_irq_handle_event, drm_dp_send_real_edid_checksum, drm_edp_backlight_set_enable, dp_aux_backlight_update_status, drm_dp_add_payload_part2, drm_dp_dual_mode_detect, drm_edp_backlight_enable, drm_dp_check_act_status, drm_dp_send_link_address, drm_lspcon_set_mode, drm_dp_mst_up_req_work, drm_dp_mst_atomic_wait_for_dependencies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00118048 size=1
// signature: undefined usleep_range_state(void)
// callers: [drm_dp_lttpr_link_train_clock_recovery_delay, drm_dp_link_train_clock_recovery_delay, drm_dp_link_train_channel_eq_delay, drm_dp_dpcd_write_payload, drm_dp_dpcd_access, drm_dp_aux_crc_work, drm_dp_check_act_status, drm_dp_lttpr_link_train_channel_eq_delay, drm_dp_i2c_do_msg, drm_lspcon_get_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00118050 size=1
// signature: undefined msleep(void)
// callers: [drm_lspcon_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00118058 size=1
// signature: undefined mutex_lock(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_mst_detect_port, drm_dp_tx_work, drm_dp_mst_wait_tx_reply, drm_dp_port_set_pdt, drm_dp_mst_dump_topology, drm_dp_mst_hpd_irq_send_new_request, drm_dp_dpcd_access, drm_dp_mst_topology_mgr_resume, drm_dp_add_payload_part2, drm_dp_mst_topology_mgr_suspend, drm_dp_mst_i2c_xfer, drm_dp_mst_topology_put_mstb, drm_dp_remove_payload, drm_dp_mst_get_edid, drm_dp_send_link_address, drm_dp_delayed_destroy_work, drm_dp_payload_send_msg, drm_panel_dp_aux_backlight, lock_bus, drm_dp_mst_is_virtual_dpcd, drm_dp_send_dpcd_write, drm_dp_get_mst_branch_device, drm_dp_queue_down_tx, drm_dp_mst_hpd_irq_handle_event, drm_dp_mst_topology_mgr_set_mst, drm_dp_mst_link_probe_work, drm_dp_mst_dpcd_read, drm_dp_mst_topology_put_port, drm_dp_dpcd_set_powered, drm_dp_mst_atomic_check, drm_dp_mst_up_req_work, drm_dp_send_power_updown_phy, drm_dp_add_payload_part1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00118060 size=1
// signature: undefined mutex_unlock(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_mst_detect_port, drm_dp_tx_work, drm_dp_mst_wait_tx_reply, drm_dp_port_set_pdt, drm_dp_mst_dump_topology, drm_dp_mst_hpd_irq_send_new_request, drm_dp_dpcd_access, drm_dp_mst_topology_mgr_resume, drm_dp_add_payload_part2, drm_dp_mst_topology_mgr_suspend, drm_dp_mst_i2c_xfer, drm_dp_mst_topology_put_mstb, drm_dp_remove_payload, drm_dp_mst_get_edid, drm_dp_send_link_address, drm_dp_delayed_destroy_work, drm_dp_payload_send_msg, drm_panel_dp_aux_backlight, drm_dp_mst_is_virtual_dpcd, drm_dp_send_dpcd_write, unlock_bus, drm_dp_get_mst_branch_device, drm_dp_queue_down_tx, drm_dp_mst_hpd_irq_handle_event, drm_dp_mst_topology_mgr_set_mst, drm_dp_mst_link_probe_work, drm_dp_mst_dpcd_read, drm_dp_mst_topology_put_port, drm_dp_dpcd_set_powered, drm_dp_mst_atomic_check, drm_dp_mst_up_req_work, drm_dp_send_power_updown_phy, drm_dp_add_payload_part1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_display_mode_from_cea_vic @ 00118068 size=1
// signature: undefined drm_display_mode_from_cea_vic(void)
// callers: [drm_dp_downstream_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_display_mode_from_cea_vic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00118070 size=1
// signature: undefined seq_printf(void)
// callers: [drm_dp_downstream_debug, drm_dp_mst_dump_mstb, drm_dp_mst_dump_topology]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00118078 size=1
// signature: undefined seq_puts(void)
// callers: [drm_dp_downstream_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_object_property_set_value @ 00118080 size=1
// signature: undefined drm_object_property_set_value(void)
// callers: [drm_dp_set_subconnector_property]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_object_property_set_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_crtc_wait_one_vblank @ 00118088 size=1
// signature: undefined drm_crtc_wait_one_vblank(void)
// callers: [drm_dp_aux_crc_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_crtc_wait_one_vblank(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_crtc_add_crc_entry @ 00118090 size=1
// signature: undefined drm_crtc_add_crc_entry(void)
// callers: [drm_dp_aux_crc_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_crtc_add_crc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00118098 size=1
// signature: undefined __mutex_init(void)
// callers: [drm_dp_aux_register, drm_dp_aux_init, drm_dp_mst_topology_mgr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001180a0 size=1
// signature: size_t strlen(char * __s)
// callers: [drm_dp_aux_register, drm_dp_port_set_pdt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_add_adapter @ 001180a8 size=1
// signature: undefined i2c_add_adapter(void)
// callers: [drm_dp_aux_register, drm_dp_port_set_pdt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_add_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_adapter @ 001180b0 size=1
// signature: undefined i2c_del_adapter(void)
// callers: [drm_dp_aux_unregister, drm_dp_port_set_pdt, drm_dp_delayed_destroy_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_adapter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001180c0 size=1
// signature: undefined queue_work_on(void)
// callers: [drm_dp_mst_topology_mgr_set_mst, drm_dp_mst_topology_mgr_resume, drm_dp_mst_wait_tx_reply, drm_dp_mst_topology_put_mstb, drm_dp_mst_topology_put_port, drm_dp_start_crc, drm_dp_mst_up_req_work, drm_dp_mst_hpd_irq_handle_event, drm_dp_mst_hpd_irq_send_new_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 001180c8 size=1
// signature: undefined flush_work(void)
// callers: [drm_dp_mst_topology_mgr_resume, drm_dp_mst_topology_mgr_suspend, drm_dp_mst_topology_mgr_destroy, drm_dp_stop_crc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001180d0 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [drm_dp_read_desc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001180d8 size=1
// signature: undefined fortify_panic(void)
// callers: [drm_dp_mst_i2c_xfer, drm_dp_port_set_pdt, process_single_tx_qlock, drm_dp_read_desc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 001180e0 size=1
// signature: undefined __sw_hweight8(void)
// callers: [drm_dp_lttpr_count]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_printk @ 001180e8 size=1
// signature: undefined _dev_printk(void)
// callers: [drm_dp_vsc_sdp_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_dev_printk @ 001180f0 size=1
// signature: undefined drm_dev_printk(void)
// callers: [drm_dp_i2c_do_msg, drm_panel_dp_aux_backlight]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_dev_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001180f8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [drm_panel_dp_aux_backlight]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_backlight_device_register @ 00118100 size=1
// signature: undefined devm_backlight_device_register(void)
// callers: [drm_panel_dp_aux_backlight]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_backlight_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00118110 size=1
// signature: undefined ___ratelimit(void)
// callers: [drm_dp_i2c_do_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 00118118 size=1
// signature: undefined mutex_trylock(void)
// callers: [trylock_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 00118128 size=1
// signature: undefined kmemdup(void)
// callers: [drm_dp_mst_duplicate_state, drm_dp_decode_sideband_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_printf @ 00118130 size=1
// signature: undefined drm_printf(void)
// callers: [drm_dp_mst_dump_sideband_msg_tx, drm_dp_dump_sideband_msg_req_body, process_single_tx_qlock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00118140 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [drm_dp_mst_destroy_state, drm_dp_mst_topology_try_get_mstb, drm_dp_mst_put_port_malloc, drm_dp_port_set_pdt, drm_dp_mst_atomic_setup_commit, drm_dp_mst_topology_mgr_set_mst, drm_dp_atomic_find_time_slots, drm_dp_mst_duplicate_state, drm_dp_mst_topology_put_mstb, drm_dp_mst_topology_try_get_port, kref_put, drm_dp_mst_topology_put_port, drm_dp_mst_get_port_malloc, drm_dp_send_link_address, drm_dp_delayed_destroy_work, drm_dp_mst_add_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00118148 size=1
// signature: undefined __list_add_valid(void)
// callers: [drm_dp_atomic_find_time_slots, drm_dp_mst_duplicate_state, drm_dp_mst_topology_put_mstb, drm_dp_mst_topology_put_port, drm_dp_send_link_address, drm_dp_queue_down_tx, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00118160 size=1
// signature: undefined init_wait_entry(void)
// callers: [drm_dp_mst_wait_tx_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00118168 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [drm_dp_mst_wait_tx_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00118170 size=1
// signature: undefined schedule_timeout(void)
// callers: [drm_dp_mst_wait_tx_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00118178 size=1
// signature: undefined finish_wait(void)
// callers: [drm_dp_mst_wait_tx_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00118180 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [process_single_down_tx_qlock, drm_dp_mst_wait_tx_reply, drm_dp_send_link_address, drm_dp_delayed_destroy_work, drm_dp_mst_up_req_work, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 00118190 size=1
// signature: undefined get_random_bytes(void)
// callers: [drm_dp_send_query_stream_enc_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_modeset_lock @ 00118198 size=1
// signature: undefined drm_modeset_lock(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_mst_detect_port, drm_dp_send_link_address, drm_dp_mst_up_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_modeset_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_modeset_unlock @ 001181a0 size=1
// signature: undefined drm_modeset_unlock(void)
// callers: [drm_dp_send_query_stream_enc_status, drm_dp_send_link_address, drm_dp_mst_dump_topology, drm_dp_mst_up_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_modeset_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001181a8 size=1
// signature: undefined _dev_warn(void)
// callers: [drm_dp_add_payload_part1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memchr_inv @ 001181b0 size=1
// signature: undefined memchr_inv(void)
// callers: [drm_dp_mst_topology_mgr_resume, drm_dp_send_link_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memchr_inv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001181b8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [drm_dp_mst_i2c_xfer, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001181c0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [drm_dp_mst_dump_sideband_msg_tx, drm_dp_send_link_address, drm_dp_mst_port_add_connector, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___drm_dbg @ 001181c8 size=1
// signature: undefined ___drm_dbg(void)
// callers: [drm_dsc_compute_rc_parameters, drm_dp_mst_update_slots, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___drm_dbg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001181d0 size=1
// signature: undefined __wake_up(void)
// callers: [process_single_down_tx_qlock, drm_dp_delayed_destroy_work, drm_dp_mst_hpd_irq_handle_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_get_edid @ 001181d8 size=1
// signature: undefined drm_get_edid(void)
// callers: [drm_dp_mst_detect_port, drm_dp_mst_get_edid, drm_dp_mst_port_add_connector]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_get_edid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_edid_duplicate @ 001181e0 size=1
// signature: undefined drm_edid_duplicate(void)
// callers: [drm_dp_mst_get_edid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_edid_duplicate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_detect_monitor_audio @ 001181e8 size=1
// signature: undefined drm_detect_monitor_audio(void)
// callers: [drm_dp_mst_get_edid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_detect_monitor_audio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_get_private_obj_state @ 001181f0 size=1
// signature: undefined drm_atomic_get_private_obj_state(void)
// callers: [drm_dp_mst_atomic_enable_dsc, drm_dp_atomic_find_time_slots, drm_dp_mst_root_conn_atomic_check, drm_dp_mst_add_affected_dsc_crtcs, drm_atomic_get_mst_topology_state, drm_dp_atomic_release_time_slots]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_get_private_obj_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 001181f8 size=1
// signature: undefined dev_driver_string(void)
// callers: [drm_dp_atomic_find_time_slots]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00118200 size=1
// signature: undefined __warn_printk(void)
// callers: [drm_dp_atomic_find_time_slots, process_single_tx_qlock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight32 @ 00118208 size=1
// signature: undefined __sw_hweight32(void)
// callers: [drm_dp_mst_atomic_setup_commit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_crtc_commit_wait @ 00118210 size=1
// signature: undefined drm_crtc_commit_wait(void)
// callers: [drm_dp_mst_atomic_wait_for_dependencies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_crtc_commit_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00118218 size=1
// signature: undefined ktime_get(void)
// callers: [drm_dp_check_act_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_modeset_lock_single_interruptible @ 00118220 size=1
// signature: undefined drm_modeset_lock_single_interruptible(void)
// callers: [drm_dp_mst_dump_topology]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_modeset_lock_single_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_edid_get_monitor_name @ 00118228 size=1
// signature: undefined drm_edid_get_monitor_name(void)
// callers: [drm_dp_mst_dump_topology]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_edid_get_monitor_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_get_connector_state @ 00118230 size=1
// signature: undefined drm_atomic_get_connector_state(void)
// callers: [drm_dp_mst_add_affected_dsc_crtcs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_get_connector_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_get_crtc_state @ 00118238 size=1
// signature: undefined drm_atomic_get_crtc_state(void)
// callers: [drm_dp_mst_add_affected_dsc_crtcs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_get_crtc_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __drm_atomic_helper_private_obj_duplicate_state @ 00118240 size=1
// signature: undefined __drm_atomic_helper_private_obj_duplicate_state(void)
// callers: [drm_dp_mst_duplicate_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __drm_atomic_helper_private_obj_duplicate_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __drm_crtc_commit_free @ 00118248 size=1
// signature: undefined __drm_crtc_commit_free(void)
// callers: [drm_dp_mst_destroy_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __drm_crtc_commit_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_get_old_private_obj_state @ 00118250 size=1
// signature: undefined drm_atomic_get_old_private_obj_state(void)
// callers: [drm_atomic_get_old_mst_topology_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_get_old_private_obj_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_get_new_private_obj_state @ 00118258 size=1
// signature: undefined drm_atomic_get_new_private_obj_state(void)
// callers: [drm_atomic_get_new_mst_topology_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_get_new_private_obj_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00118260 size=1
// signature: undefined alloc_workqueue(void)
// callers: [drm_dp_mst_topology_mgr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00118268 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [drm_dp_mst_topology_mgr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_private_obj_init @ 00118270 size=1
// signature: undefined drm_atomic_private_obj_init(void)
// callers: [drm_dp_mst_topology_mgr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_private_obj_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_kms_helper_hotplug_event @ 00118278 size=1
// signature: undefined drm_kms_helper_hotplug_event(void)
// callers: [drm_dp_mst_link_probe_work, drm_dp_delayed_destroy_work, drm_dp_mst_up_req_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_kms_helper_hotplug_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_connector_unregister @ 00118280 size=1
// signature: undefined drm_connector_unregister(void)
// callers: [drm_dp_delayed_destroy_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_connector_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_mode_object_put @ 00118288 size=1
// signature: undefined drm_mode_object_put(void)
// callers: [drm_dp_delayed_destroy_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_mode_object_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00118290 size=1
// signature: undefined destroy_workqueue(void)
// callers: [drm_dp_mst_topology_mgr_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_atomic_private_obj_fini @ 00118298 size=1
// signature: undefined drm_atomic_private_obj_fini(void)
// callers: [drm_dp_mst_topology_mgr_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_atomic_private_obj_fini(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 001182a0 size=1
// signature: undefined mutex_is_locked(void)
// callers: [process_single_down_tx_qlock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 001182a8 size=1
// signature: undefined print_hex_dump(void)
// callers: [drm_dp_sideband_append_payload, drm_dp_get_one_sb_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __drm_err @ 001182b0 size=1
// signature: undefined __drm_err(void)
// callers: [drm_dp_send_enum_path_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __drm_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 001182b8 size=1
// signature: undefined strlcat(void)
// callers: [drm_dp_mst_port_add_connector]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drm_connector_register @ 001182c0 size=1
// signature: undefined drm_connector_register(void)
// callers: [drm_dp_mst_port_add_connector]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drm_connector_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



