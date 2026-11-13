// Decompiled by Ghidra 12.2
// Program: wcd937x_slave_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd937x_swr_probe @ 0010049c size=40
// signature: undefined wcd937x_swr_probe(void)
// callers: []
//------------------------------------------------------------

void wcd937x_swr_probe(long param_1)

{
  component_add(param_1 + 0x48,&wcd937x_slave_comp_ops);
  return;
}



//------------------------------------------------------------
// wcd937x_swr_remove @ 001004c8 size=44
// signature: undefined wcd937x_swr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_swr_remove(long param_1)

{
  component_del(param_1 + 0x48,&wcd937x_slave_comp_ops);
  return 0;
}



//------------------------------------------------------------
// wcd937x_swr_up @ 001004f8 size=8
// signature: undefined wcd937x_swr_up(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_swr_up(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd937x_swr_down @ 00100504 size=8
// signature: undefined wcd937x_swr_down(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_swr_down(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd937x_swr_reset @ 00100510 size=8
// signature: undefined wcd937x_swr_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_swr_reset(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd937x_slave_bind @ 0010051c size=372
// signature: undefined wcd937x_slave_bind(void)
// callers: []
//------------------------------------------------------------

int wcd937x_slave_bind(long *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  undefined1 local_3c [4];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_3c[0] = 0;
  if ((param_1 == (long *)0x0) || (plVar6 = param_1 + -9, plVar6 == (long *)0x0)) {
    _dev_err(param_1,"%s: pdev is NULL\n","wcd937x_slave_bind");
    iVar1 = -0x16;
  }
  else {
    puVar2 = (undefined8 *)devm_kmalloc(param_1,0x30,0xdc0);
    if (puVar2 == (undefined8 *)0x0) {
      iVar1 = -0xc;
    }
    else {
      lVar5 = puVar2[1];
      param_1[0x13] = (long)puVar2;
      *puVar2 = plVar6;
      if (lVar5 == 0) {
        lVar5 = param_1[0xe];
        if (lVar5 == 0) {
          lVar5 = *param_1;
        }
        uVar3 = debugfs_create_dir(lVar5,0);
        puVar2[1] = uVar3;
        if (uVar3 < 0xfffffffffffff001) {
          uVar4 = debugfs_create_file("swrslave_peek",0x8124,uVar3,plVar6,codec_debug_read_ops);
          puVar2[2] = uVar4;
          uVar4 = debugfs_create_file("swrslave_poke",0x8124,puVar2[1],plVar6,codec_debug_write_ops)
          ;
          puVar2[3] = uVar4;
          uVar4 = debugfs_create_file("swrslave_reg_dump",0x8124,puVar2[1],plVar6,
                                      codec_debug_dump_ops);
          puVar2[4] = uVar4;
        }
      }
      iVar1 = swr_get_logical_dev_num(plVar6,param_1[0x72],local_3c);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + -1) = local_3c[0];
      }
      else {
        swr_remove_device(plVar6);
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd937x_slave_unbind @ 00100694 size=112
// signature: undefined wcd937x_slave_unbind(void)
// callers: []
//------------------------------------------------------------

void wcd937x_slave_unbind(long param_1)

{
  char *pcVar1;
  long lVar2;
  
  if ((param_1 == 0) || (param_1 == 0x48)) {
    pcVar1 = "%s: pdev is NULL\n";
  }
  else {
    lVar2 = *(long *)(param_1 + 0x98);
    if (lVar2 != 0) {
      debugfs_remove(*(undefined8 *)(lVar2 + 8));
      *(undefined8 *)(lVar2 + 8) = 0;
      *(undefined8 *)(param_1 + 0x98) = 0;
      return;
    }
    pcVar1 = "%s: wcd937x_slave is NULL\n";
  }
  _dev_err(param_1,pcVar1,"wcd937x_slave_unbind");
  return;
}



//------------------------------------------------------------
// codec_debug_read @ 00100708 size=228
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
// codec_debug_peek_write @ 001007f0 size=600
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
  goto LAB_001009d0;
  __check_object_size(local_58,param_3,0);
  puVar8 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
     (uVar4 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
    uVar4 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar5 = param_3;
  if (0x8000000000 - param_3 < uVar4) {
LAB_001009fc:
    memset(local_58 + (param_3 - uVar5),0,uVar5);
    if ((int)uVar5 != 0) {
      uVar4 = 0xfffffffffffffff2;
      goto LAB_001009d0;
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
    if (uVar5 != 0) goto LAB_001009fc;
  }
  if (0x1f < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x100a30);
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
        goto LAB_001009d0;
      }
    }
  }
  uVar4 = 0xffffffffffffffea;
LAB_001009d0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_open @ 00100a64 size=16
// signature: undefined codec_debug_open(void)
// callers: []
//------------------------------------------------------------

undefined8 codec_debug_open(long param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x2b8);
  return 0;
}



