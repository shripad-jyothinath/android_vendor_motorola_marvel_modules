// Decompiled by Ghidra 12.2
// Program: msm-mmrm.ko
// Image base: 00100000

//------------------------------------------------------------
// mmrm_get_clk_mgr_ops @ 00100bfc size=180
// signature: undefined mmrm_get_clk_mgr_ops(void)
// callers: [mmrm_init]
//------------------------------------------------------------

undefined4 mmrm_get_clk_mgr_ops(long param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 1) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_0010724f,&DAT_00106027,"mmrm_get_clk_mgr_ops");
      uVar1 = 0xffffffea;
    }
    else {
      uVar1 = 0xffffffea;
    }
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
    *(undefined ***)(param_1 + 0x68) = &sw_clk_mgr_ops;
    uVar1 = 0;
  }
  else {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001064d4,&DAT_00106027,"mmrm_get_clk_mgr_ops");
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// mmrm_clk_client_register @ 00100cb4 size=252
// signature: undefined mmrm_clk_client_register(void)
// callers: [mmrm_client_register]
//------------------------------------------------------------

void mmrm_clk_client_register(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 auStack_e0 [152];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  if (((param_1 == 0) || (*(undefined8 **)(param_1 + 0x98) == (undefined8 *)0x0)) ||
     (pcVar5 = (code *)**(undefined8 **)(param_1 + 0x98), pcVar5 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a38,&DAT_00106027,"mmrm_clk_client_register");
    }
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined8 *)(param_2 + 0xa8);
    uVar1 = *(undefined8 *)(param_2 + 0xb0);
    uVar2 = *(undefined4 *)(param_2 + 0xa0);
    memcpy(auStack_e0,(void *)(param_2 + 8),0x98);
    if (*(int *)(pcVar5 + -4) != 0x77e1911) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8237,0x100d3c);
      (*pcVar5)();
    }
    uVar4 = (*pcVar5)(param_1,auStack_e0,uVar2,uVar4,uVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// mmrm_clk_client_deregister @ 00100db4 size=132
// signature: undefined mmrm_clk_client_deregister(void)
// callers: [mmrm_client_deregister]
//------------------------------------------------------------

undefined8 mmrm_clk_client_deregister(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x98) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 8), pcVar2 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a38,&DAT_00106027,"mmrm_clk_client_deregister");
    }
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x3af67783) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100dec);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// mmrm_clk_client_setval @ 00100e3c size=132
// signature: undefined mmrm_clk_client_setval(void)
// callers: [mmrm_client_set_value]
//------------------------------------------------------------

undefined8 mmrm_clk_client_setval(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x98) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x10), pcVar2 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a38,&DAT_00106027,"mmrm_clk_client_setval");
    }
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5304bab2) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100e74);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// mmrm_clk_client_setval_inrange @ 00100ec4 size=132
// signature: undefined mmrm_clk_client_setval_inrange(void)
// callers: [mmrm_client_set_value_in_range]
//------------------------------------------------------------

undefined8 mmrm_clk_client_setval_inrange(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x98) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x18), pcVar2 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a38,&DAT_00106027,"mmrm_clk_client_setval_inrange");
    }
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x763f1fca) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100efc);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// mmrm_clk_client_getval @ 00100f4c size=132
// signature: undefined mmrm_clk_client_getval(void)
// callers: [mmrm_client_get_value]
//------------------------------------------------------------

undefined8 mmrm_clk_client_getval(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x98) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x20), pcVar2 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a38,&DAT_00106027,"mmrm_clk_client_getval");
    }
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5c25fbad) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100f84);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// mmrm_clk_print_enabled_client_info @ 00100fd4 size=132
// signature: undefined mmrm_clk_print_enabled_client_info(void)
// callers: [dump_enabled_client_info_show]
//------------------------------------------------------------

undefined8 mmrm_clk_print_enabled_client_info(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x98) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x28), pcVar2 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a38,&DAT_00106027,"mmrm_clk_print_enabled_client_info");
    }
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x4ec1f042) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10100c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// mmrm_init_sw_clk_mgr @ 0010105c size=716
// signature: undefined mmrm_init_sw_clk_mgr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmrm_init_sw_clk_mgr(long param_1)

{
  int *piVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  ushort uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  
  lVar7 = kmalloc_trace(___kmalloc,0xdc0,0xa0);
  if (lVar7 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107366,&DAT_00106027,"mmrm_init_sw_clk_mgr");
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x50);
    *(long *)(lVar7 + 0x38) = param_1;
    lVar8 = __kmalloc(iVar10 * 0x1b0,0xdc0);
    *(long *)(lVar7 + 0x40) = lVar8;
    if (lVar8 != 0) {
      iVar10 = *(int *)(param_1 + 0x50);
      *(int *)(lVar7 + 0x48) = iVar10;
      *(undefined4 *)(lVar7 + 0x4c) = 0;
      *(long *)(lVar7 + 0x88) = lVar7 + 0x88;
      *(long *)(lVar7 + 0x90) = lVar7 + 0x88;
      if (iVar10 != 0) {
        lVar11 = 0;
        uVar12 = 0;
        lVar8 = 0x18c;
        do {
          piVar1 = (int *)(*(long *)(param_1 + 0x48) + lVar11);
          lVar2 = *(long *)(lVar7 + 0x40) + lVar8;
          *(int *)(lVar2 + -0xec) = piVar1[1] | *piVar1 << 0x10;
          *(int *)(lVar2 + -0xa0) = piVar1[2];
          *(int *)(lVar2 + -0x8c) = piVar1[3];
          *(int *)(lVar2 + -0xdc) = piVar1[4];
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
            _printk(&DAT_00106505,&DAT_00107aa9,"mmrm_sw_prepare_table");
          }
          uVar12 = uVar12 + 1;
          lVar8 = lVar8 + 0x1b0;
          lVar11 = lVar11 + 0x14;
        } while (uVar12 < *(uint *)(lVar7 + 0x48));
      }
      uVar3 = *(undefined4 *)(param_1 + 0x58);
      *(undefined8 *)(lVar7 + 0x80) = 0;
      uVar5 = *(ushort *)(param_1 + 0x30);
      uVar12 = (ulong)uVar5;
      *(undefined4 *)(lVar7 + 0x7c) = uVar3;
      *(ushort *)(lVar7 + 0x78) = uVar5;
      if (uVar5 != 0) {
        uVar9 = 0;
        do {
          if (*(int *)(lVar7 + 0x48) != 0) {
            if (4 < uVar9) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x101328);
              (*pcVar6)();
            }
            iVar10 = 0;
            iVar4 = *(int *)(param_1 + uVar9 * 4 + 0x1c);
            do {
              if (*(int *)(*(long *)(lVar7 + 0x40) + (long)iVar10 * 0x1b0 + 0xa0) == iVar4) {
                lVar8 = uVar9 * 8;
                if ((lVar8 - 0x50U < 0xffffffffffffff60) ||
                   (*(int *)(lVar7 + lVar8 + 0x50) = iVar4, lVar8 - 0x4dU < 0xffffffffffffff5f)) {
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(1,0x10121c);
                  (*pcVar6)();
                }
                uVar12 = (ulong)*(ushort *)(lVar7 + 0x78);
                *(short *)(lVar7 + uVar9 * 8 + 0x54) = (short)iVar10;
                break;
              }
              iVar10 = iVar10 + 1;
            } while (*(int *)(lVar7 + 0x48) != iVar10);
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar12);
      }
      __mutex_init(lVar7,"&sw_clk_mgr->lock",&mmrm_init_sw_clk_mgr___key);
      *(long *)(param_1 + 0x60) = lVar7;
      *(undefined4 *)(lVar7 + 0x30) = *(undefined4 *)(param_1 + 0x18);
      *(undefined ***)(lVar7 + 0x98) = &clk_client_swops;
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106d87,&DAT_00106027,"mmrm_init_sw_clk_mgr",*(undefined4 *)(param_1 + 0x50));
    }
    kfree(lVar7);
    *(undefined8 *)(param_1 + 0x60) = 0;
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_init_sw_clk_mgr",0xfffffff4);
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// mmrm_destroy_sw_clk_mgr @ 0010132c size=224
// signature: undefined mmrm_destroy_sw_clk_mgr(void)
// callers: []
//------------------------------------------------------------

undefined8 mmrm_destroy_sw_clk_mgr(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 uVar5;
  long *plVar6;
  
  plVar3 = *(long **)(param_1 + 0x88);
  while (plVar3 != (long *)(param_1 + 0x88)) {
    plVar6 = (long *)*plVar3;
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    kfree(plVar3);
    plVar3 = plVar6;
  }
  if (param_1 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107ed5,&DAT_00106027,"mmrm_destroy_sw_clk_mgr");
    }
    uVar5 = 0xffffffea;
  }
  else {
    kfree(*(undefined8 *)(param_1 + 0x40));
    kfree(param_1);
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// mmrm_sw_clk_client_register @ 00101410 size=1404
// signature: undefined mmrm_sw_clk_client_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
mmrm_sw_clk_client_register
          (long param_1,int *param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  size_t __n;
  undefined *puVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  uint *puVar9;
  ulong uVar10;
  void *__dest;
  undefined4 *puVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  
  mutex_lock();
  uVar6 = *(uint *)(param_1 + 0x48);
  if (uVar6 == *(uint *)(param_1 + 0x4c)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107b74,&DAT_00106027,"mmrm_sw_clk_client_register");
    }
  }
  else {
    uVar5 = param_2[1] | *param_2 << 0x10;
    if (uVar6 == 0) {
      uVar12 = 0;
LAB_001014c8:
      if ((uint)uVar12 == uVar6) goto LAB_001014d0;
      lVar15 = *(long *)(param_1 + 0x40);
      lVar13 = param_1 + 0x38;
      uVar10 = uVar12 & 0xffffffff;
      __dest = (void *)(lVar15 + (uVar12 & 0xffffffff) * 0x1b0);
      puVar1 = (undefined8 *)((long)__dest + 0x170);
      puVar11 = *(undefined4 **)((long)__dest + 0x170);
      if (puVar11 == (undefined4 *)0x0) {
        puVar11 = (undefined4 *)kmalloc_trace(_mutex_lock,0xdc0,8);
        if (puVar11 == (undefined4 *)0x0) {
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_001077ab,&DAT_00106027,"mmrm_sw_clk_client_register");
          }
          iVar2 = -0xc;
        }
        else {
          *puVar11 = 0;
          puVar11[1] = (uint)uVar12;
          *(undefined4 *)(lVar15 + uVar10 * 0x1b0 + 0x188) = 1;
          *puVar1 = puVar11;
          __n = strnlen((char *)(param_2 + 2),0x80);
          if (0x80 < __n) {
            fortify_panic("strnlen");
LAB_00101980:
            fortify_panic("__fortify_strlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
            halt_baddata();
          }
          if (__n == 0x80) goto LAB_00101980;
          memcpy(__dest,param_2 + 2,__n);
          lVar7 = lVar15 + uVar10 * 0x1b0;
          *(undefined1 *)((long)__dest + __n) = 0;
          uVar8 = *(undefined8 *)(param_2 + 0x22);
          *(undefined4 *)(lVar7 + 0x88) = param_3;
          *(undefined8 *)(lVar7 + 0x80) = uVar8;
          *(undefined8 *)(lVar7 + 0x90) = param_4;
          *(undefined8 *)(lVar7 + 0x98) = param_5;
          uVar6 = param_2[0x24];
          if ((uVar6 < 7) && (uVar5 = param_2[0x25], uVar5 < 6)) {
            if ((uVar6 == 0) || (uVar5 == 0)) {
LAB_0010177c:
              if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                lVar4 = lVar15 + uVar10 * 0x1b0;
                _printk(&DAT_001075ef,&DAT_00107aa9,"mmrm_sw_clk_client_register",
                        *(undefined4 *)(lVar4 + 0xa0),__dest,*(undefined4 *)(lVar7 + 0x88),
                        *(undefined8 *)(lVar7 + 0x90),*(undefined8 *)(lVar7 + 0x98),
                        *(undefined4 *)(lVar4 + 0x194),*(undefined4 *)(lVar4 + 0x198));
              }
              mmrm_sw_update_freq(lVar13,__dest);
              iVar2 = mmrm_sw_update_curr(lVar13,__dest);
              if (iVar2 == 0) {
LAB_00101578:
                mutex_unlock(param_1);
                return puVar11;
              }
              if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
                _printk(&DAT_0010663b,&DAT_00106027,"mmrm_sw_clk_client_register",
                        *(undefined4 *)(lVar15 + uVar10 * 0x1b0 + 0xa0));
              }
              lVar13 = lVar15 + uVar10 * 0x1b0;
              *(undefined1 *)(lVar13 + 400) = 0;
              *(undefined4 *)(lVar13 + 0x19c) = 0;
              *(undefined8 *)(lVar13 + 0x194) = 0;
              kfree(*(undefined8 *)(lVar13 + 0x1a8));
              *(undefined8 *)(lVar13 + 0x1a8) = 0;
            }
            else {
              if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                _printk(&DAT_001060c3,&DAT_00107aa9,"mmrm_sw_clk_client_register");
                uVar6 = param_2[0x24];
                uVar5 = param_2[0x25];
              }
              uVar6 = uVar5 * uVar6 + 1;
              lVar14 = lVar15 + uVar10 * 0x1b0;
              *(uint *)(lVar14 + 0x1a0) = uVar6;
              lVar4 = __kmalloc((ulong)uVar6 << 3,0xdc0);
              *(long *)(lVar14 + 0x1a8) = lVar4;
              if (lVar4 != 0) {
                lVar4 = lVar15 + uVar10 * 0x1b0;
                *(undefined1 *)(lVar4 + 400) = 1;
                *(undefined4 *)(lVar4 + 0x19c) = 0;
                *(int *)(lVar4 + 0x194) = param_2[0x24];
                *(int *)(lVar4 + 0x198) = param_2[0x25];
                goto LAB_0010177c;
              }
              if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
                _printk(&DAT_001067f4,&DAT_00106027,"mmrm_sw_clk_client_register");
              }
              iVar2 = -0xc;
            }
            *(undefined4 *)(lVar15 + uVar10 * 0x1b0 + 0x1a0) = 0;
          }
          else {
            if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
              _printk(&DAT_001065ef,&DAT_00106027,"mmrm_sw_clk_client_register",uVar6,param_2[0x25])
              ;
            }
            iVar2 = -0x16;
          }
          kfree(puVar11);
        }
        *puVar1 = 0;
        lVar15 = lVar15 + uVar10 * 0x1b0;
        *(undefined8 *)(lVar15 + 0x80) = 0;
        *(undefined4 *)(lVar15 + 0x88) = 0;
        *(undefined8 *)(lVar15 + 0x90) = 0;
        *(undefined8 *)(lVar15 + 0x98) = 0;
        goto LAB_001014e0;
      }
      if (msm_mmrm_allow_multiple_register != '\0') {
        lVar7 = lVar15 + uVar10 * 0x1b0;
        *(int *)(lVar7 + 0x188) = *(int *)(lVar7 + 0x188) + 1;
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_001075ad,&DAT_00107aa9,"mmrm_sw_clk_client_register",
                  *(undefined4 *)(lVar15 + uVar10 * 0x1b0 + 0xa0));
          puVar11 = (undefined4 *)*puVar1;
        }
        mmrm_sw_print_client_data(lVar13,__dest);
        goto LAB_00101578;
      }
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_001014dc;
      puVar3 = &DAT_00106ef4;
      uVar5 = *(uint *)(lVar15 + uVar10 * 0x1b0 + 0xa0);
    }
    else {
      uVar12 = 0;
      puVar9 = (uint *)(*(long *)(param_1 + 0x40) + 0xa0);
      do {
        if (uVar5 == *puVar9) goto LAB_001014c8;
        uVar12 = uVar12 + 1;
        puVar9 = puVar9 + 0x6c;
      } while (uVar6 != uVar12);
LAB_001014d0:
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_001014dc;
      puVar3 = &DAT_001070c4;
    }
    _printk(puVar3,&DAT_00106027,"mmrm_sw_clk_client_register",uVar5);
  }
