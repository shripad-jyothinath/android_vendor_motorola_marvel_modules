// Decompiled by Ghidra 12.2
// Program: coresight-tpdm.ko
// Image base: 00100000

//------------------------------------------------------------
// tpdm_probe @ 00102194 size=1316
// signature: undefined tpdm_probe(void)
// callers: []
//------------------------------------------------------------

void tpdm_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 uVar10;
  int local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined1 *local_a0;
  undefined8 local_98;
  long local_90;
  undefined **local_88;
  long local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = (undefined **)0x0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = (undefined1 *)0x0;
  local_b0 = 0;
  local_b4 = 0;
  local_80 = coresight_alloc_device_name(tpdm_devs,param_1);
  if (local_80 != 0) {
    uVar3 = coresight_get_platform_data(param_1);
    if (0xfffffffffffff000 < uVar3) goto LAB_001025f0;
    *(ulong *)(param_1 + 0x90) = uVar3;
    lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,hw-enable-check",0);
    if (lVar4 != 0) {
      iVar1 = qcom_scm_get_sec_dump_state(&local_b4);
      uVar3 = 0xfffffffa;
      if ((iVar1 != 0) || (local_b4 == 0)) goto LAB_001025f0;
    }
    plVar5 = (long *)devm_kmalloc(param_1,0xd0,0xdc0);
    if (plVar5 != (long *)0x0) {
      plVar5[1] = param_1;
      *(long **)(param_1 + 0x98) = plVar5;
      lVar4 = devm_ioremap_resource(param_1,param_1 + 0x390);
      *plVar5 = lVar4;
      if (lVar4 != 0) {
        __mutex_init(plVar5 + 7,"&drvdata->lock",&tpdm_probe___key);
        local_58 = 0;
        local_50 = 0;
        uVar10 = *(undefined8 *)(plVar5[1] + 0x2e8);
        lVar4 = of_find_property(uVar10,"qcom,clk-enable",0);
        *(bool *)((long)plVar5 + 0x69) = lVar4 != 0;
        lVar4 = of_find_property(uVar10,"qcom,msr-fix-req",0);
        *(bool *)((long)plVar5 + 0xc9) = lVar4 != 0;
        lVar4 = of_find_property(uVar10,"qcom,cmb-msr-skip",0);
        *(bool *)((long)plVar5 + 0xca) = lVar4 != 0;
        uVar2 = of_property_read_string_helper(uVar10,"qcom,tpdm-clks",0,0,0);
        *(uint *)(plVar5 + 3) = uVar2;
        if (0 < (int)uVar2) {
          lVar4 = devm_kmalloc(plVar5[1],(ulong)uVar2 << 3,0xdc0);
          plVar5[4] = lVar4;
          if (lVar4 == 0) goto LAB_00102620;
          if (0 < (int)plVar5[3]) {
            uVar3 = 0;
            do {
              iVar1 = of_property_read_string_helper
                                (uVar10,"qcom,tpdm-clks",&local_50,1,uVar3 & 0xffffffff);
              if (iVar1 < 0) goto LAB_00102620;
              uVar6 = devm_clk_get(plVar5[1],local_50);
              *(undefined8 *)(plVar5[4] + uVar3 * 8) = uVar6;
              uVar7 = *(ulong *)(plVar5[4] + uVar3 * 8);
              if (0xfffffffffffff000 < uVar7) goto LAB_0010245c;
              uVar3 = uVar3 + 1;
            } while ((long)uVar3 < (long)(int)plVar5[3]);
          }
        }
        uVar2 = of_property_read_string_helper(uVar10,"qcom,tpdm-regs",0,0,0);
        *(uint *)(plVar5 + 5) = uVar2;
        if (0 < (int)uVar2) {
          lVar4 = devm_kmalloc(plVar5[1],(ulong)uVar2 << 3,0xdc0);
          plVar5[6] = lVar4;
          if (lVar4 == 0) goto LAB_00102620;
          if (0 < (int)plVar5[5]) {
            uVar3 = 0;
            do {
              iVar1 = of_property_read_string_helper
                                (uVar10,"qcom,tpdm-regs",&local_58,1,uVar3 & 0xffffffff);
              if (iVar1 < 0) goto LAB_00102620;
              uVar6 = devm_regulator_get(plVar5[1],local_58);
              *(undefined8 *)(plVar5[6] + uVar3 * 8) = uVar6;
              uVar7 = *(ulong *)(plVar5[6] + uVar3 * 8);
              if (0xfffffffffffff000 < uVar7) goto LAB_0010245c;
              uVar3 = uVar3 + 1;
            } while ((long)uVar3 < (long)(int)plVar5[5]);
          }
        }
        goto LAB_00102460;
      }
    }
  }
  goto LAB_001025ec;
LAB_0010245c:
  if ((int)uVar7 != 0) {
LAB_00102620:
    _dev_err(plVar5[1],"TPDM parse of data fail\n");
    uVar3 = 0xffffffea;
    goto LAB_001025f0;
  }
LAB_00102460:
  local_98 = *(undefined8 *)(param_1 + 0x90);
  local_b0 = 3;
  local_a0 = tpdm_cs_ops;
  local_88 = &tpdm_attr_grps;
  local_90 = param_1;
  uVar3 = coresight_register(&local_b0);
  plVar5[2] = uVar3;
  if (0xfffffffffffff000 < uVar3) goto LAB_001025f0;
  uVar2 = *(uint *)(*plVar5 + 0xfe8) >> 4 & 0xf;
  *(uint *)((long)plVar5 + 0xc4) = uVar2;
  if (uVar2 != 0) {
    *(undefined1 *)(plVar5 + 0x19) = 1;
  }
  uVar3 = 0;
  uVar2 = *(uint *)(*plVar5 + 0xfe0);
  do {
    uVar7 = 1L << (uVar3 & 0x3f);
    if ((uVar7 & uVar2) != 0) {
      uVar8 = uVar3 >> 3 & 0x1ffffffffffffff8;
      uVar9 = *(ulong *)((long)plVar5 + uVar8 + 0x78);
      plVar5[0xe] = plVar5[0xe] | uVar7;
      *(ulong *)((long)plVar5 + uVar8 + 0x78) = uVar9 | uVar7;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0x20);
  if (((uint)plVar5[0xe] >> 5 & 1) == 0) {
LAB_00102538:
    if (((uint)plVar5[0xe] >> 4 & 1) != 0) {
      lVar4 = devm_kmalloc(plVar5[1],0x148,0xdc0);
      plVar5[0x14] = lVar4;
      if (lVar4 == 0) goto LAB_001025e4;
    }
    if (((uint)plVar5[0xe] >> 3 & 1) != 0) {
      lVar4 = devm_kmalloc(plVar5[1],0x94,0xdc0);
      plVar5[0x15] = lVar4;
      if (lVar4 == 0) goto LAB_001025e4;
    }
    if (((uint)plVar5[0xe] >> 1 & 1) != 0) {
      lVar4 = devm_kmalloc(plVar5[1],0x18c,0xdc0);
      plVar5[0x16] = lVar4;
      if (lVar4 == 0) goto LAB_001025e4;
    }
    if (((uint)plVar5[0xe] >> 2 & 1) == 0) {
      if (((uint)plVar5[0xe] >> 6 & 1) != 0) {
        lVar4 = devm_kmalloc(plVar5[1],0xc0,0xdc0);
        plVar5[0x17] = lVar4;
        if (lVar4 == 0) goto LAB_001025e4;
        uVar10 = devm_kmalloc(plVar5[1],2,0xdc0);
        *(undefined8 *)(plVar5[0x17] + 0xb8) = uVar10;
        lVar4 = *(long *)(plVar5[0x17] + 0xb8);
        goto joined_r0x0010264c;
      }
    }
    else {
      lVar4 = devm_kmalloc(plVar5[1],0xc0,0xdc0);
      plVar5[0x17] = lVar4;
joined_r0x0010264c:
      if (lVar4 == 0) goto LAB_001025e4;
    }
    tpdm_init_default_data(plVar5);
    uVar2 = *(uint *)(*plVar5 + 0xfc8);
    *(uint *)(plVar5 + 0x10) = uVar2 >> 0x1b & 3;
    *(uint *)((long)plVar5 + 0x84) = uVar2 >> 0x19 & 3;
    *(int *)(plVar5 + 0x18) = tpdm_probe_traceid;
    *(uint *)(plVar5 + 0x11) = uVar2 >> 0x17 & 3;
    *(uint *)((long)plVar5 + 0x8c) = (uVar2 >> 6 & 0x1f) + 1;
    *(uint *)(plVar5 + 0x12) = (uVar2 >> 4 & 3) + 1;
    tpdm_probe_traceid = tpdm_probe_traceid + 1;
    __pm_runtime_idle(param_1,5);
    uVar3 = 0;
    goto LAB_001025f0;
  }
  lVar4 = devm_kmalloc(plVar5[1],0x298,0xdc0);
  plVar5[0x13] = lVar4;
  if (lVar4 != 0) goto LAB_00102538;
LAB_001025e4:
  coresight_unregister(plVar5[2]);
LAB_001025ec:
  uVar3 = 0xfffffff4;
LAB_001025f0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// tpdm_freeze @ 001026bc size=40
// signature: undefined tpdm_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 tpdm_freeze(long param_1)

{
  coresight_disable(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x10));
  return 0;
}



//------------------------------------------------------------
// tpdm_init_default_data @ 001026e4 size=120
// signature: undefined tpdm_init_default_data(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void tpdm_init_default_data(long param_1)

{
  uint uVar1;
  
  if (((uint)*(undefined8 *)(param_1 + 0x70) >> 4 & 1) == 0) {
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x70);
  }
  else {
    *(undefined4 *)(*(long *)(param_1 + 0xa0) + 4) = 0;
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x70);
  }
  if ((uVar1 >> 3 & 1) == 0) {
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x70);
  }
  else {
    *(undefined4 *)(*(long *)(param_1 + 0xa8) + 4) = 0;
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x70);
  }
  if ((uVar1 >> 1 & 1) == 0) {
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x70);
  }
  else {
    *(undefined1 *)(*(long *)(param_1 + 0xb0) + 0xe8) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0xb0) + 0xe9) = 0;
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x70);
  }
  if (((uVar1 >> 2 & 1) != 0) || (((uint)*(undefined8 *)(param_1 + 0x70) >> 6 & 1) != 0)) {
    *(undefined1 *)(*(long *)(param_1 + 0xb8) + 0x2c) = 1;
  }
  return;
}



//------------------------------------------------------------
// tpdm_trace_id @ 00102760 size=16
// signature: undefined tpdm_trace_id(void)
// callers: []
//------------------------------------------------------------

undefined4 tpdm_trace_id(long param_1)

{
  return *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x98) + 0x98) + 0xc0);
}



//------------------------------------------------------------
// tpdm_enable @ 00102774 size=3616
// signature: undefined tpdm_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 tpdm_enable(long param_1)

