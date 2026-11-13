// Decompiled by Ghidra 12.2
// Program: rproc_qcom_common.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_rproc_toggle_load_state @ 00100adc size=160
// signature: undefined qcom_rproc_toggle_load_state(void)
// callers: []
//------------------------------------------------------------

void qcom_rproc_toggle_load_state(undefined8 param_1,char *param_2,ulong param_3)

{
  char *param4;
  long lVar1;
  char local_68 [64];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  param4 = "on";
  if ((param_3 & 1) == 0) {
    param4 = "off";
  }
  local_68[0x30] = '\0';
  local_68[0x31] = '\0';
  local_68[0x32] = '\0';
  local_68[0x33] = '\0';
  local_68[0x34] = '\0';
  local_68[0x35] = '\0';
  local_68[0x36] = '\0';
  local_68[0x37] = '\0';
  local_68[0x38] = '\0';
  local_68[0x39] = '\0';
  local_68[0x3a] = '\0';
  local_68[0x3b] = '\0';
  local_68[0x3c] = '\0';
  local_68[0x3d] = '\0';
  local_68[0x3e] = '\0';
  local_68[0x3f] = '\0';
  local_68[0x20] = '\0';
  local_68[0x21] = '\0';
  local_68[0x22] = '\0';
  local_68[0x23] = '\0';
  local_68[0x24] = '\0';
  local_68[0x25] = '\0';
  local_68[0x26] = '\0';
  local_68[0x27] = '\0';
  local_68[0x28] = '\0';
  local_68[0x29] = '\0';
  local_68[0x2a] = '\0';
  local_68[0x2b] = '\0';
  local_68[0x2c] = '\0';
  local_68[0x2d] = '\0';
  local_68[0x2e] = '\0';
  local_68[0x2f] = '\0';
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  snprintf(local_68,0x40,"{class: image, res: load_state, name: %s, val: %s}",param_2,param4);
  qmp_send(param_1,local_68,0x40);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_minidump @ 00100b80 size=2480
// signature: undefined qcom_minidump(void)
// callers: []
//------------------------------------------------------------

void qcom_minidump(long param_1,undefined8 param_2,uint param_3,undefined8 param_4,ulong param_5)

{
  long *plVar1;
  ulong uVar2;
  undefined8 *puVar3;
  long *plVar4;
  uint uVar5;
  ulong uVar6;
  code *pcVar7;
  int iVar8;
  int *piVar9;
  long lVar10;
  char *pcVar11;
  size_t sVar12;
  undefined8 *puVar13;
  size_t sVar14;
  undefined8 uVar15;
  long lVar16;
  undefined4 uVar17;
  undefined8 *puVar18;
  long *plVar19;
  long lVar20;
  long *plVar21;
  ulong uVar22;
  size_t sVar23;
  short sVar24;
  ulong uVar25;
  long lVar26;
  ulong uVar27;
  long local_b0;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulong local_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  piVar9 = (int *)qcom_smem_get(0xffffffff,0x25a,0);
  if ((piVar9 < (int *)0xfffffffffffff001) && (*piVar9 != 0)) {
    uVar25 = (ulong)param_3;
    if (((*(long *)(piVar9 + uVar25 * 8 + 10) == 0) || (piVar9[uVar25 * 8 + 4] != 1)) ||
       (piVar9[uVar25 * 8 + 5] != 0x454e424c)) {
      rproc_coredump(param_1);
    }
    else {
      if (((param_5 & 1) != 0) && (qcom_collect_both_coredumps != '\0')) {
        rproc_coredump(param_1);
      }
      if (piVar9[uVar25 * 8 + 6] != 0x444f4e45) {
        _dev_err(param_1 + 0x38,"encryption_status != MD_SS_ENCR_DONE\n");
      }
      rproc_coredump_cleanup(param_1);
      local_78 = 0;
      local_70 = 0;
      plVar1 = (long *)(param_1 + 0x4f8);
      local_88 = 0;
      uStack_80 = 0;
      local_90 = 0;
      if (*(long **)(param_1 + 0x4f8) != plVar1) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x101528);
        (*pcVar7)();
      }
      uVar5 = piVar9[uVar25 * 8 + 8];
      uVar15 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar15 = 0x68000000000f13;
      }
      lVar10 = ioremap_prot(*(long *)(piVar9 + uVar25 * 8 + 10),(long)(int)uVar5 * 0x28,uVar15);
      if (lVar10 == 0) {
        uVar15 = 0xfffffff2;
LAB_001011f8:
        _dev_err(param_1 + 0x38,"Failed with error: %d while adding minidump entries\n",uVar15);
      }
      else {
        if (0 < (int)uVar5) {
          lVar26 = 0;
          do {
            __memcpy_fromio(&local_90,lVar10 + lVar26,0x28);
            if (uStack_80._4_4_ == 0x56414c49) {
              pcVar11 = (char *)kstrdup(&local_90,0xcc0);
              uVar15 = local_78;
              if (pcVar11 == (char *)0x0) {
                iounmap(lVar10);
                uVar15 = 0xfffffff4;
                goto LAB_001011f8;
              }
              uVar22 = local_70 & 0xffffffff;
              if (piVar9[uVar25 * 8 + 6] != 0x444f4e45) {
                if ((lVar26 == 0) && (iVar8 = strcmp(pcVar11,"md_dbg_buf"), iVar8 == 0)) {
                  rproc_coredump_add_custom_segment(param_1,uVar15,uVar22,param_4,pcVar11);
                }
                break;
              }
              rproc_coredump_add_custom_segment(param_1,local_78,uVar22,param_4,pcVar11);
            }
            lVar26 = lVar26 + 0x28;
          } while ((ulong)uVar5 * 0x28 != lVar26);
        }
        iounmap(lVar10);
        if (*(char *)(param_1 + 0x50c) == '\x02') {
          plVar19 = *(long **)(param_1 + 0x4f8);
          if ((plVar19 != plVar1) && (*(int *)(param_1 + 0x3d0) != 0)) {
            sVar24 = 2;
            lVar10 = 0xc0;
            sVar14 = 9;
            do {
              sVar23 = sVar14;
              lVar26 = lVar10;
              sVar12 = strlen((char *)plVar19[4]);
              lVar20 = plVar19[3];
              plVar19 = (long *)*plVar19;
              sVar14 = sVar23 + sVar12 + 1;
              sVar24 = sVar24 + 1;
              lVar10 = lVar26 + lVar20 + 0x40;
            } while (plVar19 != plVar1);
            uVar25 = lVar10 + sVar14;
            puVar13 = (undefined8 *)vmalloc(uVar25);
            if (puVar13 != (undefined8 *)0x0) {
              puVar13[6] = 0;
              puVar13[7] = 0;
              puVar13[4] = 0;
              puVar13[5] = 0;
              puVar13[2] = 0;
              puVar13[3] = 0;
              *puVar13 = 0;
              puVar13[1] = 0;
              if (((uVar25 < 4) || (*(undefined4 *)puVar13 = 0x464c457f, uVar25 == 4)) ||
                 (uVar25 < 4)) {
LAB_00101534:
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(1,0x101538);
                (*pcVar7)();
              }
              *(undefined1 *)((long)puVar13 + 4) = 2;
              if ((((((uVar25 < 6) || (*(undefined1 *)((long)puVar13 + 5) = 1, uVar25 == 6)) ||
                    ((uVar25 < 6 ||
                     ((*(undefined1 *)((long)puVar13 + 6) = 1, uVar25 < 8 ||
                      (*(undefined1 *)((long)puVar13 + 7) = 0, uVar25 < 0x10)))))) ||
                   (uVar22 = uVar25 & 0xfffffffffffffffe, uVar22 == 0x10)) ||
                  (((((((uVar25 & 0xfffffffffffffffe) == 0x10 ||
                       (*(undefined2 *)(puVar13 + 2) = 4, uVar25 < 0x12)) || (uVar22 == 0x12)) ||
                     (((uVar25 & 0xfffffffffffffffe) == 0x12 ||
                      (*(undefined2 *)((long)puVar13 + 0x12) = *(undefined2 *)(param_1 + 0x50e),
                      uVar25 < 0x14)))) || ((uVar25 & 0xfffffffffffffffc) == 0x14)) ||
                   (((uVar25 & 0xfffffffffffffffc) == 0x14 ||
                    (*(undefined4 *)((long)puVar13 + 0x14) = 1, uVar25 < 0x18)))))) ||
                 (((((uVar25 & 0xfffffffffffffff8) == 0x18 ||
                    ((((uVar25 & 0xfffffffffffffff8) == 0x18 ||
                      (puVar13[3] = *(undefined8 *)(param_1 + 0x448), uVar25 < 0x28)) ||
                     ((uVar25 & 0xfffffffffffffff8) == 0x28)))) ||
                   ((((uVar25 & 0xfffffffffffffff8) == 0x28 || (puVar13[5] = 0x40, uVar25 < 0x34))
                    || ((uVar22 == 0x34 ||
                        ((((uVar25 & 0xfffffffffffffffe) == 0x34 ||
                          (*(undefined2 *)((long)puVar13 + 0x34) = 0x40, uVar25 < 0x3a)) ||
                         ((uVar22 == 0x3a ||
                          ((((uVar25 & 0xfffffffffffffffe) == 0x3a ||
                            (*(undefined2 *)((long)puVar13 + 0x3a) = 0x40, uVar25 < 0x3c)) ||
                           (uVar22 == 0x3c)))))))))))) ||
                  ((((uVar25 & 0xfffffffffffffffe) == 0x3c ||
                    (*(short *)((long)puVar13 + 0x3c) = sVar24, uVar25 < 0x3e)) ||
                   ((uVar22 == 0x3e || ((uVar25 & 0xfffffffffffffffe) == 0x3e))))))))
              goto LAB_00101534;
              puVar18 = puVar13 + 8;
              *puVar18 = 0;
              *(undefined2 *)((long)puVar13 + 0x3e) = 1;
              puVar13[9] = 0;
              puVar13[10] = 0;
              puVar13[0xb] = 0;
              puVar13[0xc] = 0;
              puVar13[0xd] = 0;
              puVar13[0xe] = 0;
              puVar13[0xf] = 0;
              if (((uVar25 < 0x28) || ((uVar25 & 0xfffffffffffffff8) == 0x28)) ||
                 ((uVar25 < 0x3c || ((uVar25 & 0xfffffffffffffffe) == 0x3c)))) goto LAB_00101534;
              lVar10 = puVar13[5] + (ulong)*(ushort *)((long)puVar13 + 0x3c) * 0x40;
              memset((void *)((long)puVar13 + lVar10),0,sVar14);
              puVar13[0x10] = 0;
              puVar13[0x11] = 0;
              puVar13[0x12] = 0;
              puVar13[0x13] = 0;
              puVar13[0x14] = 0;
              puVar13[0x15] = 0;
              puVar13[0x16] = 0;
              puVar13[0x17] = 0;
              if ((((((uVar25 < 0x84) || ((uVar25 & 0xfffffffffffffffc) == 0x84)) ||
                    ((uVar25 & 0xfffffffffffffffc) == 0x84)) ||
                   ((*(undefined4 *)((long)puVar13 + 0x84) = 3, uVar25 < 0x98 ||
                    ((uVar25 & 0xfffffffffffffff8) == 0x98)))) ||
                  (((uVar25 & 0xfffffffffffffff8) == 0x98 ||
                   ((puVar13[0x13] = lVar10, uVar25 < 0xa0 ||
                    ((uVar25 & 0xfffffffffffffff8) == 0xa0)))))) ||
                 (((((uVar25 & 0xfffffffffffffff8) == 0xa0 ||
                    (((puVar13[0x14] = sVar14, uVar25 < 0xb8 ||
                      ((uVar25 & 0xfffffffffffffff8) == 0xb8)) ||
                     ((uVar25 & 0xfffffffffffffff8) == 0xb8)))) ||
                   (((puVar13[0x17] = 0, (uVar25 & 0xfffffffffffffff8) == 0x88 || (uVar25 < 0x88))
                    || ((uVar25 & 0xfffffffffffffff8) == 0x88)))) ||
                  (puVar13[0x11] = 0, (uVar25 & 0xfffffffffffffffe) == 0x3e)))) goto LAB_00101534;
              lVar16 = (ulong)*(ushort *)((long)puVar13 + 0x3e) * 0x40;
              uVar22 = lVar16 + 0x58;
              if (((uVar25 < uVar22) || (uVar25 - uVar22 < 8)) ||
                 ((uVar22 = lVar16 + 0x58, uVar25 < uVar22 || (uVar25 - uVar22 < 8))))
              goto LAB_00101534;
              lVar16 = puVar18[(ulong)*(ushort *)((long)puVar13 + 0x3e) * 8 + 3];
              if ((long)puVar13 + lVar16 == 0) {
                uVar17 = 0;
                local_b0 = 1;
              }
              else {
                uVar22 = lVar16 + 1;
                if ((((long)uVar22 < 0) || (uVar25 < uVar22)) || (uVar25 - uVar22 < 8))
                goto LAB_00101534;
                uVar22 = lVar16 + 1;
                if ((((long)uVar22 < 0) || (uVar25 < uVar22)) || (uVar25 - uVar22 < 8))
                goto LAB_00101534;
                uVar17 = 1;
                local_b0 = 9;
                *(undefined8 *)((long)puVar13 + lVar16 + 1) = 0x4c42545f525453;
              }
              if ((((uVar25 & 0xfffffffffffffffc) == 0x80) || (uVar25 < 0x80)) ||
                 ((uVar25 & 0xfffffffffffffffc) == 0x80)) goto LAB_00101534;
              plVar19 = (long *)*plVar1;
              *(undefined4 *)(puVar13 + 0x10) = uVar17;
              if (plVar19 != plVar1) {
                if ((uVar25 < 0xa0) || ((uVar25 & 0xfffffffffffffff8) == 0xa0)) goto LAB_00101534;
                lVar10 = puVar13[0x14] + lVar10;
                uVar22 = 0xf8;
                uVar27 = (sVar12 + lVar26 + sVar23 + lVar20) - 0xb7;
                do {
                  puVar3 = (undefined8 *)((long)puVar13 + uVar22);
                  puVar3[-1] = 0;
                  *puVar3 = 0;
                  puVar3[-3] = 0;
                  puVar3[-2] = 0;
                  puVar3[-5] = 0;
                  puVar3[-4] = 0;
                  puVar3[-6] = 0;
                  puVar3[-7] = 0;
                  if ((((long)(uVar22 - 0x34) < 0) || (uVar25 < uVar22 - 0x34)) ||
                     (uVar27 + 0x34 < 4)) goto LAB_00101534;
                  *(undefined4 *)((long)puVar13 + (uVar22 - 0x34)) = 1;
                  if ((((long)(uVar22 - 0x20) < 0) || (uVar25 < uVar22 - 0x20)) ||
                     (uVar27 + 0x20 < 8)) goto LAB_00101534;
                  *(long *)((long)puVar13 + (uVar22 - 0x20)) = lVar10;
                  if ((((long)(uVar22 - 0x28) < 0) || (uVar25 < uVar22 - 0x28)) ||
                     (uVar27 + 0x28 < 8)) goto LAB_00101534;
                  uVar6 = uVar22 - 0x18;
                  *(long *)((long)puVar13 + (uVar22 - 0x28)) = plVar19[2];
                  if ((((((long)uVar6 < 0) || (uVar25 < uVar6)) || (uVar27 + 0x18 < 8)) ||
                      ((*(long *)((long)puVar13 + (uVar22 - 0x18)) = plVar19[3], (long)uVar22 < 0 ||
                       (uVar25 < uVar22)))) || (uVar27 < 8)) goto LAB_00101534;
                  *(undefined8 *)((long)puVar13 + uVar22) = 0;
                  if ((((long)(uVar22 - 0x30) < 0) || (uVar25 < uVar22 - 0x30)) ||
                     ((uVar27 + 0x30 < 8 ||
                      (*(undefined8 *)((long)puVar13 + (uVar22 - 0x30)) = 1,
                      uVar25 < 0x3e || (uVar25 & 0xfffffffffffffffe) == 0x3e)))) goto LAB_00101534;
                  lVar26 = (ulong)*(ushort *)((long)puVar13 + 0x3e) * 0x40;
                  uVar2 = lVar26 + 0x58;
                  if ((((uVar25 < uVar2) || (uVar25 - uVar2 < 8)) ||
                      (uVar2 = lVar26 + 0x58, uVar25 < uVar2)) || (uVar25 - uVar2 < 8))
                  goto LAB_00101534;
                  uVar17 = 0;
                  pcVar11 = (char *)plVar19[4];
                  if ((pcVar11 != (char *)0x0) &&
                     ((long)puVar13 + puVar18[(ulong)*(ushort *)((long)puVar13 + 0x3e) * 8 + 3] != 0
                     )) {
                    strcpy((char *)((long)puVar13 +
                                    puVar18[(ulong)*(ushort *)((long)puVar13 + 0x3e) * 8 + 3] +
                                   local_b0),pcVar11);
                    sVar14 = strlen(pcVar11);
                    uVar17 = (undefined4)local_b0;
                    local_b0 = local_b0 + sVar14 + 1;
                  }
                  if ((((long)(uVar22 - 0x38) < 0) || (uVar25 < uVar22 - 0x38)) ||
                     (uVar27 + 0x38 < 4)) goto LAB_00101534;
                  *(undefined4 *)(puVar3 + -7) = uVar17;
                  if (*(int *)((code *)plVar19[5] + -4) != -0x60ea929f) {
                    /* WARNING: Does not return */
                    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101458);
                    (*pcVar7)();
                  }
                  (*(code *)plVar19[5])(param_1,plVar19,(long)puVar13 + lVar10,0,plVar19[3]);
                  if ((((long)uVar6 < 0) || (uVar25 < uVar6)) || (uVar27 + 0x18 < 8))
                  goto LAB_00101534;
                  lVar26 = uVar22 - 0x18;
                  uVar22 = uVar22 + 0x40;
                  uVar27 = uVar27 - 0x40;
                  plVar19 = (long *)*plVar19;
                  lVar10 = *(long *)((long)puVar13 + lVar26) + lVar10;
                } while (plVar19 != plVar1);
              }
              dev_coredumpv(param_2,puVar13,uVar25,0xcc0);
            }
          }
        }
        else {
          rproc_coredump();
        }
      }
      plVar19 = (long *)*plVar1;
      while (plVar19 != plVar1) {
        plVar21 = (long *)*plVar19;
        uVar25 = __list_del_entry_valid(plVar19);
        if ((uVar25 & 1) != 0) {
          lVar10 = *plVar19;
          plVar4 = (long *)plVar19[1];
          *(long **)(lVar10 + 8) = plVar4;
          *plVar4 = lVar10;
        }
        *plVar19 = -0x2152ffffffffff00;
        plVar19[1] = -0x2152fffffffffede;
        kfree(plVar19[4]);
        kfree(plVar19);
        plVar19 = plVar21;
      }
    }
  }
  else {
    _dev_err(param_1 + 0x38,"Minidump TOC not found in SMEM\n");
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_add_glink_subdev @ 00101540 size=160
// signature: undefined qcom_add_glink_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_add_glink_subdev(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = of_get_child_by_name(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),"glink-edge");
  *(long *)(param_2 + 0x40) = lVar1;
  if (lVar1 != 0) {
    lVar1 = kstrdup_const(param_3,0xcc0);
    *(long *)(param_2 + 0x30) = lVar1;
    if (lVar1 != 0) {
      *(long *)(param_2 + 0x38) = param_1 + 0x38;
      *(code **)(param_2 + 0x10) = glink_subdev_prepare;
      *(code **)(param_2 + 0x18) = glink_subdev_start;
      *(code **)(param_2 + 0x20) = glink_subdev_stop;
      *(code **)(param_2 + 0x28) = glink_subdev_unprepare;
      rproc_add_subdev(param_1,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// glink_subdev_start @ 001015e4 size=164
// signature: undefined glink_subdev_start(void)
// callers: []
//------------------------------------------------------------

void glink_subdev_start(long param_1)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  
  plVar3 = *(long **)(*(long *)(param_1 + 0x38) + 0x60);
  lVar2 = plVar3[0xe];
  if (lVar2 == 0) {
    lVar2 = *plVar3;
  }
  *(undefined8 *)(param_1 + 0x50) = glink_early_ssr_notifier_event;
  uVar1 = qcom_ssr_get_subsys(*(undefined8 *)(param_1 + 0x30),lVar2);
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = uVar1 + 0x220;
    srcu_notifier_chain_register(uVar1,(undefined8 *)(param_1 + 0x50));
  }
  *(ulong *)(param_1 + 0x68) = uVar1;
  if (0xfffffffffffff000 < uVar1) {
    _dev_err(*(undefined8 *)(param_1 + 0x38),"Failed to register for SSR notifier\n");
    *(undefined8 *)(param_1 + 0x68) = 0;
  }
  qcom_glink_smem_start(*(undefined8 *)(param_1 + 0x48));
  return;
}



//------------------------------------------------------------
// glink_subdev_prepare @ 00101700 size=84
// signature: undefined glink_subdev_prepare(void)
// callers: []
//------------------------------------------------------------

undefined4 glink_subdev_prepare(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar1 = qcom_glink_smem_register(*(undefined8 *)(param_1 + 0x38),*(undefined8 *)(param_1 + 0x40));
  uVar2 = (undefined4)uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = 0;
  }
  *(ulong *)(param_1 + 0x48) = uVar1;
  return uVar2;
}



//------------------------------------------------------------
// glink_subdev_stop @ 001017cc size=152
// signature: undefined glink_subdev_stop(void)
// callers: []
//------------------------------------------------------------

void glink_subdev_stop(long param_1,ulong param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  
  if (*(long *)(param_1 + 0x48) != 0) {
    if ((param_2 & 1) == 0) {
      pcVar2 = "stop";
    }
    else {
      if (*(char *)(*(long *)(param_1 + 0x38) + 0x48c) != '\0') {
        return;
      }
      pcVar2 = "crash stop";
    }
    iVar1 = srcu_notifier_chain_unregister
                      (*(undefined8 *)(param_1 + 0x68),param_1 + 0x50,param_3,pcVar2);
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x38),"Error in unregistering notifier\n");
    }
    *(undefined8 *)(param_1 + 0x68) = 0;
    qcom_glink_smem_unregister(*(undefined8 *)(param_1 + 0x48));
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  return;
}



