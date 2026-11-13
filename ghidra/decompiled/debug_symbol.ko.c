// Decompiled by Ghidra 12.2
// Program: debug_symbol.ko
// Image base: 00100000

//------------------------------------------------------------
// debug_symbol_available @ 00100114 size=644
// signature: undefined debug_symbol_available(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void debug_symbol_available(void)

{
  byte *pbVar1;
  long lVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  undefined8 uVar6;
  byte *pbVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  ulong uVar11;
  char *pcVar12;
  ulong uVar13;
  char cVar14;
  long lVar15;
  ulong uVar16;
  uint uVar17;
  int iVar18;
  char acStack_270 [512];
  long local_70;
  
  lVar2 = sp_el0;
  local_70 = *(long *)(lVar2 + 0x638);
  if ((debug_symbol_vaddr == (int *)0x0) || (*debug_symbol_vaddr != -0x33112201)) {
    uVar6 = 0;
  }
  else {
    if (debug_symbol_0 == 0) {
      uVar8 = debug_symbol_vaddr[3];
      debug_symbol_0 = _kimage_voffset + *(long *)(debug_symbol_vaddr + 6);
      debug_symbol_1 = *(long *)(debug_symbol_vaddr + 0x14) + _kimage_voffset;
      debug_symbol_4 = *(long *)(debug_symbol_vaddr + 8) + _kimage_voffset;
      debug_symbol_2 = *(long *)(debug_symbol_vaddr + 0x16) + _kimage_voffset;
      debug_symbol_5 = *(long *)(debug_symbol_vaddr + 0x18) + _kimage_voffset;
      debug_symbol_7 = *(long *)(debug_symbol_vaddr + 0x1c) + _kimage_voffset;
      debug_symbol_6 = *(long *)(debug_symbol_vaddr + 0x1a) + _kimage_voffset;
      debug_symbol_3 = uVar8;
      memset(acStack_270,0,0x200);
      if (uVar8 != 0) {
        uVar8 = 0;
        uVar16 = 0;
        do {
          lVar4 = debug_symbol_4;
          lVar2 = debug_symbol_1;
          pbVar1 = (byte *)(debug_symbol_2 + (ulong)uVar8);
          uVar17 = (uint)*pbVar1;
          if ((char)*pbVar1 < '\0') {
            pbVar7 = pbVar1 + 2;
            iVar18 = uVar8 + 2;
            uVar17 = uVar17 & 0x7f | (uint)pbVar1[1] << 7;
            if (uVar17 != 0) goto LAB_00100284;
LAB_00100338:
            pcVar9 = acStack_270;
LAB_0010033c:
            *pcVar9 = '\0';
          }
          else {
            iVar18 = uVar8 + 1;
            pbVar7 = pbVar1 + 1;
            if (uVar17 == 0) goto LAB_00100338;
LAB_00100284:
            bVar3 = false;
            uVar11 = 0x200;
            pcVar10 = acStack_270;
            uVar8 = uVar17;
            do {
              uVar13 = (ulong)*(ushort *)(debug_symbol_6 + (ulong)*pbVar7 * 2);
              pcVar12 = (char *)(debug_symbol_5 + uVar13);
              cVar14 = *pcVar12;
              if (cVar14 != '\0') {
                if (bVar3) {
                  pcVar9 = pcVar10;
                  if (uVar11 < 2) break;
                  uVar11 = uVar11 - 1;
                  *pcVar10 = cVar14;
                  pcVar10 = pcVar10 + 1;
                }
                cVar14 = pcVar12[1];
                if (cVar14 == '\0') {
                  bVar3 = true;
                }
                else {
                  pcVar9 = pcVar10;
                  pcVar12 = (char *)(debug_symbol_5 + 2 + uVar13);
                  uVar13 = uVar11;
                  do {
                    if (uVar13 < 2) {
                      uVar11 = (ulong)(uVar11 != 0);
                      goto LAB_0010031c;
                    }
                    pcVar10 = pcVar9 + 1;
                    *pcVar9 = cVar14;
                    cVar14 = *pcVar12;
                    uVar13 = uVar13 - 1;
                    pcVar9 = pcVar10;
                    pcVar12 = pcVar12 + 1;
                  } while (cVar14 != '\0');
                  bVar3 = true;
                  uVar11 = uVar13;
                }
              }
              uVar8 = uVar8 - 1;
              pbVar7 = pbVar7 + 1;
              pcVar9 = pcVar10;
            } while (uVar8 != 0);
LAB_0010031c:
            if (uVar11 != 0) goto LAB_0010033c;
          }
          lVar15 = 0;
          do {
            if ((*(long *)((long)&DAT_001008f8 + lVar15) == 0) &&
               (iVar5 = strcmp(acStack_270,*(char **)((long)&ds_entries + lVar15)), iVar5 == 0)) {
              *(ulong *)((long)&DAT_001008f8 + lVar15) =
                   lVar4 + (ulong)*(uint *)(lVar2 + (long)(int)uVar16 * 4);
            }
            lVar15 = lVar15 + 0x10;
          } while (lVar15 != 0xb0);
          uVar8 = uVar17 + iVar18;
          uVar16 = uVar16 + 1;
        } while (uVar16 < debug_symbol_3);
      }
    }
    uVar6 = 1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// debug_symbol_lookup_name @ 0010039c size=772
// signature: undefined debug_symbol_lookup_name(void)
// callers: []
//------------------------------------------------------------

void debug_symbol_lookup_name(char *param_1)

{
  byte *pbVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  byte *pbVar7;
  ulong uVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  char *pcVar12;
  ulong uVar13;
  char cVar14;
  ulong uVar15;
  uint uVar16;
  char acStack_268 [512];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  memset(acStack_268,0,0x200);
  if (*param_1 != '\0') {
    iVar4 = strcmp(param_1,ds_entries);
    if (iVar4 == 0) {
      lVar6 = 0;
LAB_00100518:
      lVar6 = (&DAT_001008f8)[lVar6 * 2];
      if (lVar6 != 0) goto LAB_00100644;
    }
    else {
      iVar4 = strcmp(param_1,PTR_s___bss_stop_00100900);
      if (iVar4 == 0) {
        lVar6 = 1;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s___per_cpu_start_00100910);
      if (iVar4 == 0) {
        lVar6 = 2;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s___per_cpu_end_00100920);
      if (iVar4 == 0) {
        lVar6 = 3;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s___start_ro_after_init_00100930);
      if (iVar4 == 0) {
        lVar6 = 4;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s___end_ro_after_init_00100940);
      if (iVar4 == 0) {
        lVar6 = 5;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_DAT_00100950);
      if (iVar4 == 0) {
        lVar6 = 6;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s_linux_banner_00100960);
      if (iVar4 == 0) {
        lVar6 = 7;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s_irq_stack_ptr_00100970);
      if (iVar4 == 0) {
        lVar6 = 8;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s_tick_cpu_device_00100980);
      if (iVar4 == 0) {
        lVar6 = 9;
        goto LAB_00100518;
      }
      iVar4 = strcmp(param_1,PTR_s_modules_00100990);
      if (iVar4 == 0) {
        lVar6 = 10;
        goto LAB_00100518;
      }
    }
    if (debug_symbol_3 != 0) {
      uVar8 = 0;
      uVar15 = 0;
      do {
        pbVar1 = (byte *)(debug_symbol_2 + uVar8);
        uVar16 = (uint)*pbVar1;
        if ((char)*pbVar1 < '\0') {
          pbVar7 = pbVar1 + 2;
          iVar4 = (int)uVar8 + 2;
          uVar16 = uVar16 & 0x7f | (uint)pbVar1[1] << 7;
          if (uVar16 != 0) goto LAB_00100568;
LAB_00100614:
          pcVar9 = acStack_268;
LAB_00100618:
          *pcVar9 = '\0';
        }
        else {
          iVar4 = (int)uVar8 + 1;
          pbVar7 = pbVar1 + 1;
          if (uVar16 == 0) goto LAB_00100614;
LAB_00100568:
          bVar3 = false;
          pcVar10 = acStack_268;
          uVar8 = 0x200;
          uVar11 = uVar16;
          do {
            uVar13 = (ulong)*(ushort *)(debug_symbol_6 + (ulong)*pbVar7 * 2);
            pcVar12 = (char *)(debug_symbol_5 + uVar13);
            cVar14 = *pcVar12;
            if (cVar14 != '\0') {
              if (bVar3) {
                pcVar9 = pcVar10;
                if (uVar8 < 2) break;
                uVar8 = uVar8 - 1;
                *pcVar10 = cVar14;
                pcVar10 = pcVar10 + 1;
              }
              cVar14 = pcVar12[1];
              if (cVar14 == '\0') {
                bVar3 = true;
              }
              else {
                pcVar9 = pcVar10;
                pcVar12 = (char *)(debug_symbol_5 + 2 + uVar13);
                uVar13 = uVar8;
                do {
                  if (uVar13 < 2) {
                    uVar8 = (ulong)(uVar8 != 0);
                    goto LAB_001005f8;
                  }
                  pcVar10 = pcVar9 + 1;
                  *pcVar9 = cVar14;
                  cVar14 = *pcVar12;
                  uVar13 = uVar13 - 1;
                  pcVar9 = pcVar10;
                  pcVar12 = pcVar12 + 1;
                } while (cVar14 != '\0');
                bVar3 = true;
                uVar8 = uVar13;
              }
            }
            uVar11 = uVar11 - 1;
            pbVar7 = pbVar7 + 1;
            pcVar9 = pcVar10;
          } while (uVar11 != 0);
LAB_001005f8:
          if (uVar8 != 0) goto LAB_00100618;
        }
        iVar5 = strcmp(acStack_268,param_1);
        if (iVar5 == 0) {
          lVar6 = debug_symbol_4 +
                  (ulong)*(uint *)(debug_symbol_1 +
                                  (-(uVar15 >> 0x1f & 1) & 0xfffffffc00000000 |
                                  (uVar15 & 0xffffffff) << 2));
          goto LAB_00100644;
        }
        uVar8 = (ulong)(uVar16 + iVar4);
        uVar15 = uVar15 + 1;
      } while (uVar15 < debug_symbol_3);
    }
  }
  lVar6 = 0;
LAB_00100644:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001006d8 size=280
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  int iVar1;
  long lVar2;
  void *__s;
  undefined *puVar3;
  long local_78 [10];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = of_find_compatible_node(0,0,"google,debug-kinfo");
  if (lVar2 == 0) {
    puVar3 = &DAT_00100a97;
  }
  else {
    memset(local_78,0,0x50);
    iVar1 = __of_parse_phandle_with_args(lVar2,"memory-region",0,0,0,local_78);
    if ((iVar1 == 0) && (local_78[0] != 0)) {
      lVar2 = of_reserved_mem_lookup();
      if (lVar2 == 0) {
        puVar3 = &DAT_00100a6c;
      }
      else {
        __s = (void *)memremap(*(undefined8 *)(lVar2 + 0x20),*(undefined8 *)(lVar2 + 0x28),1);
        debug_symbol_vaddr = __s;
        if (__s != (void *)0x0) {
          memset(__s,0,0x1e4);
          *(void **)(lVar2 + 0x30) = __s;
          goto LAB_001007c0;
        }
        puVar3 = &DAT_001009c8;
      }
    }
    else {
      puVar3 = &DAT_00100ad6;
    }
  }
  _printk(puVar3);
LAB_001007c0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// memset @ 00102008 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [debug_symbol_available, debug_symbol_lookup_name, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00102010 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [debug_symbol_available, debug_symbol_lookup_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [debug_symbol_available, debug_symbol_lookup_name, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00102020 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102028 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_lookup @ 00102030 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memremap @ 00102038 size=1
// signature: undefined memremap(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102040 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



