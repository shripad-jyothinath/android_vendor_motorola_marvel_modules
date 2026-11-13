// Decompiled by Ghidra 12.2
// Program: spmi-pmic-arb-debug.ko
// Image base: 00100000

//------------------------------------------------------------
// spmi_pmic_arb_debug_probe @ 0010024c size=720
// signature: undefined spmi_pmic_arb_debug_probe(void)
// callers: []
//------------------------------------------------------------

ulong spmi_pmic_arb_debug_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong *puVar11;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_4c = 0;
  iVar4 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,fuse-disable-bit",&local_4c,1,0);
  if ((-1 < iVar4) ||
     (iVar5 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,fuse-enable-bit",&local_4c,1,0),
     -1 < iVar5)) {
    if (0x1f < local_4c) {
      pcVar3 = "disable";
      if (iVar4 < 0) {
        pcVar3 = "enable";
      }
      _dev_err(lVar1,"qcom,fuse-%s-bit supports values 0 to 31, but %u specified\n",pcVar3);
      uVar8 = 0xffffffea;
      goto LAB_00100440;
    }
    plVar6 = (long *)platform_get_resource_byname(param_1,0x200,&DAT_001010c3);
    if (plVar6 == (long *)0x0) {
      _dev_err(lVar1,"fuse address not specified\n");
      uVar8 = 0xffffffea;
      goto LAB_00100440;
    }
    uVar2 = 0x68000000000713;
    if (arm64_use_ng_mappings != '\0') {
      uVar2 = 0x68000000000f13;
    }
    lVar7 = ioremap_prot(*plVar6,(plVar6[1] - *plVar6) + 1,uVar2);
    if (lVar7 == 0) {
      uVar8 = 0xffffffea;
      goto LAB_00100440;
    }
    uVar8 = readl_relaxed();
    iounmap(lVar7);
    if (-1 < iVar4 != (((uVar8 & 0xffffffff) >> ((ulong)local_4c & 0x3f) & 1) == 0)) {
      _dev_err(lVar1,"SPMI PMIC arbiter debug bus disabled by fuse\n");
      uVar8 = 0xffffffed;
      goto LAB_00100440;
    }
  }
  lVar7 = spmi_controller_alloc(lVar1,0x18);
  if (lVar7 == 0) {
    uVar8 = 0xfffffff4;
    goto LAB_00100440;
  }
  puVar11 = *(ulong **)(lVar7 + 0x98);
  lVar9 = platform_get_resource_byname(param_1,0x200,&DAT_00101062);
  if (lVar9 == 0) {
    _dev_err(lVar1,"core address not specified\n");
    uVar8 = 0xffffffea;
  }
  else {
    uVar8 = devm_ioremap_resource(lVar7,lVar9);
    *puVar11 = uVar8;
    if (uVar8 < 0xfffffffffffff001) {
      lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"clock-names",0);
      if (lVar9 != 0) {
        uVar8 = devm_clk_get(lVar1,"core_clk");
        puVar11[2] = uVar8;
        if (0xfffffffffffff000 < uVar8) {
          if ((int)uVar8 == -0x205) {
            uVar8 = 0xfffffdfb;
          }
          else {
            _dev_err(lVar1,"unable to request core clock, rc=%d\n",uVar8 & 0xffffffff);
          }
          goto LAB_00100438;
        }
      }
      *(long *)(param_1 + 0xa8) = lVar7;
      *(undefined4 *)(puVar11 + 1) = 0;
      *(code **)(lVar7 + 0x398) = pmic_arb_debug_cmd;
      *(code **)(lVar7 + 0x3a0) = pmic_arb_debug_read_cmd;
      *(code **)(lVar7 + 0x3a8) = pmic_arb_debug_write_cmd;
      uVar10 = spmi_controller_add(lVar7);
      uVar8 = uVar10 & 0xffffffff;
      if ((int)uVar10 == 0) {
        _dev_info(lVar7,"SPMI PMIC arbiter debug bus controller added\n");
        goto LAB_00100440;
      }
    }
    else {
      uVar8 = uVar8 & 0xffffffff;
    }
  }
LAB_00100438:
  put_device(lVar7);