{
  undefined4 *puVar1;
  char cVar2;
  code *pcVar3;
  long lVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  
  plVar10 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  if ((char)plVar10[0xd] != '\0') {
    _dev_err(plVar10[1],"TPDM setup already enabled,Skipping enablei\n");
    return 0;
  }
  mutex_lock(plVar10 + 7);
  *(undefined4 *)(*plVar10 + 0xfb0) = 0xc5acce55;
  DataSynchronizationBarrier(3,3,0);
  if (*(char *)((long)plVar10 + 0x69) != '\0') {
    *(undefined4 *)(*plVar10 + 0x220) = 1;
  }
  if (((uint)plVar10[0xf] >> 5 & 1) != 0) {
    uVar9 = 0;
    lVar4 = 0x18;
    do {
      if ((*(ulong *)(plVar10[0x13] + (uVar9 >> 3 & 0x1ffffffffffffff8)) >> (uVar9 & 0x3f) & 1) != 0
         ) {
        *(undefined4 *)(*plVar10 + lVar4 + -0x18) = *(undefined4 *)(plVar10[0x13] + lVar4);
      }
      uVar9 = uVar9 + 1;
      lVar4 = lVar4 + 4;
    } while (lVar4 != 0x298);
  }
  if (((uint)plVar10[0xf] >> 4 & 1) != 0) {
    if (*(int *)(plVar10[0x14] + 8) == 0) {
      *(int *)(*plVar10 + 0x284) = 0;
    }
    else {
      *(int *)(*plVar10 + 0x284) = *(int *)(plVar10[0x14] + 8);
    }
    lVar4 = plVar10[0x14];
    if (*(int *)(lVar4 + 0xc) == 0) {
      iVar6 = *(int *)(lVar4 + 0x10);
      if (iVar6 != 0) goto LAB_0010293c;
LAB_00102874:
      if (*(int *)(lVar4 + 0x14) != 0) goto LAB_00102954;
LAB_0010287c:
      iVar6 = *(int *)(lVar4 + 0x18);
    }
    else {
      *(undefined4 *)(*plVar10 + 0x28c) = 0xffffffff;
      *(undefined4 *)(*plVar10 + 0x288) = *(undefined4 *)(plVar10[0x14] + 0xc);
      lVar4 = plVar10[0x14];
      iVar6 = *(int *)(lVar4 + 0x10);
      if (iVar6 == 0) goto LAB_00102874;
LAB_0010293c:
      *(int *)(*plVar10 + 0x28c) = iVar6;
      lVar4 = plVar10[0x14];
      if (*(int *)(lVar4 + 0x14) == 0) goto LAB_0010287c;
LAB_00102954:
      *(undefined4 *)(*plVar10 + 0x294) = 0xffffffff;
      *(undefined4 *)(*plVar10 + 0x290) = *(undefined4 *)(plVar10[0x14] + 0x14);
      iVar6 = *(int *)(plVar10[0x14] + 0x18);
    }
    if (iVar6 != 0) {
      *(int *)(*plVar10 + 0x294) = iVar6;
    }
    if (*(int *)((long)plVar10 + 0x84) == 1) {
      *(undefined4 *)(*plVar10 + 0x298) = *(undefined4 *)(plVar10[0x14] + 0x1c);
      *(undefined4 *)(*plVar10 + 0x318) = *(undefined4 *)(plVar10[0x14] + 0x9c);
    }
    else if ((*(int *)((long)plVar10 + 0x84) == 0) && (*(int *)((long)plVar10 + 0x8c) != 0)) {
      lVar4 = 0x318;
      lVar8 = 0x27;
      do {
        if (lVar8 == 0x47) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103594);
          (*pcVar3)();
        }
        *(undefined4 *)(*plVar10 + lVar4 + -0x80) = *(undefined4 *)(plVar10[0x14] + lVar4 + -0x2fc);
        *(undefined4 *)(*plVar10 + lVar4) = *(undefined4 *)(plVar10[0x14] + lVar8 * 4);
        uVar9 = lVar8 - 0x26;
        lVar4 = lVar4 + 4;
        lVar8 = lVar8 + 1;
      } while (uVar9 < *(uint *)((long)plVar10 + 0x8c));
    }
    lVar4 = plVar10[0x14];
    if (*(int *)(lVar4 + 0x11c) != 0) {
      *(int *)(*plVar10 + 0x398) = *(int *)(lVar4 + 0x11c);
      lVar4 = plVar10[0x14];
    }
    *(undefined4 *)(*plVar10 + 0x39c) = *(undefined4 *)(lVar4 + 0x120);
    *(undefined4 *)(*plVar10 + 0x3a0) = *(undefined4 *)(plVar10[0x14] + 0x124);
    *(undefined4 *)(*plVar10 + 0x3a4) = *(undefined4 *)(plVar10[0x14] + 0x128);
    *(undefined4 *)(*plVar10 + 0x3a8) = *(undefined4 *)(plVar10[0x14] + 300);
    *(undefined4 *)(*plVar10 + 0x3ac) = *(undefined4 *)(plVar10[0x14] + 0x130);
    *(undefined4 *)(*plVar10 + 0x3b0) = *(undefined4 *)(plVar10[0x14] + 0x134);
    if ((char)plVar10[0x19] != '\0') {
      *(undefined4 *)(*plVar10 + 0x4f0) = *(undefined4 *)(plVar10[0x14] + 0x138);
      *(undefined4 *)(*plVar10 + 0x4f4) = *(undefined4 *)(plVar10[0x14] + 0x13c);
      *(undefined4 *)(*plVar10 + 0x4f8) = *(undefined4 *)(plVar10[0x14] + 0x140);
      *(undefined4 *)(*plVar10 + 0x4fc) = *(undefined4 *)(plVar10[0x14] + 0x144);
    }
    *(uint *)(*plVar10 + 0x280) =
         *(uint *)(*plVar10 + 0x280) & 0xfffffff8 |
         *(uint *)(*plVar10 + 0x280) & 3 | (uint)(*(int *)(plVar10[0x14] + 4) == 1) << 2;
    *(uint *)(*plVar10 + 0x280) = *(uint *)(*plVar10 + 0x280) | 1;
  }
  if (((uint)plVar10[0xf] >> 3 & 1) == 0) goto LAB_00102c6c;
  lVar4 = plVar10[0x15];
  if (*(int *)(lVar4 + 0xc) == 0) {
    iVar6 = *(int *)(lVar4 + 0x10);
    if (iVar6 != 0) goto LAB_001030b0;
LAB_00102afc:
    if (*(int *)(lVar4 + 0x14) != 0) goto LAB_001030c8;
LAB_00102b04:
    iVar6 = *(int *)(lVar4 + 0x18);
  }
  else {
    *(undefined4 *)(*plVar10 + 0x508) = 0xf;
    *(undefined4 *)(*plVar10 + 0x504) = *(undefined4 *)(plVar10[0x15] + 0xc);
    lVar4 = plVar10[0x15];
    iVar6 = *(int *)(lVar4 + 0x10);
    if (iVar6 == 0) goto LAB_00102afc;
LAB_001030b0:
    *(int *)(*plVar10 + 0x508) = iVar6;
    lVar4 = plVar10[0x15];
    if (*(int *)(lVar4 + 0x14) == 0) goto LAB_00102b04;
LAB_001030c8:
    *(undefined4 *)(*plVar10 + 0x510) = 0xf;
    *(undefined4 *)(*plVar10 + 0x50c) = *(undefined4 *)(plVar10[0x15] + 0x14);
    iVar6 = *(int *)(plVar10[0x15] + 0x18);
  }
  if (iVar6 != 0) {
    *(int *)(*plVar10 + 0x510) = iVar6;
  }
  if ((int)plVar10[0x10] == 1) {
    *(undefined4 *)(*plVar10 + 0x514) = *(undefined4 *)(plVar10[0x15] + 0x1c);
    *(undefined4 *)(*plVar10 + 0x534) = *(undefined4 *)(plVar10[0x15] + 0x3c);
    *(undefined4 *)(*plVar10 + 0x554) = *(undefined4 *)(plVar10[0x15] + 0x5c);
    cVar2 = (char)plVar10[0x19];
  }
  else {
    if ((int)plVar10[0x10] == 0) {
      lVar4 = 0x554;
      do {
        *(undefined4 *)(*plVar10 + lVar4 + -0x40) = *(undefined4 *)(plVar10[0x15] + lVar4 + -0x538);
        *(undefined4 *)(*plVar10 + lVar4 + -0x20) = *(undefined4 *)(plVar10[0x15] + lVar4 + -0x518);
        lVar8 = plVar10[0x15] + lVar4;
        puVar1 = (undefined4 *)(*plVar10 + lVar4);
        lVar4 = lVar4 + 4;
        *puVar1 = *(undefined4 *)(lVar8 + -0x4f8);
      } while (lVar4 != 0x574);
    }
    cVar2 = (char)plVar10[0x19];
  }
  if (cVar2 != '\0') {
    *(undefined4 *)(*plVar10 + 0x768) = *(undefined4 *)(plVar10[0x15] + 0x7c);
    *(undefined4 *)(*plVar10 + 0x76c) = *(undefined4 *)(plVar10[0x15] + 0x80);
    *(undefined4 *)(*plVar10 + 0x770) = *(undefined4 *)(plVar10[0x15] + 0x84);
    *(undefined4 *)(*plVar10 + 0x774) = *(undefined4 *)(plVar10[0x15] + 0x88);
    *(undefined4 *)(*plVar10 + 0x778) = *(undefined4 *)(plVar10[0x15] + 0x8c);
    *(undefined4 *)(*plVar10 + 0x77c) = *(undefined4 *)(plVar10[0x15] + 0x90);
  }
  *(uint *)(*plVar10 + 0x500) =
       *(uint *)(*plVar10 + 0x500) & 0xffffffeb | (uint)*(byte *)(plVar10[0x15] + 8) << 4 |
       (uint)(*(int *)(plVar10[0x15] + 4) == 1) << 2;
  *(uint *)(*plVar10 + 0x500) = *(uint *)(*plVar10 + 0x500) | 1;
LAB_00102c6c:
  if (((uint)plVar10[0xf] >> 1 & 1) != 0) {
    lVar4 = 0x808;
    do {
      lVar8 = plVar10[0x16] + lVar4;
      puVar1 = (undefined4 *)(*plVar10 + lVar4);
      lVar4 = lVar4 + 4;
      *puVar1 = *(undefined4 *)(lVar8 + -0x804);
    } while (lVar4 != 0x848);
    *(undefined4 *)(*plVar10 + 0x848) = *(undefined4 *)(plVar10[0x16] + 0x44);
    *(undefined4 *)(*plVar10 + 0x84c) = *(undefined4 *)(plVar10[0x16] + 0x48);
    *(undefined4 *)(*plVar10 + 0x850) = *(undefined4 *)(plVar10[0x16] + 0x4c);
    *(undefined4 *)(*plVar10 + 0x854) = *(undefined4 *)(plVar10[0x16] + 0x50);
    *(undefined4 *)(*plVar10 + 0x858) = *(undefined4 *)(plVar10[0x16] + 0x54);
    *(undefined4 *)(*plVar10 + 0x85c) = *(undefined4 *)(plVar10[0x16] + 0x58);
    *(undefined4 *)(*plVar10 + 0x860) = *(undefined4 *)(plVar10[0x16] + 0x5c);
    *(undefined4 *)(*plVar10 + 0x864) = *(undefined4 *)(plVar10[0x16] + 0x60);
    *(undefined4 *)(*plVar10 + 0x788) = *(undefined4 *)(plVar10[0x16] + 100);
    *(undefined4 *)(*plVar10 + 0x7a8) = *(undefined4 *)(plVar10[0x16] + 0x84);
    *(undefined4 *)(*plVar10 + 0x78c) = *(undefined4 *)(plVar10[0x16] + 0x68);
    *(undefined4 *)(*plVar10 + 0x7ac) = *(undefined4 *)(plVar10[0x16] + 0x88);
    *(undefined4 *)(*plVar10 + 0x790) = *(undefined4 *)(plVar10[0x16] + 0x6c);
    *(undefined4 *)(*plVar10 + 0x7b0) = *(undefined4 *)(plVar10[0x16] + 0x8c);
    *(undefined4 *)(*plVar10 + 0x794) = *(undefined4 *)(plVar10[0x16] + 0x70);
    *(undefined4 *)(*plVar10 + 0x7b4) = *(undefined4 *)(plVar10[0x16] + 0x90);
    *(undefined4 *)(*plVar10 + 0x798) = *(undefined4 *)(plVar10[0x16] + 0x74);
    *(undefined4 *)(*plVar10 + 0x7b8) = *(undefined4 *)(plVar10[0x16] + 0x94);
    *(undefined4 *)(*plVar10 + 0x79c) = *(undefined4 *)(plVar10[0x16] + 0x78);
    *(undefined4 *)(*plVar10 + 0x7bc) = *(undefined4 *)(plVar10[0x16] + 0x98);
    *(undefined4 *)(*plVar10 + 0x7a0) = *(undefined4 *)(plVar10[0x16] + 0x7c);
    *(undefined4 *)(*plVar10 + 0x7c0) = *(undefined4 *)(plVar10[0x16] + 0x9c);
    *(undefined4 *)(*plVar10 + 0x7a4) = *(undefined4 *)(plVar10[0x16] + 0x80);
    *(undefined4 *)(*plVar10 + 0x7c4) = *(undefined4 *)(plVar10[0x16] + 0xa0);
    *(undefined4 *)(*plVar10 + 0x7c8) = *(undefined4 *)(plVar10[0x16] + 0xa8);
    *(undefined4 *)(*plVar10 + 0x7e8) = *(undefined4 *)(plVar10[0x16] + 200);
    *(undefined4 *)(*plVar10 + 0x7cc) = *(undefined4 *)(plVar10[0x16] + 0xac);
    *(undefined4 *)(*plVar10 + 0x7ec) = *(undefined4 *)(plVar10[0x16] + 0xcc);
    *(undefined4 *)(*plVar10 + 2000) = *(undefined4 *)(plVar10[0x16] + 0xb0);
    *(undefined4 *)(*plVar10 + 0x7f0) = *(undefined4 *)(plVar10[0x16] + 0xd0);
    *(undefined4 *)(*plVar10 + 0x7d4) = *(undefined4 *)(plVar10[0x16] + 0xb4);
    *(undefined4 *)(*plVar10 + 0x7f4) = *(undefined4 *)(plVar10[0x16] + 0xd4);
    *(undefined4 *)(*plVar10 + 0x7d8) = *(undefined4 *)(plVar10[0x16] + 0xb8);
    *(undefined4 *)(*plVar10 + 0x7f8) = *(undefined4 *)(plVar10[0x16] + 0xd8);
    *(undefined4 *)(*plVar10 + 0x7dc) = *(undefined4 *)(plVar10[0x16] + 0xbc);
    *(undefined4 *)(*plVar10 + 0x7fc) = *(undefined4 *)(plVar10[0x16] + 0xdc);
    *(undefined4 *)(*plVar10 + 0x7e0) = *(undefined4 *)(plVar10[0x16] + 0xc0);
    *(undefined4 *)(*plVar10 + 0x800) = *(undefined4 *)(plVar10[0x16] + 0xe0);
    *(undefined4 *)(*plVar10 + 0x7e4) = *(undefined4 *)(plVar10[0x16] + 0xc4);
    *(undefined4 *)(*plVar10 + 0x804) = *(undefined4 *)(plVar10[0x16] + 0xe4);
    *(undefined4 *)(*plVar10 + 0x86c) = *(undefined4 *)(plVar10[0x16] + 0xec);
    *(undefined4 *)(*plVar10 + 0x870) = *(undefined4 *)(plVar10[0x16] + 0xf0);
    *(undefined4 *)(*plVar10 + 0x874) = *(undefined4 *)(plVar10[0x16] + 0xf4);
    *(undefined4 *)(*plVar10 + 0x878) = *(undefined4 *)(plVar10[0x16] + 0xf8);
    *(undefined4 *)(*plVar10 + 0x87c) = *(undefined4 *)(plVar10[0x16] + 0xfc);
    *(undefined4 *)(*plVar10 + 0x880) = *(undefined4 *)(plVar10[0x16] + 0x100);
    *(undefined4 *)(*plVar10 + 0x884) = *(undefined4 *)(plVar10[0x16] + 0x104);
    *(undefined4 *)(*plVar10 + 0x888) = *(undefined4 *)(plVar10[0x16] + 0x108);
    uVar7 = *(uint *)(*plVar10 + 0x784);
    lVar4 = plVar10[0x16];
    if (*(char *)(lVar4 + 0xa4) == '\0') {
      uVar7 = uVar7 & 0xfffffffe;
    }
    else if (*(char *)(lVar4 + 0xa5) == '\0') {
      uVar7 = uVar7 & 0xfffffffb | 1;
    }
    else {
      uVar7 = uVar7 | 5;
    }
    *(uint *)(*plVar10 + 0x784) = uVar7 & 0xfffffffd | (uint)*(byte *)(lVar4 + 0xe8) << 1;
    if ((*(char *)((long)plVar10 + 0xc9) == '\0') && ((char)plVar10[0x19] != '\0')) {
      lVar4 = 0x980;
      do {
        lVar8 = plVar10[0x16] + lVar4;
        puVar1 = (undefined4 *)(*plVar10 + lVar4);
        lVar4 = lVar4 + 4;
        *puVar1 = *(undefined4 *)(lVar8 + -0x874);
      } while (lVar4 != 0xa00);
    }
    uVar7 = *(uint *)plVar10[0x16];
    *(uint *)(*plVar10 + 0x780) =
         *(uint *)(*plVar10 + 0x780) & 0xffffe000 |
         *(uint *)(*plVar10 + 0x780) & 0x181 | (uVar7 & 7) << 9 | uVar7 >> 2 & 0x7e |
         (uint)*(byte *)(plVar10[0x16] + 0xe9) << 0xc;
    *(uint *)(*plVar10 + 0x780) = *(uint *)(*plVar10 + 0x780) | 1;
    if ((*(char *)((long)plVar10 + 0xc9) != '\0') && ((char)plVar10[0x19] != '\0')) {
      lVar4 = 0x980;
      do {
        lVar8 = plVar10[0x16] + lVar4;
        puVar1 = (undefined4 *)(*plVar10 + lVar4);
        lVar4 = lVar4 + 4;
        *puVar1 = *(undefined4 *)(lVar8 + -0x874);
      } while (lVar4 != 0xa00);
    }
  }
  if (((uint)plVar10[0xf] >> 2 & 1) == 0) {
    if (((uint)plVar10[0xf] >> 6 & 1) != 0) {
      pbVar5 = *(byte **)(plVar10[0x17] + 0xb8);
      *(undefined4 *)(*plVar10 + 0xa08) = *(undefined4 *)(plVar10[0x17] + 8);
      *(undefined4 *)(*plVar10 + 0xa10) = *(undefined4 *)(plVar10[0x17] + 0x10);
      *(undefined4 *)(*plVar10 + 0xa18) = *(undefined4 *)(plVar10[0x17] + 0x1c);
      *(undefined4 *)(*plVar10 + 0xa20) = *(undefined4 *)(plVar10[0x17] + 0x24);
      *(undefined4 *)(*plVar10 + 0xa0c) = *(undefined4 *)(plVar10[0x17] + 0xc);
      *(undefined4 *)(*plVar10 + 0xa14) = *(undefined4 *)(plVar10[0x17] + 0x14);
      *(undefined4 *)(*plVar10 + 0xa1c) = *(undefined4 *)(plVar10[0x17] + 0x20);
      *(undefined4 *)(*plVar10 + 0xa24) = *(undefined4 *)(plVar10[0x17] + 0x28);
      lVar4 = plVar10[0x17];
      *(uint *)(*plVar10 + 0xa04) =
           *(uint *)(*plVar10 + 0xa04) & 0xfffffff8 | (uint)*(byte *)(lVar4 + 0x18) |
           (uint)*(byte *)(lVar4 + 0x2c) << 1 | (uint)*(byte *)(lVar4 + 0x2d) << 2;
      if ((*(char *)((long)plVar10 + 0xca) == '\0') && ((char)plVar10[0x19] != '\0')) {
        lVar4 = 0xa80;
        do {
          lVar8 = plVar10[0x17] + lVar4;
          puVar1 = (undefined4 *)(*plVar10 + lVar4);
          lVar4 = lVar4 + 4;
          *puVar1 = *(undefined4 *)(lVar8 + -0xa50);
        } while (lVar4 != 0xb00);
      }
      uVar7 = *(uint *)(*plVar10 + 0xa00) & 0xffe000f9;
      if (*(char *)plVar10[0x17] != '\0') {
        uVar7 = *(uint *)(*plVar10 + 0xa00) | 2;
      }
      uVar7 = uVar7 & 0xffe00000 |
              uVar7 & 0xfb | (*(uint *)((char *)plVar10[0x17] + 4) & 3) << 8 | (*pbVar5 & 7) << 0x12
              | (uint)pbVar5[1] << 10;
      *(uint *)(*plVar10 + 0xa00) = uVar7;
      *(uint *)(*plVar10 + 0xa00) = uVar7 | 1;
    }
  }
  else {
    *(undefined4 *)(*plVar10 + 0xa08) = *(undefined4 *)(plVar10[0x17] + 8);
    *(undefined4 *)(*plVar10 + 0xa10) = *(undefined4 *)(plVar10[0x17] + 0x10);
    *(undefined4 *)(*plVar10 + 0xa18) = *(undefined4 *)(plVar10[0x17] + 0x1c);
    *(undefined4 *)(*plVar10 + 0xa20) = *(undefined4 *)(plVar10[0x17] + 0x24);
    *(undefined4 *)(*plVar10 + 0xa0c) = *(undefined4 *)(plVar10[0x17] + 0xc);
    *(undefined4 *)(*plVar10 + 0xa14) = *(undefined4 *)(plVar10[0x17] + 0x14);
    *(undefined4 *)(*plVar10 + 0xa1c) = *(undefined4 *)(plVar10[0x17] + 0x20);
    *(undefined4 *)(*plVar10 + 0xa24) = *(undefined4 *)(plVar10[0x17] + 0x28);
    lVar4 = plVar10[0x17];
    *(uint *)(*plVar10 + 0xa04) =
         *(uint *)(*plVar10 + 0xa04) & 0xfffffff8 | (uint)*(byte *)(lVar4 + 0x18) |
         (uint)*(byte *)(lVar4 + 0x2c) << 1 | (uint)*(byte *)(lVar4 + 0x2d) << 2;
    if ((*(char *)((long)plVar10 + 0xca) == '\0') && ((char)plVar10[0x19] != '\0')) {
      lVar4 = 0xa80;
      do {
        lVar8 = plVar10[0x17] + lVar4;
        puVar1 = (undefined4 *)(*plVar10 + lVar4);
        lVar4 = lVar4 + 4;
        *puVar1 = *(undefined4 *)(lVar8 + -0xa50);
      } while (lVar4 != 0xb00);
    }
    uVar7 = *(uint *)(*plVar10 + 0xa00) & 0xfffffcf9;
    if (*(char *)plVar10[0x17] != '\0') {
      uVar7 = *(uint *)(*plVar10 + 0xa00) | 2;
    }
    uVar7 = uVar7 & 0xfffffc00 | uVar7 & 0xfb | (*(uint *)((char *)plVar10[0x17] + 4) & 3) << 8;
    *(uint *)(*plVar10 + 0xa00) = uVar7;
    *(uint *)(*plVar10 + 0xa00) = uVar7 | 1;
  }
  DataSynchronizationBarrier(3,3,0);
  *(undefined4 *)(*plVar10 + 0xfb0) = 0;
  *(undefined1 *)(plVar10 + 0xd) = 1;
  mutex_unlock(plVar10 + 7);
  _dev_info(plVar10[1],"TPDM tracing enabled\n");
  return 0;
}



