// Decompiled by Ghidra 12.2
// Program: tz_log_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// tzdbg_procfs_open @ 0010039c size=40
// signature: undefined tzdbg_procfs_open(void)
// callers: []
//------------------------------------------------------------

void tzdbg_procfs_open(long param_1,undefined8 param_2)

{
  single_open(param_2,0,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// tzdbg_fs_read @ 001003c8 size=3756
// signature: undefined tzdbg_fs_read(void)
// callers: []
//------------------------------------------------------------

void tzdbg_fs_read(long param_1,undefined8 param_2,ulong param_3,undefined8 *param_4)

{
  uint uVar1;
  long *plVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  code *pcVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  undefined8 *puVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined8 uVar16;
  ulong uVar17;
  ulong uVar18;
  uint uVar19;
  ulong uVar20;
  uint uVar21;
  ushort uVar22;
  uint uVar23;
  undefined2 *puVar24;
  undefined4 *puVar25;
  long lVar26;
  uint local_6c;
  long local_68;
  
  lVar26 = sp_el0;
  local_68 = *(long *)(lVar26 + 0x638);
  if (*(long *)(param_1 + 0xd8) == 0) {
    _printk(&DAT_00103404,"tz_log_dlkm","tzdbg_fs_read",0x57e,"tzdbg_fs_read");
LAB_00100920:
    lVar26 = 0;
    goto LAB_00100fe0;
  }
  uVar4 = **(uint **)(*(long *)(param_1 + 0xd8) + 0x80);
  if ((DAT_00102cd8 != '\0') && (((uVar4 != 7 && uVar4 != 8) && uVar4 != 9) && uVar4 != 10)) {
    if (0xb < uVar4) goto LAB_00101270;
    if (uVar4 != 0xb) {
      lVar26 = (long)(int)uVar4 * 0x28;
      if ((lVar26 - 0x1d9U < 0xfffffffffffffdaf) || (uVar18 = lVar26 + 0x78, 0x250 < uVar18))
      goto LAB_00101268;
      puVar3 = (ulong *)(&DAT_00102b10 + lVar26);
      uVar20 = *puVar3;
      if (uVar20 == 0) {
        if (uVar4 != 6) {
          puVar13 = &enc_tzlog_info;
          uVar23 = uVar4;
        }
        else {
          puVar13 = &enc_qseelog_info;
          uVar23 = 6;
        }
        iVar11 = _disp_encrpted_log_stats(puVar13,uVar23,uVar4 == 6);
        if (0x250 < uVar18) goto LAB_00101268;
        uVar20 = (ulong)iVar11;
        *puVar3 = uVar20;
        if ((lVar26 - 0x1d1U < 0xfffffffffffffdaf) ||
           ((long)(int)uVar4 * 0x28 - 0x1d1U < 0xfffffffffffffdaf)) goto LAB_00101268;
        *(undefined8 *)(&DAT_00102b18 + (long)(int)uVar4 * 0x28) = 0;
      }
      *param_4 = 0;
      if (lVar26 - 0x1c1U < 0xfffffffffffffdaf) goto LAB_00101268;
      lVar26 = (long)(int)uVar4 * 0x28;
      uVar17 = param_3;
      if ((ulong)(long)(int)uVar20 <= param_3) {
        uVar17 = uVar20;
      }
      if ((lVar26 - 0x1c1U < 0xfffffffffffffdaf) ||
         ((long)(int)uVar4 * 0x28 - 0x1d1U < 0xfffffffffffffdaf)) goto LAB_00101268;
      plVar2 = (long *)(&DAT_00102b18 + lVar26);
      iVar11 = simple_read_from_buffer
                         (param_2,(long)(int)uVar17,param_4,
                          (&DAT_00102b28)[(long)(int)uVar4 * 5] + *plVar2,param_3);
      lVar26 = (long)iVar11;
      *plVar2 = lVar26 + *plVar2;
      if (0x250 < uVar18) goto LAB_00101268;
      *puVar3 = *puVar3 - lVar26;
      goto LAB_00100fe0;
    }
    _printk(&DAT_001031e7,"tz_log_dlkm","tzdbg_fs_read_encrypted",0x556,0xb);
    goto LAB_00100920;
  }
  if (uVar4 < 6) {
    puVar14 = DAT_00102ab8;
    uVar16 = tzdbg;
    uVar23 = debug_rw_buf_size;
LAB_001004dc:
    __memcpy_fromio(puVar14,uVar16,uVar23);
  }
  else if (uVar4 - 7 < 2) {
    puVar14 = DAT_00102ac0;
    uVar16 = DAT_00102aa0;
    uVar23 = DAT_00102cc8;
    goto LAB_001004dc;
  }
  puVar25 = DAT_00102ac0;
  puVar14 = DAT_00102ab8;
  uVar23 = (uint)param_3;
  switch(uVar4) {
  case 0:
    _printk(&DAT_00103254,"tz_log_dlkm","_disp_tz_boot_stats",0x232,DAT_00102cd4);
    if (DAT_00102ab8[2] == 0) {
      uVar21 = 0;
    }
    else {
      uVar19 = 0;
      uVar21 = 0;
      puVar25 = (undefined4 *)((long)DAT_00102ab8 + (ulong)(uint)DAT_00102ab8[4]);
      puVar14 = (undefined4 *)0x0;
      if (DAT_00102cd4 >> 0x17 == 0) {
        puVar25 = (undefined4 *)0x0;
        puVar14 = (undefined4 *)((long)DAT_00102ab8 + (ulong)(uint)DAT_00102ab8[4]);
      }
      do {
        if (DAT_00102cd4 < 0x800000) {
          iVar11 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                             "  CPU #: %d\n     Warmboot jump address     : 0x%x\n     Warmboot entry CPU counter: 0x%x\n     Warmboot exit CPU counter : 0x%x\n     Power Collapse entry CPU counter: 0x%x\n     Power Collapse exit CPU counter : 0x%x\n"
                             ,uVar19,puVar14[4],*puVar14,puVar14[1],puVar14[2],puVar14[3]);
          uVar21 = iVar11 + uVar21;
          if (debug_rw_buf_size - 1 < uVar21) {
            uVar16 = 0x268;
            goto LAB_00101214;
          }
          puVar14 = puVar14 + 6;
        }
        else {
          iVar11 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                             "  CPU #: %d\n     Warmboot jump address : 0x%llx\n     Warmboot entry CPU counter : 0x%x\n     Warmboot exit CPU counter : 0x%x\n     Power Collapse entry CPU counter : 0x%x\n     Power Collapse exit CPU counter : 0x%x\n     Psci entry CPU counter : 0x%x\n     Psci exit CPU counter : 0x%x\n     Warmboot Jump Address Instruction : 0x%x\n"
                             ,uVar19,*(undefined8 *)(puVar25 + 6),*puVar25,puVar25[1],puVar25[2],
                             puVar25[3],puVar25[4],puVar25[5],puVar25[8]);
          uVar21 = iVar11 + uVar21;
          if (debug_rw_buf_size - 1 < uVar21) {
            uVar16 = 0x253;
LAB_00101214:
            _printk(&DAT_00103278,"tz_log_dlkm","_disp_tz_boot_stats",uVar16,"_disp_tz_boot_stats");
            break;
          }
          puVar25 = puVar25 + 10;
        }
        uVar19 = uVar19 + 1;
      } while (uVar19 < (uint)DAT_00102ab8[2]);
    }
    DAT_00102b28 = DAT_00102ad8;
    break;
  case 1:
    if (DAT_00102ab8[2] == 0) {
      uVar21 = 0;
    }
    else {
      uVar19 = 0;
      uVar21 = 0;
      puVar14 = (undefined4 *)((long)DAT_00102ab8 + (ulong)(uint)DAT_00102ab8[5]);
      do {
        iVar11 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                           "  CPU #: %d\n     Reset Type (reason)       : 0x%x\n     Reset counter             : 0x%x\n"
                           ,uVar19,*puVar14,puVar14[1]);
        uVar21 = iVar11 + uVar21;
        if (debug_rw_buf_size - 1 < uVar21) {
          _printk(&DAT_00103278,"tz_log_dlkm","_disp_tz_reset_stats",0x285,"_disp_tz_reset_stats");
          break;
        }
        uVar19 = uVar19 + 1;
        puVar14 = puVar14 + 2;
      } while (uVar19 < (uint)DAT_00102ab8[2]);
    }
    DAT_00102b50 = DAT_00102ad8;
    break;
  case 2:
    lVar26 = (ulong)(uint)DAT_00102ab8[6] - 4;
    puVar24 = (undefined2 *)((long)DAT_00102ab8 + (ulong)(uint)DAT_00102ab8[6]);
    _printk(&DAT_00103254,"tz_log_dlkm","_disp_tz_interrupt_stats",0x29d,DAT_00102cd4);
    if (DAT_00102cd4._3_1_ == '\0') {
      if (*(int *)((long)puVar14 + lVar26) < 1) goto LAB_001011ec;
      iVar11 = 0;
      uVar21 = 0;
      do {
        iVar12 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                           "     Interrupt Number          : 0x%x\n     Type of Interrupt         : 0x%x\n     Description of interrupt  : %s\n"
                           ,*(undefined4 *)(puVar24 + 2),*puVar24,puVar24 + 4);
        uVar21 = iVar12 + uVar21;
        if (DAT_00102ab8[2] != 0) {
          uVar19 = 0;
          do {
            iVar12 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                               "     int_count on CPU # %d      : %u\n",uVar19,
                               *(undefined4 *)(puVar24 + (long)(int)uVar19 * 4 + 0xc));
            uVar21 = iVar12 + uVar21;
            uVar19 = uVar19 + 1;
          } while (uVar19 < (uint)DAT_00102ab8[2]);
        }
        iVar12 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size - 1,&DAT_00103aed);
        uVar21 = iVar12 + uVar21;
        if (debug_rw_buf_size - 1 < uVar21) {
          uVar16 = 0x2b6;
          goto LAB_00101244;
        }
        puVar24 = puVar24 + 0x2c;
        iVar11 = iVar11 + 1;
      } while (iVar11 < *(int *)((long)puVar14 + lVar26));
    }
    else {
      if (0 < *(int *)((long)puVar14 + lVar26)) {
        iVar11 = 0;
        uVar21 = 0;
LAB_001010ac:
        iVar12 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                           "     Interrupt Number          : 0x%x\n     Type of Interrupt         : 0x%x\n     Description of interrupt  : %s\n"
                           ,*(undefined4 *)(puVar24 + 2),*puVar24,puVar24 + 4);
        uVar21 = iVar12 + uVar21;
        if (DAT_00102ab8[2] != 0) {
          uVar19 = 0;
          do {
            iVar12 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                               "     int_count on CPU # %d      : %u\n",uVar19,
                               *(undefined4 *)(puVar24 + (long)(int)uVar19 * 2 + 0xc));
            uVar21 = iVar12 + uVar21;
            uVar19 = uVar19 + 1;
          } while (uVar19 < (uint)DAT_00102ab8[2]);
        }
        iVar12 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size - 1,&DAT_00103aed);
        uVar21 = iVar12 + uVar21;
        if (uVar21 <= debug_rw_buf_size - 1) goto code_r0x0010115c;
        uVar16 = 0x2d2;