//------------------------------------------------------------
// glink_subdev_unprepare @ 001018d4 size=64
// signature: undefined glink_subdev_unprepare(void)
// callers: []
//------------------------------------------------------------

void glink_subdev_unprepare(long param_1)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x38) + 0x60);
  lVar1 = plVar2[0xe];
  if (lVar1 == 0) {
    lVar1 = *plVar2;
  }
  qcom_glink_ssr_notify(*(undefined8 *)(param_1 + 0x30),lVar1);
  return;
}



//------------------------------------------------------------
// qcom_remove_glink_subdev @ 00101998 size=56
// signature: undefined qcom_remove_glink_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_remove_glink_subdev(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x40) != 0) {
    rproc_remove_subdev();
    kfree_const(*(undefined8 *)(param_2 + 0x30));
  }
  return;
}



//------------------------------------------------------------
// qcom_register_dump_segments @ 001019d4 size=160
// signature: undefined qcom_register_dump_segments(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_register_dump_segments(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  uint *puVar5;
  
  lVar3 = *(long *)(param_2 + 8);
  uVar2 = (ulong)*(ushort *)(lVar3 + 0x2c);
  if (*(ushort *)(lVar3 + 0x2c) != 0) {
    uVar4 = 0;
    puVar5 = (uint *)(lVar3 + 0x4c);
    do {
      if (((puVar5[-6] == 1) && ((*puVar5 & 0x7000000) != 0x2000000)) && (puVar5[-1] != 0)) {
        uVar1 = rproc_coredump_add_segment(param_1,puVar5[-3]);
        if ((int)uVar1 != 0) {
          return uVar1;
        }
        uVar2 = (ulong)*(ushort *)(lVar3 + 0x2c);
      }
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 8;
    } while (uVar4 < uVar2);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_add_smd_subdev @ 00101a78 size=108
// signature: undefined qcom_add_smd_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_add_smd_subdev(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = of_get_child_by_name(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),"smd-edge");
  *(long *)(param_2 + 0x38) = lVar1;
  if (lVar1 != 0) {
    *(long *)(param_2 + 0x30) = param_1 + 0x38;
    *(code **)(param_2 + 0x18) = smd_subdev_start;
    *(code **)(param_2 + 0x20) = smd_subdev_stop;
    rproc_add_subdev(param_1,param_2);
  }
  return;
}