//------------------------------------------------------------
// tpdm_disable @ 00103598 size=356
// signature: undefined tpdm_disable(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void tpdm_disable(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  if ((char)plVar2[0xd] == '\0') {
    _dev_err(plVar2[1],"TPDM setup already disabled, Skipping disable\n");
    return;
  }
  mutex_lock(plVar2 + 7);
  *(undefined4 *)(*plVar2 + 0xfb0) = 0xc5acce55;
  DataSynchronizationBarrier(3,3,0);
  if (((uint)plVar2[0xf] >> 4 & 1) == 0) {
    uVar1 = (uint)plVar2[0xf];
  }
  else {
    *(uint *)(*plVar2 + 0x280) = *(uint *)(*plVar2 + 0x280) & 0xfffffffe;
    uVar1 = (uint)plVar2[0xf];
  }
  if ((uVar1 >> 3 & 1) == 0) {
    uVar1 = (uint)plVar2[0xf];
  }
  else {
    *(uint *)(*plVar2 + 0x500) = *(uint *)(*plVar2 + 0x500) & 0xfffffffe;
    uVar1 = (uint)plVar2[0xf];
  }
  if ((uVar1 >> 1 & 1) == 0) {
    uVar1 = (uint)plVar2[0xf];
  }
  else {
    *(uint *)(*plVar2 + 0x780) = *(uint *)(*plVar2 + 0x780) & 0xfffffffe;
    uVar1 = (uint)plVar2[0xf];
  }
  if (((uVar1 >> 2 & 1) != 0) || (((uint)plVar2[0xf] >> 6 & 1) != 0)) {
    *(uint *)(*plVar2 + 0xa00) = *(uint *)(*plVar2 + 0xa00) & 0xfffffffe;
  }
  if (*(char *)((long)plVar2 + 0x69) != '\0') {
    *(undefined4 *)(*plVar2 + 0x220) = 0;
  }
  DataSynchronizationBarrier(3,3,0);
  *(undefined4 *)(*plVar2 + 0xfb0) = 0;
  *(undefined1 *)(plVar2 + 0xd) = 0;
  mutex_unlock(plVar2 + 7);
  _dev_info(plVar2[1],"TPDM tracing disabled\n");
  return;
}



//------------------------------------------------------------
// available_datasets_show @ 00103700 size=436
// signature: undefined available_datasets_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

long available_datasets_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((*(ulong *)(lVar4 + 0x70) & 1) == 0) {
    lVar3 = 0;
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bd94,"IMPLDEF");
    lVar3 = (long)iVar1;
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  if ((uVar2 >> 1 & 1) != 0) {
    iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010bd94,&DAT_0010bdaa);
    lVar3 = lVar3 + iVar1;
  }
  if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) == 0) {
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  else {
    iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010bd94,&DAT_0010bdae);
    lVar3 = lVar3 + iVar1;
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  if ((uVar2 >> 3 & 1) == 0) {
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  else {
    iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010bd94,&DAT_0010be7b);
    lVar3 = lVar3 + iVar1;
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  if ((uVar2 >> 4 & 1) == 0) {
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  else {
    iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010bd94,&DAT_0010c099);
    lVar3 = lVar3 + iVar1;
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  if ((uVar2 >> 5 & 1) == 0) {
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  else {
    iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010bd94,&DAT_0010c095);
    lVar3 = lVar3 + iVar1;
    uVar2 = (uint)*(undefined8 *)(lVar4 + 0x70);
  }
  if ((uVar2 >> 6 & 1) != 0) {
    iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010bd94,&DAT_0010be23);
    lVar3 = lVar3 + iVar1;
  }
  iVar1 = scnprintf(param_3 + lVar3,0x1000 - lVar3,&DAT_0010c169);
  return lVar3 + iVar1;
}



//------------------------------------------------------------
// enable_datasets_show @ 001038b8 size=120
// signature: undefined enable_datasets_show(void)
// callers: []
//------------------------------------------------------------

long enable_datasets_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  iVar1 = scnprintf(param_3,0x1000,"%*pb\n",0x20,*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x78)
  ;
  lVar2 = (long)iVar1;
  if (lVar2 - 0xfffU < 2) {
    lVar2 = -0x16;
  }
  else {
    iVar1 = scnprintf(param_3 + lVar2,2,&DAT_0010c169);
    lVar2 = lVar2 + iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// enable_datasets_store @ 00103934 size=272
// signature: undefined enable_datasets_store(void)
// callers: []
//------------------------------------------------------------

undefined8
enable_datasets_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  ulong local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_40 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    mutex_lock(lVar6 + 0x38);
    if (*(char *)(lVar6 + 0x68) == '\0') {
      uVar3 = 0;
      lVar1 = lVar6 + 0x78;
      do {
        uVar4 = 1L << (uVar3 & 0x3f);
        if (((*(ulong *)(lVar6 + 0x70) & uVar4) == 0) || ((local_40 & uVar4) == 0)) {
          uVar4 = uVar3 >> 3 & 0x1ffffffffffffff8;
          uVar5 = *(ulong *)(lVar1 + uVar4) & (1L << (uVar3 & 0x3f) ^ 0xffffffffffffffffU);
        }
        else {
          uVar4 = uVar3 >> 3 & 0x1ffffffffffffff8;
          uVar5 = *(ulong *)(lVar1 + uVar4) | 1L << (uVar3 & 0x3f);
        }
        uVar3 = uVar3 + 1;
        *(ulong *)(lVar1 + uVar4) = uVar5;
      } while (uVar3 != 0x20);
    }
    else {
      param_4 = 0xffffffffffffffff;
    }
    mutex_unlock(lVar6 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// reset_store @ 00103a48 size=476
// signature: undefined reset_store(void)
// callers: []
//------------------------------------------------------------

long reset_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined8 *puVar2;
  undefined2 *puVar3;
  long lVar4;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 != 0) {
    param_4 = (long)iVar1;
    goto LAB_00103bf0;
  }
  mutex_lock(lVar4 + 0x38);
  if (*(void **)(lVar4 + 0x98) != (void *)0x0) {
    memset(*(void **)(lVar4 + 0x98),0,0x298);
  }
  if (*(void **)(lVar4 + 0xa0) != (void *)0x0) {
    memset(*(void **)(lVar4 + 0xa0),0,0x148);
  }
  puVar2 = *(undefined8 **)(lVar4 + 0xa8);
  if (puVar2 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar2 + 0x12) = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
  }
  if (*(void **)(lVar4 + 0xb0) != (void *)0x0) {
    memset(*(void **)(lVar4 + 0xb0),0,0x18c);
  }
  puVar2 = *(undefined8 **)(lVar4 + 0xb8);
  if (puVar2 != (undefined8 *)0x0) {
    puVar3 = (undefined2 *)puVar2[0x17];
    if (puVar3 != (undefined2 *)0x0) {
      *puVar3 = 0;
      puVar2 = *(undefined8 **)(lVar4 + 0xb8);
    }
    puVar2[0x16] = 0;
    puVar2[0x17] = 0;
    puVar2[0x14] = 0;
    puVar2[0x15] = 0;
    puVar2[0x12] = 0;
    puVar2[0x13] = 0;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar2[0xc] = 0;
    puVar2[0xd] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined2 **)(*(long *)(lVar4 + 0xb8) + 0xb8) = puVar3;
  }
  if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 4 & 1) == 0) {
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 3 & 1) != 0) goto LAB_00103b98;
LAB_00103b74:
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) != 0) goto LAB_00103ba8;
LAB_00103b7c:
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) != 0) goto LAB_00103bcc;
LAB_00103bc4:
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 6 & 1) != 0) goto LAB_00103bcc;
  }
  else {
    *(undefined4 *)(*(long *)(lVar4 + 0xa0) + 4) = 0;
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 3 & 1) == 0) goto LAB_00103b74;
LAB_00103b98:
    *(undefined4 *)(*(long *)(lVar4 + 0xa8) + 4) = 0;
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) == 0) goto LAB_00103b7c;
LAB_00103ba8:
    *(undefined1 *)(*(long *)(lVar4 + 0xb0) + 0xe8) = 1;
    *(undefined1 *)(*(long *)(lVar4 + 0xb0) + 0xe9) = 0;
    if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) == 0) goto LAB_00103bc4;
LAB_00103bcc:
    *(undefined1 *)(*(long *)(lVar4 + 0xb8) + 0x2c) = 1;
  }
  mutex_unlock(lVar4 + 0x38);
  if (*(char *)(lVar4 + 0x68) != '\0') {
    coresight_disable(*(undefined8 *)(lVar4 + 0x10));
  }
LAB_00103bf0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// integration_test_store @ 00103c28 size=320
// signature: undefined integration_test_store(void)
// callers: []
//------------------------------------------------------------