LAB_00101244:
        _printk(&DAT_001036fd,"tz_log_dlkm","_disp_tz_interrupt_stats",uVar16,
                "_disp_tz_interrupt_stats");
        goto LAB_001011f0;
      }
LAB_001011ec:
      uVar21 = 0;
    }
LAB_001011f0:
    DAT_00102b78 = DAT_00102ad8;
    break;
  case 3:
    uVar19 = DAT_00102ab8[4] - DAT_00102ab8[3];
    if (uVar19 < 8) {
      uVar21 = 0;
    }
    else {
      uVar21 = 0;
      uVar19 = uVar19 >> 3;
      lVar26 = (long)DAT_00102ab8 + (ulong)(uint)DAT_00102ab8[3] + 1;
      do {
        if (*(char *)(lVar26 + -1) != -1) {
          iVar11 = scnprintf(DAT_00102ad8 + (int)uVar21,debug_rw_buf_size + ~uVar21,
                             "   0x%x        %s\n",*(char *)(lVar26 + -1),lVar26);
          uVar21 = iVar11 + uVar21;
        }
        if (debug_rw_buf_size - 1 < uVar21) {
          _printk(&DAT_00103278,"tz_log_dlkm","_disp_tz_vmid_stats",0x221,"_disp_tz_vmid_stats");
          break;
        }
        uVar19 = uVar19 - 1;
        lVar26 = lVar26 + 8;
      } while (uVar19 != 0);
    }
    DAT_00102ba0 = DAT_00102ad8;
    break;
  case 4:
    uVar21 = scnprintf(DAT_00102ad8,debug_rw_buf_size - 1,
                       "   Version        : 0x%x\n   Magic Number   : 0x%x\n   Number of CPU  : %d\n"
                       ,DAT_00102ab8[1],*DAT_00102ab8,DAT_00102ab8[2]);
    DAT_00102bc8 = DAT_00102ad8;
    goto LAB_00100bdc;
  case 5:
    if (0x2ffff < (uint)DAT_00102ab8[1]) {
      if (restore_from_hibernation != '\x01') {
        uVar15 = DAT_00102ab8[8];
        if (DAT_00102cd9 != '\0') {
          lVar26 = (long)DAT_00102ab8 + ((ulong)(uint)DAT_00102ab8[7] - 8);
          puVar13 = &_disp_tz_log_stats_log_start_v2;
          uVar16 = 5;
          goto LAB_00100bd4;
        }
        lVar26 = (long)DAT_00102ab8 + ((ulong)(uint)DAT_00102ab8[7] - 4);
        puVar14 = &_disp_tz_log_stats_log_start;
        uVar16 = 5;
        goto LAB_00100af0;
      }
      uVar21 = 0;
      _disp_tz_log_stats_log_start = 0;
      goto LAB_00100bd8;
    }
    uVar21 = scnprintf(DAT_00102ad8,debug_rw_buf_size - 1,&DAT_0010399e,
                       (long)DAT_00102ab8 + (ulong)(uint)DAT_00102ab8[7]);
    DAT_00102bf0 = DAT_00102ad8;
    goto LAB_00100bdc;
  case 6:
    if (DAT_00102cd9 == '\0') {
      puVar14 = &_disp_qsee_log_stats_log_start;
      uVar15 = 0x7ffc;
      uVar16 = 6;
      lVar26 = g_qsee_log;
LAB_00100af0:
      uVar21 = _disp_log_stats(lVar26,puVar14,uVar15,param_3,uVar16);
    }
    else if (restore_from_hibernation == '\x01') {
      uVar21 = 0;
      _disp_qsee_log_stats_log_start = 0;
    }
    else {
      puVar13 = &_disp_qsee_log_stats_log_start_v2;
      uVar15 = 0x1fff8;
      uVar16 = 6;
      lVar26 = g_qsee_log_v2;
LAB_00100bd4:
      uVar21 = _disp_log_stats_v2(lVar26,puVar13,uVar15,param_3,uVar16);
    }
    goto LAB_00100bd8;
  case 7:
    uVar21 = scnprintf(DAT_00102ad8,DAT_00102cc8 - 1,
                       "   Magic Number    : 0x%x\n   CPU Count       : 0x%x\n   S2 Fault Counter: 0x%x\n"
                       ,*DAT_00102ac0,DAT_00102ac0[1],DAT_00102ac0[5]);
    if (DAT_00102ac0[1] != 0) {
      uVar19 = 0;
      puVar14 = DAT_00102ac0 + 6;
      do {
        iVar11 = scnprintf(DAT_00102ad8 + (int)uVar21,DAT_00102cc8 + ~uVar21,
                           "  CPU #: %d\n     Warmboot entry CPU counter: 0x%x\n     Warmboot exit CPU counter : 0x%x\n"
                           ,uVar19,*puVar14,puVar14[1]);
        uVar21 = iVar11 + uVar21;
        if (DAT_00102cc8 - 1 < uVar21) {
          _printk(&DAT_00103278,"tz_log_dlkm","_disp_hyp_general_stats",0x4c5,
                  "_disp_hyp_general_stats");
          break;
        }
        uVar19 = uVar19 + 1;
        puVar14 = puVar14 + 2;
      } while (uVar19 < (uint)DAT_00102ac0[1]);
    }
    DAT_00102c40 = DAT_00102ad8;
    break;
  case 8:
    uVar22 = *(ushort *)(DAT_00102ac0 + 3);
    uVar19 = DAT_00102ac0[2];
    uVar5 = DAT_00102cc8 - uVar19;
    uVar21 = 2;
    if ((uint)_disp_hyp_log_stats_log_start_0 <= (uint)uVar22) {
      uVar21 = (uint)uVar22 - (uint)_disp_hyp_log_stats_log_start_0;
    }
    if (uVar21 < 2) {
      if (uVar21 == 1) {
        uVar22 = *(ushort *)((long)DAT_00102ac0 + 0xe);
        uVar21 = (uint)uVar22;
        uVar18 = (ulong)_disp_hyp_log_stats_log_start_1;
        if (_disp_hyp_log_stats_log_start_1 < uVar22) {
          uVar1 = 0;
          if (uVar5 != 0) {
            uVar1 = (uVar22 + 1) / uVar5;
          }
          uVar1 = (uVar22 + 1) - uVar1 * uVar5;
          uVar18 = (ulong)(uVar1 & 0xffff);
          _disp_hyp_log_stats_log_start_1 = (ushort)uVar1;
        }
      }
      else {
        uVar21 = (uint)*(ushort *)((long)DAT_00102ac0 + 0xe);
        uVar18 = (ulong)_disp_hyp_log_stats_log_start_1;
      }
    }
    else {
      uVar21 = (uint)*(ushort *)((long)DAT_00102ac0 + 0xe);
      _disp_hyp_log_stats_log_start_0 = uVar22 - 1;
      uVar1 = *(ushort *)((long)DAT_00102ac0 + 0xe) + 1;
      uVar6 = 0;
      if (uVar5 != 0) {
        uVar6 = uVar1 / uVar5;
      }
      uVar1 = uVar1 - uVar6 * uVar5;
      uVar18 = (ulong)(uVar1 & 0xffff);
      _disp_hyp_log_stats_log_start_1 = (ushort)uVar1;
    }
    if ((uint)uVar18 == uVar21) {
      do {
        lVar26 = msleep_interruptible(0x32);
        if (lVar26 != 0) goto LAB_00100f8c;
        __memcpy_fromio(DAT_00102ac0,DAT_00102aa0,DAT_00102cc8);
        uVar18 = (ulong)_disp_hyp_log_stats_log_start_1;
        uVar21 = (uint)*(ushort *)((long)puVar25 + 0xe);
      } while (_disp_hyp_log_stats_log_start_1 == uVar21);
    }
    lVar26 = 0;
    uVar20 = (ulong)DAT_00102cc8;
    if (param_3 <= DAT_00102cc8) {
      uVar20 = param_3;
    }
    if (((uint)uVar18 != uVar21) && (iVar11 = (int)uVar20, 0 < iVar11)) {
      lVar26 = 0;
      uVar21 = (uint)_disp_hyp_log_stats_log_start_1;
      uVar22 = _disp_hyp_log_stats_log_start_0;
      do {
        uVar1 = 0;
        if (uVar5 != 0) {
          uVar1 = (uVar21 + 1) / uVar5;
        }
        uVar1 = (uVar21 + 1) - uVar1 * uVar5;
        uVar21 = uVar1 & 0xffff;
        *(undefined1 *)(DAT_00102ad8 + lVar26) = *(undefined1 *)((long)puVar25 + uVar18 + uVar19);
        if (uVar21 == 0) {
          uVar22 = uVar22 + 1;
          _disp_hyp_log_stats_log_start_0 = uVar22;
        }
        lVar26 = lVar26 + 1;
        uVar18 = (ulong)uVar21;
        bVar9 = false;
        bVar10 = false;
        if (*(ushort *)((long)puVar25 + 0xe) != uVar21) {
          bVar10 = SBORROW4((int)lVar26,iVar11);
          bVar9 = (int)lVar26 - iVar11 < 0;
        }
      } while (bVar9 != bVar10);
      _disp_hyp_log_stats_log_start_1 = (ushort)uVar1;
    }
    uVar21 = (uint)lVar26;
    DAT_00102c68 = DAT_00102ad8;
    goto LAB_00100f90;
  case 9:
    if ((_disp_rm_log_stats_log_start_1 == 0) && (_disp_rm_log_stats_wrap_around == '\x01')) {
      uVar21 = 0;
      _disp_rm_log_stats_wrap_around = '\0';
    }
    else if (DAT_00102ccc == 0) {
      _printk(&DAT_00103ce7,"tz_log_dlkm","_disp_rm_log_stats",0x480,0);
LAB_00100f8c:
      uVar21 = 0;
    }
    else {
      if (_disp_rm_log_stats_wrap_around != '\x01') {
        __memcpy_fromio(DAT_00102ac8,DAT_00102aa8);
        _disp_rm_log_stats_log_start_0 = 0;
        _disp_rm_log_stats_log_start_1 = *(uint *)(DAT_00102ac8 + 4);
      }
      uVar18 = (ulong)_disp_rm_log_stats_log_start_1;
      if (param_3 <= _disp_rm_log_stats_log_start_1) {
        uVar18 = param_3;
      }
      uVar19 = (uint)uVar18;
      _disp_rm_log_stats_log_start_1 = _disp_rm_log_stats_log_start_1 - uVar19;
      uVar21 = _disp_rm_log_stats_log_start_0 + uVar19;
      if (_disp_rm_log_stats_log_start_1 != 0) {
        _disp_rm_log_stats_wrap_around = '\x01';
      }
      uVar20 = 0;
      uVar17 = (ulong)display_buf_size;
      if ((uVar19 != 0) && (display_buf_size != 0)) {
        lVar26 = DAT_00102ac8 + (ulong)_disp_rm_log_stats_log_start_0;
        uVar20 = 0;
        _disp_rm_log_stats_log_start_0 = uVar21;
        do {
          *(undefined1 *)(DAT_00102ad8 + uVar20) = *(undefined1 *)(lVar26 + 8 + uVar20);
          uVar20 = uVar20 + 1;
          uVar21 = _disp_rm_log_stats_log_start_0;
          if (uVar18 <= uVar20) break;
        } while (uVar20 < uVar17);
      }
      _disp_rm_log_stats_log_start_0 = uVar21;
      uVar21 = (uint)uVar20;
      if (uVar21 != uVar19) {
        _printk(&DAT_00103a1a,"tz_log_dlkm","__disp_rm_log_stats",0x3d5,uVar20 & 0xffffffff);
      }
      DAT_00102c90 = DAT_00102ad8;
    }