LAB_001014dc:
  iVar2 = -0x16;
LAB_001014e0:
  mutex_unlock(param_1);
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_sw_clk_client_register",iVar2);
  }
  return (undefined4 *)0x0;
}



//------------------------------------------------------------
// mmrm_sw_clk_client_deregister @ 00101990 size=348
// signature: undefined mmrm_sw_clk_client_deregister(void)
// callers: []
//------------------------------------------------------------

undefined8 mmrm_sw_clk_client_deregister(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (param_2 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00105e7f,&DAT_00106027,"mmrm_sw_clk_client_deregister");
    }
  }
  else {
    if (*(uint *)(param_2 + 4) < *(uint *)(param_1 + 0x48)) {
      mutex_lock(param_1);
      lVar3 = *(long *)(param_1 + 0x40);
      uVar1 = *(uint *)(param_2 + 4);
      lVar4 = lVar3 + (ulong)uVar1 * 0x1b0;
      iVar2 = *(int *)(lVar4 + 0x188);
      if ((iVar2 == 0) || (iVar2 = iVar2 + -1, *(int *)(lVar4 + 0x188) = iVar2, iVar2 == 0)) {
        lVar3 = lVar3 + (ulong)uVar1 * 0x1b0;
        kfree(*(undefined8 *)(lVar3 + 0x1a8));
        *(undefined8 *)(lVar3 + 0x1a8) = 0;
        kfree(*(undefined8 *)(lVar3 + 0x170));
        *(undefined8 *)(lVar3 + 0x80) = 0;
        *(undefined4 *)(lVar3 + 0x88) = 0;
        *(undefined1 *)(lVar3 + 400) = 0;
        *(undefined8 *)(lVar3 + 0x90) = 0;
        *(undefined8 *)(lVar3 + 0x98) = 0;
        *(undefined8 *)(lVar3 + 0x170) = 0;
        *(undefined8 *)(lVar3 + 0x178) = 0;
        *(undefined4 *)(lVar3 + 0x180) = 0;
        *(undefined8 *)(lVar3 + 0x194) = 0;
        *(undefined8 *)(lVar3 + 0x19c) = 0;
      }
      mutex_unlock(param_1);
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_0010749b,&DAT_00106027,"mmrm_sw_clk_client_deregister");
    }
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_sw_clk_client_deregister",0xffffffea);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// mmrm_sw_clk_client_setval @ 00101af0 size=1684
// signature: undefined mmrm_sw_clk_client_setval(void)
// callers: [mmrm_sw_clk_client_setval_inrange]
//------------------------------------------------------------

int mmrm_sw_clk_client_setval(long param_1,long param_2,uint *param_3,long param_4)

{
  char *pcVar1;
  long *plVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  ulong *puVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined8 local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_70 = 0;
  if (param_2 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      puVar8 = &DAT_00105e7f;
      goto LAB_00101c60;
    }
LAB_00101f98:
    iVar6 = -0x16;
  }
  else {
    uVar5 = *(uint *)(param_2 + 4);
    if (*(uint *)(param_1 + 0x48) <= uVar5) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_0010749b,&DAT_00106027,"mmrm_sw_clk_client_setval",uVar5);
      }
      goto LAB_00101f98;
    }
    if (param_3 == (uint *)0x0) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        puVar8 = &DAT_001078b3;
LAB_00101c60:
        _printk(puVar8,&DAT_00106027,"mmrm_sw_clk_client_setval");
      }
      goto LAB_00101f98;
    }
    lVar14 = *(long *)(param_1 + 0x40);
    lVar15 = lVar14 + (ulong)uVar5 * 0x1b0;
    puVar12 = (ulong *)(lVar15 + 0x80);
    if ((*puVar12 == 0) || (0xfffffffffffff000 < *puVar12)) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        puVar8 = &DAT_00107bb1;
        goto LAB_00101c60;
      }
      goto LAB_00101f98;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_001078dd,&DAT_00107aa9,"mmrm_sw_clk_client_setval",
              *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),param_4);
    }
    lVar13 = lVar14 + (ulong)uVar5 * 0x1b0;
    if (*(char *)(lVar13 + 400) == '\0') {
      lVar7 = 0;
    }
    else {
      if ((*(uint *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0x194) <= param_3[3]) ||
         (*(uint *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0x198) <= param_3[4])) {
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          puVar8 = &DAT_001070f2;
          goto LAB_00101c60;
        }
        goto LAB_00101f98;
      }
      lVar7 = mmrm_sw_get_max_crm_rate(lVar15,param_3,param_4,&local_70);
    }
    pcVar1 = (char *)(lVar13 + 400);
    lVar13 = lVar14 + (ulong)uVar5 * 0x1b0;
    uVar3 = param_3[1] & 1;
    if (((*(long *)(lVar13 + 0x178) == param_4) &&
        (*(uint *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0x18c) == *param_3)) && (*pcVar1 == '\0')) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_001074c9,&DAT_00107aa9,"mmrm_sw_clk_client_setval",
                *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),param_4);
      }
      lVar13 = lVar14 + (ulong)uVar5 * 0x1b0;
      if (uVar3 != *(byte *)(lVar13 + 0x184)) {
        mutex_lock(param_1);
        *(char *)(lVar13 + 0x184) = (char)uVar3;
        mutex_unlock(param_1);
        if (uVar3 == 0) {
LAB_00101f1c:
          if (*pcVar1 != '\0') goto LAB_00101f38;
LAB_00101f6c:
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
            _printk(&DAT_00106f76,&DAT_00107aa9,"mmrm_sw_clk_client_setval",
                    *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),param_4);
          }
          iVar6 = clk_set_rate(*puVar12,param_4);
          if (iVar6 != 0) goto LAB_00101f8c;
        }
      }
LAB_00102018:
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_00107aae,&DAT_00107aa9,"mmrm_sw_clk_client_setval",param_4,lVar15);
      }
      iVar6 = 0;
      goto LAB_00101fa8;
    }
    if (param_4 != 0) {
      lVar4 = param_4;
      if (*pcVar1 != '\0') {
        lVar4 = lVar7;
      }
      iVar6 = mmrm_sw_get_req_level(lVar15,lVar4,(long)&local_70 + 4);
      if ((iVar6 == 0) && (local_70._4_4_ < 5)) {
        if ((*param_3 != 0) &&
           (uVar9 = local_70._4_4_, *param_3 <= *(uint *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xb0)))
        goto LAB_00101d4c;
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_001073a5,&DAT_00106027,"mmrm_sw_clk_client_setval",
                  *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0));
        }
      }
      else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107678,&DAT_00106027,"mmrm_sw_clk_client_setval",
                *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),param_4,lVar7);
      }
      goto LAB_00101f98;
    }
    uVar9 = 0;
LAB_00101d4c:
    mutex_lock(param_1);
    uVar11 = (undefined4)param_4;
    if (*pcVar1 != '\0') {
      uVar11 = (undefined4)lVar7;
    }
    iVar6 = mmrm_sw_check_peak_current(param_1 + 0x38,lVar15,uVar9,uVar11,*param_3);
    if (iVar6 == 0) {
      plVar2 = (long *)(lVar13 + 0x178);
      if (*pcVar1 == '\0') {
        *plVar2 = param_4;
      }
      else {
        *plVar2 = lVar7;
        lVar13 = lVar14 + (ulong)uVar5 * 0x1b0;
        *(undefined4 *)(lVar13 + 0x19c) = (undefined4)local_70;
        lVar7 = lVar14 + (ulong)uVar5 * 0x1b0;
        if (param_3[2] == 0) {
          uVar10 = *(int *)(lVar7 + 0x1a0) - 1;
        }
        else {
          uVar10 = param_3[4] + param_3[3] * *(int *)(lVar7 + 0x198);
        }
        *(long *)(*(long *)(lVar13 + 0x1a8) + (ulong)uVar10 * 8) = param_4;
        mmrm_sw_print_crm_table(lVar15);
      }
      lVar13 = lVar14 + (ulong)uVar5 * 0x1b0;
      *(uint *)(lVar13 + 0x180) = uVar9;
      *(char *)(lVar13 + 0x184) = (char)uVar3;
      *(uint *)(lVar13 + 0x18c) = *param_3;
      mutex_unlock(param_1);
      if (uVar3 == 0) goto LAB_00101f1c;
      if (*pcVar1 == '\0') {
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_00107efb,&DAT_00107aa9,"mmrm_sw_clk_client_setval",
                  *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0));
        }
        goto LAB_00102018;
      }
LAB_00101f38:
      if (param_3[2] == 0) goto LAB_00101f6c;
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_001068bb,&DAT_00107aa9,"mmrm_sw_clk_client_setval",
                *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),param_4,0,param_3[3],
                param_3[4]);
      }
      iVar6 = qcom_clk_crm_set_rate(*puVar12,0,param_3[3],param_3[4],param_4);
      if (iVar6 == 0) goto LAB_00102018;
LAB_00101f8c:
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00106259,&DAT_00106027,"mmrm_sw_clk_client_setval",
                *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),param_4);
      }
      goto LAB_00101f98;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001072ee,&DAT_00106027,"mmrm_sw_clk_client_setval",
              *(undefined4 *)(lVar14 + (ulong)uVar5 * 0x1b0 + 0xa0),*(undefined4 *)(param_1 + 0x80))
      ;
    }
    mutex_unlock(param_1);
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_sw_clk_client_setval",iVar6);
  }
LAB_00101fa8:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// mmrm_sw_clk_client_setval_inrange @ 00102188 size=32
// signature: undefined mmrm_sw_clk_client_setval_inrange(void)
// callers: []
//------------------------------------------------------------

void mmrm_sw_clk_client_setval_inrange(void)

{
  mmrm_sw_clk_client_setval();
  return;
}



