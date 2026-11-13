// Decompiled by Ghidra 12.2
// Program: cpufreq_stats_scmi_v2.ko
// Image base: 00100000

//------------------------------------------------------------
// scmi_cpufreq_stats_probe @ 0010015c size=1400
// signature: undefined scmi_cpufreq_stats_probe(void)
// callers: []
//------------------------------------------------------------

ulong scmi_cpufreq_stats_probe(long param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  code *pcVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  long *plVar17;
  long lVar18;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int local_74;
  char local_70 [8];
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  sdev = get_qcom_scmi_device();
  if (sdev < 0xfffffffffffff001) {
    pcVar12 = *(code **)(*(long *)(sdev + 0x3a0) + 0x18);
    if (*(int *)(pcVar12 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1001e8);
      (*pcVar12)();
    }
    ops = (*pcVar12)(sdev,0x80,&ph);
    if (0xfffffffffffff000 < ops) {
      uVar14 = ops & 0xffffffff;
      goto LAB_00100638;
    }
    local_80 = 0;
    uStack_7c = 0;
    uStack_78 = 0;
    local_74 = 0;
    plVar17 = *(long **)(sdev + 0x3a0);
    if (*(int *)(*(code **)(ops + 8) + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x822a,0x100254);
      (*pcVar12)();
    }
    uVar5 = (**(code **)(ops + 8))(ph,&local_80,0x11ece0c0ae12da,2,0,0x10);
    if (uVar5 == 0) {
      if (local_74 == 0) {
        lVar15 = *plVar17;
        pcVar11 = "SCMI cpufreq stats length is zero\n";
LAB_00100630:
        _dev_err(lVar15,pcVar11);
        uVar14 = 0xffffffff;
      }
      else {
        param_1 = param_1 + 0x10;
        pinfo = devm_kmalloc(param_1,0x28,0xdc0);
        if (pinfo != 0) {
          uVar14 = devm_ioremap(*plVar17,CONCAT44(uStack_78,uStack_7c),local_74);
          *(ulong *)(pinfo + 8) = uVar14;
          if (uVar14 < 0xfffffffffffff001) {
            iVar6 = readl_relaxed();
            cVar3 = readl_relaxed(*(long *)(pinfo + 8) + 4);
            uVar5 = readl_relaxed(*(long *)(pinfo + 8) + 8);
            if (iVar6 == 0x50455246) {
              if (cVar3 == '\x01') {
                if ((uVar5 & 0xff) != 0) {
                  uVar2 = uVar5 & 0xff;
                  uVar14 = (ulong)uVar2;
                  *(short *)(pinfo + 0x10) = (short)(uVar5 & 0xff);
                  lVar9 = devm_kmalloc(param_1,uVar2 << 4,0xdc0);
                  lVar15 = pinfo;
                  *(long *)(pinfo + 0x18) = lVar9;
                  if (lVar9 != 0) {
                    if (uVar2 != 0) {
                      lVar9 = 0;
                      uVar13 = 0;
                      do {
                        puVar1 = (undefined4 *)(*(long *)(lVar15 + 0x18) + lVar9);
                        lVar9 = lVar9 + 0x10;
                        *(short *)(puVar1 + 1) = (short)uVar13;
                        *(short *)(puVar1 + 3) = (short)uVar13;
                        uVar13 = uVar13 + 1;
                        *puVar1 = 0;
                        puVar1[2] = 1;
                      } while (uVar14 != uVar13);
                    }
                    lVar15 = *plVar17;
                    local_70[0] = '\0';
                    local_70[1] = '\0';
                    local_70[2] = '\0';
                    local_70[3] = '\0';
                    local_70[4] = '\0';
                    local_70[5] = '\0';
                    local_70[6] = '\0';
                    local_70[7] = '\0';
                    dir = debugfs_create_dir("cpufreq_stats",0);
                    if (dir < 0xfffffffffffff001) {
                      if (*(short *)(pinfo + 0x10) != 0) {
                        uVar13 = 0;
                        lVar9 = 8;
                        do {
                          snprintf(local_70,8,"clkdom%d",(int)uVar13);
                          uVar10 = debugfs_create_dir(local_70,dir);
                          if (0xfffffffffffff000 < uVar10) {
                            _dev_err(lVar15,"Debugfs directory creation for %s failed\n",local_70);
                            goto LAB_001006b8;
                          }
                          debugfs_create_file("usage",0x100,uVar10,
                                              *(long *)(pinfo + 0x18) + lVar9 + -8,stats_ops);
                          debugfs_create_file("time_in_state",0x100,uVar10,
                                              *(long *)(pinfo + 0x18) + lVar9,stats_ops);
                          uVar13 = uVar13 + 1;
                          lVar9 = lVar9 + 0x10;
                        } while (uVar13 < *(ushort *)(pinfo + 0x10));
                      }
                      if (uVar2 == 0) {
                        uVar5 = 0;
                      }
                      else {
                        lVar15 = 0;
                        uVar5 = 0;
                        do {
                          iVar6 = readl_relaxed(*(long *)(pinfo + 8) + lVar15 + 0x10);
                          uVar7 = readl_relaxed(*(long *)(pinfo + 8) + (ulong)(uint)(iVar6 << 2));
                          lVar15 = lVar15 + 4;
                          uVar5 = uVar5 + (uVar7 & 0xff);
                        } while (uVar14 * 4 != lVar15);
                        uVar5 = uVar5 & 0xffff;
                      }
                      lVar15 = devm_kmalloc(param_1,(uVar5 + uVar2) * 4,0xdc0);
                      *(long *)(pinfo + 0x20) = lVar15;
                      if (lVar15 == 0) {
                        _dev_err(*plVar17,"Failed to allocate memory for freq entries\n");
                        uVar14 = 0xfffffff4;
                      }
                      else {
                        if (uVar2 != 0) {
                          lVar15 = 0;
                          uVar13 = 0;
                          do {
                            lVar9 = pinfo;
                            lVar16 = uVar13 * 4;
                            *(uint *)(*(long *)(pinfo + 0x20) + uVar13 * 4) = uVar2;
                            if (uVar13 != 0) {
                              lVar18 = 0;
                              do {
                                iVar6 = readl_relaxed(*(long *)(lVar9 + 8) + lVar18 + 0x10);
                                uVar5 = readl_relaxed(*(long *)(pinfo + 8) +
                                                      (ulong)(uint)(iVar6 << 2));
                                lVar9 = pinfo;
                                lVar18 = lVar18 + 4;
                                *(uint *)(*(long *)(pinfo + 0x20) + lVar16) =
                                     *(int *)(*(long *)(pinfo + 0x20) + lVar16) + (uVar5 & 0xff);
                              } while (lVar15 != lVar18);
                            }
                            iVar6 = readl_relaxed(*(long *)(lVar9 + 8) + lVar16 + 0x10);
                            bVar4 = readl_relaxed(*(long *)(pinfo + 8) + (ulong)(uint)(iVar6 << 2));
                            if (bVar4 != 0) {
                              uVar10 = 0;
                              lVar9 = 0x10;
                              lVar18 = pinfo;
                              do {
                                iVar6 = readl_relaxed(*(long *)(lVar18 + 8) + lVar16 + 0x10);
                                uVar8 = readl_relaxed(*(long *)(pinfo + 8) + lVar9 +
                                                      (ulong)(uint)(iVar6 << 2));
                                lVar18 = pinfo;
                                lVar9 = lVar9 + 0x18;
                                iVar6 = (int)uVar10;
                                uVar10 = uVar10 + 1;
                                *(undefined4 *)
                                 (*(long *)(pinfo + 0x20) +
                                 (ulong)(uint)(iVar6 + *(int *)(*(long *)(pinfo + 0x20) + uVar13 * 4
                                                               )) * 4) = uVar8;
                              } while (bVar4 != uVar10);
                            }
                            uVar13 = uVar13 + 1;
                            lVar15 = lVar15 + 4;
                          } while (uVar13 != uVar14);
                        }
                        uVar14 = 0;
                      }
                    }
                    else {
                      _dev_err(lVar15,"Debugfs directory creation failed\n");
LAB_001006b8:
                      _dev_err(*plVar17,"Failed to create debugfs entries\n");
                      uVar14 = 0xfffffffe;
                    }
                    goto LAB_00100638;
                  }
                  goto LAB_00100490;
                }
                lVar15 = *plVar17;
                pcVar11 = "SCMI cpufreq stats number of clock domains are zero\n";
              }
              else {
                lVar15 = *plVar17;
                pcVar11 = "SCMI stats revision not supported\n";
              }
            }
            else {
              lVar15 = *plVar17;
              pcVar11 = "SCMI stats mem signature check failed\n";
            }
            goto LAB_00100630;
          }
        }
LAB_00100490:
        uVar14 = 0xfffffff4;
      }
      goto LAB_00100638;
    }
    uVar14 = (ulong)uVar5;
    param_1 = *plVar17;
    pcVar11 = "SCMI CPUFREQ Stats CPUFREQSTATS_GET_MEM_INFO error: %d\n";
  }
  else {
    if ((int)sdev == -0x205) {
      uVar14 = 0xfffffdfb;
      goto LAB_00100638;
    }
    param_1 = param_1 + 0x10;
    pcVar11 = "Error getting scmi_dev ret = %d\n";
    uVar14 = sdev;
  }
  _dev_err(param_1,pcVar11,uVar14 & 0xffffffff);
LAB_00100638:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14 & 0xffffffff;
}



