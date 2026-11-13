// Decompiled by Ghidra 12.2
// Program: smem.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_smem_bust_hwspin_lock_by_host @ 001004bc size=68
// signature: undefined qcom_smem_bust_hwspin_lock_by_host(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smem_bust_hwspin_lock_by_host(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 - 0x19U < 0xffffffe8) {
    return 0xffffffea;
  }
  uVar1 = qcom_hwspinlock_bust(*(undefined8 *)(__smem + 8),param_1 + 1);
  return uVar1;
}



//------------------------------------------------------------
// qcom_smem_alloc @ 00100504 size=396
// signature: undefined qcom_smem_alloc(void)
// callers: []
//------------------------------------------------------------

int qcom_smem_alloc(uint param_1,uint param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  int *piVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  if (__smem == (undefined8 *)0x0) {
    iVar3 = -0x205;
    goto LAB_001005cc;
  }
  uVar9 = (ulong)param_2;
  if (param_2 < 8) {
    _dev_err(*__smem,"Rejecting allocation of static entry %d\n",uVar9);
    iVar3 = -0x16;
    goto LAB_001005cc;
  }
  if (*(uint *)(__smem + 2) <= param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100684);
    (*pcVar2)();
  }
  iVar3 = __hwspin_lock_timeout(__smem[1],1000,1,&local_50);
  if (iVar3 != 0) goto LAB_001005cc;
  if (param_1 < 0x19) {
    plVar4 = __smem + (ulong)param_1 * 4 + 9;
    if (*plVar4 == 0) goto LAB_00100594;
LAB_001005a0:
    iVar3 = qcom_smem_alloc_private(__smem,plVar4,uVar9,param_3);
  }
  else {
LAB_00100594:
    plVar4 = __smem + 5;
    if (*plVar4 != 0) goto LAB_001005a0;
    lVar5 = __smem[0x6f];
    piVar6 = (int *)(lVar5 + uVar9 * 0x10 + 0xd0);
    if (*piVar6 == 0) {
      uVar8 = param_3 + 7U & 0xfffffffffffffff8;
      if (*(uint *)(lVar5 + 200) < uVar8) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100690);
        (*pcVar2)();
      }
      iVar3 = 0;
      lVar1 = lVar5 + uVar9 * 0x10;
      iVar7 = (int)uVar8;
      *(undefined4 *)(lVar1 + 0xd4) = *(undefined4 *)(lVar5 + 0xc4);
      *(int *)(lVar1 + 0xd8) = iVar7;
      DataSynchronizationBarrier(3,2,0);
      *piVar6 = 1;
      *(int *)(lVar5 + 0xc4) = *(int *)(lVar5 + 0xc4) + iVar7;
      *(int *)(lVar5 + 200) = *(int *)(lVar5 + 200) - iVar7;
    }
    else {
      iVar3 = -0x11;
    }
  }
  __hwspin_unlock(__smem[1],1,&local_50);
LAB_001005cc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qcom_smem_alloc_private @ 00100698 size=316
// signature: undefined qcom_smem_alloc_private(void)
// callers: [qcom_smem_alloc]
//------------------------------------------------------------

undefined8
qcom_smem_alloc_private(undefined8 *param_1,undefined8 *param_2,uint param_3,long param_4)