//------------------------------------------------------------
// mmrm_sw_clk_client_getval @ 001021ac size=288
// signature: undefined mmrm_sw_clk_client_getval(void)
// callers: []
//------------------------------------------------------------

undefined8 mmrm_sw_clk_client_getval(long param_1,long param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_2 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_00102280;
    puVar2 = &DAT_00105e7f;
  }
  else {
    uVar1 = *(uint *)(param_2 + 4);
    if (*(uint *)(param_1 + 0x48) <= uVar1) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_0010749b,&DAT_00106027,"mmrm_sw_clk_client_getval");
      }
      goto LAB_00102280;
    }
    if (*(long *)(*(long *)(param_1 + 0x40) + (ulong)uVar1 * 0x1b0 + 0x80) != 0) {
      lVar3 = *(long *)(param_1 + 0x40) + (ulong)uVar1 * 0x1b0;
      *param_3 = *(undefined8 *)(lVar3 + 0x178);
      param_3[1] = *(undefined8 *)(lVar3 + 0x178);
      param_3[2] = *(undefined8 *)(lVar3 + 0x178);
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_00102280;
    puVar2 = &DAT_00107bb1;
  }
  _printk(puVar2,&DAT_00106027,"mmrm_sw_clk_client_getval");
LAB_00102280:
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_sw_clk_client_getval",0xffffffea);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// mmrm_sw_clk_print_enabled_client_info @ 001022d0 size=336
// signature: undefined mmrm_sw_clk_print_enabled_client_info(void)
// callers: []
//------------------------------------------------------------

int mmrm_sw_clk_print_enabled_client_info(long param_1,long param_2,int param_3)

{
  bool bVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  
  uVar4 = scnprintf(param_2,param_3,"  csid    clk_rate     vdd_level   cur_ma   num_hw_blocks\n");
  uVar8 = param_3 - uVar4;
  if ((param_1 != -0x38) && (param_1 != -0x7c)) {
    uVar6 = (ulong)*(uint *)(param_1 + 0x48);
    param_2 = param_2 + (ulong)uVar4;
    bVar1 = 1 < uVar8;
    if ((*(uint *)(param_1 + 0x48) != 0) && (1 < uVar8)) {
      lVar9 = 0;
      uVar10 = 1;
      do {
        lVar7 = *(long *)(param_1 + 0x40);
        if (lVar7 + lVar9 != 0) {
          lVar2 = lVar7 + lVar9;
          if (*(long *)(lVar2 + 0x178) != 0) {
            uVar4 = *(uint *)(lVar2 + 0x180);
            if ((4 < uVar4) || (4 < *(uint *)(param_1 + 0x84))) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x102420);
              (*pcVar3)();
            }
            uVar4 = scnprintf(param_2,uVar8,"0x%x    %zu   %zu   %zu   %zu\n",
                              *(undefined4 *)(lVar2 + 0xa0),*(long *)(lVar2 + 0x178),uVar4,
                              *(int *)(lVar7 + lVar9 + 0x18c) *
                              *(int *)(lVar7 + lVar9 +
                                       (ulong)*(uint *)(param_1 + 0x84) * 4 + (ulong)uVar4 * 0x14 +
                                      0x108));
            uVar6 = (ulong)*(uint *)(param_1 + 0x48);
            uVar8 = uVar8 - uVar4;
            param_2 = param_2 + (ulong)uVar4;
          }
        }
        bVar1 = 1 < uVar8;
        if (uVar6 <= uVar10) break;
        lVar9 = lVar9 + 0x1b0;
        uVar10 = uVar10 + 1;
      } while (1 < uVar8);
    }
    if (bVar1) {
      iVar5 = scnprintf(param_2,uVar8,"aggreg_val(%zu) aggreg_level(%zu)\n",
                        *(undefined4 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x84));
      uVar8 = uVar8 - iVar5;
    }
  }
  return param_3 - uVar8;
}



//------------------------------------------------------------
// mmrm_sw_print_client_data @ 00102420 size=488
// signature: undefined mmrm_sw_print_client_data(void)
// callers: [mmrm_sw_clk_client_register, mmrm_sw_update_curr]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void mmrm_sw_print_client_data(long *param_1,long param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  long lVar3;
  int *piVar4;
  long lVar5;
  
  lVar3 = 0;
  piVar4 = (int *)(param_2 + 0xf4);
  lVar5 = *param_1;
  puVar2 = (undefined4 *)(param_2 + 0x118);
  uVar1 = msm_mmrm_debug;
  do {
    if (((uVar1 ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00106f2f,"power","mmrm_sw_print_client_data",*(undefined4 *)(param_2 + 0xa0),
              *(undefined8 *)(*(long *)(lVar5 + 0x38) + lVar3),piVar4[-5],*piVar4);
      uVar1 = msm_mmrm_debug;
    }
    if (((uVar1 ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00107cf8,"power","mmrm_sw_print_client_data",*(undefined4 *)(param_2 + 0xa0),
              *piVar4 + piVar4[-5],puVar2[-4]);
      uVar1 = msm_mmrm_debug;
    }
    if (((uVar1 ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00107cf8,"power","mmrm_sw_print_client_data",*(undefined4 *)(param_2 + 0xa0),
              *piVar4 + piVar4[-5],puVar2[-3]);
      uVar1 = msm_mmrm_debug;
    }
    if (((uVar1 ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00107cf8,"power","mmrm_sw_print_client_data",*(undefined4 *)(param_2 + 0xa0),
              *piVar4 + piVar4[-5],puVar2[-2]);
      uVar1 = msm_mmrm_debug;
    }
    if (((uVar1 ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00107cf8,"power","mmrm_sw_print_client_data",*(undefined4 *)(param_2 + 0xa0),
              *piVar4 + piVar4[-5],puVar2[-1]);
      uVar1 = msm_mmrm_debug;
    }
    if (((uVar1 ^ 0xffffffff) & 0x10010) == 0) {
      _printk(&DAT_00107cf8,"power","mmrm_sw_print_client_data",*(undefined4 *)(param_2 + 0xa0),
              *piVar4 + piVar4[-5],*puVar2);
      uVar1 = msm_mmrm_debug;
    }
    lVar3 = lVar3 + 0x18;
    piVar4 = piVar4 + 1;
    puVar2 = puVar2 + 5;
  } while (lVar3 != 0x78);
  return;
}



//------------------------------------------------------------
// mmrm_sw_update_freq @ 00102608 size=700
// signature: undefined mmrm_sw_update_freq(void)
// callers: [mmrm_sw_clk_client_register]
//------------------------------------------------------------

void mmrm_sw_update_freq(long *param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *param_1;
  lVar3 = clk_round_rate(*(undefined8 *)(param_2 + 0x80),1);
  lVar4 = clk_round_rate(*(undefined8 *)(param_2 + 0x80),0xffffffffffffffff);
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106855,&DAT_00107aa9,"mmrm_sw_update_freq",*(undefined4 *)(param_2 + 0xa0),lVar3,
            lVar4);
  }
  *(long *)(param_2 + 0xb8) = lVar3;
  *(long *)(param_2 + 0xc0) = lVar3;
  *(long *)(param_2 + 200) = lVar3;
  *(long *)(param_2 + 0xd0) = lVar3;
  *(long *)(param_2 + 0xd8) = lVar3;
  if (lVar3 < lVar4) {
    lVar7 = lVar3;
    do {
      lVar5 = clk_round_rate(*(undefined8 *)(param_2 + 0x80),lVar3);
      if (lVar7 < lVar5) {
        uVar2 = qcom_clk_get_voltage(*(undefined8 *)(param_2 + 0x80),lVar5);
        if (0x180 < uVar2) break;
        if (uVar2 < 0x41) {
          lVar7 = 0;
LAB_001026e4:
          do {
            lVar1 = lVar7 + 1;
            *(long *)(param_2 + 0xb8 + lVar7 * 8) = lVar5;
            lVar7 = lVar1;
          } while (lVar1 != 5);
        }
        else {
          uVar2 = (uint)(CONCAT44(uVar2,uVar2 - 0x80) >> 6);
          if ((uVar2 < 5) && ((0x17U >> (ulong)(uVar2 & 0x1f) & 1) != 0)) {
            lVar7 = *(long *)(&DAT_00107fd0 + (long)(int)uVar2 * 8);
            goto LAB_001026e4;
          }
        }
        lVar7 = lVar5;
      }
      lVar3 = lVar3 + 1000000;
    } while (lVar3 < lVar4);
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106cf2,&DAT_00107aa9,"mmrm_sw_update_freq",*(undefined4 *)(param_2 + 0xa0),
            **(undefined8 **)(lVar6 + 0x38),*(undefined8 *)(param_2 + 0xb8));
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106cf2,&DAT_00107aa9,"mmrm_sw_update_freq",*(undefined4 *)(param_2 + 0xa0),
            *(undefined8 *)(*(long *)(lVar6 + 0x38) + 0x18),*(undefined8 *)(param_2 + 0xc0));
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106cf2,&DAT_00107aa9,"mmrm_sw_update_freq",*(undefined4 *)(param_2 + 0xa0),
            *(undefined8 *)(*(long *)(lVar6 + 0x38) + 0x30),*(undefined8 *)(param_2 + 200));
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106cf2,&DAT_00107aa9,"mmrm_sw_update_freq",*(undefined4 *)(param_2 + 0xa0),
            *(undefined8 *)(*(long *)(lVar6 + 0x38) + 0x48),*(undefined8 *)(param_2 + 0xd0));
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106cf2,&DAT_00107aa9,"mmrm_sw_update_freq",*(undefined4 *)(param_2 + 0xa0),
            *(undefined8 *)(*(long *)(lVar6 + 0x38) + 0x60),*(undefined8 *)(param_2 + 0xd8));
  }
  return;
}



//------------------------------------------------------------
// mmrm_sw_update_curr @ 001028c4 size=708
// signature: undefined mmrm_sw_update_curr(void)
// callers: [mmrm_sw_clk_client_register]
//------------------------------------------------------------

