// Decompiled by Ghidra 12.2
// Program: pinctrl-spmi-mpp.ko
// Image base: 00100000

//------------------------------------------------------------
// pmic_mpp_probe @ 001003ec size=1756
// signature: undefined pmic_mpp_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100ac0) */

ulong pmic_mpp_probe(long param_1)

{
  long *plVar1;
  ushort *puVar2;
  undefined2 uVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  ulong uVar7;
  long *plVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  char *pcVar14;
  long lVar15;
  int iVar16;
  ulong uVar17;
  ulong uVar18;
  long *plVar19;
  int iVar20;
  int local_70;
  uint local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  plVar1 = (long *)(param_1 + 0x10);
  local_70 = 0;
  uVar6 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),&DAT_001029af,&local_70,1,0);
  if ((int)uVar6 < 0) {
    uVar17 = (ulong)uVar6;
    _dev_err(plVar1,"missing base address");
  }
  else {
    uVar7 = platform_irq_count(param_1);
    uVar6 = (uint)uVar7;
    if (uVar6 == 0) {
      uVar17 = 0xffffffea;
    }
    else {
      uVar17 = uVar7 & 0xffffffff;
      if (-1 < (int)uVar6) {
        if (8 < uVar6) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100ac8);
          (*pcVar5)();
        }
        plVar8 = (long *)devm_kmalloc(plVar1,0x2a0,0xdc0);
        if (plVar8 != (long *)0x0) {
          uVar9 = *(undefined8 *)(param_1 + 0x70);
          uVar18 = uVar7 & 0xffffffff;
          *(long **)(param_1 + 0xa8) = plVar8;
          *plVar8 = (long)plVar1;
          lVar10 = dev_get_regmap(uVar9,0);
          plVar8[1] = lVar10;
          lVar10 = devm_kmalloc(plVar1,uVar18 * 0x18,0xdc0);
          if (((lVar10 != 0) && (lVar11 = devm_kmalloc(plVar1,uVar18 * 0x30,0xdc0), lVar11 != 0)) &&
             (plVar12 = (long *)devm_kmalloc(plVar1,0x58,0xdc0), plVar12 != (long *)0x0)) {
            plVar12[3] = (long)&pmic_mpp_pinctrl_ops;
            plVar12[4] = (long)pmic_mpp_pinmux_ops;
            lVar15 = *(long *)(param_1 + 0x80);
            plVar12[5] = (long)pmic_mpp_pinconf_ops;
            plVar12[6] = (long)&__this_module;
            if (lVar15 == 0) {
              lVar15 = *plVar1;
            }
            *plVar12 = lVar15;
            plVar12[1] = lVar10;
            iVar20 = 0;
            *(undefined4 *)(plVar12 + 7) = 4;
            lVar15 = 0;
            lVar13 = 0;
            plVar19 = (long *)(lVar10 + 0x10);
            *(uint *)(plVar12 + 2) = uVar6;
            plVar12[8] = (long)&pmic_mpp_bindings;
            plVar12[9] = (long)pmic_conf_items;
            do {
              puVar2 = (ushort *)(lVar11 + lVar15);
              *(int *)(plVar19 + -2) = (int)lVar13;
              *plVar19 = (long)puVar2;
              if (lVar15 == 0x180) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100ac0);
                (*pcVar5)();
              }
              plVar19[-1] = (long)(&pmic_mpp_groups)[lVar13];
              uVar17 = platform_get_irq(param_1);
              *(int *)(lVar11 + lVar15 + 4) = (int)uVar17;
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                goto LAB_00100888;
              }
              lVar10 = plVar8[1];
              local_6c = 0;
              *puVar2 = (ushort)(iVar20 + local_70);
              uVar17 = regmap_read(lVar10,(iVar20 + local_70 & 0xffffU) + 4,&local_6c);
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                lVar10 = *plVar8;
                uVar9 = 4;
                goto LAB_00100a90;
              }
              if ((int)local_6c < 0) {
                uVar17 = (ulong)local_6c;
                goto LAB_00100888;
              }
              if (local_6c != 0x11) {
                uVar3 = *(undefined2 *)(lVar11 + lVar15);
                pcVar14 = "incorrect block type 0x%x at 0x%x\n";
                lVar10 = *plVar8;
LAB_001009a8:
                _dev_err(lVar10,pcVar14,local_6c,uVar3);
                uVar17 = 0xffffffed;
                goto LAB_00100888;
              }
              local_6c = 0;
              uVar17 = regmap_read(plVar8[1],*puVar2 + 5,&local_6c);
              uVar6 = local_6c;
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                lVar10 = *plVar8;
                uVar9 = 5;
                goto LAB_00100a90;
              }
              if ((int)local_6c < 0) {
                uVar17 = (ulong)local_6c;
                goto LAB_00100888;
              }
              uVar4 = local_6c - 3;
              if ((0xc < uVar4) || ((0x101fU >> (ulong)(uVar4 & 0x1f) & 1) == 0)) {
                uVar3 = *(undefined2 *)(lVar11 + lVar15);
                pcVar14 = "unknown MPP type 0x%x at 0x%x\n";
                lVar10 = *plVar8;
                goto LAB_001009a8;
              }
              lVar10 = plVar8[1];
              local_6c = 0;
              *(undefined4 *)((ushort *)(lVar11 + lVar15) + 8) =
                   *(undefined4 *)(&DAT_00102418 + (long)(int)uVar4 * 4);
              uVar17 = regmap_read(lVar10,*(ushort *)(lVar11 + lVar15) + 0x40,&local_6c);
              if ((int)uVar17 < 0) {
                lVar10 = *plVar8;
                uVar9 = 0x40;
LAB_00100a10:
                uVar17 = uVar17 & 0xffffffff;
                _dev_err(lVar10,"read 0x%x failed\n",uVar9);
                goto LAB_00100888;
              }
              if ((int)local_6c < 0) {
                uVar17 = (ulong)local_6c;
                goto LAB_00100888;
              }
              lVar10 = lVar11 + lVar15;
              uVar17 = (ulong)(local_6c >> 4) & 7;
              iVar16 = (int)uVar17;
              *(byte *)(lVar10 + 9) = (byte)local_6c & 1;
              if (iVar16 == 7) {
                _dev_err(*plVar8,"unknown MPP direction\n");
                uVar17 = 0xffffffed;
                goto LAB_00100888;
              }
              iVar16 = iVar16 << 3;
              uVar4 = local_6c >> 1 & 7;
              *(undefined4 *)(lVar10 + 0x24) = *(undefined4 *)(&DAT_0010244c + uVar17 * 4);
              *(char *)(lVar10 + 0xb) = (char)(0x101010001 >> iVar16);
              *(char *)(lVar10 + 10) = (char)(0x1010001010100 >> iVar16);
              if (uVar4 < 4) {
                if (uVar4 == 1) {
                  *(undefined1 *)(lVar11 + lVar15 + 0xc) = 1;
                }
              }
              else {
                *(uint *)(lVar11 + lVar15 + 0x2c) = uVar4 + 1;
              }
              local_6c = 0;
              uVar17 = regmap_read(plVar8[1],*puVar2 + 0x41,&local_6c);
              if ((int)uVar17 < 0) {
                lVar10 = *plVar8;
                uVar9 = 0x41;
                goto LAB_00100a10;
              }
              uVar17 = (ulong)local_6c;
              if ((int)local_6c < 0) goto LAB_00100888;
              *(uint *)(lVar11 + lVar15 + 0x14) = local_6c & 7;
              if ((uVar6 & 0xfffffffd) != 4) {
                local_6c = 0;
                uVar17 = regmap_read(plVar8[1],*puVar2 + 0x42,&local_6c);
                if ((int)uVar17 < 0) {
                  uVar17 = uVar17 & 0xffffffff;
                  lVar10 = *plVar8;
                  uVar9 = 0x42;
                  goto LAB_00100a90;
                }
                uVar17 = (ulong)local_6c;
                if ((int)local_6c < 0) goto LAB_00100888;
                *(uint *)(lVar11 + lVar15 + 0x20) = local_6c & 7;
                *(undefined1 *)(lVar11 + lVar15 + 0xd) = 1;
              }
              local_6c = 0;
              uVar17 = regmap_read(plVar8[1],*puVar2 + 0x4a,&local_6c);
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                lVar10 = *plVar8;
                uVar9 = 0x4a;
