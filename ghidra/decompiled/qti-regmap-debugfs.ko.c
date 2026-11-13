// Decompiled by Ghidra 12.2
// Program: qti-regmap-debugfs.ko
// Image base: 00100000

//------------------------------------------------------------
// regmap_qti_debugfs_register @ 001003bc size=36
// signature: undefined regmap_qti_debugfs_register(void)
// callers: []
//------------------------------------------------------------

undefined4 regmap_qti_debugfs_register(void)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = regmap_qti_debugfs_add();
  uVar1 = (undefined4)uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// regmap_qti_debugfs_add @ 001003e0 size=352
// signature: undefined regmap_qti_debugfs_add(void)
// callers: [regmap_qti_debugfs_register, devm_regmap_qti_debugfs_register]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * regmap_qti_debugfs_add(long param_1,undefined *param_2)

{
  undefined *puVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined8 *puVar4;
  
  if ((param_1 == 0) || (param_2 == (undefined *)0x0)) {
    _printk(&DAT_0010158e,"regmap_qti_debugfs_add");
    puVar4 = (undefined8 *)0xffffffffffffffea;
  }
  else {
    mutex_lock(&regmap_qti_debugfs_lock);
    ppuVar3 = &regmap_qti_debugfs_list;
    do {
      ppuVar3 = (undefined **)*ppuVar3;
      if (ppuVar3 == &regmap_qti_debugfs_list) {
        puVar4 = (undefined8 *)kmalloc_trace(_mutex_unlock,0xdc0,0x28);
        puVar1 = regmap_qti_debugfs_list;
        if (puVar4 == (undefined8 *)0x0) {
          puVar4 = (undefined8 *)0xfffffffffffffff4;
        }
        else {
          puVar4[2] = param_2;
          puVar4[3] = param_1;
          *(undefined4 *)((long)puVar4 + 0x24) = 1;
          uVar2 = __list_add_valid(puVar4,&regmap_qti_debugfs_list,puVar1);
          if ((uVar2 & 1) != 0) {
            *(undefined8 **)(puVar1 + 8) = puVar4;
            *puVar4 = puVar1;
            puVar4[1] = &regmap_qti_debugfs_list;
            regmap_qti_debugfs_list = (undefined *)puVar4;
          }
          debugfs_create_x32("address",0x180,*(undefined8 *)(param_2 + 0x110),puVar4 + 4);
          debugfs_create_u32("count",0x180,*(undefined8 *)(param_2 + 0x110),
                             (undefined4 *)((long)puVar4 + 0x24));
          debugfs_create_file_unsafe
                    (&DAT_001014e6,0x100,*(undefined8 *)(param_2 + 0x110),puVar4,&regmap_data_fops);
        }
        goto LAB_001004fc;
      }
    } while (ppuVar3[2] != param_2);
    _dev_err(param_1,"%s: qti debugfs files already registered for regmap\n",
             "regmap_qti_debugfs_add");
    puVar4 = (undefined8 *)0xffffffffffffffea;
LAB_001004fc:
    mutex_unlock(&regmap_qti_debugfs_lock);
  }
  return puVar4;
}



//------------------------------------------------------------
// regmap_qti_debugfs_unregister @ 00100544 size=136
// signature: undefined regmap_qti_debugfs_unregister(void)
// callers: []
//------------------------------------------------------------

void regmap_qti_debugfs_unregister(undefined *param_1)

{
  undefined **ppuVar1;
  
  if ((param_1 == (undefined *)0x0) || ((undefined *)0xfffffffffffff000 < param_1)) {
    _printk(&DAT_0010153b,"regmap_qti_debugfs_unregister");
  }
  else {
    mutex_lock(&regmap_qti_debugfs_lock);
    ppuVar1 = &regmap_qti_debugfs_list;
    do {
      ppuVar1 = (undefined **)*ppuVar1;
      if (ppuVar1 == &regmap_qti_debugfs_list) goto LAB_00100598;
    } while (ppuVar1[2] != param_1);
    regmap_qti_debugfs_remove();
LAB_00100598:
    mutex_unlock(&regmap_qti_debugfs_lock);
  }
  return;
}



//------------------------------------------------------------
// regmap_qti_debugfs_remove @ 001005cc size=196
// signature: undefined regmap_qti_debugfs_remove(void)
// callers: [devm_regmap_qti_debugfs_release, _devm_regmap_qti_debugfs_release, regmap_qti_debugfs_unregister]
//------------------------------------------------------------