undefined8 mmrm_sw_update_curr(long *param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  int *piVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  
  if (*(uint *)(param_1 + 2) != 0) {
    lVar7 = *param_1;
    lVar14 = 0;
    piVar15 = (int *)(param_1[1] + 0xa0);
    do {
      if (*(int *)(param_2 + 0xa0) == *piVar15) {
        if (*(long *)(lVar7 + 0x48) + lVar14 != 0) {
          lVar14 = *(long *)(lVar7 + 0x48) + lVar14;
          lVar13 = 0;
          lVar18 = 0x118;
          uVar3 = *(uint *)(lVar14 + 8);
          uVar5 = *(uint *)(lVar14 + 0xc);
          uVar16 = *(ulong *)(param_2 + 0xd0);
          lVar14 = 0xb8;
          lVar17 = 0xf4;
          do {
            plVar1 = (long *)(param_2 + lVar14);
            lVar14 = lVar14 + 8;
            lVar2 = *(long *)(lVar7 + 0x38) + lVar13;
            lVar13 = lVar13 + 0x18;
            uVar4 = *(uint *)(lVar2 + 0xc);
            uVar6 = *(uint *)(lVar2 + 0x10);
            uVar9 = 0;
            if (uVar16 != 0) {
              uVar9 = (*plVar1 * (((ulong)uVar3 & 0xffff0000) +
                                 (ulong)((uVar3 & 0xffff) * 100 & 0x7f0000) / 100) &
                      0xffffffffffff0000) / uVar16;
            }
            uVar9 = (((ulong)uVar4 & 0xffff0000) + (ulong)((uVar4 & 0xffff) * 100 & 0x7f0000) / 100)
                    * uVar9;
            piVar15 = (int *)(param_2 + lVar17);
            uVar8 = (((ulong)uVar6 & 0xffff0000) + (ulong)((uVar6 & 0xffff) * 100 & 0x7f0000) / 100)
                    * (((ulong)uVar5 & 0xffff0000) +
                      (ulong)((uVar5 & 0xffff) * 100 & 0x7f0000) / 100);
            lVar17 = lVar17 + 4;
            iVar11 = (int)(uVar9 >> 0x20);
            if (0x7ffe0000 < (uVar9 & 0xffff0000)) {
              iVar11 = iVar11 + 1;
            }
            iVar12 = (int)(uVar8 >> 0x20);
            if (0x7ffe0000 < (uVar8 & 0xffff0000)) {
              iVar12 = iVar12 + 1;
            }
            piVar15[-5] = iVar11;
            uVar10 = (uVar9 & 0xffffffffffff0000) + uVar8 & 0xffffffffffff0000;
            *piVar15 = iVar12;
            uVar4 = *(uint *)(*(long *)(lVar7 + 0x38) + 8);
            uVar9 = ((ulong)uVar4 & 0xffff0000) + (ulong)((uVar4 & 0xffff) * 100 & 0x7f0000) / 100;
            uVar8 = 0;
            if (uVar9 != 0) {
              uVar8 = uVar10 / uVar9;
            }
            piVar15 = (int *)(param_2 + lVar18);
            iVar11 = (int)(uVar8 >> 0x10);
            if (0x7ffe < (uVar8 & 0xffff)) {
              iVar11 = iVar11 + 1;
            }
            lVar18 = lVar18 + 0x14;
            piVar15[-4] = iVar11;
            uVar4 = *(uint *)(*(long *)(lVar7 + 0x38) + 0x20);
            uVar9 = ((ulong)uVar4 & 0xffff0000) + (ulong)((uVar4 & 0xffff) * 100 & 0x7f0000) / 100;
            uVar8 = 0;
            if (uVar9 != 0) {
              uVar8 = uVar10 / uVar9;
            }
            iVar11 = (int)(uVar8 >> 0x10);
            if (0x7ffe < (uVar8 & 0xffff)) {
              iVar11 = iVar11 + 1;
            }
            piVar15[-3] = iVar11;
            uVar4 = *(uint *)(*(long *)(lVar7 + 0x38) + 0x38);
            uVar9 = ((ulong)uVar4 & 0xffff0000) + (ulong)((uVar4 & 0xffff) * 100 & 0x7f0000) / 100;
            uVar8 = 0;
            if (uVar9 != 0) {
              uVar8 = uVar10 / uVar9;
            }
            iVar11 = (int)(uVar8 >> 0x10);
            if (0x7ffe < (uVar8 & 0xffff)) {
              iVar11 = iVar11 + 1;
            }
            piVar15[-2] = iVar11;
            uVar4 = *(uint *)(*(long *)(lVar7 + 0x38) + 0x50);
            uVar9 = ((ulong)uVar4 & 0xffff0000) + (ulong)((uVar4 & 0xffff) * 100 & 0x7f0000) / 100;
            uVar8 = 0;
            if (uVar9 != 0) {
              uVar8 = uVar10 / uVar9;
            }
            iVar11 = (int)(uVar8 >> 0x10);
            if (0x7ffe < (uVar8 & 0xffff)) {
              iVar11 = iVar11 + 1;
            }
            piVar15[-1] = iVar11;
            uVar4 = *(uint *)(*(long *)(lVar7 + 0x38) + 0x68);
            uVar9 = ((ulong)uVar4 & 0xffff0000) + (ulong)((uVar4 & 0xffff) * 100 & 0x7f0000) / 100;
            uVar8 = 0;
            if (uVar9 != 0) {
              uVar8 = uVar10 / uVar9;
            }
            iVar11 = (int)(uVar8 >> 0x10);
            if (0x7ffe < (uVar8 & 0xffff)) {
              iVar11 = iVar11 + 1;
            }
            *piVar15 = iVar11;
          } while (lVar13 != 0x78);
          mmrm_sw_print_client_data();
          return 0;
        }
        break;
      }
      lVar14 = lVar14 + 0x14;
      piVar15 = piVar15 + 0x6c;
    } while ((ulong)*(uint *)(param_1 + 2) * 0x14 != lVar14);
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106ae0,&DAT_00107aa9,"mmrm_sw_update_curr",*(undefined4 *)(param_2 + 0xa0));
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// mmrm_sw_get_max_crm_rate @ 00102b88 size=288
// signature: undefined mmrm_sw_get_max_crm_rate(void)
// callers: [mmrm_sw_clk_client_setval]
//------------------------------------------------------------

ulong mmrm_sw_get_max_crm_rate(long param_1,long param_2,ulong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar2 = *(uint *)(param_1 + 0x19c);
  uVar6 = *(ulong *)(param_1 + 0x178);
  *param_4 = uVar2;
  if (*(int *)(param_2 + 8) == 0) {
    uVar1 = *(int *)(param_1 + 0x1a0) - 1;
  }
  else {
    uVar1 = *(int *)(param_2 + 0x10) + *(int *)(param_2 + 0xc) * *(int *)(param_1 + 0x198);
  }
  uVar3 = uVar1;
  if (param_3 <= (uVar6 & 0xffffffff)) {
    if (uVar1 != *(uint *)(param_1 + 0x19c)) goto LAB_00102c54;
    uVar3 = *(uint *)(param_1 + 0x1a0);
    if (uVar3 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0;
      uVar4 = 0;
      do {
        if ((uVar4 != *(uint *)(param_1 + 0x19c)) &&
           (uVar5 = *(ulong *)(*(long *)(param_1 + 0x1a8) + (long)(int)uVar4 * 8), uVar6 < uVar5)) {
          *param_4 = uVar4;
          uVar3 = *(uint *)(param_1 + 0x1a0);
          uVar6 = uVar5 & 0xffffffff;
          uVar2 = uVar4;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
    if (param_3 < uVar6) goto LAB_00102c54;
    uVar3 = *(uint *)(param_1 + 0x19c);
  }
  uVar2 = uVar3;
  uVar6 = param_3 & 0xffffffff;
  *param_4 = uVar2;
LAB_00102c54:
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106118,&DAT_00107aa9,"mmrm_sw_get_max_crm_rate",*(undefined4 *)(param_1 + 0xa0),
            uVar1,param_3,uVar2,uVar6 & 0xffffffff);
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// mmrm_sw_get_req_level @ 00102ca8 size=408
// signature: undefined mmrm_sw_get_req_level(void)
// callers: [mmrm_sw_clk_client_setval]
//------------------------------------------------------------

uint mmrm_sw_get_req_level(long param_1,undefined8 param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar3 = clk_round_rate(*(undefined8 *)(param_1 + 0x80));
  uVar2 = qcom_clk_get_voltage(*(undefined8 *)(param_1 + 0x80),uVar3);
  if (uVar2 < 0x181) {
    if (uVar2 < 0x40) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_00106fad,&DAT_00107aa9,"mmrm_sw_get_req_level",*(undefined4 *)(param_1 + 0xa0),
                uVar2);
      }
      uVar2 = 0;
      *param_3 = 0;
    }
    else {
      uVar1 = (uint)(CONCAT44(uVar2,uVar2 - 0x40) >> 6);
      if ((uVar1 < 6) && ((0x2fU >> (ulong)(uVar1 & 0x1f) & 1) != 0)) {
        *param_3 = *(undefined4 *)(&DAT_00107ff8 + (long)(int)uVar1 * 4);
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_00107509,&DAT_00107aa9,"mmrm_sw_get_req_level");
        }
        uVar2 = 0;
      }
      else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00105ebe,&DAT_00106027,"mmrm_sw_get_req_level",*(undefined4 *)(param_1 + 0xa0),
                uVar2,uVar3);
        uVar2 = 0xffffffea;
      }
      else {
        uVar2 = 0xffffffea;
      }
    }
  }
  else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00105ebe,&DAT_00106027,"mmrm_sw_get_req_level",*(undefined4 *)(param_1 + 0xa0),
            uVar2,uVar3);
  }
  return uVar2;
}



//------------------------------------------------------------
// mmrm_sw_check_peak_current @ 00102e40 size=3176
// signature: undefined mmrm_sw_check_peak_current(void)
// callers: [mmrm_sw_clk_client_setval]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int mmrm_sw_check_peak_current(long param_1,long param_2,uint param_3,int param_4,int param_5)

{
  uint *puVar1;
  undefined8 *puVar2;
  long *plVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  undefined *puVar10;
  code *pcVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  undefined8 uVar16;
  ulong uVar17;
  uint uVar18;
  ulong uVar19;
  long lVar20;
  uint uVar21;
  long *plVar22;
  undefined8 *puVar23;
  long lVar24;
  ulong uVar25;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  if (param_3 < 5) {
    iVar7 = *(int *)(param_1 + 0x48);
    iVar8 = *(int *)(param_2 + 0xa0);
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_00106dcf,&DAT_00107aa9,"mmrm_sw_check_req_level",iVar8,param_3,
              *(undefined4 *)(param_1 + 0x4c));
    }
    uVar18 = *(uint *)(param_1 + 0x4c);
    uVar19 = (ulong)param_3;
    if (param_3 < uVar18) {
      uVar17 = (ulong)*(uint *)(param_1 + 0x10);
      uVar19 = (ulong)param_3;
      if (*(uint *)(param_1 + 0x10) != 0) {
        uVar19 = *(ulong *)(param_1 + 8);
        uVar25 = 0;
        do {
          uVar14 = uVar25;
          if ((((*(ulong *)(uVar19 + 0x80) != 0) && (*(ulong *)(uVar19 + 0x80) < 0xfffffffffffff001)
               ) && (*(long *)(uVar19 + 0x178) != 0)) && (*(int *)(uVar19 + 0xa0) != iVar8)) {
            uVar12 = *(uint *)(uVar19 + 0x180);
            if (uVar12 == uVar18) {
              uVar19 = (ulong)uVar18;
              goto LAB_00102f58;
            }
            uVar14 = uVar19;
            if (uVar12 <= param_3 || uVar18 <= uVar12) {
              uVar14 = uVar25;
            }
          }
          uVar17 = uVar17 - 1;
          uVar19 = uVar19 + 0x1b0;
          uVar25 = uVar14;
        } while (uVar17 != 0);
        uVar19 = (ulong)param_3;
        if ((uVar14 != 0) && (uVar19 = (ulong)param_3, uVar14 < 0xfffffffffffff001)) {
          uVar18 = *(uint *)(uVar14 + 0x180);
          if (*(uint *)(uVar14 + 0x180) <= param_3) {
            uVar18 = param_3;
          }
          uVar19 = (ulong)uVar18;
        }
      }
    }
LAB_00102f58:
    uVar18 = (uint)uVar19;
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_001061b2,&DAT_00107aa9,"mmrm_sw_check_req_level",uVar19);
      if (param_4 != 0) goto LAB_00102f68;
LAB_00103060:
      param_5 = 0;
      if (*(long *)(param_2 + 0x178) != 0) goto LAB_00102f94;
LAB_0010306c:
      iVar8 = 0;
      if (uVar18 != *(uint *)(param_1 + 0x4c)) goto LAB_0010307c;
LAB_00102fcc:
      uVar12 = param_5 - iVar8;
    }
    else {
      if (param_4 == 0) goto LAB_00103060;
LAB_00102f68:
      if ((4 < param_3) || (4 < uVar18)) goto LAB_00103aa0;
      param_5 = *(int *)(param_2 + (ulong)param_3 * 0x14 + uVar19 * 4 + 0x108) * param_5;
      if (*(long *)(param_2 + 0x178) == 0) goto LAB_0010306c;
LAB_00102f94:
      if (4 < *(uint *)(param_2 + 0x180)) {
LAB_00103aa0:
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x103aa4);
        (*pcVar11)();
      }
      uVar12 = *(uint *)(param_1 + 0x4c);
      if (4 < uVar12) goto LAB_00103aa0;
      iVar8 = *(int *)(param_2 + 0x18c) *
              *(int *)(param_2 + (ulong)*(uint *)(param_2 + 0x180) * 0x14 + (ulong)uVar12 * 4 +
                      0x108);
      if (uVar18 == uVar12) goto LAB_00102fcc;
