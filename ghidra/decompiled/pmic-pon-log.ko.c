// Decompiled by Ghidra 12.2
// Program: pmic-pon-log.ko
// Image base: 00100000

//------------------------------------------------------------
// pmic_pon_log_probe @ 0010013c size=3788
// signature: undefined pmic_pon_log_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

ulong pmic_pon_log_probe(long param_1)

{
  int iVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  ushort uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  long *plVar10;
  undefined8 uVar11;
  ulong uVar12;
  ulong *puVar13;
  long lVar14;
  long *plVar15;
  long lVar16;
  char *pcVar17;
  byte *pbVar18;
  undefined **ppuVar19;
  undefined *puVar20;
  undefined8 *puVar21;
  long lVar22;
  ulong uVar23;
  uint uVar24;
  bool bVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  ulong uVar29;
  byte local_110 [4];
  byte local_10c [4];
  undefined4 local_108;
  undefined8 local_100;
  undefined4 local_f8;
  long local_f0 [18];
  
  lVar14 = sp_el0;
  lVar16 = param_1 + 0x10;
  local_f0[0x10] = *(long *)(lVar14 + 0x638);
  local_f8 = 0;
  local_100 = 0;
  local_110[0] = 0;
  plVar10 = (long *)devm_kmalloc(lVar16,0x30,0xdc0);
  if (plVar10 == (long *)0x0) {
LAB_0010039c:
    uVar29 = 0xfffffff4;
    goto LAB_00100d2c;
  }
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  *plVar10 = lVar16;
  uVar12 = of_count_phandle_with_args(uVar11,"nvmem",0);
  uVar29 = uVar12 & 0xffffffff;
  iVar8 = (int)uVar12;
  if (iVar8 < 0) {
    if (iVar8 == -0x205) {
LAB_00100d28:
      uVar29 = 0xfffffdfb;
    }
    else {
      _dev_err(lVar16,"failed to get nvmem count, ret=%d\n",uVar29);
    }
    goto LAB_00100d2c;
  }
  if (iVar8 == 0) {
    _dev_err(lVar16,"nvmem property empty\n");
    uVar29 = 0xffffffea;
    goto LAB_00100d2c;
  }
  *(int *)(plVar10 + 5) = iVar8;
  puVar13 = (ulong *)devm_kmalloc(lVar16,(uVar12 & 0xffffffff) << 3,0xdc0);
  plVar10[4] = (long)puVar13;
  if (puVar13 == (ulong *)0x0) goto LAB_0010039c;
  if (0 < (int)plVar10[5]) {
    uVar12 = 0;
    do {
      scnprintf(&local_100,0xc,"pon_log%d",uVar12 & 0xffffffff);
      uVar11 = devm_nvmem_device_get(lVar16,&local_100);
      *(undefined8 *)(plVar10[4] + uVar12 * 8) = uVar11;
      puVar13 = (ulong *)plVar10[4];
      uVar29 = puVar13[uVar12];
      if (((uVar29 != 0x205) && (0xfffffffffffff000 < uVar29)) && (uVar12 == 0)) {
        uVar11 = devm_nvmem_device_get(lVar16,"pon_log");
        *(undefined8 *)plVar10[4] = uVar11;
        puVar13 = (ulong *)plVar10[4];
        uVar29 = *puVar13;
      }
      if (0xfffffffffffff000 < uVar29) {
        if ((int)uVar29 == -0x205) goto LAB_00100d28;
        _dev_err(lVar16,"failed to get nvmem device %d, ret=%d\n",uVar12 & 0xffffffff,
                 uVar29 & 0xffffffff);
        goto LAB_00100d2c;
      }
      uVar12 = uVar12 + 1;
    } while ((long)uVar12 < (long)(int)plVar10[5]);
  }
  uVar29 = nvmem_device_read(*puVar13,0x45,1,local_110);
  if ((int)uVar29 < 0) {
    uVar29 = uVar29 & 0xffffffff;
    goto LAB_00100d2c;
  }
  *(int *)((long)plVar10 + 0x2c) = (int)((ulong)local_110[0] + 1);
  if ((int)plVar10[5] <= (int)(uint)local_110[0]) {
    _dev_err(lVar16,"Missing nvmem handles; found %d, expected %d\n");
    uVar29 = 0xffffffed;
    goto LAB_00100d2c;
  }
  uVar12 = ((ulong)local_110[0] + 1) * 0x75;
  *(int *)((long)plVar10 + 0x14) = (int)(uVar12 >> 2);
  lVar14 = devm_kmalloc(lVar16,uVar12 & 0xfffc,0xdc0);
  plVar10[1] = lVar14;
  if (lVar14 == 0) goto LAB_0010039c;
  lVar14 = ipc_log_context_create(3,"pmic_pon",0);
  puVar21 = (undefined8 *)plVar10[4];
  plVar10[3] = lVar14;
  *(long **)(param_1 + 0xa8) = plVar10;
  local_108 = 0;
  local_10c[0] = 0;
  uVar29 = nvmem_device_read(*puVar21,0x46,1,local_10c);
  bVar4 = local_10c[0];
  if ((int)uVar29 < 0) {
LAB_00100d90:
    uVar29 = uVar29 & 0xffffffff;
LAB_00100df4:
    _dev_err(lVar16,"PMIC PON log parsing failed, ret=%d\n",uVar29);
  }
  else {
    if ((byte)(local_10c[0] + 0x40) < 0x8b) {
      lVar14 = *plVar10;
      pcVar17 = "unexpected PON log end address: %02X\n";
LAB_00100dec:
      _dev_err(lVar14,pcVar17,local_10c[0]);
      uVar29 = 0xffffffea;
      goto LAB_00100df4;
    }
    uVar29 = nvmem_device_read(*(undefined8 *)plVar10[4],0x47,1,local_10c);
    if ((int)uVar29 < 0) goto LAB_00100d90;
    if (*(int *)((long)plVar10 + 0x2c) <= (int)(uint)local_10c[0]) {
      lVar14 = *plVar10;
      pcVar17 = "unexpected PON log end SDAM index: %d\n";
      goto LAB_00100dec;
    }
    iVar8 = *(int *)((long)plVar10 + 0x14);
    if (0 < iVar8) {
      iVar27 = 0;
      uVar26 = ((*(int *)((long)plVar10 + 0x2c) * 0x75 &
                (int)((uint)bVar4 + (uint)local_10c[0] * 0x75 + iVar8 * -4 + -0x4b) >> 0x1f) +
                (uint)local_10c[0] * 0x75 + (uint)bVar4 + iVar8 * -4) - 0x4b;
      do {
        uVar24 = *(int *)((long)plVar10 + 0x2c) * 0x75;
        uVar28 = 0;
        if (uVar24 != 0) {
          uVar28 = uVar26 / uVar24;
        }
        uVar28 = uVar26 - uVar28 * uVar24;
        uVar24 = uVar28 / 0x75;
        uVar28 = uVar28 % 0x75;
        iVar8 = uVar28 + 0x4b;
        if (uVar28 < 0x72) {
          pbVar18 = (byte *)&local_108;
          lVar14 = 4;
          uVar11 = *(undefined8 *)(plVar10[4] + (ulong)uVar24 * 8);
        }
        else {
          uVar12 = (ulong)(0x75 - uVar28);
          uVar29 = nvmem_device_read(*(undefined8 *)(plVar10[4] + (ulong)uVar24 * 8),iVar8,uVar12,
                                     &local_108);
          if ((int)uVar29 < 0) goto LAB_00100d90;
          iVar1 = *(int *)((long)plVar10 + 0x2c);
          iVar8 = 0x4b;
          iVar5 = 0;
          if (iVar1 != 0) {
            iVar5 = (int)(uVar24 + 1) / iVar1;
          }
          uVar11 = *(undefined8 *)(plVar10[4] + (ulong)((uVar24 + 1) - iVar5 * iVar1) * 8);
          lVar14 = 4 - uVar12;
          pbVar18 = local_10c + uVar12 + 4;
        }
        uVar12 = nvmem_device_read(uVar11,iVar8,lVar14,pbVar18);
        uVar29 = uVar12 & 0xffffffff;
        if ((int)uVar12 < 0) goto LAB_00100df4;
        cVar3 = local_108._2_1_;
        bVar4 = local_108._3_1_;
        uVar12 = (ulong)local_108._3_1_;
        uVar24 = (uint)local_108._1_1_;
        if ((((byte)local_108 == 0) && (uVar24 == 0)) &&
           ((local_108._2_1_ == '\0' && (local_108._3_1_ == 0)))) goto LAB_001003f8;
        lVar14 = plVar10[3];
        uVar6 = CONCAT11(local_108._2_1_,local_108._3_1_);
        uVar9 = (uint)uVar6;
        uVar28 = (uint)(uVar24 < 0x21) & (uint)(0x11fff16c2 >> ((ulong)local_108._1_1_ & 0x3f));
        local_f0[0xe] = 0;
        local_f0[0xf] = 0;
        local_f0[0xc] = 0;
        local_f0[0xd] = 0;
        local_f0[10] = 0;
        local_f0[0xb] = 0;
        local_f0[8] = 0;
        local_f0[9] = 0;
        local_f0[6] = 0;
        local_f0[7] = 0;
        local_f0[4] = 0;
        local_f0[5] = 0;
        local_f0[2] = 0;
        local_f0[3] = 0;
        local_f0[0] = 0;
        local_f0[1] = 0;
        switch(uVar24) {
        case 1:
          if (uVar9 < 0x18a0) {
            if (uVar9 < 0x202) {
              lVar22 = 0;
              switch(uVar9) {
              case 0x84:
                break;
              case 0x85:
                lVar22 = 1;
                break;
              case 0x86:
                lVar22 = 2;
                break;
              case 0x87:
                lVar22 = 3;
                break;
              default:
switchD_00100674_default:
                pcVar17 = "PON Trigger: ";
                goto LAB_00100cd8;
              }
            }
            else if (uVar9 == 0x202) {
              lVar22 = 4;
            }
            else if (uVar9 == 0x621) {
              lVar22 = 5;
            }
            else {
              if (uVar9 != 0x640) goto switchD_00100674_default;
              lVar22 = 6;
            }
          }
          else if (uVar9 < 0x31c2) {
            if (uVar9 == 0x18a0) {
              lVar22 = 7;
            }
            else if (uVar9 == 0x18c0) {
              lVar22 = 8;
            }
            else {
              if (uVar9 != 0x2763) goto switchD_00100674_default;
              lVar22 = 9;
            }
          }
          else if (uVar9 == 0x31c2) {
            lVar22 = 10;
          }
          else if (uVar9 == 0x71c2) {
            lVar22 = 0xb;
          }
          else {
            if (uVar9 != 0x8732) goto switchD_00100674_default;
            lVar22 = 0xc;
          }
          puVar20 = &pmic_pon_pon_trigger_map + lVar22 * 0x10;
          pcVar17 = "PON Trigger: ";
          goto LAB_00100c50;
        case 2:
          pcVar17 = "OTP Copy Complete: last addr written=0x%04X";
          goto LAB_001007c4;
        case 3:
          pcVar17 = "Trim Complete: %u bytes written";
          goto LAB_001007c4;
        case 4:
          pcVar17 = "XVLO Check Complete";
          goto LAB_0010090c;
        case 5:
          pcVar17 = "PMICs Detected: SID Mask=0x%04X";
          goto LAB_001007c4;
        case 6:
          if (uVar9 < 0x11d0) {
            lVar22 = 0;
            switch(uVar9) {
            case 0x80:
              break;
            case 0x81:
              lVar22 = 1;
              break;
            case 0x82:
              lVar22 = 2;
              break;
            case 0x83:
              lVar22 = 3;
              break;
            case 0x84:
              lVar22 = 4;
              break;
            case 0x85:
              lVar22 = 5;
              break;
            case 0x86:
              lVar22 = 6;
              break;
            case 0x87:
              lVar22 = 7;
              break;
            default:
switchD_00100700_default:
              pcVar17 = "Reset Trigger: ";
LAB_00100cd8:
              uVar24 = scnprintf(local_f0,0x80,pcVar17);
              if (0x80 < uVar24) goto LAB_00100f60;
              scnprintf((long)local_f0 + (ulong)uVar24,0x80 - uVar24,
                        "SID=0x%X, PID=0x%02X, IRQ=0x%X",local_108._2_1_ >> 4,uVar6 >> 4 & 0xff,
                        local_108 >> 0x18 & 7);
              goto joined_r0x00100d18;
            }
          }
          else if (uVar9 < 0x31f5) {
            if (uVar9 == 0x11d0) {
              lVar22 = 10;
            }
            else if (uVar9 == 0x21d0) {
              lVar22 = 0xb;
            }
            else {
              if (uVar9 != 0x21e3) goto switchD_00100700_default;
              lVar22 = 8;
            }
          }
          else if (uVar9 == 0x31f5) {
            lVar22 = 9;
          }
          else if (uVar9 == 0x41d0) {
            lVar22 = 0xc;
          }
          else {
            if (uVar9 != 0x51d0) goto switchD_00100700_default;
            lVar22 = 0xd;
          }
          puVar20 = &pmic_pon_reset_trigger_map + lVar22 * 0x10;
          pcVar17 = "Reset Trigger: ";
LAB_00100c50:
          uVar11 = *(undefined8 *)(puVar20 + 8);
          uVar24 = scnprintf(local_f0,0x80,pcVar17);
          if (0x80 < uVar24) {
LAB_00100f60:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x100f64);
            (*pcVar7)();
          }
          plVar15 = (long *)((long)local_f0 + (ulong)uVar24);
          iVar8 = 0x80 - uVar24;
          pcVar17 = "%s";
LAB_00100c80:
          scnprintf(plVar15,iVar8,pcVar17,uVar11);
          break;
        case 7:
          if ((7 < local_108._3_1_) || ((0x6dUL >> (uVar12 & 0x3f) & 1) != 0)) {
            pcVar17 = "Reset Type: UNKNOWN (%u)";
            goto LAB_001007c8;
          }
          if (7 < local_108._3_1_) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(1,0x101008);
            (*pcVar7)();
          }
          plVar15 = local_f0;
          iVar8 = 0x80;
          uVar11 = *(undefined8 *)(pmic_pon_reset_type_label + uVar12 * 8);
          pcVar17 = "Reset Type: %s";
          goto LAB_00100c80;
        case 8:
          pcVar17 = "Warm Reset Count: %u";
          goto LAB_001007c8;
        case 9:
          if (local_108._3_1_ == 0) {
            uVar24 = 1;
            if ((local_108._2_1_ == '\0') || (uVar28 == 0)) {
              uVar28 = 0;
              goto LAB_00100a90;
            }
            uVar9 = 0;
            puVar20 = &DAT_00101c26;
          }
          else {
            uVar24 = uVar28 ^ 1;
LAB_00100a90:
            uVar9 = scnprintf(local_f0,0x80,"FAULT_REASON1=");
            if (0x80 < uVar9) goto LAB_00100f60;
            iVar8 = pmic_pon_log_print_reason
                              ((long)local_f0 + (ulong)uVar9,0x80 - uVar9,local_108._3_1_,
                               &pmic_pon_fault_reason1);
            if (((uint)(local_108._2_1_ == '\0') & (uVar24 ^ 0xffffffff)) != 0) break;
            uVar9 = iVar8 + uVar9;
            if (0x80 < uVar9) goto LAB_00100f60;
            if (local_108._3_1_ != '\0') {
              uVar24 = 1;
            }
            puVar20 = &DAT_00101b8f;
            if (uVar24 == 0) {
              puVar20 = &DAT_00101c26;
            }
            uVar24 = (uint)(uVar28 != 0);
          }
          iVar8 = scnprintf((long)local_f0 + (ulong)uVar9,0x80 - uVar9,"%sFAULT_REASON2=",puVar20);
          uVar9 = iVar8 + uVar9;
          if (0x80 < uVar9) goto LAB_00100f60;
          pmic_pon_log_print_reason
                    ((long)local_f0 + (ulong)uVar9,0x80 - uVar9,local_108._2_1_,
                     &pmic_pon_fault_reason2);
          uVar28 = uVar24;
          break;
        case 10:
          uVar24 = scnprintf(local_f0,0x80,"FAULT_REASON3=");
          if (0x80 < uVar24) goto LAB_00100f60;
          pmic_pon_log_print_reason
                    ((long)local_f0 + (ulong)uVar24,0x80 - uVar24,local_108._3_1_,
                     &pmic_pon_fault_reason3);
          if (bVar4 == 0) goto LAB_00100c98;
          break;
        case 0xb:
          pcVar17 = "PBS PC at Fault: 0x%04X";
LAB_001007c4:
          uVar12 = (ulong)uVar9;
LAB_001007c8:
          scnprintf(local_f0,0x80,pcVar17,uVar12);
          break;
        case 0xc:
          uVar24 = scnprintf(local_f0,0x80,"Fundamental Reset: ");
          uVar9 = 0;
          if (bVar4 != 0 || cVar3 != '\0') {
            uVar9 = uVar28;
          }
          if ((local_108._2_1_ != '\0') || (uVar9 == 0)) {
            if (0x80 < uVar24) goto LAB_00100f60;
            iVar8 = scnprintf((long)local_f0 + (ulong)uVar24,0x80 - uVar24,"PON_PBL_STATUS=");
            uVar24 = iVar8 + uVar24;
            if (0x80 < uVar24) goto LAB_00100f60;
            iVar8 = pmic_pon_log_print_reason
                              ((long)local_f0 + (ulong)uVar24,0x80 - uVar24,local_108._2_1_,
                               &pmic_pon_pon_pbl_status);
            uVar24 = iVar8 + uVar24;
          }
          uVar28 = 0;
          if (local_108._3_1_ == '\0') {
            uVar28 = uVar9;
          }
          if (uVar28 == 0) {
            if (0x80 < uVar24) goto LAB_00100f60;
            puVar20 = &DAT_00101c26;
            if ((local_108._2_1_ == '\0' & uVar9) == 0) {
              puVar20 = &DAT_00101b8f;
            }
            iVar8 = scnprintf((long)local_f0 + (ulong)uVar24,0x80 - uVar24,"%sS3_RESET_REASON=",
                              puVar20);
            uVar24 = iVar8 + uVar24;
            if (0x80 < uVar24) goto LAB_00100f60;
            lVar22 = (long)local_f0 + (ulong)uVar24;
            ppuVar19 = &pmic_pon_s3_reset_reason;
            uVar2 = local_108._3_1_;
LAB_00100630:
            pmic_pon_log_print_reason(lVar22,0x80 - uVar24,uVar2,ppuVar19);
            uVar28 = uVar9;
            break;
          }
          goto LAB_00100c88;
        case 0xd:
          pcVar17 = "Begin PON Sequence";
          goto LAB_0010090c;
        case 0xe:
          pcVar17 = "PON Successful";
          goto LAB_0010090c;
        case 0xf:
          pcVar17 = "Waiting on PS_HOLD";
LAB_0010090c:
          scnprintf(local_f0,0x80,pcVar17);
          break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
          uVar24 = scnprintf(local_f0,0x80,"PMIC SID%u ",uVar24 - 0xf);
          uVar9 = 0;
          if (bVar4 != 0 || cVar3 != '\0') {
            uVar9 = uVar28;
          }
          if ((local_108._3_1_ != '\0') || (uVar9 == 0)) {
            if (0x80 < uVar24) goto LAB_00100f60;
            iVar8 = scnprintf((long)local_f0 + (ulong)uVar24,0x80 - uVar24,"FAULT_REASON1=");
            uVar24 = iVar8 + uVar24;
            if (0x80 < uVar24) goto LAB_00100f60;
            iVar8 = pmic_pon_log_print_reason
                              ((long)local_f0 + (ulong)uVar24,0x80 - uVar24,local_108._3_1_,
                               &pmic_pon_fault_reason1);
            uVar24 = iVar8 + uVar24;
          }
          uVar28 = 0;
          if (local_108._2_1_ == '\0') {
            uVar28 = uVar9;
          }
          if (uVar28 == 0) {
            if (0x80 < uVar24) goto LAB_00100f60;
            puVar20 = &DAT_00101c26;
            if ((local_108._3_1_ == '\0' & uVar9) == 0) {
              puVar20 = &DAT_00101b8f;
            }
            iVar8 = scnprintf((long)local_f0 + (ulong)uVar24,0x80 - uVar24,"%sFAULT_REASON2=",
                              puVar20);
            uVar24 = iVar8 + uVar24;
            if (0x80 < uVar24) goto LAB_00100f60;
            lVar22 = (long)local_f0 + (ulong)uVar24;
            ppuVar19 = &pmic_pon_fault_reason2;
            uVar2 = local_108._2_1_;
            goto LAB_00100630;
          }
          goto LAB_00100c88;
        default:
          scnprintf(local_f0,0x80,"Unknown Event (0x%02X): data=0x%04X",(ulong)local_108._1_1_,uVar9
                   );
          break;
        case 0x20:
          puVar20 = &DAT_00101c26;
          if (uVar9 == 0) {
            puVar20 = &DAT_00101e16;
          }
          scnprintf(local_f0,0x80,"VREG Check: %sVREG_FAULT detected",puVar20);
          if (uVar9 != 0) break;
          goto LAB_00100c98;
        }
joined_r0x00100d18:
        if (uVar28 != 0) {
LAB_00100c88:
          _printk(&DAT_00101f5d,local_f0);
        }
LAB_00100c98:
        uVar12 = (ulong)(byte)local_108;
        if (uVar12 < 8) {
          ipc_log_string(lVar14,"State=%s; %s\n",(&pmic_pon_state_label)[uVar12],local_f0);
        }
        else {
          ipc_log_string(lVar14,"State=Unknown (0x%02X); %s\n",uVar12,local_f0);
        }
        lVar14 = plVar10[2];
        *(int *)(plVar10 + 2) = (int)lVar14 + 1;
        *(uint *)(plVar10[1] + (long)(int)lVar14 * 4) = local_108;
LAB_001003f8:
        iVar27 = iVar27 + 1;
        uVar26 = uVar26 + 4;
      } while (iVar27 < *(int *)((long)plVar10 + 0x14));
    }
    uVar29 = 0;
  }
  lVar16 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,pmic-fault-panic",0);
  if (lVar16 != 0) {
    local_f0[0xe] = 0;
    local_f0[0xf] = 0;
    local_f0[0xc] = 0;
    local_f0[0xd] = 0;
    local_f0[10] = 0;
    local_f0[0xb] = 0;
    uVar26 = (int)plVar10[2] - 1;
    uVar12 = (ulong)uVar26;
    local_f0[8] = 0;
    local_f0[9] = 0;
    local_f0[6] = 0;
    local_f0[7] = 0;
    local_f0[4] = 0;
    local_f0[5] = 0;
    local_f0[2] = 0;
    local_f0[3] = 0;
    local_f0[0] = 0;
    local_f0[1] = 0;
    if (-1 < (int)uVar26) {
      bVar25 = false;
      uVar24 = 0;
      uVar23 = uVar12;
      do {
        uVar26 = (uint)uVar12;
        cVar3 = *(char *)(plVar10[1] + uVar23 * 4 + 1);
        if (cVar3 == '\b') {
          uVar24 = (uint)*(byte *)(plVar10[1] + uVar23 * 4 + 3);
        }
        else if (cVar3 == '\x0e') {
          if (bVar25) {
            if ((int)uVar24 < 1) goto LAB_00100eb0;
            bVar25 = true;
            uVar24 = uVar24 - 1;
          }
          else {
            bVar25 = true;
            uVar12 = uVar23;
          }
        }
        uVar26 = (uint)uVar12;
        uVar28 = (int)uVar23 - 1;
        uVar23 = (ulong)uVar28;
      } while (-1 < (int)uVar28);
    }
    uVar23 = 0;
LAB_00100eb0:
    if ((int)uVar23 <= (int)uVar26) {
      lVar16 = plVar10[1];
      do {
        iVar8 = (int)uVar23;
        lVar14 = (long)iVar8;
        bVar4 = *(byte *)(lVar16 + (long)iVar8 * 4 + 1);
        if (bVar4 - 0x10 < 0xd) {
          lVar22 = lVar16 + lVar14 * 4;
          cVar3 = *(char *)(lVar22 + 3);
          if (cVar3 != '\0') {
            pmic_pon_log_print_reason(local_f0,0x80,cVar3,&pmic_pon_fault_reason1);
            lVar16 = plVar10[1];
            pcVar17 = "PMIC SID%u FAULT; FAULT_REASON1=%s";
LAB_00100fa8:
                    /* WARNING: Subroutine does not return */
            panic(pcVar17,*(byte *)(lVar16 + lVar14 * 4 + 1) - 0xf,local_f0);
          }
          bVar4 = *(byte *)(lVar22 + 2);
          if ((bVar4 & 0xb7) != 0) {
            pmic_pon_log_print_reason(local_f0,0x80,bVar4,&pmic_pon_fault_reason2);
            lVar16 = plVar10[1];
            pcVar17 = "PMIC SID%u FAULT; FAULT_REASON2=%s";
            goto LAB_00100fa8;
          }
        }
        else if (bVar4 == 10) {
          cVar3 = *(char *)(lVar16 + lVar14 * 4 + 3);
          if (cVar3 != '\0') {
            pmic_pon_log_print_reason(local_f0,0x80,cVar3,&pmic_pon_fault_reason3);
                    /* WARNING: Subroutine does not return */
            panic("PMIC SID0 FAULT; FAULT_REASON3=%s",local_f0);
          }
        }
        else if (bVar4 == 9) {
          lVar14 = lVar16 + lVar14 * 4;
          cVar3 = *(char *)(lVar14 + 3);
          if (cVar3 != '\0') {
            pmic_pon_log_print_reason(local_f0,0x80,cVar3,&pmic_pon_fault_reason1);
                    /* WARNING: Subroutine does not return */
            panic("PMIC SID0 FAULT; FAULT_REASON1=%s",local_f0);
          }
          bVar4 = *(byte *)(lVar14 + 2);
          if ((bVar4 & 0xb7) != 0) {
            pmic_pon_log_print_reason(local_f0,0x80,bVar4,&pmic_pon_fault_reason2);
                    /* WARNING: Subroutine does not return */
            panic("PMIC SID0 FAULT; FAULT_REASON2=%s",local_f0);
          }
        }
        uVar23 = (ulong)(iVar8 + 1U);
      } while ((int)(iVar8 + 1U) <= (int)uVar26);
    }
  }