{
  bool bVar1;
  long lVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  code *pcVar6;
  undefined8 uVar7;
  short *psVar8;
  short *psVar9;
  ulong uVar10;
  
  psVar8 = (short *)*param_2;
  psVar3 = (short *)((long)psVar8 + (ulong)*(uint *)(psVar8 + 6));
  psVar4 = (short *)((long)psVar8 + (ulong)*(uint *)(psVar8 + 8));
  if ((psVar3 < psVar8 || psVar4 < psVar3) || (short *)((long)psVar8 + param_2[3]) < psVar4) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1006d4);
    (*pcVar6)();
  }
  psVar9 = psVar8 + 0x10;
  while( true ) {
    if ((psVar3 <= psVar9) || (psVar3 <= psVar9 + 8)) {
      if (psVar3 < psVar9) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1007dc);
        (*pcVar6)();
      }
      uVar10 = param_4 + 7U & 0xfffffffffffffff8;
      lVar2 = uVar10 + 0x10;
      if (psVar4 < (short *)((long)psVar9 + lVar2)) {
        _dev_err(*param_1,"Out of memory\n");
        uVar7 = 0xffffffe4;
      }
      else {
        psVar9[1] = (short)param_3;
        *(int *)(psVar9 + 2) = (int)uVar10;
        uVar7 = 0;
        *psVar9 = -0x5a5b;
        psVar9[4] = ((ushort)(param_4 + 7U) & 0xfff8) - (short)param_4;
        psVar9[5] = 0;
        DataSynchronizationBarrier(3,2,0);
        *(int *)(psVar8 + 6) = *(int *)(psVar8 + 6) + (int)lVar2;
      }
      return uVar7;
    }
    if (*psVar9 != -0x5a5b) {
      _dev_err(*param_1,"Found invalid canary in hosts %hu:%hu partition\n",psVar8[2],psVar8[3]);
      return 0xffffffea;
    }
    if ((ushort)psVar9[1] == param_3) break;
    psVar5 = (short *)((long)(psVar9 + 8) + (ulong)*(uint *)(psVar9 + 2) + (ulong)(ushort)psVar9[5])
    ;
    bVar1 = psVar5 <= psVar9;
    psVar9 = psVar5;
    if (bVar1) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x100730);
      (*pcVar6)();
    }
  }
  return 0xffffffef;
}



//------------------------------------------------------------
// qcom_smem_get @ 001007e4 size=392
// signature: undefined qcom_smem_get(void)
// callers: []
//------------------------------------------------------------

long qcom_smem_get(uint param_1,uint param_2,ulong *param_3)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  long *plVar5;
  ulong *puVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 local_40;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_40 = 0;
  if (__smem == 0) {
    lVar8 = -0x205;
    goto LAB_001008a4;
  }
  uVar9 = (ulong)param_2;
  if (*(uint *)(__smem + 0x10) <= param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100960);
    (*pcVar3)();
  }
  iVar4 = __hwspin_lock_timeout(*(undefined8 *)(__smem + 8),1000,1,&local_40);
  if (iVar4 != 0) {
    lVar8 = (long)iVar4;
    goto LAB_001008a4;
  }
  if (param_1 < 0x19) {
    plVar5 = (long *)(__smem + (ulong)param_1 * 0x20 + 0x48);
    if (*plVar5 == 0) goto LAB_00100874;
LAB_00100880:
    lVar8 = qcom_smem_get_private(__smem,plVar5,uVar9,param_3);
  }
  else {
LAB_00100874:
    plVar5 = (long *)(__smem + 0x28);
    if (*plVar5 != 0) goto LAB_00100880;
    lVar8 = *(long *)(__smem + 0x378);
    if (*(int *)(lVar8 + uVar9 * 0x10 + 0xd0) == 0) {
      lVar8 = -6;
    }
    else {
      uVar7 = (ulong)*(uint *)(__smem + 0x368);
      if (*(uint *)(__smem + 0x368) != 0) {
        uVar1 = *(uint *)(lVar8 + uVar9 * 0x10 + 0xdc) & 0xfffffffc;
        puVar6 = (ulong *)(__smem + 0x380);
        do {
          if ((uVar1 == 0) || (uVar1 == (uint)puVar6[-2])) {
            lVar8 = lVar8 + uVar9 * 0x10;
            uVar9 = (ulong)*(uint *)(lVar8 + 0xd4);
            uVar7 = (ulong)*(uint *)(lVar8 + 0xd8);
            if (*puVar6 < uVar9 + uVar7) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10096c);
              (*pcVar3)();
            }
            if (param_3 != (ulong *)0x0) {
              *param_3 = uVar7;
            }
            lVar8 = puVar6[-1] + uVar9;
            goto LAB_00100890;
          }
          puVar6 = puVar6 + 3;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      lVar8 = -2;
    }
  }
LAB_00100890:
  __hwspin_unlock(*(undefined8 *)(__smem + 8),1,&local_40);
LAB_001008a4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar8;
}



//------------------------------------------------------------
// qcom_smem_get_private @ 00100974 size=528
// signature: undefined qcom_smem_get_private(void)
// callers: [qcom_smem_get]
//------------------------------------------------------------