LAB_00100f90:
    *param_4 = 0;
    break;
  case 10:
    local_6c = 0;
    if (_disp_tme_log_stats_log_start_1 == 0) {
      if (_disp_tme_log_stats_wrap_around == '\0') goto LAB_00100b08;
      uVar21 = 0;
      _disp_tme_log_stats_wrap_around = '\0';
    }
    else {
      if (_disp_tme_log_stats_wrap_around == '\0') {
LAB_00100b08:
        iVar11 = tmelog_process_request(tmecrashdump_address_offset,0x5000,&local_6c);
        uVar18 = (ulong)local_6c;
        if (iVar11 != 0) {
          _printk(&DAT_00103bd9,"tz_log_dlkm","_disp_tme_log_stats",0x4e3,0);
          uVar21 = 0;
          goto LAB_00100bd8;
        }
        uVar20 = 0;
      }
      else {
        uVar20 = (ulong)_disp_tme_log_stats_log_start_0;
        uVar18 = _disp_tme_log_stats_log_start_1;
      }
      uVar21 = uVar23;
      if ((uint)uVar18 <= uVar23) {
        uVar21 = (uint)uVar18;
      }
      if (display_buf_size <= uVar21) {
        uVar21 = display_buf_size;
      }
      _disp_tme_log_stats_log_start_1 = uVar18 - uVar21;
      _disp_tme_log_stats_log_start_0 = uVar21 + (int)uVar20;
      if (_disp_tme_log_stats_log_start_1 != 0) {
        _disp_tme_log_stats_wrap_around = '\x01';
      }
      __memcpy_fromio(DAT_00102ad8,DAT_00102ab0 + uVar20,(ulong)uVar21);
      DAT_00102cb8 = DAT_00102ad8;
    }