void regmap_qti_debugfs_remove(long *param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  uVar3 = debugfs_lookup("address",*(undefined8 *)(param_1[2] + 0x110));
  dput();
  debugfs_remove(uVar3);
  uVar3 = debugfs_lookup("count",*(undefined8 *)(param_1[2] + 0x110));
  dput();
  debugfs_remove(uVar3);
  uVar3 = debugfs_lookup(&DAT_001014e6,*(undefined8 *)(param_1[2] + 0x110));
  dput();
  debugfs_remove(uVar3);
  uVar4 = __list_del_entry_valid(param_1);
  if ((uVar4 & 1) != 0) {
    lVar1 = *param_1;
    plVar2 = (long *)param_1[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *param_1 = -0x2152ffffffffff00;
  param_1[1] = -0x2152fffffffffede;
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 00100694 size=156
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: []
//------------------------------------------------------------

ulong devm_regmap_qti_debugfs_register(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  ulong uVar2;
  
  puVar1 = (ulong *)__devres_alloc_node(devm_regmap_qti_debugfs_release,8,0xcc0,0xffffffff,
                                        "devm_regmap_qti_debugfs_release");
  if (puVar1 == (ulong *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = regmap_qti_debugfs_add(param_1,param_2);
    if (uVar2 < 0xfffffffffffff001) {
      *puVar1 = uVar2;
      devres_add(param_1,puVar1);
      uVar2 = 0;
    }
    else {
      devres_free(puVar1);
    }
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_release @ 00100734 size=100
// signature: undefined devm_regmap_qti_debugfs_release(void)
// callers: []
//------------------------------------------------------------

void devm_regmap_qti_debugfs_release(undefined8 param_1,undefined8 *param_2)

{
  undefined **ppuVar1;
  
  mutex_lock(&regmap_qti_debugfs_lock);
  ppuVar1 = &regmap_qti_debugfs_list;
  do {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &regmap_qti_debugfs_list) goto LAB_0010077c;
  } while (ppuVar1 != (undefined **)*param_2);
  regmap_qti_debugfs_remove();
LAB_0010077c:
  mutex_unlock(&regmap_qti_debugfs_lock);
  return;
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_unregister @ 0010079c size=200
// signature: undefined devm_regmap_qti_debugfs_unregister(void)
// callers: []
//------------------------------------------------------------

void devm_regmap_qti_debugfs_unregister(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  if ((param_1 == (undefined *)0x0) || ((undefined *)0xfffffffffffff000 < param_1)) {
    _printk(&DAT_0010153b,"devm_regmap_qti_debugfs_unregister");
  }
  else {
    mutex_lock(&regmap_qti_debugfs_lock);
    ppuVar1 = (undefined **)regmap_qti_debugfs_list;
    if ((undefined **)regmap_qti_debugfs_list != &regmap_qti_debugfs_list) {
      do {
        ppuVar2 = (undefined **)*ppuVar1;
        if (ppuVar1[2] == param_1) {
          devres_release(ppuVar1[3],_devm_regmap_qti_debugfs_release,devm_regmap_qti_debugfs_match);
        }
        ppuVar1 = ppuVar2;
      } while (ppuVar2 != &regmap_qti_debugfs_list);
    }
    mutex_unlock(&regmap_qti_debugfs_lock);
  }
  return;
}



//------------------------------------------------------------
// _devm_regmap_qti_debugfs_release @ 00100868 size=64
// signature: undefined _devm_regmap_qti_debugfs_release(void)
// callers: []
//------------------------------------------------------------

void _devm_regmap_qti_debugfs_release(undefined8 param_1,undefined8 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = &regmap_qti_debugfs_list;
  do {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &regmap_qti_debugfs_list) {
      return;
    }
  } while (ppuVar1 != (undefined **)*param_2);
  regmap_qti_debugfs_remove();
  return;
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_match @ 001008ac size=32
// signature: undefined devm_regmap_qti_debugfs_match(void)
// callers: []
//------------------------------------------------------------

bool devm_regmap_qti_debugfs_match(undefined8 param_1,long *param_2,long param_3)

{
  code *pcVar1;
  
  if ((param_2 == (long *)0x0) || (*param_2 == 0)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1008cc);
    (*pcVar1)();
  }
  return *param_2 == param_3;
}



//------------------------------------------------------------
// regmap_data_read_file @ 001008d4 size=1348
// signature: undefined regmap_data_read_file(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong regmap_data_read_file(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  long *plVar15;
  long *plVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  long lVar21;
  long lVar22;
  uint uVar23;
  long lVar24;
  uint local_6c;
  long local_68;
  
  lVar19 = sp_el0;
  local_68 = *(long *)(lVar19 + 0x638);
  lVar22 = *(long *)(param_1 + 0xd8);
  lVar19 = *(long *)(lVar22 + 0x10);
  uVar23 = *(uint *)(lVar22 + 0x20);
  if (*(int *)(lVar19 + 0x128) == 0) {
    iVar8 = snprintf((char *)0x0,0,"%x",(ulong)*(uint *)(lVar19 + 0x170));
    *(int *)(lVar19 + 0x120) = iVar8;
    iVar9 = *(int *)(lVar19 + 0x80) * 2;
    *(int *)(lVar19 + 0x124) = iVar9;
    *(int *)(lVar19 + 0x128) = iVar8 + iVar9 + 3;
  }
  iVar9 = regmap_debugfs_generate_cache(lVar19);
  if (-1 < iVar9) {
    lVar24 = lVar19 + 0x140;
    mutex_lock(lVar24);
    for (puVar14 = *(undefined8 **)(lVar19 + 0x130); puVar14 != (undefined8 *)(lVar19 + 0x130);
        puVar14 = (undefined8 *)*puVar14) {
      if ((*(uint *)(puVar14 + 4) <= uVar23) && (uVar23 <= *(uint *)((long)puVar14 + 0x24))) {
        uVar5 = 0;
        if (*(uint *)(lVar19 + 0x21c) != 0) {
          uVar5 = (uVar23 - *(uint *)(puVar14 + 4)) / *(uint *)(lVar19 + 0x21c);
        }
        lVar19 = puVar14[2] + (ulong)(*(int *)(lVar19 + 0x128) * uVar5);
        mutex_unlock(lVar24);
        uVar20 = 0xffffffffffffffea;
        local_6c = 0;
        lVar24 = lVar19 + *param_4;
        *param_4 = lVar24;
        lVar21 = *(long *)(lVar22 + 0x10);
        iVar3 = *(int *)(lVar22 + 0x20);
        iVar8 = *(int *)(lVar21 + 0x21c);
        iVar9 = 0;
        if (*(int *)(lVar22 + 0x24) != 0) {
          iVar9 = *(int *)(lVar22 + 0x24) + -1;
        }
        if (iVar8 == 0) {
          iVar8 = 1;
        }
        if ((param_3 == 0) || (lVar24 < 0)) goto LAB_00100de4;
        if (0x3fffff < param_3) {
          param_3 = 0x400000;
        }
        lVar22 = __kmalloc(param_3,0xdc0);
        if (lVar22 == 0) {
          uVar20 = 0xfffffffffffffff4;
          goto LAB_00100de4;
        }
        if (*(int *)(lVar21 + 0x128) == 0) {
          iVar10 = snprintf((char *)0x0,0,"%x",(ulong)*(uint *)(lVar21 + 0x170));
          *(int *)(lVar21 + 0x120) = iVar10;
          iVar11 = *(int *)(lVar21 + 0x80) * 2;
          *(int *)(lVar21 + 0x124) = iVar11;
          *(int *)(lVar21 + 0x128) = iVar10 + iVar11 + 3;
        }
        lVar18 = *param_4;
        iVar11 = regmap_debugfs_generate_cache(lVar21);
        if (iVar11 < 0) {
          uVar23 = 0;
          goto LAB_00100b6c;
        }
        lVar1 = lVar21 + 0x140;
        mutex_lock(lVar1);
        plVar15 = *(long **)(lVar21 + 0x130);
        plVar2 = (long *)(lVar21 + 0x130);
        if (plVar15 == plVar2) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x100b54);
          (*pcVar7)();
        }
        if (plVar15 != plVar2) goto LAB_00100a94;
        uVar23 = 0;
        goto LAB_00100b64;
      }
    }
    mutex_unlock(lVar24);
    iVar9 = -0x16;
  }
  uVar20 = (ulong)iVar9;
  goto LAB_00100ad4;
LAB_00100cd8:
  if (uVar20 >> 0x1f != 0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x800,0x100e04);
    (*pcVar7)();
  }
  goto LAB_00100ce4;
  while (plVar15 = (long *)*plVar16, (long *)*plVar16 != plVar2) {
LAB_00100a94:
    plVar16 = plVar15;
    lVar17 = plVar16[2];
    lVar24 = plVar16[3];
    if (lVar17 <= lVar18 && lVar18 <= lVar24) {
      uVar23 = *(uint *)(lVar21 + 0x128);
      uVar5 = 0;
      if (uVar23 != 0) {
        uVar5 = (uint)((int)lVar18 - (int)lVar17) / uVar23;
      }
      lVar24 = lVar17 + (ulong)(uVar5 * uVar23);
      mutex_unlock(lVar1);
      uVar23 = (int)plVar16[4] + *(int *)(lVar21 + 0x21c) * uVar5;
      goto LAB_00100b6c;
    }
  }
  uVar23 = *(uint *)((long)plVar16 + 0x24);
LAB_00100b64:
  mutex_unlock(lVar1);
LAB_00100b6c:
  uVar20 = 0;
  if ((-1 < (int)uVar23) && (uVar5 = iVar3 + iVar8 * iVar9, uVar23 <= uVar5)) {
    uVar20 = 0;
    do {
      if (*param_4 <= lVar24) {
        if (param_3 < uVar20 + *(uint *)(lVar21 + 0x128)) goto LAB_00100cd8;
        snprintf((char *)(lVar22 + uVar20),param_3 - uVar20,"%.*x: ",*(int *)(lVar21 + 0x120),uVar23
                );
        lVar18 = uVar20 + (*(int *)(lVar21 + 0x120) + 2);
        iVar9 = regmap_read(lVar21,uVar23,&local_6c);
        if (iVar9 == 0) {
          snprintf((char *)(lVar22 + lVar18),param_3 - lVar18,"%.*x",
                   (ulong)*(uint *)(lVar21 + 0x124),(ulong)local_6c);
        }
        else {
          memset((void *)(lVar22 + lVar18),0x58,(ulong)*(uint *)(lVar21 + 0x124));
        }
        uVar12 = lVar18 + *(long *)(lVar21 + 0x80) * 2;
        if (param_3 <= uVar12) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(1,0x100e18);
          (*pcVar7)();
        }
        uVar20 = uVar12 + 1;
        *(undefined1 *)(lVar22 + uVar12) = 10;
      }
      uVar4 = *(uint *)(lVar21 + 0x128);
      uVar12 = regmap_printable(lVar21,*(int *)(lVar21 + 0x21c) + uVar23);
      if ((uVar12 & 1) == 0) {
        mutex_lock(lVar21 + 0x140);
        for (puVar14 = *(undefined8 **)(lVar21 + 0x130); puVar14 != (undefined8 *)(lVar21 + 0x130);
            puVar14 = (undefined8 *)*puVar14) {
          if ((uVar23 <= *(uint *)((long)puVar14 + 0x24)) && (uVar23 < *(uint *)(puVar14 + 4))) {
            uVar23 = *(uint *)(puVar14 + 4);
            goto LAB_00100cb8;
          }
        }
        uVar23 = 0xffffffea;
LAB_00100cb8:
        mutex_unlock(lVar21 + 0x140);
      }
      else {
        uVar23 = *(int *)(lVar21 + 0x21c) + uVar23;
      }
      if (((int)uVar23 < 0) || (lVar24 = lVar24 + (ulong)uVar4, uVar5 < uVar23)) goto LAB_00100cd8;
    } while( true );
  }
LAB_00100ce4:
  __check_object_size(lVar22,uVar20,1);
  puVar14 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar13 = uVar20;
  if (uVar12 <= 0x8000000000 - uVar20) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      puVar14 = (undefined8 *)puVar14[1];
      uVar13 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar14;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    uVar13 = __arch_copy_to_user(puVar14,param_2 & 0xff7fffffffffffff,lVar22,uVar20);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar6 = daif;
        daif = uVar6 | 0xc0;
      }
      uVar6 = ttbr1_el1;
      ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar6 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
  }
  if (uVar13 == 0) {
    *param_4 = *param_4 + uVar20;
  }
  else {
    uVar20 = 0xfffffffffffffff2;
  }
  kfree(lVar22);