short * qcom_smem_get_private(undefined8 *param_1,undefined8 *param_2,uint param_3,ulong *param_4)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  short *psVar6;
  short *psVar7;
  ulong uVar8;
  short *psVar9;
  short *psVar10;
  ulong uVar11;
  ulong uVar12;
  short *psVar13;
  
  psVar7 = (short *)*param_2;
  uVar8 = param_2[3];
  psVar9 = (short *)((long)psVar7 + (ulong)*(uint *)(psVar7 + 6));
  psVar1 = (short *)((long)psVar7 + (ulong)*(uint *)(psVar7 + 8));
  psVar13 = (short *)((long)psVar7 + uVar8);
  if ((psVar9 < psVar7 || psVar1 < psVar9) || psVar13 < psVar1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100b88);
    (*pcVar4)();
  }
  psVar10 = psVar7 + 0x10;
  while ((psVar10 < psVar9 && (psVar6 = psVar10 + 8, psVar6 < psVar9))) {
    if (*psVar10 != -0x5a5b) goto LAB_00100b44;
    if ((ushort)psVar10[1] == param_3) {
      uVar2 = *(uint *)(psVar10 + 2);
      if (uVar8 <= uVar2) {
        return (short *)0xffffffffffffffea;
      }
      uVar3 = uVar2 - (ushort)psVar10[4];
      uVar8 = (ulong)uVar3;
      if (uVar2 < (ushort)psVar10[4] || uVar3 == 0) {
        return (short *)0xffffffffffffffea;
      }
      psVar6 = (short *)((long)psVar6 + (ulong)(ushort)psVar10[5]);
      if (((psVar6 < psVar10) || ((short *)((long)psVar6 + uVar8) < psVar6)) ||
         (psVar9 < (short *)((long)psVar6 + uVar8))) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100a78);
        (*pcVar4)();
      }
      goto LAB_00100af0;
    }
    psVar6 = (short *)((long)psVar6 + (ulong)*(uint *)(psVar10 + 2) + (ulong)(ushort)psVar10[5]);
    bVar5 = psVar6 <= psVar10;
    psVar10 = psVar6;
    if (bVar5) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100a00);
      (*pcVar4)();
    }
  }
  if (psVar9 < psVar10) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100b94);
    (*pcVar4)();
  }
  if (psVar1 == psVar13) {
    return (short *)0xfffffffffffffffe;
  }
  uVar11 = param_2[2] + 0xf & -param_2[2];
  psVar9 = (short *)((long)psVar7 + (*(uint *)(psVar7 + 4) - uVar11));
  if (((psVar9 < psVar1) || (psVar9 + 8 < psVar9)) || (psVar13 < psVar9 + 8)) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100a40);
    (*pcVar4)();
  }
  do {
    if (psVar9 <= psVar1) {
      if (psVar9 < psVar7) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100ba0);
        (*pcVar4)();
      }
      return (short *)0xfffffffffffffffe;
    }
    if (*psVar9 != -0x5a5b) {
LAB_00100b44:
      _dev_err(*param_1,"Found invalid canary in hosts %hu:%hu partition\n",psVar7[2],psVar7[3]);
      return (short *)0xffffffffffffffea;
    }
    uVar2 = *(uint *)(psVar9 + 2);
    uVar12 = (ulong)uVar2;
    if ((ushort)psVar9[1] == param_3) {
      if (uVar8 <= uVar12) {
        return (short *)0xffffffffffffffea;
      }
      if (uVar2 <= (ushort)psVar9[4]) {
        return (short *)0xffffffffffffffea;
      }
      psVar6 = (short *)((long)psVar9 - uVar12);
      if (psVar1 <= psVar6) {
        uVar8 = (ulong)(uVar2 - (ushort)psVar9[4]);
        if ((psVar6 <= (short *)((long)psVar6 + uVar8)) &&
           ((short *)((long)psVar6 + uVar8) <= psVar9)) {
LAB_00100af0:
          if (param_4 != (ulong *)0x0) {
            *param_4 = uVar8;
          }
          return psVar6;
        }
      }
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100b40);
      (*pcVar4)();
    }
    psVar13 = (short *)((long)psVar9 + (-uVar12 - uVar11));
    bVar5 = psVar9 <= psVar13;
    psVar9 = psVar13;
    if (bVar5) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100ad8);
      (*pcVar4)();
    }
  } while( true );
}



//------------------------------------------------------------
// qcom_smem_get_free_space @ 00100ba8 size=128
// signature: undefined qcom_smem_get_free_space(void)
// callers: []
//------------------------------------------------------------

