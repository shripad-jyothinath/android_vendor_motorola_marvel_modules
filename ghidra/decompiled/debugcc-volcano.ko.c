// Decompiled by Ghidra 12.2
// Program: debugcc-volcano.ko
// Image base: 00100000

//------------------------------------------------------------
// clk_debug_volcano_probe @ 0010008c size=1008
// signature: undefined clk_debug_volcano_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong clk_debug_volcano_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  undefined **ppuVar8;
  long lVar9;
  
  lVar1 = param_1 + 0x10;
  uVar3 = devm_clk_get(lVar1,"xo_clk_src");
  if (uVar3 < 0xfffffffffffff001) {
    debug_mux_priv = uVar3;
    if (((((((_DAT_00100730 == 0) || (0xfffffffffffff000 < _DAT_00100730)) &&
           (uVar2 = map_debug_bases(param_1,"qcom,mccc",&mc_cc_debug_mux), uVar2 != 0)) &&
          (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)) ||
         (((_DAT_001007b0 == 0 || (0xfffffffffffff000 < _DAT_001007b0)) &&
          ((uVar2 = map_debug_bases(param_1,"qcom,videocc",&video_cc_debug_mux), uVar2 != 0 &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
        ((((_DAT_00100830 == 0 || (0xfffffffffffff000 < _DAT_00100830)) &&
          ((uVar2 = map_debug_bases(param_1,"qcom,gxclkctl",&gx_clkctl_debug_mux), uVar2 != 0 &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))) ||
         ((((_DAT_001008b0 == 0 || (0xfffffffffffff000 < _DAT_001008b0)) &&
           (uVar2 = map_debug_bases(param_1,"qcom,gpucc",&gpu_cc_debug_mux), uVar2 != 0)) &&
          (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
       (((((_DAT_00100930 == 0 || (0xfffffffffffff000 < _DAT_00100930)) &&
          ((uVar2 = map_debug_bases(param_1,"qcom,dispcc",&disp_cc_debug_mux), uVar2 != 0 &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))) ||
         (((_DAT_001009b0 == 0 || (0xfffffffffffff000 < _DAT_001009b0)) &&
          ((uVar2 = map_debug_bases(param_1,"qcom,camcc",&cam_cc_debug_mux), uVar2 != 0 &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
        (((((_DAT_00100a30 == 0 || (0xfffffffffffff000 < _DAT_00100a30)) &&
           (uVar2 = map_debug_bases(param_1,"qcom,apsscc",&apss_cc_debug_mux), uVar2 != 0)) &&
          (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)) ||
         (((_DAT_001006b0 == 0 || (0xfffffffffffff000 < _DAT_001006b0)) &&
          ((uVar2 = map_debug_bases(param_1,"qcom,gcc",&gcc_debug_mux), uVar2 != 0 &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))))))) goto LAB_001000d0;
    lVar9 = 0;
    do {
      lVar7 = *(long *)((long)&debugcc_volcano_hws + lVar9);
      uVar3 = devm_clk_register(lVar1,lVar7);
      if (0xfffffffffffff000 < uVar3) {
        if (*(undefined8 **)(lVar7 + 0x10) == (undefined8 *)0x0) {
          uVar5 = clk_hw_get_name(lVar7);
        }
        else {
          uVar5 = **(undefined8 **)(lVar7 + 0x10);
        }
        _dev_err(lVar1,"Unable to register %s, err:(%ld)\n",uVar5,uVar3);
        goto LAB_001000d0;
      }
      lVar9 = lVar9 + 8;
    } while (lVar9 != 0x178);
    ppuVar8 = (undefined **)&mc_cc_debug_mux;
    uVar3 = devm_clk_register_debug_mux(lVar1,&mc_cc_debug_mux);
    if ((int)uVar3 == 0) {
      ppuVar8 = &video_cc_debug_mux;
      uVar3 = devm_clk_register_debug_mux(lVar1,&video_cc_debug_mux);
      if ((int)uVar3 == 0) {
        ppuVar8 = &gx_clkctl_debug_mux;
        uVar3 = devm_clk_register_debug_mux(lVar1,&gx_clkctl_debug_mux);
        if ((int)uVar3 == 0) {
          ppuVar8 = &gpu_cc_debug_mux;
          uVar3 = devm_clk_register_debug_mux(lVar1,&gpu_cc_debug_mux);
          if ((int)uVar3 == 0) {
            ppuVar8 = &disp_cc_debug_mux;
            uVar3 = devm_clk_register_debug_mux(lVar1,&disp_cc_debug_mux);
            if ((int)uVar3 == 0) {
              ppuVar8 = &cam_cc_debug_mux;
              uVar3 = devm_clk_register_debug_mux(lVar1,&cam_cc_debug_mux);
              if ((int)uVar3 == 0) {
                ppuVar8 = &apss_cc_debug_mux;
                uVar3 = devm_clk_register_debug_mux(lVar1,&apss_cc_debug_mux);
                if ((int)uVar3 == 0) {
                  ppuVar8 = &gcc_debug_mux;
                  uVar3 = devm_clk_register_debug_mux(lVar1,&gcc_debug_mux);
                  if ((int)uVar3 == 0) {
                    uVar4 = clk_debug_measure_register(&DAT_001006e8);
                    uVar3 = uVar4 & 0xffffffff;
                    if ((int)uVar4 == 0) {
                      _dev_info(lVar1,"Registered debug measure clocks\n");
                      goto LAB_001000d0;
                    }
                    pcVar6 = "Could not register Measure clocks\n";
                    goto LAB_001003f4;
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar3 = uVar3 & 0xffffffff;
    if ((undefined8 *)ppuVar8[0xd] == (undefined8 *)0x0) {
      uVar5 = clk_hw_get_name(ppuVar8 + 0xb);
    }
    else {
      uVar5 = *(undefined8 *)ppuVar8[0xd];
    }
    _dev_err(lVar1,"Unable to register mux clk %s, err:(%d)\n",uVar5,uVar3);
  }
  else {
    if (uVar3 == 0xfffffffffffffdfb) goto LAB_001000d0;
    pcVar6 = "Unable to get xo clock\n";
LAB_001003f4:
    _dev_err(lVar1,pcVar6);
  }
LAB_001000d0:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// init_module @ 00100480 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&clk_debug_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00106000 size=1
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
// devm_clk_get @ 00106008 size=1
// signature: undefined devm_clk_get(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// map_debug_bases @ 00106010 size=1
// signature: undefined map_debug_bases(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void map_debug_bases(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register @ 00106018 size=1
// signature: undefined devm_clk_register(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register_debug_mux @ 00106020 size=1
// signature: undefined devm_clk_register_debug_mux(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register_debug_mux(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_debug_measure_register @ 00106028 size=1
// signature: undefined clk_debug_measure_register(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_debug_measure_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00106030 size=1
// signature: undefined _dev_info(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106038 size=1
// signature: undefined _dev_err(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_name @ 00106040 size=1
// signature: undefined clk_hw_get_name(void)
// callers: [clk_debug_volcano_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



