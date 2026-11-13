// Decompiled by Ghidra 12.2
// Program: spmi-pmic-arb.ko
// Image base: 00100000

//------------------------------------------------------------
// spmi_pmic_arb_map_address @ 00100c8c size=312
// signature: undefined spmi_pmic_arb_map_address(void)
// callers: []
//------------------------------------------------------------

void spmi_pmic_arb_map_address(long param_1,uint param_2,long param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  long local_78 [11];
  
  lVar2 = sp_el0;
  local_78[10] = *(long *)(lVar2 + 0x638);
  if (((param_1 == 0) || (param_3 == 0)) || (*(long *)(param_1 + 0x2e8) == 0)) {
    _printk(&DAT_00104268,"spmi_pmic_arb_map_address");
    uVar3 = 0xffffffea;
    goto LAB_00100d50;
  }
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  iVar1 = __of_parse_phandle_with_args(*(long *)(param_1 + 0x2e8),"qcom,pmic-arb",0,0,0,local_78);
  if ((iVar1 == 0) && (local_78[0] != 0)) {
    lVar2 = of_find_device_by_node();
    if ((lVar2 == 0) || (*(long *)(lVar2 + 0xa8) == 0)) {
      uVar3 = 0xfffffdfb;
      goto LAB_00100d50;
    }
    lVar2 = *(long *)(*(long *)(lVar2 + 0xa8) + 0x98);
    if (lVar2 != 0) {
      pcVar4 = *(code **)(*(long *)(lVar2 + 0xb0) + 0x58);
      if (*(int *)(pcVar4 + -4) != -0x75b4cca7) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100d44);
        (*pcVar4)();
      }
      uVar3 = (*pcVar4)(lVar2,param_2 >> 0x10 & 0xf,param_2,param_3);
      goto LAB_00100d50;
    }
    _printk(&DAT_0010427f);
  }
  else {
    _printk(&DAT_0010420a,"spmi_pmic_arb_map_address");
  }
  uVar3 = 0xffffffed;
LAB_00100d50:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// spmi_pmic_arb_probe @ 00100dc8 size=1508
// signature: undefined spmi_pmic_arb_probe(void)
// callers: []
//------------------------------------------------------------

ulong spmi_pmic_arb_probe(long param_1)

{
  long lVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  char *pcVar12;
  undefined **ppuVar13;
  ulong uVar14;
  ulong *puVar15;
  ulong uVar16;
  uint local_64;
  uint local_60;
  uint local_5c;
  long local_58;
  
  lVar11 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_58 = *(long *)(lVar11 + 0x638);
  local_5c = 0;
  local_64 = 0;
  local_60 = 0;
  uVar6 = spmi_controller_alloc(lVar1,0xe8);
  if (uVar6 == 0) {
    uVar8 = 0xfffffff4;
    goto LAB_001011f8;
  }
  puVar15 = *(ulong **)(uVar6 + 0x98);
  puVar15[0x15] = uVar6;
  puVar7 = (ulong *)platform_get_resource_byname(param_1,0x200,&DAT_001043cc);
  if ((puVar7 == (ulong *)0x0) ||
     (uVar8 = devm_ioremap(uVar6,*puVar7,(puVar7[1] - *puVar7) + 1), uVar8 == 0)) goto LAB_001011ec;
  if (uVar8 < 0xfffffffffffff001) {
    puVar15[6] = (puVar7[1] - *puVar7) + 1;
    uVar9 = devm_kmalloc(uVar6,0x2000,0xdc0);
    puVar15[0x17] = uVar9;
    if (uVar9 == 0) {
LAB_00100edc:
      uVar8 = 0xfffffff4;
    }
    else {
      uVar9 = readl_relaxed(uVar8);
      uVar16 = uVar9 & 0xffffffff;
      if ((uint)uVar9 < 0x20010000) {
        puVar15[1] = uVar8;
        puVar15[0x16] = (ulong)&pmic_arb_v1;
        uVar9 = 0x200;
        uVar14 = *puVar7;
        *puVar15 = uVar8;
        *(undefined4 *)(puVar15 + 0x1a) = 0x200;
        puVar15[2] = uVar14;
LAB_00100ec4:
        uVar8 = devm_kmalloc(uVar6,uVar9 << 2,0xdc0);
        puVar15[0x19] = uVar8;
        if (uVar8 == 0) goto LAB_00100edc;
        _dev_info(uVar6,"PMIC arbiter version %s (0x%x)\n",*(undefined8 *)puVar15[0x16],uVar16);
        lVar11 = platform_get_resource_byname(param_1,0x200,&DAT_00104453);
        if (lVar11 != 0) {
          uVar9 = devm_ioremap_resource(uVar6,lVar11);
          puVar15[3] = uVar9;
          if (0xfffffffffffff000 < uVar9) goto LAB_00100fb0;
          lVar11 = platform_get_resource_byname(param_1,0x200,&DAT_001044a4);
          if (lVar11 != 0) {
            uVar9 = devm_ioremap_resource(uVar6,lVar11);
            puVar15[4] = uVar9;
            if (0xfffffffffffff000 < uVar9) goto LAB_00100fb0;
            lVar11 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"interrupt-names",0);
            if (lVar11 != 0) {
              uVar3 = platform_get_irq_byname(param_1,"periph_irq");
              *(uint *)(puVar15 + 8) = uVar3;
              if ((int)uVar3 < 0) {
                uVar8 = (ulong)uVar3;
                goto LAB_001011f0;
              }
            }
            uVar3 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,channel",&local_5c,1,0);
            if ((int)uVar3 < 0) {
              pcVar12 = "channel unspecified.\n";
LAB_0010136c:
              uVar8 = (ulong)uVar3;
              _dev_err(lVar1,pcVar12);
              goto LAB_001011f0;
            }
            if (local_5c < 6) {
              *(char *)((long)puVar15 + 0x3c) = (char)local_5c;
              uVar3 = of_property_read_variable_u32_array
                                (*(undefined8 *)(param_1 + 0x2f8),"qcom,ee",&local_60,1,0);
              if ((int)uVar3 < 0) {
                pcVar12 = "EE unspecified.\n";
                goto LAB_0010136c;
              }
              if (local_60 < 6) {
                *(char *)((long)puVar15 + 0x44) = (char)local_60;
                *(undefined1 *)((long)puVar15 + 0x4c) = 0x16;
                iVar4 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,mid",&local_64,1,0);
                if ((iVar4 < 0) || (3 < local_64)) {
                  if (-1 < iVar4) {
                    iVar4 = 0;
                  }
                  if (iVar4 != -0x16) {
                    pcVar12 = "invalid MID (%u) specified\n";
                    goto LAB_001011e4;
                  }
                }
                else {
                  *(char *)((long)puVar15 + 0x4c) = (char)local_64;
                }
                uVar8 = devm_kmalloc(uVar6,0x800,0xdc0);
                if (uVar8 != 0) {
                  puVar15[0xb] = uVar8;
                  *(undefined2 *)(puVar15 + 10) = 0;
                  *(short *)((long)puVar15 + 0x4e) = (short)puVar15[0x1a] + -1;
                  *(ulong *)(param_1 + 0xa8) = uVar6;
                  *(undefined4 *)(puVar15 + 7) = 0;
                  *(code **)(uVar6 + 0x398) = pmic_arb_cmd;
                  *(code **)(uVar6 + 0x3a0) = pmic_arb_read_cmd;
                  *(code **)(uVar6 + 0x3a8) = pmic_arb_write_cmd;
                  if (4 < (uint)(uVar16 >> 0x1c)) {
                    pmic_arb_read_apid_map_v5(puVar15);
                  }
                  if (0 < (int)puVar15[8]) {
                    lVar11 = 0;
                    if (*(long *)(param_1 + 0x2f8) != 0) {
                      lVar11 = *(long *)(param_1 + 0x2f8) + 0x18;
                    }
                    uVar8 = __irq_domain_add(lVar11,0,0xffffffffffffffff,0,pmic_arb_irq_domain_ops,
                                             puVar15);
                    puVar15[0x14] = uVar8;
                    if (uVar8 == 0) {
                      _dev_err(lVar1,"unable to create irq_domain\n");
                      uVar8 = 0xfffffff4;
                      goto LAB_001011f0;
                    }
                    irq_set_chained_handler_and_data((int)puVar15[8],pmic_arb_chained_irq,puVar15);
                  }
                  uVar9 = spmi_controller_add(uVar6);
                  uVar8 = uVar9 & 0xffffffff;
                  if ((int)uVar9 == 0) {
                    spmi_pmic_arb_debugfs_init(puVar15);
                    goto LAB_001011f8;
                  }
                  if (0 < (int)puVar15[8]) {
                    irq_set_chained_handler_and_data((int)puVar15[8],0,0);
                    irq_domain_remove(puVar15[0x14]);
                  }
                  goto LAB_001011f0;
                }
                goto LAB_00100edc;
              }
              pcVar12 = "invalid EE (%u) specified\n";
            }
            else {
              pcVar12 = "invalid channel (%u) specified.\n";
            }
LAB_001011e4:
            _dev_err(lVar1,pcVar12);
          }
        }
      }
      else {
        uVar3 = (uint)(uVar16 >> 0x1c);
        puVar15[5] = uVar8;
        if (uVar3 < 3) {
          ppuVar13 = &pmic_arb_v2;
        }
        else if (uVar3 < 5) {
          ppuVar13 = &pmic_arb_v3;
        }
        else if (uVar3 < 7) {
          ppuVar13 = &pmic_arb_v5;
        }
        else {
          ppuVar13 = &pmic_arb_v7;
        }
        puVar15[0x16] = (ulong)ppuVar13;
        plVar10 = (long *)platform_get_resource_byname(param_1,0x200,"obsrvr");
        if (plVar10 != (long *)0x0) {
          uVar9 = devm_ioremap(uVar6,*plVar10,(plVar10[1] - *plVar10) + 1);
          *puVar15 = uVar9;
          if (uVar9 < 0xfffffffffffff001) {
            puVar7 = (ulong *)platform_get_resource_byname(param_1,0x200,"chnls");
            if (puVar7 == (ulong *)0x0) goto LAB_001011ec;
            uVar9 = devm_ioremap(uVar6,*puVar7,(puVar7[1] - *puVar7) + 1);
            puVar15[1] = uVar9;
            if (uVar9 < 0xfffffffffffff001) {
              puVar15[2] = *puVar7;
              *(undefined4 *)(puVar15 + 0x1a) = 0x200;
              if (uVar3 < 7) {
                if (uVar3 < 5) {
                  uVar9 = 0x200;
                  goto LAB_00100ec4;
                }
                *(undefined2 *)((long)puVar15 + 0x52) = 0;
                uVar5 = readl_relaxed(uVar8 + 4);
                uVar3 = (uint)puVar15[0x1a];
                *(uint *)((long)puVar15 + 0x54) = uVar5 & 0x7ff;
                if ((int)uVar3 < (int)(uVar5 & 0x7ff)) goto LAB_00101188;
LAB_001011cc:
                uVar9 = (ulong)uVar3;
                if ((int)uVar3 < 0) {
                  uVar8 = 0xfffffff4;
                  puVar15[0x19] = 0;
                  goto LAB_001011f0;
                }
                goto LAB_00100ec4;
              }
              *(undefined4 *)(puVar15 + 0x1a) = 0x400;
              of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,bus-id",puVar15 + 9,1,0);
              if ((uint)puVar15[9] < 2) {
                if ((uint)puVar15[9] == 0) {
                  uVar2 = 0;
                  lVar11 = 4;
                }
                else {
                  uVar2 = readl_relaxed(uVar8 + 4);
                  lVar11 = 8;
                  uVar2 = uVar2 & 0x7ff;
                }
                *(ushort *)((long)puVar15 + 0x52) = uVar2;
                uVar5 = readl_relaxed(uVar8 + lVar11);
                uVar3 = (uint)puVar15[0x1a];
                *(uint *)((long)puVar15 + 0x54) = uVar5 & 0x7ff;
                if ((int)((uVar5 & 0x7ff) + (uint)*(ushort *)((long)puVar15 + 0x52)) <= (int)uVar3)
                goto LAB_001011cc;
LAB_00101188:
                pcVar12 = "Unsupported APID count %d detected\n";
              }
              else {
                pcVar12 = "invalid bus instance (%u) specified\n";
              }
              goto LAB_001011e4;
            }
          }
LAB_00100fb0:
          uVar8 = uVar9 & 0xffffffff;
          goto LAB_001011f0;
        }
      }
LAB_001011ec:
      uVar8 = 0xffffffea;
    }
  }
