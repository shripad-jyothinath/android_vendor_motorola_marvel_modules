// Decompiled by Ghidra 12.2
// Program: qcom-vadc-common.ko
// Image base: 00100000

//------------------------------------------------------------
// adc_tm_scale_therm_voltage_100k_gen3 @ 00100394 size=992
// signature: undefined adc_tm_scale_therm_voltage_100k_gen3(void)
// callers: []
//------------------------------------------------------------

void adc_tm_scale_therm_voltage_100k_gen3(int *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  
  iVar1 = *param_1;
  piVar8 = &DAT_001020e4;
  lVar11 = 0;
  do {
    if (iVar1 <= *piVar8) {
      uVar9 = (uint)lVar11;
      if (uVar9 == 0) {
        iVar10 = 0x40dc21;
        goto LAB_001003e4;
      }
      if (uVar9 != 0xffffff58) {
        uVar12 = (ulong)~uVar9;
        if ((0x540 < (uVar12 << 3 | 4)) || (0xa7 < uVar12)) goto LAB_00100770;
        iVar14 = (&adcmap7_100k)[uVar12 * 2];
        iVar2 = iVar1 - (&DAT_001020e4)[uVar12 * 2];
        iVar10 = iVar14;
        if (iVar2 != 0) {
          iVar4 = piVar8[-1];
          if (iVar4 - iVar14 != 0) {
            iVar3 = *piVar8 - (&DAT_001020e4)[uVar12 * 2];
            iVar10 = iVar4;
            if ((iVar3 != 0) && (*piVar8 != iVar1)) {
              iVar10 = 0;
              if (iVar3 != 0) {
                iVar10 = ((iVar4 - iVar14) * iVar2) / iVar3;
              }
              iVar10 = iVar10 + iVar14;
            }
          }
        }
        goto LAB_001003e4;
      }
      break;
    }
    piVar8 = piVar8 + 2;
    bVar7 = lVar11 != -0xa7;
    lVar11 = lVar11 + -1;
  } while (bVar7);
  iVar10 = 0x974;
LAB_001003e4:
  lVar11 = (long)iVar10 + 100000;
  uVar12 = 0;
  if (lVar11 != 0) {
    uVar12 = (long)((ulong)*(uint *)(param_2 + 0x10) * (long)iVar10) / lVar11;
  }
  *(ulong *)(param_1 + 4) = uVar12;
  if (((uint)uVar12 & 0xffff) < *(uint *)(param_2 + 0x10)) {
    lVar11 = ((ulong)*(uint *)(param_2 + 0x10) & 0xffff) - (uVar12 & 0xffff);
    iVar10 = 0;
    if (lVar11 != 0) {
      iVar10 = (int)((long)((uVar12 & 0xffff) * 100000) / lVar11);
    }
    piVar8 = &adcmap7_100k;
    lVar11 = 0;
    do {
      if (*piVar8 <= iVar10) {
        uVar9 = (uint)lVar11;
        if (uVar9 == 0) {
          iVar14 = -0xa000;
          goto LAB_001004e8;
        }
        if (uVar9 != 0xffffff58) {
          uVar13 = (ulong)~uVar9;
          if (((0xa7 < ~uVar9) || (0x540 < (uVar13 << 3 | 4))) || (0x540 < (uVar13 << 3 | 4)))
          goto LAB_00100770;
          iVar4 = (&adcmap7_100k)[uVar13 * 2];
          iVar2 = (&DAT_001020e4)[uVar13 * 2];
          iVar14 = iVar2;
          if (iVar4 != iVar10) {
            iVar3 = piVar8[1];
            if (iVar3 - iVar2 != 0) {
              iVar5 = *piVar8 - iVar4;
              iVar14 = iVar3;
              if ((iVar5 != 0) && (*piVar8 != iVar10)) {
                iVar14 = 0;
                if (iVar5 != 0) {
                  iVar14 = ((iVar3 - iVar2) * (iVar10 - iVar4)) / iVar5;
                }
                iVar14 = iVar14 + iVar2;
              }
            }
          }
          goto LAB_001004e8;
        }
        break;
      }
      piVar8 = piVar8 + 2;
      bVar7 = lVar11 != -0xa7;
      lVar11 = lVar11 + -1;
    } while (bVar7);
    iVar14 = 0x1fc00;
LAB_001004e8:
    if (iVar14 < iVar1) {
      *(ulong *)(param_1 + 4) = uVar12 - 1;
    }
    iVar1 = param_1[1];
    piVar8 = &DAT_001020e4;
    lVar11 = 0;
    do {
      if (iVar1 <= *piVar8) {
        uVar9 = (uint)lVar11;
        if (uVar9 == 0) {
          iVar10 = 0x40dc21;
          goto LAB_001005c8;
        }
        if (uVar9 != 0xffffff58) {
          uVar12 = (ulong)~uVar9;
          if ((0x540 < (uVar12 << 3 | 4)) || (0xa7 < uVar12)) goto LAB_00100770;
          iVar14 = (&adcmap7_100k)[uVar12 * 2];
          iVar2 = iVar1 - (&DAT_001020e4)[uVar12 * 2];
          iVar10 = iVar14;
          if (iVar2 != 0) {
            iVar4 = piVar8[-1];
            if (iVar4 - iVar14 != 0) {
              iVar3 = *piVar8 - (&DAT_001020e4)[uVar12 * 2];
              iVar10 = iVar4;
              if ((iVar3 != 0) && (*piVar8 != iVar1)) {
                iVar10 = 0;
                if (iVar3 != 0) {
                  iVar10 = ((iVar4 - iVar14) * iVar2) / iVar3;
                }
                iVar10 = iVar10 + iVar14;
              }
            }
          }
          goto LAB_001005c8;
        }
        break;
      }
      piVar8 = piVar8 + 2;
      bVar7 = lVar11 != -0xa7;
      lVar11 = lVar11 + -1;
    } while (bVar7);
    iVar10 = 0x974;
LAB_001005c8:
    lVar11 = (long)iVar10 + 100000;
    uVar12 = 0;
    if (lVar11 != 0) {
      uVar12 = (long)((ulong)*(uint *)(param_2 + 0x10) * (long)iVar10) / lVar11;
    }
    *(ulong *)(param_1 + 2) = uVar12;
    if (((uint)uVar12 & 0xffff) < *(uint *)(param_2 + 0x10)) {
      lVar11 = ((ulong)*(uint *)(param_2 + 0x10) & 0xffff) - (uVar12 & 0xffff);
      iVar10 = 0;
      if (lVar11 != 0) {
        iVar10 = (int)((long)((uVar12 & 0xffff) * 100000) / lVar11);
      }
      piVar8 = &adcmap7_100k;
      lVar11 = 0;
      do {
        if (*piVar8 <= iVar10) {
          uVar9 = (uint)lVar11;
          if (uVar9 == 0) {
            iVar14 = -0xa000;
            goto LAB_0010075c;
          }
          if (uVar9 != 0xffffff58) {
            uVar13 = (ulong)~uVar9;
            if (((0xa7 < ~uVar9) || (0x540 < (uVar13 << 3 | 4))) || (0x540 < (uVar13 << 3 | 4))) {
LAB_00100770:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(1,0x100774);
              (*pcVar6)();
            }
            iVar4 = (&adcmap7_100k)[uVar13 * 2];
            iVar2 = (&DAT_001020e4)[uVar13 * 2];
            iVar14 = iVar2;
            if (iVar4 != iVar10) {
              iVar3 = piVar8[1];
              if (iVar3 - iVar2 != 0) {
                iVar5 = *piVar8 - iVar4;
                iVar14 = iVar3;
                if ((iVar5 != 0) && (*piVar8 != iVar10)) {
                  iVar14 = 0;
                  if (iVar5 != 0) {
                    iVar14 = ((iVar3 - iVar2) * (iVar10 - iVar4)) / iVar5;
                  }
                  iVar14 = iVar14 + iVar2;
                }
              }
            }
            goto LAB_0010075c;
          }
          break;
        }
        piVar8 = piVar8 + 2;
        bVar7 = lVar11 != -0xa7;
        lVar11 = lVar11 + -1;
      } while (bVar7);
      iVar14 = 0x1fc00;
LAB_0010075c:
      if (iVar1 < iVar14) {
        *(ulong *)(param_1 + 2) = uVar12 + 1;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// qcom_vadc7_scale_hw_calib_therm @ 00100778 size=260
// signature: undefined qcom_vadc7_scale_hw_calib_therm(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc7_scale_hw_calib_therm(undefined8 param_1,long param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  long lVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  ulong uVar12;
  
  if (*(uint *)(param_2 + 0x10) <= (param_3 & 0xffff)) {
    return 0xffffffea;
  }
  lVar8 = ((ulong)*(uint *)(param_2 + 0x10) & 0xffff) - ((ulong)param_3 & 0xffff);
  iVar4 = 0;
  if (lVar8 != 0) {
    iVar4 = (int)((long)(((ulong)param_3 & 0xffff) * 100000) / lVar8);
  }
  piVar9 = &adcmap7_100k;
  lVar8 = 0;
  do {
    if (*piVar9 <= iVar4) {
      uVar11 = (uint)lVar8;
      if (uVar11 == 0) {
        iVar10 = -0xa000;
        goto LAB_001007f4;
      }
      if (uVar11 != 0xffffff58) {
        uVar12 = (ulong)~uVar11;
        if ((0xa7 < ~uVar11) || (0x540 < (uVar12 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x10087c);
          (*pcVar6)();
        }
        iVar3 = (&adcmap7_100k)[uVar12 * 2];
        iVar1 = (&DAT_001020e4)[uVar12 * 2];
        iVar10 = iVar1;
        if (iVar3 != iVar4) {
          iVar2 = piVar9[1];
          if (iVar2 - iVar1 != 0) {
            iVar5 = *piVar9 - iVar3;
            iVar10 = iVar2;
            if ((iVar5 != 0) && (*piVar9 != iVar4)) {
              iVar10 = 0;
              if (iVar5 != 0) {
                iVar10 = ((iVar2 - iVar1) * (iVar4 - iVar3)) / iVar5;
              }
              iVar10 = iVar10 + iVar1;
            }
          }
        }
        goto LAB_001007f4;
      }
      break;
    }
    piVar9 = piVar9 + 2;
    bVar7 = lVar8 != -0xa7;
    lVar8 = lVar8 + -1;
  } while (bVar7);
  iVar10 = 0x1fc00;
LAB_001007f4:
  *param_4 = iVar10;
  return 0;
}



//------------------------------------------------------------
// adc_tm_absolute_rthr_gen3 @ 00100880 size=80
// signature: undefined adc_tm_absolute_rthr_gen3(void)
// callers: []
//------------------------------------------------------------

undefined8 adc_tm_absolute_rthr_gen3(long param_1)

{
  *(long *)(param_1 + 8) = (*(long *)(param_1 + 8) * 0x70e4) / 0x1c9c38;
  *(long *)(param_1 + 0x10) = (*(long *)(param_1 + 0x10) * 0x70e4) / 0x1c9c38;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale @ 001008d4 size=620
// signature: undefined qcom_vadc_scale(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale(undefined4 param_1,int *param_2,uint *param_3,uint param_4,uint param_5,int *param_6
               )

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auVar4 [16];
  int iVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  
  switch(param_1) {
  case 0:
    lVar12 = (long)param_2[1];
    lVar11 = 0;
    if ((long)*param_2 != 0) {
      lVar11 = ((long)param_2[1] * (long)(int)((param_5 & 0xffff) - param_2[2])) / (long)*param_2;
    }
    if ((param_4 & 1) == 0) {
      lVar12 = 0;
    }
    lVar11 = lVar11 + lVar12;
    if (lVar11 < 1) {
      lVar11 = 0;
    }
    iVar10 = 0;
    if ((ulong)*param_3 != 0) {
      iVar10 = (int)((long)(lVar11 * (ulong)param_3[1]) / (long)(ulong)*param_3);
    }
    break;
  case 1:
  case 3:
    lVar11 = (long)param_2[1];
    lVar12 = 0;
    if ((long)*param_2 != 0) {
      lVar12 = ((long)param_2[1] * (long)(int)((param_5 & 0xffff) - param_2[2])) / (long)*param_2;
    }
    if ((param_4 & 1) == 0) {
      lVar11 = 0;
    }
    uVar14 = lVar12 + lVar11;
    if ((long)uVar14 < 1) {
      uVar14 = 0;
    }
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar14;
    iVar8 = (int)(SUB168(auVar4 * ZEXT816(0x20c49ba5e353f7cf),8) >> 7);
    if ((param_4 & 1) == 0) {
      iVar8 = (int)uVar14;
    }
    piVar9 = &adcmap_100k_104ef_104fb;
    lVar11 = 0;
    do {
      if (*piVar9 <= iVar8) {
        uVar13 = (uint)lVar11;
        if (uVar13 == 0) {
          iVar10 = -40000;
          goto LAB_00100aa8;
        }
        if (uVar13 != 0xffffffde) {
          uVar14 = (ulong)~uVar13;
          if (((0x21 < ~uVar13) || (0x110 < (uVar14 << 3 | 4))) || (0x110 < (uVar14 << 3 | 4))) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(1,0x100b40);
            (*pcVar6)();
          }
          iVar3 = (&adcmap_100k_104ef_104fb)[uVar14 * 2];
          iVar1 = *(int *)(&DAT_001028b4 + uVar14 * 8);
          iVar10 = iVar1;
          if (iVar3 != iVar8) {
            iVar2 = piVar9[1];
            if (iVar2 - iVar1 != 0) {
              iVar5 = *piVar9 - iVar3;
              iVar10 = iVar2;
              if ((iVar5 != 0) && (*piVar9 != iVar8)) {
                iVar10 = 0;
                if (iVar5 != 0) {
                  iVar10 = ((iVar2 - iVar1) * (iVar8 - iVar3)) / iVar5;
                }
                iVar10 = iVar10 + iVar1;
              }
            }
          }
          goto LAB_00100aa8;
        }
        break;
      }
      piVar9 = piVar9 + 2;
      bVar7 = lVar11 != -0x21;
      lVar11 = lVar11 + -1;
    } while (bVar7);
    iVar10 = 0x1e848;
    break;
  case 2:
    lVar11 = (long)param_2[1];
    lVar12 = 0;
    if ((long)*param_2 != 0) {
      lVar12 = ((long)param_2[1] * (long)(int)((param_5 & 0xffff) - param_2[2])) / (long)*param_2;
    }
    if ((param_4 & 1) == 0) {
      lVar11 = 0;
    }
    iVar10 = -0x42afe;
    if (0 < lVar12 + lVar11) {
      iVar10 = 0;
      if ((ulong)(*param_3 << 1) != 0) {
        iVar10 = (int)(((lVar12 + lVar11) * (ulong)param_3[1]) / (ulong)(*param_3 << 1));
      }
      iVar10 = iVar10 + -0x42afe;
    }
    break;
  case 4:
    lVar12 = (long)param_2[1];
    lVar11 = 0;
    if ((long)*param_2 != 0) {
      lVar11 = ((long)param_2[1] * (long)(int)((param_5 & 0xffff) - param_2[2])) / (long)*param_2;
    }
    if ((param_4 & 1) == 0) {
      lVar12 = 0;
    }
    lVar11 = lVar11 + lVar12;
    if (lVar11 < 1) {
      lVar11 = 0;
    }
    lVar12 = 0;
    if ((ulong)*param_3 != 0) {
      lVar12 = (long)(lVar11 * (ulong)param_3[1]) / (long)(ulong)*param_3;
    }
    auVar4 = SEXT816(lVar12 * -0x43d14 + 0x5b361e9d80) * SEXT816(0x431bde82d7b634db);
    iVar10 = (int)(auVar4._8_8_ >> 0x12) - (auVar4._12_4_ >> 0x1f);
    break;
  default:
    return 0xffffffea;
  }
LAB_00100aa8:
  *param_6 = iVar10;
  return 0;
}



//------------------------------------------------------------
// qcom_adc_tm5_temp_volt_scale @ 00100b44 size=304
// signature: undefined qcom_adc_tm5_temp_volt_scale(void)
// callers: []
//------------------------------------------------------------

long qcom_adc_tm5_temp_volt_scale(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  bool bVar6;
  int *piVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  
  if (0x13 < param_1) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100c74);
    (*pcVar5)();
  }
  piVar7 = (int *)&DAT_001026bc;
  lVar11 = 0;
  do {
    if (param_3 <= *piVar7) {
      uVar9 = (uint)lVar11;
      if (uVar9 == 0) {
        iVar10 = 0x727;
        goto LAB_00100b94;
      }
      if (uVar9 != 0xffffffde) {
        uVar8 = (ulong)~uVar9;
        if ((0x110 < (uVar8 << 3 | 4)) || (0x21 < uVar8)) goto LAB_00100c6c;
        iVar1 = *(int *)(&DAT_001026bc + uVar8 * 8);
        iVar2 = (&adcmap_100k_104ef_104fb_1875_vref)[uVar8 * 2];
        iVar10 = iVar2;
        if (iVar1 != param_3) {
          iVar3 = piVar7[-1];
          if (iVar3 - iVar2 != 0) {
            iVar4 = *piVar7 - iVar1;
            iVar10 = iVar3;
            if ((iVar4 != 0) && (*piVar7 != param_3)) {
              iVar10 = 0;
              if (iVar4 != 0) {
                iVar10 = ((iVar3 - iVar2) * (param_3 - iVar1)) / iVar4;
              }
              iVar10 = iVar10 + iVar2;
            }
          }
        }
        goto LAB_00100b94;
      }
      break;
    }
    piVar7 = piVar7 + 2;
    bVar6 = lVar11 != -0x21;
    lVar11 = lVar11 + -1;
  } while (bVar6);
  iVar10 = 0x2e;
LAB_00100b94:
  if ((param_1 < 0x13) && (uVar8 = (ulong)param_1, (uVar8 << 3 | 4) < 0x99)) {
    lVar11 = 0;
    if ((ulong)(uint)(&DAT_00102624)[uVar8 * 2] * 0x1c9c38 != 0) {
      lVar11 = (long)((ulong)(uint)(param_2 * (&adc5_prescale_ratios)[uVar8 * 2] * 1000) *
                     (long)iVar10) / (long)((ulong)(uint)(&DAT_00102624)[uVar8 * 2] * 0x1c9c38);
    }
    return lVar11;
  }
LAB_00100c6c:
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(1,0x100c70);
  (*pcVar5)();
}