long integration_test_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,10,&local_30);
  if (iVar3 == 0) {
    if ((local_30 - 3U < 0xfffffffffffffffe) || ((char)plVar4[0xd] == '\0')) {
      param_4 = -0x16;
    }
    else {
      bVar2 = local_30 != 1;
      local_30 = 0xc01f1409;
      if (bVar2) {
        local_30 = 0xc00f1409;
      }
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xf00) = 1;
      *(undefined4 *)(*plVar4 + 0xef0) = (undefined4)local_30;
      *(undefined4 *)(*plVar4 + 0xef0) = (undefined4)local_30;
      *(undefined4 *)(*plVar4 + 0xef0) = (undefined4)local_30;
      *(undefined4 *)(*plVar4 + 0xef0) = (undefined4)local_30;
      *(undefined4 *)(*plVar4 + 0xf00) = 0;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
    }
  }
  else {
    param_4 = (long)iVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// gp_regs_show @ 00103d6c size=204
// signature: undefined gp_regs_show(void)
// callers: []
//------------------------------------------------------------

long gp_regs_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 5 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar4 + 0x38);
    uVar3 = 0;
    lVar2 = 0;
    do {
      if ((*(ulong *)(*(long *)(lVar4 + 0x98) + (uVar3 >> 3 & 0x1ffffffffffffff8)) >> (uVar3 & 0x3f)
          & 1) != 0) {
        iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",
                          uVar3 & 0xffffffff,
                          *(undefined4 *)(*(long *)(lVar4 + 0x98) + uVar3 * 4 + 0x18));
        lVar2 = lVar2 + iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0xa0);
    mutex_unlock(lVar4 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// gp_regs_store @ 00103e3c size=244
// signature: undefined gp_regs_store(void)
// callers: []
//------------------------------------------------------------

void gp_regs_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar1 == 2) {
    uVar2 = 0xffffffffffffffff;
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 5 & 1) != 0) && (local_40 < 0xa0)) {
      mutex_lock(lVar4 + 0x38);
      *(int *)(*(long *)(lVar4 + 0x98) + local_40 * 4 + 0x18) = (int)local_48;
      uVar3 = local_40 >> 3 & 0x1ffffffffffffff8;
      *(ulong *)(*(long *)(lVar4 + 0x98) + uVar3) =
           *(ulong *)(*(long *)(lVar4 + 0x98) + uVar3) | 1L << (local_40 & 0x3f);
      mutex_unlock(lVar4 + 0x38);
      uVar2 = param_4;
    }
  }
  else {
    uVar2 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// bc_capture_mode_show @ 00103f34 size=108
// signature: undefined bc_capture_mode_show(void)
// callers: []
//------------------------------------------------------------

long bc_capture_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) {
    lVar3 = -1;
  }
  else {
    puVar1 = &DAT_0010c0a0;
    if (**(int **)(lVar3 + 0xa0) != 0) {
      puVar1 = &DAT_0010bcc4;
    }
    iVar2 = scnprintf(param_3,0x1000,&DAT_0010c09c,puVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// bc_capture_mode_store @ 00103fa4 size=368
// signature: undefined bc_capture_mode_store(void)
// callers: []
//------------------------------------------------------------

ulong bc_capture_mode_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (param_4 < 0x14) {
    iVar2 = sscanf(param_3,"%s",&local_50);
    if (iVar2 == 1) {
      if (((uint)plVar4[0xf] >> 4 & 1) == 0) {
        param_4 = 0xffffffffffffffff;
        goto LAB_00104018;
      }
      mutex_lock(plVar4 + 7);
      if ((char)plVar4[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else {
        if ((int)local_50 == 0x425441) {
          uVar3 = 0;
        }
        else {
          if (((int)local_50 != 0x425041) || (*(int *)(plVar4[0x14] + 4) != 1)) {
            param_4 = 0xffffffffffffffea;
            goto LAB_00104104;
          }
          *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
          DataSynchronizationBarrier(3,3,0);
          *(uint *)(*plVar4 + 0x280) = *(uint *)(*plVar4 + 0x280) | 8;
          DataSynchronizationBarrier(3,3,0);
          uVar3 = 1;
          *(undefined4 *)(*plVar4 + 0xfb0) = 0;
        }
        *(undefined4 *)plVar4[0x14] = uVar3;
      }
LAB_00104104:
      mutex_unlock(plVar4 + 7);
      goto LAB_00104018;
    }
  }
  param_4 = 0xffffffffffffffea;
LAB_00104018:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_retrieval_mode_show @ 00104118 size=108
// signature: undefined bc_retrieval_mode_show(void)
// callers: []
//------------------------------------------------------------

long bc_retrieval_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) {
    lVar3 = -1;
  }
  else {
    puVar1 = &DAT_0010c0a0;
    if (*(int *)(*(long *)(lVar3 + 0xa0) + 4) != 0) {
      puVar1 = &DAT_0010bcc4;
    }
    iVar2 = scnprintf(param_3,0x1000,&DAT_0010c09c,puVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// bc_retrieval_mode_store @ 00104188 size=272
// signature: undefined bc_retrieval_mode_store(void)
// callers: []
//------------------------------------------------------------

ulong bc_retrieval_mode_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (param_4 < 0x14) {
    iVar1 = sscanf(param_3,"%s",&local_50);
    if (iVar1 == 1) {
      if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) {
        param_4 = 0xffffffffffffffff;
        goto LAB_001041fc;
      }
      mutex_lock(lVar3 + 0x38);
      if (*(char *)(lVar3 + 0x68) == '\0') {
        if ((int)local_50 == 0x425441) {
          uVar2 = 0;
        }
        else {
          if ((int)local_50 != 0x425041) {
            param_4 = 0xffffffffffffffea;
            goto LAB_00104288;
          }
          uVar2 = 1;
        }
        *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 4) = uVar2;
      }
      else {
        param_4 = 0xffffffffffffffff;
      }
LAB_00104288:
      mutex_unlock(lVar3 + 0x38);
      goto LAB_001041fc;
    }
  }
  param_4 = 0xffffffffffffffea;
LAB_001041fc:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_reset_counters_store @ 0010429c size=272
// signature: undefined bc_reset_counters_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_reset_counters_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if (iVar3 == 0) {
    if (((uint)plVar4[0xf] >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar4 + 7);
      if ((char)plVar4[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        uVar1 = *(uint *)(*plVar4 + 0x280) | 2;
        local_40 = (ulong)uVar1;
        *(uint *)(*plVar4 + 0x280) = uVar1;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      }
      mutex_unlock(plVar4 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_sat_mode_show @ 001043b0 size=84
// signature: undefined bc_sat_mode_show(void)
// callers: []
//------------------------------------------------------------

long bc_sat_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa0) + 8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_sat_mode_store @ 00104408 size=184
// signature: undefined bc_sat_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bc_sat_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa0) + 8) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_enable_counters_show @ 001044c4 size=84
// signature: undefined bc_enable_counters_show(void)
// callers: []
//------------------------------------------------------------

long bc_enable_counters_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa0) + 0xc));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_enable_counters_store @ 0010451c size=184
// signature: undefined bc_enable_counters_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_enable_counters_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa0) + 0xc) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_clear_counters_show @ 001045d8 size=84
// signature: undefined bc_clear_counters_show(void)
// callers: []
//------------------------------------------------------------

long bc_clear_counters_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa0) + 0x10));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_clear_counters_store @ 00104630 size=184
// signature: undefined bc_clear_counters_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_clear_counters_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa0) + 0x10) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_enable_irq_show @ 001046ec size=84
// signature: undefined bc_enable_irq_show(void)
// callers: []
//------------------------------------------------------------

long bc_enable_irq_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa0) + 0x14));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_enable_irq_store @ 00104744 size=184
// signature: undefined bc_enable_irq_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_enable_irq_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa0) + 0x14) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_clear_irq_show @ 00104800 size=84
// signature: undefined bc_clear_irq_show(void)
// callers: []
//------------------------------------------------------------

long bc_clear_irq_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa0) + 0x18));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_clear_irq_store @ 00104858 size=184
// signature: undefined bc_clear_irq_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bc_clear_irq_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa0) + 0x18) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_trig_val_lo_show @ 00104914 size=176
// signature: undefined bc_trig_val_lo_show(void)
// callers: []
//------------------------------------------------------------

long bc_trig_val_lo_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar4 + 0x38);
    uVar3 = 0;
    lVar2 = 0;
    do {
      iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",
                        uVar3 & 0xffffffff,
                        *(undefined4 *)(*(long *)(lVar4 + 0xa0) + uVar3 * 4 + 0x1c));
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + iVar1;
    } while (uVar3 != 0x20);
    mutex_unlock(lVar4 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_trig_val_lo_store @ 001049c8 size=256
// signature: undefined bc_trig_val_lo_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bc_trig_val_lo_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    if ((((((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) ||
         (*(uint *)(lVar3 + 0x8c) <= local_40)) || (*(int *)(lVar3 + 0x84) == 2)) ||
       ((*(int *)(lVar3 + 0x84) == 1 && (local_40 != 0)))) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar3 + 0x38);
      if (0x1f < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104ac8);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar3 + 0xa0) + local_40 * 4 + 0x1c) = (int)local_48;
      mutex_unlock(lVar3 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_trig_val_hi_show @ 00104acc size=176
// signature: undefined bc_trig_val_hi_show(void)
// callers: []
//------------------------------------------------------------

long bc_trig_val_hi_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar4 + 0x38);
    uVar3 = 0;
    lVar2 = 0;
    do {
      iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",
                        uVar3 & 0xffffffff,
                        *(undefined4 *)(*(long *)(lVar4 + 0xa0) + uVar3 * 4 + 0x9c));
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + iVar1;
    } while (uVar3 != 0x20);
    mutex_unlock(lVar4 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_trig_val_hi_store @ 00104b80 size=256
// signature: undefined bc_trig_val_hi_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bc_trig_val_hi_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    if ((((((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) ||
         (*(uint *)(lVar3 + 0x8c) <= local_40)) || (*(int *)(lVar3 + 0x84) == 2)) ||
       ((*(int *)(lVar3 + 0x84) == 1 && (local_40 != 0)))) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar3 + 0x38);
      if (0x1f < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104c80);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar3 + 0xa0) + local_40 * 4 + 0x9c) = (int)local_48;
      mutex_unlock(lVar3 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_enable_ganging_show @ 00104c84 size=84
// signature: undefined bc_enable_ganging_show(void)
// callers: []
//------------------------------------------------------------

long bc_enable_ganging_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa0) + 0x11c))
    ;
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_enable_ganging_store @ 00104cdc size=184
// signature: undefined bc_enable_ganging_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_enable_ganging_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa0) + 0x11c) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_overflow_val_show @ 00104d98 size=304
// signature: undefined bc_overflow_val_show(void)
// callers: []
//------------------------------------------------------------

long bc_overflow_val_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x120));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x124));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x128));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 300));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x130));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x134));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_overflow_val_store @ 00104ecc size=224
// signature: undefined bc_overflow_val_store(void)
// callers: []
//------------------------------------------------------------

void bc_overflow_val_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    uVar3 = 0xffffffffffffffff;
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 4 & 1) != 0) && (local_40 < 6)) {
      mutex_lock(lVar4 + 0x38);
      if (5 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104fac);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xa0) + local_40 * 4 + 0x120) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// bc_ovsr_show @ 00104fb0 size=192
// signature: undefined bc_ovsr_show(void)
// callers: []
//------------------------------------------------------------

long bc_ovsr_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x3c0);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// bc_ovsr_store @ 00105074 size=256
// signature: undefined bc_ovsr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bc_ovsr_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x3c0) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_counter_sel_show @ 00105178 size=192
// signature: undefined bc_counter_sel_show(void)
// callers: []
//------------------------------------------------------------

long bc_counter_sel_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x3c4);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// bc_counter_sel_store @ 0010523c size=264
// signature: undefined bc_counter_sel_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_counter_sel_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if (((char)plVar3[0xd] == '\0') || (*(uint *)((long)plVar3 + 0x8c) <= local_40)) {
        param_4 = 0xffffffffffffffff;
      }
      else {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x3c4) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_count_val_lo_show @ 00105348 size=192
// signature: undefined bc_count_val_lo_show(void)
// callers: []
//------------------------------------------------------------

long bc_count_val_lo_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x3c8);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// bc_count_val_lo_store @ 0010540c size=300
// signature: undefined bc_count_val_lo_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_count_val_lo_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_001054e0;
  }
  if (((uint)plVar3[0xf] >> 4 & 1) == 0) {
    param_4 = 0xffffffffffffffff;
    goto LAB_001054e0;
  }
  mutex_lock(plVar3 + 7);
  if ((char)plVar3[0xd] == '\0') {
LAB_001054d4:
    param_4 = 0xffffffffffffffff;
  }
  else if (local_40 != 0) {
    *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    if ((1L << ((ulong)*(uint *)(*plVar3 + 0x3c4) & 0x3f) & (ulong)*(uint *)(*plVar3 + 0x288)) >>
        ((ulong)*(uint *)(*plVar3 + 0x3c4) & 0x3f) != 0) goto LAB_001054d4;
    *(undefined4 *)(*plVar3 + 0x3c8) = (undefined4)local_40;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar3 + 0xfb0) = 0;
  }
  mutex_unlock(plVar3 + 7);
LAB_001054e0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_count_val_hi_show @ 0010553c size=192
// signature: undefined bc_count_val_hi_show(void)
// callers: []
//------------------------------------------------------------

long bc_count_val_hi_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x3cc);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// bc_count_val_hi_store @ 00105600 size=300
// signature: undefined bc_count_val_hi_store(void)
// callers: []
//------------------------------------------------------------

undefined8
bc_count_val_hi_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_001056d4;
  }
  if (((uint)plVar3[0xf] >> 4 & 1) == 0) {
    param_4 = 0xffffffffffffffff;
    goto LAB_001056d4;
  }
  mutex_lock(plVar3 + 7);
  if ((char)plVar3[0xd] == '\0') {
LAB_001056c8:
    param_4 = 0xffffffffffffffff;
  }
  else if (local_40 != 0) {
    *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    if ((1L << ((ulong)*(uint *)(*plVar3 + 0x3c4) & 0x3f) & (ulong)*(uint *)(*plVar3 + 0x288)) >>
        ((ulong)*(uint *)(*plVar3 + 0x3c4) & 0x3f) != 0) goto LAB_001056c8;
    *(undefined4 *)(*plVar3 + 0x3cc) = (undefined4)local_40;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar3 + 0xfb0) = 0;
  }
  mutex_unlock(plVar3 + 7);
LAB_001056d4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_shadow_val_lo_show @ 00105730 size=264
// signature: undefined bc_shadow_val_lo_show(void)
// callers: []
//------------------------------------------------------------

long bc_shadow_val_lo_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  long *plVar4;
  int iVar5;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(plVar4 + 7);
    if ((char)plVar4[0xd] == '\0') {
      lVar2 = -1;
    }
    else {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      if (*(int *)((long)plVar4 + 0x8c) == 0) {
        lVar2 = 0;
      }
      else {
        uVar3 = 0;
        lVar2 = 0;
        iVar5 = 0x3d0;
        do {
          iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",uVar3,
                            *(undefined4 *)(*plVar4 + (long)iVar5));
          lVar2 = lVar2 + iVar1;
          uVar3 = uVar3 + 1;
          iVar5 = iVar5 + 4;
        } while (uVar3 < *(uint *)((long)plVar4 + 0x8c));
      }
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
    }
    mutex_unlock(plVar4 + 7);
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_shadow_val_hi_show @ 0010583c size=264
// signature: undefined bc_shadow_val_hi_show(void)
// callers: []
//------------------------------------------------------------