//------------------------------------------------------------
// smd_subdev_start @ 00101ae8 size=84
// signature: undefined smd_subdev_start(void)
// callers: []
//------------------------------------------------------------

undefined4 smd_subdev_start(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar1 = qcom_smd_register_edge(*(undefined8 *)(param_1 + 0x30),*(undefined8 *)(param_1 + 0x38));
  uVar2 = (undefined4)uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = 0;
  }
  *(ulong *)(param_1 + 0x40) = uVar1;
  return uVar2;
}



//------------------------------------------------------------
// smd_subdev_stop @ 00101bb4 size=108
// signature: undefined smd_subdev_stop(void)
// callers: []
//------------------------------------------------------------

void smd_subdev_stop(long param_1,uint param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  long *plVar3;
  
  if (*(long *)(param_1 + 0x40) != 0) {
    plVar3 = *(long **)(*(long *)(param_1 + 0x30) + 0x60);
    lVar2 = plVar3[0xe];
    if (lVar2 == 0) {
      lVar2 = *plVar3;
    }
    pcVar1 = "crash stop";
    if ((param_2 & 1) == 0) {
      pcVar1 = "stop";
    }
    qcom_smd_unregister_edge(*(undefined8 *)(param_1 + 0x40),lVar2,param_3,pcVar1);
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  return;
}



//------------------------------------------------------------
// qcom_remove_smd_subdev @ 00101c90 size=36
// signature: undefined qcom_remove_smd_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_remove_smd_subdev(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x38) != 0) {
    rproc_remove_subdev();
  }
  return;
}



