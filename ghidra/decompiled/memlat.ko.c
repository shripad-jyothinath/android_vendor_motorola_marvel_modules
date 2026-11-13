// Decompiled by Ghidra 12.2
// Program: memlat.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_memlat_probe @ 00100b34 size=7736
// signature: undefined qcom_memlat_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_memlat_probe(long param_1)

{
  long *plVar1;
  ulong *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  char cVar7;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  ulong uVar16;
  long *plVar17;
  long lVar18;
  ulong uVar19;
  long lVar20;
  ulong uVar21;
  ulong uVar22;
  undefined8 *puVar23;
  char *pcVar24;
  undefined *puVar25;
  undefined1 *puVar26;
  char *pcVar27;
  long lVar28;
  int *piVar29;
  undefined8 *puVar30;
  undefined1 uVar31;
  long lVar32;
  uint *puVar33;
  long lVar34;
  undefined1 uVar35;
  undefined1 uVar36;
  undefined8 *puVar37;
  undefined1 uVar38;
  undefined8 uVar39;
  long *plVar40;
  long *plVar41;
  undefined4 *puVar42;
  undefined8 *puVar43;
  ulong local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  ulong local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  uint local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  long local_70;
  
  lVar18 = sp_el0;
  plVar1 = (long *)(param_1 + 0x10);
  local_70 = *(long *)(lVar18 + 0x638);
  piVar15 = (int *)of_device_get_match_data(plVar1);
  if (piVar15 == (int *)0x0) {
    iVar10 = 3;
LAB_0010126c:
    _dev_err(plVar1,"Invalid memlat mon type specified: %u\n",iVar10);
    uVar16 = 0xffffffea;
    goto LAB_001028b4;
  }
  iVar10 = *piVar15;
  if (iVar10 == 2) {
    lVar18 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
    if (lVar18 == 0) {
      pcVar27 = "Mon probe called without memlat_grp inited.\n";
LAB_00101cfc:
      _dev_err(plVar1,pcVar27);
      uVar16 = 0xffffffed;
    }
    else {
      uVar16 = *(ulong *)(param_1 + 0x2f8);
      mutex_lock();
      lVar32 = *(long *)(lVar18 + 0x50);
      uVar21 = (ulong)*(uint *)(lVar18 + 0x5c);
      plVar17 = (long *)(lVar32 + uVar21 * 200);
      *plVar17 = (long)plVar1;
      plVar17[1] = lVar18;
      local_98 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      local_c8 = 0;
      local_c0 = 0;
      local_d8 = 0;
      local_d0 = 0;
      local_e8 = 0;
      local_e0 = 0;
      iVar10 = __of_parse_phandle_with_args
                         (*(undefined8 *)(param_1 + 0x2f8),"qcom,cpulist",0,0,0,&local_e8);
      if ((iVar10 == 0) && (local_e8 != 0)) {
        iVar11 = -0x13;
        iVar10 = 1;
        do {
          uVar22 = local_e8;
          lVar28 = 0;
LAB_00100cf8:
          uVar19 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar28);
          if ((uint)uVar19 < _nr_cpu_ids) {
            lVar28 = get_cpu_device(uVar19 & 0xffffffff);
            if ((lVar28 == 0) || (*(ulong *)(lVar28 + 0x2e8) != uVar22)) goto LAB_00100cf4;
            puVar2 = (ulong *)(plVar17 + 3 + (uVar19 >> 6 & 0x3ffffff));
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar7 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar9) {
                *puVar2 = *puVar2 | 1L << (uVar19 & 0x3f);
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            smp_call_function_single(uVar19 & 0xffffffff,get_mpidr_cpu,&local_98,1);
            iVar11 = 0;
            *(uint *)((long)plVar17 + 0x14) =
                 *(uint *)((long)plVar17 + 0x14) | (uint)(1L << ((ulong)local_98 & 0x3f));
          }
          local_a8 = 0;
          uStack_a0 = 0;
          local_b8 = 0;
          local_b0 = 0;
          local_c8 = 0;
          local_c0 = 0;
          local_d8 = 0;
          local_d0 = 0;
          local_e8 = 0;
          local_e0 = 0;
          iVar12 = __of_parse_phandle_with_args
                             (*(undefined8 *)(param_1 + 0x2f8),"qcom,cpulist",0,0,iVar10,&local_e8);
        } while ((iVar12 == 0) && (iVar10 = iVar10 + 1, local_e8 != 0));
        if (iVar11 != 0) goto LAB_001015ec;
        __bitmap_weight(plVar17 + 3,_nr_cpu_ids);
        lVar28 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,sampling-enabled",0);
        if (lVar28 != 0) {
          mutex_lock(memlat_lock);
          if (*(char *)((long)memlat_data + 0x151) == '\0') {
            iVar10 = 0;
            lVar28 = *memlat_data;
            while (uVar13 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar10),
                  uVar13 < _nr_cpu_ids) {
              lVar20 = devm_kmalloc(lVar28,0x2d0,0xdc0);
              if (lVar20 == 0) goto LAB_001016b8;
              if ((uVar13 & 0xffffffe0) != 0) goto LAB_0010296c;
              iVar10 = uVar13 + 1;
              *(long *)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)uVar13 * 8)) = lVar20
              ;
              *(undefined4 *)(lVar20 + 0x290) = 0;
            }
            lVar20 = alloc_workqueue(&DAT_001062a9,0x4000e,1,"memlat_wq");
            plVar17 = memlat_data;
            memlat_data[0x15] = lVar20;
            if (lVar20 == 0) {
              _dev_err(lVar28,"Couldn\'t create memlat workqueue.\n");
            }
            else {
              plVar17[0xf] = 0xfffffffe0;
              plVar17[0x10] = (long)(plVar17 + 0x10);
              plVar17[0x11] = (long)(plVar17 + 0x10);
              plVar17[0x12] = (long)memlat_update_work;
              hrtimer_init(plVar17 + 0x17,1,1);
              memlat_data[0x1c] = (long)memlat_hrtimer_handler;
              tracepoint_probe_register
                        (&__tracepoint_android_vh_scheduler_tick,memlat_sched_tick_cb,0);
              tracepoint_probe_register
                        (&__tracepoint_android_vh_jiffies_update,memlat_jiffies_update_cb,0);
              qcom_pmu_idle_register(&memlat_idle_notif);
            }
LAB_001016b8:
            *(undefined1 *)((long)memlat_data + 0x151) = 1;
          }
          mutex_unlock(memlat_lock);
          lVar28 = lVar32 + uVar21 * 200;
          *(uint *)(lVar28 + 0x10) = *(uint *)(lVar28 + 0x10) | 1;
        }
        lVar28 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,threadlat-enabled",0);
        if (lVar28 != 0) {
          lVar28 = lVar32 + uVar21 * 200;
          *(uint *)(lVar28 + 0x10) = *(uint *)(lVar28 + 0x10) | 2;
        }
        lVar28 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,cpucp-enabled",0);
        if (lVar28 != 0) {
          lVar28 = lVar32 + uVar21 * 200;
          *(uint *)(lVar28 + 0x10) = *(uint *)(lVar28 + 0x10) | 4;
          *(undefined1 *)(lVar18 + 0x1c) = 1;
        }
        if (*(int *)(lVar32 + uVar21 * 200 + 0x10) != 0) {
          lVar28 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,compute-mon",0);
          if (lVar28 != 0) {
            *(undefined1 *)(lVar32 + uVar21 * 200 + 0xc0) = 1;
          }
          lVar28 = lVar32 + uVar21 * 200;
          *(undefined8 *)(lVar28 + 0x2c) = 400;
          *(undefined8 *)(lVar28 + 0x44) = 0x61a800000064;
          *(undefined8 *)(lVar28 + 0x34) = 0;
          *(undefined8 *)(lVar28 + 0x3c) = 0x138800001388;
          local_a8 = 0;
          uStack_a0 = 0;
          local_b8 = 0;
          local_b0 = 0;
          local_c8 = 0;
          local_c0 = 0;
          local_d8 = 0;
          local_d0 = 0;
          local_e8 = 0;
          local_e0 = 0;
          iVar10 = __of_parse_phandle_with_args(uVar16,"qcom,cpufreq-memfreq-tbl",0,0,0,&local_e8);
          if ((iVar10 == 0) && (local_e8 != 0)) {
            local_a8 = 0;
            uStack_a0 = 0;
            local_b8 = 0;
            local_b0 = 0;
            local_c8 = 0;
            local_c0 = 0;
            local_d8 = 0;
            local_d0 = 0;
            local_e8 = 0;
            local_e0 = 0;
            iVar10 = __of_parse_phandle_with_args(uVar16,"qcom,cpufreq-memfreq-tbl",0,0,0,&local_e8)
            ;
            uVar16 = local_e8;
            if (iVar10 != 0) {
              uVar16 = 0;
            }
          }
          lVar28 = of_get_next_child(uVar16,0);
          if (lVar28 != 0) {
            iVar10 = 0;
            do {
              lVar28 = of_get_next_child(uVar16,lVar28);
              iVar10 = iVar10 + -1;
            } while (lVar28 != 0);
            if (iVar10 != 0) {
              uVar16 = qcom_dcvs_get_ddr_child_node(uVar16);
            }
          }
          local_e8 = local_e8 & 0xffffffff00000000;
          local_98 = 0;
          lVar28 = of_find_property(uVar16,"qcom,cpufreq-memfreq-tbl",&local_e8);
          if (lVar28 != 0) {
            uVar13 = (uint)local_e8;
            iVar10 = (int)(uint)local_e8 >> 2;
            bVar9 = (uint)local_e8 < 4;
            local_e8 = CONCAT44(local_e8._4_4_,iVar10);
            if ((bVar9) || ((uVar13 >> 2 & 1) != 0)) goto LAB_00101b58;
            if (iVar10 < 0) {
              iVar10 = iVar10 + 1;
            }
            uVar14 = iVar10 >> 1;
            piVar15 = (int *)devm_kmalloc(plVar1,-(ulong)(uVar14 + 1 >> 0x1f) & 0xfffffff800000000 |
                                                 (ulong)(uVar14 + 1) << 3,0xdc0);
            if (piVar15 == (int *)0x0) goto LAB_00101b58;
            puVar33 = (uint *)(lVar32 + uVar21 * 200 + 0x28);
            if ((int)uVar13 < 8) {
              *puVar33 = uVar14;
              *piVar15 = 0;
LAB_00101990:
              lVar20 = lVar32 + uVar21 * 200;
              *(int **)(lVar20 + 0x20) = piVar15;
              piVar29 = piVar15 + -1;
              lVar28 = -8;
              if (*piVar15 != 0) {
                lVar28 = 0;
              }
              uVar4 = *(undefined4 *)((long)piVar15 + lVar28 + 4);
              *(undefined4 *)(lVar20 + 0x4c) = uVar4;
              *(undefined4 *)(lVar20 + 0x54) = uVar4;
              do {
                piVar15 = piVar29 + 1;
                piVar29 = piVar29 + 2;
              } while (1 < *piVar15 + 1U);
              lVar28 = -8;
              if (*piVar15 != 0) {
                lVar28 = 0;
              }
              lVar20 = lVar32 + uVar21 * 200;
              uVar6 = *(undefined4 *)((long)piVar29 + lVar28);
              *(undefined4 *)(lVar20 + 0x50) = uVar6;
              *(undefined4 *)(lVar20 + 0x58) = uVar6;
              *(undefined4 *)(lVar20 + 0x5c) = uVar4;
              lVar28 = *(long *)(param_1 + 0x80);
              if (*(char *)(lVar20 + 0xc0) == '\0') {
                if (lVar28 == 0) {
                  lVar28 = *plVar1;
                }
                puVar26 = memlat_mon_ktype;
              }
              else {
                if (lVar28 == 0) {
                  lVar28 = *plVar1;
                }
                puVar26 = compute_mon_ktype;
              }
              uVar22 = kobject_init_and_add
                                 (lVar20 + 0x60,puVar26,*(undefined8 *)(lVar18 + 8),lVar28);
              uVar16 = uVar22 & 0xffffffff;
              if ((int)uVar22 < 0) {
                _dev_err(plVar1,"failed to init memlat mon kobj: %d\n",uVar16);
                kobject_put(lVar20 + 0x60);
                goto LAB_001028a4;
              }
              iVar10 = *(int *)(lVar18 + 0x5c);
              *(int *)(lVar18 + 0x5c) = iVar10 + 1;
              *(int *)(lVar32 + uVar21 * 200 + 0xc4) = iVar10;
              goto LAB_00101a5c;
            }
            uVar13 = uVar14;
            if ((int)uVar14 < 2) {
              uVar13 = 1;
            }
            uVar22 = 0;
            while (iVar10 = of_property_read_u32_index
                                      (uVar16,"qcom,cpufreq-memfreq-tbl",uVar22 & 0xffffffff,
                                       &local_98), -1 < iVar10) {
              piVar15[uVar22] = local_98 / 1000;
              iVar10 = of_property_read_u32_index
                                 (uVar16,"qcom,cpufreq-memfreq-tbl",uVar22 + 1 & 0xffffffff,
                                  &local_98);
              if (iVar10 < 0) break;
              lVar28 = uVar22 + 2;
              piVar15[uVar22 + 1] = local_98;
              uVar22 = uVar22 + 2;
              if ((ulong)uVar13 * 2 == lVar28) {
                *puVar33 = uVar14;
                piVar15[(ulong)uVar13 * 2] = 0;
                goto LAB_00101990;
              }
            }
          }
LAB_00101b58:
          *(undefined8 *)(lVar32 + uVar21 * 200 + 0x20) = 0;
          _dev_err(plVar1,"error importing cpufreq-memfreq table!\n");
          uVar16 = 0xffffffea;
          goto LAB_001028a4;
        }
        _dev_err(plVar1,"No types configured for mon!\n");
        uVar16 = 0xffffffed;
        goto LAB_001028a4;
      }
