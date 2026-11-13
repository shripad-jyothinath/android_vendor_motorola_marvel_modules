// Decompiled by Ghidra 12.2
// Program: glink_probe.ko
// Image base: 00100000

//------------------------------------------------------------
// glink_probe @ 0010026c size=628
// signature: undefined glink_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_probe(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined *puVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined8 uVar8;
  code *pcVar9;
  code *pcVar10;
  undefined8 uVar11;
  char *pcVar12;
  char *local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  puVar5 = (undefined8 *)of_get_next_available_child(uVar11,0);
  if (puVar5 != (undefined8 *)0x0) {
    param_1 = param_1 + 0x10;
    do {
      local_70 = (char *)0x0;
      puVar6 = (undefined8 *)devm_kmalloc(param_1,0x68,0xdc0);
      if (puVar6 != (undefined8 *)0x0) {
        puVar1 = puVar6 + 5;
        iVar4 = of_property_read_string(puVar5,"label",puVar1);
        if (iVar4 < 0) {
          *puVar1 = *puVar5;
        }
        iVar4 = of_property_read_string(puVar5,"qcom,glink-label",puVar6 + 4);
        if (iVar4 < 0) {
          _dev_err(param_1,"[%s]: no qcom,glink-label for %s\n","probe_subsystem",*puVar1);
          ipc_log_string(glink_ilc,"[%s]: no qcom,glink-label for %s\n","probe_subsystem",*puVar1);
        }
        else {
          puVar6[2] = param_1;
          puVar6[3] = puVar5;
          iVar4 = of_property_read_string(puVar5,"transport",&local_70);
          pcVar12 = local_70;
          if (iVar4 < 0) {
            uVar8 = *puVar1;
            pcVar12 = "[%s]: %s missing transport\n";
          }
          else {
            iVar4 = strcmp(local_70,"smem");
            if (iVar4 == 0) {
              pcVar9 = glink_probe_smem_reg;
              pcVar10 = glink_probe_smem_unreg;
LAB_001003c0:
              puVar6[7] = pcVar9;
              puVar6[8] = pcVar10;
            }
            else {
              iVar4 = strcmp(pcVar12,"spss");
              if (iVar4 == 0) {
                pcVar9 = glink_probe_spss_reg;
                pcVar10 = glink_probe_spss_unreg;
                goto LAB_001003c0;
              }
            }
            puVar6[9] = glink_probe_ssr_cb;
            uVar7 = qcom_register_ssr_notifier(puVar6[5]);
            puVar3 = PTR_edge_infos_00100ea8;
            if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
              puVar6[0xc] = uVar7;
              uVar7 = __list_add_valid(puVar6,puVar3,&edge_infos);
              if ((uVar7 & 1) != 0) {
                PTR_edge_infos_00100ea8 = (undefined *)puVar6;
                *puVar6 = &edge_infos;
                puVar6[1] = puVar3;
                *(undefined8 **)puVar3 = puVar6;
              }
              ipc_log_string(glink_ilc,"probe successful for %s\n",*puVar1);
              goto LAB_001002f0;
            }
            uVar8 = *puVar1;
            pcVar12 = "[%s]: could not register for SSR notifier for %s\n";
          }
          _dev_err(param_1,pcVar12,"probe_subsystem",uVar8);
          ipc_log_string(glink_ilc,pcVar12,"probe_subsystem",*puVar1);
        }
      }
LAB_001002f0:
      puVar5 = (undefined8 *)of_get_next_available_child(uVar11,puVar5);
    } while (puVar5 != (undefined8 *)0x0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// glink_remove @ 001004e4 size=196
// signature: undefined glink_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_remove(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  lVar3 = of_get_next_available_child(uVar5,0);
  if (lVar3 != 0) {
    do {
      ppuVar6 = (undefined **)edge_infos;
      if ((undefined **)edge_infos != &edge_infos) {
        do {
          ppuVar7 = (undefined **)*ppuVar6;
          qcom_unregister_ssr_notifier(ppuVar6[0xc],ppuVar6 + 9);
          uVar4 = __list_del_entry_valid(ppuVar6);
          if ((uVar4 & 1) != 0) {
            puVar1 = *ppuVar6;
            plVar2 = (long *)ppuVar6[1];
            *(long **)(puVar1 + 8) = plVar2;
            *plVar2 = (long)puVar1;
          }
          *ppuVar6 = (undefined *)0xdead000000000100;
          ppuVar6[1] = (undefined *)0xdead000000000122;
          ppuVar6 = ppuVar7;
        } while (ppuVar7 != &edge_infos);
      }
      lVar3 = of_get_next_available_child(uVar5,lVar3);
    } while (lVar3 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// glink_probe_smem_reg @ 001005ac size=172
// signature: undefined glink_probe_smem_reg(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_probe_smem_reg(long param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  uVar2 = qcom_glink_smem_register(uVar1,*(undefined8 *)(param_1 + 0x18));
  *(ulong *)(param_1 + 0x30) = uVar2;
  if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
    _dev_err(uVar1,"[%s]: register failed for %s\n","glink_probe_smem_reg",
             *(undefined8 *)(param_1 + 0x28));
    ipc_log_string(glink_ilc,"[%s]: register failed for %s\n","glink_probe_smem_reg",
                   *(undefined8 *)(param_1 + 0x28));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  ipc_log_string(glink_ilc,"register successful for %s\n",*(undefined8 *)(param_1 + 0x28));
  return 0;
}



//------------------------------------------------------------
// glink_probe_smem_unreg @ 0010065c size=76
// signature: undefined glink_probe_smem_unreg(void)
// callers: []
//------------------------------------------------------------

void glink_probe_smem_unreg(long param_1)

{
  if (*(long *)(param_1 + 0x30) != 0) {
    qcom_glink_smem_unregister();
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  ipc_log_string(glink_ilc,"unregister for %s\n",*(undefined8 *)(param_1 + 0x28));
  return;
}



//------------------------------------------------------------
// glink_probe_spss_reg @ 001006ac size=144
// signature: undefined glink_probe_spss_reg(void)
// callers: []
//------------------------------------------------------------

undefined8 glink_probe_spss_reg(long param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  uVar2 = qcom_glink_spss_register(uVar1,*(undefined8 *)(param_1 + 0x18));
  *(ulong *)(param_1 + 0x30) = uVar2;
  if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
    _dev_err(uVar1,"[%s]: register failed for %s\n","glink_probe_spss_reg",
             *(undefined8 *)(param_1 + 0x28));
    ipc_log_string(glink_ilc,"[%s]: register failed for %s\n","glink_probe_spss_reg",
                   *(undefined8 *)(param_1 + 0x28));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// glink_probe_spss_unreg @ 00100740 size=52
// signature: undefined glink_probe_spss_unreg(void)
// callers: []
//------------------------------------------------------------

void glink_probe_spss_unreg(long param_1)

{
  if (*(long *)(param_1 + 0x30) != 0) {
    qcom_glink_spss_unregister();
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  return;
}



//------------------------------------------------------------
// glink_probe_ssr_cb @ 00100778 size=236
// signature: undefined glink_probe_ssr_cb(void)
// callers: []
//------------------------------------------------------------

undefined1  [16] glink_probe_ssr_cb(long param_1,long param_2)

{
  undefined1 auVar1 [16];
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  
  ipc_log_string(glink_ilc,"received %ld for %s\n",param_2,*(undefined8 *)(param_1 + -0x20));
  if (param_2 == 3) {
    lVar3 = (*(long **)(param_1 + -0x38))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + -0x38);
    }
    if (*(int *)(*(code **)(param_1 + -8) + -4) != -0x14617435) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100834);
      (*pcVar2)();
    }
    (**(code **)(param_1 + -8))(param_1 + -0x48,lVar3);
  }
  else if (param_2 == 1) {
    lVar3 = (*(long **)(param_1 + -0x38))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + -0x38);
    }
    if (*(int *)(*(code **)(param_1 + -0x10) + -4) != -0x7adab4f5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1007f8);
      (*pcVar2)();
    }
    (**(code **)(param_1 + -0x10))(param_1 + -0x48,lVar3);
  }
  uVar4 = (*(ulong **)(param_1 + -0x38))[0xe];
  if (uVar4 == 0) {
    uVar4 = **(ulong **)(param_1 + -0x38);
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar4;
  return auVar1 << 0x40;
}