//------------------------------------------------------------
// qcom_ssr_get_subsys @ 00101cb8 size=248
// signature: undefined qcom_ssr_get_subsys(void)
// callers: [glink_subdev_start, qcom_add_ssr_subdev, qcom_register_early_ssr_notifier, qcom_register_ssr_notifier]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ** qcom_ssr_get_subsys(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  if (param_1 == (char *)0x0) {
    ppuVar2 = (undefined **)0xffffffffffffffea;
  }
  else {
    mutex_lock(&qcom_ssr_subsys_lock);
    ppuVar5 = &qcom_ssr_subsystem_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &qcom_ssr_subsystem_list) {
        ppuVar2 = (undefined **)kmalloc_trace(_mod_timer,0xdc0,0x448);
        if (ppuVar2 == (undefined **)0x0) {
          ppuVar2 = (undefined **)0xfffffffffffffff4;
        }
        else {
          puVar3 = (undefined *)kstrdup_const(param_1,0xcc0);
          *ppuVar2 = puVar3;
          srcu_init_notifier_head(ppuVar2 + 1);
          srcu_init_notifier_head(ppuVar2 + 0x44);
          puVar3 = PTR_qcom_ssr_subsystem_list_00103510;
          ppuVar5 = ppuVar2 + 0x87;
          uVar4 = __list_add_valid(ppuVar5,PTR_qcom_ssr_subsystem_list_00103510,
                                   &qcom_ssr_subsystem_list);
          if ((uVar4 & 1) != 0) {
            PTR_qcom_ssr_subsystem_list_00103510 = (undefined *)ppuVar5;
            ppuVar2[0x87] = (undefined *)&qcom_ssr_subsystem_list;
            ppuVar2[0x88] = puVar3;
            *(undefined ***)puVar3 = ppuVar5;
          }
        }
        break;
      }
      ppuVar2 = ppuVar5 + -0x87;
      iVar1 = strcmp(*ppuVar2,param_1);
    } while (iVar1 != 0);
    mutex_unlock(&qcom_ssr_subsys_lock);
  }
  return ppuVar2;
}