LAB_00100d2c:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_f0[0x10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar29 & 0xffffffff;
}



//------------------------------------------------------------
// pmic_pon_log_remove @ 0010100c size=40
// signature: undefined pmic_pon_log_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_pon_log_remove(long param_1)

{
  ipc_log_context_destroy(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 0x18));
  return 0;
}



//------------------------------------------------------------
// pmic_pon_log_print_reason @ 00101034 size=648
// signature: undefined pmic_pon_log_print_reason(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

int pmic_pon_log_print_reason(long param_1,int param_2,uint param_3,undefined8 *param_4)

{
  undefined *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_3 & 0xff) == 0) {
    iVar3 = scnprintf(param_1,(long)param_2,&DAT_00102135);
    return iVar3;
  }
  uVar2 = (param_3 & 1) == 0;
  uVar5 = param_3 & 0xff;
  if ((param_3 & 1) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = scnprintf(param_1,(long)param_2,&DAT_00101c53,&DAT_00101c26,*param_4);
  }
  if ((uVar5 >> 1 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if ((param_3 & 1) != 0) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[1]);
    uVar2 = false;
    iVar3 = iVar4 + iVar3;
  }
  if ((uVar5 >> 2 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if (!(bool)uVar2) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[2]);
    uVar2 = false;
    iVar3 = iVar4 + iVar3;
  }
  if ((uVar5 >> 3 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if (!(bool)uVar2) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[3]);
    uVar2 = false;
    iVar3 = iVar4 + iVar3;
  }
  if ((uVar5 >> 4 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if (!(bool)uVar2) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[4]);
    uVar2 = false;
    iVar3 = iVar4 + iVar3;
  }
  if ((uVar5 >> 5 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if (!(bool)uVar2) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[5]);
    uVar2 = false;
    iVar3 = iVar4 + iVar3;
  }
  if ((uVar5 >> 6 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if (!(bool)uVar2) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[6]);
    uVar2 = false;
    iVar3 = iVar4 + iVar3;
  }
  if ((param_3 >> 7 & 1) != 0) {
    puVar1 = &DAT_00101c26;
    if (!(bool)uVar2) {
      puVar1 = &DAT_0010207e;
    }
    iVar4 = scnprintf(param_1 + iVar3,(long)(param_2 - iVar3),&DAT_00101c53,puVar1,param_4[7]);
    iVar3 = iVar4 + iVar3;
  }
  return iVar3;
}



//------------------------------------------------------------
// init_module @ 001012c0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pmic_pon_log_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001012f0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pmic_pon_log_driver);
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
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00103018 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103020 size=1
// signature: undefined scnprintf(void)
// callers: [pmic_pon_log_print_reason, pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_device_get @ 00103028 size=1
// signature: undefined devm_nvmem_device_get(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_device_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_read @ 00103030 size=1
// signature: undefined nvmem_device_read(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00103038 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103040 size=1
// signature: undefined _dev_err(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00103048 size=1
// signature: undefined ipc_log_string(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103050 size=1
// signature: undefined _printk(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103058 size=1
// signature: undefined of_find_property(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00103060 size=1
// signature: noreturn undefined panic(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pmic_pon_log_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00103070 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [pmic_pon_log_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