ulong qcom_smem_get_free_space(uint param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  if (__smem == 0) {
    return 0xfffffdfb;
  }
  if (param_1 < 0x19) {
    lVar3 = __smem + (ulong)param_1 * 0x20;
    lVar4 = *(long *)(lVar3 + 0x48);
    if (lVar4 != 0) {
      uVar1 = *(int *)(lVar4 + 0x10) - *(int *)(lVar4 + 0xc);
      if (*(uint *)(lVar3 + 0x60) < uVar1) {
        return 0xffffffea;
      }
      return (ulong)uVar1;
    }
  }
  lVar3 = *(long *)(__smem + 0x28);
  if (lVar3 == 0) {
    uVar2 = (ulong)*(uint *)(*(long *)(__smem + 0x378) + 200);
    if (uVar2 <= *(ulong *)(__smem + 0x380)) {
      return uVar2;
    }
  }
  else {
    uVar1 = *(int *)(lVar3 + 0x10) - *(int *)(lVar3 + 0xc);
    if (uVar1 <= *(uint *)(__smem + 0x40)) {
      return (ulong)uVar1;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// qcom_smem_virt_to_phys @ 00100c2c size=204
// signature: undefined qcom_smem_virt_to_phys(void)
// callers: []
//------------------------------------------------------------

long qcom_smem_virt_to_phys(ulong param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  lVar2 = 0;
  do {
    uVar4 = *(ulong *)(__smem + lVar2 + 0x48);
    if ((uVar4 != 0) && (uVar4 <= param_1 && param_1 < uVar4 + *(long *)(__smem + lVar2 + 0x60))) {
      lVar3 = param_1 - uVar4;
      plVar1 = (long *)(__smem + lVar2 + 0x50);
      goto LAB_00100ce4;
    }
    lVar2 = lVar2 + 0x20;
  } while (lVar2 != 800);
  uVar4 = *(ulong *)(__smem + 0x28);
  if (((uVar4 != 0) && (uVar4 <= param_1)) && (param_1 < uVar4 + *(long *)(__smem + 0x40))) {
    lVar3 = param_1 - uVar4;
    plVar1 = (long *)(__smem + 0x30);
LAB_00100ce4:
    return lVar3 + *plVar1;
  }
  uVar4 = (ulong)*(uint *)(__smem + 0x368);
  if (*(uint *)(__smem + 0x368) != 0) {
    plVar1 = (long *)(__smem + 0x370);
    do {
      uVar5 = plVar1[1];
      if (((uVar5 != 0) && (uVar5 <= param_1)) && (param_1 < uVar5 + plVar1[2])) {
        lVar3 = param_1 - uVar5;
        goto LAB_00100ce4;
      }
      plVar1 = plVar1 + 3;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_smem_probe @ 00100cfc size=1212
// signature: undefined qcom_smem_probe(void)
// callers: [qcom_smem_restore]
//------------------------------------------------------------

int qcom_smem_probe(long param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  long *plVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  char *pcVar15;
  undefined8 local_120;
  long local_118;
  long local_110;
  undefined8 local_108;
  char *pcStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  long local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_120 = 0;
  lVar10 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,rpm-msg-ram",0);
  iVar7 = 1;
  if (lVar10 != 0) {
    iVar7 = 2;
  }
  uVar4 = iVar7 * 0x18;
  iVar1 = uVar4 + 0x370;
  plVar11 = (long *)__kmalloc(iVar1,0xdc0);
  if (plVar11 == (long *)0x0) {
    iVar7 = -0xc;
    goto LAB_001010ac;
  }
  lVar2 = param_1 + 0x10;
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  *plVar11 = lVar2;
  *(int *)(plVar11 + 0x6d) = iVar7;
  lVar13 = of_reserved_mem_lookup(uVar12);
  if (lVar13 == 0) {
    lVar13 = *plVar11;
    local_c8 = 0;
    uStack_c0 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    local_108 = 0;
    pcStack_100 = (char *)0x0;
    local_118 = 0;
    local_110 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    iVar7 = __of_parse_phandle_with_args
                      (*(undefined8 *)(lVar13 + 0x2e8),"memory-region",0,0,0,&local_b8);
    if ((iVar7 == 0) && (local_b8 != 0)) {
      iVar7 = of_address_to_resource(local_b8,0,&local_118);
      if (iVar7 == 0) {
        plVar11[0x6e] = local_118;
        if (uVar4 < 0x11) goto LAB_001011b0;
        plVar11[0x70] = (local_110 - local_118) + 1;
        lVar14 = local_118;
        goto joined_r0x00100ee4;
      }
      goto LAB_001010a4;
    }
    pcVar15 = "memory-region";
LAB_00101098:
    _dev_err(lVar13,"No %s specified\n",pcVar15);
LAB_001010a0:
    iVar7 = -0x16;
  }
  else {
    lVar14 = *(long *)(lVar13 + 0x20);
    plVar11[0x6e] = lVar14;
    if (uVar4 < 0x11) goto LAB_001011b0;
    plVar11[0x70] = *(long *)(lVar13 + 0x28);
joined_r0x00100ee4:
    if (lVar10 != 0) {
      lVar13 = *plVar11;
      local_c8 = 0;
      uStack_c0 = 0;
      local_d8 = 0;
      uStack_d0 = 0;
      local_e8 = 0;
      uStack_e0 = 0;
      local_f8 = 0;
      uStack_f0 = 0;
      local_108 = 0;
      pcStack_100 = (char *)0x0;
      local_118 = 0;
      local_110 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a8 = 0;
      uStack_a0 = 0;
      local_b8 = 0;
      uStack_b0 = 0;
      iVar7 = __of_parse_phandle_with_args
                        (*(undefined8 *)(lVar13 + 0x2e8),"qcom,rpm-msg-ram",0,0,0,&local_b8);
      if ((iVar7 != 0) || (local_b8 == 0)) {
        pcVar15 = "qcom,rpm-msg-ram";
        goto LAB_00101098;
      }
      iVar7 = of_address_to_resource(local_b8,0,&local_118);
      if (iVar7 != 0) goto LAB_001010a4;
      if ((uVar4 < 0x19) || (plVar11[0x71] = local_118, uVar4 < 0x29)) goto LAB_001011b0;
      lVar14 = plVar11[0x6e];
      plVar11[0x73] = (local_110 - local_118) + 1;
    }
    lVar13 = devm_ioremap_wc(*plVar11,lVar14,0x1000);
    if ((iVar1 == 0x378) || (plVar11[0x6f] = lVar13, uVar4 < 0x11)) goto LAB_001011b0;
    lVar13 = devm_ioremap_wc(*plVar11,(int)plVar11[0x6e] + (int)plVar11[0x70] + -0x1000,0x1000);
    plVar11[4] = lVar13;
    if (iVar1 == 0x378) goto LAB_001011b0;
    lVar14 = plVar11[0x6f];
    iVar7 = -0xc;
    if ((lVar14 != 0) && (lVar13 != 0)) {
      if (lVar10 != 0) {
        if (((uVar4 < 0x19) || (uVar4 < 0x29)) ||
           (lVar10 = devm_ioremap_wc(lVar2,plVar11[0x71],plVar11[0x73]), iVar1 == 0x390))
        goto LAB_001011b0;
        plVar11[0x72] = lVar10;
        if (lVar10 == 0) {
          _dev_err(lVar2,"failed to remap %pa\n",plVar11 + 0x71);
          goto LAB_001010a4;
        }
        if (iVar1 == 0x378) goto LAB_001011b0;
        lVar14 = plVar11[0x6f];
      }
      if ((*(int *)(lVar14 + 0xc0) != 1) || (*(int *)(lVar14 + 0xcc) != 0)) {
        _dev_err(lVar2,"SMEM is not initialized by SBL\n");
        goto LAB_001010a0;
      }
      iVar7 = of_hwspin_lock_get_id(*(undefined8 *)(param_1 + 0x2f8),0);
      if (iVar7 < 0) {
        if (iVar7 != -0x205) {
          _dev_err(lVar2,"failed to retrieve hwlock\n");
        }
      }
      else {
        lVar10 = hwspin_lock_request_specific(iVar7);
        plVar11[1] = lVar10;
        if (lVar10 == 0) {
          iVar7 = -6;
        }
        else {
          iVar7 = __hwspin_lock_timeout(lVar10,1000,1,&local_120);
          if (iVar7 == 0) {
            iVar7 = readl_relaxed(lVar14 + 200);
            iVar8 = readl_relaxed(lVar14 + 0xc4);
            __hwspin_unlock(plVar11[1],1,&local_120);
            if (iVar1 == 0x378) goto LAB_001011b0;
            uVar3 = *(uint *)(plVar11[0x6f] + 0x5c);
            devm_iounmap(*plVar11);
            uVar5 = uVar3 >> 0x10;
            if (uVar5 == 0xb) {
              if (uVar4 < 0x11) {
LAB_001011b0:
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(1,0x1011b4);
                (*pcVar6)();
              }
              plVar11[0x70] = (ulong)(uint)(iVar8 + iVar7);
              lVar10 = devm_ioremap_wc(*plVar11,(int)plVar11[0x6e]);
              if (iVar1 == 0x378) goto LAB_001011b0;
              uVar9 = 0x200;
              plVar11[0x6f] = lVar10;
            }
            else {
              if (uVar5 != 0xc) {
                _dev_err(lVar2,"Unsupported SMEM version 0x%x\n",uVar3);
                goto LAB_001010a0;
              }
              iVar7 = qcom_smem_set_global_partition(plVar11);
              if (iVar7 < 0) goto LAB_001010a4;
              uVar9 = qcom_smem_get_item_count(plVar11);
            }
            *(undefined4 *)(plVar11 + 2) = uVar9;
            iVar7 = qcom_smem_enumerate_partitions(plVar11);
            if ((-1 < iVar7) || (iVar7 == -2)) {
              uStack_f0 = 0;
              local_110 = 0;
              local_f8 = 0xffffffff;
              local_e8 = 0;
              uStack_e0 = 0;
              local_d8 = 0;
              uStack_d0 = 0;
              local_108 = 0;
              pcStack_100 = "qcom-socinfo";
              local_c8 = 0;
              uStack_c0 = 0;
              __smem = plVar11;
              local_118 = lVar2;
              lVar10 = platform_device_register_full(&local_118);
              iVar7 = 0;
              plVar11[3] = lVar10;
              goto LAB_001010ac;
            }
          }
        }
      }
    }
  }
LAB_001010a4:
  kfree(plVar11);
LAB_001010ac:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// qcom_smem_remove @ 001011bc size=76
// signature: undefined qcom_smem_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smem_remove(void)

{
  platform_device_unregister(*(undefined8 *)(__smem + 0x18));
  hwspin_lock_free(*(undefined8 *)(__smem + 8));
  kfree(__smem);
  __smem = 0;
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00101208 size=124
// signature: undefined readl_relaxed(void)
// callers: [qcom_smem_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101250,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_smem_set_global_partition @ 00101284 size=344
// signature: undefined qcom_smem_set_global_partition(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

ulong qcom_smem_set_global_partition(undefined8 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint *puVar7;
  
  if (param_1[5] == 0) {
    piVar5 = (int *)param_1[4];
    if (*piVar5 != 0x434f5424) {
      piVar6 = (int *)0xfffffffffffffffe;
      goto LAB_001013a8;
    }
    if (piVar5[1] != 1) {
      _dev_err(*param_1,"Unsupported partition header version %d\n");
      piVar6 = (int *)0xffffffffffffffea;
      goto LAB_001013a8;
    }
    piVar6 = piVar5;
    if ((int *)0xfffffffffffff000 < piVar5) goto LAB_001013a8;
    if (piVar5[2] != 0) {
      iVar4 = 0;
      do {
        puVar7 = (uint *)(piVar5 + (long)iVar4 * 0xc + 8);
        if ((((*puVar7 != 0) && (piVar5[(long)iVar4 * 0xc + 9] != 0)) &&
            ((short)piVar5[(long)iVar4 * 0xc + 0xb] == -2)) &&
           (*(short *)((long)piVar5 + (long)iVar4 * 0x30 + 0x2e) == -2)) {
          lVar1 = qcom_smem_partition_header(param_1,puVar7,0xfffe,0xfffe);
          if (lVar1 == 0) goto LAB_001013a4;
          param_1[5] = lVar1;
          piVar6 = (int *)0x0;
          param_1[6] = param_1[0x6e] + (ulong)*puVar7;
          param_1[8] = (ulong)(uint)piVar5[(long)iVar4 * 0xc + 9];
          param_1[7] = (ulong)(uint)piVar5[(long)iVar4 * 0xc + 0xc];
          goto LAB_001013a8;
        }
        iVar4 = iVar4 + 1;
      } while (piVar5[2] != iVar4);
    }
    uVar2 = *param_1;
    pcVar3 = "Missing entry for global partition\n";
  }
  else {
    uVar2 = *param_1;
    pcVar3 = "Already found the global partition\n";
  }
  _dev_err(uVar2,pcVar3);
LAB_001013a4:
  piVar6 = (int *)0xffffffea;
LAB_001013a8:
  return (ulong)piVar6 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_smem_get_item_count @ 001013dc size=140
// signature: undefined qcom_smem_get_item_count(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

undefined2 qcom_smem_get_item_count(undefined8 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[4];
  if (*piVar1 == 0x434f5424) {
    if (piVar1[1] == 1) {
      if (piVar1 == (int *)0x0) {
        return 0x200;
      }
      if ((int *)0xfffffffffffff000 < piVar1) {
        return 0x200;
      }
      if (piVar1[(ulong)(uint)piVar1[2] * 0xc + 8] == 0x49494953) {
        return (short)piVar1[(ulong)(uint)piVar1[2] * 0xc + 0xc];
      }
      return 0x200;
    }
    _dev_err(*param_1,"Unsupported partition header version %d\n");
  }
  return 0x200;
}



//------------------------------------------------------------
// qcom_smem_enumerate_partitions @ 00101468 size=376
// signature: undefined qcom_smem_enumerate_partitions(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

ulong qcom_smem_enumerate_partitions(undefined8 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  
  piVar9 = (int *)param_1[4];
  if (*piVar9 == 0x434f5424) {
    if (piVar9[1] == 1) {
      if (piVar9 < (int *)0xfffffffffffff001) {
        uVar8 = piVar9[2];
        if (uVar8 != 0) {
          uVar7 = 0;
          do {
            puVar10 = (uint *)(piVar9 + (long)(int)uVar7 * 0xc + 8);
            if ((*puVar10 != 0) && (piVar9[(long)(int)uVar7 * 0xc + 9] != 0)) {
              uVar1 = *(ushort *)((long)piVar9 + (long)(int)uVar7 * 0x30 + 0x2e);
              uVar6 = (ulong)uVar1;
              uVar2 = *(ushort *)(piVar9 + (long)(int)uVar7 * 0xc + 0xb);
              if ((uVar2 == 0) || (uVar6 = (ulong)(uint)uVar2, uVar1 == 0)) {
                if ((uint)uVar6 < 0x19) {
                  if (param_1[uVar6 * 4 + 9] == 0) {
                    lVar3 = qcom_smem_partition_header(param_1,puVar10,uVar2);
                    if (lVar3 != 0) {
                      param_1[uVar6 * 4 + 9] = lVar3;
                      param_1[uVar6 * 4 + 10] = param_1[0x6e] + (ulong)*puVar10;
                      param_1[uVar6 * 4 + 0xc] = (ulong)(uint)piVar9[(long)(int)uVar7 * 0xc + 9];
                      param_1[uVar6 * 4 + 0xb] = (ulong)(uint)piVar9[(long)(int)uVar7 * 0xc + 0xc];
                      uVar8 = piVar9[2];
                      goto LAB_001014d0;
                    }
                    piVar9 = (int *)0xffffffea;
                    goto LAB_00101578;
                  }
                  uVar4 = *param_1;
                  pcVar5 = "duplicate host %u\n";
                }
                else {
                  uVar4 = *param_1;
                  pcVar5 = "bad host %u\n";
                }
                _dev_err(uVar4,pcVar5);
                piVar9 = (int *)0xffffffea;
                goto LAB_00101578;
              }
            }
LAB_001014d0:
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar8);
        }
        piVar9 = (int *)0x0;
      }
    }
    else {
      _dev_err(*param_1,"Unsupported partition header version %d\n");
      piVar9 = (int *)0xffffffffffffffea;
    }
  }
  else {
    piVar9 = (int *)0xfffffffffffffffe;
  }
LAB_00101578:
  return (ulong)piVar9 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_smem_partition_header @ 001015e0 size=268
// signature: undefined qcom_smem_partition_header(void)
// callers: [qcom_smem_enumerate_partitions, qcom_smem_set_global_partition]
//------------------------------------------------------------

int * qcom_smem_partition_header(undefined8 *param_1,int *param_2,ushort param_3,ushort param_4)

{
  int *piVar1;
  undefined8 uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  
  piVar1 = (int *)devm_ioremap_wc(*param_1,*param_2 + *(int *)(param_1 + 0x6e),param_2[1]);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 == 0x54525024) {
      uVar5 = (uint)*(ushort *)(piVar1 + 1);
      if (*(ushort *)(piVar1 + 1) == param_3) {
        uVar5 = (uint)*(ushort *)((long)piVar1 + 6);
        if (*(ushort *)((long)piVar1 + 6) == param_4) {
          uVar4 = piVar1[2];
          uVar5 = param_2[1];
          if (uVar4 == uVar5) {
            if ((uint)piVar1[3] <= uVar4) {
              return piVar1;
            }
            uVar2 = *param_1;
            pcVar3 = "bad partition free uncached (%u > %u)\n";
            uVar5 = uVar4;
            uVar4 = piVar1[3];
          }
          else {
            uVar2 = *param_1;
            pcVar3 = "bad partition size (%u != %u)\n";
          }
        }
        else {
          uVar2 = *param_1;
          uVar4 = (uint)param_4;
          pcVar3 = "bad host1 (%hu != %hu)\n";
        }
      }
      else {
        uVar2 = *param_1;
        uVar4 = (uint)param_3;
        pcVar3 = "bad host0 (%hu != %hu)\n";
      }
      _dev_err(uVar2,pcVar3,uVar4,uVar5);
    }
    else {
      _dev_err(*param_1,"bad partition magic %4ph\n",piVar1);
    }
  }
  return (int *)0x0;
}



//------------------------------------------------------------
// qcom_smem_freeze @ 001016f0 size=76
// signature: undefined qcom_smem_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smem_freeze(void)

{
  platform_device_unregister(*(undefined8 *)(__smem + 0x18));
  hwspin_lock_free(*(undefined8 *)(__smem + 8));
  kfree(__smem);
  __smem = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_smem_restore @ 00101740 size=76
// signature: undefined qcom_smem_restore(void)
// callers: []
//------------------------------------------------------------

int qcom_smem_restore(long param_1)

{
  int iVar1;
  
  iVar1 = qcom_smem_probe(param_1 + -0x10);
  if (iVar1 != 0) {
    _dev_err(param_1,"Error getting SMEM information\n");
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00101820 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_smem_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101850 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_smem_driver);
  return;
}



//------------------------------------------------------------
// qcom_hwspinlock_bust @ 00103000 size=1
// signature: undefined qcom_hwspinlock_bust(void)
// callers: [qcom_smem_bust_hwspin_lock_by_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_hwspinlock_bust(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __hwspin_lock_timeout @ 00103008 size=1
// signature: undefined __hwspin_lock_timeout(void)
// callers: [qcom_smem_probe, qcom_smem_get, qcom_smem_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __hwspin_lock_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __hwspin_unlock @ 00103010 size=1
// signature: undefined __hwspin_unlock(void)
// callers: [qcom_smem_probe, qcom_smem_get, qcom_smem_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __hwspin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103018 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_smem_enumerate_partitions, qcom_smem_probe, qcom_smem_get_item_count, qcom_smem_set_global_partition, qcom_smem_restore, qcom_smem_alloc_private, qcom_smem_get_private, qcom_smem_alloc, qcom_smem_partition_header]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_smem_probe, qcom_smem_get, qcom_smem_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103028 size=1
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
// platform_driver_unregister @ 00103030 size=1
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
// of_find_property @ 00103038 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103040 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_lookup @ 00103048 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103050 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00103058 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_wc @ 00103060 size=1
// signature: undefined devm_ioremap_wc(void)
// callers: [qcom_smem_probe, qcom_smem_partition_header]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_wc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_hwspin_lock_get_id @ 00103068 size=1
// signature: undefined of_hwspin_lock_get_id(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_hwspin_lock_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hwspin_lock_request_specific @ 00103070 size=1
// signature: undefined hwspin_lock_request_specific(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hwspin_lock_request_specific(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_iounmap @ 00103078 size=1
// signature: undefined devm_iounmap(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103080 size=1
// signature: undefined kfree(void)
// callers: [qcom_smem_probe, qcom_smem_remove, qcom_smem_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_register_full @ 00103088 size=1
// signature: undefined platform_device_register_full(void)
// callers: [qcom_smem_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_register_full(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 00103090 size=1
// signature: undefined platform_device_unregister(void)
// callers: [qcom_smem_remove, qcom_smem_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hwspin_lock_free @ 00103098 size=1
// signature: undefined hwspin_lock_free(void)
// callers: [qcom_smem_remove, qcom_smem_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hwspin_lock_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001030a0 size=1
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
// log_post_read_mmio @ 001030a8 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