LAB_00100a90:
                _dev_err(lVar10,"read 0x%x failed\n",uVar9);
                goto LAB_00100888;
              }
              uVar17 = (ulong)local_6c;
              if ((int)local_6c < 0) goto LAB_00100888;
              uVar6 = local_6c & 7;
              lVar10 = plVar8[1];
              local_6c = 0;
              *(uint *)((ushort *)(lVar11 + lVar15) + 0xc) = uVar6;
              uVar17 = regmap_read(lVar10,*(ushort *)(lVar11 + lVar15) + 0x4c,&local_6c);
              uVar6 = local_6c;
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                lVar10 = *plVar8;
                uVar9 = 0x4c;
                goto LAB_00100a90;
              }
              uVar17 = (ulong)local_6c;
              if ((int)local_6c < 0) goto LAB_00100888;
              lVar10 = plVar8[1];
              local_6c = 0;
              *(uint *)((ushort *)(lVar11 + lVar15) + 0x14) = uVar6;
              uVar17 = regmap_read(lVar10,*(ushort *)(lVar11 + lVar15) + 0x48,&local_6c);
              uVar6 = local_6c;
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                lVar10 = *plVar8;
                uVar9 = 0x48;
                goto LAB_00100a90;
              }
              uVar17 = (ulong)local_6c;
              if ((int)local_6c < 0) goto LAB_00100888;
              lVar10 = plVar8[1];
              local_6c = 0;
              *(uint *)((ushort *)(lVar11 + lVar15) + 0xe) = uVar6;
              uVar17 = regmap_read(lVar10,*(ushort *)(lVar11 + lVar15) + 0x46,&local_6c);
              if ((int)uVar17 < 0) {
                uVar17 = uVar17 & 0xffffffff;
                lVar10 = *plVar8;
                uVar9 = 0x46;
                goto LAB_00100a90;
              }
              uVar17 = (ulong)local_6c;
              if ((int)local_6c < 0) goto LAB_00100888;
              lVar10 = lVar11 + lVar15;
              lVar15 = lVar15 + 0x30;
              iVar20 = iVar20 + 0x100;
              plVar19 = plVar19 + 3;
              lVar13 = lVar13 + 1;
              *(bool *)(lVar10 + 8) = local_6c != 0;
            } while (uVar18 * 0x30 != lVar15);
            plVar19 = plVar8 + 3;
            lVar10 = *(long *)(param_1 + 0x80);
            memcpy(plVar19,pmic_mpp_gpio_template,0x288);
            *(short *)((long)plVar8 + 0xc4) = (short)uVar7;
            plVar8[5] = (long)plVar1;
            *(undefined4 *)(plVar8 + 0x18) = 0xffffffff;
            if (lVar10 == 0) {
              lVar10 = *plVar1;
            }
            plVar8[3] = lVar10;
            *(undefined4 *)(plVar8 + 0x4f) = 2;
            *(undefined1 *)(plVar8 + 0x1a) = 0;
            uVar17 = devm_pinctrl_register(plVar1,plVar12,plVar8);
            plVar8[2] = uVar17;
            if (uVar17 < 0xfffffffffffff001) {
              uVar6 = gpiochip_add_data_with_key(plVar19,plVar8,0,0);
              if (uVar6 == 0) {
                lVar10 = *(long *)(param_1 + 0x80);
                if (lVar10 == 0) {
                  lVar10 = *plVar1;
                }
                uVar7 = gpiochip_add_pin_range(plVar19,lVar10,0,0,uVar7 & 0xffffffff);
                uVar17 = 0;
                if ((int)uVar7 != 0) {
                  uVar17 = uVar7 & 0xffffffff;
                  _dev_err(plVar1,"failed to add pin range\n");
                  gpiochip_remove(plVar19);
                }
              }
              else {
                uVar17 = (ulong)uVar6;
                _dev_err(*plVar8,"can\'t add gpio chip\n");
              }
            }
            else {
              uVar17 = uVar17 & 0xffffffff;
            }
            goto LAB_00100888;
          }
        }
        uVar17 = 0xfffffff4;
      }
    }
  }
