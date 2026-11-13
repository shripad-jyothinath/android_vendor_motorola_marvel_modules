// Decompiled by Ghidra 12.2
// Program: qcom_cpuss_sleep_stats.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_cpuss_sleep_stats_probe @ 001002d4 size=2276
// signature: undefined qcom_cpuss_sleep_stats_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_cpuss_sleep_stats_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  long *plVar10;
  long lVar11;
  long *plVar12;
  undefined8 uVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  uint uVar18;
  uint param3;
  uint local_98;
  uint local_94;
  char local_90 [8];
  char local_88 [32];
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  local_98 = 0;
  plVar10 = (long *)devm_kmalloc(param_1 + 0x10,0x150,0xdc0);
  if (plVar10 == (long *)0x0) {
LAB_00100a14:
    uVar13 = 0xfffffff4;
    goto LAB_00100a18;
  }
  plVar1 = plVar10 + 0x18;
  plVar10[0x18] = (long)plVar1;
  plVar10[0x19] = (long)plVar1;
  lVar11 = debugfs_create_dir("qcom_cpuss_sleep_stats",0);
  iVar8 = 0;
  *plVar10 = param_1;
  plVar10[0x1a] = lVar11;
  plVar10[0x13] = -1;
  while (uVar7 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar8), uVar7 < _nr_cpu_ids)
  {
    local_88[0x10] = '\0';
    local_88[0x11] = '\0';
    local_88[0x12] = '\0';
    local_88[0x13] = '\0';
    local_88[0x14] = '\0';
    local_88[0x15] = '\0';
    local_88[0] = '\0';
    local_88[1] = '\0';
    local_88[2] = '\0';
    local_88[3] = '\0';
    local_88[4] = '\0';
    local_88[5] = '\0';
    local_88[6] = '\0';
    local_88[7] = '\0';
    local_88[8] = '\0';
    local_88[9] = '\0';
    local_88[10] = '\0';
    local_88[0xb] = '\0';
    local_88[0xc] = '\0';
    local_88[0xd] = '\0';
    local_88[0xe] = '\0';
    local_88[0xf] = '\0';
    smp_call_function_single(uVar7,get_mpidr_cpu,&local_98,1);
    snprintf(local_88,0x16,"seq_lpm_cntr_cfg_cpu%u",local_98);
    plVar12 = (long *)platform_get_resource_byname(param_1,0x200,local_88);
    if (plVar12 != (long *)0x0) {
      if ((uVar7 & 0xfffffff8) != 0) goto LAB_00100bb0;
      *(char *)((long)plVar10 + (ulong)uVar7 + 0x98) = (char)local_98;
      plVar10[(ulong)uVar7 + 2] = *plVar12;
      *(int *)((long)plVar10 + (ulong)uVar7 * 4 + 0x50) = ((int)plVar12[1] - (int)*plVar12) + 1;
    }
    iVar8 = uVar7 + 1;
  }
  plVar12 = (long *)platform_get_resource_byname(param_1,0x200,"apss_seq_mem_base");
  if (plVar12 != (long *)0x0) {
    plVar10[0xe] = *plVar12;
    *(int *)(plVar10 + 0xf) = ((int)plVar12[1] - (int)*plVar12) + 1;
    plVar12 = (long *)platform_get_resource_byname(param_1,0x200,"l3_seq_lpm_cntr_cfg");
    if (plVar12 != (long *)0x0) {
      plVar2 = plVar10 + 1;
      plVar10[0x10] = *plVar12;
      uVar13 = *(undefined8 *)(param_1 + 0x2f8);
      *(int *)(plVar10 + 0x11) = ((int)plVar12[1] - (int)*plVar12) + 1;
      of_property_read_variable_u32_array(uVar13,"num-cpus",plVar2,1,0);
      if (0xfffffff7 < (int)plVar10[1] - 9U) {
        lVar14 = device_get_match_data(param_1 + 0x10);
        plVar10[0x12] = lVar14;
        if (lVar14 == 0) goto LAB_001004f0;
        iVar8 = (int)*plVar2;
        local_94 = 0;
        if (0 < iVar8) {
          lVar14 = 0;
          do {
            if (lVar14 == 8) {
LAB_00100bb0:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x100bb4);
              (*pcVar6)();
            }
            bVar4 = *(byte *)((long)plVar10 + lVar14 + 0x98);
            if (bVar4 != 0xff) {
              iVar8 = qcom_scm_io_readl(plVar10[lVar14 + 2],&local_94);
              uVar7 = local_94;
              if (iVar8 != 0) goto LAB_001004b8;
              lVar17 = *plVar10;
              local_90[4] = '\0';
              local_90[5] = '\0';
              local_90[0] = '\0';
              local_90[1] = '\0';
              local_90[2] = '\0';
              local_90[3] = '\0';
              local_88[0x18] = 0;
              local_88[8] = '\0';
              local_88[9] = '\0';
              local_88[10] = '\0';
              local_88[0xb] = '\0';
              local_88[0xc] = '\0';
              local_88[0xd] = '\0';
              local_88[0xe] = '\0';
              local_88[0xf] = '\0';
              local_88[0x10] = '\0';
              local_88[0x11] = '\0';
              local_88[0x12] = '\0';
              local_88[0x13] = '\0';
              local_88[0x14] = '\0';
              local_88[0x15] = '\0';
              local_88[0x16] = '\0';
              local_88[0x17] = '\0';
              local_88[0] = '\0';
              local_88[1] = '\0';
              local_88[2] = '\0';
              local_88[3] = '\0';
              local_88[4] = '\0';
              local_88[5] = '\0';
              local_88[6] = '\0';
              local_88[7] = '\0';
              snprintf(local_90,6,"pcpu%u",(uint)bVar4);
              lVar15 = debugfs_create_dir(local_90,plVar10[0x1a]);
              uVar18 = (uint)bVar4;
              if (7 < uVar18) goto LAB_00100bb0;
              lVar16 = plVar10[0xe];
              lVar5 = plVar10[0xf];
              plVar12 = plVar10 + (ulong)bVar4 + 0x1b;
              *plVar12 = lVar15;
              lVar15 = devm_ioremap(lVar17 + 0x10,lVar16,(int)lVar5);
              if (lVar15 == 0) goto LAB_00100a14;
              iVar8 = (uint)bVar4 * 8;
              param3 = (uint)bVar4;
              if ((uVar7 & 1) != 0) {
                if (*(int *)plVar10[0x12] + iVar8 == 0xffffffea) goto LAB_001004b8;
                lVar17 = lVar15 + (ulong)(uint)(*(int *)plVar10[0x12] + iVar8);
                debugfs_create_file("C1_count",0x124,*plVar12,lVar17,&qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",param3,"C1_count");
                uVar13 = store_stats_data(plVar10,local_88,lVar17);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              if ((uVar7 >> 1 & 1) != 0) {
                uVar3 = *(int *)(plVar10[0x12] + 4) + iVar8;
                if (uVar3 == 0xffffffea) goto LAB_001004b8;
                lVar17 = lVar15 + (ulong)uVar3;
                debugfs_create_file("C2D_count",0x124,*plVar12,lVar17,&qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",param3,"C2D_count");
                uVar13 = store_stats_data(plVar10,local_88,lVar17);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              if ((uVar7 >> 2 & 1) != 0) {
                uVar3 = *(int *)(plVar10[0x12] + 8) + iVar8;
                if (uVar3 == 0xffffffea) goto LAB_001004b8;
                lVar17 = lVar15 + (ulong)uVar3;
                debugfs_create_file("C3_count",0x124,*plVar12,lVar17,&qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",param3,"C3_count");
                uVar13 = store_stats_data(plVar10,local_88,lVar17);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              if ((uVar7 >> 3 & 1) != 0) {
                uVar7 = *(int *)(plVar10[0x12] + 0xc) + iVar8;
                if (uVar7 == 0xffffffea) goto LAB_001004b8;
                lVar15 = lVar15 + (ulong)uVar7;
                debugfs_create_file("C4_count",0x124,*plVar12,lVar15,&qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",param3,"C4_count");
                uVar13 = store_stats_data(plVar10,local_88,lVar15);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              iVar9 = qcom_scm_io_readl(plVar10[0xe] +
                                        (ulong)(*(int *)(plVar10[0x12] + 0x10) + uVar18 * 4),
                                        &local_94);
              uVar7 = local_94;
              if (iVar9 != 0) goto LAB_001004b8;
              local_88[0x18] = 0;
              local_88[8] = '\0';
              local_88[9] = '\0';
              local_88[10] = '\0';
              local_88[0xb] = '\0';
              local_88[0xc] = '\0';
              local_88[0xd] = '\0';
              local_88[0xe] = '\0';
              local_88[0xf] = '\0';
              local_88[0x10] = '\0';
              local_88[0x11] = '\0';
              local_88[0x12] = '\0';
              local_88[0x13] = '\0';
              local_88[0x14] = '\0';
              local_88[0x15] = '\0';
              local_88[0x16] = '\0';
              local_88[0x17] = '\0';
              local_88[0] = '\0';
              local_88[1] = '\0';
              local_88[2] = '\0';
              local_88[3] = '\0';
              local_88[4] = '\0';
              local_88[5] = '\0';
              local_88[6] = '\0';
              local_88[7] = '\0';
              lVar15 = devm_ioremap(*plVar10 + 0x10,plVar10[0xe],(int)plVar10[0xf]);
              if (lVar15 == 0) goto LAB_00100a14;
              if ((uVar7 & 1) != 0) {
                uVar3 = *(int *)(plVar10[0x12] + 0x18) + iVar8;
                if (uVar3 == 0xffffffea) goto LAB_001004b8;
                lVar17 = lVar15 + (ulong)uVar3;
                debugfs_create_file("C2_residency",0x124,*plVar12,lVar17,
                                    &qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",uVar18,"C2_residency");
                uVar13 = store_stats_data(plVar10,local_88,lVar17);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              if ((uVar7 >> 2 & 1) != 0) {
                uVar18 = *(int *)(plVar10[0x12] + 0x1c) + iVar8;
                if (uVar18 == 0xffffffea) goto LAB_001004b8;
                lVar17 = lVar15 + (ulong)uVar18;
                debugfs_create_file("C3_residency",0x124,*plVar12,lVar17,
                                    &qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",param3,"C3_residency");
                uVar13 = store_stats_data(plVar10,local_88,lVar17);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              if ((uVar7 >> 4 & 1) != 0) {
                uVar7 = *(int *)(plVar10[0x12] + 0x20) + iVar8;
                if (uVar7 == 0xffffffea) goto LAB_001004b8;
                lVar15 = lVar15 + (ulong)uVar7;
                debugfs_create_file("C4_residency",0x124,*plVar12,lVar15,
                                    &qcom_cpuss_sleep_stats_fops);
                snprintf(local_88,0x19,"pcpu%u: %s",param3,"C4_residency");
                uVar13 = store_stats_data(plVar10,local_88,lVar15);
                if ((int)uVar13 != 0) goto LAB_00100a18;
              }
              iVar8 = (int)*plVar2;
            }
            lVar14 = lVar14 + 1;
          } while ((int)lVar14 < iVar8);
        }
        iVar8 = qcom_scm_io_readl(plVar10[0x10],&local_94);
        uVar7 = local_94;
        if (iVar8 == 0) {
          lVar15 = *plVar10;
          lVar14 = debugfs_create_dir(&DAT_00101592,plVar10[0x1a]);
          plVar10[0x23] = lVar14;
          if ((lVar14 == 0) ||
             (lVar14 = devm_ioremap(lVar15 + 0x10,plVar10[0xe],(int)plVar10[0xf]), lVar14 == 0))
          goto LAB_00100a14;
          if ((uVar7 & 1) != 0) {
            uVar18 = *(int *)plVar10[0x12] + (int)plVar10[1] * 8;
            if (uVar18 == 0xffffffea) goto LAB_001004b8;
            lVar15 = lVar14 + (ulong)uVar18;
            debugfs_create_file("D1_count",0x124,plVar10[0x23],lVar15,&qcom_cpuss_sleep_stats_fops);
            uVar13 = store_stats_data(plVar10,"D1_count",lVar15);
            if ((int)uVar13 != 0) goto LAB_00100a18;
          }
          if ((uVar7 >> 1 & 1) != 0) {
            uVar18 = *(int *)(plVar10[0x12] + 4) + (int)plVar10[1] * 8;
            if (uVar18 == 0xffffffea) goto LAB_001004b8;
            lVar15 = lVar14 + (ulong)uVar18;
            debugfs_create_file("D2D_count",0x124,plVar10[0x23],lVar15,&qcom_cpuss_sleep_stats_fops)
            ;
            uVar13 = store_stats_data(plVar10,"D2D_count",lVar15);
            if ((int)uVar13 != 0) goto LAB_00100a18;
          }
          if ((uVar7 >> 2 & 1) != 0) {
            uVar18 = *(int *)(plVar10[0x12] + 8) + (int)plVar10[1] * 8;
            if (uVar18 == 0xffffffea) goto LAB_001004b8;
            lVar15 = lVar14 + (ulong)uVar18;
            debugfs_create_file("D3_count",0x124,plVar10[0x23],lVar15,&qcom_cpuss_sleep_stats_fops);
            uVar13 = store_stats_data(plVar10,"D3_count",lVar15);
            if ((int)uVar13 != 0) goto LAB_00100a18;
          }
          if ((uVar7 >> 3 & 1) != 0) {
            uVar7 = *(int *)(plVar10[0x12] + 0xc) + (int)plVar10[1] * 8;
            if (uVar7 == 0xffffffea) goto LAB_001004b8;
            lVar14 = lVar14 + (ulong)uVar7;
            debugfs_create_file("D4_count",0x124,plVar10[0x23],lVar14,&qcom_cpuss_sleep_stats_fops);
            uVar13 = store_stats_data(plVar10,"D4_count",lVar14);
            if ((int)uVar13 != 0) goto LAB_00100a18;
          }
          iVar8 = qcom_scm_io_readl(plVar10[0xe] + (ulong)*(uint *)(plVar10[0x12] + 0x14),&local_94)
          ;
          if (iVar8 == 0) {
            uVar13 = qcom_cpuss_sleep_stats_create_cl_residency_debugfs(plVar10,local_94);
            if ((int)uVar13 == 0) {
              debugfs_create_file("stats",0x124,lVar11,plVar1,&qcom_cpuss_all_stats_fops);
              __mutex_init(plVar10 + 0x24,"&t_info->stats_reset_lock",
                           &qcom_cpuss_sleep_stats_probe___key);
              debugfs_create_file("reset",0x90,lVar11,plVar10,&qcom_cpuss_stats_reset_fops);
              uVar13 = 0;
              *(long *)(param_1 + 0xa8) = lVar11;
            }
            goto LAB_00100a18;
          }
        }
      }
LAB_001004b8:
      uVar13 = 0xffffffea;
      goto LAB_00100a18;
    }
  }
LAB_001004f0:
  uVar13 = 0xffffffed;
LAB_00100a18:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}



//------------------------------------------------------------
// qcom_cpuss_sleep_stats_remove @ 00100bbc size=36
// signature: undefined qcom_cpuss_sleep_stats_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpuss_sleep_stats_remove(long param_1)

{
  debugfs_remove(*(undefined8 *)(param_1 + 0xa8));
  return 0;
}



//------------------------------------------------------------
// get_mpidr_cpu @ 00100be4 size=16
// signature: undefined get_mpidr_cpu(void)
// callers: []
//------------------------------------------------------------

void get_mpidr_cpu(uint *param_1)

{
  undefined8 uVar1;
  
  uVar1 = mpidr_el1;
  *param_1 = (uint)uVar1 >> 8 & 0xff;
  return;
}



//------------------------------------------------------------
// qcom_cpuss_sleep_stats_create_cl_residency_debugfs @ 00100bf4 size=316
// signature: undefined qcom_cpuss_sleep_stats_create_cl_residency_debugfs(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

undefined8 qcom_cpuss_sleep_stats_create_cl_residency_debugfs(long *param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *param_1;
  if ((param_2 & 1) == 0) {
LAB_00100c20:
    if ((param_2 >> 2 & 1) != 0) {
      uVar1 = *(int *)(param_1[0x12] + 0x20) + (int)param_1[1] * 8;
      if (uVar1 == 0xffffffea) goto LAB_00100cb4;
      lVar4 = devm_ioremap(lVar4 + 0x10,param_1[0xe] + (ulong)uVar1,4);
      if (lVar4 == 0) {
        return 0xfffffff4;
      }
      debugfs_create_file("D4_residency",0x124,param_1[0x23],lVar4,&qcom_cpuss_sleep_stats_fops);
      uVar2 = store_stats_data(param_1,"D4_residency",lVar4);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  else {
    uVar1 = *(int *)(param_1[0x12] + 0x18) + (int)param_1[1] * 8;
    if (uVar1 != 0xffffffea) {
      lVar3 = devm_ioremap(lVar4 + 0x10,param_1[0xe] + (ulong)uVar1,4);
      if (lVar3 == 0) {
        return 0xfffffff4;
      }
      debugfs_create_file("D2_residency",0x124,param_1[0x23],lVar3,&qcom_cpuss_sleep_stats_fops);
      uVar2 = store_stats_data(param_1,"D2_residency",lVar3);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      goto LAB_00100c20;
    }
LAB_00100cb4:
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// store_stats_data @ 00100d30 size=228
// signature: undefined store_stats_data(void)
// callers: [qcom_cpuss_sleep_stats_create_cl_residency_debugfs, qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 store_stats_data(long *param_1,char *param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  
  lVar2 = devm_kmalloc(*param_1 + 0x10,0x30,0xdc0);
  if (lVar2 == 0) {
    return 0xfffffff4;
  }
  *(undefined8 *)(lVar2 + 0x18) = param_3;
  uVar3 = strnlen(param_2,0x14);
  if (uVar3 == 0xffffffffffffffff) {
    fortify_panic("strnlen");
  }
  else {
    if (uVar3 != 0x14) {
      uVar3 = uVar3 + 1;
    }
    if (uVar3 < 0x15) {
      strscpy(lVar2,param_2);
      plVar4 = (long *)param_1[0x19];
      lVar1 = lVar2 + 0x20;
      uVar3 = __list_add_valid(lVar1,plVar4,param_1 + 0x18);
      if ((uVar3 & 1) == 0) {
        return 0;
      }
      param_1[0x19] = lVar1;
      *(long **)(lVar2 + 0x20) = param_1 + 0x18;
      *(long **)(lVar2 + 0x28) = plVar4;
      *plVar4 = lVar1;
      return 0;
    }
  }
  fortify_panic("strscpy");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_cpuss_sleep_stats_open @ 00100e18 size=48
// signature: undefined qcom_cpuss_sleep_stats_open(void)
// callers: []
//------------------------------------------------------------

void qcom_cpuss_sleep_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_cpuss_sleep_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_cpuss_sleep_stats_show @ 00100e4c size=68
// signature: undefined qcom_cpuss_sleep_stats_show(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpuss_sleep_stats_show(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = readq_relaxed(*(undefined8 *)(param_1 + 0x80));
  seq_printf(param_1,&DAT_00101677,uVar1);
  return 0;
}



//------------------------------------------------------------
// readq_relaxed @ 00100e90 size=124
// signature: undefined readq_relaxed(void)
// callers: [qcom_cpuss_sleep_stats_show, qcom_cpuss_all_stats_show]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x100ed8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_cpuss_all_stats_open @ 00100f10 size=48
// signature: undefined qcom_cpuss_all_stats_open(void)
// callers: []
//------------------------------------------------------------

void qcom_cpuss_all_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_cpuss_all_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_cpuss_all_stats_show @ 00100f44 size=124
// signature: undefined qcom_cpuss_all_stats_show(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpuss_all_stats_show(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  long *plVar3;
  
  plVar2 = *(long **)(param_1 + 0x80);
  for (plVar3 = (long *)*plVar2; plVar3 != plVar2; plVar3 = (long *)*plVar3) {
    uVar1 = readq_relaxed(plVar3[-1]);
    seq_printf(param_1,"%s: %ld\n",plVar3 + -4,uVar1);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_cpuss_stats_reset_write @ 00100fc4 size=628
// signature: undefined qcom_cpuss_stats_reset_write(void)
// callers: []
//------------------------------------------------------------

long qcom_cpuss_stats_reset_write(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong local_78;
  short local_6c [2];
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_78 = 0;
  local_6c[0] = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 0x20) + 0x2b8);
  uVar3 = *(uint *)(lVar7 + 8);
  iVar5 = simple_write_to_buffer(local_6c,1,&local_78,param_2,param_3 + -1);
  if ((0 < iVar5) && (local_6c[0] == 0x31)) {
    lVar1 = lVar7 + 0x120;
    mutex_lock(lVar1);
    if (0 < (int)uVar3) {
      uVar8 = 0;
      do {
        if (uVar8 == 8) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101234);
          (*pcVar4)();
        }
        uVar9 = (ulong)*(byte *)(lVar7 + 0x98 + uVar8);
        if (uVar9 != 0xff) {
          uVar6 = *(undefined8 *)(lVar7 + 0x98 + uVar8 * 8 + -0x88);
          local_78 = local_78 & 0xffffffff00000000;
          iVar5 = qcom_scm_io_readl(uVar6,&local_78);
          if (iVar5 != 0) goto LAB_00101218;
          local_78 = local_78 | 0xf0;
          iVar5 = qcom_scm_io_writel(uVar6);
          if (iVar5 != 0) goto LAB_00101218;
          local_78 = local_78 & 0xffffffffffffff0f;
          iVar5 = qcom_scm_io_writel(uVar6);
          if (iVar5 != 0) goto LAB_00101218;
          local_78 = local_78 & 0xffffffff00000000;
          lVar2 = *(long *)(lVar7 + 0x70) + uVar9 * 4 +
                  (ulong)*(uint *)(*(long *)(lVar7 + 0x90) + 0x10);
          iVar5 = qcom_scm_io_readl(lVar2,&local_78);
          if (iVar5 != 0) goto LAB_00101218;
          local_78 = local_78 | 0x2a;
          iVar5 = qcom_scm_io_writel(lVar2);
          if (iVar5 != 0) goto LAB_00101218;
          local_78 = local_78 & 0xffffffffffffffd5;
          iVar5 = qcom_scm_io_writel(lVar2);
          if (iVar5 != 0) goto LAB_00101218;
        }
        uVar8 = uVar8 + 1;
      } while (uVar3 != uVar8);
    }
    uVar6 = *(undefined8 *)(lVar7 + 0x80);
    local_78 = local_78 & 0xffffffff00000000;
    iVar5 = qcom_scm_io_readl(uVar6,&local_78);
    if (iVar5 == 0) {
      local_78 = local_78 | 0xf0;
      iVar5 = qcom_scm_io_writel(uVar6);
      if (iVar5 == 0) {
        local_78 = local_78 & 0xffffffffffffff0f;
        iVar5 = qcom_scm_io_writel(uVar6);
        if (iVar5 == 0) {
          local_78 = local_78 & 0xffffffff00000000;
          lVar7 = *(long *)(lVar7 + 0x70) + (ulong)*(uint *)(*(long *)(lVar7 + 0x90) + 0x14);
          iVar5 = qcom_scm_io_readl(lVar7,&local_78);
          if (iVar5 == 0) {
            local_78 = local_78 | 10;
            iVar5 = qcom_scm_io_writel(lVar7);
            if (iVar5 == 0) {
              local_78 = local_78 & 0xfffffffffffffff5;
              iVar5 = qcom_scm_io_writel(lVar7);
              if (iVar5 == 0) {
                mutex_unlock(lVar1);
                goto LAB_0010103c;
              }
            }
          }
        }
      }
    }
LAB_00101218:
    _printk(&DAT_00101552);
    mutex_unlock(lVar1);
  }
  param_3 = -0x16;
LAB_0010103c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// init_module @ 00101240 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_cpuss_sleep_stats,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101270 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_cpuss_sleep_stats);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [store_stats_data, qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00103018 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00103030 size=1
// signature: undefined _find_next_bit(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// smp_call_function_single @ 00103038 size=1
// signature: undefined smp_call_function_single(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void smp_call_function_single(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103040 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00103048 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103050 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_match_data @ 00103058 size=1
// signature: undefined device_get_match_data(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 00103060 size=1
// signature: undefined qcom_scm_io_readl(void)
// callers: [qcom_cpuss_stats_reset_write, qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_readl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00103068 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_cpuss_sleep_stats_create_cl_residency_debugfs, qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00103070 size=1
// signature: undefined debugfs_create_file(void)
// callers: [qcom_cpuss_sleep_stats_create_cl_residency_debugfs, qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103078 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_cpuss_stats_reset_write, qcom_cpuss_sleep_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00103088 size=1
// signature: undefined debugfs_remove(void)
// callers: [qcom_cpuss_sleep_stats_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00103090 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [store_stats_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103098 size=1
// signature: undefined strscpy(void)
// callers: [store_stats_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001030a0 size=1
// signature: undefined __list_add_valid(void)
// callers: [store_stats_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030a8 size=1
// signature: undefined fortify_panic(void)
// callers: [store_stats_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001030b0 size=1
// signature: undefined single_open(void)
// callers: [qcom_cpuss_all_stats_open, qcom_cpuss_sleep_stats_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001030b8 size=1
// signature: undefined seq_printf(void)
// callers: [qcom_cpuss_sleep_stats_show, qcom_cpuss_all_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001030c0 size=1
// signature: undefined log_read_mmio(void)
// callers: [readq_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 001030c8 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readq_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_write_to_buffer @ 001030d0 size=1
// signature: undefined simple_write_to_buffer(void)
// callers: [qcom_cpuss_stats_reset_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_write_to_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001030d8 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_cpuss_stats_reset_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 001030e0 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [qcom_cpuss_stats_reset_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001030e8 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_cpuss_stats_reset_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030f0 size=1
// signature: undefined _printk(void)
// callers: [qcom_cpuss_stats_reset_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



