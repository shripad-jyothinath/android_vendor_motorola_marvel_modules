// Decompiled by Ghidra 12.2
// Program: coresight-hwevent.ko
// Image base: 00100000

//------------------------------------------------------------
// hwevent_probe @ 001001dc size=616
// signature: undefined hwevent_probe(void)
// callers: []
//------------------------------------------------------------

void hwevent_probe(long param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  ulong uVar11;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  long lStack_98;
  undefined **local_90;
  long local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  long local_58;
  
  lVar8 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_58 = *(long *)(lVar8 + 0x638);
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = (undefined **)0x0;
  local_88 = 0;
  local_a0 = 0;
  lStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_88 = coresight_alloc_device_name(hwevent_devs,lVar1);
  if (local_88 != 0) {
    uVar6 = coresight_get_platform_data(lVar1);
    if (0xfffffffffffff000 < uVar6) goto LAB_00100404;
    *(ulong *)(param_1 + 0xa0) = uVar6;
    plVar7 = (long *)devm_kmalloc(lVar1,0x88,0xdc0);
    if (plVar7 != (long *)0x0) {
      *(long **)(param_1 + 0xa8) = plVar7;
      *plVar7 = lVar1;
      __mutex_init(plVar7 + 3,"&drvdata->mutex",&hwevent_probe___key);
      iVar4 = of_get_coresight_csr_name(*(undefined8 *)(param_1 + 0x2f8),plVar7 + 0x10);
      if (iVar4 == 0) {
        uVar6 = coresight_csr_get(plVar7[0x10]);
        plVar7[0xf] = uVar6;
        if (0xfffffffffffff000 < uVar6) {
          uVar6 = 0xfffffdfb;
          goto LAB_00100404;
        }
      }
      else {
        _dev_err(lVar1,"No csr data\n");
      }
      uVar6 = devm_clk_get(lVar1,"apb_pclk");
      plVar7[2] = uVar6;
      if (0xfffffffffffff000 < uVar6) goto LAB_00100404;
      uVar10 = *(undefined8 *)(*plVar7 + 0x2e8);
      local_60 = 0;
      uVar5 = of_property_read_string_helper(uVar10,"reg-names",0,0,0);
      uVar3 = uVar5;
      if ((int)uVar5 < 1) {
        uVar3 = 0;
      }
      *(uint *)(plVar7 + 0xd) = uVar3;
      if (0 < (int)uVar5) {
        lVar8 = devm_kmalloc(*plVar7,(ulong)uVar3 << 4,0xdc0);
        plVar7[0xe] = lVar8;
        if (lVar8 == 0) goto LAB_00100400;
        if (0 < (int)plVar7[0xd]) {
          lVar8 = 0;
          uVar11 = 0;
          do {
            uVar6 = of_property_read_string_helper
                              (uVar10,"reg-names",&local_60,1,uVar11 & 0xffffffff);
            if ((int)uVar6 < 0) goto LAB_00100404;
            puVar9 = (undefined8 *)platform_get_resource_byname(param_1,0x200,local_60);
            if (puVar9 == (undefined8 *)0x0) {
              uVar6 = 0xffffffed;
              goto LAB_00100404;
            }
            uVar11 = uVar11 + 1;
            *(undefined8 *)(plVar7[0xe] + lVar8) = *puVar9;
            lVar2 = plVar7[0xe] + lVar8;
            lVar8 = lVar8 + 0x10;
            *(undefined8 *)(lVar2 + 8) = puVar9[1];
          } while ((long)uVar11 < (long)(int)plVar7[0xd]);
        }
      }
      uVar6 = hwevent_init_clk(plVar7);
      if ((int)uVar6 == 0) {
        local_a0 = *(undefined8 *)(param_1 + 0xa0);
        local_b8 = CONCAT44(local_b8._4_4_,4);
        local_90 = &hwevent_attr_grps;
        lStack_98 = lVar1;
        uVar6 = coresight_register(&local_b8);
        plVar7[1] = uVar6;
        if (uVar6 < 0xfffffffffffff001) {
          uVar6 = 0;
        }
      }
      goto LAB_00100404;
    }
  }
LAB_00100400:
  uVar6 = 0xfffffff4;
LAB_00100404:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// hwevent_remove @ 00100448 size=40
// signature: undefined hwevent_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 hwevent_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 8));
  return 0;
}



//------------------------------------------------------------
// hwevent_init_clk @ 00100470 size=472
// signature: undefined hwevent_init_clk(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

