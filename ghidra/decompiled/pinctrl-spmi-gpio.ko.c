// Decompiled by Ghidra 12.2
// Program: pinctrl-spmi-gpio.ko
// Image base: 00100000

//------------------------------------------------------------
// pmic_gpio_probe @ 001004ec size=1636
// signature: undefined pmic_gpio_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100d88) */
/* WARNING: Removing unreachable block (ram,0x00100d84) */

ulong pmic_gpio_probe(long param_1)

{
  long *plVar1;
  long *__dest;
  uint uVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  int iVar5;
  long *plVar6;
  undefined8 uVar7;
  long lVar8;
  undefined4 *puVar9;
  ushort *puVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  undefined4 uVar15;
  uint local_bc;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  plVar1 = (long *)(param_1 + 0x10);
  local_bc = 0;
  uVar4 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),&DAT_0010603f,&local_bc,1,0);
  if ((int)uVar4 < 0) {
    uVar12 = (ulong)uVar4;
    _dev_err(plVar1,"missing base address");
    goto LAB_00100a18;
  }
  iVar5 = device_get_match_data(plVar1);
  plVar6 = (long *)devm_kmalloc(plVar1,0x2a8,0xdc0);
  if (plVar6 == (long *)0x0) {
LAB_00100a14:
    uVar12 = 0xfffffff4;
    goto LAB_00100a18;
  }
  uVar7 = *(undefined8 *)(param_1 + 0x70);
  *(long **)(param_1 + 0xa8) = plVar6;
  *plVar6 = (long)plVar1;
  lVar8 = dev_get_regmap(uVar7,0);
  lVar14 = *(long *)(param_1 + 0x70);
  plVar6[1] = lVar8;
  auVar3._8_8_ = 0;
  auVar3._0_8_ = (long)iVar5;
  *(undefined1 *)(plVar6 + 0x54) = *(undefined1 *)(lVar14 + 0x398);
  *(char *)((long)plVar6 + 0x2a1) = (char)(local_bc >> 8);
  if ((((SUB168(auVar3 * ZEXT816(0x18),8) != 0) ||
       (puVar9 = (undefined4 *)devm_kmalloc(plVar1,((long)iVar5 + (long)iVar5 * 2) * 8,0xdc0),
       puVar9 == (undefined4 *)0x0)) ||
      (puVar10 = (ushort *)devm_kmalloc(plVar1,(long)iVar5 * 0x2c,0xdc0), puVar10 == (ushort *)0x0))
     || (plVar11 = (long *)devm_kmalloc(plVar1,0x58,0xdc0), plVar11 == (long *)0x0))
  goto LAB_00100a14;
  lVar14 = *(long *)(param_1 + 0x80);
  plVar11[3] = (long)&pmic_gpio_pinctrl_ops;
  plVar11[4] = (long)pmic_gpio_pinmux_ops;
  plVar11[5] = (long)pmic_gpio_pinconf_ops;
  plVar11[6] = (long)&__this_module;
  lVar8 = lVar14;
  if (lVar14 == 0) {
    lVar8 = *plVar1;
  }
  *plVar11 = lVar8;
  plVar11[1] = (long)puVar9;
  *(int *)(plVar11 + 2) = iVar5;
  *(undefined4 *)(plVar11 + 7) = 5;
  plVar11[8] = (long)&pmic_gpio_bindings;
  plVar11[9] = (long)pmic_conf_items;
  if (iVar5 < 1) {
    __dest = plVar6 + 3;
    memcpy(__dest,pmic_gpio_gpio_template,0x288);
    plVar6[5] = (long)plVar1;
    *(short *)((long)plVar6 + 0xc4) = (short)iVar5;
    *(undefined4 *)(plVar6 + 0x18) = 0xffffffff;
    if (lVar14 == 0) {
      lVar14 = *plVar1;
    }
    plVar6[3] = lVar14;
    *(undefined4 *)(plVar6 + 0x4f) = 2;
    *(undefined1 *)(plVar6 + 0x1a) = 0;
    uVar12 = devm_pinctrl_register(plVar1,plVar11,plVar6);
    plVar6[2] = uVar12;
    if (0xfffffffffffff000 < uVar12) goto LAB_00100a18;
    lVar8 = of_irq_find_parent(*(undefined8 *)(*plVar6 + 0x2e8));
    if (lVar8 == 0) {
LAB_00100bcc:
      uVar12 = 0xfffffffa;
    }
    else {
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      uStack_b0 = 0;
      local_b8 = lVar8 + 0x18U;
      lVar14 = irq_find_matching_fwspec(&local_b8,1);
      if (lVar14 == 0) {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        uStack_b0 = 0;
        local_b8 = lVar8 + 0x18U;
        lVar14 = irq_find_matching_fwspec(&local_b8,0);
        if (lVar14 == 0) goto LAB_00100bcc;
      }
      *(undefined4 *)(plVar6 + 0x3a) = 0;
      plVar6[0x27] = (long)&spmi_gpio_irq_chip;
      plVar6[0x39] = (long)&handle_level_irq;
      lVar8 = 0;
      if (*(long *)(*plVar6 + 0x2e8) != 0) {
        lVar8 = *(long *)(*plVar6 + 0x2e8) + 0x18;
      }
      plVar6[0x2c] = (long)pmic_gpio_child_to_parent_hwirq;
      plVar6[0x2d] = (long)pmic_gpio_populate_parent_fwspec;
      plVar6[0x2a] = lVar8;
      plVar6[0x2b] = lVar14;
      plVar6[0x2e] = (long)pmic_gpio_child_offset_to_irq;
      plVar6[0x38] = (long)pmic_gpio_domain_translate;
      uVar4 = gpiochip_add_data_with_key(__dest,plVar6,0,0);
      if (uVar4 == 0) {
        lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"gpio-ranges",0);
        if (lVar8 == 0) {
          lVar8 = *(long *)(param_1 + 0x80);
          if (lVar8 == 0) {
            lVar8 = *plVar1;
          }
          uVar13 = gpiochip_add_pin_range(__dest,lVar8,0,0,iVar5);
          uVar12 = 0;
          if ((int)uVar13 != 0) {
            uVar12 = uVar13 & 0xffffffff;
            _dev_err(plVar1,"failed to add pin range\n");
            gpiochip_remove(__dest);
          }
        }
        else {
          uVar12 = 0;
        }
      }
      else {
        uVar12 = (ulong)uVar4;
        _dev_err(*plVar6,"can\'t add gpio chip\n");
      }
    }
    goto LAB_00100a18;
  }
  *puVar9 = 0;
  *(ushort **)(puVar9 + 4) = puVar10;
  lVar8 = plVar6[1];
  local_b8 = local_b8 & 0xffffffff00000000;
  *(undefined **)(puVar9 + 2) = pmic_gpio_groups;
  *puVar10 = (ushort)local_bc;
  uVar12 = regmap_read(lVar8,(local_bc & 0xffff) + 4,&local_b8);
  if ((int)uVar12 < 0) {
    uVar12 = uVar12 & 0xffffffff;
    _dev_err(*plVar6,"read 0x%x failed\n",4);
    goto LAB_00100a18;
  }
  uVar12 = local_b8 & 0xffffffff;
  if ((int)(uint)local_b8 < 0) goto LAB_00100a18;
  if ((uint)local_b8 != 0x10) {
    _dev_err(*plVar6,"incorrect block type 0x%x at 0x%x\n",uVar12,*puVar10);
    goto LAB_00100c6c;
  }
  local_b8 = local_b8 & 0xffffffff00000000;
  uVar12 = regmap_read(plVar6[1],*puVar10 + 5,&local_b8);
  if ((int)uVar12 < 0) {
    uVar12 = uVar12 & 0xffffffff;
    _dev_err(*plVar6,"read 0x%x failed\n",5);
    goto LAB_00100a18;
  }
  uVar12 = local_b8 & 0xffffffff;
  if ((int)(uint)local_b8 < 0) goto LAB_00100a18;
  switch((uint)local_b8) {
  case 1:
    *(undefined1 *)((long)puVar10 + 5) = 1;
  case 5:
    uVar15 = 4;
    break;
  default:
    _dev_err(*plVar6,"unknown GPIO type 0x%x\n",uVar12);
    goto LAB_00100c6c;
  case 9:
    *(undefined1 *)((long)puVar10 + 5) = 1;
  case 0xd:
    uVar15 = 8;
    break;
  case 0x10:
    puVar10[6] = 1;
    puVar10[7] = 0;
    goto LAB_00100750;
  case 0x11:
  case 0x12:
  case 0x14:
    uVar15 = 2;
    goto LAB_0010074c;
  case 0x13:
  case 0x15:
    uVar15 = 3;
LAB_0010074c:
    *(undefined4 *)(puVar10 + 6) = uVar15;
LAB_00100750:
    *(undefined1 *)((long)puVar10 + 5) = 1;
    *(undefined1 *)((long)puVar10 + 9) = 1;
    goto LAB_00100784;
  }
  *(undefined4 *)(puVar10 + 6) = uVar15;