//------------------------------------------------------------
// init_module @ 001009d0 size=120
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  glink_ilc = ipc_log_context_create(4,"glink_probe",0);
  iVar1 = __platform_driver_register(&glink_probe_driver,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_00100bc8,"glink_probe_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100a4c size=52
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (glink_ilc != 0) {
    ipc_log_context_destroy();
  }
  platform_driver_unregister(&glink_probe_driver);
  return;
}



//------------------------------------------------------------
// ipc_log_context_create @ 00102000 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102008 size=1
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
// _printk @ 00102010 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00102018 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00102020 size=1
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
// of_get_next_available_child @ 00102028 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [glink_remove, glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00102030 size=1
// signature: undefined ipc_log_string(void)
// callers: [glink_probe_ssr_cb, glink_probe_smem_reg, glink_probe_smem_unreg, glink_probe, glink_probe_spss_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102038 size=1
// signature: undefined devm_kmalloc(void)
// callers: [glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00102040 size=1
// signature: undefined of_property_read_string(void)
// callers: [glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102048 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 00102050 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102058 size=1
// signature: undefined __list_add_valid(void)
// callers: [glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102060 size=1
// signature: undefined _dev_err(void)
// callers: [glink_probe_smem_reg, glink_probe, glink_probe_spss_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 00102070 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [glink_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00102078 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [glink_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_smem_register @ 00102080 size=1
// signature: undefined qcom_glink_smem_register(void)
// callers: [glink_probe_smem_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_smem_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_smem_unregister @ 00102088 size=1
// signature: undefined qcom_glink_smem_unregister(void)
// callers: [glink_probe_smem_unreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_smem_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_spss_register @ 00102090 size=1
// signature: undefined qcom_glink_spss_register(void)
// callers: [glink_probe_spss_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_spss_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_glink_spss_unregister @ 00102098 size=1
// signature: undefined qcom_glink_spss_unregister(void)
// callers: [glink_probe_spss_unreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_glink_spss_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



