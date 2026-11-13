// Decompiled by Ghidra 12.2
// Program: sysmon_subsystem_stats.ko
// Image base: 00100000

//------------------------------------------------------------
// sysmon_stats_query_hmx_utlization @ 001004e4 size=196
// signature: undefined sysmon_stats_query_hmx_utlization(void)
// callers: []
//------------------------------------------------------------

ulong sysmon_stats_query_hmx_utlization(int *param_1)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  
  if (DAT_00102e6b == '\0') {
    sysmon_smem_init_cdsp();
  }
  uVar2 = 0xffffff82;
  if ((DAT_00102f08 != (int *)0x0) && (DAT_00102f08 < (int *)0xfffffffffffff001)) {
    InstructionSynchronizationBarrier();
    uVar2 = cntvct_el0;
    iVar1 = 0;
    if (uVar2 - *(ulong *)(DAT_00102f08 + 1) < 0x1d9700 || uVar2 <= *(ulong *)(DAT_00102f08 + 1)) {
      iVar1 = *DAT_00102f08;
    }
    iVar3 = iVar1;
    if (iVar1 == 0xffff) {
      _printk(&DAT_00103048,"sysmon_subsystem_stats");
      iVar3 = 0;
    }
    *param_1 = iVar3;
    uVar2 = (ulong)(iVar1 == 0xffff);
  }
  return uVar2;
}



//------------------------------------------------------------
// sysmon_smem_init_cdsp @ 001005a8 size=684
// signature: undefined sysmon_smem_init_cdsp(void)
// callers: [master_cdsp_stats_show, sysmon_stats_query_hmx_utlization, sysmon_stats_query_q6_votes, sysmon_stats_query_hvx_utlization, sysmon_stats_query_power_residency, sysmon_stats_query_q6_load, sysmon_stats_query_sleep]
//------------------------------------------------------------

void sysmon_smem_init_cdsp(void)