long bc_shadow_val_hi_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  long *plVar4;
  int iVar5;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(plVar4 + 7);
    if ((char)plVar4[0xd] == '\0') {
      lVar2 = -1;
    }
    else {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      if (*(int *)((long)plVar4 + 0x8c) == 0) {
        lVar2 = 0;
      }
      else {
        uVar3 = 0;
        lVar2 = 0;
        iVar5 = 0x450;
        do {
          iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",uVar3,
                            *(undefined4 *)(*plVar4 + (long)iVar5));
          lVar2 = lVar2 + iVar1;
          uVar3 = uVar3 + 1;
          iVar5 = iVar5 + 4;
        } while (uVar3 < *(uint *)((long)plVar4 + 0x8c));
      }
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
    }
    mutex_unlock(plVar4 + 7);
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_sw_inc_show @ 00105948 size=192
// signature: undefined bc_sw_inc_show(void)
// callers: []
//------------------------------------------------------------

long bc_sw_inc_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 4 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x4d0);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// bc_sw_inc_store @ 00105a0c size=256
// signature: undefined bc_sw_inc_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bc_sw_inc_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 4 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x4d0) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// bc_msr_show @ 00105b10 size=232
// signature: undefined bc_msr_show(void)
// callers: []
//------------------------------------------------------------

long bc_msr_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar3 + 200) == '\0') {
    lVar2 = -0x16;
  }
  else if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%u 0x%x\n",0,*(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x138))
    ;
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x13c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x140));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa0) + 0x144));
    lVar2 = lVar2 + iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// bc_msr_store @ 00105bfc size=228
// signature: undefined bc_msr_store(void)
// callers: []
//------------------------------------------------------------

void bc_msr_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar3 + 200) == '\0') {
    uVar2 = 0xffffffffffffffea;
  }
  else if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 4 & 1) == 0) {
    uVar2 = 0xffffffffffffffff;
  }
  else {
    iVar1 = sscanf(param_3,"%u %x",(uint *)((long)&local_40 + 4),(uint *)&local_40);
    uVar2 = 0xffffffffffffffea;
    if ((iVar1 == 2) && (local_40._4_4_ < 4)) {
      mutex_lock(lVar3 + 0x38);
      *(uint *)(*(long *)(lVar3 + 0xa0) + (local_40 >> 0x20) * 4 + 0x138) = (uint)local_40;
      mutex_unlock(lVar3 + 0x38);
      uVar2 = param_4;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// tc_capture_mode_show @ 00105ce4 size=108
// signature: undefined tc_capture_mode_show(void)
// callers: []
//------------------------------------------------------------

long tc_capture_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    lVar3 = -1;
  }
  else {
    puVar1 = &DAT_0010c0a0;
    if (**(int **)(lVar3 + 0xa8) != 0) {
      puVar1 = &DAT_0010bcc4;
    }
    iVar2 = scnprintf(param_3,0x1000,&DAT_0010c09c,puVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// tc_capture_mode_store @ 00105d54 size=368
// signature: undefined tc_capture_mode_store(void)
// callers: []
//------------------------------------------------------------

ulong tc_capture_mode_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (param_4 < 0x14) {
    iVar2 = sscanf(param_3,"%s",&local_50);
    if (iVar2 == 1) {
      if (((uint)plVar4[0xf] >> 3 & 1) == 0) {
        param_4 = 0xffffffffffffffff;
        goto LAB_00105dc8;
      }
      mutex_lock(plVar4 + 7);
      if ((char)plVar4[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else {
        if ((int)local_50 == 0x425441) {
          uVar3 = 0;
        }
        else {
          if (((int)local_50 != 0x425041) || (*(int *)(plVar4[0x15] + 4) != 1)) {
            param_4 = 0xffffffffffffffea;
            goto LAB_00105eb4;
          }
          *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
          DataSynchronizationBarrier(3,3,0);
          *(uint *)(*plVar4 + 0x500) = *(uint *)(*plVar4 + 0x500) | 8;
          DataSynchronizationBarrier(3,3,0);
          uVar3 = 1;
          *(undefined4 *)(*plVar4 + 0xfb0) = 0;
        }
        *(undefined4 *)plVar4[0x15] = uVar3;
      }
LAB_00105eb4:
      mutex_unlock(plVar4 + 7);
      goto LAB_00105dc8;
    }
  }
  param_4 = 0xffffffffffffffea;
LAB_00105dc8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_retrieval_mode_show @ 00105ec8 size=108
// signature: undefined tc_retrieval_mode_show(void)
// callers: []
//------------------------------------------------------------

long tc_retrieval_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    lVar3 = -1;
  }
  else {
    puVar1 = &DAT_0010c0a0;
    if (*(int *)(*(long *)(lVar3 + 0xa8) + 4) != 0) {
      puVar1 = &DAT_0010bcc4;
    }
    iVar2 = scnprintf(param_3,0x1000,&DAT_0010c09c,puVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// tc_retrieval_mode_store @ 00105f38 size=272
// signature: undefined tc_retrieval_mode_store(void)
// callers: []
//------------------------------------------------------------

ulong tc_retrieval_mode_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (param_4 < 0x14) {
    iVar1 = sscanf(param_3,"%s",&local_50);
    if (iVar1 == 1) {
      if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
        param_4 = 0xffffffffffffffff;
        goto LAB_00105fac;
      }
      mutex_lock(lVar3 + 0x38);
      if (*(char *)(lVar3 + 0x68) == '\0') {
        if ((int)local_50 == 0x425441) {
          uVar2 = 0;
        }
        else {
          if ((int)local_50 != 0x425041) {
            param_4 = 0xffffffffffffffea;
            goto LAB_00106038;
          }
          uVar2 = 1;
        }
        *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 4) = uVar2;
      }
      else {
        param_4 = 0xffffffffffffffff;
      }
LAB_00106038:
      mutex_unlock(lVar3 + 0x38);
      goto LAB_00105fac;
    }
  }
  param_4 = 0xffffffffffffffea;
LAB_00105fac:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_reset_counters_store @ 0010604c size=272
// signature: undefined tc_reset_counters_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_reset_counters_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if (iVar3 == 0) {
    if (((uint)plVar4[0xe] >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar4 + 7);
      if ((char)plVar4[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        uVar1 = *(uint *)(*plVar4 + 0x500) | 2;
        local_40 = (ulong)uVar1;
        *(uint *)(*plVar4 + 0x500) = uVar1;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      }
      mutex_unlock(plVar4 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_sat_mode_show @ 00106160 size=84
// signature: undefined tc_sat_mode_show(void)
// callers: []
//------------------------------------------------------------

long tc_sat_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xa8) + 8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_sat_mode_store @ 001061b8 size=192
// signature: undefined tc_sat_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_sat_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xa8) + 8) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_enable_counters_show @ 0010627c size=84
// signature: undefined tc_enable_counters_show(void)
// callers: []
//------------------------------------------------------------

long tc_enable_counters_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa8) + 0xc));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_enable_counters_store @ 001062d4 size=200
// signature: undefined tc_enable_counters_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_enable_counters_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) ||
       (local_40 >> ((ulong)*(uint *)(lVar2 + 0x90) & 0x3f) != 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa8) + 0xc) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_clear_counters_show @ 001063a0 size=84
// signature: undefined tc_clear_counters_show(void)
// callers: []
//------------------------------------------------------------

long tc_clear_counters_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa8) + 0x10));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_clear_counters_store @ 001063f8 size=200
// signature: undefined tc_clear_counters_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_clear_counters_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) ||
       (local_40 >> ((ulong)*(uint *)(lVar2 + 0x90) & 0x3f) != 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa8) + 0x10) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_enable_irq_show @ 001064c4 size=84
// signature: undefined tc_enable_irq_show(void)
// callers: []
//------------------------------------------------------------

long tc_enable_irq_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa8) + 0x14));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_enable_irq_store @ 0010651c size=184
// signature: undefined tc_enable_irq_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_enable_irq_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa8) + 0x14) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_clear_irq_show @ 001065d8 size=84
// signature: undefined tc_clear_irq_show(void)
// callers: []
//------------------------------------------------------------

long tc_clear_irq_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,*(undefined4 *)(*(long *)(lVar2 + 0xa8) + 0x18));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_clear_irq_store @ 00106630 size=184
// signature: undefined tc_clear_irq_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_clear_irq_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xa8) + 0x18) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_trig_sel_show @ 001066ec size=368
// signature: undefined tc_trig_sel_show(void)
// callers: []
//------------------------------------------------------------

long tc_trig_sel_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x1c));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x20));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x24));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x28));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x2c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x30));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x34));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x38));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_trig_sel_store @ 00106860 size=252
// signature: undefined tc_trig_sel_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_trig_sel_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    if ((((((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) || (7 < local_40)) ||
        (*(int *)(lVar3 + 0x80) == 2)) || ((*(int *)(lVar3 + 0x80) == 1 && (local_40 != 0)))) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar3 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10695c);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar3 + 0xa8) + local_40 * 4 + 0x1c) = (int)local_48;
      mutex_unlock(lVar3 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_trig_val_lo_show @ 00106960 size=368
// signature: undefined tc_trig_val_lo_show(void)
// callers: []
//------------------------------------------------------------

long tc_trig_val_lo_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x3c));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x40));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x44));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x48));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x4c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x50));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x54));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x58));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_trig_val_lo_store @ 00106ad4 size=252
// signature: undefined tc_trig_val_lo_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_trig_val_lo_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    if ((((((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) || (7 < local_40)) ||
        (*(int *)(lVar3 + 0x80) == 2)) || ((*(int *)(lVar3 + 0x80) == 1 && (local_40 != 0)))) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar3 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x106bd0);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar3 + 0xa8) + local_40 * 4 + 0x3c) = (int)local_48;
      mutex_unlock(lVar3 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_trig_val_hi_show @ 00106bd4 size=368
// signature: undefined tc_trig_val_hi_show(void)
// callers: []
//------------------------------------------------------------

long tc_trig_val_hi_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x5c));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x60));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 100));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x68));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x6c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x70));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x74));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x78));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_trig_val_hi_store @ 00106d48 size=252
// signature: undefined tc_trig_val_hi_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_trig_val_hi_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    if ((((((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) || (7 < local_40)) ||
        (*(int *)(lVar3 + 0x80) == 2)) || ((*(int *)(lVar3 + 0x80) == 1 && (local_40 != 0)))) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar3 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x106e44);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar3 + 0xa8) + local_40 * 4 + 0x5c) = (int)local_48;
      mutex_unlock(lVar3 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_ovsr_gp_show @ 00106e48 size=192
// signature: undefined tc_ovsr_gp_show(void)
// callers: []
//------------------------------------------------------------

long tc_ovsr_gp_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xe] >> 3 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x580);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// tc_ovsr_gp_store @ 00106f0c size=256
// signature: undefined tc_ovsr_gp_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_ovsr_gp_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x580) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_ovsr_impl_show @ 00107010 size=192
// signature: undefined tc_ovsr_impl_show(void)
// callers: []
//------------------------------------------------------------

long tc_ovsr_impl_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x584);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// tc_ovsr_impl_store @ 001070d4 size=256
// signature: undefined tc_ovsr_impl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_ovsr_impl_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x584) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_counter_sel_show @ 001071d8 size=192
// signature: undefined tc_counter_sel_show(void)
// callers: []
//------------------------------------------------------------

long tc_counter_sel_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x588);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// tc_counter_sel_store @ 0010729c size=248
// signature: undefined tc_counter_sel_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_counter_sel_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x588) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_count_val_lo_show @ 00107398 size=192
// signature: undefined tc_count_val_lo_show(void)
// callers: []
//------------------------------------------------------------

long tc_count_val_lo_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x58c);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// tc_count_val_lo_store @ 0010745c size=304
// signature: undefined tc_count_val_lo_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_count_val_lo_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if (iVar3 != 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_00107534;
  }
  if (((uint)plVar4[0xf] >> 3 & 1) == 0) {
    param_4 = 0xffffffffffffffff;
    goto LAB_00107534;
  }
  mutex_lock(plVar4 + 7);
  if ((char)plVar4[0xd] == '\0') {
LAB_00107528:
    param_4 = 0xffffffffffffffff;
  }
  else if (local_40 != 0) {
    *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar1 = *(uint *)(*plVar4 + 0x588) >> 0xb & 3;
    if ((1L << uVar1 & (ulong)*(uint *)(*plVar4 + 0x504)) >> uVar1 != 0) goto LAB_00107528;
    *(undefined4 *)(*plVar4 + 0x58c) = (undefined4)local_40;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar4 + 0xfb0) = 0;
  }
  mutex_unlock(plVar4 + 7);
LAB_00107534:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_count_val_hi_show @ 00107590 size=192
// signature: undefined tc_count_val_hi_show(void)
// callers: []
//------------------------------------------------------------

long tc_count_val_hi_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x590);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// tc_count_val_hi_store @ 00107654 size=304
// signature: undefined tc_count_val_hi_store(void)
// callers: []
//------------------------------------------------------------

undefined8
tc_count_val_hi_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = kstrtoull(param_3,0x10,&local_40);
  if (iVar3 != 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_0010772c;
  }
  if (((uint)plVar4[0xf] >> 3 & 1) == 0) {
    param_4 = 0xffffffffffffffff;
    goto LAB_0010772c;
  }
  mutex_lock(plVar4 + 7);
  if ((char)plVar4[0xd] == '\0') {
LAB_00107720:
    param_4 = 0xffffffffffffffff;
  }
  else if (local_40 != 0) {
    *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar1 = *(uint *)(*plVar4 + 0x588) >> 0xb & 3;
    if ((1L << uVar1 & (ulong)*(uint *)(*plVar4 + 0x504)) >> uVar1 != 0) goto LAB_00107720;
    *(undefined4 *)(*plVar4 + 0x590) = (undefined4)local_40;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar4 + 0xfb0) = 0;
  }
  mutex_unlock(plVar4 + 7);
LAB_0010772c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_shadow_val_lo_show @ 00107788 size=244
// signature: undefined tc_shadow_val_lo_show(void)
// callers: []
//------------------------------------------------------------

long tc_shadow_val_lo_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(plVar4 + 7);
    if ((char)plVar4[0xd] == '\0') {
      lVar2 = -1;
    }
    else {
      uVar3 = 0;
      lVar2 = 0;
      lVar5 = 0x594;
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      do {
        iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",
                          uVar3 & 0xffffffff,*(undefined4 *)(*plVar4 + lVar5));
        uVar3 = uVar3 + 1;
        lVar2 = lVar2 + iVar1;
        lVar5 = lVar5 + 4;
      } while (uVar3 != 0x2c);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
    }
    mutex_unlock(plVar4 + 7);
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_shadow_val_hi_show @ 00107880 size=244
// signature: undefined tc_shadow_val_hi_show(void)
// callers: []
//------------------------------------------------------------

