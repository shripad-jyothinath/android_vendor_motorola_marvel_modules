// Decompiled by Ghidra 12.2
// Program: debugcc-cliffs.ko
// Image base: 00100000

//------------------------------------------------------------
// clk_debug_cliffs_probe @ 0010008c size=908
// signature: undefined clk_debug_cliffs_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong clk_debug_cliffs_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined **ppuVar7;
  long lVar8;
  
  lVar1 = param_1 + 0x10;
  uVar3 = devm_clk_get(lVar1,"xo_clk_src");
  if (uVar3 < 0xfffffffffffff001) {
    debug_mux_priv = uVar3;
    if (((((((((_DAT_001006c0 == 0) || (0xfffffffffffff000 < _DAT_001006c0)) &&
             (uVar2 = map_debug_bases(param_1,"qcom,mccc",&mc_cc_debug_mux), uVar2 != 0)) &&
            (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)) ||
           (((_DAT_00100740 == 0 || (0xfffffffffffff000 < _DAT_00100740)) &&
            ((uVar2 = map_debug_bases(param_1,"qcom,videocc",&video_cc_debug_mux), uVar2 != 0 &&
             (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
          (((_DAT_001007c0 == 0 || (0xfffffffffffff000 < _DAT_001007c0)) &&
           ((uVar2 = map_debug_bases(param_1,"qcom,gpucc",&gpu_cc_debug_mux), uVar2 != 0 &&
            (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
         (((((_DAT_00100840 == 0 || (0xfffffffffffff000 < _DAT_00100840)) &&
            (uVar2 = map_debug_bases(param_1,"qcom,dispcc",&disp_cc_debug_mux), uVar2 != 0)) &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)) ||
          (((_DAT_001008c0 == 0 || (0xfffffffffffff000 < _DAT_001008c0)) &&
           ((uVar2 = map_debug_bases(param_1,"qcom,camcc",&cam_cc_debug_mux), uVar2 != 0 &&
            (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))))) ||
        (((_DAT_00100940 == 0 || (0xfffffffffffff000 < _DAT_00100940)) &&
         ((uVar2 = map_debug_bases(param_1,"qcom,apsscc",&apss_cc_debug_mux), uVar2 != 0 &&
          (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
       ((((_DAT_00100640 == 0 || (0xfffffffffffff000 < _DAT_00100640)) &&
         (uVar2 = map_debug_bases(param_1,"qcom,gcc",&gcc_debug_mux), uVar2 != 0)) &&
        (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))) goto LAB_00100290;
    lVar8 = 0;
    do {
      uVar6 = *(undefined8 *)((long)&debugcc_cliffs_hws + lVar8);
      uVar3 = devm_clk_register(lVar1,uVar6);
      if (0xfffffffffffff000 < uVar3) {
        uVar6 = clk_hw_get_name(uVar6);
        _dev_err(lVar1,"Unable to register %s, err:(%d)\n",uVar6,uVar3);
        goto LAB_00100290;
      }
      lVar8 = lVar8 + 8;
    } while (lVar8 != 0x138);
    ppuVar7 = (undefined **)&mc_cc_debug_mux;
    uVar3 = devm_clk_register_debug_mux(lVar1,&mc_cc_debug_mux);
    if ((int)uVar3 == 0) {
      ppuVar7 = &video_cc_debug_mux;
      uVar3 = devm_clk_register_debug_mux(lVar1,&video_cc_debug_mux);
      if ((int)uVar3 == 0) {
        ppuVar7 = &gpu_cc_debug_mux;
        uVar3 = devm_clk_register_debug_mux(lVar1,&gpu_cc_debug_mux);
        if ((int)uVar3 == 0) {
          ppuVar7 = &disp_cc_debug_mux;
          uVar3 = devm_clk_register_debug_mux(lVar1,&disp_cc_debug_mux);
          if ((int)uVar3 == 0) {
            ppuVar7 = &cam_cc_debug_mux;
            uVar3 = devm_clk_register_debug_mux(lVar1,&cam_cc_debug_mux);
            if ((int)uVar3 == 0) {
              ppuVar7 = &apss_cc_debug_mux;
              uVar3 = devm_clk_register_debug_mux(lVar1,&apss_cc_debug_mux);
              if ((int)uVar3 == 0) {
                ppuVar7 = &gcc_debug_mux;
                uVar3 = devm_clk_register_debug_mux(lVar1,&gcc_debug_mux);
                if ((int)uVar3 == 0) {
                  uVar4 = clk_debug_measure_register(&DAT_00100678);
                  uVar3 = uVar4 & 0xffffffff;
                  if ((int)uVar4 == 0) {
                    _dev_info(lVar1,"Registered debug measure clocks\n");
                    goto LAB_00100290;
                  }
                  pcVar5 = "Could not register Measure clocks\n";
                  goto LAB_001000d8;
                }
              }
            }
          }
        }
      }
    }
    uVar3 = uVar3 & 0xffffffff;
    if ((undefined8 *)ppuVar7[0xd] == (undefined8 *)0x0) {
      uVar6 = clk_hw_get_name(ppuVar7 + 0xb);
    }
    else {
      uVar6 = *(undefined8 *)ppuVar7[0xd];
    }
    _dev_err(lVar1,"Unable to register mux clk %s, err:(%d)\n",uVar6,uVar3);
  }
  else {
    if (uVar3 == 0xfffffffffffffdfb) goto LAB_00100290;
    pcVar5 = "Unable to get xo clock\n";
LAB_001000d8:
    _dev_err(lVar1,pcVar5);
  }
LAB_00100290:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// init_module @ 0010041c size=44
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
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106010 size=1
// signature: undefined _dev_err(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// map_debug_bases @ 00106018 size=1
// signature: undefined map_debug_bases(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void map_debug_bases(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register @ 00106020 size=1
// signature: undefined devm_clk_register(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register_debug_mux @ 00106028 size=1
// signature: undefined devm_clk_register_debug_mux(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register_debug_mux(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_debug_measure_register @ 00106030 size=1
// signature: undefined clk_debug_measure_register(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_debug_measure_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00106038 size=1
// signature: undefined _dev_info(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_name @ 00106040 size=1
// signature: undefined clk_hw_get_name(void)
// callers: [clk_debug_cliffs_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



