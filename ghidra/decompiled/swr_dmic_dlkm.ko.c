// Decompiled by Ghidra 12.2
// Program: swr_dmic_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// swr_dmic_probe @ 001002cc size=2508
// signature: undefined swr_dmic_probe(void)
// callers: []
//------------------------------------------------------------

int swr_dmic_probe(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  ulong uVar3;
  uint uVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  undefined4 *puVar12;
  undefined8 *puVar13;
  char *pcVar14;
  char *pcVar15;
  undefined *puVar16;
  undefined *puVar17;
  long lVar18;
  char *local_c8;
  undefined1 local_bc [4];
  ulong local_b8 [11];
  
  lVar9 = sp_el0;
  lVar1 = param_1 + 0x48;
  local_b8[10] = *(long *)(lVar9 + 0x638);
  local_bc[0] = 0;
  local_c8 = (char *)0x0;
  lVar9 = devm_kmalloc(lVar1,200,0xdc0);
  if (lVar9 == 0) {
    iVar7 = -0xc;
    goto LAB_00100490;
  }
  puVar2 = (undefined4 *)(lVar9 + 0x30);
  iVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x330),"qcom,swr-dmic-supply",puVar2,1,0);
  if (iVar7 < 0) goto LAB_00100490;
  local_b8[8] = 0;
  local_b8[9] = 0;
  local_b8[6] = 0;
  local_b8[7] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[0] = 0;
  local_b8[1] = 0;
  iVar7 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x330),"qcom,wcd-handle",0,0,0,local_b8);
  uVar3 = local_b8[0];
  if (iVar7 != 0) {
    uVar3 = 0;
  }
  *(ulong *)(lVar9 + 0x38) = uVar3;
  if (uVar3 != 0) {
    lVar10 = of_find_device_by_node();
    if (lVar10 != 0) {
      uVar11 = snd_soc_lookup_component(lVar10 + 0x10,0);
      *(undefined8 *)(lVar9 + 0x28) = uVar11;
    }
    *(undefined1 *)(lVar9 + 0x40) = 1;
    if (*(long *)(lVar9 + 0x28) == 0) {
      iVar7 = ___ratelimit(enable_wcd_codec_supply__rs,"enable_wcd_codec_supply");
      if (iVar7 != 0) {
        _printk(&DAT_00101ca5,"enable_wcd_codec_supply");
      }
    }
    else {
      iVar7 = wcd939x_codec_force_enable_micbias_v2(*(long *)(lVar9 + 0x28),1,*puVar2);
      if (iVar7 == 0) {
        *(int *)(lVar9 + 0x44) = *(int *)(lVar9 + 0x44) + 1;
        goto LAB_001003ec;
      }
    }
LAB_0010044c:
    iVar7 = -0x205;
    *(undefined1 *)(lVar9 + 0x40) = 0;
    *(undefined8 *)(lVar9 + 0x38) = 0;
    goto LAB_00100490;
  }
  *(undefined1 *)(lVar9 + 0x40) = 0;