long tc_shadow_val_hi_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(plVar4 + 7);
    if ((char)plVar4[0xd] == '\0') {
      lVar2 = -1;
    }
    else {
      uVar3 = 0;
      lVar2 = 0;
      lVar5 = 0x644;
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      do {
        iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",
                          uVar3 & 0xffffffff,*(undefined4 *)(*plVar4 + lVar5));
        uVar3 = uVar3 + 1;
        lVar2 = lVar2 + iVar1;
        lVar5 = lVar5 + 4;
      } while (uVar3 != 0x2c);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
    }
    mutex_unlock(plVar4 + 7);
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_sw_inc_show @ 00107978 size=192
// signature: undefined tc_sw_inc_show(void)
// callers: []
//------------------------------------------------------------

long tc_sw_inc_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)plVar4[0xf] >> 3 & 1) != 0) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0x700);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// tc_sw_inc_store @ 00107a3c size=256
// signature: undefined tc_sw_inc_store(void)
// callers: []
//------------------------------------------------------------

undefined8 tc_sw_inc_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xf] >> 3 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else if (local_40 != 0) {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x700) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// tc_msr_show @ 00107b40 size=296
// signature: undefined tc_msr_show(void)
// callers: []
//------------------------------------------------------------

long tc_msr_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar3 + 200) == '\0') {
    lVar2 = -0x16;
  }
  else if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%u 0x%x\n",0,*(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x7c));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x80));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x84));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x88));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x8c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xa8) + 0x90));
    lVar2 = lVar2 + iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// tc_msr_store @ 00107c6c size=228
// signature: undefined tc_msr_store(void)
// callers: []
//------------------------------------------------------------

void tc_msr_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar3 + 200) == '\0') {
    uVar2 = 0xffffffffffffffea;
  }
  else if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 3 & 1) == 0) {
    uVar2 = 0xffffffffffffffff;
  }
  else {
    iVar1 = sscanf(param_3,"%u %x",(uint *)((long)&local_40 + 4),(uint *)&local_40);
    uVar2 = 0xffffffffffffffea;
    if ((iVar1 == 2) && (local_40._4_4_ < 6)) {
      mutex_lock(lVar3 + 0x38);
      *(uint *)(*(long *)(lVar3 + 0xa8) + (local_40 >> 0x20) * 4 + 0x7c) = (uint)local_40;
      mutex_unlock(lVar3 + 0x38);
      uVar2 = param_4;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// dsb_mode_show @ 00107d54 size=84
// signature: undefined dsb_mode_show(void)
// callers: []
//------------------------------------------------------------

long dsb_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdd2,**(undefined4 **)(lVar2 + 0xb0));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_mode_store @ 00107dac size=188
// signature: undefined dsb_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dsb_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      **(uint **)(lVar2 + 0xb0) = (uint)local_40 & 0xfffffff;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_testmode_data_store @ 00107e6c size=272
// signature: undefined dsb_testmode_data_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dsb_testmode_data_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    if (((uint)plVar3[0xe] >> 1 & 1) != 0) {
      if (3 < local_40) goto LAB_00107ee0;
      mutex_lock(plVar3 + 7);
      lVar1 = plVar3[0xd];
      mutex_unlock(plVar3 + 7);
      if ((char)lVar1 != '\0') {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + local_40 * 4 + 0x868) = (undefined4)local_48;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
        goto LAB_00107ee4;
      }
    }
    param_4 = 0xffffffffffffffff;
  }
  else {
LAB_00107ee0:
    param_4 = 0xffffffffffffffea;
  }
LAB_00107ee4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_testmode_data_valid_store @ 00107f80 size=240
// signature: undefined dsb_testmode_data_valid_store(void)
// callers: []
//------------------------------------------------------------

undefined8
dsb_testmode_data_valid_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if (((uint)plVar3[0xe] >> 1 & 1) != 0) {
      mutex_lock(plVar3 + 7);
      lVar1 = plVar3[0xd];
      mutex_unlock(plVar3 + 7);
      if ((char)lVar1 != '\0') {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0x888) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
        goto LAB_0010803c;
      }
    }
    param_4 = 0xffffffffffffffff;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
LAB_0010803c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_edge_ctrl_show @ 00108074 size=176
// signature: undefined dsb_edge_ctrl_show(void)
// callers: []
//------------------------------------------------------------

long dsb_edge_ctrl_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar4 + 0x38);
    uVar3 = 0;
    lVar2 = 0;
    do {
      iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",uVar3 & 0xffffffff,
                        *(undefined4 *)(*(long *)(lVar4 + 0xb0) + uVar3 * 4 + 4));
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + iVar1;
    } while (uVar3 != 0x10);
    mutex_unlock(lVar4 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_edge_ctrl_store @ 00108128 size=356
// signature: undefined dsb_edge_ctrl_store(void)
// callers: []
//------------------------------------------------------------

void dsb_edge_ctrl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  ulong local_50;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  lVar9 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = sscanf(param_3,"%lx %lx %lx",&local_40,&local_48,&local_50);
  if (iVar5 == 3) {
    if (((uint)*(undefined8 *)(lVar9 + 0x70) >> 1 & 1) == 0) {
      uVar6 = 0xffffffffffffffff;
    }
    else {
      uVar6 = 0xffffffffffffffff;
      if (((local_40 < 0x100) && (local_48 < 0x100)) && (local_50 < 3)) {
        mutex_lock(lVar9 + 0x38);
        if ((ulong)(long)(int)local_40 <= local_48) {
          iVar5 = (int)local_40 << 1;
          uVar8 = local_40;
          do {
            iVar7 = (int)uVar8;
            iVar3 = iVar7 + 0xf;
            if (-1 < iVar7) {
              iVar3 = iVar7;
            }
            uVar2 = iVar3 >> 4;
            if (0xf < uVar2) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x108288);
              (*pcVar4)();
            }
            uVar8 = (ulong)(iVar7 + 1U);
            lVar1 = *(long *)(lVar9 + 0xb0) + (ulong)uVar2 * 4;
            uVar2 = iVar5 + uVar2 * -0x20;
            iVar5 = iVar5 + 2;
            *(uint *)(lVar1 + 4) =
                 *(uint *)(lVar1 + 4) &
                 ((int)(2L << ((ulong)(uVar2 + 1) & 0x3f)) + (int)(-1L << ((ulong)uVar2 & 0x3f)) ^
                 0xffffffffU) | (uint)(local_50 << ((ulong)uVar2 & 0x3f));
          } while ((ulong)(long)(int)(iVar7 + 1U) <= local_48);
        }
        mutex_unlock(lVar9 + 0x38);
        uVar6 = param_4;
      }
    }
  }
  else {
    uVar6 = 0xffffffffffffffea;
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// dsb_edge_ctrl_mask_show @ 00108290 size=368
// signature: undefined dsb_edge_ctrl_mask_show(void)
// callers: []
//------------------------------------------------------------

long dsb_edge_ctrl_mask_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index:0x%x Val:0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x44));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x48));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x4c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x50));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x54));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x58));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x5c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x60));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_edge_ctrl_mask_store @ 00108404 size=324
// signature: undefined dsb_edge_ctrl_mask_store(void)
// callers: []
//------------------------------------------------------------

void dsb_edge_ctrl_mask_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  long lVar11;
  ulong local_50;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  lVar11 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = sscanf(param_3,"%lx %lx %lx",&local_40,&local_48,&local_50);
  if (iVar5 == 3) {
    if (((uint)*(undefined8 *)(lVar11 + 0x70) >> 1 & 1) == 0) {
      uVar6 = 0xffffffffffffffff;
    }
    else {
      uVar6 = 0xffffffffffffffff;
      if ((local_40 < 0x100) && (local_48 < 0x100)) {
        mutex_lock(lVar11 + 0x38);
        uVar7 = (uint)local_40;
        uVar9 = local_40;
        while ((ulong)(long)(int)uVar7 <= local_48) {
          iVar8 = (int)uVar9;
          iVar5 = iVar8 + 0x1f;
          if (-1 < iVar8) {
            iVar5 = iVar8;
          }
          uVar2 = iVar5 >> 5;
          if (7 < uVar2) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x108544);
            (*pcVar4)();
          }
          lVar1 = *(long *)(lVar11 + 0xb0) + (ulong)uVar2 * 4;
          uVar7 = iVar8 + 1;
          uVar9 = (ulong)uVar7;
          uVar3 = *(uint *)(lVar1 + 0x44);
          uVar10 = (uint)(1L << ((ulong)(iVar8 + uVar2 * -0x20) & 0x3f));
          uVar2 = uVar3 & (uVar10 ^ 0xffffffff);
          if (local_50 != 0) {
            uVar2 = uVar3 | uVar10;
          }
          *(uint *)(lVar1 + 0x44) = uVar2;
        }
        mutex_unlock(lVar11 + 0x38);
        uVar6 = param_4;
      }
    }
  }
  else {
    uVar6 = 0xffffffffffffffea;
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// dsb_patt_val_show @ 0010854c size=368
// signature: undefined dsb_patt_val_show(void)
// callers: []
//------------------------------------------------------------

long dsb_patt_val_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 100));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x68));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x6c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x70));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x74));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x78));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x7c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x80));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_patt_val_store @ 001086c0 size=224
// signature: undefined dsb_patt_val_store(void)
// callers: []
//------------------------------------------------------------

void dsb_patt_val_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    uVar3 = 0xffffffffffffffff;
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) != 0) && (local_40 < 8)) {
      mutex_lock(lVar4 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1087a0);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xb0) + local_40 * 4 + 100) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// dsb_patt_mask_show @ 001087a4 size=368
// signature: undefined dsb_patt_mask_show(void)
// callers: []
//------------------------------------------------------------

long dsb_patt_mask_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x84));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x88));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x8c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x90));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x94));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x98));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x9c));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xa0));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_patt_mask_store @ 00108918 size=224
// signature: undefined dsb_patt_mask_store(void)
// callers: []
//------------------------------------------------------------

void dsb_patt_mask_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    uVar3 = 0xffffffffffffffff;
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) != 0) && (local_40 < 8)) {
      mutex_lock(lVar4 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1089f8);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xb0) + local_40 * 4 + 0x84) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// dsb_patt_ts_show @ 001089fc size=84
// signature: undefined dsb_patt_ts_show(void)
// callers: []
//------------------------------------------------------------

long dsb_patt_ts_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb0) + 0xa4));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_patt_ts_store @ 00108a54 size=192
// signature: undefined dsb_patt_ts_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dsb_patt_ts_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb0) + 0xa4) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_patt_type_show @ 00108b18 size=84
// signature: undefined dsb_patt_type_show(void)
// callers: []
//------------------------------------------------------------

long dsb_patt_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb0) + 0xa5));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_patt_type_store @ 00108b70 size=192
// signature: undefined dsb_patt_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8
dsb_patt_type_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb0) + 0xa5) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_trig_patt_val_show @ 00108c34 size=368
// signature: undefined dsb_trig_patt_val_show(void)
// callers: []
//------------------------------------------------------------

long dsb_trig_patt_val_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xa8));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xac));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xb0));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xb4));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xb8));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xbc));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xc0));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xc4));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_trig_patt_val_store @ 00108da8 size=224
// signature: undefined dsb_trig_patt_val_store(void)
// callers: []
//------------------------------------------------------------

void dsb_trig_patt_val_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    uVar3 = 0xffffffffffffffff;
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) != 0) && (local_40 < 8)) {
      mutex_lock(lVar4 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x108e88);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xb0) + local_40 * 4 + 0xa8) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// dsb_trig_patt_mask_show @ 00108e8c size=368
// signature: undefined dsb_trig_patt_mask_show(void)
// callers: []
//------------------------------------------------------------

long dsb_trig_patt_mask_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 200));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xcc));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xd0));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xd4));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xd8));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xdc));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xe0));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xe4));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_trig_patt_mask_store @ 00109000 size=224
// signature: undefined dsb_trig_patt_mask_store(void)
// callers: []
//------------------------------------------------------------

void dsb_trig_patt_mask_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar2 == 2) {
    uVar3 = 0xffffffffffffffff;
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) != 0) && (local_40 < 8)) {
      mutex_lock(lVar4 + 0x38);
      if (7 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1090e0);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xb0) + local_40 * 4 + 200) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// dsb_trig_ts_show @ 001090e4 size=84
// signature: undefined dsb_trig_ts_show(void)
// callers: []
//------------------------------------------------------------

long dsb_trig_ts_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb0) + 0xe8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_trig_ts_store @ 0010913c size=192
// signature: undefined dsb_trig_ts_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dsb_trig_ts_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb0) + 0xe8) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_trig_type_show @ 00109200 size=84
// signature: undefined dsb_trig_type_show(void)
// callers: []
//------------------------------------------------------------

long dsb_trig_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb0) + 0xe9));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_trig_type_store @ 00109258 size=192
// signature: undefined dsb_trig_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8
dsb_trig_type_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 1 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb0) + 0xe9) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsb_select_val_show @ 0010931c size=368
// signature: undefined dsb_select_val_show(void)
// callers: []
//------------------------------------------------------------

long dsb_select_val_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index:0x%x Val:0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xec));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xf0));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",2,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xf4));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",3,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xf8));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",4,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0xfc));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",5,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x100));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",6,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x104));
    lVar2 = lVar2 + iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index:0x%x Val:0x%x\n",7,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x108));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_select_val_store @ 00109490 size=300
// signature: undefined dsb_select_val_store(void)
// callers: []
//------------------------------------------------------------

void dsb_select_val_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar9 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar4 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  if (iVar4 == 2) {
    if (((uint)*(undefined8 *)(lVar9 + 0x70) >> 1 & 1) == 0) {
      uVar5 = 0xffffffffffffffff;
    }
    else {
      uVar5 = 0xffffffffffffffff;
      if ((local_40 < 0x100) && (local_48 < 0x100)) {
        mutex_lock(lVar9 + 0x38);
        uVar6 = (uint)local_40;
        uVar8 = local_40;
        while ((ulong)(long)(int)uVar6 <= local_48) {
          iVar7 = (int)uVar8;
          iVar4 = iVar7 + 0x1f;
          if (-1 < iVar7) {
            iVar4 = iVar7;
          }
          uVar2 = iVar4 >> 5;
          if (7 < uVar2) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1095b8);
            (*pcVar3)();
          }
          lVar1 = *(long *)(lVar9 + 0xb0) + (ulong)uVar2 * 4;
          uVar6 = iVar7 + 1;
          uVar8 = (ulong)uVar6;
          *(uint *)(lVar1 + 0xec) =
               *(uint *)(lVar1 + 0xec) | (uint)(1L << ((ulong)(iVar7 + uVar2 * -0x20) & 0x3f));
        }
        mutex_unlock(lVar9 + 0x38);
        uVar5 = param_4;
      }
    }
  }
  else {
    uVar5 = 0xffffffffffffffea;
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// dsb_msr_show @ 001095c0 size=164
// signature: undefined dsb_msr_show(void)
// callers: []
//------------------------------------------------------------

long dsb_msr_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar4 + 200) == '\0') {
    lVar2 = -0x16;
  }
  else if (((uint)*(undefined8 *)(lVar4 + 0x70) >> 1 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    uVar3 = 0;
    lVar2 = 0;
    do {
      iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",uVar3 & 0xffffffff,
                        *(undefined4 *)(*(long *)(lVar4 + 0xb0) + uVar3 * 4 + 0x10c));
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + iVar1;
    } while (uVar3 != 0x20);
  }
  return lVar2;
}