{
  long lVar1;
  ulong uVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  DAT_00102e69 = 1;
  DAT_00102e6b = 1;
  DAT_00102ee8 = qcom_smem_get(5,0x270,&local_30);
  if (((DAT_00102ee8 == 0) || (0xfffffffffffff000 < DAT_00102ee8)) || (local_30 < 0x34)) {
    _printk(&DAT_00103263,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e69 = 0;
  }
  DAT_00102ea8 = qcom_smem_get(5,0x25f,&local_30);
  if (((DAT_00102ea8 == 0) || (0xfffffffffffff000 < DAT_00102ea8)) || (local_30 < 0x20)) {
    _printk(&DAT_0010394b,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e69 = 0;
  }
  uVar2 = qcom_smem_get(5,0x27a,&local_30);
  if (((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) || (local_30 == 0)) {
    _printk(&DAT_00103907,"sysmon_subsystem_stats","sysmon_smem_init_cdsp",uVar2);
    DAT_00102e69 = 0;
  }
  update_sysmon_smem_pointers(uVar2,5,local_30);
  if ((DAT_00102e90 == 0) || (0xfffffffffffff000 < DAT_00102e90)) {
    _printk(&DAT_00103617,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e69 = 0;
  }
  if ((DAT_00102e78 == 0) || (0xfffffffffffff000 < DAT_00102e78)) {
    _printk(&DAT_00103308,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e69 = 0;
  }
  if ((DAT_00102ed0 == 0) || (0xfffffffffffff000 < DAT_00102ed0)) {
    _printk(&DAT_0010367c,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e69 = 0;
  }
  if ((DAT_00102f08 == 0) || (0xfffffffffffff000 < DAT_00102f08)) {
    _printk(&DAT_00103881,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e6b = 0;
  }
  if ((DAT_00102f10 == 0) || (0xfffffffffffff000 < DAT_00102f10)) {
    _printk(&DAT_00103881,"sysmon_subsystem_stats","sysmon_smem_init_cdsp");
    DAT_00102e6b = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sysmon_stats_query_hvx_utlization @ 00100858 size=196
// signature: undefined sysmon_stats_query_hvx_utlization(void)
// callers: []
//------------------------------------------------------------

ulong sysmon_stats_query_hvx_utlization(int *param_1)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  
  if (DAT_00102e6b == '\0') {
    sysmon_smem_init_cdsp();
  }
  uVar2 = 0xffffff82;
  if ((DAT_00102f10 != (int *)0x0) && (DAT_00102f10 < (int *)0xfffffffffffff001)) {
    InstructionSynchronizationBarrier();
    uVar2 = cntvct_el0;
    iVar1 = 0;
    if (uVar2 - *(ulong *)(DAT_00102f10 + 1) < 0x1d9700 || uVar2 <= *(ulong *)(DAT_00102f10 + 1)) {
      iVar1 = *DAT_00102f10;
    }
    iVar3 = iVar1;
    if (iVar1 == 0xffff) {
      _printk(&DAT_00103a95,"sysmon_subsystem_stats");
      iVar3 = 0;
    }
    *param_1 = iVar3;
    uVar2 = (ulong)(iVar1 == 0xffff);
  }
  return uVar2;
}



//------------------------------------------------------------
// copy_powerstats @ 00100920 size=332
// signature: undefined copy_powerstats(void)
// callers: []
//------------------------------------------------------------

undefined8 copy_powerstats(uint *param_1,uint param_2)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined8 *puVar3;
  byte *pbVar4;
  long lVar5;
  
  if (param_2 == 2) {
    puVar3 = &DAT_00102e70;
  }
  else if (param_2 == 5) {
    puVar3 = &DAT_00102e78;
  }
  else {
    if (param_2 != 3) {
      _printk(&DAT_00102f6d,"sysmon_subsystem_stats","copy_powerstats");
      return 1;
    }
    puVar3 = &DAT_00102e80;
  }
  pbVar4 = (byte *)*puVar3;
  *param_1 = (uint)*pbVar4;
  bVar2 = *pbVar4;
  param_1[0x41] = *(uint *)(pbVar4 + 0x84);
  param_1[0x42] = *(uint *)(pbVar4 + 0x88);
  if (1 < bVar2) {
    param_1[99] = *(uint *)(pbVar4 + 0xcc);
  }
  lVar5 = 0;
  do {
    *(undefined4 *)((long)param_1 + lVar5 + 4) = *(undefined4 *)(pbVar4 + lVar5 + 4);
    *(undefined4 *)((long)param_1 + lVar5 + 0x84) = *(undefined4 *)(pbVar4 + lVar5 + 0x44);
    if ((param_2 & 0xfffffffe) == 2 && 1 < bVar2) {
      *(undefined4 *)((long)param_1 + lVar5 + 0x10c) = *(undefined4 *)(pbVar4 + lVar5 + 0x8c);
    }
    lVar5 = lVar5 + 4;
  } while (lVar5 != 0x40);
  if (3 < bVar2) {
    lVar5 = 0;
    do {
      puVar1 = (undefined4 *)((long)param_1 + lVar5 + 0xc4);
      puVar1[-0x20] = *(undefined4 *)(pbVar4 + lVar5 + 0x168);
      *puVar1 = *(undefined4 *)(pbVar4 + lVar5 + 0x1a8);
      if (param_2 == 2) {
        puVar1[0x22] = *(undefined4 *)(pbVar4 + lVar5 + 0x1e8);
      }
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x40);
  }
  return 0;
}



//------------------------------------------------------------
// sysmon_stats_query_power_residency @ 00100a70 size=1868
// signature: undefined sysmon_stats_query_power_residency(void)
// callers: [master_cdsp_stats_show, master_adsp_stats_show]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sysmon_stats_query_power_residency(uint param_1,uint *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  byte bVar4;
  ulong uVar5;
  uint *puVar6;
  code *pcVar7;
  undefined8 uVar8;
  long lVar9;
  undefined *puVar10;
  char *pcVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  uint *puVar15;
  ulong uVar16;
  ulong uVar17;
  uint local_1e8;
  uint local_1e4 [32];
  uint local_164 [32];
  uint local_e4;
  uint local_e0;
  int local_dc [32];
  uint local_5c;
  long local_58;
  
  lVar13 = sp_el0;
  local_58 = *(long *)(lVar13 + 0x638);
  memset(&local_1e8,0,400);
  if (param_2 == (uint *)0x0) {
    _printk(&DAT_0010322c,"sysmon_subsystem_stats","sysmon_stats_query_power_residency");
    uVar8 = 0xffffffea;
    goto LAB_0010115c;
  }
  if (param_1 == 5) {
    if (DAT_00102e69 == '\0') {
      sysmon_smem_init_cdsp();
    }
    puVar15 = DAT_00102e78;
    uVar8 = 0xffffff82;
    if ((DAT_00102e78 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < DAT_00102e78))
    goto LAB_0010115c;
    local_e4 = DAT_00102e78[0x21];
    local_e0 = DAT_00102e78[0x22];
    local_1e8 = (uint)(byte)*DAT_00102e78;
    if (1 < local_1e8) {
      local_5c = DAT_00102e78[0x33];
    }
    local_1e4[0] = DAT_00102e78[1];
    local_164[0] = DAT_00102e78[0x11];
    local_1e4[1] = DAT_00102e78[2];
    local_164[1] = DAT_00102e78[0x12];
    local_1e4[2] = DAT_00102e78[3];
    local_164[2] = DAT_00102e78[0x13];
    local_1e4[3] = DAT_00102e78[4];
    local_164[3] = DAT_00102e78[0x14];
    local_1e4[4] = DAT_00102e78[5];
    local_164[4] = DAT_00102e78[0x15];
    local_1e4[5] = DAT_00102e78[6];
    local_164[5] = DAT_00102e78[0x16];
    local_1e4[6] = DAT_00102e78[7];
    local_164[6] = DAT_00102e78[0x17];
    local_1e4[7] = DAT_00102e78[8];
    local_164[7] = DAT_00102e78[0x18];
    local_1e4[8] = DAT_00102e78[9];
    local_164[8] = DAT_00102e78[0x19];
    local_1e4[9] = DAT_00102e78[10];
    local_164[9] = DAT_00102e78[0x1a];
    local_1e4[10] = DAT_00102e78[0xb];
    local_164[10] = DAT_00102e78[0x1b];
    local_1e4[0xb] = DAT_00102e78[0xc];
    local_164[0xb] = DAT_00102e78[0x1c];
    local_1e4[0xc] = DAT_00102e78[0xd];
    local_164[0xc] = DAT_00102e78[0x1d];
    local_1e4[0xd] = DAT_00102e78[0xe];
    local_164[0xd] = DAT_00102e78[0x1e];
    local_1e4[0xe] = DAT_00102e78[0xf];
    local_164[0xe] = DAT_00102e78[0x1f];
    local_1e4[0xf] = DAT_00102e78[0x10];
    local_164[0xf] = DAT_00102e78[0x20];
    if (3 < (byte)*DAT_00102e78) {
      lVar13 = 0;
      do {
        puVar1 = (undefined4 *)((long)DAT_00102e78 + lVar13 + 0x1a8);
        lVar9 = lVar13 + 4;
        *(undefined4 *)((long)local_1e4 + lVar13 + 0x40) = puVar1[-0x10];
        *(undefined4 *)((long)local_164 + lVar13 + 0x40) = *puVar1;
        lVar13 = lVar9;
      } while (lVar9 != 0x40);
    }
    if (DAT_00102ea8 == 0) {
      uVar16 = 0;
    }
    else {
      uVar16 = *(ulong *)(DAT_00102ea8 + 0x18);
      if (*(ulong *)(DAT_00102ea8 + 0x10) < *(ulong *)(DAT_00102ea8 + 8)) {
        if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x100d2c);
          (*pcVar7)();
        }
        lVar13 = (*_arch_timer_read_counter)(0xffffff82);
        uVar17 = 0;
        uVar16 = (lVar13 + uVar16) - *(long *)(DAT_00102ea8 + 8);
        goto LAB_00100fd8;
      }
    }
LAB_00100fd4:
    uVar17 = 0;
LAB_00100fd8:
    puVar6 = DAT_00102e70;
    if ((((param_1 != 2) && (puVar6 = DAT_00102e80, param_1 != 3)) &&
        (puVar6 = DAT_00102e78, param_1 != 5)) || (puVar6 == (uint *)0x0)) {
      uVar8 = 0xffffffea;
      goto LAB_0010115c;
    }
    if ((*puVar15 & 0xfe) != 0) {
      uVar12 = *(ulong *)(puVar6 + 0x34);
      InstructionSynchronizationBarrier();
      uVar5 = cntvct_el0;
      uVar14 = -uVar12;
      if (uVar5 < uVar12) {
        uVar14 = ~uVar12;
      }
      if (19199999 < uVar14 + uVar5) {
        lVar13 = 0;
        uVar12 = 0;
        if ((ulong)local_e4 <= uVar16 / 19200000) {
          uVar12 = (ulong)local_e4;
        }
        uVar14 = (uVar14 + uVar5) / 19200000;
        uVar12 = uVar16 / 19200000 - uVar12;
        iVar2 = 0;
        if (uVar12 <= uVar14) {
          iVar2 = (int)uVar14 - (int)uVar12;
        }
        if (19199999 < uVar17) {
          uVar16 = 0;
          if ((ulong)local_e0 <= uVar17 / 19200000) {
            uVar16 = (ulong)local_e0;
          }
          lVar13 = uVar17 / 19200000 - uVar16;
        }
        lVar9 = 0;
        lVar3 = lVar13;
        if (uVar12 <= lVar13 - 1U) {
          lVar3 = 0;
        }
        do {
          if (*(uint *)((long)local_1e4 + lVar9) == local_5c) {
            *(int *)((long)local_164 + lVar9) = *(int *)((long)local_164 + lVar9) + iVar2;
            *(int *)((long)local_dc + lVar9) = *(int *)((long)local_dc + lVar9) + (int)lVar13;
            local_e4 = local_e4 + ((int)uVar12 - (int)lVar3);
            local_e0 = local_e0 + (int)lVar13;
            goto LAB_00101140;
          }
          lVar9 = lVar9 + 4;
        } while (lVar9 != 0x80);
        puVar10 = &DAT_001030c2;
        pcVar11 = "add_delta_time";
        param_1 = local_5c;
        goto LAB_001011ac;
      }
    }
LAB_00101140:
    memcpy(param_2,&local_1e8,400);
    uVar8 = 0;
    *param_2 = (uint)(byte)*puVar15;
  }
  else {
    if (param_1 == 3) {
      if (DAT_00102e6a == '\0') {
        sysmon_smem_init_slpi();
      }
      puVar15 = DAT_00102e80;
      uVar8 = 0xffffff82;
      if ((DAT_00102e80 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < DAT_00102e80))
      goto LAB_0010115c;
      local_e4 = DAT_00102e80[0x21];
      bVar4 = (byte)*DAT_00102e80;
      local_e0 = DAT_00102e80[0x22];
      local_1e8 = (uint)bVar4;
      if (1 < local_1e8) {
        local_5c = DAT_00102e80[0x33];
      }
      lVar13 = 0;
      do {
        *(undefined4 *)((long)local_1e4 + lVar13) = *(undefined4 *)((long)DAT_00102e80 + lVar13 + 4)
        ;
        *(undefined4 *)((long)local_164 + lVar13) =
             *(undefined4 *)((long)DAT_00102e80 + lVar13 + 0x44);
        if (1 < bVar4) {
          *(undefined4 *)((long)local_dc + lVar13) =
               *(undefined4 *)((long)DAT_00102e80 + lVar13 + 0x8c);
        }
        lVar13 = lVar13 + 4;
      } while (lVar13 != 0x40);
      if (3 < bVar4) {
        lVar13 = 0;
        do {
          puVar1 = (undefined4 *)((long)DAT_00102e80 + lVar13 + 0x1a8);
          lVar9 = lVar13 + 4;
          *(undefined4 *)((long)local_1e4 + lVar13 + 0x40) = puVar1[-0x10];
          *(undefined4 *)((long)local_164 + lVar13 + 0x40) = *puVar1;
          lVar13 = lVar9;
        } while (lVar9 != 0x40);
      }
      if (DAT_00102eb0 == 0) {
        uVar16 = 0;
      }
      else {
        uVar16 = *(ulong *)(DAT_00102eb0 + 0x18);
        if (*(ulong *)(DAT_00102eb0 + 0x10) < *(ulong *)(DAT_00102eb0 + 8)) {
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x100eec);
            (*pcVar7)();
          }
          lVar13 = (*_arch_timer_read_counter)(0xffffff82);
          uVar16 = (lVar13 + uVar16) - *(long *)(DAT_00102eb0 + 8);
        }
      }
      if (DAT_00102ec0 == 0) goto LAB_00100fd4;
      uVar17 = *(ulong *)(DAT_00102ec0 + 0x18);
      if (*(ulong *)(DAT_00102ec0 + 0x10) < *(ulong *)(DAT_00102ec0 + 8)) {
        if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x100fbc);
          (*pcVar7)();
        }
        lVar9 = (*_arch_timer_read_counter)();
        lVar13 = DAT_00102ec0;
LAB_00100fc4:
        uVar17 = (lVar9 + uVar17) - *(long *)(lVar13 + 8);
      }
      goto LAB_00100fd8;
    }
    if (param_1 == 2) {
      if (g_sysmon_stats == '\0') {
        sysmon_smem_init_adsp();
      }
      puVar15 = DAT_00102e70;
      uVar8 = 0xffffff82;
      if ((DAT_00102e70 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < DAT_00102e70))
      goto LAB_0010115c;
      local_e4 = DAT_00102e70[0x21];
      bVar4 = (byte)*DAT_00102e70;
      local_e0 = DAT_00102e70[0x22];
      local_1e8 = (uint)bVar4;
      if (1 < local_1e8) {
        local_5c = DAT_00102e70[0x33];
      }
      lVar13 = 0;
      do {
        *(undefined4 *)((long)local_1e4 + lVar13) = *(undefined4 *)((long)DAT_00102e70 + lVar13 + 4)
        ;
        *(undefined4 *)((long)local_164 + lVar13) =
             *(undefined4 *)((long)DAT_00102e70 + lVar13 + 0x44);
        if (1 < bVar4) {
          *(undefined4 *)((long)local_dc + lVar13) =
               *(undefined4 *)((long)DAT_00102e70 + lVar13 + 0x8c);
        }
        lVar13 = lVar13 + 4;
      } while (lVar13 != 0x40);
      if (3 < bVar4) {
        lVar13 = 0;
        do {
          puVar1 = (undefined4 *)((long)DAT_00102e70 + lVar13 + 0x1e8);
          lVar9 = lVar13 + 4;
          *(undefined4 *)((long)local_1e4 + lVar13 + 0x40) = puVar1[-0x20];
          *(undefined4 *)((long)local_164 + lVar13 + 0x40) = puVar1[-0x10];
          *(undefined4 *)((long)local_dc + lVar13 + 0x40) = *puVar1;
          lVar13 = lVar9;
        } while (lVar9 != 0x40);
      }
      if (DAT_00102ea0 == 0) {
        uVar16 = 0;
      }
      else {
        uVar16 = *(ulong *)(DAT_00102ea0 + 0x18);
        if (*(ulong *)(DAT_00102ea0 + 0x10) < *(ulong *)(DAT_00102ea0 + 8)) {
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x100e5c);
            (*pcVar7)();
          }
          lVar13 = (*_arch_timer_read_counter)(0xffffff82);
          uVar16 = (lVar13 + uVar16) - *(long *)(DAT_00102ea0 + 8);
        }
      }
      if (DAT_00102eb8 != 0) {
        uVar17 = *(ulong *)(DAT_00102eb8 + 0x18);
        if (*(ulong *)(DAT_00102eb8 + 0x10) < *(ulong *)(DAT_00102eb8 + 8)) {
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x100f70);
            (*pcVar7)();
          }
          lVar9 = (*_arch_timer_read_counter)();
          lVar13 = DAT_00102eb8;
          goto LAB_00100fc4;
        }
        goto LAB_00100fd8;
      }
      goto LAB_00100fd4;
    }
    puVar10 = &DAT_001034ff;
    pcVar11 = "sysmon_stats_query_power_residency";