LAB_00100888:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17;
}



//------------------------------------------------------------
// pmic_mpp_remove @ 00100acc size=40
// signature: undefined pmic_mpp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_mpp_remove(long param_1)

{
  gpiochip_remove(*(long *)(param_1 + 0xa8) + 0x18);
  return 0;
}



//------------------------------------------------------------
// pmic_mpp_get_groups_count @ 00100af8 size=12
// signature: undefined pmic_mpp_get_groups_count(void)
// callers: []
//------------------------------------------------------------

undefined4 pmic_mpp_get_groups_count(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x10);
}



//------------------------------------------------------------
// pmic_mpp_get_group_name @ 00100b08 size=24
// signature: undefined pmic_mpp_get_group_name(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_mpp_get_group_name(long param_1,uint param_2)

{
  return *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 8);
}



//------------------------------------------------------------
// pmic_mpp_get_group_pins @ 00100b24 size=36
// signature: undefined pmic_mpp_get_group_pins(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_mpp_get_group_pins(long param_1,uint param_2,long *param_3,undefined4 *param_4)

{
  *param_3 = *(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18;
  *param_4 = 1;
  return 0;
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map_group @ 00100b4c size=32
// signature: undefined pinconf_generic_dt_node_to_map_group(void)
// callers: []
//------------------------------------------------------------

void pinconf_generic_dt_node_to_map_group(void)

{
  pinconf_generic_dt_node_to_map();
  return;
}



//------------------------------------------------------------
// pmic_mpp_get_functions_count @ 00100b70 size=8
// signature: undefined pmic_mpp_get_functions_count(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_mpp_get_functions_count(void)

{
  return 3;
}



//------------------------------------------------------------
// pmic_mpp_get_function_name @ 00100b7c size=28
// signature: undefined pmic_mpp_get_function_name(void)
// callers: []
//------------------------------------------------------------

undefined * pmic_mpp_get_function_name(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  
  if (2 < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100b98);
    (*pcVar1)();
  }
  return (&pmic_mpp_functions)[param_2];
}



//------------------------------------------------------------
// pmic_mpp_get_function_groups @ 00100b9c size=32
// signature: undefined pmic_mpp_get_function_groups(void)
// callers: []
//------------------------------------------------------------

undefined8
pmic_mpp_get_function_groups
          (long param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  *param_3 = &pmic_mpp_groups;
  *param_4 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x10);
  return 0;
}