LAB_00100bd8:
    *param_4 = 0;
LAB_00100bdc:
    if ((ulong)(long)(int)uVar21 <= param_3) {
      uVar23 = uVar21;
    }
    goto LAB_00100fa8;
  default:
    uVar21 = 0;
  }
  if ((ulong)(long)(int)uVar21 <= param_3) {
    uVar23 = uVar21;
  }
  if (10 < uVar4) {
LAB_00101270:
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x101274);
    (*pcVar8)();
  }
LAB_00100fa8:
  if (0x1c0 < (ulong)uVar4 * 0x28) {
LAB_00101268:
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(1,0x10126c);
    (*pcVar8)();
  }
  lVar26 = simple_read_from_buffer
                     (param_2,(long)(int)uVar23,param_4,(&DAT_00102b28)[(ulong)uVar4 * 5],
                      (long)(int)uVar23);
LAB_00100fe0:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar26);
  }
  return;
code_r0x0010115c:
  puVar24 = puVar24 + 0x1c;
  iVar11 = iVar11 + 1;
  if (*(int *)((long)puVar14 + lVar26) <= iVar11) goto LAB_001011f0;
  goto LAB_001010ac;
}



//------------------------------------------------------------
// tzdbg_procfs_release @ 00101278 size=28
// signature: undefined tzdbg_procfs_release(void)
// callers: []
//------------------------------------------------------------

void tzdbg_procfs_release(void)

{
  single_release();
  return;
}



//------------------------------------------------------------
// _disp_log_stats @ 00101294 size=428
// signature: undefined _disp_log_stats(void)
// callers: [tz_log_restore, tzdbg_fs_read]
//------------------------------------------------------------

long _disp_log_stats(ushort *param_1,ushort *param_2,uint param_3,ulong param_4,uint param_5)

{
  ulong uVar1;
  ushort uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  long lVar7;
  ulong uVar8;
  int iVar9;
  uint uVar10;
  
  uVar2 = *param_1;
  uVar10 = 2;
  if ((uint)*param_2 <= (uint)uVar2) {
    uVar10 = (uint)uVar2 - (uint)*param_2;
  }
  if (uVar10 < 2) {
    if (uVar10 != 1) {
      uVar8 = (ulong)param_2[1];
      goto LAB_00101328;
    }
    uVar2 = param_1[1];
    uVar8 = (ulong)param_2[1];
    if (uVar2 <= param_2[1]) goto LAB_00101328;
  }
  else {
    *param_2 = uVar2 - 1;
    uVar2 = param_1[1];
  }
  uVar10 = 0;
  if (param_3 != 0) {
    uVar10 = (uVar2 + 1) / param_3;
  }
  uVar10 = (uVar2 + 1) - uVar10 * param_3;
  uVar8 = (ulong)(uVar10 & 0xffff);
  param_2[1] = (ushort)uVar10;
LAB_00101328:
  uVar10 = (uint)param_1[1];
  if ((uint)uVar8 == (uint)param_1[1]) {
    do {
      lVar7 = msleep_interruptible(0x32);
      if (lVar7 != 0) {
        return 0;
      }
      if (param_5 == 5) {
        __memcpy_fromio(DAT_00102ab8,tzdbg,debug_rw_buf_size);
      }
      uVar8 = (ulong)param_2[1];
      uVar10 = (uint)param_1[1];
    } while (param_2[1] == uVar10);
  }
  lVar7 = 0;
  uVar1 = (ulong)debug_rw_buf_size;
  if (param_4 <= debug_rw_buf_size) {
    uVar1 = param_4;
  }
  if (((uint)uVar8 != uVar10) && (iVar9 = (int)uVar1, 0 < iVar9)) {
    lVar7 = 0;
    do {
      *(undefined1 *)(DAT_00102ad8 + lVar7) = *(undefined1 *)((long)param_1 + uVar8 + 4);
      uVar10 = 0;
      if (param_3 != 0) {
        uVar10 = (param_2[1] + 1) / param_3;
      }
      uVar3 = (param_2[1] + 1) - uVar10 * param_3;
      uVar10 = uVar3 & 0xffff;
      uVar8 = (ulong)uVar10;
      param_2[1] = (ushort)uVar3;
      if (uVar10 == 0) {
        *param_2 = *param_2 + 1;
      }
      lVar7 = lVar7 + 1;
      bVar5 = false;
      bVar6 = false;
      if (param_1[1] != uVar10) {
        bVar6 = SBORROW4((int)lVar7,iVar9);
        bVar5 = (int)lVar7 - iVar9 < 0;
      }
    } while (bVar5 != bVar6);
  }
  if (0x1c0 < ((ulong)param_5 + (ulong)param_5 * 4) * 8) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x101440);
    (*pcVar4)();
  }
  (&DAT_00102b28)[(ulong)param_5 * 5] = DAT_00102ad8;
  return lVar7;
}