LAB_0010307c:
      if (4 < uVar18) {
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00106172,&DAT_00106027,"mmrm_sw_calculate_total_current",uVar19);
        }
        goto LAB_00102e98;
      }
      uVar17 = (ulong)*(uint *)(param_1 + 0x10);
      if (*(uint *)(param_1 + 0x10) == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = 0;
        lVar20 = *(long *)(param_1 + 8);
        do {
          if ((((*(ulong *)(lVar20 + 0x80) != 0) && (*(ulong *)(lVar20 + 0x80) < 0xfffffffffffff001)
               ) && (*(long *)(lVar20 + 0x178) != 0)) && (lVar20 != param_2)) {
            if (4 < *(uint *)(lVar20 + 0x180)) goto LAB_00103aa0;
            iVar7 = iVar7 + *(int *)(lVar20 + 0x18c) *
                            *(int *)(lVar20 + uVar19 * 4 + 0x108 +
                                              (ulong)*(uint *)(lVar20 + 0x180) * 0x14);
          }
          uVar17 = uVar17 - 1;
          lVar20 = lVar20 + 0x1b0;
        } while (uVar17 != 0);
      }
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_00107819,&DAT_00107aa9,"mmrm_sw_calculate_total_current",iVar7);
      }
      uVar12 = 0;
      iVar7 = iVar7 + param_5;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_00106675,&DAT_00107aa9,"mmrm_sw_check_peak_current",
              *(undefined4 *)(param_2 + 0xa0),iVar7,param_5,iVar8,uVar12);
    }
    uVar21 = uVar12 + iVar7;
    if ((int)uVar21 < 1) {
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(uint *)(param_1 + 0x4c) = uVar18;
    }
    else {
      if (*(uint *)(param_1 + 0x44) <= uVar21) {
        if ((*(int *)(param_2 + 0x88) != 1) || (msm_mmrm_enable_throttle_feature == '\0')) {
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00107944,&DAT_00106027,"mmrm_sw_check_peak_current",
                    *(undefined4 *)(param_2 + 0xa0),param_2);
          }
          mmrm_sw_dump_enabled_client_info(param_1);
          goto LAB_00102e98;
        }
        local_78 = 0;
        local_70 = 0;
        local_88 = 0;
        local_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        uStack_a0 = 0;
        __init_swait_queue_head(&uStack_a0,"&x->wait",&init_completion___key);
        if (*(short *)(param_1 + 0x40) != 0) {
          uVar19 = 0;
          iVar8 = 0;
          lVar20 = 0x1c;
          do {
            if (uVar19 == 5) goto LAB_00103aa0;
            uVar17 = (ulong)*(ushort *)(param_1 + lVar20);
            lVar9 = *(long *)(param_1 + 8);
            uVar25 = lVar9 + uVar17 * 0x1b0;
            if ((uVar25 != 0) && (uVar25 < 0xfffffffffffff001)) {
              lVar24 = lVar9 + uVar17 * 0x1b0;
              if ((4 < *(uint *)(lVar24 + 0x180)) || (4 < *(uint *)(param_1 + 0x4c)))
              goto LAB_00103aa0;
              lVar15 = (ulong)*(uint *)(param_1 + 0x4c) * 4;
              uVar5 = *(uint *)(lVar24 + 0x108 + lVar15);
              uVar4 = *(uint *)(lVar9 + uVar17 * 0x1b0 + (ulong)*(uint *)(lVar24 + 0x180) * 0x14 +
                                lVar15 + 0x108);
              if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                _printk(&DAT_00106b9d,&DAT_00107aa9,"mmrm_sw_throttle_low_priority_client",
                        *(undefined4 *)(lVar9 + uVar17 * 0x1b0 + 0xa0),uVar25);
                if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) != 0) goto LAB_00103550;
LAB_001036e0:
                _printk(&DAT_0010770f,&DAT_00107aa9,"mmrm_sw_throttle_low_priority_client",uVar4,
                        uVar5);
                uVar13 = uVar4 - uVar5;
                if (uVar4 < uVar5 || uVar13 == 0) goto LAB_001034d0;
              }
              else {
                if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) goto LAB_001036e0;
LAB_00103550:
                uVar13 = uVar4 - uVar5;
                if (uVar4 < uVar5 || uVar13 == 0) goto LAB_001034d0;
              }
              if (uVar12 < uVar13) {
                if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                  _printk(&DAT_0010752d,&DAT_00107aa9,"mmrm_sw_throttle_low_priority_client",
                          *(undefined4 *)(lVar9 + uVar17 * 0x1b0 + 0xa0),uVar25);
                }
                if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                  _printk(&DAT_00107d6f,&DAT_00107aa9,"mmrm_sw_throttle_low_priority_client",uVar4,
                          uVar5,uVar12);
                }
                puVar1 = (uint *)(lVar24 + 0x180);
                local_88 = CONCAT44(local_88._4_4_,1);
                if (4 < *puVar1) goto LAB_00103aa0;
                lVar15 = lVar9 + uVar17 * 0x1b0;
                puVar2 = (undefined8 *)(lVar9 + uVar17 * 0x1b0 + 0xb8);
                local_80 = *(undefined8 *)(lVar15 + (ulong)*puVar1 * 8 + 0xb8);
                local_78 = *puVar2;
                local_70 = *(undefined8 *)(lVar15 + 0x90);
                lVar24 = ktime_get();
                pcVar11 = *(code **)(lVar15 + 0x98);
                if (pcVar11 != (code *)0x0) {
                  if (*(int *)(pcVar11 + -4) != 0x43125528) {
                    /* WARNING: Does not return */
                    pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1035e8);
                    (*pcVar11)();
                  }
                  iVar8 = (*pcVar11)(&local_88);
                }
                lVar15 = ktime_get();
                if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                  _printk(&DAT_00106e16,&DAT_00107aa9,"mmrm_sw_throttle_low_priority_client",
                          lVar15 - lVar24);
                  if (iVar8 == 0) goto LAB_00103614;
LAB_001034b4:
                  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_001034d0;
                  puVar10 = &DAT_00107f32;
                }
                else {
                  if (iVar8 != 0) goto LAB_001034b4;
LAB_00103614:
                  if ((100000000 < (ulong)(lVar15 - lVar24)) &&
                     (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
                    _printk(&DAT_00106296,&DAT_00106027,"mmrm_sw_throttle_low_priority_client",
                            lVar15 - lVar24,100000000);
                  }
                  lVar24 = lVar9 + uVar17 * 0x1b0;
                  if ((*(char *)(lVar24 + 0x184) != '\0') ||
                     (iVar8 = clk_set_rate(*(undefined8 *)(lVar9 + uVar17 * 0x1b0 + 0x80),*puVar2),
                     iVar8 == 0)) {
                    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                      _printk(&DAT_00106bc6,&DAT_00107aa9,"mmrm_sw_throttle_low_priority_client",
                              uVar25,*puVar2);
                    }
                    plVar22 = (long *)kmalloc_trace(_mutex_lock,0xdc0,0x20);
                    if ((plVar22 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar22)) {
                      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
                        _printk(&DAT_00106bf1,&DAT_00106027,"mmrm_sw_throttle_low_priority_client");
                      }
                      iVar8 = -0xc;
                      goto LAB_0010386c;
                    }
                    puVar23 = *(undefined8 **)(param_1 + 0x58);
                    *(int *)(plVar22 + 2) = (int)uVar19;
                    *(uint *)((long)plVar22 + 0x14) = uVar13;
                    *(uint *)(plVar22 + 3) = *puVar1;
                    uVar19 = __list_add_valid(plVar22,puVar23,param_1 + 0x50);
                    if ((uVar19 & 1) != 0) {
                      *(long **)(param_1 + 0x58) = plVar22;
                      *plVar22 = param_1 + 0x50;
                      plVar22[1] = (long)puVar23;
                      *puVar23 = plVar22;
                    }
                    uVar16 = *puVar2;
                    *(undefined1 *)(lVar24 + 0x184) = 0;
                    uVar21 = (uVar12 - uVar13) + iVar7;
                    *puVar1 = 0;
                    *(undefined8 *)(lVar9 + uVar17 * 0x1b0 + 0x178) = uVar16;
                    goto LAB_00103160;
                  }
                  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_001034d0;
                  puVar10 = &DAT_00106919;
                }
                _printk(puVar10,&DAT_00106027,"mmrm_sw_throttle_low_priority_client",
                        *(undefined4 *)(lVar9 + uVar17 * 0x1b0 + 0xa0));
              }
            }
LAB_001034d0:
            uVar19 = uVar19 + 1;
            lVar20 = lVar20 + 8;
          } while (uVar19 < *(ushort *)(param_1 + 0x40));
          if (iVar8 != 0) {
LAB_0010386c:
            if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
              _printk(&DAT_00105f16,&DAT_00106027,"mmrm_sw_check_peak_current");
            }
            mmrm_sw_dump_enabled_client_info(param_1);
            goto LAB_001033f8;
          }
        }
      }
LAB_00103160:
      *(uint *)(param_1 + 0x48) = uVar21;
      *(uint *)(param_1 + 0x4c) = uVar18;
      local_78 = 0;
      local_70 = 0;
      local_88 = 0;
      local_80 = 0;
      plVar22 = *(long **)(param_1 + 0x50);
      while (plVar6 = plVar22, plVar6 != (long *)(param_1 + 0x50)) {
        plVar22 = (long *)*plVar6;
        if (((plVar6 != (long *)0x0) && (plVar6 < (long *)0xfffffffffffff001)) &&
           ((uint)(*(int *)((long)plVar6 + 0x14) + *(int *)(param_1 + 0x48)) <=
            *(uint *)(param_1 + 0x44))) {
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
            _printk(&DAT_00107ae9,&DAT_00107aa9,"mmrm_reinstate_throttled_client",(int)plVar6[2]);
          }
          if (4 < *(uint *)(plVar6 + 2)) goto LAB_00103aa0;
          lVar20 = *(long *)(param_1 + 8);
          uVar17 = (ulong)*(ushort *)(param_1 + (ulong)*(uint *)(plVar6 + 2) * 8 + 0x1c);
          uVar19 = lVar20 + uVar17 * 0x1b0;
          if ((uVar19 != 0) && (uVar19 < 0xfffffffffffff001)) {
            if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
              _printk(&DAT_00107db1,&DAT_00107aa9,"mmrm_reinstate_throttled_client",uVar19,
                      *(undefined4 *)(lVar20 + uVar17 * 0x1b0 + 0xa0));
            }
            local_88 = CONCAT44(local_88._4_4_,1);
            local_80 = *(undefined8 *)(lVar20 + uVar17 * 0x1b0 + 0xb8);
            if (4 < *(uint *)(plVar6 + 3)) goto LAB_00103aa0;
            lVar24 = lVar20 + uVar17 * 0x1b0;
            local_78 = *(undefined8 *)(lVar24 + (ulong)*(uint *)(plVar6 + 3) * 8 + 0xb8);
            local_70 = *(undefined8 *)(lVar24 + 0x90);
            lVar9 = ktime_get();
            pcVar11 = *(code **)(lVar24 + 0x98);
            if (pcVar11 != (code *)0x0) {
              if (*(int *)(pcVar11 + -4) != 0x43125528) {
                    /* WARNING: Does not return */
                pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103294);
                (*pcVar11)();
              }
              iVar7 = (*pcVar11)(&local_88);
              lVar24 = ktime_get();
              if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
                _printk(&DAT_00106953,&DAT_00107aa9,"mmrm_reinstate_throttled_client",lVar24 - lVar9
                       );
              }
              if ((iVar7 != 0) && (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
                _printk(&DAT_00105f8f,&DAT_00106027,"mmrm_reinstate_throttled_client",
                        *(undefined4 *)(lVar20 + uVar17 * 0x1b0 + 0xa0));
              }
              if ((100000000 < (ulong)(lVar24 - lVar9)) &&
                 (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
                _printk(&DAT_00107171,&DAT_00106027,"mmrm_reinstate_throttled_client");
              }
            }
            uVar19 = __list_del_entry_valid(plVar6);
            if ((uVar19 & 1) != 0) {
              lVar20 = *plVar6;
              plVar3 = (long *)plVar6[1];
              *(long **)(lVar20 + 8) = plVar3;
              *plVar3 = lVar20;
            }
            *plVar6 = -0x2152ffffffffff00;
            plVar6[1] = -0x2152fffffffffede;
            kfree(plVar6);
          }
        }
      }
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_00105f57,&DAT_00107aa9,"mmrm_sw_check_peak_current",
              *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c));
    }
    iVar8 = 0;
  }
  else {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106172,&DAT_00106027,"mmrm_sw_check_req_level",param_3);
    }
LAB_00102e98:
    iVar8 = -0x16;
  }
LAB_001033f8:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// mmrm_sw_print_crm_table @ 00103aa8 size=248
// signature: undefined mmrm_sw_print_crm_table(void)
// callers: [mmrm_sw_clk_client_setval]
//------------------------------------------------------------