LAB_00100de4:
  if (*param_4 < lVar19) {
    uVar20 = 0xffffffffffffffea;
  }
  else {
    *param_4 = *param_4 - lVar19;
  }
LAB_00100ad4:
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20;
}



//------------------------------------------------------------
// regmap_debugfs_generate_cache @ 00100e48 size=604
// signature: undefined regmap_debugfs_generate_cache(void)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 regmap_debugfs_generate_cache(long param_1)

{
  long *plVar1;
  long *plVar2;
  code *pcVar3;
  ulong uVar4;
  undefined8 uVar5;
  long *plVar6;
  undefined8 *puVar7;
  uint uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long lVar11;
  
  mutex_lock(param_1 + 0x140);
  plVar1 = (long *)(param_1 + 0x130);
  if (*(long **)(param_1 + 0x130) == plVar1) {
    uVar8 = 0;
    lVar11 = 0;
    uVar10 = 0;
    puVar7 = (undefined8 *)0x0;
    do {
      uVar4 = regmap_printable(param_1,uVar8);
      if ((uVar4 & 1) == 0) {
        if (puVar7 == (undefined8 *)0x0) {
          uVar10 = 0;
        }
        else {
          if ((((uVar10 < 0x18) || (uVar10 == 0x18)) || (puVar7[3] = lVar11 + -1, uVar10 < 0x24)) ||
             (uVar10 == 0x24)) goto LAB_001010a0;
          *(uint *)((long)puVar7 + 0x24) = uVar8 - *(int *)(param_1 + 0x21c);
          puVar9 = *(undefined8 **)(param_1 + 0x138);
          uVar4 = __list_add_valid(puVar7,puVar9,plVar1);
          if ((uVar4 & 1) == 0) {
            uVar10 = 0;
            puVar7 = (undefined8 *)0x0;
          }
          else {
            *(undefined8 **)(param_1 + 0x138) = puVar7;
            if ((uVar10 < 8) || (*puVar7 = plVar1, uVar10 == 8)) goto LAB_001010a0;
            uVar10 = 0;
            puVar7[1] = puVar9;
            *puVar9 = puVar7;
            puVar7 = (undefined8 *)0x0;
          }
        }
      }
      else {
        if (puVar7 == (undefined8 *)0x0) {
          puVar7 = (undefined8 *)kmalloc_trace(_mutex_unlock,0xdc0,0x28);
          if (puVar7 == (undefined8 *)0x0) {
            plVar6 = (long *)*plVar1;
            while (plVar6 != plVar1) {
              uVar10 = __list_del_entry_valid(plVar6);
              if ((uVar10 & 1) != 0) {
                lVar11 = *plVar6;
                plVar2 = (long *)plVar6[1];
                *(long **)(lVar11 + 8) = plVar2;
                *plVar2 = lVar11;
              }
              *plVar6 = -0x2152ffffffffff00;
              plVar6[1] = -0x2152fffffffffede;
              kfree(plVar6);
              plVar6 = (long *)*plVar1;
            }
            uVar5 = 0xfffffff4;
            goto LAB_00100e8c;
          }
          uVar10 = 0x28;
          puVar7[2] = lVar11;
          *(uint *)(puVar7 + 4) = uVar8;
        }
        lVar11 = lVar11 + (ulong)*(uint *)(param_1 + 0x128);
      }
      uVar8 = *(int *)(param_1 + 0x21c) + uVar8;
    } while (uVar8 <= *(uint *)(param_1 + 0x170));
    if (puVar7 != (undefined8 *)0x0) {
      if (((uVar10 < 0x18) || (uVar10 == 0x18)) ||
         ((puVar7[3] = lVar11 + -1, uVar10 < 0x24 || (uVar10 == 0x24)))) {
LAB_001010a0:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x1010a4);
        (*pcVar3)();
      }
      *(uint *)((long)puVar7 + 0x24) = uVar8 - *(int *)(param_1 + 0x21c);
      puVar9 = *(undefined8 **)(param_1 + 0x138);
      uVar4 = __list_add_valid(puVar7,puVar9,plVar1);
      if ((uVar4 & 1) != 0) {
        *(undefined8 **)(param_1 + 0x138) = puVar7;
        if ((uVar10 < 8) || (*puVar7 = plVar1, uVar10 == 8)) goto LAB_001010a0;
        uVar5 = 0;
        puVar7[1] = puVar9;
        *puVar9 = puVar7;
        goto LAB_00100e8c;
      }
    }
  }
  uVar5 = 0;