//------------------------------------------------------------
// _disp_log_stats_v2 @ 00101440 size=420
// signature: undefined _disp_log_stats_v2(void)
// callers: [tzdbg_fs_read]
//------------------------------------------------------------

long _disp_log_stats_v2(uint *param_1,uint *param_2,uint param_3,ulong param_4,uint param_5)

{
  ulong uVar1;
  uint uVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  long lVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  
  uVar2 = *param_1;
  uVar9 = 2;
  if (*param_2 <= uVar2) {
    uVar9 = uVar2 - *param_2;
  }
  if (uVar9 < 2) {
    if (uVar9 != 1) {
      uVar7 = (ulong)param_2[1];
      goto LAB_001014d0;
    }
    uVar9 = param_1[1];
    uVar7 = (ulong)param_2[1];
    if (uVar9 <= param_2[1]) goto LAB_001014d0;
  }
  else {
    *param_2 = uVar2 - 1;
    uVar9 = param_1[1];
  }
  uVar2 = 0;
  if (param_3 != 0) {
    uVar2 = (uVar9 + 1) / param_3;
  }
  uVar9 = (uVar9 + 1) - uVar2 * param_3;
  uVar7 = (ulong)uVar9;
  param_2[1] = uVar9;
LAB_001014d0:
  uVar9 = param_1[1];
  if ((uint)uVar7 == uVar9) {
    do {
      lVar6 = msleep_interruptible(0x32);
      if (lVar6 != 0) {
        return 0;
      }
      if (param_5 == 5) {
        __memcpy_fromio(DAT_00102ab8,tzdbg,debug_rw_buf_size);
      }
      uVar7 = (ulong)param_2[1];
      uVar9 = param_1[1];
    } while (param_2[1] == uVar9);
  }
  lVar6 = 0;
  uVar1 = (ulong)debug_rw_buf_size;
  if (param_4 <= debug_rw_buf_size) {
    uVar1 = param_4;
  }
  if (((uint)uVar7 != uVar9) && (iVar8 = (int)uVar1, 0 < iVar8)) {
    lVar6 = 0;
    do {
      *(undefined1 *)(DAT_00102ad8 + lVar6) = *(undefined1 *)((long)param_1 + uVar7 + 8);
      uVar9 = 0;
      if (param_3 != 0) {
        uVar9 = (param_2[1] + 1) / param_3;
      }
      uVar9 = (param_2[1] + 1) - uVar9 * param_3;
      uVar7 = (ulong)uVar9;
      param_2[1] = uVar9;
      if (uVar9 == 0) {
        *param_2 = *param_2 + 1;
      }
      lVar6 = lVar6 + 1;
      bVar4 = false;
      bVar5 = false;
      if (uVar9 != param_1[1]) {
        bVar5 = SBORROW4((int)lVar6,iVar8);
        bVar4 = (int)lVar6 - iVar8 < 0;
      }
    } while (bVar4 != bVar5);
  }
  if (0x1c0 < ((ulong)param_5 + (ulong)param_5 * 4) * 8) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x1015e4);
    (*pcVar3)();
  }
  (&DAT_00102b28)[(ulong)param_5 * 5] = DAT_00102ad8;
  return lVar6;
}



//------------------------------------------------------------
// _disp_encrpted_log_stats @ 001015e4 size=580
// signature: undefined _disp_encrpted_log_stats(void)
// callers: [tzdbg_fs_read]
//------------------------------------------------------------

int _disp_encrpted_log_stats(undefined8 *param_1,uint param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  if ((DAT_00102cda == '\0') && (DAT_00102cdb != '\0')) {
    _printk(&DAT_001037fb,"tz_log_dlkm","_disp_encrpted_log_stats",0x3fc);
  }
  iVar4 = qcom_scm_request_encrypted_log
                    (*param_1,param_1[2],param_3,DAT_00102cda != '\0',DAT_00102cdb != '\0');
  if (iVar4 == 0) {
    puVar7 = (undefined4 *)param_1[1];
    pcVar1 = "QSEE Log";
    if (param_3 != 1) {
      pcVar1 = "TZ Dialog";
    }
    iVar2 = puVar7[2];
    uVar5 = scnprintf(DAT_00102ad8,display_buf_size + -1,"\n-------- New Encrypted %s --------\n",
                      pcVar1);
    iVar6 = scnprintf(DAT_00102ad8 + (int)uVar5,display_buf_size + ~uVar5,
                      "\nMagic_Num :\n0x%x\n\nVerion :\n%d\n\nEncr_Log_Buff_Size :\n%d\n\nWrap_Count :\n%d\n"
                      ,*puVar7,puVar7[1],puVar7[2],*(undefined2 *)(puVar7 + 3));
    iVar4 = print_text("\nKey : ",(long)puVar7 + 0xe,0x100,DAT_00102ad8 + (int)(iVar6 + uVar5),
                       display_buf_size);
    iVar4 = iVar4 + iVar6 + uVar5;
    iVar6 = print_text("\nNonce : ",(long)puVar7 + 0x10e,0xc,DAT_00102ad8 + iVar4,
                       display_buf_size - iVar4);
    iVar6 = iVar6 + iVar4;
    iVar4 = print_text("\nTag : ",(long)puVar7 + 0x11a,0x10,DAT_00102ad8 + iVar6,
                       display_buf_size - iVar6);
    uVar5 = iVar4 + iVar6;
    if ((uint)(display_buf_size - iVar2) < uVar5) {
      _printk(&DAT_00103454,"tz_log_dlkm","_disp_encrpted_log_stats",0x423);
    }
    iVar4 = print_text("\nLog : ",(long)puVar7 + 0x12a,iVar2,DAT_00102ad8 + (int)uVar5,
                       display_buf_size - uVar5);
    memset((void *)param_1[1],0,param_1[2]);
    if (10 < param_2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101824);
      (*pcVar3)();
    }
    if (0x1c0 < ((ulong)param_2 + (ulong)param_2 * 4) * 8) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x101828);
      (*pcVar3)();
    }
    iVar4 = iVar4 + uVar5;
    (&DAT_00102b28)[(ulong)param_2 * 5] = DAT_00102ad8;
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}



//------------------------------------------------------------
// print_text @ 00101828 size=304
// signature: undefined print_text(void)
// callers: [_disp_encrpted_log_stats]
//------------------------------------------------------------

uint print_text(undefined8 param_1,long param_2,uint param_3,long param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  
  iVar1 = scnprintf(param_4,param_5,&DAT_0010399e,param_1);
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      if (param_5 <= iVar1 + 6U) {
        _printk(&DAT_001034fc,"tz_log_dlkm","print_text",999,param_5,iVar1);
        return param_5;
      }
      iVar2 = scnprintf(param_4 + iVar1,param_5 - iVar1,"%02hhx ",*(undefined1 *)(param_2 + uVar3));
      iVar1 = iVar2 + iVar1;
      if ((~(uint)uVar3 & 0x1f) == 0) {
        iVar2 = scnprintf(param_4 + iVar1,param_5 - iVar1,&DAT_001033d8,10);
        iVar1 = iVar2 + iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (param_3 != uVar3);
  }
  iVar2 = scnprintf(param_4 + iVar1,param_5 - iVar1,&DAT_001033d8,10);
  return iVar2 + iVar1;
}