void mmrm_sw_print_crm_table(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 400) != '\0') {
    uVar2 = *(uint *)(param_1 + 0x1a0);
    uVar1 = msm_mmrm_debug;
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        if (((uVar1 ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_0010798e,&DAT_00107aa9,"mmrm_sw_print_crm_table",
                  *(undefined4 *)(param_1 + 0xa0),uVar3,
                  *(undefined8 *)(*(long *)(param_1 + 0x1a8) + (long)(int)uVar3 * 8));
          uVar2 = *(uint *)(param_1 + 0x1a0);
          uVar1 = msm_mmrm_debug;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    if (((uVar1 ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_00106e58,&DAT_00107aa9,"mmrm_sw_print_crm_table",*(undefined4 *)(param_1 + 0xa0),
              *(undefined4 *)(param_1 + 0x19c),*(undefined8 *)(param_1 + 0x178));
    }
  }
  return;
}



//------------------------------------------------------------
// mmrm_sw_dump_enabled_client_info @ 00103ba0 size=312
// signature: undefined mmrm_sw_dump_enabled_client_info(void)
// callers: [mmrm_sw_check_peak_current]
//------------------------------------------------------------

void mmrm_sw_dump_enabled_client_info(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  
  uVar4 = (ulong)*(uint *)(param_1 + 0x10);
  if (*(uint *)(param_1 + 0x10) != 0) {
    uVar6 = 0;
    lVar7 = 0x18c;
    do {
      lVar5 = *(long *)(param_1 + 8);
      lVar3 = *(long *)(lVar5 + lVar7 + -0x14);
      if ((lVar3 != 0) && (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
        uVar1 = *(uint *)(lVar5 + lVar7 + -0xc);
        if ((4 < uVar1) || (4 < *(uint *)(param_1 + 0x4c))) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103cd8);
          (*pcVar2)();
        }
        _printk(&DAT_001066cd,&DAT_00106027,"mmrm_sw_dump_enabled_client_info",
                *(undefined4 *)(lVar5 + lVar7 + -0xec),lVar3,uVar1,
                *(int *)(lVar5 + lVar7) *
                ((int *)(lVar5 + lVar7))
                [(ulong)uVar1 * 5 + ((ulong)*(uint *)(param_1 + 0x4c) - 0x21)]);
        uVar4 = (ulong)*(uint *)(param_1 + 0x10);
      }
      uVar6 = uVar6 + 1;
      lVar7 = lVar7 + 0x1b0;
    } while (uVar6 < uVar4);
  }
  if ((param_1 != -0x44) && (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
    _printk(&DAT_00107119,&DAT_00106027,"mmrm_sw_dump_enabled_client_info",
            *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c));
  }
  return;
}



//------------------------------------------------------------
// msm_mmrm_debugfs_info_read @ 00103cdc size=180
// signature: undefined msm_mmrm_debugfs_info_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
msm_mmrm_debugfs_info_read
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = kmalloc_trace(_scnprintf,0xdc0,0x1000);
  if (lVar1 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001063da,&DAT_00106027,"msm_mmrm_debugfs_info_read");
    }
    uVar2 = 0xfffffffffffffff4;
  }
  else {
    uVar2 = simple_read_from_buffer(param_2,param_3,param_4,lVar1,0);
    kfree(lVar1);
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_mmrm_debugfs_init @ 00103d94 size=404
// signature: undefined msm_mmrm_debugfs_init(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

ulong msm_mmrm_debugfs_init(void)

{
  ulong uVar1;
  long lVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  uVar1 = debugfs_create_dir("msm_mmrm",0);
  if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      puVar3 = &DAT_0010783e;
      puVar4 = &DAT_00106310;
LAB_00103f1c:
      _printk(puVar3,&DAT_00106027,"msm_mmrm_debugfs_init",puVar4);
    }
  }
  else {
    lVar2 = debugfs_create_file(&DAT_00106ea6,0x124,uVar1,&local_2c,&msm_mmrm_debugfs_info_fops);
    if (lVar2 != 0) {
      debugfs_create_u32("debug_level",0x1a4,uVar1,&msm_mmrm_debug);
      debugfs_create_u8("allow_multiple_register",0x1a4,uVar1,&msm_mmrm_allow_multiple_register);
      debugfs_create_u8("enable_throttle_feature",0x1a4,uVar1,&msm_mmrm_enable_throttle_feature);
      goto LAB_00103eb0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      puVar3 = &DAT_001061d6;
      puVar4 = &DAT_00106ea6;
      goto LAB_00103f1c;
    }
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107a17,&DAT_00106027,"msm_mmrm_debugfs_init");
  }
  uVar1 = 0;
LAB_00103eb0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_mmrm_debugfs_deinit @ 00103f2c size=28
// signature: undefined msm_mmrm_debugfs_deinit(void)
// callers: [msm_mmrm_remove, msm_mmrm_probe]
//------------------------------------------------------------

void msm_mmrm_debugfs_deinit(void)

{
  debugfs_remove();
  return;
}



//------------------------------------------------------------
// mmrm_get_platform_data @ 00103f4c size=48
// signature: undefined mmrm_get_platform_data(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

undefined8 mmrm_get_platform_data(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = of_match_node(&mmrm_dt_match,*(undefined8 *)(param_1 + 0x2e8));
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0xc0);
  }
  return uVar2;
}



//------------------------------------------------------------
// mmrm_init @ 00103f80 size=156
// signature: undefined mmrm_init(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

int mmrm_init(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = mmrm_get_clk_mgr_ops();
  if (iVar2 == 0) {
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x68) + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103fc8);
      (*pcVar1)();
    }
    iVar2 = (*(code *)**(undefined8 **)(param_1 + 0x68))(param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107051,&DAT_00106027,"mmrm_init");
  }
  return iVar2;
}



//------------------------------------------------------------
// mmrm_deinit @ 00104020 size=216
// signature: undefined mmrm_deinit(void)
// callers: [msm_mmrm_remove]
//------------------------------------------------------------

int mmrm_deinit(long param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x68) == 0)) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x68) + 8), pcVar2 == (code *)0x0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107e50,&DAT_00106027,"mmrm_deinit");
    }
    iVar1 = -0x16;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x79a1b161) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104064);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(*(undefined8 *)(param_1 + 0x60));
    if (iVar1 != 0) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107567,&DAT_00106027,"mmrm_deinit");
      }
      *(undefined8 *)(param_1 + 0x60) = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// mmrm_count_clk_clients_frm_dt @ 001040fc size=184
// signature: undefined mmrm_count_clk_clients_frm_dt(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

ulong mmrm_count_clk_clients_frm_dt(long param_1)

{
  long lVar1;
  ulong uVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  of_find_property(*(undefined8 *)(param_1 + 0x2f8),"mmrm-client-info",&local_2c);
  uVar2 = (ulong)local_2c;
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106c21,&DAT_00107aa9,"mmrm_count_clk_clients_frm_dt",uVar2 / 0x14);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2 / 0x14;
}



//------------------------------------------------------------
// mmrm_read_platform_resources @ 001041b8 size=1852
// signature: undefined mmrm_read_platform_resources(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

undefined8 mmrm_read_platform_resources(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined *puVar8;
  undefined4 uVar9;
  char *__s1;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  long lVar14;
  uint local_6c;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  if (*(long *)(param_1 + 0x2f8) == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107bfd,&DAT_00106027,"mmrm_read_platform_resources");
    }
    uVar11 = 0xffffffea;
    goto LAB_001048b0;
  }
  puVar12 = (undefined8 *)*param_2;
  param_2[2] = param_1;
  uVar13 = (ulong)*(uint *)(puVar12 + 2);
  if (0 < (int)*(uint *)(puVar12 + 2)) {
    __s1 = (char *)*puVar12;
    do {
      iVar5 = strcmp(__s1,"qcom,mmrm_clk_mgr_scheme");
      if (iVar5 == 0) {
        uVar9 = *(undefined4 *)(__s1 + 0x80);
        goto LAB_00104258;
      }
      __s1 = __s1 + 0x84;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
  }
  uVar9 = 0;
LAB_00104258:
  *(undefined4 *)(param_2 + 3) = uVar9;
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_00106214,&DAT_00107aa9,"mmrm_read_clk_pltfrm_rsrc_frm_drv_data");
  }
  *(undefined2 *)(param_2 + 6) = *(undefined2 *)((long)puVar12 + 0x14);
  if (((((*(short *)((long)puVar12 + 0x14) != 0) &&
        (*(int *)((long)param_2 + 0x1c) = ((int *)puVar12[1])[1] | *(int *)puVar12[1] << 0x10,
        1 < *(ushort *)((long)puVar12 + 0x14))) &&
       (*(uint *)(param_2 + 4) = *(uint *)(puVar12[1] + 0xc) | *(int *)(puVar12[1] + 8) << 0x10,
       2 < *(ushort *)((long)puVar12 + 0x14))) &&
      ((*(uint *)((long)param_2 + 0x24) =
             *(uint *)(puVar12[1] + 0x14) | *(int *)(puVar12[1] + 0x10) << 0x10,
       3 < *(ushort *)((long)puVar12 + 0x14) &&
       (*(uint *)(param_2 + 5) = *(uint *)(puVar12[1] + 0x1c) | *(int *)(puVar12[1] + 0x18) << 0x10,
       4 < *(ushort *)((long)puVar12 + 0x14))))) &&
     (*(uint *)((long)param_2 + 0x2c) =
           *(uint *)(puVar12[1] + 0x24) | *(int *)(puVar12[1] + 0x20) << 0x10,
     5 < *(ushort *)((long)puVar12 + 0x14))) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1048f4);
    (*pcVar4)();
  }
  lVar14 = param_2[2];
  uVar6 = of_property_read_string_helper(*(undefined8 *)(lVar14 + 0x2f8),"mm-rail-corners",0,0,0);
  if ((int)uVar6 < 1) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106a9f,&DAT_00106027,"mmrm_load_mm_rail_corner_table");
    }
    *(undefined4 *)(param_2 + 8) = 0;
LAB_00104484:
    if (*(int *)(param_2 + 3) == 1) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_0010724f,&DAT_00106027,"mmrm_read_clk_pltfrm_rsrc_frm_dt");
      }
      uVar11 = 0xffffffea;
    }
    else {
      if (*(int *)(param_2 + 3) != 0) {
LAB_001048ac:
        uVar11 = 0;
        goto LAB_001048b0;
      }
      lVar14 = param_2[2];
      local_6c = 0;
      iVar5 = of_property_read_variable_u32_array
                        (*(undefined8 *)(lVar14 + 0x2f8),"mmrm-peak-threshold",param_2 + 0xb,1,0);
      if (iVar5 < 0) {
        uVar11 = 0xffffffed;
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          puVar8 = &DAT_00106995;
LAB_00104714:
          _printk(puVar8,&DAT_00106027,"mmrm_load_nom_clk_src_table");
        }
      }
      else {
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_00107218,&DAT_00107aa9,"mmrm_load_nom_clk_src_table",
                  *(undefined4 *)(param_2 + 0xb));
        }
        of_find_property(*(undefined8 *)(lVar14 + 0x2f8),"mmrm-client-info",&local_6c);
        if ((local_6c < 0x14) || ((ulong)(long)(int)local_6c % 0x14 != 0)) {
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_0010787b,&DAT_00106027,"mmrm_load_nom_clk_src_table");
          }
          *(undefined4 *)(param_2 + 10) = 0;
          uVar11 = 0;
          goto LAB_001048b0;
        }
        lVar7 = devm_kmalloc(lVar14 + 0x10,(long)(int)local_6c,0xdc0);
        param_2[9] = lVar7;
        if (lVar7 != 0) {
          uVar13 = (ulong)(long)(int)local_6c / 0x14;
          uVar6 = msm_mmrm_debug ^ 0xffffffff;
          *(int *)(param_2 + 10) = (int)uVar13;
          if ((uVar6 & 0x10002) == 0) {
            _printk(&DAT_00106c21,&DAT_00107aa9,"mmrm_load_nom_clk_src_table",uVar13 & 0xffffffff);
          }
          if (0 < (int)uVar13) {
            lVar7 = 0;
            iVar5 = 4;
            do {
              lVar1 = param_2[9] + lVar7;
              of_property_read_u32_index
                        (*(undefined8 *)(lVar14 + 0x2f8),"mmrm-client-info",iVar5 + -4,lVar1);
              of_property_read_u32_index
                        (*(undefined8 *)(lVar14 + 0x2f8),"mmrm-client-info",iVar5 + -3,lVar1 + 4);
              of_property_read_u32_index
                        (*(undefined8 *)(lVar14 + 0x2f8),"mmrm-client-info",iVar5 + -2,lVar1 + 8);
              of_property_read_u32_index
                        (*(undefined8 *)(lVar14 + 0x2f8),"mmrm-client-info",iVar5 + -1,lVar1 + 0xc);
              of_property_read_u32_index
                        (*(undefined8 *)(lVar14 + 0x2f8),"mmrm-client-info",iVar5,lVar1 + 0x10);
              lVar7 = lVar7 + 0x14;
              iVar5 = iVar5 + 5;
            } while (((uVar13 & 0xffffffff) + (uVar13 & 0xffffffff) * 4) * 4 != lVar7);
            lVar14 = 0;
            uVar6 = msm_mmrm_debug;
            do {
              if (((uVar6 ^ 0xffffffff) & 0x10002) == 0) {
                puVar2 = (undefined4 *)(param_2[9] + lVar14);
                _printk(&DAT_00106371,&DAT_00107aa9,"mmrm_load_nom_clk_src_table",*puVar2,puVar2[1],
                        puVar2[2],puVar2[3]);
                uVar6 = msm_mmrm_debug;
              }
              lVar14 = lVar14 + 0x14;
            } while ((uVar13 & 0xffffffff) * 0x14 != lVar14);
          }
          goto LAB_001048ac;
        }
        uVar11 = 0xfffffff4;
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          puVar8 = &DAT_00106331;
          goto LAB_00104714;
        }
      }
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_001071e1,&DAT_00106027,"mmrm_read_clk_pltfrm_rsrc_frm_dt");
      }
      param_2[9] = 0;
      *(undefined4 *)(param_2 + 10) = 0;
    }
  }
  else {
    uVar13 = (ulong)uVar6;
    lVar7 = devm_kmalloc(lVar14 + 0x10,(uVar13 + (ulong)uVar6 * 2) * 8,0xdc0);
    param_2[7] = lVar7;
    uVar3 = msm_mmrm_debug;
    if (lVar7 != 0) {
      *(uint *)(param_2 + 8) = uVar6;
      if (((uVar3 ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_0010682e,&DAT_00107aa9,"mmrm_load_mm_rail_corner_table",uVar6);
      }
      uVar10 = 0;
      lVar7 = 0x10;
      do {
        lVar1 = param_2[7] + lVar7;
        of_property_read_string_helper
                  (*(undefined8 *)(lVar14 + 0x2f8),"mm-rail-corners",lVar1 + -0x10,1,
                   uVar10 & 0xffffffff);
        of_property_read_u32_index
                  (*(undefined8 *)(lVar14 + 0x2f8),"mm-rail-fact-volt",uVar10 & 0xffffffff,
                   lVar1 + -8);
        of_property_read_u32_index
                  (*(undefined8 *)(lVar14 + 0x2f8),"scaling-fact-dyn",uVar10 & 0xffffffff,lVar1 + -4
                  );
        of_property_read_u32_index
                  (*(undefined8 *)(lVar14 + 0x2f8),"scaling-fact-leak",uVar10 & 0xffffffff,lVar1);
        uVar10 = uVar10 + 1;
        lVar7 = lVar7 + 0x18;
      } while (uVar13 != uVar10);
      lVar14 = 0;
      uVar6 = msm_mmrm_debug;
      do {
        if (((uVar6 ^ 0xffffffff) & 0x10002) == 0) {
          puVar12 = (undefined8 *)(param_2[7] + lVar14);
          _printk(&DAT_00107e89,&DAT_00107aa9,"mmrm_load_mm_rail_corner_table",*puVar12,
                  *(undefined4 *)(puVar12 + 1),*(undefined4 *)((long)puVar12 + 0xc),
                  *(undefined4 *)(puVar12 + 2));
          uVar6 = msm_mmrm_debug;
        }
        lVar14 = lVar14 + 0x18;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
      goto LAB_00104484;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106764,&DAT_00106027,"mmrm_load_mm_rail_corner_table");
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) goto LAB_001047fc;
LAB_00104684:
      uVar11 = 0xfffffff4;
    }
    else {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_00104684;
LAB_001047fc:
      _printk(&DAT_0010672a,&DAT_00106027,"mmrm_read_clk_pltfrm_rsrc_frm_dt");
      uVar11 = 0xfffffff4;
    }
  }
  uVar6 = msm_mmrm_debug;
  param_2[7] = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  if (((uVar6 ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00106403,&DAT_00106027,"mmrm_read_platform_resources");
  }
LAB_001048b0:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// mmrm_free_platform_resources @ 001048f8 size=28
// signature: undefined mmrm_free_platform_resources(void)
// callers: [msm_mmrm_remove, msm_mmrm_probe]
//------------------------------------------------------------

undefined8 mmrm_free_platform_resources(long param_1)

{
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return 0;
}



//------------------------------------------------------------
// mmrm_client_check_scaling_supported @ 00104918 size=216
// signature: undefined mmrm_client_check_scaling_supported(void)
// callers: []
//------------------------------------------------------------

undefined8 mmrm_client_check_scaling_supported(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  if (drv_data == -0x205) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001077ea,&DAT_00106027,"mmrm_client_check_scaling_supported");
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) {
      return 0;
    }
    puVar1 = &DAT_00107c37;
    puVar2 = &DAT_00106027;
  }
  else {
    if ((param_1 != 0) || (*(char *)(drv_data + 8) != '\0')) {
      return 1;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) != 0) {
      return 0;
    }
    puVar1 = &DAT_00106441;
    puVar2 = &DAT_00107aa9;
  }
  _printk(puVar1,puVar2,"mmrm_client_check_scaling_supported");
  return 0;
}