//------------------------------------------------------------
// pmic_mpp_set_mux @ 00100bc0 size=160
// signature: undefined pmic_mpp_set_mux(void)
// callers: []
//------------------------------------------------------------

int pmic_mpp_set_mux(long param_1,undefined4 param_2,ulong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  ushort *puVar3;
  
  puVar2 = (undefined8 *)pinctrl_dev_get_drvdata();
  puVar3 = *(ushort **)
            (*(long *)(*(long *)(param_1 + 0x10) + 8) + (param_3 & 0xffffffff) * 0x18 + 0x10);
  *(undefined4 *)(puVar3 + 0x12) = param_2;
  iVar1 = pmic_mpp_write_mode_ctl(puVar2,puVar3);
  if ((-1 < iVar1) &&
     (iVar1 = regmap_write(puVar2[1],*puVar3 + 0x46,(ulong)(byte)puVar3[4] << 7), iVar1 < 0)) {
    _dev_err(*puVar2,"write 0x%x failed\n",0x46);
  }
  return iVar1;
}



//------------------------------------------------------------
// pmic_mpp_write_mode_ctl @ 00100c60 size=256
// signature: undefined pmic_mpp_write_mode_ctl(void)
// callers: [pmic_mpp_config_set, pmic_mpp_set_mux]
//------------------------------------------------------------

int pmic_mpp_write_mode_ctl(undefined8 *param_1,ushort *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_2 + 0x12) == 0) {
    if (*(char *)((long)param_2 + 0xb) == '\0') {
      uVar2 = 0x10;
    }
    else {
      uVar2 = (uint)(byte)param_2[5];
      if ((byte)param_2[5] != 0) {
        uVar2 = 0x20;
        iVar1 = *(int *)(param_2 + 0x16);
        goto joined_r0x00100cbc;
      }
    }
    iVar1 = *(int *)(param_2 + 0x16);
  }
  else if (*(int *)(param_2 + 0x12) == 1) {
    if (*(char *)((long)param_2 + 0xb) == '\0') {
      uVar2 = 0x50;
      iVar1 = *(int *)(param_2 + 0x16);
    }
    else if ((char)param_2[5] == '\0') {
      uVar2 = 0x40;
      iVar1 = *(int *)(param_2 + 0x16);
    }
    else {
      uVar2 = 0x30;
      iVar1 = *(int *)(param_2 + 0x16);
    }
  }
  else {
    uVar2 = 0x60;
    iVar1 = *(int *)(param_2 + 0x16);
  }
