// Decompiled by Ghidra 12.2
// Program: qcom-ipcc.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_ipcc_probe @ 001002dc size=800
// signature: undefined qcom_ipcc_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_ipcc_probe(long param_1)

{
  long lVar1;
  undefined1 auVar2 [16];
  int iVar3;
  int iVar4;
  uint uVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  long lVar12;
  long lVar13;
  int iVar14;
  long local_b8 [11];
  
  lVar8 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_b8[10] = *(long *)(lVar8 + 0x638);
  plVar6 = (long *)devm_kmalloc(lVar1,0xe0,0xdc0);
  if (plVar6 == (long *)0x0) goto LAB_001004a0;
  *plVar6 = lVar1;
  uVar7 = devm_platform_ioremap_resource(param_1,0);
  plVar6[1] = uVar7;
  if (0xfffffffffffff000 < uVar7) goto LAB_001004a4;
  uVar7 = platform_get_irq(param_1,0);
  *(int *)((long)plVar6 + 0xbc) = (int)uVar7;
  if ((int)uVar7 < 0) {
    uVar7 = uVar7 & 0xffffffff;
    goto LAB_001004a4;
  }
  qcom_ipcc_probe_id = qcom_ipcc_probe_id + 1;
  lVar8 = devm_kasprintf(lVar1,0xcc0,"ipcc_%d");
  if (lVar8 != 0) {
    lVar9 = 0;
    if (*(long *)(param_1 + 0x2f8) != 0) {
      lVar9 = *(long *)(param_1 + 0x2f8) + 0x18;
    }
    lVar9 = __irq_domain_add(lVar9,0,0xffffffffffffffff,0,qcom_ipcc_irq_ops,plVar6);
    plVar6[2] = lVar9;
    if (lVar9 != 0) {
      lVar12 = *plVar6;
      lVar13 = *(long *)(param_1 + 0x2f8);
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
      *(undefined4 *)(plVar6 + 0x17) = 0;
      lVar9 = of_find_node_with_property(0,"mboxes");
      if (lVar9 != 0) {
        do {
          uVar7 = of_device_is_available(lVar9);
          if (((uVar7 & 1) != 0) &&
             (iVar3 = of_count_phandle_with_args(lVar9,"mboxes","#mbox-cells"), 0 < iVar3)) {
            iVar14 = 0;
            do {
              iVar4 = __of_parse_phandle_with_args
                                (lVar9,"mboxes","#mbox-cells",0xffffffff,iVar14,local_b8);
              if ((iVar4 == 0) && (local_b8[0] == lVar13)) {
                *(int *)(plVar6 + 0x17) = (int)plVar6[0x17] + 1;
              }
              iVar14 = iVar14 + 1;
            } while (iVar3 != iVar14);
          }
          lVar9 = of_find_node_with_property(lVar9,"mboxes");
        } while (lVar9 != 0);
      }
      iVar3 = (int)plVar6[0x17];
      if (iVar3 == 0) {
LAB_0010055c:
        uVar5 = devm_request_threaded_irq
                          (lVar1,*(undefined4 *)((long)plVar6 + 0xbc),qcom_ipcc_irq_fn,0,0x14004,
                           lVar8,plVar6);
        if ((int)uVar5 < 0) {
          uVar7 = (ulong)uVar5;
          pcVar11 = "Failed to register the irq: %d\n";
        }
        else {
          plVar6[0x18] = (long)qcom_ipcc_hibernation_cb;
          uVar10 = register_pm_notifier();
          uVar7 = uVar10 & 0xffffffff;
          if ((int)uVar10 == 0) {
            *(long **)(param_1 + 0xa8) = plVar6;
            goto LAB_001004a4;
          }
          pcVar11 = "Failed to register PM notifier: %d\n";
        }
        _dev_err(lVar1,pcVar11,uVar7);
        if ((int)plVar6[0x17] != 0) {
          mbox_controller_unregister(plVar6 + 5);
        }
      }
      else {
        auVar2._8_8_ = 0;
        auVar2._0_8_ = (long)iVar3;
        if (SUB168(auVar2 * ZEXT816(0xf8),8) == 0) {
          lVar9 = devm_kmalloc(lVar12,(long)iVar3 * 0xf8,0xdc0);
          plVar6[3] = lVar9;
          if (lVar9 != 0) {
            plVar6[5] = lVar12;
            plVar6[6] = (long)&ipcc_mbox_chan_ops;
            plVar6[7] = lVar9;
            plVar6[10] = (long)qcom_ipcc_mbox_xlate;
            *(undefined2 *)((long)plVar6 + 0x44) = 0;
            *(int *)(plVar6 + 8) = (int)plVar6[0x17];
            uVar10 = devm_mbox_controller_register(lVar12);
            uVar7 = uVar10 & 0xffffffff;
            if ((int)uVar10 == 0) goto LAB_0010055c;
            goto LAB_001005ec;
          }
        }
        else {
          plVar6[3] = 0;
        }
        uVar7 = 0xfffffff4;
      }
LAB_001005ec:
      irq_domain_remove(plVar6[2]);
      goto LAB_001004a4;
    }
  }
LAB_001004a0:
  uVar7 = 0xfffffff4;
LAB_001004a4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_ipcc_remove @ 00100600 size=68
// signature: undefined qcom_ipcc_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ipcc_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  unregister_pm_notifier(lVar1 + 0xc0);
  irq_set_irq_wake(*(undefined4 *)(lVar1 + 0xbc),0);
  irq_domain_remove(*(undefined8 *)(lVar1 + 0x10));
  return 0;
}