//------------------------------------------------------------
// mmrm_client_register @ 001049f4 size=312
// signature: undefined mmrm_client_register(void)
// callers: []
//------------------------------------------------------------

long mmrm_client_register(int *param_1)

{
  long lVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if (param_1 == (int *)0x0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      puVar2 = &DAT_00106c51;
LAB_00104b14:
      _printk(puVar2,&DAT_00106027,"mmrm_client_register");
    }
  }
  else if (drv_data == -0x205) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      puVar2 = &DAT_001077ea;
      goto LAB_00104b14;
    }
  }
  else if (*param_1 == 0) {
    if (*(char *)(drv_data + 8) == '\0') {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) != 0) {
        return 0;
      }
      puVar2 = &DAT_00106441;
      puVar3 = &DAT_00107aa9;
      goto LAB_00104afc;
    }
    lVar1 = mmrm_clk_client_register(*(undefined8 *)(drv_data + 0x60),param_1);
    if (lVar1 != 0) {
      return lVar1;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      puVar2 = &DAT_00107f99;
      goto LAB_00104b14;
    }
  }
  else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107a33,&DAT_00106027,"mmrm_client_register");
  }
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) {
    return 0;
  }
  puVar2 = &DAT_00107c37;
  puVar3 = &DAT_00106027;
LAB_00104afc:
  _printk(puVar2,puVar3,"mmrm_client_register");
  return 0;
}



//------------------------------------------------------------
// mmrm_client_deregister @ 00104b30 size=368
// signature: undefined mmrm_client_deregister(void)
// callers: []
//------------------------------------------------------------

int mmrm_client_deregister(int *param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_1 == (int *)0x0) {
    iVar1 = -0x16;
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_00104bb0;
    puVar2 = &DAT_00107a60;
  }
  else if (drv_data == -0x205) {
    iVar1 = 0;
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_00104bb0;
    puVar2 = &DAT_001077ea;
  }
  else {
    if (*param_1 != 0) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107a33,&DAT_00106027,"mmrm_client_deregister");
      }
      return 0;
    }
    if (*(char *)(drv_data + 8) == '\0') {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
        _printk(&DAT_00106441,&DAT_00107aa9,"mmrm_client_deregister");
        return 0;
      }
      return 0;
    }
    iVar1 = mmrm_clk_client_deregister(*(undefined8 *)(drv_data + 0x60),param_1);
    if (iVar1 == 0) {
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) goto LAB_00104bb0;
    puVar2 = &DAT_00107092;
  }
  _printk(puVar2,&DAT_00106027,"mmrm_client_deregister");
LAB_00104bb0:
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_client_deregister",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// mmrm_client_set_value @ 00104ca4 size=428
// signature: undefined mmrm_client_set_value(void)
// callers: []
//------------------------------------------------------------

int mmrm_client_set_value(int *param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001069de,&DAT_00106027,"mmrm_client_set_value",param_1);
    }
    iVar1 = -0x16;
  }
  else {
    if (drv_data != -0x205) {
      if (*param_1 == 0) {
        if (*(char *)(drv_data + 8) != '\0') {
          iVar1 = mmrm_clk_client_setval(*(undefined8 *)(drv_data + 0x60),param_1,param_2,param_3);
          if (iVar1 == 0) {
            return 0;
          }
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_001073f3,&DAT_00106027,"mmrm_client_set_value");
          }
          goto LAB_00104d20;
        }
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_00106441,&DAT_00107aa9,"mmrm_client_set_value");
        }
      }
      else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107a33,&DAT_00106027,"mmrm_client_set_value");
      }
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001077ea,&DAT_00106027,"mmrm_client_set_value");
    }
    iVar1 = 0;
  }
LAB_00104d20:
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_client_set_value",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// mmrm_client_set_value_in_range @ 00104e54 size=432
// signature: undefined mmrm_client_set_value_in_range(void)
// callers: []
//------------------------------------------------------------

int mmrm_client_set_value_in_range(int *param_1,long param_2,long param_3)

{
  int iVar1;
  
  if (((param_1 == (int *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107428,&DAT_00106027,"mmrm_client_set_value_in_range",param_1);
    }
    iVar1 = -0x16;
  }
  else {
    if (drv_data != -0x205) {
      if (*param_1 == 0) {
        if (*(char *)(drv_data + 8) != '\0') {
          iVar1 = mmrm_clk_client_setval_inrange
                            (*(undefined8 *)(drv_data + 0x60),param_1,param_2,param_3);
          if (iVar1 == 0) {
            return 0;
          }
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_001073f3,&DAT_00106027,"mmrm_client_set_value_in_range");
          }
          goto LAB_00104ed8;
        }
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_00106441,&DAT_00107aa9,"mmrm_client_set_value_in_range");
        }
      }
      else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107a33,&DAT_00106027,"mmrm_client_set_value_in_range");
      }
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001077ea,&DAT_00106027,"mmrm_client_set_value_in_range");
    }
    iVar1 = 0;
  }
LAB_00104ed8:
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_client_set_value_in_range",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// mmrm_client_get_value @ 00105008 size=420
// signature: undefined mmrm_client_get_value(void)
// callers: []
//------------------------------------------------------------

int mmrm_client_get_value(int *param_1,long param_2)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106ebb,&DAT_00106027,"mmrm_client_get_value",param_1);
    }
    iVar1 = -0x16;
  }
  else {
    if (drv_data != -0x205) {
      if (*param_1 == 0) {
        if (*(char *)(drv_data + 8) != '\0') {
          iVar1 = mmrm_clk_client_getval(*(undefined8 *)(drv_data + 0x60),param_1,param_2);
          if (iVar1 == 0) {
            return 0;
          }
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00106473,&DAT_00106027,"mmrm_client_get_value");
          }
          goto LAB_00105084;
        }
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
          _printk(&DAT_00106441,&DAT_00107aa9,"mmrm_client_get_value");
        }
      }
      else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107a33,&DAT_00106027,"mmrm_client_get_value");
      }
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_001077ea,&DAT_00106027,"mmrm_client_get_value");
    }
    iVar1 = 0;
  }
LAB_00105084:
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
    _printk(&DAT_00107e1b,&DAT_00106027,"mmrm_client_get_value",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// mmrm_client_get_clk_count @ 001051b0 size=36
// signature: undefined mmrm_client_get_clk_count(void)
// callers: []
//------------------------------------------------------------

undefined4 mmrm_client_get_clk_count(void)

{
  if (drv_data == -0x205) {
    return 0;
  }
  return *(undefined4 *)(*(long *)(drv_data + 0x60) + 0x48);
}



//------------------------------------------------------------
// msm_mmrm_probe @ 001051d8 size=944
// signature: undefined msm_mmrm_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_mmrm_probe(long param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  char *pcVar5;
  
  if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
    _printk(&DAT_001067a3,&DAT_00107aa9,"msm_mmrm_probe");
  }
  if (param_1 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107df3,&DAT_00106027,"msm_mmrm_probe");
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) {
      return -0x16;
    }
    pcVar5 = "msm_mmrm_probe";
    iVar2 = -0x16;
  }
  else {
    iVar2 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,msm-mmrm");
    if (iVar2 == 0) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_001065a0,&DAT_00106027,"msm_mmrm_probe");
        return -0x16;
      }
      return -0x16;
    }
    drv_data = (long *)kmalloc_trace(_mutex_unlock,0xdc0,0x78);
    if (drv_data == (long *)0x0) {
      if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
        _printk(&DAT_00107c77,&DAT_00106027,"msm_mmrm_probe_init");
        iVar2 = -0xc;
      }
      else {
        iVar2 = -0xc;
      }
    }
    else {
      iVar2 = mmrm_count_clk_clients_frm_dt(param_1);
      bVar1 = (msm_mmrm_debug & 0x10002) == 0x10002;
      if (iVar2 == 0) {
        if (bVar1) {
          _printk(&DAT_00106c93,&DAT_00107aa9,"msm_mmrm_probe_init");
        }
        *(undefined1 *)(drv_data + 1) = 0;
        return 0;
      }
      if (bVar1) {
        _printk(&DAT_00106b1c,&DAT_00107aa9,"msm_mmrm_probe_init",iVar2);
      }
      *(undefined1 *)(drv_data + 1) = 1;
      lVar3 = mmrm_get_platform_data(param_1 + 0x10);
      *drv_data = lVar3;
      if (*drv_data == 0) {
        if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00106083,&DAT_00106027,"msm_mmrm_probe_init");
          iVar2 = -0x16;
        }
        else {
          iVar2 = -0x16;
        }
      }
      else {
        lVar3 = msm_mmrm_debugfs_init();
        plVar4 = drv_data;
        drv_data[0xe] = lVar3;
        if ((lVar3 == 0) && (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
          _printk(&DAT_0010790c,&DAT_00106027,"msm_mmrm_probe_init");
          plVar4 = drv_data;
        }
        *(long **)(param_1 + 0xa8) = plVar4;
        iVar2 = mmrm_read_platform_resources(param_1);
        if (iVar2 == 0) {
          iVar2 = mmrm_init(drv_data);
          if (iVar2 == 0) {
            iVar2 = sysfs_create_group(param_1 + 0x10,mmrm_fs_attrs_group);
            if ((iVar2 == 0) || (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0)) {
              return 0;
            }
            _printk(&DAT_00106d5a,&DAT_00106027,"msm_mmrm_probe_init");
            return 0;
          }
          if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
            _printk(&DAT_00105fe6,&DAT_00106027,"msm_mmrm_probe_init");
          }
          msm_mmrm_debugfs_deinit(drv_data[0xe]);
        }
        else if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
          _printk(&DAT_00107cb7,&DAT_00106027,"msm_mmrm_probe_init");
        }
        mmrm_free_platform_resources(drv_data);
      }
      kfree(drv_data);
      drv_data = (long *)0xfffffffffffffdfb;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) != 0) {
      return iVar2;
    }
    pcVar5 = "msm_mmrm_probe_init";
  }
  _printk(&DAT_00107e1b,&DAT_00106027,pcVar5,iVar2);
  return iVar2;
}