LAB_001011f0:
  put_device(uVar6);
LAB_001011f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// spmi_pmic_arb_remove @ 001013b0 size=104
// signature: undefined spmi_pmic_arb_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 spmi_pmic_arb_remove(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  lVar2 = *(long *)(lVar1 + 0x98);
  debugfs_remove(*(undefined8 *)(lVar2 + 0xd8));
  spmi_controller_remove(lVar1);
  if (0 < *(int *)(lVar2 + 0x40)) {
    irq_set_chained_handler_and_data(*(int *)(lVar2 + 0x40),0,0);
    irq_domain_remove(*(undefined8 *)(lVar2 + 0xa0));
  }
  if (lVar1 != 0) {
    put_device(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00101418 size=124
// signature: undefined readl_relaxed(void)
// callers: [pmic_arb_chained_irq, pmic_arb_ppid_to_apid_v1, spmi_pmic_arb_probe, pmic_arb_wait_for_done, pmic_arb_read_apid_map_v5, periph_interrupt, pmic_arb_ppid_to_apid_v2]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101460,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// pmic_arb_cmd @ 00101498 size=88
// signature: undefined pmic_arb_cmd(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_arb_cmd(long param_1,char param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if ((byte)(param_2 - 0x14U) < 0xfc) {
    return 0xffffffea;
  }
  pcVar2 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x20);
  if (*(int *)(pcVar2 + -4) != -0x776f3218) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1014e0);
    (*pcVar2)();
  }
  uVar1 = (*pcVar2)();
  return uVar1;
}



//------------------------------------------------------------
// pmic_arb_read_cmd @ 001014f4 size=384
// signature: undefined pmic_arb_read_cmd(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_read_cmd(long param_1,byte param_2,undefined4 param_3,undefined4 param_4,
                     undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  pcVar4 = *(code **)(*(long *)(lVar5 + 0xb0) + 0x10);
  if (*(int *)(pcVar4 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101560);
    (*pcVar4)();
  }
  iVar1 = (*pcVar4)(lVar5,param_3,param_4,1);
  if (-1 < iVar1) {
    if (((int)param_6 - 1U & 0xff) < 8) {
      if ((char)param_2 < '`') {
        if ((param_2 & 0xf0) == 0x20) {
          uVar3 = 0xd;
        }
        else {
          if ((param_2 & 0xf8) != 0x38) {
            return -0x16;
          }
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 0xf;
      }
      pcVar4 = *(code **)(*(long *)(lVar5 + 0xb0) + 0x18);
      if (*(int *)(pcVar4 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1015e0);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(uVar3,param_3,param_4);
      uVar3 = _raw_spin_lock_irqsave(lVar5 + 0x38);
      iVar1 = pmic_arb_read_cmd_unlocked(param_1,uVar2,iVar1,param_3,param_4,param_5,param_6);
      _raw_spin_unlock_irqrestore(lVar5 + 0x38,uVar3);
    }
    else {
      _dev_err(*(undefined8 *)(lVar5 + 0xa8),
               "pmic-arb supports 1..%d bytes per trans, but:%zu requested",8,param_6);
      iVar1 = -0x16;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// pmic_arb_write_cmd @ 00101678 size=392
// signature: undefined pmic_arb_write_cmd(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_write_cmd(long param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                      undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  pcVar4 = *(code **)(*(long *)(lVar5 + 0xb0) + 0x10);
  if (*(int *)(pcVar4 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1016e4);
    (*pcVar4)();
  }
  iVar1 = (*pcVar4)(lVar5,param_3,param_4,0);
  if (-1 < iVar1) {
    if (((int)param_6 - 1U & 0xff) < 8) {
      if ((param_2 & 0xe0) == 0x40) {
        uVar3 = 0xe;
      }
      else if ((param_2 & 0xff) < 0x10) {
        uVar3 = 2;
      }
      else if ((param_2 & 0xf8) == 0x30) {
        uVar3 = 0;
      }
      else {
        if ((param_2 & 0xff) >> 7 == 0) {
          return -0x16;
        }
        uVar3 = 0x10;
      }
      pcVar4 = *(code **)(*(long *)(lVar5 + 0xb0) + 0x18);
      if (*(int *)(pcVar4 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101794);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(uVar3,param_3,param_4);
      uVar3 = _raw_spin_lock_irqsave(lVar5 + 0x38);
      iVar1 = pmic_arb_write_cmd_unlocked(param_1,uVar2,iVar1,param_3,param_4,param_5,param_6);
      _raw_spin_unlock_irqrestore(lVar5 + 0x38,uVar3);
    }
    else {
      _dev_err(*(undefined8 *)(lVar5 + 0xa8),
               "pmic-arb supports 1..%d bytes per trans, but:%zu requested",8,param_6);
      iVar1 = -0x16;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// pmic_arb_read_apid_map_v5 @ 00101800 size=336
// signature: undefined pmic_arb_read_apid_map_v5(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

void pmic_arb_read_apid_map_v5(long param_1)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar6;
  ulong uVar7;
  code *pcVar8;
  uint uVar9;
  ulong uVar10;
  byte *pbVar11;
  
  uVar4 = *(ushort *)(param_1 + 0x52);
  uVar10 = (ulong)uVar4;
  uVar1 = (uint)uVar4 + (uint)*(ushort *)(param_1 + 0x54);
  if ((uint)uVar4 < (uVar1 & 0xffff)) {
    pbVar11 = (byte *)(*(long *)(param_1 + 200) + uVar10 * 4 + 2);
    do {
      pcVar8 = *(code **)(*(long *)(param_1 + 0xb0) + 0x48);
      if (*(int *)(pcVar8 + -4) != -0xae94c33) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10188c);
        (*pcVar8)();
      }
      uVar7 = (*pcVar8)(uVar10);
      if (*(ulong *)(param_1 + 0x30) <= (uVar7 & 0xffffffff)) {
        return;
      }
      uVar6 = readl_relaxed(*(long *)(param_1 + 0x28) + (uVar7 & 0xffffffff));
      if (uVar6 != 0) {
        pcVar8 = *(code **)(*(long *)(param_1 + 0xb0) + 0x50);
        if (*(int *)(pcVar8 + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1018dc);
          (*pcVar8)();
        }
        (*pcVar8)(param_1,uVar10);
        bVar5 = readl_relaxed();
        bVar5 = bVar5 & 7;
        bVar3 = bVar5;
        if ((uVar6 & 0x1000000) == 0) {
          bVar3 = 0xff;
        }
        uVar7 = (ulong)(uVar6 >> 8) & 0xfff;
        *pbVar11 = bVar5;
        pbVar11[1] = bVar3;
        uVar9 = (uint)*(short *)(*(long *)(param_1 + 0xb8) + uVar7 * 2);
        if (((int)uVar9 < 0) && (bVar5 != *(byte *)(param_1 + 0x44))) {
          if (((uVar6 >> 0x18 & 1) != 0) &&
             (lVar2 = *(long *)(param_1 + 200) + (ulong)(uVar9 & 0x7fff) * 4,
             *(byte *)(lVar2 + 2) == *(byte *)(param_1 + 0x44))) {
            *(byte *)(lVar2 + 3) = bVar3;
          }
        }
        else {
          *(ushort *)(*(long *)(param_1 + 0xb8) + uVar7 * 2) = (ushort)uVar10 | 0x8000;
        }
        *(ushort *)(pbVar11 + -2) = (ushort)(uVar6 >> 8) & 0xfff;
        *(ushort *)(param_1 + 0xc0) = (ushort)uVar10;
      }
      uVar6 = (int)uVar10 + 1;
      uVar10 = (ulong)uVar6;
      pbVar11 = pbVar11 + 4;
    } while ((uVar6 & 0xffff) < (uVar1 & 0xffff));
  }
  return;
}



//------------------------------------------------------------
// pmic_arb_chained_irq @ 00101954 size=828
// signature: undefined pmic_arb_chained_irq(void)
// callers: []
//------------------------------------------------------------

void pmic_arb_chained_irq(long param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  code *pcVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  bool bVar17;
  long lVar18;
  uint uVar19;
  int local_80;
  
  lVar13 = *(long *)(param_1 + 8);
  lVar16 = *(long *)(param_1 + 0x48);
  lVar18 = *(long *)(lVar13 + 0xb0);
  uVar2 = *(ushort *)(lVar13 + 0x4e);
  uVar14 = (ulong)uVar2;
  uVar3 = *(ushort *)(lVar13 + 0x50);
  uVar4 = *(ushort *)(lVar13 + 0x52);
  uVar1 = *(undefined1 *)(lVar13 + 0x44);
  if (*(long *)(lVar16 + 0x48) == 0) {
    pcVar12 = *(code **)(lVar16 + 0x38);
    if (pcVar12 == (code *)0x0) {
      if (*(int *)(*(code **)(lVar16 + 0x30) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1019d8);
        (*pcVar12)();
      }
      (**(code **)(lVar16 + 0x30))(param_1 + 0x30);
      pcVar12 = *(code **)(lVar16 + 0x28);
      if (pcVar12 == (code *)0x0) goto LAB_00101a04;
    }
    if (*(int *)(pcVar12 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x101a00);
      (*pcVar12)();
    }
    (*pcVar12)(param_1 + 0x30);
  }
LAB_00101a04:
  if (uVar3 >> 5 < uVar2 >> 5) {
    local_80 = 0;
    bVar17 = false;
  }
  else {
    bVar17 = false;
    local_80 = 0;
    uVar19 = (uint)(uVar2 >> 5);
    do {
      if (*(int *)(*(code **)(lVar18 + 0x28) + -4) != -0x2184e93c) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x101b50);
        (*pcVar12)();
      }
      (**(code **)(lVar18 + 0x28))(lVar13,uVar1,uVar19 - (uVar4 >> 5));
      uVar9 = readl_relaxed();
      bVar7 = uVar9 != 0;
      if (uVar9 != 0) {
        do {
          while( true ) {
            uVar5 = (uVar9 & 0xaaaaaaaa) >> 1 | (uVar9 & 0x55555555) << 1;
            uVar5 = (uVar5 & 0xcccccccc) >> 2 | (uVar5 & 0x33333333) << 2;
            uVar5 = (uVar5 & 0xf0f0f0f0) >> 4 | (uVar5 & 0xf0f0f0f) << 4;
            uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
            uVar11 = (uint)LZCOUNT(uVar5 >> 0x10 | uVar5 << 0x10);
            uVar5 = uVar11 | uVar19 << 5;
            uVar9 = uVar9 & (1 << (ulong)(uVar11 & 0x1f) ^ 0xffffffffU);
            if (((int)(uint)uVar2 <= (int)uVar5) && ((int)uVar5 <= (int)(uint)uVar3)) break;
            if ((pmic_arb_chained_irq___already_done & 1) == 0) {
              pmic_arb_chained_irq___already_done = 1;
              __warn_printk("spurious spmi irq received for apid=%d\n",uVar5);
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(0x800,0x101c20);
              (*pcVar12)();
            }
            if (uVar9 == 0) goto LAB_00101b10;
          }
          if (*(int *)(*(code **)(lVar18 + 0x30) + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x101bcc);
            (*pcVar12)();
          }
          (**(code **)(lVar18 + 0x30))(lVar13,uVar5);
          uVar15 = readl_relaxed();
          if (((uVar15 & 1) != 0) && (iVar8 = periph_interrupt(lVar13,uVar5), iVar8 != 0)) {
            local_80 = local_80 + 1;
          }
        } while (uVar9 != 0);
      }
LAB_00101b10:
      bVar6 = uVar19 != uVar3 >> 5;
      bVar17 = (bool)(bVar7 | bVar17);
      uVar19 = uVar19 + 1;
    } while (bVar6);
  }
  if ((!bVar17) && (uVar2 <= uVar3)) {
    uVar15 = uVar14 << 2 | 3;
    do {
      if (*(char *)(*(long *)(lVar13 + 200) + uVar15) == *(char *)(lVar13 + 0x44)) {
        if (*(int *)(*(code **)(lVar18 + 0x38) + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
          pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x101a94);
          (*pcVar12)();
        }
        (**(code **)(lVar18 + 0x38))(lVar13,uVar14 & 0xffffffff);
        iVar8 = readl_relaxed();
        if (iVar8 != 0) {
          if (*(int *)(*(code **)(lVar18 + 0x30) + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x101ac4);
            (*pcVar12)();
          }
          (**(code **)(lVar18 + 0x30))(lVar13,uVar14 & 0xffffffff);
          uVar10 = readl_relaxed();
          if (((uVar10 & 1) != 0) &&
             (iVar8 = periph_interrupt(lVar13,uVar14 & 0xffffffff), iVar8 != 0)) {
            local_80 = local_80 + 1;
          }
        }
      }
      uVar14 = uVar14 + 1;
      uVar15 = uVar15 + 4;
    } while ((ulong)uVar3 + 1 != uVar14);
  }
  if (local_80 == 0) {
    handle_bad_irq(param_1);
    pcVar12 = *(code **)(lVar16 + 0x48);
  }
  else {
    pcVar12 = *(code **)(lVar16 + 0x48);
  }
  if (pcVar12 == (code *)0x0) {
    pcVar12 = *(code **)(lVar16 + 0x40);
  }
  if (*(int *)(pcVar12 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x101c5c);
    (*pcVar12)();
  }
  (*pcVar12)(param_1 + 0x30);
  return;
}



//------------------------------------------------------------
// spmi_pmic_arb_debugfs_init @ 00101c98 size=392
// signature: undefined spmi_pmic_arb_debugfs_init(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

void spmi_pmic_arb_debugfs_init(long param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 local_38;
  undefined2 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_38 = 0;
  scnprintf(&local_38,10,"spmi%u",*(undefined4 *)(*(long *)(param_1 + 0xa8) + 0x390));
  uVar2 = debugfs_create_dir(&local_38,0);
  if (uVar2 < 0xfffffffffffff001) {
    *(ulong *)(param_1 + 0xd8) = uVar2;
    uVar2 = debugfs_create_dir("address_map",uVar2);
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = debugfs_create_file_unsafe("spmi_addr",0x180,uVar2,param_1,&debug_spmi_addr_fops);
      if (uVar3 < 0xfffffffffffff001) {
        uVar3 = debugfs_create_file_unsafe
                          ("soc_addr_start",0x100,uVar2,param_1,&debug_soc_start_addr_fops);
        if (uVar3 < 0xfffffffffffff001) {
          uVar2 = debugfs_create_file_unsafe
                            ("soc_addr_end",0x100,uVar2,param_1,&debug_soc_end_addr_fops);
          if (uVar2 < 0xfffffffffffff001) goto LAB_00101df4;
          pcVar4 = "Could not create soc_addr_end debugfs file, rc=%ld\n";
        }
        else {
          pcVar4 = "Could not create soc_addr_start debugfs file, rc=%ld\n";
          uVar2 = uVar3;
        }
      }
      else {
        pcVar4 = "Could not create spmi_addr debugfs file, rc=%ld\n";
        uVar2 = uVar3;
      }
    }
    else {
      pcVar4 = "Could not create address_map debugfs directory, rc=%ld\n";
    }
    _dev_err(*(undefined8 *)(param_1 + 0xa8),pcVar4,uVar2);
    debugfs_remove(*(undefined8 *)(param_1 + 0xd8));
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0xa8),"Could not create %s debugfs directory, rc=%ld\n",
             &local_38);
  }