LAB_001015ec:
      _dev_err(plVar1,"Mon missing cpulist\n");
      uVar16 = 0xffffffed;
      *(int *)(lVar18 + 0x58) = *(int *)(lVar18 + 0x58) + -1;
LAB_00101a5c:
      if ((((((int)memlat_data[0x28] <= *(int *)((long)memlat_data + 0x144)) &&
            ((lVar32 = memlat_data[0x22], lVar32 == 0 ||
             (*(uint *)(lVar32 + 0x58) <= *(uint *)(lVar32 + 0x5c))))) &&
           ((lVar32 = memlat_data[0x23], lVar32 == 0 ||
            (*(uint *)(lVar32 + 0x58) <= *(uint *)(lVar32 + 0x5c))))) &&
          ((((lVar32 = memlat_data[0x24], lVar32 == 0 ||
             (*(uint *)(lVar32 + 0x58) <= *(uint *)(lVar32 + 0x5c))) &&
            ((lVar32 = memlat_data[0x25], lVar32 == 0 ||
             (*(uint *)(lVar32 + 0x58) <= *(uint *)(lVar32 + 0x5c))))) &&
           ((lVar32 = memlat_data[0x26], lVar32 == 0 ||
            (*(uint *)(lVar32 + 0x58) <= *(uint *)(lVar32 + 0x5c))))))) &&
         ((lVar32 = memlat_data[0x27], lVar32 == 0 ||
          (*(uint *)(lVar32 + 0x58) <= *(uint *)(lVar32 + 0x5c))))) {
        *(undefined1 *)((long)memlat_data + 0x152) = 1;
        uVar21 = get_qcom_scmi_device();
        if (uVar21 < 0xfffffffffffff001) {
          local_100 = 0;
          if ((uVar21 == 0) || (*(long *)(uVar21 + 0x3a0) == 0)) {
            uVar21 = 0xffffffea;
          }
          else {
            pcVar8 = *(code **)(*(long *)(uVar21 + 0x3a0) + 0x18);
            if (*(int *)(pcVar8 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x101b3c);
              (*pcVar8)();
            }
            puVar23 = (undefined8 *)(*pcVar8)(uVar21,0x80,&local_100);
            if (puVar23 < (undefined8 *)0xfffffffffffff001) {
              mutex_lock(memlat_lock);
              plVar17 = memlat_data;
              lVar32 = memlat_data[0xd];
              memlat_data[0x2b] = (long)puVar23;
              plVar17[0x2c] = local_100;
              if ((int)lVar32 == 0) {
                uVar35 = 0xff;
              }
              else {
                uVar13 = qcom_get_cpucp_id((int)lVar32,0);
                if (8 < uVar13) {
                  uVar13 = 0xffffffff;
                }
                uVar35 = (undefined1)uVar13;
                plVar17 = memlat_data;
              }
              if (*(int *)((long)plVar17 + 0x6c) == 0) {
                uVar36 = 0xff;
              }
              else {
                uVar13 = qcom_get_cpucp_id(*(int *)((long)plVar17 + 0x6c),0);
                if (8 < uVar13) {
                  uVar13 = 0xffffffff;
                }
                uVar36 = (undefined1)uVar13;
                plVar17 = memlat_data;
              }
              if ((int)plVar17[0xe] == 0) {
                uVar38 = 0xff;
              }
              else {
                uVar13 = qcom_get_cpucp_id((int)plVar17[0xe],0);
                if (8 < uVar13) {
                  uVar13 = 0xffffffff;
                }
                uVar38 = (undefined1)uVar13;
                plVar17 = memlat_data;
              }
              if (*(int *)((long)plVar17 + 0x74) == 0) {
                uVar31 = 0xff;
              }
              else {
                uVar13 = qcom_get_cpucp_id(*(int *)((long)plVar17 + 0x74),0);
                if (8 < uVar13) {
                  uVar13 = 0xffffffff;
                }
                uVar31 = (undefined1)uVar13;
                plVar17 = memlat_data;
              }
              uVar39 = local_e0;
              local_e8 = 0xff00000004;
              local_e0._4_4_ = SUB84(uVar39,4);
              local_e0._0_4_ = CONCAT13(uVar31,CONCAT12(uVar38,CONCAT11(uVar36,uVar35)));
              if (*(int *)((code *)*puVar23 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x101e48);
                (*pcVar8)();
              }
              uVar13 = (*(code *)*puVar23)(plVar17[0x2c],&local_e8,0x4d454d4c4154,0x12,0xc);
              if ((int)uVar13 < 0) {
                uVar21 = (ulong)uVar13;
                puVar25 = &DAT_001062cb;
LAB_00102820:
                _printk(puVar25,uVar21);
LAB_0010282c:
                if (((((memlat_data[0x22] != 0) && (*(char *)(memlat_data[0x22] + 0x1c) != '\0')) ||
                     ((memlat_data[0x23] != 0 && (*(char *)(memlat_data[0x23] + 0x1c) != '\0')))) ||
                    (((memlat_data[0x24] != 0 && (*(char *)(memlat_data[0x24] + 0x1c) != '\0')) ||
                     ((memlat_data[0x25] != 0 && (*(char *)(memlat_data[0x25] + 0x1c) != '\0'))))))
                   || (((memlat_data[0x26] != 0 && (*(char *)(memlat_data[0x26] + 0x1c) != '\0')) ||
                       ((memlat_data[0x27] != 0 && (*(char *)(memlat_data[0x27] + 0x1c) != '\0')))))
                   ) {
                  memlat_data[0x2b] = 0;
                }
              }
              else {
                lVar32 = 0;
                bVar9 = false;
                do {
                  plVar17 = (long *)memlat_data[lVar32 + 0x22];
                  if ((plVar17 != (long *)0x0) && (*(char *)((long)plVar17 + 0x1c) != '\0')) {
                    puVar30 = (undefined8 *)memlat_data[0x2b];
                    local_90 = 0;
                    local_c8 = local_c8 & 0xffffffff00000000;
                    local_d8 = 0;
                    local_d0 = 0;
                    local_f0 = 0;
                    local_f8 = 0;
                    local_e0 = 0;
                    local_e8 = CONCAT44((int)plVar17[2],(int)___cpu_possible_mask);
                    puVar37 = *(undefined8 **)(*plVar17 + 0x2e8);
                    if (*(int *)((code *)*puVar30 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101f18);
                      (*pcVar8)();
                    }
                    uVar13 = (*(code *)*puVar30)(memlat_data[0x2c],&local_e8,0x4d454d4c4154,0x10,
                                                 0x24);
                    if ((int)uVar13 < 0) {
                      uVar21 = (ulong)uVar13;
                      puVar25 = &DAT_001063a3;
                    }
                    else {
                      if ((int)plVar17[8] == 0) {
                        uVar35 = 0xff;
                      }
                      else {
                        uVar13 = qcom_get_cpucp_id((int)plVar17[8],0);
                        if (8 < uVar13) {
                          uVar13 = 0xffffffff;
                        }
                        uVar35 = (undefined1)uVar13;
                      }
                      if (*(int *)((long)plVar17 + 0x44) == 0) {
                        uVar36 = 0xff;
                      }
                      else {
                        uVar13 = qcom_get_cpucp_id(*(int *)((long)plVar17 + 0x44),0);
                        if (8 < uVar13) {
                          uVar13 = 0xffffffff;
                        }
                        uVar36 = (undefined1)uVar13;
                      }
                      if ((int)plVar17[9] == 0) {
                        uVar38 = 0xff;
                      }
                      else {
                        uVar13 = qcom_get_cpucp_id((int)plVar17[9],0);
                        if (8 < uVar13) {
                          uVar13 = 0xffffffff;
                        }
                        uVar38 = (undefined1)uVar13;
                      }
                      uVar13 = local_90;
                      uStack_94 = (undefined4)plVar17[2];
                      local_98 = 3;
                      local_90._3_1_ = SUB41(uVar13,3);
                      local_90._0_3_ = CONCAT12(uVar38,CONCAT11(uVar36,uVar35));
                      if (*(int *)((code *)*puVar30 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101fd8);
                        (*pcVar8)();
                      }
                      uVar13 = (*(code *)*puVar30)(memlat_data[0x2c],&local_98,0x4d454d4c4154,0x13,
                                                   0xc);
                      if ((int)uVar13 < 0) {
                        uVar21 = (ulong)uVar13;
                        puVar25 = &DAT_00106b49;
                      }
                      else {
                        local_f0 = *(undefined4 *)((long)plVar17 + 0x2c);
                        local_f8 = (ulong)*(uint *)(plVar17 + 2);
                        if (*(int *)((code *)*puVar30 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x10202c);
                          (*pcVar8)();
                        }
                        uVar13 = (*(code *)*puVar30)(memlat_data[0x2c],&local_f8,0x4d454d4c4154,0x14
                                                     ,0xc);
                        if ((int)uVar13 < 0) {
                          uVar21 = (ulong)uVar13;
                          puVar25 = &DAT_001061e8;
                        }
                        else {
                          local_f0 = (undefined4)plVar17[5];
                          local_f8 = (ulong)*(uint *)(plVar17 + 2);
                          if (*(int *)((code *)*puVar30 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                            pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x102080);
                            (*pcVar8)();
                          }
                          uVar13 = (*(code *)*puVar30)(memlat_data[0x2c],&local_f8,0x4d454d4c4154,
                                                       0x15,0xc);
                          if (-1 < (int)uVar13) {
                            uVar13 = *(uint *)((long)plVar17 + 0x5c);
                            if (uVar13 != 0) {
                              uVar14 = 0;
                              do {
                                plVar40 = memlat_data;
                                if (*(char *)((long)plVar17 + 0x1c) != '\0') {
                                  lVar28 = plVar17[10];
                                  plVar41 = (long *)(lVar28 + (long)(int)uVar14 * 200);
                                  puVar43 = (undefined8 *)memlat_data[0x2b];
                                  lVar20 = plVar41[1];
                                  local_78 = 0;
                                  local_88 = 0;
                                  uStack_80 = 0;
                                  local_b0 = local_b0 & 0xffffffff00000000;
                                  local_c0 = 0;
                                  local_b8 = 0;
                                  local_d0 = 0;
                                  local_c8 = 0;
                                  local_e0 = 0;
                                  local_d8 = 0;
                                  local_e8 = 0;
                                  uStack_94 = *(undefined4 *)(lVar20 + 0x10);
                                  local_98 = *(uint *)((long)plVar41 + 0x14);
                                  puVar30 = (undefined8 *)*plVar41;
                                  pcVar27 = (char *)puVar30[0xe];
                                  puVar37 = (undefined8 *)puVar30[0x5d];
                                  local_90 = (uint)*(byte *)(plVar41 + 0x18);
                                  puVar42 = (undefined4 *)((long)plVar41 + 0xc4);
                                  local_8c = *puVar42;
                                  if (pcVar27 == (char *)0x0) {
                                    pcVar27 = (char *)*puVar30;
                                  }
                                  pcVar24 = strrchr(pcVar27,0x3a);
                                  if (pcVar24 != (char *)0xffffffffffffffff) {
                                    pcVar27 = strrchr(pcVar27,0x3a);
                                    scnprintf(&local_88,0x14,&DAT_001062a9,pcVar27 + 1);
                                    plVar40 = memlat_data;
                                  }
                                  if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                    pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x102190);
                                    (*pcVar8)();
                                  }
                                  uVar13 = (*(code *)*puVar43)(plVar40[0x2c],&local_98,
                                                               0x4d454d4c4154,0x11,0x24);
                                  if ((int)uVar13 < 0) {
                                    uVar21 = (ulong)uVar13;
                                    puVar25 = &DAT_001060cb;
                                  }
                                  else {
                                    local_f8 = CONCAT44(*puVar42,*(undefined4 *)(lVar20 + 0x10));
                                    local_f0 = *(undefined4 *)
                                                (lVar28 + (long)(int)uVar14 * 200 + 0x2c);
                                    if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x102200);
                                      (*pcVar8)();
                                    }
                                    uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],&local_f8,
                                                                 0x4d454d4c4154,0x17,0xc);
                                    if ((int)uVar13 < 0) {
                                      uVar21 = (ulong)uVar13;
                                      puVar25 = &DAT_00106531;
                                    }
                                    else {
                                      local_f8 = CONCAT44(*puVar42,*(undefined4 *)(lVar20 + 0x10));
                                      local_f0 = *(undefined4 *)
                                                  (lVar28 + (long)(int)uVar14 * 200 + 0x30);
                                      if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x102260);
                                        (*pcVar8)();
                                      }
                                      uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],&local_f8,
                                                                   0x4d454d4c4154,0x18,0xc);
                                      if ((int)uVar13 < 0) {
                                        uVar21 = (ulong)uVar13;
                                        puVar25 = &DAT_00106972;
                                      }
                                      else {
                                        local_f8 = CONCAT44(*puVar42,*(undefined4 *)(lVar20 + 0x10))
                                        ;
                                        local_f0 = *(undefined4 *)
                                                    (lVar28 + (long)(int)uVar14 * 200 + 0x34);
                                        if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1022c0);
                                          (*pcVar8)();
                                        }
                                        uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],&local_f8,
                                                                     0x4d454d4c4154,0x19,0xc);
                                        if ((int)uVar13 < 0) {
                                          uVar21 = (ulong)uVar13;
                                          puVar25 = &DAT_0010655f;
                                        }
                                        else {
                                          local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                        (lVar20 + 0x10));
                                          local_f0 = *(undefined4 *)
                                                      (lVar28 + (long)(int)uVar14 * 200 + 0x44);
                                          if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                            pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x102320);
                                            (*pcVar8)();
                                          }
                                          uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],&local_f8,
                                                                       0x4d454d4c4154,0x1a,0xc);
                                          if ((int)uVar13 < 0) {
                                            uVar21 = (ulong)uVar13;
                                            puVar25 = &DAT_00106713;
                                          }
                                          else {
                                            local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                          (lVar20 + 0x10));
                                            local_f0 = *(undefined4 *)
                                                        (lVar28 + (long)(int)uVar14 * 200 + 0x48);
                                            if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                              pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x102380);
                                              (*pcVar8)();
                                            }
                                            uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],&local_f8
                                                                         ,0x4d454d4c4154,0x1b,0xc);
                                            if ((int)uVar13 < 0) {
                                              uVar21 = (ulong)uVar13;
                                              puVar25 = &DAT_00106058;
                                            }
                                            else {
                                              local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                            (lVar20 + 0x10));
                                              local_f0 = *(undefined4 *)
                                                          (lVar28 + (long)(int)uVar14 * 200 + 0x38);
                                              if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                                                pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1023e0)
                                                ;
                                                (*pcVar8)();
                                              }
                                              uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],
                                                                           &local_f8,0x4d454d4c4154,
                                                                           0x1c,0xc);
                                              if ((int)uVar13 < 0) {
                                                uVar21 = (ulong)uVar13;
                                                puVar25 = &DAT_001067d4;
                                              }
                                              else {
                                                local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                              (lVar20 + 0x10));
                                                local_f0 = *(undefined4 *)
                                                            (lVar28 + (long)(int)uVar14 * 200 + 0x3c
                                                            );
                                                if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a)
                                                {
                    /* WARNING: Does not return */
                                                  pcVar8 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x102440);
                                                  (*pcVar8)();
                                                }
                                                uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],
                                                                             &local_f8,
                                                                             0x4d454d4c4154,0x1d,0xc
                                                                            );
                                                if ((int)uVar13 < 0) {
                                                  uVar21 = (ulong)uVar13;
                                                  puVar25 = &DAT_00106683;
                                                }
                                                else {
                                                  local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                                (lVar20 + 0x10));
                                                  local_f0 = *(undefined4 *)
                                                              (lVar28 + (long)(int)uVar14 * 200 +
                                                              0x40);
                                                  if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a
                                                     ) {
                    /* WARNING: Does not return */
                                                    pcVar8 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x1024a0);
                                                  (*pcVar8)();
                                                  }
                                                  uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],
                                                                               &local_f8,
                                                                               0x4d454d4c4154,0x1e,
                                                                               0xc);
                                                  if ((int)uVar13 < 0) {
                                                    uVar21 = (ulong)uVar13;
                                                    puVar25 = &DAT_00106892;
                                                  }
                                                  else {
                                                    local_e8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                                  (lVar20 + 0x10));
                                                    uVar13 = *(uint *)(lVar28 + (long)(int)uVar14 *
                                                                                200 + 0x28);
                                                    local_e0 = CONCAT44(local_e0._4_4_,uVar13);
                                                    if (uVar13 != 0) {
                                                      uVar21 = 0;
                                                      puVar33 = (uint *)(*(long *)(lVar28 + (long)(
                                                  int)uVar14 * 200 + 0x20) + 4);
                                                  lVar34 = -0x30;
                                                  do {
                                                    if (((lVar34 == 0) ||
                                                        ((uVar21 & 0x3fffffffffffffff) == 0xc)) ||
                                                       (*(short *)((long)&local_b0 + lVar34 + 4) =
                                                             (short)puVar33[-1],
                                                       lVar34 + 1U < 0xffffffffffffffc3)) {
                    /* WARNING: Does not return */
                                                      pcVar8 = (code *)SoftwareBreakpoint(1,0x10296c
                                                                                         );
                                                      (*pcVar8)();
                                                    }
                                                    uVar5 = *puVar33;
                                                    uVar21 = uVar21 + 1;
                                                    uVar3 = uVar5 / 1000;
                                                    if (uVar5 < 0x3e9) {
                                                      uVar3 = uVar5;
                                                    }
                                                    *(short *)((long)&local_b0 + lVar34 + 6) =
                                                         (short)uVar3;
                                                    puVar33 = puVar33 + 2;
                                                    lVar34 = lVar34 + 4;
                                                  } while (uVar13 != uVar21);
                                                  }
                                                  if (*(int *)((code *)*puVar43 + -4) != -0x6997da7a
                                                     ) {
                    /* WARNING: Does not return */
                                                    pcVar8 = (code *)SoftwareBreakpoint(0x8229,
                                                  0x10257c);
                                                  (*pcVar8)();
                                                  }
                                                  uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],
                                                                               &local_e8,
                                                                               0x4d454d4c4154,0x20,
                                                                               0x3c);
                                                  if ((int)uVar13 < 0) {
                                                    uVar21 = (ulong)uVar13;
                                                    puVar25 = &DAT_001060fa;
                                                  }
                                                  else {
                                                    local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                                  (lVar20 + 0x10));
                                                    local_f0 = *(undefined4 *)
                                                                (lVar28 + (long)(int)uVar14 * 200 +
                                                                0x4c);
                                                    if (*(int *)((code *)*puVar43 + -4) !=
                                                        -0x6997da7a) {
                    /* WARNING: Does not return */
                                                      pcVar8 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x1025e0);
                                                  (*pcVar8)();
                                                  }
                                                  uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],
                                                                               &local_f8,
                                                                               0x4d454d4c4154,0x21,
                                                                               0xc);
                                                  if ((int)uVar13 < 0) {
                                                    uVar21 = (ulong)uVar13;
                                                    puVar25 = &DAT_001064e5;
                                                  }
                                                  else {
                                                    local_f8 = CONCAT44(*puVar42,*(undefined4 *)
                                                                                  (lVar20 + 0x10));
                                                    local_f0 = *(undefined4 *)
                                                                (lVar28 + (long)(int)uVar14 * 200 +
                                                                0x50);
                                                    if (*(int *)((code *)*puVar43 + -4) !=
                                                        -0x6997da7a) {
                    /* WARNING: Does not return */
                                                      pcVar8 = (code *)SoftwareBreakpoint(0x8228,
                                                  0x102640);
                                                  (*pcVar8)();
                                                  }
                                                  uVar13 = (*(code *)*puVar43)(memlat_data[0x2c],
                                                                               &local_f8,
                                                                               0x4d454d4c4154,0x22,
                                                                               0xc);
                                                  if (-1 < (int)uVar13) {
                                                    bVar9 = true;
                                                    uVar13 = *(uint *)((long)plVar17 + 0x5c);
                                                    goto LAB_001020a0;
                                                  }
                                                  uVar21 = (ulong)uVar13;
                                                  puVar25 = &DAT_00106484;
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
                                  _printk(puVar25,*puVar37);
                                  puVar25 = &DAT_00106624;
                                  goto LAB_00102820;
                                }
