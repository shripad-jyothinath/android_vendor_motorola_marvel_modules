// Decompiled by Ghidra 12.2
// Program: qrng_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_rng_probe @ 0010025c size=1076
// signature: undefined msm_rng_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong msm_rng_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  
  plVar5 = (long *)platform_get_resource(param_1,0x200,0);
  if (plVar5 == (long *)0x0) {
    _dev_err(param_1 + 0x10,"invalid address\n");
    uVar8 = 0xfffffff2;
    goto LAB_00100668;
  }
  plVar6 = (long *)kmalloc_trace(_clk_prepare,0xdc0,0x50);
  if (plVar6 == (long *)0x0) {
    uVar8 = 0xfffffff4;
    goto LAB_00100668;
  }
  uVar2 = 0x68000000000713;
  if (arm64_use_ng_mappings != '\0') {
    uVar2 = 0x68000000000f13;
  }
  lVar7 = ioremap_prot(*plVar5,(plVar5[1] - *plVar5) + 1,uVar2);
  if (lVar7 == 0) {
    _dev_err(param_1 + 0x10,"ioremap failed\n");
    uVar8 = 0xfffffff4;
  }
  else {
    lVar9 = *(long *)(param_1 + 0x2f8);
    lVar1 = param_1 + 0x10;
    plVar6[1] = lVar7;
    if (lVar9 == 0) {
      if ((ulong)plVar6[2] < 0xfffffffffffff001) goto LAB_00100318;
LAB_0010051c:
      _dev_err(lVar1,"failed to register clock source\n");
      uVar8 = 0xffffffed;
    }
    else {
      lVar7 = of_find_property(lVar9,"qcom,no-clock-support",0);
      if (lVar7 == 0) {
        uVar8 = clk_get(lVar1,"km_clk_src");
        plVar6[2] = uVar8;
        if (0xfffffffffffff000 < uVar8) goto LAB_0010051c;
      }
      else {
        plVar6[2] = 0;
      }
LAB_00100318:
      lVar7 = *(long *)(param_1 + 0x2f8);
      *plVar6 = param_1;
      *(long **)(param_1 + 0xa8) = plVar6;
      if (lVar7 == 0) {
LAB_00100368:
        if ((plVar6[9] == 0) || (iVar3 = icc_set_bw(plVar6[9],0,30000), iVar3 == 0)) {
          lVar7 = plVar6[2];
        }
        else {
          _printk(&DAT_001011ce);
          lVar7 = plVar6[2];
        }
        if (lVar7 == 0) {
LAB_001003a0:
          uVar4 = readl_relaxed(plVar6[1] + 0x104);
          if ((uVar4 >> 1 & 1) == 0) {
            uVar4 = readl_relaxed(plVar6[1] + 0x100);
            writel_relaxed(uVar4 & 0xffff0000 | 0xdddd,plVar6[1] + 0x100);
            DataSynchronizationBarrier(3,3,0);
            uVar4 = readl_relaxed(plVar6[1] + 0x104);
            writel_relaxed(uVar4 | 2,plVar6[1] + 0x104);
            DataSynchronizationBarrier(3,3,0);
          }
          lVar7 = plVar6[2];
          if (lVar7 != 0) {
            clk_disable(lVar7);
            clk_unprepare(lVar7);
          }
          if ((plVar6[9] != 0) && (iVar3 = icc_set_bw(plVar6[9],0,0), iVar3 != 0)) {
            _printk(&DAT_001011ce);
          }
LAB_00100424:
          __mutex_init(plVar6 + 3,"&msm_rng_dev->rng_lock",&msm_rng_probe___key);
          __mutex_init(cached_rng_lock,"&cached_rng_lock",&msm_rng_probe___key_12);
          _DAT_001010b0 = plVar6;
          uVar4 = hwrng_register();
          if (uVar4 == 0) {
            uVar4 = __register_chrdev(0x100,0,0x100,"msm_rng",msm_rng_fops);
            if (uVar4 == 0) {
              msm_rng_class = __class_create(&__this_module,"msm-rng",&msm_rng_probe___key_16);
              if (msm_rng_class < 0xfffffffffffff001) {
                uVar8 = device_create(msm_rng_class,0,0x10000000,0,"msm-rng");
                if (uVar8 < 0xfffffffffffff001) {
                  cdev_init(msm_rng_cdev,msm_rng_fops);
                  uVar8 = 0;
                  msm_rng_dev_cached = plVar6;
                  goto LAB_00100668;
                }
                _printk(&DAT_00101276);
                class_destroy(msm_rng_class);
              }
              else {
                _printk(&DAT_001012e3);
                uVar8 = msm_rng_class;
              }
              __unregister_chrdev(0x100,0,0x100,"msm_rng");
            }
            else {
              uVar8 = (ulong)uVar4;
              _dev_err(lVar1,"failed to register chrdev\n");
            }
            hwrng_unregister(&msm_rng);
          }
          else {
            uVar8 = (ulong)uVar4;
            _dev_err(lVar1,"failed to register hwrng\n");
          }
          if (plVar6[9] != 0) {
            icc_put();
          }
        }
        else {
          iVar3 = clk_prepare(lVar7);
          if (iVar3 == 0) {
            iVar3 = clk_enable(lVar7);
            if (iVar3 == 0) goto LAB_001003a0;
            clk_unprepare(lVar7);
          }
          _dev_err(*plVar6 + 0x10,"failed to enable clock in probe\n");
          uVar8 = 0xffffffff;
        }
      }
      else {
        uVar8 = of_icc_get(lVar1,"data_path");
        plVar6[9] = uVar8;
        msm_rng_device_info_0 = uVar8;
        if (uVar8 < 0xfffffffffffff001) {
          if ((*(long *)(param_1 + 0x2f8) == 0) ||
             (lVar7 = of_find_property(*(long *)(param_1 + 0x2f8),"qcom,no-qrng-config",0),
             lVar7 == 0)) goto LAB_00100368;
          goto LAB_00100424;
        }
        _dev_err(lVar1,"get icc path err %d\n",uVar8 & 0xffffffff);
        uVar8 = uVar8 & 0xffffffff;
      }
      if (plVar6[2] != 0) {
        clk_put();
      }
    }
    iounmap(plVar6[1]);
  }
  kfree_sensitive(plVar6);