//------------------------------------------------------------
// dsb_msr_store @ 00109668 size=228
// signature: undefined dsb_msr_store(void)
// callers: []
//------------------------------------------------------------

void dsb_msr_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar3 + 200) == '\0') {
    uVar2 = 0xffffffffffffffea;
  }
  else if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 1 & 1) == 0) {
    uVar2 = 0xffffffffffffffff;
  }
  else {
    iVar1 = sscanf(param_3,"%u %x",(uint *)((long)&local_40 + 4),(uint *)&local_40);
    uVar2 = 0xffffffffffffffea;
    if ((iVar1 == 2) && (local_40._4_4_ < 0x20)) {
      mutex_lock(lVar3 + 0x38);
      *(uint *)(*(long *)(lVar3 + 0xb0) + (local_40 >> 0x20) * 4 + 0x10c) = (uint)local_40;
      mutex_unlock(lVar3 + 0x38);
      uVar2 = param_4;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// cmb_available_modes_show @ 00109750 size=56
// signature: undefined cmb_available_modes_show(void)
// callers: []
//------------------------------------------------------------

long cmb_available_modes_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010c09c,"continuous trace_on_change");
  return (long)iVar1;
}



//------------------------------------------------------------
// cmb_mode_show @ 0010978c size=120
// signature: undefined cmb_mode_show(void)
// callers: []
//------------------------------------------------------------

long cmb_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar3 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar3 + 0x70) >> 6 & 1) == 0)) {
    lVar3 = -1;
  }
  else {
    pcVar1 = "continuous";
    if (**(char **)(lVar3 + 0xb8) != '\0') {
      pcVar1 = "trace_on_change";
    }
    iVar2 = scnprintf(param_3,0x1000,"trace_mode: %s cycle_acc: %d\n",pcVar1,
                      *(undefined4 *)(*(char **)(lVar3 + 0xb8) + 4));
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// cmb_mode_store @ 00109808 size=224
// signature: undefined cmb_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cmb_mode_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_40 [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40[0] = 0;
  local_40[1] = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = sscanf(param_3,"%u %u",local_40 + 1,local_40);
  if (iVar1 == 2) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)*(undefined8 *)(lVar2 + 0xb8) = local_40[1] != 0;
      *(uint *)(*(long *)(lVar2 + 0xb8) + 4) = local_40[0];
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_patt_val_show @ 001098ec size=184
// signature: undefined cmb_patt_val_show(void)
// callers: []
//------------------------------------------------------------

long cmb_patt_val_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar3 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar3 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb8) + 8));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb8) + 0xc));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_patt_val_store @ 001099a8 size=236
// signature: undefined cmb_patt_val_store(void)
// callers: []
//------------------------------------------------------------

void cmb_patt_val_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 2) && (local_40 < 2)) {
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar4 + 0x70) >> 6 & 1) == 0)) {
      uVar3 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar4 + 0x38);
      if (1 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x109a94);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xb8) + local_40 * 4 + 8) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// cmb_patt_mask_show @ 00109a98 size=184
// signature: undefined cmb_patt_mask_show(void)
// callers: []
//------------------------------------------------------------

long cmb_patt_mask_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar3 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar3 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    mutex_lock(lVar3 + 0x38);
    iVar1 = scnprintf(param_3,0x1000,"Index: 0x%x Value: 0x%x\n",0,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb8) + 0x10));
    lVar2 = (long)iVar1;
    iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"Index: 0x%x Value: 0x%x\n",1,
                      *(undefined4 *)(*(long *)(lVar3 + 0xb8) + 0x14));
    lVar2 = lVar2 + iVar1;
    mutex_unlock(lVar3 + 0x38);
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_patt_mask_store @ 00109b54 size=236
// signature: undefined cmb_patt_mask_store(void)
// callers: []
//------------------------------------------------------------

void cmb_patt_mask_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_48;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = sscanf(param_3,"%lx %lx",&local_40,&local_48);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 2) && (local_40 < 2)) {
    if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar4 + 0x70) >> 6 & 1) == 0)) {
      uVar3 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar4 + 0x38);
      if (1 < local_40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x109c40);
        (*pcVar1)();
      }
      *(int *)(*(long *)(lVar4 + 0xb8) + local_40 * 4 + 0x10) = (int)local_48;
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// cmb_patt_ts_show @ 00109c44 size=92
// signature: undefined cmb_patt_ts_show(void)
// callers: []
//------------------------------------------------------------

long cmb_patt_ts_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb8) + 0x18));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_patt_ts_store @ 00109ca4 size=200
// signature: undefined cmb_patt_ts_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cmb_patt_ts_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb8) + 0x18) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_ts_all_show @ 00109d70 size=92
// signature: undefined cmb_ts_all_show(void)
// callers: []
//------------------------------------------------------------

long cmb_ts_all_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb8) + 0x2d));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_ts_all_store @ 00109dd0 size=200
// signature: undefined cmb_ts_all_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cmb_ts_all_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb8) + 0x2d) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_trig_patt_val_lsb_show @ 00109e9c size=92
// signature: undefined cmb_trig_patt_val_lsb_show(void)
// callers: []
//------------------------------------------------------------

long cmb_trig_patt_val_lsb_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%#lx\n",*(undefined4 *)(*(long *)(lVar2 + 0xb8) + 0x1c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_trig_patt_val_lsb_store @ 00109efc size=192
// signature: undefined cmb_trig_patt_val_lsb_store(void)
// callers: []
//------------------------------------------------------------

undefined8
cmb_trig_patt_val_lsb_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xb8) + 0x1c) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_trig_patt_mask_lsb_show @ 00109fc0 size=92
// signature: undefined cmb_trig_patt_mask_lsb_show(void)
// callers: []
//------------------------------------------------------------

long cmb_trig_patt_mask_lsb_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%#lx\n",*(undefined4 *)(*(long *)(lVar2 + 0xb8) + 0x24));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_trig_patt_mask_lsb_store @ 0010a020 size=192
// signature: undefined cmb_trig_patt_mask_lsb_store(void)
// callers: []
//------------------------------------------------------------

undefined8
cmb_trig_patt_mask_lsb_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xb8) + 0x24) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_trig_patt_val_msb_show @ 0010a0e4 size=92
// signature: undefined cmb_trig_patt_val_msb_show(void)
// callers: []
//------------------------------------------------------------

long cmb_trig_patt_val_msb_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%#lx\n",*(undefined4 *)(*(long *)(lVar2 + 0xb8) + 0x20));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_trig_patt_val_msb_store @ 0010a144 size=192
// signature: undefined cmb_trig_patt_val_msb_store(void)
// callers: []
//------------------------------------------------------------

undefined8
cmb_trig_patt_val_msb_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xb8) + 0x20) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_trig_patt_mask_msb_show @ 0010a208 size=92
// signature: undefined cmb_trig_patt_mask_msb_show(void)
// callers: []
//------------------------------------------------------------

long cmb_trig_patt_mask_msb_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"%#lx\n",*(undefined4 *)(*(long *)(lVar2 + 0xb8) + 0x28));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_trig_patt_mask_msb_store @ 0010a268 size=192
// signature: undefined cmb_trig_patt_mask_msb_store(void)
// callers: []
//------------------------------------------------------------

undefined8
cmb_trig_patt_mask_msb_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(int *)(*(long *)(lVar2 + 0xb8) + 0x28) = (int)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_trig_ts_show @ 0010a32c size=92
// signature: undefined cmb_trig_ts_show(void)
// callers: []
//------------------------------------------------------------

long cmb_trig_ts_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,*(undefined1 *)(*(long *)(lVar2 + 0xb8) + 0x2c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_trig_ts_store @ 0010a38c size=200
// signature: undefined cmb_trig_ts_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cmb_trig_ts_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if ((((uint)*(undefined8 *)(lVar2 + 0x70) >> 2 & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar2 + 0x38);
      *(bool *)(*(long *)(lVar2 + 0xb8) + 0x2c) = local_40 != 0;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_msr_show @ 0010a458 size=172
// signature: undefined cmb_msr_show(void)
// callers: []
//------------------------------------------------------------

long cmb_msr_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar4 + 200) == '\0') {
    lVar2 = -0x16;
  }
  else if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) == 0) &&
          (((uint)*(undefined8 *)(lVar4 + 0x70) >> 6 & 1) == 0)) {
    lVar2 = -1;
  }
  else {
    uVar3 = 0;
    lVar2 = 0;
    do {
      iVar1 = scnprintf(param_3 + lVar2,0x1000 - lVar2,"%u 0x%x\n",uVar3 & 0xffffffff,
                        *(undefined4 *)(*(long *)(lVar4 + 0xb8) + uVar3 * 4 + 0x30));
      uVar3 = uVar3 + 1;
      lVar2 = lVar2 + iVar1;
    } while (uVar3 != 0x20);
  }
  return lVar2;
}



//------------------------------------------------------------
// cmb_msr_store @ 0010a508 size=252
// signature: undefined cmb_msr_store(void)
// callers: []
//------------------------------------------------------------

void cmb_msr_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint local_40 [2];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40[0] = 0;
  local_40[1] = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(char *)(lVar4 + 200) == '\0') {
    uVar3 = 0xffffffffffffffea;
  }
  else if ((((uint)*(undefined8 *)(lVar4 + 0x70) >> 2 & 1) == 0) &&
          (((uint)*(undefined8 *)(lVar4 + 0x70) >> 6 & 1) == 0)) {
    uVar3 = 0xffffffffffffffff;
  }
  else {
    iVar2 = sscanf(param_3,"%u %x",local_40 + 1,local_40);
    uVar3 = 0xffffffffffffffea;
    if ((iVar2 == 2) && (local_40[1] < 0x20)) {
      mutex_lock(lVar4 + 0x38);
      if (0x1f < local_40[1]) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a604);
        (*pcVar1)();
      }
      *(uint *)(*(long *)(lVar4 + 0xb8) + (ulong)local_40[1] * 4 + 0x30) = local_40[0];
      mutex_unlock(lVar4 + 0x38);
      uVar3 = param_4;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// cmb_read_interface_state_show @ 0010a608 size=200
// signature: undefined cmb_read_interface_state_show(void)
// callers: []
//------------------------------------------------------------

long cmb_read_interface_state_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)plVar4[0xe] >> 2 & 1) != 0) || (((uint)plVar4[0xe] >> 6 & 1) != 0)) {
    plVar1 = plVar4 + 7;
    mutex_lock(plVar1);
    if ((char)plVar4[0xd] != '\0') {
      *(undefined4 *)(*plVar4 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(undefined4 *)(*plVar4 + 0xa74);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar4 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      iVar3 = scnprintf(param_3,0x1000,&DAT_0010bdd2,uVar2);
      return (long)iVar3;
    }
    mutex_unlock(plVar1);
  }
  return -1;
}



//------------------------------------------------------------
// cmb_read_ctl_reg_show @ 0010a6d4 size=248
// signature: undefined cmb_read_ctl_reg_show(void)
// callers: []
//------------------------------------------------------------

long cmb_read_ctl_reg_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if ((((uint)plVar5[0xe] >> 2 & 1) == 0) && (((uint)plVar5[0xe] >> 6 & 1) == 0)) {
    lVar4 = -1;
  }
  else {
    plVar1 = plVar5 + 7;
    mutex_lock(plVar1);
    if ((char)plVar5[0xd] == '\0') {
      mutex_unlock(plVar1);
      lVar4 = -1;
    }
    else {
      *(undefined4 *)(*plVar5 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      uVar2 = *(uint *)(*plVar5 + 0xa70);
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar5 + 0xfb0) = 0;
      mutex_unlock(plVar1);
      if (((uint)plVar5[0xe] >> 2 & 1) == 0) {
        iVar3 = scnprintf(param_3,0x1000,"Lane %u SEL: %lx\n",uVar2 >> 1 & 7,uVar2 & 1);
      }
      else {
        iVar3 = scnprintf(param_3,0x1000,"SEL: %lx\n",uVar2);
      }
      lVar4 = (long)iVar3;
    }
  }
  return lVar4;
}



//------------------------------------------------------------
// cmb_read_ctl_reg_store @ 0010a7d0 size=256
// signature: undefined cmb_read_ctl_reg_store(void)
// callers: []
//------------------------------------------------------------

undefined8
cmb_read_ctl_reg_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if ((((uint)plVar3[0xe] >> 2 & 1) == 0) && (((uint)plVar3[0xe] >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xa70) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmb_markr_store @ 0010a8d4 size=256
// signature: undefined cmb_markr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cmb_markr_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    if ((((uint)plVar3[0xe] >> 2 & 1) == 0) && (((uint)plVar3[0xe] >> 6 & 1) == 0)) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(plVar3 + 7);
      if ((char)plVar3[0xd] == '\0') {
        param_4 = 0xffffffffffffffff;
      }
      else {
        *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xa28) = (undefined4)local_40;
        DataSynchronizationBarrier(3,3,0);
        *(undefined4 *)(*plVar3 + 0xfb0) = 0;
      }
      mutex_unlock(plVar3 + 7);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mcmb_trig_lane_show @ 0010a9d8 size=88
// signature: undefined mcmb_trig_lane_show(void)
// callers: []
//------------------------------------------------------------

long mcmb_trig_lane_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,**(undefined1 **)(*(long *)(lVar2 + 0xb8) + 0xb8)
                     );
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// mcmb_trig_lane_store @ 0010aa34 size=200
// signature: undefined mcmb_trig_lane_store(void)
// callers: []
//------------------------------------------------------------