LAB_00101df4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_arb_ppid_to_apid_v1 @ 00101e24 size=320
// signature: undefined pmic_arb_ppid_to_apid_v1(void)
// callers: []
//------------------------------------------------------------

uint pmic_arb_ppid_to_apid_v1(long param_1,ushort param_2)

{
  ulong *puVar1;
  uint uVar2;
  ushort uVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  ulong uVar12;
  
  uVar9 = (ulong)param_2;
  uVar3 = *(ushort *)(*(long *)(param_1 + 0xb8) + uVar9 * 2);
  if ((short)uVar3 < 0) {
    uVar6 = uVar3 & 0x7fff;
  }
  else {
    uVar6 = 0;
    lVar10 = *(long *)(param_1 + 0x58);
    iVar11 = 0x10;
    do {
      uVar12 = (ulong)uVar6;
      uVar7 = 1L << (uVar12 & 0x3f);
      puVar1 = (ulong *)(param_1 + 0x60 + (ulong)(uVar6 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar8 = *puVar1;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = uVar8 | uVar7;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
      if ((uVar8 & uVar7) == 0) {
        uVar7 = readl_relaxed(*(long *)(param_1 + 0x20) + (ulong)(uVar6 * 4 + 0xb00));
        *(int *)(lVar10 + uVar12 * 4) = (int)uVar7;
      }
      else {
        uVar7 = (ulong)*(uint *)(lVar10 + uVar12 * 4);
      }
      uVar6 = (uint)uVar7;
      if ((param_2 >> (uVar6 >> 0x12 & 0xf) & 1) == 0) {
        if ((uVar6 >> 0x11 & 1) == 0) {
          uVar2 = uVar6 >> 9;
          uVar7 = (uVar7 & 0xffffffff) >> 9;
          uVar6 = uVar6 >> 9;
          *(ushort *)(*(long *)(param_1 + 0xb8) + uVar9 * 2) = (ushort)uVar2 & 0xff | 0x8000;
LAB_00101f50:
          *(ushort *)(*(long *)(param_1 + 200) + (uVar7 & 0xff) * 4) = param_2;
          return uVar6 & 0xff;
        }
        uVar6 = (uint)(uVar7 >> 9) & 0x7fffff;
      }
      else if ((uVar6 >> 8 & 1) == 0) {
        *(ushort *)(*(long *)(param_1 + 0xb8) + uVar9 * 2) = (ushort)uVar7 & 0xff | 0x8000;
        goto LAB_00101f50;
      }
      uVar6 = uVar6 & 0xff;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    uVar6 = 0xffffffed;
  }
  return uVar6;
}



//------------------------------------------------------------
// pmic_arb_offset_v1 @ 00101f78 size=16
// signature: undefined pmic_arb_offset_v1(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_offset_v1(long param_1)

{
  return (uint)*(byte *)(param_1 + 0x3c) * 0x80 + 0x800;
}



//------------------------------------------------------------
// pmic_arb_fmt_cmd_v1 @ 00101f8c size=20
// signature: undefined pmic_arb_fmt_cmd_v1(void)
// callers: []
//------------------------------------------------------------

uint pmic_arb_fmt_cmd_v1(int param_1,uint param_2,uint param_3,uint param_4)

{
  return param_1 << 0x1b | (param_2 & 0xf) << 0x14 | (param_3 & 0xffff) << 4 | param_4 & 7;
}



//------------------------------------------------------------
// pmic_arb_non_data_cmd_v1 @ 00101fa4 size=216
// signature: undefined pmic_arb_non_data_cmd_v1(void)
// callers: []
//------------------------------------------------------------

ulong pmic_arb_non_data_cmd_v1(long param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = *(long *)(param_1 + 0x98);
  pcVar3 = *(code **)(*(long *)(lVar4 + 0xb0) + 0x10);
  if (*(int *)(pcVar3 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102000);
    (*pcVar3)();
  }
  uVar1 = (*pcVar3)(lVar4,param_3,0,0);
  uVar5 = (ulong)uVar1;
  if (-1 < (int)uVar1) {
    uVar2 = _raw_spin_lock_irqsave(lVar4 + 0x38);
    writel_relaxed(param_2 << 0x1b | (param_3 & 0xf) << 0x14,*(long *)(lVar4 + 8) + uVar5);
    uVar5 = pmic_arb_wait_for_done(param_1,*(undefined8 *)(lVar4 + 8),param_3,0,0);
    uVar5 = uVar5 & 0xffffffff;
    _raw_spin_unlock_irqrestore(lVar4 + 0x38,uVar2);
  }
  return uVar5;
}



//------------------------------------------------------------
// pmic_arb_owner_acc_status_v1 @ 00102080 size=20
// signature: undefined pmic_arb_owner_acc_status_v1(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_owner_acc_status_v1(long param_1,ulong param_2,ushort param_3)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xff) * 0x20 + (ulong)param_3 * 4;
}



//------------------------------------------------------------
// pmic_arb_acc_enable_v1 @ 00102098 size=16
// signature: undefined pmic_arb_acc_enable_v1(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_acc_enable_v1(long param_1,ushort param_2)

{
  return *(long *)(param_1 + 0x18) + (ulong)param_2 * 4 + 0x200;
}



//------------------------------------------------------------
// pmic_arb_irq_status_v1 @ 001020ac size=16
// signature: undefined pmic_arb_irq_status_v1(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_status_v1(long param_1,ushort param_2)

{
  return *(long *)(param_1 + 0x18) + (ulong)param_2 * 4 + 0x600;
}



//------------------------------------------------------------
// pmic_arb_irq_clear_v1 @ 001020c0 size=16
// signature: undefined pmic_arb_irq_clear_v1(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_clear_v1(long param_1,ushort param_2)

{
  return *(long *)(param_1 + 0x18) + (ulong)param_2 * 4 + 0xa00;
}



//------------------------------------------------------------
// pmic_arb_apid_map_offset_v2 @ 001020d4 size=16
// signature: undefined pmic_arb_apid_map_offset_v2(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_apid_map_offset_v2(uint param_1)

{
  return (param_1 & 0xffff) * 4 + 0x800;
}



//------------------------------------------------------------
// pmic_arb_wr_addr_map_v1 @ 001020e8 size=36
// signature: undefined pmic_arb_wr_addr_map_v1(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_arb_wr_addr_map_v1(long param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x10) + (ulong)*(byte *)(param_1 + 0x3c) * 0x80;
  *param_4 = lVar1 + 0x800;
  param_4[1] = lVar1 + 0x87f;
  return 0;
}



//------------------------------------------------------------
// pmic_arb_wait_for_done @ 0010210c size=356
// signature: undefined pmic_arb_wait_for_done(void)
// callers: [pmic_arb_write_cmd_unlocked, qpnpint_irq_unmask, pmic_arb_non_data_cmd_v1, qpnpint_irq_domain_activate, qpnpint_irq_set_type, qpnpint_spmi_read, qpnpint_irq_ack, qpnpint_irq_mask, pmic_arb_read_cmd_unlocked]
//------------------------------------------------------------

undefined8
pmic_arb_wait_for_done(long param_1,long param_2,uint param_3,uint param_4,undefined4 param_5)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  
  pcVar4 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x10);
  if (*(int *)(pcVar4 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102164);
    (*pcVar4)();
  }
  uVar3 = (*pcVar4)(*(long *)(param_1 + 0x98),param_3,param_4,param_5);
  if (-1 < (int)uVar3) {
    iVar5 = -1000;
    do {
      uVar2 = readl_relaxed(param_2 + (ulong)((int)uVar3 + 8));
      if ((uVar2 & 1) != 0) {
        if ((uVar2 >> 2 & 1) != 0) {
          _dev_err(param_1,"%s: %#x %#x: transaction denied (%#x)\n","pmic_arb_wait_for_done",
                   param_3 & 0xff,param_4 & 0xffff,uVar2);
          return 0xffffffff;
        }
        if ((uVar2 >> 1 & 1) != 0) {
          _dev_err(param_1,"%s: %#x %#x: transaction failed (%#x)\n","pmic_arb_wait_for_done",
                   param_3 & 0xff,param_4 & 0xffff,uVar2);
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x102244);
          (*pcVar4)();
        }
        if ((uVar2 >> 3 & 1) == 0) {
          return 0;
        }
        _dev_err(param_1,"%s: %#x %#x: transaction dropped (%#x)\n","pmic_arb_wait_for_done",
                 param_3 & 0xff,param_4 & 0xffff,uVar2);
        return 0xfffffffb;
      }
      __const_udelay(0x10c7);
      bVar1 = iVar5 != -1;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    _dev_err(param_1,"%s: %#x %#x: timeout, status %#x\n","pmic_arb_wait_for_done",param_3 & 0xff,
             param_4 & 0xffff,uVar2);
    uVar3 = 0xffffff92;
  }
  return uVar3;
}