LAB_001020a0:
                                uVar14 = uVar14 + 1;
                              } while (uVar14 < uVar13);
                            }
                            goto LAB_00101e80;
                          }
                          uVar21 = (ulong)uVar13;
                          puVar25 = &DAT_0010600e;
                        }
                      }
                    }
                    _printk(puVar25,*puVar37);
                    _printk(&DAT_001065c7,uVar21);
                    goto LAB_0010282c;
                  }
LAB_00101e80:
                  lVar32 = lVar32 + 1;
                } while (lVar32 != 6);
                if (*(int *)((code *)*puVar23 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                  pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x1026b4);
                  (*pcVar8)();
                }
                uVar22 = (*(code *)*puVar23)(memlat_data[0x2c],memlat_data + 0x2d,0x4d454d4c4154,
                                             0x1f,4);
                uVar21 = uVar22 & 0xffffffff;
                if ((int)uVar22 < 0) {
                  puVar25 = &DAT_0010693b;
                  goto LAB_00102820;
                }
                if (bVar9) {
                  if (*(int *)((code *)puVar23[2] + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
                    pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x102704);
                    (*pcVar8)();
                  }
                  uVar22 = (*(code *)puVar23[2])(memlat_data[0x2c],0,0x4d454d4c4154,0x24,0);
                  uVar21 = uVar22 & 0xffffffff;
                  if (-1 < (int)uVar22) goto LAB_00102894;
                  _printk(&DAT_001061af,uVar21);
                  goto LAB_0010282c;
                }
              }
LAB_00102894:
              mutex_unlock(memlat_lock);
              iVar10 = (int)uVar21;
            }
            else {
              uVar21 = (ulong)puVar23 & 0xffffffff;
              iVar10 = (int)puVar23;
            }
            if (-1 < iVar10) goto LAB_001028a4;
          }
          pcVar27 = "Err during cpucp_memlat_init: %d\n";
        }
        else {
          pcVar27 = "get_qcom_scmi_device ret: %d\n";
          uVar21 = uVar21 & 0xffffffff;
        }
        _dev_err(plVar1,pcVar27,uVar21);
      }
LAB_001028a4:
      mutex_unlock(lVar18 + 0x60);
