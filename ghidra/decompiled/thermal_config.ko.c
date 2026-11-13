// Decompiled by Ghidra 12.2
// Program: thermal_config.ko
// Image base: 00100000

//------------------------------------------------------------
// buffer_overflow_check @ 001001dc size=76
// signature: undefined buffer_overflow_check(void)
// callers: []
//------------------------------------------------------------

undefined4 buffer_overflow_check(char *param_1,int param_2,int param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffea;
  if ((param_1 != (char *)0x0) && (param_2 < param_3)) {
    sVar1 = strlen(param_1);
    uVar2 = 0;
    if ((ulong)(long)param_3 <= sVar1) {
      uVar2 = 0xffffffea;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// thermal_dbgfs_config_read @ 0010022c size=2188
// signature: undefined thermal_dbgfs_config_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thermal_dbgfs_config_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  long *plVar2;
  undefined *puVar3;
  undefined *puVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  char *pcVar13;
  char *__s;
  size_t sVar14;
  char *__s_00;
  code *pcVar15;
  long *plVar16;
  long lVar17;
  ulong uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  long lVar24;
  undefined4 local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  uVar11 = thermal_zone_get_zone_by_name(&tzone_sensor_name);
  if (0xfffffffffffff000 < uVar11) {
    _printk(&DAT_00100df0,"thermal_config","thermal_dbgfs_config_read",&tzone_sensor_name,
            uVar11 & 0xffffffff);
    lVar12 = (long)(int)uVar11;
    goto LAB_00100a40;
  }
  lVar12 = kmalloc_trace(_debugfs_create_file,0xdc0,0x1000);
  if (lVar12 == 0) {
    lVar12 = -0xc;
    goto LAB_00100a40;
  }
  iVar6 = scnprintf(lVar12,0x1000,"%*s%s\n",0xfffffff1,"sensor");
  iVar7 = scnprintf(lVar12 + iVar6,0x1000 - (long)iVar6,"%*s%s\n",0xfffffff1,"algo_type",
                    *(undefined8 *)(uVar11 + 0x450));
  iVar7 = iVar7 + iVar6;
  pcVar13 = "disabled";
  if (*(int *)(uVar11 + 1000) != 0) {
    pcVar13 = "enabled";
  }
  iVar6 = scnprintf(lVar12 + iVar7,0x1000 - (long)iVar7,"%*s%s\n",0xfffffff1,&DAT_00100e7a,pcVar13);
  iVar6 = iVar6 + iVar7;
  uVar8 = jiffies_to_msecs(*(undefined8 *)(uVar11 + 0x418));
  iVar7 = scnprintf(lVar12 + iVar6,0x1000 - (long)iVar6,"%*s%d\n",0xfffffff1,"polling_delay",uVar8);
  iVar7 = iVar7 + iVar6;
  uVar8 = jiffies_to_msecs(*(undefined8 *)(uVar11 + 0x410));
  iVar6 = scnprintf(lVar12 + iVar7,0x1000 - (long)iVar7,"%*s%d\n",0xfffffff1,"passive_delay",uVar8);
  uVar22 = iVar6 + iVar7;
  if ((*(int *)(uVar11 + 0x400) == 0) || (*(long *)(*(long *)(uVar11 + 0x440) + 0x30) == 0)) {
    if (uVar22 < 0x1000) {
      *(undefined1 *)(lVar12 + (ulong)uVar22) = 0;
      iVar7 = simple_read_from_buffer(param_2,param_3,param_4,lVar12,(ulong)uVar22);
      kfree(lVar12);
      lVar12 = (long)iVar7;
      goto LAB_00100a40;
    }
LAB_00100a78:
    _printk(&DAT_00100f28,"thermal_config","thermal_dbgfs_config_read",uVar11 + 4);
LAB_00100564:
    uVar9 = 0xfffffff4;
  }
  else {
    lVar24 = (long)(*(int *)(uVar11 + 0x400) * 0xb);
    pcVar13 = (char *)__kmalloc(lVar24,0xdc0);
    __s = (char *)__kmalloc(lVar24,0xdc0);
    if ((__s == (char *)0x0) || (pcVar13 == (char *)0x0)) {
LAB_00100558:
      kfree(pcVar13);
      kfree(__s);
      goto LAB_00100564;
    }
    if (*(int *)(uVar11 + 0x400) < 1) {
      uVar19 = 0;
    }
    else {
      uVar19 = 0;
      uVar18 = 0;
      iVar7 = 0;
      do {
        local_6c = 0;
        pcVar15 = *(code **)(*(long *)(uVar11 + 0x440) + 0x30);
        if (*(int *)(pcVar15 + -4) != -0x14767f3) {
                    /* WARNING: Does not return */
          pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x100474);
          (*pcVar15)();
        }
        uVar9 = (*pcVar15)(uVar11,iVar7,&local_6c);
        if (uVar9 == 0) {
          iVar6 = scnprintf(pcVar13 + uVar18,lVar24 - uVar18,&DAT_00100f83,local_6c);
          uVar9 = iVar6 + (int)uVar18;
        }
        uVar18 = (ulong)uVar9;
        if ((int)uVar9 < 0) goto LAB_00100660;
        pcVar15 = *(code **)(*(long *)(uVar11 + 0x440) + 0x40);
        if (pcVar15 != (code *)0x0) {
          local_6c = 0;
          if (*(int *)(pcVar15 + -4) != -0x14767f3) {
                    /* WARNING: Does not return */
            pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x1004d8);
            (*pcVar15)();
          }
          uVar9 = (*pcVar15)(uVar11,iVar7,&local_6c);
          if (uVar9 == 0) {
            iVar6 = scnprintf(__s + uVar19,lVar24 - (ulong)uVar19,&DAT_00100f83,local_6c);
            uVar9 = iVar6 + uVar19;
          }
          uVar19 = uVar9;
          if ((int)uVar19 < 0) {
            uVar9 = uVar19;
            goto LAB_00100660;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(uVar11 + 0x400));
    }
    lVar24 = 0x1000 - (long)(int)uVar22;
    iVar7 = (int)lVar24;
    if (((int)uVar22 < iVar7) && (sVar14 = strlen(pcVar13), sVar14 < (ulong)(long)iVar7)) {
      iVar7 = scnprintf(lVar12 + (int)uVar22,lVar24,"%*s%s\n",0xfffffff1,"set_temp",pcVar13);
      uVar22 = iVar7 + uVar22;
      if (uVar19 == 0) {
        uVar9 = 0;
      }
      else {
        lVar24 = 0x1000 - (long)(int)uVar22;
        iVar7 = (int)lVar24;
        if (((int)uVar22 < iVar7) && (sVar14 = strlen(__s), sVar14 < (ulong)(long)iVar7)) {
          iVar7 = scnprintf(lVar12 + (int)uVar22,lVar24,"%*s%s\n",0xfffffff1,"clr_temp",__s);
          uVar9 = 0;
          uVar22 = iVar7 + uVar22;
        }
        else {
          uVar9 = 0xffffffea;
        }
      }
    }
    else {
      uVar9 = 0xffffffea;
    }
LAB_00100660:
    kfree(pcVar13);
    kfree(__s);
    if (-1 < (int)uVar9) {
      uVar9 = uVar22;
    }
    if (-1 < (int)uVar9) {
      lVar24 = uVar11 + 0x480;
      mutex_lock(lVar24);
      plVar16 = *(long **)(uVar11 + 0x460);
      plVar2 = (long *)(uVar11 + 0x460);
      if (plVar16 == plVar2) {
LAB_0010072c:
        mutex_unlock(lVar24);
      }
      else {
        iVar7 = 0;
        do {
          plVar1 = plVar16 + -0x13;
          plVar16 = (long *)*plVar16;
          if (*plVar1 != 0) {
            iVar7 = iVar7 + 1;
          }
        } while (plVar16 != plVar2);
        if (iVar7 == 0) goto LAB_0010072c;
        iVar7 = (*(int *)(uVar11 + 0x400) + iVar7) * 0x14;
        lVar17 = (long)iVar7;
        __s_00 = (char *)__kmalloc(lVar17,0xdc0);
        pcVar13 = (char *)__kmalloc(lVar17,0xdc0);
        __s = (char *)__kmalloc(lVar17,0xdc0);
        if ((__s_00 == (char *)0x0 || pcVar13 == (char *)0x0) || __s == (char *)0x0) {
          mutex_unlock(lVar24);
          kfree(__s_00);
          goto LAB_00100558;
        }
        if (0 < *(int *)(uVar11 + 0x400)) {
          iVar6 = 0;
          iVar23 = 0;
          iVar20 = 0;
          iVar21 = 0;
          do {
            plVar16 = (long *)*plVar2;
            if (plVar16 == plVar2) {
LAB_0010076c:
              iVar10 = scnprintf(__s_00 + iVar23,(long)(iVar7 - iVar23),&DAT_00100ece,&DAT_00100e88)
              ;
              iVar23 = iVar10 + iVar23;
              iVar10 = scnprintf(pcVar13 + iVar20,(long)(iVar7 - iVar20),&DAT_00100ece,&DAT_00100e88
                                );
              iVar20 = iVar10 + iVar20;
              iVar10 = scnprintf(__s + iVar21,(long)(iVar7 - iVar21),&DAT_00100ece,&DAT_00100e88);
              iVar21 = iVar10 + iVar21;
            }
            else {
              bVar5 = true;
              do {
                while ((plVar16[-0x13] == 0 || ((int)plVar16[-0x12] != iVar6))) {
                  plVar16 = (long *)*plVar16;
                  if (plVar16 == plVar2) {
                    if (bVar5) goto LAB_0010076c;
                    goto LAB_001007e0;
                  }
                }
                puVar3 = &DAT_00100ece;
                if (!bVar5) {
                  puVar3 = &DAT_00100f96;
                }
                puVar4 = &DAT_00100ed2;
                if (!bVar5) {
                  puVar4 = &UNK_00100eca;
                }
                iVar10 = scnprintf(__s_00 + iVar23,(long)(iVar7 - iVar23),puVar3,
                                   *(undefined8 *)(plVar16[-0x13] + 8));
                iVar23 = iVar10 + iVar23;
                iVar10 = scnprintf(pcVar13 + iVar20,(long)(iVar7 - iVar20),puVar4,plVar16[-0x11]);
                iVar20 = iVar10 + iVar20;
                iVar10 = scnprintf(__s + iVar21,(long)(iVar7 - iVar21),puVar4,plVar16[-0x10]);
                plVar16 = (long *)*plVar16;
                bVar5 = false;
                iVar21 = iVar10 + iVar21;
              } while (plVar16 != plVar2);
            }
LAB_001007e0:
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(uVar11 + 0x400));
        }
        mutex_unlock(lVar24);
        lVar24 = 0x1000 - (ulong)uVar9;
        iVar7 = (int)lVar24;
        if ((int)uVar9 < iVar7) {
          sVar14 = strlen(__s_00);
          if (sVar14 < (ulong)(long)iVar7) {
            iVar7 = scnprintf(lVar12 + (ulong)uVar9,lVar24,"%*s%s\n",0xfffffff2,"device",__s_00);
            iVar7 = iVar7 + uVar9;
            lVar24 = 0x1000 - (long)iVar7;
            iVar6 = (int)lVar24;
            if ((iVar7 < iVar6) && (sVar14 = strlen(pcVar13), sVar14 < (ulong)(long)iVar6)) {
              iVar6 = scnprintf(lVar12 + iVar7,lVar24,"%*s%s\n",0xfffffff2,"upper_limit",pcVar13);
              iVar6 = iVar6 + iVar7;
              lVar24 = 0x1000 - (long)iVar6;
              iVar7 = (int)lVar24;
              if ((iVar6 < iVar7) && (sVar14 = strlen(__s), sVar14 < (ulong)(long)iVar7)) {
                iVar7 = scnprintf(lVar12 + iVar6,lVar24,"%*s%s\n",0xfffffff2,"lower_limit",__s);
                uVar9 = iVar7 + iVar6;
                goto LAB_001009ec;
              }
            }
          }
          uVar9 = 0xffffffea;
        }
        else {
          uVar9 = 0xffffffea;
        }
LAB_001009ec:
        kfree(__s_00);
        kfree(pcVar13);
        kfree(__s);
      }
      if (-1 < (int)uVar9) {
        if (0xfff < uVar9) goto LAB_00100a78;
        *(undefined1 *)(lVar12 + (ulong)uVar9) = 0;
        uVar9 = simple_read_from_buffer(param_2,param_3,param_4,lVar12);
      }
    }
  }
  kfree(lVar12);
  lVar12 = (long)(int)uVar9;
LAB_00100a40:
  lVar24 = sp_el0;
  if (*(long *)(lVar24 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar12);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100abc size=208
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  ulong uVar1;
  
  uVar1 = debugfs_create_dir("thermal",0);
  thermal_debugfs_parent = uVar1;
  if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
    _printk(&DAT_00100e40,"thermal_config","thermal_config_init",uVar1 & 0xffffffff);
  }
  else {
    uVar1 = debugfs_create_file("config",0x180,uVar1,0,&thermal_dbgfs_config_fops);
    thermal_debugfs_config = uVar1;
    if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
      _printk(&DAT_00100fa1,"thermal_config","thermal_config_init",uVar1 & 0xffffffff);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 00100b90 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  debugfs_remove(thermal_debugfs_parent);
  return;
}



//------------------------------------------------------------
// thermal_dbgfs_config_write @ 00100bb8 size=464
// signature: undefined thermal_dbgfs_config_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong thermal_dbgfs_config_write(undefined8 param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  ulong uVar5;
  char local_40 [24];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_40[0x10] = '\0';
  local_40[0x11] = '\0';
  local_40[0x12] = '\0';
  local_40[0x13] = '\0';
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  if (param_3 - 0x15 < 0xffffffffffffffec) {
LAB_00100d34:
    param_3 = 0xffffffffffffffea;
  }
  else {
    __check_object_size(local_40,param_3,0);
    puVar4 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar5 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar5 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar4 = (undefined8 *)puVar4[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4;
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      lVar3 = __arch_copy_from_user(puVar4,local_40,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      if (lVar3 == 0) {
        iVar2 = sscanf(local_40,"%19[^\n\t ]",&tzone_sensor_name);
        if (iVar2 == 1) {
          uVar5 = thermal_zone_get_zone_by_name(&tzone_sensor_name);
          if (0xfffffffffffff000 < uVar5) {
            _printk(&DAT_00100df0,"thermal_config","thermal_dbgfs_config_write",&tzone_sensor_name,
                    uVar5);
            param_3 = uVar5;
          }
          goto LAB_00100d38;
        }
        goto LAB_00100d34;
      }
    }
    param_3 = 0xfffffffffffffff2;
  }
LAB_00100d38:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// strlen @ 00102000 size=1
// signature: size_t strlen(char * __s)
// callers: [buffer_overflow_check, thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_get_zone_by_name @ 00102008 size=1
// signature: undefined thermal_zone_get_zone_by_name(void)
// callers: [thermal_dbgfs_config_write, thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_get_zone_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102018 size=1
// signature: undefined kmalloc_trace(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102020 size=1
// signature: undefined scnprintf(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 00102028 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102030 size=1
// signature: undefined __kmalloc(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00102038 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102040 size=1
// signature: undefined kfree(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102048 size=1
// signature: undefined _printk(void)
// callers: [init_module, thermal_dbgfs_config_write, thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102050 size=1
// signature: undefined mutex_lock(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102058 size=1
// signature: undefined mutex_unlock(void)
// callers: [thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [thermal_dbgfs_config_write, thermal_dbgfs_config_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00102068 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00102070 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00102078 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00102080 size=1
// signature: undefined __check_object_size(void)
// callers: [thermal_dbgfs_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00102098 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [thermal_dbgfs_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 001020a0 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [thermal_dbgfs_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



