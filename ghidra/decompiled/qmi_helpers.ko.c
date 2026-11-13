// Decompiled by Ghidra 12.2
// Program: qmi_helpers.ko
// Image base: 00100000

//------------------------------------------------------------
// qmi_encode_message @ 0010063c size=244
// signature: undefined qmi_encode_message(void)
// callers: [qmi_send_message]
//------------------------------------------------------------

undefined1 *
qmi_encode_message(undefined1 param_1,undefined2 param_2,long *param_3,undefined2 param_4,
                  undefined8 param_5,long param_6)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if ((param_6 == 0) && (iVar1 = qmi_calc_min_msg_len(param_5,1), iVar1 != 0)) {
    _printk(&DAT_00102f2e,"qmi_encode_message",iVar1);
    puVar2 = (undefined1 *)0xffffffffffffffea;
  }
  else {
    puVar2 = (undefined1 *)__kmalloc(*param_3 + 7,0xdc0);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0xfffffffffffffff4;
    }
    else {
      puVar3 = (undefined1 *)0x0;
      if (param_6 != 0) {
        iVar1 = qmi_encode(param_5,puVar2 + 7,param_6,(int)*param_3,1);
        puVar3 = (undefined1 *)(long)iVar1;
        if (iVar1 < 0) {
          kfree(puVar2);
          return puVar3;
        }
      }
      *puVar2 = param_1;
      *(undefined2 *)(puVar2 + 1) = param_4;
      *(undefined2 *)(puVar2 + 3) = param_2;
      *(short *)(puVar2 + 5) = (short)puVar3;
      *param_3 = (long)(puVar3 + 7);
    }
  }
  return puVar2;
}



//------------------------------------------------------------
// qmi_calc_min_msg_len @ 00100730 size=276
// signature: undefined qmi_calc_min_msg_len(void)
// callers: [qmi_calc_min_msg_len, qmi_encode_message]
//------------------------------------------------------------

int qmi_calc_min_msg_len(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    iVar5 = 0;
switchD_001007b8_caseD_0:
    return iVar5;
  }
  iVar5 = 0;
LAB_00100770:
  while (*param_1 == 1) {
    if (param_2 < 2) {
      piVar4 = param_1;
      do {
        piVar1 = piVar4 + 4;
        param_1 = piVar4 + 8;
        piVar2 = piVar4 + 0xc;
        piVar4 = param_1;
      } while ((char)*piVar1 == (char)*piVar2);
    }
    else {
      param_1 = param_1 + 8;
    }
  }
  switch(*param_1) {
  case 0:
    goto switchD_001007b8_caseD_0;
  default:
    iVar3 = iVar5 + param_1[2] * param_1[1];
    break;
  case 2:
    goto switchD_001007b8_caseD_2;
  case 9:
    iVar3 = qmi_calc_min_msg_len(*(undefined8 *)(param_1 + 6),param_2 + 1);
    iVar3 = iVar3 + iVar5;
    break;
  case 10:
    iVar3 = 1;
    if (0xff < (uint)param_1[1]) {
      iVar3 = 2;
    }
    if (param_2 < 2) {
      iVar3 = 0;
    }
    iVar3 = iVar5 + iVar3 + param_1[2] * param_1[1];
  }
  iVar5 = iVar3 + 3;
  if (param_2 != 1) {
    iVar5 = iVar3;
  }
  param_1 = param_1 + 8;
  goto LAB_00100770;
switchD_001007b8_caseD_2:
  piVar4 = param_1 + 2;
  param_1 = param_1 + 8;
  iVar3 = 1;
  if (*piVar4 != 1) {
    iVar3 = 2;
  }
  iVar5 = iVar3 + iVar5;
  goto LAB_00100770;
}



//------------------------------------------------------------
// qmi_encode @ 00100844 size=1312
// signature: undefined qmi_encode(void)
// callers: [qmi_encode_message, qmi_encode]
//------------------------------------------------------------