LAB_001011ac:
    _printk(puVar10,"sysmon_subsystem_stats",pcVar11,param_1);
    uVar8 = 0xffffffea;
  }
LAB_0010115c:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// sysmon_smem_init_adsp @ 001011bc size=652
// signature: undefined sysmon_smem_init_adsp(void)
// callers: [sysmon_stats_query_q6_votes, master_adsp_stats_show, sysmon_stats_query_power_residency, sysmon_stats_query_q6_load, sysmon_stats_query_sleep]
//------------------------------------------------------------

void sysmon_smem_init_adsp(void)

{
  long lVar1;
  ulong uVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  g_sysmon_stats = 1;
  DAT_00102ee0 = qcom_smem_get(2,0x270,&local_30);
  if (((DAT_00102ee0 == 0) || (0xfffffffffffff000 < DAT_00102ee0)) || (local_30 < 0x34)) {
    _printk(&DAT_00103428,"sysmon_subsystem_stats","sysmon_smem_init_adsp");
    g_sysmon_stats = 0;
  }
  DAT_00102ea0 = qcom_smem_get(2,0x25e,&local_30);
  if (((DAT_00102ea0 == 0) || (0xfffffffffffff000 < DAT_00102ea0)) || (local_30 < 0x20)) {
    _printk(&DAT_001039ca,"sysmon_subsystem_stats","sysmon_smem_init_adsp");
    g_sysmon_stats = 0;
  }
  DAT_00102eb8 = qcom_smem_get(2,0x265,&local_30);
  if (((DAT_00102eb8 == 0) || (0xfffffffffffff000 < DAT_00102eb8)) || (local_30 < 0x20)) {
    _printk(&DAT_001037b4,"sysmon_subsystem_stats","sysmon_smem_init_adsp");
    g_sysmon_stats = 0;
  }
  uVar2 = qcom_smem_get(2,0x27a,&local_30);
  if (((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) || (local_30 == 0)) {
    _printk(&DAT_001036be,"sysmon_subsystem_stats","sysmon_smem_init_adsp",uVar2);
    g_sysmon_stats = 0;
  }
  update_sysmon_smem_pointers(uVar2,2,local_30);
  if ((DAT_00102e88 == 0) || (0xfffffffffffff000 < DAT_00102e88)) {
    _printk(&DAT_0010313a,"sysmon_subsystem_stats","sysmon_smem_init_adsp");
    g_sysmon_stats = 0;
  }
  if ((DAT_00102e70 == 0) || (0xfffffffffffff000 < DAT_00102e70)) {
    _printk(&DAT_0010338d,"sysmon_subsystem_stats","sysmon_smem_init_adsp");
    g_sysmon_stats = 0;
  }
  if ((DAT_00102ec8 == 0) || (0xfffffffffffff000 < DAT_00102ec8)) {
    _printk(&DAT_00102faa,"sysmon_subsystem_stats","sysmon_smem_init_adsp");
    g_sysmon_stats = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sysmon_smem_init_slpi @ 00101448 size=552
// signature: undefined sysmon_smem_init_slpi(void)
// callers: [sysmon_stats_query_q6_votes, sysmon_stats_query_power_residency, sysmon_stats_query_q6_load, sysmon_stats_query_sleep]
//------------------------------------------------------------

void sysmon_smem_init_slpi(void)

{
  long lVar1;
  ulong uVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  DAT_00102e6a = 1;
  DAT_00102eb0 = qcom_smem_get(3,0x260,&local_30);
  if (((DAT_00102eb0 == 0) || (0xfffffffffffff000 < DAT_00102eb0)) || (local_30 < 0x20)) {
    _printk(&DAT_00103473,"sysmon_subsystem_stats","sysmon_smem_init_slpi");
    DAT_00102e6a = 0;
  }
  DAT_00102ec0 = qcom_smem_get(3,0x265,&local_30);
  if (((DAT_00102ec0 == 0) || (0xfffffffffffff000 < DAT_00102ec0)) || (local_30 < 0x20)) {
    _printk(&DAT_0010354b,"sysmon_subsystem_stats","sysmon_smem_init_slpi");
    DAT_00102e6a = 0;
  }
  uVar2 = qcom_smem_get(3,0x27a,&local_30);
  if (((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) || (local_30 == 0)) {
    _printk(&DAT_00103af8,"sysmon_subsystem_stats","sysmon_smem_init_slpi",uVar2);
  }
  update_sysmon_smem_pointers(uVar2,3,local_30);
  if ((DAT_00102e98 == 0) || (0xfffffffffffff000 < DAT_00102e98)) {
    _printk(&DAT_00103081,"sysmon_subsystem_stats","sysmon_smem_init_slpi");
    DAT_00102e6a = 0;
  }
  if ((DAT_00102e80 == 0) || (0xfffffffffffff000 < DAT_00102e80)) {
    _printk(&DAT_001034bd,"sysmon_subsystem_stats","sysmon_smem_init_slpi");
    DAT_00102e6a = 0;
  }
  if ((DAT_00102ed8 == 0) || (0xfffffffffffff000 < DAT_00102ed8)) {
    _printk(&DAT_001033cf,"sysmon_subsystem_stats","sysmon_smem_init_slpi");
    DAT_00102e6a = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sysmon_stats_query_q6_votes @ 00101674 size=268
// signature: undefined sysmon_stats_query_q6_votes(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_stats_query_q6_votes(int param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (param_2 == (undefined8 *)0x0) {
    _printk(&DAT_0010322c,"sysmon_subsystem_stats","sysmon_stats_query_q6_votes");
LAB_00101778:
    uVar3 = 0xffffffea;
  }
  else {
    if (param_1 == 5) {
      puVar2 = DAT_00102e90;
      if (DAT_00102e69 == '\0') {
        sysmon_smem_init_cdsp();
        puVar2 = DAT_00102e90;
      }
    }
    else if (param_1 == 3) {
      puVar2 = DAT_00102e98;
      if (DAT_00102e6a == '\0') {
        sysmon_smem_init_slpi();
        puVar2 = DAT_00102e98;
      }
    }
    else {
      if (param_1 != 2) {
        _printk(&DAT_001034ff,"sysmon_subsystem_stats","sysmon_stats_query_q6_votes");
        goto LAB_00101778;
      }
      puVar2 = DAT_00102e88;
      if (g_sysmon_stats == '\0') {
        sysmon_smem_init_adsp();
        puVar2 = DAT_00102e88;
      }
    }
    uVar3 = 0xffffff82;
    if ((puVar2 != (undefined8 *)0x0) &&
       (uVar3 = 0xffffff82, puVar2 < (undefined8 *)0xfffffffffffff001)) {
      uVar1 = puVar2[2];
      uVar3 = 0;
      uVar4 = *puVar2;
      param_2[1] = puVar2[1];
      param_2[2] = uVar1;
      *param_2 = uVar4;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// sysmon_read_q6_load @ 00101784 size=172
// signature: undefined sysmon_read_q6_load(void)
// callers: []
//------------------------------------------------------------

undefined4 sysmon_read_q6_load(int param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined4 *puVar3;
  
  InstructionSynchronizationBarrier();
  uVar2 = cntvct_el0;
  if (param_1 == 5) {
    puVar3 = DAT_00102ed0;
  }
  else if (param_1 == 3) {
    puVar3 = DAT_00102ed8;
  }
  else {
    if (param_1 != 2) {
      _printk(&DAT_001034ff,"sysmon_subsystem_stats","sysmon_read_q6_load");
      return 0xffffffea;
    }
    puVar3 = DAT_00102ec8;
  }
  uVar1 = 0;
  if (uVar2 - *(ulong *)(puVar3 + 1) < 0x1d9700 || uVar2 <= *(ulong *)(puVar3 + 1)) {
    uVar1 = *puVar3;
  }
  return uVar1;
}



//------------------------------------------------------------
// sysmon_stats_query_q6_load @ 00101834 size=376
// signature: undefined sysmon_stats_query_q6_load(void)
// callers: []
//------------------------------------------------------------

undefined8 sysmon_stats_query_q6_load(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  ulong uVar4;
  
  if (param_2 == (undefined4 *)0x0) {
    _printk(&DAT_0010322c,"sysmon_subsystem_stats","sysmon_stats_query_q6_load");
LAB_001019a4:
    uVar2 = 0xffffffea;
  }
  else {
    if (param_1 == 5) {
      if (DAT_00102e69 == '\0') {
        sysmon_smem_init_cdsp();
      }
      if (DAT_00102ed0 == (undefined4 *)0x0) {
        return 0xffffff82;
      }
      if ((undefined4 *)0xfffffffffffff000 < DAT_00102ed0) {
        return 0xffffff82;
      }
      InstructionSynchronizationBarrier();
      uVar4 = cntvct_el0;
      puVar3 = DAT_00102ed0;
    }
    else if (param_1 == 3) {
      if (DAT_00102e6a == '\0') {
        sysmon_smem_init_slpi();
      }
      if (DAT_00102ed8 == (undefined4 *)0x0) {
        return 0xffffff82;
      }
      if ((undefined4 *)0xfffffffffffff000 < DAT_00102ed8) {
        return 0xffffff82;
      }
      InstructionSynchronizationBarrier();
      uVar4 = cntvct_el0;
      puVar3 = DAT_00102ed8;
    }
    else {
      if (param_1 != 2) {
        _printk(&DAT_001034ff,"sysmon_subsystem_stats","sysmon_stats_query_q6_load");
        goto LAB_001019a4;
      }
      if (g_sysmon_stats == '\0') {
        sysmon_smem_init_adsp();
      }
      if (DAT_00102ec8 == (undefined4 *)0x0) {
        return 0xffffff82;
      }
      if ((undefined4 *)0xfffffffffffff000 < DAT_00102ec8) {
        return 0xffffff82;
      }
      InstructionSynchronizationBarrier();
      uVar4 = cntvct_el0;
      puVar3 = DAT_00102ec8;
    }
    uVar2 = 0;
    uVar1 = 0;
    if (uVar4 - *(ulong *)(puVar3 + 1) < 0x1d9700 || uVar4 <= *(ulong *)(puVar3 + 1)) {
      uVar1 = *puVar3;
    }
    *param_2 = uVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// sysmon_stats_query_sleep @ 001019b0 size=860
// signature: undefined sysmon_stats_query_sleep(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sysmon_stats_query_sleep(int param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  if (param_2 == (undefined8 *)0x0 && param_3 == (undefined8 *)0x0) {
    _printk(&DAT_0010322c,"sysmon_subsystem_stats","sysmon_stats_query_sleep");
    return 0xffffffea;
  }
  if (param_1 == 5) {
    if (DAT_00102e69 == '\0') {
      sysmon_smem_init_cdsp();
    }
    if (param_2 == (undefined8 *)0x0) {
      return 0;
    }
    if (DAT_00102ea8 == (undefined8 *)0x0) {
      return 0xffffff82;
    }
    if ((undefined8 *)0xfffffffffffff000 < DAT_00102ea8) {
      return 0xffffff82;
    }
    if ((ulong)DAT_00102ea8[2] < (ulong)DAT_00102ea8[1]) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101ad4);
        (*pcVar4)();
      }
      lVar5 = (*_arch_timer_read_counter)(0xffffff82);
      DAT_00102ea8[3] = (lVar5 - DAT_00102ea8[1]) + DAT_00102ea8[3];
    }
    uVar1 = DAT_00102ea8[3];
    uVar7 = *DAT_00102ea8;
    uVar2 = DAT_00102ea8[1];
    param_2[2] = DAT_00102ea8[2];
    param_2[3] = uVar1;
    *param_2 = uVar7;
    param_2[1] = uVar2;
    return 0;
  }
  if (param_1 != 3) {
    if (param_1 != 2) {
      _printk(&DAT_001034ff,"sysmon_subsystem_stats","sysmon_stats_query_sleep");
      return 0xffffffea;
    }
    if (g_sysmon_stats == '\0') {
      sysmon_smem_init_adsp();
      if (param_2 == (undefined8 *)0x0) goto LAB_00101ba4;
LAB_00101a00:
      uVar7 = 0xffffff82;
      if ((DAT_00102ea0 != (undefined8 *)0x0) && (DAT_00102ea0 < (undefined8 *)0xfffffffffffff001))
      {
        if ((ulong)DAT_00102ea0[2] < (ulong)DAT_00102ea0[1]) {
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101a44);
            (*pcVar4)();
          }
          lVar5 = (*_arch_timer_read_counter)();
          DAT_00102ea0[3] = (lVar5 - DAT_00102ea0[1]) + DAT_00102ea0[3];
        }
        uVar2 = DAT_00102ea0[3];
        uVar7 = 0;
        uVar1 = *DAT_00102ea0;
        uVar3 = DAT_00102ea0[1];
        param_2[2] = DAT_00102ea0[2];
        param_2[3] = uVar2;
        *param_2 = uVar1;
        param_2[1] = uVar3;
      }
    }
    else {
      if (param_2 != (undefined8 *)0x0) goto LAB_00101a00;
LAB_00101ba4:
      uVar7 = 0;
    }
    if (param_3 == (undefined8 *)0x0) {
      return uVar7;
    }
    if (DAT_00102eb8 == (undefined8 *)0x0) {
      return 0xffffff82;
    }
    if ((undefined8 *)0xfffffffffffff000 < DAT_00102eb8) {
      return 0xffffff82;
    }
    puVar6 = DAT_00102eb8;
    if ((ulong)DAT_00102eb8[2] < (ulong)DAT_00102eb8[1]) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101bf0);
        (*pcVar4)();
      }
      lVar5 = (*_arch_timer_read_counter)(0xffffff82);
      DAT_00102eb8[3] = (lVar5 - DAT_00102eb8[1]) + DAT_00102eb8[3];
      puVar6 = DAT_00102eb8;
    }
    goto LAB_00101c98;
  }
  if (DAT_00102e6a == '\0') {
    sysmon_smem_init_slpi();
    if (param_2 == (undefined8 *)0x0) goto LAB_00101c2c;
LAB_00101b1c:
    uVar7 = 0xffffff82;
    puVar6 = DAT_00102ec0;
    if ((DAT_00102eb0 != (undefined8 *)0x0) && (DAT_00102eb0 < (undefined8 *)0xfffffffffffff001)) {
      if ((ulong)DAT_00102eb0[2] < (ulong)DAT_00102eb0[1]) {
        if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101b60);
          (*pcVar4)();
        }
        lVar5 = (*_arch_timer_read_counter)();
        DAT_00102eb0[3] = (lVar5 - DAT_00102eb0[1]) + DAT_00102eb0[3];
      }
      uVar2 = DAT_00102eb0[3];
      uVar7 = 0;
      uVar1 = *DAT_00102eb0;
      uVar3 = DAT_00102eb0[1];
      param_2[2] = DAT_00102eb0[2];
      param_2[3] = uVar2;
      *param_2 = uVar1;
      param_2[1] = uVar3;
      puVar6 = DAT_00102ec0;
    }
  }
  else {
    if (param_2 != (undefined8 *)0x0) goto LAB_00101b1c;
LAB_00101c2c:
    uVar7 = 0;
    puVar6 = DAT_00102ec0;
  }
  if (param_3 == (undefined8 *)0x0) {
    DAT_00102ec0 = puVar6;
    return uVar7;
  }
  if (puVar6 == (undefined8 *)0x0) {
    DAT_00102ec0 = puVar6;
    return 0xffffff82;
  }
  if ((undefined8 *)0xfffffffffffff000 < puVar6) {
    DAT_00102ec0 = puVar6;
    return 0xffffff82;
  }
  DAT_00102ec0 = puVar6;
  if ((ulong)puVar6[2] < (ulong)puVar6[1]) {
    if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101c78);
      (*pcVar4)();
    }
    lVar5 = (*_arch_timer_read_counter)(0xffffff82);
    DAT_00102ec0[3] = (lVar5 - DAT_00102ec0[1]) + DAT_00102ec0[3];
    puVar6 = DAT_00102ec0;
  }