LAB_001003ec:
  uVar11 = *(undefined8 *)(param_1 + 0x330);
  *(long *)(param_1 + 0xe0) = lVar9;
  *(long *)(lVar9 + 8) = param_1;
  iVar7 = of_property_read_string(uVar11,"qcom,codec-name",&local_c8);
  if (iVar7 == 0) {
    lVar18 = *(long *)(param_1 + 0xe0);
    local_b8[0] = local_b8[0] & 0xffffffff00000000;
    lVar10 = of_find_property(*(undefined8 *)(param_1 + 0x330),"qcom,swr-tx-port-params",local_b8);
    uVar3 = local_b8[0];
    if (lVar10 == 0) {
      pcVar14 = "missing port mapping prop %s\n";
      pcVar15 = "qcom,swr-tx-port-params";
LAB_00100550:
      _dev_err(lVar1,pcVar14,pcVar15);
      iVar7 = -0x16;
    }
    else {
      uVar4 = (uint)local_b8[0];
      if (((uint)local_b8[0] & 0xfffffff0) != 0x40) {
        pcVar14 = "%s:port params not provided for all usecases\n";
        pcVar15 = "swr_dmic_parse_port_params";
        goto LAB_00100550;
      }
      puVar12 = (undefined4 *)__kmalloc(local_b8[0] & 0xffffffff,0xdc0);
      if (puVar12 == (undefined4 *)0x0) {
        iVar7 = -0xc;
      }
      else {
        iVar7 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x330),"qcom,swr-tx-port-params",puVar12,0x10,0
                          );
        if (-1 < iVar7) {
          if (uVar4 < 4) {
LAB_00100c94:
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(1,0x100c98);
            (*pcVar5)();
          }
          *(undefined4 *)(lVar18 + 0x4c) = *puVar12;
          if ((((((uVar3 & 0xfffffffc) == 4) ||
                (*(undefined4 *)(lVar18 + 0x50) = puVar12[1], uVar4 < 4)) ||
               ((uVar3 & 0xfffffffc) == 4)) ||
              ((_dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n",
                         "swr_dmic_parse_port_params",0,0,*puVar12,puVar12[1]), uVar4 < 8 ||
               ((uVar3 & 0xfffffffc) == 8)))) ||
             ((*(undefined4 *)(lVar18 + 0x54) = puVar12[2], uVar4 < 0xc ||
              ((uVar3 & 0xfffffffc) == 0xc)))) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x58) = puVar12[3];
          if ((((uVar3 & 0xfffffffc) == 8) || (uVar4 < 0xc)) || ((uVar3 & 0xfffffffc) == 0xc))
          goto LAB_00100c94;
          _dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n","swr_dmic_parse_port_params",
                   1,0,puVar12[2],puVar12[3]);
          *(undefined4 **)(lVar18 + 0x90) = (undefined4 *)(lVar18 + 0x4c);
          if ((uVar4 < 0x10) || ((uVar3 & 0xfffffffc) == 0x10)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x5c) = puVar12[4];
          if ((uVar4 < 0x14) || ((uVar3 & 0xfffffffc) == 0x14)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x60) = puVar12[5];
          if (((((((uVar3 & 0xfffffffc) == 0x10) || (uVar4 < 0x14)) ||
                ((uVar3 & 0xfffffffc) == 0x14)) ||
               ((_dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n",
                          "swr_dmic_parse_port_params",0,1,puVar12[4],puVar12[5]), uVar4 < 0x18 ||
                ((uVar3 & 0xfffffffc) == 0x18)))) ||
              (*(undefined4 *)(lVar18 + 100) = puVar12[6], uVar4 < 0x1c)) ||
             ((uVar3 & 0xfffffffc) == 0x1c)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x68) = puVar12[7];
          if ((((uVar3 & 0xfffffffc) == 0x18) || (uVar4 < 0x1c)) || ((uVar3 & 0xfffffffc) == 0x1c))
          goto LAB_00100c94;
          _dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n","swr_dmic_parse_port_params",
                   1,1,puVar12[6],puVar12[7]);
          *(undefined4 **)(lVar18 + 0x98) = (undefined4 *)(lVar18 + 0x5c);
          if ((uVar4 < 0x20) || ((uVar3 & 0xfffffffc) == 0x20)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x6c) = puVar12[8];
          if ((uVar4 < 0x24) || ((uVar3 & 0xfffffffc) == 0x24)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x70) = puVar12[9];
          if (((((uVar3 & 0xfffffffc) == 0x20) || (uVar4 < 0x24)) || ((uVar3 & 0xfffffffc) == 0x24))
             || (((_dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n",
                            "swr_dmic_parse_port_params",0,2,puVar12[8],puVar12[9]), uVar4 < 0x28 ||
                  ((uVar3 & 0xfffffffc) == 0x28)) ||
                 ((*(undefined4 *)(lVar18 + 0x74) = puVar12[10], uVar4 < 0x2c ||
                  ((uVar3 & 0xfffffffc) == 0x2c)))))) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x78) = puVar12[0xb];
          if ((((uVar3 & 0xfffffffc) == 0x28) || (uVar4 < 0x2c)) || ((uVar3 & 0xfffffffc) == 0x2c))
          goto LAB_00100c94;
          _dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n","swr_dmic_parse_port_params",
                   1,2,puVar12[10],puVar12[0xb]);
          *(undefined4 **)(lVar18 + 0xa0) = (undefined4 *)(lVar18 + 0x6c);
          if ((uVar4 < 0x30) || ((uVar3 & 0xfffffffc) == 0x30)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x7c) = puVar12[0xc];
          if ((uVar4 < 0x34) || ((uVar3 & 0xfffffffc) == 0x34)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x80) = puVar12[0xd];
          if (((((((uVar3 & 0xfffffffc) == 0x30) || (uVar4 < 0x34)) ||
                ((uVar3 & 0xfffffffc) == 0x34)) ||
               ((_dev_err(lVar1,"%s: port %d, uc: %d, offset1:%d, lane: %d\n",
                          "swr_dmic_parse_port_params",0,3,puVar12[0xc],puVar12[0xd]), uVar4 < 0x38
                || ((uVar3 & 0xfffffffc) == 0x38)))) ||
              (*(undefined4 *)(lVar18 + 0x84) = puVar12[0xe], uVar4 < 0x3c)) ||
             ((uVar3 & 0xfffffffc) == 0x3c)) goto LAB_00100c94;
          *(undefined4 *)(lVar18 + 0x88) = puVar12[0xf];
          if ((((uVar3 & 0xfffffffc) == 0x38) || (uVar4 < 0x3c)) || ((uVar3 & 0xfffffffc) == 0x3c))
          goto LAB_00100c94;
          _dev_err(param_1 + 0x48,"%s: port %d, uc: %d, offset1:%d, lane: %d\n",
                   "swr_dmic_parse_port_params",1,3,puVar12[0xe],puVar12[0xf]);
          *(undefined4 **)(lVar18 + 0xa8) = (undefined4 *)(lVar18 + 0x7c);
          kfree(puVar12);
          usleep_range_state(5000,0x1392,2);
          usleep_range_state(100,0x6e,2);
          iVar7 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_bc);
          bVar6 = iVar7 == 0;
          if (iVar7 != 0) {
            usleep_range_state(100,0x6e,2);
            iVar7 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_bc);
            bVar6 = iVar7 == 0;
            if (iVar7 != 0) {
              usleep_range_state(100,0x6e,2);
              iVar7 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_bc);
              bVar6 = iVar7 == 0;
              if (iVar7 != 0) {
                usleep_range_state(100,0x6e,2);
                iVar7 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_bc);
                bVar6 = iVar7 == 0;
                if (iVar7 != 0) {
                  usleep_range_state(100,0x6e,2);
                  iVar7 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_bc)
                  ;
                  bVar6 = iVar7 == 0;
                }
              }
            }
          }
          if (!bVar6) {
            _dev_info(param_1 + 0x48,"%s get devnum %d for dev addr %llx failed\n","swr_dmic_probe",
                      local_bc[0],*(undefined8 *)(param_1 + 0x3d8));
            if (*(int *)(lVar9 + 0x44) == 1) {
              enable_wcd_codec_supply(lVar9,0);
              *(int *)(lVar9 + 0x44) = *(int *)(lVar9 + 0x44) + -1;
            }
            goto LAB_0010044c;
          }
          *(undefined1 *)(param_1 + 0x40) = local_bc[0];
          swr_init_port_params(param_1,2,lVar9 + 0x90);
          puVar13 = (undefined8 *)devm_kmalloc(lVar1,0x170,0xdc0);
          *(undefined8 **)(lVar9 + 0x18) = puVar13;
          if (puVar13 != (undefined8 *)0x0) {
            memcpy(puVar13,soc_codec_dev_swr_dmic,0x170);
            pcVar14 = local_c8;
            puVar16 = codec_name_list;
            iVar7 = strcmp(local_c8,codec_name_list);
            puVar17 = PTR_s_swr_dmic_02_00101ed0;
            if (iVar7 == 0) {
              lVar10 = 0;
            }
            else {
              iVar7 = strcmp(pcVar14,PTR_s_swr_dmic_02_00101ed0);
              puVar16 = PTR_s_swr_dmic_03_00101ed8;
              if (iVar7 == 0) {
                lVar10 = 1;
                puVar16 = puVar17;
              }
              else {
                iVar7 = strcmp(pcVar14,PTR_s_swr_dmic_03_00101ed8);
                puVar17 = PTR_s_swr_dmic_04_00101ee0;
                if (iVar7 == 0) {
                  lVar10 = 2;
                }
                else {
                  iVar7 = strcmp(pcVar14,PTR_s_swr_dmic_04_00101ee0);
                  if (iVar7 != 0) {
                    iVar7 = -0x16;
                    goto LAB_00100410;
                  }
                  lVar10 = 3;
                  puVar16 = puVar17;
                }
              }
            }
            *puVar13 = puVar16;
            puVar13 = (undefined8 *)devm_kmalloc(lVar1,0xe0,0xdc0);
            *(undefined8 **)(lVar9 + 0x20) = puVar13;
            if (puVar13 != (undefined8 *)0x0) {
              memcpy(puVar13,&swr_dmic_dai,0xe0);
              uVar11 = *(undefined8 *)(lVar9 + 0x18);
              puVar17 = (&dai_name_list)[lVar10];
              puVar16 = (&aif_name_list)[lVar10];
              *(int *)(puVar13 + 1) = (int)lVar10;
              *puVar13 = puVar17;
              puVar13[0x10] = puVar16;
              iVar7 = snd_soc_register_component(lVar1,uVar11,puVar13,1);
              if (iVar7 == 0) {
                lVar10 = snd_soc_lookup_component(lVar1,**(undefined8 **)(lVar9 + 0x18));
                if (lVar10 != 0) {
                  iVar7 = 0;
                  *(long *)(lVar9 + 0x10) = lVar10;
                  goto LAB_00100490;
                }
                _dev_err(lVar1,"%s: could not find swr_dmic component\n","swr_dmic_probe");
                iVar7 = 0;
              }
              else {
                _dev_err(lVar1,"%s: Codec registration failed\n","swr_dmic_probe");
              }
              goto LAB_00100410;
            }
          }
          iVar7 = -0xc;
          goto LAB_00100410;
        }
        _dev_err(lVar1,"%s: Failed to read  port mapping from prop %s\n",
                 "swr_dmic_parse_port_params","qcom,swr-tx-port-params");
        kfree(puVar12);
      }
    }
    _dev_err(param_1 + 0x48,"%s: Parsing %s failed in node %s\n","swr_dmic_probe",
             "qcom,swr-tx-port-params",*(undefined8 *)(*(long *)(param_1 + 0x330) + 0x10));
  }