LAB_001028ac:
      if (-1 < (int)uVar16) goto LAB_001028b0;
    }
  }
  else if (iVar10 == 1) {
    local_98 = 0;
    local_f8 = CONCAT44(local_f8._4_4_,3);
    local_100 = CONCAT44(local_100._4_4_,3);
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_c8 = 0;
    local_c0 = 0;
    local_d8 = 0;
    local_d0 = 0;
    local_e8 = 0;
    local_e0 = 0;
    iVar10 = __of_parse_phandle_with_args
                       (*(undefined8 *)(param_1 + 0x2f8),"qcom,target-dev",0,0,0,&local_e8);
    if ((iVar10 != 0) || (local_e8 == 0)) {
      _dev_err(plVar1,"Unable to find target-dev for grp\n");
      uVar16 = 0xffffffea;
      goto LAB_00101d04;
    }
    iVar10 = of_property_read_variable_u32_array(local_e8,"qcom,dcvs-hw-type",&local_f8,1,0);
    uVar16 = local_f8 & 0xffffffff;
    if ((iVar10 < 0) || (5 < (uint)local_f8)) {
      pcVar27 = "invalid dcvs hw_type=%d, ret=%d\n";
    }
    else {
      plVar17 = (long *)devm_kmalloc(plVar1,0xf0,0xdc0);
      if (plVar17 == (long *)0x0) goto LAB_001015e4;
      *(uint *)(plVar17 + 2) = (uint)local_f8;
      *plVar17 = (long)plVar1;
      uVar16 = qcom_dcvs_kobject_get();
      plVar17[1] = uVar16;
      if (0xfffffffffffff000 < uVar16) {
        _dev_err(plVar1,"error getting kobj from qcom_dcvs: %d\n",uVar16 & 0xffffffff);
        iVar10 = (int)uVar16;
joined_r0x00101c1c:
        if (iVar10 != 0) goto LAB_001028ac;
LAB_00101598:
        uVar39 = *(undefined8 *)(param_1 + 0x2f8);
        lVar18 = of_get_next_available_child(uVar39,0);
        if (lVar18 != 0) {
          iVar10 = 0;
          do {
            lVar18 = of_get_next_available_child(uVar39,lVar18);
            iVar10 = iVar10 + -1;
          } while (lVar18 != 0);
          if (iVar10 != 0) {
            uVar39 = *(undefined8 *)(param_1 + 0x2f8);
            goto LAB_001015d0;
          }
        }
        goto LAB_001028b0;
      }
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      local_c8 = 0;
      local_c0 = 0;
      local_d8 = 0;
      local_d0 = 0;
      local_e8 = 0;
      local_e0 = 0;
      iVar10 = __of_parse_phandle_with_args
                         (*(undefined8 *)(param_1 + 0x2f8),"qcom,sampling-path",0,0,0,&local_e8);
      uVar13 = 3;
      if ((iVar10 == 0) && (local_e8 != 0)) {
        iVar10 = of_property_read_variable_u32_array(local_e8,"qcom,dcvs-path-type",&local_100,1,0);
        uVar16 = local_100 & 0xffffffff;
        if ((-1 < iVar10) && ((uint)local_100 < 3)) {
          if ((uint)local_100 == 1) {
            pcVar27 = "memlat_fp";
          }
          else {
            pcVar27 = *(char **)(param_1 + 0x80);
            if (pcVar27 == (char *)0x0) {
              pcVar27 = (char *)*plVar1;
            }
          }
          uVar21 = qcom_dcvs_register_voter(pcVar27,(uint)local_f8);
          uVar16 = uVar21 & 0xffffffff;
          if ((int)uVar21 < 0) {
            _dev_err(plVar1,"qcom dcvs registration error: %d\n",uVar16);
            goto LAB_00101d04;
          }
          uVar13 = (uint)local_100;
          goto LAB_001012a4;
        }
      }
      else {
LAB_001012a4:
        uVar39 = *(undefined8 *)(param_1 + 0x2f8);
        *(uint *)((long)plVar17 + 0x14) = uVar13;
        local_a8 = 0;
        uStack_a0 = 0;
        local_b8 = 0;
        local_b0 = 0;
        local_c8 = 0;
        local_c0 = 0;
        local_d8 = 0;
        local_d0 = 0;
        local_e8 = 0;
        local_e0 = 0;
        iVar10 = __of_parse_phandle_with_args(uVar39,"qcom,threadlat-path",0,0,0,&local_e8);
        if ((iVar10 != 0) || (local_e8 == 0)) {
          *(undefined4 *)(plVar17 + 3) = 3;
          uVar14 = uVar13;
          if (2 < (uint)local_100) {
            pcVar27 = "error: no dcvs voting paths\n";
            goto LAB_00101cfc;
          }
joined_r0x00101340:
          if (uVar14 == 1) {
LAB_00101344:
            uVar13 = _nr_cpu_ids;
            *(undefined1 *)(plVar17 + 6) = 1;
            uVar13 = __bitmap_weight(&__cpu_possible_mask,uVar13);
            if (uVar13 < 9) {
              uVar13 = 8;
            }
            lVar18 = devm_kmalloc(plVar1,(ulong)(uVar13 + 1) << 2,0xdc0);
            plVar17[7] = lVar18;
          }
          uVar39 = *(undefined8 *)(param_1 + 0x2f8);
          lVar18 = of_get_next_available_child(uVar39,0);
          if (lVar18 != 0) {
            uVar13 = 0;
            do {
              uVar13 = uVar13 + 1;
              lVar18 = of_get_next_available_child(uVar39,lVar18);
            } while (lVar18 != 0);
            if (uVar13 != 0) {
              lVar18 = devm_kmalloc(plVar1,(ulong)uVar13 * 200,0xdc0);
              plVar17[10] = lVar18;
              if (lVar18 == 0) goto LAB_001015e4;
              *(uint *)(plVar17 + 0xb) = uVar13;
              *(undefined4 *)((long)plVar17 + 0x5c) = 0;
              __mutex_init(plVar17 + 0xc,"&memlat_grp->mons_lock",&memlat_grp_probe___key);
              iVar10 = of_property_read_variable_u32_array
                                 (*(undefined8 *)(param_1 + 0x2f8),"qcom,miss-ev",&local_98,1,0);
              if (iVar10 < 0) {
                _dev_err(plVar1,"Cache miss event missing for grp: %d\n",iVar10);
                uVar16 = 0xffffffea;
                goto LAB_00101d04;
              }
              uVar39 = *(undefined8 *)(param_1 + 0x2f8);
              *(uint *)(plVar17 + 8) = local_98;
              iVar10 = of_property_read_variable_u32_array(uVar39,"qcom,access-ev",&local_98,1,0);
              if (-1 < iVar10) {
                *(uint *)(plVar17 + 9) = local_98;
              }
              iVar10 = of_property_read_variable_u32_array
                                 (*(undefined8 *)(param_1 + 0x2f8),"qcom,wb-ev",&local_98,1,0);
              if (-1 < iVar10) {
                *(uint *)((long)plVar17 + 0x44) = local_98;
              }
              iVar10 = 0;
              while (uVar13 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar10),
                    uVar13 < _nr_cpu_ids) {
                local_98 = *(uint *)(plVar17 + 8);
                if ((((local_98 != 0) &&
                     (uVar21 = qcom_pmu_event_supported(local_98,uVar13), (int)uVar21 != 0)) ||
                    ((local_98 = *(uint *)((long)plVar17 + 0x44), local_98 != 0 &&
                     (uVar21 = qcom_pmu_event_supported(local_98,uVar13), (int)uVar21 != 0)))) ||
                   ((local_98 = *(uint *)(plVar17 + 9), local_98 != 0 &&
                    (uVar21 = qcom_pmu_event_supported(local_98,uVar13), (int)uVar21 != 0)))) {
                  uVar16 = uVar21 & 0xffffffff;
                  iVar10 = (int)uVar21;
                  if (iVar10 == -0x205) goto LAB_00101d04;
                  _dev_err(plVar1,"ev=%lu not found on cpu%d: %d\n",local_98,uVar13,uVar16);
                  goto joined_r0x00101c1c;
                }
                iVar10 = uVar13 + 1;
              }
              kobject_init_and_add(plVar17 + 0x12,memlat_grp_ktype,plVar17[1],"memlat");
              mutex_lock(memlat_lock);
              plVar40 = memlat_data;
              *(int *)((long)memlat_data + 0x144) = *(int *)((long)memlat_data + 0x144) + 1;
              if (5 < (uint)local_f8) {
LAB_0010296c:
                    /* WARNING: Does not return */
                pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x102970);
                (*pcVar8)();
              }
              plVar40[(local_f8 & 0xffffffff) + 0x22] = (long)plVar17;
              if ((char)plVar40[0x2a] == '\0') {
                uVar16 = should_enable_memlat_fp();
                plVar40 = memlat_data;
                if ((uVar16 & 1) != 0) {
                  memlat_data[0x29] = 0;
                  *(undefined1 *)(plVar40 + 0x2a) = 1;
                }
              }
              mutex_unlock(memlat_lock);
              *(long **)(param_1 + 0xa8) = plVar17;
              goto LAB_00101598;
            }
          }
          pcVar27 = "No mons provided!\n";
          goto LAB_00101cfc;
        }
        iVar10 = of_property_read_variable_u32_array(local_e8,"qcom,dcvs-path-type",&local_100,1,0);
        uVar16 = local_100 & 0xffffffff;
        if ((-1 < iVar10) && ((uint)local_100 < 3)) {
          *(uint *)(plVar17 + 3) = (uint)local_100;
          uVar14 = (uint)local_100;
          if (uVar13 != 1) goto joined_r0x00101340;
          goto LAB_00101344;
        }
      }
      pcVar27 = "invalid dcvs path: %d, ret=%d\n";
    }
    if (-1 < iVar10) {
      iVar10 = 0;
    }
    _dev_err(plVar1,pcVar27,uVar16,iVar10);
    uVar16 = 0xffffffea;
  }
  else {
    if (iVar10 != 0) goto LAB_0010126c;
    if (memlat_data != (long *)0x0) {
      _dev_err(plVar1,"only one memlat device allowed\n");
    }
    local_e8 = local_e8 & 0xffffffff00000000;
    uVar16 = get_qcom_scmi_device();
    if (0xfffffffffffff000 < uVar16) {
      if ((int)uVar16 == -0x205) {
        uVar16 = 0xfffffdfb;
        goto LAB_00101d04;
      }
      _dev_err(plVar1,"Error getting scmi_dev ret = %d\n");
    }
    plVar17 = (long *)devm_kmalloc(plVar1,0x170,0xdc0);
    if (plVar17 != (long *)0x0) {
      uVar39 = *(undefined8 *)(param_1 + 0x2f8);
      *plVar17 = (long)plVar1;
      *(undefined4 *)(plVar17 + 0x16) = 8;
      *(undefined4 *)(plVar17 + 0x2d) = 8;
      lVar18 = of_get_next_available_child(uVar39,0);
      if (lVar18 == 0) {
        *(undefined4 *)(plVar17 + 0x28) = 0;
      }
      else {
        iVar10 = 0;
        do {
          lVar18 = of_get_next_available_child(uVar39,lVar18);
          iVar10 = iVar10 + -1;
        } while (lVar18 != 0);
        *(int *)(plVar17 + 0x28) = -iVar10;
        if (iVar10 != 0) {
          iVar10 = of_property_read_variable_u32_array
                             (*(undefined8 *)(param_1 + 0x2f8),"qcom,inst-ev",&local_e8,1,0);
          if (iVar10 < 0) {
            iVar10 = 8;
            local_e8 = CONCAT44(local_e8._4_4_,8);
          }
          else {
            iVar10 = (uint)local_e8;
          }
          uVar39 = *(undefined8 *)(param_1 + 0x2f8);
          *(int *)(plVar17 + 0xd) = iVar10;
          iVar11 = of_property_read_variable_u32_array(uVar39,"qcom,cyc-ev",&local_e8,1,0);
          if (iVar11 < 0) {
            iVar11 = 0x11;
            local_e8 = CONCAT44(local_e8._4_4_,0x11);
          }
          else {
            iVar11 = (uint)local_e8;
          }
          uVar39 = *(undefined8 *)(param_1 + 0x2f8);
          *(int *)((long)plVar17 + 0x6c) = iVar11;
          iVar12 = of_property_read_variable_u32_array(uVar39,"qcom,fe-stall-ev",&local_e8,1,0);
          if (-1 < iVar12) {
            *(uint *)(plVar17 + 0xe) = (uint)local_e8;
          }
          iVar12 = of_property_read_variable_u32_array
                             (*(undefined8 *)(param_1 + 0x2f8),"qcom,be-stall-ev",&local_e8,1,0);
          if (-1 < iVar12) {
            *(uint *)((long)plVar17 + 0x74) = (uint)local_e8;
          }
          iVar12 = 0;
          while (uVar13 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar12),
                uVar13 < _nr_cpu_ids) {
            local_e8 = CONCAT44(local_e8._4_4_,iVar10);
            if ((iVar10 != 0) && (uVar14 = qcom_pmu_event_supported(iVar10,uVar13), uVar14 != 0)) {
              uVar16 = (ulong)uVar14;
              if (uVar14 == 0xfffffdfb) goto LAB_00101d04;
              _dev_err(plVar1,"ev=%lu not found on cpu%d: %d\n",local_e8 & 0xffffffff,uVar13,uVar16)
              ;
              if (((uint)local_e8 == 8) || ((uint)local_e8 == 0x11)) goto LAB_00101cac;
            }
            local_e8 = CONCAT44(local_e8._4_4_,iVar11);
            if ((iVar11 != 0) && (uVar14 = qcom_pmu_event_supported(iVar11,uVar13), uVar14 != 0)) {
              uVar16 = (ulong)uVar14;
              if (uVar14 == 0xfffffdfb) goto LAB_00101d04;
              _dev_err(plVar1,"ev=%lu not found on cpu%d: %d\n",local_e8 & 0xffffffff,uVar13,uVar16)
              ;
              if (((uint)local_e8 == 8) || ((uint)local_e8 == 0x11)) goto LAB_00101cac;
            }
            iVar12 = (int)plVar17[0xe];
            local_e8 = CONCAT44(local_e8._4_4_,iVar12);
            if ((iVar12 != 0) && (uVar14 = qcom_pmu_event_supported(iVar12,uVar13), uVar14 != 0)) {
              uVar16 = (ulong)uVar14;
              if (uVar14 == 0xfffffdfb) goto LAB_00101d04;
              _dev_err(plVar1,"ev=%lu not found on cpu%d: %d\n",local_e8 & 0xffffffff,uVar13,uVar16)
              ;
              if (((uint)local_e8 == 8) || ((uint)local_e8 == 0x11)) goto LAB_00101cac;
            }
            iVar12 = *(int *)((long)plVar17 + 0x74);
            local_e8 = CONCAT44(local_e8._4_4_,iVar12);
            if ((iVar12 != 0) && (uVar14 = qcom_pmu_event_supported(iVar12,uVar13), uVar14 != 0)) {
              uVar16 = (ulong)uVar14;
              if (uVar14 == 0xfffffdfb) goto LAB_00101d04;
              _dev_err(plVar1,"ev=%lu not found on cpu%d: %d\n",local_e8 & 0xffffffff,uVar13,uVar16)
              ;
              if (((uint)local_e8 == 8) || ((uint)local_e8 == 0x11)) goto LAB_00101cac;
            }
            iVar12 = uVar13 + 1;
          }
          uVar16 = qcom_dcvs_kobject_get(6);
          if (uVar16 < 0xfffffffffffff001) {
            uVar13 = kobject_init_and_add
                               (plVar17 + 1,memlat_settings_ktype,uVar16,"memlat_settings");
            if ((int)uVar13 < 0) {
              uVar16 = (ulong)uVar13;
              _dev_err(plVar1,"failed to init memlat settings kobj: %d\n",uVar16);
              kobject_put(plVar17 + 1);
              goto LAB_00101d04;
            }
            memlat_data = plVar17;
          }
          else {
            _dev_err(plVar1,"error getting kobj from qcom_dcvs: %d\n",uVar16 & 0xffffffff);
LAB_00101cac:
            if ((int)uVar16 != 0) goto LAB_001028ac;
          }
          uVar39 = *(undefined8 *)(param_1 + 0x2f8);
          lVar18 = of_get_next_available_child(uVar39,0);
          if (lVar18 != 0) {
            iVar10 = 0;
            do {
              lVar18 = of_get_next_available_child(uVar39,lVar18);
              iVar10 = iVar10 + -1;
            } while (lVar18 != 0);
            if (iVar10 != 0) {
              uVar39 = *(undefined8 *)(param_1 + 0x2f8);
LAB_001015d0:
              of_platform_populate(uVar39,0,0,plVar1);
            }
          }
LAB_001028b0:
          uVar16 = 0;
          goto LAB_001028b4;
        }
      }
      pcVar27 = "No memlat grps provided!\n";
      goto LAB_00101cfc;
    }
LAB_001015e4:
    uVar16 = 0xfffffff4;
  }
LAB_00101d04:
  _dev_err(plVar1,"Failure to probe memlat device: %d\n",uVar16 & 0xffffffff);
LAB_001028b4:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar16 & 0xffffffff;
LAB_00100cf4:
  lVar28 = uVar19 + 1;
  goto LAB_00100cf8;
}



//------------------------------------------------------------
// attr_show @ 00102978 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1029a4);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 001029c0 size=68
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
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1029ec);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_sample_ms @ 00102a08 size=60
// signature: undefined show_sample_ms(void)
// callers: []
//------------------------------------------------------------

long show_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(memlat_data + 0xb0));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_sample_ms @ 00102a48 size=192
// signature: undefined store_sample_ms(void)
// callers: []
//------------------------------------------------------------