void mcmb_trig_lane_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,10,&local_40);
  uVar2 = 0xffffffffffffffea;
  if ((iVar1 == 0) && (local_40 < 8)) {
    if (((uint)*(undefined8 *)(lVar3 + 0x70) >> 6 & 1) == 0) {
      uVar2 = 0xffffffffffffffff;
    }
    else {
      mutex_lock(lVar3 + 0x38);
      **(undefined1 **)(*(long *)(lVar3 + 0xb8) + 0xb8) = (char)local_40;
      mutex_unlock(lVar3 + 0x38);
      uVar2 = param_4;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// mcmb_lanes_select_show @ 0010ab00 size=88
// signature: undefined mcmb_lanes_select_show(void)
// callers: []
//------------------------------------------------------------

long mcmb_lanes_select_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010bdb2,
                      *(undefined1 *)(*(long *)(*(long *)(lVar2 + 0xb8) + 0xb8) + 1));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// mcmb_lanes_select_store @ 0010ab5c size=196
// signature: undefined mcmb_lanes_select_store(void)
// callers: []
//------------------------------------------------------------

undefined8
mcmb_lanes_select_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_40);
  if (iVar1 == 0) {
    if (((uint)*(undefined8 *)(lVar2 + 0x70) >> 6 & 1) == 0) {
      param_4 = 0xffffffffffffffff;
    }
    else {
      local_40 = local_40 & 0xff;
      mutex_lock(lVar2 + 0x38);
      *(char *)(*(long *)(*(long *)(lVar2 + 0xb8) + 0xb8) + 1) = (char)local_40;
      mutex_unlock(lVar2 + 0x38);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 0010ace0 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  amba_driver_register(&tpdm_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010ad08 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  amba_driver_unregister(&tpdm_driver);
  return;
}



//------------------------------------------------------------
// tpdm_remove @ 0010ad30 size=36
// signature: undefined tpdm_remove(void)
// callers: []
//------------------------------------------------------------

void tpdm_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x10));
  return;
}



//------------------------------------------------------------
// amba_driver_register @ 0010d000 size=1
// signature: undefined amba_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_unregister @ 0010d008 size=1
// signature: undefined amba_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 0010d010 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 0010d018 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010d020 size=1
// signature: undefined of_find_property(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_get_sec_dump_state @ 0010d028 size=1
// signature: undefined qcom_scm_get_sec_dump_state(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_get_sec_dump_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010d030 size=1
// signature: undefined devm_kmalloc(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0010d038 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010d040 size=1
// signature: undefined __mutex_init(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0010d048 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010d050 size=1
// signature: undefined devm_clk_get(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 0010d058 size=1
// signature: undefined devm_regulator_get(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 0010d060 size=1
// signature: undefined coresight_register(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 0010d068 size=1
// signature: undefined coresight_unregister(void)
// callers: [tpdm_probe, tpdm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d070 size=1
// signature: undefined _dev_err(void)
// callers: [tpdm_probe, tpdm_disable, tpdm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010d078 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [tpdm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010d080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [dsb_trig_patt_val_store, tc_sw_inc_store, mcmb_trig_lane_store, tc_retrieval_mode_store, dsb_msr_store, tc_trig_sel_store, bc_counter_sel_store, cmb_trig_patt_val_msb_store, bc_sat_mode_store, dsb_edge_ctrl_store, integration_test_store, bc_sw_inc_store, tc_sat_mode_store, cmb_msr_store, reset_store, dsb_testmode_data_valid_store, gp_regs_store, dsb_trig_patt_mask_store, mcmb_lanes_select_store, bc_enable_ganging_store, cmb_ts_all_store, bc_count_val_hi_store, tc_count_val_hi_store, cmb_patt_mask_store, tc_clear_counters_store, tc_ovsr_impl_store, bc_count_val_lo_store, cmb_read_ctl_reg_store, bc_enable_counters_store, tc_msr_store, cmb_patt_ts_store, tc_ovsr_gp_store, dsb_patt_mask_store, cmb_patt_val_store, cmb_markr_store, enable_datasets_store, cmb_mode_store, dsb_select_val_store, bc_overflow_val_store, tpdm_probe, bc_msr_store, dsb_trig_type_store, tc_trig_val_lo_store, dsb_mode_store, bc_ovsr_store, dsb_patt_type_store, tc_capture_mode_store, bc_reset_counters_store, cmb_trig_patt_mask_lsb_store, tc_trig_val_hi_store, bc_enable_irq_store, tc_enable_counters_store, dsb_patt_ts_store, tc_counter_sel_store, cmb_trig_ts_store, bc_trig_val_lo_store, dsb_patt_val_store, bc_capture_mode_store, tc_reset_counters_store, bc_clear_counters_store, bc_trig_val_hi_store, dsb_edge_ctrl_mask_store, bc_clear_irq_store, tc_count_val_lo_store, cmb_trig_patt_val_lsb_store, bc_retrieval_mode_store, tc_clear_irq_store, tc_enable_irq_store, dsb_testmode_data_store, dsb_trig_ts_store, cmb_trig_patt_mask_msb_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disable @ 0010d088 size=1
// signature: undefined coresight_disable(void)
// callers: [reset_store, tpdm_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010d090 size=1
// signature: undefined mutex_lock(void)
// callers: [dsb_trig_patt_val_store, mcmb_trig_lane_store, tc_retrieval_mode_store, dsb_msr_store, tc_trig_sel_store, dsb_edge_ctrl_store, tc_sat_mode_store, tc_trig_val_lo_show, reset_store, bc_trig_val_hi_show, gp_regs_store, dsb_trig_patt_mask_store, tc_sw_inc_show, mcmb_lanes_select_store, dsb_patt_mask_show, bc_enable_ganging_store, bc_trig_val_lo_show, bc_count_val_hi_store, dsb_trig_patt_val_show, dsb_edge_ctrl_mask_show, cmb_read_ctl_reg_store, cmb_patt_ts_store, tc_ovsr_gp_store, cmb_patt_val_show, tc_count_val_hi_show, dsb_select_val_store, gp_regs_show, tpdm_enable, cmb_read_interface_state_show, tc_capture_mode_store, cmb_trig_patt_mask_lsb_store, bc_shadow_val_hi_show, tc_ovsr_impl_show, dsb_patt_ts_store, cmb_read_ctl_reg_show, cmb_trig_ts_store, tc_counter_sel_show, dsb_patt_val_store, tc_ovsr_gp_show, bc_capture_mode_store, bc_clear_counters_store, bc_trig_val_hi_store, tc_count_val_lo_store, tc_clear_irq_store, bc_count_val_hi_show, dsb_trig_ts_store, cmb_patt_mask_show, tc_sw_inc_store, bc_counter_sel_store, cmb_trig_patt_val_msb_store, bc_sat_mode_store, bc_sw_inc_store, cmb_msr_store, dsb_testmode_data_valid_store, dsb_select_val_show, tc_shadow_val_lo_show, dsb_patt_val_show, cmb_ts_all_store, bc_overflow_val_show, tc_count_val_hi_store, tc_shadow_val_hi_show, cmb_patt_mask_store, tc_count_val_lo_show, tc_clear_counters_store, tc_ovsr_impl_store, bc_counter_sel_show, bc_count_val_lo_store, bc_ovsr_show, bc_enable_counters_store, tc_trig_val_hi_show, tc_msr_store, dsb_patt_mask_store, dsb_trig_patt_mask_show, dsb_edge_ctrl_show, cmb_patt_val_store, cmb_markr_store, enable_datasets_store, cmb_mode_store, bc_overflow_val_store, bc_msr_store, dsb_trig_type_store, tc_trig_val_lo_store, dsb_mode_store, bc_ovsr_store, dsb_patt_type_store, bc_reset_counters_store, bc_count_val_lo_show, tc_trig_val_hi_store, bc_enable_irq_store, tc_enable_counters_store, tc_counter_sel_store, tc_trig_sel_show, bc_shadow_val_lo_show, bc_trig_val_lo_store, tc_reset_counters_store, dsb_edge_ctrl_mask_store, bc_clear_irq_store, bc_sw_inc_show, cmb_trig_patt_val_lsb_store, tpdm_disable, bc_retrieval_mode_store, tc_enable_irq_store, dsb_testmode_data_store, cmb_trig_patt_mask_msb_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010d098 size=1
// signature: undefined mutex_unlock(void)
// callers: [dsb_trig_patt_val_store, mcmb_trig_lane_store, tc_retrieval_mode_store, dsb_msr_store, tc_trig_sel_store, dsb_edge_ctrl_store, tc_sat_mode_store, tc_trig_val_lo_show, reset_store, bc_trig_val_hi_show, gp_regs_store, dsb_trig_patt_mask_store, tc_sw_inc_show, mcmb_lanes_select_store, dsb_patt_mask_show, bc_enable_ganging_store, bc_trig_val_lo_show, bc_count_val_hi_store, dsb_trig_patt_val_show, dsb_edge_ctrl_mask_show, cmb_read_ctl_reg_store, cmb_patt_ts_store, tc_ovsr_gp_store, cmb_patt_val_show, tc_count_val_hi_show, dsb_select_val_store, gp_regs_show, tpdm_enable, cmb_read_interface_state_show, tc_capture_mode_store, cmb_trig_patt_mask_lsb_store, bc_shadow_val_hi_show, tc_ovsr_impl_show, dsb_patt_ts_store, cmb_read_ctl_reg_show, cmb_trig_ts_store, tc_counter_sel_show, dsb_patt_val_store, tc_ovsr_gp_show, bc_capture_mode_store, bc_clear_counters_store, bc_trig_val_hi_store, tc_count_val_lo_store, tc_clear_irq_store, bc_count_val_hi_show, dsb_trig_ts_store, cmb_patt_mask_show, tc_sw_inc_store, bc_counter_sel_store, cmb_trig_patt_val_msb_store, bc_sat_mode_store, bc_sw_inc_store, cmb_msr_store, dsb_testmode_data_valid_store, dsb_select_val_show, tc_shadow_val_lo_show, dsb_patt_val_show, cmb_ts_all_store, bc_overflow_val_show, tc_count_val_hi_store, tc_shadow_val_hi_show, cmb_patt_mask_store, tc_count_val_lo_show, tc_clear_counters_store, tc_ovsr_impl_store, bc_counter_sel_show, bc_count_val_lo_store, bc_ovsr_show, bc_enable_counters_store, tc_trig_val_hi_show, tc_msr_store, dsb_patt_mask_store, dsb_trig_patt_mask_show, dsb_edge_ctrl_show, cmb_patt_val_store, cmb_markr_store, enable_datasets_store, cmb_mode_store, bc_overflow_val_store, bc_msr_store, dsb_trig_type_store, tc_trig_val_lo_store, dsb_mode_store, bc_ovsr_store, dsb_patt_type_store, bc_reset_counters_store, bc_count_val_lo_show, tc_trig_val_hi_store, bc_enable_irq_store, tc_enable_counters_store, tc_counter_sel_store, tc_trig_sel_show, bc_shadow_val_lo_show, bc_trig_val_lo_store, tc_reset_counters_store, dsb_edge_ctrl_mask_store, bc_clear_irq_store, bc_sw_inc_show, cmb_trig_patt_val_lsb_store, tpdm_disable, bc_retrieval_mode_store, tc_enable_irq_store, dsb_testmode_data_store, cmb_trig_patt_mask_msb_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010d0a0 size=1
// signature: undefined _dev_info(void)
// callers: [tpdm_disable, tpdm_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010d0a8 size=1
// signature: undefined scnprintf(void)
// callers: [available_datasets_show, cmb_trig_patt_mask_msb_show, dsb_patt_ts_show, tc_enable_irq_show, tc_trig_val_lo_show, bc_trig_val_hi_show, dsb_select_val_show, bc_enable_counters_show, tc_shadow_val_lo_show, tc_msr_show, tc_sw_inc_show, dsb_patt_mask_show, cmb_available_modes_show, dsb_patt_val_show, bc_trig_val_lo_show, bc_overflow_val_show, tc_shadow_val_hi_show, cmb_msr_show, bc_enable_irq_show, tc_count_val_lo_show, cmb_trig_patt_mask_lsb_show, dsb_trig_patt_val_show, dsb_trig_ts_show, dsb_msr_show, bc_counter_sel_show, tc_clear_irq_show, dsb_edge_ctrl_mask_show, bc_ovsr_show, tc_trig_val_hi_show, dsb_mode_show, cmb_patt_val_show, tc_count_val_hi_show, dsb_trig_patt_mask_show, bc_enable_ganging_show, dsb_edge_ctrl_show, gp_regs_show, tc_retrieval_mode_show, dsb_trig_type_show, cmb_ts_all_show, cmb_read_interface_state_show, bc_count_val_lo_show, bc_shadow_val_hi_show, tc_ovsr_impl_show, cmb_read_ctl_reg_show, tc_trig_sel_show, bc_clear_irq_show, tc_counter_sel_show, bc_shadow_val_lo_show, tc_sat_mode_show, bc_capture_mode_show, tc_ovsr_gp_show, cmb_mode_show, bc_clear_counters_show, cmb_patt_ts_show, cmb_trig_ts_show, tc_enable_counters_show, bc_msr_show, bc_sw_inc_show, tc_clear_counters_show, enable_datasets_show, bc_retrieval_mode_show, bc_sat_mode_show, cmb_trig_patt_val_msb_show, tc_capture_mode_show, mcmb_lanes_select_show, bc_count_val_hi_show, dsb_patt_type_show, cmb_trig_patt_val_lsb_show, mcmb_trig_lane_show, cmb_patt_mask_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0010d0b0 size=1
// signature: undefined kstrtoull(void)
// callers: [dsb_trig_type_store, tc_sw_inc_store, mcmb_trig_lane_store, dsb_mode_store, bc_counter_sel_store, cmb_trig_patt_val_msb_store, bc_sat_mode_store, bc_ovsr_store, dsb_patt_type_store, integration_test_store, bc_sw_inc_store, tc_sat_mode_store, bc_reset_counters_store, cmb_trig_patt_mask_lsb_store, reset_store, dsb_testmode_data_valid_store, bc_enable_irq_store, tc_enable_counters_store, dsb_patt_ts_store, tc_counter_sel_store, cmb_trig_ts_store, mcmb_lanes_select_store, tc_reset_counters_store, bc_enable_ganging_store, cmb_ts_all_store, bc_clear_counters_store, bc_count_val_hi_store, tc_count_val_hi_store, bc_clear_irq_store, tc_clear_counters_store, tc_ovsr_impl_store, bc_count_val_lo_store, cmb_read_ctl_reg_store, bc_enable_counters_store, cmb_patt_ts_store, tc_ovsr_gp_store, tc_count_val_lo_store, cmb_trig_patt_val_lsb_store, tc_clear_irq_store, cmb_markr_store, enable_datasets_store, tc_enable_irq_store, dsb_trig_ts_store, cmb_trig_patt_mask_msb_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010d0b8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [reset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0010d0c0 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [bc_msr_store, dsb_trig_patt_val_store, tc_retrieval_mode_store, dsb_msr_store, tc_trig_sel_store, tc_trig_val_lo_store, dsb_edge_ctrl_store, tc_capture_mode_store, cmb_msr_store, tc_trig_val_hi_store, gp_regs_store, dsb_trig_patt_mask_store, bc_trig_val_lo_store, dsb_patt_val_store, bc_capture_mode_store, cmb_patt_mask_store, bc_trig_val_hi_store, dsb_edge_ctrl_mask_store, tc_msr_store, dsb_patt_mask_store, bc_retrieval_mode_store, cmb_patt_val_store, cmb_mode_store, dsb_select_val_store, bc_overflow_val_store, dsb_testmode_data_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