LAB_00100410:
  if (*(int *)(lVar9 + 0x44) == 1) {
    if (*(long *)(lVar9 + 0x28) == 0) {
      iVar8 = ___ratelimit(enable_wcd_codec_supply__rs,"enable_wcd_codec_supply");
      if (iVar8 != 0) {
        _printk(&DAT_00101ca5,"enable_wcd_codec_supply");
      }
    }
    else {
      wcd939x_codec_force_enable_micbias_v2(*(long *)(lVar9 + 0x28),8,*puVar2);
    }
    *(int *)(lVar9 + 0x44) = *(int *)(lVar9 + 0x44) + -1;
  }
  *(undefined1 *)(lVar9 + 0x40) = 0;
  *(undefined8 *)(lVar9 + 0x38) = 0;
  swr_remove_device(param_1);
LAB_00100490:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// swr_dmic_remove @ 00100c9c size=192
// signature: undefined swr_dmic_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_dmic_remove(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0xe0), lVar3 == 0)) {
    _dev_err(param_1 + 0x48,"%s: swr_dmic is NULL\n","swr_dmic_remove");
    uVar2 = 0xffffffea;
  }
  else {
    if (*(int *)(lVar3 + 0x44) == 1) {
      if (*(long *)(lVar3 + 0x28) == 0) {
        iVar1 = ___ratelimit(enable_wcd_codec_supply__rs,"enable_wcd_codec_supply");
        if (iVar1 != 0) {
          _printk(&DAT_00101ca5,"enable_wcd_codec_supply");
        }
      }
      else {
        wcd939x_codec_force_enable_micbias_v2
                  (*(long *)(lVar3 + 0x28),8,*(undefined4 *)(lVar3 + 0x30));
      }
      *(int *)(lVar3 + 0x44) = *(int *)(lVar3 + 0x44) + -1;
    }
    snd_soc_unregister_component(param_1 + 0x48);
    uVar2 = 0;
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// enable_wcd_codec_supply @ 00100d5c size=108
// signature: undefined enable_wcd_codec_supply(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

void enable_wcd_codec_supply(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x28) == 0) {
    iVar1 = ___ratelimit(enable_wcd_codec_supply__rs,"enable_wcd_codec_supply");
    if (iVar1 != 0) {
      _printk(&DAT_00101ca5,"enable_wcd_codec_supply");
    }
  }
  else {
    if ((param_2 & 1) == 0) {
      uVar2 = 8;
    }
    else {
      uVar2 = 1;
    }
    wcd939x_codec_force_enable_micbias_v2
              (*(long *)(param_1 + 0x28),uVar2,*(undefined4 *)(param_1 + 0x30));
  }
  return;
}