//------------------------------------------------------------
// tz_log_probe @ 0010195c size=2508
// signature: undefined tz_log_probe(void)
// callers: []
//------------------------------------------------------------

int tz_log_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined4 *puVar10;
  ulong local_88;
  uint local_7c;
  ulong local_78;
  uint local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_88 = 0;
  local_78 = 0;
  DAT_00102b30 = 1;
  DAT_00102b58 = 1;
  DAT_00102b80 = 1;
  DAT_00102ba8 = 1;
  DAT_00102bd0 = 1;
  DAT_00102bf8 = 1;
  DAT_00102c20 = 1;
  DAT_00102c48 = 1;
  DAT_00102c70 = 1;
  DAT_00102c98 = 1;
  DAT_00102cc0 = 1;
  iVar2 = qcom_scm_get_tz_log_feat_id(&local_78);
  if (iVar2 != 0) {
    _printk(&DAT_00103d70,"tz_log_dlkm","tzdbg_get_tz_version",0x6d8,"tzdbg_get_tz_version");
    goto LAB_00102268;
  }
  DAT_00102cd4 = (undefined4)local_78;
  iVar2 = qcom_scm_get_tz_feat_id_version(6,&local_78);
  if (iVar2 != 0) {
    _printk(&DAT_0010376a,"tz_log_dlkm","tzdbg_get_tz_version",0x6e0,"tzdbg_get_tz_version",iVar2);
    goto LAB_00102268;
  }
  _printk(&DAT_00103b57,"tz_log_dlkm","tzdbg_get_tz_version",0x6e3,local_78);
  DAT_00102ce0 = (uint)local_78 >> 0x16;
  DAT_00102cdc = (uint)local_78 >> 0xc & 0x3ff;
  DAT_00102cd9 = DAT_00102ce0 == 9 && DAT_00102cdc - 2 < 3;
  plVar3 = (long *)platform_get_resource(param_1,0x200,0);
  if (plVar3 == (long *)0x0) {
    _dev_err(param_1 + 0x10,"%s: ERROR Missing MEM resource\n","tz_log_probe");
  }
  else {
    lVar1 = param_1 + 0x10;
    uVar6 = (plVar3[1] - *plVar3) + 1;
    debug_rw_buf_size = (uint)uVar6;
    lVar4 = devm_ioremap(lVar1,*plVar3,uVar6 & 0xffffffff);
    if (lVar4 == 0) {
      _dev_err(lVar1,"%s: ERROR could not ioremap: start=%pr, len=%u\n","tz_log_probe",plVar3,
               debug_rw_buf_size);
    }
    else {
      if (*(long *)(param_1 + 0x2f8) != 0) {
        lVar5 = of_find_property(*(long *)(param_1 + 0x2f8),"qcom,hyplog-enabled",0);
        DAT_00102cd0 = lVar5 != 0;
        if (lVar5 != 0) {
          local_6c = 0;
          local_7c = 0;
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"hyplog-address-offset",&local_6c,1,0)
          ;
          if (iVar2 < 0) {
            pcVar8 = "hyplog address offset is not defined\n";
LAB_00101f74:
            _dev_err(lVar1,pcVar8);
            uVar9 = 0xffffffea;
LAB_00101f80:
            pcVar8 = "%s: fail to get hypdbg_base ret %d\n";
          }
          else {
            iVar2 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"hyplog-size-offset",&local_7c,1,0);
            if (iVar2 < 0) {
              pcVar8 = "hyplog size offset is not defined\n";
              goto LAB_00101f74;
            }
            uVar6 = readl_relaxed(lVar4 + (ulong)local_6c);
            local_78 = uVar6 & 0xffffffff;
            DAT_00102cc8 = readl_relaxed(lVar4 + (ulong)local_7c);
            DAT_00102aa0 = devm_ioremap(lVar1,uVar6 & 0xffffffff,DAT_00102cc8);
            if (DAT_00102aa0 == 0) {
              _dev_err(lVar1,"ERROR could not ioremap: start=%pr, len=%u\n",&local_78);
              uVar9 = 0xfffffffa;
              goto LAB_00101f80;
            }
            lVar5 = __kmalloc(DAT_00102cc8,0xdc0);
            if (lVar5 == 0) {
              uVar9 = 0xfffffff4;
              goto LAB_00101f80;
            }
            uVar9 = *(undefined8 *)(param_1 + 0x2f8);
            *(undefined4 *)(lVar5 + 0xc) = 0;
            local_78 = local_78 & 0xffffffff00000000;
            local_6c = 0;
            DAT_00102ac0 = lVar5;
            iVar2 = of_property_read_variable_u32_array(uVar9,"rmlog-address",&local_78,1,0);
            if (iVar2 < 0) {
              pcVar8 = "RM log address is not defined\n";
LAB_001022ac:
              _dev_err(lVar1,pcVar8);
              DAT_00102ccc = 0;
              goto LAB_00101c28;
            }
            iVar2 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"rmlog-size",&local_6c,1,0);
            if (iVar2 < 0) {
              pcVar8 = "RM log size is not defined\n";
              goto LAB_001022ac;
            }
            DAT_00102ccc = local_6c;
            if (local_6c == 0) {
              DAT_00102aa8 = 0;
              DAT_00102ac8 = 0;
              _dev_err(lVar1,"RM log size is %d\n");
              goto LAB_00101c28;
            }
            DAT_00102aa8 = devm_ioremap(lVar1,local_78 & 0xffffffff);
            if (DAT_00102aa8 == 0) {
              _dev_err(lVar1,"ERROR could not ioremap: start=%u, len=%u\n",local_78 & 0xffffffff,
                       DAT_00102ccc);
              uVar9 = 0xfffffffa;
            }
            else {
              lVar5 = __kmalloc(DAT_00102ccc,0xdc0);
              if (lVar5 != 0) {
                DAT_00102ac8 = lVar5;
                goto LAB_00101c28;
              }
              uVar9 = 0xfffffff4;
            }
            pcVar8 = "%s: fail to get rmlog_base ret %d\n";
          }
          _dev_err(lVar1,pcVar8,"tz_log_probe",uVar9);
          iVar2 = -0x16;
          goto LAB_00102268;
        }
        DAT_00102c70 = 0;
        DAT_00102c48 = 0;
        DAT_00102c98 = 0;
        _dev_info(lVar1,"Hyp log service not support\n");
      }