void hwevent_init_clk(long *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  uVar6 = *(undefined8 *)(*param_1 + 0x2e8);
  uVar1 = of_property_read_string_helper(uVar6,"qcom,hwevent-clks",0,0,0);
  *(undefined4 *)(param_1 + 9) = uVar1;
  uVar2 = of_property_read_string_helper(uVar6,"qcom,hwevent-regs",0,0,0);
  *(uint *)(param_1 + 0xb) = uVar2;
  if ((int)*(uint *)(param_1 + 9) < 1) {
LAB_00100578:
    if (0 < (int)uVar2) {
      lVar3 = devm_kmalloc(*param_1,(ulong)uVar2 << 3,0xdc0);
      param_1[0xc] = lVar3;
      if (lVar3 == 0) goto LAB_00100610;
      if (0 < (int)param_1[0xb]) {
        uVar7 = 0;
        do {
          uVar4 = of_property_read_string_helper
                            (uVar6,"qcom,hwevent-regs",&local_48,1,uVar7 & 0xffffffff);
          if ((int)uVar4 < 0) goto LAB_00100614;
          uVar5 = devm_regulator_get(*param_1,local_48);
          *(undefined8 *)(param_1[0xc] + uVar7 * 8) = uVar5;
          uVar4 = *(ulong *)(param_1[0xc] + uVar7 * 8);
          if (0xfffffffffffff000 < uVar4) goto LAB_00100614;
          uVar7 = uVar7 + 1;
        } while ((long)uVar7 < (long)(int)param_1[0xb]);
      }
    }
    uVar4 = 0;
  }
  else {
    lVar3 = devm_kmalloc(*param_1,(ulong)*(uint *)(param_1 + 9) << 3,0xdc0);
    param_1[10] = lVar3;
    if (lVar3 != 0) {
      if (0 < (int)param_1[9]) {
        uVar7 = 0;
        do {
          uVar4 = of_property_read_string_helper
                            (uVar6,"qcom,hwevent-clks",&local_40,1,uVar7 & 0xffffffff);
          if ((int)uVar4 < 0) goto LAB_00100614;
          uVar5 = devm_clk_get(*param_1,local_40);
          *(undefined8 *)(param_1[10] + uVar7 * 8) = uVar5;
          uVar4 = *(ulong *)(param_1[10] + uVar7 * 8);
          if (0xfffffffffffff000 < uVar4) goto LAB_00100614;
          uVar7 = uVar7 + 1;
        } while ((long)uVar7 < (long)(int)param_1[9]);
      }
      uVar2 = *(uint *)(param_1 + 0xb);
      goto LAB_00100578;
    }
LAB_00100610:
    uVar4 = 0xfffffff4;
  }
LAB_00100614:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// setreg_store @ 0010064c size=760
// signature: undefined setreg_store(void)
// callers: []
//------------------------------------------------------------

long setreg_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ulong local_68;
  ulonglong local_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  local_68 = 0;
  local_60 = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar3 = sscanf(param_3,"%llx %lx",&local_60,&local_68);
  if (iVar3 != 2) {
    param_4 = -0x16;
    goto LAB_001008d4;
  }
  lVar1 = lVar7 + 0x18;
  mutex_lock(lVar1);
  uVar9 = *(undefined8 *)(lVar7 + 0x10);
  iVar3 = clk_prepare(uVar9);
  if (iVar3 == 0) {
    iVar3 = clk_enable(uVar9);
    if (iVar3 == 0) {
      if (*(int *)(lVar7 + 0x58) < 1) {
        lVar10 = 0;
      }
      else {
        lVar10 = 0;
        do {
          iVar3 = regulator_enable(*(undefined8 *)(*(long *)(lVar7 + 0x60) + lVar10 * 8));
          if (iVar3 != 0) goto LAB_00100890;
          lVar10 = lVar10 + 1;
        } while (lVar10 < *(int *)(lVar7 + 0x58));
      }
      if (0 < *(int *)(lVar7 + 0x48)) {
        lVar11 = 0;
        do {
          uVar9 = *(undefined8 *)(*(long *)(lVar7 + 0x50) + lVar11 * 8);
          iVar3 = clk_prepare(uVar9);
          if (iVar3 != 0) {
LAB_0010085c:
            if (lVar11 != 0) {
              do {
                uVar9 = *(undefined8 *)(*(long *)(lVar7 + 0x50) + (lVar11 + -1) * 8);
                clk_disable(uVar9);
                clk_unprepare(uVar9);
                bVar2 = 1 < lVar11;
                lVar11 = lVar11 + -1;
              } while (bVar2);
            }
LAB_00100890:
            uVar5 = (int)lVar10 - 1;
            if (-1 < (int)uVar5) {
              lVar10 = (ulong)uVar5 << 3;
              do {
                regulator_disable(*(undefined8 *)(*(long *)(lVar7 + 0x60) + lVar10));
                bVar2 = lVar10 != 0;
                lVar10 = lVar10 + -8;
              } while (bVar2);
            }
            uVar9 = *(undefined8 *)(lVar7 + 0x10);
            clk_disable(uVar9);
            goto LAB_001008c0;
          }
          iVar3 = clk_enable(uVar9);
          if (iVar3 != 0) {
            clk_unprepare(uVar9);
            goto LAB_0010085c;
          }
          lVar11 = lVar11 + 1;
        } while (lVar11 < *(int *)(lVar7 + 0x48));
      }
      uVar5 = *(uint *)(lVar7 + 0x68);
      if ((int)uVar5 < 1) {
        uVar8 = 0;
LAB_00100818:
        if (uVar8 == uVar5) goto LAB_00100820;
      }
      else {
        uVar8 = 0;
        lVar10 = 0;
        do {
          uVar4 = *(ulong *)(*(long *)(lVar7 + 0x70) + lVar10);
          if ((uVar4 <= local_60) &&
             (uVar6 = *(ulong *)(*(long *)(lVar7 + 0x70) + lVar10 + 8), local_60 < uVar6)) {
            uVar9 = 0x68000000000713;
            if (arm64_use_ng_mappings != '\0') {
              uVar9 = 0x68000000000f13;
            }
            lVar11 = ioremap_prot(uVar4,uVar6 - uVar4,uVar9);
            if (lVar11 != 0) {
              writel_relaxed(local_68 & 0xffffffff,
                             (lVar11 + local_60) - *(long *)(*(long *)(lVar7 + 0x70) + lVar10));
              DataSynchronizationBarrier(3,3,0);
              iounmap(lVar11);
              uVar5 = *(uint *)(lVar7 + 0x68);
              goto LAB_00100818;
            }
            _dev_err(param_1,"unable to map address 0x%llx\n",local_60);
            param_4 = -0xc;
            goto LAB_00100834;
          }
          lVar10 = lVar10 + 0x10;
          uVar8 = uVar8 + 1;
        } while ((ulong)uVar5 * 0x10 != lVar10);
LAB_00100820:
        iVar3 = coresight_csr_hwctrl_set
                          (*(undefined8 *)(lVar7 + 0x78),local_60,local_68 & 0xffffffff);
        if (iVar3 != 0) {
          _dev_err(param_1,"invalid mux control register address\n");
          param_4 = -0x16;
        }
      }
LAB_00100834:
      hwevent_disable(lVar7);
      mutex_unlock(lVar1);
      goto LAB_001008d4;
    }
LAB_001008c0:
    clk_unprepare(uVar9);
  }
  mutex_unlock(lVar1);
  param_4 = (long)iVar3;
LAB_001008d4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// writel_relaxed @ 00100944 size=132
// signature: undefined writel_relaxed(void)
// callers: [setreg_store]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10095c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100998,uVar1);
  return;
}