//------------------------------------------------------------
// qcom_ipcc_irq_fn @ 00100648 size=196
// signature: undefined qcom_ipcc_irq_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ipcc_irq_fn(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  iVar2 = readl(*(long *)(param_2 + 8) + 0x10);
  while (iVar2 != -1) {
    local_3c = 0;
    lVar3 = __irq_resolve_mapping(*(undefined8 *)(param_2 + 0x10),iVar2,&local_3c);
    uVar1 = 0;
    if (lVar3 != 0) {
      uVar1 = local_3c;
    }
    writel(iVar2,*(long *)(param_2 + 8) + 0x1c);
    generic_handle_irq(uVar1);
    iVar2 = readl(*(long *)(param_2 + 8) + 0x10);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// qcom_ipcc_hibernation_cb @ 00100710 size=40
// signature: undefined qcom_ipcc_hibernation_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ipcc_hibernation_cb(long param_1,long param_2)

{
  undefined1 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 1;
  }
  else {
    if (param_2 != 2) {
      return 1;
    }
    uVar1 = 0;
  }
  *(undefined1 *)(param_1 + 0x18) = uVar1;
  return 1;
}



//------------------------------------------------------------
// qcom_ipcc_domain_map @ 0010073c size=100
// signature: undefined qcom_ipcc_domain_map(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ipcc_domain_map(long param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  irq_set_chip_and_handler_name(param_2,&qcom_ipcc_irq_chip,&handle_level_irq,0);
  irq_set_chip_data(param_2,uVar1);
  irq_modify_status(param_2,0,0x400);
  return 0;
}



//------------------------------------------------------------
// qcom_ipcc_domain_xlate @ 001007a4 size=56
// signature: undefined qcom_ipcc_domain_xlate(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_ipcc_domain_xlate
          (undefined8 param_1,undefined8 param_2,int *param_3,int param_4,ulong *param_5,
          uint *param_6)