//------------------------------------------------------------
// readl_relaxed @ 001006d4 size=124
// signature: undefined readl_relaxed(void)
// callers: [scmi_cpufreq_stats_probe, stats_get]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10071c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// stats_get @ 00100754 size=612
// signature: undefined stats_get(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long stats_get(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  ushort uVar2;
  code *pcVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  undefined8 uVar16;
  long lVar17;
  int *piVar18;
  
  uVar16 = *(undefined8 *)(param_1 + 0x18);
  piVar18 = *(int **)(param_1 + 0xd8);
  iVar5 = debugfs_file_get(uVar16);
  if (iVar5 == 0) {
    if (piVar18 == (int *)0x0) {
      lVar12 = -2;
    }
    else {
      uVar2 = *(ushort *)(piVar18 + 1);
      lVar12 = (ulong)uVar2 * 4;
      lVar14 = *(long *)(pinfo + 8);
      iVar5 = readl_relaxed(lVar14 + lVar12 + 0x10);
      iVar6 = readl_relaxed(*(long *)(pinfo + 8) + lVar12 + 0x10);
      bVar4 = readl_relaxed(*(long *)(pinfo + 8) + (ulong)(uint)(iVar6 << 2));
      if (bVar4 == 0) {
        lVar12 = 0;
      }
      else {
        uVar15 = (ulong)bVar4 << 3;
        lVar12 = __kmalloc(uVar15,0xdc0);
        if ((lVar12 != 0) && (lVar9 = kmalloc_trace(_DAT_001020d0,0xdc0,0x1000), lVar9 != 0)) {
          uVar8 = 0;
          lVar1 = 8;
          if (*piVar18 != 0) {
            lVar1 = (ulong)(*piVar18 == 1) << 4;
          }
          do {
            uVar7 = readl_relaxed(*(long *)(pinfo + 8) + 0xc);
            if ((uVar7 & 1) == 0) {
              uVar13 = 0;
              lVar17 = lVar1 + lVar14 + (ulong)(uint)(iVar5 << 2) + 0x10;
              do {
                uVar10 = readl_relaxed(lVar17);
                lVar11 = readl_relaxed(lVar17 + 4);
                if (uVar15 <= uVar13) goto LAB_001009b4;
                lVar17 = lVar17 + 0x18;
                *(ulong *)(lVar12 + uVar13) = uVar10 & 0xffffffff | lVar11 << 0x20;
                uVar13 = uVar13 + 8;
              } while (uVar15 != uVar13);
              uVar8 = readl_relaxed(*(long *)(pinfo + 8) + 0xc);
            }
          } while (uVar7 != uVar8);
          iVar5 = 0;
          uVar13 = 0;
          lVar14 = 0;
          while (uVar13 < uVar15) {
            iVar6 = scnprintf(lVar9 + lVar14,0x1000 - lVar14,"%u %llu\n",
                              *(undefined4 *)
                               (*(long *)(pinfo + 0x20) +
                               (ulong)(uint)(iVar5 + *(int *)(*(long *)(pinfo + 0x20) +
                                                             (ulong)uVar2 * 4)) * 4),
                              *(undefined8 *)(lVar12 + uVar13));
            uVar13 = uVar13 + 8;
            lVar14 = lVar14 + iVar6;
            iVar5 = iVar5 + 1;
            if (uVar15 == uVar13) {
              lVar14 = simple_read_from_buffer(param_2,param_3,param_4,lVar9,lVar14);
              debugfs_file_put(uVar16);
              kfree(lVar12);
              kfree(lVar9);
              return lVar14;
            }
          }
LAB_001009b4:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x1009b8);
          (*pcVar3)();
        }
        lVar12 = -0xc;
      }
    }
  }
  else {
    lVar12 = (long)iVar5;
  }
  return lVar12;
}



//------------------------------------------------------------
// init_module @ 001009c0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cpufreq_stats_v2_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001009f0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cpufreq_stats_v2_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// get_qcom_scmi_device @ 00102010 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00102020 size=1
// signature: undefined devm_ioremap(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00102028 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00102030 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00102038 size=1
// signature: undefined debugfs_create_file(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [scmi_cpufreq_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00102050 size=1
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
// log_post_read_mmio @ 00102058 size=1
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
// debugfs_file_get @ 00102060 size=1
// signature: undefined debugfs_file_get(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_file_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102068 size=1
// signature: undefined __kmalloc(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102078 size=1
// signature: undefined kmalloc_trace(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102080 size=1
// signature: undefined scnprintf(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00102088 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_file_put @ 00102090 size=1
// signature: undefined debugfs_file_put(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_file_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102098 size=1
// signature: undefined kfree(void)
// callers: [stats_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