LAB_00100e8c:
  mutex_unlock(param_1 + 0x140);
  return uVar5;
}



//------------------------------------------------------------
// regmap_printable @ 001010a4 size=808
// signature: undefined regmap_printable(void)
// callers: [regmap_data_read_file, regmap_debugfs_generate_cache]
//------------------------------------------------------------

void regmap_printable(long param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (*(long *)(param_1 + 0x1d8) == 0) {
LAB_0010110c:
    local_2c = 0;
    if (((*(int *)(param_1 + 0x230) != 0) && (*(long *)(param_1 + 0x228) != 0)) &&
       ((*(uint *)(param_1 + 0x170) == 0 || (param_2 <= *(uint *)(param_1 + 0x170))))) {
      if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101150);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x30))(*(undefined8 *)(param_1 + 0x40));
      if (*(int *)(param_1 + 0x230) == 0) {
LAB_0010137c:
        if (*(int *)(*(code **)(param_1 + 0x38) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101398);
          (*pcVar2)();
        }
        (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40));
      }
      else {
        if (*(long *)(param_1 + 0x228) == 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10137c);
          (*pcVar2)();
        }
        if (*(long *)(param_1 + 0x88) == 0) {
          if ((*(long *)(param_1 + 0x1d8) != 0) &&
             ((*(uint *)(param_1 + 0x170) == 0 || (param_2 <= *(uint *)(param_1 + 0x170))))) {
            pcVar2 = *(code **)(param_1 + 0x180);
            if (pcVar2 == (code *)0x0) {
              if (*(long *)(param_1 + 0x1b0) == 0) goto LAB_0010116c;
              uVar4 = regmap_check_range_table(param_1,param_2);
            }
            else {
              if (*(int *)(pcVar2 + -4) != 0x510ef413) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101294);
                (*pcVar2)();
              }
              uVar4 = (*pcVar2)(*(undefined8 *)(param_1 + 0x50),param_2);
            }
            if ((uVar4 & 1) != 0) goto LAB_0010116c;
          }
        }
        else {
LAB_0010116c:
          pcVar2 = *(code **)(param_1 + 0x188);
          if (pcVar2 == (code *)0x0) {
            if (*(long *)(param_1 + 0x1b8) == 0) {
              if (*(long *)(param_1 + 0x228) == 0) goto LAB_0010137c;
              goto LAB_001012fc;
            }
            uVar4 = regmap_check_range_table(param_1,param_2);
          }
          else {
            if (*(int *)(pcVar2 + -4) != 0x510ef413) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101194);
              (*pcVar2)();
            }
            uVar4 = (*pcVar2)(*(undefined8 *)(param_1 + 0x50),param_2);
          }
          if ((uVar4 & 1) != 0) goto LAB_0010137c;
        }