joined_r0x00100cbc:
  if (iVar1 == 0) {
    uVar3 = (uint)(byte)param_2[6] << 1;
  }
  else {
    uVar3 = iVar1 * 2 + 6;
  }
  iVar1 = regmap_write(param_1[1],*param_2 + 0x40,uVar3 | uVar2 | *(byte *)((long)param_2 + 9));
  if (iVar1 < 0) {
    _dev_err(*param_1,"write 0x%x failed\n",0x40);
  }
  return iVar1;
}



//------------------------------------------------------------
// pmic_mpp_config_get @ 00100d64 size=244
// signature: undefined pmic_mpp_config_get(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_mpp_config_get(long param_1,uint param_2,ulong *param_3)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  
  uVar3 = 0xffffffea;
  bVar1 = (byte)*param_3;
  lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 0x10);
  switch(bVar1) {
  case 1:
    if (*(int *)(lVar5 + 0x20) != 3) {
      return uVar3;
    }
    goto LAB_00100e18;
  case 2:
    if (*(char *)(lVar5 + 8) != '\0') {
      return uVar3;
    }
    goto LAB_00100e18;
  case 3:
  case 4:
  case 6:
  case 7:
  case 8:
  case 10:
  case 0xb:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x12:
  case 0x13:
  case 0x14:
    goto switchD_00100da0_caseD_3;
  case 5:
    if (2 < *(uint *)(lVar5 + 0x20)) {
      return uVar3;
    }
    uVar4 = *(uint *)(&DAT_00102468 + (long)(int)*(uint *)(lVar5 + 0x20) * 4);
    break;
  case 9:
    uVar4 = *(uint *)(lVar5 + 0x28);
    break;
  case 0xc:
    cVar2 = *(char *)(lVar5 + 0xb);
joined_r0x00100e50:
    if (cVar2 == '\0') {
switchD_00100da0_caseD_3:
      return uVar3;
    }
LAB_00100e18:
    uVar4 = 1;
    break;
  case 0x11:
    uVar4 = (uint)*(byte *)(lVar5 + 9);
    break;
  case 0x15:
    uVar4 = *(uint *)(lVar5 + 0x14);
    break;
  default:
    switch(bVar1) {
    case 0x80:
      uVar4 = *(uint *)(lVar5 + 0x18);
      break;
    case 0x81:
      uVar4 = *(uint *)(lVar5 + 0x1c);
      break;
    case 0x82:
      uVar4 = *(uint *)(lVar5 + 0x2c);
      break;
    case 0x83:
      cVar2 = *(char *)(lVar5 + 0xc);
      goto joined_r0x00100e50;
    default:
      goto switchD_00100da0_caseD_3;
    }
  }
  *param_3 = (ulong)((uint)bVar1 | uVar4 << 8);
  return 0;
}



//------------------------------------------------------------
// pmic_mpp_config_set @ 00100e5c size=680
// signature: undefined pmic_mpp_config_set(void)
// callers: [pmic_mpp_direction_input, pmic_mpp_set, pmic_mpp_direction_output]
//------------------------------------------------------------