//------------------------------------------------------------
// swr_dmic_codec_probe @ 00100dcc size=824
// signature: undefined swr_dmic_codec_probe(void)
// callers: []
//------------------------------------------------------------

void swr_dmic_codec_probe(long param_1)

{
  long lVar1;
  size_t sVar2;
  undefined8 uVar3;
  long lVar4;
  char *pcVar5;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_80 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar4 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    *(long *)(lVar4 + 0x10) = param_1;
    pcVar5 = *(char **)(param_1 + 0x10);
    if (pcVar5 == (char *)0x0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: component prefix is NULL\n",
               "swr_dmic_codec_probe");
      uVar3 = 0xfffffdfb;
    }
    else {
      lVar1 = param_1 + 0xd0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80,&DAT_00101cd9,0x28);
      strlcat(&local_80,*(undefined8 *)(*(long *)(lVar4 + 0x20) + 0x80),0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      pcVar5 = *(char **)(param_1 + 0x10);
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80," SWR_DMIC",0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      pcVar5 = *(char **)(param_1 + 0x10);
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80," SMIC_PORT_EN",0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      pcVar5 = *(char **)(param_1 + 0x10);
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80," SWR_DMIC_OUTPUT",0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      pcVar5 = *(char **)(param_1 + 0x10);
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80," VA_SWR_DMIC",0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      pcVar5 = *(char **)(param_1 + 0x10);
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80," SMIC_VA_PORT_EN",0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      pcVar5 = *(char **)(param_1 + 0x10);
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      sVar2 = strlen(pcVar5);
      if (0x26 < sVar2) {
        sVar2 = 0x27;
      }
      memcpy(&local_80,pcVar5,sVar2);
      *(undefined1 *)((long)&local_80 + sVar2) = 0;
      strlcat(&local_80," SWR_DMIC_VA_OUTPUT",0x28);
      snd_soc_dapm_ignore_suspend(lVar1,&local_80);
      snd_soc_dapm_sync(lVar1);
      *(undefined8 *)(lVar4 + 0xb0) = swr_dmic_event_notify;
      wcd939x_swr_dmic_register_notifier
                (*(undefined8 *)(lVar4 + 0x28),(undefined8 *)(lVar4 + 0xb0),1);
      uVar3 = 0;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// swr_dmic_codec_remove @ 00101108 size=16
// signature: undefined swr_dmic_codec_remove(void)
// callers: []
//------------------------------------------------------------

void swr_dmic_codec_remove(long param_1)

{
  *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x10) = 0;
  return;
}