LAB_001012fc:
        pcVar2 = *(code **)(*(long *)(param_1 + 0x228) + 0x28);
        if (*(int *)(pcVar2 + -4) != -0x2261fbf4) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101328);
          (*pcVar2)();
        }
        iVar3 = (*pcVar2)(param_1,param_2,&local_2c);
        if (*(int *)(*(code **)(param_1 + 0x38) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10134c);
          (*pcVar2)();
        }
        (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40));
        if (iVar3 == 0) goto LAB_00101354;
      }
    }
  }
  else {
    if (((*(uint *)(param_1 + 0x170) != 0) && (*(uint *)(param_1 + 0x170) < param_2)) ||
       (*(long *)(param_1 + 0x88) != 0)) {
LAB_001010ec:
      if (((*(long *)(param_1 + 0x1d8) == 0) ||
          ((*(uint *)(param_1 + 0x170) != 0 && (*(uint *)(param_1 + 0x170) < param_2)))) ||
         (*(long *)(param_1 + 0x88) != 0)) goto LAB_0010110c;
      pcVar2 = *(code **)(param_1 + 0x180);
      if (pcVar2 == (code *)0x0) {
        if (*(long *)(param_1 + 0x1b0) != 0) {
          uVar4 = regmap_check_range_table(param_1,param_2);
          goto joined_r0x001012d0;
        }
      }
      else {
        if (*(int *)(pcVar2 + -4) != 0x510ef413) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1011fc);
          (*pcVar2)();
        }
        uVar4 = (*pcVar2)(*(undefined8 *)(param_1 + 0x50),param_2);
joined_r0x001012d0:
        if ((uVar4 & 1) == 0) goto LAB_0010110c;
      }
