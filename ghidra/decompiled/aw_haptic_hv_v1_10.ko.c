// Decompiled by Ghidra 12.2
// Program: aw_haptic_hv_v1_10.ko
// Image base: 00100000

//------------------------------------------------------------
// aw869x_get_f0 @ 0010717c size=852
// signature: undefined aw869x_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869x_get_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined *puVar6;
  int iVar7;
  undefined1 local_48 [4];
  byte local_44;
  undefined2 local_43;
  byte local_41;
  byte local_40;
  ushort local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw869x_stop();
  aw869x_play_mode(param_1,4);
  haptic_hv_i2c_write_bits(param_1,0x48,0xfffffff3,4);
  haptic_hv_i2c_write_bits(param_1,0x2b,0xffffff9f,0xe0);
  haptic_hv_i2c_writes(param_1,0x7b,param_1 + 0x53a,1);
  local_41 = *(byte *)(param_1 + 0x547);
  local_40 = *(byte *)(param_1 + 0x548);
  local_43 = *(undefined2 *)(param_1 + 0x549);
  local_44 = local_40 | local_41 << 4;
  haptic_hv_i2c_writes(param_1,0x7d,&local_44,3);
  haptic_hv_i2c_reads(param_1,2,local_48,1);
  _printk(&DAT_00133f37,"haptic_hv",0x26,"aw869x_play_go",1);
  haptic_hv_i2c_write_bits(param_1,5,0xfffffffe,1);
  uVar5 = ktime_get();
  uVar1 = *(uint *)(param_1 + 0x74);
  *(undefined8 *)(param_1 + 0x268) = uVar5;
  if (uVar1 == 0) {
    _printk(&DAT_00131788,"haptic_hv",0x428,"aw869x_get_f0");
    uVar5 = 0xffffffde;
  }
  else {
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 10000 / uVar1;
    }
    iVar7 = uVar2 * ((uint)local_40 + (uint)local_41 +
                    ((byte)local_43 - 1) * ((uint)local_43._1_1_ + (uint)local_40)) * 1000;
    usleep_range_state(iVar7,iVar7 + 500,2);
    iVar7 = -100;
    do {
      local_3c[0] = local_3c[0] & 0xff00;
      haptic_hv_i2c_reads(param_1,0x46,local_3c,1);
      if ((local_3c[0] & 0xf) == 0) {
        puVar6 = &DAT_00136940;
        uVar5 = 0x16d;
        goto LAB_00107374;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar4 = iVar7 != -1;
      iVar7 = iVar7 + 1;
    } while (bVar4);
    puVar6 = &DAT_00137ca1;
    uVar5 = 0x173;
LAB_00107374:
    _printk(puVar6,"haptic_hv",uVar5,"aw869x_wait_enter_standby");
    local_3c[0] = 0;
    haptic_hv_i2c_reads(param_1,0x68,local_3c,2);
    uVar1 = ((uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8) * *(int *)(param_1 + 0x54c);
    if (uVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      _printk(&DAT_00132236,"haptic_hv",0x346,"aw869x_read_f0");
      uVar5 = 0xffffffde;
    }
    else {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = 1000000000 / uVar1;
      }
      *(uint *)(param_1 + 100) = uVar2;
      _printk(&DAT_00136043,"haptic_hv",0x34a,"aw869x_read_f0");
      uVar5 = 0;
    }
    local_3c[0] = local_3c[0] & 0xff00;
    haptic_hv_i2c_reads(param_1,0x6d,local_3c,1);
    *(undefined1 *)(param_1 + 0xd) = (undefined1)local_3c[0];
    haptic_hv_i2c_reads(param_1,0x6f,local_3c,1);
    *(undefined1 *)(param_1 + 0xe) = (undefined1)local_3c[0];
    _printk(&DAT_00132261,"haptic_hv",0x362,"aw869x_read_beme",*(undefined1 *)(param_1 + 0xd));
    _printk(&DAT_001373ad,"haptic_hv",0x363,"aw869x_read_beme",*(undefined1 *)(param_1 + 0xe));
    haptic_hv_i2c_write_bits(param_1,0x48,0xfffffff3,8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// aw869x_ram_get_f0 @ 001074d4 size=60
// signature: undefined aw869x_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869x_ram_get_f0(void)

{
  _printk(&DAT_00132acd,"haptic_hv",0x43e,"aw869x_ram_get_f0");
  return 0xffffffde;
}



//------------------------------------------------------------
// aw869x_creat_node @ 00107514 size=96
// signature: undefined aw869x_creat_node(void)
// callers: []
//------------------------------------------------------------

int aw869x_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw869x_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_00134bdf,"haptic_hv",0x5ef,"aw869x_creat_node");
  }
  return iVar1;
}



//------------------------------------------------------------
// aw869x_offset_cali @ 00107578 size=244
// signature: undefined aw869x_offset_cali(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869x_offset_cali(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  undefined8 uVar4;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0x20);
  usleep_range_state(1000,0x41a,2);
  haptic_hv_i2c_write_bits(param_1,0x5f,0xfffffffe,1);
  uVar3 = 0xfffff82f;
  do {
    bVar2 = 0xfffffffe < uVar3;
    uVar3 = uVar3 + 1;
    if (bVar2) {
      _printk(&DAT_00134c10,"haptic_hv",0x266,"aw869x_offset_cali");
      uVar4 = 0xffffffde;
      goto LAB_00107600;
    }
    haptic_hv_i2c_reads(param_1,0x5f,local_2c,1);
  } while ((local_2c[0] & 1) != 0);
  uVar4 = 0;
LAB_00107600:
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// aw869x_get_irq_state @ 00107670 size=460
// signature: undefined aw869x_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_34 [4];
  undefined1 local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  local_30[0] = 0;
  local_34[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_34,1);
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  haptic_hv_i2c_reads(param_1,0x30,local_30,1);
  if ((local_2c[0] >> 6 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    _printk(&DAT_001373ce,"haptic_hv",0x4b6,"aw869x_get_irq_state");
    uVar2 = 9;
  }
  if (((local_2c[0] & local_34[0]) >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x4ba,"aw869x_get_irq_state");
    uVar2 = 5;
  }
  if ((local_2c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x4be,"aw869x_get_irq_state");
    uVar2 = 6;
  }
  if ((local_2c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x4c2,"aw869x_get_irq_state");
    uVar2 = 7;
  }
  if ((local_2c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",0x4c6,"aw869x_get_irq_state");
    uVar2 = 10;
  }
  if ((local_2c[0] >> 3 & 1) != 0) {
    _printk(&DAT_0013605e,"haptic_hv",0x4ca,"aw869x_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_2c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw869x_check_qualify @ 00107840 size=60
// signature: undefined aw869x_check_qualify(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869x_check_qualify(void)

{
  _printk(&DAT_00132e8a,"haptic_hv",0x11,"aw869x_check_qualify");
  return 0;
}



//------------------------------------------------------------
// aw869x_judge_rtp_going @ 00107880 size=152
// signature: undefined aw869x_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw869x_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  bVar2 = (local_1c[0] & 5) == 4;
  if (bVar2) {
    _printk(&DAT_00134c3c,"haptic_hv",0x189,"aw869x_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw869x_container_update @ 0010791c size=816
// signature: undefined aw869x_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869x_container_update(long param_1,int *param_2)

{
  byte *pbVar1;
  long lVar2;
  ushort uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte local_45c;
  byte local_45b;
  byte local_45a;
  byte local_459;
  char local_458 [1024];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  memset(local_458,0,0x400);
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0x20);
  usleep_range_state(1000,0x41a,2);
  pbVar1 = (byte *)((long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4);
  uVar3 = CONCAT11(*pbVar1,pbVar1[1]);
  local_45c = *pbVar1 >> 1;
  local_45b = (byte)(uVar3 >> 1);
  iVar6 = (uint)uVar3 - (uint)(uVar3 >> 2);
  *(uint *)(param_1 + 0x520) = (uint)uVar3;
  local_45a = (byte)((uint)iVar6 >> 8);
  local_459 = (byte)iVar6;
  _printk(&DAT_00137cd5,"haptic_hv",0x6f,"aw869x_container_update");
  haptic_hv_i2c_writes(param_1,0x21,pbVar1,2);
  haptic_hv_i2c_writes(param_1,0x23,&local_45c,4);
  haptic_hv_i2c_reads(param_1,0x23,&local_45c,4);
  _printk(&DAT_001344e9,"haptic_hv",0x75,"aw869x_container_update",
          (uint)local_45b | (local_45c & 0xf) << 8);
  _printk(&DAT_001351c2,"haptic_hv",0x77,"aw869x_container_update",
          (uint)local_459 | (local_45a & 0xf) << 8);
  haptic_hv_i2c_writes(param_1,0x40,(long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4,2);
  uVar8 = (uint)*(byte *)(param_1 + 0x526);
  iVar6 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar6) {
    do {
      iVar9 = iVar6 - uVar8;
      if (0x7ff < iVar9) {
        iVar9 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar8 + 4,iVar9);
      iVar6 = *param_2;
      uVar8 = iVar9 + uVar8;
    } while ((int)uVar8 < iVar6);
  }
  haptic_hv_i2c_writes(param_1,0x40,(long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4,2);
  uVar8 = (uint)*(byte *)(param_1 + 0x526);
  iVar6 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar6) {
    do {
      uVar10 = iVar6 - uVar8;
      if (0x3ff < (int)uVar10) {
        uVar10 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,local_458,uVar10);
      if (uVar10 != 0) {
        uVar5 = 0;
        do {
          if (0x3ff < uVar5) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x107c48);
            (*pcVar4)();
          }
          if (local_458[(int)uVar5] !=
              *(char *)((long)param_2 + (long)(int)uVar5 + (long)(int)uVar8 + 4)) {
            _printk(&DAT_001373f1,"haptic_hv",0x4b,"aw869x_check_ram_data");
            _printk(&DAT_001351ee,"haptic_hv",0x97,"aw869x_container_update");
            uVar7 = 0xffffffde;
            goto LAB_00107bf0;
          }
          uVar5 = uVar5 + 1;
        } while (uVar10 != uVar5);
      }
      iVar6 = *param_2;
      uVar8 = uVar10 + uVar8;
    } while ((int)uVar8 < iVar6);
  }
  _printk(&DAT_00132afb,"haptic_hv",0x99,"aw869x_container_update");
  uVar7 = 0;
LAB_00107bf0:
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0);
  mutex_unlock(param_1 + 0x350);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// aw869x_stop @ 00107c50 size=296
// signature: undefined aw869x_stop(void)
// callers: [aw869x_get_f0, aw869x_get_vbat, aw869x_get_lra_resistance]
//------------------------------------------------------------

void aw869x_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  undefined *puVar3;
  undefined8 uVar4;
  int iVar5;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  *(undefined1 *)(param_1 + 0xb) = 0;
  aw869x_play_go(param_1,0);
  iVar5 = -100;
  do {
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,0x46,local_2c,1);
    if ((local_2c[0] & 0xf) == 0) {
      puVar3 = &DAT_00136940;
      uVar4 = 0x16d;
      goto LAB_00107cfc;
    }
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar5 != -1;
    iVar5 = iVar5 + 1;
  } while (bVar2);
  puVar3 = &DAT_00137ca1;
  uVar4 = 0x173;
LAB_00107cfc:
  _printk(puVar3,"haptic_hv",uVar4,"aw869x_wait_enter_standby");
  _printk(&DAT_00134895,"haptic_hv",0xd3,"aw869x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 0;
  haptic_hv_i2c_write_bits(param_1,3,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,4,0xfffffffe,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_get_vbat @ 00107d7c size=312
// signature: undefined aw869x_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_vbat(long param_1)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  byte local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = 0;
  aw869x_stop();
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0x20);
  usleep_range_state(1000,0x41a,2);
  haptic_hv_i2c_write_bits(param_1,0x5f,0xfffffffd,2);
  iVar4 = -2000;
  do {
    haptic_hv_i2c_reads(param_1,0x5f,local_2c,1);
    if ((local_2c[0] >> 1 & 1) == 0) break;
    bVar1 = iVar4 != 0;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  haptic_hv_i2c_reads(param_1,0x62,local_2c,1);
  uVar5 = (uint)local_2c[0] * 0x17d4 >> 8;
  if (uVar5 < 0xbb9) {
    uVar5 = 3000;
  }
  uVar2 = 0x1194;
  if ((uint)local_2c[0] * 0x17d4 < 0x119500) {
    uVar2 = uVar5;
  }
  *(uint *)(param_1 + 0x70) = uVar2;
  _printk(&DAT_00134516,"haptic_hv",0x303,"aw869x_get_vbat");
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_cont_config @ 00107eb8 size=368
// signature: undefined aw869x_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw869x_cont_config(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  ushort local_30 [2];
  ushort local_2c [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38[0] = 0x23;
  aw869x_play_mode(param_1,4);
  haptic_hv_i2c_write_bits(param_1,0x2b,0xffffff9f,0xe0);
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff00,0x89);
  local_2c[0] = *(ushort *)(param_1 + 0x550) >> 8 | *(ushort *)(param_1 + 0x550) << 8;
  haptic_hv_i2c_writes(param_1,0x4b,local_2c,2);
  haptic_hv_i2c_writes(param_1,0x4d,param_1 + 0x538,1);
  local_30[0] = *(ushort *)(param_1 + 0x554) >> 8 | *(ushort *)(param_1 + 0x554) << 8;
  haptic_hv_i2c_writes(param_1,0x72,local_30,2);
  haptic_hv_i2c_write_bits(param_1,0x78,0xfffffff0,*(undefined1 *)(param_1 + 0x53b));
  haptic_hv_i2c_writes(param_1,0x7a,local_38,1);
  local_34 = *(undefined1 *)(param_1 + 0x53a);
  local_33 = *(undefined1 *)(param_1 + 0x53c);
  haptic_hv_i2c_writes(param_1,0x7b,&local_34,2);
  _printk(&DAT_00133f37,"haptic_hv",0x26,"aw869x_play_go",1);
  haptic_hv_i2c_write_bits(param_1,5,0xfffffffe,1);
  uVar1 = ktime_get();
  lVar2 = sp_el0;
  lVar2 = *(long *)(lVar2 + 0x638);
  *(undefined8 *)(param_1 + 0x268) = uVar1;
  if (lVar2 != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_play_go @ 0010802c size=244
// signature: undefined aw869x_play_go(void)
// callers: [aw869x_stop]
//------------------------------------------------------------

void aw869x_play_go(uint *param_1,uint param_2)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined8 uVar3;
  long lVar4;
  
  _printk(&DAT_00133f37,"haptic_hv",0x26,"aw869x_play_go",param_2 & 1);
  if ((param_2 & 1) == 0) {
    lVar4 = ktime_get();
    *(long *)(param_1 + 0x98) = lVar4;
    auVar2 = SEXT816(lVar4 - *(long *)(param_1 + 0x9a)) * SEXT816(0x20c49ba5e353f7cf);
    uVar1 = (int)(auVar2._8_8_ >> 7) - (auVar2._12_4_ >> 0x1f);
    *param_1 = uVar1;
    if (uVar1 < 2000) {
      _printk(&DAT_00133174,"haptic_hv",0x30,"aw869x_play_go");
      usleep_range_state(2000,0x9c4,2);
    }
    haptic_hv_i2c_write_bits(param_1,5,0xfffffffe,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,5,0xfffffffe,1);
    uVar3 = ktime_get();
    *(undefined8 *)(param_1 + 0x9a) = uVar3;
  }
  return;
}



//------------------------------------------------------------
// aw869x_ram_init @ 00108124 size=80
// signature: undefined aw869x_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw869x_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0x20);
    usleep_range_state(1000,0x41a,2);
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_bst_peak_cur @ 00108178 size=152
// signature: undefined aw869x_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_bst_peak_cur(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 10) == '\x01') {
    _printk(&DAT_001317fd,"haptic_hv",0x20f,"aw869x_set_bst_peak_cur");
    uVar1 = 5;
  }
  else {
    if (*(char *)(param_1 + 10) == '\0') {
      uVar1 = 0x209;
    }
    else {
      uVar1 = 0x215;
    }
    _printk(&DAT_001337fc,"haptic_hv",uVar1,"aw869x_set_bst_peak_cur");
    uVar1 = 1;
  }
  haptic_hv_i2c_write_bits(param_1,0x34,0xfffffff8,uVar1);
  return;
}



//------------------------------------------------------------
// aw869x_get_lra_resistance @ 00108214 size=336
// signature: undefined aw869x_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_lra_resistance(long param_1)

{
  long lVar1;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  aw869x_stop();
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0x20);
  usleep_range_state(1000,0x41a,2);
  haptic_hv_i2c_write_bits(param_1,4,0xfffffffd,0);
  haptic_hv_i2c_write_bits(param_1,0x36,0xfffffff7,0);
  haptic_hv_i2c_write_bits(param_1,0x5e,0xffffff1f,0x60);
  haptic_hv_i2c_write_bits(param_1,0x5f,0xffffffbe,0x41);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_reads(param_1,0x60,local_2c,1);
  *(uint *)(param_1 + 0x6c) = (uint)local_2c[0] * 0x12a;
  haptic_hv_i2c_write_bits(param_1,0x36,0xfffffff7,8);
  haptic_hv_i2c_write_bits(param_1,0x5e,0xffffff1f,0x20);
  haptic_hv_i2c_write_bits(param_1,4,0xfffffffd,2);
  haptic_hv_i2c_write_bits(param_1,4,0xffffffdf,0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_pwm @ 00108368 size=68
// signature: undefined aw869x_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_pwm(undefined8 param_1,uint param_2)

{
  if ((param_2 & 0xff) < 3) {
    haptic_hv_i2c_write_bits(param_1,0x2e,0xffffff9f,0x604000 >> (ulong)((param_2 & 3) << 3));
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_gain @ 001083b0 size=88
// signature: undefined aw869x_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,0x39,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_play_mode @ 0010840c size=1100
// signature: undefined aw869x_play_mode(void)
// callers: [aw869x_get_f0, aw869x_cont_config]
//------------------------------------------------------------

void aw869x_play_mode(long param_1,undefined1 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0xd3,"aw869x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    haptic_hv_i2c_write_bits(param_1,3,0xffffffdf,0x20);
    uVar2 = 4;
    uVar3 = 0xfffffffe;
    uVar4 = 1;
    break;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",0xdd,"aw869x_play_mode");
    uVar5 = 1;
    goto LAB_001085c8;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x10e,"aw869x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,4,0xfffffff1,4);
    if (*(char *)(param_1 + 0xc) != '\0') {
      haptic_hv_i2c_write_bits(param_1,0x47,0xfffffffd,0);
    }
    haptic_hv_i2c_write_bits(param_1,4,0xfffffffe,0);
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,2,local_2c,1);
    haptic_hv_i2c_write_bits(param_1,3,0xffffffdf,0);
    if (*(char *)(param_1 + 0xc) == '\0') goto LAB_001086ac;
    uVar2 = 0xfffffffd;
    uVar3 = 2;
    goto LAB_00108654;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x12f,"aw869x_play_mode");
    uVar5 = 3;
LAB_001085c8:
    *(undefined1 *)(param_1 + 0xb) = uVar5;
    haptic_hv_i2c_write_bits(param_1,4,0xfffffff1,0);
    if (*(char *)(param_1 + 0xc) != '\0') {
      haptic_hv_i2c_write_bits(param_1,0x47,0xfffffffe,0);
    }
    haptic_hv_i2c_write_bits(param_1,4,0xfffffffe,0);
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,2,local_2c,1);
    haptic_hv_i2c_write_bits(param_1,3,0xffffffdf,0);
    if (*(char *)(param_1 + 0xc) == '\0') {
LAB_001086ac:
      uVar2 = 4;
      uVar3 = 0xfffffffd;
      uVar4 = 2;
    }
    else {
      uVar2 = 0xfffffffe;
      uVar3 = 1;
LAB_00108654:
      haptic_hv_i2c_write_bits(param_1,0x47,uVar2,uVar3);
      haptic_hv_i2c_write_bits(param_1,4,0xfffffffc,3);
      haptic_hv_i2c_write_bits(param_1,4,0xfffffffe,0);
      local_2c[0] = 0;
      haptic_hv_i2c_reads(param_1,2,local_2c,1);
      uVar2 = 3;
      uVar3 = 0xffffffdf;
      uVar4 = 0;
    }
    haptic_hv_i2c_write_bits(param_1,uVar2,uVar3,uVar4);
    usleep_range_state(2000,0x9c4,2);
LAB_00108818:
    uVar2 = 0x66;
    uVar3 = 0xffffffbf;
    uVar4 = 0;
    break;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x150,"aw869x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 4;
    haptic_hv_i2c_write_bits(param_1,4,0xfffffff1,8);
    if (*(char *)(param_1 + 0xc) != '\0') {
      haptic_hv_i2c_write_bits(param_1,0x47,0xfffffffe,0);
    }
    haptic_hv_i2c_write_bits(param_1,4,0xfffffffe,0);
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,2,local_2c,1);
    haptic_hv_i2c_write_bits(param_1,3,0xffffffdf,0);
    uVar2 = 0x66;
    uVar3 = 0xffffffbf;
    uVar4 = 0x40;
    break;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0xfd,"aw869x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 5;
    haptic_hv_i2c_write_bits(param_1,4,0xfffffff1,0);
    if (*(char *)(param_1 + 0xc) != '\0') {
      haptic_hv_i2c_write_bits(param_1,0x47,0xfffffffe,0);
    }
    haptic_hv_i2c_write_bits(param_1,4,0xfffffffe,0);
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,2,local_2c,1);
    haptic_hv_i2c_write_bits(param_1,3,0xffffffdf,0);
    goto LAB_00108818;
  default:
    _printk(&DAT_00135993,"haptic_hv",0x160,"aw869x_play_mode");
    goto LAB_0010882c;
  }
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar3,uVar4);
LAB_0010882c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_bst_vol @ 0010885c size=96
// signature: undefined aw869x_set_bst_vol(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_bst_vol(undefined8 param_1,ulong param_2)

{
  uint uVar1;
  
  if (((uint)(param_2 >> 4) & 0xfffffff) < 0x177) {
    uVar1 = 0;
  }
  else {
    uVar1 = (uint)param_2;
    if (0x2903 < uVar1) {
      uVar1 = 0x2904;
    }
    uVar1 = (uVar1 - 6000 & 0xffff) / 0x47 & 0x3fe;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffffc1,uVar1);
  return;
}



//------------------------------------------------------------
// aw869x_set_repeat_seq @ 001088c0 size=120
// signature: undefined aw869x_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0xf,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_auto_bst_enable @ 0010893c size=52
// signature: undefined aw869x_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw869x_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,0x47,0xfffffffb,(ulong)(param_2 != '\0') << 2);
  return;
}



//------------------------------------------------------------
// aw869x_vbat_mode_config @ 00108974 size=52
// signature: undefined aw869x_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw869x_vbat_mode_config(undefined8 param_1,char param_2)

{
  haptic_hv_i2c_write_bits(param_1,0x66,0xffffffbf,(ulong)(param_2 == '\x01') << 6);
  return;
}



//------------------------------------------------------------
// aw869x_set_wav_seq @ 001089ac size=88
// signature: undefined aw869x_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_wav_loop @ 00108a08 size=64
// signature: undefined aw869x_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0xf,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw869x_set_rtp_data @ 00108a4c size=40
// signature: undefined aw869x_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,6,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw869x_protect_config @ 00108a78 size=256
// signature: undefined aw869x_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw869x_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x2d,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x24c,"aw869x_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x3e,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",0x246,"aw869x_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x3e,local_40,1);
    haptic_hv_i2c_writes(param_1,0x3f,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_parse_dt @ 00108b7c size=1284
// signature: undefined aw869x_parse_dt(void)
// callers: []
//------------------------------------------------------------

void aw869x_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined2 local_5c;
  undefined1 local_5a;
  undefined8 local_58;
  undefined4 local_50;
  undefined2 local_4c;
  undefined7 uStack_48;
  undefined1 local_41;
  undefined7 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  local_50 = 0;
  local_58 = 0;
  local_5a = 0;
  local_5c = 0;
  uStack_40 = 0;
  uStack_48 = 0;
  local_41 = 0;
  iVar2 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x4e2,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_f0_cali_percent",param_2 + 0x529,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_0013697e,"haptic_hv",0x4e5,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_cont_drv_lev",param_2 + 0x53a,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_00137d0f,"haptic_hv",0x4e8,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_cont_drv_lvl_ov",param_2 + 0x53c,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_001360a7,"haptic_hv",0x4eb,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u32_array(param_3,"aw869x_cont_td",param_2 + 0x550,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_0013781d,"haptic_hv",0x4ee,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u32_array(param_3,"aw869x_cont_zc_thr",param_2 + 0x554,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_001359b5,"haptic_hv",0x4f1,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_cont_num_brk",param_2 + 0x53b,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_00136358,"haptic_hv",0x4f4,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u32_array(param_3,"aw869x_f0_coeff",param_2 + 0x54c,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_001360d9,"haptic_hv",0x4f7,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_duration_time",&local_5c,3,0);
  if (iVar2 < 0) {
    _printk(&DAT_0013230b,"haptic_hv",0x4fb,"aw869x_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_5c;
    *(undefined1 *)(param_2 + 0x52c) = local_5a;
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_tset",param_2 + 0x538,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_0013283a,"haptic_hv",0x500,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_r_spare",param_2 + 0x539,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_00131b0a,"haptic_hv",0x503,"aw869x_parse_dt");
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_bstdbg",&local_50,6,0);
  if (iVar2 < 0) {
    _printk(&DAT_00134250,"haptic_hv",0x506,"aw869x_parse_dt");
  }
  else {
    *(undefined4 *)(param_2 + 0x53d) = local_50;
    *(undefined2 *)(param_2 + 0x541) = local_4c;
  }
  iVar2 = of_property_read_variable_u8_array
                    (param_3,"aw869x_f0_trace_parameter",(long)&local_58 + 4,4,0);
  if (iVar2 < 0) {
    _printk(&DAT_001331c7,"haptic_hv",0x50c,"aw869x_parse_dt");
  }
  else {
    *(undefined4 *)(param_2 + 0x547) = local_58._4_4_;
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_bemf_config",&local_58,4,0);
  if (iVar2 < 0) {
    _printk(&DAT_001370f6,"haptic_hv",0x513,"aw869x_parse_dt");
  }
  else {
    *(undefined4 *)(param_2 + 0x543) = (undefined4)local_58;
  }
  iVar2 = of_property_read_variable_u8_array(param_3,"aw869x_trig_config",&uStack_48,0xf,0);
  if (iVar2 < 0) {
    _printk(&DAT_00135c9a,"haptic_hv",0x519,"aw869x_parse_dt");
  }
  else {
    *(ulong *)(param_2 + 0x570) = CONCAT71(uStack_40,local_41);
    *(ulong *)(param_2 + 0x569) = CONCAT17(local_41,uStack_48);
  }
  iVar2 = of_property_read_variable_u32_array(param_3,"aw869x_bst_vol_default",param_2 + 0x534,1,0);
  if (iVar2 < 0) {
    _printk(&DAT_00133503,"haptic_hv",0x51e,"aw869x_parse_dt");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_trig_init @ 00109084 size=412
// signature: undefined aw869x_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw869x_trig_init(long param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  long lVar4;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  _printk(&DAT_0013233b,"haptic_hv",0x48e,"aw869x_trig_init");
  cVar2 = *(char *)(param_1 + 0x56a);
  *(char *)(param_1 + 0x6c4) = cVar2;
  *(undefined2 *)(param_1 + 0x6c2) = *(undefined2 *)(param_1 + 0x56c);
  *(undefined2 *)(param_1 + 0x6cf) = *(undefined2 *)(param_1 + 0x571);
  *(undefined1 *)(param_1 + 0x6c0) = *(undefined1 *)(param_1 + 0x569);
  *(char *)(param_1 + 0x6d1) = *(char *)(param_1 + 0x56f);
  bVar3 = (cVar2 != '\0') << 1;
  if (*(char *)(param_1 + 0x56f) != '\0') {
    bVar3 = (cVar2 != '\0') << 1 | 8;
  }
  *(undefined1 *)(param_1 + 0x6cd) = *(undefined1 *)(param_1 + 0x56e);
  if (*(char *)(param_1 + 0x574) != '\0') {
    bVar3 = bVar3 | 0x20;
  }
  *(undefined1 *)(param_1 + 0x6da) = *(undefined1 *)(param_1 + 0x573);
  *(char *)(param_1 + 0x6c1) = *(char *)(param_1 + 0x56b);
  bVar3 = bVar3 | *(char *)(param_1 + 0x56b) == '\0';
  bVar1 = bVar3 | 4;
  if (*(char *)(param_1 + 0x570) != '\0') {
    bVar1 = bVar3;
  }
  *(char *)(param_1 + 0x6ce) = *(char *)(param_1 + 0x570);
  bVar3 = bVar1 | 0x10;
  if (*(char *)(param_1 + 0x575) != '\0') {
    bVar3 = bVar1;
  }
  *(char *)(param_1 + 0x6de) = *(char *)(param_1 + 0x574);
  *(char *)(param_1 + 0x6db) = *(char *)(param_1 + 0x575);
  *(undefined2 *)(param_1 + 0x6dc) = *(undefined2 *)(param_1 + 0x576);
  haptic_hv_i2c_write_bits(param_1,0x1b,0xffffffc0,bVar3);
  local_30 = *(undefined1 *)(param_1 + 0x6c2);
  local_2f = *(undefined1 *)(param_1 + 0x6cf);
  local_2e = *(undefined1 *)(param_1 + 0x6dc);
  local_2d = *(undefined1 *)(param_1 + 0x6c3);
  local_2c = *(undefined1 *)(param_1 + 0x6d0);
  local_2b = *(undefined1 *)(param_1 + 0x6dd);
  haptic_hv_i2c_writes(param_1,0x14,&local_30,6);
  haptic_hv_i2c_write_bits
            (param_1,0x1c,0xfffffff8,
             (uint)*(byte *)(param_1 + 0x6c0) | (uint)*(byte *)(param_1 + 0x6cd) << 1 |
             (uint)*(byte *)(param_1 + 0x6da) << 2);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_irq_clear @ 00109224 size=88
// signature: undefined aw869x_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw869x_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_ram_addr @ 00109280 size=100
// signature: undefined aw869x_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_ram_addr(long param_1)

{
  long lVar1;
  ushort local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_misc_para_init @ 001092e8 size=492
// signature: undefined aw869x_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw869x_misc_para_init(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined1 local_38 [4];
  ushort local_34 [2];
  undefined8 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  if (*(int *)(param_1 + 0x534) != 0) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x534);
  }
  haptic_hv_i2c_reads(param_1,0x39,&local_30,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_30;
  haptic_hv_i2c_reads(param_1,7,&local_30,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_30;
  *(undefined8 *)(param_1 + 0x11) = local_30;
  haptic_hv_i2c_writes(param_1,0x31,param_1 + 0x53d,3);
  haptic_hv_i2c_writes(param_1,0x4d,param_1 + 0x538,1);
  haptic_hv_i2c_writes(param_1,0x5d,param_1 + 0x539,1);
  haptic_hv_i2c_write_bits(param_1,0x35,0xfffffff3,0xc);
  haptic_hv_i2c_write_bits(param_1,0x36,0xffffffdf,0x20);
  haptic_hv_i2c_writes(param_1,0x74,param_1 + 0x543,4);
  iVar1 = *(int *)(param_1 + 0x530);
  *(int *)(param_1 + 0x74) = iVar1;
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x54c) == 0)) {
    _printk(&DAT_00137d3e,"haptic_hv",0x449,"aw869x_set_pref0");
  }
  else {
    uVar2 = *(int *)(param_1 + 0x54c) * iVar1;
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = 1000000000 / uVar2;
    }
    local_34[0] = (ushort)(uVar3 >> 8) & 0xff | (ushort)((uVar3 & 0xff00ff) << 8);
    haptic_hv_i2c_writes(param_1,0x49,local_34,2);
  }
  local_34[0] = CONCAT11(local_34[0]._1_1_,0x12);
  haptic_hv_i2c_write_bits(param_1,0x2d,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",0x246,"aw869x_protect_config");
  local_38[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x3e,local_38,1);
  haptic_hv_i2c_writes(param_1,0x3f,local_34,1);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_interrupt_setup @ 001094d8 size=176
// signature: undefined aw869x_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw869x_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  _printk(&DAT_00136396,"haptic_hv",0x499,"aw869x_interrupt_setup",local_2c[0]);
  haptic_hv_i2c_write_bits(param_1,0x20,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff19,0xc0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_set_rtp_aei @ 0010958c size=48
// signature: undefined aw869x_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw869x_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw869x_upload_lra @ 001095c0 size=264
// signature: undefined aw869x_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw869x_upload_lra(long param_1,int param_2)

{
  long lVar1;
  undefined1 *puVar2;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  if (param_2 == 2) {
    _printk(&DAT_00137d74,"haptic_hv",0x39f,"aw869x_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    puVar2 = local_34;
    local_34[0] = (undefined1)*(undefined4 *)(param_1 + 0x9c);
  }
  else if (param_2 == 1) {
    _printk(&DAT_001369b0,"haptic_hv",0x39a,"aw869x_upload_lra",*(undefined4 *)(param_1 + 0x90));
    puVar2 = local_30;
    local_30[0] = (undefined1)*(undefined4 *)(param_1 + 0x90);
  }
  else {
    if (param_2 != 0) goto LAB_001095fc;
    _printk(&DAT_00136e0b,"haptic_hv",0x396,"aw869x_upload_lra");
    puVar2 = local_2c;
  }
  haptic_hv_i2c_writes(param_1,0x5b,puVar2,1);
LAB_001095fc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_get_wav_seq @ 001096cc size=236
// signature: undefined aw869x_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,7,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_get_ram_data @ 001097bc size=120
// signature: undefined aw869x_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw869x_bst_mode_config @ 00109838 size=200
// signature: undefined aw869x_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw869x_bst_mode_config(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    _printk(&DAT_00137d95,"haptic_hv",0xb3,"aw869x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,4,0xfffffffd,0);
  }
  else if (param_2 == '\x01') {
    _printk(&DAT_00137491,"haptic_hv",0xad,"aw869x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,4,0xfffffffd,2);
  }
  else {
    _printk(&DAT_00131828,"haptic_hv",0xb9,"aw869x_bst_mode_config",param_2);
  }
  return;
}



//------------------------------------------------------------
// aw869x_get_first_wave_addr @ 00109904 size=112
// signature: undefined aw869x_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869x_get_wav_loop @ 00109978 size=420
// signature: undefined aw869x_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw869x_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0xf,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw869x_get_reg @ 00109b20 size=284
// signature: undefined aw869x_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw869x_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_c8 [128];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_c8[0x70] = 0;
  local_c8[0x71] = 0;
  local_c8[0x72] = 0;
  local_c8[0x73] = 0;
  local_c8[0x74] = 0;
  local_c8[0x75] = 0;
  local_c8[0x76] = 0;
  local_c8[0x77] = 0;
  local_c8[0x78] = 0;
  local_c8[0x79] = 0;
  local_c8[0x7a] = 0;
  local_c8[0x7b] = 0;
  local_c8[0x7c] = 0;
  local_c8[0x7d] = 0;
  local_c8[0x7e] = 0;
  local_c8[0x7f] = 0;
  local_c8[0x60] = 0;
  local_c8[0x61] = 0;
  local_c8[0x62] = 0;
  local_c8[99] = 0;
  local_c8[100] = 0;
  local_c8[0x65] = 0;
  local_c8[0x66] = 0;
  local_c8[0x67] = 0;
  local_c8[0x68] = 0;
  local_c8[0x69] = 0;
  local_c8[0x6a] = 0;
  local_c8[0x6b] = 0;
  local_c8[0x6c] = 0;
  local_c8[0x6d] = 0;
  local_c8[0x6e] = 0;
  local_c8[0x6f] = 0;
  local_c8[0x50] = 0;
  local_c8[0x51] = 0;
  local_c8[0x52] = 0;
  local_c8[0x53] = 0;
  local_c8[0x54] = 0;
  local_c8[0x55] = 0;
  local_c8[0x56] = 0;
  local_c8[0x57] = 0;
  local_c8[0x58] = 0;
  local_c8[0x59] = 0;
  local_c8[0x5a] = 0;
  local_c8[0x5b] = 0;
  local_c8[0x5c] = 0;
  local_c8[0x5d] = 0;
  local_c8[0x5e] = 0;
  local_c8[0x5f] = 0;
  local_c8[0x40] = 0;
  local_c8[0x41] = 0;
  local_c8[0x42] = 0;
  local_c8[0x43] = 0;
  local_c8[0x44] = 0;
  local_c8[0x45] = 0;
  local_c8[0x46] = 0;
  local_c8[0x47] = 0;
  local_c8[0x48] = 0;
  local_c8[0x49] = 0;
  local_c8[0x4a] = 0;
  local_c8[0x4b] = 0;
  local_c8[0x4c] = 0;
  local_c8[0x4d] = 0;
  local_c8[0x4e] = 0;
  local_c8[0x4f] = 0;
  local_c8[0x30] = 0;
  local_c8[0x31] = 0;
  local_c8[0x32] = 0;
  local_c8[0x33] = 0;
  local_c8[0x34] = 0;
  local_c8[0x35] = 0;
  local_c8[0x36] = 0;
  local_c8[0x37] = 0;
  local_c8[0x38] = 0;
  local_c8[0x39] = 0;
  local_c8[0x3a] = 0;
  local_c8[0x3b] = 0;
  local_c8[0x3c] = 0;
  local_c8[0x3d] = 0;
  local_c8[0x3e] = 0;
  local_c8[0x3f] = 0;
  local_c8[0x20] = 0;
  local_c8[0x21] = 0;
  local_c8[0x22] = 0;
  local_c8[0x23] = 0;
  local_c8[0x24] = 0;
  local_c8[0x25] = 0;
  local_c8[0x26] = 0;
  local_c8[0x27] = 0;
  local_c8[0x28] = 0;
  local_c8[0x29] = 0;
  local_c8[0x2a] = 0;
  local_c8[0x2b] = 0;
  local_c8[0x2c] = 0;
  local_c8[0x2d] = 0;
  local_c8[0x2e] = 0;
  local_c8[0x2f] = 0;
  local_c8[0x10] = 0;
  local_c8[0x11] = 0;
  local_c8[0x12] = 0;
  local_c8[0x13] = 0;
  local_c8[0x14] = 0;
  local_c8[0x15] = 0;
  local_c8[0x16] = 0;
  local_c8[0x17] = 0;
  local_c8[0x18] = 0;
  local_c8[0x19] = 0;
  local_c8[0x1a] = 0;
  local_c8[0x1b] = 0;
  local_c8[0x1c] = 0;
  local_c8[0x1d] = 0;
  local_c8[0x1e] = 0;
  local_c8[0x1f] = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[6] = 0;
  local_c8[7] = 0;
  local_c8[8] = 0;
  local_c8[9] = 0;
  local_c8[10] = 0;
  local_c8[0xb] = 0;
  local_c8[0xc] = 0;
  local_c8[0xd] = 0;
  local_c8[0xe] = 0;
  local_c8[0xf] = 0;
  haptic_hv_i2c_reads(param_1,0,local_c8,6);
  haptic_hv_i2c_reads(param_1,7,(ulong)local_c8 | 7,0x3b);
  haptic_hv_i2c_reads(param_1,0x43,local_c8 + 0x43,0x3d);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 6) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_c8[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x80);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw869x_get_prctmode @ 00109c40 size=96
// signature: undefined aw869x_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw869x_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3e,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw869x_get_trim_lra @ 00109ca4 size=96
// signature: undefined aw869x_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

byte aw869x_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x5b,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0x3f;
}



//------------------------------------------------------------
// aw869x_get_glb_state @ 00109d08 size=92
// signature: undefined aw869x_get_glb_state(void)
// callers: []
//------------------------------------------------------------

void aw869x_get_glb_state(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x46,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw869x_osc_read_status @ 00109d68 size=96
// signature: undefined aw869x_osc_read_status(void)
// callers: []
//------------------------------------------------------------

byte aw869x_osc_read_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x30,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw869x_rtp_get_fifo_afs @ 00109dcc size=96
// signature: undefined aw869x_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw869x_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw869x_rtp_get_fifo_aes @ 00109e30 size=96
// signature: undefined aw869x_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw869x_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw869x_get_theory_time @ 00109e94 size=216
// signature: undefined aw869x_get_theory_time(void)
// callers: []
//------------------------------------------------------------

uint aw869x_get_theory_time(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x2e,local_2c,1);
  if ((local_2c[0] & 0x60) == 0) {
    uVar2 = 0x30;
  }
  else if ((local_2c[0] & 0x60) == 0x60) {
    uVar2 = 0xc;
  }
  else {
    if ((local_2c[0] & 0x60) != 0x40) {
      uVar3 = 0;
      goto LAB_00109f14;
    }
    uVar2 = 0x18;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    uVar3 = (uint)(*(int *)(param_1 + 0x7c) * 1000) / uVar2;
  }
LAB_00109f14:
  _printk(&DAT_00132875,"haptic_hv",0x3b7,"aw869x_get_theory_time",*(undefined8 *)(param_1 + 0xa0),
          uVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// cont_td_show @ 00109f70 size=60
// signature: undefined cont_td_show(void)
// callers: []
//------------------------------------------------------------

long cont_td_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"aw869x cont delay time = 0x%04x\n",
                   *(uint *)(*(long *)(param_1 + 0x98) + 0x4a8));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_td_store @ 00109fb0 size=160
// signature: undefined cont_td_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_td_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_30;
  ushort local_2c [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = kstrtouint(param_3,0,&local_30);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x4a8) = local_30;
    local_2c[0] = (ushort)local_30 >> 8 | (ushort)local_30 << 8;
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x4b,local_2c,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_show @ 0010a054 size=108
// signature: undefined cont_drv_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,"aw869x cont drv level = %d\n",(uint)*(byte *)(lVar2 + 0x492));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,"aw869x cont drv level overdrive= %d\n",
                   (uint)*(byte *)(lVar2 + 0x494));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// cont_drv_store @ 0010a0c4 size=180
// signature: undefined cont_drv_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_34;
  undefined1 local_33;
  uint local_30 [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30[0] = 0;
  local_30[1] = 0;
  iVar1 = sscanf(param_3,"%u %u",local_30,(uint *)((ulong)local_30 | 4));
  if (iVar1 == 2) {
    local_34 = (undefined1)local_30[0];
    *(undefined1 *)(lVar2 + 0x492) = local_34;
    local_33 = (undefined1)local_30[1];
    *(undefined1 *)(lVar2 + 0x494) = local_33;
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x7b,&local_34,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_num_brk_show @ 0010a17c size=60
// signature: undefined cont_num_brk_show(void)
// callers: []
//------------------------------------------------------------

long cont_num_brk_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"aw869x cont break num = %d\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x493));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_num_brk_store @ 0010a1bc size=152
// signature: undefined cont_num_brk_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_num_brk_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 == 0) {
    uVar2 = local_2c;
    if ((local_2c & 0xf8) != 0) {
      uVar2 = 7;
    }
    *(char *)(lVar3 + 0x493) = (char)uVar2;
    haptic_hv_i2c_write_bits(lVar3 + -0xa8,0x78,0xfffffff0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_zc_thr_show @ 0010a258 size=60
// signature: undefined cont_zc_thr_show(void)
// callers: []
//------------------------------------------------------------

long cont_zc_thr_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"aw869x cont zero cross thr = 0x%04x\n",
                   *(uint *)(*(long *)(param_1 + 0x98) + 0x4ac));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_zc_thr_store @ 0010a298 size=160
// signature: undefined cont_zc_thr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_zc_thr_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_30;
  ushort local_2c [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = kstrtouint(param_3,0,&local_30);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x4ac) = local_30;
    local_2c[0] = (ushort)local_30 >> 8 | (ushort)local_30 << 8;
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x72,local_2c,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// trig_show @ 0010a33c size=220
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: enable=%d, default_level=%d, dual_edge=%d, frist_seq=%d, second_seq=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x618),(uint)*(byte *)(lVar2 + 0x61c),
                   (uint)*(byte *)(lVar2 + 0x619),(uint)*(byte *)(lVar2 + 0x61a),
                   (uint)*(byte *)(lVar2 + 0x61b));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: enable=%d, default_level=%d, dual_edge=%d, frist_seq=%d, second_seq=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x625),(uint)*(byte *)(lVar2 + 0x629),
                   (uint)*(byte *)(lVar2 + 0x626),(uint)*(byte *)(lVar2 + 0x627),
                   (uint)*(byte *)(lVar2 + 0x628));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: enable=%d, default_level=%d, dual_edge=%d, frist_seq=%d, second_seq=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x632),(uint)*(byte *)(lVar2 + 0x636),
                   (uint)*(byte *)(lVar2 + 0x633),(uint)*(byte *)(lVar2 + 0x634),
                   (uint)*(byte *)(lVar2 + 0x635));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 0010a41c size=748
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  lVar11 = *(long *)(param_1 + 0x98);
  local_48 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_50 = 0;
  iVar7 = sscanf(param_3,"%u %u %u %u %u %u",(uint *)&local_50,(uint *)((ulong)&local_50 | 4),
                 (uint *)&local_48,(uint *)((long)&local_48 + 4),local_40,local_40 + 1);
  if (iVar7 != 6) goto LAB_0010a488;
  _printk(&DAT_001344a9,"haptic_hv",0x5bb,"trig_store",local_50 & 0xffffffff,local_50._4_4_,
          local_48 & 0xffffffff,local_48._4_4_,local_40[0],local_40[1]);
  if ((uint)local_50 < 4) {
    uVar8 = (uint)local_50;
    if ((uint)local_50 != 0) goto LAB_0010a504;
    uVar9 = 0;
    cVar3 = *(char *)(lVar11 + -0xa2);
  }
  else {
    uVar8 = 3;
LAB_0010a504:
    uVar9 = (ulong)(uVar8 - 1);
    local_50 = CONCAT44(local_50._4_4_,uVar8 - 1);
    cVar3 = *(char *)(lVar11 + -0xa2);
  }
  if (cVar3 == '\0') {
    _printk(&DAT_001325b9,"haptic_hv",0x5c1,"trig_store");
  }
  else if ((*(byte *)(lVar11 + 0x47c) < local_40[0]) || (*(byte *)(lVar11 + 0x47c) < local_40[1])) {
    _printk(&DAT_00133b4e,"haptic_hv",0x5c5,"trig_store");
  }
  else {
    lVar1 = lVar11 + 0x618;
    *(char *)(lVar1 + uVar9 * 0xd) = (char)(local_50 >> 0x20);
    if ((2 < (uint)local_50) ||
       (((*(char *)(lVar1 + (local_50 & 0xffffffff) * 0xd + 4) = (char)local_48, 2 < (uint)local_50
         || (*(char *)(lVar1 + (local_50 & 0xffffffff) * 0xd + 1) = (char)(local_48 >> 0x20),
            2 < (uint)local_50)) ||
        (*(char *)(lVar1 + (local_50 & 0xffffffff) * 0xd + 2) = (char)local_40[0],
        2 < (uint)local_50)))) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10a708);
      (*pcVar5)();
    }
    lVar10 = lVar11 + -0xa8;
    *(char *)(lVar1 + (local_50 & 0xffffffff) * 0xd + 3) = (char)local_40[1];
    mutex_lock(lVar11 + 0x2a8);
    bVar6 = *(char *)(lVar11 + 0x61c) != '\0';
    bVar4 = bVar6 << 1;
    if (*(char *)(lVar11 + 0x629) != '\0') {
      bVar4 = bVar6 << 1 | 8;
    }
    if (*(char *)(lVar11 + 0x636) != '\0') {
      bVar4 = bVar4 | 0x20;
    }
    bVar4 = bVar4 | *(char *)(lVar11 + 0x619) == '\0';
    bVar2 = bVar4 | 4;
    if (*(char *)(lVar11 + 0x626) != '\0') {
      bVar2 = bVar4;
    }
    bVar4 = bVar2 | 0x10;
    if (*(char *)(lVar11 + 0x633) != '\0') {
      bVar4 = bVar2;
    }
    haptic_hv_i2c_write_bits(lVar10,0x1b,0xffffffc0,bVar4);
    local_58 = *(undefined1 *)(lVar11 + 0x61a);
    local_57 = *(undefined1 *)(lVar11 + 0x627);
    local_56 = *(undefined1 *)(lVar11 + 0x634);
    local_55 = *(undefined1 *)(lVar11 + 0x61b);
    local_54 = *(undefined1 *)(lVar11 + 0x628);
    local_53 = *(undefined1 *)(lVar11 + 0x635);
    haptic_hv_i2c_writes(lVar10,0x14,&local_58,6);
    haptic_hv_i2c_write_bits
              (lVar10,0x1c,0xfffffff8,
               (uint)*(byte *)(lVar11 + 0x618) | (uint)*(byte *)(lVar11 + 0x625) << 1 |
               (uint)*(byte *)(lVar11 + 0x632) << 2);
    mutex_unlock(lVar11 + 0x2a8);
  }
LAB_0010a488:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw869xx_get_f0 @ 0010a70c size=952
// signature: undefined aw869xx_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_get_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  int iVar7;
  undefined8 uVar8;
  byte local_44 [4];
  undefined1 local_40;
  undefined2 local_3f;
  ushort local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_44[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw869xx_stop();
  haptic_hv_i2c_write_bits(param_1,0x49,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  _printk(&DAT_001331a6,"haptic_hv",0x2bd,"aw869xx_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00137d95,"haptic_hv",0x247,"aw869xx_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffbf,0);
  local_40 = 0xc;
  haptic_hv_i2c_writes(param_1,0x3c,&local_40,1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xffffff7f,0x80);
  haptic_hv_i2c_write_bits(param_1,0x18,0xfffffff7,8);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_reads(param_1,8,local_44,1);
  bVar4 = local_44[0];
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  local_40 = *(undefined1 *)(param_1 + 0x563);
  local_3f = *(undefined2 *)(param_1 + 0x566);
  haptic_hv_i2c_writes(param_1,0x1e,&local_40,3);
  if (*(char *)(param_1 + 0x568) == '\0') {
    _printk(&DAT_00136e47,"haptic_hv",0x4e8,"aw869xx_get_f0");
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  else {
    haptic_hv_i2c_writes(param_1,0x22,param_1 + 0x568,1);
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  if (uVar1 == 0) {
    uVar8 = 0xffffffde;
  }
  else {
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 240000 / uVar1;
    }
    iVar7 = (uVar2 - ((uint)*(byte *)(param_1 + 0x565) + (uint)*(byte *)(param_1 + 0x568))) + -8;
    if (0xfe < iVar7) {
      iVar7 = 0xff;
    }
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    local_40 = (undefined1)iVar7;
    haptic_hv_i2c_writes(param_1,0x1a,&local_40,1);
    aw869xx_play_go(param_1,1);
    usleep_range_state(20000,0x5014,2);
    iVar7 = -100;
    do {
      local_3c[0] = local_3c[0] & 0xff00;
      haptic_hv_i2c_reads(param_1,0x3f,local_3c,1);
      if ((((byte)local_3c[0] & 0xf) == 10) || ((local_3c[0] & 0xf) == 0)) {
        puVar6 = &DAT_00136940;
        uVar8 = 0x25b;
        goto LAB_0010aa0c;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar5 = iVar7 != -1;
      iVar7 = iVar7 + 1;
    } while (bVar5);
    puVar6 = &DAT_00137ca1;
    uVar8 = 0x261;
LAB_0010aa0c:
    _printk(puVar6,"haptic_hv",uVar8,"aw869xx_wait_enter_standby");
    local_3c[0] = 0;
    haptic_hv_i2c_reads(param_1,0x25,local_3c,2);
    uVar1 = (uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8;
    if (uVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      _printk(&DAT_00132236,"haptic_hv",0x4af,"aw869xx_read_f0");
      uVar8 = 0xffffffde;
    }
    else {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = 0x3a9800 / uVar1;
      }
      *(uint *)(param_1 + 100) = uVar2;
      _printk(&DAT_00136043,"haptic_hv",0x4b3,"aw869xx_read_f0");
      uVar8 = 0;
    }
    haptic_hv_i2c_write_bits(param_1,0x18,0xfffffff7,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,bVar4 & 4);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// aw869xx_ram_get_f0 @ 0010aac8 size=964
// signature: undefined aw869xx_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_ram_get_f0(long param_1)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  byte local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  byte local_40 [4];
  ushort local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_4c[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    puVar5 = &DAT_001325b9;
    uVar6 = 0x511;
  }
  else {
    if (4 < *(byte *)(param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
      aw869xx_stop(param_1);
      haptic_hv_i2c_write_bits(param_1,0x49,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
      _printk(&DAT_00136db2,"haptic_hv",0x297,"aw869xx_play_mode");
      *(undefined1 *)(param_1 + 0xb) = 1;
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,0);
      _printk(&DAT_00137491,"haptic_hv",0x241,"aw869xx_bst_mode_config");
      haptic_hv_i2c_write_bits(param_1,6,0xffffffbf,0x40);
      haptic_hv_i2c_write_bits(param_1,0x43,0xffffff7f,0);
      haptic_hv_i2c_write_bits(param_1,0x18,0xfffffff7,8);
      haptic_hv_i2c_reads(param_1,8,local_4c,1);
      bVar3 = local_4c[0];
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
      haptic_hv_i2c_write_bits(param_1,6,0xffffffc0,0x19);
      local_48[0] = 5;
      haptic_hv_i2c_writes(param_1,10,local_48,1);
      local_44[0] = 0;
      haptic_hv_i2c_writes(param_1,0xb,local_44,1);
      haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0x20);
      aw869xx_play_go(param_1,1);
      usleep_range_state(20000,0x5014,2);
      iVar10 = -100;
      do {
        local_40[0] = 0;
        haptic_hv_i2c_reads(param_1,0x3f,local_40,1);
        if (((local_40[0] & 0xf) == 10) || ((local_40[0] & 0xf) == 0)) {
          puVar5 = &DAT_00136940;
          uVar6 = 0x25b;
          goto LAB_0010ad48;
        }
        usleep_range_state(2000,0x9c4,2);
        bVar4 = iVar10 != -1;
        iVar10 = iVar10 + 1;
      } while (bVar4);
      puVar5 = &DAT_00137ca1;
      uVar6 = 0x261;
LAB_0010ad48:
      _printk(puVar5,"haptic_hv",uVar6,"aw869xx_wait_enter_standby");
      local_3c[0] = 0;
      haptic_hv_i2c_reads(param_1,0x25,local_3c,2);
      uVar9 = (uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8;
      if (uVar9 == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        _printk(&DAT_00132236,"haptic_hv",0x4af,"aw869xx_read_f0");
        uVar6 = 0xffffffde;
      }
      else {
        uVar1 = 0;
        if (uVar9 != 0) {
          uVar1 = 0x3a9800 / uVar9;
        }
        *(uint *)(param_1 + 100) = uVar1;
        _printk(&DAT_00136043,"haptic_hv",0x4b3,"aw869xx_read_f0");
        uVar6 = 0;
      }
      uVar9 = *(uint *)(param_1 + 0x38);
      if (uVar9 >> 4 < 0x177) {
        uVar7 = 0;
      }
      else {
        if (0x2ada < uVar9) {
          uVar9 = 0x2adb;
        }
        uVar7 = (ulong)(uVar9 * 1000 - 6000000) / 0x1342d;
      }
      haptic_hv_i2c_write_bits(param_1,6,0xffffffc0,uVar7);
      haptic_hv_i2c_write_bits(param_1,0x18,0xfffffff7,0);
      if ((bVar3 >> 2 & 1) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 4;
      }
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar8);
      goto LAB_0010ae58;
    }
    puVar5 = &DAT_00132b34;
    uVar6 = 0x515;
  }
  _printk(puVar5,"haptic_hv",uVar6,"aw869xx_ram_get_f0");
  uVar6 = 0xffffffde;
LAB_0010ae58:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// aw869xx_creat_node @ 0010ae90 size=96
// signature: undefined aw869xx_creat_node(void)
// callers: []
//------------------------------------------------------------

int aw869xx_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw869xx_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_00134bdf,"haptic_hv",0x7f2,"aw869xx_creat_node");
  }
  return iVar1;
}



//------------------------------------------------------------
// aw869xx_offset_cali @ 0010aef4 size=464
// signature: undefined aw869xx_offset_cali(void)
// callers: []
//------------------------------------------------------------

void aw869xx_offset_cali(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined2 local_2c;
  undefined1 local_2a;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  cVar1 = *(char *)(param_1 + 0x55d);
  local_2a = 0;
  local_2c = 0;
  if (cVar1 == '\0') {
    _printk(&DAT_00136555,"haptic_hv",0x5ef,"aw869xx_offset_cali");
    cVar1 = *(char *)(param_1 + 0x55d);
  }
  haptic_hv_i2c_write_bits(param_1,0x49,0xfffffff8,cVar1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffffe,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_reads(param_1,0x54,&local_2c,1);
  haptic_hv_i2c_reads(param_1,0x57,(ulong)&local_2c | 1,1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  if ((ulong)(long)*(char *)(param_1 + 0x55d) < 8) {
    iVar2 = 0;
    if (*(int *)(&DAT_00138080 + (long)*(char *)(param_1 + 0x55d) * 4) != 0) {
      iVar2 = (int)((local_2c._1_1_ >> 2 & 3 | (uint)(byte)local_2c << 2) * 0x988 + -0x131000) /
              *(int *)(&DAT_00138080 + (long)*(char *)(param_1 + 0x55d) * 4);
    }
    _printk(&DAT_00135670,"haptic_hv",0x600,"aw869xx_offset_cali",iVar2);
    if (0xffffffe0 < iVar2 - 0x10U) {
      uVar4 = 0;
      goto LAB_0010b078;
    }
    puVar5 = &DAT_00137a8c;
    uVar4 = 0x602;
  }
  else {
    puVar5 = &DAT_00135cd6;
    uVar4 = 0x5fb;
  }
  _printk(puVar5,"haptic_hv",uVar4,"aw869xx_offset_cali");
  uVar4 = 0xffffffde;
LAB_0010b078:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_get_irq_state @ 0010b0c8 size=440
// signature: undefined aw869xx_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  if ((char)local_1c[0] < '\0') {
    _printk(&DAT_00131b4f,"haptic_hv",0x484,"aw869xx_get_irq_state");
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  if ((local_1c[0] >> 6 & 1) != 0) {
    _printk(&DAT_001373ce,"haptic_hv",0x488,"aw869xx_get_irq_state");
    uVar2 = 4;
  }
  if ((local_1c[0] >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x48c,"aw869xx_get_irq_state");
    uVar2 = 5;
  }
  if ((local_1c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x490,"aw869xx_get_irq_state");
    uVar2 = 6;
  }
  if ((local_1c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x494,"aw869xx_get_irq_state");
    uVar2 = 7;
  }
  if ((local_1c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",0x498,"aw869xx_get_irq_state");
    uVar2 = 10;
  }
  if ((local_1c[0] >> 3 & 1) != 0) {
    _printk(&DAT_00131f9b,"haptic_hv",0x49c,"aw869xx_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_1c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_check_qualify @ 0010b284 size=192
// signature: undefined aw869xx_check_qualify(void)
// callers: []
//------------------------------------------------------------

void aw869xx_check_qualify(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  _printk(&DAT_00132e8a,"haptic_hv",399,"aw869xx_check_qualify");
  uVar2 = haptic_hv_i2c_reads(param_1,100,local_2c,1);
  if (-1 < (int)uVar2) {
    if (local_2c[0] < '\0') {
      uVar2 = 0;
    }
    else {
      _printk(&DAT_0013785a,"haptic_hv",0x195,"aw869xx_check_qualify");
      uVar2 = 0xffffffde;
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
// aw869xx_judge_rtp_going @ 0010b348 size=144
// signature: undefined aw869xx_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw869xx_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  bVar2 = local_1c[0] == '\b';
  if (bVar2) {
    _printk(&DAT_00134c3c,"haptic_hv",0x42c,"aw869xx_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_container_update @ 0010b3dc size=584
// signature: undefined aw869xx_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_container_update(long param_1,int *param_2)

{
  byte *pbVar1;
  uint uVar2;
  long lVar3;
  ushort uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 local_70;
  char local_6f;
  undefined1 local_6e;
  byte local_6d;
  undefined2 local_6c;
  byte local_6a;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_6a = 0;
  local_6c = 0;
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  aw869xx_stop(param_1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  pbVar1 = (byte *)((long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4);
  uVar4 = CONCAT11(*pbVar1,pbVar1[1]);
  local_70 = (undefined1)(uVar4 >> 1);
  uVar2 = (uint)uVar4 - (uint)(uVar4 >> 2);
  local_6f = pbVar1[1] - (char)(uVar4 >> 2);
  uVar7 = (*pbVar1 & 0xfe) << 3;
  local_6d = (byte)(uVar2 >> 8) & 0xf;
  *(uint *)(param_1 + 0x520) = (uint)uVar4;
  local_6e = (undefined1)uVar7;
  _printk(&DAT_00136e85,"haptic_hv",0x659,"aw869xx_container_update");
  haptic_hv_i2c_writes(param_1,0x2d,pbVar1,2);
  haptic_hv_i2c_write_bits(param_1,0x2f,0xffffff00,uVar7 | uVar2 >> 8 & 0xf);
  haptic_hv_i2c_writes(param_1,0x30,&local_70,2);
  haptic_hv_i2c_reads(param_1,0x2f,&local_6c,3);
  bVar5 = (byte)local_6c;
  _printk(&DAT_001344e9,"haptic_hv",0x663,"aw869xx_container_update",
          CONCAT11((byte)local_6c >> 4,local_6c._1_1_));
  _printk(&DAT_001351c2,"haptic_hv",0x665,"aw869xx_container_update",
          (uint)local_6a | (bVar5 & 0xf) << 8);
  haptic_hv_i2c_writes(param_1,0x40,(long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4,2);
  uVar7 = (uint)*(byte *)(param_1 + 0x526);
  iVar6 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar6) {
    do {
      iVar8 = iVar6 - uVar7;
      if (0x7ff < iVar8) {
        iVar8 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar7 + 4,iVar8);
      iVar6 = *param_2;
      uVar7 = iVar8 + uVar7;
    } while ((int)uVar7 < iVar6);
  }
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  mutex_unlock(param_1 + 0x350);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw869xx_stop @ 0010b628 size=432
// signature: undefined aw869xx_stop(void)
// callers: [aw869xx_get_lra_resistance, aw869xx_play_mode, aw869xx_container_update, aw869xx_get_f0, aw869xx_ram_get_f0, aw869xx_get_vbat]
//------------------------------------------------------------

void aw869xx_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x279,"aw869xx_stop");
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_30[0] = 1;
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,3);
  haptic_hv_i2c_writes(param_1,9,local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  iVar3 = -100;
  while( true ) {
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,0x3f,local_2c,1);
    if (((local_2c[0] & 0xf) == 0) || ((local_2c[0] & 0xf) == 10)) break;
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar3 == -1;
    iVar3 = iVar3 + 1;
    if (bVar2) {
      _printk(&DAT_00137ca1,"haptic_hv",0x261,"aw869xx_wait_enter_standby");
      _printk(&DAT_00135cf9,"haptic_hv",0x284,"aw869xx_stop");
      haptic_hv_i2c_write_bits(param_1,0x44,0xffffffbf,0x40);
      haptic_hv_i2c_write_bits(param_1,0x44,0xffffffbf,0);
LAB_0010b7ac:
      lVar1 = sp_el0;
      if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
  _printk(&DAT_00136940,"haptic_hv",0x25b,"aw869xx_wait_enter_standby");
  goto LAB_0010b7ac;
}



//------------------------------------------------------------
// aw869xx_get_vbat @ 0010b7dc size=436
// signature: undefined aw869xx_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_vbat(long param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  byte bVar6;
  int iVar7;
  byte local_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_2c[0] = 0;
  aw869xx_stop();
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffffd,2);
  iVar7 = -1999;
  do {
    haptic_hv_i2c_reads(param_1,0x52,local_2c,1);
    if ((local_2c[0] >> 1 & 1) == 0) break;
    bVar1 = iVar7 != 0;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  haptic_hv_i2c_reads(param_1,0x55,local_2c,1);
  bVar6 = local_2c[0];
  haptic_hv_i2c_reads(param_1,0x57,local_2c,1);
  uVar4 = local_2c[0] >> 4 & 3 | (uint)bVar6 << 2;
  uVar3 = uVar4 * 0x17d4;
  uVar2 = uVar3 >> 10;
  *(uint *)(param_1 + 0x70) = uVar2;
  if (0x4653ff < uVar3) {
    *(undefined4 *)(param_1 + 0x70) = 0x1194;
    _printk(&DAT_001328b9,"haptic_hv",0x5c9,"aw869xx_get_vbat",0x1194);
    uVar2 = *(uint *)(param_1 + 0x70);
  }
  if (uVar2 < 3000) {
    *(undefined4 *)(param_1 + 0x70) = 3000;
    _printk(&DAT_00135218,"haptic_hv",0x5cd,"aw869xx_get_vbat",3000);
    uVar2 = *(uint *)(param_1 + 0x70);
  }
  _printk(&DAT_00132353,"haptic_hv",0x5cf,"aw869xx_get_vbat",uVar2,uVar4);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_cont_config @ 0010b994 size=348
// signature: undefined aw869xx_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw869xx_cont_config(long param_1)

{
  long lVar1;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0xff;
  _printk(&DAT_001331a6,"haptic_hv",0x2bd,"aw869xx_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00137d95,"haptic_hv",0x247,"aw869xx_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffbf,0);
  local_2c[0] = 0xc;
  haptic_hv_i2c_writes(param_1,0x3c,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xffffff7f,0x80);
  haptic_hv_i2c_write_bits
            (param_1,0x1d,0xffffff00,
             (uint)*(byte *)(param_1 + 0x562) | (uint)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_writes(param_1,0x1e,param_1 + 0x563,1);
  haptic_hv_i2c_writes(param_1,0x20,local_30,1);
  aw869xx_play_go(param_1,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_play_go @ 0010baf4 size=260
// signature: undefined aw869xx_play_go(void)
// callers: [aw869xx_get_f0, aw869xx_cont_config, aw869xx_ram_get_f0]
//------------------------------------------------------------

void aw869xx_play_go(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 1;
  local_30[0] = 0x75;
  local_34[0] = 1;
  local_38[0] = 2;
  _printk(&DAT_00133f37,"haptic_hv",0x22a,"aw869xx_play_go",param_2 & 1);
  if ((param_2 & 1) == 0) {
    puVar3 = local_38;
  }
  else {
    if (*(char *)(param_1 + 0x58e) != '\0') {
      haptic_hv_i2c_writes(param_1,0x3c,local_2c,1);
      haptic_hv_i2c_writes(param_1,9,local_34,1);
      usleep_range_state(1000,0x5dc,2);
      puVar3 = local_30;
      uVar2 = 0x3c;
      goto LAB_0010bbc4;
    }
    puVar3 = local_34;
  }
  uVar2 = 9;
LAB_0010bbc4:
  haptic_hv_i2c_writes(param_1,uVar2,puVar3,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_ram_init @ 0010bbfc size=80
// signature: undefined aw869xx_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw869xx_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
    usleep_range_state(500,600,2);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_bst_peak_cur @ 0010bc50 size=152
// signature: undefined aw869xx_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_bst_peak_cur(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 10) == '\x01') {
    _printk(&DAT_001317fd,"haptic_hv",0x1c2,"aw869xx_set_bst_peak_cur");
    uVar1 = 10;
  }
  else {
    if (*(char *)(param_1 + 10) == '\0') {
      uVar1 = 0x1bc;
    }
    else {
      uVar1 = 0x1c8;
    }
    _printk(&DAT_001337fc,"haptic_hv",uVar1,"aw869xx_set_bst_peak_cur");
    uVar1 = 0;
  }
  haptic_hv_i2c_write_bits(param_1,0x6d,0xfffffff1,uVar1);
  return;
}



//------------------------------------------------------------
// aw869xx_get_lra_resistance @ 0010bcec size=408
// signature: undefined aw869xx_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_lra_resistance(long param_1)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  byte local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  aw869xx_stop();
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  aw869xx_stop(param_1);
  usleep_range_state(2000,0x9c4,2);
  haptic_hv_i2c_write_bits(param_1,0x44,0xffffffbf,0);
  haptic_hv_i2c_reads(param_1,0x49,local_3c,1);
  bVar2 = local_3c[0];
  haptic_hv_i2c_write_bits(param_1,0x49,0xfffffff8,4);
  haptic_hv_i2c_write_bits(param_1,0x51,0xffffffef,0x10);
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffffe,1);
  usleep_range_state(30000,35000,2);
  haptic_hv_i2c_reads(param_1,0x53,local_3c,1);
  bVar3 = local_3c[0];
  haptic_hv_i2c_reads(param_1,0x57,local_3c,1);
  *(uint *)(param_1 + 0x6c) = ((local_3c[0] & 3 | (uint)bVar3 << 2) * 0xa5870) / 0x2800;
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  haptic_hv_i2c_write_bits(param_1,0x49,0xfffffff8,bVar2 & 7);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_pwm @ 0010be88 size=68
// signature: undefined aw869xx_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_pwm(undefined8 param_1,uint param_2)

{
  if ((param_2 & 0xff) < 3) {
    haptic_hv_i2c_write_bits(param_1,0x44,0xfffffffc,0x20001 >> (ulong)((param_2 & 3) << 3));
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_gain @ 0010bed0 size=88
// signature: undefined aw869xx_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_play_mode @ 0010bf2c size=808
// signature: undefined aw869xx_play_mode(void)
// callers: []
//------------------------------------------------------------

void aw869xx_play_mode(long param_1,undefined1 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0x292,"aw869xx_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    aw869xx_stop(param_1);
    goto LAB_0010c228;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",0x297,"aw869xx_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 1;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    uVar2 = 0;
    break;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x2ab,"aw869xx_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,1);
    uVar2 = 4;
    break;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x2b5,"aw869xx_play_mode");
    uVar2 = 8;
    uVar3 = 0xfffffffc;
    *(undefined1 *)(param_1 + 0xb) = 3;
    goto LAB_0010c20c;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x2bd,"aw869xx_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 4;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00137d95,"haptic_hv",0x247,"aw869xx_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffbf,0);
    local_2c[0] = 0xc;
    haptic_hv_i2c_writes(param_1,0x3c,local_2c,1);
    uVar2 = 0x80;
    goto LAB_0010c224;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0x2a1,"aw869xx_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 5;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00137d95,"haptic_hv",0x247,"aw869xx_bst_mode_config");
    uVar2 = 6;
    uVar3 = 0xffffffbf;
LAB_0010c20c:
    uVar4 = 0;
    goto LAB_0010c210;
  default:
    _printk(&DAT_001348de,"haptic_hv",0x2c7,"aw869xx_play_mode");
    goto LAB_0010c228;
  }
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar2);
  _printk(&DAT_00137491,"haptic_hv",0x241,"aw869xx_bst_mode_config");
  uVar2 = 6;
  uVar3 = 0xffffffbf;
  uVar4 = 0x40;
LAB_0010c210:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar3,uVar4);
  uVar2 = 0;
LAB_0010c224:
  haptic_hv_i2c_write_bits(param_1,0x43,0xffffff7f,uVar2);
LAB_0010c228:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_bst_vol @ 0010c258 size=100
// signature: undefined aw869xx_set_bst_vol(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_bst_vol(undefined8 param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (((uint)(param_2 >> 4) & 0xfffffff) < 0x177) {
    uVar2 = 0;
  }
  else {
    uVar1 = (uint)param_2;
    if (0x2ada < uVar1) {
      uVar1 = 0x2adb;
    }
    uVar2 = (ulong)(uVar1 * 1000 - 6000000) / 0x1342d;
  }
  haptic_hv_i2c_write_bits(param_1,6,0xffffffc0,uVar2);
  return;
}



//------------------------------------------------------------
// aw869xx_set_repeat_seq @ 0010c2c0 size=120
// signature: undefined aw869xx_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,10,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_auto_bst_enable @ 0010c33c size=52
// signature: undefined aw869xx_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw869xx_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,8,0xffffffbf,(ulong)(param_2 != '\0') << 6);
  return;
}



//------------------------------------------------------------
// aw869xx_vbat_mode_config @ 0010c374 size=148
// signature: undefined aw869xx_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw869xx_vbat_mode_config(undefined8 param_1,char param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (param_2 == '\x01') {
    local_2c[0] = 0xc;
    haptic_hv_i2c_writes(param_1,0x3c,local_2c,1);
    uVar2 = 0x80;
  }
  else {
    uVar2 = 0;
  }
  haptic_hv_i2c_write_bits(param_1,0x43,0xffffff7f,uVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_wav_seq @ 0010c40c size=88
// signature: undefined aw869xx_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 10,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_wav_loop @ 0010c468 size=64
// signature: undefined aw869xx_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0x12,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw869xx_set_rtp_data @ 0010c4ac size=40
// signature: undefined aw869xx_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,0x32,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw869xx_protect_config @ 0010c4d8 size=256
// signature: undefined aw869xx_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw869xx_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x30f,"aw869xx_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",0x308,"aw869xx_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x4e,local_40,1);
    haptic_hv_i2c_writes(param_1,0x4f,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_parse_dt @ 0010c5dc size=1388
// signature: undefined aw869xx_parse_dt(void)
// callers: []
//------------------------------------------------------------

void aw869xx_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined4 local_5c;
  undefined1 local_58;
  undefined2 local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_52 = 0;
  local_54 = 0;
  local_58 = 0;
  local_5c = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_gain_bypass",param_2 + 0x55f,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00135d27,"haptic_hv",0x6b0,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x6b3,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_f0_cali_percent",param_2 + 0x529,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00132eb3,"haptic_hv",0x6b6,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_cont_drv1_lvl",param_2 + 0x562,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001363b7,"haptic_hv",0x6b9,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw869xx_cont_lra_vrms",param_2 + 0x584,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00131b73,"haptic_hv",0x6bc,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_cont_drv1_time",param_2 + 0x566,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133bf0,"haptic_hv",0x6bf,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_cont_drv2_time",param_2 + 0x567,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00135d56,"haptic_hv",0x6c2,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_cont_brk_gain",param_2 + 0x565,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133fdf,"haptic_hv",0x6c5,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_d2s_gain",param_2 + 0x55d,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134c5c,"haptic_hv",0x6c8,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_cont_brk_time",param_2 + 0x564,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001356a4,"haptic_hv",0x6cb,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw869xx_cont_track_margin",param_2 + 0x568,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133846,"haptic_hv",0x6cf,"aw869xx_parse_dt");
  }
  lVar2 = of_find_property(param_3,"aw869xx_is_enabled_track_en",0);
  *(bool *)(param_2 + 0x588) = lVar2 != 0;
  _printk(&DAT_00137abd,"haptic_hv",0x6d2,"aw869xx_parse_dt");
  lVar2 = of_find_property(param_3,"aw869xx_is_enabled_auto_bst",0);
  *(bool *)(param_2 + 0x58c) = lVar2 != 0;
  _printk(&DAT_00134902,"haptic_hv",0x6d5,"aw869xx_parse_dt");
  lVar2 = of_find_property(param_3,"aw869xx_is_enabled_i2s",0);
  *(bool *)(param_2 + 0x58d) = lVar2 != 0;
  _printk(&DAT_0013387b,"haptic_hv",0x6d7,"aw869xx_parse_dt");
  lVar2 = of_find_property(param_3,"aw869xx_is_enabled_one_wire",0);
  *(bool *)(param_2 + 0x58e) = lVar2 != 0;
  _printk(&DAT_00133c22,"haptic_hv",0x6da,"aw869xx_parse_dt");
  iVar1 = of_property_read_variable_u32_array(param_3,"aw869xx_bst_vol_default",param_2 + 0x534,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00135a5f,"haptic_hv",0x6dd,"aw869xx_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_duration_time",&local_54,3,0);
  if (iVar1 < 0) {
    _printk(&DAT_001345bc,"haptic_hv",0x6e1,"aw869xx_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_54;
    *(undefined1 *)(param_2 + 0x52c) = local_52;
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_bstcfg",&local_5c,5,0);
  if (iVar1 < 0) {
    _printk(&DAT_00131ba4,"haptic_hv",0x6e6,"aw869xx_parse_dt");
  }
  else {
    *(undefined4 *)(param_2 + 0x558) = local_5c;
    *(undefined1 *)(param_2 + 0x55c) = local_58;
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw869xx_trig_config",&local_50,0x18,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013523d,"haptic_hv",0x6ec,"aw869xx_parse_dt");
  }
  else {
    *(undefined8 *)(param_2 + 0x569) = local_50;
    *(undefined8 *)(param_2 + 0x571) = local_48;
    *(undefined8 *)(param_2 + 0x579) = local_40;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_trig_init @ 0010cb4c size=592
// signature: undefined aw869xx_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw869xx_trig_init(long param_1)

{
  char cVar1;
  long lVar2;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  _printk(&DAT_0013233b,"haptic_hv",0x60b,"aw869xx_trig_init");
  if ((*(char *)(param_1 + 0x58d) == '\0') || (*(char *)(param_1 + 4) == '\0')) {
    *(undefined2 *)(param_1 + 0x6d5) = *(undefined2 *)(param_1 + 0x572);
    *(undefined1 *)(param_1 + 0x6d4) = *(undefined1 *)(param_1 + 0x571);
    *(undefined1 *)(param_1 + 0x6d8) = *(undefined1 *)(param_1 + 0x574);
    *(undefined1 *)(param_1 + 0x6d7) = *(undefined1 *)(param_1 + 0x575);
    *(undefined1 *)(param_1 + 0x6d9) = *(undefined1 *)(param_1 + 0x576);
    *(undefined2 *)(param_1 + 0x6d2) = *(undefined2 *)(param_1 + 0x577);
    *(undefined2 *)(param_1 + 0x6e1) = *(undefined2 *)(param_1 + 0x579);
    *(undefined1 *)(param_1 + 0x6e3) = *(undefined1 *)(param_1 + 0x57b);
    *(undefined1 *)(param_1 + 0x6e5) = *(undefined1 *)(param_1 + 0x57c);
    *(undefined1 *)(param_1 + 0x6e4) = *(undefined1 *)(param_1 + 0x57d);
    *(undefined1 *)(param_1 + 0x6e6) = *(undefined1 *)(param_1 + 0x57e);
    *(undefined2 *)(param_1 + 0x6df) = *(undefined2 *)(param_1 + 0x57f);
    aw869xx_trig2_param_config(param_1);
    aw869xx_trig3_param_config(param_1);
    cVar1 = *(char *)(param_1 + 0x58e);
  }
  else {
    _printk(&DAT_00134fcc,"haptic_hv",0x60e,"aw869xx_trig_init");
    _printk(&DAT_00132e8a,"haptic_hv",0x33b,"aw869xx_i2s_init");
    haptic_hv_i2c_write_bits(param_1,0x44,0xfffffffb,4);
    haptic_hv_i2c_write_bits(param_1,0x6b,0xffffffcf,0x20);
    cVar1 = *(char *)(param_1 + 0x58e);
  }
  if (cVar1 == '\0') {
    *(undefined1 *)(param_1 + 0x6c7) = *(undefined1 *)(param_1 + 0x569);
    *(undefined2 *)(param_1 + 0x6c8) = *(undefined2 *)(param_1 + 0x56a);
    *(undefined1 *)(param_1 + 0x6cb) = *(undefined1 *)(param_1 + 0x56c);
    *(undefined1 *)(param_1 + 0x6ca) = *(undefined1 *)(param_1 + 0x56d);
    *(undefined1 *)(param_1 + 0x6cc) = *(undefined1 *)(param_1 + 0x56e);
    *(undefined2 *)(param_1 + 0x6c5) = *(undefined2 *)(param_1 + 0x56f);
    aw869xx_trig1_param_config(param_1);
  }
  else {
    _printk(&DAT_00137af7,"haptic_hv",0x618,"aw869xx_trig_init");
    local_2c[0] = 0x6c;
    local_30[0] = 0x75;
    _printk(&DAT_00132e8a,"haptic_hv",0x330,"aw869xx_one_wire_init");
    haptic_hv_i2c_writes(param_1,0x3e,local_2c,1);
    haptic_hv_i2c_writes(param_1,0x3c,local_30,1);
    haptic_hv_i2c_write_bits(param_1,0x3a,0xfffffff7,8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_irq_clear @ 0010cda0 size=124
// signature: undefined aw869xx_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw869xx_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x46e,"aw869xx_irq_clear",local_1c[0]);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_ram_addr @ 0010ce20 size=100
// signature: undefined aw869xx_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_ram_addr(long param_1)

{
  long lVar1;
  ushort local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_misc_para_init @ 0010ce88 size=636
// signature: undefined aw869xx_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw869xx_misc_para_init(long param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  iVar6 = 0x711;
  if (0x707 < *(uint *)(param_1 + 0x530)) {
    iVar6 = 0x7c6;
  }
  uVar2 = iVar6 * *(int *)(param_1 + 0x584);
  uVar5 = 0x7f;
  if (uVar2 < 0x3b9200) {
    uVar5 = (undefined1)(uVar2 / 0x7724);
  }
  *(undefined1 *)(param_1 + 0x563) = uVar5;
  if (*(int *)(param_1 + 0x534) != 0) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x534);
  }
  haptic_hv_i2c_reads(param_1,7,&local_30,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_30;
  haptic_hv_i2c_reads(param_1,10,&local_30,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_30;
  *(undefined8 *)(param_1 + 0x11) = local_30;
  haptic_hv_i2c_writes(param_1,0x6d,param_1 + 0x558,5);
  haptic_hv_i2c_write_bits(param_1,0x49,0xffffffbf,(ulong)*(byte *)(param_1 + 0x55f) << 6);
  if (*(char *)(param_1 + 0x564) == '\0') {
    _printk(&DAT_0013618a,"haptic_hv",0x710,"aw869xx_misc_para_init");
  }
  haptic_hv_i2c_writes(param_1,0x21,param_1 + 0x564,1);
  cVar1 = *(char *)(param_1 + 0x565);
  if (cVar1 == '\0') {
    _printk(&DAT_00136ea5,"haptic_hv",0x715,"aw869xx_misc_para_init");
    cVar1 = *(char *)(param_1 + 0x565);
  }
  haptic_hv_i2c_write_bits(param_1,0x1c,0xfffffff0,cVar1);
  if ((*(char *)(param_1 + 0x58d) == '\0') || (*(char *)(param_1 + 4) == '\0')) {
    _printk(&DAT_00133c5c,"haptic_hv",0x71f,"aw869xx_misc_para_init");
    uVar4 = 0;
  }
  else {
    _printk(&DAT_0013238b,"haptic_hv",0x71a,"aw869xx_misc_para_init");
    uVar4 = 4;
  }
  haptic_hv_i2c_write_bits(param_1,0x44,0xfffffffb,uVar4);
  haptic_hv_i2c_write_bits(param_1,0x71,0xffffff7f,0);
  local_34[0] = 0x32;
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",0x308,"aw869xx_protect_config");
  local_38[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x4e,local_38,1);
  haptic_hv_i2c_writes(param_1,0x4f,local_34,1);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_interrupt_setup @ 0010d108 size=176
// signature: undefined aw869xx_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw869xx_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x40f,"aw869xx_interrupt_setup",local_2c[0]);
  haptic_hv_i2c_write_bits(param_1,0x49,0xffffffcf,0x10);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff19,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_set_rtp_aei @ 0010d1bc size=48
// signature: undefined aw869xx_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw869xx_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw869xx_upload_lra @ 0010d1f0 size=200
// signature: undefined aw869xx_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw869xx_upload_lra(long param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 2) {
    _printk(&DAT_001323a9,"haptic_hv",0x2db,"aw869xx_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
  }
  else if (param_2 == 1) {
    _printk(&DAT_001378a9,"haptic_hv",0x2d5,"aw869xx_upload_lra",*(undefined4 *)(param_1 + 0x90));
    uVar1 = *(undefined4 *)(param_1 + 0x90);
  }
  else {
    if (param_2 != 0) {
      return;
    }
    _printk(&DAT_00136e0b,"haptic_hv",0x2d0,"aw869xx_upload_lra");
    uVar1 = 0;
  }
  haptic_hv_i2c_write_bits(param_1,0x5a,0xffffffc0,uVar1);
  return;
}



//------------------------------------------------------------
// aw869xx_get_wav_seq @ 0010d2bc size=236
// signature: undefined aw869xx_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,10,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_get_ram_data @ 0010d3ac size=120
// signature: undefined aw869xx_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_bst_mode_config @ 0010d428 size=200
// signature: undefined aw869xx_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw869xx_bst_mode_config(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    _printk(&DAT_00137d95,"haptic_hv",0x247,"aw869xx_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffbf,0);
  }
  else if (param_2 == '\x01') {
    _printk(&DAT_00137491,"haptic_hv",0x241,"aw869xx_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffbf,0x40);
  }
  else {
    _printk(&DAT_00131828,"haptic_hv",0x24d,"aw869xx_bst_mode_config",param_2);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_get_first_wave_addr @ 0010d4f4 size=112
// signature: undefined aw869xx_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw869xx_get_wav_loop @ 0010d568 size=420
// signature: undefined aw869xx_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw869xx_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0x12,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw869xx_get_reg @ 0010d710 size=284
// signature: undefined aw869xx_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw869xx_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_c0 [120];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_c0[0x70] = 0;
  local_c0[0x71] = 0;
  local_c0[0x72] = 0;
  local_c0[0x73] = 0;
  local_c0[0x74] = 0;
  local_c0[0x75] = 0;
  local_c0[0x76] = 0;
  local_c0[0x60] = 0;
  local_c0[0x61] = 0;
  local_c0[0x62] = 0;
  local_c0[99] = 0;
  local_c0[100] = 0;
  local_c0[0x65] = 0;
  local_c0[0x66] = 0;
  local_c0[0x67] = 0;
  local_c0[0x68] = 0;
  local_c0[0x69] = 0;
  local_c0[0x6a] = 0;
  local_c0[0x6b] = 0;
  local_c0[0x6c] = 0;
  local_c0[0x6d] = 0;
  local_c0[0x6e] = 0;
  local_c0[0x6f] = 0;
  local_c0[0x50] = 0;
  local_c0[0x51] = 0;
  local_c0[0x52] = 0;
  local_c0[0x53] = 0;
  local_c0[0x54] = 0;
  local_c0[0x55] = 0;
  local_c0[0x56] = 0;
  local_c0[0x57] = 0;
  local_c0[0x58] = 0;
  local_c0[0x59] = 0;
  local_c0[0x5a] = 0;
  local_c0[0x5b] = 0;
  local_c0[0x5c] = 0;
  local_c0[0x5d] = 0;
  local_c0[0x5e] = 0;
  local_c0[0x5f] = 0;
  local_c0[0x40] = 0;
  local_c0[0x41] = 0;
  local_c0[0x42] = 0;
  local_c0[0x43] = 0;
  local_c0[0x44] = 0;
  local_c0[0x45] = 0;
  local_c0[0x46] = 0;
  local_c0[0x47] = 0;
  local_c0[0x48] = 0;
  local_c0[0x49] = 0;
  local_c0[0x4a] = 0;
  local_c0[0x4b] = 0;
  local_c0[0x4c] = 0;
  local_c0[0x4d] = 0;
  local_c0[0x4e] = 0;
  local_c0[0x4f] = 0;
  local_c0[0x30] = 0;
  local_c0[0x31] = 0;
  local_c0[0x32] = 0;
  local_c0[0x33] = 0;
  local_c0[0x34] = 0;
  local_c0[0x35] = 0;
  local_c0[0x36] = 0;
  local_c0[0x37] = 0;
  local_c0[0x38] = 0;
  local_c0[0x39] = 0;
  local_c0[0x3a] = 0;
  local_c0[0x3b] = 0;
  local_c0[0x3c] = 0;
  local_c0[0x3d] = 0;
  local_c0[0x3e] = 0;
  local_c0[0x3f] = 0;
  local_c0[0x20] = 0;
  local_c0[0x21] = 0;
  local_c0[0x22] = 0;
  local_c0[0x23] = 0;
  local_c0[0x24] = 0;
  local_c0[0x25] = 0;
  local_c0[0x26] = 0;
  local_c0[0x27] = 0;
  local_c0[0x28] = 0;
  local_c0[0x29] = 0;
  local_c0[0x2a] = 0;
  local_c0[0x2b] = 0;
  local_c0[0x2c] = 0;
  local_c0[0x2d] = 0;
  local_c0[0x2e] = 0;
  local_c0[0x2f] = 0;
  local_c0[0x10] = 0;
  local_c0[0x11] = 0;
  local_c0[0x12] = 0;
  local_c0[0x13] = 0;
  local_c0[0x14] = 0;
  local_c0[0x15] = 0;
  local_c0[0x16] = 0;
  local_c0[0x17] = 0;
  local_c0[0x18] = 0;
  local_c0[0x19] = 0;
  local_c0[0x1a] = 0;
  local_c0[0x1b] = 0;
  local_c0[0x1c] = 0;
  local_c0[0x1d] = 0;
  local_c0[0x1e] = 0;
  local_c0[0x1f] = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[6] = 0;
  local_c0[7] = 0;
  local_c0[8] = 0;
  local_c0[9] = 0;
  local_c0[10] = 0;
  local_c0[0xb] = 0;
  local_c0[0xc] = 0;
  local_c0[0xd] = 0;
  local_c0[0xe] = 0;
  local_c0[0xf] = 0;
  haptic_hv_i2c_reads(param_1,0,local_c0,0x32);
  haptic_hv_i2c_reads(param_1,0x33,local_c0 + 0x33,0xf);
  haptic_hv_i2c_reads(param_1,0x43,local_c0 + 0x43,0x34);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 0x32) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_c0[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x77);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw869xx_get_prctmode @ 0010d830 size=96
// signature: undefined aw869xx_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw869xx_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x4e,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw869xx_get_trim_lra @ 0010d894 size=96
// signature: undefined aw869xx_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

byte aw869xx_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x5a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0x3f;
}



//------------------------------------------------------------
// aw869xx_get_glb_state @ 0010d8f8 size=92
// signature: undefined aw869xx_get_glb_state(void)
// callers: []
//------------------------------------------------------------

void aw869xx_get_glb_state(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_osc_read_status @ 0010d958 size=96
// signature: undefined aw869xx_osc_read_status(void)
// callers: []
//------------------------------------------------------------

byte aw869xx_osc_read_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw869xx_rtp_get_fifo_afs @ 0010d9bc size=96
// signature: undefined aw869xx_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw869xx_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw869xx_rtp_get_fifo_aes @ 0010da20 size=96
// signature: undefined aw869xx_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw869xx_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw869xx_get_theory_time @ 0010da84 size=196
// signature: undefined aw869xx_get_theory_time(void)
// callers: []
//------------------------------------------------------------

uint aw869xx_get_theory_time(long param_1)

{
  long lVar1;
  uint uVar2;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x44,local_2c,1);
  if ((int)((ulong)local_2c[0] & 3) == 3) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (*(uint *)(&DAT_0012da48 + ((ulong)local_2c[0] & 3) * 4) != 0) {
      uVar2 = (uint)(*(int *)(param_1 + 0x7c) * 1000) /
              *(uint *)(&DAT_0012da48 + ((ulong)local_2c[0] & 3) * 4);
    }
  }
  _printk(&DAT_00132875,"haptic_hv",0x6a1,"aw869xx_get_theory_time",*(undefined8 *)(param_1 + 0xa0),
          uVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// aw869xx_snd_soc_init @ 0010db4c size=200
// signature: undefined aw869xx_snd_soc_init(void)
// callers: []
//------------------------------------------------------------

int aw869xx_snd_soc_init(undefined8 param_1)

{
  int iVar1;
  void *__dest;
  
  __dest = (void *)devm_kmalloc(param_1,0xe0,0xdc0);
  if (__dest == (void *)0x0) {
    iVar1 = -0xc;
  }
  else {
    memcpy(__dest,&aw869xx_dai,0xe0);
    _printk(&DAT_00134c88,"haptic_hv",0x17c,"aw869xx_snd_soc_init","aw869xx-aif");
    iVar1 = snd_soc_register_component(param_1,soc_codec_dev_aw869xx,__dest,1);
    if (iVar1 < 0) {
      _printk(&DAT_00132917,"haptic_hv",0x181,"aw869xx_snd_soc_init",iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// trig_show @ 0010dc18 size=292
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x61f),(uint)*(byte *)(lVar2 + 0x620),
                   (uint)*(byte *)(lVar2 + 0x621),(uint)*(byte *)(lVar2 + 0x623),
                   (uint)*(byte *)(lVar2 + 0x622),(uint)*(byte *)(lVar2 + 0x624),
                   (uint)*(byte *)(lVar2 + 0x61d),(uint)*(byte *)(lVar2 + 0x61e));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x62c),(uint)*(byte *)(lVar2 + 0x62d),
                   (uint)*(byte *)(lVar2 + 0x62e),(uint)*(byte *)(lVar2 + 0x630),
                   (uint)*(byte *)(lVar2 + 0x62f),(uint)*(byte *)(lVar2 + 0x631),
                   (uint)*(byte *)(lVar2 + 0x62a),(uint)*(byte *)(lVar2 + 0x62b));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x639),(uint)*(byte *)(lVar2 + 0x63a),
                   (uint)*(byte *)(lVar2 + 0x63b),(uint)*(byte *)(lVar2 + 0x63d),
                   (uint)*(byte *)(lVar2 + 0x63c),(uint)*(byte *)(lVar2 + 0x63e),
                   (uint)*(byte *)(lVar2 + 0x637),(uint)*(byte *)(lVar2 + 0x638));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 0010dd40 size=828
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar5 = sscanf(param_3,"%u %u %u %u %u %u %u %u %u",(uint *)&local_60,
                 (uint *)((ulong)&local_60 | 4),(uint *)&local_58,(uint *)((long)&local_58 + 4),
                 (uint *)&local_50,(uint *)((long)&local_50 + 4),(uint *)&local_48,
                 (uint *)((long)&local_48 + 4),local_40);
  if (iVar5 == 9) {
    _printk(&DAT_001359f8,"haptic_hv",0x7a8,"trig_store",local_60 & 0xffffffff,local_60._4_4_,
            local_58 & 0xffffffff,local_58._4_4_,local_50 & 0xffffffff,local_50 >> 0x20,
            local_48 & 0xffffffff,local_48._4_4_,local_40[0]);
    uVar3 = local_60;
    if ((uint)local_60 - 4 < 0xfffffffd) {
      _printk(&DAT_001369d0,"haptic_hv",0x7aa,"trig_store");
    }
    else {
      uVar2 = (uint)local_60 - 1;
      if (uVar2 == 0) {
        if (*(char *)(lVar6 + 0x4e6) != '\0') {
          _printk(&DAT_00136135,"haptic_hv",0x7ae,"trig_store");
          goto LAB_0010ddc4;
        }
      }
      else if ((*(char *)(lVar6 + 0x4e5) != '\0') && (*(char *)(lVar6 + -0xa4) != '\0')) {
        _printk(&DAT_00135a2c,"haptic_hv",0x7b4,"trig_store");
        goto LAB_0010ddc4;
      }
      if (*(char *)(lVar6 + -0xa2) == '\0') {
        _printk(&DAT_001325b9,"haptic_hv",0x7b8,"trig_store");
      }
      else {
        if (((uint)local_50 <= *(byte *)(lVar6 + 0x47c)) &&
           ((uint)local_48 <= *(byte *)(lVar6 + 0x47c))) {
          lVar1 = lVar6 + 0x618;
          local_60 = CONCAT44(local_60._4_4_,uVar2);
          *(char *)(lVar1 + (ulong)uVar2 * 0xd + 7) = (char)(uVar3 >> 0x20);
          if (uVar2 < 3) {
            *(char *)(lVar1 + (ulong)uVar2 * 0xd + 8) = (char)local_58;
            if (uVar2 < 3) {
              *(char *)(lVar1 + (ulong)uVar2 * 0xd + 9) = (char)(local_58 >> 0x20);
              if (uVar2 < 3) {
                *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xb) = (char)local_50;
                if (uVar2 < 3) {
                  *(char *)(lVar1 + (ulong)uVar2 * 0xd + 10) = (char)(local_50 >> 0x20);
                  if (uVar2 < 3) {
                    *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xc) = (char)local_48;
                    if (uVar2 < 3) {
                      *(char *)(lVar1 + (ulong)uVar2 * 0xd + 5) = (char)(local_48 >> 0x20);
                      if (uVar2 < 3) {
                        lVar7 = lVar6 + -0xa8;
                        *(char *)(lVar1 + (ulong)uVar2 * 0xd + 6) = (char)local_40[0];
                        mutex_lock(lVar6 + 0x2a8);
                        if ((uint)local_60 == 2) {
                          aw869xx_trig3_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 1) {
                          aw869xx_trig2_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 0) {
                          aw869xx_trig1_param_config(lVar7);
                        }
                        mutex_unlock(lVar6 + 0x2a8);
                        goto LAB_0010ddc4;
                      }
                    }
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10e07c);
          (*pcVar4)();
        }
        _printk(&DAT_00134564,"haptic_hv",0x7bc,"trig_store");
      }
    }
  }
LAB_0010ddc4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw869xx_trig1_param_config @ 0010e07c size=232
// signature: undefined aw869xx_trig1_param_config(void)
// callers: [trig_store, aw869xx_trig_init]
//------------------------------------------------------------

void aw869xx_trig1_param_config(long param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  undefined4 uVar5;
  
  cVar2 = *(char *)(param_1 + 0x6c7);
  cVar3 = *(char *)(param_1 + 0x6c8);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x6c9) != '\0') {
    uVar5 = 0xffffff80;
  }
  haptic_hv_i2c_write_bits(param_1,0x33,0xffffff7f,uVar5);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x6ca) != '\0') {
    uVar5 = 0xffffff80;
  }
  haptic_hv_i2c_write_bits(param_1,0x36,0xffffff7f,uVar5);
  if (*(char *)(param_1 + 0x6cb) != '\0') {
    haptic_hv_i2c_write_bits(param_1,0x33,0xffffff80);
  }
  if (*(char *)(param_1 + 0x6cc) != '\0') {
    haptic_hv_i2c_write_bits(param_1,0x36,0xffffff80);
  }
  bVar4 = cVar2 != '\0';
  uVar1 = (uint)bVar4 << 6;
  if (cVar3 != '\0') {
    uVar1 = (uint)bVar4 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6c5) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6c6) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
  return;
}



//------------------------------------------------------------
// aw869xx_trig2_param_config @ 0010e164 size=232
// signature: undefined aw869xx_trig2_param_config(void)
// callers: [trig_store, aw869xx_trig_init]
//------------------------------------------------------------

void aw869xx_trig2_param_config(long param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  undefined4 uVar5;
  
  cVar2 = *(char *)(param_1 + 0x6d4);
  cVar3 = *(char *)(param_1 + 0x6d5);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x6d6) != '\0') {
    uVar5 = 0xffffff80;
  }
  haptic_hv_i2c_write_bits(param_1,0x34,0xffffff7f,uVar5);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x6d7) != '\0') {
    uVar5 = 0xffffff80;
  }
  haptic_hv_i2c_write_bits(param_1,0x37,0xffffff7f,uVar5);
  if (*(char *)(param_1 + 0x6d8) != '\0') {
    haptic_hv_i2c_write_bits(param_1,0x34,0xffffff80);
  }
  if (*(char *)(param_1 + 0x6d9) != '\0') {
    haptic_hv_i2c_write_bits(param_1,0x37,0xffffff80);
  }
  bVar4 = cVar2 != '\0';
  bVar1 = bVar4 << 2;
  if (cVar3 != '\0') {
    bVar1 = bVar4 << 2 | 8;
  }
  if (*(char *)(param_1 + 0x6d2) != '\0') {
    bVar1 = bVar1 | 2;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x6d3) != '\0');
  return;
}



//------------------------------------------------------------
// aw869xx_trig3_param_config @ 0010e24c size=232
// signature: undefined aw869xx_trig3_param_config(void)
// callers: [trig_store, aw869xx_trig_init]
//------------------------------------------------------------

void aw869xx_trig3_param_config(long param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  bool bVar4;
  undefined4 uVar5;
  
  cVar2 = *(char *)(param_1 + 0x6e1);
  cVar3 = *(char *)(param_1 + 0x6e2);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x6e3) != '\0') {
    uVar5 = 0xffffff80;
  }
  haptic_hv_i2c_write_bits(param_1,0x35,0xffffff7f,uVar5);
  uVar5 = 0;
  if (*(char *)(param_1 + 0x6e4) != '\0') {
    uVar5 = 0xffffff80;
  }
  haptic_hv_i2c_write_bits(param_1,0x38,0xffffff7f,uVar5);
  if (*(char *)(param_1 + 0x6e5) != '\0') {
    haptic_hv_i2c_write_bits(param_1,0x35,0xffffff80);
  }
  if (*(char *)(param_1 + 0x6e6) != '\0') {
    haptic_hv_i2c_write_bits(param_1,0x38,0xffffff80);
  }
  bVar4 = cVar2 != '\0';
  uVar1 = (uint)bVar4 << 6;
  if (cVar3 != '\0') {
    uVar1 = (uint)bVar4 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  return;
}



//------------------------------------------------------------
// cont_drv_lvl_show @ 0010e338 size=64
// signature: undefined cont_drv_lvl_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_lvl_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_lvl = 0x%02X, cont_drv2_lvl = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4ba),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bb));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_store @ 0010e37c size=200
// signature: undefined cont_drv_lvl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_lvl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_40[1] = 0;
  iVar1 = sscanf(param_3,"%x %x",local_40,(uint *)((ulong)local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x4ba) = (char)local_40[0];
    *(char *)(lVar2 + 0x4bb) = (char)local_40[1];
    haptic_hv_i2c_write_bits(lVar2 + -0xa8,0x1d,0xffffff80);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1e,lVar2 + 0x4bb,1);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_time_show @ 0010e448 size=64
// signature: undefined cont_drv_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4be),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bf));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_time_store @ 0010e48c size=176
// signature: undefined cont_drv_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_34;
  undefined1 local_33;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_30,(uint *)((ulong)&local_30 | 4));
  if (iVar1 == 2) {
    *(undefined1 *)(lVar2 + 0x4be) = (undefined1)local_30;
    local_34 = (undefined1)local_30;
    *(undefined1 *)(lVar2 + 0x4bf) = local_30._4_1_;
    local_33 = local_30._4_1_;
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1f,&local_34,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_brk_time_show @ 0010e540 size=60
// signature: undefined cont_brk_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_brk_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_brk_time_store @ 0010e580 size=104
// signature: undefined cont_brk_time_store(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x4bc;
  iVar2 = kstrtou8(param_3,0,lVar1);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    haptic_hv_i2c_writes(lVar3 + -0xa8,0x21,lVar1,1);
  }
  return param_4;
}



//------------------------------------------------------------
// aw869xx_set_dai_sysclk @ 0010e5ec size=64
// signature: undefined aw869xx_set_dai_sysclk(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_set_dai_sysclk(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  _printk(&DAT_00132947,"haptic_hv",0x6a,"aw869xx_set_dai_sysclk",param_3);
  return 0;
}



//------------------------------------------------------------
// aw869xx_set_fmt @ 0010e630 size=176
// signature: undefined aw869xx_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_set_fmt(undefined8 param_1,uint param_2)

{
  _printk(&DAT_001335b4,"haptic_hv",0x57,"aw869xx_set_fmt",param_2);
  if ((param_2 & 0xf) == 1) {
    if ((param_2 & 0xf000) == 0x4000) {
      return 0;
    }
    _printk(&DAT_001335d0,"haptic_hv",0x5c,"aw869xx_set_fmt");
  }
  else {
    _printk(&DAT_00134291,"haptic_hv",0x61,"aw869xx_set_fmt");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// aw869xx_mute @ 0010e6e4 size=540
// signature: undefined aw869xx_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_mute(long param_1,int param_2,int param_3)

{
  long lVar1;
  char local_40 [4];
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = '\0';
  if (param_3 == 1) {
    _printk(&DAT_00132960,"haptic_hv",0xc4,"aw869xx_mute");
    goto LAB_0010e798;
  }
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_001338b0,"haptic_hv",199,"aw869xx_mute",param_2);
  mutex_lock(lVar1 + 0x350);
  if (param_2 == 0) {
    haptic_hv_i2c_write_bits(lVar1,0x4b,0xfffffffe,1);
    usleep_range_state(2000,3000,2);
    haptic_hv_i2c_reads(lVar1,1,local_40,1);
    _printk(&DAT_0013493c,"haptic_hv",0xd1,"aw869xx_mute",local_40[0]);
    haptic_hv_i2c_reads(lVar1,4,local_40,1);
    _printk(&DAT_00131bce,"haptic_hv",0xd3,"aw869xx_mute",local_40[0]);
    haptic_hv_i2c_reads(lVar1,5,local_40,1);
    _printk(&DAT_00135d9b,"haptic_hv",0xd5,"aw869xx_mute",local_40[0]);
    local_3c[0] = '\0';
    haptic_hv_i2c_reads(lVar1,0x3f,local_3c,1);
    local_40[0] = local_3c[0];
    if (local_3c[0] != '\n') {
      _printk(&DAT_00135703,"haptic_hv",0xd8,"aw869xx_mute");
      goto LAB_0010e77c;
    }
    _printk(&DAT_00134fed,"haptic_hv",0xdb,"aw869xx_mute");
  }
  else {
LAB_0010e77c:
    haptic_hv_i2c_write_bits(lVar1,0x4b,0xfffffffe,0);
  }
  mutex_unlock(lVar1 + 0x350);
LAB_0010e798:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw869xx_startup @ 0010e904 size=132
// signature: undefined aw869xx_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_startup(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0x49,"aw869xx_startup");
  if (*(int *)(param_1 + 0x3c) == 0) {
    lVar1 = lVar2 + 0x350;
    mutex_lock(lVar1);
    haptic_hv_i2c_write_bits(lVar2,0x44,0xffffffbf,0);
    mutex_unlock(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// aw869xx_shutdown @ 0010e98c size=112
// signature: undefined aw869xx_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw869xx_shutdown(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0xe8,"aw869xx_shutdown");
  if (*(int *)(param_1 + 0x3c) == 0) {
    lVar1 = lVar2 + 0x350;
    *(undefined4 *)(lVar2 + 0x40) = 0;
    mutex_lock(lVar1);
    mutex_unlock(lVar1);
  }
  return;
}



//------------------------------------------------------------
// aw869xx_hw_params @ 0010ea00 size=732
// signature: undefined aw869xx_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_hw_params(long param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined1 local_3c [4];
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_3c[0] = 0;
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_00132960,"haptic_hv",0x79,"aw869xx_hw_params");
    goto LAB_0010eca8;
  }
  uVar4 = *(undefined4 *)(param_2 + 0x128);
  uVar6 = *(uint *)(param_2 + 0x24);
  lVar8 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 != 0) {
      uVar7 = 0x20;
      goto LAB_0010ea90;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
LAB_0010ea90:
    uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
    uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
  }
  uVar3 = snd_pcm_format_width(uVar7);
  _printk(&DAT_00134ca7,"haptic_hv",0x7e,"aw869xx_hw_params",uVar4,uVar3);
  *(undefined4 *)(lVar8 + 0x40) = *(undefined4 *)(param_2 + 0x128);
  mutex_lock(lVar8 + 0x350);
  uVar6 = *(uint *)(param_2 + 0x24);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 != 0) {
      uVar7 = 0x20;
      goto LAB_0010eb00;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
LAB_0010eb00:
    uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
    uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
  }
  uVar4 = snd_pcm_format_width(uVar7);
  *(undefined4 *)(lVar8 + 0x44) = uVar4;
  _printk(&DAT_0013262c,"haptic_hv",0x87,"aw869xx_hw_params",uVar4);
  uVar6 = *(uint *)(param_2 + 0x24);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 != 0) {
      uVar7 = 0x20;
      goto LAB_0010eb5c;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
LAB_0010eb5c:
    uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
    uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
  }
  iVar5 = snd_pcm_format_width(uVar7);
  iVar1 = *(int *)(param_2 + 0x11c);
  iVar2 = *(int *)(lVar8 + 0x44);
  uVar6 = iVar1 * iVar5;
  if (iVar2 == 0x10) {
LAB_0010ebc8:
    uVar9 = 0;
  }
  else if (iVar2 == 0x20) {
    uVar9 = 0x30;
  }
  else {
    if (iVar2 != 0x18) {
      uVar6 = iVar1 << 4;
      _printk(&DAT_001365a5,"haptic_hv",0x98,"aw869xx_hw_params");
      goto LAB_0010ebc8;
    }
    uVar6 = iVar1 << 5;
    uVar9 = 0x20;
  }
  _printk(&DAT_00133c7b,"haptic_hv",0x9b,"aw869xx_hw_params",uVar9);
  haptic_hv_i2c_write_bits(lVar8,0x4a,0xffffffcf,uVar9);
  uVar7 = uVar6 & 0xff;
  if (uVar7 == 0x20) {
LAB_0010ec54:
    uVar9 = 0;
  }
  else if (uVar7 == 0x40) {
    uVar9 = 8;
  }
  else {
    if (uVar7 != 0x30) {
      _printk(&DAT_0013495a,"haptic_hv",0xac,"aw869xx_hw_params",uVar6 & 0xff);
      goto LAB_0010ec54;
    }
    uVar9 = 4;
  }
  haptic_hv_i2c_write_bits(lVar8,0x4a,0xfffffff3,uVar9);
  haptic_hv_i2c_reads(lVar8,0x4a,local_3c,1);
  _printk(&DAT_0013528f,"haptic_hv",0xb6,"aw869xx_hw_params",local_3c[0]);
  mutex_unlock(lVar8 + 0x350);
LAB_0010eca8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw869xx_codec_probe @ 0010ece0 size=160
// signature: undefined aw869xx_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw869xx_codec_probe(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0x120,"aw869xx_codec_probe");
  *(long *)(lVar1 + 0x270) = param_1;
  _printk(&DAT_00132e8a,"haptic_hv",0x119,"aw869xx_add_codec_controls");
  _printk(&DAT_00132b8d,"haptic_hv",0x126,"aw869xx_codec_probe");
  return 0;
}



//------------------------------------------------------------
// aw869xx_codec_remove @ 0010ed84 size=56
// signature: undefined aw869xx_codec_remove(void)
// callers: []
//------------------------------------------------------------

void aw869xx_codec_remove(void)

{
  _printk(&DAT_00132e8a,"haptic_hv",0x132,"aw869xx_codec_remove");
  return;
}



//------------------------------------------------------------
// aw869xx_codec_read @ 0010edc0 size=192
// signature: undefined aw869xx_codec_read(void)
// callers: []
//------------------------------------------------------------

int aw869xx_codec_read(long param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0x147,"aw869xx_codec_read");
  iVar2 = haptic_hv_i2c_reads(uVar3,param_2,local_2c,1);
  if (iVar2 < 0) {
    _printk(&DAT_001318a6,"haptic_hv",0x14b,"aw869xx_codec_read");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw869xx_codec_write @ 0010ee84 size=152
// signature: undefined aw869xx_codec_write(void)
// callers: []
//------------------------------------------------------------

void aw869xx_codec_write(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = (undefined1)param_3;
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98);
  _printk(&DAT_00133230,"haptic_hv",0x158,"aw869xx_codec_write",param_2,param_3);
  haptic_hv_i2c_writes(uVar2,param_2,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_get_f0 @ 0010ef20 size=912
// signature: undefined aw8671x_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_get_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  int iVar7;
  undefined8 uVar8;
  byte local_48 [4];
  char local_44 [4];
  undefined1 local_40;
  undefined2 local_3f;
  ushort local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw8671x_stop();
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  _printk(&DAT_001331a6,"haptic_hv",0x291,"aw8671x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x252,"aw8671x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffef,0);
  haptic_hv_i2c_write_bits(param_1,0x50,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_reads(param_1,8,local_48,1);
  bVar4 = local_48[0];
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  local_40 = *(undefined1 *)(param_1 + 0x563);
  local_3f = *(undefined2 *)(param_1 + 0x566);
  haptic_hv_i2c_writes(param_1,0x1e,&local_40,3);
  if (*(char *)(param_1 + 0x568) == '\0') {
    _printk(&DAT_001338cf,"haptic_hv",0x4d2,"aw8671x_get_f0");
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  else {
    haptic_hv_i2c_writes(param_1,0x22,param_1 + 0x568,1);
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  if (uVar1 == 0) {
    uVar8 = 0xffffffde;
  }
  else {
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 240000 / uVar1;
    }
    iVar7 = (uVar2 - ((uint)*(byte *)(param_1 + 0x565) + (uint)*(byte *)(param_1 + 0x568))) + -8;
    if (0xfe < iVar7) {
      iVar7 = 0xff;
    }
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    local_40 = (undefined1)iVar7;
    haptic_hv_i2c_writes(param_1,0x1a,&local_40,1);
    aw8671x_play_go(param_1,1);
    usleep_range_state(20000,0x5014,2);
    iVar7 = -100;
    do {
      local_44[0] = '\0';
      haptic_hv_i2c_reads(param_1,0x3f,local_44,1);
      if (local_44[0] == '\0') {
        puVar6 = &DAT_00136940;
        uVar8 = 0x23d;
        goto LAB_0010f1f8;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar5 = iVar7 != -1;
      iVar7 = iVar7 + 1;
    } while (bVar5);
    puVar6 = &DAT_00137ca1;
    uVar8 = 0x243;
LAB_0010f1f8:
    _printk(puVar6,"haptic_hv",uVar8,"aw8671x_wait_enter_standby");
    local_3c[0] = 0;
    haptic_hv_i2c_reads(param_1,0x25,local_3c,2);
    uVar1 = (uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8;
    if (uVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      _printk(&DAT_00132236,"haptic_hv",0x498,"aw8671x_read_f0");
      uVar8 = 0xffffffde;
    }
    else {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = 0x3a9800 / uVar1;
      }
      *(uint *)(param_1 + 100) = uVar2;
      _printk(&DAT_00136043,"haptic_hv",0x49d,"aw8671x_read_f0");
      uVar8 = 0;
    }
    haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,bVar4 & 4);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// aw8671x_ram_get_f0 @ 0010f2b4 size=960
// signature: undefined aw8671x_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_ram_get_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  int iVar10;
  byte local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  char local_40 [4];
  ushort local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_4c[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    puVar6 = &DAT_001325b9;
    uVar7 = 0x4f8;
  }
  else {
    if (4 < *(byte *)(param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
      aw8671x_stop(param_1);
      haptic_hv_i2c_write_bits(param_1,0x52,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
      _printk(&DAT_00136db2,"haptic_hv",0x26b,"aw8671x_play_mode");
      *(undefined1 *)(param_1 + 0xb) = 1;
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,0);
      _printk(&DAT_00136a5b,"haptic_hv",0x24c,"aw8671x_bst_mode_config");
      haptic_hv_i2c_write_bits(param_1,6,0xffffffef,0x10);
      haptic_hv_i2c_write_bits(param_1,0x50,0xffffffbf,0);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
      haptic_hv_i2c_reads(param_1,8,local_4c,1);
      bVar4 = local_4c[0];
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
      haptic_hv_i2c_write_bits(param_1,6,0xfffffff0,4);
      local_48[0] = 5;
      haptic_hv_i2c_writes(param_1,10,local_48,1);
      local_44[0] = 0;
      haptic_hv_i2c_writes(param_1,0xb,local_44,1);
      haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0x20);
      aw8671x_play_go(param_1,1);
      usleep_range_state(20000,0x5014,2);
      iVar10 = -100;
      do {
        local_40[0] = '\0';
        haptic_hv_i2c_reads(param_1,0x3f,local_40,1);
        if (local_40[0] == '\0') {
          puVar6 = &DAT_00136940;
          uVar7 = 0x23d;
          goto LAB_0010f528;
        }
        usleep_range_state(2000,0x9c4,2);
        bVar5 = iVar10 != -1;
        iVar10 = iVar10 + 1;
      } while (bVar5);
      puVar6 = &DAT_00137ca1;
      uVar7 = 0x243;
LAB_0010f528:
      _printk(puVar6,"haptic_hv",uVar7,"aw8671x_wait_enter_standby");
      local_3c[0] = 0;
      haptic_hv_i2c_reads(param_1,0x25,local_3c,2);
      uVar1 = (uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8;
      if (uVar1 == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        _printk(&DAT_00132236,"haptic_hv",0x498,"aw8671x_read_f0");
        uVar7 = 0xffffffde;
      }
      else {
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = 0x3a9800 / uVar1;
        }
        *(uint *)(param_1 + 100) = uVar2;
        _printk(&DAT_00136043,"haptic_hv",0x49d,"aw8671x_read_f0");
        uVar7 = 0;
      }
      uVar1 = *(uint *)(param_1 + 0x38);
      if (uVar1 >> 2 < 0x52d) {
        uVar9 = 0;
      }
      else if (uVar1 >> 5 < 0xaf) {
        uVar9 = 1;
      }
      else if (uVar1 >> 3 < 0x2d5) {
        uVar9 = 2;
      }
      else {
        uVar9 = 3;
        if (0x626 < uVar1 >> 2) {
          uVar9 = 4;
        }
      }
      haptic_hv_i2c_write_bits(param_1,6,0xfffffff0,uVar9);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
      if ((bVar4 >> 2 & 1) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 4;
      }
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar8);
      goto LAB_0010f640;
    }
    puVar6 = &DAT_00132b34;
    uVar7 = 0x4fc;
  }
  _printk(puVar6,"haptic_hv",uVar7,"aw8671x_ram_get_f0");
  uVar7 = 0xffffffde;
LAB_0010f640:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// aw8671x_creat_node @ 0010f678 size=100
// signature: undefined aw8671x_creat_node(void)
// callers: []
//------------------------------------------------------------

int aw8671x_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw8671x_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_00132ba3,"haptic_hv",0x7a0,"aw8671x_creat_node");
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw8671x_offset_cali @ 0010f6e0 size=8
// signature: undefined aw8671x_offset_cali(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_offset_cali(void)

{
  return 0;
}



//------------------------------------------------------------
// aw8671x_get_irq_state @ 0010f6ec size=392
// signature: undefined aw8671x_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  if ((local_1c[0] >> 6 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    _printk(&DAT_001352af,"haptic_hv",0x46b,"aw8671x_get_irq_state");
    uVar2 = 8;
  }
  if ((local_1c[0] >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x470,"aw8671x_get_irq_state");
    uVar2 = 5;
  }
  if ((local_1c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x475,"aw8671x_get_irq_state");
    uVar2 = 6;
  }
  if ((local_1c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x47a,"aw8671x_get_irq_state");
    uVar2 = 7;
  }
  if ((local_1c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",0x47f,"aw8671x_get_irq_state");
    uVar2 = 10;
  }
  if ((local_1c[0] >> 3 & 1) != 0) {
    _printk(&DAT_00131f9b,"haptic_hv",0x483,"aw8671x_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_1c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_check_qualify @ 0010f878 size=192
// signature: undefined aw8671x_check_qualify(void)
// callers: []
//------------------------------------------------------------

void aw8671x_check_qualify(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  _printk(&DAT_00132e8a,"haptic_hv",0x189,"aw8671x_check_qualify");
  uVar2 = haptic_hv_i2c_reads(param_1,0x61,local_2c,1);
  if (-1 < (int)uVar2) {
    if (local_2c[0] < '\0') {
      uVar2 = 0;
    }
    else {
      _printk(&DAT_0013785a,"haptic_hv",0x18e,"aw8671x_check_qualify");
      uVar2 = 0xffffffde;
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
// aw8671x_judge_rtp_going @ 0010f93c size=144
// signature: undefined aw8671x_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw8671x_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  bVar2 = local_1c[0] == '\b';
  if (bVar2) {
    _printk(&DAT_00134c3c,"haptic_hv",0x412,"aw8671x_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_container_update @ 0010f9d0 size=856
// signature: undefined aw8671x_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_container_update(long param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  ushort uVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 local_468 [4];
  undefined2 local_464;
  byte local_462;
  undefined1 local_461;
  undefined1 local_460;
  undefined2 local_45c;
  byte local_45a;
  char local_458 [1024];
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_45a = 0;
  local_45c = 0;
  memset(local_458,0,0x400);
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  aw8671x_stop(param_1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  bVar1 = *(byte *)(param_1 + 0x527);
  bVar2 = *(byte *)((long)param_2 + (ulong)bVar1 + 4);
  uVar4 = CONCAT11(bVar2,*(undefined1 *)((long)param_2 + (ulong)bVar1 + 5));
  local_461 = (undefined1)(uVar4 >> 1);
  iVar7 = (uint)uVar4 - (uint)(uVar4 >> 2);
  *(uint *)(param_1 + 0x520) = (uint)uVar4;
  local_464 = *(undefined2 *)((long)param_2 + (ulong)bVar1 + 4);
  local_462 = (bVar2 & 0xfe) << 3 | (byte)((uint)iVar7 >> 8) & 0xf;
  local_460 = (undefined1)iVar7;
  _printk(&DAT_00136e85,"haptic_hv",0x61c,"aw8671x_container_update");
  haptic_hv_i2c_writes(param_1,0x2d,&local_464,5);
  haptic_hv_i2c_reads(param_1,0x2f,&local_45c,3);
  bVar1 = (byte)local_45c;
  _printk(&DAT_001344e9,"haptic_hv",0x621,"aw8671x_container_update",
          CONCAT11((byte)local_45c >> 4,local_45c._1_1_));
  _printk(&DAT_001351c2,"haptic_hv",0x623,"aw8671x_container_update",
          (uint)local_45a | (bVar1 & 0xf) << 8);
  local_468[0] = (undefined1)*(uint *)(param_1 + 0x520);
  haptic_hv_i2c_write_bits(param_1,0x40,0xfffffff0,*(uint *)(param_1 + 0x520) >> 8);
  haptic_hv_i2c_writes(param_1,0x41,local_468,1);
  uVar9 = (uint)*(byte *)(param_1 + 0x526);
  iVar7 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar7) {
    do {
      iVar10 = iVar7 - uVar9;
      if (0x7ff < iVar10) {
        iVar10 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar9 + 4,iVar10);
      iVar7 = *param_2;
      uVar9 = iVar10 + uVar9;
    } while ((int)uVar9 < iVar7);
  }
  local_468[0] = (undefined1)*(uint *)(param_1 + 0x520);
  haptic_hv_i2c_write_bits(param_1,0x40,0xfffffff0,*(uint *)(param_1 + 0x520) >> 8);
  haptic_hv_i2c_writes(param_1,0x41,local_468,1);
  uVar9 = (uint)*(byte *)(param_1 + 0x526);
  iVar7 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar7) {
    do {
      uVar11 = iVar7 - uVar9;
      if (0x3ff < (int)uVar11) {
        uVar11 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,local_458,uVar11);
      if (uVar11 != 0) {
        uVar6 = 0;
        do {
          if (0x3ff < uVar6) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(1,0x10fd24);
            (*pcVar5)();
          }
          if (local_458[(int)uVar6] !=
              *(char *)((long)param_2 + (long)(int)uVar6 + (long)(int)uVar9 + 4)) {
            _printk(&DAT_001373f1,"haptic_hv",0x5ed,"aw8671x_check_ram_data");
            _printk(&DAT_001351ee,"haptic_hv",0x640,"aw8671x_container_update");
            uVar8 = 0xffffffde;
            goto LAB_0010fccc;
          }
          uVar6 = uVar6 + 1;
        } while (uVar11 != uVar6);
      }
      iVar7 = *param_2;
      uVar9 = uVar11 + uVar9;
    } while ((int)uVar9 < iVar7);
  }
  _printk(&DAT_00132afb,"haptic_hv",0x642,"aw8671x_container_update");
  uVar8 = 0;
LAB_0010fccc:
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  mutex_unlock(param_1 + 0x350);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// aw8671x_stop @ 0010fd2c size=452
// signature: undefined aw8671x_stop(void)
// callers: [aw8671x_get_vbat, aw8671x_get_f0, aw8671x_container_update, aw8671x_get_lra_resistance, aw8671x_ram_get_f0]
//------------------------------------------------------------

void aw8671x_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x2b3,"aw8671x_stop");
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_30[0] = 1;
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,3);
  haptic_hv_i2c_writes(param_1,9,local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  iVar3 = -100;
  do {
    local_2c[0] = '\0';
    haptic_hv_i2c_reads(param_1,0x3f,local_2c,1);
    if (local_2c[0] == '\0') {
      _printk(&DAT_00136940,"haptic_hv",0x23d,"aw8671x_wait_enter_standby");
      goto LAB_0010fec4;
    }
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar3 != -1;
    iVar3 = iVar3 + 1;
  } while (bVar2);
  _printk(&DAT_00137ca1,"haptic_hv",0x243,"aw8671x_wait_enter_standby");
  _printk(&DAT_00135cf9,"haptic_hv",0x2be,"aw8671x_stop");
  _printk(&DAT_00134895,"haptic_hv",0x261,"aw8671x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 0;
  haptic_hv_i2c_write_bits(param_1,0x44,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x44,0xffffffdf,0);
LAB_0010fec4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_get_vbat @ 0010fef4 size=436
// signature: undefined aw8671x_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_vbat(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined2 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  aw8671x_stop();
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xffffff87,0);
  haptic_hv_i2c_write_bits(param_1,0x51,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x51,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x54,&local_2c,2);
  uVar1 = (uint)local_2c._1_1_ | ((byte)local_2c & 0xf) << 8;
  uVar2 = uVar1 * 0x17a2;
  uVar4 = (ulong)uVar2 / 0xfff;
  *(uint *)(param_1 + 0x70) = uVar2 / 0xfff;
  if (0x1193e6a < uVar2) {
    *(undefined4 *)(param_1 + 0x70) = 0x1194;
    _printk(&DAT_001328b9,"haptic_hv",0x5ac,"aw8671x_get_vbat",0x1194);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  if ((uint)uVar4 < 3000) {
    *(undefined4 *)(param_1 + 0x70) = 3000;
    _printk(&DAT_00135218,"haptic_hv",0x5b0,"aw8671x_get_vbat",3000);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  _printk(&DAT_00132353,"haptic_hv",0x5b2,"aw8671x_get_vbat",uVar4,uVar1);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_cont_config @ 001100ac size=320
// signature: undefined aw8671x_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw8671x_cont_config(long param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0xff;
  _printk(&DAT_001331a6,"haptic_hv",0x291,"aw8671x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x252,"aw8671x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffef,0);
  haptic_hv_i2c_write_bits(param_1,0x50,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits
            (param_1,0x1d,0xffffff00,
             (uint)*(byte *)(param_1 + 0x562) | (uint)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_writes(param_1,0x1e,param_1 + 0x563,1);
  haptic_hv_i2c_writes(param_1,0x20,local_2c,1);
  aw8671x_play_go(param_1,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_play_go @ 001101f0 size=220
// signature: undefined aw8671x_play_go(void)
// callers: [aw8671x_get_f0, aw8671x_cont_config, aw8671x_ram_get_f0]
//------------------------------------------------------------

void aw8671x_play_go(long param_1,ulong param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 1;
  local_30[0] = 0x75;
  local_34[0] = 1;
  local_38[0] = 2;
  if ((param_2 & 1) == 0) {
    puVar3 = local_38;
  }
  else {
    if (*(char *)(param_1 + 0x58e) != '\0') {
      haptic_hv_i2c_writes(param_1,0x3c,local_2c,1);
      haptic_hv_i2c_writes(param_1,9,local_34,1);
      usleep_range_state(1000,0x5dc,2);
      puVar3 = local_30;
      uVar2 = 0x3c;
      goto LAB_00110298;
    }
    puVar3 = local_34;
  }
  uVar2 = 9;
LAB_00110298:
  haptic_hv_i2c_writes(param_1,uVar2,puVar3,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_ram_init @ 001102d0 size=80
// signature: undefined aw8671x_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw8671x_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
    usleep_range_state(500,600,2);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_set_bst_peak_cur @ 00110324 size=4
// signature: undefined aw8671x_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_bst_peak_cur(void)

{
  return;
}



//------------------------------------------------------------
// aw8671x_get_lra_resistance @ 0011032c size=428
// signature: undefined aw8671x_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_lra_resistance(long param_1)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  undefined2 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  aw8671x_stop();
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,8);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xffffff87,0x20);
  haptic_hv_i2c_reads(param_1,0x51,&local_3c,1);
  bVar2 = (byte)local_3c;
  haptic_hv_i2c_write_bits(param_1,0x51,0xfffffff3,0xc);
  haptic_hv_i2c_reads(param_1,0x52,&local_3c,1);
  bVar3 = (byte)local_3c;
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffff8,4);
  haptic_hv_i2c_write_bits(param_1,0x51,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x51,0xfffffffc,0);
  haptic_hv_i2c_write_bits(param_1,0x43,0xfffffff7,0);
  haptic_hv_i2c_write_bits(param_1,0x51,0xfffffff3,bVar2 & 0xc);
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffff8,bVar3 & 7);
  haptic_hv_i2c_reads(param_1,0x54,&local_3c,2);
  *(uint *)(param_1 + 0x6c) =
       (((uint)local_3c._1_1_ | ((byte)local_3c & 0xf) << 8) * 0x28165) / 10000;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_set_pwm @ 001104dc size=68
// signature: undefined aw8671x_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_pwm(undefined8 param_1,uint param_2)

{
  if ((param_2 & 0xff) < 3) {
    haptic_hv_i2c_write_bits(param_1,0x44,0xfffffffc,0x20001 >> (ulong)((param_2 & 3) << 3));
  }
  return;
}



//------------------------------------------------------------
// aw8671x_set_gain @ 00110524 size=88
// signature: undefined aw8671x_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_play_mode @ 00110580 size=760
// signature: undefined aw8671x_play_mode(void)
// callers: []
//------------------------------------------------------------

void aw8671x_play_mode(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0x261,"aw8671x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    haptic_hv_i2c_write_bits(param_1,0x44,0xffffffdf,0x20);
    uVar1 = 0x44;
    uVar2 = 0xffffffdf;
    goto LAB_00110860;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",0x26b,"aw8671x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 1;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    uVar1 = 0;
    break;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x27f,"aw8671x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,1);
    uVar1 = 4;
    break;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x289,"aw8671x_play_mode");
    uVar1 = 8;
    uVar2 = 0xfffffffc;
    *(undefined1 *)(param_1 + 0xb) = 3;
    goto LAB_0011084c;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x291,"aw8671x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 4;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x252,"aw8671x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffef,0);
    uVar1 = 0x50;
    uVar2 = 0xffffffbf;
    uVar3 = 0x40;
    goto LAB_00110864;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0x275,"aw8671x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 5;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x252,"aw8671x_bst_mode_config");
    uVar1 = 6;
    uVar2 = 0xffffffef;
LAB_0011084c:
    uVar3 = 0;
    goto LAB_00110850;
  default:
    _printk(&DAT_001348de,"haptic_hv",0x29b,"aw8671x_play_mode");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar1);
  _printk(&DAT_00136a5b,"haptic_hv",0x24c,"aw8671x_bst_mode_config");
  uVar1 = 6;
  uVar2 = 0xffffffef;
  uVar3 = 0x10;
LAB_00110850:
  haptic_hv_i2c_write_bits(param_1,uVar1,uVar2,uVar3);
  uVar1 = 0x50;
  uVar2 = 0xffffffbf;
LAB_00110860:
  uVar3 = 0;
LAB_00110864:
  haptic_hv_i2c_write_bits(param_1,uVar1,uVar2,uVar3);
  return;
}



//------------------------------------------------------------
// aw8671x_set_bst_vol @ 0011087c size=108
// signature: undefined aw8671x_set_bst_vol(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_bst_vol(undefined8 param_1,ulong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (uint)(param_2 >> 2) & 0x3fffffff;
  if (uVar1 < 0x52d) {
    uVar2 = 0;
  }
  else if (((uint)(param_2 >> 5) & 0x7ffffff) < 0xaf) {
    uVar2 = 1;
  }
  else if (((uint)(param_2 >> 3) & 0x1fffffff) < 0x2d5) {
    uVar2 = 2;
  }
  else {
    uVar2 = 3;
    if (0x626 < uVar1) {
      uVar2 = 4;
    }
  }
  haptic_hv_i2c_write_bits(param_1,6,0xfffffff0,uVar2);
  return;
}



//------------------------------------------------------------
// aw8671x_set_repeat_seq @ 001108ec size=120
// signature: undefined aw8671x_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,10,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_auto_bst_enable @ 00110968 size=52
// signature: undefined aw8671x_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw8671x_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,8,0xffffffef,(ulong)(param_2 != '\0') << 4);
  return;
}



//------------------------------------------------------------
// aw8671x_vbat_mode_config @ 001109a0 size=52
// signature: undefined aw8671x_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8671x_vbat_mode_config(undefined8 param_1,char param_2)

{
  haptic_hv_i2c_write_bits(param_1,0x50,0xffffffbf,(ulong)(param_2 == '\x01') << 6);
  return;
}



//------------------------------------------------------------
// aw8671x_set_wav_seq @ 001109d8 size=88
// signature: undefined aw8671x_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 10,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_set_wav_loop @ 00110a34 size=64
// signature: undefined aw8671x_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0x12,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw8671x_set_rtp_data @ 00110a78 size=40
// signature: undefined aw8671x_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,0x32,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw8671x_protect_config @ 00110aa4 size=256
// signature: undefined aw8671x_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw8671x_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x303,"aw8671x_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",0x2fc,"aw8671x_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x4e,local_40,1);
    haptic_hv_i2c_writes(param_1,0x4f,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_parse_dt @ 00110ba8 size=1296
// signature: undefined aw8671x_parse_dt(void)
// callers: []
//------------------------------------------------------------

void aw8671x_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined2 local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_52 = 0;
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_gain_bypass",param_2 + 0x55f,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001318e0,"haptic_hv",0x667,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x66a,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_f0_cali_percent",param_2 + 0x529,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00135735,"haptic_hv",0x66d,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_cont_drv1_lvl",param_2 + 0x562,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137501,"haptic_hv",0x670,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8671x_cont_lra_vrms",param_2 + 0x584,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137e24,"haptic_hv",0x673,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_cont_drv1_time",param_2 + 0x566,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013326d,"haptic_hv",0x676,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_cont_drv2_time",param_2 + 0x567,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001342bc,"haptic_hv",0x679,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_cont_brk_gain",param_2 + 0x565,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001365f9,"haptic_hv",0x67c,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_d2s_gain",param_2 + 0x55d,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001378f2,"haptic_hv",0x67f,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_cont_brk_time",param_2 + 0x564,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136209,"haptic_hv",0x682,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw8671x_cont_track_margin",param_2 + 0x568,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001352d8,"haptic_hv",0x686,"aw8671x_parse_dt");
  }
  lVar2 = of_find_property(param_3,"aw8671x_is_enabled_track_en",0);
  *(bool *)(param_2 + 0x588) = lVar2 != 0;
  _printk(&DAT_00137abd,"haptic_hv",0x689,"aw8671x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8671x_is_enabled_auto_bst",0);
  *(bool *)(param_2 + 0x58c) = lVar2 != 0;
  _printk(&DAT_00134902,"haptic_hv",0x68c,"aw8671x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8671x_is_enabled_i2s",0);
  *(bool *)(param_2 + 0x58d) = lVar2 != 0;
  _printk(&DAT_0013387b,"haptic_hv",0x68e,"aw8671x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8671x_is_enabled_one_wire",0);
  *(bool *)(param_2 + 0x58e) = lVar2 != 0;
  _printk(&DAT_00133c22,"haptic_hv",0x691,"aw8671x_parse_dt");
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_duration_time",&local_54,3,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134cf0,"haptic_hv",0x695,"aw8671x_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_54;
    *(undefined1 *)(param_2 + 0x52c) = local_52;
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8671x_bst_vol_default",param_2 + 0x534,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00137b29,"haptic_hv",0x69a,"aw8671x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8671x_trig_config",&local_50,0x18,0);
  if (iVar1 < 0) {
    _printk(&DAT_001342ee,"haptic_hv",0x69e,"aw8671x_parse_dt");
  }
  else {
    *(undefined8 *)(param_2 + 0x569) = local_50;
    *(undefined8 *)(param_2 + 0x571) = local_48;
    *(undefined8 *)(param_2 + 0x579) = local_40;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_trig_init @ 001110bc size=988
// signature: undefined aw8671x_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw8671x_trig_init(long param_1)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  _printk(&DAT_0013233b,"haptic_hv",0x5d1,"aw8671x_trig_init");
  if (*(char *)(param_1 + 0x58e) == '\0') {
    cVar2 = *(char *)(param_1 + 0x569);
    *(undefined1 *)(param_1 + 0x6c9) = *(undefined1 *)(param_1 + 0x56b);
    *(undefined1 *)(param_1 + 0x6cb) = *(undefined1 *)(param_1 + 0x56c);
    *(char *)(param_1 + 0x6c7) = cVar2;
    *(char *)(param_1 + 0x6c8) = *(char *)(param_1 + 0x56a);
    uVar1 = (uint)(cVar2 != '\0') << 6;
    if (*(char *)(param_1 + 0x56a) != '\0') {
      uVar1 = (uint)(cVar2 != '\0') << 6 | 0xffffff80;
    }
    *(undefined1 *)(param_1 + 0x6ca) = *(undefined1 *)(param_1 + 0x56d);
    if (*(char *)(param_1 + 0x56f) != '\0') {
      uVar1 = uVar1 | 0x20;
    }
    if (*(char *)(param_1 + 0x570) != '\0') {
      uVar1 = uVar1 | 0x10;
    }
    *(char *)(param_1 + 0x6c5) = *(char *)(param_1 + 0x56f);
    *(char *)(param_1 + 0x6c6) = *(char *)(param_1 + 0x570);
    *(undefined1 *)(param_1 + 0x6cc) = *(undefined1 *)(param_1 + 0x56e);
    haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
    haptic_hv_i2c_write_bits
              (param_1,0x33,0xffffff00,
               *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7);
    uVar5 = 0x36;
    uVar6 = 0xffffff00;
    bVar7 = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
  }
  else {
    _printk(&DAT_00137af7,"haptic_hv",0x5d3,"aw8671x_trig_init");
    local_2c[0] = 0x6c;
    local_30[0] = 0x75;
    _printk(&DAT_00132e8a,"haptic_hv",0x324,"aw8671x_one_wire_init");
    haptic_hv_i2c_writes(param_1,0x3e,local_2c,1);
    haptic_hv_i2c_writes(param_1,0x3c,local_30,1);
    uVar5 = 0x3a;
    uVar6 = 0xfffffff7;
    bVar7 = 8;
  }
  haptic_hv_i2c_write_bits(param_1,uVar5,uVar6,bVar7);
  if ((*(char *)(param_1 + 0x58d) == '\0') || (*(char *)(param_1 + 4) == '\0')) {
    cVar2 = *(char *)(param_1 + 0x571);
    *(undefined1 *)(param_1 + 0x6d6) = *(undefined1 *)(param_1 + 0x573);
    *(char *)(param_1 + 0x6d4) = cVar2;
    *(undefined1 *)(param_1 + 0x6d9) = *(undefined1 *)(param_1 + 0x576);
    *(char *)(param_1 + 0x6d5) = *(char *)(param_1 + 0x572);
    *(undefined1 *)(param_1 + 0x6d8) = *(undefined1 *)(param_1 + 0x574);
    *(undefined1 *)(param_1 + 0x6d7) = *(undefined1 *)(param_1 + 0x575);
    *(undefined1 *)(param_1 + 0x6e2) = *(undefined1 *)(param_1 + 0x57a);
    *(char *)(param_1 + 0x6d2) = *(char *)(param_1 + 0x577);
    bVar7 = (cVar2 != '\0') << 2;
    if (*(char *)(param_1 + 0x572) != '\0') {
      bVar7 = (cVar2 != '\0') << 2 | 8;
    }
    *(undefined1 *)(param_1 + 0x6e1) = *(undefined1 *)(param_1 + 0x579);
    *(undefined1 *)(param_1 + 0x6e3) = *(undefined1 *)(param_1 + 0x57b);
    if (*(char *)(param_1 + 0x577) != '\0') {
      bVar7 = bVar7 | 2;
    }
    *(undefined1 *)(param_1 + 0x6e5) = *(undefined1 *)(param_1 + 0x57c);
    *(char *)(param_1 + 0x6d3) = *(char *)(param_1 + 0x578);
    *(undefined1 *)(param_1 + 0x6e6) = *(undefined1 *)(param_1 + 0x57e);
    *(undefined1 *)(param_1 + 0x6e4) = *(undefined1 *)(param_1 + 0x57d);
    *(undefined2 *)(param_1 + 0x6df) = *(undefined2 *)(param_1 + 0x57f);
    haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar7 | *(char *)(param_1 + 0x578) != '\0');
    haptic_hv_i2c_write_bits
              (param_1,0x34,0xffffff00,
               *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7);
    haptic_hv_i2c_write_bits
              (param_1,0x37,0xffffff00,
               *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7);
    bVar4 = *(char *)(param_1 + 0x6e1) != '\0';
    uVar1 = (uint)bVar4 << 6;
    if (*(char *)(param_1 + 0x6e2) != '\0') {
      uVar1 = (uint)bVar4 << 6 | 0xffffff80;
    }
    if (*(char *)(param_1 + 0x6df) != '\0') {
      uVar1 = uVar1 | 0x20;
    }
    if (*(char *)(param_1 + 0x6e0) != '\0') {
      uVar1 = uVar1 | 0x10;
    }
    haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
    haptic_hv_i2c_write_bits
              (param_1,0x35,0xffffff00,
               *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7);
    uVar5 = 0x38;
    uVar6 = 0xffffff00;
    bVar7 = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  }
  else {
    _printk(&DAT_00134fcc,"haptic_hv",0x5da,"aw8671x_trig_init");
    _printk(&DAT_00132e8a,"haptic_hv",0x32f,"aw8671x_i2s_init");
    uVar5 = 0x44;
    uVar6 = 0xfffffffb;
    bVar7 = 4;
  }
  haptic_hv_i2c_write_bits(param_1,uVar5,uVar6,bVar7);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_irq_clear @ 0011149c size=124
// signature: undefined aw8671x_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw8671x_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x454,"aw8671x_irq_clear",local_1c[0]);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_set_ram_addr @ 0011151c size=124
// signature: undefined aw8671x_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_ram_addr(long param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = (undefined1)*(uint *)(param_1 + 0x520);
  haptic_hv_i2c_write_bits(param_1,0x40,0xfffffff0,*(uint *)(param_1 + 0x520) >> 8);
  haptic_hv_i2c_writes(param_1,0x41,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_misc_para_init @ 0011159c size=568
// signature: undefined aw8671x_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw8671x_misc_para_init(long param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  ulong local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = (ulong)*(byte *)(*(long *)(param_1 + 0x2c8) + 2);
  haptic_hv_i2c_writes(param_1,0x46,&local_30,1);
  iVar5 = 0x711;
  if (0x707 < *(uint *)(param_1 + 0x530)) {
    iVar5 = 0x7c6;
  }
  uVar2 = iVar5 * *(int *)(param_1 + 0x584);
  uVar4 = 0x7f;
  if (uVar2 >> 0xd < 0x271) {
    uVar4 = (undefined1)(uVar2 / 40000);
  }
  *(undefined1 *)(param_1 + 0x563) = uVar4;
  if (*(int *)(param_1 + 0x534) != 0) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x534);
  }
  haptic_hv_i2c_reads(param_1,7,&local_30,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_30;
  haptic_hv_i2c_reads(param_1,10,&local_30,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_30;
  *(ulong *)(param_1 + 0x11) = local_30;
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffd,(ulong)*(byte *)(param_1 + 0x55f) << 1);
  cVar1 = *(char *)(param_1 + 0x55d);
  if (cVar1 == '\0') {
    _printk(&DAT_00136555,"haptic_hv",0x6c3,"aw8671x_misc_para_init");
    cVar1 = *(char *)(param_1 + 0x55d);
  }
  haptic_hv_i2c_write_bits(param_1,0x52,0xfffffff8,cVar1);
  if (*(char *)(param_1 + 0x564) == '\0') {
    _printk(&DAT_0013618a,"haptic_hv",0x6c9,"aw8671x_misc_para_init");
  }
  haptic_hv_i2c_writes(param_1,0x21,param_1 + 0x564,1);
  cVar1 = *(char *)(param_1 + 0x565);
  if (cVar1 == '\0') {
    _printk(&DAT_00136ea5,"haptic_hv",0x6cf,"aw8671x_misc_para_init");
    cVar1 = *(char *)(param_1 + 0x565);
  }
  haptic_hv_i2c_write_bits(param_1,0x1c,0xfffffff0,cVar1);
  local_34[0] = 0x32;
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",0x2fc,"aw8671x_protect_config");
  local_38[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x4e,local_38,1);
  haptic_hv_i2c_writes(param_1,0x4f,local_34,1);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_interrupt_setup @ 001117d8 size=176
// signature: undefined aw8671x_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw8671x_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x3f7,"aw8671x_interrupt_setup",local_2c[0]);
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffcf,0x10);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff99,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_set_rtp_aei @ 0011188c size=48
// signature: undefined aw8671x_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw8671x_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw8671x_upload_lra @ 001118c0 size=248
// signature: undefined aw8671x_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw8671x_upload_lra(long param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 2) {
    _printk(&DAT_001323a9,"haptic_hv",0x2d2,"aw8671x_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 0) {
        _printk(&DAT_00136e0b,"haptic_hv",0x2c7,"aw8671x_upload_lra");
        haptic_hv_i2c_write_bits(param_1,0x5a,0xffffffc0,0);
        return;
      }
      _printk(&DAT_00132648,"haptic_hv",0x2d8,"aw8671x_upload_lra");
      return;
    }
    _printk(&DAT_001378a9,"haptic_hv",0x2cc,"aw8671x_upload_lra",*(undefined4 *)(param_1 + 0x90));
    uVar1 = *(undefined4 *)(param_1 + 0x90);
  }
  haptic_hv_i2c_write_bits(param_1,0x5a,0xffffffc0,uVar1);
  return;
}



//------------------------------------------------------------
// aw8671x_get_wav_seq @ 001119bc size=236
// signature: undefined aw8671x_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,10,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_get_ram_data @ 00111aac size=120
// signature: undefined aw8671x_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_bst_mode_config @ 00111b28 size=200
// signature: undefined aw8671x_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8671x_bst_mode_config(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    _printk(&DAT_00135b17,"haptic_hv",0x252,"aw8671x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffef,0);
  }
  else if (param_2 == '\x01') {
    _printk(&DAT_00136a5b,"haptic_hv",0x24c,"aw8671x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffef,0x10);
  }
  else {
    _printk(&DAT_00133915,"haptic_hv",600,"aw8671x_bst_mode_config",param_2);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_get_first_wave_addr @ 00111bf4 size=112
// signature: undefined aw8671x_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8671x_get_wav_loop @ 00111c68 size=420
// signature: undefined aw8671x_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw8671x_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0x12,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw8671x_get_reg @ 00111e10 size=284
// signature: undefined aw8671x_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw8671x_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_c0 [120];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_c0[0x70] = 0;
  local_c0[0x71] = 0;
  local_c0[0x72] = 0;
  local_c0[0x73] = 0;
  local_c0[0x60] = 0;
  local_c0[0x61] = 0;
  local_c0[0x62] = 0;
  local_c0[99] = 0;
  local_c0[100] = 0;
  local_c0[0x65] = 0;
  local_c0[0x66] = 0;
  local_c0[0x67] = 0;
  local_c0[0x68] = 0;
  local_c0[0x69] = 0;
  local_c0[0x6a] = 0;
  local_c0[0x6b] = 0;
  local_c0[0x6c] = 0;
  local_c0[0x6d] = 0;
  local_c0[0x6e] = 0;
  local_c0[0x6f] = 0;
  local_c0[0x50] = 0;
  local_c0[0x51] = 0;
  local_c0[0x52] = 0;
  local_c0[0x53] = 0;
  local_c0[0x54] = 0;
  local_c0[0x55] = 0;
  local_c0[0x56] = 0;
  local_c0[0x57] = 0;
  local_c0[0x58] = 0;
  local_c0[0x59] = 0;
  local_c0[0x5a] = 0;
  local_c0[0x5b] = 0;
  local_c0[0x5c] = 0;
  local_c0[0x5d] = 0;
  local_c0[0x5e] = 0;
  local_c0[0x5f] = 0;
  local_c0[0x40] = 0;
  local_c0[0x41] = 0;
  local_c0[0x42] = 0;
  local_c0[0x43] = 0;
  local_c0[0x44] = 0;
  local_c0[0x45] = 0;
  local_c0[0x46] = 0;
  local_c0[0x47] = 0;
  local_c0[0x48] = 0;
  local_c0[0x49] = 0;
  local_c0[0x4a] = 0;
  local_c0[0x4b] = 0;
  local_c0[0x4c] = 0;
  local_c0[0x4d] = 0;
  local_c0[0x4e] = 0;
  local_c0[0x4f] = 0;
  local_c0[0x30] = 0;
  local_c0[0x31] = 0;
  local_c0[0x32] = 0;
  local_c0[0x33] = 0;
  local_c0[0x34] = 0;
  local_c0[0x35] = 0;
  local_c0[0x36] = 0;
  local_c0[0x37] = 0;
  local_c0[0x38] = 0;
  local_c0[0x39] = 0;
  local_c0[0x3a] = 0;
  local_c0[0x3b] = 0;
  local_c0[0x3c] = 0;
  local_c0[0x3d] = 0;
  local_c0[0x3e] = 0;
  local_c0[0x3f] = 0;
  local_c0[0x20] = 0;
  local_c0[0x21] = 0;
  local_c0[0x22] = 0;
  local_c0[0x23] = 0;
  local_c0[0x24] = 0;
  local_c0[0x25] = 0;
  local_c0[0x26] = 0;
  local_c0[0x27] = 0;
  local_c0[0x28] = 0;
  local_c0[0x29] = 0;
  local_c0[0x2a] = 0;
  local_c0[0x2b] = 0;
  local_c0[0x2c] = 0;
  local_c0[0x2d] = 0;
  local_c0[0x2e] = 0;
  local_c0[0x2f] = 0;
  local_c0[0x10] = 0;
  local_c0[0x11] = 0;
  local_c0[0x12] = 0;
  local_c0[0x13] = 0;
  local_c0[0x14] = 0;
  local_c0[0x15] = 0;
  local_c0[0x16] = 0;
  local_c0[0x17] = 0;
  local_c0[0x18] = 0;
  local_c0[0x19] = 0;
  local_c0[0x1a] = 0;
  local_c0[0x1b] = 0;
  local_c0[0x1c] = 0;
  local_c0[0x1d] = 0;
  local_c0[0x1e] = 0;
  local_c0[0x1f] = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[6] = 0;
  local_c0[7] = 0;
  local_c0[8] = 0;
  local_c0[9] = 0;
  local_c0[10] = 0;
  local_c0[0xb] = 0;
  local_c0[0xc] = 0;
  local_c0[0xd] = 0;
  local_c0[0xe] = 0;
  local_c0[0xf] = 0;
  haptic_hv_i2c_reads(param_1,0,local_c0,0x32);
  haptic_hv_i2c_reads(param_1,0x33,local_c0 + 0x33,0xf);
  haptic_hv_i2c_reads(param_1,0x43,local_c0 + 0x43,0x31);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 0x32) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_c0[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x74);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw8671x_get_prctmode @ 00111f30 size=96
// signature: undefined aw8671x_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw8671x_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x4e,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw8671x_get_trim_lra @ 00111f94 size=96
// signature: undefined aw8671x_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

byte aw8671x_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x5a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0x3f;
}



//------------------------------------------------------------
// aw8671x_get_glb_state @ 00111ff8 size=92
// signature: undefined aw8671x_get_glb_state(void)
// callers: []
//------------------------------------------------------------

void aw8671x_get_glb_state(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_get_osc_status @ 00112058 size=96
// signature: undefined aw8671x_get_osc_status(void)
// callers: []
//------------------------------------------------------------

byte aw8671x_get_osc_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw8671x_rtp_get_fifo_afs @ 001120bc size=96
// signature: undefined aw8671x_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw8671x_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw8671x_rtp_get_fifo_aes @ 00112120 size=96
// signature: undefined aw8671x_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw8671x_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw8671x_get_theory_time @ 00112184 size=196
// signature: undefined aw8671x_get_theory_time(void)
// callers: []
//------------------------------------------------------------

uint aw8671x_get_theory_time(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x44,local_2c,1);
  uVar3 = 0x30;
  if ((local_2c[0] & 3) != 1) {
    uVar3 = 0xc;
  }
  uVar1 = 0x18;
  if ((local_2c[0] & 3) != 0) {
    uVar1 = uVar3;
  }
  uVar3 = 0;
  if (uVar1 != 0) {
    uVar3 = (uint)(*(int *)(param_1 + 0x7c) * 1000) / uVar1;
  }
  _printk(&DAT_0013791e,"haptic_hv",0x659,"aw8671x_get_theory_time",*(undefined8 *)(param_1 + 0xa0),
          uVar3);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// aw8671x_snd_soc_init @ 0011224c size=200
// signature: undefined aw8671x_snd_soc_init(void)
// callers: []
//------------------------------------------------------------

int aw8671x_snd_soc_init(undefined8 param_1)

{
  int iVar1;
  void *__dest;
  
  __dest = (void *)devm_kmalloc(param_1,0xe0,0xdc0);
  if (__dest == (void *)0x0) {
    iVar1 = -0xc;
  }
  else {
    memcpy(__dest,&aw8671x_dai,0xe0);
    _printk(&DAT_00134c88,"haptic_hv",0x176,"aw8671x_snd_soc_init","aw8671x-aif");
    iVar1 = snd_soc_register_component(param_1,soc_codec_dev_aw8671x,__dest,1);
    if (iVar1 < 0) {
      _printk(&DAT_00135329,"haptic_hv",0x17b,"aw8671x_snd_soc_init",iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_show @ 00112318 size=64
// signature: undefined cont_drv_lvl_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_lvl_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_lvl = 0x%02X, cont_drv2_lvl = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4ba),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bb));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_store @ 0011235c size=232
// signature: undefined cont_drv_lvl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_lvl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined2 local_44;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_44 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  iVar1 = sscanf(param_3,"%x %x",local_40,(uint *)((ulong)local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x4ba) = (char)local_40[0];
    *(char *)(lVar2 + 0x4bb) = (char)local_40[1];
    haptic_hv_i2c_reads(lVar2 + -0xa8,0x1d,&local_44,1);
    local_44 = CONCAT11(*(undefined1 *)(lVar2 + 0x4bb),
                        *(byte *)(lVar2 + 0x4ba) | (byte)local_44 & 0x80);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1d,&local_44,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_time_show @ 00112448 size=64
// signature: undefined cont_drv_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4be),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bf));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_time_store @ 0011248c size=180
// signature: undefined cont_drv_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_34;
  undefined1 local_33;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_30,(uint *)((ulong)&local_30 | 4));
  if (iVar1 == 2) {
    *(undefined1 *)(lVar2 + 0x4be) = (undefined1)local_30;
    *(char *)(lVar2 + 0x4bf) = (char)((ulong)local_30 >> 0x20);
    local_34 = (undefined1)local_30;
    local_33 = *(undefined1 *)(lVar2 + 0x4bf);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1f,&local_34,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_brk_time_show @ 00112544 size=60
// signature: undefined cont_brk_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_brk_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_brk_time_store @ 00112584 size=104
// signature: undefined cont_brk_time_store(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x4bc;
  iVar2 = kstrtou8(param_3,0,lVar1);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    haptic_hv_i2c_writes(lVar3 + -0xa8,0x21,lVar1,1);
  }
  return param_4;
}



//------------------------------------------------------------
// trig_show @ 001125f0 size=292
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x61f),(uint)*(byte *)(lVar2 + 0x620),
                   (uint)*(byte *)(lVar2 + 0x621),(uint)*(byte *)(lVar2 + 0x623),
                   (uint)*(byte *)(lVar2 + 0x622),(uint)*(byte *)(lVar2 + 0x624),
                   (uint)*(byte *)(lVar2 + 0x61d),(uint)*(byte *)(lVar2 + 0x61e));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x62c),(uint)*(byte *)(lVar2 + 0x62d),
                   (uint)*(byte *)(lVar2 + 0x62e),(uint)*(byte *)(lVar2 + 0x630),
                   (uint)*(byte *)(lVar2 + 0x62f),(uint)*(byte *)(lVar2 + 0x631),
                   (uint)*(byte *)(lVar2 + 0x62a),(uint)*(byte *)(lVar2 + 0x62b));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x639),(uint)*(byte *)(lVar2 + 0x63a),
                   (uint)*(byte *)(lVar2 + 0x63b),(uint)*(byte *)(lVar2 + 0x63d),
                   (uint)*(byte *)(lVar2 + 0x63c),(uint)*(byte *)(lVar2 + 0x63e),
                   (uint)*(byte *)(lVar2 + 0x637),(uint)*(byte *)(lVar2 + 0x638));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 00112718 size=828
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar5 = sscanf(param_3,"%u %u %u %u %u %u %u %u %u",(uint *)&local_60,
                 (uint *)((ulong)&local_60 | 4),(uint *)&local_58,(uint *)((long)&local_58 + 4),
                 (uint *)&local_50,(uint *)((long)&local_50 + 4),(uint *)&local_48,
                 (uint *)((long)&local_48 + 4),local_40);
  if (iVar5 == 9) {
    _printk(&DAT_001359f8,"haptic_hv",0x757,"trig_store",local_60 & 0xffffffff,local_60._4_4_,
            local_58 & 0xffffffff,local_58._4_4_,local_50 & 0xffffffff,local_50 >> 0x20,
            local_48 & 0xffffffff,local_48._4_4_,local_40[0]);
    uVar3 = local_60;
    if ((uint)local_60 - 4 < 0xfffffffd) {
      _printk(&DAT_001369d0,"haptic_hv",0x759,"trig_store");
    }
    else {
      uVar2 = (uint)local_60 - 1;
      if (uVar2 == 0) {
        if (*(char *)(lVar6 + 0x4e6) != '\0') {
          _printk(&DAT_00136135,"haptic_hv",0x75d,"trig_store");
          goto LAB_0011279c;
        }
      }
      else if ((*(char *)(lVar6 + 0x4e5) != '\0') && (*(char *)(lVar6 + -0xa4) != '\0')) {
        _printk(&DAT_00135a2c,"haptic_hv",0x762,"trig_store");
        goto LAB_0011279c;
      }
      if (*(char *)(lVar6 + -0xa2) == '\0') {
        _printk(&DAT_001325b9,"haptic_hv",0x766,"trig_store");
      }
      else {
        if (((uint)local_50 <= *(byte *)(lVar6 + 0x47c)) &&
           ((uint)local_48 <= *(byte *)(lVar6 + 0x47c))) {
          lVar1 = lVar6 + 0x618;
          local_60 = CONCAT44(local_60._4_4_,uVar2);
          *(char *)(lVar1 + (ulong)uVar2 * 0xd + 7) = (char)(uVar3 >> 0x20);
          if (uVar2 < 3) {
            *(char *)(lVar1 + (ulong)uVar2 * 0xd + 8) = (char)local_58;
            if (uVar2 < 3) {
              *(char *)(lVar1 + (ulong)uVar2 * 0xd + 9) = (char)(local_58 >> 0x20);
              if (uVar2 < 3) {
                *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xb) = (char)local_50;
                if (uVar2 < 3) {
                  *(char *)(lVar1 + (ulong)uVar2 * 0xd + 10) = (char)(local_50 >> 0x20);
                  if (uVar2 < 3) {
                    *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xc) = (char)local_48;
                    if (uVar2 < 3) {
                      *(char *)(lVar1 + (ulong)uVar2 * 0xd + 5) = (char)(local_48 >> 0x20);
                      if (uVar2 < 3) {
                        lVar7 = lVar6 + -0xa8;
                        *(char *)(lVar1 + (ulong)uVar2 * 0xd + 6) = (char)local_40[0];
                        mutex_lock(lVar6 + 0x2a8);
                        if ((uint)local_60 == 2) {
                          aw8671x_trig3_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 1) {
                          aw8671x_trig2_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 0) {
                          aw8671x_trig1_param_config(lVar7);
                        }
                        mutex_unlock(lVar6 + 0x2a8);
                        goto LAB_0011279c;
                      }
                    }
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x112a54);
          (*pcVar4)();
        }
        _printk(&DAT_00134564,"haptic_hv",0x76a,"trig_store");
      }
    }
  }
LAB_0011279c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8671x_trig1_param_config @ 00112a54 size=188
// signature: undefined aw8671x_trig1_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8671x_trig1_param_config(long param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = *(char *)(param_1 + 0x6c7) != '\0';
  uVar1 = (uint)bVar2 << 6;
  if (*(char *)(param_1 + 0x6c8) != '\0') {
    uVar1 = (uint)bVar2 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6c5) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6c6) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
  haptic_hv_i2c_write_bits
            (param_1,0x33,0xffffff00,
             *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x36,0xffffff00,
             *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7);
  return;
}



//------------------------------------------------------------
// aw8671x_trig2_param_config @ 00112b10 size=188
// signature: undefined aw8671x_trig2_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8671x_trig2_param_config(long param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = *(char *)(param_1 + 0x6d4) != '\0';
  bVar1 = bVar2 << 2;
  if (*(char *)(param_1 + 0x6d5) != '\0') {
    bVar1 = bVar2 << 2 | 8;
  }
  if (*(char *)(param_1 + 0x6d2) != '\0') {
    bVar1 = bVar1 | 2;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x6d3) != '\0');
  haptic_hv_i2c_write_bits
            (param_1,0x34,0xffffff00,
             *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x37,0xffffff00,
             *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7);
  return;
}



//------------------------------------------------------------
// aw8671x_trig3_param_config @ 00112bcc size=188
// signature: undefined aw8671x_trig3_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8671x_trig3_param_config(long param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar1 = (uint)bVar2 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar1 = (uint)bVar2 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  haptic_hv_i2c_write_bits
            (param_1,0x35,0xffffff00,
             *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x38,0xffffff00,
             *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7);
  return;
}



//------------------------------------------------------------
// aw8671x_set_dai_sysclk @ 00112c8c size=64
// signature: undefined aw8671x_set_dai_sysclk(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_set_dai_sysclk(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  _printk(&DAT_00132947,"haptic_hv",0x6a,"aw8671x_set_dai_sysclk",param_3);
  return 0;
}



//------------------------------------------------------------
// aw8671x_set_fmt @ 00112cd0 size=176
// signature: undefined aw8671x_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_set_fmt(undefined8 param_1,uint param_2)

{
  _printk(&DAT_001335b4,"haptic_hv",0x57,"aw8671x_set_fmt",param_2);
  if ((param_2 & 0xf) == 1) {
    if ((param_2 & 0xf000) == 0x4000) {
      return 0;
    }
    _printk(&DAT_001335d0,"haptic_hv",0x5c,"aw8671x_set_fmt");
  }
  else {
    _printk(&DAT_00134291,"haptic_hv",0x61,"aw8671x_set_fmt");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// aw8671x_mute @ 00112d84 size=540
// signature: undefined aw8671x_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_mute(long param_1,int param_2,int param_3)

{
  long lVar1;
  char local_40 [4];
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = '\0';
  if (param_3 == 1) {
    _printk(&DAT_00132960,"haptic_hv",0xc4,"aw8671x_mute");
    goto LAB_00112e38;
  }
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_001338b0,"haptic_hv",199,"aw8671x_mute",param_2);
  mutex_lock(lVar1 + 0x350);
  if (param_2 == 0) {
    haptic_hv_i2c_write_bits(lVar1,0x47,0xffffff7f,0x80);
    usleep_range_state(2000,3000,2);
    haptic_hv_i2c_reads(lVar1,1,local_40,1);
    _printk(&DAT_0013493c,"haptic_hv",0xd1,"aw8671x_mute",local_40[0]);
    haptic_hv_i2c_reads(lVar1,4,local_40,1);
    _printk(&DAT_00131bce,"haptic_hv",0xd3,"aw8671x_mute",local_40[0]);
    haptic_hv_i2c_reads(lVar1,5,local_40,1);
    _printk(&DAT_00135d9b,"haptic_hv",0xd5,"aw8671x_mute",local_40[0]);
    local_3c[0] = '\0';
    haptic_hv_i2c_reads(lVar1,0x3f,local_3c,1);
    local_40[0] = local_3c[0];
    if (local_3c[0] != '\n') {
      _printk(&DAT_00135703,"haptic_hv",0xd8,"aw8671x_mute");
      goto LAB_00112e1c;
    }
    _printk(&DAT_00134fed,"haptic_hv",0xdb,"aw8671x_mute");
  }
  else {
LAB_00112e1c:
    haptic_hv_i2c_write_bits(lVar1,0x47,0xffffff7f,0);
  }
  mutex_unlock(lVar1 + 0x350);
LAB_00112e38:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8671x_startup @ 00112fa4 size=132
// signature: undefined aw8671x_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_startup(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0x49,"aw8671x_startup");
  if (*(int *)(param_1 + 0x3c) == 0) {
    lVar1 = lVar2 + 0x350;
    mutex_lock(lVar1);
    haptic_hv_i2c_write_bits(lVar2,0x44,0xffffffdf,0);
    mutex_unlock(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// aw8671x_shutdown @ 0011302c size=112
// signature: undefined aw8671x_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw8671x_shutdown(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0xe8,"aw8671x_shutdown");
  if (*(int *)(param_1 + 0x3c) == 0) {
    lVar1 = lVar2 + 0x350;
    *(undefined4 *)(lVar2 + 0x40) = 0;
    mutex_lock(lVar1);
    mutex_unlock(lVar1);
  }
  return;
}



//------------------------------------------------------------
// aw8671x_hw_params @ 001130a0 size=732
// signature: undefined aw8671x_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_hw_params(long param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined1 local_3c [4];
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_3c[0] = 0;
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_00132960,"haptic_hv",0x79,"aw8671x_hw_params");
    goto LAB_00113348;
  }
  uVar4 = *(undefined4 *)(param_2 + 0x128);
  uVar6 = *(uint *)(param_2 + 0x24);
  lVar8 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 != 0) {
      uVar7 = 0x20;
      goto LAB_00113130;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
LAB_00113130:
    uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
    uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
  }
  uVar3 = snd_pcm_format_width(uVar7);
  _printk(&DAT_00134ca7,"haptic_hv",0x7e,"aw8671x_hw_params",uVar4,uVar3);
  *(undefined4 *)(lVar8 + 0x40) = *(undefined4 *)(param_2 + 0x128);
  mutex_lock(lVar8 + 0x350);
  uVar6 = *(uint *)(param_2 + 0x24);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 != 0) {
      uVar7 = 0x20;
      goto LAB_001131a0;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
LAB_001131a0:
    uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
    uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
  }
  uVar4 = snd_pcm_format_width(uVar7);
  *(undefined4 *)(lVar8 + 0x44) = uVar4;
  _printk(&DAT_0013262c,"haptic_hv",0x87,"aw8671x_hw_params",uVar4);
  uVar6 = *(uint *)(param_2 + 0x24);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 != 0) {
      uVar7 = 0x20;
      goto LAB_001131fc;
    }
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
LAB_001131fc:
    uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
    uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
    uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
    uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
    uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
  }
  iVar5 = snd_pcm_format_width(uVar7);
  iVar1 = *(int *)(param_2 + 0x11c);
  iVar2 = *(int *)(lVar8 + 0x44);
  uVar6 = iVar1 * iVar5;
  if (iVar2 == 0x10) {
LAB_00113268:
    uVar9 = 0;
  }
  else if (iVar2 == 0x20) {
    uVar9 = 0xc;
  }
  else {
    if (iVar2 != 0x18) {
      uVar6 = iVar1 << 4;
      _printk(&DAT_001365a5,"haptic_hv",0x98,"aw8671x_hw_params");
      goto LAB_00113268;
    }
    uVar6 = iVar1 << 5;
    uVar9 = 8;
  }
  _printk(&DAT_00133c7b,"haptic_hv",0x9b,"aw8671x_hw_params",uVar9);
  haptic_hv_i2c_write_bits(lVar8,0x49,0xfffffff3,uVar9);
  uVar7 = uVar6 & 0xff;
  if (uVar7 == 0x20) {
LAB_001132f4:
    uVar9 = 0;
  }
  else if (uVar7 == 0x40) {
    uVar9 = 2;
  }
  else {
    if (uVar7 != 0x30) {
      _printk(&DAT_0013495a,"haptic_hv",0xac,"aw8671x_hw_params",uVar6 & 0xff);
      goto LAB_001132f4;
    }
    uVar9 = 1;
  }
  haptic_hv_i2c_write_bits(lVar8,0x49,0xfffffffc,uVar9);
  haptic_hv_i2c_reads(lVar8,0x49,local_3c,1);
  _printk(&DAT_0013528f,"haptic_hv",0xb6,"aw8671x_hw_params",local_3c[0]);
  mutex_unlock(lVar8 + 0x350);
LAB_00113348:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8671x_codec_probe @ 00113380 size=160
// signature: undefined aw8671x_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8671x_codec_probe(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0x11f,"aw8671x_codec_probe");
  *(long *)(lVar1 + 0x270) = param_1;
  _printk(&DAT_00132e8a,"haptic_hv",0x118,"aw8671x_add_codec_controls");
  _printk(&DAT_00132b8d,"haptic_hv",0x122,"aw8671x_codec_probe");
  return 0;
}



//------------------------------------------------------------
// aw8671x_codec_remove @ 00113424 size=56
// signature: undefined aw8671x_codec_remove(void)
// callers: []
//------------------------------------------------------------

void aw8671x_codec_remove(void)

{
  _printk(&DAT_00132e8a,"haptic_hv",0x12e,"aw8671x_codec_remove");
  return;
}



//------------------------------------------------------------
// aw8671x_codec_read @ 00113460 size=192
// signature: undefined aw8671x_codec_read(void)
// callers: []
//------------------------------------------------------------

int aw8671x_codec_read(long param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98);
  _printk(&DAT_00132e8a,"haptic_hv",0x143,"aw8671x_codec_read");
  iVar2 = haptic_hv_i2c_reads(uVar3,param_2,local_2c,1);
  if (iVar2 < 0) {
    _printk(&DAT_001318a6,"haptic_hv",0x146,"aw8671x_codec_read");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw8671x_codec_write @ 00113524 size=152
// signature: undefined aw8671x_codec_write(void)
// callers: []
//------------------------------------------------------------

void aw8671x_codec_write(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = (undefined1)param_3;
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98);
  _printk(&DAT_00133230,"haptic_hv",0x153,"aw8671x_codec_write",param_2,param_3);
  haptic_hv_i2c_writes(uVar2,param_2,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_get_f0 @ 001135c0 size=1032
// signature: undefined aw8672x_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_get_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  int iVar7;
  undefined8 uVar8;
  byte local_44 [4];
  undefined1 local_40;
  undefined2 local_3f;
  undefined2 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_44[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw8672x_stop();
  _printk(&DAT_00132e8a,"haptic_hv",0x294,"aw8672x_vbat_ref_config");
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  _printk(&DAT_001331a6,"haptic_hv",0x23a,"aw8672x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x1fb,"aw8672x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xfffffffe,0);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_reads(param_1,8,local_44,1);
  bVar4 = local_44[0];
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  local_40 = *(undefined1 *)(param_1 + 0x563);
  local_3f = *(undefined2 *)(param_1 + 0x566);
  haptic_hv_i2c_writes(param_1,0x1e,&local_40,3);
  if (*(char *)(param_1 + 0x568) == '\0') {
    _printk(&DAT_001338cf,"haptic_hv",0x487,"aw8672x_get_f0");
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  else {
    haptic_hv_i2c_writes(param_1,0x22,param_1 + 0x568,1);
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  if (uVar1 == 0) {
    uVar8 = 0xffffffde;
  }
  else {
    local_3c._1_1_ = (undefined1)(local_3c >> 8);
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 240000 / uVar1;
    }
    iVar7 = (uVar2 - ((uint)*(byte *)(param_1 + 0x565) + (uint)*(byte *)(param_1 + 0x568))) + -8;
    if (0xfe < iVar7) {
      iVar7 = 0xff;
    }
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    local_40 = (undefined1)iVar7;
    haptic_hv_i2c_writes(param_1,0x1a,&local_40,1);
    local_3c = CONCAT11(local_3c._1_1_,1);
    haptic_hv_i2c_writes(param_1,9,&local_3c,1);
    usleep_range_state(20000,0x5014,2);
    iVar7 = -100;
    do {
      local_3c = local_3c & 0xff00;
      haptic_hv_i2c_reads(param_1,0x3f,&local_3c,1);
      if ((local_3c & 0xf) == 0) {
        puVar6 = &DAT_00136940;
        uVar8 = 0x1e6;
        goto LAB_001138dc;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar5 = iVar7 != -1;
      iVar7 = iVar7 + 1;
    } while (bVar5);
    puVar6 = &DAT_00137ca1;
    uVar8 = 0x1ec;
LAB_001138dc:
    _printk(puVar6,"haptic_hv",uVar8,"aw8672x_wait_enter_standby");
    local_3c = 0;
    haptic_hv_i2c_reads(param_1,0x25,&local_3c,2);
    uVar1 = (uint)(local_3c >> 8) | (local_3c & 0xff00ff) << 8;
    if (uVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      _printk(&DAT_00132236,"haptic_hv",1099,"aw8672x_read_f0");
      uVar8 = 0xffffffde;
    }
    else {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = 0x3a9800 / uVar1;
      }
      *(uint *)(param_1 + 100) = uVar2;
      _printk(&DAT_00136043,"haptic_hv",0x450,"aw8672x_read_f0");
      uVar8 = 0;
    }
    haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,bVar4 & 4);
    _printk(&DAT_00132e8a,"haptic_hv",0x294,"aw8672x_vbat_ref_config");
    haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x30);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// aw8672x_ram_get_f0 @ 001139cc size=948
// signature: undefined aw8672x_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_ram_get_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  byte local_40 [4];
  undefined2 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    puVar6 = &DAT_001325b9;
    uVar7 = 0x4b0;
  }
  else {
    if (4 < *(byte *)(param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
      aw8672x_stop(param_1);
      haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
      _printk(&DAT_00136db2,"haptic_hv",0x214,"aw8672x_play_mode");
      *(undefined1 *)(param_1 + 0xb) = 1;
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,0);
      _printk(&DAT_00136a5b,"haptic_hv",0x1f5,"aw8672x_bst_mode_config");
      haptic_hv_i2c_write_bits(param_1,6,0xfffffffe,1);
      haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
      haptic_hv_i2c_reads(param_1,8,local_40,1);
      bVar4 = local_40[0];
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
      local_3c._0_1_ = 0x7d;
      haptic_hv_i2c_writes(param_1,0x5a,&local_3c,1);
      haptic_hv_i2c_write_bits(param_1,0x75,0xfffffff0,2);
      local_3c = (ushort)local_3c._1_1_ << 8;
      haptic_hv_i2c_writes(param_1,0x5a,&local_3c,1);
      local_3c._0_1_ = 5;
      haptic_hv_i2c_writes(param_1,10,&local_3c,1);
      local_3c = (ushort)local_3c._1_1_ << 8;
      haptic_hv_i2c_writes(param_1,0xb,&local_3c,1);
      haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0x20);
      local_3c = CONCAT11(local_3c._1_1_,1);
      haptic_hv_i2c_writes(param_1,9,&local_3c,1);
      usleep_range_state(20000,0x5014,2);
      iVar9 = -100;
      do {
        local_3c = local_3c & 0xff00;
        haptic_hv_i2c_reads(param_1,0x3f,&local_3c,1);
        if ((local_3c & 0xf) == 0) {
          puVar6 = &DAT_00136940;
          uVar7 = 0x1e6;
          goto LAB_00113c84;
        }
        usleep_range_state(2000,0x9c4,2);
        bVar5 = iVar9 != -1;
        iVar9 = iVar9 + 1;
      } while (bVar5);
      puVar6 = &DAT_00137ca1;
      uVar7 = 0x1ec;
LAB_00113c84:
      _printk(puVar6,"haptic_hv",uVar7,"aw8672x_wait_enter_standby");
      local_3c = 0;
      haptic_hv_i2c_reads(param_1,0x25,&local_3c,2);
      uVar1 = (uint)(local_3c >> 8) | (local_3c & 0xff00ff) << 8;
      if (uVar1 == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        _printk(&DAT_00132236,"haptic_hv",1099,"aw8672x_read_f0");
        uVar7 = 0xffffffde;
      }
      else {
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = 0x3a9800 / uVar1;
        }
        *(uint *)(param_1 + 100) = uVar2;
        _printk(&DAT_00136043,"haptic_hv",0x450,"aw8672x_read_f0");
        uVar7 = 0;
      }
      aw8672x_set_bst_vol(param_1,*(undefined4 *)(param_1 + 0x38));
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
      if ((bVar4 >> 2 & 1) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = 4;
      }
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar8);
      goto LAB_00113d4c;
    }
    puVar6 = &DAT_00132b34;
    uVar7 = 0x4b4;
  }
  _printk(puVar6,"haptic_hv",uVar7,"aw8672x_ram_get_f0");
  uVar7 = 0xffffffde;
LAB_00113d4c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// aw8672x_creat_node @ 00113d84 size=100
// signature: undefined aw8672x_creat_node(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

int aw8672x_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw8672x_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_00135359,"haptic_hv",0x7ba,"aw8672x_creat_node");
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw8672x_offset_cali @ 00113dec size=476
// signature: undefined aw8672x_offset_cali(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

void aw8672x_offset_cali(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined2 local_2c;
  undefined1 local_2a;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  cVar1 = *(char *)(param_1 + 0x55d);
  local_2a = 0;
  local_2c = 0;
  if (cVar1 == '\0') {
    _printk(&DAT_00136555,"haptic_hv",0x58a,"aw8672x_offset_cali");
    cVar1 = *(char *)(param_1 + 0x55d);
  }
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,cVar1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_2c,2);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  if ((ulong)(long)*(char *)(param_1 + 0x55d) < 8) {
    iVar2 = 0;
    if (*(int *)(&DAT_001380a0 + (long)*(char *)(param_1 + 0x55d) * 4) != 0) {
      iVar2 = (int)(((uint)local_2c._1_1_ | ((byte)local_2c & 3) << 8) * 0x988 + -0x131000) /
              *(int *)(&DAT_001380a0 + (long)*(char *)(param_1 + 0x55d) * 4);
    }
    _printk(&DAT_00135670,"haptic_hv",0x59e,"aw8672x_offset_cali",iVar2);
    if (0xffffffe0 < iVar2 - 0x10U) {
      uVar4 = 0;
      goto LAB_00113f7c;
    }
    puVar5 = &DAT_00137a8c;
    uVar4 = 0x5a0;
  }
  else {
    puVar5 = &DAT_00135cd6;
    uVar4 = 0x599;
  }
  _printk(puVar5,"haptic_hv",uVar4,"aw8672x_offset_cali");
  uVar4 = 0xffffffde;
LAB_00113f7c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_get_irq_state @ 00113fcc size=392
// signature: undefined aw8672x_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw8672x_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  if ((local_1c[0] >> 6 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    _printk(&DAT_0013431d,"haptic_hv",0x41e,"aw8672x_get_irq_state");
    uVar2 = 0xb;
  }
  if ((local_1c[0] >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x423,"aw8672x_get_irq_state");
    uVar2 = 5;
  }
  if ((local_1c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x428,"aw8672x_get_irq_state");
    uVar2 = 6;
  }
  if ((local_1c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x42d,"aw8672x_get_irq_state");
    uVar2 = 7;
  }
  if ((local_1c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",0x432,"aw8672x_get_irq_state");
    uVar2 = 10;
  }
  if ((local_1c[0] >> 3 & 1) != 0) {
    _printk(&DAT_00131f9b,"haptic_hv",0x436,"aw8672x_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_1c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_check_qualify @ 00114158 size=192
// signature: undefined aw8672x_check_qualify(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

void aw8672x_check_qualify(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  _printk(&DAT_00132e8a,"haptic_hv",0x114,"aw8672x_check_qualify");
  uVar2 = haptic_hv_i2c_reads(param_1,100,local_2c,1);
  if (-1 < (int)uVar2) {
    if (local_2c[0] < '\0') {
      uVar2 = 0;
    }
    else {
      _printk(&DAT_0013785a,"haptic_hv",0x119,"aw8672x_check_qualify");
      uVar2 = 0xffffffde;
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
// aw8672x_judge_rtp_going @ 0011421c size=148
// signature: undefined aw8672x_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw8672x_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  bVar2 = (local_1c[0] & 0xf) == 8;
  if (bVar2) {
    _printk(&DAT_00134c3c,"haptic_hv",0x3c5,"aw8672x_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_container_update @ 001142b4 size=856
// signature: undefined aw8672x_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_container_update(long param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  ushort uVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined1 local_468 [4];
  undefined2 local_464;
  byte local_462;
  undefined1 local_461;
  undefined1 local_460;
  undefined2 local_45c;
  byte local_45a;
  char local_458 [1024];
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_45a = 0;
  local_45c = 0;
  memset(local_458,0,0x400);
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  aw8672x_stop(param_1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  bVar1 = *(byte *)(param_1 + 0x527);
  bVar2 = *(byte *)((long)param_2 + (ulong)bVar1 + 4);
  uVar4 = CONCAT11(bVar2,*(undefined1 *)((long)param_2 + (ulong)bVar1 + 5));
  local_461 = (undefined1)(uVar4 >> 1);
  iVar7 = (uint)uVar4 - (uint)(uVar4 >> 2);
  *(uint *)(param_1 + 0x520) = (uint)uVar4;
  local_464 = *(undefined2 *)((long)param_2 + (ulong)bVar1 + 4);
  local_462 = (bVar2 & 0xfe) << 3 | (byte)((uint)iVar7 >> 8) & 0xf;
  local_460 = (undefined1)iVar7;
  _printk(&DAT_00136e85,"haptic_hv",0x5f0,"aw8672x_container_update");
  haptic_hv_i2c_writes(param_1,0x2d,&local_464,5);
  haptic_hv_i2c_reads(param_1,0x2f,&local_45c,3);
  bVar1 = (byte)local_45c;
  _printk(&DAT_001344e9,"haptic_hv",0x5f5,"aw8672x_container_update",
          CONCAT11((byte)local_45c >> 4,local_45c._1_1_));
  _printk(&DAT_001351c2,"haptic_hv",0x5f7,"aw8672x_container_update",
          (uint)local_45a | (bVar1 & 0xf) << 8);
  local_468[0] = (undefined1)*(uint *)(param_1 + 0x520);
  haptic_hv_i2c_write_bits(param_1,0x40,0xfffffff0,*(uint *)(param_1 + 0x520) >> 8);
  haptic_hv_i2c_writes(param_1,0x41,local_468,1);
  uVar9 = (uint)*(byte *)(param_1 + 0x526);
  iVar7 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar7) {
    do {
      iVar10 = iVar7 - uVar9;
      if (0x7ff < iVar10) {
        iVar10 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar9 + 4,iVar10);
      iVar7 = *param_2;
      uVar9 = iVar10 + uVar9;
    } while ((int)uVar9 < iVar7);
  }
  local_468[0] = (undefined1)*(uint *)(param_1 + 0x520);
  haptic_hv_i2c_write_bits(param_1,0x40,0xfffffff0,*(uint *)(param_1 + 0x520) >> 8);
  haptic_hv_i2c_writes(param_1,0x41,local_468,1);
  uVar9 = (uint)*(byte *)(param_1 + 0x526);
  iVar7 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar7) {
    do {
      uVar11 = iVar7 - uVar9;
      if (0x3ff < (int)uVar11) {
        uVar11 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,local_458,uVar11);
      if (uVar11 != 0) {
        uVar6 = 0;
        do {
          if (0x3ff < uVar6) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(1,0x114608);
            (*pcVar5)();
          }
          if (local_458[(int)uVar6] !=
              *(char *)((long)param_2 + (long)(int)uVar6 + (long)(int)uVar9 + 4)) {
            _printk(&DAT_001373f1,"haptic_hv",0x5c1,"aw8672x_check_ram_data");
            _printk(&DAT_001351ee,"haptic_hv",0x614,"aw8672x_container_update");
            uVar8 = 0xffffffde;
            goto LAB_001145b0;
          }
          uVar6 = uVar6 + 1;
        } while (uVar11 != uVar6);
      }
      iVar7 = *param_2;
      uVar9 = uVar11 + uVar9;
    } while ((int)uVar9 < iVar7);
  }
  _printk(&DAT_00132afb,"haptic_hv",0x616,"aw8672x_container_update");
  uVar8 = 0;
LAB_001145b0:
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  mutex_unlock(param_1 + 0x350);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// aw8672x_stop @ 00114610 size=456
// signature: undefined aw8672x_stop(void)
// callers: [aw8672x_get_vbat, aw8672x_get_f0, aw8672x_ram_get_f0, aw8672x_get_lra_resistance, aw8672x_container_update]
//------------------------------------------------------------

void aw8672x_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x25c,"aw8672x_stop");
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_30[0] = 1;
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,3);
  haptic_hv_i2c_writes(param_1,9,local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  iVar3 = -100;
  do {
    local_2c[0] = 0;
    haptic_hv_i2c_reads(param_1,0x3f,local_2c,1);
    if ((local_2c[0] & 0xf) == 0) {
      _printk(&DAT_00136940,"haptic_hv",0x1e6,"aw8672x_wait_enter_standby");
      goto LAB_001147ac;
    }
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar3 != -1;
    iVar3 = iVar3 + 1;
  } while (bVar2);
  _printk(&DAT_00137ca1,"haptic_hv",0x1ec,"aw8672x_wait_enter_standby");
  _printk(&DAT_00135cf9,"haptic_hv",0x267,"aw8672x_stop");
  _printk(&DAT_00134895,"haptic_hv",0x20a,"aw8672x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 0;
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0);
LAB_001147ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_get_vbat @ 001147dc size=436
// signature: undefined aw8672x_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw8672x_get_vbat(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined2 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  aw8672x_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_2c,2);
  uVar1 = (uint)local_2c._1_1_ | ((byte)local_2c & 3) << 8;
  uVar2 = uVar1 * 0x17d4;
  uVar4 = (ulong)uVar2 / 0x3ff;
  *(uint *)(param_1 + 0x70) = uVar2 / 0x3ff;
  if (0x46426a < uVar2) {
    *(undefined4 *)(param_1 + 0x70) = 0x1194;
    _printk(&DAT_001328b9,"haptic_hv",0x564,"aw8672x_get_vbat",0x1194);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  if ((uint)uVar4 < 3000) {
    *(undefined4 *)(param_1 + 0x70) = 3000;
    _printk(&DAT_00135218,"haptic_hv",0x568,"aw8672x_get_vbat",3000);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  _printk(&DAT_00132353,"haptic_hv",0x56a,"aw8672x_get_vbat",uVar4,uVar1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_cont_config @ 00114994 size=336
// signature: undefined aw8672x_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw8672x_cont_config(long param_1)

{
  long lVar1;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0xff;
  _printk(&DAT_001331a6,"haptic_hv",0x23a,"aw8672x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x1fb,"aw8672x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xfffffffe,0);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits
            (param_1,0x1d,0xffffff00,
             (uint)*(byte *)(param_1 + 0x562) | (uint)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_writes(param_1,0x1e,param_1 + 0x563,1);
  haptic_hv_i2c_writes(param_1,0x20,local_30,1);
  local_2c[0] = 1;
  haptic_hv_i2c_writes(param_1,9,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_play_go @ 00114ae8 size=112
// signature: undefined aw8672x_play_go(void)
// callers: []
//------------------------------------------------------------

void aw8672x_play_go(undefined8 param_1,ulong param_2)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  puVar1 = local_1c;
  if ((param_2 & 1) == 0) {
    puVar1 = local_20;
  }
  local_1c[0] = 1;
  local_20[0] = 2;
  haptic_hv_i2c_writes(param_1,9,puVar1,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_ram_init @ 00114b5c size=80
// signature: undefined aw8672x_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw8672x_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
    usleep_range_state(500,600,2);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_bst_peak_cur @ 00114bb0 size=4
// signature: undefined aw8672x_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_bst_peak_cur(void)

{
  return;
}



//------------------------------------------------------------
// aw8672x_get_lra_resistance @ 00114bb8 size=428
// signature: undefined aw8672x_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw8672x_get_lra_resistance(long param_1)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  undefined2 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  aw8672x_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x18);
  haptic_hv_i2c_reads(param_1,0x4d,&local_3c,1);
  bVar2 = (byte)local_3c;
  haptic_hv_i2c_reads(param_1,0x4e,&local_3c,1);
  bVar3 = (byte)local_3c;
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,4);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff3,0xc);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_3c,2);
  *(uint *)(param_1 + 0x6c) = (((uint)local_3c._1_1_ | ((byte)local_3c & 3) << 8) * 610000) / 0x27f6
  ;
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff3,bVar2 & 0xc);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,bVar3 & 7);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_pwm @ 00114d68 size=68
// signature: undefined aw8672x_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_pwm(undefined8 param_1,uint param_2)

{
  if ((param_2 & 0xff) < 4) {
    haptic_hv_i2c_write_bits(param_1,0x46,0xffffff9f,0x60400020 >> (ulong)((param_2 & 3) << 3));
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_gain @ 00114db0 size=88
// signature: undefined aw8672x_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_play_mode @ 00114e0c size=692
// signature: undefined aw8672x_play_mode(void)
// callers: []
//------------------------------------------------------------

void aw8672x_play_mode(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0x20a,"aw8672x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
    uVar2 = 0x45;
    uVar1 = 0xffffffdf;
    goto LAB_00114fd4;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",0x214,"aw8672x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 1;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    uVar2 = 0;
    break;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x228,"aw8672x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,1);
    uVar2 = 4;
    break;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x232,"aw8672x_play_mode");
    uVar2 = 8;
    uVar1 = 0xfffffffc;
    uVar3 = 0;
    *(undefined1 *)(param_1 + 0xb) = 3;
    goto LAB_00114fc4;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x23a,"aw8672x_play_mode");
    uVar4 = 4;
    uVar2 = 2;
    goto LAB_00115050;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0x21e,"aw8672x_play_mode");
    uVar4 = 5;
    uVar2 = 0;
LAB_00115050:
    *(undefined1 *)(param_1 + 0xb) = uVar4;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,uVar2);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x1fb,"aw8672x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xfffffffe,0);
    uVar2 = 0x4c;
    uVar1 = 0xffffffbf;
    uVar3 = 0x40;
    goto LAB_001150ac;
  default:
    _printk(&DAT_001348de,"haptic_hv",0x244,"aw8672x_play_mode");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar2);
  _printk(&DAT_00136a5b,"haptic_hv",0x1f5,"aw8672x_bst_mode_config");
  uVar2 = 6;
  uVar1 = 0xfffffffe;
  uVar3 = 1;
LAB_00114fc4:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar1,uVar3);
  uVar2 = 0x4c;
  uVar1 = 0xffffffbf;
LAB_00114fd4:
  uVar3 = 0;
LAB_001150ac:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar1,uVar3);
  return;
}



//------------------------------------------------------------
// aw8672x_set_bst_vol @ 001150c4 size=400
// signature: undefined aw8672x_set_bst_vol(void)
// callers: [aw8672x_ram_get_f0]
//------------------------------------------------------------

void aw8672x_set_bst_vol(undefined8 param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar5 = (uint)(param_2 >> 1) & 0x7fffffff;
  if (uVar5 < 0xc35) {
    uVar3 = 0;
  }
  else {
    uVar2 = (uint)(param_2 >> 2) & 0x3fffffff;
    if (uVar2 < 0x659) {
      uVar3 = 1;
    }
    else if (uVar5 < 0xd2f) {
      uVar3 = 2;
    }
    else {
      uVar4 = (uint)(param_2 >> 3) & 0x1fffffff;
      if (uVar4 < 0x36b) {
        uVar3 = 3;
      }
      else if (uVar5 < 0xe29) {
        uVar3 = 4;
      }
      else if (uVar2 < 0x753) {
        uVar3 = 5;
      }
      else if (uVar5 < 0xf23) {
        uVar3 = 6;
      }
      else if (((uint)(param_2 >> 6) & 0x3ffffff) < 0x7d) {
        uVar3 = 7;
      }
      else {
        uVar5 = (uint)param_2;
        if (uVar5 < 0x203a) {
          uVar3 = 8;
        }
        else if (uVar2 < 0x84d) {
          uVar3 = 9;
        }
        else if (uVar5 < 0x222e) {
          uVar3 = 10;
        }
        else if (uVar4 < 0x465) {
          uVar3 = 0xb;
        }
        else if (uVar5 < 0x2422) {
          uVar3 = 0xc;
        }
        else {
          uVar3 = 0xd;
          if (0x946 < uVar2) {
            uVar3 = 0xe;
          }
        }
      }
    }
  }
  local_30[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5a,local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x75,0xfffffff0,uVar3);
  local_2c[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5a,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_repeat_seq @ 00115258 size=120
// signature: undefined aw8672x_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,10,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_auto_bst_enable @ 001152d4 size=52
// signature: undefined aw8672x_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw8672x_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,8,0xffffffef,(ulong)(param_2 != '\0') << 4);
  return;
}



//------------------------------------------------------------
// aw8672x_vbat_mode_config @ 0011530c size=52
// signature: undefined aw8672x_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8672x_vbat_mode_config(undefined8 param_1,char param_2)

{
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,(ulong)(param_2 == '\x01') << 6);
  return;
}



//------------------------------------------------------------
// aw8672x_set_wav_seq @ 00115344 size=88
// signature: undefined aw8672x_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 10,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_wav_loop @ 001153a0 size=64
// signature: undefined aw8672x_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0x12,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw8672x_set_rtp_data @ 001153e4 size=40
// signature: undefined aw8672x_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,0x32,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw8672x_protect_config @ 00115410 size=256
// signature: undefined aw8672x_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw8672x_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x2c6,"aw8672x_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x4a,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",0x2bf,"aw8672x_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x4a,local_40,1);
    haptic_hv_i2c_writes(param_1,0x4b,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_parse_dt @ 00115514 size=1368
// signature: undefined aw8672x_parse_dt(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

void aw8672x_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined2 local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_52 = 0;
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_gain_bypass",param_2 + 0x55f,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133934,"haptic_hv",0x63d,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_uvlo_vol_default",param_2 + 0x560,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00133963,"haptic_hv",0x640,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x643,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_f0_cali_percent",param_2 + 0x529,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001353a6,"haptic_hv",0x646,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_cont_smart_loop",param_2 + 0x561,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136418,"haptic_hv",0x649,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_cont_drv1_lvl",param_2 + 0x562,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134626,"haptic_hv",0x64c,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8672x_cont_lra_vrms",param_2 + 0x584,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00132bda,"haptic_hv",0x64f,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_cont_drv1_time",param_2 + 0x566,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00132c0b,"haptic_hv",0x652,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_cont_drv2_time",param_2 + 0x567,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136aa8,"haptic_hv",0x655,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_cont_brk_gain",param_2 + 0x565,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133cca,"haptic_hv",0x658,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_d2s_gain",param_2 + 0x55d,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00132f1d,"haptic_hv",0x65b,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_cont_brk_time",param_2 + 0x564,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00131967,"haptic_hv",0x65e,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw8672x_cont_track_margin",param_2 + 0x568,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134657,"haptic_hv",0x662,"aw8672x_parse_dt");
  }
  lVar2 = of_find_property(param_3,"aw8672x_is_enabled_track_en",0);
  *(bool *)(param_2 + 0x588) = lVar2 != 0;
  _printk(&DAT_00137abd,"haptic_hv",0x665,"aw8672x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8672x_is_enabled_auto_bst",0);
  *(bool *)(param_2 + 0x58c) = lVar2 != 0;
  _printk(&DAT_00134902,"haptic_hv",0x668,"aw8672x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8672x_is_enabled_one_wire",0);
  *(bool *)(param_2 + 0x58e) = lVar2 != 0;
  _printk(&DAT_00133c22,"haptic_hv",0x66b,"aw8672x_parse_dt");
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_duration_time",&local_54,3,0);
  if (iVar1 < 0) {
    _printk(&DAT_001371e0,"haptic_hv",0x66f,"aw8672x_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_54;
    *(undefined1 *)(param_2 + 0x52c) = local_52;
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8672x_bst_vol_default",param_2 + 0x534,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00136651,"haptic_hv",0x674,"aw8672x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8672x_trig_config",&local_50,0x18,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136684,"haptic_hv",0x678,"aw8672x_parse_dt");
  }
  else {
    *(undefined8 *)(param_2 + 0x569) = local_50;
    *(undefined8 *)(param_2 + 0x571) = local_48;
    *(undefined8 *)(param_2 + 0x579) = local_40;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_trig_init @ 00115a70 size=860
// signature: undefined aw8672x_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw8672x_trig_init(long param_1)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  undefined1 local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  _printk(&DAT_0013233b,"haptic_hv",0x5a9,"aw8672x_trig_init");
  if (*(char *)(param_1 + 0x58e) == '\0') {
    cVar2 = *(char *)(param_1 + 0x569);
    *(undefined1 *)(param_1 + 0x6c9) = *(undefined1 *)(param_1 + 0x56b);
    *(undefined1 *)(param_1 + 0x6cb) = *(undefined1 *)(param_1 + 0x56c);
    *(char *)(param_1 + 0x6c7) = cVar2;
    *(char *)(param_1 + 0x6c8) = *(char *)(param_1 + 0x56a);
    uVar1 = (uint)(cVar2 != '\0') << 6;
    if (*(char *)(param_1 + 0x56a) != '\0') {
      uVar1 = (uint)(cVar2 != '\0') << 6 | 0xffffff80;
    }
    *(undefined1 *)(param_1 + 0x6ca) = *(undefined1 *)(param_1 + 0x56d);
    if (*(char *)(param_1 + 0x56f) != '\0') {
      uVar1 = uVar1 | 0x20;
    }
    if (*(char *)(param_1 + 0x570) != '\0') {
      uVar1 = uVar1 | 0x10;
    }
    *(char *)(param_1 + 0x6c5) = *(char *)(param_1 + 0x56f);
    *(char *)(param_1 + 0x6c6) = *(char *)(param_1 + 0x570);
    *(undefined1 *)(param_1 + 0x6cc) = *(undefined1 *)(param_1 + 0x56e);
    haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
    haptic_hv_i2c_write_bits
              (param_1,0x33,0xffffff00,
               *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7);
    uVar5 = 0x36;
    uVar6 = 0xffffff00;
    bVar7 = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
  }
  else {
    _printk(&DAT_00137af7,"haptic_hv",0x5ab,"aw8672x_trig_init");
    local_2c[0] = 0x6c;
    _printk(&DAT_00132e8a,"haptic_hv",0x2e6,"aw8672x_one_wire_init");
    haptic_hv_i2c_writes(param_1,0x3e,local_2c,1);
    uVar5 = 0x3a;
    uVar6 = 0xfffffff7;
    bVar7 = 8;
  }
  haptic_hv_i2c_write_bits(param_1,uVar5,uVar6,bVar7);
  cVar2 = *(char *)(param_1 + 0x571);
  *(undefined1 *)(param_1 + 0x6d6) = *(undefined1 *)(param_1 + 0x573);
  *(char *)(param_1 + 0x6d4) = cVar2;
  *(undefined1 *)(param_1 + 0x6d9) = *(undefined1 *)(param_1 + 0x576);
  *(char *)(param_1 + 0x6d5) = *(char *)(param_1 + 0x572);
  *(undefined1 *)(param_1 + 0x6d8) = *(undefined1 *)(param_1 + 0x574);
  *(undefined1 *)(param_1 + 0x6d7) = *(undefined1 *)(param_1 + 0x575);
  *(undefined1 *)(param_1 + 0x6e2) = *(undefined1 *)(param_1 + 0x57a);
  *(char *)(param_1 + 0x6d2) = *(char *)(param_1 + 0x577);
  bVar7 = (cVar2 != '\0') << 2;
  if (*(char *)(param_1 + 0x572) != '\0') {
    bVar7 = (cVar2 != '\0') << 2 | 8;
  }
  *(undefined1 *)(param_1 + 0x6e1) = *(undefined1 *)(param_1 + 0x579);
  *(undefined1 *)(param_1 + 0x6e3) = *(undefined1 *)(param_1 + 0x57b);
  if (*(char *)(param_1 + 0x577) != '\0') {
    bVar7 = bVar7 | 2;
  }
  *(undefined1 *)(param_1 + 0x6e5) = *(undefined1 *)(param_1 + 0x57c);
  *(char *)(param_1 + 0x6d3) = *(char *)(param_1 + 0x578);
  *(undefined1 *)(param_1 + 0x6e6) = *(undefined1 *)(param_1 + 0x57e);
  *(undefined1 *)(param_1 + 0x6e4) = *(undefined1 *)(param_1 + 0x57d);
  *(undefined2 *)(param_1 + 0x6df) = *(undefined2 *)(param_1 + 0x57f);
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar7 | *(char *)(param_1 + 0x578) != '\0');
  haptic_hv_i2c_write_bits
            (param_1,0x34,0xffffff00,
             *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x37,0xffffff00,
             *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7);
  bVar4 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar1 = (uint)bVar4 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar1 = (uint)bVar4 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  haptic_hv_i2c_write_bits
            (param_1,0x35,0xffffff00,
             *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x38,0xffffff00,
             *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_irq_clear @ 00115dd0 size=124
// signature: undefined aw8672x_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw8672x_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x407,"aw8672x_irq_clear",local_1c[0]);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_ram_addr @ 00115e50 size=124
// signature: undefined aw8672x_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_ram_addr(long param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = (undefined1)*(uint *)(param_1 + 0x520);
  haptic_hv_i2c_write_bits(param_1,0x40,0xfffffff0,*(uint *)(param_1 + 0x520) >> 8);
  haptic_hv_i2c_writes(param_1,0x41,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_misc_para_init @ 00115ed0 size=752
// signature: undefined aw8672x_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw8672x_misc_para_init(long param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = (ulong)*(byte *)(*(long *)(param_1 + 0x2c8) + 2);
  haptic_hv_i2c_writes(param_1,0x47,&local_30,1);
  iVar5 = 0x711;
  if (0x707 < *(uint *)(param_1 + 0x530)) {
    iVar5 = 0x7c6;
  }
  uVar2 = iVar5 * *(int *)(param_1 + 0x584);
  uVar4 = 0x7f;
  if (uVar2 >> 0xd < 0x271) {
    uVar4 = (undefined1)(uVar2 / 40000);
  }
  *(undefined1 *)(param_1 + 0x563) = uVar4;
  if (*(int *)(param_1 + 0x534) != 0) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x534);
  }
  haptic_hv_i2c_reads(param_1,7,&local_30,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_30;
  haptic_hv_i2c_reads(param_1,10,&local_30,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_30;
  *(ulong *)(param_1 + 0x11) = local_30;
  haptic_hv_i2c_write_bits(param_1,0x46,0xfffffffe,*(undefined1 *)(param_1 + 0x55f));
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffff7f,(ulong)*(byte *)(param_1 + 0x561) << 7);
  if (*(char *)(param_1 + 0x564) == '\0') {
    _printk(&DAT_0013618a,"haptic_hv",0x6a1,"aw8672x_misc_para_init");
  }
  haptic_hv_i2c_writes(param_1,0x21,param_1 + 0x564,1);
  cVar1 = *(char *)(param_1 + 0x565);
  if (cVar1 == '\0') {
    _printk(&DAT_00136ea5,"haptic_hv",0x6a7,"aw8672x_misc_para_init");
    cVar1 = *(char *)(param_1 + 0x565);
  }
  haptic_hv_i2c_write_bits(param_1,0x1c,0xfffffff0,cVar1);
  local_34[0] = 0x32;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",0x2bf,"aw8672x_protect_config");
  local_38[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x4a,local_38,1);
  haptic_hv_i2c_writes(param_1,0x4b,local_34,1);
  haptic_hv_i2c_write_bits(param_1,6,0xfffffffd,2);
  _printk(&DAT_00132e8a,"haptic_hv",0x294,"aw8672x_vbat_ref_config");
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x30);
  local_34[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5a,local_34,1);
  haptic_hv_i2c_write_bits(param_1,0x56,0xfffffffc,*(undefined1 *)(param_1 + 0x560));
  haptic_hv_i2c_write_bits(param_1,0x6b,0xffffffdf,0x20);
  local_30 = CONCAT71(local_30._1_7_,0xdb);
  haptic_hv_i2c_writes(param_1,0x73,&local_30,1);
  local_30._0_2_ = CONCAT11(0x87,(byte)local_30);
  haptic_hv_i2c_writes(param_1,0x76,(ulong)&local_30 | 1,1);
  local_34[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5a,local_34,1);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_interrupt_setup @ 001161c4 size=156
// signature: undefined aw8672x_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw8672x_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x3b0,"aw8672x_interrupt_setup",local_2c[0]);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff99,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_set_rtp_aei @ 00116264 size=48
// signature: undefined aw8672x_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw8672x_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw8672x_upload_lra @ 00116298 size=248
// signature: undefined aw8672x_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw8672x_upload_lra(long param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 2) {
    _printk(&DAT_001323a9,"haptic_hv",0x27b,"aw8672x_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 0) {
        _printk(&DAT_00136e0b,"haptic_hv",0x270,"aw8672x_upload_lra");
        haptic_hv_i2c_write_bits(param_1,0x59,0xffffff80,0);
        return;
      }
      _printk(&DAT_00132648,"haptic_hv",0x281,"aw8672x_upload_lra");
      return;
    }
    _printk(&DAT_001378a9,"haptic_hv",0x275,"aw8672x_upload_lra",*(undefined4 *)(param_1 + 0x90));
    uVar1 = *(undefined4 *)(param_1 + 0x90);
  }
  haptic_hv_i2c_write_bits(param_1,0x59,0xffffff80,uVar1);
  return;
}



//------------------------------------------------------------
// aw8672x_get_wav_seq @ 00116394 size=236
// signature: undefined aw8672x_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8672x_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,10,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_get_ram_data @ 00116484 size=120
// signature: undefined aw8672x_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw8672x_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_bst_mode_config @ 00116500 size=200
// signature: undefined aw8672x_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8672x_bst_mode_config(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    _printk(&DAT_00135b17,"haptic_hv",0x1fb,"aw8672x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xfffffffe,0);
  }
  else if (param_2 == '\x01') {
    _printk(&DAT_00136a5b,"haptic_hv",0x1f5,"aw8672x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xfffffffe,1);
  }
  else {
    _printk(&DAT_00133915,"haptic_hv",0x201,"aw8672x_bst_mode_config",param_2);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_get_first_wave_addr @ 001165cc size=112
// signature: undefined aw8672x_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw8672x_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8672x_get_wav_loop @ 00116640 size=420
// signature: undefined aw8672x_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw8672x_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0x12,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw8672x_get_reg @ 001167e8 size=288
// signature: undefined aw8672x_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw8672x_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_c8 [128];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_c8[0x78] = 0;
  local_c8[0x68] = 0;
  local_c8[0x69] = 0;
  local_c8[0x6a] = 0;
  local_c8[0x6b] = 0;
  local_c8[0x6c] = 0;
  local_c8[0x6d] = 0;
  local_c8[0x6e] = 0;
  local_c8[0x6f] = 0;
  local_c8[0x70] = 0;
  local_c8[0x71] = 0;
  local_c8[0x72] = 0;
  local_c8[0x73] = 0;
  local_c8[0x74] = 0;
  local_c8[0x75] = 0;
  local_c8[0x76] = 0;
  local_c8[0x77] = 0;
  local_c8[0x58] = 0;
  local_c8[0x59] = 0;
  local_c8[0x5a] = 0;
  local_c8[0x5b] = 0;
  local_c8[0x5c] = 0;
  local_c8[0x5d] = 0;
  local_c8[0x5e] = 0;
  local_c8[0x5f] = 0;
  local_c8[0x60] = 0;
  local_c8[0x61] = 0;
  local_c8[0x62] = 0;
  local_c8[99] = 0;
  local_c8[100] = 0;
  local_c8[0x65] = 0;
  local_c8[0x66] = 0;
  local_c8[0x67] = 0;
  local_c8[0x48] = 0;
  local_c8[0x49] = 0;
  local_c8[0x4a] = 0;
  local_c8[0x4b] = 0;
  local_c8[0x4c] = 0;
  local_c8[0x4d] = 0;
  local_c8[0x4e] = 0;
  local_c8[0x4f] = 0;
  local_c8[0x50] = 0;
  local_c8[0x51] = 0;
  local_c8[0x52] = 0;
  local_c8[0x53] = 0;
  local_c8[0x54] = 0;
  local_c8[0x55] = 0;
  local_c8[0x56] = 0;
  local_c8[0x57] = 0;
  local_c8[0x38] = 0;
  local_c8[0x39] = 0;
  local_c8[0x3a] = 0;
  local_c8[0x3b] = 0;
  local_c8[0x3c] = 0;
  local_c8[0x3d] = 0;
  local_c8[0x3e] = 0;
  local_c8[0x3f] = 0;
  local_c8[0x40] = 0;
  local_c8[0x41] = 0;
  local_c8[0x42] = 0;
  local_c8[0x43] = 0;
  local_c8[0x44] = 0;
  local_c8[0x45] = 0;
  local_c8[0x46] = 0;
  local_c8[0x47] = 0;
  local_c8[0x28] = 0;
  local_c8[0x29] = 0;
  local_c8[0x2a] = 0;
  local_c8[0x2b] = 0;
  local_c8[0x2c] = 0;
  local_c8[0x2d] = 0;
  local_c8[0x2e] = 0;
  local_c8[0x2f] = 0;
  local_c8[0x30] = 0;
  local_c8[0x31] = 0;
  local_c8[0x32] = 0;
  local_c8[0x33] = 0;
  local_c8[0x34] = 0;
  local_c8[0x35] = 0;
  local_c8[0x36] = 0;
  local_c8[0x37] = 0;
  local_c8[0x18] = 0;
  local_c8[0x19] = 0;
  local_c8[0x1a] = 0;
  local_c8[0x1b] = 0;
  local_c8[0x1c] = 0;
  local_c8[0x1d] = 0;
  local_c8[0x1e] = 0;
  local_c8[0x1f] = 0;
  local_c8[0x20] = 0;
  local_c8[0x21] = 0;
  local_c8[0x22] = 0;
  local_c8[0x23] = 0;
  local_c8[0x24] = 0;
  local_c8[0x25] = 0;
  local_c8[0x26] = 0;
  local_c8[0x27] = 0;
  local_c8[8] = 0;
  local_c8[9] = 0;
  local_c8[10] = 0;
  local_c8[0xb] = 0;
  local_c8[0xc] = 0;
  local_c8[0xd] = 0;
  local_c8[0xe] = 0;
  local_c8[0xf] = 0;
  local_c8[0x10] = 0;
  local_c8[0x11] = 0;
  local_c8[0x12] = 0;
  local_c8[0x13] = 0;
  local_c8[0x14] = 0;
  local_c8[0x15] = 0;
  local_c8[0x16] = 0;
  local_c8[0x17] = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[6] = 0;
  local_c8[7] = 0;
  haptic_hv_i2c_reads(param_1,0,local_c8,0x32);
  haptic_hv_i2c_reads(param_1,0x33,local_c8 + 0x33,0xf);
  haptic_hv_i2c_reads(param_1,0x43,local_c8 + 0x43,0x36);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 0x32) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_c8[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x79);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw8672x_get_prctmode @ 0011690c size=96
// signature: undefined aw8672x_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw8672x_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x4a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw8672x_get_trim_lra @ 00116970 size=96
// signature: undefined aw8672x_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

byte aw8672x_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x59,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0x7f;
}



//------------------------------------------------------------
// aw8672x_get_glb_state @ 001169d4 size=96
// signature: undefined aw8672x_get_glb_state(void)
// callers: []
//------------------------------------------------------------

byte aw8672x_get_glb_state(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0xf;
}



//------------------------------------------------------------
// aw8672x_get_osc_status @ 00116a38 size=96
// signature: undefined aw8672x_get_osc_status(void)
// callers: []
//------------------------------------------------------------

byte aw8672x_get_osc_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw8672x_rtp_get_fifo_afs @ 00116a9c size=96
// signature: undefined aw8672x_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw8672x_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw8672x_rtp_get_fifo_aes @ 00116b00 size=96
// signature: undefined aw8672x_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw8672x_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw8672x_get_theory_time @ 00116b64 size=288
// signature: undefined aw8672x_get_theory_time(void)
// callers: []
//------------------------------------------------------------

ulong aw8672x_get_theory_time(long param_1)

{
  long lVar1;
  ulong uVar2;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x45,local_2c,1);
  if ((local_2c[0] & 0x60) == 0x60) {
    uVar2 = (ulong)((uint)(*(int *)(param_1 + 0x7c) * 1000) >> 3);
  }
  else if ((local_2c[0] & 0x60) == 0x20) {
    uVar2 = (ulong)(uint)(*(int *)(param_1 + 0x7c) * 1000) / 0x30;
  }
  else if ((local_2c[0] & 0x60) == 0) {
    uVar2 = (ulong)(uint)(*(int *)(param_1 + 0x7c) * 1000) / 0x18;
  }
  else {
    uVar2 = (ulong)(uint)(*(int *)(param_1 + 0x7c) * 1000) / 0xc;
  }
  _printk(&DAT_0013791e,"haptic_hv",0x62f,"aw8672x_get_theory_time",*(undefined8 *)(param_1 + 0xa0),
          uVar2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// aw8672x_snd_soc_init @ 00116c88 size=200
// signature: undefined aw8672x_snd_soc_init(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

int aw8672x_snd_soc_init(undefined8 param_1)

{
  int iVar1;
  void *__dest;
  
  __dest = (void *)devm_kmalloc(param_1,0xe0,0xdc0);
  if (__dest == (void *)0x0) {
    iVar1 = -0xc;
  }
  else {
    memcpy(__dest,&aw8672x_dai,0xe0);
    _printk(&DAT_00134c88,"haptic_hv",0x102,"aw8672x_snd_soc_init","aw8672x-aif");
    iVar1 = snd_soc_register_component(param_1,soc_codec_dev_aw8672x,__dest,1);
    if (iVar1 < 0) {
      _printk(&DAT_001349c4,"haptic_hv",0x107,"aw8672x_snd_soc_init",iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_show @ 00116d54 size=64
// signature: undefined cont_drv_lvl_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_lvl_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_lvl = 0x%02X, cont_drv2_lvl = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4ba),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bb));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_store @ 00116d98 size=196
// signature: undefined cont_drv_lvl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_lvl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_40[1] = 0;
  iVar1 = sscanf(param_3,"%x %x",local_40,(uint *)((ulong)local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x4ba) = (char)local_40[0];
    *(char *)(lVar2 + 0x4bb) = (char)local_40[1];
    haptic_hv_i2c_write_bits(lVar2 + -0xa8,0x1d,0xffffff80);
    haptic_hv_i2c_write_bits(lVar2 + -0xa8,0x1e,0xffffff80,*(undefined1 *)(lVar2 + 0x4bb));
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_time_show @ 00116e60 size=64
// signature: undefined cont_drv_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4be),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bf));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_time_store @ 00116ea4 size=180
// signature: undefined cont_drv_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_34;
  undefined1 local_33;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_30,(uint *)((ulong)&local_30 | 4));
  if (iVar1 == 2) {
    *(undefined1 *)(lVar2 + 0x4be) = (undefined1)local_30;
    *(char *)(lVar2 + 0x4bf) = (char)((ulong)local_30 >> 0x20);
    local_34 = (undefined1)local_30;
    local_33 = *(undefined1 *)(lVar2 + 0x4bf);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1f,&local_34,2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_brk_time_show @ 00116f5c size=60
// signature: undefined cont_brk_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_brk_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_brk_time_store @ 00116f9c size=104
// signature: undefined cont_brk_time_store(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x4bc;
  iVar2 = kstrtou8(param_3,0,lVar1);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    haptic_hv_i2c_writes(lVar3 + -0xa8,0x21,lVar1,1);
  }
  return param_4;
}



//------------------------------------------------------------
// trig_show @ 00117008 size=292
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x61f),(uint)*(byte *)(lVar2 + 0x620),
                   (uint)*(byte *)(lVar2 + 0x621),(uint)*(byte *)(lVar2 + 0x623),
                   (uint)*(byte *)(lVar2 + 0x622),(uint)*(byte *)(lVar2 + 0x624),
                   (uint)*(byte *)(lVar2 + 0x61d),(uint)*(byte *)(lVar2 + 0x61e));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x62c),(uint)*(byte *)(lVar2 + 0x62d),
                   (uint)*(byte *)(lVar2 + 0x62e),(uint)*(byte *)(lVar2 + 0x630),
                   (uint)*(byte *)(lVar2 + 0x62f),(uint)*(byte *)(lVar2 + 0x631),
                   (uint)*(byte *)(lVar2 + 0x62a),(uint)*(byte *)(lVar2 + 0x62b));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x639),(uint)*(byte *)(lVar2 + 0x63a),
                   (uint)*(byte *)(lVar2 + 0x63b),(uint)*(byte *)(lVar2 + 0x63d),
                   (uint)*(byte *)(lVar2 + 0x63c),(uint)*(byte *)(lVar2 + 0x63e),
                   (uint)*(byte *)(lVar2 + 0x637),(uint)*(byte *)(lVar2 + 0x638));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 00117130 size=776
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar5 = sscanf(param_3,"%u %u %u %u %u %u %u %u %u",(uint *)&local_60,
                 (uint *)((ulong)&local_60 | 4),(uint *)&local_58,(uint *)((long)&local_58 + 4),
                 (uint *)&local_50,(uint *)((long)&local_50 + 4),(uint *)&local_48,
                 (uint *)((long)&local_48 + 4),local_40);
  if (iVar5 == 9) {
    _printk(&DAT_001359f8,"haptic_hv",0x746,"trig_store",local_60 & 0xffffffff,local_60._4_4_,
            local_58 & 0xffffffff,local_58._4_4_,local_50 & 0xffffffff,local_50 >> 0x20,
            local_48 & 0xffffffff,local_48._4_4_,local_40[0]);
    uVar3 = local_60;
    if ((uint)local_60 - 4 < 0xfffffffd) {
      _printk(&DAT_001369d0,"haptic_hv",0x748,"trig_store");
    }
    else {
      uVar2 = (uint)local_60 - 1;
      if ((uVar2 == 0) && (*(char *)(lVar6 + 0x4e6) != '\0')) {
        _printk(&DAT_00136135,"haptic_hv",0x74c,"trig_store");
      }
      else if (*(char *)(lVar6 + -0xa2) == '\0') {
        _printk(&DAT_001325b9,"haptic_hv",0x750,"trig_store");
      }
      else {
        if (((uint)local_50 <= *(byte *)(lVar6 + 0x47c)) &&
           ((uint)local_48 <= *(byte *)(lVar6 + 0x47c))) {
          lVar1 = lVar6 + 0x618;
          local_60 = CONCAT44(local_60._4_4_,uVar2);
          *(char *)(lVar1 + (ulong)uVar2 * 0xd + 7) = (char)(uVar3 >> 0x20);
          if (uVar2 < 3) {
            *(char *)(lVar1 + (ulong)uVar2 * 0xd + 8) = (char)local_58;
            if (uVar2 < 3) {
              *(char *)(lVar1 + (ulong)uVar2 * 0xd + 9) = (char)(local_58 >> 0x20);
              if (uVar2 < 3) {
                *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xb) = (char)local_50;
                if (uVar2 < 3) {
                  *(char *)(lVar1 + (ulong)uVar2 * 0xd + 10) = (char)(local_50 >> 0x20);
                  if (uVar2 < 3) {
                    *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xc) = (char)local_48;
                    if (uVar2 < 3) {
                      *(char *)(lVar1 + (ulong)uVar2 * 0xd + 5) = (char)(local_48 >> 0x20);
                      if (uVar2 < 3) {
                        lVar7 = lVar6 + -0xa8;
                        *(char *)(lVar1 + (ulong)uVar2 * 0xd + 6) = (char)local_40[0];
                        mutex_lock(lVar6 + 0x2a8);
                        if ((uint)local_60 == 2) {
                          aw8672x_trig3_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 1) {
                          aw8672x_trig2_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 0) {
                          aw8672x_trig1_param_config(lVar7);
                        }
                        mutex_unlock(lVar6 + 0x2a8);
                        goto LAB_001171b4;
                      }
                    }
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x117438);
          (*pcVar4)();
        }
        _printk(&DAT_00134564,"haptic_hv",0x754,"trig_store");
      }
    }
  }
LAB_001171b4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8672x_trig1_param_config @ 00117438 size=188
// signature: undefined aw8672x_trig1_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8672x_trig1_param_config(long param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = *(char *)(param_1 + 0x6c7) != '\0';
  uVar1 = (uint)bVar2 << 6;
  if (*(char *)(param_1 + 0x6c8) != '\0') {
    uVar1 = (uint)bVar2 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6c5) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6c6) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
  haptic_hv_i2c_write_bits
            (param_1,0x33,0xffffff00,
             *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x36,0xffffff00,
             *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7);
  return;
}



//------------------------------------------------------------
// aw8672x_trig2_param_config @ 001174f4 size=188
// signature: undefined aw8672x_trig2_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8672x_trig2_param_config(long param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = *(char *)(param_1 + 0x6d4) != '\0';
  bVar1 = bVar2 << 2;
  if (*(char *)(param_1 + 0x6d5) != '\0') {
    bVar1 = bVar2 << 2 | 8;
  }
  if (*(char *)(param_1 + 0x6d2) != '\0') {
    bVar1 = bVar1 | 2;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x6d3) != '\0');
  haptic_hv_i2c_write_bits
            (param_1,0x34,0xffffff00,
             *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x37,0xffffff00,
             *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7);
  return;
}



//------------------------------------------------------------
// aw8672x_trig3_param_config @ 001175b0 size=188
// signature: undefined aw8672x_trig3_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8672x_trig3_param_config(long param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar1 = (uint)bVar2 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar1 = (uint)bVar2 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  haptic_hv_i2c_write_bits
            (param_1,0x35,0xffffff00,
             *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7);
  haptic_hv_i2c_write_bits
            (param_1,0x38,0xffffff00,
             *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7);
  return;
}



//------------------------------------------------------------
// rtp_auto_sin_show @ 00117670 size=60
// signature: undefined rtp_auto_sin_show(void)
// callers: []
//------------------------------------------------------------

long rtp_auto_sin_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"rtp_cnt = %u\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// rtp_auto_sin_store @ 001176b0 size=332
// signature: undefined rtp_auto_sin_store(void)
// callers: []
//------------------------------------------------------------

long rtp_auto_sin_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    _printk(&DAT_00132666,"haptic_hv",0x788,"rtp_auto_sin_store");
    param_4 = (long)iVar1;
    goto LAB_00117770;
  }
  mutex_lock(lVar3 + 0x2a8);
  if (local_3c == 0) {
    uVar2 = 0;
    *(undefined4 *)(lVar3 + -0x60) = 0;
LAB_00117754:
    haptic_hv_i2c_write_bits(lVar3 + -0xa8,0x2d,0xffffffef,uVar2);
  }
  else {
    if (local_3c < *(uint *)(lVar3 + -0x28)) {
      uVar2 = 0x10;
      *(undefined4 *)(lVar3 + -0x60) = 1;
      *(uint *)(lVar3 + -0x14) = local_3c;
      goto LAB_00117754;
    }
    *(undefined4 *)(lVar3 + -0x60) = 0;
    _printk(&DAT_0013408e,"haptic_hv",0x799,"rtp_auto_sin_store",local_3c);
  }
  mutex_unlock(lVar3 + 0x2a8);
  queue_work_on(0x20,*(undefined8 *)(lVar3 + 0x468),lVar3 + 0x350);
LAB_00117770:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8672x_set_dai_sysclk @ 00117800 size=64
// signature: undefined aw8672x_set_dai_sysclk(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_set_dai_sysclk(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  _printk(&DAT_00132947,"haptic_hv",0x51,"aw8672x_set_dai_sysclk",param_3);
  return 0;
}



//------------------------------------------------------------
// aw8672x_set_fmt @ 00117844 size=64
// signature: undefined aw8672x_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_set_fmt(undefined8 param_1,undefined4 param_2)

{
  _printk(&DAT_00137211,"haptic_hv",0x4a,"aw8672x_set_fmt",param_2);
  return 0;
}



//------------------------------------------------------------
// aw8672x_mute @ 00117888 size=380
// signature: undefined aw8672x_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_mute(long param_1,int param_2,int param_3)

{
  long lVar1;
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = '\0';
  if (param_3 == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0x95,"aw8672x_mute");
  }
  else {
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
    _printk(&DAT_001338b0,"haptic_hv",0x98,"aw8672x_mute",param_2);
    mutex_lock(lVar1 + 0x350);
    if (param_2 == 0) {
      haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,2);
      haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0x80);
      usleep_range_state(1000,0x5dc,2);
      haptic_hv_i2c_reads(lVar1,0x3f,local_3c,1);
      if (local_3c[0] != '\n') {
        _printk(&DAT_00135703,"haptic_hv",0xa3,"aw8672x_mute");
        aw8672x_i2s_enable(lVar1,0);
      }
    }
    else {
      haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,0);
      haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0);
    }
    mutex_unlock(lVar1 + 0x350);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8672x_startup @ 00117a08 size=8
// signature: undefined aw8672x_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_startup(void)

{
  return 0;
}



//------------------------------------------------------------
// aw8672x_shutdown @ 00117a14 size=152
// signature: undefined aw8672x_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw8672x_shutdown(long param_1,long param_2)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0xb2,"aw8672x_shutdown");
  }
  else {
    lVar1 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
    mutex_lock(lVar1 + 0x350);
    haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,0);
    haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0);
    mutex_unlock(lVar1 + 0x350);
  }
  return;
}



//------------------------------------------------------------
// aw8672x_hw_params @ 00117ab0 size=432
// signature: undefined aw8672x_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_hw_params(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0x61,"aw8672x_hw_params");
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x128);
  lVar6 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132051,"haptic_hv",0x66,"aw8672x_hw_params",iVar2);
  if (iVar2 == 48000) {
LAB_00117b7c:
    uVar7 = 0;
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 != 0) goto LAB_00117b54;
LAB_00117b88:
    uVar4 = *(uint *)(param_2 + 0x28);
    if (uVar4 == 0) {
      uVar5 = 0;
      goto LAB_00117ba8;
    }
    uVar5 = 0x20;
  }
  else {
    if (iVar2 != 96000) {
      _printk(&DAT_00132073,"haptic_hv",0x70,"aw8672x_hw_params");
      goto LAB_00117b7c;
    }
    uVar7 = 4;
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 == 0) goto LAB_00117b88;
LAB_00117b54:
    uVar5 = 0;
  }
  uVar4 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
  uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
  uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
  uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
  uVar5 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10) | uVar5;
LAB_00117ba8:
  cVar3 = snd_pcm_format_width(uVar5);
  _printk(&DAT_001340cb,"haptic_hv",0x75,"aw8672x_hw_params",cVar3);
  if (cVar3 != '\x10') {
    if (cVar3 == ' ') {
      uVar7 = uVar7 | 2;
    }
    else if (cVar3 == '\x18') {
      uVar7 = uVar7 | 1;
    }
    else {
      uVar7 = uVar7 | 2;
      _printk(&DAT_00133305,"haptic_hv",0x82,"aw8672x_hw_params");
    }
  }
  lVar1 = lVar6 + 0x350;
  mutex_lock(lVar1);
  haptic_hv_i2c_write_bits(lVar6,0x53,0xf8,uVar7);
  mutex_unlock(lVar1);
  return 0;
}



//------------------------------------------------------------
// aw8672x_i2s_enable @ 00117c60 size=88
// signature: undefined aw8672x_i2s_enable(void)
// callers: [aw8672x_mute]
//------------------------------------------------------------

void aw8672x_i2s_enable(undefined8 param_1,ulong param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = (param_2 & 1) == 0;
  uVar2 = 2;
  if (bVar1) {
    uVar2 = 0;
  }
  uVar3 = 0xffffff80;
  if (bVar1) {
    uVar3 = 0;
  }
  haptic_hv_i2c_write_bits(0xffffff80,param_1,0x46,0xfffffffd,uVar2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xffffff7f,uVar3);
  return;
}



//------------------------------------------------------------
// aw8672x_codec_probe @ 00117cbc size=104
// signature: undefined aw8672x_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8672x_codec_probe(long param_1)

{
  long lVar1;
  undefined2 local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0x800;
  haptic_hv_i2c_writes(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98),0x52,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8672x_codec_remove @ 00117d28 size=56
// signature: undefined aw8672x_codec_remove(void)
// callers: []
//------------------------------------------------------------

void aw8672x_codec_remove(void)

{
  _printk(&DAT_00132e8a,"haptic_hv",0xe7,"aw8672x_codec_remove");
  return;
}



//------------------------------------------------------------
// aw8692x_get_f0 @ 00117d64 size=1012
// signature: undefined aw8692x_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8692x_get_f0(long param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  byte bVar5;
  bool bVar6;
  undefined *puVar7;
  int iVar8;
  undefined8 uVar9;
  byte local_4c [4];
  byte local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined2 local_3f;
  undefined2 local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_4c[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw8692x_stop();
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  _printk(&DAT_001331a6,"haptic_hv",0x151,"aw8692x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x112,"aw8692x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffff7f,0);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_reads(param_1,8,local_4c,1);
  bVar5 = local_4c[0];
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  local_40 = *(undefined1 *)(param_1 + 0x563);
  local_3f = *(undefined2 *)(param_1 + 0x566);
  haptic_hv_i2c_writes(param_1,0x1e,&local_40,3);
  if (*(char *)(param_1 + 0x568) == '\0') {
    _printk(&DAT_001366d5,"haptic_hv",0x3a7,"aw8692x_get_f0");
    uVar2 = *(uint *)(param_1 + 0x530);
  }
  else {
    haptic_hv_i2c_writes(param_1,0x22,param_1 + 0x568,1);
    uVar2 = *(uint *)(param_1 + 0x530);
  }
  if (uVar2 == 0) {
    uVar9 = 0xffffffde;
  }
  else {
    local_3c._1_1_ = (undefined1)(local_3c >> 8);
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = 240000 / uVar2;
    }
    iVar8 = (uVar3 - ((uint)*(byte *)(param_1 + 0x565) + (uint)*(byte *)(param_1 + 0x568))) + -8;
    if (0xfe < iVar8) {
      iVar8 = 0xff;
    }
    if (iVar8 < 1) {
      iVar8 = 0;
    }
    local_40 = (undefined1)iVar8;
    haptic_hv_i2c_writes(param_1,0x1a,&local_40,1);
    local_3c = CONCAT11(local_3c._1_1_,1);
    local_44[0] = 2;
    local_48[0] = 0;
    _printk(&DAT_00133f37,"haptic_hv",0xed,"aw8692x_play_go",1);
    haptic_hv_i2c_reads(param_1,0x79,local_48,1);
    puVar1 = &local_3c;
    if (0x3f < local_48[0]) {
      puVar1 = (undefined2 *)local_44;
    }
    haptic_hv_i2c_writes(param_1,9,puVar1,1);
    usleep_range_state(20000,0x5014,2);
    iVar8 = -100;
    do {
      local_3c = local_3c & 0xff00;
      haptic_hv_i2c_reads(param_1,0x3f,&local_3c,1);
      if ((char)local_3c == '\0') {
        puVar7 = &DAT_00136940;
        uVar9 = 0xfd;
        goto LAB_001180a0;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar6 = iVar8 != -1;
      iVar8 = iVar8 + 1;
    } while (bVar6);
    puVar7 = &DAT_00137ca1;
    uVar9 = 0x103;
LAB_001180a0:
    _printk(puVar7,"haptic_hv",uVar9,"aw8692x_wait_enter_standby");
    local_3c = 0;
    haptic_hv_i2c_reads(param_1,0x25,&local_3c,2);
    uVar2 = (uint)(local_3c >> 8) | (local_3c & 0xff00ff) << 8;
    if (uVar2 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      _printk(&DAT_00132236,"haptic_hv",0x370,"aw8692x_read_f0");
      uVar9 = 0xffffffde;
    }
    else {
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = 0x3a9800 / uVar2;
      }
      *(uint *)(param_1 + 100) = uVar3;
      _printk(&DAT_00136043,"haptic_hv",0x374,"aw8692x_read_f0");
      uVar9 = 0;
    }
    haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,bVar5 & 4);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// aw8692x_ram_get_f0 @ 0011815c size=1048
// signature: undefined aw8692x_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8692x_ram_get_f0(long param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  long lVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 uVar9;
  uint uVar10;
  int iVar11;
  byte local_58 [4];
  byte local_54 [4];
  undefined1 local_50 [4];
  undefined2 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    puVar6 = &DAT_001325b9;
    uVar7 = 0x3cd;
  }
  else {
    if (4 < *(byte *)(param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
      aw8692x_stop(param_1);
      haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
      _printk(&DAT_00136db2,"haptic_hv",299,"aw8692x_play_mode");
      *(undefined1 *)(param_1 + 0xb) = 1;
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,0);
      _printk(&DAT_0013335b,"haptic_hv",0x10c,"aw8692x_bst_mode_config");
      haptic_hv_i2c_write_bits(param_1,6,0xffffff7f,0x80);
      haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
      haptic_hv_i2c_reads(param_1,8,local_58,1);
      bVar4 = local_58[0];
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
      haptic_hv_i2c_write_bits(param_1,6,0xffffff80,0x48);
      local_4c._0_1_ = 5;
      haptic_hv_i2c_writes(param_1,10,&local_4c,1);
      local_4c = (ushort)local_4c._1_1_ << 8;
      haptic_hv_i2c_writes(param_1,0xb,&local_4c,1);
      haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0x20);
      local_4c = CONCAT11(local_4c._1_1_,1);
      local_50[0] = 2;
      local_54[0] = 0;
      _printk(&DAT_00133f37,"haptic_hv",0xed,"aw8692x_play_go",1);
      haptic_hv_i2c_reads(param_1,0x79,local_54,1);
      puVar1 = &local_4c;
      if (0x3f < local_54[0]) {
        puVar1 = (undefined2 *)local_50;
      }
      haptic_hv_i2c_writes(param_1,9,puVar1,1);
      usleep_range_state(20000,0x5014,2);
      iVar11 = -100;
      do {
        local_4c = local_4c & 0xff00;
        haptic_hv_i2c_reads(param_1,0x3f,&local_4c,1);
        if ((char)local_4c == '\0') {
          puVar6 = &DAT_00136940;
          uVar7 = 0xfd;
          goto LAB_00118430;
        }
        usleep_range_state(2000,0x9c4,2);
        bVar5 = iVar11 != -1;
        iVar11 = iVar11 + 1;
      } while (bVar5);
      puVar6 = &DAT_00137ca1;
      uVar7 = 0x103;
LAB_00118430:
      _printk(puVar6,"haptic_hv",uVar7,"aw8692x_wait_enter_standby");
      local_4c = 0;
      haptic_hv_i2c_reads(param_1,0x25,&local_4c,2);
      uVar10 = (uint)(local_4c >> 8) | (local_4c & 0xff00ff) << 8;
      if (uVar10 == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        _printk(&DAT_00132236,"haptic_hv",0x370,"aw8692x_read_f0");
        uVar7 = 0xffffffde;
      }
      else {
        uVar2 = 0;
        if (uVar10 != 0) {
          uVar2 = 0x3a9800 / uVar10;
        }
        *(uint *)(param_1 + 100) = uVar2;
        _printk(&DAT_00136043,"haptic_hv",0x374,"aw8692x_read_f0");
        uVar7 = 0;
      }
      uVar10 = *(uint *)(param_1 + 0x38);
      if (uVar10 >> 4 < 0x177) {
        uVar8 = 0x28;
      }
      else {
        if (0x2cac < uVar10) {
          uVar10 = 0x2cad;
        }
        uVar8 = (ulong)(uVar10 * 10 - 35000) / 0x271;
      }
      haptic_hv_i2c_write_bits(param_1,6,0xffffff80,uVar8);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
      if ((bVar4 >> 2 & 1) == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = 4;
      }
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar9);
      goto LAB_0011853c;
    }
    puVar6 = &DAT_00132b34;
    uVar7 = 0x3d1;
  }
  _printk(puVar6,"haptic_hv",uVar7,"aw8692x_ram_get_f0");
  uVar7 = 0xffffffde;
LAB_0011853c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// aw8692x_creat_node @ 00118578 size=100
// signature: undefined aw8692x_creat_node(void)
// callers: []
//------------------------------------------------------------

int aw8692x_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw8692x_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_001320c4,"haptic_hv",0x680,"aw8692x_creat_node");
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw8692x_offset_cali @ 001185e0 size=8
// signature: undefined aw8692x_offset_cali(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8692x_offset_cali(void)

{
  return 0;
}



//------------------------------------------------------------
// aw8692x_get_irq_state @ 001185ec size=440
// signature: undefined aw8692x_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  if ((char)local_1c[0] < '\0') {
    _printk(&DAT_00131b4f,"haptic_hv",0x33e,"aw8692x_get_irq_state");
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  if ((local_1c[0] >> 6 & 1) != 0) {
    _printk(&DAT_001373ce,"haptic_hv",0x343,"aw8692x_get_irq_state");
    uVar2 = 4;
  }
  if ((local_1c[0] >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x348,"aw8692x_get_irq_state");
    uVar2 = 5;
  }
  if ((local_1c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x34d,"aw8692x_get_irq_state");
    uVar2 = 6;
  }
  if ((local_1c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x352,"aw8692x_get_irq_state");
    uVar2 = 7;
  }
  if ((local_1c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",0x357,"aw8692x_get_irq_state");
    uVar2 = 10;
  }
  if ((local_1c[0] >> 3 & 1) != 0) {
    _printk(&DAT_00131f9b,"haptic_hv",0x35c,"aw8692x_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_1c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_check_qualify @ 001187a8 size=488
// signature: undefined aw8692x_check_qualify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00118814) */
/* WARNING: Removing unreachable block (ram,0x0011883c) */
/* WARNING: Removing unreachable block (ram,0x00118848) */
/* WARNING: Removing unreachable block (ram,0x001188ac) */
/* WARNING: Removing unreachable block (ram,0x001188cc) */
/* WARNING: Removing unreachable block (ram,0x001188d8) */
/* WARNING: Removing unreachable block (ram,0x00118920) */
/* WARNING: Removing unreachable block (ram,0x00118918) */

void aw8692x_check_qualify(undefined8 param_1)

{
  long lVar1;
  undefined2 local_2c;
  undefined1 local_2a;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2a = 0;
  local_2c = 0;
  _printk(&DAT_00132e8a,"haptic_hv",0x23,"aw8692x_check_qualify");
  haptic_hv_i2c_reads(param_1,0x61,&local_2c,3);
  _printk(&DAT_0013785a,"haptic_hv",0x26,"aw8692x_check_qualify");
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0xffffffde);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_judge_rtp_going @ 00118994 size=144
// signature: undefined aw8692x_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw8692x_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  bVar2 = local_1c[0] == '\b';
  if (bVar2) {
    _printk(&DAT_00134c3c,"haptic_hv",0x2e3,"aw8692x_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_container_update @ 00118a28 size=888
// signature: undefined aw8692x_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8692x_container_update(long param_1,int *param_2)

{
  byte bVar1;
  long lVar2;
  ushort uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte local_460;
  undefined1 local_45f;
  byte local_45e;
  ushort local_45c [2];
  char local_458 [1024];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  memset(local_458,0,0x400);
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  aw8692x_stop(param_1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  bVar1 = *(byte *)((long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4);
  uVar3 = CONCAT11(bVar1,*(undefined1 *)((long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 5));
  uVar8 = (uint)uVar3;
  *(uint *)(param_1 + 0x520) = uVar8;
  _printk(&DAT_00136e85,"haptic_hv",0x4e3,"aw8692x_container_update",uVar8);
  iVar6 = uVar8 - (uVar3 >> 2);
  local_460 = (bVar1 & 0xfe) << 3 | (byte)((uint)iVar6 >> 8) & 0xf;
  local_45f = (undefined1)(uVar3 >> 1);
  local_45e = (byte)iVar6;
  haptic_hv_i2c_writes(param_1,0x2f,&local_460,3);
  haptic_hv_i2c_reads(param_1,0x2f,&local_460,3);
  _printk(&DAT_001344e9,"haptic_hv",0x4f1,"aw8692x_container_update",
          CONCAT11(local_460 >> 4,local_45f));
  _printk(&DAT_001351c2,"haptic_hv",0x4f4,"aw8692x_container_update",
          (uint)local_45e | (local_460 & 0xf) << 8);
  uVar8 = *(uint *)(param_1 + 0x520);
  local_45c[0] = (ushort)(uVar8 >> 8) & 0xff | (ushort)((uVar8 & 0xff00ff) << 8);
  haptic_hv_i2c_write_bits(param_1,0x2d,0xffffffe0,uVar8 >> 8);
  haptic_hv_i2c_writes(param_1,0x2e,(ulong)local_45c | 1,1);
  local_45c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_45c,2);
  uVar8 = (uint)*(byte *)(param_1 + 0x526);
  iVar6 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar6) {
    do {
      iVar9 = iVar6 - uVar8;
      if (0x7ff < iVar9) {
        iVar9 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar8 + 4,iVar9);
      iVar6 = *param_2;
      uVar8 = iVar9 + uVar8;
    } while ((int)uVar8 < iVar6);
  }
  local_45c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_45c,2);
  uVar8 = (uint)*(byte *)(param_1 + 0x526);
  iVar6 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar6) {
    do {
      uVar10 = iVar6 - uVar8;
      if (0x3ff < (int)uVar10) {
        uVar10 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,local_458,uVar10);
      if (uVar10 != 0) {
        uVar5 = 0;
        do {
          if (0x3ff < uVar5) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x118d9c);
            (*pcVar4)();
          }
          if (local_458[(int)uVar5] !=
              *(char *)((long)param_2 + (long)(int)uVar5 + (long)(int)uVar8 + 4)) {
            _printk(&DAT_001373f1,"haptic_hv",0x4bd,"aw8692x_check_ram_data");
            _printk(&DAT_001351ee,"haptic_hv",0x513,"aw8692x_container_update");
            uVar7 = 0xffffffde;
            goto LAB_00118d44;
          }
          uVar5 = uVar5 + 1;
        } while (uVar10 != uVar5);
      }
      iVar6 = *param_2;
      uVar8 = uVar10 + uVar8;
    } while ((int)uVar8 < iVar6);
  }
  _printk(&DAT_00132afb,"haptic_hv",0x515,"aw8692x_container_update");
  uVar7 = 0;
LAB_00118d44:
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  mutex_unlock(param_1 + 0x350);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// aw8692x_stop @ 00118da4 size=452
// signature: undefined aw8692x_stop(void)
// callers: [aw8692x_ram_get_f0, aw8692x_get_vbat, aw8692x_get_lra_resistance, aw8692x_get_f0, aw8692x_container_update]
//------------------------------------------------------------

void aw8692x_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x173,"aw8692x_stop");
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_30[0] = 1;
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,3);
  haptic_hv_i2c_writes(param_1,9,local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  iVar3 = -100;
  do {
    local_2c[0] = '\0';
    haptic_hv_i2c_reads(param_1,0x3f,local_2c,1);
    if (local_2c[0] == '\0') {
      _printk(&DAT_00136940,"haptic_hv",0xfd,"aw8692x_wait_enter_standby");
      goto LAB_00118f3c;
    }
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar3 != -1;
    iVar3 = iVar3 + 1;
  } while (bVar2);
  _printk(&DAT_00137ca1,"haptic_hv",0x103,"aw8692x_wait_enter_standby");
  _printk(&DAT_00135cf9,"haptic_hv",0x17e,"aw8692x_stop");
  _printk(&DAT_00134895,"haptic_hv",0x121,"aw8692x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 0;
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0);
LAB_00118f3c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_vbat @ 00118f6c size=424
// signature: undefined aw8692x_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_vbat(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined2 local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  aw8692x_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_2c,2);
  uVar1 = (uint)local_2c._1_1_ | ((byte)local_2c & 3) << 8;
  uVar3 = uVar1 * 0x17bb;
  uVar2 = uVar3 >> 10;
  *(uint *)(param_1 + 0x70) = uVar2;
  if (0x4653ff < uVar3) {
    *(undefined4 *)(param_1 + 0x70) = 0x1194;
    _printk(&DAT_001328b9,"haptic_hv",0x481,"aw8692x_get_vbat",0x1194);
    uVar2 = *(uint *)(param_1 + 0x70);
  }
  if (uVar2 < 3000) {
    *(undefined4 *)(param_1 + 0x70) = 3000;
    _printk(&DAT_00135218,"haptic_hv",0x485,"aw8692x_get_vbat",3000);
    uVar2 = *(uint *)(param_1 + 0x70);
  }
  _printk(&DAT_00135e49,"haptic_hv",0x487,"aw8692x_get_vbat",uVar2,uVar1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_cont_config @ 00119118 size=440
// signature: undefined aw8692x_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw8692x_cont_config(long param_1)

{
  undefined1 *puVar1;
  long lVar2;
  undefined1 local_48 [4];
  byte local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48[0] = 0xff;
  _printk(&DAT_001331a6,"haptic_hv",0x151,"aw8692x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x112,"aw8692x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffff7f,0);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  haptic_hv_i2c_writes(param_1,0x1e,param_1 + 0x563,1);
  haptic_hv_i2c_writes(param_1,0x20,local_48,1);
  local_3c[0] = 1;
  local_40[0] = 2;
  local_44[0] = 0;
  _printk(&DAT_00133f37,"haptic_hv",0xed,"aw8692x_play_go",1);
  haptic_hv_i2c_reads(param_1,0x79,local_44,1);
  puVar1 = local_3c;
  if (0x3f < local_44[0]) {
    puVar1 = local_40;
  }
  haptic_hv_i2c_writes(param_1,9,puVar1,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_play_go @ 001192d4 size=204
// signature: undefined aw8692x_play_go(void)
// callers: []
//------------------------------------------------------------

void aw8692x_play_go(undefined8 param_1,byte param_2)

{
  undefined1 *puVar1;
  long lVar2;
  byte local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c[0] = 1;
  local_30[0] = 2;
  local_34[0] = 0;
  _printk(&DAT_00133f37,"haptic_hv",0xed,"aw8692x_play_go",param_2 & 1);
  haptic_hv_i2c_reads(param_1,0x79,local_34,1);
  puVar1 = local_2c;
  if ((param_2 & 1 & local_34[0] < 0x40) == 0) {
    puVar1 = local_30;
  }
  haptic_hv_i2c_writes(param_1,9,puVar1,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_ram_init @ 001193a4 size=80
// signature: undefined aw8692x_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw8692x_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
    usleep_range_state(500,600,2);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_set_bst_peak_cur @ 001193f8 size=244
// signature: undefined aw8692x_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_bst_peak_cur(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5b,local_30,1);
  if (*(char *)(param_1 + 10) == '\x01') {
    _printk(&DAT_001317fd,"haptic_hv",0x69,"aw8692x_set_bst_peak_cur");
    uVar2 = 0x90;
  }
  else {
    if (*(char *)(param_1 + 10) == '\0') {
      uVar2 = 99;
    }
    else {
      uVar2 = 0x6f;
    }
    _printk(&DAT_001337fc,"haptic_hv",uVar2,"aw8692x_set_bst_peak_cur");
    uVar2 = 0x60;
  }
  haptic_hv_i2c_write_bits(param_1,0x72,0xffffff0f,uVar2);
  local_2c[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5b,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_lra_resistance @ 001194f0 size=412
// signature: undefined aw8692x_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_lra_resistance(long param_1)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  byte local_40 [4];
  undefined2 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0;
  local_3c = 0;
  aw8692x_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x18);
  haptic_hv_i2c_reads(param_1,0x4d,local_40,1);
  bVar2 = local_40[0];
  haptic_hv_i2c_reads(param_1,0x4e,local_40,1);
  bVar3 = local_40[0];
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,4);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff0,5);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff3,bVar2 & 0xc);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,bVar3 & 7);
  haptic_hv_i2c_reads(param_1,0x4f,&local_3c,2);
  *(uint *)(param_1 + 0x6c) =
       (((uint)local_3c._1_1_ | ((byte)local_3c & 3) << 8) * 0x9450c) / 0x2800;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_set_pwm @ 00119690 size=132
// signature: undefined aw8692x_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_pwm(undefined8 param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_2 == '\x02') {
    uVar1 = 0x40;
  }
  else if (param_2 == '\x01') {
    uVar1 = 0;
  }
  else {
    if (param_2 != '\0') {
      _printk(&DAT_00132648,"haptic_hv",0x54,"aw8692x_set_pwm");
      return;
    }
    uVar1 = 0x20;
  }
  haptic_hv_i2c_write_bits(param_1,0x46,0xffffff9f,uVar1);
  return;
}



//------------------------------------------------------------
// aw8692x_set_gain @ 00119718 size=88
// signature: undefined aw8692x_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_play_mode @ 00119774 size=760
// signature: undefined aw8692x_play_mode(void)
// callers: []
//------------------------------------------------------------

void aw8692x_play_mode(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0x121,"aw8692x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
    uVar1 = 0x45;
    uVar2 = 0xffffffdf;
    goto LAB_00119a54;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",299,"aw8692x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 1;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    uVar1 = 0;
    break;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x13f,"aw8692x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,1);
    uVar1 = 4;
    break;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x149,"aw8692x_play_mode");
    uVar1 = 8;
    uVar2 = 0xfffffffc;
    *(undefined1 *)(param_1 + 0xb) = 3;
    goto LAB_00119a40;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x151,"aw8692x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 4;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x112,"aw8692x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffff7f,0);
    uVar1 = 0x4c;
    uVar2 = 0xffffffbf;
    uVar3 = 0x40;
    goto LAB_00119a58;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0x135,"aw8692x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 5;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x112,"aw8692x_bst_mode_config");
    uVar1 = 6;
    uVar2 = 0xffffff7f;
LAB_00119a40:
    uVar3 = 0;
    goto LAB_00119a44;
  default:
    _printk(&DAT_001348de,"haptic_hv",0x15b,"aw8692x_play_mode");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar1);
  _printk(&DAT_0013335b,"haptic_hv",0x10c,"aw8692x_bst_mode_config");
  uVar1 = 6;
  uVar2 = 0xffffff7f;
  uVar3 = 0x80;
LAB_00119a44:
  haptic_hv_i2c_write_bits(param_1,uVar1,uVar2,uVar3);
  uVar1 = 0x4c;
  uVar2 = 0xffffffbf;
LAB_00119a54:
  uVar3 = 0;
LAB_00119a58:
  haptic_hv_i2c_write_bits(param_1,uVar1,uVar2,uVar3);
  return;
}



//------------------------------------------------------------
// aw8692x_set_bst_vol @ 00119a70 size=96
// signature: undefined aw8692x_set_bst_vol(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_bst_vol(undefined8 param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (((uint)(param_2 >> 4) & 0xfffffff) < 0x177) {
    uVar2 = 0x28;
  }
  else {
    uVar1 = (uint)param_2;
    if (0x2cac < uVar1) {
      uVar1 = 0x2cad;
    }
    uVar2 = (ulong)(uVar1 * 10 - 35000) / 0x271;
  }
  haptic_hv_i2c_write_bits(param_1,6,0xffffff80,uVar2);
  return;
}



//------------------------------------------------------------
// aw8692x_set_repeat_seq @ 00119ad4 size=120
// signature: undefined aw8692x_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,10,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_auto_bst_enable @ 00119b50 size=52
// signature: undefined aw8692x_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw8692x_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,8,0xffffffef,(ulong)(param_2 != '\0') << 4);
  return;
}



//------------------------------------------------------------
// aw8692x_vbat_mode_config @ 00119b88 size=52
// signature: undefined aw8692x_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8692x_vbat_mode_config(undefined8 param_1,char param_2)

{
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,(ulong)(param_2 == '\x01') << 6);
  return;
}



//------------------------------------------------------------
// aw8692x_set_wav_seq @ 00119bc0 size=88
// signature: undefined aw8692x_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 10,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_set_wav_loop @ 00119c1c size=64
// signature: undefined aw8692x_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0x12,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw8692x_set_rtp_data @ 00119c60 size=40
// signature: undefined aw8692x_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,0x32,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw8692x_protect_config @ 00119c8c size=256
// signature: undefined aw8692x_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw8692x_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x1c3,"aw8692x_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x4a,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",0x1bc,"aw8692x_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x4a,local_40,1);
    haptic_hv_i2c_writes(param_1,0x4b,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_parse_dt @ 00119d90 size=1236
// signature: undefined aw8692x_parse_dt(void)
// callers: []
//------------------------------------------------------------

void aw8692x_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined2 local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_52 = 0;
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_gain_bypass",param_2 + 0x55f,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133997,"haptic_hv",0x53a,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x53d,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_f0_cali_percent",param_2 + 0x529,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136b32,"haptic_hv",0x540,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_cont_drv1_lvl",param_2 + 0x562,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136724,"haptic_hv",0x543,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8692x_cont_lra_vrms",param_2 + 0x584,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137996,"haptic_hv",0x546,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_cont_drv1_time",param_2 + 0x566,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001326c0,"haptic_hv",0x549,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_cont_drv2_time",param_2 + 0x567,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133329,"haptic_hv",0x54c,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_cont_brk_time",param_2 + 0x564,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136b65,"haptic_hv",0x54f,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw8692x_cont_track_margin",param_2 + 0x568,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136b96,"haptic_hv",0x553,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_cont_brk_gain",param_2 + 0x565,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013722b,"haptic_hv",0x556,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_d2s_gain",param_2 + 0x55d,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00132c66,"haptic_hv",0x559,"aw8692x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_duration_time",&local_54,3,0);
  if (iVar1 < 0) {
    _printk(&DAT_001357a5,"haptic_hv",0x55d,"aw8692x_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_54;
    *(undefined1 *)(param_2 + 0x52c) = local_52;
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8692x_trig_config",&local_50,0x18,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133d23,"haptic_hv",0x563,"aw8692x_parse_dt");
  }
  else {
    *(undefined8 *)(param_2 + 0x569) = local_50;
    *(undefined8 *)(param_2 + 0x571) = local_48;
    *(undefined8 *)(param_2 + 0x579) = local_40;
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8692x_bst_vol_default",param_2 + 0x534,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00132f8f,"haptic_hv",0x568,"aw8692x_parse_dt");
  }
  lVar2 = of_find_property(param_3,"aw8692x_is_enabled_track_en",0);
  *(bool *)(param_2 + 0x588) = lVar2 != 0;
  _printk(&DAT_00137abd,"haptic_hv",0x56b,"aw8692x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8692x_is_enabled_auto_bst",0);
  *(bool *)(param_2 + 0x58c) = lVar2 != 0;
  _printk(&DAT_00134902,"haptic_hv",0x56e,"aw8692x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8692x_is_enabled_one_wire",0);
  *(bool *)(param_2 + 0x58e) = lVar2 != 0;
  _printk(&DAT_00133c22,"haptic_hv",0x571,"aw8692x_parse_dt");
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_trig_init @ 0011a268 size=940
// signature: undefined aw8692x_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw8692x_trig_init(long param_1)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  long lVar4;
  bool bVar5;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  byte local_34 [4];
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  _printk(&DAT_0013233b,"haptic_hv",0x4a6,"aw8692x_trig_init");
  if (*(char *)(param_1 + 0x58e) == '\0') {
    cVar3 = *(char *)(param_1 + 0x569);
    *(undefined1 *)(param_1 + 0x6c9) = *(undefined1 *)(param_1 + 0x56b);
    *(undefined1 *)(param_1 + 0x6cb) = *(undefined1 *)(param_1 + 0x56c);
    *(char *)(param_1 + 0x6c7) = cVar3;
    *(char *)(param_1 + 0x6c8) = *(char *)(param_1 + 0x56a);
    uVar2 = (uint)(cVar3 != '\0') << 6;
    if (*(char *)(param_1 + 0x56a) != '\0') {
      uVar2 = (uint)(cVar3 != '\0') << 6 | 0xffffff80;
    }
    *(undefined1 *)(param_1 + 0x6ca) = *(undefined1 *)(param_1 + 0x56d);
    if (*(char *)(param_1 + 0x56f) != '\0') {
      uVar2 = uVar2 | 0x20;
    }
    if (*(char *)(param_1 + 0x570) != '\0') {
      uVar2 = uVar2 | 0x10;
    }
    *(char *)(param_1 + 0x6c5) = *(char *)(param_1 + 0x56f);
    *(char *)(param_1 + 0x6c6) = *(char *)(param_1 + 0x570);
    *(undefined1 *)(param_1 + 0x6cc) = *(undefined1 *)(param_1 + 0x56e);
    haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar2);
    local_34[0] = *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7;
    haptic_hv_i2c_writes(param_1,0x33,local_34,1);
    local_34[0] = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
    haptic_hv_i2c_writes(param_1,0x36,local_34,1);
  }
  else {
    _printk(&DAT_00137af7,"haptic_hv",0x4a8,"aw8692x_trig_init");
    local_38[0] = 0x6c;
    local_3c[0] = 0x75;
    _printk(&DAT_00132e8a,"haptic_hv",0x1e4,"aw8692x_one_wire_init");
    haptic_hv_i2c_writes(param_1,0x3e,local_38,1);
    haptic_hv_i2c_writes(param_1,0x3c,local_3c,1);
    haptic_hv_i2c_write_bits(param_1,0x3a,0xfffffff7,8);
  }
  cVar3 = *(char *)(param_1 + 0x571);
  *(undefined1 *)(param_1 + 0x6d6) = *(undefined1 *)(param_1 + 0x573);
  *(char *)(param_1 + 0x6d4) = cVar3;
  *(undefined1 *)(param_1 + 0x6d9) = *(undefined1 *)(param_1 + 0x576);
  *(char *)(param_1 + 0x6d5) = *(char *)(param_1 + 0x572);
  *(undefined1 *)(param_1 + 0x6d8) = *(undefined1 *)(param_1 + 0x574);
  *(undefined1 *)(param_1 + 0x6d7) = *(undefined1 *)(param_1 + 0x575);
  *(undefined1 *)(param_1 + 0x6e2) = *(undefined1 *)(param_1 + 0x57a);
  *(char *)(param_1 + 0x6d2) = *(char *)(param_1 + 0x577);
  bVar1 = (cVar3 != '\0') << 2;
  if (*(char *)(param_1 + 0x572) != '\0') {
    bVar1 = (cVar3 != '\0') << 2 | 8;
  }
  *(undefined1 *)(param_1 + 0x6e1) = *(undefined1 *)(param_1 + 0x579);
  *(undefined1 *)(param_1 + 0x6e3) = *(undefined1 *)(param_1 + 0x57b);
  if (*(char *)(param_1 + 0x577) != '\0') {
    bVar1 = bVar1 | 2;
  }
  *(undefined1 *)(param_1 + 0x6e5) = *(undefined1 *)(param_1 + 0x57c);
  *(char *)(param_1 + 0x6d3) = *(char *)(param_1 + 0x578);
  *(undefined1 *)(param_1 + 0x6e6) = *(undefined1 *)(param_1 + 0x57e);
  *(undefined1 *)(param_1 + 0x6e4) = *(undefined1 *)(param_1 + 0x57d);
  *(undefined2 *)(param_1 + 0x6df) = *(undefined2 *)(param_1 + 0x57f);
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x578) != '\0');
  local_30[0] = *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x34,local_30,1);
  local_30[0] = *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x37,local_30,1);
  bVar5 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar2 = (uint)bVar5 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar2 = (uint)bVar5 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar2 = uVar2 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar2 = uVar2 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar2);
  local_2c[0] = *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x35,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x38,local_2c,1);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_irq_clear @ 0011a618 size=88
// signature: undefined aw8692x_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw8692x_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_set_ram_addr @ 0011a674 size=100
// signature: undefined aw8692x_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_ram_addr(long param_1)

{
  long lVar1;
  ushort local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_misc_para_init @ 0011a6dc size=704
// signature: undefined aw8692x_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw8692x_misc_para_init(long param_1)

{
  uint uVar1;
  long lVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  ulong local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = (ulong)*(byte *)(*(long *)(param_1 + 0x2c8) + 2);
  haptic_hv_i2c_writes(param_1,0x47,&local_30,1);
  iVar4 = 0x711;
  if (0x707 < *(uint *)(param_1 + 0x530)) {
    iVar4 = 0x7c6;
  }
  uVar1 = iVar4 * *(int *)(param_1 + 0x584);
  uVar3 = 0x7f;
  if (uVar1 >> 0xd < 0x271) {
    uVar3 = (undefined1)(uVar1 / 40000);
  }
  *(undefined1 *)(param_1 + 0x563) = uVar3;
  if (*(int *)(param_1 + 0x534) != 0) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x534);
  }
  haptic_hv_i2c_reads(param_1,7,&local_30,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_30;
  haptic_hv_i2c_reads(param_1,10,&local_30,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_30;
  *(ulong *)(param_1 + 0x11) = local_30;
  haptic_hv_i2c_write_bits(param_1,0x46,0xfffffffe,*(undefined1 *)(param_1 + 0x55f));
  local_34[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5b,local_34,1);
  local_30 = CONCAT71(local_30._1_7_,0xf);
  haptic_hv_i2c_writes(param_1,0x70,&local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x71,0xffffff7f,0x80);
  haptic_hv_i2c_write_bits(param_1,0x74,0xffffff7f,0x80);
  haptic_hv_i2c_write_bits(param_1,0x75,0xffffffef,0);
  local_34[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5b,local_34,1);
  if (*(char *)(param_1 + 0x564) == '\0') {
    _printk(&DAT_0013618a,"haptic_hv",0x5a0,"aw8692x_misc_para_init");
  }
  if (*(char *)(param_1 + 0x565) == '\0') {
    _printk(&DAT_00136ea5,"haptic_hv",0x5a2,"aw8692x_misc_para_init");
  }
  if (*(char *)(param_1 + 0x55d) == '\0') {
    _printk(&DAT_00136555,"haptic_hv",0x5a4,"aw8692x_misc_para_init");
  }
  haptic_hv_i2c_write_bits(param_1,0x1c,0xfffffff0,*(undefined1 *)(param_1 + 0x565));
  haptic_hv_i2c_writes(param_1,0x21,param_1 + 0x564,1);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  local_34[0] = 0x32;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",0x1bc,"aw8692x_protect_config");
  local_38[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x4a,local_38,1);
  haptic_hv_i2c_writes(param_1,0x4b,local_34,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_interrupt_setup @ 0011a9a0 size=176
// signature: undefined aw8692x_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw8692x_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  _printk(&DAT_0013526c,"haptic_hv",0x2c6,"aw8692x_interrupt_setup",local_2c[0]);
  haptic_hv_i2c_write_bits(param_1,0x46,0xffffffe7,8);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff19,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_set_rtp_aei @ 0011aa54 size=48
// signature: undefined aw8692x_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw8692x_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw8692x_upload_lra @ 0011aa88 size=340
// signature: undefined aw8692x_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw8692x_upload_lra(long param_1,int param_2)

{
  long lVar1;
  byte local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_34[0] = 0;
  local_30[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5b,local_30,1);
  if (param_2 == 2) {
    _printk(&DAT_001323a9,"haptic_hv",0x191,"aw8692x_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    local_34[0] = *(byte *)(param_1 + 0x9c);
  }
  else {
    if (param_2 == 1) {
      _printk(&DAT_001378a9,"haptic_hv",0x18d,"aw8692x_upload_lra",*(undefined4 *)(param_1 + 0x90));
    }
    else {
      if (param_2 == 0) {
        _printk(&DAT_00136e0b,"haptic_hv",0x18a,"aw8692x_upload_lra");
        goto LAB_0011ab84;
      }
      _printk(&DAT_00136f7a,"haptic_hv",0x195,"aw8692x_upload_lra");
    }
    local_34[0] = *(byte *)(param_1 + 0x90);
  }
  local_34[0] = local_34[0] & 0x3f;
LAB_0011ab84:
  haptic_hv_i2c_writes(param_1,0x79,local_34,1);
  local_2c[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5b,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_wav_seq @ 0011abe0 size=236
// signature: undefined aw8692x_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,10,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_ram_data @ 0011acd0 size=120
// signature: undefined aw8692x_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_bst_mode_config @ 0011ad4c size=200
// signature: undefined aw8692x_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8692x_bst_mode_config(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    _printk(&DAT_00135b17,"haptic_hv",0x112,"aw8692x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffff7f,0);
  }
  else if (param_2 == '\x01') {
    _printk(&DAT_0013335b,"haptic_hv",0x10c,"aw8692x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffff7f,0x80);
  }
  else {
    _printk(&DAT_0013725c,"haptic_hv",0x118,"aw8692x_bst_mode_config",param_2);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_first_wave_addr @ 0011ae18 size=112
// signature: undefined aw8692x_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_wav_loop @ 0011ae8c size=420
// signature: undefined aw8692x_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw8692x_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0x12,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw8692x_get_reg @ 0011b034 size=288
// signature: undefined aw8692x_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw8692x_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_c8 [128];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_c8[0x78] = 0;
  local_c8[0x79] = 0;
  local_c8[0x7a] = 0;
  local_c8[0x7b] = 0;
  local_c8[0x7c] = 0;
  local_c8[0x68] = 0;
  local_c8[0x69] = 0;
  local_c8[0x6a] = 0;
  local_c8[0x6b] = 0;
  local_c8[0x6c] = 0;
  local_c8[0x6d] = 0;
  local_c8[0x6e] = 0;
  local_c8[0x6f] = 0;
  local_c8[0x70] = 0;
  local_c8[0x71] = 0;
  local_c8[0x72] = 0;
  local_c8[0x73] = 0;
  local_c8[0x74] = 0;
  local_c8[0x75] = 0;
  local_c8[0x76] = 0;
  local_c8[0x77] = 0;
  local_c8[0x58] = 0;
  local_c8[0x59] = 0;
  local_c8[0x5a] = 0;
  local_c8[0x5b] = 0;
  local_c8[0x5c] = 0;
  local_c8[0x5d] = 0;
  local_c8[0x5e] = 0;
  local_c8[0x5f] = 0;
  local_c8[0x60] = 0;
  local_c8[0x61] = 0;
  local_c8[0x62] = 0;
  local_c8[99] = 0;
  local_c8[100] = 0;
  local_c8[0x65] = 0;
  local_c8[0x66] = 0;
  local_c8[0x67] = 0;
  local_c8[0x48] = 0;
  local_c8[0x49] = 0;
  local_c8[0x4a] = 0;
  local_c8[0x4b] = 0;
  local_c8[0x4c] = 0;
  local_c8[0x4d] = 0;
  local_c8[0x4e] = 0;
  local_c8[0x4f] = 0;
  local_c8[0x50] = 0;
  local_c8[0x51] = 0;
  local_c8[0x52] = 0;
  local_c8[0x53] = 0;
  local_c8[0x54] = 0;
  local_c8[0x55] = 0;
  local_c8[0x56] = 0;
  local_c8[0x57] = 0;
  local_c8[0x38] = 0;
  local_c8[0x39] = 0;
  local_c8[0x3a] = 0;
  local_c8[0x3b] = 0;
  local_c8[0x3c] = 0;
  local_c8[0x3d] = 0;
  local_c8[0x3e] = 0;
  local_c8[0x3f] = 0;
  local_c8[0x40] = 0;
  local_c8[0x41] = 0;
  local_c8[0x42] = 0;
  local_c8[0x43] = 0;
  local_c8[0x44] = 0;
  local_c8[0x45] = 0;
  local_c8[0x46] = 0;
  local_c8[0x47] = 0;
  local_c8[0x28] = 0;
  local_c8[0x29] = 0;
  local_c8[0x2a] = 0;
  local_c8[0x2b] = 0;
  local_c8[0x2c] = 0;
  local_c8[0x2d] = 0;
  local_c8[0x2e] = 0;
  local_c8[0x2f] = 0;
  local_c8[0x30] = 0;
  local_c8[0x31] = 0;
  local_c8[0x32] = 0;
  local_c8[0x33] = 0;
  local_c8[0x34] = 0;
  local_c8[0x35] = 0;
  local_c8[0x36] = 0;
  local_c8[0x37] = 0;
  local_c8[0x18] = 0;
  local_c8[0x19] = 0;
  local_c8[0x1a] = 0;
  local_c8[0x1b] = 0;
  local_c8[0x1c] = 0;
  local_c8[0x1d] = 0;
  local_c8[0x1e] = 0;
  local_c8[0x1f] = 0;
  local_c8[0x20] = 0;
  local_c8[0x21] = 0;
  local_c8[0x22] = 0;
  local_c8[0x23] = 0;
  local_c8[0x24] = 0;
  local_c8[0x25] = 0;
  local_c8[0x26] = 0;
  local_c8[0x27] = 0;
  local_c8[8] = 0;
  local_c8[9] = 0;
  local_c8[10] = 0;
  local_c8[0xb] = 0;
  local_c8[0xc] = 0;
  local_c8[0xd] = 0;
  local_c8[0xe] = 0;
  local_c8[0xf] = 0;
  local_c8[0x10] = 0;
  local_c8[0x11] = 0;
  local_c8[0x12] = 0;
  local_c8[0x13] = 0;
  local_c8[0x14] = 0;
  local_c8[0x15] = 0;
  local_c8[0x16] = 0;
  local_c8[0x17] = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[6] = 0;
  local_c8[7] = 0;
  haptic_hv_i2c_reads(param_1,0,local_c8,0x32);
  haptic_hv_i2c_reads(param_1,0x33,local_c8 + 0x33,0xf);
  haptic_hv_i2c_reads(param_1,0x43,local_c8 + 0x43,0x3a);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 0x32) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_c8[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x7d);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw8692x_get_prctmode @ 0011b158 size=96
// signature: undefined aw8692x_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw8692x_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x4a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw8692x_get_trim_lra @ 0011b1bc size=96
// signature: undefined aw8692x_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

byte aw8692x_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x79,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0x3f;
}



//------------------------------------------------------------
// aw8692x_get_glb_state @ 0011b220 size=92
// signature: undefined aw8692x_get_glb_state(void)
// callers: []
//------------------------------------------------------------

void aw8692x_get_glb_state(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw8692x_get_osc_status @ 0011b280 size=96
// signature: undefined aw8692x_get_osc_status(void)
// callers: []
//------------------------------------------------------------

byte aw8692x_get_osc_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw8692x_rtp_get_fifo_afs @ 0011b2e4 size=96
// signature: undefined aw8692x_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw8692x_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw8692x_rtp_get_fifo_aes @ 0011b348 size=96
// signature: undefined aw8692x_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw8692x_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw8692x_get_theory_time @ 0011b3ac size=216
// signature: undefined aw8692x_get_theory_time(void)
// callers: []
//------------------------------------------------------------

uint aw8692x_get_theory_time(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x46,local_2c,1);
  if ((local_2c[0] & 0x60) == 0x40) {
    uVar2 = 0xc;
  }
  else if ((local_2c[0] & 0x60) == 0x20) {
    uVar2 = 0x30;
  }
  else {
    if ((local_2c[0] & 0x60) != 0) {
      uVar3 = 0;
      goto LAB_0011b42c;
    }
    uVar2 = 0x18;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    uVar3 = (uint)(*(int *)(param_1 + 0x7c) * 1000) / uVar2;
  }
LAB_0011b42c:
  _printk(&DAT_0013791e,"haptic_hv",0x52c,"aw8692x_get_theory_time",*(undefined8 *)(param_1 + 0xa0),
          uVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// cont_drv_lvl_show @ 0011b488 size=64
// signature: undefined cont_drv_lvl_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_lvl_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_lvl = 0x%02X, cont_drv2_lvl = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4ba),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bb));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_store @ 0011b4cc size=252
// signature: undefined cont_drv_lvl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_lvl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined2 local_44;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_40[1] = 0;
  local_44 = 0;
  iVar1 = sscanf(param_3,"%x %x",local_40,(uint *)((ulong)local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x4ba) = (char)local_40[0];
    *(char *)(lVar2 + 0x4bb) = (char)local_40[1];
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_reads(lVar2 + -0xa8,0x1d,&local_44,1);
    local_44 = CONCAT11(*(undefined1 *)(lVar2 + 0x4bb),
                        *(byte *)(lVar2 + 0x4ba) | (byte)local_44 & 0x80);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1d,&local_44,2);
    mutex_unlock(lVar2 + 0x2a8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_time_show @ 0011b5cc size=64
// signature: undefined cont_drv_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4be),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bf));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_time_store @ 0011b610 size=212
// signature: undefined cont_drv_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_44;
  undefined1 local_43;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_40,(uint *)((ulong)&local_40 | 4));
  if (iVar1 == 2) {
    *(undefined1 *)(lVar2 + 0x4be) = (undefined1)local_40;
    *(char *)(lVar2 + 0x4bf) = (char)((ulong)local_40 >> 0x20);
    local_44 = (undefined1)local_40;
    local_43 = *(undefined1 *)(lVar2 + 0x4bf);
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1f,&local_44,2);
    mutex_unlock(lVar2 + 0x2a8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_brk_time_show @ 0011b6e8 size=60
// signature: undefined cont_brk_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_brk_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_brk_time_store @ 0011b728 size=128
// signature: undefined cont_brk_time_store(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = kstrtou8(param_3,0,lVar2 + 0x4bc);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x21,lVar2 + 0x4bc,1);
    mutex_unlock(lVar2 + 0x2a8);
  }
  return param_4;
}



//------------------------------------------------------------
// trig_show @ 0011b7ac size=292
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x61f),(uint)*(byte *)(lVar2 + 0x620),
                   (uint)*(byte *)(lVar2 + 0x621),(uint)*(byte *)(lVar2 + 0x623),
                   (uint)*(byte *)(lVar2 + 0x622),(uint)*(byte *)(lVar2 + 0x624),
                   (uint)*(byte *)(lVar2 + 0x61d),(uint)*(byte *)(lVar2 + 0x61e));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x62c),(uint)*(byte *)(lVar2 + 0x62d),
                   (uint)*(byte *)(lVar2 + 0x62e),(uint)*(byte *)(lVar2 + 0x630),
                   (uint)*(byte *)(lVar2 + 0x62f),(uint)*(byte *)(lVar2 + 0x631),
                   (uint)*(byte *)(lVar2 + 0x62a),(uint)*(byte *)(lVar2 + 0x62b));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x639),(uint)*(byte *)(lVar2 + 0x63a),
                   (uint)*(byte *)(lVar2 + 0x63b),(uint)*(byte *)(lVar2 + 0x63d),
                   (uint)*(byte *)(lVar2 + 0x63c),(uint)*(byte *)(lVar2 + 0x63e),
                   (uint)*(byte *)(lVar2 + 0x637),(uint)*(byte *)(lVar2 + 0x638));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 0011b8d4 size=776
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar5 = sscanf(param_3,"%u %u %u %u %u %u %u %u %u",(uint *)&local_60,
                 (uint *)((ulong)&local_60 | 4),(uint *)&local_58,(uint *)((long)&local_58 + 4),
                 (uint *)&local_50,(uint *)((long)&local_50 + 4),(uint *)&local_48,
                 (uint *)((long)&local_48 + 4),local_40);
  if (iVar5 == 9) {
    _printk(&DAT_001359f8,"haptic_hv",0x63c,"trig_store",local_60 & 0xffffffff,local_60._4_4_,
            local_58 & 0xffffffff,local_58._4_4_,local_50 & 0xffffffff,local_50 >> 0x20,
            local_48 & 0xffffffff,local_48._4_4_,local_40[0]);
    uVar3 = local_60;
    if ((uint)local_60 - 4 < 0xfffffffd) {
      _printk(&DAT_001369d0,"haptic_hv",0x63e,"trig_store");
    }
    else {
      uVar2 = (uint)local_60 - 1;
      if ((uVar2 == 0) && (*(char *)(lVar6 + 0x4e6) != '\0')) {
        _printk(&DAT_00136135,"haptic_hv",0x642,"trig_store");
      }
      else if (*(char *)(lVar6 + -0xa2) == '\0') {
        _printk(&DAT_001325b9,"haptic_hv",0x646,"trig_store");
      }
      else {
        if (((uint)local_50 <= *(byte *)(lVar6 + 0x47c)) &&
           ((uint)local_48 <= *(byte *)(lVar6 + 0x47c))) {
          lVar1 = lVar6 + 0x618;
          local_60 = CONCAT44(local_60._4_4_,uVar2);
          *(char *)(lVar1 + (ulong)uVar2 * 0xd + 7) = (char)(uVar3 >> 0x20);
          if (uVar2 < 3) {
            *(char *)(lVar1 + (ulong)uVar2 * 0xd + 8) = (char)local_58;
            if (uVar2 < 3) {
              *(char *)(lVar1 + (ulong)uVar2 * 0xd + 9) = (char)(local_58 >> 0x20);
              if (uVar2 < 3) {
                *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xb) = (char)local_50;
                if (uVar2 < 3) {
                  *(char *)(lVar1 + (ulong)uVar2 * 0xd + 10) = (char)(local_50 >> 0x20);
                  if (uVar2 < 3) {
                    *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xc) = (char)local_48;
                    if (uVar2 < 3) {
                      *(char *)(lVar1 + (ulong)uVar2 * 0xd + 5) = (char)(local_48 >> 0x20);
                      if (uVar2 < 3) {
                        lVar7 = lVar6 + -0xa8;
                        *(char *)(lVar1 + (ulong)uVar2 * 0xd + 6) = (char)local_40[0];
                        mutex_lock(lVar6 + 0x2a8);
                        if ((uint)local_60 == 2) {
                          aw8692x_trig3_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 1) {
                          aw8692x_trig2_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 0) {
                          aw8692x_trig1_param_config(lVar7);
                        }
                        mutex_unlock(lVar6 + 0x2a8);
                        goto LAB_0011b958;
                      }
                    }
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11bbdc);
          (*pcVar4)();
        }
        _printk(&DAT_00134564,"haptic_hv",0x64a,"trig_store");
      }
    }
  }
LAB_0011b958:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8692x_trig1_param_config @ 0011bbdc size=248
// signature: undefined aw8692x_trig1_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8692x_trig1_param_config(long param_1)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6c7) != '\0';
  uVar1 = (uint)bVar3 << 6;
  if (*(char *)(param_1 + 0x6c8) != '\0') {
    uVar1 = (uint)bVar3 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6c5) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6c6) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
  local_2c[0] = *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x33,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x36,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_trig2_param_config @ 0011bcd4 size=248
// signature: undefined aw8692x_trig2_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8692x_trig2_param_config(long param_1)

{
  byte bVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6d4) != '\0';
  bVar1 = bVar3 << 2;
  if (*(char *)(param_1 + 0x6d5) != '\0') {
    bVar1 = bVar3 << 2 | 8;
  }
  if (*(char *)(param_1 + 0x6d2) != '\0') {
    bVar1 = bVar1 | 2;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x6d3) != '\0');
  local_2c[0] = *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x34,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x37,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8692x_trig3_param_config @ 0011bdcc size=248
// signature: undefined aw8692x_trig3_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8692x_trig3_param_config(long param_1)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar1 = (uint)bVar3 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar1 = (uint)bVar3 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  local_2c[0] = *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x35,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x38,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_f0 @ 0011bec8 size=1076
// signature: undefined aw8693x_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_get_f0(long param_1)

{
  uint uVar1;
  long lVar2;
  ushort uVar3;
  byte bVar4;
  bool bVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  byte local_44 [4];
  undefined1 local_40;
  undefined2 local_3f;
  undefined2 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_44[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw8693x_stop();
  _printk(&DAT_00132e8a,"haptic_hv",0x206,"aw8693x_vbat_ref_config");
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  _printk(&DAT_001331a6,"haptic_hv",0x25d,"aw8693x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x1f7,"aw8693x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_reads(param_1,8,local_44,1);
  bVar4 = local_44[0];
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  local_40 = *(undefined1 *)(param_1 + 0x563);
  local_3f = *(undefined2 *)(param_1 + 0x566);
  haptic_hv_i2c_writes(param_1,0x1e,&local_40,3);
  if (*(char *)(param_1 + 0x568) == '\0') {
    _printk(&DAT_001366d5,"haptic_hv",0x49f,"aw8693x_get_f0");
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  else {
    haptic_hv_i2c_writes(param_1,0x22,param_1 + 0x568,1);
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  if (uVar1 == 0) {
    uVar9 = 0xffffffde;
  }
  else {
    local_3c._1_1_ = (undefined1)(local_3c >> 8);
    uVar8 = 0;
    if (uVar1 != 0) {
      uVar8 = 240000 / uVar1;
    }
    iVar7 = (uVar8 - ((uint)*(byte *)(param_1 + 0x565) + (uint)*(byte *)(param_1 + 0x568))) + -8;
    if (0xfe < iVar7) {
      iVar7 = 0xff;
    }
    if (iVar7 < 1) {
      iVar7 = 0;
    }
    if (0xfe < uVar8) {
      uVar8 = 0xff;
    }
    uVar3 = (ushort)local_3f >> 8;
    local_3f = CONCAT11((char)uVar3,(char)iVar7);
    local_40 = (undefined1)uVar8;
    haptic_hv_i2c_writes(param_1,0x19,&local_40,2);
    _printk(&DAT_00133f37,"haptic_hv",0x1d0,"aw8693x_play_go",1);
    local_3c = CONCAT11(local_3c._1_1_,1);
    haptic_hv_i2c_writes(param_1,9,&local_3c,1);
    usleep_range_state(20000,0x5014,2);
    iVar7 = -100;
    do {
      local_3c = local_3c & 0xff00;
      haptic_hv_i2c_reads(param_1,0x3f,&local_3c,1);
      if ((char)local_3c == '\0') {
        puVar6 = &DAT_00136940;
        uVar9 = 0x1e3;
        goto LAB_0011c210;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar5 = iVar7 != -1;
      iVar7 = iVar7 + 1;
    } while (bVar5);
    puVar6 = &DAT_00137ca1;
    uVar9 = 0x1e8;
LAB_0011c210:
    _printk(puVar6,"haptic_hv",uVar9,"aw8693x_wait_enter_standby");
    local_3c = 0;
    haptic_hv_i2c_reads(param_1,0x25,&local_3c,2);
    uVar1 = (uint)(local_3c >> 8) | (local_3c & 0xff00ff) << 8;
    if (uVar1 == 0) {
      *(undefined4 *)(param_1 + 100) = 0;
      _printk(&DAT_00137bb0,"haptic_hv",0x464,"aw8693x_read_f0");
      uVar9 = 0xffffffde;
    }
    else {
      uVar8 = 0;
      if (uVar1 != 0) {
        uVar8 = 0x3a9800 / uVar1;
      }
      *(uint *)(param_1 + 100) = uVar8;
      _printk(&DAT_00137ea5,"haptic_hv",0x468,"aw8693x_read_f0");
      uVar9 = 0;
    }
    haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,bVar4 & 4);
    _printk(&DAT_00132e8a,"haptic_hv",0x206,"aw8693x_vbat_ref_config");
    haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x30);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// aw8693x_ram_get_f0 @ 0011c300 size=1060
// signature: undefined aw8693x_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_ram_get_f0(long param_1)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  byte local_50 [4];
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  char local_40 [4];
  ushort local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_50[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    puVar5 = &DAT_001325b9;
    uVar6 = 0x4cc;
  }
  else {
    if (4 < *(byte *)(param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
      aw8693x_stop(param_1);
      haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
      _printk(&DAT_00136db2,"haptic_hv",0x237,"aw8693x_play_mode");
      *(undefined1 *)(param_1 + 0xb) = 1;
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,0);
      _printk(&DAT_0013335b,"haptic_hv",0x1f1,"aw8693x_bst_mode_config");
      haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0x20);
      haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0x20);
      haptic_hv_i2c_reads(param_1,8,local_50,1);
      bVar3 = local_50[0];
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
      _printk(&DAT_00137ecf,"haptic_hv",0x169,"aw8693x_set_bst_vol",8000,0xd);
      haptic_hv_i2c_write_bits(param_1,6,0xffffffe0,0xd);
      local_4c[0] = 5;
      haptic_hv_i2c_writes(param_1,10,local_4c,1);
      local_48[0] = 0;
      haptic_hv_i2c_writes(param_1,0xb,local_48,1);
      haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0x20);
      _printk(&DAT_00133f37,"haptic_hv",0x1d0,"aw8693x_play_go",1);
      local_44[0] = 1;
      haptic_hv_i2c_writes(param_1,9,local_44,1);
      usleep_range_state(20000,0x5014,2);
      iVar9 = -100;
      do {
        local_40[0] = '\0';
        haptic_hv_i2c_reads(param_1,0x3f,local_40,1);
        if (local_40[0] == '\0') {
          puVar5 = &DAT_00136940;
          uVar6 = 0x1e3;
          goto LAB_0011c5c4;
        }
        usleep_range_state(2000,0x9c4,2);
        bVar4 = iVar9 != -1;
        iVar9 = iVar9 + 1;
      } while (bVar4);
      puVar5 = &DAT_00137ca1;
      uVar6 = 0x1e8;
LAB_0011c5c4:
      _printk(puVar5,"haptic_hv",uVar6,"aw8693x_wait_enter_standby");
      local_3c[0] = 0;
      haptic_hv_i2c_reads(param_1,0x25,local_3c,2);
      uVar8 = (uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8;
      if (uVar8 == 0) {
        *(undefined4 *)(param_1 + 100) = 0;
        _printk(&DAT_00137bb0,"haptic_hv",0x464,"aw8693x_read_f0");
        uVar6 = 0xffffffde;
      }
      else {
        uVar1 = 0;
        if (uVar8 != 0) {
          uVar1 = 0x3a9800 / uVar8;
        }
        *(uint *)(param_1 + 100) = uVar1;
        _printk(&DAT_00137ea5,"haptic_hv",0x468,"aw8693x_read_f0");
        uVar6 = 0;
      }
      uVar8 = *(uint *)(param_1 + 0x38);
      if (uVar8 < 0x1771) {
        uVar8 = 6000;
      }
      if (10999 < uVar8) {
        uVar8 = 11000;
      }
      uVar1 = (uVar8 - 6000 >> 1 & 0x7fff) / 0x7d + 5;
      _printk(&DAT_00137ecf,"haptic_hv",0x169,"aw8693x_set_bst_vol",uVar8,uVar1 & 0xff);
      haptic_hv_i2c_write_bits(param_1,6,0xffffffe0,uVar1);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffffdf,0);
      if ((bVar3 >> 2 & 1) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 4;
      }
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar7);
      goto LAB_0011c6f0;
    }
    puVar5 = &DAT_00132b34;
    uVar6 = 0x4d0;
  }
  _printk(puVar5,"haptic_hv",uVar6,"aw8693x_ram_get_f0");
  uVar6 = 0xffffffde;
LAB_0011c6f0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// aw8693x_creat_node @ 0011c728 size=100
// signature: undefined aw8693x_creat_node(void)
// callers: []
//------------------------------------------------------------

int aw8693x_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw8693x_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_001339d7,"haptic_hv",0x7f2,"aw8693x_creat_node");
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw8693x_offset_cali @ 0011c790 size=432
// signature: undefined aw8693x_offset_cali(void)
// callers: []
//------------------------------------------------------------

void aw8693x_offset_cali(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined2 local_2c;
  undefined1 local_2a;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2a = 0;
  local_2c = 0;
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_2c,2);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  if ((ulong)(long)*(char *)(param_1 + 0x55d) < 8) {
    iVar1 = 0;
    if (*(int *)(&DAT_001380a0 + (long)*(char *)(param_1 + 0x55d) * 4) != 0) {
      iVar1 = (int)(((uint)local_2c._1_1_ | ((byte)local_2c & 3) << 8) * 0x988 + -0x131000) /
              *(int *)(&DAT_001380a0 + (long)*(char *)(param_1 + 0x55d) * 4);
    }
    _printk(&DAT_00135670,"haptic_hv",0x5bc,"aw8693x_offset_cali",iVar1);
    if (0xffffffe0 < iVar1 - 0x10U) {
      uVar3 = 0;
      goto LAB_0011c8f4;
    }
    puVar4 = &DAT_00137a8c;
    uVar3 = 0x5be;
  }
  else {
    puVar4 = &DAT_00135cd6;
    uVar3 = 0x5b7;
  }
  _printk(puVar4,"haptic_hv",uVar3,"aw8693x_offset_cali");
  uVar3 = 0xffffffde;
LAB_0011c8f4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_irq_state @ 0011c944 size=440
// signature: undefined aw8693x_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  if ((char)local_1c[0] < '\0') {
    _printk(&DAT_00131b4f,"haptic_hv",0x432,"aw8693x_get_irq_state");
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  if ((local_1c[0] >> 6 & 1) != 0) {
    _printk(&DAT_001373ce,"haptic_hv",0x437,"aw8693x_get_irq_state");
    uVar2 = 4;
  }
  if ((local_1c[0] >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x43c,"aw8693x_get_irq_state");
    uVar2 = 5;
  }
  if ((local_1c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x441,"aw8693x_get_irq_state");
    uVar2 = 6;
  }
  if ((local_1c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x446,"aw8693x_get_irq_state");
    uVar2 = 7;
  }
  if ((local_1c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",1099,"aw8693x_get_irq_state");
    uVar2 = 10;
  }
  if ((local_1c[0] >> 3 & 1) != 0) {
    _printk(&DAT_00131f9b,"haptic_hv",0x450,"aw8693x_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_1c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_check_qualify @ 0011cb00 size=172
// signature: undefined aw8693x_check_qualify(void)
// callers: []
//------------------------------------------------------------

void aw8693x_check_qualify(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,100,local_1c,1);
  if (local_1c[0] < '\0') {
    _printk(&DAT_00134387,"haptic_hv",0x136,"aw8693x_check_qualify");
    uVar2 = 0;
  }
  else {
    _printk(&DAT_00132ca5,"haptic_hv",0x133,"aw8693x_check_qualify");
    uVar2 = 0xffffffde;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_judge_rtp_going @ 0011cbb0 size=144
// signature: undefined aw8693x_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw8693x_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  bVar2 = local_1c[0] == '\b';
  if (bVar2) {
    _printk(&DAT_0013728f,"haptic_hv",0x3d4,"aw8693x_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_container_update @ 0011cc44 size=884
// signature: undefined aw8693x_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_container_update(long param_1,int *param_2)

{
  ushort uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte local_460;
  undefined1 local_45f;
  byte local_45e;
  ushort local_45c [2];
  char local_458 [1024];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  memset(local_458,0,0x400);
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  aw8693x_stop(param_1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  uVar1 = *(ushort *)((long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4);
  *(uint *)(param_1 + 0x520) = (uint)(uVar1 >> 8) | (uVar1 & 0xff00ff) << 8;
  _printk(&DAT_00136e85,"haptic_hv",0x602,"aw8693x_container_update");
  uVar7 = *(uint *)(param_1 + 0x520);
  iVar5 = uVar7 - (uVar7 >> 2);
  local_460 = (byte)(uVar7 >> 5) & 0xf0 | (byte)((uint)iVar5 >> 8) & 0xf;
  local_45e = (byte)iVar5;
  local_45f = (undefined1)(uVar7 >> 1);
  haptic_hv_i2c_writes(param_1,0x2f,&local_460,3);
  haptic_hv_i2c_reads(param_1,0x2f,&local_460,3);
  _printk(&DAT_001344e9,"haptic_hv",0x610,"aw8693x_container_update",
          CONCAT11(local_460 >> 4,local_45f));
  _printk(&DAT_001351c2,"haptic_hv",0x613,"aw8693x_container_update",
          (uint)local_45e | (local_460 & 0xf) << 8);
  uVar7 = *(uint *)(param_1 + 0x520);
  local_45c[0] = (ushort)(uVar7 >> 8) & 0xff | (ushort)((uVar7 & 0xff00ff) << 8);
  haptic_hv_i2c_write_bits(param_1,0x2d,0xffffffe0,uVar7 >> 8);
  haptic_hv_i2c_writes(param_1,0x2e,(ulong)local_45c | 1,1);
  local_45c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_45c,2);
  uVar7 = (uint)*(byte *)(param_1 + 0x526);
  iVar5 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar5) {
    do {
      iVar8 = iVar5 - uVar7;
      if (0x7ff < iVar8) {
        iVar8 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar7 + 4,iVar8);
      iVar5 = *param_2;
      uVar7 = iVar8 + uVar7;
    } while ((int)uVar7 < iVar5);
  }
  local_45c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_45c,2);
  uVar7 = (uint)*(byte *)(param_1 + 0x526);
  iVar5 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar5) {
    do {
      uVar9 = iVar5 - uVar7;
      if (0x3ff < (int)uVar9) {
        uVar9 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,local_458,uVar9);
      if (uVar9 != 0) {
        uVar4 = 0;
        do {
          if (0x3ff < uVar4) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x11cfb4);
            (*pcVar3)();
          }
          if (local_458[(int)uVar4] !=
              *(char *)((long)param_2 + (long)(int)uVar4 + (long)(int)uVar7 + 4)) {
            _printk(&DAT_001373f1,"haptic_hv",0x5de,"aw8693x_check_ram_data");
            _printk(&DAT_001351ee,"haptic_hv",0x632,"aw8693x_container_update");
            uVar6 = 0xffffffde;
            goto LAB_0011cf5c;
          }
          uVar4 = uVar4 + 1;
        } while (uVar9 != uVar4);
      }
      iVar5 = *param_2;
      uVar7 = uVar9 + uVar7;
    } while ((int)uVar7 < iVar5);
  }
  _printk(&DAT_00132afb,"haptic_hv",0x634,"aw8693x_container_update");
  uVar6 = 0;
LAB_0011cf5c:
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  mutex_unlock(param_1 + 0x350);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// aw8693x_stop @ 0011cfbc size=452
// signature: undefined aw8693x_stop(void)
// callers: [aw8693x_ram_get_f0, aw8693x_container_update, aw8693x_get_f0, aw8693x_get_vbat, aw8693x_get_lra_resistance]
//------------------------------------------------------------

void aw8693x_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x27f,"aw8693x_stop");
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_30[0] = 1;
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,3);
  haptic_hv_i2c_writes(param_1,9,local_30,1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  iVar3 = -100;
  do {
    local_2c[0] = '\0';
    haptic_hv_i2c_reads(param_1,0x3f,local_2c,1);
    if (local_2c[0] == '\0') {
      _printk(&DAT_00136940,"haptic_hv",0x1e3,"aw8693x_wait_enter_standby");
      goto LAB_0011d154;
    }
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar3 != -1;
    iVar3 = iVar3 + 1;
  } while (bVar2);
  _printk(&DAT_00137ca1,"haptic_hv",0x1e8,"aw8693x_wait_enter_standby");
  _printk(&DAT_00135cf9,"haptic_hv",0x28a,"aw8693x_stop");
  _printk(&DAT_00134895,"haptic_hv",0x22d,"aw8693x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 0;
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0);
LAB_0011d154:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_vbat @ 0011d184 size=436
// signature: undefined aw8693x_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_vbat(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined2 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  aw8693x_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_2c,2);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  uVar1 = (uint)local_2c._1_1_ | ((byte)local_2c & 3) << 8;
  uVar2 = uVar1 * 0x17d4;
  uVar4 = (ulong)uVar2 / 0x3ff;
  *(uint *)(param_1 + 0x70) = uVar2 / 0x3ff;
  if (0x46426a < uVar2) {
    *(undefined4 *)(param_1 + 0x70) = 0x1194;
    _printk(&DAT_001328b9,"haptic_hv",0x585,"aw8693x_get_vbat",0x1194);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  if ((uint)uVar4 < 3000) {
    *(undefined4 *)(param_1 + 0x70) = 3000;
    _printk(&DAT_00135218,"haptic_hv",0x589,"aw8693x_get_vbat",3000);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  _printk(&DAT_00135e49,"haptic_hv",0x58b,"aw8693x_get_vbat",uVar4,uVar1);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_cont_config @ 0011d33c size=392
// signature: undefined aw8693x_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw8693x_cont_config(long param_1)

{
  long lVar1;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0xff;
  _printk(&DAT_001331a6,"haptic_hv",0x25d,"aw8693x_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x1f7,"aw8693x_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,0x40);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  haptic_hv_i2c_writes(param_1,0x1e,param_1 + 0x563,1);
  haptic_hv_i2c_writes(param_1,0x20,local_40,1);
  _printk(&DAT_00133f37,"haptic_hv",0x1d0,"aw8693x_play_go",1);
  local_3c[0] = 1;
  haptic_hv_i2c_writes(param_1,9,local_3c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_play_go @ 0011d4c8 size=152
// signature: undefined aw8693x_play_go(void)
// callers: []
//------------------------------------------------------------

void aw8693x_play_go(undefined8 param_1,uint param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar2 = 1;
  if ((param_2 & 1) == 0) {
    uVar2 = 2;
  }
  _printk(&DAT_00133f37,"haptic_hv",0x1d0,"aw8693x_play_go",param_2 & 1);
  local_2c[0] = uVar2;
  haptic_hv_i2c_writes(param_1,9,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_ram_init @ 0011d564 size=80
// signature: undefined aw8693x_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw8693x_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
    usleep_range_state(500,600,2);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_set_bst_peak_cur @ 0011d5b8 size=4
// signature: undefined aw8693x_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_bst_peak_cur(void)

{
  return;
}



//------------------------------------------------------------
// aw8693x_get_lra_resistance @ 0011d5c0 size=412
// signature: undefined aw8693x_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_lra_resistance(long param_1)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  byte local_40 [4];
  undefined2 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0;
  local_3c = 0;
  aw8693x_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x18);
  haptic_hv_i2c_reads(param_1,0x4d,local_40,1);
  bVar2 = local_40[0];
  haptic_hv_i2c_reads(param_1,0x4e,local_40,1);
  bVar3 = local_40[0];
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,4);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff0,5);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff3,bVar2 & 0xc);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,bVar3 & 7);
  haptic_hv_i2c_reads(param_1,0x4f,&local_3c,2);
  *(uint *)(param_1 + 0x6c) = (((uint)local_3c._1_1_ | ((byte)local_3c & 3) << 8) * 610000) / 0x27f6
  ;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_set_pwm @ 0011d760 size=164
// signature: undefined aw8693x_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_pwm(undefined8 param_1,undefined1 param_2)

{
  undefined8 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = 0x20;
    break;
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 0x40;
    break;
  case 3:
    uVar1 = 0x60;
    break;
  default:
    _printk(&DAT_00132ff4,"haptic_hv",0x153,"aw8693x_set_pwm");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,0x46,0xffffff9f,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693x_set_gain @ 0011d808 size=88
// signature: undefined aw8693x_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_play_mode @ 0011d864 size=692
// signature: undefined aw8693x_play_mode(void)
// callers: []
//------------------------------------------------------------

void aw8693x_play_mode(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0x22d,"aw8693x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
    uVar2 = 0x45;
    uVar1 = 0xffffffdf;
    goto LAB_0011da2c;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",0x237,"aw8693x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 1;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    uVar2 = 0;
    break;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x24b,"aw8693x_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,1);
    uVar2 = 4;
    break;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x255,"aw8693x_play_mode");
    uVar2 = 8;
    uVar1 = 0xfffffffc;
    uVar3 = 0;
    *(undefined1 *)(param_1 + 0xb) = 3;
    goto LAB_0011da1c;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x25d,"aw8693x_play_mode");
    uVar4 = 4;
    uVar2 = 2;
    goto LAB_0011daa8;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0x241,"aw8693x_play_mode");
    uVar4 = 5;
    uVar2 = 0;
LAB_0011daa8:
    *(undefined1 *)(param_1 + 0xb) = uVar4;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,uVar2);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x1f7,"aw8693x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
    uVar2 = 0x4c;
    uVar1 = 0xffffffbf;
    uVar3 = 0x40;
    goto LAB_0011db04;
  default:
    _printk(&DAT_001348de,"haptic_hv",0x267,"aw8693x_play_mode");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar2);
  _printk(&DAT_0013335b,"haptic_hv",0x1f1,"aw8693x_bst_mode_config");
  uVar2 = 6;
  uVar1 = 0xffffffdf;
  uVar3 = 0x20;
LAB_0011da1c:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar1,uVar3);
  uVar2 = 0x4c;
  uVar1 = 0xffffffbf;
LAB_0011da2c:
  uVar3 = 0;
LAB_0011db04:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar1,uVar3);
  return;
}



//------------------------------------------------------------
// aw8693x_set_bst_vol @ 0011db1c size=144
// signature: undefined aw8693x_set_bst_vol(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_bst_vol(undefined8 param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < 0x1771) {
    param_2 = 6000;
  }
  if (10999 < param_2) {
    param_2 = 11000;
  }
  uVar1 = (param_2 - 6000 >> 1 & 0x7fff) / 0x7d + 5;
  _printk(&DAT_00137ecf,"haptic_hv",0x169,"aw8693x_set_bst_vol",param_2,uVar1 & 0xff);
  haptic_hv_i2c_write_bits(param_1,6,0xffffffe0,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693x_set_repeat_seq @ 0011dbb0 size=120
// signature: undefined aw8693x_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,10,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_auto_bst_enable @ 0011dc2c size=52
// signature: undefined aw8693x_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw8693x_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,8,0xffffffef,(ulong)(param_2 != '\0') << 4);
  return;
}



//------------------------------------------------------------
// aw8693x_vbat_mode_config @ 0011dc64 size=52
// signature: undefined aw8693x_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8693x_vbat_mode_config(undefined8 param_1,char param_2)

{
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,(ulong)(param_2 == '\x01') << 6);
  return;
}



//------------------------------------------------------------
// aw8693x_set_wav_seq @ 0011dc9c size=88
// signature: undefined aw8693x_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 10,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_set_wav_loop @ 0011dcf8 size=64
// signature: undefined aw8693x_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0x12,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw8693x_set_rtp_data @ 0011dd3c size=40
// signature: undefined aw8693x_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,0x32,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw8693x_protect_config @ 0011dd68 size=256
// signature: undefined aw8693x_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw8693x_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x2c3,"aw8693x_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x4a,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",700,"aw8693x_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x4a,local_40,1);
    haptic_hv_i2c_writes(param_1,0x4b,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_parse_dt @ 0011de6c size=1364
// signature: undefined aw8693x_parse_dt(void)
// callers: []
//------------------------------------------------------------

void aw8693x_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined2 local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_52 = 0;
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_gain_bypass",param_2 + 0x55f,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133d52,"haptic_hv",0x65b,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_uvlo_vol_default",param_2 + 0x560,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_00131cb1,"haptic_hv",0x65f,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x663,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_f0_cali_percent",param_2 + 0x529,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133a25,"haptic_hv",0x667,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_cont_smart_loop",param_2 + 0x561,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134a05,"haptic_hv",0x66b,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_cont_drv1_lvl",param_2 + 0x562,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133d9a,"haptic_hv",0x66f,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8693x_cont_lra_vrms",param_2 + 0x584,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134d59,"haptic_hv",0x673,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_cont_drv1_time",param_2 + 0x566,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001346d5,"haptic_hv",0x677,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_cont_drv2_time",param_2 + 0x567,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001372b0,"haptic_hv",0x67b,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_cont_brk_time",param_2 + 0x564,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137580,"haptic_hv",0x67f,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw8693x_cont_track_margin",param_2 + 0x568,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001375b1,"haptic_hv",0x684,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_cont_brk_gain",param_2 + 0x565,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134707,"haptic_hv",0x688,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_d2s_gain",param_2 + 0x55d,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00135404,"haptic_hv",0x68c,"aw8693x_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_duration_time",&local_54,3,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134da0,"haptic_hv",0x691,"aw8693x_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_54;
    *(undefined1 *)(param_2 + 0x52c) = local_52;
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693x_trig_config",&local_50,0x18,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133396,"haptic_hv",0x698,"aw8693x_parse_dt");
  }
  else {
    *(undefined8 *)(param_2 + 0x569) = local_50;
    *(undefined8 *)(param_2 + 0x571) = local_48;
    *(undefined8 *)(param_2 + 0x579) = local_40;
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8693x_bst_vol_default",param_2 + 0x534,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_0013412c,"haptic_hv",0x69f,"aw8693x_parse_dt");
  }
  lVar2 = of_find_property(param_3,"aw8693x_is_enabled_track_en",0);
  *(bool *)(param_2 + 0x588) = lVar2 != 0;
  _printk(&DAT_00132438,"haptic_hv",0x6a3,"aw8693x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693x_is_enabled_auto_bst",0);
  *(bool *)(param_2 + 0x58c) = lVar2 != 0;
  _printk(&DAT_00136783,"haptic_hv",0x6a7,"aw8693x_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693x_is_enabled_one_wire",0);
  *(bool *)(param_2 + 0x58e) = lVar2 != 0;
  _printk(&DAT_001372f6,"haptic_hv",0x6ab,"aw8693x_parse_dt");
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_trig_init @ 0011e3c4 size=940
// signature: undefined aw8693x_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw8693x_trig_init(long param_1)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  long lVar4;
  bool bVar5;
  undefined1 local_38 [4];
  byte local_34 [4];
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x5c7,"aw8693x_trig_init");
  if (*(char *)(param_1 + 0x58e) == '\0') {
    cVar3 = *(char *)(param_1 + 0x569);
    *(undefined1 *)(param_1 + 0x6c9) = *(undefined1 *)(param_1 + 0x56b);
    *(undefined1 *)(param_1 + 0x6cb) = *(undefined1 *)(param_1 + 0x56c);
    *(char *)(param_1 + 0x6c7) = cVar3;
    *(char *)(param_1 + 0x6c8) = *(char *)(param_1 + 0x56a);
    uVar2 = (uint)(cVar3 != '\0') << 6;
    if (*(char *)(param_1 + 0x56a) != '\0') {
      uVar2 = (uint)(cVar3 != '\0') << 6 | 0xffffff80;
    }
    *(undefined1 *)(param_1 + 0x6ca) = *(undefined1 *)(param_1 + 0x56d);
    if (*(char *)(param_1 + 0x56f) != '\0') {
      uVar2 = uVar2 | 0x20;
    }
    if (*(char *)(param_1 + 0x570) != '\0') {
      uVar2 = uVar2 | 0x10;
    }
    *(char *)(param_1 + 0x6c5) = *(char *)(param_1 + 0x56f);
    *(char *)(param_1 + 0x6c6) = *(char *)(param_1 + 0x570);
    *(undefined1 *)(param_1 + 0x6cc) = *(undefined1 *)(param_1 + 0x56e);
    haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar2);
    local_34[0] = *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7;
    haptic_hv_i2c_writes(param_1,0x33,local_34,1);
    local_34[0] = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
    haptic_hv_i2c_writes(param_1,0x36,local_34,1);
  }
  else {
    _printk(&DAT_00136463,"haptic_hv",0x5c9,"aw8693x_trig_init");
    _printk(&DAT_00132e8a,"haptic_hv",0x2e1,"aw8693x_one_wire_init");
    local_38[0] = 0x6c;
    haptic_hv_i2c_writes(param_1,0x3e,local_38,1);
    local_38[0] = 0x75;
    haptic_hv_i2c_writes(param_1,0x3c,local_38,1);
    haptic_hv_i2c_write_bits(param_1,0x3a,0xfffffff7,8);
  }
  cVar3 = *(char *)(param_1 + 0x571);
  *(undefined1 *)(param_1 + 0x6d6) = *(undefined1 *)(param_1 + 0x573);
  *(char *)(param_1 + 0x6d4) = cVar3;
  *(undefined1 *)(param_1 + 0x6d9) = *(undefined1 *)(param_1 + 0x576);
  *(char *)(param_1 + 0x6d5) = *(char *)(param_1 + 0x572);
  *(undefined1 *)(param_1 + 0x6d8) = *(undefined1 *)(param_1 + 0x574);
  *(undefined1 *)(param_1 + 0x6d7) = *(undefined1 *)(param_1 + 0x575);
  *(undefined1 *)(param_1 + 0x6e2) = *(undefined1 *)(param_1 + 0x57a);
  *(char *)(param_1 + 0x6d2) = *(char *)(param_1 + 0x577);
  bVar1 = (cVar3 != '\0') << 2;
  if (*(char *)(param_1 + 0x572) != '\0') {
    bVar1 = (cVar3 != '\0') << 2 | 8;
  }
  *(undefined1 *)(param_1 + 0x6e1) = *(undefined1 *)(param_1 + 0x579);
  *(undefined1 *)(param_1 + 0x6e3) = *(undefined1 *)(param_1 + 0x57b);
  if (*(char *)(param_1 + 0x577) != '\0') {
    bVar1 = bVar1 | 2;
  }
  *(undefined1 *)(param_1 + 0x6e5) = *(undefined1 *)(param_1 + 0x57c);
  *(char *)(param_1 + 0x6d3) = *(char *)(param_1 + 0x578);
  *(undefined1 *)(param_1 + 0x6e6) = *(undefined1 *)(param_1 + 0x57e);
  *(undefined1 *)(param_1 + 0x6e4) = *(undefined1 *)(param_1 + 0x57d);
  *(undefined2 *)(param_1 + 0x6df) = *(undefined2 *)(param_1 + 0x57f);
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x578) != '\0');
  local_30[0] = *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x34,local_30,1);
  local_30[0] = *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x37,local_30,1);
  bVar5 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar2 = (uint)bVar5 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar2 = (uint)bVar5 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar2 = uVar2 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar2 = uVar2 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar2);
  local_2c[0] = *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x35,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x38,local_2c,1);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_irq_clear @ 0011e774 size=88
// signature: undefined aw8693x_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw8693x_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_set_ram_addr @ 0011e7d0 size=100
// signature: undefined aw8693x_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_ram_addr(long param_1)

{
  long lVar1;
  ushort local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_misc_para_init @ 0011e838 size=684
// signature: undefined aw8693x_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw8693x_misc_para_init(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = (ulong)*(byte *)(*(long *)(param_1 + 0x2c8) + 2);
  haptic_hv_i2c_writes(param_1,0x47,&local_40,1);
  iVar3 = 0x711;
  if (0x707 < *(uint *)(param_1 + 0x530)) {
    iVar3 = 0x7c6;
  }
  uVar2 = (uint)(iVar3 * *(int *)(param_1 + 0x584)) / 40000;
  if (0x7e < uVar2) {
    uVar2 = 0x7f;
  }
  *(char *)(param_1 + 0x563) = (char)uVar2;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x534);
  haptic_hv_i2c_reads(param_1,7,&local_40,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_40;
  haptic_hv_i2c_reads(param_1,10,&local_40,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_40;
  *(ulong *)(param_1 + 0x11) = local_40;
  haptic_hv_i2c_write_bits(param_1,0x46,0xfffffffe,*(undefined1 *)(param_1 + 0x55f));
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffff7f,(ulong)*(byte *)(param_1 + 0x561) << 7);
  haptic_hv_i2c_write_bits(param_1,0x1c,0xfffffff0,*(undefined1 *)(param_1 + 0x565));
  haptic_hv_i2c_writes(param_1,0x21,param_1 + 0x564,1);
  local_44[0] = 0x32;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",700,"aw8693x_protect_config");
  local_48[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x4a,local_48,1);
  haptic_hv_i2c_writes(param_1,0x4b,local_44,1);
  _printk(&DAT_00132e8a,"haptic_hv",0x206,"aw8693x_vbat_ref_config");
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x30);
  local_40 = CONCAT35(local_40._5_3_,0x4180030e1c);
  local_44[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5e,local_44,1);
  haptic_hv_i2c_write_bits(param_1,0x56,0xfffffffc,*(undefined1 *)(param_1 + 0x560));
  haptic_hv_i2c_writes(param_1,0x6f,&local_40,2);
  haptic_hv_i2c_writes(param_1,0x72,(ulong)&local_40 | 2,1);
  haptic_hv_i2c_writes(param_1,0x77,(ulong)&local_40 | 3,1);
  haptic_hv_i2c_writes(param_1,0x7d,(ulong)&local_40 | 4,1);
  local_44[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5e,local_44,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_interrupt_setup @ 0011eae8 size=140
// signature: undefined aw8693x_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw8693x_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x46,0xffffffe7,8);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff19,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_set_rtp_aei @ 0011eb78 size=48
// signature: undefined aw8693x_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw8693x_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693x_upload_lra @ 0011ebac size=288
// signature: undefined aw8693x_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw8693x_upload_lra(long param_1,int param_2)

{
  long lVar1;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  if (param_2 == 2) {
    _printk(&DAT_001323a9,"haptic_hv",0x29c,"aw8693x_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    local_2c[0] = *(byte *)(param_1 + 0x9c);
  }
  else {
    if (param_2 == 1) {
      _printk(&DAT_001378a9,"haptic_hv",0x298,"aw8693x_upload_lra",*(undefined4 *)(param_1 + 0x90));
    }
    else {
      if (param_2 == 0) {
        _printk(&DAT_00136e0b,"haptic_hv",0x295,"aw8693x_upload_lra");
        goto LAB_0011ec8c;
      }
      _printk(&DAT_00136f7a,"haptic_hv",0x2a0,"aw8693x_upload_lra");
    }
    local_2c[0] = *(byte *)(param_1 + 0x90);
  }
  local_2c[0] = local_2c[0] & 0x7f;
LAB_0011ec8c:
  haptic_hv_i2c_writes(param_1,0x5d,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_wav_seq @ 0011ecd0 size=236
// signature: undefined aw8693x_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,10,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_ram_data @ 0011edc0 size=120
// signature: undefined aw8693x_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_bst_mode_config @ 0011ee3c size=200
// signature: undefined aw8693x_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8693x_bst_mode_config(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    _printk(&DAT_00135b17,"haptic_hv",0x1f7,"aw8693x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
  }
  else if (param_2 == '\x01') {
    _printk(&DAT_0013335b,"haptic_hv",0x1f1,"aw8693x_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0x20);
  }
  else {
    _printk(&DAT_00134a38,"haptic_hv",0x1fd,"aw8693x_bst_mode_config",param_2);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_first_wave_addr @ 0011ef08 size=112
// signature: undefined aw8693x_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_wav_loop @ 0011ef7c size=420
// signature: undefined aw8693x_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw8693x_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0x12,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw8693x_get_reg @ 0011f124 size=288
// signature: undefined aw8693x_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw8693x_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_d0 [136];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_d0[0x70] = 0;
  local_d0[0x71] = 0;
  local_d0[0x72] = 0;
  local_d0[0x73] = 0;
  local_d0[0x74] = 0;
  local_d0[0x75] = 0;
  local_d0[0x76] = 0;
  local_d0[0x77] = 0;
  local_d0[0x78] = 0;
  local_d0[0x79] = 0;
  local_d0[0x7a] = 0;
  local_d0[0x7b] = 0;
  local_d0[0x7c] = 0;
  local_d0[0x7d] = 0;
  local_d0[0x7e] = 0;
  local_d0[0x7f] = 0;
  local_d0[0x80] = 0;
  local_d0[0x81] = 0;
  local_d0[0x82] = 0;
  local_d0[0x60] = 0;
  local_d0[0x61] = 0;
  local_d0[0x62] = 0;
  local_d0[99] = 0;
  local_d0[100] = 0;
  local_d0[0x65] = 0;
  local_d0[0x66] = 0;
  local_d0[0x67] = 0;
  local_d0[0x68] = 0;
  local_d0[0x69] = 0;
  local_d0[0x6a] = 0;
  local_d0[0x6b] = 0;
  local_d0[0x6c] = 0;
  local_d0[0x6d] = 0;
  local_d0[0x6e] = 0;
  local_d0[0x6f] = 0;
  local_d0[0x50] = 0;
  local_d0[0x51] = 0;
  local_d0[0x52] = 0;
  local_d0[0x53] = 0;
  local_d0[0x54] = 0;
  local_d0[0x55] = 0;
  local_d0[0x56] = 0;
  local_d0[0x57] = 0;
  local_d0[0x58] = 0;
  local_d0[0x59] = 0;
  local_d0[0x5a] = 0;
  local_d0[0x5b] = 0;
  local_d0[0x5c] = 0;
  local_d0[0x5d] = 0;
  local_d0[0x5e] = 0;
  local_d0[0x5f] = 0;
  local_d0[0x40] = 0;
  local_d0[0x41] = 0;
  local_d0[0x42] = 0;
  local_d0[0x43] = 0;
  local_d0[0x44] = 0;
  local_d0[0x45] = 0;
  local_d0[0x46] = 0;
  local_d0[0x47] = 0;
  local_d0[0x48] = 0;
  local_d0[0x49] = 0;
  local_d0[0x4a] = 0;
  local_d0[0x4b] = 0;
  local_d0[0x4c] = 0;
  local_d0[0x4d] = 0;
  local_d0[0x4e] = 0;
  local_d0[0x4f] = 0;
  local_d0[0x30] = 0;
  local_d0[0x31] = 0;
  local_d0[0x32] = 0;
  local_d0[0x33] = 0;
  local_d0[0x34] = 0;
  local_d0[0x35] = 0;
  local_d0[0x36] = 0;
  local_d0[0x37] = 0;
  local_d0[0x38] = 0;
  local_d0[0x39] = 0;
  local_d0[0x3a] = 0;
  local_d0[0x3b] = 0;
  local_d0[0x3c] = 0;
  local_d0[0x3d] = 0;
  local_d0[0x3e] = 0;
  local_d0[0x3f] = 0;
  local_d0[0x20] = 0;
  local_d0[0x21] = 0;
  local_d0[0x22] = 0;
  local_d0[0x23] = 0;
  local_d0[0x24] = 0;
  local_d0[0x25] = 0;
  local_d0[0x26] = 0;
  local_d0[0x27] = 0;
  local_d0[0x28] = 0;
  local_d0[0x29] = 0;
  local_d0[0x2a] = 0;
  local_d0[0x2b] = 0;
  local_d0[0x2c] = 0;
  local_d0[0x2d] = 0;
  local_d0[0x2e] = 0;
  local_d0[0x2f] = 0;
  local_d0[0x10] = 0;
  local_d0[0x11] = 0;
  local_d0[0x12] = 0;
  local_d0[0x13] = 0;
  local_d0[0x14] = 0;
  local_d0[0x15] = 0;
  local_d0[0x16] = 0;
  local_d0[0x17] = 0;
  local_d0[0x18] = 0;
  local_d0[0x19] = 0;
  local_d0[0x1a] = 0;
  local_d0[0x1b] = 0;
  local_d0[0x1c] = 0;
  local_d0[0x1d] = 0;
  local_d0[0x1e] = 0;
  local_d0[0x1f] = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  local_d0[2] = 0;
  local_d0[3] = 0;
  local_d0[4] = 0;
  local_d0[5] = 0;
  local_d0[6] = 0;
  local_d0[7] = 0;
  local_d0[8] = 0;
  local_d0[9] = 0;
  local_d0[10] = 0;
  local_d0[0xb] = 0;
  local_d0[0xc] = 0;
  local_d0[0xd] = 0;
  local_d0[0xe] = 0;
  local_d0[0xf] = 0;
  haptic_hv_i2c_reads(param_1,0,local_d0,0x32);
  haptic_hv_i2c_reads(param_1,0x33,local_d0 + 0x33,0xf);
  haptic_hv_i2c_reads(param_1,0x43,local_d0 + 0x43,0x40);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 0x32) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_d0[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x83);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw8693x_get_prctmode @ 0011f248 size=96
// signature: undefined aw8693x_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw8693x_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x4a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw8693x_get_trim_lra @ 0011f2ac size=96
// signature: undefined aw8693x_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

byte aw8693x_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x5d,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 0x7f;
}



//------------------------------------------------------------
// aw8693x_get_glb_state @ 0011f310 size=92
// signature: undefined aw8693x_get_glb_state(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_glb_state(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_get_osc_status @ 0011f370 size=96
// signature: undefined aw8693x_get_osc_status(void)
// callers: []
//------------------------------------------------------------

byte aw8693x_get_osc_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw8693x_rtp_get_fifo_afs @ 0011f3d4 size=96
// signature: undefined aw8693x_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw8693x_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw8693x_rtp_get_fifo_aes @ 0011f438 size=96
// signature: undefined aw8693x_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw8693x_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw8693x_get_theory_time @ 0011f49c size=88
// signature: undefined aw8693x_get_theory_time(void)
// callers: []
//------------------------------------------------------------

void aw8693x_get_theory_time(undefined8 param_1)

{
  long lVar1;
  byte local_2c [4];
  undefined8 local_28;
  
  lVar1 = sp_el0;
  local_28 = *(undefined8 *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x46,local_2c,1);
                    /* WARNING: Could not recover jumptable at 0x0011f4f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&UNK_0011f4f4 + (ulong)(byte)(&DAT_0012e08a)[local_2c[0] >> 5 & 3] * 4))();
  return;
}



//------------------------------------------------------------
// aw8693x_snd_soc_init @ 0011f5c4 size=224
// signature: undefined aw8693x_snd_soc_init(void)
// callers: []
//------------------------------------------------------------

int aw8693x_snd_soc_init(undefined8 param_1)

{
  int iVar1;
  void *__dest;
  
  dev_set_name(param_1,&DAT_001333e1,"haptic_hv");
  __dest = (void *)devm_kmalloc(param_1,0xe0,0xdc0);
  if (__dest == (void *)0x0) {
    iVar1 = -0xc;
  }
  else {
    memcpy(__dest,&aw8693x_dai,0xe0);
    _printk(&DAT_00134c88,"haptic_hv",0x111,"aw8693x_snd_soc_init","aw8693x-aif");
    iVar1 = snd_soc_register_component(param_1,soc_codec_dev_aw8693x,__dest,1);
    if (iVar1 < 0) {
      _printk(&DAT_00132ce1,"haptic_hv",0x116,"aw8693x_snd_soc_init",iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_show @ 0011f6a8 size=64
// signature: undefined cont_drv_lvl_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_lvl_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_lvl = 0x%02X, cont_drv2_lvl = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4ba),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bb));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_store @ 0011f6ec size=252
// signature: undefined cont_drv_lvl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_lvl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined2 local_44;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_40[1] = 0;
  local_44 = 0;
  iVar1 = sscanf(param_3,"%x %x",local_40,(uint *)((ulong)local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x4ba) = (char)local_40[0];
    *(char *)(lVar2 + 0x4bb) = (char)local_40[1];
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_reads(lVar2 + -0xa8,0x1d,&local_44,1);
    local_44 = CONCAT11(*(undefined1 *)(lVar2 + 0x4bb),
                        *(byte *)(lVar2 + 0x4ba) | (byte)local_44 & 0x80);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1d,&local_44,2);
    mutex_unlock(lVar2 + 0x2a8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_time_show @ 0011f7ec size=64
// signature: undefined cont_drv_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4be),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bf));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_time_store @ 0011f830 size=212
// signature: undefined cont_drv_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_44;
  undefined1 local_43;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_40,(uint *)((ulong)&local_40 | 4));
  if (iVar1 == 2) {
    *(undefined1 *)(lVar2 + 0x4be) = (undefined1)local_40;
    *(char *)(lVar2 + 0x4bf) = (char)((ulong)local_40 >> 0x20);
    local_44 = (undefined1)local_40;
    local_43 = *(undefined1 *)(lVar2 + 0x4bf);
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1f,&local_44,2);
    mutex_unlock(lVar2 + 0x2a8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_brk_time_show @ 0011f908 size=60
// signature: undefined cont_brk_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_brk_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_brk_time_store @ 0011f948 size=128
// signature: undefined cont_brk_time_store(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = kstrtou8(param_3,0,lVar2 + 0x4bc);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x21,lVar2 + 0x4bc,1);
    mutex_unlock(lVar2 + 0x2a8);
  }
  return param_4;
}



//------------------------------------------------------------
// trig_show @ 0011f9cc size=292
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x61f),(uint)*(byte *)(lVar2 + 0x620),
                   (uint)*(byte *)(lVar2 + 0x621),(uint)*(byte *)(lVar2 + 0x623),
                   (uint)*(byte *)(lVar2 + 0x622),(uint)*(byte *)(lVar2 + 0x624),
                   (uint)*(byte *)(lVar2 + 0x61d),(uint)*(byte *)(lVar2 + 0x61e));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x62c),(uint)*(byte *)(lVar2 + 0x62d),
                   (uint)*(byte *)(lVar2 + 0x62e),(uint)*(byte *)(lVar2 + 0x630),
                   (uint)*(byte *)(lVar2 + 0x62f),(uint)*(byte *)(lVar2 + 0x631),
                   (uint)*(byte *)(lVar2 + 0x62a),(uint)*(byte *)(lVar2 + 0x62b));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x639),(uint)*(byte *)(lVar2 + 0x63a),
                   (uint)*(byte *)(lVar2 + 0x63b),(uint)*(byte *)(lVar2 + 0x63d),
                   (uint)*(byte *)(lVar2 + 0x63c),(uint)*(byte *)(lVar2 + 0x63e),
                   (uint)*(byte *)(lVar2 + 0x637),(uint)*(byte *)(lVar2 + 0x638));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 0011faf4 size=776
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar5 = sscanf(param_3,"%u %u %u %u %u %u %u %u %u",(uint *)&local_60,
                 (uint *)((ulong)&local_60 | 4),(uint *)&local_58,(uint *)((long)&local_58 + 4),
                 (uint *)&local_50,(uint *)((long)&local_50 + 4),(uint *)&local_48,
                 (uint *)((long)&local_48 + 4),local_40);
  if (iVar5 == 9) {
    _printk(&DAT_001359f8,"haptic_hv",0x77c,"trig_store",local_60 & 0xffffffff,local_60._4_4_,
            local_58 & 0xffffffff,local_58._4_4_,local_50 & 0xffffffff,local_50 >> 0x20,
            local_48 & 0xffffffff,local_48._4_4_,local_40[0]);
    uVar3 = local_60;
    if ((uint)local_60 - 4 < 0xfffffffd) {
      _printk(&DAT_001369d0,"haptic_hv",0x77e,"trig_store");
    }
    else {
      uVar2 = (uint)local_60 - 1;
      if ((uVar2 == 0) && (*(char *)(lVar6 + 0x4e6) != '\0')) {
        _printk(&DAT_00136135,"haptic_hv",0x782,"trig_store");
      }
      else if (*(char *)(lVar6 + -0xa2) == '\0') {
        _printk(&DAT_001325b9,"haptic_hv",0x786,"trig_store");
      }
      else {
        if (((uint)local_50 <= *(byte *)(lVar6 + 0x47c)) &&
           ((uint)local_48 <= *(byte *)(lVar6 + 0x47c))) {
          lVar1 = lVar6 + 0x618;
          local_60 = CONCAT44(local_60._4_4_,uVar2);
          *(char *)(lVar1 + (ulong)uVar2 * 0xd + 7) = (char)(uVar3 >> 0x20);
          if (uVar2 < 3) {
            *(char *)(lVar1 + (ulong)uVar2 * 0xd + 8) = (char)local_58;
            if (uVar2 < 3) {
              *(char *)(lVar1 + (ulong)uVar2 * 0xd + 9) = (char)(local_58 >> 0x20);
              if (uVar2 < 3) {
                *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xb) = (char)local_50;
                if (uVar2 < 3) {
                  *(char *)(lVar1 + (ulong)uVar2 * 0xd + 10) = (char)(local_50 >> 0x20);
                  if (uVar2 < 3) {
                    *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xc) = (char)local_48;
                    if (uVar2 < 3) {
                      *(char *)(lVar1 + (ulong)uVar2 * 0xd + 5) = (char)(local_48 >> 0x20);
                      if (uVar2 < 3) {
                        lVar7 = lVar6 + -0xa8;
                        *(char *)(lVar1 + (ulong)uVar2 * 0xd + 6) = (char)local_40[0];
                        mutex_lock(lVar6 + 0x2a8);
                        if ((uint)local_60 == 2) {
                          aw8693x_trig3_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 1) {
                          aw8693x_trig2_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 0) {
                          aw8693x_trig1_param_config(lVar7);
                        }
                        mutex_unlock(lVar6 + 0x2a8);
                        goto LAB_0011fb78;
                      }
                    }
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11fdfc);
          (*pcVar4)();
        }
        _printk(&DAT_00134564,"haptic_hv",0x78b,"trig_store");
      }
    }
  }
LAB_0011fb78:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8693x_trig1_param_config @ 0011fdfc size=248
// signature: undefined aw8693x_trig1_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8693x_trig1_param_config(long param_1)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6c7) != '\0';
  uVar1 = (uint)bVar3 << 6;
  if (*(char *)(param_1 + 0x6c8) != '\0') {
    uVar1 = (uint)bVar3 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6c5) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6c6) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
  local_2c[0] = *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x33,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x36,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_trig2_param_config @ 0011fef4 size=248
// signature: undefined aw8693x_trig2_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8693x_trig2_param_config(long param_1)

{
  byte bVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6d4) != '\0';
  bVar1 = bVar3 << 2;
  if (*(char *)(param_1 + 0x6d5) != '\0') {
    bVar1 = bVar3 << 2 | 8;
  }
  if (*(char *)(param_1 + 0x6d2) != '\0') {
    bVar1 = bVar1 | 2;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x6d3) != '\0');
  local_2c[0] = *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x34,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x37,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693x_trig3_param_config @ 0011ffec size=248
// signature: undefined aw8693x_trig3_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8693x_trig3_param_config(long param_1)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar1 = (uint)bVar3 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar1 = (uint)bVar3 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  local_2c[0] = *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x35,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x38,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rtp_auto_sin_show @ 001200e8 size=60
// signature: undefined rtp_auto_sin_show(void)
// callers: []
//------------------------------------------------------------

long rtp_auto_sin_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"rtp_cnt = %u\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// rtp_auto_sin_store @ 00120128 size=332
// signature: undefined rtp_auto_sin_store(void)
// callers: []
//------------------------------------------------------------

long rtp_auto_sin_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    _printk(&DAT_00132666,"haptic_hv",0x7bf,"rtp_auto_sin_store");
    param_4 = (long)iVar1;
    goto LAB_001201e8;
  }
  mutex_lock(lVar3 + 0x2a8);
  if (local_3c == 0) {
    uVar2 = 0;
    *(undefined4 *)(lVar3 + -0x60) = 0;
LAB_001201cc:
    haptic_hv_i2c_write_bits(lVar3 + -0xa8,0x2d,0xffffffdf,uVar2);
  }
  else {
    if (local_3c < *(uint *)(lVar3 + -0x28)) {
      uVar2 = 0x20;
      *(undefined4 *)(lVar3 + -0x60) = 1;
      *(uint *)(lVar3 + -0x14) = local_3c;
      goto LAB_001201cc;
    }
    *(undefined4 *)(lVar3 + -0x60) = 0;
    _printk(&DAT_0013408e,"haptic_hv",2000,"rtp_auto_sin_store",local_3c);
  }
  mutex_unlock(lVar3 + 0x2a8);
  queue_work_on(0x20,*(undefined8 *)(lVar3 + 0x468),lVar3 + 0x350);
LAB_001201e8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8693x_set_dai_sysclk @ 00120278 size=64
// signature: undefined aw8693x_set_dai_sysclk(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_set_dai_sysclk(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  _printk(&DAT_00132947,"haptic_hv",0x4f,"aw8693x_set_dai_sysclk",param_3);
  return 0;
}



//------------------------------------------------------------
// aw8693x_set_fmt @ 001202bc size=64
// signature: undefined aw8693x_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_set_fmt(undefined8 param_1,undefined4 param_2)

{
  _printk(&DAT_00137211,"haptic_hv",0x48,"aw8693x_set_fmt",param_2);
  return 0;
}



//------------------------------------------------------------
// aw8693x_mute @ 00120300 size=380
// signature: undefined aw8693x_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_mute(long param_1,int param_2,int param_3)

{
  long lVar1;
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = '\0';
  if (param_3 == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0x93,"aw8693x_mute");
  }
  else {
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
    _printk(&DAT_001338b0,"haptic_hv",0x96,"aw8693x_mute",param_2);
    mutex_lock(lVar1 + 0x350);
    if (param_2 == 0) {
      haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,2);
      haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0x80);
      usleep_range_state(1000,0x5dc,2);
      haptic_hv_i2c_reads(lVar1,0x3f,local_3c,1);
      if (local_3c[0] != '\n') {
        _printk(&DAT_00135703,"haptic_hv",0xa1,"aw8693x_mute");
        aw8693x_i2s_enable(lVar1,0);
      }
    }
    else {
      haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,0);
      haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0);
    }
    mutex_unlock(lVar1 + 0x350);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8693x_startup @ 00120480 size=8
// signature: undefined aw8693x_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_startup(void)

{
  return 0;
}



//------------------------------------------------------------
// aw8693x_shutdown @ 0012048c size=152
// signature: undefined aw8693x_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw8693x_shutdown(long param_1,long param_2)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0xb0,"aw8693x_shutdown");
  }
  else {
    lVar1 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
    mutex_lock(lVar1 + 0x350);
    haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,0);
    haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0);
    mutex_unlock(lVar1 + 0x350);
  }
  return;
}



//------------------------------------------------------------
// aw8693x_hw_params @ 00120528 size=432
// signature: undefined aw8693x_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_hw_params(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0x5f,"aw8693x_hw_params");
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x128);
  lVar6 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132051,"haptic_hv",100,"aw8693x_hw_params",iVar2);
  if (iVar2 == 48000) {
LAB_001205f4:
    uVar7 = 0;
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 != 0) goto LAB_001205cc;
LAB_00120600:
    uVar4 = *(uint *)(param_2 + 0x28);
    if (uVar4 == 0) {
      uVar5 = 0;
      goto LAB_00120620;
    }
    uVar5 = 0x20;
  }
  else {
    if (iVar2 != 96000) {
      _printk(&DAT_00132073,"haptic_hv",0x6e,"aw8693x_hw_params");
      goto LAB_001205f4;
    }
    uVar7 = 4;
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 == 0) goto LAB_00120600;
LAB_001205cc:
    uVar5 = 0;
  }
  uVar4 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
  uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
  uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
  uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
  uVar5 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10) | uVar5;
LAB_00120620:
  cVar3 = snd_pcm_format_width(uVar5);
  _printk(&DAT_001340cb,"haptic_hv",0x73,"aw8693x_hw_params",cVar3);
  if (cVar3 != '\x10') {
    if (cVar3 == ' ') {
      uVar7 = uVar7 | 2;
    }
    else if (cVar3 == '\x18') {
      uVar7 = uVar7 | 1;
    }
    else {
      uVar7 = uVar7 | 2;
      _printk(&DAT_00133305,"haptic_hv",0x80,"aw8693x_hw_params");
    }
  }
  lVar1 = lVar6 + 0x350;
  mutex_lock(lVar1);
  haptic_hv_i2c_write_bits(lVar6,0x53,0xf8,uVar7);
  mutex_unlock(lVar1);
  return 0;
}



//------------------------------------------------------------
// aw8693x_i2s_enable @ 001206d8 size=88
// signature: undefined aw8693x_i2s_enable(void)
// callers: [aw8693x_mute]
//------------------------------------------------------------

void aw8693x_i2s_enable(undefined8 param_1,ulong param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = (param_2 & 1) == 0;
  uVar2 = 2;
  if (bVar1) {
    uVar2 = 0;
  }
  uVar3 = 0xffffff80;
  if (bVar1) {
    uVar3 = 0;
  }
  haptic_hv_i2c_write_bits(0xffffff80,param_1,0x46,0xfffffffd,uVar2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xffffff7f,uVar3);
  return;
}



//------------------------------------------------------------
// aw8693x_codec_probe @ 00120734 size=104
// signature: undefined aw8693x_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693x_codec_probe(long param_1)

{
  long lVar1;
  undefined2 local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0x800;
  haptic_hv_i2c_writes(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98),0x52,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8693x_codec_remove @ 001207a0 size=56
// signature: undefined aw8693x_codec_remove(void)
// callers: []
//------------------------------------------------------------

void aw8693x_codec_remove(void)

{
  _printk(&DAT_00132e8a,"haptic_hv",0xf1,"aw8693x_codec_remove");
  return;
}



//------------------------------------------------------------
// aw8693xs_get_f0 @ 001207dc size=956
// signature: undefined aw8693xs_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined4 aw8693xs_get_f0(long param_1)

{
  uint uVar1;
  long lVar2;
  ushort uVar3;
  byte bVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined8 uVar8;
  int iVar9;
  uint uVar10;
  byte local_48 [4];
  undefined1 local_44 [4];
  char local_40 [4];
  undefined1 local_3c;
  undefined2 local_3b;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48[0] = 0;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
  aw8693xs_stop();
  _printk(&DAT_00132e8a,"haptic_hv",0x211,"aw8693xs_vbat_ref_config");
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
  _printk(&DAT_001331a6,"haptic_hv",0x268,"aw8693xs_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x202,"aw8693xs_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff7f,0x80);
  haptic_hv_i2c_write_bits(param_1,0x18,0xffffff9f,0x60);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_reads(param_1,8,local_48,1);
  bVar4 = local_48[0];
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  local_3c = *(undefined1 *)(param_1 + 0x563);
  local_3b = *(undefined2 *)(param_1 + 0x566);
  haptic_hv_i2c_writes(param_1,0x1e,&local_3c,3);
  if (*(char *)(param_1 + 0x568) == '\0') {
    _printk(&DAT_001366d5,"haptic_hv",0x4c6,"aw8693xs_get_f0");
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  else {
    haptic_hv_i2c_writes(param_1,0x22,param_1 + 0x568,1);
    uVar1 = *(uint *)(param_1 + 0x530);
  }
  if (uVar1 == 0) {
    uVar6 = 0xffffffde;
  }
  else {
    uVar10 = 0;
    if (uVar1 != 0) {
      uVar10 = 240000 / uVar1;
    }
    iVar9 = (uVar10 - ((uint)*(byte *)(param_1 + 0x565) + (uint)*(byte *)(param_1 + 0x568))) + -8;
    if (0xfe < iVar9) {
      iVar9 = 0xff;
    }
    if (iVar9 < 1) {
      iVar9 = 0;
    }
    if (0xfe < uVar10) {
      uVar10 = 0xff;
    }
    uVar3 = (ushort)local_3b >> 8;
    local_3b = CONCAT11((char)uVar3,(char)iVar9);
    local_3c = (undefined1)uVar10;
    haptic_hv_i2c_writes(param_1,0x19,&local_3c,2);
    _printk(&DAT_00133f37,"haptic_hv",0x1db,"aw8693xs_play_go",1);
    local_44[0] = 1;
    haptic_hv_i2c_writes(param_1,9,local_44,1);
    usleep_range_state(20000,0x5014,2);
    iVar9 = -100;
    do {
      local_40[0] = '\0';
      haptic_hv_i2c_reads(param_1,0x3f,local_40,1);
      if (local_40[0] == '\0') {
        puVar7 = &DAT_00136940;
        uVar8 = 0x1ee;
        goto LAB_00120b24;
      }
      usleep_range_state(2000,0x9c4,2);
      bVar5 = iVar9 != -1;
      iVar9 = iVar9 + 1;
    } while (bVar5);
    puVar7 = &DAT_00137ca1;
    uVar8 = 499;
LAB_00120b24:
    _printk(puVar7,"haptic_hv",uVar8,"aw8693xs_wait_enter_standby");
    uVar6 = aw8693xs_read_f0(param_1);
    haptic_hv_i2c_write_bits(param_1,0x18,0xffffff9f,0);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,bVar4 & 4);
    _printk(&DAT_00132e8a,"haptic_hv",0x211,"aw8693xs_vbat_ref_config");
    haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x30);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// aw8693xs_ram_get_f0 @ 00120b9c size=912
// signature: undefined aw8693xs_ram_get_f0(void)
// callers: []
//------------------------------------------------------------

undefined4 aw8693xs_ram_get_f0(long param_1)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  byte local_4c [4];
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  char local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_4c[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    puVar6 = &DAT_001325b9;
    uVar7 = 0x505;
  }
  else {
    if (4 < *(byte *)(param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x530);
      aw8693xs_stop(param_1);
      haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,*(undefined1 *)(param_1 + 0x55d));
      _printk(&DAT_00136db2,"haptic_hv",0x242,"aw8693xs_play_mode");
      *(undefined1 *)(param_1 + 0xb) = 1;
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,0);
      haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0x20);
      haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff7f,0);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffff9f,0x60);
      haptic_hv_i2c_reads(param_1,8,local_4c,1);
      bVar3 = local_4c[0];
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
      _printk(&DAT_00137ecf,"haptic_hv",0x174,"aw8693xs_set_bst_vol",8000,0xd);
      haptic_hv_i2c_write_bits(param_1,6,0xffffffe0,0xd);
      local_48[0] = 5;
      haptic_hv_i2c_writes(param_1,10,local_48,1);
      local_44[0] = 0;
      haptic_hv_i2c_writes(param_1,0xb,local_44,1);
      haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0x20);
      _printk(&DAT_00133f37,"haptic_hv",0x1db,"aw8693xs_play_go",1);
      local_40[0] = 1;
      haptic_hv_i2c_writes(param_1,9,local_40,1);
      usleep_range_state(20000,0x5014,2);
      iVar9 = -100;
      do {
        local_3c[0] = '\0';
        haptic_hv_i2c_reads(param_1,0x3f,local_3c,1);
        if (local_3c[0] == '\0') {
          puVar6 = &DAT_00136940;
          uVar7 = 0x1ee;
          goto LAB_00120e44;
        }
        usleep_range_state(2000,0x9c4,2);
        bVar4 = iVar9 != -1;
        iVar9 = iVar9 + 1;
      } while (bVar4);
      puVar6 = &DAT_00137ca1;
      uVar7 = 499;
LAB_00120e44:
      _printk(puVar6,"haptic_hv",uVar7,"aw8693xs_wait_enter_standby");
      uVar5 = aw8693xs_read_f0(param_1);
      uVar8 = *(uint *)(param_1 + 0x38);
      if (uVar8 < 0x1771) {
        uVar8 = 6000;
      }
      if (10999 < uVar8) {
        uVar8 = 11000;
      }
      uVar1 = (uVar8 - 6000 >> 1 & 0x7fff) / 0x7d + 5;
      _printk(&DAT_00137ecf,"haptic_hv",0x174,"aw8693xs_set_bst_vol",uVar8,uVar1 & 0xff);
      haptic_hv_i2c_write_bits(param_1,6,0xffffffe0,uVar1);
      haptic_hv_i2c_write_bits(param_1,0x18,0xffffff9f,0);
      if ((bVar3 >> 2 & 1) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 4;
      }
      haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar7);
      goto LAB_00120ef8;
    }
    puVar6 = &DAT_00132b34;
    uVar7 = 0x509;
  }
  _printk(puVar6,"haptic_hv",uVar7,"aw8693xs_ram_get_f0");
  uVar5 = 0xffffffde;
LAB_00120ef8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// aw8693xs_creat_node @ 00120f30 size=100
// signature: undefined aw8693xs_creat_node(void)
// callers: []
//------------------------------------------------------------

int aw8693xs_creat_node(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),aw8693xs_vibrator_attribute_group);
  if (iVar1 < 0) {
    _printk(&DAT_00131ce5,"haptic_hv",0x87b,"aw8693xs_creat_node");
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw8693xs_offset_cali @ 00120f98 size=244
// signature: undefined aw8693xs_offset_cali(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_offset_cali(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = aw8693xs_offset_os_code(param_1,0);
  _printk(&DAT_00137f06,"haptic_hv",0x60d,"aw8693xs_offset_cali",iVar1);
  if (iVar1 - 0x10U < 0xffffffe1) {
    _printk(&DAT_00134dd1,"haptic_hv",0x60f,"aw8693xs_offset_cali");
    sw_reset(param_1);
  }
  iVar1 = aw8693xs_offset_os_code(param_1,1);
  _printk(&DAT_0013302f,"haptic_hv",0x614,"aw8693xs_offset_cali",iVar1);
  if (iVar1 - 0x10U < 0xffffffe1) {
    _printk(&DAT_00133054,"haptic_hv",0x616,"aw8693xs_offset_cali");
    uVar2 = 0xffffffde;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw8693xs_get_irq_state @ 00121090 size=440
// signature: undefined aw8693xs_get_irq_state(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_irq_state(undefined8 param_1)

{
  long lVar1;
  undefined4 uVar2;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  if ((char)local_1c[0] < '\0') {
    _printk(&DAT_00131b4f,"haptic_hv",0x459,"aw8693xs_get_irq_state");
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  if ((local_1c[0] >> 6 & 1) != 0) {
    _printk(&DAT_001373ce,"haptic_hv",0x45e,"aw8693xs_get_irq_state");
    uVar2 = 4;
  }
  if ((local_1c[0] >> 5 & 1) != 0) {
    _printk(&DAT_001322d2,"haptic_hv",0x463,"aw8693xs_get_irq_state");
    uVar2 = 5;
  }
  if ((local_1c[0] >> 2 & 1) != 0) {
    _printk(&DAT_00131f4e,"haptic_hv",0x468,"aw8693xs_get_irq_state");
    uVar2 = 6;
  }
  if ((local_1c[0] >> 1 & 1) != 0) {
    _printk(&DAT_00133f06,"haptic_hv",0x46d,"aw8693xs_get_irq_state");
    uVar2 = 7;
  }
  if ((local_1c[0] & 1) != 0) {
    _printk(&DAT_001317d9,"haptic_hv",0x472,"aw8693xs_get_irq_state");
    uVar2 = 10;
  }
  if ((local_1c[0] >> 3 & 1) != 0) {
    _printk(&DAT_00131f9b,"haptic_hv",0x477,"aw8693xs_get_irq_state");
    uVar2 = 2;
  }
  lVar1 = sp_el0;
  if ((local_1c[0] & 0x10) != 0) {
    uVar2 = 1;
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_check_qualify @ 0012124c size=172
// signature: undefined aw8693xs_check_qualify(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_check_qualify(undefined8 param_1)

{
  long lVar1;
  undefined8 uVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,0x67,local_1c,1);
  if (local_1c[0] < '\0') {
    _printk(&DAT_00134387,"haptic_hv",0x141,"aw8693xs_check_qualify");
    uVar2 = 0;
  }
  else {
    _printk(&DAT_00132ca5,"haptic_hv",0x13e,"aw8693xs_check_qualify");
    uVar2 = 0xffffffde;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_judge_rtp_going @ 001212fc size=144
// signature: undefined aw8693xs_judge_rtp_going(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_judge_rtp_going(undefined8 param_1)

{
  long lVar1;
  bool bVar2;
  char local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = '\0';
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  bVar2 = local_1c[0] == '\b';
  if (bVar2) {
    _printk(&DAT_0013728f,"haptic_hv",0x3de,"aw8693xs_judge_rtp_going");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_container_update @ 00121390 size=884
// signature: undefined aw8693xs_container_update(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_container_update(long param_1,int *param_2)

{
  ushort uVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  byte local_460;
  undefined1 local_45f;
  byte local_45e;
  ushort local_45c [2];
  char local_458 [1024];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  memset(local_458,0,0x400);
  mutex_lock(param_1 + 0x350);
  *(undefined2 *)(param_1 + 0x526) = 0x204;
  aw8693xs_stop(param_1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  uVar1 = *(ushort *)((long)param_2 + (ulong)*(byte *)(param_1 + 0x527) + 4);
  *(uint *)(param_1 + 0x520) = (uint)(uVar1 >> 8) | (uVar1 & 0xff00ff) << 8;
  _printk(&DAT_00136e85,"haptic_hv",0x65a,"aw8693xs_container_update");
  uVar7 = *(uint *)(param_1 + 0x520);
  iVar5 = uVar7 - (uVar7 >> 2);
  local_460 = (byte)(uVar7 >> 5) & 0xf0 | (byte)((uint)iVar5 >> 8) & 0xf;
  local_45e = (byte)iVar5;
  local_45f = (undefined1)(uVar7 >> 1);
  haptic_hv_i2c_writes(param_1,0x2f,&local_460,3);
  haptic_hv_i2c_reads(param_1,0x2f,&local_460,3);
  _printk(&DAT_001344e9,"haptic_hv",0x668,"aw8693xs_container_update",
          CONCAT11(local_460 >> 4,local_45f));
  _printk(&DAT_001351c2,"haptic_hv",0x66b,"aw8693xs_container_update",
          (uint)local_45e | (local_460 & 0xf) << 8);
  uVar7 = *(uint *)(param_1 + 0x520);
  local_45c[0] = (ushort)(uVar7 >> 8) & 0xff | (ushort)((uVar7 & 0xff00ff) << 8);
  haptic_hv_i2c_write_bits(param_1,0x2d,0xffffffe0,uVar7 >> 8);
  haptic_hv_i2c_writes(param_1,0x2e,(ulong)local_45c | 1,1);
  local_45c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_45c,2);
  uVar7 = (uint)*(byte *)(param_1 + 0x526);
  iVar5 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar5) {
    do {
      iVar8 = iVar5 - uVar7;
      if (0x7ff < iVar8) {
        iVar8 = 0x800;
      }
      haptic_hv_i2c_writes(param_1,0x42,(long)param_2 + (long)(int)uVar7 + 4,iVar8);
      iVar5 = *param_2;
      uVar7 = iVar8 + uVar7;
    } while ((int)uVar7 < iVar5);
  }
  local_45c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_45c,2);
  uVar7 = (uint)*(byte *)(param_1 + 0x526);
  iVar5 = *param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x526) < iVar5) {
    do {
      uVar9 = iVar5 - uVar7;
      if (0x3ff < (int)uVar9) {
        uVar9 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,local_458,uVar9);
      if (uVar9 != 0) {
        uVar4 = 0;
        do {
          if (0x3ff < uVar4) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x121700);
            (*pcVar3)();
          }
          if (local_458[(int)uVar4] !=
              *(char *)((long)param_2 + (long)(int)uVar4 + (long)(int)uVar7 + 4)) {
            _printk(&DAT_001373f1,"haptic_hv",0x636,"aw8693xs_check_ram_data");
            _printk(&DAT_001351ee,"haptic_hv",0x68a,"aw8693xs_container_update");
            uVar6 = 0xffffffde;
            goto LAB_001216a8;
          }
          uVar4 = uVar4 + 1;
        } while (uVar9 != uVar4);
      }
      iVar5 = *param_2;
      uVar7 = uVar9 + uVar7;
    } while ((int)uVar7 < iVar5);
  }
  _printk(&DAT_00132afb,"haptic_hv",0x68c,"aw8693xs_container_update");
  uVar6 = 0;
LAB_001216a8:
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  mutex_unlock(param_1 + 0x350);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// aw8693xs_stop @ 00121708 size=376
// signature: undefined aw8693xs_stop(void)
// callers: [aw8693xs_ram_get_f0, aw8693xs_container_update, aw8693xs_get_vbat, aw8693xs_get_f0, aw8693xs_get_lra_resistance]
//------------------------------------------------------------

void aw8693xs_stop(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x28a,"aw8693xs_stop");
  *(undefined1 *)(param_1 + 0xb) = 0;
  local_30[0] = 2;
  haptic_hv_i2c_writes(param_1,9,local_30,1);
  iVar3 = -100;
  do {
    local_2c[0] = '\0';
    haptic_hv_i2c_reads(param_1,0x3f,local_2c,1);
    if (local_2c[0] == '\0') {
      _printk(&DAT_00136940,"haptic_hv",0x1ee,"aw8693xs_wait_enter_standby");
      goto LAB_00121854;
    }
    usleep_range_state(2000,0x9c4,2);
    bVar2 = iVar3 != -1;
    iVar3 = iVar3 + 1;
  } while (bVar2);
  _printk(&DAT_00137ca1,"haptic_hv",499,"aw8693xs_wait_enter_standby");
  _printk(&DAT_00135cf9,"haptic_hv",0x290,"aw8693xs_stop");
  _printk(&DAT_00134895,"haptic_hv",0x238,"aw8693xs_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 0;
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0);
LAB_00121854:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_get_vbat @ 00121884 size=436
// signature: undefined aw8693xs_get_vbat(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_vbat(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined2 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  aw8693xs_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_2c,2);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  uVar1 = (uint)local_2c._1_1_ | ((byte)local_2c & 3) << 8;
  uVar2 = uVar1 * 0x17d4;
  uVar4 = (ulong)uVar2 / 0x3ff;
  *(uint *)(param_1 + 0x70) = uVar2 / 0x3ff;
  if (0x46426a < uVar2) {
    *(undefined4 *)(param_1 + 0x70) = 0x1194;
    _printk(&DAT_001328b9,"haptic_hv",0x5be,"aw8693xs_get_vbat",0x1194);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  if ((uint)uVar4 < 3000) {
    *(undefined4 *)(param_1 + 0x70) = 3000;
    _printk(&DAT_00135218,"haptic_hv",0x5c2,"aw8693xs_get_vbat",3000);
    uVar4 = (ulong)*(uint *)(param_1 + 0x70);
  }
  _printk(&DAT_00135e49,"haptic_hv",0x5c4,"aw8693xs_get_vbat",uVar4,uVar1);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_cont_config @ 00121a3c size=392
// signature: undefined aw8693xs_cont_config(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_cont_config(long param_1)

{
  long lVar1;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0xff;
  _printk(&DAT_001331a6,"haptic_hv",0x268,"aw8693xs_play_mode");
  *(undefined1 *)(param_1 + 0xb) = 4;
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,2);
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
  _printk(&DAT_00135b17,"haptic_hv",0x202,"aw8693xs_bst_mode_config");
  haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff7f,0x80);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff7f,(ulong)*(byte *)(param_1 + 0x588) << 7);
  haptic_hv_i2c_write_bits(param_1,0x1d,0xffffff80,*(undefined1 *)(param_1 + 0x562));
  haptic_hv_i2c_writes(param_1,0x1e,param_1 + 0x563,1);
  haptic_hv_i2c_writes(param_1,0x20,local_40,1);
  _printk(&DAT_00133f37,"haptic_hv",0x1db,"aw8693xs_play_go",1);
  local_3c[0] = 1;
  haptic_hv_i2c_writes(param_1,9,local_3c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_play_go @ 00121bc8 size=152
// signature: undefined aw8693xs_play_go(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_play_go(undefined8 param_1,uint param_2)

{
  long lVar1;
  undefined1 uVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar2 = 1;
  if ((param_2 & 1) == 0) {
    uVar2 = 2;
  }
  _printk(&DAT_00133f37,"haptic_hv",0x1db,"aw8693xs_play_go",param_2 & 1);
  local_2c[0] = uVar2;
  haptic_hv_i2c_writes(param_1,9,local_2c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_ram_init @ 00121c64 size=80
// signature: undefined aw8693xs_ram_init(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_ram_init(undefined8 param_1,ulong param_2)

{
  if ((param_2 & 1) == 0) {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  }
  else {
    haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
    usleep_range_state(500,600,2);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_set_bst_peak_cur @ 00121cb8 size=4
// signature: undefined aw8693xs_set_bst_peak_cur(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_bst_peak_cur(void)

{
  return;
}



//------------------------------------------------------------
// aw8693xs_get_lra_resistance @ 00121cc0 size=412
// signature: undefined aw8693xs_get_lra_resistance(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_lra_resistance(long param_1)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  byte local_40 [4];
  undefined2 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40[0] = 0;
  local_3c = 0;
  aw8693xs_stop();
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x18);
  haptic_hv_i2c_reads(param_1,0x4d,local_40,1);
  bVar2 = local_40[0];
  haptic_hv_i2c_reads(param_1,0x4e,local_40,1);
  bVar3 = local_40[0];
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,4);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff0,5);
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffff3,bVar2 & 0xc);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xfffffff8,bVar3 & 7);
  haptic_hv_i2c_reads(param_1,0x4f,&local_3c,2);
  *(uint *)(param_1 + 0x6c) = (((uint)local_3c._1_1_ | ((byte)local_3c & 3) << 8) * 610000) / 0x27f6
  ;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_set_pwm @ 00121e60 size=164
// signature: undefined aw8693xs_set_pwm(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_pwm(undefined8 param_1,undefined1 param_2)

{
  undefined8 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = 0x20;
    break;
  case 1:
    uVar1 = 0;
    break;
  case 2:
    uVar1 = 0x40;
    break;
  case 3:
    uVar1 = 0x60;
    break;
  default:
    _printk(&DAT_00132ff4,"haptic_hv",0x15e,"aw8693xs_set_pwm");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,0x46,0xffffff9f,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693xs_set_gain @ 00121f08 size=88
// signature: undefined aw8693xs_set_gain(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_gain(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_2;
  haptic_hv_i2c_writes(param_1,7,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_play_mode @ 00121f64 size=656
// signature: undefined aw8693xs_play_mode(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_play_mode(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  
  switch(param_2) {
  case 0:
    _printk(&DAT_00134895,"haptic_hv",0x238,"aw8693xs_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 0;
    haptic_hv_i2c_write_bits(param_1,0x45,0xffffffdf,0x20);
    uVar2 = 0x45;
    uVar1 = 0xffffffdf;
    goto LAB_00122108;
  case 1:
    _printk(&DAT_00136db2,"haptic_hv",0x242,"aw8693xs_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 1;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,0);
    uVar2 = 0;
    break;
  case 2:
    _printk(&DAT_00131f7b,"haptic_hv",0x256,"aw8693xs_play_mode");
    *(undefined1 *)(param_1 + 0xb) = 2;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,1);
    uVar2 = 4;
    break;
  case 3:
    _printk(&DAT_00137446,"haptic_hv",0x260,"aw8693xs_play_mode");
    uVar2 = 8;
    uVar1 = 0xfffffffc;
    uVar3 = 0;
    *(undefined1 *)(param_1 + 0xb) = 3;
    goto LAB_001220f8;
  case 4:
    _printk(&DAT_001331a6,"haptic_hv",0x268,"aw8693xs_play_mode");
    uVar4 = 4;
    uVar2 = 2;
    goto LAB_00122184;
  case 5:
    _printk(&DAT_001348b9,"haptic_hv",0x24c,"aw8693xs_play_mode");
    uVar4 = 5;
    uVar2 = 0;
LAB_00122184:
    *(undefined1 *)(param_1 + 0xb) = uVar4;
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffc,uVar2);
    haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,4);
    _printk(&DAT_00135b17,"haptic_hv",0x202,"aw8693xs_bst_mode_config");
    haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,0);
    uVar2 = 0x4d;
    uVar1 = 0xffffff7f;
    uVar3 = 0x80;
    goto LAB_001221e0;
  default:
    _printk(&DAT_001348de,"haptic_hv",0x272,"aw8693xs_play_mode");
    return;
  }
  haptic_hv_i2c_write_bits(param_1,8,0xfffffffb,uVar2);
  uVar2 = 6;
  uVar1 = 0xffffffdf;
  uVar3 = 0x20;
LAB_001220f8:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar1,uVar3);
  uVar2 = 0x4d;
  uVar1 = 0xffffff7f;
LAB_00122108:
  uVar3 = 0;
LAB_001221e0:
  haptic_hv_i2c_write_bits(param_1,uVar2,uVar1,uVar3);
  return;
}



//------------------------------------------------------------
// aw8693xs_set_bst_vol @ 001221f8 size=144
// signature: undefined aw8693xs_set_bst_vol(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_bst_vol(undefined8 param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < 0x1771) {
    param_2 = 6000;
  }
  if (10999 < param_2) {
    param_2 = 11000;
  }
  uVar1 = (param_2 - 6000 >> 1 & 0x7fff) / 0x7d + 5;
  _printk(&DAT_00137ecf,"haptic_hv",0x174,"aw8693xs_set_bst_vol",param_2,uVar1 & 0xff);
  haptic_hv_i2c_write_bits(param_1,6,0xffffffe0,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693xs_set_repeat_seq @ 0012228c size=120
// signature: undefined aw8693xs_set_repeat_seq(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_repeat_seq(undefined8 param_1,undefined1 param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = param_2;
  haptic_hv_i2c_writes(param_1,10,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x12,0xffffff0f,0xf0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_auto_bst_enable @ 00122308 size=52
// signature: undefined aw8693xs_auto_bst_enable(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_auto_bst_enable(long param_1,char param_2)

{
  *(char *)(param_1 + 0xc) = param_2;
  haptic_hv_i2c_write_bits(param_1,8,0xffffffef,(ulong)(param_2 != '\0') << 4);
  return;
}



//------------------------------------------------------------
// aw8693xs_vbat_mode_config @ 00122340 size=52
// signature: undefined aw8693xs_vbat_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_vbat_mode_config(undefined8 param_1,char param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffff80;
  if (param_2 != '\x01') {
    uVar1 = 0;
  }
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff7f,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693xs_set_wav_seq @ 00122378 size=88
// signature: undefined aw8693xs_set_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_wav_seq(undefined8 param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = param_3;
  haptic_hv_i2c_writes(param_1,param_2 + 10,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_set_wav_loop @ 001223d4 size=64
// signature: undefined aw8693xs_set_wav_loop(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_wav_loop(undefined8 param_1,uint param_2,int param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    param_3 = param_3 << 4;
    uVar1 = 0xffffff0f;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  haptic_hv_i2c_write_bits(param_1,(param_2 >> 1 & 0x7f) + 0x12,uVar1,param_3);
  return;
}



//------------------------------------------------------------
// aw8693xs_set_rtp_data @ 00122418 size=40
// signature: undefined aw8693xs_set_rtp_data(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_rtp_data(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  haptic_hv_i2c_writes(param_1,0x32,param_2,param_3);
  return;
}



//------------------------------------------------------------
// aw8693xs_protect_config @ 00122444 size=256
// signature: undefined aw8693xs_protect_config(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_protect_config(undefined8 param_1,undefined1 param_2,byte param_3)

{
  long lVar1;
  byte local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = param_2;
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  if (param_3 == 0) {
    _printk(&DAT_00136dd2,"haptic_hv",0x2cd,"aw8693xs_protect_config");
    haptic_hv_i2c_write_bits(param_1,0x4a,0xffffff7f,0);
  }
  else {
    _printk(&DAT_00136330,"haptic_hv",0x2c6,"aw8693xs_protect_config");
    local_40[0] = param_3 | 0x80;
    haptic_hv_i2c_writes(param_1,0x4a,local_40,1);
    haptic_hv_i2c_writes(param_1,0x4b,local_3c,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_parse_dt @ 00122548 size=1532
// signature: undefined aw8693xs_parse_dt(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_parse_dt(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined2 local_54;
  undefined1 local_52;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_52 = 0;
  local_54 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_gain_bypass",param_2 + 0x55f,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013510e,"haptic_hv",0x6b3,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw8693xs_uvlo_vol_default",param_2 + 0x560,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013475d,"haptic_hv",0x6b7,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"f0_pre",param_2 + 0x530,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001377fb,"haptic_hv",0x6bb,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_f0_cali_percent",param_2 + 0x529,1,0)
  ;
  if (iVar1 < 0) {
    _printk(&DAT_001329b8,"haptic_hv",0x6bf,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_cont_drv1_lvl",param_2 + 0x562,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00136c35,"haptic_hv",0x6c3,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u32_array(param_3,"aw8693xs_cont_lra_vrms",param_2 + 0x584,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00131d2f,"haptic_hv",0x6c7,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_cont_drv1_time",param_2 + 0x566,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001367e9,"haptic_hv",0x6cb,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_cont_drv2_time",param_2 + 0x567,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134183,"haptic_hv",0x6cf,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_cont_brk_time",param_2 + 0x564,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134a88,"haptic_hv",0x6d3,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array
                    (param_3,"aw8693xs_cont_track_margin",param_2 + 0x568,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00134792,"haptic_hv",0x6d8,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_cont_brk_gain",param_2 + 0x565,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001357ed,"haptic_hv",0x6dc,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_d2s_gain",param_2 + 0x55d,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00133df1,"haptic_hv",0x6e0,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_bemf_d2s_gain",param_2 + 0x55e,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137314,"haptic_hv",0x6e4,"aw8693xs_parse_dt");
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_duration_time",&local_54,3,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013513e,"haptic_hv",0x6e9,"aw8693xs_parse_dt");
  }
  else {
    *(undefined2 *)(param_2 + 0x52a) = local_54;
    *(undefined1 *)(param_2 + 0x52c) = local_52;
  }
  iVar1 = of_property_read_variable_u8_array(param_3,"aw8693xs_trig_config",&local_50,0x18,0);
  if (iVar1 < 0) {
    _printk(&DAT_0013581f,"haptic_hv",0x6f0,"aw8693xs_parse_dt");
  }
  else {
    *(undefined8 *)(param_2 + 0x569) = local_50;
    *(undefined8 *)(param_2 + 0x571) = local_48;
    *(undefined8 *)(param_2 + 0x579) = local_40;
  }
  iVar1 = of_property_read_variable_u32_array
                    (param_3,"aw8693xs_bst_vol_default",param_2 + 0x534,1,0);
  if (iVar1 < 0) {
    _printk(&DAT_001347c8,"haptic_hv",0x6f7,"aw8693xs_parse_dt");
  }
  lVar2 = of_find_property(param_3,"aw8693xs_is_enabled_track_en",0);
  *(bool *)(param_2 + 0x588) = lVar2 != 0;
  _printk(&DAT_00132438,"haptic_hv",0x6fb,"aw8693xs_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693xs_is_enabled_inter_brake",0);
  *(bool *)(param_2 + 0x589) = lVar2 != 0;
  _printk(&DAT_001379f3,"haptic_hv",0x6ff,"aw8693xs_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693xs_is_enabled_low_power",0);
  *(bool *)(param_2 + 0x58a) = lVar2 != 0;
  _printk(&DAT_00133e1e,"haptic_hv",0x703,"aw8693xs_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693xs_is_enabled_vbat_pro",0);
  *(bool *)(param_2 + 0x58b) = lVar2 != 0;
  _printk(&DAT_00135eab,"haptic_hv",0x707,"aw8693xs_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693xs_is_enabled_auto_bst",0);
  *(bool *)(param_2 + 0x58c) = lVar2 != 0;
  _printk(&DAT_00136783,"haptic_hv",0x70b,"aw8693xs_parse_dt");
  lVar2 = of_find_property(param_3,"aw8693xs_is_enabled_one_wire",0);
  *(bool *)(param_2 + 0x58e) = lVar2 != 0;
  _printk(&DAT_001372f6,"haptic_hv",0x70f,"aw8693xs_parse_dt");
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_trig_init @ 00122b48 size=940
// signature: undefined aw8693xs_trig_init(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_trig_init(long param_1)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  long lVar4;
  bool bVar5;
  undefined1 local_38 [4];
  byte local_34 [4];
  byte local_30 [4];
  byte local_2c [4];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0x61f,"aw8693xs_trig_init");
  if (*(char *)(param_1 + 0x58e) == '\0') {
    cVar3 = *(char *)(param_1 + 0x569);
    *(undefined1 *)(param_1 + 0x6c9) = *(undefined1 *)(param_1 + 0x56b);
    *(undefined1 *)(param_1 + 0x6cb) = *(undefined1 *)(param_1 + 0x56c);
    *(char *)(param_1 + 0x6c7) = cVar3;
    *(char *)(param_1 + 0x6c8) = *(char *)(param_1 + 0x56a);
    uVar2 = (uint)(cVar3 != '\0') << 6;
    if (*(char *)(param_1 + 0x56a) != '\0') {
      uVar2 = (uint)(cVar3 != '\0') << 6 | 0xffffff80;
    }
    *(undefined1 *)(param_1 + 0x6ca) = *(undefined1 *)(param_1 + 0x56d);
    if (*(char *)(param_1 + 0x56f) != '\0') {
      uVar2 = uVar2 | 0x20;
    }
    if (*(char *)(param_1 + 0x570) != '\0') {
      uVar2 = uVar2 | 0x10;
    }
    *(char *)(param_1 + 0x6c5) = *(char *)(param_1 + 0x56f);
    *(char *)(param_1 + 0x6c6) = *(char *)(param_1 + 0x570);
    *(undefined1 *)(param_1 + 0x6cc) = *(undefined1 *)(param_1 + 0x56e);
    haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar2);
    local_34[0] = *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7;
    haptic_hv_i2c_writes(param_1,0x33,local_34,1);
    local_34[0] = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
    haptic_hv_i2c_writes(param_1,0x36,local_34,1);
  }
  else {
    _printk(&DAT_00136463,"haptic_hv",0x621,"aw8693xs_trig_init");
    _printk(&DAT_00132e8a,"haptic_hv",0x2eb,"aw8693xs_one_wire_init");
    local_38[0] = 0x6c;
    haptic_hv_i2c_writes(param_1,0x3e,local_38,1);
    local_38[0] = 0x75;
    haptic_hv_i2c_writes(param_1,0x3c,local_38,1);
    haptic_hv_i2c_write_bits(param_1,0x3a,0xfffffff7,8);
  }
  cVar3 = *(char *)(param_1 + 0x571);
  *(undefined1 *)(param_1 + 0x6d6) = *(undefined1 *)(param_1 + 0x573);
  *(char *)(param_1 + 0x6d4) = cVar3;
  *(undefined1 *)(param_1 + 0x6d9) = *(undefined1 *)(param_1 + 0x576);
  *(char *)(param_1 + 0x6d5) = *(char *)(param_1 + 0x572);
  *(undefined1 *)(param_1 + 0x6d8) = *(undefined1 *)(param_1 + 0x574);
  *(undefined1 *)(param_1 + 0x6d7) = *(undefined1 *)(param_1 + 0x575);
  *(undefined1 *)(param_1 + 0x6e2) = *(undefined1 *)(param_1 + 0x57a);
  *(char *)(param_1 + 0x6d2) = *(char *)(param_1 + 0x577);
  bVar1 = (cVar3 != '\0') << 2;
  if (*(char *)(param_1 + 0x572) != '\0') {
    bVar1 = (cVar3 != '\0') << 2 | 8;
  }
  *(undefined1 *)(param_1 + 0x6e1) = *(undefined1 *)(param_1 + 0x579);
  *(undefined1 *)(param_1 + 0x6e3) = *(undefined1 *)(param_1 + 0x57b);
  if (*(char *)(param_1 + 0x577) != '\0') {
    bVar1 = bVar1 | 2;
  }
  *(undefined1 *)(param_1 + 0x6e5) = *(undefined1 *)(param_1 + 0x57c);
  *(char *)(param_1 + 0x6d3) = *(char *)(param_1 + 0x578);
  *(undefined1 *)(param_1 + 0x6e6) = *(undefined1 *)(param_1 + 0x57e);
  *(undefined1 *)(param_1 + 0x6e4) = *(undefined1 *)(param_1 + 0x57d);
  *(undefined2 *)(param_1 + 0x6df) = *(undefined2 *)(param_1 + 0x57f);
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x578) != '\0');
  local_30[0] = *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x34,local_30,1);
  local_30[0] = *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x37,local_30,1);
  bVar5 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar2 = (uint)bVar5 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar2 = (uint)bVar5 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar2 = uVar2 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar2 = uVar2 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar2);
  local_2c[0] = *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x35,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x38,local_2c,1);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_irq_clear @ 00122ef8 size=88
// signature: undefined aw8693xs_irq_clear(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_irq_clear(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_set_ram_addr @ 00122f54 size=100
// signature: undefined aw8693xs_set_ram_addr(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_ram_addr(long param_1)

{
  long lVar1;
  ushort local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = *(ushort *)(param_1 + 0x520) >> 8 | *(ushort *)(param_1 + 0x520) << 8;
  haptic_hv_i2c_writes(param_1,0x40,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_misc_para_init @ 00122fbc size=1052
// signature: undefined aw8693xs_misc_para_init(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_misc_para_init(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  byte local_68 [4];
  undefined2 local_64;
  undefined8 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_60 = 0;
  local_68[0] = 0;
  local_64._0_1_ = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5d,&local_64,1);
  haptic_hv_i2c_reads(param_1,0x6a,local_68,1);
  local_64 = (ushort)local_64._1_1_ << 8;
  haptic_hv_i2c_writes(param_1,0x5d,&local_64,1);
  uVar2 = local_68[0] | 0xffffff00;
  if (local_68[0] < 0x81) {
    uVar2 = (uint)local_68[0];
  }
  _printk(&DAT_00135eca,"haptic_hv",0x4f9,"aw8693xs_get_trim_osc_code",uVar2);
  *(uint *)(param_1 + 0x34) = uVar2;
  local_60 = CONCAT71(local_60._1_7_,*(undefined1 *)(*(long *)(param_1 + 0x2c8) + 2));
  haptic_hv_i2c_writes(param_1,0x47,&local_60,1);
  iVar3 = 0x711;
  if (0x707 < *(uint *)(param_1 + 0x530)) {
    iVar3 = 0x7c6;
  }
  uVar2 = (uint)(iVar3 * *(int *)(param_1 + 0x584)) / 40000;
  if (0x7e < uVar2) {
    uVar2 = 0x7f;
  }
  *(char *)(param_1 + 0x563) = (char)uVar2;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x534);
  haptic_hv_i2c_reads(param_1,7,&local_60,1);
  *(uint *)(param_1 + 0x3c) = (uint)(byte)local_60;
  haptic_hv_i2c_reads(param_1,10,&local_60,8);
  *(uint *)(param_1 + 0x4c) = (uint)(byte)local_60;
  *(undefined8 *)(param_1 + 0x11) = local_60;
  haptic_hv_i2c_write_bits(param_1,0x46,0xfffffffe,*(undefined1 *)(param_1 + 0x55f));
  haptic_hv_i2c_write_bits(param_1,0x1c,0xfffffff0,*(undefined1 *)(param_1 + 0x565));
  haptic_hv_i2c_writes(param_1,0x21,param_1 + 0x564,1);
  local_64 = CONCAT11(local_64._1_1_,0x32);
  haptic_hv_i2c_write_bits(param_1,0x48,0xffffff7f,0);
  _printk(&DAT_00136330,"haptic_hv",0x2c6,"aw8693xs_protect_config");
  local_68[0] = 0xbf;
  haptic_hv_i2c_writes(param_1,0x4a,local_68,1);
  haptic_hv_i2c_writes(param_1,0x4b,&local_64,1);
  _printk(&DAT_00132e8a,"haptic_hv",0x211,"aw8693xs_vbat_ref_config");
  haptic_hv_i2c_write_bits(param_1,0x4d,0xffffff8f,0x30);
  local_64 = 0x424;
  _printk(&DAT_0013584f,"haptic_hv",0x71c,"aw8693xs_set_vbat_protect",6000,2);
  _printk(&DAT_00137f69,"haptic_hv",0x71d,"aw8693xs_set_vbat_protect",0x9c4,4);
  haptic_hv_i2c_writes(param_1,0x55,&local_64,1);
  local_64 = 0;
  _printk(&DAT_0013584f,"haptic_hv",0x71c,"aw8693xs_set_vbat_protect",5000,0);
  _printk(&DAT_00137f69,"haptic_hv",0x71d,"aw8693xs_set_vbat_protect",0x5dc,0);
  haptic_hv_i2c_writes(param_1,0x56,&local_64,1);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffbf,(ulong)*(byte *)(param_1 + 0x589) << 6);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffdf,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4c,0xffffffef,0x10);
  haptic_hv_i2c_write_bits(param_1,0x5b,0xffffff8f,(ulong)*(byte *)(param_1 + 0x560) << 4);
  local_60 = CONCAT53(local_60._3_5_,0x4114ea);
  haptic_hv_i2c_writes(param_1,0x54,&local_60,1);
  local_64._0_1_ = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5d,&local_64,1);
  haptic_hv_i2c_writes(param_1,0x7c,(ulong)&local_60 | 1,1);
  haptic_hv_i2c_writes(param_1,0x7f,(ulong)&local_60 | 2,1);
  local_64 = (ushort)local_64._1_1_ << 8;
  haptic_hv_i2c_writes(param_1,0x5d,&local_64,1);
  haptic_hv_i2c_write_bits(param_1,0x54,0xffffffef,(ulong)*(byte *)(param_1 + 0x58b) << 4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_interrupt_setup @ 001233dc size=140
// signature: undefined aw8693xs_interrupt_setup(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_interrupt_setup(undefined8 param_1)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,2,local_2c,1);
  haptic_hv_i2c_write_bits(param_1,0x46,0xffffffe7,8);
  haptic_hv_i2c_write_bits(param_1,3,0xffffff19,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_set_rtp_aei @ 0012346c size=48
// signature: undefined aw8693xs_set_rtp_aei(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_set_rtp_aei(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 & 1) == 0) {
    uVar1 = 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,3,0xffffffef,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693xs_upload_lra @ 001234a0 size=380
// signature: undefined aw8693xs_upload_lra(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_upload_lra(long param_1,int param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined2 *puVar3;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined2 local_2c [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38[0] = 0;
  local_2c[0] = 0x2000;
  local_34[0] = 0x7d;
  haptic_hv_i2c_writes(param_1,0x5d,local_34,1);
  haptic_hv_i2c_writes(param_1,0x60,(ulong)local_2c | 1,1);
  if (param_2 == 2) {
    _printk(&DAT_001323a9,"haptic_hv",0x2a7,"aw8693xs_upload_lra",*(undefined4 *)(param_1 + 0x9c));
    local_38[0] = (undefined1)*(undefined4 *)(param_1 + 0x9c);
  }
  else {
    if (param_2 == 1) {
      _printk(&DAT_001378a9,"haptic_hv",0x2a2,"aw8693xs_upload_lra",*(undefined4 *)(param_1 + 0x90))
      ;
    }
    else {
      if (param_2 == 0) {
        _printk(&DAT_00136e0b,"haptic_hv",0x29e,"aw8693xs_upload_lra");
        puVar3 = local_2c;
        uVar2 = 0x60;
        goto LAB_001235d0;
      }
      _printk(&DAT_00136f7a,"haptic_hv",0x2ac,"aw8693xs_upload_lra");
    }
    local_38[0] = (undefined1)*(undefined4 *)(param_1 + 0x90);
  }
  puVar3 = (undefined2 *)local_38;
  uVar2 = 0x61;
LAB_001235d0:
  haptic_hv_i2c_writes(param_1,uVar2,puVar3,1);
  local_30[0] = 0;
  haptic_hv_i2c_writes(param_1,0x5d,local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_get_wav_seq @ 00123620 size=236
// signature: undefined aw8693xs_get_wav_seq(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_wav_seq(long param_1,uint param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (7 < param_2) {
    param_2 = 8;
  }
  local_30 = 0;
  haptic_hv_i2c_reads(param_1,10,&local_30,param_2);
  if (((((param_2 != 0) && (*(undefined1 *)(param_1 + 0x11) = (undefined1)local_30, param_2 != 1))
       && (*(undefined1 *)(param_1 + 0x12) = local_30._1_1_, param_2 != 2)) &&
      ((*(undefined1 *)(param_1 + 0x13) = local_30._2_1_, param_2 != 3 &&
       (*(undefined1 *)(param_1 + 0x14) = local_30._3_1_, param_2 != 4)))) &&
     ((*(undefined1 *)(param_1 + 0x15) = local_30._4_1_, param_2 != 5 &&
      ((*(undefined1 *)(param_1 + 0x16) = local_30._5_1_, param_2 != 6 &&
       (*(undefined1 *)(param_1 + 0x17) = local_30._6_1_, param_2 != 7)))))) {
    *(undefined1 *)(param_1 + 0x18) = local_30._7_1_;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_get_ram_data @ 00123710 size=120
// signature: undefined aw8693xs_get_ram_data(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_ram_data(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x518);
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar1 - uVar2;
      if (0x3ff < uVar3) {
        uVar3 = 0x400;
      }
      haptic_hv_i2c_reads(param_1,0x42,param_2 + (int)uVar2,uVar3);
      uVar1 = *(uint *)(param_1 + 0x518);
      uVar2 = uVar3 + uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_bst_mode_config @ 0012378c size=164
// signature: undefined aw8693xs_bst_mode_config(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_bst_mode_config(undefined8 param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_2 == '\x01') {
    uVar1 = 0x20;
  }
  else {
    if (param_2 != '\0') {
      _printk(&DAT_00134a38,"haptic_hv",0x208,"aw8693xs_bst_mode_config",param_2);
      return;
    }
    _printk(&DAT_00135b17,"haptic_hv",0x202,"aw8693xs_bst_mode_config");
    uVar1 = 0;
  }
  haptic_hv_i2c_write_bits(param_1,6,0xffffffdf,uVar1);
  return;
}



//------------------------------------------------------------
// aw8693xs_get_first_wave_addr @ 00123834 size=112
// signature: undefined aw8693xs_get_first_wave_addr(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_first_wave_addr(undefined8 param_1,undefined2 *param_2)

{
  long lVar1;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c._0_3_ = 0;
  haptic_hv_i2c_reads(param_1,0x42,local_2c,3);
  *param_2 = local_2c._1_2_;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_get_wav_loop @ 001238a8 size=420
// signature: undefined aw8693xs_get_wav_loop(void)
// callers: []
//------------------------------------------------------------

long aw8693xs_get_wav_loop(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  haptic_hv_i2c_reads(param_1,0x12,&local_4c,4);
  *(byte *)(param_1 + 0x19) = (byte)local_4c >> 4;
  *(byte *)(param_1 + 0x1a) = (byte)local_4c & 0xf;
  iVar2 = snprintf(param_2,0x1000,"seq%d loop: 0x%02x\n",1,(uint)((byte)local_4c >> 4));
  lVar3 = (long)iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",2,
                   (uint)*(byte *)(param_1 + 0x1a));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1b) = local_4c._1_1_ >> 4;
  *(byte *)(param_1 + 0x1c) = local_4c._1_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",3,
                   (uint)(local_4c._1_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",4,
                   (uint)*(byte *)(param_1 + 0x1c));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1d) = local_4c._2_1_ >> 4;
  *(byte *)(param_1 + 0x1e) = local_4c._2_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",5,
                   (uint)(local_4c._2_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",6,
                   (uint)*(byte *)(param_1 + 0x1e));
  lVar3 = lVar3 + iVar2;
  *(byte *)(param_1 + 0x1f) = local_4c._3_1_ >> 4;
  *(byte *)(param_1 + 0x20) = local_4c._3_1_ & 0xf;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",7,
                   (uint)(local_4c._3_1_ >> 4));
  lVar3 = lVar3 + iVar2;
  iVar2 = snprintf(param_2 + lVar3,0x1000 - lVar3,"seq%d loop: 0x%02x\n",8,
                   (uint)*(byte *)(param_1 + 0x20));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw8693xs_get_reg @ 00123a50 size=292
// signature: undefined aw8693xs_get_reg(void)
// callers: []
//------------------------------------------------------------

long aw8693xs_get_reg(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  byte local_d8 [144];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_d8[0x88] = 0;
  local_d8[0x89] = 0;
  local_d8[0x8a] = 0;
  local_d8[0x8b] = 0;
  local_d8[0x8c] = 0;
  local_d8[0x8d] = 0;
  local_d8[0x78] = 0;
  local_d8[0x79] = 0;
  local_d8[0x7a] = 0;
  local_d8[0x7b] = 0;
  local_d8[0x7c] = 0;
  local_d8[0x7d] = 0;
  local_d8[0x7e] = 0;
  local_d8[0x7f] = 0;
  local_d8[0x80] = 0;
  local_d8[0x81] = 0;
  local_d8[0x82] = 0;
  local_d8[0x83] = 0;
  local_d8[0x84] = 0;
  local_d8[0x85] = 0;
  local_d8[0x86] = 0;
  local_d8[0x87] = 0;
  local_d8[0x68] = 0;
  local_d8[0x69] = 0;
  local_d8[0x6a] = 0;
  local_d8[0x6b] = 0;
  local_d8[0x6c] = 0;
  local_d8[0x6d] = 0;
  local_d8[0x6e] = 0;
  local_d8[0x6f] = 0;
  local_d8[0x70] = 0;
  local_d8[0x71] = 0;
  local_d8[0x72] = 0;
  local_d8[0x73] = 0;
  local_d8[0x74] = 0;
  local_d8[0x75] = 0;
  local_d8[0x76] = 0;
  local_d8[0x77] = 0;
  local_d8[0x58] = 0;
  local_d8[0x59] = 0;
  local_d8[0x5a] = 0;
  local_d8[0x5b] = 0;
  local_d8[0x5c] = 0;
  local_d8[0x5d] = 0;
  local_d8[0x5e] = 0;
  local_d8[0x5f] = 0;
  local_d8[0x60] = 0;
  local_d8[0x61] = 0;
  local_d8[0x62] = 0;
  local_d8[99] = 0;
  local_d8[100] = 0;
  local_d8[0x65] = 0;
  local_d8[0x66] = 0;
  local_d8[0x67] = 0;
  local_d8[0x48] = 0;
  local_d8[0x49] = 0;
  local_d8[0x4a] = 0;
  local_d8[0x4b] = 0;
  local_d8[0x4c] = 0;
  local_d8[0x4d] = 0;
  local_d8[0x4e] = 0;
  local_d8[0x4f] = 0;
  local_d8[0x50] = 0;
  local_d8[0x51] = 0;
  local_d8[0x52] = 0;
  local_d8[0x53] = 0;
  local_d8[0x54] = 0;
  local_d8[0x55] = 0;
  local_d8[0x56] = 0;
  local_d8[0x57] = 0;
  local_d8[0x38] = 0;
  local_d8[0x39] = 0;
  local_d8[0x3a] = 0;
  local_d8[0x3b] = 0;
  local_d8[0x3c] = 0;
  local_d8[0x3d] = 0;
  local_d8[0x3e] = 0;
  local_d8[0x3f] = 0;
  local_d8[0x40] = 0;
  local_d8[0x41] = 0;
  local_d8[0x42] = 0;
  local_d8[0x43] = 0;
  local_d8[0x44] = 0;
  local_d8[0x45] = 0;
  local_d8[0x46] = 0;
  local_d8[0x47] = 0;
  local_d8[0x28] = 0;
  local_d8[0x29] = 0;
  local_d8[0x2a] = 0;
  local_d8[0x2b] = 0;
  local_d8[0x2c] = 0;
  local_d8[0x2d] = 0;
  local_d8[0x2e] = 0;
  local_d8[0x2f] = 0;
  local_d8[0x30] = 0;
  local_d8[0x31] = 0;
  local_d8[0x32] = 0;
  local_d8[0x33] = 0;
  local_d8[0x34] = 0;
  local_d8[0x35] = 0;
  local_d8[0x36] = 0;
  local_d8[0x37] = 0;
  local_d8[0x18] = 0;
  local_d8[0x19] = 0;
  local_d8[0x1a] = 0;
  local_d8[0x1b] = 0;
  local_d8[0x1c] = 0;
  local_d8[0x1d] = 0;
  local_d8[0x1e] = 0;
  local_d8[0x1f] = 0;
  local_d8[0x20] = 0;
  local_d8[0x21] = 0;
  local_d8[0x22] = 0;
  local_d8[0x23] = 0;
  local_d8[0x24] = 0;
  local_d8[0x25] = 0;
  local_d8[0x26] = 0;
  local_d8[0x27] = 0;
  local_d8[8] = 0;
  local_d8[9] = 0;
  local_d8[10] = 0;
  local_d8[0xb] = 0;
  local_d8[0xc] = 0;
  local_d8[0xd] = 0;
  local_d8[0xe] = 0;
  local_d8[0xf] = 0;
  local_d8[0x10] = 0;
  local_d8[0x11] = 0;
  local_d8[0x12] = 0;
  local_d8[0x13] = 0;
  local_d8[0x14] = 0;
  local_d8[0x15] = 0;
  local_d8[0x16] = 0;
  local_d8[0x17] = 0;
  local_d8[0] = 0;
  local_d8[1] = 0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d8[4] = 0;
  local_d8[5] = 0;
  local_d8[6] = 0;
  local_d8[7] = 0;
  haptic_hv_i2c_reads(param_1,0,local_d8,0x32);
  haptic_hv_i2c_reads(param_1,0x33,local_d8 + 0x33,0xf);
  haptic_hv_i2c_reads(param_1,0x43,local_d8 + 0x43,0x4b);
  lVar3 = 0;
  do {
    uVar1 = (uint)lVar3 & 0xff;
    if ((uVar1 != 0x32) && (uVar1 != 0x42)) {
      iVar2 = snprintf((char *)(param_3 + param_2),0x1000 - param_2,"reg:0x%02X=0x%02X\n",
                       (uint)lVar3,(uint)local_d8[lVar3]);
      param_2 = param_2 + iVar2;
    }
    lVar3 = lVar3 + 1;
  } while (lVar3 != 0x8e);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// aw8693xs_get_prctmode @ 00123b78 size=96
// signature: undefined aw8693xs_get_prctmode(void)
// callers: []
//------------------------------------------------------------

byte aw8693xs_get_prctmode(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x4a,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 7;
}



//------------------------------------------------------------
// aw8693xs_get_trim_lra @ 00123bdc size=92
// signature: undefined aw8693xs_get_trim_lra(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_trim_lra(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x61,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_get_glb_state @ 00123c3c size=92
// signature: undefined aw8693xs_get_glb_state(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_glb_state(undefined8 param_1)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x3f,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_1c[0]);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_get_osc_status @ 00123c9c size=96
// signature: undefined aw8693xs_get_osc_status(void)
// callers: []
//------------------------------------------------------------

byte aw8693xs_get_osc_status(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,4,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] & 1;
}



//------------------------------------------------------------
// aw8693xs_rtp_get_fifo_afs @ 00123d00 size=96
// signature: undefined aw8693xs_rtp_get_fifo_afs(void)
// callers: []
//------------------------------------------------------------

byte aw8693xs_rtp_get_fifo_afs(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 3 & 1;
}



//------------------------------------------------------------
// aw8693xs_rtp_get_fifo_aes @ 00123d64 size=96
// signature: undefined aw8693xs_rtp_get_fifo_aes(void)
// callers: []
//------------------------------------------------------------

byte aw8693xs_rtp_get_fifo_aes(undefined8 param_1)

{
  long lVar1;
  byte local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  haptic_hv_i2c_reads(param_1,1,local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1c[0] >> 4 & 1;
}



//------------------------------------------------------------
// aw8693xs_get_theory_time @ 00123dc8 size=88
// signature: undefined aw8693xs_get_theory_time(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_theory_time(undefined8 param_1)

{
  long lVar1;
  byte local_2c [4];
  undefined8 local_28;
  
  lVar1 = sp_el0;
  local_28 = *(undefined8 *)(lVar1 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x46,local_2c,1);
                    /* WARNING: Could not recover jumptable at 0x00123e1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&UNK_00123e20 + (ulong)(byte)(&DAT_0012e682)[local_2c[0] >> 5 & 3] * 4))();
  return;
}



//------------------------------------------------------------
// aw8693xs_get_bemf_peak @ 00123ef0 size=624
// signature: undefined aw8693xs_get_bemf_peak(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_get_bemf_peak(long param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined4 local_50;
  undefined2 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_4c = 0;
  local_50 = 0;
  haptic_hv_i2c_reads(param_1,0x29,&local_50,4);
  *param_2 = (byte)local_50 & 3 | (ushort)local_50._1_1_ << 8;
  param_2[1] = (byte)local_50 & 0xc | (ushort)local_50._2_1_ << 8;
  param_2[2] = (ushort)local_50 & 0x30 | (ushort)local_50._3_1_ << 8;
  haptic_hv_i2c_reads(param_1,0x8b,&local_50,3);
  param_2[3] = local_50._2_1_ & 3 | (ushort)(byte)local_50 << 8;
  param_2[4] = local_50._2_1_ & 0xc | (ushort)local_50._1_1_ << 8;
  _printk(&DAT_00132141,"haptic_hv",0x41a,"aw8693xs_get_bemf_peak",0,*param_2);
  _printk(&DAT_00132141,"haptic_hv",0x41a,"aw8693xs_get_bemf_peak",1,param_2[1]);
  _printk(&DAT_00132141,"haptic_hv",0x41a,"aw8693xs_get_bemf_peak",2,param_2[2]);
  _printk(&DAT_00132141,"haptic_hv",0x41a,"aw8693xs_get_bemf_peak",3,param_2[3]);
  _printk(&DAT_00132141,"haptic_hv",0x41a,"aw8693xs_get_bemf_peak",4,param_2[4]);
  haptic_hv_i2c_reads(param_1,0x85,&local_50,6);
  uVar1 = (uint)(byte)local_4c & ((byte)local_4c >> 4) - 1 & 0xf |
          ((local_50 >> 8 & 0xff) + (local_50 & 0xff)) * 0x10;
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = 0x3a9800 / uVar1;
  }
  *(uint *)(param_1 + 100) = uVar2;
  _printk(&DAT_00132d28,"haptic_hv",0x41f,"aw8693xs_get_bemf_peak");
  uVar1 = (uint)(byte)local_4c & (local_4c._1_1_ >> 4) - 1 & 0xf |
          ((local_50 >> 0x10 & 0xff) + (local_50 >> 8 & 0xff)) * 0x10;
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = 0x3a9800 / uVar1;
  }
  *(uint *)(param_1 + 100) = uVar2;
  _printk(&DAT_00134819,"haptic_hv",0x422,"aw8693xs_get_bemf_peak");
  uVar1 = local_4c._1_1_ + 0xf & (uint)(local_4c._1_1_ >> 4) |
          ((local_50 >> 0x18) + (local_50 >> 0x10 & 0xff)) * 0x10;
  uVar2 = 0;
  if (uVar1 != 0) {
    uVar2 = 0x3a9800 / uVar1;
  }
  *(uint *)(param_1 + 100) = uVar2;
  _printk(&DAT_0013625c,"haptic_hv",0x425,"aw8693xs_get_bemf_peak");
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_snd_soc_init @ 00124164 size=200
// signature: undefined aw8693xs_snd_soc_init(void)
// callers: []
//------------------------------------------------------------

int aw8693xs_snd_soc_init(undefined8 param_1)

{
  int iVar1;
  void *__dest;
  
  __dest = (void *)devm_kmalloc(param_1,0xe0,0xdc0);
  if (__dest == (void *)0x0) {
    iVar1 = -0xc;
  }
  else {
    memcpy(__dest,&aw8693xs_dai,0xe0);
    _printk(&DAT_00134c88,"haptic_hv",0x11c,"aw8693xs_snd_soc_init","aw8693xs-aif");
    iVar1 = snd_soc_register_component(param_1,soc_codec_dev_aw8693xs,__dest,1);
    if (iVar1 < 0) {
      _printk(&DAT_00135b95,"haptic_hv",0x121,"aw8693xs_snd_soc_init",iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// aw8693xs_read_f0 @ 0012422c size=316
// signature: undefined aw8693xs_read_f0(void)
// callers: [aw8693xs_ram_get_f0, aw8693xs_get_f0]
//------------------------------------------------------------

void aw8693xs_read_f0(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined *puVar4;
  undefined8 uVar5;
  ushort local_2c [2];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = 0;
  haptic_hv_i2c_reads(param_1,0x25,local_2c,2);
  uVar1 = (uint)(local_2c[0] >> 8) | (local_2c[0] & 0xff00ff) << 8;
  if (uVar1 == 0) {
    puVar4 = &DAT_00137bb0;
    uVar5 = 0x48b;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  else {
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 0x3a9800 / uVar1;
    }
    *(uint *)(param_1 + 100) = uVar2;
    _printk(&DAT_00137ea5,"haptic_hv",0x48f,"aw8693xs_read_f0");
    haptic_hv_i2c_reads(param_1,0x27,local_2c,2);
    uVar1 = (uint)(local_2c[0] >> 8) | (local_2c[0] & 0xff00ff) << 8;
    if (uVar1 != 0) {
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = 0x3a9800 / uVar1;
      }
      *(uint *)(param_1 + 0x68) = uVar2;
      _printk(&DAT_00133011,"haptic_hv",0x49a,"aw8693xs_read_f0");
      uVar5 = 0;
      goto LAB_0012433c;
    }
    *(undefined4 *)(param_1 + 0x68) = 0;
    puVar4 = &DAT_00137618;
    uVar5 = 0x496;
  }
  _printk(puVar4,"haptic_hv",uVar5,"aw8693xs_read_f0");
  uVar5 = 0xffffffde;
LAB_0012433c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// cont_drv_lvl_show @ 0012436c size=64
// signature: undefined cont_drv_lvl_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_lvl_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_lvl = 0x%02X, cont_drv2_lvl = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4ba),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bb));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_lvl_store @ 001243b0 size=252
// signature: undefined cont_drv_lvl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_lvl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined2 local_44;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_40[1] = 0;
  local_44 = 0;
  iVar1 = sscanf(param_3,"%x %x",local_40,(uint *)((ulong)local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x4ba) = (char)local_40[0];
    *(char *)(lVar2 + 0x4bb) = (char)local_40[1];
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_reads(lVar2 + -0xa8,0x1d,&local_44,1);
    local_44 = CONCAT11(*(undefined1 *)(lVar2 + 0x4bb),
                        *(byte *)(lVar2 + 0x4ba) | (byte)local_44 & 0x80);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1d,&local_44,2);
    mutex_unlock(lVar2 + 0x2a8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_drv_time_show @ 001244b0 size=64
// signature: undefined cont_drv_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_drv_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_drv1_time = 0x%02X, cont_drv2_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4be),
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bf));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_drv_time_store @ 001244f4 size=212
// signature: undefined cont_drv_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cont_drv_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_44;
  undefined1 local_43;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_40,(uint *)((ulong)&local_40 | 4));
  if (iVar1 == 2) {
    *(undefined1 *)(lVar2 + 0x4be) = (undefined1)local_40;
    *(char *)(lVar2 + 0x4bf) = (char)((ulong)local_40 >> 0x20);
    local_44 = (undefined1)local_40;
    local_43 = *(undefined1 *)(lVar2 + 0x4bf);
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x1f,&local_44,2);
    mutex_unlock(lVar2 + 0x2a8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_brk_time_show @ 001245cc size=60
// signature: undefined cont_brk_time_show(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"cont_brk_time = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x4bc));
  return (long)iVar1;
}



//------------------------------------------------------------
// cont_brk_time_store @ 0012460c size=128
// signature: undefined cont_brk_time_store(void)
// callers: []
//------------------------------------------------------------

long cont_brk_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = kstrtou8(param_3,0,lVar2 + 0x4bc);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    mutex_lock(lVar2 + 0x2a8);
    haptic_hv_i2c_writes(lVar2 + -0xa8,0x21,lVar2 + 0x4bc,1);
    mutex_unlock(lVar2 + 0x2a8);
  }
  return param_4;
}



//------------------------------------------------------------
// trig_show @ 00124690 size=292
// signature: undefined trig_show(void)
// callers: []
//------------------------------------------------------------

long trig_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,1,(uint)*(byte *)(lVar2 + 0x61f),(uint)*(byte *)(lVar2 + 0x620),
                   (uint)*(byte *)(lVar2 + 0x621),(uint)*(byte *)(lVar2 + 0x623),
                   (uint)*(byte *)(lVar2 + 0x622),(uint)*(byte *)(lVar2 + 0x624),
                   (uint)*(byte *)(lVar2 + 0x61d),(uint)*(byte *)(lVar2 + 0x61e));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,2,(uint)*(byte *)(lVar2 + 0x62c),(uint)*(byte *)(lVar2 + 0x62d),
                   (uint)*(byte *)(lVar2 + 0x62e),(uint)*(byte *)(lVar2 + 0x630),
                   (uint)*(byte *)(lVar2 + 0x62f),(uint)*(byte *)(lVar2 + 0x631),
                   (uint)*(byte *)(lVar2 + 0x62a),(uint)*(byte *)(lVar2 + 0x62b));
  lVar3 = lVar3 + iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,
                   "trig%d: trig_level=%d, trig_polar=%d, pos_enable=%d, pos_sequence=%d, neg_enable=%d, neg_sequence=%d trig_brk=%d, trig_bst=%d\n"
                   ,3,(uint)*(byte *)(lVar2 + 0x639),(uint)*(byte *)(lVar2 + 0x63a),
                   (uint)*(byte *)(lVar2 + 0x63b),(uint)*(byte *)(lVar2 + 0x63d),
                   (uint)*(byte *)(lVar2 + 0x63c),(uint)*(byte *)(lVar2 + 0x63e),
                   (uint)*(byte *)(lVar2 + 0x637),(uint)*(byte *)(lVar2 + 0x638));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// trig_store @ 001247b8 size=776
// signature: undefined trig_store(void)
// callers: []
//------------------------------------------------------------

undefined8 trig_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40 [2];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40[0] = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar5 = sscanf(param_3,"%u %u %u %u %u %u %u %u %u",(uint *)&local_60,
                 (uint *)((ulong)&local_60 | 4),(uint *)&local_58,(uint *)((long)&local_58 + 4),
                 (uint *)&local_50,(uint *)((long)&local_50 + 4),(uint *)&local_48,
                 (uint *)((long)&local_48 + 4),local_40);
  if (iVar5 == 9) {
    _printk(&DAT_001359f8,"haptic_hv",0x805,"trig_store",local_60 & 0xffffffff,local_60._4_4_,
            local_58 & 0xffffffff,local_58._4_4_,local_50 & 0xffffffff,local_50 >> 0x20,
            local_48 & 0xffffffff,local_48._4_4_,local_40[0]);
    uVar3 = local_60;
    if ((uint)local_60 - 4 < 0xfffffffd) {
      _printk(&DAT_001369d0,"haptic_hv",0x807,"trig_store");
    }
    else {
      uVar2 = (uint)local_60 - 1;
      if ((uVar2 == 0) && (*(char *)(lVar6 + 0x4e6) != '\0')) {
        _printk(&DAT_00136135,"haptic_hv",0x80b,"trig_store");
      }
      else if (*(char *)(lVar6 + -0xa2) == '\0') {
        _printk(&DAT_001325b9,"haptic_hv",0x80f,"trig_store");
      }
      else {
        if (((uint)local_50 <= *(byte *)(lVar6 + 0x47c)) &&
           ((uint)local_48 <= *(byte *)(lVar6 + 0x47c))) {
          lVar1 = lVar6 + 0x618;
          local_60 = CONCAT44(local_60._4_4_,uVar2);
          *(char *)(lVar1 + (ulong)uVar2 * 0xd + 7) = (char)(uVar3 >> 0x20);
          if (uVar2 < 3) {
            *(char *)(lVar1 + (ulong)uVar2 * 0xd + 8) = (char)local_58;
            if (uVar2 < 3) {
              *(char *)(lVar1 + (ulong)uVar2 * 0xd + 9) = (char)(local_58 >> 0x20);
              if (uVar2 < 3) {
                *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xb) = (char)local_50;
                if (uVar2 < 3) {
                  *(char *)(lVar1 + (ulong)uVar2 * 0xd + 10) = (char)(local_50 >> 0x20);
                  if (uVar2 < 3) {
                    *(char *)(lVar1 + (ulong)uVar2 * 0xd + 0xc) = (char)local_48;
                    if (uVar2 < 3) {
                      *(char *)(lVar1 + (ulong)uVar2 * 0xd + 5) = (char)(local_48 >> 0x20);
                      if (uVar2 < 3) {
                        lVar7 = lVar6 + -0xa8;
                        *(char *)(lVar1 + (ulong)uVar2 * 0xd + 6) = (char)local_40[0];
                        mutex_lock(lVar6 + 0x2a8);
                        if ((uint)local_60 == 2) {
                          aw8693xs_trig3_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 1) {
                          aw8693xs_trig2_param_config(lVar7);
                        }
                        else if ((uint)local_60 == 0) {
                          aw8693xs_trig1_param_config(lVar7);
                        }
                        mutex_unlock(lVar6 + 0x2a8);
                        goto LAB_0012483c;
                      }
                    }
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x124ac0);
          (*pcVar4)();
        }
        _printk(&DAT_00134564,"haptic_hv",0x814,"trig_store");
      }
    }
  }
LAB_0012483c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8693xs_trig1_param_config @ 00124ac0 size=248
// signature: undefined aw8693xs_trig1_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8693xs_trig1_param_config(long param_1)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6c7) != '\0';
  uVar1 = (uint)bVar3 << 6;
  if (*(char *)(param_1 + 0x6c8) != '\0') {
    uVar1 = (uint)bVar3 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6c5) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6c6) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xffffff0f,uVar1);
  local_2c[0] = *(byte *)(param_1 + 0x6cb) | (*(char *)(param_1 + 0x6c9) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x33,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6cc) | (*(char *)(param_1 + 0x6ca) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x36,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_trig2_param_config @ 00124bb8 size=248
// signature: undefined aw8693xs_trig2_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8693xs_trig2_param_config(long param_1)

{
  byte bVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6d4) != '\0';
  bVar1 = bVar3 << 2;
  if (*(char *)(param_1 + 0x6d5) != '\0') {
    bVar1 = bVar3 << 2 | 8;
  }
  if (*(char *)(param_1 + 0x6d2) != '\0') {
    bVar1 = bVar1 | 2;
  }
  haptic_hv_i2c_write_bits(param_1,0x39,0xfffffff0,bVar1 | *(char *)(param_1 + 0x6d3) != '\0');
  local_2c[0] = *(byte *)(param_1 + 0x6d8) | (*(char *)(param_1 + 0x6d6) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x34,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6d9) | (*(char *)(param_1 + 0x6d7) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x37,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_trig3_param_config @ 00124cb0 size=248
// signature: undefined aw8693xs_trig3_param_config(void)
// callers: [trig_store]
//------------------------------------------------------------

void aw8693xs_trig3_param_config(long param_1)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  byte local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  bVar3 = *(char *)(param_1 + 0x6e1) != '\0';
  uVar1 = (uint)bVar3 << 6;
  if (*(char *)(param_1 + 0x6e2) != '\0') {
    uVar1 = (uint)bVar3 << 6 | 0xffffff80;
  }
  if (*(char *)(param_1 + 0x6df) != '\0') {
    uVar1 = uVar1 | 0x20;
  }
  if (*(char *)(param_1 + 0x6e0) != '\0') {
    uVar1 = uVar1 | 0x10;
  }
  haptic_hv_i2c_write_bits(param_1,0x3a,0xffffff0f,uVar1);
  local_2c[0] = *(byte *)(param_1 + 0x6e5) | (*(char *)(param_1 + 0x6e3) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x35,local_2c,1);
  local_2c[0] = *(byte *)(param_1 + 0x6e6) | (*(char *)(param_1 + 0x6e4) != '\0') << 7;
  haptic_hv_i2c_writes(param_1,0x38,local_2c,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rtp_auto_sin_show @ 00124dac size=60
// signature: undefined rtp_auto_sin_show(void)
// callers: []
//------------------------------------------------------------

long rtp_auto_sin_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"rtp_cnt = %u\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// rtp_auto_sin_store @ 00124dec size=332
// signature: undefined rtp_auto_sin_store(void)
// callers: []
//------------------------------------------------------------

long rtp_auto_sin_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    _printk(&DAT_00132666,"haptic_hv",0x848,"rtp_auto_sin_store");
    param_4 = (long)iVar1;
    goto LAB_00124eac;
  }
  mutex_lock(lVar3 + 0x2a8);
  if (local_3c == 0) {
    uVar2 = 0;
    *(undefined4 *)(lVar3 + -0x60) = 0;
LAB_00124e90:
    haptic_hv_i2c_write_bits(lVar3 + -0xa8,0x2d,0xffffffdf,uVar2);
  }
  else {
    if (local_3c < *(uint *)(lVar3 + -0x28)) {
      uVar2 = 0x20;
      *(undefined4 *)(lVar3 + -0x60) = 1;
      *(uint *)(lVar3 + -0x14) = local_3c;
      goto LAB_00124e90;
    }
    *(undefined4 *)(lVar3 + -0x60) = 0;
    _printk(&DAT_0013408e,"haptic_hv",0x859,"rtp_auto_sin_store",local_3c);
  }
  mutex_unlock(lVar3 + 0x2a8);
  queue_work_on(0x20,*(undefined8 *)(lVar3 + 0x468),lVar3 + 0x350);
LAB_00124eac:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw8693xs_offset_os_code @ 00124f38 size=428
// signature: undefined aw8693xs_offset_os_code(void)
// callers: [aw8693xs_offset_cali]
//------------------------------------------------------------

void aw8693xs_offset_os_code(long param_1,int param_2)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  if (param_2 == 0) {
    bVar1 = *(byte *)(param_1 + 0x55d);
    uVar4 = 0x4e;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x55e);
    uVar4 = 0x4c;
  }
  haptic_hv_i2c_write_bits(param_1,uVar4,0xfffffff8,bVar1);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,4);
  usleep_range_state(500,600,2);
  haptic_hv_i2c_write_bits(param_1,0x4e,0xffffff87,0x20);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,1);
  if (param_2 == 1) {
    usleep_range_state(3000,0xdac,2);
    haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,2);
  }
  usleep_range_state(3000,0xdac,2);
  haptic_hv_i2c_write_bits(param_1,0x4d,0xfffffffc,0);
  haptic_hv_i2c_reads(param_1,0x4f,&local_3c,2);
  haptic_hv_i2c_write_bits(param_1,0x45,0xfffffffb,0);
  if (bVar1 < 8) {
    iVar3 = 0;
    if (*(int *)(&DAT_001380a0 + (long)(char)bVar1 * 4) != 0) {
      iVar3 = (int)(((uint)local_3c._1_1_ | ((byte)local_3c & 3) << 8) * 0x988 + -0x131000) /
              *(int *)(&DAT_001380a0 + (long)(char)bVar1 * 4);
    }
  }
  else {
    _printk(&DAT_00135cd6,"haptic_hv",0x5ff,"aw8693xs_offset_os_code");
    iVar3 = -0x14;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_set_dai_sysclk @ 001250e8 size=64
// signature: undefined aw8693xs_set_dai_sysclk(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_set_dai_sysclk(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  _printk(&DAT_00132947,"haptic_hv",0x4f,"aw8693xs_set_dai_sysclk",param_3);
  return 0;
}



//------------------------------------------------------------
// aw8693xs_set_fmt @ 0012512c size=64
// signature: undefined aw8693xs_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_set_fmt(undefined8 param_1,undefined4 param_2)

{
  _printk(&DAT_00137211,"haptic_hv",0x48,"aw8693xs_set_fmt",param_2);
  return 0;
}



//------------------------------------------------------------
// aw8693xs_mute @ 00125170 size=380
// signature: undefined aw8693xs_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_mute(long param_1,int param_2,int param_3)

{
  long lVar1;
  char local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = '\0';
  if (param_3 == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0x93,"aw8693xs_mute");
  }
  else {
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x58) + 0x18) + 0x98);
    _printk(&DAT_001338b0,"haptic_hv",0x96,"aw8693xs_mute",param_2);
    mutex_lock(lVar1 + 0x350);
    if (param_2 == 0) {
      haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,2);
      haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0x80);
      usleep_range_state(1000,0x5dc,2);
      haptic_hv_i2c_reads(lVar1,0x3f,local_3c,1);
      if (local_3c[0] != '\n') {
        _printk(&DAT_00135703,"haptic_hv",0xa1,"aw8693xs_mute");
        aw8693xs_i2s_enable(lVar1,0);
      }
    }
    else {
      haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,0);
      haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0);
    }
    mutex_unlock(lVar1 + 0x350);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8693xs_startup @ 001252f0 size=8
// signature: undefined aw8693xs_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_startup(void)

{
  return 0;
}



//------------------------------------------------------------
// aw8693xs_shutdown @ 001252fc size=152
// signature: undefined aw8693xs_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_shutdown(long param_1,long param_2)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0xb0,"aw8693xs_shutdown");
  }
  else {
    lVar1 = *(long *)(*(long *)(*(long *)(param_2 + 0x58) + 0x18) + 0x98);
    mutex_lock(lVar1 + 0x350);
    haptic_hv_i2c_write_bits(lVar1,0x46,0xfffffffd,0);
    haptic_hv_i2c_write_bits(lVar1,0x52,0xffffff7f,0);
    mutex_unlock(lVar1 + 0x350);
  }
  return;
}



//------------------------------------------------------------
// aw8693xs_hw_params @ 00125398 size=432
// signature: undefined aw8693xs_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_hw_params(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x3c) == 1) {
    _printk(&DAT_001366b3,"haptic_hv",0x5f,"aw8693xs_hw_params");
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x128);
  lVar6 = *(long *)(*(long *)(*(long *)(param_3 + 0x58) + 0x18) + 0x98);
  _printk(&DAT_00132051,"haptic_hv",100,"aw8693xs_hw_params",iVar2);
  if (iVar2 == 48000) {
LAB_00125464:
    uVar7 = 0;
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 != 0) goto LAB_0012543c;
LAB_00125470:
    uVar4 = *(uint *)(param_2 + 0x28);
    if (uVar4 == 0) {
      uVar5 = 0;
      goto LAB_00125490;
    }
    uVar5 = 0x20;
  }
  else {
    if (iVar2 != 96000) {
      _printk(&DAT_00132073,"haptic_hv",0x6e,"aw8693xs_hw_params");
      goto LAB_00125464;
    }
    uVar7 = 4;
    uVar4 = *(uint *)(param_2 + 0x24);
    if (uVar4 == 0) goto LAB_00125470;
LAB_0012543c:
    uVar5 = 0;
  }
  uVar4 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
  uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
  uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
  uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
  uVar5 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10) | uVar5;
LAB_00125490:
  cVar3 = snd_pcm_format_width(uVar5);
  _printk(&DAT_001340cb,"haptic_hv",0x73,"aw8693xs_hw_params",cVar3);
  if (cVar3 != '\x10') {
    if (cVar3 == ' ') {
      uVar7 = uVar7 | 2;
    }
    else if (cVar3 == '\x18') {
      uVar7 = uVar7 | 1;
    }
    else {
      uVar7 = uVar7 | 2;
      _printk(&DAT_00133305,"haptic_hv",0x80,"aw8693xs_hw_params");
    }
  }
  lVar1 = lVar6 + 0x350;
  mutex_lock(lVar1);
  haptic_hv_i2c_write_bits(lVar6,0x53,0xf8,uVar7);
  mutex_unlock(lVar1);
  return 0;
}



//------------------------------------------------------------
// aw8693xs_i2s_enable @ 00125548 size=88
// signature: undefined aw8693xs_i2s_enable(void)
// callers: [aw8693xs_mute]
//------------------------------------------------------------

void aw8693xs_i2s_enable(undefined8 param_1,ulong param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = (param_2 & 1) == 0;
  uVar2 = 2;
  if (bVar1) {
    uVar2 = 0;
  }
  uVar3 = 0xffffff80;
  if (bVar1) {
    uVar3 = 0;
  }
  haptic_hv_i2c_write_bits(0xffffff80,param_1,0x46,0xfffffffd,uVar2);
  haptic_hv_i2c_write_bits(param_1,0x52,0xffffff7f,uVar3);
  return;
}



//------------------------------------------------------------
// aw8693xs_codec_probe @ 001255a4 size=104
// signature: undefined aw8693xs_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw8693xs_codec_probe(long param_1)

{
  long lVar1;
  undefined2 local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0x800;
  haptic_hv_i2c_writes(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98),0x52,local_1c,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw8693xs_codec_remove @ 00125610 size=56
// signature: undefined aw8693xs_codec_remove(void)
// callers: []
//------------------------------------------------------------

void aw8693xs_codec_remove(void)

{
  _printk(&DAT_00132e8a,"haptic_hv",0xfd,"aw8693xs_codec_remove");
  return;
}



//------------------------------------------------------------
// haptic_hv_i2c_reads @ 0012564c size=248
// signature: undefined haptic_hv_i2c_reads(void)
// callers: [aw8672x_misc_para_init, aw8672x_get_f0, aw869xx_get_f0, aw8693x_ram_get_f0, aw8693x_container_update, aw869xx_ram_get_f0, aw8693xs_get_reg, aw8693xs_mute, aw8692x_get_irq_state, aw8693x_interrupt_setup, aw8692x_get_f0, aw8672x_offset_cali, aw869xx_get_glb_state, aw8693xs_get_vbat, aw8693xs_interrupt_setup, aw8693xs_get_theory_time, aw869x_offset_cali, aw8671x_get_prctmode, aw8692x_stop, aw8693xs_judge_rtp_going, aw869xx_check_qualify, aw8692x_get_lra_resistance, aw869xx_get_lra_resistance, aw8693x_misc_para_init, aw8671x_get_wav_seq, aw8671x_check_qualify, aw8692x_get_reg, aw8693xs_read_f0, aw8693x_get_first_wave_addr, aw869xx_misc_para_init, aw8693x_offset_cali, aw869x_get_trim_lra, aw869x_get_theory_time, aw8693x_rtp_get_fifo_afs, aw8672x_interrupt_setup, aw8672x_mute, aw869x_get_ram_data, aw869xx_stop, aw8672x_judge_rtp_going, aw8692x_get_wav_loop, aw8671x_get_lra_resistance, aw869x_play_mode, aw8693xs_misc_para_init, aw8672x_rtp_get_fifo_aes, aw8671x_misc_para_init, aw8693xs_get_prctmode, aw869xx_get_theory_time, aw8672x_get_vbat, aw869xx_get_trim_lra, aw8693x_get_osc_status, aw8672x_get_first_wave_addr, aw8693x_get_prctmode, aw8671x_stop, aw869xx_irq_clear, aw8671x_get_reg, aw8672x_ram_get_f0, aw8692x_interrupt_setup, aw8671x_get_first_wave_addr, aw8693x_get_trim_lra, aw8692x_rtp_get_fifo_afs, aw8693xs_container_update, cont_drv_lvl_store, aw8692x_rtp_get_fifo_aes, aw8692x_judge_rtp_going, aw869xx_get_ram_data, aw8692x_irq_clear, aw8671x_rtp_get_fifo_aes, aw8693xs_get_bemf_peak, aw869x_get_vbat, aw8693xs_get_wav_loop, aw869xx_get_wav_loop, aw8671x_irq_clear, aw8672x_get_ram_data, aw8671x_rtp_get_fifo_afs, aw869x_stop, aw8671x_get_osc_status, aw8672x_get_irq_state, aw8693xs_get_glb_state, aw8693xs_get_f0, aw8693xs_get_first_wave_addr, aw8693xs_irq_clear, aw8693xs_offset_os_code, aw8693x_get_glb_state, aw8671x_get_trim_lra, aw8672x_check_qualify, aw8693xs_ram_get_f0, aw869x_misc_para_init, aw869xx_judge_rtp_going, aw869xx_osc_read_status, aw8672x_get_lra_resistance, aw8692x_get_prctmode, aw8693xs_rtp_get_fifo_afs, aw869xx_get_vbat, aw869x_rtp_get_fifo_afs, aw8671x_get_vbat, aw8692x_ram_get_f0, aw8692x_get_theory_time, aw8671x_ram_get_f0, aw8671x_codec_read, aw8692x_get_first_wave_addr, aw8692x_get_trim_lra, aw8693x_get_f0, aw8693x_mute, aw8693x_rtp_get_fifo_aes, aw8693xs_get_wav_seq, aw8693xs_get_trim_lra, aw869xx_get_prctmode, aw8672x_get_osc_status, aw8693x_get_theory_time, aw869x_get_first_wave_addr, aw869x_interrupt_setup, aw8672x_stop, aw8671x_get_theory_time, aw8693x_stop, aw8693xs_get_ram_data, aw8692x_check_qualify, aw8672x_get_reg, aw869xx_mute, cont_drv_lvl_store, aw869xx_hw_params, aw869x_get_f0, aw869x_rtp_get_fifo_aes, aw869x_container_update, aw8672x_get_prctmode, aw8692x_get_glb_state, aw8693x_get_lra_resistance, aw8671x_get_glb_state, aw8692x_misc_para_init, aw8693xs_rtp_get_fifo_aes, aw8693x_get_ram_data, aw869x_get_lra_resistance, aw8671x_interrupt_setup, aw869x_get_wav_loop, aw8672x_container_update, aw8672x_get_glb_state, aw869xx_get_first_wave_addr, aw8672x_get_trim_lra, aw8693x_get_wav_seq, aw8671x_judge_rtp_going, aw8671x_container_update, aw8671x_get_irq_state, aw8692x_play_go, aw8693xs_get_osc_status, aw869x_get_wav_seq, aw8693x_get_vbat, cont_drv_lvl_store, aw8693x_get_reg, aw8671x_get_f0, aw869xx_rtp_get_fifo_afs, aw8693x_get_irq_state, aw8693x_check_qualify, aw8671x_get_ram_data, aw8693xs_check_qualify, aw869xx_get_irq_state, aw8672x_get_wav_seq, aw8693xs_stop, aw8693x_irq_clear, aw8671x_get_wav_loop, cont_drv_lvl_store, aw8672x_rtp_get_fifo_afs, aw8692x_get_ram_data, aw8693xs_get_lra_resistance, aw8671x_mute, aw8693xs_get_irq_state, aw8692x_get_osc_status, aw8693x_judge_rtp_going, aw869x_get_glb_state, aw869xx_offset_cali, aw869x_irq_clear, aw8672x_irq_clear, aw869x_osc_read_status, aw8671x_hw_params, aw8672x_get_wav_loop, aw8692x_get_wav_seq, aw869x_get_reg, aw869xx_get_wav_seq, aw869xx_get_reg, aw8672x_get_theory_time, aw869xx_rtp_get_fifo_aes, aw869x_get_irq_state, aw8692x_container_update, aw869xx_codec_read, aw8692x_get_vbat, aw8693x_get_wav_loop, aw869x_get_prctmode, aw8692x_cont_config, aw869xx_container_update, aw869xx_interrupt_setup, aw869x_judge_rtp_going]
//------------------------------------------------------------

int haptic_hv_i2c_reads(long param_1,undefined1 param_2,undefined8 param_3,undefined2 param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_4c [4];
  undefined2 local_48;
  undefined6 uStack_46;
  undefined1 *local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_40 = local_4c;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x2c8);
  _local_48 = CONCAT62(0x10000,*(undefined2 *)(lVar2 + 2));
  local_38 = CONCAT62(1,*(undefined2 *)(lVar2 + 2));
  local_38 = (ulong)CONCAT24(param_4,(undefined4)local_38);
  local_4c[0] = param_2;
  local_30 = param_3;
  iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_48,2);
  if (iVar1 < 0) {
    _printk(&DAT_001343e2,"haptic_hv",0x76,"haptic_hv_i2c_reads");
  }
  else if (iVar1 != 2) {
    _printk(&DAT_001324a5,"haptic_hv",0x79,"haptic_hv_i2c_reads");
    iVar1 = -6;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// haptic_hv_i2c_writes @ 00125748 size=180
// signature: undefined haptic_hv_i2c_writes(void)
// callers: [aw8672x_misc_para_init, aw8672x_get_f0, aw869xx_get_f0, aw8692x_set_repeat_seq, aw8693x_ram_get_f0, aw8693x_container_update, aw869xx_ram_get_f0, aw8692x_get_f0, aw8671x_protect_config, cont_brk_time_store, aw8671x_set_ram_addr, aw869xx_play_go, aw8693x_trig_init, aw8692x_stop, aw8692x_protect_config, aw869x_trig_init, aw8693xs_play_go, aw869xx_set_wav_seq, aw8693x_misc_para_init, aw8672x_protect_config, aw8693xs_trig2_param_config, cont_drv_time_store, aw8672x_trig_init, aw869xx_misc_para_init, aw8693x_set_repeat_seq, aw8693xs_codec_probe, aw8693xs_upload_lra, aw869x_set_rtp_data, aw869xx_stop, aw8671x_set_wav_seq, aw8671x_set_gain, cont_drv_time_store, aw8693xs_misc_para_init, aw8671x_misc_para_init, aw869xx_set_gain, aw8672x_cont_config, cont_brk_time_store, aw8693xs_set_repeat_seq, cont_drv_time_store, aw8693xs_set_wav_seq, aw8693x_trig1_param_config, aw8692x_trig1_param_config, cont_drv_time_store, aw8671x_stop, aw8693xs_set_gain, cont_brk_time_store, aw8672x_ram_get_f0, aw869x_upload_lra, cont_drv_time_store, aw8693x_set_gain, aw8692x_trig2_param_config, aw8693xs_set_ram_addr, aw8692x_set_wav_seq, aw8693xs_container_update, cont_drv_lvl_store, aw8671x_codec_write, aw869x_set_gain, aw8693xs_trig3_param_config, aw8693xs_cont_config, aw8693x_trig2_param_config, aw8693xs_trig1_param_config, aw869x_set_repeat_seq, aw8693xs_get_f0, aw8693x_trig3_param_config, cont_brk_time_store, aw8692x_set_rtp_data, aw8692x_set_ram_addr, aw8693xs_ram_get_f0, aw869x_misc_para_init, aw8692x_trig_init, aw8693x_cont_config, aw8672x_set_bst_vol, aw8671x_cont_config, aw8692x_ram_get_f0, aw8671x_ram_get_f0, aw8693x_get_f0, aw869xx_set_repeat_seq, aw869xx_protect_config, aw8672x_set_repeat_seq, trig_store, aw869xx_play_mode, aw8692x_set_bst_peak_cur, aw8672x_stop, aw869x_protect_config, aw8693x_stop, aw8692x_check_qualify, cont_drv_lvl_store, aw869xx_set_ram_addr, aw869x_get_f0, aw869x_container_update, aw8672x_set_gain, aw8692x_upload_lra, aw8672x_play_go, aw8672x_set_ram_addr, aw8671x_play_go, aw8693xs_protect_config, cont_drv_store, aw869x_set_ram_addr, cont_td_store, aw8692x_misc_para_init, aw8693x_set_ram_addr, aw8693x_upload_lra, aw8672x_container_update, aw869xx_vbat_mode_config, cont_drv_time_store, aw8692x_set_gain, aw8693x_set_wav_seq, aw8671x_container_update, aw8671x_set_rtp_data, cont_zc_thr_store, cont_drv_lvl_store, aw8692x_play_go, aw8671x_trig_init, cont_drv_lvl_store, aw8671x_get_f0, aw8693xs_stop, aw8693x_protect_config, aw8692x_trig3_param_config, aw869xx_codec_write, aw869x_cont_config, cont_drv_lvl_store, aw8672x_codec_probe, aw869xx_trig_init, aw8671x_set_repeat_seq, aw869xx_cont_config, aw8672x_set_rtp_data, cont_brk_time_store, aw8693xs_set_rtp_data, cont_brk_time_store, aw869x_set_wav_seq, aw869xx_set_rtp_data, aw8692x_container_update, aw8693xs_trig_init, aw8692x_cont_config, aw8672x_set_wav_seq, aw8693x_play_go, aw8693x_codec_probe, aw869xx_container_update, aw8693x_set_rtp_data]
//------------------------------------------------------------

int haptic_hv_i2c_writes(long param_1,undefined1 param_2,void *param_3,uint param_4)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)__kmalloc(param_4 + 1,0xcc0);
  *puVar2 = param_2;
  memcpy(puVar2 + 1,param_3,(ulong)param_4);
  iVar1 = i2c_transfer_buffer_flags(*(undefined8 *)(param_1 + 0x2c8),puVar2,param_4 + 1,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137c1e,"haptic_hv",0x8a,"haptic_hv_i2c_writes",param_2);
  }
  kfree(puVar2);
  return iVar1;
}



//------------------------------------------------------------
// haptic_hv_i2c_write_bits @ 00125800 size=496
// signature: undefined haptic_hv_i2c_write_bits(void)
// callers: [aw8672x_misc_para_init, aw8693x_container_update, aw869xx_ram_get_f0, aw8693xs_ram_init, aw8692x_get_f0, aw8671x_set_ram_addr, aw869x_offset_cali, aw8692x_stop, aw869x_trig_init, aw8692x_get_lra_resistance, aw8672x_hw_params, aw8693x_misc_para_init, aw8693xs_vbat_mode_config, aw8672x_protect_config, aw8693xs_trig2_param_config, aw8672x_trig_init, aw8672x_trig2_param_config, aw869xx_misc_para_init, aw8693x_set_repeat_seq, aw8693x_offset_cali, aw869x_set_bst_vol, aw8671x_startup, aw8693x_bst_mode_config, aw8693x_set_pwm, aw8693xs_misc_para_init, aw8671x_misc_para_init, aw8671x_vbat_mode_config, aw8693x_auto_bst_enable, aw8692x_trig1_param_config, aw8671x_stop, aw8672x_upload_lra, aw8692x_ram_init, aw8692x_play_mode, aw8693xs_container_update, aw869xx_trig2_param_config, rtp_auto_sin_store, aw8693xs_trig1_param_config, aw8672x_i2s_enable, aw8692x_set_bst_vol, aw8672x_trig3_param_config, aw8693xs_offset_os_code, aw869xx_ram_init, aw8693xs_ram_get_f0, aw8671x_set_rtp_aei, aw869xx_get_vbat, aw8672x_set_bst_vol, aw8671x_cont_config, aw8671x_get_vbat, aw8692x_ram_get_f0, aw8693xs_i2s_enable, aw8693x_get_f0, aw869xx_protect_config, aw8672x_ram_init, aw8672x_set_repeat_seq, aw869x_interrupt_setup, trig_store, aw8693x_set_rtp_aei, aw8693xs_set_pwm, aw869x_protect_config, aw8672x_set_rtp_aei, aw8692x_check_qualify, aw869xx_upload_lra, aw869xx_mute, aw869xx_hw_params, aw869x_container_update, aw8672x_set_pwm, aw8693xs_protect_config, aw8693x_get_lra_resistance, aw8692x_misc_para_init, aw869x_get_lra_resistance, aw8693x_i2s_enable, aw8672x_container_update, aw869xx_vbat_mode_config, aw8671x_set_pwm, aw8671x_container_update, aw8693xs_set_rtp_aei, aw8671x_set_wav_loop, aw8672x_shutdown, aw8671x_bst_mode_config, aw869x_cont_config, aw869xx_startup, aw8671x_upload_lra, aw869xx_trig_init, aw869xx_cont_config, aw869x_set_bst_peak_cur, aw8692x_vbat_mode_config, aw869x_set_wav_loop, aw8693x_ram_init, aw8693xs_trig_init, aw8692x_get_vbat, aw8692x_cont_config, aw869x_auto_bst_enable, aw869xx_container_update, aw8672x_get_f0, aw869xx_get_f0, aw8692x_set_repeat_seq, aw8693x_ram_get_f0, aw869x_set_rtp_aei, rtp_auto_sin_store, aw8693xs_mute, aw8693x_interrupt_setup, aw8672x_set_wav_loop, aw8671x_protect_config, aw8672x_offset_cali, aw869xx_set_wav_loop, aw869x_bst_mode_config, aw8693x_trig_init, aw8693xs_get_vbat, aw8693xs_interrupt_setup, aw8692x_protect_config, aw869xx_auto_bst_enable, aw869xx_get_lra_resistance, aw8693xs_hw_params, aw8692x_bst_mode_config, cont_drv_lvl_store, aw8672x_interrupt_setup, aw8672x_mute, aw869xx_stop, aw8671x_get_lra_resistance, aw869x_play_mode, aw8692x_set_pwm, aw8672x_cont_config, aw8693xs_set_repeat_seq, aw8672x_get_vbat, aw8693xs_set_wav_loop, aw869xx_bst_mode_config, aw8693x_trig1_param_config, aw8671x_play_mode, aw8693xs_play_mode, aw8672x_ram_get_f0, aw869x_set_pwm, aw8692x_interrupt_setup, aw8693xs_set_bst_vol, aw8692x_trig2_param_config, aw869xx_trig3_param_config, aw8672x_play_mode, aw869xx_set_rtp_aei, aw8693xs_trig3_param_config, aw8693xs_cont_config, aw8693x_trig2_param_config, aw869x_get_vbat, aw869x_stop, aw869x_set_repeat_seq, aw8693x_vbat_mode_config, aw8693xs_get_f0, aw8693x_trig3_param_config, aw869x_misc_para_init, cont_num_brk_store, aw8671x_trig2_param_config, aw8692x_trig_init, aw8672x_get_lra_resistance, aw8693x_cont_config, aw8693x_shutdown, aw8671x_ram_init, aw8693xs_shutdown, aw8692x_auto_bst_enable, aw8671x_trig1_param_config, aw8671x_ram_get_f0, aw869xx_trig1_param_config, aw8693x_mute, aw8693x_hw_params, aw869xx_set_repeat_seq, aw8672x_vbat_mode_config, aw869xx_play_mode, aw8692x_set_bst_peak_cur, aw8672x_stop, aw869x_vbat_mode_config, aw8693x_stop, aw8693x_set_bst_vol, aw8672x_trig1_param_config, aw869x_get_f0, aw8672x_set_ram_addr, aw8692x_set_rtp_aei, aw8671x_interrupt_setup, rtp_auto_sin_store, aw869xx_set_bst_vol, aw869x_ram_init, aw8693x_play_mode, aw8672x_bst_mode_config, aw869x_play_go, cont_drv_lvl_store, aw8693x_set_wav_loop, aw869xx_set_pwm, aw8671x_trig3_param_config, aw8671x_trig_init, aw8693x_get_vbat, aw8671x_get_f0, aw8693xs_bst_mode_config, aw8693xs_stop, aw8693x_protect_config, aw8692x_trig3_param_config, aw8693xs_get_lra_resistance, aw8671x_set_repeat_seq, aw8671x_mute, aw8693xs_auto_bst_enable, aw869xx_offset_cali, aw869xx_set_bst_peak_cur, aw8672x_auto_bst_enable, aw8671x_hw_params, aw8671x_auto_bst_enable, aw8692x_container_update, aw8692x_set_wav_loop, aw8671x_set_bst_vol, aw869xx_interrupt_setup]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int haptic_hv_i2c_write_bits(long param_1,undefined1 param_2,byte param_3,byte param_4)

{
  int iVar1;
  undefined1 *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  long lVar5;
  byte local_70 [4];
  undefined1 local_6c [4];
  undefined2 local_68;
  undefined6 uStack_66;
  undefined1 *local_60;
  undefined8 local_58;
  undefined1 *local_50;
  long local_48;
  
  local_50 = local_70;
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_60 = local_6c;
  lVar5 = *(long *)(param_1 + 0x2c8);
  local_70[0] = 0;
  _local_68 = CONCAT62(0x10000,*(undefined2 *)(lVar5 + 2));
  local_58 = (ulong)CONCAT42(0x10001,*(undefined2 *)(lVar5 + 2));
  local_6c[0] = param_2;
  iVar1 = i2c_transfer(*(undefined8 *)(lVar5 + 0x18),&local_68,2);
  if (iVar1 < 0) {
    _printk(&DAT_001343e2,"haptic_hv",0x76,"haptic_hv_i2c_reads");
LAB_00125974:
    puVar4 = &DAT_00134e32;
    uVar3 = 0x98;
  }
  else {
    if (iVar1 != 2) {
      _printk(&DAT_001324a5,"haptic_hv",0x79,"haptic_hv_i2c_reads");
      iVar1 = -6;
      goto LAB_00125974;
    }
    local_70[0] = local_70[0] & param_3 | param_4 & (param_3 ^ 0xff);
    puVar2 = (undefined1 *)kmalloc_trace(_gpiod_set_raw_value_cansleep,0xcc0,2);
    uVar3 = *(undefined8 *)(param_1 + 0x2c8);
    *puVar2 = param_2;
    puVar2[1] = local_70[0];
    iVar1 = i2c_transfer_buffer_flags(uVar3,puVar2,2,0);
    if (-1 < iVar1) {
      kfree(puVar2);
      iVar1 = 0;
      goto LAB_001258f8;
    }
    _printk(&DAT_00137c1e,"haptic_hv",0x8a,"haptic_hv_i2c_writes",param_2);
    kfree(puVar2);
    puVar4 = &DAT_001336e5;
    uVar3 = 0x9f;
  }
  _printk(puVar4,"haptic_hv",uVar3,"haptic_hv_i2c_write_bits",iVar1);
LAB_001258f8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// sw_reset @ 001259f4 size=156
// signature: undefined sw_reset(void)
// callers: [aw8693xs_offset_cali, aw_i2c_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sw_reset(long param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined2 *)kmalloc_trace(_gpiod_set_raw_value_cansleep,0xcc0,2);
  uVar3 = *(undefined8 *)(param_1 + 0x2c8);
  *puVar2 = 0xaa00;
  iVar1 = i2c_transfer_buffer_flags(uVar3,puVar2,2,0);
  if (iVar1 < 0) {
    _printk(&DAT_00137c1e,"haptic_hv",0x8a,"haptic_hv_i2c_writes",0);
  }
  kfree(puVar2);
  usleep_range_state(3000,0xdac,2);
  return;
}



//------------------------------------------------------------
// aw_i2c_probe @ 00125a94 size=2016
// signature: undefined aw_i2c_probe(void)
// callers: []
//------------------------------------------------------------

int aw_i2c_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined *puVar8;
  undefined1 uVar9;
  code *pcVar10;
  undefined **ppuVar11;
  long lVar12;
  uint uVar13;
  int local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_1 + 0x308);
  _printk(&DAT_001324d3,"haptic_hv","aw_i2c_probe");
  pcVar10 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
  if (*(int *)(pcVar10 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x125b0c);
    (*pcVar10)();
  }
  uVar5 = (*pcVar10)();
  if ((uVar5 & 1) == 0) {
    _printk(&DAT_0013766b,"haptic_hv","aw_i2c_probe");
    iVar4 = -5;
  }
  else {
    lVar1 = param_1 + 0x20;
    lVar6 = devm_kmalloc(lVar1,0x720,0xdc0);
    if (lVar6 == 0) {
      iVar4 = -0xc;
    }
    else {
      *(long *)(lVar6 + 0x2c0) = lVar1;
      *(long *)(lVar6 + 0x2c8) = param_1;
      *(long *)(param_1 + 0xb8) = lVar6;
      if (lVar12 == 0) {
        *(undefined4 *)(lVar6 + 0x60) = 0xffffffff;
        *(undefined4 *)(lVar6 + 0x54) = 0xffffffff;
      }
      else {
        iVar4 = of_get_named_gpio_flags(lVar12,"reset-gpio",0,0);
        *(int *)(lVar6 + 0x60) = iVar4;
        if (iVar4 < 0) {
          _printk(&DAT_0013547e,"haptic_hv",0xac,"parse_dt_gpio");
          _printk(&DAT_00137a28,"haptic_hv",0xf3f,"aw_i2c_probe");
          iVar4 = -1;
          goto LAB_00125b30;
        }
        _printk(&DAT_00134ada,"haptic_hv",0xaf,"parse_dt_gpio",iVar4);
        iVar4 = of_get_named_gpio_flags(lVar12,"irq-gpio",0,0);
        *(int *)(lVar6 + 0x54) = iVar4;
        if (iVar4 < 0) {
          _printk(&DAT_00135bc6,"haptic_hv",0xb2,"parse_dt_gpio");
        }
        else {
          _printk(&DAT_0013629d,"haptic_hv",0xb4,"parse_dt_gpio",iVar4);
        }
        iVar4 = of_property_read_variable_u8_array(lVar12,&DAT_00133099,lVar6 + 0x528,1,0);
        if (iVar4 < 0) {
          _printk(&DAT_00135f12,"haptic_hv",0xb7,"parse_dt_gpio");
        }
      }
      if ((*(uint *)(lVar6 + 0x60) < 0x200) &&
         (iVar4 = devm_gpio_request_one(lVar1,*(uint *)(lVar6 + 0x60),0,"aw_rst"), iVar4 != 0)) {
        _printk(&DAT_00135889,"haptic_hv",0xf4b,"aw_i2c_probe");
      }
      else if ((*(uint *)(lVar6 + 0x54) < 0x200) &&
              (iVar4 = devm_gpio_request_one(lVar1,*(uint *)(lVar6 + 0x54),1,"aw_int"), iVar4 != 0))
      {
        _printk(&DAT_00137036,"haptic_hv",0xf68,"aw_i2c_probe");
      }
      else {
        local_6c = 0;
        _printk(&DAT_00132e8a,"haptic_hv",0x117,"ctrl_init");
        uVar13 = 0;
        do {
          _printk(&DAT_00132e8a,"haptic_hv",0xce,"hw_reset");
          if (*(uint *)(lVar6 + 0x60) < 0x200) {
            uVar7 = gpio_to_desc();
            gpiod_set_raw_value_cansleep(uVar7,0);
            usleep_range_state(1000,2000,2);
            uVar7 = gpio_to_desc(*(undefined4 *)(lVar6 + 0x60));
            gpiod_set_raw_value_cansleep(uVar7,1);
            usleep_range_state(8000,0x2134,2);
          }
          else {
            _printk(&DAT_00132191,"haptic_hv",0xd5,"hw_reset");
          }
          iVar4 = read_chipid(lVar6,&local_6c);
          if (iVar4 < 0) {
            _printk(&DAT_001324e4,"haptic_hv",0x11c,"ctrl_init");
          }
          if (0x727f < local_6c) {
            uVar2 = local_6c - 0x9360;
            if (uVar2 < 0x22) {
              if ((1L << ((ulong)uVar2 & 0x3f) & 0x100010001U) == 0) {
                if ((1L << ((ulong)uVar2 & 0x3f) & 0x200020000U) == 0) goto LAB_00125d2c;
                uVar9 = 0;
                ppuVar11 = &aw8693xs_func_list;
              }
              else {
                uVar9 = 0;
                ppuVar11 = &aw8693x_func_list;
              }
            }
            else {
LAB_00125d2c:
              if ((local_6c - 0x9250U < 0x31) &&
                 ((1L << ((ulong)(local_6c - 0x9250U) & 0x3f) & 0x1000100010001U) != 0)) {
                uVar9 = 1;
                ppuVar11 = &aw8692x_func_list;
              }
              else {
                iVar4 = 0x7280;
LAB_00125d4c:
                if (local_6c != iVar4) goto LAB_00125d6c;
                uVar9 = 0;
                ppuVar11 = &aw8672x_func_list;
              }
            }
LAB_00125fd4:
            pcVar10 = (code *)ppuVar11[5];
            *(undefined ***)(lVar6 + 0x6a8) = ppuVar11;
            *(undefined1 *)(lVar6 + 0x10) = uVar9;
            if (*(int *)(pcVar10 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x822a,0x125ffc);
              (*pcVar10)();
            }
            iVar4 = (*pcVar10)(lVar6);
            if (iVar4 < 0) {
              puVar8 = &DAT_00136c80;
              uVar7 = 0xf76;
            }
            else {
              iVar4 = parse_chipid(lVar6);
              if (iVar4 < 0) {
                puVar8 = &DAT_00136839;
                uVar7 = 0xf7d;
              }
              else {
                pcVar10 = *(code **)(*(long *)(lVar6 + 0x6a8) + 0xd0);
                if (*(int *)(pcVar10 + -4) != 0x2a969f2) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x126084);
                  (*pcVar10)();
                }
                (*pcVar10)(lVar1,lVar6,lVar12);
                sw_reset(lVar6);
                if (*(char *)(lVar6 + 0x561) == '\0') {
                  pcVar10 = *(code **)(*(long *)(lVar6 + 0x6a8) + 0x18);
                  if (*(int *)(pcVar10 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
                    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1260bc);
                    (*pcVar10)();
                  }
                  iVar4 = (*pcVar10)(lVar6);
                  if (iVar4 < 0) {
                    sw_reset(lVar6);
                  }
                }
                else {
                  _printk(&DAT_0013278a,"haptic_hv",0xf89,"aw_i2c_probe");
                }
                pcVar10 = *(code **)(*(long *)(lVar6 + 0x6a8) + 0x180);
                if (*(int *)(pcVar10 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x126114);
                  (*pcVar10)();
                }
                (*pcVar10)(lVar1);
                iVar4 = irq_config(lVar1,lVar6);
                if (iVar4 == 0) {
                  g_aw_haptic = lVar6;
                  iVar4 = tiktap_init(lVar6);
                  if (iVar4 == 0) {
                    vibrator_init(lVar6);
                    haptic_init(lVar6);
                    lVar12 = alloc_workqueue(&DAT_001333e1,0xe000a,1,"aw_haptic_vibrator_work_queue"
                                            );
                    *(long *)(lVar6 + 0x510) = lVar12;
                    if (lVar12 == 0) {
                      _printk(&DAT_00134e87,"haptic_hv",0xfa4,"aw_i2c_probe");
                      iVar4 = -0x22;
                    }
                    else {
                      pcVar10 = *(code **)(*(long *)(lVar6 + 0x6a8) + 0x10);
                      if (*(int *)(pcVar10 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
                        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x12623c);
                        (*pcVar10)();
                      }
                      (*pcVar10)(lVar6);
                      ram_work_init(lVar6);
                      _printk(&DAT_00133e72,"haptic_hv",0xfa9,"aw_i2c_probe");
                      iVar4 = 0;
                    }
                    goto LAB_00125b30;
                  }
                  puVar8 = &DAT_00134e5a;
                  uVar7 = 0xf9b;
                }
                else {
                  puVar8 = &DAT_001329ec;
                  uVar7 = 0xf93;
                }
              }
            }
            _printk(puVar8,"haptic_hv",uVar7,"aw_i2c_probe",iVar4);
            goto LAB_00125b30;
          }
          if (0x96 < local_6c) {
            if ((local_6c - 0x7150U < 0x31) &&
               ((1L << ((ulong)(local_6c - 0x7150U) & 0x3f) & 0x1000300000001U) != 0)) {
              uVar9 = 1;
              ppuVar11 = &aw8671x_func_list;
            }
            else {
              if (local_6c != 0x97) {
                iVar4 = 0x7270;
                goto LAB_00125d4c;
              }
LAB_00125fc8:
              uVar9 = 1;
              ppuVar11 = &aw869x_func_list;
            }
            goto LAB_00125fd4;
          }
          if (local_6c - 4U < 4) {
            uVar9 = 1;
            ppuVar11 = &aw869xx_func_list;
            goto LAB_00125fd4;
          }
          if (local_6c == 0x95) goto LAB_00125fc8;
LAB_00125d6c:
          _printk(&DAT_00137691,"haptic_hv",0x157,"ctrl_init");
          usleep_range_state(2000,0x9c4,2);
          bVar3 = uVar13 < 4;
          uVar13 = uVar13 + 1;
        } while (bVar3);
        iVar4 = -0x16;
        _printk(&DAT_00136488,"haptic_hv",0xf70,"aw_i2c_probe",0xffffffea);
      }
    }
  }
LAB_00125b30:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// aw_remove @ 00126278 size=252
// signature: undefined aw_remove(void)
// callers: []
//------------------------------------------------------------

void aw_remove(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xb8);
  _printk(&DAT_00132e8a,"haptic_hv",0xfb6,"aw_remove");
  devm_led_classdev_unregister(*(long *)(lVar4 + 0x2c8) + 0x20,lVar4 + 0xa8);
  cancel_delayed_work_sync(lVar4 + 0x458);
  cancel_work_sync(lVar4 + 0x630);
  hrtimer_cancel(lVar4 + 0x5e8);
  cancel_work_sync(lVar4 + 0x3f8);
  cancel_work_sync(lVar4 + 0x4e0);
  hrtimer_cancel(lVar4 + 0x380);
  destroy_workqueue(*(undefined8 *)(lVar4 + 0x510));
  snd_soc_unregister_component(param_1 + 0x20);
  cancel_work_sync(lVar4 + 0x280);
  puVar1 = (ulong *)((((*(long *)(lVar4 + 0x2b8) << 8) >> 8) + 0x8000000000U >> 6 &
                     0x3ffffffffffffc0) - 0x200000000);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 & 0xffffffffffffefff;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  free_pages(*(undefined8 *)(lVar4 + 0x2b8),2);
  *(undefined8 *)(lVar4 + 0x2b8) = 0;
  proc_remove(*(undefined8 *)(lVar4 + 0x2b0));
  *(undefined8 *)(lVar4 + 0x2b0) = 0;
  return;
}



//------------------------------------------------------------
// parse_chipid @ 00126384 size=3140
// signature: undefined parse_chipid(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

int parse_chipid(long param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = read_chipid(param_1,&local_2c);
  if (iVar2 < 0) {
    _printk(&DAT_00132d5a,"haptic_hv",0x169,"parse_chipid",iVar2);
  }
  if (local_2c < 0x7280) {
    if (local_2c < 0x7150) {
      switch(local_2c) {
      case 4:
switchD_0012641c_caseD_4:
        *(undefined1 *)(param_1 + 4) = 0;
        puVar3 = &DAT_00134ece;
        *(undefined4 *)(param_1 + 0x50) = 4;
        *(undefined1 *)(param_1 + 10) = 1;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 0x188;
        break;
      case 5:
switchD_0012641c_caseD_5:
        *(undefined1 *)(param_1 + 10) = 0;
        puVar3 = &DAT_001358c1;
        *(undefined1 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 0x50) = 5;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 0x181;
        break;
      case 6:
switchD_0012641c_caseD_6:
        puVar3 = &DAT_001376b5;
        *(undefined4 *)(param_1 + 0x50) = 6;
        *(undefined1 *)(param_1 + 10) = 1;
        *(undefined1 *)(param_1 + 4) = 1;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 0x196;
        break;
      case 7:
switchD_0012641c_caseD_7:
        *(undefined1 *)(param_1 + 10) = 0;
        puVar3 = &DAT_00135f32;
        *(undefined4 *)(param_1 + 0x50) = 7;
        *(undefined1 *)(param_1 + 4) = 1;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 399;
        break;
      default:
        if (local_2c != 0x95) {
          if (local_2c != 0x97) goto switchD_00126544_caseD_9361;
LAB_00126590:
          *(undefined1 *)(param_1 + 4) = 0;
          *(undefined4 *)(param_1 + 0x50) = 0x97;
          *(undefined1 *)(param_1 + 10) = 1;
          *(undefined1 *)(param_1 + 0x30) = 0x20;
          _printk(&DAT_00132a16,"haptic_hv",0x178,"parse_chipid");
          goto LAB_00126f98;
        }
LAB_00126e8c:
        *(undefined1 *)(param_1 + 10) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0x95;
        *(undefined1 *)(param_1 + 4) = 0;
        _printk(&DAT_00132d81,"haptic_hv",0x170,"parse_chipid");
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        goto LAB_00126f98;
      }
    }
    else if (local_2c < 0x7171) {
      if (local_2c == 0x7150) {
LAB_00126ee4:
        puVar3 = &DAT_00131d90;
        uVar4 = 0x19e;
        *(undefined1 *)(param_1 + 4) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0x7150;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
      }
      else {
        if (local_2c != 0x7170) goto switchD_00126544_caseD_9361;
LAB_001265e8:
        *(undefined4 *)(param_1 + 0x50) = 0x7170;
        puVar3 = &DAT_00135f55;
        *(undefined1 *)(param_1 + 4) = 1;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 0x1a4;
      }
    }
    else if (local_2c == 0x7171) {
LAB_00126db0:
      *(undefined4 *)(param_1 + 0x50) = 0x7171;
      puVar3 = &DAT_00137fb6;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x20;
      uVar4 = 0x1aa;
    }
    else if (local_2c == 0x7180) {
LAB_00126de4:
      *(undefined4 *)(param_1 + 0x50) = 0x7180;
      puVar3 = &DAT_001364b1;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x20;
      uVar4 = 0x1b0;
    }
    else {
      if (local_2c != 0x7270) goto switchD_00126544_caseD_9361;
LAB_001264ec:
      *(undefined4 *)(param_1 + 0x50) = 0x7270;
      puVar3 = &DAT_00134ef1;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x40;
      uVar4 = 0x1b8;
    }
  }
  else if (local_2c < 0x9270) {
    if (local_2c == 0x7280) {
LAB_00126d18:
      *(undefined4 *)(param_1 + 0x50) = 0x7280;
      puVar3 = &DAT_0013370e;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x40;
      uVar4 = 0x1be;
    }
    else if (local_2c == 0x9250) {
LAB_00126d4c:
      *(undefined1 *)(param_1 + 10) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0x9250;
      puVar3 = &DAT_00132507;
      *(undefined1 *)(param_1 + 0x30) = 0x20;
      uVar4 = 0x1c6;
    }
    else {
      if (local_2c != 0x9260) goto switchD_00126544_caseD_9361;
LAB_0012648c:
      *(undefined1 *)(param_1 + 10) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0x9260;
      puVar3 = &DAT_00132a38;
      *(undefined1 *)(param_1 + 0x30) = 0x20;
      uVar4 = 0x1cc;
    }
  }
  else {
    switch(local_2c) {
    case 0x9360:
switchD_00126e3c_caseD_9360:
      puVar3 = &DAT_00134f14;
      *(undefined4 *)(param_1 + 0x50) = 0x9360;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x40;
      uVar4 = 0x1e0;
      break;
    case 0x9361:
    case 0x9362:
    case 0x9363:
    case 0x9364:
    case 0x9365:
    case 0x9366:
    case 0x9367:
    case 0x9368:
    case 0x9369:
    case 0x936a:
    case 0x936b:
    case 0x936c:
    case 0x936d:
    case 0x936e:
    case 0x936f:
    case 0x9372:
    case 0x9373:
    case 0x9374:
    case 0x9375:
    case 0x9376:
    case 0x9377:
    case 0x9378:
    case 0x9379:
    case 0x937a:
    case 0x937b:
    case 0x937c:
    case 0x937d:
    case 0x937e:
    case 0x937f:
switchD_00126544_caseD_9361:
      _printk(&DAT_001358e4,"haptic_hv",0x1fe,"parse_chipid");
      usleep_range_state(2000,0x9c4,2);
      iVar2 = read_chipid(param_1,&local_2c);
      if (iVar2 < 0) {
        _printk(&DAT_00132d5a,"haptic_hv",0x169,"parse_chipid",iVar2);
      }
      if (local_2c < 0x7280) {
        if (local_2c < 0x7150) {
          switch(local_2c) {
          case 4:
            goto switchD_0012641c_caseD_4;
          case 5:
            goto switchD_0012641c_caseD_5;
          case 6:
            goto switchD_0012641c_caseD_6;
          case 7:
            goto switchD_0012641c_caseD_7;
          default:
            if (local_2c == 0x95) goto LAB_00126e8c;
            if (local_2c == 0x97) goto LAB_00126590;
          }
        }
        else if (local_2c < 0x7171) {
          if (local_2c == 0x7150) goto LAB_00126ee4;
          if (local_2c == 0x7170) goto LAB_001265e8;
        }
        else {
          if (local_2c == 0x7171) goto LAB_00126db0;
          if (local_2c == 0x7180) goto LAB_00126de4;
          if (local_2c == 0x7270) goto LAB_001264ec;
        }
      }
      else if (local_2c < 0x9270) {
        if (local_2c == 0x7280) goto LAB_00126d18;
        if (local_2c == 0x9250) goto LAB_00126d4c;
        if (local_2c == 0x9260) goto LAB_0012648c;
      }
      else {
        switch(local_2c) {
        case 0x9360:
          goto switchD_00126e3c_caseD_9360;
        case 0x9361:
        case 0x9362:
        case 0x9363:
        case 0x9364:
        case 0x9365:
        case 0x9366:
        case 0x9367:
        case 0x9368:
        case 0x9369:
        case 0x936a:
        case 0x936b:
        case 0x936c:
        case 0x936d:
        case 0x936e:
        case 0x936f:
        case 0x9372:
        case 0x9373:
        case 0x9374:
        case 0x9375:
        case 0x9376:
        case 0x9377:
        case 0x9378:
        case 0x9379:
        case 0x937a:
        case 0x937b:
        case 0x937c:
        case 0x937d:
        case 0x937e:
        case 0x937f:
          break;
        case 0x9370:
          goto switchD_00126e3c_caseD_9370;
        case 0x9371:
          goto switchD_00126e3c_caseD_9371;
        case 0x9380:
          goto switchD_00126e3c_caseD_9380;
        case 0x9381:
          goto switchD_00126e3c_caseD_9381;
        default:
          if (local_2c == 0x9270) goto LAB_00126f64;
          if (local_2c == 0x9280) goto LAB_00126634;
        }
      }
      _printk(&DAT_001358e4,"haptic_hv",0x1fe,"parse_chipid");
      usleep_range_state(2000,0x9c4,2);
      iVar2 = read_chipid(param_1,&local_2c);
      if (iVar2 < 0) {
        _printk(&DAT_00132d5a,"haptic_hv",0x169,"parse_chipid",iVar2);
      }
      if (local_2c < 0x7280) {
        if (local_2c < 0x7150) {
          switch(local_2c) {
          case 4:
            goto switchD_0012641c_caseD_4;
          case 5:
            goto switchD_0012641c_caseD_5;
          case 6:
            goto switchD_0012641c_caseD_6;
          case 7:
            goto switchD_0012641c_caseD_7;
          default:
            if (local_2c == 0x95) goto LAB_00126e8c;
            if (local_2c == 0x97) goto LAB_00126590;
          }
        }
        else if (local_2c < 0x7171) {
          if (local_2c == 0x7150) goto LAB_00126ee4;
          if (local_2c == 0x7170) goto LAB_001265e8;
        }
        else {
          if (local_2c == 0x7171) goto LAB_00126db0;
          if (local_2c == 0x7180) goto LAB_00126de4;
          if (local_2c == 0x7270) goto LAB_001264ec;
        }
      }
      else if (local_2c < 0x9270) {
        if (local_2c == 0x7280) goto LAB_00126d18;
        if (local_2c == 0x9250) goto LAB_00126d4c;
        if (local_2c == 0x9260) goto LAB_0012648c;
      }
      else {
        switch(local_2c) {
        case 0x9360:
          goto switchD_00126e3c_caseD_9360;
        case 0x9361:
        case 0x9362:
        case 0x9363:
        case 0x9364:
        case 0x9365:
        case 0x9366:
        case 0x9367:
        case 0x9368:
        case 0x9369:
        case 0x936a:
        case 0x936b:
        case 0x936c:
        case 0x936d:
        case 0x936e:
        case 0x936f:
        case 0x9372:
        case 0x9373:
        case 0x9374:
        case 0x9375:
        case 0x9376:
        case 0x9377:
        case 0x9378:
        case 0x9379:
        case 0x937a:
        case 0x937b:
        case 0x937c:
        case 0x937d:
        case 0x937e:
        case 0x937f:
          break;
        case 0x9370:
          goto switchD_00126e3c_caseD_9370;
        case 0x9371:
          goto switchD_00126e3c_caseD_9371;
        case 0x9380:
          goto switchD_00126e3c_caseD_9380;
        case 0x9381:
          goto switchD_00126e3c_caseD_9381;
        default:
          if (local_2c == 0x9270) goto LAB_00126f64;
          if (local_2c == 0x9280) goto LAB_00126634;
        }
      }
      _printk(&DAT_001358e4,"haptic_hv",0x1fe,"parse_chipid");
      usleep_range_state(2000,0x9c4,2);
      iVar2 = read_chipid(param_1,&local_2c);
      if (iVar2 < 0) {
        _printk(&DAT_00132d5a,"haptic_hv",0x169,"parse_chipid",iVar2);
      }
      if (local_2c < 0x7280) {
        if (local_2c < 0x7150) {
          switch(local_2c) {
          case 4:
            goto switchD_0012641c_caseD_4;
          case 5:
            goto switchD_0012641c_caseD_5;
          case 6:
            goto switchD_0012641c_caseD_6;
          case 7:
            goto switchD_0012641c_caseD_7;
          default:
            if (local_2c == 0x95) goto LAB_00126e8c;
            if (local_2c == 0x97) goto LAB_00126590;
          }
        }
        else if (local_2c < 0x7171) {
          if (local_2c == 0x7150) goto LAB_00126ee4;
          if (local_2c == 0x7170) goto LAB_001265e8;
        }
        else {
          if (local_2c == 0x7171) goto LAB_00126db0;
          if (local_2c == 0x7180) goto LAB_00126de4;
          if (local_2c == 0x7270) goto LAB_001264ec;
        }
      }
      else if (local_2c < 0x9270) {
        if (local_2c == 0x7280) goto LAB_00126d18;
        if (local_2c == 0x9250) goto LAB_00126d4c;
        if (local_2c == 0x9260) goto LAB_0012648c;
      }
      else {
        switch(local_2c) {
        case 0x9360:
          goto switchD_00126e3c_caseD_9360;
        case 0x9361:
        case 0x9362:
        case 0x9363:
        case 0x9364:
        case 0x9365:
        case 0x9366:
        case 0x9367:
        case 0x9368:
        case 0x9369:
        case 0x936a:
        case 0x936b:
        case 0x936c:
        case 0x936d:
        case 0x936e:
        case 0x936f:
        case 0x9372:
        case 0x9373:
        case 0x9374:
        case 0x9375:
        case 0x9376:
        case 0x9377:
        case 0x9378:
        case 0x9379:
        case 0x937a:
        case 0x937b:
        case 0x937c:
        case 0x937d:
        case 0x937e:
        case 0x937f:
          break;
        case 0x9370:
          goto switchD_00126e3c_caseD_9370;
        case 0x9371:
          goto switchD_00126e3c_caseD_9371;
        case 0x9380:
          goto switchD_00126e3c_caseD_9380;
        case 0x9381:
          goto switchD_00126e3c_caseD_9381;
        default:
          if (local_2c == 0x9270) goto LAB_00126f64;
          if (local_2c == 0x9280) goto LAB_00126634;
        }
      }
      _printk(&DAT_001358e4,"haptic_hv",0x1fe,"parse_chipid");
      usleep_range_state(2000,0x9c4,2);
      iVar2 = read_chipid(param_1,&local_2c);
      if (iVar2 < 0) {
        _printk(&DAT_00132d5a,"haptic_hv",0x169,"parse_chipid",iVar2);
      }
      if (local_2c < 0x7280) {
        if (local_2c < 0x7150) {
          switch(local_2c) {
          case 4:
            goto switchD_0012641c_caseD_4;
          case 5:
            goto switchD_0012641c_caseD_5;
          case 6:
            goto switchD_0012641c_caseD_6;
          case 7:
            goto switchD_0012641c_caseD_7;
          default:
            if (local_2c == 0x95) goto LAB_00126e8c;
            if (local_2c == 0x97) goto LAB_00126590;
          }
        }
        else if (local_2c < 0x7171) {
          if (local_2c == 0x7150) goto LAB_00126ee4;
          if (local_2c == 0x7170) goto LAB_001265e8;
        }
        else {
          if (local_2c == 0x7171) goto LAB_00126db0;
          if (local_2c == 0x7180) goto LAB_00126de4;
          if (local_2c == 0x7270) goto LAB_001264ec;
        }
      }
      else if (local_2c < 0x9270) {
        if (local_2c == 0x7280) goto LAB_00126d18;
        if (local_2c == 0x9250) goto LAB_00126d4c;
        if (local_2c == 0x9260) goto LAB_0012648c;
      }
      else {
        switch(local_2c) {
        case 0x9360:
          goto switchD_00126e3c_caseD_9360;
        case 0x9361:
        case 0x9362:
        case 0x9363:
        case 0x9364:
        case 0x9365:
        case 0x9366:
        case 0x9367:
        case 0x9368:
        case 0x9369:
        case 0x936a:
        case 0x936b:
        case 0x936c:
        case 0x936d:
        case 0x936e:
        case 0x936f:
        case 0x9372:
        case 0x9373:
        case 0x9374:
        case 0x9375:
        case 0x9376:
        case 0x9377:
        case 0x9378:
        case 0x9379:
        case 0x937a:
        case 0x937b:
        case 0x937c:
        case 0x937d:
        case 0x937e:
        case 0x937f:
          break;
        case 0x9370:
          goto switchD_00126e3c_caseD_9370;
        case 0x9371:
          goto switchD_00126e3c_caseD_9371;
        case 0x9380:
          goto switchD_00126e3c_caseD_9380;
        case 0x9381:
          goto switchD_00126e3c_caseD_9381;
        default:
          if (local_2c == 0x9270) goto LAB_00126f64;
          if (local_2c == 0x9280) goto LAB_00126634;
        }
      }
      _printk(&DAT_001358e4,"haptic_hv",0x1fe,"parse_chipid");
      usleep_range_state(2000,0x9c4,2);
      iVar2 = -0x16;
      goto LAB_00126f98;
    case 0x9370:
switchD_00126e3c_caseD_9370:
      puVar3 = &DAT_00133a98;
      *(undefined4 *)(param_1 + 0x50) = 0x9370;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x40;
      uVar4 = 0x1e6;
      break;
    case 0x9371:
switchD_00126e3c_caseD_9371:
      puVar3 = &DAT_00133abb;
      *(undefined4 *)(param_1 + 0x50) = 0x9371;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x80;
      uVar4 = 500;
      break;
    case 0x9380:
switchD_00126e3c_caseD_9380:
      puVar3 = &DAT_00137fd9;
      *(undefined4 *)(param_1 + 0x50) = 0x9380;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x40;
      uVar4 = 0x1ec;
      break;
    case 0x9381:
switchD_00126e3c_caseD_9381:
      puVar3 = &DAT_00131db3;
      *(undefined4 *)(param_1 + 0x50) = 0x9381;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 0x30) = 0x80;
      uVar4 = 0x1fa;
      break;
    default:
      if (local_2c == 0x9270) {
LAB_00126f64:
        *(undefined1 *)(param_1 + 10) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0x9270;
        puVar3 = &DAT_00133429;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 0x1d2;
      }
      else {
        if (local_2c != 0x9280) goto switchD_00126544_caseD_9361;
LAB_00126634:
        *(undefined1 *)(param_1 + 10) = 0;
        *(undefined4 *)(param_1 + 0x50) = 0x9280;
        puVar3 = &DAT_001354a5;
        *(undefined1 *)(param_1 + 0x30) = 0x20;
        uVar4 = 0x1d8;
      }
    }
  }
  _printk(puVar3,"haptic_hv",uVar4,"parse_chipid");
  iVar2 = 0;
LAB_00126f98:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// irq_config @ 00126fc8 size=256
// signature: undefined irq_config(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

int irq_config(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  if ((*(uint *)(param_2 + 0x54) < 0x200) && ((*(byte *)(param_2 + 9) & 1) == 0)) {
    pcVar3 = *(code **)(*(long *)(param_2 + 0x6a8) + 0xf8);
    if (*(int *)(pcVar3 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x127018);
      (*pcVar3)();
    }
    (*pcVar3)(param_2);
    gpio_to_desc(*(undefined4 *)(param_2 + 0x54));
    uVar1 = gpiod_to_irq();
    iVar2 = devm_request_threaded_irq(param_1,uVar1,0,irq_handle,0x2002,"aw_haptic",param_2);
    if (iVar2 != 0) {
      gpio_to_desc(*(undefined4 *)(param_2 + 0x54));
      uVar1 = gpiod_to_irq();
      _printk(&DAT_00131dd7,"haptic_hv",0x687,"irq_config",uVar1,iVar2);
    }
  }
  else {
    _dev_info(param_1,"skipping IRQ registration");
    iVar2 = 0;
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) | 1;
  }
  return iVar2;
}



//------------------------------------------------------------
// tiktap_init @ 001270c8 size=596
// signature: undefined tiktap_init(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

undefined8 tiktap_init(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar4 = proc_create("tiktap_buf",0x1b4,0,tiktap_proc_ops);
  if (lVar4 == 0) {
    _printk(&DAT_00136cba,"haptic_hv",0xe85,"tiktap_init");
    uVar6 = 0xffffffff;
  }
  else {
    _printk(&DAT_00131e28,"haptic_hv",0xe88,"tiktap_init");
    lVar5 = __get_free_pages(0xcc0,2);
    if (lVar5 == 0) {
      _printk(&DAT_00131e53,"haptic_hv",0xe8d,"tiktap_init");
      uVar6 = 0xfffffff4;
    }
    else {
      puVar1 = (ulong *)((((lVar5 << 8) >> 8) + 0x8000000000U >> 6 & 0x3ffffffffffffc0) -
                        0x200000000);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x1000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      *(long *)(lVar5 + 4) = lVar5 + 0x400;
      *(long *)(lVar5 + 0x404) = lVar5 + 0x800;
      *(long *)(lVar5 + 0x804) = lVar5 + 0xc00;
      *(long *)(lVar5 + 0xc04) = lVar5 + 0x1000;
      *(long *)(lVar5 + 0x1004) = lVar5 + 0x1400;
      *(undefined1 *)(lVar5 + 0x1001) = 4;
      *(long *)(lVar5 + 0x1404) = lVar5 + 0x1800;
      *(long *)(lVar5 + 0x1804) = lVar5 + 0x1c00;
      *(undefined1 *)(lVar5 + 0x1401) = 5;
      *(undefined1 *)(lVar5 + 0x1801) = 6;
      *(undefined1 *)(lVar5 + 0x801) = 2;
      *(undefined1 *)(lVar5 + 0xc01) = 3;
      *(long *)(lVar5 + 0x1c04) = lVar5 + 0x2000;
      *(undefined1 *)(lVar5 + 0x1c01) = 7;
      *(undefined1 *)(lVar5 + 0x2001) = 8;
      *(undefined1 *)(lVar5 + 0x2401) = 9;
      *(undefined1 *)(lVar5 + 0x2801) = 10;
      *(undefined1 *)(lVar5 + 0x2c01) = 0xb;
      *(undefined1 *)(lVar5 + 0x3001) = 0xc;
      *(long *)(lVar5 + 0x2004) = lVar5 + 0x2400;
      uVar6 = 0;
      *(long *)(lVar5 + 0x2404) = lVar5 + 0x2800;
      *(long *)(lVar5 + 0x2804) = lVar5 + 0x2c00;
      *(long *)(lVar5 + 0x2c04) = lVar5 + 0x3000;
      *(long *)(lVar5 + 0x3004) = lVar5 + 0x3400;
      *(long *)(lVar5 + 0x3404) = lVar5 + 0x3800;
      *(long *)(lVar5 + 0x3804) = lVar5 + 0x3c00;
      *(long *)(lVar5 + 0x3c04) = lVar5;
      *(undefined1 *)(lVar5 + 1) = 0;
      *(undefined1 *)(lVar5 + 0x401) = 1;
      *(undefined1 *)(lVar5 + 0x3401) = 0xd;
      *(undefined1 *)(lVar5 + 0x3801) = 0xe;
      *(undefined1 *)(lVar5 + 0x3c01) = 0xf;
      *(undefined1 *)(param_1 + 0x27a) = 1;
      *(long *)(param_1 + 0x2b0) = lVar4;
      *(long *)(param_1 + 0x2b8) = lVar5;
      *(undefined1 *)(param_1 + 0x278) = 0;
      *(undefined8 *)(param_1 + 0x280) = 0xfffffffe0;
      *(long *)(param_1 + 0x288) = param_1 + 0x288;
      *(long *)(param_1 + 0x290) = param_1 + 0x288;
      *(code **)(param_1 + 0x298) = tiktap_work_routine;
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// vibrator_init @ 0012732c size=492
// signature: undefined vibrator_init(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

void vibrator_init(long param_1)

{
  long lVar1;
  int iVar2;
  char *local_48;
  undefined2 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00132e8a,"haptic_hv",0xeb2,"vibrator_init");
  _printk(&DAT_00134f37,"haptic_hv",0xece,"vibrator_init");
  *(undefined8 *)(param_1 + 0xa8) = "vibrator";
  *(code **)(param_1 + 0xd8) = brightness_get;
  *(code **)(param_1 + 200) = brightness_set;
  iVar2 = devm_led_classdev_register_ext
                    (*(long *)(param_1 + 0x2c8) + 0x20,(undefined8 *)(param_1 + 0xa8),0);
  if (iVar2 < 0) {
    _printk(&DAT_00135533,"haptic_hv",0xedd,"vibrator_init");
  }
  else {
    iVar2 = sysfs_create_group(*(undefined8 *)(param_1 + 0xf8),vibrator_attribute_group);
    if (iVar2 < 0) {
      _printk(&DAT_00134bdf,"haptic_hv",0xee2,"vibrator_init");
    }
    else {
      local_40 = 0;
      local_48 = "trigger";
      sysfs_remove_file_ns(*(undefined8 *)(param_1 + 0xf8),&local_48,0);
      hrtimer_init(param_1 + 0x380,1,1);
      *(code **)(param_1 + 0x3a8) = vibrator_timer_func;
      *(undefined8 *)(param_1 + 0x4e0) = 0xfffffffe0;
      *(long *)(param_1 + 0x4e8) = param_1 + 0x4e8;
      *(long *)(param_1 + 0x4f0) = param_1 + 0x4e8;
      *(code **)(param_1 + 0x4f8) = vibrator_work_routine;
      *(undefined8 *)(param_1 + 0x3f8) = 0xfffffffe0;
      *(long *)(param_1 + 0x400) = param_1 + 0x400;
      *(long *)(param_1 + 0x408) = param_1 + 0x400;
      *(code **)(param_1 + 0x410) = rtp_work_routine;
      __mutex_init(param_1 + 0x350,"&aw_haptic->lock",&vibrator_init___key);
      __mutex_init(param_1 + 0x3c8,"&aw_haptic->rtp_lock",&vibrator_init___key_97);
      *(undefined8 *)(param_1 + 0x2d8) = 0x100000000;
      *(long *)(param_1 + 0x2e0) = param_1 + 0x2e0;
      *(long *)(param_1 + 0x2e8) = param_1 + 0x2e0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// haptic_init @ 00127518 size=544
// signature: undefined haptic_init(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

void haptic_init(long param_1)

{
  code *pcVar1;
  
  _printk(&DAT_00132e8a,"haptic_hv",0xeff,"haptic_init");
  *(undefined4 *)(param_1 + 0x80) = 0x3c;
  *(undefined8 *)(param_1 + 0x5a0) = 0x534600000001;
  *(long *)(param_1 + 0x670) = param_1 + 0x670;
  *(long *)(param_1 + 0x678) = param_1 + 0x670;
  hrtimer_init(param_1 + 0x5e8,1,1);
  *(code **)(param_1 + 0x610) = audio_timer_func;
  *(undefined8 *)(param_1 + 0x630) = 0xfffffffe0;
  *(long *)(param_1 + 0x638) = param_1 + 0x638;
  *(long *)(param_1 + 0x640) = param_1 + 0x638;
  *(code **)(param_1 + 0x648) = audio_work_routine;
  __mutex_init(param_1 + 0x5b8,"&aw_haptic->haptic_audio.lock",&haptic_init___key);
  *(long *)(param_1 + 0x660) = param_1 + 0x660;
  *(long *)(param_1 + 0x668) = param_1 + 0x660;
  mutex_lock(param_1 + 0x350);
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x84) = 0xff;
  *(undefined1 *)(param_1 + 0xf) = *(undefined1 *)(param_1 + 0x528);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x88);
  if (*(int *)(pcVar1 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x127614);
    (*pcVar1)();
  }
  (*pcVar1)(param_1,0);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x127640);
    (*pcVar1)();
  }
  (*pcVar1)(param_1,1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0xf0);
  if (*(int *)(pcVar1 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x127668);
    (*pcVar1)();
  }
  (*pcVar1)(param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x68);
  if (*(int *)(pcVar1 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x127690);
    (*pcVar1)();
  }
  (*pcVar1)(param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x90);
  if (*(int *)(pcVar1 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1276bc);
    (*pcVar1)();
  }
  (*pcVar1)(param_1,*(undefined4 *)(param_1 + 0x38));
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0xa0);
  if (*(int *)(pcVar1 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1276e8);
    (*pcVar1)();
  }
  (*pcVar1)(param_1,*(undefined1 *)(param_1 + 0x58c));
  pcVar1 = *(code **)(*(long *)(param_1 + 0x6a8) + 0xa8);
  if (*(int *)(pcVar1 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x127714);
    (*pcVar1)();
  }
  (*pcVar1)(param_1,1);
  f0_cali(param_1);
  mutex_unlock(param_1 + 0x350);
  return;
}



//------------------------------------------------------------
// ram_work_init @ 00127738 size=124
// signature: undefined ram_work_init(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_work_init(long param_1)

{
  *(undefined8 *)(param_1 + 0x458) = 0xfffffffe0;
  *(long *)(param_1 + 0x460) = param_1 + 0x460;
  *(long *)(param_1 + 0x468) = param_1 + 0x460;
  *(code **)(param_1 + 0x470) = ram_work_routine;
  init_timer_key(param_1 + 0x488,&delayed_work_timer_fn,0x200000,0,0);
  queue_delayed_work_on(0x20,_system_wq,param_1 + 0x458,2000);
  return;
}



//------------------------------------------------------------
// read_chipid @ 001277b4 size=420
// signature: undefined read_chipid(void)
// callers: [aw_i2c_probe, parse_chipid]
//------------------------------------------------------------

int read_chipid(long param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  undefined1 local_60 [4];
  ushort local_5c [2];
  undefined2 local_58;
  undefined6 uStack_56;
  undefined1 *local_50;
  undefined8 local_48;
  ushort *local_40;
  long local_38;
  
  local_50 = local_60;
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x2c8);
  local_5c[0] = 0;
  local_40 = local_5c;
  local_60[0] = 0;
  _local_58 = CONCAT62(0x10000,*(undefined2 *)(lVar3 + 2));
  local_48._0_6_ = CONCAT42(0x10001,*(undefined2 *)(lVar3 + 2));
  local_48 = (ulong)(uint6)local_48;
  iVar1 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
  if (iVar1 < 0) {
LAB_00127900:
    _printk(&DAT_001343e2,"haptic_hv",0x76,"haptic_hv_i2c_reads");
  }
  else {
    if (iVar1 != 2) {
LAB_00127924:
      _printk(&DAT_001324a5,"haptic_hv",0x79,"haptic_hv_i2c_reads");
      iVar1 = -6;
      goto LAB_001278d0;
    }
    uVar2 = (uint)(byte)local_5c[0];
    if (((byte)local_5c[0] < 4) || ((byte)local_5c[0] - 0x80 < 4)) {
      lVar3 = *(long *)(param_1 + 0x2c8);
      local_40 = local_5c;
      local_60[0] = 0x57;
      _local_58 = CONCAT62(0x10000,*(undefined2 *)(lVar3 + 2));
      local_48._0_6_ = CONCAT42(0x20001,*(undefined2 *)(lVar3 + 2));
      local_48 = (ulong)(uint6)local_48;
      local_50 = local_60;
      iVar1 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
      if (iVar1 < 0) goto LAB_00127900;
      if (iVar1 != 2) goto LAB_00127924;
      uVar2 = (uint)(local_5c[0] >> 8) | (local_5c[0] & 0xff00ff) << 8;
    }
    else {
      iVar1 = 0;
    }
    *param_2 = uVar2;
  }
LAB_001278d0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// irq_handle @ 0012795c size=264
// signature: undefined irq_handle(void)
// callers: []
//------------------------------------------------------------

undefined8 irq_handle(undefined8 param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  
  do {
    pcVar2 = *(code **)(*(long *)(param_2 + 0x6a8) + 0x20);
    if (*(int *)(pcVar2 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1279c0);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(param_2);
    if (iVar1 == 1) {
      if (*(char *)(param_2 + 5) == '\0') {
        _printk(&DAT_001354c8,"haptic_hv",0x66f,"irq_handle",0);
      }
      else {
        mutex_lock(param_2 + 0x3c8);
        rtp_play(param_2);
        mutex_unlock(param_2 + 0x3c8);
      }
    }
    if (*(char *)(param_2 + 0xb) != '\x02') {
      pcVar2 = *(code **)(*(long *)(param_2 + 0x6a8) + 0x100);
      if (*(int *)(pcVar2 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x127a24);
        (*pcVar2)();
      }
      (*pcVar2)(param_2,0);
    }
  } while (iVar1 != 0);
  return 1;
}



//------------------------------------------------------------
// rtp_play @ 00127a64 size=392
// signature: undefined rtp_play(void)
// callers: [irq_handle, rtp_work_routine]
//------------------------------------------------------------

void rtp_play(long param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  code *pcVar7;
  int *piVar8;
  
  piVar8 = *(int **)(param_1 + 0x6e8);
  while( true ) {
    pcVar7 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x160);
    if (*(int *)(pcVar7 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x127aa4);
      (*pcVar7)();
    }
    cVar3 = (*pcVar7)(param_1);
    if (cVar3 != '\0') {
      return;
    }
    if (*(char *)(param_1 + 0xb) != '\x02') {
      return;
    }
    if (piVar8 == (int *)0x0) break;
    uVar2 = *(uint *)(param_1 + 0x78);
    uVar4 = *(uint *)(param_1 + 0x520);
    if (uVar4 <= uVar2) {
      uVar4 = uVar4 >> 2;
    }
    uVar1 = *piVar8 - uVar2;
    if (uVar4 <= *piVar8 - uVar2) {
      uVar1 = uVar4;
    }
    pcVar7 = *(code **)(*(long *)(param_1 + 0x6a8) + 0xc0);
    if (*(int *)(pcVar7 + -4) != 0x6c91e1cc) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x127b14);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,(long)piVar8 + (ulong)uVar2 + 4,uVar1);
    *(uint *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + uVar1;
    pcVar7 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x150);
    if (*(int *)(pcVar7 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x127b48);
      (*pcVar7)();
    }
    uVar4 = (*pcVar7)(param_1);
    if ((*(int *)(param_1 + 0x78) == *piVar8) || ((uVar4 & 0xf) == 0)) {
      if (*(int *)(param_1 + 0x78) == *piVar8) {
        puVar5 = &DAT_00135918;
        uVar6 = 0x4d9;
      }
      else {
        puVar5 = &DAT_00131e05;
        uVar6 = 0x4d7;
      }
      _printk(puVar5,"haptic_hv",uVar6,"rtp_play");
      *(undefined4 *)(param_1 + 0x78) = 0;
      *(undefined1 *)(param_1 + 5) = 0;
      return;
    }
  }
  _printk(&DAT_0013309e,"haptic_hv",0x4b3,"rtp_play");
  return;
}



//------------------------------------------------------------
// tiktap_work_routine @ 00127bf0 size=984
// signature: undefined tiktap_work_routine(void)
// callers: []
//------------------------------------------------------------

void tiktap_work_routine(long param_1)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined *puVar6;
  undefined8 uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  int iVar11;
  byte *pbVar12;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  lVar9 = param_1 + 0xd0;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = param_1 + -0x280;
  pbVar12 = *(byte **)(param_1 + 0x38);
  mutex_lock(lVar9);
  *(undefined1 *)(param_1 + -6) = 0;
  pcVar8 = *(code **)(*(long *)(param_1 + 0x428) + 0x88);
  if (*(int *)(pcVar8 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x127c64);
    (*pcVar8)();
  }
  (*pcVar8)(lVar10,2);
  pcVar8 = *(code **)(*(long *)(param_1 + 0x428) + 0x108);
  if (*(int *)(pcVar8 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x127c90);
    (*pcVar8)();
  }
  (*pcVar8)(lVar10,0);
  iVar3 = 99;
  do {
    if (*pbVar12 == 0x55) {
      pcVar8 = *(code **)(*(long *)(param_1 + 0x428) + 0x58);
      if (*(int *)(pcVar8 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x127cf4);
        (*pcVar8)();
      }
      (*pcVar8)(lVar10,1);
      __const_udelay(0x418958);
      if (0 < iVar3) {
        *(undefined1 *)(param_1 + -8) = 1;
        mutex_unlock(lVar9);
        lVar9 = param_1 + 0x148;
        mutex_lock(lVar9);
        lVar1 = param_1 + 0x470;
        uVar5 = cpu_latency_qos_request_active(lVar1);
        if ((uVar5 & 1) == 0) {
          cpu_latency_qos_add_request(lVar1,0);
        }
        local_78 = 0;
        uStack_70 = 0;
        ktime_get_coarse_real_ts64(&local_78);
        timespec64_to_jiffies(&local_78);
        iVar3 = jiffies_to_msecs();
        local_78 = 0;
        uStack_70 = 0;
        ktime_get_coarse_real_ts64(&local_78);
        timespec64_to_jiffies(&local_78);
        uVar4 = jiffies_to_msecs();
        if (iVar3 + 800U < uVar4) goto LAB_00127dec;
        iVar11 = 0;
        goto LAB_00127e5c;
      }
      break;
    }
    if (*(char *)(param_1 + -6) != '\0') goto LAB_00127d38;
    __const_udelay(0x418958);
    iVar3 = iVar3 + -1;
  } while (iVar3 != -1);
  _printk(&DAT_001354e6,"haptic_hv",0xd9f,"tiktap_work_routine",*pbVar12);
  goto LAB_00127d30;
LAB_00127e5c:
  do {
    pcVar8 = *(code **)(*(long *)(param_1 + 0x428) + 0x168);
    if (*(int *)(pcVar8 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x127e80);
      (*pcVar8)();
    }
    uVar5 = (*pcVar8)(lVar10);
    pcVar8 = *(code **)(*(long *)(param_1 + 0x428) + 0x150);
    if (*(int *)(pcVar8 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x127eac);
      (*pcVar8)();
    }
    bVar2 = (*pcVar8)(lVar10);
    if ((bVar2 & 0xf) != 8) {
      puVar6 = &DAT_001376d8;
      uVar7 = 0xdb2;
LAB_00127fa8:
      _printk(puVar6,"haptic_hv",uVar7,"tiktap_work_routine",bVar2);
      goto LAB_00127fac;
    }
    bVar2 = *pbVar12;
    if (*(char *)(param_1 + -6) != '\0') {
LAB_00127f68:
      puVar6 = &DAT_0013344c;
      uVar7 = 0xdb8;
      goto LAB_00127fa8;
    }
    if (bVar2 == 0x55) {
      if ((uVar5 & 1) == 0) goto LAB_00127e2c;
      _printk(&DAT_00134b2a,"haptic_hv",0xdbc,"tiktap_work_routine",iVar11,pbVar12[1],
              (long)*(short *)(pbVar12 + 2));
      pcVar8 = *(code **)(*(long *)(param_1 + 0x428) + 0xc0);
      if (*(int *)(pcVar8 + -4) != 0x6c91e1cc) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x127f34);
        (*pcVar8)();
      }
      (*pcVar8)(lVar10,pbVar12 + 0x15,(long)*(short *)(pbVar12 + 2));
      *pbVar12 = 0xaa;
      pbVar12 = *(byte **)(pbVar12 + 4);
      local_78 = 0;
      uStack_70 = 0;
      ktime_get_coarse_real_ts64(&local_78);
      timespec64_to_jiffies(&local_78);
      iVar3 = jiffies_to_msecs();
      iVar11 = iVar11 + 1;
    }
    else {
      if ((bVar2 == 0xff) || (bVar2 == 0xaa)) goto LAB_00127f68;
LAB_00127e2c:
      __const_udelay(0x418958);
    }
    local_78 = 0;
    uStack_70 = 0;
    ktime_get_coarse_real_ts64(&local_78);
    timespec64_to_jiffies(&local_78);
    uVar4 = jiffies_to_msecs();
  } while (uVar4 <= iVar3 + 800U);
LAB_00127dec:
  _printk(&DAT_0013593e,"haptic_hv",0xdac,"tiktap_work_routine");
LAB_00127fac:
  uVar5 = cpu_latency_qos_request_active(lVar1);
  if ((uVar5 & 1) != 0) {
    cpu_latency_qos_remove_request(lVar1);
  }
LAB_00127d30:
  *(undefined1 *)(param_1 + -6) = 1;
LAB_00127d38:
  mutex_unlock(lVar9);
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tiktap_file_open @ 00127fcc size=20
// signature: undefined tiktap_file_open(void)
// callers: []
//------------------------------------------------------------

undefined8 tiktap_file_open(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = g_aw_haptic;
  return 0;
}



//------------------------------------------------------------
// tiktap_unlocked_ioctl @ 00127fe4 size=1304
// signature: undefined tiktap_unlocked_ioctl(void)
// callers: [tiktap_compat_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tiktap_unlocked_ioctl(long param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined1 *puVar7;
  long lVar8;
  undefined4 local_3c;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0xd8);
  local_3c = 0;
  if (param_2 == 0xff09) {
    puVar7 = *(undefined1 **)(*(undefined1 **)(lVar8 + 0x2b8) + 4);
    **(undefined1 **)(lVar8 + 0x2b8) = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    *puVar3 = 0xff;
    **(undefined1 **)(puVar3 + 4) = 0xff;
    *(undefined1 *)(lVar8 + 0x27a) = 1;
    mutex_lock(lVar8 + 0x350);
    pcVar4 = *(code **)(*(long *)(lVar8 + 0x6a8) + 0x40);
    if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1280d8);
      (*pcVar4)();
    }
    (*pcVar4)(lVar8);
    mutex_unlock(lVar8 + 0x350);
    queue_work_on(0x20,*(undefined8 *)(lVar8 + 0x510),lVar8 + 0x280);
    goto LAB_001280f4;
  }
  switch(param_2) {
  case 0xff01:
    _printk(&DAT_00134b04,"haptic_hv",0xde6,"tiktap_unlocked_ioctl",param_2);
    local_3c = *(undefined4 *)(lVar8 + 100);
    puVar5 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_3, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar6 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar6) {
LAB_0012842c:
      uVar2 = 0xfffffffffffffff2;
      goto LAB_001280f8;
    }
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar5 = (undefined8 *)puVar5[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar5;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    lVar8 = __arch_copy_to_user(puVar5,param_3 & 0xff7fffffffffffff,&local_3c,4);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    goto LAB_0012841c;
  case 0xff02:
    _printk(&DAT_001341c7,"haptic_hv",0xde0,"tiktap_unlocked_ioctl",param_2);
    local_3c = *(undefined4 *)(lVar8 + 0x50);
    puVar5 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_3, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar6 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar6) goto LAB_0012842c;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar5 = (undefined8 *)puVar5[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar5;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    lVar8 = __arch_copy_to_user(puVar5,param_3 & 0xff7fffffffffffff,&local_3c,4);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
LAB_0012841c:
    uVar2 = 0;
    if (lVar8 != 0) {
      uVar2 = 0xfffffffffffffff2;
    }
    goto LAB_001280f8;
  default:
    _printk(&DAT_00132544,"haptic_hv",0xe05,"tiktap_unlocked_ioctl",param_2);
    break;
  case 0xff04:
    _printk(&DAT_00131a63,"haptic_hv",0xdfd,"tiktap_unlocked_ioctl",param_2);
    if (0x7f < param_3) {
      param_3 = 0x80;
    }
    mutex_lock(lVar8 + 0x350);
    pcVar4 = *(code **)(*(long *)(lVar8 + 0x6a8) + 0x80);
    if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128494);
      (*pcVar4)();
    }
    (*pcVar4)(lVar8,param_3 & 0xffffffff);
    mutex_unlock(lVar8 + 0x350);
    break;
  case 0xff0b:
    _printk(&DAT_0013708e,"haptic_hv",0xdec,"tiktap_unlocked_ioctl",param_2);
    puVar7 = *(undefined1 **)(*(undefined1 **)(lVar8 + 0x2b8) + 4);
    **(undefined1 **)(lVar8 + 0x2b8) = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    puVar7 = *(undefined1 **)(puVar3 + 4);
    *puVar3 = 0xff;
    puVar3 = *(undefined1 **)(puVar7 + 4);
    *puVar7 = 0xff;
    *puVar3 = 0xff;
    **(undefined1 **)(puVar3 + 4) = 0xff;
    *(undefined1 *)(lVar8 + 0x27a) = 1;
    mutex_lock(lVar8 + 0x350);
    pcVar4 = *(code **)(*(long *)(lVar8 + 0x6a8) + 0x40);
    if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128320);
      (*pcVar4)();
    }
    (*pcVar4)(lVar8);
    mutex_unlock(lVar8 + 0x350);
  }
LAB_001280f4:
  uVar2 = 0;
LAB_001280f8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// tiktap_compat_ioctl @ 00128530 size=32
// signature: undefined tiktap_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

long tiktap_compat_ioctl(void)

{
  int iVar1;
  
  iVar1 = tiktap_unlocked_ioctl();
  return (long)iVar1;
}



//------------------------------------------------------------
// tiktap_file_mmap @ 00128554 size=324
// signature: undefined tiktap_file_mmap(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int tiktap_file_mmap(long param_1,long *param_2)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  
  if (param_2 != (long *)0x0) {
    lVar4 = sp_el0;
    lVar7 = *(long *)(param_1 + 0xd8);
    lVar8 = param_2[3];
    lVar4 = vm_get_page_prot(*(ulong *)(*(long *)(lVar4 + 0x5a0) + 0xf8) | 0xfb);
    if (lVar8 == lVar4) {
      if (param_2[1] - *param_2 == 0x4000) {
        lVar4 = (*(long *)(lVar7 + 0x2b8) << 8) >> 8;
        uVar1 = lVar4 + 0x8000000000;
        uVar2 = uVar1 + _memstart_addr;
        if (uVar1 >> 0x26 != 0) {
          uVar2 = lVar4 - _kimage_voffset;
        }
        iVar3 = remap_pfn_range(param_2,*param_2,uVar2 >> 0xc,0x4000,param_2[3]);
        if (iVar3 == 0) {
          puVar5 = &DAT_00132a5b;
          uVar6 = 0xe34;
        }
        else {
          puVar5 = &DAT_00137ffc;
          uVar6 = 0xe30;
        }
        _printk(puVar5,"haptic_hv",uVar6,"tiktap_file_mmap");
        return iVar3;
      }
      puVar5 = &DAT_001327ab;
      uVar6 = 0xe27;
      goto LAB_00128634;
    }
  }
  puVar5 = &DAT_00131e82;
  uVar6 = 0xe22;
LAB_00128634:
  _printk(puVar5,"haptic_hv",uVar6,"tiktap_file_mmap");
  return -1;
}



//------------------------------------------------------------
// brightness_get @ 0012869c size=8
// signature: undefined brightness_get(void)
// callers: []
//------------------------------------------------------------

undefined4 brightness_get(long param_1)

{
  return *(undefined4 *)(param_1 + -0x4c);
}



//------------------------------------------------------------
// brightness_set @ 001286a8 size=176
// signature: undefined brightness_set(void)
// callers: []
//------------------------------------------------------------

void brightness_set(long param_1,undefined4 param_2)

{
  _printk(&DAT_00132e8a,"haptic_hv",0x800,"brightness_set");
  if (*(char *)(param_1 + -0xa2) == '\0') {
    _printk(&DAT_001325b9,"haptic_hv",0x802,"brightness_set");
  }
  else {
    mutex_lock(param_1 + 0x2a8);
    *(undefined4 *)(param_1 + -0x4c) = param_2;
    *(undefined4 *)(param_1 + -0x60) = param_2;
    *(undefined1 *)(param_1 + -0x99) = 1;
    mutex_unlock(param_1 + 0x2a8);
    queue_work_on(0x20,*(undefined8 *)(param_1 + 0x468),param_1 + 0x438);
  }
  return;
}



//------------------------------------------------------------
// vibrator_timer_func @ 0012875c size=52
// signature: undefined vibrator_timer_func(void)
// callers: []
//------------------------------------------------------------

undefined8 vibrator_timer_func(long param_1)

{
  *(undefined4 *)(param_1 + -0x338) = 0;
  queue_work_on(0x20,*(undefined8 *)(param_1 + 400),param_1 + 0x160);
  return 0;
}



//------------------------------------------------------------
// vibrator_work_routine @ 00128794 size=876
// signature: undefined vibrator_work_routine(void)
// callers: []
//------------------------------------------------------------

void vibrator_work_routine(long param_1)

{
  char cVar1;
  undefined *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  uint uVar5;
  long lVar6;
  
  lVar6 = param_1 + -0x4e0;
  mutex_lock(param_1 + -400);
  hrtimer_cancel(param_1 + -0x160);
  pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x40);
  if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1287ec);
    (*pcVar4)();
  }
  (*pcVar4)(lVar6);
  if (*(int *)(param_1 + -0x498) != 0) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x108);
    if (*(int *)(pcVar4 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128824);
      (*pcVar4)();
    }
    (*pcVar4)(lVar6,1);
    cVar1 = *(char *)(param_1 + -0x4d1);
    if (cVar1 == '\x04') {
      pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x50);
      if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12885c);
        (*pcVar4)();
      }
      (*pcVar4)(lVar6);
    }
    else {
      if (cVar1 != '\x05') {
        if (cVar1 == '\x01') {
          pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x80);
          if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12890c);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,*(undefined4 *)(param_1 + -0x4a4));
          _printk(&DAT_00137786,"haptic_hv",0x24a,"ram_vbat_comp");
          pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x88);
          if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128958);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,1);
          pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x58);
          if (*(int *)(pcVar4 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128984);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,1);
        }
        else {
          _printk(&DAT_001377b5,"haptic_hv",0x4a0,"vibrator_work_routine");
        }
        goto LAB_001288b4;
      }
      if (*(char *)(param_1 + -0x4d0) == '\x01') {
        pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x48);
        if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1289c0);
          (*pcVar4)();
        }
        (*pcVar4)(lVar6);
        uVar5 = 0;
        if (*(uint *)(param_1 + -0x470) != 0) {
          uVar5 = (uint)(*(int *)(param_1 + -0x4a4) * 0x1068) / *(uint *)(param_1 + -0x470);
        }
        if (0xb2 < (int)uVar5) {
          uVar5 = 0xb3;
        }
        pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x80);
        if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128a10);
          (*pcVar4)();
        }
        (*pcVar4)(lVar6,uVar5);
        puVar2 = &DAT_00133121;
        uVar3 = 0x243;
      }
      else {
        pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x80);
        if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128a80);
          (*pcVar4)();
        }
        (*pcVar4)(lVar6,*(undefined4 *)(param_1 + -0x4a4));
        puVar2 = &DAT_00137786;
        uVar3 = 0x246;
      }
      _printk(puVar2,"haptic_hv",uVar3,"ram_vbat_comp");
      pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x88);
      if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128acc);
        (*pcVar4)();
      }
      (*pcVar4)(lVar6,5);
      pcVar4 = *(code **)(*(long *)(param_1 + 0x1c8) + 0x58);
      if (*(int *)(pcVar4 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128af8);
        (*pcVar4)();
      }
      (*pcVar4)(lVar6,1);
    }
    hrtimer_start_range_ns
              (param_1 + -0x160,
               (long)((*(int *)(param_1 + -0x488) % 1000) * 1000000) +
               (long)(*(int *)(param_1 + -0x488) / 1000) * 1000000000,0,1);
  }
LAB_001288b4:
  mutex_unlock(param_1 + -400);
  return;
}



//------------------------------------------------------------
// rtp_work_routine @ 00128b04 size=1048
// signature: undefined rtp_work_routine(void)
// callers: []
//------------------------------------------------------------

void rtp_work_routine(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  uint *puVar8;
  ulong uVar9;
  size_t *local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60 = (size_t *)0x0;
  if (*(int *)(param_1 + 0x128) == 0) {
    _printk(&DAT_0013690c,"haptic_hv",0x602,"rtp_work_routine");
  }
  else {
    lVar7 = param_1 + -0xa8;
    lVar6 = param_1 + -0x3f8;
    mutex_lock(lVar7);
    hrtimer_cancel(param_1 + -0x78);
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x40);
    if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128b7c);
      (*pcVar4)();
    }
    (*pcVar4)(lVar6);
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x100);
    if (*(int *)(pcVar4 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128ba8);
      (*pcVar4)();
    }
    (*pcVar4)(lVar6,0);
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0xe0);
    if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128bd0);
      (*pcVar4)();
    }
    (*pcVar4)(lVar6);
    iVar2 = *(int *)(param_1 + -0x3b0);
    mutex_unlock(lVar7);
    if (iVar2 != 0) {
      lVar5 = param_1 + -0x30;
      mutex_lock(lVar5);
      puVar8 = (uint *)(param_1 + -0x364);
      if (0x3c < *puVar8) {
LAB_00128f10:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x128f14);
        (*pcVar4)();
      }
      iVar2 = request_firmware(&local_60,aw_rtp_name + (ulong)*puVar8 * 0x40,
                               *(undefined8 *)(param_1 + -0x138));
      if (iVar2 < 0) {
        if (0x3c < *puVar8) goto LAB_00128f10;
        _printk(&DAT_001321e5,"haptic_hv",0x613,"rtp_work_routine",
                aw_rtp_name + (ulong)*puVar8 * 0x40);
      }
      else {
        *(undefined1 *)(param_1 + -0x3f3) = 0;
        vfree(*(undefined8 *)(param_1 + 0x2f0));
        uVar9 = *local_60;
        puVar3 = (undefined4 *)vmalloc(uVar9 + 4);
        *(undefined4 **)(param_1 + 0x2f0) = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          release_firmware(local_60);
          _printk(&DAT_0013446e,"haptic_hv",0x638,"rtp_work_routine");
        }
        else {
          if (0xfffffffffffffffb < uVar9) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x128f1c);
            (*pcVar4)();
          }
          uVar1 = *puVar8;
          *puVar3 = (int)*local_60;
          if (0x3c < uVar1) goto LAB_00128f10;
          _printk(&DAT_00133b0d,"haptic_hv",0x63e,"rtp_work_routine",
                  aw_rtp_name + (ulong)uVar1 * 0x40);
          memcpy((void *)(*(long *)(param_1 + 0x2f0) + 4),(void *)local_60[1],*local_60);
          mutex_unlock(lVar5);
          release_firmware(local_60);
          mutex_lock(lVar7);
          *(undefined1 *)(param_1 + -0x3f3) = 1;
          pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x108);
          if (*(int *)(pcVar4 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x128db0);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,(ulong)*(byte *)(param_1 + -0x3f0) << 1);
          pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x80);
          if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128de0);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,*(undefined4 *)(param_1 + -0x3bc));
          _printk(&DAT_00137786,"haptic_hv",0x24a,"ram_vbat_comp");
          pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x88);
          if (*(int *)(pcVar4 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128e28);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,2);
          pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x58);
          if (*(int *)(pcVar4 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128e54);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6,1);
          usleep_range_state(2000,0x9c4,2);
          iVar2 = wait_enter_rtp_mode(lVar6);
          mutex_unlock(lVar7);
          if (iVar2 < 0) goto LAB_00128be8;
          mutex_lock(lVar5);
          lVar7 = param_1 + 0x2f8;
          uVar9 = cpu_latency_qos_request_active(lVar7);
          if ((uVar9 & 1) == 0) {
            cpu_latency_qos_add_request(lVar7,0);
          }
          *(undefined4 *)(param_1 + -0x380) = 0;
          rtp_play(lVar6);
          if (*(char *)(param_1 + -0x3ed) == '\x02') {
            pcVar4 = *(code **)(*(long *)(param_1 + 0x2b0) + 0x100);
            if (*(int *)(pcVar4 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x128eec);
              (*pcVar4)();
            }
            (*pcVar4)(lVar6,1);
          }
          uVar9 = cpu_latency_qos_request_active(lVar7);
          if ((uVar9 & 1) != 0) {
            cpu_latency_qos_remove_request(lVar7);
          }
        }
      }
      mutex_unlock(lVar5);
    }
  }
LAB_00128be8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// state_show @ 00128f20 size=60
// signature: undefined state_show(void)
// callers: []
//------------------------------------------------------------

long state_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"state = %d\n",*(int *)(*(long *)(param_1 + 0x98) + -0x60));
  return (long)iVar1;
}



//------------------------------------------------------------
// state_store @ 00128f60 size=8
// signature: undefined state_store(void)
// callers: []
//------------------------------------------------------------

undefined8 state_store(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



//------------------------------------------------------------
// duration_show @ 00128f6c size=128
// signature: undefined duration_show(void)
// callers: []
//------------------------------------------------------------

long duration_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98) + 0x2d8;
  uVar2 = hrtimer_active(lVar3);
  if ((uVar2 & 1) == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = __hrtimer_get_remaining(lVar3,0);
    lVar3 = lVar3 / 1000000;
  }
  iVar1 = snprintf(param_3,0x1000,"duration = %lldms\n",lVar3);
  return (long)iVar1;
}



//------------------------------------------------------------
// duration_store @ 00128ff0 size=580
// signature: undefined duration_store(void)
// callers: []
//------------------------------------------------------------

long duration_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  iVar1 = kstrtouint(param_3,0,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else if (local_4c != 0) {
    _printk(&DAT_0013555b,"haptic_hv",0x839,"duration_store");
    mutex_lock(lVar6 + 0x2a8);
    *(uint *)(lVar6 + -0x50) = local_4c;
    if ((int)local_4c < 1) {
      _printk(&DAT_00133486,"haptic_hv",0x46c,"ram_select_waveform");
    }
    else {
      lVar3 = lVar6 + -0xa8;
      *(undefined1 *)(lVar6 + -0x99) = 1;
      if (local_4c < *(byte *)(lVar6 + 0x482)) {
        uVar4 = 0;
        uVar5 = 3;
      }
      else if (local_4c < *(byte *)(lVar6 + 0x483)) {
        uVar4 = 0;
        uVar5 = 2;
      }
      else if (local_4c < *(byte *)(lVar6 + 0x484)) {
        uVar4 = 0;
        uVar5 = 1;
      }
      else {
        uVar5 = 4;
        uVar4 = 0xf;
        *(undefined1 *)(lVar6 + -0x99) = 5;
      }
      _printk(&DAT_00136ced,"haptic_hv",0x47d,"ram_select_waveform",local_4c,uVar5);
      pcVar2 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb0);
      if (*(int *)(pcVar2 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129190);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3,0,uVar5);
      pcVar2 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb8);
      if (*(int *)(pcVar2 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1291c0);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3,0,uVar4);
      pcVar2 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb0);
      if (*(int *)(pcVar2 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1291f0);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3,1,0);
      pcVar2 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb8);
      if (*(int *)(pcVar2 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129220);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3,1,0);
    }
    mutex_unlock(lVar6 + 0x2a8);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// activate_show @ 00129238 size=60
// signature: undefined activate_show(void)
// callers: []
//------------------------------------------------------------

long activate_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"activate = %d\n",*(int *)(*(long *)(param_1 + 0x98) + -0x60));
  return (long)iVar1;
}



//------------------------------------------------------------
// activate_store @ 00129278 size=272
// signature: undefined activate_store(void)
// callers: []
//------------------------------------------------------------

long activate_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    _printk(&DAT_00135faf,"haptic_hv",0x855,"activate_store",local_3c);
    if (*(char *)(lVar2 + -0xa2) == '\0') {
      _printk(&DAT_001325b9,"haptic_hv",0x857,"activate_store");
    }
    else {
      mutex_lock(lVar2 + 0x2a8);
      *(int *)(lVar2 + -0x60) = local_3c;
      if (local_3c == 0) {
        *(undefined4 *)(lVar2 + -0x6c) = 0x80;
      }
      mutex_unlock(lVar2 + 0x2a8);
      queue_work_on(0x20,*(undefined8 *)(lVar2 + 0x468),lVar2 + 0x438);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// activate_mode_show @ 0012938c size=60
// signature: undefined activate_mode_show(void)
// callers: []
//------------------------------------------------------------

long activate_mode_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"activate_mode = %d\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + -0x99));
  return (long)iVar1;
}



//------------------------------------------------------------
// activate_mode_store @ 001293cc size=160
// signature: undefined activate_mode_store(void)
// callers: []
//------------------------------------------------------------

long activate_mode_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtouint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    lVar1 = lVar3 + 0x2a8;
    mutex_lock(lVar1);
    *(char *)(lVar3 + -0x99) = (char)local_3c;
    mutex_unlock(lVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// index_show @ 00129470 size=152
// signature: undefined index_show(void)
// callers: []
//------------------------------------------------------------

long index_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x110);
  if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1294c4);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8,1);
  *(uint *)(lVar3 + -0x5c) = (uint)*(byte *)(lVar3 + -0x97);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"index = %d\n",*(int *)(lVar3 + -0x5c));
  return (long)iVar1;
}



//------------------------------------------------------------
// index_store @ 0012950c size=288
// signature: undefined index_store(void)
// callers: []
//------------------------------------------------------------

long index_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else if (*(byte *)(lVar3 + 0x47c) < local_3c) {
    _printk(&DAT_00133731,"haptic_hv",0x897,"index_store");
  }
  else {
    _printk(&DAT_00135faf,"haptic_hv",0x89a,"index_store");
    mutex_lock(lVar3 + 0x2a8);
    *(uint *)(lVar3 + -0x5c) = local_3c;
    pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x98);
    if (*(int *)(pcVar2 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129618);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3 + -0xa8);
    mutex_unlock(lVar3 + 0x2a8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// vmax_show @ 00129630 size=60
// signature: undefined vmax_show(void)
// callers: []
//------------------------------------------------------------

long vmax_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"vmax = %dmV\n",*(int *)(*(long *)(param_1 + 0x98) + -0x70));
  return (long)iVar1;
}



//------------------------------------------------------------
// vmax_store @ 00129670 size=240
// signature: undefined vmax_store(void)
// callers: []
//------------------------------------------------------------

long vmax_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    _printk(&DAT_00135faf,"haptic_hv",0x8b6,"vmax_store",local_3c);
    mutex_lock(lVar3 + 0x2a8);
    *(undefined4 *)(lVar3 + -0x70) = local_3c;
    pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x90);
    if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12974c);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3 + -0xa8);
    mutex_unlock(lVar3 + 0x2a8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// gain_show @ 00129764 size=60
// signature: undefined gain_show(void)
// callers: []
//------------------------------------------------------------

long gain_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"gain = 0x%02X\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x6c));
  return (long)iVar1;
}



//------------------------------------------------------------
// gain_store @ 001297a4 size=240
// signature: undefined gain_store(void)
// callers: []
//------------------------------------------------------------

long gain_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    _printk(&DAT_00135fd6,"haptic_hv",0x8d2,"gain_store",local_3c);
    mutex_lock(lVar3 + 0x2a8);
    *(undefined4 *)(lVar3 + -0x6c) = local_3c;
    pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x80);
    if (*(int *)(pcVar2 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129880);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3 + -0xa8);
    mutex_unlock(lVar3 + 0x2a8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// strength_show @ 00129898 size=60
// signature: undefined strength_show(void)
// callers: []
//------------------------------------------------------------

long strength_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"gain = 0x%02X\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + -0x6c));
  return (long)iVar1;
}



//------------------------------------------------------------
// strength_store @ 001298d8 size=320
// signature: undefined strength_store(void)
// callers: []
//------------------------------------------------------------

long strength_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
    goto LAB_00129924;
  }
  _printk(&DAT_00132dc9,"haptic_hv",0xd00,"strength_store",local_3c);
  mutex_lock(lVar4 + 0x2a8);
  if (local_3c == 2) {
    uVar2 = 0x80;
LAB_001299b4:
    *(undefined4 *)(lVar4 + -0x6c) = uVar2;
  }
  else {
    if (local_3c == 1) {
      uVar2 = 0x60;
      goto LAB_001299b4;
    }
    if (local_3c == 0) {
      uVar2 = 0x40;
      goto LAB_001299b4;
    }
    _printk(&DAT_0013772c,"haptic_hv",0xd0f,"strength_store");
    uVar2 = *(undefined4 *)(lVar4 + -0x6c);
  }
  pcVar3 = *(code **)(*(long *)(lVar4 + 0x600) + 0x80);
  if (*(int *)(pcVar3 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1299dc);
    (*pcVar3)();
  }
  (*pcVar3)(lVar4 + -0xa8,uVar2);
  mutex_unlock(lVar4 + 0x2a8);
LAB_00129924:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// seq_show @ 00129a1c size=360
// signature: undefined seq_show(void)
// callers: []
//------------------------------------------------------------

long seq_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x110);
  if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129a74);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8,8);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"seq%d = %d\n",1,(uint)*(byte *)(lVar3 + -0x97));
  lVar4 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",2,(uint)*(byte *)(lVar3 + -0x96));
  lVar4 = lVar4 + iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",3,(uint)*(byte *)(lVar3 + -0x95));
  lVar4 = lVar4 + iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",4,(uint)*(byte *)(lVar3 + -0x94));
  lVar4 = lVar4 + iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",5,(uint)*(byte *)(lVar3 + -0x93));
  lVar4 = lVar4 + iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",6,(uint)*(byte *)(lVar3 + -0x92));
  lVar4 = lVar4 + iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",7,(uint)*(byte *)(lVar3 + -0x91));
  lVar4 = lVar4 + iVar1;
  iVar1 = snprintf(param_3 + lVar4,0x1000 - lVar4,"seq%d = %d\n",8,(uint)*(byte *)(lVar3 + -0x90));
  return lVar4 + iVar1;
}



//------------------------------------------------------------
// seq_store @ 00129b88 size=444
// signature: undefined seq_store(void)
// callers: []
//------------------------------------------------------------

long seq_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined1 uVar1;
  int iVar2;
  code *pcVar3;
  undefined1 uVar4;
  long lVar5;
  long lVar6;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  iVar2 = kstrtouint(param_3,0,&local_4c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    local_4c = local_4c >> 0x18;
    lVar5 = lVar6 + -0xa8;
    _printk(&DAT_0013801a,"haptic_hv",0x908,"seq_store","seq_store");
    mutex_lock(lVar6 + 0x2a8);
    *(undefined4 *)(lVar6 + -0x50) = 0;
    uVar4 = 3;
    if (local_4c != 4) {
      uVar4 = 1;
    }
    uVar1 = 2;
    if (local_4c != 6) {
      uVar1 = uVar4;
    }
    *(undefined1 *)(lVar6 + -0x97) = uVar1;
    pcVar3 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb0);
    if (*(int *)(pcVar3 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x129c98);
      (*pcVar3)();
    }
    (*pcVar3)(lVar5,0);
    pcVar3 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb8);
    if (*(int *)(pcVar3 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x129cc8);
      (*pcVar3)();
    }
    (*pcVar3)(lVar5,0,0);
    pcVar3 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb0);
    if (*(int *)(pcVar3 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x129cfc);
      (*pcVar3)();
    }
    (*pcVar3)(lVar5,1,0);
    pcVar3 = *(code **)(*(long *)(lVar6 + 0x600) + 0xb8);
    if (*(int *)(pcVar3 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x129d2c);
      (*pcVar3)();
    }
    (*pcVar3)(lVar5,1,0);
    *(undefined1 *)(lVar6 + -0x99) = 1;
    mutex_unlock(lVar6 + 0x2a8);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// rtp_interface_show @ 00129d48 size=8
// signature: undefined rtp_interface_show(void)
// callers: []
//------------------------------------------------------------

undefined8 rtp_interface_show(void)

{
  return 0;
}



//------------------------------------------------------------
// rtp_interface_store @ 00129d54 size=8
// signature: undefined rtp_interface_store(void)
// callers: []
//------------------------------------------------------------

undefined8 rtp_interface_store(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



//------------------------------------------------------------
// loop_show @ 00129d60 size=124
// signature: undefined loop_show(void)
// callers: []
//------------------------------------------------------------

undefined8 loop_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x130);
  if (*(int *)(pcVar2 + -4) != 0x6218b549) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129db4);
    (*pcVar2)();
  }
  uVar1 = (*pcVar2)(lVar3 + -0xa8,param_3);
  mutex_unlock(lVar3 + 0x2a8);
  return uVar1;
}



//------------------------------------------------------------
// loop_store @ 00129de0 size=284
// signature: undefined loop_store(void)
// callers: []
//------------------------------------------------------------

undefined8 loop_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_40,(uint *)((ulong)&local_40 | 4));
  if (iVar1 != 2) {
LAB_00129e38:
    lVar3 = sp_el0;
    if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return param_4;
  }
  _printk(&DAT_001321c2,"haptic_hv",0x943,"loop_store",local_40 & 0xffffffff,local_40._4_4_);
  mutex_lock(lVar3 + 0x2a8);
  if ((uint)local_40 < 8) {
    *(char *)(lVar3 + -0x8f + (local_40 & 0xffffffff)) = (char)(local_40 >> 0x20);
    if ((uint)local_40 < 8) {
      pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0xb8);
      if (*(int *)(pcVar2 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129ee4);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3 + -0xa8,local_40 & 0xffffffff,
                *(undefined1 *)(lVar3 + -0x8f + (local_40 & 0xffffffff)));
      mutex_unlock(lVar3 + 0x2a8);
      goto LAB_00129e38;
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x129efc);
  (*pcVar2)();
}



//------------------------------------------------------------
// reg_show @ 00129f00 size=128
// signature: undefined reg_show(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x138);
  if (*(int *)(pcVar2 + -4) != -0x64e39800) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x129f58);
    (*pcVar2)();
  }
  uVar1 = (*pcVar2)(lVar3 + -0xa8,0,param_3);
  mutex_unlock(lVar3 + 0x2a8);
  return uVar1;
}



//------------------------------------------------------------
// reg_store @ 00129f84 size=280
// signature: undefined reg_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 reg_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  uint auVar3 [2];
  uint auVar4 [2];
  int iVar5;
  undefined1 *puVar6;
  undefined8 uVar7;
  long lVar8;
  uint local_50 [2];
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x98);
  local_50[0] = 0;
  local_50[1] = 0;
  iVar5 = sscanf(param_3,"%x %x",local_50,(uint *)((ulong)local_50 | 4));
  auVar3 = local_50;
  if (iVar5 == 2) {
    lVar1 = lVar8 + 0x2a8;
    mutex_lock(lVar1);
    auVar4 = local_50;
    uVar2 = local_50[0];
    puVar6 = (undefined1 *)kmalloc_trace(_gpiod_set_raw_value_cansleep,0xcc0,2);
    uVar7 = *(undefined8 *)(lVar8 + 0x220);
    *puVar6 = (char)auVar4[0];
    puVar6[1] = (char)auVar3[1];
    iVar5 = i2c_transfer_buffer_flags(uVar7,puVar6,2,0);
    if (iVar5 < 0) {
      _printk(&DAT_00137c1e,"haptic_hv",0x8a,"haptic_hv_i2c_writes",uVar2 & 0xff);
    }
    kfree(puVar6);
    mutex_unlock(lVar1);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// rtp_show @ 0012a0a0 size=60
// signature: undefined rtp_show(void)
// callers: []
//------------------------------------------------------------

long rtp_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"rtp_cnt = %u\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// rtp_store @ 0012a0e0 size=352
// signature: undefined rtp_store(void)
// callers: []
//------------------------------------------------------------

long rtp_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtouint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    _printk(&DAT_00132666,"haptic_hv",0x982,"rtp_store");
    param_4 = (long)iVar2;
  }
  else {
    mutex_lock(lVar3 + 0x2a8);
    if (local_3c == 0) {
      *(undefined4 *)(lVar3 + -0x60) = 0;
    }
    else if (local_3c < *(uint *)(lVar3 + -0x28)) {
      *(undefined4 *)(lVar3 + -0x60) = 1;
      *(uint *)(lVar3 + -0x14) = local_3c;
      if (0x3c < local_3c) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x12a240);
        (*pcVar1)();
      }
      _printk(&DAT_00131ead,"haptic_hv",0x989,"rtp_store",(ulong)local_3c,
              aw_rtp_name + (ulong)local_3c * 0x40);
    }
    else {
      *(undefined4 *)(lVar3 + -0x60) = 0;
      _printk(&DAT_0013408e,"haptic_hv",0x98e,"rtp_store",local_3c);
    }
    mutex_unlock(lVar3 + 0x2a8);
    queue_work_on(0x20,*(undefined8 *)(lVar3 + 0x468),lVar3 + 0x350);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ram_update_show @ 0012a244 size=580
// signature: undefined ram_update_show(void)
// callers: []
//------------------------------------------------------------

undefined8 ram_update_show(long param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  code *pcVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  
  lVar10 = *(long *)(param_1 + 0x98);
  _printk(&DAT_00134422,"haptic_hv",0x99e,"ram_update_show",*(undefined4 *)(lVar10 + 0x470));
  lVar4 = __kmalloc(*(undefined4 *)(lVar10 + 0x470),0xdc0);
  if (lVar4 == 0) {
    _printk(&DAT_001364e6,"haptic_hv",0x9a1,"ram_update_show");
    uVar5 = 0;
  }
  else {
    lVar7 = lVar10 + -0xa8;
    mutex_lock(lVar10 + 0x2a8);
    pcVar6 = *(code **)(*(long *)(lVar10 + 0x600) + 0x40);
    if (*(int *)(pcVar6 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12a2d8);
      (*pcVar6)();
    }
    (*pcVar6)(lVar7);
    pcVar6 = *(code **)(*(long *)(lVar10 + 0x600) + 0x60);
    if (*(int *)(pcVar6 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12a304);
      (*pcVar6)();
    }
    (*pcVar6)(lVar7,1);
    pcVar6 = *(code **)(*(long *)(lVar10 + 0x600) + 0xe8);
    if (*(int *)(pcVar6 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12a32c);
      (*pcVar6)();
    }
    (*pcVar6)(lVar7);
    pcVar6 = *(code **)(*(long *)(lVar10 + 0x600) + 0x118);
    if (*(int *)(pcVar6 + -4) != 0x31aed82f) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12a358);
      (*pcVar6)();
    }
    (*pcVar6)(lVar7,lVar4);
    if (*(int *)(lVar10 + 0x470) != 0) {
      lVar9 = 0;
      uVar8 = 1;
      do {
        iVar3 = snprintf(param_3 + lVar9,0x1000,"0x%02x,",
                         (uint)*(byte *)(lVar4 + -1 + (long)(int)uVar8));
        if (((uVar8 & 0xf) == 0) || (uVar1 = *(uint *)(lVar10 + 0x470), uVar8 == uVar1)) {
          _printk(&DAT_00136d20,"haptic_hv",0x9ae,"ram_update_show",param_3);
          lVar9 = 0;
          uVar1 = *(uint *)(lVar10 + 0x470);
        }
        else {
          lVar9 = lVar9 + iVar3;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 <= uVar1);
    }
    kfree(lVar4);
    pcVar6 = *(code **)(*(long *)(lVar10 + 0x600) + 0x60);
    if (*(int *)(pcVar6 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12a418);
      (*pcVar6)();
    }
    (*pcVar6)(lVar7,0);
    uVar2 = s_Please_check_log_00136d34._8_8_;
    uVar5 = s_Please_check_log_00136d34._0_8_;
    param_3[0x10] = '\n';
    param_3[0x11] = '\0';
    *(undefined8 *)param_3 = uVar5;
    *(undefined8 *)(param_3 + 8) = uVar2;
    mutex_unlock(lVar10 + 0x2a8);
    uVar5 = 0x11;
  }
  return uVar5;
}



//------------------------------------------------------------
// ram_update_store @ 0012a48c size=180
// signature: undefined ram_update_store(void)
// callers: []
//------------------------------------------------------------

long ram_update_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else if (local_2c != 0) {
    *(undefined2 *)(lVar2 + -0xa3) = 0;
    request_firmware_nowait
              (&__this_module,1,aw_ram_name,*(undefined8 *)(lVar2 + 0x218),0xcc0,lVar2 + -0xa8,
               ram_load);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ram_load @ 0012a544 size=828
// signature: undefined ram_load(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_load(ulong *param_1,long param_2)

{
  ulong uVar1;
  size_t __n;
  ushort *puVar2;
  void *__src;
  int *piVar3;
  code *pcVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  int iVar12;
  byte *pbVar13;
  ulong uVar14;
  
  ram_load_load_cont = ram_load_load_cont + 1;
  if (param_1 == (ulong *)0x0) {
    _printk(&DAT_001321e5,"haptic_hv",0x6a2,"ram_load",aw_ram_name);
    release_firmware(0);
    if (ram_load_load_cont < 0x15) {
      queue_delayed_work_on(0x20,_system_wq,param_2 + 0x458,0xfa);
      _printk(&DAT_00138037,"haptic_hv",0x6a8,"ram_load",ram_load_load_cont);
      return;
    }
    return;
  }
  _printk(&DAT_00135586,"haptic_hv",0x6ad,"ram_load",aw_ram_name,*param_1);
  uVar1 = *param_1;
  puVar2 = (ushort *)param_1[1];
  if (uVar1 < 3) {
    uVar7 = 0;
    goto LAB_0012a6d4;
  }
  uVar9 = uVar1 - 2;
  if (uVar9 < 2) {
    uVar7 = 0;
    uVar5 = 2;
    iVar8 = 2;
LAB_0012a6b8:
    do {
      iVar8 = iVar8 + 1;
      pbVar13 = (byte *)((long)puVar2 + uVar5);
      uVar5 = (ulong)iVar8;
      uVar7 = uVar7 + *pbVar13;
    } while (uVar5 < uVar1);
  }
  else {
    uVar7 = 0;
    uVar5 = 2;
    iVar8 = 2;
    uVar10 = (uint)(uVar1 - 3);
    if (((0x7ffffffd < uVar10) || (0x7ffffffc < uVar10)) || (uVar1 - 3 >> 0x20 != 0))
    goto LAB_0012a6b8;
    uVar11 = uVar9 & 0xfffffffffffffffe;
    iVar6 = 0;
    iVar12 = 0;
    uVar5 = uVar11 + 2;
    iVar8 = (int)uVar11 + 2;
    pbVar13 = (byte *)((long)puVar2 + 3);
    uVar14 = uVar11;
    do {
      uVar14 = uVar14 - 2;
      iVar6 = iVar6 + (uint)pbVar13[-1];
      iVar12 = iVar12 + (uint)*pbVar13;
      pbVar13 = pbVar13 + 2;
    } while (uVar14 != 0);
    uVar7 = iVar12 + iVar6;
    if (uVar9 != uVar11) goto LAB_0012a6b8;
  }
  uVar7 = uVar7 & 0xffff;
LAB_0012a6d4:
  if (uVar7 == ((uint)(*puVar2 >> 8) | (*puVar2 & 0xff00ff) << 8)) {
    _printk(&DAT_001355ad,"haptic_hv",0x6b6,"ram_load",uVar7);
    *(uint *)(param_2 + 0x51c) = uVar7;
    piVar3 = (int *)__kmalloc(*param_1 + 4,0xdc0);
    if (piVar3 == (int *)0x0) {
      release_firmware(param_1);
      _printk(&DAT_001364e6,"haptic_hv",0x6bd,"ram_load");
    }
    else {
      __n = *param_1;
      __src = (void *)param_1[1];
      *piVar3 = (int)__n;
      memcpy(piVar3 + 1,__src,__n);
      release_firmware(param_1);
      pcVar4 = *(code **)(*(long *)(param_2 + 0x6a8) + 0x38);
      if (*(int *)(pcVar4 + -4) != -0x44c8dc66) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12a7bc);
        (*pcVar4)();
      }
      iVar8 = (*pcVar4)(param_2,piVar3);
      if (iVar8 == 0) {
        iVar8 = *piVar3;
        *(undefined1 *)(param_2 + 6) = 1;
        *(uint *)(param_2 + 0x518) = iVar8 - (uint)*(byte *)(param_2 + 0x526);
        mutex_lock(param_2 + 0x350);
        pcVar4 = *(code **)(*(long *)(param_2 + 0x6a8) + 0xd8);
        if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12a80c);
          (*pcVar4)();
        }
        (*pcVar4)(param_2);
        mutex_unlock(param_2 + 0x350);
        _printk(&DAT_001355d6,"haptic_hv",0x6cc,"ram_load");
        get_ram_num(param_2);
      }
      else {
        _printk(&DAT_00132a75,"haptic_hv",0x6c5,"ram_load");
      }
      kfree(piVar3);
    }
  }
  else {
    _printk(&DAT_00133778,"haptic_hv",0x6b2,"ram_load",uVar7);
    release_firmware(param_1);
  }
  return;
}



//------------------------------------------------------------
// get_ram_num @ 0012a880 size=464
// signature: undefined get_ram_num(void)
// callers: [ram_load, ram_num_show]
//------------------------------------------------------------

void get_ram_num(long param_1)

{
  long lVar1;
  code *pcVar2;
  ushort local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  if (*(char *)(param_1 + 6) == '\0') {
    _printk(&DAT_00132208,"haptic_hv",0x222,"get_ram_num");
  }
  else {
    mutex_lock(param_1 + 0x350);
    pcVar2 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x40);
    if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12a908);
      (*pcVar2)();
    }
    (*pcVar2)(param_1);
    pcVar2 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x60);
    if (*(int *)(pcVar2 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12a934);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,1);
    pcVar2 = *(code **)(*(long *)(param_1 + 0x6a8) + 0xe8);
    if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12a95c);
      (*pcVar2)();
    }
    (*pcVar2)(param_1);
    pcVar2 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x128);
    if (*(int *)(pcVar2 + -4) != -0x294007f0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12a988);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,local_3c);
    *(char *)(param_1 + 0x524) =
         (char)(((uint)(local_3c[0] >> 8) | (local_3c[0] & 0xff00ff) << 8) +
                ~*(uint *)(param_1 + 0x520) >> 2);
    _printk(&DAT_001362cc,"haptic_hv",0x22d,"get_ram_num");
    _printk(&DAT_001334bd,"haptic_hv",0x22e,"get_ram_num",*(undefined1 *)(param_1 + 0x524));
    pcVar2 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x60);
    if (*(int *)(pcVar2 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12aa14);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,0);
    mutex_unlock(param_1 + 0x350);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ram_num_show @ 0012aa54 size=76
// signature: undefined ram_num_show(void)
// callers: []
//------------------------------------------------------------

long ram_num_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  get_ram_num(lVar2 + -0xa8);
  iVar1 = snprintf(param_3,0x1000,"ram_num = %d\n",(uint)*(byte *)(lVar2 + 0x47c));
  return (long)iVar1;
}



//------------------------------------------------------------
// f0_show @ 0012aaa4 size=184
// signature: undefined f0_show(void)
// callers: []
//------------------------------------------------------------

long f0_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x108);
  if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12aaf8);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8,0);
  if (*(int *)((code *)**(undefined8 **)(lVar3 + 0x600) + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12ab20);
    (*pcVar2)();
  }
  (*(code *)**(undefined8 **)(lVar3 + 0x600))(lVar3 + -0xa8);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"f0 = %u\n",*(uint *)(lVar3 + -0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// ram_f0_show @ 0012ab60 size=184
// signature: undefined ram_f0_show(void)
// callers: []
//------------------------------------------------------------

long ram_f0_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x108);
  if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12abb4);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8,0);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 8);
  if (*(int *)(pcVar2 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12abdc);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"f0 = %u\n",*(uint *)(lVar3 + -0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// f0_save_show @ 0012ac1c size=60
// signature: undefined f0_save_show(void)
// callers: []
//------------------------------------------------------------

long f0_save_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"f0_cali_data = 0x%02X\n",
                   *(uint *)(*(long *)(param_1 + 0x98) + -0x18));
  return (long)iVar1;
}



//------------------------------------------------------------
// f0_save_store @ 0012ac5c size=132
// signature: undefined f0_save_store(void)
// callers: []
//------------------------------------------------------------

long f0_save_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    *(undefined4 *)(lVar2 + -0x18) = local_2c;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cali_show @ 0012ace4 size=184
// signature: undefined cali_show(void)
// callers: []
//------------------------------------------------------------

long cali_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x108);
  if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12ad38);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8,1);
  if (*(int *)((code *)**(undefined8 **)(lVar3 + 0x600) + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12ad60);
    (*pcVar2)();
  }
  (*(code *)**(undefined8 **)(lVar3 + 0x600))(lVar3 + -0xa8);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"f0 = %u\n",*(uint *)(lVar3 + -0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// cali_store @ 0012ada0 size=172
// signature: undefined cali_store(void)
// callers: []
//------------------------------------------------------------

long cali_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtouint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else if (local_3c != 0) {
    lVar1 = lVar3 + 0x2a8;
    mutex_lock(lVar1);
    f0_cali(lVar3 + -0xa8);
    mutex_unlock(lVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// f0_cali @ 0012ae4c size=444
// signature: undefined f0_cali(void)
// callers: [haptic_init, cali_store]
//------------------------------------------------------------

void f0_cali(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x108);
  if (*(int *)(pcVar4 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12ae88);
    (*pcVar4)();
  }
  (*pcVar4)(param_1,0);
  if (*(int *)((code *)**(undefined8 **)(param_1 + 0x6a8) + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12aeb0);
    (*pcVar4)();
  }
  iVar3 = (*(code *)**(undefined8 **)(param_1 + 0x6a8))(param_1);
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 0x530);
    uVar1 = (100 - (uint)*(byte *)(param_1 + 0x529)) * iVar3;
    uVar2 = (*(byte *)(param_1 + 0x529) + 100) * iVar3;
    _printk(&DAT_001330d7,"haptic_hv",0x278,"judge_cali_range",iVar3,(ulong)uVar1 / 100,
            (ulong)uVar2 / 100,*(undefined4 *)(param_1 + 100));
    if (*(uint *)(param_1 + 100) < uVar1 / 100) {
      _printk(&DAT_0013735f,"haptic_hv",0x27b,"judge_cali_range");
      return;
    }
    if (uVar2 / 100 < *(uint *)(param_1 + 100)) {
      _printk(&DAT_00132aa2,"haptic_hv",0x289,"judge_cali_range");
      return;
    }
    calculate_cali_data(param_1);
    pcVar4 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x108);
    if (*(int *)(pcVar4 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12af5c);
      (*pcVar4)();
    }
    (*pcVar4)(param_1,1);
  }
  else {
    _printk(&DAT_00137756,"haptic_hv",0x29f,"f0_cali");
  }
  pcVar4 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x40);
  if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12afa8);
    (*pcVar4)();
  }
  (*pcVar4)(param_1);
  return;
}



//------------------------------------------------------------
// calculate_cali_data @ 0012b008 size=336
// signature: undefined calculate_cali_data(void)
// callers: [f0_cali, ram_cali_store]
//------------------------------------------------------------

void calculate_cali_data(long param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x50) == 0x9381 || *(int *)(param_1 + 0x50) == 0x9371) {
    iVar4 = *(int *)(param_1 + 100) * 0x16;
    iVar5 = (*(int *)(param_1 + 100) * -10000 +
            (*(int *)(param_1 + 0x34) * 0x16 + 10000) * *(int *)(param_1 + 0x530)) * 10;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x530) * 0x18;
    iVar5 = (*(int *)(param_1 + 100) - *(int *)(param_1 + 0x530)) * 100000;
  }
  uVar2 = 0;
  if (iVar4 != 0) {
    uVar2 = iVar5 / iVar4;
  }
  _printk(&DAT_00136d54,"haptic_hv",0x25a,"calculate_cali_data",uVar2);
  if ((int)uVar2 < 0) {
    uVar2 = -uVar2;
    bVar1 = *(byte *)(param_1 + 0x30);
    uVar3 = -(uVar2 / 10);
    if (4 < uVar2 % 10) {
      uVar3 = ~(uVar2 / 10);
    }
    iVar5 = bVar1 + uVar3;
  }
  else {
    bVar1 = *(byte *)(param_1 + 0x30);
    iVar5 = uVar2 / 10 + (uint)bVar1;
    if (4 < uVar2 % 10) {
      iVar5 = iVar5 + 1;
    }
  }
  uVar3 = (uint)bVar1;
  uVar2 = -uVar3;
  if (iVar5 < (int)uVar3) {
    uVar2 = uVar3;
  }
  *(uint *)(param_1 + 0x90) = uVar2 + iVar5 & 0xff;
  _printk(&DAT_00134447,"haptic_hv",0x26c,"calculate_cali_data");
  return;
}



//------------------------------------------------------------
// ram_cali_show @ 0012b15c size=184
// signature: undefined ram_cali_show(void)
// callers: []
//------------------------------------------------------------

long ram_cali_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x108);
  if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b1b0);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8,1);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 8);
  if (*(int *)(pcVar2 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b1d8);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"f0 = %u\n",*(uint *)(lVar3 + -0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// ram_cali_store @ 0012b218 size=576
// signature: undefined ram_cali_store(void)
// callers: []
//------------------------------------------------------------

long ram_cali_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  int local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  iVar3 = kstrtouint(param_3,0,&local_4c);
  if (iVar3 < 0) {
    param_4 = (long)iVar3;
    goto LAB_0012b384;
  }
  if (local_4c == 0) goto LAB_0012b384;
  lVar5 = lVar6 + -0xa8;
  mutex_lock(lVar6 + 0x2a8);
  pcVar4 = *(code **)(*(long *)(lVar6 + 0x600) + 0x108);
  if (*(int *)(pcVar4 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12b2a4);
    (*pcVar4)();
  }
  (*pcVar4)(lVar5,0);
  pcVar4 = *(code **)(*(long *)(lVar6 + 0x600) + 8);
  if (*(int *)(pcVar4 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12b2cc);
    (*pcVar4)();
  }
  iVar3 = (*pcVar4)(lVar5);
  if (iVar3 == 0) {
    iVar3 = *(int *)(lVar6 + 0x488);
    uVar1 = (100 - (uint)*(byte *)(lVar6 + 0x481)) * iVar3;
    uVar2 = (*(byte *)(lVar6 + 0x481) + 100) * iVar3;
    _printk(&DAT_001330d7,"haptic_hv",0x278,"judge_cali_range",iVar3,(ulong)uVar1 / 100,
            (ulong)uVar2 / 100,*(undefined4 *)(lVar6 + -0x44));
    if (*(uint *)(lVar6 + -0x44) < uVar1 / 100) {
      _printk(&DAT_0013735f,"haptic_hv",0x27b,"judge_cali_range");
    }
    else {
      if (*(uint *)(lVar6 + -0x44) <= uVar2 / 100) {
        calculate_cali_data(lVar5);
        pcVar4 = *(code **)(*(long *)(lVar6 + 0x600) + 0x108);
        if (*(int *)(pcVar4 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12b378);
          (*pcVar4)();
        }
        (*pcVar4)(lVar5,1);
        goto LAB_0012b3d8;
      }
      _printk(&DAT_00132aa2,"haptic_hv",0x289,"judge_cali_range");
    }
  }
  else {
    _printk(&DAT_00137756,"haptic_hv",0x2b3,"ram_f0_cali");
LAB_0012b3d8:
    pcVar4 = *(code **)(*(long *)(lVar6 + 0x600) + 0x40);
    if (*(int *)(pcVar4 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12b3fc);
      (*pcVar4)();
    }
    (*pcVar4)(lVar5);
  }
  mutex_unlock(lVar6 + 0x2a8);
LAB_0012b384:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cont_store @ 0012b45c size=288
// signature: undefined cont_store(void)
// callers: []
//------------------------------------------------------------

long cont_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    lVar3 = lVar4 + -0xa8;
    mutex_lock(lVar4 + 0x2a8);
    pcVar2 = *(code **)(*(long *)(lVar4 + 0x600) + 0x40);
    if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b4d8);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3);
    if (local_3c != 0) {
      pcVar2 = *(code **)(*(long *)(lVar4 + 0x600) + 0x108);
      if (*(int *)(pcVar2 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b50c);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3,1);
      pcVar2 = *(code **)(*(long *)(lVar4 + 0x600) + 0x50);
      if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b534);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3);
    }
    mutex_unlock(lVar4 + 0x2a8);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// vbat_monitor_show @ 0012b580 size=144
// signature: undefined vbat_monitor_show(void)
// callers: []
//------------------------------------------------------------

long vbat_monitor_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x48);
  if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b5d0);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8);
  iVar1 = snprintf(param_3,0x1000,"vbat_monitor = %u\n",*(uint *)(lVar3 + -0x38));
  mutex_unlock(lVar3 + 0x2a8);
  return (long)iVar1;
}



//------------------------------------------------------------
// lra_resistance_show @ 0012b614 size=140
// signature: undefined lra_resistance_show(void)
// callers: []
//------------------------------------------------------------

long lra_resistance_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 0x2a8);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x70);
  if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b664);
    (*pcVar2)();
  }
  (*pcVar2)(lVar3 + -0xa8);
  mutex_unlock(lVar3 + 0x2a8);
  iVar1 = snprintf(param_3,0x1000,"lra_resistance = %u\n",*(uint *)(lVar3 + -0x3c));
  return (long)iVar1;
}



//------------------------------------------------------------
// auto_boost_show @ 0012b6a4 size=60
// signature: undefined auto_boost_show(void)
// callers: []
//------------------------------------------------------------

long auto_boost_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"auto_boost = %d\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + -0x9c));
  return (long)iVar1;
}



//------------------------------------------------------------
// auto_boost_store @ 0012b6e4 size=240
// signature: undefined auto_boost_store(void)
// callers: []
//------------------------------------------------------------

long auto_boost_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    mutex_lock(lVar3 + 0x2a8);
    pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0x40);
    if (*(int *)(pcVar2 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b760);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3 + -0xa8);
    pcVar2 = *(code **)(*(long *)(lVar3 + 0x600) + 0xa0);
    if (*(int *)(pcVar2 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x12b78c);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3 + -0xa8,local_3c);
    mutex_unlock(lVar3 + 0x2a8);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// prct_mode_show @ 0012b7d8 size=144
// signature: undefined prct_mode_show(void)
// callers: []
//------------------------------------------------------------

long prct_mode_show(long param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar4 + 0x2a8);
  pcVar3 = *(code **)(*(long *)(lVar4 + 0x600) + 0x140);
  if (*(int *)(pcVar3 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x12b828);
    (*pcVar3)();
  }
  uVar1 = (*pcVar3)(lVar4 + -0xa8);
  mutex_unlock(lVar4 + 0x2a8);
  iVar2 = snprintf(param_3,0x1000,"prctmode = %d\n",uVar1 & 0xff);
  return (long)iVar2;
}



//------------------------------------------------------------
// prct_mode_store @ 0012b86c size=224
// signature: undefined prct_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 prct_mode_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  long lVar5;
  undefined8 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  iVar3 = sscanf(param_3,"%x %x",(uint *)&local_50,(uint *)((ulong)&local_50 | 4));
  uVar1 = local_50;
  if (iVar3 == 2) {
    uVar2 = local_50._4_4_;
    mutex_lock(lVar5 + 0x2a8);
    pcVar4 = *(code **)(*(long *)(lVar5 + 0x600) + 200);
    if (*(int *)(pcVar4 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x12b908);
      (*pcVar4)();
    }
    (*pcVar4)(lVar5 + -0xa8,uVar1 & 0xffffffff,uVar2);
    mutex_unlock(lVar5 + 0x2a8);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ram_vbat_comp_show @ 0012b950 size=60
// signature: undefined ram_vbat_comp_show(void)
// callers: []
//------------------------------------------------------------

long ram_vbat_comp_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"ram_vbat_comp = %d\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + -0x98));
  return (long)iVar1;
}



//------------------------------------------------------------
// ram_vbat_comp_store @ 0012b990 size=168
// signature: undefined ram_vbat_comp_store(void)
// callers: []
//------------------------------------------------------------

long ram_vbat_comp_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtouint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    lVar1 = lVar3 + 0x2a8;
    mutex_lock(lVar1);
    *(bool *)(lVar3 + -0x98) = local_3c != 0;
    mutex_unlock(lVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// osc_cali_show @ 0012ba3c size=60
// signature: undefined osc_cali_show(void)
// callers: []
//------------------------------------------------------------

long osc_cali_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"osc_cali_data = 0x%02X\n",
                   *(uint *)(*(long *)(param_1 + 0x98) + -0xc));
  return (long)iVar1;
}



//------------------------------------------------------------
// osc_cali_store @ 0012ba7c size=1232
// signature: undefined osc_cali_store(void)
// callers: []
//------------------------------------------------------------

long osc_cali_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  int iVar12;
  long lVar13;
  int local_5c;
  long local_58;
  
  lVar13 = sp_el0;
  local_58 = *(long *)(lVar13 + 0x638);
  lVar13 = *(long *)(param_1 + 0x98);
  local_5c = 0;
  iVar3 = kstrtouint(param_3,0,&local_5c);
  if (iVar3 < 0) {
    param_4 = (long)iVar3;
    goto LAB_0012bbcc;
  }
  lVar9 = lVar13 + -0xa8;
  mutex_lock(lVar13 + 0x2a8);
  if (local_5c == 2) {
    pcVar6 = *(code **)(*(long *)(lVar13 + 0x600) + 0x108);
    if (*(int *)(pcVar6 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12bbb8);
      (*pcVar6)();
    }
    (*pcVar6)(lVar9,2);
    rtp_osc_cali(lVar9);
  }
  else if (local_5c == 1) {
    *(undefined1 *)(lVar13 + -0xa0) = 1;
    pcVar6 = *(code **)(*(long *)(lVar13 + 0x600) + 0x108);
    if (*(int *)(pcVar6 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12bb1c);
      (*pcVar6)();
    }
    (*pcVar6)(lVar9,0);
    rtp_osc_cali(lVar9);
    uVar11 = *(ulong *)(lVar13 + -8);
    pcVar6 = *(code **)(*(long *)(lVar13 + 0x600) + 0x170);
    if (*(int *)(pcVar6 + -4) != 0x55e024f8) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12bb50);
      (*pcVar6)();
    }
    uVar4 = (*pcVar6)(lVar9);
    uVar10 = (uint)uVar11;
    if (uVar4 == uVar10) {
      _printk(&DAT_001327da,"haptic_hv",0x345,"rtp_trim_lra_cali",uVar11 & 0xffffffff);
    }
    else if (uVar4 < uVar10) {
      uVar10 = uVar10 - uVar4;
      if (uVar4 / 0x32 < uVar10) {
        _printk(&DAT_00134b7c,"haptic_hv",0x349,"rtp_trim_lra_cali");
      }
      else {
        if ((uVar4 * 10) / 10000 <= uVar10) {
          uVar2 = 0;
          if (uVar4 * 0x18 != 0) {
            uVar2 = (uVar10 * 100000) / (uVar4 * 0x18);
          }
          iVar3 = (int)uVar2 / 10 + (uint)*(byte *)(lVar13 + -0x78);
          if (4 < (int)uVar2 % 10) {
            iVar3 = iVar3 + 1;
          }
          goto LAB_0012bdd0;
        }
        uVar5 = 0x34f;
LAB_0012bd10:
        _printk(&DAT_001341fa,"haptic_hv",uVar5,"rtp_trim_lra_cali",uVar11 & 0xffffffff,uVar4);
      }
    }
    else {
      uVar2 = uVar4 - uVar10;
      if (uVar4 < uVar10 || uVar2 == 0) {
        iVar3 = 0;
      }
      else {
        if (uVar4 / 0x32 < uVar2) {
          _printk(&DAT_00135605,"haptic_hv",0x359,"rtp_trim_lra_cali");
          goto LAB_0012bbc4;
        }
        if (uVar2 < (uVar4 * 10) / 10000) {
          uVar5 = 0x35e;
          goto LAB_0012bd10;
        }
        uVar10 = 0;
        if (uVar4 / 100000 != 0) {
          uVar10 = uVar2 / (uVar4 / 100000);
        }
        iVar3 = ((uint)*(byte *)(lVar13 + -0x78) - uVar10 / 0xf0) -
                (uint)(4 < uVar10 / 0x18 + (uVar10 / 0xf0) * -10);
      }
LAB_0012bdd0:
      if ((*(int *)(lVar13 + -0x58) == 0x9371) || (*(int *)(lVar13 + -0x58) == 0x9381)) {
        lVar8 = (uVar11 & 0xffffffff) * 0x16;
        uVar1 = 0;
        if (lVar8 != 0) {
          uVar1 = (long)(((uVar11 & 0xffffffff) * -10000 +
                         (ulong)uVar4 * (long)(*(int *)(lVar13 + -0x74) * 0x16 + 10000)) * 10) /
                  lVar8;
        }
        _printk(&DAT_0013652c,"haptic_hv",0x36a,"rtp_trim_lra_cali",uVar1 & 0xffffffff);
        iVar12 = (int)uVar1;
        if (iVar12 < 0) {
          uVar2 = -iVar12;
          uVar10 = (uint)*(byte *)(lVar13 + -0x78);
          if (uVar2 % 10 < 5) {
            iVar3 = uVar10 - uVar2 / 10;
          }
          else {
            iVar3 = uVar10 + ~(uVar2 / 10);
          }
        }
        else {
          uVar10 = (uint)*(byte *)(lVar13 + -0x78);
          iVar7 = (int)((uVar1 & 0xffffffff) / 10);
          iVar3 = iVar7 + (uint)*(byte *)(lVar13 + -0x78);
          if (4 < (uint)(iVar12 + iVar7 * -10)) {
            iVar3 = iVar3 + 1;
          }
        }
      }
      else {
        uVar10 = (uint)*(byte *)(lVar13 + -0x78);
      }
      uVar2 = -uVar10;
      if (iVar3 < (int)uVar10) {
        uVar2 = uVar10;
      }
      *(uint *)(lVar13 + -0xc) = uVar2 + iVar3;
      pcVar6 = *(code **)(*(long *)(lVar13 + 0x600) + 0x108);
      if (*(int *)(pcVar6 + -4) != 0x1a765956) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x12bef0);
        (*pcVar6)();
      }
      (*pcVar6)(lVar9,2);
      _printk(&DAT_001337ba,"haptic_hv",0x398,"rtp_trim_lra_cali",uVar11 & 0xffffffff,uVar4);
      _printk(&DAT_00136004,"haptic_hv",0x399,"rtp_trim_lra_cali",iVar3,uVar2 + iVar3);
    }
  }
LAB_0012bbc4:
  mutex_unlock(lVar13 + 0x2a8);
LAB_0012bbcc:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// rtp_osc_cali @ 0012bf4c size=1172
// signature: undefined rtp_osc_cali(void)
// callers: [osc_cali_store]
//------------------------------------------------------------

void rtp_osc_cali(long param_1)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  long lVar10;
  undefined8 uVar11;
  char *pcVar12;
  code *pcVar13;
  uint *puVar14;
  uint uVar15;
  ulong uVar16;
  size_t *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  *(undefined4 *)(param_1 + 0x78) = 0;
  local_50 = (size_t *)0x0;
  *(undefined4 *)(param_1 + 0x98) = 1;
  iVar7 = request_firmware(&local_50,aw_rtp_name,*(undefined8 *)(param_1 + 0x2c0));
  if (iVar7 < 0) {
    puVar8 = &DAT_001321e5;
    pcVar12 = aw_rtp_name;
    uVar11 = 0x2e4;
  }
  else {
    pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x40);
    if (*(int *)(pcVar13 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12bfec);
      (*pcVar13)();
    }
    (*pcVar13)(param_1);
    lVar1 = param_1 + 0x3c8;
    *(undefined1 *)(param_1 + 5) = 0;
    mutex_lock(lVar1);
    vfree(*(undefined8 *)(param_1 + 0x6e8));
    uVar16 = *local_50;
    puVar9 = (undefined4 *)vmalloc(uVar16 + 4);
    *(undefined4 **)(param_1 + 0x6e8) = puVar9;
    if (puVar9 == (undefined4 *)0x0) {
      release_firmware();
      mutex_unlock(lVar1);
      _printk(&DAT_0013446e,"haptic_hv",0x2f0,"rtp_osc_cali");
      goto LAB_0012c3a8;
    }
    if (0xfffffffffffffffb < uVar16) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(1,0x12c3dc);
      (*pcVar13)();
    }
    *puVar9 = (int)*local_50;
    *(int *)(param_1 + 0x7c) = (int)*local_50;
    _printk(&DAT_00133b0d,"haptic_hv",0x2f5,"rtp_osc_cali",aw_rtp_name);
    memcpy((void *)(*(long *)(param_1 + 0x6e8) + 4),(void *)local_50[1],*local_50);
    release_firmware(local_50);
    mutex_unlock(lVar1);
    pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x80);
    if (*(int *)(pcVar13 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c0e8);
      (*pcVar13)();
    }
    (*pcVar13)(param_1,*(undefined4 *)(param_1 + 0x3c));
    _printk(&DAT_00137786,"haptic_hv",0x24a,"ram_vbat_comp");
    pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x88);
    if (*(int *)(pcVar13 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c130);
      (*pcVar13)();
    }
    (*pcVar13)(param_1,2);
    pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x120);
    if (*(int *)(pcVar13 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c15c);
      (*pcVar13)();
    }
    (*pcVar13)(param_1,0);
    gpio_to_desc(*(undefined4 *)(param_1 + 0x54));
    gpiod_to_irq();
    disable_irq();
    pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x58);
    if (*(int *)(pcVar13 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c198);
      (*pcVar13)();
    }
    (*pcVar13)(param_1,1);
    mutex_lock(lVar1);
    lVar2 = param_1 + 0x6f0;
    uVar16 = cpu_latency_qos_request_active(lVar2);
    if ((uVar16 & 1) == 0) {
      cpu_latency_qos_add_request(lVar2,0);
    }
    do {
      pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x160);
      if (*(int *)(pcVar13 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c1fc);
        (*pcVar13)();
      }
      cVar6 = (*pcVar13)(param_1);
      if (cVar6 == '\0') {
        puVar14 = *(uint **)(param_1 + 0x6e8);
        uVar15 = *(uint *)(param_1 + 0x78);
        uVar4 = *(uint *)(param_1 + 0x520) >> 2;
        uVar5 = *puVar14 - uVar15;
        if (uVar4 <= uVar5) {
          uVar5 = uVar4;
        }
        if (*puVar14 != uVar15) {
          if (*(int *)(param_1 + 0x98) == 1) {
            uVar11 = ktime_get();
            puVar14 = *(uint **)(param_1 + 0x6e8);
            *(undefined8 *)(param_1 + 600) = uVar11;
            uVar15 = *(uint *)(param_1 + 0x78);
            *(undefined4 *)(param_1 + 0x98) = 0;
          }
          pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0xc0);
          if (*(int *)(pcVar13 + -4) != 0x6c91e1cc) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x12c280);
            (*pcVar13)();
          }
          (*pcVar13)(param_1,(long)puVar14 + (ulong)uVar15 + 4,uVar5);
          *(uint *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + uVar5;
        }
      }
      pcVar13 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x158);
      if (*(int *)(pcVar13 + -4) != -0x696f46c4) {
                    /* WARNING: Does not return */
        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c2b4);
        (*pcVar13)();
      }
      cVar6 = (*pcVar13)(param_1);
      lVar10 = ktime_get();
      *(long *)(param_1 + 0x250) = lVar10;
      if (cVar6 != '\0') {
        uVar3 = *(undefined4 *)(param_1 + 0x78);
        puVar8 = &DAT_00131eef;
        uVar11 = 0x31b;
        goto LAB_0012c32c;
      }
      uVar16 = (lVar10 - *(long *)(param_1 + 600)) / 1000;
      *(ulong *)(param_1 + 0xa0) = uVar16;
    } while (uVar16 < 0x4dd1e1);
    uVar3 = *(undefined4 *)(param_1 + 0x78);
    puVar8 = &DAT_0013686e;
    uVar11 = 0x321;
LAB_0012c32c:
    _printk(puVar8,"haptic_hv",uVar11,"rtp_osc_cali",uVar3);
    uVar16 = cpu_latency_qos_request_active(lVar2);
    if ((uVar16 & 1) != 0) {
      cpu_latency_qos_remove_request(lVar2);
    }
    mutex_unlock(lVar1);
    gpio_to_desc(*(undefined4 *)(param_1 + 0x54));
    gpiod_to_irq();
    enable_irq();
    puVar8 = &DAT_0013738a;
    uVar11 = 0x32a;
    pcVar12 = (char *)((*(long *)(param_1 + 0x250) - *(long *)(param_1 + 600)) / 1000);
    *(char **)(param_1 + 0xa0) = pcVar12;
  }
  _printk(puVar8,"haptic_hv",uVar11,"rtp_osc_cali",pcVar12);
LAB_0012c3a8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// osc_save_show @ 0012c3e4 size=60
// signature: undefined osc_save_show(void)
// callers: []
//------------------------------------------------------------

long osc_save_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"osc_cali_data = 0x%02X\n",
                   *(uint *)(*(long *)(param_1 + 0x98) + -0xc));
  return (long)iVar1;
}



//------------------------------------------------------------
// osc_save_store @ 0012c424 size=132
// signature: undefined osc_save_store(void)
// callers: []
//------------------------------------------------------------

long osc_save_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    *(undefined4 *)(lVar2 + -0xc) = local_2c;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// haptic_audio_show @ 0012c4ac size=60
// signature: undefined haptic_audio_show(void)
// callers: []
//------------------------------------------------------------

long haptic_audio_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(byte *)(*(long *)(param_1 + 0x98) + 0x5d8));
  return (long)iVar1;
}



//------------------------------------------------------------
// haptic_audio_store @ 0012c4ec size=792
// signature: undefined haptic_audio_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 haptic_audio_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined1 *puVar1;
  long *plVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  ulong uVar12;
  code *pcVar13;
  long lVar14;
  long lVar15;
  char cVar16;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70 [2];
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  lVar15 = *(long *)(param_1 + 0x98);
  local_78 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_80 = 0;
  if (*(char *)(lVar15 + -0xa2) == '\0') {
    _printk(&DAT_001325b9,"haptic_hv",0xb0c,"haptic_audio_store");
  }
  else {
    iVar9 = sscanf(param_3,"%u %u %u %u %u %u",(uint *)&local_80,(uint *)((ulong)&local_80 | 4),
                   (uint *)&local_78,(uint *)((long)&local_78 + 4),local_70,local_70 + 1);
    if (iVar9 == 6) {
      if ((uint)local_78 != 0) {
        _printk(&DAT_001368a8,"haptic_hv",0xb14,"haptic_audio_store",local_80 & 0xffffffff,
                local_80._4_4_,local_78 & 0xffffffff,local_78._4_4_,local_70[0],local_70[1]);
      }
      puVar10 = (undefined1 *)kmalloc_trace(_gpiod_set_raw_value_cansleep,0xdc0,0x18);
      if (puVar10 != (undefined1 *)0x0) {
        mutex_lock();
        uVar8 = _gpiod_set_raw_value_cansleep;
        cVar16 = local_80._4_1_;
        uVar3 = (undefined1)local_78;
        puVar10[2] = uVar3;
        uVar4 = (undefined1)local_80;
        *puVar10 = uVar4;
        puVar10[1] = local_80._4_1_;
        uVar5 = (undefined1)(local_78 >> 0x20);
        puVar10[5] = uVar5;
        uVar6 = (undefined1)local_70[0];
        puVar10[3] = uVar6;
        uVar7 = (undefined1)local_70[1];
        puVar10[4] = uVar7;
        puVar11 = (undefined1 *)kmalloc_trace(uVar8,0xdc0,0x18);
        if (puVar11 != (undefined1 *)0x0) {
          *puVar11 = uVar4;
          puVar1 = puVar11 + 8;
          puVar11[1] = cVar16;
          puVar11[2] = uVar3;
          puVar11[5] = uVar5;
          puVar11[3] = uVar6;
          plVar2 = (long *)(lVar15 + 0x5c8);
          puVar11[4] = uVar7;
          *(undefined1 **)(puVar11 + 8) = puVar1;
          *(undefined1 **)(puVar11 + 0x10) = puVar1;
          lVar14 = *(long *)(lVar15 + 0x5c8);
          uVar12 = __list_add_valid(puVar1,plVar2,lVar14);
          if ((uVar12 & 1) != 0) {
            *(undefined1 **)(lVar14 + 8) = puVar1;
            *(long *)(puVar11 + 8) = lVar14;
            *(long **)(puVar11 + 0x10) = plVar2;
            *plVar2 = (long)puVar1;
            cVar16 = puVar10[1];
          }
        }
        if (cVar16 == -1) {
          _printk(&DAT_00134872,"haptic_hv",0xb24,"haptic_audio_store");
          uVar12 = hrtimer_active(lVar15 + 0x540);
          if ((uVar12 & 1) != 0) {
            _printk(&DAT_00133149,"haptic_hv",0xb26,"haptic_audio_store");
            hrtimer_cancel(lVar15 + 0x540);
            *(undefined1 *)(lVar15 + 0x5d8) = 0;
            audio_off(lVar15 + -0xa8);
          }
        }
        else {
          uVar12 = hrtimer_active(lVar15 + 0x540);
          if ((uVar12 & 1) == 0) {
            _printk(&DAT_00131a9a,"haptic_hv",0xb2f,"haptic_audio_store");
            pcVar13 = *(code **)(*(long *)(lVar15 + 0x600) + 0xb0);
            if (*(int *)(pcVar13 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x12c7a8);
              (*pcVar13)();
            }
            (*pcVar13)(lVar15 + -0xa8,1,0);
            hrtimer_start_range_ns
                      (lVar15 + 0x540,
                       (long)((*(int *)(lVar15 + 0x4f8) % 1000000) * 1000) +
                       (long)(*(int *)(lVar15 + 0x4f8) / 1000000) * 1000000000,0,1);
          }
        }
        mutex_unlock(lVar15 + 0x510);
        kfree(puVar10);
      }
    }
  }
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// audio_off @ 0012c804 size=280
// signature: undefined audio_off(void)
// callers: [haptic_audio_store]
//------------------------------------------------------------

void audio_off(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  code *pcVar5;
  long *plVar6;
  
  _printk(&DAT_00132e8a,"haptic_hv",0x71b,"audio_off");
  mutex_lock(param_1 + 0x350);
  pcVar5 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x40);
  if (*(int *)(pcVar5 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x12c870);
    (*pcVar5)();
  }
  (*pcVar5)(param_1);
  pcVar5 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x80);
  if (*(int *)(pcVar5 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x12c89c);
    (*pcVar5)();
  }
  (*pcVar5)(param_1,0x80);
  plVar3 = *(long **)(param_1 + 0x678);
  while (plVar3 != (long *)(param_1 + 0x670)) {
    plVar6 = (long *)plVar3[1];
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    kfree(plVar3 + -1);
    plVar3 = plVar6;
  }
  mutex_unlock(param_1 + 0x350);
  return;
}



//------------------------------------------------------------
// haptic_audio_time_show @ 0012c920 size=108
// signature: undefined haptic_audio_time_show(void)
// callers: []
//------------------------------------------------------------

long haptic_audio_time_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = snprintf(param_3,0x1000,"haptic_audio.delay_val=%dus\n",*(int *)(lVar2 + 0x4f8));
  lVar3 = (long)iVar1;
  iVar1 = snprintf(param_3 + lVar3,0x1000 - lVar3,"haptic_audio.timer_val=%dus\n",
                   *(int *)(lVar2 + 0x4fc));
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// haptic_audio_time_store @ 0012c990 size=148
// signature: undefined haptic_audio_time_store(void)
// callers: []
//------------------------------------------------------------

undefined8 haptic_audio_time_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_30 [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30[0] = 0;
  local_30[1] = 0;
  iVar1 = sscanf(param_3,"%u %u",local_30,(uint *)((ulong)local_30 | 4));
  if (iVar1 == 2) {
    *(uint *)(lVar2 + 0x4f8) = local_30[0];
    *(uint *)(lVar2 + 0x4fc) = local_30[1];
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// gun_type_show @ 0012ca28 size=60
// signature: undefined gun_type_show(void)
// callers: []
//------------------------------------------------------------

long gun_type_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"0x%02x\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x24));
  return (long)iVar1;
}



//------------------------------------------------------------
// gun_type_store @ 0012ca68 size=160
// signature: undefined gun_type_store(void)
// callers: []
//------------------------------------------------------------

long gun_type_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtouint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    lVar1 = lVar3 + 0x2a8;
    mutex_lock(lVar1);
    *(undefined4 *)(lVar3 + -0x24) = local_3c;
    mutex_unlock(lVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bullet_nr_show @ 0012cb0c size=60
// signature: undefined bullet_nr_show(void)
// callers: []
//------------------------------------------------------------

long bullet_nr_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"0x%02x\n",*(uint *)(*(long *)(param_1 + 0x98) + -0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// bullet_nr_store @ 0012cb4c size=160
// signature: undefined bullet_nr_store(void)
// callers: []
//------------------------------------------------------------

long bullet_nr_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtouint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    lVar1 = lVar3 + 0x2a8;
    mutex_lock(lVar1);
    *(undefined4 *)(lVar3 + -0x20) = local_3c;
    mutex_unlock(lVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// awrw_show @ 0012cbf0 size=260
// signature: undefined awrw_show(void)
// callers: []
//------------------------------------------------------------

long awrw_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  
  lVar5 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar5 + 0x608) == 1) {
    if (*(long *)(lVar5 + 0x610) != 0) {
      if (*(int *)(lVar5 + 0x60c) == 0) {
        lVar4 = 0;
      }
      else {
        lVar4 = 0;
        uVar6 = 0;
        do {
          iVar1 = snprintf((char *)(param_3 + lVar4),0x1000 - lVar4,"0x%02x,",
                           (uint)*(byte *)(*(long *)(lVar5 + 0x610) + (long)(int)uVar6));
          lVar4 = lVar4 + iVar1;
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(lVar5 + 0x60c));
      }
      iVar1 = snprintf((char *)(param_3 + lVar4 + -1),0x1000 - lVar4,"\n");
      return lVar4 + iVar1;
    }
    puVar2 = &DAT_00133eae;
    uVar3 = 0xba1;
  }
  else {
    puVar2 = &DAT_001368ee;
    uVar3 = 0xb9d;
  }
  _printk(puVar2,"haptic_hv",uVar3,"awrw_show");
  return -0x22;
}



//------------------------------------------------------------
// awrw_store @ 0012ccf8 size=804
// signature: undefined awrw_store(void)
// callers: []
//------------------------------------------------------------

undefined8 awrw_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  ulong __n;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  size_t sVar5;
  undefined1 *puVar6;
  undefined *puVar7;
  long lVar8;
  uint uVar9;
  void *__src;
  long lVar10;
  uint local_94;
  undefined8 local_90;
  undefined1 local_88 [4];
  undefined1 local_84 [4];
  undefined4 local_80;
  undefined1 local_7c;
  undefined2 local_78;
  undefined6 uStack_76;
  undefined1 *local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x98);
  local_88[0] = 0;
  local_7c = 0;
  local_80 = 0;
  local_90 = 0;
  local_94 = 0;
  iVar2 = sscanf(param_3,"%x %x %x",(uint *)((long)&local_90 + 4),(uint *)&local_90,&local_94);
  if (iVar2 != 3) {
    _printk(&DAT_00137a56,"haptic_hv",0xbde,"awrw_store");
    goto LAB_0012cee8;
  }
  if ((uint)local_90 == 0) {
    uVar4 = 0xbbc;
LAB_0012d00c:
    _printk(&DAT_00137a56,"haptic_hv",uVar4,"awrw_store");
    param_4 = 0xffffffffffffffde;
  }
  else {
    *(int *)(lVar10 + 0x608) = local_90._4_4_;
    *(uint *)(lVar10 + 0x60c) = (uint)local_90;
    if (*(long *)(lVar10 + 0x610) != 0) {
      kfree();
    }
    uVar4 = __kmalloc(local_90 & 0xffffffff,0xcc0);
    *(undefined8 *)(lVar10 + 0x610) = uVar4;
    if (local_90._4_4_ == 1) {
      mutex_lock(lVar10 + 0x2a8);
      local_60 = *(undefined8 *)(lVar10 + 0x610);
      local_70 = local_84;
      lVar8 = *(long *)(lVar10 + 0x220);
      local_84[0] = (undefined1)local_94;
      _local_78 = CONCAT62(0x10000,*(undefined2 *)(lVar8 + 2));
      local_68 = (ulong)CONCAT24((short)local_90,CONCAT22(1,*(undefined2 *)(lVar8 + 2)));
      iVar2 = i2c_transfer(*(undefined8 *)(lVar8 + 0x18),&local_78,2);
      if (iVar2 < 0) {
        puVar7 = &DAT_001343e2;
        uVar4 = 0x76;
      }
      else {
        if (iVar2 == 2) goto LAB_0012cee0;
        puVar7 = &DAT_001324a5;
        uVar4 = 0x79;
      }
      _printk(puVar7,"haptic_hv",uVar4,"haptic_hv_i2c_reads");
    }
    else {
      if (local_90._4_4_ != 0) goto LAB_0012cee8;
      uVar1 = (uint)local_90;
      uVar9 = (uint)local_90 * 5;
      sVar5 = strlen(param_3);
      if (sVar5 - 0xf != (ulong)uVar9) {
        uVar4 = 0xbc6;
        goto LAB_0012d00c;
      }
      if (uVar1 != 0) {
        uVar9 = 0;
        iVar2 = 0xf;
        do {
          local_80 = *(undefined4 *)(param_3 + iVar2);
          local_7c = 0;
          iVar3 = kstrtou8(&local_80,0,local_88);
          if (iVar3 < 0) {
            uVar4 = 0xbce;
            goto LAB_0012d00c;
          }
          iVar2 = iVar2 + 5;
          *(undefined1 *)(*(long *)(lVar10 + 0x610) + (long)(int)uVar9) = local_88[0];
          uVar9 = uVar9 + 1;
        } while (uVar9 < (uint)local_90);
      }
      mutex_lock(lVar10 + 0x2a8);
      uVar9 = local_94;
      __n = local_90 & 0xffffffff;
      __src = *(void **)(lVar10 + 0x610);
      iVar2 = (uint)local_90 + 1;
      puVar6 = (undefined1 *)__kmalloc(iVar2,0xcc0);
      *puVar6 = (char)uVar9;
      memcpy(puVar6 + 1,__src,__n);
      iVar2 = i2c_transfer_buffer_flags(*(undefined8 *)(lVar10 + 0x220),puVar6,iVar2,0);
      if (iVar2 < 0) {
        _printk(&DAT_00137c1e,"haptic_hv",0x8a,"haptic_hv_i2c_writes",uVar9 & 0xff);
      }
      kfree(puVar6);
    }
LAB_0012cee0:
    mutex_unlock(lVar10 + 0x2a8);
  }
LAB_0012cee8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wait_enter_rtp_mode @ 0012d01c size=292
// signature: undefined wait_enter_rtp_mode(void)
// callers: [rtp_work_routine]
//------------------------------------------------------------

undefined8 wait_enter_rtp_mode(long param_1)

{
  bool bVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = -200;
  while( true ) {
    pcVar3 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x30);
    if (*(int *)(pcVar3 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x12d078);
      (*pcVar3)();
    }
    cVar2 = (*pcVar3)(param_1);
    if (cVar2 != '\0') break;
    _printk(&DAT_00137c6e,"haptic_hv",0x4f1,"wait_enter_rtp_mode",0);
    usleep_range_state(2000,0x9c4,2);
    bVar1 = iVar4 == -1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      pcVar3 = *(code **)(*(long *)(param_1 + 0x6a8) + 0x40);
      if (*(int *)(pcVar3 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x12d0d8);
        (*pcVar3)();
      }
      (*pcVar3)(param_1);
      _printk(&DAT_00135c43,"haptic_hv",0x4f6,"wait_enter_rtp_mode");
      return 0xffffffde;
    }
  }
  _printk(&DAT_00137a73,"haptic_hv",0x4ed,"wait_enter_rtp_mode");
  return 0;
}



//------------------------------------------------------------
// audio_timer_func @ 0012d144 size=136
// signature: undefined audio_timer_func(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_timer_func(long param_1)

{
  queue_work_on(0x20,*(undefined8 *)(param_1 + -0xd8),param_1 + 0x48);
  hrtimer_start_range_ns
            (param_1,(long)((*(int *)(param_1 + -0x44) % 1000000) * 1000) +
                     (long)(*(int *)(param_1 + -0x44) / 1000000) * 1000000000,0,1);
  return 0;
}



//------------------------------------------------------------
// audio_work_routine @ 0012d1d0 size=1096
// signature: undefined audio_work_routine(void)
// callers: []
//------------------------------------------------------------

void audio_work_routine(long param_1)

{
  long *plVar1;
  uint uVar2;
  long *plVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  code *pcVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  long *plVar13;
  
  lVar10 = param_1 + -0x78;
  mutex_lock(lVar10);
  plVar11 = *(long **)(param_1 + 0x48);
  plVar1 = (long *)(param_1 + 0x40);
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  if (plVar11 != plVar1) {
    if ((long *)*plVar1 == plVar1) {
      uVar8 = 0;
    }
    else {
      uVar8 = (uint)*(byte *)((long *)*plVar1 + -1);
    }
    uVar5 = uVar8 - *(byte *)(plVar11 + -1);
    uVar2 = uVar5 + 0x20;
    if (*(byte *)(plVar11 + -1) <= uVar8) {
      uVar2 = uVar5;
    }
    if (2 < uVar2) {
      uVar8 = 0;
      do {
        if (plVar11 == plVar1) break;
        plVar13 = (long *)plVar11[1];
        if ((*(char *)((long)plVar11 + -6) == '\0') && ((*(byte *)((long)plVar11 + -7) & 0xf) == 1))
        {
          uVar7 = __list_del_entry_valid(plVar11);
          if ((uVar7 & 1) != 0) {
            lVar12 = *plVar11;
            plVar3 = (long *)plVar11[1];
            *(long **)(lVar12 + 8) = plVar3;
            *plVar3 = lVar12;
          }
          *plVar11 = -0x2152ffffffffff00;
          plVar11[1] = -0x2152fffffffffede;
          kfree(plVar11 + -1);
          uVar8 = uVar8 + 1;
        }
        plVar11 = plVar13;
      } while (uVar8 != uVar2);
      plVar11 = *(long **)(param_1 + 0x48);
    }
    if (plVar11 != plVar1) {
      *(char *)(param_1 + 0x50) = (char)plVar11[-1];
      *(undefined1 *)(param_1 + 0x51) = *(undefined1 *)((long)plVar11 + -7);
      *(undefined1 *)(param_1 + 0x52) = *(undefined1 *)((long)plVar11 + -6);
      *(undefined1 *)(param_1 + 0x55) = *(undefined1 *)((long)plVar11 + -3);
      *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)((long)plVar11 + -5);
      *(undefined1 *)(param_1 + 0x54) = *(undefined1 *)((long)plVar11 + -4);
      uVar7 = __list_del_entry_valid(plVar11);
      if ((uVar7 & 1) != 0) {
        lVar12 = *plVar11;
        plVar1 = (long *)plVar11[1];
        *(long **)(lVar12 + 8) = plVar1;
        *plVar1 = lVar12;
      }
      *plVar11 = -0x2152ffffffffff00;
      plVar11[1] = -0x2152fffffffffede;
      kfree(plVar11 + -1);
    }
  }
  if (*(char *)(param_1 + 0x52) != '\0') {
    _printk(&DAT_001368a8,"haptic_hv",0x77f,"audio_work_routine",*(undefined1 *)(param_1 + 0x50),
            *(undefined1 *)(param_1 + 0x51),*(char *)(param_1 + 0x52),
            *(undefined1 *)(param_1 + 0x55),*(undefined1 *)(param_1 + 0x53),
            *(undefined1 *)(param_1 + 0x54));
  }
  if (*(byte *)(param_1 + -0x10c) < *(byte *)(param_1 + 0x55)) {
    _printk(&DAT_00133ee0,"haptic_hv",0x782,"audio_work_routine");
  }
  else {
    lVar12 = param_1 + -0x630;
    pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x30);
    if (*(int *)(pcVar9 + -4) != 0x79194b6d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d370);
      (*pcVar9)();
    }
    iVar6 = (*pcVar9)(lVar12);
    mutex_unlock(lVar10);
    if (iVar6 != 0) {
      return;
    }
    if (*(char *)(param_1 + 0x51) != '\x01') {
      return;
    }
    cVar4 = *(char *)(param_1 + 0x52);
    if (cVar4 == '\x02') {
      lVar10 = param_1 + -0x2e0;
      mutex_lock(lVar10);
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x40);
      if (*(int *)(pcVar9 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d5ac);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12);
    }
    else if (cVar4 == '\b') {
      lVar10 = param_1 + -0x2e0;
      mutex_lock(lVar10);
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x80);
      if (*(int *)(pcVar9 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d5e8);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,*(undefined1 *)(param_1 + 0x54));
    }
    else {
      if (cVar4 != '\x01') {
        return;
      }
      _printk(&DAT_001370cd,"haptic_hv",0x7b6,"audio_work_routine");
      lVar10 = param_1 + -0x2e0;
      mutex_lock(lVar10);
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x40);
      if (*(int *)(pcVar9 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d3fc);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12);
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x88);
      if (*(int *)(pcVar9 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d428);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,1);
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0xb0);
      if (*(int *)(pcVar9 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d458);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,0,*(undefined1 *)(param_1 + 0x55));
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0xb0);
      if (*(int *)(pcVar9 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d488);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,1,0);
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0xb8);
      if (*(int *)(pcVar9 + -4) != -0x24166715) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d4b8);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,0,*(undefined1 *)(param_1 + 0x53));
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x80);
      if (*(int *)(pcVar9 + -4) != -0x6bc804a0) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d4e4);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,*(undefined1 *)(param_1 + 0x54));
      pcVar9 = *(code **)(*(long *)(param_1 + 0x78) + 0x58);
      if (*(int *)(pcVar9 + -4) != -0x43abc456) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x12d510);
        (*pcVar9)();
      }
      (*pcVar9)(lVar12,1);
    }
  }
  mutex_unlock(lVar10);
  return;
}



//------------------------------------------------------------
// ram_work_routine @ 0012d61c size=80
// signature: undefined ram_work_routine(void)
// callers: []
//------------------------------------------------------------

void ram_work_routine(long param_1)

{
  *(undefined2 *)(param_1 + -0x453) = 0;
  request_firmware_nowait
            (&__this_module,1,aw_ram_name,*(undefined8 *)(param_1 + -0x198),0xcc0,param_1 + -0x458,
             ram_load);
  return;
}



//------------------------------------------------------------
// aw_i2c_suspend @ 0012d670 size=100
// signature: undefined aw_i2c_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_i2c_suspend(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar2 + 0x350);
  pcVar1 = *(code **)(*(long *)(lVar2 + 0x6a8) + 0x40);
  if (*(int *)(pcVar1 + -4) != 0x2340237f) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x12d6b4);
    (*pcVar1)();
  }
  (*pcVar1)(lVar2);
  mutex_unlock(lVar2 + 0x350);
  return 0;
}



//------------------------------------------------------------
// aw_i2c_resume @ 0012d6d8 size=8
// signature: undefined aw_i2c_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_i2c_resume(void)

{
  return 0;
}



//------------------------------------------------------------
// init_module @ 001380c4 size=132
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_00135eeb,"haptic_hv","aw_i2c_init","v1.10.0");
  iVar1 = i2c_register_driver(&__this_module,aw_i2c_driver);
  if (iVar1 != 0) {
    _printk(&DAT_00132160,"haptic_hv","aw_i2c_init");
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0013814c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(aw_i2c_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 0013a000 size=1
// signature: undefined _printk(void)
// callers: [aw869x_check_qualify, aw8692x_upload_lra, aw869xx_ram_get_f0, aw8692x_get_f0, aw8693xs_misc_para_init, irq_handle, activate_store, vmax_store, audio_work_routine, aw869xx_play_go, aw869x_offset_cali, aw869xx_check_qualify, aw869x_trig_init, aw8671x_check_qualify, ram_cali_store, aw869xx_misc_para_init, trig_store, aw8692x_play_go, aw869xx_set_dai_sysclk, aw869x_get_theory_time, aw8693x_ram_get_f0, aw8672x_judge_rtp_going, aw8693xs_trig_init, f0_cali, aw8671x_misc_para_init, aw8693x_shutdown, aw8693xs_play_mode, tiktap_init, aw869xx_get_theory_time, aw8693xs_set_pwm, aw8693x_container_update, reg_store, strength_store, aw_remove, aw8693xs_hw_params, aw8671x_stop, aw869xx_creat_node, rtp_work_routine, aw869xx_irq_clear, aw8693x_creat_node, aw869x_upload_lra, aw8671x_set_dai_sysclk, aw8692x_container_update, haptic_hv_i2c_reads, aw8693x_cont_config, aw8693xs_container_update, aw8693x_set_dai_sysclk, aw8693x_codec_remove, haptic_init, aw8693xs_offset_os_code, aw8671x_irq_clear, aw8693x_set_bst_vol, aw869x_parse_dt, aw8693xs_snd_soc_init, awrw_show, rtp_auto_sin_store, haptic_audio_store, aw8672x_creat_node, rtp_auto_sin_store, aw869xx_get_vbat, aw8671x_cont_config, aw8671x_mute, aw8692x_stop, trig_store, aw8671x_get_vbat, read_chipid, aw8671x_codec_read, aw8672x_misc_para_init, aw8693x_play_go, aw8692x_interrupt_setup, aw869xx_protect_config, aw8672x_mute, aw869x_interrupt_setup, trig_store, aw8671x_get_theory_time, aw8693xs_get_f0, aw8693xs_ram_get_f0, aw8693xs_codec_remove, aw869x_protect_config, index_store, aw869xx_upload_lra, aw869xx_mute, aw869xx_hw_params, aw8693x_trig_init, aw869x_container_update, aw8693x_hw_params, haptic_hv_i2c_writes, aw8672x_hw_params, calculate_cali_data, aw8672x_parse_dt, trig_store, duration_store, ram_load, aw8693xs_shutdown, aw8672x_bst_mode_config, aw8693xs_bst_mode_config, aw869xx_set_fmt, aw8671x_container_update, aw8671x_startup, aw8692x_get_vbat, aw8671x_bst_mode_config, aw8672x_upload_lra, aw869xx_get_irq_state, aw869x_cont_config, aw869xx_startup, aw8671x_upload_lra, aw869xx_trig_init, aw8693x_parse_dt, aw8672x_shutdown, aw869xx_cont_config, aw8693x_judge_rtp_going, wait_enter_rtp_mode, aw8693xs_judge_rtp_going, aw869x_set_bst_peak_cur, aw8693x_get_irq_state, vibrator_work_routine, aw8692x_creat_node, aw8672x_codec_remove, aw8672x_snd_soc_init, vibrator_init, aw8693xs_play_go, sw_reset, aw869x_get_irq_state, init_module, brightness_set, aw869xx_container_update, aw869x_ram_get_f0, aw8672x_get_f0, aw8692x_protect_config, aw869xx_get_f0, loop_store, aw869xx_codec_probe, seq_store, aw8671x_protect_config, aw8672x_offset_cali, aw8671x_codec_probe, aw869x_bst_mode_config, awrw_store, aw8671x_hw_params, aw8692x_play_mode, aw8693xs_stop, get_ram_num, aw8692x_check_qualify, aw869x_creat_node, aw8693xs_protect_config, aw8672x_cont_config, tiktap_work_routine, audio_off, aw8693x_snd_soc_init, irq_config, aw869xx_stop, aw8693x_play_mode, aw869x_play_mode, ram_update_show, aw869xx_snd_soc_init, aw8692x_parse_dt, aw8671x_set_fmt, aw8692x_judge_rtp_going, aw8672x_get_vbat, aw8693xs_cont_config, aw869xx_bst_mode_config, aw8671x_play_mode, aw8672x_ram_get_f0, aw8672x_get_theory_time, gain_store, aw8692x_get_theory_time, aw8693xs_mute, aw8671x_codec_write, aw8693xs_get_bemf_peak, aw8693xs_set_dai_sysclk, aw869x_get_vbat, aw869x_stop, aw8692x_ram_get_f0, aw8672x_get_irq_state, tiktap_unlocked_ioctl, aw869xx_parse_dt, aw8672x_check_qualify, aw8693xs_set_bst_vol, aw869x_misc_para_init, aw869xx_judge_rtp_going, osc_cali_store, aw8693xs_upload_lra, aw8692x_set_pwm, aw8693x_get_f0, aw8693xs_check_qualify, aw8671x_ram_get_f0, aw8692x_set_bst_peak_cur, rtp_play, aw8693x_bst_mode_config, aw_i2c_probe, rtp_store, aw869xx_shutdown, aw8693x_stop, aw869xx_play_mode, aw8671x_parse_dt, aw8672x_stop, aw8692x_bst_mode_config, aw8693xs_set_fmt, aw8692x_cont_config, aw8671x_creat_node, aw8693x_get_vbat, parse_chipid, aw869x_get_f0, aw8693x_set_pwm, rtp_osc_cali, aw8693x_mute, trig_store, aw8672x_protect_config, aw8693x_check_qualify, aw8693x_upload_lra, aw8671x_interrupt_setup, aw8672x_set_fmt, tiktap_file_mmap, aw8692x_misc_para_init, aw8671x_judge_rtp_going, aw8693xs_creat_node, aw8671x_get_irq_state, aw869x_play_go, trig_store, aw8671x_shutdown, aw8693x_protect_config, aw8693x_set_fmt, aw8671x_trig_init, aw8672x_irq_clear, aw8693xs_get_irq_state, aw8672x_set_dai_sysclk, aw8671x_get_f0, aw8692x_get_irq_state, aw8693xs_offset_cali, aw8672x_trig_init, aw869xx_codec_remove, aw869xx_codec_write, trig_store, aw8671x_codec_remove, aw8672x_play_mode, aw8693x_misc_para_init, aw8672x_container_update, aw8693xs_get_vbat, aw8693x_offset_cali, aw869xx_offset_cali, aw8671x_snd_soc_init, haptic_hv_i2c_write_bits, aw8693xs_read_f0, aw8693xs_parse_dt, aw869xx_set_bst_peak_cur, rtp_auto_sin_store, aw8672x_interrupt_setup, aw869xx_codec_read, aw8692x_trig_init, aw869xx_interrupt_setup, aw869x_judge_rtp_going]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0013a008 size=1
// signature: undefined ktime_get(void)
// callers: [aw869x_get_f0, aw869x_play_go, aw869x_cont_config, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0013a010 size=1
// signature: undefined usleep_range_state(void)
// callers: [aw8672x_get_f0, aw8671x_get_vbat, aw869xx_get_f0, aw8671x_ram_get_f0, aw8671x_ram_init, aw869xx_ram_get_f0, aw8692x_get_f0, aw_i2c_probe, aw8672x_offset_cali, aw8693x_stop, aw869xx_play_go, aw8672x_mute, aw8692x_get_lra_resistance, aw869x_offset_cali, aw8672x_stop, aw8693xs_get_f0, aw8672x_ram_init, aw8693xs_ram_get_f0, aw8693x_get_vbat, aw869xx_mute, aw8693xs_stop, aw869xx_ram_init, aw8692x_check_qualify, parse_chipid, aw869x_get_f0, aw8692x_ram_init, aw869x_container_update, aw8693x_mute, aw8693x_ram_get_f0, aw869xx_stop, aw869x_play_mode, aw869x_ram_init, aw8693x_container_update, aw869xx_get_lra_resistance, aw8672x_get_vbat, aw8672x_get_lra_resistance, aw8671x_container_update, aw869x_play_go, aw8671x_stop, rtp_work_routine, aw8672x_ram_get_f0, aw8692x_get_vbat, aw8692x_container_update, aw8671x_get_f0, aw8693xs_container_update, aw8693xs_mute, aw8671x_play_go, aw869x_get_lra_resistance, aw8693xs_ram_init, aw8693xs_offset_os_code, wait_enter_rtp_mode, aw8693xs_get_lra_resistance, aw869x_get_vbat, aw8693x_ram_init, aw8672x_container_update, aw8693xs_get_vbat, aw869x_stop, aw8692x_ram_get_f0, aw8693x_get_lra_resistance, aw8671x_get_lra_resistance, aw8693x_offset_cali, aw869xx_offset_cali, sw_reset, aw869xx_get_vbat, aw869xx_container_update, aw8693x_get_f0, aw8671x_mute, aw8692x_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0013a018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [aw8692x_upload_lra, aw869xx_ram_get_f0, aw8692x_get_f0, aw869x_rtp_get_fifo_aes, cont_drv_time_store, aw8693xs_get_osc_status, aw869xx_osc_read_status, aw8693xs_misc_para_init, aw8671x_get_osc_status, aw8693xs_rtp_get_fifo_afs, aw8672x_get_glb_state, activate_store, aw869xx_rtp_get_fifo_afs, vmax_store, aw869xx_play_go, aw8693x_get_first_wave_addr, aw869x_offset_cali, aw869xx_check_qualify, aw869x_trig_init, aw8693xs_trig1_param_config, aw869xx_get_prctmode, aw8693xs_rtp_get_fifo_aes, aw8671x_check_qualify, aw869x_osc_read_status, ram_cali_store, aw869x_get_reg, aw869xx_misc_para_init, trig_store, aw8692x_play_go, aw8692x_get_first_wave_addr, aw869x_get_theory_time, aw8693x_ram_get_f0, aw8672x_judge_rtp_going, aw8693xs_trig_init, aw8671x_misc_para_init, aw869x_get_wav_seq, aw8693xs_get_wav_seq, aw8693xs_set_repeat_seq, aw869xx_get_theory_time, aw8693x_container_update, reg_store, aw8672x_play_go, aw869x_get_prctmode, aw8693xs_interrupt_setup, strength_store, aw8672x_get_trim_lra, aw8671x_stop, aw8693x_get_glb_state, rtp_work_routine, aw869xx_irq_clear, aw869xx_get_reg, aw869x_upload_lra, aw8693xs_set_gain, aw8671x_set_wav_seq, aw8692x_container_update, haptic_hv_i2c_reads, aw8693x_cont_config, aw8693xs_container_update, aw8671x_rtp_get_fifo_aes, aw869xx_get_wav_loop, aw8671x_play_go, aw8693x_get_trim_lra, aw8693xs_offset_os_code, aw8671x_irq_clear, aw869x_parse_dt, aw8693xs_irq_clear, aw869x_get_trim_lra, aw8672x_get_osc_status, aw8692x_set_ram_addr, rtp_auto_sin_store, haptic_audio_store, cont_drv_lvl_store, bullet_nr_store, rtp_auto_sin_store, aw8672x_set_wav_seq, aw8692x_rtp_get_fifo_afs, aw869xx_get_glb_state, aw869xx_get_vbat, aw8672x_set_bst_vol, aw8693x_set_gain, aw8671x_cont_config, prct_mode_store, aw8671x_mute, aw8692x_stop, trig_store, aw8693x_get_wav_loop, aw8671x_get_vbat, aw8693xs_codec_probe, read_chipid, aw8671x_codec_read, aw8672x_misc_para_init, aw8693x_play_go, aw8692x_interrupt_setup, aw869xx_protect_config, aw8672x_mute, aw869x_interrupt_setup, aw8671x_get_wav_loop, trig_store, aw869x_set_gain, aw8671x_get_theory_time, aw8693xs_get_f0, aw8693xs_ram_get_f0, aw869x_protect_config, aw869xx_vbat_mode_config, aw8671x_rtp_get_fifo_afs, aw869x_rtp_get_fifo_afs, index_store, aw8672x_codec_probe, aw869xx_mute, aw8693xs_get_wav_loop, aw869xx_hw_params, aw8693x_trig_init, aw869x_container_update, aw869xx_get_trim_lra, aw8692x_get_prctmode, aw8692x_set_gain, aw869x_get_glb_state, aw8672x_parse_dt, aw869xx_rtp_get_fifo_aes, trig_store, duration_store, aw8692x_set_wav_seq, aw8693x_get_wav_seq, aw8671x_container_update, aw8692x_irq_clear, aw8692x_get_vbat, aw869xx_set_ram_addr, auto_boost_store, aw8672x_set_ram_addr, aw869xx_get_irq_state, aw8693x_codec_probe, aw869x_cont_config, cont_drv_lvl_store, aw869xx_trig_init, aw8693x_parse_dt, aw8693xs_set_wav_seq, aw869xx_cont_config, aw8693x_get_osc_status, aw8693x_judge_rtp_going, aw869x_set_ram_addr, aw8672x_get_wav_loop, aw8693xs_get_lra_resistance, aw8693xs_judge_rtp_going, aw8672x_get_first_wave_addr, aw8693x_get_irq_state, aw8693x_get_lra_resistance, aw8671x_get_lra_resistance, vibrator_init, aw8693xs_play_go, aw869xx_set_repeat_seq, cont_drv_lvl_store, aw8693x_trig1_param_config, cont_num_brk_store, aw869x_get_irq_state, aw8672x_get_prctmode, aw8671x_get_prctmode, aw869xx_set_wav_seq, cont_store, aw869xx_container_update, aw8672x_get_f0, aw8692x_protect_config, aw869xx_get_f0, loop_store, aw8692x_get_osc_status, seq_store, cont_drv_lvl_store, aw8693x_trig2_param_config, aw8671x_protect_config, aw8672x_offset_cali, aw8693x_irq_clear, cont_td_store, awrw_store, cont_drv_lvl_store, cont_drv_time_store, aw8671x_get_wav_seq, aw869x_irq_clear, aw8671x_hw_params, aw8693x_interrupt_setup, aw8693xs_stop, aw8693xs_get_glb_state, aw8693xs_trig3_param_config, get_ram_num, aw8692x_check_qualify, aw8693xs_protect_config, aw8672x_cont_config, aw8671x_get_reg, aw869xx_set_gain, tiktap_work_routine, f0_save_store, aw869xx_stop, aw869x_play_mode, cali_store, aw8692x_parse_dt, aw8693x_get_prctmode, aw8671x_set_gain, aw8692x_judge_rtp_going, aw8672x_get_vbat, aw8693xs_cont_config, activate_mode_store, aw869xx_get_wav_seq, aw8692x_get_reg, aw8672x_ram_get_f0, aw8672x_get_theory_time, aw8693xs_set_ram_addr, gun_type_store, aw8671x_set_ram_addr, gain_store, aw8692x_trig1_param_config, aw8693xs_get_reg, aw8693xs_trig2_param_config, aw8692x_get_theory_time, aw8693xs_mute, aw8671x_codec_write, aw8693xs_get_bemf_peak, aw869x_get_lra_resistance, aw869x_get_vbat, ram_update_store, cont_drv_time_store, aw869x_stop, aw8692x_ram_get_f0, aw8672x_get_irq_state, tiktap_unlocked_ioctl, aw869xx_parse_dt, cont_drv_lvl_store, aw8672x_check_qualify, aw869xx_get_first_wave_addr, aw869x_misc_para_init, aw869xx_judge_rtp_going, osc_cali_store, aw8693xs_upload_lra, ram_vbat_comp_store, aw8672x_get_reg, aw8672x_rtp_get_fifo_afs, aw8693x_get_f0, aw8693xs_check_qualify, aw8671x_ram_get_f0, aw8692x_set_bst_peak_cur, aw_i2c_probe, rtp_store, aw869x_get_wav_loop, aw8692x_trig2_param_config, aw8693x_stop, cont_drv_time_store, aw8692x_get_lra_resistance, aw869xx_play_mode, aw8693xs_get_first_wave_addr, aw8671x_parse_dt, aw8672x_stop, aw8692x_cont_config, aw8671x_get_first_wave_addr, aw8692x_get_wav_loop, aw8693x_get_vbat, aw8693x_get_reg, aw8693x_set_ram_addr, aw8693xs_get_trim_lra, aw8693x_rtp_get_fifo_afs, parse_chipid, aw869x_get_f0, aw8692x_get_wav_seq, cont_drv_time_store, rtp_osc_cali, cont_zc_thr_store, aw8693x_set_repeat_seq, aw8693x_mute, osc_save_store, trig_store, aw8672x_set_repeat_seq, aw8672x_protect_config, aw8693x_check_qualify, aw8693x_upload_lra, aw869x_set_repeat_seq, aw8671x_interrupt_setup, aw8672x_rtp_get_fifo_aes, aw8693xs_get_prctmode, aw869xx_get_lra_resistance, aw8672x_get_lra_resistance, aw8692x_misc_para_init, aw8671x_judge_rtp_going, aw8671x_get_trim_lra, aw8693x_set_wav_seq, aw8671x_get_irq_state, aw8693x_rtp_get_fifo_aes, trig_store, aw8692x_set_repeat_seq, aw8693x_protect_config, aw869x_set_wav_seq, aw8671x_trig_init, cont_drv_time_store, aw8672x_irq_clear, aw8672x_get_wav_seq, aw8693xs_get_irq_state, aw8671x_get_f0, aw8692x_get_irq_state, haptic_audio_time_store, aw8672x_trig_init, aw8671x_set_repeat_seq, aw869xx_codec_write, trig_store, aw8671x_get_glb_state, aw8692x_get_trim_lra, aw8692x_get_glb_state, aw8672x_set_gain, aw8693x_misc_para_init, aw8672x_container_update, aw8693xs_get_vbat, aw8693x_trig3_param_config, aw8692x_trig3_param_config, aw8693x_offset_cali, aw869xx_offset_cali, haptic_hv_i2c_write_bits, aw8693xs_read_f0, aw8693xs_parse_dt, aw8692x_rtp_get_fifo_aes, cont_drv_store, rtp_auto_sin_store, aw8672x_interrupt_setup, aw869xx_codec_read, aw869x_get_first_wave_addr, aw8692x_trig_init, aw869xx_interrupt_setup, aw869x_judge_rtp_going]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0013a020 size=1
// signature: undefined sysfs_create_group(void)
// callers: [aw8693xs_creat_node, aw869x_creat_node, aw8692x_creat_node, aw869xx_creat_node, aw8672x_creat_node, aw8693x_creat_node, vibrator_init, aw8671x_creat_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0013a028 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [aw8693xs_container_update, aw8671x_container_update, aw8672x_container_update, aw869x_container_update, aw8693x_container_update, aw8692x_container_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0013a030 size=1
// signature: undefined mutex_lock(void)
// callers: [trig_store, rtp_store, loop_store, aw869xx_shutdown, seq_store, cont_drv_lvl_store, irq_handle, activate_store, index_show, ram_cali_show, vmax_store, lra_resistance_show, audio_work_routine, aw8672x_mute, trig_store, cont_brk_time_store, awrw_store, cont_drv_time_store, aw8671x_hw_params, index_store, aw869xx_mute, get_ram_num, aw869xx_hw_params, ram_cali_store, aw869x_container_update, trig_store, cont_drv_time_store, cont_brk_time_store, tiktap_work_routine, rtp_osc_cali, audio_off, aw8693x_hw_params, aw8672x_hw_params, aw8693x_mute, trig_store, ram_f0_show, seq_show, trig_store, ram_update_show, cali_store, duration_store, ram_load, aw8693x_shutdown, aw8693x_container_update, aw8693xs_shutdown, reg_store, strength_store, aw8671x_container_update, aw8693xs_hw_params, activate_mode_store, trig_store, aw8671x_shutdown, aw8671x_startup, rtp_work_routine, aw8692x_container_update, gun_type_store, gain_store, vbat_monitor_show, auto_boost_store, aw8693xs_container_update, cali_show, prct_mode_show, aw8693xs_mute, aw_i2c_suspend, trig_store, haptic_init, f0_show, aw869xx_startup, aw8672x_shutdown, loop_show, cont_brk_time_store, aw8672x_container_update, cont_drv_time_store, vibrator_work_routine, tiktap_unlocked_ioctl, cont_drv_lvl_store, rtp_auto_sin_store, haptic_audio_store, osc_cali_store, rtp_auto_sin_store, cont_drv_lvl_store, ram_vbat_comp_store, bullet_nr_store, rtp_auto_sin_store, brightness_set, cont_store, aw869xx_container_update, prct_mode_store, aw8671x_mute, reg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0013a038 size=1
// signature: undefined mutex_unlock(void)
// callers: [trig_store, rtp_store, loop_store, aw869xx_shutdown, seq_store, cont_drv_lvl_store, irq_handle, activate_store, index_show, ram_cali_show, vmax_store, lra_resistance_show, audio_work_routine, aw8672x_mute, trig_store, cont_brk_time_store, awrw_store, cont_drv_time_store, aw8671x_hw_params, index_store, aw869xx_mute, get_ram_num, aw869xx_hw_params, ram_cali_store, aw869x_container_update, trig_store, cont_drv_time_store, cont_brk_time_store, tiktap_work_routine, rtp_osc_cali, audio_off, aw8693x_hw_params, aw8672x_hw_params, aw8693x_mute, trig_store, ram_f0_show, seq_show, trig_store, ram_update_show, cali_store, duration_store, ram_load, aw8693x_shutdown, aw8693x_container_update, aw8693xs_shutdown, reg_store, strength_store, aw8671x_container_update, aw8693xs_hw_params, activate_mode_store, trig_store, aw8671x_shutdown, aw8671x_startup, rtp_work_routine, aw8692x_container_update, gun_type_store, gain_store, vbat_monitor_show, auto_boost_store, aw8693xs_container_update, cali_show, prct_mode_show, aw8693xs_mute, aw_i2c_suspend, trig_store, haptic_init, f0_show, aw869xx_startup, aw8672x_shutdown, loop_show, cont_brk_time_store, aw8672x_container_update, cont_drv_time_store, vibrator_work_routine, tiktap_unlocked_ioctl, cont_drv_lvl_store, rtp_auto_sin_store, haptic_audio_store, osc_cali_store, rtp_auto_sin_store, cont_drv_lvl_store, ram_vbat_comp_store, bullet_nr_store, rtp_auto_sin_store, brightness_set, cont_store, aw869xx_container_update, prct_mode_store, aw8671x_mute, reg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0013a040 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [aw869x_parse_dt, aw8671x_parse_dt, aw8692x_parse_dt, aw869xx_parse_dt, aw8693x_parse_dt, aw8693xs_parse_dt, aw8672x_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u8_array @ 0013a048 size=1
// signature: undefined of_property_read_variable_u8_array(void)
// callers: [aw869x_parse_dt, aw_i2c_probe, aw8671x_parse_dt, aw8692x_parse_dt, aw869xx_parse_dt, aw8693x_parse_dt, aw8693xs_parse_dt, aw8672x_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u8_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0013a050 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [aw8693x_get_wav_loop, trig_show, cont_drv_time_show, cont_drv_time_show, ram_vbat_comp_show, aw869x_get_wav_loop, index_show, f0_save_show, ram_cali_show, rtp_show, lra_resistance_show, aw8671x_get_wav_loop, trig_show, aw8692x_get_wav_loop, cont_drv_time_show, cont_num_brk_show, aw8693x_get_reg, cont_drv_time_show, aw8693xs_get_wav_loop, state_show, haptic_audio_time_show, bullet_nr_show, activate_mode_show, aw869x_get_reg, rtp_auto_sin_show, trig_show, aw8671x_get_reg, strength_show, cont_brk_time_show, ram_f0_show, rtp_auto_sin_show, seq_show, trig_show, ram_update_show, ram_num_show, trig_show, cont_td_show, activate_show, cont_drv_time_show, cont_drv_lvl_show, cont_drv_lvl_show, gain_show, cont_drv_lvl_show, aw8692x_get_reg, aw869xx_get_reg, cont_drv_lvl_show, vmax_show, rtp_auto_sin_show, vbat_monitor_show, aw8693xs_get_reg, gun_type_show, duration_show, cali_show, prct_mode_show, osc_save_show, cont_drv_lvl_show, aw869xx_get_wav_loop, cont_brk_time_show, trig_show, f0_show, cont_brk_time_show, osc_cali_show, aw8672x_get_wav_loop, cont_brk_time_show, awrw_show, auto_boost_show, haptic_audio_show, cont_zc_thr_show, cont_drv_lvl_show, cont_brk_time_show, trig_show, aw8672x_get_reg, cont_drv_time_show, cont_brk_time_show, cont_drv_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0013a058 size=1
// signature: undefined kstrtouint(void)
// callers: [activate_mode_store, rtp_store, seq_store, gun_type_store, activate_store, gain_store, vmax_store, auto_boost_store, cont_td_store, index_store, ram_cali_store, ram_update_store, cont_zc_thr_store, osc_save_store, f0_save_store, rtp_auto_sin_store, cont_num_brk_store, cali_store, osc_cali_store, rtp_auto_sin_store, duration_store, ram_vbat_comp_store, bullet_nr_store, rtp_auto_sin_store, cont_store, strength_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0013a060 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [trig_store, trig_store, cont_drv_time_store, loop_store, cont_drv_lvl_store, cont_drv_time_store, haptic_audio_time_store, cont_drv_time_store, trig_store, trig_store, awrw_store, cont_drv_lvl_store, cont_drv_time_store, cont_drv_lvl_store, cont_drv_time_store, trig_store, cont_drv_time_store, trig_store, cont_drv_lvl_store, cont_drv_store, cont_drv_lvl_store, trig_store, haptic_audio_store, cont_drv_lvl_store, reg_store, prct_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0013a068 size=1
// signature: undefined of_find_property(void)
// callers: [aw8671x_parse_dt, aw8692x_parse_dt, aw869xx_parse_dt, aw8693x_parse_dt, aw8693xs_parse_dt, aw8672x_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0013a070 size=1
// signature: undefined devm_kmalloc(void)
// callers: [aw869xx_snd_soc_init, aw_i2c_probe, aw8693xs_snd_soc_init, aw8672x_snd_soc_init, aw8693x_snd_soc_init, aw8671x_snd_soc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0013a078 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [ram_load, aw869xx_snd_soc_init, aw8693xs_snd_soc_init, rtp_work_routine, awrw_store, rtp_osc_cali, haptic_hv_i2c_writes, aw8672x_snd_soc_init, aw8693x_snd_soc_init, aw8671x_snd_soc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 0013a080 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [aw869xx_snd_soc_init, aw8693xs_snd_soc_init, aw8672x_snd_soc_init, aw8693x_snd_soc_init, aw8671x_snd_soc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 0013a088 size=1
// signature: undefined kstrtou8(void)
// callers: [cont_brk_time_store, cont_brk_time_store, cont_brk_time_store, cont_brk_time_store, cont_brk_time_store, awrw_store, cont_brk_time_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 0013a090 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [aw869xx_hw_params, aw8693xs_hw_params, aw8693x_hw_params, aw8671x_hw_params, aw8672x_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0013a098 size=1
// signature: undefined queue_work_on(void)
// callers: [audio_timer_func, rtp_auto_sin_store, rtp_store, rtp_auto_sin_store, tiktap_unlocked_ioctl, brightness_set, vibrator_timer_func, activate_store, rtp_auto_sin_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 0013a0a0 size=1
// signature: undefined dev_set_name(void)
// callers: [aw8693x_snd_soc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 0013a0a8 size=1
// signature: undefined i2c_transfer(void)
// callers: [awrw_store, read_chipid, haptic_hv_i2c_reads, haptic_hv_i2c_write_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0013a0b0 size=1
// signature: undefined __kmalloc(void)
// callers: [ram_update_show, ram_load, awrw_store, haptic_hv_i2c_writes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer_buffer_flags @ 0013a0b8 size=1
// signature: undefined i2c_transfer_buffer_flags(void)
// callers: [sw_reset, awrw_store, haptic_hv_i2c_writes, reg_store, haptic_hv_i2c_write_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer_buffer_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0013a0c0 size=1
// signature: undefined kfree(void)
// callers: [ram_update_show, haptic_audio_store, ram_load, sw_reset, awrw_store, audio_off, haptic_hv_i2c_writes, reg_store, haptic_hv_i2c_write_bits, audio_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0013a0d0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [haptic_audio_store, sw_reset, reg_store, haptic_hv_i2c_write_bits]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 0013a0d8 size=1
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
// i2c_del_driver @ 0013a0e0 size=1
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
// devm_gpio_request_one @ 0013a0e8 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 0013a0f0 size=1
// signature: undefined gpio_to_desc(void)
// callers: [aw_i2c_probe, rtp_osc_cali, irq_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value_cansleep @ 0013a0f8 size=1
// signature: undefined gpiod_set_raw_value_cansleep(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value_cansleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 0013a100 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0013a108 size=1
// signature: undefined alloc_workqueue(void)
// callers: [aw_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_unregister @ 0013a110 size=1
// signature: undefined devm_led_classdev_unregister(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0013a118 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0013a120 size=1
// signature: undefined cancel_work_sync(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 0013a128 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [haptic_audio_store, vibrator_work_routine, rtp_work_routine, aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0013a130 size=1
// signature: undefined destroy_workqueue(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 0013a138 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 0013a148 size=1
// signature: undefined free_pages(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_remove @ 0013a150 size=1
// signature: undefined proc_remove(void)
// callers: [aw_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 0013a158 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [rtp_osc_cali, irq_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0013a160 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [irq_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0013a168 size=1
// signature: undefined _dev_info(void)
// callers: [irq_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create @ 0013a170 size=1
// signature: undefined proc_create(void)
// callers: [tiktap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_free_pages @ 0013a178 size=1
// signature: undefined __get_free_pages(void)
// callers: [tiktap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_register_ext @ 0013a180 size=1
// signature: undefined devm_led_classdev_register_ext(void)
// callers: [vibrator_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_register_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 0013a188 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [vibrator_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 0013a190 size=1
// signature: undefined hrtimer_init(void)
// callers: [haptic_init, vibrator_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0013a198 size=1
// signature: undefined __mutex_init(void)
// callers: [haptic_init, vibrator_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0013a1a8 size=1
// signature: undefined init_timer_key(void)
// callers: [ram_work_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0013a1b8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [ram_work_init, ram_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0013a1c0 size=1
// signature: undefined __const_udelay(void)
// callers: [tiktap_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_request_active @ 0013a1c8 size=1
// signature: undefined cpu_latency_qos_request_active(void)
// callers: [rtp_work_routine, tiktap_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_request_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_add_request @ 0013a1d0 size=1
// signature: undefined cpu_latency_qos_add_request(void)
// callers: [rtp_work_routine, tiktap_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_coarse_real_ts64 @ 0013a1d8 size=1
// signature: undefined ktime_get_coarse_real_ts64(void)
// callers: [tiktap_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_coarse_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// timespec64_to_jiffies @ 0013a1e0 size=1
// signature: undefined timespec64_to_jiffies(void)
// callers: [tiktap_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void timespec64_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 0013a1e8 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [tiktap_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_remove_request @ 0013a1f0 size=1
// signature: undefined cpu_latency_qos_remove_request(void)
// callers: [rtp_work_routine, tiktap_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0013a200 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [tiktap_unlocked_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vm_get_page_prot @ 0013a210 size=1
// signature: undefined vm_get_page_prot(void)
// callers: [tiktap_file_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vm_get_page_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remap_pfn_range @ 0013a228 size=1
// signature: undefined remap_pfn_range(void)
// callers: [tiktap_file_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 0013a230 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [audio_timer_func, haptic_audio_store, vibrator_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 0013a238 size=1
// signature: undefined request_firmware(void)
// callers: [rtp_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 0013a240 size=1
// signature: undefined vfree(void)
// callers: [rtp_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 0013a248 size=1
// signature: undefined vmalloc(void)
// callers: [rtp_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 0013a250 size=1
// signature: undefined release_firmware(void)
// callers: [ram_load, rtp_work_routine, rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 0013a258 size=1
// signature: undefined hrtimer_active(void)
// callers: [duration_show, haptic_audio_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __hrtimer_get_remaining @ 0013a260 size=1
// signature: undefined __hrtimer_get_remaining(void)
// callers: [duration_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __hrtimer_get_remaining(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware_nowait @ 0013a268 size=1
// signature: undefined request_firmware_nowait(void)
// callers: [ram_update_store, ram_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware_nowait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0013a270 size=1
// signature: undefined disable_irq(void)
// callers: [rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0013a278 size=1
// signature: undefined enable_irq(void)
// callers: [rtp_osc_cali]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0013a280 size=1
// signature: undefined __list_add_valid(void)
// callers: [haptic_audio_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0013a288 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [audio_off, audio_work_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0013a290 size=1
// signature: size_t strlen(char * __s)
// callers: [awrw_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