LAB_00101c98:
  uVar2 = puVar6[3];
  uVar1 = *puVar6;
  uVar3 = puVar6[1];
  param_3[2] = puVar6[2];
  param_3[3] = uVar2;
  *param_3 = uVar1;
  param_3[1] = uVar3;
  return uVar7;
}



//------------------------------------------------------------
// update_sysmon_smem_pointers @ 00101d0c size=840
// signature: undefined update_sysmon_smem_pointers(void)
// callers: [sysmon_smem_init_slpi, sysmon_smem_init_cdsp, sysmon_smem_init_adsp]
//------------------------------------------------------------

void update_sysmon_smem_pointers(uint *param_1,int param_2,ulong param_3)

{
  uint *puVar1;
  uint uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  if (param_3 != 0) {
    uVar2 = *param_1;
    uVar5 = (ulong)(uVar2 >> 0x10) & 0xfff;
    if (uVar5 <= param_3) {
      do {
        puVar3 = &DAT_0010320b;
        switch(uVar2 >> 0x1c) {
        case 1:
          puVar1 = param_1 + 1;
          if ((puVar1 == (uint *)0x0) ||
             ((uint *)0xffffffffffffefff < puVar1 && param_1 != (uint *)0xffffffffffffeffc)) {
LAB_00102034:
            _printk(&DAT_0010375c,"sysmon_subsystem_stats","update_sysmon_smem_pointers");
            return;
          }
          if (param_2 == 5) {
            DAT_00102ed0 = puVar1;
          }
          else if (param_2 == 3) {
            DAT_00102ed8 = puVar1;
          }
          else if (param_2 == 2) {
            DAT_00102ec8 = puVar1;
          }
          else {
            uVar4 = 1;
LAB_00101fb4:
            _printk(puVar3,"sysmon_subsystem_stats","update_sysmon_smem_pointers",uVar4);
          }
          break;
        case 2:
          puVar1 = param_1 + 1;
          if ((puVar1 == (uint *)0x0) ||
             ((uint *)0xffffffffffffefff < puVar1 && param_1 != (uint *)0xffffffffffffeffc))
          goto LAB_00102034;
          if (param_2 == 5) {
            DAT_00102e90 = puVar1;
          }
          else if (param_2 == 3) {
            DAT_00102e98 = puVar1;
          }
          else {
            if (param_2 != 2) {
              uVar4 = 2;
              goto LAB_00101fb4;
            }
            DAT_00102e88 = puVar1;
          }
          break;
        case 3:
          if ((param_1 == (uint *)0xfffffffffffffffc) ||
             ((uint *)0xffffffffffffefff < param_1 + 1 && param_1 != (uint *)0xffffffffffffeffc))
          goto LAB_00102034;
          if (param_2 == 5) {
            DAT_00102e78 = param_1;
          }
          else if (param_2 == 3) {
            DAT_00102e80 = param_1;
          }
          else {
            if (param_2 != 2) {
              puVar3 = &DAT_0010336b;
              uVar4 = 3;
              goto LAB_00101fb4;
            }
            DAT_00102e70 = param_1;
          }
          break;
        case 4:
          puVar1 = param_1 + 1;
          if ((puVar1 == (uint *)0x0) ||
             ((uint *)0xffffffffffffefff < puVar1 && param_1 != (uint *)0xffffffffffffeffc))
          goto LAB_00102034;
          if (param_2 == 5) {
            DAT_00102f08 = puVar1;
          }
          else {
            uVar4 = 4;
LAB_00101f38:
            _printk(&DAT_001031e6,"sysmon_subsystem_stats","update_sysmon_smem_pointers",uVar4);
          }
          break;
        case 5:
          puVar1 = param_1 + 1;
          if ((puVar1 == (uint *)0x0) ||
             ((uint *)0xffffffffffffefff < puVar1 && param_1 != (uint *)0xffffffffffffeffc))
          goto LAB_00102034;
          if (param_2 != 5) {
            uVar4 = 5;
            goto LAB_00101f38;
          }
          DAT_00102f10 = puVar1;
          break;
        default:
          _printk(&DAT_00103a62,"sysmon_subsystem_stats","update_sysmon_smem_pointers");
        }
        param_1 = (uint *)((long)param_1 + uVar5);
        if (param_1 == (uint *)0x0) {
          return;
        }
        if ((uint *)0xfffffffffffff000 < param_1) {
          return;
        }
        if (param_3 <= uVar5) {
          return;
        }
        param_3 = param_3 - uVar5;
        if (param_3 == 0) {
          return;
        }
        uVar2 = *param_1;
        uVar5 = (ulong)(uVar2 >> 0x10) & 0xfff;
        if (param_3 < uVar5) {
          return;
        }
      } while( true );
    }
  }
  return;
}