ulong qmi_encode(int *param_1,undefined1 *param_2,long param_3,uint param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  size_t sVar5;
  undefined *puVar6;
  ushort *puVar7;
  bool bVar8;
  uint uVar9;
  undefined1 *__dest;
  uint uVar10;
  int iVar11;
  long lVar12;
  int iVar13;
  ulong uVar14;
  undefined1 *puVar15;
  int iVar16;
  ulong uVar17;
  undefined1 *local_90;
  ushort local_74 [2];
  byte local_70 [4];
  uint local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_70[0] = 0;
  local_74[0] = 0;
  if ((param_1 == (int *)0x0) || (iVar16 = *param_1, iVar16 == 0)) {
    uVar17 = 0;
  }
  else {
    lVar12 = 3;
    if (param_5 != 1) {
      lVar12 = 0;
    }
    __dest = param_2 + lVar12;
    uVar10 = 0;
    bVar8 = false;
    uVar14 = 0;
    iVar11 = 0;
    local_90 = param_2;
    do {
      iVar2 = param_1[4];
      if (param_1[3] != 0) {
        if (param_1[3] == 1) {
          uVar10 = param_1[1];
          goto LAB_00100924;
        }
        if ((uVar10 != 0) && (uVar10 <= (uint)param_1[1])) goto LAB_00100924;
        puVar6 = &DAT_00102b87;
LAB_00100cc8:
        _printk(puVar6,"qmi_encode");
        uVar17 = 0xffffffea;
        break;
      }
      uVar10 = 1;
LAB_00100924:
      if (9 < iVar16 - 1U) {
        puVar6 = &DAT_00102b0f;
        goto LAB_00100cc8;
      }
      puVar7 = (ushort *)(param_3 + (ulong)(uint)param_1[5]);
      iVar13 = (int)uVar14;
      switch(iVar16) {
      case 1:
        puVar15 = __dest;
        if ((byte)*puVar7 == 0) {
          if (1 < param_5) {
            param_1 = param_1 + 8;
            goto LAB_001008dc;
          }
          do {
            piVar3 = param_1 + 4;
            piVar1 = param_1 + 0xc;
            param_1 = param_1 + 8;
          } while ((char)*piVar3 == (char)*piVar1);
        }
        else {
          param_1 = param_1 + 8;
        }
        break;
      case 2:
        uVar9 = 1;
        if (param_1[2] != 1) {
          uVar9 = 2;
        }
        uVar14 = (ulong)(uVar9 + iVar13);
        if (uVar14 + 3 <= (ulong)param_4) {
          if (param_1[2] == 1) {
            local_70[0] = (byte)*puVar7;
            uVar10 = (uint)local_70[0];
            puVar7 = (ushort *)local_70;
          }
          else {
            local_74[0] = *puVar7;
            uVar10 = (uint)local_74[0];
            puVar7 = local_74;
          }
          memcpy(__dest,puVar7,(ulong)uVar9);
          __dest = __dest + uVar9;
          iVar11 = uVar9 + iVar11;
          if (uVar10 == 0) {
            if (param_5 < 2) {
              piVar3 = param_1 + 0x14;
              do {
                param_1 = piVar3;
                piVar3 = param_1 + 8;
              } while ((char)param_1[-8] == (char)*param_1);
              uVar10 = 0;
              param_1 = param_1 + -4;
              bVar8 = true;
              puVar15 = __dest;
              break;
            }
            uVar10 = 0;
            param_1 = param_1 + 0x10;
            bVar8 = true;
          }
          else {
            bVar8 = false;
            param_1 = param_1 + 8;
          }
          goto LAB_001008dc;
        }
        _printk(&DAT_00102ba2,"qmi_encode");
        uVar17 = 0xfffffdf3;
        goto LAB_00100c68;
      default:
        uVar9 = param_1[2];
        iVar16 = uVar9 * uVar10;
        uVar14 = (ulong)(uint)(iVar16 + iVar13);
        if (uVar14 + 3 <= (ulong)param_4) {
          if (uVar10 != 0) {
            lVar12 = 0;
            uVar4 = uVar10;
            do {
              memcpy(__dest + lVar12,(byte *)((long)puVar7 + lVar12),(ulong)uVar9);
              lVar12 = lVar12 + (ulong)uVar9;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
          }
          uVar17 = (ulong)iVar16;
          goto LAB_001009c0;
        }
        _printk(&DAT_00102ae9,"qmi_encode");
        uVar17 = 0xfffffdf3;
        goto LAB_00100c68;
      case 9:
        if (uVar10 == 0) {
          uVar17 = 0;
        }
        else {
          uVar17 = 0;
          puVar15 = __dest;
          uVar9 = uVar10;
          do {
            iVar16 = (int)uVar17;
            uVar4 = qmi_encode(*(undefined8 *)(param_1 + 6),puVar15,puVar7,
                               param_4 - (iVar13 + iVar16),param_5 + 1);
            uVar17 = (ulong)uVar4;
            if ((int)uVar4 < 0) {
              _printk(&DAT_00102b5f,"qmi_encode_struct_elem");
              goto LAB_00100c68;
            }
            puVar15 = puVar15 + uVar17;
            uVar4 = uVar4 + iVar16;
            uVar17 = (ulong)uVar4;
            uVar9 = uVar9 - 1;
            puVar7 = (ushort *)((long)puVar7 + (ulong)(uint)param_1[2]);
          } while (uVar9 != 0);
          if ((int)uVar4 < 0) goto LAB_00100c68;
        }
        uVar14 = (ulong)(uint)((int)uVar17 + iVar13);
        iVar11 = (int)uVar17 + iVar11;
        param_1 = param_1 + 8;
        bVar8 = true;
        puVar15 = __dest + uVar17;
        break;
      case 10:
        sVar5 = strlen((char *)puVar7);
        uVar9 = 1;
        if (0xff < (uint)param_1[1]) {
          uVar9 = 2;
        }
        uVar17 = (ulong)uVar9;
        local_6c = (uint)sVar5;
        if ((uint)param_1[1] < local_6c) {
          _printk(&DAT_00102bc4,"qmi_encode_string_elem",sVar5 & 0xffffffff);
          uVar17 = 0xffffffea;
          goto LAB_00100c68;
        }
        if (param_5 == 1) {
          if ((ulong)(param_4 - iVar13) < (sVar5 & 0xffffffff) + 3) {
LAB_00100d40:
            _printk(&DAT_00102aac,"qmi_encode_string_elem",sVar5 & 0xffffffff);
            uVar17 = 0xfffffdf3;
            goto LAB_00100c68;
          }
          uVar17 = 0;
          uVar9 = 0;
          if (local_6c != 0) goto LAB_00100b0c;
LAB_00100bb4:
          uVar17 = (ulong)uVar9;
        }
        else {
          if (param_4 - iVar13 < uVar9 + local_6c) goto LAB_00100d40;
          memcpy(__dest,&local_6c,uVar17);
          sVar5 = (size_t)local_6c;
          if (local_6c == 0) goto LAB_00100bb4;
LAB_00100b0c:
          uVar9 = param_1[2];
          lVar12 = 0;
          iVar16 = (int)sVar5;
          do {
            memcpy(__dest + lVar12 + uVar17,(byte *)((long)puVar7 + lVar12),(ulong)uVar9);
            lVar12 = lVar12 + (ulong)uVar9;
            uVar4 = (int)sVar5 - 1;
            sVar5 = (size_t)uVar4;
          } while (uVar4 != 0);
          uVar9 = uVar9 * iVar16 + (int)uVar17;
          uVar17 = (ulong)uVar9;
          if ((int)uVar9 < 0) goto LAB_00100c68;
        }
        iVar16 = (int)uVar17;
        uVar14 = (ulong)(uint)(iVar16 + iVar13);
LAB_001009c0:
        iVar11 = iVar16 + iVar11;
        param_1 = param_1 + 8;
        bVar8 = true;
        puVar15 = __dest + uVar17;
      }
      if ((param_5 == 1) && (bVar8)) {
        bVar8 = false;
        uVar14 = (ulong)((int)uVar14 + 3);
        local_90[1] = (char)iVar11;
        *local_90 = (char)iVar2;
        local_90[2] = (char)((uint)iVar11 >> 8);
        __dest = puVar15 + 3;
        iVar11 = 0;
        local_90 = puVar15;
      }
      else {
        __dest = puVar15;
      }
LAB_001008dc:
      iVar16 = *param_1;
      uVar17 = uVar14;
    } while (iVar16 != 0);
  }
LAB_00100c68:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17;
}



//------------------------------------------------------------
// qmi_decode_message @ 00100d68 size=88
// signature: undefined qmi_decode_message(void)
// callers: [qmi_data_ready_work, qmi_invoke_handler]
//------------------------------------------------------------

undefined8 qmi_decode_message(long param_1,long param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    return 0xffffffea;
  }
  uVar1 = 0xffffffea;
  if (((param_2 != 0) && (param_1 != 0)) && (param_4 != 0)) {
    uVar1 = qmi_decode(param_3,param_4,param_1 + 7,(int)param_2 + -7,1);
  }
  return uVar1;
}



//------------------------------------------------------------
// qmi_decode @ 00100dc0 size=1340
// signature: undefined qmi_decode(void)
// callers: [qmi_decode_message, qmi_decode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x001012f0) */

