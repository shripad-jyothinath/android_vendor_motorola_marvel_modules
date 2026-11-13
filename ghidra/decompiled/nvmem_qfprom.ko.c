// Decompiled by Ghidra 12.2
// Program: nvmem_qfprom.ko
// Image base: 00100000

//------------------------------------------------------------
// qfprom_probe @ 00100244 size=648
// signature: undefined qfprom_probe(void)
// callers: []
//------------------------------------------------------------

ulong qfprom_probe(long param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ulong *puVar5;
  int *piVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  undefined1 *puVar12;
  ulong local_d0 [6];
  undefined8 local_a0;
  undefined4 local_98;
  code *local_70;
  int local_60;
  ulong *local_50;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  memcpy(local_d0,&DAT_00101638,0x98);
  uVar11 = param_1 + 0x10;
  puVar5 = (ulong *)devm_kmalloc(uVar11,0x40,0xdc0);
  if (puVar5 == (ulong *)0x0) {
    uVar7 = 0xfffffff4;
    goto LAB_001003f0;
  }
  piVar6 = (int *)platform_get_resource(param_1,0x200,0);
  uVar7 = devm_ioremap_resource(uVar11,piVar6);
  puVar5[2] = uVar7;
  if (0xfffffffffffff000 < uVar7) goto LAB_001003ec;
  iVar1 = piVar6[2];
  iVar2 = *piVar6;
  puVar5[4] = uVar11;
  local_60 = (iVar1 - iVar2) + 1;
  local_d0[0] = uVar11;
  local_50 = puVar5;
  puVar8 = (undefined8 *)device_get_match_data(uVar11);
  if (puVar8 != (undefined8 *)0x0) {
    local_a0 = *puVar8;
    local_98 = *(undefined4 *)(puVar8 + 1);
  }
  lVar9 = platform_get_resource(param_1,0x200,1);
  if (lVar9 == 0) {
LAB_00100464:
    pm_runtime_enable(uVar11);
    uVar4 = devm_add_action(uVar11,qfprom_runtime_disable,uVar11);
    if (uVar4 == 0) {
      uVar11 = devm_nvmem_register(uVar11,local_d0);
      uVar4 = (uint)uVar11;
      if (uVar11 < 0xfffffffffffff001) {
        uVar4 = 0;
      }
      uVar7 = (ulong)uVar4;
    }
    else {
      uVar7 = (ulong)uVar4;
      __pm_runtime_disable(uVar11,1);
    }
  }
  else {
    uVar7 = devm_ioremap_resource(uVar11,lVar9);
    *puVar5 = uVar7;
    if (uVar7 < 0xfffffffffffff001) {
      uVar10 = platform_get_resource(param_1,0x200,2);
      uVar7 = devm_ioremap_resource(uVar11,uVar10);
      puVar5[1] = uVar7;
      if (uVar7 < 0xfffffffffffff001) {
        uVar10 = platform_get_resource(param_1,0x200,3);
        uVar7 = devm_ioremap_resource(uVar11,uVar10);
        puVar5[3] = uVar7;
        if (uVar7 < 0xfffffffffffff001) {
          uVar3 = readl();
          uVar4 = uVar3 >> 0x10 & 0xfff;
          if (((uVar3 & 0xf0000000) == 0x70000000) && (uVar4 == 8)) {
            puVar12 = qfprom_7_8_data;
LAB_001003cc:
            puVar5[7] = (ulong)puVar12;
          }
          else if (((uVar3 & 0xf0000000) == 0x70000000) && (uVar4 == 0xf)) {
            puVar12 = qfprom_7_15_data;
            goto LAB_001003cc;
          }
          uVar7 = devm_regulator_get(uVar11,&DAT_00101c36);
          puVar5[6] = uVar7;
          if (uVar7 < 0xfffffffffffff001) {
            uVar7 = devm_clk_get(uVar11,&DAT_00101be1);
            puVar5[5] = uVar7;
            if (0xfffffffffffff000 < uVar7) {
              if ((int)uVar7 == -0x205) {
                uVar7 = 0xfffffdfb;
              }
              else {
                _dev_err(uVar11,"Error getting clock: %d\n",uVar7 & 0xffffffff);
              }
              goto LAB_001003f0;
            }
            if (puVar5[7] != 0) {
              local_70 = qfprom_reg_write;
            }
            goto LAB_00100464;
          }
        }
      }
    }
LAB_001003ec:
    uVar7 = uVar7 & 0xffffffff;
  }
LAB_001003f0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// qfprom_reg_read @ 001004d0 size=248
// signature: undefined qfprom_reg_read(void)
// callers: []
//------------------------------------------------------------

undefined8 qfprom_reg_read(long *param_1,uint param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = param_1[2];
  if (read_raw_data != '\0') {
    if (*param_1 != 0) {
      lVar6 = *param_1;
    }
  }
  uVar1 = param_2 & 0xfffffffc;
  uVar2 = param_2 + (int)param_4 + 3 & 0xfffffffc;
  lVar4 = __kmalloc((long)(int)(uVar2 - uVar1),0xdc0);
  if (lVar4 == 0) {
    _printk(&DAT_00101be6,"qfprom_reg_read");
    uVar5 = 0xfffffff4;
  }
  else {
    if ((int)uVar1 < (int)uVar2) {
      lVar7 = 0;
      do {
        uVar3 = readl_relaxed(lVar6 + (int)uVar1 + lVar7);
        *(undefined4 *)(lVar4 + (int)lVar7) = uVar3;
        lVar7 = lVar7 + 4;
      } while ((int)uVar1 + lVar7 < (long)(int)uVar2);
    }
    memcpy(param_3,(void *)(lVar4 + (ulong)(param_2 & 3)),param_4);
    kfree(lVar4);
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// readl @ 001005c8 size=140
// signature: undefined readl(void)
// callers: [qfprom_probe, qfprom_reg_write]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100620,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qfprom_reg_write @ 00100658 size=1072
// signature: undefined qfprom_reg_write(void)
// callers: []
//------------------------------------------------------------

int qfprom_reg_write(long *param_1,ulong param_2,long param_3,ulong param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  long lVar10;
  char *pcVar11;
  long lVar12;
  ulong uVar13;
  
  if ((param_4 & 3) != 0) {
    _dev_err(param_1[4],"%zu is not an integral number of words\n",param_4);
    return -0x16;
  }
  if ((param_2 & 3) != 0) {
    _dev_err(param_1[4],"Invalid offset: %#x.  Must be word aligned\n",param_2 & 0xffffffff);
    return -0x16;
  }
  lVar12 = param_1[5];
  uVar6 = *(undefined4 *)(param_1[7] + 0xc);
  iVar5 = clk_prepare(lVar12);
  if (iVar5 == 0) {
    iVar5 = clk_enable(lVar12);
    if (iVar5 == 0) {
      uVar9 = clk_get_rate(param_1[5]);
      iVar5 = clk_set_rate(param_1[5],*(undefined4 *)(param_1[7] + 8));
      if (iVar5 == 0) {
        iVar5 = regulator_set_voltage(param_1[6],uVar6,0x7fffffff);
        if (iVar5 == 0) {
          iVar5 = regulator_enable(param_1[6]);
          lVar12 = param_1[4];
          if (iVar5 == 0) {
            iVar5 = __pm_runtime_resume(lVar12,4);
            if (-1 < iVar5) {
              dev_pm_genpd_set_performance_state(param_1[4],0x7fffffff);
              uVar6 = readl(param_1[1] + 0x3c);
              uVar7 = readl(param_1[1] + 0x44);
              writel(*(undefined4 *)(param_1[7] + 4),param_1[1] + 0x3c);
              writel(*(undefined4 *)param_1[7],param_1[1] + 0x44);
              lVar12 = ktime_get();
              iVar5 = readl_relaxed(param_1[1] + 0x48);
              if (iVar5 != 0) {
                do {
                  lVar10 = ktime_get();
                  if (lVar12 + 10000000 < lVar10) {
                    iVar5 = readl_relaxed(param_1[1] + 0x48);
                    if (iVar5 != 0) {
                      pcVar11 = "Timeout waiting for initial ready; aborting.\n";
                      goto LAB_00100a8c;
                    }
                    break;
                  }
                  usleep_range_state(0x1a,100,2);
                  Yield();
                  iVar5 = readl_relaxed(param_1[1] + 0x48);
                } while (iVar5 != 0);
              }
              if (0 < (int)(param_4 >> 2)) {
                uVar13 = 0;
                do {
                  writel(*(undefined4 *)(param_3 + uVar13),
                         *param_1 + (param_2 & 0xffffffff) + (long)(int)uVar13);
                  uVar13 = uVar13 + 4;
                } while ((param_4 & 0x3fffffffc) != uVar13);
              }
              lVar12 = ktime_get();
              iVar5 = readl_relaxed(param_1[1] + 0x48);
              if (iVar5 != 0) {
LAB_00100820:
                lVar10 = ktime_get();
                if (lVar10 <= lVar12 + 10000000) goto code_r0x0010082c;
                iVar5 = readl_relaxed(param_1[1] + 0x48);
                if (iVar5 != 0) {
                  pcVar11 = "Timeout waiting for finish.\n";
LAB_00100a8c:
                  _dev_err(param_1[4],pcVar11);
                  iVar5 = -0x6e;
                  goto LAB_00100868;
                }
              }
LAB_00100864:
              iVar5 = 0;
LAB_00100868:
              writel(uVar6,param_1[1] + 0x3c);
              writel(uVar7,param_1[1] + 0x44);
              dev_pm_genpd_set_performance_state(param_1[4],0);
              __pm_runtime_idle(param_1[4],5);
              iVar8 = regulator_set_voltage(param_1[6],0,0x7fffffff);
              if (iVar8 != 0) {
                _dev_warn(param_1[4],"Failed to set 0 voltage (ignoring)\n");
              }
              iVar8 = regulator_disable(param_1[6]);
              if (iVar8 != 0) {
                _dev_warn(param_1[4],"Failed to disable regulator (ignoring)\n");
              }
              iVar8 = clk_set_rate(param_1[5],uVar9);
              if (iVar8 != 0) {
                _dev_warn(param_1[4],"Failed to set clock rate for disable (ignoring)\n");
              }
              goto LAB_001008d0;
            }
            piVar1 = (int *)(lVar12 + 0x1f8);
            iVar8 = *(int *)(lVar12 + 0x1f8);
            do {
              if (iVar8 == 0) break;
              Hint_Prefetch(piVar1,2,0,1);
              do {
                iVar2 = *piVar1;
                if (iVar2 != iVar8) goto LAB_001009e0;
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                if (bVar4) {
                  *piVar1 = iVar8 + -1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              DataMemoryBarrier(2,3);
LAB_001009e0:
              bVar4 = iVar8 != iVar2;
              iVar8 = iVar2;
            } while (bVar4);
            _dev_err(param_1[4],"Failed to enable power-domain\n");
            regulator_disable(param_1[6]);
          }
          else {
            _dev_err(lVar12,"Failed to enable regulator\n");
          }
        }
        else {
          _dev_err(param_1[4],"Failed to set %duV\n",uVar6);
        }
        clk_set_rate(param_1[5],uVar9);
      }
      else {
        _dev_err(param_1[4],"Failed to set clock rate for enable\n");
      }
LAB_001008d0:
      lVar12 = param_1[5];
      clk_disable(lVar12);
      clk_unprepare(lVar12);
      return iVar5;
    }
    clk_unprepare(lVar12);
  }
  _dev_err(param_1[4],"Failed to enable clock\n");
  return iVar5;
code_r0x0010082c:
  usleep_range_state(0x1a,100,2);
  Yield();
  iVar5 = readl_relaxed(param_1[1] + 0x48);
  if (iVar5 == 0) goto LAB_00100864;
  goto LAB_00100820;
}



//------------------------------------------------------------
// qfprom_runtime_disable @ 00100aa0 size=32
// signature: undefined qfprom_runtime_disable(void)
// callers: []
//------------------------------------------------------------

void qfprom_runtime_disable(undefined8 param_1)

{
  __pm_runtime_disable(param_1,1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100ac0 size=124
// signature: undefined readl_relaxed(void)
// callers: [qfprom_reg_read, qfprom_reg_write]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100b08,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00100b3c size=136
// signature: undefined writel(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100b54,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100b94,uVar1);
  return;
}



//------------------------------------------------------------
// init_module @ 00100bd0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qfprom_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100c00 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qfprom_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// memcpy @ 00103010 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qfprom_probe, qfprom_reg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00103020 size=1
// signature: undefined platform_get_resource(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00103028 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_match_data @ 00103030 size=1
// signature: undefined device_get_match_data(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00103038 size=1
// signature: undefined devm_regulator_get(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00103040 size=1
// signature: undefined devm_clk_get(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00103048 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_add_action @ 00103050 size=1
// signature: undefined devm_add_action(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_add_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00103058 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [qfprom_runtime_disable, qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_register @ 00103060 size=1
// signature: undefined devm_nvmem_register(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103068 size=1
// signature: undefined _dev_err(void)
// callers: [qfprom_probe, qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qfprom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103078 size=1
// signature: undefined __kmalloc(void)
// callers: [qfprom_reg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103080 size=1
// signature: undefined kfree(void)
// callers: [qfprom_reg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103088 size=1
// signature: undefined _printk(void)
// callers: [qfprom_reg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00103090 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00103098 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001030a0 size=1
// signature: undefined clk_prepare(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001030a8 size=1
// signature: undefined clk_enable(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 001030b0 size=1
// signature: undefined clk_get_rate(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 001030b8 size=1
// signature: undefined clk_set_rate(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001030c0 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001030c8 size=1
// signature: undefined regulator_enable(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001030d0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_set_performance_state @ 001030d8 size=1
// signature: undefined dev_pm_genpd_set_performance_state(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_set_performance_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001030e0 size=1
// signature: undefined ktime_get(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001030e8 size=1
// signature: undefined usleep_range_state(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001030f0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001030f8 size=1
// signature: undefined regulator_disable(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00103100 size=1
// signature: undefined clk_disable(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00103108 size=1
// signature: undefined clk_unprepare(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00103118 size=1
// signature: undefined _dev_warn(void)
// callers: [qfprom_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00103120 size=1
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
// log_post_write_mmio @ 00103128 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