{
  if (param_4 == 3) {
    *param_5 = (ulong)*(ushort *)(param_3 + 1) | (ulong)(uint)(*param_3 << 0x10);
    *param_6 = param_3[2] & 0xf;
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// qcom_ipcc_mask_irq @ 001007e0 size=124
// signature: undefined qcom_ipcc_mask_irq(void)
// callers: []
//------------------------------------------------------------

void qcom_ipcc_mask_irq(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ushort *puVar5;
  
  lVar2 = *(long *)(param_1 + 0x30);
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar3 = (ulong)*(uint *)(lVar2 + 0xb8);
  if (0 < (int)*(uint *)(lVar2 + 0xb8)) {
    puVar4 = (undefined8 *)(*(long *)(lVar2 + 0x18) + 0xf0);
    do {
      puVar5 = (ushort *)*puVar4;
      if (puVar5 == (ushort *)0x0) break;
      if (((uint)*puVar5 == ((uint)((ulong)uVar1 >> 0x10) & 0xffff)) &&
         ((uint)puVar5[1] == ((uint)uVar1 & 0xffff))) {
        puVar5[2] = 0;
        break;
      }
      uVar3 = uVar3 - 1;
      puVar4 = puVar4 + 0x1f;
    } while (uVar3 != 0);
  }
  writel(uVar1,*(long *)(lVar2 + 8) + 0x18);
  return;
}



//------------------------------------------------------------
// qcom_ipcc_unmask_irq @ 00100860 size=128
// signature: undefined qcom_ipcc_unmask_irq(void)
// callers: []
//------------------------------------------------------------

void qcom_ipcc_unmask_irq(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ushort *puVar5;
  
  lVar2 = *(long *)(param_1 + 0x30);
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar3 = (ulong)*(uint *)(lVar2 + 0xb8);
  if (0 < (int)*(uint *)(lVar2 + 0xb8)) {
    puVar4 = (undefined8 *)(*(long *)(lVar2 + 0x18) + 0xf0);
    do {
      puVar5 = (ushort *)*puVar4;
      if (puVar5 == (ushort *)0x0) break;
      if (((uint)*puVar5 == ((uint)((ulong)uVar1 >> 0x10) & 0xffff)) &&
         ((uint)puVar5[1] == ((uint)uVar1 & 0xffff))) {
        puVar5[2] = 1;
        break;
      }
      uVar3 = uVar3 - 1;
      puVar4 = puVar4 + 0x1f;
    } while (uVar3 != 0);
  }
  writel(uVar1,*(long *)(lVar2 + 8) + 0x14);
  return;
}



//------------------------------------------------------------
// writel @ 001008e0 size=136
// signature: undefined writel(void)
// callers: [qcom_ipcc_mbox_send_data, qcom_ipcc_pm_resume, qcom_ipcc_irq_fn, qcom_ipcc_unmask_irq, qcom_ipcc_mask_irq]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1008f8,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100938,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_ipcc_mbox_xlate @ 0010096c size=244
// signature: undefined qcom_ipcc_mbox_xlate(void)
// callers: []
//------------------------------------------------------------

long qcom_ipcc_mbox_xlate(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  
  if (*(int *)(param_2 + 8) == 2) {
    iVar2 = *(int *)(param_1 + 0x18);
    if (iVar2 < 1) {
LAB_00100a10:
      lVar5 = -0x10;
    }
    else {
      lVar5 = *(long *)(param_1 + -0x10);
      lVar6 = 0;
      puVar7 = (undefined8 *)(lVar5 + 0xf0);
      puVar4 = (ushort *)*puVar7;
      if (puVar4 != (ushort *)0x0) {
        do {
          if (*(uint *)(param_2 + 0xc) == (uint)*puVar4) {
            if (*(uint *)(param_2 + 0x10) == (uint)puVar4[1]) {
              return -0x10;
            }
            if (iVar2 <= (int)lVar6 + 1) {
              return -0x10;
            }
          }
          else if (iVar2 <= (int)lVar6 + 1) goto LAB_00100a10;
          lVar6 = lVar6 + 1;
          puVar7 = (undefined8 *)(lVar5 + lVar6 * 0xf8 + 0xf0);
          puVar4 = (ushort *)*puVar7;
        } while (puVar4 != (ushort *)0x0);
      }
      puVar3 = (undefined2 *)devm_kmalloc(*(undefined8 *)(param_1 + -0x28),6,0xdc0);
      if (puVar3 == (undefined2 *)0x0) {
        lVar5 = -0xc;
      }
      else {
        uVar1 = *(undefined4 *)(param_2 + 0x10);
        lVar5 = lVar5 + lVar6 * 0xf8;
        *puVar3 = (short)*(undefined4 *)(param_2 + 0xc);
        puVar3[1] = (short)uVar1;
        *puVar7 = puVar3;
      }
    }
  }
  else {
    lVar5 = -0x16;
  }
  return lVar5;
}



//------------------------------------------------------------
// qcom_ipcc_mbox_send_data @ 00100a64 size=60
// signature: undefined qcom_ipcc_mbox_send_data(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_ipcc_mbox_send_data(long *param_1)

{
  writel(CONCAT22(*(undefined2 *)param_1[0x1e],((undefined2 *)param_1[0x1e])[1]),
         *(long *)(*param_1 + -0x20) + 0xc);
  return 0;
}



//------------------------------------------------------------
// qcom_ipcc_mbox_shutdown @ 00100aa4 size=8
// signature: undefined qcom_ipcc_mbox_shutdown(void)
// callers: []
//------------------------------------------------------------

void qcom_ipcc_mbox_shutdown(long param_1)

{
  *(undefined8 *)(param_1 + 0xf0) = 0;
  return;
}



//------------------------------------------------------------
// readl @ 00100aac size=140
// signature: undefined readl(void)
// callers: [qcom_ipcc_pm_resume, qcom_ipcc_irq_fn]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x100b04,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_ipcc_pm_resume @ 00100b3c size=268
// signature: undefined qcom_ipcc_pm_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_ipcc_pm_resume(long param_1)

{
  int iVar1;
  undefined2 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  if (_pm_suspend_target_state == 3) {
    if (lVar3 == 0) goto LAB_00100bec;
  }
  else if (*(char *)(lVar3 + 0xd8) == '\0' || lVar3 == 0) goto LAB_00100bec;
  iVar1 = *(int *)(lVar3 + 0xb8);
  if ((iVar1 != 0) && (0 < iVar1)) {
    lVar4 = 0;
    lVar5 = 0xf0;
    do {
      puVar2 = *(undefined2 **)(*(long *)(lVar3 + 0x18) + lVar5);
      if (puVar2 == (undefined2 *)0x0) break;
      if (puVar2[2] != 0) {
        writel(CONCAT22(*puVar2,puVar2[1]),*(long *)(lVar3 + 8) + 0x14);
        iVar1 = *(int *)(lVar3 + 0xb8);
      }
      lVar4 = lVar4 + 1;
      lVar5 = lVar5 + 0xf8;
    } while (lVar4 < iVar1);
  }
LAB_00100bec:
  iVar1 = readl(*(long *)(lVar3 + 8) + 0x10);
  if (iVar1 != -1) {
    local_3c = 0;
    __irq_resolve_mapping(*(undefined8 *)(lVar3 + 0x10),iVar1,&local_3c);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100c50 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_ipcc_driver,&__this_module);
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
// devm_kmalloc @ 00102008 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_ipcc_probe, qcom_ipcc_mbox_xlate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 00102010 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00102018 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kasprintf @ 00102020 size=1
// signature: undefined devm_kasprintf(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_domain_add @ 00102028 size=1
// signature: undefined __irq_domain_add(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_domain_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_with_property @ 00102030 size=1
// signature: undefined of_find_node_with_property(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_with_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00102038 size=1
// signature: undefined of_device_is_available(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00102040 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102048 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_mbox_controller_register @ 00102050 size=1
// signature: undefined devm_mbox_controller_register(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_mbox_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00102058 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00102060 size=1
// signature: undefined register_pm_notifier(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102068 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_controller_unregister @ 00102070 size=1
// signature: undefined mbox_controller_unregister(void)
// callers: [qcom_ipcc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_controller_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_remove @ 00102078 size=1
// signature: undefined irq_domain_remove(void)
// callers: [qcom_ipcc_probe, qcom_ipcc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_ipcc_pm_resume, qcom_ipcc_probe, qcom_ipcc_irq_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 00102088 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [qcom_ipcc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00102090 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [qcom_ipcc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 00102098 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [qcom_ipcc_pm_resume, qcom_ipcc_irq_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// generic_handle_irq @ 001020a0 size=1
// signature: undefined generic_handle_irq(void)
// callers: [qcom_ipcc_irq_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void generic_handle_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_and_handler_name @ 001020b0 size=1
// signature: undefined irq_set_chip_and_handler_name(void)
// callers: [qcom_ipcc_domain_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_and_handler_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_data @ 001020b8 size=1
// signature: undefined irq_set_chip_data(void)
// callers: [qcom_ipcc_domain_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 001020c0 size=1
// signature: undefined irq_modify_status(void)
// callers: [qcom_ipcc_domain_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001020c8 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 001020d0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001020d8 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 001020e0 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