//------------------------------------------------------------
// qcom_adc_tm5_gen2_temp_res_scale @ 00100c78 size=236
// signature: undefined qcom_adc_tm5_gen2_temp_res_scale(void)
// callers: []
//------------------------------------------------------------

long qcom_adc_tm5_gen2_temp_res_scale(int param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  int *piVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  
  piVar8 = &DAT_001020e4;
  lVar10 = 0;
  do {
    if (param_1 <= *piVar8) {
      uVar9 = (uint)lVar10;
      if (uVar9 == 0) {
        uVar11 = 0x40dc21;
        goto LAB_00100cc4;
      }
      if (uVar9 != 0xffffff58) {
        uVar11 = (ulong)~uVar9;
        if ((0x540 < (uVar11 << 3 | 4)) || (0xa7 < uVar11)) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x100d64);
          (*pcVar6)();
        }
        iVar1 = (&DAT_001020e4)[uVar11 * 2];
        uVar9 = (&adcmap7_100k)[uVar11 * 2];
        if (iVar1 == param_1) {
          uVar11 = (ulong)uVar9;
        }
        else {
          uVar11 = (ulong)uVar9;
          iVar4 = piVar8[-1] - uVar9;
          if (iVar4 != 0) {
            uVar11 = (ulong)(uint)piVar8[-1];
            iVar5 = *piVar8 - iVar1;
            if ((iVar5 != 0) && (*piVar8 != param_1)) {
              iVar2 = 0;
              if (iVar5 != 0) {
                iVar2 = (iVar4 * (param_1 - iVar1)) / iVar5;
              }
              uVar11 = (ulong)(iVar2 + uVar9);
            }
          }
        }
        goto LAB_00100cc4;
      }
      break;
    }
    piVar8 = piVar8 + 2;
    bVar7 = lVar10 != -0xa7;
    lVar10 = lVar10 + -1;
  } while (bVar7);
  uVar11 = 0x974;