//------------------------------------------------------------
// writel_relaxed @ 00102274 size=132
// signature: undefined writel_relaxed(void)
// callers: [pmic_arb_write_cmd_unlocked, qpnpint_irq_unmask, pmic_arb_non_data_cmd_v1, qpnpint_irq_domain_activate, qpnpint_irq_set_type, qpnpint_spmi_read, periph_interrupt, qpnpint_irq_ack, qpnpint_irq_mask, pmic_arb_read_cmd_unlocked]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10228c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1022c8,uVar1);
  return;
}



//------------------------------------------------------------
// pmic_arb_ppid_to_apid_v2 @ 001022fc size=360
// signature: undefined pmic_arb_ppid_to_apid_v2(void)
// callers: [pmic_arb_wr_addr_map_v2, pmic_arb_offset_v2]
//------------------------------------------------------------

uint pmic_arb_ppid_to_apid_v2(long param_1,ulong param_2)

{
  uint uVar1;
  byte bVar2;
  ulong uVar3;
  uint uVar4;
  code *pcVar5;
  short sVar6;
  ulong uVar7;
  long lVar8;
  byte *pbVar9;
  
  sVar6 = *(short *)(*(long *)(param_1 + 0xb8) + (param_2 & 0xffff) * 2);
  if (sVar6 < 0) {
    uVar4 = (int)sVar6 & 0x7fff;
  }
  else {
    uVar7 = (ulong)*(ushort *)(param_1 + 0xc0);
    lVar8 = *(long *)(param_1 + 200);
    pcVar5 = *(code **)(*(long *)(param_1 + 0xb0) + 0x48);
    if (*(int *)(pcVar5 + -4) != -0xae94c33) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102358);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(uVar7);
    uVar3 = uVar3 & 0xffffffff;
    if (uVar3 < *(ulong *)(param_1 + 0x30)) {
      pbVar9 = (byte *)(lVar8 + uVar7 * 4 + 3);
      do {
        pcVar5 = *(code **)(*(long *)(param_1 + 0xb0) + 0x50);
        if (*(int *)(pcVar5 + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1023e4);
          (*pcVar5)();
        }
        (*pcVar5)(param_1,uVar7);
        bVar2 = readl_relaxed();
        *pbVar9 = bVar2 & 7;
        pbVar9[-1] = bVar2 & 7;
        uVar3 = readl_relaxed(*(long *)(param_1 + 0x28) + uVar3);
        if ((uint)uVar3 != 0) {
          uVar4 = (uint)uVar7 | 0xffff8000;
          uVar1 = (uint)uVar3 >> 8 & 0xfff;
          *(short *)(*(long *)(param_1 + 0xb8) + (uVar3 >> 8 & 0xfff) * 2) = (short)uVar4;
          *(short *)(pbVar9 + -3) = (short)uVar1;
          if (uVar1 == ((uint)param_2 & 0xffff)) {
            uVar7 = (ulong)uVar4;
            break;
          }
        }
        uVar7 = (ulong)((uint)uVar7 + 1);
        pcVar5 = *(code **)(*(long *)(param_1 + 0xb0) + 0x48);
        if (*(int *)(pcVar5 + -4) != -0xae94c33) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1023a4);
          (*pcVar5)();
        }
        uVar3 = (*pcVar5)(uVar7);
        uVar3 = uVar3 & 0xffffffff;
        pbVar9 = pbVar9 + 4;
      } while (uVar3 < *(ulong *)(param_1 + 0x30));
    }
    sVar6 = (short)uVar7;
    uVar4 = (uint)uVar7 & 0x7fff;
    *(short *)(param_1 + 0xc0) = (short)uVar4;
  }
  uVar1 = 0xffffffed;
  if (sVar6 < 0) {
    uVar1 = uVar4;
  }
  return uVar1;
}



//------------------------------------------------------------
// pmic_arb_offset_v2 @ 00102468 size=64
// signature: undefined pmic_arb_offset_v2(void)
// callers: []
//------------------------------------------------------------

ulong pmic_arb_offset_v2(long param_1,long param_2,int param_3)

{
  ulong uVar1;
  
  uVar1 = pmic_arb_ppid_to_apid_v2
                    (param_1,(param_2 << 0x20 | (ulong)(uint)(param_3 << 0x10)) >> 0x18 & 0xffffffff
                    );
  if (-1 < (int)(uint)uVar1) {
    uVar1 = (ulong)(((uint)uVar1 & 0xffff) * 0x8000 + (uint)*(byte *)(param_1 + 0x44) * 0x1000);
  }
  return uVar1;
}



//------------------------------------------------------------
// pmic_arb_fmt_cmd_v2 @ 001024ac size=16
// signature: undefined pmic_arb_fmt_cmd_v2(void)
// callers: []
//------------------------------------------------------------

uint pmic_arb_fmt_cmd_v2(int param_1,undefined8 param_2,uint param_3,uint param_4)

{
  return (param_3 & 0xff) << 4 | param_1 << 0x1b | param_4 & 7;
}



//------------------------------------------------------------
// pmic_arb_non_data_cmd_v2 @ 001024c0 size=8
// signature: undefined pmic_arb_non_data_cmd_v2(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_arb_non_data_cmd_v2(void)

{
  return 0xffffffa1;
}



//------------------------------------------------------------
// pmic_arb_owner_acc_status_v2 @ 001024cc size=24
// signature: undefined pmic_arb_owner_acc_status_v2(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_owner_acc_status_v2(long param_1,ulong param_2,ushort param_3)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xff) * 0x1000 + (ulong)param_3 * 4 + 0x100000;
}



//------------------------------------------------------------
// pmic_arb_acc_enable_v2 @ 001024e8 size=16
// signature: undefined pmic_arb_acc_enable_v2(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_acc_enable_v2(long param_1,ulong param_2)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xffff) * 0x1000;
}



//------------------------------------------------------------
// pmic_arb_irq_status_v2 @ 001024fc size=20
// signature: undefined pmic_arb_irq_status_v2(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_status_v2(long param_1,ulong param_2)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xffff) * 0x1000 + 4;
}



//------------------------------------------------------------
// pmic_arb_irq_clear_v2 @ 00102514 size=20
// signature: undefined pmic_arb_irq_clear_v2(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_clear_v2(long param_1,ulong param_2)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xffff) * 0x1000 + 8;
}



//------------------------------------------------------------
// pmic_arb_apid_owner_v2 @ 0010252c size=16
// signature: undefined pmic_arb_apid_owner_v2(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_apid_owner_v2(long param_1,ushort param_2)

{
  return *(long *)(param_1 + 0x20) + (ulong)param_2 * 4 + 0x700;
}



//------------------------------------------------------------
// pmic_arb_wr_addr_map_v2 @ 00102540 size=96
// signature: undefined pmic_arb_wr_addr_map_v2(void)
// callers: []
//------------------------------------------------------------

ulong pmic_arb_wr_addr_map_v2(long param_1,long param_2,int param_3,long *param_4)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = pmic_arb_ppid_to_apid_v2
                    (param_1,(param_2 << 0x20 | (ulong)(uint)(param_3 << 0x10)) >> 0x18 & 0xffffffff
                    );
  if ((-1 < (int)uVar2) &&
     (uVar2 = (uVar2 & 0xffff) * 0x8000 + (ulong)*(byte *)(param_1 + 0x44) * 0x1000, -1 < (int)uVar2
     )) {
    lVar1 = *(long *)(param_1 + 0x10) + uVar2;
    uVar2 = 0;
    *param_4 = lVar1;
    param_4[1] = lVar1 + 0xfff;
  }
  return uVar2;
}



//------------------------------------------------------------
// pmic_arb_owner_acc_status_v3 @ 001025a4 size=24
// signature: undefined pmic_arb_owner_acc_status_v3(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_owner_acc_status_v3(long param_1,ulong param_2,ushort param_3)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xff) * 0x1000 + (ulong)param_3 * 4 + 0x200000;
}



//------------------------------------------------------------
// pmic_arb_ppid_to_apid_v5 @ 001025c0 size=36
// signature: undefined pmic_arb_ppid_to_apid_v5(void)
// callers: []
//------------------------------------------------------------

uint pmic_arb_ppid_to_apid_v5(long param_1,ulong param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(*(long *)(param_1 + 0xb8) + (param_2 & 0xffff) * 2);
  uVar1 = 0xffffffed;
  if ((short)uVar2 < 0) {
    uVar1 = uVar2 & 0x7fff;
  }
  return uVar1;
}



//------------------------------------------------------------
// pmic_arb_offset_v5 @ 001025e8 size=176
// signature: undefined pmic_arb_offset_v5(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_offset_v5(long param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = *(ushort *)
           (*(long *)(param_1 + 0xb8) + (ulong)((param_2 & 0xff) << 8 | param_3 >> 8 & 0xff) * 2);
  uVar1 = uVar2 & 0x7fff;
  iVar3 = -0x13;
  if ((short)uVar2 < 0) {
    if (param_4 == 0) {
      if (*(char *)(*(long *)(param_1 + 200) + (ulong)uVar1 * 4 + 2) == *(char *)(param_1 + 0x44)) {
        iVar3 = uVar1 << 0x10;
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + 0xa8),"disallowed SPMI write to sid=%u, addr=0x%04X\n",
                 param_2 & 0xff,param_3 & 0xffff);
        iVar3 = -1;
      }
    }
    else if (param_4 == 1) {
      iVar3 = uVar1 * 0x80 + (uint)*(byte *)(param_1 + 0x44) * 0x10000;
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// pmic_arb_owner_acc_status_v5 @ 0010269c size=20
// signature: undefined pmic_arb_owner_acc_status_v5(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_owner_acc_status_v5(long param_1,ulong param_2,ushort param_3)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xff) * 0x10000 + (ulong)param_3 * 4;
}