//------------------------------------------------------------
// qcom_register_early_ssr_notifier @ 00101db4 size=72
// signature: undefined qcom_register_early_ssr_notifier(void)
// callers: []
//------------------------------------------------------------

ulong qcom_register_early_ssr_notifier(undefined8 param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = qcom_ssr_get_subsys();
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = uVar1 + 0x220;
    srcu_notifier_chain_register(uVar1,param_2);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_unregister_early_ssr_notifier @ 00101e00 size=28
// signature: undefined qcom_unregister_early_ssr_notifier(void)
// callers: []
//------------------------------------------------------------

void qcom_unregister_early_ssr_notifier(void)

{
  srcu_notifier_chain_unregister();
  return;
}



//------------------------------------------------------------
// qcom_notify_early_ssr_clients @ 00101e20 size=44
// signature: undefined qcom_notify_early_ssr_clients(void)
// callers: []
//------------------------------------------------------------

void qcom_notify_early_ssr_clients(long param_1)

{
  srcu_notifier_call_chain(*(long *)(param_1 + 0x70) + 0x220,2,0);
  return;
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 00101e50 size=72
// signature: undefined qcom_register_ssr_notifier(void)
// callers: []
//------------------------------------------------------------

ulong qcom_register_ssr_notifier(undefined8 param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = qcom_ssr_get_subsys();
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = uVar1 + 8;
    srcu_notifier_chain_register(uVar1,param_2);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 00101e9c size=28
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: []
//------------------------------------------------------------

void qcom_unregister_ssr_notifier(void)

{
  srcu_notifier_chain_unregister();
  return;
}



//------------------------------------------------------------
// qcom_notify_ssr_clients @ 00101ebc size=52
// signature: undefined qcom_notify_ssr_clients(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_notify_ssr_clients(long param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffea;
  if ((param_1 != 0) && (-1 < param_2)) {
    uVar1 = srcu_notifier_call_chain(param_1 + 8,param_2);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_add_ssr_subdev @ 00101ef4 size=172
// signature: undefined qcom_add_ssr_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_add_ssr_subdev(long param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  
  uVar1 = qcom_ssr_get_subsys(param_3);
  if (uVar1 < 0xfffffffffffff001) {
    init_timer_key(param_2 + 0x38,ssr_notif_timeout_handler,0,0,0);
    *(ulong *)(param_2 + 0x70) = uVar1;
    *(code **)(param_2 + 0x10) = ssr_notify_prepare;
    *(code **)(param_2 + 0x18) = ssr_notify_start;
    *(code **)(param_2 + 0x20) = ssr_notify_stop;
    *(code **)(param_2 + 0x28) = ssr_notify_unprepare;
    rproc_add_subdev(param_1,param_2);
  }
  else {
    _dev_err(param_1 + 0x38,"Failed to add ssr subdevice\n");
  }
  return;
}



//------------------------------------------------------------
// ssr_notif_timeout_handler @ 00101fa4 size=136
// signature: undefined ssr_notif_timeout_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ssr_notif_timeout_handler(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = *(uint *)(param_1 + -8);
  if (_system_state - 7U < 0xfffffffd && qcom_device_shutdown_in_progress == '\0') {
    if (uVar1 < 4) {
                    /* WARNING: Subroutine does not return */
      panic("srcu notifier chain for %s:%s taking too long",**(undefined8 **)(param_1 + 0x38),
            (&subdevice_state_string)[uVar1]);
    }
  }
  else if (uVar1 < 4) {
    __warn_printk("srcu notifier chain for %s:%s taking too long",**(undefined8 **)(param_1 + 0x38),
                  (&subdevice_state_string)[uVar1]);
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x102000);
    (*pcVar2)();
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102038);
  (*pcVar2)();
}



//------------------------------------------------------------
// ssr_notify_prepare @ 0010203c size=168
// signature: undefined ssr_notify_prepare(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ssr_notify_prepare(long param_1)

{
  long lVar1;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = **(undefined8 **)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x30) = 0;
  mod_timer(param_1 + 0x38,_jiffies + 5000);
  srcu_notifier_call_chain(*(long *)(param_1 + 0x70) + 8,*(undefined4 *)(param_1 + 0x30),&local_38);
  del_timer_sync(param_1 + 0x38);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// ssr_notify_start @ 0010215c size=172
// signature: undefined ssr_notify_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ssr_notify_start(long param_1)

{
  long lVar1;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = **(undefined8 **)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x30) = 1;
  mod_timer(param_1 + 0x38,_jiffies + 5000);
  srcu_notifier_call_chain(*(long *)(param_1 + 0x70) + 8,*(undefined4 *)(param_1 + 0x30),&local_38);
  del_timer_sync(param_1 + 0x38);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// ssr_notify_stop @ 00102280 size=196
// signature: undefined ssr_notify_stop(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ssr_notify_stop(long param_1,ulong param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  undefined8 local_38;
  ulong local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  pcVar1 = "crash stop";
  if ((param_2 & 1) == 0) {
    pcVar1 = "stop";
  }
  local_38 = **(undefined8 **)(param_1 + 0x70);
  local_30 = param_2 & 0xff;
  *(undefined4 *)(param_1 + 0x30) = 2;
  mod_timer(param_1 + 0x38,_jiffies + 5000,param_3,pcVar1);
  srcu_notifier_call_chain(*(long *)(param_1 + 0x70) + 8,*(undefined4 *)(param_1 + 0x30),&local_38);
  del_timer_sync(param_1 + 0x38);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ssr_notify_unprepare @ 001023b4 size=168
// signature: undefined ssr_notify_unprepare(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ssr_notify_unprepare(long param_1)

{
  long lVar1;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = **(undefined8 **)(param_1 + 0x70);
  *(undefined4 *)(param_1 + 0x30) = 3;
  mod_timer(param_1 + 0x38,_jiffies + 5000);
  srcu_notifier_call_chain(*(long *)(param_1 + 0x70) + 8,*(undefined4 *)(param_1 + 0x30),&local_38);
  del_timer_sync(param_1 + 0x38);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_remove_ssr_subdev @ 001024d4 size=44
// signature: undefined qcom_remove_ssr_subdev(void)
// callers: []
//------------------------------------------------------------

void qcom_remove_ssr_subdev(undefined8 param_1,long param_2)

{
  rproc_remove_subdev();
  *(undefined8 *)(param_2 + 0x70) = 0;
  return;
}



//------------------------------------------------------------
// glink_early_ssr_notifier_event @ 00102504 size=36
// signature: undefined glink_early_ssr_notifier_event(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_early_ssr_notifier_event(long param_1)

{
  qcom_glink_early_ssr_notify(*(undefined8 *)(param_1 + -8));
  return 0;
}



//------------------------------------------------------------
// qcom_check_ssr_status @ 0010252c size=92
// signature: undefined qcom_check_ssr_status(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_check_ssr_status(undefined8 param_1,long param_2)

{
  if ((((*(int *)(param_2 + 0x3c8) != 0) && (*(int *)(param_2 + 0x3cc) != 2)) &&
      (qcom_device_shutdown_in_progress == '\0')) && (2 < _system_state - 4U)) {
                    /* WARNING: Subroutine does not return */
    panic("Panicking, remoteproc %s failed to recover!\n",*(undefined8 *)(param_2 + 0x18));
  }
  return;
}



//------------------------------------------------------------
// rproc_recovery_notifier @ 0010258c size=96
// signature: undefined rproc_recovery_notifier(void)
// callers: []
//------------------------------------------------------------

void rproc_recovery_notifier(undefined8 param_1,long param_2)

{
  char *pcVar1;
  
  pcVar1 = "enabled";
  if (*(char *)(param_2 + 0x4c4) != '\0') {
    pcVar1 = "disabled";
  }
  _printk(&DAT_001031cf,*(undefined8 *)(param_2 + 0x18),pcVar1);
  return;
}



//------------------------------------------------------------
// qcom_rproc_shutdown_request_store @ 0010267c size=160
// signature: undefined qcom_rproc_shutdown_request_store(void)
// callers: []
//------------------------------------------------------------

long qcom_rproc_shutdown_request_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  char local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c[0] = '\0';
  iVar3 = kstrtobool(param_3,local_2c);
  if (iVar3 == 0) {
    pcVar1 = "false";
    if (local_2c[0] != '\0') {
      pcVar1 = "true";
    }
    qcom_device_shutdown_in_progress = local_2c[0];
    _printk(&DAT_001033b5,pcVar1);
  }
  else {
    param_4 = (long)iVar3;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qcom_collect_both_coredumps_show @ 00102720 size=56
// signature: undefined qcom_collect_both_coredumps_show(void)
// callers: []
//------------------------------------------------------------

long qcom_collect_both_coredumps_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,3,&DAT_001031cb,qcom_collect_both_coredumps);
  return (long)iVar1;
}



//------------------------------------------------------------
// qcom_collect_both_coredumps_store @ 0010275c size=160
// signature: undefined qcom_collect_both_coredumps_store(void)
// callers: []
//------------------------------------------------------------

long qcom_collect_both_coredumps_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  char local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c[0] = '\0';
  iVar3 = kstrtobool(param_3,local_2c);
  if (iVar3 == 0) {
    pcVar1 = "false";
    if (local_2c[0] != '\0') {
      pcVar1 = "true";
    }
    qcom_collect_both_coredumps = local_2c[0];
    _printk(&DAT_00103450,pcVar1);
  }
  else {
    param_4 = (long)iVar3;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// __traceiter_rproc_qcom_event @ 0010282c size=124
// signature: undefined __traceiter_rproc_qcom_event(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_rproc_qcom_event
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00103880;
  plVar2 = DAT_00103880;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x747ff3a2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102884);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_rproc_qcom_event @ 001028ac size=364
// signature: undefined trace_event_raw_event_rproc_qcom_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rproc_qcom_event(long param_1,char *param_2,char *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *__s;
  char *__s_00;
  char *__s_01;
  size_t sVar6;
  size_t sVar7;
  long lVar8;
  ulong uVar9;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar9 = __trace_trigger_soft_disabled(param_1), (uVar9 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar6 = strlen(__s);
    __s_00 = "(null)";
    if (param_3 != (char *)0x0) {
      __s_00 = param_3;
    }
    iVar1 = (int)sVar6 + 1;
    sVar7 = strlen(__s_00);
    iVar2 = (int)sVar7 + 1;
    __s_01 = "(null)";
    if (param_4 != (char *)0x0) {
      __s_01 = param_4;
    }
    sVar7 = strlen(__s_01);
    iVar5 = iVar2 + iVar1;
    iVar3 = (int)sVar7 + 1;
    lVar8 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar3 + iVar5) + 0x14);
    if (lVar8 != 0) {
      uVar4 = (int)sVar6 + 0x15;
      *(uint *)(lVar8 + 8) = iVar1 * 0x10000 | 0x14;
      *(uint *)(lVar8 + 0xc) = uVar4 | iVar2 * 0x10000;
      *(uint *)(lVar8 + 0x10) = iVar5 + 0x14U | iVar3 * 0x10000;
      strcpy((char *)(lVar8 + 0x14),__s);
      strcpy((char *)(lVar8 + (ulong)(uVar4 & 0xffff)),__s_00);
      strcpy((char *)(lVar8 + (ulong)*(ushort *)(lVar8 + 0x10)),__s_01);
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rproc_qcom_event @ 00102a1c size=448
// signature: undefined perf_trace_rproc_qcom_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rproc_qcom_event(long param_1,char *param_2,char *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  char *__s;
  char *__s_00;
  char *__s_01;
  ulong uVar7;
  int iVar8;
  size_t sVar9;
  size_t sVar10;
  size_t sVar11;
  long lVar12;
  ulong unaff_x30;
  undefined1 auStack_110 [128];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  sVar9 = strlen(__s);
  __s_00 = "(null)";
  if (param_3 != (char *)0x0) {
    __s_00 = param_3;
  }
  sVar10 = strlen(__s_00);
  __s_01 = "(null)";
  if (param_4 != (char *)0x0) {
    __s_01 = param_4;
  }
  sVar11 = strlen(__s_01);
  lVar12 = tpidr_el1;
  plVar6 = (long *)(lVar12 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar6 != 0)) {
    iVar1 = (int)sVar9 + 1;
    iVar2 = (int)sVar10 + 1;
    iVar5 = iVar2 + iVar1;
    iVar3 = (int)sVar11 + 1;
    iVar8 = (iVar5 + iVar3 + 0x1fU & 0xfffffff8) - 4;
    lVar12 = perf_trace_buf_alloc(iVar8,&local_70,&local_74);
    if (lVar12 != 0) {
      uVar4 = (int)sVar9 + 0x15;
      uVar7 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar7 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xe8) = auStack_110 + 0xb0;
      *(ulong *)(local_70 + 0x100) = uVar7;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined1 **)(local_70 + 0xf8) = auStack_110 + 0x80;
      *(uint *)(lVar12 + 8) = iVar1 * 0x10000 | 0x14;
      *(uint *)(lVar12 + 0xc) = uVar4 | iVar2 * 0x10000;
      *(uint *)(lVar12 + 0x10) = iVar5 + 0x14U | iVar3 * 0x10000;
      strcpy((char *)(lVar12 + 0x14),__s);
      strcpy((char *)(lVar12 + (ulong)(uVar4 & 0xffff)),__s_00);
      strcpy((char *)(lVar12 + (ulong)*(ushort *)(lVar12 + 0x10)),__s_01);
      perf_trace_run_bpf_submit(lVar12,iVar8,local_74,param_1,1,local_70,plVar6,0);
    }
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_rproc_qcom_event @ 00102be0 size=28
// signature: undefined __bpf_trace_rproc_qcom_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rproc_qcom_event(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// trace_raw_output_rproc_qcom_event @ 00102c00 size=120
// signature: undefined trace_raw_output_rproc_qcom_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rproc_qcom_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: %s: %s\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0xc),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00102eb0 size=344
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  int iVar1;
  
  qcom_device_shutdown_in_progress = 0;
  sysfs_kobject = kobject_create_and_add("qcom_rproc",_kernel_kobj);
  if (sysfs_kobject == 0) {
    _printk(&DAT_00103322);
    iVar1 = -0x16;
  }
  else {
    iVar1 = sysfs_create_file_ns(sysfs_kobject,&shutdown_requested_attr,0);
    if (iVar1 == 0) {
      iVar1 = sysfs_create_file_ns(sysfs_kobject,&both_coredumps_attr,0);
      if (iVar1 == 0) {
        iVar1 = tracepoint_probe_register
                          (&__tracepoint_android_vh_rproc_recovery,qcom_check_ssr_status,0);
        if (iVar1 == 0) {
          iVar1 = tracepoint_probe_register
                            (&__tracepoint_android_vh_rproc_recovery_set,rproc_recovery_notifier,0);
          if (iVar1 == 0) {
            return 0;
          }
          _printk(&DAT_001032cc);
          tracepoint_probe_unregister
                    (&__tracepoint_android_vh_rproc_recovery,qcom_check_ssr_status,0);
        }
        else {
          _printk(&DAT_00103115);
        }
        sysfs_remove_file_ns(sysfs_kobject,&both_coredumps_attr,0);
      }
      else {
        _printk(&DAT_00103350);
      }
      sysfs_remove_file_ns(sysfs_kobject,&shutdown_requested_attr,0);
    }
    else {
      _printk(&DAT_00103494);
    }
    kobject_put(sysfs_kobject);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010300c size=132
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_rproc_recovery_set,rproc_recovery_notifier,0)
  ;
  sysfs_remove_file_ns(sysfs_kobject,&both_coredumps_attr,0);
  sysfs_remove_file_ns(sysfs_kobject,&shutdown_requested_attr,0);
  kobject_put(sysfs_kobject);
  tracepoint_probe_unregister(&__tracepoint_android_vh_rproc_recovery,qcom_check_ssr_status,0);
  return;
}