long store_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  if (iVar3 < 0) {
    param_4 = (long)iVar3;
  }
  else {
    if (local_2c < 5) {
      local_2c = 4;
    }
    if (999 < local_2c) {
      local_2c = 1000;
    }
    plVar1 = (long *)(memlat_data + 0x158);
    *(uint *)(memlat_data + 0xb0) = local_2c;
    if ((*plVar1 != 0) && (iVar3 = update_cpucp_sample_ms(), iVar3 < 0)) {
      _printk(&DAT_00106a5f,iVar3);
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
// update_cpucp_sample_ms @ 00102b08 size=312
// signature: undefined update_cpucp_sample_ms(void)
// callers: [store_cpucp_sample_ms, store_sample_ms]
//------------------------------------------------------------

int update_cpucp_sample_ms(undefined4 param_1)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = param_1;
  if (*(undefined8 **)(memlat_data + 0x158) == (undefined8 *)0x0) {
    iVar2 = -0x13;
  }
  else if ((((*(long *)(memlat_data + 0x110) == 0) ||
            (*(char *)(*(long *)(memlat_data + 0x110) + 0x1c) == '\0')) &&
           ((*(long *)(memlat_data + 0x118) == 0 ||
            (*(char *)(*(long *)(memlat_data + 0x118) + 0x1c) == '\0')))) &&
          ((((*(long *)(memlat_data + 0x120) == 0 ||
             (*(char *)(*(long *)(memlat_data + 0x120) + 0x1c) == '\0')) &&
            ((*(long *)(memlat_data + 0x128) == 0 ||
             (*(char *)(*(long *)(memlat_data + 0x128) + 0x1c) == '\0')))) &&
           (((*(long *)(memlat_data + 0x130) == 0 ||
             (*(char *)(*(long *)(memlat_data + 0x130) + 0x1c) == '\0')) &&
            ((*(long *)(memlat_data + 0x138) == 0 ||
             (*(char *)(*(long *)(memlat_data + 0x138) + 0x1c) == '\0')))))))) {
    iVar2 = 0;
  }
  else {
    pcVar3 = (code *)**(undefined8 **)(memlat_data + 0x158);
    if (*(int *)(pcVar3 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102bd4);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)(*(undefined8 *)(memlat_data + 0x160),&local_2c,0x4d454d4c4154,0x1f,4);
    if (iVar2 < 0) {
      _printk(&DAT_00106132,iVar2);
    }
    else {
      *(undefined4 *)(memlat_data + 0x168) = local_2c;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// show_cpucp_sample_ms @ 00102c44 size=60
// signature: undefined show_cpucp_sample_ms(void)
// callers: []
//------------------------------------------------------------

long show_cpucp_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105fe8,*(undefined4 *)(memlat_data + 0x168));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_cpucp_sample_ms @ 00102c84 size=160
// signature: undefined store_cpucp_sample_ms(void)
// callers: []
//------------------------------------------------------------

void store_cpucp_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  if (iVar2 < 0) {
    lVar3 = (long)iVar2;
  }
  else {
    if (local_2c < 5) {
      local_2c = 4;
    }
    if (999 < local_2c) {
      local_2c = 1000;
    }
    iVar2 = update_cpucp_sample_ms();
    lVar3 = (long)iVar2;
    if (-1 < iVar2) {
      lVar3 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// show_cpucp_log_level @ 00102d28 size=60
// signature: undefined show_cpucp_log_level(void)
// callers: []
//------------------------------------------------------------

long show_cpucp_log_level(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00105fe8,*(undefined4 *)(memlat_data + 0x16c));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_cpucp_log_level @ 00102d68 size=352
// signature: undefined store_cpucp_log_level(void)
// callers: []
//------------------------------------------------------------

long store_cpucp_log_level(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  puVar4 = *(undefined8 **)(memlat_data + 0x158);
  if (puVar4 == (undefined8 *)0x0) {
    param_4 = -0x13;
  }
  else if ((((*(long *)(memlat_data + 0x110) != 0) &&
            (*(char *)(*(long *)(memlat_data + 0x110) + 0x1c) != '\0')) ||
           ((*(long *)(memlat_data + 0x118) != 0 &&
            (*(char *)(*(long *)(memlat_data + 0x118) + 0x1c) != '\0')))) ||
          ((((*(long *)(memlat_data + 0x120) != 0 &&
             (*(char *)(*(long *)(memlat_data + 0x120) + 0x1c) != '\0')) ||
            ((*(long *)(memlat_data + 0x128) != 0 &&
             (*(char *)(*(long *)(memlat_data + 0x128) + 0x1c) != '\0')))) ||
           (((*(long *)(memlat_data + 0x130) != 0 &&
             (*(char *)(*(long *)(memlat_data + 0x130) + 0x1c) != '\0')) ||
            ((*(long *)(memlat_data + 0x138) != 0 &&
             (*(char *)(*(long *)(memlat_data + 0x138) + 0x1c) != '\0')))))))) {
    iVar2 = kstrtouint(param_3,10,&local_3c);
    if (iVar2 < 0) {
      param_4 = (long)iVar2;
    }
    else {
      pcVar3 = (code *)*puVar4;
      if (*(int *)(pcVar3 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102e54);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(*(undefined8 *)(memlat_data + 0x160),&local_3c,0x4d454d4c4154,3,4);
      if (iVar2 < 0) {
        _printk(&DAT_00106a94,iVar2);
        param_4 = (long)iVar2;
      }
      else {
        *(undefined4 *)(memlat_data + 0x16c) = local_3c;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_flush_cpucp_log @ 00102ecc size=48
// signature: undefined show_flush_cpucp_log(void)
// callers: []
//------------------------------------------------------------

long show_flush_cpucp_log(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"Echo here to flush cpucp logs\n");
  return (long)iVar1;
}



//------------------------------------------------------------
// store_flush_cpucp_log @ 00102f00 size=152
// signature: undefined store_flush_cpucp_log(void)
// callers: []
//------------------------------------------------------------

long store_flush_cpucp_log(void)

{
  int iVar1;
  long in_x3;
  code *pcVar2;
  
  if (*(undefined8 **)(memlat_data + 0x158) == (undefined8 *)0x0) {
    in_x3 = -0x13;
  }
  else {
    pcVar2 = (code *)**(undefined8 **)(memlat_data + 0x158);
    if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x102f5c);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),0,0x4d454d4c4154,4,0);
    if (iVar1 < 0) {
      _printk(&DAT_00106593,iVar1);
      in_x3 = (long)iVar1;
    }
  }
  return in_x3;
}



//------------------------------------------------------------
// show_hlos_cpucp_offset @ 00102f9c size=260
// signature: undefined show_hlos_cpucp_offset(void)
// callers: []
//------------------------------------------------------------

void show_hlos_cpucp_offset(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  code *pcVar5;
  long local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  if (*(long *)(memlat_data + 0x158) == 0) {
    lVar4 = -0x13;
  }
  else {
    pcVar5 = *(code **)(*(long *)(memlat_data + 0x158) + 8);
    if (*(int *)(pcVar5 + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x103010);
      (*pcVar5)();
    }
    iVar2 = (*pcVar5)(*(undefined8 *)(memlat_data + 0x160),&local_30,0x4d454d4c4154,0x26,0,8);
    if (iVar2 < 0) {
      _printk(&DAT_00106447);
      lVar4 = (long)iVar2;
    }
    else {
      uVar3 = sched_clock();
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106bde,local_30 - uVar3 / 1000);
      lVar4 = (long)iVar2;
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
// should_enable_memlat_fp @ 001030a0 size=176
// signature: undefined should_enable_memlat_fp(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

undefined8 should_enable_memlat_fp(void)

{
  if (*(int *)(memlat_data + 0x140) <= *(int *)(memlat_data + 0x144)) {
    if ((*(long *)(memlat_data + 0x110) != 0) &&
       (*(char *)(*(long *)(memlat_data + 0x110) + 0x30) != '\0')) {
      return 1;
    }
    if ((*(long *)(memlat_data + 0x118) != 0) &&
       (*(char *)(*(long *)(memlat_data + 0x118) + 0x30) != '\0')) {
      return 1;
    }
    if ((*(long *)(memlat_data + 0x120) != 0) &&
       (*(char *)(*(long *)(memlat_data + 0x120) + 0x30) != '\0')) {
      return 1;
    }
    if ((*(long *)(memlat_data + 0x128) != 0) &&
       (*(char *)(*(long *)(memlat_data + 0x128) + 0x30) != '\0')) {
      return 1;
    }
    if ((*(long *)(memlat_data + 0x130) != 0) &&
       (*(char *)(*(long *)(memlat_data + 0x130) + 0x30) != '\0')) {
      return 1;
    }
    if ((*(long *)(memlat_data + 0x138) != 0) &&
       (*(char *)(*(long *)(memlat_data + 0x138) + 0x30) != '\0')) {
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// show_sampling_cur_freq @ 00103154 size=56
// signature: undefined show_sampling_cur_freq(void)
// callers: []
//------------------------------------------------------------

long show_sampling_cur_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x70));
  return (long)iVar1;
}



//------------------------------------------------------------
// show_adaptive_cur_freq @ 00103190 size=252
// signature: undefined show_adaptive_cur_freq(void)
// callers: []
//------------------------------------------------------------

void show_adaptive_cur_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  if (*(char *)(param_1 + -0x74) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + -0x6c);
  }
  else {
    if (*(long *)(memlat_data + 0x158) == 0) {
      lVar4 = -0x13;
      goto LAB_00103248;
    }
    local_38 = *(undefined4 *)(param_1 + -0x80);
    pcVar5 = *(code **)(*(long *)(memlat_data + 0x158) + 8);
    uStack_34 = 0;
    if (*(int *)(pcVar5 + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x103214);
      (*pcVar5)();
    }
    iVar3 = (*pcVar5)(*(undefined8 *)(memlat_data + 0x160),&local_38,0x4d454d4c4154,0x16,0xc,4);
    if (iVar3 < 0) {
      _printk(&DAT_00106828);
      lVar4 = (long)iVar3;
      goto LAB_00103248;
    }
    uVar1 = local_38;
  }
  iVar3 = scnprintf(param_3,0x1000,&DAT_00105fe8,uVar1);
  lVar4 = (long)iVar3;
LAB_00103248:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// show_adaptive_high_freq @ 00103290 size=56
// signature: undefined show_adaptive_high_freq(void)
// callers: []
//------------------------------------------------------------

long show_adaptive_high_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x68));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_adaptive_high_freq @ 001032cc size=288
// signature: undefined store_adaptive_high_freq(void)
// callers: []
//------------------------------------------------------------

long store_adaptive_high_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined4 local_48;
  undefined4 local_44;
  uint uStack_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  puVar4 = *(undefined8 **)(memlat_data + 0x158);
  iVar2 = kstrtouint(param_3,10,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    if (7999999 < local_3c) {
      local_3c = 8000000;
    }
    *(uint *)(param_1 + -0x68) = local_3c;
    if ((*(char *)(param_1 + -0x74) != '\0') && (puVar4 != (undefined8 *)0x0)) {
      local_48 = *(undefined4 *)(param_1 + -0x80);
      local_44 = 0;
      pcVar3 = (code *)*puVar4;
      uStack_40 = local_3c;
      if (*(int *)(pcVar3 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x103390);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(*(undefined8 *)(memlat_data + 0x160),&local_48,0x4d454d4c4154,0x15,0xc);
      if (iVar2 < 0) {
        _printk(&DAT_001066e5,iVar2);
        param_4 = (long)iVar2;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_adaptive_low_freq @ 001033f0 size=56
// signature: undefined show_adaptive_low_freq(void)
// callers: []
//------------------------------------------------------------

long show_adaptive_low_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -100));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_adaptive_low_freq @ 0010342c size=288
// signature: undefined store_adaptive_low_freq(void)
// callers: []
//------------------------------------------------------------

long store_adaptive_low_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined4 local_48;
  undefined4 local_44;
  uint uStack_40;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  puVar4 = *(undefined8 **)(memlat_data + 0x158);
  iVar2 = kstrtouint(param_3,10,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    if (7999999 < local_3c) {
      local_3c = 8000000;
    }
    *(uint *)(param_1 + -100) = local_3c;
    if ((*(char *)(param_1 + -0x74) != '\0') && (puVar4 != (undefined8 *)0x0)) {
      local_48 = *(undefined4 *)(param_1 + -0x80);
      local_44 = 0;
      pcVar3 = (code *)*puVar4;
      uStack_40 = local_3c;
      if (*(int *)(pcVar3 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1034f0);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(*(undefined8 *)(memlat_data + 0x160),&local_48,0x4d454d4c4154,0x14,0xc);
      if (iVar2 < 0) {
        _printk(&DAT_001066e5,iVar2);
        param_4 = (long)iVar2;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// get_mpidr_cpu @ 00103550 size=16
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
// memlat_update_work @ 00103564 size=1912
// signature: undefined memlat_update_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void memlat_update_work(void)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  uint *puVar16;
  uint uVar17;
  long lVar18;
  uint uVar19;
  long lVar20;
  ulong uVar21;
  undefined8 *puVar22;
  long lVar23;
  long lVar24;
  ulong local_f8;
  undefined4 local_f0;
  uint local_e8 [12];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar24 = sp_el0;
  lVar20 = 0;
  local_70 = *(long *)(lVar24 + 0x638);
  uVar5 = sp_el0;
  local_f0 = 0;
  local_f8 = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_e8[0] = 0;
  local_e8[1] = 0;
  do {
    lVar24 = *(long *)(memlat_data + lVar20 * 8 + 0x110);
    if (lVar24 != 0) {
      uVar10 = *(uint *)(lVar24 + 0x5c);
      if (uVar10 != 0) {
        uVar11 = 0;
        do {
          lVar23 = *(long *)(lVar24 + 0x50);
          if ((lVar23 + (long)(int)uVar11 * 200 != 0) &&
             ((*(byte *)(lVar23 + (long)(int)uVar11 * 200 + 0x10) & 1) != 0)) {
            lVar18 = lVar23 + (long)(int)uVar11 * 200;
            lVar13 = lVar18 + 0x18;
            uVar8 = _find_first_bit(lVar13,_nr_cpu_ids);
            uVar10 = *(uint *)(*(long *)(lVar18 + 8) + 0x10);
            if (uVar10 < 6) {
              lVar18 = lVar23 + (long)(int)uVar11 * 200;
              uVar19 = 0;
              iVar12 = 0;
              while (uVar9 = _find_next_bit(lVar13,_nr_cpu_ids,(long)iVar12), uVar9 < _nr_cpu_ids) {
                if ((uVar9 & 0xffffffe0) != 0) goto LAB_00103dcc;
                lVar15 = *(long *)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)uVar9 * 8)
                                  );
                if ((*(char *)(lVar18 + 0xc0) == '\0') &&
                   ((lVar1 = lVar15 + (ulong)uVar10 * 4, uVar2 = *(uint *)(lVar1 + 0x2a0),
                    *(uint *)(lVar1 + 0x2b8) < *(uint *)(lVar18 + 0x44) ||
                    (*(uint *)(lVar18 + 0x48) < uVar2)))) {
                  uVar3 = *(uint *)(lVar18 + 0x2c);
                  uVar17 = uVar8;
                  if (uVar2 <= uVar3) {
                    uVar14 = *(uint *)(lVar15 + 0x294);
                    if ((((*(int *)(lVar18 + 0x38) != 0) && (*(uint *)(lVar18 + 0x40) < uVar14)) &&
                        (uVar17 = *(uint *)(lVar18 + 0x3c), uVar14 < uVar17)) &&
                       ((*(uint *)(lVar18 + 0x30) <= *(uint *)(lVar15 + 0x298) ||
                        (*(uint *)(lVar18 + 0x34) <= *(uint *)(lVar15 + 0x29c))))) {
                      uVar4 = 0;
                      if (uVar3 * 100 != 0) {
                        uVar4 = (uVar14 * (uVar3 - uVar2) * *(int *)(lVar18 + 0x38)) / (uVar3 * 100)
                        ;
                      }
                      uVar4 = uVar4 + uVar14;
                      uVar14 = uVar17;
                      if (uVar4 <= uVar17) {
                        uVar14 = uVar4;
                      }
                    }
                    goto LAB_001036d0;
                  }
                }
                else {
                  uVar14 = *(uint *)(lVar15 + 0x294);
LAB_001036d0:
                  uVar17 = uVar9;
                  if (uVar14 <= uVar19) {
                    uVar17 = uVar8;
                  }
                  if (uVar19 <= uVar14) {
                    uVar19 = uVar14;
                  }
                }
                iVar12 = uVar9 + 1;
                uVar8 = uVar17;
              }
              lVar13 = *(long *)(lVar23 + (long)(int)uVar11 * 200 + 0x20);
              if (lVar13 == 0) {
                uVar9 = 0;
              }
              else {
                lVar13 = lVar13 + -4;
                do {
                  uVar10 = *(uint *)(lVar13 + 4);
                  lVar13 = lVar13 + 8;
                  if (uVar10 == 0) break;
                } while (uVar10 < uVar19);
                lVar18 = -8;
                if (uVar10 != 0) {
                  lVar18 = 0;
                }
                uVar9 = *(uint *)(lVar13 + lVar18);
              }
              lVar13 = lVar23 + (long)(int)uVar11 * 200;
              uVar10 = *(uint *)(lVar13 + 0x4c);
              uVar2 = *(uint *)(lVar13 + 0x50);
              if (uVar9 <= uVar10) {
                uVar9 = uVar10;
              }
              if (uVar2 <= uVar9) {
                uVar9 = uVar2;
              }
              if (((uVar19 != 0) || (*(uint *)(lVar23 + (long)(int)uVar11 * 200 + 0x5c) != uVar10))
                 && (0x1f < uVar8)) {
LAB_00103dcc:
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x103dd0);
                (*pcVar7)();
              }
              *(uint *)(lVar23 + (long)(int)uVar11 * 200 + 0x5c) = uVar9;
            }
            else {
              uVar9 = *(uint *)(lVar23 + (long)(int)uVar11 * 200 + 0x5c);
            }
            if (uVar9 <= local_e8[lVar20]) {
              uVar9 = local_e8[lVar20];
            }
            uVar10 = *(uint *)(lVar24 + 0x5c);
            local_e8[lVar20] = uVar9;
          }
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar10);
      }
      uVar10 = *(uint *)(lVar24 + 0x28);
      uVar11 = *(uint *)(lVar24 + 0x2c);
      if (uVar10 == 0 && uVar11 == 0) {
        if (*(int *)(lVar24 + 0x24) != 0) {
          puVar16 = local_e8 + lVar20;
          uVar8 = *puVar16;
          goto LAB_00103968;
        }
      }
      else {
        puVar16 = local_e8 + lVar20;
        uVar8 = *puVar16;
        if (uVar8 < uVar11) {
          *puVar16 = uVar11;
          uVar10 = uVar11;
        }
        else {
LAB_00103968:
          if (uVar8 < uVar10) {
            *puVar16 = uVar10;
          }
        }
        *(uint *)(lVar24 + 0x24) = uVar10;
      }
    }
    lVar20 = lVar20 + 1;
    if (lVar20 == 6) {
      uVar10 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
      local_80 = 0;
      uStack_78 = 0;
      if (uVar10 < 9) {
        uVar10 = 8;
      }
      local_90 = 0;
      local_88 = 0;
      local_a0 = 0;
      local_98 = 0;
      local_b0 = 0;
      uStack_a8 = 0;
      local_e8[10] = 0;
      local_e8[0xb] = 0;
      local_b8 = 0;
      local_e8[6] = 0;
      local_e8[7] = 0;
      local_e8[8] = 0;
      local_e8[9] = 0;
      if (*(char *)(memlat_data + 0x150) != '\0') {
        uVar11 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
        if (uVar11 < 9) {
          uVar11 = 8;
        }
        if (uVar10 <= uVar11 + 1) {
          uVar6 = daif;
          if ((uVar6 & 0x80) == 0) {
            uVar21 = daif;
            daif = uVar21 | 0xc0;
          }
          _raw_spin_lock(memlat_data + 0x148);
          uVar21 = 0;
          uVar11 = 0;
          do {
            lVar20 = *(long *)(memlat_data + uVar21 * 8 + 0x110);
            if ((lVar20 != 0) && (*(char *)(lVar20 + 0x30) != '\0')) {
              uVar8 = 0;
              *(uint *)(*(long *)(lVar20 + 0x38) + (long)(int)uVar10 * 4) = local_e8[uVar21];
              while( true ) {
                uVar9 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
                if (uVar9 < 9) {
                  uVar9 = 8;
                }
                if (uVar9 + 1 <= uVar8) break;
                uVar9 = *(uint *)(*(long *)(lVar20 + 0x38) + (long)(int)uVar8 * 4);
                uVar8 = uVar8 + 1;
                if (uVar9 <= local_e8[uVar21 + 6]) {
                  uVar9 = local_e8[uVar21 + 6];
                }
                local_e8[uVar21 + 6] = uVar9;
              }
              if (local_e8[uVar21 + 6] != *(uint *)(lVar20 + 0x34)) {
                uVar11 = uVar11 | (uint)(1L << (uVar21 & 0x3f));
              }
            }
            uVar21 = uVar21 + 1;
          } while (uVar21 != 6);
          if (uVar11 == 0) {
            _raw_spin_unlock(memlat_data + 0x148);
            daif = uVar6;
          }
          else {
            _raw_spin_lock(memlat_data + 0x14c);
            lVar20 = memlat_data;
            if ((uVar11 & 1) != 0) {
              *(uint *)(*(long *)(memlat_data + 0x110) + 0x34) = local_e8[6];
            }
            if ((uVar11 >> 1 & 1) != 0) {
              *(uint *)(*(long *)(lVar20 + 0x118) + 0x34) = local_e8[7];
            }
            if ((uVar11 >> 2 & 1) != 0) {
              *(uint *)(*(long *)(lVar20 + 0x120) + 0x34) = local_e8[8];
            }
            if ((uVar11 >> 3 & 1) != 0) {
              *(uint *)(*(long *)(lVar20 + 0x128) + 0x34) = local_e8[9];
            }
            if ((uVar11 >> 4 & 1) != 0) {
              *(uint *)(*(long *)(lVar20 + 0x130) + 0x34) = local_e8[10];
            }
            if ((uVar11 >> 5 & 1) != 0) {
              *(uint *)(*(long *)(lVar20 + 0x138) + 0x34) = local_e8[0xb];
            }
            _raw_spin_unlock(lVar20 + 0x148);
            if ((uVar11 & 1) != 0) {
              local_b0 = local_b0 & 0xffffffff00000000;
              local_b8 = CONCAT44(local_b8._4_4_,local_e8[6]);
            }
            if ((uVar11 >> 1 & 1) != 0) {
              local_b0 = CONCAT44(local_e8[7],(undefined4)local_b0);
              uStack_a8 = CONCAT44(1,(undefined4)uStack_a8);
            }
            if ((uVar11 >> 2 & 1) != 0) {
              local_a0 = CONCAT44(local_a0._4_4_,local_e8[8]);
              local_98 = CONCAT44(local_98._4_4_,2);
            }
            if ((uVar11 >> 3 & 1) != 0) {
              local_98 = CONCAT44(local_e8[9],(undefined4)local_98);
              local_90 = CONCAT44(3,(undefined4)local_90);
            }
            if ((uVar11 >> 4 & 1) != 0) {
              local_88 = CONCAT44(local_88._4_4_,local_e8[10]);
              local_80 = CONCAT44(local_80._4_4_,4);
            }
            if ((uVar11 >> 5 & 1) != 0) {
              local_80 = CONCAT44(local_e8[0xb],(undefined4)local_80);
              uStack_78 = CONCAT44(5,(undefined4)uStack_78);
            }
            iVar12 = qcom_dcvs_update_votes("memlat_fp",&local_b8,uVar11,1);
            if (iVar12 < 0) {
              _printk(&DAT_001069d6,iVar12);
            }
            _raw_spin_unlock(memlat_data + 0x14c);
            daif = uVar6;
          }
        }
      }
      lVar20 = 0;
      do {
        puVar22 = *(undefined8 **)(memlat_data + lVar20 * 8 + 0x110);
        if ((((puVar22 != (undefined8 *)0x0) &&
             (uVar10 = local_e8[lVar20], *(uint *)(puVar22 + 4) != uVar10)) &&
            (*(int *)((long)puVar22 + 0x14) != 3)) &&
           (*(uint *)(puVar22 + 4) = uVar10, *(char *)(puVar22 + 6) == '\0')) {
          local_f8 = (ulong)uVar10;
          local_f0 = (undefined4)lVar20;
          lVar24 = ((long *)*puVar22)[0xe];
          if (lVar24 == 0) {
            lVar24 = *(long *)*puVar22;
          }
          iVar12 = qcom_dcvs_update_votes(lVar24,&local_f8,1);
          if (iVar12 < 0) {
            _dev_err(*puVar22,"qcom dcvs err: %d\n",iVar12);
          }
        }
        lVar20 = lVar20 + 1;
      } while (lVar20 != 6);
      lVar20 = sp_el0;
      if (*(long *)(lVar20 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// memlat_hrtimer_handler @ 00103de0 size=1012
// signature: undefined memlat_hrtimer_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 memlat_hrtimer_handler(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  code *pcVar4;
  uint uVar5;
  long lVar6;
  long *__dest;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  ulong *puVar14;
  long lVar15;
  
  lVar6 = ktime_get();
  lVar8 = *(long *)(memlat_data + 0x100);
  *(long *)(memlat_data + 0x100) = lVar6;
  uVar3 = daif;
  if ((uVar3 & 0x80) == 0) {
    uVar7 = daif;
    daif = uVar7 | 0xc0;
  }
  iVar10 = 0;
  while (uVar5 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar10), uVar5 < _nr_cpu_ids)
  {
    if ((uVar5 & 0xffffffe0) != 0) goto LAB_00104258;
    _raw_spin_lock(*(long *)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)uVar5 * 8)) +
                   0x290);
    iVar10 = uVar5 + 1;
  }
  iVar10 = 0;
  uVar2 = sp_el0;
  while (uVar5 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar10), uVar5 < _nr_cpu_ids)
  {
    if ((uVar5 & 0xffffffe0) != 0) goto LAB_00104258;
    __dest = *(long **)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)uVar5 * 8));
    if ((char)__dest[0x4f] == '\0') {
      lVar15 = __dest[0x51];
      __dest[0x51] = __dest[0x50];
      lVar15 = __dest[0x50] - lVar15;
    }
    else {
      __dest[0x51] = lVar6;
      lVar15 = lVar6 - lVar8;
    }
    lVar11 = memlat_data;
    if (*(int *)(memlat_data + 0x68) != 0) {
      __dest[0x2c] = __dest[0x16] - *__dest;
    }
    if (*(int *)(lVar11 + 0x6c) != 0) {
      __dest[0x2d] = __dest[0x17] - __dest[1];
      lVar11 = memlat_data;
    }
    if (*(int *)(lVar11 + 0x70) != 0) {
      __dest[0x2e] = __dest[0x18] - __dest[2];
      lVar11 = memlat_data;
    }
    if (*(int *)(lVar11 + 0x74) != 0) {
      __dest[0x2f] = __dest[0x19] - __dest[3];
    }
    plVar9 = __dest + 0x1a;
    lVar11 = 0x110;
    do {
      lVar13 = *(long *)(memlat_data + lVar11);
      if (lVar13 != 0) {
        if (*(int *)(lVar13 + 0x40) != 0) {
          plVar9[0x16] = *plVar9 - plVar9[-0x16];
        }
        if (*(int *)(lVar13 + 0x44) != 0) {
          plVar9[0x17] = plVar9[1] - plVar9[-0x15];
        }
        if (*(int *)(lVar13 + 0x48) != 0) {
          plVar9[0x18] = plVar9[2] - plVar9[-0x14];
        }
      }
      lVar13 = memlat_data;
      lVar11 = lVar11 + 8;
      plVar9 = plVar9 + 3;
    } while (lVar11 != 0x140);
    uVar7 = __dest[0x2d];
    uVar1 = 0;
    if (lVar15 / 1000 != 0) {
      uVar1 = (undefined4)(uVar7 / (ulong)(lVar15 / 1000));
    }
    *(undefined4 *)((long)__dest + 0x294) = uVar1;
    if (*(int *)(lVar13 + 0x70) == 0) {
      iVar10 = 100;
    }
    else {
      uVar12 = 0;
      if (uVar7 != 0) {
        uVar12 = 100 / uVar7;
      }
      iVar10 = 0;
      if (uVar7 != 0) {
        iVar10 = (int)((__dest[0x2e] * (100 - uVar12 * uVar7)) / uVar7);
      }
      iVar10 = iVar10 + (int)__dest[0x2e] * (int)uVar12;
    }
    *(int *)(__dest + 0x53) = iVar10;
    if (*(int *)(lVar13 + 0x74) == 0) {
      iVar10 = 100;
    }
    else {
      uVar12 = 0;
      if (uVar7 != 0) {
        uVar12 = 100 / uVar7;
      }
      iVar10 = 0;
      if (uVar7 != 0) {
        iVar10 = (int)((__dest[0x2f] * (100 - uVar12 * uVar7)) / uVar7);
      }
      iVar10 = iVar10 + (int)__dest[0x2f] * (int)uVar12;
    }
    plVar9 = __dest + 0x54;
    puVar14 = (ulong *)(__dest + 0x30);
    lVar15 = 0x110;
    *(int *)((long)__dest + 0x29c) = iVar10;
    do {
      lVar11 = *(long *)(memlat_data + lVar15);
      if (lVar11 == 0) {
        *(undefined4 *)plVar9 = 0;
        *(undefined4 *)(plVar9 + 3) = 0;
      }
      else {
        uVar7 = __dest[0x2c];
        *(int *)plVar9 = (int)uVar7;
        uVar12 = *puVar14;
        if (uVar12 != 0) {
          uVar1 = 0;
          if (uVar12 != 0) {
            uVar1 = (undefined4)((uVar7 & 0xffffffff) / uVar12);
          }
          *(undefined4 *)plVar9 = uVar1;
        }
        if ((*(int *)(lVar11 + 0x44) == 0) || (*(int *)(lVar11 + 0x48) == 0)) {
          iVar10 = 0;
        }
        else {
          uVar7 = puVar14[2];
          uVar12 = 0;
          if (uVar7 != 0) {
            uVar12 = 100 / uVar7;
          }
          iVar10 = 0;
          if (uVar7 != 0) {
            iVar10 = (int)((puVar14[1] * (100 - uVar12 * uVar7)) / uVar7);
          }
          iVar10 = iVar10 + (int)puVar14[1] * (int)uVar12;
        }
        *(int *)(plVar9 + 3) = iVar10;
      }
      lVar15 = lVar15 + 8;
      plVar9 = (long *)((long)plVar9 + 4);
      puVar14 = puVar14 + 3;
    } while (lVar15 != 0x140);
    memcpy(__dest,__dest + 0x16,0xb0);
    iVar10 = uVar5 + 1;
  }
  iVar10 = 0;
  while( true ) {
    uVar5 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar10);
    if (_nr_cpu_ids <= uVar5) {
      daif = uVar3;
      queue_work_on(0x20,*(undefined8 *)(memlat_data + 0xa8),memlat_data + 0x78);
      return 0;
    }
    if ((uVar5 & 0xffffffe0) != 0) break;
    _raw_spin_unlock(*(long *)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)uVar5 * 8)) +
                     0x290);
    iVar10 = uVar5 + 1;
  }