ulong qmi_decode(int *param_1,long param_2,byte *param_3,uint param_4,int param_5)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined *puVar5;
  char *pcVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  ulong uVar12;
  long lVar13;
  byte *pbVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  ulong uVar19;
  uint *puVar20;
  ushort local_78 [2];
  byte local_74 [4];
  ushort local_70 [2];
  byte local_6c [4];
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  local_74[0] = 0;
  local_78[0] = 0;
  if (param_4 == 0) {
    uVar12 = 0;
  }
  else {
    uVar18 = 0;
    uVar12 = 0;
    iVar2 = param_5 + 1;
    piVar15 = param_1;
    do {
      iVar11 = (int)uVar12;
      if (param_5 < 2) {
        if (param_5 != 1) goto LAB_00100eac;
        if (uVar12 + 3 <= (ulong)param_4) {
          iVar9 = *param_1;
          piVar15 = param_1;
          while (iVar9 != 0) {
            if (*(byte *)(piVar15 + 4) == *param_3) goto LAB_00100e88;
            piVar15 = piVar15 + 8;
            iVar9 = *piVar15;
          }
          piVar15 = (int *)0x0;
LAB_00100e88:
          puVar1 = (ushort *)(param_3 + 1);
          uVar19 = (ulong)*puVar1;
          if ((piVar15 != (int *)0x0) || (0xf < *param_3)) {
            param_3 = param_3 + 3;
            iVar11 = iVar11 + 3;
            if (piVar15 != (int *)0x0) {
              bVar4 = true;
              goto LAB_00100eb4;
            }
            param_3 = param_3 + uVar19;
            uVar10 = (uint)*puVar1 + iVar11;
            goto LAB_0010101c;
          }
          puVar5 = &DAT_00102bff;
LAB_00101264:
          _printk(puVar5,"qmi_decode");
        }
        goto LAB_00101270;
      }
      if (*piVar15 == 0) break;
LAB_00100eac:
      bVar4 = false;
      uVar19 = (ulong)(param_4 - iVar11);
LAB_00100eb4:
      iVar9 = *piVar15;
      puVar20 = (uint *)(param_2 + (ulong)(uint)piVar15[5]);
      piVar16 = piVar15;
      if (iVar9 == 1) {
        *(undefined1 *)puVar20 = 1;
        piVar16 = piVar15 + 8;
        iVar9 = *piVar16;
        puVar20 = (uint *)(param_2 + (ulong)(uint)piVar15[0xd]);
      }
      if (iVar9 == 2) {
        uVar10 = 1;
        if (piVar16[2] != 1) {
          uVar10 = 2;
        }
        if (piVar16[2] != 1) {
          if (param_4 - iVar11 < uVar10) {
            iVar9 = -0x16;
          }
          else {
            memcpy(local_78,param_3,(ulong)uVar10);
            iVar9 = 2;
          }
          uVar18 = (uint)local_78[0];
        }
        else if (param_4 - iVar11 < uVar10) {
          uVar18 = (uint)local_74[0];
          iVar9 = -0x16;
        }
        else {
          memcpy(local_74,param_3,(ulong)uVar10);
          iVar9 = 1;
          uVar18 = (uint)local_74[0];
        }
        *puVar20 = uVar18;
        uVar19 = (ulong)((int)uVar19 - uVar10);
        puVar20 = (uint *)(piVar16 + 0xd);
        piVar16 = piVar16 + 8;
        param_3 = param_3 + iVar9;
        iVar11 = iVar9 + iVar11;
        puVar20 = (uint *)(param_2 + (ulong)*puVar20);
      }
      if (piVar16[3] != 0) {
        if (piVar16[3] == 1) {
          uVar18 = piVar16[1];
          goto LAB_00100fb0;
        }
        if (uVar18 <= (uint)piVar16[1]) goto LAB_00100fb0;
        puVar5 = &DAT_00102db3;
        pcVar6 = "qmi_decode";
        uVar8 = (ulong)uVar18;
LAB_001012c0:
        _printk(puVar5,pcVar6,uVar8);
        uVar12 = 0xfffffdf3;
        break;
      }
      uVar18 = 1;
LAB_00100fb0:
      iVar9 = *piVar16;
      if (5 < iVar9 - 3U) {
        uVar10 = (uint)uVar19;
        if (iVar9 == 9) {
          if (uVar10 <= param_4 - iVar11) {
            uVar17 = 0;
            bVar4 = uVar18 != 0;
            uVar12 = 0;
            if ((uVar18 != 0) && (uVar10 != 0)) {
              uVar12 = 0;
              uVar17 = 0;
              pbVar14 = param_3;
              do {
                uVar8 = qmi_decode(*(undefined8 *)(piVar16 + 6),puVar20,pbVar14,uVar10 - (int)uVar12
                                   ,iVar2);
                if ((int)uVar8 < 0) {
                  uVar12 = uVar8 & 0xffffffff;
                  goto LAB_00101274;
                }
                uVar17 = uVar17 + 1;
                uVar7 = (int)uVar8 + (int)uVar12;
                uVar12 = (ulong)uVar7;
                bVar4 = uVar18 > uVar17;
                if (uVar18 <= uVar17) break;
                pbVar14 = pbVar14 + (uVar8 & 0xffffffff);
                puVar20 = (uint *)((long)puVar20 + (ulong)(uint)piVar16[2]);
              } while (uVar7 < uVar10);
            }
            if ((2 < iVar2) || (uVar10 == (uint)uVar12)) {
              if (uVar10 < (uint)uVar12) {
                bVar4 = true;
              }
              if ((iVar2 < 3) || (!bVar4)) goto LAB_00101004;
            }
            _printk(&DAT_00102dd4,"qmi_decode_struct_elem",iVar2,uVar12,uVar19,uVar17,uVar18);
            uVar12 = 0xfffffff2;
            break;
          }
        }
        else {
          if (iVar9 != 10) {
            puVar5 = &DAT_00102b0f;
            goto LAB_00101264;
          }
          iVar9 = 0;
          uVar17 = param_4 - iVar11;
          local_6c[0] = 0;
          local_70[0] = 0;
          uVar8 = uVar19;
          if (!bVar4) {
            uVar7 = 1;
            if (0xff < (uint)piVar16[1]) {
              uVar7 = 2;
            }
            if ((uint)piVar16[1] < 0x100) {
              if (uVar17 < uVar7) goto LAB_00101148;
              memcpy(local_6c,param_3,(ulong)uVar7);
              iVar9 = 1;
              uVar8 = (ulong)local_6c[0];
            }
            else if (uVar17 < uVar7) {
LAB_00101148:
              uVar8 = 0;
              iVar9 = -0x16;
            }
            else {
              memcpy(local_70,param_3,(ulong)uVar7);
              iVar9 = 2;
              uVar8 = (ulong)local_70[0];
            }
          }
          uVar7 = (uint)uVar8;
          if ((uint)piVar16[1] <= uVar7) {
            puVar5 = &DAT_00102d10;
            pcVar6 = "qmi_decode_string_elem";
            goto LAB_001012c0;
          }
          if (uVar10 < uVar7) {
            _printk(&DAT_00102e14,"qmi_decode_string_elem",uVar8,uVar19);
            uVar12 = 0xfffffff2;
            break;
          }
          uVar10 = piVar16[2];
          uVar3 = uVar10 * uVar7;
          uVar12 = (ulong)uVar3;
          if (uVar3 <= uVar17 - iVar9) {
            if (uVar7 != 0) {
              lVar13 = 0;
              uVar19 = uVar8;
              do {
                memcpy((undefined1 *)((long)puVar20 + lVar13),param_3 + lVar13 + iVar9,(ulong)uVar10
                      );
                lVar13 = lVar13 + (ulong)uVar10;
                uVar17 = (int)uVar19 - 1;
                uVar19 = (ulong)uVar17;
              } while (uVar17 != 0);
              if ((int)uVar3 < 0) break;
            }
            uVar12 = (ulong)(uVar3 + iVar9);
            *(undefined1 *)((long)puVar20 + uVar8) = 0;
            if (-1 < (int)(uVar3 + iVar9)) goto LAB_00101010;
            break;
          }
        }
LAB_00101270:
        uVar12 = 0xffffffea;
        break;
      }
      uVar10 = piVar16[2];
      uVar12 = (ulong)(uVar10 * uVar18);
      if (param_4 - iVar11 < uVar10 * uVar18) goto LAB_00101270;
      if (uVar18 != 0) {
        lVar13 = 0;
        uVar17 = uVar18;
        do {
          memcpy((undefined1 *)((long)puVar20 + lVar13),param_3 + lVar13,(ulong)uVar10);
          lVar13 = lVar13 + (ulong)uVar10;
          uVar17 = uVar17 - 1;
        } while (uVar17 != 0);
LAB_00101004:
        if ((int)uVar12 < 0) break;
      }
LAB_00101010:
      param_3 = param_3 + uVar12;
      uVar10 = (int)uVar12 + iVar11;
      piVar15 = piVar16 + 8;
LAB_0010101c:
      uVar12 = (ulong)uVar10;
    } while (uVar10 < param_4);
  }