LAB_00100668:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// msm_rng_remove @ 00100694 size=176
// signature: undefined msm_rng_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_rng_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  cdev_del(msm_rng_cdev);
  device_destroy(msm_rng_class,0x10000000);
  class_destroy(msm_rng_class);
  __unregister_chrdev(0x100,0,0x100,"msm_rng");
  hwrng_unregister(&msm_rng);
  if (*(long *)(lVar1 + 0x10) != 0) {
    clk_put();
  }
  iounmap(*(undefined8 *)(lVar1 + 8));
  *(undefined8 *)(param_1 + 0xa8) = 0;
  if (*(long *)(lVar1 + 0x48) != 0) {
    icc_put();
  }
  kfree_sensitive(lVar1);
  msm_rng_dev_cached = 0;
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00100744 size=124
// signature: undefined readl_relaxed(void)
// callers: [msm_rng_direct_read, msm_rng_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10078c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 001007c0 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1007d8,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100814,uVar1);
  return;
}



//------------------------------------------------------------
// msm_rng_read @ 00100848 size=32
// signature: undefined msm_rng_read(void)
// callers: []
//------------------------------------------------------------

void msm_rng_read(long param_1)

{
  msm_rng_direct_read(*(undefined8 *)(param_1 + 0x30));
  return;
}



//------------------------------------------------------------
// msm_rng_direct_read @ 00100868 size=396
// signature: undefined msm_rng_direct_read(void)
// callers: [qrng_get_random, msm_rng_read]
//------------------------------------------------------------