int pmic_mpp_config_set(long param_1,ulong param_2,long param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  ushort *puVar7;
  
  puVar3 = (undefined8 *)pinctrl_dev_get_drvdata();
  puVar7 = *(ushort **)
            (*(long *)(*(long *)(param_1 + 0x10) + 8) + (param_2 & 0xffffffff) * 0x18 + 0x10);
  *(undefined1 *)(puVar7 + 4) = 1;
  if (param_4 != 0) {
    iVar2 = 0;
    iVar1 = -0x16;
    do {
      uVar6 = *(undefined8 *)(param_3 + (long)iVar2 * 8);
      uVar5 = (uint)uVar6;
      uVar4 = (uint)((ulong)uVar6 >> 8) & 0xffffff;
      switch(uVar5 & 0xff) {
      case 1:
        puVar7[0x10] = 3;
        puVar7[0x11] = 0;
        break;
      case 2:
        *(undefined1 *)(puVar7 + 4) = 0;
        break;
      case 3:
      case 4:
      case 6:
      case 7:
      case 8:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x12:
      case 0x13:
      case 0x14:
        goto switchD_00100f0c_caseD_3;
      case 5:
        if (uVar4 == 30000) {
          puVar7[0x10] = 2;
          puVar7[0x11] = 0;
        }
        else if (uVar4 == 10000) {
          puVar7[0x10] = 1;
          puVar7[0x11] = 0;
        }
        else {
          if (uVar4 != 600) {
            return -0x16;
          }
          puVar7[0x10] = 0;
          puVar7[0x11] = 0;
        }
        break;
      case 9:
        *(uint *)(puVar7 + 0x14) = uVar4;
        break;
      case 0xc:
        *(bool *)((long)puVar7 + 0xb) = 0xff < uVar5;
        break;
      case 0x11:
        *(undefined1 *)(puVar7 + 5) = 1;
        *(bool *)((long)puVar7 + 9) = 0xff < uVar5;
        break;
      case 0x15:
        if (*(uint *)(puVar7 + 8) <= uVar4) {
          return -0x16;
        }
        *(uint *)(puVar7 + 10) = uVar4;
        break;
      default:
        switch(uVar5 & 0xff) {
        case 0x80:
          if (0x6ff < uVar5) {
            return -0x16;
          }
          *(uint *)(puVar7 + 0xc) = uVar4;
          break;
        case 0x81:
          *(uint *)(puVar7 + 0xe) = uVar4;
          break;
        case 0x82:
          *(uint *)(puVar7 + 0x16) = uVar4;
          break;
        case 0x83:
          *(bool *)(puVar7 + 6) = 0xff < uVar5;
          break;
        default:
          goto switchD_00100f0c_caseD_3;
        }
      }
      iVar2 = iVar2 + 1;
    } while (param_4 != iVar2);
  }
  iVar1 = regmap_write(puVar3[1],*puVar7 + 0x41,*(undefined4 *)(puVar7 + 10));
  if (iVar1 < 0) {
    uVar6 = 0x41;
  }
  else if ((*(char *)((long)puVar7 + 0xd) == '\0') ||
          (iVar1 = regmap_write(puVar3[1],*puVar7 + 0x42,*(undefined4 *)(puVar7 + 0x10)), -1 < iVar1
          )) {
    iVar1 = regmap_write(puVar3[1],*puVar7 + 0x4a,*(uint *)(puVar7 + 0xc) & 7);
    if (iVar1 < 0) {
      uVar6 = 0x4a;
    }
    else {
      iVar1 = regmap_write(puVar3[1],*puVar7 + 0x48,*(undefined4 *)(puVar7 + 0xe));
      if (iVar1 < 0) {
        uVar6 = 0x48;
      }
      else {
        iVar2 = pmic_mpp_write_mode_ctl(puVar3,puVar7);
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar1 = regmap_write(puVar3[1],*puVar7 + 0x4c,*(undefined4 *)(puVar7 + 0x14));
        if (iVar1 < 0) {
          uVar6 = 0x4c;
        }
        else {
          iVar1 = regmap_write(puVar3[1],*puVar7 + 0x46,(ulong)(byte)puVar7[4] << 7);
          if (-1 < iVar1) {
            return iVar1;
          }
          uVar6 = 0x46;
        }
      }
    }
  }
  else {
    uVar6 = 0x42;
  }
  _dev_err(*puVar3,"write 0x%x failed\n",uVar6);
switchD_00100f0c_caseD_3:
  return iVar1;
}



//------------------------------------------------------------
// pmic_mpp_config_dbg_show @ 00101108 size=508
// signature: undefined pmic_mpp_config_dbg_show(void)
// callers: [pmic_mpp_dbg_show]
//------------------------------------------------------------

void pmic_mpp_config_dbg_show(long param_1,undefined8 param_2,uint param_3)