LAB_00104258:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10425c);
  (*pcVar4)();
}



//------------------------------------------------------------
// memlat_sched_tick_cb @ 00104268 size=260
// signature: undefined memlat_sched_tick_cb(void)
// callers: []
//------------------------------------------------------------

void memlat_sched_tick_cb(void)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar4 = tpidr_el1;
  uVar1 = *(uint *)(&cpu_number + lVar4);
  if (0x1f < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10436c);
    (*pcVar2)();
  }
  lVar6 = *(long *)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)uVar1 * 8));
  lVar4 = ktime_get();
  if (*(char *)(memlat_data + 0x152) != '\0') {
    uVar5 = _raw_spin_lock_irqsave(lVar6 + 0x290);
    if ((long)((ulong)*(uint *)(memlat_data + 0xb0) * 1000000) <=
        (lVar4 - *(long *)(lVar6 + 0x288)) + 2000000) {
      *(long *)(lVar6 + 0x280) = lVar4;
      *(undefined1 *)(lVar6 + 0x278) = 0;
      *(undefined4 *)(lVar6 + 0x270) = 0;
      iVar3 = qcom_pmu_read_all_local(lVar6 + 0x210);
      if ((iVar3 < 0) || (*(int *)(lVar6 + 0x270) == 0)) {
        _printk(&DAT_00106901,uVar1,iVar3);
      }
      else {
        process_raw_ctrs(lVar6);
      }
    }
    _raw_spin_unlock_irqrestore(lVar6 + 0x290,uVar5);
  }
  return;
}