//------------------------------------------------------------
// pmic_arb_acc_enable_v5 @ 001026b4 size=20
// signature: undefined pmic_arb_acc_enable_v5(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_acc_enable_v5(long param_1,int param_2)

{
  return *(long *)(param_1 + 8) + (long)(param_2 << 0x10) + 0x100;
}



//------------------------------------------------------------
// pmic_arb_irq_status_v5 @ 001026cc size=20
// signature: undefined pmic_arb_irq_status_v5(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_status_v5(long param_1,int param_2)

{
  return *(long *)(param_1 + 8) + (long)(param_2 << 0x10) + 0x104;
}



//------------------------------------------------------------
// pmic_arb_irq_clear_v5 @ 001026e4 size=20
// signature: undefined pmic_arb_irq_clear_v5(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_clear_v5(long param_1,int param_2)

{
  return *(long *)(param_1 + 8) + (long)(param_2 << 0x10) + 0x108;
}



//------------------------------------------------------------
// pmic_arb_apid_map_offset_v5 @ 001026fc size=16
// signature: undefined pmic_arb_apid_map_offset_v5(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_apid_map_offset_v5(uint param_1)

{
  return (param_1 & 0xffff) * 4 + 0x900;
}



//------------------------------------------------------------
// pmic_arb_wr_addr_map_v5 @ 00102710 size=160
// signature: undefined pmic_arb_wr_addr_map_v5(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_arb_wr_addr_map_v5(long param_1,uint param_2,uint param_3,long *param_4)

{
  long lVar1;
  uint uVar2;
  ushort uVar3;
  undefined8 uVar4;
  
  uVar3 = *(ushort *)
           (*(long *)(param_1 + 0xb8) + (ulong)((param_2 & 0xff) << 8 | param_3 >> 8 & 0xff) * 2);
  uVar2 = uVar3 & 0x7fff;
  uVar4 = 0xffffffed;
  if ((short)uVar3 < 0) {
    if (*(char *)(*(long *)(param_1 + 200) + (ulong)uVar2 * 4 + 2) == *(char *)(param_1 + 0x44)) {
      uVar4 = 0;
      lVar1 = *(long *)(param_1 + 0x10) + (ulong)(uVar2 << 0x10);
      *param_4 = lVar1;
      param_4[1] = lVar1 + 0xffff;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0xa8),"disallowed SPMI write to sid=%u, addr=0x%04X\n",
               param_2 & 0xff,param_3 & 0xffff);
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// pmic_arb_offset_v7 @ 001027b4 size=204
// signature: undefined pmic_arb_offset_v7(void)
// callers: []
//------------------------------------------------------------

ulong pmic_arb_offset_v7(long param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(*(long *)(param_1 + 0xb0) + 8);
  if (*(int *)(pcVar3 + -4) != 0x7089cf1b) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102800);
    (*pcVar3)();
  }
  uVar2 = (*pcVar3)(param_1,(param_2 & 0xff) << 8 | param_3 >> 8 & 0xff);
  uVar1 = (uint)uVar2;
  if (-1 < (int)uVar1) {
    if (param_4 == 0) {
      if (*(char *)(*(long *)(param_1 + 200) + (ulong)(uVar1 & 0xffff) * 4 + 2) ==
          *(char *)(param_1 + 0x44)) {
        uVar2 = (ulong)((uVar1 & 0xffff) << 0xc);
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + 0xa8),"disallowed SPMI write to sid=%u, addr=0x%04X\n",
                 param_2 & 0xff,param_3 & 0xffff);
        uVar2 = 0xffffffff;
      }
    }
    else if (param_4 == 1) {
      uVar2 = (ulong)((uVar1 & 0xffff) * 0x20 + (uint)*(byte *)(param_1 + 0x44) * 0x8000);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// pmic_arb_owner_acc_status_v7 @ 00102884 size=20
// signature: undefined pmic_arb_owner_acc_status_v7(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_owner_acc_status_v7(long param_1,ulong param_2,ushort param_3)

{
  return *(long *)(param_1 + 0x18) + (param_2 & 0xff) * 0x1000 + (ulong)param_3 * 4;
}



//------------------------------------------------------------
// pmic_arb_acc_enable_v7 @ 0010289c size=20
// signature: undefined pmic_arb_acc_enable_v7(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_acc_enable_v7(long param_1,ulong param_2)

{
  return *(long *)(param_1 + 8) + (param_2 & 0xffff) * 0x1000 + 0x100;
}



//------------------------------------------------------------
// pmic_arb_irq_status_v7 @ 001028b4 size=20
// signature: undefined pmic_arb_irq_status_v7(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_status_v7(long param_1,ulong param_2)

{
  return *(long *)(param_1 + 8) + (param_2 & 0xffff) * 0x1000 + 0x104;
}



//------------------------------------------------------------
// pmic_arb_irq_clear_v7 @ 001028cc size=20
// signature: undefined pmic_arb_irq_clear_v7(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_irq_clear_v7(long param_1,ulong param_2)

{
  return *(long *)(param_1 + 8) + (param_2 & 0xffff) * 0x1000 + 0x108;
}



//------------------------------------------------------------
// pmic_arb_apid_map_offset_v7 @ 001028e4 size=16
// signature: undefined pmic_arb_apid_map_offset_v7(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_apid_map_offset_v7(uint param_1)

{
  return (param_1 & 0xffff) * 4 + 0x2000;
}



//------------------------------------------------------------
// pmic_arb_apid_owner_v7 @ 001028f8 size=28
// signature: undefined pmic_arb_apid_owner_v7(void)
// callers: []
//------------------------------------------------------------

long pmic_arb_apid_owner_v7(long param_1,uint param_2)

{
  return *(long *)(param_1 + 0x20) +
         (long)(int)(((param_2 & 0xffff) - (uint)*(ushort *)(param_1 + 0x52)) * 4);
}



//------------------------------------------------------------
// pmic_arb_wr_addr_map_v7 @ 00102918 size=188
// signature: undefined pmic_arb_wr_addr_map_v7(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_arb_wr_addr_map_v7(long param_1,uint param_2,uint param_3,long *param_4)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(*(long *)(param_1 + 0xb0) + 8);
  if (*(int *)(pcVar4 + -4) != 0x7089cf1b) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102964);
    (*pcVar4)();
  }
  uVar3 = (*pcVar4)(param_1,(param_2 & 0xff) << 8 | param_3 >> 8 & 0xff);
  uVar2 = (uint)uVar3;
  if (-1 < (int)uVar2) {
    if (*(char *)(*(long *)(param_1 + 200) + (ulong)(uVar2 & 0xffff) * 4 + 2) ==
        *(char *)(param_1 + 0x44)) {
      uVar3 = 0;
      lVar1 = *(long *)(param_1 + 0x10) + (ulong)((uVar2 & 0xffff) << 0xc);
      *param_4 = lVar1;
      param_4[1] = lVar1 + 0xfff;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0xa8),"disallowed SPMI write to sid=%u, addr=0x%04X\n",
               param_2 & 0xff,param_3 & 0xffff);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// pmic_arb_read_cmd_unlocked @ 001029d4 size=288
// signature: undefined pmic_arb_read_cmd_unlocked(void)
// callers: [pmic_arb_read_cmd]
//------------------------------------------------------------