ulong msm_rng_direct_read(long param_1,undefined4 *param_2,ulong param_3)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  
  if (param_3 < 4) {
    uVar4 = 0;
    goto LAB_0010098c;
  }
  lVar6 = *(long *)(param_1 + 8);
  mutex_lock(param_1 + 0x18);
  if ((*(long *)(param_1 + 0x48) == 0) ||
     (iVar1 = icc_set_bw(*(long *)(param_1 + 0x48),0,300000), iVar1 == 0)) {
    lVar5 = *(long *)(param_1 + 0x10);
    if (lVar5 == 0) {
LAB_001008ec:
      iVar1 = 0;
      uVar4 = 0;
      do {
        while (uVar3 = readl_relaxed(lVar6 + 4), (uVar3 & 1) != 0) {
          uVar2 = readl_relaxed(lVar6);
          uVar4 = uVar4 + 4;
          *param_2 = uVar2;
          if ((param_3 - uVar4 < 4) || (param_2 = param_2 + 1, param_3 <= uVar4)) goto LAB_00100954;
        }
        if (iVar1 == 5) {
          if (uVar4 == 0) {
            _printk(&DAT_00101310);
            lVar6 = *(long *)(param_1 + 0x10);
            if (lVar6 == 0) goto LAB_0010096c;
            goto LAB_0010095c;
          }
          break;
        }
        iVar1 = iVar1 + 1;
        __const_udelay(0x1cd608);
      } while (uVar4 < param_3);
LAB_00100954:
      lVar6 = *(long *)(param_1 + 0x10);
      if (lVar6 != 0) {
LAB_0010095c:
        clk_disable(lVar6);
        clk_unprepare(lVar6);
      }
    }
    else {
      iVar1 = clk_prepare(lVar5);
      if (iVar1 == 0) {
        iVar1 = clk_enable(lVar5);
        if (iVar1 == 0) goto LAB_001008ec;
        clk_unprepare(lVar5);
      }
      _printk(&DAT_0010134e);
      uVar4 = 0;
    }
LAB_0010096c:
    if ((*(long *)(param_1 + 0x48) != 0) &&
       (iVar1 = icc_set_bw(*(long *)(param_1 + 0x48),0,0), iVar1 != 0)) goto LAB_001009b0;
  }
  else {
    uVar4 = 0;
LAB_001009b0:
    _printk(&DAT_001011ce);
  }
  mutex_unlock(param_1 + 0x18);
LAB_0010098c:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// msm_rng_ioctl @ 001009f8 size=116
// signature: undefined msm_rng_ioctl(void)
// callers: []
//------------------------------------------------------------

long msm_rng_ioctl(undefined8 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0x10001) {
    iVar1 = icc_set_bw(msm_rng_device_info_0,0,0);
    if (iVar1 != 0) {
      _printk(&DAT_0010116c,(long)iVar1);
      return (long)iVar1;
    }
  }
  else {
    _printk(&DAT_0010136d);
  }
  return 0;
}



//------------------------------------------------------------
// qrng_get_random @ 00100a70 size=228
// signature: undefined qrng_get_random(void)
// callers: []
//------------------------------------------------------------

undefined4 qrng_get_random(void)