//------------------------------------------------------------
// codec_debug_write @ 00100a78 size=660
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
        pcVar2 = (code *)SoftwareBreakpoint(1,0x100cf4);
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
            goto LAB_00100c08;
          }
        }
      }
      uVar4 = 0xffffffffffffffea;
    }
    else {
      uVar4 = 0xfffffffffffffff2;
    }
  }
LAB_00100c08:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_dump @ 00100d28 size=896
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
  long lVar6;
  int iVar7;
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
  if (((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
      ((param_4 != (long *)0x0 && (lVar9 = *(long *)(param_1 + 0xd8), lVar9 != 0)))) &&
     (-1 < *param_4)) {
    uVar10 = 0;
    local_84 = 0;
    iVar7 = (int)*param_4;
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
    if (iVar7 < 0x17d78) {
      uVar10 = 0;
      puVar3 = (undefined8 *)sp_el0;
      param3 = iVar7 / 0xc + 0x40;
      do {
        if ((((((0x864 < param3 - 0xf36 >> 1) && (9 < param3 - 0xf26)) &&
              ((0x19 < param3 - 0xf06 &&
               (((0xaf9 < param3 - 0x406 && (0xcb < param3 - 0x339)) && (0xcb < param3 - 0x239))))))
             && ((0xcb < param3 - 0x139 && (6 < param3 - 0x429)))) &&
            ((6 < (param3 & 0xfffffeff) - 0x229 &&
             (((6 < param3 - 0x129 && (0x19 < param3 - 0x406)) &&
              ((0x19 < (param3 & 0xfffffefe) - 0x206 &&
               (((0x19 < param3 - 0x106 && (0xe < (param3 & 0xffffffef) - 0xe1)) &&
                (0xe < param3 - 0xd1)))))))))) &&
           (((0x79 < param3 - 0x56 && (2 < param3 - 0x47)) && (4 < param3 - 0x4b)))) {
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
                lVar6 = lVar11;
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
                  lVar6 = __arch_copy_to_user(uVar2 & 0xff7fffffffffffff,local_80,lVar11);
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
                if (lVar6 == 0) {
                  *param_4 = *param_4 + lVar11;
                  uVar10 = uVar10 + lVar11;
                  goto LAB_00100dd8;
                }
              }
              else {
                __copy_overflow(0x14,lVar11);
              }
              _printk(&DAT_00101350,"wcd937x_swrslave_reg_show");
              uVar10 = 0xfffffffffffffff2;
            }
          }
          break;
        }
LAB_00100dd8:
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
// init_module @ 0010113c size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  swr_driver_register(&wcd937x_slave_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101164 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  swr_driver_unregister(&wcd937x_slave_driver);
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
// component_add @ 00103010 size=1
// signature: undefined component_add(void)
// callers: [wcd937x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_del @ 00103018 size=1
// signature: undefined component_del(void)
// callers: [wcd937x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00103028 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00103030 size=1
// signature: undefined debugfs_create_file(void)
// callers: [wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 00103038 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_device @ 00103040 size=1
// signature: undefined swr_remove_device(void)
// callers: [wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103048 size=1
// signature: undefined _dev_err(void)
// callers: [wcd937x_slave_unbind, wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [codec_debug_dump, codec_debug_read, codec_debug_peek_write, codec_debug_write, wcd937x_slave_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00103058 size=1
// signature: undefined debugfs_remove(void)
// callers: [wcd937x_slave_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103060 size=1
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
// strnlen @ 00103068 size=1
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
// simple_read_from_buffer @ 00103070 size=1
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
// fortify_panic @ 00103078 size=1
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
// __check_object_size @ 00103080 size=1
// signature: undefined __check_object_size(void)
// callers: [codec_debug_dump, codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00103098 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 001030a0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001030a8 size=1
// signature: undefined kstrtouint(void)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 001030b0 size=1
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
// memset @ 001030b8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_write @ 001030c8 size=1
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
// __arch_copy_to_user @ 001030d0 size=1
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
// __copy_overflow @ 001030d8 size=1
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
// _printk @ 001030e0 size=1
// signature: undefined _printk(void)
// callers: [codec_debug_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