LAB_00101354:
      uVar5 = 1;
      goto LAB_001013a0;
    }
    pcVar2 = *(code **)(param_1 + 0x180);
    if (pcVar2 == (code *)0x0) {
      if ((*(long *)(param_1 + 0x1b0) == 0) ||
         (uVar4 = regmap_check_range_table(param_1,param_2), (uVar4 & 1) != 0)) goto LAB_00101220;
      goto LAB_001010ec;
    }
    if (*(int *)(pcVar2 + -4) != 0x510ef413) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1011c8);
      (*pcVar2)();
    }
    uVar4 = (*pcVar2)(*(undefined8 *)(param_1 + 0x50),param_2);
    if ((uVar4 & 1) == 0) goto LAB_001010ec;
LAB_00101220:
    pcVar2 = *(code **)(param_1 + 400);
    if (pcVar2 == (code *)0x0) {
      if (*(long *)(param_1 + 0x1c0) == 0) goto LAB_001010ec;
      uVar4 = regmap_check_range_table(param_1,param_2);
    }
    else {
      if (*(int *)(pcVar2 + -4) != 0x510ef413) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101248);
        (*pcVar2)();
      }
      uVar4 = (*pcVar2)(*(undefined8 *)(param_1 + 0x50),param_2);
    }
    if ((uVar4 & 1) == 0) goto LAB_001010ec;
  }
  uVar5 = 0;