LAB_00101c28:
      uVar6 = readl_relaxed(lVar4);
      local_78 = 0;
      local_88 = uVar6 & 0xffffffff;
      iVar2 = qcom_scm_query_encrypted_log_feature(&local_78);
      if (iVar2 == 0) {
        _printk(&DAT_001034ba,"tz_log_dlkm","tzdbg_query_encrypted_log",0x705,local_78);
        DAT_00102cd8 = local_78 != 0;
        if (local_78 == 0) goto LAB_00101d30;
        if ((DAT_00102ce0 == 9) && (3 < (int)DAT_00102cdc)) {
          DAT_00102cda = 1;
        }
        if (*(long *)(param_1 + 0x2f8) != 0) {
          lVar4 = of_find_property(*(long *)(param_1 + 0x2f8),"qcom,full-encrypted-tz-logs-enabled",
                                   0);
          DAT_00102cdb = lVar4 != 0;
        }
      }
      else {
        if (iVar2 == -5) {
          _printk(&DAT_00103c95,"tz_log_dlkm","tzdbg_query_encrypted_log",0x700,0xfffffffb);
        }
        else {
          _printk(&DAT_00102ee8,"tz_log_dlkm","tzdbg_query_encrypted_log",0x702,iVar2);
        }
        DAT_00102cd8 = false;
LAB_00101d30:
        tzdbg = devm_ioremap(lVar1,uVar6 & 0xffffffff,debug_rw_buf_size);
        if (tzdbg == 0) {
          _dev_err(lVar1,"%s: could not ioremap: start=%pr, len=%u\n","tz_log_probe",&local_88);
          goto LAB_00102264;
        }
        lVar4 = __kmalloc(debug_rw_buf_size,0xdc0);
        if (lVar4 == 0) {
          iVar2 = -0xc;
          goto LAB_00102268;
        }
        DAT_00102ab8 = lVar4;
      }
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"tmecrashdump-address-offset",
                         &tmecrashdump_address_offset,1,0);
      if (iVar2 < 0) {
        _printk(&DAT_00103213,"tz_log_dlkm","tzdbg_init_tme_log",0x5ab);
LAB_00102024:
        DAT_00102cc0 = 0;
        _printk(&DAT_00103532,"tz_log_dlkm","tz_log_probe",0x77f);
      }
      else {
        DAT_00102ab0 = devm_ioremap(lVar1,tmecrashdump_address_offset,0x5000);
        if (DAT_00102ab0 == 0) {
          _printk(&DAT_00103561,"tz_log_dlkm","tzdbg_init_tme_log",0x5b3,tmecrashdump_address_offset
                  ,0x5000);
          goto LAB_00102024;
        }
      }
      iVar2 = tzdbg_register_qsee_log_buf(param_1);
      if (iVar2 == 0) {
        local_78 = CONCAT44(local_78._4_4_,3);
        local_6c = 6;
        if (DAT_00102cd8 == '\0') {
LAB_00101e78:
          if (qseelog_buf_size >> 0x1e == 0) {
            display_buf_size = (undefined4)((ulong)qseelog_buf_size << 2);
            DAT_00102ad8 = dma_alloc_attrs(lVar1,(ulong)qseelog_buf_size << 2,&disp_buf_paddr,0xcc0,
                                           0);
            if (DAT_00102ad8 != 0) {
              lVar4 = proc_mkdir("tzdbg",0);
              if (lVar4 != 0) {
                puVar10 = &DAT_00102ae0;
                lVar5 = 0;
                pcVar8 = &DAT_00102b30;
                do {
                  *puVar10 = (int)lVar5;
                  if ((*pcVar8 != '\0') &&
                     (lVar7 = proc_create_data(*(undefined8 *)(pcVar8 + -0x10),0x124,lVar4,
                                               &tzdbg_fops,puVar10), lVar7 == 0)) {
                    _dev_err(lVar1,"TZ proc_create_data failed\n");
                    remove_proc_entry("tzdbg",0);
                    goto LAB_001021b8;
                  }
                  lVar5 = lVar5 + 1;
                  pcVar8 = pcVar8 + 0x28;
                  puVar10 = puVar10 + 1;
                } while (lVar5 != 0xb);
                iVar2 = 0;
                *(long *)(param_1 + 0xa8) = lVar4;
                goto LAB_00102268;
              }
              _dev_err(lVar1,"tzdbg proc_mkdir failed\n");
LAB_001021b8:
              dma_free_attrs(lVar1,display_buf_size,DAT_00102ad8,disp_buf_paddr,0);
            }
            qtee_shmbridge_deregister(DAT_00103e40);
            dma_free_attrs(lVar1,DAT_00103e38,DAT_00103e30,enc_tzlog_info,0);
            qtee_shmbridge_deregister(DAT_00103e20);
            dma_free_attrs(lVar1,DAT_00103e18,DAT_00103e10,enc_qseelog_info,0);
          }
          else {
            _printk(&DAT_00103738,"tz_log_dlkm","tz_log_probe",0x792);
          }
        }
        else {
          DAT_00103e18 = (ulong)qseelog_buf_size + 0x1000;
          DAT_00103e10 = dma_alloc_attrs(lVar1,DAT_00103e18,&enc_qseelog_info,0xcc0,0);
          if (DAT_00103e10 != 0) {
            iVar2 = qtee_shmbridge_register
                              (enc_qseelog_info,DAT_00103e18,&local_78,&local_6c,1,6,&DAT_00103e20);
            if (iVar2 == 0) {
              DAT_00103e38 = (ulong)debug_rw_buf_size;
              DAT_00103e30 = dma_alloc_attrs(lVar1,DAT_00103e38,&enc_tzlog_info,0xcc0,0);
              if (DAT_00103e30 != 0) {
                iVar2 = qtee_shmbridge_register
                                  (enc_tzlog_info,DAT_00103e38,&local_78,&local_6c,1,6,&DAT_00103e40
                                  );
                if (iVar2 == 0) goto LAB_00101e78;
                _printk(&DAT_001039dc,"tz_log_dlkm","tzdbg_allocate_encrypted_log_buf",0x62a,iVar2);
                dma_free_attrs(lVar1,DAT_00103e38,DAT_00103e30,enc_tzlog_info,0);
              }
              qtee_shmbridge_deregister(DAT_00103e20);
            }
            else {
              _printk(&DAT_00103380,"tz_log_dlkm","tzdbg_allocate_encrypted_log_buf",0x619,iVar2);
            }
            dma_free_attrs(lVar1,DAT_00103e18,DAT_00103e10,enc_qseelog_info,0);
          }
          _dev_err(lVar1," %s: Failed to allocate encrypted log buffer\n","tz_log_probe");
        }
        if (DAT_00102cd8 == '\0') {
          qtee_shmbridge_deregister(qseelog_shmbridge_handle);
        }
        dma_free_attrs(lVar1,qseelog_buf_size,g_qsee_log,coh_pmem,0);
      }
      if (DAT_00102cd8 == '\0') {
        kfree(DAT_00102ab8);
      }
    }
  }
LAB_00102264:
  iVar2 = -6;
LAB_00102268:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// tz_log_remove @ 0010232c size=268
// signature: undefined tz_log_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 tz_log_remove(long param_1)