//------------------------------------------------------------
// msm_mmrm_remove @ 0010558c size=308
// signature: undefined msm_mmrm_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_mmrm_remove(long param_1)

{
  long lVar1;
  
  if (param_1 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107df3,&DAT_00106027,"msm_mmrm_remove");
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107e1b,&DAT_00106027,"msm_mmrm_remove",0xffffffea);
      return 0xffffffea;
    }
  }
  else {
    drv_data = *(long *)(param_1 + 0xa8);
    if (drv_data != 0) {
      if (*(char *)(drv_data + 8) != '\0') {
        sysfs_remove_group(param_1 + 0x10,mmrm_fs_attrs_group);
        msm_mmrm_debugfs_deinit(*(undefined8 *)(drv_data + 0x70));
        mmrm_deinit(drv_data);
        mmrm_free_platform_resources(drv_data);
      }
      lVar1 = drv_data;
      *(undefined8 *)(param_1 + 0xa8) = 0;
      kfree(lVar1);
      drv_data = 0xfffffffffffffdfb;
      return 0;
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00106b5f,&DAT_00106027,"msm_mmrm_remove");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// mmrm_sysfs_debug_get @ 001056c4 size=92
// signature: undefined mmrm_sysfs_debug_get(void)
// callers: []
//------------------------------------------------------------

long mmrm_sysfs_debug_get(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",msm_mmrm_debug);
  _printk(&DAT_001060b5,"mmrm_sysfs_debug_get",msm_mmrm_debug);
  return (long)iVar1;
}



//------------------------------------------------------------
// mmrm_sysfs_debug_set @ 00105724 size=156
// signature: undefined mmrm_sysfs_debug_set(void)
// callers: []
//------------------------------------------------------------

undefined8
mmrm_sysfs_debug_set(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (param_3 != 0) {
    uVar3 = 0x10;
    if ((*(char *)(param_3 + 1) + 0xa8U & 0xdf) != 0) {
      uVar3 = 10;
    }
    iVar2 = kstrtouint(param_3,uVar3,&local_2c);
    if (iVar2 != 0) goto LAB_00105790;
  }
  msm_mmrm_debug = local_2c;
LAB_00105790:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mmrm_sysfs_enable_throttle_get @ 001057c4 size=92
// signature: undefined mmrm_sysfs_enable_throttle_get(void)
// callers: []
//------------------------------------------------------------

long mmrm_sysfs_enable_throttle_get(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",msm_mmrm_enable_throttle_feature);
  _printk(&DAT_001060b5,"mmrm_sysfs_enable_throttle_get",msm_mmrm_enable_throttle_feature);
  return (long)iVar1;
}



//------------------------------------------------------------
// mmrm_sysfs_enable_throttle_set @ 00105824 size=156
// signature: undefined mmrm_sysfs_enable_throttle_set(void)
// callers: []
//------------------------------------------------------------

undefined8
mmrm_sysfs_enable_throttle_set
          (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (param_3 != 0) {
    uVar3 = 0x10;
    if ((*(char *)(param_3 + 1) + 0xa8U & 0xdf) != 0) {
      uVar3 = 10;
    }
    iVar2 = kstrtouint(param_3,uVar3,&local_2c);
    if (iVar2 != 0) goto LAB_00105890;
  }
  msm_mmrm_enable_throttle_feature = (undefined1)local_2c;
LAB_00105890:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mmrm_sysfs_allow_multiple_get @ 001058c4 size=92
// signature: undefined mmrm_sysfs_allow_multiple_get(void)
// callers: []
//------------------------------------------------------------

long mmrm_sysfs_allow_multiple_get(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"0x%x\n",msm_mmrm_allow_multiple_register);
  _printk(&DAT_001060b5,"mmrm_sysfs_allow_multiple_get",msm_mmrm_allow_multiple_register);
  return (long)iVar1;
}



//------------------------------------------------------------
// mmrm_sysfs_allow_multiple_set @ 00105924 size=156
// signature: undefined mmrm_sysfs_allow_multiple_set(void)
// callers: []
//------------------------------------------------------------

undefined8
mmrm_sysfs_allow_multiple_set(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (param_3 != 0) {
    uVar3 = 0x10;
    if ((*(char *)(param_3 + 1) + 0xa8U & 0xdf) != 0) {
      uVar3 = 10;
    }
    iVar2 = kstrtouint(param_3,uVar3,&local_2c);
    if (iVar2 != 0) goto LAB_00105990;
  }
  msm_mmrm_allow_multiple_register = (undefined1)local_2c;
LAB_00105990:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dump_enabled_client_info_show @ 001059c4 size=120
// signature: undefined dump_enabled_client_info_show(void)
// callers: []
//------------------------------------------------------------

long dump_enabled_client_info_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = mmrm_clk_print_enabled_client_info(*(undefined8 *)(drv_data + 0x60),param_3,0x1000);
  if ((iVar1 == 0) && (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0)) {
    _printk(&DAT_001079e6,&DAT_00106027,"dump_enabled_client_info_show");
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// dump_clk_res_info_show @ 00105a40 size=200
// signature: undefined dump_clk_res_info_show(void)
// callers: []
//------------------------------------------------------------

long dump_clk_res_info_show(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  lVar1 = drv_data;
  iVar2 = scnprintf(param_3,0x1000,"threshold: %d\n",*(undefined4 *)(drv_data + 0x58));
  iVar3 = 0x1000 - iVar2;
  if (*(int *)(lVar1 + 0x50) != 0 && 1 < iVar3) {
    puVar4 = *(undefined4 **)(lVar1 + 0x48);
    param_3 = param_3 + iVar2;
    uVar5 = 1;
    do {
      iVar2 = scnprintf(param_3,iVar3,"%d\t%d\t% 8d\t%d\t%d\n",*puVar4,puVar4[1],puVar4[2],puVar4[3]
                        ,puVar4[4]);
      iVar3 = iVar3 - iVar2;
      if (*(uint *)(lVar1 + 0x50) <= uVar5) break;
      param_3 = param_3 + iVar2;
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 5;
    } while (1 < iVar3);
  }
  return 0x1000 - (long)iVar3;
}



//------------------------------------------------------------
// init_module @ 00108754 size=216
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&msm_mmrm_driver,&__this_module);
  if (iVar1 == 0) {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10002) == 0) {
      _printk(&DAT_00106582,&DAT_00107aa9,"msm_mmrm_init");
    }
  }
  else {
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107754,&DAT_00106027,"msm_mmrm_init");
    }
    if (((msm_mmrm_debug ^ 0xffffffff) & 0x10001) == 0) {
      _printk(&DAT_00107e1b,&DAT_00106027,"msm_mmrm_init",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00108830 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_mmrm_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 0010a000 size=1
// signature: undefined _printk(void)
// callers: [mmrm_clk_print_enabled_client_info, mmrm_sw_get_req_level, mmrm_sw_print_client_data, mmrm_count_clk_clients_frm_dt, mmrm_client_check_scaling_supported, mmrm_client_get_value, mmrm_sw_update_curr, mmrm_read_platform_resources, mmrm_destroy_sw_clk_mgr, mmrm_sysfs_allow_multiple_get, mmrm_clk_client_register, mmrm_sw_print_crm_table, mmrm_sw_clk_client_deregister, mmrm_sw_clk_client_register, init_module, dump_enabled_client_info_show, mmrm_client_set_value_in_range, mmrm_init, mmrm_sw_check_peak_current, mmrm_client_deregister, mmrm_sw_update_freq, mmrm_sw_get_max_crm_rate, mmrm_sw_clk_client_getval, msm_mmrm_debugfs_info_read, mmrm_clk_client_deregister, msm_mmrm_debugfs_init, mmrm_get_clk_mgr_ops, mmrm_sysfs_enable_throttle_get, mmrm_client_set_value, msm_mmrm_probe, mmrm_sw_dump_enabled_client_info, mmrm_sw_clk_client_setval, mmrm_clk_client_setval_inrange, mmrm_clk_client_setval, mmrm_client_register, mmrm_sysfs_debug_get, mmrm_clk_client_getval, mmrm_deinit, mmrm_init_sw_clk_mgr, msm_mmrm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010a008 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mmrm_sw_clk_client_register, mmrm_clk_client_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mmrm_sysfs_allow_multiple_set, mmrm_sw_clk_client_setval, mmrm_count_clk_clients_frm_dt, msm_mmrm_debugfs_init, mmrm_sysfs_debug_set, mmrm_sw_check_peak_current, mmrm_read_platform_resources, mmrm_clk_client_register, mmrm_sysfs_enable_throttle_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a020 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mmrm_sw_clk_client_register, msm_mmrm_debugfs_info_read, mmrm_sw_check_peak_current, mmrm_init_sw_clk_mgr, msm_mmrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010a028 size=1
// signature: undefined __kmalloc(void)
// callers: [mmrm_sw_clk_client_register, mmrm_init_sw_clk_mgr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010a030 size=1
// signature: undefined __mutex_init(void)
// callers: [mmrm_init_sw_clk_mgr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010a038 size=1
// signature: undefined kfree(void)
// callers: [mmrm_sw_clk_client_deregister, mmrm_sw_clk_client_register, msm_mmrm_debugfs_info_read, mmrm_sw_check_peak_current, mmrm_destroy_sw_clk_mgr, mmrm_init_sw_clk_mgr, msm_mmrm_remove, msm_mmrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010a040 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mmrm_sw_check_peak_current, mmrm_destroy_sw_clk_mgr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a048 size=1
// signature: undefined mutex_lock(void)
// callers: [mmrm_sw_clk_client_setval, mmrm_sw_clk_client_deregister, mmrm_sw_clk_client_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a050 size=1
// signature: undefined mutex_unlock(void)
// callers: [mmrm_sw_clk_client_setval, mmrm_sw_clk_client_deregister, mmrm_sw_clk_client_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010a058 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [mmrm_sw_clk_client_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010a060 size=1
// signature: undefined fortify_panic(void)
// callers: [mmrm_sw_clk_client_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_clk_crm_set_rate @ 0010a068 size=1
// signature: undefined qcom_clk_crm_set_rate(void)
// callers: [mmrm_sw_clk_client_setval]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_clk_crm_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 0010a070 size=1
// signature: undefined clk_set_rate(void)
// callers: [mmrm_sw_clk_client_setval, mmrm_sw_check_peak_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010a078 size=1
// signature: undefined scnprintf(void)
// callers: [dump_clk_res_info_show, mmrm_sw_clk_print_enabled_client_info, mmrm_sysfs_debug_get, mmrm_sysfs_enable_throttle_get, mmrm_sysfs_allow_multiple_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_round_rate @ 0010a080 size=1
// signature: undefined clk_round_rate(void)
// callers: [mmrm_sw_update_freq, mmrm_sw_get_req_level]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_clk_get_voltage @ 0010a088 size=1
// signature: undefined qcom_clk_get_voltage(void)
// callers: [mmrm_sw_update_freq, mmrm_sw_get_req_level]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_clk_get_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0010a090 size=1
// signature: undefined ktime_get(void)
// callers: [mmrm_sw_check_peak_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010a098 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [mmrm_sw_check_peak_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010a0a0 size=1
// signature: undefined __list_add_valid(void)
// callers: [mmrm_sw_check_peak_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0010a0a8 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [msm_mmrm_debugfs_info_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010a0b0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [msm_mmrm_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0010a0b8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [msm_mmrm_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 0010a0c0 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [msm_mmrm_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u8 @ 0010a0c8 size=1
// signature: undefined debugfs_create_u8(void)
// callers: [msm_mmrm_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0010a0d0 size=1
// signature: undefined debugfs_remove(void)
// callers: [msm_mmrm_debugfs_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 0010a0e0 size=1
// signature: undefined of_match_node(void)
// callers: [mmrm_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010a0e8 size=1
// signature: undefined of_find_property(void)
// callers: [mmrm_count_clk_clients_frm_dt, mmrm_read_platform_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010a0f0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mmrm_read_platform_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0010a0f8 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [mmrm_read_platform_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010a100 size=1
// signature: undefined devm_kmalloc(void)
// callers: [mmrm_read_platform_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0010a108 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [mmrm_read_platform_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010a110 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mmrm_read_platform_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a118 size=1
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
// platform_driver_unregister @ 0010a120 size=1
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
// of_device_is_compatible @ 0010a128 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0010a130 size=1
// signature: undefined sysfs_create_group(void)
// callers: [msm_mmrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 0010a138 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [msm_mmrm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010a140 size=1
// signature: undefined kstrtouint(void)
// callers: [mmrm_sysfs_allow_multiple_set, mmrm_sysfs_debug_set, mmrm_sysfs_enable_throttle_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