int pmic_arb_read_cmd_unlocked
              (long param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
              void *param_6,int param_7)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  undefined4 local_5c;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  plVar5 = *(long **)(param_1 + 0x98);
  writel_relaxed(param_2,*plVar5 + (ulong)param_3);
  iVar3 = pmic_arb_wait_for_done(param_1,*plVar5,param_4,param_5,1);
  if (iVar3 == 0) {
    uVar1 = param_7 - 1U & 0xff;
    uVar4 = uVar1;
    if (2 < uVar1) {
      uVar4 = 3;
    }
    local_5c = *(undefined4 *)(*plVar5 + (ulong)(param_3 + 0x18));
    memcpy(param_6,&local_5c,(ulong)(uVar4 + 1));
    if (3 < uVar1) {
      local_5c = *(undefined4 *)(*plVar5 + (ulong)(param_3 + 0x1c));
      memcpy((void *)((long)param_6 + 4),&local_5c,((ulong)(param_7 - 1) & 3) + 1);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// pmic_arb_write_cmd_unlocked @ 00102af4 size=296
// signature: undefined pmic_arb_write_cmd_unlocked(void)
// callers: [pmic_arb_write_cmd]
//------------------------------------------------------------

void pmic_arb_write_cmd_unlocked
               (long param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
               void *param_6,int param_7)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined4 local_6c;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  uVar1 = param_7 - 1U & 0xff;
  uVar2 = uVar1;
  if (2 < uVar1) {
    uVar2 = 3;
  }
  lVar3 = *(long *)(param_1 + 0x98);
  local_6c = 0;
  memcpy(&local_6c,param_6,(ulong)(uVar2 + 1));
  *(undefined4 *)(*(long *)(lVar3 + 8) + (ulong)(param_3 + 0x10)) = local_6c;
  if (3 < uVar1) {
    local_6c = 0;
    memcpy(&local_6c,(void *)((long)param_6 + 4),((ulong)(param_7 - 1) & 3) + 1);
    *(undefined4 *)(*(long *)(lVar3 + 8) + (ulong)(param_3 + 0x14)) = local_6c;
  }
  writel_relaxed(param_2,*(long *)(lVar3 + 8) + (ulong)param_3);
  pmic_arb_wait_for_done(param_1,*(undefined8 *)(lVar3 + 8),param_4,param_5,0);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qpnpint_irq_domain_alloc @ 00102c20 size=248
// signature: undefined qpnpint_irq_domain_alloc(void)
// callers: []
//------------------------------------------------------------

void qpnpint_irq_domain_alloc(long param_1,int param_2,int param_3,undefined8 param_4)

{
  undefined *puVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  uint local_64;
  long local_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x20);
  local_60 = 0;
  local_64 = 0;
  uVar3 = qpnpint_irq_domain_translate(param_1,param_4,&local_60,&local_64);
  lVar2 = local_60;
  if ((int)uVar3 == 0) {
    if (param_3 != 0) {
      iVar5 = 0;
      puVar1 = &handle_level_irq;
      if ((local_64 & 3) != 0) {
        puVar1 = &handle_edge_irq;
      }
      do {
        irq_domain_set_info(param_1,param_2 + iVar5,lVar2 + iVar5,&pmic_arb_irqchip,uVar4,puVar1,0,0
                           );
        iVar5 = iVar5 + 1;
      } while (param_3 != iVar5);
    }
    uVar3 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qpnpint_irq_domain_activate @ 00102d1c size=1056
// signature: undefined qpnpint_irq_domain_activate(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnpint_irq_domain_activate(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  
  lVar13 = *(long *)(param_2 + 0x30);
  uVar12 = *(ulong *)(param_2 + 8);
  if (*(char *)(*(long *)(lVar13 + 200) + (uVar12 & 0x3ff) * 4 + 3) != *(char *)(lVar13 + 0x44)) {
    _dev_err(*(undefined8 *)(lVar13 + 0xa8),
             "failed to xlate sid = %#x, periph = %#x, irq = %u: ee=%u but owner=%u\n",
             uVar12 >> 0x1c & 0xf,(uint)uVar12 >> 0x14 & 0xff,(uint)uVar12 >> 0x10 & 7);
    return 0xffffffed;
  }
  if (*(char *)(lVar13 + 0x4c) != '\x16') {
    lVar8 = *(long *)(lVar13 + 0xa8);
    uVar9 = uVar12 >> 0x1c & 0xf;
    lVar10 = *(long *)(lVar8 + 0x98);
    uVar1 = (uint)(uVar12 >> 0xc) & 0xffffff00 | 0x1a;
    pcVar7 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x10);
    if (*(int *)(pcVar7 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102dbc);
      (*pcVar7)();
    }
    uVar2 = (*pcVar7)(lVar10,uVar9,uVar1,0);
    if (-1 < (int)uVar2) {
      pcVar7 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x18);
      if (*(int *)(pcVar7 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102df8);
        (*pcVar7)();
      }
      uVar3 = (*pcVar7)(0,uVar9,uVar1,0);
      uVar6 = _raw_spin_lock_irqsave(lVar10 + 0x38);
      lVar11 = *(long *)(lVar8 + 0x98);
      *(uint *)(*(long *)(lVar11 + 8) + (ulong)(uVar2 + 0x10)) = (uint)*(byte *)(lVar13 + 0x4c);
      writel_relaxed(uVar3,*(long *)(lVar11 + 8) + (ulong)uVar2);
      iVar4 = pmic_arb_wait_for_done(lVar8,*(undefined8 *)(lVar11 + 8),uVar9,uVar1,0);
      _raw_spin_unlock_irqrestore(lVar10 + 0x38,uVar6);
      if (iVar4 == 0) goto LAB_00102e7c;
    }
    iVar4 = ___ratelimit(qpnpint_spmi_write__rs,"qpnpint_spmi_write");
    if (iVar4 != 0) {
      _dev_err(*(undefined8 *)(lVar13 + 0xa8),"failed irqchip transaction on %x\n",
               *(undefined4 *)(param_2 + 4));
    }
  }
LAB_00102e7c:
  lVar10 = *(long *)(param_2 + 0x30);
  lVar13 = *(long *)(lVar10 + 0xa8);
  uVar9 = *(ulong *)(param_2 + 8) >> 0x1c & 0xf;
  uVar1 = (uint)(*(ulong *)(param_2 + 8) >> 0xc) & 0xffffff00 | 0x16;
  lVar8 = *(long *)(lVar13 + 0x98);
  pcVar7 = *(code **)(*(long *)(lVar8 + 0xb0) + 0x10);
  if (*(int *)(pcVar7 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102edc);
    (*pcVar7)();
  }
  uVar2 = (*pcVar7)(lVar8,uVar9,uVar1,0);
  uVar3 = (undefined4)(1L << (uVar12 >> 0x10 & 7));
  if (-1 < (int)uVar2) {
    pcVar7 = *(code **)(*(long *)(lVar8 + 0xb0) + 0x18);
    if (*(int *)(pcVar7 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102f18);
      (*pcVar7)();
    }
    uVar5 = (*pcVar7)(0,uVar9,uVar1,0);
    uVar6 = _raw_spin_lock_irqsave(lVar8 + 0x38);
    lVar11 = *(long *)(lVar13 + 0x98);
    *(undefined4 *)(*(long *)(lVar11 + 8) + (ulong)(uVar2 + 0x10)) = uVar3;
    writel_relaxed(uVar5,*(long *)(lVar11 + 8) + (ulong)uVar2);
    iVar4 = pmic_arb_wait_for_done(lVar13,*(undefined8 *)(lVar11 + 8),uVar9,uVar1,0);
    _raw_spin_unlock_irqrestore(lVar8 + 0x38,uVar6);
    if (iVar4 == 0) goto LAB_00102f9c;
  }
  iVar4 = ___ratelimit(qpnpint_spmi_write__rs,"qpnpint_spmi_write");
  if (iVar4 != 0) {
    _dev_err(*(undefined8 *)(lVar10 + 0xa8),"failed irqchip transaction on %x\n",
             *(undefined4 *)(param_2 + 4));
  }
LAB_00102f9c:
  lVar10 = *(long *)(param_2 + 0x30);
  lVar13 = *(long *)(lVar10 + 0xa8);
  uVar12 = *(ulong *)(param_2 + 8) >> 0x1c & 0xf;
  uVar1 = (uint)(*(ulong *)(param_2 + 8) >> 0xc) & 0xffffff00 | 0x14;
  lVar8 = *(long *)(lVar13 + 0x98);
  pcVar7 = *(code **)(*(long *)(lVar8 + 0xb0) + 0x10);
  if (*(int *)(pcVar7 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102fec);
    (*pcVar7)();
  }
  uVar2 = (*pcVar7)(lVar8,uVar12,uVar1,0);
  if (-1 < (int)uVar2) {
    pcVar7 = *(code **)(*(long *)(lVar8 + 0xb0) + 0x18);
    if (*(int *)(pcVar7 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103028);
      (*pcVar7)();
    }
    uVar5 = (*pcVar7)(0,uVar12,uVar1,0);
    uVar6 = _raw_spin_lock_irqsave(lVar8 + 0x38);
    lVar11 = *(long *)(lVar13 + 0x98);
    *(undefined4 *)(*(long *)(lVar11 + 8) + (ulong)(uVar2 + 0x10)) = uVar3;
    writel_relaxed(uVar5,*(long *)(lVar11 + 8) + (ulong)uVar2);
    iVar4 = pmic_arb_wait_for_done(lVar13,*(undefined8 *)(lVar11 + 8),uVar12,uVar1,0);
    _raw_spin_unlock_irqrestore(lVar8 + 0x38,uVar6);
    if (iVar4 == 0) {
      return 0;
    }
  }
  uVar6 = ___ratelimit(qpnpint_spmi_write__rs,"qpnpint_spmi_write");
  if ((int)uVar6 == 0) {
    return uVar6;
  }
  _dev_err(*(undefined8 *)(lVar10 + 0xa8),"failed irqchip transaction on %x\n",
           *(undefined4 *)(param_2 + 4));
  return 0;
}



//------------------------------------------------------------
// qpnpint_irq_domain_translate @ 00103140 size=348
// signature: undefined qpnpint_irq_domain_translate(void)
// callers: [qpnpint_irq_domain_alloc]
//------------------------------------------------------------

ulong qpnpint_irq_domain_translate(long param_1,long param_2,ulong *param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  
  lVar2 = 0;
  uVar4 = *(ulong *)(param_1 + 0x30);
  lVar6 = *(long *)(param_1 + 0x20);
  if (((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) &&
     (lVar2 = uVar4 - 0x18, *(undefined **)(uVar4 + 8) != &of_fwnode_ops)) {
    lVar2 = 0;
  }
  if (((lVar2 == *(long *)(*(long *)(lVar6 + 0xa8) + 0x2e8)) && (*(int *)(param_2 + 8) == 4)) &&
     ((*(uint *)(param_2 + 0xc) < 0x10 &&
      ((*(uint *)(param_2 + 0x10) < 0x100 && (*(uint *)(param_2 + 0x14) < 8)))))) {
    pcVar3 = *(code **)(*(long *)(lVar6 + 0xb0) + 8);
    if (*(int *)(pcVar3 + -4) != 0x7089cf1b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10321c);
      (*pcVar3)();
    }
    uVar4 = (*pcVar3)(lVar6,*(uint *)(param_2 + 0x10) | *(uint *)(param_2 + 0xc) << 8);
    uVar5 = uVar4 & 0xffffffff;
    if ((int)(uint)uVar4 < 0) {
      _dev_err(*(undefined8 *)(lVar6 + 0xa8),
               "failed to xlate sid = %#x, periph = %#x, irq = %u rc = %d\n",
               *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
               *(undefined4 *)(param_2 + 0x14),uVar5);
    }
    else {
      uVar1 = (uint)uVar4 & 0xffff;
      if (*(ushort *)(lVar6 + 0x50) < uVar1) {
        *(short *)(lVar6 + 0x50) = (short)uVar5;
      }
      if (uVar1 < *(ushort *)(lVar6 + 0x4e)) {
        *(short *)(lVar6 + 0x4e) = (short)uVar5;
      }
      uVar5 = 0;
      *param_3 = (ulong)(uint)(*(int *)(param_2 + 0xc) << 0x1c) |
                 ((ulong)*(uint *)(param_2 + 0x10) & 0xff) << 0x14 |
                 ((ulong)*(uint *)(param_2 + 0x14) & 7) << 0x10 | uVar4 & 0x3ff;
      *param_4 = *(uint *)(param_2 + 0x18) & 0xf;
    }
  }
  else {
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// qpnpint_irq_ack @ 001032a0 size=448
// signature: undefined qpnpint_irq_ack(void)
// callers: []
//------------------------------------------------------------

void qpnpint_irq_ack(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  code *pcVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  
  uVar8 = 1L << (*(ulong *)(param_1 + 8) >> 0x10 & 7);
  pcVar6 = *(code **)(*(long *)(*(long *)(param_1 + 0x30) + 0xb0) + 0x40);
  if (*(int *)(pcVar6 + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103300);
    (*pcVar6)();
  }
  uVar5 = (*pcVar6)(*(long *)(param_1 + 0x30),(uint)*(ulong *)(param_1 + 8) & 0x3ff);
  writel_relaxed(uVar8 & 0xffffffff,uVar5);
  lVar7 = *(long *)(param_1 + 0x30);
  lVar9 = *(long *)(lVar7 + 0xa8);
  lVar11 = *(long *)(lVar9 + 0x98);
  uVar10 = *(ulong *)(param_1 + 8) >> 0x1c & 0xf;
  uVar1 = (uint)(*(ulong *)(param_1 + 8) >> 0xc) & 0xffffff00 | 0x14;
  pcVar6 = *(code **)(*(long *)(lVar11 + 0xb0) + 0x10);
  if (*(int *)(pcVar6 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103364);
    (*pcVar6)();
  }
  uVar2 = (*pcVar6)(lVar11,uVar10,uVar1,0);
  if (-1 < (int)uVar2) {
    pcVar6 = *(code **)(*(long *)(lVar11 + 0xb0) + 0x18);
    if (*(int *)(pcVar6 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1033a0);
      (*pcVar6)();
    }
    uVar3 = (*pcVar6)(0,uVar10,uVar1,0);
    uVar5 = _raw_spin_lock_irqsave(lVar11 + 0x38);
    lVar12 = *(long *)(lVar9 + 0x98);
    *(int *)(*(long *)(lVar12 + 8) + (ulong)(uVar2 + 0x10)) = (int)uVar8;
    writel_relaxed(uVar3,*(long *)(lVar12 + 8) + (ulong)uVar2);
    iVar4 = pmic_arb_wait_for_done(lVar9,*(undefined8 *)(lVar12 + 8),uVar10,uVar1,0);
    _raw_spin_unlock_irqrestore(lVar11 + 0x38,uVar5);
    if (iVar4 == 0) {
      return;
    }
  }
  iVar4 = ___ratelimit(qpnpint_spmi_write__rs,"qpnpint_spmi_write");
  if (iVar4 != 0) {
    _dev_err(*(undefined8 *)(lVar7 + 0xa8),"failed irqchip transaction on %x\n",
             *(undefined4 *)(param_1 + 4));
  }
  return;
}



//------------------------------------------------------------
// qpnpint_irq_mask @ 00103464 size=388
// signature: undefined qpnpint_irq_mask(void)
// callers: []
//------------------------------------------------------------

void qpnpint_irq_mask(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  
  lVar7 = *(long *)(param_1 + 0x30);
  uVar11 = *(ulong *)(param_1 + 8);
  lVar8 = *(long *)(lVar7 + 0xa8);
  uVar9 = uVar11 >> 0x1c & 0xf;
  uVar1 = (uint)(uVar11 >> 0xc) & 0xffffff00 | 0x16;
  lVar10 = *(long *)(lVar8 + 0x98);
  pcVar6 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x10);
  if (*(int *)(pcVar6 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1034e0);
    (*pcVar6)();
  }
  uVar2 = (*pcVar6)(lVar10,uVar9,uVar1,0);
  if (-1 < (int)uVar2) {
    pcVar6 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x18);
    if (*(int *)(pcVar6 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103528);
      (*pcVar6)();
    }
    uVar3 = (*pcVar6)(0,uVar9,uVar1,0);
    uVar5 = _raw_spin_lock_irqsave(lVar10 + 0x38);
    lVar12 = *(long *)(lVar8 + 0x98);
    *(int *)(*(long *)(lVar12 + 8) + (ulong)(uVar2 + 0x10)) = 1 << (uVar11 >> 0x10 & 7);
    writel_relaxed(uVar3,*(long *)(lVar12 + 8) + (ulong)uVar2);
    iVar4 = pmic_arb_wait_for_done(lVar8,*(undefined8 *)(lVar12 + 8),uVar9,uVar1,0);
    _raw_spin_unlock_irqrestore(lVar10 + 0x38,uVar5);
    if (iVar4 == 0) {
      return;
    }
  }
  iVar4 = ___ratelimit(qpnpint_spmi_write__rs,"qpnpint_spmi_write");
  if (iVar4 != 0) {
    _dev_err(*(undefined8 *)(lVar7 + 0xa8),"failed irqchip transaction on %x\n",
             *(undefined4 *)(param_1 + 4));
  }
  return;
}