{
  undefined *puVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  char *pcVar6;
  ushort *puVar7;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar5 = (undefined8 *)pinctrl_dev_get_drvdata();
  puVar7 = *(ushort **)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_3 * 0x18 + 0x10);
  seq_printf(param_2," mpp%-2d:",param_3 + 1);
  if ((char)puVar7[4] == '\0') {
    pcVar6 = " ---";
  }
  else {
    if (*(char *)((long)puVar7 + 0xb) != '\0') {
      local_3c = 0;
      iVar4 = regmap_read(puVar5[1],*puVar7 + 0x10,&local_3c);
      if (iVar4 < 0) {
        _dev_err(*puVar5,"read 0x%x failed\n",0x10);
        goto LAB_001012b8;
      }
      if (local_3c < 0) goto LAB_001012b8;
      *(byte *)((long)puVar7 + 9) = (byte)local_3c & 1;
    }
    puVar1 = &DAT_001029a7;
    if ((char)puVar7[5] != '\0') {
      puVar1 = &DAT_001028f8;
    }
    seq_printf(param_2," %-4s",puVar1);
    if (2 < *(uint *)(puVar7 + 0x12)) {
LAB_00101300:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101304);
      (*pcVar3)();
    }
    seq_printf(param_2," %-7s",(&pmic_mpp_functions)[*(uint *)(puVar7 + 0x12)]);
    seq_printf(param_2," vin-%d",*(undefined4 *)(puVar7 + 10));
    seq_printf(param_2,&DAT_001029f4,*(undefined4 *)(puVar7 + 0xe));
    if (*(char *)((long)puVar7 + 0xd) != '\0') {
      if (3 < *(uint *)(puVar7 + 0x10)) goto LAB_00101300;
      seq_printf(param_2," %-8s",(&pmic_mpp_config_dbg_show_biases)[*(uint *)(puVar7 + 0x10)]);
    }
    puVar1 = &DAT_00102a45;
    if (*(char *)((long)puVar7 + 9) != '\0') {
      puVar1 = &DAT_00102a8e;
    }
    seq_printf(param_2," %-4s",puVar1);
    if (*(int *)(puVar7 + 0x16) != 0) {
      seq_printf(param_2," dtest%d");
    }
    if ((char)puVar7[6] == '\0') goto LAB_001012b8;
    pcVar6 = " paired";
  }
  seq_puts(param_2,pcVar6);
LAB_001012b8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_mpp_direction_input @ 00101308 size=112
// signature: undefined pmic_mpp_direction_input(void)
// callers: []
//------------------------------------------------------------