LAB_00101274:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// qmi_add_lookup @ 00101300 size=172
// signature: undefined qmi_add_lookup(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qmi_add_lookup(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  
  puVar2 = (undefined4 *)kmalloc_trace(___init_swait_queue_head,0xdc0,0x30);
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *puVar2 = param_2;
    puVar2[1] = param_3;
    puVar2[2] = param_4;
    puVar1 = puVar2 + 8;
    plVar6 = (long *)(param_1 + 0x90);
    lVar5 = *plVar6;
    *(undefined4 *)(param_1 + 0x140) = param_2;
    uVar3 = __list_add_valid(puVar1,plVar6,lVar5);
    if ((uVar3 & 1) != 0) {
      *(undefined4 **)(lVar5 + 8) = puVar1;
      *(long *)(puVar2 + 8) = lVar5;
      *(long **)(puVar2 + 10) = plVar6;
      *plVar6 = (long)puVar1;
    }
    qmi_send_new_lookup(param_1,puVar2);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// qmi_send_new_lookup @ 001013ac size=256
// signature: undefined qmi_send_new_lookup(void)
// callers: [qmi_data_ready_work, qmi_add_lookup]
//------------------------------------------------------------

void qmi_send_new_lookup(long *param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 *local_c8;
  undefined8 uStack_c0;
  uint *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  uint local_38;
  undefined8 local_34;
  long local_28;
  
  lVar1 = sp_el0;
  local_c8 = &local_40;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_c0 = 0x14;
  uStack_3c = *param_2;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_38 = param_2[1] | param_2[2] << 8;
  local_40 = 10;
  uStack_4c = *(undefined4 *)((long)param_1 + 0x3c);
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b8 = &local_50;
  uStack_a8 = 0;
  local_50 = (uint)*(ushort *)(param_1 + 7);
  local_34 = 0;
  local_48 = 0xfffffffe;
  local_b0 = 0xc;
  mutex_lock(param_1 + 1);
  if ((*param_1 != 0) && (iVar2 = kernel_sendmsg(*param_1,&local_b8,&local_c8,1,0x14), iVar2 < 0)) {
    _printk(&DAT_00102c7f,iVar2);
  }
  mutex_unlock(param_1 + 1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_add_server @ 001014b0 size=172
// signature: undefined qmi_add_server(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qmi_add_server(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  
  puVar2 = (undefined4 *)kmalloc_trace(___init_swait_queue_head,0xdc0,0x30);
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *puVar2 = param_2;
    puVar2[1] = param_3;
    puVar2[2] = param_4;
    puVar1 = puVar2 + 8;
    plVar6 = (long *)(param_1 + 0xb0);
    lVar5 = *plVar6;
    *(undefined4 *)(param_1 + 0x140) = param_2;
    uVar3 = __list_add_valid(puVar1,plVar6,lVar5);
    if ((uVar3 & 1) != 0) {
      *(undefined4 **)(lVar5 + 8) = puVar1;
      *(long *)(puVar2 + 8) = lVar5;
      *(long **)(puVar2 + 10) = plVar6;
      *plVar6 = (long)puVar1;
    }
    qmi_send_new_server(param_1,puVar2);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// qmi_send_new_server @ 0010155c size=256
// signature: undefined qmi_send_new_server(void)
// callers: [qmi_data_ready_work, qmi_add_server]
//------------------------------------------------------------

void qmi_send_new_server(long *param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 *local_c8;
  undefined8 uStack_c0;
  uint *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_c8 = &local_40;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_c0 = 0x14;
  uStack_3c = *param_2;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_40 = 4;
  uStack_4c = *(undefined4 *)((long)param_1 + 0x3c);
  uStack_30 = (undefined4)param_1[8];
  local_90 = 0;
  uStack_88 = 0;
  local_38 = param_2[1] | param_2[2] << 8;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_b8 = &local_50;
  local_50 = (uint)*(ushort *)(param_1 + 7);
  local_48 = 0xfffffffe;
  local_b0 = 0xc;
  local_34 = uStack_4c;
  mutex_lock(param_1 + 1);
  if ((*param_1 != 0) && (iVar2 = kernel_sendmsg(*param_1,&local_b8,&local_c8,1,0x14), iVar2 < 0)) {
    _printk(&DAT_00102ce8,iVar2);
  }
  mutex_unlock(param_1 + 1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_txn_init @ 00101660 size=196
// signature: undefined qmi_txn_init(void)
// callers: []
//------------------------------------------------------------

int qmi_txn_init(long param_1,long *param_2,long param_3,long param_4)

{
  int iVar1;
  
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[4] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  *param_2 = 0;
  param_2[3] = 0;
  __init_swait_queue_head(param_2 + 3,"&x->wait",&init_completion___key);
  *param_2 = param_1;
  param_2[7] = param_3;
  param_2[8] = param_4;
  mutex_lock(param_1 + 0x108);
  iVar1 = idr_alloc_cyclic(param_1 + 0xf0,param_2,0,0xffff,0xcc0);
  if (iVar1 < 0) {
    _printk(&DAT_00102c19);
  }
  *(short *)(param_2 + 1) = (short)iVar1;
  mutex_unlock(param_1 + 0x108);
  return iVar1;
}



//------------------------------------------------------------
// qmi_txn_wait @ 00101728 size=128
// signature: undefined qmi_txn_wait(void)
// callers: []
//------------------------------------------------------------

undefined4 qmi_txn_wait(long *param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar4 = *param_1;
  iVar2 = wait_for_completion_timeout(param_1 + 2);
  if ((int)param_1[6] == -0x66) {
    uVar3 = 0xffffff9a;
  }
  else {
    lVar1 = lVar4 + 0x108;
    mutex_lock(lVar1);
    idr_remove(lVar4 + 0xf0,(short)param_1[1]);
    mutex_unlock(lVar1);
    if (iVar2 == 0) {
      uVar3 = 0xffffff92;
    }
    else {
      uVar3 = (undefined4)param_1[6];
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// qmi_txn_cancel @ 001017ac size=80
// signature: undefined qmi_txn_cancel(void)
// callers: []
//------------------------------------------------------------

void qmi_txn_cancel(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *param_1;
  lVar1 = lVar2 + 0x108;
  mutex_lock(lVar1);
  idr_remove(lVar2 + 0xf0,(short)param_1[1]);
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// qmi_handle_init @ 00101800 size=428
// signature: undefined qmi_handle_init(void)
// callers: []
//------------------------------------------------------------

undefined4 qmi_handle_init(ulong *param_1,long param_2,ulong *param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  __mutex_init(param_1 + 0x21,"&qmi->txn_lock",&qmi_handle_init___key);
  __mutex_init(param_1 + 1,"&qmi->sock_lock",&qmi_handle_init___key_2);
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x1e] = 0x1000000400000000;
  param_1[0x12] = (ulong)(param_1 + 0x12);
  param_1[0x13] = (ulong)(param_1 + 0x12);
  param_1[0x14] = (ulong)(param_1 + 0x14);
  param_1[0x15] = (ulong)(param_1 + 0x14);
  param_1[0x16] = (ulong)(param_1 + 0x16);
  param_1[0x17] = (ulong)(param_1 + 0x16);
  param_1[9] = 0xfffffffe0;
  param_1[10] = (ulong)(param_1 + 10);
  param_1[0xb] = (ulong)(param_1 + 10);
  param_1[0x27] = param_4;
  param_1[0xc] = (ulong)qmi_data_ready_work;
  if (param_3 != (ulong *)0x0) {
    uVar3 = param_3[1];
    param_1[0x18] = *param_3;
    param_1[0x19] = uVar3;
    uVar1 = param_3[5];
    uVar3 = param_3[2];
    uVar2 = param_3[3];
    param_1[0x1c] = param_3[4];
    param_1[0x1d] = uVar1;
    param_1[0x1a] = uVar3;
    param_1[0x1b] = uVar2;
  }
  uVar3 = param_2 + 7;
  if (uVar3 < 0x15) {
    uVar3 = 0x14;
  }
  param_1[0x11] = uVar3;
  uVar3 = __kmalloc(uVar3,0xdc0);
  param_1[0x10] = uVar3;
  if (uVar3 == 0) {
    uVar4 = 0xfffffff4;
  }
  else {
    uVar3 = alloc_workqueue("qmi_msg_handler",0x12,1);
    param_1[0xf] = uVar3;
    if (uVar3 == 0) {
      uVar4 = 0xfffffff4;
    }
    else {
      uVar3 = qmi_sock_create(param_1,param_1 + 7);
      *param_1 = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        if (qmi_ilc == 0) {
          qmi_ilc = ipc_log_context_create(8,"qmi_interface",0);
          return 0;
        }
        return 0;
      }
      if (uVar3 == 0xffffffffffffff9f) {
        uVar4 = 0xfffffdfb;
      }
      else {
        _printk(&DAT_00102a3b);
        uVar4 = (undefined4)*param_1;
      }
      destroy_workqueue(param_1[0xf]);
    }
    kfree(param_1[0x10]);
  }
  return uVar4;
}



//------------------------------------------------------------
// qmi_data_ready_work @ 001019b0 size=1864
// signature: undefined qmi_data_ready_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_data_ready_work(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  long *plVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  code *pcVar13;
  uint *puVar14;
  undefined4 *puVar15;
  long *plVar16;
  long lVar17;
  long *plVar18;
  long *plVar19;
  char *pcVar20;
  long *plVar21;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 *local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  int local_c0;
  undefined8 local_b8;
  ulong local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar9 = sp_el0;
  lVar17 = param_1 + -0x40;
  local_70 = *(long *)(lVar9 + 0x638);
  local_130 = &local_c8;
  local_c0 = 0;
  local_c8 = 0;
  local_140 = *(undefined8 *)(param_1 + 0x38);
  local_138 = *(undefined8 *)(param_1 + 0x40);
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  uStack_120 = 0;
  local_128 = 0xc;
  mutex_lock(lVar17);
  plVar16 = (long *)(param_1 + -0x48);
  lVar9 = *plVar16;
  if (lVar9 != 0) {
    lVar1 = param_1 + 0xc0;
    plVar18 = (long *)(param_1 + 0x58);
    do {
      uVar7 = kernel_recvmsg(lVar9,&local_130,&local_140,1,local_138,0x40);
      lVar9 = (long)(int)uVar7;
      mutex_unlock(lVar17);
      if (lVar9 == -0xb) goto LAB_001020bc;
      if (lVar9 == -0x66) {
        local_b0 = local_b0 & 0xffffffff00000000;
        local_b8 = 0;
        uVar11 = qmi_sock_create(plVar16,&local_b8);
        if (uVar11 < 0xfffffffffffff001) {
          mutex_lock(lVar17);
          sock_release(*plVar16);
          *plVar16 = 0;
          mutex_unlock(lVar17);
          plVar19 = (long *)*plVar18;
          while (plVar19 != plVar18) {
            pcVar13 = *(code **)(param_1 + 0x80);
            plVar21 = (long *)*plVar19;
            if (pcVar13 != (code *)0x0) {
              if (*(int *)(pcVar13 + -4) != -0xcb05aeb) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x102080);
                (*pcVar13)();
              }
              (*pcVar13)(plVar16,plVar19 + -4);
            }
            uVar12 = __list_del_entry_valid(plVar19);
            if ((uVar12 & 1) != 0) {
              lVar9 = *plVar19;
              plVar5 = (long *)plVar19[1];
              *(long **)(lVar9 + 8) = plVar5;
              *plVar5 = lVar9;
            }
            *plVar19 = -0x2152ffffffffff00;
            plVar19[1] = -0x2152fffffffffede;
            kfree(plVar19 + -4);
            plVar19 = plVar21;
          }
          pcVar13 = *(code **)(param_1 + 0x88);
          if (pcVar13 != (code *)0x0) {
            if (*(int *)(pcVar13 + -4) != -0x13d8742b) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101fb8);
              (*pcVar13)();
            }
            (*pcVar13)(plVar16);
          }
          mutex_lock(lVar17);
          *(ulong *)(param_1 + -0x48) = uVar11;
          *(undefined8 *)(param_1 + -0x10) = local_b8;
          *(undefined4 *)(param_1 + -8) = (undefined4)local_b0;
          mutex_unlock(lVar17);
          for (plVar18 = *(long **)(param_1 + 0x48); plVar18 != (long *)(param_1 + 0x48);
              plVar18 = (long *)*plVar18) {
            qmi_send_new_lookup(plVar16,plVar18 + -4);
          }
          for (plVar18 = *(long **)(param_1 + 0x68); plVar18 != (long *)(param_1 + 0x68);
              plVar18 = (long *)*plVar18) {
            qmi_send_new_server(plVar16,plVar18 + -4);
          }
        }
        ipc_log_string(qmi_ilc,"Invoke ENETRESET on a QMI handle for svc_id:0x%x [0x%x:0x%x]\n",
                       *(undefined4 *)(param_1 + 0xf8),local_c8._4_4_,local_c0);
        goto LAB_001020bc;
      }
      if ((int)uVar7 < 0) goto LAB_001020ac;
      puVar14 = *(uint **)(param_1 + 0x38);
      uVar6 = *puVar14;
      if (uVar6 == 3) {
        ipc_log_string(qmi_ilc,"cmd:0x%x node[0x%x]\n",3,local_c8._4_4_);
      }
      else if ((uVar6 & 0xfffffffe) == 4) {
        ipc_log_string(qmi_ilc,"cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n",uVar6,puVar14[1],
                       puVar14[2],puVar14[3],puVar14[4]);
      }
      else if ((uVar6 & 0xfffffffe) == 6) {
        ipc_log_string(qmi_ilc,"cmd:0x%x addr[0x%x:0x%x]\n",uVar6,puVar14[1],puVar14[2]);
      }
      else {
        ipc_log_string(qmi_ilc,"DATA: type:%d txn_id:%d svc:0x%x, msg_id:%d len:%d sq[0x%x:0x%x]\n",
                       uVar6 & 0xff,uVar6 >> 8 & 0xffff,*(undefined4 *)(param_1 + 0xf8),
                       *(undefined2 *)((long)puVar14 + 3),*(undefined2 *)((long)puVar14 + 5),
                       local_c8._4_4_,local_c0);
      }
      if ((local_c8._4_4_ == *(int *)(param_1 + -0xc)) && (local_c0 == -2)) {
        if (0x13 < uVar7) {
          puVar15 = *(undefined4 **)(param_1 + 0x38);
          switch(*puVar15) {
          case 3:
            iVar8 = puVar15[1];
            plVar19 = (long *)*plVar18;
            while (plVar21 = plVar19, plVar21 != plVar18) {
              plVar19 = (long *)*plVar21;
              if ((iVar8 == -1) || (*(int *)((long)plVar21 + -0x14) == iVar8)) {
                pcVar13 = *(code **)(param_1 + 0x80);
                if (pcVar13 != (code *)0x0) {
                  if (*(int *)(pcVar13 + -4) != -0xcb05aeb) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101ce0);
                    (*pcVar13)();
                  }
                  (*pcVar13)(plVar16,plVar21 + -4);
                }
                uVar11 = __list_del_entry_valid(plVar21);
                if ((uVar11 & 1) != 0) {
                  lVar9 = *plVar21;
                  plVar5 = (long *)plVar21[1];
                  *(long **)(lVar9 + 8) = plVar5;
                  *plVar5 = lVar9;
                }
                *plVar21 = -0x2152ffffffffff00;
                plVar21[1] = -0x2152fffffffffede;
                kfree(plVar21 + -4);
              }
            }
            pcVar13 = *(code **)(param_1 + 0x98);
            if (pcVar13 != (code *)0x0) {
              if (*(int *)(pcVar13 + -4) != -0x14ff6de7) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101c78);
                (*pcVar13)();
              }
              (*pcVar13)(plVar16,iVar8);
            }
            break;
          case 4:
            iVar8 = puVar15[3];
            iVar4 = puVar15[4];
            if ((iVar4 != 0 || iVar8 != 0) && (*(long *)(param_1 + 0x78) != 0)) {
              uVar3 = puVar15[1];
              uVar7 = puVar15[2];
              puVar15 = (undefined4 *)kmalloc_trace(___init_swait_queue_head,0xdc0,0x30);
              if (puVar15 != (undefined4 *)0x0) {
                puVar15[4] = iVar4;
                *puVar15 = uVar3;
                puVar15[1] = uVar7 & 0xff;
                pcVar13 = *(code **)(param_1 + 0x78);
                puVar15[2] = uVar7 >> 8;
                puVar15[3] = iVar8;
                if (*(int *)(pcVar13 + -4) != -0x1fcdc6ad) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101da4);
                  (*pcVar13)();
                }
                iVar8 = (*pcVar13)(plVar16,puVar15);
                if (iVar8 < 0) {
                  kfree(puVar15);
                }
                else {
                  lVar9 = *plVar18;
                  puVar2 = puVar15 + 8;
                  uVar11 = __list_add_valid(puVar2,plVar18,lVar9);
                  if ((uVar11 & 1) != 0) {
                    *(undefined4 **)(lVar9 + 8) = puVar2;
                    *(long *)(puVar15 + 8) = lVar9;
                    *(long **)(puVar15 + 10) = plVar18;
                    *plVar18 = (long)puVar2;
                  }
                }
              }
            }
            break;
          case 5:
            if ((long *)*plVar18 != plVar18) {
              iVar8 = puVar15[3];
              iVar4 = puVar15[4];
              plVar19 = (long *)*plVar18;
              do {
                plVar21 = (long *)*plVar19;
                if (((iVar8 == -1) || (*(int *)((long)plVar19 + -0x14) == iVar8)) &&
                   ((iVar4 == -1 || ((int)plVar19[-2] == iVar4)))) {
                  pcVar13 = *(code **)(param_1 + 0x80);
                  if (pcVar13 != (code *)0x0) {
                    if (*(int *)(pcVar13 + -4) != -0xcb05aeb) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101e60);
                      (*pcVar13)();
                    }
                    (*pcVar13)(plVar16,plVar19 + -4);
                  }
                  uVar11 = __list_del_entry_valid(plVar19);
                  if ((uVar11 & 1) != 0) {
                    lVar9 = *plVar19;
                    plVar5 = (long *)plVar19[1];
                    *(long **)(lVar9 + 8) = plVar5;
                    *plVar5 = lVar9;
                  }
                  *plVar19 = -0x2152ffffffffff00;
                  plVar19[1] = -0x2152fffffffffede;
                  kfree(plVar19 + -4);
                }
                plVar19 = plVar21;
              } while (plVar21 != plVar18);
            }
            break;
          case 6:
            pcVar13 = *(code **)(param_1 + 0xa0);
            if (pcVar13 != (code *)0x0) {
              if (*(int *)(pcVar13 + -4) != 0x568057f4) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x101ea8);
                (*pcVar13)();
              }
              (*pcVar13)(plVar16,puVar15[1],puVar15[2]);
            }
          }
        }
      }
      else {
        pcVar13 = *(code **)(param_1 + 0x90);
        pcVar20 = *(char **)(param_1 + 0x38);
        if (pcVar13 == (code *)0x0) {
          if (uVar7 < 7) {
            _printk(&DAT_00102d33);
          }
          else if (*pcVar20 == '\x02') {
            mutex_lock(lVar1);
            lVar10 = idr_find(param_1 + 0xa8,*(undefined2 *)(pcVar20 + 1));
            if (lVar10 == 0) {
              ipc_log_string(qmi_ilc,"txn_id 0x%x svc_id:0x%x not found for remote[0x%x:0x%x]\n",
                             *(undefined2 *)(pcVar20 + 1),*(undefined4 *)(param_1 + 0xf8),
                             local_c8._4_4_,local_c0);
              mutex_unlock(lVar1);
            }
            else {
              if ((*(long *)(lVar10 + 0x40) == 0) || (*(long *)(lVar10 + 0x38) == 0)) {
                qmi_invoke_handler(plVar16,&local_c8,lVar10,pcVar20,lVar9);
              }
              else {
                iVar8 = qmi_decode_message(pcVar20,lVar9);
                if (iVar8 < 0) {
                  _printk(&DAT_00102cc3);
                }
                *(int *)(lVar10 + 0x30) = iVar8;
                complete(lVar10 + 0x10);
              }
              mutex_unlock(lVar1);
            }
          }
          else {
            local_80 = 0;
            uStack_78 = 0;
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            uStack_a8 = 0;
            local_b8 = 0;
            local_b0 = (ulong)*(ushort *)(pcVar20 + 1);
            qmi_invoke_handler(plVar16,&local_c8,&local_b8,pcVar20,lVar9);
          }
        }
        else {
          if (*(int *)(pcVar13 + -4) != 0x15aa0683) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x101a84);
            (*pcVar13)();
          }
          (*pcVar13)(plVar16,&local_c8,pcVar20,lVar9);
        }
      }
      local_140 = *(undefined8 *)(param_1 + 0x38);
      local_138 = *(undefined8 *)(param_1 + 0x40);
      mutex_lock(lVar17);
      lVar9 = *(long *)(param_1 + -0x48);
    } while (lVar9 != 0);
  }
  mutex_unlock(lVar17);
  lVar9 = -0x20;