LAB_00100cc4:
  lVar10 = (long)(int)uVar11 + 100000;
  lVar3 = 0;
  if (lVar10 != 0) {
    lVar3 = (long)(-(uVar11 >> 0x1f) & 0xffffc00000000000 | uVar11 << 0xe) / lVar10;
  }
  return lVar3;
}



//------------------------------------------------------------
// qcom_adc5_hw_scale @ 00100d68 size=152
// signature: undefined qcom_adc5_hw_scale(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_hw_scale(uint param_1,uint param_2,undefined8 param_3,undefined4 param_4,
                  undefined8 param_5)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (0x13 < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100dfc);
    (*pcVar1)();
  }
  if (param_1 - 5 < 0x18) {
    if (0x1c < param_1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x100e00);
      (*pcVar1)();
    }
    if (*(int *)(*(code **)(scale_adc5_fn + (ulong)param_1 * 8) + -4) != 0x4a94b9cb) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100dd0);
      (*pcVar1)();
    }
    uVar2 = (**(code **)(scale_adc5_fn + (ulong)param_1 * 8))
                      (&adc5_prescale_ratios + (ulong)param_2 * 2,param_3,param_4,param_5);
  }
  else {
    _printk(&DAT_00103340,(ulong)param_1);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_adc5_prescaling_from_dt @ 00100e04 size=76
// signature: undefined qcom_adc5_prescaling_from_dt(void)
// callers: []
//------------------------------------------------------------

long qcom_adc5_prescaling_from_dt(int param_1,int param_2)

{
  long lVar1;
  int *piVar2;
  
  lVar1 = 0;
  piVar2 = &DAT_00102624;
  while ((piVar2[-1] != param_1 || (*piVar2 != param_2))) {
    lVar1 = lVar1 + 1;
    piVar2 = piVar2 + 2;
    if (lVar1 == 0x13) {
      return 0xffffffea;
    }
  }
  if ((int)lVar1 == 0x13) {
    return 0xffffffea;
  }
  return lVar1;
}



//------------------------------------------------------------
// qcom_adc5_hw_settle_time_from_dt @ 00100e54 size=324
// signature: undefined qcom_adc5_hw_settle_time_from_dt(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_adc5_hw_settle_time_from_dt(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*param_2 == param_1) {
    return 0;
  }
  if (param_2[1] == param_1) {
    return 1;
  }
  if (param_2[2] == param_1) {
    return 2;
  }
  if (param_2[3] == param_1) {
    return 3;
  }
  if (param_2[4] == param_1) {
    return 4;
  }
  if (param_2[5] == param_1) {
    return 5;
  }
  if (param_2[6] == param_1) {
    return 6;
  }
  if (param_2[7] == param_1) {
    return 7;
  }
  if (param_2[8] == param_1) {
    return 8;
  }
  if (param_2[9] == param_1) {
    return 9;
  }
  if (param_2[10] == param_1) {
    return 10;
  }
  if (param_2[0xb] == param_1) {
    return 0xb;
  }
  if (param_2[0xc] == param_1) {
    return 0xc;
  }
  if (param_2[0xd] == param_1) {
    return 0xd;
  }
  if (param_2[0xe] == param_1) {
    return 0xe;
  }
  uVar1 = 0xf;
  if (param_2[0xf] != param_1) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_adc5_avg_samples_from_dt @ 00100f9c size=100