//------------------------------------------------------------
// memlat_jiffies_update_cb @ 00104370 size=128
// signature: undefined memlat_jiffies_update_cb(void)
// callers: []
//------------------------------------------------------------

void memlat_jiffies_update_cb(void)

{
  long lVar1;
  
  lVar1 = ktime_get();
  if ((*(char *)(memlat_data + 0x152) != '\0') &&
     ((long)((ulong)*(uint *)(memlat_data + 0xb0) * 1000000) <
      (lVar1 - *(long *)(memlat_data + 0x108)) + 2000000)) {
    hrtimer_start_range_ns(memlat_data + 0xb8,100000,0,3);
    *(long *)(memlat_data + 0x108) = lVar1;
  }
  return;
}



//------------------------------------------------------------
// process_raw_ctrs @ 001043f0 size=604
// signature: undefined process_raw_ctrs(void)
// callers: [memlat_sched_tick_cb, memlat_pmu_idle_cb]
//------------------------------------------------------------

void process_raw_ctrs(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  long lVar8;
  
  lVar3 = memlat_data;
  uVar1 = *(uint *)(param_1 + 0x270);
  if (uVar1 != 0) {
    lVar5 = 0;
    do {
      if ((int)lVar5 == 8) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10464c);
        (*pcVar4)();
      }
      iVar2 = *(int *)(param_1 + 0x230 + lVar5 * 4 + -0x20);
      if (iVar2 == 0) {
        return;
      }
      uVar6 = *(undefined8 *)(param_1 + 0x230 + lVar5 * 8);
      if (iVar2 == *(int *)(lVar3 + 0x68)) {
        puVar7 = (undefined8 *)(param_1 + 0xb0);
LAB_00104634:
        *puVar7 = uVar6;
      }
      else {
        if (iVar2 == *(int *)(lVar3 + 0x6c)) {
          puVar7 = (undefined8 *)(param_1 + 0xb8);
          goto LAB_00104634;
        }
        if (iVar2 == *(int *)(lVar3 + 0x70)) {
          puVar7 = (undefined8 *)(param_1 + 0xc0);
          goto LAB_00104634;
        }
        if (iVar2 == *(int *)(lVar3 + 0x74)) {
          puVar7 = (undefined8 *)(param_1 + 200);
          goto LAB_00104634;
        }
        lVar8 = *(long *)(lVar3 + 0x110);
        if (lVar8 != 0) {
          if (iVar2 == *(int *)(lVar8 + 0x40)) {
            lVar8 = 0;
          }
          else if (iVar2 == *(int *)(lVar8 + 0x44)) {
            lVar8 = 1;
          }
          else {
            if (iVar2 != *(int *)(lVar8 + 0x48)) goto LAB_001044cc;
            lVar8 = 2;
          }
          *(undefined8 *)(param_1 + lVar8 * 8 + 0xd0) = uVar6;
        }
LAB_001044cc:
        lVar8 = *(long *)(lVar3 + 0x118);
        if (lVar8 != 0) {
          if (iVar2 == *(int *)(lVar8 + 0x40)) {
            lVar8 = 0;
          }
          else if (iVar2 == *(int *)(lVar8 + 0x44)) {
            lVar8 = 1;
          }
          else {
            if (iVar2 != *(int *)(lVar8 + 0x48)) goto LAB_00104514;
            lVar8 = 2;
          }
          *(undefined8 *)(param_1 + lVar8 * 8 + 0xe8) = uVar6;
        }
LAB_00104514:
        lVar8 = *(long *)(lVar3 + 0x120);
        if (lVar8 != 0) {
          if (iVar2 == *(int *)(lVar8 + 0x40)) {
            lVar8 = 0;
          }
          else if (iVar2 == *(int *)(lVar8 + 0x44)) {
            lVar8 = 1;
          }
          else {
            if (iVar2 != *(int *)(lVar8 + 0x48)) goto LAB_0010455c;
            lVar8 = 2;
          }
          *(undefined8 *)(param_1 + lVar8 * 8 + 0x100) = uVar6;
        }
LAB_0010455c:
        lVar8 = *(long *)(lVar3 + 0x128);
        if (lVar8 != 0) {
          if (iVar2 == *(int *)(lVar8 + 0x40)) {
            lVar8 = 0;
          }
          else if (iVar2 == *(int *)(lVar8 + 0x44)) {
            lVar8 = 1;
          }
          else {
            if (iVar2 != *(int *)(lVar8 + 0x48)) goto LAB_001045a4;
            lVar8 = 2;
          }
          *(undefined8 *)(param_1 + lVar8 * 8 + 0x118) = uVar6;
        }
LAB_001045a4:
        lVar8 = *(long *)(lVar3 + 0x130);
        if (lVar8 != 0) {
          if (iVar2 == *(int *)(lVar8 + 0x40)) {
            lVar8 = 0;
          }
          else if (iVar2 == *(int *)(lVar8 + 0x44)) {
            lVar8 = 1;
          }
          else {
            if (iVar2 != *(int *)(lVar8 + 0x48)) goto LAB_001045ec;
            lVar8 = 2;
          }
          *(undefined8 *)(param_1 + lVar8 * 8 + 0x130) = uVar6;
        }
LAB_001045ec:
        lVar8 = *(long *)(lVar3 + 0x138);
        if (lVar8 != 0) {
          if (iVar2 == *(int *)(lVar8 + 0x40)) {
            lVar8 = 0;
          }
          else if (iVar2 == *(int *)(lVar8 + 0x44)) {
            lVar8 = 1;
          }
          else {
            if (iVar2 != *(int *)(lVar8 + 0x48)) goto LAB_00104638;
            lVar8 = 2;
          }
          puVar7 = (undefined8 *)(param_1 + lVar8 * 8 + 0x148);
          goto LAB_00104634;
        }
      }
LAB_00104638:
      lVar5 = lVar5 + 1;
    } while ((uint)lVar5 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// memlat_pmu_idle_cb @ 00104650 size=220
// signature: undefined memlat_pmu_idle_cb(void)
// callers: []
//------------------------------------------------------------

void memlat_pmu_idle_cb(undefined8 *param_1,uint param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (0x1f < param_2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10472c);
    (*pcVar4)();
  }
  if (*(char *)(memlat_data + 0x152) != '\0') {
    lVar6 = *(long *)(&sampling_stats + *(long *)(&__per_cpu_offset + (ulong)param_2 * 8));
    uVar5 = _raw_spin_lock_irqsave(lVar6 + 0x290);
    *(undefined8 *)(lVar6 + 0x210) = *param_1;
    uVar2 = param_1[2];
    uVar1 = param_1[3];
    uVar3 = param_1[4];
    *(undefined8 *)(lVar6 + 0x218) = param_1[1];
    *(undefined8 *)(lVar6 + 0x220) = uVar2;
    *(undefined8 *)(lVar6 + 0x228) = uVar1;
    *(undefined8 *)(lVar6 + 0x230) = uVar3;
    uVar2 = param_1[6];
    uVar1 = param_1[7];
    uVar3 = param_1[8];
    *(undefined8 *)(lVar6 + 0x238) = param_1[5];
    *(undefined8 *)(lVar6 + 0x240) = uVar2;
    *(undefined8 *)(lVar6 + 0x248) = uVar1;
    *(undefined8 *)(lVar6 + 0x250) = uVar3;
    uVar2 = param_1[10];
    uVar1 = param_1[0xb];
    uVar3 = param_1[0xc];
    *(undefined8 *)(lVar6 + 600) = param_1[9];
    *(undefined8 *)(lVar6 + 0x260) = uVar2;
    *(undefined8 *)(lVar6 + 0x268) = uVar1;
    *(undefined8 *)(lVar6 + 0x270) = uVar3;
    process_raw_ctrs(lVar6);
    *(undefined1 *)(lVar6 + 0x278) = 1;
    _raw_spin_unlock_irqrestore(lVar6 + 0x290,uVar5);
  }
  return;
}



//------------------------------------------------------------
// show_min_freq @ 00104730 size=56
// signature: undefined show_min_freq(void)
// callers: []
//------------------------------------------------------------

long show_min_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x14));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_min_freq @ 0010476c size=308
// signature: undefined store_min_freq(void)
// callers: []
//------------------------------------------------------------