//------------------------------------------------------------
// snprintf @ 00106000 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qcom_rproc_toggle_load_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_send @ 00106008 size=1
// signature: undefined qmp_send(void)
// callers: [qcom_rproc_toggle_load_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_collect_both_coredumps_store, ssr_notify_prepare, trace_event_raw_event_rproc_qcom_event, ssr_notify_unprepare, perf_trace_rproc_qcom_event, ssr_notify_stop, qcom_minidump, ssr_notify_start, qcom_rproc_shutdown_request_store, qcom_rproc_toggle_load_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00106018 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump @ 00106020 size=1
// signature: undefined rproc_coredump(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_cleanup @ 00106028 size=1
// signature: undefined rproc_coredump_cleanup(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00106038 size=1
// signature: undefined ioremap_prot(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_add_custom_segment @ 00106040 size=1
// signature: undefined rproc_coredump_add_custom_segment(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_add_custom_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00106048 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00106050 size=1
// signature: undefined kstrdup(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00106058 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_ssr_get_subsys, qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00106060 size=1
// signature: undefined iounmap(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00106068 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_rproc_qcom_event, perf_trace_rproc_qcom_event, qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 00106070 size=1
// signature: undefined vmalloc(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00106078 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106080 size=1
// signature: undefined _dev_err(void)
// callers: [glink_subdev_start, qcom_minidump, qcom_add_ssr_subdev, glink_subdev_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00106088 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_rproc_qcom_event, perf_trace_rproc_qcom_event, qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_coredumpv @ 00106090 size=1
// signature: undefined dev_coredumpv(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_coredumpv(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106098 size=1
// signature: undefined kfree(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001060a0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 001060a8 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [qcom_add_smd_subdev, qcom_add_glink_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup_const @ 001060b0 size=1
// signature: undefined kstrdup_const(void)
// callers: [qcom_ssr_get_subsys, qcom_add_glink_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_add_subdev @ 001060b8 size=1
// signature: undefined rproc_add_subdev(void)
// callers: [qcom_add_smd_subdev, qcom_add_glink_subdev, qcom_add_ssr_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_add_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_register @ 001060c0 size=1
// signature: undefined srcu_notifier_chain_register(void)
// callers: [glink_subdev_start, qcom_register_early_ssr_notifier, qcom_register_ssr_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_smem_start @ 001060c8 size=1
// signature: undefined qcom_glink_smem_start(void)
// callers: [glink_subdev_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_smem_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_smem_register @ 001060e8 size=1
// signature: undefined qcom_glink_smem_register(void)
// callers: [glink_subdev_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_smem_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_chain_unregister @ 001060f0 size=1
// signature: undefined srcu_notifier_chain_unregister(void)
// callers: [qcom_unregister_early_ssr_notifier, glink_subdev_stop, qcom_unregister_ssr_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_smem_unregister @ 001060f8 size=1
// signature: undefined qcom_glink_smem_unregister(void)
// callers: [glink_subdev_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_smem_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_ssr_notify @ 00106100 size=1
// signature: undefined qcom_glink_ssr_notify(void)
// callers: [glink_subdev_unprepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_ssr_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_remove_subdev @ 00106108 size=1
// signature: undefined rproc_remove_subdev(void)
// callers: [qcom_remove_glink_subdev, qcom_remove_ssr_subdev, qcom_remove_smd_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_remove_subdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_const @ 00106110 size=1
// signature: undefined kfree_const(void)
// callers: [qcom_remove_glink_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_const(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_coredump_add_segment @ 00106118 size=1
// signature: undefined rproc_coredump_add_segment(void)
// callers: [qcom_register_dump_segments]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_coredump_add_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smd_register_edge @ 00106120 size=1
// signature: undefined qcom_smd_register_edge(void)
// callers: [smd_subdev_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smd_register_edge(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smd_unregister_edge @ 00106128 size=1
// signature: undefined qcom_smd_unregister_edge(void)
// callers: [smd_subdev_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smd_unregister_edge(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00106130 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_ssr_get_subsys]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00106140 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_ssr_get_subsys]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_init_notifier_head @ 00106148 size=1
// signature: undefined srcu_init_notifier_head(void)
// callers: [qcom_ssr_get_subsys]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_init_notifier_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00106150 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_ssr_get_subsys]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00106158 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_ssr_get_subsys]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// srcu_notifier_call_chain @ 00106160 size=1
// signature: undefined srcu_notifier_call_chain(void)
// callers: [ssr_notify_prepare, ssr_notify_unprepare, ssr_notify_stop, ssr_notify_start, qcom_notify_ssr_clients, qcom_notify_early_ssr_clients]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void srcu_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00106168 size=1
// signature: undefined init_timer_key(void)
// callers: [qcom_add_ssr_subdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00106178 size=1
// signature: undefined __warn_printk(void)
// callers: [ssr_notif_timeout_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00106180 size=1
// signature: noreturn undefined panic(void)
// callers: [qcom_check_ssr_status, ssr_notif_timeout_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00106190 size=1
// signature: undefined mod_timer(void)
// callers: [ssr_notify_prepare, ssr_notify_unprepare, ssr_notify_stop, ssr_notify_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 00106198 size=1
// signature: undefined del_timer_sync(void)
// callers: [ssr_notify_prepare, ssr_notify_unprepare, ssr_notify_stop, ssr_notify_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 001061a8 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 001061b0 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001061c0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001061d0 size=1
// signature: undefined _printk(void)
// callers: [qcom_collect_both_coredumps_store, rproc_recovery_notifier, qcom_rproc_shutdown_request_store, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 001061d8 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 001061e0 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 001061e8 size=1
// signature: undefined kobject_put(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_early_ssr_notify @ 001061f0 size=1
// signature: undefined qcom_glink_early_ssr_notify(void)
// callers: [glink_early_ssr_notifier_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_early_ssr_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 001061f8 size=1
// signature: undefined kstrtobool(void)
// callers: [qcom_collect_both_coredumps_store, qcom_rproc_shutdown_request_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00106200 size=1
// signature: undefined scnprintf(void)
// callers: [qcom_collect_both_coredumps_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00106208 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00106210 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00106218 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00106220 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00106228 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00106230 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 00106238 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00106240 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00106248 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_rproc_qcom_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