{
  if (*(long *)(param_1 + 0xa8) != 0) {
    remove_proc_entry("tzdbg",0);
  }
  param_1 = param_1 + 0x10;
  dma_free_attrs(param_1,display_buf_size,DAT_00102ad8,disp_buf_paddr,0);
  qtee_shmbridge_deregister(DAT_00103e40);
  dma_free_attrs(param_1,DAT_00103e38,DAT_00103e30,enc_tzlog_info,0);
  qtee_shmbridge_deregister(DAT_00103e20);
  dma_free_attrs(param_1,DAT_00103e18,DAT_00103e10,enc_qseelog_info,0);
  if (DAT_00102cd8 == '\0') {
    qtee_shmbridge_deregister(qseelog_shmbridge_handle);
  }
  dma_free_attrs(param_1,qseelog_buf_size,g_qsee_log,coh_pmem,0);
  if (DAT_00102cd8 == '\0') {
    kfree(DAT_00102ab8);
  }
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00102438 size=124
// signature: undefined readl_relaxed(void)
// callers: [tz_log_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102480,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// tzdbg_register_qsee_log_buf @ 001024b4 size=468
// signature: undefined tzdbg_register_qsee_log_buf(void)
// callers: [tz_log_restore, tz_log_probe]
//------------------------------------------------------------

int tzdbg_register_qsee_log_buf(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 6;
  uStack_4c = 3;
  if (DAT_00102cd9 == '\0') {
    qseelog_buf_size = 0x8000;
  }
  else {
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qseelog-buf-size-v2",&qseelog_buf_size,1,0)
    ;
    if (iVar3 < 0) {
      qseelog_buf_size = 0x20000;
    }
  }
  puVar4 = (undefined8 *)dma_alloc_attrs(param_1 + 0x10,qseelog_buf_size,&coh_pmem,0xcc0,0);
  if (puVar4 == (undefined8 *)0x0) {
    iVar3 = -0xc;
  }
  else {
    if ((DAT_00102cd8 == '\0') &&
       (iVar3 = qtee_shmbridge_register
                          (coh_pmem,qseelog_buf_size,&uStack_4c,&local_50,1,6,
                           &qseelog_shmbridge_handle), iVar3 != 0)) {
      _printk(&DAT_001037c2,"tz_log_dlkm","tzdbg_register_qsee_log_buf",0x5db);
    }
    else {
      uVar2 = qseelog_buf_size;
      g_qsee_log = puVar4;
      g_qsee_log_v2 = puVar4;
      *puVar4 = 0;
      iVar3 = qcom_scm_register_qsee_log_buf(coh_pmem,uVar2);
      if (iVar3 == 0) goto LAB_0010260c;
      _printk(&DAT_00102ffc,"tz_log_dlkm","tzdbg_register_qsee_log_buf",0x5ea,
              "tzdbg_register_qsee_log_buf",iVar3);
      if (DAT_00102cd8 == '\0') {
        qtee_shmbridge_deregister(qseelog_shmbridge_handle);
      }
    }
    dma_free_attrs(param_1 + 0x10,qseelog_buf_size,g_qsee_log,coh_pmem,0);
  }
LAB_0010260c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// tz_log_freeze @ 0010268c size=96
// signature: undefined tz_log_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 tz_log_freeze(undefined8 param_1)

{
  restore_from_hibernation = 1;
  if (g_qsee_log != 0) {
    dma_free_attrs(param_1,0x8000,g_qsee_log,coh_pmem,0);
  }
  if (DAT_00102cd8 == '\0') {
    qtee_shmbridge_deregister(qseelog_shmbridge_handle);
  }
  return 0;
}



//------------------------------------------------------------
// tz_log_restore @ 001026f0 size=132
// signature: undefined tz_log_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 tz_log_restore(long param_1)

{
  if (restore_from_hibernation == '\x01') {
    _disp_tz_log_stats_log_start = 0;
    if (DAT_00102cd9 == '\0') {
      _disp_log_stats(g_qsee_log,&_disp_qsee_log_stats_log_start,0x7ffc,0,6);
    }
    else {
      _disp_qsee_log_stats_log_start = 0;
    }
  }
  tzdbg_register_qsee_log_buf(param_1 + -0x10);
  restore_from_hibernation = 0;
  return 0;
}



//------------------------------------------------------------
// init_module @ 001029e4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&tz_log_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102a14 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&tz_log_driver);
  return;
}



//------------------------------------------------------------
// single_open @ 00105000 size=1
// signature: undefined single_open(void)
// callers: [tzdbg_procfs_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00105008 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [tzdbg_fs_read, _disp_log_stats_v2, _disp_log_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00105010 size=1
// signature: undefined scnprintf(void)
// callers: [_disp_encrpted_log_stats, print_text, tzdbg_fs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00105018 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [tzdbg_fs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105020 size=1
// signature: undefined _printk(void)
// callers: [_disp_encrpted_log_stats, tzdbg_register_qsee_log_buf, print_text, tz_log_probe, tzdbg_fs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tmelog_process_request @ 00105028 size=1
// signature: undefined tmelog_process_request(void)
// callers: [tzdbg_fs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tmelog_process_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep_interruptible @ 00105030 size=1
// signature: undefined msleep_interruptible(void)
// callers: [_disp_log_stats_v2, tzdbg_fs_read, _disp_log_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [tzdbg_register_qsee_log_buf, tz_log_probe, tzdbg_fs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_release @ 00105040 size=1
// signature: undefined single_release(void)
// callers: [tzdbg_procfs_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105048 size=1
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
// platform_driver_unregister @ 00105050 size=1
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
// qcom_scm_request_encrypted_log @ 00105058 size=1
// signature: undefined qcom_scm_request_encrypted_log(void)
// callers: [_disp_encrpted_log_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_request_encrypted_log(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00105060 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [_disp_encrpted_log_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_get_tz_log_feat_id @ 00105068 size=1
// signature: undefined qcom_scm_get_tz_log_feat_id(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_get_tz_log_feat_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_get_tz_feat_id_version @ 00105070 size=1
// signature: undefined qcom_scm_get_tz_feat_id_version(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_get_tz_feat_id_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00105078 size=1
// signature: undefined platform_get_resource(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105080 size=1
// signature: undefined _dev_err(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00105088 size=1
// signature: undefined devm_ioremap(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105090 size=1
// signature: undefined of_find_property(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105098 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [tzdbg_register_qsee_log_buf, tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001050a0 size=1
// signature: undefined _dev_info(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_query_encrypted_log_feature @ 001050a8 size=1
// signature: undefined qcom_scm_query_encrypted_log_feature(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_query_encrypted_log_feature(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001050b0 size=1
// signature: undefined __kmalloc(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 001050b8 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [tzdbg_register_qsee_log_buf, tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_register @ 001050c0 size=1
// signature: undefined qtee_shmbridge_register(void)
// callers: [tzdbg_register_qsee_log_buf, tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 001050c8 size=1
// signature: undefined proc_mkdir(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create_data @ 001050d0 size=1
// signature: undefined proc_create_data(void)
// callers: [tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 001050d8 size=1
// signature: undefined remove_proc_entry(void)
// callers: [tz_log_remove, tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001050e0 size=1
// signature: undefined dma_free_attrs(void)
// callers: [tzdbg_register_qsee_log_buf, tz_log_remove, tz_log_probe, tz_log_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_deregister @ 001050e8 size=1
// signature: undefined qtee_shmbridge_deregister(void)
// callers: [tzdbg_register_qsee_log_buf, tz_log_remove, tz_log_probe, tz_log_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050f0 size=1
// signature: undefined kfree(void)
// callers: [tz_log_remove, tz_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001050f8 size=1
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
// log_post_read_mmio @ 00105100 size=1
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
// qcom_scm_register_qsee_log_buf @ 00105108 size=1
// signature: undefined qcom_scm_register_qsee_log_buf(void)
// callers: [tzdbg_register_qsee_log_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_register_qsee_log_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