LAB_00100440:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// spmi_pmic_arb_debug_remove @ 00100520 size=60
// signature: undefined spmi_pmic_arb_debug_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 spmi_pmic_arb_debug_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  spmi_controller_remove(lVar1);
  if (lVar1 != 0) {
    put_device(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 0010055c size=124
// signature: undefined readl_relaxed(void)
// callers: [spmi_pmic_arb_debug_probe, pmic_arb_debug_read_cmd, pmic_arb_debug_issue_command]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1005a4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// pmic_arb_debug_cmd @ 001005dc size=28
// signature: undefined pmic_arb_debug_cmd(void)
// callers: []
//------------------------------------------------------------

undefined4 pmic_arb_debug_cmd(undefined8 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffea;
  if (0xfffffffb < (param_2 & 0xff) - 0x14) {
    uVar1 = 0xffffffa1;
  }
  return uVar1;
}



//------------------------------------------------------------
// pmic_arb_debug_read_cmd @ 001005fc size=364
// signature: undefined pmic_arb_debug_read_cmd(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_debug_read_cmd
              (long param_1,byte param_2,undefined4 param_3,undefined4 param_4,long param_5,
              ulong param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  
  plVar7 = *(long **)(param_1 + 0x98);
  if ((char)param_2 < '`') {
    if ((param_2 & 0xf0) == 0x20) {
      uVar6 = 0xd;
    }
    else {
      if ((param_2 & 0xf8) != 0x38) {
        return -0x16;
      }
      uVar6 = 1;
    }
  }
  else {
    uVar6 = 0xf;
  }
  lVar5 = plVar7[2];
  iVar2 = clk_prepare(lVar5);
  if (iVar2 == 0) {
    iVar2 = clk_enable(lVar5);
    if (iVar2 == 0) {
      uVar3 = _raw_spin_lock_irqsave(plVar7 + 1);
      iVar2 = pmic_arb_debug_issue_command(param_1,uVar6,param_3,param_4,param_6);
      if ((iVar2 == 0) && (param_6 != 0)) {
        uVar4 = 0;
        do {
          uVar1 = readl_relaxed(*plVar7 + (ulong)((int)uVar4 * 4 + 0x38));
          *(undefined1 *)(param_5 + uVar4) = uVar1;
          uVar4 = (ulong)((int)uVar4 + 1);
        } while (uVar4 < param_6);
      }
      _raw_spin_unlock_irqrestore(plVar7 + 1,uVar3);
      lVar5 = plVar7[2];
      clk_disable(lVar5);
      clk_unprepare(lVar5);
      return iVar2;
    }
    clk_unprepare(lVar5);
  }
  _printk(&DAT_0010110f,"pmic_arb_debug_read_cmd",iVar2);
  return iVar2;
}



//------------------------------------------------------------
// pmic_arb_debug_write_cmd @ 0010076c size=408
// signature: undefined pmic_arb_debug_write_cmd(void)
// callers: []
//------------------------------------------------------------

int pmic_arb_debug_write_cmd
              (long param_1,uint param_2,undefined4 param_3,undefined4 param_4,long param_5,
              ulong param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  
  if (param_6 < 9) {
    plVar6 = *(long **)(param_1 + 0x98);
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
    lVar5 = plVar6[2];
    iVar1 = clk_prepare(lVar5);
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar5);
      if (iVar1 == 0) {
        uVar2 = _raw_spin_lock_irqsave(plVar6 + 1);
        if (param_6 != 0) {
          uVar4 = 0;
          do {
            writel_relaxed(*(undefined1 *)(param_5 + uVar4),*plVar6 + (ulong)((int)uVar4 * 4 + 0x18)
                          );
            uVar4 = (ulong)((int)uVar4 + 1);
          } while (uVar4 < param_6);
        }
        iVar1 = pmic_arb_debug_issue_command(param_1,uVar3,param_3,param_4,param_6);
        _raw_spin_unlock_irqrestore(plVar6 + 1,uVar2);
        lVar5 = plVar6[2];
        clk_disable(lVar5);
        clk_unprepare(lVar5);
        return iVar1;
      }
      clk_unprepare(lVar5);
    }
    _printk(&DAT_0010110f,"pmic_arb_debug_write_cmd",iVar1);
  }
  else {
    _dev_err(param_1,"pmic-arb supports 1 to %d bytes per transaction, but %zu requested\n",8,
             param_6);
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// pmic_arb_debug_issue_command @ 00100904 size=400
// signature: undefined pmic_arb_debug_issue_command(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

undefined8
pmic_arb_debug_issue_command(long param_1,uint param_2,uint param_3,uint param_4,undefined8 param_5)

{
  bool bVar1;
  uint uVar2;
  undefined8 uVar3;
  char *pcVar4;
  int iVar5;
  long *plVar6;
  
  uVar2 = (int)param_5 - 1U & 0xff;
  if (uVar2 < 8) {
    param_3 = param_3 & 0xff;
    if (param_3 < 0x10) {
      plVar6 = *(long **)(param_1 + 0x98);
      writel_relaxed(param_4 & 0xff,*plVar6 + 0xc);
      writel_relaxed(param_4 >> 8 & 0xff,*plVar6 + 8);
      writel_relaxed(param_3 | uVar2 << 4,*plVar6 + 4);
      writel_relaxed((param_2 & 0xff) << 1,*plVar6);
      plVar6 = *(long **)(param_1 + 0x98);
      iVar5 = -100;
      do {
        uVar2 = readl_relaxed(*plVar6 + 0x14);
        if ((uVar2 & 1) != 0) {
          if ((uVar2 >> 2 & 1) != 0) {
            _dev_err(param_1,"%s: transaction denied (0x%x)\n","pmic_arb_debug_wait_for_done",uVar2)
            ;
            return 0xffffffff;
          }
          if ((uVar2 >> 1 & 1) == 0) {
            if ((uVar2 >> 3 & 1) == 0) {
              return 0;
            }
            pcVar4 = "%s: transaction dropped (0x%x)\n";
          }
          else {
            pcVar4 = "%s: transaction failed (0x%x)\n";
          }
          _dev_err(param_1,pcVar4,"pmic_arb_debug_wait_for_done",uVar2);
          return 0xfffffffb;
        }
        __const_udelay(0x10c7);
        bVar1 = iVar5 != -1;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      _dev_err(param_1,"%s: timeout, status 0x%x\n","pmic_arb_debug_wait_for_done",uVar2);
      uVar3 = 0xffffff92;
    }
    else {
      _dev_err(param_1,"pmic-arb supports sid 0 to %u, but %u requested\n",0xf,param_3);
      uVar3 = 0xffffffea;
    }
  }
  else {
    _dev_err(param_1,"pmic-arb supports 1 to %d bytes per transaction, but %zu requested\n",8,
             param_5);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// writel_relaxed @ 00100a94 size=132
// signature: undefined writel_relaxed(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_issue_command]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100aac,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100ae8,uVar1);
  return;
}



//------------------------------------------------------------
// init_module @ 00100b20 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&spmi_pmic_arb_debug_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100b50 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&spmi_pmic_arb_debug_driver);
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
// of_property_read_variable_u32_array @ 00102010 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00102018 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00102028 size=1
// signature: undefined ioremap_prot(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00102030 size=1
// signature: undefined iounmap(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_alloc @ 00102038 size=1
// signature: undefined spmi_controller_alloc(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00102040 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102048 size=1
// signature: undefined of_find_property(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00102050 size=1
// signature: undefined devm_clk_get(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_add @ 00102058 size=1
// signature: undefined spmi_controller_add(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00102060 size=1
// signature: undefined put_device(void)
// callers: [spmi_pmic_arb_debug_probe, spmi_pmic_arb_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102068 size=1
// signature: undefined _dev_err(void)
// callers: [pmic_arb_debug_write_cmd, spmi_pmic_arb_debug_probe, pmic_arb_debug_issue_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102070 size=1
// signature: undefined _dev_info(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102078 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [spmi_pmic_arb_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spmi_controller_remove @ 00102080 size=1
// signature: undefined spmi_controller_remove(void)
// callers: [spmi_pmic_arb_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spmi_controller_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00102088 size=1
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
// log_post_read_mmio @ 00102090 size=1
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
// clk_prepare @ 00102098 size=1
// signature: undefined clk_prepare(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001020a0 size=1
// signature: undefined clk_enable(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001020a8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001020b0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001020b8 size=1
// signature: undefined clk_disable(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001020c0 size=1
// signature: undefined clk_unprepare(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001020c8 size=1
// signature: undefined _printk(void)
// callers: [pmic_arb_debug_write_cmd, pmic_arb_debug_read_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001020d0 size=1
// signature: undefined __const_udelay(void)
// callers: [pmic_arb_debug_issue_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001020d8 size=1
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
// log_post_write_mmio @ 001020e0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