{
  ulong *puVar1;
  int iVar2;
  long in_x3;
  int in_w4;
  undefined4 uVar3;
  
  if (msm_rng_dev_cached == 0) {
    _printk(&DAT_0010122f,"qrng_get_random");
    uVar3 = 0xffffffed;
  }
  else if (in_x3 == 0) {
    _printk(&DAT_001013b6,"qrng_get_random");
    uVar3 = 0xffffffea;
  }
  else {
    puVar1 = (ulong *)sp_el0;
    if (((((uint)*puVar1 >> 6 & 1) == 0) && ((*puVar1 & 1) == 0)) &&
       (iVar2 = mutex_lock_interruptible(cached_rng_lock), iVar2 == 0)) {
      iVar2 = msm_rng_direct_read(msm_rng_dev_cached,in_x3,in_w4);
      uVar3 = 0;
      if (iVar2 != in_w4) {
        uVar3 = 0xfffffff2;
      }
      mutex_unlock(cached_rng_lock);
    }
    else {
      _printk(&DAT_0010113e,"qrng_get_random");
      uVar3 = 0xfffffe00;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// qrng_reset @ 00100b58 size=8
// signature: undefined qrng_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 qrng_reset(void)

{
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100b68 size=136
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  msm_rng_dev_cached = 0;
  iVar1 = __platform_driver_register(&rng_driver,&__this_module);
  if (iVar1 == 0) {
    iVar1 = crypto_register_rngs(&rng_algs,1);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_00101299;
  }
  else {
    puVar2 = &DAT_001011a5;
  }
  _printk(puVar2,"msm_rng_init",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100bf4 size=52
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  crypto_unregister_rngs(&rng_algs,1);
  platform_driver_unregister(&rng_driver);
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
// crypto_register_rngs @ 00103008 size=1
// signature: undefined crypto_register_rngs(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_register_rngs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103010 size=1
// signature: undefined _printk(void)
// callers: [qrng_get_random, init_module, msm_rng_direct_read, msm_rng_probe, msm_rng_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_unregister_rngs @ 00103018 size=1
// signature: undefined crypto_unregister_rngs(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_unregister_rngs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00103020 size=1
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
// platform_get_resource @ 00103028 size=1
// signature: undefined platform_get_resource(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103038 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00103048 size=1
// signature: undefined ioremap_prot(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103050 size=1
// signature: undefined of_find_property(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00103058 size=1
// signature: undefined of_icc_get(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00103060 size=1
// signature: undefined icc_set_bw(void)
// callers: [msm_rng_direct_read, msm_rng_probe, msm_rng_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00103068 size=1
// signature: undefined clk_prepare(void)
// callers: [msm_rng_direct_read, msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00103070 size=1
// signature: undefined clk_enable(void)
// callers: [msm_rng_direct_read, msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00103078 size=1
// signature: undefined clk_disable(void)
// callers: [msm_rng_direct_read, msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00103080 size=1
// signature: undefined clk_unprepare(void)
// callers: [msm_rng_direct_read, msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103088 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hwrng_register @ 00103090 size=1
// signature: undefined hwrng_register(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hwrng_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_chrdev @ 00103098 size=1
// signature: undefined __register_chrdev(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001030a0 size=1
// signature: undefined __class_create(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001030a8 size=1
// signature: undefined device_create(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001030b0 size=1
// signature: undefined cdev_init(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 001030b8 size=1
// signature: undefined clk_get(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030c0 size=1
// signature: undefined _dev_err(void)
// callers: [msm_rng_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001030c8 size=1
// signature: undefined class_destroy(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 001030d0 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hwrng_unregister @ 001030d8 size=1
// signature: undefined hwrng_unregister(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hwrng_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 001030e0 size=1
// signature: undefined icc_put(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_put @ 001030e8 size=1
// signature: undefined clk_put(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 001030f0 size=1
// signature: undefined iounmap(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_sensitive @ 001030f8 size=1
// signature: undefined kfree_sensitive(void)
// callers: [msm_rng_probe, msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00103100 size=1
// signature: undefined cdev_del(void)
// callers: [msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00103108 size=1
// signature: undefined device_destroy(void)
// callers: [msm_rng_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00103110 size=1
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
// log_post_read_mmio @ 00103118 size=1
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
// log_write_mmio @ 00103120 size=1
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
// log_post_write_mmio @ 00103128 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103130 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_rng_direct_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00103138 size=1
// signature: undefined __const_udelay(void)
// callers: [msm_rng_direct_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103140 size=1
// signature: undefined mutex_unlock(void)
// callers: [qrng_get_random, msm_rng_direct_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock_interruptible @ 00103148 size=1
// signature: undefined mutex_lock_interruptible(void)
// callers: [qrng_get_random]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