//------------------------------------------------------------
// qpnpint_irq_unmask @ 001035ec size=520
// signature: undefined qpnpint_irq_unmask(void)
// callers: []
//------------------------------------------------------------

void qpnpint_irq_unmask(long param_1)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined2 local_6c;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_6c = 0;
  uVar7 = *(ulong *)(param_1 + 8);
  pcVar8 = *(code **)(*(long *)(*(long *)(param_1 + 0x30) + 0xb0) + 0x30);
  if (*(int *)(pcVar8 + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103654);
    (*pcVar8)();
  }
  uVar6 = (*pcVar8)(*(long *)(param_1 + 0x30),(uint)uVar7 & 0x3ff);
  writel_relaxed(1,uVar6);
  qpnpint_spmi_read(param_1,0x15,&local_6c);
  uVar7 = 1L << (uVar7 >> 0x10 & 7);
  if ((uVar7 & (byte)local_6c) == 0) {
    lVar11 = *(long *)(param_1 + 0x30);
    uVar2 = (undefined1)uVar7;
    lVar9 = *(long *)(lVar11 + 0xa8);
    local_6c = CONCAT11(uVar2,uVar2);
    uVar7 = *(ulong *)(param_1 + 8) >> 0x1c & 0xf;
    uVar1 = (uint)(*(ulong *)(param_1 + 8) >> 0xc) & 0xffffff00 | 0x14;
    lVar10 = *(long *)(lVar9 + 0x98);
    pcVar8 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x10);
    if (*(int *)(pcVar8 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x1036e0);
      (*pcVar8)();
    }
    uVar3 = (*pcVar8)(lVar10,uVar7,uVar1,0);
    if (-1 < (int)uVar3) {
      pcVar8 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x18);
      if (*(int *)(pcVar8 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10371c);
        (*pcVar8)();
      }
      uVar4 = (*pcVar8)(0,uVar7,uVar1,1);
      uVar6 = _raw_spin_lock_irqsave(lVar10 + 0x38);
      lVar12 = *(long *)(lVar9 + 0x98);
      *(uint *)(*(long *)(lVar12 + 8) + (ulong)(uVar3 + 0x10)) = (uint)local_6c;
      writel_relaxed(uVar4,*(long *)(lVar12 + 8) + (ulong)uVar3);
      iVar5 = pmic_arb_wait_for_done(lVar9,*(undefined8 *)(lVar12 + 8),uVar7,uVar1,0);
      _raw_spin_unlock_irqrestore(lVar10 + 0x38,uVar6);
      if (iVar5 == 0) goto LAB_001037a0;
    }
    iVar5 = ___ratelimit(qpnpint_spmi_write__rs,"qpnpint_spmi_write");
    if (iVar5 != 0) {
      _dev_err(*(undefined8 *)(lVar11 + 0xa8),"failed irqchip transaction on %x\n",
               *(undefined4 *)(param_1 + 4));
    }
  }
LAB_001037a0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qpnpint_irq_set_type @ 001037f8 size=788
// signature: undefined qpnpint_irq_set_type(void)
// callers: []
//------------------------------------------------------------

ulong qpnpint_irq_set_type(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  ulong uVar11;
  code *pcVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  undefined *puVar19;
  long *plVar20;
  uint local_64;
  
  uVar11 = *(ulong *)(param_1 + 8);
  uVar8 = 1 << (uVar11 >> 0x10 & 7);
  if ((param_2 & 3) == 0) {
    if (((param_2 ^ 0xffffffff) & 0xc) == 0) {
      return 0xffffffea;
    }
    uVar18 = uVar8;
    if ((param_2 & 4) != 0) {
      uVar18 = 0;
    }
    puVar19 = &handle_level_irq;
    uVar2 = (int)(param_2 << 0x1d) >> 0x1f;
    local_64 = 0;
  }
  else {
    uVar2 = -(param_2 & 1);
    uVar18 = uVar8 & (int)(param_2 << 0x1e) >> 0x1f;
    puVar19 = &handle_edge_irq;
    local_64 = uVar8;
  }
  lVar13 = *(long *)(param_1 + 0x30);
  uVar16 = uVar11 >> 0x1c & 0xf;
  lVar14 = *(long *)(lVar13 + 0xa8);
  lVar17 = *(long *)(lVar14 + 0x98);
  uVar1 = (uint)(uVar11 >> 0xc) & 0xffffff00 | 0x11;
  pcVar12 = *(code **)(*(long *)(lVar17 + 0xb0) + 0x10);
  if (*(int *)(pcVar12 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1038d8);
    (*pcVar12)();
  }
  uVar3 = (*pcVar12)(lVar17,uVar16,uVar1,1);
  uVar11 = (ulong)uVar3;
  if (-1 < (int)uVar3) {
    pcVar12 = *(code **)(*(long *)(lVar17 + 0xb0) + 0x18);
    if (*(int *)(pcVar12 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x103918);
      (*pcVar12)();
    }
    uVar4 = (*pcVar12)(1,uVar16,uVar1,2);
    pcVar12 = *(code **)(*(long *)(lVar17 + 0xb0) + 0x10);
    if (*(int *)(pcVar12 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x103950);
      (*pcVar12)();
    }
    uVar5 = (*pcVar12)(lVar17,uVar16,uVar1,0);
    uVar11 = (ulong)uVar5;
    if (-1 < (int)uVar5) {
      pcVar12 = *(code **)(*(long *)(lVar17 + 0xb0) + 0x18);
      if (*(int *)(pcVar12 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x103990);
        (*pcVar12)();
      }
      uVar6 = (*pcVar12)(0,uVar16,uVar1,2);
      lVar17 = lVar17 + 0x38;
      uVar10 = _raw_spin_lock_irqsave(lVar17);
      plVar20 = *(long **)(lVar14 + 0x98);
      writel_relaxed(uVar4,*plVar20 + (ulong)uVar3);
      uVar7 = pmic_arb_wait_for_done(lVar14,*plVar20,uVar16,uVar1,1);
      if (uVar7 == 0) {
        uVar3 = *(uint *)(*plVar20 + (ulong)(uVar3 + 0x18));
        lVar15 = *(long *)(lVar14 + 0x98);
        *(uint *)(*(long *)(lVar15 + 8) + (ulong)(uVar5 + 0x10)) =
             ((uVar3 >> 8 & (uVar8 ^ 0xffffffff) | uVar2 & uVar8 & uVar8) & 0xff) << 8 |
             ((uVar3 >> 0x10 & (uVar8 ^ 0xffffffff) | uVar18 & uVar8) & 0xff) << 0x10 |
             (uVar3 & (uVar8 ^ 0xffffffff) | local_64 & uVar8) & 0xff;
        writel_relaxed(uVar6,*(long *)(lVar15 + 8) + (ulong)uVar5);
        uVar8 = pmic_arb_wait_for_done(lVar14,*(undefined8 *)(lVar15 + 8),uVar16,uVar1,0);
        uVar11 = (ulong)uVar8;
        _raw_spin_unlock_irqrestore(lVar17,uVar10);
        if (uVar8 == 0) goto LAB_00103abc;
      }
      else {
        uVar11 = (ulong)uVar7;
        _raw_spin_unlock_irqrestore(lVar17,uVar10);
      }
    }
  }
  iVar9 = ___ratelimit(qpnpint_spmi_masked_write__rs,"qpnpint_spmi_masked_write");
  if (iVar9 != 0) {
    _dev_err(*(undefined8 *)(lVar13 + 0xa8),"failed irqchip transaction on %x rc=%d\n",
             *(undefined4 *)(param_1 + 4),uVar11);
  }
LAB_00103abc:
  *(undefined **)(*(long *)(param_1 + 0x10) + 0x70) = puVar19;
  return uVar11;
}



//------------------------------------------------------------
// qpnpint_irq_set_wake @ 00103b10 size=36
// signature: undefined qpnpint_irq_set_wake(void)
// callers: []
//------------------------------------------------------------

void qpnpint_irq_set_wake(long param_1)

{
  irq_set_irq_wake(*(undefined4 *)(*(long *)(param_1 + 0x30) + 0x40));
  return;
}



//------------------------------------------------------------
// qpnpint_get_irqchip_state @ 00103b38 size=140
// signature: undefined qpnpint_get_irqchip_state(void)
// callers: []
//------------------------------------------------------------

void qpnpint_get_irqchip_state(long param_1,int param_2,byte *param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(ulong *)(param_1 + 8);
  local_2c[0] = 0;
  if (param_2 == 3) {
    qpnpint_spmi_read(param_1,0x10,local_2c);
    uVar2 = 0;
    *param_3 = local_2c[0] >> (uVar3 >> 0x10 & 7) & 1;
  }
  else {
    uVar2 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qpnpint_spmi_read @ 00103bc4 size=392
// signature: undefined qpnpint_spmi_read(void)
// callers: [qpnpint_irq_unmask, qpnpint_get_irqchip_state]
//------------------------------------------------------------

void qpnpint_spmi_read(long param_1,uint param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  code *pcVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0x30);
  lVar9 = *(long *)(lVar11 + 0xa8);
  uVar1 = *(uint *)(param_1 + 8) >> 0x1c;
  lVar10 = *(long *)(lVar9 + 0x98);
  uVar2 = param_2 & 0xff | (*(uint *)(param_1 + 8) >> 0x14 & 0xff) << 8;
  pcVar7 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x10);
  if (*(int *)(pcVar7 + -4) != -0x27bf939d) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103c40);
    (*pcVar7)();
  }
  uVar3 = (*pcVar7)(lVar10,uVar1,uVar2,1);
  if (-1 < (int)uVar3) {
    pcVar7 = *(code **)(*(long *)(lVar10 + 0xb0) + 0x18);
    if (*(int *)(pcVar7 + -4) != -0x5edd812c) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103c80);
      (*pcVar7)();
    }
    uVar4 = (*pcVar7)(1,uVar1,uVar2,0);
    lVar10 = lVar10 + 0x38;
    uVar6 = _raw_spin_lock_irqsave(lVar10);
    plVar8 = *(long **)(lVar9 + 0x98);
    writel_relaxed(uVar4,*plVar8 + (ulong)uVar3);
    iVar5 = pmic_arb_wait_for_done(lVar9,*plVar8,uVar1,uVar2,1);
    if (iVar5 == 0) {
      *param_3 = (char)*(undefined4 *)(*plVar8 + (ulong)(uVar3 + 0x18));
      _raw_spin_unlock_irqrestore(lVar10,uVar6);
      return;
    }
    _raw_spin_unlock_irqrestore(lVar10,uVar6);
  }
  iVar5 = ___ratelimit(qpnpint_spmi_read__rs,"qpnpint_spmi_read");
  if (iVar5 != 0) {
    _dev_err(*(undefined8 *)(lVar11 + 0xa8),"failed irqchip transaction on %x\n",
             *(undefined4 *)(param_1 + 4));
  }
  return;
}