LAB_001020ac:
  _printk(&DAT_00102b44,lVar9);
LAB_001020bc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_sock_create @ 001020f8 size=232
// signature: undefined qmi_sock_create(void)
// callers: [qmi_data_ready_work, qmi_handle_init]
//------------------------------------------------------------

void qmi_sock_create(ulong param_1,undefined8 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  iVar3 = sock_create_kern(&init_net,0x2a,2,0x2a,&local_30);
  if (iVar3 < 0) {
    lVar4 = (long)iVar3;
  }
  else {
    iVar3 = kernel_getsockname(local_30,param_2);
    if (iVar3 < 0) {
      sock_release(local_30);
      lVar4 = (long)iVar3;
    }
    else {
      if ((param_1 & 7) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1021dc);
        (*pcVar2)();
      }
      *(ulong *)(*(long *)(local_30 + 0x18) + 0x288) = param_1;
      *(code **)(*(long *)(local_30 + 0x18) + 0x2b8) = qmi_data_ready;
      *(code **)(*(long *)(local_30 + 0x18) + 0x2c8) = qmi_data_ready;
      *(undefined8 *)(*(long *)(local_30 + 0x18) + 400) = 0x9c4;
      lVar4 = local_30;
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
// qmi_handle_release @ 001021e8 size=608
// signature: undefined qmi_handle_release(void)
// callers: []
//------------------------------------------------------------

void qmi_handle_release(long *param_1)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  code *pcVar4;
  long lVar5;
  long *plVar6;
  int local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  ipc_log_string(qmi_ilc,"%s : SVC ID: 0x%x sock[0x%x:0x%x]\n","qmi_handle_release",
                 (int)param_1[0x28],*(undefined4 *)((long)param_1 + 0x3c),(int)param_1[8]);
  mutex_lock(param_1 + 1);
  lVar5 = *param_1;
  *(undefined8 *)(*(long *)(lVar5 + 0x18) + 0x288) = 0;
  synchronize_rcu();
  sock_release(lVar5);
  *param_1 = 0;
  mutex_unlock(param_1 + 1);
  cancel_work_sync(param_1 + 9);
  plVar2 = (long *)param_1[0x14];
  while (plVar2 != param_1 + 0x14) {
    pcVar4 = (code *)param_1[0x19];
    plVar6 = (long *)*plVar2;
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0xcb05aeb) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1023a4);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,plVar2 + -4);
    }
    uVar3 = __list_del_entry_valid(plVar2);
    if ((uVar3 & 1) != 0) {
      lVar5 = *plVar2;
      plVar1 = (long *)plVar2[1];
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
    }
    *plVar2 = -0x2152ffffffffff00;
    plVar2[1] = -0x2152fffffffffede;
    kfree(plVar2 + -4);
    plVar2 = plVar6;
  }
  destroy_workqueue(param_1[0xf]);
  mutex_lock(param_1 + 0x21);
  plVar2 = param_1 + 0x1e;
  local_4c = 0;
  lVar5 = idr_get_next(plVar2,&local_4c);
  if (lVar5 != 0) {
    do {
      idr_remove(plVar2,*(undefined2 *)(lVar5 + 8));
      *(undefined4 *)(lVar5 + 0x30) = 0xffffff9a;
      complete(lVar5 + 0x10);
      local_4c = local_4c + 1;
      lVar5 = idr_get_next(plVar2,&local_4c);
    } while (lVar5 != 0);
  }
  mutex_unlock(param_1 + 0x21);
  idr_destroy(plVar2);
  kfree(param_1[0x10]);
  plVar2 = (long *)param_1[0x12];
  while (plVar2 != param_1 + 0x12) {
    plVar6 = (long *)*plVar2;
    uVar3 = __list_del_entry_valid(plVar2);
    if ((uVar3 & 1) != 0) {
      lVar5 = *plVar2;
      plVar1 = (long *)plVar2[1];
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
    }
    *plVar2 = -0x2152ffffffffff00;
    plVar2[1] = -0x2152fffffffffede;
    kfree(plVar2 + -4);
    plVar2 = plVar6;
  }
  plVar2 = (long *)param_1[0x16];
  while (plVar2 != param_1 + 0x16) {
    plVar6 = (long *)*plVar2;
    uVar3 = __list_del_entry_valid(plVar2);
    if ((uVar3 & 1) != 0) {
      lVar5 = *plVar2;
      plVar1 = (long *)plVar2[1];
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
    }
    *plVar2 = -0x2152ffffffffff00;
    plVar2[1] = -0x2152fffffffffede;
    kfree(plVar2 + -4);
    plVar2 = plVar6;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_send_request @ 0010244c size=48
// signature: undefined qmi_send_request(void)
// callers: []
//------------------------------------------------------------

void qmi_send_request(void)

{
  qmi_send_message();
  return;
}



//------------------------------------------------------------
// qmi_send_message @ 0010247c size=292
// signature: undefined qmi_send_message(void)
// callers: [qmi_send_response, qmi_send_indication, qmi_send_request]
//------------------------------------------------------------

ulong qmi_send_message(long *param_1,long param_2,long param_3,undefined4 param_4,undefined4 param_5
                      ,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong local_b8;
  undefined8 uStack_b0;
  long local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_40 = param_6;
  uVar3 = qmi_encode_message(param_4,param_5,&local_40,*(undefined2 *)(param_3 + 8),param_7,param_8)
  ;
  if (uVar3 < 0xfffffffffffff001) {
    uStack_b0 = local_40;
    if (param_2 != 0) {
      local_a0 = CONCAT44(local_a0._4_4_,0xc);
      local_a8 = param_2;
    }
    local_b8 = uVar3;
    mutex_lock(param_1 + 1);
    if (*param_1 == 0) {
      iVar2 = -0x20;
    }
    else {
      iVar2 = kernel_sendmsg(*param_1,&local_a8,&local_b8,1,local_40);
      if (iVar2 < 0) {
        _printk(&DAT_00102c3e);
      }
    }
    mutex_unlock(param_1 + 1);
    kfree(uVar3);
    if (-1 < iVar2) {
      iVar2 = 0;
    }
    uVar3 = (ulong)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// qmi_send_response @ 001025a4 size=48
// signature: undefined qmi_send_response(void)
// callers: []
//------------------------------------------------------------

void qmi_send_response(void)

{
  qmi_send_message();
  return;
}



//------------------------------------------------------------
// qmi_send_indication @ 001025d8 size=348
// signature: undefined qmi_send_indication(void)
// callers: []
//------------------------------------------------------------

long qmi_send_indication(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                        undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long local_a0;
  ulong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  __init_swait_queue_head(&local_88,"&x->wait",&init_completion___key);
  lVar4 = param_1 + 0x108;
  local_68 = 0;
  uStack_60 = 0;
  local_a0 = param_1;
  mutex_lock(lVar4);
  iVar3 = idr_alloc_cyclic(param_1 + 0xf0,&local_a0,0,0xffff,0xcc0);
  if (iVar3 < 0) {
    _printk(&DAT_00102c19);
    local_98 = CONCAT62(local_98._2_6_,(short)iVar3);
    mutex_unlock(lVar4);
    lVar4 = (long)iVar3;
  }
  else {
    local_98 = CONCAT62(local_98._2_6_,(short)iVar3);
    mutex_unlock(lVar4);
    lVar4 = qmi_send_message(param_1,param_2,&local_a0,4,param_3,param_4,param_5,param_6);
    lVar2 = local_a0;
    lVar1 = local_a0 + 0x108;
    mutex_lock(lVar1);
    idr_remove(lVar2 + 0xf0,local_98 & 0xffff);
    mutex_unlock(lVar1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// qmi_invoke_handler @ 00102734 size=292
// signature: undefined qmi_invoke_handler(void)
// callers: [qmi_data_ready_work]
//------------------------------------------------------------

void qmi_invoke_handler(long param_1,undefined8 param_2,undefined8 param_3,byte *param_4,
                       undefined8 param_5)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  
  lVar4 = *(long *)(param_1 + 0x138);
  if ((lVar4 != 0) && (*(long *)(lVar4 + 0x18) != 0)) {
    puVar5 = (undefined8 *)(lVar4 + 0x10);
    do {
      if ((*(uint *)(puVar5 + -2) == (uint)*param_4) &&
         (*(uint *)((long)puVar5 + -0xc) == (uint)*(ushort *)(param_4 + 3))) {
        lVar4 = __kmalloc(*puVar5,0xdc0);
        if (lVar4 == 0) {
          ipc_log_string(qmi_ilc,"failed to allocate memory of decoded_size: 0x%x svc_id:0x%x\n",
                         *puVar5,*(undefined4 *)(param_1 + 0x140));
          return;
        }
        iVar3 = qmi_decode_message(param_4,param_5,puVar5[-1],lVar4);
        if (iVar3 < 0) {
          _printk(&DAT_00102cc3);
        }
        else {
          if (*(int *)((code *)puVar5[1] + -4) != 0x7caaa272) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102800);
            (*pcVar2)();
          }
          (*(code *)puVar5[1])(param_1,param_2,param_3,lVar4);
        }
        kfree(lVar4);
        return;
      }
      plVar1 = puVar5 + 5;
      puVar5 = puVar5 + 4;
    } while (*plVar1 != 0);
  }
  return;
}



//------------------------------------------------------------
// qmi_data_ready @ 0010285c size=100
// signature: undefined qmi_data_ready(void)
// callers: []
//------------------------------------------------------------

void qmi_data_ready(long param_1)

{
  ulong uVar1;
  
  __rcu_read_lock();
  uVar1 = *(ulong *)(param_1 + 0x288) & 0xfffffffffffffff8;
  if (uVar1 != 0) {
    ipc_log_string(qmi_ilc,"qmi recv pkt queued for svc_id:0x%x sock[0x%x:0x%x]\n",
                   *(undefined4 *)(uVar1 + 0x140),*(undefined4 *)(uVar1 + 0x3c),
                   *(undefined4 *)(uVar1 + 0x40));
    queue_work_on(0x20,*(undefined8 *)(uVar1 + 0x78),uVar1 + 0x48);
  }
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// __kmalloc @ 00104000 size=1
// signature: undefined __kmalloc(void)
// callers: [qmi_handle_init, qmi_encode_message, qmi_invoke_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104008 size=1
// signature: undefined kfree(void)
// callers: [qmi_send_message, qmi_data_ready_work, qmi_handle_init, qmi_encode_message, qmi_handle_release, qmi_invoke_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104010 size=1
// signature: undefined _printk(void)
// callers: [qmi_send_new_lookup, qmi_send_message, qmi_data_ready_work, qmi_handle_init, qmi_txn_init, qmi_encode_message, qmi_invoke_handler, qmi_send_indication, qmi_encode, qmi_decode, qmi_send_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104018 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qmi_decode, qmi_encode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00104020 size=1
// signature: size_t strlen(char * __s)
// callers: [qmi_encode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qmi_send_new_lookup, qmi_sock_create, qmi_send_message, qmi_data_ready_work, qmi_handle_release, qmi_send_indication, qmi_encode, qmi_decode, qmi_send_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104030 size=1
// signature: undefined fortify_panic(void)
// callers: [qmi_decode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104040 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qmi_data_ready_work, qmi_add_server, qmi_add_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104048 size=1
// signature: undefined __list_add_valid(void)
// callers: [qmi_data_ready_work, qmi_add_server, qmi_add_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104050 size=1
// signature: undefined mutex_lock(void)
// callers: [qmi_send_new_lookup, qmi_send_message, qmi_txn_wait, qmi_data_ready_work, qmi_txn_init, qmi_txn_cancel, qmi_handle_release, qmi_send_indication, qmi_send_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_sendmsg @ 00104058 size=1
// signature: undefined kernel_sendmsg(void)
// callers: [qmi_send_new_lookup, qmi_send_message, qmi_send_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_sendmsg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104060 size=1
// signature: undefined mutex_unlock(void)
// callers: [qmi_send_new_lookup, qmi_send_message, qmi_txn_wait, qmi_data_ready_work, qmi_txn_init, qmi_txn_cancel, qmi_handle_release, qmi_send_indication, qmi_send_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104068 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qmi_txn_init, qmi_send_indication]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_cyclic @ 00104070 size=1
// signature: undefined idr_alloc_cyclic(void)
// callers: [qmi_txn_init, qmi_send_indication]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00104078 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [qmi_txn_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00104080 size=1
// signature: undefined idr_remove(void)
// callers: [qmi_txn_wait, qmi_txn_cancel, qmi_handle_release, qmi_send_indication]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104088 size=1
// signature: undefined __mutex_init(void)
// callers: [qmi_handle_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00104090 size=1
// signature: undefined alloc_workqueue(void)
// callers: [qmi_handle_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00104098 size=1
// signature: undefined destroy_workqueue(void)
// callers: [qmi_handle_init, qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001040a0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qmi_handle_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_recvmsg @ 001040a8 size=1
// signature: undefined kernel_recvmsg(void)
// callers: [qmi_data_ready_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_recvmsg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001040b0 size=1
// signature: undefined ipc_log_string(void)
// callers: [qmi_data_ready_work, qmi_data_ready, qmi_handle_release, qmi_invoke_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 001040b8 size=1
// signature: undefined idr_find(void)
// callers: [qmi_data_ready_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001040c0 size=1
// signature: undefined complete(void)
// callers: [qmi_data_ready_work, qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040c8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qmi_data_ready_work, qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_release @ 001040d0 size=1
// signature: undefined sock_release(void)
// callers: [qmi_sock_create, qmi_data_ready_work, qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_create_kern @ 001040e0 size=1
// signature: undefined sock_create_kern(void)
// callers: [qmi_sock_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_create_kern(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_getsockname @ 001040e8 size=1
// signature: undefined kernel_getsockname(void)
// callers: [qmi_sock_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_getsockname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 001040f0 size=1
// signature: undefined synchronize_rcu(void)
// callers: [qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001040f8 size=1
// signature: undefined cancel_work_sync(void)
// callers: [qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_get_next @ 00104100 size=1
// signature: undefined idr_get_next(void)
// callers: [qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_get_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 00104108 size=1
// signature: undefined idr_destroy(void)
// callers: [qmi_handle_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00104110 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [qmi_data_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104118 size=1
// signature: undefined queue_work_on(void)
// callers: [qmi_data_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00104120 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [qmi_data_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