//------------------------------------------------------------
// master_adsp_stats_open @ 00102058 size=48
// signature: undefined master_adsp_stats_open(void)
// callers: []
//------------------------------------------------------------

void master_adsp_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,master_adsp_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// master_adsp_stats_show @ 0010208c size=1124
// signature: undefined master_adsp_stats_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 master_adsp_stats_show(undefined8 param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  ulong uVar7;
  undefined1 auStack_1d8 [4];
  int local_1d4 [32];
  undefined4 local_154 [32];
  undefined4 local_d4;
  int local_d0;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  memset(auStack_1d8,0,400);
  if (g_sysmon_stats == '\0') {
    sysmon_smem_init_adsp();
  }
  if (DAT_00102e88 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nsysMon stats:\n\n");
    seq_printf(param_1,"Core clock(KHz): %d\n",*DAT_00102e88);
    seq_printf(param_1,"Ab vote(Bytes): %llu\n",*(undefined8 *)(DAT_00102e88 + 1));
    seq_printf(param_1,"Ib vote(Bytes): %llu\n",*(undefined8 *)(DAT_00102e88 + 3));
    iVar3 = DAT_00102e88[5];
    if (iVar3 == 0) {
      iVar3 = -1;
    }
    seq_printf(param_1,"Sleep latency(usec): %u\n",iVar3);
  }
  if (DAT_00102ee0 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nDSPPM stats:\n\n");
    seq_printf(param_1,"Version: %u\n",*DAT_00102ee0);
    iVar3 = DAT_00102ee0[1];
    if (iVar3 == 0) {
      iVar3 = -1;
    }
    seq_printf(param_1,"Sleep latency(usec): %u\n",iVar3);
    seq_printf(param_1,"Timestamp: %llu\n",DAT_00102ee0[2]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee0[3],DAT_00102ee0[4]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee0[5],DAT_00102ee0[6]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee0[7],DAT_00102ee0[8]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee0[9],DAT_00102ee0[10]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee0[0xb],DAT_00102ee0[0xc]);
  }
  if (DAT_00102ea0 != 0) {
    lVar6 = *(long *)(DAT_00102ea0 + 0x18);
    if (*(ulong *)(DAT_00102ea0 + 0x10) < *(ulong *)(DAT_00102ea0 + 8)) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102270);
        (*pcVar2)();
      }
      lVar4 = (*_arch_timer_read_counter)();
      lVar6 = (lVar4 + lVar6) - *(long *)(DAT_00102ea0 + 8);
    }
    seq_puts(param_1,"\nLPM stats:\n\n");
    seq_printf(param_1,"Count = %u\n",*(undefined4 *)(DAT_00102ea0 + 4));
    seq_printf(param_1,"Last Entered At = %llu\n",*(undefined8 *)(DAT_00102ea0 + 8));
    seq_printf(param_1,"Last Exited At = %llu\n",*(undefined8 *)(DAT_00102ea0 + 0x10));
    seq_printf(param_1,"Accumulated Duration = %llu\n",lVar6);
  }
  if (DAT_00102eb8 != 0) {
    lVar6 = *(long *)(DAT_00102eb8 + 0x18);
    if (*(ulong *)(DAT_00102eb8 + 0x10) < *(ulong *)(DAT_00102eb8 + 8)) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10232c);
        (*pcVar2)();
      }
      lVar4 = (*_arch_timer_read_counter)();
      lVar6 = (lVar4 + lVar6) - *(long *)(DAT_00102eb8 + 8);
    }
    seq_puts(param_1,"\nLPI stats:\n\n");
    seq_printf(param_1,"Count = %u\n",*(undefined4 *)(DAT_00102eb8 + 4));
    seq_printf(param_1,"Last Entered At = %llu\n",*(undefined8 *)(DAT_00102eb8 + 8));
    seq_printf(param_1,"Last Exited At = %llu\n",*(undefined8 *)(DAT_00102eb8 + 0x10));
    seq_printf(param_1,"Accumulated Duration = %llu\n",lVar6);
  }
  if (DAT_00102e70 != 0) {
    iVar3 = sysmon_stats_query_power_residency(2,auStack_1d8);
    if (iVar3 == 0) {
      seq_puts(param_1,"\nPower Stats:\n\n");
      uVar7 = 0;
      do {
        if (local_1d4[uVar7] != 0) {
          seq_printf(param_1,"%u : Core Clock(KHz): %u \tActive Time(sec): %u\n",uVar7 & 0xffffffff,
                     local_1d4[uVar7],local_154[uVar7]);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != 0x20);
      seq_printf(param_1,"Power collapse time(sec) = %u\n",local_d4);
      pcVar5 = "Total LPI time(sec) = %u\n";
    }
    else {
      pcVar5 = "\nPower Stats Read failed : %d\n";
      local_d0 = iVar3;
    }
    seq_printf(param_1,pcVar5,local_d0);
  }
  if (DAT_00102ec8 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nQ6 load:\n\n");
    InstructionSynchronizationBarrier();
    uVar7 = cntvct_el0;
    uVar1 = 0;
    if (uVar7 - *(ulong *)(DAT_00102ec8 + 1) < 0x1d9700 || uVar7 <= *(ulong *)(DAT_00102ec8 + 1)) {
      uVar1 = *DAT_00102ec8;
    }
    seq_printf(param_1,"Average Q6 load in KCPS = %u\n",uVar1);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// master_cdsp_stats_open @ 001024f4 size=48
// signature: undefined master_cdsp_stats_open(void)
// callers: []
//------------------------------------------------------------

void master_cdsp_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,master_cdsp_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// master_cdsp_stats_show @ 00102528 size=1284
// signature: undefined master_cdsp_stats_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 master_cdsp_stats_show(undefined8 param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  ulong uVar7;
  undefined1 auStack_1d8 [4];
  int local_1d4 [32];
  undefined4 local_154 [32];
  undefined4 local_d4;
  int local_d0;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  memset(auStack_1d8,0,400);
  if (DAT_00102e69 == '\0') {
    sysmon_smem_init_cdsp();
  }
  if (DAT_00102e90 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nsysMon stats:\n\n");
    seq_printf(param_1,"Core clock(KHz): %d\n",*DAT_00102e90);
    seq_printf(param_1,"Ab vote(Bytes): %llu\n",*(undefined8 *)(DAT_00102e90 + 1));
    seq_printf(param_1,"Ib vote(Bytes): %llu\n",*(undefined8 *)(DAT_00102e90 + 3));
    iVar3 = DAT_00102e90[5];
    if (iVar3 == 0) {
      iVar3 = -1;
    }
    seq_printf(param_1,"Sleep latency(usec): %u\n",iVar3);
  }
  if (DAT_00102ee8 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nDSPPM stats:\n\n");
    seq_printf(param_1,"Version: %u\n",*DAT_00102ee8);
    iVar3 = DAT_00102ee8[1];
    if (iVar3 == 0) {
      iVar3 = -1;
    }
    seq_printf(param_1,"Sleep latency(usec): %u\n",iVar3);
    seq_printf(param_1,"Timestamp: %llu\n",DAT_00102ee8[2]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee8[3],DAT_00102ee8[4]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee8[5],DAT_00102ee8[6]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee8[7],DAT_00102ee8[8]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee8[9],DAT_00102ee8[10]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_00102ee8[0xb],DAT_00102ee8[0xc]);
  }
  if (DAT_00102ea8 != 0) {
    lVar6 = *(long *)(DAT_00102ea8 + 0x18);
    if (*(ulong *)(DAT_00102ea8 + 0x10) < *(ulong *)(DAT_00102ea8 + 8)) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10270c);
        (*pcVar2)();
      }
      lVar4 = (*_arch_timer_read_counter)();
      lVar6 = (lVar4 + lVar6) - *(long *)(DAT_00102ea8 + 8);
    }
    seq_puts(param_1,"\nLPM stats:\n\n");
    seq_printf(param_1,"Count = %u\n",*(undefined4 *)(DAT_00102ea8 + 4));
    seq_printf(param_1,"Last Entered At = %llu\n",*(undefined8 *)(DAT_00102ea8 + 8));
    seq_printf(param_1,"Last Exited At = %llu\n",*(undefined8 *)(DAT_00102ea8 + 0x10));
    seq_printf(param_1,"Accumulated Duration = %llu\n",lVar6);
  }
  if (DAT_00102e78 != 0) {
    iVar3 = sysmon_stats_query_power_residency(5,auStack_1d8);
    if (iVar3 == 0) {
      seq_puts(param_1,"\nPower Stats:\n\n");
      uVar7 = 0;
      do {
        if (local_1d4[uVar7] != 0) {
          seq_printf(param_1,"%u : Core Clock(KHz) : %u \tActive Time(sec) : %u\n",
                     uVar7 & 0xffffffff,local_1d4[uVar7],local_154[uVar7]);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != 0x20);
      seq_printf(param_1,"Power collapse time(sec) = %u\n",local_d4);
      pcVar5 = "Total LPI time(sec) = %u\n";
    }
    else {
      pcVar5 = "\nPower Stats Read failed : %d\n";
      local_d0 = iVar3;
    }
    seq_printf(param_1,pcVar5,local_d0);
  }
  if (DAT_00102ed0 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nQ6 load:\n\n");
    InstructionSynchronizationBarrier();
    uVar7 = cntvct_el0;
    uVar1 = 0;
    if (uVar7 - *(ulong *)(DAT_00102ed0 + 1) < 0x1d9700 || uVar7 <= *(ulong *)(DAT_00102ed0 + 1)) {
      uVar1 = *DAT_00102ed0;
    }
    seq_printf(param_1,"Average Q6 load in KCPS = %u\n",uVar1);
  }
  if (DAT_00102e6b == '\0') {
    sysmon_smem_init_cdsp();
  }
  iVar3 = -0x7e;
  if ((DAT_00102f08 == (int *)0x0) || ((int *)0xfffffffffffff000 < DAT_00102f08)) {
LAB_00102938:
    pcVar5 = "\nHMX stats not available, error code: %d\n";
  }
  else {
    InstructionSynchronizationBarrier();
    uVar7 = cntvct_el0;
    iVar3 = 0;
    if (uVar7 - *(ulong *)(DAT_00102f08 + 1) < 0x1d9700 || uVar7 <= *(ulong *)(DAT_00102f08 + 1)) {
      iVar3 = *DAT_00102f08;
    }
    if (iVar3 == 0xffff) {
      _printk(&DAT_00103048,"sysmon_subsystem_stats",0xffffff82);
      iVar3 = 1;
      goto LAB_00102938;
    }
    seq_puts(param_1,"\nHMX stats:\n\n");
    pcVar5 = "HMX utilization in percentage = %u\n";
  }
  seq_printf(param_1,pcVar5,iVar3);
  if (DAT_00102e6b == '\0') {
    sysmon_smem_init_cdsp();
  }
  iVar3 = -0x7e;
  if ((DAT_00102f10 != (int *)0x0) && (DAT_00102f10 < (int *)0xfffffffffffff001)) {
    InstructionSynchronizationBarrier();
    uVar7 = cntvct_el0;
    iVar3 = 0;
    if (uVar7 - *(ulong *)(DAT_00102f10 + 1) < 0x1d9700 || uVar7 <= *(ulong *)(DAT_00102f10 + 1)) {
      iVar3 = *DAT_00102f10;
    }
    if (iVar3 != 0xffff) {
      seq_puts(param_1,"\nHVX Stats:\n\n");
      pcVar5 = "HVX utilization in percentage = %u\n";
      goto LAB_001029f0;
    }
    _printk(&DAT_00103a95,"sysmon_subsystem_stats",0xffffff82);
    iVar3 = 1;
  }
  pcVar5 = "\nHVX stats not available, error code: %d\n";
LAB_001029f0:
  seq_printf(param_1,pcVar5,iVar3);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102b40 size=216
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  undefined *puVar1;
  
  DAT_00102ef0 = debugfs_create_dir("sysmon_subsystem_stats",0);
  if (DAT_00102ef0 == 0) {
    puVar1 = &DAT_00103802;
  }
  else {
    DAT_00102ef8 = debugfs_create_file("master_adsp_stats",0x124,DAT_00102ef0,0,
                                       &master_adsp_stats_fops);
    if (DAT_00102ef8 == 0) {
      _printk(&DAT_00102f18,"sysmon_subsystem_stats");
    }
    DAT_00102f00 = debugfs_create_file("master_cdsp_stats",0x124,DAT_00102ef0,0,
                                       &master_cdsp_stats_fops);
    if (DAT_00102f00 != 0) {
      return 0;
    }
    puVar1 = &DAT_00103599;
    DAT_00102f00 = 0;
  }
  _printk(puVar1,"sysmon_subsystem_stats");
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00102c1c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  debugfs_remove(DAT_00102ef0);
  return;
}



