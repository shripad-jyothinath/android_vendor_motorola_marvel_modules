// Decompiled by Ghidra 12.2
// Program: qti-ocp-notifier.ko
// Image base: 00100000

//------------------------------------------------------------
// ocp_notifier_probe @ 001001dc size=1016
// signature: undefined ocp_notifier_probe(void)
// callers: []
//------------------------------------------------------------

ulong ocp_notifier_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  char *pcVar7;
  long lVar8;
  ulong *puVar9;
  int iVar10;
  ulong local_88;
  undefined4 local_80 [2];
  ulong local_78;
  undefined4 local_70 [2];
  long local_68;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar6 + 0x638);
  local_80[0] = 0;
  local_88 = 0;
  plVar3 = (long *)devm_kmalloc(lVar1,0x50,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_00100554;
  }
  *plVar3 = lVar1;
  uVar4 = devm_nvmem_cell_get(lVar1,"ocp_log");
  puVar9 = (ulong *)(plVar3 + 4);
  *puVar9 = uVar4;
  if (uVar4 < 0xfffffffffffff001) {
    uVar5 = platform_get_irq(param_1,0);
    uVar4 = uVar5 & 0xffffffff;
    if (-1 < (int)uVar5) {
      lVar6 = ipc_log_context_create(3,"regulator_ocp",0);
      lVar8 = plVar3[4];
      plVar3[6] = lVar6;
      *(long **)(param_1 + 0xa8) = plVar3;
      uVar5 = nvmem_cell_read(lVar8,&local_88);
      if (uVar5 < 0xfffffffffffff001) {
        *(int *)(plVar3 + 5) = (int)(local_88 >> 1);
        kfree(uVar5);
        plVar3[1] = 0x1000000400000000;
        plVar3[2] = 0;
        plVar3[3] = 0;
        if (0 < (int)plVar3[5]) {
          iVar10 = 0;
          do {
            uVar2 = ocp_notifier_read_entry(plVar3,puVar9,iVar10,local_80);
            if (uVar2 != 0) {
              uVar5 = (ulong)uVar2;
              goto LAB_00100540;
            }
            uVar2 = ocp_notifier_log_event
                              (plVar3,puVar9,local_80,"Regulator OCP event before kernel boot:");
            if (uVar2 != 0) {
              uVar5 = (ulong)uVar2;
              if (uVar2 != 0xfffffdfb) {
                _dev_err(lVar1,"failed to log OCP entry %d, ret=%d\n",iVar10,uVar5);
              }
              goto LAB_00100540;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 < (int)plVar3[5]);
        }
        uVar4 = devm_request_threaded_irq
                          (lVar1,uVar4,0,ocp_notifier_handler,0x2000,"regulator-ocp",plVar3);
        uVar5 = uVar4 & 0xffffffff;
        if ((int)uVar4 == 0) {
          local_70[0] = 0;
          local_78 = 0;
          uVar4 = devm_nvmem_cell_get(lVar1,"alarm_log");
          puVar9 = (ulong *)(plVar3 + 7);
          *puVar9 = uVar4;
          if (uVar4 < 0xfffffffffffff001) {
            uVar4 = platform_get_irq(param_1,1);
            uVar5 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) {
              _dev_err(lVar1,"failed to get alarm irq, ret=%d\n",uVar5);
            }
            else {
              lVar6 = ipc_log_context_create(3,"regulator_alarm",0);
              plVar3[9] = lVar6;
              uVar4 = nvmem_cell_read(plVar3[7],&local_78);
              if (uVar4 < 0xfffffffffffff001) {
                *(int *)(plVar3 + 8) = (int)(local_78 >> 1);
                kfree(uVar4);
                if (0 < (int)plVar3[8]) {
                  iVar10 = 0;
                  do {
                    uVar2 = ocp_notifier_read_entry(plVar3,puVar9,iVar10,local_70);
                    if (uVar2 != 0) {
                      uVar4 = (ulong)uVar2;
                      goto LAB_00100538;
                    }
                    uVar2 = ocp_notifier_log_event
                                      (plVar3,puVar9,local_70,
                                       "Regulator alarm event before kernel boot:");
                    if (uVar2 != 0) {
                      uVar4 = (ulong)uVar2;
                      if (uVar2 == 0xfffffdfb) goto LAB_00100538;
                      _dev_err(lVar1,"failed to log alarm entry %d, ret=%d\n",iVar10,uVar4);
                      goto LAB_001005c0;
                    }
                    iVar10 = iVar10 + 1;
                  } while (iVar10 < (int)plVar3[8]);
                }
                uVar5 = devm_request_threaded_irq
                                  (lVar1,uVar5,0,alarm_notifier_handler,0x2000,"regulator-alarm",
                                   plVar3);
                uVar4 = uVar5 & 0xffffffff;
                if ((int)uVar5 == 0) {
LAB_00100504:
                  uVar4 = 0;
                  goto LAB_00100554;
                }
LAB_00100538:
                ipc_log_context_destroy(plVar3[9]);
                uVar5 = uVar4;
              }
              else {
                _dev_err(lVar1,"failed to read alarm nvmem cell, ret=%d\n",uVar4 & 0xffffffff);
LAB_001005c0:
                ipc_log_context_destroy(plVar3[9]);
                uVar5 = uVar4;
                if ((int)uVar4 == 0) goto LAB_00100504;
              }
            }
          }
          else {
            if ((int)uVar4 != -0x205) {
              *puVar9 = 0;
              goto LAB_00100504;
            }
            uVar5 = 0xfffffdfb;
          }
        }
LAB_00100540:
        idr_destroy(plVar3 + 1);
      }
      else {
        _dev_err(lVar1,"failed to read OCP nvmem cell, ret=%d\n",uVar5 & 0xffffffff);
      }
      ipc_log_context_destroy(plVar3[6]);
      uVar4 = uVar5 & 0xffffffff;
      goto LAB_00100554;
    }
    pcVar7 = "failed to get OCP irq, ret=%d\n";
  }
  else {
    if ((int)uVar4 == -0x205) {
      uVar4 = 0xfffffdfb;
      goto LAB_00100554;
    }
    pcVar7 = "failed to get nvmem cell, ret=%d\n";
  }
  _dev_err(lVar1,pcVar7,uVar4 & 0xffffffff);