//------------------------------------------------------------
// hwevent_disable @ 001009c8 size=164
// signature: undefined hwevent_disable(void)
// callers: [setreg_store]
//------------------------------------------------------------

void hwevent_disable(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  clk_disable(uVar1);
  clk_unprepare(uVar1);
  if (0 < *(int *)(param_1 + 0x48)) {
    lVar2 = 0;
    do {
      uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x50) + lVar2 * 8);
      clk_disable(uVar1);
      clk_unprepare(uVar1);
      lVar2 = lVar2 + 1;
    } while (lVar2 < *(int *)(param_1 + 0x48));
  }
  if (0 < *(int *)(param_1 + 0x58)) {
    lVar2 = 0;
    do {
      regulator_disable(*(undefined8 *)(*(long *)(param_1 + 0x60) + lVar2 * 8));
      lVar2 = lVar2 + 1;
    } while (lVar2 < *(int *)(param_1 + 0x58));
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100a70 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&hwevent_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100aa0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&hwevent_driver);
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
// coresight_alloc_device_name @ 00102010 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00102018 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [hwevent_init_clk, hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00102028 size=1
// signature: undefined __mutex_init(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_coresight_csr_name @ 00102030 size=1
// signature: undefined of_get_coresight_csr_name(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_coresight_csr_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_csr_get @ 00102038 size=1
// signature: undefined coresight_csr_get(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_csr_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [setreg_store, hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00102048 size=1
// signature: undefined devm_clk_get(void)
// callers: [hwevent_init_clk, hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00102050 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [hwevent_init_clk, hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00102058 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00102060 size=1
// signature: undefined coresight_register(void)
// callers: [hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hwevent_init_clk, setreg_store, hwevent_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00102070 size=1
// signature: undefined coresight_unregister(void)
// callers: [hwevent_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00102078 size=1
// signature: undefined devm_regulator_get(void)
// callers: [hwevent_init_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00102080 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102088 size=1
// signature: undefined mutex_lock(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00102090 size=1
// signature: undefined clk_prepare(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00102098 size=1
// signature: undefined clk_enable(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001020a0 size=1
// signature: undefined regulator_enable(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 001020b0 size=1
// signature: undefined ioremap_prot(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 001020b8 size=1
// signature: undefined iounmap(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_csr_hwctrl_set @ 001020c0 size=1
// signature: undefined coresight_csr_hwctrl_set(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_csr_hwctrl_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001020c8 size=1
// signature: undefined mutex_unlock(void)
// callers: [setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001020d0 size=1
// signature: undefined clk_unprepare(void)
// callers: [hwevent_disable, setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001020d8 size=1
// signature: undefined clk_disable(void)
// callers: [hwevent_disable, setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001020e0 size=1
// signature: undefined regulator_disable(void)
// callers: [hwevent_disable, setreg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001020e8 size=1
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
// log_post_write_mmio @ 001020f0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