//------------------------------------------------------------
// _printk @ 00105000 size=1
// signature: undefined _printk(void)
// callers: [sysmon_stats_query_hmx_utlization, sysmon_stats_query_q6_votes, update_sysmon_smem_pointers, sysmon_smem_init_adsp, init_module, sysmon_stats_query_hvx_utlization, sysmon_stats_query_sleep, master_cdsp_stats_show, copy_powerstats, sysmon_smem_init_slpi, sysmon_smem_init_cdsp, sysmon_stats_query_power_residency, sysmon_stats_query_q6_load, sysmon_read_q6_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00105008 size=1
// signature: undefined qcom_smem_get(void)
// callers: [sysmon_smem_init_slpi, sysmon_smem_init_cdsp, sysmon_smem_init_adsp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [master_cdsp_stats_show, sysmon_smem_init_slpi, master_adsp_stats_show, sysmon_smem_init_cdsp, sysmon_smem_init_adsp, sysmon_stats_query_power_residency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00105018 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [master_cdsp_stats_show, master_adsp_stats_show, sysmon_stats_query_power_residency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105028 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [sysmon_stats_query_power_residency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00105030 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00105038 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105040 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00105048 size=1
// signature: undefined single_open(void)
// callers: [master_adsp_stats_open, master_cdsp_stats_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00105050 size=1
// signature: undefined seq_puts(void)
// callers: [master_cdsp_stats_show, master_adsp_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00105058 size=1
// signature: undefined seq_printf(void)
// callers: [master_cdsp_stats_show, master_adsp_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



