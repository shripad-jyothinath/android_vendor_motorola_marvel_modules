// Decompiled by Ghidra 12.2
// Program: debugcc-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// clk_debug_pineapple_probe @ 00100084 size=1216
// signature: undefined clk_debug_pineapple_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong clk_debug_pineapple_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  undefined **ppuVar8;
  
  lVar1 = param_1 + 0x10;
  uVar3 = devm_clk_get(lVar1,"xo_clk_src");
  if (uVar3 < 0xfffffffffffff001) {
    debug_mux_priv = uVar3;
    if (((((((((_DAT_001007f8 == 0) || (0xfffffffffffff000 < _DAT_001007f8)) &&
             (uVar2 = map_debug_bases(param_1,"qcom,mccc",&mc_cc_debug_mux), uVar2 != 0)) &&
            (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)) ||
           (((_DAT_00100878 == 0 || (0xfffffffffffff000 < _DAT_00100878)) &&
            ((uVar2 = map_debug_bases(param_1,"qcom,videocc",&video_cc_debug_mux), uVar2 != 0 &&
             (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
          (((_DAT_001008f8 == 0 || (0xfffffffffffff000 < _DAT_001008f8)) &&
           ((uVar2 = map_debug_bases(param_1,"qcom,gpucc",&gpu_cc_debug_mux), uVar2 != 0 &&
            (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
         (((((_DAT_00100978 == 0 || (0xfffffffffffff000 < _DAT_00100978)) &&
            (uVar2 = map_debug_bases(param_1,"qcom,dispcc",&disp_cc_debug_mux), uVar2 != 0)) &&
           (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)) ||
          (((_DAT_001009f8 == 0 || (0xfffffffffffff000 < _DAT_001009f8)) &&
           ((uVar2 = map_debug_bases(param_1,"qcom,camcc",&cam_cc_debug_mux), uVar2 != 0 &&
            (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))))) ||
        (((_DAT_00100a78 == 0 || (0xfffffffffffff000 < _DAT_00100a78)) &&
         ((uVar2 = map_debug_bases(param_1,"qcom,apsscc",&apss_cc_debug_mux), uVar2 != 0 &&
          (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))))) ||
       ((((_DAT_00100778 == 0 || (0xfffffffffffff000 < _DAT_00100778)) &&
         (uVar2 = map_debug_bases(param_1,"qcom,gcc",&gcc_debug_mux), uVar2 != 0)) &&
        (uVar3 = (ulong)uVar2, uVar2 != 0xffffffcb)))) goto LAB_00100284;
    puVar7 = measure_only_apcs_gold_post_acd_clk;
    uVar3 = devm_clk_register(lVar1,measure_only_apcs_gold_post_acd_clk);
    if (uVar3 < 0xfffffffffffff001) {
      puVar7 = measure_only_apcs_goldapc2_post_acd_clk;
      uVar3 = devm_clk_register(lVar1,measure_only_apcs_goldapc2_post_acd_clk);
      if (uVar3 < 0xfffffffffffff001) {
        puVar7 = measure_only_apcs_goldplus_post_acd_clk;
        uVar3 = devm_clk_register(lVar1,measure_only_apcs_goldplus_post_acd_clk);
        if (uVar3 < 0xfffffffffffff001) {
          puVar7 = measure_only_apcs_l3_post_acd_clk;
          uVar3 = devm_clk_register(lVar1,measure_only_apcs_l3_post_acd_clk);
          if (uVar3 < 0xfffffffffffff001) {
            puVar7 = measure_only_apcs_silver_post_acd_clk;
            uVar3 = devm_clk_register(lVar1,measure_only_apcs_silver_post_acd_clk);
            if (uVar3 < 0xfffffffffffff001) {
              puVar7 = measure_only_cnoc_clk;
              uVar3 = devm_clk_register(lVar1,measure_only_cnoc_clk);
              if (uVar3 < 0xfffffffffffff001) {
                puVar7 = measure_only_gpu_cc_cx_gfx3d_clk;
                uVar3 = devm_clk_register(lVar1,measure_only_gpu_cc_cx_gfx3d_clk);
                if (uVar3 < 0xfffffffffffff001) {
                  puVar7 = measure_only_gpu_cc_cx_gfx3d_slv_clk;
                  uVar3 = devm_clk_register(lVar1,measure_only_gpu_cc_cx_gfx3d_slv_clk);
                  if (uVar3 < 0xfffffffffffff001) {
                    puVar7 = measure_only_gpu_cc_gx_gfx3d_clk;
                    uVar3 = devm_clk_register(lVar1,measure_only_gpu_cc_gx_gfx3d_clk);
                    if (uVar3 < 0xfffffffffffff001) {
                      puVar7 = measure_only_ipa_2x_clk;
                      uVar3 = devm_clk_register(lVar1,measure_only_ipa_2x_clk);
                      if (uVar3 < 0xfffffffffffff001) {
                        puVar7 = measure_only_mccc_clk;
                        uVar3 = devm_clk_register(lVar1,measure_only_mccc_clk);
                        if (uVar3 < 0xfffffffffffff001) {
                          puVar7 = measure_only_memnoc_clk;
                          uVar3 = devm_clk_register(lVar1,measure_only_memnoc_clk);
                          if (uVar3 < 0xfffffffffffff001) {
                            puVar7 = measure_only_snoc_clk;
                            uVar3 = devm_clk_register(lVar1,measure_only_snoc_clk);
                            if (uVar3 < 0xfffffffffffff001) {
                              ppuVar8 = (undefined **)&mc_cc_debug_mux;
                              uVar3 = devm_clk_register_debug_mux(lVar1,&mc_cc_debug_mux);
                              if ((int)uVar3 == 0) {
                                ppuVar8 = &video_cc_debug_mux;
                                uVar3 = devm_clk_register_debug_mux(lVar1,&video_cc_debug_mux);
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
                                        uVar3 = devm_clk_register_debug_mux
                                                          (lVar1,&apss_cc_debug_mux);
                                        if ((int)uVar3 == 0) {
                                          ppuVar8 = &gcc_debug_mux;
                                          uVar3 = devm_clk_register_debug_mux(lVar1,&gcc_debug_mux);
                                          if ((int)uVar3 == 0) {
                                            uVar5 = clk_debug_measure_register(&DAT_001007b0);
                                            uVar3 = uVar5 & 0xffffffff;
                                            if ((int)uVar5 == 0) {
                                              _dev_info(lVar1,"Registered debug measure clocks\n");
                                              goto LAB_00100284;
                                            }
                                            pcVar6 = "Could not register Measure clocks\n";
                                            goto LAB_001000cc;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              uVar3 = uVar3 & 0xffffffff;
                              if ((undefined8 *)ppuVar8[0xd] == (undefined8 *)0x0) {
                                uVar4 = clk_hw_get_name(ppuVar8 + 0xb);
                              }
                              else {
                                uVar4 = *(undefined8 *)ppuVar8[0xd];
                              }
                              _dev_err(lVar1,"Unable to register mux clk %s, err:(%d)\n",uVar4,uVar3
                                      );
                              goto LAB_00100284;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar4 = clk_hw_get_name(puVar7);
    _dev_err(lVar1,"Unable to register %s, err:(%d)\n",uVar4,uVar3);
  }
  else {
    if (uVar3 == 0xfffffffffffffdfb) goto LAB_00100284;
    pcVar6 = "Unable to get xo clock\n";
LAB_001000cc:
    _dev_err(lVar1,pcVar6);
  }
LAB_00100284:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// init_module @ 00100548 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&clk_debug_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00105000 size=1
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
// devm_clk_get @ 00105008 size=1
// signature: undefined devm_clk_get(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105010 size=1
// signature: undefined _dev_err(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// map_debug_bases @ 00105018 size=1
// signature: undefined map_debug_bases(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void map_debug_bases(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register @ 00105020 size=1
// signature: undefined devm_clk_register(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_name @ 00105028 size=1
// signature: undefined clk_hw_get_name(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register_debug_mux @ 00105030 size=1
// signature: undefined devm_clk_register_debug_mux(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register_debug_mux(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_debug_measure_register @ 00105038 size=1
// signature: undefined clk_debug_measure_register(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_debug_measure_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00105040 size=1
// signature: undefined _dev_info(void)
// callers: [clk_debug_pineapple_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