void pmic_mpp_direction_input(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = 0x10c;
  pmic_mpp_config_set(*(undefined8 *)(lVar1 + 0x10),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_mpp_direction_output @ 0010137c size=120
// signature: undefined pmic_mpp_direction_output(void)
// callers: []
//------------------------------------------------------------

void pmic_mpp_direction_output(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = (ulong)(param_3 << 8 | 0x11);
  pmic_mpp_config_set(*(undefined8 *)(lVar1 + 0x10),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_mpp_get @ 001013f8 size=212
// signature: undefined pmic_mpp_get(void)
// callers: []
//------------------------------------------------------------

uint pmic_mpp_get(undefined8 param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  ushort *puVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar3 = (undefined8 *)gpiochip_get_data();
  puVar4 = *(ushort **)
            (*(long *)(*(long *)(puVar3[2] + 0x10) + 8) + (param_2 & 0xffffffff) * 0x18 + 0x10);
  if (*(char *)((long)puVar4 + 0xb) == '\0') {
    uVar2 = (uint)*(byte *)((long)puVar4 + 9);
  }
  else {
    local_3c = 0;
    uVar2 = regmap_read(puVar3[1],*puVar4 + 0x10,&local_3c);
    if ((int)uVar2 < 0) {
      _dev_err(*puVar3,"read 0x%x failed\n",0x10);
    }
    else {
      uVar2 = local_3c;
      if (-1 < (int)local_3c) {
        uVar2 = local_3c & 1;
        *(char *)((long)puVar4 + 9) = (char)uVar2;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// pmic_mpp_set @ 001014d0 size=120
// signature: undefined pmic_mpp_set(void)
// callers: []
//------------------------------------------------------------

void pmic_mpp_set(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = (ulong)(param_3 << 8 | 0x11);
  pmic_mpp_config_set(*(undefined8 *)(lVar1 + 0x10),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_mpp_to_irq @ 0010154c size=68
// signature: undefined pmic_mpp_to_irq(void)
// callers: []
//------------------------------------------------------------

undefined4 pmic_mpp_to_irq(undefined8 param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = gpiochip_get_data();
  return *(undefined4 *)
          (*(long *)(*(long *)(*(long *)(*(long *)(lVar1 + 0x10) + 0x10) + 8) +
                     (ulong)param_2 * 0x18 + 0x10) + 4);
}



//------------------------------------------------------------
// pmic_mpp_dbg_show @ 00101594 size=132
// signature: undefined pmic_mpp_dbg_show(void)
// callers: []
//------------------------------------------------------------

void pmic_mpp_dbg_show(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = gpiochip_get_data(param_2);
  if (*(short *)(param_2 + 0xac) != 0) {
    uVar2 = 0;
    do {
      pmic_mpp_config_dbg_show(*(undefined8 *)(lVar1 + 0x10),param_1,uVar2);
      seq_puts(param_1,&DAT_00102a8c);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(param_2 + 0xac));
  }
  return;
}



//------------------------------------------------------------
// pmic_mpp_of_xlate @ 0010161c size=44
// signature: undefined pmic_mpp_of_xlate(void)
// callers: []
//------------------------------------------------------------

int pmic_mpp_of_xlate(long param_1,long param_2,undefined4 *param_3)

{
  if (*(uint *)(param_1 + 0x260) < 2) {
    return -0x16;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_2 + 0x10);
  }
  return *(int *)(param_2 + 0xc) + -1;
}



//------------------------------------------------------------
// init_module @ 0010164c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pmic_mpp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010167c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pmic_mpp_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// platform_driver_unregister @ 00104008 size=1
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
// of_property_read_variable_u32_array @ 00104010 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_irq_count @ 00104018 size=1
// signature: undefined platform_irq_count(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_irq_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00104028 size=1
// signature: undefined dev_get_regmap(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00104030 size=1
// signature: undefined platform_get_irq(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00104038 size=1
// signature: undefined regmap_read(void)
// callers: [pmic_mpp_get, pmic_mpp_probe, pmic_mpp_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104040 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_register @ 00104048 size=1
// signature: undefined devm_pinctrl_register(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104050 size=1
// signature: undefined _dev_err(void)
// callers: [pmic_mpp_config_set, pmic_mpp_get, pmic_mpp_probe, pmic_mpp_config_dbg_show, pmic_mpp_set_mux, pmic_mpp_write_mode_ctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_data_with_key @ 00104058 size=1
// signature: undefined gpiochip_add_data_with_key(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_data_with_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_pin_range @ 00104060 size=1
// signature: undefined gpiochip_add_pin_range(void)
// callers: [pmic_mpp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_pin_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_remove @ 00104068 size=1
// signature: undefined gpiochip_remove(void)
// callers: [pmic_mpp_probe, pmic_mpp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pmic_mpp_get, pmic_mpp_probe, pmic_mpp_direction_input, pmic_mpp_set, pmic_mpp_direction_output, pmic_mpp_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map @ 00104078 size=1
// signature: undefined pinconf_generic_dt_node_to_map(void)
// callers: [pinconf_generic_dt_node_to_map_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinconf_generic_dt_node_to_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_dev_get_drvdata @ 00104080 size=1
// signature: undefined pinctrl_dev_get_drvdata(void)
// callers: [pmic_mpp_config_set, pmic_mpp_config_dbg_show, pmic_mpp_set_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_dev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00104088 size=1
// signature: undefined regmap_write(void)
// callers: [pmic_mpp_config_set, pmic_mpp_set_mux, pmic_mpp_write_mode_ctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00104090 size=1
// signature: undefined seq_printf(void)
// callers: [pmic_mpp_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00104098 size=1
// signature: undefined seq_puts(void)
// callers: [pmic_mpp_dbg_show, pmic_mpp_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_get_data @ 001040a0 size=1
// signature: undefined gpiochip_get_data(void)
// callers: [pmic_mpp_to_irq, pmic_mpp_get, pmic_mpp_direction_input, pmic_mpp_set, pmic_mpp_dbg_show, pmic_mpp_direction_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_get_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



