// Decompiled by Ghidra 12.2
// Program: wcd938x_slave_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd938x_swr_probe @ 00100464 size=252
// signature: undefined wcd938x_swr_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_swr_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  
  plVar1 = (long *)(param_1 + 0x48);
  plVar2 = (long *)devm_kmalloc(plVar1,0x30,0xdc0);
  if (plVar2 == (long *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    lVar5 = plVar2[1];
    *(long **)(param_1 + 0xe0) = plVar2;
    *plVar2 = param_1;
    if (lVar5 == 0) {
      lVar5 = *(long *)(param_1 + 0xb8);
      if (lVar5 == 0) {
        lVar5 = *plVar1;
      }
      uVar3 = debugfs_create_dir(lVar5,0);
      plVar2[1] = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        lVar5 = debugfs_create_file("swrslave_peek",0x8124,uVar3,param_1,codec_debug_read_ops);
        plVar2[2] = lVar5;
        lVar5 = debugfs_create_file("swrslave_poke",0x8124,plVar2[1],param_1,codec_debug_write_ops);
        plVar2[3] = lVar5;
        lVar5 = debugfs_create_file("swrslave_reg_dump",0x8124,plVar2[1],param_1,
                                    codec_debug_dump_ops);
        plVar2[4] = lVar5;
      }
    }
    uVar4 = component_add(plVar1,&wcd938x_slave_comp_ops);
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd938x_swr_remove @ 00100564 size=92
// signature: undefined wcd938x_swr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_swr_remove(long param_1)

{
  long lVar1;
  
  if ((param_1 != 0) && (lVar1 = *(long *)(param_1 + 0xe0), lVar1 != 0)) {
    debugfs_remove(*(undefined8 *)(lVar1 + 8));
    *(undefined8 *)(lVar1 + 8) = 0;
  }
  component_del(param_1 + 0x48,&wcd938x_slave_comp_ops);
  *(undefined8 *)(param_1 + 0xe0) = 0;
  swr_remove_device(param_1);
  return 0;
}



//------------------------------------------------------------
// codec_debug_read @ 001005c4 size=228
// signature: undefined codec_debug_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void codec_debug_read(long param_1,long param_2,long param_3,long *param_4)

{
  undefined8 uVar1;
  size_t sVar2;
  long lVar3;
  char local_40 [8];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar1 = 0xffffffffffffffea;
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  if ((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
     (((param_4 != (long *)0x0 && (*(long *)(param_1 + 0xd8) != 0)) &&
      ((lVar3 = *(long *)(*(long *)(param_1 + 0xd8) + 0xe0), lVar3 != 0 && (-1 < *param_4)))))) {
    snprintf(local_40,8,"0x%x\n",(uint)*(byte *)(lVar3 + 0x28));
    sVar2 = strnlen(local_40,7);
    if (7 < sVar2) {
      fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = simple_read_from_buffer(param_2,param_3,param_4,local_40,sVar2);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_peek_write @ 001006ac size=600
// signature: undefined codec_debug_peek_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void codec_debug_peek_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  long lVar9;
  long lVar10;
  char *local_78;
  ulong local_70 [2];
  undefined4 local_60;
  char local_58 [32];
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  uVar4 = 0xffffffffffffffea;
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  local_60 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  if (((((param_2 == 0) || (param_1 == 0)) || (param_3 == 0)) ||
      ((param_4 == (long *)0x0 || (lVar9 = *(long *)(param_1 + 0xd8), lVar9 == 0)))) ||
     ((lVar10 = *(long *)(lVar9 + 0xe0), lVar10 == 0 || ((0x1f < param_3 || (*param_4 < 0))))))
  goto LAB_0010088c;
  __check_object_size(local_58,param_3,0);
  puVar8 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
     (uVar4 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
    uVar4 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar5 = param_3;
  if (0x8000000000 - param_3 < uVar4) {
LAB_001008b8:
    memset(local_58 + (param_3 - uVar5),0,uVar5);
    if ((int)uVar5 != 0) {
      uVar4 = 0xfffffffffffffff2;
      goto LAB_0010088c;
    }
  }
  else {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      puVar8 = (undefined8 *)puVar8[1];
      uVar5 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar8;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    uVar5 = __arch_copy_from_user(puVar8,local_58,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    if (uVar5 != 0) goto LAB_001008b8;
  }
  if (0x1f < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x1008ec);
    (*pcVar2)();
  }
  local_78 = local_58;
  local_78[param_3] = '\0';
  pcVar6 = strsep(&local_78," ");
  if (pcVar6 != (char *)0x0) {
    uVar7 = 0x10;
    if ((pcVar6[1] + 0xa8U & 0xdf) != 0) {
      uVar7 = 10;
    }
    iVar3 = kstrtouint(pcVar6,uVar7,local_70);
    if (iVar3 == 0) {
      strsep(&local_78," ");
      if ((uint)local_70[0] < 0x200a) {
        swr_read(lVar9,*(undefined1 *)(lVar9 + 0x40),local_70[0] & 0xffffffff,lVar10 + 0x28,1);
        uVar4 = param_3;
        goto LAB_0010088c;
      }
    }
  }
  uVar4 = 0xffffffffffffffea;
LAB_0010088c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_open @ 00100920 size=16
// signature: undefined codec_debug_open(void)
// callers: []
//------------------------------------------------------------

undefined8 codec_debug_open(long param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x2b8);
  return 0;
}



//------------------------------------------------------------
// codec_debug_write @ 00100934 size=660
// signature: undefined codec_debug_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void codec_debug_write(long param_1,ulong param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  long lVar9;
  char *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  char local_58 [32];
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  uVar4 = 0xffffffffffffffea;
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  if ((((param_2 != 0) && (param_1 != 0)) && (param_4 != 0)) &&
     ((param_3 < 0x20 && (lVar9 = *(long *)(param_1 + 0xd8), lVar9 != 0)))) {
    __check_object_size(local_58,param_3,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar4 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar4 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar5 = param_3;
    if (uVar4 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      uVar5 = __arch_copy_from_user(puVar8,local_58,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
    }
    if ((uVar5 == 0) || (memset(local_58 + (param_3 - uVar5),0,uVar5), (int)uVar5 == 0)) {
      if (0x1f < param_3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x100bb0);
        (*pcVar2)();
      }
      local_78 = local_58;
      local_78[param_3] = '\0';
      pcVar6 = strsep(&local_78," ");
      if (pcVar6 != (char *)0x0) {
        uVar7 = 0x10;
        if ((pcVar6[1] + 0xa8U & 0xdf) != 0) {
          uVar7 = 10;
        }
        iVar3 = kstrtouint(pcVar6,uVar7,&local_70);
        if ((iVar3 == 0) && (pcVar6 = strsep(&local_78," "), pcVar6 != (char *)0x0)) {
          uVar7 = 0x10;
          if ((pcVar6[1] + 0xa8U & 0xdf) != 0) {
            uVar7 = 10;
          }
          iVar3 = kstrtouint(pcVar6,uVar7,(ulong)&local_70 | 4);
          if (iVar3 == 0) {
            strsep(&local_78," ");
            uVar4 = 0xffffffffffffffea;
            if (((uint)local_70 < 0x200a) && (local_70._4_4_ < 0x100)) {
              swr_write(lVar9,*(undefined1 *)(lVar9 + 0x40),local_70 & 0xffffffff,
                        (ulong)&local_70 | 4);
              uVar4 = param_3;
            }
            goto LAB_00100ac4;
          }
        }
      }
      uVar4 = 0xffffffffffffffea;
    }
    else {
      uVar4 = 0xfffffffffffffff2;
    }
  }
LAB_00100ac4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_dump @ 00100be4 size=888
// signature: undefined codec_debug_dump(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong codec_debug_dump(long param_1,long param_2,long param_3,long *param_4)

{
  bool bVar1;
  ulong uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  uint param3;
  ulong uVar10;
  long lVar11;
  uint local_84;
  char local_80 [24];
  long local_68;
  
  lVar9 = sp_el0;
  uVar10 = 0xffffffffffffffea;
  local_68 = *(long *)(lVar9 + 0x638);
  if ((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
     (((param_4 != (long *)0x0 && (lVar9 = *(long *)(param_1 + 0xd8), lVar9 != 0)) &&
      (-1 < *param_4)))) {
    uVar10 = 0;
    local_84 = 0;
    iVar6 = (int)*param_4;
    local_80[0x10] = '\0';
    local_80[0x11] = '\0';
    local_80[0x12] = '\0';
    local_80[0x13] = '\0';
    local_80[0] = '\0';
    local_80[1] = '\0';
    local_80[2] = '\0';
    local_80[3] = '\0';
    local_80[4] = '\0';
    local_80[5] = '\0';
    local_80[6] = '\0';
    local_80[7] = '\0';
    local_80[8] = '\0';
    local_80[9] = '\0';
    local_80[10] = '\0';
    local_80[0xb] = '\0';
    local_80[0xc] = '\0';
    local_80[0xd] = '\0';
    local_80[0xe] = '\0';
    local_80[0xf] = '\0';
    if (iVar6 < 0x17d78) {
      uVar10 = 0;
      puVar3 = (undefined8 *)sp_el0;
      param3 = iVar6 / 0xc + 0x40;
      do {
        if ((((0xdfc < param3 - 0x406 >> 1) && (0xcb < param3 - 0x339)) &&
            ((0xcb < param3 - 0x239 &&
             ((((0xcb < param3 - 0x139 && (6 < param3 - 0x429)) &&
               (6 < (param3 & 0xfffffeff) - 0x229)) &&
              ((6 < param3 - 0x129 && (0x19 < param3 - 0x406)))))))) &&
           (((0x19 < (param3 & 0xfffffefe) - 0x206 &&
             ((0x19 < param3 - 0x106 && (0xe < (param3 & 0xffffffef) - 0xe1)))) &&
            ((0xe < param3 - 0xd1 &&
             (((0x79 < param3 - 0x56 && (2 < param3 - 0x47)) && (4 < param3 - 0x4b)))))))) {
          swr_read(lVar9,*(undefined1 *)(lVar9 + 0x40),param3,&local_84,1);
          uVar5 = snprintf(local_80,0x14,"0x%.3x: 0x%.2x\n",param3,local_84 & 0xff);
          if (-1 < (int)uVar5) {
            lVar11 = (long)(int)uVar5;
            if (uVar10 + lVar11 < param_3 - 1U) {
              if (uVar5 < 0x15) {
                uVar2 = param_2 + uVar10;
                __check_object_size(local_80,lVar11,1);
                if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
                   (uVar8 = uVar2, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
                  uVar8 = uVar2 & (long)(uVar2 * 0x100) >> 8;
                }
                lVar7 = lVar11;
                if (uVar8 <= 0x8000000000U - lVar11) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar8 = daif;
                    if ((uVar8 & 0x80) == 0) {
                      uVar4 = daif;
                      daif = uVar4 | 0xc0;
                    }
                    uVar4 = ttbr1_el1;
                    ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar3[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar8;
                  }
                  lVar7 = __arch_copy_to_user(uVar2 & 0xff7fffffffffffff,local_80,lVar11);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar2 = daif;
                    if ((uVar2 & 0x80) == 0) {
                      uVar8 = daif;
                      daif = uVar8 | 0xc0;
                    }
                    uVar8 = ttbr1_el1;
                    ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar8 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar2;
                  }
                }
                if (lVar7 == 0) {
                  *param_4 = *param_4 + lVar11;
                  uVar10 = uVar10 + lVar11;
                  goto LAB_00100c94;
                }
              }
              else {
                __copy_overflow(0x14,lVar11);
              }
              iVar6 = ___ratelimit(wcd938x_swrslave_reg_show__rs,"wcd938x_swrslave_reg_show");
              if (iVar6 != 0) {
                _printk(&DAT_00101480,"wcd938x_swrslave_reg_show");
              }
              uVar10 = 0xfffffffffffffff2;
            }
          }
          break;
        }
LAB_00100c94:
        bVar1 = (int)param3 < 0x2009;
        param3 = param3 + 1;
      } while (bVar1);
    }
    *param_4 = 0x1806c;
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// wcd938x_slave_bind @ 00100f78 size=396
// signature: undefined wcd938x_slave_bind(void)
// callers: []
//------------------------------------------------------------

void wcd938x_slave_bind(long param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 local_2c [4];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c[0] = 0;
  if ((param_1 == 0) || (lVar4 = param_1 + -0x48, lVar4 == 0)) {
    iVar2 = ___ratelimit(wcd938x_slave_bind__rs,"wcd938x_slave_bind");
    if (iVar2 == 0) {
      uVar3 = 0xffffffea;
    }
    else {
      _printk(&DAT_0010149d,"wcd938x_slave_bind");
      uVar3 = 0xffffffea;
    }
  }
  else {
    usleep_range_state(100,0x6e,2);
    iVar2 = swr_get_logical_dev_num(lVar4,*(undefined8 *)(param_1 + 0x390),local_2c);
    bVar1 = iVar2 == 0;
    if (iVar2 != 0) {
      usleep_range_state(100,0x6e,2);
      iVar2 = swr_get_logical_dev_num(lVar4,*(undefined8 *)(param_1 + 0x390),local_2c);
      bVar1 = iVar2 == 0;
      if (iVar2 != 0) {
        usleep_range_state(100,0x6e,2);
        iVar2 = swr_get_logical_dev_num(lVar4,*(undefined8 *)(param_1 + 0x390),local_2c);
        bVar1 = iVar2 == 0;
        if (iVar2 != 0) {
          usleep_range_state(100,0x6e,2);
          iVar2 = swr_get_logical_dev_num(lVar4,*(undefined8 *)(param_1 + 0x390),local_2c);
          bVar1 = iVar2 == 0;
          if (iVar2 != 0) {
            usleep_range_state(100,0x6e,2);
            iVar2 = swr_get_logical_dev_num(lVar4,*(undefined8 *)(param_1 + 0x390),local_2c);
            bVar1 = iVar2 == 0;
          }
        }
      }
    }
    if (bVar1) {
      uVar3 = 0;
      *(undefined1 *)(param_1 + -8) = local_2c[0];
    }
    else {
      uVar3 = 0xfffffdfb;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_slave_unbind @ 00101108 size=108
// signature: undefined wcd938x_slave_unbind(void)
// callers: []
//------------------------------------------------------------

void wcd938x_slave_unbind(long param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = param_1 + -0x48;
  }
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0xe0) == 0)) &&
     (iVar2 = ___ratelimit(wcd938x_slave_unbind__rs,"wcd938x_slave_unbind"), iVar2 != 0)) {
    _dev_err(lVar1 + 0x48,"%s: wcd938x_slave is NULL\n","wcd938x_slave_unbind");
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001011f0 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  swr_driver_register(&wcd938x_slave_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101218 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  swr_driver_unregister(&wcd938x_slave_driver);
  return;
}



//------------------------------------------------------------
// swr_driver_register @ 00103000 size=1
// signature: undefined swr_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_unregister @ 00103008 size=1
// signature: undefined swr_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd938x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00103018 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [wcd938x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00103020 size=1
// signature: undefined debugfs_create_file(void)
// callers: [wcd938x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_add @ 00103028 size=1
// signature: undefined component_add(void)
// callers: [wcd938x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00103030 size=1
// signature: undefined debugfs_remove(void)
// callers: [wcd938x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_del @ 00103038 size=1
// signature: undefined component_del(void)
// callers: [wcd938x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_device @ 00103040 size=1
// signature: undefined swr_remove_device(void)
// callers: [wcd938x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103048 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [codec_debug_dump, codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00103050 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00103058 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [codec_debug_dump, wcd938x_slave_bind, codec_debug_write, codec_debug_read, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00103068 size=1
// signature: undefined fortify_panic(void)
// callers: [codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00103070 size=1
// signature: undefined __check_object_size(void)
// callers: [codec_debug_dump, codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00103088 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00103090 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00103098 size=1
// signature: undefined kstrtouint(void)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 001030a0 size=1
// signature: undefined swr_read(void)
// callers: [codec_debug_dump, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001030a8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_write @ 001030b8 size=1
// signature: undefined swr_write(void)
// callers: [codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001030c0 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [codec_debug_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __copy_overflow @ 001030c8 size=1
// signature: undefined __copy_overflow(void)
// callers: [codec_debug_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __copy_overflow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001030d0 size=1
// signature: undefined ___ratelimit(void)
// callers: [codec_debug_dump, wcd938x_slave_bind, wcd938x_slave_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030d8 size=1
// signature: undefined _printk(void)
// callers: [codec_debug_dump, wcd938x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001030e0 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd938x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 001030e8 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wcd938x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001030f0 size=1
// signature: undefined _dev_err(void)
// callers: [wcd938x_slave_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