LAB_00100554:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// ocp_notifier_remove @ 001005d8 size=64
// signature: undefined ocp_notifier_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 ocp_notifier_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  ipc_log_context_destroy(*(undefined8 *)(lVar1 + 0x30));
  ipc_log_context_destroy(*(undefined8 *)(lVar1 + 0x48));
  idr_destroy(lVar1 + 8);
  return 0;
}



//------------------------------------------------------------
// ocp_notifier_read_entry @ 00100618 size=264
// signature: undefined ocp_notifier_read_entry(void)
// callers: [alarm_notifier_handler, ocp_notifier_handler, ocp_notifier_probe]
//------------------------------------------------------------

ulong ocp_notifier_read_entry
                (undefined8 *param_1,undefined8 *param_2,uint param_3,undefined2 *param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (param_3 < *(uint *)(param_2 + 1)) {
    uVar2 = nvmem_cell_read(*param_2,&local_40);
    if (0xfffffffffffff000 < uVar2) {
      _dev_err(*param_1,"failed to read nvmem cell, ret=%d\n",uVar2 & 0xffffffff);
      goto LAB_001006ec;
    }
    uVar3 = (ulong)(int)(param_3 << 1);
    if ((uVar3 | 1) < local_40) {
      *param_4 = CONCAT11(*(byte *)(uVar2 + uVar3) >> 4,*(undefined1 *)(uVar2 + (uVar3 | 1)));
      *(byte *)(param_4 + 1) = *(byte *)(uVar2 + uVar3) & 7;
      kfree(uVar2);
      uVar2 = 0;
      goto LAB_001006ec;
    }
    _dev_err(*param_1,"invalid OCP log index=%i\n");
    kfree(uVar2);
  }
  uVar2 = 0xffffffea;
LAB_001006ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// ocp_notifier_log_event @ 00100720 size=484
// signature: undefined ocp_notifier_log_event(void)
// callers: [alarm_notifier_handler, ocp_notifier_handler, ocp_notifier_probe]
//------------------------------------------------------------

void ocp_notifier_log_event(undefined8 *param_1,long param_2,ushort *param_3,undefined8 param_4)

{
  ushort uVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  uint uVar6;
  undefined *puVar7;
  ulong local_68 [3];
  
  lVar2 = sp_el0;
  local_68[2] = *(long *)(lVar2 + 0x638);
  uVar1 = *param_3;
  if (uVar1 != 0) {
    local_68[0] = 0;
    local_68[1] = 0;
    puVar4 = (undefined8 *)idr_find(param_1 + 1,uVar1);
    if (puVar4 == (undefined8 *)0x0) {
      local_68[0] = local_68[0] & 0xffffffffffffff00;
      scnprintf(local_68,0x10,"periph-%03x",uVar1);
      uVar5 = regulator_get_optional(*param_1,local_68);
      if (uVar5 < 0xfffffffffffff001) {
        puVar4 = *(undefined8 **)(uVar5 + 0x78);
        regulator_put();
        uVar6 = (uint)uVar1;
        uVar5 = idr_alloc(param_1 + 1,puVar4,uVar6,uVar6 + 1,0xcc0);
        if ((int)(uint)uVar5 < 0) goto LAB_001007e4;
        if ((uint)uVar5 != uVar6) {
          uVar5 = 0xffffffea;
          goto LAB_001007e4;
        }
        if (puVar4 != (undefined8 *)0x0) goto LAB_00100780;
      }
      else if ((int)uVar5 == -0x205) goto LAB_001007e4;
      iVar3 = ___ratelimit(ocp_notifier_log_event__rs_13,"ocp_notifier_log_event");
      if (iVar3 != 0) {
        _printk(&DAT_00100fd1,param_4,*param_3,(char)param_3[1]);
      }
      ipc_log_string(*(undefined8 *)(param_2 + 0x10),"%s ppid=0x%03X, mode=%u\n",param_4,*param_3,
                     (char)param_3[1]);
    }
    else {
LAB_00100780:
      if (((undefined8 *)puVar4[0x8f] == (undefined8 *)0x0) ||
         (puVar7 = *(undefined **)puVar4[0x8f], puVar7 == (undefined *)0x0)) {
        puVar7 = &UNK_00100fd0;
        if (*(undefined **)*puVar4 != (undefined *)0x0) {
          puVar7 = *(undefined **)*puVar4;
        }
      }
      iVar3 = ___ratelimit(ocp_notifier_log_event__rs,"ocp_notifier_log_event");
      if (iVar3 != 0) {
        _printk(&DAT_0010114a,param_4,puVar7,*param_3,(char)param_3[1]);
      }
      ipc_log_string(*(undefined8 *)(param_2 + 0x10),"%s name=%s, ppid=0x%03X, mode=%u\n",param_4,
                     puVar7,*param_3,(char)param_3[1]);
    }
  }
  uVar5 = 0;
LAB_001007e4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// ocp_notifier_handler @ 00100908 size=172
// signature: undefined ocp_notifier_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ocp_notifier_handler(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_30 [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30[0] = 0;
  iVar1 = ocp_notifier_read_entry(param_2,param_2 + 0x20,0,local_30);
  if (((iVar1 == 0) &&
      (iVar1 = ocp_notifier_log_event
                         (param_2,param_2 + 0x20,local_30,"Regulator OCP during runtime:"),
      iVar1 == 0)) && (lVar2 = idr_find(param_2 + 8,(undefined2)local_30[0]), lVar2 != 0)) {
    regulator_notifier_call_chain(lVar2,2,0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// alarm_notifier_handler @ 001009b8 size=172
// signature: undefined alarm_notifier_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 alarm_notifier_handler(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_30 [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30[0] = 0;
  iVar1 = ocp_notifier_read_entry(param_2,param_2 + 0x38,0,local_30);
  if (((iVar1 == 0) &&
      (iVar1 = ocp_notifier_log_event
                         (param_2,param_2 + 0x38,local_30,"Regulator alarm during runtime:"),
      iVar1 == 0)) && (lVar2 = idr_find(param_2 + 8,(undefined2)local_30[0]), lVar2 != 0)) {
    regulator_notifier_call_chain(lVar2,1,0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 00100a68 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ocp_notifier_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100a98 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ocp_notifier_driver);
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_cell_get @ 00102018 size=1
// signature: undefined devm_nvmem_cell_get(void)
// callers: [ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00102020 size=1
// signature: undefined platform_get_irq(void)
// callers: [ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00102028 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 00102030 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [ocp_notifier_read_entry, ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102038 size=1
// signature: undefined kfree(void)
// callers: [ocp_notifier_read_entry, ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00102040 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [ocp_notifier_read_entry, ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00102050 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [ocp_notifier_remove, ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 00102058 size=1
// signature: undefined idr_destroy(void)
// callers: [ocp_notifier_remove, ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ocp_notifier_read_entry, alarm_notifier_handler, ocp_notifier_handler, ocp_notifier_log_event, ocp_notifier_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00102068 size=1
// signature: undefined idr_find(void)
// callers: [alarm_notifier_handler, ocp_notifier_handler, ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00102070 size=1
// signature: undefined ___ratelimit(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00102078 size=1
// signature: undefined ipc_log_string(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102080 size=1
// signature: undefined scnprintf(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_optional @ 00102088 size=1
// signature: undefined regulator_get_optional(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00102090 size=1
// signature: undefined regulator_put(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00102098 size=1
// signature: undefined idr_alloc(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001020a0 size=1
// signature: undefined _printk(void)
// callers: [ocp_notifier_log_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_notifier_call_chain @ 001020a8 size=1
// signature: undefined regulator_notifier_call_chain(void)
// callers: [alarm_notifier_handler, ocp_notifier_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