long store_min_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (local_4c <= *(uint *)(param_1 + -0xc)) {
      local_4c = *(uint *)(param_1 + -0xc);
    }
    if (*(uint *)(param_1 + -0x10) <= local_4c) {
      local_4c = *(uint *)(param_1 + -0x10);
    }
    *(uint *)(param_1 + -0x14) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x104840);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x21,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a06,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_max_freq @ 001048a4 size=56
// signature: undefined show_max_freq(void)
// callers: []
//------------------------------------------------------------

long show_max_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x10));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_max_freq @ 001048e0 size=312
// signature: undefined store_max_freq(void)
// callers: []
//------------------------------------------------------------

long store_max_freq(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (local_4c <= *(uint *)(param_1 + -0x14)) {
      local_4c = *(uint *)(param_1 + -0x14);
    }
    if (*(uint *)(param_1 + -8) <= local_4c) {
      local_4c = *(uint *)(param_1 + -8);
    }
    *(uint *)(param_1 + -0x10) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x1049b8);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x22,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00105fac,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_freq_map @ 00104a1c size=216
// signature: undefined show_freq_map(void)
// callers: []
//------------------------------------------------------------

ulong show_freq_map(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + -0x40);
  uVar1 = scnprintf(param_3,0x1000,"CPU freq (MHz)\tMem freq (kHz)\n");
  iVar2 = *piVar4;
  while( true ) {
    uVar3 = (ulong)uVar1;
    if ((iVar2 == 0) || (0xfff < uVar1)) break;
    iVar2 = scnprintf(param_3 + uVar3,0x1000 - uVar3,"%14u\t%14u\n",iVar2,piVar4[1]);
    uVar1 = iVar2 + uVar1;
    iVar2 = piVar4[2];
    piVar4 = piVar4 + 2;
  }
  if (uVar1 < 0x1000) {
    iVar2 = scnprintf(param_3 + uVar3,0x1000 - uVar3,&DAT_00106939);
    uVar3 = (ulong)(iVar2 + uVar1);
  }
  return uVar3;
}



//------------------------------------------------------------
// show_cur_freq @ 00104af8 size=260
// signature: undefined show_cur_freq(void)
// callers: []
//------------------------------------------------------------

void show_cur_freq(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  if (*(char *)(*(long *)(param_1 + -0x58) + 0x1c) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + -4);
  }
  else {
    if (*(long *)(memlat_data + 0x158) == 0) {
      lVar4 = -0x13;
      goto LAB_00104bb8;
    }
    local_38 = *(undefined4 *)(*(long *)(param_1 + -0x58) + 0x10);
    uStack_34 = *(undefined4 *)(param_1 + 100);
    pcVar5 = *(code **)(*(long *)(memlat_data + 0x158) + 8);
    if (*(int *)(pcVar5 + -4) != -0x5012a6d9) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x104b84);
      (*pcVar5)();
    }
    iVar3 = (*pcVar5)(*(undefined8 *)(memlat_data + 0x160),&local_38,0x4d454d4c4154,0x23,0xc,4);
    if (iVar3 < 0) {
      _printk(&DAT_00106c06);
      lVar4 = (long)iVar3;
      goto LAB_00104bb8;
    }
    uVar1 = local_38;
  }
  iVar3 = scnprintf(param_3,0x1000,&DAT_00105fe8,uVar1);
  lVar4 = (long)iVar3;
LAB_00104bb8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// show_ipm_ceil @ 00104c00 size=56
// signature: undefined show_ipm_ceil(void)
// callers: []
//------------------------------------------------------------

long show_ipm_ceil(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x34));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_ipm_ceil @ 00104c3c size=308
// signature: undefined store_ipm_ceil(void)
// callers: []
//------------------------------------------------------------

long store_ipm_ceil(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (local_4c < 2) {
      local_4c = 1;
    }
    if (49999 < local_4c) {
      local_4c = 50000;
    }
    *(uint *)(param_1 + -0x34) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x104d10);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x17,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_fe_stall_floor @ 00104d74 size=56
// signature: undefined show_fe_stall_floor(void)
// callers: []
//------------------------------------------------------------

long show_fe_stall_floor(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_fe_stall_floor @ 00104db0 size=300
// signature: undefined store_fe_stall_floor(void)
// callers: []
//------------------------------------------------------------

long store_fe_stall_floor(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (99 < local_4c) {
      local_4c = 100;
    }
    *(uint *)(param_1 + -0x30) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x104e7c);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x18,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_be_stall_floor @ 00104ee0 size=56
// signature: undefined show_be_stall_floor(void)
// callers: []
//------------------------------------------------------------

long show_be_stall_floor(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x2c));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_be_stall_floor @ 00104f1c size=300
// signature: undefined store_be_stall_floor(void)
// callers: []
//------------------------------------------------------------

long store_be_stall_floor(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (99 < local_4c) {
      local_4c = 100;
    }
    *(uint *)(param_1 + -0x2c) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x104fe8);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x19,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_freq_scale_pct @ 0010504c size=56
// signature: undefined show_freq_scale_pct(void)
// callers: []
//------------------------------------------------------------

long show_freq_scale_pct(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x28));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_freq_scale_pct @ 00105088 size=300
// signature: undefined store_freq_scale_pct(void)
// callers: []
//------------------------------------------------------------

long store_freq_scale_pct(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (999 < local_4c) {
      local_4c = 1000;
    }
    *(uint *)(param_1 + -0x28) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x105154);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x1c,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_wb_pct_thres @ 001051b8 size=56
// signature: undefined show_wb_pct_thres(void)
// callers: []
//------------------------------------------------------------

long show_wb_pct_thres(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x1c));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_wb_pct_thres @ 001051f4 size=300
// signature: undefined store_wb_pct_thres(void)
// callers: []
//------------------------------------------------------------

long store_wb_pct_thres(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (99 < local_4c) {
      local_4c = 100;
    }
    *(uint *)(param_1 + -0x1c) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x1052c0);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x1a,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_wb_filter_ipm @ 00105324 size=56
// signature: undefined show_wb_filter_ipm(void)
// callers: []
//------------------------------------------------------------

long show_wb_filter_ipm(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x18));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_wb_filter_ipm @ 00105360 size=300
// signature: undefined store_wb_filter_ipm(void)
// callers: []
//------------------------------------------------------------

long store_wb_filter_ipm(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (49999 < local_4c) {
      local_4c = 50000;
    }
    *(uint *)(param_1 + -0x18) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x10542c);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x1b,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_freq_scale_ceil_mhz @ 00105490 size=56
// signature: undefined show_freq_scale_ceil_mhz(void)
// callers: []
//------------------------------------------------------------

long show_freq_scale_ceil_mhz(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x24));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_freq_scale_ceil_mhz @ 001054cc size=300
// signature: undefined store_freq_scale_ceil_mhz(void)
// callers: []
//------------------------------------------------------------

long store_freq_scale_ceil_mhz(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (4999 < local_4c) {
      local_4c = 5000;
    }
    *(uint *)(param_1 + -0x24) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x105598);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x1d,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_freq_scale_floor_mhz @ 001055fc size=56
// signature: undefined show_freq_scale_floor_mhz(void)
// callers: []
//------------------------------------------------------------

long show_freq_scale_floor_mhz(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010612e,*(undefined4 *)(param_1 + -0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_freq_scale_floor_mhz @ 00105638 size=300
// signature: undefined store_freq_scale_floor_mhz(void)
// callers: []
//------------------------------------------------------------

long store_freq_scale_floor_mhz(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined4 local_58;
  undefined4 local_54;
  uint uStack_50;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  lVar4 = *(long *)(param_1 + -0x58);
  puVar3 = *(undefined8 **)(memlat_data + 0x158);
  iVar1 = kstrtouint(param_3,10,&local_4c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    if (4999 < local_4c) {
      local_4c = 5000;
    }
    *(uint *)(param_1 + -0x20) = local_4c;
    if (((*(byte *)(param_1 + -0x50) >> 2 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
      local_54 = *(undefined4 *)(param_1 + 100);
      local_58 = *(undefined4 *)(lVar4 + 0x10);
      pcVar2 = (code *)*puVar3;
      uStack_50 = local_4c;
      if (*(int *)(pcVar2 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x105704);
        (*pcVar2)();
      }
      iVar1 = (*pcVar2)(*(undefined8 *)(memlat_data + 0x160),&local_58,0x4d454d4c4154,0x1e,0xc);
      if (iVar1 < 0) {
        _printk(&DAT_00106a31,iVar1);
        param_4 = (long)iVar1;
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 0010579c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_memlat_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001057cc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_memlat_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00109000 size=1
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
// platform_driver_unregister @ 00109008 size=1
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
// of_device_get_match_data @ 00109010 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_qcom_scmi_device @ 00109018 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00109020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00109028 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00109030 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109038 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00109040 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00109058 size=1
// signature: undefined _find_next_bit(void)
// callers: [memlat_update_work, memlat_hrtimer_handler, qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 00109060 size=1
// signature: undefined get_cpu_device(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// smp_call_function_single @ 00109070 size=1
// signature: undefined smp_call_function_single(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void smp_call_function_single(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_kobject_get @ 00109078 size=1
// signature: undefined qcom_dcvs_kobject_get(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_kobject_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00109080 size=1
// signature: undefined __bitmap_weight(void)
// callers: [memlat_update_work, qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00109088 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pmu_event_supported @ 00109098 size=1
// signature: undefined qcom_pmu_event_supported(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pmu_event_supported(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001090a0 size=1
// signature: undefined _dev_err(void)
// callers: [memlat_update_work, qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 001090a8 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_register_voter @ 001090b0 size=1
// signature: undefined qcom_dcvs_register_voter(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_register_voter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001090b8 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001090c0 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 001090c8 size=1
// signature: undefined of_platform_populate(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001090d0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 001090d8 size=1
// signature: undefined hrtimer_init(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001090e8 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pmu_idle_register @ 001090f8 size=1
// signature: undefined qcom_pmu_idle_register(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pmu_idle_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 00109100 size=1
// signature: undefined of_get_next_child(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_get_ddr_child_node @ 00109108 size=1
// signature: undefined qcom_dcvs_get_ddr_child_node(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_get_ddr_child_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00109110 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00109118 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_get_cpucp_id @ 00109120 size=1
// signature: undefined qcom_get_cpucp_id(void)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_get_cpucp_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strrchr @ 00109128 size=1
// signature: char * strrchr(char * __s, int __c)
// callers: [qcom_memlat_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00109130 size=1
// signature: undefined scnprintf(void)
// callers: [show_adaptive_low_freq, show_wb_pct_thres, show_wb_filter_ipm, show_sample_ms, show_flush_cpucp_log, show_be_stall_floor, show_cpucp_sample_ms, show_min_freq, show_cpucp_log_level, show_freq_scale_pct, show_hlos_cpucp_offset, show_max_freq, show_ipm_ceil, show_fe_stall_floor, show_cur_freq, show_freq_map, show_freq_scale_ceil_mhz, show_adaptive_cur_freq, show_sampling_cur_freq, qcom_memlat_probe, show_freq_scale_floor_mhz, show_adaptive_high_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109138 size=1
// signature: undefined _printk(void)
// callers: [store_be_stall_floor, store_fe_stall_floor, store_adaptive_low_freq, store_wb_filter_ipm, store_sample_ms, store_freq_scale_floor_mhz, update_cpucp_sample_ms, store_ipm_ceil, store_cpucp_log_level, store_freq_scale_ceil_mhz, show_hlos_cpucp_offset, store_wb_pct_thres, memlat_sched_tick_cb, store_flush_cpucp_log, memlat_update_work, store_adaptive_high_freq, show_cur_freq, show_adaptive_cur_freq, store_freq_scale_pct, store_max_freq, qcom_memlat_probe, store_min_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109140 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [store_be_stall_floor, store_fe_stall_floor, store_adaptive_low_freq, store_wb_filter_ipm, store_sample_ms, store_freq_scale_floor_mhz, update_cpucp_sample_ms, store_ipm_ceil, store_cpucp_log_level, store_freq_scale_ceil_mhz, show_hlos_cpucp_offset, store_wb_pct_thres, memlat_update_work, store_cpucp_sample_ms, store_adaptive_high_freq, show_cur_freq, show_adaptive_cur_freq, store_freq_scale_pct, store_max_freq, qcom_memlat_probe, store_min_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00109148 size=1
// signature: undefined kstrtouint(void)
// callers: [store_be_stall_floor, store_fe_stall_floor, store_adaptive_low_freq, store_wb_filter_ipm, store_sample_ms, store_freq_scale_floor_mhz, store_ipm_ceil, store_cpucp_log_level, store_freq_scale_ceil_mhz, store_wb_pct_thres, store_cpucp_sample_ms, store_adaptive_high_freq, store_freq_scale_pct, store_max_freq, store_min_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00109150 size=1
// signature: undefined sched_clock(void)
// callers: [show_hlos_cpucp_offset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00109160 size=1
// signature: undefined _find_first_bit(void)
// callers: [memlat_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00109190 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [memlat_update_work, memlat_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00109198 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [memlat_update_work, memlat_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dcvs_update_votes @ 001091a0 size=1
// signature: undefined qcom_dcvs_update_votes(void)
// callers: [memlat_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dcvs_update_votes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001091a8 size=1
// signature: undefined ktime_get(void)
// callers: [memlat_sched_tick_cb, memlat_hrtimer_handler, memlat_jiffies_update_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001091b0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [memlat_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001091c8 size=1
// signature: undefined queue_work_on(void)
// callers: [memlat_hrtimer_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001091d0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [memlat_sched_tick_cb, memlat_pmu_idle_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pmu_read_all_local @ 001091d8 size=1
// signature: undefined qcom_pmu_read_all_local(void)
// callers: [memlat_sched_tick_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pmu_read_all_local(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001091e0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [memlat_sched_tick_cb, memlat_pmu_idle_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 001091e8 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [memlat_jiffies_update_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