//------------------------------------------------------------
// swr_dmic_tx_master_port_get @ 0010111c size=272
// signature: undefined swr_dmic_tx_master_port_get(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_dmic_tx_master_port_get(long param_1,long param_2)

{
  char *__s;
  uint uVar1;
  int iVar2;
  size_t sVar3;
  long lVar4;
  undefined *puVar5;
  long lVar6;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    iVar2 = ___ratelimit(swr_dmic_tx_master_port_get__rs,"swr_dmic_tx_master_port_get");
    if (iVar2 != 0) {
      puVar5 = &DAT_00101c77;
      goto LAB_00101218;
    }
  }
  else {
    lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
    if (lVar6 != 0) {
      __s = (char *)(param_1 + 0x20);
      sVar3 = strlen(__s);
      lVar4 = strnstr(__s,&DAT_00101d50,sVar3);
      if (lVar4 == 0) {
        sVar3 = strlen(__s);
        lVar4 = strnstr(__s,&DAT_0010194a,sVar3);
        if (lVar4 == 0) {
          return 0xffffffea;
        }
        lVar4 = 1;
      }
      else {
        lVar4 = 0;
      }
      uVar1 = *(byte *)(lVar6 + lVar4 + 0x48) - 0x2d;
      lVar6 = 0;
      if (uVar1 < 0xe) {
        lVar6 = ((ulong)uVar1 & 0xff) + 1;
      }
      *(long *)(param_2 + 0x48) = lVar6;
      return 0;
    }
    iVar2 = ___ratelimit(swr_dmic_tx_master_port_get__rs_35,"swr_dmic_tx_master_port_get");
    if (iVar2 != 0) {
      puVar5 = &DAT_00101a3c;
LAB_00101218:
      _printk(puVar5,"swr_dmic_tx_master_port_get");
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// swr_dmic_tx_master_port_put @ 00101230 size=272
// signature: undefined swr_dmic_tx_master_port_put(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_dmic_tx_master_port_put(long param_1,long param_2)

{
  char *__s;
  int iVar1;
  size_t sVar2;
  long lVar3;
  undefined *puVar4;
  long lVar5;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    iVar1 = ___ratelimit(swr_dmic_tx_master_port_put__rs,"swr_dmic_tx_master_port_put");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar4 = &DAT_00101c77;
  }
  else {
    lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
    if (lVar5 != 0) {
      __s = (char *)(param_1 + 0x20);
      sVar2 = strlen(__s);
      lVar3 = strnstr(__s,&DAT_00101d50,sVar2);
      if (lVar3 == 0) {
        sVar2 = strlen(__s);
        lVar3 = strnstr(__s,&DAT_0010194a,sVar2);
        if (lVar3 == 0) {
          return 0xffffffea;
        }
        lVar3 = 1;
      }
      else {
        lVar3 = 0;
      }
      if (*(uint *)(param_2 + 0x48) < 0xf) {
        *(char *)(lVar5 + lVar3 + 0x48) =
             (char)*(undefined4 *)(swr_master_channel_map + (ulong)*(uint *)(param_2 + 0x48) * 4);
        return 0;
      }
      return 0xffffffea;
    }
    iVar1 = ___ratelimit(swr_dmic_tx_master_port_put__rs_41,"swr_dmic_tx_master_port_put");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar4 = &DAT_00101a3c;
  }
  _printk(puVar4,"swr_dmic_tx_master_port_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// dmic_swr_ctrl @ 00101344 size=296
// signature: undefined dmic_swr_ctrl(void)
// callers: []
//------------------------------------------------------------

void dmic_swr_ctrl(long param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  byte local_3c [4];
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar5 = *(long *)(param_1 + 0x28);
  local_2c[0] = 1;
  bVar1 = *(byte *)(param_1 + 0x4c);
  local_30[0] = 1;
  lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
  local_3c[0] = bVar1;
  if (bVar1 < 2) {
    local_34 = 2400000;
    if (bVar1 != 0) {
      local_34 = 600000;
    }
    local_38[0] = *(undefined1 *)(lVar4 + (ulong)bVar1 + 0x48);
    if ((int)param_3 == 8) {
      uVar3 = swr_slvdev_datapath_control
                        (*(long *)(lVar4 + 8),*(undefined1 *)(*(long *)(lVar4 + 8) + 0x40),0);
    }
    else if ((int)param_3 == 1) {
      uVar3 = swr_connect_port(*(undefined8 *)(lVar4 + 8),local_3c,param_3,local_30,&local_34,
                               local_2c,local_38);
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    iVar2 = ___ratelimit(dmic_swr_ctrl__rs,"dmic_swr_ctrl");
    if (iVar2 == 0) {
      uVar3 = 0xffffffea;
    }
    else {
      _dev_err(*(undefined8 *)(lVar5 + -0xb8),"%s: invalid port id: %d\n","dmic_swr_ctrl",bVar1);
      uVar3 = 0xffffffea;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// swr_dmic_port_enable @ 00101470 size=188
// signature: undefined swr_dmic_port_enable(void)
// callers: []
//------------------------------------------------------------

void swr_dmic_port_enable(long param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 local_24 [4];
  byte local_20 [4];
  undefined1 local_1c [4];
  long local_18;
  
  lVar3 = sp_el0;
  local_18 = *(long *)(lVar3 + 0x638);
  local_1c[0] = 1;
  local_20[0] = *(byte *)(param_1 + 0x4c);
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (1 < (ulong)local_20[0]) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101528);
    (*pcVar1)();
  }
  local_24[0] = *(undefined1 *)(lVar3 + (ulong)local_20[0] + 0x48);
  if (param_3 == 4) {
    uVar2 = swr_disconnect_port(*(undefined8 *)(lVar3 + 8),local_20,1,local_1c,local_24);
  }
  else if (param_3 == 2) {
    uVar2 = swr_slvdev_datapath_control
                      (*(long *)(lVar3 + 8),*(undefined1 *)(*(long *)(lVar3 + 8) + 0x40),1);
  }
  else {
    uVar2 = 0;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// swr_dmic_event_notify @ 00101530 size=748
// signature: undefined swr_dmic_event_notify(void)
// callers: []
//------------------------------------------------------------

void swr_dmic_event_notify(long param_1,short param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  undefined1 local_2c [4];
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  if (param_2 != 1) {
    if (param_2 == 0) {
      lVar5 = *(long *)(param_1 + -0xa8);
      if ((lVar5 == 0) || (lVar4 = *(long *)(lVar5 + 0xe0), lVar4 == 0)) {
        iVar1 = ___ratelimit(swr_dmic_down__rs,"swr_dmic_down");
        if (iVar1 != 0) {
          lVar5 = lVar5 + 0x48;
          pcVar3 = "swr_dmic_down";
          goto LAB_00101724;
        }
        goto LAB_0010177c;
      }
      iVar1 = *(int *)(lVar4 + 0x44) + -1;
      *(int *)(lVar4 + 0x44) = iVar1;
      if (iVar1 < 0) {
        _dev_warn(lVar5 + 0x48,"%s: mismatch in supply count %d\n","swr_dmic_down");
        uVar2 = 0;
        *(undefined4 *)(lVar4 + 0x44) = 0;
        goto LAB_00101780;
      }
      if (iVar1 == 0) {
        if (*(long *)(lVar4 + 0x28) == 0) {
          uVar2 = ___ratelimit(enable_wcd_codec_supply__rs,"enable_wcd_codec_supply");
          if ((int)uVar2 != 0) {
            _printk(&DAT_00101ca5,"enable_wcd_codec_supply");
            uVar2 = 0;
          }
        }
        else {
          wcd939x_codec_force_enable_micbias_v2
                    (*(long *)(lVar4 + 0x28),8,*(undefined4 *)(lVar4 + 0x30));
          uVar2 = 0;
        }
        goto LAB_00101780;
      }
    }
    uVar2 = 0;
    goto LAB_00101780;
  }
  lVar5 = *(long *)(param_1 + -0xa8);
  if ((lVar5 == 0) || (lVar4 = *(long *)(lVar5 + 0xe0), lVar4 == 0)) {
    iVar1 = ___ratelimit(swr_dmic_up__rs,"swr_dmic_up");
    if (iVar1 != 0) {
      lVar5 = lVar5 + 0x48;
      pcVar3 = "swr_dmic_up";
LAB_00101724:
      _dev_err(lVar5,"%s: swr_dmic is NULL\n",pcVar3);
    }
  }
  else {
    iVar1 = *(int *)(lVar4 + 0x44);
    *(int *)(lVar4 + 0x44) = iVar1 + 1;
    if (iVar1 == 0) {
      if (*(long *)(lVar4 + 0x28) == 0) {
        iVar1 = ___ratelimit(enable_wcd_codec_supply__rs,"enable_wcd_codec_supply");
        if (iVar1 != 0) {
          _printk(&DAT_00101ca5,"enable_wcd_codec_supply");
        }
        goto LAB_0010177c;
      }
      uVar2 = wcd939x_codec_force_enable_micbias_v2
                        (*(long *)(lVar4 + 0x28),1,*(undefined4 *)(lVar4 + 0x30));
      if ((int)uVar2 != 0) goto LAB_00101780;
    }
    lVar5 = *(long *)(param_1 + -0xa8);
    local_2c[0] = 0;
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0xe0) != 0)) {
      iVar1 = swr_get_logical_dev_num(lVar5,*(undefined8 *)(lVar5 + 0x3d8),local_2c);
      if (iVar1 != 0) {
        usleep_range_state(1000,0x44c,2);
        iVar1 = swr_get_logical_dev_num(lVar5,*(undefined8 *)(lVar5 + 0x3d8),local_2c);
        if (iVar1 != 0) {
          usleep_range_state(1000,0x44c,2);
          iVar1 = swr_get_logical_dev_num(lVar5,*(undefined8 *)(lVar5 + 0x3d8),local_2c);
          if (iVar1 != 0) {
            usleep_range_state(1000,0x44c,2);
            iVar1 = swr_get_logical_dev_num(lVar5,*(undefined8 *)(lVar5 + 0x3d8),local_2c);
            if (iVar1 != 0) {
              usleep_range_state(1000,0x44c,2);
              iVar1 = swr_get_logical_dev_num(lVar5,*(undefined8 *)(lVar5 + 0x3d8),local_2c);
              if (iVar1 != 0) {
                usleep_range_state(1000,0x44c,2);
                swr_get_logical_dev_num(lVar5,*(undefined8 *)(lVar5 + 0x3d8),local_2c);
              }
            }
          }
        }
      }
      uVar2 = 0;
      *(undefined1 *)(lVar5 + 0x40) = local_2c[0];
      goto LAB_00101780;
    }
    iVar1 = ___ratelimit(swr_dmic_reset__rs,"swr_dmic_reset");
    if (iVar1 != 0) {
      lVar5 = lVar5 + 0x48;
      pcVar3 = "swr_dmic_reset";
      goto LAB_00101724;
    }
  }
LAB_0010177c:
  uVar2 = 0xffffffea;
LAB_00101780:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// swr_dmic_suspend @ 00101820 size=8
// signature: undefined swr_dmic_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_dmic_suspend(void)

{
  return 0;
}



//------------------------------------------------------------
// swr_dmic_resume @ 0010182c size=120
// signature: undefined swr_dmic_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_dmic_resume(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (*(long *)(param_1 + 0x98) == 0)) {
    iVar1 = ___ratelimit(swr_dmic_resume__rs,"swr_dmic_resume");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: swr_dmic private data is NULL\n","swr_dmic_resume");
    }
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 001018a8 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  swr_driver_register(&swr_dmic_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001018d0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  swr_driver_unregister(&swr_dmic_driver);
  return;
}



//------------------------------------------------------------
// swr_driver_register @ 00105000 size=1
// signature: undefined swr_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_unregister @ 00105008 size=1
// signature: undefined swr_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00105010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105018 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00105020 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00105028 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_lookup_component @ 00105030 size=1
// signature: undefined snd_soc_lookup_component(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_lookup_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd939x_codec_force_enable_micbias_v2 @ 00105038 size=1
// signature: undefined wcd939x_codec_force_enable_micbias_v2(void)
// callers: [swr_dmic_remove, swr_dmic_probe, swr_dmic_event_notify, enable_wcd_codec_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd939x_codec_force_enable_micbias_v2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105040 size=1
// signature: undefined of_property_read_string(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00105048 size=1
// signature: undefined ___ratelimit(void)
// callers: [swr_dmic_remove, swr_dmic_probe, swr_dmic_tx_master_port_get, swr_dmic_event_notify, swr_dmic_resume, swr_dmic_tx_master_port_put, dmic_swr_ctrl, enable_wcd_codec_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_device @ 00105050 size=1
// signature: undefined swr_remove_device(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105058 size=1
// signature: undefined of_find_property(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105060 size=1
// signature: undefined __kmalloc(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105068 size=1
// signature: undefined _printk(void)
// callers: [swr_dmic_remove, swr_dmic_probe, swr_dmic_tx_master_port_get, swr_dmic_event_notify, swr_dmic_tx_master_port_put, enable_wcd_codec_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105070 size=1
// signature: undefined _dev_err(void)
// callers: [swr_dmic_remove, swr_dmic_probe, swr_dmic_event_notify, swr_dmic_resume, dmic_swr_ctrl, swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105078 size=1
// signature: undefined kfree(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00105080 size=1
// signature: undefined usleep_range_state(void)
// callers: [swr_dmic_probe, swr_dmic_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 00105088 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [swr_dmic_probe, swr_dmic_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_init_port_params @ 00105090 size=1
// signature: undefined swr_init_port_params(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_init_port_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105098 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [swr_dmic_probe, swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001050a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001050a8 size=1
// signature: undefined _dev_info(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 001050b0 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [swr_dmic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050b8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [swr_dmic_probe, swr_dmic_event_notify, dmic_swr_ctrl, swr_dmic_port_enable, swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 001050c0 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [swr_dmic_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001050c8 size=1
// signature: size_t strlen(char * __s)
// callers: [swr_dmic_tx_master_port_get, swr_dmic_tx_master_port_put, swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 001050d0 size=1
// signature: undefined strlcat(void)
// callers: [swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 001050d8 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 001050e0 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd939x_swr_dmic_register_notifier @ 001050e8 size=1
// signature: undefined wcd939x_swr_dmic_register_notifier(void)
// callers: [swr_dmic_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd939x_swr_dmic_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 001050f0 size=1
// signature: undefined strnstr(void)
// callers: [swr_dmic_tx_master_port_get, swr_dmic_tx_master_port_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 001050f8 size=1
// signature: undefined swr_connect_port(void)
// callers: [dmic_swr_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 00105100 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [dmic_swr_ctrl, swr_dmic_port_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 00105108 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [swr_dmic_port_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00105110 size=1
// signature: undefined _dev_warn(void)
// callers: [swr_dmic_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