//------------------------------------------------------------
// periph_interrupt @ 00103d4c size=444
// signature: undefined periph_interrupt(void)
// callers: [pmic_arb_chained_irq]
//------------------------------------------------------------

void periph_interrupt(long param_1,ulong param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  code *pcVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  int local_6c;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  lVar13 = (param_2 & 0xffff) * 4;
  uVar1 = *(ushort *)(*(long *)(param_1 + 200) + lVar13);
  pcVar8 = *(code **)(*(long *)(param_1 + 0xb0) + 0x38);
  if (*(int *)(pcVar8 + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103db4);
    (*pcVar8)();
  }
  (*pcVar8)();
  uVar5 = readl_relaxed();
  if ((int)uVar5 != 0) {
    uVar10 = uVar5 & 0xffffffff;
    uVar5 = 0;
    do {
      while( true ) {
        uVar9 = (uint)uVar10;
        uVar3 = (uVar9 & 0xaaaaaaaa) >> 1 | (uVar9 & 0x55555555) << 1;
        uVar3 = (uVar3 & 0xcccccccc) >> 2 | (uVar3 & 0x33333333) << 2;
        uVar3 = (uVar3 & 0xf0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f) << 4;
        uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
        lVar12 = LZCOUNT(uVar3 >> 0x10 | uVar3 << 0x10);
        uVar11 = (uint)lVar12;
        local_6c = 0;
        uVar3 = 1 << (ulong)(uVar11 & 0x1f);
        uVar9 = uVar9 & (uVar3 ^ 0xffffffff);
        uVar10 = (ulong)uVar9;
        lVar6 = __irq_resolve_mapping
                          (*(undefined8 *)(param_1 + 0xa0),
                           (uVar11 & 7) << 0x10 | (uint)uVar1 << 0x14 | (uint)param_2 & 0x3ff,
                           &local_6c);
        if ((lVar6 != 0) && (local_6c != 0)) break;
        uVar2 = *(ushort *)(*(long *)(param_1 + 200) + lVar13);
        iVar4 = ___ratelimit(cleanup_irq__rs,"cleanup_irq");
        if (iVar4 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0xa8),"%s apid=%d sid=0x%x per=0x%x irq=%d\n",
                   "cleanup_irq",(uint)param_2 & 0xffff,uVar2 >> 8,uVar2 & 0xff,lVar12);
        }
        pcVar8 = *(code **)(*(long *)(param_1 + 0xb0) + 0x40);
        if (*(int *)(pcVar8 + -4) != 0x1add67c8) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103e74);
          (*pcVar8)();
        }
        uVar7 = (*pcVar8)(param_1,param_2 & 0xffffffff);
        writel_relaxed(uVar3 & 0xff,uVar7);
        if (uVar9 == 0) goto LAB_00103ecc;
      }
      generic_handle_irq();
      uVar5 = (ulong)((int)uVar5 + 1);
    } while (uVar9 != 0);
  }
LAB_00103ecc:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// debug_spmi_addr_fops_open @ 00103f0c size=52
// signature: undefined debug_spmi_addr_fops_open(void)
// callers: []
//------------------------------------------------------------

void debug_spmi_addr_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,debug_spmi_addr_get,debug_spmi_addr_set,"0x%05llX\n");
  return;
}



//------------------------------------------------------------
// debug_spmi_addr_get @ 00103f44 size=16
// signature: undefined debug_spmi_addr_get(void)
// callers: []
//------------------------------------------------------------

undefined8 debug_spmi_addr_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0xe0);
  return 0;
}



//------------------------------------------------------------
// debug_spmi_addr_set @ 00103f58 size=16
// signature: undefined debug_spmi_addr_set(void)
// callers: []
//------------------------------------------------------------

undefined8 debug_spmi_addr_set(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xe0) = param_2;
  return 0;
}



//------------------------------------------------------------
// debug_soc_start_addr_fops_open @ 00103f6c size=48
// signature: undefined debug_soc_start_addr_fops_open(void)
// callers: []
//------------------------------------------------------------

void debug_soc_start_addr_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,debug_soc_start_addr_get,0,"0x%llX\n");
  return;
}



//------------------------------------------------------------
// debug_soc_start_addr_get @ 00103fa0 size=164
// signature: undefined debug_soc_start_addr_get(void)
// callers: []
//------------------------------------------------------------

void debug_soc_start_addr_get(long param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  pcVar3 = *(code **)(*(long *)(param_1 + 0xb0) + 0x58);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (*(int *)(pcVar3 + -4) != -0x75b4cca7) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104008);
    (*pcVar3)();
  }
  iVar2 = (*pcVar3)((int)param_1,*(uint *)(param_1 + 0xe0) >> 0x10 & 0xf,*(uint *)(param_1 + 0xe0),
                    &local_88);
  if (iVar2 == 0) {
    *param_2 = local_88;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// debug_soc_end_addr_fops_open @ 00104048 size=48
// signature: undefined debug_soc_end_addr_fops_open(void)
// callers: []
//------------------------------------------------------------

void debug_soc_end_addr_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,debug_soc_end_addr_get,0,"0x%llX\n");
  return;
}



//------------------------------------------------------------
// debug_soc_end_addr_get @ 0010407c size=164
// signature: undefined debug_soc_end_addr_get(void)
// callers: []
//------------------------------------------------------------

void debug_soc_end_addr_get(long param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  pcVar3 = *(code **)(*(long *)(param_1 + 0xb0) + 0x58);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = 0;
  if (*(int *)(pcVar3 + -4) != -0x75b4cca7) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1040e4);
    (*pcVar3)();
  }
  iVar2 = (*pcVar3)((int)param_1,*(uint *)(param_1 + 0xe0) >> 0x10 & 0xf,*(uint *)(param_1 + 0xe0),
                    &local_88);
  if (iVar2 == 0) {
    *param_2 = local_80;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00104154 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&spmi_pmic_arb_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104184 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&spmi_pmic_arb_driver);
  return;
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00107000 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [spmi_pmic_arb_map_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00107008 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [spmi_pmic_arb_map_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00107010 size=1
// signature: undefined _printk(void)
// callers: [spmi_pmic_arb_map_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pmic_arb_write_cmd_unlocked, qpnpint_irq_domain_alloc, qpnpint_irq_unmask, debug_soc_start_addr_get, spmi_pmic_arb_probe, qpnpint_get_irqchip_state, debug_soc_end_addr_get, spmi_pmic_arb_map_address, periph_interrupt, spmi_pmic_arb_debugfs_init, pmic_arb_read_cmd_unlocked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107020 size=1
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
// platform_driver_unregister @ 00107028 size=1
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
// spmi_controller_alloc @ 00107030 size=1
// signature: undefined spmi_controller_alloc(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00107038 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00107040 size=1
// signature: undefined devm_ioremap(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00107048 size=1
// signature: undefined devm_kmalloc(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00107050 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00107058 size=1
// signature: undefined _dev_info(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00107060 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00107068 size=1
// signature: undefined of_find_property(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00107070 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00107078 size=1
// signature: undefined _dev_err(void)
// callers: [pmic_arb_wait_for_done, qpnpint_irq_domain_activate, qpnpint_spmi_read, qpnpint_irq_ack, qpnpint_irq_mask, qpnpint_irq_domain_translate, spmi_pmic_arb_debugfs_init, pmic_arb_offset_v7, qpnpint_irq_unmask, pmic_arb_wr_addr_map_v7, spmi_pmic_arb_probe, qpnpint_irq_set_type, periph_interrupt, pmic_arb_offset_v5, pmic_arb_wr_addr_map_v5, pmic_arb_read_cmd, pmic_arb_write_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00107080 size=1
// signature: undefined put_device(void)
// callers: [spmi_pmic_arb_probe, spmi_pmic_arb_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_domain_add @ 00107088 size=1
// signature: undefined __irq_domain_add(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_domain_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chained_handler_and_data @ 00107090 size=1
// signature: undefined irq_set_chained_handler_and_data(void)
// callers: [spmi_pmic_arb_probe, spmi_pmic_arb_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chained_handler_and_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_add @ 00107098 size=1
// signature: undefined spmi_controller_add(void)
// callers: [spmi_pmic_arb_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_remove @ 001070a0 size=1
// signature: undefined irq_domain_remove(void)
// callers: [spmi_pmic_arb_probe, spmi_pmic_arb_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001070a8 size=1
// signature: undefined debugfs_remove(void)
// callers: [spmi_pmic_arb_remove, spmi_pmic_arb_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_remove @ 001070b0 size=1
// signature: undefined spmi_controller_remove(void)
// callers: [spmi_pmic_arb_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001070b8 size=1
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
// log_post_read_mmio @ 001070c0 size=1
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
// _raw_spin_lock_irqsave @ 001070c8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qpnpint_irq_unmask, pmic_arb_non_data_cmd_v1, qpnpint_irq_domain_activate, qpnpint_irq_set_type, qpnpint_spmi_read, qpnpint_irq_ack, qpnpint_irq_mask, pmic_arb_read_cmd, pmic_arb_write_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001070d0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qpnpint_irq_unmask, pmic_arb_non_data_cmd_v1, qpnpint_irq_domain_activate, qpnpint_irq_set_type, qpnpint_spmi_read, qpnpint_irq_ack, qpnpint_irq_mask, pmic_arb_read_cmd, pmic_arb_write_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001070d8 size=1
// signature: undefined __warn_printk(void)
// callers: [pmic_arb_chained_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// handle_bad_irq @ 001070e0 size=1
// signature: undefined handle_bad_irq(void)
// callers: [pmic_arb_chained_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void handle_bad_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001070e8 size=1
// signature: undefined scnprintf(void)
// callers: [spmi_pmic_arb_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001070f0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [spmi_pmic_arb_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 001070f8 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [spmi_pmic_arb_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00107108 size=1
// signature: undefined __const_udelay(void)
// callers: [pmic_arb_wait_for_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00107110 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00107118 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00107120 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [pmic_arb_write_cmd_unlocked, pmic_arb_read_cmd_unlocked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_set_info @ 00107138 size=1
// signature: undefined irq_domain_set_info(void)
// callers: [qpnpint_irq_domain_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_set_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00107140 size=1
// signature: undefined ___ratelimit(void)
// callers: [qpnpint_irq_unmask, qpnpint_irq_domain_activate, qpnpint_irq_set_type, qpnpint_spmi_read, periph_interrupt, qpnpint_irq_ack, qpnpint_irq_mask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00107150 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [qpnpint_irq_set_wake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 00107158 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [periph_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// generic_handle_irq @ 00107160 size=1
// signature: undefined generic_handle_irq(void)
// callers: [periph_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void generic_handle_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00107168 size=1
// signature: undefined simple_attr_open(void)
// callers: [debug_soc_start_addr_fops_open, debug_spmi_addr_fops_open, debug_soc_end_addr_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