LAB_00100784:
  if (*(char *)((long)puVar10 + 9) == '\0') {
    local_b8 = (ulong)local_b8._4_4_ << 0x20;
    uVar12 = regmap_read(plVar6[1],*puVar10 + 0x40,&local_b8);
    if ((int)uVar12 < 0) {
LAB_00100c90:
      uVar12 = uVar12 & 0xffffffff;
      _dev_err(*plVar6,"read 0x%x failed\n",0x40);
      goto LAB_00100a18;
    }
    uVar12 = local_b8 & 0xffffffff;
    if ((int)(uint)local_b8 < 0) goto LAB_00100a18;
    uVar4 = (uint)local_b8 >> 4 & 7;
    *(byte *)(puVar10 + 2) = (byte)local_b8 & 1;
    *(uint *)(puVar10 + 0x10) = (uint)local_b8 >> 1 & 7;
  }
  else {
    local_b8 = (ulong)local_b8._4_4_ << 0x20;
    uVar12 = regmap_read(plVar6[1],*puVar10 + 0x44,&local_b8);
    if ((int)uVar12 < 0) {
      uVar12 = uVar12 & 0xffffffff;
      _dev_err(*plVar6,"read 0x%x failed\n",0x44);
      goto LAB_00100a18;
    }
    uVar12 = local_b8 & 0xffffffff;
    if ((int)(uint)local_b8 < 0) goto LAB_00100a18;
    uVar2 = (uint)local_b8 >> 7;
    uVar4 = (uint)local_b8 & 0xf;
    lVar8 = plVar6[1];
    local_b8 = local_b8 & 0xffffffff00000000;
    *(byte *)(puVar10 + 2) = (byte)uVar2 & 1;
    *(uint *)(puVar10 + 0x10) = uVar4;
    uVar12 = regmap_read(lVar8,*puVar10 + 0x40,&local_b8);
    if ((int)uVar12 < 0) goto LAB_00100c90;
    uVar12 = local_b8 & 0xffffffff;
    if ((int)(uint)local_b8 < 0) goto LAB_00100a18;
    uVar4 = (uint)local_b8 & 3;
  }
  if (uVar4 < 4) {
                    /* WARNING: Could not recover jumptable at 0x0010085c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)(&UNK_00100860 + (ulong)(byte)(&DAT_00101e6a)[uVar4] * 4))();
    return uVar12;
  }
  _dev_err(*plVar6,"unknown GPIO direction\n");
LAB_00100c6c:
  uVar12 = 0xffffffed;
LAB_00100a18:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12 & 0xffffffff;
}



//------------------------------------------------------------
// pmic_gpio_remove @ 00100d90 size=40
// signature: undefined pmic_gpio_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_gpio_remove(long param_1)

{
  gpiochip_remove(*(long *)(param_1 + 0xa8) + 0x18);
  return 0;
}



//------------------------------------------------------------
// pmic_gpio_child_to_parent_hwirq @ 00100dbc size=80
// signature: undefined pmic_gpio_child_to_parent_hwirq(void)
// callers: []
//------------------------------------------------------------

undefined8
pmic_gpio_child_to_parent_hwirq
          (undefined8 param_1,int param_2,undefined4 param_3,int *param_4,undefined4 *param_5)

{
  long lVar1;
  
  lVar1 = gpiochip_get_data();
  *param_4 = (uint)*(byte *)(lVar1 + 0x2a1) + param_2;
  *param_5 = param_3;
  return 0;
}



//------------------------------------------------------------
// pmic_gpio_populate_parent_fwspec @ 00100e10 size=100
// signature: undefined pmic_gpio_populate_parent_fwspec(void)
// callers: []
//------------------------------------------------------------

undefined8
pmic_gpio_populate_parent_fwspec
          (long param_1,undefined8 *param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = gpiochip_get_data();
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x140) + 0x30);
  *(undefined4 *)(param_2 + 1) = 4;
  *param_2 = uVar2;
  *(uint *)((long)param_2 + 0xc) = (uint)*(byte *)(lVar1 + 0x2a0);
  *(undefined4 *)(param_2 + 2) = param_3;
  *(undefined4 *)(param_2 + 3) = param_4;
  return 0;
}



//------------------------------------------------------------
// pmic_gpio_child_offset_to_irq @ 00100e78 size=8
// signature: undefined pmic_gpio_child_offset_to_irq(void)
// callers: []
//------------------------------------------------------------

int pmic_gpio_child_offset_to_irq(undefined8 param_1,int param_2)

{
  return param_2 + 1;
}



//------------------------------------------------------------
// pmic_gpio_domain_translate @ 00100e84 size=68
// signature: undefined pmic_gpio_domain_translate(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_gpio_domain_translate(long param_1,long param_2,ulong *param_3,undefined4 *param_4)

{
  uint uVar1;
  
  if (((*(int *)(param_2 + 8) == 2) && (uVar1 = *(uint *)(param_2 + 0xc), uVar1 != 0)) &&
     (uVar1 <= *(ushort *)(*(long *)(param_1 + 0x20) + 0xac))) {
    *param_3 = (ulong)(uVar1 - 1);
    *param_4 = *(undefined4 *)(param_2 + 0x10);
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// pmic_gpio_get_groups_count @ 00100ecc size=12
// signature: undefined pmic_gpio_get_groups_count(void)
// callers: []
//------------------------------------------------------------

undefined4 pmic_gpio_get_groups_count(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x10);
}



//------------------------------------------------------------
// pmic_gpio_get_group_name @ 00100edc size=24
// signature: undefined pmic_gpio_get_group_name(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_gpio_get_group_name(long param_1,uint param_2)

{
  return *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 8);
}



//------------------------------------------------------------
// pmic_gpio_get_group_pins @ 00100ef8 size=36
// signature: undefined pmic_gpio_get_group_pins(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_gpio_get_group_pins(long param_1,uint param_2,long *param_3,undefined4 *param_4)

{
  *param_3 = *(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18;
  *param_4 = 1;
  return 0;
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map_group @ 00100f20 size=32
// signature: undefined pinconf_generic_dt_node_to_map_group(void)
// callers: []
//------------------------------------------------------------

void pinconf_generic_dt_node_to_map_group(void)

{
  pinconf_generic_dt_node_to_map();
  return;
}



//------------------------------------------------------------
// pmic_gpio_get_functions_count @ 00100f44 size=8
// signature: undefined pmic_gpio_get_functions_count(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_gpio_get_functions_count(void)

{
  return 10;
}



//------------------------------------------------------------
// pmic_gpio_get_function_name @ 00100f50 size=28
// signature: undefined pmic_gpio_get_function_name(void)
// callers: []
//------------------------------------------------------------

undefined * pmic_gpio_get_function_name(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  
  if (9 < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100f6c);
    (*pcVar1)();
  }
  return (&pmic_gpio_functions)[param_2];
}



//------------------------------------------------------------
// pmic_gpio_get_function_groups @ 00100f70 size=32
// signature: undefined pmic_gpio_get_function_groups(void)
// callers: []
//------------------------------------------------------------

undefined8
pmic_gpio_get_function_groups
          (long param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  *param_3 = &pmic_gpio_groups;
  *param_4 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x10);
  return 0;
}



//------------------------------------------------------------
// pmic_gpio_set_mux @ 00100f94 size=468
// signature: undefined pmic_gpio_set_mux(void)
// callers: []
//------------------------------------------------------------

int pmic_gpio_set_mux(long param_1,uint param_2,ulong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  ushort *puVar7;
  
  puVar2 = (undefined8 *)pinctrl_dev_get_drvdata();
  if (9 < param_2) {
    _printk(&DAT_00105fcc,param_2);
    return -0x16;
  }
  puVar7 = *(ushort **)
            (*(long *)(*(long *)(param_1 + 0x10) + 8) + (param_3 & 0xffffffff) * 0x18 + 0x10);
  uVar6 = param_2;
  if (*(char *)((long)puVar7 + 9) == '\0') {
    if ((param_2 & 0xfffffffe) == 4) {
      _printk(&DAT_001062be);
      return -0x16;
    }
    uVar6 = param_2 - 2;
    if (param_2 < 6) {
      uVar6 = param_2;
    }
  }
  *(uint *)(puVar7 + 0x10) = uVar6;
  *(undefined1 *)((long)puVar7 + 3) = 1;
  if ((char)puVar7[4] == '\0') {
    uVar4 = (uint)(byte)puVar7[3];
    if (((byte)puVar7[3] != 0) && (*(char *)((long)puVar7 + 7) != '\0')) {
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 3;
  }
  if (*(char *)((long)puVar7 + 9) == '\0') {
    iVar1 = regmap_write(puVar2[1],*puVar7 + 0x40,uVar4 << 4 | uVar6 << 1 | (uint)(byte)puVar7[2]);
    if (iVar1 < 0) goto LAB_0010110c;
  }
  else {
    iVar1 = regmap_write(puVar2[1],*puVar7 + 0x40,uVar4);
    if (iVar1 < 0) {
LAB_0010110c:
      uVar3 = *puVar2;
      uVar5 = 0x40;
      goto LAB_0010114c;
    }
    iVar1 = regmap_write(puVar2[1],*puVar7 + 0x4a,*(int *)(puVar7 + 0x12) + -1);
    if (iVar1 < 0) {
      uVar3 = *puVar2;
      uVar5 = 0x4a;
      goto LAB_0010114c;
    }
    iVar1 = regmap_write(puVar2[1],*puVar7 + 0x44,
                         *(uint *)(puVar7 + 0x10) & 0xf | (uint)(byte)puVar7[2] << 7);
    if (iVar1 < 0) {
      uVar3 = *puVar2;
      uVar5 = 0x44;
      goto LAB_0010114c;
    }
  }
  iVar1 = regmap_write(puVar2[1],*puVar7 + 0x46,(ulong)(byte)puVar7[1] << 7);
  if (-1 < iVar1) {
    return iVar1;
  }
  uVar3 = *puVar2;
  uVar5 = 0x46;
LAB_0010114c:
  _dev_err(uVar3,"write 0x%x failed\n",uVar5);
  return iVar1;
}



//------------------------------------------------------------
// pmic_gpio_config_get @ 0010116c size=260
// signature: undefined pmic_gpio_config_get(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_gpio_config_get(long param_1,uint param_2,ulong *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  
  uVar2 = 0xffffffea;
  uVar5 = (uint)(byte)*param_3;
  if (0x83 < uVar5 - 1) {
    return uVar2;
  }
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 0x10);
  switch(uVar5) {
  case 1:
    if (*(int *)(lVar4 + 0x18) != 5) {
      return uVar2;
    }
    goto LAB_0010121c;
  case 2:
    if (*(char *)(lVar4 + 2) != '\0') {
      return uVar2;
    }
    goto LAB_0010121c;
  case 3:
    if (*(int *)(lVar4 + 0x18) != 4) {
      return uVar2;
    }
    goto LAB_0010121c;
  default:
    goto switchD_001011ac_caseD_4;
  case 5:
    iVar1 = *(int *)(lVar4 + 0x18);
    goto joined_r0x0010120c;
  case 6:
    uVar3 = 1;
    if (*(int *)(lVar4 + 0x14) != 1) {
      return uVar2;
    }
    break;
  case 7:
    if (*(int *)(lVar4 + 0x14) != 2) {
      return uVar2;
    }
    goto LAB_0010121c;
  case 8:
    iVar1 = *(int *)(lVar4 + 0x14);
joined_r0x0010120c:
    if (iVar1 != 0) {
switchD_001011ac_caseD_4:
      return uVar2;
    }
    goto LAB_0010121c;
  case 0xc:
    if (*(char *)(lVar4 + 7) == '\0') {
      return uVar2;
    }
LAB_0010121c:
    uVar3 = 1;
    break;
  case 0x11:
    uVar3 = (uint)*(byte *)(lVar4 + 4);
    break;
  case 0x12:
    uVar3 = (uint)*(byte *)(lVar4 + 6);
    break;
  case 0x15:
    uVar3 = *(uint *)(lVar4 + 0x10);
    break;
  case 0x80:
    uVar3 = *(uint *)(lVar4 + 0x18);
    break;
  case 0x81:
    uVar3 = *(uint *)(lVar4 + 0x1c);
    break;
  case 0x82:
    uVar3 = *(uint *)(lVar4 + 0x24);
    break;
  case 0x83:
    uVar3 = (uint)*(byte *)(lVar4 + 8);
    break;
  case 0x84:
    uVar3 = *(uint *)(lVar4 + 0x28);
  }
  *param_3 = (ulong)(uVar5 | uVar3 << 8);
  return 0;
}



//------------------------------------------------------------
// pmic_gpio_config_set @ 00101274 size=916
// signature: undefined pmic_gpio_config_set(void)
// callers: [pmic_gpio_direction_output, pmic_gpio_direction_input, pmic_gpio_set, pmic_gpio_restore, pmic_gpio_resume]
//------------------------------------------------------------

int pmic_gpio_config_set(long param_1,ulong param_2,long param_3,int param_4)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  ushort *puVar8;
  
  puVar2 = (undefined8 *)pinctrl_dev_get_drvdata();
  puVar8 = *(ushort **)
            (*(long *)(*(long *)(param_1 + 0x10) + 8) + (param_2 & 0xffffffff) * 0x18 + 0x10);
  puVar8[1] = 0x101;
  if (param_4 != 0) {
    iVar5 = 0;
    do {
      uVar7 = *(undefined8 *)(param_3 + (long)iVar5 * 8);
      iVar1 = -0x16;
      uVar3 = (uint)uVar7;
      if (0x83 < (uVar3 & 0xff) - 1) {
        return -0x16;
      }
      uVar6 = (uint)((ulong)uVar7 >> 8) & 0xffffff;
      switch(uVar3 & 0xff) {
      case 1:
switchD_00101320_caseD_1:
        puVar8[0xc] = 5;
        puVar8[0xd] = 0;
        break;
      case 2:
        *(undefined1 *)(puVar8 + 1) = 0;
        break;
      case 3:
        if (uVar3 < 0x100) goto switchD_00101320_caseD_1;
        puVar8[0xc] = 4;
        puVar8[0xd] = 0;
        break;
      default:
        goto switchD_00101320_caseD_4;
      case 5:
        puVar8[0xc] = 0;
        puVar8[0xd] = 0;
        break;
      case 6:
        if (*(char *)((long)puVar8 + 5) == '\0') {
          return -0x16;
        }
        puVar8[10] = 1;
        puVar8[0xb] = 0;
        break;
      case 7:
        if (*(char *)((long)puVar8 + 5) == '\0') {
          return -0x16;
        }
        puVar8[10] = 2;
        puVar8[0xb] = 0;
        break;
      case 8:
        puVar8[10] = 0;
        puVar8[0xb] = 0;
        break;
      case 0xc:
        *(bool *)((long)puVar8 + 7) = 0xff < uVar3;
        break;
      case 0x11:
        *(undefined1 *)(puVar8 + 3) = 1;
        *(bool *)(puVar8 + 2) = 0xff < uVar3;
        break;
      case 0x12:
        *(bool *)(puVar8 + 3) = 0xff < uVar3;
        break;
      case 0x15:
        if (*(uint *)(puVar8 + 6) <= uVar6) {
          return -0x16;
        }
        *(uint *)(puVar8 + 8) = uVar6;
        break;
      case 0x80:
        if (0x3ff < uVar3) {
          return -0x16;
        }
        *(uint *)(puVar8 + 0xc) = uVar6;
        break;
      case 0x81:
        if (0x3ff < uVar3) {
          return -0x16;
        }
        if (uVar6 == 1) {
          puVar8[0xe] = 1;
          puVar8[0xf] = 0;
        }
        else if (uVar6 == 3) {
          puVar8[0xe] = 3;
          puVar8[0xf] = 0;
        }
        else {
          *(uint *)(puVar8 + 0xe) = uVar6;
        }
        break;
      case 0x82:
        if (*(char *)((long)puVar8 + 9) == '\0') {
          return -0x16;
        }
        if (0x4ff < uVar3) {
          return -0x16;
        }
        *(uint *)(puVar8 + 0x12) = uVar6;
        break;
      case 0x83:
        if (*(char *)((long)puVar8 + 9) == '\0') {
          return -0x16;
        }
        *(undefined1 *)(puVar8 + 4) = 1;
        break;
      case 0x84:
        if (0x4ff < uVar3) {
          return -0x16;
        }
        *(uint *)(puVar8 + 0x14) = uVar6;
      }
      iVar5 = iVar5 + 1;
    } while (param_4 != iVar5);
  }
  iVar1 = regmap_write(puVar2[1],*puVar8 + 0x41,*(undefined4 *)(puVar8 + 8));
  if (iVar1 < 0) {
    uVar7 = 0x41;
    goto LAB_001015dc;
  }
  iVar1 = regmap_write(puVar2[1],*puVar8 + 0x42,*(undefined4 *)(puVar8 + 0xc));
  if (iVar1 < 0) {
    uVar7 = 0x42;
    goto LAB_001015dc;
  }
  iVar1 = regmap_write(puVar2[1],*puVar8 + 0x45,*(uint *)(puVar8 + 0xe) | *(int *)(puVar8 + 10) << 4
                      );
  if (iVar1 < 0) {
    uVar7 = 0x45;
    goto LAB_001015dc;
  }
  if (*(int *)(puVar8 + 0x14) == 0) {
    uVar4 = 0;
  }
  else {
    uVar3 = *(int *)(puVar8 + 0x14) - 1;
    if (*(char *)((long)puVar8 + 9) == '\0') {
      uVar4 = 1L << ((ulong)uVar3 & 0x3f);
    }
    else {
      uVar4 = (ulong)(uVar3 | 0x80);
    }
  }
  iVar1 = regmap_write(puVar2[1],*puVar8 + 0x43,uVar4);
  if (iVar1 < 0) {
    uVar7 = 0x43;
    goto LAB_001015dc;
  }
  if ((char)puVar8[4] == '\0') {
    uVar3 = (uint)(byte)puVar8[3];
    if (((byte)puVar8[3] != 0) && (*(char *)((long)puVar8 + 7) != '\0')) {
      uVar3 = 2;
    }
  }
  else {
    uVar3 = 3;
  }
  if (*(char *)((long)puVar8 + 9) == '\0') {
    iVar1 = regmap_write(puVar2[1],*puVar8 + 0x40,
                         *(int *)(puVar8 + 0x10) << 1 | uVar3 << 4 | (uint)(byte)puVar8[2]);
    if (iVar1 < 0) goto LAB_001015c8;
  }
  else {
    iVar1 = regmap_write(puVar2[1],*puVar8 + 0x40,uVar3);
    if (iVar1 < 0) {
LAB_001015c8:
      uVar7 = 0x40;
      goto LAB_001015dc;
    }
    iVar1 = regmap_write(puVar2[1],*puVar8 + 0x4a,*(int *)(puVar8 + 0x12) + -1);
    if (iVar1 < 0) {
      uVar7 = 0x4a;
      goto LAB_001015dc;
    }
    iVar1 = regmap_write(puVar2[1],*puVar8 + 0x44,
                         *(uint *)(puVar8 + 0x10) & 0xf | (uint)(byte)puVar8[2] << 7);
    if (iVar1 < 0) {
      uVar7 = 0x44;
      goto LAB_001015dc;
    }
  }
  iVar1 = regmap_write(puVar2[1],*puVar8 + 0x46,(ulong)(byte)puVar8[1] << 7);
  if (-1 < iVar1) {
    return iVar1;
  }
  uVar7 = 0x46;
LAB_001015dc:
  _dev_err(*puVar2,"write 0x%x failed\n",uVar7);
switchD_00101320_caseD_4:
  return iVar1;
}



//------------------------------------------------------------
// pmic_gpio_config_dbg_show @ 0010160c size=664
// signature: undefined pmic_gpio_config_dbg_show(void)
// callers: [pmic_gpio_dbg_show]
//------------------------------------------------------------

void pmic_gpio_config_dbg_show(long param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  undefined8 *puVar7;
  ushort *puVar8;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  puVar7 = (undefined8 *)pinctrl_dev_get_drvdata();
  puVar8 = *(ushort **)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_3 * 0x18 + 0x10);
  seq_printf(param_2," gpio%-2d:",param_3 + 1);
  local_3c = 0;
  iVar6 = regmap_read(puVar7[1],*puVar8 + 0x46,&local_3c);
  if (iVar6 < 0) {
    _dev_err(*puVar7,"read 0x%x failed\n",0x46);
  }
  else if (0x7f < local_3c) {
    if (*(char *)((long)puVar8 + 7) != '\0') {
      local_3c = 0;
      iVar6 = regmap_read(puVar7[1],*puVar8 + 0x10,&local_3c);
      if (iVar6 < 0) {
        _dev_err(*puVar7,"read 0x%x failed\n",0x10);
        goto LAB_00101840;
      }
      if (local_3c < 0) goto LAB_00101840;
      *(byte *)(puVar8 + 2) = (byte)local_3c & 1;
    }
    uVar3 = *(uint *)(puVar8 + 0x10);
    uVar1 = uVar3 + 2;
    if (uVar3 < 4 || *(char *)((long)puVar8 + 9) != '\0') {
      uVar1 = uVar3;
    }
    if ((char)puVar8[4] == '\0') {
      puVar2 = &DAT_0010601d;
      if ((char)puVar8[3] != '\0') {
        puVar2 = &DAT_00105f08;
      }
      seq_printf(param_2," %-4s",puVar2);
    }
    else {
      seq_puts(param_2," analog-pass");
    }
    puVar2 = &DAT_00106177;
    if ((char)puVar8[2] != '\0') {
      puVar2 = &DAT_00106223;
    }
    seq_printf(param_2," %-4s",puVar2);
    if (9 < uVar1) {
LAB_0010189c:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1018a0);
      (*pcVar5)();
    }
    seq_printf(param_2," %-7s",(&pmic_gpio_functions)[uVar1]);
    seq_printf(param_2," vin-%d",*(undefined4 *)(puVar8 + 8));
    if (5 < *(uint *)(puVar8 + 0xc)) goto LAB_0010189c;
    seq_printf(param_2," %-27s",(&pmic_gpio_config_dbg_show_biases)[*(uint *)(puVar8 + 0xc)]);
    if (2 < *(uint *)(puVar8 + 10)) goto LAB_0010189c;
    seq_printf(param_2," %-10s",(&pmic_gpio_config_dbg_show_buffer_types)[*(uint *)(puVar8 + 10)]);
    if (3 < *(uint *)(puVar8 + 0xe)) goto LAB_0010189c;
    seq_printf(param_2," %-7s",(&pmic_gpio_config_dbg_show_strengths)[*(uint *)(puVar8 + 0xe)]);
    seq_printf(param_2," atest-%d",*(undefined4 *)(puVar8 + 0x12));
    seq_printf(param_2," dtest-%d",*(undefined4 *)(puVar8 + 0x14));
    goto LAB_00101840;
  }
  seq_puts(param_2,&DAT_0010615a);
LAB_00101840:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_gpio_direction_input @ 001018a8 size=112
// signature: undefined pmic_gpio_direction_input(void)
// callers: []
//------------------------------------------------------------

void pmic_gpio_direction_input(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = 0x10c;
  pmic_gpio_config_set(*(undefined8 *)(lVar1 + 0x10),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_gpio_direction_output @ 0010191c size=120
// signature: undefined pmic_gpio_direction_output(void)
// callers: []
//------------------------------------------------------------

void pmic_gpio_direction_output(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = (ulong)(param_3 << 8 | 0x11);
  pmic_gpio_config_set(*(undefined8 *)(lVar1 + 0x10),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_gpio_get @ 00101998 size=228
// signature: undefined pmic_gpio_get(void)
// callers: []
//------------------------------------------------------------

uint pmic_gpio_get(undefined8 param_1,ulong param_2)

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
  if ((char)puVar4[1] == '\0') {
    uVar2 = 0xffffffea;
  }
  else if (*(char *)((long)puVar4 + 7) == '\0') {
    uVar2 = (uint)(byte)puVar4[2];
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
        *(char *)(puVar4 + 2) = (char)uVar2;
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
// pmic_gpio_set @ 00101a80 size=120
// signature: undefined pmic_gpio_set(void)
// callers: []
//------------------------------------------------------------

void pmic_gpio_set(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = (ulong)(param_3 << 8 | 0x11);
  pmic_gpio_config_set(*(undefined8 *)(lVar1 + 0x10),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pmic_gpio_dbg_show @ 00101afc size=132
// signature: undefined pmic_gpio_dbg_show(void)
// callers: []
//------------------------------------------------------------

void pmic_gpio_dbg_show(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = gpiochip_get_data(param_2);
  if (*(short *)(param_2 + 0xac) != 0) {
    uVar2 = 0;
    do {
      pmic_gpio_config_dbg_show(*(undefined8 *)(lVar1 + 0x10),param_1,uVar2);
      seq_puts(param_1,&DAT_0010621a);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)(param_2 + 0xac));
  }
  return;
}



//------------------------------------------------------------
// pmic_gpio_of_xlate @ 00101b84 size=44
// signature: undefined pmic_gpio_of_xlate(void)
// callers: []
//------------------------------------------------------------

int pmic_gpio_of_xlate(long param_1,long param_2,undefined4 *param_3)

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
// pmic_gpio_irq_mask @ 00101bb4 size=56
// signature: undefined pmic_gpio_irq_mask(void)
// callers: []
//------------------------------------------------------------

void pmic_gpio_irq_mask(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  irq_chip_mask_parent();
  gpiochip_disable_irq(uVar1,*(undefined4 *)(param_1 + 8));
  return;
}



//------------------------------------------------------------
// pmic_gpio_irq_unmask @ 00101bf0 size=56
// signature: undefined pmic_gpio_irq_unmask(void)
// callers: []
//------------------------------------------------------------

void pmic_gpio_irq_unmask(long param_1)

{
  gpiochip_enable_irq(*(undefined8 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 8));
  irq_chip_unmask_parent(param_1);
  return;
}



//------------------------------------------------------------
// pmic_gpio_resume @ 00101c2c size=228
// signature: undefined pmic_gpio_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int pmic_gpio_resume(long param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  
  if (_pm_suspend_target_state == 3) {
    puVar5 = *(undefined8 **)(param_1 + 0x98);
    lVar4 = puVar5[2];
    uVar1 = *(uint *)(*(long *)(lVar4 + 0x10) + 0x10);
    if (uVar1 != 0) {
      lVar6 = 0;
      iVar3 = 0;
      iVar2 = 0;
      do {
        if (*(char *)(*(long *)(*(long *)(*(long *)(lVar4 + 0x10) + 8) + lVar6 + 0x10) + 3) != '\0')
        {
          iVar2 = pmic_gpio_config_set(lVar4,iVar3,0,0);
          if (iVar2 < 0) {
            _dev_err(*puVar5,"Failed to restore pin %s[%d] ret=%d\n",
                     *(undefined8 *)(*(long *)(*(long *)(lVar4 + 0x10) + 8) + lVar6 + 8),iVar3,iVar2
                    );
            return iVar2;
          }
        }
        iVar3 = iVar3 + 1;
        lVar6 = lVar6 + 0x18;
      } while ((ulong)uVar1 * 0x18 != lVar6);
      return iVar2;
    }
  }
  return 0;
}



//------------------------------------------------------------
// pmic_gpio_restore @ 00101d14 size=212
// signature: undefined pmic_gpio_restore(void)
// callers: []
//------------------------------------------------------------

int pmic_gpio_restore(long param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  lVar4 = puVar5[2];
  uVar1 = *(uint *)(*(long *)(lVar4 + 0x10) + 0x10);
  if (uVar1 == 0) {
    iVar2 = 0;
  }
  else {
    lVar6 = 0;
    iVar3 = 0;
    iVar2 = 0;
    do {
      if (*(char *)(*(long *)(*(long *)(*(long *)(lVar4 + 0x10) + 8) + lVar6 + 0x10) + 3) != '\0') {
        iVar2 = pmic_gpio_config_set(lVar4,iVar3,0,0);
        if (iVar2 < 0) {
          _dev_err(*puVar5,"Failed to restore pin %s[%d] ret=%d\n",
                   *(undefined8 *)(*(long *)(*(long *)(lVar4 + 0x10) + 8) + lVar6 + 8),iVar3,iVar2);
          return iVar2;
        }
      }
      iVar3 = iVar3 + 1;
      lVar6 = lVar6 + 0x18;
    } while ((ulong)uVar1 * 0x18 != lVar6);
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00101dec size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pmic_gpio_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101e1c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pmic_gpio_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00108000 size=1
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
// platform_driver_unregister @ 00108008 size=1
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
// of_property_read_variable_u32_array @ 00108010 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_match_data @ 00108018 size=1
// signature: undefined device_get_match_data(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00108020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00108028 size=1
// signature: undefined dev_get_regmap(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00108030 size=1
// signature: undefined regmap_read(void)
// callers: [pmic_gpio_probe, pmic_gpio_get, pmic_gpio_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00108038 size=1
// signature: undefined _dev_err(void)
// callers: [pmic_gpio_set_mux, pmic_gpio_probe, pmic_gpio_restore, pmic_gpio_get, pmic_gpio_config_dbg_show, pmic_gpio_resume, pmic_gpio_config_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00108040 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_register @ 00108048 size=1
// signature: undefined devm_pinctrl_register(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_find_parent @ 00108050 size=1
// signature: undefined of_irq_find_parent(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_find_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_find_matching_fwspec @ 00108058 size=1
// signature: undefined irq_find_matching_fwspec(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_find_matching_fwspec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_data_with_key @ 00108068 size=1
// signature: undefined gpiochip_add_data_with_key(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_data_with_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00108070 size=1
// signature: undefined of_find_property(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_pin_range @ 00108078 size=1
// signature: undefined gpiochip_add_pin_range(void)
// callers: [pmic_gpio_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_pin_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_remove @ 00108080 size=1
// signature: undefined gpiochip_remove(void)
// callers: [pmic_gpio_probe, pmic_gpio_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pmic_gpio_direction_output, pmic_gpio_probe, pmic_gpio_direction_input, pmic_gpio_set, pmic_gpio_get, pmic_gpio_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_get_data @ 00108090 size=1
// signature: undefined gpiochip_get_data(void)
// callers: [pmic_gpio_direction_output, pmic_gpio_populate_parent_fwspec, pmic_gpio_direction_input, pmic_gpio_set, pmic_gpio_get, pmic_gpio_child_to_parent_hwirq, pmic_gpio_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_get_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map @ 00108098 size=1
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
// pinctrl_dev_get_drvdata @ 001080a0 size=1
// signature: undefined pinctrl_dev_get_drvdata(void)
// callers: [pmic_gpio_set_mux, pmic_gpio_config_dbg_show, pmic_gpio_config_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_dev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001080a8 size=1
// signature: undefined regmap_write(void)
// callers: [pmic_gpio_set_mux, pmic_gpio_config_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001080b0 size=1
// signature: undefined _printk(void)
// callers: [pmic_gpio_set_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001080b8 size=1
// signature: undefined seq_printf(void)
// callers: [pmic_gpio_config_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 001080c0 size=1
// signature: undefined seq_puts(void)
// callers: [pmic_gpio_config_dbg_show, pmic_gpio_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_mask_parent @ 001080c8 size=1
// signature: undefined irq_chip_mask_parent(void)
// callers: [pmic_gpio_irq_mask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_mask_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_disable_irq @ 001080d0 size=1
// signature: undefined gpiochip_disable_irq(void)
// callers: [pmic_gpio_irq_mask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_enable_irq @ 001080d8 size=1
// signature: undefined gpiochip_enable_irq(void)
// callers: [pmic_gpio_irq_unmask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_unmask_parent @ 001080e0 size=1
// signature: undefined irq_chip_unmask_parent(void)
// callers: [pmic_gpio_irq_unmask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_unmask_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