LAB_001013a0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [regmap_qti_debugfs_add, regmap_data_read_file, devm_regmap_qti_debugfs_release, devm_regmap_qti_debugfs_unregister, regmap_debugfs_generate_cache, regmap_qti_debugfs_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103008 size=1
// signature: undefined _dev_err(void)
// callers: [regmap_qti_debugfs_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103018 size=1
// signature: undefined kmalloc_trace(void)
// callers: [regmap_qti_debugfs_add, regmap_debugfs_generate_cache]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103020 size=1
// signature: undefined __list_add_valid(void)
// callers: [regmap_qti_debugfs_add, regmap_debugfs_generate_cache]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x32 @ 00103028 size=1
// signature: undefined debugfs_create_x32(void)
// callers: [regmap_qti_debugfs_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00103030 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [regmap_qti_debugfs_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 00103038 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [regmap_qti_debugfs_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103040 size=1
// signature: undefined mutex_unlock(void)
// callers: [regmap_qti_debugfs_add, regmap_data_read_file, devm_regmap_qti_debugfs_release, devm_regmap_qti_debugfs_unregister, regmap_debugfs_generate_cache, regmap_qti_debugfs_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103048 size=1
// signature: undefined _printk(void)
// callers: [regmap_qti_debugfs_add, devm_regmap_qti_debugfs_unregister, regmap_qti_debugfs_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_lookup @ 00103050 size=1
// signature: undefined debugfs_lookup(void)
// callers: [regmap_qti_debugfs_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dput @ 00103058 size=1
// signature: undefined dput(void)
// callers: [regmap_qti_debugfs_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00103060 size=1
// signature: undefined debugfs_remove(void)
// callers: [regmap_qti_debugfs_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103068 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [regmap_qti_debugfs_remove, regmap_debugfs_generate_cache]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103070 size=1
// signature: undefined kfree(void)
// callers: [regmap_data_read_file, regmap_qti_debugfs_remove, regmap_debugfs_generate_cache]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devres_alloc_node @ 00103078 size=1
// signature: undefined __devres_alloc_node(void)
// callers: [devm_regmap_qti_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devres_alloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_free @ 00103080 size=1
// signature: undefined devres_free(void)
// callers: [devm_regmap_qti_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_add @ 00103088 size=1
// signature: undefined devres_add(void)
// callers: [devm_regmap_qti_debugfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_release @ 00103090 size=1
// signature: undefined devres_release(void)
// callers: [devm_regmap_qti_debugfs_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103098 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001030a0 size=1
// signature: undefined __kmalloc(void)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 001030a8 size=1
// signature: undefined regmap_read(void)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001030b0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001030b8 size=1
// signature: undefined __check_object_size(void)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001030d0 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [regmap_data_read_file]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030d8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [regmap_data_read_file, regmap_printable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_check_range_table @ 001030e8 size=1
// signature: undefined regmap_check_range_table(void)
// callers: [regmap_printable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_check_range_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