// signature: undefined qcom_adc5_avg_samples_from_dt(void)
// callers: []
//------------------------------------------------------------

long qcom_adc5_avg_samples_from_dt(uint param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  uVar2 = (ulong)param_1;
  lVar1 = 0xffffffea;
  if ((param_1 < 0x11) &&
     (uVar3 = uVar2 - ((ulong)(param_1 >> 1) & 0x5555555555555555),
     uVar3 = (uVar3 & 0x3333333333333333) + (uVar3 >> 2 & 0x3333333333333333),
     (uVar3 + (uVar3 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38 < 2)) {
    uVar2 = (uVar2 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar2 & 0x5555555555555555) << 1;
    uVar2 = (uVar2 & 0xcccccccccccccccc) >> 2 | (uVar2 & 0x3333333333333333) << 2;
    uVar2 = (uVar2 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar2 = (uVar2 & 0xff00ff00ff00ff00) >> 8 | (uVar2 & 0xff00ff00ff00ff) << 8;
    lVar1 = LZCOUNT((uVar2 >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10) << 0x20);
  }
  return lVar1;
}



//------------------------------------------------------------
// qcom_adc5_decimation_from_dt @ 00101004 size=64
// signature: undefined qcom_adc5_decimation_from_dt(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_adc5_decimation_from_dt(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (*param_2 == param_1) {
    return 0;
  }
  if (param_2[1] == param_1) {
    return 1;
  }
  uVar1 = 2;
  if (param_2[2] != param_1) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_vadc_decimation_from_dt @ 00101048 size=104
// signature: undefined qcom_vadc_decimation_from_dt(void)
// callers: []
//------------------------------------------------------------

long qcom_vadc_decimation_from_dt(uint param_1)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  lVar3 = 0xffffffea;
  if ((param_1 - 0x200 < 0xe01) &&
     (uVar2 = param_1 - (param_1 >> 1 & 0x55555555),
     uVar2 = (uVar2 & 0x33333333) + (uVar2 >> 2 & 0x33333333),
     (uVar2 + (uVar2 >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18 < 2)) {
    uVar1 = ((ulong)(param_1 >> 9) & 0xaaaaaaaaaaaaaaaa) >> 1 |
            ((ulong)(param_1 >> 9) & 0x5555555555555555) << 1;
    uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
    uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
    lVar3 = LZCOUNT(((uVar1 & 0xff00ff00ff00ff) >> 8 |
                    ((uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff000000ff) << 8) << 0x10) <<
                    0x20);
  }
  return lVar3;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_volt @ 001010b4 size=68
// signature: undefined qcom_vadc_scale_hw_calib_volt(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_calib_volt(uint *param_1,long param_2,short param_3,undefined4 *param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  uVar1 = (uint)param_3;
  if ((int)uVar1 < 1) {
    uVar1 = 0;
  }
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  uVar3 = 0;
  if (uVar4 <= (ulong)uVar1 * 0x1c9c38) {
    uVar2 = 0;
    if (uVar4 != 0) {
      uVar2 = ((ulong)uVar1 * 0x1c9c38) / uVar4;
    }
    uVar3 = 0;
    if ((ulong)*param_1 != 0) {
      uVar3 = (undefined4)((long)(uVar2 * param_1[1]) / (long)(ulong)*param_1);
    }
  }
  *param_4 = uVar3;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_therm @ 001010fc size=276
// signature: undefined qcom_vadc_scale_hw_calib_therm(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc_scale_hw_calib_therm(int *param_1,long param_2,short param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  
  uVar12 = (uint)param_3;
  if ((int)uVar12 < 1) {
    uVar12 = 0;
  }
  uVar9 = (ulong)*(uint *)(param_2 + 8);
  iVar8 = 0;
  if (uVar9 <= (ulong)uVar12 * 0x1c9c38) {
    uVar5 = 0;
    if (uVar9 != 0) {
      uVar5 = ((ulong)uVar12 * 0x1c9c38) / uVar9;
    }
    iVar8 = 0;
    if ((ulong)(uint)(*param_1 * 1000) != 0) {
      iVar8 = (int)((long)(uVar5 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 * 1000));
    }
  }
  piVar10 = &adcmap_100k_104ef_104fb_1875_vref;
  lVar13 = 0;
  do {
    if (*piVar10 <= iVar8) {
      uVar12 = (uint)lVar13;
      if (uVar12 == 0) {
        iVar11 = -40000;
        goto LAB_0010118c;
      }
      if (uVar12 != 0xffffffde) {
        uVar9 = (ulong)~uVar12;
        if ((0x21 < ~uVar12) || (0x110 < (uVar9 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x101210);
          (*pcVar6)();
        }
        iVar1 = *(int *)(&DAT_001026bc + uVar9 * 8);
        iVar3 = iVar8 - (&adcmap_100k_104ef_104fb_1875_vref)[uVar9 * 2];
        iVar11 = iVar1;
        if (iVar3 != 0) {
          iVar2 = piVar10[1];
          if (iVar2 - iVar1 != 0) {
            iVar4 = *piVar10 - (&adcmap_100k_104ef_104fb_1875_vref)[uVar9 * 2];
            iVar11 = iVar2;
            if ((iVar4 != 0) && (*piVar10 != iVar8)) {
              iVar8 = 0;
              if (iVar4 != 0) {
                iVar8 = ((iVar2 - iVar1) * iVar3) / iVar4;
              }
              iVar11 = iVar8 + iVar1;
            }
          }
        }
        goto LAB_0010118c;
      }
      break;
    }
    piVar10 = piVar10 + 2;
    bVar7 = lVar13 != -0x21;
    lVar13 = lVar13 + -1;
  } while (bVar7);
  iVar11 = 0x1e848;
LAB_0010118c:
  *param_4 = iVar11;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_die_temp @ 00101214 size=80
// signature: undefined qcom_vadc_scale_hw_calib_die_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc_scale_hw_calib_die_temp(int *param_1,long param_2,short param_3,int *param_4)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar1 = (uint)param_3;
  if ((int)uVar1 < 1) {
    uVar1 = 0;
  }
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  iVar3 = -0x42afe;
  if (uVar4 <= (ulong)uVar1 * 0x1c9c38) {
    uVar2 = 0;
    if (uVar4 != 0) {
      uVar2 = ((ulong)uVar1 * 0x1c9c38) / uVar4;
    }
    iVar3 = 0;
    if ((ulong)(uint)(*param_1 << 1) != 0) {
      iVar3 = (int)((long)(uVar2 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 << 1));
    }
    iVar3 = iVar3 + -0x42afe;
  }
  *param_4 = iVar3;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc7_scale_hw_calib_die_temp @ 00101268 size=456
// signature: undefined qcom_vadc7_scale_hw_calib_die_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc7_scale_hw_calib_die_temp(uint *param_1,long param_2,short param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  long lVar10;
  
  uVar6 = (uint)param_3;
  if ((int)uVar6 < 1) {
    uVar6 = 0;
  }
  uVar8 = (ulong)*(uint *)(param_2 + 8);
  if ((ulong)uVar6 * 0x1c9c38 < uVar8) {
LAB_0010128c:
    iVar9 = -60000;
  }
  else {
    uVar7 = 0;
    if (uVar8 != 0) {
      uVar7 = ((ulong)uVar6 * 0x1c9c38) / uVar8;
    }
    iVar4 = 0;
    if ((ulong)*param_1 != 0) {
      iVar4 = (int)((long)(uVar7 * param_1[1]) / (long)(ulong)*param_1);
    }
    if (0xd14d3 < iVar4) {
      iVar9 = 160000;
      goto LAB_00101424;
    }
    if (iVar4 < 0xc8384) {
      if (iVar4 < 0xbf0a4) {
        if (iVar4 < 0xb5c98) {
          if (iVar4 < 0xac760) {
            if (iVar4 < 0xa30fc) {
              if (iVar4 < 0x99a34) {
                if (iVar4 < 0x902a4) {
                  if (iVar4 < 0x86a4c) {
                    if (iVar4 < 0x7d190) {
                      if (iVar4 < 0x7380c) {
                        if (iVar4 < 0x69e24) goto LAB_0010128c;
                        lVar10 = 0xb;
                      }
                      else {
                        lVar10 = 10;
                      }
                    }
                    else {
                      lVar10 = 9;
                    }
                  }
                  else {
                    lVar10 = 8;
                  }
                }
                else {
                  lVar10 = 7;
                }
              }
              else {
                lVar10 = 6;
              }
            }
            else {
              lVar10 = 5;
            }
          }
          else {
            lVar10 = 4;
          }
        }
        else {
          lVar10 = 3;
        }
      }
      else {
        lVar10 = 2;
      }
    }
    else {
      lVar10 = 1;
    }
    uVar8 = (ulong)((int)lVar10 - 1);
    iVar1 = (&adcmap7_die_temp)[uVar8 * 2];
    iVar2 = (&DAT_001029c4)[uVar8 * 2];
    iVar3 = (&DAT_001029c4)[lVar10 * 2];
    iVar9 = iVar2;
    if (iVar1 != iVar4 && iVar3 != iVar2) {
      iVar5 = (&adcmap7_die_temp)[lVar10 * 2] - iVar1;
      iVar9 = iVar3;
      if ((iVar5 != 0) && ((&adcmap7_die_temp)[lVar10 * 2] != iVar4)) {
        iVar9 = 0;
        if (iVar5 != 0) {
          iVar9 = ((iVar3 - iVar2) * (iVar4 - iVar1)) / iVar5;
        }
        iVar9 = iVar9 + iVar2;
      }
    }
  }
LAB_00101424:
  *param_4 = iVar9;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_chg5_temp @ 00101434 size=80
// signature: undefined qcom_vadc_scale_hw_chg5_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc_scale_hw_chg5_temp(int *param_1,long param_2,short param_3,int *param_4)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar1 = (uint)param_3;
  if ((int)uVar1 < 1) {
    uVar1 = 0;
  }
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  iVar3 = 0x5c29c;
  if (uVar4 <= (ulong)uVar1 * 0x1c9c38) {
    uVar2 = 0;
    if (uVar4 != 0) {
      uVar2 = ((ulong)uVar1 * 0x1c9c38) / uVar4;
    }
    iVar3 = 0;
    if ((ulong)(uint)(*param_1 << 2) != 0) {
      iVar3 = (int)((long)(uVar2 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 << 2));
    }
    iVar3 = 0x5c29c - iVar3;
  }
  *param_4 = iVar3;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_smb_temp @ 00101488 size=92
// signature: undefined qcom_vadc_scale_hw_smb_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc_scale_hw_smb_temp(int *param_1,long param_2,short param_3,int *param_4)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  uVar1 = (uint)(short)(param_3 * 100);
  if ((int)uVar1 < 1) {
    uVar1 = 0;
  }
  iVar3 = 0x66648;
  if (uVar4 <= (ulong)uVar1 * 0x1c9c38) {
    uVar2 = 0;
    if (uVar4 != 0) {
      uVar2 = ((ulong)uVar1 * 0x1c9c38) / uVar4;
    }
    iVar3 = 0;
    if ((ulong)(uint)(*param_1 * 0x164) != 0) {
      iVar3 = (int)((long)(uVar2 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 * 0x164));
    }
    iVar3 = 0x66648 - iVar3;
  }
  *param_4 = iVar3;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_batt_therm_100 @ 001014e8 size=272
// signature: undefined qcom_vadc_scale_hw_calib_batt_therm_100(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_calib_batt_therm_100(int *param_1,long param_2,short param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  
  uVar12 = (uint)param_3;
  if ((int)uVar12 < 1) {
    uVar12 = 0;
  }
  uVar9 = (ulong)*(uint *)(param_2 + 8);
  iVar8 = 0;
  if (uVar9 <= (ulong)uVar12 * 0x1c9c38) {
    uVar5 = 0;
    if (uVar9 != 0) {
      uVar5 = ((ulong)uVar12 * 0x1c9c38) / uVar9;
    }
    iVar8 = 0;
    if ((ulong)(uint)(*param_1 * 1000) != 0) {
      iVar8 = (int)((long)(uVar5 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 * 1000));
    }
  }
  piVar10 = &adcmap_batt_therm_100k;
  lVar13 = 0;
  do {
    if (*piVar10 <= iVar8) {
      uVar12 = (uint)lVar13;
      if (uVar12 == 0) {
        iVar11 = -400;
        goto LAB_00101574;
      }
      if (uVar12 != 0xffffffba) {
        uVar9 = (ulong)~uVar12;
        if ((0x45 < ~uVar12) || (0x230 < (uVar9 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x1015f8);
          (*pcVar6)();
        }
        iVar1 = *(int *)(&DAT_00102a24 + uVar9 * 8);
        iVar3 = iVar8 - (&adcmap_batt_therm_100k)[uVar9 * 2];
        iVar11 = iVar1;
        if (iVar3 != 0) {
          iVar2 = piVar10[1];
          if (iVar2 - iVar1 != 0) {
            iVar4 = *piVar10 - (&adcmap_batt_therm_100k)[uVar9 * 2];
            iVar11 = iVar2;
            if ((iVar4 != 0) && (*piVar10 != iVar8)) {
              iVar8 = 0;
              if (iVar4 != 0) {
                iVar8 = ((iVar2 - iVar1) * iVar3) / iVar4;
              }
              iVar11 = iVar8 + iVar1;
            }
          }
        }
        goto LAB_00101574;
      }
      break;
    }
    piVar10 = piVar10 + 2;
    bVar7 = lVar13 != -0x45;
    lVar13 = lVar13 + -1;
  } while (bVar7);
  iVar11 = 0x3d4;
LAB_00101574:
  *param_4 = iVar11;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_batt_therm_30 @ 001015fc size=272
// signature: undefined qcom_vadc_scale_hw_calib_batt_therm_30(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_calib_batt_therm_30(int *param_1,long param_2,short param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  
  uVar12 = (uint)param_3;
  if ((int)uVar12 < 1) {
    uVar12 = 0;
  }
  uVar9 = (ulong)*(uint *)(param_2 + 8);
  iVar8 = 0;
  if (uVar9 <= (ulong)uVar12 * 0x1c9c38) {
    uVar5 = 0;
    if (uVar9 != 0) {
      uVar5 = ((ulong)uVar12 * 0x1c9c38) / uVar9;
    }
    iVar8 = 0;
    if ((ulong)(uint)(*param_1 * 1000) != 0) {
      iVar8 = (int)((long)(uVar5 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 * 1000));
    }
  }
  piVar10 = &adcmap_batt_therm_30k;
  lVar13 = 0;
  do {
    if (*piVar10 <= iVar8) {
      uVar12 = (uint)lVar13;
      if (uVar12 == 0) {
        iVar11 = -400;
        goto LAB_00101688;
      }
      if (uVar12 != 0xffffffba) {
        uVar9 = (ulong)~uVar12;
        if ((0x45 < ~uVar12) || (0x230 < (uVar9 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x10170c);
          (*pcVar6)();
        }
        iVar1 = *(int *)(&DAT_00102c54 + uVar9 * 8);
        iVar3 = iVar8 - (&adcmap_batt_therm_30k)[uVar9 * 2];
        iVar11 = iVar1;
        if (iVar3 != 0) {
          iVar2 = piVar10[1];
          if (iVar2 - iVar1 != 0) {
            iVar4 = *piVar10 - (&adcmap_batt_therm_30k)[uVar9 * 2];
            iVar11 = iVar2;
            if ((iVar4 != 0) && (*piVar10 != iVar8)) {
              iVar8 = 0;
              if (iVar4 != 0) {
                iVar8 = ((iVar2 - iVar1) * iVar3) / iVar4;
              }
              iVar11 = iVar8 + iVar1;
            }
          }
        }
        goto LAB_00101688;
      }
      break;
    }
    piVar10 = piVar10 + 2;
    bVar7 = lVar13 != -0x45;
    lVar13 = lVar13 + -1;
  } while (bVar7);
  iVar11 = 0x3d4;
LAB_00101688:
  *param_4 = iVar11;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_batt_therm_400 @ 00101710 size=272
// signature: undefined qcom_vadc_scale_hw_calib_batt_therm_400(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_calib_batt_therm_400(int *param_1,long param_2,short param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  long lVar13;
  
  uVar12 = (uint)param_3;
  if ((int)uVar12 < 1) {
    uVar12 = 0;
  }
  uVar9 = (ulong)*(uint *)(param_2 + 8);
  iVar8 = 0;
  if (uVar9 <= (ulong)uVar12 * 0x1c9c38) {
    uVar5 = 0;
    if (uVar9 != 0) {
      uVar5 = ((ulong)uVar12 * 0x1c9c38) / uVar9;
    }
    iVar8 = 0;
    if ((ulong)(uint)(*param_1 * 1000) != 0) {
      iVar8 = (int)((long)(uVar5 * (uint)param_1[1]) / (long)(ulong)(uint)(*param_1 * 1000));
    }
  }
  piVar10 = &adcmap_batt_therm_400k;
  lVar13 = 0;
  do {
    if (*piVar10 <= iVar8) {
      uVar12 = (uint)lVar13;
      if (uVar12 == 0) {
        iVar11 = -400;
        goto LAB_0010179c;
      }
      if (uVar12 != 0xffffffba) {
        uVar9 = (ulong)~uVar12;
        if ((0x45 < ~uVar12) || (0x230 < (uVar9 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x101820);
          (*pcVar6)();
        }
        iVar1 = *(int *)(&DAT_00102e84 + uVar9 * 8);
        iVar3 = iVar8 - (&adcmap_batt_therm_400k)[uVar9 * 2];
        iVar11 = iVar1;
        if (iVar3 != 0) {
          iVar2 = piVar10[1];
          if (iVar2 - iVar1 != 0) {
            iVar4 = *piVar10 - (&adcmap_batt_therm_400k)[uVar9 * 2];
            iVar11 = iVar2;
            if ((iVar4 != 0) && (*piVar10 != iVar8)) {
              iVar8 = 0;
              if (iVar4 != 0) {
                iVar8 = ((iVar2 - iVar1) * iVar3) / iVar4;
              }
              iVar11 = iVar8 + iVar1;
            }
          }
        }
        goto LAB_0010179c;
      }
      break;
    }
    piVar10 = piVar10 + 2;
    bVar7 = lVar13 != -0x45;
    lVar13 = lVar13 + -1;
  } while (bVar7);
  iVar11 = 0x3d4;
LAB_0010179c:
  *param_4 = iVar11;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_smb1398_temp @ 00101824 size=92
// signature: undefined qcom_vadc_scale_hw_smb1398_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc_scale_hw_smb1398_temp(int *param_1,long param_2,short param_3,int *param_4)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  uVar1 = (uint)param_3;
  if ((int)uVar1 < 1) {
    uVar1 = 0;
  }
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  iVar3 = -0x417cb;
  if (uVar4 <= (ulong)uVar1 * 0x1c9c38) {
    uVar2 = 0;
    if (uVar4 != 0) {
      uVar2 = ((ulong)uVar1 * 0x1c9c38) / uVar4;
    }
    iVar3 = 0;
    if ((ulong)(uint)(*param_1 * 0x154) != 0) {
      iVar3 = (int)((uVar2 * (uint)param_1[1] * 100) / (ulong)(uint)(*param_1 * 0x154));
    }
    iVar3 = iVar3 + -0x417cb;
  }
  *param_4 = iVar3;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_pm7_smb_temp @ 00101884 size=144
// signature: undefined qcom_vadc_scale_hw_pm7_smb_temp(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_pm7_smb_temp(uint *param_1,long param_2,short param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  uVar2 = (uint)param_3;
  if ((int)uVar2 < 1) {
    uVar2 = 0;
  }
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  if ((ulong)uVar2 * 0x1c9c38 < uVar4) {
    lVar5 = -0x3ddab;
  }
  else {
    uVar3 = 0;
    if (uVar4 != 0) {
      uVar3 = ((ulong)uVar2 * 0x1c9c38) / uVar4;
    }
    iVar1 = 0;
    if ((ulong)*param_1 != 0) {
      iVar1 = (int)((long)(uVar3 * param_1[1]) / (long)(ulong)*param_1);
    }
    lVar5 = ((long)iVar1 * 250000000 + -0xe253e7da3400) / 894000000 + 25000;
  }
  if (lVar5 < 1) {
    lVar5 = 0;
  }
  *param_4 = (int)lVar5;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_pm7_chg_temp @ 00101918 size=132
// signature: undefined qcom_vadc_scale_hw_pm7_chg_temp(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_pm7_chg_temp(uint *param_1,long param_2,short param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  uVar2 = (uint)param_3;
  if ((int)uVar2 < 1) {
    uVar2 = 0;
  }
  uVar4 = (ulong)*(uint *)(param_2 + 8);
  if ((ulong)uVar2 * 0x1c9c38 < uVar4) {
    lVar5 = -0x43a80;
  }
  else {
    uVar3 = 0;
    if (uVar4 != 0) {
      uVar3 = ((ulong)uVar2 * 0x1c9c38) / uVar4;
    }
    iVar1 = 0;
    if ((ulong)*param_1 != 0) {
      iVar1 = (int)((long)(uVar3 * param_1[1]) / (long)(ulong)*param_1);
    }
    lVar5 = ((long)iVar1 * 0x765f + -0x673c39000) / 100000;
  }
  if (lVar5 < 1) {
    lVar5 = 0;
  }
  *param_4 = (int)lVar5;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_current @ 001019a0 size=64
// signature: undefined qcom_vadc_scale_hw_calib_current(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_calib_current(int *param_1,long param_2,short param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0xffffffea;
  }
  lVar3 = 0;
  if ((long)*(int *)(param_2 + 8) != 0) {
    lVar3 = ((long)(int)param_3 * 0x1c9c38) / (long)*(int *)(param_2 + 8);
  }
  uVar2 = 0;
  if ((long)iVar1 != 0) {
    uVar2 = (undefined4)((long)(lVar3 * (ulong)(uint)param_1[1]) / (long)iVar1);
  }
  *param_4 = uVar2;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_calib_current_raw @ 001019e4 size=44
// signature: undefined qcom_vadc_scale_hw_calib_current_raw(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_calib_current_raw
          (int *param_1,undefined8 param_2,short param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0xffffffea;
  }
  uVar2 = 0;
  if ((long)iVar1 != 0) {
    uVar2 = (undefined4)((long)((ulong)(uint)param_1[1] * (long)param_3) / (long)iVar1);
  }
  *param_4 = uVar2;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc_scale_hw_pm2250_s3_die_temp @ 00101a14 size=132
// signature: undefined qcom_vadc_scale_hw_pm2250_s3_die_temp(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_vadc_scale_hw_pm2250_s3_die_temp(uint *param_1,long param_2,short param_3,int *param_4)

{
  long lVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  
  uVar3 = (uint)param_3;
  if ((int)uVar3 < 1) {
    uVar3 = 0;
  }
  uVar6 = (ulong)*(uint *)(param_2 + 8);
  if ((ulong)uVar3 * 0x1c9c38 < uVar6) {
    iVar5 = 0x5de1b;
  }
  else {
    uVar4 = 0;
    if (uVar6 != 0) {
      uVar4 = ((ulong)uVar3 * 0x1c9c38) / uVar6;
    }
    lVar1 = 0;
    if ((ulong)*param_1 != 0) {
      lVar1 = (long)(uVar4 * param_1[1]) / (long)(ulong)*param_1;
    }
    auVar2 = SEXT816((0xafce4 - lVar1) * 100000) * SEXT816(0x59977b91ee00534b);
    iVar5 = auVar2._10_4_ - (auVar2._12_4_ >> 0x1f);
  }
  *param_4 = iVar5;
  return 0;
}



//------------------------------------------------------------
// qcom_vadc5_scale_hw_calib_current @ 00101a9c size=92
// signature: undefined qcom_vadc5_scale_hw_calib_current(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_vadc5_scale_hw_calib_current(uint *param_1,long param_2,short param_3,int *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = -param_3;
  if (-1 < param_3) {
    sVar1 = param_3;
  }
  iVar3 = 0;
  if ((ulong)*param_1 != 0) {
    iVar3 = (int)((long)(((long)((long)sVar1 * (ulong)*(uint *)(param_2 + 0xc) * 1000) / 0x7fff) *
                        (ulong)param_1[1]) / (long)(ulong)*param_1);
  }
  iVar2 = -iVar3;
  if (-1 < param_3) {
    iVar2 = iVar3;
  }
  *param_4 = iVar2;
  return 0;
}



//------------------------------------------------------------
// qcom_adc5_gen3_scale_hw_calib_batt_therm_100 @ 00101afc size=260
// signature: undefined qcom_adc5_gen3_scale_hw_calib_batt_therm_100(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_gen3_scale_hw_calib_batt_therm_100
          (undefined8 param_1,long param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  long lVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  ulong uVar12;
  
  if (*(uint *)(param_2 + 0x10) <= (param_3 & 0xffff)) {
    return 0xffffffea;
  }
  lVar8 = ((ulong)*(uint *)(param_2 + 0x10) & 0xffff) - ((ulong)param_3 & 0xffff);
  iVar4 = 0;
  if (lVar8 != 0) {
    iVar4 = (int)((long)(((ulong)param_3 & 0xffff) * 100000) / lVar8);
  }
  piVar9 = &adcmap_gen3_batt_therm_100k;
  lVar8 = 0;
  do {
    if (*piVar9 <= iVar4) {
      uVar11 = (uint)lVar8;
      if (uVar11 == 0) {
        iVar10 = -400;
        goto LAB_00101b78;
      }
      if (uVar11 != 0xffffffba) {
        uVar12 = (ulong)~uVar11;
        if ((0x45 < ~uVar11) || (0x230 < (uVar12 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x101c00);
          (*pcVar6)();
        }
        iVar3 = (&adcmap_gen3_batt_therm_100k)[uVar12 * 2];
        iVar1 = *(int *)(&DAT_001030b4 + uVar12 * 8);
        iVar10 = iVar1;
        if (iVar3 != iVar4) {
          iVar2 = piVar9[1];
          if (iVar2 - iVar1 != 0) {
            iVar5 = *piVar9 - iVar3;
            iVar10 = iVar2;
            if ((iVar5 != 0) && (*piVar9 != iVar4)) {
              iVar10 = 0;
              if (iVar5 != 0) {
                iVar10 = ((iVar2 - iVar1) * (iVar4 - iVar3)) / iVar5;
              }
              iVar10 = iVar10 + iVar1;
            }
          }
        }
        goto LAB_00101b78;
      }
      break;
    }
    piVar9 = piVar9 + 2;
    bVar7 = lVar8 != -0x45;
    lVar8 = lVar8 + -1;
  } while (bVar7);
  iVar10 = 0x3d4;
LAB_00101b78:
  *param_4 = iVar10;
  return 0;
}



//------------------------------------------------------------
// qcom_adc5_gen3_scale_hw_calib_batt_id_100 @ 00101c04 size=60
// signature: undefined qcom_adc5_gen3_scale_hw_calib_batt_id_100(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_gen3_scale_hw_calib_batt_id_100
          (undefined8 param_1,long param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  long lVar2;
  
  if (*(uint *)(param_2 + 0x10) <= (param_3 & 0xffff)) {
    return 0xffffffea;
  }
  lVar2 = ((ulong)*(uint *)(param_2 + 0x10) & 0xffff) - ((ulong)param_3 & 0xffff);
  uVar1 = 0;
  if (lVar2 != 0) {
    uVar1 = (undefined4)((long)(((ulong)param_3 & 0xffff) * 100000) / lVar2);
  }
  *param_4 = uVar1;
  return 0;
}



//------------------------------------------------------------
// qcom_adc5_gen3_scale_hw_calib_usb_in_current @ 00101c44 size=84
// signature: undefined qcom_adc5_gen3_scale_hw_calib_usb_in_current(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_gen3_scale_hw_calib_usb_in_current
          (uint *param_1,undefined8 param_2,short param_3,int *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = -param_3;
  if (-1 < param_3) {
    sVar1 = param_3;
  }
  iVar3 = 0;
  if ((ulong)*param_1 != 0) {
    iVar3 = (int)((long)((((long)(int)sVar1 * 1000000) / 0x2420) * (ulong)param_1[1]) /
                 (long)(ulong)*param_1);
  }
  iVar2 = -iVar3;
  if (-1 < param_3) {
    iVar2 = iVar3;
  }
  *param_4 = iVar2;
  return 0;
}



//------------------------------------------------------------
// qcom_adc5_gen4_scale_hw_calib_batt_therm_10 @ 00101c9c size=252
// signature: undefined qcom_adc5_gen4_scale_hw_calib_batt_therm_10(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_gen4_scale_hw_calib_batt_therm_10
          (undefined8 param_1,long param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  
  param_3 = param_3 & 0xffff;
  if (*(uint *)(param_2 + 0x10) <= param_3) {
    return 0xffffffea;
  }
  iVar9 = (*(uint *)(param_2 + 0x10) & 0xffff) - param_3;
  iVar3 = 0;
  if (iVar9 != 0) {
    iVar3 = (int)(param_3 * 10000) / iVar9;
  }
  piVar8 = &adcmap_gen3_batt_therm_100k;
  lVar11 = 0;
  do {
    if (*piVar8 <= iVar3) {
      uVar10 = (uint)lVar11;
      if (uVar10 == 0) {
        iVar9 = -400;
        goto LAB_00101d14;
      }
      if (uVar10 != 0xffffffba) {
        uVar12 = (ulong)~uVar10;
        if ((0x45 < ~uVar10) || (0x230 < (uVar12 << 3 | 4))) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x101d98);
          (*pcVar6)();
        }
        iVar1 = *(int *)(&DAT_001030b4 + uVar12 * 8);
        iVar4 = iVar3 - (&adcmap_gen3_batt_therm_100k)[uVar12 * 2];
        iVar9 = iVar1;
        if (iVar4 != 0) {
          iVar2 = piVar8[1];
          if (iVar2 - iVar1 != 0) {
            iVar5 = *piVar8 - (&adcmap_gen3_batt_therm_100k)[uVar12 * 2];
            iVar9 = iVar2;
            if ((iVar5 != 0) && (*piVar8 != iVar3)) {
              iVar3 = 0;
              if (iVar5 != 0) {
                iVar3 = ((iVar2 - iVar1) * iVar4) / iVar5;
              }
              iVar9 = iVar3 + iVar1;
            }
          }
        }
        goto LAB_00101d14;
      }
      break;
    }
    piVar8 = piVar8 + 2;
    bVar7 = lVar11 != -0x45;
    lVar11 = lVar11 + -1;
  } while (bVar7);
  iVar9 = 0x3d4;
LAB_00101d14:
  *param_4 = iVar9;
  return 0;
}



//------------------------------------------------------------
// qcom_adc5_gen4_scale_hw_calib_batt_id_10 @ 00101d9c size=56
// signature: undefined qcom_adc5_gen4_scale_hw_calib_batt_id_10(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_gen4_scale_hw_calib_batt_id_10(undefined8 param_1,long param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  param_3 = param_3 & 0xffff;
  if (*(uint *)(param_2 + 0x10) <= param_3) {
    return 0xffffffea;
  }
  iVar2 = (*(uint *)(param_2 + 0x10) & 0xffff) - param_3;
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = (int)(param_3 * 10000) / iVar2;
  }
  *param_4 = iVar1;
  return 0;
}



//------------------------------------------------------------
// qcom_adc5_gen3_scale_hw_calib_die_temp_lite @ 00101dd8 size=452
// signature: undefined qcom_adc5_gen3_scale_hw_calib_die_temp_lite(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_adc5_gen3_scale_hw_calib_die_temp_lite(uint *param_1,long param_2,short param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  long lVar10;
  
  uVar6 = (uint)param_3;
  if ((int)uVar6 < 1) {
    uVar6 = 0;
  }
  uVar8 = (ulong)*(uint *)(param_2 + 8);
  iVar9 = 160000;
  if (uVar8 <= (ulong)uVar6 * 0x1c9c38) {
    uVar7 = 0;
    if (uVar8 != 0) {
      uVar7 = ((ulong)uVar6 * 0x1c9c38) / uVar8;
    }
    iVar4 = 0;
    if ((ulong)*param_1 != 0) {
      iVar4 = (int)((long)(uVar7 * param_1[1]) / (long)(ulong)*param_1);
    }
    if (iVar4 < 0xcb6b0) {
      if (iVar4 < 0xc2e5c) {
        if (iVar4 < 0xba414) {
          if (iVar4 < 0xb183c) {
            if (iVar4 < 0xa8ad4) {
              if (iVar4 < 0x9fc40) {
                if (iVar4 < 0x96c1c) {
                  if (iVar4 < 0x8db30) {
                    if (iVar4 < 0x84918) {
                      if (iVar4 < 0x7b638) {
                        if (iVar4 < 0x72290) {
                          if (iVar4 < 0x68e20) goto LAB_00101f90;
                          lVar10 = 0xb;
                        }
                        else {
                          lVar10 = 10;
                        }
                      }
                      else {
                        lVar10 = 9;
                      }
                    }
                    else {
                      lVar10 = 8;
                    }
                  }
                  else {
                    lVar10 = 7;
                  }
                }
                else {
                  lVar10 = 6;
                }
              }
              else {
                lVar10 = 5;
              }
            }
            else {
              lVar10 = 4;
            }
          }
          else {
            lVar10 = 3;
          }
        }
        else {
          lVar10 = 2;
        }
      }
      else {
        lVar10 = 1;
      }
      uVar8 = (ulong)((int)lVar10 - 1);
      iVar1 = (&adcmap_gen3_die_temp_lite)[uVar8 * 2];
      iVar2 = (&DAT_001032e4)[uVar8 * 2];
      iVar3 = (&DAT_001032e4)[lVar10 * 2];
      iVar9 = iVar2;
      if (iVar1 != iVar4 && iVar3 != iVar2) {
        iVar5 = (&adcmap_gen3_die_temp_lite)[lVar10 * 2] - iVar1;
        iVar9 = iVar3;
        if ((iVar5 != 0) && ((&adcmap_gen3_die_temp_lite)[lVar10 * 2] != iVar4)) {
          iVar9 = 0;
          if (iVar5 != 0) {
            iVar9 = ((iVar3 - iVar2) * (iVar4 - iVar1)) / iVar5;
          }
          iVar9 = iVar9 + iVar2;
        }
      }
    }
    else {
      iVar9 = -60000;
    }
  }
LAB_00101f90:
  *param_4 = iVar9;
  return 0;
}



//------------------------------------------------------------
// _printk @ 00104000 size=1
// signature: undefined _printk(void)
// callers: [qcom_adc5_hw_scale]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



